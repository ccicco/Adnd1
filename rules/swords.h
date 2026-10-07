// ====================================================================
// Adnd1 - rules/swords.h
// R242: the III.G swords pins
// (DMG p.131) - the magic swords table (the
// RIGHT column of the two-column print):
//   - 26 rows, Sword +1 01-25 through
//     Sword, Cursed Berserking 96-00 (the
//     00 band pins as 100).
//   - the x.p. point values and the g.p.
//     sale values of every row.
//   - the THREE cursed swords print --- g.p.
//     sale values: Sword +1 Cursed 86-90,
//     Sword -2 Cursed 91-95 and Sword,
//     Cursed Berserking 96-00 (pinned as 0
//     g.p.).
//   - the sword SIZE note: 70% of swords are
//     longswords, 20% broadswords, 5% short
//     (small) swords, 4% bastard swords, 1%
//     two-handed swords (sum 100).
//   - the TWO tiered-bonus wrapped rows: the
//     Flame Tongue 46-49 is +2 vs.
//     regenerating, +3 vs. cold-using,
//     inflammable or avian, +4 vs. undead;
//     the Frost Brand 72-74 is +6 vs. fire
//     using/dwelling.
// NO class marks or asterisks ride this
// table (the no-x.p. footnote after the
// table belongs to the III.E Special table,
// pinned R240).
// The row identity is the 26 die bands of
// the engine III.G table (dm/treasure.cpp
// kSwords order). The row NAMES were pinned
// by the R122 line-diff audit; this header
// pins the values, band edges, the size
// note and the tiered bonuses.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int swRowCount() {
    // Sword +1 through the Cursed Berserking
    return 26;
}

inline int swRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 25) i = 25;
    static const int t[26] = {
        1, 26, 31, 36, 41, 46, 50, 51, 59,
        63, 67, 68, 72, 75, 77, 78, 79, 80,
        81, 82, 83, 84, 85, 86, 91, 96,
    };
    return t[i];
}

inline int swRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 25) i = 25;
    static const int t[26] = {
        25, 30, 35, 40, 45, 49, 50, 58, 62,
        66, 67, 71, 74, 76, 77, 78, 79, 80,
        81, 82, 83, 84, 85, 90, 95, 100,
    };
    return t[i];
}

inline int swXpValue(int i) {
    // the x.p. point values; i clamps
    if (i < 0) i = 0;
    if (i > 25) i = 25;
    static const int t[26] = {
        400, 600, 700, 800, 800, 900, 1000, 800, 900,
        900, 1600, 1400, 1600, 2000, 3000, 3000, 3600, 4000,
        4400, 4400, 5000, 7000, 10000, 400, 600, 900,
    };
    return t[i];
}

inline int swSaleGp(int i) {
    // the g.p. sale values; the cursed rows are 0; i clamps
    if (i < 0) i = 0;
    if (i > 25) i = 25;
    static const int t[26] = {
        2000, 3000, 3500, 4000, 4000, 4500, 5000, 4000, 4500,
        4500, 8000, 7000, 8000, 10000, 15000, 15000, 18000, 20000,
        22000, 22000, 25000, 35000, 50000, 0, 0, 0,
    };
    return t[i];
}

inline int swNoSaleCount() {
    // the three cursed swords print --- g.p.
    return 3;
}

inline int swLongswordPct() {
    // 70% of swords are longswords
    return 70;
}

inline int swBroadswordPct() {
    // 20% are broadswords
    return 20;
}

inline int swShortswordPct() {
    // 5% are short (small) swords
    return 5;
}

inline int swBastardPct() {
    // 4% are bastard swords
    return 4;
}

inline int swTwoHandedPct() {
    // 1% are two-handed swords
    return 1;
}

inline int swFlameVsRegenBonus() {
    // Flame Tongue: +2 vs. regenerating creatures
    return 2;
}

inline int swFlameVsColdAvianBonus() {
    // Flame Tongue: +3 vs. cold-using, inflammable or avian
    return 3;
}

inline int swFlameVsUndeadBonus() {
    // Flame Tongue: +4 vs. undead
    return 4;
}

inline int swFrostVsFireBonus() {
    // Frost Brand: +6 vs. fire using/dwelling creatures
    return 6;
}

}  // namespace rules
