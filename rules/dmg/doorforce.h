// ====================================================================
// Adnd1 - rules/dmg/doorforce.h
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

// R-refactor: namespace rules -> class Doorforce (instance methods)
class Doorforce {
public:
    int doorForceTypicalMin();
    int doorForceTypicalMax();
    int doorVeryHeavyHalvesChances();
    int doorLockedSimultaneousOnes();
    int doorWidthStandardAttempts();
    int doorNarrowWidthAttempts();
    int doorWoodBreakFullTurn();
    int doorWoodBreakMonsterChecks();
    int doorMetalNeedsKnock();
};
