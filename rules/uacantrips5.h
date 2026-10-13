// ===========================================================================
// Adnd1 - rules/uacantrips5.h
// The UA MAGIC-USER CANTRIP
// DESCRIPTIONS, part 5 (R416):
// the PERSONAL category
// (pp. 49-50), 10 cantrips.
// The R363/R412/R413/R414/R415
// precedents ride: the
// descriptions pin; the
// casting-time fraction cells
// garble in the scan (the
// whole family) and record
// as holes pending the PDF
// read - never guesses.
//
// The school tags print clean:
// Summoning and Conjuration
// are NEW school codes this
// round, pinned AS PRINTED.
// The census: Summoning 5
// (Bee, Bug, Gnats, Mouse,
// Spider), Conjuration 3
// (Bluelight, Tweak, Unlock),
// Alteration 1 (Firefinger),
// Evocation 1 (Smokepuff).
// The scan prints "Flrefinger"
// for the roster's Firefinger -
// the name resolves via the
// LIVE R341/R401 roster
// cross-check (the roster is
// the independent
// confirmation).
//
// The area lines: EIGHT print
// clean - the one-summoned-
// animal four (Bee, Bug,
// Mouse, Spider - a NEW area
// kind), the Gnats 1 cubic
// foot, the Smokepuff 1-foot
// cloud (a NEW area kind), the
// Tweak one creature (the
// R415 kind), the Unlock one
// lock (a NEW area kind) - and
// TWO garble their numbers
// (the Bluelight sphere
// diameter and the Firefinger
// line length): the two record
// as area holes pending the
// PDF read.
//
// The range family: the seven
// ranged blocks (Bee, Bug,
// Gnats, Mouse, Smokepuff,
// Spider, Tweak) print the
// numeral 1 clean but the
// foot/inch glyphs garble -
// the numeral pins, the unit
// family records as holes
// pending the PDF read.
//
// The mechanics pin clean: the
// Bee 90% sting, the Bluelight
// 3-inch sphere + 5-foot
// illumination, the Firefinger
// one-half-foot jet + 1
// segment persistence, the
// Gnats 1-4 segment distraction,
// the Smokepuff six colors, the
// SPIDER POISON READ (the 5%
// the 1-2 inch size, the
// 1-segment bite distraction,
// the +4 venom save, the 1/2
// damage pair, the 1-4 day
// sickness; the slow-poison
// defer prints a garbled
// numeral and records as a
// hole), the Tweak seven
// portions + 1-segment
// distraction + the INT 7
// threshold + the 3d6 read.

#pragma once

namespace rules {

// The school codes (Summoning
// and Conjuration NEW this
// round, pinned AS PRINTED).
const int UCO_EVO = 0;
const int UCO_ABJ = 1;
const int UCO_ALT = 2;
const int UCO_ENCH = 3;
const int UCO_ILL = 4;
const int UCO_CHARM = 5;
const int UCO_SUMM = 6;
const int UCO_CONJ = 7;

// The area kind codes (the one
// summoned animal, the 1-foot
// cloud and the one lock NEW
// this round; the cubic foot
// rides the R412 kind and the
// one creature the R415 kind).
const int UCO_AREA_HOLE = -1;
const int UCO_AREA_CUBEFoot = 1;
const int UCO_AREA_CREATURE = 9;
const int UCO_AREA_BEAST = 10;
const int UCO_AREA_CLOUD = 11;
const int UCO_AREA_LOCK = 12;
// The sphere and the line NEW
// this round (R419 - the PDF
// read resolves the two area
// holes).
const int UCO_AREA_SPHERE = 13;
const int UCO_AREA_LINE = 14;

// One personal cantrip: the
// name, the school, the area
// kind and the area value (0
// when the kind carries no
// number).
struct UcoCantrip {
    const char* name;
    int school;
    int areaKind;
    int areaVal;
};

// The 10 personal cantrips, in
// the R341/R401 roster order.
inline const UcoCantrip& ucoPersonal(int i) {
    static const UcoCantrip T[10] = {
        { "Bee", 6, 10, 0 },
        { "Bluelight", 7,
            UCO_AREA_SPHERE, 3 },
        { "Bug", 6, 10, 0 },
        { "Firefinger", 2,
            UCO_AREA_LINE, 6 },
        { "Gnats", 6, 1, 1 },
        { "Mouse", 6, 10, 0 },
        { "Smokepuff", 0, 11, 1 },
        { "Spider", 6, 10, 0 },
        { "Tweak", 7, 9, 0 },
        { "Unlock", 7, 12, 0 },
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return T[i];
}

// The count.
inline int ucoPersonalCount()
    { return 10; }

// The school census helper.
inline int ucoSchoolCount(int s)
{
    int n = 0;
    for (int i = 0; i < 10; ++i)
        if (ucoPersonal(i).school == s)
            ++n;
    return n;
}

// The area kind census helper.
inline int ucoAreaKindCount(int a)
{
    int n = 0;
    for (int i = 0; i < 10; ++i)
        if (ucoPersonal(i).areaKind == a)
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
// order: Bee, Bluelight,
// Bug, Gnats, Mouse, Spider
// and Unlock at 1/2,
// Firefinger, Smokepuff and
// Tweak at 1/3.
inline int ucoCastTimeDen(int i)
{
    static const int D[10] = {
        2, 2, 2, 3, 2, 2, 3, 2, 3, 2 };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return D[i];
}

// The casting-time
// denominator census helper.
inline int ucoCastTimeDenCount(int d)
{
    int n = 0;
    for (int i = 0; i < 10; ++i)
        if (ucoCastTimeDen(i) == d)
            ++n;
    return n;
}

// The range units: the PDF read
// resolves the glyphs (R419) - the
// seven ranged blocks print the
// AD&D 1" notation (one inch of
// range, the ten-foot indoor
// scale). The unit pins as inch;
// the numeral 1 rides the
// standing ucoRangeVal() pin.
inline bool ucoRangeUnitIsInch()
    { return true; }

// The range numeral (the seven
// ranged blocks all print 1).
inline int ucoRangeVal()
    { return 1; }

// ---- the mechanics pins ----

// The Bee read: the bee is 90%
// likely to sting any living
// creature it finds itself
// upon.
inline int ucoBeeStingPct()
    { return 90; }

// The Bluelight read: the
// 3-inch sphere of glowing blue
// radiance illuminates an area
// of 5 feet around itself (and
// casts no reflections beyond
// that radius; infravision and
// ultravision unaffected).
inline int ucoBluelightSphereInches()
    { return 3; }

inline int ucoBluelightRadiusFeet()
    { return 5; }

// The Firefinger read: a jet of
// flame up to one-half foot in
// length (6 inches) that
// persists for up to 1 segment.
inline int ucoFirefingerJetInches()
    { return 6; }

inline int ucoFirefingerSegments()
    { return 1; }

// The Gnats read: on a failed
// save versus poison the cloud
// distracts for from 1 to 4
// segments.
inline int ucoGnatsDistractMinSegments()
    { return 1; }

inline int ucoGnatsDistractMaxSegments()
    { return 4; }

// The Smokepuff read: the puff
// can be white, gray, black,
// brown, yellow, or green -
// six colors.
inline int ucoSmokepuffColors()
    { return 6; }

// ---- the spider poison read ----

// The venom chance: a 5% chance
// the summoned spider is one
// with powerful poison (black
// widow, brown recluse, etc.).
inline int ucoSpiderPoisonPct()
    { return 5; }

// The size: a common garden
// spider or the like, no
// larger than an inch or two
// in diameter.
inline int ucoSpiderSizeMaxInches()
    { return 2; }

// The normal bite: a
// momentary distraction of 1
// segment.
inline int ucoSpiderBiteDistractSegments()
    { return 1; }

// The venom save: versus poison
// at +4.
inline int ucoSpiderPoisonSaveBonus()
    { return 4; }

// The damage pair: success on
// the save inflicts 1 point,
// failure 2 points.
inline int ucoSpiderHitLight()
    { return 1; }

inline int ucoSpiderHitHeavy()
    { return 2; }

// The sickness: on the failed
// venom save the victim cannot
// act normally for from 1 to 4
// days unless neutralize poison
// removes the toxin.
inline int ucoSpiderSickMinDays()
    { return 1; }

inline int ucoSpiderSickMaxDays()
    { return 4; }

// The slow poison defer: the PDF
// read resolves the garble (R419)
// - a slow poison defers the
// sickness for 1 day.
inline int ucoSlowPoisonDeferDays()
    { return 1; }

// ---- the tweak read ----

// The portions: cheek, nose,
// ear, beard, moustache,
// whiskers, or tail - seven.
inline int ucoTweakPortions()
    { return 7; }

// The distraction: a 1-segment
// distraction on the failed
// save/roll.
inline int ucoTweakDistractSegments()
    { return 1; }

// The INT threshold: creatures
// with intelligence under 7
// save versus spell; creatures
// with intelligence of 7 or
// greater must roll greater
// than intelligence on 3d6.
inline int ucoTweakIntThreshold()
    { return 7; }

inline int ucoTweakDice()
    { return 3; }

}   // namespace rules

