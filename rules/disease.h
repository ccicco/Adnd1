// ====================================================================
// Adnd1 - rules/disease.h
// R167: PC disease and parasitic infestation (DMG
// pp.13-14) - the contraction chances, the
// occurrence and severity tables, the per-area
// effects.
//
// Pure data, header-only (the grenade.h pattern: the
// caller rolls the percentile and d8 dice and tracks
// the disability). The monster-borne disease layer
// (mummy rot) stays as wired.
//
// The pp.13-14 print:
//   - Contraction is checked each game MONTH,
//     each WEEK when conditions are particularly
//     favorable (disease: very hot or hot moist
//     weather, filthy crowded warm conditions;
//     parasites: filthy conditions and warm
//     temperature, hot moist weather), and every
//     single carrier exposure.
//   - Disease base chance 2 percent; parasite base
//     chance 3 percent; the printed modifiers ride
//     below.
//   - The DISEASE (OR DISORDER) TABLE: 16 body
//     areas by d100; occurrence by d8 (acute or
//     chronic); severity by d8 (mild, severe,
//     terminal - three areas print no terminal:
//     joints, mucous membranes, nose-throat).
//   - The PARASITIC INFESTATION TABLE: 6 areas by
//     d100 with severity by d8 (skin/hair prints no
//     terminal).
//   - Severity: MILD - 1-3 weeks of rest, no
//     strenuous activity. SEVERE - hit points to 50
//     percent of normal, totally disabled 1-2
//     weeks plus 1-2 further weeks in the mild
//     state. TERMINAL - death or loss of the body
//     part or function in 1-12 days, with the
//     per-area exceptions stated below.
//   - Chronic maladies recur periodically; a
//     simultaneous malady raises the severity of
//     both.
//   - The occurrence/severity die roll adjustments
//     (disease only, NOT parasitic infestation): the
//     constitution ladder and the three condition
//     modifiers; a die score of 0 or less means the
//     character does not contract.
//   - Death from disease or infestation: the raised
//     character is 90 percent likely to still
//     suffer the cause unless a curative is used;
//     permanently sustained ability losses are
//     never corrected by any curative - only
//     wishes, alter reality or devices.
// ====================================================================

#pragma once

namespace rules {

// ----------------------------------------------------------------------------
// Contraction chances (p.13)
// ----------------------------------------------------------------------------

inline int diseaseContractBasePercent() { return 2; }
inline int parasiteContractBasePercent() { return 3; }

// The printed disease modifiers (percent).
inline int diseaseModCurrentlyAfflicted() { return 1; }
inline int diseaseModCrowding() { return 1; }
inline int diseaseModFilth() { return 1; }
inline int diseaseModOld() { return 2; }
inline int diseaseModMarshEnvironment() { return 2; }
inline int diseaseModHotMoist() { return 2; }
inline int diseaseModVenerable() { return 5; }
inline int diseaseModCarrierExposure() { return 10; }
inline int diseaseModCoolClimate() { return -1; }
inline int diseaseModColdHighMountains() { return -2; }
inline int diseaseModShipboardPastTwoWeeks() { return -2; }

// The printed parasite modifiers (percent).
inline int parasiteModFilth() { return 1; }
inline int parasiteModImproperlyCookedMeat() { return 2; }
inline int parasiteModPollutedWater() { return 5; }
inline int parasiteModSwampJungle() { return 5; }
inline int parasiteModCoolOrDesert() { return -1; }
inline int parasiteModColdOrCoolDesert() { return -1; }

// The check cadence: monthly, weekly when favorable,
// and on every carrier exposure.
inline bool diseaseWeeklyCheckWhenFavorable() { return true; }
inline bool diseaseCheckOnEachCarrierExposure() { return true; }

// ----------------------------------------------------------------------------
// The disease (or disorder) table (p.14) - 16 areas
// ----------------------------------------------------------------------------

inline int diseaseAreaCount() { return 16; }

inline const char* diseaseAreaName(int idx) {
    static const char* const k[16] = {
        "blood/blood forming organs",
        "bones",
        "brain/nervous system",
        "cardiovascular-renal",
        "connective tissue",
        "ears",
        "eyes",
        "gastro-intestinal",
        "generative organs",
        "joints",
        "mucous membranes",
        "muscles",
        "nose-throat",
        "respiratory system",
        "skin",
        "urinary system"
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}

// Row index for a d100 score (97-00 reads as 97-100).
inline int diseaseAreaForD100(int d100) {
    static const int kLo[16] = {
        1, 4, 5, 6, 8, 10, 13, 19, 41, 43,
        49, 51, 53, 66, 86, 97
    };
    if (d100 < 1) d100 = 1;
    if (d100 > 100) d100 = 100;
    for (int i = 15; i >= 0; --i)
        if (d100 >= kLo[i]) return i;
    return 0;
}

// Occurrence by d8: acute up to kAcuteHi, chronic
// from kChronicLo (chronic always runs to 8).
inline int diseaseAcuteHi(int idx) {
    static const int k[16] = {
        3, 1, 6, 3, 1, 7, 7, 6, 2, 4,
        7, 5, 6, 6, 5, 6
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}
inline int diseaseChronicLo(int idx) {
    return diseaseAcuteHi(idx) + 1;
}
inline bool diseaseIsAcute(int idx, int d8) {
    return d8 <= diseaseAcuteHi(idx);
}
inline bool diseaseIsChronic(int idx, int d8) {
    return d8 >= diseaseChronicLo(idx);
}

// Severity by d8: 0 means the column prints a dash
// (no terminal result for that area).
inline int diseaseSeverityMildHi(int idx) {
    static const int k[16] = {
        2, 1, 2, 2, 1, 6, 5, 5, 3, 6,
        6, 5, 6, 5, 5, 5
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}
inline int diseaseSeveritySevereHi(int idx) {
    static const int k[16] = {
        5, 3, 5, 4, 3, 7, 7, 7, 7, 8,
        8, 7, 8, 7, 7, 7
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}
inline int diseaseSeverityTerminalHi(int idx) {
    static const int k[16] = {
        8, 8, 8, 8, 8, 8, 8, 8, 8, 0,
        0, 8, 0, 8, 8, 8
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}

// ----------------------------------------------------------------------------
// The parasitic infestation table (p.14) - 6 areas
// ----------------------------------------------------------------------------

inline int parasiteAreaCount() { return 6; }

inline const char* parasiteAreaName(int idx) {
    static const char* const k[6] = {
        "cardiovascular system",
        "intestines",
        "muscles",
        "respiratory system",
        "skin/hair",
        "stomach"
    };
    if (idx < 0) idx = 0;
    if (idx > 5) idx = 5;
    return k[idx];
}

inline int parasiteAreaForD100(int d100) {
    static const int kLo[6] = { 1, 11, 36, 41, 46, 76 };
    if (d100 < 1) d100 = 1;
    if (d100 > 100) d100 = 100;
    for (int i = 5; i >= 0; --i)
        if (d100 >= kLo[i]) return i;
    return 0;
}

// Severity by d8 (no occurrence roll for parasites).
inline int parasiteSeverityMildHi(int idx) {
    static const int k[6] = { 2, 2, 1, 1, 7, 2 };
    if (idx < 0) idx = 0;
    if (idx > 5) idx = 5;
    return k[idx];
}
inline int parasiteSeveritySevereHi(int idx) {
    static const int k[6] = { 5, 7, 3, 4, 8, 7 };
    if (idx < 0) idx = 0;
    if (idx > 5) idx = 5;
    return k[idx];
}
inline int parasiteSeverityTerminalHi(int idx) {
    static const int k[6] = { 8, 8, 8, 8, 0, 8 };
    if (idx < 0) idx = 0;
    if (idx > 5) idx = 5;
    return k[idx];
}

// ----------------------------------------------------------------------------
// Severity effects and durations (p.14)
// ----------------------------------------------------------------------------

inline int diseaseMildWeeksMin() { return 1; }
inline int diseaseMildWeeksMax() { return 3; }
inline int diseaseSevereHitPointPercent() { return 50; }
inline int diseaseSevereDisabledWeeksMin() { return 1; }
inline int diseaseSevereDisabledWeeksMax() { return 2; }
inline int diseaseSevereMildRecoveryWeeksMin() { return 1; }
inline int diseaseSevereMildRecoveryWeeksMax() { return 2; }
inline int diseaseTerminalDaysMin() { return 1; }
inline int diseaseTerminalDaysMax() { return 12; }

// Terminal durations: the unit and range per area.
// DUR_NONE: the area prints no terminal column, or
// the terminal result is a function loss, not death.
enum DiseaseDurationUnit {
    DUR_NONE = 0,
    DUR_HOURS,
    DUR_DAYS,
    DUR_WEEKS,
    DUR_MONTHS
};

inline DiseaseDurationUnit diseaseTerminalUnit(int idx) {
    // blood and bones: 1-12 weeks; brain: 1-12
    // hours; cardiovascular-renal: 1-12 days;
    // connective tissue: terminal treated as
    // chronic severe (no duration); ears and eyes:
    // function loss; gastro-intestinal and skin and
    // urinary: 1-12 weeks; generative organs,
    // muscles, respiratory: 1-12 months;
    // joints, mucous membranes, nose-throat: none
    static const DiseaseDurationUnit k[16] = {
        DUR_WEEKS, DUR_WEEKS, DUR_HOURS, DUR_DAYS,
        DUR_NONE, DUR_NONE, DUR_NONE, DUR_WEEKS,
        DUR_MONTHS, DUR_NONE, DUR_NONE, DUR_MONTHS,
        DUR_NONE, DUR_MONTHS, DUR_WEEKS, DUR_WEEKS
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}

// The three areas with no terminal column at all
// (joints, mucous membranes, nose-throat).
inline bool diseaseHasTerminalColumn(int idx) {
    return diseaseSeverityTerminalHi(idx) != 0;
}

// Ears terminal: hearing loss in one ear. Eyes
// terminal: blindness in one or both eyes, 50/50.
inline bool diseaseTerminalIsFunctionLoss(int idx) {
    return idx == 5 || idx == 6;
}
inline int diseaseEyesBlindBothChance() { return 50; }

// Connective tissue: terminal treated as chronic
// severe (it lasts until constitution reaches 0).
inline bool diseaseTerminalTreatedAsChronicSevere(
        int idx) {
    return idx == 4;
}

// ----------------------------------------------------------------------------
// Per-area ability losses (p.14)
// ----------------------------------------------------------------------------

// Blood: -1 strength and -1 constitution per week
// until totally cured.
inline int diseaseBloodWeeklyStrLoss() { return 1; }
inline int diseaseBloodWeeklyConLoss() { return 1; }

// Brain: -1 intelligence and -1 dexterity per
// occurrence until totally cured.
inline int diseaseBrainIntLoss() { return 1; }
inline int diseaseBrainDexLoss() { return 1; }

// Connective tissue: -1 each strength, dexterity,
// constitution and charisma per month of
// affliction (permanent).
inline int diseaseConnectiveMonthlyLoss() { return 1; }

// Gastro-intestinal: -1 strength and -1
// constitution per occurrence; severe attacks
// cause the loss permanently.
inline int diseaseGastroStrConLoss() { return 1; }

// Joints: chronic -1 dexterity per occurrence,
// severe attacks permanent.
inline int diseaseJointsDexLoss() { return 1; }

// Mucous membranes: chronic -1 constitution,
// severe attacks permanent.
inline int diseaseMucousConLoss() { return 1; }

// Muscles: chronic -1 strength and -1 dexterity;
// severe attacks 25 percent permanent.
inline int diseaseMuscleStrDexLoss() { return 1; }
inline int diseaseMuscleSeverePermanentChance() {
    return 25;
}

// Nose-throat: 10 percent of -1 constitution per
// severe attack.
inline int diseaseNoseThroatSevereConLossChance() {
    return 10;
}

// Respiratory: 10 percent of -1 strength and -1
// constitution (checked separately).
inline int diseaseRespiratoryLossChance() { return 10; }

// Skin: severe 10 percent permanent -1 charisma;
// chronic mild 10 percent; chronic severe 25
// percent.
inline int diseaseSkinSevereChaLossChance() { return 10; }
inline int diseaseSkinChronicMildChance() { return 10; }
inline int diseaseSkinChronicSevereChance() { return 25; }

// Urinary: chronic severe 20 percent of -1
// dexterity and -1 constitution per occurrence.
inline int diseaseUrinaryLossChance() { return 20; }

// ----------------------------------------------------------------------------
// The occurrence/severity die roll adjustments
// ----------------------------------------------------------------------------

// The constitution ladder (disease only, NOT
// parasitic infestation): under 3 +2, 3-5 +1,
// 6-9 0, 10-12 -1, 13-15 -2, 16-17 -3, 18 -4.
inline int diseaseConRollAdjust(int con) {
    if (con <= 2) return 2;
    if (con <= 5) return 1;
    if (con <= 9) return 0;
    if (con <= 12) return -1;
    if (con <= 15) return -2;
    if (con <= 17) return -3;
    return -4;
}

// The three condition modifiers: chronic disease
// or disorder +1, severe parasitic infestation +1,
// under 25 percent of normal hit points +1.
inline int diseaseAdjustChronicDisease() { return 1; }
inline int diseaseAdjustSevereInfestation() { return 1; }
inline int diseaseAdjustLowHitPoints() { return 1; }

// The adjustments never apply to parasitic
// infestation determination.
inline bool diseaseAdjustmentsApplyToParasites() {
    return false;
}

// A die score of 0 or less on either roll means the
// character does not contract.
inline bool diseaseRollMeansNoContraction(int die) {
    return die <= 0;
}

// ----------------------------------------------------------------------------
// Death from disease or infestation
// ----------------------------------------------------------------------------

// The raised character is 90 percent likely to
// still suffer the cause unless a curative is
// used; permanent ability losses are never
// corrected by any curative.
inline int diseaseDeathRelapseChance() { return 90; }
inline bool diseasePermanentLossFixedByCurative() {
    return false;
}

} // namespace rules
