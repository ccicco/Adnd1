# tools/r164_splice.py - R164, 5 patches: the
# assassination table (DMG p.75) - the odds table
# proper. A new header-only layer, rules/assassinate.h
# (the grenade.h pattern: the caller rolls the
# percentile dice and owns the plan-vs-precautions
# adjustments). The p.19-20 spying rules stay as
# wired (the spy).
#
# (1) rules/assassinate.h: the p.75 print - the 15-row
#     by 10-column table (assassin level 1-15 against
#     victim level band 0-1 through 18+), a printed
#     dash read as -1 (no chance at all); JUDGMENT:
#     an attacker below level 1 reads row 1 and above
#     15 reads row 15. The footnote: the table also
#     governs attacks on helpless opponents by ANY
#     character class. The percentages are near
#     optimum conditions - the caller adjusts up for
#     perfect conditions (absolute trust, asleep and
#     unguarded, very drunk and unguarded) and down
#     for a wary, prepared or guarded victim; weapon
#     damage always occurs and may kill even when
#     the assassination roll fails.
#     (2) the regtest include. (3) the R164 audit:
#     every printed cell pinned - CENSUS 82.
#     (4)-(5) the gap report.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R164: the assassination table pinned - the
# p.75 odds matrix, every cell (census 82)"
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

p1_text = NL.join(['// ====================================================================', '// Adnd1 - rules/assassinate.h', '// R164: the assassination table (DMG p.75) - the', '// odds matrix for assassination attempts.', '//', '// Pure data, header-only (the grenade.h pattern: the', '// caller rolls the percentile dice and owns the', '// plan-vs-precautions adjustments). The p.19-20', '// spying rules stay as wired (the spy).', '//', '// The p.75 print:', '//   - The table: assassin level 1-15 (rows) against', '//     the intended victim level band 0-1, 2-3, 4-5,', '//     6-7, 8-9, 10-11, 12-13, 14-15, 16-17, 18+', '//     (columns). The printed dash reads -1 here: no', '//     chance at all.', '//   - JUDGMENT: an attacker below level 1 reads row', '//     1, and above level 15 reads row 15.', '//   - Footnote: the table also governs attacks on', '//     helpless opponents by ANY character class', '//     (the COMBAT section note on automatically slain', '//     sleeping or held opponents).', '//   - The percentages are for success (instant death)', '//     under NEAR OPTIMUM conditions: adjust slightly', '//     upwards for perfect conditions (absolute', '//     trust, asleep and unguarded, very drunk and', '//     unguarded) and deduct for a wary, prepared or', '//     guarded victim - caller-side.', '//   - Weapon damage always occurs and may kill the', '//     victim even when the assassination roll fails', '//     - caller-side.', '// ====================================================================', '', '#pragma once', '', 'namespace rules {', '', '// The intended victim level band: 0 = levels 0-1,', '// 1 = 2-3, ... 9 = 18 and beyond.', 'inline int assassinationVictimBand(int victimLevel) {', '    if (victimLevel < 0) victimLevel = 0;', '    int band = victimLevel / 2;', '    if (band > 9) band = 9;', '    return band;', '}', '', '// The p.75 matrix: percent chance of success', '// (instant death), -1 where the print shows a dash.', '// Row index = assassin level - 1; column index = the', '// victim band.', 'inline int assassinationChance(', '        int assassinLevel, int victimLevel) {', '    static const int kTable[15][10] = {', '        { 50, 45, 35, 25, 10,  1, -1, -1, -1, -1 },', '        { 55, 50, 40, 30, 15,  2, -1, -1, -1, -1 },', '        { 60, 55, 45, 35, 20,  5, -1, -1, -1, -1 },', '        { 65, 60, 50, 40, 25, 10,  1, -1, -1, -1 },', '        { 70, 65, 55, 45, 30, 15,  5, -1, -1, -1 },', '        { 75, 70, 60, 50, 35, 20, 10,  1, -1, -1 },', '        { 80, 75, 65, 55, 40, 25, 15,  5, -1, -1 },', '        { 85, 80, 70, 60, 45, 30, 20, 10,  2, -1 },', '        { 95, 90, 80, 70, 55, 40, 30, 20,  5, -1 },', '        { 99, 95, 85, 75, 60, 45, 35, 25, 10,  1 },', '        { 100, 99, 90, 80, 65, 50, 40, 30, 15,  5 },', '        { 100, 100, 95, 85, 70, 55, 45, 35, 20, 10 },', '        { 100, 100, 99, 95, 80, 65, 50, 40, 25, 15 },', '        { 100, 100, 100, 99, 90, 75, 60, 50, 35, 25 },', '        { 100, 100, 100, 100, 99, 85, 70, 60, 40, 30 }', '    };', '    if (assassinLevel < 1) assassinLevel = 1;', '    if (assassinLevel > 15) assassinLevel = 15;', '    return kTable[assassinLevel - 1]', '        [assassinationVictimBand(victimLevel)];', '}', '', '// The footnote: the same table governs attacks on', '// helpless opponents by ANY character class, not', '// assassins alone.', 'inline bool assassinationTableCoversHelpless() {', '    return true;', '}', '', '} // namespace rules', ''])
create("rules/assassinate.h", p1_text,
      "assassinate.h: the assassination table layer",
      marker='assassinationChance')
assert len(applied) + len(already) == 1

p2_old = NL.join(['#include "rules/poison.h"  // R163: p.20 the poison table'])
p2_new = NL.join(['#include "rules/poison.h"  // R163: p.20 the poison table', '#include "rules/assassinate.h"  // R164: p.75 the assassination table'])
patch("regtest.cpp", p2_old, p2_new,
      "regtest.cpp: assassinate include",
      marker='rules/assassinate.h"  // R164')
assert len(applied) + len(already) == 2

p3_old = NL.join(['        printf("R163 poison table audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
p3_new = NL.join(['        printf("R163 poison table audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R164: the assassination table audit -------', '    // DMG p.75: the assassins table - every printed', '    // cell pinned, the dashes read as no chance, the', '    // band mapping, the level clamps, and the', '    // helpless-opponents footnote.', '    {', '        static const int kExp[15][10] = {', '            { 50, 45, 35, 25, 10,  1, -1, -1, -1, -1 },', '            { 55, 50, 40, 30, 15,  2, -1, -1, -1, -1 },', '            { 60, 55, 45, 35, 20,  5, -1, -1, -1, -1 },', '            { 65, 60, 50, 40, 25, 10,  1, -1, -1, -1 },', '            { 70, 65, 55, 45, 30, 15,  5, -1, -1, -1 },', '            { 75, 70, 60, 50, 35, 20, 10,  1, -1, -1 },', '            { 80, 75, 65, 55, 40, 25, 15,  5, -1, -1 },', '            { 85, 80, 70, 60, 45, 30, 20, 10,  2, -1 },', '            { 95, 90, 80, 70, 55, 40, 30, 20,  5, -1 },', '            { 99, 95, 85, 75, 60, 45, 35, 25, 10,  1 },', '            { 100, 99, 90, 80, 65, 50, 40, 30, 15,  5 },', '            { 100, 100, 95, 85, 70, 55, 45, 35, 20, 10 },', '            { 100, 100, 99, 95, 80, 65, 50, 40, 25, 15 },', '            { 100, 100, 100, 99, 90, 75, 60, 50, 35, 25 },', '            { 100, 100, 100, 100, 99, 85, 70, 60, 40, 30 }', '        };', '        int bad = 0;', '        // every printed cell, through the band mapping', '        for (int lvl = 1; lvl <= 15; ++lvl) {', '            for (int v = 0; v <= 19; ++v) {', '                int col = (v >= 18) ? 9 : v / 2;', '                if (rules::assassinationChance(lvl, v)', '                        != kExp[lvl - 1][col]) ++bad;', '            }', '        }', '        // the dashes read as -1: no chance at all', '        if (rules::assassinationChance(1, 12) != -1 ||', '            rules::assassinationChance(1, 18) != -1 ||', '            rules::assassinationChance(8, 18) != -1 ||', '            rules::assassinationChance(9, 18) != -1)', '            ++bad;', '        // spot cells off the band edges: a level 18 and', '        // a level 25 victim both read the 18+ column', '        if (rules::assassinationChance(10, 18) != 1 ||', '            rules::assassinationChance(10, 25) != 1 ||', '            rules::assassinationChance(15, 18) != 30)', '            ++bad;', '        // the level clamps: below 1 reads row 1,', '        // above 15 reads row 15', '        if (rules::assassinationChance(0, 0) != 50 ||', '            rules::assassinationChance(-2, 4) != 35 ||', '            rules::assassinationChance(16, 0) != 100 ||', '            rules::assassinationChance(20, 8) != 99)', '            ++bad;', '        // the victim band mapping', '        if (rules::assassinationVictimBand(-5) != 0 ||', '            rules::assassinationVictimBand(0) != 0 ||', '            rules::assassinationVictimBand(1) != 0 ||', '            rules::assassinationVictimBand(2) != 1 ||', '            rules::assassinationVictimBand(3) != 1 ||', '            rules::assassinationVictimBand(17) != 8 ||', '            rules::assassinationVictimBand(18) != 9 ||', '            rules::assassinationVictimBand(99) != 9)', '            ++bad;', '        // the helpless-opponents footnote', '        if (!rules::assassinationTableCoversHelpless())', '            ++bad;', '        printf("R164 assassination table audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
patch("regtest.cpp", p3_old, p3_new,
      "regtest.cpp: R164 audit block",
      marker='R164 assassination table audit')
assert len(applied) + len(already) == 3

p4_old = NL.join(['keeps its per-monster saves). Census 81.', '', 'Categories:'])
p4_new = NL.join(['keeps its per-monster saves). Census 81.', 'R164 PINNED the assassination table (DMG p.75) -', 'rules/assassinate.h: the assassins table for', 'assassinations, 15 rows (assassin level 1-15)', 'against 10 victim bands (0-1 through 18+), every', 'printed cell pinned; the printed dashes read as no', 'chance. JUDGMENT: an attacker below level 1', 'reads row 1, above 15 reads row 15. The footnote:', 'the table also governs attacks on helpless', 'opponents by any character class. The percentages', 'are near optimum conditions - the caller adjusts', 'up for perfect conditions (asleep and unguarded,', 'absolute trust, very drunk and unguarded) and down', 'for a wary, prepared or guarded victim; weapon', 'damage always occurs and may kill even when the', 'assassination roll fails (caller-side). The', 'percentile roll is caller-side (the grenade.h', 'pattern). Census 82.', '', 'Categories:'])
patch("tools/dmg_gap_report.md", p4_old, p4_new,
      "gap report: R164 header note",
      marker='R164 PINNED the assassination table')
assert len(applied) + len(already) == 4

p5_old = NL.join(['- [ ] **The assassination table (p.75)** - the odds table', '      proper; the p.19-20 spying rules are already wired', '      (the spy).'])
p5_new = NL.join(['- [x] **The assassination table (p.75)** - pinned by', '      R164: rules/assassinate.h (the 15x10 odds matrix', '      with the dashes as no chance, the band mapping,', '      the level clamps, the helpless-opponents', '      footnote).'])
patch("tools/dmg_gap_report.md", p5_old, p5_new,
      "gap report: assassination table box closed",
      marker='The assassination table (p.75)** - pinned by')
assert len(applied) + len(already) == 5

# ---- R164 fails/tail ----
if fails:
    print("R164 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print("R164 splice: FAIL - expected 5 patches, counted " + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R164 splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R164 splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R164 note: 5 patches; census 82; commit: R164: the assassination table pinned - the p.75 odds matrix, every cell (census 82)")
