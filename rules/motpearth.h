// =========================================================================================
// Adnd1 - rules/motpearth.h
// THE MotP PLANE OF ELEMENTAL EARTH - printed pp. 41-46, the whole chapter in
// one round: the solid wall doctrine, the survival rules, the Strength
// movement ladder, the phenomena, the pockets, the native passwall doctrine,
// and the features (Ogremoch, Grumbar, the dao and the Great Dismal Delve,
// the silver doorways).
// census 493 -> 494.
//
// verified against printed pp. 41-46 of the uploaded motp.pdf OCR; the DSG
// mining cross-references (pp. 12, 48, 50-53) noted in the pins but not
// auto-credited - the MotP carries its own Earth text (the pressure, the
// ladder, the quake tiers).
//
// the gap census after this round: 29 closed, 61 open - one box falls (the
// Earth plane, encounters within it); Water closes the four majors next.
//
namespace rules {

// ---- the Earth plane pins ----

// the plane of Earth is the least hospitable of the four majors: the
// surrounding rock inflicts 1d2 points of damage per turn on the traveler
// caught like a fly on gummed paper, unable to move or return to the Ethereal
// unaided.
inline int dcyEarthPressureDie()
    { return 2; }

// travelers in the plane of Earth have a 1-in-10 chance of an encounter every
// four hours; roll: 1-5 elemental phenomena, 6-35 elemental pocket, 36-00
// creature encounter.
inline int dcyEarthEncounterDenom()
    { return 10; }

// the earthquake severity roll is d10: light (1-4) deals 4d6, medium (5-8)
// deals 6d6, severe (9-10) deals 8d6; a passing traveler saves vs. spell or
// is flung into the earth and trapped.
inline int dcyEarthQuakeSeverityDie()
    { return 10; }

// the volatile gas pocket: 60% poisonous (cloudkill in the pocket), 40% also
// explosive - open flame deals 8d8 fire damage to all within and 30% chance
// the walls weaken to a quake.
inline int dcyEarthGasPoisonPct()
    { return 60; }

// the fossil roll: 1-30 Prime Material creature, 31-90 human traveler (the
// largest share), 91-00 outer planar; 20% of fossils converted to precious
// minerals; human remains keep arms, armor and magic.
inline int dcyEarthFossilHumanPct()
    { return 31; }

// the brute-force movement ladder (d10): very soft rock needs Strength 15,
// soft 18, hard 19, impenetrable 23 or Power abilities - at one actual foot
// per turn; the DSG mining rules (p. 48) apply where there is room to swing
// tools.
inline int dcyEarthStrengthSoft()
    { return 15; }

// the air pocket: a dry, lightless cavern, 80% occupied - Earth creatures
// 30%, Air creatures 30%, other-planar wayfarers 40% - the habitable heart of
// the inhabited plane.
inline int dcyEarthAirPocketOccPct()
    { return 80; }

// the traveler in Earth rock is blind but hears through it: any movement
// within 6 inches is detectable, including the passage of ethereal or phased
// creatures through the stone.
inline int dcyEarthHearingInches()
    { return 6; }

// air, water and fire all part for the traveler, but elemental earth forms a
// solid wall: entry requires a pocket, a stone shape, a passwall, or shape
// change into an earth creature - the Border Ethereal is the default stance.
inline bool dcyEarthSolidWall()
    { return true; }

// the border gradations: warming viscous rock toward Magma, wetter pliable
// stone toward Ooze, crystal and ore bands toward Minerals, drying crumbling
// soil toward Dust.
inline bool dcyEarthBordersGrade()
    { return true; }

// all Earth natives (and the Magma, Ooze, Minerals and Dust natives) have a
// permanent passwall ability through elemental earth, conferred on those in
// physical contact - they treat the plane as the Ethereal for movement; Prime
// mimics are AC 2 factors better than their counterparts.
inline bool dcyEarthNativePasswall()
    { return true; }

// the magic rule: blind casters can only use range-0 or self spells unless
// they can see through the rock; created items do not move the stone (a wall
// of iron looks like a vein of iron, created water drains into mud pockets).
inline bool dcyEarthMagicRangeRule()
    { return true; }

// Earth natives are immune to earth-modifying spells (earthquake, move earth,
// stone shape) anywhere on the inner planes; they hide as thieves of level
// equal to their hit dice.
inline bool dcyEarthNativeEarthImmunity()
    { return true; }

// the spell effects: Prime conjurations appear as great silver doorways of
// four to six sides that charm the summoned type - a traveler passing through
// is treated as a conjured, possibly controlled, creature; contact other
// plane makes angular translucent bubbles.
inline bool dcyEarthSilverDoorway()
    { return true; }

}   // namespace rules
