// ====================================================================
// Adnd1 - rules/dmg/rings_mechanics_contrariness_to_elemental_command.h
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

// R-refactor: namespace rules -> class Rings_mechanics_contrariness_to_elemental_command (instance methods)
class Rings_mechanics_contrariness_to_elemental_command {
public:
    int rgpMaxWornCount();
    int rgpMaxPerHand();
    int rgpSpellLikeLevel();
    int rgpSmallCharMalfunctionPercent();
    int rgpCursedMalfunctionNamedCount();
    int rgpContrarinessPropertyRowCount();
    int rgpContrarinessPropLo(int i);
    int rgpContrarinessPropHi(int i);
    int rgpContrarinessShockingGraspPerRound();
    int rgpContrarinessStrengthScore();
    int rgpContrarinessRemoveCursePercent();
    int rgpDjinniAppearDelayRounds();
    int rgpElemCommandTypeCount();
    int rgpElemCommandKeepAwayFeet();
    int rgpElemCommandCharmSaveMod();
    int rgpElemCommandElemToHitMod();
    int rgpElemCommandWearerDamagePerDieMod();
    int rgpElemCommandWearerSaveBonus();
    int rgpElemCommandWearerToHitBonus();
    int rgpElemCommandElemSaveMod();
    int rgpElemCommandWearerDamageBonus();
    int rgpElemCommandSavePenaltyRowCount();
    int rgpElemCommandSavePenalty(int i);
    int rgpElemCommandMaxActivePowers();
    int rgpElemCommandAirPowerCount();
    int rgpElemCommandEarthPowerCount();
    int rgpElemCommandFirePowerCount();
    int rgpElemCommandWaterPowerCount();
    int rgpElemCommandAirGustPerRound();
    int rgpElemCommandWallOfForcePerDay();
    int rgpElemCommandControlWindsPerWeek();
    int rgpElemCommandStoneTellPerDay();
    int rgpElemCommandPasswallPerDay();
    int rgpElemCommandWallOfStonePerDay();
    int rgpElemCommandStoneToFleshPerWeek();
    int rgpElemCommandMoveEarthPerWeek();
    int rgpElemCommandBurningHandsPerTurn();
    int rgpElemCommandPyrotechnicsPerDay();
    int rgpElemCommandWallOfFirePerDay();
    int rgpElemCommandFlameStrikePerWeek();
    int rgpElemCommandCreateWaterPerDay();
    int rgpElemCommandWallOfIcePerDay();
    int rgpElemCommandLowerWaterPerWeek();
    int rgpElemCommandPartWaterPerWeek();
    int rgpElemCommandWaterBreathingRadiusFeet();
    int rgpOperateLevelExperience();
    int rgpPowerActivationSegments();
};
