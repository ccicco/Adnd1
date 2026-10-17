// =========================================================================================
// Adnd1 - rules/motpair.h
// THE MotP PLANE OF ELEMENTAL AIR - printed pp. 31-36, the whole chapter in
// one round: the hospitable plane, the phenomena, the winds, the pockets, the
// encounter chart, and the features (the archoment Yan-C-Bin, the queen
// Akadi, Bahamut's citadel, the djinn landholds, and the summoning hooks and
// bubbles).
// census 491 -> 492.
//
// verified against printed pp. 31-36 of the uploaded motp.pdf OCR; the
// high-winds table is the WSG-adapted table - the cross-book seam, nothing
// auto-credited, the MotP pins carry the MotP text (the 80-mph cutoff, the
// 1d8 impact rule, the 1d10-hour duration).
//
// the gap census after this round: 25 closed, 65 open - four boxes fall (the
// plane, the phenomena table, the high-winds table, the pockets table); Fire
// is next.
//
namespace rules {

// ---- the Air plane pins ----

// the sighting distance in the plane of Air is 1,000 yards - about twice a
// clear Prime day; infravision fails (as in all inner planes), smell-tracking
// is foiled by the chaotic winds.
inline int dcwAirSightingYards()
    { return 1000; }

// travelers in the plane of Air have a 1-in-20 chance of an encounter every
// 12 hours; roll: 1-20 elemental phenomena, 21-40 elemental pocket, 41-00
// creature encounter.
inline int dcwAirEncounterDenom()
    { return 20; }

// the d12 phenomena table: cloud banks, high winds, sirocco, rain storm,
// lightning storm, snow storm, maelstrom, dust storm, hail storm, and the
// vortex to a Prime Material plane.
inline int dcwAirPhenomenaDieSides()
    { return 12; }

// the d20 elemental pocket table - all sixteen other inner-plane types drift
// as pockets in the passive plane of Air, from earth (1-2) through mineral
// (20).
inline int dcwAirPocketTableDie()
    { return 20; }

// the Air encounter chart is a d8+d12 roll (2-20): 2 type I demons, 10 air
// elementals, 11 djinni, 12 invisible stalkers, 20 monadic devas - the 2 and
// 20 unique-powers slots.
inline int dcwAirChartDieSides()
    { return 12; }

// magical spells with verbal components cannot be cast when the wind rises
// above 80 mph; the high-wind impact damage is 1d8 per 10 mph of wind speed
// against a hard surface.
inline int dcwAirWindCutoffMPH()
    { return 80; }

// the maelstrom (the tornado eating its own tail) cannot be escaped short of
// moving faster than 2,000 feet per turn, magical winds, outside rescue, or
// leaving the plane; high wind lasts 1d10 hours and prevents encounters
// during that time.
inline int dcwAirMaelstromEscapeFt()
    { return 2000; }

// the temporary vortices to a Prime Material plane: most last 2d10 subjective
// days, only one in 50 lasts longer; the Prime-side opening is severe
// weather, several miles above the ground.
inline int dcwAirVortexDenom()
    { return 50; }

// the plane of Air is the most hospitable inner plane to Prime planar life:
// the medium can be breathed and is excellent for travel; its beings are the
// most easily summoned and controlled.
inline bool dcwAirHospitable()
    { return true; }

// the border gradations: thicker and warmer toward Smoke, cooler with ice
// crystals toward Ice, rain clouds and ozone toward Lightning, thinning to
// the airless state toward Vacuum.
inline bool dcwAirBordersGrade()
    { return true; }

// most Air-native creatures are invisible (only a 10% chance of a
// dust-outlined silhouette); they keep invisibility even when attacking; they
// are immune to weather, wind, lightning and cloud/mist spells - but trapped
// in complete vacuum they save vs. spell or perish.
inline bool dcwAirNativesInvisible()
    { return true; }

// the djinn landhold: an earth pocket 1,000 yards to several miles across,
// about 1,000 djinn plus 1d10 jann and 1d10 elemental servants under a
// maximum-hit-point sheik; caliphs rule within two days' travel with six
// viziers; messenger-relay alert.
inline bool dcwAirDjinnLandhold()
    { return true; }

}   // namespace rules
