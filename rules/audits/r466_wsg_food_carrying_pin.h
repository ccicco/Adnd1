    // ---- R466 WSG food carrying pin audit ----
    // The Table 33 spoilage grid cell by cell (the max days and the pct per
    // food type per temperature band), the ration ladder (the fish half
    // ration, the size S/M/L rations, the twenty-ration butchering) and the
    // spoilage mechanics (the warmest-category rule, the ratchet, the frozen
    // and thaw rules, the taint and spoil CON modifiers and penalties, the
    // ration-value chance) - every cell, const and bool verified against the
    // model.
    {
        using namespace rules;
        int bad = 0;
    if (wccRowCount() != 4
            || wccFishRationNum() != 1
            || wccFishRationDen() != 2
            || wccSizeSRations() != 1
            || wccSizeMFeedCount() != 3
            || wccSizeLRations() != 6
            || wccButcherRations() != 20
            || wccButcherDays() != 1
            || wccOverkillFeedCount() != 3
            || wccTempHourGate() != 1
            || wccThawStartDay() != 1
            || wccTaintConMod() != 4
            || wccTaintOnsetDie() != 10
            || wccTaintOnsetBase() != 10
            || wccTaintAtkPenalty() != 1
            || wccTaintPenaltyHours() != 12
            || wccTaintRecheckMins() != 60
            || wccSpoilConMod() != 10
            || wccSpoilPenaltyHours() != 24
            || wccSpoilRationPct() != 50
            || !wccGluttonyNotModeled()
            || !wccDruidDisapprovesOverkill()
            || !wccOverkillExcusable()
            || !wccExcessCarryAllowed()
            || !wccEncumbranceDMCall()
            || !wccDashNoSpoilage()
            || !wccFrozenKeepsIndefinitely()
            || !wccThawSpoilsEvenIfRefrozen()
            || !wccWarmestCategoryApplies()
            || !wccCategoryRatchet()
            || !wccOneFailTainted()
            || !wccTaintSecretWisdomCheck()
            || !wccMayEatAnyway()
            || !wccTwoFailsSpoiled()
            || !wccTaintFullRationValue()
            || !wccSpoiledHalfRationIfHalfEaten()
            || !wccSpoiledNoNourishment()
        )
            ++bad;
        // the Table 33 food spoilage grid (the max days kept before the first
        // check, then the pct spoilage chance per subsequent day, per food
        // type per effective temperature band)
        int C33[4][10] = {
            {0,0,6,20,4,30,2,40,1,50},
            {0,0,5,30,3,40,2,50,1,60},
            {0,0,3,20,2,50,1,60,1,80},
            {0,0,2,50,1,70,1,80,1,90},
            };
        for (int b = 0;
             b < wccRowCount();
             ++b) {
            int vals[10];
            vals[0] = wccBelowDays(b);
            vals[1] = wccBelowPct(b);
            vals[2] = wcc31Days(b);
            vals[3] = wcc31Pct(b);
            vals[4] = wcc51Days(b);
            vals[5] = wcc51Pct(b);
            vals[6] = wcc71Days(b);
            vals[7] = wcc71Pct(b);
            vals[8] = wccAboveDays(b);
            vals[9] = wccAbovePct(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != C33[b][c])
                    ++bad;
            }
        }
        // the green plants row: dash below 30, then 6/20, 4/30, 2/40, 1/50
    if (wccBelowDays(0) != 0
            || wccBelowPct(0) != 0
            || wcc31Days(0) != 6
            || wcc31Pct(0) != 20
            || wcc51Days(0) != 4
            || wcc51Pct(0) != 30
            || wcc71Days(0) != 2
            || wcc71Pct(0) != 40
            || wccAboveDays(0) != 1
            || wccAbovePct(0) != 50
        )
            ++bad;
        // the fruits or vegetables row: dash below 30, then 5/30, 3/40, 2/50,
        // 1/60
    if (wccBelowDays(1) != 0
            || wccBelowPct(1) != 0
            || wcc31Days(1) != 5
            || wcc31Pct(1) != 30
            || wcc51Days(1) != 3
            || wcc51Pct(1) != 40
            || wcc71Days(1) != 2
            || wcc71Pct(1) != 50
            || wccAboveDays(1) != 1
            || wccAbovePct(1) != 60
        )
            ++bad;
        // the cooked meat row: dash below 30, then 3/20, 2/50, 1/60, 1/80
    if (wccBelowDays(2) != 0
            || wccBelowPct(2) != 0
            || wcc31Days(2) != 3
            || wcc31Pct(2) != 20
            || wcc51Days(2) != 2
            || wcc51Pct(2) != 50
            || wcc71Days(2) != 1
            || wcc71Pct(2) != 60
            || wccAboveDays(2) != 1
            || wccAbovePct(2) != 80
        )
            ++bad;
        // the raw meat row: dash below 30, then 2/50, 1/70, 1/80, 1/90
    if (wccBelowDays(3) != 0
            || wccBelowPct(3) != 0
            || wcc31Days(3) != 2
            || wcc31Pct(3) != 50
            || wcc51Days(3) != 1
            || wcc51Pct(3) != 70
            || wcc71Days(3) != 1
            || wcc71Pct(3) != 80
            || wccAboveDays(3) != 1
            || wccAbovePct(3) != 90
        )
            ++bad;
        // one fish is half a ration (cross-multiplied)
    if (2 * wccFishRationNum() != wccFishRationDen()
        )
            ++bad;
        // the ration ladder: one size S a full ration, one size M feeds
        // three, one size L six rations
    if (wccSizeSRations() != 1
            || wccSizeMFeedCount() != 3
            || wccSizeLRations() != 6
        )
            ++bad;
        // the expert butchering: one full day yields at least twenty full
        // rations
    if (wccButcherRations() != 20
            || wccButcherDays() != 1
        )
            ++bad;
        // the excusable overkill: one size L kill feeding the hunter and two
        // others
    if (wccOverkillFeedCount() != 3
            || wccSizeLRations() != 6
        )
            ++bad;
        // the tainted-food onset: nausea and cramps within 1d10+10 minutes,
        // the 11-20 window
    if (wccTaintOnsetDie() + wccTaintOnsetBase() != 20
            || wccTaintOnsetBase() != 10
        )
            ++bad;
        // the Constitution modifiers: +4 for tainted food, +10 for spoiled
    if (wccTaintConMod() != 4
            || wccSpoilConMod() != 10
        )
            ++bad;
        // the penalty durations: 12 hours tainted, at least 24 hours spoiled
    if (wccTaintPenaltyHours() != 12
            || wccSpoilPenaltyHours() != 24
        )
            ++bad;
        // the tainted-food penalty: -1 on attack rolls and dodging or
        // maneuvering saves, one recovery check per hour
    if (wccTaintAtkPenalty() != 1
            || wccTaintRecheckMins() != 60
        )
            ++bad;
        // the effective-temperature gates: the one-hour rule and the thaw day
        // counted as day 1
    if (wccTempHourGate() != 1
            || wccThawStartDay() != 1
        )
            ++bad;
        // the no-illness spoiled ration: a 50% chance of the full or half
        // ration value
    if (wccSpoilRationPct() != 50
        )
            ++bad;
        // the below-30 column is the dash in every row: zero days and zero
        // pct for all four food types
    if (wccBelowDays(0) != 0
            || wccBelowPct(0) != 0
            || wccBelowDays(1) != 0
            || wccBelowPct(1) != 0
            || wccBelowDays(2) != 0
            || wccBelowPct(2) != 0
            || wccBelowDays(3) != 0
            || wccBelowPct(3) != 0
        )
            ++bad;
        // the max-days ladder never rises as the temperature warms, in every
        // row
    if (wcc31Days(0) < wcc51Days(0)
            || wcc51Days(0) < wcc71Days(0)
            || wcc71Days(0) < wccAboveDays(0)
            || wcc31Days(1) < wcc51Days(1)
            || wcc51Days(1) < wcc71Days(1)
            || wcc71Days(1) < wccAboveDays(1)
            || wcc31Days(2) < wcc51Days(2)
            || wcc51Days(2) < wcc71Days(2)
            || wcc71Days(2) < wccAboveDays(2)
            || wcc31Days(3) < wcc51Days(3)
            || wcc51Days(3) < wcc71Days(3)
            || wcc71Days(3) < wccAboveDays(3)
        )
            ++bad;
        // the spoilage pct climbs strictly as the temperature warms, in every
        // row
    if (wcc31Pct(0) >= wcc51Pct(0)
            || wcc51Pct(0) >= wcc71Pct(0)
            || wcc71Pct(0) >= wccAbovePct(0)
            || wcc31Pct(1) >= wcc51Pct(1)
            || wcc51Pct(1) >= wcc71Pct(1)
            || wcc71Pct(1) >= wccAbovePct(1)
            || wcc31Pct(2) >= wcc51Pct(2)
            || wcc51Pct(2) >= wcc71Pct(2)
            || wcc71Pct(2) >= wccAbovePct(2)
            || wcc31Pct(3) >= wcc51Pct(3)
            || wcc51Pct(3) >= wcc71Pct(3)
            || wcc71Pct(3) >= wccAbovePct(3)
        )
            ++bad;
        // the hardier the food, the longer it keeps: the green plants days
        // never trail the fruits, the fruits never trail the cooked meat, the
        // cooked never trails the raw, in every band
    if (wcc31Days(0) < wcc31Days(1)
            || wcc31Days(1) < wcc31Days(2)
            || wcc31Days(2) < wcc31Days(3)
            || wcc51Days(0) < wcc51Days(1)
            || wcc51Days(1) < wcc51Days(2)
            || wcc51Days(2) < wcc51Days(3)
            || wcc71Days(0) < wcc71Days(1)
            || wcc71Days(1) < wcc71Days(2)
            || wcc71Days(2) < wcc71Days(3)
            || wccAboveDays(0) < wccAboveDays(1)
            || wccAboveDays(1) < wccAboveDays(2)
            || wccAboveDays(2) < wccAboveDays(3)
        )
            ++bad;
        printf("R466 WSG food carrying pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
