#!/usr/bin/env python3
# tools/r175_splice.py - R175: the Appendix L 5-and-up
# table pinned - the R171 OCR-debt finding closed.
#
# The book upload drops the 5-and-up band columns
# (the "15 & up" header prints with nothing under
# it), but the 1eonline.info compilation - the
# repo-trusted source, alive after all - carries the
# COMPLETE table on its conjure-animals page, so the
# finding is payable now:
#
#   (a) rules/klm.h header comment - the OCR-debt
#       JUDGMENT wording closes.
#   (b) rules/klm.h - the 20-name roster accessors
#       are replaced by the full banded table: hit
#       dice categories 5-14, 26 rows cell by cell
#       (the banded categories 5, 6, 7, 8, 10 and 12
#       with every dice-score column; the bandless
#       rows 9, 11, 13 and 14 the print dashes,
#       pinned as lo/hi 0), every name and quarter
#       cost. JUDGMENTs: the pinned roster was
#       incomplete (buffalo, skunk giant, lion, bear
#       cave and boar giant were absent); the
#       compilation spelling woolly corrects the
#       R171 wooly. The whale cap and the water
#       note stand unchanged.
#   (c) regtest.cpp - the R171 audit roster check
#       (the 20-name array) is amended to the new
#       count; a NEW R175 audit block carries the
#       full 26-row cell-by-cell check, the band
#       contiguity walk, the bandless gate and the
#       cap/note re-pins (census 93 - one new
#       audit printf).
#   (d) tools/dmg_gap_report.md - the header round
#       note, the R171 box tail and the Appendix
#       K+L+M box close the finding.
#
# Idempotent: safe to run twice; a silent run means
# the paste was truncated - this tail ALWAYS prints.
# An assert follows EVERY patch (the R142 lesson).
# This file contains ZERO backslash characters (the
# C newline is built from chr(92)), and no content
# string embeds a literal apostrophe (the R133b +
# R147 chunk-delivery lessons).
# Commit: "R175: appendix L 5-and-up table pinned -
# the R171 OCR debt closed (census 93)"
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

# ---- (1) the klm.h header comment ----
p1_old = NL.join([
    '// source, the R146 precedent); the Appendix L',
    '// 5-and-up band columns are OCR debt (open finding) -',
    '// the printed roster, the whale cap and the water',
    '// note are pinned; the Appendix M water tables for',
])
p1_new = NL.join([
    '// source, the R146 precedent); the Appendix L',
    '// 5-and-up section is pinned R175 (the full table',
    '// from the trusted compilation; the book upload',
    '// drops the band columns); the whale cap and the',
    '// water note are pinned; the Appendix M water tables for',
])

# ---- (2) the klm.h roster block -> the full table ----
p2_old = NL.join([
    '// The 5-and-up roster: the printed animal names.',
    '// The band columns of this section are OCR debt',
    '// (see the gap report open finding).',
    'inline int klmConjHigherRosterCount() { return 20; }',
    '',
    'inline const char* klmConjHigherRosterName(int i) {',
    '    static const char* const k[20] = {',
    '        "ape, carnivorous",',
    '        "baluchitherium",',
    '        "bear, brown",',
    '        "elephant",',
    '        "elephant (loxodont)",',
    '        "hippopotamus",',
    '        "hyena, giant",',
    '        "lion, spotted",',
    '        "mammoth",',
    '        "mastodon",',
    '        "otter, giant",',
    '        "porcupine, giant",',
    '        "rhinoceros",',
    '        "rhinoceros, wooly",',
    '        "stag, giant",',
    '        "tiger",',
    '        "tiger, sabre-tooth",',
    '        "titanothere",',
    '        "whale (small)",',
    '        "wolverine, giant"',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 19) i = 19;',
    '    return k[i];',
    '}',
])
p2_new = NL.join([
    '// R175: the full 5-and-up section - hit dice',
    '// categories 5-14, every band, name and quarter',
    '// cost. Source: the 1eonline.info compilation',
    '// (the repo-trusted source), whose',
    '// conjure-animals page carries the complete',
    '// table the book upload drops. JUDGMENTs: the',
    '// R171 20-name roster was incomplete (buffalo,',
    '// skunk giant, lion, bear cave and boar giant',
    '// were absent) - replaced by the full table;',
    '// the compilation spelling woolly corrects the',
    '// pinned wooly; the bandless rows the print',
    '// dashes (9, 11, 13, 14) pin as lo/hi 0.',
    'struct ConjHigherRow {',
    '    int cat;           // hit dice category (5-14)',
    '    int lo, hi;        // 0,0 = the printed dash',
    '    const char* name;',
    '    int cost;          // quarter hit dice (5 = 20)',
    '};',
    '',
    'inline int klmConjHigherCount() { return 26; }',
    '',
    'inline const ConjHigherRow& klmConjHigherRow(int i) {',
    '    static const ConjHigherRow k[26] = {',
    '        // category 5',
    '        { 5,   1, 10, "ape, carnivorous",  20 },',
    '        { 5,  11, 25, "buffalo",           20 },',
    '        { 5,  26, 35, "hyena, giant",      20 },',
    '        { 5,  36, 50, "otter, giant",      20 },',
    '        { 5,  51, 70, "skunk, giant",      20 },',
    '        { 5,  71, 85, "stag, giant",       20 },',
    '        { 5,  86,100, "wolverine, giant",  20 },',
    '        // category 6',
    '        { 6,   1, 40, "bear, brown",       25 },',
    '        { 6,  41, 60, "lion",              22 },',
    '        { 6,  61, 80, "porcupine, giant",  24 },',
    '        { 6,  81,100, "tiger",             25 },',
    '        // category 7',
    '        { 7,   1, 65, "boar, giant",       28 },',
    '        { 7,  66,100, "lion, spotted",     26 },',
    '        // category 8',
    '        { 8,   1, 30, "bear, cave",        30 },',
    '        { 8,  31, 70, "hippopotamus",      32 },',
    '        { 8,  71,100, "tiger, sabre-tooth", 30 },',
    '        // category 9 (bandless: the printed dash)',
    '        { 9,   0,  0, "rhinoceros",        34 },',
    '        // category 10',
    '        { 10,  1, 60, "elephant",          40 },',
    '        { 10, 61,100, "rhinoceros, woolly",40 },',
    '        // category 11 (bandless)',
    '        { 11,  0,  0, "elephant (loxodont)", 44 },',
    '        // category 12',
    '        { 12,  1, 60, "mastodon",          48 },',
    '        { 12, 61,100, "titanothere",       48 },',
    '        // category 13 (bandless)',
    '        { 13,  0,  0, "mammoth",           52 },',
    '        { 13,  0,  0, "whale (small)",     52 },',
    '        // category 14 (bandless)',
    '        { 14,  0,  0, "baluchitherium",    56 },',
    '        { 14,  0,  0, "whale (small)",     56 }',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 25) i = 25;',
    '    return k[i];',
    '}',
])

# ---- (3) the regtest.cpp R171 roster check ----
p3_old = NL.join([
    '        static const char* kCjHi20[20] = {',
    '            "ape, carnivorous",',
    '            "baluchitherium",',
    '            "bear, brown",',
    '            "elephant",',
    '            "elephant (loxodont)",',
    '            "hippopotamus",',
    '            "hyena, giant",',
    '            "lion, spotted",',
    '            "mammoth",',
    '            "mastodon",',
    '            "otter, giant",',
    '            "porcupine, giant",',
    '            "rhinoceros",',
    '            "rhinoceros, wooly",',
    '            "stag, giant",',
    '            "tiger",',
    '            "tiger, sabre-tooth",',
    '            "titanothere",',
    '            "whale (small)",',
    '            "wolverine, giant"',
    '        };',
    '        if (rules::klmConjHigherRosterCount() != 20)',
    '            ++bad;',
    '        for (int i = 0; i < 20; ++i)',
    '            if (std::string(',
    '                    rules::klmConjHigherRosterName(i))',
    '                    != kCjHi20[i])',
    '                ++bad;',
])
p3_new = NL.join([
    '        // R175: the 20-name roster became the full',
    '        // banded table (26 rows) - the count check',
    '        // here keeps the R171 audit honest; the',
    '        // cell-by-cell check lives in the R175',
    '        // audit block below',
    '        if (rules::klmConjHigherCount() != 26)',
    '            ++bad;',
])

# ---- (4) the regtest.cpp R175 audit block ----
p4_old = NL.join([
    '        printf("R171 appendices K L and M audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R172: appendix J herbs audit --------------',
])
p4_new = NL.join([
    '        printf("R171 appendices K L and M audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R175: appendix L 5-and-up table audit -----',
    '    // DMG p.222: the full 5-and-up section the',
    '    // book upload drops - pinned from the',
    '    // 1eonline.info compilation (the repo-trusted',
    '    // source). Hit dice categories 5-14, 26 rows',
    '    // cell by cell: the banded categories (5, 6,',
    '    // 7, 8, 10, 12) with every dice-score column;',
    '    // the bandless rows (9, 11, 13, 14) the print',
    '    // dashes, pinned as lo/hi 0. JUDGMENT: the',
    '    // compilation spelling woolly (the R171 wooly',
    '    // corrected); the bandless rows carry no',
    '    // dice-score column, so only the contiguity',
    '    // walk gates the banded ones.',
    '    {',
    '        int bad = 0;',
    '        static const int kCat[26] = {',
    '            5, 5, 5, 5, 5, 5, 5,',
    '            6, 6, 6, 6,',
    '            7, 7,',
    '            8, 8, 8,',
    '            9,',
    '            10, 10,',
    '            11,',
    '            12, 12,',
    '            13, 13,',
    '            14, 14',
    '        };',
    '        static const int kLo[26] = {',
    '             1, 11, 26, 36, 51, 71, 86,',
    '             1, 41, 61, 81,',
    '             1, 66,',
    '             1, 31, 71,',
    '             0,',
    '             1, 61,',
    '             0,',
    '             1, 61,',
    '             0, 0,',
    '             0, 0',
    '        };',
    '        static const int kHi[26] = {',
    '            10, 25, 35, 50, 70, 85, 100,',
    '            40, 60, 80, 100,',
    '            65, 100,',
    '            30, 70, 100,',
    '            0,',
    '            60, 100,',
    '            0,',
    '            60, 100,',
    '            0, 0,',
    '            0, 0',
    '        };',
    '        static const char* const kNm[26] = {',
    '            "ape, carnivorous",',
    '            "buffalo",',
    '            "hyena, giant",',
    '            "otter, giant",',
    '            "skunk, giant",',
    '            "stag, giant",',
    '            "wolverine, giant",',
    '            "bear, brown",',
    '            "lion",',
    '            "porcupine, giant",',
    '            "tiger",',
    '            "boar, giant",',
    '            "lion, spotted",',
    '            "bear, cave",',
    '            "hippopotamus",',
    '            "tiger, sabre-tooth",',
    '            "rhinoceros",',
    '            "elephant",',
    '            "rhinoceros, woolly",',
    '            "elephant (loxodont)",',
    '            "mastodon",',
    '            "titanothere",',
    '            "mammoth",',
    '            "whale (small)",',
    '            "baluchitherium",',
    '            "whale (small)"',
    '        };',
    '        static const int kCost[26] = {',
    '            20, 20, 20, 20, 20, 20, 20,',
    '            25, 22, 24, 25,',
    '            28, 26,',
    '            30, 32, 30,',
    '            34,',
    '            40, 40,',
    '            44,',
    '            48, 48,',
    '            52, 52,',
    '            56, 56',
    '        };',
    '        if (rules::klmConjHigherCount() != 26) ++bad;',
    '        for (int i = 0; i < 26; ++i) {',
    '            const rules::ConjHigherRow& r =',
    '                rules::klmConjHigherRow(i);',
    '            if (r.cat  != kCat[i])  ++bad;',
    '            if (r.lo   != kLo[i])   ++bad;',
    '            if (r.hi   != kHi[i])   ++bad;',
    '            if (std::string(r.name) != kNm[i]) ++bad;',
    '            if (r.cost != kCost[i]) ++bad;',
    '        }',
    '        // the clamps: index -1 and 26+ read the ends',
    '        if (rules::klmConjHigherRow(-1).cat != 5 ||',
    '            rules::klmConjHigherRow(99).cat != 14)',
    '            ++bad;',
    '        // the banded categories: first row lo 1,',
    '        // contiguous bands, last row hi 100',
    '        for (int i = 0; i < 26; ++i) {',
    '            const rules::ConjHigherRow& r =',
    '                rules::klmConjHigherRow(i);',
    '            if (r.lo == 0) continue;   // bandless',
    '            bool first = (i == 0) ||',
    '                rules::klmConjHigherRow(i - 1).cat',
    '                    != r.cat;',
    '            bool last = (i == 25) ||',
    '                rules::klmConjHigherRow(i + 1).cat',
    '                    != r.cat;',
    '            if (first && r.lo != 1) ++bad;',
    '            if (last) {',
    '                if (r.hi != 100) ++bad;',
    '            } else {',
    '                const rules::ConjHigherRow& n =',
    '                    rules::klmConjHigherRow(i + 1);',
    '                if (r.hi + 1 != n.lo) ++bad;',
    '            }',
    '        }',
    '        // the bandless categories are 9, 11, 13, 14',
    '        for (int i = 0; i < 26; ++i) {',
    '            const rules::ConjHigherRow& r =',
    '                rules::klmConjHigherRow(i);',
    '            if ((r.cat == 9 || r.cat == 11 ||',
    '                 r.cat == 13 || r.cat == 14)',
    '                && (r.lo != 0 || r.hi != 0)) ++bad;',
    '        }',
    '        // the whale cap and the water note stand',
    '        if (rules::klmConjWhaleMaxHitDiceCost() != 36)',
    '            ++bad;',
    '        if (!rules::klmConjWaterSwimmersAndFlyersOnly())',
    '            ++bad;',
    '        printf("R175 appendix L 5-and-up table audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R172: appendix J herbs audit --------------',
])

# ---- (5) the gap report header note ----
p5_old = NL.join([
    'R174 battery block. Census 92.',
    '',
    'Categories:',
])
p5_new = NL.join([
    'R174 battery block. Census 92.',
    'R175 PINNED the Appendix L 5-and-up table (DMG',
    'p.222) - the R171 OCR-debt finding closed: the',
    'book upload drops the band columns, but the',
    '1eonline.info compilation (alive - its',
    'conjure-animals page carries the complete',
    'table) supplies the full section: hit dice',
    'categories 5-14, 26 rows cell by cell (the',
    'banded categories 5, 6, 7, 8, 10 and 12 with',
    'every dice-score column; the bandless rows 9,',
    '11, 13 and 14 the print dashes), every name',
    'and quarter cost. JUDGMENTs: the pinned',
    '20-name roster was incomplete (buffalo, skunk',
    'giant, lion, bear cave and boar giant were',
    'absent) - replaced by the full table; the',
    'compilation spelling woolly corrects the',
    'pinned wooly; the bandless rows pin as lo/hi',
    '0 (the printed dash). rules/klm.h; the R175',
    'battery audit carries the cell-by-cell check.',
    'Census 93.',
    '',
    'Categories:',
])

# ---- (6) the gap report R171 box tail ----
p6_old = NL.join([
    'the Appendix L 5-and-up band columns are OCR',
    'debt - an open finding, the roster is pinned;',
])
p6_new = NL.join([
    'the Appendix L 5-and-up band columns were OCR',
    'debt, CLOSED R175 (the trusted compilation',
    'supplies the full 26-row table - see the R175',
    'header note);',
])

# ---- (7) the gap report Appendix K+L+M box ----
p7_old = NL.join([
    '      monsters tables; the Appendix L 5-and-up band',
    '      columns are the open OCR-debt finding).',
])
p7_new = NL.join([
    '      monsters tables; the Appendix L 5-and-up band',
    '      columns were the OCR-debt finding, CLOSED',
    '      R175: the full 26-row table is pinned from',
    '      the trusted compilation).',
])

# ---- run ----
patch("rules/klm.h", p1_old, p1_new,
      "klm.h: header comment closed",
      marker="pinned R175 (the full table")
assert len(applied) + len(already) == 1

patch("rules/klm.h", p2_old, p2_new,
      "klm.h: the full 5-and-up table",
      marker="klmConjHigherRow(int i)")
assert len(applied) + len(already) == 2

patch("regtest.cpp", p3_old, p3_new,
      "regtest.cpp: R171 roster check amended",
      marker="klmConjHigherCount() != 26")
assert len(applied) + len(already) == 3

patch("regtest.cpp", p4_old, p4_new,
      "regtest.cpp: R175 audit block",
      marker="R175 appendix L 5-and-up table audit")
assert len(applied) + len(already) == 4

patch("tools/dmg_gap_report.md", p5_old, p5_new,
      "gap report: R175 header note",
      marker="R175 PINNED the Appendix L 5-and-up table")
assert len(applied) + len(already) == 5

patch("tools/dmg_gap_report.md", p6_old, p6_new,
      "gap report: R171 box tail closed",
      marker="CLOSED R175 (the trusted compilation")
assert len(applied) + len(already) == 6

patch("tools/dmg_gap_report.md", p7_old, p7_new,
      "gap report: K+L+M box closed",
      marker="CLOSED" + NL + "      R175: the full 26-row table")
assert len(applied) + len(already) == 7

# ---- R175 fails/tail ----
if fails:
    print("R175 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 7:
    print("R175 splice: FAIL - expected 7 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R175 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R175 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R175 note: 7 patches; census 93 (one new audit);")
print("commit: R175: appendix L 5-and-up table pinned - the")
print("R171 OCR debt closed (census 93)")

