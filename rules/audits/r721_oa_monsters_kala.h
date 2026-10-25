    // ---- R721 OA monsters Kala audit ----
    // OA round one hundred eight (capture pp. 272-273): the Chapter 12
    // monster roster - the kala, the paired Cave and Earth stat table riding
    // one flip, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkiKalaCount() != 2
            || dkiAttackCount() != 2
            || dkiXP6Base() != 825
            || dkiXP6PerHP() != 10
            || dkiXP8Base() != 1275
            || dkiXP8PerHP() != 6
            || dkiTrackBasePct() != 80
            || dkiPainRounds() != 5
            || dkiPainTurnsMin() != 1
            || dkiPainTurnsMax() != 3
            || dkiPainRound2ToHitPenalty() != 1
            || dkiPainRound3Penalty() != 2
            || dkiPainRound4Penalty() != 4
            || dkiDiseaseRangeFeet() != 5
            || dkiDiseaseWidthFeet() != 2
            || dkiDiseaseDmgDice() != 1
            || dkiDiseaseDmgSides() != 6
            || !dkiFrequencyRare()
            || !dkiSpecialDefensesNil()
            || !dkiMagicResistStandard()
            || !dkiIntelligenceLow()
            || !dkiAlignmentNeutral()
            || !dkiSizeMedium()
            || !dkiPsionicNil()
            || !dkiAncientPrimitiveSpiritRace()
            || !dkiColdWastelands()
            || !dkiSimilarToHumans()
            || !dkiPointedHeads()
            || !dkiLargeFeet()
            || !dkiInuredToCold()
            || !dkiFerocious()
            || !dkiCannibalistic()
            || !dkiExpertTrackers()
            || !dkiExpertHunters()
            || !dkiClawedHands()
            || !dkiStoneAxes()
            || !dkiCaveBitePoison()
            || !dkiPainBuildsSlowly()
            || !dkiPainRound1Headache()
            || !dkiPainRound5Incapacitated()
            || !dkiEarthBreathDisease()
            || !dkiDiseaseBlocksHealing()
            || !dkiCaveLairsInCaves()
            || !dkiEarthNomadic()
            || !dkiSpeaksNorthernTribes()
            || !dkiSpeaksOwnKind()
        )
            ++bad;
        // the dkiKala grid
        int CKala[2][8] = {
            {1,10,-1,9,8,30,1,8},
            {1,12,2,12,6,25,1,6},
            };
        int nKala[8] = {0,0,0,0,0,0,0,0};
        int eKala[8] = {0,0,0,0,0,0,0,0};
        for (int b = 0;
             b < dkiKalaCount();
             ++b) {
            int vals[8];
            vals[0] = dkiKalaAppearMin(b);
            vals[1] = dkiKalaAppearMax(b);
            vals[2] = dkiKalaAC(b);
            vals[3] = dkiKalaMove(b);
            vals[4] = dkiKalaHD(b);
            vals[5] = dkiKalaLairPct(b);
            vals[6] = dkiKalaDmgMin(b);
            vals[7] = dkiKalaDmgMax(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CKala[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nKala[c];
            }
        }
        for (int c = 0; c < 8; ++c)
            if (nKala[c] != eKala[c])
                ++bad;
        // the stat table - the paired stat columns, audited cell by cell by
        // the table audit
    if (dkiKalaCount() != 2
        )
            ++bad;
        // the shared stat lines - the lines shared by both columns, healthy
        // values, each condition false
    if (dkiFrequencyRare() != 1
            || dkiAttackCount() != 2
            || dkiSpecialDefensesNil() != 1
            || dkiMagicResistStandard() != 1
            || dkiIntelligenceLow() != 1
            || dkiAlignmentNeutral() != 1
            || dkiSizeMedium() != 1
            || dkiPsionicNil() != 1
            || dkiXP6Base() != 825
            || dkiXP6PerHP() != 10
            || dkiXP8Base() != 1275
            || dkiXP8PerHP() != 6
        )
            ++bad;
        // the spirit race - the pointed heads and large feet, healthy values,
        // each condition false
    if (dkiAncientPrimitiveSpiritRace() != 1
            || dkiColdWastelands() != 1
            || dkiSimilarToHumans() != 1
            || dkiPointedHeads() != 1
            || dkiLargeFeet() != 1
            || dkiInuredToCold() != 1
            || dkiFerocious() != 1
            || dkiCannibalistic() != 1
        )
            ++bad;
        // the hunters - the tracking and the axes, healthy values, each
        // condition false
    if (dkiExpertTrackers() != 1
            || dkiExpertHunters() != 1
            || dkiTrackBasePct() != 80
            || dkiClawedHands() != 1
            || dkiStoneAxes() != 1
        )
            ++bad;
        // the cave kala pain ladder - the five-round poison ladder, healthy
        // values, each condition false
    if (dkiCaveBitePoison() != 1
            || dkiPainBuildsSlowly() != 1
            || dkiPainRounds() != 5
            || dkiPainRound1Headache() != 1
            || dkiPainRound2ToHitPenalty() != 1
            || dkiPainRound3Penalty() != 2
            || dkiPainRound4Penalty() != 4
            || dkiPainRound5Incapacitated() != 1
            || dkiPainTurnsMin() != 1
            || dkiPainTurnsMax() != 3
        )
            ++bad;
        // the earth kala disease breath - the disease breath, healthy values,
        // each condition false
    if (dkiEarthBreathDisease() != 1
            || dkiDiseaseRangeFeet() != 5
            || dkiDiseaseWidthFeet() != 2
            || dkiDiseaseDmgDice() != 1
            || dkiDiseaseDmgSides() != 6
            || dkiDiseaseBlocksHealing() != 1
        )
            ++bad;
        // the lairs and tongues - the cave den and the nomad camp, healthy
        // values, each condition false
    if (dkiCaveLairsInCaves() != 1
            || dkiEarthNomadic() != 1
            || dkiSpeaksNorthernTribes() != 1
            || dkiSpeaksOwnKind() != 1
        )
            ++bad;
        printf("R721 OA monsters Kala audit: bad %d\n", bad);
        if (bad) return 1;
    }
