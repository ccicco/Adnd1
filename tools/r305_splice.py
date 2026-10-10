#!/usr/bin/env python3
# tools/r305_splice.py - R305: the locked door
# forced (the R304 successor - the DMG doors
# prose pins, and the STR Table II parentheticals
# gain the [O] force site).
#
# The DMG FIRST DUNGEON ADVENTURE print: each
# person pushing rolls a d6 (a 1 or 2 typically
# opens), locked doors need two or even three
# simultaneous 1s, the standard 8-foot door
# takes up to three shoulders and a narrow door
# one, very heavy doors halve the chances,
# breaking a metal-bound wooden door takes a
# full turn and at least 3 noise checks, and
# metal doors need the knock spell. This round
# pins the prose (rules/doorforce.h, the
# grenade.h pattern - the typical band, the
# halves and the break lane stay data) and
# wires the width and simultaneous folds at
# the R304 locked door: [O] in the dungeon
# spends the turn and up to three living
# members roll the d6 against the R153
# open-doors-locked parentheticals (the wrench
# once ever per door) while two simultaneous 1s
# tear the lock out.
#
#   (a) rules/doorforce.h CREATED - the DMG
#       forcing prose pins (nine helpers).
#   (b) game/appstate.h - the LockedDoor
#       exTried flag and the declaration.
#   (c) game/state_dungeon.cpp - the site:
#       forceLockedDoor (the adjacency scan,
#       the width-capped d6 rolls, the
#       once-ever wrench, the simultaneous
#       fold, the turn and the wander check).
#   (d) adnd1.cpp - the [O] key and the hint
#       (the case labels carry the one
#       apostrophe family of the content,
#       built via chr(39), the R303 precedent).
#   (e) regtest.cpp - the R305 audit pair (the
#       battery census 227 -> 229): the R305a
#       seam audit walks the forcing pins and
#       their folds (evaluable - verified by
#       audit_eval) and the R305 engine audit
#       pins every scenario on seeded
#       sequences (the replica walked the
#       draws first - no compiler in the splice
#       sandbox).
#   (f) tools/phb_gap_report.md - the STR
#       Table II box head amended and the
#       round box (the ledger holds ZERO open
#       items).
#   (g) tools/dmg_gap_report.md - the
#       chronicle paragraph (the DMG pins
#       recorded).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY patch
# (the R142 lesson). ZERO literal backslash
# bytes in this file (the audit printf newline
# builds via BS) and no CONTENT string embeds
# an apostrophe outside the adnd1.cpp case
# labels, non-ASCII or (for the gap reports) a
# line past 57 columns.
# Commit: "R305: the locked door forced (census
# 229)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
BS = chr(92)
Q = chr(39)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit, allow_apos=False):
    if not allow_apos:
        assert Q not in s, 'apostrophe in content'
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

# ---- (a) rules/doorforce.h CREATED ----
DF = NL.join([
    '// ====================================================================',
    '// Adnd1 - rules/doorforce.h',
    '// R305: the DMG FIRST DUNGEON ADVENTURE',
    '// doors prose - the forcing pins - a DATA',
    '// pin (the grenade.h pattern), WIRED R305:',
    '// the locked-door site draws the width and',
    '// simultaneous folds.',
    '//',
    '// The doors print: each person pushing',
    '// rolls a d6 and "a roll of 1 or 2',
    '// typically indicates success"; very heavy',
    '// doors "might reduce chances by half";',
    '// locked doors "might only open if two or',
    '// even three simultaneous 1s are rolled"',
    '// (JUDGMENT: the band pins at two); the',
    '// standard door "allows up to three',
    '// characters to attempt opening" and a door',
    '// of 3 feet or less "allows but a single',
    '// character"; breaking a metal-bound',
    '// wooden door takes "a full turn" and "at',
    '// least 3 checks" for the noise; metal',
    '// doors need "a knock spell or similar',
    '// means most of the time".',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int doorForceTypicalMin() {',
    '    // the typical band floor: a roll of 1',
    '    // indicates success',
    '    return 1;',
    '}',
    '',
    'inline int doorForceTypicalMax() {',
    '    // the typical band ceiling: a 2 still',
    '    // opens (anything above does not)',
    '    return 2;',
    '}',
    '',
    'inline int doorVeryHeavyHalvesChances() {',
    '    // very heavy doors might reduce the',
    '    // chances by half',
    '    return 1;',
    '}',
    '',
    'inline int doorLockedSimultaneousOnes() {',
    '    // JUDGMENT: locked doors need two or',
    '    // even three simultaneous 1s - the band',
    '    // pins at two',
    '    return 2;',
    '}',
    '',
    'inline int doorWidthStandardAttempts() {',
    '    // the standard door allows up to three',
    '    // characters to attempt opening',
    '    return 3;',
    '}',
    '',
    'inline int doorNarrowWidthAttempts() {',
    '    // a door of 3 feet or less allows but a',
    '    // single character to make an attempt',
    '    return 1;',
    '}',
    '',
    'inline int doorWoodBreakFullTurn() {',
    '    // breaking a metal-bound wooden door',
    '    // takes a full turn',
    '    return 1;',
    '}',
    '',
    'inline int doorWoodBreakMonsterChecks() {',
    '    // the break noise draws at least 3',
    '    // checks for nearby monsters',
    '    return 3;',
    '}',
    '',
    'inline int doorMetalNeedsKnock() {',
    '    // metal doors need a knock spell or',
    '    // similar means most of the time',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
    '',
])
clean(DF, 78)

p = 'rules/doorforce.h'
if os.path.exists(os.path.join(ROOT, p)):
    s = rd(p)
    if 'R305: the DMG FIRST DUNGEON ADVENTURE' in s:
        already.append('doorforce.h created')
    else:
        fails.append('doorforce.h exists without the R305 marker')
else:
    wr(p, DF)
    applied.append('doorforce.h created')
s = rd(p)
assert s.count('inline int door') == 9, 'df pin count'
assert s.count('return 1;') == 5, 'df ones'
assert s.count('return 2;') == 2, 'df twos'
assert s.count('return 3;') == 2, 'df threes'
assert s.count('}  // namespace rules') == 1, 'df namespace close'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) game/appstate.h: the flag + the decl ----
AH_STRUCT_OLD = NL.join([
    'struct LockedDoor {',
    '    int  x = 0, y = 0;',
    '    bool opened = false;',
    '    int  tryLevel = 0;',
    '};',
])
AH_STRUCT_NEW = NL.join([
    'struct LockedDoor {',
    '    int  x = 0, y = 0;',
    '    bool opened = false;',
    '    int  tryLevel = 0;',
    '    bool exTried = false;   // R305: the wrench once ever',
    '};',
])
AH_DECL_OLD = NL.join([
    '    void bumpLockedDoor(int x, int y);',
])
AH_DECL_NEW = NL.join([
    '    void bumpLockedDoor(int x, int y);',
    '',
    '    // R305: [O] force - the company shoulders',
    '    // the adjacent locked door: up to three',
    '    // living members (the width cap) each',
    '    // roll the d6 against the R153 open-doors',
    '    // parentheticals (the wrench is once ever',
    '    // per door), or two simultaneous 1s tear',
    '    // the lock out (the DMG doors prose)',
    '    void forceLockedDoor();',
])
for t in (AH_STRUCT_OLD, AH_STRUCT_NEW, AH_DECL_OLD, AH_DECL_NEW):
    clean(t, 78)

p = 'game/appstate.h'
s = rd(p)
if 'forceLockedDoor' in s:
    already.append('appstate.h: the flag + the decl')
else:
    assert s.count(AH_STRUCT_OLD) == 1, 'ah struct anchor not unique'
    assert s.count(AH_DECL_OLD) == 1, 'ah decl anchor not unique'
    assert 'exTried' not in s, 'ah marker collision'
    s = s.replace(AH_STRUCT_OLD, AH_STRUCT_NEW)
    s = s.replace(AH_DECL_OLD, AH_DECL_NEW)
    wr(p, s)
    applied.append('appstate.h: the flag + the decl')
s = rd(p)
assert s.count('bool exTried = false;') == 1, 'patch b flag'
assert s.count('void forceLockedDoor();') == 1, 'patch b decl'
assert s.count('void bumpLockedDoor(int x, int y);') == 1, \
    'patch b bump decl'
assert s.count('struct LockedDoor') == 1, 'patch b struct'
assert s.count('int  tryLevel = 0;') == 1, 'patch b try level'
assert s.count('void placeLockedDoors();') == 1, 'patch b place decl'
assert s.count('const LockedDoor* lockedDoorAt('
               'int x, int y) const;') == 1, 'patch b lookup decl'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) game/state_dungeon.cpp: the site ----
SD_INC_OLD = NL.join([
    '#include "rules/locktime.h"   // R304: the lock time draw',
])
SD_INC_NEW = NL.join([
    '#include "rules/locktime.h"   // R304: the lock time draw',
    '#include "rules/doorforce.h"  // R305: the door force folds',
])
SD_SITE_OLD = NL.join([
    '        // the turn spent can draw a wanderer',
    '        if (dm::wanderCheck(dice, wander))',
    '            spawnWanderingEncounter();',
    '    }',
    '',
    '// ---- searchExplore ----',
])
SD_SITE_NEW = NL.join([
    '        // the turn spent can draw a wanderer',
    '        if (dm::wanderCheck(dice, wander))',
    '            spawnWanderingEncounter();',
    '    }',
    '',
    '// ---- forceLockedDoor ----',
    '// R305: [O] - the company puts its shoulders',
    '// to the adjacent locked door. The shove',
    '// spends the turn (the searchExplore',
    '// convention) and up to',
    '// doorWidthStandardAttempts living members',
    '// each roll the d6 against the R153',
    '// open-doors-locked parentheticals (the',
    '// exceptional wrench is once ever per door),',
    '// while doorLockedSimultaneousOnes',
    '// simultaneous 1s tear the lock out of the',
    '// frame (the DMG doors prose; the wander',
    '// check rides, the bump convention).',
    'void AppState::forceLockedDoor(){',
    '        if (mode != MODE_EXPLORE) return;',
    '        if (!party.alive()) return;',
    '',
    '        ++turnCount;',
    '        tickActivity(1);   // R119: the shove is work too',
    '',
    '        LockedDoor* door = nullptr;',
    '        for (auto& d : lockedDoors) {',
    '            if (d.opened) continue;',
    '            int dx = d.x - party.x;',
    '            int dy = d.y - party.y;',
    '            bool hits = (dx == 1 || dx == -1) && dy == 0;',
    '            hits = hits ||',
    '                   (dx == 0 && (dy == 1 || dy == -1));',
    '            if (hits) {',
    '                door = &d;',
    '                break;',
    '            }',
    '        }',
    '        if (door == nullptr) {',
    '            log.add("There is no locked door to force "',
    '                    "here.");',
    '        } else {',
    '            int ones = 0;',
    '            int attempts = 0;',
    '            bool opened = false;',
    '            for (const auto& c : party.members) {',
    '                if (attempts >=',
    '                        rules::doorWidthStandardAttempts())',
    '                    break;',
    '                if (c.hp <= 0) continue;',
    '                ++attempts;',
    '                int roll = 1 + (int)rng.below(6);',
    '                int lmax = rules::strOpenDoorsLockedMax(',
    '                    c.abilities.str, c.exStr);',
    '                if (lmax > 0 && !door->exTried) {',
    '                    door->exTried = true;',
    '                    if (roll <= lmax) {',
    '                        door->opened = true;',
    '                        opened = true;',
    '                        char buf[96];',
    '                        snprintf(buf, sizeof buf,',
    '                                 "%s wrenches the locked "',
    '                                 "door open!",',
    '                                 c.name.c_str());',
    '                        log.add(buf);',
    '                        break;',
    '                    }',
    '                }',
    '                if (roll == 1) ++ones;',
    '            }',
    '            if (!opened && ones >=',
    '                    rules::doorLockedSimultaneousOnes()) {',
    '                door->opened = true;',
    '                opened = true;',
    '                log.add("The shoulders slam home - the "',
    '                        "lock gives!");',
    '            }',
    '            if (!opened)',
    '                log.add("The door will not budge.");',
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
if 'void AppState::forceLockedDoor' in s:
    already.append('state_dungeon.cpp: the site')
else:
    assert s.count(SD_INC_OLD) == 1, 'sd include anchor not unique'
    assert s.count(SD_SITE_OLD) == 1, 'sd site anchor not unique'
    assert 'forceLockedDoor' not in s, 'sd marker collision'
    s = s.replace(SD_INC_OLD, SD_INC_NEW)
    s = s.replace(SD_SITE_OLD, SD_SITE_NEW)
    wr(p, s)
    applied.append('state_dungeon.cpp: the site')
s = rd(p)
assert s.count('#include "rules/doorforce.h"') == 1, 'patch c include'
assert s.count('void AppState::forceLockedDoor') == 1, 'patch c site'
assert s.count('// ---- searchExplore ----') == 1, 'patch c search head'
assert s.count('// ---- bumpLockedDoor ----') == 1, 'patch c bump head'
assert s.count('wrenches the locked') == 1, 'patch c wrench line'
assert s.count('doorWidthStandardAttempts') == 2, 'patch c width fold'
assert s.count('doorLockedSimultaneousOnes') == 2, \
    'patch c simult fold'
assert s.count('strOpenDoorsLockedMax') == 1, 'patch c parenthetical'
assert s.count('The door will not budge.') == 1, 'patch c budge line'
assert s.count('spawnWanderingEncounter();') == 4, 'patch c wander'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) adnd1.cpp: the [O] key + the hint ----
AD_CASE_OLD = NL.join([
    '                    case ' + Q + 'P' + Q + ':',
    '                    case ' + Q + 'p' + Q + ':',
    '                        g_app.quaffExplore();',
    '                        break;',
])
AD_CASE_NEW = NL.join([
    '                    case ' + Q + 'P' + Q + ':',
    '                    case ' + Q + 'p' + Q + ':',
    '                        g_app.quaffExplore();',
    '                        break;',
    '',
    '                    // R305: force the adjacent locked door',
    '                    case ' + Q + 'O' + Q + ':',
    '                    case ' + Q + 'o' + Q + ':',
    '                        g_app.forceLockedDoor();',
    '                        break;',
])
AD_HINT_OLD = NL.join([
    '             "[K] save  [L] load  [R] rest  [B] town",',
])
AD_HINT_NEW = NL.join([
    '             "[O] force  [K] save  [L] load  [R] rest  "',
    '             "[B] town",',
])
clean(AD_CASE_OLD, 78, allow_apos=True)
clean(AD_CASE_NEW, 78, allow_apos=True)
for t in (AD_HINT_OLD, AD_HINT_NEW):
    clean(t, 78)

p = 'adnd1.cpp'
s = rd(p)
if 'g_app.forceLockedDoor();' in s:
    already.append('adnd1.cpp: the [O] key + the hint')
else:
    assert s.count(AD_CASE_OLD) == 1, 'ad case anchor not unique'
    assert s.count(AD_HINT_OLD) == 1, 'ad hint anchor not unique'
    assert 'forceLockedDoor' not in s, 'ad marker collision'
    s = s.replace(AD_CASE_OLD, AD_CASE_NEW)
    s = s.replace(AD_HINT_OLD, AD_HINT_NEW)
    wr(p, s)
    applied.append('adnd1.cpp: the [O] key + the hint')
s = rd(p)
assert s.count('g_app.forceLockedDoor();') == 1, 'patch d the call'
assert (NL.join(['                    case ' + Q + 'O' + Q + ':',
                 '                    case ' + Q + 'o' + Q + ':'])
        in s), 'patch d the case pair'
assert s.count('g_app.quaffExplore();') == 1, 'patch d quaff intact'
assert s.count('"[O] force  [K] save  [L] load  [R] rest  "') == 1, \
    'patch d hint head'
assert s.count('             "[B] town",') == 1, 'patch d hint tail'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) regtest.cpp: the include + the audit pair ----
RT_INC_OLD = NL.join([
    '#include "rules/locktime.h"  // R304: the DMG lock time pins',
])
RT_INC_NEW = NL.join([
    '#include "rules/locktime.h"  // R304: the DMG lock time pins',
    '#include "rules/doorforce.h"  // R305: the DMG door force pins',
])
RT_AUD_OLD = NL.join([
    '        printf("R304 thief locks engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_AUD_NEW = NL.join([
    '        printf("R304 thief locks engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R305a: the door force seam audit ----',
    '    // The DMG FIRST DUNGEON ADVENTURE doors',
    '    // prose (rules/doorforce.h, the grenade.h',
    '    // pattern) - the forcing pins and their',
    '    // folds - verified by audit_eval.',
    '    {',
    '        int bad = 0;',
    '        // the typical band: a roll of 1 or 2',
    '        // indicates success',
    '        if (rules::doorForceTypicalMin() != 1 ||',
    '            rules::doorForceTypicalMax() != 2) ++bad;',
    '        // very heavy doors halve the chances',
    '        if (rules::doorVeryHeavyHalvesChances() != 1)',
    '            ++bad;',
    '        // locked doors need simultaneous 1s',
    '        // (JUDGMENT: the print reads two or even',
    '        // three - the band pins at two)',
    '        if (rules::doorLockedSimultaneousOnes() != 2)',
    '            ++bad;',
    '        // the width caps: three shoulders at the',
    '        // standard door, one at a narrow',
    '        if (rules::doorWidthStandardAttempts() != 3 ||',
    '            rules::doorNarrowWidthAttempts() != 1)',
    '            ++bad;',
    '        // the wood-break lane: a full turn and',
    '        // at least 3 noise checks',
    '        if (rules::doorWoodBreakFullTurn() != 1 ||',
    '            rules::doorWoodBreakMonsterChecks() != 3)',
    '            ++bad;',
    '        // metal doors need the knock spell',
    '        if (rules::doorMetalNeedsKnock() != 1) ++bad;',
    '        // folds: the typical band spans the',
    '        // printed 1-2; the width band orders;',
    '        // the simultaneous band rides inside',
    '        // the printed two-to-three',
    '        if (rules::doorForceTypicalMax() -',
    '                rules::doorForceTypicalMin() + 1 != 2)',
    '            ++bad;',
    '        if (rules::doorNarrowWidthAttempts() >',
    '                rules::doorWidthStandardAttempts()) ++bad;',
    '        if (rules::doorLockedSimultaneousOnes() < 2 ||',
    '            rules::doorLockedSimultaneousOnes() > 3)',
    '            ++bad;',
    '        printf("R305a door force seam audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R305: the door force engine audit ----',
    '    // The [O] force site: up to',
    '    // doorWidthStandardAttempts living members',
    '    // roll the d6 against the R153 open-doors',
    '    // parentheticals (the wrench is once ever',
    '    // per door) or the simultaneous 1s tear',
    '    // the lock out (the DMG doors prose; the',
    '    // wander check rides, the bump',
    '    // convention). Every scenario sits on a',
    '    // seeded sequence the replica walked first',
    '    // (no compiler in the splice sandbox). The',
    '    // seeds discriminate: scenario 6 holds on',
    '    // rolls 6, 1 and 4 at the width cap - the',
    '    // counterfactual fourth roll reads 1, so a',
    '    // broken cap would tear the lock out; the',
    '    // scenario 8 second roll reads 2, which a',
    '    // missing once-ever gate would spend again.',
    '    {',
    '        int bad = 0;',
    '        // scenario 1: the R153 parentheticals -',
    '        // only the exceptional rows force a lock',
    '        {',
    '            rules::ExceptionalStrength ex;',
    '            if (rules::strOpenDoorsLockedMax(',
    '                    18, ex) != 0) ++bad;',
    '            ex.has = true; ex.pct = 95;',
    '            if (rules::strOpenDoorsLockedMax(',
    '                    18, ex) != 1) ++bad;',
    '            ex.pct = 100;',
    '            if (rules::strOpenDoorsLockedMax(',
    '                    18, ex) != 2) ++bad;',
    '            if (rules::strOpenDoorsLockedMax(',
    '                    17, ex) != 0) ++bad;',
    '        }',
    '        // scenario 2: no lock in reach - the turn',
    '        // spends and the shove finds nothing',
    '        // (seed 1: the wander d12 reads 2, quiet)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character bru;',
    '            bru.name = "Bru";',
    '            bru.classIndex = 0; bru.level = 1;',
    '            bru.race = 0; bru.abilities.str = 10;',
    '            bru.hp = 30; bru.maxHp = 30;',
    '            st.party.members.push_back(bru);',
    '            st.party.formed = true;',
    '            st.party.x = 4; st.party.y = 7;',
    '            st.rng.seed(1);',
    '            st.forceLockedDoor();',
    '            if (st.turnCount != 1) ++bad;',
    '            if (st.log.get(0).find("no locked door")',
    '                == std::string::npos) ++bad;',
    '        }',
    '        // scenario 3: the lock sits DIAGONAL - no',
    '        // shove target (seed 1)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character bru;',
    '            bru.name = "Bru";',
    '            bru.classIndex = 0; bru.level = 1;',
    '            bru.race = 0; bru.abilities.str = 10;',
    '            bru.hp = 30; bru.maxHp = 30;',
    '            st.party.members.push_back(bru);',
    '            st.party.formed = true;',
    '            st.party.x = 4; st.party.y = 6;',
    '            LockedDoor d;',
    '            d.x = 5; d.y = 7;',
    '            st.lockedDoors.push_back(d);',
    '            st.rng.seed(1);',
    '            st.forceLockedDoor();',
    '            if (st.turnCount != 1) ++bad;',
    '            if (st.log.get(0).find("no locked door")',
    '                == std::string::npos) ++bad;',
    '            if (st.lockedDoorAt(5, 7) == nullptr) ++bad;',
    '            if (st.lockedDoors[0].opened) ++bad;',
    '        }',
    '        // scenario 4: the DEAD member never rolls;',
    '        // the two living shoulders both roll 1 -',
    '        // the lock tears out (seed 77)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character dell;',
    '            dell.name = "Dell";',
    '            dell.classIndex = 0; dell.level = 1;',
    '            dell.race = 0; dell.abilities.str = 10;',
    '            dell.hp = 0; dell.maxHp = 30;',
    '            st.party.members.push_back(dell);',
    '            Character one;',
    '            one.name = "One";',
    '            one.classIndex = 0; one.level = 1;',
    '            one.race = 0; one.abilities.str = 10;',
    '            one.hp = 30; one.maxHp = 30;',
    '            st.party.members.push_back(one);',
    '            Character two;',
    '            two.name = "Two";',
    '            two.classIndex = 0; two.level = 1;',
    '            two.race = 0; two.abilities.str = 10;',
    '            two.hp = 30; two.maxHp = 30;',
    '            st.party.members.push_back(two);',
    '            st.party.formed = true;',
    '            st.party.x = 4; st.party.y = 7;',
    '            LockedDoor d;',
    '            d.x = 5; d.y = 7;',
    '            st.lockedDoors.push_back(d);',
    '            st.rng.seed(77);',
    '            st.forceLockedDoor();',
    '            if (st.turnCount != 1) ++bad;',
    '            if (!st.lockedDoors[0].opened) ++bad;',
    '            if (st.lockedDoors[0].tryLevel != 0) ++bad;',
    '            if (st.log.get(0).find("slam home")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(0).find("Dell")',
    '                != std::string::npos) ++bad;',
    '            if (st.lockedDoorAt(5, 7) != nullptr) ++bad;',
    '        }',
    '        // scenario 5: repeatable - the first shove',
    '        // rolls 1 and 6 (one 1, the door holds);',
    '        // the second rolls 1 and 1 (the lock tears',
    '        // out; seed 63)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character one;',
    '            one.name = "One";',
    '            one.classIndex = 0; one.level = 1;',
    '            one.race = 0; one.abilities.str = 10;',
    '            one.hp = 30; one.maxHp = 30;',
    '            st.party.members.push_back(one);',
    '            Character two;',
    '            two.name = "Two";',
    '            two.classIndex = 0; two.level = 1;',
    '            two.race = 0; two.abilities.str = 10;',
    '            two.hp = 30; two.maxHp = 30;',
    '            st.party.members.push_back(two);',
    '            st.party.formed = true;',
    '            st.party.x = 4; st.party.y = 7;',
    '            LockedDoor d;',
    '            d.x = 5; d.y = 7;',
    '            st.lockedDoors.push_back(d);',
    '            st.rng.seed(63);',
    '            st.forceLockedDoor();',
    '            if (st.lockedDoorAt(5, 7) == nullptr) ++bad;',
    '            if (st.log.get(0).find("will not budge")',
    '                == std::string::npos) ++bad;',
    '            st.forceLockedDoor();',
    '            if (st.turnCount != 2 ||',
    '                !st.lockedDoors[0].opened) ++bad;',
    '            if (st.log.get(0).find("slam home")',
    '                == std::string::npos) ++bad;',
    '        }',
    '        // scenario 6: the width cap - four living',
    '        // members but three rolls: 6, 1 and 4 hold',
    '        // the door (the counterfactual fourth roll',
    '        // reads 1 - a broken cap would tear the',
    '        // lock out; seed 17)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character one;',
    '            one.name = "A";',
    '            one.classIndex = 0; one.level = 1;',
    '            one.race = 0; one.abilities.str = 10;',
    '            one.hp = 30; one.maxHp = 30;',
    '            st.party.members.push_back(one);',
    '            Character two;',
    '            two.name = "B";',
    '            two.classIndex = 0; two.level = 1;',
    '            two.race = 0; two.abilities.str = 10;',
    '            two.hp = 30; two.maxHp = 30;',
    '            st.party.members.push_back(two);',
    '            Character three;',
    '            three.name = "C";',
    '            three.classIndex = 0; three.level = 1;',
    '            three.race = 0; three.abilities.str = 10;',
    '            three.hp = 30; three.maxHp = 30;',
    '            st.party.members.push_back(three);',
    '            Character four;',
    '            four.name = "E";',
    '            four.classIndex = 0; four.level = 1;',
    '            four.race = 0; four.abilities.str = 10;',
    '            four.hp = 30; four.maxHp = 30;',
    '            st.party.members.push_back(four);',
    '            st.party.formed = true;',
    '            st.party.x = 4; st.party.y = 7;',
    '            LockedDoor d;',
    '            d.x = 5; d.y = 7;',
    '            st.lockedDoors.push_back(d);',
    '            st.rng.seed(17);',
    '            st.forceLockedDoor();',
    '            if (st.turnCount != 1 ||',
    '                st.lockedDoors[0].opened) ++bad;',
    '            if (st.log.get(0).find("will not budge")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(0).find("wrenches")',
    '                != std::string::npos) ++bad;',
    '        }',
    '        // scenario 7: the 18/00 wrench - the',
    '        // parenthetical reads 2 and the roll 2',
    '        // opens it (seed 1)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character might;',
    '            might.name = "Might";',
    '            might.classIndex = 0; might.level = 1;',
    '            might.race = 0;',
    '            might.abilities.str = 18;',
    '            might.exStr.has = true;',
    '            might.exStr.pct = 100;',
    '            might.hp = 30; might.maxHp = 30;',
    '            st.party.members.push_back(might);',
    '            st.party.formed = true;',
    '            st.party.x = 4; st.party.y = 7;',
    '            LockedDoor d;',
    '            d.x = 5; d.y = 7;',
    '            st.lockedDoors.push_back(d);',
    '            st.rng.seed(1);',
    '            st.forceLockedDoor();',
    '            if (st.turnCount != 1) ++bad;',
    '            if (!st.lockedDoors[0].opened ||',
    '                !st.lockedDoors[0].exTried) ++bad;',
    '            if (st.log.get(0).find(',
    '                    "Might wrenches the locked "',
    '                    "door open")',
    '                == std::string::npos) ++bad;',
    '            if (st.lockedDoorAt(5, 7) != nullptr) ++bad;',
    '        }',
    '        // scenario 8: the wrench is ONCE EVER - the',
    '        // roll 3 spends it (the door holds); the',
    '        // second roll reads 2 and the spent wrench',
    '        // never fires (seed 2)',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            Character might;',
    '            might.name = "Might";',
    '            might.classIndex = 0; might.level = 1;',
    '            might.race = 0;',
    '            might.abilities.str = 18;',
    '            might.exStr.has = true;',
    '            might.exStr.pct = 100;',
    '            might.hp = 30; might.maxHp = 30;',
    '            st.party.members.push_back(might);',
    '            st.party.formed = true;',
    '            st.party.x = 4; st.party.y = 7;',
    '            LockedDoor d;',
    '            d.x = 5; d.y = 7;',
    '            st.lockedDoors.push_back(d);',
    '            st.rng.seed(2);',
    '            st.forceLockedDoor();',
    '            if (st.lockedDoors[0].opened ||',
    '                !st.lockedDoors[0].exTried) ++bad;',
    '            if (st.log.get(0).find("will not budge")',
    '                == std::string::npos) ++bad;',
    '            st.forceLockedDoor();',
    '            if (st.turnCount != 2 ||',
    '                st.lockedDoors[0].opened) ++bad;',
    '            if (st.log.get(0).find("wrenches")',
    '                != std::string::npos) ++bad;',
    '            if (st.log.get(0).find("will not budge")',
    '                == std::string::npos) ++bad;',
    '            if (st.lockedDoorAt(5, 7) == nullptr) ++bad;',
    '        }',
    '        printf("R305 door force engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
# the include lines ride at 58 (the locktime line is
# existing repo text, cleaned at the 90 limit)
for t in (RT_INC_OLD, RT_INC_NEW):
    clean(t, 90)
# the audit blocks carry the printf newline (BS) - the
# R300 check: BS lives ONLY on the printf lines, one
# per line, and nothing else carries a backslash
for t in (RT_AUD_OLD, RT_AUD_NEW):
    for ln in t.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii in audit'
        assert len(ln) <= 76, 'audit line too long: ' + ln
        assert Q not in ln, 'apostrophe in audit'
        if 'printf("' in ln:
            assert ln.count(BS) == 1, 'printf BS count wrong'
        else:
            assert BS not in ln, 'stray backslash in audit'

p = 'regtest.cpp'
s = rd(p)
if 'R305 door force engine audit' in s:
    already.append('regtest.cpp: the audit pair')
else:
    assert s.count('audit: bad') == 227, 'rt census not 227'
    assert s.count(RT_INC_OLD) == 1, 'rt include anchor not unique'
    assert s.count(RT_AUD_OLD) == 1, 'rt audit anchor not unique'
    assert 'R305a' not in s, 'rt marker collision'
    s = s.replace(RT_INC_OLD, RT_INC_NEW)
    s = s.replace(RT_AUD_OLD, RT_AUD_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the audit pair')
s = rd(p)
assert s.count('audit: bad') == 229, 'patch e census wrong'
assert s.count('R305a door force seam audit') == 1, 'patch e seam label'
assert s.count('R305 door force engine audit') == 1, \
    'patch e engine label'
assert s.count('#include "rules/doorforce.h"') == 1, 'patch e include'
assert s.count('R304 thief locks engine audit') == 1, 'patch e r304 tail'
assert s.count('R227: the wis mental save wiring audit') == 1, \
    'patch e r227 head'
assert s.count('strOpenDoorsLockedMax') == 5, 'patch e parentheticals'
assert s.count('forceLockedDoor();') == 9, 'patch e site calls'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) tools/phb_gap_report.md: the head + the box ----
GR153_OLD = NL.join([
    '- [x] **STR Table II (p.9, ability adjustments)** -',
    '      pinned R153: hit probability, damage, the',
    '      weight allowance, open doors and bend bars or',
    '      lift gates for the whole 3-18/00 run.',
])
GR153_NEW = NL.join([
    '- [x] **STR Table II (p.9, ability adjustments)** -',
    '      pinned R153: hit probability, damage, the',
    '      weight allowance, open doors and bend bars or',
    '      lift gates for the whole 3-18/00 run.',
    '      WIRED R305: the open-doors-locked',
    '      parentheticals now force the R304 lock',
    '      (the forcing prose pins in',
    '      rules/doorforce.h).',
])
GR_INS_OLD = NL.join([
    '      the draws first). Census 227. The',
    '      ledger holds ZERO open items.',
    '',
    '## R299 the party recordings round (the third',
])
GR_BOX = NL.join([
    '- [x] **The locked door forced - WIRED',
    '      R305:** the STR Table II open-doors',
    '      parentheticals gain their first engine',
    '      site. rules/doorforce.h CREATED (the',
    '      grenade.h pattern): the DMG FIRST',
    '      DUNGEON ADVENTURE forcing prose - the',
    '      typical 1-2 d6 band, the heavy-door',
    '      halves, the simultaneous-1s rule',
    '      (the print reads two or even three -',
    '      the JUDGMENT pins at two), the width',
    '      caps (three shoulders at the',
    '      standard door, one at a narrow), the',
    '      wood-break full turn with its three',
    '      noise checks and the knock-only metal',
    '      door (the band, the halves and the',
    '      break lane stay data - no site). The',
    '      site: [O] in the dungeon spends the',
    '      turn and puts up to three living',
    '      members on the adjacent lock - each',
    '      rolls the d6 against the parentheticals',
    '      (the wrench once ever per door), or',
    '      the simultaneous 1s tear the lock out.',
    '      The R305a battery audit walks the',
    '      forcing pins and their folds',
    '      (evaluable - verified by audit_eval);',
    '      the R305 engine audit pins every',
    '      scenario on seeded sequences (the',
    '      replica walked the draws first).',
    '      Census 229. The ledger',
    '      holds ZERO open items.',
])
GR_INS_NEW = NL.join([
    '      the draws first). Census 227. The',
    '      ledger holds ZERO open items.',
    '',
    GR_BOX,
    '',
    '## R299 the party recordings round (the third',
])
for t in (GR153_OLD, GR153_NEW, GR_INS_OLD, GR_BOX, GR_INS_NEW):
    clean(t, 57)

p = 'tools/phb_gap_report.md'
s = rd(p)
if 'The locked door forced' in s:
    already.append('phb_gap_report.md: the head + the box')
else:
    assert s.count(GR153_OLD) == 1, 'gr head anchor not unique'
    assert s.count(GR_INS_OLD) == 1, 'gr insert anchor not unique'
    assert 'Census 229.' not in s, 'gr marker collision'
    s = s.replace(GR153_OLD, GR153_NEW)
    s = s.replace(GR_INS_OLD, GR_INS_NEW)
    wr(p, s)
    applied.append('phb_gap_report.md: the head + the box')
s = rd(p)
assert s.count('The locked door forced') == 1, 'patch f box'
assert s.count('WIRED R305') == 1, 'patch f wired note'
assert s.count('holds ZERO open items') == 5, 'patch f zero notes'
assert s.count('Census 229.') == 1, 'patch f census note'
assert s.count('Census 227.') == 1, 'patch f r304 census'
assert s.count('Census 225.') == 1, 'patch f r303 census'
assert s.count('Census 223.') == 1, 'patch f r302 census'
assert 'Census 221.' in s, 'patch f ate the R301 census'
assert 'Census 215.' in s, 'patch f ate the R298 census'
assert 'PINNED R298' in s, 'patch f ate the R298 box head'
assert 'The thief locks wired' in s, 'patch f ate the R304 box'
assert 'The thief pockets wired' in s, 'patch f ate the R303 box'
assert '## R299 the party recordings round' in s, 'patch f ate the head'
assert s.count('- [ ]') == 0, 'patch f opened an item'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- (g) tools/dmg_gap_report.md: the chronicle ----
DMG_OLD = NL.join([
    'carries the round box; the battery',
    'census moves 225 -> 227).',
    '',
    'Categories:',
])
DMG_NEW = NL.join([
    'carries the round box; the battery',
    'census moves 225 -> 227).',
    '',
    'R305 PINNED the DMG FIRST DUNGEON ADVENTURE',
    'forcing prose: rules/doorforce.h, the',
    'grenade.h pattern - the typical 1-2 d6',
    'band, the very-heavy halves, the',
    'simultaneous-1s locked rule (the print',
    'reads two or even three - the JUDGMENT',
    'pins at two), the width caps (three at',
    'the standard door, one at a narrow), the',
    'wood-break full turn with its three noise',
    'checks, and the knock-only metal door.',
    'The PHB STR Table II open-doors',
    'parentheticals wire at the R304 locked',
    'door (the phb report carries the round',
    'box; the battery census moves 227 -> 229).',
    '',
    'Categories:',
])
for t in (DMG_OLD, DMG_NEW):
    clean(t, 57)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R305 PINNED the DMG FIRST DUNGEON' in s:
    already.append('dmg_gap_report.md: the chronicle')
else:
    assert s.count(DMG_OLD) == 1, 'dmg anchor not unique'
    s = s.replace(DMG_OLD, DMG_NEW)
    wr(p, s)
    applied.append('dmg_gap_report.md: the chronicle')
s = rd(p)
assert s.count('R305 PINNED the DMG FIRST DUNGEON') == 1, 'patch g note'
assert s.count('Categories:') == 1, 'patch g legend head'
assert s.count('R304 PINNED the DMG THIEF ABILITIES') == 1, \
    'patch g r304 chronicle'
assert s.count('- [ ]') == 1, 'patch g checkbox count'
assert 'battery census stays 213.' in s, 'patch g ate the R296 tail'
assert len(applied) + len(already) == 7, 'patch g count wrong'

# ---- R305 fails/tail ----
if fails:
    print('R305 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 7:
    print('R305 splice: FAIL - expected 7 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R305 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R305 note: 7 patches; the battery census 227 -> 229;')
print('the phb ledger holds ZERO open items')
print('commit: R305: the locked door forced (census 229)')

