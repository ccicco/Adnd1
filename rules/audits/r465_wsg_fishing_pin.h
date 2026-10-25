    // ---- R465 WSG fishing pin audit ----
    // The Table 32 dice grid cell by cell (the die and the modifier per spot
    // quality per time of day), the hunting proficiency kill rules (the
    // one-hit size M kill, the two-hit size L kill, the distance kill of a
    // wounded size M, the single-hit wounded size L, the Proficiency Check
    // before the 1d6 roll) and the fishing mechanics (the net bonus, the zero
    // gate, the proficiency bonus, the group and hour penalties, the
    // fished-out rule) - every cell, const, bool and switch verified against
    // the model.
    {
        using namespace rules;
        int bad = 0;
    if (wfsRowCount() != 3
            || wfsNetBonusPct() != 50
            || wfsProfBonus() != 2
            || wfsGroupPenalty() != 1
            || wfsSpotHourPenalty() != 2
            || wfsFishedOutDays() != 1
            || wfsProfWoundedMDistancePct() != 50
            || wfsProfWoundedLHits() != 1
            || !wfsProfCheckBeforeRoll()
            || !wfsProfNeedsMissile()
            || !wfsProfNoEncounterBoost()
            || !wfsProfRepeatable()
            || !wfsProfWoundedMOneAttempt()
            || !wfsProfWoundedLMultipleAttempts()
            || !wfsZeroNoFish()
            || !wfsProfBonusFairGoodOnly()
            || !wfsFishedOutAllZero()
            || !wfsBoatBetterThanShore()
            || !wfsShadedSpotFairGood()
            || !wfsUnshadedSpotPoor()
            || !wfsSwampBogPoor()
            || !wfsStagnantCreekPoor()
        )
            ++bad;
        // the Table 32 fishing success grid (the die and the modifier per
        // spot quality per time of day)
        int C32[3][6] = {
            {4,-2,4,0,4,2},
            {6,-2,6,-1,6,2},
            {8,-2,6,2,8,2},
            };
        for (int b = 0;
             b < wfsRowCount();
             ++b) {
            int vals[6];
            vals[0] = wfsDayDie(b);
            vals[1] = wfsDayMod(b);
            vals[2] = wfsNightDie(b);
            vals[3] = wfsNightMod(b);
            vals[4] = wfsDawnDie(b);
            vals[5] = wfsDawnMod(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != C32[b][c])
                    ++bad;
            }
        }
        // the poor spot: 1d4-2 by day, 1d4 at night, 1d4+2 at dawn or dusk
    if (wfsDayDie(0) != 4
            || wfsDayMod(0) != -2
            || wfsNightDie(0) != 4
            || wfsNightMod(0) != 0
            || wfsDawnDie(0) != 4
            || wfsDawnMod(0) != 2
        )
            ++bad;
        // the fair spot: 1d6-2 by day, 1d6-1 at night, 1d6+2 at dawn or dusk
        // (the OCR-dropped day cell, pixel-confirmed)
    if (wfsDayDie(1) != 6
            || wfsDayMod(1) != -2
            || wfsNightDie(1) != 6
            || wfsNightMod(1) != -1
            || wfsDawnDie(1) != 6
            || wfsDawnMod(1) != 2
        )
            ++bad;
        // the good spot: 1d8-2 by day, 1d6+2 at night (the book example
        // cell), 1d8+2 at dawn or dusk
    if (wfsDayDie(2) != 8
            || wfsDayMod(2) != -2
            || wfsNightDie(2) != 6
            || wfsNightMod(2) != 2
            || wfsDawnDie(2) != 8
            || wfsDawnMod(2) != 2
        )
            ++bad;
        // the book hour-1 example A: the proficient lone fisherman at a good
        // spot at night rolls 1d6+4
    if (wfsNightMod(2) + wfsProfBonus() != 4
        )
            ++bad;
        // the book hour-1 example B: the first extra group member rolls 1d6+1
    if (wfsNightMod(2) - wfsGroupPenalty() != 1
        )
            ++bad;
        // the book hour-1 example C: the second extra group member rolls 1d6
    if (wfsNightMod(2) - 2 * wfsGroupPenalty() != 0
        )
            ++bad;
        // the book hour-2 example A: 1d6+2 (the night modifier less the hour
        // penalty plus the proficiency bonus)
    if (wfsNightMod(2) - wfsSpotHourPenalty() + wfsProfBonus() != 2
        )
            ++bad;
        // the book hour-2 example B: 1d6-1
    if (wfsNightMod(2) - wfsSpotHourPenalty() - wfsGroupPenalty() != -1
        )
            ++bad;
        // the book hour-3 example B: 1d6-3 (the cumulative hour penalty twice
        // plus the group penalty)
    if (wfsNightMod(2) - 2 * wfsSpotHourPenalty() - wfsGroupPenalty() != -3
        )
            ++bad;
        // the book hour-3 example C: 1d6-4, and in hour 4 all three can reach
        // zero or lower - the fished-out hour
    if (wfsNightMod(2) - 2 * wfsSpotHourPenalty() - 2 * wfsGroupPenalty() !=
        -4
        )
            ++bad;
        // the net: a take of 4 fish rises to 6 (50% more, cross-multiplied)
    if (2 * 100 != 4 * wfsNetBonusPct()
        )
            ++bad;
        // the fished-out spot yields nothing for at least one day
    if (wfsFishedOutDays() != 1
        )
            ++bad;
        // the hunting proficiency kill ladder: one hit for size S and M, two
        // for size L
    if (wfsProfHitsToKill(0) != 1
            || wfsProfHitsToKill(1) != 1
            || wfsProfHitsToKill(2) != 2
        )
            ++bad;
        // the distance kill of a wounded size M creature: a 50% chance, one
        // attempt only
    if (wfsProfWoundedMDistancePct() != 50
        )
            ++bad;
        // the wounded size L creature drops to a single hit for a proficient
        // hunter
    if (wfsProfWoundedLHits() != 1
        )
            ++bad;
        // the dawn-or-dusk modifier is the daytime modifier plus 4 in every
        // row
    if (wfsDawnMod(0) - wfsDayMod(0) != 4
            || wfsDawnMod(1) - wfsDayMod(1) != 4
            || wfsDawnMod(2) - wfsDayMod(2) != 4
        )
            ++bad;
        // the daytime die ladder climbs 4, 6, 8 across the poor, fair and
        // good rows, and so does the dawn-or-dusk die
    if (wfsDayDie(0) != 4
            || wfsDayDie(1) != 6
            || wfsDayDie(2) != 8
            || wfsDawnDie(0) != 4
            || wfsDawnDie(1) != 6
            || wfsDawnDie(2) != 8
        )
            ++bad;
        printf("R465 WSG fishing pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
