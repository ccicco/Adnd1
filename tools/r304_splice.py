#!/usr/bin/env python3
# tools/r304_splice.py - R304: the locked door
# wired (the R301/R302/R303 successor chain -
# the open locks column rolls at the dungeon
# door site).
#
# The R298 open locks column stayed data (no
# lock layer existed). This round builds one:
# the DMG doors prose (metal doors are usually
# locked) pins as ONE locked door per delve (a
# JUDGMENT - the print carries no count),
# placed by the R45 scan pattern (a wall slot
# with open tiles on both sides of one axis),
# printed as a TILE_DOOR the company sees but
# cannot pass; the bump spends the turn and the
# first living thief works the lock for the DMG
# time draw (1-10 rounds) against the printed
# percentile (the R298 seam), one try per lock -
# a retry waits for a higher level thief (the
# printed note).
#
#   (a) rules/locktime.h CREATED - the DMG THIEF
#       ABILITIES time pins (the pick takes
#       1-10 rounds on the complexity, most
#       locks 1-4; the traps roll rides the
#       locks time) and the doors prose (wooden
#       doors always metal bound, metal doors
#       usually locked) with the per-delve
#       count judgment.
#   (b) game/appstate.h - the LockedDoor struct,
#       the lockedDoors member and the three
#       declarations.
#   (c) game/state_dungeon.cpp - the site:
#       placeLockedDoors (the scan),
#       lockedDoorAt (the gate lookup) and
#       bumpLockedDoor (the roll, the turn and
#       the wander check).
#   (d) game/state_core.cpp - the delve call.
#   (e) adnd1.cpp - the movement gate (the shell
#       step wire).
#   (f) regtest.cpp - the R304 audit pair (the
#       battery census 225 -> 227): the R304a
#       seam audit walks the time pins and the
#       open locks percentile boundaries
#       (evaluable - verified by audit_eval) and
#       the R304 engine audit pins every
#       scenario on seeded sequences (the
#       replica walked the draws first - no
#       compiler in the splice sandbox).
#   (g) tools/phb_gap_report.md - the wiring-arc
#       box (the R298 box head amended; the
#       ledger holds ZERO open items).
#   (h) tools/dmg_gap_report.md - the chronicle
#       paragraph (the DMG pins recorded; the
#       legend stays the only open checkbox).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY patch
# (the R142 lesson). ZERO literal backslash
# bytes in this file (the audit printf newline
# builds via BS) and no CONTENT string embeds
# an apostrophe, non-ASCII or (for the gap
# reports) a line past 57 columns.
# Commit: "R304: the locked door wired (census
# 227)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
BS = chr(92)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit, allow_apos=False):
    if not allow_apos:
        assert chr(39) not in s, 'apostrophe in content'
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

# ---- (a) rules/locktime.h CREATED ----
LT = NL.join([
    '// ====================================================================',
    '// Adnd1 - rules/locktime.h',
    '// R304: the DMG THIEF ABILITIES time pins',
    '// and the FIRST DUNGEON ADVENTURE doors',
    '// prose - a DATA pin (the grenade.h',
    '// pattern), WIRED R304: the locked-door',
    '// site draws the pick time and places the',
    '// per-delve door.',
    '//',
    '// The CHARACTER CLASSES THIEF ABILITIES',
    '// print: opening a lock "can take from',
    '// 1-10 rounds, depending on the complexity',
    '// of the lock" and most locks take "but',
    '// 1-4 rounds of time to pick"; finding',
    '// and removing traps "use the time',
    '// requirements for opening locks. Time',
    '// counts for each function." The doors',
    '// print (the FIRST DUNGEON ADVENTURE):',
    '// wooden doors are "always metal bound"',
    '// and metal doors are "usually locked" -',
    '// the engine dungeon doors carry no lock',
    '// layer, so the count pins as a JUDGMENT:',
    '// one locked door per delve (the print',
    '// carries no count; the R45 placement',
    '// convention).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int thfLocksPickRoundsMin() {',
    '    // the printed band floor: a lock can',
    '    // take from 1 round',
    '    return 1;',
    '}',
    '',
    'inline int thfLocksPickRoundsMax() {',
    '    // the printed band ceiling: up to 10',
    '    // rounds, on the complexity of the lock',
    '    return 10;',
    '}',
    '',
    'inline int thfLocksPickRoundsTypicalMax() {',
    '    // most locks take but 1-4 rounds',
    '    return 4;',
    '}',
    '',
    'inline int thfTrapsTimeRidesLocks() {',
    '    // the traps print: use the time',
    '    // requirements for opening locks; time',
    '    // counts for each function',
    '    return 1;',
    '}',
    '',
    'inline int doorWoodAlwaysMetalBound() {',
    '    // the doors prose: wooden doors are',
    '    // always metal bound',
    '    return 1;',
    '}',
    '',
    'inline int doorMetalUsuallyLocked() {',
    '    // the doors prose: metal doors are',
    '    // usually locked',
    '    return 1;',
    '}',
    '',
    'inline int doorLockedPerDelveCount() {',
    '    // JUDGMENT: the print carries no count;',
    '    // one locked door per delve (the R45',
    '    // placement convention)',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
    '',
])
clean(LT, 78)

p = 'rules/locktime.h'
if os.path.exists(os.path.join(ROOT, p)):
    s = rd(p)
    if 'R304: the DMG THIEF ABILITIES time pins' in s:
        already.append('locktime.h created')
    else:
        fails.append('locktime.h exists without the R304 marker')
else:
    wr(p, LT)
    applied.append('locktime.h created')
s = rd(p)
assert s.count('inline int thfLocksPickRounds') == 3, 'lt locks band'
assert s.count('inline int thfTrapsTimeRidesLocks') == 1, 'lt traps note'
assert s.count('inline int door') == 3, 'lt door pins'
assert s.count('return 1;') == 5, 'lt ones'
assert s.count('return 10;') == 1, 'lt ten'
assert s.count('return 4;') == 1, 'lt four'
assert s.count('}  // namespace rules') == 1, 'lt namespace close'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) game/appstate.h: the struct, the member, the decls ----
AH_STRUCT_OLD = NL.join([
    '// R45: a secret door hides in a wall tile until found',
    'struct SecretDoor {',
    '    int  x = 0, y = 0;',
    '    bool found = false;',
    '};',
])
AH_STRUCT_NEW = NL.join([
    '// R45: a secret door hides in a wall tile until found',
    'struct SecretDoor {',
    '    int  x = 0, y = 0;',
    '    bool found = false;',
    '};',
    '',
    '// R304: a locked door bars its tile until a',
    '// thief works the lock (the DMG doors prose',
    '// - metal doors are usually locked); one try',
    '// per lock, a retry waits for a higher level',
    '// thief (the printed note)',
    'struct LockedDoor {',
    '    int  x = 0, y = 0;',
    '    bool opened = false;',
    '    int  tryLevel = 0;',
    '};',
])
AH_MEMBER_OLD = NL.join([
    '    std::vector<SecretDoor> secretDoors;',
])
AH_MEMBER_NEW = NL.join([
    '    std::vector<SecretDoor> secretDoors;',
    '',
    '    // R304: the locked doors of this delve',
    '    std::vector<LockedDoor> lockedDoors;',
])
AH_DECL_OLD = NL.join([
    '    void placeSecretDoors();',
])
AH_DECL_NEW = NL.join([
    '    void placeSecretDoors();',
    '',
    '    // R304: one locked door per delve - a',
    '    // visible TILE_DOOR the company cannot',
    '    // pass until the first living thief works',
    '    // the lock (the DMG time draw, 1-10',
    '    // rounds, against the printed open locks',
    '    // percentile; one try per lock, a retry',
    '    // waits for a higher level thief)',
    '    void placeLockedDoors();',
    '    const LockedDoor* lockedDoorAt(int x, int y) const;',
    '    void bumpLockedDoor(int x, int y);',
])
for t in (AH_STRUCT_OLD, AH_STRUCT_NEW, AH_MEMBER_OLD, AH_MEMBER_NEW,
          AH_DECL_OLD, AH_DECL_NEW):
    clean(t, 78)

p = 'game/appstate.h'
s = rd(p)
if 'struct LockedDoor' in s:
    already.append('appstate.h: the lock layer')
else:
    assert s.count(AH_STRUCT_OLD) == 1, 'ah struct anchor not unique'
    assert s.count(AH_MEMBER_OLD) == 1, 'ah member anchor not unique'
    assert s.count(AH_DECL_OLD) == 1, 'ah decl anchor not unique'
    assert 'lockedDoors' not in s, 'ah marker collision'
    s = s.replace(AH_STRUCT_OLD, AH_STRUCT_NEW)
    s = s.replace(AH_MEMBER_OLD, AH_MEMBER_NEW)
    s = s.replace(AH_DECL_OLD, AH_DECL_NEW)
    wr(p, s)
    applied.append('appstate.h: the lock layer')
s = rd(p)
assert s.count('struct LockedDoor') == 1, 'patch b struct'
assert s.count('std::vector<LockedDoor> lockedDoors;') == 1, 'patch b member'
assert s.count('void placeLockedDoors();') == 1, 'patch b place decl'
assert s.count('const LockedDoor* lockedDoorAt('
               'int x, int y) const;') == 1, 'patch b lookup decl'
assert s.count('void bumpLockedDoor(int x, int y);') == 1, 'patch b bump decl'
assert s.count('struct SecretDoor') == 1, 'patch b ate the secret door'
assert s.count('std::vector<SecretDoor> secretDoors;') == 1, 'patch b member'
assert s.count('void placeSecretDoors();') == 1, 'patch b secret decl'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) game/state_dungeon.cpp: the include + the site ----
SD_INC_OLD = NL.join([
    '#include "rules/thieffunc.h"   // R301: the thief trap rolls',
])
SD_INC_NEW = NL.join([
    '#include "rules/thieffunc.h"   // R301: the thief trap rolls',
    '#include "rules/locktime.h"   // R304: the lock time draw',
])
SD_SITE_OLD = NL.join([
    '            secretDoors.push_back(d);',
    '            ++placed;',
    '        }',
    '    }',
    '',
    '// ---- searchExplore ----',
])
SD_SITE_NEW = NL.join([
    '            secretDoors.push_back(d);',
    '            ++placed;',
    '        }',
    '    }',
    '',
    '// ---- placeLockedDoors ----',
    '// R304: the DMG doors prose - metal doors',
    '// are usually locked. One locked door per',
    '// delve (the count judgment; the print',
    '// carries no count): a TILE_WALL slot with',
    '// open tiles on both sides of one axis (a',
    '// real passage to bar - the R45 secret-door',
    '// scan pattern). The door prints as a',
    '// TILE_DOOR the company sees but cannot',
    '// pass until a thief works it.',
    'void AppState::placeLockedDoors(){',
    '        lockedDoors.clear();',
    '        int placed = 0;',
    '        int guard = 0;',
    '        while (placed < rules::doorLockedPerDelveCount() &&',
    '               ++guard < 500) {',
    '            int x = 1 + (int)rng.below(MAP_TILES_X - 2);',
    '            int y = 1 + (int)rng.below(MAP_TILES_Y - 2);',
    '            if (map.at(x, y) != TILE_WALL) continue;',
    '            bool openAbove = map.at(x, y - 1) == TILE_FLOOR ||',
    '                             map.at(x, y - 1) == TILE_CORR;',
    '            bool openBelow = map.at(x, y + 1) == TILE_FLOOR ||',
    '                             map.at(x, y + 1) == TILE_CORR;',
    '            bool openLeft  = map.at(x - 1, y) == TILE_FLOOR ||',
    '                             map.at(x - 1, y) == TILE_CORR;',
    '            bool openRight = map.at(x + 1, y) == TILE_FLOOR ||',
    '                             map.at(x + 1, y) == TILE_CORR;',
    '            if (!((openAbove && openBelow) ||',
    '                  (openLeft && openRight))) continue;',
    '            map.set(x, y, TILE_DOOR);',
    '            LockedDoor d;',
    '            d.x = x;',
    '            d.y = y;',
    '            lockedDoors.push_back(d);',
    '            ++placed;',
    '        }',
    '    }',
    '',
    '// ---- lockedDoorAt ----',
    '// R304: the unopened lock at a tile (null',
    '// when the tile is free) - the movement',
    '// gate reads it',
    'const LockedDoor* AppState::lockedDoorAt('
    'int x, int y) const{',
    '        for (const auto& d : lockedDoors)',
    '            if (!d.opened && d.x == x && d.y == y)',
    '                return &d;',
    '        return nullptr;',
    '    }',
    '',
    '// ---- bumpLockedDoor ----',
    '// R304: the company walks into the locked',
    '// door. The bump spends the turn (the',
    '// searchExplore convention) and the first',
    '// living thief works the lock for the DMG',
    '// time draw against the printed open locks',
    '// percentile (the R298 seam). One try per',
    '// lock (the printed note): a retry waits for',
    '// a higher level thief.',
    'void AppState::bumpLockedDoor(int x, int y){',
    '        LockedDoor* door = nullptr;',
    '        for (auto& d : lockedDoors)',
    '            if (!d.opened && d.x == x && d.y == y)',
    '                door = &d;',
    '        if (door == nullptr) return;',
    '',
    '        ++turnCount;',
    '        tickActivity(1);   // R119: the lock is work too',
    '',
    '        const Character* thief = nullptr;',
    '        for (const auto& c : party.members) {',
    '            if (c.hp <= 0 || c.classIndex != 3) continue;',
    '            thief = &c;',
    '            break;',
    '        }',
    '        if (thief == nullptr) {',
    '            log.add("The iron-bound door is locked - no "',
    '                    "thief walks with you.");',
    '        } else if (door->tryLevel >= thief->level) {',
    '            log.add("The lock resists - a higher level "',
    '                    "thief must try it.");',
    '        } else {',
    '            door->tryLevel = thief->level;',
    '            int rounds = rules::thfLocksPickRoundsMin() +',
    '                (int)rng.below(',
    '                    rules::thfLocksPickRoundsMax() -',
    '                    rules::thfLocksPickRoundsMin() + 1);',
    '            int roll = (int)rng.below(1000);',
    '            char buf[96];',
    '            if (rules::thfAttemptSucceeds(roll,',
    '                    rules::THF_OPEN_LOCKS, thief->level,',
    '                    thief->race,',
    '                    (int)thief->abilities.dex)) {',
    '                door->opened = true;',
    '                snprintf(buf, sizeof buf,',
    '                         "%s works the lock for %d "',
    '                         "rounds - it opens!",',
    '                         thief->name.c_str(), rounds);',
    '            } else {',
    '                snprintf(buf, sizeof buf,',
    '                         "%s works the lock for %d "',
    '                         "rounds - it resists.",',
    '                         thief->name.c_str(), rounds);',
    '            }',
    '            log.add(buf);',
    '        }',
    '',
    '        // the turn spent can draw a wanderer',
    '        if (dm::wanderCheck(dice, wander))',
    '            spawnWanderingEncounter();',
    '    }',
    '',
    '// ---- searchExplore ----',
])
for t in (SD_INC_OLD, SD_INC_NEW, SD_SITE_OLD, SD_SITE_NEW):
    clean(t, 78)

p = 'game/state_dungeon.cpp'
s = rd(p)
if 'void AppState::bumpLockedDoor' in s:
    already.append('state_dungeon.cpp: the site')
else:
    assert s.count(SD_INC_OLD) == 1, 'sd include anchor not unique'
    assert s.count(SD_SITE_OLD) == 1, 'sd site anchor not unique'
    assert 'placeLockedDoors' not in s, 'sd marker collision'
    s = s.replace(SD_INC_OLD, SD_INC_NEW)
    s = s.replace(SD_SITE_OLD, SD_SITE_NEW)
    wr(p, s)
    applied.append('state_dungeon.cpp: the site')
s = rd(p)
assert s.count('#include "rules/locktime.h"') == 1, 'patch c include'
assert s.count('void AppState::placeLockedDoors') == 1, 'patch c place'
assert s.count('AppState::lockedDoorAt') == 1, 'patch c lookup'
assert s.count('void AppState::bumpLockedDoor') == 1, 'patch c bump'
assert s.count('// ---- searchExplore ----') == 1, 'patch c search head'
assert s.count('// ---- placeSecretDoors ----') == 1, 'patch c secret head'
assert 'secretDoors.push_back(d);' in s, 'patch c ate the secret tail'
assert s.count('thfAttemptSucceeds') >= 2, 'patch c seam call'
assert 'doorLockedPerDelveCount' in s, 'patch c count helper'
assert s.count('spawnWanderingEncounter();') >= 2, 'patch c wander'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) game/state_core.cpp: the delve call ----
SC_OLD = NL.join([
    '        placeSecretDoors();   // R45',
])
SC_NEW = NL.join([
    '        placeSecretDoors();   // R45',
    '        placeLockedDoors();   // R304: the locked door feature',
])
for t in (SC_OLD, SC_NEW):
    clean(t, 78)

p = 'game/state_core.cpp'
s = rd(p)
if 'placeLockedDoors();' in s:
    already.append('state_core.cpp: the delve call')
else:
    assert s.count(SC_OLD) == 1, 'sc anchor not unique'
    s = s.replace(SC_OLD, SC_NEW)
    wr(p, s)
    applied.append('state_core.cpp: the delve call')
s = rd(p)
assert s.count('placeLockedDoors();') == 1, 'patch d call'
assert s.count('placeSecretDoors();   // R45') == 1, 'patch d secret call'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) adnd1.cpp: the movement gate ----
AD_OLD = NL.join([
    '    int nx = s.party.x + dx;',
    '    int ny = s.party.y + dy;',
    '    if (!s.map.walkable(nx, ny)) return;',
])
AD_NEW = NL.join([
    '    int nx = s.party.x + dx;',
    '    int ny = s.party.y + dy;',
    '    // R304: a locked door bars the tile until',
    '    // picked',
    '    if (s.lockedDoorAt(nx, ny) != nullptr) {',
    '        s.bumpLockedDoor(nx, ny);',
    '        return;',
    '    }',
    '    if (!s.map.walkable(nx, ny)) return;',
])
for t in (AD_OLD, AD_NEW):
    clean(t, 78)

p = 'adnd1.cpp'
s = rd(p)
if 's.bumpLockedDoor(nx, ny);' in s:
    already.append('adnd1.cpp: the movement gate')
else:
    assert s.count(AD_OLD) == 1, 'ad anchor not unique'
    assert 'lockedDoorAt' not in s, 'ad marker collision'
    s = s.replace(AD_OLD, AD_NEW)
    wr(p, s)
    applied.append('adnd1.cpp: the movement gate')
s = rd(p)
assert s.count('s.bumpLockedDoor(nx, ny);') == 1, 'patch e bump call'
assert s.count('s.lockedDoorAt(nx, ny)') == 1, 'patch e gate'
assert s.count('if (!s.map.walkable(nx, ny)) return;') == 1, \
    'patch e walkable gate'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) regtest.cpp: the include + the audit pair ----
RT_INC_OLD = NL.join([
    '#include "rules/thieffunc.h"  // R298: the thief function take table'
    ' and DEX Table II',
])
RT_INC_NEW = NL.join([
    '#include "rules/thieffunc.h"  // R298: the thief function take table'
    ' and DEX Table II',
    '#include "rules/locktime.h"  // R304: the DMG lock time pins',
])
RT_AUD_OLD = NL.join([
    '        printf("R303 thief pockets engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_AUD_NEW = NL.join([
    '        printf("R303 thief pockets engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R304a: the thief locks seam audit ----',
    '    // The DMG THIEF ABILITIES time pins and',
    '    // the doors prose (rules/locktime.h, the',
    '    // grenade.h pattern) plus the open locks',
    '    // percentile boundary walk against the',
    '    // R298 tables - verified by audit_eval.',
    '    // The race reads a plain int (0 human,',
    '    // 5 halfling, 1 dwarf, 2 elf).',
    '    {',
    '        int bad = 0;',
    '        // the printed time band: picking takes',
    '        // 1-10 rounds (most locks 1-4); the',
    '        // traps roll rides the locks time',
    '        if (rules::thfLocksPickRoundsMin() != 1 ||',
    '            rules::thfLocksPickRoundsMax() != 10 ||',
    '            rules::thfLocksPickRoundsTypicalMax() != 4 ||',
    '            rules::thfTrapsTimeRidesLocks() != 1) ++bad;',
    '        // the doors prose pins',
    '        if (rules::doorWoodAlwaysMetalBound() != 1 ||',
    '            rules::doorMetalUsuallyLocked() != 1) ++bad;',
    '        // the per-delve count judgment',
    '        if (rules::doorLockedPerDelveCount() != 1) ++bad;',
    '        // the time draw band folds the',
    '        // helpers: min + below(max - min + 1)',
    '        // covers the printed 1-10',
    '        if (rules::thfLocksPickRoundsMax() -',
    '                rules::thfLocksPickRoundsMin() + 1 != 10)',
    '            ++bad;',
    '        // open locks level 1 human dex 9',
    '        // prints 15 percent (150 tenths)',
    '        if (!rules::thfAttemptSucceeds(149,',
    '                rules::THF_OPEN_LOCKS, 1, 0, 9) ||',
    '            rules::thfAttemptSucceeds(150,',
    '                rules::THF_OPEN_LOCKS, 1, 0, 9)) ++bad;',
    '        // open locks level 10 halfling dex 13',
    '        // prints 72 percent (720 tenths)',
    '        if (!rules::thfAttemptSucceeds(719,',
    '                rules::THF_OPEN_LOCKS, 10, 5, 13) ||',
    '            rules::thfAttemptSucceeds(720,',
    '                rules::THF_OPEN_LOCKS, 10, 5, 13)) ++bad;',
    '        // open locks level 12 dwarf dex 18',
    '        // prints 102 percent (1020 - every',
    '        // draw of the band succeeds)',
    '        if (!rules::thfAttemptSucceeds(999,',
    '                rules::THF_OPEN_LOCKS, 12, 1, 18)) ++bad;',
    '        // open locks level 1 elf dex 18 prints',
    '        // 35 percent (350 tenths)',
    '        if (!rules::thfAttemptSucceeds(349,',
    '                rules::THF_OPEN_LOCKS, 1, 2, 18) ||',
    '            rules::thfAttemptSucceeds(350,',
    '                rules::THF_OPEN_LOCKS, 1, 2, 18)) ++bad;',
    '        printf("R304a thief locks seam audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R304: the thief locks engine audit ----',
    '    // The locked-door site (the R45 placement',
    '    // pattern): one door per delve bars a wall',
    '    // slot with open tiles on both sides of one',
    '    // axis; the bump spends the turn and the',
    '    // first living thief works the lock for the',
    '    // DMG time draw (1-10 rounds) against the',
    '    // printed open locks percentile (the R298',
    '    // seam), one try per lock - a retry waits',
    '    // for a higher level thief. Every scenario',
    '    // sits on a seeded sequence the replica',
    '    // walked first (no compiler in the splice',
    '    // sandbox). The seeds discriminate: the',
    '    // scenario 1 coordinate (x 33) pins the',
    '    // scan draws, the scenario 2 map defeats',
    '    // the one-sided predicate, and the',
    '    // scenario 5 first roll (167) fails only',
    '    // WITH the dex 9 fold (the plain 250 base',
    '    // would open it).',
    '    {',
    '        int bad = 0;',
    '        // scenario 1: a crafted strip - floor',
    '        // rows y 9 and y 11, wall row y 10.',
    '        // Seed 1: the scan lands x 33 y 10',
    '        {',
    '            AppState st;',
    '            for (int y = 0; y < 64; ++y)',
    '                for (int x = 0; x < 64; ++x)',
    '                    st.map.set(x, y, world::TILE_WALL);',
    '            for (int x = 0; x < 64; ++x) {',
    '                st.map.set(x, 9, world::TILE_FLOOR);',
    '                st.map.set(x, 11, world::TILE_FLOOR);',
    '            }',
    '            st.rng.seed(1);',
    '            st.placeLockedDoors();',
    '            if ((int)st.lockedDoors.size() != 1) ++bad;',
    '            if (st.lockedDoors[0].x != 33 ||',
    '                st.lockedDoors[0].y != 10) ++bad;',
    '            if (st.map.at(33, 10) !=',
    '                world::TILE_DOOR) ++bad;',
    '            if (st.lockedDoorAt(33, 10) == nullptr)',
    '                ++bad;',
    '            if (st.lockedDoorAt(33, 9) != nullptr) ++bad;',
    '            if (st.lockedDoorAt(3, 10) != nullptr) ++bad;',
    '        }',
    '        // scenario 2: one open side is no slot -',
    '        // the lone floor row y 9 places nothing',
    '        {',
    '            AppState st;',
    '            for (int y = 0; y < 64; ++y)',
    '                for (int x = 0; x < 64; ++x)',
    '                    st.map.set(x, y, world::TILE_WALL);',
    '            for (int x = 0; x < 64; ++x)',
    '                st.map.set(x, 9, world::TILE_FLOOR);',
    '            st.rng.seed(2);',
    '            st.placeLockedDoors();',
    '            if (!st.lockedDoors.empty()) ++bad;',
    '        }',
    '        // scenario 3: the no-thief bump - the',
    '        // turn is spent, the try is not (seed',
    '        // 1: the wander d12 reads 2, quiet)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            LockedDoor d;',
    '            d.x = 5; d.y = 7;',
    '            st.lockedDoors.push_back(d);',
    '            st.rng.seed(1);',
    '            st.bumpLockedDoor(5, 7);',
    '            if (st.turnCount != 1) ++bad;',
    '            if (st.lockedDoors[0].tryLevel != 0 ||',
    '                st.lockedDoors[0].opened) ++bad;',
    '            if (st.log.get(0).find("no thief")',
    '                == std::string::npos) ++bad;',
    '            if (st.lockedDoorAt(5, 7) == nullptr) ++bad;',
    '        }',
    '        // scenario 4: the pick succeeds - the',
    '        // DEAD thief never rolls; the living one',
    '        // (level 17 human dex 18, chance 1140)',
    '        // opens it (seed 1: 6 rounds, the roll',
    '        // 517, the wander d12 8)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character fell;',
    '            fell.name = "Fell";',
    '            fell.classIndex = 3; fell.level = 17;',
    '            fell.race = 0; fell.abilities.dex = 18;',
    '            fell.hp = 0; fell.maxHp = 30;',
    '            st.party.members.push_back(fell);',
    '            Character sly;',
    '            sly.name = "Sly";',
    '            sly.classIndex = 3; sly.level = 17;',
    '            sly.race = 0; sly.abilities.dex = 18;',
    '            sly.hp = 30; sly.maxHp = 30;',
    '            st.party.members.push_back(sly);',
    '            LockedDoor d;',
    '            d.x = 5; d.y = 7;',
    '            st.lockedDoors.push_back(d);',
    '            st.rng.seed(1);',
    '            st.bumpLockedDoor(5, 7);',
    '            if (st.turnCount != 1) ++bad;',
    '            if (!st.lockedDoors[0].opened ||',
    '                st.lockedDoors[0].tryLevel != 17) ++bad;',
    '            if (st.log.get(0).find(',
    '                    "Sly works the lock for 6 rounds "',
    '                    "- it opens")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(0).find("Fell")',
    '                != std::string::npos) ++bad;',
    '            if (st.lockedDoorAt(5, 7) != nullptr) ++bad;',
    '        }',
    '        // scenario 5: the one-try ladder (seed',
    '        // 23). Bump 1 at level 1 (chance 150):',
    '        // the roll 167 resists - only WITH the',
    '        // dex 9 fold; bump 2 at the same level',
    '        // reads the refuse line (no time or',
    '        // percentile draw); bump 3 at level 2',
    '        // (chance 190) retries: 6 rounds, the',
    '        // roll 299 resists again',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character sly;',
    '            sly.name = "Sly";',
    '            sly.classIndex = 3; sly.level = 1;',
    '            sly.race = 0; sly.abilities.dex = 9;',
    '            sly.hp = 30; sly.maxHp = 30;',
    '            st.party.members.push_back(sly);',
    '            LockedDoor d;',
    '            d.x = 5; d.y = 7;',
    '            st.lockedDoors.push_back(d);',
    '            st.rng.seed(23);',
    '            st.bumpLockedDoor(5, 7);',
    '            if (st.lockedDoors[0].opened ||',
    '                st.lockedDoors[0].tryLevel != 1) ++bad;',
    '            if (st.log.get(0).find(',
    '                    "for 1 rounds - it resists")',
    '                == std::string::npos) ++bad;',
    '            st.bumpLockedDoor(5, 7);',
    '            if (st.turnCount != 2 ||',
    '                st.lockedDoors[0].tryLevel != 1) ++bad;',
    '            if (st.log.get(0).find("higher level")',
    '                == std::string::npos) ++bad;',
    '            st.party.members[0].level = 2;',
    '            st.bumpLockedDoor(5, 7);',
    '            if (st.turnCount != 3 ||',
    '                st.lockedDoors[0].opened ||',
    '                st.lockedDoors[0].tryLevel != 2) ++bad;',
    '            if (st.log.get(0).find(',
    '                    "for 6 rounds - it resists")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(0).find("higher level")',
    '                != std::string::npos) ++bad;',
    '            if (st.lockedDoorAt(5, 7) == nullptr) ++bad;',
    '        }',
    '        printf("R304 thief locks engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
# the anchor line is EXISTING repo text (83
# cols, the R298 include); the NEW line rides
# at 61
for t in (RT_INC_OLD, RT_INC_NEW):
    clean(t, 90)
# the audit blocks carry the printf newline (BS) - the
# R300 check: BS lives ONLY on the printf lines, one
# per line, and nothing else carries a backslash
for t in (RT_AUD_OLD, RT_AUD_NEW):
    for ln in t.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii in audit'
        assert len(ln) <= 76, 'audit line too long: ' + ln
        assert chr(39) not in ln, 'apostrophe in audit'
        if 'printf("' in ln:
            assert ln.count(BS) == 1, 'printf BS count wrong'
        else:
            assert BS not in ln, 'stray backslash in audit'

p = 'regtest.cpp'
s = rd(p)
if 'R304 thief locks engine audit' in s:
    already.append('regtest.cpp: the audit pair')
else:
    assert s.count('audit: bad') == 225, 'rt census not 225'
    assert s.count(RT_INC_OLD) == 1, 'rt include anchor not unique'
    assert s.count(RT_AUD_OLD) == 1, 'rt audit anchor not unique'
    assert 'R304a' not in s, 'rt marker collision'
    s = s.replace(RT_INC_OLD, RT_INC_NEW)
    s = s.replace(RT_AUD_OLD, RT_AUD_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the audit pair')
s = rd(p)
assert s.count('audit: bad') == 227, 'patch f census wrong'
assert s.count('R304a thief locks seam audit') == 1, 'patch f seam label'
assert s.count('R304 thief locks engine audit') == 1, 'patch f engine label'
assert s.count('#include "rules/locktime.h"') == 1, 'patch f include'
assert s.count('R303 thief pockets engine audit') == 1, 'patch f r303 tail'
assert s.count('R227: the wis mental save wiring audit') == 1, \
    'patch f r227 head'
assert s.count('THF_OPEN_LOCKS') == 7, 'patch f open locks probes'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- (g) tools/phb_gap_report.md: the box ----
GR_HEAD_OLD = NL.join([
    '      move silently draw; R303: the street',
    '      site rolls the pick pockets draw;',
    '      the rest stay data) -',
])
GR_HEAD_NEW = NL.join([
    '      move silently draw; R303: the street',
    '      site rolls the pick pockets draw;',
    '      R304: the locked-door site rolls the',
    '      open locks draw; the rest stay data) -',
])
GR_INS_OLD = NL.join([
    '      convention). Census 225. The ledger',
    '      holds ZERO open items.',
    '',
    '## R299 the party recordings round (the third',
])
GR_BOX = NL.join([
    '- [x] **The thief locks wired - WIRED',
    '      R304:** the open locks column gains',
    '      its first engine site - the locked',
    '      door. rules/locktime.h CREATED (the',
    '      grenade.h pattern): the DMG THIEF',
    '      ABILITIES time pins (the pick takes',
    '      1-10 rounds on the complexity, most',
    '      locks 1-4; the traps roll rides the',
    '      locks time) and the doors prose',
    '      (wooden doors always metal bound,',
    '      metal doors usually locked), with',
    '      the per-delve count judgment (one',
    '      door; the print carries no count).',
    '      The site: one locked door per delve',
    '      (the R45 placement scan - a TILE_WALL',
    '      slot with open tiles on both sides',
    '      of one axis) prints as a TILE_DOOR',
    '      the company sees but cannot pass;',
    '      the bump spends the turn and the',
    '      first living thief works the lock',
    '      for the DMG time draw against the',
    '      printed percentile (the R298 seam;',
    '      one try per lock, a retry waits for',
    '      a higher level thief, the printed',
    '      note; the wander check rides, the',
    '      searchExplore convention). The',
    '      remaining functions stay data (hide',
    '      in shadows, climb walls, read',
    '      languages - no engine site; hear',
    '      noise keeps the R120 portal listen',
    '      convention, not the R298 percentile).',
    '      The R304a battery audit walks the',
    '      time pins and the open locks',
    '      percentile boundaries (evaluable -',
    '      verified by audit_eval); the R304',
    '      engine audit pins every scenario on',
    '      seeded sequences (the replica walked',
    '      the draws first). Census 227. The',
    '      ledger holds ZERO open items.',
])
GR_INS_NEW = NL.join([
    '      convention). Census 225. The ledger',
    '      holds ZERO open items.',
    '',
    GR_BOX,
    '',
    '## R299 the party recordings round (the third',
])
for t in (GR_HEAD_OLD, GR_HEAD_NEW, GR_INS_OLD, GR_BOX, GR_INS_NEW):
    clean(t, 57)

p = 'tools/phb_gap_report.md'
s = rd(p)
if 'The thief locks wired' in s:
    already.append('phb_gap_report.md: the wiring-arc box')
else:
    assert s.count(GR_HEAD_OLD) == 1, 'gr head anchor not unique'
    assert s.count(GR_INS_OLD) == 1, 'gr insert anchor not unique'
    assert 'Census 227.' not in s, 'gr marker collision'
    s = s.replace(GR_HEAD_OLD, GR_HEAD_NEW)
    s = s.replace(GR_INS_OLD, GR_INS_NEW)
    wr(p, s)
    applied.append('phb_gap_report.md: the wiring-arc box')
s = rd(p)
assert s.count('The thief locks wired') == 1, 'patch g box'
assert s.count('R304: the locked-door site') == 1, 'patch g head amend'
assert s.count('holds ZERO open items') == 4, 'patch g zero-item notes'
assert s.count('Census 227.') == 1, 'patch g census note'
assert s.count('Census 225.') == 1, 'patch g R303 census'
assert s.count('Census 223.') == 1, 'patch g R302 census'
assert 'Census 221.' in s, 'patch g ate the R301 census'
assert 'Census 215.' in s, 'patch g ate the R298 census'
assert 'PINNED R298' in s, 'patch g ate the R298 box head'
assert 'The thief pockets wired' in s, 'patch g ate the R303 box'
assert 'The thief silence wired' in s, 'patch g ate the R302 box'
assert 'The thief trap rolls wired' in s, 'patch g ate the R301 box'
assert '## R299 the party recordings round' in s, 'patch g ate the head'
assert s.count('- [ ]') == 0, 'patch g opened an item'
assert len(applied) + len(already) == 7, 'patch g count wrong'

# ---- (h) tools/dmg_gap_report.md: the chronicle ----
DMG_OLD = NL.join([
    'candidate). No audit added; the',
    'battery census stays 213.',
    '',
    'Categories:',
])
DMG_NEW = NL.join([
    'candidate). No audit added; the',
    'battery census stays 213.',
    '',
    'R304 PINNED the DMG THIEF ABILITIES time',
    'figures and the FIRST DUNGEON ADVENTURE',
    'doors prose: rules/locktime.h, the',
    'grenade.h pattern - the lock-pick time',
    'band (1-10 rounds on the complexity,',
    'most locks 1-4), the traps-time-rides-',
    'locks note, the wooden-doors-always-',
    'metal-bound and metal-doors-usually-',
    'locked prose, and the per-delve count',
    'judgment (one locked door; the print',
    'carries no count). The locked door',
    'wires the PHB open locks percentile at',
    'the dungeon door site (the phb report',
    'carries the round box; the battery',
    'census moves 225 -> 227).',
    '',
    'Categories:',
])
for t in (DMG_OLD, DMG_NEW):
    clean(t, 57)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R304 PINNED the DMG THIEF ABILITIES' in s:
    already.append('dmg_gap_report.md: the chronicle')
else:
    assert s.count(DMG_OLD) == 1, 'dmg anchor not unique'
    s = s.replace(DMG_OLD, DMG_NEW)
    wr(p, s)
    applied.append('dmg_gap_report.md: the chronicle')
s = rd(p)
assert s.count('R304 PINNED the DMG THIEF ABILITIES') == 1, 'patch h note'
assert s.count('Categories:') == 1, 'patch h legend head'
assert s.count('battery census stays 213.') == 1, 'patch h r296 tail'
assert s.count('- [ ]') == 1, 'patch h checkbox count'
assert 'R296 the PHB report scope round' in s, 'patch h ate the R296 note'
assert len(applied) + len(already) == 8, 'patch h count wrong'

# ---- R304 fails/tail ----
if fails:
    print('R304 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 8:
    print('R304 splice: FAIL - expected 8 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R304 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R304 note: 8 patches; the battery census 225 -> 227;')
print('the phb ledger holds ZERO open items')
print('commit: R304: the locked door wired (census 227)')

