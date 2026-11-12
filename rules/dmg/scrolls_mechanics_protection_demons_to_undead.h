// ====================================================================
// Adnd1 - rules/dmg/scrolls_mechanics_protection_demons_to_undead.h
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

// R-refactor: namespace rules -> class Scrolls_mechanics_protection_demons_to_undead (instance methods)
class Scrolls_mechanics_protection_demons_to_undead {
public:
    int scpClassMuLo();
    int scpClassMuHi();
    int scpClassIlluLo();
    int scpClassIlluHi();
    int scpClassClericLo();
    int scpClassClericHi();
    int scpClassDruidLo();
    int scpClassDruidHi();
    int scpFadePercentLo();
    int scpFadePercentHi();
    int scpFadeDieFaces();
    int scpWriteLevelAdd();
    int scpWriteLevelFloor();
    int scpSixthLevelSpellWrittenAt();
    int scpSeventhLevelSpellWrittenAt();
    int scpScrollFireballDice();
    int scpScrollFireballFaces();
    int scpFailPercentPerLevel();
    int scpWishExampleDiffLevels();
    int scpWishExampleFailPercent();
    int scpFailRowCount();
    int scpFailDiffStep();
    int scpFailDiffLo(int i);
    int scpFailTotal(int i);
    int scpFailHarmful(int i);
    int scpSevenSpellScrollReducesTo();
    int scpDemonsReadAllRounds();
    int scpDemonsReadTypeVISegments();
    int scpDemonsReadTypeIIISegments();
    int scpDemonsRadiusFeet();
    int scpDemonsRoundLo();
    int scpDemonsRoundHi();
    int scpDemonsDice();
    int scpDemonsFaces();
    int scpDevilsReadAllRounds();
    int scpDevilsReadGreaterSegments();
    int scpDevilsReadLesserSegments();
    int scpElemReadSegments();
    int scpElemVarietyRowCount();
    int scpElemVarLo(int i);
    int scpElemVarHi(int i);
    int scpElemRadiusFeet();
    int scpElemHitDiceSpecific();
    int scpElemHitDiceAll();
    int scpElemRoundLo();
    int scpElemRoundHi();
    int scpElemDice();
    int scpElemFaces();
    int scpLycaReadSegments();
    int scpLycaTypeRowCount();
    int scpLycaTypeLo(int i);
    int scpLycaTypeHi(int i);
    int scpLycaRadiusFeet();
    int scpLycaHitDice();
    int scpLycaPlusTolerance();
    int scpLycaRoundLo();
    int scpLycaRoundHi();
    int scpMagicReadSegments();
    int scpMagicRadiusFeet();
    int scpMagicDrainPercent();
    int scpMagicDrainSaveRoll();
    int scpMagicDrainSaveFaces();
    int scpMagicRoundLo();
    int scpMagicRoundHi();
    int scpMagicDice();
    int scpMagicFaces();
    int scpPetrifyReadSegments();
    int scpPetrifyRadiusFeet();
    int scpPetrifyRoundLo();
    int scpPetrifyRoundHi();
    int scpPetrifyDice();
    int scpPetrifyFaces();
    int scpPossessReadRounds();
    int scpPossessRadiusFeet();
    int scpPossessRoundLo();
    int scpPossessRoundHi();
    int scpPossessRoundsPercent();
    int scpPossessTurnsPercent();
    int scpPossessTurnLo();
    int scpPossessTurnHi();
    int scpUndeadReadSegments();
    int scpUndeadRadiusFeet();
    int scpUndeadTypeCount();
    int scpUndeadHitDice();
    int scpUndeadRoundLo();
    int scpUndeadRoundHi();
    int scpUndeadDice();
    int scpUndeadFaces();
};
