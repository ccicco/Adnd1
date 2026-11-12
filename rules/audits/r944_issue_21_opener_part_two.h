    // ---- R944 issue-21 opener part two audit ----
    // THE DRAGON ISSUE-21 OPENER PART TWO - the four-chain round of the
    // issue-21 three-round shape. Four chains pinned: the Callison gold-piece
    // inflation economics (the 1:1 dollar analogy, the 1-10 starting purse,
    // the Strategic Review Vol. II No. 2 Gygax reference), the Callison
    // natural-history monster doctrine (the never-both snakes, the live-prey
    // spiders, the solitary scorpions, the social ants), the Turnbull Hall of
    // Mystery do-it-yourself module (the five mirrors, the Excalibur dial,
    // the eight-room census) and the Blume M-U titles kit (the ten-column
    // chart against the seven-column prose walk). No watches moved: the
    // Sullin levels 7-9 and the brawling sequel still print nowhere and ride
    // to TD 22.
    {
        using namespace rules;
        int bad = 0;
    if (g21InflationGpDollarRatio() != 1
            || g21InflationGpDollarAltMin() != 5
            || g21InflationGpDollarAltMax() != 10
            || g21InflationNewbieGoldMin() != 1
            || g21InflationNewbieGoldMax() != 10
            || g21InflationStrategicReviewVol() != 2
            || g21InflationStrategicReviewNo() != 2
            || g21InflationPurpleDragonLevel() != 1
            || g21InflationPlusFiveSwords() != 1
            || g21InflationPlusFiveSpears() != 2
            || g21MonsterCentipedeAcMin() != 2
            || g21MonsterCentipedeAcMax() != 3
            || g21HallRooms() != 8
            || g21HallMirrors() != 5
            || g21HallMirrorSquareFeet() != 10
            || g21HallOrdinaryMirrors() != 3
            || g21HallCeilingFeet() != 45
            || g21HallLifeTrapDiameterFeet() != 6
            || g21HallCylinderHeightFeet() != 5
            || g21HallDialPositions() != 9
            || g21HallTeleportLimit() != 3
            || g21HallExcaliburSpeaks() != 3
            || g21HallTrapperCorridors() != 4
            || g21HallUmberHulks() != 2
            || g21HallLongCorridorGuards() != 2
            || g21HallShortCorridorGuards() != 1
            || g21HallAbsorberSourceIssue() != 12
            || g21HallAnecdotePaladinLevel() != 11
            || g21TitleKitChartColumns() != 10
            || g21TitleKitProseColumns() != 7
            || g21TitleKitRogorLevel() != 20
            || !g21InflationSpendForXpCritique()
            || !g21InflationSilverCopperRevived()
            || !g21InflationPlatinumElectrumCritique()
            || !g21InflationSmallIsBeautiful()
            || !g21InflationPeasantHundredsGp()
            || !g21InflationEptReference()
            || !g21InflationTypoPrintCatch()
            || !g21MonsterSnakeNeverBoth()
            || !g21MonsterSnakeColdBlooded()
            || !g21MonsterSnakeDeafVibration()
            || !g21MonsterSnakeCoilInitiative()
            || !g21MonsterSpiderLivePrey()
            || !g21MonsterSpiderSolitary()
            || !g21MonsterTrapdoorSurprise()
            || !g21MonsterScorpionSolitary()
            || !g21MonsterAntSocial()
            || !g21MonsterNoTypicalSpider()
            || !g21MonsterNaturalSource()
            || !g21MonsterEnvisionPrintCatch()
            || !g21HallMirrorAOpposition()
            || !g21HallMirrorCLifeTrap()
            || !g21HallMuslinSeals()
            || !g21HallPyrotechnicsHarmless()
            || !g21HallFourthDisplaced()
            || !g21HallPanelsSync()
            || !g21HallPointerNeutralReset()
            || !g21HallOtyuglSpellingPrintCatch()
            || !g21HallVersePrintCatch()
            || !g21TitleKitDeleteEmbellish()
            || !g21TitleKitWizardHeaderPrintCatch()
            || !g21TitleKitSpellingPrintCatch()
            || !g21TitleKitWhateverHeWants()
        )
            ++bad;
        // the Hall of Mystery room census - eight rooms around the Excalibur
        // dial, the four trapper corridors at i, iii, v and vii, and the
        // single printed hit-die count on the room iii Otyugl, the unprinted
        // rooms pinned 0, the conversion noted
        int CHm[8][3] = {
            {1,1,0},
            {2,0,0},
            {3,1,7},
            {4,0,0},
            {5,1,0},
            {6,0,0},
            {7,1,0},
            {8,0,0},
            };
        for (int b = 0;
             b < g21HallRooms();
             ++b) {
            int vals[3];
            vals[0] = g21HallRoomNumber(b);
            vals[1] = g21HallRoomTrapper(b);
            vals[2] = g21HallRoomPrintedHd(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CHm[b][c])
                    ++bad;
            }
        }
        // the gold-piece scale - the 1:1 dollar analogy, the 5-or-10 richer
        // alternate and the 1-10 starting purse the gold-piece inflation
        // doctrine (print 9)
    if (g21InflationGpDollarRatio() != 1
            || g21InflationGpDollarAltMin() != 5
            || g21InflationGpDollarAltMax() != 10
            || g21InflationNewbieGoldMin() != 1
            || g21InflationNewbieGoldMax() != 10
        )
            ++bad;
        // the reference and the anecdote - Strategic Review Vol. II No. 2,
        // and the 1st-level purple dragon with its plus-5 gifts the
        // gold-piece inflation doctrine (print 9)
    if (g21InflationStrategicReviewVol() != 2
            || g21InflationStrategicReviewNo() != 2
            || g21InflationPurpleDragonLevel() != 1
            || g21InflationPlusFiveSwords() != 1
            || g21InflationPlusFiveSpears() != 2
        )
            ++bad;
        // the doctrine bools - the spend-for-xp critique, the silver-copper
        // revival, the platinum-electrum critique, the small-is-beautiful
        // close, the peasant absurdity, the EPT reference and the typo print
        // catch the gold-piece inflation doctrine (print 9)
    if (g21InflationSpendForXpCritique() != 1
            || g21InflationSilverCopperRevived() != 1
            || g21InflationPlatinumElectrumCritique() != 1
            || g21InflationSmallIsBeautiful() != 1
            || g21InflationPeasantHundredsGp() != 1
            || g21InflationEptReference() != 1
            || g21InflationTypoPrintCatch() != 1
        )
            ++bad;
        // the serpent and centipede pins - the AC 2-3 exoskeleton, the
        // never-both snakes, the cold-blooded limit, the deaf-vibration
        // senses and the coil initiative the natural-history monster doctrine
        // (print 8)
    if (g21MonsterCentipedeAcMin() != 2
            || g21MonsterCentipedeAcMax() != 3
            || g21MonsterSnakeNeverBoth() != 1
            || g21MonsterSnakeColdBlooded() != 1
            || g21MonsterSnakeDeafVibration() != 1
            || g21MonsterSnakeCoilInitiative() != 1
        )
            ++bad;
        // the arthropod pins - the live-prey webs, the solitary spiders, the
        // trap-door surprise, the solitary scorpions and the social ants the
        // natural-history monster doctrine (print 8)
    if (g21MonsterSpiderLivePrey() != 1
            || g21MonsterSpiderSolitary() != 1
            || g21MonsterTrapdoorSurprise() != 1
            || g21MonsterScorpionSolitary() != 1
            || g21MonsterAntSocial() != 1
        )
            ++bad;
        // the doctrine and print catch - no typical giant spider, Mother
        // Nature as the source, the envision typo pinned as scanned the
        // natural-history monster doctrine (print 8)
    if (g21MonsterNoTypicalSpider() != 1
            || g21MonsterNaturalSource() != 1
            || g21MonsterEnvisionPrintCatch() != 1
        )
            ++bad;
        // the hall geometry - five 10-foot mirrors, three ordinary, the
        // 45-foot ceiling, the 6-foot life trap and the 5-foot cylinder the
        // Hall of Mystery do-it-yourself module (print 14-15)
    if (g21HallMirrors() != 5
            || g21HallMirrorSquareFeet() != 10
            || g21HallOrdinaryMirrors() != 3
            || g21HallCeilingFeet() != 45
            || g21HallLifeTrapDiameterFeet() != 6
            || g21HallCylinderHeightFeet() != 5
        )
            ++bad;
        // the dial pins - nine positions, the three-person teleport limit,
        // Excalibur thrice spoken, the four trapper corridors and the two
        // Umber Hulks the Hall of Mystery do-it-yourself module (print 14-15)
    if (g21HallDialPositions() != 9
            || g21HallTeleportLimit() != 3
            || g21HallExcaliburSpeaks() != 3
            || g21HallTrapperCorridors() != 4
            || g21HallUmberHulks() != 2
        )
            ++bad;
        // the corridor and credit pins - two guards on the long corridors,
        // one on the short, the Magic Absorbers from Alarums and Excursions
        // 12, and the 11th-level Paladin anecdote the Hall of Mystery
        // do-it-yourself module (print 14-15)
    if (g21HallLongCorridorGuards() != 2
            || g21HallShortCorridorGuards() != 1
            || g21HallAbsorberSourceIssue() != 12
            || g21HallAnecdotePaladinLevel() != 11
        )
            ++bad;
        // the hall doctrine bools - the opposition mirror a, the life-trap
        // mirror c, the muslin seal, the harmless pyrotechnics, the fourth
        // displaced clockwise, the synced panels, the neutral reset and the
        // two print catches the Hall of Mystery do-it-yourself module (print
        // 14-15)
    if (g21HallMirrorAOpposition() != 1
            || g21HallMirrorCLifeTrap() != 1
            || g21HallMuslinSeals() != 1
            || g21HallPyrotechnicsHarmless() != 1
            || g21HallFourthDisplaced() != 1
            || g21HallPanelsSync() != 1
            || g21HallPointerNeutralReset() != 1
            || g21HallOtyuglSpellingPrintCatch() != 1
            || g21HallVersePrintCatch() != 1
        )
            ++bad;
        // the kit census - the ten-column chart against the seven-column
        // prose walk, and the 20th-level Rogor example the M-U titles kit
        // (print 7)
    if (g21TitleKitChartColumns() != 10
            || g21TitleKitProseColumns() != 7
            || g21TitleKitRogorLevel() != 20
        )
            ++bad;
        // the kit doctrine bools - the delete-embellish customization, the
        // wizard header print catch, the six spelling print catches and the
        // standing answer the M-U titles kit (print 7)
    if (g21TitleKitDeleteEmbellish() != 1
            || g21TitleKitWizardHeaderPrintCatch() != 1
            || g21TitleKitSpellingPrintCatch() != 1
            || g21TitleKitWhateverHeWants() != 1
        )
            ++bad;
        // the room census spot check - the room iii Otyugl at 7 hit dice on a
        // trapper corridor, the room i Night Hag unprinted the Hall of
        // Mystery do-it-yourself module (print 14-15)
    if (g21HallRoomNumber(2) != 3
            || g21HallRoomTrapper(2) != 1
            || g21HallRoomPrintedHd(2) != 7
            || g21HallRoomTrapper(6) != 1
            || g21HallRoomPrintedHd(0) != 0
        )
            ++bad;
        printf("R944 issue-21 opener part two audit: bad %d\n", bad);
        if (bad) return 1;
    }
