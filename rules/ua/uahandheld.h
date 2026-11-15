// ===========================================================================
// Adnd1 - rules/ua/uahandheld.h
// The UA HAND HELD WEAPON TYPES, GENERAL DATA, AND "TO HIT"
// ADJUSTMENTS table (p. 27) pins (R392).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs:
//   - the roster: 60 rows in the printed order - the R392 clean
//     PDF read, every cell legible, no holes, no attributions.
//   - the n/a cells (the atlatl, blowgun and caltrop rows) pin
//     -1 in the numeric columns, "n/a" in the string columns.
//   - the half-foot glyphs (c. 1 1/2' and the like) normalize to
//     ASCII; the foot and inch marks print straight.
//   - the aklys speed factor prints "4 (+ 1)" - the 4 pins, the
//     +1 bonus rides uahhAklysSpeedBonus.
//   - the Spear and Trident speed factors print the range 6-8,
//     the Whip 5-8 - the min/max accessors carry the ranges.
//   - the footnotes: * = the set-double note (the spetum, the
//     bastard sword), ** = the dismount note (eight rows) -
//     uahhSetDoubleFlag/uahhDismountFlag; the general note: +2
//     vs the back, +4 vs stunned, prone and motionless.
// ===========================================================================

#pragma once

// R1058 applied
#include "rules/seams/weaponsreg.h"

namespace rules {

// The row count (60).
inline int uahhRowCount()
    { return 60; }

// The row name (printed).
inline const char* uahhName(int i) {
    const auto& rows = wRows("uahh");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The length (printed; "n/a" = the not-applicable rows).
inline const char* uahhLength(int i) {
    const auto& rows = wRows("uahh_length");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The space required (printed; "n/a" = the caltrop).
inline const char* uahhSpaceRequired(int i) {
    const auto& rows = wRows("uahh_space");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The speed factor minimum; -1 = the n/a rows (the atlatl,
// the blowgun, the caltrop).
inline int uahhSpeedFactorMin(int i) {
    const auto* g = wTable(
        "uahh", "speed_min");
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    if (!g) return 4;
    return (int)(*g)[i];
}

// The speed factor maximum (the Spear and Trident print the
// range 6-8, the Whip 5-8).
inline int uahhSpeedFactorMax(int i) {
    const auto* g = wTable(
        "uahh", "speed_max");
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    if (!g) return 4;
    return (int)(*g)[i];
}

// The aklys speed-factor bonus (the print "4 (+ 1)").
inline int uahhAklysSpeedBonus()
    { return 1; }

// The AC adjustment by AC 0..10 (the full printed ladder).
inline int uahhAcAdjustment(int i, int ac) {
    const auto* g = wTable(
        "uahh", "ac_adjustment");
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    if (ac < 0) ac = 0;
    if (ac > 10) ac = 10;
    if (!g) return -7;
    return (int)(*g)[(i) * 11
        + (ac)];
}

// True when the row carries the * footnote (set to receive
// a charge: double damage - the spetum, the bastard sword).
inline bool uahhSetDoubleFlag(int i) {
    const auto* g = wTable(
        "uahh", "set_double");
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    if (!g) return 0;
    return (int)(*g)[i];
}

// True when the row carries the ** footnote (the dismount
// capability - eight rows).
inline bool uahhDismountFlag(int i) {
    const auto* g = wTable(
        "uahh", "dismount");
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    if (!g) return 0;
    return (int)(*g)[i];
}

// The general note: any weapon strikes at +2 vs the back.
inline int uahhRearAttackBonus()
    { return 2; }

// The general note: +4 vs stunned, prone and motionless.
inline int uahhStunnedProneBonus()
    { return 4; }

// The * footnote: these weapons do twice the damage
// indicated to size L creatures when set (firmly grounded)
// to receive a charging opponent.
inline bool uahhNoteSetDoubleVsCharge()
    { return true; }

// The ** footnote: these weapons are capable of dismounting
// a rider on a score equal to or greater than the "to hit"
// score.
inline bool uahhNoteDismountOnHit()
    { return true; }

}   // namespace rules