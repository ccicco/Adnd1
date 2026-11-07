#!/usr/bin/env python3
"""mstruct.py - the structure layer: wall runs and
gap geometry from the seated lattice (v1.1.5).

Input: a .grid.json statement (mgrid) + the raster
it came from (same stem by default). Optional
.cells.json (mseat) for label cross-checking.

The seating ruling says walls are drawn ON the cell
lines (offset +0.00), fused with the printed grid
rules wherever both share a line. The v1.2 fixes
live here, not in the lattice:
  (a) band-split by WIDTH: a wall is wide ink
      (thickness > the THIN_MAX rule doctrine),
      a rule is thin - so per position along a
      line, the contiguous ink WIDTH through the
      line center separates wall from a COLLINEAR
      rule (the merged-band case: a gap in a wall
      that shares its line with a rule stays a
      gap, because the rule-only positions are
      thin), and crossing rules add only short
      slivers that never reach the per-cell
      fraction;
  (b) runs are built only from wall cells, so
      they can never stitch across crossing rules
      (the length-quant pollution is gone by
      construction).

Statement: per line, per-cell wall presence -> runs
(cell units) and flanked gaps (door candidates,
GEOMETRY ONLY - door rulings come from wall-gap
geometry + module text + Curtiss, never from
drawn door symbols). Output <stem>.structure.json
beside the grid file. Pure stdlib."""
import argparse
import datetime
import json
import math
import os
import sys

import mgrid

BAND = 0.30      # sampling half-band, fraction of
                 # pitch (well under the half-cell,
                 # so neighbor lines cannot bleed)
WALL = 0.50      # per-cell wide fraction that a
                 # wall clears and slivers cannot
WIDE_MIN = 10.0  # px: contiguous ink width that
                 # is wall, not rule. SET FROM THE
                 # v1.1.3 --widths CENSUS (his run
                 # 2026-11-07): rules 3-4px, walls
                 # 14-22px, valley 10-11px - the
                 # old 6.0 read rule-crossing
                 # slivers as wall (red=grid)
INKED = 0.03     # line inked-cell fraction: below
                 # this a line is empty
GAP_MAX = 3      # cells: widest flanked gap still
                 # reported as a door/opening
                 # candidate; wider = room boundary


def wide_run(binm, w, h, axis, c0, pos):
    """Contiguous ink width through the line
    center c0 at position pos, max over +-1
    position (anti-alias slack). Thin rule ink
      -> rule width; wall ink -> wall width."""
    def inked(cc, p):
        if axis == "x":
            return (0 <= p < h and 0 <= cc < w
                    and binm[p * w + cc])
        return (0 <= p < w and 0 <= cc < h
                and binm[cc * w + p])
    best = 0
    for p in (pos, pos - 1, pos + 1):
        if not inked(int(round(c0)), p):
            continue
        i = j = int(round(c0))
        while inked(i - 1, p):
            i -= 1
        while inked(j + 1, p):
            j += 1
        best = max(best, j - i + 1)
    return best


def sample(binm, w, h, axis, c0, half, a, b):
    """Along positions a..b: (present, wide) 0/1
    lists. present = any ink in the band around
    c0; wide = ink width through c0 >= WIDE_MIN
    (wall), which a collinear rule never is
    (rules print thin). Crossing rules give
    only a few wide positions (their own
    thickness), far below a cell fraction."""
    lo = int(math.floor(c0 - half))
    hi = int(math.ceil(c0 + half))
    present, wide = [], []
    for pos in range(a, b):
        if axis == "x":  # vertical line, scan rows
            lo2 = max(0, lo)
            hi2 = min(w - 1, hi)
            s = pos * w
            pr = binm[s + lo2:s + hi2 + 1] \
                .count(1) > 0
        else:            # horizontal, scan cols
            lo2 = max(0, lo)
            hi2 = min(h - 1, hi)
            pr = binm[pos::w][lo2:hi2 + 1] \
                .count(1) > 0
        wd = wide_run(binm, w, h, axis, c0,
                      pos) >= WIDE_MIN
        present.append(pr)
        wide.append(wd)
    return present, wide


def cell_fracs(binm, w, h, axis, c0, half,
               o_cross, pitch_cross, n_cross):
    """Per cell along the line: (presence
    fraction, wide fraction, edge touch).
    Walls clear WALL on wide; a COLLINEAR
    rule holds presence ~1 but wide 0
    (thin); crossing rules lift a cell by
    only a sliver. edge = wide ink at the
    cell's first or last position: walls
    enter/exit cells at edges (a wall END
    mid-cell still enters from one edge);
    blobs and slivers touch neither."""
    prf, fr, ed = [], [], []
    for j in range(n_cross):
        a = int(round(o_cross + j * pitch_cross))
        b = int(round(o_cross +
                      (j + 1) * pitch_cross))
        a = max(a, 0)
        b = min(b, h if axis == "x" else w)
        if b <= a:
            prf.append(0.0)
            fr.append(0.0)
            ed.append(False)
            continue
        pr, wd = sample(binm, w, h, axis, c0,
                        half, a, b)
        prf.append(sum(pr) / float(len(pr)))
        fr.append(sum(wd) / float(len(wd)))
        ed.append(bool(wd[0] or wd[-1]))
    return prf, fr, ed


def load_grid(path):
    g = json.load(open(path))
    px = g.get("provenance", {}).get("px")
    lat = g.get("lattice", {})
    if not px or "nx" not in lat.get("cells", {}):
        sys.exit("mstruct: %s is not a seated grid "
                 "statement (need provenance.px + "
                 "lattice.cells)" % path)
    if g.get("state") == "rejected-not-a-map":
        sys.exit("mstruct: %s is a rejected page - "
                 "no structure to state" % path)
    return g


def find_raster(gp):
    stem = os.path.splitext(gp)[0]
    if stem.endswith(".grid"):
        stem = stem[:-len(".grid")]
    for ext in (".jpg", ".jpeg", ".png",
                ".JPG", ".JPEG", ".PNG"):
        p = stem + ext
        if os.path.exists(p):
            return p
    sys.exit("mstruct: no raster beside %s (tried "
             ".jpg/.jpeg/.png same stem; use "
             "--raster)" % gp)


WALL_MIN_WIDE = 0.30  # wide-ink coverage
                      # floor under the
                      # end-inclusive path


def is_wall(prf, fr, ed):
    """A cell is wall if wide ink covers WALL
    of its positions (full coverage), OR
    end-inclusive: wide ink covers at least
    a third of the cell AND touches a cell
    edge. A wall ENDING mid-cell enters from
    one edge (that is the case the strict
    fraction missed); blobs and door-leaf
    strokes touch no edge, and crossing
    rules cap at ~0.1 coverage (their own
    thickness), all safely under the floor.
    prf is unused here but kept for the
    statement's provenance."""
    if fr >= WALL:
        return True
    return fr >= WALL_MIN_WIDE and ed


def runs_of(prf, fr, ed):
    """Contiguous wall cells -> [(a, b)] cell
    indices, inclusive. Collinear rules stay
    below every wall test and crossing rules
    add only slivers, so runs never stitch
    across them (fix b)."""
    out = []
    st = None
    for j in range(len(fr)):
        if is_wall(prf[j], fr[j], ed[j]) \
                and st is None:
            st = j
        elif not is_wall(prf[j], fr[j],
                         ed[j]) and st is not None:
            out.append((st, j - 1))
            st = None
    if st is not None:
        out.append((st, len(fr) - 1))
    return out


def gaps_of(runs, fr, gap_max=GAP_MAX):
    """Flanked gaps between consecutive runs:
    door/opening candidates. interior_ink = mean
    wide fraction inside the gap (drawn door-
    leaf strokes would lift it; a hint, never
    evidence)."""
    out = []
    for r1, r2 in zip(runs, runs[1:]):
        a, b = r1[1] + 1, r2[0] - 1
        if a > b or (b - a + 1) > gap_max:
            continue
        seg = fr[a:b + 1]
        out.append(dict(
            gap=[a, b],
            width=b - a + 1,
            interior_ink=round(
                sum(seg) / len(seg), 3)))
    return out


def line_fracs(binm, w, h, g, axis, k):
    """(presence fracs, wide fracs, edge
    touches) along line k of the given
    axis."""
    px = g["provenance"]["px"]
    if axis == "x":  # vertical line k
        c0 = px["origin_x_px"] + k * px[
            "pitch_x_px"]
        return cell_fracs(
            binm, w, h, "x", c0, BAND * px[
                "pitch_x_px"],
            px["origin_y_px"], px["pitch_y_px"],
            g["lattice"]["cells"]["ny"])
    c0 = px["origin_y_px"] + k * px[
        "pitch_y_px"]
    return cell_fracs(
        binm, w, h, "y", c0, BAND * px[
            "pitch_y_px"],
        px["origin_x_px"], px["pitch_x_px"],
        g["lattice"]["cells"]["nx"])


def classify(prf, fr):
    """Line class: empty / crossed / rule / wall /
    wall+rule / mixed. Sustained ink (presence
    ~1) means a COLLINEAR rule or a wall; walls
    clear the wide fraction, collinear rules
    never do (thin); crossing-only lines hold
    only slivers of presence."""
    n = len(fr)
    if n == 0:
        return "empty"
    inked = sum(1 for f in prf if f > 0.05)
    held = sum(1 for f in prf if f >= 0.80)
    walls = sum(1 for f in fr if f >= WALL)
    if inked / n < INKED:
        return "empty"
    if walls == 0 and held / n >= 0.90:
        return "rule"
    if walls and held > walls and \
            held / n >= 0.90:
        return "wall+rule"
    if walls:
        return "wall"
    if held == 0:
        return "crossed"
    return "mixed"


def structure(binm, w, h, g):
    """Full per-line statement for both axes."""
    lat = g["lattice"]["cells"]
    out = {}
    for axis, nlines in (("x", lat["nx"] + 1),
                         ("y", lat["ny"] + 1)):
        lines = []
        for k in range(nlines):
            prf, fr, ed = line_fracs(
                binm, w, h, g, axis, k)
            runs = runs_of(prf, fr, ed)
            lines.append(dict(
                index=k,
                cls=classify(prf, fr),
                inked=round(sum(1 for f in prf
                                if f > 0.05)
                            / max(1, len(fr)), 3),
                wall_cells=sum(
                    1 for j in
                    range(len(fr))
                    if is_wall(prf[j], fr[j],
                               ed[j])),
                runs=runs,
                gaps=gaps_of(runs, fr)))
        out[axis] = lines
    return out


def near_line(v):
    """Fractional distance to the nearest integer
    (cell line). < 0.25 = on a line."""
    f = v - math.floor(v)
    return min(f, 1.0 - f)


def width_census(binm, w, h, g):
    """Measured contiguous ink WIDTH at every
    2nd position along every seated line,
    per axis: per-line stats (count, inked
    fraction, median, p90) plus a global
    width histogram. This is the data the
    rule-vs-wall WIDE_MIN cut comes from -
    never a doctrine constant alone."""
    px = g["provenance"]["px"]
    lat = g["lattice"]["cells"]
    out = {}
    for axis, nlines in (
            ("x", lat["nx"] + 1),
            ("y", lat["ny"] + 1)):
        hist = {}
        lines = []
        pitch_line = px[
            "pitch_x_px" if axis == "x"
            else "pitch_y_px"]
        for k in range(nlines):
            c0 = (px["origin_x_px"] if
                   axis == "x" else
                   px["origin_y_px"]) \
                + k * pitch_line
            oc = (px["origin_y_px"] if
                  axis == "x" else
                  px["origin_x_px"])
            pc = (px["pitch_y_px"] if
                  axis == "x" else
                  px["pitch_x_px"])
            nmax = (h if axis == "x"
                    else w)
            ws = []
            ntot = 0
            ocross = (lat["ny"] if
                      axis == "x"
                      else lat["nx"])
            for p in range(max(0, int(
                    round(oc))), min(nmax,
                    int(round(
                        oc + ocross * pc))),
                    2):
                ntot += 1
                wdth = wide_run(binm, w, h,
                                axis, c0, p)
                if wdth:
                    ws.append(wdth)
                    b = min(wdth, 26)
                    hist[b] = hist.get(b, 0) \
                        + 1
            ss = sorted(ws)
            if ss:
                lines.append(dict(
                    index=k,
                    ink=round(
                        (len(ss) /
                         float(ntot))
                        if ntot else 0.0, 3),
                    median=ss[len(ss)//2],
                    p90=ss[int(
                        0.9 * (len(ss)-1))]))
            else:
                lines.append(dict(
                    index=k, ink=0.0,
                    median=0, p90=0))
        out[axis] = dict(lines=lines,
                         hist=hist)
    return out


def line_samples(binm, w, h, axis, c0,
                 oc, pc, ncell,
                 win=0.40):
    """Sampled ink centers of a line:
    for each along-line position, the
    midpoint of the ink run nearest the
    seated center (window +-win pitch).
    Returns [(p, mid)] - positions with
    no ink in the window are skipped."""
    mids = []
    lo = int(round(c0 - win * pc))
    hi = int(round(c0 + win * pc))

    def ink(cc, pp):
        if axis == "x":
            return (0 <= pp < h
                    and 0 <= cc < w
                    and binm[
                        pp * w + cc])
        return (0 <= pp < w
                and 0 <= cc < h
                and binm[
                    cc * w + pp])

    for p in range(max(0, int(round(oc))),
                    min(h if axis == "x"
                        else w,
                        int(round(
                            oc + ncell
                            * pc))), 4):
        # find every ink run in the
        # window and keep the one whose
        # midpoint is nearest the seated
        # center - a drifted line still
        # measures, it must not be skipped
        best = None
        cc = lo - 1
        while cc <= hi:
            cc += 1
            if not ink(cc, p):
                continue
            i = j = cc
            while ink(i - 1, p):
                i -= 1
            while ink(j + 1, p):
                j += 1
            mid = (i + j) / 2.0
            # a run whose midpoint left
            # the window is a crossing
            # wall fused with this line -
            # reject it, do not let it
            # poison the drift fit
            if lo <= mid <= hi and \
                    (best is None or
                     abs(mid - c0) <
                     abs(best - c0)):
                best = mid
            cc = j + 1
        if best is not None:
            mids.append((p, best))
    return mids


def line_center(binm, w, h, axis, c0,
                oc, pc, ncell,
                win=0.40):
    """Median measured ink center of a
    line (median of line_samples)."""
    mids = [m for _, m in
            line_samples(binm, w, h, axis,
                         c0, oc, pc, ncell,
                         win)]
    if not mids:
        return None
    mids.sort()
    return mids[len(mids) // 2]


def drift(binm, w, h, g):
    """Per-line ink-center residual vs the
    seated lattice + rotation fit. The
    lattice is orthogonal (pitch+origin);
    a skewed scan shows residuals growing
    linearly with line index - the slope
    is the rotation. Returns per-axis:
    residuals per line, fitted slope
    (px per line), rotation angle (deg),
    max drift (px)."""
    px = g["provenance"]["px"]
    lat = g["lattice"]["cells"]
    out = {}
    for axis in ("x", "y"):
        pl = (px["pitch_x_px"] if
              axis == "x" else
              px["pitch_y_px"])
        pc = (px["pitch_y_px"] if
              axis == "x" else
              px["pitch_x_px"])
        o0 = (px["origin_x_px"] if
              axis == "x" else
              px["origin_y_px"])
        oc = (px["origin_y_px"] if
              axis == "x" else
              px["origin_x_px"])
        ncell = (lat["ny"] if
                 axis == "x"
                 else lat["nx"])
        nlines = (lat["nx"] + 1 if
                  axis == "x" else
                  lat["ny"] + 1)
        # sample every line at every
        # inked position, then fit
        # residual = A*p + B*k + C.
        # A (px drift per px along the
        # line) is the rotation: a scan
        # rotated about any center leans
        # every line by sin(theta). The
        # per-line median would cancel
        # the +/- lean at the two ends,
        # so the fit must see p, not k.
        # B (px per line index) is skew.
        pts = []
        for k in range(nlines):
            c0 = o0 + k * pl
            for p, m in line_samples(
                    binm, w, h, axis,
                    c0, oc, pc, ncell):
                pts.append((k, p, m - c0))
        a = b = c = None
        if len(pts) >= 6:
            s1 = s2 = s3 = \
                s11 = s12 = s22 = 0.0
            s111 = s112 = s122 = 0.0
            for k, p, r in pts:
                s1 += k
                s2 += p
                s3 += r
                s11 += k * k
                s12 += k * p
                s22 += p * p
                s111 += k * r
                s112 += p * r
                s122 += r * r
            n = len(pts)
            m_ = [[n, s1, s2],
                  [s1, s11, s12],
                  [s2, s12, s22]]
            v_ = [s3, s111, s112]
            # 3x3 solve via Cramer
            det = (m_[0][0]
                   * (m_[1][1] * m_[2][2]
                      - m_[1][2]
                      * m_[2][1])
                   - m_[0][1]
                   * (m_[1][0] * m_[2][2]
                      - m_[1][2]
                      * m_[2][0])
                   + m_[0][2]
                   * (m_[1][0] * m_[2][1]
                      - m_[1][1]
                      * m_[2][0]))
            if abs(det) > 1e-9:
                def cr(col):
                    mm = [row[:]
                          for row in m_]
                    for rr in range(3):
                        mm[rr][col] = \
                            v_[rr]
                    return ((mm[0][0]
                             * (mm[1][1]
                                * mm[2][2]
                                - mm[1][2]
                                * mm[2][1])
                             - mm[0][1]
                             * (mm[1][0]
                                * mm[2][2]
                                - mm[1][2]
                                * mm[2][0])
                             + mm[0][2]
                             * (mm[1][0]
                                * mm[2][1]
                                - mm[1][1]
                                * mm[2][0]))
                            / det)
                c = cr(0)
                b = cr(1)
                a = cr(2)
        ang = (math.degrees(math.asin(
                    max(-0.999,
                        min(0.999, a))))
               if a is not None
               else None)
        mx = max((abs(r)
                  for _, _, r in pts),
                 default=0.0)
        # per-line median residuals
        # (skew view, kept for print)
        byk = {}
        for k, p, r in pts:
            byk.setdefault(k,
                           []).append(r)
        lines = []
        for k in sorted(byk):
            rs = sorted(byk[k])
            lines.append((k,
                          rs[len(rs)
                             // 2]))
        out[axis] = dict(
            lines=lines,
            rot_slope=a,
            skew_px_per_line=(b if b
                              is None
                              else round(
                                  b, 4)),
            intercept=c,
            rotation_deg=(round(ang, 4)
                          if ang
                          is not None
                          else None),
            max_drift_px=round(mx, 2),
            n=len(pts))
    return out


def probe(binm, w, h, g, cx, cy):
    """Measured ink WIDTH at a cell position, on
    whichever line(s) the position straddles.
    Verdicts: wall (wide ink sustained) /
    thin (inked, median width under
    WIDE_MIN - rule-scale; note max width
    includes CROSSING rules' own length) /
    debris (sparse ink) / no-ink. This is the
    threshold-vs-label arbiter: it reports what
    the ink actually measures, no guessing."""
    px = g["provenance"]["px"]
    out = []
    cands = []
    # (axis, line k, position in CELL units,
    #  line center c0 in px, cross origin in
    #  px, cross pitch in px)
    if near_line(cx) < 0.25:
        cands.append(("x", int(round(cx)), cy,
                      px["origin_x_px"] +
                      int(round(cx)) *
                      px["pitch_x_px"],
                      px["origin_y_px"],
                      px["pitch_y_px"]))
    if near_line(cy) < 0.25:
        cands.append(("y", int(round(cy)), cx,
                      px["origin_y_px"] +
                      int(round(cy)) *
                      px["pitch_y_px"],
                      px["origin_x_px"],
                      px["pitch_x_px"]))
    for axis, k, p0, c0, oc, pc in cands:
        # p0 is in cells: convert to px
        p0px = oc + p0 * pc
        a = max(0, int(round(
            p0px - 0.25 * pc)))
        b = int(round(
            p0px + 0.25 * pc)) + 1
        wd = [wide_run(binm, w, h, axis, c0,
                       p) for p in range(a, b)]
        n = len(wd)
        ink = sum(1 for v in wd if v > 0)
        wide = sum(1 for v in wd
                   if v >= WIDE_MIN)
        mx = max(wd) if wd else 0
        med = sorted(wd)[n // 2] if wd else 0
        if ink == 0:
            v = "no-ink"
        elif wide >= n * 0.5:
            v = "wall"
        elif wide > 0 and wide >= 0.5 * ink:
            v = ("wall-partial (wide %d/%d "
                 "inked; end/corner cell)"
                 % (wide, ink))
        elif ink >= n * 0.5:
            v = "thin (median %dpx, max %dpx)"
            v %= (med, mx)
        else:
            v = "debris (ink %d/%d pos)" % (
                ink, n)
        # the containing cell's statement
        # numbers: the threshold-vs-label
        # evidence, straight from the
        # structure pass's own arrays
        prf, fr, ed = line_fracs(
            binm, w, h, g, axis, k)
        j = min(max(int(math.floor(p0)), 0),
                len(fr) - 1)
        cw = is_wall(prf[j], fr[j], ed[j])
        out.append(dict(
            axis=axis, line=k,
            pos=round(p0, 2),
            max_width_px=mx,
            median_width_px=med,
            inked=ink, of=n, wide=wide,
            verdict=v,
            cell=dict(
                index=j,
                prf=round(prf[j], 3),
                fr=round(fr[j], 3),
                edge=ed[j],
                is_wall=cw)))
    if not out:
        out.append(dict(
            axis=None, line=None,
            pos=None, max_width_px=None,
            median_width_px=None,
            inked=None, of=None, wide=None,
            verdict="off-line (straddles no "
                    "cell line)"))
    return out


def cross_check(struct, cpath, g):
    """mseat wall rows vs measured wall cells.
    A confident/anchored wall row must sit on a
    line whose runs cover its cell. Mismatches
    ask; other labels are counted only."""
    if not cpath:
        return None, []
    rows = json.load(open(cpath)).get("rows", [])
    asks = []
    ok = off = other = 0
    lat = g["lattice"]["cells"]
    for r in rows:
        if not r.get("in_grid"):
            continue
        if (r.get("label") != "wall"
                or not r.get("confident")):
            if r.get("label") != "wall":
                other += 1
            continue
        cx, cy = r["cell"]
        # a wall row straddles ~0 on one axis
        on_x = r["straddle"][0] < 0.25
        on_y = r["straddle"][1] < 0.25
        if not (on_x or on_y):
            off += 1
            asks.append(
                "wall row %s at cell (%.2f, %.2f) "
                "straddles neither axis - not on "
                "any cell line" % (r.get("i"),
                                   cx, cy))
            continue
        hit = False
        # a run over cells a..b spans cell
        # units [a, b+1] (cells are half-
        # open); a mid-cell centroid like
        # 21.51 sits INSIDE its run's last
        # cell, so the right edge is b+1
        # (+0.3 slack for centroid wobble)
        if on_y:  # horizontal wall line
            m = int(round(cy))
            if 0 <= m <= lat["ny"]:
                for a, b in struct["y"][m][
                        "runs"]:
                    if a - 0.3 <= cx \
                            <= b + 1.3:
                        hit = True
        if on_x and not hit:
            k = int(round(cx))
            if 0 <= k <= lat["nx"]:
                for a, b in struct["x"][k][
                        "runs"]:
                    if a - 0.3 <= cy \
                            <= b + 1.3:
                        hit = True
        if hit:
            ok += 1
        else:
            off += 1
            asks.append(
                "wall row %s at cell (%.2f, %.2f) "
                "has NO measured wall run on its "
                "line - label vs geometry mismatch"
                % (r.get("i"), cx, cy))
    return dict(ok=ok, off=off, other=other), \
        asks


def main():
    ap = argparse.ArgumentParser(description=(
        "structure layer: wall runs + gap "
        "geometry from a seated grid"))
    ap.add_argument("grid")
    ap.add_argument("--raster",
                    help="override raster path")
    ap.add_argument("--cells",
                    help="mseat .cells.json for "
                         "label cross-check")
    ap.add_argument("--probe", action="append",
                    metavar="X,Y",
                    help="probe measured ink "
                         "width at a cell "
                         "position, e.g. "
                         "9.41,32.99; repeatable")
    ap.add_argument("--widths",
                    action="store_true",
                    help="dump measured ink "
                         "width stats per "
                         "line + histogram "
                         "(the WIDE_MIN "
                         "cut data)")
    ap.add_argument("--drift",
                    action="store_true",
                    help="measure per-line "
                         "ink-center "
                         "residuals vs the "
                         "lattice + fit "
                         "scan rotation")
    ap.add_argument("--quiet",
                    action="store_true")
    a = ap.parse_args()
    g = load_grid(a.grid)
    rp = a.raster or find_raster(a.grid)
    if a.drift:
        w, h, pix = mgrid.decode_gray(rp)
        binm = mgrid.binarize(pix)
        dr = drift(binm, w, h, g)
        for axis in ("x", "y"):
            d = dr[axis]
            print("drift %s: n=%d rot "
                  "%s deg, skew %s "
                  "px/line, max drift "
                  "%spx"
                  % (axis, d["n"],
                     d["rotation_deg"],
                     d["skew_px_per_line"],
                     d["max_drift_px"]))
            for k, r in d["lines"]:
                print("  line %2d: "
                      "%+.2fpx" % (k, r))
        return
    if a.widths:
        w, h, pix = mgrid.decode_gray(rp)
        binm = mgrid.binarize(pix)
        for axis in ("x", "y"):
            wc = width_census(binm, w, h,
                              g)[axis]
            print("width census %s lines:"
                  % axis)
            for ln in wc["lines"]:
                print("  line %2d: ink "
                      "%.2f median %2d "
                      "p90 %2d"
                      % (ln["index"],
                         ln["ink"],
                         ln["median"],
                         ln["p90"]))
            hs = sorted(wc["hist"]
                        .items())[:26]
            print("  histogram %s"
                  % json.dumps(hs))
        return
    if a.probe:
        w, h, pix = mgrid.decode_gray(rp)
        binm = mgrid.binarize(pix)
        for spec in a.probe:
            cx, cy = [float(t) for t in
                      spec.split(",")[:2]]
            for r in probe(binm, w, h, g,
                           cx, cy):
                if r["axis"]:
                    c = r["cell"]
                    print("probe (%.2f,%.2f) "
                          "%s line %d: max %spx, "
                          "median %spx, inked "
                          "%s/%s, wide %s -> %s; "
                          "cell %d prf %.3f fr "
                          "%.3f edge %s is_wall "
                          "%s"
                          % (cx, cy, r["axis"],
                             r["line"],
                             r["max_width_px"],
                             r["median_width_px"],
                             r["inked"], r["of"],
                             r["wide"],
                             r["verdict"],
                             c["index"],
                             c["prf"], c["fr"],
                             c["edge"],
                             c["is_wall"]))
                else:
                    print("probe (%.2f,%.2f): %s"
                          % (cx, cy,
                             r["verdict"]))
        return
    w, h, pix = mgrid.decode_gray(rp)
    binm = mgrid.binarize(pix)
    px = g["provenance"]["px"]
    if (w, h) != (px["w"], px["h"]):
        sys.exit("mstruct: raster %s is %dx%d, "
                 "grid statement says %dx%d - "
                 "wrong raster?"
                 % (rp, w, h, px["w"], px["h"]))
    st = structure(binm, w, h, g)
    cc, cc_asks = cross_check(st, a.cells, g)
    asks = list(cc_asks)
    out = dict(
        generated=datetime.date.today()
        .isoformat(),
        state=None, asks=asks,
        grid=dict(
            source=os.path.basename(a.grid),
            raster=os.path.basename(rp),
            state=g.get("state"),
            cells=[g["lattice"]["cells"]["nx"],
                   g["lattice"]["cells"]["ny"]]),
        params=dict(
            band=BAND, wall=WALL,
            wall_min_wide=WALL_MIN_WIDE,
            wide_min=WIDE_MIN,
            gap_max=GAP_MAX),
        cross_check=cc,
        lines=st)
    # gap candidates across both axes, one flat
    # list (door rulings are his, not ours)
    cands = []
    for axis in ("x", "y"):
        for ln in st[axis]:
            for gp in ln["gaps"]:
                cands.append(dict(
                    axis=axis, line=ln["index"],
                    **gp))
    out["gap_candidates"] = cands
    out["state"] = "ask" if asks else "stated"
    op = os.path.splitext(a.grid)[0] + \
        ".structure.json"
    json.dump(out, open(op, "w"), indent=1)
    if not a.quiet:
        nr = sum(len(l["runs"])
                 for l in st["x"]) + \
            sum(len(l["runs"])
                for l in st["y"])
        nw = sum(l["wall_cells"]
                 for l in st["x"]) + \
            sum(l["wall_cells"]
                for l in st["y"])
        print("%s: %s, %d wall runs, %d wall "
              "cells, %d gap candidate(s)"
              % (os.path.basename(a.grid),
                 out["state"], nr, nw,
                 len(cands)))
        for axis in ("x", "y"):
            cl = {}
            for l in st[axis]:
                cl[l["cls"]] = cl.get(
                    l["cls"], 0) + 1
            print("  %s lines: %s"
                  % (axis, json.dumps(
                      cl, sort_keys=True)))
        if cc:
            print("  cross-check: %d wall rows "
                  "on runs, %d off, %d other "
                  "labels" % (cc["ok"],
                              cc["off"],
                              cc["other"]))
        for c in cands:
            print("  gap: %s line %d cells "
                  "%d-%d (w %d, ink %.2f)"
                  % (c["axis"], c["line"],
                     c["gap"][0], c["gap"][1],
                     c["width"],
                     c["interior_ink"]))
        for q in asks:
            print("  ASK: %s" % q)
        print("  -> %s" % op)


if __name__ == "__main__":
    main()

