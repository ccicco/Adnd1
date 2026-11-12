// R-refactor: split from rings_mechanics_contrariness_to_elemental_command.h - definitions
#include "rules/dmg/rings_mechanics_contrariness_to_elemental_command.h"

int Rings_mechanics_contrariness_to_elemental_command::rgpMaxWornCount() {
    // no more than 2 magic rings can be
    // worn at once; if more are worn
    // then none will function
    return 2;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpMaxPerHand() {
    // no more than 1 per hand; a 2nd
    // will cause both to be useless
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpSpellLikeLevel() {
    // spell-like abilities function as
    // 12th level of magic use unless
    // the power requires higher
    return 12;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpSmallCharMalfunctionPercent() {
    // rings worn by gnomes, dwarves
    // and halflings malfunction 20%
    // per use (the ring does not work)
    return 20;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpCursedMalfunctionNamedCount() {
    // the cursed rings the malfunction
    // rule names: contrariness,
    // delusion, weakness
    return 3;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpContrarinessPropertyRowCount() {
    // the additional-properties table:
    // 6 die bands
    return 6;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpContrarinessPropLo(int i) {
    // the band lower edges: 01-20 Flying,
    // 21-40 Invisibility, 41-60
    // Levitation, 61-70 Shocking Grasp
    // once per round, 71-80 Spell
    // Turning, 81-00 Strength 18/00;
    // i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 21, 41, 61, 71, 81,
    };
    return t[i];
}

int Rings_mechanics_contrariness_to_elemental_command::rgpContrarinessPropHi(int i) {
    // the band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        20, 40, 60, 70, 80, 100,
    };
    return t[i];
}

int Rings_mechanics_contrariness_to_elemental_command::rgpContrarinessShockingGraspPerRound() {
    // the 61-70 property: shocking
    // grasp once per round
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpContrarinessStrengthScore() {
    // the 81-00 property: strength
    // 18/00
    return 18;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpContrarinessRemoveCursePercent() {
    // a cumulative remove curse must
    // equal or exceed 00 (100%)
    return 100;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpDjinniAppearDelayRounds() {
    // when the ring is rubbed the
    // djinni will appear on the next
    // round
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandTypeCount() {
    // the 4 types of elemental
    // command rings
    return 4;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandKeepAwayFeet() {
    // attuned elementals cannot
    // approach within 5 feet of or
    // attack the wearer
    return 5;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandCharmSaveMod() {
    // the alternative charm attempt:
    // elemental saving throw at -2
    // on the die
    return -2;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandElemToHitMod() {
    // plane creatures other than normal
    // elementals attack at -1 on
    // to hit
    return -1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandWearerDamagePerDieMod() {
    // the wearer takes damage at -1
    // on each hit die
    return -1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandWearerSaveBonus() {
    // the wearer makes applicable
    // saves at +2
    return 2;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandWearerToHitBonus() {
    // wearer attacks at +4 to hit
    return 4;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandElemSaveMod() {
    // or -4 on the elemental
    // creature saving throw
    return -4;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandWearerDamageBonus() {
    // the wearer does +6 damage
    // (total, not per die)
    return 6;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandSavePenaltyRowCount() {
    // the 4-plane save penalty list:
    // Air fire, Earth petrification,
    // Fire water or cold, Water
    // lightning/electricity
    return 4;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandSavePenalty(int i) {
    // every plane penalty is -2;
    // i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        -2, -2, -2, -2,
    };
    return t[i];
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandMaxActivePowers() {
    // only one power (major or minor)
    // can be in use at one time
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandAirPowerCount() {
    // gust of wind, fly, wall of
    // force, control winds,
    // invisibility
    return 5;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandEarthPowerCount() {
    // stone tell, passwall, wall of
    // stone, stone to flesh,
    // move earth, feather fall
    return 6;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandFirePowerCount() {
    // burning hands, pyrotechnics,
    // wall of fire, flame strike,
    // fire resistance
    return 5;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandWaterPowerCount() {
    // purify water, create water,
    // water breathing, wall of ice,
    // airy water, lower water,
    // part water, water walking
    return 8;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandAirGustPerRound() {
    // gust of wind once per round
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandWallOfForcePerDay() {
    // wall of force once per day
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandControlWindsPerWeek() {
    // control winds once per week
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandStoneTellPerDay() {
    // stone tell once per day
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandPasswallPerDay() {
    // passwall twice per day
    return 2;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandWallOfStonePerDay() {
    // wall of stone once per day
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandStoneToFleshPerWeek() {
    // stone to flesh twice per week
    return 2;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandMoveEarthPerWeek() {
    // move earth once per week
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandBurningHandsPerTurn() {
    // burning hands once per turn
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandPyrotechnicsPerDay() {
    // pyrotechnics twice per day
    return 2;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandWallOfFirePerDay() {
    // wall of fire once per day
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandFlameStrikePerWeek() {
    // flame strike twice per week
    return 2;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandCreateWaterPerDay() {
    // create water once per day
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandWallOfIcePerDay() {
    // wall of ice once per day
    return 1;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandLowerWaterPerWeek() {
    // lower water twice per week
    return 2;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandPartWaterPerWeek() {
    // part water twice per week
    return 2;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpElemCommandWaterBreathingRadiusFeet() {
    // water breathing with a 5 foot
    // radius
    return 5;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpOperateLevelExperience() {
    // rings operate at 12th level of
    // experience, or the minimum
    // level needed for the spell
    return 12;
}

int Rings_mechanics_contrariness_to_elemental_command::rgpPowerActivationSegments() {
    // the additional powers take only
    // 5 segments to bring forth
    return 5;
}
