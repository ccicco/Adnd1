// ===========================================================================
// Adnd1 - rules/underwater.h
// The underwater environment (R311).
//
// The DMG UNDERWATER ADVENTURES section (upload
// lines 4055-4130) with the surface SWIMMING
// paragraph (upload line 4017): the swim
// terms, the underwater movement, vision and
// combat. The underwater spell use lists and
// the fire and electrical facts ride R168
// (rules/uwspells.h) - this header does not
// re-pin them.
//
// The surface swim: swimming impossible in any
// metal armor except magic armor (the dog
// paddle the only stroke possible); leather
// and padded armor swim at 5 percent drown per
// hour, the chance +2 percent per 5 pounds of
// possessions beyond the armor; winds above
// 35 miles per hour swim at 75 percent drown.
//
// The underwater movement: swimming impossible
// in armor heavier than leather (magic armor
// excepted) or above 20 pounds of equipment -
// the cap moves 1 pound per 100 g.p. of
// strength bonus or penalty (the caller feeds
// the strength weight allowance in g.p.; the
// engine has no allowance accessor); movement
// reads the dungeon speeds with the dungeon
// encumbrance ratios; free action moves at 3x
// the dungeon rate (the wilderness rate);
// swimmers move vertically at the same rate.
//
// The vision: 50 feet fresh water, 100 salt;
// the depth limit the distance limit; the
// optional decay - 10 feet of distance per 10
// feet of depth, fresh 0 at 60, salt 0 at 110;
// the light spell 30 feet regardless of depth
// or +10 feet to any distance under 60,
// whichever greater; the helm of underwater
// action quintuples distance AND depth;
// infravision as in dungeons; ultravision
// halved at 100 feet of depth, zero below 200;
// seaweed and sea grass reduce vision to 10
// feet or nil (the grass 3-30 feet tall);
// shoals totally obstruct; mud clouds block
// vision d6+6 rounds after the movement stops.
//
// The combat: only thrusting weapons (crushing
// and cleaving fail); aquatic creatures always
// strike first unless the human weapon is
// significantly longer; free action allows any
// weapon with no reaction penalty; nets thrown
// 1 foot per strength point (the underwater
// races 15, the sahuagin 20), the untrained at
// -4; missile weapons impossible except the
// special crossbow at 10x price and half the
// dungeon range.
//
// RECORDED NOTES (ride the pin, not data): the
// breathing aids (the water breathing, airy
// water, shape change and wish spells; the
// potion; the helm of underwater action and
// the cloak of the manta ray), the one
// unsheathed dagger carried between the teeth,
// the swimmer vulnerable from every direction,
// the infravision temperature-layer confusion,
// the schools of fish, the mud even light
// cannot penetrate, the stretched, weighted
// and barbed net prose, and the keep-dry rule
// for bows, scrolls and books. The net throw
// is now charged (R315 - the state_combat
// volley fold; sahuagin and the underwater
// races throw at the DMG distances); the
// untrained -4 and the strength-point range
// stay recorded (no party net exists - the
// PHB p.38 table carries no net row; no
// allowance accessor exists); the rest rides
// no engine layer yet (a state seam is the
// future candidate).
//
// DATA-DRIVEN (the standing scope).
// ===========================================================================

#pragma once

namespace rules {

// ---- the surface swim ----

// Metal armor: swimming impossible (the flag).
inline int uwSurfaceMetalArmorImpossible() {
    return 1;
}

// Magic armor excepts the metal ban.
inline int uwSurfaceMagicArmorExcepted() {
    return 1;
}

// In magic armor the dog paddle is the only
// stroke possible.
inline int uwSurfaceMagicArmorDogPaddleOnly() {
    return 1;
}

// Leather and padded armor swim.
inline int uwSurfaceLeatherPaddedPossible() {
    return 1;
}

// The leather-or-padded drown chance per
// hour (percent).
inline int uwSurfaceLeatherDrownPctPerHour() {
    return 5;
}

// The drown step: pounds per step.
inline int uwSurfaceDrownStepLbs() {
    return 5;
}

// The drown step: percent per step.
inline int uwSurfaceDrownStepPct() {
    return 2;
}

// The leather-or-padded drown percent per
// hour with lbs of possessions beyond the
// armor: 5 + 2 per full 5 pounds (the
// negatives clamped to the base).
inline int uwSurfaceDrownPct(int carriedLbs) {
    if (carriedLbs < 0) carriedLbs = 0;
    return 5 + 2 * (carriedLbs / 5);
}

// Winds above this speed: almost impossible.
inline int uwSurfaceHighWindMph() {
    return 35;
}

// The high-wind drown chance (percent).
inline int uwSurfaceHighWindDrownPct() {
    return 75;
}

// ---- the underwater movement ----

// Swimming impossible in armor heavier than
// leather (the flag).
inline int uwSwimArmorHeavierThanLeatherBlocked() {
    return 1;
}

// Magic armor excepts the armor ban.
inline int uwSwimMagicArmorExcepted() {
    return 1;
}

// The equipment cap: 20 pounds of any type.
inline int uwSwimEquipmentCapLbs() {
    return 20;
}

// The cap moves 1 pound per 100 g.p. of
// strength bonus or penalty.
inline int uwSwimCapAdjLbsPer100gp() {
    return 1;
}

// The swim encumbrance cap in pounds; the
// caller feeds the strength weight allowance
// adjustment in g.p. (C truncation: each
// full 100 g.p. one pound).
inline int uwSwimEncumbranceCapLbs(int strBonusGp) {
    return 20 + strBonusGp / 100;
}

// Movement (swimming or walking) reads the
// dungeon speeds with the dungeon encumbrance
// ratios.
inline int uwMoveSameAsDungeon() {
    return 1;
}

// Free action moves at 3x the dungeon rate
// (the wilderness rate).
inline int uwFreeActionRateMultiple() {
    return 3;
}

// Swimmers move vertically at the same rate.
inline int uwSwimVerticalSameRate() {
    return 1;
}

// ---- the underwater vision ----

// The base distance of vision: fresh 50,
// salt 100 (salt nonzero).
inline int uwVisionBaseFt(int salt) {
    return salt ? 100 : 50;
}

// The depth limit of vision is the distance
// limit (obscured below the base).
inline int uwVisionDepthLimitSameAsDistance() {
    return 1;
}

// The optional decay segment: 10 feet of
// depth and 10 feet of distance per step.
inline int uwVisionDecaySegmentFt() {
    return 10;
}

// The optional decay distance at depth
// (salt nonzero; clamped to the base and to
// zero): fresh 50 at 10 feet to 0 at 60;
// salt 100 at 10 feet to 0 at 110.
inline int uwVisionDecayFt(int salt, int depthFt) {
    int base = salt ? 100 : 50;
    int v = (salt ? 110 : 60) - 10 * (depthFt / 10);
    if (v < 0) v = 0;
    if (v > base) v = base;
    return v;
}

// The light spell: 30 feet regardless of
// depth.
inline int uwLightSpellMinFt() {
    return 30;
}

// ...or +10 feet of vision to any distance
// shorter than 60 feet.
inline int uwLightSpellBonusFt() {
    return 10;
}

inline int uwLightSpellBonusThresholdFt() {
    return 60;
}

// The light spell vision at distance: the
// greater of 30 feet and dist + 10 when
// dist is under 60.
inline int uwLightSpellVisionFt(int distFt) {
    int v = distFt < 60 ? distFt + 10 : distFt;
    if (v < 30) v = 30;
    return v;
}

// The helm of underwater action quintuples
// normal vision - distance AND depth.
inline int uwHelmVisionMultiple() {
    return 5;
}

// Infravision: the dungeon distance limits.
inline int uwInfravisionSameAsDungeon() {
    return 1;
}

// Ultravision: halved at this depth.
inline int uwUltravisionHalvedAtDepthFt() {
    return 100;
}

// Ultravision: zero below this depth.
inline int uwUltravisionZeroBelowDepthFt() {
    return 200;
}

// The ultravision rate at depth: 2 full
// above 100 feet, 1 (half) from 100 to 200,
// 0 below 200.
inline int uwUltravisionRate(int depthFt) {
    return depthFt <= 200 ?
        (depthFt >= 100 ? 1 : 2) : 0;
}

// Seaweed or sea grass reduces vision to 10
// feet.
inline int uwSeaweedVisionFt() {
    return 10;
}

// ...or perhaps nil, on the density.
inline int uwSeaweedVisionMayBeNil() {
    return 1;
}

// The sea grass height band (feet).
inline int uwSeaGrassHeightLoFt() {
    return 3;
}

inline int uwSeaGrassHeightHiFt() {
    return 30;
}

// Shoals of either totally obstruct vision.
inline int uwShoalTotallyObstructs() {
    return 1;
}

// Mud clouds totally block vision while the
// violent movement lasts and d6 + 6 rounds
// after it stops (the 7-12 band).
inline int uwMudCloudRoundsDie() {
    return 6;
}

inline int uwMudCloudRoundsPlus() {
    return 6;
}

// ---- the underwater combat ----

// Only thrusting weapons (crushing and
// cleaving fail).
inline int uwCombatThrustingOnly() {
    return 1;
}

// Aquatic creatures always strike first
// unless the human weapon is significantly
// longer.
inline int uwAquaticFirstStrike() {
    return 1;
}

// Free action: any normal weapon.
inline int uwFreeActionAnyWeapon() {
    return 1;
}

// Free action: no reaction penalty.
inline int uwFreeActionNoReactionPenalty() {
    return 1;
}

// A net throws 1 foot per strength point.
inline int uwNetThrowFtPerStrPoint() {
    return 1;
}

// The underwater races throw nets an average
// of 15 feet; the sahuagin 20.
inline int uwNetThrowUnderwaterRaceFt() {
    return 15;
}

inline int uwNetThrowSahuaginFt() {
    return 20;
}

// The untrained underwater net: -4 to hit.
inline int uwNetUntrainedPenalty() {
    return 4;
}

// Missile weapons impossible except the
// specially-made crossbow.
inline int uwMissileExceptCrossbowImpossible() {
    return 1;
}

// The special crossbow: 10x the normal
// price.
inline int uwSpecialCrossbowPriceMultiple() {
    return 10;
}

// ...and half the normal (dungeon) range.
inline int uwSpecialCrossbowRangeDivisor() {
    return 2;
}

}  // namespace rules
