// ===========================================================================
// Adnd1 - rules/uacantrips4.h
// The UA MAGIC-USER CANTRIP
// DESCRIPTIONS, part 4 (R415):
// the PERSON-AFFECTING
// category (p. 49), 10
// cantrips. The R363/R412/
// R413/R414 precedents ride:
// the descriptions pin; the
// casting-time fraction cells
// garble in the scan (the
// whole family) and record
// as holes pending the PDF
// read - never guesses.
//
// The school tags print clean
// except two reads: the scan
// prints "TVvitch" for the
// roster's Twitch (the name
// resolves via the LIVE
// R341/R401 roster cross-check
// - the roster is the
// independent confirmation),
// and Giggle prints "(Charm)"
// while Wink prints
// "(Enchantment)" in the SAME
// section - the print
// distinguishes the two, so
// Charm pins AS PRINTED (a
// NEW school code; the
// never-guess doctrine). The
// census: Evocation 8,
// Enchantment 1 (Wink),
// Charm 1 (Giggle).
//
// The area lines print clean
// for ALL 10 blocks - ZERO
// area holes: the one-person
// six (Belch, Blink, Cough,
// Giggle, Nod, Wink - a NEW
// area kind code) and the
// one-creature four (Scratch,
// Sneeze, Twitch, Yawn - a
// NEW area kind code).
//
// The mechanics pin clean: the
// Blink half-second momentary
// read, the Cough 1-3 second
// spasms, the Giggle 2-3
// second chuckle, the Scratch
// one-second itch relief, and
// the YAWN SLEEP
// SUSCEPTIBILITY - the window
// (the balance of the cast
// round + the whole following
// round), the 1 additional
// vulnerable creature, the 4
// or fewer HD band, the 4+1 to
// 4+4 re-roll band, the up-to
// 5+2 HD reach, and the 50%
// unaffected chance.

#pragma once

namespace rules {

// The school codes (Charm NEW
// this round, pinned AS
// PRINTED).
const int UCP_EVO = 0;
const int UCP_ABJ = 1;
const int UCP_ALT = 2;
const int UCP_ENCH = 3;
const int UCP_ILL = 4;
const int UCP_CHARM = 5;

// The area kind codes (one
// person and one creature NEW
// this round).
const int UCP_AREA_HOLE = -1;
const int UCP_AREA_PERSON = 8;
const int UCP_AREA_CREATURE = 9;

// One person-affecting
// cantrip: the name, the
// school, the area kind and
// the area value (0 when the
// kind carries no number).
struct UcpCantrip {
    const char* name;
    int school;
    int areaKind;
    int areaVal;
};

// The 10 person-affecting
// cantrips, in the R341/R401
// roster order.
inline const UcpCantrip& ucpPersonAffecting(int i) {
    static const UcpCantrip T[10] = {
        { "Belch", 0, 8, 0 },
        { "Blink", 0, 8, 0 },
        { "Cough", 0, 8, 0 },
        { "Giggle", 5, 8, 0 },
        { "Nod", 0, 8, 0 },
        { "Scratch", 0, 9, 0 },
        { "Sneeze", 0, 9, 0 },
        { "Twitch", 0, 9, 0 },
        { "Wink", 3, 8, 0 },
        { "Yawn", 0, 9, 0 },
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return T[i];
}

// The count.
inline int ucpPersonAffectingCount()
    { return 10; }

// The school census helper.
inline int ucpSchoolCount(int s)
{
    int n = 0;
    for (int i = 0; i < 10; ++i)
        if (ucpPersonAffecting(i).school == s)
            ++n;
    return n;
}

// The area kind census helper.
inline int ucpAreaKindCount(int a)
{
    int n = 0;
    for (int i = 0; i < 10; ++i)
        if (ucpPersonAffecting(i).areaKind == a)
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
// order: Sneeze at 1/2,
// Cough, Giggle and Twitch
// at 1/3, Scratch and Yawn
// at 1/8, Belch, Blink, Nod
// and Wink at 1/10.
inline int ucpCastTimeDen(int i)
{
    static const int D[10] = {
        10, 10, 3, 3, 10, 8, 2, 3, 10, 8 };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return D[i];
}

// The casting-time
// denominator census helper.
inline int ucpCastTimeDenCount(int d)
{
    int n = 0;
    for (int i = 0; i < 10; ++i)
        if (ucpCastTimeDen(i) == d)
            ++n;
    return n;
}

// ---- the mechanics pins ----

// The Blink read: momentary,
// lasting no more than half a
// second (in halves).
inline int ucpBlinkDurationHalfSecs()
    { return 1; }

// The Cough spasms: from 1 to
// 3 seconds on a failed save.
inline int ucpCoughMinSeconds()
    { return 1; }

inline int ucpCoughMaxSeconds()
    { return 3; }

// The Giggle chuckle: about 2
// or 3 seconds on a failed
// save.
inline int ucpGiggleMinSeconds()
    { return 2; }

inline int ucpGiggleMaxSeconds()
    { return 3; }

// The Scratch relief: the
// scratching takes but a
// second and the itch ceases.
inline int ucpScratchSeconds()
    { return 1; }

// ---- the yawn sleep
// susceptibility ----

// The window: the balance of
// the round in which the yawn
// was cast, plus the whole of
// the following round (the
// span covers 2 rounds).
inline int ucpYawnWindowRounds()
    { return 2; }

// The extra vulnerable: 1
// additional creature of 4 or
// fewer hit dice may be
// affected by the sleep spell.
inline int ucpYawnExtraVulnerable()
    { return 1; }

// The low band: creatures of
// 4 or fewer hit dice (the
// sleep spell norm).
inline int ucpYawnSleepHdLow()
    { return 4; }

// The re-roll band: creatures
// of 4+1 to 4+4 hit dice gain
// a chance to be affected
// (encoded lo*10+plus: 41..44).
inline int ucpYawnSleepBandLo()
    { return 41; }

inline int ucpYawnSleepBandHi()
    { return 44; }

// The reach: even a creature
// of up to 5+2 hit dice can
// be affected (encoded 52),
// rolled as if in the band.
inline int ucpYawnSleepHdMax()
    { return 52; }

// The unaffected chance: the
// over-band creature has a
// 50% chance of NOT being
// affected.
inline int ucpYawnUnaffectedPct()
    { return 50; }

}   // namespace rules

