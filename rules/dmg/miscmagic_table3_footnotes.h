// ====================================================================
// Adnd1 - rules/dmg/miscmagic_table3_footnotes.h
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

// R-refactor: namespace rules -> class Miscmagic_table3_footnotes (instance methods)
class Miscmagic_table3_footnotes {
public:
    int m3RowCount();
    int m3RowLo(int i);
    int m3RowHi(int i);
    int m3UsableByCleric(int i);
    int m3UsableByFighter(int i);
    int m3UsableByThief(int i);
    int m3StarCount(int i);
    int m3IsPerFacetValued(int i);
    int m3ClericCount();
    int m3FighterCount();
    int m3ThiefCount();
    int m3FigurinePerHitDieXp();
    int m3FigurinePerHitDieGp();
    int m3ValhallaBaseXp();
    int m3ValhallaBaseGp();
    int m3ValhallaBronzeMult();
    int m3ValhallaIronMult();
    int m3IounPerStoneXp();
    int m3IounPerStoneGp();
    int m3InstrumentBaseXp();
    int m3InstrumentBaseGp();
    int m3JewelPerFacetGp();
};
