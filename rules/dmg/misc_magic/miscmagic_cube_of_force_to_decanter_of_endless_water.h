// ====================================================================
// Adnd1 - rules/dmg/misc_magic/miscmagic_cube_of_force_to_decanter_of_endless_water.h
// R263: the III.E misc magic explanation prose part 7
// (DMG p.132-133) - Cube of Force through Decanter
// of Endless Water, part2 lines 285-322 (global =
// 11065 + part2 line). ZERO page headers inside the
// slice (a first); ONE seam pins exactly: the Daern
// (line 314 ends but the person or, line 316
// continues persons nearby). 45 accessors: 42
// scalars + 3 array walkers, no name collisions
// with miscprose1.h through miscprose6.h. The slice
// completes kMisc2 rows 13-17; this stretch carries
// no class marks and no asterisk rows (the negative
// control slice). Pure data + helpers, header-only
// (the grenade.h pattern).
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_cube_of_force_to_decanter_of_endless_water {
public:
    int mmpCubeForceWallInches();
    int mmpCubeForceCharges();
    int mmpCubeForceRestoreDays();
    int mmpCubeForceFaceCount();
    int mmpCubeForceSurchargeFormCount();
    int mmpCubeForceSpellsInOutBlocked();
    int mmpCubeForceMaterialCount();
    int mmpCubeFrostSideInches();
    int mmpCubeFrostTempF();
    int mmpCubeFrostColdAttackCount();
    int mmpCubeFrostCollapseHp();
    int mmpCubeFrostTurnRounds();
    int mmpCubeFrostRenewHours();
    int mmpCubeFrostDestroyHp();
    int mmpCubeFrostColdPer10BelowF();
    int mmpCubeFrostAt40BelowHp();
    int mmpCubicGateSideCount();
    int mmpCubicGatePrimeSides();
    int mmpCubicGateChosenSides();
    int mmpCubicGateNexusChancePct();
    int mmpCubicGateDrawRadiusFeet();
    int mmpCubicGateMaxLinks();
    int mmpDaernSquareFeet();
    int mmpDaernHeightFeet();
    int mmpDaernGroundDepthFeet();
    int mmpDaernCollapseHp();
    int mmpDaernWishRepairHp();
    int mmpDaernSpringRounds();
    int mmpDaernGrowthDamageMin();
    int mmpDaernGrowthDamageMax();
    int mmpDaernDoorOwnerOnly();
    int mmpDaernNormalWeaponsAffect();
    int mmpDaernDamageCumulative();
    int mmpDecanterModeCount();
    int mmpDecanterStreamGallonsPerRound();
    int mmpDecanterFountainLengthFeet();
    int mmpDecanterFountainGallonsPerRound();
    int mmpDecanterGeyserLengthFeet();
    int mmpDecanterGeyserGallonsPerRound();
    int mmpDecanterWaterTypeCount();
    int mmpDecanterGeyserKnockover();
    int mmpDecanterStopsOnCommand();
    int mmpCubeForceCostPerTurn(int i);
    int mmpCubeForceMoveInches(int i);
    int mmpCubeForceSurchargeAt(int i);
};
