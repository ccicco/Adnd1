# tools/r166_splice.py - R166, 5 patches: intoxication
# and insanity (DMG pp.82-83) - the alcohol and drug
# effects with the recovery table, and the types of
# insanity. A new header-only layer, rules/insanity.h
# (the grenade.h pattern: the caller tracks state and
# plays the insane character; the numbers are data).
#
# (1) rules/insanity.h: the p.82 intoxication table -
#     bravery +1/+2/+4, morale +5/+10/+15 percent,
#     intelligence -1/-3/-6, wisdom -1/-4/-7,
#     dexterity 0/-2/-5, charisma 0/-1/-4, attack
#     dice 0/-1/-5, hit points 0/+1/+3 (slight,
#     moderate, great); beyond great intoxication is
#     comatose with 7-10 hours of sleep. Opponent
#     saving throws vs magic from an intoxicated
#     character rise by the same number (1 or 5
#     points, 5 or 25 percent). The p.83 recovery
#     table: slight 1-2 hours, moderate 2-4, great
#     4-6, comatose 7-10; mild stimulants multiply
#     recovery time by .80/.85/.90/.95, strong by
#     .50/.55/.55/.60; mild stimulants are harmless,
#     a strong stimulant has a 5 percent chance per
#     application of permanently lowering
#     constitution by 1. The p.83 insanity types:
#     the 20 named forms, the four MILD ones
#     (dipsomania, kleptomania, schizoid,
#     pathological liar) marked as subject to psionic
#     attack, the psionic-section duration classes
#     (permanent until heal, restoration or wish,
#     two forms; temporary 2-12 weeks two forms;
#     mild 1-4 weeks one form), and each form's
#     printed numeric parameters: dipsomania 50/10
#     percent, kleptomania seen 90 percent with
#     thief/assassin stealing -10, dementia praecox
#     ignore 25 percent, melancholia 50, mania 1 in
#     6 per turn lasting 2-12 turns with the 18/50,
#     18/75, 18/00 strength states, manic-depressive
#     1-4 day cycle with 90 percent switch,
#     hallucinatory 50 percent then 1-20 turns,
#     sado-masochism normal 1-3 days after,
#     homicidal 1-4 day intervals with 1-6 day
#     melancholia after, hebephrenia 75 percent
#     enraged else catatonic 1-6 hours, suicidal
#     scale 10-80 percent with 2-8 turn mania and
#     2-12 day melancholy after, catatonia 1
#     percent cumulative per round of provocation,
#     schizophrenia 1-4 personalities with the 1 in
#     6 per day onset checked every round under
#     stress. The behavioral prose is caller-side.
#     (2) the regtest include. (3) the R166 audit:
#     every printed number pinned - CENSUS 84.
#     (4)-(5) the gap report.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R166: intoxication and insanity pinned - the
# pp.82-83 tables and the 20 insanity types (census 84)"
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

p1_text = NL.join(['// ====================================================================', '// Adnd1 - rules/insanity.h', '// R166: intoxication and insanity (DMG pp.82-83) -', '// the alcohol and drug effects with the recovery', '// table, and the types of insanity.', '//', '// Pure data, header-only (the grenade.h pattern: the', '// caller tracks the intoxication state and plays the', '// insane character; the printed numbers are data, the', '// behavioral prose is caller-side).', '//', '// The p.82 print - the intoxication table (slight,', '// moderate, great):', '//   bravery +1/+2/+4 (up to foolhardy); morale', '//   +5/+10/+15 percent (NPCs only); intelligence', '//   -1/-3/-6; wisdom -1/-4/-7; dexterity 0/-2/-5;', '//   charisma 0/-1/-4; attack dice 0/-1/-5 (opponent', '//   saves vs magic from the intoxicated character', '//   raised by the same: 1 or 5 points, 5 or 25', '//   percent); hit points 0/+1/+3.', '//   - Beyond great intoxication: comatose, asleep', '//     7-10 hours.', '// The p.83 recovery table:', '//   slight 1-2 hours, moderate 2-4, great 4-6,', '//   comatose 7-10. A mild stimulant multiplies the', '//   time by .80/.85/.90/.95; a strong stimulant by', '//   .50/.55/.55/.60. Mild stimulants are harmless;', '//   a strong stimulant has a 5 percent chance per', '//   application of permanently lowering', '//   constitution by 1. Time is the only cure.', '// The p.83 insanity types: 20 named forms; the', '// first four are MILD and subject to psionic attack', '// (per the PSIONIC COMBAT TABLES note). The', '// psionic-section duration classes: PERMANENT', '// until heal, restoration or wish, select TWO', '// forms; TEMPORARY 2-12 weeks, otherwise as', '// permanent; MILD 1-4 weeks, ONE form. Each', '// form carries the printed parameters below.', '// ====================================================================', '', '#pragma once', '', 'namespace rules {', '', '// ----------------------------------------------------------------------------', '// Intoxication (p.82)', '// ----------------------------------------------------------------------------', '', 'enum IntoxState {', '    INTOX_SOBER = 0,', '    INTOX_SLIGHT,', '    INTOX_MODERATE,', '    INTOX_GREAT,', '    INTOX_COMATOSE', '};', '', 'inline IntoxState intoxicationClamp(IntoxState s) {', '    if (s < INTOX_SOBER) s = INTOX_SOBER;', '    if (s > INTOX_COMATOSE) s = INTOX_COMATOSE;', '    return s;', '}', '', '// The eight table rows, slight/moderate/great.', '// Bravery moves up towards foolhardy; morale is', '// NPC-only; hp RISE with the drug.', 'inline int intoxicationBraveryAdjust(IntoxState s) {', '    static const int k[5] = { 0, 1, 2, 4, 0 };', '    return k[intoxicationClamp(s)];', '}', 'inline int intoxicationMoraleAdjust(IntoxState s) {', '    static const int k[5] = { 0, 5, 10, 15, 0 };', '    return k[intoxicationClamp(s)];', '}', 'inline int intoxicationIntelligenceAdjust(IntoxState s) {', '    static const int k[5] = { 0, -1, -3, -6, 0 };', '    return k[intoxicationClamp(s)];', '}', 'inline int intoxicationWisdomAdjust(IntoxState s) {', '    static const int k[5] = { 0, -1, -4, -7, 0 };', '    return k[intoxicationClamp(s)];', '}', 'inline int intoxicationDexterityAdjust(IntoxState s) {', '    static const int k[5] = { 0, 0, -2, -5, 0 };', '    return k[intoxicationClamp(s)];', '}', 'inline int intoxicationCharismaAdjust(IntoxState s) {', '    static const int k[5] = { 0, 0, -1, -4, 0 };', '    return k[intoxicationClamp(s)];', '}', 'inline int intoxicationAttackDiceAdjust(IntoxState s) {', '    static const int k[5] = { 0, 0, -1, -5, 0 };', '    return k[intoxicationClamp(s)];', '}', 'inline int intoxicationHitPointAdjust(IntoxState s) {', '    static const int k[5] = { 0, 0, 1, 3, 0 };', '    return k[intoxicationClamp(s)];', '}', '', '// Opponent saves vs magic from the intoxicated', '// character rise by the attack-dice number: the', '// point value (1 or 5) and its percent form', '// (5 or 25).', 'inline int intoxicationMagicSaveRaise(IntoxState s) {', '    return -intoxicationAttackDiceAdjust(s);', '}', 'inline int intoxicationMagicSaveRaisePercent(IntoxState s) {', '    static const int k[5] = { 0, 0, 5, 25, 0 };', '    return k[intoxicationClamp(s)];', '}', '', '// Comatose sleep: 7-10 hours.', 'inline int intoxicationComatoseSleepMin() { return 7; }', 'inline int intoxicationComatoseSleepMax() { return 10; }', '', '// ----------------------------------------------------------------------------', '// Recovery (p.83)', '// ----------------------------------------------------------------------------', '', '// Recovery time in hours per state (time is the', '// only cure).', 'inline int intoxicationRecoveryMin(IntoxState s) {', '    static const int k[5] = { 0, 1, 2, 4, 7 };', '    return k[intoxicationClamp(s)];', '}', 'inline int intoxicationRecoveryMax(IntoxState s) {', '    static const int k[5] = { 0, 2, 4, 6, 10 };', '    return k[intoxicationClamp(s)];', '}', '', '// Stimulant effect as a percent multiplier on the', '// recovery time (the print: x .80/.85/.90/.95 mild,', '// x .50/.55/.55/.60 strong).', 'inline int intoxicationStimulantPercent(', '        IntoxState s, bool strong) {', '    static const int kMild[5] = { 100, 80, 85, 90, 95 };', '    static const int kStrong[5] = { 100, 50, 55, 55, 60 };', '    return strong ? kStrong[intoxicationClamp(s)]', '                  : kMild[intoxicationClamp(s)];', '}', '', '// A strong stimulant: 5 percent per application of', '// permanently lowering constitution by 1. Mild', '// stimulants are harmless.', 'inline int intoxicationStrongStimulantConChance() {', '    return 5;', '}', 'inline int intoxicationStrongStimulantConLoss() {', '    return 1;', '}', '', '// ----------------------------------------------------------------------------', '// The types of insanity (p.83)', '// ----------------------------------------------------------------------------', '', '// The 20 named forms, 1-20 in the printed order.', '// 1-4 are MILD (subject to psionic attack); 11-20', '// the print lists under COMBAT (INSANITY).', 'inline const char* insanityName(int type) {', '    static const char* const k[21] = {', '        "",', '        "dipsomania",', '        "kleptomania",', '        "schizoid",', '        "pathological liar",', '        "monomania",', '        "dementia praecox",', '        "melancholia",', '        "megalomania",', '        "delusional insanity",', '        "schizophrenia",', '        "mania",', '        "lunacy",', '        "paranoia",', '        "manic-depressive",', '        "hallucinatory insanity",', '        "sado-masochism",', '        "homicidal mania",', '        "hebephrenia",', '        "suicidal mania",', '        "catatonia"', '    };', '    if (type < 1) type = 1;', '    if (type > 20) type = 20;', '    return k[type];', '}', '', '// The four mild forms (the print star): subject to', '// psionic attack.', 'inline bool insanityIsMild(int type) {', '    return type >= 1 && type <= 4;', '}', '', '// The psionic-section duration classes: permanent', '// (until heal, restoration or wish; TWO forms),', '// temporary (2-12 weeks; otherwise as permanent),', '// mild (1-4 weeks; ONE form).', 'inline int insanityTemporaryWeeksMin() { return 2; }', 'inline int insanityTemporaryWeeksMax() { return 12; }', 'inline int insanityMildWeeksMin() { return 1; }', 'inline int insanityMildWeeksMax() { return 4; }', '', '// 1. Dipsomania: drinking until passing out about', '// once per week; 50 percent it continues on waking', '// near alcohol, 10 percent otherwise.', 'inline int insanityDipsomaniaContinueNearAlcohol() {', '    return 50;', '}', 'inline int insanityDipsomaniaContinueOtherwise() {', '    return 10;', '}', '', '// 2. Kleptomania: 90 percent chance of being seen', '// if observed; thieves and assassins steal at -10', '// percent.', 'inline int insanityKleptomaniaSeenChance() { return 90; }', 'inline int insanityKleptomaniaThiefPenalty() { return -10; }', '', '// 6. Dementia praecox: 25 percent to ignore any', '// situation as meaningless.', 'inline int insanityDementiaPraecoxIgnoreChance() { return 25; }', '', '// 7. Melancholia: 50 percent to ignore a given', '// situation.', 'inline int insanityMelancholiaIgnoreChance() { return 50; }', '', '// 10. Schizophrenia: 1-4 personalities; onset 1 in 6', '// per day, checked every round under stress.', 'inline int insanitySchizophreniaPersonalitiesMin() { return 1; }', 'inline int insanitySchizophreniaPersonalitiesMax() { return 4; }', 'inline int insanityOnsetChanceIn6() { return 1; }', '', '// 11. Mania: strikes 1 in 6 per turn, lasts 2-12', '// turns, 1 in 6 per turn of return; the d6 strength', '// states 18/50, 18/75, 18/00.', 'inline int insanityManiaDurationMinTurns() { return 2; }', 'inline int insanityManiaDurationMaxTurns() { return 12; }', 'inline int insanityManiaStrengthState(int d6) {', '    static const int k[7] = { 0, 50, 75, 100, 100, 100, 100 };', '    if (d6 < 1) d6 = 1;', '    if (d6 > 6) d6 = 6;', '    return k[d6];', '}', '', '// 14. Manic-depressive: 1-4 day cycle; 90 percent', '// likely to flip on excitement or frustration.', 'inline int insanityManicDepressiveCycleMinDays() { return 1; }', 'inline int insanityManicDepressiveCycleMaxDays() { return 4; }', 'inline int insanityManicDepressiveFlipChance() { return 90; }', '', '// 15. Hallucinatory insanity: 50 percent normal', '// until stimulated; hallucinations 1-20 turns', '// after the excitement passes.', 'inline int insanityHallucinatoryNormalChance() { return 50; }', 'inline int insanityHallucinatoryDurationMinTurns() { return 1; }', 'inline int insanityHallucinatoryDurationMaxTurns() { return 20; }', '', '// 16. Sado-masochism: normalcy returns 1-3 days', '// after acting out either phase.', 'inline int insanitySadoMasoNormalMinDays() { return 1; }', 'inline int insanitySadoMasoNormalMaxDays() { return 3; }', '', '// 17. Homicidal mania: the kill urge on 1-4 day', '// intervals; frustrated killing means mania, then', '// melancholia 1-6 days.', 'inline int insanityHomicidalIntervalMinDays() { return 1; }', 'inline int insanityHomicidalIntervalMaxDays() { return 4; }', 'inline int insanityHomicidalMelancholiaMinDays() { return 1; }', 'inline int insanityHomicidalMelancholiaMaxDays() { return 6; }', '', '// 18. Hebephrenia: 75 percent enraged when', '// irritated, else catatonic 1-6 hours.', 'inline int insanityHebephreniaEnrageChance() { return 75; }', 'inline int insanityHebephreniaCatatonicMinHours() { return 1; }', 'inline int insanityHebephreniaCatatonicMaxHours() { return 6; }', '', '// 19. Suicidal mania: a 10-80 percent scale by', '// danger; frustration means mania 2-8 turns,', '// then melancholy 2-12 days.', 'inline int insanitySuicidalScaleMin() { return 10; }', 'inline int insanitySuicidalScaleMax() { return 80; }', 'inline int insanitySuicidalManiaMinTurns() { return 2; }', 'inline int insanitySuicidalManiaMaxTurns() { return 8; }', 'inline int insanitySuicidalMelancholyMinDays() { return 2; }', 'inline int insanitySuicidalMelancholyMaxDays() { return 12; }', '', '// 20. Catatonia: a 1 percent cumulative chance per', '// round of provocation of homicidal mania; the', '// catatonia returns once provocation ceases.', 'inline int insanityCatatoniaReactionChance() { return 1; }', '', '} // namespace rules', ''])
create("rules/insanity.h", p1_text,
      "insanity.h: the intoxication and insanity layer",
      marker='insanityName')
assert len(applied) + len(already) == 1

p2_old = NL.join(['#include "rules/miscibility.h"  // R165: p.119 potion miscibility'])
p2_new = NL.join(['#include "rules/miscibility.h"  // R165: p.119 potion miscibility', '#include "rules/insanity.h"  // R166: pp.82-83 intoxication and insanity'])
patch("regtest.cpp", p2_old, p2_new,
      "regtest.cpp: insanity include",
      marker='rules/insanity.h"  // R166')
assert len(applied) + len(already) == 2

p3_old = NL.join(['        printf("R165 potion miscibility audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
p3_new = NL.join(['        printf("R165 potion miscibility audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R166: intoxication and insanity audit ------', '    // DMG pp.82-83: the intoxication table, the', '    // recovery table with the stimulant multipliers,', '    // the comatose sleep, the 20 named insanity', '    // forms with the mild-star and each form printed', '    // numeric parameter, and the duration classes.', '    {', '        int bad = 0;', '        // the intoxication table: slight/moderate/great', '        static const int kBrave[3] = { 1, 2, 4 };', '        static const int kMorale[3] = { 5, 10, 15 };', '        static const int kInt[3] = { -1, -3, -6 };', '        static const int kWis[3] = { -1, -4, -7 };', '        static const int kDex[3] = { 0, -2, -5 };', '        static const int kCha[3] = { 0, -1, -4 };', '        static const int kAtk[3] = { 0, -1, -5 };', '        static const int kHp[3] = { 0, 1, 3 };', '        for (int i = 0; i < 3; ++i) {', '            rules::IntoxState s =', '                (i == 0) ? rules::INTOX_SLIGHT', '                : (i == 1) ? rules::INTOX_MODERATE', '                : rules::INTOX_GREAT;', '            if (rules::intoxicationBraveryAdjust(s) != kBrave[i] ||', '                rules::intoxicationMoraleAdjust(s) != kMorale[i] ||', '                rules::intoxicationIntelligenceAdjust(s) != kInt[i] ||', '                rules::intoxicationWisdomAdjust(s) != kWis[i] ||', '                rules::intoxicationDexterityAdjust(s) != kDex[i] ||', '                rules::intoxicationCharismaAdjust(s) != kCha[i] ||', '                rules::intoxicationAttackDiceAdjust(s) != kAtk[i] ||', '                rules::intoxicationHitPointAdjust(s) != kHp[i])', '                ++bad;', '        }', '        // the magic-save raise rides the attack-dice', '        // number: 1/5 points, 5/25 percent', '        if (rules::intoxicationMagicSaveRaise(', '                rules::INTOX_MODERATE) != 1 ||', '            rules::intoxicationMagicSaveRaise(', '                rules::INTOX_GREAT) != 5 ||', '            rules::intoxicationMagicSaveRaisePercent(', '                rules::INTOX_MODERATE) != 5 ||', '            rules::intoxicationMagicSaveRaisePercent(', '                rules::INTOX_GREAT) != 25) ++bad;', '        // sober and comatose read zero on every row', '        if (rules::intoxicationBraveryAdjust(rules::INTOX_SOBER) != 0 ||', '            rules::intoxicationHitPointAdjust(rules::INTOX_COMATOSE) != 0)', '            ++bad;', '        // comatose sleep 7-10 hours', '        if (rules::intoxicationComatoseSleepMin() != 7 ||', '            rules::intoxicationComatoseSleepMax() != 10) ++bad;', '        // the recovery table: hours and multipliers', '        static const int kRecMin[4] = { 1, 2, 4, 7 };', '        static const int kRecMax[4] = { 2, 4, 6, 10 };', '        static const int kMild[4] = { 80, 85, 90, 95 };', '        static const int kStrong[4] = { 50, 55, 55, 60 };', '        for (int i = 0; i < 4; ++i) {', '            rules::IntoxState s =', '                (rules::IntoxState)(i + 1);', '            if (rules::intoxicationRecoveryMin(s) != kRecMin[i] ||', '                rules::intoxicationRecoveryMax(s) != kRecMax[i] ||', '                rules::intoxicationStimulantPercent(s, false)', '                    != kMild[i] ||', '                rules::intoxicationStimulantPercent(s, true)', '                    != kStrong[i])', '                ++bad;', '        }', '        // the strong-stimulant constitution risk', '        if (rules::intoxicationStrongStimulantConChance() != 5 ||', '            rules::intoxicationStrongStimulantConLoss() != 1)', '            ++bad;', '        // the 20 named forms in printed order', '        static const char* const kNames[20] = {', '            "dipsomania", "kleptomania", "schizoid",', '            "pathological liar", "monomania",', '            "dementia praecox", "melancholia",', '            "megalomania", "delusional insanity",', '            "schizophrenia", "mania", "lunacy",', '            "paranoia", "manic-depressive",', '            "hallucinatory insanity", "sado-masochism",', '            "homicidal mania", "hebephrenia",', '            "suicidal mania", "catatonia"', '        };', '        for (int i = 1; i <= 20; ++i)', '            if (std::string(rules::insanityName(i))', '                    != kNames[i - 1]) ++bad;', '        if (std::string(rules::insanityName(0))', '                != kNames[0] ||', '            std::string(rules::insanityName(21))', '                != kNames[19]) ++bad;', '        // the mild star: types 1-4 only', '        for (int i = 1; i <= 20; ++i)', '            if (rules::insanityIsMild(i) != (i <= 4)) ++bad;', '        // the duration classes', '        if (rules::insanityTemporaryWeeksMin() != 2 ||', '            rules::insanityTemporaryWeeksMax() != 12 ||', '            rules::insanityMildWeeksMin() != 1 ||', '            rules::insanityMildWeeksMax() != 4) ++bad;', '        // the per-form printed parameters', '        if (rules::insanityDipsomaniaContinueNearAlcohol() != 50 ||', '            rules::insanityDipsomaniaContinueOtherwise() != 10 ||', '            rules::insanityKleptomaniaSeenChance() != 90 ||', '            rules::insanityKleptomaniaThiefPenalty() != -10 ||', '            rules::insanityDementiaPraecoxIgnoreChance() != 25 ||', '            rules::insanityMelancholiaIgnoreChance() != 50)', '            ++bad;', '        if (rules::insanitySchizophreniaPersonalitiesMin() != 1 ||', '            rules::insanitySchizophreniaPersonalitiesMax() != 4 ||', '            rules::insanityOnsetChanceIn6() != 1 ||', '            rules::insanityManiaDurationMinTurns() != 2 ||', '            rules::insanityManiaDurationMaxTurns() != 12)', '            ++bad;', '        // the mania strength states: 18/50, 18/75,', '        // 18/00 - the percent-of-exceptional encoding', '        if (rules::insanityManiaStrengthState(1) != 50 ||', '            rules::insanityManiaStrengthState(2) != 75 ||', '            rules::insanityManiaStrengthState(3) != 100 ||', '            rules::insanityManiaStrengthState(6) != 100)', '            ++bad;', '        if (rules::insanityManicDepressiveCycleMinDays() != 1 ||', '            rules::insanityManicDepressiveCycleMaxDays() != 4 ||', '            rules::insanityManicDepressiveFlipChance() != 90 ||', '            rules::insanityHallucinatoryNormalChance() != 50 ||', '            rules::insanityHallucinatoryDurationMinTurns() != 1 ||', '            rules::insanityHallucinatoryDurationMaxTurns() != 20)', '            ++bad;', '        if (rules::insanitySadoMasoNormalMinDays() != 1 ||', '            rules::insanitySadoMasoNormalMaxDays() != 3 ||', '            rules::insanityHomicidalIntervalMinDays() != 1 ||', '            rules::insanityHomicidalIntervalMaxDays() != 4 ||', '            rules::insanityHomicidalMelancholiaMinDays() != 1 ||', '            rules::insanityHomicidalMelancholiaMaxDays() != 6)', '            ++bad;', '        if (rules::insanityHebephreniaEnrageChance() != 75 ||', '            rules::insanityHebephreniaCatatonicMinHours() != 1 ||', '            rules::insanityHebephreniaCatatonicMaxHours() != 6 ||', '            rules::insanitySuicidalScaleMin() != 10 ||', '            rules::insanitySuicidalScaleMax() != 80 ||', '            rules::insanitySuicidalManiaMinTurns() != 2 ||', '            rules::insanitySuicidalManiaMaxTurns() != 8 ||', '            rules::insanitySuicidalMelancholyMinDays() != 2 ||', '            rules::insanitySuicidalMelancholyMaxDays() != 12 ||', '            rules::insanityCatatoniaReactionChance() != 1)', '            ++bad;', '        printf("R166 intoxication and insanity audit: bad %d' + BS + 'n", bad);', '        if (bad) return 1;', '    }', '    // ---- R146: city flavor subtables audit ----'])
patch("regtest.cpp", p3_old, p3_new,
      "regtest.cpp: R166 audit block",
      marker='R166 intoxication and insanity audit')
assert len(applied) + len(already) == 3

p4_old = NL.join(['duration bookkeeping are caller-side. Census 83.', '', 'Categories:'])
p4_new = NL.join(['duration bookkeeping are caller-side. Census 83.', 'R166 PINNED intoxication and insanity (DMG', 'pp.82-83) - rules/insanity.h: the intoxication', 'table (bravery +1/+2/+4, morale +5/+10/+15', 'percent, intelligence -1/-3/-6, wisdom', '-1/-4/-7, dexterity 0/-2/-5, charisma 0/-1/-4,', 'attack dice 0/-1/-5 with opponent magic saves', 'raised by the same, hit points 0/+1/+3; beyond', 'great, comatose with 7-10 hours of sleep); the', 'recovery table (slight 1-2 hours, moderate 2-4,', 'great 4-6, comatose 7-10; mild stimulants x', '.80/.85/.90/.95, strong x .50/.55/.55/.60; a', 'strong stimulant risks a permanent -1', 'constitution at 5 percent per application); and', 'the 20 named insanity types with the four MILD', 'ones (dipsomania, kleptomania, schizoid,', 'pathological liar) subject to psionic attack, the', 'psionic-section duration classes (permanent', 'until heal, restoration or wish, two forms;', 'temporary 2-12 weeks; mild 1-4 weeks, one', 'form), and each form printed numeric parameter', '(dipsomania 50/10, kleptomania seen 90 with', 'thief stealing -10, dementia praecox 25,', 'melancholia 50, schizophrenia 1-4 personalities', 'at 1 in 6 per day, mania 1 in 6 per turn for', '2-12 turns with the 18/50, 18/75, 18/00', 'strength states, manic-depressive 1-4 days at 90', 'percent, hallucinatory 50 then 1-20 turns,', 'sado-masochism 1-3 days, homicidal 1-4 day', 'intervals then 1-6 day melancholia, hebephrenia', '75 then 1-6 hours, suicidal 10-80 percent with', '2-8 turn mania and 2-12 day melancholy,', 'catatonia 1 percent cumulative per round). The', 'behavioral prose is caller-side - the caller plays', 'the insane character. Census 84.', '', 'Categories:'])
patch("tools/dmg_gap_report.md", p4_old, p4_new,
      "gap report: R166 header note",
      marker='R166 PINNED intoxication and insanity')
assert len(applied) + len(already) == 4

p5_old = NL.join(['- [ ] **Intoxication and insanity (pp.82-83)** - the', '      alcohol and drugs effects with recovery tables;', '      the types of insanity.'])
p5_new = NL.join(['- [x] **Intoxication and insanity (pp.82-83)** - pinned', '      by R166: rules/insanity.h (the intoxication and', '      recovery tables; the 20 insanity types with', '      the mild-star, the duration classes and the', '      per-form numbers).'])
patch("tools/dmg_gap_report.md", p5_old, p5_new,
      "gap report: intoxication and insanity box closed",
      marker='Intoxication and insanity (pp.82-83)** - pinned')
assert len(applied) + len(already) == 5

# ---- R166 fails/tail ----
if fails:
    print("R166 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print("R166 splice: FAIL - expected 5 patches, counted " + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R166 splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R166 splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R166 note: 5 patches; census 84; commit: R166: intoxication and insanity pinned - the pp.82-83 tables and the 20 insanity types (census 84)")
