// ===========================================================================
// Adnd1 - rules/uacantrips3.h
// The UA MAGIC-USER CANTRIP
// DESCRIPTIONS, part 3 (R414):
// the LEGERDEMAIN category
// (pp. 48-49), 6 cantrips. The
// R363/R412/R413 precedents
// ride: the descriptions pin;
// the casting-time fraction
// cells garble in the scan (the
// whole family) and record as
// holes pending the PDF read -
// never guesses.
//
// The school tags print clean:
// Alteration 3 (Change, Mute,
// Present), Enchantment 1
// (Distract), Illusion 2 (Hide,
// Palm), Evocation 0,
// Abjuration 0 - Illusion a NEW
// school code this round.
//
// The area lines print clean
// for ALL 6 blocks - ZERO area
// holes: the one-object three
// (Change, Hide, Mute), the
// Distract Special, the Palm/
// Present one small item pair
// (a NEW area kind code).
//
// The mechanics pin clean: the
// Change 50% size band with
// the base 1 turn, the radical
// 1 round and the slight 1+
// day durations, the Distract
// 10-foot range + 1 segment
// duration, the Hide duration
// ladder (the base 1 turn at
// 2 cubic yards or less,
// minus 1 round per additional
// 2 cubic yards to the 1-round
// floor at 20, then minus 1
// segment per 2 additional
// cubic yards from the 9
// segments at 22 down to 1
// segment at 38, over 38
// momentary - the ladder
// cross-checks by derivation:
// 22 + 2*8 = 38 and 9 - 8 = 1),
// the Mute 1 round, the Palm 1
// segment, the Present 2-foot
// radius + the dozen-coin
// capacity + the tankard
// exhaustion.

#pragma once

namespace rules {

// The school codes (Illusion
// NEW this round).
const int UCL_EVO = 0;
const int UCL_ABJ = 1;
const int UCL_ALT = 2;
const int UCL_ENCH = 3;
const int UCL_ILL = 4;

// The area kind codes (one
// small item NEW this round).
const int UCL_AREA_HOLE = -1;
const int UCL_AREA_OBJECT = 0;
const int UCL_AREA_SPECIAL = 3;
const int UCL_AREA_SMALLITEM = 7;

// One legerdemain cantrip:
// the name, the school, the
// area kind and the area value
// (0 when the kind carries no
// number).
struct UclCantrip {
    const char* name;
    int school;
    int areaKind;
    int areaVal;
};

// The 6 legerdemain cantrips,
// in the R341/R401 roster
// order.
inline const UclCantrip& uclLegerdemain(int i) {
    static const UclCantrip T[6] = {
        { "Change", 2, 0, 0 },
        { "Distract", 3, 3, 0 },
        { "Hide", 4, 0, 0 },
        { "Mute", 2, 0, 0 },
        { "Palm", 4, 7, 0 },
        { "Present", 2, 7, 0 },
    };
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return T[i];
}

// The count.
inline int uclLegerdemainCount()
    { return 6; }

// The school census helper.
inline int uclSchoolCount(int s)
{
    int n = 0;
    for (int i = 0; i < 6; ++i)
        if (uclLegerdemain(i).school == s)
            ++n;
    return n;
}

// The area kind census helper.
inline int uclAreaKindCount(int a)
{
    int n = 0;
    for (int i = 0; i < 6; ++i)
        if (uclLegerdemain(i).areaKind == a)
            ++n;
    return n;
}

// The casting times: the
// PDF read resolves the
// whole family (R418) - the
// real UA PDF prints every
// cell clean, a unit
// fraction, one segment
// over the denominator. The
// denominators, in roster
// order: Change, Hide,
// Mute and Palm at 1/10,
// Distract at 1/3, Present
// at 1/8.
inline int uclCastTimeDen(int i)
{
    static const int D[6] = {
        10, 3, 10, 10, 10, 8 };
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return D[i];
}

// The casting-time
// denominator census helper.
inline int uclCastTimeDenCount(int d)
{
    int n = 0;
    for (int i = 0; i < 6; ++i)
        if (uclCastTimeDen(i) == d)
            ++n;
    return n;
}

// ---- the mechanics pins ----

// The Change size band: no more
// than a 50% increase or
// decrease in size/volume.
inline int uclChangeSizePctMax()
    { return 50; }

// The Change base duration: 1
// turn.
inline int uclChangeBaseTurns()
    { return 1; }

// The Change radical duration:
// a radical change lasts only
// 1 round.
inline int uclChangeRadicalRounds()
    { return 1; }

// The Change slight duration: a
// very slight alteration lasts
// 1 or more days.
inline int uclChangeSlightDays()
    { return 1; }

// The Distract range: the
// distraction must be within
// 10 feet of the caster.
inline int uclDistractRangeFt()
    { return 10; }

// The Distract duration: only
// 1 segment.
inline int uclDistractDurationSegments()
    { return 1; }

// The Hide ladder base: 1 turn
// on an object of 2 cubic yards
// or less in volume.
inline int uclHideBaseCubicYds()
    { return 2; }

inline int uclHideBaseTurns()
    { return 1; }

// The Hide ladder round floor:
// reduced by 1 round per
// additional 2 cubic yards
// until, at 20 cubic yards,
// the duration is 1 round.
inline int uclHideRoundCubicYds()
    { return 20; }

// The Hide ladder segment tail:
// over 20 cubic yards the
// duration drops 1 segment per
// 2 additional cubic yards - 9
// segments at 22 cubic yards.
inline int uclHideSegStartCubicYds()
    { return 22; }

inline int uclHideSegStartSegments()
    { return 9; }

// The Hide ladder segment step:
// 2 cubic yards per segment.
inline int uclHideSegStepCubicYds()
    { return 2; }

// The Hide ladder floor: 1
// segment at 38 cubic yards;
// anything over 38 at best
// momentarily disappears.
inline int uclHideMinCubicYds()
    { return 38; }

inline int uclHideMinSegments()
    { return 1; }

// The Mute duration: but
// 1 round.
inline int uclMuteDurationRounds()
    { return 1; }

// The Palm duration: the
// illusory duplicate lasts but
// 1 segment.
inline int uclPalmDurationSegments()
    { return 1; }

// The Present radius: within
// 2 feet of the caster.
inline int uclPresentRadiusFt()
    { return 2; }

// The Present capacity: as many
// as a dozen coins before the
// dweomer fails (a tankard
// exhausts it).
inline int uclPresentMaxCoins()
    { return 12; }

}   // namespace rules

