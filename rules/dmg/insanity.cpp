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

const char* Insanity::name(int type) {
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

bool Insanity::isMild(int type) {
    return type >= 1 && type <= 4;
}

int Insanity::temporaryWeeksMin() { return 2; }

int Insanity::temporaryWeeksMax() { return 12; }

int Insanity::mildWeeksMin() { return 1; }

int Insanity::mildWeeksMax() { return 4; }

int Insanity::dipsomaniaContinueNearAlcohol() {
    return 50;
}

int Insanity::dipsomaniaContinueOtherwise() {
    return 10;
}

int Insanity::kleptomaniaSeenChance() { return 90; }

int Insanity::kleptomaniaThiefPenalty() { return -10; }

int Insanity::dementiaPraecoxIgnoreChance() { return 25; }

int Insanity::melancholiaIgnoreChance() { return 50; }

int Insanity::schizophreniaPersonalitiesMin() { return 1; }

int Insanity::schizophreniaPersonalitiesMax() { return 4; }

int Insanity::onsetChanceIn6() { return 1; }

int Insanity::maniaDurationMinTurns() { return 2; }

int Insanity::maniaDurationMaxTurns() { return 12; }

int Insanity::maniaStrengthState(int d6) {
    static const int k[7] = { 0, 50, 75, 100, 100, 100, 100 };
    if (d6 < 1) d6 = 1;
    if (d6 > 6) d6 = 6;
    return k[d6];
}

int Insanity::manicDepressiveCycleMinDays() { return 1; }

int Insanity::manicDepressiveCycleMaxDays() { return 4; }

int Insanity::manicDepressiveFlipChance() { return 90; }

int Insanity::hallucinatoryNormalChance() { return 50; }

int Insanity::hallucinatoryDurationMinTurns() { return 1; }

int Insanity::hallucinatoryDurationMaxTurns() { return 20; }

int Insanity::sadoMasoNormalMinDays() { return 1; }

int Insanity::sadoMasoNormalMaxDays() { return 3; }

int Insanity::homicidalIntervalMinDays() { return 1; }

int Insanity::homicidalIntervalMaxDays() { return 4; }

int Insanity::homicidalMelancholiaMinDays() { return 1; }

int Insanity::homicidalMelancholiaMaxDays() { return 6; }

int Insanity::hebephreniaEnrageChance() { return 75; }

int Insanity::hebephreniaCatatonicMinHours() { return 1; }

int Insanity::hebephreniaCatatonicMaxHours() { return 6; }

int Insanity::suicidalScaleMin() { return 10; }

int Insanity::suicidalScaleMax() { return 80; }

int Insanity::suicidalManiaMinTurns() { return 2; }

int Insanity::suicidalManiaMaxTurns() { return 8; }

int Insanity::suicidalMelancholyMinDays() { return 2; }

int Insanity::suicidalMelancholyMaxDays() { return 12; }

int Insanity::catatoniaReactionChance() { return 1; }
