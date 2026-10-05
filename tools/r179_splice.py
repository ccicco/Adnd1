#!/usr/bin/env python3
# tools/r179_splice.py - R179: the six subclass
# foundations pinned - the registry round.
#
# The arc foundations (the R178 scope, data-driven
# per the standing scope - a future class lands as
# one appended row):
#
#   (a) rules/subclasses.h CREATED - the subclass
#       registry: struct SubclassDef (base class,
#       group, level cap, fixed hp past the cap,
#       hit die, the XP attain rows, the per-level
#       adder, the title ladder, the prime
#       requisite) and the six pinned defs -
#       paladin, ranger, druid, illusionist,
#       assassin, monk - from the printed
#       subclass tables (PHB pp.20-31 and the
#       class sections). Convention: XP to attain
#       = the printed band lower bound - 1 (the
#       R176 convention). JUDGMENTs: the ranger and
#       monk first level carries TWO dice (the
#       printed accumulated column reads 2); the
#       druid, assassin and monk tables print no
#       adder past the top row - pinned as adder
#       0, the printed top is the ceiling; the
#       monk has no base class (its own class,
#       base -1); the ranger and monk carry
#       multiple primes (noted per def, the
#       primary returned).
#   (b) regtest.cpp - a NEW R179 audit block after
#       the R178c audit: the registry walk (six
#       defs, every XP row, every title, the caps,
#       the hit dice, the adders, the clamps)
#       (census 96 - one new audit printf).
#   (c) tools/phb_gap_report.md - the R179 arc box
#       flips to pinned; the round note is added.
#   (d) tools/dmg_gap_report.md - the round-note
#       chain gains the R179 note.
#
# Idempotent: safe to run twice; a silent run means
# the paste was truncated - this tail ALWAYS prints.
# An assert follows EVERY patch (the R142 lesson).
# ZERO backslash characters (the C newline is built
# from chr(92)), and no content string embeds a
# literal apostrophe. The created-file md5 is the
# real gate (the R172 convention).
# Commit: "R179: the six subclass foundations pinned -
# the registry round (census 96)"
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

# ---- (a) rules/subclasses.h CREATED ----
HEADER = NL.join([
    "// ============================================================================",
    "// Adnd1 - rules/subclasses.h",
    "// The subclass registry (R179, the arc foundations).",
    "//",
    "// The six PHB subclasses pinned from the printed class",
    "// tables: paladin and ranger (the fighter group), druid",
    "// (the cleric group), illusionist (the magic-user group),",
    "// assassin (the thief group), and the monk - its own",
    "// class, no base. Convention: the XP to ATTAIN a level is",
    "// the printed band lower bound - 1 (the R176 convention).",
    "//",
    "// JUDGMENTs:",
    "//   - the ranger and the monk first level carries TWO hit",
    "//     dice (the printed accumulated column reads 2 at",
    "//     level 1); the hit-die rolling wiring lands with the",
    "//     later arc rounds.",
    "//   - the druid, assassin and monk tables print no adder",
    "//     past the top row - pinned as adder 0; the printed",
    "//     top level is the ceiling (the druid hierarchy, the",
    "//     assassin and monk tables end there).",
    "//   - the ranger primes are strength, intelligence and",
    "//     wisdom (all three, the print); the def returns the",
    "//     primary. The monk likewise strength, wisdom and",
    "//     dexterity. The druid double-primes wisdom and",
    "//     charisma.",
    "//   - the paladin and ranger join the fighter CON bonus",
    "//     group (CON 17 +3, 18 +4 - the print includes the",
    "//     fighter subclasses).",
    "//   - the caps are the fixed-hp levels: the printed gain",
    "//     X hp per level past the cap (paladin 3 past the",
    "//     9th, ranger 2 past the 10th, druid 2 past the 9th,",
    "//     illusionist 1 past the 10th, assassin 2 past the",
    "//     10th; the monk rolls through its 17 printed",
    "//     levels - hpBeyond 0).",
    "//",
    "// DATA-DRIVEN (the standing scope): a future class from",
    "// a later sourcebook lands as ONE appended row - a def",
    "// block, a bump of SUB_COUNT, and its battery rows.",
    "// ============================================================================",
    "",
    "#pragma once",
    "",
    "#include <cstdint>",
    "",
    "namespace rules {",
    "",
    "// The subclass indices (stable; append only)",
    "enum Subclass : int {",
    "    SUB_PALADIN = 0,",
    "    SUB_RANGER = 1,",
    "    SUB_DRUID = 2,",
    "    SUB_ILLUSIONIST = 3,",
    "    SUB_ASSASSIN = 4,",
    "    SUB_MONK = 5,",
    "    SUB_COUNT = 6",
    "};",
    "",
    "// One registry row. xpRows[i] is the XP to attain",
    "// level i+1 (the printed band lower bound - 1).",
    "struct SubclassDef {",
    "    const char* name;",
    "    int base;           // the base CharClass, or -1 (monk)",
    "    int group;          // the ClassGroup from classes.h",
    "    int levelCap;       // past this level, fixed hp",
    "    int hpBeyondCap;    // the fixed hp per level past the cap",
    "    int hitDie;         // 4 / 6 / 8 / 10",
    "    int twoDiceFirstLevel;  // 1 if level 1 carries two dice",
    "    const int* xpRows;      // the printed attain rows",
    "    int xpRowCount;",
    "    int xpAdder;       // per level past the printed rows",
    "    const char* const* titles;   // the printed ladder",
    "    int titleCount;    // == xpRowCount",
    "    int prime;         // the primary prime requisite",
    "};",
    "",
    "// ---- the printed rows (PHB pp.21-31, the class sections) ----",
    "",
    "// Paladin: 0-2750 ... 1,050,001-1,400,000 (11th);",
    "// 350,000 per level above the 11th; 3 hp past the 9th.",
    "static const int kXpPaladin[11] = {",
    "        0,   2750,   5500,  12000,  24000,",
    "    45000,  95000, 175000, 350000, 700000,",
    "  1050000",
    "};",
    "static const char* const kTitlePaladin[11] = {",
    '    "Gallant", "Keeper", "Protector", "Defender",',
    '    "Warder", "Guardian", "Chevalier", "Justiciar",',
    '    "Paladin",',
    '    "Paladin (10th level)", "Paladin (11th level)"',
    "};",
    "",
    "// Ranger: 0-2250 ... 975,001-1,300,000 (12th);",
    "// 325,000 per level above the 12th; 2 hp past the",
    "// 10th; level 1 carries two d8.",
    "static const int kXpRanger[12] = {",
    "        0,   2250,   4500,  10000,  20000,",
    "    40000,  90000, 150000, 225000, 325000,",
    "   650000,  975000",
    "};",
    "static const char* const kTitleRanger[12] = {",
    '    "Runner", "Strider", "Scout", "Courser",',
    '    "Tracker", "Guide", "Pathfinder", "Ranger",',
    '    "Ranger Knight", "Ranger Lord",',
    '    "Ranger Lord (11th level)", "Ranger Lord (12th level)"',
    "};",
    "",
    "// Druid: 0-2000 ... 1,500,001 (the 14th, the Great",
    "// Druid); no printed adder - the hierarchy ceiling;",
    "// 2 hp past the 9th.",
    "static const int kXpDruid[14] = {",
    "        0,   2000,   4000,   7500,  12500,",
    "    20000,  35000,  60000,  90000, 125000,",
    "   200000,  300000,  750000, 1500000",
    "};",
    "static const char* const kTitleDruid[14] = {",
    '    "Aspirant", "Ovate",',
    '    "Initiate of the 1st Circle", "Initiate of the 2nd Circle",',
    '    "Initiate of the 3rd Circle", "Initiate of the 4th Circle",',
    '    "Initiate of the 5th Circle", "Initiate of the 6th Circle",',
    '    "Initiate of the 7th Circle", "Initiate of the 8th Circle",',
    '    "Initiate of the 9th Circle", "Druid",',
    '    "Archdruid", "The Great Druid"',
    "};",
    "",
    "// Illusionist: 0-2250 ... 660,001-880,000 (12th);",
    "// 220,000 per level beyond the 12th; 1 hp past the",
    "// 10th.",
    "static const int kXpIllusionist[12] = {",
    "        0,   2250,   4500,   9000,  18000,",
    "    35000,  60000,  95000, 145000, 220000,",
    "   440000,  660000",
    "};",
    "static const char* const kTitleIllusionist[12] = {",
    '    "Prestidigitator", "Minor Trickster", "Trickster",',
    '    "Master Trickster", "Cabalist", "Visionist",',
    '    "Phantasmist", "Apparitionist", "Spellbinder",',
    '    "Illusionist",',
    '    "Illusionist (11th level)", "Illusionist (12th level)"',
    "};",
    "",
    "// Assassin: 0-1500 ... 1,500,001 and over (the 15th,",
    "// the Grandfather of Assassins); no printed adder;",
    "// 2 hp past the 10th.",
    "static const int kXpAssassin[15] = {",
    "        0,   1500,   3000,   6000,  12000,",
    "    25000,  50000, 100000, 200000, 300000,",
    "   425000,  575000,  750000, 1000000, 1500000",
    "};",
    "static const char* const kTitleAssassin[15] = {",
    '    "Bravo (Apprentice)", "Rutterkin", "Waghalter",',
    '    "Murderer", "Thug", "Killer", "Cutthroat",',
    '    "Executioner", "Assassin", "Expert Assassin",',
    '    "Senior Assassin", "Chief Assassin",',
    '    "Prime Assassin", "Guildmaster Assassin",',
    '    "Grandfather of Assassins"',
    "};",
    "",
    "// Monk: 0-2250 ... 3,250,001 and up (the 17th, the",
    "// Grand Master of Flowers); no printed adder;",
    "// level 1 carries two d4; hp rolls through all 17.",
    "static const int kXpMonk[17] = {",
    "        0,   2250,   4750,  10000,  22500,",
    "    47500,  98000, 200000, 350000, 500000,",
    "   700000,  950000, 1250000, 1750000, 2250000,",
    "  2750000, 3250000",
    "};",
    "static const char* const kTitleMonk[17] = {",
    '    "Novice", "Initiate", "Brother", "Disciple",',
    '    "Immaculate", "Master", "Superior Master",',
    '    "Master of Dragons",',
    '    "Master of the North Wind", "Master of the West Wind",',
    '    "Master of the South Wind", "Master of the East Wind",',
    '    "Master of Winter", "Master of Autumn",',
    '    "Master of Summer", "Master of Spring",',
    '    "Grand Master of Flowers"',
    "};",
    "",
    "// ---- the registry (append a row per new class) ----",
    "",
    "static const SubclassDef SUB_DEFS[SUB_COUNT] = {",
    "    // paladin: fighter base, fighter group,",
    "    // 3 hp past the 9th, d10, STR prime",
    '    { "paladin", 0, 0, 9, 3, 10, 0,',
    "      kXpPaladin, 11, 350000,",
    "      kTitlePaladin, 11, 0 },",
    "    // ranger: fighter base, fighter group,",
    "    // 2 hp past the 10th, d8, two dice at level 1,",
    "    // STR prime (with INT and WIS - the print)",
    '    { "ranger", 0, 0, 10, 2, 8, 1,',
    "      kXpRanger, 12, 325000,",
    "      kTitleRanger, 12, 0 },",
    "    // druid: cleric base, priest group,",
    "    // 2 hp past the 9th, d8, WIS prime (with CHA)",
    '    { "druid", 2, 1, 14, 2, 8, 0,',
    "      kXpDruid, 14, 0,",
    "      kTitleDruid, 14, 2 },",
    "    // illusionist: magic-user base, wizard group,",
    "    // 1 hp past the 10th, d4, INT prime",
    '    { "illusionist", 1, 2, 10, 1, 4, 0,',
    "      kXpIllusionist, 12, 220000,",
    "      kTitleIllusionist, 12, 1 },",
    "    // assassin: thief base, rogue group,",
    "    // 2 hp past the 10th, d6, DEX prime",
    '    { "assassin", 3, 3, 10, 2, 6, 0,',
    "      kXpAssassin, 15, 0,",
    "      kTitleAssassin, 15, 3 },",
    "    // monk: no base class (its own), fighter-ish",
    "    // group pending the specials round, d4, two",
    "    // dice at level 1, STR prime (with WIS and DEX)",
    '    { "monk", -1, 3, 17, 0, 4, 1,',
    "      kXpMonk, 17, 0,",
    "      kTitleMonk, 17, 0 },",
    "};",
    "",
    "// ---- accessors ----",
    "",
    "inline int subclassCount() { return SUB_COUNT; }",
    "",
    "inline const SubclassDef& subclassDef(int i) {",
    "    if (i < 0) i = 0;",
    "    if (i >= SUB_COUNT) i = SUB_COUNT - 1;",
    "    return SUB_DEFS[i];",
    "}",
    "",
    "// The XP to ATTAIN the given level (the R176",
    "// convention). Past the printed rows, the adder",
    "// applies (adder 0: the printed top is the",
    "// ceiling, the top row repeats).",
    "inline int subclassXpFor(int i, int level) {",
    "    const SubclassDef& d = subclassDef(i);",
    "    if (level <= 1) return 0;",
    "    if (level <= d.xpRowCount)",
    "        return d.xpRows[level - 1];",
    "    return d.xpRows[d.xpRowCount - 1]",
    "         + (level - d.xpRowCount) * d.xpAdder;",
    "}",
    "",
    "// The printed title for the level (clamped)",
    "inline const char* subclassTitle(int i, int level) {",
    "    const SubclassDef& d = subclassDef(i);",
    "    if (level < 1) level = 1;",
    "    if (level > d.titleCount) level = d.titleCount;",
    "    return d.titles[level - 1];",
    "}",
    "",
    "} // namespace rules",
])

def patch_create():
    p = os.path.join(ROOT, "rules/subclasses.h")
    if os.path.exists(p):
        with open(p, encoding="ascii") as f:
            s = f.read()
        if "R179, the arc foundations" in s:
            already.append("rules/subclasses.h created")
        else:
            fails.append("rules/subclasses.h exists without "
                         "the R179 marker")
        return
    wr("rules/subclasses.h", HEADER)
    applied.append("rules/subclasses.h created")

patch_create()
assert len(applied) + len(already) == 1

# ---- (b) the regtest R179 audit block ----
p2_old = NL.join([
    '        printf("R178c DEX and CON tables audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R163: the poison table audit -------------',
])
p2_new = NL.join([
    '        printf("R178c DEX and CON tables audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R179: the subclass registry audit -------',
    '    // The six pinned subclass defs from the printed',
    '    // PHB class tables: the XP attain rows cell by',
    '    // cell, the title ladders, the caps, the hit',
    '    // dice, the two-dice first levels (ranger,',
    '    // monk), the adders, the base-class map, and',
    '    // the clamps (the R176 attain convention).',
    '    {',
    '        int bad = 0;',
    '        if (rules::subclassCount() != 6) ++bad;',
    '        // the base-class map: paladin fighter,',
    '        // ranger fighter, druid cleric,',
    '        // illusionist MU, assassin thief, monk none',
    '        static const int kBase[6] = { 0, 0, 2, 1, 3, -1 };',
    '        static const int kCap[6]  = { 9, 10, 14, 10, 10, 17 };',
    '        static const int kHpB[6]  = { 3, 2, 2, 1, 2, 0 };',
    '        static const int kDie[6]  = { 10, 8, 8, 4, 6, 4 };',
    '        static const int kTwo[6]  = { 0, 1, 0, 0, 0, 1 };',
    '        static const int kRows[6] = { 11, 12, 14, 12, 15, 17 };',
    '        static const int kAdder[6] = { 350000, 325000, 0,',
    '                                     220000, 0, 0 };',
    '        static const int kXpPal[11] = {',
    '            0, 2750, 5500, 12000, 24000,',
    '            45000, 95000, 175000, 350000, 700000, 1050000',
    '        };',
    '        static const int kXpRng[12] = {',
    '            0, 2250, 4500, 10000, 20000,',
    '            40000, 90000, 150000, 225000, 325000,',
    '            650000, 975000',
    '        };',
    '        static const int kXpDru[14] = {',
    '            0, 2000, 4000, 7500, 12500,',
    '            20000, 35000, 60000, 90000, 125000,',
    '            200000, 300000, 750000, 1500000',
    '        };',
    '        static const int kXpIll[12] = {',
    '            0, 2250, 4500, 9000, 18000,',
    '            35000, 60000, 95000, 145000, 220000,',
    '            440000, 660000',
    '        };',
    '        static const int kXpAsn[15] = {',
    '            0, 1500, 3000, 6000, 12000,',
    '            25000, 50000, 100000, 200000, 300000,',
    '            425000, 575000, 750000, 1000000, 1500000',
    '        };',
    '        static const int kXpMnk[17] = {',
    '            0, 2250, 4750, 10000, 22500,',
    '            47500, 98000, 200000, 350000, 500000,',
    '            700000, 950000, 1250000, 1750000,',
    '            2250000, 2750000, 3250000',
    '        };',
    '        for (int i = 0; i < 6; ++i) {',
    '            const rules::SubclassDef& d =',
    '                rules::subclassDef(i);',
    '            if (d.base != kBase[i]) ++bad;',
    '            if (d.levelCap != kCap[i]) ++bad;',
    '            if (d.hpBeyondCap != kHpB[i]) ++bad;',
    '            if (d.hitDie != kDie[i]) ++bad;',
    '            if (d.twoDiceFirstLevel != kTwo[i]) ++bad;',
    '            if (d.xpRowCount != kRows[i]) ++bad;',
    '            if (d.xpAdder != kAdder[i]) ++bad;',
    '            if (d.titleCount != d.xpRowCount) ++bad;',
    '        }',
    '        for (int l = 1; l <= 11; ++l)',
    '            if (rules::subclassXpFor(0, l) != kXpPal[l-1]) ++bad;',
    '        for (int l = 1; l <= 12; ++l)',
    '            if (rules::subclassXpFor(1, l) != kXpRng[l-1]) ++bad;',
    '        for (int l = 1; l <= 14; ++l)',
    '            if (rules::subclassXpFor(2, l) != kXpDru[l-1]) ++bad;',
    '        for (int l = 1; l <= 12; ++l)',
    '            if (rules::subclassXpFor(3, l) != kXpIll[l-1]) ++bad;',
    '        for (int l = 1; l <= 15; ++l)',
    '            if (rules::subclassXpFor(4, l) != kXpAsn[l-1]) ++bad;',
    '        for (int l = 1; l <= 17; ++l)',
    '            if (rules::subclassXpFor(5, l) != kXpMnk[l-1]) ++bad;',
    '        // the adder probes: paladin, ranger,',
    '        // illusionist; the ceiling rows repeat for',
    '        // the adder-0 defs',
    '        if (rules::subclassXpFor(0, 12) != 1400000 ||',
    '            rules::subclassXpFor(0, 13) != 1750000) ++bad;',
    '        if (rules::subclassXpFor(1, 13) != 1300000 ||',
    '            rules::subclassXpFor(1, 14) != 1625000) ++bad;',
    '        if (rules::subclassXpFor(3, 13) != 880000 ||',
    '            rules::subclassXpFor(3, 14) != 1100000) ++bad;',
    '        if (rules::subclassXpFor(2, 15) != 1500000 ||',
    '            rules::subclassXpFor(4, 16) != 1500000 ||',
    '            rules::subclassXpFor(5, 18) != 3250000) ++bad;',
    '        // title spot rows and clamps',
    '        if (std::string(rules::subclassTitle(0, 9))',
    '            != "Paladin") ++bad;',
    '        if (std::string(rules::subclassTitle(1, 8))',
    '            != "Ranger") ++bad;',
    '        if (std::string(rules::subclassTitle(2, 14))',
    '            != "The Great Druid") ++bad;',
    '        if (std::string(rules::subclassTitle(3, 10))',
    '            != "Illusionist") ++bad;',
    '        if (std::string(rules::subclassTitle(4, 15))',
    '            != "Grandfather of Assassins") ++bad;',
    '        if (std::string(rules::subclassTitle(5, 17))',
    '            != "Grand Master of Flowers") ++bad;',
    '        if (std::string(rules::subclassTitle(5, 1))',
    '            != "Novice") ++bad;',
    '        if (std::string(rules::subclassTitle(0, 0))',
    '            != "Gallant") ++bad;',
    '        if (std::string(rules::subclassTitle(0, 99))',
    '            != "Paladin (11th level)") ++bad;',
    '        if (rules::subclassXpFor(0, 0) != 0 ||',
    '            rules::subclassXpFor(5, -3) != 0) ++bad;',
    '        printf("R179 subclass registry audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R163: the poison table audit -------------',
])

s = rd("regtest.cpp")
if "R179 subclass registry audit" in s:
    already.append("regtest.cpp: R179 audit block")
else:
    n = s.count(p2_old)
    if n != 1:
        fails.append("regtest.cpp R179 audit: anchor count "
                     + str(n) + " (expected 1)")
    else:
        wr("regtest.cpp", s.replace(p2_old, p2_new))
        applied.append("regtest.cpp: R179 audit block")
assert len(applied) + len(already) == 2

# ---- (c) the phb report: the R179 arc box flips ----
p3_old = NL.join([
    '- R179 the six subclass foundations - the class',
    '      registry grows (new indices past the four',
    '      base classes), per-class level caps, hit',
    '      dice, the HP-beyond-cap convention, the XP',
    '      rows and the title ladders from the printed',
    '      subclass tables (PALADINS, RANGERS, DRUIDS,',
    '      ILLUSIONISTS, ASSASSINS, MONKS tables).',
])
p3_new = NL.join([
    '- [x] R179 the six subclass foundations - PINNED:',
    '      rules/subclasses.h CREATED (the data-driven',
    '      registry - a future class lands as one',
    '      appended row): struct SubclassDef with the',
    '      base-class map (paladin/ranger fighter,',
    '      druid cleric, illusionist MU, assassin',
    '      thief, monk none), the caps with the',
    '      fixed-hp-past-cap convention (paladin 9/+3,',
    '      ranger 10/+2, druid 9/+2, illusionist 10/+1,',
    '      assassin 10/+2, monk 17 rolls through), the',
    '      hit dice (d10/d8/d8/d4/d6/d4), the XP attain',
    '      rows cell by cell from the printed tables',
    '      (the R176 convention), the adders (350k',
    '      paladin past the 11th, 325k ranger past the',
    '      12th, 220k illusionist past the 12th; the',
    '      druid, assassin and monk print none -',
    '      ceiling rows), and the full title ladders',
    '      (11/12/14/12/15/17 titles). JUDGMENTs: the',
    '      ranger and monk level 1 carries two dice',
    '      (the printed accumulated column reads 2);',
    '      the ranger primes STR+INT+WIS, the monk',
    '      STR+WIS+DEX, the druid WIS+CHA (the primary',
    '      returned). The R179 battery audit walks',
    '      every row, title, cap and clamp. Census 96.',
])

s = rd("tools/phb_gap_report.md")
if "PINNED:" + NL + "      rules/subclasses.h CREATED" in s:
    already.append("phb report: R179 box flipped")
else:
    n = s.count(p3_old)
    if n != 1:
        fails.append("phb report R179 box: anchor count "
                     + str(n) + " (expected 1)")
    else:
        wr("tools/phb_gap_report.md", s.replace(p3_old, p3_new))
        applied.append("phb report: R179 box flipped")
assert len(applied) + len(already) == 3

# ---- (d) the dmg report round note ----
p4_old = NL.join([
    'accessor retired. New R178c battery audit;',
    'census 95.',
])
p4_new = NL.join([
    'accessor retired. New R178c battery audit;',
    'census 95.',
    'R179 PINNED the six subclass foundations (the',
    'arc registry round): rules/subclasses.h CREATED,',
    'data-driven - the six PHB subclasses with the',
    'base-class map, caps, hit dice, the XP attain',
    'rows and title ladders from the printed tables,',
    'the adders, and the two-dice first levels',
    '(ranger, monk). New R179 battery audit; census',
    '96. The wiring rounds follow (qualification,',
    'attacks, spells, multi-class, the bard).',
])

s = rd("tools/dmg_gap_report.md")
if "R179 PINNED the six subclass foundations" in s:
    already.append("dmg report: R179 round note")
else:
    n = s.count(p4_old)
    if n != 1:
        fails.append("dmg report R179 note: anchor count "
                     + str(n) + " (expected 1)")
    else:
        wr("tools/dmg_gap_report.md", s.replace(p4_old, p4_new))
        applied.append("dmg report: R179 round note")
assert len(applied) + len(already) == 4

# ---- R179 fails/tail ----
if fails:
    print("R179 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 4:
    print("R179 splice: FAIL - expected 4 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R179 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R179 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R179 note: 4 patches; census 96 (one new audit);")
print("real gate: md5sum rules/subclasses.h")
print("commit: R179: the six subclass foundations pinned -")
print("the registry round (census 96)")

