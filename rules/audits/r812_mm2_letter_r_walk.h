    // ---- R812 MM2 letter R walk audit ----
    // THE MM2 LETTER R WALK - the ordinary rat and the vapor rat p. 105, the
    // raven (crow) variant table p. 105 (the ordinary, huge and giant
    // columns), the retch plant and the rock reptile p. 106; the R-FLIP
    // round: the Letter R gap box flips to closed (23 closed, 14 open). SEVEN
    // .lua defs ride the R791 data_files extension, registry 726 -> 733. The
    // RStats 7x10 grid cross-checks every armor class, hit dice, bonus,
    // avgHp, attack, xp, xp/hp, lair, move and magic-resistance cell; the
    // per-def doctrine pins carry the settled reads (the ordinary rat and the
    // ordinary raven 1/4 hit dice the flat-hp path reads - hdNum 0, avgHp 2,
    // the ikiryo precedent; the huge raven 1-1 the hdNum 1 bonus -1 read -
    // the buckawn precedent; the retch plant 5-8 the first-number 5 read -
    // the quickwood precedent; the rock reptile the M-row V/400+7 xp with the
    // L-row VI/600+9 riding as consts; the ordinary raven I/Nil the Nil-xp
    // read - the phantom precedent; the vapor rat 6 (or special) armor class
    // and 12/6/1 move the verbatim print cells; every Standard magic
    // resistance 0 - the R155 class); the R812b repair note: the first cut
    // carried the lair cells verbatim as 30%/25%/15%/10% and the preflight
    // walked them bad 5 (the loader luaGetInt is a lua_isnumber-only coercer
    // - a percent string reads 0), the bare-numeral read now pinned - the
    // R639 repair flow, nothing landed, the same round number re-issued
    {
        using namespace rules;
        int bad = 0;
    if (mm2rRound() != 812
            || mm2rRegistryBefore() != 726
            || mm2rRegistryAfter() != 733
            || mm2rDefCount() != 7
            || mm2rEntryCount() != 4
            || mm2rStatBlockHeadings() != 7
            || mm2rDoctrineHeads() != 0
            || mm2rLetterRHeadings() != 4
            || mm2rRStatRows() != 7
            || mm2rGapClosed() != 23
            || mm2rGapOpen() != 14
            || mm2rPriorOwnedEntries() != 0
            || mm2rRatOrdinaryXpValue() != 4
            || mm2rRatOrdinaryXpLevel() != 1
            || mm2rRatVaporXpValue() != 66
            || mm2rRatVaporXpLevel() != 2
            || mm2rRavenOrdinaryXpValue() != 0
            || mm2rRavenOrdinaryXpLevel() != 1
            || mm2rRavenHugeXpValue() != 32
            || mm2rRavenHugeXpLevel() != 2
            || mm2rRavenGiantXpValue() != 108
            || mm2rRavenGiantXpLevel() != 3
            || mm2rRetchPlantXpValue() != 252
            || mm2rRetchPlantXpLevel() != 3
            || mm2rRockReptileXpValue() != 519
            || mm2rRockReptileXpLevel() != 5
            || mm2rRockReptileLargeXpBase() != 600
            || mm2rRockReptileLargeXpPerHp() != 9
            || mm2rRockReptileLargeXpValue() != 753
            || mm2rRockReptileLargeXpLevel() != 6
            || mm2rRatOrdinaryDiseasePct() != 5
            || mm2rRatVaporLairTreasurePct() != 25
            || mm2rRatVaporGasReachFeetMin() != 5
            || mm2rRatVaporGasReachFeetMax() != 8
            || mm2rRavenEyeAttackPct() != 10
            || mm2rRavenNestTreasurePct() != 25
            || mm2rRavenNestQChanceIn6() != 6
            || mm2rRavenNestGemBaseGp() != 10
            || mm2rRavenCommonWords() != 100
            || mm2rRetchGlobesMin() != 5
            || mm2rRetchGlobesMax() != 8
            || mm2rRetchSplashRadiusFeet() != 5
            || mm2rRetchSplashContactPct() != 25
            || mm2rRetchSplashContactFeetMin() != 5
            || mm2rRetchSplashContactFeetMax() != 9
            || mm2rRetchRetchingRounds() != 3
            || mm2rRetchWeaknessTurns() != 6
            || mm2rRetchWeaknessPct() != 50
            || mm2rRetchOdorRadiusFeet() != 50
            || mm2rRetchOdorHoursMin() != 1
            || mm2rRetchOdorHoursMax() != 4
            || mm2rRetchWalkUnderDropPct() != 20
            || mm2rRetchContactGlobesMin() != 2
            || mm2rRetchContactGlobesMax() != 5
            || mm2rRockReptileLengthFeetMin() != 5
            || mm2rRockReptileLengthFeetMax() != 12
            || mm2rRockReptileSurpriseMin() != 1
            || mm2rRockReptileSurpriseMax() != 3
            || mm2rRockReptileRushSpeedMultiplier() != 2
            || mm2rRockReptileDamageMin() != 1
            || mm2rRockReptileDamageMax() != 4
            || mm2rRockReptileDamagePerFoot() != 1
            || mm2rRockReptileLairTreasurePct() != 25
            || !mm2rRatOrdinaryFightWhenCornered()
            || !mm2rRatOrdinaryStarvingPackAttacks()
            || !mm2rRatOrdinaryFearFire()
            || !mm2rRatVaporGaseousForm()
            || !mm2rRatVaporStingingCloudRelease()
            || !mm2rRavenNeverSurprisedInLight()
            || !mm2rRavenScoutsGiveWarning()
            || !mm2rRavenLoveGlitteringObjects()
            || !mm2rRavenGiantEasilyTrained()
            || !mm2rRavenHugeServeEvilMasters()
            || !mm2rRetchNoSavingThrow()
            || !mm2rRetchCarnivoreAttractionDouble()
            || !mm2rRockReptileChameleonPowers()
            || !mm2rRockReptileFavorsDarkness()
            || !mm2rRockReptilePairDoubleMetalGems()
        )
            ++bad;
        // THE R-GRID: the 7-row RStats stat grid (every armor class,
        // hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the seven letter R stat blocks, in print
        // order - the ordinary rat and the vapor rat p. 105, the raven (crow)
        // variant table p. 105 (the ordinary, huge and giant columns), the
        // retch plant and the rock reptile p. 106)
        int CRStats[7][10] = {
            {7,0,0,2,1,2,1,0,15,0},
            {6,2,0,7,1,52,2,30,12,0},
            {7,0,0,2,1,0,0,25,1,0},
            {6,1,-1,2,1,30,1,15,1,0},
            {4,3,2,12,1,60,4,10,3,0},
            {8,5,0,17,1,150,6,0,0,0},
            {3,5,0,17,1,400,7,30,6,0},
            };
        for (int b = 0;
             b < mm2rRStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2rRStatAc(b);
            vals[1] = mm2rRStatHd(b);
            vals[2] = mm2rRStatHdBonus(b);
            vals[3] = mm2rRStatAvgHp(b);
            vals[4] = mm2rRStatAttacks(b);
            vals[5] = mm2rRStatXp(b);
            vals[6] = mm2rRStatXpHp(b);
            vals[7] = mm2rRStatLairPct(b);
            vals[8] = mm2rRStatMove(b);
            vals[9] = mm2rRStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CRStats[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count and the Letter R gap
        // box flips (the census walk)
    if (mm2rRegistryAfter() - mm2rRegistryBefore() != mm2rDefCount()
            || mm2rDefCount() != 7
            || mm2rEntryCount() != 4
            || mm2rStatBlockHeadings() != 7
            || mm2rDoctrineHeads() != 0
            || mm2rLetterRHeadings() != 4
            || mm2rRStatRows() != 7
            || mm2rGapClosed() != 23
            || mm2rGapOpen() != 14
            || mm2rPriorOwnedEntries() != 0
        )
            ++bad;
        // the ordinary rat grid row (p. 105 print order)
    if (mm2rRStatAc(0) != 7
            || mm2rRStatHd(0) != 0
            || mm2rRStatHdBonus(0) != 0
            || mm2rRStatAvgHp(0) != 2
            || mm2rRStatAttacks(0) != 1
            || mm2rRStatXp(0) != 2
            || mm2rRStatXpHp(0) != 1
            || mm2rRStatLairPct(0) != 0
            || mm2rRStatMove(0) != 15
            || mm2rRStatMr(0) != 0
            || mm2rRatOrdinaryXpValue() != 4
            || mm2rRatOrdinaryXpLevel() != 1
        )
            ++bad;
        // the vapor rat grid row (p. 105 print order)
    if (mm2rRStatAc(1) != 6
            || mm2rRStatHd(1) != 2
            || mm2rRStatHdBonus(1) != 0
            || mm2rRStatAvgHp(1) != 7
            || mm2rRStatAttacks(1) != 1
            || mm2rRStatXp(1) != 52
            || mm2rRStatXpHp(1) != 2
            || mm2rRStatLairPct(1) != 30
            || mm2rRStatMove(1) != 12
            || mm2rRStatMr(1) != 0
            || mm2rRatVaporXpValue() != 66
            || mm2rRatVaporXpLevel() != 2
        )
            ++bad;
        // the ordinary raven (crow) grid row (p. 105 print order)
    if (mm2rRStatAc(2) != 7
            || mm2rRStatHd(2) != 0
            || mm2rRStatHdBonus(2) != 0
            || mm2rRStatAvgHp(2) != 2
            || mm2rRStatAttacks(2) != 1
            || mm2rRStatXp(2) != 0
            || mm2rRStatXpHp(2) != 0
            || mm2rRStatLairPct(2) != 25
            || mm2rRStatMove(2) != 1
            || mm2rRStatMr(2) != 0
            || mm2rRavenOrdinaryXpValue() != 0
            || mm2rRavenOrdinaryXpLevel() != 1
        )
            ++bad;
        // the huge raven (crow) grid row (p. 105 print order)
    if (mm2rRStatAc(3) != 6
            || mm2rRStatHd(3) != 1
            || mm2rRStatHdBonus(3) != -1
            || mm2rRStatAvgHp(3) != 2
            || mm2rRStatAttacks(3) != 1
            || mm2rRStatXp(3) != 30
            || mm2rRStatXpHp(3) != 1
            || mm2rRStatLairPct(3) != 15
            || mm2rRStatMove(3) != 1
            || mm2rRStatMr(3) != 0
            || mm2rRavenHugeXpValue() != 32
            || mm2rRavenHugeXpLevel() != 2
        )
            ++bad;
        // the giant raven (crow) grid row (p. 105 print order)
    if (mm2rRStatAc(4) != 4
            || mm2rRStatHd(4) != 3
            || mm2rRStatHdBonus(4) != 2
            || mm2rRStatAvgHp(4) != 12
            || mm2rRStatAttacks(4) != 1
            || mm2rRStatXp(4) != 60
            || mm2rRStatXpHp(4) != 4
            || mm2rRStatLairPct(4) != 10
            || mm2rRStatMove(4) != 3
            || mm2rRStatMr(4) != 0
            || mm2rRavenGiantXpValue() != 108
            || mm2rRavenGiantXpLevel() != 3
        )
            ++bad;
        // the retch plant grid row (p. 106 print order)
    if (mm2rRStatAc(5) != 8
            || mm2rRStatHd(5) != 5
            || mm2rRStatHdBonus(5) != 0
            || mm2rRStatAvgHp(5) != 17
            || mm2rRStatAttacks(5) != 1
            || mm2rRStatXp(5) != 150
            || mm2rRStatXpHp(5) != 6
            || mm2rRStatLairPct(5) != 0
            || mm2rRStatMove(5) != 0
            || mm2rRStatMr(5) != 0
            || mm2rRetchPlantXpValue() != 252
            || mm2rRetchPlantXpLevel() != 3
        )
            ++bad;
        // the rock reptile grid row (p. 106 print order, the M read)
    if (mm2rRStatAc(6) != 3
            || mm2rRStatHd(6) != 5
            || mm2rRStatHdBonus(6) != 0
            || mm2rRStatAvgHp(6) != 17
            || mm2rRStatAttacks(6) != 1
            || mm2rRStatXp(6) != 400
            || mm2rRStatXpHp(6) != 7
            || mm2rRStatLairPct(6) != 30
            || mm2rRStatMove(6) != 6
            || mm2rRStatMr(6) != 0
            || mm2rRockReptileXpValue() != 519
            || mm2rRockReptileXpLevel() != 5
            || mm2rRockReptileLargeXpValue() != 753
            || mm2rRockReptileLargeXpLevel() != 6
            || mm2rRockReptileLargeXpBase() != 600
            || mm2rRockReptileLargeXpPerHp() != 9
        )
            ++bad;
        // the raven variant table shares one prose block across its three
        // columns (the pedipalp precedent)
    if (mm2rRavenEyeAttackPct() != 10
            || mm2rRavenNestTreasurePct() != 25
            || mm2rRavenNestQChanceIn6() != 6
            || mm2rRavenNestGemBaseGp() != 10
            || mm2rRavenCommonWords() != 100
        )
            ++bad;
        printf("R812 MM2 letter R walk audit: bad %d\n", bad);
        if (bad) return 1;
    }
