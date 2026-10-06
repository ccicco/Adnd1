#!/usr/bin/env python3
# R228 splice: the druid roster joins the
# SpellId registry - the wiring arc box 2.
# The R182 roster was identity-only dead
# data; this round makes the 77 druid spells
# REAL registry spells: the parameter seam
# (rules/druidspells.h, eight clamped
# accessors - the evaluable audit_eval
# subset), SPELL_DRUID + 77 DR_ ids
# (spells.h), 77 kSpells rows + the
# spellSlots(SPELL_DRUID) delegation
# (spells.cpp), the R80 battery walk
# extended to the druid rows and checked
# against the R182 roster, the R228 seam
# audit. Parameters from the PHB spell
# description headers; eight OCR-scattered
# blocks pinned as JUDGMENTs (documented
# in the seam comment). Effects stay
# known-cast-pending (the R80 convention).
# Patches: 12. Census 143 -> 144.

NL = chr(10)
Q = chr(39)
BS = chr(92)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


def patch(path, marker, old, new):
    global applied, already
    try:
        t = rd(path)
    except IOError:
        assert old is None, 'anchor patch on absent file: ' + marker
        assert marker in new, 'marker missing in new file: ' + marker
        wr(path, new)
        applied += 1
        return
    if marker in t:
        already += 1
        return
    assert marker not in t, 'marker must be absent pre-patch: ' + marker
    assert t.count(old) == 1, 'anchor not unique in ' + path + ': ' + marker
    t = t.replace(old, new)
    assert marker in t, 'marker missing post-patch in ' + path
    assert NL not in marker, 'marker spans a newline: ' + marker
    wr(path, t)
    applied += 1


DATA = [
    ('Animal Friendship', 1, 0, 360, 1, 0, 0, 4, 1),
    ('Detect Magic', 1, 0, 3, 0, 12, 0, -1, 2),
    ('Detect Snares & Pits', 1, 0, 3, 0, 4, 0, -1, 2),
    ('Entangle', 1, 0, 3, 8, 10, 2, -1, 2),
    ('Faerie Fire', 1, 0, 3, 8, 4, 4, -1, 2),
    ('Invisibility To Animals', 1, 0, 4, 0, 10, 0, -1, 1),
    ('Locate Animals', 1, 0, 10, 0, 1, 0, -1, 2),
    ('Pass Without Trace', 1, 0, 10, 0, 10, 0, -1, 1),
    ('Predict Weather', 1, 0, 10, 0, 120, 0, -1, 4),
    ('Purify Water', 1, 1, 10, 4, 0, 0, -1, 2),
    ('Shillelagh', 1, 0, 1, 0, 1, 0, -1, 4),
    ('Speak With Animals', 1, 0, 3, 0, 2, 0, -1, 1),
    ('Barkskin', 2, 0, 3, 0, 4, 0, -1, 1),
    ('Charm Person Or Mammal', 2, 0, 4, 8, 0, 0, 4, 1),
    ('Create Water', 2, 0, 60, 1, 0, 0, -1, 2),
    ('Cure Light Wounds', 2, 1, 4, 0, 0, 0, -1, 1),
    ('Feign Death', 2, 0, 3, 1, 4, 0, -1, 1),
    ('Fire Trap', 2, 0, 60, 0, 0, 0, 4, 4),
    ('Heat Metal', 2, 1, 4, 4, 7, 0, -1, 4),
    ('Locate Plants', 2, 0, 10, 0, 10, 1, -1, 2),
    ('Obscurement', 2, 0, 4, 0, 4, 0, -1, 4),
    ('Produce Flame', 2, 0, 4, 0, 2, 0, -1, 4),
    ('Trip', 2, 0, 4, 0, 10, 0, 4, 4),
    ('Warp Wood', 2, 0, 4, 1, 0, 0, -1, 4),
    ('Call Lightning', 3, 0, 60, 0, 10, 36, 4, 2),
    ('Cure Disease', 3, 1, 10, 0, 0, 0, -1, 1),
    ('Hold Animal', 3, 0, 5, 8, 2, 0, 4, 1),
    ('Neutralize Poison', 3, 1, 5, 0, 0, 0, -1, 1),
    ('Plant Growth', 3, 0, 10, 16, 0, 0, -1, 2),
    ('Protection From Fire', 3, 0, 5, 0, 0, 0, -1, 1),
    ('Pyrotechnics', 3, 0, 5, 16, 0, 0, -1, 4),
    ('Snare', 3, 0, 30, 0, 0, 1, -1, 2),
    ('Stone Shape', 3, 0, 10, 0, 0, 0, -1, 2),
    ('Summon Insects', 3, 0, 10, 3, 1, 0, -1, 4),
    ('Tree', 3, 0, 5, 0, 60, 0, -1, 0),
    ('Water Breathing', 3, 1, 5, 0, 60, 0, -1, 1),
    ('Animal Summoning I', 4, 0, 6, 4, 0, 0, -1, 4),
    ('Call Woodland Beings', 4, 0, 0, 12, 0, 0, 4, 4),
    ('Control Temperature, 10' + Q + ' Radius', 4, 0, 6, 0, 40, 1, -1, 2),
    ('Cure Serious Wounds', 4, 1, 6, 0, 0, 0, -1, 1),
    ('Dispel Magic', 4, 0, 6, 8, 0, 0, -1, 2),
    ('Hallucinatory Forest', 4, 1, 6, 8, 0, 0, -1, 2),
    ('Hold Plant', 4, 0, 6, 8, 1, 0, 4, 4),
    ('Plant Door', 4, 0, 6, 0, 10, 0, -1, 4),
    ('Produce Fire', 4, 1, 6, 4, 1, 0, -1, 2),
    ('Protection From Lightning', 4, 0, 6, 0, 0, 0, -1, 1),
    ('Repel Insects', 4, 0, 10, 0, 10, 1, -1, 2),
    ('Speak With Plants', 4, 0, 60, 0, 2, 4, -1, 2),
    ('Animal Growth', 5, 1, 7, 8, 2, 0, -1, 2),
    ('Animal Summoning II', 5, 0, 7, 6, 0, 0, -1, 4),
    ('Anti-Plant Shell', 5, 0, 7, 0, 10, 1, -1, 2),
    ('Commune With Nature', 5, 0, 60, 0, 0, 0, -1, 4),
    ('Control Winds', 5, 0, 7, 0, 10, 0, -1, 2),
    ('Insect Plague', 5, 0, 5, 32, 10, 2, -1, 2),
    ('Wall of Fire', 5, 0, 60, 8, 0, 0, -1, 4),
    ('Pass Plant', 5, 0, 7, 0, 0, 0, -1, 4),
    ('Animal Summoning III', 6, 0, 8, 8, 0, 0, -1, 4),
    ('Anti-Animal Shell', 6, 0, 10, 0, 10, 1, -1, 2),
    ('Sticks to Snakes', 6, 1, 7, 4, 2, 0, -1, 2),
    ('Conjure Fire Elemental', 6, 1, 60, 8, 10, 0, -1, 4),
    ('Transmute Rock to Mud', 6, 1, 7, 16, 0, 0, -1, 2),
    ('Cure Critical Wounds', 6, 1, 8, 0, 0, 0, -1, 1),
    ('Feeblemind', 6, 0, 8, 16, 0, 0, 4, 1),
    ('Transport Via Plants', 6, 0, 3, 0, 0, 0, -1, 4),
    ('Turn Wood', 6, 0, 8, 0, 4, 0, -1, 2),
    ('Wall of Thorns', 6, 0, 8, 8, 10, 0, -1, 2),
    ('Weather Summoning', 6, 0, 60, 0, 0, 0, -1, 4),
    ('Confusion', 6, 0, 60, 8, 1, 0, -1, 2),
    ('Animate Rock', 7, 0, 60, 4, 1, 0, -1, 4),
    ('Conjure Earth Elemental', 7, 1, 9, 4, 10, 0, -1, 4),
    ('Control Weather', 7, 0, 60, 0, 0, 0, -1, 4),
    ('Chariot Of Sustarre', 7, 0, 60, 1, 60, 0, -1, 4),
    ('Creeping Doom', 7, 0, 9, 0, 4, 0, -1, 4),
    ('Finger Of Death', 7, 0, 5, 6, 0, 0, 4, 1),
    ('Fire Storm', 7, 1, 9, 16, 1, 0, 4, 2),
    ('Reincarnate', 7, 0, 60, 0, 0, 0, -1, 1),
    ('Transmute Metal To Wood', 7, 0, 9, 8, 0, 0, -1, 4),
]
ENUMS = [    'DR_ANIMAL_FRIENDSHIP',
    'DR_DETECT_MAGIC',
    'DR_DETECT_SNARES_AND_PITS',
    'DR_ENTANGLE',
    'DR_FAERIE_FIRE',
    'DR_INVISIBILITY_TO_ANIMALS',
    'DR_LOCATE_ANIMALS',
    'DR_PASS_WITHOUT_TRACE',
    'DR_PREDICT_WEATHER',
    'DR_PURIFY_WATER',
    'DR_SHILLELAGH',
    'DR_SPEAK_WITH_ANIMALS',
    'DR_BARKSKIN',
    'DR_CHARM_PERSON_OR_MAMMAL',
    'DR_CREATE_WATER',
    'DR_CURE_LIGHT_WOUNDS',
    'DR_FEIGN_DEATH',
    'DR_FIRE_TRAP',
    'DR_HEAT_METAL',
    'DR_LOCATE_PLANTS',
    'DR_OBSCUREMENT',
    'DR_PRODUCE_FLAME',
    'DR_TRIP',
    'DR_WARP_WOOD',
    'DR_CALL_LIGHTNING',
    'DR_CURE_DISEASE',
    'DR_HOLD_ANIMAL',
    'DR_NEUTRALIZE_POISON',
    'DR_PLANT_GROWTH',
    'DR_PROTECTION_FROM_FIRE',
    'DR_PYROTECHNICS',
    'DR_SNARE',
    'DR_STONE_SHAPE',
    'DR_SUMMON_INSECTS',
    'DR_TREE',
    'DR_WATER_BREATHING',
    'DR_ANIMAL_SUMMONING_I',
    'DR_CALL_WOODLAND_BEINGS',
    'DR_CONTROL_TEMPERATURE_10_RADIUS',
    'DR_CURE_SERIOUS_WOUNDS',
    'DR_DISPEL_MAGIC',
    'DR_HALLUCINATORY_FOREST',
    'DR_HOLD_PLANT',
    'DR_PLANT_DOOR',
    'DR_PRODUCE_FIRE',
    'DR_PROTECTION_FROM_LIGHTNING',
    'DR_REPEL_INSECTS',
    'DR_SPEAK_WITH_PLANTS',
    'DR_ANIMAL_GROWTH',
    'DR_ANIMAL_SUMMONING_II',
    'DR_ANTI_PLANT_SHELL',
    'DR_COMMUNE_WITH_NATURE',
    'DR_CONTROL_WINDS',
    'DR_INSECT_PLAGUE',
    'DR_WALL_OF_FIRE',
    'DR_PASS_PLANT',
    'DR_ANIMAL_SUMMONING_III',
    'DR_ANTI_ANIMAL_SHELL',
    'DR_STICKS_TO_SNAKES',
    'DR_CONJURE_FIRE_ELEMENTAL',
    'DR_TRANSMUTE_ROCK_TO_MUD',
    'DR_CURE_CRITICAL_WOUNDS',
    'DR_FEEBLEMIND',
    'DR_TRANSPORT_VIA_PLANTS',
    'DR_TURN_WOOD',
    'DR_WALL_OF_THORNS',
    'DR_WEATHER_SUMMONING',
    'DR_CONFUSION',
    'DR_ANIMATE_ROCK',
    'DR_CONJURE_EARTH_ELEMENTAL',
    'DR_CONTROL_WEATHER',
    'DR_CHARIOT_OF_SUSTARRE',
    'DR_CREEPING_DOOM',
    'DR_FINGER_OF_DEATH',
    'DR_FIRE_STORM',
    'DR_REINCARNATE',
    'DR_TRANSMUTE_METAL_TO_WOOD',]

DQ = chr(34)
TGTC = {0: 'TARGET_SELF', 1: 'TARGET_CREATURE', 2: 'TARGET_AREA',
        3: 'TARGET_CREATURES', 4: 'TARGET_SPECIAL'}
names = [r[0] for r in DATA]
lvls  = [r[1] for r in DATA]
revs  = [r[2] for r in DATA]
cts   = [r[3] for r in DATA]
rngs  = [r[4] for r in DATA]
durs  = [r[5] for r in DATA]
aoes  = [r[6] for r in DATA]
saves = [r[7] for r in DATA]
tgts  = [r[8] for r in DATA]
def arr(name, vals, per):
    out = ['    static const int ' + name + '[77] = {']
    for i in range(0, 77, per):
        out.append('        ' + ', '.join(str(v) for v in vals[i:i+per]) + ',')
    out.append('    };')
    return NL.join(out)
def aud(name, vals, per):
    out = ['        static const int ' + name + '[77] = {']
    for i in range(0, 77, per):
        out.append('            ' + ', '.join(str(v) for v in vals[i:i+per]) + ',')
    out.append('        };')
    return NL.join(out)
def cstr(s):
    if Q in s:
        pre, post = s.split(Q)
        return DQ + pre + Q + post + DQ
    return DQ + s + DQ

# ---- the pre-assert: DATA matches the R182 roster ----
hdr = rd('rules/druidspells.h')
roster = []
for ln in hdr.split(NL):
    ln = ln.strip()
    if not (ln.startswith('{ ') and ln.endswith(' },')):
        continue
    inner = ln[2:-3]
    parts = inner.split(DQ)
    if len(parts) != 3:
        continue
    roster.append((int(parts[0].strip().rstrip(',')), parts[1], int(parts[2].strip().lstrip(','))))
assert len(roster) == 77, 'roster parse: ' + str(len(roster))
for i, (lv, nm, rv) in enumerate(roster):
    assert (DATA[i][0] == nm and DATA[i][1] == lv and DATA[i][2] == rv), (
        'roster mismatch at ' + str(i) + ': ' + nm)
assert len(set(ENUMS)) == 77 and len(ENUMS) == len(DATA)
if 'R228: the registry parameter seam' not in hdr:
    for nm in ('kLevel', 'kRev', 'kCt', 'kRng', 'kDur', 'kAoe', 'kSave', 'kTgt'):
        assert (nm + '[77]') not in hdr, 'seam collision: ' + nm

seam_lines = []
seam_lines.append('// ---------------------------------------------------------------------------')
seam_lines.append('// R228: the registry parameter seam. The R182 roster carries')
seam_lines.append('// identity (level, name, reversible); these tables carry the')
seam_lines.append('// per-spell registry parameters extracted from the PHB spell')
seam_lines.append('// description headers (Level/Range/Duration/Area of')
seam_lines.append('// Effect/Casting Time/Saving Throw blocks), in the engine')
seam_lines.append('// SpellDef conventions:')
seam_lines.append('//   - ct: casting time in SEGMENTS (a printed turn is 60,')
seam_lines.append('//     a printed round 10; Special pins 0);')
seam_lines.append('//   - range: tens of feet (Touch pins 0);')
seam_lines.append('//   - dur: base ROUNDS (a per-level scale pins its base')
seam_lines.append('//     number - the scaling itself is an effects-round')
seam_lines.append('//     concern; Permanent/Special pin 0; a turn is 10);')
seam_lines.append('//   - aoe: radius in TENS of feet where the print gives a')
seam_lines.append('//     circle (diameter halves, round up); paths, cubes,')
seam_lines.append('//     linear feet and square miles pin 0;')
seam_lines.append('//   - save: rules::SaveCategory (-1 none; the printed')
seam_lines.append('//     Neg./half pins SAVE_SPELLS = 4);')
seam_lines.append('//   - target: the SpellTarget enum value.')
seam_lines.append('// JUDGMENTs (the OCR-scattered blocks): Entangle (table-form')
seam_lines.append('// header read directly), Invisibility To Animals, Faerie Fire,')
seam_lines.append('// Insect Plague (mirrors the cleric q.v. row: ct 5, save')
seam_lines.append('// none), Conjure Fire Elemental (ct 6 rounds = 60; save')
seam_lines.append('// none), Weather Summoning (ct 1 turn = 60, the')
seam_lines.append('// control-weather q.v.), Animate Rock (ct 1 turn = 60, save')
seam_lines.append('// none), Conjure Earth Elemental (ct 9 segments, save none).')
seam_lines.append('// The spells.cpp registry rows carry the same values; the')
seam_lines.append('// R228 battery walks the match.')
seam_lines.append('// ---------------------------------------------------------------------------')
seam_lines.append('')
seam_lines.append('')
seam_lines.append('inline int druidSpellLevel(int i) {')
seam_lines.append('    ' + arr('kLevel', lvls, 10) + NL + '    if (i < 0) i = 0;' + NL + '    if (i > 76) i = 76;' + NL + '    return kLevel[i];' + NL + '}')
seam_lines.append('')
seam_lines.append('inline int druidSpellRev(int i) {')
seam_lines.append('    ' + arr('kRev', revs, 10) + NL + '    if (i < 0) i = 0;' + NL + '    if (i > 76) i = 76;' + NL + '    return kRev[i];' + NL + '}')
seam_lines.append('')
seam_lines.append('inline int druidSpellCt(int i) {')
seam_lines.append('    ' + arr('kCt', cts, 10) + NL + '    if (i < 0) i = 0;' + NL + '    if (i > 76) i = 76;' + NL + '    return kCt[i];' + NL + '}')
seam_lines.append('')
seam_lines.append('inline int druidSpellRangeTens(int i) {')
seam_lines.append('    ' + arr('kRng', rngs, 10) + NL + '    if (i < 0) i = 0;' + NL + '    if (i > 76) i = 76;' + NL + '    return kRng[i];' + NL + '}')
seam_lines.append('')
seam_lines.append('inline int druidSpellDur(int i) {')
seam_lines.append('    ' + arr('kDur', durs, 10) + NL + '    if (i < 0) i = 0;' + NL + '    if (i > 76) i = 76;' + NL + '    return kDur[i];' + NL + '}')
seam_lines.append('')
seam_lines.append('inline int druidSpellAoeTens(int i) {')
seam_lines.append('    ' + arr('kAoe', aoes, 10) + NL + '    if (i < 0) i = 0;' + NL + '    if (i > 76) i = 76;' + NL + '    return kAoe[i];' + NL + '}')
seam_lines.append('')
seam_lines.append('inline int druidSpellSaveCat(int i) {')
seam_lines.append('    ' + arr('kSave', saves, 10) + NL + '    if (i < 0) i = 0;' + NL + '    if (i > 76) i = 76;' + NL + '    return kSave[i];' + NL + '}')
seam_lines.append('')
seam_lines.append('inline int druidSpellTarget(int i) {')
seam_lines.append('    ' + arr('kTgt', tgts, 10) + NL + '    if (i < 0) i = 0;' + NL + '    if (i > 76) i = 76;' + NL + '    return kTgt[i];' + NL + '}')
seam = NL.join(seam_lines)

seam_anchor_old = ('    return kByLevel[spellLevel - 1];' + NL + '}' + NL + NL
                   + '} // namespace rules')
seam_anchor_new = ('    return kByLevel[spellLevel - 1];' + NL + '}' + NL + NL
                   + seam + NL + '} // namespace rules')

enum_lines = [
    '    // --- R228: the druid roster joins the registry (77',
    '    //     spells, the printed alphabetical order within',
    '    //     each level - the R182 roster order; appended ids',
    '    //     keep saved knownSpells indices valid) ---',
]
for e, lv in zip(ENUMS, lvls):
    pad = ' ' * max(1, 23 - len(e))
    enum_lines.append('    ' + e + ',' + pad + '// druid ' + str(lv))
enum_block = NL.join(enum_lines)
sc_old = '    SPELL_CLERIC,' + NL + '    SPELL_CLASS_COUNT'
sc_new = ('    SPELL_CLERIC,' + NL
          + '    SPELL_DRUID,   // R228: the druid roster'
          + NL + '    SPELL_CLASS_COUNT')
id_old = '    CL_RESURRECTION,     // CL 7; caster ages 3 (p.14)' + NL + '    SPELL_COUNT'
id_new = ('    CL_RESURRECTION,     // CL 7; caster ages 3 (p.14)' + NL
          + enum_block + NL + '    SPELL_COUNT')

inc_old = '#include ' + DQ + '../rules/wisdom.h' + DQ + '  // R192: Wisdom Tables I and II'
inc_new = (inc_old + NL
          + '#include ' + DQ + '../rules/druidspells.h' + DQ + '  // R228: the druid roster + parameter seam')

row_lines = ['    // ---- R228: the druid roster (77 spells; parameters per',
    '    // the rules/druidspells.h R228 seam - the PHB spell',
    '    // description headers; effects stay known, cast',
    '    // pending per the R80 utility convention) ----']
for nm, lv, ct, rg, du, ao, sv, tg, rv in zip(names, lvls, cts, rngs, durs, aoes, saves, tgts, revs):
    row = ('    { ' + cstr(nm) + ', SPELL_DRUID, ' + str(lv) + ', '
           + str(ct) + ', ' + str(rg) + ', ' + str(du) + ', '
           + str(sv) + ', ' + TGTC[tg] + ', ' + str(ao) + ', 0, 0, '
           + ('true' if rv else 'false') + ' },')
    row_lines.append(row)
rows_block = NL.join(row_lines)
rows_old = ('    { ' + DQ + 'Resurrection' + DQ + ',     SPELL_CLERIC,  7,  8,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },' + NL + '};')
rows_new = ('    { ' + DQ + 'Resurrection' + DQ + ',     SPELL_CLERIC,  7,  8,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },'
            + NL + rows_block + NL + '};')
slots_old = ('int spellSlots(SpellClass sc, int classLevel, int spellLevel) {' + NL
             + '    if (spellLevel < 1 || spellLevel > kSlots) return 0;')
slots_new = (slots_old + NL
    + '    // R228: the druid rows read the R182 slot table'
    + NL + '    // (druidSpellSlots clamps level 1-14, spell 1-7)'
    + NL + '    if (sc == SPELL_DRUID)'
    + NL + '        return rules::druidSpellSlots(classLevel, spellLevel);')

r80a_old = '        int bad = 0, mu = 0, cl = 0, l46 = 0;'
r80a_new = '        int bad = 0, mu = 0, cl = 0, dr = 0, l46 = 0;'
r80b_old = ('            if (s.sclass != spells::SPELL_MU &&'
            + NL + '                s.sclass != spells::SPELL_CLERIC) ++bad;'
            + NL + '            if (s.sclass == spells::SPELL_MU) ++mu; else ++cl;')
r80b_new = ('            // R228: the druid registry rows ride'
            + NL + '            // SPELL_DRUID (77 spells, levels 1-7)'
            + NL + '            if (s.sclass != spells::SPELL_MU &&'
            + NL + '                s.sclass != spells::SPELL_CLERIC &&'
            + NL + '                s.sclass != spells::SPELL_DRUID) ++bad;'
            + NL + '            if (s.sclass == spells::SPELL_MU) ++mu;'
            + NL + '            else if (s.sclass == spells::SPELL_DRUID) ++dr;'
            + NL + '            else ++cl;')
r80c_old = '        if (l46 < 12) ++bad;   // the R80 roster landed'
r80c_new = (r80c_old + NL
    + '        // R228: the druid rows match the R182 roster'
    + NL + '        // cell by cell (level, reversible, class)'
    + NL + '        for (int i = 0; i < rules::druidSpellTotal(); ++i) {'
    + NL + '            const spells::SpellDef& s = spells::spell('
    + NL + '                (spells::SpellId)('
    + NL + '                    spells::DR_ANIMAL_FRIENDSHIP + i));'
    + NL + '            if (s.level != rules::druidSpell(i).level ||'
    + NL + '                (s.reversible ? 1 : 0) !='
    + NL + '                    rules::druidSpell(i).reversible ||'
    + NL + '                s.sclass != spells::SPELL_DRUID) ++bad;'
    + NL + '        }')
r80d_old = ('        printf(' + DQ + 'R80 spells audit: %d spells (MU %d, CL %d), ' + DQ
            + NL + '               ' + DQ + 'L4-6 %d, bad %d' + BS + 'n' + DQ + ','
            + NL + '               spells::SPELL_COUNT, mu, cl, l46, bad);')
r80d_new = ('        printf(' + DQ + 'R80 spells audit: %d spells (MU %d, CL %d, DR %d), ' + DQ
            + NL + '               ' + DQ + 'L4-6 %d, bad %d' + BS + 'n' + DQ + ','
            + NL + '               spells::SPELL_COUNT, mu, cl, dr, l46, bad);')

audit_lines = [
    '    // ---- R228: the druid registry parameters audit ----',
    '    // The evaluable seam walk: the rules/druidspells.h',
    '    // R228 parameter tables vs the book-pin arrays (the',
    '    // PHB spell description headers). The registry rows',
    '    // themselves are walked by the extended R80 battery',
    '    // block - spells.cpp structs are outside the',
    '    // audit_eval subset.',
    '    {',
    '        int bad = 0;',
    aud('kLv', lvls, 10),
    aud('kRv', revs, 10),
    aud('kCt', cts, 10),
    aud('kRg', rngs, 10),
    aud('kDu', durs, 10),
    aud('kAo', aoes, 10),
    aud('kSv', saves, 10),
    aud('kTg', tgts, 10),
    '        for (int i = 0; i < 77; ++i)',
    '            if (rules::druidSpellLevel(i) != kLv[i] ||',
    '                rules::druidSpellRev(i) != kRv[i] ||',
    '                rules::druidSpellCt(i) != kCt[i] ||',
    '                rules::druidSpellRangeTens(i) != kRg[i] ||',
    '                rules::druidSpellDur(i) != kDu[i] ||',
    '                rules::druidSpellAoeTens(i) != kAo[i] ||',
    '                rules::druidSpellSaveCat(i) != kSv[i] ||',
    '                rules::druidSpellTarget(i) != kTg[i]) ++bad;',
    '        // the clamps: -5 and 99 read rows 0 and 76',
    '        if (rules::druidSpellLevel(-5) != kLv[0] ||',
    '            rules::druidSpellLevel(99) != kLv[76] ||',
    '            rules::druidSpellCt(99) != kCt[76]) ++bad;',
    '        // the level histogram ladder: the seam pins',
    '        // the printed roster counts (12/12/12/12/8/',
    '        // 12/9 - R182); every seam level sits in 1..7',
    '        // (the reversible count 16 and the 11 Neg./',
    '        // half saves are properties of the pin arrays',
    '        // above, walked cellwise)',
    '        static const int kHist[7] = { 12, 12, 12, 12, 8, 12, 9 };',
    '        for (int l = 1; l <= 7; ++l)',
    '            if (rules::druidSpellCountByLevel(l) != kHist[l - 1]) ++bad;',
    '        for (int i = 0; i < 77; ++i)',
    '            if (rules::druidSpellLevel(i) < 1 ||',
    '                rules::druidSpellLevel(i) > 7) ++bad;',
    '        // the R182 slot table cross-checks (a spell-level',
    '        // 8 query clamps to the 7th: 3)',
    '        if (rules::druidSpellSlots(1, 1) != 2 ||',
    '            rules::druidSpellSlots(12, 4) != 4 ||',
    '            rules::druidSpellSlots(14, 7) != 3 ||',
    '            rules::druidSpellSlots(14, 8) != 3) ++bad;',
    '        printf(' + DQ + 'R228 druid registry parameters audit: bad %d' + BS + 'n' + DQ + ', bad);',
    '        if (bad) return 1;',
    '    }',
    '',
]
audit_block = NL.join(audit_lines)
audit_old = '    // ---- R163: the poison table audit -------------'
audit_new = audit_block + audit_old

gap_old = ('- [ ] R228 the druid and illusionist rosters'
           + NL + '      join the SpellId registry (139 spells,'
           + NL + '      rules/druidspells.h + illusionspells.h'
           + NL + '      are dead data today) - the largest item,'
           + NL + '      may split.')
gap_new = NL.join([
    '- [x] R228 the druid roster joins the SpellId',
    '      registry - WIRED: 77 DR_ ids appended after',
    '      CL_RESURRECTION (saved knownSpells indices',
    '      stay valid); SPELL_DRUID joins SpellClass;',
    '      77 kSpells rows with the PHB spell-description',
    '      header parameters (casting time in segments:',
    '      a printed turn 60, a round 10, Special 0;',
    '      range in tens of feet, Touch 0; duration the',
    '      base rounds of a per-level scale, Permanent/',
    '      Special 0; save Neg./half = spells 4, none',
    '      -1; aoe the radius in tens where the print',
    '      gives a circle, diameter halved round-up;',
    '      paths/cubes/miles pin 0); the parameters',
    '      also land as the evaluable seam in',
    '      rules/druidspells.h (eight clamped accessors,',
    '      the grenade.h pattern) and',
    '      spellSlots(SPELL_DRUID, ...) delegates to',
    '      the R182 druidSpellSlots (levels 1-14,',
    '      spell 1-7 clamped). Effects stay',
    '      known-cast-pending (the R80 convention);',
    '      the R80 battery walk extends to the druid',
    '      rows and checks them against the R182 roster',
    '      cell by cell. Eight OCR-scattered blocks',
    '      pinned as JUDGMENTs: Entangle (table-form',
    '      header), Invisibility To Animals, Faerie',
    '      Fire, Insect Plague (cleric q.v.: ct 5, no',
    '      save), Conjure Fire Elemental (ct 6 rounds',
    '      = 60, no save), Weather Summoning (ct 1',
    '      turn = 60, the control-weather q.v.),',
    '      Animate Rock (ct 1 turn = 60, no save),',
    '      Conjure Earth Elemental (ct 9 segments, no',
    '      save). Three spell descriptions print a',
    '      Level: divergent from the roster (Sticks to',
    '      Snakes 5, Transmute Rock to Mud 5,',
    '      Confusion 7) - the printed TABLE (R182)',
    '      wins. Census 144.',
    '- [ ] R229 the illusionist roster joins the',
    '      SpellId registry (61 spells, the same seam',
    '      shape as R228).',
])

# ---- the 12 patches ----
patch('rules/druidspells.h', 'R228: the registry parameter seam',
      seam_anchor_old, seam_anchor_new)
patch('spells/spells.h', 'SPELL_DRUID,   // R228: the druid roster',
      sc_old, sc_new)
patch('spells/spells.h', 'DR_ANIMAL_FRIENDSHIP',
      id_old, id_new)
patch('spells/spells.cpp', 'R228: the druid roster + parameter seam',
      inc_old, inc_new)
patch('spells/spells.cpp', 'R228: the druid roster (77 spells; parameters per',
      rows_old, rows_new)
patch('spells/spells.cpp', 'R228: the druid rows read the R182 slot table',
      slots_old, slots_new)
patch('regtest.cpp', 'int bad = 0, mu = 0, cl = 0, dr = 0, l46 = 0;',
      r80a_old, r80a_new)
patch('regtest.cpp', 'R228: the druid registry rows ride',
      r80b_old, r80b_new)
patch('regtest.cpp', 'R228: the druid rows match the R182 roster',
      r80c_old, r80c_new)
patch('regtest.cpp', '(MU %d, CL %d, DR %d), ' + DQ,
      r80d_old, r80d_new)
patch('regtest.cpp', 'R228: the druid registry parameters audit',
      audit_old, audit_new)
patch('tools/phb_gap_report.md',
      'R229 the illusionist roster joins the',
      gap_old, gap_new)

assert applied + already == 12, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R228 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R228 note: 12 patches; the 77 druid spells join the registry -')
print('ids, rows, the parameter seam, the slot delegation and the')
print('battery walks; census 144.')
print('commit: R228: the druid roster joins the SpellId registry - 77')
print('spells wired, the R182 layer live (census 144)')


