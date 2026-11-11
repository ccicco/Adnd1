#!/usr/bin/env python3
"""mnum.py - the numeral census: group digit blobs
into printed numbers and seat each number's exact
cell coordinates (numeral-first rebuild, v0.2).

Input: a seated .grid.json statement (mgrid) + one
or more .match.json row files (mapp). Numeral rows
are selected by proposal label (default: single
digits 0-9; --labels adds names like num12, ONE,
whatever the library taught). Digits are grouped
into one PRINTED NUMBER when close on the same
baseline (numbers may straddle several squares -
the centroid is exact and fractional, cell units).

Output: <stem>.numbers.json beside each match file:
one row per printed number - read proposal, exact
cell centroid, member extent, straddle, per-digit
provenance, ask flags. Reads are PROPOSALS, never
decisions: the census asks, Curtiss adjudicates.

Doctrine: cell units in the body; px only as
provenance; no map-specific constants; ambiguity
asks, never guesses."""
import argparse
import datetime
import json
import math
import os
import sys

# digit grouping: same printed number if within
# MAX_DX columns and MAX_DY rows (cell units).
MAX_DX = 0.75
MAX_DY = 0.30


def load_grid(path):
    g = json.load(open(path))
    px = g.get("provenance", {}).get("px")
    lat = g.get("lattice", {})
    if not px or "nx" not in lat.get("cells", {}):
        sys.exit("mnum: %s is not a seated grid "
                 "statement (need provenance.px + "
                 "lattice.cells)" % path)
    if g.get("state") == "rejected-not-a-map":
        sys.exit("mnum: %s is a rejected page - "
                 "nothing to count" % path)
    return dict(
        P=px["pitch_x_px"], Q=px["pitch_y_px"],
        ox=px["origin_x_px"], oy=px["origin_y_px"],
        nx=lat["cells"]["nx"], ny=lat["cells"]["ny"],
        state=g.get("state"),
        grid_path=os.path.basename(path))


def to_cell(px, gx, gy):
    """px centroid -> float cell position."""
    cx = (px[0] - gx["ox"]) / gx["P"]
    cy = (px[1] - gx["oy"]) / gx["Q"]
    return cx, cy


def straddle(cx, cy):
    """Distance to the nearest drawn line per
    axis (walls ~0, interior ~0.5). Reported,
    never adjudicated."""
    def near(v):
        f = v - math.floor(v)
        return round(min(f, 1.0 - f), 3)
    return near(cx), near(cy)


def is_numeral(row, labels):
    p = row.get("proposal")
    if p is None or p == "UNKNOWN":
        return False
    # whole-number families taught as labels
    # ("12", "20") select by default; any
    # other taught name goes via --labels.
    return p in labels or p.isdigit()


def group_digits(rows):
    """Single-linkage grouping of numeral rows
    into printed numbers (same-baseline rule).
    Returns lists of row dicts, left-to-right
    sorted inside each group."""
    groups = []
    for r in rows:
        placed = False
        for g in groups:
            if any(
                abs(r["cell"][0] - m["cell"][0])
                <= MAX_DX and
                abs(r["cell"][1] - m["cell"][1])
                <= MAX_DY for m in g):
                g.append(r)
                placed = True
                break
        if not placed:
            groups.append([r])
    for g in groups:
        g.sort(key=lambda m: m["cell"][0])
    return groups


def census(grid, rows, labels):
    """Seat and group; returns (numbers, tally,
    asks)."""
    seated, asks, tally = [], [], {}
    for r in rows:
        px = r.get("px")
        if not px or len(px) != 2:
            continue
        cx, cy = to_cell(px, grid, grid)
        seated.append(dict(
            i=r.get("i"), proposal=r.get("proposal"),
            kind=r.get("kind", "?"),
            confident=bool(r.get("confident")),
            family=r.get("family"),
            dist=r.get("dist"), margin=r.get("margin"),
            cell=[cx, cy],
            px_provenance=px, lat_legacy=r.get("lat"),
            numeral=is_numeral(r, labels)))
        p = r.get("proposal") or "UNKNOWN"
        tally[(p, r.get("kind", "?"),
               bool(r.get("confident")))] = \
            tally.get((p, r.get("kind", "?"),
                       bool(r.get("confident"))), 0) + 1
    nums = group_digits(
        [s for s in seated if s["numeral"]])
    numbers = []
    for n, g in enumerate(nums, 1):
        cx = sum(m["cell"][0] for m in g) / len(g)
        cy = sum(m["cell"][1] for m in g) / len(g)
        sx, sy = straddle(cx, cy)
        in_grid = (-0.5 <= cx <= grid["nx"] + 0.5
                   and -0.5 <= cy
                   <= grid["ny"] + 0.5)
        read = "".join(
            str(m["proposal"]) for m in g)
        bad = [m for m in g
               if not m["confident"]]
        if not in_grid:
            asks.append(
                "number %s '%s' at cell (%.2f, "
                "%.2f) lands OUTSIDE the grid"
                % (n, read, cx, cy))
        if bad:
            asks.append(
                "number %s '%s' has %d non-"
                "confident digit(s) - read "
                "needs adjudication"
                % (n, read, len(bad)))
        numbers.append(dict(
            n=n, read=read,
            digits=[m["proposal"] for m in g],
            cell=[round(cx, 3), round(cy, 3)],
            cell_idx=[int(math.floor(cx)),
                      int(math.floor(cy))],
            straddle=[sx, sy],
            in_grid=in_grid,
            extent=dict(
                x=[round(min(m["cell"][0]
                             for m in g), 3),
                   round(max(m["cell"][0]
                             for m in g), 3)],
                y=[round(min(m["cell"][1]
                             for m in g), 3),
                   round(max(m["cell"][1]
                             for m in g), 3)]),
            confident=all(m["confident"]
                          for m in g),
            members=[dict(
                i=m["i"], proposal=m["proposal"],
                kind=m["kind"],
                confident=m["confident"],
                cell=[round(m["cell"][0], 3),
                      round(m["cell"][1], 3)],
                px_provenance=m["px_provenance"])
                for m in g]))
    return numbers, tally, asks, seated


def main():
    ap = argparse.ArgumentParser(description=(
        "numeral census: group digit blobs into "
        "printed numbers, seat exact coordinates "
        "(numeral-first rebuild)"))
    ap.add_argument("grid")
    ap.add_argument("matches", nargs="+")
    ap.add_argument("--labels", default="",
                    help="extra numeral labels "
                         "(comma-separated, e.g. "
                         "num10,twelve)")
    ap.add_argument("--expect", type=int, default=0,
                    help="expected printed-number "
                         "count; a mismatch asks")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()
    grid = load_grid(a.grid)
    labels = set(x for x in
                 (s.strip() for s in
                  a.labels.split(",")) if x)
    for mp in a.matches:
        rows = json.load(open(mp))
        stem = os.path.basename(mp)
        if stem.endswith(".match.json"):
            stem = stem[:-len(".match.json")]
        elif stem.endswith(".json"):
            stem = os.path.splitext(stem)[0]
        numbers, tally, asks, seated = \
            census(grid, rows, labels)
        if a.expect and \
                len(numbers) != a.expect:
            asks.append(
                "census found %d printed "
                "numbers, expected %d - "
                "unfound or unrecognized "
                "numerals?"
                % (len(numbers), a.expect))
        out = dict(
            generated=datetime.date.today()
            .isoformat(),
            grid=dict(
                source=grid["grid_path"],
                state=grid["state"],
                cells=[grid["nx"],
                       grid["ny"]]),
            lattice=dict(
                pitch=[grid["P"], grid["Q"]],
                origin=[grid["ox"],
                        grid["oy"]],
                nx=grid["nx"], ny=grid["ny"]),
            grouping=dict(max_dx=MAX_DX,
                          max_dy=MAX_DY),
            state="ask" if asks else "stated",
            asks=asks,
            numbers=numbers)
        op = os.path.join(
            os.path.dirname(
                os.path.abspath(mp)),
            stem + ".numbers.json")
        json.dump(out, open(op, "w"), indent=1)
        if not a.quiet:
            print("%s: %d seated blobs, %d "
                  "printed numbers, %d ask(s)"
                  % (stem, len(seated),
                     len(numbers), len(asks)))
            print("  %-4s %-6s %-16s %-7s %s"
                  % ("n", "read", "cell",
                     "strdl", "ok"))
            for nb in sorted(numbers,
                             key=lambda b:
                             (b["cell"][1],
                              b["cell"][0])):
                print("  %-4d %-6s (%6.2f,%6.2f) "
                      "(%.2f,%.2f) %s"
                      % (nb["n"], nb["read"],
                         nb["cell"][0],
                         nb["cell"][1],
                         nb["straddle"][0],
                         nb["straddle"][1],
                         "" if nb["confident"]
                         and nb["in_grid"]
                         else "ASK"))
            for (lab, kind, conf), cnt in \
                    sorted(tally.items(),
                           key=str):
                print("  label %-10s %-9s %s %d"
                      % (lab, kind,
                         "confident" if conf
                         else "review", cnt))
            for q in asks:
                print("  ASK: %s" % q)
            print("  -> %s" % op)


if __name__ == "__main__":
    main()

