// ====================================================================
// Adnd1 - rules/dmg/hirecost.h
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

// R-refactor: namespace rules -> class Hirecost (instance methods)
class Hirecost {
public:
    int hireSpellCount();
    int hireSpellBase(int spell);
    int hireSpellUnit(int spell);
    int hireSpellRate(int spell);
    int hireQuantity(int unit, int casterLevel, int recipientLevel, int persons, int questions, int pointsHealed);
    int hireSpellCost(int spell, int casterLevel, int persons, int recipientLevel, int questions, int pointsHealed);


// -----------------------------------------------------------------------
// The hiring clauses: the travel and
// risk factors, the charm-opposite
// percent, and the deliberate omissions.
// -----------------------------------------------------------------------
    int hireTravelNotAtRiskFactor();
    int hireAtRiskFactor();
    int hireRiskRefusalPossible();
    int hireCharmOppositePercent();
    int hireAttackSpellEntriesPriced();
    int hireHiredCastersAccompanyParty();
    int hireInterruptRaisesRates();
    int troopRaceCount();
    int troopControlPercent(int race, int column);
    int troopFightsFriendlyHumansPercent();
    int troopWeakLeaderWithOfficersPossible();
    int troopHighPayViewedAsWeakness();
    int demiHumanTroopsServeHumanMaster();
};
