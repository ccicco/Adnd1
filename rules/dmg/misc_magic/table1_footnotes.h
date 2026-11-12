// ====================================================================
// Adnd1 - rules/dmg/misc_magic/table1_footnotes.h
// R225: the III.E table 1 footnote pins
// (DMG p.128) - the class marks and the
// special-row footnotes that frame the
// TABLE (III.E.) 1 miscellaneous magic
// table:
//   - the (C) and (M) class marks
//     (Book of Exalted Deeds and Book
//     of Vile Darkness are (C); the two
//     Bowls and the two Braziers are
//     (M)).
//   - the Artifact or Relic row (17):
//     no values - see the Special table
//     hereafter.
//   - the Bracers of Defense asterisk
//     (60-79): the x.p. and g.p. values
//     are PER ARMOR CLASS POINT above
//     10 (AC 6 is worth 2,000 x.p.,
//     12,000 g.p. if sold - four
//     points).
//   - Bucknard Everfull Purse (99-00):
//     the printed tiered values
//     (1,500/2,500/4,000 x.p.;
//     15,000/25,000/40,000 g.p.) are
//     carried by the R122-pinned row
//     ranges.
// The row identity is the 33 die bands
// of the engine III.E.1 table
// (dm/treasure.cpp kMisc1 order,
// Alchemy Jug 01-02 through Bucknard
// Everfull Purse 99-00). The row VALUES
// were pinned by the R122 line-diff
// audit; this header pins the class
// marks, the special rows and the band
// edges. JUDGMENT: the R122 row for the
// purse pins xp 1500-4000 / gp
// 15000-40000, matching the printed
// tiers as ranges.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Miscmagic_table1_footnotes (instance methods)
class Miscmagic_table1_footnotes {
public:
    int m1RowCount();
    int m1RowLo(int i);
    int m1RowHi(int i);
    int m1UsableByMagicUser(int i);
    int m1UsableByCleric(int i);
    int m1IsArtifactRelicRow(int i);
    int m1IsPerAcPointValued(int i);
    int m1IsTieredPurseRow(int i);
    int m1MagicUserCount();
    int m1ClericCount();
    int m1BracersPerAcXp();
    int m1BracersPerAcGp();
};
