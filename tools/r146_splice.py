#!/usr/bin/env python3
# tools/r146_splice.py - R146 the city flavor subtables:
# the two flavor tables R64 named as unmodeled - the p.191
# drunk identity table ("the character(s) found drunk
# should be diced for", 20 bands) and the p.192 harlot type
# table (12 bands) - pinned as fiction-only descriptors and
# wired into the city streets flavor strings. Cell-verified
# at the raw-HTML level of the 1eonline.info compilation,
# the repo-trusted source; the DMG re-upload's OCR debt
# stands.
#  - dm/encounters.h: cityDrunkKind / cityHarlotKind
#    declared; the R64 comment amended
#  - dm/encounters.cpp: the two band tables + lookup
#    (clamps 1..100); the R64 comment amended
#  - game/state_sea.cpp: the drunk and harlot flavor
#    strings dress with the subtable kinds
#  - regtest.cpp: the R146 city flavor audit (census 64)
#  - tools/dmg_gap_report.md: the R146 box (noble gender
#    and the ruffian humanoid note stay named fiction)
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson).
# This file contains ZERO backslash characters (the
# R133b lesson); the audit printf assembles its escaped
# newline from chr(92).
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

old_h_comment = NL.join([
    '// level ranges; civilian fictions carry printed counts',
    '// (their flavor subtables are fiction the engine does not',
    '// model, documented in encounters.cpp). Numbers are the',
])
new_h_comment = NL.join([
    '// level ranges; civilian fictions carry printed counts',
    '// (their flavor subtables are fiction the engine models',
    '// only in part: the drunk identity and harlot type tables',
    '// are pinned R146 - cityDrunkKind / cityHarlotKind; the',
    '// rest stay unmodeled, documented in encounters.cpp).',
    '// Numbers are the',
])
old_h_anchor = NL.join([
    'std::vector<std::string> cityEncounterKeys(',
    '    const monsters::MonsterRegistry& reg);',
    '',
])
new_h_decl = NL.join([
    'std::vector<std::string> cityEncounterKeys(',
    '    const monsters::MonsterRegistry& reg);',
    '',
    '// R146: the two flavor subtables R64 named as unmodeled -',
    '// the p.191 drunk identity table ("the character(s) found',
    '// drunk should be diced for") and the p.192 harlot type',
    '// table - transcribed from the 1eonline.info compilation',
    "// (the repo-trusted source; the DMG re-upload's OCR debt",
    '// stands). Fiction-only descriptors for the city flavor',
    '// strings: 1-100 percentile, 00 reading as 100.',
    'const char* cityDrunkKind(int pctile);',
    'const char* cityHarlotKind(int pctile);',
    '',
])
old_c_comment = NL.join([
    '// but no bestiary entry - their flavor subtables (harlot type',
    '// p.192, drunk-of-what-type p.191, noble gender, ruffian 1-in-4',
    '// half-orc/humanoid) are fiction the engine does not model,',
    '// documented in the row comments.',
])
new_c_comment = NL.join([
    '// but no bestiary entry - their flavor subtables are',
    '// fiction the engine models only in part: the harlot type',
    '// (p.192) and drunk-of-what-type (p.191) tables are',
    '// pinned R146 (cityHarlotKind / cityDrunkKind); noble',
    '// gender and the ruffian 1-in-4 half-orc/humanoid note',
    '// stay unmodeled fiction, documented in the row',
    '// comments.',
])
old_c_anchor = NL.join([
    '    (void)reg;',
    '    return out;',
    '}',
    '',
    '',
    '// ----------------------------------------------------------------------------',
    '// R65: the ASTRAL & ETHEREAL encounter tables - DMG Appendix C',
])
new_c_impl = NL.join([
    '    (void)reg;',
    '    return out;',
    '}',
    '',
    '// ----------------------------------------------------------------------------',
    '// R146: the city flavor subtables R64 named as unmodeled -',
    '// the p.191 drunk identity table ("the character(s) found',
    '// drunk should be diced for") and the p.192 harlot type',
    '// table, both transcribed from the 1eonline.info',
    "// compilation (the repo-trusted source; the DMG re-upload's",
    "// OCR debt stands). Fiction-only descriptors: the app's",
    '// cityFlavor strings dress the "drunk" and "harlot" rows',
    '// with them; no combat effect. The book prints "MU" and',
    '// "Merc" in full as the fiction strings (magic-user,',
    '// mercenary); the printed book reads "haughty", the',
    '// compilation "Haughy" an OCR defect (corrected,',
    '// documented). The two remaining R64 flavor notes - noble',
    '// gender (70% nobleman / 25% noblewoman, the last 5%',
    '// unprinted) and the ruffian 1-in-4 half-orc/humanoid note',
    '// - stay unmodeled fiction (gap report).',
    'namespace {',
    '',
    'struct FlavorBand {',
    '    short lo, hi;',
    '    const char* kind;',
    '};',
    '',
    "// p.191: the drunk's dice-for identity (20 bands)",
    'static const FlavorBand kDrunkKinds[] = {',
    '    {   1,  2, "assassin" },',
    '    {   3,10, "bandit" },',
    '    { 11,18, "brigand" },',
    '    { 19,20, "city guard" },',
    '    { 21,22, "city official" },',
    '    { 23,25, "city watchman" },',
    '    { 26,27, "cleric" },',
    '    { 28,29, "druid" },',
    '    { 30,38, "fighter" },',
    '    { 39,45, "gentleman" },',
    '    { 46,48, "illusionist" },',
    '    { 49,63, "laborer" },',
    '    { 64,65, "magic-user" },',
    '    { 66,73, "mercenary" },',
    '    { 74,80, "merchant" },',
    '    { 81,82, "noble" },',
    '    { 83,90, "rake" },',
    '    { 91,95, "ruffian" },',
    '    { 96,97, "thief" },',
    '    { 98,100, "tradesman" },',
    '};',
    '',
    '// p.192: the harlot encounter type (12 bands)',
    'static const FlavorBand kHarlotKinds[] = {',
    '    {   1,10, "slovenly trull" },',
    '    { 11,25, "brazen strumpet" },',
    '    { 26,35, "cheap trollop" },',
    '    { 36,50, "typical streetwalker" },',
    '    { 51,65, "saucy tart" },',
    '    { 66,75, "wanton wench" },',
    '    { 76,85, "expensive doxy" },',
    '    { 86,90, "haughty courtesan" },',
    '    { 91,92, "aged madam" },',
    '    { 93,94, "wealthy procuress" },',
    '    { 95,98, "sly pimp" },',
    '    { 99,100, "rich panderer" },',
    '};',
    '',
    'const char* flavorKindFor(const FlavorBand* t, size_t n,',
    '                          int pctile) {',
    '    if (pctile < 1)   pctile = 1;',
    '    if (pctile > 100) pctile = 100;',
    '    for (size_t i = 0; i < n; ++i)',
    '        if (pctile >= t[i].lo && pctile <= t[i].hi)',
    '            return t[i].kind;',
    '    return "";',
    '}',
    '',
    '}   // namespace',
    '',
    'const char* cityDrunkKind(int pctile) {',
    '    return flavorKindFor(kDrunkKinds,',
    '        sizeof kDrunkKinds / sizeof kDrunkKinds[0], pctile);',
    '}',
    '',
    'const char* cityHarlotKind(int pctile) {',
    '    return flavorKindFor(kHarlotKinds,',
    '        sizeof kHarlotKinds / sizeof kHarlotKinds[0], pctile);',
    '}',
    '',
    '',
    '',
    '// ----------------------------------------------------------------------------',
    '// R65: the ASTRAL & ETHEREAL encounter tables - DMG Appendix C',
])
old_sea = NL.join([
    '        // fiction civilians - flavor only',
    '        log.add(cityFlavor(e.key.c_str()));',
    '    }',
])
new_sea = NL.join([
    '        // fiction civilians - flavor only; R146: the',
    '        // p.191 drunk identity and p.192 harlot type',
    '        // subtables dress the two keyed rows',
    '        std::string line = cityFlavor(e.key.c_str());',
    '        if (e.key == "drunk") {',
    '            line = std::string("A drunk ") +',
    '                dm::cityDrunkKind(',
    '                    (int)dice.roll(1, 100, 0)) +',
    '                " sings loud in a doorway.";',
    '        } else if (e.key == "harlot") {',
    '            line = std::string("A ") +',
    '                dm::cityHarlotKind(',
    '                    (int)dice.roll(1, 100, 0)) +',
    '                " waves from a doorway.";',
    '        }',
    '        log.add(line);',
    '    }',
])
old_r145_head = NL.join([
    '    // ---- R145: PHB p.38 weapon table audit ----',
])
r146_audit = NL.join([
    '    // ---- R146: city flavor subtables audit ----',
    '    // The two flavor subtables R64 named as unmodeled:',
    '    // the p.191 drunk identity table ("the character(s)',
    '    // found drunk should be diced for") and the p.192',
    '    // harlot type table, both cell-verified at the',
    '    // raw-HTML level of the 1eonline.info compilation -',
    "    // the repo-trusted source; the DMG re-upload's OCR",
    "    // debt stands (the compilation's 'Haughy' is the",
    "    // printed 'haughty', corrected). Fiction-only",
    '    // descriptors; every band edge pinned both ways: at',
    '    // the edge the kind, one below the edge the next.',
    '    {',
    '        int bad = 0;',
    "        // the drunk's dice-for identity (p.191): 20 bands",
    '        static const struct { int lo, hi; const char* k; }',
    '            kDrunk[] = {',
    '            {   1,  2, "assassin" },',
    '            {   3,10, "bandit" },',
    '            { 11,18, "brigand" },',
    '            { 19,20, "city guard" },',
    '            { 21,22, "city official" },',
    '            { 23,25, "city watchman" },',
    '            { 26,27, "cleric" },',
    '            { 28,29, "druid" },',
    '            { 30,38, "fighter" },',
    '            { 39,45, "gentleman" },',
    '            { 46,48, "illusionist" },',
    '            { 49,63, "laborer" },',
    '            { 64,65, "magic-user" },',
    '            { 66,73, "mercenary" },',
    '            { 74,80, "merchant" },',
    '            { 81,82, "noble" },',
    '            { 83,90, "rake" },',
    '            { 91,95, "ruffian" },',
    '            { 96,97, "thief" },',
    '            { 98,100, "tradesman" },',
    '        };',
    '        for (int i = 0; i < 20; ++i) {',
    '            if (std::string(dm::cityDrunkKind(kDrunk[i].lo))',
    '                != kDrunk[i].k) ++bad;',
    '            if (std::string(dm::cityDrunkKind(kDrunk[i].hi))',
    '                != kDrunk[i].k) ++bad;',
    '            if (kDrunk[i].lo > 1 && std::string(',
    '                    dm::cityDrunkKind(kDrunk[i].lo - 1))',
    '                == kDrunk[i].k) ++bad;',
    '        }',
    "        // the harlot's type (p.192): 12 bands",
    '        static const struct { int lo, hi; const char* k; }',
    '            kHarlot[] = {',
    '            {   1,10, "slovenly trull" },',
    '            { 11,25, "brazen strumpet" },',
    '            { 26,35, "cheap trollop" },',
    '            { 36,50, "typical streetwalker" },',
    '            { 51,65, "saucy tart" },',
    '            { 66,75, "wanton wench" },',
    '            { 76,85, "expensive doxy" },',
    '            { 86,90, "haughty courtesan" },',
    '            { 91,92, "aged madam" },',
    '            { 93,94, "wealthy procuress" },',
    '            { 95,98, "sly pimp" },',
    '            { 99,100, "rich panderer" },',
    '        };',
    '        for (int i = 0; i < 12; ++i) {',
    '            if (std::string(dm::cityHarlotKind(kHarlot[i].lo))',
    '                != kHarlot[i].k) ++bad;',
    '            if (std::string(dm::cityHarlotKind(kHarlot[i].hi))',
    '                != kHarlot[i].k) ++bad;',
    '            if (kHarlot[i].lo > 1 && std::string(',
    '                    dm::cityHarlotKind(kHarlot[i].lo - 1))',
    '                == kHarlot[i].k) ++bad;',
    '        }',
    '        // the sweep: every percentile yields a kind on',
    '        // both tables (the clamps cover <1 / >100)',
    '        for (int p = 1; p <= 100; ++p) {',
    '            if (!*dm::cityDrunkKind(p)) ++bad;',
    '            if (!*dm::cityHarlotKind(p)) ++bad;',
    '        }',
    '        printf(' + chr(34) + 'R146 city flavor audit: bad %d' + BS + 'n' + chr(34) + ', bad);',
    '        if (bad) return 1;',
    '    }',
    '',
])
old_gap = NL.join([
    '      weapon table audit; census 63.',
    '',
    '## Out of scope by design',
])
new_gap = NL.join([
    '      weapon table audit; census 63.',
    "- [x] **The city flavor subtables (R64's named omissions)**",
    '      - CLOSED R146: the p.191 drunk identity table ("the',
    '      character(s) found drunk should be diced for" - 20',
    '      bands, assassin 01-02 through tradesman 98-00) and',
    '      the famous p.192 harlot type table (12 bands, the',
    '      slovenly trull 01-10 through the rich panderer',
    '      99-00 - Gygax, on why the table exists: built from',
    "      boredom with the genre's continual 'whores'",
    '      references, included in a spirit of',
    '      vocabulary-building, "no particular regrets") are',
    '      pinned as fiction-only descriptors and wired into',
    "      the city streets flavor strings (the book's MU /",
    "      Merc print in full; the compilation's 'Haughy",
    "      courtesan' is the printed 'haughty', corrected and",
    '      documented). Cell-verified at the raw-HTML level of',
    '      the 1eonline.info compilation - the repo-trusted',
    "      source; the DMG re-upload's OCR debt stands. Still",
    '      unmodeled fiction, named: noble gender (the book',
    '      prints nobleman-with-retainers 70% / noblewoman 25%',
    '      and no last 5%) and the ruffian 1-in-4',
    '      half-orc/humanoid note. Pinned by the R146 city',
    '      flavor audit; census 64.',
    '',
    '## Out of scope by design',
])
patch("dm/encounters.h", old_h_comment, new_h_comment,
      "encounters.h: R64 comment amended",
      marker="pinned R146 - cityDrunkKind")
assert len(applied) + len(already) == 1

patch("dm/encounters.h", old_h_anchor, new_h_decl,
      "encounters.h: R146 decls",
      marker="cityHarlotKind(int pctile)")
assert len(applied) + len(already) == 2

patch("dm/encounters.cpp", old_c_comment, new_c_comment,
      "encounters.cpp: R64 comment amended",
      marker="pinned R146 (cityHarlotKind")
assert len(applied) + len(already) == 3

patch("dm/encounters.cpp", old_c_anchor, new_c_impl,
      "encounters.cpp: R146 tables + lookup",
      marker="kHarlotKinds")
assert len(applied) + len(already) == 4

patch("game/state_sea.cpp", old_sea, new_sea,
      "state_sea.cpp: flavor wiring",
      marker="dm::cityHarlotKind(")
assert len(applied) + len(already) == 5

patch("regtest.cpp", old_r145_head + NL,
      r146_audit + old_r145_head + NL,
      "regtest.cpp: R146 audit",
      marker="R146 city flavor audit")
assert len(applied) + len(already) == 6

patch("tools/dmg_gap_report.md", old_gap, new_gap,
      "gap report: R146 box", marker="CLOSED R146:")
assert len(applied) + len(already) == 7

# ---- R146 fails/tail ----
if fails:
    print("R146 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 7:
    print("R146 splice: FAIL - expected 7 patches, "
          "counted " + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R146 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R146 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
