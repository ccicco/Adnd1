// ===========================================================================
// Adnd1 - rules/uamoves.h
// The UA APPENDIX S MOVE values
// (pp. 110-120), R411: the 23
// deity block movement rates -
// the last numeric remainder in
// Appendix S (the pantheon prose
// alone stays open). The clean
// djvu scan carries all 23 lines;
// the systematic OCR reads
// resolve: the label colon dot
// ("MOVE;" reads "MOVE:"), the
// quote forms rendering as
// apostrophes, back-ticks and
// dashes (MOVE: 12', 18', 12-
// all read the printed inch
// mark; the parentheticals
// 48/24/36/36/12 are all
// multiples of 12.
//
// The hole: the Shargaas line
// garbles ("MOVE: 78-") with no
// independent confirmation - the
// value records as the hole
// sentinel, never a guess.
//
// The sanity ladders: every
// clean base is a multiple of 3;
// every printed alternate is a
// multiple of 12.

#pragma once

namespace rules {

// The Shargaas hole sentinel.
const int UMV_MOVE_HOLE = -1;

// One MOVE line: the base rate,
// the parenthetical alternate (0
// = the line prints no
// parenthetical) and the
// flight-only flag.
struct UmvMove {
    int base;
    int alt;
    bool flightOnly;
};

// The 23 MOVE lines, in the R406
// roster order.
inline const UmvMove& umvMove(int i) {
    static const UmvMove T[23] = {
        { 12, 0, false },
        { 18, 0, false },
        { 9, 48, false },
        { 12, 0, false },
        { 12, 0, false },
        { 48, 0, true },
        { 18, 0, false },
        { 15, 0, false },
        { 12, 0, false },
        { 12, 0, false },
        { 9, 24, false },
        { 12, 0, false },
        { 12, 0, false },
        { 12, 0, false },
        { 15, 0, false },
        { 12, 36, false },
        { 9, 36, false },
        { 6, 0, false },
        { 9, 0, false },
        { -1, 0, false },
        { 12, 0, false },
        { 6, 0, false },
        { 15, 12, false },
    };
    if (i < 0) i = 0;
    if (i > 22) i = 22;
    return T[i];
}

inline int umvMoveCount()
    { return 23; }

// The alternate census (the lines
// printing a parenthetical): 5 -
// Dumathoin 48, Sheela 24,
// Urdlen 36, Segojan 36,
// Luthic 12.
inline int umvAltCount() {
    int n = 0;
    for (int i = 0; i < 23; ++i)
        if (umvMove(i).alt > 0) ++n;
    return n;
}

// The base sum over the clean
// rows (the hole excluded): a
// drift in ANY clean base cell
// moves it.
inline int umvBaseSum() {
    int n = 0;
    for (int i = 0; i < 23; ++i) {
        const UmvMove& m = umvMove(i);
        if (m.base != UMV_MOVE_HOLE)
            n += m.base;
    }
    return n;
}

// True when every clean base is a
// multiple of 3 (the sanity
// ladder; the hole excluded).
inline bool umvBasesAreMultiplesOf3() {
    for (int i = 0; i < 23; ++i) {
        const UmvMove& m = umvMove(i);
        if (m.base == UMV_MOVE_HOLE)
            continue;
        if (m.base <= 0 || m.base % 3)
            return false;
    }
    return true;
}

// True when every printed
// alternate is a multiple of 12
// (the sanity ladder).
inline bool umvAltsAreMultiplesOf12() {
    for (int i = 0; i < 23; ++i) {
        const UmvMove& m = umvMove(i);
        if (m.alt > 0 && m.alt % 12)
            return false;
    }
    return true;
}

// The flight-only flag: the
// Aerdrie 48 reads flight only.
inline bool umvAerdrieFlightOnly()
    { return umvMove(5).flightOnly;
    }

}   // namespace rules

