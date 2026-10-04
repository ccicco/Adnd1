// ====================================================================
// Adnd1 - rules/humrpref.h
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

namespace rules {

enum HumRPrefCode {
    HPREF_P = 0,  // preference
    HPREF_G,      // goodwill
    HPREF_T,      // tolerate
    HPREF_N,      // neutral negative
    HPREF_A,      // antipathy
    HPREF_H       // hatred
};

// ----------------------------------------------------------------------------
// The nine races (p.106)
// ----------------------------------------------------------------------------

inline int humRPrefRaceCount() { return 9; }

inline const char* humRPrefRaceName(int i) {
    static const char* const k[9] = {
        "bugbear",
        "gnoll",
        "goblin",
        "hill giant",
        "hobgoblin",
        "kobold",
        "ogre",
        "orc",
        "troll"
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

// A tiny string equality (no library includes
// in the header).
inline bool humStrEq(const char* a, const char* b) {
    int i = 0;
    while (a[i] != 0 && b[i] != 0) {
        if (a[i] != b[i]) return false;
        ++i;
    }
    return a[i] == b[i];
}

inline int humRPrefRaceIndex(const char* name) {
    for (int i = 0; i < 9; ++i)
        if (humStrEq(humRPrefRaceName(i), name))
            return i;
    return -1;
}

// ----------------------------------------------------------------------------
// The matrix (p.106) - 81 cells, row rates column
// ----------------------------------------------------------------------------

inline HumRPrefCode humRPrefCode(int row, int col) {
    static const HumRPrefCode k[9][9] = {
        // bugbear
        { HPREF_P, HPREF_T, HPREF_G, HPREF_T,
          HPREF_A, HPREF_A, HPREF_T, HPREF_A,
          HPREF_N },
        // gnoll
        { HPREF_T, HPREF_P, HPREF_A, HPREF_T,
          HPREF_N, HPREF_A, HPREF_G, HPREF_T,
          HPREF_N },
        // goblin
        { HPREF_G, HPREF_A, HPREF_P, HPREF_N,
          HPREF_T, HPREF_G, HPREF_H, HPREF_N,
          HPREF_A },
        // hill giant
        { HPREF_G, HPREF_G, HPREF_A, HPREF_P,
          HPREF_A, HPREF_A, HPREF_G, HPREF_N,
          HPREF_T },
        // hobgoblin
        { HPREF_T, HPREF_N, HPREF_N, HPREF_N,
          HPREF_H, HPREF_A, HPREF_A, HPREF_T,
          HPREF_H },
        // kobold
        { HPREF_A, HPREF_H, HPREF_G, HPREF_A,
          HPREF_A, HPREF_P, HPREF_H, HPREF_A,
          HPREF_T },
        // ogre
        { HPREF_T, HPREF_T, HPREF_A, HPREF_G,
          HPREF_A, HPREF_A, HPREF_P, HPREF_T,
          HPREF_T },
        // orc
        { HPREF_A, HPREF_N, HPREF_T, HPREF_A,
          HPREF_N, HPREF_A, HPREF_G, HPREF_H,
          HPREF_H },
        // troll
        { HPREF_A, HPREF_N, HPREF_A, HPREF_T,
          HPREF_H, HPREF_T, HPREF_N, HPREF_A,
          HPREF_N }
    };
    if (row < 0) row = 0;
    if (row > 8) row = 8;
    if (col < 0) col = 0;
    if (col > 8) col = 8;
    return k[row][col];
}

// The star marks: 1 = the single star (the race
// will bully and harass such humanoids);
// 2 = the double star (the others of this race
// are of a rival tribe or family group).
inline int humRPrefStars(int row, int col) {
    static const int k[9][9] = {
        { 0, 1, 0, 0, 1, 1, 0, 1, 0 },
        { 0, 0, 1, 0, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 0, 1, 0, 2, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 1, 0, 1, 1, 0, 1, 0 },
        { 0, 0, 1, 0, 0, 1, 0, 2, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 2 }
    };
    if (row < 0) row = 0;
    if (row > 8) row = 8;
    if (col < 0) col = 0;
    if (col > 8) col = 8;
    return k[row][col];
}

inline bool humRPrefBullyMark(int row, int col) {
    return humRPrefStars(row, col) == 1;
}

inline bool humRPrefRivalTribe(int row, int col) {
    return humRPrefStars(row, col) == 2;
}

// The letter key names.
inline const char* humRPrefCodeName(HumRPrefCode c) {
    static const char* const k[6] = {
        "preference",
        "goodwill",
        "tolerate",
        "neutral negative",
        "antipathy",
        "hatred"
    };
    if (c < HPREF_P) c = HPREF_P;
    if (c > HPREF_H) c = HPREF_H;
    return k[c];
}

inline char humRPrefCodeLetter(HumRPrefCode c) {
    static const char k[6] = {
        'P', 'G', 'T',
        'N', 'A', 'H'
    };
    if (c < HPREF_P) c = HPREF_P;
    if (c > HPREF_H) c = HPREF_H;
    return k[c];
}

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
inline bool humCodeAllowsCoOperation(HumRPrefCode c) {
    return c == HPREF_P || c == HPREF_G;
}
inline bool humCodeNoHostilityLikely(HumRPrefCode c) {
    return c == HPREF_T;
}
inline bool humCodeNoAidIfIllBefalls(HumRPrefCode c) {
    return c == HPREF_N;
}

// A: antipathy and active dislike which will
// break into open hostility if the
// opportunity presents itself; if leaders or
// overseers are weak, these creatures will
// desert.
inline bool humAntipathyDesertIfLeadersWeak() {
    return true;
}

// H: hatred, possibly kept in check by fear,
// which will certainly break into open
// hostilities at the first opportunity, or else
// the hating humanoids will desert at the first
// chance if near a strong body of such hated
// creatures.
inline bool humHatredBreaksOutAtFirstOpportunity() {
    return true;
}
inline bool humHatredDesertsNearStrongHatedBody() {
    return true;
}

// Use the table whenever humanoid troops are
// fighting or even serving side by side (within
// 12 inches of each other without any
// intervening troops or screen so that the other
// humanoids are visible). Have the troops
// behave according to the letter key.
inline int humSideBySideVisibilityRangeInches() {
    return 12;
}
inline bool humInterveningTroopsOrScreenBlocks() {
    return true;
}

// ----------------------------------------------------------------------------
// The compatibility prose (p.106)
// ----------------------------------------------------------------------------

// The general compatibility of demi-human
// troop types is the PLAYERS HANDBOOK RACIAL
// PREFERENCES TABLE.
inline bool humDemihumanCompatibilityFromPHBTable() {
    return true;
}

// Lizard men are hated by all demi-humans and
// humanoids save kobolds, and even the latter
// are suspicious of them, just as human troops
// are.
inline bool humLizardMenHatedByAllHumanoidsSaveKobolds() {
    return true;
}
inline bool humKoboldsSuspiciousOfLizardMen() {
    return true;
}
inline bool humHumanTroopsSuspiciousOfLizardMen() {
    return true;
}

} // namespace rules
