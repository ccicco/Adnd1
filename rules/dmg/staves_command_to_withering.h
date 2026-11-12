// ====================================================================
// Adnd1 - rules/dmg/staves_command_to_withering.h
// R245: the III.D staves explanation prose
// pins (DMG pp.142-143) - the staff
// conventions and the per-item facts of
// the SEVEN staves of the RODS, et al.
// explanation prose (upload lines
// ~10688-10785):
//   - the conventions: staves function
//     at the 8th level of magic-use; the
//     magic functions discharge in 2
//     segments and build up again in 8;
//     nominal damage is 8d6.
//   - Staff of Command: 3 functions, only
//     2 effective for a magic-user; 1
//     charge per suggestion or charm, 1
//     per turn of mammal/animal control,
//     1 per 1" square of plants per turn.
//   - Staff of Curing: 4 functions; cure
//     wounds 6-21 hit points (3d6 + 3);
//     1 charge each; once per person per
//     day, max twice per function, 8
//     uses per 24 hours.
//   - Staff of the Magi: 5 free powers
//     (detect magic, enlarge, hold portal,
//     light, protection from evil/good),
//     10 powers at 1 charge, 4 at 2
//     charges; elementals 8 hit dice;
//     telekinesis 200 pounds; +2 saves
//     versus magic. JUDGMENT: rechargeable
//     is pinned 1 - absorption is the
//     ONLY way it recharges.
//   - The retributive strike (shared by
//     the magi and the power): a 3" radius
//     globe; damage 8/6/4 times the spell
//     levels (1 to 25) by distance band;
//     save for half; 50% plane travel for
//     the breaker; 2 items capable.
//   - Staff of Power: 6 one-charge powers
//     (continual light, magic missile or
//     lightning bolt, ray of enfeeblement,
//     cone of cold or fireball, darkness
//     5 ft radius, levitation) and 3
//     two-charge powers (shield, globe of
//     invulnerability, paralyzation - the
//     book prints these lists in merged
//     two-column lines; the counts are
//     pinned, the names ride the comments).
//     +2 AC and saves; smite +2 for 3-8;
//     1 charge doubles, 2 do not triple;
//     paralyzation cone 4" long, 2" wide.
//   - Staff of the Serpent: 2 varieties;
//     the python +2 for 3-8, snake 25 ft
//     AC 3 49 hp 9" move, constriction
//     4-10 per round; the adder +1 for
//     2-4, head AC 5 20 hp for 1 turn,
//     save versus poison or die; NO
//     charges; 60% pythons.
//   - Staff of Striking: +3; 4-9 (d6 + 3);
//     bonus 3/6/9 at 1/2/3 charges; max 3
//     charges per strike.
//   - Staff of Withering: +1; 2-5; 2
//     charges age 10 years; 3 wither a
//     limb unless saved; ageless creatures
//     immune. JUDGMENT: it prints NO
//     recharge statement - unpinned.
// The seven staves are the engine III.D
// table rows 8-14 (dm/treasure.cpp kRods,
// bands 20-33); the wand rows begin at
// band 34.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Staves_command_to_withering (instance methods)
class Staves_command_to_withering {
public:
    int stfStaffLevelOfUse();
    int stfDischargeSegments();
    int stfRechargeSegments();
    int stfNominalDamageDice();
    int stfNominalDamageDieFaces();
    int stfStaffCount();
    int stfCmdFunctionCount();
    int stfCmdMuEffectiveFunctions();
    int stfCmdHumanInfluenceCharge();
    int stfCmdControlChargePerTurn();
    int stfCmdPlantAreaInches();
    int stfCmdRechargeable();
    int stfCureFunctionCount();
    int stfCureWoundsHpLo();
    int stfCureWoundsHpHi();
    int stfCureChargePerFunction();
    int stfCureUsesPerPersonPerDay();
    int stfCureMaxPerFunctionPerDay();
    int stfCureMaxPerDay();
    int stfCureRechargeable();
    int stfMagiFreePowerCount();
    int stfMagiOneChargePowerCount();
    int stfMagiTwoChargePowerCount();
    int stfMagiElementalHitDice();
    int stfMagiTelekinesisPounds();
    int stfMagiSaveBonus();
    int stfMagiRechargeable();
    int stfStrikeGlobeRadiusInches();
    int stfStrikeDamageMultiple(int i);
    int stfStrikeMaxSpellLevels();
    int stfStrikeSaveHalf();
    int stfStrikePlaneTravelPercent();
    int stfStrikeCapableItems();
    int stfPowerOneChargeCount();
    int stfPowerTwoChargeCount();
    int stfPowerAcSaveBonus();
    int stfPowerSmiteBonus();
    int stfPowerSmiteDamageLo();
    int stfPowerSmiteDamageHi();
    int stfPowerSmiteDoubleChargeCost();
    int stfPowerSmiteTripleAllowed();
    int stfPowerParalysisConeLengthInches();
    int stfPowerParalysisConeWidthInches();
    int stfPowerRechargeable();
    int stfSerpentVarietyCount();
    int stfPythonBonus();
    int stfPythonDamageLo();
    int stfPythonDamageHi();
    int stfPythonSnakeLengthFeet();
    int stfPythonSnakeAc();
    int stfPythonSnakeHp();
    int stfPythonSnakeMoveInches();
    int stfPythonTransformRounds();
    int stfPythonConstrictLo();
    int stfPythonConstrictHi();
    int stfAdderBonus();
    int stfAdderDamageLo();
    int stfAdderDamageHi();
    int stfAdderHeadAc();
    int stfAdderHeadHp();
    int stfAdderHeadTurns();
    int stfAdderPoisonSaveOrDie();
    int stfSerpentHasCharges();
    int stfSerpentPythonPercent();
    int stfStrikingBonus();
    int stfStrikingDamageLo();
    int stfStrikingDamageHi();
    int stfStrikingBonusPerCharge(int i);
    int stfStrikingMaxChargesPerStrike();
    int stfStrikingRechargeable();
    int stfWitherBonus();
    int stfWitherDamageLo();
    int stfWitherDamageHi();
    int stfWitherAgeYears();
    int stfWitherLimbCharges();
    int stfWitherAgelessImmune();
};
