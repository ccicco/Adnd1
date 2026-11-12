// ====================================================================
// Adnd1 - rules/dmg/miscmagic_alchemy_jug_to_bag_of_devouring.h
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

// R-refactor: namespace rules -> class Miscmagic_alchemy_jug_to_bag_of_devouring (instance methods)
class Miscmagic_alchemy_jug_to_bag_of_devouring {
public:
    int mmpIntroMaxDuplicates();
    int mmpIntroBooksExactWishCount();
    int mmpAlchemyJugRowCount();
    int mmpAlchemyJugKindsPerDay();
    int mmpAlchemyJugPouringsPerDay();
    int mmpAlchemyJugGallonsPerRound();
    int mmpAlchemyJugRoundsPerLargePouring();
    int mmpAlchemyJugRowQty(int i);
    int mmpAlchemyJugRowUnit(int i);
    int mmpAmuletLocationMultiplier();
    int mmpAmuletLifeProtectionDays();
    int mmpAmuletPlanesRowCount();
    int mmpAmuletPlanesLowDieFaces();
    int mmpAmuletPlanesHighDieFaces();
    int mmpAmuletPlanesAddOnHigh();
    int mmpAmuletPlanesResultMax();
    int mmpAmuletPlanesAltRowCount();
    int mmpAmuletPlanesRowLo(int i);
    int mmpAmuletPlanesRowHi(int i);
    int mmpAmuletPlanesAltLo(int i);
    int mmpAmuletProofNoAuraFlag();
    int mmpKwalishLeverCount();
    int mmpKwalishForwardInches();
    int mmpKwalishBackwardInches();
    int mmpKwalishPincerReachFeet();
    int mmpKwalishPincerDamageLo();
    int mmpKwalishPincerDamageHi();
    int mmpKwalishPincerHitPct();
    int mmpKwalishMaxDepthFeet();
    int mmpKwalishOccupants();
    int mmpKwalishAirHoursLo();
    int mmpKwalishAirHoursHi();
    int mmpKwalishArmorClass();
    int mmpKwalishLeakHp();
    int mmpKwalishStaveHp();
    int mmpArrowDirectionUsesPerDay();
    int mmpArrowDirectionRepetitions();
    int mmpArrowDirectionTurns();
    int mmpArrowDirectionRequestKinds();
    int mmpBeanExplodeDamageLo();
    int mmpBeanExplodeDamageHi();
    int mmpBeanExplodeRadiusFeet();
    int mmpBeanOptimumLo();
    int mmpBeanOptimumHi();
    int mmpBeanBeneficialMax();
    int mmpBeanEffectRowCount();
    int mmpBeanBerryCountLo();
    int mmpBeanBerryCountHi();
    int mmpBeanBerryGemLo();
    int mmpBeanBerryGemHi();
    int mmpBeanSmokeRadiusFeet();
    int mmpBeanSmokeTurns();
    int mmpBeanBlindRoundsLo();
    int mmpBeanBlindRoundsHi();
    int mmpBeanGasRadiusFeet();
    int mmpBeanGasTurns();
    int mmpDevouringIgnorePct();
    int mmpDevouringClosePct();
    int mmpDevouringBaseDrawPct();
    int mmpDevouringDrawModPerPlus();
    int mmpDevouringExampleStr18Pct();
    int mmpDevouringExampleStr5Pct();
    int mmpDevouringCapacityCubicFeet();
    int mmpDevouringSwallowPctPerTurn();
    int mmpDevouringConsumeSegments();
};
