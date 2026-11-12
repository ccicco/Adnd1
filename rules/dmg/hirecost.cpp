// R-refactor: split from hirecost.h - definitions
#include "rules/dmg/hirecost.h"

int Hirecost::hireSpellCount() { return 40; }

int Hirecost::hireSpellBase(int spell) {
    // the base gold of each price (the
    // flat costs live here; the scaled
    // ones carry base 0 except commune,
    // raise dead and restoration)
    if (spell < 0) spell = 0;
    if (spell > 39) spell = 39;
    static const int t[40] = {
        0, 0, 300, 0, 1000, 500, 10000,
        1000, 1000, 100, 350, 600, 100,
        150, 1000, 0, 1000, 10000,
        0, 0, 50000, 0, 0, 1000, 0,
        4000, 0, 0, 100, 1000, 15000,
        0, 0, 0, 10000, 0, 0, 0, 500, 0,
    };
    return t[spell];
}

int Hirecost::hireSpellUnit(int spell) {
    // the unit code of each price (the
    // HireUnit order)
    if (spell < 0) spell = 0;
    if (spell > 39) spell = 39;
    static const int t[40] = {
        1, 3, 0, 4, 6, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 2, 0, 0,
        2, 2, 0, 2, 5, 0, 2, 0, 2, 2,
        0, 7, 0, 2, 2, 2, 8, 2, 2, 2,
        0, 2,
    };
    return t[spell];
}

int Hirecost::hireSpellRate(int spell) {
    // the scaled gold of each price (0
    // for the flat ones)
    if (spell < 0) spell = 0;
    if (spell > 39) spell = 39;
    static const int t[40] = {
        5000, 500, 0, 5, 500, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 100,
        0, 0,
        1000, 500, 0, 100, 200, 0,
        1000, 0, 50, 50, 0, 500, 0,
        500, 50, 100, 1000, 100, 200,
        100, 0, 400,
    };
    return t[spell];
}

int Hirecost::hireQuantity(int unit, int casterLevel, int recipientLevel, int persons, int questions, int pointsHealed) {
    // the multiplier quantity a unit
    // selects (the clamped params)
    int q = 0;
    if (unit == 1) q = persons;
    if (unit == 2) q = casterLevel;
    if (unit == 3) q = recipientLevel;
    if (unit == 4) q = persons * casterLevel;
    if (unit == 5) q = pointsHealed;
    if (unit == 6) q = questions;
    if (unit == 7) q = casterLevel;
    if (unit == 8) q = recipientLevel;
    return q;
}

int Hirecost::hireSpellCost(int spell, int casterLevel, int persons, int recipientLevel, int questions, int pointsHealed) {
    // the full price: base plus rate
    // times the unit quantity; the
    // params are clamped, so a flat
    // spell ignores extras and no
    // input can produce negative gold
    if (spell < 0) spell = 0;
    if (spell > 39) spell = 39;
    if (casterLevel < 0) casterLevel = 0;
    if (persons < 0) persons = 0;
    if (recipientLevel < 0) recipientLevel = 0;
    if (questions < 0) questions = 0;
    if (pointsHealed < 0) pointsHealed = 0;
    return hireSpellBase(spell)
        + hireSpellRate(spell)
        * hireQuantity(hireSpellUnit(spell),
                       casterLevel,
                       recipientLevel, persons,
                       questions, pointsHealed);
}

int Hirecost::hireTravelNotAtRiskFactor() {
    // travel any distance, not at risk:
    // as much as doubled
    return 2;
}

int Hirecost::hireAtRiskFactor() {
    // at risk: five or more times the
    // rates (5 pinned as the floor)
    return 5;
}

int Hirecost::hireRiskRefusalPossible() {
    // at risk the cleric is likely to
    // refuse outright
    return 1;
}

int Hirecost::hireCharmOppositePercent() {
    // a charmed caster is always 25%
    // likely to cast the near-opposite
    return 25;
}

int Hirecost::hireAttackSpellEntriesPriced() {
    // attack spells are deliberately
    // not shown in the print
    return 0;
}

int Hirecost::hireHiredCastersAccompanyParty() {
    // no hired caster ever accompanies
    // a party, except DM-planned
    return 0;
}

int Hirecost::hireInterruptRaisesRates() {
    // continual interruptions are not
    // taken kindly: rates rise
    return 1;
}

int Hirecost::troopRaceCount() { return 7; }

int Hirecost::troopControlPercent(int race, int column) {
    // the print percents: roll
    // exceeding the shown number, the
    // troops disobey; columns: 0 no
    // officers and a weak leader, 1 no
    // officers and a strong leader, 2
    // officers and a strong leader
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    if (column < 0) column = 0;
    if (column > 2) column = 2;
    static const int t[21] = {
        30, 50, 80,
        30, 40, 80,
        40, 50, 90,
        20, 40, 90,
        25, 50, 95,
        10, 60, 100,
        20, 50, 90,
    };
    return t[race * 3 + column];
}

int Hirecost::troopFightsFriendlyHumansPercent() {
    // they fight with humans nearby,
    // friendly or not: 25% if friendly
    return 25;
}

int Hirecost::troopWeakLeaderWithOfficersPossible() {
    // the print: it is not possible to
    // have a weak leader and effective
    // officers
    return 0;
}

int Hirecost::troopHighPayViewedAsWeakness() {
    // granting a high rate of pay is
    // generally viewed as weakness in a
    // leader
    return 1;
}

int Hirecost::demiHumanTroopsServeHumanMaster() {
    // demi-human troops are unlikely
    // to serve a human master not
    // supporting their cause
    return 0;
}
