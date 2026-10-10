#!/usr/bin/env python3
# tools/r312_splice.py - R312: the flooded
# crossing wired (the first ENGINE site the
# R311 underwater pins charge).
#
# The pin charge: the DMG surface SWIMMING
# paragraph (rules/underwater.h, R311) -
# swimming impossible in metal armor except
# magic armor (the dog paddle only); leather
# and padded swim at 5 percent drown per
# hour, +2 per 5 pounds of possessions
# BEYOND the armor - now rides a real site:
# the flooded crossing, one water pool per
# delve (the R304 one-per-delve convention).
#
#   (a) rules/swimcross.h - CREATED (the
#       seam, the grenade.h evaluable
#       subset): the armor gate with the
#       magic exception, the load beyond the
#       armor in pounds, the one-roll
#       judgment, the pool judgments.
#   (b) world/map.h - TILE_WATER (5), the
#       walkable fold.
#   (c) game/appstate.h - the placeFlood /
#       enterWater declarations.
#   (d) game/state_core.cpp - the delve
#       calls placeFlood after the locked
#       doors.
#   (e) game/state_dungeon.cpp - the site:
#       the swimcross include, placeFlood
#       (a 2-3 by 2-3 floor sheet clear of
#       the stairs and the entry) and
#       enterWater (the gate blocks on the
#       first living metal-armored member,
#       magic armor dog paddles; the passing
#       company rolls the R311 drown percent
#       once per living swimmer).
#   (f) adnd1.cpp - the movement gate at the
#       water tile and the water brush.
#   (g) regtest.cpp - the include line.
#   (h) regtest.cpp - the R312a seam audit
#       (audit_eval) and the R312 engine
#       audit (seeded scenarios the replica
#       walked first); the battery census
#       moves 235 -> 237.
#   (i) tools/dmg_gap_report.md - the
#       chronicle paragraph (no box flip -
#       the dmg ledger holds ZERO open
#       items).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY
# patch (the R142 lesson). ZERO literal
# backslash bytes in this file except the
# printf continuations, built via chr(92); no
# CONTENT string embeds an apostrophe,
# non-ASCII, or a line past its bound (78 the
# header, 76 regtest, 57 the gap report).
# Commit: "R312: the flooded crossing wired
# (census 237)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
Q = chr(39)
DQ = chr(34)
BS = chr(92)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit, gap=False):
    if gap:
        assert Q not in s, 'apostrophe in gap content'
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

def counts(s):
    return (s.count('{'), s.count('}'),
            s.count('('), s.count(')'))

def _ctrunc(a, b):
    # C integer division (truncation toward
    # zero) - the audit_eval mirror
    q = abs(a) // abs(b)
    return q if (a >= 0) == (b >= 0) else -q

# ---- the replica (the seeded sequences) ----
UMASK = (1 << 64) - 1

class _Rep:
    def __init__(self, s):
        self.st = s if s != 0 else 0x9E3779B97F4A7C15

    def nxt(self):
        self.st ^= self.st >> 12
        self.st &= UMASK
        self.st ^= (self.st << 25) & UMASK
        self.st &= UMASK
        self.st ^= self.st >> 27
        return (self.st * 0x2545F4914F6CDD1D) & UMASK

    def below(self, n):
        if n <= 1:
            return 0
        lim = UMASK - (UMASK % n)
        while True:
            v = self.nxt()
            if v < lim:
                return v % n

    def rrange(self, lo, hi):
        if hi <= lo:
            return lo
        return lo + self.below(hi - lo + 1)

def _replica_flood(rep, is_floor, sx, sy):
    # the placeFlood draw walk: returns the
    # placed rect (x, y, w, h) or None
    placed = 0
    guard = 0
    while placed < 1:
        guard += 1
        if not (guard < 500):
            break
        x = 1 + rep.below(62)
        y = 1 + rep.below(62)
        w = rep.rrange(2, 3)
        h = rep.rrange(2, 3)
        allf = True
        for yy in range(y, y + h):
            for xx in range(x, x + w):
                if not is_floor(xx, yy):
                    allf = False
        if not allf:
            continue
        on_s = (sx >= x and sx < x + w and
                sy >= y and sy < y + h)
        if on_s:
            continue
        placed += 1
        return (x, y, w, h)
    return None

def _sanity():
    # the seam walks (the audit_eval mirror)
    for _i in range(10):
        _v = 1 if _i <= 2 else 0
        assert _v == (1 if _i <= 2 else 0), 'armor walk'
    assert 20 + _ctrunc(250, 100) == 22, 'cap adj'
    # the load beyond the armor: 1 pound =
    # 10 g.p., C truncation, the clamp
    assert _ctrunc(170 - 150, 10) == 2, 'load 2'
    assert _ctrunc(1550 - 1500, 10) == 5, 'load 5'
    assert _ctrunc(50 - 100, 10) == -5, 'load neg'
    # the drown band probes (the R311 pin)
    for _l, _p in ((0, 5), (2, 5), (5, 7), (25, 15)):
        _c = max(0, _l)
        assert 5 + 2 * (_c // 5) == _p, 'drown band'
    # scenario 1: seed 3 accepts on the FIRST
    # draw - the pool x 6 y 22, 2 by 2
    _r = _Rep(3)
    _rect = _replica_flood(
        _r,
        lambda xx, yy: 0 <= xx <= 63 and
                       20 <= yy <= 25, 2, 2)
    assert _rect == (6, 22, 2, 2), 'flood seed 3'
    # scenario 2: seed 4 - the only 2x2 floor
    # pocket holds the stairs, nothing places
    _r = _Rep(4)
    _rect = _replica_flood(
        _r,
        lambda xx, yy: 10 <= xx <= 11 and
                       10 <= yy <= 11, 10, 10)
    assert _rect is None, 'flood seed 4'
    # scenario 3: seed 1 - the blocked bump
    # draws the wander d12 only, and it
    # reads 2 (quiet, the 1-in-12 chance)
    _r = _Rep(1)
    assert 1 + _r.below(12) == 2, 'wander d12 seed 1'
    # the drown boundary: the bare leather
    # swimmer carries 2 pounds beyond the
    # armor (the dagger), the percent 5
    for _s, _v in ((60, 7), (69, 4), (180, 5),
                   (91, 9)):
        assert _Rep(_s).below(100) == _v, (
            'drown roll seed ' + str(_s))
_sanity()

# ---- (a) rules/swimcross.h CREATED ----
SB = NL.join(
    ['// ====================================================================',
     '// Adnd1 - rules/swimcross.h',
     '// R312: the DMG surface SWIMMING',
     '// paragraph (the R311 pins,',
     '// rules/underwater.h) WIRED as the',
     '// flooded crossing - the first ENGINE',
     '// site the underwater data charges.',
     '//',
     '// The print (the SWIMMING note before',
     '// UNDERWATER ADVENTURES): swimming is',
     '// impossible in any metal armor except',
     '// magic armor (the dog paddle the only',
     '// stroke possible); leather and padded',
     '// armor swim with a 5 percent drown',
     '// chance per hour, +2 percent per 5',
     '// pounds of possessions beyond the',
     '// armor. The engine counts the worn',
     '// armor OUT of the load (1 pound = 10',
     '// g.p. of weight, the engine unit), and',
     '// a water entry is a crossing, so the',
     '// per-hour percent condenses to ONE',
     '// roll per living member per entry (the',
     '// JUDGMENT; the print carries no',
     '// per-entry count).',
     '//',
     '// The site: one flooded pool per delve',
     '// (the R304 one-per-delve convention;',
     '// the count JUDGMENT), a 2-3 by 2-3 tile',
     '// sheet of open floor clear of the',
     '// stairs and the entry. The underwater',
     '// MOVEMENT, VISION and COMBAT paragraphs',
     '// stay data (no underwater combat layer',
     '// exists - a future seam); the spell',
     '// lists ride R168 (rules/uwspells.h).',
     '//',
     '// The armor ids read plain ints (the',
     '// items::ArmorId order): 0 none, 1',
     '// padded, 2 leather, 3 studded, 4 ring,',
     '// 5 scale, 6 chain, 7 splinted, 8 banded,',
     '// 9 plate. Studded leather reads METAL',
     '// (the studs; the JUDGMENT - the engine',
     '// ARMOR_LEATHER weight class is the',
     '// class-restriction grain, not the swim',
     '// gate).',
     '// ====================================================================',
     '',
     '#pragma once',
     '',
     'namespace rules {',
     '',
     '// The armor swim gate: 1 when the armor',
     '// swims (none, padded, leather), 0 when',
     '// the metal armors bar the water.',
     'inline int swimArmorSwims(int armorId) {',
     '    return armorId <= 2 ? 1 : 0;',
     '}',
     '',
     '// Magic armor excepts the metal ban (the',
     '// dog paddle the only stroke possible).',
     'inline int swimMagicArmorSwims() {',
     '    return 1;',
     '}',
     '',
     '// The crossing gate: enchanted armor dog',
     '// paddles, plain armor reads the metal',
     '// ban.',
     'inline int swimCanSwim(int armorId, int armorPlus) {',
     '    return armorPlus > 0 ? swimMagicArmorSwims()',
     '                         : swimArmorSwims(armorId);',
     '}',
     '',
     '// The load beyond the worn armor, in',
     '// pounds (1 pound = 10 g.p.; the print',
     '// counts the possessions BEYOND the',
     '// armor), the negatives clamped.',
     'inline int swimLoadBeyondArmorLbs(int carriedGp,',
     '                                  int armorGp) {',
     '    int lbs = (carriedGp - armorGp) / 10;',
     '    if (lbs < 0) lbs = 0;',
     '    return lbs;',
     '}',
     '',
     '// The drown roll cadence: one roll per',
     '// living member per water entry (the',
     '// JUDGMENT - the per-hour print percent',
     '// condensed to the crossing).',
     'inline int swimDrownRollPerCrossing() {',
     '    return 1;',
     '}',
     '',
     '// The flooded pool count: one per delve',
     '// (the R304 one-per-delve convention; the',
     '// JUDGMENT).',
     'inline int floodPerDelveCount() {',
     '    return 1;',
     '}',
     '',
     '// The pool side floor: 2-3 tiles a side',
     '// (the JUDGMENT).',
     'inline int floodSideMin() {',
     '    return 2;',
     '}',
     '',
     'inline int floodSideMax() {',
     '    return 3;',
     '}',
     '',
     '}  // namespace rules',
     '',
     ])
clean(SB, 78)
assert Q not in SB, 'apostrophe in header'

p = 'rules/swimcross.h'
if os.path.exists(os.path.join(ROOT, p)):
    s = rd(p)
    if 'inline int swimArmorSwims(int armorId) {' in s:
        already.append('swimcross.h created')
    else:
        fails.append('swimcross.h exists without the R312 marker')
else:
    wr(p, SB)
    applied.append('swimcross.h created')

s = rd(p)
assert Q not in s, 'sb apostrophes'
assert s.count('namespace rules') == 2, 'sb namespace pair'
assert s.count('}  // namespace rules') == 1, 'sb namespace close'
assert s.count('{') == s.count('}'), 'sb brace balance'
assert s.count('(') == s.count(')'), 'sb paren balance'
assert s.count('inline int swim') == 5, 'sb swim accessors'
assert s.count('inline int flood') == 3, 'sb flood accessors'
assert s.count('return armorId <= 2 ? 1 : 0;') == 1, 'sb gate pin'
assert s.count('int lbs = (carriedGp - armorGp) / 10;') == 1, 'sb load pin'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) world/map.h: the water tile ----
MAP_C_OLD = NL.join([
    '// Tile types (0 = void/rock, 1 = floor, 2 = wall, 3 = door, 4 = corridor)',
])
MAP_C_NEW = NL.join([
    '// Tile types (0 = void/rock, 1 = floor, 2 = wall,',
    '// 3 = door, 4 = corridor, 5 = water)',
])
MAP_E_OLD = NL.join([
    '    TILE_CORR     = 4,',
])
MAP_E_NEW = NL.join([
    '    TILE_CORR     = 4,',
    '    TILE_WATER    = 5,   // R312: the flooded crossing',
])
MAP_W_OLD = NL.join([
    '        return t == TILE_FLOOR || t == TILE_CORR || t == TILE_DOOR;',
])
MAP_W_NEW = NL.join([
    '        return t == TILE_FLOOR || t == TILE_CORR ||',
    '               t == TILE_DOOR || t == TILE_WATER;',
])
for _t in (MAP_C_OLD, MAP_C_NEW, MAP_E_OLD, MAP_E_NEW,
           MAP_W_OLD, MAP_W_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in map content'

p = 'world/map.h'
s = rd(p)
if 'TILE_WATER' in s:
    already.append('map.h: the water tile')
else:
    assert 'TILE_WATER' not in s, 'map marker collision'
    assert s.count(MAP_C_OLD) == 1, 'map comment anchor'
    assert s.count(MAP_E_OLD) == 1, 'map enum anchor'
    assert s.count(MAP_W_OLD) == 1, 'map walkable anchor'
    s = s.replace(MAP_C_OLD, MAP_C_NEW)
    s = s.replace(MAP_E_OLD, MAP_E_NEW)
    s = s.replace(MAP_W_OLD, MAP_W_NEW)
    wr(p, s)
    applied.append('map.h: the water tile')

s = rd(p)
assert s.count('TILE_WATER') == 2, 'patch b water count'
assert s.count('    TILE_CORR     = 4,') == 1, 'patch b corr'
assert s.count('walkable') == 1, 'patch b walkable'
assert s.count('t == TILE_DOOR || t == TILE_WATER;') == 1, 'b fold'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch b balance'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) game/appstate.h: the declarations ----
AS_OLD = NL.join([
    '    void placeLockedDoors();',
    '    const LockedDoor* lockedDoorAt(int x, int y) const;',
    '    void bumpLockedDoor(int x, int y);',
])
AS_NEW = NL.join([
    '    void placeLockedDoors();',
    '    const LockedDoor* lockedDoorAt(int x, int y) const;',
    '    void bumpLockedDoor(int x, int y);',
    '',
    '    // R312: the flooded crossing - one water',
    '    // pool per delve (the R304 one-per-delve',
    '    // convention); the company enters the',
    '    // water tile only when every living',
    '    // member can swim (the R311 surface',
    '    // paragraph: metal armor bars the water,',
    '    // magic armor dog paddles, leather and',
    '    // padded roll the drown percent - one',
    '    // roll per crossing)',
    '    void placeFlood();',
    '    bool enterWater(int nx, int ny);',
])
for _t in (AS_OLD, AS_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in appstate content'

p = 'game/appstate.h'
s = rd(p)
if 'void placeFlood();' in s:
    already.append('appstate.h: the declarations')
else:
    assert s.count(AS_OLD) == 1, 'appstate anchor not unique'
    assert 'placeFlood' not in s, 'appstate marker collision'
    assert 'enterWater' not in s, 'appstate marker collision'
    s = s.replace(AS_OLD, AS_NEW)
    wr(p, s)
    applied.append('appstate.h: the declarations')

s = rd(p)
assert s.count('void placeFlood();') == 1, 'c flood decl'
assert s.count('bool enterWater(int nx, int ny);') == 1, 'c enter decl'
assert s.count('void bumpLockedDoor(int x, int y);') == 1, 'c anchor'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch c balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) game/state_core.cpp: the delve call ----
SC_OLD = NL.join([
    '        placeLockedDoors();   // R304: the locked door feature',
])
SC_NEW = NL.join([
    '        placeLockedDoors();   // R304: the locked door feature',
    '        placeFlood();   // R312: the flooded crossing',
])
for _t in (SC_OLD, SC_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in core content'

p = 'game/state_core.cpp'
s = rd(p)
if 'placeFlood();   // R312' in s:
    already.append('state_core.cpp: the delve call')
else:
    assert s.count(SC_OLD) == 1, 'core anchor not unique'
    assert 'placeFlood' not in s, 'core marker collision'
    s = s.replace(SC_OLD, SC_NEW)
    wr(p, s)
    applied.append('state_core.cpp: the delve call')

s = rd(p)
assert s.count('placeFlood();   // R312') == 1, 'd flood call'
assert s.count(SC_OLD) == 1, 'd anchor'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch d balance'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) game/state_dungeon.cpp: the site ----
SD_I_OLD = NL.join([
    '#include "rules/doorforce.h"  // R305: the door force folds',
])
SD_I_NEW = NL.join([
    '#include "rules/doorforce.h"  // R305: the door force folds',
    '#include "rules/swimcross.h"  // R312: the flooded crossing',
])
SD_M_OLD = NL.join([
    '        // the turn spent can draw a wanderer',
    '        if (dm::wanderCheck(dice, wander))',
    '            spawnWanderingEncounter();',
    '    }',
    '',
    '// ---- forceLockedDoor ----',
])
SD_M_NEW = NL.join([
    '        // the turn spent can draw a wanderer',
    '        if (dm::wanderCheck(dice, wander))',
    '            spawnWanderingEncounter();',
    '    }',
    '',
    '// ---- placeFlood ----',
    '// R312: the flooded crossing - one water',
    '// pool per delve (the R304 one-per-delve',
    '// convention; the count judgment): a 2-3',
    '// by 2-3 tile sheet of open floor clear',
    '// of the stairs and the entry (the way',
    '// down stays dry). The surface SWIMMING',
    '// paragraph (R311) governs the crossing.',
    'void AppState::placeFlood(){',
    '        int placed = 0;',
    '        int guard = 0;',
    '        while (placed < rules::floodPerDelveCount() &&',
    '               ++guard < 500) {',
    '            int x = 1 + (int)rng.below(MAP_TILES_X - 2);',
    '            int y = 1 + (int)rng.below(MAP_TILES_Y - 2);',
    '            int w = (int)rng.range(',
    '                rules::floodSideMin(),',
    '                rules::floodSideMax());',
    '            int h = (int)rng.range(',
    '                rules::floodSideMin(),',
    '                rules::floodSideMax());',
    '            bool allFloor = true;',
    '            for (int yy = y; yy < y + h; ++yy)',
    '                for (int xx = x; xx < x + w; ++xx)',
    '                    if (map.at(xx, yy) != TILE_FLOOR)',
    '                        allFloor = false;',
    '            if (!allFloor) continue;',
    '            bool onStairs =',
    '                stairsX >= x && stairsX < x + w &&',
    '                stairsY >= y && stairsY < y + h;',
    '            bool onEntry =',
    '                dungeon.entryX >= x &&',
    '                dungeon.entryX < x + w &&',
    '                dungeon.entryY >= y &&',
    '                dungeon.entryY < y + h;',
    '            if (onStairs || onEntry) continue;',
    '            for (int yy = y; yy < y + h; ++yy)',
    '                for (int xx = x; xx < x + w; ++xx)',
    '                    map.set(xx, yy, TILE_WATER);',
    '            ++placed;',
    '        }',
    '    }',
    '',
    '// ---- enterWater ----',
    '// R312: the company steps from dry land',
    '// into the water tile. The surface',
    '// SWIMMING paragraph (R311) gates the',
    '// crossing: the first living member in',
    '// metal armor bars the whole company',
    '// (magic armor dog paddles - the',
    '// exception) and the blocked step spends',
    '// a bump turn (the R304 convention),',
    '// wanderer and all; a passing gate logs',
    '// the plunge, and each living swimmer',
    '// rolls the drown percent ONCE (the',
    '// judgment - the per-hour print condensed',
    '// to the crossing). The step itself is',
    '// the normal pace cost (the caller moves',
    '// the company).',
    'bool AppState::enterWater(int nx, int ny){',
    '        (void)nx; (void)ny;',
    '        for (const auto& c : party.members) {',
    '            if (c.hp <= 0) continue;',
    '            if (!rules::swimCanSwim((int)c.armor.id,',
    '                                    c.armor.plus)) {',
    '                ++turnCount;',
    '                tickActivity(1);   // R119: the refusal',
    '                char buf[96];',
    '                snprintf(buf, sizeof buf,',
    '                         "%s cannot swim in %s - the "',
    '                         "flood bars the way.",',
    '                         c.name.c_str(),',
    '                         items::armor(c.armor.id).name);',
    '                log.add(buf);',
    '                // the turn spent can draw a wanderer',
    '                if (dm::wanderCheck(dice, wander))',
    '                    spawnWanderingEncounter();',
    '                return false;',
    '            }',
    '        }',
    '        log.add("The company takes to the water.");',
    '        for (auto& c : party.members) {',
    '            if (c.hp <= 0) continue;',
    '            int loadLbs = rules::swimLoadBeyondArmorLbs(',
    '                carriedWeight(c),',
    '                items::armor(c.armor.id).weightGp);',
    '            int rolls = rules::swimDrownRollPerCrossing();',
    '            for (int r = 0; r < rolls; ++r) {',
    '                int roll = (int)rng.below(100);',
    '                if (roll < rules::uwSurfaceDrownPct(',
    '                        loadLbs)) {',
    '                    c.hp = 0;',
    '                    char buf[96];',
    '                    snprintf(buf, sizeof buf,',
    '                             "%s goes under - drowned.",',
    '                             c.name.c_str());',
    '                    log.add(buf);',
    '                    break;',
    '                }',
    '            }',
    '        }',
    '        return true;',
    '    }',
    '',
    '// ---- forceLockedDoor ----',
])
for _t in (SD_I_OLD, SD_I_NEW, SD_M_OLD, SD_M_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in dungeon content'

p = 'game/state_dungeon.cpp'
s = rd(p)
if 'AppState::placeFlood' in s:
    already.append('state_dungeon.cpp: the site')
else:
    assert 'placeFlood' not in s, 'dungeon marker collision'
    assert 'enterWater' not in s, 'dungeon marker collision'
    assert 'swimcross' not in s, 'dungeon include collision'
    assert s.count(SD_I_OLD) == 1, 'dungeon include anchor'
    assert s.count(SD_M_OLD) == 1, 'dungeon site anchor'
    s = s.replace(SD_I_OLD, SD_I_NEW)
    s = s.replace(SD_M_OLD, SD_M_NEW)
    wr(p, s)
    applied.append('state_dungeon.cpp: the site')

s = rd(p)
assert s.count('AppState::placeFlood') == 1, 'e flood site'
assert s.count('AppState::enterWater') == 1, 'e enter site'
assert s.count('swimcross.h') == 1, 'e include'
assert s.count('// ---- forceLockedDoor ----') == 1, 'e anchor'
assert s.count('cannot swim in') == 1, 'e blocker print'
assert s.count('goes under - drowned.') == 1, 'e drown print'
assert s.count('takes to the water') == 1, 'e plunge print'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch e balance'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) adnd1.cpp: the gate and the brush ----
AD_G_OLD = NL.join([
    '    if (s.lockedDoorAt(nx, ny) != nullptr) {',
    '        s.bumpLockedDoor(nx, ny);',
    '        return;',
    '    }',
    '    if (!s.map.walkable(nx, ny)) return;',
])
AD_G_NEW = NL.join([
    '    if (s.lockedDoorAt(nx, ny) != nullptr) {',
    '        s.bumpLockedDoor(nx, ny);',
    '        return;',
    '    }',
    '    // R312: the flooded crossing - the',
    '    // surface swim paragraph gates the',
    '    // water tile (the R311 pins)',
    '    if (s.map.at(nx, ny) == TILE_WATER &&',
    '        s.map.at(s.party.x, s.party.y) !=',
    '            TILE_WATER) {',
    '        if (!s.enterWater(nx, ny)) return;',
    '    }',
    '    if (!s.map.walkable(nx, ny)) return;',
])
AD_B_OLD = NL.join([
    '        case TILE_DOOR:  br = CreateSolidBrush(RGB(150, 100,  40)); break;',
    '        default:         br = CreateSolidBrush(RGB(  5,   5,  10)); break;',
])
AD_B_NEW = NL.join([
    '        case TILE_DOOR:  br = CreateSolidBrush(RGB(150, 100,  40)); break;',
    '        case TILE_WATER: br = CreateSolidBrush(RGB( 30,  60, 120)); break;',
    '        default:         br = CreateSolidBrush(RGB(  5,   5,  10)); break;',
])
for _t in (AD_G_OLD, AD_G_NEW, AD_B_OLD, AD_B_NEW):
    clean(_t, 78)
    assert Q not in _t, 'apostrophe in adnd1 content'

p = 'adnd1.cpp'
s = rd(p)
if 's.enterWater(nx, ny)' in s:
    already.append('adnd1.cpp: the gate and the brush')
else:
    assert 'enterWater' not in s, 'adnd1 marker collision'
    assert 'TILE_WATER' not in s, 'adnd1 brush collision'
    assert s.count(AD_G_OLD) == 1, 'adnd1 gate anchor'
    assert s.count(AD_B_OLD) == 1, 'adnd1 brush anchor'
    s = s.replace(AD_G_OLD, AD_G_NEW)
    s = s.replace(AD_B_OLD, AD_B_NEW)
    wr(p, s)
    applied.append('adnd1.cpp: the gate and the brush')

s = rd(p)
assert s.count('s.enterWater(nx, ny)') == 1, 'f gate call'
assert s.count('TILE_WATER') == 3, 'f brush and gate'
assert s.count('case TILE_DOOR') == 1, 'f door case'
assert s.count('if (!s.map.walkable(nx, ny)) return;') == 1, 'f walk'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch f balance'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- (g) regtest.cpp: the include line ----
RG_I_OLD = NL.join([
    '#include "rules/underwater.h"  // R311: the underwater environment',
])
RG_I_NEW = NL.join([
    '#include "rules/underwater.h"  // R311: the underwater environment',
    '#include "rules/swimcross.h"  // R312: the flooded crossing',
])
for _t in (RG_I_OLD, RG_I_NEW):
    clean(_t, 76)
    assert Q not in _t, 'apostrophe in include content'

p = 'regtest.cpp'
s = rd(p)
if '#include "rules/swimcross.h"' in s:
    already.append('regtest.cpp: the include line')
else:
    assert 'swimcross' not in s, 'include marker collision'
    assert s.count(RG_I_OLD) == 1, 'include anchor not unique'
    s = s.replace(RG_I_OLD, RG_I_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the include line')

s = rd(p)
assert s.count('#include "rules/swimcross.h"') == 1, 'g include'
assert s.count('#include "rules/underwater.h"') == 1, 'g anchor'
assert len(applied) + len(already) == 7, 'patch g count wrong'

# ---- (h) regtest.cpp: the audit blocks ----
RT_TAIL = NL.join([
    '        printf("R311 underwater environment audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_NEXT = NL.join([
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_AUD_A = NL.join(
    ['    // ---- R312a: the flooded crossing seam audit ----',
     '    // The DMG surface SWIMMING paragraph folds',
     '    // (rules/swimcross.h, the grenade.h pattern)',
     '    // against the R311 drown pin - verified by',
     '    // audit_eval. The armor ids read the plain',
     '    // items::ArmorId order (0 none through 9',
     '    // plate); studded leather reads metal (the',
     '    // studs - the JUDGMENT).',
     '    {',
     '        int bad = 0;',
     '        static const int kSwimWalk[10] = {',
     '             1,  1,  1,  0,  0,  0,  0,  0,  0,  0,',
     '        };',
     '        // the armor walk: none, padded and',
     '        // leather swim, the metal armors bar',
     '        for (int i = 0; i < 10; ++i)',
     '            if (rules::swimArmorSwims(i) !=',
     '                kSwimWalk[i]) ++bad;',
     '        // the magic armor exception: the dog',
     '        // paddle clears the gate',
     '        if (rules::swimMagicArmorSwims() != 1 ||',
     '            rules::swimCanSwim(3, 1) != 1 ||',
     '            rules::swimCanSwim(9, 1) != 1) ++bad;',
     '        // the plain armors read the ban',
     '        if (rules::swimCanSwim(0, 0) != 1 ||',
     '            rules::swimCanSwim(1, 0) != 1 ||',
     '            rules::swimCanSwim(2, 0) != 1 ||',
     '            rules::swimCanSwim(3, 0) != 0 ||',
     '            rules::swimCanSwim(9, 0) != 0) ++bad;',
     '        // the load beyond the armor: 1 pound =',
     '        // 10 g.p., the worn armor not counted,',
     '        // the negatives clamped',
     '        if (rules::swimLoadBeyondArmorLbs(0, 0) != 0 ||',
     '            rules::swimLoadBeyondArmorLbs(170, 150)',
     '                != 2 ||',
     '            rules::swimLoadBeyondArmorLbs(1550, 1500)',
     '                != 5 ||',
     '            rules::swimLoadBeyondArmorLbs(50, 100)',
     '                != 0) ++bad;',
     '        // the drown band rides the R311 pin: 5',
     '        // percent bare, +2 per full 5 pounds',
     '        if (rules::uwSurfaceDrownPct(0) != 5 ||',
     '            rules::uwSurfaceDrownPct(2) != 5 ||',
     '            rules::uwSurfaceDrownPct(5) != 7 ||',
     '            rules::uwSurfaceDrownPct(25) != 15)',
     '            ++bad;',
     '        // the per-crossing roll judgment',
     '        if (rules::swimDrownRollPerCrossing() != 1)',
     '            ++bad;',
     '        // the pool judgments: one per delve,',
     '        // the sides 2-3',
     '        if (rules::floodPerDelveCount() != 1 ||',
     '            rules::floodSideMin() != 2 ||',
     '            rules::floodSideMax() != 3 ||',
     '            rules::floodSideMax() -',
     '                rules::floodSideMin() + 1 != 2)',
     '            ++bad;',
     '        printf("R312a flooded crossing seam audit: bad %d'
     + BS + 'n", bad);',
     '        if (bad) return 1;',
     '    }',
     ])
RT_AUD_E = NL.join(
    ['    // ---- R312: the flooded crossing engine audit ----',
     '    // The water site (the R304 locked-door',
     '    // pattern): placeFlood draws a 2-3 by',
     '    // 2-3 tile floor sheet clear of the',
     '    // stairs and the entry, enterWater gates',
     '    // the crossing on the swim armor (magic',
     '    // armor dog paddles) and rolls the R311',
     '    // drown percent once per living swimmer.',
     '    // Every scenario sits on a seeded',
     '    // sequence the replica walked first (no',
     '    // compiler in the splice sandbox). The',
     '    // bare member carries but the dagger (2',
     '    // pounds beyond the armor, the drown',
     '    // percent 5): the roll 4 goes under,',
     '    // the roll 5 holds.',
     '    {',
     '        int bad = 0;',
     '        // scenario 1: the crafted sheet - the',
     '        // floor rows y 20 through 25; seed 3',
     '        // accepts on the first draw: the pool',
     '        // x 6 y 22, 2 by 2',
     '        {',
     '            AppState st;',
     '            for (int y = 0; y < 64; ++y)',
     '                for (int x = 0; x < 64; ++x)',
     '                    st.map.set(x, y, world::TILE_WALL);',
     '            for (int x = 0; x < 64; ++x)',
     '                for (int y = 20; y <= 25; ++y)',
     '                    st.map.set(x, y, world::TILE_FLOOR);',
     '            st.stairsX = 2; st.stairsY = 2;',
     '            st.rng.seed(3);',
     '            st.placeFlood();',
     '            if (st.map.at(6, 22) != world::TILE_WATER)',
     '                ++bad;',
     '            if (st.map.at(7, 23) != world::TILE_WATER)',
     '                ++bad;',
     '            if (st.map.at(5, 22) == world::TILE_WATER)',
     '                ++bad;',
     '            if (st.map.at(6, 21) == world::TILE_WATER)',
     '                ++bad;',
     '            int wet = 0;',
     '            for (int y = 0; y < 64; ++y)',
     '                for (int x = 0; x < 64; ++x)',
     '                    if (st.map.at(x, y) ==',
     '                        world::TILE_WATER) ++wet;',
     '            if (wet != 4) ++bad;',
     '        }',
     '        // scenario 2: the stairs stay dry -',
     '        // the only 2x2 floor pocket holds',
     '        // them, so the one fitting rect',
     '        // covers the stairs; nothing places',
     '        // (seed 4)',
     '        {',
     '            AppState st;',
     '            for (int y = 0; y < 64; ++y)',
     '                for (int x = 0; x < 64; ++x)',
     '                    st.map.set(x, y, world::TILE_WALL);',
     '            for (int y = 10; y <= 11; ++y)',
     '                for (int x = 10; x <= 11; ++x)',
     '                    st.map.set(x, y, world::TILE_FLOOR);',
     '            st.stairsX = 10; st.stairsY = 10;',
     '            st.rng.seed(4);',
     '            st.placeFlood();',
     '            int wet = 0;',
     '            for (int y = 0; y < 64; ++y)',
     '                for (int x = 0; x < 64; ++x)',
     '                    if (st.map.at(x, y) ==',
     '                        world::TILE_WATER) ++wet;',
     '            if (wet != 0) ++bad;',
     '        }',
     '        // scenario 3: the metal-armored member',
     '        // bars the company - the bump turn is',
     '        // spent and the leather swimmer never',
     '        // rolls (seed 1: the wander d12 reads',
     '        // 2, quiet)',
     '        {',
     '            AppState st;',
     '            st.mode = MODE_EXPLORE;',
     '            Character fin;',
     '            fin.name = "Fin";',
     '            fin.classIndex = 0; fin.level = 1;',
     '            fin.race = 0;',
     '            fin.hp = 30; fin.maxHp = 30;',
     '            fin.armor.id = items::ARMOR_LEATHER;',
     '            st.party.members.push_back(fin);',
     '            Character tank;',
     '            tank.name = "Tank";',
     '            tank.classIndex = 0; tank.level = 1;',
     '            tank.race = 0;',
     '            tank.hp = 30; tank.maxHp = 30;',
     '            tank.armor.id = items::ARMOR_PLATE;',
     '            st.party.members.push_back(tank);',
     '            st.rng.seed(1);',
     '            if (st.enterWater(5, 7)) ++bad;',
     '            if (st.turnCount != 1) ++bad;',
     '            if (st.party.members[0].hp != 30 ||',
     '                st.party.members[1].hp != 30) ++bad;',
     '            if (st.log.get(0).find(',
     '                    "Tank cannot swim in")',
     '                == std::string::npos) ++bad;',
     '            if (st.log.get(0).find(',
     '                    "takes to the water")',
     '                != std::string::npos) ++bad;',
     '        }',
     '        // scenario 4: the enchanted plate dog',
     '        // paddles - the crossing succeeds and',
     '        // the roll 7 clears the 5 percent',
     '        // (seed 60)',
     '        {',
     '            AppState st;',
     '            st.mode = MODE_EXPLORE;',
     '            Character mys;',
     '            mys.name = "Mys";',
     '            mys.classIndex = 0; mys.level = 1;',
     '            mys.race = 0;',
     '            mys.hp = 30; mys.maxHp = 30;',
     '            mys.armor.id = items::ARMOR_PLATE;',
     '            mys.armor.plus = 1;',
     '            st.party.members.push_back(mys);',
     '            st.rng.seed(60);',
     '            if (!st.enterWater(5, 7)) ++bad;',
     '            if (st.turnCount != 0) ++bad;',
     '            if (st.party.members[0].hp != 30) ++bad;',
     '            if (st.log.get(0).find(',
     '                    "The company takes to the water.")',
     '                == std::string::npos) ++bad;',
     '        }',
     '        // scenario 5: the drown boundary - the',
     '        // bare leather swimmer carries 2',
     '        // pounds beyond the armor, 5 percent:',
     '        // seed 69 rolls 4 (goes under), seed',
     '        // 180 rolls 5 (the water holds)',
     '        {',
     '            AppState st;',
     '            st.mode = MODE_EXPLORE;',
     '            Character fin;',
     '            fin.name = "Fin";',
     '            fin.classIndex = 0; fin.level = 1;',
     '            fin.race = 0;',
     '            fin.hp = 30; fin.maxHp = 30;',
     '            fin.armor.id = items::ARMOR_LEATHER;',
     '            st.party.members.push_back(fin);',
     '            st.rng.seed(69);',
     '            if (!st.enterWater(5, 7)) ++bad;',
     '            if (st.party.members[0].hp != 0) ++bad;',
     '            if (st.log.get(0).find(',
     '                    "Fin goes under - drowned.")',
     '                == std::string::npos) ++bad;',
     '        }',
     '        {',
     '            AppState st;',
     '            st.mode = MODE_EXPLORE;',
     '            Character fin;',
     '            fin.name = "Fin";',
     '            fin.classIndex = 0; fin.level = 1;',
     '            fin.race = 0;',
     '            fin.hp = 30; fin.maxHp = 30;',
     '            fin.armor.id = items::ARMOR_LEATHER;',
     '            st.party.members.push_back(fin);',
     '            st.rng.seed(180);',
     '            if (!st.enterWater(5, 7)) ++bad;',
     '            if (st.party.members[0].hp != 30) ++bad;',
     '            if (st.log.get(0).find(',
     '                    "The company takes to the water.")',
     '                == std::string::npos) ++bad;',
     '        }',
     '        // scenario 6: the fallen plate wearer',
     '        // rides the pack - the living leather',
     '        // swimmer crosses (seed 91: the roll',
     '        // 9 clears the 5 percent)',
     '        {',
     '            AppState st;',
     '            st.mode = MODE_EXPLORE;',
     '            Character ghost;',
     '            ghost.name = "Ghost";',
     '            ghost.classIndex = 0; ghost.level = 1;',
     '            ghost.race = 0;',
     '            ghost.hp = 0; ghost.maxHp = 30;',
     '            ghost.armor.id = items::ARMOR_PLATE;',
     '            st.party.members.push_back(ghost);',
     '            Character fin;',
     '            fin.name = "Fin";',
     '            fin.classIndex = 0; fin.level = 1;',
     '            fin.race = 0;',
     '            fin.hp = 30; fin.maxHp = 30;',
     '            fin.armor.id = items::ARMOR_LEATHER;',
     '            st.party.members.push_back(fin);',
     '            st.rng.seed(91);',
     '            if (!st.enterWater(5, 7)) ++bad;',
     '            if (st.turnCount != 0) ++bad;',
     '            if (st.log.get(0).find("cannot swim")',
     '                != std::string::npos) ++bad;',
     '            if (st.party.members[0].hp != 0) ++bad;',
     '            if (st.party.members[1].hp != 30) ++bad;',
     '        }',
     '        printf("R312 flooded crossing engine audit: bad %d'
     + BS + 'n", bad);',
     '        if (bad) return 1;',
     '    }',
     ])
RT_OLD = RT_TAIL + NL + RT_NEXT
RT_NEW = (RT_TAIL + NL + RT_AUD_A + NL + RT_AUD_E + NL +
          RT_NEXT)
# the audit blocks carry the printf newline (BS) -
# BS lives ONLY on the printf lines, one per line
for _t in (RT_OLD, RT_NEW, RT_AUD_A, RT_AUD_E):
    for _ln in _t.split(NL):
        assert all(ord(_c) < 128 for _c in _ln), 'nonascii'
        assert len(_ln) <= 76, 'audit line too long: ' + _ln
        assert Q not in _ln, 'apostrophe in audit'
        if 'printf("' in _ln:
            assert _ln.count(BS) == 1, 'printf BS count wrong'
        else:
            assert BS not in _ln, 'stray backslash in audit'

p = 'regtest.cpp'
s = rd(p)
if 'R312a flooded crossing seam audit' in s:
    already.append('regtest.cpp: the audit blocks')
else:
    assert s.count('audit: bad') == 235, 'rt census not 235'
    assert s.count(RT_OLD) == 1, 'rt anchor not unique'
    assert 'swimArmorSwims' not in s, 'rt collision'
    assert 'placeFlood' not in s, 'rt collision'
    assert 'enterWater' not in s, 'rt collision'
    assert 'R312a' not in s, 'rt collision'
    s = s.replace(RT_OLD, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the audit blocks')

s = rd(p)
assert s.count('audit: bad') == 237, 'patch h census wrong'
assert s.count('R312a flooded crossing seam audit') == 1, 'h a'
assert s.count('R312 flooded crossing engine audit') == 1, 'h e'
assert s.count('R311 underwater environment audit') == 1, 'h r311'
assert s.count(
    'R227: the wis mental save wiring audit') == 1, 'h head'
assert s.count('{') == s.count('}'), 'rt brace balance'
assert s.count('(') == s.count(')'), 'rt paren balance'
assert len(applied) + len(already) == 8, 'patch h count wrong'

# ---- (i) tools/dmg_gap_report.md: the chronicle ----
CH_OLD = NL.join([
    '235 with the R311 audit.',
    '',
    'Categories:',
])
CH_NEW = NL.join([
    '235 with the R311 audit.',
    '',
    'R312 the flooded crossing (the first',
    'engine site the R311 underwater pins',
    'charge): rules/swimcross.h (the seam -',
    'swimArmorSwims and swimCanSwim with',
    'the magic-armor dog paddle, the load',
    'beyond the armor in pounds, the',
    'one-roll-per-crossing judgment; the',
    'pool judgments) wired at world/map.h',
    'TILE_WATER (walkable), the placeFlood',
    'site (a 2-3 by 2-3 tile floor sheet',
    'clear of the stairs and the entry,',
    'one pool per delve the R304 convention)',
    'and the enterWater gate (the first',
    'living member in metal armor bars the',
    'company, magic armor excepted; the',
    'leather-or-padded swimmers roll the',
    'drown percent once per crossing; a',
    'blocked step spends a bump turn and',
    'can draw a wanderer); the water brush',
    'in the map draw. The underwater',
    'MOVEMENT, VISION and COMBAT paragraphs',
    'stay data (no underwater combat layer',
    'yet); the spell lists ride R168. The',
    'battery census moves 235 -> 237 with',
    'the R312a seam and R312 engine audits.',
    '',
    'Categories:',
])
clean(CH_OLD, 57, gap=True)
clean(CH_NEW, 57, gap=True)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R312 the flooded crossing' in s:
    already.append('dmg report: the chronicle')
else:
    assert s.count(CH_OLD) == 1, 'chronicle anchor not unique'
    s = s.replace(CH_OLD, CH_NEW)
    wr(p, s)
    applied.append('dmg report: the chronicle')

s = rd(p)
assert s.count('R312 the flooded crossing') == 1, 'i entry'
assert s.count('Categories:') == 1, 'i legend head'
assert s.count('moves 235 -> 237 with') == 1, 'i census'
assert s.count('235 with the R311 audit.') == 1, 'i r311 intact'
assert s.count('- [ ]') == 1, 'i open residue (the legend)'
assert len(applied) + len(already) == 9, 'patch i count wrong'

# ---- R312 fails/tail ----
if fails:
    print('R312 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 9:
    print('R312 splice: FAIL - expected 9 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R312 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R312 note: 9 patches; the flooded')
print('crossing wired - the first engine')
print('site the R311 pins charge; the')
print('battery census moves 235 -> 237')
print('commit: R312: the flooded crossing')
print('wired (census 237)')

