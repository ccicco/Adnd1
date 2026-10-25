    // ---- R311: the underwater environment audit ----
    // The DMG UNDERWATER ADVENTURES section
    // (rules/underwater.h) walked cell for cell
    // against this local ground truth: the
    // surface swim constants with the drown walk,
    // the movement pins with the cap walk, the
    // vision bases with the fresh and salt decay
    // walks, the light spell and ultravision
    // tables, the seaweed, grass and mud pins,
    // and the combat constants with the print
    // identities.
    {
        int bad = 0;
        static const int kVisionBase[2] = {
              50,  100,
        };
        static const int kFreshDecay[6] = {
              50,   40,   30,   20,   10,    0,
        };
        static const int kSaltDecay[11] = {
             100,   90,   80,   70,   60,   50,
              40,   30,   20,   10,    0,
        };
        static const int kLightDist[11] = {
               0,   10,   20,   25,   30,   50,
              55,   59,   60,   70,  100,
        };
        static const int kLightVis[11] = {
              30,   30,   30,   35,   40,   60,
              65,   69,   60,   70,  100,
        };
        static const int kUltraDepth[8] = {
               0,   50,   99,  100,  150,  200,  201,  300,
        };
        static const int kUltraRate[8] = {
               2,    2,    2,    1,    1,    1,    0,    0,
        };
        static const int kCapGp[8] = {
               0,  100,  250,  999,  -50, -100, -250, -999,
        };
        static const int kCapLbs[8] = {
              20,   21,   22,   29,   20,   19,   18,   11,
        };
        static const int kDrownLbs[8] = {
               0,    4,    5,   14,   15,   25,   50,   -5,
        };
        static const int kDrownPct[8] = {
               5,    5,    7,    9,   11,   15,   25,    5,
        };
        // the surface swim constants
        if (rules::uwSurfaceMetalArmorImpossible() != 1 ||
            rules::uwSurfaceMagicArmorExcepted() != 1 ||
            rules::uwSurfaceMagicArmorDogPaddleOnly()
                != 1 ||
            rules::uwSurfaceLeatherPaddedPossible()
                != 1 ||
            rules::uwSurfaceLeatherDrownPctPerHour()
                != 5 ||
            rules::uwSurfaceDrownStepLbs() != 5 ||
            rules::uwSurfaceDrownStepPct() != 2 ||
            rules::uwSurfaceHighWindMph() != 35 ||
            rules::uwSurfaceHighWindDrownPct() != 75)
            ++bad;
        // the drown walk: 5 percent plus 2 per
        // full 5 pounds, the negatives clamped
        for (int i = 0; i < 8; ++i)
            if (rules::uwSurfaceDrownPct(kDrownLbs[i]) !=
                kDrownPct[i]) ++bad;
        // the step identity: the first step lands
        // 5 + 2
        if (rules::uwSurfaceDrownPct(
                rules::uwSurfaceDrownStepLbs()) !=
            rules::uwSurfaceLeatherDrownPctPerHour() +
                rules::uwSurfaceDrownStepPct()) ++bad;
        // the movement pins
        if (rules::uwSwimArmorHeavierThanLeatherBlocked()
                != 1 ||
            rules::uwSwimMagicArmorExcepted() != 1 ||
            rules::uwSwimEquipmentCapLbs() != 20 ||
            rules::uwSwimCapAdjLbsPer100gp() != 1 ||
            rules::uwMoveSameAsDungeon() != 1 ||
            rules::uwFreeActionRateMultiple() != 3 ||
            rules::uwSwimVerticalSameRate() != 1) ++bad;
        // the cap walk: 20 pounds plus one per
        // full 100 g.p. of strength adjustment
        // (C truncation, both signs)
        for (int i = 0; i < 8; ++i)
            if (rules::uwSwimEncumbranceCapLbs(kCapGp[i])
                != kCapLbs[i]) ++bad;
        // the cap identity at zero adjustment
        if (rules::uwSwimEncumbranceCapLbs(0) !=
            rules::uwSwimEquipmentCapLbs()) ++bad;
        // the vision bases (0 fresh, 1 salt)
        for (int i = 0; i < 2; ++i)
            if (rules::uwVisionBaseFt(i) !=
                kVisionBase[i]) ++bad;
        if (rules::uwVisionDepthLimitSameAsDistance()
                != 1 ||
            rules::uwVisionDecaySegmentFt() != 10) ++bad;
        // the fresh decay walk (depth 10 to 60)
        for (int i = 0; i < 6; ++i)
            if (rules::uwVisionDecayFt(0, 10 * (i + 1))
                != kFreshDecay[i]) ++bad;
        // the salt decay walk (depth 10 to 110)
        for (int i = 0; i < 11; ++i)
            if (rules::uwVisionDecayFt(1, 10 * (i + 1))
                != kSaltDecay[i]) ++bad;
        // the decay clamps: the shallow depth
        // reads the base; the deep reads zero
        if (rules::uwVisionDecayFt(0, 0) != 50 ||
            rules::uwVisionDecayFt(0, 5) != 50 ||
            rules::uwVisionDecayFt(1, 0) != 100 ||
            rules::uwVisionDecayFt(0, 55) != 10 ||
            rules::uwVisionDecayFt(1, 105) != 10 ||
            rules::uwVisionDecayFt(0, 60) != 0 ||
            rules::uwVisionDecayFt(1, 110) != 0 ||
            rules::uwVisionDecayFt(0, 500) != 0 ||
            rules::uwVisionDecayFt(1, 500) != 0) ++bad;
        // the light spell constants
        if (rules::uwLightSpellMinFt() != 30 ||
            rules::uwLightSpellBonusFt() != 10 ||
            rules::uwLightSpellBonusThresholdFt() != 60)
            ++bad;
        // the light spell walk
        for (int i = 0; i < 11; ++i)
            if (rules::uwLightSpellVisionFt(
                    kLightDist[i]) != kLightVis[i]) ++bad;
        // the light spell identities: the floor
        // and the threshold edge
        if (rules::uwLightSpellVisionFt(0) !=
            rules::uwLightSpellMinFt() ||
            rules::uwLightSpellVisionFt(59) != 69 ||
            rules::uwLightSpellVisionFt(60) != 60 ||
            rules::uwLightSpellVisionFt(-10) != 30) ++bad;
        // the helm quintuples both waters, and
        // the infravision pin
        if (rules::uwHelmVisionMultiple() != 5 ||
            rules::uwVisionBaseFt(0) *
                rules::uwHelmVisionMultiple() != 250 ||
            rules::uwVisionBaseFt(1) *
                rules::uwHelmVisionMultiple() != 500 ||
            rules::uwInfravisionSameAsDungeon() != 1)
            ++bad;
        // the ultravision pins and walk
        if (rules::uwUltravisionHalvedAtDepthFt() != 100
            ||
            rules::uwUltravisionZeroBelowDepthFt()
                != 200) ++bad;
        for (int i = 0; i < 8; ++i)
            if (rules::uwUltravisionRate(kUltraDepth[i])
                != kUltraRate[i]) ++bad;
        // the seaweed, grass and shoal pins
        if (rules::uwSeaweedVisionFt() != 10 ||
            rules::uwSeaweedVisionMayBeNil() != 1 ||
            rules::uwSeaGrassHeightLoFt() != 3 ||
            rules::uwSeaGrassHeightHiFt() != 30 ||
            rules::uwSeaGrassHeightHiFt() -
                rules::uwSeaGrassHeightLoFt() != 27 ||
            rules::uwShoalTotallyObstructs() != 1) ++bad;
        // the mud identity: the 7-12 band
        if (rules::uwMudCloudRoundsPlus() + 1 != 7 ||
            rules::uwMudCloudRoundsDie() +
                rules::uwMudCloudRoundsPlus() != 12) ++bad;
        // the combat constants
        if (rules::uwCombatThrustingOnly() != 1 ||
            rules::uwAquaticFirstStrike() != 1 ||
            rules::uwFreeActionAnyWeapon() != 1 ||
            rules::uwFreeActionNoReactionPenalty() != 1
            ||
            rules::uwMissileExceptCrossbowImpossible()
                != 1) ++bad;
        // the net throw bands and the special
        // crossbow economics
        if (rules::uwNetThrowFtPerStrPoint() != 1 ||
            rules::uwNetThrowUnderwaterRaceFt() != 15 ||
            rules::uwNetThrowSahuaginFt() != 20 ||
            rules::uwNetUntrainedPenalty() != 4 ||
            rules::uwSpecialCrossbowPriceMultiple()
                != 10 ||
            rules::uwSpecialCrossbowRangeDivisor()
                != 2) ++bad;
        printf("R311 underwater environment audit: bad %d\n", bad);
        if (bad) return 1;
    }
