// ====================================================================
// Adnd1 - rules/dmg/spying.h
// R205: the spying tables (DMG pp.19-20, the
// SPYING section after the assassin guild
// tables) - the lane rules/dmg/assassinate.h
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



// -----------------------------------------------------------------------
// The three mission categories (the print order)
// -----------------------------------------------------------------------
enum SpyCategory {
    SPY_SIMPLE = 0,
    SPY_DIFFICULT,
    SPY_EXTRAORDINARY,
    SPY_CATEGORY_COUNT
};



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



// -----------------------------------------------------------------------
// The torture outcomes (the 81-95 band): d6
// 1-2 dead, 3-4 revealed everything, 5-6
// turncoat.
// -----------------------------------------------------------------------
enum SpyTortureOutcome { SPYT_DEAD = 0, SPYT_REVEALED,
                          SPYT_TURNCOAT };

// R-refactor: namespace rules -> class Spying (instance methods)
class Spying {
public:
    const char* spyCategoryName(SpyCategory c);


// -----------------------------------------------------------------------
// The ASSASSIN SPYING TABLE: the chance of
// success by spy level (1-17) and category.
// -----------------------------------------------------------------------
    int spySuccessChance(int level, SpyCategory c);


// The hired-spy level cap (the print: never
// more proficient at spying than 8th level)
    int spyHiredLevelCap();


// -----------------------------------------------------------------------
// Time required to accomplish the mission:
// simple 1-8 days, difficult 5-40 days,
// extraordinary as required (0-0 - the caller
// rules the case).
// -----------------------------------------------------------------------
    void spyMissionDays(SpyCategory c, int& lo, int& hi);


// -----------------------------------------------------------------------
// The chance of discovery: the modified percent
// is a cumulative 1 percent per day spent
// spying, capped at 10, minus the spy level,
// and always at least 1 percent (the print:
// even a negative result leaves 1 percent).
// -----------------------------------------------------------------------
    int spyModifiedDiscoveryChance(int daysSpent, int spyLevel);
    int spyPrecautionChecksPerWeek(SpyPrecautions p);


// The percent chance for ONE discovery check
// under the given precautions, given the
// modified percent.
    int spyDiscoveryCheckPercent(SpyPrecautions p, int modifiedPercent);


// The tenfold window: if a spy is caught,
// the chance of discovery increases tenfold
// for any other spy operating during the
// following 20 to 50 days.
    int spyPostCaptureWindowLo();
    int spyPostCaptureWindowHi();
    int spyPostCaptureChanceMultiple();
    SpyFailureResult spyFailureResult(int d100);


// The failure-score modifiers: a difficult
// mission +10, an extraordinary mission -5,
// and a discovered spy +25 (the same table
// reads the discovery).
    int spyFailureScoreAdj(SpyCategory c, bool discovered);
    SpyTortureOutcome spyTortureOutcome(int d6);


// The 90 percent of the 36-60 band: any
// further spying attempt fails (discovery and
// imprisonment follow)
    int spyCompromisedFailChance();


// -----------------------------------------------------------------------
// Fanatical spies: absolutely dedicated,
// never double agents; on any dice total
// over 60 they simply kill themselves.
// -----------------------------------------------------------------------
    bool spyFanaticalNeverDoubleAgent();
    bool spyFanaticalSuicided(int diceTotal);
};
