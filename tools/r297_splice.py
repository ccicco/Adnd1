#!/usr/bin/env python3
# tools/r297_splice.py - R297: the weapon
# proficiency table pinned and wired - the
# penalty reaches the to-hit path.
#
# The R296 scope round opened the Weapon
# Proficiency Table (the PHB WEAPONS section,
# upload line 2499) as the R297 candidate. This
# round pins it and wires the penalty:
#
#   (a) rules/weaponprof.h CREATED - the ten
#       printed rows (the initial slots 2, 2, 4,
#       3, 3, 1, 1, 2, 3, 1; the non-proficiency
#       penalty magnitudes 3, 4, 2, 2, 2, 5, 5, 3,
#       2, 3; the added-slot cadences 4, 5, 3, 3,
#       3, 6, 6, 4, 4, 2), the engine mapping
#       (the base CharClass pair and the registry
#       Subclass to the printed row; the subclass
#       row wins when set, the fighter default
#       matches attackNumber), the slot-at-level
#       walker (the printed cleric example: 2 at
#       1st, 3 at 5th, 4 at 9th, 5 at 13th), the
#       printed notes (the same-type magical
#       subsumption, the missile-or-melee reach,
#       the levels-above-the-1st cadence) and the
#       penalty seam wpfNonProfHitAdj (-2 to -5
#       by the class pair).
#   (b) ai/actor.h - the Actor gains the recorded
#       slot list profWeaponIds plus
#       proficientWithWeapon (the EMPTY list =
#       the pre-R297 convention: unrecorded
#       choices never pay; monsters read
#       proficient).
#   (c) ai/actor.cpp - Actor::hitAdjustment folds
#       the seam: a held weapon outside a
#       NON-EMPTY recorded list pays the class
#       penalty. The monk open hand stays flat 0
#       (the early return, the R181/R232 pins).
#   (d) game/state_combat.cpp - the kitNpc NPCs
#       record their kit weapons (the creation
#       choice).
#   (e) regtest.cpp - the R297 audit block (the
#       battery census 213 -> 214): the three
#       printed columns walked row by row, the
#       clamps, the cleric example, the mapping
#       pair probes, the seam identity and the
#       note scalars.
#   (f) tools/phb_gap_report.md - the R296 open
#       item flips PINNED R297 (Census 214).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY patch
# (the R142 lesson). ZERO literal backslash
# bytes in this file (the audit printf newline
# builds via BS; the include lines carry plain
# double quotes inside single-quoted Python
# strings), and no CONTENT string embeds an
# apostrophe, non-ASCII or (for the gap report)
# a line past 57 columns.
# Commit: "R297: the weapon proficiency table
# pinned and wired - the penalty reaches the
# to-hit path (census 214)"
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

def clean(s, limit):
    assert chr(39) not in s, 'apostrophe in content'
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

# ---- (a) rules/weaponprof.h CREATED ----
HEADER = NL.join([
    '// ====================================================================',
    '// Adnd1 - rules/weaponprof.h',
    '// R297: the PHB Weapon Proficiency Table',
    '// (the WEAPONS section, Premium 1e OCR',
    '// upload line 2499) - the ten printed class',
    '// rows: the initial number of weapons, the',
    '// non-proficiency to-hit penalty and the',
    '// added-proficiency cadence, plus the',
    '// mapping from the engine class pair (the',
    '// base CharClass and the registry Subclass)',
    '// to the printed row, and the',
    '// non-proficiency to-hit adjustment seam the',
    '// combat layer folds into Actor::hitAdjustment',
    '// (ai/actor.cpp).',
    '//',
    '// The printed rows (the table top to bottom):',
    '//   CLERIC      2 slots, -3 penalty, 1 per 4 levels',
    '//   Druid       2, -4, 1 per 5',
    '//   FIGHTER     4, -2, 1 per 3',
    '//   Paladin     3, -2, 1 per 3',
    '//   Ranger      3, -2, 1 per 3',
    '//   MAGIC-USER  1, -5, 1 per 6',
    '//   Illusionist 1, -5, 1 per 6',
    '//   THIEF       2, -3, 1 per 4',
    '//   Assassin    3, -2, 1 per 4',
    '//   MONK        1, -3, 1 per 2',
    '//',
    '// The printed notes (upload lines 2491-2497):',
    '//   - proficiency with a normal weapon is',
    '//     subsumed in using a magical weapon of the',
    '//     same type (wpfNoteSubsumption);',
    '//   - the penalty applies to attacks in missile',
    '//     or melee combat (wpfNoteMeleeMissile);',
    '//   - the added proficiency arrives at the',
    '//     printed number of LEVELS ABOVE THE 1ST',
    '//     (the cleric example: two weapons at 1st,',
    '//     three at 5th, four at 9th, five at 13th -',
    '//     wpfSlotsAt and wpfNoteAddedAboveFirst).',
    '//',
    '// Conventions:',
    '//   - wpfNonProfPenalty returns the MAGNITUDE',
    '//     (2..5); the to-hit adjustment is negative',
    '//     (wpfNonProfHitAdj).',
    '//   - the row enum follows the PRINTED row order.',
    '//   - the engine carries four base classes plus',
    '//     six registry subclasses; wpfRowFor picks',
    '//     the subclass row when the registry',
    '//     subclass is set, else the base row (an',
    '//     unknown subclass index falls back to the',
    '//     base row - the attackNumber default-class',
    '//     convention).',
    '//   - the slot COUNTS are data (the engine',
    '//     records no weapon choices yet beyond the',
    '//     kitNpc grant; the party roster carries',
    '//     none - a future round); the PENALTY is',
    '//     live wiring (Actor::hitAdjustment pays it',
    '//     when a recorded list excludes the held',
    '//     weapon). The monk open hand stays flat 0',
    '//     (the R181/R232 pins).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The printed row order (the table top to bottom).',
    'enum ProfRow {',
    '    PROF_CLERIC = 0,',
    '    PROF_DRUID,',
    '    PROF_FIGHTER,',
    '    PROF_PALADIN,',
    '    PROF_RANGER,',
    '    PROF_MAGIC_USER,',
    '    PROF_ILLUSIONIST,',
    '    PROF_THIEF,',
    '    PROF_ASSASSIN,',
    '    PROF_MONK',
    '};',
    '',
    'inline int wpfRowCount() {',
    '    // the ten printed class rows',
    '    return 10;',
    '}',
    '',
    'inline int wpfInitialSlots(int row) {',
    '    // the initial number of weapons; row clamps',
    '    if (row < 0) row = 0;',
    '    if (row > 9) row = 9;',
    '    static const int t[10] = {',
    '        2, 2, 4, 3, 3, 1, 1, 2, 3, 1,',
    '    };',
    '    return t[row];',
    '}',
    '',
    'inline int wpfNonProfPenalty(int row) {',
    '    // the non-proficiency to-hit penalty MAGNITUDE',
    '    if (row < 0) row = 0;',
    '    if (row > 9) row = 9;',
    '    static const int t[10] = {',
    '        3, 4, 2, 2, 2, 5, 5, 3, 2, 3,',
    '    };',
    '    return t[row];',
    '}',
    '',
    'inline int wpfAddedCadence(int row) {',
    '    // the added-proficiency levels-per-slot',
    '    if (row < 0) row = 0;',
    '    if (row > 9) row = 9;',
    '    static const int t[10] = {',
    '        4, 5, 3, 3, 3, 6, 6, 4, 4, 2,',
    '    };',
    '    return t[row];',
    '}',
    '',
    'inline int wpfSlotsAt(int row, int level) {',
    '    // the slots at a level: the initial number',
    '    // plus one per completed cadence of levels',
    '    // above the 1st (the printed cleric',
    '    // example: 2 at 1st, 3 at 5th, 4 at 9th,',
    '    // 5 at 13th); the level clamps at 1',
    '    if (level < 1) level = 1;',
    '    return wpfInitialSlots(row) +',
    '           (level - 1) / wpfAddedCadence(row);',
    '}',
    '',
    'inline int wpfRowForBase(int classIndex) {',
    '    // the base CharClass to the printed row',
    '    // (the fighter default matches attackNumber)',
    '    if (classIndex == 1) return 5;   // magic-user',
    '    if (classIndex == 2) return 0;   // cleric',
    '    if (classIndex == 3) return 7;   // thief',
    '    return 2;                        // fighter',
    '}',
    '',
    'inline int wpfRowForSubclass(int sub) {',
    '    // the registry Subclass to the printed row;',
    '    // -1 = a plain class member (no subclass row)',
    '    if (sub == 0) return 3;   // paladin',
    '    if (sub == 1) return 4;   // ranger',
    '    if (sub == 2) return 1;   // druid',
    '    if (sub == 3) return 6;   // illusionist',
    '    if (sub == 4) return 8;   // assassin',
    '    if (sub == 5) return 9;   // monk',
    '    return -1;',
    '}',
    '',
    'inline int wpfRowFor(int classIndex, int subclass) {',
    '    // the engine class pair to the printed row:',
    '    // the subclass row wins when the registry',
    '    // subclass is set, else the base row',
    '    if (wpfRowForSubclass(subclass) >= 0)',
    '        return wpfRowForSubclass(subclass);',
    '    return wpfRowForBase(classIndex);',
    '}',
    '',
    'inline int wpfNonProfHitAdj(int classIndex,',
    '                             int subclass) {',
    '    // the to-hit adjustment a non-proficient',
    '    // attacker pays: -2..-5 by class (the',
    '    // Actor::hitAdjustment seam)',
    '    return -wpfNonProfPenalty(',
    '        wpfRowFor(classIndex, subclass));',
    '}',
    '',
    'inline int wpfNoteSubsumption() {',
    '    // a magical weapon of the same type',
    '    // subsumes the normal-weapon proficiency',
    '    return 1;',
    '}',
    '',
    'inline int wpfNoteMeleeMissile() {',
    '    // the penalty applies in missile or melee',
    '    return 1;',
    '}',
    '',
    'inline int wpfNoteAddedAboveFirst() {',
    '    // the added slots count levels above the 1st',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
    '',
])
clean(HEADER, 100)

p = 'rules/weaponprof.h'
if os.path.exists(os.path.join(ROOT, p)):
    s = rd(p)
    if 'R297: the PHB Weapon Proficiency Table' in s:
        already.append('weaponprof.h created')
    else:
        fails.append('weaponprof.h exists without the R297 marker')
else:
    wr(p, HEADER)
    applied.append('weaponprof.h created')
s = rd(p)
assert 'wpfNonProfHitAdj' in s, 'patch a failed'
assert s.count('inline int wpf') == 12, 'accessor count wrong'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) ai/actor.h: the recorded slot list ----
ACTH_NEW = NL.join([
    '    // R297: the weapon proficiency slots (the PHB',
    '    // Weapon Proficiency Table, rules/weaponprof.h).',
    '    // The RECORDED weapon ids the character chose.',
    '    // EMPTY = proficiency unrecorded: the pre-R297',
    '    // convention holds (the held weapon is treated',
    '    // as proficient; no penalty paid) - the party',
    '    // roster carries no recordings yet. The kitNpc',
    '    // NPCs record their kit weapons. A held weapon',
    '    // outside a NON-EMPTY list pays the class',
    '    // non-proficiency penalty (hitAdjustment).',
    '    std::vector<int> profWeaponIds;',
    '    bool proficientWithWeapon(int weaponId) const {',
    '        if (!isCharacter) return true;   // monsters',
    '        if (profWeaponIds.empty()) return true;',
    '        for (int id : profWeaponIds)',
    '            if (id == weaponId) return true;',
    '        return false;',
    '    }',
])
clean(ACTH_NEW, 100)

p = 'ai/actor.h'
s = rd(p)
if 'R297: the weapon proficiency slots' in s:
    already.append('actor.h: the slot list')
else:
    anchor = NL.join([
        '    items::WeaponInstance rangedWeapon;',
        '    // R35: shots remaining in the quiver (characters only; the',
    ])
    assert s.count(anchor) == 1, 'actor.h anchor not unique'
    s2 = s.replace(anchor,
        '    items::WeaponInstance rangedWeapon;' + NL +
        ACTH_NEW + NL +
        '    // R35: shots remaining in the quiver (characters only; the')
    wr(p, s2)
    applied.append('actor.h: the slot list')
s = rd(p)
assert 'proficientWithWeapon' in s, 'patch b failed'
assert s.count('R297: the weapon proficiency slots') == 1, 'patch b marker'
assert 'std::vector<int> knownSpells;' in s, 'patch b ate knownSpells'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) ai/actor.cpp: the include + the fold ----
INC_NEW = NL.join([
    '#include "../rules/bard.h"  // R236: the poetics ferocity',
    '#include "../rules/weaponprof.h"  // R297: the proficiency table',
])
FOLD_OLD = NL.join([
    '        return items::attackAdjustment(weapon, exStr, str,',
    '                items::apparentArmorAc(defender.armor,',
    '                                       defender.shield));',
    '    }',
    '    return 0;   // monsters: flat',
])
FOLD_NEW = NL.join([
    '        int adj = items::attackAdjustment(weapon, exStr,',
    '                str,',
    '                items::apparentArmorAc(defender.armor,',
    '                                       defender.shield));',
    '        // R297: the PHB Weapon Proficiency Table - a',
    '        // held weapon outside the RECORDED slots pays',
    '        // the class non-proficiency penalty (the seam',
    '        // rules::wpfNonProfHitAdj). The EMPTY list =',
    '        // the pre-R297 convention (unrecorded choices',
    '        // never pay); the monk open hand stays flat 0',
    '        // (the early return above, the R181/R232 pins)',
    '        if (!proficientWithWeapon(weapon.id))',
    '            adj += rules::wpfNonProfHitAdj(classIndex,',
    '                                           subclass);',
    '        return adj;',
    '    }',
    '    return 0;   // monsters: flat',
])
clean(INC_NEW, 100)
clean(FOLD_NEW, 100)

p = 'ai/actor.cpp'
s = rd(p)
if 'R297: the PHB Weapon Proficiency Table - a' in s:
    already.append('actor.cpp: the fold')
else:
    a1 = '#include "../rules/bard.h"  // R236: the poetics ferocity'
    assert s.count(a1) == 1, 'actor.cpp include anchor not unique'
    assert s.count(FOLD_OLD) == 1, 'actor.cpp fold anchor not unique'
    s = s.replace(a1, INC_NEW)
    s = s.replace(FOLD_OLD, FOLD_NEW)
    wr(p, s)
    applied.append('actor.cpp: the fold')
s = rd(p)
assert 'rules::wpfNonProfHitAdj' in s, 'patch c failed'
assert s.count('R297: the proficiency table') == 1, 'patch c include marker'
assert 'if (subclass == rules::SUB_MONK) return 0;' in s, 'patch c ate the monk pin'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) game/state_combat.cpp: the kit grant ----
KIT_OLD = NL.join([
    '            default:   // fighter group',
    '                a.armor.id = m.level >= 2 ? ARMOR_PLATE',
    '                                          : ARMOR_CHAIN_MAIL;',
    '                a.weapon.id = WPN_LONG_SWORD;',
    '                a.shield = true;',
    '                break;',
    '        }',
    '    }',
])
KIT_NEW = NL.join([
    '            default:   // fighter group',
    '                a.armor.id = m.level >= 2 ? ARMOR_PLATE',
    '                                          : ARMOR_CHAIN_MAIL;',
    '                a.weapon.id = WPN_LONG_SWORD;',
    '                a.shield = true;',
    '                break;',
    '        }',
    '        // R297: the kit weapon is the chosen',
    '        // proficiency (the PHB Weapon Proficiency',
    '        // Table - rules/weaponprof.h; the initial',
    '        // and added slots size the full list at a',
    '        // future choice round)',
    '        a.profWeaponIds.push_back(a.weapon.id);',
    '    }',
])
clean(KIT_NEW, 100)

p = 'game/state_combat.cpp'
s = rd(p)
if 'R297: the kit weapon is the chosen' in s:
    already.append('state_combat.cpp: the kit grant')
else:
    assert s.count(KIT_OLD) == 1, 'kitNpc anchor not unique'
    wr(p, s.replace(KIT_OLD, KIT_NEW))
    applied.append('state_combat.cpp: the kit grant')
s = rd(p)
assert 'a.profWeaponIds.push_back(a.weapon.id);' in s, 'patch d failed'
assert 'void AppState::kitNpc' in s, 'patch d ate kitNpc'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) regtest.cpp: the include + the audit block ----
REG_INC_OLD = '#include "rules/specartprose2.h"  // R281: the III.E Special artifacts explanation prose part 2 pins'
REG_INC_NEW = NL.join([
    '#include "rules/specartprose2.h"  // R281: the III.E Special artifacts explanation prose part 2 pins',
    '#include "rules/weaponprof.h"  // R297: the PHB Weapon Proficiency Table',
])
AUDIT = NL.join([
    '    // ---- R297: the weapon proficiency table pins audit ----',
    '    // The PHB WEAPONS section Weapon Proficiency',
    '    // Table: the ten printed class rows (the',
    '    // initial slots, the non-proficiency penalty,',
    '    // the added-slot cadence), the base-class and',
    '    // subclass mappings, the slot-at-level walker',
    '    // (the printed cleric example), the clamps and',
    '    // the penalty seam wpfNonProfHitAdj (the',
    '    // Actor::hitAdjustment fold - ai/actor.cpp;',
    '    // the empty-list convention and the monk open',
    '    // hand stay engine pins, recorded in the',
    '    // header).',
    '    {',
    '        int bad = 0;',
    '        // the row count and the three printed columns',
    '        if (rules::wpfRowCount() != 10) ++bad;',
    '        static const int kSlots[10] = {',
    '            2, 2, 4, 3, 3, 1, 1, 2, 3, 1,',
    '        };',
    '        static const int kPen[10] = {',
    '            3, 4, 2, 2, 2, 5, 5, 3, 2, 3,',
    '        };',
    '        static const int kCad[10] = {',
    '            4, 5, 3, 3, 3, 6, 6, 4, 4, 2,',
    '        };',
    '        for (int i = 0; i < 10; ++i)',
    '            if (rules::wpfInitialSlots(i) != kSlots[i] ||',
    '                rules::wpfNonProfPenalty(i) != kPen[i] ||',
    '                rules::wpfAddedCadence(i) != kCad[i]) ++bad;',
    '        // the clamps (the rows clamp 0..9, the',
    '        // level at 1)',
    '        if (rules::wpfInitialSlots(-5) != 2 ||',
    '            rules::wpfInitialSlots(99) != 1 ||',
    '            rules::wpfNonProfPenalty(-1) != 3 ||',
    '            rules::wpfNonProfPenalty(12) != 3 ||',
    '            rules::wpfAddedCadence(-3) != 4 ||',
    '            rules::wpfAddedCadence(77) != 2 ||',
    '            rules::wpfSlotsAt(0, 0) != 2 ||',
    '            rules::wpfSlotsAt(0, -7) != 2) ++bad;',
    '        // the printed cleric example: two weapons',
    '        // at 1st, three at 5th, four at 9th, five',
    '        // at 13th (the added-slot notes)',
    '        if (rules::wpfSlotsAt(0, 1) != 2 ||',
    '            rules::wpfSlotsAt(0, 5) != 3 ||',
    '            rules::wpfSlotsAt(0, 9) != 4 ||',
    '            rules::wpfSlotsAt(0, 13) != 5) ++bad;',
    '        // the per-class cadence spot checks',
    '        // (fighter 1 per 3, druid 1 per 5,',
    '        // magic-user 1 per 6, assassin 1 per 4,',
    '        // monk 1 per 2)',
    '        if (rules::wpfSlotsAt(2, 1) != 4 ||',
    '            rules::wpfSlotsAt(2, 4) != 5 ||',
    '            rules::wpfSlotsAt(2, 7) != 6 ||',
    '            rules::wpfSlotsAt(1, 1) != 2 ||',
    '            rules::wpfSlotsAt(1, 6) != 3 ||',
    '            rules::wpfSlotsAt(1, 11) != 4 ||',
    '            rules::wpfSlotsAt(5, 1) != 1 ||',
    '            rules::wpfSlotsAt(5, 7) != 2 ||',
    '            rules::wpfSlotsAt(5, 13) != 3 ||',
    '            rules::wpfSlotsAt(8, 1) != 3 ||',
    '            rules::wpfSlotsAt(8, 5) != 4 ||',
    '            rules::wpfSlotsAt(9, 1) != 1 ||',
    '            rules::wpfSlotsAt(9, 3) != 2 ||',
    '            rules::wpfSlotsAt(9, 5) != 3) ++bad;',
    '        // the walker identities: level 1 = the',
    '        // initial slots; the added slot lands at',
    '        // 1 + cadence (every row)',
    '        for (int r = 0; r < 10; ++r)',
    '            if (rules::wpfSlotsAt(r, 1) !=',
    '                    rules::wpfInitialSlots(r) ||',
    '                rules::wpfSlotsAt(r, 1 +',
    '                    rules::wpfAddedCadence(r)) !=',
    '                    rules::wpfInitialSlots(r) + 1) ++bad;',
    '        // the base-class mapping (fighter 2,',
    '        // magic-user 5, cleric 0, thief 7; the',
    '        // out-of-range default reads the fighter',
    '        // row - the attackNumber convention)',
    '        if (rules::wpfRowForBase(0) != 2 ||',
    '            rules::wpfRowForBase(1) != 5 ||',
    '            rules::wpfRowForBase(2) != 0 ||',
    '            rules::wpfRowForBase(3) != 7 ||',
    '            rules::wpfRowForBase(99) != 2) ++bad;',
    '        // the subclass mapping (paladin 3, ranger',
    '        // 4, druid 1, illusionist 6, assassin 8,',
    '        // monk 9; -1 and the unknowns read -1)',
    '        if (rules::wpfRowForSubclass(0) != 3 ||',
    '            rules::wpfRowForSubclass(1) != 4 ||',
    '            rules::wpfRowForSubclass(2) != 1 ||',
    '            rules::wpfRowForSubclass(3) != 6 ||',
    '            rules::wpfRowForSubclass(4) != 8 ||',
    '            rules::wpfRowForSubclass(5) != 9 ||',
    '            rules::wpfRowForSubclass(-1) != -1 ||',
    '            rules::wpfRowForSubclass(6) != -1) ++bad;',
    '        // the pair mapping: the subclass row wins',
    '        // when set, the base row otherwise (an',
    '        // unknown subclass falls back to the base)',
    '        if (rules::wpfRowFor(0, -1) != 2 ||',
    '            rules::wpfRowFor(2, -1) != 0 ||',
    '            rules::wpfRowFor(0, 0) != 3 ||',
    '            rules::wpfRowFor(2, 2) != 1 ||',
    '            rules::wpfRowFor(1, 3) != 6 ||',
    '            rules::wpfRowFor(3, 4) != 8 ||',
    '            rules::wpfRowFor(3, 5) != 9 ||',
    '            rules::wpfRowFor(3, 9) != 7) ++bad;',
    '        // the penalty seam: -2..-5 by the class',
    '        // pair (the subclass overrides the base)',
    '        if (rules::wpfNonProfHitAdj(0, -1) != -2 ||',
    '            rules::wpfNonProfHitAdj(1, -1) != -5 ||',
    '            rules::wpfNonProfHitAdj(2, -1) != -3 ||',
    '            rules::wpfNonProfHitAdj(3, -1) != -3 ||',
    '            rules::wpfNonProfHitAdj(0, 0) != -2 ||',
    '            rules::wpfNonProfHitAdj(2, 2) != -4 ||',
    '            rules::wpfNonProfHitAdj(3, 4) != -2 ||',
    '            rules::wpfNonProfHitAdj(3, 5) != -3 ||',
    '            rules::wpfNonProfHitAdj(1, 3) != -5) ++bad;',
    '        // the seam identity: the adjustment is',
    '        // the negated penalty of the mapped row,',
    '        // every base pair and every subclass',
    '        for (int c = 0; c < 4; ++c)',
    '            if (rules::wpfNonProfHitAdj(c, -1) !=',
    '                    -rules::wpfNonProfPenalty(',
    '                        rules::wpfRowForBase(c))) ++bad;',
    '        for (int s = 0; s < 6; ++s)',
    '            if (rules::wpfNonProfHitAdj(0, s) !=',
    '                    -rules::wpfNonProfPenalty(',
    '                        rules::wpfRowForSubclass(s))) ++bad;',
    '        // the printed notes: the same-type magical',
    '        // subsumption, the missile-or-melee reach,',
    '        // the levels-above-the-1st cadence',
    '        if (rules::wpfNoteSubsumption() != 1 ||',
    '            rules::wpfNoteMeleeMissile() != 1 ||',
    '            rules::wpfNoteAddedAboveFirst() != 1) ++bad;',
    '        printf("R297 weapon proficiency table pins audit: bad %d'
    + BS + 'n", bad);',
    '    }',
])
for ln in AUDIT.split(NL):
    assert all(ord(c) < 128 for c in ln), 'non-ascii in audit'
    assert len(ln) <= 74, 'audit line too long: ' + ln
    assert chr(39) not in ln, 'apostrophe in audit'
    if 'printf' in ln:
        assert ln.count(BS) == 1, 'printf BS count wrong'
    else:
        assert BS not in ln, 'stray backslash in audit'
clean(REG_INC_NEW, 100)

p = 'regtest.cpp'
s = rd(p)
if 'R297 weapon proficiency table pins audit' in s:
    already.append('regtest.cpp: the R297 audit')
else:
    assert s.count(REG_INC_OLD) == 1, 'regtest include anchor not unique'
    r295_tail = ('        printf("R295 special artifacts prose'
                 ' part 16 pins audit: bad %d' + BS
                 + 'n", bad);')
    r227_head = '    // ---- R227: the wis mental save wiring audit ----'
    anchor = r295_tail + NL + '    }' + NL + r227_head
    assert s.count(anchor) == 1, 'regtest block anchor not unique'
    s = s.replace(REG_INC_OLD, REG_INC_NEW)
    new_region = r295_tail + NL + '    }' + NL + AUDIT + NL + r227_head
    s = s.replace(anchor, new_region)
    wr(p, s)
    applied.append('regtest.cpp: the R297 audit')
s = rd(p)
assert s.count('R297 weapon proficiency table pins audit') == 1, 'patch e failed'
assert s.count('audit: bad') == 214, 'census is not 214'
assert s.count('#include "rules/weaponprof.h"') == 1, 'patch e include'
assert 'R295 special artifacts prose part 16' in s, 'patch e ate R295'
assert '// ---- R227: the wis mental save wiring audit ----' in s, 'patch e ate R227'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) tools/phb_gap_report.md: the flip ----
ITEM_OLD = NL.join([
    '- [ ] **Weapon Proficiency Table (the WEAPONS',
    '      section)** - ten class rows. Initial',
    '      slots: cleric 2, druid 2, fighter 4,',
    '      paladin 3, ranger 3, magic-user 1,',
    '      illusionist 1, thief 2, assassin 3,',
    '      monk 1. The non-proficiency to-hit',
    '      penalty: fighter, paladin, ranger and',
    '      assassin -2; cleric, thief and monk -3;',
    '      druid -4; magic-user and illusionist',
    '      -5. The added-slot cadence: monk 1 per 2',
    '      levels, fighter-types 1 per 3, cleric,',
    '      thief and assassin 1 per 4, druid 1 per',
    '      5, magic-user and illusionist 1 per 6.',
    '      The printed notes: proficiency with a',
    '      normal weapon is subsumed in the magical',
    '      weapon of the same type; the added slots',
    '      arrive at the indicated level count above',
    '      the 1st (the cleric example: two weapons',
    '      at 1st, three at 5th, four at 9th, five',
    '      at 13th). UNWIRED - no proficiency layer',
    '      exists in the engine; the pin candidate',
    '      wires the penalty into the to-hit path',
    '      and the slot counts as data. The R297',
    '      candidate.',
])
ITEM_NEW = NL.join([
    '- [x] **Weapon Proficiency Table (the WEAPONS',
    '      section) - PINNED R297:**',
    '      rules/weaponprof.h CREATED - the ten',
    '      printed rows (the initial slots, the',
    '      non-proficiency penalty, the added-slot',
    '      cadence) with the engine mapping',
    '      (wpfRowFor: the base-class pair to the',
    '      printed row; the subclass row wins when',
    '      the registry subclass is set, the',
    '      fighter default matches attackNumber),',
    '      the slot-at-level walker wpfSlotsAt',
    '      (the printed cleric example: 2 at 1st,',
    '      3 at 5th, 4 at 9th, 5 at 13th) and the',
    '      printed notes (the same-type magical',
    '      subsumption, the missile-or-melee reach,',
    '      the levels-above-the-1st cadence).',
    '      WIRED: the penalty seam wpfNonProfHitAdj',
    '      folds into Actor::hitAdjustment',
    '      (ai/actor.cpp) - a held weapon outside a',
    '      RECORDED slot list pays the class',
    '      penalty (-2 to -5); the empty list =',
    '      the pre-R297 convention (unrecorded',
    '      choices never pay), and the monk open',
    '      hand stays flat 0 (the R181/R232 pins).',
    '      The kitNpc NPCs record their kit weapons',
    '      (game/state_combat.cpp). Simplifications',
    '      recorded: the party roster carries no',
    '      recordings yet (a future round), the',
    '      slot COUNTS stay data (the engine sizes',
    '      no lists beyond the kit grant) and the',
    '      ranged-weapon slot is not yet recorded',
    '      (the missile path shares the same',
    '      hitAdjustment seam). The R297 battery',
    '      audit walks the three columns row by',
    '      row, the clamps, the mapping pair probes',
    '      and the seam identity. Census 214.',
])
clean(ITEM_OLD, 57)
clean(ITEM_NEW, 57)

p = 'tools/phb_gap_report.md'
s = rd(p)
if 'PINNED R297' in s:
    already.append('phb_gap_report.md: the flip')
else:
    assert s.count(ITEM_OLD) == 1, 'the gap item anchor not unique'
    assert s.count('- [ ]') == 2, 'the open-item count is not 2'
    wr(p, s.replace(ITEM_OLD, ITEM_NEW))
    applied.append('phb_gap_report.md: the flip')
s = rd(p)
assert s.count('PINNED R297') == 1, 'patch f failed'
assert s.count('- [ ]') == 1, 'patch f left no open item'
assert s.count('[x] **Weapon Proficiency Table') == 1, 'flip box wrong'
assert 'R298 candidate.' in s, 'patch f ate the R298 item'
assert s.rstrip().endswith('(data-only).'), 'patch f ate the tail'
assert 'R296 SCOPE PASS' in s, 'patch f ate the scope section'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- R297 fails/tail ----
if fails:
    print('R297 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 6:
    print('R297 splice: FAIL - expected 6 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R297 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R297 note: 6 patches; the battery census 213 -> 214;')
print('real gate: md5sum rules/weaponprof.h')
print('commit: R297: the weapon proficiency table pinned and wired - the penalty reaches the to-hit path (census 214)')

