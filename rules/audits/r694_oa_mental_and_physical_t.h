    // ---- R694 OA mental and physical training audit ----
    // OA round eighty-one (capture pp. 232-233): the Mental and Physical
    // Training maneuvers - Meditation, All-Around Sight, Mental Resistance,
    // Blind Fighting, Ironskin and Levitation - with the Stunning and
    // Incapacitating rules, single-pass pins per the Chapter 9 provenance
    // shift
    {
        using namespace rules;
        int bad = 0;
    if (djhMentalResSaveBonus() != 2
            || djhBlindFightPenalty() != 1
            || djhIronskinACBonus() != 2
            || djhLevConcTurns() != 1
            || djhLevMoveFt() != 5
            || djhLevRestRounds() != 1
            || djhStunHitRoll() != 20
            || djhStunDie() != 6
            || djhIncapHoursMin() != 1
            || djhIncapHoursMax() != 3
            || djhExtraDieHDBonus() != 4
            || !djhTrainAnyStyle()
            || !djhMeditationShukenjaPowers()
            || !djhMeditationFreeSlot()
            || !djhAllAroundSightConst()
            || !djhAllAroundNoBackAttack()
            || !djhMentalResConst()
            || !djhBlindFightConst()
            || !djhBlindFightSilenceRule()
            || !djhIronskinUnarmoredOnly()
            || !djhLevRarest()
            || !djhLevNoActions()
            || !djhStunManSizedOnly()
            || !djhStunUnmodifiedOnly()
            || !djhStunSavePara()
            || !djhStunSaveSuccessDamage()
            || !djhStunCompareHD()
            || !djhExtraDieRule()
        )
            ++bad;
        // the training constants - the mental +2, the blind -1, the ironskin
        // AC 2
    if (djhMentalResSaveBonus() != 2
            || djhBlindFightPenalty() != 1
            || djhIronskinACBonus() != 2
        )
            ++bad;
        // the levitation - one turn of concentration, five feet per round,
        // one round of rest
    if (djhLevConcTurns() != 1
            || djhLevMoveFt() != 5
            || djhLevRestRounds() != 1
        )
            ++bad;
        // the stun trigger - the unmodified 20 and the 1d6 round stun die
    if (djhStunHitRoll() != 20
            || djhStunDie() != 6
        )
            ++bad;
        // the incapacitation hours - 1 to 3, the OCR artifact t-3 resolved
        // per the lizard man example
    if (djhIncapHoursMin() != 1
            || djhIncapHoursMax() != 3
        )
            ++bad;
        // the extra-die threshold - the +4 or greater hit dice bonus treated
        // as one extra die
    if (djhExtraDieHDBonus() != 4
        )
            ++bad;
        printf("R694 OA mental and physical training audit: bad %d\n", bad);
        if (bad) return 1;
    }
