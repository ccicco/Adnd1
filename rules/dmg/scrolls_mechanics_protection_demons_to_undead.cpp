// R-refactor: split from scrolls_mechanics_protection_demons_to_undead.h - definitions
#include "rules/dmg/scrolls_mechanics_protection_demons_to_undead.h"

int Scrolls_mechanics_protection_demons_to_undead::scpClassMuLo() {
    // the class table: first roll 01-70
    // magic-user
    return 1;
}

int Scrolls_mechanics_protection_demons_to_undead::scpClassMuHi() {
    return 70;
}

int Scrolls_mechanics_protection_demons_to_undead::scpClassIlluLo() {
    // then 01-10 illusionist
    return 1;
}

int Scrolls_mechanics_protection_demons_to_undead::scpClassIlluHi() {
    return 10;
}

int Scrolls_mechanics_protection_demons_to_undead::scpClassClericLo() {
    // 71-00 cleric
    return 71;
}

int Scrolls_mechanics_protection_demons_to_undead::scpClassClericHi() {
    return 100;
}

int Scrolls_mechanics_protection_demons_to_undead::scpClassDruidLo() {
    // then 01-25 druid
    return 1;
}

int Scrolls_mechanics_protection_demons_to_undead::scpClassDruidHi() {
    return 25;
}

int Scrolls_mechanics_protection_demons_to_undead::scpFadePercentLo() {
    // unread scrolls are from 5% to 30%
    // likely to fade
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpFadePercentHi() {
    return 30;
}

int Scrolls_mechanics_protection_demons_to_undead::scpFadeDieFaces() {
    // a d6 can randomly determine it
    return 6;
}

int Scrolls_mechanics_protection_demons_to_undead::scpWriteLevelAdd() {
    // scroll spells are written typically
    // 1 level higher than that required
    // to actually use the spell
    return 1;
}

int Scrolls_mechanics_protection_demons_to_undead::scpWriteLevelFloor() {
    // but never below 6th level of
    // experience
    return 6;
}

int Scrolls_mechanics_protection_demons_to_undead::scpSixthLevelSpellWrittenAt() {
    // a sixth level magic-user spell is
    // written at 13th level of ability
    return 13;
}

int Scrolls_mechanics_protection_demons_to_undead::scpSeventhLevelSpellWrittenAt() {
    // a seventh at 15th level
    return 15;
}

int Scrolls_mechanics_protection_demons_to_undead::scpScrollFireballDice() {
    // a scroll fireball or lightning bolt
    // spell is of 6 dice (6d6)
    return 6;
}

int Scrolls_mechanics_protection_demons_to_undead::scpScrollFireballFaces() {
    return 6;
}

int Scrolls_mechanics_protection_demons_to_undead::scpFailPercentPerLevel() {
    // spell failure: the chance of failure
    // is 5% per level difference
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpWishExampleDiffLevels() {
    // the wish example: 18 - 1 = 17 levels
    // of difference
    return 17;
}

int Scrolls_mechanics_protection_demons_to_undead::scpWishExampleFailPercent() {
    // 17 x 5% = 85% chance of failure
    return 85;
}

int Scrolls_mechanics_protection_demons_to_undead::scpFailRowCount() {
    // the level-difference table: 6 rows
    return 6;
}

int Scrolls_mechanics_protection_demons_to_undead::scpFailDiffStep() {
    // the difference bands step by 3
    return 3;
}

int Scrolls_mechanics_protection_demons_to_undead::scpFailDiffLo(int i) {
    // the difference band lower edges; i
    // clamps: 1-3, 4-6, 7-9, 10-12,
    // 13-15, 16 and up
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 4, 7, 10, 13, 16,
    };
    return t[i];
}

int Scrolls_mechanics_protection_demons_to_undead::scpFailTotal(int i) {
    // the total failure percents; i clamps:
    // 95, 85, 75, 65, 50, 30
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        95, 85, 75, 65, 50, 30,
    };
    return t[i];
}

int Scrolls_mechanics_protection_demons_to_undead::scpFailHarmful(int i) {
    // the reverse-or-harmful percents; i
    // clamps: 5, 15, 25, 35, 50, 70
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        5, 15, 25, 35, 50, 70,
    };
    return t[i];
}

int Scrolls_mechanics_protection_demons_to_undead::scpSevenSpellScrollReducesTo() {
    // reading a spell from a scroll of 7
    // spells makes it a scroll of 6
    return 6;
}

int Scrolls_mechanics_protection_demons_to_undead::scpDemonsReadAllRounds() {
    // Protection from Demons: 1 full round
    // to read for all demons including
    // demon princes
    return 1;
}

int Scrolls_mechanics_protection_demons_to_undead::scpDemonsReadTypeVISegments() {
    // 7 segments for type VI or lower
    return 7;
}

int Scrolls_mechanics_protection_demons_to_undead::scpDemonsReadTypeIIISegments() {
    // 3 segments for type III or lower
    return 3;
}

int Scrolls_mechanics_protection_demons_to_undead::scpDemonsRadiusFeet() {
    // the circle springs outwards in a 10
    // foot radius
    return 10;
}

int Scrolls_mechanics_protection_demons_to_undead::scpDemonsRoundLo() {
    // the effect lasts for 5-20 (5d4)
    // rounds
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpDemonsRoundHi() {
    return 20;
}

int Scrolls_mechanics_protection_demons_to_undead::scpDemonsDice() {
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpDemonsFaces() {
    return 4;
}

int Scrolls_mechanics_protection_demons_to_undead::scpDevilsReadAllRounds() {
    // Protection from Devils: 1 round to
    // read for all kinds including
    // arch-devils
    return 1;
}

int Scrolls_mechanics_protection_demons_to_undead::scpDevilsReadGreaterSegments() {
    // 7 segments for greater devils or
    // lower
    return 7;
}

int Scrolls_mechanics_protection_demons_to_undead::scpDevilsReadLesserSegments() {
    // 3 segments for lesser devils or
    // lower
    return 3;
}

int Scrolls_mechanics_protection_demons_to_undead::scpElemReadSegments() {
    // Protection from Elementals: reading
    // time 6 segments
    return 6;
}

int Scrolls_mechanics_protection_demons_to_undead::scpElemVarietyRowCount() {
    // the variety table: 5 rows
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpElemVarLo(int i) {
    // the printed band lower edges; i
    // clamps: air, earth, fire, water, all
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        1, 16, 31, 46, 61,
    };
    return t[i];
}

int Scrolls_mechanics_protection_demons_to_undead::scpElemVarHi(int i) {
    // the printed band upper edges; i
    // clamps: 15, 30, 45, 60, 00 (=100)
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        15, 30, 45, 60, 100,
    };
    return t[i];
}

int Scrolls_mechanics_protection_demons_to_undead::scpElemRadiusFeet() {
    // the reader and all within 10 feet
    return 10;
}

int Scrolls_mechanics_protection_demons_to_undead::scpElemHitDiceSpecific() {
    // a maximum of 24 hit dice of elemental
    // creatures for a specific type
    return 24;
}

int Scrolls_mechanics_protection_demons_to_undead::scpElemHitDiceAll() {
    // 16 hit dice against all sorts
    return 16;
}

int Scrolls_mechanics_protection_demons_to_undead::scpElemRoundLo() {
    // the spell lasts for 5-40 (5d8)
    // rounds
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpElemRoundHi() {
    return 40;
}

int Scrolls_mechanics_protection_demons_to_undead::scpElemDice() {
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpElemFaces() {
    return 8;
}

int Scrolls_mechanics_protection_demons_to_undead::scpLycaReadSegments() {
    // Protection from Lycanthropes: reading
    // time 4 segments
    return 4;
}

int Scrolls_mechanics_protection_demons_to_undead::scpLycaTypeRowCount() {
    // the type table: 7 rows
    return 7;
}

int Scrolls_mechanics_protection_demons_to_undead::scpLycaTypeLo(int i) {
    // the printed band lower edges; i
    // clamps: werebears, wereboars,
    // wererats, weretigers, werewolves,
    // all lycanthropes, shape-changers
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 6, 11, 21, 26, 41, 99,
    };
    return t[i];
}

int Scrolls_mechanics_protection_demons_to_undead::scpLycaTypeHi(int i) {
    // the printed band upper edges; i
    // clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        5, 10, 20, 25, 40, 98, 100,
    };
    return t[i];
}

int Scrolls_mechanics_protection_demons_to_undead::scpLycaRadiusFeet() {
    // the magic circle extends in a 10
    // foot radius
    return 10;
}

int Scrolls_mechanics_protection_demons_to_undead::scpLycaHitDice() {
    // each scroll protects against 49 hit
    // dice of lycanthropes
    return 49;
}

int Scrolls_mechanics_protection_demons_to_undead::scpLycaPlusTolerance() {
    // hit point pluses are rounded down
    // unless they exceed +2
    return 2;
}

int Scrolls_mechanics_protection_demons_to_undead::scpLycaRoundLo() {
    // the magic lasts for 5-30 rounds
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpLycaRoundHi() {
    return 30;
}

int Scrolls_mechanics_protection_demons_to_undead::scpMagicReadSegments() {
    // Protection from Magic: reading time
    // 8 segments
    return 8;
}

int Scrolls_mechanics_protection_demons_to_undead::scpMagicRadiusFeet() {
    // the globe of anti-magic in a 5 foot
    // radius
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpMagicDrainPercent() {
    // a magical item touching the globe
    // is 50% likely to be drained
    return 50;
}

int Scrolls_mechanics_protection_demons_to_undead::scpMagicDrainSaveRoll() {
    // save equals 11 or better
    return 11;
}

int Scrolls_mechanics_protection_demons_to_undead::scpMagicDrainSaveFaces() {
    // the save is with d20
    return 20;
}

int Scrolls_mechanics_protection_demons_to_undead::scpMagicRoundLo() {
    // the protection lasts for 5-30
    // (5d6) rounds
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpMagicRoundHi() {
    return 30;
}

int Scrolls_mechanics_protection_demons_to_undead::scpMagicDice() {
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpMagicFaces() {
    return 6;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPetrifyReadSegments() {
    // Protection from Petrification:
    // reading time 5 segments
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPetrifyRadiusFeet() {
    // a 10 foot radius circle of
    // protection
    return 10;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPetrifyRoundLo() {
    // the protection lasts for 5-20
    // (5d4) rounds
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPetrifyRoundHi() {
    return 20;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPetrifyDice() {
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPetrifyFaces() {
    return 4;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPossessReadRounds() {
    // Protection from Possession: reading
    // time 1 round
    return 1;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPossessRadiusFeet() {
    // a magic circle of 10 foot radius
    return 10;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPossessRoundLo() {
    // the protection lasts 10 to 60 rounds
    // in 90% of these scrolls
    return 10;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPossessRoundHi() {
    return 60;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPossessRoundsPercent() {
    // 90% of these scrolls
    return 90;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPossessTurnsPercent() {
    // 10% have power lasting in turns
    return 10;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPossessTurnLo() {
    // 10 to 60 turns, but the protection
    // is stationary
    return 10;
}

int Scrolls_mechanics_protection_demons_to_undead::scpPossessTurnHi() {
    return 60;
}

int Scrolls_mechanics_protection_demons_to_undead::scpUndeadReadSegments() {
    // Protection from Undead: reading time
    // 4 segments
    return 4;
}

int Scrolls_mechanics_protection_demons_to_undead::scpUndeadRadiusFeet() {
    // a 5 foot radius circle of
    // protection
    return 5;
}

int Scrolls_mechanics_protection_demons_to_undead::scpUndeadTypeCount() {
    // physical attacks from 10 undead
    // types: ghasts, ghosts, ghouls,
    // shadows, skeletons, spectres,
    // wights, wraiths, vampires, zombies
    return 10;
}

int Scrolls_mechanics_protection_demons_to_undead::scpUndeadHitDice() {
    // restrains up to 35 hit
    // dice/levels of undead
    return 35;
}

int Scrolls_mechanics_protection_demons_to_undead::scpUndeadRoundLo() {
    // it remains in effect for 10-80
    // (10d8) rounds
    return 10;
}

int Scrolls_mechanics_protection_demons_to_undead::scpUndeadRoundHi() {
    return 80;
}

int Scrolls_mechanics_protection_demons_to_undead::scpUndeadDice() {
    return 10;
}

int Scrolls_mechanics_protection_demons_to_undead::scpUndeadFaces() {
    return 8;
}
