// ===========================================================================
// Adnd1 - rules/hirelings.h
// The hirelings cost tables (R309).
//
// The DMG HIRELINGS section (the STANDARD HIRELINGS
// TABLE OF DAILY AND MONTHLY COSTS, upload line 1817;
// the EXPERT HIRELINGS TABLE OF MONTHLY COSTS IN GOLD
// PIECES, upload line 1873): the standard table - 10
// rows, every daily cost in silver pieces and every
// monthly cost in its printed coin (gold or silver,
// exactly one monthly column nonzero per row) - and
// the expert table - 33 rows, the 14 professions
// around the 19-row mercenary soldier block (the
// block sits between jeweler-gemcutter and sage, the
// print order). The special-cost rows pin as -1 (the
// cost is negotiated: captain, lieutenant, serjeant,
// sage, ship crew, ship master, spy,
// steward/castellan). The asterisk rows (armorer,
// engineer-architect, jeweler-gemcutter, weapon maker
// - the four 100 g.p. rows) and the standard
// double-asterisk rows (carpenter, leather worker,
// tailor) pay 10 percent of the usual price of items
// fashioned or handled on top, per job. The standard
// monthly rate assumes quarters with a bed. The
// standard employment bands: a long-term offer draws
// 1 in 6 willing without a sufficient bonus; a double
// or treble daily-wage bonus makes 3 in 6 willing.
//
// SOURCE NOTE: the 1eonline.info compilation
// cross-read agrees on every cell of both tables but
// adds two rows it sources to OSRIC (cook, groom) -
// compilation additions, not the print; excluded per
// the R211 ground-truth rule.
//
// The description prose rides this pin as recorded
// notes: the armorer skill bands (01-50 ring scale or
// studded, 51-75 plus splint, 76-90 plus chain, 91-00
// any) and manufacture times, one armorer per 40
// soldiers with the spare-time prorate and the
// 310-400 g.p. workroom, the blacksmith 40/160
// coverage and monthly output, the jeweler value
// bands, the alchemist attraction terms, the engineer
// fees and the race efficiency and cost multipliers.
// No engine site charges any of this yet (no
// stronghold hiring layer exists; the town stores
// price canonically).
//
// DATA-DRIVEN (the standing scope).
// ===========================================================================

#pragma once

namespace rules {

// ---- the standard table (10 rows) ----

// The standard row count (the print: 10 occupations).
inline int hireStdCount() {
    return 10;
}

// The standard row name at index i (clamped); the
// slash names print as shown.
inline const char* hireStdName(int i) {
    static const char* const kNames[10] = {
        "bearer/porter",
        "carpenter",
        "leather worker",
        "limner",
        "linkboy",
        "mason",
        "pack handler",
        "tailor",
        "teamster",
        "valet/lackey",
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return kNames[i];
}

// The daily cost in silver pieces (clamped).
inline int hireStdDailySp(int i) {
    static const int kDaily[10] = {
           1,    3,    2,   10,    1,    4,    2,    2,    5,    3,
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return kDaily[i];
}

// The monthly cost in gold pieces (clamped; 0 when
// the row prints in silver).
inline int hireStdMonthlyGold(int i) {
    static const int kGold[10] = {
           1,    2,    0,   10,    1,    3,    0,    0,    5,    0,
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return kGold[i];
}

// The monthly cost in silver pieces (clamped; 0 when
// the row prints in gold).
inline int hireStdMonthlySilver(int i) {
    static const int kSilver[10] = {
           0,    0,   30,    0,    0,    0,   30,   30,    0,   50,
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return kSilver[i];
}

// The craft percent flag (clamped): the
// double-asterisk rows add 10 percent of the usual
// price of items fashioned, per job (carpenter,
// leather worker, tailor).
inline int hireStdPercentOnTop(int i) {
    static const int kPct[10] = {
           0,    1,    1,    0,    0,    0,    0,    1,    0,    0,
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return kPct[i];
}

// The long-term employment acceptance: 1 in 6 willing
// without a sufficient bonus; a bonus of double or
// treble the daily wage makes 3 in 6 willing (a
// single daily wage is too small).
inline int hireStdLongTermSixths(int bonusMultiple) {
    if (bonusMultiple >= 2) return 3;
    return 1;
}

// ---- the expert table (33 rows) ----

// The expert row count (the print: 14 professions and
// the 19-row mercenary soldier block).
inline int hireExpCount() {
    return 33;
}

// The expert row name at index i (clamped); the print
// parenthetical weapons read as commas (the R300
// convention).
inline const char* hireExpName(int i) {
    static const char* const kNames[33] = {
        "alchemist",
        "armorer",
        "blacksmith",
        "engineer-architect",
        "engineer-artillerist",
        "engineer-sapper/miner",
        "jeweler-gemcutter",
        "archer, longbow",
        "archer, shortbow",
        "artillerist",
        "captain",
        "crossbowman",
        "footman, heavy",
        "footman, light",
        "footman, pikeman",
        "hobilar, heavy",
        "hobilar, light",
        "horseman, archer",
        "horseman, crossbowman",
        "horseman, heavy",
        "horseman, light",
        "horseman, medium",
        "lieutenant",
        "sapper/miner",
        "serjeant",
        "slinger",
        "sage",
        "scribe",
        "ship crew",
        "ship master",
        "spy",
        "steward/castellan",
        "weapon maker",
    };
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    return kNames[i];
}

// The monthly cost in gold pieces (clamped); -1 pins
// the special rows (the cost is negotiated, not
// fixed).
inline int hireExpCost(int i) {
    static const int kCost[33] = {
         300,  100,   30,  100,  150,  150,  100,    4,    2,    5,
          -1,    2,    2,    1,    3,    3,    2,    6,    4,    6,
           3,    4,   -1,    4,   -1,    3,   -1,   15,   -1,   -1,
          -1,   -1,  100,
    };
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    return kCost[i];
}

// The mercenary soldier block: rows 7-25, the print
// order (the block sits between jeweler-gemcutter
// and sage).
inline int hireExpMercenaryFirst() {
    return 7;
}

inline int hireExpMercenaryCount() {
    return 19;
}

// The mercenary block membership at row i (clamped).
inline int hireExpIsMercenary(int i) {
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    if (i >= 7 && i <= 25) return 1;
    return 0;
}

// The special-cost row flag (clamped): -1 reads
// special.
inline int hireExpIsSpecial(int i) {
    return hireExpCost(i) < 0;
}

// The asterisk flag (clamped): the rows that add 10
// percent of the usual price of items handled or
// made, per job - the four 100 g.p. rows.
inline int hireExpPercentOnTop(int i) {
    static const int kPct[33] = {
           0,    1,    0,    1,    0,    0,    1,    0,    0,    0,
           0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
           0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
           0,    0,    1,
    };
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    return kPct[i];
}

}  // namespace rules
