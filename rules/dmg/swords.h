// ====================================================================
// Adnd1 - rules/dmg/swords.h
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

// R-refactor: namespace rules -> class Swords (instance methods)
class Swords {
public:
    int swRowCount();
    int swRowLo(int i);
    int swRowHi(int i);
    int swXpValue(int i);
    int swSaleGp(int i);
    int swNoSaleCount();
    int swLongswordPct();
    int swBroadswordPct();
    int swShortswordPct();
    int swBastardPct();
    int swTwoHandedPct();
    int swFlameVsRegenBonus();
    int swFlameVsColdAvianBonus();
    int swFlameVsUndeadBonus();
    int swFrostVsFireBonus();
};
