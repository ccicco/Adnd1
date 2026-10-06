// ============================================================================
// Adnd1 - rules/multiclass.h
// The multi-class and dual-class rules (R185).
//
// The per-race MULTI-CLASS combination table (the
// print: dwarf fighter/thief; elf four combos; gnome
// three; half-elf eight; halfling fighter/thief;
// half-orc five; human none), the multi-class hit-
// point quotient (sum the class dice, adjust for
// CON, divide by the class count, drop fractions
// under one half, round one half and up), the even
// XP split among the classes, the stalled-hit-dice
// rule (a class that can no longer progress gives
// no further hit dice), the thief-armor limitation
// (a multi-classed thief functions only with thief
// armor and weaponry), the cleric edged-weapons
// allowance (a multi-classed cleric may use edged
// weapons), the half-elf multi-class cleric WIS
// minimum of 13, and the human-only dual-class
// gates: 15+ in the prime requisite of the original
// class and 17+ in the prime requisite of the new.
//
// JUDGMENTs:
//   - combos pin as class bitmasks; the alphabet is
//     fighter, magic-user, cleric, thief, illusionist,
//     ranger, assassin. Paladin, druid and monk never
//     multi-class (the print lists no such combo).
//   - the XP rule: experience is always divided
//     evenly among the classes of the combination.
//   - dual-class judgment pins only what the print
//     says here: the race gate and the two prime
//     gates, plus the retained hit dice and the
//     negated-XP-on-old-use rule recorded in the
//     comments; the level-exceeds mechanics belong to
//     the engine rounds that consume them.
//
// DATA-DRIVEN (the standing scope): future UA or
// Dragon combos land as appended rows or bits.
// ============================================================================

#pragma once

#include <cstdint>

namespace rules {

// ---- the combo alphabet (class bits) ----

// R233: a named enum (was static const ints) so
// the audit_eval seam reads the same constants.
enum McBits {
    MC_FIGHTER = 1,
    MC_MAGIC_USER = 2,
    MC_CLERIC = 4,
    MC_THIEF = 8,
    MC_ILLUSIONIST = 16,
    MC_RANGER = 32,
    MC_ASSASSIN = 64,
};

// ---- the per-race combination table ----
// Race order: human, dwarf, elf, gnome,
// half-elf, halfling, half-orc (the CharRace
// order). Human has no multi-class combos.

inline int multiClassComboCount(int race) {
    static const int kCount[7] = {
        0,
        1,
        4,
        3,
        8,
        1,
        5,
    };
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    return kCount[race];
}

// The combo bitmask at index i of the race
// list (clamped to the list).
inline int multiClassCombo(int race, int i) {
    static const int kCombos[7][8] = {
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 9, 0, 0, 0, 0, 0, 0, 0 },
        { 3, 9, 10, 11, 0, 0, 0, 0 },
        { 17, 9, 24, 0, 0, 0, 0, 0 },
        { 5, 36, 6, 3, 9, 10, 7, 11 },
        { 9, 0, 0, 0, 0, 0, 0, 0 },
        { 5, 12, 68, 9, 65, 0, 0, 0 },
    };
    int n = multiClassComboCount(race);
    if (n == 0) return 0;
    if (i < 0) i = 0;
    if (i > n - 1) i = n - 1;
    return kCombos[race < 0 ? 0 : (race > 6 ? 6 : race)][i];
}

// True when mask is one of the printed
// combos for the race.
inline bool multiClassAllowed(int race, int mask) {
    if (mask == 0) return false;
    for (int i = 0; i < multiClassComboCount(race); ++i)
        if (multiClassCombo(race, i) == mask) return true;
    return false;
}

// True when the race has any multi-class
// combos at all (false for humans, who
// dual-class instead).
inline bool multiClassPossible(int race) {
    return multiClassComboCount(race) > 0;
}

// ---- the hit-point and XP machinery ----

// The multi-class hit-point quotient: the
// rolled dice of all classes plus the CON
// adjustment, divided by the class count;
// fractions under one half drop, one half
// and up rounds up (PHB: hit points are
// determined by dividing the sum by the
// number of classes, dropping fractions
// under 1/2, rounding 1/2 and up).
inline int multiclassHpQuotient(int rolledTotal,
                               int nClasses) {
    if (nClasses < 1) nClasses = 1;
    return (2 * rolledTotal + nClasses)
           / (2 * nClasses);
}

// The XP rule: experience is always
// divided evenly among the classes (any
// remainder is not earned while the
// division is even in play).
inline int multiclassXpShare(int totalXp,
                            int nClasses) {
    if (nClasses < 1) nClasses = 1;
    return totalXp / nClasses;
}

// The stalled-hit-dice rule: a class that
// can no longer progress (its level has
// reached the cap) contributes no further
// hit dice to the quotient.
inline bool multiclassHitDieStalled(int classLevel,
                                    int levelCap) {
    return classLevel >= levelCap;
}

// ---- the printed multi-class allowances ----

// A multi-classed thief functions only with
// thief armor and weaponry (the limitation of
// the thief class only).
inline bool multiclassThiefLimited(int mask) {
    return (mask & MC_THIEF) != 0;
}

// A multi-classed cleric may use edged
// weapons (the print).
inline bool multiclassClericEdgedOk(int mask) {
    return (mask & MC_CLERIC) != 0;
}

// The half-elf multi-class cleric WIS
// minimum: 13 (vs the single-class 9).
inline int halfelfClericWisMin() {
    return 13;
}

// ---- the dual-class gates (human only) ----

static const int DUAL_CLASS_OLD_PRIME_MIN = 15;
static const int DUAL_CLASS_NEW_PRIME_MIN = 17;

// True only for humans (the print: humans
// may not multi-class; they may change class).
inline bool dualClassRaceAllowed(int race) {
    return race == 0;
}

// The prime gates: 15+ in the prime
// requisite of the original class, 17+ in
// the prime requisite of the new class.
inline bool dualClassPrimeGate(int oldPrime,
                              int newPrime) {
    return oldPrime >= DUAL_CLASS_OLD_PRIME_MIN
           && newPrime >= DUAL_CLASS_NEW_PRIME_MIN;
}

// The printed example, pinned: a 6th-level
// fighter switches to magic-user - the six
// d10 hit dice and hit points are retained,
// all functions begin at 1st level in the
// new class, and using old-class capabilities
// during an adventure negates the XP earned
// for it; once the new-class level exceeds
// the old, the character gains the new-class
// hit die per level up to its class maximum
// and may mix functions freely (each class
// restrictions to its own armor and weapons).
// (Recorded as comments: engine rounds
// consume these mechanics.)

// ---- the R233 engine seam (plain ints, pure
// expressions - the R230 evaluable-subset
// convention: no while, no mutation, no bitwise
// ops; the modulo ladder reads each bit) ----

// The combo class count (the set-bit count).
inline int multiClassCount(int mask) {
    return (mask % 2 == 1 ? 1 : 0)
         + (mask % 4 >= 2 ? 1 : 0)
         + (mask % 8 >= 4 ? 1 : 0)
         + (mask % 16 >= 8 ? 1 : 0)
         + (mask % 32 >= 16 ? 1 : 0)
         + (mask % 64 >= 32 ? 1 : 0)
         + (mask % 128 >= 64 ? 1 : 0);
}

// The i-th set bit of the mask, low to high (the
// fighter bit first - the primary-class order).
// The below-counts c1..c6 say how many set bits
// sit below each bit; a bit fires as the i-th
// when its below-count equals i.
inline int multiClassBitAt(int mask, int i) {
    int c1 = mask % 2;
    int c2 = c1 + (mask % 4 >= 2 ? 1 : 0);
    int c3 = c2 + (mask % 8 >= 4 ? 1 : 0);
    int c4 = c3 + (mask % 16 >= 8 ? 1 : 0);
    int c5 = c4 + (mask % 32 >= 16 ? 1 : 0);
    int c6 = c5 + (mask % 64 >= 32 ? 1 : 0);
    return (mask % 2 == 1 && i == 0 ? 1 : 0)
         + (mask % 4 >= 2 && i == c1 ? 2 : 0)
         + (mask % 8 >= 4 && i == c2 ? 4 : 0)
         + (mask % 16 >= 8 && i == c3 ? 8 : 0)
         + (mask % 32 >= 16 && i == c4 ? 16 : 0)
         + (mask % 64 >= 32 && i == c5 ? 32 : 0)
         + (mask % 128 >= 64 && i == c6 ? 64 : 0);
}

// The runtime base class (CLASS_*) of a bit: the
// illusionist rides the magic-user tables, the
// ranger the fighter tables, the assassin the
// thief tables (the R230 runtime-base convention).
inline int multiClassBaseOfBit(int bit) {
    return bit == MC_MAGIC_USER ? 1
         : bit == MC_CLERIC ? 2
         : bit == MC_THIEF ? 3
         : bit == MC_ILLUSIONIST ? 1
         : bit == MC_ASSASSIN ? 3
         : 0;
}

// The registry subclass of a bit (-1 = a plain
// base class; plain ints - the SUB_* values in the
// subclasses.h order).
inline int multiClassSubOfBit(int bit) {
    return bit == MC_ILLUSIONIST ? 3
         : bit == MC_RANGER ? 1
         : bit == MC_ASSASSIN ? 4
         : -1;
}

} // namespace rules
