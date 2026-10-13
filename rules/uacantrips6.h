// ===========================================================================
// Adnd1 - rules/uacantrips6.h
// The UA MAGIC-USER CANTRIP
// DESCRIPTIONS, part 6 (R417):
// the HAUNTING-SOUND category
// (pp. 50-51), 8 cantrips - the
// LAST of the six MU cantrip
// description rounds. The
// R363/R412/R413/R414/R415/R416
// precedents ride: the
// descriptions pin; the
// casting-time fraction cells
// garble in the scan (the
// whole family) and record
// as holes pending the PDF
// read - never guesses.
//
// The school tags print clean:
// NO new school codes this
// round. The census: Evocation
// 3 (Creak, Tap, Whistle),
// Illusion 5 (Footfall, Groan,
// Moan, Rattle, Thump).
//
// The area lines print clean
// for ALL 8 blocks - ZERO area
// holes: the Special seven and
// the Tap 1 sq. ft. (a NEW area
// kind code).
//
// The range family: five
// blocks print the numerals
// clean (the near 1, the
// footfall far 2) but the
// foot/inch glyphs garble -
// the numerals pin, the unit
// family records as holes
// pending the PDF read. The
// creak traverse prints an
// ambiguous "1 0" - the value
// records as a hole (never a
// guess). The whistle pair
// prints CLEAN: the faint 10
// feet and the loud 30 feet pin
// with the loud == faint*3
// derivation.
//
// The mechanics pin clean: the
// creak latter half segment
// (the former 1/3 garbles - a
// hole), the moan two flavors,
// the rattle 2 seconds, the tap
// once/twice/thrice 1..3 band,
// and the whistle pair.

#pragma once

namespace rules {

// The school codes (NO new
// codes this round; Evocation
// and Illusion ride the
// standing codes).
const int UCH_EVO = 0;
const int UCH_ILL = 4;

// The area kind codes (the one
// square foot NEW this round;
// the Special rides the
// R412/R413 kind).
const int UCH_AREA_HOLE = -1;
const int UCH_AREA_SPECIAL = 3;
const int UCH_AREA_SQFT = 13;

// One haunting-sound cantrip:
// the name, the school, the
// area kind and the area value
// (0 when the kind carries no
// number).
struct UchCantrip {
    const char* name;
    int school;
    int areaKind;
    int areaVal;
};

// The 8 haunting-sound
// cantrips, in the R341/R401
// roster order.
inline const UchCantrip& uchHauntingSound(int i) {
    static const UchCantrip T[8] = {
        { "Creak", 0, 3, 0 },
        { "Footfall", 4, 3, 0 },
        { "Groan", 4, 3, 0 },
        { "Moan", 4, 3, 0 },
        { "Rattle", 4, 3, 0 },
        { "Tap", 0, 13, 1 },
        { "Thump", 4, 3, 0 },
        { "Whistle", 0, 3, 0 },
    };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return T[i];
}

// The count.
inline int uchHauntingSoundCount()
    { return 8; }

// The school census helper.
inline int uchSchoolCount(int s)
{
    int n = 0;
    for (int i = 0; i < 8; ++i)
        if (uchHauntingSound(i).school == s)
            ++n;
    return n;
}

// The area kind census helper.
inline int uchAreaKindCount(int a)
{
    int n = 0;
    for (int i = 0; i < 8; ++i)
        if (uchHauntingSound(i).areaKind == a)
            ++n;
    return n;
}

// The casting times: the
// PDF read resolves the
// whole family (R419) - the
// real UA PDF prints every
// cell clean, a unit
// fraction, one segment
// over the denominator. The
// denominators, in roster
// order:
// order: Creak, Footfall,
// Groan, Tap and Whistle at
// 1/6, Moan, Rattle and
// Thump at 1/10 - the 1/6
// lands inside the 2..10
// band the p. 45 header
// prints.
inline int uchCastTimeDen(int i)
{
    static const int D[8] = {
        6, 6, 6, 10, 10, 6, 10, 6 };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return D[i];
}

// The casting-time
// denominator census helper.
inline int uchCastTimeDenCount(int d)
{
    int n = 0;
    for (int i = 0; i < 8; ++i)
        if (uchCastTimeDen(i) == d)
            ++n;
    return n;
}

// The range units: the PDF read
// resolves the glyphs (R419) - the
// ranged blocks print the
// AD&D 1" notation (one inch of
// range, the ten-foot indoor
// scale). The unit pins as inch;
// the numerals ride the
// standing uchRangeNearVal() and
// uchFootfallFarVal() pins.
inline bool uchRangeUnitIsInch()
    { return true; }

// The near range numeral (the
// groan, rattle, tap and thump
// blocks all print 1).
inline int uchRangeNearVal()
    { return 1; }

// The footfall far numeral (the
// footfalls may move away up to
// 2).
inline int uchFootfallFarVal()
    { return 2; }

// ---- the mechanics pins ----

// The creak read (the PDF read
// resolves the garble - R419):
// the former sound (corroded-
// hinge door) lasts 1/3
// segment (the denominator
// 3); the latter noise
// (squeaking floorboards) lasts
// half a segment (in halves).
inline int uchCreakFormerDen()
    { return 3; }

inline int uchCreakLatterHalfSegs()
    { return 1; }

// The creak traverse: the PDF
// read resolves the ambiguity
// (R419) - the latter noise
// seems to traverse up to 10
// feet distance.
inline int uchCreakTraverseFeet()
    { return 10; }

// The moan read: the sound is
// either a low-pitched haunting
// moan or a high-pitched
// pitiful one - two flavors.
inline int uchMoanFlavors()
    { return 2; }

// The rattle read: the chain
// rattle lasts for up to 2
// seconds.
inline int uchRattleSeconds()
    { return 2; }

// The tap read: the sound occurs
// once, twice, or thrice,
// according to the number of
// fingers extended by the
// caster.
inline int uchTapCountMin()
    { return 1; }

inline int uchTapCountMax()
    { return 3; }

// The whistle read: a faint
// whistling can be heard within
// 10 feet, a loud one within 30
// feet (the pair prints clean).
inline int uchWhistleFaintFeet()
    { return 10; }

inline int uchWhistleLoudFeet()
    { return 30; }

}   // namespace rules

