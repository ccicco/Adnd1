// ====================================================================
// Adnd1 - rules/dmg/potions_conventions_animal_control_to_extra_healing.h
// R249: the III.A potions explanation prose
// pins, part 1 (DMG pp.133-134) - the general
// conventions and the FIRST NINE potion
// explanations (upload lines ~9998-10062):
//   - the conventions: effects last 4
//     complete turns plus 1-4 additional
//     turns (d4); half doses last half as
//     long in some cases; potions take
//     effect 2-5 segments after they are
//     imbibed.
//   - Animal Control: 5-20 giant-rat-size,
//     3-12 man-size, or 1-4 half-ton-plus
//     animals; save at intelligence 5+; the
//     7-row d20 animal type sub-table.
//   - Clairaudience: 3" range, 2 turns.
//   - Clairvoyance: 3" range, 1 turn.
//   - Climbing: base 1% slip, 01 falls at
//     the halfway d% check, 1 turn + 5-20
//     rounds, +1% per 1,000 g.p. carried;
//     the 7-row armor table (studded
//     leather 1%, ring mail 2%, scale mail
//     4%, chainmail 7%, banded or
//     splinted 8%, plate mail 10%, magic
//     armor any type 1%).
//   - Delusion: 90% likely tasters agree.
//   - Diminution: to 5% size (50% on half
//     dose), 6 turns + 2-5 turns (d4+1).
//   - Dragon Control: charm monster within
//     6", save at -2; the 12-row d20
//     dragon type sub-table; control lasts
//     5-20 (5d4) rounds.
//   - ESP: 5-40 (5d8) rounds.
//   - Extra-Healing: 6-27 (3d8+3) whole,
//     1-8 per one-third potion.
// The nine potions are the engine III.A
// table rows 1-9 (dm/treasure.cpp kPotions,
// bands 01-26, fire resistance from 27) -
// cross-checked against the R221 potions.h
// pins in the audit.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Potions_conventions_animal_control_to_extra_healing (instance methods)
class Potions_conventions_animal_control_to_extra_healing {
public:
    int potDurationTurnsBase();
    int potDurationExtraLo();
    int potDurationExtraHi();
    int potOnsetLo();
    int potOnsetHi();
    int potAnimalSmallLo();
    int potAnimalSmallHi();
    int potAnimalManLo();
    int potAnimalManHi();
    int potAnimalLargeLo();
    int potAnimalLargeHi();
    int potAnimalSaveInt();
    int potAnimalTypeRowCount();
    int potAnimalTypeLo(int i);
    int potAnimalTypeHi(int i);
    int potAnimalTypeFaces();
    int potClairaudRangeInches();
    int potClairaudTurns();
    int potClairvoyRangeInches();
    int potClairvoyTurns();
    int potClimbBasePercent();
    int potClimbFallRoll();
    int potClimbTurns();
    int potClimbExtraRoundsLo();
    int potClimbExtraRoundsHi();
    int potClimbLoadIncrementGp();
    int potClimbLoadPercent();
    int potClimbArmorRowCount();
    int potClimbArmorPercent(int i);
    int potDeludeAgreePercent();
    int potDiminishMinPercent();
    int potDiminishHalfPercent();
    int potDiminishTurnsBase();
    int potDiminishExtraLo();
    int potDiminishExtraHi();
    int potDragonRangeInches();
    int potDragonSaveMod();
    int potDragonTypeRowCount();
    int potDragonTypeLo(int i);
    int potDragonTypeHi(int i);
    int potDragonTypeFaces();
    int potDragonLo();
    int potDragonHi();
    int potDragonDice();
    int potDragonFaces();
    int potEspLo();
    int potEspHi();
    int potEspDice();
    int potEspFaces();
    int potXHealLo();
    int potXHealHi();
    int potXHealDice();
    int potXHealFaces();
    int potXHealBonus();
    int potXHealThirdLo();
    int potXHealThirdHi();
};
