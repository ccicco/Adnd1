    // ---- R539 DSG Deepearth areas 12-13 audit ----
    // The DSG Deepearth areas 12-13 pin Area 12 (the Combat Zone with its
    // jermalaine-pech war, the sabotaged hollow bridges and the 16 walled
    // treasure troves) and Area 13 (the Empty Caverns with their bat
    // thousands and the abandoned dry lairs).
    {
        using namespace rules;
        int bad = 0;
    if (dnahZoneWideMiles() != 3
            || dnahZoneLongMiles() != 4
            || dnahBlockCount() != 12
            || dnahWalkMaxFt() != 100
            || dnahBarrierLowFt() != 10
            || dnahBarrierHighFt() != 20
            || dnahBarrierMaxFt() != 100
            || dnahPassHtFt() != 3
            || dnahPassWidFt() != 5
            || dnahPechMaxCount() != 100
            || dnahOddsRatio() != 10
            || dnahSabotagePct() != 20
            || dnahCollapseWeightLb() != 50
            || dnahCollapseWeightGp() != 500
            || dnahTroveCount() != 16
            || dnahTroveGemsDice() != 2
            || dnahTroveGemsSides() != 6
            || dnahTroveGemsMultGp() != 1000
            || dnahTroveSealFt() != 16
            || dnahPassDiaMaxIn() != 18
            || !dnahQuakeLandscape()
            || !dnahDecimatedJermalaine()
            || !dnahPechWagons()
            || !dnahZoneFauna()
            || !dnahColumnWaterfalls()
            || !dnahQuakeOres()
            || !dnahHollowBridges()
            || !dnahNarrowAttachments()
            || !dnahDeadDustyCaves()
            || !dnahBatRoost()
            || !dnahDryVentilation()
            || !dnahAbandonedLairs()
        )
            ++bad;
        // the Combat Zone dimensions: over three miles wide, four miles long,
        // a dozen supporting blocks, no 100-foot same-elevation walks.
    if (dnahZoneWideMiles() != 3
            || dnahZoneLongMiles() != 4
            || dnahBlockCount() != 12
            || dnahWalkMaxFt() != 100
        )
            ++bad;
        // the zone's obstacles and connections: the 10/20-ft drops, the
        // 100-ft barriers, the 3x5-ft smallest passages.
    if (dnahBarrierLowFt() != 10
            || dnahBarrierHighFt() != 20
            || dnahBarrierMaxFt() != 100
            || dnahPassHtFt() != 3
            || dnahPassWidFt() != 5
        )
            ++bad;
        // the war's odds: the pech under 100 strong, outnumbered at least 10
        // to 1.
    if (dnahPechMaxCount() != 100
            || dnahOddsRatio() != 10
        )
            ++bad;
        // the sabotaged bridges: 20% of them, collapsing under more than 50
        // pounds (500 gp).
    if (dnahSabotagePct() != 20
            || dnahCollapseWeightLb() != 50
            || dnahCollapseWeightGp() != 500
        )
            ++bad;
        // the treasure troves: 16 of them, gems worth 2d6 x 1,000 gp, seals
        // 16 feet thick.
    if (dnahTroveCount() != 16
            || dnahTroveGemsDice() != 2
            || dnahTroveGemsSides() != 6
            || dnahTroveGemsMultGp() != 1000
            || dnahTroveSealFt() != 16
        )
            ++bad;
        // the empty caverns' pinch: passages under 18 inches in diameter.
    if (dnahPassDiaMaxIn() != 18
        )
            ++bad;
        printf("R539 DSG Deepearth areas 12-13 audit: bad %d\n", bad);
        if (bad) return 1;
    }
