// ====================================================================
// Adnd1 - rules/rodsprose.h
// R244: the III.D rods explanation prose
// pins (DMG pp.141-142) - the section
// conventions of the RODS, et al. text
// (upload lines ~10562-10687) and the
// per-item facts of the SEVEN rods:
//   - the charges conventions: rods 50
//     charges minus 0-9 (d10-1), staves
//     25 minus 0-5 (d6-1), wands 100
//     minus 0-19 (d20-1); an item
//     completely drained crumbles to
//     powder, forever useless.
//   - the command-word rule for devices
//     that discharge magic over a
//     distance, and magical silence
//     stopping such devices.
//   - Rod of Absorption: absorbs 50
//     spell levels, 1-segment casting,
//     never recharged.
//   - Rod of Beguiling: 2" radius, any
//     intelligence 1+, no saving throw,
//     1 turn per charge, rechargeable.
//   - Rod of Cancellation: the 11-row
//     item saving throw table with the
//     +5 armor/shield and holy sword
//     variants; drained items are not
//     restorable, and the rod goes
//     brittle.
//   - Rod of Lordly Might: 10 pounds,
//     strength 16, the 3 spell-like
//     functions, the 4 weapon forms and
//     the 3 mundane uses; never
//     recharged.
//   - Rod of Resurrection: the 11-class
//     and 7-race charge tables, once
//     per day, multi-classed takes the
//     least favorable; never recharged.
//   - Rod of Rulership: 12" radius,
//     200-500 hit dice, save at
//     intelligence 15 and 12 hit dice,
//     5 segments to activate; never
//     recharged.
//   - Rod of Smiting: +3, 4-11 damage,
//     the golem and outer-plane rules;
//     never recharged.
// JUDGMENT, named in place: of the seven
// rods only Beguiling prints a
// rechargeable statement; Cancellation
// prints none (it goes brittle instead).
// The seven rods are the first seven rows
// of the engine III.D table (dm/treasure.
// cpp kRods, bands 01-19); the staff rows
// begin at band 20.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int rpRodChargesMax() {
    // rods: 50 charges minus 0-9 (d10-1)
    return 50;
}

inline int rpRodChargesDieLo() {
    // the minus die rolls 0
    return 0;
}

inline int rpRodChargesDieHi() {
    // the minus die rolls 9
    return 9;
}

inline int rpStaffChargesMax() {
    // staves: 25 charges minus 0-5 (d6-1)
    return 25;
}

inline int rpStaffChargesDieLo() {
    // the minus die rolls 0
    return 0;
}

inline int rpStaffChargesDieHi() {
    // the minus die rolls 5
    return 5;
}

inline int rpWandChargesMax() {
    // wands: 100 charges minus 0-19 (d20-1)
    return 100;
}

inline int rpWandChargesDieLo() {
    // the minus die rolls 0
    return 0;
}

inline int rpWandChargesDieHi() {
    // the minus die rolls 19
    return 19;
}

inline int rpDrainedCrumble() {
    // completely drained: crumbles to powder,
    // forever useless - printed as a rule
    return 1;
}

inline int rpCommandWordRule() {
    // distance-discharge devices need a
    // command word - printed as a rule
    return 1;
}

inline int rpSilenceBlocks() {
    // magical silence stops the device
    return 1;
}

inline int rpRodCount() {
    // the rods subsection describes seven rods
    return 7;
}

inline int rpAbsorbMaxSpellLevels() {
    // Rod of Absorption: 50 spell levels
    return 50;
}

inline int rpAbsorbCastSegments() {
    // stored energy casts in 1 segment
    return 1;
}

inline int rpAbsorbRechargeable() {
    // it can never be recharged
    return 0;
}

inline int rpBeguileRadiusInches() {
    // Rod of Beguiling: 2" radius
    return 2;
}

inline int rpBeguileMinIntelligence() {
    // any intelligence whatsoever: 1 or higher
    return 1;
}

inline int rpBeguileHasSave() {
    // no saving throw
    return 0;
}

inline int rpBeguileTurnsPerCharge() {
    // each charge beguiles for 1 turn
    return 1;
}

inline int rpBeguileRechargeable() {
    // it can be recharged
    return 1;
}

inline int rpCancSaveCount() {
    // Rod of Cancellation: 11 item rows
    return 11;
}

inline int rpCancSaveValue(int i) {
    // the printed item saving throws; i clamps
    if (i < 0) i = 0;
    if (i > 10) i = 10;
    static const int t[11] = {
        20, 19, 17, 14, 13, 15, 12, 3, 11, 9, 10,
    };
    return t[i];
}

inline int rpCancArmorShieldPlus5() {
    // armor or shield: 11, or 8 if +5
    return 8;
}

inline int rpCancHolySword() {
    // sword: 9, or 7 if a holy sword
    return 7;
}

inline int rpCancDrainedRestorable() {
    // drained items are not restorable,
    // even by wish
    return 0;
}

inline int rpCancRodBecomesBrittle() {
    // upon the item draining, the rod
    // becomes brittle, no longer potent
    return 1;
}

inline int rpLmWeightPounds() {
    // Rod of Lordly Might: 10 pounds
    return 10;
}

inline int rpLmMinStrength() {
    // 16 or greater strength to wield properly
    return 16;
}

inline int rpLmStrBelowPenalty() {
    // minus 1 to hit per point below 16
    return 1;
}

inline int rpLmSpellLikeCount() {
    // the 3 spell-like functions
    return 3;
}

inline int rpLmSpellCostCharges() {
    // each function draws off 1 charge
    return 1;
}

inline int rpLmFearRangeInches() {
    // function 2, fear: 6" maximum range
    return 6;
}

inline int rpLmDrainHpLo() {
    // function 3, drain: 2-8 hit points
    return 2;
}

inline int rpLmDrainHpHi() {
    return 8;
}

inline int rpLmWeaponFormCount() {
    // the 4 weapon forms
    return 4;
}

inline int rpLmWeaponBonus(int i) {
    // +2 mace, +1 flame sword, +4 battle axe,
    // +3 spear; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        2, 1, 4, 3,
    };
    return t[i];
}

inline int rpLmSpearLenMinFeet() {
    // the +3 spear: 6 foot minimum
    return 6;
}

inline int rpLmSpearLenMaxFeet() {
    // 15 foot maximum
    return 15;
}

inline int rpLmSpearHandleMaxFeet() {
    // the handle lengthens up to 12 feet
    return 12;
}

inline int rpLmMundaneUseCount() {
    // the 3 mundane uses
    return 3;
}

inline int rpLmPoleGrowthPerSegment() {
    // the pole lengthens 5 feet per segment
    return 5;
}

inline int rpLmPoleMaxFeet() {
    // the pole stops at 50 feet
    return 50;
}

inline int rpLmPoleBearPounds() {
    // it bears up to 4,000 pounds
    return 4000;
}

inline int rpLmDoorForceMaxFeet() {
    // door force: planted 30 feet or less
    // from the portal
    return 30;
}

inline int rpLmRechargeable() {
    // it cannot be recharged
    return 0;
}

inline int rpLmExhaustedWeaponCeaseLo() {
    // charges exhausted: weapon functions
    // 2 and 3 cease (the spell-like all do)
    return 2;
}

inline int rpLmExhaustedWeaponCeaseHi() {
    return 3;
}

inline int rpResUsesPerDay() {
    // Rod of Resurrection: once per day
    return 1;
}

inline int rpResClassCount() {
    // the charge table lists 11 classes
    return 11;
}

inline int rpResClassCharges(int i) {
    // cleric, druid, fighter, paladin, ranger,
    // magic-user, illusionist, thief, assassin,
    // monk, bard; i clamps
    if (i < 0) i = 0;
    if (i > 10) i = 10;
    static const int t[11] = {
        1, 2, 2, 1, 2, 3, 3, 3, 4, 3, 2,
    };
    return t[i];
}

inline int rpResRaceCount() {
    // the charge table lists 7 races
    return 7;
}

inline int rpResRaceCharges(int i) {
    // dwarf, elf, gnome, half-elf, halfling,
    // half-orc, human; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        3, 4, 3, 2, 2, 4, 1,
    };
    return t[i];
}

inline int rpResMultiLeastFavorable() {
    // multi-classed uses the least favorable
    return 1;
}

inline int rpResRechargeable() {
    // it cannot be recharged
    return 0;
}

inline int rpRuleRadiusInches() {
    // Rod of Rulership: creatures within 12"
    return 12;
}

inline int rpRuleHdLo() {
    // from 200 hit dice
    return 200;
}

inline int rpRuleHdHi() {
    // to 500 hit dice
    return 500;
}

inline int rpRuleSaveIntMin() {
    // save at 15 or greater intelligence
    return 15;
}

inline int rpRuleSaveHdMin() {
    // and 12 or more hit dice/levels
    return 12;
}

inline int rpRuleActivateSegments() {
    // 5 segments to activate
    return 5;
}

inline int rpRuleTurnsPerCharge() {
    // each charge lasts 1 turn
    return 1;
}

inline int rpRuleRechargeable() {
    // it cannot be recharged
    return 0;
}

inline int rpSmiteBonus() {
    // Rod of Smiting: a +3 magic weapon
    return 3;
}

inline int rpSmiteDamageLo() {
    // 4-11 (d8 + 3) hit points
    return 4;
}

inline int rpSmiteDamageHi() {
    return 11;
}

inline int rpSmiteGolemDamageLo() {
    // vs golems: 8-22 (2d8 + 6) hit points
    return 8;
}

inline int rpSmiteGolemDamageHi() {
    return 22;
}

inline int rpSmiteGolemDestroyRoll() {
    // any score of 20 or better destroys
    return 20;
}

inline int rpSmiteGolemHitChargeDrain() {
    // any hit upon a golem drains 1 charge
    return 1;
}

inline int rpSmiteOuterTripleRoll() {
    // outer planes: 20 or better
    return 20;
}

inline int rpSmiteOuterChargeDrain() {
    // draws off 1 charge
    return 1;
}

inline int rpSmiteOuterDamageMultiple() {
    // and causes triple damage
    return 3;
}

inline int rpSmiteRechargeable() {
    // it cannot be recharged
    return 0;
}

}  // namespace rules

