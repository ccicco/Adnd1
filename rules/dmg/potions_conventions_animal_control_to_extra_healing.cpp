// R-refactor: split from potions_conventions_animal_control_to_extra_healing.h - definitions
#include "rules/dmg/potions_conventions_animal_control_to_extra_healing.h"

int Potions_conventions_animal_control_to_extra_healing::potDurationTurnsBase() {
    // the conventions: effects last 4
    // complete turns
    return 4;
}

int Potions_conventions_animal_control_to_extra_healing::potDurationExtraLo() {
    // plus 1-4 additional turns (d4)
    return 1;
}

int Potions_conventions_animal_control_to_extra_healing::potDurationExtraHi() {
    return 4;
}

int Potions_conventions_animal_control_to_extra_healing::potOnsetLo() {
    // potions take effect 2-5 segments
    // after they are imbibed
    return 2;
}

int Potions_conventions_animal_control_to_extra_healing::potOnsetHi() {
    return 5;
}

int Potions_conventions_animal_control_to_extra_healing::potAnimalSmallLo() {
    // Animal Control: 5-20 animals of
    // the size of giant rats
    return 5;
}

int Potions_conventions_animal_control_to_extra_healing::potAnimalSmallHi() {
    return 20;
}

int Potions_conventions_animal_control_to_extra_healing::potAnimalManLo() {
    // 3-12 animals of about man-size
    return 3;
}

int Potions_conventions_animal_control_to_extra_healing::potAnimalManHi() {
    return 12;
}

int Potions_conventions_animal_control_to_extra_healing::potAnimalLargeLo() {
    // 1-4 animals of about half a ton
    // or more in weight
    return 1;
}

int Potions_conventions_animal_control_to_extra_healing::potAnimalLargeHi() {
    return 4;
}

int Potions_conventions_animal_control_to_extra_healing::potAnimalSaveInt() {
    // animals with intelligence of 5
    // or better get a save versus magic
    return 5;
}

int Potions_conventions_animal_control_to_extra_healing::potAnimalTypeRowCount() {
    // the animal type sub-table: 7 rows
    return 7;
}

int Potions_conventions_animal_control_to_extra_healing::potAnimalTypeLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 5, 9, 13, 16, 18, 20,
    };
    return t[i];
}

int Potions_conventions_animal_control_to_extra_healing::potAnimalTypeHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        4, 8, 12, 15, 17, 19, 20,
    };
    return t[i];
}

int Potions_conventions_animal_control_to_extra_healing::potAnimalTypeFaces() {
    // the animal type roll is on d20
    return 20;
}

int Potions_conventions_animal_control_to_extra_healing::potClairaudRangeInches() {
    // Clairaudience: clairaudit unknown
    // areas within 3"
    return 3;
}

int Potions_conventions_animal_control_to_extra_healing::potClairaudTurns() {
    // the effects last for 2 turns only
    return 2;
}

int Potions_conventions_animal_control_to_extra_healing::potClairvoyRangeInches() {
    // Clairvoyance: unknown areas up to
    // 3" distant can be seen
    return 3;
}

int Potions_conventions_animal_control_to_extra_healing::potClairvoyTurns() {
    // the effects last for 1 turn only
    return 1;
}

int Potions_conventions_animal_control_to_extra_healing::potClimbBasePercent() {
    // Climbing: a base 1% chance of
    // slipping and falling
    return 1;
}

int Potions_conventions_animal_control_to_extra_healing::potClimbFallRoll() {
    // check at the halfway point, d%;
    // 01 equals a fall
    return 1;
}

int Potions_conventions_animal_control_to_extra_healing::potClimbTurns() {
    // effective for 1 turn
    return 1;
}

int Potions_conventions_animal_control_to_extra_healing::potClimbExtraRoundsLo() {
    // plus 5 to 20 rounds
    return 5;
}

int Potions_conventions_animal_control_to_extra_healing::potClimbExtraRoundsHi() {
    return 20;
}

int Potions_conventions_animal_control_to_extra_healing::potClimbLoadIncrementGp() {
    // for every 1,000 g.p. weight
    // equivalent carried
    return 1000;
}

int Potions_conventions_animal_control_to_extra_healing::potClimbLoadPercent() {
    // an additional 1% chance of slipping
    return 1;
}

int Potions_conventions_animal_control_to_extra_healing::potClimbArmorRowCount() {
    // the climbing armor table: 7 rows
    return 7;
}

int Potions_conventions_animal_control_to_extra_healing::potClimbArmorPercent(int i) {
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

int Potions_conventions_animal_control_to_extra_healing::potDeludeAgreePercent() {
    // Delusion: 90% probable that tasters
    // will all agree it is the same potion
    return 90;
}

int Potions_conventions_animal_control_to_extra_healing::potDiminishMinPercent() {
    // Diminution: diminish to as small as
    // 5% of normal size
    return 5;
}

int Potions_conventions_animal_control_to_extra_healing::potDiminishHalfPercent() {
    // half the contents: shrinks to 50%
    return 50;
}

int Potions_conventions_animal_control_to_extra_healing::potDiminishTurnsBase() {
    // the effects last for 6 turns
    return 6;
}

int Potions_conventions_animal_control_to_extra_healing::potDiminishExtraLo() {
    // plus 2-5 turns (d4 + 1)
    return 2;
}

int Potions_conventions_animal_control_to_extra_healing::potDiminishExtraHi() {
    return 5;
}

int Potions_conventions_animal_control_to_extra_healing::potDragonRangeInches() {
    // Dragon Control: a charm monster
    // effect upon any dragon within 6"
    return 6;
}

int Potions_conventions_animal_control_to_extra_healing::potDragonSaveMod() {
    // the dragon save versus magic is
    // made at -2 on the die
    return -2;
}

int Potions_conventions_animal_control_to_extra_healing::potDragonTypeRowCount() {
    // the dragon type sub-table: 12 rows
    return 12;
}

int Potions_conventions_animal_control_to_extra_healing::potDragonTypeLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 11) i = 11;
    static const int t[12] = {
        1, 3, 5, 8, 10, 11, 13, 15, 16, 17, 18, 20,
    };
    return t[i];
}

int Potions_conventions_animal_control_to_extra_healing::potDragonTypeHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 11) i = 11;
    static const int t[12] = {
        2, 4, 7, 9, 10, 12, 14, 15, 16, 17, 19, 20,
    };
    return t[i];
}

int Potions_conventions_animal_control_to_extra_healing::potDragonTypeFaces() {
    // the dragon type roll is on d20
    return 20;
}

int Potions_conventions_animal_control_to_extra_healing::potDragonLo() {
    // control lasts for from 5-20
    // (5d4) rounds
    return 5;
}

int Potions_conventions_animal_control_to_extra_healing::potDragonHi() {
    return 20;
}

int Potions_conventions_animal_control_to_extra_healing::potDragonDice() {
    return 5;
}

int Potions_conventions_animal_control_to_extra_healing::potDragonFaces() {
    return 4;
}

int Potions_conventions_animal_control_to_extra_healing::potEspLo() {
    // ESP: the effects last for 5-40
    // (5d8) rounds
    return 5;
}

int Potions_conventions_animal_control_to_extra_healing::potEspHi() {
    return 40;
}

int Potions_conventions_animal_control_to_extra_healing::potEspDice() {
    return 5;
}

int Potions_conventions_animal_control_to_extra_healing::potEspFaces() {
    return 8;
}

int Potions_conventions_animal_control_to_extra_healing::potXHealLo() {
    // Extra-Healing: restores 6-27
    // (3d8 + 3) hit points when wholly
    // consumed
    return 6;
}

int Potions_conventions_animal_control_to_extra_healing::potXHealHi() {
    return 27;
}

int Potions_conventions_animal_control_to_extra_healing::potXHealDice() {
    return 3;
}

int Potions_conventions_animal_control_to_extra_healing::potXHealFaces() {
    return 8;
}

int Potions_conventions_animal_control_to_extra_healing::potXHealBonus() {
    return 3;
}

int Potions_conventions_animal_control_to_extra_healing::potXHealThirdLo() {
    // or 1-8 hit points of damage for each
    // one-third potion
    return 1;
}

int Potions_conventions_animal_control_to_extra_healing::potXHealThirdHi() {
    return 8;
}
