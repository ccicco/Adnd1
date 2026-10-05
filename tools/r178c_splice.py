#!/usr/bin/env python3
# tools/r178c_splice.py - R178c: the DEX and CON
# ability tables repinned - the live ladders fixed.
#
# The PHB founding read (R177) verified divergences
# 1 and 2; this round closes them, the live bugs
# first per the arc ordering rule:
#
#   (a) rules/character.cpp - the DEX Table I
#       reaction/attacking ladder repinned (dex 3
#       reads -3, dex 4 -2, dex 18 +3; the defensive
#       ladder already matched the print and is
#       re-noted). LIVE callers now read the right
#       cells: missile attacks (ai/actor) and the
#       surprise roll (rules/turn).
#   (b) rules/character.cpp - the CON table repinned
#       cell by cell: the system shock column (35
#       through 99), the resurrection survival column
#       (40 through 100 - LIVE, the raise-dead roll),
#       and the CON 6 hit-point cell (-1). The
#       unsourced, unused poison-save column
#       (conPoisonSaveAdj) is RETIRED - not in the 1e
#       print.
#   (c) rules/character.h - the CON block comment
#       updated; the poison-save declaration removed.
#   (d) regtest.cpp - a NEW R178c audit block after
#       the R176 audit: the 16-score DEX reaction and
#       defensive walks, the CON hit-point, system
#       shock and resurrection walks, and the clamps
#       (census 95 - one new audit printf).
#   (e) tools/phb_gap_report.md - divergences 1 and
#       2 flip to CLOSED R178c; the header round note
#       is added.
#   (f) tools/dmg_gap_report.md - the round-note chain
#       gains the R178c note.
#
# Idempotent: safe to run twice; a silent run means
# the paste was truncated - this tail ALWAYS prints.
# An assert follows EVERY patch (the R142 lesson).
# ZERO backslash characters (the C newline is built
# from chr(92)), and no content string embeds a
# literal apostrophe.
# Commit: "R178c: the DEX and CON tables repinned -
# the live ladders fixed (census 95)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BS = chr(92)   # one backslash
NL = chr(10)   # one newline
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

def patch(p, old, new, tag, expect=1, marker=None):
    s = rd(p)
    if marker is None:
        marker = new
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != expect:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected " + str(expect) + ")")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

# ---- (1) the DEX comment + reaction ladder ----
p1_old = NL.join([
    '// DEX (PHB p.11-12)',
    '//   Score  Reaction adj  Defensive adj',
    '//   3      -2           +4   (worse AC number)',
    '//   4      -1           +3',
    '//   5      -1           +2',
    '//   6      0            +1',
    '//   7      0            0',
    '//   8-14   0            0',
    '//   15     0            -1',
    '//   16     +1           -2',
    '//   17     +2           -3',
    '//   18     +2           -4',
    '// ----------------------------------------------------------------------------',
    '',
    'int dexReactionAdj(uint8_t dex) {',
    '    if (dex <= 3)  return -2;',
    '    if (dex <= 5)  return -1;',
    '    if (dex <= 14) return 0;',
    '    if (dex == 15) return 0;',
    '    if (dex == 16) return 1;',
    '    if (dex == 17) return 2;',
    '    return 2;   // 18',
    '}',
])
p1_new = NL.join([
    '// DEX (PHB p.11-12, the reaction ladder pinned R178c)',
    '//   Score  Reaction adj  Defensive adj',
    '//   3      -3           +4   (worse AC number)',
    '//   4      -2           +3',
    '//   5      -1           +2',
    '//   6      0            +1',
    '//   7-14   0            0',
    '//   15     0            -1',
    '//   16     +1           -2',
    '//   17     +2           -3',
    '//   18     +3           -4',
    '// ----------------------------------------------------------------------------',
    '',
    'int dexReactionAdj(uint8_t dex) {',
    '    if (dex <= 3)  return -3;',
    '    if (dex == 4)  return -2;',
    '    if (dex == 5)  return -1;',
    '    if (dex <= 15) return 0;',
    '    if (dex == 16) return 1;',
    '    if (dex == 17) return 2;',
    '    return 3;   // 18',
    '}',
])

# ---- (2) the CON comment + the three ladders + the retirement ----
p2_old = NL.join([
    '// CON (PHB p.12)',
    '//   Score  HP adj  System shock  Res survival  Poison save adj',
    '//   3      -2      25%           30%           -2',
    '//   4      -1      30%           35%           -1',
    '//   5      -1      35%           40%           -1',
    '//   6-8    0       45-55%        45-55%        0',
    '//   9-12   0       60-75%        60-75%        0',
    '//   13-14  0       80-85%        80-85%        0',
    '//   15     +1      88%           90%           0',
    '//   16     +2      90%           93%           0',
    '//   17     +2      94%           96%           +1',
    '//   18     +2      96%           98%           +2',
    '//   (19+ rows exist for non-player characters; included for monsters)',
    '// ----------------------------------------------------------------------------',
])
p2_new = NL.join([
    '// CON (PHB p.12, pinned R178c cell by cell)',
    '//   Score  HP adj  System shock  Res survival',
    '//   3      -2      35%           40%',
    '//   4      -1      40%           45%',
    '//   5      -1      45%           50%',
    '//   6      -1      50%           55%',
    '//   7-12   0       55-75%        60-80%',
    '//   13-14  0       85%, 88%      90%, 92%',
    '//   15     +1      91%           94%',
    '//   16     +2      95%           96%',
    '//   17     +2      97%           98%',
    '//   18     +2      99%           100%',
    '//   (the unsourced poison-save column is retired',
    '//   R178c - not in the 1e print, and unused)',
    '// ----------------------------------------------------------------------------',
])

# ---- (3) the CON ladder bodies ----
p3_old = NL.join([
    'int conHPAdj(uint8_t con) {',
    '    static constexpr int adj[16] = {',
    '        -2, -1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, 1,  2,  2,  2',
    '    };',
    '    return adj[conIndex(con)];',
    '}',
    '',
    'int conSystemShock(uint8_t con) {',
    '    static constexpr int v[16] = {',
    '        25, 30, 35, 45, 50, 55, 60, 65, 70, 75, 80, 85, 88, 90, 94, 96',
    '    };',
    '    return v[conIndex(con)];',
    '}',
    '',
    'int conResSurvival(uint8_t con) {',
    '    static constexpr int v[16] = {',
    '        30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 93, 96, 98',
    '    };',
    '    return v[conIndex(con)];',
    '}',
    '',
    'int conPoisonSaveAdj(uint8_t con) {',
    '    static constexpr int v[16] = {',
    '        -2, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2',
    '    };',
    '    return v[conIndex(con)];',
    '}',
])
p3_new = NL.join([
    'int conHPAdj(uint8_t con) {',
    '    static constexpr int adj[16] = {',
    '        -2, -1, -1, -1,  0,  0,  0,  0,  0,  0,  0,  0, 1,  2,  2,  2',
    '    };',
    '    return adj[conIndex(con)];',
    '}',
    '',
    'int conSystemShock(uint8_t con) {',
    '    static constexpr int v[16] = {',
    '        35, 40, 45, 50, 55, 60, 65, 70, 75,',
    '        80, 85, 88, 91, 95, 97, 99',
    '    };',
    '    return v[conIndex(con)];',
    '}',
    '',
    'int conResSurvival(uint8_t con) {',
    '    static constexpr int v[16] = {',
    '        40, 45, 50, 55, 60, 65, 70, 75, 80,',
    '        85, 90, 92, 94, 96, 98, 100',
    '    };',
    '    return v[conIndex(con)];',
    '}',
])

# ---- (4) the character.h CON block ----
p4_old = NL.join([
    '// CON table (PHB p.12)',
    '//   hpAdj: bonus hp per hit die (clerics/fighters +1..+2 at high CON;',
    '//          full table applies to all classes per PHB, fighters gain the',
    '//          higher values - see rules/classes conHPAdjustment)',
    '//   systemShock: percent (d100 <= value = survive)',
    '//   resurrectionSurvival: percent',
    '//   poisonSaveAdj: save modifier vs. poison',
    '// ----------------------------------------------------------------------------',
    'int  conHPAdj(uint8_t con);          // -2..+2',
    'int  conSystemShock(uint8_t con);    // 25..99 (%)',
    'int  conResSurvival(uint8_t con);    // 35..100 (%)',
    'int  conPoisonSaveAdj(uint8_t con);  // -2..+2',
])
p4_new = NL.join([
    '// CON table (PHB p.12, pinned R178c)',
    '//   hpAdj: bonus hp per hit die (clerics/fighters +1..+2 at high CON;',
    '//          full table applies to all classes per PHB, fighters gain the',
    '//          higher values - see rules/classes conHPAdjustment)',
    '//   systemShock: percent (d100 <= value = survive)',
    '//   resurrectionSurvival: percent',
    '//   (the unsourced poison-save accessor is retired R178c)',
    '// ----------------------------------------------------------------------------',
    'int  conHPAdj(uint8_t con);          // -2..+2',
    'int  conSystemShock(uint8_t con);    // 35..99 (%)',
    'int  conResSurvival(uint8_t con);    // 40..100 (%)',
])

# ---- (5) the regtest R178c audit block ----
p5_old = NL.join([
    '        printf("R176 printed XP tables audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R163: the poison table audit -------------',
])
p5_new = NL.join([
    '        printf("R176 printed XP tables audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R178c: the DEX and CON tables audit ----',
    '    // PHB pp.11-12: the printed DEX reaction and',
    '    // defensive ladders and the CON hit-point,',
    '    // system-shock and resurrection-survival',
    '    // columns, pinned R178c (the R177 founding',
    '    // read divergences 1 and 2 closed). The',
    '    // 16-score walks and the clamps.',
    '    {',
    '        int bad = 0;',
    '        static const int kDexRe[16] = {',
    '            -3, -2, -1, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 1, 2, 3',
    '        };',
    '        static const int kDexDef[16] = {',
    '            4, 3, 2, 1, 0, 0, 0, 0, 0, 0,',
    '            0, 0, -1, -2, -3, -4',
    '        };',
    '        static const int kConHp[16] = {',
    '            -2, -1, -1, -1, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 1, 2, 2, 2',
    '        };',
    '        static const int kShock[16] = {',
    '            35, 40, 45, 50, 55, 60, 65, 70, 75,',
    '            80, 85, 88, 91, 95, 97, 99',
    '        };',
    '        static const int kRes[16] = {',
    '            40, 45, 50, 55, 60, 65, 70, 75, 80,',
    '            85, 90, 92, 94, 96, 98, 100',
    '        };',
    '        for (int i = 0; i < 16; ++i) {',
    '            uint8_t s = (uint8_t)(i + 3);',
    '            if (rules::dexReactionAdj(s) != kDexRe[i]) ++bad;',
    '            if (rules::dexDefensiveAdj(s) != kDexDef[i]) ++bad;',
    '            if (rules::conHPAdj(s) != kConHp[i]) ++bad;',
    '            if (rules::conSystemShock(s) != kShock[i]) ++bad;',
    '            if (rules::conResSurvival(s) != kRes[i]) ++bad;',
    '        }',
    '        // the clamps: low scores read the first row,',
    '        // high scores the last',
    '        if (rules::dexReactionAdj(0) != -3 ||',
    '            rules::dexReactionAdj(99) != 3) ++bad;',
    '        if (rules::dexDefensiveAdj(0) != 4 ||',
    '            rules::dexDefensiveAdj(99) != -4) ++bad;',
    '        if (rules::conSystemShock(0) != 35 ||',
    '            rules::conSystemShock(99) != 99) ++bad;',
    '        if (rules::conResSurvival(0) != 40 ||',
    '            rules::conResSurvival(99) != 100) ++bad;',
    '        if (rules::conHPAdj(2) != -2 ||',
    '            rules::conHPAdj(18) != 2) ++bad;',
    '        printf("R178c DEX and CON tables audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R163: the poison table audit -------------',
])

# ---- (6) the phb report: divergences 1 and 2 closed ----
p6_old = NL.join([
    '- [~] 1. **DEX Table I, reaction and attacking',
    '      adjustment (the DEXTERITY TABLE I page)** -',
    '      engine cells diverge at dex 3 (engine -2,',
    '      print -3), dex 4 (engine -1, print -2) and',
    '      dex 18 (engine +2, print +3); 5 through 17',
    '      match. LIVE: the accessor feeds missile',
    '      attacks (ai/actor) and the surprise roll',
    '      (rules/turn). The defensive adjustment ladder',
    '      matches the print (the items.cpp armor class',
    '      wiring).',
])
p6_new = NL.join([
    '- [x] 1. **DEX Table I, reaction and attacking',
    '      adjustment (the DEXTERITY TABLE I page)** -',
    '      CLOSED R178c: the ladder repinned to the',
    '      print (dex 3 -3, dex 4 -2, dex 18 +3; the',
    '      defensive ladder re-noted, already the',
    '      print). The live callers - missile attacks',
    '      (ai/actor) and the surprise roll',
    '      (rules/turn) - now read the printed cells;',
    '      the R178c battery audit walks both ladders.',
])

p7_old = NL.join([
    '- [~] 2. **CON table, the system shock and',
    '      resurrection survival columns (the',
    '      CONSTITUTION TABLE page)** - the engine system',
    '      shock reads 25 through 96 against the printed',
    '      35 through 99; the resurrection survival reads',
    '      30 through 98 against the printed 40 through',
    '      100 - every score diverges in both columns.',
    '      The resurrection column is LIVE (the',
    '      raise-dead roll and the R82 audit). The',
    '      character.cpp conHPAdj CON 6 cell reads 0',
    '      against the printed -1 (classes.cpp',
    '      conHPAdjustment already matches the print).',
    '      The poison-save column the engine carries',
    '      (conPoisonSaveAdj) is not in the 1e print at',
    '      all - unsourced, and unused.',
])
p7_new = NL.join([
    '- [x] 2. **CON table, the system shock and',
    '      resurrection survival columns (the',
    '      CONSTITUTION TABLE page)** -',
    '      CLOSED R178c: both columns repinned to the',
    '      print cell by cell (shock 35 through 99;',
    '      resurrection survival 40 through 100 - the',
    '      LIVE raise-dead roll now reads the printed',
    '      values); the CON 6 hit-point cell repinned',
    '      -1; the unsourced poison-save accessor',
    '      (conPoisonSaveAdj) RETIRED - not in the 1e',
    '      print, and unused. The R178c battery audit',
    '      walks all three repinned columns.',
])

# ---- (8) the phb report header round note ----
p8_old = NL.join([
    'requisite ladder is an open verify item. A report',
    'round adds no audit; the battery census stays 94',
    'until the first PHB fix round lands.',
])
p8_new = NL.join([
    'requisite ladder is an open verify item. A report',
    'round adds no audit; the battery census stays 94',
    'until the first PHB fix round lands.',
    '',
    'R178c CLOSED divergences 1 and 2 (the live bugs',
    'first, per the arc ordering rule): the DEX',
    'reaction ladder and the CON columns repinned to',
    'the print; the unsourced CON poison-save accessor',
    'retired. Census 95. The WIS, INT and CHA',
    'divergences (3, 4, 5) remain ranked fix rounds.',
])

# ---- (9) the dmg report round note ----
p9_old = NL.join([
    'round; the per-subclass specials renumber to',
    'R187+. No audit; census stays 94.',
])
p9_new = NL.join([
    'round; the per-subclass specials renumber to',
    'R187+. No audit; census stays 94.',
    'R178c CLOSED the PHB report divergences 1 and 2',
    '(the live bugs first, per the arc ordering',
    'rule): rules/character.cpp - the DEX reaction',
    'ladder repinned (3 -3, 4 -2, 18 +3; missile',
    'attacks and surprise now read the print), the',
    'CON system-shock (35-99) and resurrection-',
    'survival (40-100) columns repinned cell by cell',
    '(the raise-dead roll), the CON 6 hit-point cell',
    'repinned -1, and the unsourced poison-save',
    'accessor retired. New R178c battery audit;',
    'census 95.',
])

# ---- run ----
patch("rules/character.cpp", p1_old, p1_new,
      "character.cpp: the DEX ladder repinned",
      marker="return 3;   // 18")
assert len(applied) + len(already) == 1

patch("rules/character.cpp", p2_old, p2_new,
      "character.cpp: the CON comment repinned",
      marker="CON (PHB p.12, pinned R178c cell by cell)")
assert len(applied) + len(already) == 2

patch("rules/character.cpp", p3_old, p3_new,
      "character.cpp: the CON ladders repinned",
      marker="85, 90, 92, 94, 96, 98, 100")
assert len(applied) + len(already) == 3

patch("rules/character.h", p4_old, p4_new,
      "character.h: the CON block updated",
      marker="CON table (PHB p.12, pinned R178c)")
assert len(applied) + len(already) == 4

patch("regtest.cpp", p5_old, p5_new,
      "regtest.cpp: R178c audit block",
      marker="R178c DEX and CON tables audit")
assert len(applied) + len(already) == 5

patch("tools/phb_gap_report.md", p6_old, p6_new,
      "phb report: divergence 1 closed",
      marker="CLOSED R178c: the ladder repinned")
assert len(applied) + len(already) == 6

patch("tools/phb_gap_report.md", p7_old, p7_new,
      "phb report: divergence 2 closed",
      marker="CLOSED R178c: both columns repinned")
assert len(applied) + len(already) == 7

patch("tools/phb_gap_report.md", p8_old, p8_new,
      "phb report: R178c header note",
      marker="R178c CLOSED divergences 1 and 2")
assert len(applied) + len(already) == 8

patch("tools/dmg_gap_report.md", p9_old, p9_new,
      "dmg report: R178c round note",
      marker="R178c CLOSED the PHB report divergences 1 and 2")
assert len(applied) + len(already) == 9

# ---- R178c fails/tail ----
if fails:
    print("R178c splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 9:
    print("R178c splice: FAIL - expected 9 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R178c splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R178c splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R178c note: 9 patches; census 95 (one new audit);")
print("commit: R178c: the DEX and CON tables repinned - the")
print("live ladders fixed (census 95)")

