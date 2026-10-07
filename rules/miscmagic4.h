// ====================================================================
// Adnd1 - rules/miscmagic4.h
// R238: the III.E table 4 footnote pins
// (DMG p.129-130) - the class marks, the
// asterisk ladder and the dual-value rows
// that frame TABLE (III.E.) 4 of the
// miscellaneous magic tables:
//   - the (M) marks: the three Librams,
//     the Manual of Golems (with C), the
//     Mirror of Life Trapping and the
//     Pearl of Power.
//   - the (C) marks: the Manual of Golems
//     (with M), the Necklace of Prayer
//     Beads, the Pearl of Wisdom, the two
//     Nets (with F and T) and the three
//     Phylacteries.
//   - the (F) marks: the Manual of
//     Puissant Skill at Arms, the Mattock
//     of the Titans and the two Nets.
//   - the (T) marks: the Manual of
//     Stealthy Pilfering and the two Nets.
//   - the Necklace of Missiles single
//     asterisk (24-27): the 50 x.p. / 200
//     g.p. values are PER HIT DIE of each
//     missile.
//   - the Necklace of Prayer Beads double
//     asterisk (28-33): PER SPECIAL BEAD
//     (500 x.p. / 3,000 g.p.).
//   - the Marvelous Pigments triple
//     asterisk (43-44): PER POT of
//     pigments (500 x.p. / 3,000 g.p.).
//   - the Pearl of Power quadruple
//     asterisk (45-46): PER LEVEL OF SPELL
//     (200 x.p. / 2,000 g.p.) - all four
//     footnotes ride the book upload this
//     time.
//   - the two DUAL-VALUE rows: the
//     Medallion of ESP (13-15) at 1,000 /
//     3,000 x.p. and 10,000 / 30,000 g.p.,
//     and the Feather Token (86-00) at
//     500 / 1,000 x.p. and 2,000 / 7,000
//     g.p.
// The row identity is the 36 die bands of
// the engine III.E.4 table (dm/treasure.cpp
// kMisc4 order, the three Librams 01-03
// through the Feather Token 86-00). The
// row VALUES were pinned by the R122
// line-diff audit; this header pins the
// class marks, the asterisk ladder, the
// dual-value rows and the band edges.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int m4RowCount() {
    // the Librams through the Feather Token
    return 36;
}

inline int m4RowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 16, 18, 19, 20, 21, 24, 28,
        34, 36, 39, 43, 45, 47, 49, 51, 54, 61,
        65, 71, 75, 77, 85, 86,
    };
    return t[i];
}

inline int m4RowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 15, 17, 18, 19, 20, 23, 27, 33,
        35, 38, 42, 44, 46, 48, 50, 53, 60, 64,
        70, 74, 76, 84, 85, 100,
    };
    return t[i];
}

inline int m4UsableByCleric(int i) {
    // the (C) mark; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 1, 1, 0, 0, 1, 0, 0, 0, 0,
        1, 1, 1, 0, 0, 0,
    };
    return t[i];
}

inline int m4UsableByFighter(int i) {
    // the (F) mark; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int m4UsableByMagicUser(int i) {
    // the (M) mark; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        1, 1, 1, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int m4UsableByThief(int i) {
    // the (T) mark; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int m4StarCount(int i) {
    // the asterisk ladder: 1 the Necklace of
    // Missiles (per hit die of each missile),
    // 2 the Prayer Beads (per special bead),
    // 3 the Marvelous Pigments (per pot),
    // 4 the Pearl of Power (per level of
    // spell); i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 2,
        0, 0, 0, 3, 4, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int m4IsDualValued(int i) {
    // the dual-value rows: the Medallion of
    // ESP (13-15) and the Feather Token
    // (86-00); i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1,
    };
    return t[i];
}

inline int m4ClericCount() {
    return 8;
}

inline int m4FighterCount() {
    return 4;
}

inline int m4MagicUserCount() {
    return 6;
}

inline int m4ThiefCount() {
    return 3;
}

inline int m4MissilePerHitDieXp() {
    // per hit die of each missile
    return 50;
}

inline int m4MissilePerHitDieGp() {
    return 200;
}

inline int m4BeadPerSpecialXp() {
    // per special bead
    return 500;
}

inline int m4BeadPerSpecialGp() {
    return 3000;
}

inline int m4PigmentsPerPotXp() {
    // per pot of pigments
    return 500;
}

inline int m4PigmentsPerPotGp() {
    return 3000;
}

inline int m4PearlPerSpellLevelXp() {
    // per level of spell
    return 200;
}

inline int m4PearlPerSpellLevelGp() {
    return 2000;
}

inline int m4MedallionEspXpLow() {
    return 1000;
}

inline int m4MedallionEspXpHigh() {
    return 3000;
}

inline int m4MedallionEspGpLow() {
    return 10000;
}

inline int m4MedallionEspGpHigh() {
    return 30000;
}

inline int m4FeatherTokenXpLow() {
    return 500;
}

inline int m4FeatherTokenXpHigh() {
    return 1000;
}

inline int m4FeatherTokenGpLow() {
    return 2000;
}

inline int m4FeatherTokenGpHigh() {
    return 7000;
}

}  // namespace rules
