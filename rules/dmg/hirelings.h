// ===========================================================================
// Adnd1 - rules/dmg/hirelings.h
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

// R-refactor: namespace rules -> class Hirelings (instance methods)
class Hirelings {
public:


// ---- the standard table (10 rows) ----

// The standard row count (the print: 10 occupations).
    int hireStdCount();


// The standard row name at index i (clamped); the
// slash names print as shown.
    const char* hireStdName(int i);


// The daily cost in silver pieces (clamped).
    int hireStdDailySp(int i);


// The monthly cost in gold pieces (clamped; 0 when
// the row prints in silver).
    int hireStdMonthlyGold(int i);


// The monthly cost in silver pieces (clamped; 0 when
// the row prints in gold).
    int hireStdMonthlySilver(int i);


// The craft percent flag (clamped): the
// double-asterisk rows add 10 percent of the usual
// price of items fashioned, per job (carpenter,
// leather worker, tailor).
    int hireStdPercentOnTop(int i);


// The long-term employment acceptance: 1 in 6 willing
// without a sufficient bonus; a bonus of double or
// treble the daily wage makes 3 in 6 willing (a
// single daily wage is too small).
    int hireStdLongTermSixths(int bonusMultiple);


// ---- the expert table (33 rows) ----

// The expert row count (the print: 14 professions and
// the 19-row mercenary soldier block).
    int hireExpCount();


// The expert row name at index i (clamped); the print
// parenthetical weapons read as commas (the R300
// convention).
    const char* hireExpName(int i);


// The monthly cost in gold pieces (clamped); -1 pins
// the special rows (the cost is negotiated, not
// fixed).
    int hireExpCost(int i);


// The mercenary soldier block: rows 7-25, the print
// order (the block sits between jeweler-gemcutter
// and sage).
    int hireExpMercenaryFirst();
    int hireExpMercenaryCount();


// The mercenary block membership at row i (clamped).
    int hireExpIsMercenary(int i);


// The special-cost row flag (clamped): -1 reads
// special.
    int hireExpIsSpecial(int i);


// The asterisk flag (clamped): the rows that add 10
// percent of the usual price of items handled or
// made, per job - the four 100 g.p. rows.
    int hireExpPercentOnTop(int i);
};
