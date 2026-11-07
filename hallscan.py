#!/usr/bin/env python3
"""hallscan - lattice ink scanner for the G1 map (Termux-friendly).

Reads the map image, scans any lattice line row-by-row (or col-by-col),
and prints a proposed solid/open/door segmentation in edge-list style.

Setup (once, in Termux):
    pkg install python python-pillow python-numpy

Usage (run from anywhere):
    python3 hallscan.py <image> v 8 15 31
    python3 hallscan.py ~/pdf/map-006.jpg v 8 15 31   # vertical line X8, rows 15..31
    python3 hallscan.py map.jpeg h 22 5 15            # horizontal line Y22, cols 5..15

First run fit_lattice.py on your image and paste its constants into
X0/XPITCH/Y0/YPITCH below. BAND auto-scales to the pitch.

Output: per-row ink fraction plus merged runs (SOLID / GLYPH / OPEN).
GLYPH = partial ink: door gaps, swing arcs - check by eye against the map.
"""
import sys
from PIL import Image

X0, XPITCH = 2.0, 19.9        # X(k) = X0 + XPITCH*k  <- replace with fit_lattice output
Y0, YPITCH = 9.5, 20.0        # Y(k) = Y0 + YPITCH*k  <- replace with fit_lattice output
DARK = 128                    # ink threshold
BAND = None                   # auto: 0.15*pitch when None
IMGTHRESH = 0.50              # >= -> SOLID
GLYPH = 0.10                  # >= -> GLYPH (partial ink: doors, arcs)

def main():
    if len(sys.argv) != 6 or sys.argv[2] not in ("v", "h"):
        print(__doc__)
        sys.exit(2)
    imgpath = sys.argv[1]
    axis, k, lo, hi = sys.argv[2], int(sys.argv[3]), int(sys.argv[4]), int(sys.argv[5])
    img = Image.open(imgpath).convert("L")
    px = img.load()
    w, h = img.size
    print(f"image: {imgpath}  ({w}x{h})")
    band_x = BAND or max(2, round(0.15 * XPITCH))
    band_y = BAND or max(2, round(0.15 * YPITCH))
    def frac(pos, a, b):
        # ink fraction in the band around line `pos` between coords a..b
        if axis == "v":
            x = int(round(X0 + XPITCH * pos))
            xs = range(max(0, x - band_x), min(w, x + band_x + 1))
            ys = range(max(0, int(round(Y0 + YPITCH * a))),
                       min(h, int(round(Y0 + YPITCH * b))))
            tot = hit = 0
            for y in ys:
                for x in xs:
                    tot += 1
                    if px[x, y] < DARK: hit += 1
        else:
            y = int(round(Y0 + YPITCH * pos))
            ys = range(max(0, y - band_y), min(h, y + band_y + 1))
            xs = range(max(0, int(round(X0 + XPITCH * a))),
                       min(w, int(round(X0 + XPITCH * b))))
            tot = hit = 0
            for x in xs:
                for y in ys:
                    tot += 1
                    if px[x, y] < DARK: hit += 1
        return hit / max(1, tot)

    unit = "row" if axis == "v" else "col"
    line = ("X" if axis == "v" else "Y") + str(k)
    print(f"--- line {line}, {unit}s {lo}..{hi} ---")
    vals = []
    for u in range(lo, hi + 1):
        f = frac(k, u - 1, u)   # unit u spans lines (u-1)..u
        vals.append((u, f))
    for u, f in vals:
        tag = "SOLID " if f >= IMGTHRESH else ("glyph " if f >= GLYPH else "open  ")
        print(f"  {unit} {u:>3}  {f:4.2f}  {tag}")

    # merge into runs
    def tagof(f): return "SOLID" if f >= IMGTHRESH else ("GLYPH" if f >= GLYPH else "OPEN")
    runs, start, cur = [], lo, tagof(vals[0][1])
    for u, f in vals[1:]:
        t = tagof(f)
        if t != cur:
            runs.append((start, u - 1, cur)); start, cur = u, t
    runs.append((start, hi, cur))
    print(f"  proposed runs on {line}:")
    for a, b, t in runs:
        label = t
        if t == "GLYPH":
            label = "GLYPH (door gap / swing arc? check by eye)"
        print(f"    {unit}s {a}-{b}: {label}")

if __name__ == "__main__":
    main()

