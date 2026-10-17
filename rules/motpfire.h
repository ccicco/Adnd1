// =========================================================================================
// Adnd1 - rules/motpfire.h
// THE MotP PLANE OF ELEMENTAL FIRE - printed pp. 36-41, the whole chapter in
// one round: the survival ladder, the phenomena, the pockets, the encounter
// chart, and the features (Imix, Kossuth, the City of Brass, the azer, the
// spiraling flame).
// census 492 -> 493.
//
// verified against printed pp. 36-41 of the uploaded motp.pdf OCR; the
// survival ladder and the native vulnerability thresholds are the MotP's own
// text, pinned plane-by-plane per the R567 doctrine frame.
//
// the gap census after this round: 28 closed, 62 open - three boxes fall (the
// plane, the phenomena table, the pocket table); Earth is next.
//
namespace rules {

// ---- the Fire plane pins ----

// travelers in the plane of Fire have a 1-in-10 chance of an encounter every
// eight hours; roll: 1-15 elemental phenomena, 16-20 elemental pocket, 21-00
// creature encounter.
inline int dcxFireEncounterDenom()
    { return 10; }

// the d12 phenomena table: hot spot (1-4), cold spot (5-7), rain of ashes,
// smoke cloud, eruption, explosion field, and the vortex to a Prime Material
// plane.
inline int dcxFirePhenomenaDieSides()
    { return 12; }

// the d20 pocket table - the plane of Fire is the purest of the four majors
// (hostile to pockets): air 1-3, earth 4-6, smoke 7-9, magma 10-12, and the
// rare survivors through water/ooze/ice at 20.
inline int dcxFirePocketTableDie()
    { return 20; }

// the Fire encounter chart is a d8+d12 roll (2-20): 2 Imix (the archoment),
// 10 the azer, 11 the efreeti, 13 the salamanders, 40-400 flame goblins - the
// 2 and 20 unique-powers slots.
inline int dcxFireChartDieSides()
    { return 12; }

// the survival ladder: unprotected beings save vs. breath weapons or die,
// survivors take 4d10 per round (1d10 with a natural nonmetal AC 2+ and a +2
// save bonus); flammables burn their wearer for 3d6; nonmagical metal melts
// in two rounds (heat metal then 3d10); the thin hot atmosphere deals 1d10
// per round and cloudkill effects to the unprotected.
inline int dcxFireHeatDamageRounds()
    { return 10; }

// vision is limited to 120 feet in the misty, translucent brilliance; smoked
// glass or quartz lenses double the sighting distance; infravision finds
// non-natives as cooler spots but not natives against the flame background.
inline int dcxFireVisionFeet()
    { return 120; }

// the native vulnerability: temperatures below 100 degrees Fahrenheit deal
// 1d2 per round to a creature of elemental fire; water and ice spells deal
// 1d6 per quart of water used; natives are immune to fire/heat throughout the
// inner planes.
inline int dcxFireNativeColdDamageDie()
    { return 2; }

// the City of Brass: 40 miles across, its base a hemisphere of golden glowing
// brass, the Sultan's Palace in the citadel towers, bordered by magma seas
// and lava lakes - the grand sultan a Greater Power, advised by six great
// pashas for Prime business.
inline int dcxFireCityMiles()
    { return 40; }

// the border gradations: burnable haze and soot toward Smoke, basalt and
// flowing rock toward Magma, brightening flame toward Radiance, and dying
// fires with bone-chilling cold toward Ash.
inline bool dcxFireBordersGrade()
    { return true; }

// the hot spot: double fire damage and -1 saves for non-natives, but Fire
// natives regain 1d6 hit points per turn within; cold spots are sanctuaries
// near Prime desert temperatures where water and flammables can exist.
inline bool dcxFireHotSpotHeal()
    { return true; }

// the eruption: a moving sphere of flame spurting about 2,000 yards, hot-spot
// effects plus 2d6 debris damage; the explosion field adds 4d12 physical
// damage when tripped; the vortex opens in lakes of lava or volcano hearts.
inline bool dcxFireEruptionRange()
    { return true; }

// the magic rule: created materials are immediately affected by the plane
// (create water turns to steam in one round), spells cannot affect what does
// not exist (move earth needs an earth pocket), control winds and control
// weather fail in the thin atmosphere outside air pockets.
inline bool dcxFireMagicElementRule()
    { return true; }

// the spiraling flame, the plane-unique artifact: save vs. spell or be
// charmed and immobile, drawn in within 1-6 rounds, containerized and cast
// into another plane like an efreet in a bottle - only ally rescue frees the
// victim; it cannot leave the plane of Fire.
inline bool dcxFireSpiralFlame()
    { return true; }

}   // namespace rules
