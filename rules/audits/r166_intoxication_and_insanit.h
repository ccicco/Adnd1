    // ---- R166: intoxication and insanity audit ------
    // DMG pp.82-83: the intoxication table, the
    // recovery table with the stimulant multipliers,
    // the comatose sleep, the 20 named insanity
    // forms with the mild-star and each form printed
    // numeric parameter, and the duration classes.
    {
        Insanity insanity;
        int bad = 0;
        // the intoxication table: slight/moderate/great
        static const int kBrave[3] = { 1, 2, 4 };
        static const int kMorale[3] = { 5, 10, 15 };
        static const int kInt[3] = { -1, -3, -6 };
        static const int kWis[3] = { -1, -4, -7 };
        static const int kDex[3] = { 0, -2, -5 };
        static const int kCha[3] = { 0, -1, -4 };
        static const int kAtk[3] = { 0, -1, -5 };
        static const int kHp[3] = { 0, 1, 3 };
        for (int i = 0; i < 3; ++i) {
            Insanity insanity;
            IntoxState s =
                (i == 0) ? INTOX_SLIGHT
                : (i == 1) ? INTOX_MODERATE
                : INTOX_GREAT;
            if (insanity.intoxicationBraveryAdjust(s) != kBrave[i] ||
                insanity.intoxicationMoraleAdjust(s) != kMorale[i] ||
                insanity.intoxicationIntelligenceAdjust(s) != kInt[i] ||
                insanity.intoxicationWisdomAdjust(s) != kWis[i] ||
                insanity.intoxicationDexterityAdjust(s) != kDex[i] ||
                insanity.intoxicationCharismaAdjust(s) != kCha[i] ||
                insanity.intoxicationAttackDiceAdjust(s) != kAtk[i] ||
                insanity.intoxicationHitPointAdjust(s) != kHp[i])
                ++bad;
        }
        // the magic-save raise rides the attack-dice
        // number: 1/5 points, 5/25 percent
        if (insanity.intoxicationMagicSaveRaise(
                INTOX_MODERATE) != 1 ||
            insanity.intoxicationMagicSaveRaise(
                INTOX_GREAT) != 5 ||
            insanity.intoxicationMagicSaveRaisePercent(
                INTOX_MODERATE) != 5 ||
            insanity.intoxicationMagicSaveRaisePercent(
                INTOX_GREAT) != 25) ++bad;
        // sober and comatose read zero on every row
        if (insanity.intoxicationBraveryAdjust(INTOX_SOBER) != 0 ||
            insanity.intoxicationHitPointAdjust(INTOX_COMATOSE) != 0)
            ++bad;
        // comatose sleep 7-10 hours
        if (insanity.intoxicationComatoseSleepMin() != 7 ||
            insanity.intoxicationComatoseSleepMax() != 10) ++bad;
        // the recovery table: hours and multipliers
        static const int kRecMin[4] = { 1, 2, 4, 7 };
        static const int kRecMax[4] = { 2, 4, 6, 10 };
        static const int kMild[4] = { 80, 85, 90, 95 };
        static const int kStrong[4] = { 50, 55, 55, 60 };
        for (int i = 0; i < 4; ++i) {
            Insanity insanity;
            IntoxState s =
                (IntoxState)(i + 1);
            if (insanity.intoxicationRecoveryMin(s) != kRecMin[i] ||
                insanity.intoxicationRecoveryMax(s) != kRecMax[i] ||
                insanity.intoxicationStimulantPercent(s, false)
                    != kMild[i] ||
                insanity.intoxicationStimulantPercent(s, true)
                    != kStrong[i])
                ++bad;
        }
        // the strong-stimulant constitution risk
        if (insanity.intoxicationStrongStimulantConChance() != 5 ||
            insanity.intoxicationStrongStimulantConLoss() != 1)
            ++bad;
        // the 20 named forms in printed order
        static const char* const kNames[20] = {
            "dipsomania", "kleptomania", "schizoid",
            "pathological liar", "monomania",
            "dementia praecox", "melancholia",
            "megalomania", "delusional insanity",
            "schizophrenia", "mania", "lunacy",
            "paranoia", "manic-depressive",
            "hallucinatory insanity", "sado-masochism",
            "homicidal mania", "hebephrenia",
            "suicidal mania", "catatonia"
        };
        for (int i = 1; i <= 20; ++i)
            if (std::string(insanity.insanityName(i))
                    != kNames[i - 1]) ++bad;
        if (std::string(insanity.insanityName(0))
                != kNames[0] ||
            std::string(insanity.insanityName(21))
                != kNames[19]) ++bad;
        // the mild star: types 1-4 only
        for (int i = 1; i <= 20; ++i)
            if (insanity.insanityIsMild(i) != (i <= 4)) ++bad;
        // the duration classes
        if (insanity.insanityTemporaryWeeksMin() != 2 ||
            insanity.insanityTemporaryWeeksMax() != 12 ||
            insanity.insanityMildWeeksMin() != 1 ||
            insanity.insanityMildWeeksMax() != 4) ++bad;
        // the per-form printed parameters
        if (insanity.insanityDipsomaniaContinueNearAlcohol() != 50 ||
            insanity.insanityDipsomaniaContinueOtherwise() != 10 ||
            insanity.insanityKleptomaniaSeenChance() != 90 ||
            insanity.insanityKleptomaniaThiefPenalty() != -10 ||
            insanity.insanityDementiaPraecoxIgnoreChance() != 25 ||
            insanity.insanityMelancholiaIgnoreChance() != 50)
            ++bad;
        if (insanity.insanitySchizophreniaPersonalitiesMin() != 1 ||
            insanity.insanitySchizophreniaPersonalitiesMax() != 4 ||
            insanity.insanityOnsetChanceIn6() != 1 ||
            insanity.insanityManiaDurationMinTurns() != 2 ||
            insanity.insanityManiaDurationMaxTurns() != 12)
            ++bad;
        // the mania strength states: 18/50, 18/75,
        // 18/00 - the percent-of-exceptional encoding
        if (insanity.insanityManiaStrengthState(1) != 50 ||
            insanity.insanityManiaStrengthState(2) != 75 ||
            insanity.insanityManiaStrengthState(3) != 100 ||
            insanity.insanityManiaStrengthState(6) != 100)
            ++bad;
        if (insanity.insanityManicDepressiveCycleMinDays() != 1 ||
            insanity.insanityManicDepressiveCycleMaxDays() != 4 ||
            insanity.insanityManicDepressiveFlipChance() != 90 ||
            insanity.insanityHallucinatoryNormalChance() != 50 ||
            insanity.insanityHallucinatoryDurationMinTurns() != 1 ||
            insanity.insanityHallucinatoryDurationMaxTurns() != 20)
            ++bad;
        if (insanity.insanitySadoMasoNormalMinDays() != 1 ||
            insanity.insanitySadoMasoNormalMaxDays() != 3 ||
            insanity.insanityHomicidalIntervalMinDays() != 1 ||
            insanity.insanityHomicidalIntervalMaxDays() != 4 ||
            insanity.insanityHomicidalMelancholiaMinDays() != 1 ||
            insanity.insanityHomicidalMelancholiaMaxDays() != 6)
            ++bad;
        if (insanity.insanityHebephreniaEnrageChance() != 75 ||
            insanity.insanityHebephreniaCatatonicMinHours() != 1 ||
            insanity.insanityHebephreniaCatatonicMaxHours() != 6 ||
            insanity.insanitySuicidalScaleMin() != 10 ||
            insanity.insanitySuicidalScaleMax() != 80 ||
            insanity.insanitySuicidalManiaMinTurns() != 2 ||
            insanity.insanitySuicidalManiaMaxTurns() != 8 ||
            insanity.insanitySuicidalMelancholyMinDays() != 2 ||
            insanity.insanitySuicidalMelancholyMaxDays() != 12 ||
            insanity.insanityCatatoniaReactionChance() != 1)
            ++bad;
        printf("R166 intoxication and insanity audit: bad %d\n", bad);
        if (bad) return 1;
    }
