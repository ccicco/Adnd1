// ====================================================================
// Adnd1 - rules/dmg/miscmagic_phylactery_of_faithfulness_to_feather_token.h
// R276: the III.E misc magic explanation prose part 20
// (DMG p.153-154) - the Phylactery of Faithfulness, the
// Phylactery of Long Years, the Phylactery of Monstrous
// Attention, the Pipes of the Sewers, the Portable Hole
// and Quaals Feather Token, part2 lines 971-998 (global
// = 11065 + part2 line), pinning the kMisc4 rows 30-35 of
// the 36-row III.E.4 table - the slice that closes the
// table. This round has no seam: the slice starts at the
// Faithfulness paragraph head (971 after the 970 blank)
// and ends at the token tail (998 before the 999 blank),
// every paragraph complete. The upload quirks this round:
// the OCR splits three hyphenated words with a space (one-
// quarter, re- establish and non- dimensional); the curly
// apostrophes print in deitys, pipers, tokens and the
// Quaals item name (the engine spells the item with the
// straight mark); curly quotes wrap picked up, hole and to
// hit; the foot and inch primes print as curly marks; two
// multiplication signs ride the rat dice; the token rows
// separate with em-dashes - all pinned as plain digits and
// words, apostrophe-free here. The part1 quirks: the
// Monstrous Attention row splits across two table lines
// (part1 9851-9852, with --- in the x.p. column); the
// Feather Token row prints both dual value pairs in the
// x.p. column. The Phylactery of Faithfulness carries no
// accessor (numberless prose, like the Periapt of Health
// in part 19). 44 accessors: 42 scalars + 2 walkers (the
// token die bands), no name collisions with miscprose1.h
// through miscprose19.h. Pure data + helpers, header-only
// (the grenade.h pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Miscmagic_phylactery_of_faithfulness_to_feather_token (instance methods)
class Miscmagic_phylactery_of_faithfulness_to_feather_token {
public:
    int mmpLongYearsSlowPct();
    int mmpLongYearsDonAge();
    int mmpLongYearsMonthsPerYear();
    int mmpLongYearsPhysicalAge();
    int mmpLongYearsChronAge();
    int mmpLongYearsReverseOneIn();
    int mmpAttentionMinLevel();
    int mmpPipeGiantRatMin();
    int mmpPipeGiantRatMax();
    int mmpPipeGiantRatPct();
    int mmpPipeNormalRatMin();
    int mmpPipeNormalRatMax();
    int mmpPipeNormalRatPct();
    int mmpPipeCallRangeInches();
    int mmpPipeDelayPerInches();
    int mmpPipeObeyPct();
    int mmpPipeReplayObeyPct();
    int mmpPipeReplayTurnPct();
    int mmpPipeTakeoverPctPerRound();
    int mmpPipeKeepPct();
    int mmpHoleDiameterFeet();
    int mmpHoleDepthFeet();
    int mmpHoleBreathTurns();
    int mmpHoleGateRadiusFeet();
    int mmpTokenUses();
    int mmpTokenRowLo(int i);
    int mmpTokenRowHi(int i);
    int mmpTokenAnchorDays();
    int mmpTokenBirdDays();
    int mmpTokenFanHours();
    int mmpTokenSwanSpeedInches();
    int mmpTokenSwanHorses();
    int mmpTokenSwanMen();
    int mmpTokenSwanDays();
    int mmpTokenTreeTrunkFeet();
    int mmpTokenTreeHeightFeet();
    int mmpTokenTreeTopFeet();
    int mmpTokenWhipPlus();
    int mmpTokenWhipLevel();
    int mmpTokenWhipDmgMin();
    int mmpTokenWhipDmgMax();
    int mmpTokenWhipBindMin();
    int mmpTokenWhipBindMax();
    int mmpTokenWhipTurns();
};
