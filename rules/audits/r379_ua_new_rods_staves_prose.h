    // ---- R379: the UA new rods
    // staves prose pin audit ----
    // The four clean
    // descriptions (pp. 94-96):
    // the rod of alertness, the
    // rod of security, the
    // staff-mace, the staff of
    // slinging. The seven
    // garbled descriptions
    // filled by the R397 clean
    // read. The R378 seam
    // cross-checks the rings
    // ledger, the R375 seam the
    // rod band; the census
    // 305 -> 306.
    {
        using namespace rules;
        int bad = 0;
        // ---- the rod of alertness ----
            if (!uaroAlLooksFootmanMacePlusOne())
                ++bad;
            if (uaroAlSurpriseBonus() != 1) ++bad;
            if (uaroAlInitiativeBonus() != 1) ++bad;
            if (uaroAlDetectCount() != 7) ++bad;
            if (!uaroAlDetectsExpendNoCharge())
                ++bad;
            if (uaroAlSenseRadiusIn() != 12) ++bad;
            if (!uaroAlSenseNeedsHarmfulIntent())
                ++bad;
            if (uaroAlFlangeCount() != 8) ++bad;
            if (uaroAlFlangeLightRangeIn() != 6)
                ++bad;
            if (uaroAlPrayerRadiusIn() != 2) ++bad;
            if (!uaroAlMentalAlertSent()) ++bad;
            if (uaroAlAnimateMaxObjects() != 16)
                ++bad;
            if (uaroAlAnimateCircleRadiusIn() != 6)
                ++bad;
            if (uaroAlFunctionChargeCost() != 1)
                ++bad;
            if (uaroAlAnimateChargeCost() != 1)
                ++bad;
            if (uaroAlAllAtOnceCharges() != 2)
                ++bad;
            // functions + animation =
            // the all-at-once cost
            if (uaroAlFunctionChargeCost()
                    + uaroAlAnimateChargeCost()
                    != uaroAlAllAtOnceCharges())
                ++bad;
            if (uaroAlRechargeClericLevel() != 16)
                ++bad;
            if (!uaroAlRechargeNeedsChargeLeft())
                ++bad;
        // ---- the rod of security ----
            if (uaroSeDaysBase() != 200) ++bad;
            if (uaroSeMaxCreatures() != 200) ++bad;
            if (uaroSeOtherCreaturesMax() != 199)
                ++bad;
            // the possessor plus the
            // 199 others fill the cap
            if (uaroSeOtherCreaturesMax() + 1
                    != uaroSeMaxCreatures()) ++bad;
            if (uaroSeExampleOneDays() != 200)
                ++bad;
            if (uaroSeExampleFourDays() != 50)
                ++bad;
            if (uaroSeExampleSixtyDays() != 3)
                ++bad;
            if (uaroSeGroup101to200Days() != 1)
                ++bad;
            // the days divide by the
            // creature count
            if (uaroSeDaysBase()
                    / 4 != uaroSeExampleFourDays())
                ++bad;
            if (uaroSeDaysBase()
                    / 60 != uaroSeExampleSixtyDays())
                ++bad;
            if (!uaroSeNoAging()) ++bad;
            if (uaroSeHealingRateMult() != 2) ++bad;
            if (!uaroSeFoodFruitsVegetables())
                ++bad;
            if (!uaroSeReappearOnExpiry()) ++bad;
            if (uaroSeRechargeClericLevel() != 16)
                ++bad;
            if (uaroSeRechargeMuLevel() != 18)
                ++bad;
            // security's recharge is
            // the stricter cousin of
            // alertness's cleric-16
            if (uaroSeRechargeClericLevel()
                    != uaroAlRechargeClericLevel())
                ++bad;
        // ---- the staff-mace ----
            if (!uaroSmClericalWeapon()) ++bad;
            if (!uaroSmFaintAlterationDweomer())
                ++bad;
            if (uaroSmFormCount() != 3) ++bad;
            if (uaroSmQuarterstaffBonus() != 3)
                ++bad;
            if (!uaroSmQuarterstaffIronShod())
                ++bad;
            if (uaroSmGreatMaceBonus() != 1) ++bad;
            if (uaroSmMaceBonus() != 2) ++bad;
            if (!uaroSmBronzewoodIronBound()) ++bad;
            // the form bonuses run
            // 3, 1, 2 and sum to the
            // form count
            if (uaroSmQuarterstaffBonus()
                    + uaroSmGreatMaceBonus()
                    + uaroSmMaceBonus()
                    != 2 * uaroSmFormCount()) ++bad;
        // ---- the staff of slinging ----
            if (!uaroSlAppearsPlusOne()) ++bad;
            if (!uaroSlDruidOnly()) ++bad;
            if (uaroSlMaxObjectDiamInches() != 9)
                ++bad;
            if (uaroSlMaxObjectPounds() != 5) ++bad;
            if (!uaroSlReleaseIsOverhandArc())
                ++bad;
            if (uaroSlRiseFeetPerInchRange() != 1)
                ++bad;
            if (uaroSlMaxRangeIn() != 18) ++bad;
            if (uaroSlShortRangeIn() != 6) ++bad;
            if (uaroSlMediumRangeIn() != 12) ++bad;
            // short + medium bound
            // the maximum range
            if (uaroSlShortRangeIn()
                    + uaroSlMediumRangeIn()
                    != uaroSlMaxRangeIn()) ++bad;
            if (uaroSlGiantHurlChargeCost() != 1)
                ++bad;
            if (uaroSlGiantHurlRangeIn() != 30)
                ++bad;
            if (uaroSlGiantHurlDmgLo() != 3) ++bad;
            if (uaroSlGiantHurlDmgHi() != 30) ++bad;
            if (uaroSlHitBonus() != 1) ++bad;
            if (uaroSlDmgPerDieBonus() != 1) ++bad;
            if (uaroSlRechargeDruidLevel() != 12)
                ++bad;
        // ---- the extract ledger ----
            if (uaroCleanCount() != 11) ++bad;
            if (uaroGarbledCount() != 0) ++bad;
            if (uaroTotalTypes() != 11) ++bad;
            if (uaroCleanCount() + uaroGarbledCount()
                    != uaroTotalTypes()) ++bad;
        // ---- the R378 rings seam ----
            if (uarpCleanCount() != 13) ++bad;
            if (uarpGarbledCount() != 0) ++bad;
        // ---- the R375 skeleton seam ----
            // the rods staves and
            // wands ride the 41-45
            // band, split 01-40 new
            // / 41-00 the II.D.2
            if (uadsCategoryLo(3) != 41) ++bad;
            if (uadsCategoryHi(3) != 45) ++bad;
            if (uadsRodSplitLo() != 40) ++bad;
            if (!uadsRodSecondTableIsIID2())
                ++bad;
            if (uadsRowBodiesGarble()) ++bad;
        printf("R379 UA new rods staves prose pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
