// ====================================================================
// Adnd1 - rules/miscprose16.h
// R272: the III.E misc magic explanation prose part 16
// (DMG p.148-149) - Iron Flask through Keoghtom
// ointment, part2 lines 766-802 (global = 11065 +
// part2 line). The slice completes the kMisc3 rows
// 27-32, the 33-row III.E.3 table. ONE page header
// inside the slice (792, the TREASURE page) falls
// inside the javelin of lightning paragraph between
// 1-6 hit and points of damage - ONE seam restored
// this round; the page attribution rides the
// 1eonline.info compilation TOC (the jewels,
// magical at p.149). The flask contents table: the
// upload drops the pipe in three rows (82-83
// mezzodaemon, 94-97 water elemental, 98-99 wind
// walker) - the 19-row d100 table pinned with the
// printed 00 row as the d100 100 (the engine kMisc3
// 93-00 precedent). 43 accessors: 41 scalars + 2
// walkers (the flask contents die table), no name
// collisions with miscprose1.h through
// miscprose15.h. Pure data + helpers, header-only
// (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpFlaskRangeInches() {
    // the command range is 6 inches
    return 6;
}

inline int mmpFlaskMaxCreatures() {
    // only 1 creature at a time can be held
    return 1;
}

inline int mmpFlaskServiceTurns() {
    // forced service lasts 1 turn
    return 1;
}

inline int mmpFlaskServiceHours() {
    // a minor service up to 1 hour of time
    return 1;
}

inline int mmpFlaskRepeatSaveBonus() {
    // a second forcing attempt saves at +2
    return 2;
}

inline int mmpFlaskContentsRowCount() {
    // 19 bands, empty through xorn
    return 19;
}

inline int mmpFlaskContentsLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    static const int t[19] = {
        1, 51, 55, 57, 58, 60, 61, 66, 70, 73,
        77, 82, 84, 86, 87, 90, 94, 98, 100,
    };
    return t[i];
}

inline int mmpFlaskContentsHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    static const int t[19] = {
        50, 54, 56, 57, 59, 60, 65, 69, 72, 76,
        81, 83, 85, 86, 89, 93, 97, 99, 100,
    };
    return t[i];
}

inline int mmpJavelinLightningPlus() {
    // equal to a +2 magic weapon, no bonuses
    return 2;
}

inline int mmpJavelinLightningRangeInches() {
    // the range is 9 inches
    return 9;
}

inline int mmpJavelinLightningStrokeWidthHalfInches() {
    // the stroke is one half inch wide
    return 1;
}

inline int mmpJavelinLightningStrokeLengthInches() {
    // the stroke is 3 inches long
    return 3;
}

inline int mmpJavelinLightningDamageMin() {
    // the struck target takes 1-6 hit points
    return 1;
}

inline int mmpJavelinLightningDamageMax() {
    // the upper edge of the 1-6 damage
    return 6;
}

inline int mmpJavelinLightningElectricalDamage() {
    // plus 20 hit points of electrical damage
    return 20;
}

inline int mmpJavelinLightningBackstrokeMin() {
    // the back stroke deals 10 or 20
    return 10;
}

inline int mmpJavelinLightningBackstrokeMax() {
    // the upper edge of the back stroke
    return 20;
}

inline int mmpJavelinLightningBackstrokeInches() {
    // drawn 3 inches back toward the hurler
    return 3;
}

inline int mmpJavelinLightningFoundMin() {
    // from 2-5 will be found
    return 2;
}

inline int mmpJavelinLightningFoundMax() {
    // the upper edge of the 2-5 find
    return 5;
}

inline int mmpJavelinPiercingRangeInches() {
    // range 6 inches, all distances short
    return 6;
}

inline int mmpJavelinPiercingToHitBonus() {
    // +6 to hit
    return 6;
}

inline int mmpJavelinPiercingDamageMin() {
    // the strike inflicts 7-12 hit points
    return 7;
}

inline int mmpJavelinPiercingDamageMax() {
    // the upper edge of the 7-12 damage
    return 12;
}

inline int mmpJavelinPiercingFoundMin() {
    // from 2-8 will be found
    return 2;
}

inline int mmpJavelinPiercingFoundMax() {
    // the upper edge of the 2-8 find
    return 8;
}

inline int mmpJavelinPiercingThrows() {
    // the magic is good for only 1 throw
    return 1;
}

inline int mmpJewelAttacksWanderingPct() {
    // 100 percent more wandering monsters
    return 100;
}

inline int mmpJewelAttacksPursuitPct() {
    // 100 percent greater pursuit likelihood
    return 100;
}

inline int mmpJewelFlawlessBoostPct() {
    // the value likelihood rises 100 percent
    return 100;
}

inline int mmpJewelFlawlessBaseTenths() {
    // 1 in 10 stones rise unboosted
    return 1;
}

inline int mmpJewelFlawlessBoostedTenths() {
    // 2 in 10 stones rise boosted
    return 2;
}

inline int mmpJewelFlawlessFacetMin() {
    // the jewel has 10-100 facets
    return 10;
}

inline int mmpJewelFlawlessFacetMax() {
    // the upper edge of the 10-100 facets
    return 100;
}

inline int mmpJewelFlawlessTriggerD10() {
    // a roll of 2 on d10 raises a stone
    return 2;
}

inline int mmpJewelFlawlessFacetsLostPerBoost() {
    // 1 facet disappears per raised stone
    return 1;
}

inline int mmpOintmentJarDiameterInches() {
    // the jar is three inches in diameter
    return 3;
}

inline int mmpOintmentJarDepthInches() {
    // the jar is one inch deep
    return 1;
}

inline int mmpOintmentApplications() {
    // the jar contains 5 applications
    return 5;
}

inline int mmpOintmentHealMin() {
    // rubbed on it heals 9-12 points
    return 9;
}

inline int mmpOintmentHealMax() {
    // the upper edge of the 9-12 healing
    return 12;
}

inline int mmpOintmentFoundMin() {
    // 1-3 jars will commonly be found
    return 1;
}

inline int mmpOintmentFoundMax() {
    // the upper edge of the 1-3 jars
    return 3;
}

}  // namespace rules