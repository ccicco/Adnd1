// =========================================================================================
// Adnd1 - rules/motpwater.h
// THE MotP PLANE OF ELEMENTAL WATER - printed pp. 46-51, the whole chapter in
// one round: the ocean doctrine, the survival, the phenomena, the pockets,
// the encounter chart, and the features (Istishia, the marids) - the four
// majors close here.
// census 494 -> 495.
//
// verified against printed pp. 46-51 of the uploaded motp.pdf OCR; the DMG/UA
// underwater-spell cross-references (pp. 56-57, 81) noted in the pins but not
// auto-credited - the MotP carries its own Water text.
//
// the gap census after this round: 32 closed, 58 open - three boxes fall (the
// plane and its two tables); the para-planes are next.
//
namespace rules {

// ---- the Water plane pins ----

// the drowning hazard: an unprotected character holds his breath for 1/3 his
// Constitution score (rounded up) in rounds; potions and spells of water
// breathing, the ring without a time limit, or polymorph to a water-breather
// carry the traveler.
inline int dczWaterBreathDivisor()
    { return 3; }

// the clearest water reduces sighting distance to 60 feet maximum; the
// varying temperature renders infravision no better than normal vision;
// sounds carry greater distances.
inline int dczWaterVisionFeet()
    { return 60; }

// travelers have a 1-in-10 chance of an encounter every four hours; roll:
// 1-10 elemental phenomena, 11-25 elemental pocket, 26-00 creature encounter.
inline int dczWaterEncounterDenom()
    { return 10; }

// the d12 phenomena: steam current (1-3), whirlpool (4-5), ice floe (6-8),
// tidal bore, silt flow, the airy water pocket, and the vortex to a Prime
// Material plane.
inline int dczWaterPhenomenaDieSides()
    { return 12; }

// the d20 pocket table: air 1-3, earth 4-6, ice 7-9, ooze 10-12, salt 13-14,
// steam 15-16, and the rare hostile fire/magma only at 20 - the airy-water
// survival rule governs them.
inline int dczWaterPocketTableDie()
    { return 20; }

// the Water encounter chart is a d8+d12 roll (2-20): 2 the Charonadaemon, 9
// the water elementals, 10 the marids, 11 the tritons, 20 the eye of the deep
// - the 2 and 20 unique-powers slots.
inline int dczWaterChartDieSides()
    { return 12; }

// the native vulnerability: all fire attacks on water elemental creatures
// inflict double damage with a -4 saving throw penalty (within the plane's
// fire limitations); natives are less susceptible to cold, earth and air
// attacks than Prime creatures.
inline int dczWaterNativeFireDouble()
    { return 2; }

// the ocean without a surface: pressure uniform in all directions like a few
// feet beneath a Prime ocean, soft glowing blues and greens radiating from
// the water itself - less harsh than Fire and Earth, less accessible than
// Air.
inline bool dczWaterOceanDoctrine()
    { return true; }

// the border gradations: muck toward Ooze, chill ice fragments toward Ice,
// warm agitation toward Steam, evaporating brine toward Salt.
inline bool dczWaterBordersGrade()
    { return true; }

// swimming creatures move at twice their normal rate in the plane of
// elemental Water.
inline bool dczWaterSwimDouble()
    { return true; }

// underwater combat per the DMG p. 56 limitations; nets entangle but cannot
// drag to a sea floor that does not exist; crossbows need magical bolts
// (normal bolts hang motionless once fired).
inline bool dczWaterCombatRules()
    { return true; }

// spells are affected as in Prime seas (DMG 57, UA 81) - a fireball is
// useless from the water itself but works in an air pocket; contact other
// plane makes silvery cabbage-sized balls; summonings make charmed
// golden-green spheres.
inline bool dczWaterMagicRule()
    { return true; }

// the marids: the handsomest, most powerful, most chaotic geniekind - a loose
// empire under a padisha, households of 2d10 around pocket clusters; nearly
// unsummonable (more trouble than worth, hence no marid-controlling items).
inline bool dczWaterMaridHousehold()
    { return true; }

}   // namespace rules
