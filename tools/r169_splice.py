# tools/r169_splice.py - R169, 5 patches: the
# humanoid racial preferences table (DMG p.106) -
# the 9 by 9 basic acceptability matrix, the star
# marks and the letter key. A new header-only
# layer, rules/humrpref.h (the grenade.h pattern:
# the caller reads the letter and plays the
# troops; the demi-human side stays on the PHB
# RACIAL PREFERENCES TABLE, outside this box).
#
# (1) rules/humrpref.h: the p.106 print - nine
#     races (bugbear, gnoll, goblin, hill giant,
#     hobgoblin, kobold, ogre, orc, troll) each
#     rated against the same nine; six letters -
#     P preference (compatibility, possible
#     friendliness with co-operation), G goodwill
#     (no hostility, some co-operation possible),
#     T tolerate (open hostilities not likely), N
#     neutral negative (no move to aid if ill
#     befalls), A antipathy (active dislike, open
#     hostility at the opportunity, desert if
#     leaders or overseers are weak), H hatred
#     (kept in check by fear, breaks into open
#     hostilities at the first opportunity, or
#     desert at the first chance near a strong
#     body of the hated creatures). The single
#     star: the race will bully and harass such
#     humanoids - 18 cells. The double star:
#     assumes the others of this race are of a
#     rival tribe or family group - the
#     hobgoblin, orc and troll self cells (the
#     other six self cells print P). The full
#     matrix, cell by cell: bugbear row
#     P T* G T A* A* T A* N; gnoll
#     T P A* T N A* G T* N; goblin G A P N T G H
#     N A; hill giant G G A P A A G N* T;
#     hobgoblin T N N* N H** A* A T* H; kobold
#     A H G A A P H A T; ogre T T* A* G A* A* P
#     T* T; orc A N T* A N A* G H** H; troll A N
#     A T H T N A N**. The usage prose: consult
#     whenever humanoid troops fight or serve
#     side by side within 12 inches of each other
#     with no intervening troops or screen so
#     the other humanoids are visible. The
#     compatibility prose: demi-human troop
#     compatibility is the PLAYERS HANDBOOK
#     RACIAL PREFERENCES TABLE; lizard men are
#     hated by all demi-humans and humanoids
#     save kobolds, and even kobolds are
#     suspicious of them, just as human troops
#     are. (2) the regtest include. (3) the R169
#     audit: every printed cell pinned - CENSUS
#     87. (4)-(5) the gap report.
#
# JUDGMENT: the re-upload OCR wraps each matrix
# row across line breaks; the reconstruction
# (9 tokens per row) was cross-validated against
# the known print readings - gnolls with goodwill
# toward ogres and neutral to hobgoblins and
# trolls, bugbears bullying hobgoblins,
# hobgoblins loyal to their own group but enemy
# to rival tribes (the H** self cell), kobolds
# hating gnolls and ogres most - every probe
# matched.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R169: humanoid racial preferences pinned -
# the p.106 nine-race matrix and letter key (census 87)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
BS = chr(92)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="latin-1") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="latin-1") as f:
        f.write(s)

def patch(p, old, new, tag, marker):
    s = rd(p)
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != 1:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected 1)")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

def create(p, text, tag, marker):
    fp = os.path.join(ROOT, p)
    if os.path.exists(fp):
        s = rd(p)
        if marker in s:
            already.append(tag)
            return
        fails.append(tag + ": exists without the marker")
        return
    wr(p, text)
    applied.append(tag)

p1_text = NL.join(['// ====================================================================', '// Adnd1 - rules/humrpref.h', '// R169: the humanoid racial preferences table', '// (DMG p.106) - the nine-race basic acceptability', '// matrix, the star marks and the letter key.', '//', '// Pure data, header-only (the grenade.h pattern:', '// the caller reads the letter and plays the', '// troops; the demi-human side stays on the PHB', '// RACIAL PREFERENCES TABLE, outside this box).', '//', '// The p.106 print:', '//   - Nine races, each rated against the same', '//     nine: bugbear, gnoll, goblin, hill giant,', '//     hobgoblin, kobold, ogre, orc, troll.', '//   - Six letters. P: preference and', '//     compatibility, even possible friendliness', '//     with appropriate co-operation. G: goodwill,', '//     no hostility and some co-operation', '//     possible. T: tolerate each other, open', '//     hostilities not likely. N: neutral', '//     negative feelings, no move to aid them if', '//     anything ill befalls. A: antipathy and', '//     active dislike, breaking into open', '//     hostility if the opportunity presents', '//     itself; if leaders or overseers are weak,', '//     these creatures will desert. H: hatred,', '//     possibly kept in check by fear, which', '//     will certainly break into open hostilities', '//     at the first opportunity, or else the', '//     hating humanoids will desert at the first', '//     chance if near a strong body of such', '//     hated creatures.', '//   - Single star: the race will bully and', '//     harass such humanoids (18 cells).', '//   - Double star: assumes the others of this', '//     race are of a rival tribe or family group', '//     - the hobgoblin, orc and troll self cells;', '//     the other six self cells print P.', '//   - Usage: consult whenever humanoid troops', '//     are fighting or serving side by side', '//     (within 12 inches of each other without', '//     any intervening troops or screen so that', '//     the other humanoids are visible); have', '//     the troops behave according to the letter', '//     key.', '//   - Compatibility of demi-human troops is the', '//     PLAYERS HANDBOOK RACIAL PREFERENCES TABLE.', '//     Lizard men are hated by all demi-humans', '//     and humanoids save kobolds, and even', '//     kobolds are suspicious of them, just as', '//     human troops are.', '// ====================================================================', '', '#pragma once', '', 'namespace rules {', '', 'enum HumRPrefCode {', '    HPREF_P = 0,  // preference', '    HPREF_G,      // goodwill', '    HPREF_T,      // tolerate', '    HPREF_N,      // neutral negative', '    HPREF_A,      // antipathy', '    HPREF_H       // hatred', '};', '', '// ----------------------------------------------------------------------------', '// The nine races (p.106)', '// ----------------------------------------------------------------------------', '', 'inline int humRPrefRaceCount() { return 9; }', '', 'inline const char* humRPrefRaceName(int i) {', '    static const char* const k[9] = {', '        "bugbear",', '        "gnoll",', '        "goblin",', '        "hill giant",', '        "hobgoblin",', '        "kobold",', '        "ogre",', '        "orc",', '        "troll"', '    };', '    if (i < 0) i = 0;', '    if (i > 8) i = 8;', '    return k[i];', '}', '', '// A tiny string equality (no library includes', '// in the header).', 'inline bool humStrEq(const char* a, const char* b) {', '    int i = 0;', '    while (a[i] != 0 && b[i] != 0) {', '        if (a[i] != b[i]) return false;', '        ++i;', '    }', '    return a[i] == b[i];', '}', '', 'inline int humRPrefRaceIndex(const char* name) {', '    for (int i = 0; i < 9; ++i)', '        if (humStrEq(humRPrefRaceName(i), name))', '            return i;', '    return -1;', '}', '', '// ----------------------------------------------------------------------------', '// The matrix (p.106) - 81 cells, row rates column', '// ----------------------------------------------------------------------------', '', 'inline HumRPrefCode humRPrefCode(int row, int col) {', '    static const HumRPrefCode k[9][9] = {', '        // bugbear', '        { HPREF_P, HPREF_T, HPREF_G, HPREF_T,', '          HPREF_A, HPREF_A, HPREF_T, HPREF_A,', '          HPREF_N },', '        // gnoll', '        { HPREF_T, HPREF_P, HPREF_A, HPREF_T,', '          HPREF_N, HPREF_A, HPREF_G, HPREF_T,', '          HPREF_N },', '        // goblin', '        { HPREF_G, HPREF_A, HPREF_P, HPREF_N,', '          HPREF_T, HPREF_G, HPREF_H, HPREF_N,', '          HPREF_A },', '        // hill giant', '        { HPREF_G, HPREF_G, HPREF_A, HPREF_P,', '          HPREF_A, HPREF_A, HPREF_G, HPREF_N,', '          HPREF_T },', '        // hobgoblin', '        { HPREF_T, HPREF_N, HPREF_N, HPREF_N,', '          HPREF_H, HPREF_A, HPREF_A, HPREF_T,', '          HPREF_H },', '        // kobold', '        { HPREF_A, HPREF_H, HPREF_G, HPREF_A,', '          HPREF_A, HPREF_P, HPREF_H, HPREF_A,', '          HPREF_T },', '        // ogre', '        { HPREF_T, HPREF_T, HPREF_A, HPREF_G,', '          HPREF_A, HPREF_A, HPREF_P, HPREF_T,', '          HPREF_T },', '        // orc', '        { HPREF_A, HPREF_N, HPREF_T, HPREF_A,', '          HPREF_N, HPREF_A, HPREF_G, HPREF_H,', '          HPREF_H },', '        // troll', '        { HPREF_A, HPREF_N, HPREF_A, HPREF_T,', '          HPREF_H, HPREF_T, HPREF_N, HPREF_A,', '          HPREF_N }', '    };', '    if (row < 0) row = 0;', '    if (row > 8) row = 8;', '    if (col < 0) col = 0;', '    if (col > 8) col = 8;', '    return k[row][col];', '}', '', '// The star marks: 1 = the single star (the race', '// will bully and harass such humanoids);', '// 2 = the double star (the others of this race', '// are of a rival tribe or family group).', 'inline int humRPrefStars(int row, int col) {', '    static const int k[9][9] = {', '        { 0, 1, 0, 0, 1, 1, 0, 1, 0 },', '        { 0, 0, 1, 0, 0, 1, 0, 1, 0 },', '        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },', '        { 0, 0, 0, 0, 0, 0, 0, 1, 0 },', '        { 0, 0, 1, 0, 2, 1, 0, 1, 0 },', '        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },', '        { 0, 1, 1, 0, 1, 1, 0, 1, 0 },', '        { 0, 0, 1, 0, 0, 1, 0, 2, 0 },', '        { 0, 0, 0, 0, 0, 0, 0, 0, 2 }', '    };', '    if (row < 0) row = 0;', '    if (row > 8) row = 8;', '    if (col < 0) col = 0;', '    if (col > 8) col = 8;', '    return k[row][col];', '}', '', 'inline bool humRPrefBullyMark(int row, int col) {', '    return humRPrefStars(row, col) == 1;', '}', '', 'inline bool humRPrefRivalTribe(int row, int col) {', '    return humRPrefStars(row, col) == 2;', '}', '', '// The letter key names.', 'inline const char* humRPrefCodeName(HumRPrefCode c) {', '    static const char* const k[6] = {', '        "preference",', '        "goodwill",', '        "tolerate",', '        "neutral negative",', '        "antipathy",', '        "hatred"', '    };', '    if (c < HPREF_P) c = HPREF_P;', '    if (c > HPREF_H) c = HPREF_H;', '    return k[c];', '}', '', 'inline char humRPrefCodeLetter(HumRPrefCode c) {', '    static const char k[6] = {', '        ' + chr(39) + 'P' + chr(39) + ', ' + chr(39) + 'G' + chr(39) + ', ' + chr(39) + 'T' + chr(39) + ',', '        ' + chr(39) + 'N' + chr(39) + ', ' + chr(39) + 'A' + chr(39) + ', ' + chr(39) + 'H' + chr(39), '    };', '    if (c < HPREF_P) c = HPREF_P;', '    if (c > HPREF_H) c = HPREF_H;', '    return k[c];', '}', '', '// ----------------------------------------------------------------------------', '// The letter definitions and the usage prose (p.106)', '// ----------------------------------------------------------------------------', '', '// P: preference and compatibility, even', '// possible friendliness with appropriate', '// co-operation. G: goodwill, no hostility and', '// some co-operation possible. T: the races can', '// tolerate each other, open hostilities not', '// likely to be evident. N: neutral negative', '// feelings; no move to aid them if anything', '// ill befalls.', 'inline bool humCodeAllowsCoOperation(HumRPrefCode c) {', '    return c == HPREF_P || c == HPREF_G;', '}', 'inline bool humCodeNoHostilityLikely(HumRPrefCode c) {', '    return c == HPREF_T;', '}', 'inline bool humCodeNoAidIfIllBefalls(HumRPrefCode c) {', '    return c == HPREF_N;', '}', '', '// A: antipathy and active dislike which will', '// break into open hostility if the', '// opportunity presents itself; if leaders or', '// overseers are weak, these creatures will', '// desert.', 'inline bool humAntipathyDesertIfLeadersWeak() {', '    return true;', '}', '', '// H: hatred, possibly kept in check by fear,', '// which will certainly break into open', '// hostilities at the first opportunity, or else', '// the hating humanoids will desert at the first', '// chance if near a strong body of such hated', '// creatures.', 'inline bool humHatredBreaksOutAtFirstOpportunity() {', '    return true;', '}', 'inline bool humHatredDesertsNearStrongHatedBody() {', '    return true;', '}', '', '// Use the table whenever humanoid troops are', '// fighting or even serving side by side (within', '// 12 inches of each other without any', '// intervening troops or screen so that the other', '// humanoids are visible). Have the troops', '// behave according to the letter key.', 'inline int humSideBySideVisibilityRangeInches() {', '    return 12;', '}', 'inline bool humInterveningTroopsOrScreenBlocks() {', '    return true;', '}', '', '// ----------------------------------------------------------------------------', '// The compatibility prose (p.106)', '// ----------------------------------------------------------------------------', '', '// The general compatibility of demi-human', '// troop types is the PLAYERS HANDBOOK RACIAL', '// PREFERENCES TABLE.', 'inline bool humDemihumanCompatibilityFromPHBTable() {', '    return true;', '}', '', '// Lizard men are hated by all demi-humans and', '// humanoids save kobolds, and even the latter', '// are suspicious of them, just as human troops', '// are.', 'inline bool humLizardMenHatedByAllHumanoidsSaveKobolds() {', '    return true;', '}', 'inline bool humKoboldsSuspiciousOfLizardMen() {', '    return true;', '}', 'inline bool humHumanTroopsSuspiciousOfLizardMen() {', '    return true;', '}', '', '} // namespace rules', ''])
create("rules/humrpref.h", p1_text,
      "humrpref.h: the humanoid racial preferences layer",
      marker="humRPrefRaceCount")
assert len(applied) + len(already) == 1

p2_old = NL.join(['#include "rules/uwspells.h"  // R168: p.57 underwater spell use'])
p2_new = NL.join(['#include "rules/uwspells.h"  // R168: p.57 underwater spell use', '#include "rules/humrpref.h"  // R169: p.106 humanoid racial preferences'])
patch("regtest.cpp", p2_old, p2_new,
      "regtest.cpp: humrpref include",
      marker='rules/humrpref.h"  // R169')
assert len(applied) + len(already) == 2

p3_old = NL.join(['        printf("R168 underwater spell use audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
p3_new = NL.join(['        printf("R168 underwater spell use audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R169: humanoid racial preferences audit ----', '    // DMG p.106: the nine-race matrix cell by', '    // cell, the star marks, the letter key and', '    // the usage and compatibility prose.', '    {', '        int bad = 0;', '        // the nine race names, in print order', '        if (rules::humRPrefRaceCount() != 9) ++bad;', '        static const char* kRace[9] = {', '            "bugbear", "gnoll", "goblin", "hill giant",', '            "hobgoblin", "kobold", "ogre", "orc", "troll"', '        };', '        for (int i = 0; i < 9; ++i)', '            if (std::string(rules::humRPrefRaceName(i))', '                    != kRace[i])', '                ++bad;', '        // the race index probe, both ways', '        if (rules::humRPrefRaceIndex("hobgoblin") != 4 ||', '            rules::humRPrefRaceIndex("troll") != 8 ||', '            rules::humRPrefRaceIndex("bugbear") != 0 ||', '            rules::humRPrefRaceIndex("purple worm") != -1)', '            ++bad;', '        // the full 81-cell matrix and the star', '        // marks, cell by cell', '        static const rules::HumRPrefCode kWant[9][9] = {', '            { rules::HPREF_P, rules::HPREF_T, rules::HPREF_G, rules::HPREF_T, rules::HPREF_A, rules::HPREF_A, rules::HPREF_T, rules::HPREF_A, rules::HPREF_N },', '            { rules::HPREF_T, rules::HPREF_P, rules::HPREF_A, rules::HPREF_T, rules::HPREF_N, rules::HPREF_A, rules::HPREF_G, rules::HPREF_T, rules::HPREF_N },', '            { rules::HPREF_G, rules::HPREF_A, rules::HPREF_P, rules::HPREF_N, rules::HPREF_T, rules::HPREF_G, rules::HPREF_H, rules::HPREF_N, rules::HPREF_A },', '            { rules::HPREF_G, rules::HPREF_G, rules::HPREF_A, rules::HPREF_P, rules::HPREF_A, rules::HPREF_A, rules::HPREF_G, rules::HPREF_N, rules::HPREF_T },', '            { rules::HPREF_T, rules::HPREF_N, rules::HPREF_N, rules::HPREF_N, rules::HPREF_H, rules::HPREF_A, rules::HPREF_A, rules::HPREF_T, rules::HPREF_H },', '            { rules::HPREF_A, rules::HPREF_H, rules::HPREF_G, rules::HPREF_A, rules::HPREF_A, rules::HPREF_P, rules::HPREF_H, rules::HPREF_A, rules::HPREF_T },', '            { rules::HPREF_T, rules::HPREF_T, rules::HPREF_A, rules::HPREF_G, rules::HPREF_A, rules::HPREF_A, rules::HPREF_P, rules::HPREF_T, rules::HPREF_T },', '            { rules::HPREF_A, rules::HPREF_N, rules::HPREF_T, rules::HPREF_A, rules::HPREF_N, rules::HPREF_A, rules::HPREF_G, rules::HPREF_H, rules::HPREF_H },', '            { rules::HPREF_A, rules::HPREF_N, rules::HPREF_A, rules::HPREF_T, rules::HPREF_H, rules::HPREF_T, rules::HPREF_N, rules::HPREF_A, rules::HPREF_N }', '        };', '        static const int kStar[9][9] = {', '            { 0, 1, 0, 0, 1, 1, 0, 1, 0 },', '            { 0, 0, 1, 0, 0, 1, 0, 1, 0 },', '            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },', '            { 0, 0, 0, 0, 0, 0, 0, 1, 0 },', '            { 0, 0, 1, 0, 2, 1, 0, 1, 0 },', '            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },', '            { 0, 1, 1, 0, 1, 1, 0, 1, 0 },', '            { 0, 0, 1, 0, 0, 1, 0, 2, 0 },', '            { 0, 0, 0, 0, 0, 0, 0, 0, 2 }', '        };', '        int nP = 0, nG = 0, nT = 0, nN = 0,', '            nA = 0, nH = 0, nSingle = 0, nDouble = 0;', '        for (int r = 0; r < 9; ++r) {', '            for (int c = 0; c < 9; ++c) {', '                if (rules::humRPrefCode(r, c) != kWant[r][c])', '                    ++bad;', '                if (rules::humRPrefStars(r, c)', '                        != kStar[r][c])', '                    ++bad;', '                if (rules::humRPrefBullyMark(r, c)', '                        != (kStar[r][c] == 1))', '                    ++bad;', '                if (rules::humRPrefRivalTribe(r, c)', '                        != (kStar[r][c] == 2))', '                    ++bad;', '                switch (rules::humRPrefCode(r, c)) {', '                case rules::HPREF_P: ++nP; break;', '                case rules::HPREF_G: ++nG; break;', '                case rules::HPREF_T: ++nT; break;', '                case rules::HPREF_N: ++nN; break;', '                case rules::HPREF_A: ++nA; break;', '                case rules::HPREF_H: ++nH; break;', '                }', '                if (rules::humRPrefStars(r, c) == 1) ++nSingle;', '                if (rules::humRPrefStars(r, c) == 2) ++nDouble;', '            }', '        }', '        // the letter census: P 6, G 10, T 18,', '        // N 14, A 25, H 8 (81 cells)', '        if (nP != 6 || nG != 10 || nT != 18 ||', '            nN != 14 || nA != 25 || nH != 8)', '            ++bad;', '        // 18 single stars, 3 double stars', '        if (nSingle != 18 || nDouble != 3) ++bad;', '        // the self cells: six print P, the', '        // hobgoblin, orc and troll cells print the', '        // double star (rival tribe or family', '        // group)', '        for (int i = 0; i < 9; ++i) {', '            bool selfP =', '                rules::humRPrefCode(i, i) == rules::HPREF_P;', '            bool rival = rules::humRPrefRivalTribe(i, i);', '            if (i == 4 || i == 7 || i == 8) {', '                if (selfP || !rival) ++bad;', '            } else {', '                if (!selfP || rival) ++bad;', '            }', '        }', '        // the letter key names and letters', '        if (std::string(rules::humRPrefCodeName(', '                rules::HPREF_P)) != "preference" ||', '            std::string(rules::humRPrefCodeName(', '                rules::HPREF_G)) != "goodwill" ||', '            std::string(rules::humRPrefCodeName(', '                rules::HPREF_T)) != "tolerate" ||', '            std::string(rules::humRPrefCodeName(', '                rules::HPREF_N)) != "neutral negative" ||', '            std::string(rules::humRPrefCodeName(', '                rules::HPREF_A)) != "antipathy" ||', '            std::string(rules::humRPrefCodeName(', '                rules::HPREF_H)) != "hatred" ||', '            rules::humRPrefCodeLetter(rules::HPREF_P) != ' + chr(39) + 'P' + chr(39) + ' ||', '            rules::humRPrefCodeLetter(rules::HPREF_G) != ' + chr(39) + 'G' + chr(39) + ' ||', '            rules::humRPrefCodeLetter(rules::HPREF_T) != ' + chr(39) + 'T' + chr(39) + ' ||', '            rules::humRPrefCodeLetter(rules::HPREF_N) != ' + chr(39) + 'N' + chr(39) + ' ||', '            rules::humRPrefCodeLetter(rules::HPREF_A) != ' + chr(39) + 'A' + chr(39) + ' ||', '            rules::humRPrefCodeLetter(rules::HPREF_H) != ' + chr(39) + 'H' + chr(39) + ')', '            ++bad;', '        // the letter semantics', '        if (!rules::humCodeAllowsCoOperation(', '                rules::HPREF_P) ||', '            !rules::humCodeAllowsCoOperation(', '                rules::HPREF_G) ||', '            rules::humCodeAllowsCoOperation(rules::HPREF_T) ||', '            !rules::humCodeNoHostilityLikely(rules::HPREF_T) ||', '            rules::humCodeNoHostilityLikely(rules::HPREF_N) ||', '            !rules::humCodeNoAidIfIllBefalls(rules::HPREF_N) ||', '            rules::humCodeNoAidIfIllBefalls(rules::HPREF_G))', '            ++bad;', '        // the antipathy and hatred behavior', '        if (!rules::humAntipathyDesertIfLeadersWeak() ||', '            !rules::humHatredBreaksOutAtFirstOpportunity() ||', '            !rules::humHatredDesertsNearStrongHatedBody())', '            ++bad;', '        // the usage prose: side by side within 12', '        // inches, no intervening troops or screen', '        if (rules::humSideBySideVisibilityRangeInches() != 12 ||', '            !rules::humInterveningTroopsOrScreenBlocks())', '            ++bad;', '        // the compatibility prose', '        if (!rules::humDemihumanCompatibilityFromPHBTable() ||', '            !rules::humLizardMenHatedByAllHumanoidsSaveKobolds() ||', '            !rules::humKoboldsSuspiciousOfLizardMen() ||', '            !rules::humHumanTroopsSuspiciousOfLizardMen())', '            ++bad;', '        // spot probes of the matrix in print', '        // coordinates', '        if (rules::humRPrefCode(0, 2) != rules::HPREF_G ||', '            rules::humRPrefCode(2, 0) != rules::HPREF_G ||', '            rules::humRPrefCode(4, 8) != rules::HPREF_H ||', '            rules::humRPrefCode(8, 4) != rules::HPREF_H ||', '            rules::humRPrefCode(1, 6) != rules::HPREF_G ||', '            rules::humRPrefCode(6, 1) != rules::HPREF_T ||', '            rules::humRPrefCode(5, 1) != rules::HPREF_H ||', '            rules::humRPrefCode(5, 6) != rules::HPREF_H)', '            ++bad;', '        if (!rules::humRPrefBullyMark(0, 1) ||', '            !rules::humRPrefBullyMark(0, 4) ||', '            !rules::humRPrefBullyMark(6, 5) ||', '            !rules::humRPrefBullyMark(7, 5) ||', '            !rules::humRPrefBullyMark(3, 7) ||', '            !rules::humRPrefBullyMark(4, 2) ||', '            rules::humRPrefBullyMark(4, 4) ||', '            rules::humRPrefBullyMark(2, 5) ||', '            rules::humRPrefRivalTribe(0, 4))', '            ++bad;', '        printf("R169 humanoid racial preferences audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
patch("regtest.cpp", p3_old, p3_new,
      "regtest.cpp: R169 audit block",
      marker="R169 humanoid racial preferences audit")
assert len(applied) + len(already) == 3

p4_old = NL.join(['the encounter tables stay pinned R60/R127.', 'Census 86.', '', 'Categories:'])
p4_new = NL.join(['the encounter tables stay pinned R60/R127.', 'Census 86.', 'R169 PINNED the humanoid racial preferences table', '(DMG p.106) - rules/humrpref.h: the nine-race', 'basic acceptability matrix (bugbear, gnoll,', 'goblin, hill giant, hobgoblin, kobold, ogre,', 'orc, troll - each rated against the same nine),', 'all 81 cells pinned with the star marks (18', 'single-star cells: the race will bully and', 'harass such humanoids; 3 double-star self', 'cells - hobgoblin, orc, troll - where the', 'others of the race are of a rival tribe or', 'family group, the other six self cells print', 'P); the six-letter key (P preference, G', 'goodwill, T tolerate, N neutral negative, A', 'antipathy - desert if leaders are weak, H', 'hatred - breaks into open hostilities at the', 'first opportunity or desert near a strong', 'body of the hated); the usage prose (fighting', 'or serving side by side within 12 inches,', 'no intervening troops or screen); and the', 'compatibility prose (demi-human troops use', 'the PHB RACIAL PREFERENCES TABLE; lizard men', 'hated by all save kobolds, and even kobolds', 'suspicious, just as human troops are).', 'JUDGMENT: the OCR wraps each row across', 'lines; the reconstruction was cross-validated', 'against the known print readings and every', 'probe matched. The caller reads the letter', 'and plays the troops. Census 87.', '', 'Categories:'])
patch("tools/dmg_gap_report.md", p4_old, p4_new,
      "gap report: R169 header note",
      marker="R169 PINNED the humanoid racial preferences table")
assert len(applied) + len(already) == 4

p5_old = NL.join(['- [ ] **Humanoid racial preferences (p.106)** - the', '      association matrix for lair and population', '      placement passes.'])
p5_new = NL.join(['- [x] **Humanoid racial preferences (p.106)** - PINNED', '      R169: rules/humrpref.h (the 81-cell matrix with', '      the star marks, the letter key, the usage and', '      the compatibility prose).'])
patch("tools/dmg_gap_report.md", p5_old, p5_new,
      "gap report: humanoid racial preferences box closed",
      marker="R169: rules/humrpref.h (the 81-cell matrix with")
assert len(applied) + len(already) == 5

# ---- R169 fails/tail ----
if fails:
    print("R169 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print("R169 splice: FAIL - expected 5 patches, counted " + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R169 splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R169 splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R169 note: 5 patches; census 87; commit: R169: humanoid racial preferences pinned - the p.106 nine-race matrix and letter key (census 87)")
