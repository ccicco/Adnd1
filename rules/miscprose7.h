// ====================================================================
// Adnd1 - rules/miscprose7.h
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
// ====================================================================

#pragma once

namespace rules {

inline int mmpCubeForceWallInches() {
    // wall of force, 1 inch per side
    return 1;
}

inline int mmpCubeForceCharges() {
    // the cube has 36 charges
    return 36;
}

inline int mmpCubeForceRestoreDays() {
    // energy restored each day
    return 1;
}

inline int mmpCubeForceFaceCount() {
    // six faces, one per screen strength
    return 6;
}

inline int mmpCubeForceSurchargeFormCount() {
    // the attack-form surcharge table entries
    return 14;
}

inline int mmpCubeForceSpellsInOutBlocked() {
    // no casting into or out of the cube
    return 1;
}

inline int mmpCubeForceMaterialCount() {
    // hard mineral, ivory, bone
    return 3;
}

inline int mmpCubeFrostSideInches() {
    // encloses 1 inch per side
    return 1;
}

inline int mmpCubeFrostTempF() {
    // always 65 degrees F inside
    return 65;
}

inline int mmpCubeFrostColdAttackCount() {
    // cone of cold, ice storm, dragon breath
    return 3;
}

inline int mmpCubeFrostCollapseHp() {
    // more than this per turn: collapse
    return 50;
}

inline int mmpCubeFrostTurnRounds() {
    // a turn is 10 rounds
    return 10;
}

inline int mmpCubeFrostRenewHours() {
    // after collapse: no renewal for
    return 1;
}

inline int mmpCubeFrostDestroyHp() {
    // over this in 1 turn: destroyed
    return 100;
}

inline int mmpCubeFrostColdPer10BelowF() {
    // 2 hp of cold per minus 10 degrees
    return 2;
}

inline int mmpCubeFrostAt40BelowHp() {
    // at minus 40 F: withstands only
    return 42;
}

inline int mmpCubicGateSideCount() {
    // the 6 sides, each keyed to a plane
    return 6;
}

inline int mmpCubicGatePrimeSides() {
    // one side is always Prime Material
    return 1;
}

inline int mmpCubicGateChosenSides() {
    // the other 5 are chosen
    return 5;
}

inline int mmpCubicGateNexusChancePct() {
    // per turn, something comes through
    return 10;
}

inline int mmpCubicGateDrawRadiusFeet() {
    // second press draws all within
    return 5;
}

inline int mmpCubicGateMaxLinks() {
    // no more than 1 nexial link at once
    return 1;
}

inline int mmpDaernSquareFeet() {
    // the tower footprint, square
    return 20;
}

inline int mmpDaernHeightFeet() {
    // the tower height
    return 30;
}

inline int mmpDaernGroundDepthFeet() {
    // metal extends into the ground
    return 10;
}

inline int mmpDaernCollapseHp() {
    // damage before the tower collapses
    return 200;
}

inline int mmpDaernWishRepairHp() {
    // a wish restores this much damage
    return 10;
}

inline int mmpDaernSpringRounds() {
    // springs up in but 1 round
    return 1;
}

inline int mmpDaernGrowthDamageMin() {
    // caught by the growth: minimum
    return 10;
}

inline int mmpDaernGrowthDamageMax() {
    // caught by the growth: maximum
    return 100;
}

inline int mmpDaernDoorOwnerOnly() {
    // opens only to the owner command
    return 1;
}

inline int mmpDaernNormalWeaponsAffect() {
    // normal weapons do NOT affect the walls
    return 0;
}

inline int mmpDaernDamageCumulative() {
    // sustained damage is cumulative
    return 1;
}

inline int mmpDecanterModeCount() {
    // stream, fountain, geyser
    return 3;
}

inline int mmpDecanterStreamGallonsPerRound() {
    // stream pours per round
    return 1;
}

inline int mmpDecanterFountainLengthFeet() {
    // the fountain stream length
    return 5;
}

inline int mmpDecanterFountainGallonsPerRound() {
    // fountain pours per round
    return 5;
}

inline int mmpDecanterGeyserLengthFeet() {
    // the geyser stream length
    return 20;
}

inline int mmpDecanterGeyserGallonsPerRound() {
    // geyser pours per round
    return 30;
}

inline int mmpDecanterWaterTypeCount() {
    // fresh or salt, as ordered
    return 2;
}

inline int mmpDecanterGeyserKnockover() {
    // geyser back pressure knocks over
    return 1;
}

inline int mmpDecanterStopsOnCommand() {
    // the command word ceases the flow
    return 1;
}

inline int mmpCubeForceCostPerTurn(int i) {
    // the face charge cost; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 2, 3, 4, 6, 0,
    };
    return t[i];
}

inline int mmpCubeForceMoveInches(int i) {
    // the face movement rate; 0 is normal; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 8, 6, 4, 3, 0,
    };
    return t[i];
}

inline int mmpCubeForceSurchargeAt(int i) {
    // the attack-form surcharges, row-major
    // print order; i clamps
    if (i < 0) i = 0;
    if (i > 13) i = 13;
    static const int t[14] = {
        1, 3, 2, 4, 6, 8, 3, 3, 6, 5, 3, 7, 3, 2,
    };
    return t[i];
}

} // namespace rules