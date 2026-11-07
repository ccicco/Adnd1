#!/usr/bin/env python3
"""fit_lattice - detect the G1 map lattice constants from the image itself.

Anchors: west wall = line X2, east wall = line X33, north wall = Y0,
south wall = Y40 (seated building bbox). Prints constants for hallscan.py
plus a diagnostic listing of every detected wall run.

Usage:
    python3 fit_lattice.py <image>

Verify the diagnostics before trusting the fit:
  - west/east/north/south anchors should be the 4 outermost long runs
  - pitch_x and pitch_y should be ~equal (a scan is uniform)
  - interior lines (X8/X9/X10, Y22) should show small residuals (<2px)
"""
import sys
from PIL import Image

DARK = 128      # ink threshold
PROF = 0.25     # sustained ink fraction for a wall line

def load(path):
    img = Image.open(path).convert("L")
    w, h = img.size
    px = img.load()
    dark = [[1 if px[x, y] < DARK else 0 for x in range(w)] for y in range(h)]
    return dark, w, h

def runs(prof, thresh):
    out = []
    i, n = 0, len(prof)
    while i < n:
        if prof[i] > thresh:
            j = i
            while j < n and prof[j] > thresh:
                j += 1
            seg = prof[i:j]
            out.append({"lo": i, "hi": j - 1,
                        "cent": (i + j - 1) / 2.0,
                        "len": j - i,
                        "val": sum(seg) / (j - i)})
            i = j
        else:
            i += 1
    return out

def main():
    dark, w, h = load(sys.argv[1])
    colprof = [sum(dark[y][x] for y in range(h)) / h for x in range(w)]
    rowprof = [sum(dark[y][x] for x in range(w)) / w for y in range(h)]
    cruns = runs(colprof, PROF)
    rruns = runs(rowprof, PROF)

    maxlen_c = max(r["len"] for r in cruns)
    maxlen_r = max(r["len"] for r in rruns)
    print("== vertical wall runs (len >= 50% of max) ==")
    cqual = [r for r in cruns if r["len"] >= 0.5 * maxlen_c]
    for r in cqual:
        print(f"  run {r['lo']}-{r['hi']} cent={r['cent']:.1f} len={r['len']} ink={r['val']:.2f}")
    print("== horizontal wall runs (len >= 50% of max) ==")
    rqual = [r for r in rruns if r["len"] >= 0.5 * maxlen_r]
    for r in rqual:
        print(f"  run {r['lo']}-{r['hi']} cent={r['cent']:.1f} len={r['len']} ink={r['val']:.2f}")

    west = min(cqual, key=lambda r: r["cent"])
    east = max(cqual, key=lambda r: r["cent"])
    north = min(rqual, key=lambda r: r["cent"])
    south = max(rqual, key=lambda r: r["cent"])

    px_ = (east["cent"] - west["cent"]) / 31.0   # X2 -> X33
    py_ = (south["cent"] - north["cent"]) / 40.0 # Y0 -> Y40
    print()
    print(f"anchors: west={west['cent']:.1f} east={east['cent']:.1f} "
          f"north={north['cent']:.1f} south={south['cent']:.1f}")
    print(f"pitch_x={px_:.4f}  pitch_y={py_:.4f}  (ratio {px_/py_:.3f}; "
          f"a scan should be ~1.0)")

    print()
    print(">>> paste into hallscan.py:")
    print(f"X0, XPITCH = {west['cent'] - 2*px_:.2f}, {px_:.4f}   # X(k) = X0 + XPITCH*k")
    print(f"Y0, YPITCH = {north['cent'] + 0*py_:.2f}, {py_:.4f}    # Y(k) = Y0 + YPITCH*k")

    # residuals: expected interior line vs nearest detected run
    def resid(cent, runs_):
        return min((abs(r["cent"] - cent), r["cent"]) for r in runs_)
    print()
    print("interior-line check (residual should be < 1 pitch):")
    for k in (8, 9, 10, 22):
        xc = west["cent"] + (k - 2) * px_
        d, c = resid(xc, cruns)
        print(f"  X{k}: expected {xc:.1f}, nearest run {c:.1f}, residual {d:.1f}px")
    for k in (22, 30):
        yc = north["cent"] + k * py_
        d, c = resid(yc, rruns)
        print(f"  Y{k}: expected {yc:.1f}, nearest run {c:.1f}, residual {d:.1f}px")

if __name__ == "__main__":
    main()

