#!/usr/bin/env python3
# tools/r176_splice.py - R176: the printed XP tables
# pinned - the R162 open box closed.
#
# The R162 round pinned the title ladders but left the
# xpForLevel rows open (they diverged from the print from
# mid-table on). The PHB upload DOES carry the four printed
# XP boundary columns (the R162 round had read only the
# title columns), so the finding is payable:
#
#   (a) rules/classes.h header comment - the divergence
#       wording closes.
#   (b) rules/classes.h - the xpForLevel function comment
#       carries the attain convention and the printed
#       adders.
#   (c) rules/classes.cpp header comment - the divergence
#       wording closes.
#   (d) rules/classes.cpp - the four XP rows repinned to
#       the print cell by cell (levels 1-13 each), and the
#       XP_ADDER row repinned to the printed adders
#       (fighter 250k past the 11th, MU 375k past the
#       12th, cleric 225k past the 11th, thief 220k past
#       the 12th). JUDGMENT: the attain convention is the
#       printed band lower bound - 1 (fighter level 5:
#       the band 18,001-35,000 gives 18000; the old row
#       read 16000). The engine linear-beyond convention
#       is kept, now anchored on the printed adders.
#   (e) regtest.cpp - a NEW R176 audit block after the
#       R162 audit: the 13-row walk per class, the
#       beyond-table probes (levels 14 and 15 per class),
#       and the clamps (census 94 - one new audit printf).
#   (f) tools/dmg_gap_report.md - the header round note,
#       the R162 FINDING tail and the classes box tail
#       close the finding.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). This file contains
# ZERO backslash characters (the C newline is built from
# chr(92)), and no content string embeds a literal
# apostrophe (the R133b + R147 lessons).
# Commit: "R176: the printed XP tables pinned - the R162
# divergence closed (census 94)"
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

# ---- (1) the classes.h header comment ----
p1_old = NL.join([
    '// against the PHB print by R162 (p.20-31); the XP tables are',
    '// transcribed from project notes and DIVERGE from the print from',
    '// mid-table on (an open box - see the gap report header note).',
])
p1_new = NL.join([
    '// against the PHB print by R162 (p.20-31); the XP tables are',
    '// pinned to the printed XP boundaries by R176 (the old project',
    '// notes rows diverged from the print mid-table and are retired).',
])

# ---- (2) the classes.h xpForLevel comment ----
p2_old = NL.join([
    '// Total XP required to ATTAIN the given level (level 1 = 0).',
    '// Rows are defined through level 12 (13 entries, index = level-1);',
    '// beyond the table, each level adds the class' + chr(39) + 's linear adder',
    '// (fighter 100k, MU 125k, cleric 112.5k, thief 110k).',
    'int xpForLevel(int classIndex, int level);',
])
p2_new = NL.join([
    '// Total XP required to ATTAIN the given level (level 1 = 0).',
    '// Convention: the printed band' + chr(39) + 's lower bound - 1',
    '// (PHB pp.20-31, pinned R176). Rows through level 13 (13',
    '// entries, index = level-1); beyond, each level adds the',
    '// printed adder (fighter 250k past the 11th, MU 375k past',
    '// the 12th, cleric 225k past the 11th, thief 220k past',
    '// the 12th).',
    'int xpForLevel(int classIndex, int level);',
])

# ---- (3) the classes.cpp header comment ----
p3_old = NL.join([
    '// R162: the titleFor ladders and the HP_BEYOND_CAP convention are',
    '// verified against the PHB print (pp.20-31); the xpForLevel rows',
    '// DIVERGE from the print from mid-table on (fighter level 5 reads',
    '// 16000 against the printed 18000 boundary; the MU, cleric and',
    '// thief rows diverge above that) and stay open.',
])
p3_new = NL.join([
    '// R162: the titleFor ladders and the HP_BEYOND_CAP convention are',
    '// verified against the PHB print (pp.20-31); R176 repins the',
    '// xpForLevel rows to the printed XP boundaries cell by cell (the',
    '// R162 divergence closed - the printed adders, the band-lower-1',
    '// attain convention; see the R176 battery audit).',
])

# ---- (4) the classes.cpp XP table block ----
p4_old = NL.join([
    '// ----------------------------------------------------------------------------',
    '// XP tables (index = level - 1; rows through level 12, then linear)',
    '// NOTE: transcribed from project notes; verify vs PHB p.20-31.',
    '// ----------------------------------------------------------------------------',
    '',
    'static const int XP_FIGHTER[13] = {',
    '        0,    2000,    4000,    8000,   16000,   35000,',
    '    70000,  125000,  250000,  350000,  450000,  550000,',
    '   650000',
    '};',
    '',
    'static const int XP_MAGIC_USER[13] = {',
    '        0,    2500,    5000,   10000,   20000,   40000,',
    '    60000,   80000,  105000,  135000,  165000,  195000,',
    '   225000',
    '};',
    '',
    'static const int XP_CLERIC[13] = {',
    '        0,    1500,    3000,    6000,   13000,   27500,',
    '    55000,  110000,  225000,  337500,  450000,  562500,',
    '   675000',
    '};',
    '',
    'static const int XP_THIEF[13] = {',
    '        0,    1250,    2500,    5000,   10000,   20000,',
    '    42500,   70000,  110000,  160000,  210000,  260000,',
    '   310000',
    '};',
    '',
    '// Linear adder per level beyond the 12-row tables',
    'static const int XP_ADDER[CLASS_COUNT] = { 100000, 125000, 112500, 110000 };',
])
p4_new = NL.join([
    '// ----------------------------------------------------------------------------',
    '// XP tables (PHB pp.20-31 printed class tables, pinned R176).',
    '// Convention: the XP to ATTAIN level N is the printed band lower',
    '// bound - 1 (fighter level 5: the band 18,001-35,000 gives 18000);',
    '// level 1 is 0. Rows through level 13 (index = level-1); beyond,',
    '// each level adds the printed adder (fighter 250k past the 11th,',
    '// MU 375k past the 12th, cleric 225k past the 11th, thief 220k',
    '// past the 12th).',
    '// ----------------------------------------------------------------------------',
    '',
    'static const int XP_FIGHTER[13] = {',
    '        0,    2000,    4000,    8000,   18000,   35000,',
    '    70000,  125000,  250000,  500000,  750000, 1000000,',
    '  1250000',
    '};',
    '',
    'static const int XP_MAGIC_USER[13] = {',
    '        0,    2500,    5000,   10000,   22500,   40000,',
    '    60000,   90000,  135000,  250000,  375000,  750000,',
    '  1125000',
    '};',
    '',
    'static const int XP_CLERIC[13] = {',
    '        0,    1500,    3000,    6000,   13000,   27500,',
    '    55000,  110000,  225000,  450000,  675000,  900000,',
    '  1125000',
    '};',
    '',
    'static const int XP_THIEF[13] = {',
    '        0,    1250,    2500,    5000,   10000,   20000,',
    '    42500,   70000,  110000,  160000,  220000,  440000,',
    '   660000',
    '};',
    '',
    '// The printed adders per level beyond the table rows',
    'static const int XP_ADDER[CLASS_COUNT] = { 250000, 375000, 225000, 220000 };',
])

# ---- (5) the regtest R176 audit block ----
p5_old = NL.join([
    '        printf("R162 level title ladders audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R163: the poison table audit -------------',
])
p5_new = NL.join([
    '        printf("R162 level title ladders audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R176: the printed XP tables audit -------',
    '    // PHB pp.20-31: the four printed class XP',
    '    // boundary rows, pinned R176 (the R162 open',
    '    // box closed). Convention: the XP to attain',
    '    // level N is the band lower bound - 1. The',
    '    // 13-row walk per class, the printed adders',
    '    // via the beyond-table probes, and the clamps.',
    '    {',
    '        int bad = 0;',
    '        static const int kF[13] = {',
    '            0, 2000, 4000, 8000, 18000, 35000,',
    '            70000, 125000, 250000, 500000,',
    '            750000, 1000000, 1250000',
    '        };',
    '        static const int kM[13] = {',
    '            0, 2500, 5000, 10000, 22500, 40000,',
    '            60000, 90000, 135000, 250000,',
    '            375000, 750000, 1125000',
    '        };',
    '        static const int kC[13] = {',
    '            0, 1500, 3000, 6000, 13000, 27500,',
    '            55000, 110000, 225000, 450000,',
    '            675000, 900000, 1125000',
    '        };',
    '        static const int kT[13] = {',
    '            0, 1250, 2500, 5000, 10000, 20000,',
    '            42500, 70000, 110000, 160000,',
    '            220000, 440000, 660000',
    '        };',
    '        for (int i = 0; i < 13; ++i) {',
    '            if (rules::xpForLevel(rules::CLASS_FIGHTER,',
    '                                  i + 1) != kF[i]) ++bad;',
    '            if (rules::xpForLevel(rules::CLASS_MAGIC_USER,',
    '                                  i + 1) != kM[i]) ++bad;',
    '            if (rules::xpForLevel(rules::CLASS_CLERIC,',
    '                                  i + 1) != kC[i]) ++bad;',
    '            if (rules::xpForLevel(rules::CLASS_THIEF,',
    '                                  i + 1) != kT[i]) ++bad;',
    '        }',
    '        // the printed adders, probed beyond the rows',
    '        // (fighter 250k past the 11th, MU 375k past',
    '        // the 12th, cleric 225k past the 11th, thief',
    '        // 220k past the 12th)',
    '        if (rules::xpForLevel(rules::CLASS_FIGHTER, 14)',
    '            != 1500000) ++bad;',
    '        if (rules::xpForLevel(rules::CLASS_FIGHTER, 15)',
    '            != 1750000) ++bad;',
    '        if (rules::xpForLevel(rules::CLASS_MAGIC_USER, 14)',
    '            != 1500000) ++bad;',
    '        if (rules::xpForLevel(rules::CLASS_MAGIC_USER, 15)',
    '            != 1875000) ++bad;',
    '        if (rules::xpForLevel(rules::CLASS_CLERIC, 14)',
    '            != 1350000) ++bad;',
    '        if (rules::xpForLevel(rules::CLASS_CLERIC, 15)',
    '            != 1575000) ++bad;',
    '        if (rules::xpForLevel(rules::CLASS_THIEF, 14)',
    '            != 880000) ++bad;',
    '        if (rules::xpForLevel(rules::CLASS_THIEF, 15)',
    '            != 1100000) ++bad;',
    '        // the clamps: level 0 or below reads 0, a bad',
    '        // class reads 0',
    '        if (rules::xpForLevel(rules::CLASS_FIGHTER, 0) != 0 ||',
    '            rules::xpForLevel(rules::CLASS_FIGHTER, -5) != 0)',
    '            ++bad;',
    '        if (rules::xpForLevel(-1, 5) != 0 ||',
    '            rules::xpForLevel(99, 5) != 0) ++bad;',
    '        printf("R176 printed XP tables audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R163: the poison table audit -------------',
])

# ---- (6) the gap report header round note + census ----
p6_old = NL.join([
    '0 (the printed dash). rules/klm.h; the R175',
    'battery audit carries the cell-by-cell check.',
    'Census 93.',
])
p6_new = NL.join([
    '0 (the printed dash). rules/klm.h; the R175',
    'battery audit carries the cell-by-cell check.',
    'R176 PINNED the printed XP tables (PHB pp.20-31',
    'class tables) - the R162 FINDING closed: the PHB',
    'upload DOES carry the four printed XP boundary',
    'columns (the R162 round had read the title',
    'columns only). All four xpForLevel rows repinned',
    'to the print cell by cell - fighter 0, 2000,',
    '4000, 8000, 18000, 35000, 70000, 125000, 250000,',
    '500000, 750000, then 250k per level past the',
    '11th; MU 0, 2500, 5000, 10000, 22500, 40000,',
    '60000, 90000, 135000, 250000, 375000, 750000,',
    '1125000, then 375k past the 12th; cleric 0,',
    '1500, 3000, 6000, 13000, 27500, 55000, 110000,',
    '225000, 450000, 675000, then 225k past the',
    '11th; thief 0, 1250, 2500, 5000, 10000, 20000,',
    '42500, 70000, 110000, 160000, 220000, 440000,',
    '660000, then 220k past the 12th. JUDGMENT: the',
    'attain convention is the printed band lower',
    'bound - 1 (fighter level 5: 18,001-35,000 gives',
    '18000 - the old row read 16000); the engine',
    'linear-beyond convention is kept, now anchored',
    'on the printed adders. rules/classes.cpp; the',
    'R176 battery audit carries the row walk, the',
    'beyond-table probes and the clamps.',
    'Census 94.',
])

# ---- (7) the gap report R162 FINDING tail ----
p7_old = NL.join([
    'rows DIVERGE from the print from mid-table on',
    '(fighter level 5 reads 16000 against the printed',
    '18000 boundary; the MU, cleric and thief rows',
    'diverge above that) - the XP tables stay an',
    'open box. Census 80.',
])
p7_new = NL.join([
    'rows DIVERGED from the print from mid-table on',
    '(fighter level 5 read 16000 against the printed',
    '18000 boundary; the MU, cleric and thief rows',
    'diverged above that) - CLOSED R176: the rows',
    'repinned to the print cell by cell.',
    'Census 80.',
])

# ---- (8) the gap report classes box tail ----
p8_old = NL.join([
    '      R162: rules/classes.cpp (the four printed ladders',
    '      through the name levels; the cleric level 5 blank',
    '      cell carries Curate down; the XP-row divergence is',
    '      recorded in the header note).',
])
p8_new = NL.join([
    '      R162: rules/classes.cpp (the four printed ladders',
    '      through the name levels; the cleric level 5 blank',
    '      cell carries Curate down; the XP-row divergence is',
    '      CLOSED R176 - the rows repinned to the print).',
])

# ---- run ----
patch("rules/classes.h", p1_old, p1_new,
      "classes.h: header comment closed",
      marker="pinned to the printed XP boundaries by R176")
assert len(applied) + len(already) == 1

patch("rules/classes.h", p2_old, p2_new,
      "classes.h: xpForLevel comment",
      marker="Convention: the printed band" + chr(39) + 's lower bound - 1')
assert len(applied) + len(already) == 2

patch("rules/classes.cpp", p3_old, p3_new,
      "classes.cpp: header comment closed",
      marker="R176 repins the")
assert len(applied) + len(already) == 3

patch("rules/classes.cpp", p4_old, p4_new,
      "classes.cpp: the printed XP tables",
      marker="static const int XP_ADDER[CLASS_COUNT] = { 250000, 375000, 225000, 220000 };")
assert len(applied) + len(already) == 4

patch("regtest.cpp", p5_old, p5_new,
      "regtest.cpp: R176 audit block",
      marker="R176 printed XP tables audit")
assert len(applied) + len(already) == 5

patch("tools/dmg_gap_report.md", p6_old, p6_new,
      "gap report: R176 header note",
      marker="R176 PINNED the printed XP tables")
assert len(applied) + len(already) == 6

patch("tools/dmg_gap_report.md", p7_old, p7_new,
      "gap report: R162 FINDING tail closed",
      marker="CLOSED R176: the rows")
assert len(applied) + len(already) == 7

patch("tools/dmg_gap_report.md", p8_old, p8_new,
      "gap report: classes box tail closed",
      marker="CLOSED R176 - the rows repinned to the print).")
assert len(applied) + len(already) == 8

# ---- R176 fails/tail ----
if fails:
    print("R176 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 8:
    print("R176 splice: FAIL - expected 8 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R176 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R176 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R176 note: 8 patches; census 94 (one new audit);")
print("commit: R176: the printed XP tables pinned - the R162")
print("divergence closed (census 94)")

