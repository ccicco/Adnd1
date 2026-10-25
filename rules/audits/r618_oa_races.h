    // ---- R618 OA races audit ----
    // OA round five (capture pp. 17-22): the three nonhuman races - the
    // korobokuru save ladders and ability modifications, the hengeyokai form
    // doctrine with the Table 11 twelve-creature grid, and the three spirit
    // folk powers with their life-force ties.
    {
        using namespace rules;
        int bad = 0;
    if (dgeKoroClasses() != 4
            || dgeKoroSaveDivisor() != 2
            || dgeKoroInfravision() != 120
            || dgeKoroPlantIdPct() != 66
            || dgeKoroStrAdj() != 1
            || dgeKoroConAdj() != 1
            || dgeKoroIntAdj() != -2
            || dgeHengeClasses() != 4
            || dgeHengeFormCount() != 12
            || dgeHengeFormsPerDay() != 1
            || dgeHengeAnimalHpHalved() != 2
            || dgeT11RowCount() != 12
            || dgeT11NoDamage() != 0
            || dgeT11NoMove() != 0
            || dgeT11AlignGood() != 1
            || dgeT11AlignChaotic() != 2
            || dgeT11AlignAny() != 3
            || dgeT11AlignEvil() != 4
            || dgeSpiritClasses() != 3
            || dgeBambooPlantPct() != 75
            || dgeBambooAnimalPct() != 50
            || dgeBambooHidePct() != 75
            || dgeRiverLowerWaterFeet() != 10
            || dgeRiverLowerWaterRounds() != 5
            || dgeSeaWeatherPct() != 75
            || dgeSeaWeatherHours() != 24
            || dgeSeaFavorsPerYear() != 1
            || dgeSeaGiftHonor() != 85
            || !dgeKoroBarbarianCommon()
            || !dgeKoroSamuraiSponsored()
            || !dgeKoroSavePoisonToo()
            || !dgeKoroGoblinBonus()
            || !dgeKoroGiantPenalty()
            || !dgeKoroSizeLimits()
            || !dgeKoroLanguages()
            || !dgeKoroScoreBounds()
            || !dgeKoroFamilyRequired()
            || !dgeHengeNotLycanthrope()
            || !dgeHengeChangeRound()
            || !dgeHengeScoresUnchanged()
            || !dgeHengeAnimalReal()
            || !dgeHengeAnimalInfravision()
            || !dgeHengeAnimalNoGear()
            || !dgeHengeBipedalFull()
            || !dgeHengeHumanFull()
            || !dgeHengeNoClan()
            || !dgeHengeProtector()
            || !dgeSpiritFamilyRequired()
            || !dgeSpiritLordSummon()
            || !dgeBambooTrail()
            || !dgeBambooLanguagePerLevel()
            || !dgeBambooSaveBonus()
            || !dgeBambooGrove()
            || !dgeRiverBreatheSwim()
            || !dgeRiverSaveBonus()
            || !dgeRiverLanguages()
            || !dgeRiverLifeForce()
            || !dgeSeaBreatheSwim()
            || !dgeSeaSaveBonus()
            || !dgeSeaNoSeaTie()
        )
            ++bad;
        // the Table 11 grid: alignment tiers, damage dice, animal AC, the
        // move/fly/swim rates and the ability modifications across the twelve
        // forms (capture p. 18)
        int CT11[12][10] = {
            {1,0,7,0,0,12,1,2,-1,0},
            {2,3,9,12,0,0,1,1,-1,2},
            {3,3,8,3,0,6,2,0,-2,4},
            {1,2,9,6,12,0,1,2,-1,1},
            {1,6,9,12,0,0,1,3,-1,3},
            {1,0,7,6,12,9,1,4,-1,1},
            {4,3,6,15,0,0,1,3,-1,2},
            {1,0,5,18,0,0,1,2,-1,0},
            {2,0,6,12,0,0,2,1,-2,2},
            {4,6,9,9,0,0,2,0,-2,2},
            {4,3,5,9,0,0,2,3,-2,4},
            {1,0,3,3,15,0,2,4,-2,3},
            };
        for (int b = 0;
             b < dgeT11RowCount();
             ++b) {
            int vals[10];
            vals[0] = dgeT11Align(b);
            vals[1] = dgeT11DmgDie(b);
            vals[2] = dgeT11Ac(b);
            vals[3] = dgeT11Move(b);
            vals[4] = dgeT11Fly(b);
            vals[5] = dgeT11Swim(b);
            vals[6] = dgeT11Plus(b);
            vals[7] = dgeT11PlusAb(b);
            vals[8] = dgeT11Minus(b);
            vals[9] = dgeT11MinusAb(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CT11[b][c])
                    ++bad;
            }
        }
        // the dgeKoroClasses pin
    if (dgeKoroClasses() != 4
        )
            ++bad;
        // the dgeKoroBarbarianCommon pin
    if (dgeKoroBarbarianCommon() != 1
        )
            ++bad;
        // the dgeKoroSamuraiSponsored pin
    if (dgeKoroSamuraiSponsored() != 1
        )
            ++bad;
        // the dgeKoroSaveDivisor pin
    if (dgeKoroSaveDivisor() != 2
        )
            ++bad;
        // the dgeKoroSavePoisonToo pin
    if (dgeKoroSavePoisonToo() != 1
        )
            ++bad;
        // the dgeKoroInfravision pin
    if (dgeKoroInfravision() != 120
        )
            ++bad;
        // the dgeKoroPlantIdPct pin
    if (dgeKoroPlantIdPct() != 66
        )
            ++bad;
        // the dgeKoroGoblinBonus pin
    if (dgeKoroGoblinBonus() != 1
        )
            ++bad;
        // the dgeKoroGiantPenalty pin
    if (dgeKoroGiantPenalty() != 1
        )
            ++bad;
        // the dgeKoroSizeLimits pin
    if (dgeKoroSizeLimits() != 1
        )
            ++bad;
        // the dgeKoroLanguages pin
    if (dgeKoroLanguages() != 1
        )
            ++bad;
        // the dgeKoroStrAdj pin
    if (dgeKoroStrAdj() != 1
        )
            ++bad;
        // the dgeKoroConAdj pin
    if (dgeKoroConAdj() != 1
        )
            ++bad;
        // the dgeKoroIntAdj pin
    if (dgeKoroIntAdj() != -2
        )
            ++bad;
        // the dgeKoroScoreBounds pin
    if (dgeKoroScoreBounds() != 1
        )
            ++bad;
        // the dgeKoroFamilyRequired pin
    if (dgeKoroFamilyRequired() != 1
        )
            ++bad;
        // the dgeHengeNotLycanthrope pin
    if (dgeHengeNotLycanthrope() != 1
        )
            ++bad;
        // the dgeHengeClasses pin
    if (dgeHengeClasses() != 4
        )
            ++bad;
        // the dgeHengeFormCount pin
    if (dgeHengeFormCount() != 12
        )
            ++bad;
        // the dgeHengeFormsPerDay pin
    if (dgeHengeFormsPerDay() != 1
        )
            ++bad;
        // the dgeHengeChangeRound pin
    if (dgeHengeChangeRound() != 1
        )
            ++bad;
        // the dgeHengeScoresUnchanged pin
    if (dgeHengeScoresUnchanged() != 1
        )
            ++bad;
        // the dgeHengeAnimalReal pin
    if (dgeHengeAnimalReal() != 1
        )
            ++bad;
        // the dgeHengeAnimalInfravision pin
    if (dgeHengeAnimalInfravision() != 1
        )
            ++bad;
        // the dgeHengeAnimalNoGear pin
    if (dgeHengeAnimalNoGear() != 1
        )
            ++bad;
        // the dgeHengeAnimalHpHalved pin
    if (dgeHengeAnimalHpHalved() != 2
        )
            ++bad;
        // the dgeHengeBipedalFull pin
    if (dgeHengeBipedalFull() != 1
        )
            ++bad;
        // the dgeHengeHumanFull pin
    if (dgeHengeHumanFull() != 1
        )
            ++bad;
        // the dgeHengeNoClan pin
    if (dgeHengeNoClan() != 1
        )
            ++bad;
        // the dgeHengeProtector pin
    if (dgeHengeProtector() != 1
        )
            ++bad;
        // the dgeT11RowCount pin
    if (dgeT11RowCount() != 12
        )
            ++bad;
        // the dgeT11NoDamage pin
    if (dgeT11NoDamage() != 0
        )
            ++bad;
        // the dgeT11NoMove pin
    if (dgeT11NoMove() != 0
        )
            ++bad;
        // the dgeT11AlignGood pin
    if (dgeT11AlignGood() != 1
        )
            ++bad;
        // the dgeT11AlignChaotic pin
    if (dgeT11AlignChaotic() != 2
        )
            ++bad;
        // the dgeT11AlignAny pin
    if (dgeT11AlignAny() != 3
        )
            ++bad;
        // the dgeT11AlignEvil pin
    if (dgeT11AlignEvil() != 4
        )
            ++bad;
        // the dgeSpiritClasses pin
    if (dgeSpiritClasses() != 3
        )
            ++bad;
        // the dgeSpiritFamilyRequired pin
    if (dgeSpiritFamilyRequired() != 1
        )
            ++bad;
        // the dgeSpiritLordSummon pin
    if (dgeSpiritLordSummon() != 1
        )
            ++bad;
        // the dgeBambooPlantPct pin
    if (dgeBambooPlantPct() != 75
        )
            ++bad;
        // the dgeBambooAnimalPct pin
    if (dgeBambooAnimalPct() != 50
        )
            ++bad;
        // the dgeBambooTrail pin
    if (dgeBambooTrail() != 1
        )
            ++bad;
        // the dgeBambooHidePct pin
    if (dgeBambooHidePct() != 75
        )
            ++bad;
        // the dgeBambooLanguagePerLevel pin
    if (dgeBambooLanguagePerLevel() != 1
        )
            ++bad;
        // the dgeBambooSaveBonus pin
    if (dgeBambooSaveBonus() != 1
        )
            ++bad;
        // the dgeBambooGrove pin
    if (dgeBambooGrove() != 1
        )
            ++bad;
        // the dgeRiverBreatheSwim pin
    if (dgeRiverBreatheSwim() != 1
        )
            ++bad;
        // the dgeRiverLowerWaterFeet pin
    if (dgeRiverLowerWaterFeet() != 10
        )
            ++bad;
        // the dgeRiverLowerWaterRounds pin
    if (dgeRiverLowerWaterRounds() != 5
        )
            ++bad;
        // the dgeRiverSaveBonus pin
    if (dgeRiverSaveBonus() != 1
        )
            ++bad;
        // the dgeRiverLanguages pin
    if (dgeRiverLanguages() != 1
        )
            ++bad;
        // the dgeRiverLifeForce pin
    if (dgeRiverLifeForce() != 1
        )
            ++bad;
        // the dgeSeaBreatheSwim pin
    if (dgeSeaBreatheSwim() != 1
        )
            ++bad;
        // the dgeSeaWeatherPct pin
    if (dgeSeaWeatherPct() != 75
        )
            ++bad;
        // the dgeSeaWeatherHours pin
    if (dgeSeaWeatherHours() != 24
        )
            ++bad;
        // the dgeSeaSaveBonus pin
    if (dgeSeaSaveBonus() != 1
        )
            ++bad;
        // the dgeSeaNoSeaTie pin
    if (dgeSeaNoSeaTie() != 1
        )
            ++bad;
        // the dgeSeaFavorsPerYear pin
    if (dgeSeaFavorsPerYear() != 1
        )
            ++bad;
        // the dgeSeaGiftHonor pin
    if (dgeSeaGiftHonor() != 85
        )
            ++bad;
        // the carp cannot cross land but swims 12 (capture p. 18)
    if (dgeT11Move(0) != 0
            || dgeT11Swim(0) != 12
        )
            ++bad;
        // the hare is the fastest land form at 18 (capture p. 18)
    if (dgeT11Move(7) != 18
        )
            ++bad;
        // the sparrow flies 15 and has AC 3 (capture p. 18)
    if (dgeT11Fly(11) != 15
            || dgeT11Ac(11) != 3
        )
            ++bad;
        // the crab takes any alignment (capture p. 18)
    if (dgeT11Align(2) != 3
        )
            ++bad;
        // the dog damage is 1-6 (capture p. 18)
    if (dgeT11DmgDie(4) != 6
        )
            ++bad;
        // the korobokuru ability adjustments sum (capture p. 18)
    if (dgeKoroStrAdj() + dgeKoroConAdj() + dgeKoroIntAdj() != 0
        )
            ++bad;
        // the hengeyokai change count equals the level (capture p. 19)
    if (dgeHengeFormsPerDay() != 1
        )
            ++bad;
        // the river lower-water pair (capture p. 21)
    if (dgeRiverLowerWaterFeet() != 10
            || dgeRiverLowerWaterRounds() != 5
        )
            ++bad;
        // the bamboo plant and hide chances both print 75 (capture p. 21)
    if (dgeBambooPlantPct() != dgeBambooHidePct()
        )
            ++bad;
        // the sea weather prediction window (capture p. 21)
    if (dgeSeaWeatherHours() != 24
        )
            ++bad;
        printf("R618 OA races audit: bad %d\n", bad);
        if (bad) return 1;
    }
