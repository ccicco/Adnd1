#!/usr/bin/env python3
# R180 splice: the qualification and race gates pinned.
#
# rules/subclassgates.h is CREATED: the class-section
# ability minimums, the alignment requirements, the
# XP bonus rules, Race Table I (class limitations) and
# Race Table II (the level caps, parentheses = NPC-only)
# for the six registry subclasses - PHB pp.21-33 and
# the Character Race Tables I and II.
#
# regtest.cpp: the include lands WITH the audit (the
# R179 lesson); a new R180 battery audit walks every
# cell of both race matrices, the minimums, the
# alignment requirements, the bonus rules, the
# footnote-8 gnome illusionist conditional and the
# meets-min / bonus-earned probes.
#
# Both gap reports carry the round.
#
# Patches: 5. Census 97 (one new audit).

import os

BS = chr(92)
NL = chr(10)

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
    assert t.count(old) == 1, 'anchor not unique in ' + path + ': ' + marker
    t = t.replace(old, new)
    assert marker in t, 'marker missing post-patch in ' + path
    wr(path, t)
    applied += 1


def create(path, marker, content):
    # created-file patch; presence of the marker line = already
    global applied, already
    if os.path.exists(path):
        already += 1
        return
    assert marker in content, 'create marker missing'
    wr(path, content)
    applied += 1


# ---------------------------------------------------------------------------
# Patch 1: rules/subclassgates.h CREATED
# ---------------------------------------------------------------------------

hdr = []
a = hdr.append

a('// ============================================================================')
a('// Adnd1 - rules/subclassgates.h')
a('// The qualification and race gates (R180).')
a('//')
a('// The printed gates for the six registry subclasses: the')
a('// class-section ability minimums, the alignment')
a('// requirements, the XP bonus rules, Character Race Table')
a('// I (class limitations by racial stock) and Character Race')
a('// Table II (the level caps) - PHB pp.21-33 and the Race')
a('// Tables I and II.')
a('//')
a('// Conventions:')
a('//   - ability minimum 0 = no requirement.')
a('//   - Race Table I: 1 = player-character eligible,')
a('//     0 = not eligible.')
a('//   - Race Table II: 0 = forbidden, -1 = unlimited,')
a('//     a positive number = the maximum player level, a')
a('//     number at -n (n >= 2) = the printed parenthesized')
a('//     entry: NPC-only, capped at level n (the halfling')
a('//     druid prints (6)).')
a('//')
a('// JUDGMENTs:')
a('//   - the assassin class text prints NO experience bonus')
a('//     (assassins do not gain any experience bonuses for')
a('//     having high ability scores); pinned as bonus rule')
a('//     none, like the monk and the illusionist.')
a('//   - the gnome illusionist prints cap 7 with footnote 8:')
a('//     intelligence or dexterity under 17 limits to the')
a('//     5th level; both at 17 or better limit to the 6th.')
a('//     The base matrix carries the printed 7; the')
a('//     conditional accessor walks the footnote.')
a('//   - the parenthesized Table II entries mark NPC-only')
a('//     classes; Table I lists the halfling druid as no,')
a('//     and the two tables agree: no player-character')
a('//     halfling druid, NPC-only to level 6.')
a('//   - the Table I alignment letters: (A) any, (LG) lawful')
a('//     good only, (G) good only, (N) neutral only (the')
a('//     druid true neutral), (E) evil only, (L) lawful only.')
a('//')
a('// DATA-DRIVEN (the standing scope): a future class appends')
a('// one row to each matrix and one gate block.')
a('// ============================================================================')
a('')
a('#pragma once')
a('')
a('#include "character.h"')
a('#include "classes.h"')
a('#include "races.h"')
a('#include "subclasses.h"')
a('')
a('#include <cstdint>')
a('')
a('namespace rules {')
a('')
a('// The alignment requirement codes (the Table I letters).')
a('enum SubAlignReq : int {')
a('    SUB_ALIGN_ANY = 0,')
a('    SUB_ALIGN_LG_ONLY,')
a('    SUB_ALIGN_GOOD_ONLY,')
a('    SUB_ALIGN_TRUE_NEUTRAL,')
a('    SUB_ALIGN_EVIL_ONLY,')
a('    SUB_ALIGN_LAWFUL_ONLY')
a('};')
a('')
a('// The printed experience-bonus rules (the class sections).')
a('// The illusionist, assassin and monk print none.')
a('enum SubXpBonusRule : int {')
a('    SUB_XP_BONUS_NONE = 0,')
a('    SUB_XP_BONUS_STR_WIS,      // both over 15 (paladin)')
a('    SUB_XP_BONUS_STR_INT_WIS,  // all three over 15 (ranger)')
a('    SUB_XP_BONUS_WIS_CHA       // both over 15 (druid)')
a('};')
a('')
a('// The ability minimums, in Ability enum order')
a('// (STR INT WIS DEX CON CHA); 0 = no requirement.')
a('//   paladin  12  9 13  0  9 17   (p.22)')
a('//   ranger   13 13 14  0 14  0   (p.24)')
a('//   druid     0  0 12  0  0 15   (p.21)')
a('//   illusionist 0 15 0 16 0  0   (p.26)')
a('//   assassin 12 11  0 12  0  0   (p.31)')
a('//   monk     15  0 15 15 11  0   (p.30)')
a('static const int kGateAbilityMin[SUB_COUNT][6] = {')
a('    { 12,  9, 13,  0,  9, 17 },')
a('    { 13, 13, 14,  0, 14,  0 },')
a('    {  0,  0, 12,  0,  0, 15 },')
a('    {  0, 15,  0, 16,  0,  0 },')
a('    { 12, 11,  0, 12,  0,  0 },')
a('    { 15,  0, 15, 15, 11,  0 }')
a('};')
a('')
a('// Character Race Table I (class limitations), columns in')
a('// CharRace order (human dwarf elf gnome half-elf halfling')
a('// half-orc): 1 = player-character eligible.')
a('static const int kGateRaceAllowed[SUB_COUNT][7] = {')
a('    { 1, 0, 0, 0, 0, 0, 0 },  // paladin')
a('    { 1, 0, 0, 0, 1, 0, 0 },  // ranger')
a('    { 1, 0, 0, 0, 1, 0, 0 },  // druid')
a('    { 1, 0, 0, 1, 0, 0, 0 },  // illusionist')
a('    { 1, 1, 1, 1, 1, 0, 1 },  // assassin')
a('    { 1, 0, 0, 0, 0, 0, 0 }   // monk')
a('};')
a('')
a('// Character Race Table II (level caps), same column order.')
a('// 0 = forbidden; -1 = unlimited; positive = the printed')
a('// player cap; negative n (>= 2) = NPC-only cap n.')
a('static const int kGateRaceCap[SUB_COUNT][7] = {')
a('    { -1,  0,  0,  0,  0,  0,  0 },  // paladin')
a('    { -1,  0,  0,  0,  8,  0,  0 },  // ranger')
a('    { -1,  0,  0,  0, -1, -6,  0 },  // druid (halfling NPC-only 6)')
a('    { -1,  0,  0,  7,  0,  0,  0 },  // illusionist (footnote 8)')
a('    { -1,  9, 10,  8, 11,  0, -1 },  // assassin')
a('    { -1,  0,  0,  0,  0,  0,  0 }   // monk')
a('};')
a('')
a('// The Table I alignment letters and the printed bonus rules.')
a('static const int kGateAlignReq[SUB_COUNT] = {')
a('    SUB_ALIGN_LG_ONLY,        // paladin')
a('    SUB_ALIGN_GOOD_ONLY,      // ranger')
a('    SUB_ALIGN_TRUE_NEUTRAL,   // druid')
a('    SUB_ALIGN_ANY,            // illusionist')
a('    SUB_ALIGN_EVIL_ONLY,     // assassin')
a('    SUB_ALIGN_LAWFUL_ONLY     // monk')
a('};')
a('')
a('static const int kGateXpBonus[SUB_COUNT] = {')
a('    SUB_XP_BONUS_STR_WIS,     // paladin: strength and wisdom over 15')
a('    SUB_XP_BONUS_STR_INT_WIS, // ranger: all three over 15')
a('    SUB_XP_BONUS_WIS_CHA,      // druid: wisdom and charisma over 15')
a('    SUB_XP_BONUS_NONE,        // illusionist prints none')
a('    SUB_XP_BONUS_NONE,        // assassin prints none')
a('    SUB_XP_BONUS_NONE         // monk: never gains bonuses')
a('};')
a('')
a('// ---- accessors (indices clamped; unknown abilities score 0) ----')
a('')
a('inline int subclassAbilityMin(int sub, Ability ab) {')
a('    if (sub < 0) sub = 0;')
a('    if (sub >= SUB_COUNT) sub = SUB_COUNT - 1;')
a('    if ((int)ab < 0 || (int)ab >= ABILITY_COUNT) return 0;')
a('    return kGateAbilityMin[sub][(int)ab];')
a('}')
a('')
a('// True when every printed minimum is met.')
a('inline bool subclassMeetsAbilityMin(int sub, const AbilityScores& s) {')
a('    for (int ab = 0; ab < (int)ABILITY_COUNT; ++ab)')
a('        if (s.get((Ability)ab)')
a('            < subclassAbilityMin(sub, (Ability)ab))')
a('            return false;')
a('    return true;')
a('}')
a('')
a('// Table I: 1 = player-character eligible.')
a('inline int subclassRaceAllowed(int sub, CharRace r) {')
a('    if (sub < 0) sub = 0;')
a('    if (sub >= SUB_COUNT) sub = SUB_COUNT - 1;')
a('    if ((int)r < 0 || (int)r >= RACE_CHAR_COUNT) return 0;')
a('    return kGateRaceAllowed[sub][(int)r];')
a('}')
a('')
a('// Table II: 0 = forbidden; -1 = unlimited; positive =')
a('// the printed player cap; negative n (>= 2) = NPC-only,')
a('// cap level n.')
a('inline int subclassRaceCap(int sub, CharRace r) {')
a('    if (sub < 0) sub = 0;')
a('    if (sub >= SUB_COUNT) sub = SUB_COUNT - 1;')
a('    if ((int)r < 0 || (int)r >= RACE_CHAR_COUNT) return 0;')
a('    return kGateRaceCap[sub][(int)r];')
a('}')
a('')
a('// True when the Table II entry is a parenthesized')
a('// (NPC-only) cap.')
a('inline bool subclassCapIsNpcOnly(int sub, CharRace r) {')
a('    return subclassRaceCap(sub, r) <= -2;')
a('}')
a('')
a('// Footnote 8 (Race Table II): the gnome illusionist.')
a('// Intelligence or dexterity under 17 limits to the 5th')
a('// level; both at 17 or better limit to the 6th. The')
a('// printed base entry 7 never survives the footnote -')
a('// every rolled gnome takes a 5 or a 6 here (recorded')
a('// as the JUDGMENT; the matrix keeps the printed 7).')
a('inline int illusionistGnomeCap(int intScore, int dexScore) {')
a('    if (intScore < 17 || dexScore < 17) return 5;')
a('    return 6;')
a('}')
a('')
a('// The Table I alignment letters.')
a('inline int subclassAlignmentReq(int sub) {')
a('    if (sub < 0) sub = 0;')
a('    if (sub >= SUB_COUNT) sub = SUB_COUNT - 1;')
a('    return kGateAlignReq[sub];')
a('}')
a('')
a('// The printed bonus rule code.')
a('inline int subclassXpBonusRule(int sub) {')
a('    if (sub < 0) sub = 0;')
a('    if (sub >= SUB_COUNT) sub = SUB_COUNT - 1;')
a('    return kGateXpBonus[sub];')
a('}')
a('')
a('// True when the printed bonus is earned for the scores.')
a('inline bool subclassXpBonusEarned(int sub, const AbilityScores& s) {')
a('    switch (subclassXpBonusRule(sub)) {')
a('    case SUB_XP_BONUS_STR_WIS:')
a('        return s.get(ABILITY_STR) > 15')
a('            && s.get(ABILITY_WIS) > 15;')
a('    case SUB_XP_BONUS_STR_INT_WIS:')
a('        return s.get(ABILITY_STR) > 15')
a('            && s.get(ABILITY_INT) > 15')
a('            && s.get(ABILITY_WIS) > 15;')
a('    case SUB_XP_BONUS_WIS_CHA:')
a('        return s.get(ABILITY_WIS) > 15')
a('            && s.get(ABILITY_CHA) > 15;')
a('    default:')
a('        return false;')
a('    }')
a('}')
a('')
a('} // namespace rules')

create('rules/subclassgates.h',
       'The qualification and race gates (R180)',
       NL.join(hdr) + NL)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include (the R179 lesson: with the audit)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
       'rules/subclassgates.h',
       '#include "rules/subclasses.h"  // R179: the subclass registry',
       '#include "rules/subclasses.h"  // R179: the subclass registry'
       + NL + '#include "rules/subclassgates.h"  // R180: the qualification and race gates')

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R180 battery audit (census 97)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R180: the qualification and race gates audit ----')
a('    // The class-section ability minimums, the Table I')
a('    // alignment letters, the printed XP bonus rules,')
a('    // Character Race Tables I and II cell by cell, the')
a('    // footnote-8 gnome illusionist conditional, and the')
a('    // meets-min / bonus-earned probes.')
a('    {')
a('        int bad = 0;')
a('        // the ability minimums, in Ability enum order')
a('        const int kGMin[6][6] = {')
a('            { 12,  9, 13,  0,  9, 17 },')
a('            { 13, 13, 14,  0, 14,  0 },')
a('            {  0,  0, 12,  0,  0, 15 },')
a('            {  0, 15,  0, 16,  0,  0 },')
a('            { 12, 11,  0, 12,  0,  0 },')
a('            { 15,  0, 15, 15, 11,  0 }')
a('        };')
a('        // Table I, CharRace column order')
a('        const int kGAllowed[6][7] = {')
a('            { 1, 0, 0, 0, 0, 0, 0 },')
a('            { 1, 0, 0, 0, 1, 0, 0 },')
a('            { 1, 0, 0, 0, 1, 0, 0 },')
a('            { 1, 0, 0, 1, 0, 0, 0 },')
a('            { 1, 1, 1, 1, 1, 0, 1 },')
a('            { 1, 0, 0, 0, 0, 0, 0 }')
a('        };')
a('        // Table II: 0 forbidden, -1 unlimited, -n NPC-only')
a('        const int kGCap[6][7] = {')
a('            { -1,  0,  0,  0,  0,  0,  0 },')
a('            { -1,  0,  0,  0,  8,  0,  0 },')
a('            { -1,  0,  0,  0, -1, -6,  0 },')
a('            { -1,  0,  0,  7,  0,  0,  0 },')
a('            { -1,  9, 10,  8, 11,  0, -1 },')
a('            { -1,  0,  0,  0,  0,  0,  0 }')
a('        };')
a('        // the alignment requirements and bonus rules')
a('        const int kGAlign[6] = { 1, 2, 3, 0, 4, 5 };')
a('        const int kGBonus[6] = { 1, 2, 3, 0, 0, 0 };')
a('        for (int i = 0; i < 6; ++i) {')
a('            for (int ab = 0; ab < 6; ++ab)')
a('                if (rules::subclassAbilityMin(')
a('                        i, (rules::Ability)ab)')
a('                    != kGMin[i][ab]) ++bad;')
a('            for (int r = 0; r < 7; ++r) {')
a('                if (rules::subclassRaceAllowed(')
a('                        i, (rules::CharRace)r)')
a('                    != kGAllowed[i][r]) ++bad;')
a('                if (rules::subclassRaceCap(')
a('                        i, (rules::CharRace)r)')
a('                    != kGCap[i][r]) ++bad;')
a('            }')
a('            if (rules::subclassAlignmentReq(i)')
a('                != kGAlign[i]) ++bad;')
a('            if (rules::subclassXpBonusRule(i)')
a('                != kGBonus[i]) ++bad;')
a('        }')
a('        // the NPC-only convention: the halfling druid (6)')
a('        if (!rules::subclassCapIsNpcOnly(')
a('                2, rules::RACE_HALFLING)) ++bad;')
a('        if (rules::subclassCapIsNpcOnly(')
a('                1, rules::RACE_HALFELF)) ++bad;')
a('        if (rules::subclassCapIsNpcOnly(')
a('                0, rules::RACE_HUMAN)) ++bad;')
a('        // the footnote-8 conditional (gnome illusionist)')
a('        if (rules::illusionistGnomeCap(16, 18) != 5) ++bad;')
a('        if (rules::illusionistGnomeCap(18, 16) != 5) ++bad;')
a('        if (rules::illusionistGnomeCap(17, 16) != 5) ++bad;')
a('        if (rules::illusionistGnomeCap(17, 17) != 6) ++bad;')
a('        if (rules::illusionistGnomeCap(18, 18) != 6) ++bad;')
a('        // meets-min probes: at the minimums passes,')
a('        // one point short fails, one over passes')
a('        rules::AbilityScores s;')
a('        s.set(rules::ABILITY_STR, 12);')
a('        s.set(rules::ABILITY_INT, 9);')
a('        s.set(rules::ABILITY_WIS, 13);')
a('        s.set(rules::ABILITY_DEX, 3);')
a('        s.set(rules::ABILITY_CON, 9);')
a('        s.set(rules::ABILITY_CHA, 17);')
a('        if (!rules::subclassMeetsAbilityMin(0, s)) ++bad;')
a('        s.set(rules::ABILITY_CHA, 16);')
a('        if (rules::subclassMeetsAbilityMin(0, s)) ++bad;')
a('        s.set(rules::ABILITY_STR, 15);')
a('        s.set(rules::ABILITY_INT, 15);')
a('        s.set(rules::ABILITY_WIS, 15);')
a('        s.set(rules::ABILITY_DEX, 15);')
a('        s.set(rules::ABILITY_CON, 11);')
a('        s.set(rules::ABILITY_CHA, 3);')
a('        if (!rules::subclassMeetsAbilityMin(5, s)) ++bad;')
a('        s.set(rules::ABILITY_CON, 10);')
a('        if (rules::subclassMeetsAbilityMin(5, s)) ++bad;')
a('        s.set(rules::ABILITY_CON, 12);')
a('        // bonus-earned probes: all over 15 earns the')
a('        // printed bonus; at 15 nothing earns')
a('        rules::AbilityScores b;')
a('        b.set(rules::ABILITY_STR, 16);')
a('        b.set(rules::ABILITY_INT, 16);')
a('        b.set(rules::ABILITY_WIS, 16);')
a('        b.set(rules::ABILITY_DEX, 10);')
a('        b.set(rules::ABILITY_CON, 10);')
a('        b.set(rules::ABILITY_CHA, 16);')
a('        if (!rules::subclassXpBonusEarned(0, b)) ++bad;')
a('        if (!rules::subclassXpBonusEarned(1, b)) ++bad;')
a('        if (!rules::subclassXpBonusEarned(2, b)) ++bad;')
a('        if (rules::subclassXpBonusEarned(3, b)) ++bad;')
a('        if (rules::subclassXpBonusEarned(4, b)) ++bad;')
a('        if (rules::subclassXpBonusEarned(5, b)) ++bad;')
a('        rules::AbilityScores n;')
a('        n.set(rules::ABILITY_STR, 15);')
a('        n.set(rules::ABILITY_INT, 15);')
a('        n.set(rules::ABILITY_WIS, 15);')
a('        n.set(rules::ABILITY_DEX, 10);')
a('        n.set(rules::ABILITY_CON, 10);')
a('        n.set(rules::ABILITY_CHA, 15);')
a('        if (rules::subclassXpBonusEarned(0, n)) ++bad;')
a('        if (rules::subclassXpBonusEarned(1, n)) ++bad;')
a('        if (rules::subclassXpBonusEarned(2, n)) ++bad;')
a('        if (rules::subclassXpBonusEarned(3, n)) ++bad;')
a('        if (rules::subclassXpBonusEarned(4, n)) ++bad;')
a('        if (rules::subclassXpBonusEarned(5, n)) ++bad;')
a('        printf("R180 qualification and race gates audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

patch('regtest.cpp',
      'R180 qualification and race gates audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 4: tools/phb_gap_report.md - the R180 box flipped
# ---------------------------------------------------------------------------

patch('tools/phb_gap_report.md',
      'R180 the qualification and race gates - PINNED',
      '- R180 qualification and race gates - the ability'
      + NL + '      minimums and the alignment requirements;'
      + NL + '      Race Table I class limitations and the Race'
      + NL + '      Table II level caps for the new classes.',
      '- [x] R180 the qualification and race gates - PINNED:'
      + NL + '      rules/subclassgates.h CREATED: the ability'
      + NL + '      minimums (paladin 12/9/13/-/9/17, ranger'
      + NL + '      13/13/14/-/14/-, druid WIS 12 CHA 15,'
      + NL + '      illusionist INT 15 DEX 16, assassin'
      + NL + '      12/11/-/12/-/-, monk 15/-/15/15/11/-), the'
      + NL + '      Table I alignment letters (LG paladin, G'
      + NL + '      ranger, N druid, A illusionist, E assassin,'
      + NL + '      L monk), the XP bonus rules (paladin STR and'
      + NL + '      WIS over 15, ranger STR INT WIS, druid WIS'
      + NL + '      CHA; the illusionist, assassin and monk'
      + NL + '      print none - the assassin class text is'
      + NL + '      explicit), Race Table I cell by cell (the'
      + NL + '      paladin and monk human only, the ranger and'
      + NL + '      druid half-elf and human, the illusionist'
      + NL + '      gnome and human, the assassin all but'
      + NL + '      halfling), and Race Table II with the'
      + NL + '      parentheses-equal-NPC-only convention (the'
      + NL + '      halfling druid (6); ranger half-elf 8;'
      + NL + '      illusionist gnome 7 with the footnote-8'
      + NL + '      conditional accessor; assassin 9/10/8/11'
      + NL + '      dwarf/elf/gnome/half-elf, unlimited'
      + NL + '      half-orc and human). The R180 battery audit'
      + NL + '      walks every cell, the footnote and the'
      + NL + '      meets-min and bonus probes. Census 97.')

# ---------------------------------------------------------------------------
# Patch 5: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R180 landed the qualification',
      'Census stays 96 (no new audit).',
      'Census stays 96 (no new audit).'
      + NL + 'R180 landed the qualification and race gates:'
      + NL + 'rules/subclassgates.h CREATED (the ability'
      + NL + 'minimums, the Table I alignment letters, the XP'
      + NL + 'bonus rules, Race Table I and Race Table II cell'
      + NL + 'by cell, the halfling-druid NPC-only (6), the'
      + NL + 'footnote-8 gnome illusionist conditional). The'
      + NL + 'include landed with the audit (the R179 lesson'
      + NL + 'held). New R180 battery audit; census 97. The'
      + NL + 'assassin XP bonus pinned NONE - the class text'
      + NL + 'prints no bonus despite the thief-group pattern.'
      + NL + 'Next: R181 attacks per melee round.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 5, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R180 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R180 note: 5 patches; census 97 (one new audit);')
print('real gate: md5sum rules/subclassgates.h')
print('commit: R180: the qualification and race gates pinned -')
print('the subclass entry gates (census 97)')

