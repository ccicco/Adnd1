// ====================================================================
// Adnd1 - rules/potionsprose2.h
// R250: the III.A potions explanation prose
// pins, part 2 (DMG pp.134-136) - potions
// 10 through 19 of the EXPLANATIONS AND
// DESCRIPTIONS section (upload lines
// ~10063-10128):
//   - Fire Resistance: damage reduced
//     by -2 per die of damage, saves at
//     +4; half dose -1 and +2; 1 turn,
//     or 5 rounds on a half dose.
//   - Flying: as the fly spell, third
//     level magic-user.
//   - Gaseous Form: base speed 3" per
//     round; a whirlwind inflicts double
//     damage.
//   - Giant Control: 1 or 2 giants; save
//     -4 if 1, +2 if 2; the 6-row d20
//     giant type sub-table; control lasts
//     5-30 (5d6) rounds.
//   - Giant Strength: the 6-row die
//     table - hill 1-6 through storm 20 -
//     weight allowance, damage bonus,
//     rock base range, rock hurling
//     damage, bend bars/lift gates
//     percent.
//   - Growth: 6 feet per quarter, 24
//     feet for the full potion.
//   - Healing: 4-10 (2d4 + 2) hit
//     points.
//   - Heroism: below 10 levels; the
//     3-row consumer level table
//     (10-sided dice for the
//     accumulated damage).
//   - Human Control: up to 32 levels
//     or hit dice; the 8-row d20 human
//     type table; 5-30 rounds.
//   - Invisibility: a gulp is 1/8 of
//     the contents; 3-6 turns.
// The ten potions are the engine III.A
// table rows 10-19 (dm/treasure.cpp
// kPotions, bands 27-54, invulnerability
// from 55) - cross-checked against the
// R221 potions.h pins in the audit.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int potFireDieReduction() {
    // Fire Resistance: all damage from
    // such fires is reduced by -2 from
    // each die of damage
    return -2;
}

inline int potFireSaveMod() {
    // if a saving throw is applicable it
    // is made at +4
    return 4;
}

inline int potFireHalfDieReduction() {
    // one-half potion: half the
    // benefits, -1
    return -1;
}

inline int potFireHalfSaveMod() {
    // one-half potion: half the
    // benefits, +2
    return 2;
}

inline int potFireTurns() {
    // the potion lasts 1 turn
    return 1;
}

inline int potFireHalfRounds() {
    // or 5 rounds for half doses
    return 5;
}

inline int potFlySpellLevel() {
    // Flying: in the same manner as the
    // third level magic-user spell, fly
    return 3;
}

inline int potGasSpeedInches() {
    // Gaseous Form: flows at a base
    // speed of 3" per round
    return 3;
}

inline int potGasWhirlwindMult() {
    // a whirlwind inflicts double
    // damage upon the gaseous form
    return 2;
}

inline int potGiantControlLo() {
    // Giant Control: influences 1 or 2
    // giants as if a charm monster spell
    return 1;
}

inline int potGiantControlHi() {
    return 2;
}

inline int potGiantOneSaveMod() {
    // if only 1 giant is influenced its
    // save versus magic is at -4
    return -4;
}

inline int potGiantTwoSaveMod() {
    // if 2 are influenced the die rolls
    // are at +2
    return 2;
}

inline int potGiantRoundLo() {
    // control lasts for only 5-30
    // (5d6) rounds
    return 5;
}

inline int potGiantRoundHi() {
    return 30;
}

inline int potGiantRoundDice() {
    return 5;
}

inline int potGiantRoundFaces() {
    return 6;
}

inline int potGiantTypeRowCount() {
    // the giant type sub-table: 6 rows
    return 6;
}

inline int potGiantTypeLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 6, 10, 14, 18, 20,
    };
    return t[i];
}

inline int potGiantTypeHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        5, 9, 13, 17, 19, 20,
    };
    return t[i];
}

inline int potGiantTypeFaces() {
    // the giant type roll is on d20
    return 20;
}

inline int potGStrRowCount() {
    // Giant Strength: the die table has
    // 6 rows
    return 6;
}

inline int potGStrTypeLo(int i) {
    // the printed die band lower edges;
    // i clamps - hill, stone, frost, fire,
    // cloud, storm
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 7, 11, 15, 18, 20,
    };
    return t[i];
}

inline int potGStrTypeHi(int i) {
    // the printed die band upper edges;
    // i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        6, 10, 14, 17, 19, 20,
    };
    return t[i];
}

inline int potGStrWeightGp(int i) {
    // the weight allowances; i clamps:
    // hill +4,500, stone +5,000, frost
    // +6,000, fire +7,500, cloud +9,000,
    // storm +12,000
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4500, 5000, 6000, 7500, 9000, 12000,
    };
    return t[i];
}

inline int potGStrDmgBonus(int i) {
    // the damage bonuses; i clamps:
    // +7, +8, +9, +10, +11, +12
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        7, 8, 9, 10, 11, 12,
    };
    return t[i];
}

inline int potGStrRockRangeInches(int i) {
    // the rock base ranges; i clamps:
    // hill 8", stone 16", frost 10",
    // fire 12", cloud 14", storm 16"
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        8, 16, 10, 12, 14, 16,
    };
    return t[i];
}

inline int potGStrRockDmgLo(int i) {
    // the rock hurling damage lower
    // edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 1, 1, 1, 1, 1,
    };
    return t[i];
}

inline int potGStrRockDmgHi(int i) {
    // the rock hurling damage upper
    // edges; i clamps: 1-6, 1-12, 1-8,
    // 1-8, 1-10, 1-12
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        6, 12, 8, 8, 10, 12,
    };
    return t[i];
}

inline int potGStrBendBarsPercent(int i) {
    // the bend bars/lift gates
    // percents; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        50, 60, 70, 80, 90, 100,
    };
    return t[i];
}

inline int potGrowthQuarterFeet() {
    // Growth: each quarter of the potion
    // causes 6 feet of height growth
    return 6;
}

inline int potGrowthFullFeet() {
    // a full potion increases height by
    // 24 feet
    return 24;
}

inline int potHealLo() {
    // Healing: restores 4-10
    // (2d4 + 2) hit points
    return 4;
}

inline int potHealHi() {
    return 10;
}

inline int potHealDice() {
    return 2;
}

inline int potHealFaces() {
    return 4;
}

inline int potHealBonus() {
    return 2;
}

inline int potHeroMaxLevels() {
    // Heroism: a temporary increase in
    // life energy levels if the imbiber
    // has fewer than 10 levels
    return 10;
}

inline int potHeroRowCount() {
    // the consumer level table: 3 rows
    return 3;
}

inline int potHeroDmgFaces() {
    // 10-sided dice for the accumulated
    // damage bestowed
    return 10;
}

inline int potHeroLevels(int i) {
    // the energy levels bestowed; i
    // clamps: 1st-3rd 3, 4th-6th 2,
    // 7th-9th 1
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        3, 2, 1,
    };
    return t[i];
}

inline int potHeroDmgDice(int i) {
    // the accumulated damage dice; i
    // clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        3, 2, 1,
    };
    return t[i];
}

inline int potHeroDmgBonus(int i) {
    // the accumulated damage bonus; i
    // clamps: 3 + 1, 2 + 2, 1 + 3
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 2, 3,
    };
    return t[i];
}

inline int potHumanLevelsTotal() {
    // Human Control: control up to 32
    // levels/hit dice of humans and
    // kindred as if a charm person spell
    return 32;
}

inline int potHumanTypeRowCount() {
    // the human type table: 8 rows
    return 8;
}

inline int potHumanTypeLo(int i) {
    // the printed band lower edges; i
    // clamps: dwarves, elves or
    // half-elves, gnomes, halflings,
    // half-orcs, humans, humanoids,
    // the mixed 20 row
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        1, 3, 5, 7, 9, 11, 17, 20,
    };
    return t[i];
}

inline int potHumanTypeHi(int i) {
    // the printed band upper edges; i
    // clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        2, 4, 6, 8, 10, 16, 19, 20,
    };
    return t[i];
}

inline int potHumanTypeFaces() {
    // the human type roll is on d20
    return 20;
}

inline int potHumanRoundLo() {
    // the potion lasts for 5-30 rounds
    return 5;
}

inline int potHumanRoundHi() {
    return 30;
}

inline int potInvisGulpFraction() {
    // Invisibility: a single gulp is
    // equal to 1/8 of the contents
    return 8;
}

inline int potInvisTurnsLo() {
    // the gulp bestows invisibility for
    // 3-6 turns
    return 3;
}

inline int potInvisTurnsHi() {
    return 6;
}

}  // namespace rules

