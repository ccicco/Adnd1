    // ---- R533 DSG Deepearth opener audit ----
    // The DSG lands of Deepearth opener pins the setting frame (the
    // example-to-adapt rule, the hollow-below note), the water-passage
    // generation (the 1d6-x-10 widths, the drift bands, the temperature
    // bands), the tunnel generation (the 10% carved chance, the 33%
    // obstacles, the 3d20 cavern widths with the 1d20-x-100 constancy), and
    // the area-details example with the DMG page 169 referral.
    {
        using namespace rules;
        int bad = 0;
    if (dndlWaterWidthDice() != 1
            || dndlWaterWidthSides() != 6
            || dndlWaterWidthMultFt() != 10
            || dndlWaterWidthMinFt() != 10
            || dndlWaterWidthMaxFt() != 60
            || dndlWidthSameLow() != 2
            || dndlWidthSameHigh() != 5
            || dndlWidthShrinkFt() != 10
            || dndlWidthFloorFt() != 5
            || dndlWidthGrowFt() != 10
            || dndlWaterColdHigh() != 5
            || dndlWaterHeatRoll() != 6
            || dndlWaterWarmLow() != 1
            || dndlWaterBoilRoll() != 6
            || dndlCarvedChancePct() != 10
            || dndlCarvedDiaFt() != 10
            || dndlObstaclePct() != 33
            || dndlCliffDice() != 10
            || dndlCliffSides() != 10
            || dndlChasmDepthDice() != 20
            || dndlChasmDepthSides() != 10
            || dndlChasmWidthDice() != 4
            || dndlChasmWidthSides() != 10
            || dndlCavernDice() != 3
            || dndlCavernSides() != 20
            || dndlCavernMinFt() != 3
            || dndlCavernMaxFt() != 60
            || dndlConstDice() != 1
            || dndlConstSides() != 20
            || dndlConstMultFt() != 100
            || dndlConstMinFt() != 100
            || dndlConstMaxFt() != 2000
            || dndlChangeChancePct() != 33
            || dndlSquareFt() != 300
            || dndlSquaresPerSide() != 30
            || dndlDmgPage() != 169
            || !dndlSettingForCampaign()
            || !dndlExampleToAdapt()
            || !dndlAreaKeyRoughDetail()
            || !dndlThreeDimReferral()
            || !dndlHollowBelowNote()
            || !dndlPassagesHumanSized()
            || !dndlRiversFlowMap()
            || !dndlWaterfallsIndicated()
            || !dndlWidthMileConst()
            || !dndlWaterBoilOnlyDanger()
            || !dndlTunnelsHumanPass()
            || !dndlObstacleExamples()
            || !dndlUnintelligentDwellers()
            || !dndlFrameworkNotFullDetail()
            || !dndlSquareMeansGraph()
            || !dndlDmgRandomDungeon()
        )
            ++bad;
        // the waterway width generation: 1d6 x 10 for the 10-to-60-foot
        // spread.
    if (dndlWaterWidthDice() != 1
            || dndlWaterWidthSides() != 6
            || dndlWaterWidthMultFt() != 10
            || dndlWaterWidthMinFt() != 10
            || dndlWaterWidthMaxFt() != 60
        )
            ++bad;
        // the width-drift bands: 2-5 the same, 1 shrinks 10 feet (5 at the
        // floor), 6 grows 10 feet even beyond 60.
    if (dndlWidthSameLow() != 2
            || dndlWidthSameHigh() != 5
            || dndlWidthShrinkFt() != 10
            || dndlWidthFloorFt() != 5
            || dndlWidthGrowFt() != 10
        )
            ++bad;
        // the temperature bands: 1-5 very cold, the 6 heat check, the 1
        // cool-slightly-warmer, the 6 boiling.
    if (dndlWaterColdHigh() != 5
            || dndlWaterHeatRoll() != 6
            || dndlWaterWarmLow() != 1
            || dndlWaterBoilRoll() != 6
        )
            ++bad;
        // the tunnel carving: the 10% carved chance, the uniform 10-foot
        // diameter, the 33% per-mile obstacle chance.
    if (dndlCarvedChancePct() != 10
            || dndlCarvedDiaFt() != 10
            || dndlObstaclePct() != 33
        )
            ++bad;
        // the obstacle dice: the 10d10 cliff, the 20d10 chasm depth, the 4d10
        // chasm width.
    if (dndlCliffDice() != 10
            || dndlCliffSides() != 10
            || dndlChasmDepthDice() != 20
            || dndlChasmDepthSides() != 10
            || dndlChasmWidthDice() != 4
            || dndlChasmWidthSides() != 10
        )
            ++bad;
        // the cavern widths: the 3d20 (the djvu 3420 settled by Capture), the
        // 3-60-foot range, the 1d20 x 100 constancy runs of 100-2,000 feet,
        // the 1/3 change chance.
    if (dndlCavernDice() != 3
            || dndlCavernSides() != 20
            || dndlCavernMinFt() != 3
            || dndlCavernMaxFt() != 60
            || dndlConstDice() != 1
            || dndlConstSides() != 20
            || dndlConstMultFt() != 100
            || dndlConstMinFt() != 100
            || dndlConstMaxFt() != 2000
            || dndlChangeChancePct() != 33
        )
            ++bad;
        // the area-details example and referral: the 300-foot square as
        // 30-by-30 graph squares, the DMG page 169.
    if (dndlSquareFt() != 300
            || dndlSquaresPerSide() != 30
            || dndlDmgPage() != 169
        )
            ++bad;
        // the frame prose: the setting use, the example-to-adapt rule, the
        // hollow-below note, the unintelligent dwellers.
    if (dndlSettingForCampaign() != 1
            || dndlExampleToAdapt() != 1
            || dndlHollowBelowNote() != 1
            || dndlUnintelligentDwellers() != 1
        )
            ++bad;
        printf("R533 DSG Deepearth opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
