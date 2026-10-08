// ====================================================================
// Adnd1 - rules/miscprose4.h
// R260: the III.E misc magic explanation prose part 4
// (DMG p.132) - Bowl Commanding Water Elementals
// through Bucknard Everfull Purse, part2 lines
// 110-153 (global = 11065 + part2 line). ONE page
// header inside the slice (line 127, the TREASURE
// page) splits the Bracers of Defense table from
// Bracers of Defenselessness - stripped per the
// R249 lesson; no mid-sentence seam this time.
// 53 accessors: 48 scalars + 5 array walkers, no
// name collisions with miscprose1.h through
// miscprose3.h. The purse type-table coin columns
// are mangled in the upload - only the band
// edges and the 26-per-type are pinned (the
// R256 lesson).
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpBowlCmdHd() {
    // the summoned water elemental
    return 12;
}

inline int mmpBowlCmdWordsRounds() {
    // the summoning words take 1 round
    return 1;
}

inline int mmpBowlCmdSaltBonusPerDie() {
    // salt water: +2 per hit die
    return 2;
}

inline int mmpBowlCmdSaltMaxHpPerDie() {
    // salt water: max 8 hp per die
    return 8;
}

inline int mmpBowlCmdDiameterInches() {
    // about 1 foot across
    return 12;
}

inline int mmpBowlCmdDepthInches() {
    // half the diameter
    return 6;
}

inline int mmpWateryDeathSaltSavePenalty() {
    // salt water: the save is at minus 2
    return 2;
}

inline int mmpWateryDeathDrownMinRounds() {
    // the victim drowns in 3-8 rounds
    return 3;
}

inline int mmpWateryDeathDrownMaxRounds() {
    // the victim drowns in 3-8 rounds
    return 8;
}

inline int mmpWateryDeathFreeSpellCount() {
    // animal growth, enlarge, wish
    return 3;
}

inline int mmpWateryDeathDeathPermanent() {
    // no resurrection, even a wish fails
    return 1;
}

inline int mmpWateryDeathSweetWaterAnotherSave() {
    // a sweet water potion: another save
    return 1;
}

inline int mmpBracersDefRowCount() {
    // the random AC table rows
    return 7;
}

inline int mmpBracersDefAcMin() {
    // the 86-00 row
    return 2;
}

inline int mmpBracersDefAcMax() {
    // the 01-05 row
    return 8;
}

inline int mmpDefenselessAc() {
    // lowers armor class to 10
    return 10;
}

inline int mmpDefenselessNegatesProtections() {
    // all protections and dex bonuses
    return 1;
}

inline int mmpDefenselessRemoveCurseOnly() {
    // only remove curse takes them off
    return 1;
}

inline int mmpBrazierFireHd() {
    // the summoned fire elemental
    return 12;
}

inline int mmpBrazierFireLightRounds() {
    // lighting the fire usually takes 1 round
    return 1;
}

inline int mmpBrazierFireSulphurBonusPerDie() {
    // sulphur: +1 on each hit die
    return 1;
}

inline int mmpBrazierFireSulphurHpMin() {
    // sulphur: 2-9 hp per die
    return 2;
}

inline int mmpBrazierFireSulphurHpMax() {
    // sulphur: 2-9 hp per die
    return 9;
}

inline int mmpSleepSmokeRadiusInches() {
    // the smoke cloud radius
    return 1;
}

inline int mmpSleepSmokeHd() {
    // the fire elemental that appears
    return 12;
}

inline int mmpSleepSmokeAwakenSpellCount() {
    // dispel magic or remove curse
    return 2;
}

inline int mmpBroochPctWithoutGems() {
    // usually without gems inset
    return 90;
}

inline int mmpBroochAbsorbHp() {
    // absorbs magic missile damage, then melts
    return 101;
}

inline int mmpBroomAttackDumpMinFeet() {
    // dumps the rider from 6 feet
    return 6;
}

inline int mmpBroomAttackDumpMaxFeet() {
    // dumps the rider up to 9 feet
    return 9;
}

inline int mmpBroomAttackAttacksPerRound() {
    // each attack twice per round
    return 2;
}

inline int mmpBroomAttackAsHd() {
    // attacks as a 4 hit die monster
    return 4;
}

inline int mmpBroomAttackStrawBlindRounds() {
    // the straw end blinds for 1 round
    return 1;
}

inline int mmpBroomAttackHandleDmgMin() {
    // the handle end: 1-3 hp
    return 1;
}

inline int mmpBroomAttackHandleDmgMax() {
    // the handle end: 1-3 hp
    return 3;
}

inline int mmpBroomAttackAc() {
    // the broom armor class
    return 7;
}

inline int mmpBroomAttackHpToDestroy() {
    // hit points to destroy
    return 18;
}

inline int mmpBroomFlySpeedInches() {
    // movement speed
    return 30;
}

inline int mmpBroomFlyCapacityPounds() {
    // carries 182 pounds at speed
    return 182;
}

inline int mmpBroomFlyPoundsPerInch() {
    // every 14 pounds slows 1 inch
    return 14;
}

inline int mmpBroomFlyClimbDiveDegrees() {
    // climb or dive angle
    return 30;
}

inline int mmpBroomFlyFetchSpeedInches() {
    // comes to its owner at up to 30
    return 30;
}

inline int mmpPurseCoinsPerType() {
    // 26 of each applicable type, next morning
    return 26;
}

inline int mmpPurseTypeRowCount() {
    // the type bands
    return 3;
}

inline int mmpPurseGemsBaseGp() {
    // base gems
    return 10;
}

inline int mmpPurseGemsMaxGp() {
    // gems may increase to 100 at most
    return 100;
}

inline int mmpPurseAbilitiesNeverChange() {
    // once rolled, the type never changes
    return 1;
}

inline int mmpPurseSpiceNote() {
    // the design note: a constant fund source
    return 1;
}

inline int mmpBracersDefBandLo(int i) {
    // printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 6, 16, 36, 51, 71, 86,
    };
    return t[i];
}

inline int mmpBracersDefBandHi(int i) {
    // printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        5, 15, 35, 50, 70, 85, 100,
    };
    return t[i];
}

inline int mmpBracersDefAc(int i) {
    // the armor class per band; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        8, 7, 6, 5, 4, 3, 2,
    };
    return t[i];
}

inline int mmpPurseTypeBandLo(int i) {
    // the type band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 51, 91,
    };
    return t[i];
}

inline int mmpPurseTypeBandHi(int i) {
    // the type band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        50, 90, 100,
    };
    return t[i];
}

} // namespace rules
