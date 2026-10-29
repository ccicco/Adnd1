// =========================================================================================
// Adnd1 - rules/spr.h
// The specialists round - Hettlestad's Healers (folios 22-23) and Mumper's
// Scribes (folios 23, 25)
// census 818 -> 819.
//
// Pinned from The Dragon Vol. 1 No. 3 (October 1976): folios 22-23, C.
// Hettlestad's Healers - the rapid-repair class with its 15-each
// prerequisites, the 8-sided hit dice, the level-unlock abilities at 4th,
// 8th, 12th, 16th and 20th, and the twenty-five-level ladder with its
// spell-progression grid; folios 23 and 25, David Mumper's Scribes - the rare
// and expensive specialists who alone may transcribe magical writing, with
// the find and leave chances, the hire rates, the six-grade ability ladder
// with its mistake and insanity percents, and the alignment bands by
// vocation. The editor's caution rides: none of this is official, and the
// alchemist precedent holds - specialists are non-player-character
// recommended.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon. The
// Healer's printed hit-dice forms 10+N are CONVERTED to base-plus-bonus
// columns and the spell-grid dashes CONVERTED to zeros, both conversions
// noted, never silent; the Scribe alignment block garbles in OCR and pins AS
// SCANNED with the clerical vocation's missing neutral band carried as the
// sentinel 9; the mistake percent pairs read as within-abilities over
// above-abilities and pin as scanned. The Healer and Scribe ride the variant
// layer against the engine's canon class frame, never a rewrite.
//
namespace rules {

// ---- the Healer (folios 22-23) ----

// the Healer ladder runs twenty-five levels, Apprentice through Doctor 25th
// (folios 22-23)
inline int sprHealerLevels()
    { return 25; }

// the experience ladder - Apprentice 0 through Doctor 25th at 1,900,000
// (folio 22)
inline int sprHealXp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5000;
        case 2:
            return 10000;
        case 3:
            return 15000;
        case 4:
            return 25000;
        case 5:
            return 50000;
        case 6:
            return 100000;
        case 7:
            return 200000;
        case 8:
            return 300000;
        case 9:
            return 400000;
        case 10:
            return 500000;
        case 11:
            return 600000;
        case 12:
            return 700000;
        case 13:
            return 800000;
        case 14:
            return 900000;
        case 15:
            return 1000000;
        case 16:
            return 1100000;
        case 17:
            return 1200000;
        case 18:
            return 1300000;
        case 19:
            return 1400000;
        case 20:
            return 1500000;
        case 21:
            return 1600000;
        case 22:
            return 1700000;
        case 23:
            return 1800000;
        case 24:
            return 1900000;
        default:
            return 9;
        }
    }

// the hit-dice base split from the printed "10+N" forms, the conversion noted
// - 1 through 10 by level, then 10 flat (folio 22)
inline int sprHealHitBase(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 10;
        case 13:
            return 10;
        case 14:
            return 10;
        case 15:
            return 10;
        case 16:
            return 10;
        case 17:
            return 10;
        case 18:
            return 10;
        case 19:
            return 10;
        case 20:
            return 10;
        case 21:
            return 10;
        case 22:
            return 10;
        case 23:
            return 10;
        case 24:
            return 10;
        default:
            return 9;
        }
    }

// the hit-dice bonus - flat from 10+1 at 11th level to 10+15 at 25th (folio
// 22)
inline int sprHealHitBonus(int b)
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
            return 3;
        case 13:
            return 4;
        case 14:
            return 5;
        case 15:
            return 6;
        case 16:
            return 7;
        case 17:
            return 8;
        case 18:
            return 9;
        case 19:
            return 10;
        case 20:
            return 11;
        case 21:
            return 12;
        case 22:
            return 13;
        case 23:
            return 14;
        case 24:
            return 15;
        default:
            return 9;
        }
    }

// the first-level spell count per level, the printed dashes CONVERTED to
// zeros, the conversion noted (folio 22)
inline int sprHealSp1(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 5;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 6;
        case 16:
            return 6;
        case 17:
            return 6;
        case 18:
            return 7;
        case 19:
            return 7;
        case 20:
            return 7;
        case 21:
            return 8;
        case 22:
            return 8;
        case 23:
            return 8;
        case 24:
            return 9;
        default:
            return 9;
        }
    }

// the second-level spell count (folio 22)
inline int sprHealSp2(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 6;
        case 17:
            return 6;
        case 18:
            return 6;
        case 19:
            return 7;
        case 20:
            return 7;
        case 21:
            return 7;
        case 22:
            return 8;
        case 23:
            return 8;
        case 24:
            return 8;
        default:
            return 9;
        }
    }

// the third-level spell count (folio 22)
inline int sprHealSp3(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
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
            return 3;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 6;
        case 18:
            return 6;
        case 19:
            return 6;
        case 20:
            return 7;
        case 21:
            return 7;
        case 22:
            return 7;
        case 23:
            return 8;
        case 24:
            return 8;
        default:
            return 9;
        }
    }

// the fourth-level spell count (folio 22)
inline int sprHealSp4(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 6;
        case 19:
            return 6;
        case 20:
            return 6;
        case 21:
            return 7;
        case 22:
            return 7;
        case 23:
            return 7;
        case 24:
            return 8;
        default:
            return 9;
        }
    }

// the fifth-level spell count (folio 22)
inline int sprHealSp5(int b)
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
            return 1;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 6;
        case 20:
            return 6;
        case 21:
            return 6;
        case 22:
            return 7;
        case 23:
            return 7;
        case 24:
            return 7;
        default:
            return 9;
        }
    }

// the sixth-level spell count (folio 22)
inline int sprHealSp6(int b)
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
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 6;
        case 21:
            return 6;
        case 22:
            return 6;
        case 23:
            return 7;
        case 24:
            return 7;
        default:
            return 9;
        }
    }

// the seventh-level spell count (folio 22)
inline int sprHealSp7(int b)
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
            return 1;
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
            return 3;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 5;
        case 21:
            return 6;
        case 22:
            return 6;
        case 23:
            return 6;
        case 24:
            return 7;
        default:
            return 9;
        }
    }

// the Healer prerequisites are high - a minimum score of 15 EACH in
// intelligence, wisdom and dexterity (folio 22)
inline int sprHealStatMin()
    { return 15; }

// the Healer can only be lawful or neutral - a chaotic healer is not allowed
// and would become a mere fighter if forced to change alignment (folio 22)
inline bool sprHealerLawfulNeutralOnly()
    { return true; }

// Healers may not wear any armor or shield, but may use any weapons and/or
// magical items (folio 22)
inline bool sprHealerNoArmorShield()
    { return true; }

// the various books to be found will not aid the healer in any way and can
// only hurt (folio 22)
inline bool sprHealBooksOnlyHurt()
    { return true; }

// the Healer rolls 8-sided hit dice (folio 22)
inline int sprHealHitDieSides()
    { return 8; }

// the Medic at 10th level is the highest level for a Dwarf Healer (folio 22)
inline int sprHealDwarfMaxLevel()
    { return 10; }

// the Doctor at 14th level is the highest for a Hobbit, Half-Elf or Elf
// Healer (folio 22)
inline int sprHealDemiHumanMaxLevel()
    { return 14; }

// at 4th level the Healer can detect molds, slimes, etc. at 40 feet (folio
// 22)
inline int sprHealDetectRangeFeet()
    { return 40; }

// the Detect Poison spell allows determining poison use within a 30-foot
// radius, and its type (folio 23)
inline int sprHealDetectPoisonRangeFeet()
    { return 30; }

// Detect Disease tells what disease is present within a 30-foot range (folio
// 23)
inline int sprHealDetectDiseaseRangeFeet()
    { return 30; }

// Detect Phase finds out-of-phase treasure and creatures, duration 6 turns
// (folio 23)
inline int sprHealDetectPhaseTurns()
    { return 6; }

// at 16th level the Healer can use 4 first-level magic-user spells, at 20th 4
// second-level ones (folio 22)
inline int sprHealMuSpellCount()
    { return 4; }

// the 16th-level unlock is the first magic-user spell level (folio 22)
inline int sprHealMuSpellLevelOne()
    { return 1; }

// the 20th-level unlock is the second (folio 22)
inline int sprHealMuSpellLevelTwo()
    { return 2; }

// the Remove Charm spell carries a range of 3 inches (folio 23)
inline int sprHealRemoveCharmRangeInches()
    { return 3; }

// the Longevity spell reduces 10 game-years of game-age, countering a staff
// of withering or ghost attack (folio 23)
inline int sprHealLongevityYears()
    { return 10; }

// the Sterilize spell cleanses a room of infection, mold, slime or nasty
// creatures up to 5 hit die (folio 23)
inline int sprHealSterilizeHdCap()
    { return 5; }

// the Improved Cure Serious Wounds spell cures four 6-sided dice worth of
// damage (folio 23)
inline int sprHealIcswDice()
    { return 4; }

// each die is a 6-sider (folio 23)
inline int sprHealIcswDieSides()
    { return 6; }

// with an addition of 1 per die (folio 23)
inline int sprHealIcswBonusPerDie()
    { return 1; }

// so the range runs 8 hit points at the floor (folio 23)
inline int sprHealIcswMinDamage()
    { return 8; }

// to 24 at the ceiling (folio 23)
inline int sprHealIcswMaxDamage()
    { return 24; }

// ---- the Scribe (folios 23, 25) ----

// the Scribe belongs to either of two vocations - transcribing magical spells
// or clerical spells (folio 23)
inline int sprScribeVocations()
    { return 2; }

// the percentile ceiling of the lawful band for this vocation - magical
// 01-70, clerical 01-80 (folio 23)
inline int sprScrLawfulMax(int b)
    {
        switch (b) {
        case 0:
            return 70;
        case 1:
            return 80;
        default:
            return 9;
        }
    }

// the neutral band ceiling - magical 71-90; the clerical vocation carries NO
// neutral band, pinned as the sentinel 9, as scanned (folio 23)
inline int sprScrNeutralMax(int b)
    {
        switch (b) {
        case 0:
            return 90;
        case 1:
            return 9;
        default:
            return 9;
        }
    }

// the chaotic band closes at 00 - magical 91-00, clerical 81-00 (folio 23)
inline int sprScrChaoticMax(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 100;
        default:
            return 9;
        }
    }

// the Scribe ability ladder runs six grades on the percentile dice (folio 23)
inline int sprScribeGrades()
    { return 6; }

// the highest spell level transcribed at this grade - 1-3 through 1-9 (folio
// 23)
inline int sprScrSpellMax(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 7;
        case 4:
            return 8;
        case 5:
            return 9;
        default:
            return 9;
        }
    }

// the percent mistake within his abilities, as scanned - 25 down to 1 by
// grade (folio 23)
inline int sprScrMistakeNormal(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 15;
        case 2:
            return 10;
        case 3:
            return 5;
        case 4:
            return 2;
        case 5:
            return 1;
        default:
            return 9;
        }
    }

// the percent mistake when attempting spells ABOVE his abilities, as scanned
// - 75 down to 3 (folio 23)
inline int sprScrMistakeAbove(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 45;
        case 2:
            return 30;
        case 3:
            return 15;
        case 4:
            return 6;
        case 5:
            return 3;
        default:
            return 9;
        }
    }

// the percent insanity when attempting spells above his abilities - 35 down
// to 5 (folio 23)
inline int sprScrInsanityAbove(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 25;
        case 2:
            return 20;
        case 3:
            return 15;
        case 4:
            return 10;
        case 5:
            return 5;
        default:
            return 9;
        }
    }

// there exists a curse upon all magical writing which causes any but Scribes,
// who know the counter-spell, to go permanently and incurably insane - Remove
// Curse notwithstanding (folio 23)
inline bool sprScribeCurseOnWriting()
    { return true; }

// Scribes are free-lance and must be sought like any other Specialist (folio
// 23)
inline bool sprScribeFreelanceSearch()
    { return true; }

// the chance of finding a Scribe is 10 percent per week, cumulative (folio
// 23)
inline int sprScribeFindPct()
    { return 10; }

// the cost of hiring a Scribe runs the specialist rate - from 100 gold pieces
// a week (folio 23)
inline int sprScribeCostMinGold()
    { return 100; }

// to 600 gold pieces a week (folio 23)
inline int sprScribeCostMaxGold()
    { return 600; }

// the Scribe's fee runs from 1000 gold pieces a month (folio 25)
inline int sprScribeFeeMinGold()
    { return 1000; }

// to 5000 gold pieces a month (folio 25)
inline int sprScribeFeeMaxGold()
    { return 5000; }

// being free souls there is a 5 percent chance, cumulative, that the Scribe
// leaves each month (folio 25)
inline int sprScribeLeavePct()
    { return 5; }

// if the Scribe goes insane the percent mistake goes to 100 (folio 25)
inline int sprScribeInsanityMistakePct()
    { return 100; }

// Scribe insanity is detectable only by ESP and the like (folio 25)
inline bool sprScribeInsanityEspOnly()
    { return true; }

// if the Scribe's alignment differs from the employer the mistake percent
// doubles in a lawful-chaotic/neutral relationship (folio 25)
inline int sprScribeAlignmentDouble()
    { return 2; }

// and TRIPLES in a lawful/chaotic one (folio 25)
inline int sprScribeAlignmentTriple()
    { return 3; }

// for every 5 spells transcribed (folio 25)
inline int sprScribeGrowthSpells()
    { return 5; }

// the Scribe's ability rises by 2 (folio 25)
inline int sprScribeGrowthPoints()
    { return 2; }

// when a mistake is made the result is at the discretion of the referee, and
// mistakes may not be corrected (folio 25)
inline bool sprScribeMistakesUncorrectable()
    { return true; }

}   // namespace rules
