// rules/startmoney.h - the starting money by
// class (the PHB MONEY section, R190).
//
// The printed STARTING MONEY table: every
// class entry is a dice roll TIMES 10 gold
// pieces - cleric 3d6 (30-180 gp), fighter
// 5d4 (50-200), magic-user 2d4 (20-80),
// thief 2d6 (20-120) - except the printed
// MONK row 5-20 gp (5d4), the one entry
// with NO x10. The DMG MONEY section says
// why: monks are ascetics who do not care
// about material possessions and so do
// not accumulate much money prior to
// becoming adventurers.
//
// The engine has no party-creation money
// code; this header is the pin. Subclass
// starting money is NOT printed anywhere in
// the PHB - the paladin and ranger sections
// carry no money note (recorded; any
// subclass convention stays a caller
// judgment).

#ifndef RULES_STARTMONEY_H
#define RULES_STARTMONEY_H

namespace rules {

// The dice count of the starting money roll,
// in CharClass order (fighter, magic-user,
// cleric, thief).
inline int startingMoneyDiceCount(int cls) {
    static const int kCount[4] = {
        5,
        2,
        3,
        2,
    };
    if (cls < 0) cls = 0;
    if (cls > 3) cls = 3;
    return kCount[cls];
}

// The die faces of the starting money roll.
inline int startingMoneyDieFaces(int cls) {
    static const int kFaces[4] = {
        4,
        4,
        6,
        6,
    };
    if (cls < 0) cls = 0;
    if (cls > 3) cls = 3;
    return kFaces[cls];
}

// The gold multiplier: 10 for every printed
// class row.
inline int startingMoneyMultiplier(int cls) {
    static const int kMult[4] = {
        10,
        10,
        10,
        10,
    };
    if (cls < 0) cls = 0;
    if (cls > 3) cls = 3;
    return kMult[cls];
}

// The minimum starting gold: dice count x
// multiplier.
inline int startingMoneyMin(int cls) {
    return startingMoneyDiceCount(cls)
           * startingMoneyMultiplier(cls);
}

// The maximum starting gold: dice count x
// die faces x multiplier.
inline int startingMoneyMax(int cls) {
    return startingMoneyDiceCount(cls)
           * startingMoneyDieFaces(cls)
           * startingMoneyMultiplier(cls);
}

// ---- the monk row (the print: 5-20 gp,
// 5d4, NO x10) ----

inline int monkStartingMoneyDiceCount() { return 5; }
inline int monkStartingMoneyDieFaces() { return 4; }
inline int monkStartingMoneyMultiplier() { return 1; }
inline int monkStartingMoneyMin() { return 5; }
inline int monkStartingMoneyMax() { return 20; }

// ---- the DMG companion (the PLAYER
// CHARACTER EXPENSES rule) ----

// Not less than 100 gold pieces per level
// of experience per month - support, upkeep,
// equipment and entertainment, deducted
// automatically (the DMG MONEY section).
inline int pcMonthlySupportCost(int level) {
    if (level < 1) level = 1;
    return 100 * level;
}

} // namespace rules

#endif // RULES_STARTMONEY_H
