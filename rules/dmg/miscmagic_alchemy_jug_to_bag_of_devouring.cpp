// R-refactor: split from miscmagic_alchemy_jug_to_bag_of_devouring.h - definitions
#include "rules/dmg/miscmagic_alchemy_jug_to_bag_of_devouring.h"

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpIntroMaxDuplicates() {
    // improbable to have more than 2 or 3
    return 3;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpIntroBooksExactWishCount() {
    // a second wish determines exact contents
    return 2;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAlchemyJugRowCount() {
    // 11 pourable liquids
    return 11;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAlchemyJugKindsPerDay() {
    // only 1 kind of liquid on any given day
    return 1;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAlchemyJugPouringsPerDay() {
    // 7 pourings maximum
    return 7;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAlchemyJugGallonsPerRound() {
    // pours forth 2 gallons per round
    return 2;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAlchemyJugRoundsPerLargePouring() {
    // 8 rounds for 1 pouring of salt water
    return 8;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAlchemyJugRowQty(int i) {
    // salt water 16 gallons, fresh 8, beer 4,
    // vinegar 2, wine 1, ammonia 1 quart, oil
    // 1 pint, aqua regia 2 gills, alcohol 1
    // gill, chlorine 8 drams, cyanide 4 drams
    static const int t[11] = {
        16, 8, 4, 2, 1, 1, 1, 2, 1, 8, 4,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAlchemyJugRowUnit(int i) {
    // 0 gallons, 1 quart, 2 pint, 3 gill,
    // 4 drams
    static const int t[11] = {
        0, 0, 0, 0, 0, 1, 2, 3, 3, 4, 4,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAmuletLocationMultiplier() {
    // DOUBLES the likelihood and range (a cursed
    // lure disguised as a protection amulet)
    return 2;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAmuletLifeProtectionDays() {
    // the psyche is protected for 7 full days
    return 7;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAmuletPlanesRowCount() {
    // the plane table has 17 rows
    return 17;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAmuletPlanesLowDieFaces() {
    // roll d6: 1-3 do not add 12
    return 6;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAmuletPlanesHighDieFaces() {
    // add 12 to d12 for 1-24 random results
    return 12;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAmuletPlanesAddOnHigh() {
    // the added 12 of the 4-6 results
    return 12;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAmuletPlanesResultMax() {
    // 1-24 random results
    return 24;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAmuletPlanesAltRowCount() {
    // the alternate results: 3 rows
    return 3;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAmuletPlanesRowLo(int i) {
    // 1-2 Seven Heavens through 21-24 Prime
    // Material Plane
    static const int t[17] = {
        1, 3, 4, 5, 6, 8, 9, 10, 11, 13, 14,
        15, 16, 18, 19, 20, 21,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAmuletPlanesRowHi(int i) {
    static const int t[17] = {
        2, 3, 4, 5, 7, 8, 9, 10, 12, 13, 14,
        15, 17, 18, 19, 20, 24,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAmuletPlanesAltLo(int i) {
    // alternates: 22 Ethereal, 23 Astral,
    // 24 alternate Earth
    static const int t[3] = {
        22, 23, 24,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpAmuletProofNoAuraFlag() {
    // no aura is discernible on the wearer
    return 1;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishLeverCount() {
    // 10 levers inside
    return 10;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishForwardInches() {
    // moves forward at 3 inches
    return 3;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishBackwardInches() {
    // backwards at 6 inches
    return 6;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishPincerReachFeet() {
    // pincers extend forward 4 feet
    return 4;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishPincerDamageLo() {
    // snap for 2-12 hit points each
    return 2;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishPincerDamageHi() {
    return 12;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishPincerHitPct() {
    // 25% chance, no armor reduction
    return 25;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishMaxDepthFeet() {
    // operates in waters up to 900 feet
    return 900;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishOccupants() {
    // holds 2 human-sized persons
    return 2;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishAirHoursLo() {
    // air for 2-5 hours at maximum capacity
    return 2;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishAirHoursHi() {
    return 5;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishArmorClass() {
    // the apparatus is AC 0
    return 0;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishLeakHp() {
    // 100 hit points to cause a leak
    return 100;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpKwalishStaveHp() {
    // 200 to stave in a side
    return 200;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpArrowDirectionUsesPerDay() {
    // tossed into the air once per day
    return 1;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpArrowDirectionRepetitions() {
    // the process can be repeated 7 times
    return 7;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpArrowDirectionTurns() {
    // during the next 7 turns
    return 7;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpArrowDirectionRequestKinds() {
    // stairway, sloping passage, dungeon exit
    // or entrance, cave, cavern
    return 5;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanExplodeDamageLo() {
    // dumped beans explode for 5-20 hit points
    return 5;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanExplodeDamageHi() {
    return 20;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanExplodeRadiusFeet() {
    // all creatures within 10 feet save
    return 10;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanOptimumLo() {
    // 3-12 beans are optimum
    return 3;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanOptimumHi() {
    return 12;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanBeneficialMax() {
    // only 1 or 2 will be beneficial
    return 2;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanEffectRowCount() {
    // the example bean table has 7 rows
    return 7;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanBerryCountLo() {
    // the raspberry bush: 5-20 berries
    return 5;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanBerryCountHi() {
    return 20;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanBerryGemLo() {
    // berries are gems of 100 or 500 g.p.
    return 100;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanBerryGemHi() {
    return 500;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanSmokeRadiusFeet() {
    // smoke covers 50 feet radius
    return 50;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanSmokeTurns() {
    // for 5 turns
    return 5;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanBlindRoundsLo() {
    // blinded for 1-6 rounds even outside
    return 1;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanBlindRoundsHi() {
    return 6;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanGasRadiusFeet() {
    // poison gas cloud of 20 feet radius
    return 20;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpBeanGasTurns() {
    // persists for 1 turn
    return 1;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpDevouringIgnorePct() {
    // 90% likely to ignore initial intrusions
    return 90;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpDevouringClosePct() {
    // 60% likely to close on living human flesh
    return 60;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpDevouringBaseDrawPct() {
    // base 75% chance to draw the victim in
    return 75;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpDevouringDrawModPerPlus() {
    // each +1 damage bonus is -5% on the base
    return 5;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpDevouringExampleStr18Pct() {
    // 18 strength (+2 damage): only 65%
    return 65;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpDevouringExampleStr5Pct() {
    // 5 strength (-1 damage): 80%
    return 80;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpDevouringCapacityCubicFeet() {
    // holds up to 30 cubic feet of matter
    return 30;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpDevouringSwallowPctPerTurn() {
    // 5% cumulative chance per turn - THE SEAM
    // FACT, completed from part2 line 3
    return 5;
}

int Miscmagic_alchemy_jug_to_bag_of_devouring::mmpDevouringConsumeSegments() {
    // creatures drawn within are consumed in
    // 7 segments
    return 7;
}
