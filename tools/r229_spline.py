#!/usr/bin/env python3
# R229 splice: the illusionist roster joins the SpellId
# registry. The R183 dead-data layer goes live: 61 IL_ ids
# appended after DR_TRANSMUTE_METAL_TO_WOOD, 61 kSpells rows
# (PHB illusionist spell description header parameters in the
# R228 conventions), the seven-accessor parameter seam in
# rules/illusionspells.h (the grenade.h/druidspells.h
# pattern; the illusionist print carries no reversible
# markers), spellSlots(SPELL_ILLUSIONIST, ...) delegates to
# the R183 slot table, the R80 battery walk extends to the
# illusionist rows, the R129 census grows to 192, the R229
# audit_eval block walks the seam, and the PHB gap report
# flips the R229 box. 14 patches; idempotent (markers = the
# new content); zero backslashes. Run on dd44588 (R228+R228b
# landed). Level pins follow the printed TABLE (R183): six
# spell description headers print a divergent Level: (Dispel
# Illusion 3, Fear 3, Hallucinatory Terrain 3, Illusionary
# Script 3, Improved Invisibility 4, Massmorph 4) - the
# roster wins, recorded in the gap report.

NL = chr(10)
Q = chr(39)
BS = chr(92)
DQ = chr(34)
APPLIED = 0
ALREADY = 0

DATA = [
    ('Audible Glamer', 1, 5, 6, 3, 0, -1, 4),
    ('Detect Invisibility', 1, 1, 1, 5, 0, -1, 2),
    ('Change Self', 1, 1, 0, 2, 0, -1, 0),
    ('Gaze Reflection', 1, 1, 0, 1, 0, -1, 4),
    ('Hypnotism', 1, 1, 3, 1, 0, 4, 3),
    ('Light', 1, 1, 6, 10, 2, -1, 2),
    ('Phantasmal Force', 1, 1, 6, 0, 0, -1, 2),
    ('Wall Of Fog', 1, 1, 3, 2, 0, -1, 4),
    ('Blindness', 2, 2, 3, 0, 0, 4, 1),
    ('Blur', 2, 2, 0, 3, 0, -1, 0),
    ('Deafness', 2, 2, 6, 0, 0, 4, 1),
    ('Detect Magic', 2, 2, 0, 2, 0, -1, 2),
    ('Fog Cloud', 2, 2, 1, 4, 0, -1, 2),
    ('Hypnotic Pattern', 2, 2, 0, 0, 0, 4, 2),
    ('Improved Phantasmal Force', 2, 2, 6, 0, 0, -1, 2),
    ('Invisibility', 2, 2, 0, 0, 0, -1, 1),
    ('Dispel Illusion', 2, 3, 1, 0, 0, -1, 4),
    ('Magic Mouth', 2, 2, 0, 0, 0, -1, 4),
    ('Fear', 2, 4, 0, 0, 0, 4, 2),
    ('Mirror Image', 2, 2, 0, 3, 0, -1, 0),
    ('Hallucinatory Terrain', 2, 50, 2, 0, 0, -1, 2),
    ('Misdirection', 2, 2, 3, 1, 0, 4, 4),
    ('Illusionary Script', 2, 0, 0, 0, 0, -1, 1),
    ('Ventriloquism', 2, 2, 1, 4, 0, -1, 4),
    ('Invisibility, 10' + Q + ' Radius', 3, 3, 0, 0, 1, -1, 2),
    ('Continual Darkness', 3, 3, 6, 0, 3, -1, 2),
    ('Continual Light', 3, 3, 6, 0, 6, -1, 2),
    ('Non-detection', 3, 3, 0, 10, 0, -1, 0),
    ('Emotion', 3, 3, 1, 0, 0, 4, 2),
    ('Paralyzation', 3, 3, 1, 0, 0, 4, 2),
    ('Rope Trick', 3, 3, 0, 20, 0, -1, 4),
    ('Spectral Force', 3, 3, 6, 0, 0, -1, 2),
    ('Improved Invisibility', 3, 4, 0, 4, 0, -1, 1),
    ('Suggestion', 3, 3, 3, 40, 0, 4, 1),
    ('Massmorph', 3, 4, 1, 0, 0, -1, 2),
    ('Confusion', 4, 4, 8, 1, 0, -1, 2),
    ('Dispel Exhaustion', 4, 4, 0, 30, 0, -1, 3),
    ('Minor Creation', 4, 60, 0, 60, 0, -1, 4),
    ('Phantasmal Killer', 4, 4, 0, 1, 0, -1, 1),
    ('Shadow Monsters', 4, 4, 3, 1, 0, -1, 2),
    ('Chaos', 5, 5, 0, 1, 0, -1, 2),
    ('Demi-Shadow Monsters', 5, 5, 3, 1, 0, -1, 2),
    ('Major Creation', 5, 60, 1, 60, 0, -1, 4),
    ('Maze', 5, 5, 0, 0, 0, -1, 1),
    ('Projected Image', 5, 5, 0, 1, 0, -1, 4),
    ('Mass Suggestion', 5, 6, 3, 40, 0, 4, 3),
    ('Shadow Door', 5, 2, 1, 40, 0, -1, 4),
    ('Permanent Illusion', 5, 6, 1, 0, 0, -1, 2),
    ('Shadow Magic', 5, 5, 5, 0, 0, -1, 4),
    ('Programmed Illusion', 5, 6, 1, 0, 0, -1, 2),
    ('Summon Shadow', 5, 5, 1, 1, 0, -1, 2),
    ('Shades', 5, 6, 3, 1, 0, -1, 2),
    ('Conjure Animals', 6, 9, 3, 1, 0, -1, 4),
    ('True Sight', 6, 10, 0, 1, 0, -1, 1),
    ('Demi-Shadow Magic', 6, 5, 6, 0, 0, -1, 4),
    ('Veil', 6, 3, 1, 10, 0, -1, 2),
    ('Alter Reality', 7, 0, 0, 0, 0, -1, 0),
    ('Astral Spell', 7, 180, 0, 0, 0, -1, 4),
    ('Prismatic Spray', 7, 7, 0, 0, 0, -1, 2),
    ('Prismatic Wall', 7, 7, 1, 10, 0, -1, 4),
    ('Vision', 7, 7, 0, 0, 0, -1, 0),
]

ENAMES = ['IL_AUDIBLE_GLAMER', 'IL_DETECT_INVISIBILITY', 'IL_CHANGE_SELF', 'IL_GAZE_REFLECTION', 'IL_HYPNOTISM', 'IL_LIGHT', 'IL_PHANTASMAL_FORCE', 'IL_WALL_OF_FOG', 'IL_BLINDNESS', 'IL_BLUR', 'IL_DEAFNESS', 'IL_DETECT_MAGIC', 'IL_FOG_CLOUD', 'IL_HYPNOTIC_PATTERN', 'IL_IMPROVED_PHANTASMAL_FORCE', 'IL_INVISIBILITY', 'IL_DISPEL_ILLUSION', 'IL_MAGIC_MOUTH', 'IL_FEAR', 'IL_MIRROR_IMAGE', 'IL_HALLUCINATORY_TERRAIN', 'IL_MISDIRECTION', 'IL_ILLUSIONARY_SCRIPT', 'IL_VENTRILOQUISM', 'IL_INVISIBILITY_10_RADIUS', 'IL_CONTINUAL_DARKNESS', 'IL_CONTINUAL_LIGHT', 'IL_NON_DETECTION', 'IL_EMOTION', 'IL_PARALYZATION', 'IL_ROPE_TRICK', 'IL_SPECTRAL_FORCE', 'IL_IMPROVED_INVISIBILITY', 'IL_SUGGESTION', 'IL_MASSMORPH', 'IL_CONFUSION', 'IL_DISPEL_EXHAUSTION', 'IL_MINOR_CREATION', 'IL_PHANTASMAL_KILLER', 'IL_SHADOW_MONSTERS', 'IL_CHAOS', 'IL_DEMI_SHADOW_MONSTERS', 'IL_MAJOR_CREATION', 'IL_MAZE', 'IL_PROJECTED_IMAGE', 'IL_MASS_SUGGESTION', 'IL_SHADOW_DOOR', 'IL_PERMANENT_ILLUSION', 'IL_SHADOW_MAGIC', 'IL_PROGRAMMED_ILLUSION', 'IL_SUMMON_SHADOW', 'IL_SHADES', 'IL_CONJURE_ANIMALS', 'IL_TRUE_SIGHT', 'IL_DEMI_SHADOW_MAGIC', 'IL_VEIL', 'IL_ALTER_REALITY', 'IL_ASTRAL_SPELL', 'IL_PRISMATIC_SPRAY', 'IL_PRISMATIC_WALL', 'IL_VISION']
TGTC = {0: 'TARGET_SELF', 1: 'TARGET_CREATURE', 2: 'TARGET_AREA',
        3: 'TARGET_CREATURES', 4: 'TARGET_SPECIAL'}


def patch(path, marker, old, new):
    # the R228 pattern: marker = a unique single-line snippet
    # of the NEW content (absent pre-patch, present post)
    global APPLIED, ALREADY
    assert NL not in marker, 'marker spans a newline: ' + marker
    s = open(path).read()
    if marker in s:
        ALREADY += 1
        return
    if old not in s:
        raise SystemExit('R229 FAIL: %s anchor not found in %s'
                         % (marker, path))
    if s.count(old) != 1:
        raise SystemExit('R229 FAIL: %s anchor not unique in %s'
                         % (marker, path))
    t = s.replace(old, new)
    if marker not in t:
        raise SystemExit('R229 FAIL: %s marker missing post-patch'
                         % marker)
    open(path, 'w').write(t)
    APPLIED += 1


def lit(l):
    # an apostrophe is legal inside a C++ double-quoted
    # string - the R228 lesson: NEVER split on Q here
    assert DQ not in l and BS not in l, 'bad name: ' + l
    return DQ + l + DQ


# ---- the pre-assert: DATA matches the R183 roster ----
h = open('rules/illusionspells.h').read()
sec = h[h.index('kIllusionistSpells[61] = {'):]
sec = sec[:sec.index('};')]
roster = []
for t in sec.split(NL):
    t = t.strip()
    if t.startswith('{ ') and t.endswith(' },'):
        c1 = t.index(',')
        lv = int(t[2:c1])
        nm = t[c1 + 1:].split(DQ)[1]
        roster.append((lv, nm))
assert len(roster) == 61
assert [r[1] for r in roster] == [r[0] for r in DATA], 'name drift'
assert [r[0] for r in roster] == [r[1] for r in DATA], 'level drift'
assert len(DATA) == 61

# ---- 1: the parameter seam in rules/illusionspells.h ----
seam_lines = [
    '// ---------------------------------------------------------------------------',
    '// R229: the registry parameter seam. The R183 roster carries',
    '// identity (level, name - the illusionist print carries no',
    '// reversible markers); these tables carry the per-spell registry',
    '// parameters extracted from the PHB illusionist spell',
    '// description headers, in the engine SpellDef conventions',
    '// (the R228 druid conventions):',
    '//   - ct: casting time in SEGMENTS (a printed turn 60, a',
    '//     round 10; Special pins 0);',
    '//   - range: tens of feet (Touch/Unlimited/Special 0; a',
    '//     per-level scale pins its base; a printed half-inch',
    '//     pins 0);',
    '//   - dur: base ROUNDS (a per-level scale pins its base;',
    '//     Permanent/Special/Instantaneous 0; a turn 10);',
    '//   - aoe: radius in TENS of feet where the print gives a',
    '//     circle; squares/paths/cubes pin 0;',
    '//   - save: -1 none/Special; the printed Neg. pins',
    '//     SAVE_SPELLS = 4;',
    '//   - target: the SpellTarget enum value.',
    '// The OCR-scattered blocks pinned as JUDGMENTs (the section',
    '// interleaves neighbors; the q.v. MU/cleric prints close the',
    '// chains): Detect Invisibility (save None, the q.v. MU print),',
    '// Invisibility (the q.v. MU print: Touch/Special/CT 2/None),',
    '// Dispel Illusion (the resident 2nd-level set: 1"/level,',
    '// Permanent, Special, CT 3, None), Fear (CT 4/Neg., the q.v.',
    '// MU fear print), Hallucinatory Terrain (R 2"+2"/level,',
    '// D Special, AoE 4"x4", CT 5 rounds = 50, SV None),',
    "// Invisibility 10" + Q + " Radius (the q.v. MU 3rd print: Touch,",
    "// Special, CT 3, None, 10" + Q + " radius), Continual Light (CT 3/",
    '// None, the pair scattered into the Non-detection region),',
    '// Emotion (the twin Level-3 set: 1"/level, Special, 4"x4",',
    '// CT 3, Neg.), Mass Suggestion (R 3/CT 6 in its block; the',
    '// duration 4 turns + 4 turns/level and the one',
    '// creature/level area recovered from the mis-scattered',
    '// lines; SV Neg., the suggestion ladder), Permanent',
    '// Illusion (SV Special, the spectral force q.v.), Conjure',
    '// Animals (CT 9/None, the q.v. cleric 6th print),',
    '// Demi-Shadow Magic (CT 5/Special, the shadow magic q.v.),',
    "// Alter Reality (TARGET_SELF - the engine" + Q + "s MU row and the",
    "// R129 caster-aging convention; the print" + Q + "s AoE is Special).",
    '// Six blocks print a Level: divergent from the roster',
    '// (Dispel Illusion 3, Fear 3, Hallucinatory Terrain 3,',
    '// Illusionary Script 3, Improved Invisibility 4, Massmorph 4)',
    '// - the printed TABLE (R183) wins.',
    '// ---------------------------------------------------------------------------',
    'inline int illusionistSpellLevel(int i) {',
    '    static const int kLevel[61] = {',
    '        1, 1, 1, 1, 1, 1, 1, 1, 2, 2,',
    '        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,',
    '        2, 2, 2, 2, 3, 3, 3, 3, 3, 3,',
    '        3, 3, 3, 3, 3, 4, 4, 4, 4, 4,',
    '        5, 5, 5, 5, 5, 5, 5, 5, 5, 5,',
    '        5, 5, 6, 6, 6, 6, 7, 7, 7, 7,',
    '        7,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 60) i = 60;',
    '    return kLevel[i];',
    '}',
    'inline int illusionistSpellCt(int i) {',
    '    static const int kCt[61] = {',
    '        5, 1, 1, 1, 1, 1, 1, 1, 2, 2,',
    '        2, 2, 2, 2, 2, 2, 3, 2, 4, 2,',
    '        50, 2, 0, 2, 3, 3, 3, 3, 3, 3,',
    '        3, 3, 4, 3, 4, 4, 4, 60, 4, 4,',
    '        5, 5, 60, 5, 5, 6, 2, 6, 5, 6,',
    '        5, 6, 9, 10, 5, 3, 0, 180, 7, 7,',
    '        7,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 60) i = 60;',
    '    return kCt[i];',
    '}',
    'inline int illusionistSpellRangeTens(int i) {',
    '    static const int kRangeTens[61] = {',
    '        6, 1, 0, 0, 3, 6, 6, 3, 3, 0,',
    '        6, 0, 1, 0, 6, 0, 1, 0, 0, 0,',
    '        2, 3, 0, 1, 0, 6, 6, 0, 1, 1,',
    '        0, 6, 0, 3, 1, 8, 0, 0, 0, 3,',
    '        0, 3, 1, 0, 0, 3, 1, 1, 5, 1,',
    '        1, 3, 3, 0, 6, 1, 0, 0, 0, 1,',
    '        0,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 60) i = 60;',
    '    return kRangeTens[i];',
    '}',
    'inline int illusionistSpellDur(int i) {',
    '    static const int kDurRounds[61] = {',
    '        3, 5, 2, 1, 1, 10, 0, 2, 0, 3,',
    '        0, 2, 4, 0, 0, 0, 0, 0, 0, 3,',
    '        0, 1, 0, 4, 0, 0, 0, 10, 0, 0,',
    '        20, 0, 4, 40, 0, 1, 30, 60, 1, 1,',
    '        1, 1, 60, 0, 1, 40, 40, 0, 0, 0,',
    '        1, 1, 1, 1, 0, 10, 0, 0, 0, 10,',
    '        0,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 60) i = 60;',
    '    return kDurRounds[i];',
    '}',
    'inline int illusionistSpellAoeTens(int i) {',
    '    static const int kAoeTens[61] = {',
    '        0, 0, 0, 0, 0, 2, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 1, 3, 6, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 60) i = 60;',
    '    return kAoeTens[i];',
    '}',
    'inline int illusionistSpellSaveCat(int i) {',
    '    static const int kSaveCat[61] = {',
    '        -1, -1, -1, -1, 4, -1, -1, -1, 4, -1,',
    '        4, -1, -1, 4, -1, -1, -1, -1, 4, -1,',
    '        -1, 4, -1, -1, -1, -1, -1, -1, 4, 4,',
    '        -1, -1, -1, 4, -1, -1, -1, -1, -1, -1,',
    '        -1, -1, -1, -1, -1, 4, -1, -1, -1, -1,',
    '        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,',
    '        -1,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 60) i = 60;',
    '    return kSaveCat[i];',
    '}',
    'inline int illusionistSpellTarget(int i) {',
    '    static const int kTarget[61] = {',
    '        4, 2, 0, 4, 3, 2, 2, 4, 1, 0,',
    '        1, 2, 2, 2, 2, 1, 4, 4, 2, 0,',
    '        2, 4, 1, 4, 2, 2, 2, 0, 2, 2,',
    '        4, 2, 1, 1, 2, 2, 3, 4, 1, 2,',
    '        2, 2, 4, 1, 4, 3, 4, 2, 4, 2,',
    '        2, 2, 4, 1, 4, 2, 0, 4, 2, 4,',
    '        0,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 60) i = 60;',
    '    return kTarget[i];',
    '}'
]
seam_block = NL.join(seam_lines)
patch('rules/illusionspells.h', 'R229: the registry parameter seam',
      '    return kByLevel[spellLevel - 1];' + NL + '}' + NL + NL
      + '} // namespace rules',
      '    return kByLevel[spellLevel - 1];' + NL + '}' + NL + NL
      + seam_block + NL + '} // namespace rules')

# ---- 2: SpellClass ----
patch('spells/spells.h', 'SPELL_ILLUSIONIST,   // R229: the illusionist roster',
      '    SPELL_DRUID,   // R228: the druid roster' + NL
      + '    SPELL_CLASS_COUNT',
      '    SPELL_DRUID,   // R228: the druid roster' + NL
      + '    SPELL_ILLUSIONIST,   // R229: the illusionist roster' + NL
      + '    SPELL_CLASS_COUNT')

# ---- 3: the 61 IL_ ids ----
enum_lines = []
for e, r in zip(ENAMES, DATA):
    pad = ' ' * max(1, 27 - len(e))
    enum_lines.append('    ' + e + ',' + pad + '// illusionist '
                      + str(r[1]))
enum_block = NL.join(enum_lines)
patch('spells/spells.h', 'IL_AUDIBLE_GLAMER,',
      '    DR_TRANSMUTE_METAL_TO_WOOD, // druid 7' + NL
      + '    SPELL_COUNT',
      '    DR_TRANSMUTE_METAL_TO_WOOD, // druid 7' + NL
      + enum_block + NL + '    SPELL_COUNT')

# ---- 4: the include ----
patch('spells/spells.cpp', 'R229: the illusionist roster + parameter seam',
      '#include ' + DQ + '../rules/druidspells.h' + DQ
      + '  // R228: the druid roster + parameter seam',
      '#include ' + DQ + '../rules/druidspells.h' + DQ
      + '  // R228: the druid roster + parameter seam' + NL
      + '#include ' + DQ + '../rules/illusionspells.h' + DQ
      + '  // R229: the illusionist roster + parameter seam')

# ---- 5: the 61 registry rows ----
row_lines = ['    // ---- R229: the illusionist roster (61 spells;',
            '    // parameters per the rules/illusionspells.h R229',
            '    // seam - the PHB illusionist spell description',
            '    // headers; effects stay known, cast pending per',
            '    // the R80 utility convention) ----']
for nm, lv, ct, rg, du, ao, sv, tg in DATA:
    row = ('    { ' + lit(nm) + ', SPELL_ILLUSIONIST, ' + str(lv) + ', '
           + str(ct) + ', ' + str(rg) + ', ' + str(du) + ', '
           + str(sv) + ', ' + TGTC[tg] + ', ' + str(ao) + ', 0, 0, false },')
    row_lines.append(row)
rows_block = NL.join(row_lines)
patch('spells/spells.cpp', ', SPELL_ILLUSIONIST, 1, 5, 6, 3, -1, TARGET_SPECIAL,',
      '    { ' + DQ + 'Transmute Metal To Wood' + DQ
      + ', SPELL_DRUID, 7, 9, 8, 0, -1, TARGET_SPECIAL, 0, 0, 0, false },'
      + NL + '};',
      '    { ' + DQ + 'Transmute Metal To Wood' + DQ
      + ', SPELL_DRUID, 7, 9, 8, 0, -1, TARGET_SPECIAL, 0, 0, 0, false },'
      + NL + rows_block + NL + '};')

# ---- 6: the spellSlots delegation ----
patch('spells/spells.cpp', 'if (sc == SPELL_ILLUSIONIST)',
      '    if (sc == SPELL_DRUID)' + NL
      + '        return rules::druidSpellSlots(classLevel, spellLevel);',
      '    if (sc == SPELL_DRUID)' + NL
      + '        return rules::druidSpellSlots(classLevel, spellLevel);' + NL
      + '    // R229: the illusionist rows read the R183 slot' + NL
      + '    // table (illusionistSpellSlots clamps level 1-26,' + NL
      + '    // spell 1-7)' + NL
      + '    if (sc == SPELL_ILLUSIONIST)' + NL
      + '        return rules::illusionistSpellSlots(classLevel,'
      + ' spellLevel);')

# ---- 7: the R80 battery walk (var + class check + counts) ----
patch('regtest.cpp', 'int bad = 0, mu = 0, cl = 0, dr = 0, il = 0, l46 = 0;',
      '        int bad = 0, mu = 0, cl = 0, dr = 0, l46 = 0;',
      '        int bad = 0, mu = 0, cl = 0, dr = 0, il = 0, l46 = 0;')
patch('regtest.cpp', 'R229: the illusionist rows ride',
      '            // R228: the druid registry rows ride' + NL
      + '            // SPELL_DRUID (77 spells, levels 1-7)' + NL
      + '            if (s.sclass != spells::SPELL_MU &&' + NL
      + '                s.sclass != spells::SPELL_CLERIC &&' + NL
      + '                s.sclass != spells::SPELL_DRUID) ++bad;' + NL
      + '            if (s.sclass == spells::SPELL_MU) ++mu;' + NL
      + '            else if (s.sclass == spells::SPELL_DRUID) ++dr;' + NL
      + '            else ++cl;',
      '            // R228: the druid registry rows ride' + NL
      + '            // SPELL_DRUID (77 spells, levels 1-7);' + NL
      + '            // R229: the illusionist rows ride' + NL
      + '            // SPELL_ILLUSIONIST (61 spells)' + NL
      + '            if (s.sclass != spells::SPELL_MU &&' + NL
      + '                s.sclass != spells::SPELL_CLERIC &&' + NL
      + '                s.sclass != spells::SPELL_DRUID &&' + NL
      + '                s.sclass != spells::SPELL_ILLUSIONIST) ++bad;' + NL
      + '            if (s.sclass == spells::SPELL_MU) ++mu;' + NL
      + '            else if (s.sclass == spells::SPELL_DRUID) ++dr;' + NL
      + '            else if (s.sclass == spells::SPELL_ILLUSIONIST)'
      + ' ++il;' + NL
      + '            else ++cl;')

# ---- 8: the R80 cellwise walk + printf ----
walk_new = (
    '        // R228: the druid rows match the R182 roster' + NL
    + '        // cell by cell (level, reversible, class)' + NL
    + '        for (int i = 0; i < rules::druidSpellTotal(); ++i) {' + NL
    + '            const spells::SpellDef& s = spells::spell(' + NL
    + '                (spells::SpellId)(' + NL
    + '                    spells::DR_ANIMAL_FRIENDSHIP + i));' + NL
    + '            if (s.level != rules::druidSpell(i).level ||' + NL
    + '                (s.reversible ? 1 : 0) !=' + NL
    + '                    rules::druidSpell(i).reversible ||' + NL
    + '                s.sclass != spells::SPELL_DRUID) ++bad;' + NL
    + '        }' + NL
    + '        // R229: the illusionist rows match the R183' + NL
    + '        // roster cell by cell (level, class; the' + NL
    + '        // illusionist print carries no reversible' + NL
    + '        // markers)' + NL
    + '        for (int i = 0; i < rules::illusionistSpellTotal(); ++i) {'
    + NL
    + '            const spells::SpellDef& s = spells::spell(' + NL
    + '                (spells::SpellId)(' + NL
    + '                    spells::IL_AUDIBLE_GLAMER + i));' + NL
    + '            if (s.level != rules::illusionistSpell(i).level ||' + NL
    + '                s.sclass != spells::SPELL_ILLUSIONIST) ++bad;' + NL
    + '        }')
patch('regtest.cpp', 'R229: the illusionist rows match the R183',
      '        // R228: the druid rows match the R182 roster' + NL
      + '        // cell by cell (level, reversible, class)' + NL
      + '        for (int i = 0; i < rules::druidSpellTotal(); ++i) {' + NL
      + '            const spells::SpellDef& s = spells::spell(' + NL
      + '                (spells::SpellId)(' + NL
      + '                    spells::DR_ANIMAL_FRIENDSHIP + i));' + NL
      + '            if (s.level != rules::druidSpell(i).level ||' + NL
      + '                (s.reversible ? 1 : 0) !=' + NL
      + '                    rules::druidSpell(i).reversible ||' + NL
      + '                s.sclass != spells::SPELL_DRUID) ++bad;' + NL
      + '        }',
      walk_new)
patch('regtest.cpp', '(MU %d, CL %d, DR %d, IL %d)',
      '        printf(' + DQ + 'R80 spells audit: %d spells (MU %d, CL %d, DR %d), '
      + DQ + NL
      + '               ' + DQ + 'L4-6 %d, bad %d' + BS + 'n' + DQ + ',' + NL
      + '               spells::SPELL_COUNT, mu, cl, dr, l46, bad);',
      '        printf(' + DQ + 'R80 spells audit: %d spells (MU %d, CL %d, DR %d, IL %d), '
      + DQ + NL
      + '               ' + DQ + 'L4-6 %d, bad %d' + BS + 'n' + DQ + ',' + NL
      + '               spells::SPELL_COUNT, mu, cl, dr, il, l46, bad);')

# ---- 9: the R129 census grows to 192 ----
patch('regtest.cpp', 'SPELL_COUNT != 192',
      '        // the registry grew to 131 (R228): MU 31, CL 23, DR 77'
      + NL
      + '        if (spells::SPELL_COUNT != 131) ++bad;',
      '        // the registry grew to 192 (R229): MU 31, CL 23,' + NL
      + '        // DR 77, IL 61' + NL
      + '        if (spells::SPELL_COUNT != 192) ++bad;')
patch('regtest.cpp', 'il != 61',
      '            int mu = 0, cl = 0, dr = 0;' + NL
      + '            for (int id = 0; id < spells::SPELL_COUNT; ++id) {'
      + NL
      + '                const spells::SpellDef& s =' + NL
      + '                    spells::spell((spells::SpellId)id);' + NL
      + '                if (s.sclass == spells::SPELL_MU) ++mu;' + NL
      + '                else if (s.sclass == spells::SPELL_DRUID) ++dr;'
      + NL
      + '                else ++cl;' + NL
      + '            }' + NL
      + '            if (mu != 31 || cl != 23 || dr != 77) ++bad;',
      '            int mu = 0, cl = 0, dr = 0, il = 0;' + NL
      + '            for (int id = 0; id < spells::SPELL_COUNT; ++id) {'
      + NL
      + '                const spells::SpellDef& s =' + NL
      + '                    spells::spell((spells::SpellId)id);' + NL
      + '                if (s.sclass == spells::SPELL_MU) ++mu;' + NL
      + '                else if (s.sclass == spells::SPELL_DRUID) ++dr;'
      + NL
      + '                else if (s.sclass =='
      + ' spells::SPELL_ILLUSIONIST) ++il;' + NL
      + '                else ++cl;' + NL
      + '            }' + NL
      + '            if (mu != 31 || cl != 23 || dr != 77 ||' + NL
      + '                il != 61) ++bad;')

# ---- 10: the R229 audit block ----
audit_lines = [
    '    // ---- R229: the illusionist registry parameters audit ----',
    '    // The evaluable seam walk: the rules/illusionspells.h',
    '    // R229 parameter tables vs the book-pin arrays (the',
    '    // PHB illusionist spell description headers; the',
    '    // OCR-scattered blocks pinned as JUDGMENTs). The',
    '    // registry rows themselves are walked by the extended',
    '    // R80 battery block - spells.cpp structs are outside',
    '    // the audit_eval subset.',
    '    {',
    '        int bad = 0;',
    '        static const int kLv[61] = {',
    '            1, 1, 1, 1, 1, 1, 1, 1, 2, 2,',
    '            2, 2, 2, 2, 2, 2, 2, 2, 2, 2,',
    '            2, 2, 2, 2, 3, 3, 3, 3, 3, 3,',
    '            3, 3, 3, 3, 3, 4, 4, 4, 4, 4,',
    '            5, 5, 5, 5, 5, 5, 5, 5, 5, 5,',
    '            5, 5, 6, 6, 6, 6, 7, 7, 7, 7,',
    '            7,',
    '        };',
    '        static const int kCt[61] = {',
    '            5, 1, 1, 1, 1, 1, 1, 1, 2, 2,',
    '            2, 2, 2, 2, 2, 2, 3, 2, 4, 2,',
    '            50, 2, 0, 2, 3, 3, 3, 3, 3, 3,',
    '            3, 3, 4, 3, 4, 4, 4, 60, 4, 4,',
    '            5, 5, 60, 5, 5, 6, 2, 6, 5, 6,',
    '            5, 6, 9, 10, 5, 3, 0, 180, 7, 7,',
    '            7,',
    '        };',
    '        static const int kRg[61] = {',
    '            6, 1, 0, 0, 3, 6, 6, 3, 3, 0,',
    '            6, 0, 1, 0, 6, 0, 1, 0, 0, 0,',
    '            2, 3, 0, 1, 0, 6, 6, 0, 1, 1,',
    '            0, 6, 0, 3, 1, 8, 0, 0, 0, 3,',
    '            0, 3, 1, 0, 0, 3, 1, 1, 5, 1,',
    '            1, 3, 3, 0, 6, 1, 0, 0, 0, 1,',
    '            0,',
    '        };',
    '        static const int kDu[61] = {',
    '            3, 5, 2, 1, 1, 10, 0, 2, 0, 3,',
    '            0, 2, 4, 0, 0, 0, 0, 0, 0, 3,',
    '            0, 1, 0, 4, 0, 0, 0, 10, 0, 0,',
    '            20, 0, 4, 40, 0, 1, 30, 60, 1, 1,',
    '            1, 1, 60, 0, 1, 40, 40, 0, 0, 0,',
    '            1, 1, 1, 1, 0, 10, 0, 0, 0, 10,',
    '            0,',
    '        };',
    '        static const int kAo[61] = {',
    '            0, 0, 0, 0, 0, 2, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 1, 3, 6, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0,',
    '        };',
    '        static const int kSv[61] = {',
    '            -1, -1, -1, -1, 4, -1, -1, -1, 4, -1,',
    '            4, -1, -1, 4, -1, -1, -1, -1, 4, -1,',
    '            -1, 4, -1, -1, -1, -1, -1, -1, 4, 4,',
    '            -1, -1, -1, 4, -1, -1, -1, -1, -1, -1,',
    '            -1, -1, -1, -1, -1, 4, -1, -1, -1, -1,',
    '            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,',
    '            -1,',
    '        };',
    '        static const int kTg[61] = {',
    '            4, 2, 0, 4, 3, 2, 2, 4, 1, 0,',
    '            1, 2, 2, 2, 2, 1, 4, 4, 2, 0,',
    '            2, 4, 1, 4, 2, 2, 2, 0, 2, 2,',
    '            4, 2, 1, 1, 2, 2, 3, 4, 1, 2,',
    '            2, 2, 4, 1, 4, 3, 4, 2, 4, 2,',
    '            2, 2, 4, 1, 4, 2, 0, 4, 2, 4,',
    '            0,',
    '        };',
    '        for (int i = 0; i < 61; ++i)',
    '            if (rules::illusionistSpellLevel(i) != kLv[i] ||',
    '                rules::illusionistSpellCt(i) != kCt[i] ||',
    '                rules::illusionistSpellRangeTens(i) != kRg[i] ||',
    '                rules::illusionistSpellDur(i) != kDu[i] ||',
    '                rules::illusionistSpellAoeTens(i) != kAo[i] ||',
    '                rules::illusionistSpellSaveCat(i) != kSv[i] ||',
    '                rules::illusionistSpellTarget(i) != kTg[i]) ++bad;',
    '        // the clamps: -5 and 99 read rows 0 and 60',
    '        if (rules::illusionistSpellLevel(-5) != kLv[0] ||',
    '            rules::illusionistSpellLevel(99) != kLv[60] ||',
    '            rules::illusionistSpellCt(99) != kCt[60]) ++bad;',
    '        // the level histogram ladder: the seam pins the',
    '        // printed roster counts (8/16/11/5/12/4/5 - R183);',
    '        // every seam level sits in 1..7',
    '        static const int kHist[7] = { 8, 16, 11, 5, 12, 4, 5 };',
    '        for (int l = 1; l <= 7; ++l)',
    '            if (rules::illusionistSpellCountByLevel(l) != kHist[l - 1]) ++bad;',
    '        for (int i = 0; i < 61; ++i)',
    '            if (rules::illusionistSpellLevel(i) < 1 ||',
    '                rules::illusionistSpellLevel(i) > 7) ++bad;',
    '        // the R183 slot table cross-checks (past 26 the',
    '        // table clamps to the 26th row; a spell-level 8',
    '        // query clamps to the 7th)',
    '        if (rules::illusionistSpellSlots(1, 1) != 1 ||',
    '            rules::illusionistSpellSlots(5, 2) != 2 ||',
    '            rules::illusionistSpellSlots(12, 4) != 3 ||',
    '            rules::illusionistSpellSlots(26, 7) != 6 ||',
    '            rules::illusionistSpellSlots(30, 8) != 6) ++bad;',
    '        printf(' + DQ + 'R229 illusionist registry parameters audit: bad %d' + BS + 'n' + DQ + ', bad);',
    '        if (bad) return 1;',
    '    }'
]
audit_block = NL.join(audit_lines)
patch('regtest.cpp', 'R229: the illusionist registry parameters audit',
      '    // ---- R163: the poison table audit -------------',
      audit_block + NL
      + '    // ---- R163: the poison table audit -------------')

# ---- 11: the PHB gap report flips the R229 box ----
gap_lines = [
    '- [x] R229 the illusionist roster joins the',
    '      SpellId registry - WIRED: 61 IL_ ids appended after',
    '      DR_TRANSMUTE_METAL_TO_WOOD (saved knownSpells',
    '      indices stay valid); SPELL_ILLUSIONIST joins',
    '      SpellClass; 61 kSpells rows with the PHB',
    '      illusionist spell-description header parameters',
    '      (the R228 druid conventions); the parameters',
    '      also land as the evaluable seam in',
    '      rules/illusionspells.h (seven clamped accessors -',
    '      no reversible markers in the illusionist print)',
    '      and spellSlots(SPELL_ILLUSIONIST, ...) delegates',
    '      to the R183 illusionistSpellSlots (levels 1-26,',
    '      spell 1-7 clamped). Effects stay',
    '      known-cast-pending (the R80 convention); the R80',
    '      battery walk extends to the illusionist rows and',
    '      checks them against the R183 roster cell by cell.',
    '      Thirteen OCR-scattered blocks pinned as JUDGMENTs',
    '      (the section interleaves neighbors; the q.v. MU/',
    '      cleric prints close the chains); six blocks print',
    '      a Level: divergent from the roster (Dispel',
    '      Illusion 3, Fear 3, Hallucinatory Terrain 3,',
    '      Illusionary Script 3, Improved Invisibility 4,',
    '      Massmorph 4) - the printed TABLE wins. Census 145.'
]
gap_new = NL.join(gap_lines)
gap_old = NL.join([
    '- [ ] R229 the illusionist roster joins the',
    '      SpellId registry (61 spells, the same seam',
    '      shape as R228).',
])
patch('tools/phb_gap_report.md', '- [x] R229 the illusionist roster joins the', gap_old, gap_new)

assert APPLIED + ALREADY == 14, 'patch count drift'
print('R229 splice: ALL OK (applied %d, already %d)'
      % (APPLIED, ALREADY))
print('R229 note: 14 patches; 61 illusionist spells join the'
      ' registry - ids, rows, the parameter seam, the slot')
print('delegation and the battery walks; census 145.')
print('commit: R229: the illusionist roster joins the SpellId'
      ' registry - 61 spells wired, the R183 layer live'
      ' (census 145)')

