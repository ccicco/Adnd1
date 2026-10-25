    // ---- R506 DSG proficiencies audit ----
    // The DSG nonweapon proficiencies pins the check system (the Ability
    // Check frame, the +3-makes-12-equal-15 example, the improving +2 per
    // slot, the natural-20 flawless creation, the 110-200 percent pricing),
    // the slot economy (the one-way weapon-for-nonweapon trade, the Secondary
    // Skills conversion), the artisan ladder (the 2-slot no-weapon NPC,
    // journeyman 1-4 years, the master slot per 4 years), the craftsman
    // numbers (the armorer 2-weeks-per-AC-point with the 19-20 flawed
    // breakage, the trainer 3-month/6-animal cycles, the boatwright
    // week-per-foot, the bowyer and weaponsmith fine-quality options, the
    // carpenter crews, the smelter 4/20/100-miner ladder at 5/12/25 gp, the
    // potter costs), the adventuring numbers (the blind-fighting -2, the
    // direction-sense bands, the endurance doubling, the fire-building dice,
    // the fishing count, the fungus 50 percent, the healing pins, the six
    // riding feats, the rope bonuses, the slow respiration, the sound
    // analysis margins) and the XP option, with the four grids (Tables
    // 10-13).
    {
        using namespace rules;
        int bad = 0;
    if (dnpCheckDieSides() != 20
            || dnpCheckModifierExampleMod() != 3
            || dnpCheckModifierExampleRoll() != 12
            || dnpCheckModifierExampleEq() != 15
            || dnpImprovedStepPlus() != 2
            || dnpImprovedExampleFrom() != -1
            || dnpImprovedExampleTo() != 1
            || dnpProductPriceLoPct() != 110
            || dnpProductPriceHiPct() != 200
            || dnpSecondarySkillsPerSlotLo() != 1
            || dnpSecondarySkillsPerSlotHi() != 2
            || dnpNpcNoWeaponYieldsNonweapon() != 2
            || dnpJourneymanYearsLo() != 1
            || dnpJourneymanYearsHi() != 4
            || dnpMasterArrivalSlot() != 1
            || dnpMasterYearsPerSlot() != 4
            || dnpOptionalArmorPlusLo() != 1
            || dnpOptionalArmorPlusHi() != 2
            || dnpTrainerRoleMonths() != 3
            || dnpTrainerMaxAnimals() != 6
            || dnpTrainerEndMod() != 10
            || dnpTrainerAdvancedMonths() != 3
            || dnpTrainerAdvancedMax() != 3
            || dnpArmorWeeksPerACPoint() != 2
            || dnpArmorShieldWeeks() != 2
            || dnpArmorFullPlateWeeks() != 18
            || dnpArmorFlawedWithin() != 4
            || dnpArmorFlawedACWorse() != 1
            || dnpArmorBreaksOnLo() != 19
            || dnpArmorBreaksOnHi() != 20
            || dnpArmorBreakACDrop() != 4
            || dnpArmorBreakACCap() != 10
            || dnpArmorRemoveRoundsDie() != 4
            || dnpArmorBrokenMoveNum() != 1
            || dnpArmorBrokenMoveDen() != 2
            || dnpArmorBrokenAttackMod() != -4
            || dnpBoatMaxLenFt() != 60
            || dnpBoatWeeksPerFoot() != 1
            || dnpBoatCrewPerFtDen() != 5
            || dnpBoatFeatureWeeks() != 1
            || dnpBoatUnskilledPerSkilled() != 2
            || dnpBowWeeks() != 1
            || dnpCompositeBowWeeks() != 2
            || dnpArrowsPerDayDie() != 6
            || dnpFineBowRangeBonusIn() != 2
            || dnpBowBreaksOnAttack() != 1
            || dnpBowFineDamageBonus() != 1
            || dnpBowFineNat20AttackBonus() != 1
            || dnpCarpenterCubeFt() != 10
            || dnpCarpenterWeeksPerCube() != 1
            || dnpCarpenterCrewForDaily() != 7
            || dnpCarpenterPerWorkers() != 9
            || dnpGemStonesPerDayDie() != 10
            || dnpPotterSmallMedPerDay() != 2
            || dnpPotterLargePerDay() != 1
            || dnpPotterKilnDays() != 1
            || dnpPotterSmallCostCp() != 3
            || dnpPotterMediumCostCp() != 5
            || dnpPotterLargeCostCp() != 10
            || dnpSmeltSmallMiners() != 4
            || dnpSmeltMediumMiners() != 20
            || dnpSmeltLargeMiners() != 100
            || dnpSmeltSmallGpPerDay() != 5
            || dnpSmeltMediumGpPerDay() != 12
            || dnpSmeltLargeGpPerDay() != 25
            || dnpMasonWallThickFt() != 1
            || dnpMasonWallLongFt() != 10
            || dnpMasonWallHighFt() != 5
            || dnpWeaveSqYardsPerDay() != 2
            || dnpWeaponsmithFineDamageBonus() != 1
            || dnpWeaponsmithNat20AttackBonus() != 1
            || dnpBlindAttackMod() != -2
            || dnpBlindStandardMod() != -4
            || dnpBlindDexReductionOnly() != 1
            || dnpBlindClimbPenaltyOnly() != -5
            || dnpDirConcentrateRoundsDie() != 6
            || dnpDirErrorDeg() != 90
            || dnpDirOppositeRoll() != 1
            || dnpEnduranceTimeMult() != 2
            || dnpFireDryMinutesDice() != 2
            || dnpFireAdverseMinutesDice() != 3
            || dnpFishChecksPerHour() != 1
            || dnpFishRationNum() != 1
            || dnpFishRationDen() != 2
            || dnpFungusDeadlyPct() != 50
            || dnpFungusStudyTurns() != 1
            || dnpHealEmergencyRounds() != 1
            || dnpHealEmergencyDie() != 3
            || dnpHealTravelHpPerDay() != 1
            || dnpHealRestHpPerDay() != 2
            || dnpHealPoisonSaveMod() != 2
            || dnpHealPoisonRestTurns() != 1
            || dnpHealPoisonAidRounds() != 5
            || dnpMountClimbBonusPctPerSlot() != 10
            || dnpRideJumpFreeObstacleFt() != 3
            || dnpRideJumpFreeGapFt() != 12
            || dnpRideJumpMaxObstacleFt() != 7
            || dnpRideJumpMaxGapFt() != 30
            || dnpRideSpurFtPerRound() != 6
            || dnpRideSpurMaxTurns() != 4
            || dnpRideSpurLeadTurns() != 1
            || dnpRideShieldACBonus() != 6
            || dnpRideDropMeleeFt() != 10
            || dnpRideDropMod() != -4
            || dnpRideDropFailDie() != 3
            || dnpRideKneesFailDie() != 6
            || dnpRopeLassoMod() != 2
            || dnpRopeClimbBonusPct() != 10
            || dnpRopeEscapeMod() != -6
            || dnpSlowAirPct() != 10
            || dnpSlowConcentrateTurns() != 1
            || dnpSoundMaxMiles() != 1
            || dnpSoundLenPct() != 30
            || dnpSoundWidthPct() != 25
            || dnpSoundHeightPct() != 25
            || dnpSoundDetailRoll() != 5
            || dnpXpPerGpNum() != 1
            || dnpXpPerGpDen() != 2
            || dnpXpNpcHpDie() != 4
            || dnpT10RowCount() != 14
            || dnpT11RowCount() != 14
            || dnpT12RowCount() != 11
            || dnpT13RowCount() != 15
            || dnpArrowheadsPerDayLo() != 1
            || dnpArrowheadsPerDayHi() != 2
            || !dnpCheckLikeAbilityCheck()
            || !dnpSuccessDegreeQuality()
            || !dnpNatural20Flawless()
            || !dnpMostUsesNoFailure()
            || !dnpSlotsNeedNotBeFilled()
            || !dnpUnfilledSlotSaved()
            || !dnpFilledSlotCannotChange()
            || !dnpWeaponSlotHoldsNonweapon()
            || dnpNonweaponSlotHoldsWeapon()
            || !dnpTimeAssumesFullDay()
            || !dnpDistractionIncreasesTime()
            || !dnpOptionalBonusesAllowed()
            || !dnpBackgroundAutoProficiency()
            || !dnpTrainerDeclaresSpecies()
            || !dnpArmorFlawsArmorerDetects()
            || !dnpArmorPlateFittingsWeekly()
            || !dnpBlacksmithNeedsForge()
            || !dnpBlacksmithNoSharpWeapons()
            || !dnpBoatLargerNeedsShipwright()
            || !dnpBowFailArrowFirstShot()
            || !dnpBowFailBowBreaks()
            || !dnpBowFineFailWorthless()
            || !dnpBowyerNeedsWeaponsmithHeads()
            || !dnpGemCutterNoAssist()
            || !dnpGemCutterNeedsLightTools()
            || !dnpLeatherMakesArmor()
            || !dnpMinerFindsAndSupervises()
            || !dnpSmeltCostsOnlyOperating()
            || !dnpSmeltStockpilePractice()
            || !dnpMasonOftenMortared()
            || !dnpWeaverNeedsLoom()
            || !dnpWeaponsmithFineFailWorthless()
            || !dnpWeaponsmithEstimateByComparison()
            || !dnpAnimalNoiseMagicOnly()
            || !dnpAnimalNoiseFamiliarAuto()
            || !dnpAnimalNoiseOthersWisdomCheck()
            || !dnpBlindNoACPenalty()
            || !dnpBlindRetainsSpecials()
            || !dnpBlindStumbleHalved()
            || !dnpBoatingMaxSpeed()
            || !dnpBoatingReducesCapsize()
            || !dnpDirSecretDMRoll()
            || !dnpEnduranceNoFoodWaterExtension()
            || !dnpFireNoTinderbox()
            || !dnpFireAdverseNeedsCheck()
            || !dnpFishCountWisdomMinusRoll()
            || !dnpFungusStudyNoCheck()
            || !dnpHealInterruptResaves()
            || !dnpMountUsesSpikes()
            || !dnpRideVaultStillFree()
            || !dnpRideVaultMovingCheck()
            || !dnpRideKneesCheckOnlyWhenDamaged()
            || !dnpRideJumpBalkOnFail()
            || !dnpRideSpurCheckEachTurn()
            || !dnpRideShieldNoArmorNoAttack()
            || !dnpRopeClimbBonusIncludesBelay()
            || !dnpSlowFullyAware()
            || !dnpSoundSilenceRequired()
            || !dnpSoundStaccatoRequired()
            || !dnpSoundFailLocksArea()
            || !dnpSoundAnnouncesParty()
            || !dnpSoundCombinesAnimalNoise()
            || !dnpSwimRulesOnPageTwelve()
            || !dnpXpPcNeverEarns()
            || !dnpXpUseFighterTable()
            || !dnpXpDMMayAssignLevels()
            || !dnpHorsemanHasOneNonweapon()
            || !dnpBardAsOtherClasses()
        )
            ++bad;
        // the Table 10 class grid
        int C10[14][5] = {
            {3,2,1,1,2},
            {3,2,1,1,2},
            {2,3,1,1,4},
            {2,3,1,1,5},
            {4,2,1,1,3},
            {6,3,1,1,2},
            {3,2,1,1,3},
            {1,3,1,2,6},
            {1,3,1,2,6},
            {2,3,1,1,4},
            {2,3,1,1,4},
            {3,2,1,1,4},
            {1,1,1,1,2},
            {-1,-1,1,1,4},
            };
        int n10[5] = {0,0,0,0,0};
        int e10[5] = {1,1,0,0,0};
        for (int b = 0;
             b < dnpT10RowCount();
             ++b) {
            int vals[5];
            vals[0] = dnpT10InitialWeapon(b);
            vals[1] = dnpT10InitialNonweapon(b);
            vals[2] = dnpT10AddWeapon(b);
            vals[3] = dnpT10AddNonweapon(b);
            vals[4] = dnpT10EveryLevels(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != C10[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++n10[c];
            }
        }
        for (int c = 0; c < 5; ++c)
            if (n10[c] != e10[c])
                ++bad;
        // the Table 11 craftsman grid
        int C11[14][4] = {
            {1,1,0,1},
            {1,2,2,0},
            {1,4,0,0},
            {1,2,-2,0},
            {1,3,-1,1},
            {1,4,0,0},
            {2,2,2,0},
            {1,2,0,0},
            {2,1,-3,1},
            {1,3,-2,0},
            {1,2,-2,0},
            {1,4,-2,0},
            {3,2,3,1},
            {4,2,4,0},
            };
        for (int b = 0;
             b < dnpT11RowCount();
             ++b) {
            int vals[4];
            vals[0] = dnpT11Slots(b);
            vals[1] = dnpT11Ability(b);
            vals[2] = dnpT11Modifier(b);
            vals[3] = dnpT11EveryUse(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C11[b][c])
                    ++bad;
            }
        }
        // the Table 12 weapon-making grid
        int C12[11][2] = {
            {-1,1},
            {10,100},
            {5,50},
            {5,20},
            {20,100},
            {15,50},
            {20,100},
            {4,40},
            {20,50},
            {30,100},
            {45,200},
            };
        int n12[2] = {0,0};
        int e12[2] = {1,0};
        for (int b = 0;
             b < dnpT12RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnpT12Days(b);
            vals[1] = dnpT12CostCp(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C12[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++n12[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (n12[c] != e12[c])
                ++bad;
        // the Table 13 adventuring grid
        int C13[15][4] = {
            {1,1,-1,0},
            {1,0,99,0},
            {1,1,1,0},
            {1,1,1,1},
            {2,0,99,0},
            {1,1,-1,0},
            {1,1,-1,1},
            {1,2,6,0},
            {2,1,2,1},
            {1,0,99,0},
            {1,1,3,0},
            {1,3,0,0},
            {1,0,99,0},
            {1,1,-1,0},
            {1,5,0,0},
            };
        int n13[4] = {0,0,0,0};
        int e13[4] = {0,0,4,0};
        for (int b = 0;
             b < dnpT13RowCount();
             ++b) {
            int vals[4];
            vals[0] = dnpT13Slots(b);
            vals[1] = dnpT13Ability(b);
            vals[2] = dnpT13Modifier(b);
            vals[3] = dnpT13EveryUse(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C13[b][c])
                    ++bad;
                if (vals[c] == 99)
                    ++n13[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (n13[c] != e13[c])
                ++bad;
        // the Table 10 cavalier row: 3/2 initial, 1/1 added, every 2 levels.
    if (dnpT10InitialWeapon(0) != 3
            || dnpT10InitialNonweapon(0) != 2
            || dnpT10AddWeapon(0) != 1
            || dnpT10AddNonweapon(0) != 1
            || dnpT10EveryLevels(0) != 2
        )
            ++bad;
        // the Table 10 magic-user row: 1/3 initial, 1/2 added, every 6
        // levels.
    if (dnpT10InitialWeapon(7) != 1
            || dnpT10InitialNonweapon(7) != 3
            || dnpT10AddNonweapon(7) != 2
            || dnpT10EveryLevels(7) != 6
        )
            ++bad;
        // the Table 10 bard row reads as other classes (the -1 sentinel),
        // every 4 levels.
    if (dnpT10InitialWeapon(13) != -1
            || dnpT10InitialNonweapon(13) != -1
            || dnpT10EveryLevels(13) != 4
        )
            ++bad;
        // the printed check example: a d20 roll of 12 with a +3 modifier
        // equals a 15.
    if (dnpCheckModifierExampleRoll() + dnpCheckModifierExampleMod() !=
        dnpCheckModifierExampleEq()
        )
            ++bad;
        // the printed improving example: the -1 miner modifier rises to +1
        // with one additional slot.
    if (dnpImprovedExampleFrom() + dnpImprovedStepPlus() !=
        dnpImprovedExampleTo()
        )
            ++bad;
        // the Table 11 gem cutter row: 2 slots, Intelligence, +2.
    if (dnpT11Slots(6) != 2
            || dnpT11Ability(6) != 2
            || dnpT11Modifier(6) != 2
        )
            ++bad;
        // the Table 11 miner row: 2 slots (asterisked), Wisdom, -3.
    if (dnpT11Slots(8) != 2
            || dnpT11Ability(8) != 1
            || dnpT11Modifier(8) != -3
            || dnpT11EveryUse(8) != 1
        )
            ++bad;
        // the Table 12 longsword row: 30 days, 10 sp (100 cp).
    if (dnpT12Days(9) != 30
            || dnpT12CostCp(9) != 100
        )
            ++bad;
        // the Table 12 two-handed sword row: 45 days, 2 gp (200 cp).
    if (dnpT12Days(10) != 45
            || dnpT12CostCp(10) != 200
        )
            ++bad;
        // the armor times: a shield is 1 AC point below 10 (2 weeks), full
        // plate 9 (18 weeks).
    if (dnpArmorWeeksPerACPoint() * 1 != dnpArmorShieldWeeks()
            || dnpArmorWeeksPerACPoint() * 9 != dnpArmorFullPlateWeeks()
        )
            ++bad;
        // the smelter economy: a medium smelter handles 20 miners ore at 12
        // gp per day.
    if (dnpSmeltMediumMiners() != 20
            || dnpSmeltMediumGpPerDay() != 12
        )
            ++bad;
        // the riding spur: +6 feet per round for up to four turns, then a led
        // turn.
    if (dnpRideSpurFtPerRound() != 6
            || dnpRideSpurMaxTurns() != 4
            || dnpRideSpurLeadTurns() != 1
        )
            ++bad;
        // the healing pins: 1d3 emergency, 2 hp/day at rest, +2 poison save,
        // 5 aid rounds.
    if (dnpHealEmergencyDie() != 3
            || dnpHealRestHpPerDay() != 2
            || dnpHealPoisonSaveMod() != 2
            || dnpHealPoisonAidRounds() != 5
        )
            ++bad;
        // the fire-building times: 2d20 minutes dry, 3d20 adverse.
    if (dnpFireDryMinutesDice() != 2
            || dnpFireAdverseMinutesDice() != 3
        )
            ++bad;
        // the sound analysis margins: length +/-30, width +/-25, height +/-25
        // percent; a 5-or-less reveals details, range up to one mile.
    if (dnpSoundLenPct() != 30
            || dnpSoundWidthPct() != 25
            || dnpSoundHeightPct() != 25
            || dnpSoundDetailRoll() != 5
            || dnpSoundMaxMiles() != 1
        )
            ++bad;
        // the blind-fighting penalty is -2, replacing the standard -4.
    if (dnpBlindAttackMod() != -2
            || dnpBlindStandardMod() != -4
        )
            ++bad;
        // the XP option: 200 gp of business income nets 100 experience points
        // (1 per 2 gp).
    if (200 * dnpXpPerGpNum() != 100 * dnpXpPerGpDen()
        )
            ++bad;
        // the rope use pins: +2 lasso, +10 percent climbing, -6 escape
        // penalty.
    if (dnpRopeLassoMod() != 2
            || dnpRopeClimbBonusPct() != 10
            || dnpRopeEscapeMod() != -6
        )
            ++bad;
        // the Table 13 fungus identification row: 1 slot, Intelligence, +6.
    if (dnpT13Slots(7) != 1
            || dnpT13Ability(7) != 2
            || dnpT13Modifier(7) != 6
        )
            ++bad;
        // the Table 13 healing row: 2 slots (asterisked), Wisdom, +2.
    if (dnpT13Slots(8) != 2
            || dnpT13Ability(8) != 1
            || dnpT13Modifier(8) != 2
            || dnpT13EveryUse(8) != 1
        )
            ++bad;
        // the Table 13 blind-fighting row: 1 slot, NA ability, NA modifier.
    if (dnpT13Slots(1) != 1
            || dnpT13Ability(1) != 0
            || dnpT13Modifier(1) != 99
        )
            ++bad;
        // the artisan ladder: no-weapon NPCs get 2 slots, journeyman 1-4
        // years, then one slot per 4 years.
    if (dnpNpcNoWeaponYieldsNonweapon() != 2
            || dnpJourneymanYearsLo() != 1
            || dnpJourneymanYearsHi() != 4
            || dnpMasterYearsPerSlot() != 4
        )
            ++bad;
        // the animal trainer pins: 3 months, 6 animals, +10 at the end, 3
        // animals in additional training.
    if (dnpTrainerRoleMonths() != 3
            || dnpTrainerMaxAnimals() != 6
            || dnpTrainerEndMod() != 10
            || dnpTrainerAdvancedMax() != 3
        )
            ++bad;
        // the Table 11 animal trainer row: 1 slot (asterisked), Wisdom, 0.
    if (dnpT11Slots(0) != 1
            || dnpT11Ability(0) != 1
            || dnpT11Modifier(0) != 0
            || dnpT11EveryUse(0) != 1
        )
            ++bad;
        // the Table 12 arrowhead row: the per-day sentinel, 1 cp, 1-2 per
        // day.
    if (dnpT12Days(0) != -1
            || dnpT12CostCp(0) != 1
            || dnpArrowheadsPerDayLo() != 1
            || dnpArrowheadsPerDayHi() != 2
        )
            ++bad;
        // the Table 13 swimming row: 1 slot, Strength, 0.
    if (dnpT13Slots(14) != 1
            || dnpT13Ability(14) != 5
            || dnpT13Modifier(14) != 0
        )
            ++bad;
        // the Table 13 rope use row: 1 slot, Dexterity, 0.
    if (dnpT13Slots(11) != 1
            || dnpT13Ability(11) != 3
            || dnpT13Modifier(11) != 0
        )
            ++bad;
        // the Table 11 weaponsmith row: 3 slots, +3 (the grids-file caution
        // cells).
    if (dnpT11Slots(12) != 3
            || dnpT11Modifier(12) != 3
        )
            ++bad;
        // the Table 10 add-weapon column is 1 for fighter and bard alike.
    if (dnpT10AddWeapon(4) != 1
            || dnpT10AddWeapon(13) != 1
        )
            ++bad;
        // the Table 13 asterisks: direction sense, fishing and healing roll
        // each use.
    if (dnpT13EveryUse(3) != 1
            || dnpT13EveryUse(6) != 1
            || dnpT13EveryUse(8) != 1
        )
            ++bad;
        printf("R506 DSG proficiencies audit: bad %d\n", bad);
        if (bad) return 1;
    }
