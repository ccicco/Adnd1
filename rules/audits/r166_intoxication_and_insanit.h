    // ---- R166: intoxication and insanity audit ------
    // DMG pp.82-83: the intoxication table, the
    // recovery table with the stimulant multipliers,
    // the comatose sleep, the 20 named insanity
    // forms with the mild-star and each form printed
    // numeric parameter, and the duration classes.
    {
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
            rules::IntoxState s =
                (i == 0) ? rules::INTOX_SLIGHT
                : (i == 1) ? rules::INTOX_MODERATE
                : rules::INTOX_GREAT;
            if (rules::intoxicationBraveryAdjust(s) != kBrave[i] ||
                rules::intoxicationMoraleAdjust(s) != kMorale[i] ||
                rules::intoxicationIntelligenceAdjust(s) != kInt[i] ||
                rules::intoxicationWisdomAdjust(s) != kWis[i] ||
                rules::intoxicationDexterityAdjust(s) != kDex[i] ||
                rules::intoxicationCharismaAdjust(s) != kCha[i] ||
                rules::intoxicationAttackDiceAdjust(s) != kAtk[i] ||
                rules::intoxicationHitPointAdjust(s) != kHp[i])
                ++bad;
        }
        // the magic-save raise rides the attack-dice
        // number: 1/5 points, 5/25 percent
        if (rules::intoxicationMagicSaveRaise(
                rules::INTOX_MODERATE) != 1 ||
            rules::intoxicationMagicSaveRaise(
                rules::INTOX_GREAT) != 5 ||
            rules::intoxicationMagicSaveRaisePercent(
                rules::INTOX_MODERATE) != 5 ||
            rules::intoxicationMagicSaveRaisePercent(
                rules::INTOX_GREAT) != 25) ++bad;
        // sober and comatose read zero on every row
        if (rules::intoxicationBraveryAdjust(rules::INTOX_SOBER) != 0 ||
            rules::intoxicationHitPointAdjust(rules::INTOX_COMATOSE) != 0)
            ++bad;
        // comatose sleep 7-10 hours
        if (rules::intoxicationComatoseSleepMin() != 7 ||
            rules::intoxicationComatoseSleepMax() != 10) ++bad;
        // the recovery table: hours and multipliers
        static const int kRecMin[4] = { 1, 2, 4, 7 };
        static const int kRecMax[4] = { 2, 4, 6, 10 };
        static const int kMild[4] = { 80, 85, 90, 95 };
        static const int kStrong[4] = { 50, 55, 55, 60 };
        for (int i = 0; i < 4; ++i) {
            rules::IntoxState s =
                (rules::IntoxState)(i + 1);
            if (rules::intoxicationRecoveryMin(s) != kRecMin[i] ||
                rules::intoxicationRecoveryMax(s) != kRecMax[i] ||
                rules::intoxicationStimulantPercent(s, false)
                    != kMild[i] ||
                rules::intoxicationStimulantPercent(s, true)
                    != kStrong[i])
                ++bad;
        }
        // the strong-stimulant constitution risk
        if (rules::intoxicationStrongStimulantConChance() != 5 ||
            rules::intoxicationStrongStimulantConLoss() != 1)
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
            if (std::string(rules::insanityName(i))
                    != kNames[i - 1]) ++bad;
        if (std::string(rules::insanityName(0))
                != kNames[0] ||
            std::string(rules::insanityName(21))
                != kNames[19]) ++bad;
        // the mild star: types 1-4 only
        for (int i = 1; i <= 20; ++i)
            if (rules::insanityIsMild(i) != (i <= 4)) ++bad;
        // the duration classes
        if (rules::insanityTemporaryWeeksMin() != 2 ||
            rules::insanityTemporaryWeeksMax() != 12 ||
            rules::insanityMildWeeksMin() != 1 ||
            rules::insanityMildWeeksMax() != 4) ++bad;
        // the per-form printed parameters
        if (rules::insanityDipsomaniaContinueNearAlcohol() != 50 ||
            rules::insanityDipsomaniaContinueOtherwise() != 10 ||
            rules::insanityKleptomaniaSeenChance() != 90 ||
            rules::insanityKleptomaniaThiefPenalty() != -10 ||
            rules::insanityDementiaPraecoxIgnoreChance() != 25 ||
            rules::insanityMelancholiaIgnoreChance() != 50)
            ++bad;
        if (rules::insanitySchizophreniaPersonalitiesMin() != 1 ||
            rules::insanitySchizophreniaPersonalitiesMax() != 4 ||
            rules::insanityOnsetChanceIn6() != 1 ||
            rules::insanityManiaDurationMinTurns() != 2 ||
            rules::insanityManiaDurationMaxTurns() != 12)
            ++bad;
        // the mania strength states: 18/50, 18/75,
        // 18/00 - the percent-of-exceptional encoding
        if (rules::insanityManiaStrengthState(1) != 50 ||
            rules::insanityManiaStrengthState(2) != 75 ||
            rules::insanityManiaStrengthState(3) != 100 ||
            rules::insanityManiaStrengthState(6) != 100)
            ++bad;
        if (rules::insanityManicDepressiveCycleMinDays() != 1 ||
            rules::insanityManicDepressiveCycleMaxDays() != 4 ||
            rules::insanityManicDepressiveFlipChance() != 90 ||
            rules::insanityHallucinatoryNormalChance() != 50 ||
            rules::insanityHallucinatoryDurationMinTurns() != 1 ||
            rules::insanityHallucinatoryDurationMaxTurns() != 20)
            ++bad;
        if (rules::insanitySadoMasoNormalMinDays() != 1 ||
            rules::insanitySadoMasoNormalMaxDays() != 3 ||
            rules::insanityHomicidalIntervalMinDays() != 1 ||
            rules::insanityHomicidalIntervalMaxDays() != 4 ||
            rules::insanityHomicidalMelancholiaMinDays() != 1 ||
            rules::insanityHomicidalMelancholiaMaxDays() != 6)
            ++bad;
        if (rules::insanityHebephreniaEnrageChance() != 75 ||
            rules::insanityHebephreniaCatatonicMinHours() != 1 ||
            rules::insanityHebephreniaCatatonicMaxHours() != 6 ||
            rules::insanitySuicidalScaleMin() != 10 ||
            rules::insanitySuicidalScaleMax() != 80 ||
            rules::insanitySuicidalManiaMinTurns() != 2 ||
            rules::insanitySuicidalManiaMaxTurns() != 8 ||
            rules::insanitySuicidalMelancholyMinDays() != 2 ||
            rules::insanitySuicidalMelancholyMaxDays() != 12 ||
            rules::insanityCatatoniaReactionChance() != 1)
            ++bad;
        printf("R166 intoxication and insanity audit: bad %d\n", bad);
        if (bad) return 1;
    }
