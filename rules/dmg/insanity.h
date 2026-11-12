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

// R-refactor: namespace rules -> class Insanity (instance methods)
class Insanity {
public:
    IntoxState intoxicationClamp(IntoxState s);


// The eight table rows, slight/moderate/great.
// Bravery moves up towards foolhardy; morale is
// NPC-only; hp RISE with the drug.
    int intoxicationBraveryAdjust(IntoxState s);
    int intoxicationMoraleAdjust(IntoxState s);
    int intoxicationIntelligenceAdjust(IntoxState s);
    int intoxicationWisdomAdjust(IntoxState s);
    int intoxicationDexterityAdjust(IntoxState s);
    int intoxicationCharismaAdjust(IntoxState s);
    int intoxicationAttackDiceAdjust(IntoxState s);
    int intoxicationHitPointAdjust(IntoxState s);


// Opponent saves vs magic from the intoxicated
// character rise by the attack-dice number: the
// point value (1 or 5) and its percent form
// (5 or 25).
    int intoxicationMagicSaveRaise(IntoxState s);
    int intoxicationMagicSaveRaisePercent(IntoxState s);


// Comatose sleep: 7-10 hours.
    int intoxicationComatoseSleepMin();
    int intoxicationComatoseSleepMax();


// ----------------------------------------------------------------------------
// Recovery (p.83)
// ----------------------------------------------------------------------------

// Recovery time in hours per state (time is the
// only cure).
    int intoxicationRecoveryMin(IntoxState s);
    int intoxicationRecoveryMax(IntoxState s);


// Stimulant effect as a percent multiplier on the
// recovery time (the print: x .80/.85/.90/.95 mild,
// x .50/.55/.55/.60 strong).
    int intoxicationStimulantPercent( IntoxState s, bool strong);


// A strong stimulant: 5 percent per application of
// permanently lowering constitution by 1. Mild
// stimulants are harmless.
    int intoxicationStrongStimulantConChance();
    int intoxicationStrongStimulantConLoss();


// ----------------------------------------------------------------------------
// The types of insanity (p.83)
// ----------------------------------------------------------------------------

// The 20 named forms, 1-20 in the printed order.
// 1-4 are MILD (subject to psionic attack); 11-20
// the print lists under COMBAT (INSANITY).
    const char* name(int type);


// The four mild forms (the print star): subject to
// psionic attack.
    bool isMild(int type);


// The psionic-section duration classes: permanent
// (until heal, restoration or wish; TWO forms),
// temporary (2-12 weeks; otherwise as permanent),
// mild (1-4 weeks; ONE form).
    int temporaryWeeksMin();
    int temporaryWeeksMax();
    int mildWeeksMin();
    int mildWeeksMax();


// 1. Dipsomania: drinking until passing out about
// once per week; 50 percent it continues on waking
// near alcohol, 10 percent otherwise.
    int dipsomaniaContinueNearAlcohol();
    int dipsomaniaContinueOtherwise();


// 2. Kleptomania: 90 percent chance of being seen
// if observed; thieves and assassins steal at -10
// percent.
    int kleptomaniaSeenChance();
    int kleptomaniaThiefPenalty();


// 6. Dementia praecox: 25 percent to ignore any
// situation as meaningless.
    int dementiaPraecoxIgnoreChance();


// 7. Melancholia: 50 percent to ignore a given
// situation.
    int melancholiaIgnoreChance();


// 10. Schizophrenia: 1-4 personalities; onset 1 in 6
// per day, checked every round under stress.
    int schizophreniaPersonalitiesMin();
    int schizophreniaPersonalitiesMax();
    int onsetChanceIn6();


// 11. Mania: strikes 1 in 6 per turn, lasts 2-12
// turns, 1 in 6 per turn of return; the d6 strength
// states 18/50, 18/75, 18/00.
    int maniaDurationMinTurns();
    int maniaDurationMaxTurns();
    int maniaStrengthState(int d6);


// 14. Manic-depressive: 1-4 day cycle; 90 percent
// likely to flip on excitement or frustration.
    int manicDepressiveCycleMinDays();
    int manicDepressiveCycleMaxDays();
    int manicDepressiveFlipChance();


// 15. Hallucinatory insanity: 50 percent normal
// until stimulated; hallucinations 1-20 turns
// after the excitement passes.
    int hallucinatoryNormalChance();
    int hallucinatoryDurationMinTurns();
    int hallucinatoryDurationMaxTurns();


// 16. Sado-masochism: normalcy returns 1-3 days
// after acting out either phase.
    int sadoMasoNormalMinDays();
    int sadoMasoNormalMaxDays();


// 17. Homicidal mania: the kill urge on 1-4 day
// intervals; frustrated killing means mania, then
// melancholia 1-6 days.
    int homicidalIntervalMinDays();
    int homicidalIntervalMaxDays();
    int homicidalMelancholiaMinDays();
    int homicidalMelancholiaMaxDays();


// 18. Hebephrenia: 75 percent enraged when
// irritated, else catatonic 1-6 hours.
    int hebephreniaEnrageChance();
    int hebephreniaCatatonicMinHours();
    int hebephreniaCatatonicMaxHours();


// 19. Suicidal mania: a 10-80 percent scale by
// danger; frustration means mania 2-8 turns,
// then melancholy 2-12 days.
    int suicidalScaleMin();
    int suicidalScaleMax();
    int suicidalManiaMinTurns();
    int suicidalManiaMaxTurns();
    int suicidalMelancholyMinDays();
    int suicidalMelancholyMaxDays();


// 20. Catatonia: a 1 percent cumulative chance per
// round of provocation of homicidal mania; the
// catatonia returns once provocation ceases.
    int catatoniaReactionChance();
};
