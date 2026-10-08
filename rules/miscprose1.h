// ====================================================================
// Adnd1 - rules/miscprose1.h
// R257: the III.E misc magic explanation prose part 1
// pins - the FIRST TWO-PART-FILE round. The III.E
// explanation prose spans the upload seam: part1
// ends mid-sentence (Bag of Devouring: it has a
// 5%), part2 line 3 completes it. The seam is
// pinned exactly: part1 has 11067 lines, last
// content line 11065; global line = part1 line or
// 11065 + part2 line. Slice: part1 10949-11065
// plus the stitched completion - the section intro
// plus Alchemy Jug through Bag of Devouring:
//   - Intro: a catch-all category, not more than
//     2 or 3 duplicates; alphabetical; class
//     letters; books appear normal - a second
//     wish for exact contents.
//   - Alchemy Jug: 11 liquids (16 gallons salt
//     water down to 4 drams cyanide); 1 kind and
//     7 pourings per day; 2 gallons per round; 8
//     rounds for one salt water pouring.
//   - Amulet of Inescapable Location: DOUBLES
//     likelihood and range of detection.
//   - Amulet of Life Protection: psyche safe
//     7 full days; psionic blast and crush immune.
//   - Amulet of the Planes: d6 (1-3 no add, 4-6
//     add 12) on d12 = 1-24; the 17-row plane
//     table; alternates 22/23/24.
//   - Amulet of Proof: no aura discernible.
//   - Apparatus of Kwalish: 10 levers; 3 forward,
//     6 backward; pincers 4 feet, 2-12 damage,
//     25% hit; 900 feet; 2 occupants; 2-5 hours
//     air; AC 0; 100 leak, 200 stave.
//   - Arrow of Direction: once per day, 7 times
//     in 7 turns, 5 request kinds.
//   - Bag of Beans: 5-20 explosion in 10 feet;
//     3-12 optimum, 1-2 beneficial; the 7-row
//     bean table (5-20 berries of 100/500 gems;
//     50 feet 5 turn smoke, blind 1-6; 20 feet
//     1 turn gas).
//   - Bag of Devouring: 90% ignore, 60% close;
//     base 75% less 5% per +1 (18 str = 65%, 5
//     str = 80%); 30 cubic feet; acts as a bag
//     of holding; 5% cumulative per turn swallow
//     - THE SEAM FACT; consumed in 7 segments.
// The nine items are the engine kMisc1 rows 0-6,
// 8 and 10 (the R225 m1 band pins) - cross-checked
// in the audit. Pure data + helpers, header-only
// (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpIntroMaxDuplicates() {
    // improbable to have more than 2 or 3
    return 3;
}

inline int mmpIntroBooksExactWishCount() {
    // a second wish determines exact contents
    return 2;
}

inline int mmpAlchemyJugRowCount() {
    // 11 pourable liquids
    return 11;
}

inline int mmpAlchemyJugKindsPerDay() {
    // only 1 kind of liquid on any given day
    return 1;
}

inline int mmpAlchemyJugPouringsPerDay() {
    // 7 pourings maximum
    return 7;
}

inline int mmpAlchemyJugGallonsPerRound() {
    // pours forth 2 gallons per round
    return 2;
}

inline int mmpAlchemyJugRoundsPerLargePouring() {
    // 8 rounds for 1 pouring of salt water
    return 8;
}

inline int mmpAlchemyJugRowQty(int i) {
    // salt water 16 gallons, fresh 8, beer 4,
    // vinegar 2, wine 1, ammonia 1 quart, oil
    // 1 pint, aqua regia 2 gills, alcohol 1
    // gill, chlorine 8 drams, cyanide 4 drams
    static const int t[11] = {
        16, 8, 4, 2, 1, 1, 1, 2, 1, 8, 4,
    };
    return t[i];
}

inline int mmpAlchemyJugRowUnit(int i) {
    // 0 gallons, 1 quart, 2 pint, 3 gill,
    // 4 drams
    static const int t[11] = {
        0, 0, 0, 0, 0, 1, 2, 3, 3, 4, 4,
    };
    return t[i];
}

inline int mmpAmuletLocationMultiplier() {
    // DOUBLES the likelihood and range (a cursed
    // lure disguised as a protection amulet)
    return 2;
}

inline int mmpAmuletLifeProtectionDays() {
    // the psyche is protected for 7 full days
    return 7;
}

inline int mmpAmuletPlanesRowCount() {
    // the plane table has 17 rows
    return 17;
}

inline int mmpAmuletPlanesLowDieFaces() {
    // roll d6: 1-3 do not add 12
    return 6;
}

inline int mmpAmuletPlanesHighDieFaces() {
    // add 12 to d12 for 1-24 random results
    return 12;
}

inline int mmpAmuletPlanesAddOnHigh() {
    // the added 12 of the 4-6 results
    return 12;
}

inline int mmpAmuletPlanesResultMax() {
    // 1-24 random results
    return 24;
}

inline int mmpAmuletPlanesAltRowCount() {
    // the alternate results: 3 rows
    return 3;
}

inline int mmpAmuletPlanesRowLo(int i) {
    // 1-2 Seven Heavens through 21-24 Prime
    // Material Plane
    static const int t[17] = {
        1, 3, 4, 5, 6, 8, 9, 10, 11, 13, 14,
        15, 16, 18, 19, 20, 21,
    };
    return t[i];
}

inline int mmpAmuletPlanesRowHi(int i) {
    static const int t[17] = {
        2, 3, 4, 5, 7, 8, 9, 10, 12, 13, 14,
        15, 17, 18, 19, 20, 24,
    };
    return t[i];
}

inline int mmpAmuletPlanesAltLo(int i) {
    // alternates: 22 Ethereal, 23 Astral,
    // 24 alternate Earth
    static const int t[3] = {
        22, 23, 24,
    };
    return t[i];
}

inline int mmpAmuletProofNoAuraFlag() {
    // no aura is discernible on the wearer
    return 1;
}

inline int mmpKwalishLeverCount() {
    // 10 levers inside
    return 10;
}

inline int mmpKwalishForwardInches() {
    // moves forward at 3 inches
    return 3;
}

inline int mmpKwalishBackwardInches() {
    // backwards at 6 inches
    return 6;
}

inline int mmpKwalishPincerReachFeet() {
    // pincers extend forward 4 feet
    return 4;
}

inline int mmpKwalishPincerDamageLo() {
    // snap for 2-12 hit points each
    return 2;
}

inline int mmpKwalishPincerDamageHi() {
    return 12;
}

inline int mmpKwalishPincerHitPct() {
    // 25% chance, no armor reduction
    return 25;
}

inline int mmpKwalishMaxDepthFeet() {
    // operates in waters up to 900 feet
    return 900;
}

inline int mmpKwalishOccupants() {
    // holds 2 human-sized persons
    return 2;
}

inline int mmpKwalishAirHoursLo() {
    // air for 2-5 hours at maximum capacity
    return 2;
}

inline int mmpKwalishAirHoursHi() {
    return 5;
}

inline int mmpKwalishArmorClass() {
    // the apparatus is AC 0
    return 0;
}

inline int mmpKwalishLeakHp() {
    // 100 hit points to cause a leak
    return 100;
}

inline int mmpKwalishStaveHp() {
    // 200 to stave in a side
    return 200;
}

inline int mmpArrowDirectionUsesPerDay() {
    // tossed into the air once per day
    return 1;
}

inline int mmpArrowDirectionRepetitions() {
    // the process can be repeated 7 times
    return 7;
}

inline int mmpArrowDirectionTurns() {
    // during the next 7 turns
    return 7;
}

inline int mmpArrowDirectionRequestKinds() {
    // stairway, sloping passage, dungeon exit
    // or entrance, cave, cavern
    return 5;
}

inline int mmpBeanExplodeDamageLo() {
    // dumped beans explode for 5-20 hit points
    return 5;
}

inline int mmpBeanExplodeDamageHi() {
    return 20;
}

inline int mmpBeanExplodeRadiusFeet() {
    // all creatures within 10 feet save
    return 10;
}

inline int mmpBeanOptimumLo() {
    // 3-12 beans are optimum
    return 3;
}

inline int mmpBeanOptimumHi() {
    return 12;
}

inline int mmpBeanBeneficialMax() {
    // only 1 or 2 will be beneficial
    return 2;
}

inline int mmpBeanEffectRowCount() {
    // the example bean table has 7 rows
    return 7;
}

inline int mmpBeanBerryCountLo() {
    // the raspberry bush: 5-20 berries
    return 5;
}

inline int mmpBeanBerryCountHi() {
    return 20;
}

inline int mmpBeanBerryGemLo() {
    // berries are gems of 100 or 500 g.p.
    return 100;
}

inline int mmpBeanBerryGemHi() {
    return 500;
}

inline int mmpBeanSmokeRadiusFeet() {
    // smoke covers 50 feet radius
    return 50;
}

inline int mmpBeanSmokeTurns() {
    // for 5 turns
    return 5;
}

inline int mmpBeanBlindRoundsLo() {
    // blinded for 1-6 rounds even outside
    return 1;
}

inline int mmpBeanBlindRoundsHi() {
    return 6;
}

inline int mmpBeanGasRadiusFeet() {
    // poison gas cloud of 20 feet radius
    return 20;
}

inline int mmpBeanGasTurns() {
    // persists for 1 turn
    return 1;
}

inline int mmpDevouringIgnorePct() {
    // 90% likely to ignore initial intrusions
    return 90;
}

inline int mmpDevouringClosePct() {
    // 60% likely to close on living human flesh
    return 60;
}

inline int mmpDevouringBaseDrawPct() {
    // base 75% chance to draw the victim in
    return 75;
}

inline int mmpDevouringDrawModPerPlus() {
    // each +1 damage bonus is -5% on the base
    return 5;
}

inline int mmpDevouringExampleStr18Pct() {
    // 18 strength (+2 damage): only 65%
    return 65;
}

inline int mmpDevouringExampleStr5Pct() {
    // 5 strength (-1 damage): 80%
    return 80;
}

inline int mmpDevouringCapacityCubicFeet() {
    // holds up to 30 cubic feet of matter
    return 30;
}

inline int mmpDevouringSwallowPctPerTurn() {
    // 5% cumulative chance per turn - THE SEAM
    // FACT, completed from part2 line 3
    return 5;
}

inline int mmpDevouringConsumeSegments() {
    // creatures drawn within are consumed in
    // 7 segments
    return 7;
}

}  // namespace rules
