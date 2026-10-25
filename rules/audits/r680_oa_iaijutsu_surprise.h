    // ---- R680 OA iaijutsu surprise audit ----
    // OA round sixty-seven (capture p. 218): the Surprise and Iaijutsu
    // dueling draw doctrine - the -1 surprise modifier with the
    // special-situations scope and the two exceptions, single-pass pins per
    // the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (diqIaijutsuSurpriseModifier() != 1
            || diqIaijutsuBothTrappedCount() != 2
            || !diqIaijutsuSpecialSituationsOnly()
            || !diqIaijutsuUntrainedCarriesPenalty()
            || !diqIaijutsuBothSidesRollSurprise()
            || !diqIaijutsuNilWhenWeaponsDrawn()
            || !diqIaijutsuNilWhenAttackExpected()
            || !diqIaijutsuPeacefulEruptionOnly()
        )
            ++bad;
        // the modifier pins - the -1 iaijutsu surprise modifier and the
        // both-trained case applying it to both rolls
    if (diqIaijutsuSurpriseModifier() != 1
            || diqIaijutsuBothTrappedCount() != 2
        )
            ++bad;
        // the scope pins - special situations only, the untrained character
        // carrying the penalty, both sides rolling surprise when the
        // situation erupts
    if (diqIaijutsuSpecialSituationsOnly() != 1
            || diqIaijutsuUntrainedCarriesPenalty() != 1
            || diqIaijutsuBothSidesRollSurprise() != 1
        )
            ++bad;
        // the exception pins - no modifier when weapons are already drawn,
        // none when the attack is expected, the modifier living only in the
        // peaceful-eruption case
    if (diqIaijutsuNilWhenWeaponsDrawn() != 1
            || diqIaijutsuNilWhenAttackExpected() != 1
            || diqIaijutsuPeacefulEruptionOnly() != 1
        )
            ++bad;
        // the modifier shape - the -1 read as the absolute 1 pin, applied to
        // at most the two rolls of the both-trained case
    if (diqIaijutsuSurpriseModifier() != 1
            || diqIaijutsuBothTrappedCount() != 2
            || diqIaijutsuSurpriseModifier() > diqIaijutsuBothTrappedCount()
        )
            ++bad;
        printf("R680 OA iaijutsu surprise audit: bad %d\n", bad);
        if (bad) return 1;
    }
