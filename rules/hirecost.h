// ====================================================================
// Adnd1 - rules/hirecost.h
// R212: hiring NPCs to cast spells and
// the use of non-human troops (DMG
// pp.116-118) - the cleric spell hire
// prices, the travel and risk multipliers,
// the charm-opposite rule, and the
// non-human troop control percents.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// dice, the alignment and religion
// adjustments, and the campaign milieu).
//
// Conventions and judgments, named in
// place:
//   - Spell order: the print order - the
//     18-row first table (astral spell
//     through earthquake), then the
//     22-row second table (exorcise
//     through true seeing). The upload
//     OCR split the second table into a
//     name list and a cost list; the two
//     lists pair by order (22 and 22),
//     which is pinned here.
//   - Cost model: every price is a base
//     gold amount plus a rate times a
//     quantity selected by the unit code:
//     flat, per person, per level of the
//     caster, per level of the recipient,
//     per person per caster level, per
//     point of healing, base plus per
//     question, base plus per caster level,
//     base plus per recipient level (the
//     restoration clause - a like amount
//     per level of the recipient - reads
//     as base 10000 plus 1000 per level).
//   - The parenthetical notes on detect
//     evil/good and detect magic (assumes
//     a device being checked) do not
//     change the gold figures.
//   - The travel clause: if the caster is
//     expected to travel any distance but
//     not at risk, the factors will be as
//     much as doubled (x2); at risk, the
//     cleric is likely to refuse or charge
//     five or more times the rates (x5
//     pinned as the floor).
//   - The charm rule: a charmed caster is
//     always 25% likely to cast a spell as
//     close as possible to the opposite of
//     the instructed one.
//   - Attack spells are deliberately not
//     shown in the print, to discourage
//     hiring casters for such purposes;
//     no hired caster ever accompanies a
//     party except in DM-planned
//     circumstances (both pinned as 0).
//   - Troop order and columns: the print
//     order (bugbear, gnoll, goblin,
//     hobgoblin, kobold, lizard man, orc)
//     x the print columns (no officers and
//     a weak leader, no officers and a
//     strong leader, officers and a strong
//     leader). The roll exceeds the percent
//     shown, the troops disobey.
//   - Weakness in leadership or lack of
//     officering makes such troops unruly;
//     a weak leader with effective officers
//     is impossible (pinned 0), and a high
//     rate of pay is generally viewed as
//     weakness in a leader (pinned 1).
// ====================================================================

#pragma once

namespace rules {

// -----------------------------------------------------------------------
// The hire unit codes: how a rate scales.
// -----------------------------------------------------------------------
enum HireUnit {
    HU_FLAT = 0,
    HU_PER_PERSON,
    HU_PER_CASTER_LEVEL,
    HU_PER_RECIPIENT_LEVEL,
    HU_PER_PERSON_PER_CASTER_LEVEL,
    HU_PER_POINT_HEALED,
    HU_BASE_PLUS_PER_QUESTION,
    HU_BASE_PLUS_PER_CASTER_LEVEL,
    HU_BASE_PLUS_PER_RECIPIENT_LEVEL,
};

// -----------------------------------------------------------------------
// The hireable cleric spells, the print
// order (40).
// -----------------------------------------------------------------------
enum HireSpell {
    HS_ASTRAL_SPELL = 0,
    HS_ATONEMENT,
    HS_AUGURY,
    HS_BLESS,
    HS_COMMUNE,
    HS_CONTINUAL_LIGHT,
    HS_CONTROL_WEATHER,
    HS_CURE_BLINDNESS,
    HS_CURE_DISEASE,
    HS_CURE_LIGHT,
    HS_CURE_SERIOUS,
    HS_CURE_CRITICAL,
    HS_DETECT_EVIL_GOOD,
    HS_DETECT_MAGIC,
    HS_DISPEL_EVIL_GOOD,
    HS_DISPEL_MAGIC,
    HS_DIVINATION,
    HS_EARTHQUAKE,
    HS_EXORCISE,
    HS_FIND_THE_PATH,
    HS_GATE,
    HS_GLYPH_OF_WARDING,
    HS_HEAL,
    HS_NEUTRALIZE_POISON,
    HS_PART_WATER,
    HS_PLANE_SHIFT,
    HS_PRAYER,
    HS_PROTECTION_FROM_EVIL,
    HS_PURIFY_FOOD_DRINK,
    HS_RAISE_DEAD,
    HS_REGENERATE,
    HS_REMOVE_CURSE,
    HS_RESIST_COLD,
    HS_RESIST_FIRE,
    HS_RESTORATION,
    HS_SILENCE,
    HS_SLOW_POISON,
    HS_SPEAK_WITH_DEAD,
    HS_TONGUES,
    HS_TRUE_SEEING,
    HS_COUNT
};

inline int hireSpellCount() { return 40; }

inline int hireSpellBase(int spell) {
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

inline int hireSpellUnit(int spell) {
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

inline int hireSpellRate(int spell) {
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

inline int hireQuantity(int unit,
                        int casterLevel,
                        int recipientLevel,
                        int persons,
                        int questions,
                        int pointsHealed) {
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

inline int hireSpellCost(int spell,
                         int casterLevel,
                         int persons,
                         int recipientLevel,
                         int questions,
                         int pointsHealed) {
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

// -----------------------------------------------------------------------
// The hiring clauses: the travel and
// risk factors, the charm-opposite
// percent, and the deliberate omissions.
// -----------------------------------------------------------------------
inline int hireTravelNotAtRiskFactor() {
    // travel any distance, not at risk:
    // as much as doubled
    return 2;
}

inline int hireAtRiskFactor() {
    // at risk: five or more times the
    // rates (5 pinned as the floor)
    return 5;
}

inline int hireRiskRefusalPossible() {
    // at risk the cleric is likely to
    // refuse outright
    return 1;
}

inline int hireCharmOppositePercent() {
    // a charmed caster is always 25%
    // likely to cast the near-opposite
    return 25;
}

inline int hireAttackSpellEntriesPriced() {
    // attack spells are deliberately
    // not shown in the print
    return 0;
}

inline int hireHiredCastersAccompanyParty() {
    // no hired caster ever accompanies
    // a party, except DM-planned
    return 0;
}

inline int hireInterruptRaisesRates() {
    // continual interruptions are not
    // taken kindly: rates rise
    return 1;
}

// -----------------------------------------------------------------------
// The non-human troop control table:
// 7 races x 3 columns.
// -----------------------------------------------------------------------
enum TroopRace {
    TR_BUGBEAR = 0,
    TR_GNOLL,
    TR_GOBLIN,
    TR_HOBGOBLIN,
    TR_KOBOLD,
    TR_LIZARDMAN,
    TR_ORC,
    TR_TROOP_COUNT
};

inline int troopRaceCount() { return 7; }

inline int troopControlPercent(int race, int column) {
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

inline int troopFightsFriendlyHumansPercent() {
    // they fight with humans nearby,
    // friendly or not: 25% if friendly
    return 25;
}

inline int troopWeakLeaderWithOfficersPossible() {
    // the print: it is not possible to
    // have a weak leader and effective
    // officers
    return 0;
}

inline int troopHighPayViewedAsWeakness() {
    // granting a high rate of pay is
    // generally viewed as weakness in a
    // leader
    return 1;
}

inline int demiHumanTroopsServeHumanMaster() {
    // demi-human troops are unlikely
    // to serve a human master not
    // supporting their cause
    return 0;
}

}  // namespace rules
