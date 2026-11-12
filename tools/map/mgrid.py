#!/usr/bin/env python3
"""mgrid.py - grid determination, the front half of
mapbatch v2 (stage 0-3 of grid-spec v0.1).

Given a scanned square-grid map JPEG, decide:
  stage 0  decode + assert-map (periodicity gate;
           reject = full stop, no fitting fields)
  stage 1  enumerated, ranked grid hypotheses
           (periodogram peaks per axis, comb
           refinement, coverage + residual + spurious
           scores; thin margin -> ask)
  stage 2  wall seating, finite brute force
           (offsets x thickness; discriminators:
           edge agreement + corner closure + length
           quantization; ties ask)
  stage 3  scale statement (DPI trusted:false; two
           agreeing sources = confirmed, conflict =
           ask, none = unknown; no silent defaults)

Output: a grid statement JSON beside the input. All
geometry in lattice units downstream; pixels appear
only under provenance. Pure stdlib; JPEG decode is
jdec.py (seamlock: no image libraries)."""
import argparse
import datetime
import json
import math
import os
import struct
import sys

# ---------- tuning constants ----------------------

PITCH_MIN = 12.0     # search range only, not a claim
PITCH_MAX = 400.0
ASSERT_AC = 0.25     # periodicity floor (autocorr peak)
ASSERT_Z = 4.0       # peak z-score floor vs flat noise
ASSERT_Z_SOFT = 3.0  # softer floor, ONLY with a
                    # corroborating harmonic ladder
                    # (map-006: a ladder inflates the
                    # ac landscape spread and deflates
                    # the winner's z - 4.0 alone
                    # rejected a real gridded map)
LADDER_TOL = 0.05    # near-integer peak ratio = ladder
THIN_MAX = 5         # px band width: printed grid rule
COVERAGE_TOL = 1.5   # px: band center counts as seated
SEAT_OFFSETS = (-0.5, -0.25, 0.0, 0.25, 0.5)
SEAT_THICK = (1.0 / 16, 1.0 / 10, 1.0 / 8)
MARGIN_THIN = 0.10   # relative; thinner -> ask
WALL_PITCH_LO = 0.95 # wall comb vs grid comb print gap
WALL_PITCH_HI = 1.06


# ---------- decode -------------------------------

def decode_gray(path):
    """JPEG -> (w, h, gray bytes) via jdec; clear error
    if jdec is missing. No image libraries (seamlock)."""
    try:
        import jdec
    except ImportError:
        for p in (os.path.dirname(os.path.abspath(
                path)), "tools", "."):
            if os.path.exists(os.path.join(p, "jdec.py")):
                sys.path.insert(0, p)
                break
        try:
            import jdec
        except ImportError:
            sys.exit("mgrid: need jdec.py on the import "
                     "path (pure-stdlib JPEG decoder)")
    return jdec.decode(path)


def jfif_dpi(path):
    """JFIF density, if the scanner wrote one.
    A fallible witness - never trusted on its own."""
    try:
        d = open(path, "rb").read(64)
    except OSError:
        return None
    i = d.find(b"JFIF\x00")
    if i < 0:
        return None
    unit, xd, yd = struct.unpack(
        ">BHH", d[i + 7:i + 12])
    if unit != 1 or not xd:
        return None
    return xd if xd == yd else None


def binarize(pix):
    """gray bytes -> 0/1 bytes (1 = ink), Otsu."""
    hist = [0] * 256
    for b in pix:
        hist[b] += 1
    t = otsu(hist)
    # inclusive: with a wide empty gap the Otsu
    # plateau ties at the ink mode itself, and an
    # exclusive < would drop the whole ink class
    tbl = bytes([1 if v <= t else 0
                 for v in range(256)])
    return pix.translate(tbl)


def otsu(hist):
    tot = sum(hist)
    if not tot:
        return 128
    sum_all = sum(i * n for i, n in enumerate(hist))
    sb = 0.0
    wb = 0
    best = None
    for t in range(256):
        wb += hist[t]
        if not wb:
            continue
        wf = tot - wb
        if not wf:
            break
        sb += t * hist[t]
        mb = sb / wb
        mf = (sum_all - sb) / wf
        var = wb * wf * (mb - mf) ** 2
        if best is None or var > best[0]:
            best = (var, t)
    return best[1]


def separate_axes(binm, w, h):
    """Structural separation (mapbatch lineage): keep
    pixels in vertical runs >= 15% height (vo: grid
    rules + walls standing vertically) and pixels in
    horizontal runs >= 15% width (ho). Glyph strokes
    die in both; full-width rules stop poisoning the
    cross-axis profile. Returns (vo, ho) 0/1 bytes."""
    thr_v = max(24, int(0.15 * h))
    thr_h = max(24, int(0.15 * w))
    vo = bytearray(len(binm))
    ho = bytearray(len(binm))
    for x in range(w):
        col = binm[x::w]
        y = 0
        while y < h:
            if col[y]:
                y2 = y
                while y2 + 1 < h and col[y2 + 1]:
                    y2 += 1
                if y2 - y + 1 >= thr_v:
                    for yy in range(y, y2 + 1):
                        vo[yy * w + x] = 1
                y = y2 + 1
            else:
                y += 1
    for y in range(h):
        row = binm[y * w:(y + 1) * w]
        x = 0
        while x < w:
            if row[x]:
                x2 = x
                while x2 + 1 < w and row[x2 + 1]:
                    x2 += 1
                if x2 - x + 1 >= thr_h:
                    base = y * w
                    for xx in range(x, x2 + 1):
                        ho[base + xx] = 1
                x = x2 + 1
            else:
                x += 1
    return bytes(vo), bytes(ho)


def col_profile(binm, w, h):
    return [binm[j::w].count(1) for j in range(w)]


def row_profile(binm, w, h):
    return [binm[j * w:(j + 1) * w].count(1)
            for j in range(h)]


# ---------- stage 0: assert ----------------------

def autocorr(prof, plo, phi):
    """Normalized autocorrelation, mean removed."""
    n = len(prof)
    mu = sum(prof) / n
    p = [v - mu for v in prof]
    e0 = sum(v * v for v in p) or 1.0
    out = []
    lo = max(1, int(plo))
    hi = min(n - 1, int(phi))
    for lag in range(lo, hi + 1):
        s = sum(p[i] * p[i + lag]
                for i in range(n - lag))
        out.append((s / e0, lag))
    return out


def ac_peaks(prof):
    """Strong local maxima of the autocorrelation,
    z-scored against the ac landscape. Top peaks
    returned distinct-period, strongest first."""
    ac = autocorr(prof, PITCH_MIN, PITCH_MAX)
    if not ac:
        return []
    vals = [v for v, _ in ac]
    mu = sum(vals) / len(vals)
    sd = (sum((v - mu) ** 2 for v in vals)
          / len(vals)) ** 0.5 or 1e-9
    pk = []
    for i in range(1, len(ac) - 1):
        v, lag = ac[i]
        if ac[i - 1][0] < v >= ac[i + 1][0] \
                and v > mu:
            pk.append((v, (v - mu) / sd, lag))
    pk.sort(reverse=True)
    out = []
    for v, z, lag in pk:
        if any(abs(lag - l) < 4 for _, _, l in out):
            continue
        out.append((v, z, lag))
        if len(out) >= 5:
            break
    return out


def assert_map(vo, ho, w, h):
    """Ink census + axis periodicity on SEPARATED
    structure. Returns dict with state; reject is a
    full stop."""
    ink = (vo.count(1) + ho.count(1)) \
        / float(len(vo))
    res = dict(ink=round(ink, 5), axes={})
    if ink < 0.0005:
        res["state"] = "rejected"
        res["why"] = ("ink fraction %.5f: no coherent "
                      "ink structure" % ink)
        return res
    ok = True
    worst = None
    for ax, prof in (("x", col_profile(vo, w, h)),
                     ("y", row_profile(ho, w, h))):
        pk = ac_peaks(prof)
        res["axes"][ax] = [(round(v, 3), round(z, 1),
                           lag) for v, z, lag in pk]
        best = pk[0] if pk else (0.0, 0.0, 0)
        res["axes"][ax + "_best"] = round(best[0], 3)
        lad = None
        if best[0] >= ASSERT_AC \
                and best[1] < ASSERT_Z:
            # harmonic-ladder corroboration: another
            # strong peak at a near-integer multiple
            # (or fraction) of the winner's lag is
            # grid evidence the z-score undercounts
            for v, _, lag in pk[1:]:
                if v < 0.5 * best[0]:
                    continue
                for r in (lag / best[2],
                          best[2] / lag):
                    if abs(r - round(r)) \
                            <= LADDER_TOL:
                        lad = round(r, 3)
                        break
                if lad:
                    break
            if lad and best[1] >= ASSERT_Z_SOFT:
                res["axes"][ax + "_ladder"] = lad
            else:
                lad = None
        if best[0] < ASSERT_AC \
                or (best[1] < ASSERT_Z and not lad):
            ok = False
            if worst is None \
                    or best[0] < worst[1]:
                worst = (ax, best[0], best[1])
    res["state"] = "asserted" if ok else "rejected"
    if not ok:
        res["why"] = ( "no dominant periodic peak on "
                      "axis %r (ac %.3f, z %.1f): not "
                      "a gridded map"
                      % (worst[0], worst[1], worst[2]))
    return res


# ---------- band machinery (mapbatch lineage) ------

def bands(prof, gap=2):
    """Cluster inked profile lines into bands, tolerating
    small gaps. [(a, b, [(i, w)...])...]"""
    out = []
    c = 0
    n = len(prof)
    while c < n:
        if prof[c] > 0:
            end, miss, d = c, 0, c
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


def cent(ws):
    tot = sum(w for _, w in ws)
    return sum(w * (i + 0.5) for i, w in ws) / tot


def comb_fit(cs, plo, phi, step=0.0025):
    """Circular-concentration fit of period + phase for
    a set of line centers."""
    best = None
    P = plo
    while P <= phi:
        acc = 0.0
        acc2 = 0.0
        for c in cs:
            u = 2.0 * math.pi * ((c % P) / P)
            acc += math.cos(u)
            acc2 += math.sin(u)
        conc = (acc * acc + acc2 * acc2) ** 0.5 \
            / len(cs)
        if best is None or conc > best[0]:
            ph = (math.atan2(acc2, acc)
                  / (2.0 * math.pi) * P) % P
            best = (conc, P, ph)
        P += step
    return best[1], best[2], best[0]


def comb_inliers(cs, P, x0, clip):
    return [(c, k) for c in cs for k in
            [round((c - x0) / P)] if k >= 0 and
            abs(c - x0 - k * P) <= clip]


def comb_polish(cs, P, x0, clip, iters=4):
    """Least-squares refine period + phase on inliers."""
    inl = comb_inliers(cs, P, x0, clip)
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
        inl = comb_inliers(cs, P, x0, clip)
    if not inl:
        return P, x0, inl, 99.0
    res = [c - x0 - k * P for c, k in inl]
    rms = (sum(r * r for r in res)
           / len(inl)) ** 0.5
    return P, x0, inl, rms


# ---------- stage 1: grid hypotheses --------------

def axis_hypotheses(prof, peaks):
    """Enumerated comb hypotheses for one axis, ranked.
    Each: {period, phase, coverage, residual, score,
    weight}. Coverage = fraction of thin-band ink
    seated on comb lines; spurious = fraction of
    predicted lines with no ink (kills subharmonic
    divisors of the true pitch)."""
    bs = bands(prof)
    thin = [(cent(ws), sum(w for _, w in ws))
            for a, b, ws in bs if b - a + 1 <= THIN_MAX]
    if len(thin) < 4:
        return []
    tot = sum(wt for _, wt in thin)
    hyps = []
    for v, z, lag in peaks:
        plo = max(PITCH_MIN, 0.95 * lag)
        phi = min(PITCH_MAX, 1.05 * lag)
        P, x0, conc = comb_fit([c for c, _ in thin],
                               plo, phi)
        P, x0, inl, rms = comb_polish(
            [c for c, _ in thin], P, x0, 3.0)
        cov = 0.0
        for c, wt in thin:
            k = round((c - x0) / P)
            if abs(c - x0 - k * P) <= COVERAGE_TOL:
                cov += wt
        cov /= tot
        # spurious: predicted comb lines with no ink.
        # Without it a divisor of the true pitch (every
        # real line still seated) outscores the
        # fundamental -- the fixture caught this.
        span = len(prof)
        k0 = int(math.floor(-x0 / P)) - 1
        k1 = int(math.ceil((span - x0) / P)) + 1
        pred = [x0 + k * P for k in
                range(k0, k1 + 1)]
        pred = [p for p in pred if 0 <= p < span]
        spurious = 0
        if pred:
            for p in pred:
                if not any(abs(p - c) <= COVERAGE_TOL
                           for c, _ in thin):
                    spurious += 1
            spurious /= float(len(pred))
        n = len(inl)
        hyps.append(dict(
            period=round(P, 3), phase=round(x0 % P, 3),
            coverage=round(cov, 4),
            residual=round(rms, 3), lines=n,
            spurious=round(spurious, 4),
            score=round(cov - spurious
                        - rms / max(P, 1.0), 4),
            peak=(round(v, 3), lag)))
    hyps.sort(key=lambda h: -h["score"])
    return hyps


def hypothesis_set(vo, ho, w, h):
    """Both axes, enumerated; composite score pairs
    each x-hypothesis with the best y-hypothesis."""
    hy = {}
    for ax, prof in (("x", col_profile(vo, w, h)),
                     ("y", row_profile(ho, w, h))):
        hy[ax] = axis_hypotheses(prof,
                                 ac_peaks(prof))
    if not hy["x"] or not hy["y"]:
        return hy
    best_y = hy["y"][0]["score"]
    for h1 in hy["x"]:
        h1["composite"] = round(
            h1["score"] * best_y, 4)
    hy["x"].sort(key=lambda h: -h["composite"])
    for h2 in hy["y"]:
        h2["composite"] = round(
            hy["x"][0]["score"] * h2["score"], 4)
    hy["y"].sort(key=lambda h: -h["composite"])
    return hy


def pitch_hierarchy(prof, P):
    """Finding, not an error: report half-cell /
    offset peaks when the endpoint histogram shows
    them."""
    ac = autocorr(prof, P * 0.45, P * 0.55)
    if not ac:
        return None
    v, lag = max(ac)
    return (round(v, 3), lag) if v > ASSERT_AC else None


# ---------- stage 2: wall seating ------------------

def band_classes(prof):
    """Split bands into thin (grid rules) and thick
    (wall bands); return centers + widths."""
    bs = bands(prof)
    thin, thick = [], []
    for a, b, ws in bs:
        c = cent(ws)
        (thin if b - a + 1 <= THIN_MAX else
         thick).append((c, b - a + 1))
    return thin, thick


def run_spans(binm, w, h, axis, a, b):
    """Ink presence per position along the band
    [a, b] of a wall line. axis 'x' = vertical line:
    one bool per row y; 'y' = horizontal: per col x."""
    out = []
    if axis == "x":
        for y in range(h):
            s = y * w
            out.append(
                binm[s + a:s + b + 1].count(1) > 0)
    else:
        for x in range(w):
            col = binm[x::w]
            out.append(any(col[y] for y in
                           range(a, b + 1)))
    return out


def runs_from_spans(sp, min_len):
    """Group True spans into runs [(start, end)]."""
    out = []
    st = None
    for i, v in enumerate(sp):
        if v and st is None:
            st = i
        elif not v and st is not None:
            if i - st >= min_len:
                out.append((st, i - 1))
            st = None
    if st is not None and len(sp) - st >= min_len:
        out.append((st, len(sp) - 1))
    return out


def quant_residual(lengths, P):
    """Mean |len/P - round(len/P)|: collapses to ~0
    only under the correct convention (sharpest
    discriminator)."""
    if not lengths:
        return 0.0
    return sum(abs(l / P - round(l / P))
               for l in lengths) / len(lengths)


def seating(binm, vo, ho, w, h, gx, gy):
    """Finite brute force: wall comb fit per axis
    (thick bands, pitch seeded by grid pitch x
    print-gap range), then offsets x thickness scored
    by edge agreement + corner closure (wall ends
    land on the CROSS-axis wall comb) + length
    quantization. Offsets are mod-1 deduped so
    -0.5 and +0.5 do not masquerade as rivals."""
    px = col_profile(vo, w, h)
    py = row_profile(ho, w, h)
    walls = {}
    for ax, prof, g in (("x", px, gx), ("y", py, gy)):
        thin, thick = band_classes(prof)
        if len(thick) < 3:
            walls[ax] = None
            continue
        cs = [c for c, _ in thick]
        P, x0, _ = comb_fit(
            cs, WALL_PITCH_LO * g["period"],
            WALL_PITCH_HI * g["period"])
        P, x0, inl, rms = comb_polish(cs, P, x0, 4.0)
        walls[ax] = dict(P=P, x0=x0, rms=rms,
                         thick=thick)
    out = {}
    for ax, prof, g, cross in (
            ("x", px, gx, "y"),
            ("y", py, gy, "x")):
        wl = walls[ax]
        if wl is None:
            out[ax] = dict(state="no-wall-bands")
            continue
        P, x0, thick = wl["P"], wl["x0"], wl["thick"]
        span = (w - 1) if ax == "x" else (h - 1)
        # wall runs for length quantization + ends
        lens, ends = [], []
        for c, wd in thick:
            a = max(0, int(c - wd // 2))
            b = min(span, int(c + wd // 2))
            sp = run_spans(binm, w, h, ax, a, b)
            rs = runs_from_spans(sp, max(3, P / 8.0))
            for st, e in rs:
                lens.append(e - st + 1.0)
                ends.append(float(st))
                ends.append(float(e + 1))
        qres = quant_residual(lens, P)
        xc = walls[cross]
        offs = sorted(set(
            round(o % 1.0, 4) for o in SEAT_OFFSETS))
        cand = []
        for off in offs:
            dev = []
            for c, wd in thick:
                k = round((c - g["phase"]
                           - off * g["period"])
                          / g["period"])
                dev.append(abs(
                    c - g["phase"]
                    - (k + off) * g["period"]))
            erms = (sum(d * d for d in dev)
                    / len(dev)) ** 0.5 if dev else 99.0
            # corner closure: wall ends land on the
            # cross-axis wall comb (perpendicular walls)
            if xc is not None and ends:
                clo = []
                for e in ends:
                    k = round((e - xc["x0"]) / xc["P"])
                    clo.append(abs(
                        e - xc["x0"] - k * xc["P"]))
                crms = (sum(c * c for c in clo)
                        / len(clo)) ** 0.5
            else:
                crms = 0.0
            mt = sum(wd for _, wd in thick) \
                / len(thick) / g["period"]
            th = min(SEAT_THICK,
                     key=lambda t: abs(t - mt))
            cand.append(dict(
                offset=off, thickness=th,
                edge_rms=round(erms, 3),
                closure_rms=round(crms, 3),
                length_quant=round(qres, 4),
                measured_thick=round(mt, 4),
                score=round(erms + crms, 3)))
        cand.sort(key=lambda c: c["score"])
        margin = (cand[1]["score"] - cand[0]["score"]) \
            / cand[1]["score"] if len(cand) > 1 \
            and cand[1]["score"] else 1.0
        out[ax] = dict(
            state="seated",
            wall=dict(period=round(P, 3),
                      phase=round(x0 % P, 3),
                      bands=len(thick),
                      wander_rms=round(wl["rms"], 3)),
            convention=cand[0],
            ranked=cand[:3], margin=round(margin, 3),
            ask=(margin < MARGIN_THIN))
    return out


# ---------- stage 3: scale -------------------------

def scale_statement(dpi, hint_ft, prior_ft):
    """Sources ranked: scale bar / module dims (none
    yet) > DPI+page-format > hint > prior. DPI is a
    fallible witness (trusted:false). Two agreeing =
    confirmed; conflict = ask; none = unknown."""
    srcs = []
    if prior_ft:
        srcs.append(dict(source="prior",
                         ft_per_square=prior_ft,
                         trusted=True))
    if hint_ft:
        srcs.append(dict(source="hint",
                         ft_per_square=hint_ft,
                         trusted=True))
    if dpi:
        srcs.append(dict(source="dpi-metadata",
                         dpi=dpi, trusted=False))
    if len(srcs) >= 2:
        fts = [s["ft_per_square"] for s in srcs
               if s.get("ft_per_square")]
        if len(fts) >= 2:
            a, b = sorted(fts)[0], sorted(fts)[-1]
            if abs(a - b) / max(a, b) <= 0.02:
                return dict(state="confirmed",
                            ft_per_square=a,
                            sources=srcs)
            return dict(state="conflict",
                        sources=srcs,
                        ask=("scale sources disagree "
                             "(%.2f vs %.2f ft/square)"
                             % (a, b)))
    if len(srcs) == 1 and srcs[0].get("ft_per_square"):
        s = srcs[0]
        return dict(state="single-source",
                    ft_per_square=s["ft_per_square"],
                    sources=srcs)
    return dict(state="unknown",
                sources=srcs,
                ask="no scale source available")


# ---------- main ----------------------------------

def analyze(w, h, pix, path=None, hint_ft=None,
            prior=None):
    """Full front half on decoded gray bytes."""
    binm = binarize(pix)
    vo, ho = separate_axes(binm, w, h)
    ast = assert_map(vo, ho, w, h)
    stmt = dict(
        generated=datetime.date.today().isoformat(),
        state=None, asks=[])
    stmt["assert"] = ast
    if ast["state"] != "asserted":
        stmt["state"] = "rejected-not-a-map"
        stmt["asks"] = [ast.get("why", "not a map")]
        return stmt, binm
    hy = hypothesis_set(vo, ho, w, h)
    if not hy["x"] or not hy["y"]:
        stmt["state"] = "assert-no-comb"
        stmt["asks"] = [
            "grid: found axis periodicity but no "
            "seating comb fits the band structure; "
            "is this map printed off-square?"]
        return stmt, binm
    gx, gy = hy["x"][0], hy["y"][0]
    stmt["grid"] = dict(
        period_x=gx["period"], period_y=gy["period"],
        phase_x=gx["phase"], phase_y=gy["phase"],
        score_x=gx["score"], score_y=gy["score"],
        ranked_x=hy["x"][:3], ranked_y=hy["y"][:3])
    hx = pitch_hierarchy(col_profile(vo, w, h),
                         gx["period"])
    hyr = pitch_hierarchy(row_profile(ho, w, h),
                          gy["period"])
    seat = seating(binm, vo, ho, w, h, gx, gy)
    stmt["seating"] = seat
    # lattice statement: cells + origin, the
    # downstream contract (lattice units only)
    nx = int(round((w - gx["phase"]) / gx["period"]))
    ny = int(round((h - gy["phase"]) / gy["period"]))
    stmt["lattice"] = dict(
        cells=dict(nx=nx, ny=ny),
        origin=dict(x=gx["phase"], y=gy["phase"]))
    # provenance: the only place pixels appear
    covx, covy = gx["coverage"], gy["coverage"]
    inkexp = ((covx + covy) / 2.0)
    stmt["ink_explained"] = round(inkexp, 4)
    stmt["provenance"] = dict(
        px=dict(w=w, h=h,
                pitch_x_px=gx["period"],
                pitch_y_px=gy["period"],
                origin_x_px=gx["phase"],
                origin_y_px=gy["phase"]),
        decode="jdec Y plane, Otsu binarize",
        grid=dict(coverage_x=covx, coverage_y=covy,
                  residual_x=gx["residual"],
                  residual_y=gy["residual"]),
        dpi=None)
    if path:
        dpi = jfif_dpi(path)
        stmt["provenance"]["dpi"] = dpi
    else:
        dpi = None
    prior_ft = None
    if isinstance(prior, dict):
        prior_ft = prior.get("ft_per_square")
    stmt["scale"] = scale_statement(
        dpi, hint_ft, prior_ft)
    # asks: ambiguity is a question, never a guess
    for ax in ("x", "y"):
        s = seat.get(ax, {})
        if s.get("state") == "seated" and s.get("ask"):
            stmt["asks"].append(
                "seating on axis %s ambiguous (margin "
                "%.3f): does this wall straddle the "
                "cell line or sit inside it? top: %s"
                % (ax, s["margin"],
                   json.dumps(s["convention"])))
    if hx:
        stmt["asks"].append(
            "pitch hierarchy on x: half-cell or "
            "offset peak (ac %.3f at lag %s) - two-"
            "square modules or print wobble?"
            % (hx[0], hx[1]))
    if hyr:
        stmt["asks"].append(
            "pitch hierarchy on y: half-cell or "
            "offset peak (ac %.3f at lag %s) - two-"
            "square modules or print wobble?"
            % (hyr[0], hyr[1]))
    if stmt["scale"].get("ask"):
        stmt["asks"].append(
            "scale: %s" % stmt["scale"]["ask"])
    stmt["state"] = "ask" if stmt["asks"] \
        else "stated"
    return stmt, binm


def main():
    ap = argparse.ArgumentParser(description=(
        "grid determination - mapbatch v2 front half"))
    ap.add_argument("image")
    ap.add_argument("--lib", help="gridlib.json with "
        "per-pipeline priors (seating, scale)")
    ap.add_argument("--hint-ft", type=float,
                    help="scale hint, ft per square")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()
    prior = {}
    if a.lib and os.path.exists(a.lib):
        prior = json.load(open(a.lib))
    w, h, pix = decode_gray(a.image)
    stmt, _ = analyze(w, h, pix, path=a.image,
                      hint_ft=a.hint_ft, prior=prior)
    outp = os.path.splitext(a.image)[0] + ".grid.json"
    json.dump(stmt, open(outp, "w"), indent=1)
    if not a.quiet:
        print("%s: %s" % (
            os.path.basename(a.image), stmt["state"]))
        ast = stmt["assert"]
        print("  ink %.4f, axes %s" % (
            ast["ink"],
            {k: v[0][2] if v else None
             for k, v in ast["axes"].items()
             if k in ("x", "y")}))
        if stmt["state"] not in (
                "rejected-not-a-map",
                "assert-no-comb"):
            pr = stmt["provenance"]
            print("  grid: P=%.2f Q=%.2f cells %dx%d, "
                  "ink explained %.3f"
                  % (pr["px"]["pitch_x_px"],
                     pr["px"]["pitch_y_px"],
                     stmt["lattice"]["cells"]["nx"],
                     stmt["lattice"]["cells"]["ny"],
                     stmt["ink_explained"]))
            for ax in ("x", "y"):
                s = stmt["seating"].get(ax, {})
                if s.get("state") == "seated":
                    c = s["convention"]
                    print("  seat %s: offset %+.2f "
                          "thick %.3f (measured %.3f), "
                          "quant %.4f, margin %.3f"
                          % (ax, c["offset"],
                             c["thickness"],
                             c["measured_thick"],
                             c["length_quant"],
                             s["margin"]))
            print("  scale: %s" % stmt["scale"]
                  .get("state"))
        for q in stmt["asks"]:
            print("  ASK: %s" % q)
        print("  -> %s" % outp)


if __name__ == "__main__":
    main()

