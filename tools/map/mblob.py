#!/usr/bin/env python3
"""mblob.py - the region inventory: what the
interior ink IS, as regions (v1.2).

The completeness audit (mrender) counts
unexplained interior cells but leaves them
as a list; the yard needs them as THINGS.
This tool groups sustained interior-ink
cells into connected regions on the cell
grid and reports each region's geometry:
extent, centroid, ink profile, class
proposal, and whether any seated mapp row
covers it.

Why regions, not blobs: mapbatch's
thickness separation absorbs any ink
thicker than a wall stroke into the wall
layer BEFORE the blob inventory, so solid
drawn masses (the col-11 L, the col-7
column) never become blobs and mapp sees
nothing there. The region inventory works
from the raster + lattice directly - no
cv2, no separation, no shape library.
Class proposals are PROPOSALS; rulings are
Curtiss's (app-doctrine).

Input: a .grid.json statement (mgrid) + the
raster it came from (same stem). Optional
--cells (mseat .cells.json) marks regions
covered by seated rows.
Output: print + <stem>.regions.json.
--crop writes one PNG per region
with unexplained cells (grayscale
raster, region cells red, uncovered
cells yellow, 3x upscale) into
--out DIR (default
~/storage/shared/Pictures, his
viewing path).

Usage:
  mblob.py extract/g1/map-006.grid.json
      [--cells ~/mb6s4/map-006.cells.json]
"""
import sys, os, json, argparse
import mgrid, mstruct, mrender

SKIP = 0.20   # line margin excluded (the
HI = 0.20     # audit's own values, kept
# identical so the numbers reconcile)


def interior_ink(binm, w, g, jx, jy):
    """Ink fraction of a cell's interior,
    excluding the line margins (the
    mrender audit's math, kept identical)."""
    px = g["provenance"]["px"]
    P, Q = (px["pitch_x_px"],
            px["pitch_y_px"])
    ox, oy = (px["origin_x_px"],
              px["origin_y_px"])
    x0 = int(round(ox + (jx + SKIP)
                   * P))
    x1 = int(round(ox + (jx + 1
                        - SKIP) * P))
    y0 = int(round(oy + (jy + SKIP)
                   * Q))
    y1 = int(round(oy + (jy + 1
                        - SKIP) * Q))
    x0, x1 = max(0, x0), min(w, x1)
    if x1 <= x0 or y1 <= y0:
        return 0.0
    n = (x1 - x0) * (y1 - y0)
    if not n:
        return 0.0
    tot = 0
    for y in range(y0, y1):
        tot += binm[y * w + x0:
                    y * w + x1].count(1)
    return tot / float(n)


def regions_of(ink, lat):
    """Connected regions (4-neighborhood)
    of sustained cells. ink[jy][jx] holds
    the interior fraction; returns region
    cell lists."""
    seen = [[False] * lat["nx"]
            for _ in range(lat["ny"])]
    out = []
    for jy in range(lat["ny"]):
        for jx in range(lat["nx"]):
            if seen[jy][jx] or \
                    ink[jy][jx] < HI:
                continue
            # flood fill
            comp = []
            stack = [(jx, jy)]
            seen[jy][jx] = True
            while stack:
                cx, cy = stack.pop()
                comp.append((cx, cy))
                for dx, dy in \
                        ((1, 0), (-1, 0),
                         (0, 1), (0, -1)):
                    nx, ny = (cx + dx,
                              cy + dy)
                    if 0 <= nx < lat["nx"] \
                            and 0 <= ny \
                            < lat["ny"] \
                            and not seen[ny]\
                            [nx] \
                            and ink[ny]\
                            [nx] >= HI:
                        seen[ny][nx] = True
                        stack.append(
                            (nx, ny))
            out.append(comp)
    return out


def classify(comp, ink):
    """Size/shape proposal: single /
    cluster / band / solid. Geometry
    only - identity is a ruling."""
    n = len(comp)
    xs = [c[0] for c in comp]
    ys = [c[1] for c in comp]
    bw = max(xs) - min(xs) + 1
    bh = max(ys) - min(ys) + 1
    fill = n / float(bw * bh)
    aspect = max(bw, bh) / float(
        max(1, min(bw, bh)))
    mean_ink = sum(ink[c[1]][c[0]]
                   for c in comp) / n
    if n == 1:
        cls = "single"
    elif aspect >= 3.0:
        cls = "band"
    elif fill >= 0.80 and mean_ink >= HI:
        cls = "solid"
    else:
        cls = "cluster"
    return cls, bw, bh, fill, \
        round(mean_ink, 3)


def covered(comp, cells):
    """Seated-row labels landing in the
    region. Region-level coverage is
    COARSE: one row anywhere in the
    region covers it - the per-cell
    view (uncovered_cells) reconciles
    with the audit."""
    if not cells:
        return None
    cs = set(comp)
    hits = [r for r in cells
            if r.get("in_grid")
            and tuple(r["cell_idx"])
            in cs]
    if hits:
        return sorted(set(
            r["label"] for r in hits
            if r.get("label")))
    return None


def uncovered(comp, labeled):
    """Region cells with NO seated row
    on them - the audit's unexplained
    view, per cell, inside the region."""
    if labeled is None:
        return list(comp)
    return [c for c in comp
            if tuple(c) not in labeled]


def crop_regions(regs, pix, w, g,
                outdir, stem, z=3):
    """One PNG per region carrying
    unexplained cells: grayscale
    raster crop (bbox + 1-cell
    margin), region cells outlined
    RED, uncovered cells YELLOW, z x
    nearest upscale. Pure stdlib
    (mrender.write_png)."""
    px = g["provenance"]["px"]
    P, Q = (px["pitch_x_px"],
            px["pitch_y_px"])
    ox, oy = (px["origin_x_px"],
              px["origin_y_px"])
    n = 0
    os.makedirs(outdir, exist_ok=True)
    for r in regs:
        if r["n_uncovered"] == 0:
            continue
        n += 1
        bx0, by0, bx1, by1 = r["bbox"]
        cx0 = int(round(ox
                        + (bx0 - 1) * P))
        cx1 = int(round(ox
                        + (bx1 + 2) * P))
        cy0 = int(round(oy
                        + (by0 - 1) * Q))
        cy1 = int(round(oy
                        + (by1 + 2) * Q))
        cx0 = max(0, min(w, cx0))
        cx1 = max(0, min(w, cx1))
        cy0 = max(0, min(px["h"], cy0))
        cy1 = max(0, min(px["h"], cy1))
        if cx1 <= cx0 or cy1 <= cy0:
            continue
        cw, ch = cx1 - cx0, cy1 - cy0
        rgb = bytearray()
        for y in range(ch):
            for x in range(cw):
                v = pix[(cy0 + y) * w
                        + cx0 + x]
                rgb += bytes((v, v, v))
        def mark(cix, ciy, col):
            # cell border in crop coords
            x0 = int(round((ox + cix * P)
                           - cx0))
            x1 = int(round((ox
                            + (cix + 1) * P)
                           - cx0))
            y0 = int(round((oy + ciy * Q)
                           - cy0))
            y1 = int(round((oy
                            + (ciy + 1) * Q)
                           - cy0))
            for xx in range(max(0, x0),
                            min(cw,
                                x1 + 1)):
                for yy in (max(0, y0),
                           min(ch - 1,
                               y1)):
                    i = (yy * cw + xx) \
                        * 3
                    rgb[i] = (rgb[i]
                              + col[0]) \
                        // 2
                    rgb[i + 1] = \
                        (rgb[i + 1]
                         + col[1]) // 2
                    rgb[i + 2] = \
                        (rgb[i + 2]
                         + col[2]) // 2
            for yy in range(max(0, y0),
                            min(ch,
                                y1 + 1)):
                for xx in (max(0, x0),
                           min(cw - 1,
                               x1)):
                    i = (yy * cw + xx) \
                        * 3
                    rgb[i] = (rgb[i]
                              + col[0]) \
                        // 2
                    rgb[i + 1] = \
                        (rgb[i + 1]
                         + col[1]) // 2
                    rgb[i + 2] = \
                        (rgb[i + 2]
                         + col[2]) // 2
        for c in r["cells"]:
            mark(c[0], c[1], (255, 0, 0))
        for c in r["uncovered_cells"]:
            mark(c[0], c[1],
                 (255, 255, 0))
        # z x nearest upscale
        big = bytearray()
        for y in range(ch * z):
            src = y // z
            row = bytearray()
            base = src * cw * 3
            for x in range(cw * z):
                i = base + (x // z) * 3
                row += rgb[i:i + 3]
            big += row
        base = os.path.basename(stem)
        name = ("%s.region-%02d-%s-"
                "%d-%d.png"
                % (base, n, r["cls"],
                   r["bbox"][0],
                   r["bbox"][1]))
        mrender.write_png(
            os.path.join(outdir, name),
            cw * z, ch * z, bytes(big))
    return n


def main():
    ap = argparse.ArgumentParser(
        description=("interior-ink region "
                     "inventory (the "
                     "unexplained-cells "
                     "answer)"))
    ap.add_argument("grid")
    ap.add_argument("--cells",
                    help="mseat .cells.json")
    ap.add_argument("--crop",
                    action="store_true",
                    help="write one PNG "
                         "per unexplained "
                         "region")
    ap.add_argument("--out",
                    default=os.path.expanduser(
                        "~/storage/shared/"
                        "Pictures"),
                    help="crop output dir")
    a = ap.parse_args()
    g = mstruct.load_grid(a.grid)
    rp = mstruct.find_raster(a.grid)
    w, h, pix = mgrid.decode_gray(rp)
    px = g["provenance"]["px"]
    if (w, h) != (px["w"], px["h"]):
        sys.exit("mblob: raster %s is "
                 "%dx%d, grid says %dx%d"
                 % (rp, w, h, px["w"],
                    px["h"]))
    binm = mgrid.binarize(pix)
    lat = g["lattice"]["cells"]
    cells = None
    if a.cells:
        cells = json.load(open(a.cells)) \
            .get("rows", [])
    labeled = set()
    if cells:
        for r in cells:
            if r.get("in_grid"):
                labeled.add(tuple(
                    r["cell_idx"]))
    ink = [[interior_ink(binm, w, g,
                         jx, jy)
            for jx in range(lat["nx"])]
           for jy in range(lat["ny"])]
    regs = regions_of(ink, lat)
    # stats + region records
    out = []
    for comp in regs:
        cls, bw, bh, fill, mi = \
            classify(comp, ink)
        cov = covered(comp, cells)
        x0 = min(c[0] for c in comp)
        y0 = min(c[1] for c in comp)
        cxx = sum(c[0] for c in comp) \
            / len(comp)
        cyy = sum(c[1] for c in comp) \
            / len(comp)
        out.append(dict(
            cls=cls,
            cells=sorted(comp),
            n=len(comp),
            bbox=[x0, y0,
                  x0 + bw - 1,
                  y0 + bh - 1],
            centroid_cell=[round(cxx, 2),
                           round(cyy, 2)],
            centroid_px=[
                round(px["origin_x_px"]
                      + cxx
                      * px["pitch_x_px"],
                      1),
                round(px["origin_y_px"]
                      + cyy
                      * px["pitch_y_px"],
                      1)],
            fill=round(fill, 2),
            mean_ink=mi,
            max_ink=max(
                ink[c[1]][c[0]]
                for c in comp),
            covered=cov))
    out.sort(key=lambda r: -r["n"])
    unlab = [r for r in out
             if r["covered"] is None]
    ncells = sum(r["n"] for r in out)
    for r in out:
        uc = uncovered(r["cells"], labeled
                       if cells else None)
        r["n_uncovered"] = len(uc)
        r["uncovered_cells"] = uc
    nu = sum(r["n_uncovered"]
             for r in out)
    print("%s: %d sustained regions, "
          "%d cells; %d region(s) with "
          "NO seated row; %d uncovered "
          "cells (the audit's "
          "unexplained, reconciled)"
          % (os.path.basename(a.grid),
             len(out), ncells,
             len(unlab), nu))
    from collections import Counter
    cc = Counter(r["cls"] for r in out)
    print("  classes: %s"
          % dict(sorted(
              cc.items())))
    for r in out[:60]:
        print("  %-7s n=%-3d unc=%-3d "
              "bbox %s "
              "ink %.2f/%.2f fill %.2f "
              "at (%.2f,%.2f)%s"
              % (r["cls"], r["n"],
                 r["n_uncovered"],
                 r["bbox"], r["mean_ink"],
                 r["max_ink"], r["fill"],
                 r["centroid_cell"][0],
                 r["centroid_cell"][1],
                 "" if r["covered"]
                 is None
                 else " covered"))
    # the unexplained view: regions by
    # uncovered cells, NOT by size
    partial = [r for r in out
               if 0 < r["n_uncovered"]
               < r["n"]]
    print("  %d fully covered region(s),"
          " %d partially, %d none"
          % (len(out) - len(partial)
             - len(unlab),
             len(partial), len(unlab)))
    stem = os.path.splitext(a.grid)[0]
    if stem.endswith(".grid"):
        stem = stem[:-len(".grid")]
    op = stem + ".regions.json"
    json.dump(dict(
        generated=str(
            __import__("datetime").date
            .today()),
        params=dict(skip=SKIP, hi=HI),
        regions=out), open(op, "w"))
    print("-> %s" % op)
    if a.crop:
        n = crop_regions(out, pix, w,
                         g, a.out, stem)
        print("-> %d region crop(s) "
              "in %s" % (n, a.out))


if __name__ == "__main__":
    main()

