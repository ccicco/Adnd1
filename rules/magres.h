// ====================================================================
// Adnd1 - rules/magres.h
// R216: the magical research pins (DMG
// pp.114-119) - the holy/unholy water
// receptacles, the spell research
// economics and chance, the manufacture
// gates, and the potion rules.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// dice, the laboratory staff and the
// actual brewing; the tables and the
// numeric conventions read here).
//
// Conventions and judgments, named in
// place:
//   - Receptacles: five metals - copper,
//     silver, electrum, gold, platinum.
//     Vial capacity 6/10/18/32/50; basin
//     cost ranges per metal; font costs
//     200/500/1000/1500/2000 gp; a vial
//     costs 2-5 gp. A font takes 4-10
//     weeks (2d4+2) to build. One creation
//     per week, 8 hours of rest needed
//     after, one font per edifice. A
//     defiled font is remade at 20-50
//     percent of cost over 4-6 weeks.
//     Drinking delays lycanthropy 1-4
//     turns per vial. Mixed metals
//     interpolate capacity by the percent
//     of the first metal (the print
//     example: copper/silver 50/50 gives
//     8 vials), rounded to nearest.
//   - Spell research: 200 gp per spell
//     level per week base plus 100-400 gp
//     per level per week variable; without
//     a library the base is x10. Minimum
//     weeks = spell level + 1. Each day of
//     interruption costs one week lost.
//     8 hours per day. Chance = base 10
//     percent plus 10 percent per extra
//     2000 gp per level (capped at 50
//     percent) + INT/WIS + character level
//     - 2 x spell level. Impossible beyond
//     MU 9th and cleric 7th. A combination
//     spell = sum of levels + 1. Library
//     gathering takes one week per level.
//   - Manufacture gates: cleric 11th,
//     magic-user 12th, illusionist 11th.
//     Books, artifacts, relics and the
//     dwarven/elven specials are DM-only.
//   - Potions: MU 7th with an alchemist;
//     11th and up the alchemist is
//     optional but gives -50 percent time
//     and money. One potion at a time.
//     Laboratory 200-1000 gp plus 10
//     percent monthly upkeep. Cost in gp
//     and days equals the XP award - each
//     100 gp or fraction thereof is one
//     day; a no-XP potion has a 200 gp
//     base. Assassin poison needs 9th
//     level. A failed brew may be a
//     delusion: 5-20 percent of the time
//     it has no effect (DM option).
// ====================================================================

#pragma once

namespace rules {

// -----------------------------------------------------------------------
// The holy/unholy water receptacles.
// -----------------------------------------------------------------------
inline int receptVialCapacity(int metal) {
    // copper 6, silver 10, electrum 18,
    // gold 32, platinum 50
    if (metal < 0) metal = 0;
    if (metal > 4) metal = 4;
    static const int t[5] = {
        6, 10, 18, 32, 50,
    };
    return t[metal];
}

inline int receptBasinCostMin(int metal) {
    // copper 130, silver 1900, electrum
    // 8000, gold 19000, platinum 110000
    if (metal < 0) metal = 0;
    if (metal > 4) metal = 4;
    static const int t[5] = {
        130, 1900, 8000, 19000, 110000,
    };
    return t[metal];
}

inline int receptBasinCostMax(int metal) {
    // copper 180, silver 2400, electrum
    // 12000, gold 22000, platinum 200000
    if (metal < 0) metal = 0;
    if (metal > 4) metal = 4;
    static const int t[5] = {
        180, 2400, 12000, 22000, 200000,
    };
    return t[metal];
}

inline int receptFontCost(int metal) {
    // copper 200, silver 500, electrum
    // 1000, gold 1500, platinum 2000
    if (metal < 0) metal = 0;
    if (metal > 4) metal = 4;
    static const int t[5] = {
        200, 500, 1000, 1500, 2000,
    };
    return t[metal];
}

inline int receptMixedCapacity(int metalA, int metalB,
                                int pctA) {
    // mixed metals interpolate capacity
    // by the percent of the first metal;
    // the print example: copper/silver
    // 50/50 gives 8 vials. Rounded to the
    // nearest whole vial.
    if (metalA < 0) metalA = 0;
    if (metalA > 4) metalA = 4;
    if (metalB < 0) metalB = 0;
    if (metalB > 4) metalB = 4;
    if (pctA < 0) pctA = 0;
    if (pctA > 100) pctA = 100;
    return (receptVialCapacity(metalA) * pctA
            + receptVialCapacity(metalB) * (100 - pctA)
            + 50) / 100;
}

inline int receptVialCostMin() { return 2; }

inline int receptVialCostMax() { return 5; }

inline int receptFontWeeksMin() {
    // 2d4 + 2: 4 to 10 weeks to build
    return 4;
}

inline int receptFontWeeksMax() { return 10; }

inline int receptCreationsPerWeek() {
    // one creation per week
    return 1;
}

inline int receptRitualHoursRest() {
    // 8 hours of rest after the ritual
    return 8;
}

inline int receptFontsPerEdifice() {
    // only one font per edifice
    return 1;
}

inline int receptDefilementMinPct() { return 20; }

inline int receptDefilementMaxPct() { return 50; }

inline int receptDefilementWeeksMin() { return 4; }

inline int receptDefilementWeeksMax() { return 6; }

inline int receptLycanthropyDelayMin() {
    // drinking delays lycanthropy 1-4
    // turns per vial
    return 1;
}

inline int receptLycanthropyDelayMax() { return 4; }

// -----------------------------------------------------------------------
// The spell research economics and chance.
// -----------------------------------------------------------------------
inline int researchBaseCostPerLevelWeek() {
    // 200 gp per spell level per week
    return 200;
}

inline int researchVarCostMin() { return 100; }

inline int researchVarCostMax() { return 400; }

inline int researchNoLibraryFactor() {
    // without a library the base cost x10
    return 10;
}

inline int researchMinWeeks(int spellLevel) {
    // minimum weeks = spell level + 1;
    // a 0th read is clamped to 1
    if (spellLevel < 1) spellLevel = 1;
    return spellLevel + 1;
}

inline int researchWeeklyCost(int spellLevel, int varCost,
                              int hasLibrary) {
    // base 200 x spell level (x10 without
    // a library) plus the variable 100-400
    // x spell level, clamped
    if (spellLevel < 1) spellLevel = 1;
    if (varCost < 100) varCost = 100;
    if (varCost > 400) varCost = 400;
    int base = researchBaseCostPerLevelWeek()
        * spellLevel;
    if (hasLibrary == 0)
        base = base * researchNoLibraryFactor();
    return base + varCost * spellLevel;
}

inline int researchChancePct(int intel, int charLevel,
                             int spellLevel,
                             int extraGpPerLevel) {
    // base 10 percent, +10 percent per
    // extra 2000 gp per level spent,
    // capped at 50 percent; plus INT or
    // WIS, plus character level, minus
    // twice the spell level. Negative
    // extra spending reads as 0.
    if (spellLevel < 1) spellLevel = 1;
    if (extraGpPerLevel < 0) extraGpPerLevel = 0;
    int b = 10 + 10 * (extraGpPerLevel / 2000);
    if (b > 50) b = 50;
    return b + intel + charLevel - 2 * spellLevel;
}

inline int researchInterruptionWeeksLost(int days) {
    // each day of interruption costs one
    // week of progress
    if (days < 0) days = 0;
    return days;
}

inline int researchHoursPerDay() { return 8; }

inline int researchImpossibleBeyondMuLevel() {
    // no MU spell beyond 9th level
    return 9;
}

inline int researchImpossibleBeyondClericLevel() {
    // no cleric spell beyond 7th level
    return 7;
}

inline int researchComboSpellLevel(int levelA, int levelB) {
    // a combination spell = sum of the
    // levels + 1 (the print example:
    // audible glamer + phantasmal force
    // = 3rd + 2nd = 6th)
    return levelA + levelB + 1;
}

inline int researchLibraryGatherWeeks(int spellLevel) {
    // gathering the library takes one week
    // per spell level
    if (spellLevel < 1) spellLevel = 1;
    return spellLevel;
}

// -----------------------------------------------------------------------
// The manufacture gates.
// -----------------------------------------------------------------------
inline int manufactureClericLevel() { return 11; }

inline int manufactureWizardLevel() { return 12; }

inline int manufactureIllusionistLevel() { return 11; }

inline int playersMakeBooksArtifactsRelics() {
    // books, artifacts and relics are
    // DM-only
    return 0;
}

inline int playersMakeDwarvenElvenSpecials() {
    // the dwarven/elven specials are
    // DM-only
    return 0;
}

// -----------------------------------------------------------------------
// The potion rules.
// -----------------------------------------------------------------------
inline int potionMinLevelWithAlchemist() {
    // MU 7th with an alchemist
    return 7;
}

inline int potionAlchemistOptionalLevel() {
    // 11th and up the alchemist is optional
    return 11;
}

inline int potionAlchemistReductionPct() {
    // -50 percent time and money
    return 50;
}

inline int potionsAtATime() {
    // one potion at a time
    return 1;
}

inline int potionLabCostMin() { return 200; }

inline int potionLabCostMax() { return 1000; }

inline int potionLabUpkeepPctMonthly() {
    // 10 percent monthly upkeep
    return 10;
}

inline int potionCostGp(int xpAward) {
    // cost in gp equals the XP award; a
    // no-XP potion has a 200 gp base
    if (xpAward > 0) return xpAward;
    return 200;
}

inline int potionDays(int xpAward) {
    // days = the XP award, each 100 gp
    // or fraction thereof one day; a
    // no-XP potion reads as its 200 gp
    // base = 2 days
    if (xpAward <= 0) xpAward = 200;
    return (xpAward + 99) / 100;
}

inline int potionAssassinPoisonLevel() {
    // assassin poison needs 9th level
    return 9;
}

inline int potionDelusionFailureMinPct() { return 5; }

inline int potionDelusionFailureMaxPct() { return 20; }

}  // namespace rules
