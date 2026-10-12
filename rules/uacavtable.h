// ===========================================================================
// Adnd1 - rules/uacavtable.h
// The UA CAVALIERS TABLE I (p. 15 print) pins,
// R368: the full table - the two 0-level track rows
// (Horseman 1d4+1, Lancer 2d4+1), the 1st-level
// footnote (1d10+3 vs the track 3d4+1), the XP
// bands, the level titles, the cumulative dice
// column (2-10 dice at levels 2-10, 10+3 and 10+6
// at 11th and 12th), the 3 hp per level after the
// 10th and the 300,000 xp per level past the 12th.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. Cross-checks the landed R328 seam
// (rules/cavalier.h - the XP ladder and the known
// title cells) and the R327 d10 hit die.
//
// JUDGMENTs (the decode method):
//   - the level-5 title cell prints Knight in the
//     grid; the retainer prose elsewhere reads
//     becoming a Knight at 6th - the R328 conflict.
//     The grid print wins (the standing print-wins
//     convention), the divergence flagged pending
//     the PDF.
//   - the level-6 title cell is OCR-lost in the
//     extract - a hole, no pin, pending the PDF.
//   - the level-11 and level-12 title cells print
//     cleanly ("Cavalier, 11th", "Cavalier, 12th") -
//     two of the four R328 holes close here.
//   - the level-11 XP band cell garbles; the band is
//     decoded from its neighbors (the 10th band ends
//     600,000; the 12th band prints 900,001) - the
//     forced decode, corroborated by the R328 ladder.
//   - the table header cell prints "12-Sided Dice"
//     against the R327 cavalier d10 - a suspected
//     column scramble; not pinned, flagged pending
//     the PDF.
// ===========================================================================

#pragma once

namespace rules {

// ---- the 0-level track rows ----
// Horseman: -1,500 to -501 xp, 1d4+1 hp.
inline int uacavtHorsemanXpLow()
    { return -1500; }

inline int uacavtHorsemanXpHigh()
    { return -501; }

inline int uacavtHorsemanHpDice()
    { return 1; }

inline int uacavtHorsemanHpDiceSides()
    { return 4; }

inline int uacavtHorsemanHpBonus()
    { return 1; }

// Lancer: -500 to -1 xp, 2d4+1 hp.
inline int uacavtLancerXpLow()
    { return -500; }

inline int uacavtLancerXpHigh()
    { return -1; }

inline int uacavtLancerHpDice()
    { return 2; }

inline int uacavtLancerHpDiceSides()
    { return 4; }

inline int uacavtLancerHpBonus()
    { return 1; }

// ---- the 1st-level footnote ----
// If qualification required the two 0-level grades,
// the 1st-level hit dice are 3d4+1; in all other
// cases 1d10+3 applies (the Upper Class direct
// entry).
inline bool uacavtFirstLevelTrackFootnote()
    { return true; }

inline int uacavtTrackFirstDice()
    { return 3; }

inline int uacavtTrackFirstSides()
    { return 4; }

inline int uacavtTrackFirstBonus()
    { return 1; }

inline int uacavtDirectFirstDice()
    { return 1; }

inline int uacavtDirectFirstSides()
    { return 10; }

inline int uacavtDirectFirstBonus()
    { return 3; }

// ---- the XP bands, levels 1-12 ----
// The printed band bounds; level 12 is unbounded
// (300,000 xp per level past the 12th). The R328
// attain ladder reads attain(level) = high(level-1).
inline int uacavtLevelXpLow(int level) {
    static const int k[12] = {
        0, 2501, 5001, 10001, 18501, 37001,
        85001, 140001, 220001, 300001, 600001,
        900001,
    };
    if (level < 1) level = 1;
    if (level > 12) level = 12;
    return k[level - 1];
}

inline int uacavtLevelXpHigh(int level) {
    static const int k[12] = {
        2500, 5000, 10000, 18500, 37000,
        85000, 140000, 220000, 300000, 600000,
        900000, 0,
    };
    if (level < 1) level = 1;
    if (level > 12) level = 12;
    return k[level - 1];
}

// The 12th band is unbounded (300,000 xp per level
// past the 12th); the level-11 band garbles and is
// decoded from its neighbors.
inline bool uacavtLevel12XpUnbounded()
    { return true; }

inline bool uacavtLevel11BandDecoded()
    { return true; }

// ---- the cumulative dice column ----
// Levels 2-10: the dice count equals the level;
// the 11th and 12th rows print 10+3 and 10+6 (the
// 3 hp per level after the 10th).
inline int uacavtLevelDiceCount(int level) {
    if (level < 2) return 1;
    if (level > 10) return 10;
    return level;
}

inline int uacavtLevel11FlatHp()
    { return 3; }

inline int uacavtLevel12FlatHp()
    { return 6; }

inline int uacavtHpPerLevelPast10()
    { return 3; }

inline bool uacavtDiceColumnCumulative()
    { return true; }

// The header cell prints 12-sided against the
// landed R327 d10 - a suspected scramble, no pin.
inline bool uacavtTwelveSidedHeaderSuspect()
    { return true; }

// ---- the level titles ----
// 0 = Horseman, -1 = Lancer, 1-12 the levels,
// 13+ Cavalier Commander. Level 6 is the lost
// cell (the empty string); level 5 is the grid
// print (the prose conflict flagged below).
inline const char* uacavtTitle(int level) {
    switch (level) {
        case 0: return "Horseman";
        case -1: return "Lancer";
        case 1: return "Armiger";
        case 2: return "Scutifer";
        case 3: return "Esquire";
        case 4: return "Knight Errant";
        case 5: return "Knight";
        case 7: return "Grand Knight";
        case 8: return "Banneret";
        case 9: return "Chevalier";
        case 10: return "Cavalier";
        case 11: return "Cavalier, 11th";
        case 12: return "Cavalier, 12th";
        default:
            if (level >= 13)
                return "Cavalier Commander";
            return "";
    }
}

inline bool uacavtLevel6TitleCellLost()
    { return true; }

inline bool uacavtLevel5GridVsProseConflict()
    { return true; }

// ---- the past-12th reads ----
inline int uacavtXpPerLevelPast12()
    { return 300000; }

inline int uacavtCommanderLevel()
    { return 13; }

}   // namespace rules

