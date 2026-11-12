// ====================================================================
// Adnd1 - rules/dmg/rods_absorption_to_smiting.h
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

// R-refactor: namespace rules -> class Rods_absorption_to_smiting (instance methods)
class Rods_absorption_to_smiting {
public:
    int rpRodChargesMax();
    int rpRodChargesDieLo();
    int rpRodChargesDieHi();
    int rpStaffChargesMax();
    int rpStaffChargesDieLo();
    int rpStaffChargesDieHi();
    int rpWandChargesMax();
    int rpWandChargesDieLo();
    int rpWandChargesDieHi();
    int rpDrainedCrumble();
    int rpCommandWordRule();
    int rpSilenceBlocks();
    int rpRodCount();
    int rpAbsorbMaxSpellLevels();
    int rpAbsorbCastSegments();
    int rpAbsorbRechargeable();
    int rpBeguileRadiusInches();
    int rpBeguileMinIntelligence();
    int rpBeguileHasSave();
    int rpBeguileTurnsPerCharge();
    int rpBeguileRechargeable();
    int rpCancSaveCount();
    int rpCancSaveValue(int i);
    int rpCancArmorShieldPlus5();
    int rpCancHolySword();
    int rpCancDrainedRestorable();
    int rpCancRodBecomesBrittle();
    int rpLmWeightPounds();
    int rpLmMinStrength();
    int rpLmStrBelowPenalty();
    int rpLmSpellLikeCount();
    int rpLmSpellCostCharges();
    int rpLmFearRangeInches();
    int rpLmDrainHpLo();
    int rpLmDrainHpHi();
    int rpLmWeaponFormCount();
    int rpLmWeaponBonus(int i);
    int rpLmSpearLenMinFeet();
    int rpLmSpearLenMaxFeet();
    int rpLmSpearHandleMaxFeet();
    int rpLmMundaneUseCount();
    int rpLmPoleGrowthPerSegment();
    int rpLmPoleMaxFeet();
    int rpLmPoleBearPounds();
    int rpLmDoorForceMaxFeet();
    int rpLmRechargeable();
    int rpLmExhaustedWeaponCeaseLo();
    int rpLmExhaustedWeaponCeaseHi();
    int rpResUsesPerDay();
    int rpResClassCount();
    int rpResClassCharges(int i);
    int rpResRaceCount();
    int rpResRaceCharges(int i);
    int rpResMultiLeastFavorable();
    int rpResRechargeable();
    int rpRuleRadiusInches();
    int rpRuleHdLo();
    int rpRuleHdHi();
    int rpRuleSaveIntMin();
    int rpRuleSaveHdMin();
    int rpRuleActivateSegments();
    int rpRuleTurnsPerCharge();
    int rpRuleRechargeable();
    int rpSmiteBonus();
    int rpSmiteDamageLo();
    int rpSmiteDamageHi();
    int rpSmiteGolemDamageLo();
    int rpSmiteGolemDamageHi();
    int rpSmiteGolemDestroyRoll();
    int rpSmiteGolemHitChargeDrain();
    int rpSmiteOuterTripleRoll();
    int rpSmiteOuterChargeDrain();
    int rpSmiteOuterDamageMultiple();
    int rpSmiteRechargeable();
};
