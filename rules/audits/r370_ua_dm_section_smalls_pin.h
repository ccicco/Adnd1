    // ---- R370: the UA DM-section
    // smalls pin audit ----
    // The UA DM-section smalls, part 1:
    // Method V (p. 74) - the class-first
    // humans-only generation, the
    // best-three-of-N roll with the DM
    // approval, the minimum and maximum
    // clamps, the 9d6 fighter strength
    // example (the dice table cells lost,
    // flagged); the starting hit-point
    // minimums (p. 74) - the 12 class
    // floors, the multi-class average
    // rounded up, the constitution
    // adjustment; the warhorses and
    // barding (p. 76) - the movement rate
    // table (the medium scale and heavy
    // leather cells lost, flagged), the
    // endurance rule, the magical barding
    // costs and percentages, the flying
    // and aquatic steeds rules. The R368
    // seam cross-checks the cavalier d10
    // floor. Three items flip CLOSED; the
    // census 296 -> 297.
    {
        using namespace rules;
        int bad = 0;
        // ---- Method V ----
            if (!uasm1MethodVHumansOnly()) ++bad;
            if (!uasm1MethodVClassFirst()) ++bad;
            if (!uasm1MethodVRequiresDmApproval())
                ++bad;
            if (!uasm1MethodVBestThreeOfN()) ++bad;
            if (!uasm1MethodVMinClampApplies())
                ++bad;
            if (!uasm1MethodVMaxClampApplies())
                ++bad;
            if (uasm1MethodVFighterStrengthDice()
                    != 9) ++bad;
            if (uasm1MethodVTableCellsLost())
                ++bad;
        // ---- the starting hit points ----
            if (uasm1StartHpClassCount() != 12)
                ++bad;
            static const int hp[12] = {6, 6,
                5, 5, 6, 7, 9, 3, 3, 4, 4, 5};
            for (int i = 0; i < 12; ++i) {
                if (uasm1StartHpMin(i) != hp[i])
                    ++bad;
            }
            if (!uasm1StartHpMultiClassAverageRoundedUp())
                ++bad;
            if (uasm1StartHpExampleFighterMage()
                    != 5) ++bad;
            if (!uasm1StartHpConAdjustApplies())
                ++bad;
            if (uasm1StartHpExampleCon17Fighter()
                    != 9) ++bad;
            // the multi-class read: the
            // average of the minimums,
            // rounded up
            if ((6 + 3 + 1) / 2
                    != uasm1StartHpExampleFighterMage())
                ++bad;
            // the con-17 example: the
            // fighter floor plus the +3
            if (uasm1StartHpMin(4) + 3
                    != uasm1StartHpExampleCon17Fighter())
                ++bad;
        // ---- the barding table ----
            if (uasm1BardLightLeather() != 21)
                ++bad;
            if (!uasm1BardLightChainNa())
                ++bad;
            if (uasm1BardLightScale() != 15)
                ++bad;
            if (uasm1BardLightScaleNa()) ++bad;
            if (!uasm1BardLightPlateNa()) ++bad;
            if (uasm1BardMediumLeather() != 17)
                ++bad;
            if (uasm1BardMediumChain() != 12)
                ++bad;
            if (uasm1BardMediumScaleCellLost())
                ++bad;
            if (uasm1BardMediumScale() != 15)
                ++bad;
            if (!uasm1BardMediumPlateNa()) ++bad;
            if (uasm1BardHeavyLeatherCellLost())
                ++bad;
            if (uasm1BardHeavyLeather() != 15)
                ++bad;
            if (uasm1BardHeavyChain() != 13)
                ++bad;
            if (uasm1BardHeavyScale() != 14)
                ++bad;
            if (uasm1BardHeavyPlate() != 12)
                ++bad;
            // the movement monotonicity:
            // heavier barding, slower
            if (uasm1BardHeavyLeather()
                    <= uasm1BardHeavyScale()) ++bad;
            if (uasm1BardHeavyChain()
                    <= uasm1BardHeavyPlate()) ++bad;
            if (uasm1BardLightLeather()
                    <= uasm1BardMediumLeather())
                ++bad;
            if (!uasm1BardEnduranceFromBaseRate())
                ++bad;
        // ---- the magical barding ----
            if (uasm1MagBardingCostMultiple()
                    != 5) ++bad;
            if (uasm1MagBardingPlusCap() != 3)
                ++bad;
            if (uasm1MagBardingPlus1Pct()
                    + uasm1MagBardingPlus2Pct()
                    + uasm1MagBardingPlus3Pct()
                    != 100) ++bad;
            if (uasm1MagBardingLeatherPct()
                    + uasm1MagBardingScalePct()
                    + uasm1MagBardingChainPct()
                    + uasm1MagBardingPlatePct()
                    != 100) ++bad;
            if (uasm1MagBardingPlus1Pct()
                    != 65) ++bad;
            if (uasm1MagBardingPlus2Pct()
                    != 25) ++bad;
            if (uasm1MagBardingPlus3Pct()
                    != 10) ++bad;
            if (uasm1MagBardingLeatherPct()
                    != 10) ++bad;
            if (uasm1MagBardingScalePct()
                    != 15) ++bad;
            if (uasm1MagBardingChainPct()
                    != 25) ++bad;
            if (uasm1MagBardingPlatePct()
                    != 50) ++bad;
        // ---- the other steeds ----
            if (!uasm1FlyingSteedsLeatherOrElfinOnly())
                ++bad;
            if (!uasm1FlyingSteedsReductionEighth())
                ++bad;
            if (!uasm1AquaticSteedsNotBarded())
                ++bad;
            if (uasm1StrongMountPlateReductionMin()
                    != 5) ++bad;
            if (uasm1StrongMountPlateReductionMax()
                    != 8) ++bad;
            if (!uasm1UnicornGriffonElfinWeightAsLeather())
                ++bad;
        // ---- the R368 seam ----
            // the cavalier starting floor
            // (6) cannot exceed the d10
            // level-1 hit die the R368 pin
            // carries
            if (uasm1StartHpMin(0)
                    > uacavtDirectFirstSides())
                ++bad;
        printf("R370 UA DM-section smalls pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
