// ====================================================================
// Adnd1 - rules/scrollsprose.h
// R252: the III.B scrolls explanation prose
// pins (DMG pp.137-139) - the general
// scroll mechanics and the EIGHT protection
// scrolls of the EXPLANATIONS AND
// DESCRIPTIONS section (upload lines
// ~10191-10280):
//   - the class table: first roll 01-70
//     magic-user (then 01-10 illusionist),
//     71-00 cleric (then 01-25 druid).
//   - unread scrolls: 5% to 30% likely to
//     fade; a d6 can set the percentage.
//   - scroll spells are written 1 level
//     above the usable level, never below
//     6th; a sixth level spell written at
//     13th, a seventh at 15th; a scroll
//     fireball or lightning bolt is 6 dice
//     (6d6).
//   - spell failure: 5% per level
//     difference (the wish example 18 - 1 =
//     17 x 5% = 85%); the 6-row
//     level-difference table.
//   - reading a scroll of 7 spells makes
//     it a scroll of 6.
//   - Demons: 1 full round all demons, 7
//     segments type VI or lower, 3 segments
//     type III or lower; 10 foot radius;
//     5-20 (5d4) rounds.
//   - Devils: 1 round all, 7 segments
//     greater, 3 segments lesser.
//   - Elementals: 6 segments; the
//     5-variety table; 10 foot radius; 24
//     hit dice specific, 16 all; 5-40
//     (5d8) rounds.
//   - Lycanthropes: 4 segments; the 7-type
//     table; 10 foot radius; 49 hit dice,
//     pluses rounded down unless they
//     exceed +2; 5-30 rounds.
//   - Magic: 8 segments; 5 foot radius;
//     50% drain, save 11 or better on d20;
//     5-30 (5d6) rounds.
//   - Petrification: 5 segments; 10 foot
//     radius; 5-20 (5d4) rounds.
//   - Possession: 1 round; 10 foot
//     radius; 10-60 rounds in 90% of
//     scrolls, 10% have 10-60 turns but
//     stationary.
//   - Undead: 4 segments; 5 foot radius;
//     10 undead types; 35 hit dice/levels;
//     10-80 (10d8) rounds.
// The eight scrolls are the engine III.B
// table rows 61-97 (dm/treasure.cpp
// rollScroll, the R222 scrollpins.h pins) -
// cross-checked against them in the audit.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int scpClassMuLo() {
    // the class table: first roll 01-70
    // magic-user
    return 1;
}

inline int scpClassMuHi() {
    return 70;
}

inline int scpClassIlluLo() {
    // then 01-10 illusionist
    return 1;
}

inline int scpClassIlluHi() {
    return 10;
}

inline int scpClassClericLo() {
    // 71-00 cleric
    return 71;
}

inline int scpClassClericHi() {
    return 100;
}

inline int scpClassDruidLo() {
    // then 01-25 druid
    return 1;
}

inline int scpClassDruidHi() {
    return 25;
}

inline int scpFadePercentLo() {
    // unread scrolls are from 5% to 30%
    // likely to fade
    return 5;
}

inline int scpFadePercentHi() {
    return 30;
}

inline int scpFadeDieFaces() {
    // a d6 can randomly determine it
    return 6;
}

inline int scpWriteLevelAdd() {
    // scroll spells are written typically
    // 1 level higher than that required
    // to actually use the spell
    return 1;
}

inline int scpWriteLevelFloor() {
    // but never below 6th level of
    // experience
    return 6;
}

inline int scpSixthLevelSpellWrittenAt() {
    // a sixth level magic-user spell is
    // written at 13th level of ability
    return 13;
}

inline int scpSeventhLevelSpellWrittenAt() {
    // a seventh at 15th level
    return 15;
}

inline int scpScrollFireballDice() {
    // a scroll fireball or lightning bolt
    // spell is of 6 dice (6d6)
    return 6;
}

inline int scpScrollFireballFaces() {
    return 6;
}

inline int scpFailPercentPerLevel() {
    // spell failure: the chance of failure
    // is 5% per level difference
    return 5;
}

inline int scpWishExampleDiffLevels() {
    // the wish example: 18 - 1 = 17 levels
    // of difference
    return 17;
}

inline int scpWishExampleFailPercent() {
    // 17 x 5% = 85% chance of failure
    return 85;
}

inline int scpFailRowCount() {
    // the level-difference table: 6 rows
    return 6;
}

inline int scpFailDiffStep() {
    // the difference bands step by 3
    return 3;
}

inline int scpFailDiffLo(int i) {
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

inline int scpFailTotal(int i) {
    // the total failure percents; i clamps:
    // 95, 85, 75, 65, 50, 30
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        95, 85, 75, 65, 50, 30,
    };
    return t[i];
}

inline int scpFailHarmful(int i) {
    // the reverse-or-harmful percents; i
    // clamps: 5, 15, 25, 35, 50, 70
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        5, 15, 25, 35, 50, 70,
    };
    return t[i];
}

inline int scpSevenSpellScrollReducesTo() {
    // reading a spell from a scroll of 7
    // spells makes it a scroll of 6
    return 6;
}

inline int scpDemonsReadAllRounds() {
    // Protection from Demons: 1 full round
    // to read for all demons including
    // demon princes
    return 1;
}

inline int scpDemonsReadTypeVISegments() {
    // 7 segments for type VI or lower
    return 7;
}

inline int scpDemonsReadTypeIIISegments() {
    // 3 segments for type III or lower
    return 3;
}

inline int scpDemonsRadiusFeet() {
    // the circle springs outwards in a 10
    // foot radius
    return 10;
}

inline int scpDemonsRoundLo() {
    // the effect lasts for 5-20 (5d4)
    // rounds
    return 5;
}

inline int scpDemonsRoundHi() {
    return 20;
}

inline int scpDemonsDice() {
    return 5;
}

inline int scpDemonsFaces() {
    return 4;
}

inline int scpDevilsReadAllRounds() {
    // Protection from Devils: 1 round to
    // read for all kinds including
    // arch-devils
    return 1;
}

inline int scpDevilsReadGreaterSegments() {
    // 7 segments for greater devils or
    // lower
    return 7;
}

inline int scpDevilsReadLesserSegments() {
    // 3 segments for lesser devils or
    // lower
    return 3;
}

inline int scpElemReadSegments() {
    // Protection from Elementals: reading
    // time 6 segments
    return 6;
}

inline int scpElemVarietyRowCount() {
    // the variety table: 5 rows
    return 5;
}

inline int scpElemVarLo(int i) {
    // the printed band lower edges; i
    // clamps: air, earth, fire, water, all
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        1, 16, 31, 46, 61,
    };
    return t[i];
}

inline int scpElemVarHi(int i) {
    // the printed band upper edges; i
    // clamps: 15, 30, 45, 60, 00 (=100)
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        15, 30, 45, 60, 100,
    };
    return t[i];
}

inline int scpElemRadiusFeet() {
    // the reader and all within 10 feet
    return 10;
}

inline int scpElemHitDiceSpecific() {
    // a maximum of 24 hit dice of elemental
    // creatures for a specific type
    return 24;
}

inline int scpElemHitDiceAll() {
    // 16 hit dice against all sorts
    return 16;
}

inline int scpElemRoundLo() {
    // the spell lasts for 5-40 (5d8)
    // rounds
    return 5;
}

inline int scpElemRoundHi() {
    return 40;
}

inline int scpElemDice() {
    return 5;
}

inline int scpElemFaces() {
    return 8;
}

inline int scpLycaReadSegments() {
    // Protection from Lycanthropes: reading
    // time 4 segments
    return 4;
}

inline int scpLycaTypeRowCount() {
    // the type table: 7 rows
    return 7;
}

inline int scpLycaTypeLo(int i) {
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

inline int scpLycaTypeHi(int i) {
    // the printed band upper edges; i
    // clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        5, 10, 20, 25, 40, 98, 100,
    };
    return t[i];
}

inline int scpLycaRadiusFeet() {
    // the magic circle extends in a 10
    // foot radius
    return 10;
}

inline int scpLycaHitDice() {
    // each scroll protects against 49 hit
    // dice of lycanthropes
    return 49;
}

inline int scpLycaPlusTolerance() {
    // hit point pluses are rounded down
    // unless they exceed +2
    return 2;
}

inline int scpLycaRoundLo() {
    // the magic lasts for 5-30 rounds
    return 5;
}

inline int scpLycaRoundHi() {
    return 30;
}

inline int scpMagicReadSegments() {
    // Protection from Magic: reading time
    // 8 segments
    return 8;
}

inline int scpMagicRadiusFeet() {
    // the globe of anti-magic in a 5 foot
    // radius
    return 5;
}

inline int scpMagicDrainPercent() {
    // a magical item touching the globe
    // is 50% likely to be drained
    return 50;
}

inline int scpMagicDrainSaveRoll() {
    // save equals 11 or better
    return 11;
}

inline int scpMagicDrainSaveFaces() {
    // the save is with d20
    return 20;
}

inline int scpMagicRoundLo() {
    // the protection lasts for 5-30
    // (5d6) rounds
    return 5;
}

inline int scpMagicRoundHi() {
    return 30;
}

inline int scpMagicDice() {
    return 5;
}

inline int scpMagicFaces() {
    return 6;
}

inline int scpPetrifyReadSegments() {
    // Protection from Petrification:
    // reading time 5 segments
    return 5;
}

inline int scpPetrifyRadiusFeet() {
    // a 10 foot radius circle of
    // protection
    return 10;
}

inline int scpPetrifyRoundLo() {
    // the protection lasts for 5-20
    // (5d4) rounds
    return 5;
}

inline int scpPetrifyRoundHi() {
    return 20;
}

inline int scpPetrifyDice() {
    return 5;
}

inline int scpPetrifyFaces() {
    return 4;
}

inline int scpPossessReadRounds() {
    // Protection from Possession: reading
    // time 1 round
    return 1;
}

inline int scpPossessRadiusFeet() {
    // a magic circle of 10 foot radius
    return 10;
}

inline int scpPossessRoundLo() {
    // the protection lasts 10 to 60 rounds
    // in 90% of these scrolls
    return 10;
}

inline int scpPossessRoundHi() {
    return 60;
}

inline int scpPossessRoundsPercent() {
    // 90% of these scrolls
    return 90;
}

inline int scpPossessTurnsPercent() {
    // 10% have power lasting in turns
    return 10;
}

inline int scpPossessTurnLo() {
    // 10 to 60 turns, but the protection
    // is stationary
    return 10;
}

inline int scpPossessTurnHi() {
    return 60;
}

inline int scpUndeadReadSegments() {
    // Protection from Undead: reading time
    // 4 segments
    return 4;
}

inline int scpUndeadRadiusFeet() {
    // a 5 foot radius circle of
    // protection
    return 5;
}

inline int scpUndeadTypeCount() {
    // physical attacks from 10 undead
    // types: ghasts, ghosts, ghouls,
    // shadows, skeletons, spectres,
    // wights, wraiths, vampires, zombies
    return 10;
}

inline int scpUndeadHitDice() {
    // restrains up to 35 hit
    // dice/levels of undead
    return 35;
}

inline int scpUndeadRoundLo() {
    // it remains in effect for 10-80
    // (10d8) rounds
    return 10;
}

inline int scpUndeadRoundHi() {
    return 80;
}

inline int scpUndeadDice() {
    return 10;
}

inline int scpUndeadFaces() {
    return 8;
}

}  // namespace rules

