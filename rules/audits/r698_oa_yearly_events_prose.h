    // ---- R698 OA yearly events prose audit ----
    // OA round eighty-five (capture pp. 240-243): the Explanation of Yearly
    // Events - the nineteen Table 71 events explained with their durations,
    // chances and effects, plus the never-rerolled rule, single-pass pins per
    // the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djlAmbassadorStayDiceCount() != 3
            || djlAmbassadorStayDieSize() != 10
            || djlAmbassadorGaijinPct() != 10
            || djlAssassinAlivePct() != 30
            || djlAssassinAccusePct() != 1
            || djlAssassinNoSuccessorPct() != 20
            || djlAssassinTurmoilDie() != 6
            || djlCometDieSize() != 4
            || djlQuakeRadiusMi() != 50
            || djlQuakeFirePct() != 70
            || djlQuakePlaguePct() != 40
            || djlFamineMinMonths() != 2
            || djlFamineMaxMonths() != 7
            || djlFaminePriceMaxX() != 100
            || djlFamineNextYearPct() != 25
            || djlFamineUprisingPct() != 60
            || djlFaminePopPct() != 5
            || djlFaminePlaguePct() != 20
            || djlFireMinPct() != 50
            || djlFireMaxPct() != 80
            || djlFirePopMinPct() != 10
            || djlFirePopMaxPct() != 40
            || djlFirePlaguePct() != 20
            || djlFireFaminePct() != 10
            || djlFireLumberX() != 10
            || djlFireLumberMonths() != 4
            || djlFloodMaxFt() != 30
            || djlFloodHighDieSize() != 6
            || djlFloodFarmPlantPct() != 50
            || djlFloodFarmHarvestPct() != 80
            || djlFloodHarvestFaminePct() != 40
            || djlFloodPlaguePct() != 20
            || djlIncursionDieSize() != 12
            || djlNewReligionHostilityPct() != 75
            || djlNewReligionRulerFavorPct() != 60
            || djlNewReligionBanPct() != 40
            || djlNewReligionArrivalMin() != 2
            || djlNewReligionArrivalMax() != 7
            || djlPlagueDieCount() != 2
            || djlPlagueDieSize() != 6
            || djlPlagueCatchPct() != 40
            || djlPlagueCatchCompanyPct() != 60
            || djlPlaguePopPct() != 5
            || djlPlagueImportX() != 5
            || djlPlotAccusePct() != 40
            || djlPlotAccuseEnemiesPct() != 80
            || djlPlotRebellionPct() != 20
            || djlPlotTurmoilMaxMonths() != 3
            || djlRebellionDieSize() != 6
            || djlTsunamiCoastMi() != 50
            || djlTsunamiHeightMinFt() != 100
            || djlTsunamiHeightMaxFt() != 200
            || djlTsunamiPopPct() != 70
            || djlTsunamiPlaguePct() != 10
            || djlTsunamiBuildX() != 3
            || djlVisitationRadiusMi() != 5
            || djlVolcanoDormantPct() != 70
            || djlVolcanoRadiusMi() != 5
            || djlVolcanoAshMi() != 30
            || djlVolcanoActiveDieSize() != 12
            || djlVolcanoReEruptPct() != 10
            || djlWarCampaignMinMonths() != 2
            || djlWarCampaignMaxMonths() != 5
            || djlWarDurationMaxYears() != 3
            || djlWarFarmPct() != 50
            || !djlAmbassadorEitherDirection()
            || !djlAssassinPcSuspicion()
            || !djlAssassinStruggleMayWar()
            || !djlBirthCelebration()
            || !djlCometPortentSecond()
            || !djlDeathSameAsAssassination()
            || !djlQuakeLesserTremors()
            || !djlQuakeSpellEffects()
            || !djlFamineSigns()
            || !djlFirePcPropertyBurned()
            || !djlFloodLevees()
            || !djlFloodNoDesert()
            || !djlIncursionProportionate()
            || !djlIncursionRemainsUntilDrivenOut()
            || !djlMarriageDiplomatic()
            || !djlNewReligionRulersTool()
            || !djlPlagueSweeps()
            || !djlPlotProveInnocence()
            || !djlRebellionBattlesystem()
            || !djlTsunamiNoCoastNoEvent()
            || !djlVisitationPaths()
            || !djlWarEitherDirection()
            || !djlWarPcRoles()
            || !djlWarHomefront()
            || !djlYearlyNeverRerolled()
            || !djlYearlyPreventedNone()
            || !djlYearlySeasonCheck()
        )
            ++bad;
        // the ambassador and the assassination - the 3d10 stay, the gaijin
        // 10, the alive 30, the accusation 1, the successor 20
    if (djlAmbassadorStayDiceCount() != 3
            || djlAmbassadorStayDieSize() != 10
            || djlAmbassadorGaijinPct() != 10
            || djlAssassinAlivePct() != 30
            || djlAssassinAccusePct() != 1
            || djlAssassinNoSuccessorPct() != 20
            || djlAssassinTurmoilDie() != 6
        )
            ++bad;
        // the earthquake and the famine - the 50-mile radius, the 70/40
        // chances, the 2-7 months, the 100x food, the 60% uprising
    if (djlQuakeRadiusMi() != 50
            || djlQuakeFirePct() != 70
            || djlQuakePlaguePct() != 40
            || djlFamineMinMonths() != 2
            || djlFamineMaxMonths() != 7
            || djlFaminePriceMaxX() != 100
            || djlFamineUprisingPct() != 60
        )
            ++bad;
        // the fire and the flood - the 50-80 city, the 10x lumber, the
        // 30-foot crest, the 50/80 farm losses
    if (djlFireMinPct() != 50
            || djlFireMaxPct() != 80
            || djlFireLumberX() != 10
            || djlFireLumberMonths() != 4
            || djlFloodMaxFt() != 30
            || djlFloodHighDieSize() != 6
            || djlFloodFarmPlantPct() != 50
            || djlFloodFarmHarvestPct() != 80
        )
            ++bad;
        // the new religion and the plague - the 75/60/40 chances, the 2-7
        // arrival, the 2d6 plague, the 40/60 contagion, the 5x imports
    if (djlNewReligionHostilityPct() != 75
            || djlNewReligionRulerFavorPct() != 60
            || djlNewReligionBanPct() != 40
            || djlNewReligionArrivalMin() != 2
            || djlNewReligionArrivalMax() != 7
            || djlPlagueDieCount() != 2
            || djlPlagueDieSize() != 6
            || djlPlagueCatchPct() != 40
            || djlPlagueCatchCompanyPct() != 60
            || djlPlagueImportX() != 5
        )
            ++bad;
        // the plot, the rebellion and the tsunami - the 40/80 accusations,
        // the 1d6 rebellion, the 70% tsunami loss, the 100-200 feet
    if (djlPlotAccusePct() != 40
            || djlPlotAccuseEnemiesPct() != 80
            || djlPlotRebellionPct() != 20
            || djlPlotTurmoilMaxMonths() != 3
            || djlRebellionDieSize() != 6
            || djlTsunamiPopPct() != 70
            || djlTsunamiHeightMinFt() != 100
            || djlTsunamiHeightMaxFt() != 200
        )
            ++bad;
        // the volcano and the war - the 70/30 origin, the 5-mile radius, the
        // 30-mile ash, the 2-5 month campaign, the 1-3 years
    if (djlVolcanoDormantPct() != 70
            || djlVolcanoRadiusMi() != 5
            || djlVolcanoAshMi() != 30
            || djlVolcanoActiveDieSize() != 12
            || djlVolcanoReEruptPct() != 10
            || djlWarCampaignMinMonths() != 2
            || djlWarCampaignMaxMonths() != 5
            || djlWarDurationMaxYears() != 3
            || djlWarFarmPct() != 50
        )
            ++bad;
        printf("R698 OA yearly events prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
