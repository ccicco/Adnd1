// =========================================================================================
// Adnd1 - rules/motppara.h
// THE MotP PARA-ELEMENTAL PLANES - printed pp. 51-54, the four planes in one
// round: Smoke, Magma, Ooze and Ice - the survival, the pockets, the
// encounter check, the mapping doctrines, and the features (the archoments
// and Cryonax of Ice).
// census 495 -> 496.
//
// verified against printed pp. 51-54 of the uploaded motp.pdf OCR; the
// para-planes pin by mapping onto the R568-R571 major-plane pins (Smoke as
// Air, Magma and Ooze as Water and Fire, Ice as Earth) with the MotP's own
// differences carried explicitly.
//
// the gap census after this round: 34 closed, 56 open - two boxes fall (the
// para-planes group, the encounter table); the energy planes are next.
//
namespace rules {

// ---- the para-planes pins ----

// the four para-planes between the majors: Smoke where Air meets Fire, Magma
// where Fire meets Earth, Ooze where Earth meets Water, Ice where Water meets
// Air - minor because harder to reach, fewer powers, less varied, and
// transitional.
inline int ddaParaPlaneCount()
    { return 4; }

// travelers in any of the four para-planes have a 1-in-20 chance of an
// encounter, checked every eight TRUE hours; roll: 1-20 elemental pocket,
// 21-00 creature encounter - no outstanding phenomena, only small local
// variations.
inline int ddaParaEncounterDenom()
    { return 20; }

// the vision ladder: Smoke the best at about 30 yards; Magma and Ooze limited
// to touch range without x-ray devices; Ice varies 10-20 yards with the
// translucency.
inline int ddaParaSmokeVisionYards()
    { return 30; }

// the Ice survival: the unprotected suffer 1d6 cold damage per round, reduced
// to 1d6 per TURN when well-protected or wrapped in furs, negated by cold
// protection; the trapped are incredibly well preserved - no incarceration
// damage.
inline int ddaParaIceColdDieSides()
    { return 6; }

// each para-plane contains equal pockets from the two adjacent majors
// (50/50): Smoke takes air or fire, Magma fire or earth, Ooze water or earth,
// Ice water or air - with the lair chances per pocket type.
inline int ddaParaPocketSplitPct()
    { return 50; }

// the para-elemental encounter chart is a d8+d12 roll (2-20): 2 the
// para-element prince of evil, 9 the para-elementals, 14 the adjacent-major
// genie - the parenthetical suggestions per plane guide the DM.
inline int ddaParaChartDieSides()
    { return 12; }

// the para-elemental guides: gruff, bribed as the majors, but plane-appealing
// gifts (smoke essence, an ice-carving) double the service duration with a
// 50% chance they fight with the party.
inline int ddaParaGuideFightPct()
    { return 50; }

// Smoke survival: asphyxiation is the danger, the particles and gases
// unbreathable - airy smoke and smoke breathing negate it; only
// breath-eliminating devices permit long adventures.
inline bool ddaParaSurvivalSmoke()
    { return true; }

// Magma treats the traveler to Fire's heat and flame with breathing as in a
// hot liquid - protection plus element-breathing needed; Ooze has Water's
// drowning - water breathing works without modification.
inline bool ddaParaSurvivalMagmaOoze()
    { return true; }

// para-elementals are immune to their home para-plane and its related major
// planes while in the inner planes (the magma troll immune to flame and
// magma, unrestricted in Earth); Ice natives move and fight in Ice, Water and
// Air, immune to cold and ice.
inline bool ddaParaNativeImmunity()
    { return true; }

// the movement mapping: Magma and Ooze as Water (falling included), Smoke as
// Air, Ice as Earth save any Strength moves through the soft ice; combat maps
// identically (Smoke hardly restricted, Ice as Earth).
inline bool ddaParaMovementMap()
    { return true; }

// the magic mapping: Smoke unrestricted; Magma casts as through water if the
// caster can see, Fire's effects on created material; Ooze suffers the
// underwater strictures; Ice solid as Earth - created fires work but melt the
// ice which extinguishes them.
inline bool ddaParaMagicMap()
    { return true; }

// no single leader per plane, but ice lords, slime barons, magma generals and
// smoke dukes vie for control; the mightiest are Demi-Powers with NO Greater
// Powers above them - Cryonax of Ice the described one, with Ehkahk, Chlimbia
// and Bwimb named.
inline bool ddaParaArchomentRule()
    { return true; }

}   // namespace rules
