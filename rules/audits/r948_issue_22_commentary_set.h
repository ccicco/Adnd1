    // ---- R948 issue-22 commentary set audit ----
    // the five-chain commentary audit - the design philosophy essay, the pole
    // arms taxonomy, the Berg rebuttal, the Kassala battle report and the
    // games catalog roster
    {
        using namespace rules;
        int bad = 0;
    if (k22PlayersNow() != 150000
            || k22FirstThousandMonths() != 11
            || k22SecondThousandLowMonths() != 5
            || k22SecondThousandHighMonths() != 6
            || k22ThirdPrintingSets() != 2000
            || k22ThirdPrintingMonths() != 5
            || k22OriginalSetsByEnd() != 4000
            || k22PiracyLowPct() != 20
            || k22PiracyHighPct() != 50
            || k22BasicMonthlyCopies() != 4000
            || k22GameBornYear() != 1974
            || k22BasicSetYear() != 1977
            || k22HaftMinFeet() != 5
            || k22UltimatePikeLowFeet() != 18
            || k22UltimatePikeHighFeet() != 21
            || k22AxeHaftFeet() != 5
            || k22PikeMinFeet() != 15
            || k22AshSpearFeet() != 12
            || k22NormanLanceFeet() != 12
            || k22LanceAvgFeet() != 14
            || k22LanceReachFeet() != 10
            || k22PikeShaftGuardFeet() != 2
            || k22SpetumBladeDegrees() != 45
            || k22SempachYear() != 1386
            || k22HalberdFeet() != 8
            || k22ArbedoYear() != 1422
            || k22BardicheHeadLowFeet() != 2
            || k22BardicheHeadHighFeet() != 3
            || k22FlailShaftLowFeet() != 3
            || k22FlailShaftHighFeet() != 4
            || k22FlailTotalFeet() != 5
            || k22MorningStarLowFeet() != 3
            || k22MorningStarHighFeet() != 5
            || k22LucernHammerProngs() != 3
            || k22BillGuisarmeFeatures() != 4
            || k22PickShaftMinFeet() != 5
            || k22FauchardForkForms() != 2
            || k22SwissPikePct() != 40
            || k22SwissHalberdPct() != 40
            || k22SwissShotPct() != 20
            || k22KassalaYear() != 1541
            || k22PortugalInfantry() != 400
            || k22FirearmsStand() != 1000
            || k22GallaCohorts() != 2
            || k22CohortStrength() != 400
            || k22EthiopianCavReserve() != 160
            || k22EnemiesToFront() != 2600
            || k22HomelandMiles() != 3000
            || k22NubianFoot() != 1000
            || k22MamalukeCount() != 600
            || k22TurkishHeavyCount() != 200
            || k22ArabMercCount() != 400
            || k22CenterUnitStrength() != 200
            || k22UdakaGarrison() != 100
            || k22ArmedSlaves() != 120
            || k22IagoWing() != 300
            || k22RimMusketeers() != 100
            || k22FlankAttackers() != 1400
            || k22FlankDefenders() != 520
            || k22MusketBallsVolley() != 200
            || k22MusketBallEighths() != 12
            || k22PrintLeadPounds() != 15
            || k22GhashMilesToDeath() != 20
            || k22VolleysFired() != 3
            || k22EnemyStrengthPctPlus() != 30
            || k22DmSearchClaimedNames() != 500
            || k22DmSearchCutOffDay() != 18
            || k22DmSearchCutOffYear() != 1978
            || k22DmSearchUpdateLowMonths() != 3
            || k22DmSearchUpdateHighMonths() != 4
            || k22BackIssuePriceCents() != 210
            || k22BackIssueVolTwoCount() != 7
            || k22BackIssueVolThreeCount() != 5
            || k22GamesCatalogCount() != 21
            || k22HobbitronicsMembers() != 9
            || k22NamedDungeonCount() != 5
            || k22PoleArmFamCount() != 7
            || !k22AristotleAnalogy()
            || !k22DmPlaywrightThespians()
            || !k22CooperativeGame()
            || !k22EverybodyWins()
            || !k22DmDisinterestedReferee()
            || !k22BasicSetHadGeomorphs()
            || !k22NewestBasicModule()
            || !k22TwoDirections()
            || !k22NoPerpetualRevision()
            || !k22ChessMonopolyStamp()
            || !k22HomeComputerDirection()
            || !k22ColumnIsForum()
            || !k22WroteForMiniaturists()
            || !k22SaxtorphMaceError()
            || !k22MaceCastOnePiece()
            || !k22MorningStarRadiatingSpikes()
            || !k22RanseurBackwardHooks()
            || !k22EarSpoonPartisan()
            || !k22HalberdSpikeHook()
            || !k22BardicheTransitional()
            || !k22BardicheEasternEurope()
            || !k22LochaberRecanted()
            || !k22FauchardInefficient()
            || !k22GuisarmeReverseSpike()
            || !k22BillHookLTine()
            || !k22MilitaryForkThirdTine()
            || !k22MorningStarSprinkler()
            || !k22LucernHammerReplaced()
            || !k22BecDeCorbinKnightly()
            || !k22StoneForkError()
            || !k22SecondaryTipsIgnored()
            || !k22PartisanSpearFamily()
            || !k22BrownBillHalberd()
            || !k22BillGuisarmeLongest()
            || !k22ScorpionBillGuisarme()
            || !k22SwissPikeNotGrounded()
            || !k22BergDoesNotPlay()
            || !k22PhMereRewrite()
            || !k22PigsLipsQuote()
            || !k22UniformlyFavorable()
            || !k22IvoryChessmenAnalogy()
            || !k22SpiRehashMasters()
            || !k22PotSalverImage()
            || !k22TolkienCoattails()
            || !k22BallBackInCourt()
            || !k22BorrowedFigures()
            || !k22ThreePlayersOneUmpire()
            || !k22NoStrategicPrelude()
            || !k22NoFiresLit()
            || !k22PassiveDefense()
            || !k22NoRetreatWorry()
            || !k22AbatisBarbWire()
            || !k22BeshrabiGunRaid()
            || !k22ArabCannonFail()
            || !k22ArabBreakthroughSnuffed()
            || !k22JanissaryWithdraw()
            || !k22NubianRout()
            || !k22StalemateLesson()
            || !k22SuliemanKhartoum()
            || !k22EditorTownTarget()
            || !k22MuezzinDawn()
            || !k22AssumeDndIfSilent()
            || !k22SchoolYearItalics()
            || !k22NoOtherCorrespondence()
            || !k22PostmasterRemoval()
            || !k22ClubsWherePossible()
            || !k22NoBoardGames()
            || !k22SpaceQuestUnknown()
            || !k22OnceAWeekAtMost()
            || !k22RosterMisspellApology()
            || !k22ListerineMillions()
            || !k22ArrhInsane()
        )
            ++bad;
        // the pole arm families grid - the seven basic families of the
        // taxonomy by the member counts of the summation sentence, pinned by
        // the print order
        int CPf[7][2] = {
            {1,6},
            {2,3},
            {3,2},
            {4,1},
            {5,1},
            {6,2},
            {7,1},
            };
        for (int b = 0;
             b < k22PoleArmFamCount();
             ++b) {
            int vals[2];
            vals[0] = k22PoleArmFamCode(b);
            vals[1] = k22PoleArmFamMembers(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CPf[b][c])
                    ++bad;
            }
        }
        // the sales history - the hundred-fifty-thousand estimate and the
        // eleven-month, two-thousand-set and four-thousand-set milestones the
        // design philosophy essay (print 29-30)
    if (k22PlayersNow() != 150000
            || k22FirstThousandMonths() != 11
            || k22ThirdPrintingSets() != 2000
            || k22ThirdPrintingMonths() != 5
            || k22OriginalSetsByEnd() != 4000
        )
            ++bad;
        // the growth frame - the vague five-or-six months, the piracy
        // estimates and the monthly Basic Set sales the design philosophy
        // essay (print 29-30)
    if (k22SecondThousandLowMonths() != 5
            || k22SecondThousandHighMonths() != 6
            || k22PiracyLowPct() != 20
            || k22PiracyHighPct() != 50
            || k22BasicMonthlyCopies() != 4000
        )
            ++bad;
        // the philosophy frame - the seventy-four birth, the seventy-seven
        // Basic Set, the Poetics analogy, the everybody answer and the
        // home-computer direction the design philosophy essay (print 29-30)
    if (k22GameBornYear() != 1974
            || k22BasicSetYear() != 1977
            || k22AristotleAnalogy() != 1
            || k22EverybodyWins() != 1
            || k22HomeComputerDirection() != 1
        )
            ++bad;
        // the taxonomy floor - the five-foot minimum, the
        // eighteen-to-twenty-one-foot pike, the fifteen-foot pike line and
        // the ash spear the pole arms taxonomy (print 50-54)
    if (k22HaftMinFeet() != 5
            || k22UltimatePikeLowFeet() != 18
            || k22UltimatePikeHighFeet() != 21
            || k22PikeMinFeet() != 15
            || k22AshSpearFeet() != 12
            || k22AxeHaftFeet() != 5
        )
            ++bad;
        // the spear and lance lengths - the Norman twelve, the fourteen
        // average, the ten-foot reach, the two-foot shaft guard and the
        // spetum forty-five the pole arms taxonomy (print 50-54)
    if (k22NormanLanceFeet() != 12
            || k22LanceAvgFeet() != 14
            || k22LanceReachFeet() != 10
            || k22PikeShaftGuardFeet() != 2
            || k22SpetumBladeDegrees() != 45
        )
            ++bad;
        // the halberd and bardiche frame - the eight-foot weapon, the Arbedo
        // and Sempach references and the two-to-over-three-foot bardiche head
        // the pole arms taxonomy (print 50-54)
    if (k22HalberdFeet() != 8
            || k22ArbedoYear() != 1422
            || k22SempachYear() != 1386
            || k22BardicheHeadLowFeet() != 2
            || k22BardicheHeadHighFeet() != 3
        )
            ++bad;
        // the borderline pole arms - the three-to-four-foot flail shaft over
        // the five-foot whole and the three-to-five-foot morning star the
        // pole arms taxonomy (print 50-54)
    if (k22FlailShaftLowFeet() != 3
            || k22FlailShaftHighFeet() != 4
            || k22FlailTotalFeet() != 5
            || k22MorningStarLowFeet() != 3
            || k22MorningStarHighFeet() != 5
        )
            ++bad;
        // the special cases - the three-pronged Lucern hammer, the four
        // bill-guisarme features, the five-foot pole-mounted picks and the
        // two fauchard-fork forms the pole arms taxonomy (print 50-54)
    if (k22LucernHammerProngs() != 3
            || k22BillGuisarmeFeatures() != 4
            || k22PickShaftMinFeet() != 5
            || k22FauchardForkForms() != 2
        )
            ++bad;
        // the Swiss mix - the forty-forty-twenty pike, halberd and shot
        // proportions the pole arms taxonomy (print 50-54)
    if (k22SwissPikePct() != 40
            || k22SwissHalberdPct() != 40
            || k22SwissShotPct() != 20
        )
            ++bad;
        // the misnaming evidence - the Saxtorph mace, the Stone glossary
        // fork, the recanted lochaber and the not-grounded Swiss pike the
        // pole arms taxonomy (print 50-54)
    if (k22SaxtorphMaceError() != 1
            || k22StoneForkError() != 1
            || k22LochaberRecanted() != 1
            || k22SwissPikeNotGrounded() != 1
        )
            ++bad;
        // the rebuttal frame - the does-not-play handicap, the mere-rewrite
        // charge, the pigs-lips quote, the favorable reaction and the closing
        // ball the Berg rebuttal (print 44)
    if (k22BergDoesNotPlay() != 1
            || k22PhMereRewrite() != 1
            || k22PigsLipsQuote() != 1
            || k22UniformlyFavorable() != 1
            || k22BallBackInCourt() != 1
        )
            ++bad;
        // the countercharge set - the rehash masters, the besooted pot and
        // the silver salver, the Tolkien coattails and the ivory chessmen the
        // Berg rebuttal (print 44)
    if (k22PotSalverImage() != 1
            || k22SpiRehashMasters() != 1
            || k22TolkienCoattails() != 1
            || k22IvoryChessmenAnalogy() != 1
        )
            ++bad;
        // the historical frame - the fifteen-forty-one expedition, the four
        // hundred infantry, the thousand stand of firearms, the three
        // thousand miles and the dying river the Kassala battle report (print
        // 45-47)
    if (k22KassalaYear() != 1541
            || k22PortugalInfantry() != 400
            || k22FirearmsStand() != 1000
            || k22HomelandMiles() != 3000
            || k22GhashMilesToDeath() != 20
        )
            ++bad;
        // the Christian order of battle - the four hundred Galla plus two
        // cohorts, the one-hundred-sixty cavalry reserve, the twenty-six
        // hundred to the front at thirty percent over the Kassala battle
        // report (print 45-47)
    if (k22GallaCohorts() != 2
            || k22CohortStrength() != 400
            || k22EthiopianCavReserve() != 160
            || k22EnemiesToFront() != 2600
            || k22EnemyStrengthPctPlus() != 30
        )
            ++bad;
        // the Moslem order of battle - the thousand Nubians, the six hundred
        // Mamalukes, the two hundred Turkish heavy, the four hundred Arabs
        // and the two-hundred-strong center units the Kassala battle report
        // (print 45-47)
    if (k22NubianFoot() != 1000
            || k22MamalukeCount() != 600
            || k22TurkishHeavyCount() != 200
            || k22ArabMercCount() != 400
            || k22CenterUnitStrength() != 200
        )
            ++bad;
        // the Iago wing - the hundred in Udaka, the one hundred twenty armed
        // slaves, the three hundred who about-faced, the hundred musketeers
        // at the rim and the five hundred twenty the Kassala battle report
        // (print 45-47)
    if (k22UdakaGarrison() != 100
            || k22ArmedSlaves() != 120
            || k22IagoWing() != 300
            || k22RimMusketeers() != 100
            || k22FlankDefenders() != 520
        )
            ++bad;
        // the firefight - the fourteen hundred against the volley arithmetic,
        // the two hundred twelve-eighth-ounce balls against the printed
        // fifteen pounds, and the three volleys the Kassala battle report
        // (print 45-47)
    if (k22FlankAttackers() != 1400
            || k22MusketBallsVolley() != 200
            || k22MusketBallEighths() != 12
            || k22PrintLeadPounds() != 15
            || k22VolleysFired() != 3
        )
            ++bad;
        // the roster frame - the five hundred plus names, the December
        // seventy-eight cut-off and the three-to-four-month update cycle the
        // games catalog roster (print 18-28)
    if (k22DmSearchClaimedNames() != 500
            || k22DmSearchCutOffDay() != 18
            || k22DmSearchCutOffYear() != 1978
            || k22DmSearchUpdateLowMonths() != 3
            || k22DmSearchUpdateHighMonths() != 4
        )
            ++bad;
        // the back-issue frame - the two-ten price with the seven Volume Two
        // and five Volume Three issues in stock the games catalog roster
        // (print 18-28)
    if (k22BackIssuePriceCents() != 210
            || k22BackIssueVolTwoCount() != 7
            || k22BackIssueVolThreeCount() != 5
        )
            ++bad;
        // the catalog color - the twenty-one games, the nine Hobbitronics,
        // the five named dungeons, the unknown Space Quest publisher and the
        // Listerine Brothers the games catalog roster (print 18-28)
    if (k22GamesCatalogCount() != 21
            || k22HobbitronicsMembers() != 9
            || k22NamedDungeonCount() != 5
            || k22SpaceQuestUnknown() != 1
            || k22ListerineMillions() != 1
        )
            ++bad;
        // the families spot check - the six-member dagger family first, the
        // three-member axe second and the single-member hay fork last the
        // pole arms taxonomy (print 50-54)
    if (k22PoleArmFamCode(0) != 1
            || k22PoleArmFamMembers(0) != 6
            || k22PoleArmFamMembers(1) != 3
            || k22PoleArmFamMembers(6) != 1
        )
            ++bad;
        // the families tail - the seventh family code, the two-member cleaver
        // and pruning-hook families and the single-member scythe the pole
        // arms taxonomy (print 50-54)
    if (k22PoleArmFamCode(6) != 7
            || k22PoleArmFamMembers(2) != 2
            || k22PoleArmFamMembers(3) != 1
            || k22PoleArmFamMembers(5) != 2
        )
            ++bad;
        printf("R948 issue-22 commentary set audit: bad %d\n", bad);
        if (bad) return 1;
    }
