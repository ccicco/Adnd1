// ====================================================================
// Adnd1 - rules/potionsprose3.h
// R251: the III.A potions explanation prose
// pins, part 3 (DMG pp.136-137) - the final
// SIXTEEN potions of the EXPLANATIONS AND
// DESCRIPTIONS section (upload lines
// ~10129-10189):
//   - Invulnerability: fewer than 4 hit
//     dice cannot harm; armor class +2
//     classes; +2 to saves; 5-20 rounds.
//   - Levitation: as the spell, second
//     level; maximum weight 6,000 g.p.
//   - Longevity: age reduced 1-12 years;
//     1% cumulative reversal chance.
//   - Oil of Etherealness: effect in 3
//     rounds; lasts 4 + 1-4 turns.
//   - Oil of Slipperiness: 95% per round
//     floor slip; lasts 8 hours.
//   - Philter of Love: charm wears off in
//     4 + 1-4 turns.
//   - Philter of Persuasiveness: +25% on
//     reaction dice; suggest once per
//     turn within 3".
//   - Plant Control: save at intelligence
//     5+; a 2" x 2" square; range 9";
//     5-20 rounds.
//   - Poison: weak +1 to +4; deadly -1 to
//     -4 or more; neutralize lowers
//     toxicity by 40%.
//   - Polymorph self: the fourth level
//     spell.
//   - Speed: +100% movement and combat; 9"
//     becomes 18"; ages 1 year; 5-20
//     rounds.
//   - Super-Heroism: below 13 levels; the
//     4-row consumer table (energy levels
//     5/4/3/2, accumulated damage 4+1/
//     3+2/2+3/1+4 on d10); 5-30 melee
//     rounds.
//   - Sweet Water: 100,000 cubic feet of
//     water; 1,000 of acid; initial
//     period 5-20 rounds.
//   - Treasure Finding: within 24"; at
//     least 10,000 copper or 100 gems;
//     5-20 rounds.
//   - Undead Control: 16 hit dice maximum;
//     saves at -2; 5-20 rounds; the 10-row
//     d10 undead type table.
//   - Water Breathing: 75% two doses, 25%
//     four; one hour per dose plus 1-10
//     rounds.
// The sixteen potions are the engine III.A
// table rows 20-35 (dm/treasure.cpp
// kPotions, bands 55-100, the table closing
// at 100) - cross-checked against the R221
// potions.h pins in the audit. THIS CLOSES
// THE III.A POTIONS ARC.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int potInvulnMinHitDice() {
    // Invulnerability: attacks from
    // creatures with fewer than 4 hit dice
    // cannot harm the imbiber
    return 4;
}

inline int potInvulnAcClasses() {
    // improves armor class rating by
    // 2 classes
    return 2;
}

inline int potInvulnSaveMod() {
    // a bonus of +2 on saving throws
    // versus all forms of attack
    return 2;
}

inline int potInvulnRoundLo() {
    // the effects last for 5-20 rounds
    return 5;
}

inline int potInvulnRoundHi() {
    return 20;
}

inline int potLevitSpellLevel() {
    // Levitation: much the same manner as
    // the second level magic-user spell
    return 2;
}

inline int potLevitMaxWeightGp() {
    // the individual only, subject to a
    // maximum weight of 6,000 g.p.
    // equivalent
    return 6000;
}

inline int potLongYearsLo() {
    // Longevity: reduces game age by from
    // 1-12 years
    return 1;
}

inline int potLongYearsHi() {
    return 12;
}

inline int potLongReversePercent() {
    // each time one is drunk there is a 1%
    // cumulative chance of reversing all
    // previous age removal
    return 1;
}

inline int potEtherRoundsToEffect() {
    // Oil of Etherealness: takes effect 3
    // rounds after application
    return 3;
}

inline int potEtherTurnsBase() {
    // it lasts for 4 + 1-4 turns
    return 4;
}

inline int potEtherExtraLo() {
    return 1;
}

inline int potEtherExtraHi() {
    return 4;
}

inline int potSlipFallPercent() {
    // Oil of Slipperiness: poured on a
    // floor there is a 95% chance each
    // round of slipping and falling
    return 95;
}

inline int potSlipHours() {
    // the oil lasts 8 hours to wear off
    // normally
    return 8;
}

inline int potLoveTurnsBase() {
    // Philter of Love: charming effects
    // wear off in 4 + 1-4 turns
    return 4;
}

inline int potLoveExtraLo() {
    return 1;
}

inline int potLoveExtraHi() {
    return 4;
}

inline int potPersuadeReactPercent() {
    // Philter of Persuasiveness: a bonus
    // of 25% on reaction dice rolls
    return 25;
}

inline int potPersuadePerTurn() {
    // able to suggest once per turn
    return 1;
}

inline int potPersuadeRangeInches() {
    // to creatures within a range of 3"
    return 3;
}

inline int potPlantSaveInt() {
    // Plant Control: vegetable monsters
    // of intelligence 5 or higher get a
    // saving throw versus magic
    return 5;
}

inline int potPlantSquareInches() {
    // plants within a 2" x 2" square
    return 2;
}

inline int potPlantRangeInches() {
    // control range is 9"
    return 9;
}

inline int potPlantRoundLo() {
    // control for 5-20 rounds
    return 5;
}

inline int potPlantRoundHi() {
    return 20;
}

inline int potPoisonWeakLo() {
    // Poison: weak poison gives +1 to +4
    // on the saving throw
    return 1;
}

inline int potPoisonWeakHi() {
    return 4;
}

inline int potPoisonDeadlyLo() {
    // deadly poison gives -1 to -4 or
    // more on the saving throw
    return -4;
}

inline int potPoisonDeadlyHi() {
    return -1;
}

inline int potPoisonNeutralizePercent() {
    // neutralize poison can lower the
    // toxicity level by 40%
    return 40;
}

inline int potPolySpellLevel() {
    // Polymorph self: the fourth level
    // magic-user spell
    return 4;
}

inline int potSpeedBoostPercent() {
    // Speed: movement and combat
    // capabilities increased by 100%
    return 100;
}

inline int potSpeedMoveBaseInches() {
    // a movement rate of 9" becomes 18"
    return 9;
}

inline int potSpeedMoveBoostedInches() {
    return 18;
}

inline int potSpeedAgeYears() {
    // use ages the individual by 1 year
    return 1;
}

inline int potSpeedRoundLo() {
    // the other effects last for 5-20
    // rounds
    return 5;
}

inline int potSpeedRoundHi() {
    return 20;
}

inline int potSHeroMaxLevels() {
    // Super-Heroism: a temporary increase
    // in life energy levels if the imbiber
    // has fewer than 13 levels
    return 13;
}

inline int potSHeroRowCount() {
    // the consumer level table: 4 rows
    return 4;
}

inline int potSHeroDmgFaces() {
    // 10-sided dice for the accumulated
    // damage bestowed
    return 10;
}

inline int potSHeroRoundLo() {
    // the effects last from but 5 to 30
    // melee rounds
    return 5;
}

inline int potSHeroRoundHi() {
    return 30;
}

inline int potSHeroLevels(int i) {
    // the energy levels bestowed; i
    // clamps: 1st-3rd 5, 4th-6th 4,
    // 7th-9th 3, 10th-12th 2
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        5, 4, 3, 2,
    };
    return t[i];
}

inline int potSHeroDmgDice(int i) {
    // the accumulated damage dice; i
    // clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        4, 3, 2, 1,
    };
    return t[i];
}

inline int potSHeroDmgBonus(int i) {
    // the accumulated damage bonus; i
    // clamps: 4 + 1, 3 + 2, 2 + 3, 1 + 4
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 2, 3, 4,
    };
    return t[i];
}

inline int potSweetWaterCubicFeet() {
    // Sweet Water: changes up to 100,000
    // cubic feet of polluted, salt, or
    // alkaline water to fresh water
    return 100000;
}

inline int potSweetAcidCubicFeet() {
    // turns up to 1,000 cubic feet of
    // acid into pure water
    return 1000;
}

inline int potSweetRoundLo() {
    // an initial period of 5-20 rounds
    return 5;
}

inline int potSweetRoundHi() {
    return 20;
}

inline int potTreasureRangeInches() {
    // Treasure Finding: the treasure must
    // be within 24" or less
    return 24;
}

inline int potTreasureMinCopper() {
    // a mass of at least 10,000 copper
    // pieces
    return 10000;
}

inline int potTreasureMinGems() {
    // or 100 gems
    return 100;
}

inline int potTreasureRoundLo() {
    // the effects last for from 5-20
    // rounds
    return 5;
}

inline int potTreasureRoundHi() {
    return 20;
}

inline int potUndeadMaxHitDice() {
    // Undead Control: affects a maximum
    // of 16 hit dice of undead
    return 16;
}

inline int potUndeadSaveMod() {
    // saving throws are made at -2 due
    // to the power of the potion
    return -2;
}

inline int potUndeadRoundLo() {
    // the effects wear off in from 5-20
    // rounds
    return 5;
}

inline int potUndeadRoundHi() {
    return 20;
}

inline int potUndeadTypeRowCount() {
    // the undead type table: 10 rows
    return 10;
}

inline int potUndeadTypeLo(int i) {
    // the d10 band lower edges; i clamps:
    // ghasts, ghosts, ghouls, shadows,
    // skeletons, spectres, wights,
    // wraiths, vampires, zombies (the
    // printed 0 row is the 10 face)
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    static const int t[10] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    };
    return t[i];
}

inline int potUndeadTypeHi(int i) {
    // the d10 band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    static const int t[10] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    };
    return t[i];
}

inline int potUndeadTypeFaces() {
    // the undead type roll is on d10
    return 10;
}

inline int potWaterTwoDosePercent() {
    // Water Breathing: 75% likely to
    // contain two doses
    return 75;
}

inline int potWaterFourDosePercent() {
    // 25% probable that there will be
    // four in the container
    return 25;
}

inline int potWaterHourPerDose() {
    // one full hour per dose quaffed
    return 1;
}

inline int potWaterExtraLo() {
    // an additional 1-10 rounds (minutes)
    // variable
    return 1;
}

inline int potWaterExtraHi() {
    return 10;
}

}  // namespace rules

