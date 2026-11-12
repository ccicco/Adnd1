// R-refactor: split from doorforce.h - definitions
#include "rules/dmg/doorforce.h"

int Doorforce::doorForceTypicalMin() {
    // the typical band floor: a roll of 1
    // indicates success
    return 1;
}

int Doorforce::doorForceTypicalMax() {
    // the typical band ceiling: a 2 still
    // opens (anything above does not)
    return 2;
}

int Doorforce::doorVeryHeavyHalvesChances() {
    // very heavy doors might reduce the
    // chances by half
    return 1;
}

int Doorforce::doorLockedSimultaneousOnes() {
    // JUDGMENT: locked doors need two or
    // even three simultaneous 1s - the band
    // pins at two
    return 2;
}

int Doorforce::doorWidthStandardAttempts() {
    // the standard door allows up to three
    // characters to attempt opening
    return 3;
}

int Doorforce::doorNarrowWidthAttempts() {
    // a door of 3 feet or less allows but a
    // single character to make an attempt
    return 1;
}

int Doorforce::doorWoodBreakFullTurn() {
    // breaking a metal-bound wooden door
    // takes a full turn
    return 1;
}

int Doorforce::doorWoodBreakMonsterChecks() {
    // the break noise draws at least 3
    // checks for nearby monsters
    return 3;
}

int Doorforce::doorMetalNeedsKnock() {
    // metal doors need a knock spell or
    // similar means most of the time
    return 1;
}
