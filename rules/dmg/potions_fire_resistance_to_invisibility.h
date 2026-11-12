// ====================================================================
// Adnd1 - rules/dmg/potions_fire_resistance_to_invisibility.h
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

// R-refactor: namespace rules -> class Potions_fire_resistance_to_invisibility (instance methods)
class Potions_fire_resistance_to_invisibility {
public:
    int potFireDieReduction();
    int potFireSaveMod();
    int potFireHalfDieReduction();
    int potFireHalfSaveMod();
    int potFireTurns();
    int potFireHalfRounds();
    int potFlySpellLevel();
    int potGasSpeedInches();
    int potGasWhirlwindMult();
    int potGiantControlLo();
    int potGiantControlHi();
    int potGiantOneSaveMod();
    int potGiantTwoSaveMod();
    int potGiantRoundLo();
    int potGiantRoundHi();
    int potGiantRoundDice();
    int potGiantRoundFaces();
    int potGiantTypeRowCount();
    int potGiantTypeLo(int i);
    int potGiantTypeHi(int i);
    int potGiantTypeFaces();
    int potGStrRowCount();
    int potGStrTypeLo(int i);
    int potGStrTypeHi(int i);
    int potGStrWeightGp(int i);
    int potGStrDmgBonus(int i);
    int potGStrRockRangeInches(int i);
    int potGStrRockDmgLo(int i);
    int potGStrRockDmgHi(int i);
    int potGStrBendBarsPercent(int i);
    int potGrowthQuarterFeet();
    int potGrowthFullFeet();
    int potHealLo();
    int potHealHi();
    int potHealDice();
    int potHealFaces();
    int potHealBonus();
    int potHeroMaxLevels();
    int potHeroRowCount();
    int potHeroDmgFaces();
    int potHeroLevels(int i);
    int potHeroDmgDice(int i);
    int potHeroDmgBonus(int i);
    int potHumanLevelsTotal();
    int potHumanTypeRowCount();
    int potHumanTypeLo(int i);
    int potHumanTypeHi(int i);
    int potHumanTypeFaces();
    int potHumanRoundLo();
    int potHumanRoundHi();
    int potInvisGulpFraction();
    int potInvisTurnsLo();
    int potInvisTurnsHi();
};
