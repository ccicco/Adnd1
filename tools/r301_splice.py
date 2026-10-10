#!/usr/bin/env python3
# tools/r301_splice.py - R301: the thief trap
# rolls wired (the R299 standing successor; the
# R227 wiring-arc precedent).
#
# The R298 pin round left the thfChanceTenths
# seam with zero callers, and the R45 trap
# function springTrap has NEVER HAD A CALLER
# - the dungeon traps never sprang. This
# round wires both:
#
#   (a) rules/thieffunc.h - the percentile
#       seam: thfPercentileSucceeds (the
#       printed equal-or-less convention on
#       the tenths band) and thfAttemptSucceeds
#       (the folded attempt); the DATA-ONLY
#       comments amended.
#   (b) game/state_dungeon.cpp - springTrap
#       rolls the printed find/remove traps
#       chances (two separate percentile
#       draws, locate first, remove second,
#       one try each; the flat 1-in-3
#       retired) and the new checkTrapOnEntry
#       (the movement wire).
#   (c) game/appstate.h - the declaration.
#   (d) adnd1.cpp - the shell step calls
#       checkTrapOnEntry (one line - the MSVC
#       backlog, like every shell wire).
#   (e) regtest.cpp - the R301 audit pair
#       (the battery census 219 -> 221): the
#       R301a seam audit walks the percentile
#       boundary and the folded chances
#       (evaluable - verified by audit_eval)
#       and the R301 engine audit drives every
#       springTrap branch live on seeded
#       xorshift sequences.
#   (f) tools/preflight.sh - the battery build
#       now LINKS game/*.cpp and
#       monsters/MonsterXp.cpp (the engine
#       audit calls live AppState methods);
#       the lean syntax gate keeps the
#       complement (ai/, spelleffects/,
#       treasuresim.cpp).
#   (g) tools/phb_gap_report.md - the wiring
#       arc box (the R298 box amended; the
#       ledger holds ZERO open items).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY patch
# (the R142 lesson). ZERO literal backslash
# bytes in this file (the audit printf newline
# builds via BS), and no CONTENT string embeds
# an apostrophe, non-ASCII or (for the gap
# report) a line past 57 columns (the one
# exception: the byte-exact R125 book-name
# comment anchor in state_dungeon.cpp, built
# via chr(39), never a literal).
# Commit: "R301: the thief trap rolls wired
# (census 221)"
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
    # allow_apos: the byte-exact R125 book-name comment
    # anchor in state_dungeon.cpp embeds the one
    # apostrophe of the patched region (built via
    # chr(39), never a literal in this file)
    if not allow_apos:
        assert chr(39) not in s, 'apostrophe in content'
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

# ---- (a) rules/thieffunc.h: the seam wired ----
TF_TOP_OLD = NL.join([
    '// (upload line 400) - a DATA-ONLY pin (the',
    '// R186 poetics precedent): the engine',
    '// performs no thief rolls; the tables, the',
    '// walkers and the adjusted-chance seam are',
    '// data for the future roll round.',
])
TF_TOP_NEW = NL.join([
    '// (upload line 400) - a DATA-ONLY pin (the',
    '// R186 poetics precedent), WIRED R301: the',
    '// find/remove traps rolls now run at the',
    '// trap site (the thfAttemptSucceeds seam);',
    '// the other functions wait for engine sites',
    '// that do not exist yet.',
])
TF_SEAM_OLD = NL.join([
    '    // the adjusted chance seam: the printed',
    '    // base plus the racial and dexterity',
    '    // adjustments (the printed notes: the',
    '    // adjustments are additional pluses; a',
    '    // percentile roll at or below the chance',
    '    // succeeds). DATA-ONLY - nothing calls',
    '    // this seam yet (the engine performs no',
    '    // thief rolls; a future round wires them)',
])
TF_SEAM_NEW = NL.join([
    '    // the adjusted chance seam: the printed',
    '    // base plus the racial and dexterity',
    '    // adjustments (the printed notes: the',
    '    // adjustments are additional pluses; a',
    '    // percentile roll at or below the chance',
    '    // succeeds). R301: the trap site rolls',
    '    // this seam (the find and the remove',
    '    // draws); the other functions stay data',
])
TF_TAIL_OLD = NL.join([
    'inline int thfNoteRacialAdditional() {',
    '    // the racial adjustments are additional',
    '    // pluses on the adjusted base',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
])
TF_TAIL_NEW = NL.join([
    'inline int thfNoteRacialAdditional() {',
    '    // the racial adjustments are additional',
    '    // pluses on the adjusted base',
    '    return 1;',
    '}',
    '',
    '// R301: the printed percentile roll - a score',
    '// equal to or less than the chance succeeds.',
    '// The engine draws the roll in TENTHS on the',
    '// 0-999 band (0.0 through 99.9 percent); the',
    '// boundary reads strict less-than, so a',
    '// printed whole-percent chance keeps its',
    '// exact printed odds (a 20 percent chance owns',
    '// exactly 200 of the 1000 draws) and the',
    '// printed climb walls decimal reads true',
    '// (99.1 percent owns 991). JUDGMENT: the',
    '// book rolls two percentile dice on a 1-100',
    '// scale; the tenths band is the same',
    '// distribution at the printed resolution.',
    'inline bool thfPercentileSucceeds(int rollTenths,',
    '                                  int chanceTenths) {',
    '    return rollTenths < chanceTenths;',
    '}',
    '',
    '// R301: one printed attempt - the percentile',
    '// draw against the adjusted chance. The trap',
    '// site (the find roll and the remove roll)',
    '// reads this seam; one try each, the print.',
    'inline bool thfAttemptSucceeds(int rollTenths, int fn,',
    '                               int level, int race,',
    '                               int dex) {',
    '    return thfPercentileSucceeds(',
    '        rollTenths,',
    '        thfChanceTenths(fn, level, race, dex));',
    '}',
    '',
    '}  // namespace rules',
])
clean(TF_TOP_OLD, 78); clean(TF_TOP_NEW, 78)
clean(TF_SEAM_OLD, 78); clean(TF_SEAM_NEW, 78)
clean(TF_TAIL_OLD, 78); clean(TF_TAIL_NEW, 78)

p = 'rules/thieffunc.h'
s = rd(p)
if 'thfAttemptSucceeds' in s:
    already.append('thieffunc.h: the seam wired')
else:
    assert s.count(TF_TOP_OLD) == 1, 'tf top anchor not unique'
    assert s.count(TF_SEAM_OLD) == 1, 'tf seam anchor not unique'
    assert s.count(TF_TAIL_OLD) == 1, 'tf tail anchor not unique'
    s = s.replace(TF_TOP_OLD, TF_TOP_NEW)
    s = s.replace(TF_SEAM_OLD, TF_SEAM_NEW)
    s = s.replace(TF_TAIL_OLD, TF_TAIL_NEW)
    wr(p, s)
    applied.append('thieffunc.h: the seam wired')
s = rd(p)
assert 'thfAttemptSucceeds' in s, 'patch a failed'
assert s.count('inline bool thf') == 2, 'patch a helper count'
assert 'DATA-ONLY - nothing calls' not in s, 'patch a stale seam note'
assert 'a future round wires them' not in s, 'patch a stale top note'
assert 'WIRED R301' in s, 'patch a wired note'
assert s.count('}  // namespace rules') == 1, 'patch a namespace close'
assert 'thfTakeTenths' in s and 'thfNotePocketsNoticeBand' in s, 'patch a ate a pin'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) game/state_dungeon.cpp: the rolls + the wire ----
SD_INC_OLD = NL.join([
    '#include "appstate.h"',
    '#include "abilities/abilities.h"   // R120: listening (p.60)',
])
SD_INC_NEW = NL.join([
    '#include "appstate.h"',
    '#include "abilities/abilities.h"   // R120: listening (p.60)',
    '#include "rules/thieffunc.h"   // R301: the thief trap rolls',
])
SD_HEAD_OLD = NL.join([
    '// ---- springTrap ----',
    'void AppState::springTrap(int roomIndex){',
])
SD_HEAD_NEW = NL.join([
    '// ---- springTrap ----',
    '// R301: the printed thief rolls - the R298',
    '// find/remove traps chances decide the',
    '// disarm (two percentile draws at or below',
    '// the adjusted chance; locate first, remove',
    '// second, one try each). The strike (save',
    '// vs death, 2d6) stays the R45 effect.',
    'void AppState::springTrap(int roomIndex){',
])
SD_LOOP_OLD = NL.join([
    '        for (const auto& c : party.members) {',
    '            if (c.hp <= 0 || c.classIndex != 3) continue;',
    '            if (rng.below(3) == 0) {',
    '                room.trap = 2;',
    '                // R125: the book' + chr(39) + 's name for the snare',
    '                log.add(c.name + " spots the trap (" +',
    '                        dm::appendixg::trapName(room.trapKind) +',
    '                        ") and disarms it.");',
    '                return;',
    '            }',
    '            break;   // one thief attempt per trap',
    '        }',
])
SD_LOOP_NEW = NL.join([
    '        for (const auto& c : party.members) {',
    '            if (c.hp <= 0 || c.classIndex != 3) continue;',
    '            // R301: the printed find roll - percentile',
    '            // dice at or below the adjusted find/remove',
    '            // traps chance (the R298 tables; the draw',
    '            // runs in tenths, rules/thieffunc.h)',
    '            int find = (int)rng.below(1000);',
    '            if (!rules::thfAttemptSucceeds(find,',
    '                    rules::THF_TRAPS, c.level,',
    '                    c.race, (int)c.abilities.dex))',
    '                break;   // one thief attempt per trap',
    '            // the printed remove roll: separate, one try',
    '            int remove = (int)rng.below(1000);',
    '            if (rules::thfAttemptSucceeds(remove,',
    '                    rules::THF_TRAPS, c.level,',
    '                    c.race, (int)c.abilities.dex)) {',
    '                room.trap = 2;',
    '                // R125: the book' + chr(39) + 's name for the snare',
    '                log.add(c.name + " spots the trap (" +',
    '                        dm::appendixg::trapName(room.trapKind) +',
    '                        ") and disarms it.");',
    '                return;',
    '            }',
    '            // located but not removed - it fires anyway',
    '            log.add(c.name + " spots the trap (" +',
    '                    dm::appendixg::trapName(room.trapKind) +',
    '                    ") - too late to disarm it!");',
    '            break;   // one try each, the print',
    '        }',
])
SD_WIRE_OLD = NL.join([
    '        log.add(buf);',
    '        if (!party.alive()) {',
    '            log.add("GAME OVER - press N to roll a new party.");',
    '        }',
    '    }',
    '',
    '// ---- engageTrick ----',
])
SD_WIRE_NEW = NL.join([
    '        log.add(buf);',
    '        if (!party.alive()) {',
    '            log.add("GAME OVER - press N to roll a new party.");',
    '        }',
    '    }',
    '',
    '// ---- checkTrapOnEntry ----',
    '// R301: the movement wire - the R45 springTrap',
    '// built the snare but nothing called it. The',
    '// shell step handler calls this on every step;',
    '// an armed trap in the chamber the company',
    '// stands in springs. The mode gate and the',
    '// location read live here so the battery can',
    '// drive the whole path.',
    'void AppState::checkTrapOnEntry(){',
    '        if (mode != MODE_EXPLORE) return;',
    '        int tr = trapRoomNear(party.x, party.y);',
    '        if (tr < 0) return;',
    '        springTrap(tr);',
    '    }',
    '',
    '// ---- engageTrick ----',
])
for t in (SD_INC_OLD, SD_INC_NEW, SD_HEAD_OLD, SD_HEAD_NEW,
          SD_WIRE_OLD, SD_WIRE_NEW):
    clean(t, 78)
clean(SD_LOOP_OLD, 78, True)
clean(SD_LOOP_NEW, 78, True)

p = 'game/state_dungeon.cpp'
s = rd(p)
if 'checkTrapOnEntry' in s:
    already.append('state_dungeon.cpp: the rolls + the wire')
else:
    assert s.count(SD_INC_OLD) == 1, 'sd include anchor not unique'
    assert s.count(SD_HEAD_OLD) == 1, 'sd head anchor not unique'
    assert s.count(SD_LOOP_OLD) == 1, 'sd loop anchor not unique'
    assert s.count(SD_WIRE_OLD) == 1, 'sd wire anchor not unique'
    assert 'rng.below(3)' in s, 'sd flat roll missing (anchor drift)'
    s = s.replace(SD_INC_OLD, SD_INC_NEW)
    s = s.replace(SD_HEAD_OLD, SD_HEAD_NEW)
    s = s.replace(SD_LOOP_OLD, SD_LOOP_NEW)
    s = s.replace(SD_WIRE_OLD, SD_WIRE_NEW)
    wr(p, s)
    applied.append('state_dungeon.cpp: the rolls + the wire')
s = rd(p)
assert 'checkTrapOnEntry' in s, 'patch b failed'
assert 'rng.below(3)' not in s, 'patch b left the flat roll'
assert s.count('thfAttemptSucceeds') == 2, 'patch b seam calls'
assert 'too late to disarm it' in s, 'patch b late line'
assert 'R120: listening' in s, 'patch b ate the R120 include'
assert '// ---- engageTrick ----' in s, 'patch b ate engageTrick'
assert 'GAME OVER - press N' in s, 'patch b ate the game over line'
assert 'void AppState::checkTrapOnEntry()' in s, 'patch b method'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) game/appstate.h: the declaration ----
AH_OLD = NL.join([
    '    // R45: spring the dart trap in a room. A thief in the',
    '    // company may spot and disarm it first (1-in-3, the',
    '    // find/remove-trades instinct - simplified); otherwise a',
    '    // random living member saves vs death or eats 2d6.',
    '    void springTrap(int roomIndex);',
])
AH_NEW = NL.join([
    '    // R45: spring the dart trap in a room. R301: a thief',
    '    // in the company rolls the printed find/remove traps',
    '    // chances first (two percentile draws at or below the',
    '    // adjusted chance - locate, then remove, one try',
    '    // each); otherwise a random living member saves vs',
    '    // death or eats 2d6.',
    '    void springTrap(int roomIndex);',
    '',
    '    // R301: the movement wire - the shell step calls',
    '    // this; an armed trap in the chamber the company',
    '    // stands in springs (springTrap gains its first',
    '    // caller).',
    '    void checkTrapOnEntry();',
])
clean(AH_OLD, 78); clean(AH_NEW, 78)

p = 'game/appstate.h'
s = rd(p)
if 'void checkTrapOnEntry();' in s:
    already.append('appstate.h: the declaration')
else:
    assert s.count(AH_OLD) == 1, 'ah anchor not unique'
    s = s.replace(AH_OLD, AH_NEW)
    wr(p, s)
    applied.append('appstate.h: the declaration')
s = rd(p)
assert s.count('void checkTrapOnEntry();') == 1, 'patch c failed'
assert 'trapRoomNear(int px, int py, int radius = 0) const;' in s, 'patch c ate the near decl'
assert 'void springTrap(int roomIndex);' in s, 'patch c ate the spring decl'
assert 'find/remove-trades' not in s, 'patch c stale comment'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) adnd1.cpp: the shell step wire ----
AD_OLD = NL.join([
    '    // R46: describe a room the first time the party steps into it',
    '    {',
    '        int fl = s.roomAt(s.party.x, s.party.y);',
    '        if (fl >= 0) s.describeRoom(fl);',
    '    }',
    '',
    '    int roomIdx = s.occupiedRoomNear(s.party.x, s.party.y);',
])
AD_NEW = NL.join([
    '    // R46: describe a room the first time the party steps into it',
    '    {',
    '        int fl = s.roomAt(s.party.x, s.party.y);',
    '        if (fl >= 0) s.describeRoom(fl);',
    '    }',
    '',
    '    // R301: an armed trap springs when the company steps in',
    '    s.checkTrapOnEntry();',
    '',
    '    int roomIdx = s.occupiedRoomNear(s.party.x, s.party.y);',
])
clean(AD_OLD, 78); clean(AD_NEW, 78)

p = 'adnd1.cpp'
s = rd(p)
if 's.checkTrapOnEntry();' in s:
    already.append('adnd1.cpp: the shell step wire')
else:
    assert s.count(AD_OLD) == 1, 'ad anchor not unique'
    s = s.replace(AD_OLD, AD_NEW)
    wr(p, s)
    applied.append('adnd1.cpp: the shell step wire')
s = rd(p)
assert s.count('s.checkTrapOnEntry();') == 1, 'patch d failed'
assert 'if (fl >= 0) s.describeRoom(fl);' in s, 'patch d ate the R46 wire'
assert 's.occupiedRoomNear(s.party.x, s.party.y);' in s, 'patch d ate the occupied check'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) regtest.cpp: the R301 audit pair ----
RT_OLD = NL.join([
    '        printf("R300 equipment costs engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_NEW_HEAD = NL.join([
    '        printf("R300 equipment costs engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_R301A = NL.join([
    '    // ---- R301a: the thief percentile seam audit ----',
    '    // The R298 seam gains its first callers this',
    '    // round; this walk pins the boundary convention',
    '    // (a score equal to or less than the chance',
    '    // succeeds - the strict less-than keeps a',
    '    // whole-percent chance owning its exact',
    '    // thousandth of the band, and the printed 99.1',
    '    // climb walls decimal reads true) and the fold',
    '    // against the R298 tables (the grenade.h',
    '    // pattern - verified by audit_eval). The race',
    '    // is a plain int: the parser reads no',
    '    // underlying-type enums (0 human, 1 dwarf,',
    '    // 1 elf, 4 half-elf, 5 halfling).',
    '    {',
    '        int bad = 0;',
    '        // the printed percentile convention on the',
    '        // 0-999 tenths band',
    '        if (!rules::thfPercentileSucceeds(199, 200) ||',
    '            rules::thfPercentileSucceeds(200, 200) ||',
    '            !rules::thfPercentileSucceeds(990, 991) ||',
    '            rules::thfPercentileSucceeds(991, 991) ||',
    '            rules::thfPercentileSucceeds(0, 0) ||',
    '            !rules::thfPercentileSucceeds(999, 1000)) ++bad;',
    '        // find/remove traps level 1 human dex 9',
    '        // prints 10 percent (100 tenths)',
    '        if (!rules::thfAttemptSucceeds(99,',
    '                rules::THF_TRAPS, 1, 0, 9) ||',
    '            rules::thfAttemptSucceeds(100,',
    '                rules::THF_TRAPS, 1, 0, 9)) ++bad;',
    '        // find/remove traps level 4 dwarf dex 13',
    '        // prints 50 percent (500 tenths)',
    '        if (!rules::thfAttemptSucceeds(499,',
    '                rules::THF_TRAPS, 4, 1, 13) ||',
    '            rules::thfAttemptSucceeds(500,',
    '                rules::THF_TRAPS, 4, 1, 13)) ++bad;',
    '        // pick pockets level 1 halfling dex 13',
    '        // prints 35 percent (350 tenths)',
    '        if (!rules::thfAttemptSucceeds(349,',
    '                rules::THF_PICK_POCKETS, 1, 5, 13) ||',
    '            rules::thfAttemptSucceeds(350,',
    '                rules::THF_PICK_POCKETS, 1, 5, 13)) ++bad;',
    '        // pick pockets level 12 half-elf dex 16',
    '        // prints 110 percent (1100 - every draw of',
    '        // the band succeeds)',
    '        if (!rules::thfAttemptSucceeds(999,',
    '                rules::THF_PICK_POCKETS, 12, 4, 16)) ++bad;',
    '        // climb walls level 11 human dex 18 prints',
    '        // 99.1 percent (991 tenths)',
    '        if (!rules::thfAttemptSucceeds(990,',
    '                rules::THF_CLIMB_WALLS, 11, 0, 18) ||',
    '            rules::thfAttemptSucceeds(991,',
    '                rules::THF_CLIMB_WALLS, 11, 0, 18)) ++bad;',
    '        // hear noise level 1 human dex 18 prints',
    '        // 10 percent (the no-DEX column reads 0)',
    '        if (!rules::thfAttemptSucceeds(99,',
    '                rules::THF_HEAR_NOISE, 1, 0, 18) ||',
    '            rules::thfAttemptSucceeds(100,',
    '                rules::THF_HEAR_NOISE, 1, 0, 18)) ++bad;',
    '        // read languages level 2 elf dex 18 prints',
    '        // the dash (0 - no roll succeeds)',
    '        if (rules::thfAttemptSucceeds(0,',
    '                rules::THF_READ_LANGUAGES, 2, 1, 18)) ++bad;',
    '        printf("R301a thief percentile seam audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_R301 = NL.join([
    '    // ---- R301: the thief trap rolls engine audit ----',
    '    // The engine audit (the R300/R299 precedent -',
    '    // the C++ battery is the gate; audit_eval reads',
    '    // no engine objects): the seeded rng drives',
    '    // every springTrap branch - the fighter-only',
    '    // strike, the find-and-remove disarm, the',
    '    // too-late strike with the saving victim, the',
    '    // failed find with the multi-member victim',
    '    // pick, the dead-thief skip - and the',
    '    // checkTrapOnEntry wire (the bounds guard,',
    '    // the outside no-op, the in-room spring, the',
    '    // sprung no-op and the MODE_TOWN gate). Every',
    '    // draw sequence was replicated seed-for-seed',
    '    // before the splice was written (the',
    '    // xorshift64* replica; the party formed flag',
    '    // rides every scenario - alive() reads it).',
    '    {',
    '        int bad = 0;',
    '        // the fighter-only strike - seed 1 saves 6',
    '        // (fails the level-1 death 14) and strikes 8:',
    '        // the 30 hit points read 22',
    '        {',
    '            AppState st;',
    '            st.occupancy.rooms.resize(1);',
    '            st.occupancy.rooms[0].roomIndex = 0;',
    '            st.occupancy.rooms[0].trap = 1;',
    '            st.occupancy.rooms[0].trapKind = 0;',
    '            Character f;',
    '            f.name = "Fighter";',
    '            f.classIndex = 0; f.level = 1;',
    '            f.hp = 30; f.maxHp = 30;',
    '            st.party.members.push_back(f);',
    '            st.party.formed = true;',
    '            st.rng.seed(1);',
    '            st.springTrap(0);',
    '            if (st.party.members[0].hp != 22) ++bad;',
    '            if (st.occupancy.rooms[0].trap != 2) ++bad;',
    '            if (st.log.get(0).find("strikes Fighter")',
    '                == std::string::npos) ++bad;',
    '        }',
    '        // the disarm - seed 33 draws the find 21 and',
    '        // the remove 95, both at or below the 100',
    '        // tenths chance (level 1 human dex 9)',
    '        {',
    '            AppState st;',
    '            st.occupancy.rooms.resize(1);',
    '            st.occupancy.rooms[0].roomIndex = 0;',
    '            st.occupancy.rooms[0].trap = 1;',
    '            st.occupancy.rooms[0].trapKind = 0;',
    '            Character t;',
    '            t.name = "Thief";',
    '            t.classIndex = 3; t.level = 1;',
    '            t.hp = 30; t.maxHp = 30;',
    '            t.abilities.dex = 9;',
    '            st.party.members.push_back(t);',
    '            st.party.formed = true;',
    '            st.rng.seed(33);',
    '            st.springTrap(0);',
    '            if (st.party.members[0].hp != 30) ++bad;',
    '            if (st.occupancy.rooms[0].trap != 2) ++bad;',
    '            if (st.log.get(0).find("and disarms it")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(0).find("A trap!")',
    '                != std::string::npos) ++bad;',
    '        }',
    '        // the too-late strike - seed 13 finds 14 but',
    '        // draws the remove 614; the thief saves (17',
    '        // against the level-1 death 13)',
    '        {',
    '            AppState st;',
    '            st.occupancy.rooms.resize(1);',
    '            st.occupancy.rooms[0].roomIndex = 0;',
    '            st.occupancy.rooms[0].trap = 1;',
    '            st.occupancy.rooms[0].trapKind = 0;',
    '            Character t;',
    '            t.name = "Thief";',
    '            t.classIndex = 3; t.level = 1;',
    '            t.hp = 30; t.maxHp = 30;',
    '            t.abilities.dex = 9;',
    '            st.party.members.push_back(t);',
    '            st.party.formed = true;',
    '            st.rng.seed(13);',
    '            st.springTrap(0);',
    '            if (st.party.members[0].hp != 30) ++bad;',
    '            if (st.occupancy.rooms[0].trap != 2) ++bad;',
    '            if (st.log.get(0).find("saved!")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(1).find("too late")',
    '                == std::string::npos) ++bad;',
    '        }',
    '        // the failed find - seed 1 draws the find 165',
    '        // (above the 100); the victim pick lands on',
    '        // the fighter, the save 4 fails and the',
    '        // strike reads 7',
    '        {',
    '            AppState st;',
    '            st.occupancy.rooms.resize(1);',
    '            st.occupancy.rooms[0].roomIndex = 0;',
    '            st.occupancy.rooms[0].trap = 1;',
    '            st.occupancy.rooms[0].trapKind = 0;',
    '            Character t;',
    '            t.name = "Thief";',
    '            t.classIndex = 3; t.level = 1;',
    '            t.hp = 30; t.maxHp = 30;',
    '            t.abilities.dex = 9;',
    '            st.party.members.push_back(t);',
    '            Character f;',
    '            f.name = "Fighter";',
    '            f.classIndex = 0; f.level = 1;',
    '            f.hp = 30; f.maxHp = 30;',
    '            st.party.members.push_back(f);',
    '            st.party.formed = true;',
    '            st.rng.seed(1);',
    '            st.springTrap(0);',
    '            if (st.party.members[0].hp != 30) ++bad;',
    '            if (st.party.members[1].hp != 23) ++bad;',
    '            if (st.occupancy.rooms[0].trap != 2) ++bad;',
    '            if (st.log.get(0).find("strikes Fighter for 7")',
    '                == std::string::npos) ++bad;',
    '            if (st.log.get(0).find("spots the trap")',
    '                != std::string::npos) ++bad;',
    '        }',
    '        // the dead-thief skip - a dead thief draws',
    '        // nothing (the hp gate); the fighter takes',
    '        // the seed-1 strike (22)',
    '        {',
    '            AppState st;',
    '            st.occupancy.rooms.resize(1);',
    '            st.occupancy.rooms[0].roomIndex = 0;',
    '            st.occupancy.rooms[0].trap = 1;',
    '            st.occupancy.rooms[0].trapKind = 0;',
    '            Character t;',
    '            t.name = "Thief";',
    '            t.classIndex = 3; t.level = 1;',
    '            t.hp = 0; t.maxHp = 30;',
    '            t.abilities.dex = 9;',
    '            st.party.members.push_back(t);',
    '            Character f;',
    '            f.name = "Fighter";',
    '            f.classIndex = 0; f.level = 1;',
    '            f.hp = 30; f.maxHp = 30;',
    '            st.party.members.push_back(f);',
    '            st.party.formed = true;',
    '            st.rng.seed(1);',
    '            st.springTrap(0);',
    '            if (st.party.members[0].hp != 0) ++bad;',
    '            if (st.party.members[1].hp != 22) ++bad;',
    '            if (st.log.get(0).find("strikes Fighter")',
    '                == std::string::npos) ++bad;',
    '        }',
    '        // the entry wire - the bounds guard holds',
    '        // (the trap stays armed), the party outside',
    '        // the room reads no trap, the step into the',
    '        // chamber springs it, the sprung room is a',
    '        // no-op and the MODE_TOWN gate holds after',
    '        // a re-arm',
    '        {',
    '            AppState st;',
    '            st.mode = MODE_EXPLORE;',
    '            st.dungeon.rooms.push_back(',
    '                dm::GeneratedRoom{10, 10, 3, 3,',
    '                                   dm::ROOM_EMPTY});',
    '            st.occupancy.rooms.resize(1);',
    '            st.occupancy.rooms[0].roomIndex = 0;',
    '            st.occupancy.rooms[0].trap = 1;',
    '            st.occupancy.rooms[0].trapKind = 0;',
    '            Character f;',
    '            f.name = "Fighter";',
    '            f.classIndex = 0; f.level = 1;',
    '            f.hp = 30; f.maxHp = 30;',
    '            st.party.members.push_back(f);',
    '            st.party.formed = true;',
    '            st.rng.seed(1);',
    '            st.springTrap(-1);',
    '            st.springTrap(99);',
    '            if (st.occupancy.rooms[0].trap != 1) ++bad;',
    '            if (!st.log.get(0).empty()) ++bad;',
    '            st.party.x = 5; st.party.y = 5;',
    '            st.checkTrapOnEntry();',
    '            if (st.occupancy.rooms[0].trap != 1) ++bad;',
    '            if (st.party.members[0].hp != 30) ++bad;',
    '            st.party.x = 11; st.party.y = 11;',
    '            st.checkTrapOnEntry();',
    '            if (st.party.members[0].hp != 22) ++bad;',
    '            if (st.occupancy.rooms[0].trap != 2) ++bad;',
    '            std::string snap = st.log.get(0);',
    '            if (snap.find("strikes Fighter")',
    '                == std::string::npos) ++bad;',
    '            st.checkTrapOnEntry();',
    '            if (st.party.members[0].hp != 22) ++bad;',
    '            if (st.log.get(0) != snap) ++bad;',
    '            st.occupancy.rooms[0].trap = 1;',
    '            st.mode = MODE_TOWN;',
    '            st.checkTrapOnEntry();',
    '            if (st.occupancy.rooms[0].trap != 1) ++bad;',
    '            if (st.party.members[0].hp != 22) ++bad;',
    '            if (st.log.get(0) != snap) ++bad;',
    '        }',
    '        printf("R301 thief trap rolls engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_NEW = NL.join([RT_NEW_HEAD, RT_R301A, RT_R301,
                  '    // ---- R227: the wis mental save wiring audit ----'])
# the audit blocks carry the printf newline (BS) - the
# R300 check: BS lives ONLY on the printf lines, one
# per line, and nothing else carries a backslash
for t in (RT_OLD, RT_NEW_HEAD, RT_R301A, RT_R301):
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
if 'R301 thief trap rolls engine audit' in s:
    already.append('regtest.cpp: the R301 audit pair')
else:
    assert s.count('audit: bad') == 219, 'rt census not 219'
    assert s.count(RT_OLD) == 1, 'rt anchor not unique'
    s = s.replace(RT_OLD, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the R301 audit pair')
s = rd(p)
assert s.count('audit: bad') == 221, 'patch e census wrong'
assert s.count('R301a thief percentile seam audit') == 1, 'patch e R301a marker'
assert s.count('R301 thief trap rolls engine audit') == 1, 'patch e R301 marker'
assert s.count('R301: the thief trap rolls engine audit') == 1, 'patch e comment head'
assert s.count('R227: the wis mental save wiring audit') == 1, 'patch e ate R227'
assert s.count('R300 equipment costs engine audit') == 1, 'patch e ate R300'
assert 'R299a party kit recordings seam audit' in s, 'patch e ate R299a'
assert 'R299 party kit recordings engine audit' in s, 'patch e ate R299'
assert s.count('thfPercentileSucceeds(199, 200)') == 1, 'patch e boundary probe'
assert s.count('AppState st;') == 6, 'patch e scenario count'
assert 'springTrap(-1);' in s, 'patch e bounds probe'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) tools/preflight.sh: the build + the gate ----
PF_CMT_OLD = NL.join([
    '# adnd1.cpp stays skipped: the Win32/GDI shell needs',
    '# windows.h (MSVC verify pending, backlog).',
])
PF_CMT_NEW = NL.join([
    '# adnd1.cpp stays skipped: the Win32/GDI shell needs',
    '# windows.h (MSVC verify pending, backlog).',
    '# R301: the engine audit drives live AppState',
    '# methods, so the battery build below now compiles',
    '# every game/*.cpp state TU and links',
    '# monsters/MonsterXp.cpp (xpForKill feeds',
    '# state_dungeon.cpp). The complement gate drops',
    '# game/*.cpp and MonsterXp.cpp from its loop (the',
    '# R107 NEW COVERAGE note above is the pre-R301',
    '# history); every TU still compiles exactly once.',
])
PF_LOOP_OLD = NL.join([
    'for f in game/*.cpp ai/*.cpp spelleffects/*.cpp ' + BS,
    '         monsters/MonsterXp.cpp treasuresim.cpp; do',
])
PF_LOOP_NEW = NL.join([
    'for f in ai/*.cpp spelleffects/*.cpp ' + BS,
    '         treasuresim.cpp; do',
])
PF_BUILD_OLD = NL.join([
    '  abilities/abilities.cpp items/items.cpp ai/actor.cpp ' + BS,
    '  spelleffects/spelleffects.cpp regtest.cpp ' + BS,
])
PF_BUILD_NEW = NL.join([
    '  abilities/abilities.cpp items/items.cpp ai/actor.cpp ' + BS,
    '  game/state_core.cpp game/state_dungeon.cpp ' + BS,
    '  game/state_combat.cpp game/state_town.cpp ' + BS,
    '  game/state_overland.cpp game/state_sea.cpp ' + BS,
    '  monsters/MonsterXp.cpp ' + BS,
    '  spelleffects/spelleffects.cpp regtest.cpp ' + BS,
])
# the preflight strings carry bash continuations (BS) -
# BS lives ONLY at end-of-line, one per line
def cleanbs(s, limit):
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii in pf'
        assert len(ln) <= limit, 'pf line too long: ' + ln
        assert chr(39) not in ln, 'apostrophe in pf'
        if ln.endswith(BS):
            assert ln.count(BS) == 1, 'pf double BS'
        else:
            assert BS not in ln, 'stray BS in pf'

for t in (PF_CMT_OLD, PF_CMT_NEW, PF_LOOP_OLD, PF_LOOP_NEW,
          PF_BUILD_OLD, PF_BUILD_NEW):
    cleanbs(t, 74)

p = 'tools/preflight.sh'
s = rd(p)
if 'R301: the engine audit drives live' in s:
    already.append('preflight.sh: the build + the gate')
else:
    assert s.count(PF_CMT_OLD) == 1, 'pf comment anchor not unique'
    assert s.count(PF_LOOP_OLD) == 1, 'pf loop anchor not unique'
    assert s.count(PF_BUILD_OLD) == 1, 'pf build anchor not unique'
    s = s.replace(PF_CMT_OLD, PF_CMT_NEW)
    s = s.replace(PF_LOOP_OLD, PF_LOOP_NEW)
    s = s.replace(PF_BUILD_OLD, PF_BUILD_NEW)
    wr(p, s)
    applied.append('preflight.sh: the build + the gate')
s = rd(p)
assert s.count('game/state_dungeon.cpp ' + BS) == 1, 'patch f build line'
assert s.count('for f in ai/*.cpp spelleffects/*.cpp ' + BS) == 1, 'patch f loop line'
assert 'for f in game/*.cpp' not in s, 'patch f left game in the loop'
assert 'monsters/MonsterXp.cpp treasuresim.cpp' not in s, 'patch f left the old loop line'
assert s.count('spelleffects/spelleffects.cpp regtest.cpp ' + BS) == 1, 'patch f build tail'
assert 'AUDIT CENSUS' in s, 'patch f ate the census step'
assert 'PREFLIGHT: GREEN' in s, 'patch f ate the green line'
assert 'R107 (the lean gate)' in s, 'patch f ate the R107 note'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- (g) tools/phb_gap_report.md: the wiring-arc box ----
GR_HEAD_OLD = NL.join([
    '      rules/thieffunc.h CREATED (a DATA-ONLY',
    '      pin, the R186 poetics precedent - the',
    '      engine performs no thief rolls; the',
    '      seam waits for a future roll round) -',
])
GR_HEAD_NEW = NL.join([
    '      rules/thieffunc.h CREATED (a DATA-ONLY',
    '      pin, the R186 poetics precedent - WIRED',
    '      R301: the trap site now rolls the seam;',
    '      the other functions stay data) -',
])
GR_INS_OLD = NL.join([
    '      example. Census 215.',
    '',
    '## R299 the party recordings round (the third',
])
GR_BOX = NL.join([
    '- [x] **The thief trap rolls wired - WIRED',
    '      R301:** the R298 seam gains its first',
    '      callers and the R45 springTrap its',
    '      first caller ever.',
    '      rules/thieffunc.h gains',
    '      thfPercentileSucceeds (the printed',
    '      equal-or-less convention on the 0-999',
    '      tenths band - a whole-percent chance',
    '      owns its exact thousandth slice and',
    '      the 99.1 climb walls decimal reads',
    '      true) and thfAttemptSucceeds (the',
    '      fold over thfChanceTenths).',
    '      springTrap retires the flat 1-in-3',
    '      disarm: the thief rolls the printed',
    '      find and remove chances (two separate',
    '      percentile draws, one try each;',
    '      located but not removed fires - the',
    '      too-late line) and the new',
    '      checkTrapOnEntry springs an armed',
    '      trap in the chamber the company',
    '      stands in (the shell step wire,',
    '      adnd1.cpp; the MODE_EXPLORE gate).',
    '      The other seven functions stay data',
    '      (no engine site rolls them yet:',
    '      pick pockets, open locks, move',
    '      silently, hide in shadows, hear',
    '      noise, climb walls, read',
    '      languages). The R301a battery audit',
    '      walks the percentile boundary and',
    '      the folded chances (evaluable -',
    '      verified by audit_eval); the R301',
    '      engine audit drives every',
    '      springTrap branch on seeded',
    '      sequences (the battery build now',
    '      links the game state and xp',
    '      sources). Census 221. The ledger',
    '      holds ZERO open items.',
])
GR_INS_NEW = NL.join([
    '      example. Census 215.',
    '',
    GR_BOX,
    '',
    '## R299 the party recordings round (the third',
])
for t in (GR_HEAD_OLD, GR_HEAD_NEW, GR_INS_OLD, GR_BOX, GR_INS_NEW):
    clean(t, 57)

p = 'tools/phb_gap_report.md'
s = rd(p)
if 'The thief trap rolls wired' in s:
    already.append('phb_gap_report.md: the wiring-arc box')
else:
    assert s.count(GR_HEAD_OLD) == 1, 'gr head anchor not unique'
    assert s.count(GR_INS_OLD) == 1, 'gr insert anchor not unique'
    s = s.replace(GR_HEAD_OLD, GR_HEAD_NEW)
    s = s.replace(GR_INS_OLD, GR_INS_NEW)
    wr(p, s)
    applied.append('phb_gap_report.md: the wiring-arc box')
s = rd(p)
assert s.count('The thief trap rolls wired') == 1, 'patch g box'
assert s.count('R301: the trap site now rolls the seam') == 1, 'patch g head amend'
assert s.count('PINNED R298') == 1, 'patch g ate the R298 box head'
assert 'Census 221.' in s, 'patch g census note'
assert 'Census 215.' in s, 'patch g ate the R298 census'
assert 'Census 217.' in s, 'patch g ate the R299 census'
assert 'Census 219.' in s, 'patch g ate the R300 census'
assert 'WIRED R299' in s, 'patch g ate the R299 entry'
assert 'R299 SCOPE PASS' in s, 'patch g ate the R299 pass'
assert '## Out of engine scope' in s, 'patch g ate the scope head'
assert 'R298 battery audit' in s, 'patch g ate the R298 audit note'
assert 'seam waits for a future roll round' not in s, 'patch g stale note'
assert len(applied) + len(already) == 7, 'patch g count wrong'

# ---- R301 fails/tail ----
if fails:
    print('R301 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 7:
    print('R301 splice: FAIL - expected 7 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R301 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R301 note: 7 patches; the battery census 219 -> 221;')
print('the phb ledger holds ZERO open items')
print('commit: R301: the thief trap rolls wired (census 221)')

