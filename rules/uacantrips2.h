// ===========================================================================
// Adnd1 - rules/uacantrips2.h
// The UA MAGIC-USER CANTRIP
// DESCRIPTIONS, part 2 (R413):
// the REVERSED category
// (pp. 47-48), 12 cantrips. The
// R363/R412 precedents ride: the
// descriptions pin; the
// casting-time fraction cells
// garble in the scan (the whole
// family) and record as holes
// pending the PDF read - never
// guesses.
//
// The school tags print clean:
// Evocation 3 (Dirty, Dusty,
// Sour), Abjuration 0,
// Alteration 7 (Hairy, Knot,
// Ravel, Spill, Tangle, Tarnish,
// Untie), Enchantment 2 (Curdle,
// Wilt).
//
// The area lines print clean for
// ALL 12 blocks - ZERO area
// holes this round: the
// one-object eight (Curdle,
// Hairy, Knot, Sour, Tangle,
// Tarnish, Untie, Wilt), the
// Dirty 4 sq. yds. (cross-checks
// the Clean 4 sq. yds. from
// R412), the Dusty 10' radius,
// the Ravel Special, the Spill
// one container.
//
// The mechanics pin clean: the
// Hairy 2-12 inch growth with
// the under-1-inch short-
// material read and the
// reversed 2-12 day absence, the
// Knot 2-8 rounds, the Tangle
// 3-12 rounds, the Sour 1-pint
// vinegar max, the Spill
// 1-gallon container limit, the
// Tarnish 1 cubic yard (the
// reverse of the R412 shine
// volume - a live cross-check).

#pragma once

namespace rules {

// The school codes.
const int UCR_EVO = 0;
const int UCR_ABJ = 1;
const int UCR_ALT = 2;
const int UCR_ENCH = 3;

// The area kind codes.
const int UCR_AREA_HOLE = -1;
const int UCR_AREA_OBJECT = 0;
const int UCR_AREA_SPECIAL = 3;
const int UCR_AREA_SQYDS = 4;
const int UCR_AREA_RADIUS = 5;
const int UCR_AREA_CONTAINER = 6;

// One reversed cantrip: the
// name, the school, the area kind
// and the area value (the Dirty 4
// sq. yds., the Dusty 10'
// radius; 0 when the kind
// carries no number).
struct UcrCantrip {
    const char* name;
    int school;
    int areaKind;
    int areaVal;
};

// The 12 reversed cantrips, in
// the R341/R401 roster order.
inline const UcrCantrip& ucrReversed(int i) {
    static const UcrCantrip T[12] = {
        { "Curdle", 3, 0, 0 },
        { "Dirty", 0, 4, 4 },
        { "Dusty", 0, 5, 10 },
        { "Hairy", 2, 0, 0 },
        { "Knot", 2, 0, 0 },
        { "Ravel", 2, 3, 0 },
        { "Sour", 0, 0, 0 },
        { "Spill", 2, 6, 0 },
        { "Tangle", 2, 0, 0 },
        { "Tarnish", 2, 0, 0 },
        { "Untie", 2, 0, 0 },
        { "Wilt", 3, 0, 0 },
    };
    if (i < 0) i = 0;
    if (i > 11) i = 11;
    return T[i];
}

// The count.
inline int ucrReversedCount()
    { return 12; }

// The school census helper.
inline int ucrSchoolCount(int s)
{
    int n = 0;
    for (int i = 0; i < 12; ++i)
        if (ucrReversed(i).school == s)
            ++n;
    return n;
}

// The area kind census helper.
inline int ucrAreaKindCount(int a)
{
    int n = 0;
    for (int i = 0; i < 12; ++i)
        if (ucrReversed(i).areaKind == a)
            ++n;
    return n;
}

// The casting-time hole family:
// ALL 12 casting-time cells print
// fraction garbles in the scan -
// the whole family records as
// holes pending the PDF read (the
// R363/R412 posture). The Untie
// block prints "Casting time:"
// lowercase - the systematic OCR
// read, noted.
inline bool ucrCastTimesAreHoles()
    { return true; }

// ---- the mechanics pins ----

// The Hairy growth range: the
// subject material increases
// from 2 to 12 inches in length.
inline int ucrHairyGrowthMinIn()
    { return 2; }

inline int ucrHairyGrowthMaxIn()
    { return 12; }

// The Hairy short-material
// threshold: material under 1
// inch in length.
inline int ucrHairyShortUnderIn()
    { return 1; }

// The Hairy reversed read: the
// complete absence of growth for
// 2 to 12 days.
inline int ucrHairyAbsenceMinDays()
    { return 2; }

inline int ucrHairyAbsenceMaxDays()
    { return 12; }

// The Knot untie range: from 2
// to 8 rounds, minus the
// dexterity reaction bonus.
inline int ucrKnotUntieMinRounds()
    { return 2; }

inline int ucrKnotUntieMaxRounds()
    { return 8; }

// The Tangle untangle range: 3
// to 12 rounds unless roughly
// done.
inline int ucrTangleUntangleMinRounds()
    { return 3; }

inline int ucrTangleUntangleMaxRounds()
    { return 12; }

// The Sour vinegar max: about a
// pint appears over the subject.
inline int ucrSourMaxPints()
    { return 1; }

// The Spill container limit:
// containers of more than about
// gallon size are unaffected.
inline int ucrSpillMaxGallons()
    { return 1; }

// The Tarnish volume: the object
// must be about 1 cubic yard or
// less - the reverse of the R412
// shine volume (a live cross-
// check).
inline int ucrTarnishMaxCubicYds()
    { return 1; }

}   // namespace rules

