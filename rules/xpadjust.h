// ============================================================================
// Adnd1 - rules/xpadjust.h
// The prime requisite XP adjustment (R188).
//
// The printed per-class +10% of earned experience gates,
// every one from the PHB class sections:
//   fighter      strength 16 or more
//   magic-user   intelligence 16 or more
//   cleric       wisdom 16 or more (worked example:
//                975 XP, +98, total 1073)
//   thief        dexterity 16 or more
//   paladin      strength AND wisdom both above 15
//   ranger       strength, intelligence AND wisdom
//                all above 15
//   druid        wisdom AND charisma both above 15
//   illusionist  never (the print)
//   assassin     never (the print)
//   monk         never (the print)
//
// JUDGMENTs:
//   - every gate pins at 16 or more (the print says
//     above 15, 16 or more, or in excess of 15 - one
//     convention across the sections).
//   - the bonus rounds UP on fractions: the printed
//     example 975 x .10 = 97.5, or 98 XP, total 1073.
//     The formula is (awarded + 9) / 10, the ceiling of
//     one tenth.
//   - the engine ladder primeRequisitePct
//     (rules/character.cpp: +10, +5, 0, -10, -20
//     percent by score) is VERIFIED as to its +10 rung
//     only. The +5, 0, -10 and -20 rungs are ENGINE
//     CONVENTION, unsourced against the 1e print: the
//     PHB class sections carry only the +10 percent
//     notes, the DMG ADJUSTMENT AND DIVISION OF
//     EXPERIENCE POINTS section has no prime-requisite
//     ladder, and the phrase prime requisite does not
//     appear in the DMG at all. The character.cpp
//     comment records this verify (the R188 note).
//   - multi-classed characters divide earned experience
//     evenly before any bonus (the R185 XP rule); the
//     per-class gates here are per single class.
//
// DATA-DRIVEN (the standing scope).
// ============================================================================

#pragma once

#include "classes.h"
#include "subclasses.h"

#include <cstdint>

namespace rules {

// ---- the base-class gates (+10% of earned) ----

// True when the class earns the +10% bonus: fighter
// STR, magic-user INT, cleric WIS, thief DEX - each
// 16 or more. Any other index: false.
inline bool xpBonusQualifiesBase(int classIndex,
                             int str, int int_,
                             int wis, int dex) {
    switch (classIndex) {
        case CLASS_FIGHTER:    return str >= 16;
        case CLASS_MAGIC_USER: return int_ >= 16;
        case CLASS_CLERIC:     return wis >= 16;
        case CLASS_THIEF:      return dex >= 16;
    }
    return false;
}

// The +10 percent when the base-class gate holds,
// else 0.
inline int baseXpBonusPct(int classIndex,
                       int str, int int_,
                       int wis, int dex) {
    return xpBonusQualifiesBase(classIndex, str, int_,
                               wis, dex) ? 10 : 0;
}

// ---- the subclass gates ----

// True when the subclass earns the +10% bonus:
// paladin STR and WIS; ranger STR, INT and WIS;
// druid WIS and CHA - each 16 or more.
// Illusionist, assassin and monk NEVER (the print).
inline bool xpBonusQualifiesSubclass(int sub,
                                 int str, int int_,
                                 int wis, int cha) {
    switch (sub) {
        case SUB_PALADIN:
            return str >= 16 && wis >= 16;
        case SUB_RANGER:
            return str >= 16 && int_ >= 16 && wis >= 16;
        case SUB_DRUID:
            return wis >= 16 && cha >= 16;
    }
    return false;   // illusionist, assassin, monk
}

// The +10 percent when the subclass gate holds,
// else 0.
inline int subclassXpBonusPct(int sub,
                          int str, int int_,
                          int wis, int cha) {
    return xpBonusQualifiesSubclass(sub, str, int_,
                                  wis, cha) ? 10 : 0;
}

// ---- the worked-example rounding ----

// The +10% bonus amount, fractions rounding UP
// (the printed example: 975 x .10 = 97.5, or 98).
inline int xpBonusAmount(int awardedXp) {
    if (awardedXp <= 0) return 0;
    return (awardedXp + 9) / 10;
}

// The total with the bonus (the printed example:
// 975 -> 98 -> 1073).
inline int xpBonusTotal(int awardedXp) {
    return awardedXp + xpBonusAmount(awardedXp);
}

} // namespace rules
