// ====================================================================
// Adnd1 - rules/spying.h
// R205: the spying tables (DMG pp.19-20, the
// SPYING section after the assassin guild
// tables) - the lane rules/assassinate.h
// named and deferred in R164.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// hire, the mission assignment and the
// week-to-day clock; the rolls read here).
// Conventions, named in place:
//   - A hired spy reads the success table
//     as a 1st-level assassin on the first
//     mission, 2nd on the second, etc., and
//     can never become more proficient at
//     spying than 8th level (the print);
//     the level bookkeeping is caller-side.
//   - The success table runs to 17th level
//     (the print); levels below 1 read
//     row 1, above 17 read row 17.
//   - Extraordinary mission time is "as
//     required" - the print leaves it to
//     the case; the helper reads 0-0 and
//     the caller rules it.
//   - The discovery chance is a PERIODIC
//     check the caller schedules: no
//     precautions 1 percent per week flat;
//     minimal the modified percent per
//     week; moderate the modified percent
//     twice per week; strong the DOUBLED
//     modified percent twice per week. A
//     spy who leads the group reads no
//     precautions (above suspicion).
//   - The failure table doubles as the
//     discovery table: the caught-spy
//     result reads the same bands with
//     the discovered modifier (+25).
// ====================================================================

#pragma once

namespace rules {

// -----------------------------------------------------------------------
// The three mission categories (the print order)
// -----------------------------------------------------------------------

enum SpyCategory {
    SPY_SIMPLE = 0,
    SPY_DIFFICULT,
    SPY_EXTRAORDINARY,
    SPY_CATEGORY_COUNT
};

inline const char* spyCategoryName(SpyCategory c) {
    static const char* const n[SPY_CATEGORY_COUNT] = {
        "simple", "difficult", "extraordinary"
    };
    if (c < SPY_SIMPLE) c = SPY_SIMPLE;
    if (c >= SPY_CATEGORY_COUNT) c = SPY_EXTRAORDINARY;
    return n[c];
}

// -----------------------------------------------------------------------
// The ASSASSIN SPYING TABLE: the chance of
// success by spy level (1-17) and category.
// -----------------------------------------------------------------------
inline int spySuccessChance(int level, SpyCategory c) {
    static const int k[17][SPY_CATEGORY_COUNT] = {
        { 50, 30, 10 },
        { 55, 35, 15 },
        { 60, 35, 15 },
        { 65, 40, 20 },
        { 70, 45, 25 },
        { 75, 50, 25 },
        { 80, 55, 30 },
        { 85, 60, 35 },
        { 85, 60, 40 },
        { 90, 65, 45 },
        { 90, 65, 50 },
        { 95, 65, 50 },
        { 95, 70, 50 },
        { 95, 70, 50 },
        { 95, 75, 50 },
        { 95, 75, 55 },
        { 95, 75, 60 },
    };
    if (level < 1) level = 1;
    if (level > 17) level = 17;
    if (c < SPY_SIMPLE) c = SPY_SIMPLE;
    if (c >= SPY_CATEGORY_COUNT) c = SPY_EXTRAORDINARY;
    return k[level - 1][c];
}

// The hired-spy level cap (the print: never
// more proficient at spying than 8th level)
inline int spyHiredLevelCap() { return 8; }

// -----------------------------------------------------------------------
// Time required to accomplish the mission:
// simple 1-8 days, difficult 5-40 days,
// extraordinary as required (0-0 - the caller
// rules the case).
// -----------------------------------------------------------------------
inline void spyMissionDays(SpyCategory c, int& lo, int& hi) {
    if (c == SPY_SIMPLE) { lo = 1; hi = 8; return; }
    if (c == SPY_DIFFICULT) { lo = 5; hi = 40; return; }
    lo = 0; hi = 0;
}

// -----------------------------------------------------------------------
// The chance of discovery: the modified percent
// is a cumulative 1 percent per day spent
// spying, capped at 10, minus the spy level,
// and always at least 1 percent (the print:
// even a negative result leaves 1 percent).
// -----------------------------------------------------------------------
inline int spyModifiedDiscoveryChance(int daysSpent,
                                      int spyLevel) {
    int base = daysSpent;
    if (base > 10) base = 10;
    if (base < 0) base = 0;
    int chance = base - spyLevel;
    if (chance < 1) chance = 1;
    return chance;
}

// -----------------------------------------------------------------------
// The precaution tiers: how many discovery
// checks per week, and the percent each check
// reads. No precautions is a flat 1 percent
// per week (the modified percent does not
// apply); minimal reads the modified percent
// once per week; moderate twice per week;
// strong the DOUBLED modified percent twice
// per week. A spy who leads the group reads
// no precautions (above suspicion) - the
// caller passes SPYP_NONE.
// -----------------------------------------------------------------------
enum SpyPrecautions { SPYP_NONE = 0, SPYP_MINIMAL,
                      SPYP_MODERATE, SPYP_STRONG };

inline int spyPrecautionChecksPerWeek(SpyPrecautions p) {
    static const int k[4] = { 1, 1, 2, 2 };
    if (p < SPYP_NONE) p = SPYP_NONE;
    if (p > SPYP_STRONG) p = SPYP_STRONG;
    return k[p];
}

// The percent chance for ONE discovery check
// under the given precautions, given the
// modified percent.
inline int spyDiscoveryCheckPercent(SpyPrecautions p,
                                     int modifiedPercent) {
    if (p < SPYP_NONE) p = SPYP_NONE;
    if (p > SPYP_STRONG) p = SPYP_STRONG;
    if (p == SPYP_NONE) return 1;   // flat, per the print
    if (p == SPYP_STRONG) return 2 * modifiedPercent;
    return modifiedPercent;
}

// The tenfold window: if a spy is caught,
// the chance of discovery increases tenfold
// for any other spy operating during the
// following 20 to 50 days.
inline int spyPostCaptureWindowLo() { return 20; }
inline int spyPostCaptureWindowHi() { return 50; }
inline int spyPostCaptureChanceMultiple() { return 10; }

// -----------------------------------------------------------------------
// The SPY FAILURE TABLE (also the discovery
// table, with the discovered modifier): the
// five printed bands on d100.
// -----------------------------------------------------------------------
enum SpyFailureResult {
    SPYF_RETRY = 0,           // 01-35: further attempts possible
    SPYF_COMPROMISED_90,      // 36-60: further spying 90 percent fails
    SPYF_IMPRISONED_SILENT,   // 61-80: caught suspicious, imprisoned
    SPYF_CAUGHT_TORTURED,     // 81-95: caught with proof, tortured
    SPYF_KILLED_OR_TURNED,    // 96-00: killed or turns coat
    SPYF_COUNT
};

inline SpyFailureResult spyFailureResult(int d100) {
    if (d100 < 36) return SPYF_RETRY;
    if (d100 < 61) return SPYF_COMPROMISED_90;
    if (d100 < 81) return SPYF_IMPRISONED_SILENT;
    if (d100 < 96) return SPYF_CAUGHT_TORTURED;
    return SPYF_KILLED_OR_TURNED;
}

// The failure-score modifiers: a difficult
// mission +10, an extraordinary mission -5,
// and a discovered spy +25 (the same table
// reads the discovery).
inline int spyFailureScoreAdj(SpyCategory c, bool discovered) {
    int adj = 0;
    if (c == SPY_DIFFICULT) adj += 10;
    if (c == SPY_EXTRAORDINARY) adj -= 5;
    if (discovered) adj += 25;
    return adj;
}

// -----------------------------------------------------------------------
// The torture outcomes (the 81-95 band): d6
// 1-2 dead, 3-4 revealed everything, 5-6
// turncoat.
// -----------------------------------------------------------------------
enum SpyTortureOutcome { SPYT_DEAD = 0, SPYT_REVEALED,
                          SPYT_TURNCOAT };

inline SpyTortureOutcome spyTortureOutcome(int d6) {
    if (d6 <= 2) return SPYT_DEAD;
    if (d6 <= 4) return SPYT_REVEALED;
    return SPYT_TURNCOAT;
}

// The 90 percent of the 36-60 band: any
// further spying attempt fails (discovery and
// imprisonment follow)
inline int spyCompromisedFailChance() { return 90; }

// -----------------------------------------------------------------------
// Fanatical spies: absolutely dedicated,
// never double agents; on any dice total
// over 60 they simply kill themselves.
// -----------------------------------------------------------------------
inline bool spyFanaticalNeverDoubleAgent() { return true; }
inline bool spyFanaticalSuicided(int diceTotal) {
    return diceTotal > 60;
}

} // namespace rules
