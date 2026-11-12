// R-refactor: split from miscmagic_iron_flask_to_keoghtoms_ointment.h - definitions
#include "rules/dmg/miscmagic_iron_flask_to_keoghtoms_ointment.h"

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpFlaskRangeInches() {
    // the command range is 6 inches
    return 6;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpFlaskMaxCreatures() {
    // only 1 creature at a time can be held
    return 1;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpFlaskServiceTurns() {
    // forced service lasts 1 turn
    return 1;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpFlaskServiceHours() {
    // a minor service up to 1 hour of time
    return 1;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpFlaskRepeatSaveBonus() {
    // a second forcing attempt saves at +2
    return 2;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpFlaskContentsRowCount() {
    // 19 bands, empty through xorn
    return 19;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpFlaskContentsLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    static const int t[19] = {
        1, 51, 55, 57, 58, 60, 61, 66, 70, 73,
        77, 82, 84, 86, 87, 90, 94, 98, 100,
    };
    return t[i];
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpFlaskContentsHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    static const int t[19] = {
        50, 54, 56, 57, 59, 60, 65, 69, 72, 76,
        81, 83, 85, 86, 89, 93, 97, 99, 100,
    };
    return t[i];
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinLightningPlus() {
    // equal to a +2 magic weapon, no bonuses
    return 2;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinLightningRangeInches() {
    // the range is 9 inches
    return 9;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinLightningStrokeWidthHalfInches() {
    // the stroke is one half inch wide
    return 1;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinLightningStrokeLengthInches() {
    // the stroke is 3 inches long
    return 3;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinLightningDamageMin() {
    // the struck target takes 1-6 hit points
    return 1;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinLightningDamageMax() {
    // the upper edge of the 1-6 damage
    return 6;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinLightningElectricalDamage() {
    // plus 20 hit points of electrical damage
    return 20;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinLightningBackstrokeMin() {
    // the back stroke deals 10 or 20
    return 10;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinLightningBackstrokeMax() {
    // the upper edge of the back stroke
    return 20;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinLightningBackstrokeInches() {
    // drawn 3 inches back toward the hurler
    return 3;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinLightningFoundMin() {
    // from 2-5 will be found
    return 2;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinLightningFoundMax() {
    // the upper edge of the 2-5 find
    return 5;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinPiercingRangeInches() {
    // range 6 inches, all distances short
    return 6;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinPiercingToHitBonus() {
    // +6 to hit
    return 6;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinPiercingDamageMin() {
    // the strike inflicts 7-12 hit points
    return 7;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinPiercingDamageMax() {
    // the upper edge of the 7-12 damage
    return 12;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinPiercingFoundMin() {
    // from 2-8 will be found
    return 2;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinPiercingFoundMax() {
    // the upper edge of the 2-8 find
    return 8;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJavelinPiercingThrows() {
    // the magic is good for only 1 throw
    return 1;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJewelAttacksWanderingPct() {
    // 100 percent more wandering monsters
    return 100;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJewelAttacksPursuitPct() {
    // 100 percent greater pursuit likelihood
    return 100;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJewelFlawlessBoostPct() {
    // the value likelihood rises 100 percent
    return 100;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJewelFlawlessBaseTenths() {
    // 1 in 10 stones rise unboosted
    return 1;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJewelFlawlessBoostedTenths() {
    // 2 in 10 stones rise boosted
    return 2;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJewelFlawlessFacetMin() {
    // the jewel has 10-100 facets
    return 10;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJewelFlawlessFacetMax() {
    // the upper edge of the 10-100 facets
    return 100;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJewelFlawlessTriggerD10() {
    // a roll of 2 on d10 raises a stone
    return 2;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpJewelFlawlessFacetsLostPerBoost() {
    // 1 facet disappears per raised stone
    return 1;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpOintmentJarDiameterInches() {
    // the jar is three inches in diameter
    return 3;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpOintmentJarDepthInches() {
    // the jar is one inch deep
    return 1;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpOintmentApplications() {
    // the jar contains 5 applications
    return 5;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpOintmentHealMin() {
    // rubbed on it heals 9-12 points
    return 9;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpOintmentHealMax() {
    // the upper edge of the 9-12 healing
    return 12;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpOintmentFoundMin() {
    // 1-3 jars will commonly be found
    return 1;
}

int Miscmagic_iron_flask_to_keoghtoms_ointment::mmpOintmentFoundMax() {
    // the upper edge of the 1-3 jars
    return 3;
}
