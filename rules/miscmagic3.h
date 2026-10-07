// ====================================================================
// Adnd1 - rules/miscmagic3.h
// R237: the III.E table 3 footnote pins
// (DMG p.129) - the class marks and the
// asterisk ladder that frame TABLE
// (III.E.) 3 of the miscellaneous magic
// tables:
//   - the (C, F, T) marks: the Gauntlets
//     of Ogre Power (21-22), the Gauntlets
//     of Swimming and Climbing (23-25),
//     the Girdle of Femininity/
//     Masculinity (28) and the Girdle of
//     Giant Strength (29).
//   - the (C, F) mark: the Horn of the
//     Tritons (50-53).
//   - the (C) marks: the Incense of
//     Meditation (66-70) and the Incense
//     of Obsession (71).
//   - the (F) marks: the Javelin of
//     Lightning (81-85) and the Javelin
//     of Piercing (86-90).
//   - NO (M) rows ride this table.
//   - the Figurine of Wondrous Power
//     single asterisk (01-15): the 100 x.p.
//     / 1,000 g.p. values are PER HIT DIE
//     of the figurine.
//   - the Horn of Valhalla double
//     asterisk (54-60): double for a
//     bronze horn, triple for an iron horn
//     (base 1,000 x.p. / 15,000 g.p.).
//   - the Ioun Stones triple asterisk
//     (72): per stone (300 x.p. / 5,000
//     g.p.).
//   - the Instrument of the Bards
//     quadruple asterisk (73-78): PER LEVEL
//     OF INSTRUMENT for bards (base 1,000
//     x.p. / 5,000 g.p.) - the fourth
//     footnote the book upload DROPS,
//     restored from the 1eonline.info
//     compilation (the R175 precedent).
//   - the Jewel of Flawlessness (92): no
//     x.p., 1,000 g.p. PER FACET.
// The row identity is the 33 die bands of
// the engine III.E.3 table (dm/treasure.cpp
// kMisc3 order, Figurine of Wondrous Power
// 01-15 through the 93-00 Ointment row).
// The row VALUES were pinned by the R122
// line-diff audit; this header pins the
// class marks, the asterisk ladder and the
// band edges.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int m3RowCount() {
    // Figurine through the 93-00 Ointment
    return 33;
}

inline int m3RowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        1, 16, 17, 19, 21, 23, 26, 27, 28, 29,
        30, 31, 36, 38, 40, 41, 46, 47, 49, 50,
        54, 61, 64, 66, 71, 72, 73, 79, 81, 86,
        91, 92, 93,
    };
    return t[i];
}

inline int m3RowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        15, 16, 18, 20, 22, 25, 26, 27, 28, 29,
        30, 35, 37, 39, 40, 45, 46, 48, 49, 53,
        60, 63, 65, 70, 71, 72, 78, 80, 85, 90,
        91, 92, 100,
    };
    return t[i];
}

inline int m3UsableByCleric(int i) {
    // the (C) mark; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0,
    };
    return t[i];
}

inline int m3UsableByFighter(int i) {
    // the (F) mark; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        0, 0, 0,
    };
    return t[i];
}

inline int m3UsableByThief(int i) {
    // the (T) mark; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0,
    };
    return t[i];
}

inline int m3StarCount(int i) {
    // the asterisk ladder: 1 the Figurine
    // (per hit die), 2 the Horn of Valhalla
    // (bronze/iron), 3 the Ioun Stones (per
    // stone), 4 the Instrument of the Bards
    // (per level of instrument); i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        2, 0, 0, 0, 0, 3, 4, 0, 0, 0,
        0, 0, 0,
    };
    return t[i];
}

inline int m3IsPerFacetValued(int i) {
    // the Jewel of Flawlessness (92): 1,000
    // g.p. per facet; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0,
    };
    return t[i];
}

inline int m3ClericCount() {
    return 7;
}

inline int m3FighterCount() {
    return 7;
}

inline int m3ThiefCount() {
    return 4;
}

inline int m3FigurinePerHitDieXp() {
    // per hit die of the figurine
    return 100;
}

inline int m3FigurinePerHitDieGp() {
    return 1000;
}

inline int m3ValhallaBaseXp() {
    return 1000;
}

inline int m3ValhallaBaseGp() {
    return 15000;
}

inline int m3ValhallaBronzeMult() {
    // double for a bronze horn
    return 2;
}

inline int m3ValhallaIronMult() {
    // triple for an iron horn
    return 3;
}

inline int m3IounPerStoneXp() {
    // per stone
    return 300;
}

inline int m3IounPerStoneGp() {
    return 5000;
}

inline int m3InstrumentBaseXp() {
    // per level of instrument for bards
    return 1000;
}

inline int m3InstrumentBaseGp() {
    return 5000;
}

inline int m3JewelPerFacetGp() {
    // no x.p., 1,000 g.p. per facet
    return 1000;
}

}  // namespace rules
