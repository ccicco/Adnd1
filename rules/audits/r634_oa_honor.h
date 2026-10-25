    // ---- R634 OA honor audit ----
    // OA round twenty-one (capture pp. 69-70): the honor opener prose, the
    // starting honor doctrine and the Table 41 grid
    {
        using namespace rules;
        int bad = 0;
    if (dguT41RowCount() != 7
            || dguHonorMax() != 100
            || !dguHonorReflectsFamily()
            || !dguHonorBringsRespect()
            || !dguHonorEasierToLose()
            || !dguDishonorDeeds()
            || !dguHonorDeeds()
            || !dguHonorImprovesReactions()
            || !dguHonorNotAlignment()
            || !dguHonorDeedsBoth()
            || !dguHonorPointsTracked()
            || !dguNotEveryAdventure()
            || !dguClanStartByBirthRank()
            || !dguFamilyHonorFloorZero()
            || !dguClanStartAddsBirthrights()
            || !dguNoClanT41Base()
            || !dguClassSensitivity()
            || !dguDmAwardsHonor()
            || !dguDmJudgment()
        )
            ++bad;
        // the Table 41 grid: the class base-honor bounds (capture p. 70)
        int CT41[7][2] = {
            {20,20},
            {15,15},
            {25,25},
            {10,10},
            {10,10},
            {15,15},
            {21,40},
            };
        int nT41[2] = {0,0};
        int eT41[2] = {0,0};
        for (int b = 0;
             b < dguT41RowCount();
             ++b) {
            int vals[2];
            vals[0] = dguT41BaseLo(b);
            vals[1] = dguT41BaseHi(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT41[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT41[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nT41[c] != eT41[c])
                ++bad;
        // the dguT41RowCount pin
    if (dguT41RowCount() != 7
        )
            ++bad;
        // the dguHonorMax pin
    if (dguHonorMax() != 100
        )
            ++bad;
        // the dguHonorReflectsFamily pin
    if (dguHonorReflectsFamily() != 1
        )
            ++bad;
        // the dguHonorBringsRespect pin
    if (dguHonorBringsRespect() != 1
        )
            ++bad;
        // the dguHonorEasierToLose pin
    if (dguHonorEasierToLose() != 1
        )
            ++bad;
        // the dguDishonorDeeds pin
    if (dguDishonorDeeds() != 1
        )
            ++bad;
        // the dguHonorDeeds pin
    if (dguHonorDeeds() != 1
        )
            ++bad;
        // the dguHonorImprovesReactions pin
    if (dguHonorImprovesReactions() != 1
        )
            ++bad;
        // the dguHonorNotAlignment pin
    if (dguHonorNotAlignment() != 1
        )
            ++bad;
        // the dguHonorDeedsBoth pin
    if (dguHonorDeedsBoth() != 1
        )
            ++bad;
        // the dguHonorPointsTracked pin
    if (dguHonorPointsTracked() != 1
        )
            ++bad;
        // the dguNotEveryAdventure pin
    if (dguNotEveryAdventure() != 1
        )
            ++bad;
        // the dguClanStartByBirthRank pin
    if (dguClanStartByBirthRank() != 1
        )
            ++bad;
        // the dguFamilyHonorFloorZero pin
    if (dguFamilyHonorFloorZero() != 1
        )
            ++bad;
        // the dguClanStartAddsBirthrights pin
    if (dguClanStartAddsBirthrights() != 1
        )
            ++bad;
        // the dguNoClanT41Base pin
    if (dguNoClanT41Base() != 1
        )
            ++bad;
        // the dguClassSensitivity pin
    if (dguClassSensitivity() != 1
        )
            ++bad;
        // the dguDmAwardsHonor pin
    if (dguDmAwardsHonor() != 1
        )
            ++bad;
        // the dguDmJudgment pin
    if (dguDmJudgment() != 1
        )
            ++bad;
        // the T41 shukenja and kensai rows - the 20 and 25 bases (capture p.
        // 70)
    if (dguT41BaseLo(0) != 20
            || dguT41BaseHi(0) != 20
            || dguT41BaseLo(2) != 25
            || dguT41BaseHi(2) != 25
        )
            ++bad;
        // the T41 sohei and wu jen rows - the 15 bases (capture p. 70)
    if (dguT41BaseLo(1) != 15
            || dguT41BaseHi(1) != 15
            || dguT41BaseLo(5) != 15
            || dguT41BaseHi(5) != 15
        )
            ++bad;
        // the T41 bushi and hengeyokai rows - the 10 bases (capture p. 70)
    if (dguT41BaseLo(3) != 10
            || dguT41BaseHi(3) != 10
            || dguT41BaseLo(4) != 10
            || dguT41BaseHi(4) != 10
        )
            ++bad;
        // the T41 yakuza row - the 1d20 + 20 read pinned as 21 through 40
        // (capture p. 70)
    if (dguT41BaseLo(6) != 21
            || dguT41BaseHi(6) != 40
        )
            ++bad;
        // the T41 row count - seven rows only (capture p. 70)
    if (dguT41RowCount() != 7
        )
            ++bad;
        // the honor cap - no character above 100 points (capture p. 70)
    if (dguHonorMax() != 100
        )
            ++bad;
        // the starting honor doctrine - the birth-rank base with the T39
        // adjustments, the 0 floor, the birthright and lowest-ability adds,
        // the no-clan route (capture p. 70)
    if (dguClanStartByBirthRank() != 1
            || dguFamilyHonorFloorZero() != 1
            || dguClanStartAddsBirthrights() != 1
            || dguNoClanT41Base() != 1
        )
            ++bad;
        printf("R634 OA honor audit: bad %d\n", bad);
        if (bad) return 1;
    }
