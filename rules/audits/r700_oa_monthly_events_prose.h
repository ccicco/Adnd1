    // ---- R700 OA monthly events prose audit ----
    // OA round eighty-seven (capture pp. 243-247): the Explanation of Monthly
    // Events - the twenty-eight Table 72 events explained with their
    // durations, chances and effects, plus the worked example and the
    // player-character interaction rules, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djnBadHarvestFarmPct() != 25
            || djnBadHarvestFaminePct() != 5
            || djnBadHarvestFoodPct() != 50
            || djnBadWeatherMovePct() != 50
            || djnBadWeatherDesertPct() != 15
            || djnBadWeatherFarmPct() != 15
            || djnBanditMin() != 20
            || djnBanditMax() != 200
            || djnBanditCaravanPct() != 50
            || djnBanditLonePct() != 80
            || djnBirthNoblePct() != 95
            || djnBirthMiraclePct() != 5
            || djnBirthMonths() != 9
            || djnDeathHeirPct() != 30
            || djnDeathWeeksMin() != 2
            || djnDeathWeeksMax() != 7
            || djnQuakeMinorRadiusMi() != 5
            || djnQuakeMinorBldgPct() != 50
            || djnQuakeMinorMajorFirePct() != 20
            || djnQuakeMinorMinorFirePct() != 30
            || djnQuakeMinorPriceMonthsMin() != 1
            || djnQuakeMinorPriceMonthsMax() != 2
            || djnTaxesUprisingPct() != 30
            || djnTaxesBanditPct() != 70
            || djnFamousWeeksDie() != 6
            || djnFireMinorCityMin() != 10
            || djnFireMinorCityMax() != 40
            || djnFireMinorTownMin() != 50
            || djnFireMinorTownMax() != 70
            || djnFireMinorVillageMin() != 80
            || djnFireMinorVillageMax() != 100
            || djnFloodingWaveDice() != 5
            || djnFloodingWaveDie() != 4
            || djnFloodingWidthMinFt() != 101
            || djnFloodingWidthMaxFt() != 200
            || djnFloodingMilesDie() != 6
            || djnFloodingInchesDice() != 3
            || djnFloodingInchesDie() != 2
            || djnInjusticeAccusePct() != 5
            || djnInjusticeEnemyPct() != 20
            || djnLandslideWeeksMin() != 1
            || djnLandslideWeeksMax() != 2
            || djnMaidenNoblePct() != 50
            || djnMaidenMagicPct() != 30
            || djnMaidenPrincessPct() != 10
            || djnMaidenCommonerPct() != 10
            || djnMaidenMinStat() != 13
            || djnManeaterStrikesMin() != 1
            || djnManeaterStrikesMax() != 2
            || djnRecruitSweptPct() != 20
            || djnTroopsSpyPct() != 10
            || djnTroopsNinjaPct() != 40
            || djnUprisingArmorPct() != 10
            || djnUprisingMonasteryPct() != 60
            || djnUprisingTrainMin() != 2
            || djnUprisingTrainMax() != 4
            || djnUprisingGovtListensPct() != 70
            || djnUprisingBanditAfterPct() != 70
            || djnUprisingBanditAfterMin() != 1
            || djnUprisingBanditAfterMax() != 3
            || djnStrangerFindsPct() != 70
            || djnExampleYearlyRoll() != 82
            || djnExampleMonthRoll() != 5
            || djnExampleDurationRoll() != 3
            || djnExampleThirdColMonths() != 4
            || djnExampleFirstColMonths() != 3
            || !djnAccidentDMDecides()
            || !djnAccidentRangedOutcome()
            || !djnBadHarvestBlameRuler()
            || !djnBanditHasSpies()
            || !djnBanditBoastAutoAttack()
            || !djnBanditStaysUntilSlim()
            || !djnBirthPCTold()
            || !djnBirthMiracleOrigins()
            || !djnDeathHereditarySon()
            || !djnDeathWeakGovtSeized()
            || !djnDeathDutiesWait()
            || !djnQuakeMinorTremorsFirst()
            || !djnTaxesDebtSlavery()
            || !djnFamousQuietArrival()
            || !djnFamousSecretReasons()
            || !djnFireMinorLifeMinor()
            || !djnFloodingSuddenNotYearly()
            || !djnFloodingFlotationSaves()
            || !djnHauntingDMDecides()
            || !djnHauntingAdventureReady()
            || !djnMonsterWorshippedIfUnbeaten()
            || !djnMonsterKinAppear()
            || !djnIncursionMajorSudden()
            || !djnIncursionMajorPermanentIntent()
            || !djnIncursionMinorSameButSmall()
            || !djnInjusticeStoppable()
            || !djnLandslideHillsOnly()
            || !djnLandslideSpedBySpells()
            || !djnMaidenArtRequired()
            || !djnMaidenImpossibleTasks()
            || !djnBattleBattlesystem()
            || !djnManeaterUntilKilled()
            || !djnMarriagePCAccepted()
            || !djnMarriageFeasting()
            || !djnCriminalMaybeRumor()
            || !djnPlagueSeeYearly()
            || !djnTroopsNoRepayment()
            || !djnUprisingSpontaneous()
            || !djnUprisingNoQuarter()
            || !djnUprisingDoomedWithoutPCs()
            || !djnStrangerAncestralFeud()
            || !djnVIPDisguiseWhenInvestigating()
            || !djnVIPBanquets()
            || !djnMonthlyRerollable()
            || !djnDMPreparesAdventures()
            || !djnExampleClosesThirdCol()
        )
            ++bad;
        // the harvest, the weather and the bandits - the 25/5/50 harvest, the
        // 50/15/15 weather, the 20-200 bandits, the 50/80 attacks
    if (djnBadHarvestFarmPct() != 25
            || djnBadHarvestFaminePct() != 5
            || djnBadHarvestFoodPct() != 50
            || djnBadWeatherMovePct() != 50
            || djnBadWeatherDesertPct() != 15
            || djnBadWeatherFarmPct() != 15
            || djnBanditMin() != 20
            || djnBanditMax() != 200
            || djnBanditCaravanPct() != 50
            || djnBanditLonePct() != 80
        )
            ++bad;
        // the birth and the death - the 95/5 birth, the nine months, the 30%
        // heir, the 2-7 weeks
    if (djnBirthNoblePct() != 95
            || djnBirthMiraclePct() != 5
            || djnBirthMonths() != 9
            || djnDeathHeirPct() != 30
            || djnDeathWeeksMin() != 2
            || djnDeathWeeksMax() != 7
        )
            ++bad;
        // the minor quake and the taxes - the 5-mile radius, the 50/20/30
        // damage and fires, the 1-2 months, the 30/70 taxes
    if (djnQuakeMinorRadiusMi() != 5
            || djnQuakeMinorBldgPct() != 50
            || djnQuakeMinorMajorFirePct() != 20
            || djnQuakeMinorMinorFirePct() != 30
            || djnQuakeMinorPriceMonthsMin() != 1
            || djnQuakeMinorPriceMonthsMax() != 2
            || djnTaxesUprisingPct() != 30
            || djnTaxesBanditPct() != 70
        )
            ++bad;
        // the minor fire and the flooding - the 10-40/50-70/80-100 burns, the
        // 5d4 wave, the 101-200 feet, the 1d6 miles, the 3d2 inches
    if (djnFireMinorCityMin() != 10
            || djnFireMinorCityMax() != 40
            || djnFireMinorTownMin() != 50
            || djnFireMinorTownMax() != 70
            || djnFireMinorVillageMin() != 80
            || djnFireMinorVillageMax() != 100
            || djnFloodingWaveDice() != 5
            || djnFloodingWaveDie() != 4
            || djnFloodingWidthMinFt() != 101
            || djnFloodingWidthMaxFt() != 200
            || djnFloodingMilesDie() != 6
            || djnFloodingInchesDice() != 3
            || djnFloodingInchesDie() != 2
        )
            ++bad;
        // the injustice, the landslide and the maiden - the 5/20 accusations,
        // the 1-2 weeks, the 50/30/10/10 maiden, the 13s
    if (djnInjusticeAccusePct() != 5
            || djnInjusticeEnemyPct() != 20
            || djnLandslideWeeksMin() != 1
            || djnLandslideWeeksMax() != 2
            || djnMaidenNoblePct() != 50
            || djnMaidenMagicPct() != 30
            || djnMaidenPrincessPct() != 10
            || djnMaidenCommonerPct() != 10
            || djnMaidenMinStat() != 13
        )
            ++bad;
        // the maneater, the recruiting, the troops and the uprising - the 1-2
        // strikes, the 20% sweep, the 10/40 troops, the 10/60/70/70 uprising,
        // the 2-4 and 1-3 months
    if (djnManeaterStrikesMin() != 1
            || djnManeaterStrikesMax() != 2
            || djnRecruitSweptPct() != 20
            || djnTroopsSpyPct() != 10
            || djnTroopsNinjaPct() != 40
            || djnUprisingArmorPct() != 10
            || djnUprisingMonasteryPct() != 60
            || djnUprisingTrainMin() != 2
            || djnUprisingTrainMax() != 4
            || djnUprisingGovtListensPct() != 70
            || djnUprisingBanditAfterPct() != 70
            || djnUprisingBanditAfterMin() != 1
            || djnUprisingBanditAfterMax() != 3
        )
            ++bad;
        // the stranger, the VIP and the worked example - the 70% stranger,
        // the 82/5/3 rolls, the 4/3 column split
    if (djnStrangerFindsPct() != 70
            || djnExampleYearlyRoll() != 82
            || djnExampleMonthRoll() != 5
            || djnExampleDurationRoll() != 3
            || djnExampleThirdColMonths() != 4
            || djnExampleFirstColMonths() != 3
        )
            ++bad;
        // the rigidity bools - the rerollable monthly, the prepared
        // adventures, the quiet famous visitor, the disguised VIP
    if (djnMonthlyRerollable() != 1
            || djnDMPreparesAdventures() != 1
            || djnFamousQuietArrival() != 1
            || djnVIPDisguiseWhenInvestigating() != 1
            || djnStrangerAncestralFeud() != 1
        )
            ++bad;
        printf("R700 OA monthly events prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
