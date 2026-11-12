// R-refactor: split from staves_command_to_withering.h - definitions
#include "rules/dmg/staves_command_to_withering.h"

int Staves_command_to_withering::stfStaffLevelOfUse() {
    // staves function at the 8th level of magic-use
    return 8;
}

int Staves_command_to_withering::stfDischargeSegments() {
    // the magic functions discharge in 2 segments
    return 2;
}

int Staves_command_to_withering::stfRechargeSegments() {
    // build up power again: 8 segments
    return 8;
}

int Staves_command_to_withering::stfNominalDamageDice() {
    // nominal damage is 8d6 for fireballs,
    // lightning bolts, etc.
    return 8;
}

int Staves_command_to_withering::stfNominalDamageDieFaces() {
    return 6;
}

int Staves_command_to_withering::stfStaffCount() {
    // the staves subsection describes seven staves
    return 7;
}

int Staves_command_to_withering::stfCmdFunctionCount() {
    // Staff of Command: 3 functions
    return 3;
}

int Staves_command_to_withering::stfCmdMuEffectiveFunctions() {
    // only 2 effective for a magic-user,
    // all 3 in cleric hands
    return 2;
}

int Staves_command_to_withering::stfCmdHumanInfluenceCharge() {
    // each suggestion or charm: 1 charge
    return 1;
}

int Staves_command_to_withering::stfCmdControlChargePerTurn() {
    // mammal/animal control: 1 charge per
    // turn or fraction thereof
    return 1;
}

int Staves_command_to_withering::stfCmdPlantAreaInches() {
    // plant control: 1" square area of plants
    // per 1 turn or less, at 1 charge
    return 1;
}

int Staves_command_to_withering::stfCmdRechargeable() {
    // it can be recharged
    return 1;
}

int Staves_command_to_withering::stfCureFunctionCount() {
    // Staff of Curing: disease, blindness,
    // wounds, insanity
    return 4;
}

int Staves_command_to_withering::stfCureWoundsHpLo() {
    // cure wounds: 6-21 hit points
    return 6;
}

int Staves_command_to_withering::stfCureWoundsHpHi() {
    return 21;
}

int Staves_command_to_withering::stfCureChargePerFunction() {
    // each function drains 1 charge
    return 1;
}

int Staves_command_to_withering::stfCureUsesPerPersonPerDay() {
    // once per day on any person
    return 1;
}

int Staves_command_to_withering::stfCureMaxPerFunctionPerDay() {
    // no function more than twice per day
    return 2;
}

int Staves_command_to_withering::stfCureMaxPerDay() {
    // only 8 functions per 24 hour period
    return 8;
}

int Staves_command_to_withering::stfCureRechargeable() {
    // it can be recharged
    return 1;
}

int Staves_command_to_withering::stfMagiFreePowerCount() {
    // Staff of the Magi: detect magic,
    // enlarge, hold portal, light,
    // protection from evil/good
    return 5;
}

int Staves_command_to_withering::stfMagiOneChargePowerCount() {
    // invisibility, fireball, knock,
    // lightning bolt, pyrotechnics,
    // ice storm, web, wall of fire,
    // dispel magic, passwall
    return 10;
}

int Staves_command_to_withering::stfMagiTwoChargePowerCount() {
    // whirlwind, plane travel,
    // conjure elemental, telekinesis
    return 4;
}

int Staves_command_to_withering::stfMagiElementalHitDice() {
    // each conjured elemental: 8 hit dice
    return 8;
}

int Staves_command_to_withering::stfMagiTelekinesisPounds() {
    // telekinesis at 8th level: 200 pounds
    return 200;
}

int Staves_command_to_withering::stfMagiSaveBonus() {
    // +2 to all saving throws versus magic
    return 2;
}

int Staves_command_to_withering::stfMagiRechargeable() {
    // absorption is the ONLY way it recharges
    return 1;
}

int Staves_command_to_withering::stfStrikeGlobeRadiusInches() {
    // retributive strike: 3" radius globe
    return 3;
}

int Staves_command_to_withering::stfStrikeDamageMultiple(int i) {
    // within 1", between 1-2", and 2-3" of
    // the broken staff; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        8, 6, 4,
    };
    return t[i];
}

int Staves_command_to_withering::stfStrikeMaxSpellLevels() {
    // the spell levels of energy: 1 to 25
    return 25;
}

int Staves_command_to_withering::stfStrikeSaveHalf() {
    // a save versus magic leaves one-half
    // damage
    return 1;
}

int Staves_command_to_withering::stfStrikePlaneTravelPercent() {
    // the breaker: 50% plane travelling
    return 50;
}

int Staves_command_to_withering::stfStrikeCapableItems() {
    // the magi and the power only
    return 2;
}

int Staves_command_to_withering::stfPowerOneChargeCount() {
    // Staff of Power: continual light, magic
    // missile or lightning bolt, ray of
    // enfeeblement, cone of cold or fireball,
    // darkness 5 ft radius, levitation
    return 6;
}

int Staves_command_to_withering::stfPowerTwoChargeCount() {
    // shield, globe of invulnerability,
    // paralyzation
    return 3;
}

int Staves_command_to_withering::stfPowerAcSaveBonus() {
    // the wielder: +2 on armor class and
    // saving throws
    return 2;
}

int Staves_command_to_withering::stfPowerSmiteBonus() {
    // strikes as a +2 magic weapon
    return 2;
}

int Staves_command_to_withering::stfPowerSmiteDamageLo() {
    // 3-8 hit points of damage
    return 3;
}

int Staves_command_to_withering::stfPowerSmiteDamageHi() {
    return 8;
}

int Staves_command_to_withering::stfPowerSmiteDoubleChargeCost() {
    // 1 charge expended: double damage
    return 1;
}

int Staves_command_to_withering::stfPowerSmiteTripleAllowed() {
    // 2 charges do NOT triple the damage
    return 0;
}

int Staves_command_to_withering::stfPowerParalysisConeLengthInches() {
    // the paralyzation ray: cone 4" long
    return 4;
}

int Staves_command_to_withering::stfPowerParalysisConeWidthInches() {
    // and 2" wide at its base
    return 2;
}

int Staves_command_to_withering::stfPowerRechargeable() {
    // it can be recharged
    return 1;
}

int Staves_command_to_withering::stfSerpentVarietyCount() {
    // Staff of the Serpent: the Python and
    // the Adder
    return 2;
}

int Staves_command_to_withering::stfPythonBonus() {
    // the python strikes as a +2 magic weapon
    return 2;
}

int Staves_command_to_withering::stfPythonDamageLo() {
    // 3-8 hit points when it hits
    return 3;
}

int Staves_command_to_withering::stfPythonDamageHi() {
    return 8;
}

int Staves_command_to_withering::stfPythonSnakeLengthFeet() {
    // the constrictor snake: 25 feet long
    return 25;
}

int Staves_command_to_withering::stfPythonSnakeAc() {
    return 3;
}

int Staves_command_to_withering::stfPythonSnakeHp() {
    return 49;
}

int Staves_command_to_withering::stfPythonSnakeMoveInches() {
    return 9;
}

int Staves_command_to_withering::stfPythonTransformRounds() {
    // the snake forms in 1 round
    return 1;
}

int Staves_command_to_withering::stfPythonConstrictLo() {
    // constriction: 4-10 hit points per round
    return 4;
}

int Staves_command_to_withering::stfPythonConstrictHi() {
    return 10;
}

int Staves_command_to_withering::stfAdderBonus() {
    // the adder strikes as a +1 magic weapon
    return 1;
}

int Staves_command_to_withering::stfAdderDamageLo() {
    // 2-4 hit points when it hits
    return 2;
}

int Staves_command_to_withering::stfAdderDamageHi() {
    return 4;
}

int Staves_command_to_withering::stfAdderHeadAc() {
    // the serpent head: AC 5
    return 5;
}

int Staves_command_to_withering::stfAdderHeadHp() {
    return 20;
}

int Staves_command_to_withering::stfAdderHeadTurns() {
    // the head remains 1 full turn
    return 1;
}

int Staves_command_to_withering::stfAdderPoisonSaveOrDie() {
    // a hit: save versus poison or be slain
    return 1;
}

int Staves_command_to_withering::stfSerpentHasCharges() {
    // neither staff has or requires charges
    return 0;
}

int Staves_command_to_withering::stfSerpentPythonPercent() {
    // 60% of these staves are pythons
    return 60;
}

int Staves_command_to_withering::stfStrikingBonus() {
    // Staff of Striking: a +3 magic weapon
    return 3;
}

int Staves_command_to_withering::stfStrikingDamageLo() {
    // 4-9 (d6 + 3) points of damage
    return 4;
}

int Staves_command_to_withering::stfStrikingDamageHi() {
    return 9;
}

int Staves_command_to_withering::stfStrikingBonusPerCharge(int i) {
    // the bonus at 1, 2 and 3 charges:
    // d6 + 3, d6 + 6, d6 + 9; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        3, 6, 9,
    };
    return t[i];
}

int Staves_command_to_withering::stfStrikingMaxChargesPerStrike() {
    // no more than 3 charges per strike
    return 3;
}

int Staves_command_to_withering::stfStrikingRechargeable() {
    // it can be recharged
    return 1;
}

int Staves_command_to_withering::stfWitherBonus() {
    // Staff of Withering: a +1 magic weapon
    return 1;
}

int Staves_command_to_withering::stfWitherDamageLo() {
    // 2-5 points of damage
    return 2;
}

int Staves_command_to_withering::stfWitherDamageHi() {
    return 5;
}

int Staves_command_to_withering::stfWitherAgeYears() {
    // 2 charges: the creature ages 10 years
    return 10;
}

int Staves_command_to_withering::stfWitherLimbCharges() {
    // 3 charges: 1 limb withers unless it
    // saves versus magic
    return 3;
}

int Staves_command_to_withering::stfWitherAgelessImmune() {
    // undead, demons, devils and the like
    // cannot be aged or withered
    return 1;
}
