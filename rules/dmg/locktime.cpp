// R-refactor: split from locktime.h - definitions
#include "rules/dmg/locktime.h"

int Locktime::thfLocksPickRoundsMin() {
    // the printed band floor: a lock can
    // take from 1 round
    return 1;
}

int Locktime::thfLocksPickRoundsMax() {
    // the printed band ceiling: up to 10
    // rounds, on the complexity of the lock
    return 10;
}

int Locktime::thfLocksPickRoundsTypicalMax() {
    // most locks take but 1-4 rounds
    return 4;
}

int Locktime::thfTrapsTimeRidesLocks() {
    // the traps print: use the time
    // requirements for opening locks; time
    // counts for each function
    return 1;
}

int Locktime::doorWoodAlwaysMetalBound() {
    // the doors prose: wooden doors are
    // always metal bound
    return 1;
}

int Locktime::doorMetalUsuallyLocked() {
    // the doors prose: metal doors are
    // usually locked
    return 1;
}

int Locktime::doorLockedPerDelveCount() {
    // JUDGMENT: the print carries no count;
    // one locked door per delve (the R45
    // placement convention)
    return 1;
}
