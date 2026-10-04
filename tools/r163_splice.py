# tools/r163_splice.py - R163, 5 patches: the poison
# table (DMG p.20) - the printed types. A new
# header-only layer, rules/poison.h (the grenade.h
# pattern: the caller holds the poison lane; the
# monster venom layer keeps its per-monster saves).
#
# (1) rules/poison.h: the p.20 print - purchased
#     poisons come ingestive (A-E) or insinuative
#     (A-D); per grade the cost per dose, onset time
#     (with its unit), damage if the save is made,
#     damage or death if not, the victim save bonus,
#     and the tasting/smelling/seeing chance. Grade E
#     prints no footnotes - JUDGMENT: no save bonus
#     and no stated detection chance (0). The user
#     efficiency ladder: a studied assassin gives no
#     penalty, an unstudied assassin +1 on the victim
#     save, everyone else +2. Monster poison is
#     all-or-nothing (dead within about a minute) and
#     dual-use; purchased poison is ingestive or
#     insinuative only. The blade-venom decay rules
#     (DMG p.28) ride here too: insinuative, full
#     damage the first day or hit, half the second,
#     gone by the third, +4 on saves once decayed.
#     (2) the regtest include. (3) the R163 audit:
#     every printed cell pinned - CENSUS 81.
#     (4)-(5) the gap report.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R163: the poison table pinned - the p.20
# types, onset times and damage classes (census 81)"
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

p1_text = NL.join(['// ====================================================================', '// Adnd1 - rules/poison.h', '// R163: the poison table (DMG p.20) - the printed', '// poison types: cost, onset, damage classes.', '//', '// Pure data, header-only (the grenade.h pattern: the', '// caller holds the poison lane and rolls the save; the', '// monster venom layer keeps its per-monster saves).', '//', '// The p.20 print:', '//   - Purchased poisons are INGESTIVE (grades A-E) or', '//     INSINUATIVE (grades A-D). Dual-use poison comes', '//     from monsters only; a purchase is one route only.', '//   - Per grade the table prints: cost per dose, onset', '//     time (in its own unit), damage if the save is', '//     made, damage or death if not, the victim save', '//     bonus (the footnotes), and the chance of', '//     tasting, smelling or seeing the poison.', '//   - JUDGMENT: grade E prints no footnotes - it gives', '//     no save bonus and no stated detection chance', '//     (recorded as 0).', '//   - User efficiency: an assassin who has studied', '//     poisoning gives no penalty; an unstudied assassin', '//     gives +1 on the victim save; every other class', '//     gives +2.', '//   - Monster poison is all-or-nothing (no damage or', '//     death within about a minute) and dual-use; poison', '//     potions must be ingested.', '//   - Blade venom (DMG p.28): insinuative, evaporation', '//     and use decay it the same way - full the first', '//     day or hit, half the second, gone by the third;', '//     a decayed death poison gives the victim +4 on', '//     the save.', '// ====================================================================', '', '#pragma once', '', 'namespace rules {', '', '// ----------------------------------------------------------------------------', '// Routes and grades', '// ----------------------------------------------------------------------------', '', 'enum PoisonRoute {', '    POISON_INGESTIVE = 0,', '    POISON_INSINUATIVE = 1', '};', '', '// The print counts a segment as 6 seconds and a round as', '// 10; the onset UNIT stays per-row here and the caller', '// converts.', 'enum PoisonUnit {', '    POISON_UNIT_ROUND = 0,', '    POISON_UNIT_TURN = 1,', '    POISON_UNIT_SEGMENT = 2', '};', '', '// Grade index: 0 = A ... 4 = E. Grade E exists ingestive', '// only.', 'inline bool poisonGradeExists(int route, int grade) {', '    if (grade < 0 || grade > 4) return false;', '    if (route == POISON_INSINUATIVE) return grade <= 3;', '    return true;', '}', '', '// ----------------------------------------------------------------------------', '// The p.20 table (cost per dose)', '// ----------------------------------------------------------------------------', '', 'inline int poisonCostPerDose(int route, int grade) {', '    if (!poisonGradeExists(route, grade)) return 0;', '    static const int kIngestive[5] = { 5, 30, 200, 500, 1000 };', '    static const int kInsinuative[4] = { 10, 75, 600, 1500 };', '    if (route == POISON_INSINUATIVE) return kInsinuative[grade];', '    return kIngestive[grade];', '}', '', '// Onset: minimum and maximum on the printed range plus', '// the unit the row prints in.', 'inline int poisonOnsetMin(int route, int grade) {', '    static const int kIn[5] = { 2, 2, 1, 1, 1 };', '    static const int kIns[4] = { 2, 1, 1, 1 };', '    if (!poisonGradeExists(route, grade)) return 0;', '    if (route == POISON_INSINUATIVE) return kIns[grade];', '    return kIn[grade];', '}', '', 'inline int poisonOnsetMax(int route, int grade) {', '    static const int kIn[5] = { 8, 5, 2, 1, 4 };', '    static const int kIns[4] = { 5, 3, 1, 1 };', '    if (!poisonGradeExists(route, grade)) return 0;', '    if (route == POISON_INSINUATIVE) return kIns[grade];', '    return kIn[grade];', '}', '', 'inline PoisonUnit poisonOnsetUnit(int route, int grade) {', '    // ingestive D: 1 segment; ingestive E: 1-4 turns;', '    // everything else: rounds', '    if (route == POISON_INGESTIVE && grade == 3)', '        return POISON_UNIT_SEGMENT;', '    if (route == POISON_INGESTIVE && grade == 4)', '        return POISON_UNIT_TURN;', '    if (!poisonGradeExists(route, grade))', '        return POISON_UNIT_ROUND;', '    return POISON_UNIT_ROUND;', '}', '', '// ----------------------------------------------------------------------------', '// Damage classes', '// ----------------------------------------------------------------------------', '', '// The victim save bonus (the footnotes: +4/+3/+2/+1;', '// E prints none - JUDGMENT: 0).', 'inline int poisonVictimSaveBonus(int route, int grade) {', '    if (!poisonGradeExists(route, grade)) return 0;', '    if (grade <= 2) return 4 - grade;', '    if (grade == 3) return 1;', '    return 0;', '}', '', '// The tasting/smelling/seeing chance (80/65/40/15;', '// E prints none - JUDGMENT: 0).', 'inline int poisonDetectChance(int route, int grade) {', '    if (!poisonGradeExists(route, grade)) return 0;', '    static const int k[5] = { 80, 65, 40, 15, 0 };', '    return k[grade];', '}', '', '// Damage if the save is made (the ingestive table only;', '// every insinuative row prints 0).', 'inline int poisonDamageIfSave(int route, int grade) {', '    if (!poisonGradeExists(route, grade)) return -1;', '    if (route == POISON_INSINUATIVE) return 0;', '    static const int k[5] = { 10, 15, 20, 25, 30 };', '    return k[grade];', '}', '', '// A failed save: death (true) or the printed damage.', 'inline bool poisonKillsIfNoSave(int route, int grade) {', '    if (!poisonGradeExists(route, grade)) return false;', '    if (route == POISON_INSINUATIVE) return grade == 3;', '    return grade >= 3;', '}', '', 'inline int poisonDamageIfNoSave(int route, int grade) {', '    if (poisonKillsIfNoSave(route, grade)) return -1;', '    if (!poisonGradeExists(route, grade)) return -1;', '    if (route == POISON_INSINUATIVE) {', '        static const int k[4] = { 15, 25, 35, 0 };', '        return k[grade];', '    }', '    static const int k[5] = { 20, 30, 40, 0, 0 };', '    return k[grade];', '}', '', '// ----------------------------------------------------------------------------', '// The class rules around the table', '// ----------------------------------------------------------------------------', '', '// User efficiency: the bonus the VICTIM gets on the save.', '// A studied assassin: none; an unstudied assassin: +1;', '// every other class: +2.', 'inline int poisonUserEfficiencyAdj(', '        bool assassin, bool studied) {', '    if (assassin && studied) return 0;', '    if (assassin) return 1;', '    return 2;', '}', '', '// Monster poison: all-or-nothing - no damage or death', '// within about a minute.', 'inline bool poisonMonsterAllOrNothing() {', '    return true;', '}', '', '// Monster poison works by ingestion or insinuation alike', '// (dual-use); purchased poison is one route only.', 'inline bool poisonMonsterDualUse() {', '    return true;', '}', '', '// Blade venom (DMG p.28): insinuative. Evaporation and', '// use decay it identically - full the first day or hit,', '// half the second, gone by the third. The multiplier is', '// 100 for the first, 50 for the second, 0 for the third', '// and beyond.', 'inline int poisonBladeVenomPotencyPercent(int interval) {', '    if (interval <= 0) return 100;', '    if (interval == 1) return 50;', '    return 0;', '}', '', '// A partially evaporated or used DEATH poison gives the', '// victim +4 on the save.', 'inline bool poisonBladeVenomDecayedGivesSaveBonus(', '        int interval) {', '    return interval >= 1;', '}', '', '} // namespace rules', ''])
create("rules/poison.h", p1_text,
      "poison.h: the poison table layer",
      marker='poisonBladeVenomPotencyPercent')
assert len(applied) + len(already) == 1

p2_old = NL.join(['#include "rules/twoweapon.h"  // R161: p.70 attacks with two weapons'])
p2_new = NL.join(['#include "rules/twoweapon.h"  // R161: p.70 attacks with two weapons', '#include "rules/poison.h"  // R163: p.20 the poison table'])
patch("regtest.cpp", p2_old, p2_new,
      "regtest.cpp: poison include",
      marker='rules/poison.h"  // R163')
assert len(applied) + len(already) == 2

p3_old = NL.join(['        printf("R162 level title ladders audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
p3_new = NL.join(['        printf("R162 level title ladders audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R163: the poison table audit -------------', '    // DMG p.20: the purchased-poison table - ingestive', '    // A-E and insinuative A-D, each with cost, onset', '    // (and unit), the damage classes, the footnote save', '    // bonuses and detection chances - plus the class', '    // rules and the blade-venom decay.', '    {', '        int bad = 0;', '        // the ingestive column: A-E', '        static const int kInCost[5] = { 5, 30, 200, 500, 1000 };', '        static const int kInSaveDmg[5] = { 10, 15, 20, 25, 30 };', '        static const int kInNoSaveDmg[5] = { 20, 30, 40, -1, -1 };', '        static const int kInOnMin[5] = { 2, 2, 1, 1, 1 };', '        static const int kInOnMax[5] = { 8, 5, 2, 1, 4 };', '        for (int g = 0; g < 5; ++g) {', '            if (rules::poisonCostPerDose(', '                    rules::POISON_INGESTIVE, g) != kInCost[g])', '                ++bad;', '            if (rules::poisonDamageIfSave(', '                    rules::POISON_INGESTIVE, g) != kInSaveDmg[g])', '                ++bad;', '            int nsd = rules::poisonDamageIfNoSave(', '                rules::POISON_INGESTIVE, g);', '            if (kInNoSaveDmg[g] == -1) {', '                if (!rules::poisonKillsIfNoSave(', '                        rules::POISON_INGESTIVE, g) || nsd != -1)', '                    ++bad;', '            } else if (nsd != kInNoSaveDmg[g]) ++bad;', '            if (rules::poisonOnsetMin(', '                    rules::POISON_INGESTIVE, g) != kInOnMin[g] ||', '                rules::poisonOnsetMax(', '                    rules::POISON_INGESTIVE, g) != kInOnMax[g])', '                ++bad;', '            if (rules::poisonOnsetUnit(', '                    rules::POISON_INGESTIVE, g)', '                    != rules::POISON_UNIT_ROUND && g <= 2) ++bad;', '        }', '        // ingestive D reads segments, E turns', '        if (rules::poisonOnsetUnit(', '                rules::POISON_INGESTIVE, 3)', '                != rules::POISON_UNIT_SEGMENT ||', '            rules::poisonOnsetUnit(', '                rules::POISON_INGESTIVE, 4)', '                != rules::POISON_UNIT_TURN) ++bad;', '        // the insinuative column: A-D', '        static const int kInsCost[4] = { 10, 75, 600, 1500 };', '        static const int kInsNoSaveDmg[4] = { 15, 25, 35, -1 };', '        static const int kInsOnMin[4] = { 2, 1, 1, 1 };', '        static const int kInsOnMax[4] = { 5, 3, 1, 1 };', '        for (int g = 0; g < 4; ++g) {', '            if (rules::poisonCostPerDose(', '                    rules::POISON_INSINUATIVE, g) != kInsCost[g])', '                ++bad;', '            if (rules::poisonDamageIfSave(', '                    rules::POISON_INSINUATIVE, g) != 0) ++bad;', '            int nsd = rules::poisonDamageIfNoSave(', '                rules::POISON_INSINUATIVE, g);', '            if (kInsNoSaveDmg[g] == -1) {', '                if (!rules::poisonKillsIfNoSave(', '                        rules::POISON_INSINUATIVE, g) || nsd != -1)', '                    ++bad;', '            } else if (nsd != kInsNoSaveDmg[g]) ++bad;', '            if (rules::poisonOnsetMin(', '                    rules::POISON_INSINUATIVE, g) != kInsOnMin[g] ||', '                rules::poisonOnsetMax(', '                    rules::POISON_INSINUATIVE, g) != kInsOnMax[g])', '                ++bad;', '            if (rules::poisonOnsetUnit(', '                    rules::POISON_INSINUATIVE, g)', '                != rules::POISON_UNIT_ROUND) ++bad;', '        }', '        // grade E is ingestive only', '        if (rules::poisonGradeExists(', '                rules::POISON_INSINUATIVE, 4) ||', '            !rules::poisonGradeExists(', '                rules::POISON_INSINUATIVE, 3) ||', '            !rules::poisonGradeExists(', '                rules::POISON_INGESTIVE, 4) ||', '            rules::poisonGradeExists(', '                rules::POISON_INGESTIVE, 5) ||', '            rules::poisonGradeExists(', '                rules::POISON_INGESTIVE, -1)) ++bad;', '        // the footnotes: +4/+3/+2/+1 save, E none;', '        // detection 80/65/40/15, E none', '        static const int kBonus[5] = { 4, 3, 2, 1, 0 };', '        static const int kDetect[5] = { 80, 65, 40, 15, 0 };', '        for (int g = 0; g < 5; ++g) {', '            if (rules::poisonVictimSaveBonus(', '                    rules::POISON_INGESTIVE, g) != kBonus[g])', '                ++bad;', '            if (rules::poisonDetectChance(', '                    rules::POISON_INGESTIVE, g) != kDetect[g])', '                ++bad;', '        }', '        for (int g = 0; g < 4; ++g) {', '            if (rules::poisonVictimSaveBonus(', '                    rules::POISON_INSINUATIVE, g) != kBonus[g])', '                ++bad;', '            if (rules::poisonDetectChance(', '                    rules::POISON_INSINUATIVE, g) != kDetect[g])', '                ++bad;', '        }', '        // the user efficiency ladder', '        if (rules::poisonUserEfficiencyAdj(true, true) != 0 ||', '            rules::poisonUserEfficiencyAdj(true, false) != 1 ||', '            rules::poisonUserEfficiencyAdj(false, true) != 2 ||', '            rules::poisonUserEfficiencyAdj(false, false) != 2)', '            ++bad;', '        // monster poison: all-or-nothing, dual-use', '        if (!rules::poisonMonsterAllOrNothing() ||', '            !rules::poisonMonsterDualUse()) ++bad;', '        // blade venom decay: full, half, gone', '        if (rules::poisonBladeVenomPotencyPercent(0) != 100 ||', '            rules::poisonBladeVenomPotencyPercent(1) != 50 ||', '            rules::poisonBladeVenomPotencyPercent(2) != 0 ||', '            rules::poisonBladeVenomPotencyPercent(3) != 0 ||', '            !rules::poisonBladeVenomDecayedGivesSaveBonus(1) ||', '            rules::poisonBladeVenomDecayedGivesSaveBonus(0))', '            ++bad;', '        printf("R163 poison table audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
patch("regtest.cpp", p3_old, p3_new,
      "regtest.cpp: R163 audit block",
      marker='R163 poison table audit')
assert len(applied) + len(already) == 3

p4_old = NL.join(['open box. Census 80.', '', 'Categories:'])
p4_new = NL.join(['open box. Census 80.', 'R163 PINNED the poison table (DMG p.20) -', 'rules/poison.h: the purchased-poison types,', 'ingestive A-E and insinuative A-D, each with', 'cost per dose (5-1,000 gp ingestive, 10-1,500', 'insinuative), onset time with its unit (rounds,', 'ingestive D 1 segment, ingestive E 1-4 turns),', 'the damage classes (damage if saved, damage or', 'death if not), the footnote victim save bonuses', '(+4/+3/+2/+1) and detection chances', '(80/65/40/15). JUDGMENT: grade E prints no', 'footnotes - no save bonus, detection 0. The', 'class rules: a studied assassin gives no', 'penalty, an unstudied assassin +1 on the victim', 'save, everyone else +2; monster poison is', 'all-or-nothing and dual-use. The DMG p.28 blade', 'venom decay rides here: insinuative, full the', 'first day or hit, half the second, gone by the', 'third, +4 on saves once decayed. The caller', 'holds the save roll (the monster venom layer', 'keeps its per-monster saves). Census 81.', '', 'Categories:'])
patch("tools/dmg_gap_report.md", p4_old, p4_new,
      "gap report: R163 header note",
      marker='R163 PINNED the poison table')
assert len(applied) + len(already) == 4

p5_old = NL.join(['- [ ] **The poison table (p.20)** - the printed types:', '      ingest/injury, onset times, damage and effect', '      classes. The monster venom layer rolls per-monster', '      saves; the type table itself is unpinned.'])
p5_new = NL.join(['- [x] **The poison table (p.20)** - pinned by R163:', '      rules/poison.h (the ingestive/insinuative grade', '      table with cost, onset, damage classes, save', '      bonuses and detection chances; the efficiency', '      ladder; the blade-venom decay).'])
patch("tools/dmg_gap_report.md", p5_old, p5_new,
      "gap report: poison table box closed",
      marker='The poison table (p.20)** - pinned by R163')
assert len(applied) + len(already) == 5

# ---- R163 fails/tail ----
if fails:
    print("R163 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print("R163 splice: FAIL - expected 5 patches, counted " + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R163 splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R163 splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R163 note: 5 patches; census 81; commit: R163: the poison table pinned - the p.20 types, onset times and damage classes (census 81)")
