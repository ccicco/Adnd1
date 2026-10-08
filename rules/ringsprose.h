// ====================================================================
// Adnd1 - rules/ringsprose.h
// R253: the III.C rings explanation prose
// pins, part 1 of 3 (DMG pp.137-138) - the
// general ring mechanics and the four lead
// rings of the EXPLANATIONS AND
// DESCRIPTIONS section (upload lines
// ~10281-10392):
//   - mechanics: max 2 rings worn (if more
//     are worn none function), max 1 per
//     hand (a 2nd makes both useless);
//     spell-like abilities function as
//     12th level of magic use; gnomes,
//     dwarves and halflings have a 20%
//     per-use malfunction chance (the
//     three cursed rings named:
//     contrariness, delusion, weakness);
//     the double-dagger symbol marks the
//     most powerful rings, often with
//     limited charges at the DM option.
//   - Ring of Contrariness: removable
//     only via remove curse; the
//     6-band additional-properties table
//     (01-20 Flying, 21-40 Invisibility,
//     41-60 Levitation, 61-70 Shocking
//     Grasp once per round, 71-80 Spell
//     Turning, 81-00 Strength 18/00);
//     a cumulative remove curse must
//     equal or exceed 00 (100%).
//   - Ring of Delusion: removable at any
//     time.
//   - Ring of Djinni Summoning: the
//     djinni appears the next round; a
//     killed servant makes the ring
//     non-magical and worthless.
//   - Ring of Elemental Command: 4
//     types; elementals cannot approach
//     within 5 feet (or a charm attempt,
//     elemental saving throw at -2);
//     plane creatures attack at -1, the
//     wearer takes damage at -1 per hit
//     die, saves at +2, attacks at +4
//     (or elemental saves at -4), does
//     +6 damage total; the 4-plane save
//     penalty list (all -2); only one
//     power at a time; the four power
//     lists: Air 5 (gust of wind once per
//     round, fly, wall of force once per
//     day, control winds once per week,
//     invisibility), Earth 6 (stone tell
//     once per day, passwall twice per
//     day, wall of stone once per day,
//     stone to flesh twice per week,
//     move earth once per week, feather
//     fall), Fire 5 (burning hands once
//     per turn, pyrotechnics twice per
//     day, wall of fire once per day,
//     flame strike twice per week, fire
//     resistance), Water 8 (purify
//     water, create water once per day,
//     water breathing with a 5 foot
//     radius, wall of ice once per day,
//     airy water, lower water twice per
//     week, part water twice per week,
//     water walking); the rings appear
//     as the lesser rings (invisibility,
//     feather falling, fire resistance,
//     water walking) until a condition
//     is met.
//   - closing: rings operate at 12th
//     level of experience; additional
//     powers take 5 segments to bring
//     forth.
// The four rings are the engine III.C
// table rows 1-15 (dm/treasure.cpp
// kRings, the R223 rings.h band pins) -
// cross-checked in the audit; the djinni
// double-dagger cross-pins the R223
// ringIsChargeLimited row 2. Pure data
// + helpers, header-only (the grenade.h
// pattern).
// ====================================================================

#pragma once

namespace rules {

inline int rgpMaxWornCount() {
    // no more than 2 magic rings can be
    // worn at once; if more are worn
    // then none will function
    return 2;
}

inline int rgpMaxPerHand() {
    // no more than 1 per hand; a 2nd
    // will cause both to be useless
    return 1;
}

inline int rgpSpellLikeLevel() {
    // spell-like abilities function as
    // 12th level of magic use unless
    // the power requires higher
    return 12;
}

inline int rgpSmallCharMalfunctionPercent() {
    // rings worn by gnomes, dwarves
    // and halflings malfunction 20%
    // per use (the ring does not work)
    return 20;
}

inline int rgpCursedMalfunctionNamedCount() {
    // the cursed rings the malfunction
    // rule names: contrariness,
    // delusion, weakness
    return 3;
}

inline int rgpContrarinessPropertyRowCount() {
    // the additional-properties table:
    // 6 die bands
    return 6;
}

inline int rgpContrarinessPropLo(int i) {
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

inline int rgpContrarinessPropHi(int i) {
    // the band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        20, 40, 60, 70, 80, 100,
    };
    return t[i];
}

inline int rgpContrarinessShockingGraspPerRound() {
    // the 61-70 property: shocking
    // grasp once per round
    return 1;
}

inline int rgpContrarinessStrengthScore() {
    // the 81-00 property: strength
    // 18/00
    return 18;
}

inline int rgpContrarinessRemoveCursePercent() {
    // a cumulative remove curse must
    // equal or exceed 00 (100%)
    return 100;
}

inline int rgpDjinniAppearDelayRounds() {
    // when the ring is rubbed the
    // djinni will appear on the next
    // round
    return 1;
}

inline int rgpElemCommandTypeCount() {
    // the 4 types of elemental
    // command rings
    return 4;
}

inline int rgpElemCommandKeepAwayFeet() {
    // attuned elementals cannot
    // approach within 5 feet of or
    // attack the wearer
    return 5;
}

inline int rgpElemCommandCharmSaveMod() {
    // the alternative charm attempt:
    // elemental saving throw at -2
    // on the die
    return -2;
}

inline int rgpElemCommandElemToHitMod() {
    // plane creatures other than normal
    // elementals attack at -1 on
    // to hit
    return -1;
}

inline int rgpElemCommandWearerDamagePerDieMod() {
    // the wearer takes damage at -1
    // on each hit die
    return -1;
}

inline int rgpElemCommandWearerSaveBonus() {
    // the wearer makes applicable
    // saves at +2
    return 2;
}

inline int rgpElemCommandWearerToHitBonus() {
    // wearer attacks at +4 to hit
    return 4;
}

inline int rgpElemCommandElemSaveMod() {
    // or -4 on the elemental
    // creature saving throw
    return -4;
}

inline int rgpElemCommandWearerDamageBonus() {
    // the wearer does +6 damage
    // (total, not per die)
    return 6;
}

inline int rgpElemCommandSavePenaltyRowCount() {
    // the 4-plane save penalty list:
    // Air fire, Earth petrification,
    // Fire water or cold, Water
    // lightning/electricity
    return 4;
}

inline int rgpElemCommandSavePenalty(int i) {
    // every plane penalty is -2;
    // i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        -2, -2, -2, -2,
    };
    return t[i];
}

inline int rgpElemCommandMaxActivePowers() {
    // only one power (major or minor)
    // can be in use at one time
    return 1;
}

inline int rgpElemCommandAirPowerCount() {
    // gust of wind, fly, wall of
    // force, control winds,
    // invisibility
    return 5;
}

inline int rgpElemCommandEarthPowerCount() {
    // stone tell, passwall, wall of
    // stone, stone to flesh,
    // move earth, feather fall
    return 6;
}

inline int rgpElemCommandFirePowerCount() {
    // burning hands, pyrotechnics,
    // wall of fire, flame strike,
    // fire resistance
    return 5;
}

inline int rgpElemCommandWaterPowerCount() {
    // purify water, create water,
    // water breathing, wall of ice,
    // airy water, lower water,
    // part water, water walking
    return 8;
}

inline int rgpElemCommandAirGustPerRound() {
    // gust of wind once per round
    return 1;
}

inline int rgpElemCommandWallOfForcePerDay() {
    // wall of force once per day
    return 1;
}

inline int rgpElemCommandControlWindsPerWeek() {
    // control winds once per week
    return 1;
}

inline int rgpElemCommandStoneTellPerDay() {
    // stone tell once per day
    return 1;
}

inline int rgpElemCommandPasswallPerDay() {
    // passwall twice per day
    return 2;
}

inline int rgpElemCommandWallOfStonePerDay() {
    // wall of stone once per day
    return 1;
}

inline int rgpElemCommandStoneToFleshPerWeek() {
    // stone to flesh twice per week
    return 2;
}

inline int rgpElemCommandMoveEarthPerWeek() {
    // move earth once per week
    return 1;
}

inline int rgpElemCommandBurningHandsPerTurn() {
    // burning hands once per turn
    return 1;
}

inline int rgpElemCommandPyrotechnicsPerDay() {
    // pyrotechnics twice per day
    return 2;
}

inline int rgpElemCommandWallOfFirePerDay() {
    // wall of fire once per day
    return 1;
}

inline int rgpElemCommandFlameStrikePerWeek() {
    // flame strike twice per week
    return 2;
}

inline int rgpElemCommandCreateWaterPerDay() {
    // create water once per day
    return 1;
}

inline int rgpElemCommandWallOfIcePerDay() {
    // wall of ice once per day
    return 1;
}

inline int rgpElemCommandLowerWaterPerWeek() {
    // lower water twice per week
    return 2;
}

inline int rgpElemCommandPartWaterPerWeek() {
    // part water twice per week
    return 2;
}

inline int rgpElemCommandWaterBreathingRadiusFeet() {
    // water breathing with a 5 foot
    // radius
    return 5;
}

inline int rgpOperateLevelExperience() {
    // rings operate at 12th level of
    // experience, or the minimum
    // level needed for the spell
    return 12;
}

inline int rgpPowerActivationSegments() {
    // the additional powers take only
    // 5 segments to bring forth
    return 5;
}

}  // namespace rules

