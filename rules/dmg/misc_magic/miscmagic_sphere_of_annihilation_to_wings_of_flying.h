// ====================================================================
// Adnd1 - rules/dmg/misc_magic/miscmagic_sphere_of_annihilation_to_wings_of_flying.h
// R279: the III.E misc magic explanation prose part 23
// (DMG p.156-158) - the Sphere of Annihilation, the Stone
// of Controlling Earth Elementals, the Stone of Good Luck,
// the Stone of Weight, the Talisman of Pure Good, the
// Talisman of the Sphere, the Talisman of Ultimate Evil,
// the Talisman of Zagy, the Tome of Clear Thought, the
// Tome of Leadership and Influence, the Tome of
// Understanding, the Trident of Fish Command, the Trident
// of Submission, the Trident of Warning, the Trident of
// Yearning, the Vacuous Grimoire, the Well of Many Worlds
// and the Wings of Flying, part2 lines 1083-1149
// (global = 11065 + part2 line), pinning the kMisc5 rows
// 17-34 of the 35-row III.E.5 table - the closing slice:
// rows 0-5 landed with part 21, rows 6-16 with part 22
// and rows 17-34 here, the table complete. This round has
// two seams restored: seam A is the p.156-157 page break
// between the Stone of Weight tail (1108) and the
// Talisman of Pure Good head (1113) with the blank pair
// at 1109-1110, the TREASURE (MISCELLANEOUS MAGIC) running
// head at 1111 and the 1112 post-head blank; seam B
// splits the Fish Command paragraph between the 1127 tail
// (but they will not) and the 1129 head (approach closer
// than 10 feet of the trident) across the single 1128
// blank - the p.157-158 page break, no running head
// captured. The upload quirks this round: the foot and
// inch primes print as curly marks; curly quotes wrap to
// hit on the luckstone; curly apostrophes print
// throughout; the minus sign prints true on the Yearning
// cursed weapon; the plus-minus sign prints on the
// luckstone 1 to 10 percent range; a multiplication sign
// prints in the cancellation 3d4 x 10 damage; the OCR
// splits Non- clerics and largest/ deepest with spaces;
// the sphere control table prints as a nine-row level
// grid; the wings durations print as a bare three-line
// list - all pinned as plain digits and words,
// apostrophe-free here. The part1 quirks: the eighteen
// slice rows print side-by-side with armor-table columns
// (part1 9892-9910); the Earth Elementals row wraps its
// name across two lines; the Loadstone, Yearning and
// Vacuous rows print --- in the x.p. column; the Sphere
// and its Talisman carry the (M) marks, the Pure Good
// and Ultimate Evil the (C) marks, the command/warning
// Tridents the (C, F, T) marks and the Submission the
// lone (F). The sphere control grid and the wings
// duration list are pinned as the walkers.
// 110 accessors: 104 scalars + 6 walkers, no name
// collisions with miscprose1.h through miscprose22.h.
// Pure data + helpers, header-only (the grenade.h
// pattern).
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_sphere_of_annihilation_to_wings_of_flying {
public:
    int mmpSphereDiameterFeet();
    int mmpSphereControlRangeFeet();
    int mmpSphereControlPerLevelInches();
    int mmpSphereBaseMoveFeetPerRound();
    int mmpSphereIntBonusLowPct();
    int mmpSphereIntBonusHighPct();
    int mmpSphereIntBonusMaxPct();
    int mmpSphereIntBonusLowStat();
    int mmpSphereIntBonusHighStat();
    int mmpSphereIntBonusMaxStat();
    int mmpSphereDriftRoundsMin();
    int mmpSphereDriftRoundsMax();
    int mmpSphereDriftRangeFeet();
    int mmpSphereMultiUserPenaltyPct();
    int mmpSphereGateDestroyPct();
    int mmpSphereGateNothingPct();
    int mmpSphereGateTearPct();
    int mmpSphereGateTearRadiusInches();
    int mmpSphereCancelRadiusInches();
    int mmpSphereCancelDmgMin();
    int mmpSphereCancelDmgMax();
    int mmpSphereCtlRows();
    int mmpSphereCtlLevelLo(int i);
    int mmpSphereCtlLevelHi(int i);
    int mmpSphereCtlMoveFeet(int i);
    int mmpSphereCtlProbPct(int i);
    int mmpEarthStoneEarthDice();
    int mmpEarthStoneRoughDice();
    int mmpEarthStoneWorkedStoneDice();
    int mmpEarthStoneAreaFeet();
    int mmpEarthStoneVolumeYards();
    int mmpEarthStoneRoundsMin();
    int mmpEarthStoneRoundsMax();
    int mmpEarthStonePerDay();
    int mmpLuckSaveBonus();
    int mmpLuckSavePctBonus();
    int mmpLuckItemPctMin();
    int mmpLuckItemPctMax();
    int mmpLoadMoveReductionPct();
    int mmpLoadAttackReductionPct();
    int mmpLoadDispelClears();
    int mmpPureGoodCharges();
    int mmpPureGoodRechargeable();
    int mmpPureGoodNeutralDmgMin();
    int mmpPureGoodNeutralDmgMax();
    int mmpPureGoodEvilDmgMin();
    int mmpPureGoodEvilDmgMax();
    int mmpPureGoodNonClericDmg();
    int mmpSphereTaliNonMuDmgMin();
    int mmpSphereTaliNonMuDmgMax();
    int mmpSphereTaliLowPctPerPoint();
    int mmpSphereTaliHighPctPerPoint();
    int mmpSphereTaliCheckIntervalRounds();
    int mmpSphereTaliMaxMoveFeet();
    int mmpSphereWandNegationOnTalisman();
    int mmpSphereWandNegationOnSphere();
    int mmpUltimateEvilCharges();
    int mmpZagyHostileDmgMin();
    int mmpZagyHostileDmgMax();
    int mmpZagyNeutralHoursMin();
    int mmpZagyNeutralHoursMax();
    int mmpZagyFriendlyMonthsPerChaPoint();
    int mmpZagyWishChaDivisor();
    int mmpZagyTrapRangeFeet();
    int mmpZagyDiamondGp();
    int mmpClearThoughtIntGain();
    int mmpClearThoughtReadHours();
    int mmpClearThoughtReadDays();
    int mmpClearThoughtStartWeeks();
    int mmpClearThoughtGainMonths();
    int mmpClearThoughtRereadGain();
    int mmpLeadershipChaGain();
    int mmpUnderstandingWisGain();
    int mmpFishCmdRadiusInches();
    int mmpFishCmdChargeCost();
    int mmpFishCmdProtectFeet();
    int mmpFishCmdApproachFeet();
    int mmpFishCmdSchoolsAsOne();
    int mmpFishCmdChargesMin();
    int mmpFishCmdChargesMax();
    int mmpFishCmdMagicBonus();
    int mmpSubmitMoraleDelayRounds();
    int mmpSubmitHopelessRoundsMin();
    int mmpSubmitHopelessRoundsMax();
    int mmpSubmitChargesMin();
    int mmpSubmitChargesMax();
    int mmpSubmitMagicBonus();
    int mmpWarningRadiusInches();
    int mmpWarningScanRounds();
    int mmpWarningChargesMin();
    int mmpWarningChargesMax();
    int mmpWarningChargeRounds();
    int mmpWarningMagicBonus();
    int mmpYearningMagicPenalty();
    int mmpYearningFreeingSpells();
    int mmpYearningGrantsWaterBreathing();
    int mmpVacuousSaveCount();
    int mmpVacuousIntLoss();
    int mmpVacuousWisLoss();
    int mmpVacuousBurnAfterRemoveCurse();
    int mmpWellTwoWay();
    int mmpWingsSpanFeet();
    int mmpWingsRestHours();
    int mmpWingsQuietHours();
    int mmpWingsNoRestTurns();
    int mmpWingsUsesPerDay();
    int mmpWingsSupportPounds();
    int mmpWingsSpeedRows();
    int mmpWingsSpeedTurns(int i);
    int mmpWingsSpeedInches(int i);
};
