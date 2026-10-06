// rules/wisdom.h - Wisdom Tables I and II (the
// PHB CHARACTER ABILITIES wisdom section, R192).
//
// Wisdom Table I: the magical attack
// adjustment - a saving throw modifier
// against mental attack forms involving
// will force (beguiling, charming, fear,
// hypnosis, illusion, magic jarring, mass
// charming, phantasmal forces, possession,
// rulership, suggestion, telepathic attack).
// The Table I general-information rows also
// gate the high circles: 17 is the minimum
// wisdom for use of 6th level spells, 18 for
// 7th level spells.
//
// Wisdom Table II: the cleric spell bonus -
// CUMULATIVE, so a cleric with 14 wisdom is
// entitled to two 1st level bonus spells,
// one with 15 wisdom has two 1st and one
// 2nd level bonus spells - and the chance of
// spell failure for low wisdom: percentile
// dice are rolled, and if the number is
// equal to or less than the failure number
// the spell is expended and has absolutely
// no effect whatsoever. The bonus spells are
// only available when the cleric is
// entitled to spells of the applicable level
// (the caller gates on the base slots -
// see spells::clericSpellSlotsWithWis).

#ifndef RULES_WISDOM_H
#define RULES_WISDOM_H

#include <cstdint>

namespace rules {

// ---- Wisdom Table I ----

// The magical attack saving throw adjustment
// (3 -3 through 18 +4; scores below 3 clamp
// to the 3 row, above 18 to the 18 row).
inline int wisMagicalAttackAdj(uint8_t wis) {
    if (wis <= 3)  return -3;
    if (wis == 4)  return -2;
    if (wis <= 7)  return -1;   // 5, 6, 7
    if (wis <= 14) return  0;   // 8 through 14
    if (wis == 15) return  1;
    if (wis == 16) return  2;
    if (wis == 17) return  3;
    return  4;   // 18
}

// R227: the mental-form gate - the Wisdom
// Table I magical defense adjustment a
// defender gets vs mental attack forms
// involving will force (beguiling,
// charming, fear, hypnosis, illusion,
// mass charming, phantasmal forces,
// possession, rulership, suggestion,
// telepathic attack - the per-spell
// registry flags ride
// spells::spellIsMentalForm). 0 on
// everything else. spells::spellSaveModWis
// delegates here; the spelleffects save
// chokepoint folds the result into the
// target saveBonus.
inline int wisMentalSaveAdj(uint8_t wis, bool mentalForm) {
    if (!mentalForm) return 0;
    return wisMagicalAttackAdj(wis);
}

// The Table I high-circle gates: the minimum
// wisdom for use of the spell level (0 = no
// printed minimum). The 6th needs Wis 17, the
// 7th Wis 18.
inline int wisSpellLevelMin(int spellLevel) {
    if (spellLevel == 6) return 17;
    if (spellLevel == 7) return 18;
    return 0;
}

// ---- Wisdom Table II ----

// The CUMULATIVE cleric bonus spell count at
// the wisdom score, for the spell level (the
// printed ladder rows 13-18; every other
// score reads 0).
inline int wisBonusSpells(uint8_t wis, int spellLevel) {
    static const int kBonus[10][4] = {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 1, 0, 0, 0 },
        { 2, 0, 0, 0 },
        { 2, 1, 0, 0 },
        { 2, 2, 0, 0 },
        { 2, 2, 1, 0 },
        { 2, 2, 1, 1 },
    };
    if (wis < 9)  return 0;
    if (wis > 18) wis = 18;
    if (spellLevel < 1 || spellLevel > 4) return 0;
    return kBonus[wis - 9][spellLevel - 1];
}

// The chance of spell failure for low wisdom
// (percent). The printed table starts at 9 -
// the cleric minimum; scores below 9 clamp to
// the 9 row (they cannot be clerics anyway).
inline int wisSpellFailurePct(uint8_t wis) {
    static const int kFail[10] = {
        20,
        15,
        10,
        5,
        0,
        0,
        0,
        0,
        0,
        0,
    };
    if (wis < 9)  wis = 9;
    if (wis > 18) wis = 18;
    return kFail[wis - 9];
}

} // namespace rules

#endif // RULES_WISDOM_H
