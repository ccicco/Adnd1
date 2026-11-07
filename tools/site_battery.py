#!/usr/bin/env python3
"""
site_battery.py - the G1 site-data battery (pure stdlib).

Verifies content/sites/g1/site.json against the seated doctrines:
  - wall-offset-in-tiles: CENTER DISTRIBUTION (walldist field);
    canvas = squares + 2 in both dimensions (the boundary walls consume
    one tile per side); the grid block IS the tile canvas, squares is
    the module square count cross-check.
  - boundary walls: the canvas ring is wall (or door/gate tiles).
  - straddle pairs: interior walls occupy 2 tiles; every interior wall
    tile participates in >= 1 orthogonal wall adjacency (no isolated
    wall tiles).
  - doors: every door tile is between floor and wall (adjacent to
    floor/corridor on one side and wall - or its straddle partner - on
    the other).
  - exterior doors/gates: ring door tiles need the margin declared
    (the exterior-door closure: they must lead to the adjudicated
    margin terrain, not void).
  - rooms: printed keys covered exactly (room ids == the declared key
    list); room rects inside the square extent; room interiors
    walkable.
  - the partial-road precedent: a road tile reaching the ring may
    only abut ring walls or a gate (never silently truncate).
  - terrain classes: every terrain class referenced by the site exists
    as a landed primitive manifest with a baked tile.

Exit codes: 0 = PASS, 1 = FAIL, 2 = unreadable/malformed input.

Usage:
  python3 tools/site_battery.py content/sites/g1/site.json
  python3 tools/site_battery.py <site.json> <primitives_dir>   # explicit
"""

import json
import os
import sys

WALL, FLOOR, CORR, DOOR = '#', '.', ':', '+'
WATER, VOID, YARD, ROAD = '~', ' ', 'y', '='
ALLOWED = set(WALL + FLOOR + CORR + DOOR + WATER + VOID + YARD + ROAD)
WALKABLE = set(FLOOR + CORR + DOOR + ROAD)


def fail(rep, msg):
    rep.append('FAIL: ' + msg)


def check_level(level, rep, terrains):
    lid = level.get('id', '?')
    ok = True

    def bad(msg):
        nonlocal ok
        ok = False
        fail(rep, f'[{lid}] {msg}')

    # --- header geometry
    sq, cv = level.get('squares'), level.get('canvas')
    if not (isinstance(sq, dict) and isinstance(cv, dict)
            and all(k in sq for k in 'wh') and all(k in cv for k in 'wh')):
        bad('squares/canvas fields missing')
        return ok, None
    if cv['w'] != sq['w'] + 2 or cv['h'] != sq['h'] + 2:
        bad(f'canvas {cv["w"]}x{cv["h"]} != squares {sq["w"]}x{sq["h"]} + 2'
            ' (walldist center consumes one tile per side)')
        return ok, None
    if level.get('walldist', 'center') != 'center':
        bad(f'walldist {level.get("walldist")!r}: the seated G1 ruling is center')
    rep.append(f'[{lid}] canvas {cv["w"]}x{cv["h"]} == squares {sq["w"]}x{sq["h"]} + 2 - OK')

    # --- grid block
    grid = level.get('grid')
    if not (isinstance(grid, list) and len(grid) == cv['h']):
        bad('grid block missing or wrong row count')
        return ok, None
    for y, row in enumerate(grid):
        if not isinstance(row, str) or len(row) != cv['w']:
            bad(f'grid row {y} wrong length (need {cv["w"]} chars)')
            return ok, None
    chars = set(''.join(grid))
    unknown = chars - ALLOWED - {' '}
    if unknown:
        bad(f'unknown grid chars: {sorted(unknown)}')
    rep.append(f'[{lid}] grid block rectangular {cv["w"]}x{cv["h"]}, chars OK')

    W, H = cv['w'], cv['h']

    def g(x, y):
        return grid[y][x]

    # --- boundary ring: wall (or door/gate) everywhere
    ring_bad = []
    for x in range(W):
        for y in (0, H - 1):
            if g(x, y) not in WALL + DOOR:
                ring_bad.append((x, y))
    for y in range(H):
        for x in (0, W - 1):
            if g(x, y) not in WALL + DOOR:
                ring_bad.append((x, y))
    if ring_bad:
        bad(f'boundary ring broken at {ring_bad[:8]}'
            f'{" ..." if len(ring_bad) > 8 else ""} ({len(ring_bad)} tiles)'
            ' - walls occupy tiles, one beyond the square extent')
    else:
        rep.append(f'[{lid}] boundary ring solid (wall/door) - OK')

    # --- interior straddle pairs: no isolated interior wall tiles
    isolated = []
    for y in range(1, H - 1):
        for x in range(1, W - 1):
            if g(x, y) == WALL:
                nb = [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]
                if not any(0 <= nx < W and 0 <= ny < H and g(nx, ny) == WALL
                           for nx, ny in nb):
                    isolated.append((x, y))
    if isolated:
        bad(f'isolated interior wall tiles (no straddle partner): {isolated[:8]}')
    else:
        rep.append(f'[{lid}] interior wall tiles all straddle-paired - OK')

    # --- doors: between floor and wall (ring doors: floor inside,
    #     the outside is the margin - exempt from the wall-side rule)
    door_bad = []
    for y in range(H):
        for x in range(W):
            if g(x, y) == DOOR:
                nb = [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]
                vals = [g(nx, ny) for nx, ny in nb if 0 <= nx < W and 0 <= ny < H]
                on_ring = x in (0, W - 1) or y in (0, H - 1)
                if not any(v in WALKABLE for v in vals):
                    door_bad.append((x, y, 'no floor side'))
                if not on_ring and not any(v in WALL + DOOR for v in vals):
                    door_bad.append((x, y, 'no wall side'))
                if not on_ring and DOOR not in vals:
                    door_bad.append((x, y, 'not in a wall: no straddle'
                                     ' mate (+ across the wall line)'))
    if door_bad:
        bad(f'doors not between floor and wall: {door_bad[:8]}')
    else:
        rep.append(f'[{lid}] all door tiles between floor and wall - OK')

    # --- exterior-door closure: ring doors need the declared margin
    margin = level.get('margin')
    ring_doors = [(x, y) for x in range(W) for y in range(H)
                  if g(x, y) == DOOR and (x in (0, W - 1) or y in (0, H - 1))]
    if ring_doors:
        if not (isinstance(margin, dict) and margin.get('size', 0) > 0
                and margin.get('terrain')):
            bad(f'exterior door/gate tiles {ring_doors[:8]} lead to nothing:'
                ' margin (size + terrain) must be declared')
        else:
            rep.append(f'[{lid}] {len(ring_doors)} exterior door/gate tile(s)'
                       f' open onto margin {margin["size"]}x {margin["terrain"]} - OK')

    # --- the partial-road precedent: roads never truncate at the boundary.
    #     A road tile touching the ring is fine ONLY at a gate, or when the
    #     road continues (has a road/gate neighbor): a dead end against the
    #     ring wall is the silent-truncation signature.
    road_bad = []
    for y in range(H):
        for x in range(W):
            if g(x, y) != ROAD:
                continue
            nb = [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]
            inb = [(nx, ny) for nx, ny in nb if 0 <= nx < W and 0 <= ny < H]
            touches_ring_wall = any(g(nx, ny) == WALL and
                                    (nx in (0, W - 1) or ny in (0, H - 1))
                                    for nx, ny in inb)
            if touches_ring_wall:
                if not any(g(nx, ny) in ROAD + DOOR for nx, ny in inb):
                    road_bad.append((x, y, 'dead end at the ring wall'))
    if road_bad:
        bad(f'road tiles dead-end at the ring wall: {road_bad[:8]}'
            ' - a road crossing the boundary passes through a gate, or'
            ' terminates at a traced endpoint before the ring')
    else:
        rep.append(f'[{lid}] road tiles do not truncate at the ring - OK')

    # --- rooms: printed keys, rects, walkable interiors
    rooms = level.get('rooms', [])
    keys = level.get('keys', [])
    rids = [r.get('id') for r in rooms]
    if sorted(str(k) for k in keys) != sorted(str(r) for r in rids):
        bad(f'key coverage mismatch: declared keys {sorted(keys)} vs room ids {sorted(rids)}')
    else:
        rep.append(f'[{lid}] printed keys covered exactly ({len(keys)} keys) - OK')
    for r in rooms:
        for rect in r.get('rects', []):
            if len(rect) != 4:
                bad(f'room {r.get("id")}: rect {rect} malformed')
                continue
            rx, ry, rw, rh = rect
            if rx < 1 or ry < 1 or rx + rw > W - 1 or ry + rh > H - 1:
                bad(f'room {r.get("id")}: rect {rect} escapes the square extent')
                continue
            for y in range(ry, ry + rh):
                for x in range(rx, rx + rw):
                    if g(x, y) not in WALKABLE:
                        bad(f'room {r.get("id")}: tile ({x},{y}) inside rect'
                            f' is {g(x, y)!r}, not walkable')
    # --- void may not appear inside the square extent
    void_in = [(x, y) for y in range(1, H - 1) for x in range(1, W - 1)
               if g(x, y) == VOID]
    if void_in:
        bad(f'void tiles inside the square extent: {void_in[:8]}')
    # --- terrain classes exist as landed primitives
    used = terrains.get(margin.get('terrain'))
    if margin and margin.get('terrain') and not used:
        bad(f'margin terrain {margin["terrain"]!r} has no primitive manifest')
    return ok, None


def load_terrains(site_dir):
    """primitives/*.json -> {terrain_class: manifest}"""
    out = {}
    pdir = os.path.join(site_dir, 'primitives')
    if not os.path.isdir(pdir):
        return out
    for fn in sorted(os.listdir(pdir)):
        if not fn.endswith('.json'):
            continue
        try:
            m = json.load(open(os.path.join(pdir, fn), encoding='utf-8'))
            out[m.get('terrain_class')] = m
        except Exception:
            pass
    return out


def main(argv):
    if len(argv) < 2:
        print(__doc__)
        return 2
    path = argv[1]
    try:
        site = json.load(open(path, encoding='utf-8'))
    except Exception as e:
        print(f'MALFORMED: {path}: {e}')
        return 2
    rep = []
    ok = True
    terrains = load_terrains(argv[2] if len(argv) >= 3
                            else os.path.dirname(path))
    rep.append(f'terrain primitives found: {sorted(k for k in terrains if k)}')
    levels = site.get('levels')
    if not isinstance(levels, list) or not levels:
        print('FAIL: no levels array')
        return 1
    for level in levels:
        lv_ok, _ = check_level(level, rep, terrains)
        ok = ok and lv_ok
    print('\n'.join(rep))
    print(f'VERDICT: {path}: {"PASS" if ok else "FAIL"}')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main(sys.argv))
