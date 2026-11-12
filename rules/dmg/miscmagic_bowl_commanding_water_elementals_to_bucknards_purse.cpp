// R-refactor: split from miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.h - definitions
#include "rules/dmg/miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.h"

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBowlCmdHd() {
    // the summoned water elemental
    return 12;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBowlCmdWordsRounds() {
    // the summoning words take 1 round
    return 1;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBowlCmdSaltBonusPerDie() {
    // salt water: +2 per hit die
    return 2;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBowlCmdSaltMaxHpPerDie() {
    // salt water: max 8 hp per die
    return 8;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBowlCmdDiameterInches() {
    // about 1 foot across
    return 12;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBowlCmdDepthInches() {
    // half the diameter
    return 6;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpWateryDeathSaltSavePenalty() {
    // salt water: the save is at minus 2
    return 2;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpWateryDeathDrownMinRounds() {
    // the victim drowns in 3-8 rounds
    return 3;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpWateryDeathDrownMaxRounds() {
    // the victim drowns in 3-8 rounds
    return 8;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpWateryDeathFreeSpellCount() {
    // animal growth, enlarge, wish
    return 3;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpWateryDeathDeathPermanent() {
    // no resurrection, even a wish fails
    return 1;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpWateryDeathSweetWaterAnotherSave() {
    // a sweet water potion: another save
    return 1;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBracersDefRowCount() {
    // the random AC table rows
    return 7;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBracersDefAcMin() {
    // the 86-00 row
    return 2;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBracersDefAcMax() {
    // the 01-05 row
    return 8;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpDefenselessAc() {
    // lowers armor class to 10
    return 10;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpDefenselessNegatesProtections() {
    // all protections and dex bonuses
    return 1;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpDefenselessRemoveCurseOnly() {
    // only remove curse takes them off
    return 1;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBrazierFireHd() {
    // the summoned fire elemental
    return 12;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBrazierFireLightRounds() {
    // lighting the fire usually takes 1 round
    return 1;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBrazierFireSulphurBonusPerDie() {
    // sulphur: +1 on each hit die
    return 1;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBrazierFireSulphurHpMin() {
    // sulphur: 2-9 hp per die
    return 2;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBrazierFireSulphurHpMax() {
    // sulphur: 2-9 hp per die
    return 9;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpSleepSmokeRadiusInches() {
    // the smoke cloud radius
    return 1;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpSleepSmokeHd() {
    // the fire elemental that appears
    return 12;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpSleepSmokeAwakenSpellCount() {
    // dispel magic or remove curse
    return 2;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroochPctWithoutGems() {
    // usually without gems inset
    return 90;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroochAbsorbHp() {
    // absorbs magic missile damage, then melts
    return 101;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomAttackDumpMinFeet() {
    // dumps the rider from 6 feet
    return 6;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomAttackDumpMaxFeet() {
    // dumps the rider up to 9 feet
    return 9;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomAttackAttacksPerRound() {
    // each attack twice per round
    return 2;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomAttackAsHd() {
    // attacks as a 4 hit die monster
    return 4;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomAttackStrawBlindRounds() {
    // the straw end blinds for 1 round
    return 1;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomAttackHandleDmgMin() {
    // the handle end: 1-3 hp
    return 1;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomAttackHandleDmgMax() {
    // the handle end: 1-3 hp
    return 3;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomAttackAc() {
    // the broom armor class
    return 7;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomAttackHpToDestroy() {
    // hit points to destroy
    return 18;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomFlySpeedInches() {
    // movement speed
    return 30;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomFlyCapacityPounds() {
    // carries 182 pounds at speed
    return 182;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomFlyPoundsPerInch() {
    // every 14 pounds slows 1 inch
    return 14;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomFlyClimbDiveDegrees() {
    // climb or dive angle
    return 30;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBroomFlyFetchSpeedInches() {
    // comes to its owner at up to 30
    return 30;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpPurseCoinsPerType() {
    // 26 of each applicable type, next morning
    return 26;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpPurseTypeRowCount() {
    // the type bands
    return 3;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpPurseGemsBaseGp() {
    // base gems
    return 10;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpPurseGemsMaxGp() {
    // gems may increase to 100 at most
    return 100;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpPurseAbilitiesNeverChange() {
    // once rolled, the type never changes
    return 1;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpPurseSpiceNote() {
    // the design note: a constant fund source
    return 1;
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBracersDefBandLo(int i) {
    // printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 6, 16, 36, 51, 71, 86,
    };
    return t[i];
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBracersDefBandHi(int i) {
    // printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        5, 15, 35, 50, 70, 85, 100,
    };
    return t[i];
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpBracersDefAc(int i) {
    // the armor class per band; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        8, 7, 6, 5, 4, 3, 2,
    };
    return t[i];
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpPurseTypeBandLo(int i) {
    // the type band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 51, 91,
    };
    return t[i];
}

int Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse::mmpPurseTypeBandHi(int i) {
    // the type band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        50, 90, 100,
    };
    return t[i];
}
