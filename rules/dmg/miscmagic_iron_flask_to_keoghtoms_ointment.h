// ====================================================================
// Adnd1 - rules/dmg/miscmagic_iron_flask_to_keoghtoms_ointment.h
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

// R-refactor: namespace rules -> class Miscmagic_iron_flask_to_keoghtoms_ointment (instance methods)
class Miscmagic_iron_flask_to_keoghtoms_ointment {
public:
    int mmpFlaskRangeInches();
    int mmpFlaskMaxCreatures();
    int mmpFlaskServiceTurns();
    int mmpFlaskServiceHours();
    int mmpFlaskRepeatSaveBonus();
    int mmpFlaskContentsRowCount();
    int mmpFlaskContentsLo(int i);
    int mmpFlaskContentsHi(int i);
    int mmpJavelinLightningPlus();
    int mmpJavelinLightningRangeInches();
    int mmpJavelinLightningStrokeWidthHalfInches();
    int mmpJavelinLightningStrokeLengthInches();
    int mmpJavelinLightningDamageMin();
    int mmpJavelinLightningDamageMax();
    int mmpJavelinLightningElectricalDamage();
    int mmpJavelinLightningBackstrokeMin();
    int mmpJavelinLightningBackstrokeMax();
    int mmpJavelinLightningBackstrokeInches();
    int mmpJavelinLightningFoundMin();
    int mmpJavelinLightningFoundMax();
    int mmpJavelinPiercingRangeInches();
    int mmpJavelinPiercingToHitBonus();
    int mmpJavelinPiercingDamageMin();
    int mmpJavelinPiercingDamageMax();
    int mmpJavelinPiercingFoundMin();
    int mmpJavelinPiercingFoundMax();
    int mmpJavelinPiercingThrows();
    int mmpJewelAttacksWanderingPct();
    int mmpJewelAttacksPursuitPct();
    int mmpJewelFlawlessBoostPct();
    int mmpJewelFlawlessBaseTenths();
    int mmpJewelFlawlessBoostedTenths();
    int mmpJewelFlawlessFacetMin();
    int mmpJewelFlawlessFacetMax();
    int mmpJewelFlawlessTriggerD10();
    int mmpJewelFlawlessFacetsLostPerBoost();
    int mmpOintmentJarDiameterInches();
    int mmpOintmentJarDepthInches();
    int mmpOintmentApplications();
    int mmpOintmentHealMin();
    int mmpOintmentHealMax();
    int mmpOintmentFoundMin();
    int mmpOintmentFoundMax();
};
