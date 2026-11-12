// ====================================================================
// Adnd1 - rules/dmg/poison.h
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

// R-refactor: namespace rules -> class Poison (instance methods)
class Poison {
public:


// Grade index: 0 = A ... 4 = E. Grade E exists ingestive
// only.
    bool poisonGradeExists(int route, int grade);


// ----------------------------------------------------------------------------
// The p.20 table (cost per dose)
// ----------------------------------------------------------------------------
    int poisonCostPerDose(int route, int grade);


// Onset: minimum and maximum on the printed range plus
// the unit the row prints in.
    int poisonOnsetMin(int route, int grade);
    int poisonOnsetMax(int route, int grade);
    PoisonUnit poisonOnsetUnit(int route, int grade);


// ----------------------------------------------------------------------------
// Damage classes
// ----------------------------------------------------------------------------

// The victim save bonus (the footnotes: +4/+3/+2/+1;
// E prints none - JUDGMENT: 0).
    int poisonVictimSaveBonus(int route, int grade);


// The tasting/smelling/seeing chance (80/65/40/15;
// E prints none - JUDGMENT: 0).
    int poisonDetectChance(int route, int grade);


// Damage if the save is made (the ingestive table only;
// every insinuative row prints 0).
    int poisonDamageIfSave(int route, int grade);


// A failed save: death (true) or the printed damage.
    bool poisonKillsIfNoSave(int route, int grade);
    int poisonDamageIfNoSave(int route, int grade);


// ----------------------------------------------------------------------------
// The class rules around the table
// ----------------------------------------------------------------------------

// User efficiency: the bonus the VICTIM gets on the save.
// A studied assassin: none; an unstudied assassin: +1;
// every other class: +2.
    int poisonUserEfficiencyAdj( bool assassin, bool studied);


// Monster poison: all-or-nothing - no damage or death
// within about a minute.
    bool poisonMonsterAllOrNothing();


// Monster poison works by ingestion or insinuation alike
// (dual-use); purchased poison is one route only.
    bool poisonMonsterDualUse();


// Blade venom (DMG p.28): insinuative. Evaporation and
// use decay it identically - full the first day or hit,
// half the second, gone by the third. The multiplier is
// 100 for the first, 50 for the second, 0 for the third
// and beyond.
    int poisonBladeVenomPotencyPercent(int interval);


// A partially evaporated or used DEATH poison gives the
// victim +4 on the save.
    bool poisonBladeVenomDecayedGivesSaveBonus( int interval);
};
