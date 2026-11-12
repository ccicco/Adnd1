#!/usr/bin/env python3
"""mcomp.py - composition layer: draft the
site grid block from the seated structure
statement + adjudications.

v0.8 (2026-11-07): secret_doors
block (adj["secret_doors"], each
a point record: tile / on_line /
connects / note) - the S mark
seats ON the wall; tiles stay
as composed, the report carries
the secrets list. Tile position
is draft-grade; the geometry
layer pins dcenter from the S
ink centroid.
v0.7 (2026-11-07): override kind
'floor' (drafts '.', for
mis-stamped interiors) and
adj["keys_override"] (label ->
region id) pinning a key's
placement regardless of BFS.
v0.6 (2026-11-07): key placement
prefers FLOOR regions - the BFS
skips corridor slivers and yard
and takes the nearest floor
region (fallback: nearest region
of any kind if no floor within
the search cap).
v0.5 (2026-11-07): numerals whose
tile drafts wall/gate (bold ink
merges with the wall it sits
against) place by BFS to the
nearest region tile; the placed
record carries the search
distance.
v0.4 (2026-11-07): rooms pass -
flood-fill floor/corridor/yard
regions ('.' / ':' / 'y') from
the draft; group gate tiles into
door entities with their connects
(4-connected '+' runs; neighbors
outside the canvas = margin);
reconcile the traced numerals
against the module key list
(1-25, 10A, 18A, A, B).
v0.3 (2026-11-07): fourth ring kind
'open' (drafts ':' like a ruled
opening) for the clean wall
openings his crops ruled.
v0.2 (2026-11-07): ring adjudications
block (adj["ring"] rects, kinds wall /
gate / none) seats the corner + gate
stretches his crops ruled; the report
now splits RING ADJUDICATED vs RING
UNSEATED (none = ruled no-ring, kept
as floor/yard, not flagged).
v0.1 (2026-11-07), frame ruled by Curtiss:
ring center lines x4/x35, y7/y47; canvas
33x42 maps lattice cells x3..35, y6..47
(tile (i,j) = cell (3+i, 6+j)); squares
extent = cells x4..34, y7..46 (31x40).
Walls write CENTER-STRADDLE tile pairs
(line x=k -> canvas cols k-4, k-3; line
y=k -> rows k-7, k-6); the four ring
lines write the canvas boundary ring.
Gaps: default OPENING per adjudications;
ring-line gaps draft as gate proposals
'+'; interior gaps draft as ':' passages.
Yard band = canvas rows 36..40 (cells
y42..46), drafted 'y' under the walls.
Output: <stem>.draft.json (canvas strings
+ report lists) and a printed report.
Geometry only - every ruling is
Curtiss's (app-doctrine)."""

import sys
import os
import json
import argparse

import mstruct

RING_X = (4, 35)
RING_Y = (7, 47)
OX, OY = 3, 6
CANV_W, CANV_H = 33, 42
WALL_CH = "#"
GATE_CH = "+"
OPEN_CH = ":"
YARD_CH = "y"
FLOOR_CH = "."


def revoked_keys(adj):
    out = set()
    for r in adj.get("openings", {}).get(
            "revoked", []):
        out.add((r["axis"], r["line"],
                 r["cells"][0], r["cells"][1]))
    return out


def line_span(axis, k):
    """Canvas coordinate range (two
    straddle positions) of line k."""
    if axis == "x":
        return (k - 1 - OX, k - OX)
    return (k - 1 - OY, k - OY)


def apply_runs(cnv, axis, k, runs):
    s0, s1 = line_span(axis, k)
    for a, b in runs:
        lo = a - (OY if axis == "x"
                  else OX)
        hi = b - (OY if axis == "x"
                  else OX)
        for t in (s0, s1):
            if not (0 <= t < (
                    CANV_W if axis == "x"
                    else CANV_H)):
                continue
            for u in range(max(0, lo),
                           min(CANV_H
                               if axis == "x"
                               else CANV_W,
                               hi + 1)):
                if axis == "x":
                    cnv[u][t] = WALL_CH
                else:
                    cnv[t][u] = WALL_CH


def apply_gap(cnv, axis, k, a, b,
              rev, gates, opens):
    if (axis, k, a, b) in rev:
        return
    s0, s1 = line_span(axis, k)
    lo = a - (OY if axis == "x"
              else OX)
    hi = b - (OY if axis == "x"
              else OX)
    ring = ((axis == "x" and k in
             RING_X) or
            (axis == "y" and k in
             RING_Y))
    ch = GATE_CH if ring else OPEN_CH
    for t in (s0, s1):
        if not (0 <= t < (
                CANV_W if axis == "x"
                else CANV_H)):
            continue
        for u in range(max(0, lo),
                       min(CANV_H
                           if axis == "x"
                           else CANV_W,
                           hi + 1)):
            if axis == "x":
                cnv[u][t] = ch
            else:
                cnv[t][u] = ch
            tgt = (t, u) if axis == "x" \
                else (u, t)
            (gates if ring
             else opens).add(tgt)


def apply_ring(cnv, adj, gates):
    """Seat the adjudicated ring rects
    (kind wall/gate/open/none). Returns
    the set of non-wall ring tiles the
    rulings own (open/none - not
    'unseated' in the report)."""
    ruled = set()
    for r in adj.get("ring", []):
        x0, y0, x1, y1 = r["rect"]
        kind = r["kind"]
        for j in range(y0, y1 + 1):
            for i in range(x0, x1 + 1):
                if not (0 <= i < CANV_W
                        and 0 <= j
                        < CANV_H):
                    continue
                if kind == "wall":
                    cnv[j][i] = WALL_CH
                elif kind == "gate":
                    cnv[j][i] = GATE_CH
                    gates.add((i, j))
                elif kind == "open":
                    cnv[j][i] = OPEN_CH
                    ruled.add((i, j))
                elif kind == "floor":
                    cnv[j][i] = FLOOR_CH
                    ruled.add((i, j))
                else:
                    ruled.add((i, j))
    return ruled


def compose(st, adj):
    rev = revoked_keys(adj)
    cnv = [[FLOOR_CH] * CANV_W
           for _ in range(CANV_H)]
    for j in range(36, 41):
        for i in range(CANV_W):
            cnv[j][i] = YARD_CH
    gates, opens = set(), set()
    skip = 0
    for axis in ("x", "y"):
        for ln in st["lines"][axis]:
            k = ln["index"]
            inside = (axis == "x" and
                      RING_X[0] <= k
                      <= RING_X[1]) or \
                     (axis == "y" and
                      RING_Y[0] <= k
                      <= RING_Y[1])
            if not inside:
                skip += 1
                continue
            apply_runs(cnv, axis, k,
                       ln["runs"])
            for gp in ln["gaps"]:
                a, b = gp["gap"]
                apply_gap(cnv, axis, k,
                          a, b, rev,
                          gates, opens)
    return cnv, gates, opens, skip


def ring_report(cnv, st, ruled):
    """Ring tiles not seated by the
    ring lines' own runs, gaps, or
    adjudications (any ring position
    that nothing made wall, gate, or
    a ruled open/none)."""
    unseated = set()
    for axis in ("x", "y"):
        kl = (RING_X if axis == "x"
              else RING_Y)
        for k in kl:
            s0, s1 = line_span(axis, k)
            for t in (s0, s1):
                if t < 0:
                    continue
                if axis == "x":
                    if t >= CANV_W:
                        continue
                    for j in range(
                            CANV_H):
                        if (t, j) in \
                                ruled:
                            continue
                        if cnv[j][t] \
                           not in (
                                WALL_CH,
                                GATE_CH):
                            unseated.add(
                                (t, j))
                else:
                    if t >= CANV_H:
                        continue
                    for i in range(
                            CANV_W):
                        if (i, t) in \
                                ruled:
                            continue
                        if cnv[t][i] \
                           not in (
                                WALL_CH,
                                GATE_CH):
                            unseated.add(
                                (i, t))
    return sorted(unseated)


MODULE_KEYS = [str(n) for n in
              range(1, 26)] + \
             ["10A", "18A", "A", "B"]

REGION_KINDS = {"floor": FLOOR_CH,
                "corridor": OPEN_CH,
                "yard": YARD_CH}


def regions_of(cnv):
    """Flood-fill connected regions
    per class (floor / corridor /
    yard). Doors and walls bound
    them. Returns regions and a
    tile->region map."""
    reg = [[-1] * CANV_W
           for _ in range(CANV_H)]
    regions = []
    for j in range(CANV_H):
        for i in range(CANV_W):
            if reg[j][i] != -1:
                continue
            ch = cnv[j][i]
            kind = None
            for k, c in \
                    REGION_KINDS.items():
                if c == ch:
                    kind = k
                    break
            if kind is None:
                continue
            rid = len(regions)
            cells = []
            stack = [(i, j)]
            reg[j][i] = rid
            while stack:
                x, y = stack.pop()
                cells.append((x, y))
                for dx, dy in (
                        (1, 0), (-1, 0),
                        (0, 1), (0, -1)):
                    nx, ny = x + dx, \
                        y + dy
                    if not (0 <= nx
                            < CANV_W
                            and 0 <= ny
                            < CANV_H):
                        continue
                    if reg[ny][nx] != -1:
                        continue
                    if cnv[ny][nx] != ch:
                        continue
                    reg[ny][nx] = rid
                    stack.append(
                        (nx, ny))
            xs = [x for x, y in cells]
            ys = [y for x, y in cells]
            regions.append(dict(
                id=rid, kind=kind,
                rect=[min(xs), min(ys),
                      max(xs), max(ys)],
                area=len(cells)))
    return regions, reg


def doors_of(cnv, gates, reg):
    """Group 4-connected gate tiles
    into door entities; report each
    door's neighboring regions (a
    neighbor off-canvas is the
    margin)."""
    tiles = sorted(gates)
    seen = set()
    doors = []
    for t in tiles:
        if t in seen:
            continue
        cells = [t]
        seen.add(t)
        stack = [t]
        while stack:
            x, y = stack.pop()
            for dx, dy in ((1, 0),
                           (-1, 0),
                           (0, 1),
                           (0, -1)):
                n = (x + dx,
                     y + dy)
                if n in gates and \
                        n not in seen:
                    seen.add(n)
                    cells.append(n)
                    stack.append(n)
        xs = [x for x, y in cells]
        ys = [y for x, y in cells]
        sides = []
        for x, y in cells:
            for dx, dy in ((1, 0),
                           (-1, 0),
                           (0, 1),
                           (0, -1)):
                nx, ny = x + dx, \
                    y + dy
                if not (0 <= nx
                        < CANV_W
                        and 0 <= ny
                        < CANV_H):
                    tag = "margin"
                else:
                    rid = reg[ny][nx]
                    if rid >= 0:
                        tag = rid
                    else:
                        ch = cnv[ny][nx]
                        tag = ("wall"
                               if ch ==
                               WALL_CH
                               else "gate")
                if tag not in sides:
                    sides.append(tag)
        doors.append(dict(
            tiles=sorted(cells),
            rect=[min(xs), min(ys),
                  max(xs), max(ys)],
            connects=sides))
    return doors


def nearest_region(reg, regions,
                 ti, tj, want_floor):
    """BFS to the nearest region;
    if want_floor, skip corridor
    and yard (search cap 8;
    fallback: nearest of any
    kind)."""
    seen = {(ti, tj)}
    queue = [(ti, tj, 0)]
    best = (-1, -1)
    while queue:
        qx, qy, qd = queue.pop(0)
        if qd > 8:
            break
        for dx, dy in ((1, 0),
                       (-1, 0),
                       (0, 1),
                       (0, -1),
                       (1, 1), (1, -1),
                       (-1, 1),
                       (-1, -1)):
            nx = qx + dx
            ny = qy + dy
            if not (0 <= nx
                    < CANV_W
                    and 0 <= ny
                    < CANV_H):
                continue
            if (nx, ny) in seen:
                continue
            seen.add((nx, ny))
            rid = reg[ny][nx]
            if rid >= 0:
                if (not want_floor
                        or regions[rid]
                        ["kind"]
                        == "floor"):
                    return rid, qd + 1
                if best[0] < 0:
                    best = (rid,
                            qd + 1)
            queue.append(
                (nx, ny, qd + 1))
    return best


def keys_report(regions, reg, adj):
    """Place the traced numerals in
    their regions; reconcile with
    the module key list."""
    ov = adj.get(
        "keys_override", {})
    placed = []
    for n in adj.get("numerals",
                    []):
        x, y = n["cell"]
        ti, tj = int(x - OX), \
            int(y - OY)
        if not (0 <= ti < CANV_W
                and 0 <= tj
                < CANV_H):
            placed.append(dict(
                label=n["label"],
                tile=[ti, tj],
                region=-2, dist=-1))
            continue
        rid = reg[tj][ti]
        dist = 0
        if rid < 0 or \
                regions[rid]["kind"] \
                != "floor":
            frid, fdist = \
                nearest_region(
                    reg, regions,
                    ti, tj, True)
            if frid >= 0:
                rid, dist = \
                    frid, fdist
        if n["label"] in ov:
            rid = ov[n["label"]]
            dist = -2
        placed.append(dict(
            label=n["label"],
            tile=[ti, tj],
            region=rid,
            dist=dist))
    have = set(p["label"]
               for p in placed)
    return dict(
        module_keys=MODULE_KEYS,
        placed=placed,
        covered=sorted(
            have & set(MODULE_KEYS)),
        extra=sorted(
            have - set(MODULE_KEYS)),
        uncovered=sorted(
            set(MODULE_KEYS) - have))


def floaters(cnv):
    bad = []
    for j in range(CANV_H):
        for i in range(CANV_W):
            if cnv[j][i] != WALL_CH:
                continue
            on_ring = (i in (0,
                             CANV_W - 1)
                       or j in (0,
                                CANV_H
                                - 1))
            if on_ring:
                continue
            ok = False
            for di, dj in ((1, 0),
                           (-1, 0),
                           (0, 1),
                           (0, -1)):
                x = i + di
                y = j + dj
                if 0 <= x < CANV_W \
                        and 0 <= y < \
                        CANV_H and \
                        cnv[y][x] in \
                        (WALL_CH,
                         GATE_CH):
                    ok = True
                    break
            if not ok:
                bad.append((i, j))
    return bad


def main():
    ap = argparse.ArgumentParser(
        description=(
            "compose the draft site "
            "grid block (frame-ruled)"))
    ap.add_argument("grid")
    ap.add_argument("structure")
    ap.add_argument("adjudications")
    ap.add_argument("--out",
                    default=None)
    a = ap.parse_args()
    g = mstruct.load_grid(a.grid)
    st = json.load(open(a.structure))
    adj = json.load(
        open(a.adjudications))
    cnv, gates, opens, skip = \
        compose(st, adj)
    ruled = apply_ring(cnv, adj,
                      gates)
    unseat = ring_report(cnv, st,
                         ruled)
    fl = floaters(cnv)
    regions, regmap = \
        regions_of(cnv)
    doors = doors_of(cnv, gates,
                     regmap)
    keys = keys_report(regions,
                       regmap, adj)
    secrets = []
    for s in adj.get(
            "secret_doors", []):
        ti, tj = s["tile"]
        ok = (0 <= ti < CANV_W
              and 0 <= tj
              < CANV_H)
        secrets.append(dict(
            tile=s["tile"],
            on_line=s.get(
                "on_line"),
            connects=s.get(
                "connects"),
            note=s.get("note"),
            on_canvas=ok))
    strings = ["".join(r)
               for r in cnv]
    numerals = []
    for n in adj.get("numerals",
                     []):
        cx, cy = n["cell"]
        numerals.append(dict(
            label=n["label"],
            canvas=[round(cx - OX, 2),
                    round(cy - OY,
                          2)]))
    draft = dict(
        sheet=adj.get("sheet"),
        canvas_w=CANV_W,
        canvas_h=CANV_H,
        grid=strings,
        gates=sorted(gates),
        openings=sorted(opens),
        ring_unseated=unseat,
        floaters=fl,
        numerals=numerals,
        regions=regions,
        doors=doors,
        secrets=secrets,
        keys=keys)
    outp = a.out or os.path.join(
        os.path.dirname(a.grid),
        "map-006.draft.json")
    json.dump(draft, open(outp, "w"),
              indent=1)
    print("mcomp v0.8: canvas %dx%d"
          % (CANV_W, CANV_H))
    print("  ring adjudicated rects: "
          "%d (none-ruled tiles %d)"
          % (len(adj.get("ring", [])),
             len(ruled)))
    print("  squares 31x40, ring x"
          "%d/x%d y%d/y%d"
          % (RING_X + RING_Y))
    print("  wall/open tiles: see "
          "draft; gates %d, opens %d"
          % (len(gates), len(opens)))
    print("  lines outside frame "
          "skipped: %d" % skip)
    print("  RING UNSEATED: %d"
          % len(unseat))
    for t in unseat[:12]:
        print("    tile", t)
    print("  floaters (no straddle "
          "mate): %d" % len(fl))
    for t in fl[:12]:
        print("    tile", t)
    print("  numerals:",
          [(n["label"],
            n["canvas"])
           for n in numerals])
    kinds = {}
    for r in regions:
        kinds.setdefault(
            r["kind"], []).append(r)
    for k in ("floor",
              "corridor", "yard"):
        rs = kinds.get(k, [])
        print("  regions %-8s: %d "
              "(largest %d)"
              % (k, len(rs),
                 max((r["area"]
                      for r in rs),
                     default=0)))
    print("  door entities: %d"
          % len(doors))
    for d in doors:
        print("    door %s "
              "connects %s"
              % (d["rect"],
                 d["connects"]))
    print("  secret doors: %d"
          % len(secrets))
    for s in secrets:
        print("    secret tile %s "
              "line %s -> %s"
              % (s["tile"],
                 s["on_line"],
                 s["connects"]))
    print("  keys covered: %s"
          % keys["covered"])
    print("  keys extra (not "
          "in module list): %s"
          % keys["extra"])
    print("  keys uncovered: %s"
          % keys["uncovered"])
    print("  -> %s" % outp)


if __name__ == "__main__":
    main()

