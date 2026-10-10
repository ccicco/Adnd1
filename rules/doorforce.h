// ====================================================================
// Adnd1 - rules/doorforce.h
// R305: the DMG FIRST DUNGEON ADVENTURE
// doors prose - the forcing pins - a DATA
// pin (the grenade.h pattern), WIRED R305:
// the locked-door site draws the width and
// simultaneous folds.
//
// The doors print: each person pushing
// rolls a d6 and "a roll of 1 or 2
// typically indicates success"; very heavy
// doors "might reduce chances by half";
// locked doors "might only open if two or
// even three simultaneous 1s are rolled"
// (JUDGMENT: the band pins at two); the
// standard door "allows up to three
// characters to attempt opening" and a door
// of 3 feet or less "allows but a single
// character"; breaking a metal-bound
// wooden door takes "a full turn" and "at
// least 3 checks" for the noise; metal
// doors need "a knock spell or similar
// means most of the time".
// ====================================================================

#pragma once

namespace rules {

inline int doorForceTypicalMin() {
    // the typical band floor: a roll of 1
    // indicates success
    return 1;
}

inline int doorForceTypicalMax() {
    // the typical band ceiling: a 2 still
    // opens (anything above does not)
    return 2;
}

inline int doorVeryHeavyHalvesChances() {
    // very heavy doors might reduce the
    // chances by half
    return 1;
}

inline int doorLockedSimultaneousOnes() {
    // JUDGMENT: locked doors need two or
    // even three simultaneous 1s - the band
    // pins at two
    return 2;
}

inline int doorWidthStandardAttempts() {
    // the standard door allows up to three
    // characters to attempt opening
    return 3;
}

inline int doorNarrowWidthAttempts() {
    // a door of 3 feet or less allows but a
    // single character to make an attempt
    return 1;
}

inline int doorWoodBreakFullTurn() {
    // breaking a metal-bound wooden door
    // takes a full turn
    return 1;
}

inline int doorWoodBreakMonsterChecks() {
    // the break noise draws at least 3
    // checks for nearby monsters
    return 3;
}

inline int doorMetalNeedsKnock() {
    // metal doors need a knock spell or
    // similar means most of the time
    return 1;
}

}  // namespace rules
