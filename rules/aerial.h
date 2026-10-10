// ===========================================================================
// Adnd1 - rules/aerial.h
// The aerial environment (R321).
//
// The DMG AERIAL COMBAT section (pp.49-53)
// - the OUT reversal (the R172 appendix J
// precedent): the pins charge here, the
// fly seams charge the engine (the spell
// status and the potion claim), and the
// hex and written-orders methods stay OUT
// - the engine has no position, facing or
// altitude layer (the R311 recorded-notes
// grain); an airborne fight resolves on
// the flat geometry.
//
// The flight facts: every flyer climbs at
// one half and dives at twice the stated
// movement rate; a climb gains 1 foot per
// 3 feet forward, a dive 1 foot per foot
// (the 45 degree angle); class A is
// outside the climb and dive rules (any
// direction). A diving attack doubles the
// physical damage against any target not
// itself diving, including earthbound
// targets attacked from 30 feet up or
// more. No flyer climbs above 5000 feet.

#pragma once
namespace rules {

inline int aerialClimbRateDivisor() { return 2; }
inline int aerialDiveRateMultiple() { return 2; }
inline int aerialClimbFeetPerFootUp() { return 3; }
inline int aerialDiveFeetPerFootDown()
    { return 1; }
inline int aerialDiveEarthboundHeightFt()
    { return 30; }
inline int aerialCeilingFeet() { return 5000; }

// The maneuverability: five classes, A the
// best through E the worst. The turn per
// round assumes full speed - a flyer at
// half speed turns as one class better;
// winged flyers cannot move below half
// speed and stay aloft (class B excepted).
// The time to full airspeed reads segments
// for A and B, rounds for C, D and E; only
// A and B hover. The examples: the fly
// spell class B; the carpet and the wings
// of flying class C (the misc magic pins);
// dragons, rocs and wyverns class E.
inline int aerialTurnDegreesPerRound(int cls) {
    // A 180, B 120, C 90, D 60, E 30
    return cls == 1 ? 180 : cls == 2 ? 120 :
           cls == 3 ? 90 : cls == 4 ? 60 :
           cls == 5 ? 30 : 0;
}
inline int aerialSegmentsToFullSpeed(int cls) {
    // A 1 segment, B 6; the C, D and E rows
    // read rounds (the unit grain)
    return cls == 1 ? 1 : cls == 2 ? 6 : -1;
}
inline int aerialRoundsToFullSpeed(int cls) {
    // C 1, D 2, E 4 rounds; the A and B rows
    // read segments (the unit grain)
    return cls == 3 ? 1 : cls == 4 ? 2 :
           cls == 5 ? 4 : -1;
}
inline bool aerialHover(int cls) {
    // only A and B hold their place
    return cls == 1 || cls == 2;
}
inline int aerialFlySpellManeuverClass() {
    // the fly spell is a class B flyer
    return 2;
}

// The missile fire: a moving flyer treats
// short range as medium (-2 to hit) and
// medium as long (-5); long range always
// misses. A hovering flyer - the fly spell
// or the carpet - takes no penalty. A
// flying dragon and its kin add +2 to the
// saves of their flying breath targets.
inline int aerialMissileShortPenalty()
    { return -2; }
inline int aerialMissileMediumPenalty()
    { return -5; }
inline int aerialDragonBreathSaveBonus()
    { return 2; }

// The wing damage: a winged flyer past
// half its hit points in damage must land;
// past three quarters it plummets.
// Feathered wings add half the creature
// hit points to the flight-damage total (a
// 30 hit point griffon lands at 23 damage;
// a 30 hit point membrane wing falls at
// 15) - the extra points never absorb
// real damage.
inline int aerialWingDamageLandPct()
    { return 50; }
inline int aerialWingDamagePlummetPct()
    { return 75; }
inline int aerialFeatheredWingBonusPct()
    { return 50; }
}
