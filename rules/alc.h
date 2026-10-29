// =========================================================================================
// Adnd1 - rules/alc.h
// The Alchemist, complete - Jon Pickens' new D&D character class (folios
// 28-30): the class frame, the twenty-stage advancement ladder, the four
// ability percentages, the six-level potions grid, the level-gated abilities,
// the On Poisons doctrine, and the laboratory
// census 813 -> 814.
//
// Pinned from The Dragon Vol. 1 No. 2 (August 1976): folios 28-30, Jon
// Pickens' A New D&D Character Class: The Alchemist - the class core and
// ability table (folio 28), the potions list, acids, drugs, production costs
// and the new-potion explanations (folio 29), and the magic-item
// interactions, the On Poisons doctrine, and the weapon damage option (folio
// 30, the option rides a later round). COMPLETE per the user's mandate -
// class, progression, potions and poisons, no cherry-picking. OD&D-era ink
// converted per the walk doctrine: the pin IS the conversion, noted, never
// silent.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon. The
// Alchemist rides as a full variant class - the engine's canon classes are
// untouched; the two printed grids (the four ability percentages, the potions
// per level) and the twenty-stage XP ladder are pinned as printed, with the
// ink's blank ceiling cells read as the 100-percent cap and so noted; the
// level-gated abilities, the poison level-strength system, the acids, drugs
// and blade venom, the production costs, and the item interactions (Grimoire
// of Archaic Alchemy, Book of Infinite Spells, the Philosopher's Stone) all
// ride noted, never silent.
//
namespace rules {

// ---- the class frame (folios 28, 30) ----

// the prime requisite is Wisdom, and BOTH Wisdom and Intelligence must exceed
// 12 - the converted floor reads 13 or better (folio 28)
inline int alcWisIntFloor()
    { return 13; }

// fighting is not their vocation - the best armor class they can reach is 5
// (folio 28)
inline int alcMaxAc()
    { return 5; }

// six-sided hit dice (folio 28)
inline int alcHitDieSides()
    { return 6; }

// the d6 runs to level 9, one point per level after (folio 28)
inline int alcHitDiceTop()
    { return 9; }

// saving throws as Fighters, plus 2 against poison and non-magical
// paralyzation (folio 28)
inline int alcSaveBonusPoison()
    { return 2; }

// Neutralize Poison works up to TWICE the Alchemist's own level, once per
// character per poisoning, and never revives the dead (folio 28)
inline int alcNeutralizeMult()
    { return 2; }

// Neutralize Paralyzation cancels creature-caused paralyzation up to twice
// his level, never device-caused (folio 28)
inline int alcParalyzeMult()
    { return 2; }

// Alchemists must be human (folio 28)
inline bool alcHumanOnly()
    { return true; }

// their alignment is NEUTRAL (folio 28)
inline bool alcNeutralRequired()
    { return true; }

// attack levels advance as Clerics; one-handed weapons only, no magical
// swords (folio 28)
inline bool alcAttackAsCleric()
    { return true; }

// the saving-throw frame rides the Fighter tables, plus 2 vs poison and
// non-magical paralyzation (folio 28)
inline bool alcSavesAsFighter()
    { return true; }

// psionic ability as Fighters, with Body Weaponry replaced by Molecular
// Agitation (folio 28)
inline bool alcPsionicSwap()
    { return true; }

// the Alchemist may use any potion, and the magical items employable by all
// classes (folio 28)
inline bool alcUseAnyPotion()
    { return true; }

// the Alchemist is able to use the Manual of Golems (folio 30)
inline bool alcUseManualOfGolems()
    { return true; }

// alchemic magical items include any device save wands or staves which can
// summon elementals (folio 29)
inline bool alcNoElementalWands()
    { return true; }

// the Alchemist can control which liquids emerge from the Jug of Plentiful
// Potions; other types pour randomly (folio 30)
inline bool alcJugControl()
    { return true; }

// ---- the advancement ladder (folio 28) ----

// the advancement ladder - stage 0 Student at 0 XP through stage 19 Master
// Alchemist the 11th at 1,800,000: 0 / 1,500 / 3,000 / 6,000 / 12,000 /
// 25,000 / 50,000 / 100,000 / 150,000 / 300,000 / 450,000 / 600,000 / 750,000
// / 900,000 / 1,050,000 / 1,200,000 / 1,350,000 / 1,500,000 / 1,650,000 /
// 1,800,000 XP (folio 28)
inline int alcXpStage(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1500;
        case 2:
            return 3000;
        case 3:
            return 6000;
        case 4:
            return 12000;
        case 5:
            return 25000;
        case 6:
            return 50000;
        case 7:
            return 100000;
        case 8:
            return 150000;
        case 9:
            return 300000;
        case 10:
            return 450000;
        case 11:
            return 600000;
        case 12:
            return 750000;
        case 13:
            return 900000;
        case 14:
            return 1050000;
        case 15:
            return 1200000;
        case 16:
            return 1350000;
        case 17:
            return 1500000;
        case 18:
            return 1650000;
        case 19:
            return 1800000;
        default:
            return 1800000;
        }
    }

// the ability grid runs the full twenty stages - Student through Master
// Alchemist the 11th (folio 28)
inline int alcPctRows()
    { return 20; }

// the potions grid runs the same twenty stages (folio 28)
inline int alcPotionRows()
    { return 20; }

// ---- the ability grid (folio 28) ----

// Detect Poison percent by stage - Student 20 through the 95 at Mstr Alchem
// 2nd, capped at 100 from Mstr 3rd
inline int alcDetPct(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 25;
        case 2:
            return 30;
        case 3:
            return 35;
        case 4:
            return 45;
        case 5:
            return 55;
        case 6:
            return 60;
        case 7:
            return 65;
        case 8:
            return 75;
        case 9:
            return 85;
        case 10:
            return 95;
        case 11:
            return 100;
        case 12:
            return 100;
        case 13:
            return 100;
        case 14:
            return 100;
        case 15:
            return 100;
        case 16:
            return 100;
        case 17:
            return 100;
        case 18:
            return 100;
        case 19:
            return 100;
        default:
            return 0;
        }
    }

// Neutralize Poison percent by stage - 10 at Student to the printed 95 at
// Mstr 4th, 100 from Mstr 5th
inline int alcNeutPoisPct(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 15;
        case 2:
            return 20;
        case 3:
            return 25;
        case 4:
            return 35;
        case 5:
            return 45;
        case 6:
            return 50;
        case 7:
            return 55;
        case 8:
            return 65;
        case 9:
            return 75;
        case 10:
            return 85;
        case 11:
            return 90;
        case 12:
            return 95;
        case 13:
            return 100;
        case 14:
            return 100;
        case 15:
            return 100;
        case 16:
            return 100;
        case 17:
            return 100;
        case 18:
            return 100;
        case 19:
            return 100;
        default:
            return 0;
        }
    }

// Neutralize Paralyzation percent by stage - 15 at Student, capped at 100
// from Mstr 3rd
inline int alcNeutParaPct(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 20;
        case 2:
            return 25;
        case 3:
            return 35;
        case 4:
            return 40;
        case 5:
            return 45;
        case 6:
            return 55;
        case 7:
            return 65;
        case 8:
            return 75;
        case 9:
            return 85;
        case 10:
            return 95;
        case 11:
            return 100;
        case 12:
            return 100;
        case 13:
            return 100;
        case 14:
            return 100;
        case 15:
            return 100;
        case 16:
            return 100;
        case 17:
            return 100;
        case 18:
            return 100;
        case 19:
            return 100;
        default:
            return 0;
        }
    }

// Identify Potion percent by stage - 5 at Student, capped at 100 at Mstr 4th
inline int alcIdenPct(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 25;
        case 4:
            return 35;
        case 5:
            return 45;
        case 6:
            return 50;
        case 7:
            return 60;
        case 8:
            return 70;
        case 9:
            return 80;
        case 10:
            return 85;
        case 11:
            return 95;
        case 12:
            return 100;
        case 13:
            return 100;
        case 14:
            return 100;
        case 15:
            return 100;
        case 16:
            return 100;
        case 17:
            return 100;
        case 18:
            return 100;
        case 19:
            return 100;
        default:
            return 0;
        }
    }

// ---- the potions grid (folio 28) ----

// first-level potions per stage - none through Cleric, 2 from Scribe, 10 at
// Mstr Alchem 11th
inline int alcPots1(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 7;
        case 14:
            return 7;
        case 15:
            return 8;
        case 16:
            return 8;
        case 17:
            return 9;
        case 18:
            return 9;
        case 19:
            return 10;
        default:
            return 0;
        }
    }

// second-level potions per stage - from Savant's 1 to the terminal 8
inline int alcPots2(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 5;
        case 13:
            return 5;
        case 14:
            return 6;
        case 15:
            return 6;
        case 16:
            return 7;
        case 17:
            return 7;
        case 18:
            return 8;
        case 19:
            return 8;
        default:
            return 0;
        }
    }

// third-level potions per stage - from Philosopher's 1 to the terminal 8
inline int alcPots3(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 6;
        case 16:
            return 6;
        case 17:
            return 7;
        case 18:
            return 7;
        case 19:
            return 8;
        default:
            return 0;
        }
    }

// fourth-level potions per stage - from Alchemist's 1 to the terminal 6
inline int alcPots4(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 6;
        case 19:
            return 6;
        default:
            return 0;
        }
    }

// fifth-level potions per stage - from Mstr Alchem 2nd's 1 to the terminal 6
inline int alcPots5(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 6;
        default:
            return 0;
        }
    }

// sixth-level potions per stage - from Mstr Alchem 4th's 1 to the terminal 4
inline int alcPots6(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 3;
        case 17:
            return 3;
        case 18:
            return 4;
        case 19:
            return 4;
        default:
            return 0;
        }
    }

// ---- the level gates (folio 28) ----

// the 1st-level gates: Read Languages, prepare poisons and drugs, prepare a
// Potion of Delusion (folio 28)
inline int alcReadLangLevel()
    { return 1; }

// Read Languages at 80 percent, one attempt per week per item (folio 28)
inline int alcReadLangPct()
    { return 80; }

// poisons and drugs from the first level (folio 28)
inline int alcPoisonDrugLevel()
    { return 1; }

// the Potion of Delusion brewable from the first level (folio 28)
inline int alcDelusionLevel()
    { return 1; }

// the 3rd-level gate: prepare potions and acids (folio 28)
inline int alcPotionAcidLevel()
    { return 3; }

// the 5th-level gate: prepare Blade Venom (folio 28)
inline int alcBladeVenomLevel()
    { return 5; }

// the 7th-level gate: Read Magic and hence scrolls, as Thieves (folio 28)
inline int alcReadMagicLevel()
    { return 7; }

// the 9th-level gate: prepare potions from samples, even unresearched ones
// (folios 28-29)
inline int alcSampleLevel()
    { return 9; }

// ---- the poisons doctrine (folio 30) ----

// poisons: each strength level costs 50 gold pieces and one day to brew
// (folio 28)
inline int alcPoisonCostGp()
    { return 50; }

// one day per strength level of poison (folio 28)
inline int alcPoisonCostDays()
    { return 1; }

// a poison at or above the victim's dice count kills in 3 melee rounds on a
// failed save (folio 30)
inline int alcPoisonDieRounds()
    { return 3; }

// a poison at half the victim's dice or more (but under the full count) slows
// him until an hourly constitution/resurrection check succeeds (folio 30)
inline int alcSlowDivisor()
    { return 2; }

// large doses are detectable - minus 20 percent ingestion chance per dose
// over the basic one (folio 30)
inline int alcDoseIngestPenaltyPct()
    { return 20; }

// Belladonna reads as a half-level-strength poison (folio 30)
inline int alcBelladonnaDiv()
    { return 2; }

// Blade Venom costs 200 gold pieces and one week to prepare (folio 30)
inline int alcBladeVenomCostGp()
    { return 200; }

// one week of preparation per batch of Blade Venom, one vial per batch (folio
// 30)
inline int alcBladeVenomWeeks()
    { return 1; }

// a Blade Venom vial coats three hits with a blade or three arrows (folio 30)
inline int alcBladeVenomDoses()
    { return 3; }

// Blade Venom loses potency 24 hours after the vial is opened (folio 30)
inline int alcBladeVenomHours()
    { return 24; }

// Identify Potion: if a Potion of Delusion is not identified, check again -
// it may be identified incorrectly; also tests for acids (folio 28)
inline bool alcDelusionRecheck()
    { return true; }

// poison below the slow threshold has no effect but accumulates in the body
// (folio 30)
inline bool alcPoisonAccumulates()
    { return true; }

// the option: a cleric may remove as many poison levels as his own experience
// levels, subtracted immediately (folio 30)
inline bool alcClericNeutralizeOption()
    { return true; }

// ---- the laboratory (folios 29-30) ----

// acids by the gallon: 100 gold pieces and one day per level strength (folio
// 29)
inline int alcAcidCostGp()
    { return 100; }

// acid damage - one six-sided die per level strength, maximum strength equal
// to the Alchemist's level (folio 29)
inline int alcAcidDieSides()
    { return 6; }

// from the 3rd level the Alchemist has a chance to neutralize half the acid
// damage, if the victim survives (folio 29)
inline int alcAcidNeutralizeLevel()
    { return 3; }

// the base acid-neutralization chance is 15 percent (folio 29)
inline int alcAcidNeutralizeBasePct()
    { return 15; }

// the acid-neutralization chance rises 5 percent per level above the 3rd
// (folio 29)
inline int alcAcidNeutralizeStepPct()
    { return 5; }

// drugs cost double the poison price (folio 29)
inline int alcDrugCostMult()
    { return 2; }

// the drug save rides at minus 2 vs poison; failure means unconsciousness
// (folio 29)
inline int alcDrugSavePenalty()
    { return 2; }

// the drugged victim sleeps 4 hours minimum, waking on an hourly
// constitution/resurrection check (folio 29)
inline int alcDrugUnconsciousHours()
    { return 4; }

// potions cost 200 gold pieces and one week per level to produce; research
// costs as MU spells (folio 29)
inline int alcPotionCostGp()
    { return 200; }

// one week of production per potion level (folio 29)
inline int alcPotionWeeksPerLevel()
    { return 1; }

// a sample adds 40 percent to the research chance for an Alchemist able to
// research the potion (folio 29)
inline int alcSampleBonusPct()
    { return 40; }

// the option: raise potion production costs to 250 gold pieces and bar MU
// potion production (folio 29)
inline int alcPotionOptionCostGp()
    { return 250; }

// the production option's other half - bar MU potion production entirely
// (folio 29)
inline bool alcPotionOptionNoMu()
    { return true; }

// the level-1 potion list runs ten: Heroism to Tanglefoot Pills (folio 29)
inline int alcPotionsL1()
    { return 10; }

// the level-2 list runs eight: Speed to Dust of Paralyzation (folio 29)
inline int alcPotionsL2()
    { return 8; }

// the level-3 list runs eight: Superheroism to Dust of Sneezing and Choking
// (folio 29)
inline int alcPotionsL3()
    { return 8; }

// the level-4 list runs six: Invulnerability to Homunculi Creation (folio 29)
inline int alcPotionsL4()
    { return 6; }

// the level-5 list runs six: Dragon Control to Cloning Culture (folio 29)
inline int alcPotionsL5()
    { return 6; }

// the level-6 list runs four: Longevity, Cure Disease, Regeneration, Mind
// Damp (folio 29)
inline int alcPotionsL6()
    { return 4; }

// the Lycanthropy Immunization serum protects for one month, with a 1 percent
// chance of catching the disease from the serum itself (folio 29)
inline int alcSerumRiskPct()
    { return 1; }

// one month of lycanthropy immunity per dose of serum (folio 29)
inline int alcLycImmunityMonths()
    { return 1; }

// Dust of Sneezing: saves at minus 2, a coughing spell for 2-8 melee rounds,
// makes 10 packets (folio 29)
inline int alcSneezeCoughMin()
    { return 2; }

// the coughing spell's top end - 8 melee rounds (folio 29)
inline int alcSneezeCoughMax()
    { return 8; }

// Flash Pellets: an unexpected victim has a 90 percent chance of blindness
// for 2-8 melee rounds; makes 5 pellets (folio 29)
inline int alcFlashBlindPct()
    { return 90; }

// five Flash Pellets per batch (folio 29)
inline int alcFlashPellets()
    { return 5; }

// Purification Powder serves 10 - makes bad food and water fit, never
// neutralizing poison or drugs (folio 29)
inline int alcPurifyServings()
    { return 10; }

// Tanglefoot expands to fill a 10 x 10 area with rubbery tentacles; makes 2
// (folio 29)
inline int alcTangleSideFeet()
    { return 10; }

// a man needs 3 turns to force through the Tanglefoot; a giant takes one
// (folio 29)
inline int alcTangleMenTurns()
    { return 3; }

// the Tanglefoot tendrils dissipate harmlessly in one hour (folio 29)
inline int alcTangleHours()
    { return 1; }

// Dust of Paralyzation: a missed save paralyzes for 1 hour; makes 10 packets
// (folio 29)
inline int alcDustParalyzPackets()
    { return 10; }

// one hour of paralyzation from the Dust (folio 29)
inline int alcParalyzHours()
    { return 1; }

// Mind Damp: one week of immunity to psionic location or attack, the user
// psionically silent, psionic devices inoperative (folio 29)
inline int alcMindDampWeeks()
    { return 1; }

// the Regeneration potion acts as a Ring of Regeneration for one day (folio
// 29)
inline int alcRegenRingDays()
    { return 1; }

// revitalization holds up to three days on a fresh body, a constitution check
// needed after the first (folio 29)
inline int alcRegenFreshDays()
    { return 3; }

// applied over at least two weeks to an inactive character, it can regenerate
// a lost body member (folio 29)
inline int alcRegenWeeks()
    { return 2; }

// the Grimoire of Archaic Alchemy adds one experience level to Alchemists
// (folio 30)
inline int alcGrimoireAlcBonus()
    { return 1; }

// the Grimoire gives MUs 10,000 experience points (folio 30)
inline int alcGrimoireMuXp()
    { return 10000; }

// Clerics take 7,000 experience points from the Grimoire and lose 5-30 (folio
// 30)
inline int alcGrimoireClericXp()
    { return 7000; }

// the Grimoire's Cleric loss floor - 5 points (folio 30)
inline int alcGrimoireClericLossMin()
    { return 5; }

// the Grimoire's Cleric loss ceiling - 30 points (folio 30)
inline int alcGrimoireClericLossMax()
    { return 30; }

// other types lose 2-20 points to the Grimoire (folio 30)
inline int alcGrimoireOtherLossMin()
    { return 2; }

// the Grimoire's other-class loss ceiling - 20 points (folio 30)
inline int alcGrimoireOtherLossMax()
    { return 20; }

// the Book of Infinite Spells does 5-20 points to an Alchemist, where he
// otherwise takes book damage as a Cleric (folio 30)
inline int alcBookInfMin()
    { return 5; }

// the Book of Infinite Spells damage ceiling - 20 points (folio 30)
inline int alcBookInfMax()
    { return 20; }

// the Philosopher's Stone carries 2-8 charges (folio 30)
inline int alcPstoneChargesMin()
    { return 2; }

// the Philosopher's Stone charge ceiling - 8 (folio 30)
inline int alcPstoneChargesMax()
    { return 8; }

// one charge adds 20 percent to a research roll (folio 30)
inline int alcPstoneResearchPct()
    { return 20; }

// one charge transmutes 10,000 weight points of lead into gold or silver
// (folio 30)
inline int alcPstoneTransmuteWt()
    { return 10000; }

// the transmutation is 50 percent gold, 50 percent silver (folio 30)
inline int alcPstoneGoldPct()
    { return 50; }

// while the Philosopher's Stone holds charges it Cures Disease once per day,
// free (folio 30)
inline bool alcPstoneCureDisease()
    { return true; }

// the Alchemist cannot contact a disease while carrying the stone (folio 30)
inline bool alcPstoneDiseaseImmune()
    { return true; }

// the stone is immune to heat, even dragon breath - the molten-lead test; it
// disintegrates when the last charge is used (folio 30)
inline bool alcPstoneHeatImmune()
    { return true; }

}   // namespace rules
