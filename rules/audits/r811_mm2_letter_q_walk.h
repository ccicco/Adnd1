    // ---- R811 MM2 letter Q walk audit ----
    // THE MM2 LETTER Q WALK - the quasi-elemental lightning and the quickling
    // p. 103 (the quickling prose onto p. 104), the quickwood (spy tree) p.
    // 104; the Q-FLIP round: the Letter Q gap box flips to closed (22 closed,
    // 15 open). THREE .lua defs ride the R791 data_files extension, registry
    // 723 -> 726. The QStats 3x10 grid cross-checks every armor class, hit
    // dice, bonus, avgHp, attack, xp, xp/hp, lair, move and magic-resistance
    // cell; the per-def doctrine pins carry the settled reads (the
    // quasi-elemental 6, 9, or 12 first-number read, the quickling 1-1/2 the
    // ASCII settle of the print half-glyph with the half die reading +2 hp on
    // the quarter-die scale, the quickwood 5-10 (5 hp/die) flat 5-per-die
    // avgHp 25 read, the quickling save-as matrix II.C note reading 0 magic
    // resistance - the R155 class, the quickwood Special attacks floored at
    // 1, the quickling -3 armor class unquoted - the R806 hollyphant
    // precedent)
    {
        using namespace rules;
        int bad = 0;
    if (mm2qRound() != 811
            || mm2qRegistryBefore() != 723
            || mm2qRegistryAfter() != 726
            || mm2qDefCount() != 3
            || mm2qEntryCount() != 3
            || mm2qStatBlockHeadings() != 3
            || mm2qDoctrineHeads() != 0
            || mm2qLetterQHeadings() != 3
            || mm2qQStatRows() != 3
            || mm2qGapClosed() != 22
            || mm2qGapOpen() != 15
            || mm2qPriorOwnedEntries() != 0
            || mm2qQuasiLightningXpValue() != 1315
            || mm2qQuasiLightningXpLevel() != 7
            || mm2qQuicklingXpValue() != 215
            || mm2qQuicklingXpLevel() != 4
            || mm2qQuickwoodXpValue() != 600
            || mm2qQuickwoodXpLevel() != 5
            || mm2qQuasiLightningSmallHd() != 6
            || mm2qQuasiLightningMidHd() != 9
            || mm2qQuasiLightningLargeHd() != 12
            || mm2qQuasiLightningPmpSmallPct() != 60
            || mm2qQuasiLightningPmpMidPct() != 30
            || mm2qQuasiLightningPmpLargePct() != 10
            || mm2qQuasiLightningPlaneSmallPct() != 10
            || mm2qQuasiLightningPlaneMidPct() != 30
            || mm2qQuasiLightningPlaneLargePct() != 60
            || mm2qQuasiLightningArcLeapInches() != 6
            || mm2qQuasiLightningArcMassGp() != 50
            || mm2qQuasiLightningBallTriggerFeet() != 5
            || mm2qQuasiLightningBallMassGp() != 2000
            || mm2qQuasiLightningBallDamageMin() != 1
            || mm2qQuasiLightningBallDamageMax() != 8
            || mm2qQuasiLightningBallRoundsMin() != 6
            || mm2qQuasiLightningBallRoundsMax() != 12
            || mm2qQuasiLightningConductionDamageMin() != 1
            || mm2qQuasiLightningConductionDamageMax() != 4
            || mm2qQuasiLightningWaterDamageMin() != 1
            || mm2qQuasiLightningWaterDamageMax() != 8
            || mm2qQuasiLightningRainDamagePerTenthInch() != 2
            || mm2qQuicklingThreeHdInGroup() != 1
            || mm2qQuicklingThreeHdInLargeGroup() != 2
            || mm2qQuicklingLeaderHdNum() != 4
            || mm2qQuicklingLeaderHdBonus() != 2
            || mm2qQuicklingLeaderPoisonPct() != 75
            || mm2qQuicklingVisibleMovingPct() != 90
            || mm2qQuicklingSaveAsClericLevel() != 19
            || mm2qQuicklingSpellLikePowers() != 6
            || mm2qQuicklingDexterity() != 18
            || mm2qQuicklingMatureYearsMin() != 1
            || mm2qQuicklingMatureYearsMax() != 2
            || mm2qQuicklingDeathYearsMin() != 12
            || mm2qQuicklingDeathYearsMax() != 15
            || mm2qQuickwoodFaceMissPct() != 90
            || mm2qQuickwoodFaceNoticeFeet() != 30
            || mm2qQuickwoodFaceConcealFeet() != 10
            || mm2qQuickwoodRootMoveInches() != 3
            || mm2qQuickwoodRootHp() != 10
            || mm2qQuickwoodRootSeverLimit() != 6
            || mm2qQuickwoodRootCountMin() != 7
            || mm2qQuickwoodRootCountMax() != 12
            || mm2qQuickwoodRootWeightLimitPounds() != 1000
            || mm2qQuickwoodRootRangeYards() != 30
            || mm2qQuickwoodHostsMin() != 2
            || mm2qQuickwoodHostsMax() != 8
            || mm2qQuickwoodControlRangeInches() != 36
            || mm2qQuickwoodInfravisionFeet() != 120
            || mm2qQuickwoodMawDamageMin() != 3
            || mm2qQuickwoodMawDamageMax() != 12
            || mm2qQuickwoodFearRadiusFeetPerLevel() != 10
            || mm2qQuickwoodDrumRangeMiles() != 1
            || !mm2qQuasiLightningWeaponFloorPlus1()
            || !mm2qQuasiLightningImmuneToLightning()
            || !mm2qQuasiLightningFireAcidHalfDamage()
            || !mm2qQuasiLightningColdFullDamage()
            || !mm2qQuasiLightningWaterDoubleDamage()
            || !mm2qQuasiLightningRarelyConjured()
            || !mm2qQuicklingNeverSurprised()
            || !mm2qQuicklingInvisibleInNaturalCover()
            || !mm2qQuicklingSeenOnlyAsBlur()
            || !mm2qQuicklingExcellentArmorClassFromSpeed()
            || !mm2qQuickwoodNeverSurprised()
            || !mm2qQuickwoodFireImmune()
            || !mm2qQuickwoodLightningChanneled()
            || !mm2qQuickwoodPoisonGasImmune()
            || !mm2qQuickwoodDisintegrateDestroys()
            || !mm2qQuickwoodMindAffectingImmune()
            || !mm2qQuickwoodPlantSpellsWork()
            || !mm2qQuickwoodRootsTooStrongToBreak()
        )
            ++bad;
        // THE Q-GRID: the 3-row QStats stat grid (every armor class,
        // hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the three letter Q stat blocks, in print
        // order - the quasi-elemental lightning through the quickwood)
        int CQStats[3][10] = {
            {2,6,0,21,1,1000,15,0,18,0},
            {-3,1,2,5,3,200,3,10,96,0},
            {5,5,0,25,1,350,10,100,1,0},
            };
        for (int b = 0;
             b < mm2qQStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2qQStatAc(b);
            vals[1] = mm2qQStatHd(b);
            vals[2] = mm2qQStatHdBonus(b);
            vals[3] = mm2qQStatAvgHp(b);
            vals[4] = mm2qQStatAttacks(b);
            vals[5] = mm2qQStatXp(b);
            vals[6] = mm2qQStatXpHp(b);
            vals[7] = mm2qQStatLairPct(b);
            vals[8] = mm2qQStatMove(b);
            vals[9] = mm2qQStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CQStats[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count and the Letter Q gap
        // box flips (the census walk)
    if (mm2qRegistryAfter() - mm2qRegistryBefore() != mm2qDefCount()
            || mm2qDefCount() != 3
            || mm2qEntryCount() != 3
            || mm2qStatBlockHeadings() != 3
            || mm2qDoctrineHeads() != 0
            || mm2qLetterQHeadings() != 3
            || mm2qQStatRows() != 3
            || mm2qGapClosed() != 22
            || mm2qGapOpen() != 15
            || mm2qPriorOwnedEntries() != 0
        )
            ++bad;
        // the quasi-elemental lightning grid row (pp. 103-104 print order)
    if (mm2qQStatAc(0) != 2
            || mm2qQStatHd(0) != 6
            || mm2qQStatHdBonus(0) != 0
            || mm2qQStatAvgHp(0) != 21
            || mm2qQStatAttacks(0) != 1
            || mm2qQStatXp(0) != 1000
            || mm2qQStatXpHp(0) != 15
            || mm2qQStatLairPct(0) != 0
            || mm2qQStatMove(0) != 18
            || mm2qQStatMr(0) != 0
            || mm2qQuasiLightningXpValue() != 1315
            || mm2qQuasiLightningXpLevel() != 7
        )
            ++bad;
        // the quickling grid row (pp. 103-104 print order)
    if (mm2qQStatAc(1) != -3
            || mm2qQStatHd(1) != 1
            || mm2qQStatHdBonus(1) != 2
            || mm2qQStatAvgHp(1) != 5
            || mm2qQStatAttacks(1) != 3
            || mm2qQStatXp(1) != 200
            || mm2qQStatXpHp(1) != 3
            || mm2qQStatLairPct(1) != 10
            || mm2qQStatMove(1) != 96
            || mm2qQStatMr(1) != 0
            || mm2qQuicklingXpValue() != 215
            || mm2qQuicklingXpLevel() != 4
        )
            ++bad;
        // the quickwood grid row (pp. 103-104 print order)
    if (mm2qQStatAc(2) != 5
            || mm2qQStatHd(2) != 5
            || mm2qQStatHdBonus(2) != 0
            || mm2qQStatAvgHp(2) != 25
            || mm2qQStatAttacks(2) != 1
            || mm2qQStatXp(2) != 350
            || mm2qQStatXpHp(2) != 10
            || mm2qQStatLairPct(2) != 100
            || mm2qQStatMove(2) != 1
            || mm2qQStatMr(2) != 0
            || mm2qQuickwoodXpValue() != 600
            || mm2qQuickwoodXpLevel() != 5
        )
            ++bad;
        // the xpValue formula (the base plus the per-hp times avgHp, every
        // def)
    if (mm2qQuasiLightningXpValue() != mm2qQStatXp(0) + mm2qQStatAvgHp(0) *
        mm2qQStatXpHp(0)
            || mm2qQuicklingXpValue() != mm2qQStatXp(1) + mm2qQStatAvgHp(1) *
            mm2qQStatXpHp(1)
            || mm2qQuickwoodXpValue() != mm2qQStatXp(2) + mm2qQStatAvgHp(2) *
            mm2qQStatXpHp(2)
        )
            ++bad;
        // the avgHp formula (the floor of 3.5 x hit dice plus bonus, the
        // 5-hp/die quickwood excluded - the doubling form so the expr
        // compiles as C++)
    if (mm2qQStatAvgHp(0) * 2 + mm2qQStatHd(0) % 2 != mm2qQStatHd(0) * 7 +
        mm2qQStatHdBonus(0) * 2
            || mm2qQStatAvgHp(1) * 2 + mm2qQStatHd(1) % 2 != mm2qQStatHd(1) *
            7 + mm2qQStatHdBonus(1) * 2
        )
            ++bad;
        // the loader attack semantics (the Special floor at 1, the
        // bare-numeral reads pass through)
    if (mm2qQStatAttacks(2) != 1
            || mm2qQStatAttacks(0) != 1
            || mm2qQStatAttacks(1) != 3
        )
            ++bad;
        printf("R811 MM2 letter Q walk audit: bad %d\n", bad);
        if (bad) return 1;
    }
