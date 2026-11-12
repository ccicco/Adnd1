// R-refactor: split from energydrain.h - definitions
#include "rules/dmg/energydrain.h"

int Energydrain::potionOpenConsumeSegments() {
    // one segment to open and consume the
    // typical potion
    return 1;
}

int Energydrain::potionDelayMin() {
    // the d4 + 1 delay: 2 segments
    return 2;
}

int Energydrain::potionDelayMax() {
    // the d4 + 1 delay: 5 segments
    return 5;
}

int Energydrain::oilDecantSegments() {
    // normal opening time and decanting
    return 1;
}

int Energydrain::oilSpreadMin() { return 2; }

int Energydrain::oilSpreadMax() { return 5; }

int Energydrain::rodStaffWandNeedsCommandWord() {
    // usually necessary for a rod, staff or
    // wand
    return 1;
}

int Energydrain::commandWordInfoSpellCount() {
    // contact other plane, legend lore,
    // speak with dead
    return 3;
}

int Energydrain::scryingDetectable() {
    // scrying devices are detectable by the
    // observed
    return 1;
}

int Energydrain::scryingDetectionUsesInvisibilityTable() {
    // a spell-user target: consult the
    // DETECTION OF INVISIBILITY table,
    // checking each round
    return 1;
}

int Energydrain::scryingDarknessStopsForSpellDuration() {
    // darkness on the viewing spot stops the
    // scrying for the darkness duration
    return 1;
}

int Energydrain::scryingDispelStopsHours() {
    // dispel magic stops the scrying for a
    // full day
    return 24;
}

int Energydrain::drainLosesLevelHitPointsAndAbilities() {
    // the hit points gained with the level
    // (including the constitution bonus)
    // and all abilities of that level
    return 1;
}

int Energydrain::drainXpToMidpointOfNextLower() {
    // XP sufficient to bring the total to
    // the mid-point of the next lower level
    return 1;
}

int Energydrain::drainBelowFirstIsZeroLevel() {
    // below 1st level of experience: a 0
    // level person
    return 1;
}

int Energydrain::zeroLevelNeverGainsAgain() {
    // never capable of gaining experience
    // again
    return 1;
}

int Energydrain::isDeadIfZeroLevelDrained(int level) {
    // a 0 level individual drained an energy
    // level is dead (possibly to become an
    // undead monster)
    if (level <= 0) return 1;
    return 0;
}

int Energydrain::multiclassLosesHighestLevel() {
    // always the highest level gained
    return 1;
}

int Energydrain::equalLevelsLoseGreatestXpClass() {
    // if all levels are equal, the class
    // requiring the greatest amount of
    // experience points loses the level
    return 1;
}

int Energydrain::twoLevelDrainSplitsAcrossClasses() {
    // a two-level drain takes one level
    // from each class
    return 1;
}

int Energydrain::drainedAllMayBecomeUndead() {
    // an undead monster of the same sort
    // which killed the character
    return 1;
}

int Energydrain::lesserUndeadHalfHitDice() {
    // half the hit dice of a normal undead
    // of the same type
    return 1;
}

int Energydrain::lesserUndeadControlledBySlayer() {
    // controlled by their slayer/drainer
    return 1;
}

int Energydrain::lesserVampireLevel(int level) {
    // half the former professional level; the
    // print example: an 8th level thief
    // returns as a 4th level thief vampire.
    // Odd levels round down (the print gives
    // only the exact-half example).
    if (level < 0) level = 0;
    return level / 2;
}

int Energydrain::fullHdRegainUponSlayerDestruction() {
    // the lesser undead gain levels from
    // those they slay/drain until full hit
    // dice status
    return 1;
}
