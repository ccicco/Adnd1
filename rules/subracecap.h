// ===========================================================================
// Adnd1 - rules/subracecap.h
// The UA Race Table II caller seam (R325)
// - the level-up site's derived cap read.
//
// The print (UA p.8): the sub-table level
// limits key on the class's vital ability
// - fighters, rangers and assassins read
// strength; clerics and druids read
// wisdom; magic-users and illusionists
// read intelligence; thieves read
// dexterity - and a single-classed
// character whose class could have been
// a multi-class choice for the race
// exceeds the column by 2 (the Important
// paragraph). The engine name-level cap
// still binds above a UA limit that
// exceeds it.
// ===========================================================================

#pragma once

#include "subracelevels.h"   // the columns
#include "subclasses.h"      // the registry ids
#include "multiclass.h"      // the combo bits

namespace rules {

// The vital ability a Race Table II
// column keys on (the p.8 read).
inline int uaColumnAbility(UaClass c) {
    switch (c) {
        case UACLASS_CLERIC:
        case UACLASS_DRUID:
            return ABILITY_WIS;
        case UACLASS_MAGIC_USER:
        case UACLASS_ILLUSIONIST:
            return ABILITY_INT;
        case UACLASS_THIEF:
        case UACLASS_ACROBAT:
            return ABILITY_DEX;
        default:
            // the fighter group: fighter,
            // ranger, assassin (cavalier and
            // barbarian carry no column)
            return ABILITY_STR;
    }
}

// The column key from live scores: the
// vital ability's score*1000, strength
// through the exceptional encoder (no
// exceptional roll reads the plain 18
// row).
inline int uaColumnKey(UaClass c,
                       const AbilityScores& a,
                       const ExceptionalStrength& ex) {
    switch (uaColumnAbility(c)) {
        case ABILITY_WIS:
            return a.wis*1000;
        case ABILITY_INT:
            return a.int_*1000;
        case ABILITY_DEX:
            return a.dex*1000;
        default:
            return subraceStrengthLevelKey(
                a.str,
                ex.has ? (int)ex.pct : -1);
    }
}

// The multi-class bit of a UA class (0 =
// never a multi-class choice: cavalier,
// paladin, barbarian, druid, acrobat,
// monk, bard).
inline int uaClassBit(UaClass c) {
    switch (c) {
        case UACLASS_FIGHTER:
            return MC_FIGHTER;
        case UACLASS_MAGIC_USER:
            return MC_MAGIC_USER;
        case UACLASS_CLERIC:
            return MC_CLERIC;
        case UACLASS_THIEF:
            return MC_THIEF;
        case UACLASS_ILLUSIONIST:
            return MC_ILLUSIONIST;
        case UACLASS_RANGER:
            return MC_RANGER;
        case UACLASS_ASSASSIN:
            return MC_ASSASSIN;
        default:
            return 0;
    }
}

// The print's +2 eligibility leg (b): the
// class could be a multi-classed choice
// for the character's race - some printed
// combo of the parent race carries the
// class bit.
inline bool uaBonusEligible(CharSubRace s,
                            UaClass c) {
    int bit = uaClassBit(c);
    if (bit == 0) return false;
    int race = (int)subraceParentRace(s);
    for (int i = 0;
         i < multiClassComboCount(race); ++i)
        if (multiClassCombo(race, i) & bit)
            return true;
    return false;
}

// The UA class of an engine member: the
// registry subclass when set, else the
// base class (the R230 runtime-base
// convention).
inline UaClass uaClassOfMember(int classIndex,
                               int subclass) {
    switch (subclass) {
        case SUB_PALADIN:
            return UACLASS_PALADIN;
        case SUB_RANGER:
            return UACLASS_RANGER;
        case SUB_DRUID:
            return UACLASS_DRUID;
        case SUB_ILLUSIONIST:
            return UACLASS_ILLUSIONIST;
        case SUB_ASSASSIN:
            return UACLASS_ASSASSIN;
        case SUB_MONK:
            return UACLASS_MONK;
        default: break;
    }
    switch (classIndex) {
        case 1: return UACLASS_MAGIC_USER;
        case 2: return UACLASS_CLERIC;
        case 3: return UACLASS_THIEF;
        default: return UACLASS_FIGHTER;
    }
}

// The level-up fold: the member's cap
// reads the Race Table II column of the
// sub-race and class. No column (-1) or
// a U read (0) leaves the engine cap; a
// pinned limit rides the +2 rule when
// the member is single-classed and the
// class is a multi-class choice for the
// race; the engine cap still binds
// above. The female flag selects
// the printed female columns (the
// dark-elf split; every other
// sub-race reads the same column).
inline int uaLevelCap(int baseCap,
                      CharSubRace s,
                      UaClass c,
                      const AbilityScores& a,
                      const ExceptionalStrength& ex,
                      int multiMask,
                      int female = 0) {
    if (s == SUB_NONE || s == SUB_HUMAN)
        return baseCap;
    int limit = subraceLevelLimit(
        s, c, uaColumnKey(c, a, ex),
        female);
    if (limit <= 0) return baseCap;
    if (multiMask == 0 && uaBonusEligible(s, c))
        limit += singleClassLevelBonus();
    return limit < baseCap ? limit : baseCap;
}

}   // namespace rules
