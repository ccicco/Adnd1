    // ---- R809 MM2 letter O walk audit ----
    // THE MM2 LETTER O WALK - the obliviax, the ogre aquatic (merrow) and the
    // oliphant on p. 96, the ophidian, the opinicus, the otter and the owl on
    // p. 97 (the owl prose runs onto p. 98); the O-FLIP round: the Letter O
    // gap box flips to closed (20 closed, 17 open). SEVEN .lua defs ride the
    // R791 data_files extension, registry 699 -> 706. The OStats 7x10 grid
    // cross-checks every armor class, hit dice, bonus, avgHp, attack, xp,
    // xp/hp, lair, move and magic-resistance cell; the per-def doctrine pins
    // carry the settled reads (the merrow scrags settle, the opinicus weal
    // settle, the flat-hp and 1-1 hit-dice reads, the brute and trained
    // variants, the loader max/sum/floor attack semantics).
    {
        using namespace rules;
        int bad = 0;
    if (mm2oRound() != 809
            || mm2oRegistryBefore() != 699
            || mm2oRegistryAfter() != 706
            || mm2oDefCount() != 7
            || mm2oEntryCount() != 7
            || mm2oStatBlockHeadings() != 7
            || mm2oDoctrineHeads() != 0
            || mm2oLetterOHeadings() != 7
            || mm2oOStatRows() != 7
            || mm2oGapClosed() != 20
            || mm2oGapOpen() != 17
            || mm2oPriorOwnedEntries() != 0
            || mm2oObliviaxXpValue() != 31
            || mm2oObliviaxXpLevel() != 2
            || mm2oObliviaxStealRadiusFeet() != 60
            || mm2oObliviaxStealWindowHours() != 24
            || mm2oObliviaxSickTurnsMin() != 3
            || mm2oObliviaxSickTurnsMax() != 18
            || mm2oObliviaxEatRounds() != 1
            || mm2oMerrowXpValue() != 220
            || mm2oMerrowXpLevel() != 2
            || mm2oMerrowBruteXpLevel() != 4
            || mm2oMerrowBruteXpBase() != 250
            || mm2oMerrowBruteXpPerHp() != 6
            || mm2oMerrowSurpriseOn6() != 4
            || mm2oMerrowChargeToHitBonus() != 1
            || mm2oMerrowSpearDamageMax() != 12
            || mm2oMerrowDepthMinFeet() != 50
            || mm2oMerrowDepthMaxFeet() != 250
            || mm2oMerrowHoursOutOfWater() != 2
            || mm2oMerrowChiefAc() != 3
            || mm2oMerrowChiefHd() != 6
            || mm2oMerrowChiefBonus() != 6
            || mm2oMerrowChiefDamageBonus() != 2
            || mm2oMerrowSubChiefCount() != 2
            || mm2oMerrowSubChiefAc() != 3
            || mm2oMerrowSubChiefHd() != 5
            || mm2oMerrowSubChiefBonus() != 5
            || mm2oMerrowSubChiefDamageBonus() != 1
            || mm2oMerrowFemaleAc() != 5
            || mm2oMerrowFemaleHd() != 3
            || mm2oMerrowFemaleBonus() != 3
            || mm2oMerrowYoungAc() != 6
            || mm2oMerrowYoungHd() != 2
            || mm2oMerrowYoungBonus() != 2
            || mm2oMerrowShamanCount() != 1
            || mm2oOliphantXpValue() != 984
            || mm2oOliphantXpLevel() != 4
            || mm2oOliphantTrainedHd() != 10
            || mm2oOliphantTrainedBonus() != 5
            || mm2oOliphantTuskValueMin() != 100
            || mm2oOliphantTuskValueMax() != 400
            || mm2oOliphantIvoryGpPerPound() != 4
            || mm2oOliphantCalfChance() != 25
            || mm2oOliphantHalfGrownChance() != 75
            || mm2oOliphantMatureMalesInGroup() != 1
            || mm2oOphidianXpValue() != 165
            || mm2oOphidianXpLevel() != 3
            || mm2oOphidianAfflictionDaysMin() != 2
            || mm2oOphidianAfflictionDaysMax() != 5
            || mm2oOphidianAfflictionDurationMin() != 8
            || mm2oOphidianAfflictionDurationMax() != 16
            || mm2oOphidianBiteDamageMax() != 3
            || mm2oOpinicusXpValue() != 2672
            || mm2oOpinicusXpLevel() != 7
            || mm2oOpinicusClericLevel() != 7
            || mm2oOpinicusHolyWordPerDay() != 1
            || mm2oOpinicusDimensionDoorPerDay() != 2
            || mm2oOpinicusHealPerDay() != 3
            || mm2oOpinicusGazeDamageMin() != 2
            || mm2oOpinicusGazeDamageMax() != 16
            || mm2oOpinicusGazeIntervalRounds() != 10
            || mm2oOpinicusHabitatSurpriseOn6() != 5
            || mm2oOpinicusElsewhereSurpriseOn6() != 3
            || mm2oOpinicusMinorDisciplinesMin() != 3
            || mm2oOpinicusMinorDisciplinesMax() != 5
            || mm2oOpinicusMajorDisciplinesMin() != 1
            || mm2oOpinicusMajorDisciplinesMax() != 2
            || mm2oOpinicusMoveGround() != 21
            || mm2oOpinicusMoveFly() != 30
            || mm2oOpinicusPsionicMin() != 205
            || mm2oOpinicusPsionicMax() != 250
            || mm2oOtterXpValue() != 7
            || mm2oOtterXpLevel() != 1
            || mm2oOtterSeaHd() != 1
            || mm2oOtterSeaBonus() != 1
            || mm2oOtterDamageMax() != 2
            || mm2oOtterSeaDamageMax() != 3
            || mm2oOwlXpValue() != 33
            || mm2oOwlXpLevel() != 2
            || mm2oOwlPlummetBonus() != 2
            || mm2oOwlPlummetMinFeet() != 50
            || mm2oOwlPreySurpriseOn6() != 5
            || mm2oOwlDaylightRoostSurpriseOn6() != 3
            || mm2oOwlWingspreadMinFeet() != 4
            || mm2oOwlWingspreadMaxFeet() != 5
            || !mm2oObliviaxMosslingCastsStolenSpells()
            || !mm2oObliviaxSaveGainsMemories()
            || !mm2oMerrowCamouflageInvisible()
            || !mm2oMerrowSpeaksOgre()
            || !mm2oOliphantNoFireFear()
            || !mm2oOliphantSingleAlwaysMale()
            || !mm2oOliphantTrainedEnginesOfDestruction()
            || !mm2oOphidianPoisonSaveOrAffliction()
            || !mm2oOphidianCureDiseasePrevents()
            || !mm2oOphidianKillsNonhumanoids()
            || !mm2oOphidianServesSpiritNagas()
            || !mm2oOpinicusNeverSurprised()
            || !mm2oOpinicusTurnsUndead()
            || !mm2oOpinicusGazeSaveHalves()
            || !mm2oOpinicusGazeAffectsLowerPlanes()
            || !mm2oOpinicusAstralEtherealTravel()
            || !mm2oOtterAttacksOnlyIfCornered()
            || !mm2oOwlPlummetDoubleDamage()
            || !mm2oOwlDoubleUltravision()
            || !mm2oOwlQuadrupleHearing()
            || !mm2oOwlSilentFlight()
            || !mm2oOwlNeverSurprisedInDark()
            || !mm2oOwlLairDaylightOnly()
        )
            ++bad;
        // THE O-GRID: the 7-row OStats stat grid (every armor class,
        // hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the seven letter O stat blocks, in print
        // order - the obliviax through the owl)
        int COStats[7][10] = {
            {10,0,0,1,1,30,1,100,0,0},
            {4,4,4,18,3,130,5,20,6,0},
            {4,8,4,32,4,600,12,0,15,0},
            {5,3,0,10,2,125,4,0,9,0},
            {-2,7,7,31,4,2300,12,10,21,35},
            {5,1,-1,2,1,5,1,20,12,0},
            {5,1,0,3,3,30,1,10,1,0},
            };
        for (int b = 0;
             b < mm2oOStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2oOStatAc(b);
            vals[1] = mm2oOStatHd(b);
            vals[2] = mm2oOStatHdBonus(b);
            vals[3] = mm2oOStatAvgHp(b);
            vals[4] = mm2oOStatAttacks(b);
            vals[5] = mm2oOStatXp(b);
            vals[6] = mm2oOStatXpHp(b);
            vals[7] = mm2oOStatLairPct(b);
            vals[8] = mm2oOStatMove(b);
            vals[9] = mm2oOStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != COStats[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count and the Letter O gap
        // box flips (the census walk)
    if (mm2oRegistryAfter() - mm2oRegistryBefore() != mm2oDefCount()
            || mm2oDefCount() != 7
            || mm2oEntryCount() != 7
            || mm2oStatBlockHeadings() != 7
            || mm2oDoctrineHeads() != 0
            || mm2oLetterOHeadings() != 7
            || mm2oOStatRows() != 7
            || mm2oGapClosed() != 20
            || mm2oGapOpen() != 17
            || mm2oPriorOwnedEntries() != 0
        )
            ++bad;
        // the obliviax grid row (pp. 96-97 print order)
    if (mm2oOStatAc(0) != 10
            || mm2oOStatHd(0) != 0
            || mm2oOStatHdBonus(0) != 0
            || mm2oOStatAvgHp(0) != 1
            || mm2oOStatAttacks(0) != 1
            || mm2oOStatXp(0) != 30
            || mm2oOStatXpHp(0) != 1
            || mm2oOStatLairPct(0) != 100
            || mm2oOStatMove(0) != 0
            || mm2oOStatMr(0) != 0
            || mm2oObliviaxXpValue() != 31
            || mm2oObliviaxXpLevel() != 2
        )
            ++bad;
        // the merrow grid row (pp. 96-97 print order)
    if (mm2oOStatAc(1) != 4
            || mm2oOStatHd(1) != 4
            || mm2oOStatHdBonus(1) != 4
            || mm2oOStatAvgHp(1) != 18
            || mm2oOStatAttacks(1) != 3
            || mm2oOStatXp(1) != 130
            || mm2oOStatXpHp(1) != 5
            || mm2oOStatLairPct(1) != 20
            || mm2oOStatMove(1) != 6
            || mm2oOStatMr(1) != 0
            || mm2oMerrowXpValue() != 220
            || mm2oMerrowXpLevel() != 2
        )
            ++bad;
        // the oliphant grid row (pp. 96-97 print order)
    if (mm2oOStatAc(2) != 4
            || mm2oOStatHd(2) != 8
            || mm2oOStatHdBonus(2) != 4
            || mm2oOStatAvgHp(2) != 32
            || mm2oOStatAttacks(2) != 4
            || mm2oOStatXp(2) != 600
            || mm2oOStatXpHp(2) != 12
            || mm2oOStatLairPct(2) != 0
            || mm2oOStatMove(2) != 15
            || mm2oOStatMr(2) != 0
            || mm2oOliphantXpValue() != 984
            || mm2oOliphantXpLevel() != 4
        )
            ++bad;
        // the ophidian grid row (pp. 96-97 print order)
    if (mm2oOStatAc(3) != 5
            || mm2oOStatHd(3) != 3
            || mm2oOStatHdBonus(3) != 0
            || mm2oOStatAvgHp(3) != 10
            || mm2oOStatAttacks(3) != 2
            || mm2oOStatXp(3) != 125
            || mm2oOStatXpHp(3) != 4
            || mm2oOStatLairPct(3) != 0
            || mm2oOStatMove(3) != 9
            || mm2oOStatMr(3) != 0
            || mm2oOphidianXpValue() != 165
            || mm2oOphidianXpLevel() != 3
        )
            ++bad;
        // the opinicus grid row (pp. 96-97 print order)
    if (mm2oOStatAc(4) != -2
            || mm2oOStatHd(4) != 7
            || mm2oOStatHdBonus(4) != 7
            || mm2oOStatAvgHp(4) != 31
            || mm2oOStatAttacks(4) != 4
            || mm2oOStatXp(4) != 2300
            || mm2oOStatXpHp(4) != 12
            || mm2oOStatLairPct(4) != 10
            || mm2oOStatMove(4) != 21
            || mm2oOStatMr(4) != 35
            || mm2oOpinicusXpValue() != 2672
            || mm2oOpinicusXpLevel() != 7
        )
            ++bad;
        // the otter grid row (pp. 96-97 print order)
    if (mm2oOStatAc(5) != 5
            || mm2oOStatHd(5) != 1
            || mm2oOStatHdBonus(5) != -1
            || mm2oOStatAvgHp(5) != 2
            || mm2oOStatAttacks(5) != 1
            || mm2oOStatXp(5) != 5
            || mm2oOStatXpHp(5) != 1
            || mm2oOStatLairPct(5) != 20
            || mm2oOStatMove(5) != 12
            || mm2oOStatMr(5) != 0
            || mm2oOtterXpValue() != 7
            || mm2oOtterXpLevel() != 1
        )
            ++bad;
        // the owl grid row (pp. 96-97 print order)
    if (mm2oOStatAc(6) != 5
            || mm2oOStatHd(6) != 1
            || mm2oOStatHdBonus(6) != 0
            || mm2oOStatAvgHp(6) != 3
            || mm2oOStatAttacks(6) != 3
            || mm2oOStatXp(6) != 30
            || mm2oOStatXpHp(6) != 1
            || mm2oOStatLairPct(6) != 10
            || mm2oOStatMove(6) != 1
            || mm2oOStatMr(6) != 0
            || mm2oOwlXpValue() != 33
            || mm2oOwlXpLevel() != 2
        )
            ++bad;
        // the xpValue formula (the base plus the per-hp times avgHp, every
        // def)
    if (mm2oObliviaxXpValue() != mm2oOStatXp(0) + mm2oOStatAvgHp(0) *
        mm2oOStatXpHp(0)
            || mm2oMerrowXpValue() != mm2oOStatXp(1) + mm2oOStatAvgHp(1) *
            mm2oOStatXpHp(1)
            || mm2oOliphantXpValue() != mm2oOStatXp(2) + mm2oOStatAvgHp(2) *
            mm2oOStatXpHp(2)
            || mm2oOphidianXpValue() != mm2oOStatXp(3) + mm2oOStatAvgHp(3) *
            mm2oOStatXpHp(3)
            || mm2oOpinicusXpValue() != mm2oOStatXp(4) + mm2oOStatAvgHp(4) *
            mm2oOStatXpHp(4)
            || mm2oOtterXpValue() != mm2oOStatXp(5) + mm2oOStatAvgHp(5) *
            mm2oOStatXpHp(5)
            || mm2oOwlXpValue() != mm2oOStatXp(6) + mm2oOStatAvgHp(6) *
            mm2oOStatXpHp(6)
        )
            ++bad;
        // the avgHp formula (the floor of 3.5 x hit dice plus bonus, the
        // flat-hp obliviax excluded - the doubling form so the expr compiles
        // as C++)
    if (mm2oOStatAvgHp(1) * 2 + mm2oOStatHd(1) % 2 != mm2oOStatHd(1) * 7 +
        mm2oOStatHdBonus(1) * 2
            || mm2oOStatAvgHp(2) * 2 + mm2oOStatHd(2) % 2 != mm2oOStatHd(2) *
            7 + mm2oOStatHdBonus(2) * 2
            || mm2oOStatAvgHp(3) * 2 + mm2oOStatHd(3) % 2 != mm2oOStatHd(3) *
            7 + mm2oOStatHdBonus(3) * 2
            || mm2oOStatAvgHp(4) * 2 + mm2oOStatHd(4) % 2 != mm2oOStatHd(4) *
            7 + mm2oOStatHdBonus(4) * 2
            || mm2oOStatAvgHp(5) * 2 + mm2oOStatHd(5) % 2 != mm2oOStatHd(5) *
            7 + mm2oOStatHdBonus(5) * 2
            || mm2oOStatAvgHp(6) * 2 + mm2oOStatHd(6) % 2 != mm2oOStatHd(6) *
            7 + mm2oOStatHdBonus(6) * 2
        )
            ++bad;
        // the loader attack semantics (the "3 or 1" max read, the "1 and 1"
        // sum, the "Nil" floor)
    if (mm2oOStatAttacks(1) != 3
            || mm2oOStatAttacks(3) != 2
            || mm2oOStatAttacks(0) != 1
            || mm2oOStatAttacks(4) != 4
        )
            ++bad;
        printf("R809 MM2 letter O walk audit: bad %d\n", bad);
        if (bad) return 1;
    }
