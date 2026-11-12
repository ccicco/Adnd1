// R-refactor: split from miscmagic_incense_of_obsession_to_fochlucan_bandore.h - definitions
#include "rules/dmg/miscmagic_incense_of_obsession_to_fochlucan_bandore.h"

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpObsessionDurationHours() {
    // the cleric remains obsessed until all spells
    // are cast or 24 hours have elapsed
    return 24;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpObsessionPiecesMin() {
    // there are 2-8 pieces of this incense normally
    return 2;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpObsessionPiecesMax() {
    // the upper edge of the normal 2-8 pieces
    return 8;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpObsessionBurnHours() {
    // each piece burns for 1 hour
    return 1;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounSortCount() {
    // there are 14 sorts of useful ioun stones
    return 14;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounOwnerRadiusFeet() {
    // the stones must be within 3 feet of their
    // owner to be efficacious
    return 3;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounOrbitMinFeet() {
    // the circling orbit starts at a 1 foot radius
    return 1;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounOrbitMaxFeet() {
    // the circling orbit tops at a 3 foot radius
    return 3;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounFoundMin() {
    // from 1-10 ioun stones will be found
    return 1;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounFoundMax() {
    // the upper edge of the 1-10 found
    return 10;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounTableRowCount() {
    // the property table has 15 rows
    return 15;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounDeadRowLo() {
    // the dull gray dead band starts at roll 15
    return 15;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounDeadRowHi() {
    // and ends at roll 20
    return 20;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounStatBonusPoints() {
    // the six stat stones add 1 point to the score
    return 1;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounStatCap() {
    // with an 18 maximum
    return 18;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounStatBonusRowCount() {
    // six stones add to a stat score
    return 6;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounLevelGainLevels() {
    // the pale green prism adds 1 level of
    // experience
    return 1;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounRegenHpPerTurn() {
    // the pearly white spindle regenerates 1 hit
    // point of damage per turn
    return 1;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounPurpleStoreMin() {
    // the vibrant purple prism stores 2-12 levels
    return 2;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounPurpleStoreMax() {
    // the upper edge of the stored 2-12 levels
    return 12;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounRoseProtectionBonus() {
    // the dusty rose prism gives +1 protection
    return 1;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounGrayPsionicBonus() {
    // the dead gray stone adds 10 points to the
    // psionic strength total
    return 10;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounGrayPsionicCap() {
    // the psionic strength total caps at 50 points
    return 50;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounHpToDestroy() {
    // the stones take 10 hit points of damage to
    // destroy
    return 10;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounSaveBonus() {
    // they save as if they were of hard metal, +3
    return 3;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounAttackAc() {
    // exposed to attack they are treated as armor
    // class -4 (the minus rides the comment)
    return 4;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounRowRollLo(int i) {
    // the printed roll lower edges, rolls 1-14
    // then the dead band; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15,
    };
    return t[i];
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounRowRollHi(int i) {
    // the printed roll upper edges, the dead band
    // topping at 20; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 20,
    };
    return t[i];
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounRowAddsStat(int i) {
    // the rolls 1-6 stones add to a stat score;
    // i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounRowAbsorbMaxLevel(int i) {
    // the roll 11 and 12 stones absorb spells up
    // to the 4th and 8th level; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        4, 8, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounRowBurnoutMin(int i) {
    // the absorbed spell levels that burn a
    // stone out, the lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        10, 20, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpIounRowBurnoutMax(int i) {
    // the absorbed spell levels that burn a
    // stone out, the upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        40, 80, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpBardInstrumentCount() {
    // there are 7 magical instruments
    return 7;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanStringCount() {
    // the small, 3-stringed bandore
    return 3;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanLowestFaeriePct() {
    // a 1st level bard or a non-bard: a 50
    // percent chance per round of playing to
    // cast a faerie fire spell
    return 50;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanLowestReversePct() {
    // a 10 percent chance the musician is
    // limned by the glow instead
    return 10;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanFaerieBasePct() {
    // a bard of Fochlucan or higher college
    // casts the faerie fire at base 50 percent
    return 50;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanReverseReductionPerLevelPct() {
    // the reverse effect reduced by 1 percent
    // per level above 1st
    return 1;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanSongCount() {
    // the bandore has 4 song properties when
    // properly played
    return 4;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanCharmBonusPct() {
    // adds 10 percent to the bard charm
    // percentage
    return 10;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanEntanglePerDay() {
    // casts an entangle spell once per day
    return 1;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanShillelaghPerDay() {
    // casts a shillelagh spell once per day
    return 1;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanSpeakAnimalsPerDay() {
    // enables the bard to speak with animals
    // once per day
    return 1;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanLowestSongWorkPct() {
    // a 1st level bard attempts the powers: a
    // 30 percent chance they work
    return 30;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanLowestSongFailPct() {
    // a 70 percent chance of the mishap
    return 70;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanLowestFailDamageMin() {
    // the mishap deals 2-8 hit points of damage
    return 2;
}

int Miscmagic_incense_of_obsession_to_fochlucan_bandore::mmpFochlucanLowestFailDamageMax() {
    // the upper edge of the 2-8 damage
    return 8;
}
