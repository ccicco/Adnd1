// ====================================================================
// Adnd1 - rules/poison.h
// R163: the poison table (DMG p.20) - the printed
// poison types: cost, onset, damage classes.
//
// Pure data, header-only (the grenade.h pattern: the
// caller holds the poison lane and rolls the save; the
// monster venom layer keeps its per-monster saves).
//
// The p.20 print:
//   - Purchased poisons are INGESTIVE (grades A-E) or
//     INSINUATIVE (grades A-D). Dual-use poison comes
//     from monsters only; a purchase is one route only.
//   - Per grade the table prints: cost per dose, onset
//     time (in its own unit), damage if the save is
//     made, damage or death if not, the victim save
//     bonus (the footnotes), and the chance of
//     tasting, smelling or seeing the poison.
//   - JUDGMENT: grade E prints no footnotes - it gives
//     no save bonus and no stated detection chance
//     (recorded as 0).
//   - User efficiency: an assassin who has studied
//     poisoning gives no penalty; an unstudied assassin
//     gives +1 on the victim save; every other class
//     gives +2.
//   - Monster poison is all-or-nothing (no damage or
//     death within about a minute) and dual-use; poison
//     potions must be ingested.
//   - Blade venom (DMG p.28): insinuative, evaporation
//     and use decay it the same way - full the first
//     day or hit, half the second, gone by the third;
//     a decayed death poison gives the victim +4 on
//     the save.
// ====================================================================

#pragma once

namespace rules {

// ----------------------------------------------------------------------------
// Routes and grades
// ----------------------------------------------------------------------------

enum PoisonRoute {
    POISON_INGESTIVE = 0,
    POISON_INSINUATIVE = 1
};

// The print counts a segment as 6 seconds and a round as
// 10; the onset UNIT stays per-row here and the caller
// converts.
enum PoisonUnit {
    POISON_UNIT_ROUND = 0,
    POISON_UNIT_TURN = 1,
    POISON_UNIT_SEGMENT = 2
};

// Grade index: 0 = A ... 4 = E. Grade E exists ingestive
// only.
inline bool poisonGradeExists(int route, int grade) {
    if (grade < 0 || grade > 4) return false;
    if (route == POISON_INSINUATIVE) return grade <= 3;
    return true;
}

// ----------------------------------------------------------------------------
// The p.20 table (cost per dose)
// ----------------------------------------------------------------------------

inline int poisonCostPerDose(int route, int grade) {
    if (!poisonGradeExists(route, grade)) return 0;
    static const int kIngestive[5] = { 5, 30, 200, 500, 1000 };
    static const int kInsinuative[4] = { 10, 75, 600, 1500 };
    if (route == POISON_INSINUATIVE) return kInsinuative[grade];
    return kIngestive[grade];
}

// Onset: minimum and maximum on the printed range plus
// the unit the row prints in.
inline int poisonOnsetMin(int route, int grade) {
    static const int kIn[5] = { 2, 2, 1, 1, 1 };
    static const int kIns[4] = { 2, 1, 1, 1 };
    if (!poisonGradeExists(route, grade)) return 0;
    if (route == POISON_INSINUATIVE) return kIns[grade];
    return kIn[grade];
}

inline int poisonOnsetMax(int route, int grade) {
    static const int kIn[5] = { 8, 5, 2, 1, 4 };
    static const int kIns[4] = { 5, 3, 1, 1 };
    if (!poisonGradeExists(route, grade)) return 0;
    if (route == POISON_INSINUATIVE) return kIns[grade];
    return kIn[grade];
}

inline PoisonUnit poisonOnsetUnit(int route, int grade) {
    // ingestive D: 1 segment; ingestive E: 1-4 turns;
    // everything else: rounds
    if (route == POISON_INGESTIVE && grade == 3)
        return POISON_UNIT_SEGMENT;
    if (route == POISON_INGESTIVE && grade == 4)
        return POISON_UNIT_TURN;
    if (!poisonGradeExists(route, grade))
        return POISON_UNIT_ROUND;
    return POISON_UNIT_ROUND;
}

// ----------------------------------------------------------------------------
// Damage classes
// ----------------------------------------------------------------------------

// The victim save bonus (the footnotes: +4/+3/+2/+1;
// E prints none - JUDGMENT: 0).
inline int poisonVictimSaveBonus(int route, int grade) {
    if (!poisonGradeExists(route, grade)) return 0;
    if (grade <= 2) return 4 - grade;
    if (grade == 3) return 1;
    return 0;
}

// The tasting/smelling/seeing chance (80/65/40/15;
// E prints none - JUDGMENT: 0).
inline int poisonDetectChance(int route, int grade) {
    if (!poisonGradeExists(route, grade)) return 0;
    static const int k[5] = { 80, 65, 40, 15, 0 };
    return k[grade];
}

// Damage if the save is made (the ingestive table only;
// every insinuative row prints 0).
inline int poisonDamageIfSave(int route, int grade) {
    if (!poisonGradeExists(route, grade)) return -1;
    if (route == POISON_INSINUATIVE) return 0;
    static const int k[5] = { 10, 15, 20, 25, 30 };
    return k[grade];
}

// A failed save: death (true) or the printed damage.
inline bool poisonKillsIfNoSave(int route, int grade) {
    if (!poisonGradeExists(route, grade)) return false;
    if (route == POISON_INSINUATIVE) return grade == 3;
    return grade >= 3;
}

inline int poisonDamageIfNoSave(int route, int grade) {
    if (poisonKillsIfNoSave(route, grade)) return -1;
    if (!poisonGradeExists(route, grade)) return -1;
    if (route == POISON_INSINUATIVE) {
        static const int k[4] = { 15, 25, 35, 0 };
        return k[grade];
    }
    static const int k[5] = { 20, 30, 40, 0, 0 };
    return k[grade];
}

// ----------------------------------------------------------------------------
// The class rules around the table
// ----------------------------------------------------------------------------

// User efficiency: the bonus the VICTIM gets on the save.
// A studied assassin: none; an unstudied assassin: +1;
// every other class: +2.
inline int poisonUserEfficiencyAdj(
        bool assassin, bool studied) {
    if (assassin && studied) return 0;
    if (assassin) return 1;
    return 2;
}

// Monster poison: all-or-nothing - no damage or death
// within about a minute.
inline bool poisonMonsterAllOrNothing() {
    return true;
}

// Monster poison works by ingestion or insinuation alike
// (dual-use); purchased poison is one route only.
inline bool poisonMonsterDualUse() {
    return true;
}

// Blade venom (DMG p.28): insinuative. Evaporation and
// use decay it identically - full the first day or hit,
// half the second, gone by the third. The multiplier is
// 100 for the first, 50 for the second, 0 for the third
// and beyond.
inline int poisonBladeVenomPotencyPercent(int interval) {
    if (interval <= 0) return 100;
    if (interval == 1) return 50;
    return 0;
}

// A partially evaporated or used DEATH poison gives the
// victim +4 on the save.
inline bool poisonBladeVenomDecayedGivesSaveBonus(
        int interval) {
    return interval >= 1;
}

} // namespace rules
