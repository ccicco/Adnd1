// R-refactor: split from potions_fire_resistance_to_invisibility.h - definitions
#include "rules/dmg/potions_fire_resistance_to_invisibility.h"

int Potions_fire_resistance_to_invisibility::potFireDieReduction() {
    // Fire Resistance: all damage from
    // such fires is reduced by -2 from
    // each die of damage
    return -2;
}

int Potions_fire_resistance_to_invisibility::potFireSaveMod() {
    // if a saving throw is applicable it
    // is made at +4
    return 4;
}

int Potions_fire_resistance_to_invisibility::potFireHalfDieReduction() {
    // one-half potion: half the
    // benefits, -1
    return -1;
}

int Potions_fire_resistance_to_invisibility::potFireHalfSaveMod() {
    // one-half potion: half the
    // benefits, +2
    return 2;
}

int Potions_fire_resistance_to_invisibility::potFireTurns() {
    // the potion lasts 1 turn
    return 1;
}

int Potions_fire_resistance_to_invisibility::potFireHalfRounds() {
    // or 5 rounds for half doses
    return 5;
}

int Potions_fire_resistance_to_invisibility::potFlySpellLevel() {
    // Flying: in the same manner as the
    // third level magic-user spell, fly
    return 3;
}

int Potions_fire_resistance_to_invisibility::potGasSpeedInches() {
    // Gaseous Form: flows at a base
    // speed of 3" per round
    return 3;
}

int Potions_fire_resistance_to_invisibility::potGasWhirlwindMult() {
    // a whirlwind inflicts double
    // damage upon the gaseous form
    return 2;
}

int Potions_fire_resistance_to_invisibility::potGiantControlLo() {
    // Giant Control: influences 1 or 2
    // giants as if a charm monster spell
    return 1;
}

int Potions_fire_resistance_to_invisibility::potGiantControlHi() {
    return 2;
}

int Potions_fire_resistance_to_invisibility::potGiantOneSaveMod() {
    // if only 1 giant is influenced its
    // save versus magic is at -4
    return -4;
}

int Potions_fire_resistance_to_invisibility::potGiantTwoSaveMod() {
    // if 2 are influenced the die rolls
    // are at +2
    return 2;
}

int Potions_fire_resistance_to_invisibility::potGiantRoundLo() {
    // control lasts for only 5-30
    // (5d6) rounds
    return 5;
}

int Potions_fire_resistance_to_invisibility::potGiantRoundHi() {
    return 30;
}

int Potions_fire_resistance_to_invisibility::potGiantRoundDice() {
    return 5;
}

int Potions_fire_resistance_to_invisibility::potGiantRoundFaces() {
    return 6;
}

int Potions_fire_resistance_to_invisibility::potGiantTypeRowCount() {
    // the giant type sub-table: 6 rows
    return 6;
}

int Potions_fire_resistance_to_invisibility::potGiantTypeLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 6, 10, 14, 18, 20,
    };
    return t[i];
}

int Potions_fire_resistance_to_invisibility::potGiantTypeHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        5, 9, 13, 17, 19, 20,
    };
    return t[i];
}

int Potions_fire_resistance_to_invisibility::potGiantTypeFaces() {
    // the giant type roll is on d20
    return 20;
}

int Potions_fire_resistance_to_invisibility::potGStrRowCount() {
    // Giant Strength: the die table has
    // 6 rows
    return 6;
}

int Potions_fire_resistance_to_invisibility::potGStrTypeLo(int i) {
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

int Potions_fire_resistance_to_invisibility::potGStrTypeHi(int i) {
    // the printed die band upper edges;
    // i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        6, 10, 14, 17, 19, 20,
    };
    return t[i];
}

int Potions_fire_resistance_to_invisibility::potGStrWeightGp(int i) {
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

int Potions_fire_resistance_to_invisibility::potGStrDmgBonus(int i) {
    // the damage bonuses; i clamps:
    // +7, +8, +9, +10, +11, +12
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        7, 8, 9, 10, 11, 12,
    };
    return t[i];
}

int Potions_fire_resistance_to_invisibility::potGStrRockRangeInches(int i) {
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

int Potions_fire_resistance_to_invisibility::potGStrRockDmgLo(int i) {
    // the rock hurling damage lower
    // edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 1, 1, 1, 1, 1,
    };
    return t[i];
}

int Potions_fire_resistance_to_invisibility::potGStrRockDmgHi(int i) {
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

int Potions_fire_resistance_to_invisibility::potGStrBendBarsPercent(int i) {
    // the bend bars/lift gates
    // percents; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        50, 60, 70, 80, 90, 100,
    };
    return t[i];
}

int Potions_fire_resistance_to_invisibility::potGrowthQuarterFeet() {
    // Growth: each quarter of the potion
    // causes 6 feet of height growth
    return 6;
}

int Potions_fire_resistance_to_invisibility::potGrowthFullFeet() {
    // a full potion increases height by
    // 24 feet
    return 24;
}

int Potions_fire_resistance_to_invisibility::potHealLo() {
    // Healing: restores 4-10
    // (2d4 + 2) hit points
    return 4;
}

int Potions_fire_resistance_to_invisibility::potHealHi() {
    return 10;
}

int Potions_fire_resistance_to_invisibility::potHealDice() {
    return 2;
}

int Potions_fire_resistance_to_invisibility::potHealFaces() {
    return 4;
}

int Potions_fire_resistance_to_invisibility::potHealBonus() {
    return 2;
}

int Potions_fire_resistance_to_invisibility::potHeroMaxLevels() {
    // Heroism: a temporary increase in
    // life energy levels if the imbiber
    // has fewer than 10 levels
    return 10;
}

int Potions_fire_resistance_to_invisibility::potHeroRowCount() {
    // the consumer level table: 3 rows
    return 3;
}

int Potions_fire_resistance_to_invisibility::potHeroDmgFaces() {
    // 10-sided dice for the accumulated
    // damage bestowed
    return 10;
}

int Potions_fire_resistance_to_invisibility::potHeroLevels(int i) {
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

int Potions_fire_resistance_to_invisibility::potHeroDmgDice(int i) {
    // the accumulated damage dice; i
    // clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        3, 2, 1,
    };
    return t[i];
}

int Potions_fire_resistance_to_invisibility::potHeroDmgBonus(int i) {
    // the accumulated damage bonus; i
    // clamps: 3 + 1, 2 + 2, 1 + 3
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 2, 3,
    };
    return t[i];
}

int Potions_fire_resistance_to_invisibility::potHumanLevelsTotal() {
    // Human Control: control up to 32
    // levels/hit dice of humans and
    // kindred as if a charm person spell
    return 32;
}

int Potions_fire_resistance_to_invisibility::potHumanTypeRowCount() {
    // the human type table: 8 rows
    return 8;
}

int Potions_fire_resistance_to_invisibility::potHumanTypeLo(int i) {
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

int Potions_fire_resistance_to_invisibility::potHumanTypeHi(int i) {
    // the printed band upper edges; i
    // clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        2, 4, 6, 8, 10, 16, 19, 20,
    };
    return t[i];
}

int Potions_fire_resistance_to_invisibility::potHumanTypeFaces() {
    // the human type roll is on d20
    return 20;
}

int Potions_fire_resistance_to_invisibility::potHumanRoundLo() {
    // the potion lasts for 5-30 rounds
    return 5;
}

int Potions_fire_resistance_to_invisibility::potHumanRoundHi() {
    return 30;
}

int Potions_fire_resistance_to_invisibility::potInvisGulpFraction() {
    // Invisibility: a single gulp is
    // equal to 1/8 of the contents
    return 8;
}

int Potions_fire_resistance_to_invisibility::potInvisTurnsLo() {
    // the gulp bestows invisibility for
    // 3-6 turns
    return 3;
}

int Potions_fire_resistance_to_invisibility::potInvisTurnsHi() {
    return 6;
}
