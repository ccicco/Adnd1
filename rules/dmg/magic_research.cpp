// R-refactor: split from magic_research.h - definitions
#include "rules/dmg/magic_research.h"

int Magic_research::receptVialCapacity(int metal) {
    // copper 6, silver 10, electrum 18,
    // gold 32, platinum 50
    if (metal < 0) metal = 0;
    if (metal > 4) metal = 4;
    static const int t[5] = {
        6, 10, 18, 32, 50,
    };
    return t[metal];
}

int Magic_research::receptBasinCostMin(int metal) {
    // copper 130, silver 1900, electrum
    // 8000, gold 19000, platinum 110000
    if (metal < 0) metal = 0;
    if (metal > 4) metal = 4;
    static const int t[5] = {
        130, 1900, 8000, 19000, 110000,
    };
    return t[metal];
}

int Magic_research::receptBasinCostMax(int metal) {
    // copper 180, silver 2400, electrum
    // 12000, gold 22000, platinum 200000
    if (metal < 0) metal = 0;
    if (metal > 4) metal = 4;
    static const int t[5] = {
        180, 2400, 12000, 22000, 200000,
    };
    return t[metal];
}

int Magic_research::receptFontCost(int metal) {
    // copper 200, silver 500, electrum
    // 1000, gold 1500, platinum 2000
    if (metal < 0) metal = 0;
    if (metal > 4) metal = 4;
    static const int t[5] = {
        200, 500, 1000, 1500, 2000,
    };
    return t[metal];
}

int Magic_research::receptMixedCapacity(int metalA, int metalB, int pctA) {
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

int Magic_research::receptVialCostMin() { return 2; }

int Magic_research::receptVialCostMax() { return 5; }

int Magic_research::receptFontWeeksMin() {
    // 2d4 + 2: 4 to 10 weeks to build
    return 4;
}

int Magic_research::receptFontWeeksMax() { return 10; }

int Magic_research::receptCreationsPerWeek() {
    // one creation per week
    return 1;
}

int Magic_research::receptRitualHoursRest() {
    // 8 hours of rest after the ritual
    return 8;
}

int Magic_research::receptFontsPerEdifice() {
    // only one font per edifice
    return 1;
}

int Magic_research::receptDefilementMinPct() { return 20; }

int Magic_research::receptDefilementMaxPct() { return 50; }

int Magic_research::receptDefilementWeeksMin() { return 4; }

int Magic_research::receptDefilementWeeksMax() { return 6; }

int Magic_research::receptLycanthropyDelayMin() {
    // drinking delays lycanthropy 1-4
    // turns per vial
    return 1;
}

int Magic_research::receptLycanthropyDelayMax() { return 4; }

int Magic_research::researchBaseCostPerLevelWeek() {
    // 200 gp per spell level per week
    return 200;
}

int Magic_research::researchVarCostMin() { return 100; }

int Magic_research::researchVarCostMax() { return 400; }

int Magic_research::researchNoLibraryFactor() {
    // without a library the base cost x10
    return 10;
}

int Magic_research::researchMinWeeks(int spellLevel) {
    // minimum weeks = spell level + 1;
    // a 0th read is clamped to 1
    if (spellLevel < 1) spellLevel = 1;
    return spellLevel + 1;
}

int Magic_research::researchWeeklyCost(int spellLevel, int varCost, int hasLibrary) {
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

int Magic_research::researchChancePct(int intel, int charLevel, int spellLevel, int extraGpPerLevel) {
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

int Magic_research::researchInterruptionWeeksLost(int days) {
    // each day of interruption costs one
    // week of progress
    if (days < 0) days = 0;
    return days;
}

int Magic_research::researchHoursPerDay() { return 8; }

int Magic_research::researchImpossibleBeyondMuLevel() {
    // no MU spell beyond 9th level
    return 9;
}

int Magic_research::researchImpossibleBeyondClericLevel() {
    // no cleric spell beyond 7th level
    return 7;
}

int Magic_research::researchComboSpellLevel(int levelA, int levelB) {
    // a combination spell = sum of the
    // levels + 1 (the print example:
    // audible glamer + phantasmal force
    // = 3rd + 2nd = 6th)
    return levelA + levelB + 1;
}

int Magic_research::researchLibraryGatherWeeks(int spellLevel) {
    // gathering the library takes one week
    // per spell level
    if (spellLevel < 1) spellLevel = 1;
    return spellLevel;
}

int Magic_research::manufactureClericLevel() { return 11; }

int Magic_research::manufactureWizardLevel() { return 12; }

int Magic_research::manufactureIllusionistLevel() { return 11; }

int Magic_research::playersMakeBooksArtifactsRelics() {
    // books, artifacts and relics are
    // DM-only
    return 0;
}

int Magic_research::playersMakeDwarvenElvenSpecials() {
    // the dwarven/elven specials are
    // DM-only
    return 0;
}

int Magic_research::potionMinLevelWithAlchemist() {
    // MU 7th with an alchemist
    return 7;
}

int Magic_research::potionAlchemistOptionalLevel() {
    // 11th and up the alchemist is optional
    return 11;
}

int Magic_research::potionAlchemistReductionPct() {
    // -50 percent time and money
    return 50;
}

int Magic_research::potionsAtATime() {
    // one potion at a time
    return 1;
}

int Magic_research::potionLabCostMin() { return 200; }

int Magic_research::potionLabCostMax() { return 1000; }

int Magic_research::potionLabUpkeepPctMonthly() {
    // 10 percent monthly upkeep
    return 10;
}

int Magic_research::potionCostGp(int xpAward) {
    // cost in gp equals the XP award; a
    // no-XP potion has a 200 gp base
    if (xpAward > 0) return xpAward;
    return 200;
}

int Magic_research::potionDays(int xpAward) {
    // days = the XP award, each 100 gp
    // or fraction thereof one day; a
    // no-XP potion reads as its 200 gp
    // base = 2 days
    if (xpAward <= 0) xpAward = 200;
    return (xpAward + 99) / 100;
}

int Magic_research::potionAssassinPoisonLevel() {
    // assassin poison needs 9th level
    return 9;
}

int Magic_research::potionDelusionFailureMinPct() { return 5; }

int Magic_research::potionDelusionFailureMaxPct() { return 20; }
