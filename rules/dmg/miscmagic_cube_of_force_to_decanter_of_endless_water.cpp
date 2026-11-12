// R-refactor: split from miscmagic_cube_of_force_to_decanter_of_endless_water.h - definitions
#include "rules/dmg/miscmagic_cube_of_force_to_decanter_of_endless_water.h"

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeForceWallInches() {
    // wall of force, 1 inch per side
    return 1;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeForceCharges() {
    // the cube has 36 charges
    return 36;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeForceRestoreDays() {
    // energy restored each day
    return 1;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeForceFaceCount() {
    // six faces, one per screen strength
    return 6;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeForceSurchargeFormCount() {
    // the attack-form surcharge table entries
    return 14;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeForceSpellsInOutBlocked() {
    // no casting into or out of the cube
    return 1;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeForceMaterialCount() {
    // hard mineral, ivory, bone
    return 3;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeFrostSideInches() {
    // encloses 1 inch per side
    return 1;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeFrostTempF() {
    // always 65 degrees F inside
    return 65;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeFrostColdAttackCount() {
    // cone of cold, ice storm, dragon breath
    return 3;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeFrostCollapseHp() {
    // more than this per turn: collapse
    return 50;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeFrostTurnRounds() {
    // a turn is 10 rounds
    return 10;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeFrostRenewHours() {
    // after collapse: no renewal for
    return 1;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeFrostDestroyHp() {
    // over this in 1 turn: destroyed
    return 100;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeFrostColdPer10BelowF() {
    // 2 hp of cold per minus 10 degrees
    return 2;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeFrostAt40BelowHp() {
    // at minus 40 F: withstands only
    return 42;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubicGateSideCount() {
    // the 6 sides, each keyed to a plane
    return 6;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubicGatePrimeSides() {
    // one side is always Prime Material
    return 1;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubicGateChosenSides() {
    // the other 5 are chosen
    return 5;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubicGateNexusChancePct() {
    // per turn, something comes through
    return 10;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubicGateDrawRadiusFeet() {
    // second press draws all within
    return 5;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubicGateMaxLinks() {
    // no more than 1 nexial link at once
    return 1;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDaernSquareFeet() {
    // the tower footprint, square
    return 20;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDaernHeightFeet() {
    // the tower height
    return 30;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDaernGroundDepthFeet() {
    // metal extends into the ground
    return 10;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDaernCollapseHp() {
    // damage before the tower collapses
    return 200;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDaernWishRepairHp() {
    // a wish restores this much damage
    return 10;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDaernSpringRounds() {
    // springs up in but 1 round
    return 1;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDaernGrowthDamageMin() {
    // caught by the growth: minimum
    return 10;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDaernGrowthDamageMax() {
    // caught by the growth: maximum
    return 100;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDaernDoorOwnerOnly() {
    // opens only to the owner command
    return 1;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDaernNormalWeaponsAffect() {
    // normal weapons do NOT affect the walls
    return 0;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDaernDamageCumulative() {
    // sustained damage is cumulative
    return 1;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDecanterModeCount() {
    // stream, fountain, geyser
    return 3;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDecanterStreamGallonsPerRound() {
    // stream pours per round
    return 1;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDecanterFountainLengthFeet() {
    // the fountain stream length
    return 5;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDecanterFountainGallonsPerRound() {
    // fountain pours per round
    return 5;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDecanterGeyserLengthFeet() {
    // the geyser stream length
    return 20;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDecanterGeyserGallonsPerRound() {
    // geyser pours per round
    return 30;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDecanterWaterTypeCount() {
    // fresh or salt, as ordered
    return 2;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDecanterGeyserKnockover() {
    // geyser back pressure knocks over
    return 1;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpDecanterStopsOnCommand() {
    // the command word ceases the flow
    return 1;
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeForceCostPerTurn(int i) {
    // the face charge cost; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 2, 3, 4, 6, 0,
    };
    return t[i];
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeForceMoveInches(int i) {
    // the face movement rate; 0 is normal; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 8, 6, 4, 3, 0,
    };
    return t[i];
}

int Miscmagic_cube_of_force_to_decanter_of_endless_water::mmpCubeForceSurchargeAt(int i) {
    // the attack-form surcharges, row-major
    // print order; i clamps
    if (i < 0) i = 0;
    if (i > 13) i = 13;
    static const int t[14] = {
        1, 3, 2, 4, 6, 8, 3, 3, 6, 5, 3, 7, 3, 2,
    };
    return t[i];
}
