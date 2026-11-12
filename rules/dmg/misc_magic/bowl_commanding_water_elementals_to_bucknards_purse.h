// ====================================================================
// Adnd1 - rules/dmg/misc_magic/bowl_commanding_water_elementals_to_bucknards_purse.h
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
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse {
public:
    int mmpBowlCmdHd();
    int mmpBowlCmdWordsRounds();
    int mmpBowlCmdSaltBonusPerDie();
    int mmpBowlCmdSaltMaxHpPerDie();
    int mmpBowlCmdDiameterInches();
    int mmpBowlCmdDepthInches();
    int mmpWateryDeathSaltSavePenalty();
    int mmpWateryDeathDrownMinRounds();
    int mmpWateryDeathDrownMaxRounds();
    int mmpWateryDeathFreeSpellCount();
    int mmpWateryDeathDeathPermanent();
    int mmpWateryDeathSweetWaterAnotherSave();
    int mmpBracersDefRowCount();
    int mmpBracersDefAcMin();
    int mmpBracersDefAcMax();
    int mmpDefenselessAc();
    int mmpDefenselessNegatesProtections();
    int mmpDefenselessRemoveCurseOnly();
    int mmpBrazierFireHd();
    int mmpBrazierFireLightRounds();
    int mmpBrazierFireSulphurBonusPerDie();
    int mmpBrazierFireSulphurHpMin();
    int mmpBrazierFireSulphurHpMax();
    int mmpSleepSmokeRadiusInches();
    int mmpSleepSmokeHd();
    int mmpSleepSmokeAwakenSpellCount();
    int mmpBroochPctWithoutGems();
    int mmpBroochAbsorbHp();
    int mmpBroomAttackDumpMinFeet();
    int mmpBroomAttackDumpMaxFeet();
    int mmpBroomAttackAttacksPerRound();
    int mmpBroomAttackAsHd();
    int mmpBroomAttackStrawBlindRounds();
    int mmpBroomAttackHandleDmgMin();
    int mmpBroomAttackHandleDmgMax();
    int mmpBroomAttackAc();
    int mmpBroomAttackHpToDestroy();
    int mmpBroomFlySpeedInches();
    int mmpBroomFlyCapacityPounds();
    int mmpBroomFlyPoundsPerInch();
    int mmpBroomFlyClimbDiveDegrees();
    int mmpBroomFlyFetchSpeedInches();
    int mmpPurseCoinsPerType();
    int mmpPurseTypeRowCount();
    int mmpPurseGemsBaseGp();
    int mmpPurseGemsMaxGp();
    int mmpPurseAbilitiesNeverChange();
    int mmpPurseSpiceNote();
    int mmpBracersDefBandLo(int i);
    int mmpBracersDefBandHi(int i);
    int mmpBracersDefAc(int i);
    int mmpPurseTypeBandLo(int i);
    int mmpPurseTypeBandHi(int i);
};
