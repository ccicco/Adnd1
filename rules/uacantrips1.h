// ===========================================================================
// Adnd1 - rules/uacantrips1.h
// The UA MAGIC-USER CANTRIP
// DESCRIPTIONS, part 1 (R412):
// the USEFUL category (pp. 45-47),
// 20 cantrips. The R363
// illusionist-cantrips precedent
// rides: the descriptions pin; the
// casting-time fraction cells garble
// in the scan ("/? segment", "V?",
// 'h', 'k, Tfe, '/e - the whole
// family) and record as holes
// pending the PDF read - never
// guesses.
//
// The school tags print clean:
// Evocation 7 (Chill, Color,
// Dampen, Salt, Spice, Sweeten,
// Warm), Abjuration 4 (Clean, Dry,
// Dust, Exterminate), Alteration 7
// (Gather, Polish, Shine, Sprout,
// Stitch, Tie, Wrap), Enchantment
// 2 (Flavor, Freshen).
//
// The area lines print clean for
// 14 blocks: the one-object eight
// (Flavor, Freshen, Polish, Salt,
// Shine, Spice, Sweeten, Tie), the
// 1' cube pair (Chill, Warm), the
// cubic yard pair (Color, Wrap),
// the Clean 4 sq. yds., the Stitch
// Special. The six "7"-family
// garbles (Dampen, Dry, Dust
// 70', Exterminate, Gather,
// Sprout) record as area holes
// pending the PDF read.
//
// The mechanics pin clean: the
// Chill/Warm 40 F pair (both
// directions cross-check), the
// Freshen/Salt 1-4 damage pair,
// the Salt 4 sq. yds. and 30
// gallons limits, the Tie 1 range
// with the knot forms, the Shine
// 1 cubic yard with the DMG p. 26
// revalue at -1 once only, the
// Color 30-day renewal, the Polish
// 1,000 sq. ft. floor.

#pragma once

namespace rules {

// The school codes.
const int UCN_EVO = 0;
const int UCN_ABJ = 1;
const int UCN_ALT = 2;
const int UCN_ENCH = 3;

// The area kind codes.
const int UCN_AREA_HOLE = -1;
const int UCN_AREA_OBJECT = 0;
const int UCN_AREA_CUBEFoot = 1;
const int UCN_AREA_CUBICyd = 2;
const int UCN_AREA_SPECIAL = 3;
const int UCN_AREA_SQYDS = 4;

// One useful cantrip: the name,
// the school, the area kind and
// the area value (the Clean 4 sq.
// yds.; 0 when the kind carries
// no number).
struct UcnCantrip {
    const char* name;
    int school;
    int areaKind;
    int areaVal;
};

// The 20 useful cantrips, in the
// R341/R401 roster order.
inline const UcnCantrip& ucnUseful(int i) {
    static const UcnCantrip T[20] = {
        { "Chill", 0, 1, 1 },
        { "Clean", 1, 4, 4 },
        { "Color", 0, 2, 1 },
        { "Dampen", 0, -1, 0 },
        { "Dry", 1, -1, 0 },
        { "Dust", 1, -1, 0 },
        { "Exterminate", 1, -1, 0 },
        { "Flavor", 3, 0, 0 },
        { "Freshen", 3, 0, 0 },
        { "Gather", 2, -1, 0 },
        { "Polish", 2, 0, 0 },
        { "Salt", 0, 0, 0 },
        { "Shine", 2, 0, 0 },
        { "Spice", 0, 0, 0 },
        { "Sprout", 2, -1, 0 },
        { "Stitch", 2, 3, 0 },
        { "Sweeten", 0, 0, 0 },
        { "Tie", 2, 0, 0 },
        { "Warm", 0, 1, 1 },
        { "Wrap", 2, 2, 1 },
    };
    if (i < 0) i = 0;
    if (i > 19) i = 19;
    return T[i];
}

inline int ucnUsefulCount()
    { return 20; }

// The school census.
inline int ucnSchoolCount(int s) {
    int n = 0;
    for (int i = 0; i < 20; ++i)
        if (ucnUseful(i).school == s)
            ++n;
    return n;
}

// The area kind census.
inline int ucnAreaKindCount(int a) {
    int n = 0;
    for (int i = 0; i < 20; ++i)
        if (ucnUseful(i).areaKind == a)
            ++n;
    return n;
}

// The casting-time hole family:
// ALL 20 casting-time cells print
// fraction garbles in the scan -
// the whole family records as
// holes pending the PDF read (the
// R363 illusionist-cantrips
// posture).
inline bool ucnCastTimesAreHoles()
    { return true; }

// ---- the mechanics pins ----

// The Chill/Warm temperature delta
// (both about 40 F; the pair
// cross-checks).
inline int ucnTempDeltaF()
    { return 40; }

// The Freshen damage max (1-4 on
// a creature harmed by purify food
// and drink).
inline int ucnFreshenDmgMax()
    { return 4; }

// The Salt damage max (1-4 on a
// salt-averse creature; the pair
// cross-checks freshen).
inline int ucnSaltDmgMax()
    { return 4; }

// The Salt object limits: about 4
// square yards or 30 gallons.
inline int ucnSaltObjectSqYds()
    { return 4; }

inline int ucnSaltGallons()
    { return 30; }

// The Tie range: the similar end
// within 1 foot.
inline int ucnTieRangeFt()
    { return 1; }

// The Shine volume: a single
// object up to about 1 cubic yard.
inline int ucnShineMaxCubicYds()
    { return 1; }

// The Shine revalue: roll again
// on the DMG p. 26 table with a
// -1 die modifier, once only.
inline int ucnShineRevalueDieMod()
    { return -1; }

inline bool ucnShineRevalueOnceOnly()
    { return true; }

// The Color renewal: the effect
// must be renewed every 30 days.
inline int ucnColorRenewDays()
    { return 30; }

// The Polish floor: up to 1,000
// square feet.
inline int ucnPolishFloorSqFt()
    { return 1000; }

}   // namespace rules

