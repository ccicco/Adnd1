// R-refactor: split from insanity.h - definitions
#include "rules/dmg/insanity.h"

IntoxState Insanity::intoxicationClamp(IntoxState s) {
    if (s < INTOX_SOBER) s = INTOX_SOBER;
    if (s > INTOX_COMATOSE) s = INTOX_COMATOSE;
    return s;
}

int Insanity::intoxicationBraveryAdjust(IntoxState s) {
    static const int k[5] = { 0, 1, 2, 4, 0 };
    return k[intoxicationClamp(s)];
}

int Insanity::intoxicationMoraleAdjust(IntoxState s) {
    static const int k[5] = { 0, 5, 10, 15, 0 };
    return k[intoxicationClamp(s)];
}

int Insanity::intoxicationIntelligenceAdjust(IntoxState s) {
    static const int k[5] = { 0, -1, -3, -6, 0 };
    return k[intoxicationClamp(s)];
}

int Insanity::intoxicationWisdomAdjust(IntoxState s) {
    static const int k[5] = { 0, -1, -4, -7, 0 };
    return k[intoxicationClamp(s)];
}

int Insanity::intoxicationDexterityAdjust(IntoxState s) {
    static const int k[5] = { 0, 0, -2, -5, 0 };
    return k[intoxicationClamp(s)];
}

int Insanity::intoxicationCharismaAdjust(IntoxState s) {
    static const int k[5] = { 0, 0, -1, -4, 0 };
    return k[intoxicationClamp(s)];
}

int Insanity::intoxicationAttackDiceAdjust(IntoxState s) {
    static const int k[5] = { 0, 0, -1, -5, 0 };
    return k[intoxicationClamp(s)];
}

int Insanity::intoxicationHitPointAdjust(IntoxState s) {
    static const int k[5] = { 0, 0, 1, 3, 0 };
    return k[intoxicationClamp(s)];
}

int Insanity::intoxicationMagicSaveRaise(IntoxState s) {
    return -intoxicationAttackDiceAdjust(s);
}

int Insanity::intoxicationMagicSaveRaisePercent(IntoxState s) {
    static const int k[5] = { 0, 0, 5, 25, 0 };
    return k[intoxicationClamp(s)];
}

int Insanity::intoxicationComatoseSleepMin() { return 7; }

int Insanity::intoxicationComatoseSleepMax() { return 10; }

int Insanity::intoxicationRecoveryMin(IntoxState s) {
    static const int k[5] = { 0, 1, 2, 4, 7 };
    return k[intoxicationClamp(s)];
}

int Insanity::intoxicationRecoveryMax(IntoxState s) {
    static const int k[5] = { 0, 2, 4, 6, 10 };
    return k[intoxicationClamp(s)];
}

int Insanity::intoxicationStimulantPercent( IntoxState s, bool strong) {
    static const int kMild[5] = { 100, 80, 85, 90, 95 };
    static const int kStrong[5] = { 100, 50, 55, 55, 60 };
    return strong ? kStrong[intoxicationClamp(s)]
                  : kMild[intoxicationClamp(s)];
}

int Insanity::intoxicationStrongStimulantConChance() {
    return 5;
}

int Insanity::intoxicationStrongStimulantConLoss() {
    return 1;
}

const char* Insanity::insanityName(int type) {
    static const char* const k[21] = {
        "",
        "dipsomania",
        "kleptomania",
        "schizoid",
        "pathological liar",
        "monomania",
        "dementia praecox",
        "melancholia",
        "megalomania",
        "delusional insanity",
        "schizophrenia",
        "mania",
        "lunacy",
        "paranoia",
        "manic-depressive",
        "hallucinatory insanity",
        "sado-masochism",
        "homicidal mania",
        "hebephrenia",
        "suicidal mania",
        "catatonia"
    };
    if (type < 1) type = 1;
    if (type > 20) type = 20;
    return k[type];
}

bool Insanity::insanityIsMild(int type) {
    return type >= 1 && type <= 4;
}

int Insanity::insanityTemporaryWeeksMin() { return 2; }

int Insanity::insanityTemporaryWeeksMax() { return 12; }

int Insanity::insanityMildWeeksMin() { return 1; }

int Insanity::insanityMildWeeksMax() { return 4; }

int Insanity::insanityDipsomaniaContinueNearAlcohol() {
    return 50;
}

int Insanity::insanityDipsomaniaContinueOtherwise() {
    return 10;
}

int Insanity::insanityKleptomaniaSeenChance() { return 90; }

int Insanity::insanityKleptomaniaThiefPenalty() { return -10; }

int Insanity::insanityDementiaPraecoxIgnoreChance() { return 25; }

int Insanity::insanityMelancholiaIgnoreChance() { return 50; }

int Insanity::insanitySchizophreniaPersonalitiesMin() { return 1; }

int Insanity::insanitySchizophreniaPersonalitiesMax() { return 4; }

int Insanity::insanityOnsetChanceIn6() { return 1; }

int Insanity::insanityManiaDurationMinTurns() { return 2; }

int Insanity::insanityManiaDurationMaxTurns() { return 12; }

int Insanity::insanityManiaStrengthState(int d6) {
    static const int k[7] = { 0, 50, 75, 100, 100, 100, 100 };
    if (d6 < 1) d6 = 1;
    if (d6 > 6) d6 = 6;
    return k[d6];
}

int Insanity::insanityManicDepressiveCycleMinDays() { return 1; }

int Insanity::insanityManicDepressiveCycleMaxDays() { return 4; }

int Insanity::insanityManicDepressiveFlipChance() { return 90; }

int Insanity::insanityHallucinatoryNormalChance() { return 50; }

int Insanity::insanityHallucinatoryDurationMinTurns() { return 1; }

int Insanity::insanityHallucinatoryDurationMaxTurns() { return 20; }

int Insanity::insanitySadoMasoNormalMinDays() { return 1; }

int Insanity::insanitySadoMasoNormalMaxDays() { return 3; }

int Insanity::insanityHomicidalIntervalMinDays() { return 1; }

int Insanity::insanityHomicidalIntervalMaxDays() { return 4; }

int Insanity::insanityHomicidalMelancholiaMinDays() { return 1; }

int Insanity::insanityHomicidalMelancholiaMaxDays() { return 6; }

int Insanity::insanityHebephreniaEnrageChance() { return 75; }

int Insanity::insanityHebephreniaCatatonicMinHours() { return 1; }

int Insanity::insanityHebephreniaCatatonicMaxHours() { return 6; }

int Insanity::insanitySuicidalScaleMin() { return 10; }

int Insanity::insanitySuicidalScaleMax() { return 80; }

int Insanity::insanitySuicidalManiaMinTurns() { return 2; }

int Insanity::insanitySuicidalManiaMaxTurns() { return 8; }

int Insanity::insanitySuicidalMelancholyMinDays() { return 2; }

int Insanity::insanitySuicidalMelancholyMaxDays() { return 12; }

int Insanity::insanityCatatoniaReactionChance() { return 1; }
