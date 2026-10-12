# R368: the UA Cavaliers Table I pin
# round (p. 15): the full table - the
# two 0-level rows (Horseman 1d4+1,
# Lancer 2d4+1), the 1st-level footnote
# (the track 3d4+1 vs the direct 1d10+3),
# the printed XP bands (the level-11 band
# decoded from its neighbors), the
# cumulative dice column (10+3 and 10+6
# at 11th and 12th), the level titles
# (the 11th/12th cells newly readable,
# the level-5 grid Knight flagged, the
# level-6 cell a hole), the 3 hp per
# level past 10th and the 300,000 xp
# per level past 12th; the item flips
# CLOSED; the R328 seam cross-checks.
# Pin-era pattern (R322).
# Idempotent; run twice.
import io
import os


NL = '\n'
applied = []
already = []


def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)


# ---- (a) the seed: the R367 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R367 landed 2026-10-12: commit',
    '  6047766, census 294, the UA',
    '  campaign social class and birth',
    '  pin round (rules/uasocialclass.h',
    '  and rules/uabirth.h): the',
    '  nine-band Social Class Table',
    '  with the 68-entry occupation',
    '  rosters, the starting-money',
    '  note with the cavalier/paladin',
    '  exception, the non-human',
    '  placements and the',
    '  one-rank-below profession rule;',
    '  the 13-row Birth Table, the',
    '  marital status split with the',
    '  one-class-below-the-father read',
    '  and the racial modifiers; both',
    '  items CLOSED; the R336 seam',
    '  cross-checks the cavalier',
    '  stations; GREEN on the first',
    '  run.',
])
s = rd(SD)
if 'R367 landed 2026-10-12' in s:
    already.append('seed: the R367 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R367 record')
s = rd(SD)
assert s.count(
    'R367 landed 2026-10-12'
) == 1, 'a entry'
assert s.count(
    'R366 landed 2026-10-12'
) == 1, 'a R366 kept'
assert s.count(
    'R365 landed 2026-10-12'
) == 1, 'a R365 kept'
assert s.count(
    'R364 landed 2026-10-11'
) == 1, 'a R364 kept'
assert s.count(
    'R363 landed 2026-10-11'
) == 1, 'a R363 kept'
assert s.count(
    'R362 landed 2026-10-11'
) == 1, 'a R362 kept'
assert s.count(
    'R361 landed 2026-10-11'
) == 1, 'a R361 kept'
assert s.count(
    'R360 landed 2026-10-11'
) == 1, 'a R360 kept'
assert s.count(
    'R359 landed 2026-10-11'
) == 1, 'a R359 kept'
assert s.count(
    'R358 landed 2026-10-11'
) == 1, 'a R358 kept'
assert s.count(
    'R357 landed 2026-10-11'
) == 1, 'a R357 kept'
assert s.count(
    'R356 landed 2026-10-11'
) == 1, 'a R356 kept'
assert s.count(
    'R355 landed 2026-10-11'
) == 1, 'a R355 kept'
assert s.count(
    'R354 landed 2026-10-11'
) == 1, 'a R354 kept'
assert s.count(
    'R352 landed 2026-10-11'
) == 1, 'a R352 kept'
assert s.count(
    'R351 landed 2026-10-11'
) == 1, 'a R351 kept'
assert s.count(
    'R350 landed 2026-10-11'
) == 1, 'a R350 kept'
assert s.count(
    'R349 landed 2026-10-11'
) == 1, 'a R349 kept'
assert s.count(
    'R347 landed 2026-10-11'
) == 1, 'a R347 kept'
assert s.count(
    'R343 landed 2026-10-11'
) == 1, 'a R343 kept'
assert s.count(
    '## Knowledge maintenance'
) == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'


# ---- (b) NEW rules/uacavtable.h ----
P = 'rules/uacavtable.h'
if os.path.exists(P) and 'R368' in rd(P):
    already.append('uacavtable.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uacavtable.h
// The UA CAVALIERS TABLE I (p. 15 print) pins,
// R368: the full table - the two 0-level track rows
// (Horseman 1d4+1, Lancer 2d4+1), the 1st-level
// footnote (1d10+3 vs the track 3d4+1), the XP
// bands, the level titles, the cumulative dice
// column (2-10 dice at levels 2-10, 10+3 and 10+6
// at 11th and 12th), the 3 hp per level after the
// 10th and the 300,000 xp per level past the 12th.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. Cross-checks the landed R328 seam
// (rules/cavalier.h - the XP ladder and the known
// title cells) and the R327 d10 hit die.
//
// JUDGMENTs (the decode method):
//   - the level-5 title cell prints Knight in the
//     grid; the retainer prose elsewhere reads
//     becoming a Knight at 6th - the R328 conflict.
//     The grid print wins (the standing print-wins
//     convention), the divergence flagged pending
//     the PDF.
//   - the level-6 title cell is OCR-lost in the
//     extract - a hole, no pin, pending the PDF.
//   - the level-11 and level-12 title cells print
//     cleanly ("Cavalier, 11th", "Cavalier, 12th") -
//     two of the four R328 holes close here.
//   - the level-11 XP band cell garbles; the band is
//     decoded from its neighbors (the 10th band ends
//     600,000; the 12th band prints 900,001) - the
//     forced decode, corroborated by the R328 ladder.
//   - the table header cell prints "12-Sided Dice"
//     against the R327 cavalier d10 - a suspected
//     column scramble; not pinned, flagged pending
//     the PDF.
// ===========================================================================

#pragma once

namespace rules {

// ---- the 0-level track rows ----
// Horseman: -1,500 to -501 xp, 1d4+1 hp.
inline int uacavtHorsemanXpLow()
    { return -1500; }

inline int uacavtHorsemanXpHigh()
    { return -501; }

inline int uacavtHorsemanHpDice()
    { return 1; }

inline int uacavtHorsemanHpDiceSides()
    { return 4; }

inline int uacavtHorsemanHpBonus()
    { return 1; }

// Lancer: -500 to -1 xp, 2d4+1 hp.
inline int uacavtLancerXpLow()
    { return -500; }

inline int uacavtLancerXpHigh()
    { return -1; }

inline int uacavtLancerHpDice()
    { return 2; }

inline int uacavtLancerHpDiceSides()
    { return 4; }

inline int uacavtLancerHpBonus()
    { return 1; }

// ---- the 1st-level footnote ----
// If qualification required the two 0-level grades,
// the 1st-level hit dice are 3d4+1; in all other
// cases 1d10+3 applies (the Upper Class direct
// entry).
inline bool uacavtFirstLevelTrackFootnote()
    { return true; }

inline int uacavtTrackFirstDice()
    { return 3; }

inline int uacavtTrackFirstSides()
    { return 4; }

inline int uacavtTrackFirstBonus()
    { return 1; }

inline int uacavtDirectFirstDice()
    { return 1; }

inline int uacavtDirectFirstSides()
    { return 10; }

inline int uacavtDirectFirstBonus()
    { return 3; }

// ---- the XP bands, levels 1-12 ----
// The printed band bounds; level 12 is unbounded
// (300,000 xp per level past the 12th). The R328
// attain ladder reads attain(level) = high(level-1).
inline int uacavtLevelXpLow(int level) {
    static const int k[12] = {
        0, 2501, 5001, 10001, 18501, 37001,
        85001, 140001, 220001, 300001, 600001,
        900001,
    };
    if (level < 1) level = 1;
    if (level > 12) level = 12;
    return k[level - 1];
}

inline int uacavtLevelXpHigh(int level) {
    static const int k[12] = {
        2500, 5000, 10000, 18500, 37000,
        85000, 140000, 220000, 300000, 600000,
        900000, 0,
    };
    if (level < 1) level = 1;
    if (level > 12) level = 12;
    return k[level - 1];
}

// The 12th band is unbounded (300,000 xp per level
// past the 12th); the level-11 band garbles and is
// decoded from its neighbors.
inline bool uacavtLevel12XpUnbounded()
    { return true; }

inline bool uacavtLevel11BandDecoded()
    { return true; }

// ---- the cumulative dice column ----
// Levels 2-10: the dice count equals the level;
// the 11th and 12th rows print 10+3 and 10+6 (the
// 3 hp per level after the 10th).
inline int uacavtLevelDiceCount(int level) {
    if (level < 2) return 1;
    if (level > 10) return 10;
    return level;
}

inline int uacavtLevel11FlatHp()
    { return 3; }

inline int uacavtLevel12FlatHp()
    { return 6; }

inline int uacavtHpPerLevelPast10()
    { return 3; }

inline bool uacavtDiceColumnCumulative()
    { return true; }

// The header cell prints 12-sided against the
// landed R327 d10 - a suspected scramble, no pin.
inline bool uacavtTwelveSidedHeaderSuspect()
    { return true; }

// ---- the level titles ----
// 0 = Horseman, -1 = Lancer, 1-12 the levels,
// 13+ Cavalier Commander. Level 6 is the lost
// cell (the empty string); level 5 is the grid
// print (the prose conflict flagged below).
inline const char* uacavtTitle(int level) {
    switch (level) {
        case 0: return "Horseman";
        case -1: return "Lancer";
        case 1: return "Armiger";
        case 2: return "Scutifer";
        case 3: return "Esquire";
        case 4: return "Knight Errant";
        case 5: return "Knight";
        case 7: return "Grand Knight";
        case 8: return "Banneret";
        case 9: return "Chevalier";
        case 10: return "Cavalier";
        case 11: return "Cavalier, 11th";
        case 12: return "Cavalier, 12th";
        default:
            if (level >= 13)
                return "Cavalier Commander";
            return "";
    }
}

inline bool uacavtLevel6TitleCellLost()
    { return true; }

inline bool uacavtLevel5GridVsProseConflict()
    { return true; }

// ---- the past-12th reads ----
inline int uacavtXpPerLevelPast12()
    { return 300000; }

inline int uacavtCommanderLevel()
    { return 13; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uacavtable.h: the pins')
s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 32, 'b inline count'
assert s.count('R368') == 1, 'b round tag'
assert s.count('uacavtHorsemanXpLow') >= 1, 'b fn'
assert 'uasoc' not in s, 'b no uasoc ref'
assert 'uabirth' not in s, 'b no uabirth ref'
assert 'uail' not in s, 'b no uail ref'
assert 'uam' not in s, 'b no uam ref'
assert 'uasc' not in s, 'b no uasc ref'
assert 'uasp' not in s, 'b no uasp ref'
assert 'uauw' not in s, 'b no uauw ref'
assert 'uadk' not in s, 'b no uadk ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (c) the gap: the table close ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if '- [x] **Cavaliers Table I**' in s:
    already.append('gap report: the table close')
else:
    OLD = NL.join([
        '- [ ] **Cavaliers Table I** (p. 15) -',
        '      the XP ladder, the level titles',
        '      (Horseman to Cavalier Commander),',
        '      the 3 hp per level after 10th, the',
        '      300000 xp per level past 12th;',
        '      reads clean.',
    ])
    assert s.count(OLD) == 1, 'c old'
    NEW = NL.join([
        '- [x] **Cavaliers Table I** (p. 15) -',
        '      the XP ladder, the level titles',
        '      (Horseman to Cavalier Commander),',
        '      the 3 hp per level after 10th, the',
        '      300000 xp per level past 12th;',
        '      reads clean.',
        '      - CLOSED R368: the pin round',
        '        (rules/uacavtable.h) - the two',
        '        0-level rows, the 1st-level',
        '        footnote, the printed XP bands',
        '        (the level-11 band decoded from',
        '        its neighbors), the cumulative',
        '        dice column, the titles: the',
        '        11th and 12th cells newly',
        '        readable (two of the four R328',
        '        holes close), the level-5 grid',
        '        Knight with the prose conflict',
        '        flagged, the 3 hp per level',
        '        past 10th, the 300,000 xp past',
        '        12th; the level-6 title cell',
        '        and the 12-sided header cell',
        '        stay holes pending the PDF;',
        '        the R328 seam cross-checks;',
        '        CLOSED.',
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    wr(GP, s)
    applied.append('gap report: the table close')

# ---- (c) the gap kept asserts ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
assert s.count(
    '- [x] **Cavaliers Table I**'
) == 1, 'c flip'
assert s.count(
    '(rules/uacavtable.h) - the'
) == 1, 'c note'
assert s.count(
    '- [ ] Cavaliers Table I (p. 15).'
) == 1, 'c manifest kept'
assert s.count(
    '- [ ] **Social class and rank**'
) == 0, 'c r367 kept closed'
assert s.count(
    '- [x] **Social class and rank**'
) == 1, 'c r367 kept closed'
assert s.count(
    '- [ ] **Cantrip acquisition, MU**'
) == 1, 'c cantrip kept open'
assert s.count(
    '- [ ] **Illusionist spell acquisition**'
) == 1, 'c acq kept open'
assert s.count(
    '- [ ] **The Armor Class Table**'
) == 1, 'c armor kept open'
assert s.count(
    '### Treasure (pp. 84-106) - THE DECISION'
) == 1, 'c treasure section kept'
assert len(applied) + len(already) == 3, 'c count'


# ---- (d) regtest.cpp: the includes,
# the audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R368 UA Cavaliers Table I pin audit' in s:
    already.append('regtest.cpp: the R368 audit')
else:
    INC_ANCH = ('#include "rules/uabirth.h"  // '
        'R367: the UA circumstances of birth')
    INC_NEW = NL.join([
        '#include "rules/uabirth.h"  // R367: the UA circumstances of birth',
        '#include "rules/uacavtable.h"  // R368: the UA Cavaliers Table I',
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R368: the UA Cavaliers Table I
    // pin audit ----
    // The UA CAVALIERS TABLE I (p. 15): the
    // full table pinned - the two 0-level
    // rows (Horseman 1d4+1 at -1,500 to
    // -501, Lancer 2d4+1 at -500 to -1),
    // the 1st-level footnote (the track
    // 3d4+1 vs the direct 1d10+3), the
    // printed XP bands with the level-11
    // band decoded from its neighbors, the
    // cumulative dice column (the level
    // count at 2nd-10th, 10+3 and 10+6 at
    // 11th and 12th), the level titles (the
    // 11th and 12th cells newly readable -
    // two of the four R328 holes close; the
    // level-5 grid Knight with the prose
    // conflict flagged; the level-6 cell
    // lost, a hole; the 12-sided header cell
    // suspect against the R327 d10), the 3
    // hp per level past 10th, the 300,000
    // xp per level past 12th and Cavalier
    // Commander at 13th+. The R328 seam
    // cross-checks the XP ladder and the
    // known titles. The item flips CLOSED;
    // the census 294 -> 295.
    {
        using namespace rules;
        int bad = 0;
        // ---- the pinned cells ----
            if (uacavtHorsemanXpLow() != -1500) ++bad;
            if (uacavtHorsemanXpHigh() != -501) ++bad;
            if (uacavtHorsemanHpDice() != 1) ++bad;
            if (uacavtHorsemanHpDiceSides() != 4) ++bad;
            if (uacavtHorsemanHpBonus() != 1) ++bad;
            if (uacavtLancerXpLow() != -500) ++bad;
            if (uacavtLancerXpHigh() != -1) ++bad;
            if (uacavtLancerHpDice() != 2) ++bad;
            if (uacavtLancerHpDiceSides() != 4) ++bad;
            if (uacavtLancerHpBonus() != 1) ++bad;
            if (!uacavtFirstLevelTrackFootnote()) ++bad;
            if (uacavtTrackFirstDice() != 3) ++bad;
            if (uacavtTrackFirstSides() != 4) ++bad;
            if (uacavtTrackFirstBonus() != 1) ++bad;
            if (uacavtDirectFirstDice() != 1) ++bad;
            if (uacavtDirectFirstSides() != 10) ++bad;
            if (uacavtDirectFirstBonus() != 3) ++bad;
            if (!uacavtLevel12XpUnbounded()) ++bad;
            if (!uacavtLevel11BandDecoded()) ++bad;
            if (uacavtLevel11FlatHp() != 3) ++bad;
            if (uacavtLevel12FlatHp() != 6) ++bad;
            if (uacavtHpPerLevelPast10() != 3) ++bad;
            if (!uacavtDiceColumnCumulative()) ++bad;
            if (!uacavtTwelveSidedHeaderSuspect()) ++bad;
            if (!uacavtLevel6TitleCellLost()) ++bad;
            if (!uacavtLevel5GridVsProseConflict()) ++bad;
            if (uacavtXpPerLevelPast12() != 300000) ++bad;
            if (uacavtCommanderLevel() != 13) ++bad;
        // ---- the XP band loops ----
            static const int xl[12] = {0,
                2501, 5001, 10001, 18501,
                37001, 85001, 140001,
                220001, 300001, 600001,
                900001};
            static const int xh[12] = {2500,
                5000, 10000, 18500, 37000,
                85000, 140000, 220000,
                300000, 600000, 900000, 0};
            for (int l = 1; l <= 12; ++l) {
                if (uacavtLevelXpLow(l) != xl[l - 1])
                    ++bad;
                if (uacavtLevelXpHigh(l) != xh[l - 1])
                    ++bad;
                if (l < 12 && xh[l - 1] + 1 != xl[l]) ++bad;
                // the R328 seam:
                // attain(l) = high(l-1)
                int att = cavalierXpToAttain(l);
                if (l == 1) {
                    if (att != 0) ++bad;
                } else if (att != xh[l - 2]) {
                    ++bad;
                }
            }
            if (uacavtHorsemanXpLow() != cavalierHorsemanXp())
                ++bad;
            if (uacavtLancerXpLow() != cavalierLancerXp())
                ++bad;
        // ---- the dice column ----
            for (int l = 2; l <= 10; ++l) {
                if (uacavtLevelDiceCount(l) != l)
                    ++bad;
            }
            if (uacavtLevelDiceCount(11) != 10) ++bad;
            if (uacavtLevelDiceCount(12) != 10) ++bad;
            if (uacavtLevel11FlatHp() != uacavtHpPerLevelPast10())
                ++bad;
            if (uacavtLevel12FlatHp() != 2 * uacavtHpPerLevelPast10())
                ++bad;
            if (uacavtHpPerLevelPast10() != cavalierHpPerLevelPast10())
                ++bad;
        // ---- the titles ----
            static const char* const tn[14] = {
                "Horseman", "Lancer", "Armiger",
                "Scutifer", "Esquire", "Knight Errant",
                "Knight", "", "Grand Knight",
                "Banneret", "Chevalier", "Cavalier",
                "Cavalier, 11th", "Cavalier, 12th"};
            for (int i = 0; i < 14; ++i) {
                int l = (i == 0) ? 0 : (i == 1 ? -1 : i - 2);
                if (strcmp(uacavtTitle(l), tn[i]) != 0)
                    ++bad;
            }
            if (strcmp(uacavtTitle(13),
                    "Cavalier Commander") != 0)
                ++bad;
            if (uacavtCommanderLevel() != cavalierCommanderLevel())
                ++bad;
            if (uacavtXpPerLevelPast12() != cavalierXpPerLevelPast12())
                ++bad;
            // the R328 known-title seam
            for (int l = 1; l <= 10; ++l) {
                if (l == 5 || l == 6) continue;
                if (strcmp(uacavtTitle(l),
                        cavalierTitleKnown(l)) != 0)
                    ++bad;
            }
            // the newly readable 11th and
            // 12th cells (the R328 hole
            // record returns the empty
            // string - no seam check)
            if (uacavtTitle(11)[0] == 0)
                ++bad;
            if (uacavtTitle(12)[0] == 0)
                ++bad;
        printf("R368 UA Cavaliers Table I pin audit: bad %d\n", bad);
        if (bad) return 1;
    }"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R368 audit')
s = rd(RT)
assert s.count(
    'R368 UA Cavaliers Table I pin audit: bad '
) == 1, 'd audit line'
assert s.count(
    'R367 UA social/birth pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R366 UA DM-section spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R365 UA IL 6th/7th and DM pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R364 UA IL 3rd/4th/5th spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R363 UA IL cantrips/1st/2nd pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R362 UA MU 8th/9th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R361 UA MU 7th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R360 UA MU 5th/6th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R359 UA MU 4th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R358 UA MU 3rd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R357 UA MU 2nd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R356 UA MU 1st level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R355 UA druid 7th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R354 UA druid 6th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R353 UA druid 5th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R352 UA druid 3rd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R351 UA druid 2nd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R350 UA druid 1st level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R349 UA cleric 7th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count('audit: bad ') == 295, 'd census 295'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uacavtable.h"'
) == 1, 'd new include'
for h in ('rules/cavalier.h',
        'rules/classtables.h',
        'rules/uabirth.h',
        'rules/uasocialclass.h',
        'rules/uaspellbooks.h',
        'rules/uaspellcomment.h',
        'rules/uauwspelluse.h',
        'rules/uadarkness.h'):
    assert s.count(
        '#include "' + h + '"'
        ) == 1, 'd kept include'
for i in range(1, 8):
    assert s.count(
        '#include "rules/uailspells%d.h"'
        % i) == 1, 'd il include'
for i in range(1, 10):
    assert s.count(
        '#include "rules/uamuspells%d.h"'
        % i) == 1, 'd mu include'
assert len(applied) + len(already) == 4, 'd count'


# ---- the summary ----
print('R368 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R368 note: the UA Cavaliers Table I',)
print('pin round - the 0-level rows, the',)
print('1st-level footnote, the XP bands',)
print('(the level-11 band decoded), the',)
print('cumulative dice column, the titles',)
print('(the 11th/12th cells newly readable,',)
print('the level-5 grid Knight flagged,',)
print('the level-6 cell a hole), the 3 hp',)
print('per level past 10th and the 300,000',)
print('xp past 12th; the R328 seam',)
print('cross-checks; the item flips',)
print('CLOSED; the census 294 -> 295')
print('commit: R368: the UA Cavaliers Table',)
print('I pin round (census 295)',)

