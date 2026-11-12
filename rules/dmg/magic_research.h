// ====================================================================
// Adnd1 - rules/dmg/magic_research.h
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

// R-refactor: namespace rules -> class Magic_research (instance methods)
class Magic_research {
public:


// -----------------------------------------------------------------------
// The holy/unholy water receptacles.
// -----------------------------------------------------------------------
    int receptVialCapacity(int metal);
    int receptBasinCostMin(int metal);
    int receptBasinCostMax(int metal);
    int receptFontCost(int metal);
    int receptMixedCapacity(int metalA, int metalB, int pctA);
    int receptVialCostMin();
    int receptVialCostMax();
    int receptFontWeeksMin();
    int receptFontWeeksMax();
    int receptCreationsPerWeek();
    int receptRitualHoursRest();
    int receptFontsPerEdifice();
    int receptDefilementMinPct();
    int receptDefilementMaxPct();
    int receptDefilementWeeksMin();
    int receptDefilementWeeksMax();
    int receptLycanthropyDelayMin();
    int receptLycanthropyDelayMax();


// -----------------------------------------------------------------------
// The spell research economics and chance.
// -----------------------------------------------------------------------
    int researchBaseCostPerLevelWeek();
    int researchVarCostMin();
    int researchVarCostMax();
    int researchNoLibraryFactor();
    int researchMinWeeks(int spellLevel);
    int researchWeeklyCost(int spellLevel, int varCost, int hasLibrary);
    int researchChancePct(int intel, int charLevel, int spellLevel, int extraGpPerLevel);
    int researchInterruptionWeeksLost(int days);
    int researchHoursPerDay();
    int researchImpossibleBeyondMuLevel();
    int researchImpossibleBeyondClericLevel();
    int researchComboSpellLevel(int levelA, int levelB);
    int researchLibraryGatherWeeks(int spellLevel);


// -----------------------------------------------------------------------
// The manufacture gates.
// -----------------------------------------------------------------------
    int manufactureClericLevel();
    int manufactureWizardLevel();
    int manufactureIllusionistLevel();
    int playersMakeBooksArtifactsRelics();
    int playersMakeDwarvenElvenSpecials();


// -----------------------------------------------------------------------
// The potion rules.
// -----------------------------------------------------------------------
    int potionMinLevelWithAlchemist();
    int potionAlchemistOptionalLevel();
    int potionAlchemistReductionPct();
    int potionsAtATime();
    int potionLabCostMin();
    int potionLabCostMax();
    int potionLabUpkeepPctMonthly();
    int potionCostGp(int xpAward);
    int potionDays(int xpAward);
    int potionAssassinPoisonLevel();
    int potionDelusionFailureMinPct();
    int potionDelusionFailureMaxPct();
};
