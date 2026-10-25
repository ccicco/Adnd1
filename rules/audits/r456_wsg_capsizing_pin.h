    // ---- R456 WSG capsizing pin audit ----
    // The capsizing slice pins Table 26 (the chance of capsizing for the
    // eight vessels under the four wind/water conditions - the kayak
    // 25/40/60/80 down to the large barge 0/0/5/10), the check triggers
    // (entering or leaving the boat, abrupt movement, DM discretion), the
    // under-sail +20% wherever the base chance is greater than zero, the
    // condition bands (mild at 15 mph and 3 inches or less, moderate 16-30
    // and up to 6, dangerous 31-50 and up to 9, severe beyond 50 and from 9),
    // the boating-proficiency assumption, and the mast damage rules (the 40
    // mph threshold, the percentage chance equal to the wind velocity, the
    // 30% furled-sail reduction, the upward adjustment for poor rigging and
    // the hourly check) (rules/wsgcapsizing.h, prefix wcp); census 380 ->
    // 381.
    {
        using namespace rules;
        int bad = 0;
    if (wcpVesselCount() != 8
            || wcpConditionCount() != 4
            || wcpSailModifier() != 20
            || wcpMildWindMax() != 15
            || wcpMildCurrentMax() != 3
            || wcpModWindMin() != 16
            || wcpModWindMax() != 30
            || wcpModCurrentMax() != 6
            || wcpDangerWindMin() != 31
            || wcpDangerWindMax() != 50
            || wcpDangerCurrentMax() != 9
            || wcpSevereWindMin() != 50
            || wcpSevereCurrentMin() != 9
            || wcpMastDamageWindMin() != 40
            || wcpFurledReduction() != 30
            || wcpMastCheckPeriodHours() != 1
            || !wcpCapsizeMeansTurnOver()
            || !wcpCheckOnEnterLeave()
            || !wcpCheckOnAbruptMove()
            || !wcpCheckOnDmCall()
            || !wcpTableAssumesNoSail()
            || !wcpUnderSailIncreased()
            || !wcpProficiencyAssumed()
            || !wcpMastDamageByWind()
            || !wcpDamageChanceEqualsVelocity()
            || !wcpFurledSailReduced()
            || !wcpPoorRiggingIncreased()
            || !wcpMastCheckHourly()
        )
            ++bad;
        // the Table 26 grid: the chance of capsizing for the eight vessels
        // (kayak, small canoe, small rowboat, coracle, large canoe, large
        // rowboat, small barge, large barge) under the four wind/water
        // conditions (mild, moderate, dangerous, severe)
        int C26[8][4] = {
            {25,40,60,80},
            {20,35,50,75},
            {5,15,30,50},
            {10,20,30,50},
            {10,20,30,40},
            {0,10,25,40},
            {0,5,10,20},
            {0,0,5,10},
            };
        for (int b = 0;
             b < wcpVesselCount();
             ++b) {
            int vals[4];
            vals[0] = wcpMildPct(b);
            vals[1] = wcpModeratePct(b);
            vals[2] = wcpDangerPct(b);
            vals[3] = wcpSeverePct(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C26[b][c])
                    ++bad;
            }
        }
        // the wind bands: mild to 15, moderate 16 to 30, dangerous 31 to 50,
        // severe beyond 50 miles per hour
    if (wcpMildWindMax() != 15
            || wcpModWindMin() != 16
            || wcpModWindMax() != 30
            || wcpDangerWindMin() != 31
            || wcpDangerWindMax() != 50
            || wcpSevereWindMin() != 50
        )
            ++bad;
        // the current bands: mild to 3 inches, moderate to 6, dangerous to 9,
        // severe from 9 - the moderate is twice and the dangerous three times
        // the mild maximum
    if (wcpMildCurrentMax() != 3
            || wcpModCurrentMax() != 6
            || wcpDangerCurrentMax() != 9
            || wcpSevereCurrentMin() != 9
            || wcpModCurrentMax() != 2 * wcpMildCurrentMax()
            || wcpDangerCurrentMax() != 3 * wcpMildCurrentMax()
        )
            ++bad;
        // the modifiers: the +20 under sail, the 40 mph mast damage
        // threshold, the 30% furled reduction, the hourly check
    if (wcpSailModifier() != 20
            || wcpMastDamageWindMin() != 40
            || wcpFurledReduction() != 30
            || wcpMastCheckPeriodHours() != 1
        )
            ++bad;
        // the band seams: severe starts where dangerous tops out, in both
        // wind and current
    if (wcpDangerWindMax() != 50
            || wcpSevereWindMin() != wcpDangerWindMax()
            || wcpDangerCurrentMax() != wcpSevereCurrentMin()
        )
            ++bad;
        // the kayak ladder: 25, 40, 60, 80 across the four conditions
    if (wcpMildPct(0) != 25
            || wcpModeratePct(0) != 40
            || wcpDangerPct(0) != 60
            || wcpSeverePct(0) != 80
        )
            ++bad;
        // the large barge ladder: 0, 0, 5, 10 - the sturdiest vessel never
        // capsizes below dangerous conditions
    if (wcpMildPct(7) != 0
            || wcpModeratePct(7) != 0
            || wcpDangerPct(7) != 5
            || wcpSeverePct(7) != 10
        )
            ++bad;
        // the severe column spot checks: kayak 80, small canoe 75, small
        // rowboat 50, small barge 20
    if (wcpSeverePct(0) != 80
            || wcpSeverePct(1) != 75
            || wcpSeverePct(2) != 50
            || wcpSeverePct(6) != 20
        )
            ++bad;
        // the capsize chances climb with the conditions - the kayak strictly
        // steps up 25/40/60/80, and the large barge never steps down through
        // its 0/0/5/10
    if (wcpModeratePct(0) <= wcpMildPct(0)
            || wcpDangerPct(0) <= wcpModeratePct(0)
            || wcpSeverePct(0) <= wcpDangerPct(0)
            || wcpModeratePct(7) < wcpMildPct(7)
            || wcpDangerPct(7) < wcpModeratePct(7)
            || wcpSeverePct(7) < wcpDangerPct(7)
        )
            ++bad;
        // the severe poles: the kayak severe is eight times the large barge
        // severe
    if (wcpSeverePct(0) != 80
            || wcpSeverePct(7) != 10
            || wcpSeverePct(7) * 8 != wcpSeverePct(0)
        )
            ++bad;
        // the mild zero row: the large rowboat and both barges never capsize
        // in mild conditions (the under-sail +20 never applies to a zero
        // base)
    if (wcpMildPct(5) != 0
            || wcpMildPct(6) != 0
            || wcpMildPct(7) != 0
        )
            ++bad;
        printf("R456 WSG capsizing pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
