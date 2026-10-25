    // ---- R619 OA barbarian bushi audit ----
    // OA round six (capture pp. 23-28): the first two of the ten classes -
    // the barbarian with its hit-die and Con bonuses, the capability ladders,
    // the three territories, the horde doctrine, and the bushi with its
    // advancement and poverty doctrine.
    {
        using namespace rules;
        int bad = 0;
    if (dgfBarbHitDie() != 12
            || dgfBarbConHpBonus() != 2
            || dgfBarbConThreshold() != 14
            || dgfBarbSurpriseDie() != 6
            || dgfBarbSurpriseChance() != 3
            || dgfBarbBackProtPerLevel() != 5
            || dgfBarbLeapFwd() != 10
            || dgfBarbLeapBack() != 3
            || dgfBarbLeapUp() != 3
            || dgfBarbRunLeapBase() != 15
            || dgfBarbRunLeapDie() != 6
            || dgfBarbRunLeapUpBase() != 4
            || dgfBarbRunLeapUpDie() != 4
            || dgfBarbDetIllusionPerLevel() != 5
            || dgfBarbDetIllusionCap() != 75
            || dgfBarbDetMagicBase() != 25
            || dgfT14RowCount() != 11
            || dgfT14XpBeyond() != 500000
            || dgfT14HpBeyond() != 4
            || dgfT15RowCount() != 10
            || dgfB15Potions() != 1
            || dgfB15WeaponsSave() != 2
            || dgfB15Armor() != 3
            || dgfB15HalfXp() != 4
            || dgfB15MiscItems() != 5
            || dgfB15FullXp() != 6
            || dgfB15Scrolls() != 7
            || dgfB15SaveTwo() != 8
            || dgfB15Horde() != 9
            || dgfB15SaveThree() != 10
            || dgfT16RowCount() != 11
            || dgfSteppeProfCount() != 16
            || dgfSteppeWeaponCount() != 4
            || dgfForestProfCount() != 18
            || dgfForestWeaponCount() != 5
            || dgfJungleProfCount() != 16
            || dgfJungleWeaponCount() != 5
            || dgfHordeLevel() != 11
            || dgfHordeXpDiv() != 2000
            || dgfHordeAidePerMen() != 500
            || dgfHordeAssemblePerWeek() != 500
            || dgfHordeMaxWeeksNum() != 3
            || dgfHordeMaxWeeksDen() != 2
            || dgfBushiHitDie() != 10
            || dgfBushiSlots() != 4
            || dgfBushiPoorProfCount() != 3
            || dgfBushiAcStepLevels() != 5
            || dgfT17RowCount() != 12
            || dgfT17XpBeyond() != 250000
            || dgfT17HpBeyond() != 2
            || !dgfBarbNoPrime()
            || !dgfBarbNotLawful()
            || !dgfBarbFighterTables()
            || !dgfBarbMagicHatred()
            || !dgfBarbNoXpForItems()
            || !dgfBarbXpForDestroying()
            || !dgfBarbWuJenFoes()
            || !dgfBarbClimbSmoothHalf()
            || !dgfBarbHideUnfamiliarHalf()
            || !dgfBarbBackProtFreeAttack()
            || !dgfSteppeNomads()
            || !dgfForestVillages()
            || !dgfJungleVillages()
            || !dgfBarbOutsiders()
            || !dgfHordeShamans()
            || !dgfHordePurposeFixed()
            || !dgfHordeWeeksEqualLevel()
            || !dgfHordeSuccessLegacy()
            || !dgfBushiMasterless()
            || !dgfBushiStrPrime()
            || !dgfBushiFighterTables()
            || !dgfBushiNinjaHonor()
            || !dgfBushiFighterBonuses()
        )
            ++bad;
        // the Table 14 grid: the level xp bounds and the accumulated dice
        // plus bonus (capture p. 24)
        int CT14[11][3] = {
            {4000,1,0},
            {8000,2,0},
            {16000,3,0},
            {32000,4,0},
            {75000,5,0},
            {130000,6,0},
            {240000,7,0},
            {460000,8,0},
            {900000,8,4},
            {1400000,8,8},
            {1900000,8,12},
            };
        for (int b = 0;
             b < dgfT14RowCount();
             ++b) {
            int vals[3];
            vals[0] = dgfT14XpMax(b);
            vals[1] = dgfT14Dice(b);
            vals[2] = dgfT14HpBonus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT14[b][c])
                    ++bad;
            }
        }
        // the Table 15 grid: the level ladder of lifted restrictions with the
        // save bonuses (capture p. 25)
        int CT15[10][3] = {
            {3,1,1},
            {4,2,1},
            {5,3,0},
            {6,4,0},
            {7,5,0},
            {8,6,0},
            {9,7,0},
            {10,8,2},
            {11,9,0},
            {12,10,3},
            };
        for (int b = 0;
             b < dgfT15RowCount();
             ++b) {
            int vals[3];
            vals[0] = dgfT15Level(b);
            vals[1] = dgfT15Bonus(b);
            vals[2] = dgfT15SaveBonus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT15[b][c])
                    ++bad;
            }
        }
        // the Table 16 grid: climb, hide, back protection, detect illusion
        // and detect magic across levels 1-11 (capture p. 25)
        int CT16[11][5] = {
            {85,25,5,5,30},
            {86,31,10,10,35},
            {87,37,15,15,40},
            {88,43,20,20,45},
            {89,49,25,25,50},
            {90,56,30,30,55},
            {91,63,35,35,60},
            {92,70,40,40,65},
            {93,77,45,45,70},
            {94,85,50,50,75},
            {95,93,55,55,80},
            };
        for (int b = 0;
             b < dgfT16RowCount();
             ++b) {
            int vals[5];
            vals[0] = dgfT16Climb(b);
            vals[1] = dgfT16Hide(b);
            vals[2] = dgfT16BackProt(b);
            vals[3] = dgfT16DetIllusion(b);
            vals[4] = dgfT16DetMagic(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT16[b][c])
                    ++bad;
            }
        }
        // the Table 17 grid: the level xp bounds and the accumulated dice
        // plus bonus (capture p. 27)
        int CT17[12][3] = {
            {1500,1,0},
            {3000,2,0},
            {6000,3,0},
            {14000,4,0},
            {30000,5,0},
            {60000,6,0},
            {120000,7,0},
            {240000,8,0},
            {480000,9,0},
            {710000,9,2},
            {1000000,9,4},
            {1250000,9,6},
            };
        for (int b = 0;
             b < dgfT17RowCount();
             ++b) {
            int vals[3];
            vals[0] = dgfT17XpMax(b);
            vals[1] = dgfT17Dice(b);
            vals[2] = dgfT17HpBonus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT17[b][c])
                    ++bad;
            }
        }
        // the dgfBarbNoPrime pin
    if (dgfBarbNoPrime() != 1
        )
            ++bad;
        // the dgfBarbNotLawful pin
    if (dgfBarbNotLawful() != 1
        )
            ++bad;
        // the dgfBarbHitDie pin
    if (dgfBarbHitDie() != 12
        )
            ++bad;
        // the dgfBarbFighterTables pin
    if (dgfBarbFighterTables() != 1
        )
            ++bad;
        // the dgfBarbConHpBonus pin
    if (dgfBarbConHpBonus() != 2
        )
            ++bad;
        // the dgfBarbConThreshold pin
    if (dgfBarbConThreshold() != 14
        )
            ++bad;
        // the dgfBarbMagicHatred pin
    if (dgfBarbMagicHatred() != 1
        )
            ++bad;
        // the dgfBarbNoXpForItems pin
    if (dgfBarbNoXpForItems() != 1
        )
            ++bad;
        // the dgfBarbXpForDestroying pin
    if (dgfBarbXpForDestroying() != 1
        )
            ++bad;
        // the dgfBarbWuJenFoes pin
    if (dgfBarbWuJenFoes() != 1
        )
            ++bad;
        // the dgfBarbClimbSmoothHalf pin
    if (dgfBarbClimbSmoothHalf() != 1
        )
            ++bad;
        // the dgfBarbHideUnfamiliarHalf pin
    if (dgfBarbHideUnfamiliarHalf() != 1
        )
            ++bad;
        // the dgfBarbSurpriseDie pin
    if (dgfBarbSurpriseDie() != 6
        )
            ++bad;
        // the dgfBarbSurpriseChance pin
    if (dgfBarbSurpriseChance() != 3
        )
            ++bad;
        // the dgfBarbBackProtPerLevel pin
    if (dgfBarbBackProtPerLevel() != 5
        )
            ++bad;
        // the dgfBarbBackProtFreeAttack pin
    if (dgfBarbBackProtFreeAttack() != 1
        )
            ++bad;
        // the dgfBarbLeapFwd pin
    if (dgfBarbLeapFwd() != 10
        )
            ++bad;
        // the dgfBarbLeapBack pin
    if (dgfBarbLeapBack() != 3
        )
            ++bad;
        // the dgfBarbLeapUp pin
    if (dgfBarbLeapUp() != 3
        )
            ++bad;
        // the dgfBarbRunLeapBase pin
    if (dgfBarbRunLeapBase() != 15
        )
            ++bad;
        // the dgfBarbRunLeapDie pin
    if (dgfBarbRunLeapDie() != 6
        )
            ++bad;
        // the dgfBarbRunLeapUpBase pin
    if (dgfBarbRunLeapUpBase() != 4
        )
            ++bad;
        // the dgfBarbRunLeapUpDie pin
    if (dgfBarbRunLeapUpDie() != 4
        )
            ++bad;
        // the dgfBarbDetIllusionPerLevel pin
    if (dgfBarbDetIllusionPerLevel() != 5
        )
            ++bad;
        // the dgfBarbDetIllusionCap pin
    if (dgfBarbDetIllusionCap() != 75
        )
            ++bad;
        // the dgfBarbDetMagicBase pin
    if (dgfBarbDetMagicBase() != 25
        )
            ++bad;
        // the dgfT14RowCount pin
    if (dgfT14RowCount() != 11
        )
            ++bad;
        // the dgfT14XpBeyond pin
    if (dgfT14XpBeyond() != 500000
        )
            ++bad;
        // the dgfT14HpBeyond pin
    if (dgfT14HpBeyond() != 4
        )
            ++bad;
        // the dgfT15RowCount pin
    if (dgfT15RowCount() != 10
        )
            ++bad;
        // the dgfB15Potions pin
    if (dgfB15Potions() != 1
        )
            ++bad;
        // the dgfB15WeaponsSave pin
    if (dgfB15WeaponsSave() != 2
        )
            ++bad;
        // the dgfB15Armor pin
    if (dgfB15Armor() != 3
        )
            ++bad;
        // the dgfB15HalfXp pin
    if (dgfB15HalfXp() != 4
        )
            ++bad;
        // the dgfB15MiscItems pin
    if (dgfB15MiscItems() != 5
        )
            ++bad;
        // the dgfB15FullXp pin
    if (dgfB15FullXp() != 6
        )
            ++bad;
        // the dgfB15Scrolls pin
    if (dgfB15Scrolls() != 7
        )
            ++bad;
        // the dgfB15SaveTwo pin
    if (dgfB15SaveTwo() != 8
        )
            ++bad;
        // the dgfB15Horde pin
    if (dgfB15Horde() != 9
        )
            ++bad;
        // the dgfB15SaveThree pin
    if (dgfB15SaveThree() != 10
        )
            ++bad;
        // the dgfT16RowCount pin
    if (dgfT16RowCount() != 11
        )
            ++bad;
        // the dgfSteppeProfCount pin
    if (dgfSteppeProfCount() != 16
        )
            ++bad;
        // the dgfSteppeWeaponCount pin
    if (dgfSteppeWeaponCount() != 4
        )
            ++bad;
        // the dgfSteppeNomads pin
    if (dgfSteppeNomads() != 1
        )
            ++bad;
        // the dgfForestProfCount pin
    if (dgfForestProfCount() != 18
        )
            ++bad;
        // the dgfForestWeaponCount pin
    if (dgfForestWeaponCount() != 5
        )
            ++bad;
        // the dgfForestVillages pin
    if (dgfForestVillages() != 1
        )
            ++bad;
        // the dgfJungleProfCount pin
    if (dgfJungleProfCount() != 16
        )
            ++bad;
        // the dgfJungleWeaponCount pin
    if (dgfJungleWeaponCount() != 5
        )
            ++bad;
        // the dgfJungleVillages pin
    if (dgfJungleVillages() != 1
        )
            ++bad;
        // the dgfBarbOutsiders pin
    if (dgfBarbOutsiders() != 1
        )
            ++bad;
        // the dgfHordeLevel pin
    if (dgfHordeLevel() != 11
        )
            ++bad;
        // the dgfHordeXpDiv pin
    if (dgfHordeXpDiv() != 2000
        )
            ++bad;
        // the dgfHordeAidePerMen pin
    if (dgfHordeAidePerMen() != 500
        )
            ++bad;
        // the dgfHordeShamans pin
    if (dgfHordeShamans() != 1
        )
            ++bad;
        // the dgfHordeAssemblePerWeek pin
    if (dgfHordeAssemblePerWeek() != 500
        )
            ++bad;
        // the dgfHordePurposeFixed pin
    if (dgfHordePurposeFixed() != 1
        )
            ++bad;
        // the dgfHordeWeeksEqualLevel pin
    if (dgfHordeWeeksEqualLevel() != 1
        )
            ++bad;
        // the dgfHordeMaxWeeksNum pin
    if (dgfHordeMaxWeeksNum() != 3
        )
            ++bad;
        // the dgfHordeMaxWeeksDen pin
    if (dgfHordeMaxWeeksDen() != 2
        )
            ++bad;
        // the dgfHordeSuccessLegacy pin
    if (dgfHordeSuccessLegacy() != 1
        )
            ++bad;
        // the dgfBushiMasterless pin
    if (dgfBushiMasterless() != 1
        )
            ++bad;
        // the dgfBushiStrPrime pin
    if (dgfBushiStrPrime() != 1
        )
            ++bad;
        // the dgfBushiHitDie pin
    if (dgfBushiHitDie() != 10
        )
            ++bad;
        // the dgfBushiFighterTables pin
    if (dgfBushiFighterTables() != 1
        )
            ++bad;
        // the dgfBushiNinjaHonor pin
    if (dgfBushiNinjaHonor() != 1
        )
            ++bad;
        // the dgfBushiFighterBonuses pin
    if (dgfBushiFighterBonuses() != 1
        )
            ++bad;
        // the dgfBushiSlots pin
    if (dgfBushiSlots() != 4
        )
            ++bad;
        // the dgfBushiPoorProfCount pin
    if (dgfBushiPoorProfCount() != 3
        )
            ++bad;
        // the dgfBushiAcStepLevels pin
    if (dgfBushiAcStepLevels() != 5
        )
            ++bad;
        // the dgfT17RowCount pin
    if (dgfT17RowCount() != 12
        )
            ++bad;
        // the dgfT17XpBeyond pin
    if (dgfT17XpBeyond() != 250000
        )
            ++bad;
        // the dgfT17HpBeyond pin
    if (dgfT17HpBeyond() != 2
        )
            ++bad;
        // the T14 level-9 row - eight dice plus the 4 bonus (capture p. 24)
    if (dgfT14Dice(8) != 8
            || dgfT14HpBonus(8) != 4
        )
            ++bad;
        // the T16 detect magic - 25 base plus 5 per level lands 30 at 1st
        // (capture p. 25)
    if (dgfT16DetMagic(0) != 30
        )
            ++bad;
        // the T15 horde bonus at level 11 with no save bump (capture p. 25)
    if (dgfT15Bonus(8) != 9
            || dgfT15SaveBonus(8) != 0
        )
            ++bad;
        // the T17 level-10 row - nine dice plus the 2 bonus (capture p. 27)
    if (dgfT17Dice(9) != 9
            || dgfT17HpBonus(9) != 2
        )
            ++bad;
        // the horde max weeks - 1 1/2 times the level, the 3-over-2 pair
        // (capture p. 26)
    if (dgfHordeMaxWeeksNum() != 3
            || dgfHordeMaxWeeksDen() != 2
        )
            ++bad;
        // the barbarian Con bonus doubles the bushi hp-beyond step at their
        // thresholds (capture pp. 23, 27)
    if (dgfBarbConHpBonus() != dgfT17HpBeyond()
        )
            ++bad;
        // the bushi AC step - one per five levels (capture p. 27)
    if (dgfBushiAcStepLevels() != 5
        )
            ++bad;
        // the territory proficiency counts - 16, 18 and 16 (capture p. 26)
    if (dgfSteppeProfCount() != 16
            || dgfForestProfCount() != 18
            || dgfJungleProfCount() != 16
        )
            ++bad;
        printf("R619 OA barbarian bushi audit: bad %d\n", bad);
        if (bad) return 1;
    }
