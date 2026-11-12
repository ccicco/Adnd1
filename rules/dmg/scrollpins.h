// ====================================================================
// Adnd1 - rules/dmg/scrollpins.h
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

// R-refactor: namespace rules -> class Scrollpins (instance methods)
class Scrollpins {
public:


// -----------------------------------------------------------------------
// The spell-scroll rows (dice bands 01-60).
// -----------------------------------------------------------------------
    int scrollSpellRowCount();
    int scrollSpellRowLo(int i);
    int scrollSpellRowHi(int i);
    int scrollSpellRowN(int i);
    int scrollSpellRowLvLo(int i);
    int scrollSpellRowLvHi(int i);
    int scrollSpellRowHasAlt(int i);
    int scrollSpellRowAltLvLo(int i);
    int scrollSpellRowAltLvHi(int i);
    int scrollSpellAltRangeCount();
    int scrollProtRowCount();
    int scrollProtRowLo(int i);
    int scrollProtRowHi(int i);
    int scrollProtRowXp(int i);


// -----------------------------------------------------------------------
// The curse sub-table (the Curse** row).
// -----------------------------------------------------------------------
    int scrollCurseRowCount();
    int scrollCurseRowLo(int i);
    int scrollCurseRowHi(int i);


// -----------------------------------------------------------------------
// The prose constants.
// -----------------------------------------------------------------------
    int scrollSpellXpPerLevel();
    int scrollSpellSaleMultiplier();
    int scrollProtectionSaleMultiplier();
    int scrollDmMustConvinceRead();
    int scrollUnreadMayFade();
    int scrollCurseTakesEffectImmediately();
    int scrollCurseDiseaseOnsetMin();
    int scrollCurseDiseaseOnsetMax();
    int scrollCurseTransportMinMiles();
    int scrollCurseTransportMaxMiles();
    int scrollCurseTransportRadius();
    int scrollCurseRandomSpellLevel();
};
