// ====================================================================
// Adnd1 - rules/weaponprof.h
// R297: the PHB Weapon Proficiency Table
// (the WEAPONS section, Premium 1e OCR
// upload line 2499) - the ten printed class
// rows: the initial number of weapons, the
// non-proficiency to-hit penalty and the
// added-proficiency cadence, plus the
// mapping from the engine class pair (the
// base CharClass and the registry Subclass)
// to the printed row, and the
// non-proficiency to-hit adjustment seam the
// combat layer folds into Actor::hitAdjustment
// (ai/actor.cpp).
//
// The printed rows (the table top to bottom):
//   CLERIC      2 slots, -3 penalty, 1 per 4 levels
//   Druid       2, -4, 1 per 5
//   FIGHTER     4, -2, 1 per 3
//   Paladin     3, -2, 1 per 3
//   Ranger      3, -2, 1 per 3
//   MAGIC-USER  1, -5, 1 per 6
//   Illusionist 1, -5, 1 per 6
//   THIEF       2, -3, 1 per 4
//   Assassin    3, -2, 1 per 4
//   MONK        1, -3, 1 per 2
//
// The printed notes (upload lines 2491-2497):
//   - proficiency with a normal weapon is
//     subsumed in using a magical weapon of the
//     same type (wpfNoteSubsumption);
//   - the penalty applies to attacks in missile
//     or melee combat (wpfNoteMeleeMissile);
//   - the added proficiency arrives at the
//     printed number of LEVELS ABOVE THE 1ST
//     (the cleric example: two weapons at 1st,
//     three at 5th, four at 9th, five at 13th -
//     wpfSlotsAt and wpfNoteAddedAboveFirst).
//
// Conventions:
//   - wpfNonProfPenalty returns the MAGNITUDE
//     (2..5); the to-hit adjustment is negative
//     (wpfNonProfHitAdj).
//   - the row enum follows the PRINTED row order.
//   - the engine carries four base classes plus
//     six registry subclasses; wpfRowFor picks
//     the subclass row when the registry
//     subclass is set, else the base row (an
//     unknown subclass index falls back to the
//     base row - the attackNumber default-class
//     convention).
//   - the slot COUNTS are data (the engine
//     records no choices beyond the kit grants;
//     the party roster records its class kit at
//     creation - R299); the PENALTY is
//     live wiring (Actor::hitAdjustment pays it
//     when a recorded list excludes the held
//     weapon). The monk open hand stays flat 0
//     (the R181/R232 pins).
// ====================================================================

#pragma once

namespace rules {

// The printed row order (the table top to bottom).
enum ProfRow {
    PROF_CLERIC = 0,
    PROF_DRUID,
    PROF_FIGHTER,
    PROF_PALADIN,
    PROF_RANGER,
    PROF_MAGIC_USER,
    PROF_ILLUSIONIST,
    PROF_THIEF,
    PROF_ASSASSIN,
    PROF_MONK
};

inline int wpfRowCount() {
    // the ten printed class rows
    return 10;
}

inline int wpfInitialSlots(int row) {
    // the initial number of weapons; row clamps
    if (row < 0) row = 0;
    if (row > 9) row = 9;
    static const int t[10] = {
        2, 2, 4, 3, 3, 1, 1, 2, 3, 1,
    };
    return t[row];
}

inline int wpfNonProfPenalty(int row) {
    // the non-proficiency to-hit penalty MAGNITUDE
    if (row < 0) row = 0;
    if (row > 9) row = 9;
    static const int t[10] = {
        3, 4, 2, 2, 2, 5, 5, 3, 2, 3,
    };
    return t[row];
}

inline int wpfAddedCadence(int row) {
    // the added-proficiency levels-per-slot
    if (row < 0) row = 0;
    if (row > 9) row = 9;
    static const int t[10] = {
        4, 5, 3, 3, 3, 6, 6, 4, 4, 2,
    };
    return t[row];
}

inline int wpfSlotsAt(int row, int level) {
    // the slots at a level: the initial number
    // plus one per completed cadence of levels
    // above the 1st (the printed cleric
    // example: 2 at 1st, 3 at 5th, 4 at 9th,
    // 5 at 13th); the level clamps at 1
    if (level < 1) level = 1;
    return wpfInitialSlots(row) +
           (level - 1) / wpfAddedCadence(row);
}

inline int wpfRowForBase(int classIndex) {
    // the base CharClass to the printed row
    // (the fighter default matches attackNumber)
    if (classIndex == 1) return 5;   // magic-user
    if (classIndex == 2) return 0;   // cleric
    if (classIndex == 3) return 7;   // thief
    return 2;                        // fighter
}

inline int wpfRowForSubclass(int sub) {
    // the registry Subclass to the printed row;
    // -1 = a plain class member (no subclass row)
    if (sub == 0) return 3;   // paladin
    if (sub == 1) return 4;   // ranger
    if (sub == 2) return 1;   // druid
    if (sub == 3) return 6;   // illusionist
    if (sub == 4) return 8;   // assassin
    if (sub == 5) return 9;   // monk
    return -1;
}

inline int wpfRowFor(int classIndex, int subclass) {
    // the engine class pair to the printed row:
    // the subclass row wins when the registry
    // subclass is set, else the base row
    if (wpfRowForSubclass(subclass) >= 0)
        return wpfRowForSubclass(subclass);
    return wpfRowForBase(classIndex);
}

inline int wpfNonProfHitAdj(int classIndex,
                             int subclass) {
    // the to-hit adjustment a non-proficient
    // attacker pays: -2..-5 by class (the
    // Actor::hitAdjustment seam)
    return -wpfNonProfPenalty(
        wpfRowFor(classIndex, subclass));
}

inline int wpfNoteSubsumption() {
    // a magical weapon of the same type
    // subsumes the normal-weapon proficiency
    return 1;
}

inline int wpfNoteMeleeMissile() {
    // the penalty applies in missile or melee
    return 1;
}

inline int wpfNoteAddedAboveFirst() {
    // the added slots count levels above the 1st
    return 1;
}


inline int wpfKitRecordsMelee() {
    // R299: every class kit carries a melee arm
    // - the kit grant records it as an initial
    // proficiency choice (the engine has no
    // choice UI; the added slots stay a future
    // choice round)
    return 1;
}

inline int wpfKitRecordsRanged(int classIndex,
                               int subclass) {
    // R299: the kit missile slot - the thief-base
    // kits carry the sling (the R28 creation pin)
    // and record it; a subclass kit rides its
    // base-class kit (the makeSubclassMember
    // convention; the monk staff is a melee arm).
    // The subclass mapping mirrors
    // subclassRuntimeBase (the agreement is
    // pinned by the R299 battery audit).
    int base = classIndex;
    if (subclass == 2) base = 2;   // druid
    if (subclass == 3) base = 1;   // illusionist
    if (subclass == 4) base = 3;   // assassin
    if (base == 3) return 1;   // the thief sling
    return 0;
}

inline int wpfKitGrantCount(int classIndex,
                            int subclass) {
    // R299: the kit-grant recording count - the
    // melee slot plus the ranged slot when the
    // kit carries one (the Character grant,
    // game/party.h; the engine kit ids are
    // game-layer data, the COUNTS are the seam)
    return wpfKitRecordsMelee() +
           wpfKitRecordsRanged(classIndex, subclass);
}
}  // namespace rules
