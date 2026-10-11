// ===========================================================================
// Adnd1 - rules/uaprof.h
// The UA WEAPON PROFICIENCY TABLE (p. 26) pins (R339).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The R297 PHB pin (rules/weaponprof.h) is the decode seam.
//
// JUDGMENTs:
//   - the roster: 14 rows in the printed order. Seven rows match
//     the PHB rows cell for cell (cleric, druid, fighter,
//     magic-user, illusionist, thief, monk) - every readable cell
//     seam-verifies against R297, proving the OCR patterns row by
//     row. The UA-new rows: cavalier, barbarian, acrobat, bard
//     (no PHB row).
//   - the minus-loss decode: unsigned penalty magnitudes print
//     where the PHB prints -2/-3 (the fighter 2, the monk 3) -
//     the R297 magnitude convention, sign carried by the
//     convention not the print. The barbarian prints -1 signed.
//   - the cadence cells print "1/4 levels" style; the cavalier
//     and paladin rows print "112 levels" - the slash-loss
//     decode to 1/2 levels (the barbarian and monk rows print
//     "1/2 levels" clean, proving the cadence in this table).
//   - the cavalier initial prints "3°" - the degree sign is an
//     OCR artifact on the digit; 3 pins.
//   - attributed rows: the post-MAGIC-USER nameless row (1, -5,
//     1/6) attributes to the Illusionist - the only roster
//     class otherwise absent in its printed place, cells matching
//     the R297 illusionist row. The "EF" row (2, -3, 1/4)
//     attributes to the Thief - the garbled name fragment, cells
//     matching the R297 thief row. The post-Acrobat fragment
//     row attributes to the Assassin - the only roster class
//     otherwise absent, sitting exactly at the PHB table's
//     assassin position. The fragment splits to FIVE cells
//     (one misaligned extra empty); the added column anchors
//     right (1/4 levels), and the 2 reads as the PENALTY cell -
//     the PHB-consistent read (an initial-cell read would
//     deviate from every other PHB-matching row in this table);
//     the initial prints lost, a hole.
//   - deviations from the PHB (pinned as printed, noted): the
//     ranger initial prints 8 where the PHB row reads 3 (the
//     R297 seam) - pinned as printed, the echo-of-the-barbarian
//     row doubt noted pending the PDF. The paladin penalty
//     prints 3 where the PHB reads 2, and the paladin cadence
//     prints 1/2 where the PHB reads 1/3 - the UA paladin rides
//     the cavalier group's values, pinned as printed.
//
// OCR holes (the item closes; these stay on the PDF ledger): the
// cavalier penalty cell (prints empty), the paladin initial cell
// (prints empty - the stacked-group reading would share the
// cavalier's 3, not pinned), the assassin initial cell (prints
// empty), and the ENTIRE facing-page notes (the print points at
// them: "(Notes to this table on facing page)" - the notes
// themselves are OCR-lost).
// ===========================================================================

#pragma once

namespace rules {

// The row count (14 = the 10 PHB classes plus the cavalier,
// barbarian, acrobat and bard).
inline int uapfRowCount()
    { return 14; }

// The row name (printed; the three attributed rows carry the
// attribution JUDGMENT - uapfNameIsAttributed flags them).
inline const char* uapfName(int i) {
    static const char* const k[14] = {
        "Cavalier", "Paladin", "Cleric", "Druid",
        "Fighter", "Barbarian", "Ranger", "Magic-User",
        "Illusionist", "Thief", "Acrobat", "Assassin",
        "Monk", "Bard"
    };
    if (i < 0) i = 0;
    if (i > 13) i = 13;
    return k[i];
}

// The R297 ProfRow each row seam-verifies against; -1 = a
// UA-new row (no PHB row). The acrobat seam-closes to the
// thief row's values by print (not by PHB membership).
inline int uapfPhbSeamRow(int i) {
    // cavalier, paladin, cleric, druid, fighter,
    // barbarian, ranger, magic-user, illusionist,
    // thief, acrobat, assassin, monk, bard
    static const int k[14] = {
        -1, 3, 0, 1, 2, -1, 4, 5, 6, 7, 7, 8, 9, -1
    };
    if (i < 0) i = 0;
    if (i > 13) i = 13;
    return k[i];
}

// True when the row name is an attribution (the printed name
// is OCR-lost or garbled; the data assigns the row).
inline bool uapfNameIsAttributed(int i) {
    // illusionist, thief, assassin
    static const bool k[14] = {
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0
    };
    if (i < 0) i = 0;
    if (i > 13) i = 13;
    return k[i];
}

// The initial number of weapons; -1 = the cell prints empty
// (a hole): the paladin and the assassin.
inline int uapfInitialSlots(int i) {
    static const int k[14] = {
        3, -1, 2, 2, 4, 8, 8, 1, 1, 2, 2, -1, 1, 5
    };
    if (i < 0) i = 0;
    if (i > 13) i = 13;
    return k[i];
}

// The non-proficiency to-hit penalty MAGNITUDE (the R297
// convention; the adjustment is negative). The cavalier cell
// prints empty - a hole, -1.
inline int uapfNonProfPenalty(int i) {
    static const int k[14] = {
        -1, 3, 3, 4, 2, 1, 2, 5, 5, 3, 3, 2, 3, 2
    };
    if (i < 0) i = 0;
    if (i > 13) i = 13;
    return k[i];
}

// The added-proficiency levels-per-slot (one new proficiency
// per N levels above the 1st, the R297 note).
inline int uapfAddedCadence(int i) {
    static const int k[14] = {
        2, 2, 4, 5, 3, 2, 3, 6, 6, 4, 4, 4, 2, 4
    };
    if (i < 0) i = 0;
    if (i > 13) i = 13;
    return k[i];
}

// The facing-page notes are wholly OCR-lost (the table's own
// caption points at them); their existence pins, their
// content does not.
inline bool uapfFacingPageNotesLost()
    { return true; }

}   // namespace rules