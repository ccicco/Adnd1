#!/usr/bin/env python3
"""mseat.py - the back half: seat mapp's labeled rows
onto the mgrid lattice (mapbatch v2, v1.0).

Input: a .grid.json statement (mgrid) + one or more
.match.json row files (mapp). For every row the
tool computes TRUE cell coordinates from the row's
px centroid and the grid's pitch/origin, flags
line-straddling (walls/debris sit on cell lines),
and fits the affine that maps mapp's legacy lat
coords onto the new lattice - that fit MEASURES
where the old lattice's anchored bbox sits inside
the seated page grid (margin offset from data,
not assumption).

Output: <stem>.cells.json beside each match file.
Doctrine: cell units in the body; px appears only
as seating provenance; no map-specific constants;
ambiguity asks, never guesses."""
import argparse
import datetime
import json
import math
import os
import sys


def load_grid(path):
    g = json.load(open(path))
    px = g.get("provenance", {}).get("px")
    lat = g.get("lattice", {})
    if not px or "nx" not in lat.get("cells", {}):
        sys.exit("mseat: %s is not a seated grid "
                 "statement (need provenance.px + "
                 "lattice.cells)" % path)
    if g.get("state") == "rejected-not-a-map":
        sys.exit("mseat: %s is a rejected page - "
                 "nothing to seat" % path)
    return dict(
        P=px["pitch_x_px"], Q=px["pitch_y_px"],
        ox=px["origin_x_px"], oy=px["origin_y_px"],
        nx=lat["cells"]["nx"], ny=lat["cells"]["ny"],
        state=g.get("state"),
        grid_path=os.path.basename(path))


def to_cell(px, gx, gy):
    """px centroid -> float cell position (col, row)
    and integer cell index."""
    cx = (px[0] - gx["ox"]) / gx["P"]
    cy = (px[1] - gx["oy"]) / gx["Q"]
    return cx, cy


def straddle(cx, cy):
    """Distance of a cell position to the nearest
    drawn line, per axis. Wall/debris rows straddle
    (near 0); interior features sit mid-cell
    (near 0.5). Reported, never adjudicated."""
    def near(v):
        f = v - math.floor(v)
        return round(min(f, 1.0 - f), 3)
    return near(cx), near(cy)


def fit_affine(pairs):
    """Least-squares old-lat -> new-cell fit for one
    axis: cell ~= a * lat + b. Returns (a, b, rms).
    This is the margin-offset measurement: the old
    lattice's anchored origin lands at cell b."""
    n = len(pairs)
    if n < 3:
        return None, None, None
    sl = sum(l for l, _ in pairs)
    sc = sum(c for _, c in pairs)
    sll = sum(l * l for l, _ in pairs)
    slc = sum(l * c for l, c in pairs)
    den = n * sll - sl * sl
    if abs(den) < 1e-9:
        return None, None, None
    a = (n * slc - sl * sc) / den
    b = (sc - a * sl) / n
    rms = (sum((c - a * l - b) ** 2
               for l, c in pairs) / n) ** 0.5
    return a, b, round(rms, 3)


def seat(grid, rows):
    """Seat every row; returns (cells, transform,
    asks, tally)."""
    gx, gy = grid, grid
    cells = []
    asks = []
    tally = {}
    px_x, px_y = [], []
    for r in rows:
        px = r.get("px")
        if not px or len(px) != 2:
            asks.append("row %s: no px centroid - "
                        "cannot seat" % r.get("i"))
            continue
        cx, cy = to_cell(px, gx, gy)
        sx, sy = straddle(cx, cy)
        in_grid = (-0.5 <= cx <= grid["nx"] + 0.5
                   and -0.5 <= cy <= grid["ny"] + 0.5)
        lab = r.get("proposal") or "UNKNOWN"
        kind = r.get("kind", "?")
        conf = bool(r.get("confident"))
        tally[(lab, kind, conf)] = \
            tally.get((lab, kind, conf), 0) + 1
        if r.get("lat"):
            px_x.append((r["lat"][0], cx))
            px_y.append((r["lat"][1], cy))
        if not in_grid:
            asks.append(
                "row %s (%s) lands OUTSIDE the "
                "seated grid at cell (%.2f, %.2f) "
                "- grid/image mismatch?"
                % (r.get("i"), lab, cx, cy))
        cells.append(dict(
            i=r.get("i"), label=lab, kind=kind,
            confident=conf,
            cell=[round(cx, 2), round(cy, 2)],
            cell_idx=[int(math.floor(cx)),
                      int(math.floor(cy))],
            straddle=[sx, sy],
            in_grid=in_grid,
            family=r.get("family"),
            dist=r.get("dist"),
            margin=r.get("margin"),
            # px is seating provenance only
            px_provenance=px,
            lat_legacy=r.get("lat")))
    tr = {}
    for ax, pairs in (("x", px_x), ("y", px_y)):
        a, b, rms = fit_affine(pairs)
        if a is None:
            asks.append(
                "affine on axis %s: fewer than 3 "
                "seated rows with lat - no legacy-"
                "lattice offset measurable" % ax)
            tr[ax] = None
        else:
            tr[ax] = dict(scale=round(a, 4),
                          offset=round(b, 3),
                          rms=rms, n=len(pairs))
    return cells, tr, asks, tally


def main():
    ap = argparse.ArgumentParser(description=(
        "seat mapp match rows onto the mgrid "
        "lattice (mapbatch v2 back half)"))
    ap.add_argument("grid")
    ap.add_argument("matches", nargs="+")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()
    grid = load_grid(a.grid)
    for mp in a.matches:
        rows = json.load(open(mp))
        stem = os.path.basename(mp)
        if stem.endswith(".match.json"):
            stem = stem[:-len(".match.json")]
        elif stem.endswith(".json"):
            stem = os.path.splitext(stem)[0]
        cells, tr, asks, tally = seat(grid, rows)
        out = dict(
            generated=datetime.date.today()
            .isoformat(),
            grid=dict(
                source=grid["grid_path"],
                state=grid["state"],
                cells=[grid["nx"], grid["ny"]]),
            lattice=dict(
                pitch=[grid["P"], grid["Q"]],
                origin=[grid["ox"], grid["oy"]],
                nx=grid["nx"], ny=grid["ny"]),
            legacy_transform=tr,
            state="ask" if asks else "stated",
            asks=asks,
            rows=cells)
        op = os.path.join(
            os.path.dirname(os.path.abspath(mp)),
            stem + ".cells.json")
        json.dump(out, open(op, "w"), indent=1)
        if not a.quiet:
            print("%s: %d rows seated on %dx%d, "
                  "%d ask(s)"
                  % (stem, len(cells),
                     grid["nx"], grid["ny"],
                     len(asks)))
            for ax in ("x", "y"):
                t = tr[ax]
                if t:
                    print("  legacy lat->cell %s: "
                          "cell = %.4f*lat + %.3f "
                          "(rms %.2f, n=%d)"
                          % (ax, t["scale"],
                             t["offset"], t["rms"],
                             t["n"]))
            for (lab, kind, conf), n in sorted(
                    tally.items(), key=str):
                print("  %-10s %-9s %s %d"
                      % (lab, kind,
                         "confident" if conf
                         else "review", n))
            for q in asks:
                print("  ASK: %s" % q)
            print("  -> %s" % op)


if __name__ == "__main__":
    main()

