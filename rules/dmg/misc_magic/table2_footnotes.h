// ====================================================================
// Adnd1 - rules/dmg/misc_magic/table2_footnotes.h
// R226: the III.E table 2 footnote pins
// (DMG p.128) - the class marks and the
// asterisk rows that frame TABLE
// (III.E.) 2 of the miscellaneous magic
// tables:
//   - the (C) mark: Candle of
//     Invocation (cleric only).
//   - the (M) marks: the two Censers,
//     Crystal Ball, Crystal Hypnosis
//     Ball, Eyes of Charming.
//   - the Cloak of Protection asterisk
//     (33-55): the 1,000 x.p. / 10,000
//     g.p. values are PER PLUS of
//     protection.
//   - the Crystal Ball double asterisk
//     (56-60): add 100% for each
//     additional feature (base 1,000
//     x.p. / 5,000 g.p.).
//   - the Eyes of Petrification triple
//     asterisk (00): the print carries
//     ---*** in both value columns.
// The row identity is the 30 die bands
// of the engine III.E.2 table
// (dm/treasure.cpp kMisc2 order,
// Candle of Invocation 01-06 through
// Eyes of Petrification 00). The row
// VALUES were pinned by the R122
// line-diff audit; this header pins the
// class marks, the asterisk rows and the
// band edges.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Miscmagic_table2_footnotes (instance methods)
class Miscmagic_table2_footnotes {
public:
    int m2RowCount();
    int m2RowLo(int i);
    int m2RowHi(int i);
    int m2UsableByCleric(int i);
    int m2UsableByMagicUser(int i);
    int m2IsPerPlusValued(int i);
    int m2HasFeatureAsterisk(int i);
    int m2IsTripleStar(int i);
    int m2ClericCount();
    int m2MagicUserCount();
    int m2CloakPerPlusXp();
    int m2CloakPerPlusGp();
    int m2CrystalBallBaseXp();
    int m2CrystalBallBaseGp();
    int m2CrystalBallFeatureBonusPct();
};
