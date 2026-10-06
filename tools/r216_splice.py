#!/usr/bin/env python3
# R216 splice: the magical research pins -
# DMG pp.114-119, the MAGICAL RESEARCH
# seam: the holy/unholy water receptacles
# (5 metals - copper, silver, electrum,
# gold, platinum: vial capacity 6/10/18/
# 32/50, basin cost ranges, font costs
# 200/500/1000/1500/2000 gp, vials 2-5 gp,
# font construction 4-10 weeks, one
# creation per week, 8 hours rest, one
# font per edifice, defilement remake at
# 20-50 percent over 4-6 weeks, drinking
# delays lycanthropy 1-4 turns per vial,
# mixed metals interpolate capacity), the
# spell research economics (200 gp per
# spell level per week base plus 100-400
# gp per level per week variable, no
# library times 10, minimum weeks spell
# level + 1, each day of interruption one
# week lost, 8 hours per day, the success
# chance base 10 percent plus 10 percent
# per extra 2000 gp per level capped at
# 50 percent plus intelligence plus
# character level minus twice the spell
# level, impossible beyond MU 9th and
# cleric 7th, combination spells the sum
# plus one level, library gathering one
# week per level), the manufacture gates
# (cleric 11th, magic-user 12th,
# illusionist 11th; books, artifacts,
# relics and the dwarven/elven specials
# DM-only), and the potion rules (7th
# level with an alchemist, 11th optional
# but minus 50 percent time and money,
# one at a time, laboratory 200-1000 gp
# plus 10 percent monthly upkeep, cost in
# gp and days equal to the XP award - each
# 100 gp or fraction one day, no-XP base
# 200 gp, assassin poison 9th level, the
# delusion failure option 5-20 percent).
# Patches: 4 (new rules/magres.h, regtest
# include, audit block, gap-report log
# entry). Census 131 -> 132.

BS = chr(92)
NL = chr(10)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


def patch(path, marker, old, new):
    # in-place marker patch; old must be unique;
    # old = None means the new-file form
    global applied, already
    try:
        t = rd(path)
    except IOError:
        # the file does not exist: create it
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


# ---------------------------------------------------------------------------
# Patch 1: rules/magres.h - the new header
# ---------------------------------------------------------------------------

hdr_lines = [
'// ====================================================================',
'// Adnd1 - rules/magres.h',
'// R216: the magical research pins (DMG',
'// pp.114-119) - the holy/unholy water',
'// receptacles, the spell research',
'// economics and chance, the manufacture',
'// gates, and the potion rules.',
'//',
'// Pure data + helpers, header-only (the',
'// grenade.h pattern: the caller owns the',
'// dice, the laboratory staff and the',
'// actual brewing; the tables and the',
'// numeric conventions read here).',
'//',
'// Conventions and judgments, named in',
'// place:',
'//   - Receptacles: five metals - copper,',
'//     silver, electrum, gold, platinum.',
'//     Vial capacity 6/10/18/32/50; basin',
'//     cost ranges per metal; font costs',
'//     200/500/1000/1500/2000 gp; a vial',
'//     costs 2-5 gp. A font takes 4-10',
'//     weeks (2d4+2) to build. One creation',
'//     per week, 8 hours of rest needed',
'//     after, one font per edifice. A',
'//     defiled font is remade at 20-50',
'//     percent of cost over 4-6 weeks.',
'//     Drinking delays lycanthropy 1-4',
'//     turns per vial. Mixed metals',
'//     interpolate capacity by the percent',
'//     of the first metal (the print',
'//     example: copper/silver 50/50 gives',
'//     8 vials), rounded to nearest.',
'//   - Spell research: 200 gp per spell',
'//     level per week base plus 100-400 gp',
'//     per level per week variable; without',
'//     a library the base is x10. Minimum',
'//     weeks = spell level + 1. Each day of',
'//     interruption costs one week lost.',
'//     8 hours per day. Chance = base 10',
'//     percent plus 10 percent per extra',
'//     2000 gp per level (capped at 50',
'//     percent) + INT/WIS + character level',
'//     - 2 x spell level. Impossible beyond',
'//     MU 9th and cleric 7th. A combination',
'//     spell = sum of levels + 1. Library',
'//     gathering takes one week per level.',
'//   - Manufacture gates: cleric 11th,',
'//     magic-user 12th, illusionist 11th.',
'//     Books, artifacts, relics and the',
'//     dwarven/elven specials are DM-only.',
'//   - Potions: MU 7th with an alchemist;',
'//     11th and up the alchemist is',
'//     optional but gives -50 percent time',
'//     and money. One potion at a time.',
'//     Laboratory 200-1000 gp plus 10',
'//     percent monthly upkeep. Cost in gp',
'//     and days equals the XP award - each',
'//     100 gp or fraction thereof is one',
'//     day; a no-XP potion has a 200 gp',
'//     base. Assassin poison needs 9th',
'//     level. A failed brew may be a',
'//     delusion: 5-20 percent of the time',
'//     it has no effect (DM option).',
'// ====================================================================',
'',
'#pragma once',
'',
'namespace rules {',
'',
'// -----------------------------------------------------------------------',
'// The holy/unholy water receptacles.',
'// -----------------------------------------------------------------------',
'inline int receptVialCapacity(int metal) {',
'    // copper 6, silver 10, electrum 18,',
'    // gold 32, platinum 50',
'    if (metal < 0) metal = 0;',
'    if (metal > 4) metal = 4;',
'    static const int t[5] = {',
'        6, 10, 18, 32, 50,',
'    };',
'    return t[metal];',
'}',
'',
'inline int receptBasinCostMin(int metal) {',
'    // copper 130, silver 1900, electrum',
'    // 8000, gold 19000, platinum 110000',
'    if (metal < 0) metal = 0;',
'    if (metal > 4) metal = 4;',
'    static const int t[5] = {',
'        130, 1900, 8000, 19000, 110000,',
'    };',
'    return t[metal];',
'}',
'',
'inline int receptBasinCostMax(int metal) {',
'    // copper 180, silver 2400, electrum',
'    // 12000, gold 22000, platinum 200000',
'    if (metal < 0) metal = 0;',
'    if (metal > 4) metal = 4;',
'    static const int t[5] = {',
'        180, 2400, 12000, 22000, 200000,',
'    };',
'    return t[metal];',
'}',
'',
'inline int receptFontCost(int metal) {',
'    // copper 200, silver 500, electrum',
'    // 1000, gold 1500, platinum 2000',
'    if (metal < 0) metal = 0;',
'    if (metal > 4) metal = 4;',
'    static const int t[5] = {',
'        200, 500, 1000, 1500, 2000,',
'    };',
'    return t[metal];',
'}',
'',
'inline int receptMixedCapacity(int metalA, int metalB,',
'                                int pctA) {',
'    // mixed metals interpolate capacity',
'    // by the percent of the first metal;',
'    // the print example: copper/silver',
'    // 50/50 gives 8 vials. Rounded to the',
'    // nearest whole vial.',
'    if (metalA < 0) metalA = 0;',
'    if (metalA > 4) metalA = 4;',
'    if (metalB < 0) metalB = 0;',
'    if (metalB > 4) metalB = 4;',
'    if (pctA < 0) pctA = 0;',
'    if (pctA > 100) pctA = 100;',
'    return (receptVialCapacity(metalA) * pctA',
'            + receptVialCapacity(metalB) * (100 - pctA)',
'            + 50) / 100;',
'}',
'',
'inline int receptVialCostMin() { return 2; }',
'',
'inline int receptVialCostMax() { return 5; }',
'',
'inline int receptFontWeeksMin() {',
'    // 2d4 + 2: 4 to 10 weeks to build',
'    return 4;',
'}',
'',
'inline int receptFontWeeksMax() { return 10; }',
'',
'inline int receptCreationsPerWeek() {',
'    // one creation per week',
'    return 1;',
'}',
'',
'inline int receptRitualHoursRest() {',
'    // 8 hours of rest after the ritual',
'    return 8;',
'}',
'',
'inline int receptFontsPerEdifice() {',
'    // only one font per edifice',
'    return 1;',
'}',
'',
'inline int receptDefilementMinPct() { return 20; }',
'',
'inline int receptDefilementMaxPct() { return 50; }',
'',
'inline int receptDefilementWeeksMin() { return 4; }',
'',
'inline int receptDefilementWeeksMax() { return 6; }',
'',
'inline int receptLycanthropyDelayMin() {',
'    // drinking delays lycanthropy 1-4',
'    // turns per vial',
'    return 1;',
'}',
'',
'inline int receptLycanthropyDelayMax() { return 4; }',
'',
'// -----------------------------------------------------------------------',
'// The spell research economics and chance.',
'// -----------------------------------------------------------------------',
'inline int researchBaseCostPerLevelWeek() {',
'    // 200 gp per spell level per week',
'    return 200;',
'}',
'',
'inline int researchVarCostMin() { return 100; }',
'',
'inline int researchVarCostMax() { return 400; }',
'',
'inline int researchNoLibraryFactor() {',
'    // without a library the base cost x10',
'    return 10;',
'}',
'',
'inline int researchMinWeeks(int spellLevel) {',
'    // minimum weeks = spell level + 1;',
'    // a 0th read is clamped to 1',
'    if (spellLevel < 1) spellLevel = 1;',
'    return spellLevel + 1;',
'}',
'',
'inline int researchWeeklyCost(int spellLevel, int varCost,',
'                              int hasLibrary) {',
'    // base 200 x spell level (x10 without',
'    // a library) plus the variable 100-400',
'    // x spell level, clamped',
'    if (spellLevel < 1) spellLevel = 1;',
'    if (varCost < 100) varCost = 100;',
'    if (varCost > 400) varCost = 400;',
'    int base = researchBaseCostPerLevelWeek()',
'        * spellLevel;',
'    if (hasLibrary == 0)',
'        base = base * researchNoLibraryFactor();',
'    return base + varCost * spellLevel;',
'}',
'',
'inline int researchChancePct(int intel, int charLevel,',
'                             int spellLevel,',
'                             int extraGpPerLevel) {',
'    // base 10 percent, +10 percent per',
'    // extra 2000 gp per level spent,',
'    // capped at 50 percent; plus INT or',
'    // WIS, plus character level, minus',
'    // twice the spell level. Negative',
'    // extra spending reads as 0.',
'    if (spellLevel < 1) spellLevel = 1;',
'    if (extraGpPerLevel < 0) extraGpPerLevel = 0;',
'    int b = 10 + 10 * (extraGpPerLevel / 2000);',
'    if (b > 50) b = 50;',
'    return b + intel + charLevel - 2 * spellLevel;',
'}',
'',
'inline int researchInterruptionWeeksLost(int days) {',
'    // each day of interruption costs one',
'    // week of progress',
'    if (days < 0) days = 0;',
'    return days;',
'}',
'',
'inline int researchHoursPerDay() { return 8; }',
'',
'inline int researchImpossibleBeyondMuLevel() {',
'    // no MU spell beyond 9th level',
'    return 9;',
'}',
'',
'inline int researchImpossibleBeyondClericLevel() {',
'    // no cleric spell beyond 7th level',
'    return 7;',
'}',
'',
'inline int researchComboSpellLevel(int levelA, int levelB) {',
'    // a combination spell = sum of the',
'    // levels + 1 (the print example:',
'    // audible glamer + phantasmal force',
'    // = 3rd + 2nd = 6th)',
'    return levelA + levelB + 1;',
'}',
'',
'inline int researchLibraryGatherWeeks(int spellLevel) {',
'    // gathering the library takes one week',
'    // per spell level',
'    if (spellLevel < 1) spellLevel = 1;',
'    return spellLevel;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The manufacture gates.',
'// -----------------------------------------------------------------------',
'inline int manufactureClericLevel() { return 11; }',
'',
'inline int manufactureWizardLevel() { return 12; }',
'',
'inline int manufactureIllusionistLevel() { return 11; }',
'',
'inline int playersMakeBooksArtifactsRelics() {',
'    // books, artifacts and relics are',
'    // DM-only',
'    return 0;',
'}',
'',
'inline int playersMakeDwarvenElvenSpecials() {',
'    // the dwarven/elven specials are',
'    // DM-only',
'    return 0;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The potion rules.',
'// -----------------------------------------------------------------------',
'inline int potionMinLevelWithAlchemist() {',
'    // MU 7th with an alchemist',
'    return 7;',
'}',
'',
'inline int potionAlchemistOptionalLevel() {',
'    // 11th and up the alchemist is optional',
'    return 11;',
'}',
'',
'inline int potionAlchemistReductionPct() {',
'    // -50 percent time and money',
'    return 50;',
'}',
'',
'inline int potionsAtATime() {',
'    // one potion at a time',
'    return 1;',
'}',
'',
'inline int potionLabCostMin() { return 200; }',
'',
'inline int potionLabCostMax() { return 1000; }',
'',
'inline int potionLabUpkeepPctMonthly() {',
'    // 10 percent monthly upkeep',
'    return 10;',
'}',
'',
'inline int potionCostGp(int xpAward) {',
'    // cost in gp equals the XP award; a',
'    // no-XP potion has a 200 gp base',
'    if (xpAward > 0) return xpAward;',
'    return 200;',
'}',
'',
'inline int potionDays(int xpAward) {',
'    // days = the XP award, each 100 gp',
'    // or fraction thereof one day; a',
'    // no-XP potion reads as its 200 gp',
'    // base = 2 days',
'    if (xpAward <= 0) xpAward = 200;',
'    return (xpAward + 99) / 100;',
'}',
'',
'inline int potionAssassinPoisonLevel() {',
'    // assassin poison needs 9th level',
'    return 9;',
'}',
'',
'inline int potionDelusionFailureMinPct() { return 5; }',
'',
'inline int potionDelusionFailureMaxPct() { return 20; }',
'',
'}  // namespace rules',
]
hdr = NL.join(hdr_lines) + NL

patch('rules/magres.h',
      'R216: the magical research pins',
      None,
      hdr)
# the new-file patch: the empty anchor means
# create-if-absent, marker-check-if-present

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = '#include "rules/conduct.h"  // R215: pp.110-112 conducting the game pins'

new2 = ('#include "rules/conduct.h"  // R215: pp.110-112 conducting the game pins'
        + NL + '#include "rules/magres.h"  // R216: pp.114-119 magical research pins')

patch('regtest.cpp',
      'R216: pp.114-119 magical research pins',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R216 audit block
# ---------------------------------------------------------------------------

audit_lines = [
'    // ---- R216: the magical research pins audit ----',
'    // DMG pp.114-119: the holy/unholy water',
'    // receptacles, the spell research',
'    // economics and chance, the manufacture',
'    // gates, and the potion rules.',
'    {',
'        int bad = 0;',
'        // the receptacles: 5 metals',
'        static const int kCap[5] = { 6, 10, 18, 32, 50 };',
'        static const int kBMin[5] = { 130, 1900, 8000, 19000, 110000 };',
'        static const int kBMax[5] = { 180, 2400, 12000, 22000, 200000 };',
'        static const int kFont[5] = { 200, 500, 1000, 1500, 2000 };',
'        for (int m = 0; m < 5; ++m)',
'            if (rules::receptVialCapacity(m) != kCap[m] ||',
'                rules::receptBasinCostMin(m) != kBMin[m] ||',
'                rules::receptBasinCostMax(m) != kBMax[m] ||',
'                rules::receptFontCost(m) != kFont[m]) ++bad;',
'        if (rules::receptVialCapacity(-3) != 6 ||',
'            rules::receptVialCapacity(9) != 50 ||',
'            rules::receptBasinCostMin(4) != 110000 ||',
'            rules::receptBasinCostMax(4) != 200000 ||',
'            rules::receptFontCost(4) != 2000) ++bad;',
'        // mixed metals interpolate capacity',
'        if (rules::receptMixedCapacity(0, 1, 50) != 8 ||',
'            rules::receptMixedCapacity(0, 1, 100) != 6 ||',
'            rules::receptMixedCapacity(0, 1, 0) != 10 ||',
'            rules::receptMixedCapacity(2, 3, 50) != 25) ++bad;',
'        // the vials, weeks and limits',
'        if (rules::receptVialCostMin() != 2 ||',
'            rules::receptVialCostMax() != 5 ||',
'            rules::receptFontWeeksMin() != 4 ||',
'            rules::receptFontWeeksMax() != 10) ++bad;',
'        if (rules::receptCreationsPerWeek() != 1 ||',
'            rules::receptRitualHoursRest() != 8 ||',
'            rules::receptFontsPerEdifice() != 1) ++bad;',
'        if (rules::receptDefilementMinPct() != 20 ||',
'            rules::receptDefilementMaxPct() != 50 ||',
'            rules::receptDefilementWeeksMin() != 4 ||',
'            rules::receptDefilementWeeksMax() != 6) ++bad;',
'        if (rules::receptLycanthropyDelayMin() != 1 ||',
'            rules::receptLycanthropyDelayMax() != 4) ++bad;',
'        // the spell research economics',
'        if (rules::researchBaseCostPerLevelWeek() != 200 ||',
'            rules::researchVarCostMin() != 100 ||',
'            rules::researchVarCostMax() != 400 ||',
'            rules::researchNoLibraryFactor() != 10) ++bad;',
'        if (rules::researchWeeklyCost(3, 100, 1) != 900 ||',
'            rules::researchWeeklyCost(1, 400, 1) != 600 ||',
'            rules::researchWeeklyCost(2, 100, 0) != 4200) ++bad;',
'        if (rules::researchMinWeeks(1) != 2 ||',
'            rules::researchMinWeeks(9) != 10) ++bad;',
'        // the research chance: base 10-50 by',
'        // extra gp, + INT + level - 2 x SL',
'        if (rules::researchChancePct(12, 5, 3, 0) != 21 ||',
'            rules::researchChancePct(12, 5, 3, 2000) != 31 ||',
'            rules::researchChancePct(12, 5, 3, 8000) != 61 ||',
'            rules::researchChancePct(12, 5, 3, 20000) != 61 ||',
'            rules::researchChancePct(16, 9, 9, 8000) != 57) ++bad;',
'        if (rules::researchInterruptionWeeksLost(3) != 3 ||',
'            rules::researchInterruptionWeeksLost(-4) != 0 ||',
'            rules::researchHoursPerDay() != 8) ++bad;',
'        if (rules::researchImpossibleBeyondMuLevel() != 9 ||',
'            rules::researchImpossibleBeyondClericLevel() != 7) ++bad;',
'        if (rules::researchComboSpellLevel(2, 3) != 6 ||',
'            rules::researchLibraryGatherWeeks(4) != 4) ++bad;',
'        // the manufacture gates',
'        if (rules::manufactureClericLevel() != 11 ||',
'            rules::manufactureWizardLevel() != 12 ||',
'            rules::manufactureIllusionistLevel() != 11) ++bad;',
'        if (rules::playersMakeBooksArtifactsRelics() != 0 ||',
'            rules::playersMakeDwarvenElvenSpecials() != 0) ++bad;',
'        // the potion rules',
'        if (rules::potionMinLevelWithAlchemist() != 7 ||',
'            rules::potionAlchemistOptionalLevel() != 11 ||',
'            rules::potionAlchemistReductionPct() != 50 ||',
'            rules::potionsAtATime() != 1) ++bad;',
'        if (rules::potionLabCostMin() != 200 ||',
'            rules::potionLabCostMax() != 1000 ||',
'            rules::potionLabUpkeepPctMonthly() != 10) ++bad;',
'        if (rules::potionCostGp(250) != 250 ||',
'            rules::potionDays(250) != 3 ||',
'            rules::potionCostGp(0) != 200 ||',
'            rules::potionDays(0) != 2 ||',
'            rules::potionDays(101) != 2 ||',
'            rules::potionDays(100) != 1) ++bad;',
'        if (rules::potionAssassinPoisonLevel() != 9 ||',
'            rules::potionDelusionFailureMinPct() != 5 ||',
'            rules::potionDelusionFailureMaxPct() != 20) ++bad;',
'        printf("R216 magical research pins audit: bad %d' + BS + 'n", bad);',
'        if (bad) return 1;',
'    }',
]
audit = NL.join(audit_lines) + NL

old3 = '    // ---- R163: the poison table audit -------------'

new3 = audit + old3

patch('regtest.cpp',
      'R216: the magical research pins audit',
      old3,
      new3)

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the log entry
# ---------------------------------------------------------------------------

log_lines = [
'R216 landed the magical research pins',
'(DMG pp.114-119) - the holy/unholy',
'water receptacles, the spell research',
'economics, the manufacture gates and',
'the potion rules. rules/magres.h (the',
'grenade.h pattern): the five metals',
'(copper, silver, electrum, gold,',
'platinum) with vial capacity 6/10/18/',
'32/50, the basin cost ranges 130-180 /',
'1900-2400 / 8000-12000 / 19000-22000 /',
'110000-200000 gp, font costs 200/500/',
'1000/1500/2000 gp, vials 2-5 gp, font',
'construction 4-10 weeks (2d4+2), one',
'creation per week, 8 hours rest, one',
'font per edifice, the defilement remake',
'20-50 percent over 4-6 weeks, the',
'lycanthropy delay 1-4 turns per vial,',
'and mixed metals interpolating capacity',
'(the print copper/silver 50/50 = 8',
'vials, rounded to nearest); the spell',
'research economics (200 gp per level',
'per week base + 100-400 gp variable, no',
'library x10, minimum weeks level + 1,',
'interruption day = week lost, 8 h/day,',
'chance 10 percent + 10 per extra 2000',
'gp per level capped 50 + INT/WIS +',
'level - 2 x spell level, impossible',
'beyond MU 9th / cleric 7th, combo spells',
'sum + 1, library gathering 1 week per',
'level); the manufacture gates (cleric',
'11, wizard 12, illusionist 11; books,',
'artifacts, relics and the dwarven/elven',
'specials DM-only); and the potion rules',
'(MU 7th with alchemist, 11th optional at',
'-50 percent, one at a time, lab 200-1000',
'gp + 10 percent monthly upkeep, cost and',
'days = the XP award, each 100 gp or',
'fraction a day, no-XP base 200 gp,',
'assassin poison 9th, delusion failure',
'5-20 percent). Compilation cross-check:',
'the sr.htm page is a Dragon editorial',
'and stays OUT per the ground-truth rule;',
'the upload is clean at this seam and is',
'the sole source. New R216 battery audit;',
'census 132. Next: the scroll and other',
'magic item manufacture seams (upload',
'lines ~9100+, pp.119+).',
]
log_entry = NL.join(log_lines)

old4 = ('the AD&D campaign milieu sections, upload' + NL
        + 'lines ~8720+).' + NL + NL + 'Categories:')

new4 = ('the AD&D campaign milieu sections, upload' + NL
        + 'lines ~8720+).' + NL + NL + log_entry + NL
        + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R216 landed the magical research pins',
      old4,
      new4)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R216 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R216 note: 4 patches; the magical research pins landed -')
print('the receptacle tables, the research chance, the gates,')
print('the potion rules; census 132.')
print('commit: R216: the magical research pins pinned - DMG')
print('pp.114-119, holy water receptacles, spell research, potion manufacture (census 132)')

