# tools/r162_splice.py - R162, 8 patches: level title
# ladders (PHB pp.20-31 class tables) - the R4 named
# leader. This round PATCHES rules/classes.cpp and
# rules/classes.h (no new header): the placeholder
# TITLES_* ladders are replaced with the printed ones.
#
# (1)-(2) rules/classes.cpp: the header debt comment
#     and the four TITLES_* arrays. FIGHTER (p.20):
#     Veteran, Warrior, Swordsman, Hero, Swashbuckler,
#     Myrmidon, Champion, Superhero, Lord (already
#     correct - kept). MAGIC-USER: Prestidigitator,
#     Evoker, Conjurer, Theurgist, Thaumaturgist,
#     Magician, Enchanter, Warlock, Sorcerer,
#     Necromancer, Wizard (the all-Conjurer run was
#     wrong). CLERIC: Acolyte, Adept, Priest, Curate,
#     Canon, Lama, Patriarch, High Priest (the Curate
#     run was wrong); the level 5 title cell prints
#     blank - JUDGMENT: carries Curate down. THIEF:
#     Rogue (Apprentice), Footpad, Cutpurse, Robber,
#     Burglar, Filcher, Sharper, Magsman, Thief,
#     Master Thief (the all-Rogue run was wrong).
#     (3)-(5) rules/classes.h: the three debt
#     comments discharged (titles pinned, HP_BEYOND
#     CAP 3/1/2/2 print-verified; the xpForLevel rows
#     DIVERGE from the print and stay open).
#     (6) the R162 audit: all four ladders pinned
#     cell by cell, the cap and floor clamps, the
#     bad-class Unknown - CENSUS 80. (7)-(8) the gap
#     report.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R162: level title ladders pinned - the PHB
# class-table titles for the four classes (census 80)"
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

p1_old = NL.join(['// RE-AUTHORED from the R4 spec after the original upload was lost.', '// VERIFICATION DEBT: xpForLevel rows and titleFor ladders follow', '// the standard 1e shape from project notes; the PHB printed tables', '// (p.20-31) win when re-uploaded. The HP_BEYOND_CAP convention and', '// linear adders are likewise flagged.'])
p1_new = NL.join(['// RE-AUTHORED from the R4 spec after the original upload was lost.', '// R162: the titleFor ladders and the HP_BEYOND_CAP convention are', '// verified against the PHB print (pp.20-31); the xpForLevel rows', '// DIVERGE from the print from mid-table on (fighter level 5 reads', '// 16000 against the printed 18000 boundary; the MU, cleric and', '// thief rows diverge above that) and stay open.'])
patch("rules/classes.cpp", p1_old, p1_new,
      "classes.cpp: header debt comment",
      marker='R162: the titleFor ladders')
assert len(applied) + len(already) == 1

p2_old = NL.join(['// ----------------------------------------------------------------------------', '// Titles (PLACEHOLDER LADDERS - display only; verify vs PHB p.20-31)', '// ----------------------------------------------------------------------------', '', 'static const char* const TITLES_FIGHTER[9] = {', '    "Veteran", "Warrior", "Swordsman", "Hero", "Swashbuckler",', '    "Myrmidon", "Champion", "Superhero", "Lord"', '};', 'static const char* const TITLES_MAGIC_USER[11] = {', '    "Conjurer", "Conjurer", "Conjurer", "Conjurer", "Conjurer",', '    "Conjurer", "Conjurer", "Conjurer", "Conjurer", "Conjurer",', '    "Wizard"', '};', 'static const char* const TITLES_CLERIC[9] = {', '    "Acolyte", "Adept", "Priest", "Curate", "Curate",', '    "Curate", "Curate", "Curate", "Patriarch"', '};', 'static const char* const TITLES_THIEF[10] = {', '    "Rogue", "Rogue", "Rogue", "Rogue", "Rogue",', '    "Rogue", "Rogue", "Rogue", "Rogue", "Master Thief"', '};'])
p2_new = NL.join(['// ----------------------------------------------------------------------------', '// Titles (the PHB p.20-31 printed ladders - R162 verified; the', '// cleric level 5 cell prints blank and carries Curate down)', '// ----------------------------------------------------------------------------', '', 'static const char* const TITLES_FIGHTER[9] = {', '    "Veteran", "Warrior", "Swordsman", "Hero", "Swashbuckler",', '    "Myrmidon", "Champion", "Superhero", "Lord"', '};', 'static const char* const TITLES_MAGIC_USER[11] = {', '    "Prestidigitator", "Evoker", "Conjurer", "Theurgist",', '    "Thaumaturgist", "Magician", "Enchanter", "Warlock",', '    "Sorcerer", "Necromancer", "Wizard"', '};', 'static const char* const TITLES_CLERIC[9] = {', '    "Acolyte", "Adept", "Priest", "Curate", "Curate",', '    "Canon", "Lama", "Patriarch", "High Priest"', '};', 'static const char* const TITLES_THIEF[10] = {', '    "Rogue (Apprentice)", "Footpad", "Cutpurse", "Robber",', '    "Burglar", "Filcher", "Sharper", "Magsman", "Thief",', '    "Master Thief"', '};'])
patch("rules/classes.cpp", p2_old, p2_new,
      "classes.cpp: the four TITLES ladders",
      marker='printed ladders - R162 verified')
assert len(applied) + len(already) == 2

p3_old = NL.join(['// RE-AUTHORED from the R4 spec after the original upload was lost', '// from the repo. NOTE discipline: XP tables and title ladders are', '// transcribed from project notes and follow the standard 1e shape;', '// when the PHB PDF is re-uploaded, the printed tables win (PHB', '// p.20-31) - verify xpForLevel rows and titleFor ladders then.'])
p3_new = NL.join(['// RE-AUTHORED from the R4 spec after the original upload was lost', '// from the repo. NOTE discipline: the titleFor ladders are verified', '// against the PHB print by R162 (p.20-31); the XP tables are', '// transcribed from project notes and DIVERGE from the print from', '// mid-table on (an open box - see the gap report header note).'])
patch("rules/classes.h", p3_old, p3_new,
      "classes.h: header debt comment",
      marker='the titleFor ladders are verified')
assert len(applied) + len(already) == 3

p4_old = NL.join(['// Fixed hp per level beyond the name cap: fighter 3, MU 1, cleric 2,', '// thief 2 (the 3/2/2/1-vs-3/1/2/2 convention question is settled', '// HERE as 3/1/2/2 in F/MU/C/T order; PHB verification pending)'])
p4_new = NL.join(['// Fixed hp per level beyond the name cap: fighter 3, MU 1, cleric 2,', '// thief 2 (the 3/2/2/1-vs-3/1/2/2 convention question is settled', '// HERE as 3/1/2/2 in F/MU/C/T order; verified against the PHB', '// print by R162)'])
patch("rules/classes.h", p4_old, p4_new,
      "classes.h: HP_BEYOND_CAP debt comment",
      marker='print by R162)')
assert len(applied) + len(already) == 4

p5_old = NL.join(['// Display title for a class/level (PLACEHOLDER LADDERS - verify vs', '// PHB p.20-31 in a later pass).'])
p5_new = NL.join(['// Display title for a class/level (the PHB p.20-31 printed', '// ladders, pinned by R162; the cleric level 5 blank cell carries', '// Curate down as the JUDGMENT).'])
patch("rules/classes.h", p5_old, p5_new,
      "classes.h: titleFor debt comment",
      marker='blank cell carries')
assert len(applied) + len(already) == 5

p6_old = NL.join(['        printf("R161 two weapons audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
p6_new = NL.join(['        printf("R161 two weapons audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R162: level title ladders audit ---------', '    // PHB p.20-31: the printed per-level titles for', '    // the four engine classes. The cleric level 5', '    // title cell prints blank; JUDGMENT: it carries', '    // the level 4 title down (Curate).', '    {', '        static const char* const kF[9] = {', '            "Veteran", "Warrior", "Swordsman", "Hero",', '            "Swashbuckler", "Myrmidon", "Champion",', '            "Superhero", "Lord"', '        };', '        static const char* const kM[11] = {', '            "Prestidigitator", "Evoker", "Conjurer",', '            "Theurgist", "Thaumaturgist", "Magician",', '            "Enchanter", "Warlock", "Sorcerer",', '            "Necromancer", "Wizard"', '        };', '        static const char* const kC[9] = {', '            "Acolyte", "Adept", "Priest", "Curate",', '            "Curate", "Canon", "Lama", "Patriarch",', '            "High Priest"', '        };', '        static const char* const kT[10] = {', '            "Rogue (Apprentice)", "Footpad", "Cutpurse",', '            "Robber", "Burglar", "Filcher", "Sharper",', '            "Magsman", "Thief", "Master Thief"', '        };', '        int bad = 0;', '        for (int i = 0; i < 9; ++i)', '            if (std::string(rules::titleFor(', '                    rules::CLASS_FIGHTER, i + 1)) != kF[i])', '                ++bad;', '        for (int i = 0; i < 11; ++i)', '            if (std::string(rules::titleFor(', '                    rules::CLASS_MAGIC_USER, i + 1)) != kM[i])', '                ++bad;', '        for (int i = 0; i < 9; ++i)', '            if (std::string(rules::titleFor(', '                    rules::CLASS_CLERIC, i + 1)) != kC[i])', '                ++bad;', '        for (int i = 0; i < 10; ++i)', '            if (std::string(rules::titleFor(', '                    rules::CLASS_THIEF, i + 1)) != kT[i])', '                ++bad;', '        // the clamp conventions: a level above the', '        // cap reads the top title; level 0 or below', '        // reads the first title; a bad class reads', '        // Unknown', '        if (std::string(rules::titleFor(', '                rules::CLASS_FIGHTER, 10)) != kF[8] ||', '            std::string(rules::titleFor(', '                rules::CLASS_FIGHTER, 99)) != kF[8] ||', '            std::string(rules::titleFor(', '                rules::CLASS_MAGIC_USER, 12)) != kM[10] ||', '            std::string(rules::titleFor(', '                rules::CLASS_CLERIC, 10)) != kC[8] ||', '            std::string(rules::titleFor(', '                rules::CLASS_THIEF, 11)) != kT[9]) ++bad;', '        if (std::string(rules::titleFor(', '                rules::CLASS_FIGHTER, 0)) != kF[0] ||', '            std::string(rules::titleFor(', '                rules::CLASS_THIEF, -3)) != kT[0]) ++bad;', '        if (std::string(rules::titleFor(-1, 1)) != "Unknown" ||', '            std::string(rules::titleFor(99, 1)) != "Unknown")', '            ++bad;', '        printf("R162 level title ladders audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
patch("regtest.cpp", p6_old, p6_new,
      "regtest.cpp: R162 audit block",
      marker='R162 level title ladders audit')
assert len(applied) + len(already) == 6

p7_old = NL.join(['as a shield or parrying device. Census 79.', '', 'Categories:'])
p7_new = NL.join(['as a shield or parrying device. Census 79.', 'R162 PINNED level title ladders (PHB pp.20-31', 'class tables) - rules/classes.cpp: the printed', 'per-level titles for the four engine classes,', 'replacing the placeholder ladders (the all-Conjurer', 'MU run, the Curate run, the all-Rogue thief).', 'Fighter: Veteran, Warrior, Swordsman, Hero,', 'Swashbuckler, Myrmidon, Champion, Superhero,', 'Lord. Magic-user: Prestidigitator, Evoker,', 'Conjurer, Theurgist, Thaumaturgist, Magician,', 'Enchanter, Warlock, Sorcerer, Necromancer,', 'Wizard. Cleric: Acolyte, Adept, Priest, Curate,', 'Canon, Lama, Patriarch, High Priest. Thief:', 'Rogue (Apprentice), Footpad, Cutpurse, Robber,', 'Burglar, Filcher, Sharper, Magsman, Thief,', 'Master Thief. JUDGMENT: the cleric level 5 title', 'cell prints blank and carries Curate down. The', 'PHB display rows above the engine caps (Lord', '(10th Level) and the like) sit beyond', 'CLASS_LEVEL_CAP and stay out of engine scope.', 'The HP_BEYOND_CAP convention (3/1/2/2) is', 'print-verified in passing. R162 FINDING while', 'discharging the classes.h debt: the xpForLevel', 'rows DIVERGE from the print from mid-table on', '(fighter level 5 reads 16000 against the printed', '18000 boundary; the MU, cleric and thief rows', 'diverge above that) - the XP tables stay an', 'open box. Census 80.', '', 'Categories:'])
patch("tools/dmg_gap_report.md", p7_old, p7_new,
      "gap report: R162 header note",
      marker='R162 PINNED level title ladders')
assert len(applied) + len(already) == 7

p8_old = NL.join(['- [ ] **Level title ladders (PHB class tables)** - the R4', '      named leader: the printed per-level titles for the', '      four engine classes.'])
p8_new = NL.join(['- [x] **Level title ladders (PHB class tables)** - pinned by', '      R162: rules/classes.cpp (the four printed ladders', '      through the name levels; the cleric level 5 blank', '      cell carries Curate down; the XP-row divergence is', '      recorded in the header note).'])
patch("tools/dmg_gap_report.md", p8_old, p8_new,
      "gap report: level titles box closed",
      marker='Level title ladders (PHB class tables)** - pinned by')
assert len(applied) + len(already) == 8

# ---- R162 fails/tail ----
if fails:
    print("R162 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 8:
    print("R162 splice: FAIL - expected 8 patches, counted " + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R162 splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R162 splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R162 note: 8 patches; census 80; commit: R162: level title ladders pinned - the PHB class-table titles for the four classes (census 80)")
