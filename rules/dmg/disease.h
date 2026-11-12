// ====================================================================
// Adnd1 - rules/dmg/disease.h
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

// R-refactor: namespace rules -> class Disease (instance methods)
class Disease {
public:


// ----------------------------------------------------------------------------
// Contraction chances (p.13)
// ----------------------------------------------------------------------------
    int contractBasePercent();
    int parasiteContractBasePercent();


// The printed disease modifiers (percent).
    int modCurrentlyAfflicted();
    int modCrowding();
    int modFilth();
    int modOld();
    int modMarshEnvironment();
    int modHotMoist();
    int modVenerable();
    int modCarrierExposure();
    int modCoolClimate();
    int modColdHighMountains();
    int modShipboardPastTwoWeeks();


// The printed parasite modifiers (percent).
    int parasiteModFilth();
    int parasiteModImproperlyCookedMeat();
    int parasiteModPollutedWater();
    int parasiteModSwampJungle();
    int parasiteModCoolOrDesert();
    int parasiteModColdOrCoolDesert();


// The check cadence: monthly, weekly when favorable,
// and on every carrier exposure.
    bool weeklyCheckWhenFavorable();
    bool checkOnEachCarrierExposure();


// ----------------------------------------------------------------------------
// The disease (or disorder) table (p.14) - 16 areas
// ----------------------------------------------------------------------------
    int areaCount();
    const char* areaName(int idx);


// Row index for a d100 score (97-00 reads as 97-100).
    int areaForD100(int d100);


// Occurrence by d8: acute up to kAcuteHi, chronic
// from kChronicLo (chronic always runs to 8).
    int acuteHi(int idx);
    int chronicLo(int idx);
    bool isAcute(int idx, int d8);
    bool isChronic(int idx, int d8);


// Severity by d8: 0 means the column prints a dash
// (no terminal result for that area).
    int severityMildHi(int idx);
    int severitySevereHi(int idx);
    int severityTerminalHi(int idx);


// ----------------------------------------------------------------------------
// The parasitic infestation table (p.14) - 6 areas
// ----------------------------------------------------------------------------
    int parasiteAreaCount();
    const char* parasiteAreaName(int idx);
    int parasiteAreaForD100(int d100);


// Severity by d8 (no occurrence roll for parasites).
    int parasiteSeverityMildHi(int idx);
    int parasiteSeveritySevereHi(int idx);
    int parasiteSeverityTerminalHi(int idx);


// ----------------------------------------------------------------------------
// Severity effects and durations (p.14)
// ----------------------------------------------------------------------------
    int mildWeeksMin();
    int mildWeeksMax();
    int severeHitPointPercent();
    int severeDisabledWeeksMin();
    int severeDisabledWeeksMax();
    int severeMildRecoveryWeeksMin();
    int severeMildRecoveryWeeksMax();
    int terminalDaysMin();
    int terminalDaysMax();
    DiseaseDurationUnit terminalUnit(int idx);


// The three areas with no terminal column at all
// (joints, mucous membranes, nose-throat).
    bool hasTerminalColumn(int idx);


// Ears terminal: hearing loss in one ear. Eyes
// terminal: blindness in one or both eyes, 50/50.
    bool terminalIsFunctionLoss(int idx);
    int eyesBlindBothChance();


// Connective tissue: terminal treated as chronic
// severe (it lasts until constitution reaches 0).
    bool terminalTreatedAsChronicSevere( int idx);


// ----------------------------------------------------------------------------
// Per-area ability losses (p.14)
// ----------------------------------------------------------------------------

// Blood: -1 strength and -1 constitution per week
// until totally cured.
    int bloodWeeklyStrLoss();
    int bloodWeeklyConLoss();


// Brain: -1 intelligence and -1 dexterity per
// occurrence until totally cured.
    int brainIntLoss();
    int brainDexLoss();


// Connective tissue: -1 each strength, dexterity,
// constitution and charisma per month of
// affliction (permanent).
    int connectiveMonthlyLoss();


// Gastro-intestinal: -1 strength and -1
// constitution per occurrence; severe attacks
// cause the loss permanently.
    int gastroStrConLoss();


// Joints: chronic -1 dexterity per occurrence,
// severe attacks permanent.
    int jointsDexLoss();


// Mucous membranes: chronic -1 constitution,
// severe attacks permanent.
    int mucousConLoss();


// Muscles: chronic -1 strength and -1 dexterity;
// severe attacks 25 percent permanent.
    int muscleStrDexLoss();
    int muscleSeverePermanentChance();


// Nose-throat: 10 percent of -1 constitution per
// severe attack.
    int noseThroatSevereConLossChance();


// Respiratory: 10 percent of -1 strength and -1
// constitution (checked separately).
    int respiratoryLossChance();


// Skin: severe 10 percent permanent -1 charisma;
// chronic mild 10 percent; chronic severe 25
// percent.
    int skinSevereChaLossChance();
    int skinChronicMildChance();
    int skinChronicSevereChance();


// Urinary: chronic severe 20 percent of -1
// dexterity and -1 constitution per occurrence.
    int urinaryLossChance();


// ----------------------------------------------------------------------------
// The occurrence/severity die roll adjustments
// ----------------------------------------------------------------------------

// The constitution ladder (disease only, NOT
// parasitic infestation): under 3 +2, 3-5 +1,
// 6-9 0, 10-12 -1, 13-15 -2, 16-17 -3, 18 -4.
    int conRollAdjust(int con);


// The three condition modifiers: chronic disease
// or disorder +1, severe parasitic infestation +1,
// under 25 percent of normal hit points +1.
    int adjustChronicDisease();
    int adjustSevereInfestation();
    int adjustLowHitPoints();


// The adjustments never apply to parasitic
// infestation determination.
    bool adjustmentsApplyToParasites();


// A die score of 0 or less on either roll means the
// character does not contract.
    bool rollMeansNoContraction(int die);


// ----------------------------------------------------------------------------
// Death from disease or infestation
// ----------------------------------------------------------------------------

// The raised character is 90 percent likely to
// still suffer the cause unless a curative is
// used; permanent ability losses are never
// corrected by any curative.
    int deathRelapseChance();
    bool permanentLossFixedByCurative();
};
