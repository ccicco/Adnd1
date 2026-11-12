    // ---- R946 issue-22 opener part one audit ----
    // THE DRAGON ISSUE-22 OPENER PART ONE - the three-chain military-history
    // triptych of the issue-22 four-round shape, the first four-round issue
    // walk. Three chains pinned: the Bruner assassin order history (Alamut,
    // Hasan Sabbah, the fildais, the Guide to Famous Assassinations
    // 1127-1192), the Gygax Swiss military doctrine (Morgarten through
    // Dornach, the dozen battles, the three-phalanx echelon, the army
    // composition percentages) and the Nascati Renaissance armies overview
    // (the longbow, the pike, the Hussite laager, the hussars, the mercenary
    // age). No watches moved: the Sullin levels 7-9 and the brawling sequel
    // still print nowhere and ride to TD 23.
    {
        using namespace rules;
        int bad = 0;
    if (t22AssassRockFeet() != 600
            || t22AssassRockWidthMin() != 30
            || t22AssassRockWidthMax() != 125
            || t22AssassRockLengthFeet() != 450
            || t22AssassDinarRansom() != 3000
            || t22AssassHasanBirth() != 1050
            || t22AssassHasanCairoYear() != 1078
            || t22AssassAlamutTaken() != 1090
            || t22AssassCampRaidYear() != 1092
            || t22AssassRaiders() != 70
            || t22AssassNizamAlMulkYear() != 1092
            || t22AssassMalikShahYear() != 1092
            || t22AssassWomenBanished() != 1108
            || t22AssassHattinYear() != 1187
            || t22AssassHasanDeath() != 1124
            || t22AssassRecruitAge() != 12
            || t22AssassLevels() != 7
            || t22AssassMarcoPoloYear() != 1273
            || t22AssassGuideFirst() != 1127
            || t22AssassGuideLast() != 1192
            || t22AssassGuideCount() != 8
            || t22AssassSixtyThousandFollowers() != 60000
            || t22AssassAgaKhanMillions() != 3
            || t22SwissMorgartenYear() != 1315
            || t22SwissMorgartenAustrians() != 15000
            || t22SwissMorgartenSwiss() != 1500
            || t22SwissLaupenYear() != 1339
            || t22SwissLaupenBurgundians() != 15000
            || t22SwissPhalanxes() != 3
            || t22SwissSempachYear() != 1386
            || t22SwissArbedoYear() != 1422
            || t22SwissArbedoGendarmes() != 6000
            || t22SwissArbedoSwiss() != 4000
            || t22SwissArbedoForagers() != 600
            || t22SwissStJacobYear() != 1444
            || t22SwissStJacobSwiss() != 600
            || t22SwissStJacobFrenchTable() != 30000
            || t22SwissStJacobFrenchText() != 15000
            || t22SwissStJacobFrenchLoss() != 2000
            || t22SwissGrandsonYear() != 1476
            || t22SwissMoratYear() != 1476
            || t22SwissNancyYear() != 1477
            || t22SwissDozenBattles() != 12
            || t22SwissBattlesFirst() != 1386
            || t22SwissBattlesLast() != 1499
            || t22SwissHedgehogPikemen() != 600
            || t22SwissCavalryMax() != 200
            || t22SwissPikeAfterArbedo() != 50
            || t22SwissHalberdCenterMin() != 20
            || t22SwissHalberdCenterMax() != 30
            || t22SwissCrossbowToArquebus() != 1450
            || t22SwissArquebusPersist() != 1500
            || t22SwissLaBicoccaYear() != 1522
            || t22SwissLaBicoccaLoss() != 3000
            || t22SwissMercBattles() != 5
            || t22SwissCompCount() != 6
            || t22ArmiesHundredYearsEnd() != 1453
            || t22ArmiesPikeBan() != 1703
            || t22ArmiesPikeMinFeet() != 12
            || t22ArmiesPikeMaxFeet() != 21
            || t22ArmiesLongbowRate() != 3
            || t22ArmiesThreeWeapons() != 3
            || t22ArmiesGreatCaptains() != 4
            || t22ArmiesBibliography() != 8
            || !t22AssassDaggerDemo()
            || !t22AssassHashishDebate()
            || !t22AssassGardenUnlikely()
            || !t22AssassDisguiseTraining()
            || !t22AssassCrusaderDealing()
            || !t22AssassSonsExecuted()
            || !t22AssassSanjarTruce()
            || !t22AssassBrunnerPrintCatch()
            || !t22SwissEchelonDoctrine()
            || !t22SwissKielWedge()
            || !t22SwissLancesAsPikes()
            || !t22SwissGrandsonCannae()
            || !t22SwissCharlesHalberdDeath()
            || !t22SwissElectedLeaders()
            || !t22SwissLightArmorDoctrine()
            || !t22SwissLogistics()
            || !t22SwissArtilleryFoe()
            || !t22SwissNeverBestedLandsknecht()
            || !t22SwissChainmailRec()
            || !t22SwissPrintCatch()
            || !t22ArmiesFranklinLongbow()
            || !t22ArmiesStardioDragoon()
            || !t22ArmiesHussarLevy()
            || !t22ArmiesZiskaLaager()
            || !t22ArmiesMercenaryAge()
            || !t22ArmiesZiskaSpellingPrintCatch()
            || !t22ArmiesSwissNextTime()
        )
            ++bad;
        // the Swiss field army composition - six troop types with their
        // percentage floors and ceilings, the halberd through the cavalry
        // lance, the c. 1450 halberd relegation and the crossbow-to-arquebus
        // switch noted in prose
        int CSc[6][2] = {
            {20,60},
            {10,20},
            {10,65},
            {5,30},
            {5,25},
            {0,5},
            };
        for (int b = 0;
             b < t22SwissCompCount();
             ++b) {
            int vals[2];
            vals[0] = t22SwissCompMin(b);
            vals[1] = t22SwissCompMax(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CSc[b][c])
                    ++bad;
            }
        }
        // the Alamut census - the six-hundred-foot rock, its width and
        // length, the dinar note and the sixty-thousand-follower boast the
        // assassin order history (print 5-7)
    if (t22AssassRockFeet() != 600
            || t22AssassRockWidthMin() != 30
            || t22AssassRockWidthMax() != 125
            || t22AssassRockLengthFeet() != 450
            || t22AssassDinarRansom() != 3000
            || t22AssassSixtyThousandFollowers() != 60000
        )
            ++bad;
        // the Hasan timeline - Ray 1050 through the 1092 double strike to the
        // 1124 succession the assassin order history (print 5-7)
    if (t22AssassHasanBirth() != 1050
            || t22AssassHasanCairoYear() != 1078
            || t22AssassAlamutTaken() != 1090
            || t22AssassCampRaidYear() != 1092
            || t22AssassRaiders() != 70
            || t22AssassNizamAlMulkYear() != 1092
            || t22AssassMalikShahYear() != 1092
            || t22AssassHasanDeath() != 1124
        )
            ++bad;
        // the fildais and the Guide - the twelve-year recruits, the seven
        // levels, the Marco Polo passage, the eight assassinations and the
        // Aga Khan tail the assassin order history (print 5-7)
    if (t22AssassRecruitAge() != 12
            || t22AssassLevels() != 7
            || t22AssassMarcoPoloYear() != 1273
            || t22AssassGuideFirst() != 1127
            || t22AssassGuideLast() != 1192
            || t22AssassGuideCount() != 8
            || t22AssassHattinYear() != 1187
            || t22AssassAgaKhanMillions() != 3
            || t22AssassWomenBanished() != 1108
        )
            ++bad;
        // the order doctrine bools - the demonstration, the etymology debate,
        // the garden doubt, the curriculum, the Crusader dealings, the
        // succession, the Sanjar truce and the Bruner print catch the
        // assassin order history (print 5-7)
    if (t22AssassDaggerDemo() != 1
            || t22AssassHashishDebate() != 1
            || t22AssassGardenUnlikely() != 1
            || t22AssassDisguiseTraining() != 1
            || t22AssassCrusaderDealing() != 1
            || t22AssassSonsExecuted() != 1
            || t22AssassSanjarTruce() != 1
            || t22AssassBrunnerPrintCatch() != 1
        )
            ++bad;
        // the Morgarten and Laupen pins - the ambush numbers and the
        // three-phalanx echelon born at Laupen the Swiss military doctrine
        // (print 8-11)
    if (t22SwissMorgartenYear() != 1315
            || t22SwissMorgartenAustrians() != 15000
            || t22SwissMorgartenSwiss() != 1500
            || t22SwissLaupenYear() != 1339
            || t22SwissLaupenBurgundians() != 15000
            || t22SwissPhalanxes() != 3
        )
            ++bad;
        // the Sempach and Arbedo pins - the Kiel wedge year and the
        // dismounted-lance lesson with its forager rescue the Swiss military
        // doctrine (print 8-11)
    if (t22SwissSempachYear() != 1386
            || t22SwissArbedoYear() != 1422
            || t22SwissArbedoGendarmes() != 6000
            || t22SwissArbedoSwiss() != 4000
            || t22SwissArbedoForagers() != 600
        )
            ++bad;
        // the St Jacob print catch - six hundred die to a man, the table
        // thirty thousand against the text fifteen thousand, and the La
        // Bicocca cost the Swiss military doctrine (print 8-11)
    if (t22SwissStJacobYear() != 1444
            || t22SwissStJacobSwiss() != 600
            || t22SwissStJacobFrenchTable() != 30000
            || t22SwissStJacobFrenchText() != 15000
            || t22SwissStJacobFrenchLoss() != 2000
            || t22SwissLaBicoccaYear() != 1522
            || t22SwissLaBicoccaLoss() != 3000
        )
            ++bad;
        // the Burgundian crush and the dozen battles - Grandson Morat Nancy,
        // the 1386-1499 span and the hedgehog the Swiss military doctrine
        // (print 8-11)
    if (t22SwissGrandsonYear() != 1476
            || t22SwissMoratYear() != 1476
            || t22SwissNancyYear() != 1477
            || t22SwissDozenBattles() != 12
            || t22SwissBattlesFirst() != 1386
            || t22SwissBattlesLast() != 1499
            || t22SwissHedgehogPikemen() != 600
        )
            ++bad;
        // the composition doctrine pins - the cavalry ceiling, the pike
        // decree, the halberd relegation, the missile switch and the
        // mercenary five the Swiss military doctrine (print 8-11)
    if (t22SwissCavalryMax() != 200
            || t22SwissPikeAfterArbedo() != 50
            || t22SwissHalberdCenterMin() != 20
            || t22SwissHalberdCenterMax() != 30
            || t22SwissCrossbowToArquebus() != 1450
            || t22SwissArquebusPersist() != 1500
            || t22SwissMercBattles() != 5
            || t22SwissCompCount() != 6
        )
            ++bad;
        // the Swiss doctrine bools - the echelon, the Kiel, the dismounted
        // lance, the Cannae ploy, the Rash end, the elected leaders, the
        // mobility, the logistics, the artillery verdict, the landsknecht
        // record, the Chainmail rec and the print catch the Swiss military
        // doctrine (print 8-11)
    if (t22SwissEchelonDoctrine() != 1
            || t22SwissKielWedge() != 1
            || t22SwissLancesAsPikes() != 1
            || t22SwissGrandsonCannae() != 1
            || t22SwissCharlesHalberdDeath() != 1
            || t22SwissElectedLeaders() != 1
            || t22SwissLightArmorDoctrine() != 1
            || t22SwissLogistics() != 1
            || t22SwissArtilleryFoe() != 1
            || t22SwissNeverBestedLandsknecht() != 1
            || t22SwissChainmailRec() != 1
            || t22SwissPrintCatch() != 1
        )
            ++bad;
        // the Renaissance span pins - 1453 to 1703, the
        // twelve-to-twenty-one-foot pike, the longbow rate, the three
        // developments, the captains and the bibliography the Renaissance
        // armies overview (print 12)
    if (t22ArmiesHundredYearsEnd() != 1453
            || t22ArmiesPikeBan() != 1703
            || t22ArmiesPikeMinFeet() != 12
            || t22ArmiesPikeMaxFeet() != 21
            || t22ArmiesLongbowRate() != 3
            || t22ArmiesThreeWeapons() != 3
            || t22ArmiesGreatCaptains() != 4
            || t22ArmiesBibliography() != 8
        )
            ++bad;
        // the overview doctrine bools - the Franklin note, the stardio, the
        // hussars, the laager, the mercenary age, the spelling print catch
        // and the series preview the Renaissance armies overview (print 12)
    if (t22ArmiesFranklinLongbow() != 1
            || t22ArmiesStardioDragoon() != 1
            || t22ArmiesHussarLevy() != 1
            || t22ArmiesZiskaLaager() != 1
            || t22ArmiesMercenaryAge() != 1
            || t22ArmiesZiskaSpellingPrintCatch() != 1
            || t22ArmiesSwissNextTime() != 1
        )
            ++bad;
        // the composition spot check - the pike band and the cavalry floor
        // against the halberd ceiling the Swiss military doctrine (print
        // 8-11)
    if (t22SwissCompMin(2) != 10
            || t22SwissCompMax(2) != 65
            || t22SwissCompMin(5) != 0
            || t22SwissCompMax(0) != 60
        )
            ++bad;
        printf("R946 issue-22 opener part one audit: bad %d\n", bad);
        if (bad) return 1;
    }
