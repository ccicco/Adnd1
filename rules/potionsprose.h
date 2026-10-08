// ====================================================================
// Adnd1 - rules/potionsprose.h
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

namespace rules {

inline int potDurationTurnsBase() {
    // the conventions: effects last 4
    // complete turns
    return 4;
}

inline int potDurationExtraLo() {
    // plus 1-4 additional turns (d4)
    return 1;
}

inline int potDurationExtraHi() {
    return 4;
}

inline int potOnsetLo() {
    // potions take effect 2-5 segments
    // after they are imbibed
    return 2;
}

inline int potOnsetHi() {
    return 5;
}

inline int potAnimalSmallLo() {
    // Animal Control: 5-20 animals of
    // the size of giant rats
    return 5;
}

inline int potAnimalSmallHi() {
    return 20;
}

inline int potAnimalManLo() {
    // 3-12 animals of about man-size
    return 3;
}

inline int potAnimalManHi() {
    return 12;
}

inline int potAnimalLargeLo() {
    // 1-4 animals of about half a ton
    // or more in weight
    return 1;
}

inline int potAnimalLargeHi() {
    return 4;
}

inline int potAnimalSaveInt() {
    // animals with intelligence of 5
    // or better get a save versus magic
    return 5;
}

inline int potAnimalTypeRowCount() {
    // the animal type sub-table: 7 rows
    return 7;
}

inline int potAnimalTypeLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 5, 9, 13, 16, 18, 20,
    };
    return t[i];
}

inline int potAnimalTypeHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        4, 8, 12, 15, 17, 19, 20,
    };
    return t[i];
}

inline int potAnimalTypeFaces() {
    // the animal type roll is on d20
    return 20;
}

inline int potClairaudRangeInches() {
    // Clairaudience: clairaudit unknown
    // areas within 3"
    return 3;
}

inline int potClairaudTurns() {
    // the effects last for 2 turns only
    return 2;
}

inline int potClairvoyRangeInches() {
    // Clairvoyance: unknown areas up to
    // 3" distant can be seen
    return 3;
}

inline int potClairvoyTurns() {
    // the effects last for 1 turn only
    return 1;
}

inline int potClimbBasePercent() {
    // Climbing: a base 1% chance of
    // slipping and falling
    return 1;
}

inline int potClimbFallRoll() {
    // check at the halfway point, d%;
    // 01 equals a fall
    return 1;
}

inline int potClimbTurns() {
    // effective for 1 turn
    return 1;
}

inline int potClimbExtraRoundsLo() {
    // plus 5 to 20 rounds
    return 5;
}

inline int potClimbExtraRoundsHi() {
    return 20;
}

inline int potClimbLoadIncrementGp() {
    // for every 1,000 g.p. weight
    // equivalent carried
    return 1000;
}

inline int potClimbLoadPercent() {
    // an additional 1% chance of slipping
    return 1;
}

inline int potClimbArmorRowCount() {
    // the climbing armor table: 7 rows
    return 7;
}

inline int potClimbArmorPercent(int i) {
    // the armor slip additions; i clamps:
    // studded leather, ring mail, scale
    // mail, chainmail, banded or
    // splinted, plate mail, magic armor
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 2, 4, 7, 8, 10, 1,
    };
    return t[i];
}

inline int potDeludeAgreePercent() {
    // Delusion: 90% probable that tasters
    // will all agree it is the same potion
    return 90;
}

inline int potDiminishMinPercent() {
    // Diminution: diminish to as small as
    // 5% of normal size
    return 5;
}

inline int potDiminishHalfPercent() {
    // half the contents: shrinks to 50%
    return 50;
}

inline int potDiminishTurnsBase() {
    // the effects last for 6 turns
    return 6;
}

inline int potDiminishExtraLo() {
    // plus 2-5 turns (d4 + 1)
    return 2;
}

inline int potDiminishExtraHi() {
    return 5;
}

inline int potDragonRangeInches() {
    // Dragon Control: a charm monster
    // effect upon any dragon within 6"
    return 6;
}

inline int potDragonSaveMod() {
    // the dragon save versus magic is
    // made at -2 on the die
    return -2;
}

inline int potDragonTypeRowCount() {
    // the dragon type sub-table: 12 rows
    return 12;
}

inline int potDragonTypeLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 11) i = 11;
    static const int t[12] = {
        1, 3, 5, 8, 10, 11, 13, 15, 16, 17, 18, 20,
    };
    return t[i];
}

inline int potDragonTypeHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 11) i = 11;
    static const int t[12] = {
        2, 4, 7, 9, 10, 12, 14, 15, 16, 17, 19, 20,
    };
    return t[i];
}

inline int potDragonTypeFaces() {
    // the dragon type roll is on d20
    return 20;
}

inline int potDragonLo() {
    // control lasts for from 5-20
    // (5d4) rounds
    return 5;
}

inline int potDragonHi() {
    return 20;
}

inline int potDragonDice() {
    return 5;
}

inline int potDragonFaces() {
    return 4;
}

inline int potEspLo() {
    // ESP: the effects last for 5-40
    // (5d8) rounds
    return 5;
}

inline int potEspHi() {
    return 40;
}

inline int potEspDice() {
    return 5;
}

inline int potEspFaces() {
    return 8;
}

inline int potXHealLo() {
    // Extra-Healing: restores 6-27
    // (3d8 + 3) hit points when wholly
    // consumed
    return 6;
}

inline int potXHealHi() {
    return 27;
}

inline int potXHealDice() {
    return 3;
}

inline int potXHealFaces() {
    return 8;
}

inline int potXHealBonus() {
    return 3;
}

inline int potXHealThirdLo() {
    // or 1-8 hit points of damage for each
    // one-third potion
    return 1;
}

inline int potXHealThirdHi() {
    return 8;
}

}  // namespace rules

