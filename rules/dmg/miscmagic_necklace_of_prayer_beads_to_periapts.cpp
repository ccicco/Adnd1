// R-refactor: split from miscmagic_necklace_of_prayer_beads_to_periapts.h - definitions
#include "rules/dmg/miscmagic_necklace_of_prayer_beads_to_periapts.h"

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpBeadStoneMin() {
    // the necklace consists of 25-30 stones
    return 25;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpBeadStoneMax() {
    // the upper edge of the 25-30 stones
    return 30;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpBeadSemiPreciousPct() {
    // 60 percent semi-precious stones
    return 60;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpBeadFancyPct() {
    // 40 percent fancy stones
    return 40;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpBeadPetitionBonusPct() {
    // 25 percent more likely to petition the deity
    return 25;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpBeadSpecialMin() {
    // 3-6 special beads
    return 3;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpBeadSpecialMax() {
    // the upper edge of the 3-6 special beads
    return 6;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpBeadGemBaseGp() {
    // precious stones of 1,000 gp base value
    return 1000;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpBeadUsesPerDay() {
    // each special bead once per day
    return 1;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpBeadKarmaLevels() {
    // the karma bead casts 4 levels higher
    return 4;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpBeadSummonsPct() {
    // the summons bead calls the deity at 90 percent
    return 90;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpBeadRowLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 6, 11, 16, 18, 19,
    };
    return t[i];
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpBeadRowHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        5, 10, 15, 17, 18, 20,
    };
    return t[i];
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpStrangleDamagePerRound() {
    // 6 hit points of strangulation damage per round
    return 6;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpEntrapMinStrength() {
    // defies strength under 20
    return 20;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpEntrapCutAc() {
    // equal to AC -10 against cutting blows
    return -10;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpEntrapSizeFeet() {
    // each net is 10 feet square
    return 10;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpEntrapMeshQuarterFeet() {
    // with a quarter-foot mesh
    return 1;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpEntrapThrowFeet() {
    // it can be thrown 20 feet
    return 20;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpEntrapCloseCubeFeet() {
    // stretches to close over a 5 foot cube
    return 5;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpSnareRangeInches() {
    // shoots forth up to 3 inches underwater
    return 3;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPigPotCubicFeet() {
    // one pot creates a 1,000 cubic foot object
    return 1000;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPigDepictSquareFeet() {
    // depicted over a 100 square foot surface
    return 100;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPigContainersMin() {
    // from 1-4 containers found
    return 1;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPigContainersMax() {
    // the upper edge of the 1-4 containers
    return 4;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPigInstrumentFeet() {
    // a single instrument about 1 foot long
    return 1;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPigDepictTurns() {
    // 1 turn to depict an object
    return 1;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPowerRecallPerDay() {
    // once a day the pearl recalls
    return 1;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPowerSpellsRecalled() {
    // recalls any 1 spell as desired
    return 1;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPowerReverseOneIn() {
    // 1 in 20 of opposite effect
    return 20;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPowerDoubleMin() {
    // the 00 row recalls 2 spells
    return 2;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPowerDoubleMaxLevel() {
    // of 1st to 6th level
    return 6;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPowerDoubleDieSides() {
    // the level picked by d6
    return 6;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPowerRowLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    static const int t[10] = {
        1, 26, 46, 61, 76, 86, 93, 97, 99, 100,
    };
    return t[i];
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPowerRowHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    static const int t[10] = {
        25, 45, 60, 75, 85, 92, 96, 98, 99, 100,
    };
    return t[i];
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPowerSpellLevel(int i) {
    // the spell level per die band, the 00 row
    // marked 0 for the double-spell special; clamps
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    static const int t[10] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
    };
    return t[i];
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpWisdomGain() {
    // the cleric gains 1 point of wisdom
    return 1;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpWisdomMonths() {
    // retained for a 1 month period
    return 1;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpWisdomDays() {
    // the gain at the expiration of 30 days
    return 30;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpWisdomReverseOneIn() {
    // 1 in 20 cursed to work in reverse
    return 20;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpRotAbilityLossPerWeek() {
    // 1 point per ability per week
    return 1;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpRotStartWeek() {
    // beginning 1 week after claiming
    return 1;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpRotAbilityCount() {
    // dexterity, constitution and charisma
    return 3;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpRotDeathScore() {
    // dead when any score reaches 0
    return 0;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPoisonSavePctPerPlus() {
    // a 10 percent saving throw per plus
    return 10;
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPoisonRowLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 9, 15, 19,
    };
    return t[i];
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPoisonRowHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        8, 14, 18, 20,
    };
    return t[i];
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpPoisonPlus(int i) {
    // the plus of periapt per die band; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 2, 3, 4,
    };
    return t[i];
}

int Miscmagic_necklace_of_prayer_beads_to_periapts::mmpWoundHealRateMult() {
    // doubles the normal rate of healing
    return 2;
}
