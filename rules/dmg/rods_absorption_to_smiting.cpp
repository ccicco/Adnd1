// R-refactor: split from rods_absorption_to_smiting.h - definitions
#include "rules/dmg/rods_absorption_to_smiting.h"

int Rods_absorption_to_smiting::rpRodChargesMax() {
    // rods: 50 charges minus 0-9 (d10-1)
    return 50;
}

int Rods_absorption_to_smiting::rpRodChargesDieLo() {
    // the minus die rolls 0
    return 0;
}

int Rods_absorption_to_smiting::rpRodChargesDieHi() {
    // the minus die rolls 9
    return 9;
}

int Rods_absorption_to_smiting::rpStaffChargesMax() {
    // staves: 25 charges minus 0-5 (d6-1)
    return 25;
}

int Rods_absorption_to_smiting::rpStaffChargesDieLo() {
    // the minus die rolls 0
    return 0;
}

int Rods_absorption_to_smiting::rpStaffChargesDieHi() {
    // the minus die rolls 5
    return 5;
}

int Rods_absorption_to_smiting::rpWandChargesMax() {
    // wands: 100 charges minus 0-19 (d20-1)
    return 100;
}

int Rods_absorption_to_smiting::rpWandChargesDieLo() {
    // the minus die rolls 0
    return 0;
}

int Rods_absorption_to_smiting::rpWandChargesDieHi() {
    // the minus die rolls 19
    return 19;
}

int Rods_absorption_to_smiting::rpDrainedCrumble() {
    // completely drained: crumbles to powder,
    // forever useless - printed as a rule
    return 1;
}

int Rods_absorption_to_smiting::rpCommandWordRule() {
    // distance-discharge devices need a
    // command word - printed as a rule
    return 1;
}

int Rods_absorption_to_smiting::rpSilenceBlocks() {
    // magical silence stops the device
    return 1;
}

int Rods_absorption_to_smiting::rpRodCount() {
    // the rods subsection describes seven rods
    return 7;
}

int Rods_absorption_to_smiting::rpAbsorbMaxSpellLevels() {
    // Rod of Absorption: 50 spell levels
    return 50;
}

int Rods_absorption_to_smiting::rpAbsorbCastSegments() {
    // stored energy casts in 1 segment
    return 1;
}

int Rods_absorption_to_smiting::rpAbsorbRechargeable() {
    // it can never be recharged
    return 0;
}

int Rods_absorption_to_smiting::rpBeguileRadiusInches() {
    // Rod of Beguiling: 2" radius
    return 2;
}

int Rods_absorption_to_smiting::rpBeguileMinIntelligence() {
    // any intelligence whatsoever: 1 or higher
    return 1;
}

int Rods_absorption_to_smiting::rpBeguileHasSave() {
    // no saving throw
    return 0;
}

int Rods_absorption_to_smiting::rpBeguileTurnsPerCharge() {
    // each charge beguiles for 1 turn
    return 1;
}

int Rods_absorption_to_smiting::rpBeguileRechargeable() {
    // it can be recharged
    return 1;
}

int Rods_absorption_to_smiting::rpCancSaveCount() {
    // Rod of Cancellation: 11 item rows
    return 11;
}

int Rods_absorption_to_smiting::rpCancSaveValue(int i) {
    // the printed item saving throws; i clamps
    if (i < 0) i = 0;
    if (i > 10) i = 10;
    static const int t[11] = {
        20, 19, 17, 14, 13, 15, 12, 3, 11, 9, 10,
    };
    return t[i];
}

int Rods_absorption_to_smiting::rpCancArmorShieldPlus5() {
    // armor or shield: 11, or 8 if +5
    return 8;
}

int Rods_absorption_to_smiting::rpCancHolySword() {
    // sword: 9, or 7 if a holy sword
    return 7;
}

int Rods_absorption_to_smiting::rpCancDrainedRestorable() {
    // drained items are not restorable,
    // even by wish
    return 0;
}

int Rods_absorption_to_smiting::rpCancRodBecomesBrittle() {
    // upon the item draining, the rod
    // becomes brittle, no longer potent
    return 1;
}

int Rods_absorption_to_smiting::rpLmWeightPounds() {
    // Rod of Lordly Might: 10 pounds
    return 10;
}

int Rods_absorption_to_smiting::rpLmMinStrength() {
    // 16 or greater strength to wield properly
    return 16;
}

int Rods_absorption_to_smiting::rpLmStrBelowPenalty() {
    // minus 1 to hit per point below 16
    return 1;
}

int Rods_absorption_to_smiting::rpLmSpellLikeCount() {
    // the 3 spell-like functions
    return 3;
}

int Rods_absorption_to_smiting::rpLmSpellCostCharges() {
    // each function draws off 1 charge
    return 1;
}

int Rods_absorption_to_smiting::rpLmFearRangeInches() {
    // function 2, fear: 6" maximum range
    return 6;
}

int Rods_absorption_to_smiting::rpLmDrainHpLo() {
    // function 3, drain: 2-8 hit points
    return 2;
}

int Rods_absorption_to_smiting::rpLmDrainHpHi() {
    return 8;
}

int Rods_absorption_to_smiting::rpLmWeaponFormCount() {
    // the 4 weapon forms
    return 4;
}

int Rods_absorption_to_smiting::rpLmWeaponBonus(int i) {
    // +2 mace, +1 flame sword, +4 battle axe,
    // +3 spear; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        2, 1, 4, 3,
    };
    return t[i];
}

int Rods_absorption_to_smiting::rpLmSpearLenMinFeet() {
    // the +3 spear: 6 foot minimum
    return 6;
}

int Rods_absorption_to_smiting::rpLmSpearLenMaxFeet() {
    // 15 foot maximum
    return 15;
}

int Rods_absorption_to_smiting::rpLmSpearHandleMaxFeet() {
    // the handle lengthens up to 12 feet
    return 12;
}

int Rods_absorption_to_smiting::rpLmMundaneUseCount() {
    // the 3 mundane uses
    return 3;
}

int Rods_absorption_to_smiting::rpLmPoleGrowthPerSegment() {
    // the pole lengthens 5 feet per segment
    return 5;
}

int Rods_absorption_to_smiting::rpLmPoleMaxFeet() {
    // the pole stops at 50 feet
    return 50;
}

int Rods_absorption_to_smiting::rpLmPoleBearPounds() {
    // it bears up to 4,000 pounds
    return 4000;
}

int Rods_absorption_to_smiting::rpLmDoorForceMaxFeet() {
    // door force: planted 30 feet or less
    // from the portal
    return 30;
}

int Rods_absorption_to_smiting::rpLmRechargeable() {
    // it cannot be recharged
    return 0;
}

int Rods_absorption_to_smiting::rpLmExhaustedWeaponCeaseLo() {
    // charges exhausted: weapon functions
    // 2 and 3 cease (the spell-like all do)
    return 2;
}

int Rods_absorption_to_smiting::rpLmExhaustedWeaponCeaseHi() {
    return 3;
}

int Rods_absorption_to_smiting::rpResUsesPerDay() {
    // Rod of Resurrection: once per day
    return 1;
}

int Rods_absorption_to_smiting::rpResClassCount() {
    // the charge table lists 11 classes
    return 11;
}

int Rods_absorption_to_smiting::rpResClassCharges(int i) {
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

int Rods_absorption_to_smiting::rpResRaceCount() {
    // the charge table lists 7 races
    return 7;
}

int Rods_absorption_to_smiting::rpResRaceCharges(int i) {
    // dwarf, elf, gnome, half-elf, halfling,
    // half-orc, human; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        3, 4, 3, 2, 2, 4, 1,
    };
    return t[i];
}

int Rods_absorption_to_smiting::rpResMultiLeastFavorable() {
    // multi-classed uses the least favorable
    return 1;
}

int Rods_absorption_to_smiting::rpResRechargeable() {
    // it cannot be recharged
    return 0;
}

int Rods_absorption_to_smiting::rpRuleRadiusInches() {
    // Rod of Rulership: creatures within 12"
    return 12;
}

int Rods_absorption_to_smiting::rpRuleHdLo() {
    // from 200 hit dice
    return 200;
}

int Rods_absorption_to_smiting::rpRuleHdHi() {
    // to 500 hit dice
    return 500;
}

int Rods_absorption_to_smiting::rpRuleSaveIntMin() {
    // save at 15 or greater intelligence
    return 15;
}

int Rods_absorption_to_smiting::rpRuleSaveHdMin() {
    // and 12 or more hit dice/levels
    return 12;
}

int Rods_absorption_to_smiting::rpRuleActivateSegments() {
    // 5 segments to activate
    return 5;
}

int Rods_absorption_to_smiting::rpRuleTurnsPerCharge() {
    // each charge lasts 1 turn
    return 1;
}

int Rods_absorption_to_smiting::rpRuleRechargeable() {
    // it cannot be recharged
    return 0;
}

int Rods_absorption_to_smiting::rpSmiteBonus() {
    // Rod of Smiting: a +3 magic weapon
    return 3;
}

int Rods_absorption_to_smiting::rpSmiteDamageLo() {
    // 4-11 (d8 + 3) hit points
    return 4;
}

int Rods_absorption_to_smiting::rpSmiteDamageHi() {
    return 11;
}

int Rods_absorption_to_smiting::rpSmiteGolemDamageLo() {
    // vs golems: 8-22 (2d8 + 6) hit points
    return 8;
}

int Rods_absorption_to_smiting::rpSmiteGolemDamageHi() {
    return 22;
}

int Rods_absorption_to_smiting::rpSmiteGolemDestroyRoll() {
    // any score of 20 or better destroys
    return 20;
}

int Rods_absorption_to_smiting::rpSmiteGolemHitChargeDrain() {
    // any hit upon a golem drains 1 charge
    return 1;
}

int Rods_absorption_to_smiting::rpSmiteOuterTripleRoll() {
    // outer planes: 20 or better
    return 20;
}

int Rods_absorption_to_smiting::rpSmiteOuterChargeDrain() {
    // draws off 1 charge
    return 1;
}

int Rods_absorption_to_smiting::rpSmiteOuterDamageMultiple() {
    // and causes triple damage
    return 3;
}

int Rods_absorption_to_smiting::rpSmiteRechargeable() {
    // it cannot be recharged
    return 0;
}
