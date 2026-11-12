// ====================================================================
// Adnd1 - rules/dmg/humanoid_preferences.h
// R169: the humanoid racial preferences table
// (DMG p.106) - the nine-race basic acceptability
// matrix, the star marks and the letter key.
//
// Pure data, header-only (the grenade.h pattern:
// the caller reads the letter and plays the
// troops; the demi-human side stays on the PHB
// RACIAL PREFERENCES TABLE, outside this box).
//
// The p.106 print:
//   - Nine races, each rated against the same
//     nine: bugbear, gnoll, goblin, hill giant,
//     hobgoblin, kobold, ogre, orc, troll.
//   - Six letters. P: preference and
//     compatibility, even possible friendliness
//     with appropriate co-operation. G: goodwill,
//     no hostility and some co-operation
//     possible. T: tolerate each other, open
//     hostilities not likely. N: neutral
//     negative feelings, no move to aid them if
//     anything ill befalls. A: antipathy and
//     active dislike, breaking into open
//     hostility if the opportunity presents
//     itself; if leaders or overseers are weak,
//     these creatures will desert. H: hatred,
//     possibly kept in check by fear, which
//     will certainly break into open hostilities
//     at the first opportunity, or else the
//     hating humanoids will desert at the first
//     chance if near a strong body of such
//     hated creatures.
//   - Single star: the race will bully and
//     harass such humanoids (18 cells).
//   - Double star: assumes the others of this
//     race are of a rival tribe or family group
//     - the hobgoblin, orc and troll self cells;
//     the other six self cells print P.
//   - Usage: consult whenever humanoid troops
//     are fighting or serving side by side
//     (within 12 inches of each other without
//     any intervening troops or screen so that
//     the other humanoids are visible); have
//     the troops behave according to the letter
//     key.
//   - Compatibility of demi-human troops is the
//     PLAYERS HANDBOOK RACIAL PREFERENCES TABLE.
//     Lizard men are hated by all demi-humans
//     and humanoids save kobolds, and even
//     kobolds are suspicious of them, just as
//     human troops are.
// ====================================================================

#pragma once


enum HumRPrefCode {
    HPREF_P = 0,  // preference
    HPREF_G,      // goodwill
    HPREF_T,      // tolerate
    HPREF_N,      // neutral negative
    HPREF_A,      // antipathy
    HPREF_H       // hatred
};

// R-refactor: namespace rules -> class Humanoid_preferences (instance methods)
class Humanoid_preferences {
public:


// ----------------------------------------------------------------------------
// The nine races (p.106)
// ----------------------------------------------------------------------------
    int humRPrefRaceCount();
    const char* humRPrefRaceName(int i);


// A tiny string equality (no library includes
// in the header).
    bool humStrEq(const char* a, const char* b);
    int humRPrefRaceIndex(const char* name);


// ----------------------------------------------------------------------------
// The matrix (p.106) - 81 cells, row rates column
// ----------------------------------------------------------------------------
    HumRPrefCode humRPrefCode(int row, int col);


// The star marks: 1 = the single star (the race
// will bully and harass such humanoids);
// 2 = the double star (the others of this race
// are of a rival tribe or family group).
    int humRPrefStars(int row, int col);
    bool humRPrefBullyMark(int row, int col);
    bool humRPrefRivalTribe(int row, int col);


// The letter key names.
    const char* humRPrefCodeName(HumRPrefCode c);
    char humRPrefCodeLetter(HumRPrefCode c);


// ----------------------------------------------------------------------------
// The letter definitions and the usage prose (p.106)
// ----------------------------------------------------------------------------

// P: preference and compatibility, even
// possible friendliness with appropriate
// co-operation. G: goodwill, no hostility and
// some co-operation possible. T: the races can
// tolerate each other, open hostilities not
// likely to be evident. N: neutral negative
// feelings; no move to aid them if anything
// ill befalls.
    bool humCodeAllowsCoOperation(HumRPrefCode c);
    bool humCodeNoHostilityLikely(HumRPrefCode c);
    bool humCodeNoAidIfIllBefalls(HumRPrefCode c);


// A: antipathy and active dislike which will
// break into open hostility if the
// opportunity presents itself; if leaders or
// overseers are weak, these creatures will
// desert.
    bool humAntipathyDesertIfLeadersWeak();


// H: hatred, possibly kept in check by fear,
// which will certainly break into open
// hostilities at the first opportunity, or else
// the hating humanoids will desert at the first
// chance if near a strong body of such hated
// creatures.
    bool humHatredBreaksOutAtFirstOpportunity();
    bool humHatredDesertsNearStrongHatedBody();


// Use the table whenever humanoid troops are
// fighting or even serving side by side (within
// 12 inches of each other without any
// intervening troops or screen so that the other
// humanoids are visible). Have the troops
// behave according to the letter key.
    int humSideBySideVisibilityRangeInches();
    bool humInterveningTroopsOrScreenBlocks();


// ----------------------------------------------------------------------------
// The compatibility prose (p.106)
// ----------------------------------------------------------------------------

// The general compatibility of demi-human
// troop types is the PLAYERS HANDBOOK RACIAL
// PREFERENCES TABLE.
    bool humDemihumanCompatibilityFromPHBTable();


// Lizard men are hated by all demi-humans and
// humanoids save kobolds, and even the latter
// are suspicious of them, just as human troops
// are.
    bool humLizardMenHatedByAllHumanoidsSaveKobolds();
    bool humKoboldsSuspiciousOfLizardMen();
    bool humHumanTroopsSuspiciousOfLizardMen();
};
