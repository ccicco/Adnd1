#!/usr/bin/env python3
# R331: the UA weapon specialization
# prose (pp. 18-19) pin round - the
# class gate, the slot costs, the
# melee/bow/crossbow point blanks, the
# double specialization, the final
# note, the table structure with the
# cleanly readable cells (the mangled
# fraction cells read empty; the gap
# item stays open pending the PDF).
# Pin-era pattern (R322). Idempotent;
# run twice.

import io
import os

NL = '\n'
applied = []
already = []

def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)

def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)

# ---- (a) the seed: the R330 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R330 landed 2026-10-11: commit',
    '  76df31d, census 257, the UA',
    '  druid hierophant ladder pin',
    '  round (rules/hierophant.h): the',
    '  hierarchy, the abdication, the',
    '  Table I ladder, the spell',
    '  abilities, the 16th-23rd',
    '  powers, the plane and conjure',
    '  ladders, the five conjuring',
    '  tables; the earth 01-85 HD',
    '  cell and the L21 title cell',
    '  documented as OCR holes. GREEN',
    '  on the first paste. Two',
    '  lessons: a seam comment naming',
    '  an identifier trips the',
    '  not-in assert (reword the',
    '  comment, not the assert); and',
    '  the balance checker must strip',
    '  comments before strings - the',
    '  unpaired inch-mark quote in a',
    '  comment swallowed real braces',
    '  and faked an imbalance.',
    ])
s = rd(SD)
if 'R330 landed 2026-10-11' in s:
    already.append('seed: the R330 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R330 record')
s = rd(SD)
assert s.count('R330 landed 2026-10-11') == 1, 'a entry'
assert s.count('R329 landed') == 1, 'a r329 kept'
assert s.count('## Knowledge maintenance') == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/weaponspec.h ----
WS = 'rules/weaponspec.h'
if os.path.exists(WS) and 'R331' in rd(WS):
    already.append('weaponspec.h: the pins')
else:
    HDR = NL.join([
    '// ===========================================================================',
    '// Adnd1 - rules/weaponspec.h',
    '// The UA weapon specialization prose',
    '// (pp. 18-19) pins (R331).',
    '//',
    '// Pin-era pattern (R322): pinned data only - no engine site exists. The',
    '// creation-flow gate rides a later round; the R328 cavalier exclusion',
    '// pin carries the exclusion read.',
    '//',
    '// The Weapon Specialization Table: the',
    '// column titles, the three level bands',
    '// and six cleanly readable cells are',
    '// pinned (weaponSpecTableCellKnown).',
    '// The other eighteen cells are',
    '// OCR-mangled in the extract (the',
    '// fractions lost their slashes and',
    '// digits: "21", "mn", "3n", "an",',
    '// "4an", "51", "2n", "312", "81") with',
    '// no consistent decode - they read',
    '// empty, documented here and in the gap',
    '// report item, which stays OPEN until',
    '// the PDF read. The 1-6 row\'s light-',
    '// crossbow cell is blank in the',
    '// extract. The crossbow medium-range',
    '// read (+1 hit, no damage bonus) is',
    '// fragment-verified in the scrambled',
    '// tail (the R329 discipline).',
    '// ===========================================================================',
    '',
    '#pragma once',
    '',
    '#include "subraces.h"  // UaClass (the 14)',
    '',
    'namespace rules {',
    '',
    '// ---- the class gate (p. 18) ----',
    '// Fighters and rangers only; one',
    '// weapon chosen; the decision made',
    '// when the character is initially',
    '// created.',
    'inline bool weaponSpecClassAllowed(UaClass c) {',
    '    return c == UACLASS_FIGHTER',
    '        || c == UACLASS_RANGER;',
    '}',
    '',
    'inline bool weaponSpecAtCreationOnly()',
    '    { return true; }',
    '',
    '// ---- the slot costs (p. 18) ----',
    '// Specialization counts as two',
    '// proficiency slots: a fighter takes it',
    '// plus two other weapons of the initial',
    '// four; a ranger takes it plus a single',
    '// proficiency. A bow (other than a',
    '// crossbow) costs a third slot: the',
    '// fighter keeps one other weapon, the',
    '// ranger none.',
    'inline int weaponSpecSlots()',
    '    { return 2; }',
    '',
    'inline int weaponSpecFighterOtherProficiencies()',
    '    { return 2; }',
    '',
    'inline int weaponSpecRangerProficiencies()',
    '    { return 1; }',
    '',
    'inline int weaponSpecBowExtraSlot()',
    '    { return 1; }',
    '',
    'inline int weaponSpecFighterBowOthers()',
    '    { return 1; }',
    '',
    'inline int weaponSpecRangerBowOthers()',
    '    { return 0; }',
    '',
    '// ---- the melee benefits (p. 18) ----',
    '// +1 to hit, +2 to damage, on top of',
    '// strength and magic; the weapon must',
    '// be a specific type (long sword, not',
    '// sword); the table\'s additional',
    '// attacks override the Attacks Per',
    '// Melee Round Table.',
    'inline int weaponSpecMeleeToHitBonus()',
    '    { return 1; }',
    '',
    'inline int weaponSpecMeleeDamageBonus()',
    '    { return 2; }',
    '',
    'inline bool weaponSpecSpecificTypeRequired()',
    '    { return true; }',
    '',
    'inline bool weaponSpecExtraAttacks()',
    '    { return true; }',
    '',
    '// ---- the bow point blank (p. 18) ----',
    '// Long, short or composite bow:',
    '// 6"-30", +2 to hit and damage, double',
    '// damage on a hit (6-16 for a',
    '// non-magical arrow); the nocked-arrow',
    '// pre-initiative shot; short range',
    '// runs from 30" to the bow\'s medium',
    '// lower limit, +1 to hit and damage.',
    'inline int weaponSpecBowPointBlankMin()',
    '    { return 6; }',
    '',
    'inline int weaponSpecBowPointBlankMax()',
    '    { return 30; }',
    '',
    'inline int weaponSpecBowPointBlankBonus()',
    '    { return 2; }',
    '',
    'inline bool weaponSpecBowDoubleDamage()',
    '    { return true; }',
    '',
    'inline int weaponSpecArrowDamageLow()',
    '    { return 6; }',
    '',
    'inline int weaponSpecArrowDamageHigh()',
    '    { return 16; }',
    '',
    'inline bool',
    'weaponSpecNockedArrowPreInitiative()',
    '    { return true; }',
    '',
    'inline int weaponSpecBowShortRangeFrom()',
    '    { return 30; }',
    '',
    'inline int weaponSpecBowShortRangeBonus()',
    '    { return 1; }',
    '',
    '// ---- the crossbow point blank (p. 19)',
    '// ----',
    '// 6\'-60\' (overtaking a light crossbow\'s',
    '// short range in the dungeon); +2 to',
    '// hit and damage; double damage (6-12',
    '// for a light bolt); +1 to hit and',
    '// damage at short range; at medium +1',
    '// to hit but no damage bonus',
    '// (fragment-verified); the rate-of-fire',
    '// increase depends on light vs heavy;',
    '// the free shot before initiative if',
    '// cocked and aimed.',
    'inline int weaponSpecCrossbowPointBlankMin()',
    '    { return 6; }',
    '',
    'inline int weaponSpecCrossbowPointBlankMax()',
    '    { return 60; }',
    '',
    'inline int',
    'weaponSpecCrossbowPointBlankBonus()',
    '    { return 2; }',
    '',
    'inline bool',
    'weaponSpecCrossbowDoubleDamage()',
    '    { return true; }',
    '',
    'inline int weaponSpecLightBoltDamageLow()',
    '    { return 6; }',
    '',
    'inline int weaponSpecLightBoltDamageHigh()',
    '    { return 12; }',
    '',
    'inline int weaponSpecCrossbowShortBonus()',
    '    { return 1; }',
    '',
    'inline int',
    'weaponSpecCrossbowMediumHitBonus()',
    '    { return 1; }',
    '',
    'inline int',
    'weaponSpecCrossbowMediumDamageBonus()',
    '    { return 0; }',
    '',
    'inline bool weaponSpecCrossbowFreeShot()',
    '    { return true; }',
    '',
    '// ---- the other missiles (p. 19) ----',
    'inline int',
    'weaponSpecOtherMissileToHitBonus()',
    '    { return 1; }',
    '',
    'inline int',
    'weaponSpecOtherMissileDamageBonus()',
    '    { return 2; }',
    '',
    '// ---- the double specialization (p. 19)',
    '// ----',
    '// Melee weapons only, excluding pole',
    '// arms and the two-handed sword; taken',
    '// instead of a proficiency when the',
    '// character qualifies for a new weapon;',
    '// only in the already-specialized',
    '// weapon; +3 to hit and +3 to damage.',
    'inline bool weaponSpecDoubleAllowed()',
    '    { return true; }',
    '',
    'inline bool weaponSpecDoubleMeleeOnly()',
    '    { return true; }',
    '',
    'inline int weaponSpecDoubleToHitBonus()',
    '    { return 3; }',
    '',
    'inline int weaponSpecDoubleDamageBonus()',
    '    { return 3; }',
    '',
    '// ---- the final note (p. 19) ----',
    '// The bonuses are not magical (no',
    '// effect on magic-only creatures); a',
    '// magic weapon of the specialized type',
    '// stacks its bonuses with the',
    '// specialization bonuses.',
    'inline bool weaponSpecBonusesNotMagical()',
    '    { return true; }',
    '',
    'inline bool weaponSpecMagicStacks()',
    '    { return true; }',
    '',
    '// ---- the Weapon Specialization Table',
    '// (p. 19) ----',
    '// Eight columns (melee, bow, light',
    '// crossbow, heavy crossbow, lasso and',
    '// staff sling, thrown dagger, thrown',
    '// dart, other missiles and hurled',
    '// weapons), three level bands. Only the',
    '// cleanly readable cells are pinned',
    '// (below); the mangled cells read empty',
    '// pending the PDF.',
    'inline int weaponSpecTableColumnCount()',
    '    { return 8; }',
    '',
    'inline const char* weaponSpecTableColumnName(',
    '        int i) {',
    '    static const char* const k[8] = {',
    '        "Melee Weapon", "Bow",',
    '        "Light Crossbow", "Heavy Crossbow",',
    '        "Lasso and Staff Sling",',
    '        "Thrown Dagger", "Thrown Dart",',
    '        "Other Missiles and Hurled"',
    '        " Weapons"',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 7) i = 7;',
    '    return k[i];',
    '}',
    '',
    'inline int weaponSpecTableBandLow(int b) {',
    '    static const int k[3] = {1, 7, 13};',
    '    if (b < 0) b = 0;',
    '    if (b > 2) b = 2;',
    '    return k[b];',
    '}',
    '',
    'inline int weaponSpecTableBandHigh(int b) {',
    '    // band 0: 1-6; band 1: 7-12;',
    '    // band 2: 13+ (no upper bound;',
    '    // returns 0 to mean open)',
    '    static const int k[3] = {6, 12, 0};',
    '    if (b < 0) b = 0;',
    '    if (b > 2) b = 2;',
    '    return k[b];',
    '}',
    '',
    '// The cleanly readable cells: melee and',
    '// other-missiles 3/2 at 1-6 and 5/2 at',
    '// 13+; light crossbow and lasso/staff',
    '// sling 3/2 at 7-12. Every other cell',
    '// (and the 1-6 light-crossbow cell,',
    '// blank in the extract) reads empty -',
    '// the OCR-lost fraction cells',
    '// (documented in the header comment).',
    'inline const char* weaponSpecTableCellKnown(',
    '        int band, int col) {',
    '    if (band == 0 && col == 0) return "3/2";',
    '    if (band == 0 && col == 7) return "3/2";',
    '    if (band == 1 && col == 2) return "3/2";',
    '    if (band == 1 && col == 4) return "3/2";',
    '    if (band == 2 && col == 0) return "5/2";',
    '    if (band == 2 && col == 7) return "5/2";',
    '    return "";',
    '}',
    '',
    '}   // namespace rules',
    ])
    clean(HDR, 78)
    wr(WS, HDR)
    applied.append('weaponspec.h: the pins')
s = rd(WS)
assert s.count('namespace rules {') == 1, 'b namespace'
assert s.count('weaponSpecClassAllowed') == 1, 'b gate fn'
assert s.count('weaponSpecTableCellKnown') == 2, 'b cell fn'
assert s.count('weaponSpecTableColumnName') == 1, 'b name fn'
assert s.count('weaponSpecCrossbowMediumHitBonus') == 1, 'b medium fn'
assert s.count('#include "subraces.h"') == 1, 'b parent inc'
assert 'SUB_COUNT' not in s, 'b no SUB_COUNT'
assert 'cavalierSpecializationBanned' not in s, 'b no ban ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note ----
# The item STAYS OPEN (the table cells
# are OCR-lost); an in-place note
# records what R331 pinned.
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R331: the prose pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
    '      the bonuses are not magical.',
    ])
    NOTE = NL.join([
    '      - R331: the prose pinned',
    '      (rules/weaponspec.h) - the',
    '      class gate, the slot costs,',
    '      the melee/bow/crossbow',
    '      reads, the double, the table',
    '      structure with the cleanly',
    '      readable cells; the',
    '      table\'s fraction cells are',
    '      OCR-mangled (no consistent',
    '      decode) - stays open pending',
    '      the PDF read.',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail anchor'
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + NOTE)
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R331: the prose pinned') == 1, 'c note'
assert s.count(
    '- [ ] **Weapon specialization**'
    ) == 1, 'c item stays open'
assert s.count('CLOSED R330') == 1, 'c r330 kept'
assert s.count('- [x] **The druid hierophant'
    ) == 1, 'c druid kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R331 weapon spec prose pin audit' in s:
    already.append('regtest.cpp: the R331 audit')
else:
    INC_ANCH = ('#include "rules/hierophant.h"'
                '  // R330: the UA druid hierophant')
    INC_NEW = NL.join([
    INC_ANCH,
    '#include "rules/weaponspec.h"'
    '  // R331: the UA weapon spec'])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = NL.join([
    '    // ---- R331: the weapon specialization',
    '    // prose pin audit ----',
    '    // The UA weapon specialization (pp.',
    '    // 18-19) - the pin-era pattern: the',
    '    // class gate, the slot costs, the',
    '    // melee benefits, the bow and',
    '    // crossbow point blanks, the other',
    '    // missiles, the double',
    '    // specialization, the final note, the',
    '    // table structure with the cleanly',
    '    // readable cells (the mangled cells',
    '    // read empty - the item stays open',
    '    // pending the PDF). The R328',
    '    // exclusion seam cross-checked.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // U1: the class gate',
    '        {',
    '            if (!weaponSpecClassAllowed(',
    '                UACLASS_FIGHTER)) ++bad;',
    '            if (!weaponSpecClassAllowed(',
    '                UACLASS_RANGER)) ++bad;',
    '            if (weaponSpecClassAllowed(',
    '                UACLASS_CAVALIER)) ++bad;',
    '            if (weaponSpecClassAllowed(',
    '                UACLASS_PALADIN)) ++bad;',
    '            if (weaponSpecClassAllowed(',
    '                UACLASS_BARBARIAN)) ++bad;',
    '            if (weaponSpecClassAllowed(',
    '                UACLASS_THIEF)) ++bad;',
    '            if (!weaponSpecAtCreationOnly())',
    '                ++bad;',
    '        }',
    '        // U2: the slot costs',
    '        {',
    '            if (weaponSpecSlots() != 2) ++bad;',
    '            if (',
    '                weaponSpecFighterOtherProficiencies()',
    '                != 2) ++bad;',
    '            if (weaponSpecRangerProficiencies()',
    '                != 1) ++bad;',
    '            if (weaponSpecBowExtraSlot() != 1)',
    '                ++bad;',
    '            if (weaponSpecFighterBowOthers()',
    '                != 1) ++bad;',
    '            if (weaponSpecRangerBowOthers()',
    '                != 0) ++bad;',
    '            // the fighter budget: 2 spec',
    '            // slots + 2 others = the',
    '            // printed four',
    '            if (weaponSpecSlots()',
    '                + weaponSpecFighterOtherProficiencies()',
    '                != 4) ++bad;',
    '        }',
    '        // U3: the melee benefits',
    '        {',
    '            if (weaponSpecMeleeToHitBonus()',
    '                != 1) ++bad;',
    '            if (weaponSpecMeleeDamageBonus()',
    '                != 2) ++bad;',
    '            if (!weaponSpecSpecificTypeRequired())',
    '                ++bad;',
    '            if (!weaponSpecExtraAttacks())',
    '                ++bad;',
    '        }',
    '        // U4: the bow point blank',
    '        {',
    '            if (weaponSpecBowPointBlankMin()',
    '                != 6) ++bad;',
    '            if (weaponSpecBowPointBlankMax()',
    '                != 30) ++bad;',
    '            if (weaponSpecBowPointBlankBonus()',
    '                != 2) ++bad;',
    '            if (!weaponSpecBowDoubleDamage())',
    '                ++bad;',
    '            if (weaponSpecArrowDamageLow() != 6)',
    '                ++bad;',
    '            if (weaponSpecArrowDamageHigh()',
    '                != 16) ++bad;',
    '            if (!weaponSpecNockedArrowPreInitiative())',
    '                ++bad;',
    '            if (weaponSpecBowShortRangeFrom()',
    '                != 30) ++bad;',
    '            if (weaponSpecBowShortRangeBonus()',
    '                != 1) ++bad;',
    '        }',
    '        // U5: the crossbow point blank',
    '        // (the medium read rides the',
    '        // fragment-verified +1 hit, no',
    '        // damage bonus)',
    '        {',
    '            if (weaponSpecCrossbowPointBlankMin()',
    '                != 6) ++bad;',
    '            if (weaponSpecCrossbowPointBlankMax()',
    '                != 60) ++bad;',
    '            if (',
    '                weaponSpecCrossbowPointBlankBonus()',
    '                != 2) ++bad;',
    '            if (!weaponSpecCrossbowDoubleDamage())',
    '                ++bad;',
    '            if (weaponSpecLightBoltDamageLow()',
    '                != 6) ++bad;',
    '            if (weaponSpecLightBoltDamageHigh()',
    '                != 12) ++bad;',
    '            if (weaponSpecCrossbowShortBonus()',
    '                != 1) ++bad;',
    '            if (',
    '                weaponSpecCrossbowMediumHitBonus()',
    '                != 1) ++bad;',
    '            if (',
    '                weaponSpecCrossbowMediumDamageBonus()',
    '                != 0) ++bad;',
    '            if (!weaponSpecCrossbowFreeShot())',
    '                ++bad;',
    '        }',
    '        // U6: the other missiles and the',
    '        // double specialization',
    '        {',
    '            if (weaponSpecOtherMissileToHitBonus()',
    '                != 1) ++bad;',
    '            if (weaponSpecOtherMissileDamageBonus()',
    '                != 2) ++bad;',
    '            if (!weaponSpecDoubleAllowed())',
    '                ++bad;',
    '            if (!weaponSpecDoubleMeleeOnly())',
    '                ++bad;',
    '            if (weaponSpecDoubleToHitBonus()',
    '                != 3) ++bad;',
    '            if (weaponSpecDoubleDamageBonus()',
    '                != 3) ++bad;',
    '        }',
    '        // U7: the final note',
    '        {',
    '            if (!weaponSpecBonusesNotMagical())',
    '                ++bad;',
    '            if (!weaponSpecMagicStacks()) ++bad;',
    '        }',
    '        // U8: the table structure - the',
    '        // columns, the bands, the clean',
    '        // cells, the empty holes',
    '        {',
    '            if (weaponSpecTableColumnCount()',
    '                != 8) ++bad;',
    '            if (strcmp(weaponSpecTableColumnName(0),',
    '                "Melee Weapon") != 0) ++bad;',
    '            if (strcmp(weaponSpecTableColumnName(4),',
    '                "Lasso and Staff Sling") != 0)',
    '                ++bad;',
    '            if (strcmp(weaponSpecTableColumnName(7),',
    '                "Other Missiles and Hurled"',
    '                " Weapons") != 0) ++bad;',
    '            static const int lo[3] = {1, 7, 13};',
    '            static const int hi[3] = {6, 12, 0};',
    '            for (int b = 0; b < 3; ++b) {',
    '                if (weaponSpecTableBandLow(b)',
    '                    != lo[b]) ++bad;',
    '                if (weaponSpecTableBandHigh(b)',
    '                    != hi[b]) ++bad;',
    '            }',
    '            if (strcmp(',
    '                weaponSpecTableCellKnown(0, 0),',
    '                "3/2") != 0) ++bad;',
    '            if (strcmp(',
    '                weaponSpecTableCellKnown(0, 7),',
    '                "3/2") != 0) ++bad;',
    '            if (strcmp(',
    '                weaponSpecTableCellKnown(1, 2),',
    '                "3/2") != 0) ++bad;',
    '            if (strcmp(',
    '                weaponSpecTableCellKnown(1, 4),',
    '                "3/2") != 0) ++bad;',
    '            if (strcmp(',
    '                weaponSpecTableCellKnown(2, 0),',
    '                "5/2") != 0) ++bad;',
    '            if (strcmp(',
    '                weaponSpecTableCellKnown(2, 7),',
    '                "5/2") != 0) ++bad;',
    '            // the OCR-lost cells read empty',
    '            if (weaponSpecTableCellKnown(0, 1)[0]',
    '                != 0) ++bad;',
    '            if (weaponSpecTableCellKnown(0, 2)[0]',
    '                != 0) ++bad;',
    '            if (weaponSpecTableCellKnown(0, 3)[0]',
    '                != 0) ++bad;',
    '            if (weaponSpecTableCellKnown(1, 5)[0]',
    '                != 0) ++bad;',
    '            if (weaponSpecTableCellKnown(2, 3)[0]',
    '                != 0) ++bad;',
    '        }',
    '        // U9: the R328 exclusion seam',
    '        {',
    '            if (!cavalierSpecializationBanned())',
    '                ++bad;',
    '            if (weaponSpecClassAllowed(',
    '                UACLASS_CAVALIER)) ++bad;',
    '        }',
    '        printf("R331 weapon spec prose pin audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
    ])
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH, AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R331 audit')
s = rd(RT)
assert s.count(
    'R331 weapon spec prose pin audit: bad '
    ) == 1, 'd audit line'
assert s.count('audit: bad ') == 258, 'd census 258'
assert s.count(
    'R330 druid hierophant pin audit') == 1, 'd r330 kept'
assert s.count('R227: the wis mental save') == 1, \
    'd r227 kept'
assert s.count(
    '#include "rules/weaponspec.h"') == 1, \
    'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R331 splice: ALL OK (applied %d,'
      ' already %d)'
      % (len(applied), len(already)))
print('R331 note: the UA weapon')
print('specialization prose pin round - the')
print('class gate, the slots, the melee and')
print('point-blank reads, the double, the')
print('table structure (the fraction cells')
print('stay open pending the PDF); the')
print('census 257 -> 258')
print('commit: R331: the UA weapon')
print('specialization prose pin round')
print('(census 258)')

