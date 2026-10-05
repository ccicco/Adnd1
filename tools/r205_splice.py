#!/usr/bin/env python3
# R205 splice: the spying tables (DMG pp.19-20,
# the SPYING section after the assassin guild
# tables) - the lane rules/assassinate.h named
# and deferred in R164: "the p.19-20 spying
# rules stay as wired (the spy)". The guild
# block around it is pinned (R170 - the race,
# level, multi-class and Grandfather tables);
# this round pins the mission machinery:
#   - rules/spying.h (new file, the grenade.h
#     pattern: pure data + helpers, header-only)
#   - the ASSASSIN SPYING TABLE: assassin/spy
#     level 1-17 x the three mission categories
#     (simple, difficult, extraordinary), cell
#     for cell
#   - the mission time: simple 1-8 days,
#     difficult 5-40, extraordinary as required
#     (caller-side)
#   - the chance of discovery: cumulative 1%
#     per day spent, max 10%, minus the spy
#     level, always at least 1%; the precaution
#     tiers (no precautions 1% per week flat;
#     minimal the modified % per week; moderate
#     the modified % twice per week; strong the
#     doubled modified % twice per week); the
#     leader rule (a spy who leads the group
#     reads no precautions); the tenfold window
#     (20-50 days after a spy is caught)
#   - the SPY FAILURE TABLE: the five bands
#     (01-35 retry, 36-60 further attempts 90%
#     fail, 61-80 caught suspicious and
#     imprisoned, 81-95 caught with proof and
#     tortured, 96-00 killed or turned) with
#     the printed modifiers (difficult +10,
#     extraordinary -5, discovered +25)
#   - the torture outcomes (1-2 dead, 3-4
#     revealed, 5-6 turncoat) and the fanatical
#     spy rule (never a double agent; any dice
#     total over 60 is suicide)
#   - the hired-spy cap: 8th level, advancing
#     one level per mission (caller-side)
#   - the regtest include + the R205 audit
#   - the gap-report log entry rides this commit
#     (the R202 convention)
# Patches: 4 (spying.h, regtest include,
# regtest audit, dmg_gap_report.md). Census
# 120 -> 121.

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
# Patch 1: rules/spying.h (new file)
# ---------------------------------------------------------------------------

h = [
    '// ====================================================================',
    '// Adnd1 - rules/spying.h',
    '// R205: the spying tables (DMG pp.19-20, the',
    '// SPYING section after the assassin guild',
    '// tables) - the lane rules/assassinate.h',
    '// named and deferred in R164.',
    '//',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern: the caller owns the',
    '// hire, the mission assignment and the',
    '// week-to-day clock; the rolls read here).',
    '// Conventions, named in place:',
    '//   - A hired spy reads the success table',
    '//     as a 1st-level assassin on the first',
    '//     mission, 2nd on the second, etc., and',
    '//     can never become more proficient at',
    '//     spying than 8th level (the print);',
    '//     the level bookkeeping is caller-side.',
    '//   - The success table runs to 17th level',
    '//     (the print); levels below 1 read',
    '//     row 1, above 17 read row 17.',
    '//   - Extraordinary mission time is "as',
    '//     required" - the print leaves it to',
    '//     the case; the helper reads 0-0 and',
    '//     the caller rules it.',
    '//   - The discovery chance is a PERIODIC',
    '//     check the caller schedules: no',
    '//     precautions 1 percent per week flat;',
    '//     minimal the modified percent per',
    '//     week; moderate the modified percent',
    '//     twice per week; strong the DOUBLED',
    '//     modified percent twice per week. A',
    '//     spy who leads the group reads no',
    '//     precautions (above suspicion).',
    '//   - The failure table doubles as the',
    '//     discovery table: the caught-spy',
    '//     result reads the same bands with',
    '//     the discovered modifier (+25).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// -----------------------------------------------------------------------',
    '// The three mission categories (the print order)',
    '// -----------------------------------------------------------------------',
    '',
    'enum SpyCategory {',
    '    SPY_SIMPLE = 0,',
    '    SPY_DIFFICULT,',
    '    SPY_EXTRAORDINARY,',
    '    SPY_CATEGORY_COUNT',
    '};',
    '',
    'inline const char* spyCategoryName(SpyCategory c) {',
    '    static const char* const n[SPY_CATEGORY_COUNT] = {',
    '        "simple", "difficult", "extraordinary"',
    '    };',
    '    if (c < SPY_SIMPLE) c = SPY_SIMPLE;',
    '    if (c >= SPY_CATEGORY_COUNT) c = SPY_EXTRAORDINARY;',
    '    return n[c];',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The ASSASSIN SPYING TABLE: the chance of',
    '// success by spy level (1-17) and category.',
    '// -----------------------------------------------------------------------',
    'inline int spySuccessChance(int level, SpyCategory c) {',
    '    static const int k[17][SPY_CATEGORY_COUNT] = {',
    '        { 50, 30, 10 },',
    '        { 55, 35, 15 },',
    '        { 60, 35, 15 },',
    '        { 65, 40, 20 },',
    '        { 70, 45, 25 },',
    '        { 75, 50, 25 },',
    '        { 80, 55, 30 },',
    '        { 85, 60, 35 },',
    '        { 85, 60, 40 },',
    '        { 90, 65, 45 },',
    '        { 90, 65, 50 },',
    '        { 95, 65, 50 },',
    '        { 95, 70, 50 },',
    '        { 95, 70, 50 },',
    '        { 95, 75, 50 },',
    '        { 95, 75, 55 },',
    '        { 95, 75, 60 },',
    '    };',
    '    if (level < 1) level = 1;',
    '    if (level > 17) level = 17;',
    '    if (c < SPY_SIMPLE) c = SPY_SIMPLE;',
    '    if (c >= SPY_CATEGORY_COUNT) c = SPY_EXTRAORDINARY;',
    '    return k[level - 1][c];',
    '}',
    '',
    '// The hired-spy level cap (the print: never',
    '// more proficient at spying than 8th level)',
    'inline int spyHiredLevelCap() { return 8; }',
    '',
    '// -----------------------------------------------------------------------',
    '// Time required to accomplish the mission:',
    '// simple 1-8 days, difficult 5-40 days,',
    '// extraordinary as required (0-0 - the caller',
    '// rules the case).',
    '// -----------------------------------------------------------------------',
    'inline void spyMissionDays(SpyCategory c, int& lo, int& hi) {',
    '    if (c == SPY_SIMPLE) { lo = 1; hi = 8; return; }',
    '    if (c == SPY_DIFFICULT) { lo = 5; hi = 40; return; }',
    '    lo = 0; hi = 0;',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The chance of discovery: the modified percent',
    '// is a cumulative 1 percent per day spent',
    '// spying, capped at 10, minus the spy level,',
    '// and always at least 1 percent (the print:',
    '// even a negative result leaves 1 percent).',
    '// -----------------------------------------------------------------------',
    'inline int spyModifiedDiscoveryChance(int daysSpent,',
    '                                      int spyLevel) {',
    '    int base = daysSpent;',
    '    if (base > 10) base = 10;',
    '    if (base < 0) base = 0;',
    '    int chance = base - spyLevel;',
    '    if (chance < 1) chance = 1;',
    '    return chance;',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The precaution tiers: how many discovery',
    '// checks per week, and the percent each check',
    '// reads. No precautions is a flat 1 percent',
    '// per week (the modified percent does not',
    '// apply); minimal reads the modified percent',
    '// once per week; moderate twice per week;',
    '// strong the DOUBLED modified percent twice',
    '// per week. A spy who leads the group reads',
    '// no precautions (above suspicion) - the',
    '// caller passes SPYP_NONE.',
    '// -----------------------------------------------------------------------',
    'enum SpyPrecautions { SPYP_NONE = 0, SPYP_MINIMAL,',
    '                      SPYP_MODERATE, SPYP_STRONG };',
    '',
    'inline int spyPrecautionChecksPerWeek(SpyPrecautions p) {',
    '    static const int k[4] = { 1, 1, 2, 2 };',
    '    if (p < SPYP_NONE) p = SPYP_NONE;',
    '    if (p > SPYP_STRONG) p = SPYP_STRONG;',
    '    return k[p];',
    '}',
    '',
    '// The percent chance for ONE discovery check',
    '// under the given precautions, given the',
    '// modified percent.',
    'inline int spyDiscoveryCheckPercent(SpyPrecautions p,',
    '                                     int modifiedPercent) {',
    '    if (p < SPYP_NONE) p = SPYP_NONE;',
    '    if (p > SPYP_STRONG) p = SPYP_STRONG;',
    '    if (p == SPYP_NONE) return 1;   // flat, per the print',
    '    if (p == SPYP_STRONG) return 2 * modifiedPercent;',
    '    return modifiedPercent;',
    '}',
    '',
    '// The tenfold window: if a spy is caught,',
    '// the chance of discovery increases tenfold',
    '// for any other spy operating during the',
    '// following 20 to 50 days.',
    'inline int spyPostCaptureWindowLo() { return 20; }',
    'inline int spyPostCaptureWindowHi() { return 50; }',
    'inline int spyPostCaptureChanceMultiple() { return 10; }',
    '',
    '// -----------------------------------------------------------------------',
    '// The SPY FAILURE TABLE (also the discovery',
    '// table, with the discovered modifier): the',
    '// five printed bands on d100.',
    '// -----------------------------------------------------------------------',
    'enum SpyFailureResult {',
    '    SPYF_RETRY = 0,           // 01-35: further attempts possible',
    '    SPYF_COMPROMISED_90,      // 36-60: further spying 90 percent fails',
    '    SPYF_IMPRISONED_SILENT,   // 61-80: caught suspicious, imprisoned',
    '    SPYF_CAUGHT_TORTURED,     // 81-95: caught with proof, tortured',
    '    SPYF_KILLED_OR_TURNED,    // 96-00: killed or turns coat',
    '    SPYF_COUNT',
    '};',
    '',
    'inline SpyFailureResult spyFailureResult(int d100) {',
    '    if (d100 < 36) return SPYF_RETRY;',
    '    if (d100 < 61) return SPYF_COMPROMISED_90;',
    '    if (d100 < 81) return SPYF_IMPRISONED_SILENT;',
    '    if (d100 < 96) return SPYF_CAUGHT_TORTURED;',
    '    return SPYF_KILLED_OR_TURNED;',
    '}',
    '',
    '// The failure-score modifiers: a difficult',
    '// mission +10, an extraordinary mission -5,',
    '// and a discovered spy +25 (the same table',
    '// reads the discovery).',
    'inline int spyFailureScoreAdj(SpyCategory c, bool discovered) {',
    '    int adj = 0;',
    '    if (c == SPY_DIFFICULT) adj += 10;',
    '    if (c == SPY_EXTRAORDINARY) adj -= 5;',
    '    if (discovered) adj += 25;',
    '    return adj;',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The torture outcomes (the 81-95 band): d6',
    '// 1-2 dead, 3-4 revealed everything, 5-6',
    '// turncoat.',
    '// -----------------------------------------------------------------------',
    'enum SpyTortureOutcome { SPYT_DEAD = 0, SPYT_REVEALED,',
    '                          SPYT_TURNCOAT };',
    '',
    'inline SpyTortureOutcome spyTortureOutcome(int d6) {',
    '    if (d6 <= 2) return SPYT_DEAD;',
    '    if (d6 <= 4) return SPYT_REVEALED;',
    '    return SPYT_TURNCOAT;',
    '}',
    '',
    '// The 90 percent of the 36-60 band: any',
    '// further spying attempt fails (discovery and',
    '// imprisonment follow)',
    'inline int spyCompromisedFailChance() { return 90; }',
    '',
    '// -----------------------------------------------------------------------',
    '// Fanatical spies: absolutely dedicated,',
    '// never double agents; on any dice total',
    '// over 60 they simply kill themselves.',
    '// -----------------------------------------------------------------------',
    'inline bool spyFanaticalNeverDoubleAgent() { return true; }',
    'inline bool spyFanaticalSuicided(int diceTotal) {',
    '    return diceTotal > 60;',
    '}',
    '',
    '} // namespace rules',
    '',
]

newfile('rules/spying.h',
        'R205: the spying tables (DMG pp.19-20, the',
        NL.join(h))

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = ('#include "rules/itemsavethrow.h"  // R204: p.80 item saving throw matrix'
        + NL + '#include <cstdio>')

new2 = ('#include "rules/itemsavethrow.h"  // R204: p.80 item saving throw matrix'
        + NL + '#include "rules/spying.h"  // R205: pp.19-20 the spying tables'
        + NL + '#include <cstdio>')

patch('regtest.cpp',
      'R205: pp.19-20 the spying tables',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R205 audit (after the R204 block)
# ---------------------------------------------------------------------------

aud = []
a = aud.append
a('    // ---- R205: the spying tables audit ----')
a('    // DMG pp.19-20: the success table (spy level')
a('    // 1-17 x the three categories), the mission')
a('    // days, the discovery formula with the')
a('    // precaution tiers, the failure bands with')
a('    // the modifiers, the torture outcomes and')
a('    // the fanatical rule.')
a('    {')
a('        int bad = 0;')
a('        // the success table, all 51 cells')
a('        static const int kS[17][3] = {')
a('            { 50, 30, 10 },')
a('            { 55, 35, 15 },')
a('            { 60, 35, 15 },')
a('            { 65, 40, 20 },')
a('            { 70, 45, 25 },')
a('            { 75, 50, 25 },')
a('            { 80, 55, 30 },')
a('            { 85, 60, 35 },')
a('            { 85, 60, 40 },')
a('            { 90, 65, 45 },')
a('            { 90, 65, 50 },')
a('            { 95, 65, 50 },')
a('            { 95, 70, 50 },')
a('            { 95, 70, 50 },')
a('            { 95, 75, 50 },')
a('            { 95, 75, 55 },')
a('            { 95, 75, 60 },')
a('        };')
a('        for (int lvl = 1; lvl <= 17; ++lvl)')
a('            for (int c = 0; c < 3; ++c)')
a('                if (rules::spySuccessChance(lvl,')
a('                        (rules::SpyCategory)c)')
a('                        != kS[lvl - 1][c]) ++bad;')
a('        // the level clamps: 0 reads row 1, 18+ row 17')
a('        if (rules::spySuccessChance(0, rules::SPY_SIMPLE) != 50 ||')
a('            rules::spySuccessChance(18, rules::SPY_SIMPLE) != 95)')
a('            ++bad;')
a('        // the hired-spy level cap')
a('        if (rules::spyHiredLevelCap() != 8) ++bad;')
a('        // the mission days: simple 1-8, difficult 5-40,')
a('        // extraordinary as required (0-0)')
a('        int lo, hi;')
a('        rules::spyMissionDays(rules::SPY_SIMPLE, lo, hi);')
a('        if (lo != 1 || hi != 8) ++bad;')
a('        rules::spyMissionDays(rules::SPY_DIFFICULT, lo, hi);')
a('        if (lo != 5 || hi != 40) ++bad;')
a('        rules::spyMissionDays(rules::SPY_EXTRAORDINARY, lo, hi);')
a('        if (lo != 0 || hi != 0) ++bad;')
a('        // the discovery formula: cumulative 1 percent')
a('        // per day capped at 10, minus the level, floor 1')
a('        if (rules::spyModifiedDiscoveryChance(1, 0) != 1 ||')
a('            rules::spyModifiedDiscoveryChance(3, 1) != 2 ||')
a('            rules::spyModifiedDiscoveryChance(10, 3) != 7 ||')
a('            rules::spyModifiedDiscoveryChance(30, 5) != 5 ||')
a('            rules::spyModifiedDiscoveryChance(30, 12) != 1 ||')
a('            rules::spyModifiedDiscoveryChance(0, 1) != 1) ++bad;')
a('        // the precaution tiers: checks per week and the')
a('        // percent each check reads (no precautions is a')
a('        // flat 1 percent, the modified percent ignored)')
a('        if (rules::spyPrecautionChecksPerWeek(')
a('                rules::SPYP_NONE) != 1 ||')
a('            rules::spyPrecautionChecksPerWeek(')
a('                rules::SPYP_MINIMAL) != 1 ||')
a('            rules::spyPrecautionChecksPerWeek(')
a('                rules::SPYP_MODERATE) != 2 ||')
a('            rules::spyPrecautionChecksPerWeek(')
a('                rules::SPYP_STRONG) != 2) ++bad;')
a('        if (rules::spyDiscoveryCheckPercent(')
a('                rules::SPYP_NONE, 7) != 1 ||')
a('            rules::spyDiscoveryCheckPercent(')
a('                rules::SPYP_MINIMAL, 7) != 7 ||')
a('            rules::spyDiscoveryCheckPercent(')
a('                rules::SPYP_MODERATE, 7) != 7 ||')
a('            rules::spyDiscoveryCheckPercent(')
a('                rules::SPYP_STRONG, 7) != 14) ++bad;')
a('        // the tenfold window: 20-50 days, x10')
a('        if (rules::spyPostCaptureWindowLo() != 20 ||')
a('            rules::spyPostCaptureWindowHi() != 50 ||')
a('            rules::spyPostCaptureChanceMultiple() != 10)')
a('            ++bad;')
a('        // the failure bands: the five edges')
a('        if (rules::spyFailureResult(1) != rules::SPYF_RETRY ||')
a('            rules::spyFailureResult(35) != rules::SPYF_RETRY ||')
a('            rules::spyFailureResult(36)')
a('                != rules::SPYF_COMPROMISED_90 ||')
a('            rules::spyFailureResult(60)')
a('                != rules::SPYF_COMPROMISED_90 ||')
a('            rules::spyFailureResult(61)')
a('                != rules::SPYF_IMPRISONED_SILENT ||')
a('            rules::spyFailureResult(80)')
a('                != rules::SPYF_IMPRISONED_SILENT ||')
a('            rules::spyFailureResult(81)')
a('                != rules::SPYF_CAUGHT_TORTURED ||')
a('            rules::spyFailureResult(95)')
a('                != rules::SPYF_CAUGHT_TORTURED ||')
a('            rules::spyFailureResult(96)')
a('                != rules::SPYF_KILLED_OR_TURNED ||')
a('            rules::spyFailureResult(100)')
a('                != rules::SPYF_KILLED_OR_TURNED) ++bad;')
a('        // the failure-score modifiers: difficult +10,')
a('        // extraordinary -5, discovered +25')
a('        if (rules::spyFailureScoreAdj(')
a('                rules::SPY_SIMPLE, false) != 0 ||')
a('            rules::spyFailureScoreAdj(')
a('                rules::SPY_DIFFICULT, false) != 10 ||')
a('            rules::spyFailureScoreAdj(')
a('                rules::SPY_EXTRAORDINARY, false) != -5 ||')
a('            rules::spyFailureScoreAdj(')
a('                rules::SPY_DIFFICULT, true) != 35) ++bad;')
a('        // the 36-60 band: 90 percent further failure')
a('        if (rules::spyCompromisedFailChance() != 90) ++bad;')
a('        // the torture outcomes: 1-2 dead, 3-4 revealed,')
a('        // 5-6 turncoat')
a('        if (rules::spyTortureOutcome(1) != rules::SPYT_DEAD ||')
a('            rules::spyTortureOutcome(2) != rules::SPYT_DEAD ||')
a('            rules::spyTortureOutcome(3)')
a('                != rules::SPYT_REVEALED ||')
a('            rules::spyTortureOutcome(4)')
a('                != rules::SPYT_REVEALED ||')
a('            rules::spyTortureOutcome(5)')
a('                != rules::SPYT_TURNCOAT ||')
a('            rules::spyTortureOutcome(6)')
a('                != rules::SPYT_TURNCOAT) ++bad;')
a('        // the fanatical rule: never a double agent;')
a('        // any dice total over 60 is suicide')
a('        if (!rules::spyFanaticalNeverDoubleAgent()) ++bad;')
a('        if (rules::spyFanaticalSuicided(60)) ++bad;')
a('        if (!rules::spyFanaticalSuicided(61)) ++bad;')
a('        printf("R205 spying tables audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

anchor = ('        printf("R204 item saving throw matrix audit: bad %d'
          + BS + 'n", bad);'
          + NL + '        if (bad) return 1;'
          + NL + '    }')

patch('regtest.cpp',
      'R205 spying tables audit',
      anchor,
      anchor + NL + NL.join(aud))

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the round-log entry (R202 convention)
# ---------------------------------------------------------------------------

entry = (
    'R205 landed the spying tables (DMG pp.19-20,'
    + NL + 'the SPYING section after the assassin guild'
    + NL + 'tables) - the lane rules/assassinate.h'
    + NL + 'named and deferred in R164. rules/spying.h'
    + NL + '(the grenade.h pattern): the ASSASSIN SPYING'
    + NL + 'TABLE (spy level 1-17 x simple/difficult/'
    + NL + 'extraordinary, all 51 cells), the mission'
    + NL + 'days (1-8 / 5-40 / as required), the chance'
    + NL + 'of discovery (cumulative 1 percent per day'
    + NL + 'capped at 10, minus the spy level, floor 1'
    + NL + 'percent) with the four precaution tiers'
    + NL + '(none flat 1 percent per week; minimal the'
    + NL + 'modified percent per week; moderate twice'
    + NL + 'per week; strong doubled twice per week; a'
    + NL + 'leading spy reads none) and the tenfold'
    + NL + '20-50-day post-capture window; the SPY'
    + NL + 'FAILURE TABLE (the five bands, doubling as'
    + NL + 'the discovery table) with the modifiers'
    + NL + '(difficult +10, extraordinary -5,'
    + NL + 'discovered +25); the torture outcomes (1-2'
    + NL + 'dead, 3-4 revealed, 5-6 turncoat); the'
    + NL + 'fanatical rule (never a double agent, over'
    + NL + '60 suicide); the hired-spy 8th-level cap.'
    + NL + 'New R205 battery audit; census 121. Next:'
    + NL + 'the DMG-only sweep continues.')

log_old = ('d20 + adj >= cell. New R204 battery audit; census'
           + NL + '120. Next: the DMG-only sweep continues.'
           + NL + NL + 'Categories:')

log_new = ('d20 + adj >= cell. New R204 battery audit; census'
           + NL + '120. Next: the DMG-only sweep continues.'
           + NL + NL + entry + NL + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R205 landed the spying tables',
      log_old,
      log_new)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R205 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R205 note: 4 patches; the spying tables pinned - the success')
print('table, the discovery machinery, the failure bands, the torture')
print('and fanatical rules; the log entry rides this commit; census 121.')
print('commit: R205: the spying tables pinned - DMG pp.19-20, the success')
print('table, discovery and failure machinery (census 121)')

