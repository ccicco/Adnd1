    // ---- R702 OA daily events prose audit ----
    // OA round eighty-nine (capture pp. 247-251): the Explanation of Daily
    // Events - the twenty-nine events of Table 73 explained in prose, the
    // dice, the percentages, and the consequences, plus the daily frame and
    // the ruins type bands, single-pass pins per the Chapter 9 provenance
    // shift
    {
        using namespace rules;
        int bad = 0;
    if (djpDailyEventsMaxPerDay() != 3
            || djpBanditsCampDice() != 2
            || djpBanditsCampDie() != 10
            || djpBanditsWarnersCount() != 2
            || djpBanditsScoutDice() != 3
            || djpBanditsScoutDie() != 10
            || djpContestHonorLost() != 2
            || djpFireSmallIntentionalPct() != 70
            || djpFireSmallSpreadPct() != 70
            || djpIllnessPCTargetPct() != 20
            || djpIllnessNPCTargetPct() != 80
            || djpIllnessCourseDice() != 2
            || djpIllnessCourseDie() != 6
            || djpIllnessRestPerIllDay() != 1
            || djpMysteryInvestigatePct() != 60
            || djpNoblesBushiDice() != 2
            || djpNoblesBushiDie() != 10
            || djpNoblesSamuraiDie() != 6
            || djpNoblesRanksMin() != 1
            || djpNoblesRanksMax() != 3
            || djpNoblesOpenlyPct() != 80
            || djpNoblesDisguisePct() != 20
            || djpPiratesShipsMin() != 1
            || djpPiratesShipsMax() != 3
            || djpRuinTempleMin() != 1
            || djpRuinTempleMax() != 10
            || djpRuinTempleHauntedPct() != 70
            || djpRuinFarmhouseMin() != 11
            || djpRuinFarmhouseMax() != 60
            || djpRuinFarmhouseHauntedPct() != 20
            || djpRuinShrineMin() != 61
            || djpRuinShrineMax() != 90
            || djpRuinShrineHauntedPct() != 50
            || djpRuinStockadeMin() != 91
            || djpRuinStockadeMax() != 100
            || djpRuinStockadeHauntedPct() != 30
            || djpShipGhostPct() != 30
            || djpShipMerchantPct() != 50
            || djpShipWarPct() != 20
            || djpShipGajinPct() != 10
            || djpShrineBlessPct() != 10
            || djpShrineBlessHours() != 24
            || djpShrineCursePct() != 80
            || djpStormHoursDice() != 5
            || djpStormHoursDie() != 6
            || djpStormExhaustMin() != 1
            || djpStormExhaustMax() != 2
            || djpStrangerOrdinaryPct() != 30
            || djpStrangerSocietyPct() != 10
            || djpStrangerPolicePct() != 10
            || djpStrangerNinjaPct() != 10
            || djpStrangerNoblePct() != 10
            || djpStrangerBanditPct() != 10
            || djpStrangerHengeyokaiPct() != 10
            || djpStrangerYakuzaPct() != 10
            || djpVIPBushiDice() != 20
            || djpVIPBushiDie() != 6
            || djpVIPSamuraiDice() != 10
            || djpVIPSamuraiDie() != 4
            || !djpDailyEventsProvideTheAction()
            || !djpBanditsDelayWhileWarned()
            || !djpBanditsScoutsAvoidFight()
            || !djpBanditsPoseAsTravelers()
            || !djpBecalmedRowedThatDay()
            || !djpContestNobleStationOnly()
            || !djpContestFormalParty()
            || !djpContestExcusedForGoodReason()
            || !djpCrimeAdventureSeed()
            || !djpDuelShukenjaExempt()
            || !djpEntreatyPayOrBribed()
            || !djpFireSmallHomeBuilding()
            || !djpHauntingSeeMonthly()
            || !djpIllnessWorseUntreated()
            || !djpIllnessSaveVsDeath()
            || !djpInsultCourtComplaint()
            || !djpInsultLongTermEnemy()
            || !djpInvitationRefusalIsInsult()
            || !djpKidnapLoversGuisePossible()
            || !djpLandUnchartedDangerous()
            || !djpMonsterRollEncounterTable()
            || !djpNoblesPalanquinsOnFoot()
            || !djpPiratesSeeWakoDescription()
            || !djpPlotAdventureBasis()
            || !djpRuinsHauntedChanceInParens()
            || !djpShipGhostFerriesTheDead()
            || !djpShrineOfferingsRequired()
            || !djpSpecialAdventureStart()
            || !djpStormNoTravelThatDay()
            || !djpStormDesertSandstorm()
            || !djpStrangerTravelsAlong()
            || !djpTravelerDMDevises()
            || !djpVIPArrivalAnnounced()
            || !djpVIPImpudentCutDown()
        )
            ++bad;
        // the daily frame and the Bandits - the three events, the 2d10
        // camp-edge count with the two warners, the 3d10 mounted scouts
        // avoiding the fight, the becalmed rowing
    if (djpDailyEventsMaxPerDay() != 3
            || djpDailyEventsProvideTheAction() != 1
            || djpBanditsCampDice() != 2
            || djpBanditsCampDie() != 10
            || djpBanditsWarnersCount() != 2
            || djpBanditsScoutDice() != 3
            || djpBanditsScoutDie() != 10
            || djpBanditsDelayWhileWarned() != 1
            || djpBanditsScoutsAvoidFight() != 1
            || djpBanditsPoseAsTravelers() != 1
            || djpBecalmedRowedThatDay() != 1
        )
            ++bad;
        // the Contest and the Crime and the Duel - the two honor points lost,
        // the noble station, the judged formal party, the excused absence,
        // the adventure seed, the shukenja exempt
    if (djpContestHonorLost() != 2
            || djpContestNobleStationOnly() != 1
            || djpContestFormalParty() != 1
            || djpContestExcusedForGoodReason() != 1
            || djpCrimeAdventureSeed() != 1
            || djpDuelShukenjaExempt() != 1
        )
            ++bad;
        // the Entreaty and the Fire and the Haunting - the pay or bribe, the
        // 70% arson, the home building, the 70% spread, the see-monthly
        // haunting
    if (djpEntreatyPayOrBribed() != 1
            || djpFireSmallIntentionalPct() != 70
            || djpFireSmallHomeBuilding() != 1
            || djpFireSmallSpreadPct() != 70
            || djpHauntingSeeMonthly() != 1
        )
            ++bad;
        // the Illness and the Insult and the Invitation - the 20/80 target,
        // the 2d6 course, the rest rule, the save at the end, the court
        // complaint, the long-term enemy, the refusal insult
    if (djpIllnessPCTargetPct() != 20
            || djpIllnessNPCTargetPct() != 80
            || djpIllnessCourseDice() != 2
            || djpIllnessCourseDie() != 6
            || djpIllnessRestPerIllDay() != 1
            || djpIllnessWorseUntreated() != 1
            || djpIllnessSaveVsDeath() != 1
            || djpInsultCourtComplaint() != 1
            || djpInsultLongTermEnemy() != 1
            || djpInvitationRefusalIsInsult() != 1
        )
            ++bad;
        // the Kidnapping and the Land and the Monster and the Mystery - the
        // lovers guise, the uncharted danger, the table roll, the 60%
        // investigation
    if (djpKidnapLoversGuisePossible() != 1
            || djpLandUnchartedDangerous() != 1
            || djpMonsterRollEncounterTable() != 1
            || djpMysteryInvestigatePct() != 60
        )
            ++bad;
        // the Nobles and the Pirates - the 2d10 bushi, the 1d6 samurai, the
        // 1-3 of rank, the 80/20 open and disguised, the palanquins, the 1-3
        // wako ships
    if (djpNoblesBushiDice() != 2
            || djpNoblesBushiDie() != 10
            || djpNoblesSamuraiDie() != 6
            || djpNoblesRanksMin() != 1
            || djpNoblesRanksMax() != 3
            || djpNoblesOpenlyPct() != 80
            || djpNoblesDisguisePct() != 20
            || djpNoblesPalanquinsOnFoot() != 1
            || djpPiratesShipsMin() != 1
            || djpPiratesShipsMax() != 3
            || djpPiratesSeeWakoDescription() != 1
        )
            ++bad;
        // the Plot and the Ruins - the adventure basis, the 01-10 temple at
        // 70%, the 11-60 farmhouse at 20%, the 61-90 shrine at 50%, the
        // 91-100 stockade at 30%, the parenthesized haunt chance
    if (djpPlotAdventureBasis() != 1
            || djpRuinsHauntedChanceInParens() != 1
            || djpRuinTempleMin() != 1
            || djpRuinTempleMax() != 10
            || djpRuinTempleHauntedPct() != 70
            || djpRuinFarmhouseMin() != 11
            || djpRuinFarmhouseMax() != 60
            || djpRuinFarmhouseHauntedPct() != 20
            || djpRuinShrineMin() != 61
            || djpRuinShrineMax() != 90
            || djpRuinShrineHauntedPct() != 50
            || djpRuinStockadeMin() != 91
            || djpRuinStockadeMax() != 100
            || djpRuinStockadeHauntedPct() != 30
        )
            ++bad;
        // the Ship and the Shrine and the Special - the 30% ghost ferrying
        // the dead, the 50% merchant (the OCR misprint repaired), the 20%
        // warship, the 10% gajin crew, the 10% bless for 24 hours, the 80%
        // curse, the mission start
    if (djpShipGhostPct() != 30
            || djpShipGhostFerriesTheDead() != 1
            || djpShipMerchantPct() != 50
            || djpShipWarPct() != 20
            || djpShipGajinPct() != 10
            || djpShrineBlessPct() != 10
            || djpShrineBlessHours() != 24
            || djpShrineCursePct() != 80
            || djpShrineOfferingsRequired() != 1
            || djpSpecialAdventureStart() != 1
        )
            ++bad;
        // the Storm and the Stranger - the 5d6 hours, the 1-2 per hour, the
        // no-travel day, the desert sandstorm, the 30% ordinary with the
        // seven 10s, the travels-along
    if (djpStormHoursDice() != 5
            || djpStormHoursDie() != 6
            || djpStormExhaustMin() != 1
            || djpStormExhaustMax() != 2
            || djpStormNoTravelThatDay() != 1
            || djpStormDesertSandstorm() != 1
            || djpStrangerOrdinaryPct() != 30
            || djpStrangerSocietyPct() != 10
            || djpStrangerPolicePct() != 10
            || djpStrangerNinjaPct() != 10
            || djpStrangerNoblePct() != 10
            || djpStrangerBanditPct() != 10
            || djpStrangerHengeyokaiPct() != 10
            || djpStrangerYakuzaPct() != 10
            || djpStrangerTravelsAlong() != 1
        )
            ++bad;
        // the Traveler and the VIP - the DM devises, the 20d6 bushi, the 10d4
        // samurai, the announced arrival, the impudent cut down
    if (djpTravelerDMDevises() != 1
            || djpVIPBushiDice() != 20
            || djpVIPBushiDie() != 6
            || djpVIPSamuraiDice() != 10
            || djpVIPSamuraiDie() != 4
            || djpVIPArrivalAnnounced() != 1
            || djpVIPImpudentCutDown() != 1
        )
            ++bad;
        printf("R702 OA daily events prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
