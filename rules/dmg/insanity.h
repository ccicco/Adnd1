// ====================================================================
// Adnd1 - rules/dmg/insanity.h
// R166: intoxication and insanity (DMG pp.82-83) -
// the alcohol and drug effects with the recovery
// table, and the types of insanity.
//
// Pure data, header-only (the grenade.h pattern: the
// caller tracks the intoxication state and plays the
// insane character; the printed numbers are data, the
// behavioral prose is caller-side).
//
// The p.82 print - the intoxication table (slight,
// moderate, great):
//   bravery +1/+2/+4 (up to foolhardy); morale
//   +5/+10/+15 percent (NPCs only); intelligence
//   -1/-3/-6; wisdom -1/-4/-7; dexterity 0/-2/-5;
//   charisma 0/-1/-4; attack dice 0/-1/-5 (opponent
//   saves vs magic from the intoxicated character
//   raised by the same: 1 or 5 points, 5 or 25
//   percent); hit points 0/+1/+3.
//   - Beyond great intoxication: comatose, asleep
//     7-10 hours.
// The p.83 recovery table:
//   slight 1-2 hours, moderate 2-4, great 4-6,
//   comatose 7-10. A mild stimulant multiplies the
//   time by .80/.85/.90/.95; a strong stimulant by
//   .50/.55/.55/.60. Mild stimulants are harmless;
//   a strong stimulant has a 5 percent chance per
//   application of permanently lowering
//   constitution by 1. Time is the only cure.
// The p.83 insanity types: 20 named forms; the
// first four are MILD and subject to psionic attack
// (per the PSIONIC COMBAT TABLES note). The
// psionic-section duration classes: PERMANENT
// until heal, restoration or wish, select TWO
// forms; TEMPORARY 2-12 weeks, otherwise as
// permanent; MILD 1-4 weeks, ONE form. Each
// form carries the printed parameters below.
// ====================================================================

#pragma once

// R1053 applied
#include "items/MiscItemRegistry.h"

namespace rules {

// ---- the R1053 registry seam ---------------
// content/tables/dm_insanity/ via
// items::MiscItemRegistry: the
// R1042 rows idiom plus named
// tables per def (the R1051 dzTable
// idiom) and the rows reader (the
// R1051 dzRows idiom - insanityName
// is a rows reader now). Header-only
// singleton (the R1040 appendixp.h
// idiom). Every accessor below
// keeps its signature, clamp and
// branch; only the array read moves
// behind the registry. The stimulant
// accessor keeps its strong branch
// as a TAG-level ternary on the same
// def key (each ternary arm closes
// its own string - the R1052 adjacent
// literal lesson).

inline items::MiscItemRegistry&
izReg() {
    static items::MiscItemRegistry
        reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/"
            "dm_insanity");
    }
    return reg;
}

// the name rows of one def (the
// band is the index; insanityName
// maps type-1 onto them)
inline const std::vector<
    items::MiscItemRow>& izRows(
        const char* key) {
    static std::map<std::string,
        std::vector<
            items::MiscItemRow>>
        cache;
    auto it = cache.find(key);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = izReg().find(key);
        it = cache.emplace(
            key, d ? d->rows
                   : std::vector<
                        items::
                        MiscItemRow>()
                   ).first;
    }
    return it->second;
}

// one named int table of one def
// (null when absent or empty)
inline const std::vector<long
    long>* izTable(const char* key,
                  const char* tag) {
    static std::map<std::string,
        std::vector<long long>>
        cache;
    const std::string kk =
        std::string(key) + "/"
        + tag;
    auto it = cache.find(kk);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = izReg().find(key);
        const std::vector<long
            long>* v = nullptr;
        if (d) {
            for (const auto& t :
                 d->tables) {
                if (t.name == tag) {
                    v = &t.values;
                    break;
                }
            }
        }
        it = cache.emplace(
            kk, v ? *v
                  : std::vector<
                        long long>()
                   ).first;
    }
    return it->second.empty()
        ? nullptr
        : &it->second;
}

// ----------------------------------------------------------------------------
// Intoxication (p.82)
// ----------------------------------------------------------------------------

enum IntoxState {
    INTOX_SOBER = 0,
    INTOX_SLIGHT,
    INTOX_MODERATE,
    INTOX_GREAT,
    INTOX_COMATOSE
};

inline IntoxState intoxicationClamp(IntoxState s) {
    if (s < INTOX_SOBER) s = INTOX_SOBER;
    if (s > INTOX_COMATOSE) s = INTOX_COMATOSE;
    return s;
}

// The eight table rows, slight/moderate/great.
// Bravery moves up towards foolhardy; morale is
// NPC-only; hp RISE with the drug.
inline int intoxicationBraveryAdjust(IntoxState s) {
    const auto* g = izTable(
        "dm_intoxication", "bravery_adjust");
    if (!g) return 0;
    return (int)(*g)[intoxicationClamp(s)];
}
inline int intoxicationMoraleAdjust(IntoxState s) {
    const auto* g = izTable(
        "dm_intoxication", "morale_adjust");
    if (!g) return 0;
    return (int)(*g)[intoxicationClamp(s)];
}
inline int intoxicationIntelligenceAdjust(IntoxState s) {
    const auto* g = izTable(
        "dm_intoxication", "intelligence_adjust");
    if (!g) return 0;
    return (int)(*g)[intoxicationClamp(s)];
}
inline int intoxicationWisdomAdjust(IntoxState s) {
    const auto* g = izTable(
        "dm_intoxication", "wisdom_adjust");
    if (!g) return 0;
    return (int)(*g)[intoxicationClamp(s)];
}
inline int intoxicationDexterityAdjust(IntoxState s) {
    const auto* g = izTable(
        "dm_intoxication", "dexterity_adjust");
    if (!g) return 0;
    return (int)(*g)[intoxicationClamp(s)];
}
inline int intoxicationCharismaAdjust(IntoxState s) {
    const auto* g = izTable(
        "dm_intoxication", "charisma_adjust");
    if (!g) return 0;
    return (int)(*g)[intoxicationClamp(s)];
}
inline int intoxicationAttackDiceAdjust(IntoxState s) {
    const auto* g = izTable(
        "dm_intoxication", "attack_dice_adjust");
    if (!g) return 0;
    return (int)(*g)[intoxicationClamp(s)];
}
inline int intoxicationHitPointAdjust(IntoxState s) {
    const auto* g = izTable(
        "dm_intoxication", "hit_point_adjust");
    if (!g) return 0;
    return (int)(*g)[intoxicationClamp(s)];
}

// Opponent saves vs magic from the intoxicated
// character rise by the attack-dice number: the
// point value (1 or 5) and its percent form
// (5 or 25).
inline int intoxicationMagicSaveRaise(IntoxState s) {
    return -intoxicationAttackDiceAdjust(s);
}
inline int intoxicationMagicSaveRaisePercent(IntoxState s) {
    const auto* g = izTable(
        "dm_intoxication", "magic_save_raise_percent");
    if (!g) return 0;
    return (int)(*g)[intoxicationClamp(s)];
}

// Comatose sleep: 7-10 hours.
inline int intoxicationComatoseSleepMin() { return 7; }
inline int intoxicationComatoseSleepMax() { return 10; }

// ----------------------------------------------------------------------------
// Recovery (p.83)
// ----------------------------------------------------------------------------

// Recovery time in hours per state (time is the
// only cure).
inline int intoxicationRecoveryMin(IntoxState s) {
    const auto* g = izTable(
        "dm_intoxication", "recovery_min_hours");
    if (!g) return 0;
    return (int)(*g)[intoxicationClamp(s)];
}
inline int intoxicationRecoveryMax(IntoxState s) {
    const auto* g = izTable(
        "dm_intoxication", "recovery_max_hours");
    if (!g) return 0;
    return (int)(*g)[intoxicationClamp(s)];
}

// Stimulant effect as a percent multiplier on the
// recovery time (the print: x .80/.85/.90/.95 mild,
// x .50/.55/.55/.60 strong).
inline int intoxicationStimulantPercent(
        IntoxState s, bool strong) {
    const auto* g = izTable(
        "dm_intoxication",
        strong
            ? "stimulant_strong_percent"
            : "stimulant_mild_percent");
    if (!g) return 100;
    return (int)(*g)[intoxicationClamp(s)];
}

// A strong stimulant: 5 percent per application of
// permanently lowering constitution by 1. Mild
// stimulants are harmless.
inline int intoxicationStrongStimulantConChance() {
    return 5;
}
inline int intoxicationStrongStimulantConLoss() {
    return 1;
}

// ----------------------------------------------------------------------------
// The types of insanity (p.83)
// ----------------------------------------------------------------------------

// The 20 named forms, 1-20 in the printed order.
// 1-4 are MILD (subject to psionic attack); 11-20
// the print lists under COMBAT (INSANITY).
inline const char* insanityName(int type) {
    const auto& rows = 
        izRows("dm_insanity");
    if (rows.empty())
        return "";
    if (type < 1) type = 1;
    if (type > 20) type = 20;
    if ((int)rows.size() < type)
        return "";
    return rows[type - 1].name.c_str();
}

// The four mild forms (the print star): subject to
// psionic attack.
inline bool insanityIsMild(int type) {
    return type >= 1 && type <= 4;
}

// The psionic-section duration classes: permanent
// (until heal, restoration or wish; TWO forms),
// temporary (2-12 weeks; otherwise as permanent),
// mild (1-4 weeks; ONE form).
inline int insanityTemporaryWeeksMin() { return 2; }
inline int insanityTemporaryWeeksMax() { return 12; }
inline int insanityMildWeeksMin() { return 1; }
inline int insanityMildWeeksMax() { return 4; }

// 1. Dipsomania: drinking until passing out about
// once per week; 50 percent it continues on waking
// near alcohol, 10 percent otherwise.
inline int insanityDipsomaniaContinueNearAlcohol() {
    return 50;
}
inline int insanityDipsomaniaContinueOtherwise() {
    return 10;
}

// 2. Kleptomania: 90 percent chance of being seen
// if observed; thieves and assassins steal at -10
// percent.
inline int insanityKleptomaniaSeenChance() { return 90; }
inline int insanityKleptomaniaThiefPenalty() { return -10; }

// 6. Dementia praecox: 25 percent to ignore any
// situation as meaningless.
inline int insanityDementiaPraecoxIgnoreChance() { return 25; }

// 7. Melancholia: 50 percent to ignore a given
// situation.
inline int insanityMelancholiaIgnoreChance() { return 50; }

// 10. Schizophrenia: 1-4 personalities; onset 1 in 6
// per day, checked every round under stress.
inline int insanitySchizophreniaPersonalitiesMin() { return 1; }
inline int insanitySchizophreniaPersonalitiesMax() { return 4; }
inline int insanityOnsetChanceIn6() { return 1; }

// 11. Mania: strikes 1 in 6 per turn, lasts 2-12
// turns, 1 in 6 per turn of return; the d6 strength
// states 18/50, 18/75, 18/00.
inline int insanityManiaDurationMinTurns() { return 2; }
inline int insanityManiaDurationMaxTurns() { return 12; }
inline int insanityManiaStrengthState(int d6) {
    const auto* g = izTable(
        "dm_insanity", "mania_strength_state");
    if (d6 < 1) d6 = 1;
    if (d6 > 6) d6 = 6;
    if (!g) return 0;
    return (int)(*g)[d6];
}

// 14. Manic-depressive: 1-4 day cycle; 90 percent
// likely to flip on excitement or frustration.
inline int insanityManicDepressiveCycleMinDays() { return 1; }
inline int insanityManicDepressiveCycleMaxDays() { return 4; }
inline int insanityManicDepressiveFlipChance() { return 90; }

// 15. Hallucinatory insanity: 50 percent normal
// until stimulated; hallucinations 1-20 turns
// after the excitement passes.
inline int insanityHallucinatoryNormalChance() { return 50; }
inline int insanityHallucinatoryDurationMinTurns() { return 1; }
inline int insanityHallucinatoryDurationMaxTurns() { return 20; }

// 16. Sado-masochism: normalcy returns 1-3 days
// after acting out either phase.
inline int insanitySadoMasoNormalMinDays() { return 1; }
inline int insanitySadoMasoNormalMaxDays() { return 3; }

// 17. Homicidal mania: the kill urge on 1-4 day
// intervals; frustrated killing means mania, then
// melancholia 1-6 days.
inline int insanityHomicidalIntervalMinDays() { return 1; }
inline int insanityHomicidalIntervalMaxDays() { return 4; }
inline int insanityHomicidalMelancholiaMinDays() { return 1; }
inline int insanityHomicidalMelancholiaMaxDays() { return 6; }

// 18. Hebephrenia: 75 percent enraged when
// irritated, else catatonic 1-6 hours.
inline int insanityHebephreniaEnrageChance() { return 75; }
inline int insanityHebephreniaCatatonicMinHours() { return 1; }
inline int insanityHebephreniaCatatonicMaxHours() { return 6; }

// 19. Suicidal mania: a 10-80 percent scale by
// danger; frustration means mania 2-8 turns,
// then melancholy 2-12 days.
inline int insanitySuicidalScaleMin() { return 10; }
inline int insanitySuicidalScaleMax() { return 80; }
inline int insanitySuicidalManiaMinTurns() { return 2; }
inline int insanitySuicidalManiaMaxTurns() { return 8; }
inline int insanitySuicidalMelancholyMinDays() { return 2; }
inline int insanitySuicidalMelancholyMaxDays() { return 12; }

// 20. Catatonia: a 1 percent cumulative chance per
// round of provocation of homicidal mania; the
// catatonia returns once provocation ceases.
inline int insanityCatatoniaReactionChance() { return 1; }

} // namespace rules
