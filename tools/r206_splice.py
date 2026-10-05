#!/usr/bin/env python3
# R206 splice: pursuit and evasion of pursuit (DMG
# pp.67-69) - a whole seam the repo never
# touched: no coverage in any rules/ file, no
# mention in either gap report. The print:
#   - rules/pursuit.h (new file, the grenade.h
#     pattern: pure data + helpers, header-only)
#   - underground: the pursuit likelihood ladder
#     (stated certain; semi-intelligent or under
#     and motivated 80 percent; low intelligence
#     by party-vs-pursuer numbers 20/40/80, 100
#     when the pursuers feel greatly superior)
#   - the three end-condition cases by relative
#     speed (pursued faster: 100 feet in sight /
#     50 feet out of sight / 5 rounds; equal:
#     150 / 80 / 1 turn; pursuer faster: 200 feet
#     out of sight / endurance)
#   - the distraction modifiers: the food rule
#     (d10 base, +10 percent per intelligence
#     point below 5, 100 percent for
#     non-intelligent, second d10 to confirm, 1
#     round break-off) and the treasure rule
#     (+10 percent per 10 items for low
#     intelligence, +10 percent per 100 gp for
#     average or greater, distracted 1 round or
#     the gather time, whichever greater)
#   - the multiple-choice rule (3-way branch 2
#     in 3 wrong; door and passage 1 in 2) with
#     the detection radii (corner cuts sight to
#     60 feet; metal armor 90, hard boots 60,
#     quiet movement 30; scent persists)
#   - the movement procedure (tens of feet by
#     the slowest member, 3 phases = 1 round,
#     10 feet = confrontation)
#   - outdoor: the BASE CHANCE OF EVADING
#     PURSUIT OUTDOORS table - base 80 percent,
#     the speed, terrain, size and light
#     adjustment rows, cell for cell - plus the
#     surprise rule (party surprised the
#     encountered: automatic; party surprised:
#     impossible) and the hourly recheck (0 or
#     less: immediate confrontation)
#   - the regtest include + the R206 audit
#   - the gap-report log entry rides this commit
#     (the R202 convention)
# Patches: 4 (pursuit.h, regtest include,
# regtest audit, dmg_gap_report.md). Census
# 121 -> 122.

BS = chr(92)
NL = chr(10)
Q = chr(39)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


def patch(path, marker, old, new):
    # in-place marker patch; old must be unique
    global applied, already
    t = rd(path)
    if marker in t:
        already += 1
        return
    assert marker not in t, 'marker must be absent pre-patch: ' + marker
    assert t.count(old) == 1, 'anchor not unique in ' + path + ': ' + marker
    t = t.replace(old, new)
    assert marker in t, 'marker missing post-patch in ' + path
    assert NL not in marker, 'marker spans a newline: ' + marker
    wr(path, t)
    applied += 1


def newfile(path, marker, text):
    # create-only patch; the file must not exist pre-patch
    global applied, already
    import os
    if os.path.exists(path):
        t = rd(path)
        assert marker in t, 'existing file lacks the marker: ' + path
        already += 1
        return
    assert marker in text, 'marker missing from the new text: ' + marker
    wr(path, text)
    applied += 1


# ---------------------------------------------------------------------------
# Patch 1: rules/pursuit.h (new file)
# ---------------------------------------------------------------------------

h = [
    '// ====================================================================',
    '// Adnd1 - rules/pursuit.h',
    '// R206: pursuit and evasion of pursuit (DMG',
    '// pp.67-69) - the underground and outdoor',
    '// pursuit machinery. A seam with no prior',
    '// coverage: no rules/ file and no gap-report',
    '// mention.',
    '//',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern: the caller owns the',
    '// map, the movement phases and the weekly',
    '// clock; the rolls and bands read here).',
    '// Conventions, named in place:',
    '//   - PURSUED_FASTER / EQUAL_SPEED /',
    '//     PURSUER_FASTER name the relative-speed',
    '//     cases; the end-condition helpers read',
    '//     the printed thresholds.',
    '//   - The distractions run 10-100 percent',
    '//     and are the caller adjudication',
    '//     (the print says so); the FOOD and',
    '//     TREASURE sub-cases carry their own',
    '//     arithmetic here.',
    '//   - Outdoor evasion: the base 80 percent',
    '//     plus the four adjustment groups; the',
    '//     caller sums the group picks and rolls',
    '//     d100 against the total, hourly, and 0',
    '//     or less is immediate confrontation.',
    '//   - JUDGMENTs: the pursued-count and',
    '//     pursuer-count adjustments are',
    '//     independent rows (the print lists them',
    '//     side by side); intelligence thresholds',
    '//     follow the print (semi-intelligent or',
    '//     under; low; average or greater).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// -----------------------------------------------------------------------',
    '// Underground: will pursuit occur?',
    '// -----------------------------------------------------------------------',
    '',
    '// Case 2: semi-intelligent or under, and',
    '// hungry, angry, aggressive or trained -',
    '// 80 percent likely.',
    'inline int pursueLikelihoodMotivatedSemi() {',
    '    return 80;',
    '}',
    '',
    '// Case 3: low intelligence (otherwise',
    '// qualifying) - by party vs pursuer',
    '// numbers: outnumbers 20, about equal 40,',
    '// outnumbered 80, and 100 when the',
    '// outnumbering pursuers feel greatly',
    '// superior.',
    'inline int pursueLikelihoodLowInt(',
    '        bool partyOutnumbers,',
    '        bool partiesAboutEqual,',
    '        bool pursuersFeelSuperior) {',
    '    if (partyOutnumbers) return 20;',
    '    if (partiesAboutEqual) return 40;',
    '    if (pursuersFeelSuperior) return 100;',
    '    return 80;',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The relative-speed cases',
    '// -----------------------------------------------------------------------',
    '',
    'enum PursuitSpeed {',
    '    PURS_PURSUED_FASTER = 0,',
    '    PURS_EQUAL_SPEED,',
    '    PURS_PURSUER_FASTER,',
    '};',
    '',
    '// Pursuit ends when the pursued are in',
    '// sight but beyond the sight distance, or',
    '// out of sight and were beyond the',
    '// out-of-sight distance when lost, or the',
    '// pursuit has run past the round cap',
    '// without a perceptible gain (the pursuer-',
    '// faster case has no round cap: only the',
    '// distances and endurance).',
    'inline int pursuitEndSightFeet(PursuitSpeed s) {',
    '    static const int k[3] = { 100, 150, 0 };',
    '    if (s < PURS_PURSUED_FASTER) s = PURS_PURSUED_FASTER;',
    '    if (s > PURS_PURSUER_FASTER) s = PURS_PURSUER_FASTER;',
    '    return k[s];',
    '}',
    '',
    'inline int pursuitEndOutOfSightFeet(PursuitSpeed s) {',
    '    static const int k[3] = { 50, 80, 200 };',
    '    if (s < PURS_PURSUED_FASTER) s = PURS_PURSUED_FASTER;',
    '    if (s > PURS_PURSUER_FASTER) s = PURS_PURSUER_FASTER;',
    '    return k[s];',
    '}',
    '',
    '// The round cap: 5 rounds when the pursued',
    '// are faster, 1 turn (10 rounds) at equal',
    '// speed, no cap when the pursuer is faster',
    '// (-1).',
    'inline int pursuitEndRoundCap(PursuitSpeed s) {',
    '    static const int k[3] = { 5, 10, -1 };',
    '    if (s < PURS_PURSUED_FASTER) s = PURS_PURSUED_FASTER;',
    '    if (s > PURS_PURSUER_FASTER) s = PURS_PURSUER_FASTER;',
    '    return k[s];',
    '}',
    '',
    '// Does pursuit end this moment? (in sight,',
    '// beyond the sight distance; out of sight',
    '// and lost beyond the out-of-sight',
    '// distance; past the round cap without a',
    '// perceptible gain)',
    'inline bool pursuitEnds(PursuitSpeed s,',
    '                        bool inSight, int feetApart,',
    '                        bool outOfSight,',
    '                        int feetWhenLost,',
    '                        int roundsRun,',
    '                        bool gainedPerceptibly) {',
    '    if (inSight && feetApart > pursuitEndSightFeet(s))',
    '        return true;',
    '    if (outOfSight',
    '            && feetWhenLost > pursuitEndOutOfSightFeet(s))',
    '        return true;',
    '    int cap = pursuitEndRoundCap(s);',
    '    if (cap > 0 && roundsRun > cap && !gainedPerceptibly)',
    '        return true;',
    '    return false;',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The movement procedure (underground):',
    '// the pursued move in tens of feet by',
    '// their slowest member, the pursuers by',
    '// their fastest; 3 movement phases = 1',
    '// round; contact at 10 feet or less forces',
    '// confrontation.',
    '// -----------------------------------------------------------------------',
    'inline int pursuitPhasesPerRound() { return 3; }',
    'inline int pursuitConfrontFeet() { return 10; }',
    '',
    '// -----------------------------------------------------------------------',
    '// The FOOD distraction: d10 base, +10',
    '// percent per intelligence point below 5,',
    '// 100 percent for non-intelligent; under',
    '// 100 a second d10 at or under the',
    '// probability breaks pursuit for 1 round.',
    '// -----------------------------------------------------------------------',
    'inline int foodDistractionPercent(int d10, int intelligence) {',
    '    if (intelligence <= 0) return 100;',
    '    int pct = d10 * 10;',
    '    if (intelligence < 5) pct += 10 * (5 - intelligence);',
    '    if (pct > 100) pct = 100;',
    '    return pct;',
    '}',
    '',
    'inline bool foodDistractionSucceeds(int percent,',
    '                                    int secondD10) {',
    '    if (percent >= 100) return true;',
    '    return secondD10 * 10 <= percent;',
    '}',
    '',
    'inline int foodDistractionBreakRounds() { return 1; }',
    '',
    '// -----------------------------------------------------------------------',
    '// The TREASURE distraction: +10 percent per',
    '// 10 items dropped for low intelligence;',
    '// +10 percent per 100 gp of value (known,',
    '// presumed or potential) for average or',
    '// greater; distracted 1 round or the',
    '// gather time, whichever greater - the',
    '// gather time is caller-side.',
    '// -----------------------------------------------------------------------',
    'inline int treasureDistractionLowInt(',
    '        int basePercent, int itemsDropped) {',
    '    int pct = basePercent + 10 * (itemsDropped / 10);',
    '    if (pct > 100) pct = 100;',
    '    return pct;',
    '}',
    '',
    'inline int treasureDistractionValueBonus(',
    '        int gpValue) {',
    '    return 10 * (gpValue / 100);',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The multiple-choice rule: at a 3-way',
    '// branch 2 in 3 wrong; a door and a',
    '// passage 1 in 2. The detection clues:',
    '// straight-line sight is near infinite, a',
    '// corner cuts it to 60 feet; metal armor',
    '// hears at 90 feet, hard boots 60, quiet',
    '// movement 30; scent persists for hours.',
    '// -----------------------------------------------------------------------',
    'inline int pursuitWrongChoiceWays(int ways) {',
    '    return ways - 1;',
    '}',
    '',
    'inline int pursuitCornerSightFeet() { return 60; }',
    'inline int pursuitHearingMetalFeet() { return 90; }',
    'inline int pursuitHearingBootsFeet() { return 60; }',
    'inline int pursuitHearingQuietFeet() { return 30; }',
    '',
    '// -----------------------------------------------------------------------',
    '// Outdoor: the BASE CHANCE OF EVADING',
    '// PURSUIT OUTDOORS - base 80 percent with',
    '// the four adjustment groups.',
    '// -----------------------------------------------------------------------',
    '',
    'inline int evadeOutdoorBase() { return 80; }',
    '',
    '// Speed: pursued faster +10, equal 0,',
    '// pursuer faster -20.',
    'inline int evadeOutdoorSpeedAdj(PursuitSpeed s) {',
    '    static const int k[3] = { 10, 0, -20 };',
    '    if (s < PURS_PURSUED_FASTER) s = PURS_PURSUED_FASTER;',
    '    if (s > PURS_PURSUER_FASTER) s = PURS_PURSUER_FASTER;',
    '    return k[s];',
    '}',
    '',
    '// Terrain: plain, desert, open water -50;',
    '// scrub, rough, hills, marsh +10; forest,',
    '// mountains +30.',
    'enum EvadeTerrain { EVT_PLAIN_DESERT_WATER = 0,',
    '                    EVT_SCRUB_ROUGH_HILLS_MARSH,',
    '                    EVT_FOREST_MOUNTAINS };',
    '',
    'inline int evadeOutdoorTerrainAdj(EvadeTerrain t) {',
    '    static const int k[3] = { -50, 10, 30 };',
    '    if (t < EVT_PLAIN_DESERT_WATER) t = EVT_PLAIN_DESERT_WATER;',
    '    if (t > EVT_FOREST_MOUNTAINS) t = EVT_FOREST_MOUNTAINS;',
    '    return k[t];',
    '}',
    '',
    '// Size: the pursued party fewer than 6',
    '// +10; 6-11 0; 12-50 -20; over 50 -50.',
    '// The pursuing party: fewer than 12 -20;',
    '// 12-24 0; over 24 +10.',
    'inline int evadeOutdoorPursuedSizeAdj(int pursuedCount) {',
    '    if (pursuedCount < 6) return 10;',
    '    if (pursuedCount <= 11) return 0;',
    '    if (pursuedCount <= 50) return -20;',
    '    return -50;',
    '}',
    '',
    'inline int evadeOutdoorPursuerSizeAdj(int pursuerCount) {',
    '    if (pursuerCount < 12) return -20;',
    '    if (pursuerCount <= 24) return 0;',
    '    return 10;',
    '}',
    '',
    '// Light: full daylight -30; twilight -10;',
    '// bright moonlight 0; starlight +20; dark',
    '// night +50.',
    'enum EvadeLight { EVL_FULL_DAYLIGHT = 0, EVL_TWILIGHT,',
    '                  EVL_BRIGHT_MOONLIGHT, EVL_STARLIGHT,',
    '                  EVL_DARK_NIGHT };',
    '',
    'inline int evadeOutdoorLightAdj(EvadeLight l) {',
    '    static const int k[5] = { -30, -10, 0, 20, 50 };',
    '    if (l < EVL_FULL_DAYLIGHT) l = EVL_FULL_DAYLIGHT;',
    '    if (l > EVL_DARK_NIGHT) l = EVL_DARK_NIGHT;',
    '    return k[l];',
    '}',
    '',
    '// The assembled outdoor evasion chance:',
    '// base + speed + terrain + pursued size +',
    '// pursuer size + light. The pursued roll',
    '// d100 at or under to evade, hourly; a',
    '// chance of 0 or less is immediate',
    '// confrontation with no further evasion.',
    'inline int evadeOutdoorChance(PursuitSpeed s,',
    '                              EvadeTerrain t,',
    '                              int pursuedCount,',
    '                              int pursuerCount,',
    '                              EvadeLight l) {',
    '    int c = evadeOutdoorBase()',
    '          + evadeOutdoorSpeedAdj(s)',
    '          + evadeOutdoorTerrainAdj(t)',
    '          + evadeOutdoorPursuedSizeAdj(pursuedCount)',
    '          + evadeOutdoorPursuerSizeAdj(pursuerCount)',
    '          + evadeOutdoorLightAdj(l);',
    '    return c;',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The outdoor surprise rule: a party that',
    '// surprised the encountered evades',
    '// automatically; a surprised party cannot',
    '// evade at all.',
    '// -----------------------------------------------------------------------',
    'inline bool evadeAutoOnSurprise(bool partySurprisedThem) {',
    '    return partySurprisedThem;',
    '}',
    '',
    'inline bool evadePossibleWhenSurprised(bool partyIsSurprised) {',
    '    return !partyIsSurprised;',
    '}',
    '',
    '// The hourly recheck: 0 or less means',
    '// immediate confrontation.',
    'inline bool evadeOutdoorConfronts(int chance) {',
    '    return chance <= 0;',
    '}',
    '',
    '} // namespace rules',
    '',
]

newfile('rules/pursuit.h',
        'R206: pursuit and evasion of pursuit (DMG',
        NL.join(h))

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = ('#include "rules/spying.h"  // R205: pp.19-20 the spying tables'
        + NL + '#include <cstdio>')

new2 = ('#include "rules/spying.h"  // R205: pp.19-20 the spying tables'
        + NL + '#include "rules/pursuit.h"  // R206: pp.67-69 pursuit and evasion'
        + NL + '#include <cstdio>')

patch('regtest.cpp',
      'R206: pp.67-69 pursuit and evasion',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R206 audit (after the R205 block)
# ---------------------------------------------------------------------------

aud = []
a = aud.append
a('    // ---- R206: the pursuit and evasion audit ----')
a('    // DMG pp.67-69: the underground pursuit')
a('    // likelihood ladder, the three end-condition')
a('    // cases by relative speed, the food and')
a('    // treasure distractions, the multiple-choice')
a('    // and detection radii, and the outdoor')
a('    // evasion table (base 80 with the speed,')
a('    // terrain, size and light adjustments).')
a('    {')
a('        int bad = 0;')
a('        // the motivated semi-intelligent band')
a('        if (rules::pursueLikelihoodMotivatedSemi() != 80)')
a('            ++bad;')
a('        // the low-intelligence ladder: 20 / 40 /')
a('        // 80, and 100 when the outnumbering')
a('        // pursuers feel greatly superior')
a('        if (rules::pursueLikelihoodLowInt(')
a('                true, false, false) != 20 ||')
a('            rules::pursueLikelihoodLowInt(')
a('                false, true, false) != 40 ||')
a('            rules::pursueLikelihoodLowInt(')
a('                false, false, false) != 80 ||')
a('            rules::pursueLikelihoodLowInt(')
a('                false, false, true) != 100) ++bad;')
a('        // the end-condition distances and caps by')
a('        // relative speed: 100/50/5 rounds,')
a('        // 150/80/1 turn, 200/none/no cap')
a('        if (rules::pursuitEndSightFeet(')
a('                rules::PURS_PURSUED_FASTER) != 100 ||')
a('            rules::pursuitEndSightFeet(')
a('                rules::PURS_EQUAL_SPEED) != 150 ||')
a('            rules::pursuitEndSightFeet(')
a('                rules::PURS_PURSUER_FASTER) != 0) ++bad;')
a('        if (rules::pursuitEndOutOfSightFeet(')
a('                rules::PURS_PURSUED_FASTER) != 50 ||')
a('            rules::pursuitEndOutOfSightFeet(')
a('                rules::PURS_EQUAL_SPEED) != 80 ||')
a('            rules::pursuitEndOutOfSightFeet(')
a('                rules::PURS_PURSUER_FASTER) != 200) ++bad;')
a('        if (rules::pursuitEndRoundCap(')
a('                rules::PURS_PURSUED_FASTER) != 5 ||')
a('            rules::pursuitEndRoundCap(')
a('                rules::PURS_EQUAL_SPEED) != 10 ||')
a('            rules::pursuitEndRoundCap(')
a('                rules::PURS_PURSUER_FASTER) != -1) ++bad;')
a('        // the composition: in sight at 101 feet')
a('        // ends the faster-pursued case; 100 does')
a('        // not; out of sight lost at 201 ends the')
a('        // pursuer-faster case; past the round cap')
a('        // without a gain ends it')
a('        if (!rules::pursuitEnds(')
a('                rules::PURS_PURSUED_FASTER, true, 101,')
a('                false, 0, 0, false)) ++bad;')
a('        if (rules::pursuitEnds(')
a('                rules::PURS_PURSUED_FASTER, true, 100,')
a('                false, 0, 0, false)) ++bad;')
a('        if (!rules::pursuitEnds(')
a('                rules::PURS_PURSUER_FASTER, false, 0,')
a('                true, 201, 0, false)) ++bad;')
a('        if (rules::pursuitEnds(')
a('                rules::PURS_PURSUER_FASTER, false, 0,')
a('                true, 200, 0, false)) ++bad;')
a('        if (!rules::pursuitEnds(')
a('                rules::PURS_EQUAL_SPEED, false, 0,')
a('                false, 0, 11, false)) ++bad;')
a('        if (rules::pursuitEnds(')
a('                rules::PURS_EQUAL_SPEED, false, 0,')
a('                false, 0, 11, true)) ++bad;')
a('        // the movement procedure: 3 phases per')
a('        // round, contact at 10 feet')
a('        if (rules::pursuitPhasesPerRound() != 3 ||')
a('            rules::pursuitConfrontFeet() != 10) ++bad;')
a('        // the food distraction: 100 percent for')
a('        // non-intelligent; d10 base + 10 per point')
a('        // below 5; the confirm roll at or under')
a('        if (rules::foodDistractionPercent(0, 0) != 100 ||')
a('            rules::foodDistractionPercent(5, 5) != 50 ||')
a('            rules::foodDistractionPercent(5, 2) != 80 ||')
a('            rules::foodDistractionPercent(9, 1) != 100 ||')
a('            rules::foodDistractionPercent(3, 7) != 30)')
a('            ++bad;')
a('        if (rules::foodDistractionSucceeds(100, 1) ||')
a('            !rules::foodDistractionSucceeds(80, 8) ||')
a('            rules::foodDistractionSucceeds(80, 9) ||')
a('            !rules::foodDistractionSucceeds(30, 3) ||')
a('            rules::foodDistractionSucceeds(30, 4) ||')
a('            rules::foodDistractionBreakRounds() != 1)')
a('            ++bad;')
a('        // the treasure distraction: +10 per 10')
a('        // items for low intelligence, +10 per')
a('        // 100 gp of value')
a('        if (rules::treasureDistractionLowInt(')
a('                20, 20) != 40 ||')
a('            rules::treasureDistractionLowInt(')
a('                20, 100) != 100 ||')
a('            rules::treasureDistractionValueBonus(')
a('                250) != 20 ||')
a('            rules::treasureDistractionValueBonus(')
a('                99) != 0) ++bad;')
a('        // the multiple-choice and detection radii')
a('        if (rules::pursuitWrongChoiceWays(3) != 2 ||')
a('            rules::pursuitWrongChoiceWays(2) != 1)')
a('            ++bad;')
a('        if (rules::pursuitCornerSightFeet() != 60 ||')
a('            rules::pursuitHearingMetalFeet() != 90 ||')
a('            rules::pursuitHearingBootsFeet() != 60 ||')
a('            rules::pursuitHearingQuietFeet() != 30)')
a('            ++bad;')
a('        // the outdoor table: base 80, every')
a('        // adjustment row cell for cell')
a('        if (rules::evadeOutdoorBase() != 80) ++bad;')
a('        if (rules::evadeOutdoorSpeedAdj(')
a('                rules::PURS_PURSUED_FASTER) != 10 ||')
a('            rules::evadeOutdoorSpeedAdj(')
a('                rules::PURS_EQUAL_SPEED) != 0 ||')
a('            rules::evadeOutdoorSpeedAdj(')
a('                rules::PURS_PURSUER_FASTER) != -20) ++bad;')
a('        if (rules::evadeOutdoorTerrainAdj(')
a('                rules::EVT_PLAIN_DESERT_WATER) != -50 ||')
a('            rules::evadeOutdoorTerrainAdj(')
a('                rules::EVT_SCRUB_ROUGH_HILLS_MARSH) != 10 ||')
a('            rules::evadeOutdoorTerrainAdj(')
a('                rules::EVT_FOREST_MOUNTAINS) != 30) ++bad;')
a('        if (rules::evadeOutdoorPursuedSizeAdj(5) != 10 ||')
a('            rules::evadeOutdoorPursuedSizeAdj(6) != 0 ||')
a('            rules::evadeOutdoorPursuedSizeAdj(11) != 0 ||')
a('            rules::evadeOutdoorPursuedSizeAdj(12)')
a('                != -20 ||')
a('            rules::evadeOutdoorPursuedSizeAdj(50)')
a('                != -20 ||')
a('            rules::evadeOutdoorPursuedSizeAdj(51)')
a('                != -50) ++bad;')
a('        if (rules::evadeOutdoorPursuerSizeAdj(11)')
a('                != -20 ||')
a('            rules::evadeOutdoorPursuerSizeAdj(12) != 0 ||')
a('            rules::evadeOutdoorPursuerSizeAdj(24) != 0 ||')
a('            rules::evadeOutdoorPursuerSizeAdj(25)')
a('                != 10) ++bad;')
a('        if (rules::evadeOutdoorLightAdj(')
a('                rules::EVL_FULL_DAYLIGHT) != -30 ||')
a('            rules::evadeOutdoorLightAdj(')
a('                rules::EVL_TWILIGHT) != -10 ||')
a('            rules::evadeOutdoorLightAdj(')
a('                rules::EVL_BRIGHT_MOONLIGHT) != 0 ||')
a('            rules::evadeOutdoorLightAdj(')
a('                rules::EVL_STARLIGHT) != 20 ||')
a('            rules::evadeOutdoorLightAdj(')
a('                rules::EVL_DARK_NIGHT) != 50) ++bad;')
a('        // the assembly: a lone pursued party,')
a('        // pursuer faster, plain, dark night -')
a('        // 80 - 20 - 50 + 10 + 10 + 50 = 80; a')
a('        // 6-member party, equal speed, forest,')
a('        // 12-24 pursuers, daylight - 80 + 30 -')
a('        // 30 = 80; and a 12-member party, equal')
a('        // speed, plain, twilight, 30 pursuers -')
a('        // 80 - 50 - 20 - 10 = 0, the immediate-')
a('        // confrontation edge')
a('        if (rules::evadeOutdoorChance(')
a('                rules::PURS_PURSUER_FASTER,')
a('                rules::EVT_PLAIN_DESERT_WATER,')
a('                1, 25, rules::EVL_DARK_NIGHT) != 80 ||')
a('            rules::evadeOutdoorChance(')
a('                rules::PURS_EQUAL_SPEED,')
a('                rules::EVT_FOREST_MOUNTAINS,')
a('                6, 12, rules::EVL_FULL_DAYLIGHT) != 80 ||')
a('            rules::evadeOutdoorChance(')
a('                rules::PURS_EQUAL_SPEED,')
a('                rules::EVT_PLAIN_DESERT_WATER,')
a('                12, 30, rules::EVL_TWILIGHT) != 0)')
a('            ++bad;')
a('        // the outdoor surprise rule and the')
a('        // hourly recheck')
a('        if (!rules::evadeAutoOnSurprise(true) ||')
a('            rules::evadeAutoOnSurprise(false) ||')
a('            !rules::evadePossibleWhenSurprised(false) ||')
a('            rules::evadePossibleWhenSurprised(true) ||')
a('            !rules::evadeOutdoorConfronts(0) ||')
a('            !rules::evadeOutdoorConfronts(-10) ||')
a('            rules::evadeOutdoorConfronts(1)) ++bad;')
a('        printf("R206 pursuit and evasion audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

anchor = ('        printf("R205 spying tables audit: bad %d'
          + BS + 'n", bad);'
          + NL + '        if (bad) return 1;'
          + NL + '    }')

patch('regtest.cpp',
      'R206 pursuit and evasion audit',
      anchor,
      anchor + NL + NL.join(aud))

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the round-log entry (R202 convention)
# ---------------------------------------------------------------------------

entry = (
    'R206 landed pursuit and evasion of pursuit'
    + NL + '(DMG pp.67-69) - a seam with no prior'
    + NL + 'coverage in any rules/ file and no mention'
    + NL + 'in either gap report. rules/pursuit.h'
    + NL + '(the grenade.h pattern): underground,'
    + NL + 'the pursuit likelihood ladder (semi-'
    + NL + 'intelligent motivated 80 percent; low'
    + NL + 'intelligence 20/40/80 by numbers, 100'
    + NL + 'when the outnumbering pursuers feel'
    + NL + 'greatly superior), the three end-'
    + NL + 'condition cases by relative speed'
    + NL + '(100/50 feet/5 rounds; 150/80 feet/1'
    + NL + 'turn; 200 feet/no cap), the food and'
    + NL + 'treasure distractions with their d10'
    + NL + 'arithmetic, the multiple-choice rule and'
    + NL + 'the detection radii (corner 60 feet;'
    + NL + 'metal 90, boots 60, quiet 30), the'
    + NL + 'movement procedure (3 phases = 1 round,'
    + NL + 'contact at 10 feet); outdoor, the BASE'
    + NL + 'CHANCE OF EVADING PURSUIT table - base'
    + NL + '80 percent with the speed, terrain,'
    + NL + 'size and light rows cell for cell -'
    + NL + 'the surprise rule (surprised them:'
    + NL + 'automatic; surprised: impossible) and'
    + NL + 'the hourly recheck (0 or less:'
    + NL + 'immediate confrontation). New R206'
    + NL + 'battery audit; census 122. Next: the'
    + NL + 'DMG-only sweep continues.')

log_old = ('60 suicide); the hired-spy 8th-level cap.'
           + NL + 'New R205 battery audit; census 121. Next:'
           + NL + 'the DMG-only sweep continues.'
           + NL + NL + 'Categories:')

log_new = ('60 suicide); the hired-spy 8th-level cap.'
           + NL + 'New R205 battery audit; census 121. Next:'
           + NL + 'the DMG-only sweep continues.'
           + NL + NL + entry + NL + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R206 landed pursuit and evasion',
      log_old,
      log_new)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R206 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R206 note: 4 patches; pursuit and evasion pinned - the underground')
print('likelihood and end-condition machinery, the distractions, the outdoor')
print('evasion table; the log entry rides this commit; census 122.')
print('commit: R206: pursuit and evasion of pursuit pinned - DMG pp.67-69,')
print('the underground cases and the outdoor evasion table (census 122)')

