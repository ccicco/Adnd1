// ====================================================================
// Adnd1 - rules/stavesprose.h
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

namespace rules {

inline int stfStaffLevelOfUse() {
    // staves function at the 8th level of magic-use
    return 8;
}

inline int stfDischargeSegments() {
    // the magic functions discharge in 2 segments
    return 2;
}

inline int stfRechargeSegments() {
    // build up power again: 8 segments
    return 8;
}

inline int stfNominalDamageDice() {
    // nominal damage is 8d6 for fireballs,
    // lightning bolts, etc.
    return 8;
}

inline int stfNominalDamageDieFaces() {
    return 6;
}

inline int stfStaffCount() {
    // the staves subsection describes seven staves
    return 7;
}

inline int stfCmdFunctionCount() {
    // Staff of Command: 3 functions
    return 3;
}

inline int stfCmdMuEffectiveFunctions() {
    // only 2 effective for a magic-user,
    // all 3 in cleric hands
    return 2;
}

inline int stfCmdHumanInfluenceCharge() {
    // each suggestion or charm: 1 charge
    return 1;
}

inline int stfCmdControlChargePerTurn() {
    // mammal/animal control: 1 charge per
    // turn or fraction thereof
    return 1;
}

inline int stfCmdPlantAreaInches() {
    // plant control: 1" square area of plants
    // per 1 turn or less, at 1 charge
    return 1;
}

inline int stfCmdRechargeable() {
    // it can be recharged
    return 1;
}

inline int stfCureFunctionCount() {
    // Staff of Curing: disease, blindness,
    // wounds, insanity
    return 4;
}

inline int stfCureWoundsHpLo() {
    // cure wounds: 6-21 hit points
    return 6;
}

inline int stfCureWoundsHpHi() {
    return 21;
}

inline int stfCureChargePerFunction() {
    // each function drains 1 charge
    return 1;
}

inline int stfCureUsesPerPersonPerDay() {
    // once per day on any person
    return 1;
}

inline int stfCureMaxPerFunctionPerDay() {
    // no function more than twice per day
    return 2;
}

inline int stfCureMaxPerDay() {
    // only 8 functions per 24 hour period
    return 8;
}

inline int stfCureRechargeable() {
    // it can be recharged
    return 1;
}

inline int stfMagiFreePowerCount() {
    // Staff of the Magi: detect magic,
    // enlarge, hold portal, light,
    // protection from evil/good
    return 5;
}

inline int stfMagiOneChargePowerCount() {
    // invisibility, fireball, knock,
    // lightning bolt, pyrotechnics,
    // ice storm, web, wall of fire,
    // dispel magic, passwall
    return 10;
}

inline int stfMagiTwoChargePowerCount() {
    // whirlwind, plane travel,
    // conjure elemental, telekinesis
    return 4;
}

inline int stfMagiElementalHitDice() {
    // each conjured elemental: 8 hit dice
    return 8;
}

inline int stfMagiTelekinesisPounds() {
    // telekinesis at 8th level: 200 pounds
    return 200;
}

inline int stfMagiSaveBonus() {
    // +2 to all saving throws versus magic
    return 2;
}

inline int stfMagiRechargeable() {
    // absorption is the ONLY way it recharges
    return 1;
}

inline int stfStrikeGlobeRadiusInches() {
    // retributive strike: 3" radius globe
    return 3;
}

inline int stfStrikeDamageMultiple(int i) {
    // within 1", between 1-2", and 2-3" of
    // the broken staff; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        8, 6, 4,
    };
    return t[i];
}

inline int stfStrikeMaxSpellLevels() {
    // the spell levels of energy: 1 to 25
    return 25;
}

inline int stfStrikeSaveHalf() {
    // a save versus magic leaves one-half
    // damage
    return 1;
}

inline int stfStrikePlaneTravelPercent() {
    // the breaker: 50% plane travelling
    return 50;
}

inline int stfStrikeCapableItems() {
    // the magi and the power only
    return 2;
}

inline int stfPowerOneChargeCount() {
    // Staff of Power: continual light, magic
    // missile or lightning bolt, ray of
    // enfeeblement, cone of cold or fireball,
    // darkness 5 ft radius, levitation
    return 6;
}

inline int stfPowerTwoChargeCount() {
    // shield, globe of invulnerability,
    // paralyzation
    return 3;
}

inline int stfPowerAcSaveBonus() {
    // the wielder: +2 on armor class and
    // saving throws
    return 2;
}

inline int stfPowerSmiteBonus() {
    // strikes as a +2 magic weapon
    return 2;
}

inline int stfPowerSmiteDamageLo() {
    // 3-8 hit points of damage
    return 3;
}

inline int stfPowerSmiteDamageHi() {
    return 8;
}

inline int stfPowerSmiteDoubleChargeCost() {
    // 1 charge expended: double damage
    return 1;
}

inline int stfPowerSmiteTripleAllowed() {
    // 2 charges do NOT triple the damage
    return 0;
}

inline int stfPowerParalysisConeLengthInches() {
    // the paralyzation ray: cone 4" long
    return 4;
}

inline int stfPowerParalysisConeWidthInches() {
    // and 2" wide at its base
    return 2;
}

inline int stfPowerRechargeable() {
    // it can be recharged
    return 1;
}

inline int stfSerpentVarietyCount() {
    // Staff of the Serpent: the Python and
    // the Adder
    return 2;
}

inline int stfPythonBonus() {
    // the python strikes as a +2 magic weapon
    return 2;
}

inline int stfPythonDamageLo() {
    // 3-8 hit points when it hits
    return 3;
}

inline int stfPythonDamageHi() {
    return 8;
}

inline int stfPythonSnakeLengthFeet() {
    // the constrictor snake: 25 feet long
    return 25;
}

inline int stfPythonSnakeAc() {
    return 3;
}

inline int stfPythonSnakeHp() {
    return 49;
}

inline int stfPythonSnakeMoveInches() {
    return 9;
}

inline int stfPythonTransformRounds() {
    // the snake forms in 1 round
    return 1;
}

inline int stfPythonConstrictLo() {
    // constriction: 4-10 hit points per round
    return 4;
}

inline int stfPythonConstrictHi() {
    return 10;
}

inline int stfAdderBonus() {
    // the adder strikes as a +1 magic weapon
    return 1;
}

inline int stfAdderDamageLo() {
    // 2-4 hit points when it hits
    return 2;
}

inline int stfAdderDamageHi() {
    return 4;
}

inline int stfAdderHeadAc() {
    // the serpent head: AC 5
    return 5;
}

inline int stfAdderHeadHp() {
    return 20;
}

inline int stfAdderHeadTurns() {
    // the head remains 1 full turn
    return 1;
}

inline int stfAdderPoisonSaveOrDie() {
    // a hit: save versus poison or be slain
    return 1;
}

inline int stfSerpentHasCharges() {
    // neither staff has or requires charges
    return 0;
}

inline int stfSerpentPythonPercent() {
    // 60% of these staves are pythons
    return 60;
}

inline int stfStrikingBonus() {
    // Staff of Striking: a +3 magic weapon
    return 3;
}

inline int stfStrikingDamageLo() {
    // 4-9 (d6 + 3) points of damage
    return 4;
}

inline int stfStrikingDamageHi() {
    return 9;
}

inline int stfStrikingBonusPerCharge(int i) {
    // the bonus at 1, 2 and 3 charges:
    // d6 + 3, d6 + 6, d6 + 9; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        3, 6, 9,
    };
    return t[i];
}

inline int stfStrikingMaxChargesPerStrike() {
    // no more than 3 charges per strike
    return 3;
}

inline int stfStrikingRechargeable() {
    // it can be recharged
    return 1;
}

inline int stfWitherBonus() {
    // Staff of Withering: a +1 magic weapon
    return 1;
}

inline int stfWitherDamageLo() {
    // 2-5 points of damage
    return 2;
}

inline int stfWitherDamageHi() {
    return 5;
}

inline int stfWitherAgeYears() {
    // 2 charges: the creature ages 10 years
    return 10;
}

inline int stfWitherLimbCharges() {
    // 3 charges: 1 limb withers unless it
    // saves versus magic
    return 3;
}

inline int stfWitherAgelessImmune() {
    // undead, demons, devils and the like
    // cannot be aged or withered
    return 1;
}

}  // namespace rules

