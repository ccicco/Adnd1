// ====================================================================
// Adnd1 - rules/dmg/miscmagic_table4_footnotes.h
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

// R1059 applied
#include "rules/seams/miscreg.h"

namespace rules {

inline int m4RowCount() {
    // the Librams through the Feather Token
    return 36;
}

inline int m4RowLo(int i) {
    const auto* g = mTable(
        "misc_m4", "row_lo");
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    if (!g) return 1;
    return (int)(*g)[i];
}

inline int m4RowHi(int i) {
    const auto* g = mTable(
        "misc_m4", "row_hi");
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    if (!g) return 1;
    return (int)(*g)[i];
}

inline int m4UsableByCleric(int i) {
    const auto* g = mTable(
        "misc_m4", "usable_by_cleric");
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m4UsableByFighter(int i) {
    const auto* g = mTable(
        "misc_m4", "usable_by_fighter");
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m4UsableByMagicUser(int i) {
    const auto* g = mTable(
        "misc_m4", "usable_by_mu");
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    if (!g) return 1;
    return (int)(*g)[i];
}

inline int m4UsableByThief(int i) {
    const auto* g = mTable(
        "misc_m4", "usable_by_thief");
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m4StarCount(int i) {
    const auto* g = mTable(
        "misc_m4", "star_count");
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m4IsDualValued(int i) {
    const auto* g = mTable(
        "misc_m4", "is_dual_valued");
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    if (!g) return 0;
    return (int)(*g)[i];
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
