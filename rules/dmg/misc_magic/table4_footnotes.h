// ====================================================================
// Adnd1 - rules/dmg/misc_magic/table4_footnotes.h
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

// R-refactor: namespace rules -> class Miscmagic_table4_footnotes (instance methods)
class Miscmagic_table4_footnotes {
public:
    int m4RowCount();
    int m4RowLo(int i);
    int m4RowHi(int i);
    int m4UsableByCleric(int i);
    int m4UsableByFighter(int i);
    int m4UsableByMagicUser(int i);
    int m4UsableByThief(int i);
    int m4StarCount(int i);
    int m4IsDualValued(int i);
    int m4ClericCount();
    int m4FighterCount();
    int m4MagicUserCount();
    int m4ThiefCount();
    int m4MissilePerHitDieXp();
    int m4MissilePerHitDieGp();
    int m4BeadPerSpecialXp();
    int m4BeadPerSpecialGp();
    int m4PigmentsPerPotXp();
    int m4PigmentsPerPotGp();
    int m4PearlPerSpellLevelXp();
    int m4PearlPerSpellLevelGp();
    int m4MedallionEspXpLow();
    int m4MedallionEspXpHigh();
    int m4MedallionEspGpLow();
    int m4MedallionEspGpHigh();
    int m4FeatherTokenXpLow();
    int m4FeatherTokenXpHigh();
    int m4FeatherTokenGpLow();
    int m4FeatherTokenGpHigh();
};
