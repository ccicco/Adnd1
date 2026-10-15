// =========================================================================================
// Adnd1 - rules/wsglight.h
// R485: the WSG ARTIFICIAL ILLUMINATION slice, printed pp. 74-75 - the fourth
// and final vision-and-visibility round, a pure prose round with NO table,
// CLOSING the vision chapter: the twilight-as-light frame with the
// radius-precedence rule and the 40-foot torch vs 300-yard twilight
// comparison, the four torch wind bands (calm, 11-25, 26-40, above 40) with
// their radius and burn-time degradation, the 25%-every-five-rounds
// extinguish risk, the torch-lighting time rule with the fire-building
// proficiency halving, the lantern and bullseye sighting geometry, the magic
// weapon glow rule with the dagger/short sword/long sword figures, the three
// campfire radii, and the group visibility rules with the lantern-holder
// blind spot and the fringe-sees-normally rule.
// census 409 -> 410.
//
// The settle: two-way clean on the first pass - the tesseract full-text read,
// the pdfy layout read and the tsv coordinate read agree on every number of
// the page (the wind bands 11-25 and 26-40 mph, the 30/40 feet, the 4/6/2
// turns, the 25% and five rounds, the 200/100/200/100 sighting yards, the
// 100/150/200 magic glows, the 80/120/150 campfire radii, the 30-foot lantern
// radius); the tesseract /arge for large is an italic-L scan artifact, pdfy
// reading it cleanly. The section began at the bottom of printed p. 74 (the
// PHB p. 102 pointer, the twilight frame and the 40-foot torch example, cut
// mid-word in il-) and its opening prose is pinned with this round. No
// contested cells, no vision reads needed.
//
// Bounds held: the wind bands tile 10-25-40-41 with no gaps, the torch radius
// and burn time degrade monotonically (40 to 30 feet, 6 to 4 to 2 turns),
// every magic weapon glow is exactly ten times its radius, and the campfire
// radii strictly ascend 80 under 120 under the 150 floor.
//
namespace rules {

// ---- The twilight frame and precedence ----

// the section supplements the Players Handbook page 102 statistics with facts
// relevant to the outdoor environment
inline bool wliSupplementsPHB()
    { return true; }

// an artificial light source in moonlight or darkness lets characters within
// the illuminated area see with normal vision as if the natural light was
// twilight
inline bool wliLightAsTwilight()
    { return true; }

// or perhaps daylight, as in the case of a continual light spell
inline bool wliContinualLightAsDaylight()
    { return true; }

// the specified radius of illumination of the light source takes precedence
// over the figures on the Range of Normal Vision Table
inline bool wliRadiusTakesPrecedence()
    { return true; }

// the torch radius of illumination on a clear night (the PHB figure)
inline int wliTorchRadiusFt()
    { return 40; }

// in actual twilight under a clear sky he would see 300 yards without a light
// source
inline int wliTwilightNoLightYards()
    { return 300; }

// ---- The torch wind bands ----

// both the radius of illumination and the burning time of a torch can be
// affected by wind velocity
inline bool wliTorchWindAffects()
    { return true; }

// wind below 10 mph: the Players Handbook figures apply
inline int wliWind1MaxMph()
    { return 10; }

// the windy band starts at 11 mph
inline int wliWind2MinMph()
    { return 11; }

// and ends at 25 mph
inline int wliWind2MaxMph()
    { return 25; }

// in wind of 11-25 mph the flame of the torch struggles and flickers
inline bool wliWindyFlicker()
    { return true; }

// 11-25 mph: reliable illumination only out to 30 feet instead of 40
inline int wliTorchWindyRadiusFt()
    { return 30; }

// the PHB burning time: 6 turns
inline int wliTorchBurnTurns()
    { return 6; }

// 11-25 mph: the torch burns out in 4 turns instead of 6
inline int wliTorchWindyBurnTurns()
    { return 4; }

// the gale band starts at 26 mph
inline int wliWind3MinMph()
    { return 26; }

// and ends at 40 mph
inline int wliWind3MaxMph()
    { return 40; }

// in wind of 26-40 mph the radius of illumination is not further reduced
inline bool wliGaleRadiusHeld()
    { return true; }

// 26-40 mph: the flame lasts only 2 turns at most
inline int wliTorchGaleBurnTurns()
    { return 2; }

// 26-40 mph: a 25% chance of the torch being extinguished by the wind
inline int wliExtinguishPct()
    { return 25; }

// the extinguish chance is checked every five rounds
inline int wliExtinguishCheckRounds()
    { return 5; }

// in 26-40 mph wind there is a chance the torch is extinguished by the wind
// and must be reignited
inline bool wliGaleExtinguishRisk()
    { return true; }

// above 40 mph: more than 40
inline int wliWind4MinMph()
    { return 41; }

// in wind of more than 40 mph a torch cannot be kept burning for more than 1
// round
inline int wliTorchStormMaxRounds()
    { return 1; }

// in a wind of more than 40 mph it is impossible to keep a torch burning for
// more than 1 round
inline bool wliStormImpossible()
    { return true; }

// it takes 1 round to light a torch
inline int wliLightBaseRounds()
    { return 1; }

// plus 1 round for every 10 mph of wind velocity
inline int wliLightWindStepMph()
    { return 10; }

// the torch-lighting time is cut in half for a character with proficiency in
// fire building
inline bool wliLightProfHalved()
    { return true; }

// in moonlight or darkness a lighted torch can be seen from 200 yards
inline int wliTorchSeenYards()
    { return 200; }

// ---- The lantern and bullseye ----

// a lantern or bullseye lanthorn is much more reliable in the wilderness: the
// flame is protected, will not flicker or be extinguished by the wind, and
// the radius of illumination generally remains constant
inline bool wliLanternReliable()
    { return true; }

// regular lantern light can be seen from 100 yards away
inline int wliLanternSeenYards()
    { return 100; }

// a bullseye lanthorn beam is seen from 200 yards if the viewer looks
// directly back toward the source
inline int wliBullseyeBackYards()
    { return 200; }

// or from 100 yards if the viewer's gaze is directed across the path of the
// beam
inline int wliBullseyeAcrossYards()
    { return 100; }

// ---- Magic weapons ----

// a magic weapon illuminates a smaller area than a torch or a lantern
inline bool wliMagicWeaponSmallerArea()
    { return true; }

// a magic weapon needs no fuel and is not affected by the wind
inline bool wliMagicNoFuelNoWind()
    { return true; }

// the glow of a magic weapon can be seen from ten times its radius of
// illumination
inline int wliMagicGlowFactor()
    { return 10; }

// magic dagger radius of illumination
inline int wliDaggerRadiusFt()
    { return 10; }

// magic dagger glow seen from 100 feet
inline int wliDaggerGlowFt()
    { return 100; }

// magic short sword radius of illumination
inline int wliShortSwordRadiusFt()
    { return 15; }

// magic short sword glow seen from 150 feet
inline int wliShortSwordGlowFt()
    { return 150; }

// magic long sword radius of illumination
inline int wliLongSwordRadiusFt()
    { return 20; }

// magic long sword glow seen from 200 feet
inline int wliLongSwordGlowFt()
    { return 200; }

// ---- Campfires ----

// a small campfire illuminates an 80-foot radius
inline int wliCampSmallRadiusFt()
    { return 80; }

// a medium campfire lights up 120 feet on all sides
inline int wliCampMediumRadiusFt()
    { return 120; }

// a large campfire has a radius of at least 150 feet
inline int wliCampLargeMinRadiusFt()
    { return 150; }

// a large campfire's radius of illumination is at least 150 feet, perhaps
// more if the fire is especially large
inline bool wliCampLargeAtLeast()
    { return true; }

// for other information on fires, see the section on Camping and Campfires
inline bool wliCampfireSeeCamping()
    { return true; }

// ---- The group visibility rules ----

// the use of any artificial light source, including magical light, in
// moonlight or darkness limits long-range visibility to varying degrees for
// all characters within the illuminated area
inline bool wliLightLimitsLongRange()
    { return true; }

// the lantern of the worked example illuminates a 30-foot radius
inline int wliLanternRadiusFt()
    { return 30; }

// a character holding a lantern cannot make out any details in the darkness
// immediately beyond the radius the lantern illuminates
inline bool wliHolderBlindBeyond()
    { return true; }

// someone standing at the fringe of the illuminated area can still see
// normally into the darkness ahead of him
inline bool wliFringeSeesNormally()
    { return true; }

// for a group traveling at night with artificial light the Dungeon Master
// should note which characters carry light sources and where the others stand
// with respect to the light-holder
inline bool wliDMTracksPositions()
    { return true; }

}   // namespace rules
