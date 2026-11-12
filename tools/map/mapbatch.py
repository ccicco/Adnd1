#!/usr/bin/env python3
"""mapbatch.py - batch map extraction for G1-class maps.
Stages: lattice auto-fit -> thickness separation -> blob
inventory -> classification -> JSON emission -> residue
composite. Deps: numpy, cv2; optional: pytesseract.
Usage: mapbatch.py MAP.jpg [--outdir DIR] [--lattice
  X0,XP,Y0,YQ] [--wall-frac F] [--ocr] [--no-composite]
  [--quiet]; out: <stem>.extract.json + <stem>.residue.png
Doctrine: positions auto, identities residue (eyes).

Lattice fit (v1.6): the page carries TWO combs - the printed
graph grid (thin lines, every cell, exact) and the wall
lattice (~0.9% larger, irregular lines, +/-5.6px wander),
which cross near the map middle. The grid comb is fitted
from thin structural bands; wall anchors come from thick
bands (de-biased against grid lines); the wall comb by
pair-RANSAC with integer line counts taken from the grid
pitch; a shared print-ratio cross-check (sx vs sy) unlocks
an axis that locked onto the grid comb.
"""
import sys, os, json, math, argparse
import numpy as np
import cv2

def binarize(gray):
    _, m = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV
                        + cv2.THRESH_OTSU)
    return (m > 0).astype(np.uint8)

def _open_layers(mask):
    """Structural openings: ho keeps horizontal ink runs
    >= 15% of width (wall bands, grid rules); vo vertical
    runs >= 15% of height. Glyph strokes die in both."""
    h, w = mask.shape
    ho = cv2.morphologyEx(mask, cv2.MORPH_OPEN,
        np.ones((1, max(24, int(0.15 * w))), np.uint8))
    vo = cv2.morphologyEx(mask, cv2.MORPH_OPEN,
        np.ones((max(24, int(0.15 * h)), 1), np.uint8))
    return ho, vo

def _autocorr_period(prof, pmin, pmax):
    """Coarse comb period from autocorrelation: smallest
    strong local peak in range (the pitch fundamental)."""
    p = prof.astype(np.float64)
    p -= p.mean()
    n = len(p)
    F = np.fft.rfft(p)
    ac = np.fft.irfft(F * np.conj(F))[:n // 2]
    if ac[0] <= 0:
        return None
    ac /= ac[0]
    lo = int(pmin)
    hi = min(int(pmax), len(ac) - 2)
    if hi <= lo:
        return None
    pk = [i for i in range(lo, hi + 1)
          if ac[i] > ac[i - 1] and ac[i] >= ac[i + 1]]
    if not pk:
        return None
    m = max(ac[i] for i in pk)
    strong = [i for i in pk if ac[i] >= 0.8 * m]
    return float(min(strong))

WANDER = 5.6    # record: wall-line wander bound (px)

def _bands(prof, gap=2):
    """Cluster inked profile lines into bands, tolerating
    small gaps. Returns [(a, b, [(i, w)...])]."""
    out = []
    c = 0
    n = len(prof)
    while c < n:
        if prof[c] > 0:
            end = c
            miss = 0
            d = c
            while d + 1 < n:
                if prof[d + 1] > 0:
                    end = d + 1
                    miss = 0
                else:
                    miss += 1
                    if miss > gap:
                        break
                d += 1
            ws = [(i, prof[i]) for i in range(c, end + 1)
                  if prof[i] > 0]
            out.append((c, end, ws))
            c = end + 1
        else:
            c += 1
    return out

def _cent(ws):
    tot = sum(w for _, w in ws)
    return sum(w * (i + 0.5) for i, w in ws) / tot

def _phase(cent, P):
    acc = 0j
    for c in cent:
        u = 2.0 * math.pi * ((c % P) / P)
        acc += complex(math.cos(u), math.sin(u))
    return (math.atan2(acc.imag, acc.real)
            / (2.0 * math.pi) * P) % P

def _circ(cent, plo, phi, step=0.0025):
    """Circular-concentration fit of period+phase for a comb
    over the given line positions."""
    best = None
    P = plo
    while P <= phi:
        conc = abs(sum(
            complex(math.cos(2.0 * math.pi * ((c % P) / P)),
                    math.sin(2.0 * math.pi * ((c % P) / P)))
            for c in cent)) / len(cent)
        if best is None or conc > best[0]:
            best = (conc, P, _phase(cent, P))
        P += step
    return best[1], best[2]

def _inliers(anchors, P, x0, clip):
    return [(c, int(round((c - x0) / P))) for c in anchors
            if abs(c - x0 - round((c - x0) / P) * P)
            <= clip]

def _polish(anchors, inl, P, x0, clip, iters=4):
    """Least-squares refine of period+phase on inliers with
    residual clipping; walls wander so clip at WANDER."""
    for _ in range(iters):
        if len(inl) < 4:
            break
        m = len(inl)
        sk = sum(k for _, k in inl)
        sc = sum(c for c, _ in inl)
        skk = sum(k * k for _, k in inl)
        skc = sum(c * k for c, k in inl)
        den = m * skk - sk * sk
        if den <= 0:
            break
        P = (m * skc - sk * sc) / den
        x0 = (sc - P * sk) / m
        inl = _inliers(anchors, P, x0, clip)
    res = [c - x0 - k * P for c, k in inl]
    rms = (sum(r * r for r in res) / len(inl)) ** 0.5
    return P, x0, inl, rms

def _ransac(anchors, gP, clip):
    """Candidate wall combs from anchor pairs: integer line
    count from the grid pitch (combs drift 0.9%/line, so a
    >=8-line span rounds safely); scored by tight inliers."""
    best = None
    m = len(anchors)
    for i in range(m):
        for j in range(m):
            if i == j:
                continue
            d = anchors[j] - anchors[i]
            if d < 8.0 * gP:
                continue
            k = int(round(d / gP))
            if k < 8:
                continue
            P = d / k
            if not (0.99 * gP <= P <= 1.02 * gP):
                continue
            x0 = _phase(anchors, P)
            inl = _inliers(anchors, P, x0, clip)
            if best is None or len(inl) > len(best[0]):
                best = (inl, P, x0)
    return best

def _axis_fit(bands, pac):
    """Per-axis fit: grid comb from thin bands (<=5px), wall
    anchors from thick bands (>=6px) de-biased against grid
    lines, wall comb by pair-RANSAC + clipped LSQ."""
    thin = [_cent(ws) for (a, b, ws) in bands
            if b - a + 1 <= 5]
    if len(thin) < 4:
        return None
    gP, g0 = _circ(thin, 0.95 * pac, 1.05 * pac)
    anchors = []
    for (a, b, ws) in bands:
        if b - a + 1 < 6:
            continue
        kept = [(i, w) for (i, w) in ws
                if abs(i + 0.5 - g0 - round(
                    (i + 0.5 - g0) / gP) * gP) > 2.0]
        anchors.append(_cent(kept) if len(kept) >= 4
                       else _cent(ws))
    if len(anchors) < 4:
        return None
    rb = _ransac(anchors, gP, 3.0)
    if rb is None:
        return None
    P, x0, inl, rms = _polish(anchors, rb[0], rb[1],
                              rb[2], WANDER)
    return dict(gp=gP, g0=g0, p=P, x0=x0, n=len(inl),
                rms=rms, anchors=anchors)

def _ratio_refit(ax, s):
    """Refit a grid-locked axis with the trusted axis's
    print ratio. Q = s*gP is FROZEN (weak-axis anchors
    cannot refine pitch - a free polish lets a foreign
    comb steal inliers); phase = the inlier-count-max
    scan (the circular mean is dragged by slab-biased
    anchors), then phase-only LSQ."""
    Q = s * ax["gp"]
    anchors = ax["anchors"]
    best = None
    x = 0.0
    while x < Q:
        cnt = 0
        for c in anchors:
            if abs(c - x - round((c - x) / Q) * Q) \
                    <= WANDER:
                cnt += 1
        if best is None or cnt > best[0]:
            best = (cnt, x)
        x += 0.25
    inl = _inliers(anchors, Q, best[1], WANDER)
    x0 = best[1]
    for _ in range(4):
        if len(inl) < 4:
            break
        nx0 = sum(c - k * Q for c, k in inl) / len(inl)
        ninl = _inliers(anchors, Q, nx0, WANDER)
        if len(ninl) < len(inl):
            break
        x0 = nx0
        if ninl == inl:
            inl = ninl
            break
        inl = ninl
    if len(inl) < 4:
        return None
    res = [c - x0 - k * Q for c, k in inl]
    rms = (sum(r * r for r in res) / len(res)) ** 0.5
    return dict(gp=ax["gp"], g0=ax["g0"], p=Q, x0=x0,
                n=len(inl), rms=rms, anchors=anchors)

def fit_lattice(mask):
    """Two-comb fit. Printed grid = registration, walls =
    truth (record doctrine). Ratio cross-check: the wall/
    grid print ratio is shared across axes (~1.9% pitch
    gap is a print artifact, not per-axis noise)."""
    ho, vo = _open_layers(mask)
    both = ho | vo
    pacx = _autocorr_period(both.sum(axis=0), 8.0, 300.0)
    pacy = _autocorr_period(both.sum(axis=1), 8.0, 300.0)
    if pacx is None or pacy is None:
        return None
    fx = _axis_fit(_bands(vo.sum(axis=0).tolist()), pacx)
    fy = _axis_fit(_bands(ho.sum(axis=1).tolist()), pacy)
    if fx is None or fy is None:
        return None
    sx = fx["p"] / fx["gp"]
    sy = fy["p"] / fy["gp"]
    if abs(sx - sy) > 0.002:
        # trusted axis = the comb that departs further from
        # the grid pitch: the wall lattice carries the print
        # scale, a grid-locked fit sits at ~1.0 by construction
        # (inlier counts can favor the grid comb - seen live).
        if abs(sx - 1.0) >= abs(sy - 1.0):
            fy = _ratio_refit(fy, sx) or fy
        else:
            fx = _ratio_refit(fx, sy) or fx
    return dict(x0=fx["x0"] % fx["p"], xp=fx["p"],
                y0=fy["x0"] % fy["p"], yp=fy["p"],
                source="auto",
                grid=dict(px=round(fx["gp"], 4),
                          py=round(fy["gp"], 4),
                          sx=round(sx, 5),
                          sy=round(sy, 5)))

def separate(mask, pitch, wall_frac):
    """Walls survive a distance threshold; grid and glyphs
    do not. RUNS use unbounded constrained dilation (the
    record-frozen behavior); the BLOB layer uses BOUNDED
    walls so wall-adjacent objects (hearths, fireplaces,
    anything the grid web used to drag into walls) survive
    into the inventory."""
    dist = cv2.distanceTransform(mask, cv2.DIST_L2, 3)
    thr = max(2.0, wall_frac * pitch)
    core = (dist >= thr).astype(np.uint8)
    walls = core.copy()
    k3 = np.ones((3, 3), np.uint8)
    for _ in range(int(2 * pitch) + 4):
        nxt = cv2.dilate(walls, k3) & mask
        if np.array_equal(nxt, walls):
            break
        walls = nxt
    bw = core.copy()
    for _ in range(int(thr) + 1):
        bw = cv2.dilate(bw, k3) & mask
    nonwall = (mask & (1 - bw)).astype(np.uint8)
    return walls, nonwall, core

def inventory(nonwall, lat, pitch):
    n, lab, st, cent = cv2.connectedComponentsWithStats(nonwall)
    out = []
    big = (0.4 * pitch) ** 2
    gmax = (0.35 * pitch) ** 2
    for i in range(1, n):
        x, y, w, h, a = st[i]
        if a < 6:
            continue
        cx, cy = cent[i]
        aspect = max(w, h) / float(max(1, min(w, h)))
        if aspect >= 3.0 and min(w, h) <= 0.2 * pitch \
                and max(w, h) >= 0.4 * pitch:
            cls = "line"       # grid / dash / projection run
        elif a <= gmax:
            cls = "glyph"      # label, door leaf, column, hearth
        elif a <= big:
            cls = "feature"    # mid-size: hearth, stair block
        else:
            cls = "mass"       # bold mass, structural ink
        sub = (lab[y:y + h, x:x + w] == i).astype(np.uint8)
        hu = cv2.HuMoments(cv2.moments(sub, binaryImage=True)
                           ).flatten().tolist()
        out.append(dict(cls=cls, px=(int(cx), int(cy)),
            bbox=(int(x), int(y), int(w), int(h)), area=int(a),
            aspect=round(float(aspect), 2), hu=hu,
            lat=(round((cx - lat["x0"]) / lat["xp"], 2),
                 round((cy - lat["y0"]) / lat["yp"], 2))))
    return out

def ocr_glyphs(gray, blobs, pitch):
    """Tesseract doctrine: positions reliable, readings not."""
    try:
        import pytesseract
    except ImportError:
        return []
    out = []
    for b in blobs:
        if b["cls"] != "glyph":
            continue
        x, y, w, h = b["bbox"]
        if min(w, h) < 8 or max(w, h) < 2 * pitch / 3:
            continue
        pad = 4
        crop = gray[max(0, y - pad):y + h + pad,
                    max(0, x - pad):x + w + pad]
        txt = pytesseract.image_to_string(crop,
            config="--psm 7").strip()
        if txt:
            out.append(dict(px=b["px"], text=txt[:24]))
    return out

def wall_runs(walls, lat, core=None, cover=0.5):
    """Index wall ink per lattice line: for each V/H line,
    runs = lattice intervals whose band-slice wall coverage
    >= cover. Runs carry from/to in OTHER-axis line units
    and cov = fraction of the span backed by dist-core (the
    thickness layer); grid slivers have cov ~0, wall bands
    cov ~1."""
    h, w = walls.shape
    P, Q = lat["xp"], lat["yp"]
    out = []
    for ax, prof, per, n, cross in (
            ("V", walls.sum(axis=0), P, w, Q),
            ("H", walls.sum(axis=1), Q, h, P)):
        base = lat["x0"] if ax == "V" else lat["y0"]
        lo = int(math.floor((0 - base) / per)) - 1
        hi = int(math.ceil((n - base) / per)) + 1
        for k in range(lo, hi + 1):
            c0 = base + k * per
            if c0 < -per or c0 > n + per:
                continue
            a0 = max(0, int(c0 - 2))
            a1 = min(n, int(c0 + 3))
            if a0 >= a1:
                continue
            # slice wall ink along the line
            if ax == "V":
                sl = walls[:, a0:a1].max(axis=1)
                slc = (core[:, a0:a1].max(axis=1)
                       if core is not None else None)
            else:
                sl = walls[a0:a1, :].max(axis=0)
                slc = (core[a0:a1, :].max(axis=0)
                       if core is not None else None)
            idx = np.flatnonzero(sl > 0)
            if len(idx) == 0:
                continue
            # group into runs, convert to cross-axis lines
            # (bridge sub-0.2-line slivers: a wall band is
            # continuous ink; real openings are >= 0.25 line
            # and become door voids)
            grp = []
            st = idx[0]
            pv = idx[0]
            for v in idx[1:]:
                if v - pv > 0.2 * cross:
                    grp.append((st, pv))
                    st = v
                pv = v
            grp.append((st, pv))
            for (s, e) in grp:
                if e - s + 1 < cover * cross / 4:
                    continue
                a = (s - (lat["y0"] if ax == "V"
                          else lat["x0"])) / cross
                b = (e + 1 - (lat["y0"] if ax == "V"
                              else lat["x0"])) / cross
                rd = dict(axis=ax, line=k,
                          frm=round(a, 2),
                          to=round(b, 2))
                if slc is not None:
                    rd["cov"] = round(float(
                        (slc[s:e + 1] > 0).sum())
                        / (e - s + 1), 2)
                out.append(rd)
    return out

def door_voids(runs, max_gap=2):
    """Voids = gaps between consecutive runs on a line,
    from run end to next run start, in line units."""
    per = {}
    for r in runs:
        per.setdefault((r["axis"], r["line"]), []).append(r)
    out = []
    for key, rs in per.items():
        rs.sort(key=lambda r: r["frm"])
        for a, b in zip(rs, rs[1:]):
            g = b["frm"] - a["to"]
            if 0.25 < g <= max_gap + 0.5:
                out.append(dict(axis=key[0], line=key[1],
                                frm=round(a["to"], 2),
                                to=round(b["frm"], 2)))
    return out

def composite(gray, blobs, voids, lat, pitch, path):
    """Residue composite: every blob tile at its lattice
    address, in reading order, gridded 6 wide."""
    cells = {}
    for b in blobs:
        lx, ly = b["lat"]
        cells.setdefault((int(math.floor(lx)),
                          int(math.floor(ly))),
                         []).append(b)
    if not cells:
        return None
    ks = sorted(cells)
    cols = 6
    rows = (len(ks) + cols - 1) // cols
    cw = ch = int(pitch * 1.2)
    canvas = np.full((rows * ch, cols * cw), 255,
                     np.uint8)
    for t, key in enumerate(ks):
        gx, gy = t % cols, t // cols
        x0, y0 = gx * cw, gy * ch
        cv2.putText(canvas, "%d,%d" % key,
                    (x0 + 2, y0 + 12),
                    cv2.FONT_HERSHEY_PLAIN, 1.0, 0)
        for b in cells[key]:
            bx, by, bw, bh = b["bbox"]
            sub = gray[by:by + bh, bx:bx + bw]
            if sub.size == 0:
                continue
            sc = min((cw - 6) / bw, (ch - 22) / bh, 1.0)
            dw, dh = max(1, int(bw * sc)), \
                max(1, int(bh * sc))
            sub = cv2.resize(sub, (dw, dh),
                             interpolation=cv2.INTER_AREA)
            canvas[y0 + 18:y0 + 18 + dh,
                   x0 + 3:x0 + 3 + dw] = sub
    cv2.imwrite(path, canvas)
    return path

def main():
    ap = argparse.ArgumentParser(description="batch map "
        "extraction pipeline")
    ap.add_argument("image")
    ap.add_argument("--outdir")
    ap.add_argument("--lattice", metavar="X0,XP,Y0,YQ",
        help="override auto-fit with seated constants")
    ap.add_argument("--wall-frac", type=float, default=0.09,
        help="wall distance threshold as pitch fraction "
        "(default 0.09)")
    ap.add_argument("--ocr", action="store_true")
    ap.add_argument("--strict-runs", action="store_true",
        help="keep only runs with >= 0.5 dist-core "
        "coverage (sheds grid slivers)")
    ap.add_argument("--no-composite", action="store_true")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()

    gray = cv2.imread(a.image, cv2.IMREAD_GRAYSCALE)
    if gray is None:
        sys.exit("mapbatch: cannot read %s" % a.image)
    outdir = a.outdir or os.path.dirname(a.image) or "."
    os.makedirs(outdir, exist_ok=True)
    stem = os.path.join(outdir, os.path.splitext(
        os.path.basename(a.image))[0])

    mask = binarize(gray)
    if a.lattice:
        x0, xp, y0, yp = [float(v) for v in
                          a.lattice.split(",")]
        lat = dict(x0=x0, xp=xp, y0=y0, yp=yp,
                   source="given")
    else:
        lat = fit_lattice(mask)
        if lat is None:
            sys.exit("mapbatch: lattice auto-fit failed; "
                     "pass --lattice X0,XP,Y0,YQ")
    if not a.quiet:
        for nm, pv in (("P", lat["xp"]), ("Q", lat["yp"])):
            if pv < 30.0 or pv > 120.0:
                print("WARNING: %s=%.2f outside typical "
                      "10ft-at-300dpi range (30-120) - fit "
                      "suspect" % (nm, pv))
        if abs(lat["xp"] / lat["yp"] - 1.0) > 0.05:
            print("WARNING: pitch ratio %.3f far from 1 - "
                  "fit suspect" % (lat["xp"] / lat["yp"]))
        print("lattice: X0=%.2f P=%.4f Y0=%.2f Q=%.4f "
              "(%s)" % (lat["x0"] % lat["xp"], lat["xp"],
                        lat["y0"] % lat["yp"], lat["yp"],
                        lat["source"]))
    pitch = 0.5 * (lat["xp"] + lat["yp"])
    walls, nonwall, core = separate(mask, pitch, a.wall_frac)

    runs = wall_runs(walls, lat, core)
    if a.strict_runs:
        runs = [r for r in runs
                if r.get("cov", 1.0) >= 0.5]
    voids = door_voids(runs)
    blobs = inventory(nonwall, lat, pitch)
    res = [b for b in blobs if b["cls"] != "line"]
    if not a.quiet:
        print("walls: %d runs, voids: %d, blobs: %d "
              "(%d residue)" % (len(runs), len(voids),
                                len(blobs), len(res)))
    out = dict(lattice=lat, wall_frac=a.wall_frac,
               runs=runs, voids=voids, blobs=blobs)
    if a.ocr:
        out["ocr"] = ocr_glyphs(gray, blobs, pitch)
    with open(stem + ".extract.json", "w") as f:
        json.dump(out, f, indent=1)
    if not a.no_composite:
        p = composite(gray, res, voids, lat, pitch,
                      stem + ".residue.png")
        if p and not a.quiet:
            print("residue composite: %d tiles -> %s"
                  % (len(res), p))

if __name__ == "__main__":
    main()

