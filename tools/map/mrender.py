#!/usr/bin/env python3
"""mrender.py - make the structure statement
VISIBLE (v1.1: overlay PNG, tile map, and
the completeness audit.

Input: a .grid.json (mgrid) + the .structure.
json (mstruct) beside it; optional .cells.json
(mseat) for seated labels. Three outputs beside
the grid file:
  1. OVERLAY PNG - the raster in grayscale
     with measured wall cells in RED, gap
     candidates in YELLOW, seated labels in
     GREEN. Pure-stdlib PNG writer (zlib +
     struct, jdec in reverse). Compare against
     the raw map: anywhere the red disagrees
     with visible wall ink is a miss to fix.
  2. TILE MAP - the 2x-resolution edge map
     (walls '-'/ '|', gaps '+', enclosed
     floors '.'), the yard-composition
     skeleton.
  3. COMPLETENESS AUDIT - interior-ink census:
     ink BETWEEN the cell lines is invisible
     to the structure pass; sustained interior
     ink that no seated label explains is the
     "unexplained ink" number to drive to zero.

Doctrine unchanged: pure stdlib, cell units,
no map-specific constants, ambiguity asks."""
import argparse
import datetime
import json
import math
import os
import struct
import sys
import zlib

import mgrid
import mstruct

WALL_BAND = 0.12   # line half-width drawn in
                   # the overlay, fraction of
                   # pitch (drawn ink, not a
                   # measurement claim)
GAP_BAND = 0.05    # gap marker half-width
LABEL_R = 0.12     # label dot radius
AUDIT_SKIP = 0.20  # line margin excluded
                   # from interior sampling
AUDIT_HI = 0.20    # sustained interior ink


def load(gpath, spath, cpath):
    g = mstruct.load_grid(gpath)
    st = json.load(open(spath))
    if "lines" not in st:
        sys.exit("mrender: %s is not a "
                 "structure statement" % spath)
    cells = None
    if cpath:
        cells = json.load(open(cpath)) \
            .get("rows", [])
    return g, st, cells


def paths(gpath, cpath):
    stem = os.path.splitext(gpath)[0]
    if stem.endswith(".grid"):
        stem = stem[:-len(".grid")]
    spath = stem + ".grid.structure.json"
    if not os.path.exists(spath):
        spath = os.path.splitext(gpath)[0] \
            + ".structure.json"
    if not os.path.exists(spath):
        sys.exit("mrender: no structure "
                 "statement beside %s (run "
                 "mstruct first)" % gpath)
    if not cpath:
        cp = stem + ".cells.json"
        for cand in (cp,
                     os.path.join(
                         os.path.dirname(
                             os.path.abspath(
                                 gpath)),
                         stem + ".cells.json")):
            if os.path.exists(cand):
                cpath = cand
                break
    return spath, cpath


def write_png(path, w, h, rgb):
    """Minimal 8-bit RGB PNG writer."""
    def chunk(tag, data):
        body = tag + data
        return (struct.pack(">I", len(data))
                + body
                + struct.pack(
                    ">I",
                    zlib.crc32(body)
                    & 0xffffffff))
    ihdr = struct.pack(">IIBBBBB",
                      w, h, 8, 2, 0, 0, 0)
    raw = bytearray()
    stride = w * 3
    for y in range(h):
        raw.append(0)
        raw += rgb[y * stride:
                   (y + 1) * stride]
    data = zlib.compress(bytes(raw), 6)
    with open(path, "wb") as fh:
        fh.write(b"\x89PNG\r\n\x1a\n")
        fh.write(chunk(b"IHDR", ihdr))
        fh.write(chunk(b"IDAT", data))
        fh.write(chunk(b"IEND", b""))


def blend(rgb, w, h, x, y, col):
    if 0 <= x < w and 0 <= y < h:
        i = (y * w + x) * 3
        rgb[i] = (rgb[i] + col[0]) // 2
        rgb[i + 1] = (rgb[i + 1]
                      + col[1]) // 2
        rgb[i + 2] = (rgb[i + 2]
                      + col[2]) // 2


def box(rgb, w, h, x0, y0, x1, y1, col,
        band):
    """Fill a marker band along a line
    segment [x0,y0]-[x1,y1] (axis-aligned,
    thickness 2*band)."""
    for x in range(max(0, int(x0) - 1),
                   min(w, int(x1) + 2)):
        for y in range(max(0, int(y0)),
                       min(h, int(y1) + 1)):
            if band:
                for d in range(-band,
                               band + 1):
                    yy = y + d \
                        if x0 == x1 else y
                    xx = x \
                        if x0 == x1 else x + d
                    blend(rgb, w, h, xx, yy,
                          col)
            else:
                blend(rgb, w, h, x, y, col)


def dot(rgb, w, h, cx, cy, r, col):
    for y in range(max(0, int(cy - r)),
                   min(h, int(cy + r) + 1)):
        for x in range(max(0, int(cx - r)),
                       min(w, int(cx + r)
                           + 1)):
            if (x - cx) ** 2 + (y - cy) ** 2 \
                    <= r * r:
                blend(rgb, w, h, x, y, col)


def grid_overlay(g, w, h, pix, outp):
    """The standing calibration overlay: every
    seated lattice line in red, full length,
    no wall classification at all - the grid
    as geometry, for eyeballing drift,
    double-walling, and boundary features."""
    rgb = bytearray(w * h * 3)
    for i, v in enumerate(pix):
        rgb[3 * i] = rgb[3 * i + 1] \
            = rgb[3 * i + 2] = v
    px = g["provenance"]["px"]
    P, Q = px["pitch_x_px"], px[
        "pitch_y_px"]
    ox, oy = px["origin_x_px"], px[
        "origin_y_px"]
    nx = g["lattice"]["cells"]["nx"]
    ny = g["lattice"]["cells"]["ny"]
    band = 1
    col = (255, 0, 0)
    for k in range(nx + 1):
        x = int(round(ox + k * P))
        for y in range(h):
            for d in range(-band,
                           band + 1):
                blend(rgb, w, h, x + d, y,
                      col)
    for m in range(ny + 1):
        y = int(round(oy + m * Q))
        for x in range(w):
            for d in range(-band,
                           band + 1):
                blend(rgb, w, h, x, y + d,
                      col)
    write_png(outp, w, h, bytes(rgb))


def overlay(g, st, cells, w, h, pix, outp):
    rgb = bytearray(w * h * 3)
    for i, v in enumerate(pix):
        rgb[3 * i] = rgb[3 * i + 1] \
            = rgb[3 * i + 2] = v
    px = g["provenance"]["px"]
    P, Q = px["pitch_x_px"], px["pitch_y_px"]
    ox, oy = px["origin_x_px"], px[
        "origin_y_px"]
    lines = st["lines"]
    wall = (255, 0, 0)
    gapc = (255, 215, 0)
    lab = (0, 200, 0)
    for axis in ("x", "y"):
        for ln in lines[axis]:
            k = ln["index"]
            for a, b in ln["runs"]:
                if axis == "x":
                    box(rgb, w, h,
                        ox + k * P,
                        oy + a * Q,
                        ox + k * P,
                        oy + (b + 1) * Q,
                        wall,
                        int(WALL_BAND * P))
                else:
                    box(rgb, w, h,
                        ox + a * P,
                        oy + k * Q,
                        ox + (b + 1) * P,
                        oy + k * Q,
                        wall,
                        int(WALL_BAND * Q))
            for gp in ln["gaps"]:
                a, b = gp["gap"]
                if axis == "x":
                    box(rgb, w, h,
                        ox + k * P,
                        oy + a * Q,
                        ox + k * P,
                        oy + (b + 1) * Q,
                        gapc,
                        max(2, int(GAP_BAND
                                   * P)))
                else:
                    box(rgb, w, h,
                        ox + a * P,
                        oy + k * Q,
                        ox + (b + 1) * P,
                        oy + k * Q,
                        gapc,
                        max(2, int(GAP_BAND
                                   * Q)))
    if cells:
        for r in cells:
            if not r.get("in_grid") \
                    or not r.get("confident"):
                continue
            cx, cy = r["cell"]
            dot(rgb, w, h, ox + cx * P,
                oy + cy * Q,
                LABEL_R * P, lab)
    write_png(outp, w, h, bytes(rgb))


def edge(g, st, axis, k, j):
    """Wall/gap/None at line k, cell j."""
    if not (0 <= k < len(st["lines"][axis])):
        return None
    ln = st["lines"][axis][k]
    for a, b in ln["runs"]:
        if a <= j <= b:
            return "wall"
    for gp in ln["gaps"]:
        if gp["gap"][0] <= j \
                <= gp["gap"][1]:
            return "gap"
    return None


def tilemap(g, st):
    lat = g["lattice"]["cells"]
    nx, ny = lat["nx"], lat["ny"]
    rows = []
    for r in range(2 * ny + 1):
        row = []
        for c in range(2 * nx + 1):
            if r % 2 == 0 and c % 2 == 1:
                e = edge(g, st, "y",
                         r // 2, (c - 1) // 2)
                row.append("-" if e == "wall"
                           else "+" if e == "gap"
                           else " ")
            elif r % 2 == 1 and c % 2 == 0:
                e = edge(g, st, "x",
                         c // 2, (r - 1) // 2)
                row.append("|" if e == "wall"
                           else "+" if e == "gap"
                           else " ")
            elif r % 2 == 0 and c % 2 == 0:
                jx, jy = c // 2, r // 2
                nb = (edge(g, st, "x", jx, jy),
                      edge(g, st, "x", jx + 1,
                           jy),
                      edge(g, st, "y", jy, jx),
                      edge(g, st, "y", jy + 1,
                           jx))
                row.append("#" if "wall"
                           in nb else "+"
                           if "gap" in nb
                           else ".")
            else:
                jx, jy = (c - 1) // 2, \
                    (r - 1) // 2
                edges = (
                    edge(g, st, "y", jy, jx),
                    edge(g, st, "y", jy + 1,
                         jx),
                    edge(g, st, "x", jx, jy),
                    edge(g, st, "x", jx + 1,
                         jy))
                row.append("." if all(e == "wall"
                                      for e in
                                      edges)
                           else " ")
        rows.append("".join(row))
    return "\n".join(rows) + "\n"


def interior_ink(binm, w, g, jx, jy):
    """Ink fraction of a cell's interior,
    excluding the line margins."""
    px = g["provenance"]["px"]
    P, Q = px["pitch_x_px"], px[
        "pitch_y_px"]
    ox, oy = px["origin_x_px"], px[
        "origin_y_px"]
    x0 = int(round(ox + (jx + AUDIT_SKIP)
                   * P))
    x1 = int(round(ox + (jx + 1
                        - AUDIT_SKIP) * P))
    y0 = int(round(oy + (jy + AUDIT_SKIP)
                   * Q))
    y1 = int(round(oy + (jy + 1
                        - AUDIT_SKIP) * Q))
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


def audit(binm, w, g, cells):
    lat = g["lattice"]["cells"]
    labeled = set()
    if cells:
        for r in cells:
            if r.get("in_grid"):
                labeled.add(tuple(
                    r["cell_idx"]))
    hi = []
    inked = 0
    for jy in range(lat["ny"]):
        for jx in range(lat["nx"]):
            f = interior_ink(binm, w, g,
                             jx, jy)
            if f >= 0.02:
                inked += 1
            if f >= AUDIT_HI:
                hi.append((f, jx, jy,
                           (jx, jy)
                           in labeled))
    hi.sort(reverse=True)
    unexplained = [t for t in hi
                   if not t[3]]
    return dict(
        inked_cells=inked,
        sustained_hi=len(hi),
        labeled_hi=len(hi)
        - len(unexplained),
        unexplained_hi=len(unexplained),
        top=unexplained[:40])


def main():
    ap = argparse.ArgumentParser(description=(
        "render the structure statement: "
        "overlay PNG + tile map + "
        "completeness audit"))
    ap.add_argument("grid")
    ap.add_argument("--cells",
                    help="mseat .cells.json "
                         "(default: beside "
                         "the grid)")
    ap.add_argument("--grid",
                    dest="grid_only",
                    action="store_true",
                    help="write ONLY the "
                         "red lattice "
                         "overlay (grid.png) "
                         "- the standing "
                         "calibration "
                         "artifact")
    ap.add_argument("--quiet",
                    action="store_true")
    a = ap.parse_args()
    stem = os.path.splitext(a.grid)[0]
    if stem.endswith(".grid"):
        stem = stem[:-len(".grid")]
    if a.grid_only:
        # the calibration overlay needs
        # only the grid statement and
        # the raster - never the
        # structure statement
        g = mstruct.load_grid(a.grid)
        rp = mstruct.find_raster(a.grid)
        w, h, pix = mgrid.decode_gray(rp)
        px = g["provenance"]["px"]
        if (w, h) != (px["w"], px["h"]):
            sys.exit(
                "mrender: raster %s is "
                "%dx%d, grid says %dx%d"
                % (rp, w, h, px["w"],
                   px["h"]))
        og = stem + ".grid.png"
        grid_overlay(g, w, h, pix, og)
        if not a.quiet:
            print("%s: grid overlay "
                  "-> %s"
                  % (os.path.basename(
                      a.grid), og))
        return
    spath, cpath = paths(a.grid, a.cells)
    g, st, cells = load(a.grid, spath,
                        cpath)
    rp = mstruct.find_raster(a.grid)
    w, h, pix = mgrid.decode_gray(rp)
    px = g["provenance"]["px"]
    if (w, h) != (px["w"], px["h"]):
        sys.exit("mrender: raster %s is "
                 "%dx%d, grid says %dx%d"
                 % (rp, w, h, px["w"],
                    px["h"]))
    binm = mgrid.binarize(pix)
    opng = stem + ".overlay.png"
    otil = stem + ".tilemap.txt"
    oaud = stem + ".audit.json"
    overlay(g, st, cells, w, h, pix, opng)
    tm = tilemap(g, st)
    open(otil, "w").write(tm)
    ad = audit(binm, w, g, cells)
    json.dump(dict(
        generated=datetime.date.today()
        .isoformat(),
        params=dict(skip=AUDIT_SKIP,
                    hi=AUDIT_HI),
        **ad), open(oaud, "w"), indent=1)
    if not a.quiet:
        print("%s: overlay %dx%d, tile "
              "map, audit"
              % (os.path.basename(a.grid),
                 w, h))
        print("  walls red, gap "
              "candidates yellow, "
              "labels green")
        print("  audit: %d inked "
              "interior cells, %d "
              "sustained (>=%.2f), %d "
              "labeled, %d UNEXPLAINED"
              % (ad["inked_cells"],
                 ad["sustained_hi"],
                 AUDIT_HI,
                 ad["labeled_hi"],
                 ad["unexplained_hi"]))
        for f, jx, jy, _ in ad["top"][:20]:
            print("    cell (%d,%d) "
                  "interior ink %.3f"
                  % (jx, jy, f))
        print("  -> %s" % opng)
        print("  -> %s" % otil)
        print("  -> %s" % oaud)


if __name__ == "__main__":
    main()

