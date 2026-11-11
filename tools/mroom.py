#!/usr/bin/env python3
"""mroom.py - room wall-trace draft (numeral-first
rebuild, v0.3).

Scans every lattice line in a window - either a
square around a ruled numeral anchor, or an exact
bounding box (--bbox X1,X2,Y1,Y2 in lattice lines;
everything outside the box is ignored). Renders a
wall-map DRAFT: SOLID segments ('|', '-'), GLYPH
partial ink ('+' - door candidates), OPEN gaps
(' '). Door and gap candidates are listed
explicitly with coordinates. Everything here is a
PROPOSAL - Curtiss adjudicates each segment against
the raster; a wall is a wall when he says so.

Usage:
    python3 tools/mroom.py <image> 15,37 [radius]
    python3 tools/mroom.py <image> 16,38 6 \\
        --ledger extract/g1/map-006.ledger.json
    python3 tools/mroom.py <image> --bbox 10,22,32,40 \\
        --ledger extract/g1/map-006.ledger.json --frac

Bbox lines may lie outside the building bbox
(X0..X33, Y0..Y40) - e.g. tower rows to Y42 - the
fit lattice extrapolates. Anchor and --bbox are
mutually exclusive.

Ledger JSON: {"key": [X,Y], ...} - ruled numeral
start cells; marked '*' in the draft with a legend.
Constants copied from hallscan (his fit_lattice fit);
override with --x0/--xpitch/--y0/--ypitch."""
import argparse
import json

X0, XPITCH = 181.95, 64.2742   # X(k) = X0 + XPITCH*k
Y0, YPITCH = 482.00, 64.5875   # Y(k) = Y0 + YPITCH*k
DARK = 128                     # ink threshold
IMGTHRESH = 0.50               # >= -> SOLID
GLYPH = 0.10                   # >= -> GLYPH
NX, NY = 34, 41                # lines X0..X33, Y0..Y40


class Cfg(object):
    def __init__(self, x0, xp, y0, yp, dark, imgh,
                 glyph):
        self.x0, self.xp = x0, xp
        self.y0, self.yp = y0, yp
        self.dark, self.imgh, self.glyph = \
            dark, imgh, glyph
        self.bx = max(2, round(0.15 * xp))
        self.by = max(2, round(0.15 * yp))


def pil_source(path):
    """Pixel source backed by PIL (Termux runs)."""
    from PIL import Image
    img = Image.open(path).convert("L")
    px = img.load()

    class Src(object):
        pass
    s = Src()
    s.w, s.h = img.size

    def get(x, y, _p=px):
        return _p[x, y]
    s.px = get
    return s


def seg_frac(src, axis, k, a, b, cfg):
    """Ink fraction along line k (axis 'v' = X line,
    'h' = Y line) between lattice coords a..b."""
    if axis == "v":
        x = int(round(cfg.x0 + cfg.xp * k))
        xs = range(max(0, x - cfg.bx),
                   min(src.w, x + cfg.bx + 1))
        ys = range(max(0, int(round(
                    cfg.y0 + cfg.yp * a))),
                   min(src.h, int(round(
                    cfg.y0 + cfg.yp * b))))
    else:
        y = int(round(cfg.y0 + cfg.yp * k))
        ys = range(max(0, y - cfg.by),
                   min(src.h, y + cfg.by + 1))
        xs = range(max(0, int(round(
                    cfg.x0 + cfg.xp * a))),
                   min(src.w, int(round(
                    cfg.x0 + cfg.xp * b))))
    tot = hit = 0
    for yy in ys:
        for xx in xs:
            tot += 1
            if src.px(xx, yy) < cfg.dark:
                hit += 1
    return hit / max(1, tot)


def trace(src, bounds, cfg):
    """Scan all line segments in the window given as
    bounds (lox, hix, loy, hiy). Returns dict with
    bounds and per-segment ink:
    v[k][r] = fraction on X line k, cell row r
    (between Y(r) and Y(r+1)); h[k][c] = fraction
    on Y line k, cell column c."""
    lox, hix, loy, hiy = bounds
    v, h = {}, {}
    for k in range(lox, hix + 1):
        v[k] = {}
        for r in range(loy, hiy):
            v[k][r] = seg_frac(src, "v", k,
                               r, r + 1, cfg)
    for k in range(loy, hiy + 1):
        h[k] = {}
        for c in range(lox, hix):
            h[k][c] = seg_frac(src, "h", k,
                               c, c + 1, cfg)
    return dict(lox=lox, hix=hix, loy=loy,
                hiy=hiy, v=v, h=h)


def tag(f, cfg):
    if f >= cfg.imgh:
        return "SOLID"
    if f >= cfg.glyph:
        return "GLYPH"
    return "OPEN"


def render(tr, cfg, anchor, ledger):
    """ASCII wall-map draft; returns the string."""
    lox, hix = tr["lox"], tr["hix"]
    loy, hiy = tr["loy"], tr["hiy"]
    cells = {}
    for key, (x, y) in (ledger or {}).items():
        if lox <= x <= hix - 1 and \
                loy <= y <= hiy - 1:
            cells[(x, y)] = key
    ax, ay = anchor if anchor else (None, None)
    out = []
    ruler = "     " + "".join(
        str(c % 10) if c % 5 == 0 else " "
        for c in range(lox, hix + 1))
    out.append("     X ruler (one col per X "
               "line); Y lines labeled at left")
    for k in range(loy, hiy + 1):
        line = []
        for c in range(lox, hix + 1):
            adj = []
            if c > lox:
                adj.append(tag(tr["h"][k][c - 1],
                               cfg))
            if c < hix:
                adj.append(tag(tr["h"][k][c],
                               cfg))
            if k > loy:
                adj.append(tag(tr["v"][c][k - 1],
                               cfg))
            if k < hiy:
                adj.append(tag(tr["v"][c][k],
                               cfg))
            line.append("+" if any(
                t != "OPEN" for t in adj) else ".")
            if c < hix:
                t = tag(tr["h"][k][c], cfg)
                line.append("-" if t == "SOLID"
                            else "+" if t ==
                            "GLYPH" else " ")
        out.append("Y%-3d %s" % (k, "".join(line)))
        if k < hiy:
            row = []
            for c in range(lox, hix + 1):
                t = tag(tr["v"][c][k], cfg)
                row.append("|" if t == "SOLID"
                           else "+" if t ==
                           "GLYPH" else " ")
                if c < hix:
                    ch = "."
                    if anchor and (c, k) == (ax, ay):
                        ch = "@"
                    elif (c, k) in cells:
                        ch = "*"
                    row.append(ch)
            out.append("    " + "".join(row))
    if cells:
        out.append("")
        out.append("  * ledger: " + "; ".join(
            "%s @ (%d,%d)" % (key, pos[0], pos[1])
            for pos, key in sorted(
                cells.items(),
                key=lambda kv: str(kv[1]))))
    return "\n".join(out)


def runs(tr, cfg, kind):
    """Merged same-tag runs along one axis of the
    window. kind 'v': per X line over cell rows;
    'h': per Y line over cell cols."""
    out = []
    seg = tr[kind]
    for k in sorted(seg):
        items = sorted(seg[k])
        cur, start = None, None
        for u in items:
            t = tag(seg[k][u], cfg)
            if t != cur:
                if cur is not None:
                    out.append((kind, k, start,
                                u - 1, cur))
                cur, start = t, u
        out.append((kind, k, start, items[-1],
                    cur))
    return out


def candidates(tr, cfg):
    """Door candidates (GLYPH runs) and gap
    candidates (short OPEN runs flanked by SOLID
    on the same line)."""
    doors, gaps = [], []
    for kind, k, a, b, t in runs(tr, cfg, "v") + \
            runs(tr, cfg, "h"):
        if t == "GLYPH":
            doors.append("%s%d %ss %d-%d"
                         % ("X" if kind == "v"
                            else "Y", k,
                            "row" if kind == "v"
                            else "col", a, b))
        elif t == "OPEN" and b - a + 1 <= 3:
            seg = tr[kind][k]
            before = tag(seg.get(a - 1, 1.0),
                        cfg) if a - 1 in seg else None
            after = tag(seg.get(b + 1, 1.0),
                       cfg) if b + 1 in seg else None
            if before == "SOLID" and \
                    after == "SOLID":
                gaps.append("%s%d %ss %d-%d"
                            % ("X" if kind == "v"
                               else "Y", k,
                               "row" if kind == "v"
                               else "col", a, b))
    return doors, gaps


def main():
    ap = argparse.ArgumentParser(description=(
        "room wall-trace draft: scan all lines "
        "around a ruled numeral anchor"))
    ap.add_argument("image")
    ap.add_argument("anchor", nargs="?", default=None,
                    help="X,Y of the room's numeral "
                         "anchor (or use --bbox)")
    ap.add_argument("radius", nargs="?", type=int,
                    default=5)
    ap.add_argument("--ledger", default=None)
    ap.add_argument("--bbox", default=None,
                    help="X1,X2,Y1,Y2 lattice lines - "
                         "window is exactly this "
                         "rectangle; everything "
                         "outside is ignored")
    ap.add_argument("--x0", type=float,
                    default=X0)
    ap.add_argument("--xpitch", type=float,
                    default=XPITCH)
    ap.add_argument("--y0", type=float,
                    default=Y0)
    ap.add_argument("--ypitch", type=float,
                    default=YPITCH)
    ap.add_argument("--glyph", type=float,
                    default=GLYPH,
                    help="glyph threshold "
                         "(default 0.10; raise "
                         "in ink-dense zones)")
    ap.add_argument("--imgh", type=float,
                    default=IMGTHRESH)
    ap.add_argument("--frac", action="store_true",
                    help="print per-segment "
                         "ink fractions too")
    a = ap.parse_args()
    if a.bbox:
        if a.anchor:
            ap.error("give either an anchor or "
                     "--bbox, not both")
        bx1, bx2, by1, by2 = (int(v) for v in
                              a.bbox.split(","))
        if not (bx1 < bx2 and by1 < by2):
            ap.error("bbox needs X1<X2 and Y1<Y2")
        lox, hix = max(0, bx1), bx2
        loy, hiy = max(0, by1), by2
        anchor = None
    else:
        if not a.anchor:
            ap.error("give an anchor X,Y or "
                     "--bbox X1,X2,Y1,Y2")
        ax, ay = (int(v) for v in
                  a.anchor.split(","))
        lox = max(0, ax - a.radius)
        hix = min(NX - 1, ax + a.radius)
        loy = max(0, ay - a.radius)
        hiy = min(NY - 1, ay + a.radius)
        anchor = (ax, ay)
    cfg = Cfg(a.x0, a.xpitch, a.y0, a.ypitch,
              DARK, a.imgh, a.glyph)
    src = pil_source(a.image)
    ledger = None
    if a.ledger:
        ledger = json.load(open(a.ledger))
    tr = trace(src, (lox, hix, loy, hiy), cfg)
    print("mroom v0.3 draft - PROPOSAL, "
          "adjudicate against the raster")
    if anchor:
        print("window: X%d..X%d, Y%d..Y%d; anchor "
              "(%d,%d) '@'"
              % (lox, hix, loy, hiy,
                 anchor[0], anchor[1]))
    else:
        print("window (bbox): X%d..X%d, Y%d..Y%d"
              % (lox, hix, loy, hiy))
    print(render(tr, cfg, anchor, ledger))
    if a.frac:
        print()
        print("ink fractions (0.00-1.00 per "
              "segment):")
        for kind, seg in (("X", tr["v"]),
                          ("Y", tr["h"])):
            for k in sorted(seg):
                vals = " ".join(
                    "%.2f" % seg[k][u]
                    for u in sorted(seg[k]))
                lo = min(seg[k])
                print("  %s%-3d %s" % (kind, k,
                                      vals))
            if kind == "X":
                print("  (X rows run Y%d..Y%d)"
                      % (tr["loy"], tr["hiy"]))
    doors, gaps = candidates(tr, cfg)
    print()
    print("door candidates (GLYPH ink):")
    for d in doors:
        print("  %s" % d)
    if not doors:
        print("  (none)")
    print("gap candidates (open runs flanked "
          "by solid walls):")
    for g in gaps:
        print("  %s" % g)
    if not gaps:
        print("  (none)")


if __name__ == "__main__":
    main()
