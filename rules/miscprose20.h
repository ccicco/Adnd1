// ====================================================================
// Adnd1 - rules/miscprose20.h
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

namespace rules {

inline int mmpLongYearsSlowPct() {
    // slows the aging process by one-quarter
    return 25;
}

inline int mmpLongYearsDonAge() {
    // the example cleric dons the device at age 20
    return 20;
}

inline int mmpLongYearsMonthsPerYear() {
    // he or she will age 9 months every 12
    return 9;
}

inline int mmpLongYearsPhysicalAge() {
    // in 12 chronological years, physically 29
    return 29;
}

inline int mmpLongYearsChronAge() {
    // rather than the naive 32
    return 32;
}

inline int mmpLongYearsReverseOneIn() {
    // 1 in 20 cursed to operate in reverse
    return 20;
}

inline int mmpAttentionMinLevel() {
    // at 10th or higher level the deity most
    // powerful enemy interferes directly
    return 10;
}

inline int mmpPipeGiantRatMin() {
    // attracts from 10-60 giant rats
    return 10;
}

inline int mmpPipeGiantRatMax() {
    // the giant rat ceiling
    return 60;
}

inline int mmpPipeGiantRatPct() {
    // giant rats at 80 percent
    return 80;
}

inline int mmpPipeNormalRatMin() {
    // or from 30-180 normal rats
    return 30;
}

inline int mmpPipeNormalRatMax() {
    // the normal rat ceiling
    return 180;
}

inline int mmpPipeNormalRatPct() {
    // normal rats at 20 percent
    return 20;
}

inline int mmpPipeCallRangeInches() {
    // if either or both are within 40 inches
    return 40;
}

inline int mmpPipeDelayPerInches() {
    // a 1 round delay per each 5 inches traveled
    return 5;
}

inline int mmpPipeObeyPct() {
    // 95 percent likely to obey while the piper plays
    return 95;
}

inline int mmpPipeReplayObeyPct() {
    // called again: 70 percent come and obey
    return 70;
}

inline int mmpPipeReplayTurnPct() {
    // but 30 percent turn upon the piper
    return 30;
}

inline int mmpPipeTakeoverPctPerRound() {
    // 30 percent per round to take over control
    // from a controlling creature
    return 30;
}

inline int mmpPipeKeepPct() {
    // 70 percent chance of maintaining control
    return 70;
}

inline int mmpHoleDiameterFeet() {
    // opened fully, 6 feet in diameter
    return 6;
}

inline int mmpHoleDepthFeet() {
    // an extra-dimensional hole 10 feet deep
    return 10;
}

inline int mmpHoleBreathTurns() {
    // breath runs out after about a turn
    return 1;
}

inline int mmpHoleGateRadiusFeet() {
    // creatures within a 10 foot radius are drawn
    // to the plane, both items destroyed
    return 10;
}

inline int mmpTokenUses() {
    // each token is usable but once
    return 1;
}

inline int mmpTokenRowLo(int i) {
    // the printed token band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 5, 8, 11, 14, 19,
    };
    return t[i];
}

inline int mmpTokenRowHi(int i) {
    // the printed token band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 7, 10, 13, 18, 20,
    };
    return t[i];
}

inline int mmpTokenAnchorDays() {
    // the anchor moors a craft immobile for 1 full day
    return 1;
}

inline int mmpTokenBirdDays() {
    // the bird equals a roc of the largest size
    // (1 day duration)
    return 1;
}

inline int mmpTokenFanHours() {
    // the fan works up to eight hours a day
    return 8;
}

inline int mmpTokenSwanSpeedInches() {
    // the swan boat swims at 24 inch speed
    return 24;
}

inline int mmpTokenSwanHorses() {
    // it carries 8 horses and gear
    return 8;
}

inline int mmpTokenSwanMen() {
    // or 32 men
    return 32;
}

inline int mmpTokenSwanDays() {
    // duration 1 day
    return 1;
}

inline int mmpTokenTreeTrunkFeet() {
    // a great oak with a 6 foot diameter trunk
    return 6;
}

inline int mmpTokenTreeHeightFeet() {
    // 60 foot height
    return 60;
}

inline int mmpTokenTreeTopFeet() {
    // 40 foot top diameter
    return 40;
}

inline int mmpTokenWhipPlus() {
    // a +1 weapon
    return 1;
}

inline int mmpTokenWhipLevel() {
    // 9th level fighter to hit probability
    return 9;
}

inline int mmpTokenWhipDmgMin() {
    // 2-7 hit points damage
    return 2;
}

inline int mmpTokenWhipDmgMax() {
    return 7;
}

inline int mmpTokenWhipBindMin() {
    // save versus magic or be bound fast
    // for 2-7 rounds
    return 2;
}

inline int mmpTokenWhipBindMax() {
    return 7;
}

inline int mmpTokenWhipTurns() {
    // wielded for up to 6 turns
    return 6;
}

}  // namespace rules