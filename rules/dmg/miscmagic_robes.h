// ====================================================================
// Adnd1 - rules/dmg/miscmagic_robes.h
// R277: the III.E misc magic explanation prose part 21
// (DMG p.153-154) - the Robe of the Archmagi, the Robe
// of Blending, the Robe of Eyes, the Robe of Powerlessness,
// the Robe of Scintillating Colors and the Robe of Useful
// Items, part2 lines 1002-1052 (global = 11065 + part2
// line), pinning the kMisc5 rows 0-5 of the 35-row III.E.5
// table - the slice that opens the table. This round has
// one seam: the Powerlessness paragraph splits between the
// 1018 tail (and becomes) and the 1021 head (weak as well),
// with the 1019-1020 pair of blanks - the p.153-154 page
// break with no running head - seam restored here. The
// upload quirks this round: the OCR splits two words with
// a space (magic- user and language/ noise); the curly
// apostrophes print in the robe and wearer possessives;
// curly quotes wrap see, eyes and flowing; the foot and
// inch primes print as curly marks; the 20%/minus 4
// reduction prints the true minus sign; the coffer and
// window rows carry one-half and multiplication signs;
// the door and window rows separate with em-dashes - all
// pinned as plain digits and words, apostrophe-free here.
// The part1 quirks: the six robe rows print side-by-side
// with armor-table columns (part1 9875-9880); the
// Powerlessness row prints --- in the x.p. column; the
// Scintillating row misplaces 2,750 after the (C, M)
// marks. The useful items table flattens its two header
// rows (Dice and Roll Result each on an own line) and
// prints 13 die bands, pinned as the twin walkers.
// 67 accessors: 65 scalars + 2 walkers (the useful item
// die bands), no name collisions with miscprose1.h
// through miscprose20.h. Pure data + helpers, header-only
// (the grenade.h pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Miscmagic_robes (instance methods)
class Miscmagic_robes {
public:
    int mmpArchmagiWhitePct();
    int mmpArchmagiGrayPct();
    int mmpArchmagiBlackPct();
    int mmpArchmagiAcClass();
    int mmpArchmagiMagicResistPct();
    int mmpArchmagiSaveBonus();
    int mmpArchmagiPenaltyPct();
    int mmpArchmagiPenaltyMinus();
    int mmpArchmagiCharmFamilyCount();
    int mmpArchmagiClashDmgMin();
    int mmpArchmagiClashDmgMax();
    int mmpArchmagiClashDiceCount();
    int mmpArchmagiClashDiceBonus();
    int mmpArchmagiClashXpMin();
    int mmpArchmagiClashXpMax();
    int mmpArchmagiGrayDmgMin();
    int mmpArchmagiGrayDmgMax();
    int mmpArchmagiGrayXpMin();
    int mmpArchmagiGrayXpMax();
    int mmpBlendDetectRangeInches();
    int mmpBlendDetectPerIntPct();
    int mmpBlendDetectIntMin();
    int mmpBlendLevelDetectIntMin();
    int mmpBlendLevelDetectLevelMin();
    int mmpBlendDetectPerLevelPct();
    int mmpBlendExamplePct();
    int mmpEyesInfravisionInches();
    int mmpEyesSeeInvisibleInches();
    int mmpEyesSeeInfraredInches();
    int mmpEyesTrackRangerLevel();
    int mmpEyesBlindLightMin();
    int mmpEyesBlindLightMax();
    int mmpEyesBlindContinualMin();
    int mmpEyesBlindContinualMax();
    int mmpPowerlessIntelligence();
    int mmpPowerlessStrength();
    int mmpScintIntMin();
    int mmpScintWisMin();
    int mmpScintLightFeet();
    int mmpScintStartRounds();
    int mmpScintTransfixMin();
    int mmpScintTransfixMax();
    int mmpScintHitPctPerRound();
    int mmpScintHitPctMax();
    int mmpScintHitMaxRounds();
    int mmpScintCastRangeInches();
    int mmpScintHypnotizeMin();
    int mmpScintHypnotizeMax();
    int mmpUsefulDetachRounds();
    int mmpUsefulBaseEach();
    int mmpUsefulBaseCount();
    int mmpUsefulExtraMin();
    int mmpUsefulExtraMax();
    int mmpUsefulGpBag();
    int mmpUsefulCofferGp();
    int mmpUsefulGemsCount();
    int mmpUsefulGemValueGp();
    int mmpUsefulLadderFeet();
    int mmpUsefulPitCubicFeet();
    int mmpUsefulRowboatFeet();
    int mmpUsefulWindowWidthFeet();
    int mmpUsefulWindowHeightFeet();
    int mmpUsefulWindowDepthFeet();
    int mmpUsefulScrollSpells();
    int mmpUsefulWarDogsPair();
    int mmpUsefulRowLo(int i);
    int mmpUsefulRowHi(int i);
};
