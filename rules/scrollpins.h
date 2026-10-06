// ====================================================================
// Adnd1 - rules/scrollpins.h
// R222: the III.B scrolls prose pins
// (DMG pp.126-127) - the structure and
// prose of the III.B SCROLLS table:
//   - the 16 spell-scroll rows: dice
//     band, spell count, level range,
//     and the printed illusionist
//     alternative range (the or X-Y*
//     halves - the alt rows are the
//     17-19, 25-27, 33-35, 40-42,
//     47-49, 53-54 and 60 bands; the
//     alt lo equals the main lo and
//     the alt hi is lower).
//   - the 8 protection scroll rows
//     with their table-printed x.p.
//     values.
//   - the 8-row curse sub-table the
//     Curse** row sends the reader
//     to (DM discretion noted: these
//     are the SUGGESTED curses).
//   - the prose: 100 x.p. per spell
//     level, awarded only to
//     characters who can use the
//     spell; spell scrolls sell at
//     three times x.p. on the open
//     market, protection scrolls at
//     five times; the DM must do his
//     utmost to convince players a
//     cursed scroll should be read
//     (duplicity, coercion and
//     threat); an unread scroll has
//     a chance of fading in normal
//     air; a curse takes effect
//     immediately.
// JUDGMENTS, named in place:
//   - The alt ranges are pinned as
//     data even though the engine
//     roller reads only the main
//     range; the print gives no
//     dice split for which half a
//     found scroll uses.
//   - The curse transports move the
//     reader AND all within 20 feet;
//     the 200-1,200 miles band is
//     pinned as min/max.
// Pure data + helpers, header-only
// (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

// -----------------------------------------------------------------------
// The spell-scroll rows (dice bands 01-60).
// -----------------------------------------------------------------------
inline int scrollSpellRowCount() {
    return 16;
}

inline int scrollSpellRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        1, 11, 17, 20, 25, 28, 33, 36, 40, 43,
        47, 50, 53, 55, 58, 60,
    };
    return t[i];
}

inline int scrollSpellRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        10, 16, 19, 24, 27, 32, 35, 39, 42, 46,
        49, 52, 54, 57, 59, 60,
    };
    return t[i];
}

inline int scrollSpellRowN(int i) {
    // the spells on the scroll; i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        1, 1, 1, 2, 2, 3, 3, 4, 4, 5,
        5, 6, 6, 7, 7, 7,
    };
    return t[i];
}

inline int scrollSpellRowLvLo(int i) {
    // the main level range lower edge; i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        1, 1, 2, 1, 1, 1, 2, 1, 1, 1,
        1, 1, 3, 1, 2, 4,
    };
    return t[i];
}

inline int scrollSpellRowLvHi(int i) {
    // the main level range upper edge; i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        4, 6, 9, 4, 8, 4, 9, 6, 8, 6,
        8, 6, 8, 8, 9, 9,
    };
    return t[i];
}

inline int scrollSpellRowHasAlt(int i) {
    // 1 when the print gives an
    // illusionist alternative range
    // (the or X-Y* halves); i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        0, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        1, 0, 1, 0, 0, 1,
    };
    return t[i];
}

inline int scrollSpellRowAltLvLo(int i) {
    // the alt range lower edge (equals
    // the main lo on every alt row);
    // i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        0, 0, 2, 0, 1, 0, 2, 0, 1, 0,
        1, 0, 3, 0, 0, 4,
    };
    return t[i];
}

inline int scrollSpellRowAltLvHi(int i) {
    // the alt range upper edge (lower
    // than the main hi on every alt
    // row); i clamps
    if (i < 0) i = 0;
    if (i > 15) i = 15;
    static const int t[16] = {
        0, 0, 7, 0, 6, 0, 7, 0, 6, 0,
        6, 0, 6, 0, 0, 7,
    };
    return t[i];
}

inline int scrollSpellAltRangeCount() {
    // the 17-19, 25-27, 33-35, 40-42,
    // 47-49, 53-54 and 60 bands
    return 7;
}

inline int scrollProtRowCount() {
    // the protection scrolls (61-97)
    return 8;
}

inline int scrollProtRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        61, 63, 65, 71, 77, 83, 88, 93,
    };
    return t[i];
}

inline int scrollProtRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        62, 64, 70, 76, 82, 87, 92, 97,
    };
    return t[i];
}

inline int scrollProtRowXp(int i) {
    // the table-printed x.p. values;
    // i clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        2500, 2500, 1500, 1000, 1500, 2000, 2000, 1500,
    };
    return t[i];
}

// -----------------------------------------------------------------------
// The curse sub-table (the Curse** row).
// -----------------------------------------------------------------------
inline int scrollCurseRowCount() {
    return 8;
}

inline int scrollCurseRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        1, 26, 31, 41, 51, 76, 91, 100,
    };
    return t[i];
}

inline int scrollCurseRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        25, 30, 40, 50, 75, 90, 99, 100,
    };
    return t[i];
}

// -----------------------------------------------------------------------
// The prose constants.
// -----------------------------------------------------------------------
inline int scrollSpellXpPerLevel() {
    // awarded only to characters who can
    // use the spell(s)
    return 100;
}

inline int scrollSpellSaleMultiplier() {
    // the open market pays three times
    // the x.p. value
    return 3;
}

inline int scrollProtectionSaleMultiplier() {
    // protection scrolls sell at five
    // times the x.p. value
    return 5;
}

inline int scrollDmMustConvinceRead() {
    // duplicity, coercion and threat:
    // the DM must do his utmost to
    // convince players a cursed scroll
    // should be read
    return 1;
}

inline int scrollUnreadMayFade() {
    // a scroll not read has a chance of
    // fading in normal air; the archaic
    // wording notes it if read in the
    // still dungeon atmosphere
    return 1;
}

inline int scrollCurseTakesEffectImmediately() {
    return 1;
}

inline int scrollCurseDiseaseOnsetMin() {
    // fatal to the reader in 2-8 turns
    // unless cured
    return 2;
}

inline int scrollCurseDiseaseOnsetMax() {
    return 8;
}

inline int scrollCurseTransportMinMiles() {
    // rows 31-40: 200 to 1,200 miles in
    // a random direction
    return 200;
}

inline int scrollCurseTransportMaxMiles() {
    return 1200;
}

inline int scrollCurseTransportRadius() {
    // rows 31-50 move the reader AND all
    // within 20 feet
    return 20;
}

inline int scrollCurseRandomSpellLevel() {
    // row 00: a randomly rolled spell
    // affects the reader at the 12th
    // level of magic-use
    return 12;
}

}  // namespace rules

