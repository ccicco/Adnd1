#!/usr/bin/env python3
# tools/r174_splice.py - R174: the R146 fiction leftovers
# pinned - the two city flavor notes the R149 book-verify
# pass confirmed against the fresh DMG upload (p.191-192):
#
#   (a) dm/encounters.cpp R64 header comment - the two
#       notes stop being named-unmodeled (2 paragraphs).
#   (b) dm/encounters.cpp R146 comment tail - the stale
#       70/25/no-last-5 wording is replaced by the R174
#       note (the R149-corrected reading).
#   (c) dm/encounters.cpp - the R174 block: the noble
#       gender coin (nobleman-with-retainers 75% /
#       noblewoman 25%), the noblewoman 75% sedan-chair
#       likelihood (carriers and linkboys at night; the
#       complement reads her on foot), and the ruffian
#       matrix footnote (1 in 4 can be half-orc or of
#       humanoid race - goblin, hobgoblin, kobold, orc -
#       banded as five equal fifths of the quarter, the
#       weights the book leaves unstated, documented).
#       Fiction-only descriptors, the R146 precedent;
#       the note says CAN be - the fiction never summons
#       the bestiary records.
#   (d) dm/encounters.h - the comment amendment plus the
#       three declarations.
#   (e) game/state_sea.cpp - the noble and ruffian rows
#       dress with the new descriptors (wired like the
#       R146 drunk and harlot lines).
#   (f) regtest.cpp - the R174 audit block: every band
#       edge pinned both ways plus the 1-100 sweep, all
#       three tables (census 92 - one new audit printf).
#   (g) tools/dmg_gap_report.md - the header round note,
#       the R146 box tail, and the R146-fiction open box
#       flips CLOSED.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). This file contains
# ZERO backslash characters (the C newline is built from
# chr(92)), and no content string embeds a literal
# apostrophe (the R133b + R147 chunk-delivery lessons).
# Commit: "R174: R146 fiction leftovers pinned - the noble
# gender coin, sedan-chair detail and ruffian 1-in-4 note
# (census 92)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BS = chr(92)   # one backslash
NL = chr(10)
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

# ---- (1) the encounters.cpp R64 header comment ----
p1_old = NL.join([
    '// pinned R146 (cityHarlotKind / cityDrunkKind); noble',
    '// gender and the ruffian 1-in-4 half-orc/humanoid note',
    '// stay unmodeled fiction, documented in the row',
    '// comments. Numbers are the printed',
])
p1_new = NL.join([
    '// pinned R146 (cityHarlotKind / cityDrunkKind); the',
    '// noble gender coin, the noblewoman sedan-chair detail',
    '// and the ruffian 1-in-4 half-orc/humanoid note are',
    '// pinned R174 (cityNobleKind / cityNoblewomanSedan /',
    '// cityRuffianKind). Numbers are the printed',
])

# ---- (2) the encounters.cpp R146 comment tail ----
p2_old = NL.join([
    '// documented). The two remaining R64 flavor notes - noble',
    '// gender (70% nobleman / 25% noblewoman, the last 5%',
    '// unprinted) and the ruffian 1-in-4 half-orc/humanoid note',
    '// - stay unmodeled fiction (gap report).',
])
p2_new = NL.join([
    '// documented). R174 pins the two remaining R64 flavor',
    '// notes below (the R149-corrected reading): noble',
    '// gender is a clean nobleman-with-retainers 75% /',
    '// noblewoman 25% coin; the noblewoman is 75% likely',
    '// to have a sedan chair, carriers and linkboys (at',
    '// night); the printed matrix footnote - 1 in 4',
    '// ruffians can be half-orc or of humanoid race',
    '// (goblin, hobgoblin, kobold, orc) - is banded as',
    '// five equal fifths of the quarter, the weights the',
    '// book leaves unstated (documented).',
])

# ---- (3) the encounters.cpp R174 block ----
p3_old = NL.join([
    'const char* cityHarlotKind(int pctile) {',
    '    return flavorKindFor(kHarlotKinds,',
    '        sizeof kHarlotKinds / sizeof kHarlotKinds[0], pctile);',
    '}',
    '',
    '',
])
p3_new = NL.join([
    'const char* cityHarlotKind(int pctile) {',
    '    return flavorKindFor(kHarlotKinds,',
    '        sizeof kHarlotKinds / sizeof kHarlotKinds[0], pctile);',
    '}',
    '',
    '',
    '// ----------------------------------------------------------------------------',
    '// R174: the two remaining R64 city flavor notes, pinned',
    '// from the fresh DMG upload (p.191-192, both confirmed',
    '// by the R149 book-verify pass): the noble gender coin',
    '// - nobleman-with-retainers 75% / noblewoman 25% (the',
    '// corrected reading; the 70/25/no-last-5 guess is dead)',
    '// - and the noblewoman 75% sedan-chair likelihood (with',
    '// carriers and linkboys at night; the complement reads',
    '// her on foot). The ruffian matrix footnote (if',
    '// desired, 1 in 4 can be half-orc or of humanoid',
    '// race - goblin, hobgoblin, kobold, orc) is banded',
    '// as the printed 25% quarter split into five equal',
    '// fifths, the weights the book leaves unstated',
    '// (documented); the first band is the human',
    '// three-quarters. Like the R146 tables these are',
    '// fiction-only descriptors dressing the city flavor',
    '// strings - no combat effect. The note says CAN be:',
    '// the fiction never summons the bestiary half-orc /',
    '// goblin / hobgoblin / kobold / orc records.',
    '',
    '// p.191-192: the noble gender coin (2 bands)',
    'static const FlavorBand kNobleKinds[] = {',
    '    {  1, 75, "nobleman" },',
    '    { 76,100, "noblewoman" },',
    '};',
    '',
    '// p.192: the noblewoman ride (2 bands)',
    'static const FlavorBand kSedanKinds[] = {',
    '    {  1, 75, "sedan chair" },',
    '    { 76,100, "on foot" },',
    '};',
    '',
    '// p.191: the ruffian 1-in-4 matrix footnote (6 bands)',
    'static const FlavorBand kRuffianKinds[] = {',
    '    {   1, 75, "human" },',
    '    {  76, 80, "half-orc" },',
    '    {  81, 85, "goblin" },',
    '    {  86, 90, "hobgoblin" },',
    '    {  91, 95, "kobold" },',
    '    {  96,100, "orc" },',
    '};',
    '',
    'const char* cityNobleKind(int pctile) {',
    '    return flavorKindFor(kNobleKinds,',
    '        sizeof kNobleKinds / sizeof kNobleKinds[0], pctile);',
    '}',
    '',
    'const char* cityNoblewomanSedan(int pctile) {',
    '    return flavorKindFor(kSedanKinds,',
    '        sizeof kSedanKinds / sizeof kSedanKinds[0], pctile);',
    '}',
    '',
    'const char* cityRuffianKind(int pctile) {',
    '    return flavorKindFor(kRuffianKinds,',
    '        sizeof kRuffianKinds / sizeof kRuffianKinds[0], pctile);',
    '}',
    '',
    '',
])

# ---- (4) the encounters.h comment ----
p4_old = NL.join([
    '// are pinned R146 - cityDrunkKind / cityHarlotKind; the',
    '// rest stay unmodeled, documented in encounters.cpp).',
])
p4_new = NL.join([
    '// are pinned R146 - cityDrunkKind / cityHarlotKind; the',
    '// noble gender coin, the noblewoman sedan-chair detail',
    '// and the ruffian 1-in-4 note are pinned R174 (the',
    '// declarations below); the rest stay unmodeled,',
    '// documented in encounters.cpp).',
])

# ---- (5) the encounters.h declarations ----
p5_old = NL.join([
    'const char* cityDrunkKind(int pctile);',
    'const char* cityHarlotKind(int pctile);',
])
p5_new = NL.join([
    'const char* cityDrunkKind(int pctile);',
    'const char* cityHarlotKind(int pctile);',
    '',
    '// R174: the two remaining city flavor notes - the noble',
    '// gender coin (nobleman 75% / noblewoman 25%) with the',
    '// noblewoman 75% sedan-chair likelihood (carriers and',
    '// linkboys at night), and the ruffian 1-in-4',
    '// half-orc/humanoid matrix footnote. Fiction-only',
    '// descriptors: 1-100 percentile, 00 reading as 100.',
    'const char* cityNobleKind(int pctile);',
    'const char* cityNoblewomanSedan(int pctile);',
    'const char* cityRuffianKind(int pctile);',
])

# ---- (6) the state_sea.cpp wiring ----
p6_old = NL.join([
    '        } else if (e.key == "harlot") {',
    '            line = std::string("A ") +',
    '                dm::cityHarlotKind(',
    '                    (int)dice.roll(1, 100, 0)) +',
    '                " waves from a doorway.";',
    '        }',
    '        log.add(line);',
])
p6_new = NL.join([
    '        } else if (e.key == "harlot") {',
    '            line = std::string("A ") +',
    '                dm::cityHarlotKind(',
    '                    (int)dice.roll(1, 100, 0)) +',
    '                " waves from a doorway.";',
    '        } else if (e.key == "noble") {',
    '            // R174: the noble gender coin and the',
    '            // noblewoman sedan-chair detail',
    '            std::string gender = dm::cityNobleKind(',
    '                (int)dice.roll(1, 100, 0));',
    '            if (gender == "noblewoman") {',
    '                std::string ride = dm::cityNoblewomanSedan(',
    '                    (int)dice.roll(1, 100, 0));',
    '                if (ride == "sedan chair") {',
    '                    line = "A noblewoman passes in a sedan "',
    '                        "chair, her carriers and guards "',
    '                        "about her.";',
    '                } else {',
    '                    line = "A noblewoman passes on foot "',
    '                        "with servants and guards.";',
    '                }',
    '            } else {',
    '                line = "A nobleman passes with his "',
    '                    "retainers and guards.";',
    '            }',
    '        } else if (e.key == "ruffian") {',
    '            // R174: the 1-in-4 half-orc/humanoid note',
    '            std::string kind = dm::cityRuffianKind(',
    '                (int)dice.roll(1, 100, 0));',
    '            if (kind != "human") {',
    '                line = std::string("Ruffians melt into an "',
    '                    "alley - one in four is ") + kind +',
    '                    " stock.";',
    '            }',
    '        }',
    '        log.add(line);',
])

# ---- (7) the regtest.cpp R174 audit block ----
p7_old = NL.join([
    '        printf("R146 city flavor audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R145: PHB p.38 weapon table audit ----',
])
p7_new = NL.join([
    '        printf("R146 city flavor audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R174: city fiction notes audit ----',
    '    // The two remaining R64 flavor notes, pinned from',
    '    // the fresh DMG upload (p.191-192): the noble',
    '    // gender coin (nobleman-with-retainers 75% /',
    '    // noblewoman 25%, the R149-corrected reading)',
    '    // with the noblewoman 75% sedan-chair likelihood',
    '    // (carriers and linkboys at night), and the',
    '    // ruffian matrix footnote - 1 in 4 half-orc or',
    '    // humanoid (goblin, hobgoblin, kobold, orc),',
    '    // banded as five equal fifths of the quarter',
    '    // (the weights unstated, documented). Every band',
    '    // edge pinned both ways plus the 1-100 sweep.',
    '    {',
    '        int bad = 0;',
    '        // the noble gender coin (p.191): 2 bands',
    '        static const struct { int lo, hi; const char* k; }',
    '            kNoble[] = {',
    '            {  1, 75, "nobleman" },',
    '            { 76,100, "noblewoman" },',
    '        };',
    '        for (int i = 0; i < 2; ++i) {',
    '            if (std::string(dm::cityNobleKind(kNoble[i].lo))',
    '                != kNoble[i].k) ++bad;',
    '            if (std::string(dm::cityNobleKind(kNoble[i].hi))',
    '                != kNoble[i].k) ++bad;',
    '            if (kNoble[i].lo > 1 && std::string(',
    '                    dm::cityNobleKind(kNoble[i].lo - 1))',
    '                == kNoble[i].k) ++bad;',
    '        }',
    '        // the noblewoman ride (p.192): 2 bands',
    '        static const struct { int lo, hi; const char* k; }',
    '            kSedan[] = {',
    '            {  1, 75, "sedan chair" },',
    '            { 76,100, "on foot" },',
    '        };',
    '        for (int i = 0; i < 2; ++i) {',
    '            if (std::string(',
    '                    dm::cityNoblewomanSedan(kSedan[i].lo))',
    '                != kSedan[i].k) ++bad;',
    '            if (std::string(',
    '                    dm::cityNoblewomanSedan(kSedan[i].hi))',
    '                != kSedan[i].k) ++bad;',
    '            if (kSedan[i].lo > 1 && std::string(',
    '                    dm::cityNoblewomanSedan(kSedan[i].lo - 1))',
    '                == kSedan[i].k) ++bad;',
    '        }',
    '        // the ruffian 1-in-4 note (p.191): 6 bands',
    '        static const struct { int lo, hi; const char* k; }',
    '            kRuff[] = {',
    '            {   1, 75, "human" },',
    '            {  76, 80, "half-orc" },',
    '            {  81, 85, "goblin" },',
    '            {  86, 90, "hobgoblin" },',
    '            {  91, 95, "kobold" },',
    '            {  96,100, "orc" },',
    '        };',
    '        for (int i = 0; i < 6; ++i) {',
    '            if (std::string(dm::cityRuffianKind(kRuff[i].lo))',
    '                != kRuff[i].k) ++bad;',
    '            if (std::string(dm::cityRuffianKind(kRuff[i].hi))',
    '                != kRuff[i].k) ++bad;',
    '            if (kRuff[i].lo > 1 && std::string(',
    '                    dm::cityRuffianKind(kRuff[i].lo - 1))',
    '                == kRuff[i].k) ++bad;',
    '        }',
    '        // the sweep: every percentile yields a kind on',
    '        // all three tables (the clamps cover <1 / >100)',
    '        for (int p = 1; p <= 100; ++p) {',
    '            if (!*dm::cityNobleKind(p)) ++bad;',
    '            if (!*dm::cityNoblewomanSedan(p)) ++bad;',
    '            if (!*dm::cityRuffianKind(p)) ++bad;',
    '        }',
    '        printf("R174 city fiction notes audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R145: PHB p.38 weapon table audit ----',
])

# ---- (8) the gap report header note ----
p8_old = NL.join([
    'transcription paraphrases. Census 91.',
    '',
    'Categories:',
])
p8_new = NL.join([
    'transcription paraphrases. Census 91.',
    'R174 PINNED the R146 fiction leftovers (DMG p.191-192)',
    '- the two city flavor notes the R149 book-verify pass',
    'confirmed: the noble gender coin (nobleman-with-',
    'retainers 75% / noblewoman 25%) with the noblewoman',
    '75% sedan-chair likelihood (carriers and linkboys at',
    'night), and the ruffian matrix footnote (1 in 4 can',
    'be half-orc or of humanoid race - goblin, hobgoblin,',
    'kobold, orc - banded as five equal fifths of the',
    'quarter, the weights the book leaves unstated).',
    'Fiction-only descriptors, the R146 precedent:',
    'cityNobleKind / cityNoblewomanSedan / cityRuffianKind',
    'in dm/encounters.cpp, wired to the city streets',
    'excursion lines (game/state_sea.cpp), audited by the',
    'R174 battery block. Census 92.',
    '',
    'Categories:',
])

# ---- (9) the gap report R146 box tail ----
p9_old = NL.join([
    '      note is the printed matrix footnote, confirmed.',
    '      Pinned by the R146 city',
    '      flavor audit; census 64.',
])
p9_new = NL.join([
    '      note is the printed matrix footnote, confirmed.',
    '      R174 CLOSED the pair: the noble gender coin, the',
    '      noblewoman sedan-chair likelihood and the',
    '      ruffian 1-in-4 note are pinned as fiction-only',
    '      descriptors (cityNobleKind / cityNoblewomanSedan',
    '      / cityRuffianKind), audited by the R174 battery',
    '      block. Pinned by the R146 city',
    '      flavor audit; census 64.',
])

# ---- (10) the gap report R146-fiction open box ----
p10_old = NL.join([
    '- [ ] **R146 fiction (the named omissions)** - the',
    '      noble gender hole is CLOSED R149: the split is',
    '      a clean nobleman 75% / noblewoman 25% - a coin',
    '      now, not a table (see the R146 box). The',
    '      ruffian 1-in-4 half-orc/humanoid note and the',
    '      noblewoman 75% sedan-chair detail remain - city',
    '      flavor follow-ups.',
])
p10_new = NL.join([
    '- [x] **R146 fiction (the named omissions)** - CLOSED',
    '      R174: the noble gender coin (nobleman 75% /',
    '      noblewoman 25%, the R149 correction), the',
    '      noblewoman 75% sedan-chair detail and the',
    '      ruffian 1-in-4 half-orc/humanoid note are all',
    '      pinned as fiction-only descriptors',
    '      (cityNobleKind / cityNoblewomanSedan /',
    '      cityRuffianKind), audited by the R174 battery',
    '      block. Census 92.',
])

# ---- run ----
patch("dm/encounters.cpp", p1_old, p1_new,
      "encounters.cpp: R64 header comment",
      marker="pinned R174 (cityNobleKind /")
assert len(applied) + len(already) == 1

patch("dm/encounters.cpp", p2_old, p2_new,
      "encounters.cpp: R146 comment tail",
      marker="R174 pins the two remaining R64 flavor")
assert len(applied) + len(already) == 2

patch("dm/encounters.cpp", p3_old, p3_new,
      "encounters.cpp: R174 flavor block",
      marker="kRuffianKinds")
assert len(applied) + len(already) == 3

patch("dm/encounters.h", p4_old, p4_new,
      "encounters.h: R64 comment amended",
      marker="pinned R174 (the")
assert len(applied) + len(already) == 4

patch("dm/encounters.h", p5_old, p5_new,
      "encounters.h: R174 declarations",
      marker="const char* cityNobleKind(int pctile);")
assert len(applied) + len(already) == 5

patch("game/state_sea.cpp", p6_old, p6_new,
      "state_sea.cpp: noble and ruffian wiring",
      marker="R174: the noble gender coin and the")
assert len(applied) + len(already) == 6

patch("regtest.cpp", p7_old, p7_new,
      "regtest.cpp: R174 audit block",
      marker="R174 city fiction notes audit")
assert len(applied) + len(already) == 7

patch("tools/dmg_gap_report.md", p8_old, p8_new,
      "gap report: R174 header note",
      marker="R174 PINNED the R146 fiction leftovers")
assert len(applied) + len(already) == 8

patch("tools/dmg_gap_report.md", p9_old, p9_new,
      "gap report: R146 box tail amended",
      marker="R174 CLOSED the pair")
assert len(applied) + len(already) == 9

patch("tools/dmg_gap_report.md", p10_old, p10_new,
      "gap report: R146-fiction box closed",
      marker="CLOSED" + NL + "      R174: the noble gender coin")
assert len(applied) + len(already) == 10

# ---- R174 fails/tail ----
if fails:
    print("R174 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 10:
    print("R174 splice: FAIL - expected 10 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R174 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R174 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R174 note: 10 patches; census 92 (one new audit); no")
print("new rules file - the splice md5 is advisory; commit:")
print("R174: R146 fiction leftovers pinned - the noble gender")
print("coin, sedan-chair detail and ruffian 1-in-4 note (census 92)")

