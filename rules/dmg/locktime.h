// ====================================================================
// Adnd1 - rules/dmg/locktime.h
// R304: the DMG THIEF ABILITIES time pins
// and the FIRST DUNGEON ADVENTURE doors
// prose - a DATA pin (the grenade.h
// pattern), WIRED R304: the locked-door
// site draws the pick time and places the
// per-delve door.
//
// The CHARACTER CLASSES THIEF ABILITIES
// print: opening a lock "can take from
// 1-10 rounds, depending on the complexity
// of the lock" and most locks take "but
// 1-4 rounds of time to pick"; finding
// and removing traps "use the time
// requirements for opening locks. Time
// counts for each function." The doors
// print (the FIRST DUNGEON ADVENTURE):
// wooden doors are "always metal bound"
// and metal doors are "usually locked" -
// the engine dungeon doors carry no lock
// layer, so the count pins as a JUDGMENT:
// one locked door per delve (the print
// carries no count; the R45 placement
// convention).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Locktime (instance methods)
class Locktime {
public:
    int thfLocksPickRoundsMin();
    int thfLocksPickRoundsMax();
    int thfLocksPickRoundsTypicalMax();
    int thfTrapsTimeRidesLocks();
    int doorWoodAlwaysMetalBound();
    int doorMetalUsuallyLocked();
    int doorLockedPerDelveCount();
};
