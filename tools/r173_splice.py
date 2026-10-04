# tools/r173_splice.py - R173, 5 patches: Secondary skills
# (DMG p.12) - the player character non-professional
# skills: the 23-band SECONDARY SKILLS TABLE and the
# when-to-use guidance for PC backgrounds. A new
# header-only layer, rules/secondary.h (the grenade.h
# pattern: the caller rolls and selects).
#
# (1) rules/secondary.h: the table cell by cell - the
#     21 skills (Armorer 01-02 through Woodworker/
#     cabinetmaker 65-67), the NO SKILL OF MEASURABLE
#     WORTH band (68-85) and the ROLL TWICE IGNORING
#     THIS RESULT HEREAFTER band (86-00); the intro
#     prose (the class profession is assumed to be
#     that followed previously, virtually to the
#     exclusion of all other activity, thus 1st
#     level; some minor knowledge of certain mundane
#     skills might belong to the character from early
#     years or incidentally picked up in
#     apprenticeship; if the campaign is aimed at a
#     level of play where secondary skills can be
#     taken into account, use the table for player
#     characters, or even henchmen), the assignment
#     prose (assign a skill randomly, or select
#     according to the background of the campaign; to
#     determine if a second skill is known, roll on
#     the table, and if the dice indicate a result of
#     TWO SKILLS, assign a second, appropriate one)
#     and the adjudication prose (it is up to the DM
#     to create and/or adjudicate situations in which
#     these skills are used; as a general rule, having
#     a skill gives the ability to determine the
#     general worth and soundness of an item, to find
#     food, make small repairs, or actually construct
#     crude items; the armorer example: tell the
#     quality of normal armor, repair chain links,
#     perhaps fashion certain weapons).
#     (2) the regtest include. (3) the R173 audit: all
#     23 bands mirrored and walked, the prose - CENSUS
#     91. (4) the gap report census note. (5) the gap
#     report box.
#
# JUDGMENTs: (a) the table is cell-verified against
# the book upload (dmg-part1, the p.12 region), whose
# band arithmetic sums cleanly 1 through 100, and
# independently confirmed band for band by the
# mjyoung.net character-creation transcription (the
# third-party precedent); the upload spelling wins
# where the transcription paraphrases (Fisher
# (netting), Navigator (fresh or salt water)). (b)
# the table is print-only DMG material - the PHB
# premium edition upload does not carry it, so no
# cross-book check applies.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R173: secondary skills pinned - the p.12
# background skills table (census 91)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
BS = chr(92)
Q = chr(39)
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

# ---- patch 1: rules/secondary.h (new file) ----
p1_text = NL.join([
    "// ====================================================================",
    "// Adnd1 - rules/secondary.h",
    "// R173: Secondary skills (DMG p.12) - the player",
    "// character non-professional skills: the 23-band",
    "// SECONDARY SKILLS TABLE and the when-to-use",
    "// guidance for PC backgrounds.",
    "//",
    "// Pure data, header-only (the grenade.h pattern:",
    "// the caller rolls and selects).",
    "//",
    "// JUDGMENTs: cell-verified against the book upload",
    "// (band arithmetic 1-100 clean) and independently",
    "// confirmed band for band by the mjyoung.net",
    "// transcription; the upload spelling wins where the",
    "// transcription paraphrases.",
    "// ====================================================================",
    "",
    "#pragma once",
    "",
    "namespace rules {",
    "",
    "// ----------------------------------------------------------------------------",
    "// The secondary skills table (p.12)",
    "// ----------------------------------------------------------------------------",
    "",
    "struct SecondarySkillRow {",
    "    int lo;",
    "    int hi;",
    "    const char* name;",
    "};",
    "",
    "inline int secondaryRowCount() { return 23; }",
    "",
    "// The 23 printed bands: 21 named skills, the NO",
    "// SKILL OF MEASURABLE WORTH band (68-85) and the",
    "// ROLL TWICE IGNORING THIS RESULT HEREAFTER band",
    "// (86-00).",
    "inline const SecondarySkillRow& secondaryRow(int i) {",
    "    static const SecondarySkillRow k[23] = {",
    '        { 1, 2, "Armorer" },',
    '        { 3, 4, "Bowyer/fletcher" },',
    '        { 5, 10, "Farmer/gardener" },',
    '        { 11, 14, "Fisher (netting)" },',
    '        { 15, 20, "Forester" },',
    '        { 21, 23, "Gambler" },',
    '        { 24, 27, "Hunter/fisher (hook and line)" },',
    '        { 28, 32, "Husbandman (animal husbandry)" },',
    '        { 33, 34, "Jeweler/lapidary" },',
    '        { 35, 37, "Leather worker/tanner" },',
    '        { 38, 39, "Limner/painter" },',
    '        { 40, 42, "Mason/carpenter" },',
    '        { 43, 44, "Miner" },',
    '        { 45, 46, "Navigator (fresh or salt water)" },',
    '        { 47, 49, "Sailor (fresh or salt)" },',
    '        { 50, 51, "Shipwright (boats or ships)" },',
    '        { 52, 54, "Tailor/weaver" },',
    '        { 55, 57, "Teamster/freighter" },',
    '        { 58, 60, "Trader/barterer" },',
    '        { 61, 64, "Trapper/furrier" },',
    '        { 65, 67, "Woodworker/cabinetmaker" },',
    '        { 68, 85, "NO SKILL OF MEASURABLE WORTH" },',
    '        { 86, 100, "ROLL TWICE IGNORING THIS RESULT HEREAFTER" }',
    "    };",
    "    if (i < 0) i = 0;",
    "    if (i > 22) i = 22;",
    "    return k[i];",
    "}",
    "",
    "// True for the NO SKILL band row (index 21).",
    "inline bool secondaryIsNoSkill(int i) {",
    "    return i == 21;",
    "}",
    "",
    "// True for the ROLL TWICE band row (index 22).",
    "inline bool secondaryIsRollTwice(int i) {",
    "    return i == 22;",
    "}",
    "",
    "// The intro prose: when a player character selects",
    "// a class, this profession is assumed to be that",
    "// which the character has been following",
    "// previously, virtually to the exclusion of all",
    "// other activity - thus the particular individual",
    "// is at 1st level of ability.",
    "inline bool secondaryClassAssumedPriorProfession() {",
    "    return true;",
    "}",
    "",
    "// However, some minor knowledge of certain mundane",
    "// skills might belong to the player character -",
    "// information and training from early years or",
    "// incidentally picked up while the individual was",
    "// in apprenticeship learning his or her primary",
    "// professional skills.",
    "inline bool secondaryMinorMundaneKnowledgePossible() {",
    "    return true;",
    "}",
    "",
    "// If the particular campaign is aimed at a level",
    "// of play where secondary skills can be taken",
    "// into account, then use the table to assign them",
    "// to player characters, or even to henchmen.",
    "inline bool secondaryCampaignAimedAtSkillsUsesTable() {",
    "    return true;",
    "}",
    "",
    "// Assign a skill randomly, or select according to",
    "// the background of the campaign.",
    "inline bool secondaryAssignRandomOrPerBackground() {",
    "    return true;",
    "}",
    "",
    "// To determine if a second skill is known, roll on",
    "// the table, and if the dice indicate a result of",
    "// TWO SKILLS, then assign a second, appropriate",
    "// one.",
    "inline bool secondarySecondSkillIfTwoSkills() {",
    "    return true;",
    "}",
    "",
    "// The adjudication prose: when secondary skills",
    "// are used, it is up to the DM to create and/or",
    "// adjudicate situations in which these skills are",
    "// used or useful to the player character.",
    "inline bool secondaryDMAdjudicatesSituations() {",
    "    return true;",
    "}",
    "",
    "// As a general rule, having a skill will give the",
    "// character the ability to determine the general",
    "// worth and soundness of an item, the ability to",
    "// find food, make small repairs, or actually",
    "// construct (crude) items - the armorer example:",
    "// tell the quality of normal armor, repair chain",
    "// links, or perhaps fashion certain weapons.",
    "inline bool secondarySkillGivesWorthSoundnessRepairs() {",
    "    return true;",
    "}",
    "",
    "// To determine the extent of knowledge in",
    "// question, simply assume the role of one of",
    "// these skills, one that you know a little",
    "// something about, and determine what could be",
    "// done with this knowledge. Use this as a scale",
    "// to weigh the relative ability of characters",
    "// with secondary skills.",
    "inline bool secondaryAssumeRoleToScaleAbility() {",
    "    return true;",
    "}",
    "",
    "}  // namespace rules",
    "",
    ""])
create("rules/secondary.h", p1_text,
      "rules/secondary.h",
      marker="R173: Secondary skills (DMG p.12)")
assert len(applied) + len(already) == 1

# ---- patch 2: the regtest include ----
p2_old = '#include "rules/herbs.h"  // R172: p.220 appendix J herbs spices and medicinal vegetables'
p2_new = NL.join([
    '#include "rules/herbs.h"  // R172: p.220 appendix J herbs spices and medicinal vegetables',
    '#include "rules/secondary.h"  // R173: p.12 secondary skills'])
patch("regtest.cpp", p2_old, p2_new,
      "regtest.cpp: R173 include",
      marker="R173: p.12 secondary skills")
assert len(applied) + len(already) == 2

# ---- patch 3: the R173 audit block ----
p3_old = NL.join(['        printf("R172 appendix J herbs audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
p3_new = NL.join([
    '        printf("R172 appendix J herbs audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R173: secondary skills audit ------------------',
    '    // DMG p.12: the player character non-professional',
    '    // skills - the 23-band table cell by cell and the',
    '    // when-to-use guidance (the judgments recorded in',
    '    // the gap report).',
    '    {',
    '        int bad = 0;',
    '        static const int kLo[23] = {',
    '            1, 3, 5, 11, 15, 21, 24, 28, 33, 35, 38, 40,',
    '            43, 45, 47, 50, 52, 55, 58, 61, 65, 68, 86',
    '        };',
    '        static const int kHi[23] = {',
    '            2, 4, 10, 14, 20, 23, 27, 32, 34, 37, 39, 42,',
    '            44, 46, 49, 51, 54, 57, 60, 64, 67, 85, 100',
    '        };',
    '        static const char* kName[23] = {',
    '            "Armorer",',
    '            "Bowyer/fletcher",',
    '            "Farmer/gardener",',
    '            "Fisher (netting)",',
    '            "Forester",',
    '            "Gambler",',
    '            "Hunter/fisher (hook and line)",',
    '            "Husbandman (animal husbandry)",',
    '            "Jeweler/lapidary",',
    '            "Leather worker/tanner",',
    '            "Limner/painter",',
    '            "Mason/carpenter",',
    '            "Miner",',
    '            "Navigator (fresh or salt water)",',
    '            "Sailor (fresh or salt)",',
    '            "Shipwright (boats or ships)",',
    '            "Tailor/weaver",',
    '            "Teamster/freighter",',
    '            "Trader/barterer",',
    '            "Trapper/furrier",',
    '            "Woodworker/cabinetmaker",',
    '            "NO SKILL OF MEASURABLE WORTH",',
    '            "ROLL TWICE IGNORING THIS RESULT HEREAFTER"',
    '        };',
    '        if (rules::secondaryRowCount() != 23) ++bad;',
    '        for (int i = 0; i < 23; ++i) {',
    '            const rules::SecondarySkillRow& row =',
    '                rules::secondaryRow(i);',
    '            if (row.lo != kLo[i] || row.hi != kHi[i] ||',
    '                std::string(row.name) != kName[i])',
    '                ++bad;',
    '        }',
    '        // the band arithmetic: 1 through 100 clean',
    '        if (kLo[0] != 1) ++bad;',
    '        for (int i = 0; i < 22; ++i)',
    '            if (kHi[i] + 1 != kLo[i + 1]) ++bad;',
    '        if (kHi[22] != 100) ++bad;',
    '        // the special rows',
    '        if (!rules::secondaryIsNoSkill(21)) ++bad;',
    '        if (rules::secondaryIsNoSkill(20)) ++bad;',
    '        if (rules::secondaryIsNoSkill(22)) ++bad;',
    '        if (!rules::secondaryIsRollTwice(22)) ++bad;',
    '        if (rules::secondaryIsRollTwice(21)) ++bad;',
    '        // the intro and adjudication prose',
    '        if (!rules::secondaryClassAssumedPriorProfession() ||',
    '            !rules::secondaryMinorMundaneKnowledgePossible() ||',
    '            !rules::secondaryCampaignAimedAtSkillsUsesTable() ||',
    '            !rules::secondaryAssignRandomOrPerBackground() ||',
    '            !rules::secondarySecondSkillIfTwoSkills() ||',
    '            !rules::secondaryDMAdjudicatesSituations() ||',
    '            !rules::secondarySkillGivesWorthSoundnessRepairs() ||',
    '            !rules::secondaryAssumeRoleToScaleAbility())',
    '            ++bad;',
    '        printf("R173 secondary skills audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R146: city flavor subtables audit ----'])
patch("regtest.cpp", p3_old, p3_new,
      "regtest.cpp: R173 audit block",
      marker="R173 secondary skills audit")
assert len(applied) + len(already) == 3

# ---- patch 4: the gap report census note ----
p4_old = NL.join([
    '(user-authorized). Census 90.',
    '',
    'Categories:'])
p4_new = NL.join([
    '(user-authorized). Census 90.',
    'R173 PINNED Secondary skills (DMG p.12) - the',
    'player character non-professional skills -',
    'rules/secondary.h: the 23-band SECONDARY SKILLS',
    'TABLE cell by cell (the 21 named skills Armorer',
    '01-02 through Woodworker/cabinetmaker 65-67, the',
    'NO SKILL OF MEASURABLE WORTH band 68-85 and the',
    'ROLL TWICE IGNORING THIS RESULT HEREAFTER band',
    '86-00) and the when-to-use guidance (the intro,',
    'assignment and adjudication prose). JUDGMENTs:',
    'cell-verified against the book upload (band',
    'arithmetic 1-100 clean) and independently',
    'confirmed band for band by the mjyoung.net',
    'transcription; the upload spelling wins where the',
    'transcription paraphrases. Census 91.',
    '',
    'Categories:'])
patch("tools/dmg_gap_report.md", p4_old, p4_new,
      "gap report: R173 header note",
      marker="R173 PINNED Secondary skills (DMG p.12)")
assert len(applied) + len(already) == 4

# ---- patch 5: the gap report box ----
p5_old = NL.join([
    '- [ ] **Secondary skills (p.12)** - the table and the',
    '      when-to-use guidance for PC backgrounds.'])
p5_new = NL.join([
    '- [x] **Secondary skills (p.12)** - PINNED R173:',
    '      rules/secondary.h (the 23-band table cell by',
    '      cell; the when-to-use guidance).'])
patch("tools/dmg_gap_report.md", p5_old, p5_new,
      "gap report: secondary skills box closed",
      marker="rules/secondary.h (the 23-band table cell")
assert len(applied) + len(already) == 5

# ---- R173 fails/tail ----
if fails:
    print("R173 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print("R173 splice: FAIL - expected 5 patches, counted " + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R173 splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R173 splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R173 note: 5 patches; census 91; commit: R173: secondary skills pinned - the p.12 background skills table (census 91)")

