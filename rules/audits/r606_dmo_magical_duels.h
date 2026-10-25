    // ---- R606 DMO magical-duels audit ----
    // CHAPTER 5 of the DMO (printed pp. 96-117), the dueling system closing
    // in one round: the arena construction protocol with the consent
    // doctrine, the balance-of-power cap, the corridor geometry (ten spaces
    // plus the highest contributed levels, capped at thirty), the five-type
    // doctrine with PR = level + nine, the Table 25 interactions grid, the
    // Table 26 movement bands, the 1d20 spell combat with the lock rules, the
    // character power scores and counter-spell doctrine, the item rules (the
    // 6d6/8d6/9d6 leech caps, the protection power-score read at 14), the
    // specialist gates, the friendly, death and service stakes ladders with
    // the plane-blow and disintegration chances, the mediator duties, the
    // special dueling characteristics (the five groups and the quantified
    // individual abilities), and the Calvin-and-Delsenora worked duel.
    {
        using namespace rules;
        int bad = 0;
    if (detArenaChantTurns() != 1
            || detBalanceExampleWizardLevel() != 7
            || detBalanceExamplePriestLevel() != 12
            || detBalanceExampleCapLevel() != 7
            || detArenaCorridorMinSpaces() != 12
            || detArenaCorridorMaxSpaces() != 30
            || detArenaBaseSpaces() != 10
            || detArenaMaxIntervening() != 30
            || detArenaLargestTotal() != 32
            || detArenaExampleSpaces() != 18
            || detArenaExampleSpellA() != 5
            || detArenaExampleSpellB() != 3
            || detRoundSteps() != 4
            || detTieAdvantageDie() != 10
            || detSpellTypes() != 5
            || detPRBase() != 9
            || detFireballPR() != 12
            || detOnlyOneDefensiveStay() != 1
            || detLeechDmgDie() != 6
            || detLeechDmgPerLevel() != 1
            || detADDmgDie() != 6
            || detADDmgPerLevel() != 1
            || detMvTouch() != 1
            || detMvShort() != 2
            || detMvMedium() != 3
            || detMvLong() != 4
            || detMvVeryLong() != 5
            || detFireball5thMv() != 4
            || detFireball15thMv() != 5
            || detCombatDie() != 20
            || detRaryCharmPR() != 10
            || detSertenCurePR() != 10
            || detRaryRoll() != 12
            || detSertenRoll() != 1
            || detRaryAltRoll() != 9
            || detLockExampleRaryRoll() != 20
            || detCharMoveOneSpace() != 1
            || detCharPRBase() != 9
            || detOneCounterPerIncoming() != 1
            || detCharVsCharDmgDie() != 6
            || detCharVsCharPushDie() != 4
            || detScrollProtectionPR() != 15
            || detScrollProtectionMv() != 1
            || detItemClassPrepTurns() != 1
            || detSpecificItemPrepTurns() != 1
            || detItemLeechMaxDice() != 6
            || detStaffLeechMaxDice() != 8
            || detOtherItemLeechMaxDice() != 9
            || detExamplePowerScore() != 11
            || detExampleArmorBonus() != 2
            || detExampleRingBonus() != 1
            || detExampleAdjustedPS() != 14
            || detPreexistingPrepTurns() != 1
            || detSpecialistPrepTurns() != 1
            || detOppositionSchoolPRBonus() != 1
            || detDispelBasePR() != 12
            || detDispelVsIllusionistPR() != 13
            || detUnseenServantPR() != 10
            || detVariedUnseenServantPR() != 5
            || detVariedFireballPR() != 7
            || detVariedFireballDmgDice() != 8
            || detVariedFireballMv() != 4
            || detExtraCondPrepTurns() != 1
            || detUnequalCondPrepTurns() != 2
            || detExcessAbilityLoss() != 1
            || detTempDmgRegenPerRound() != 1
            || detTempDeathAtMinus() != 10
            || detUnconsciousTurnsDice() != 2
            || detUnconsciousTurnsSize() != 6
            || detPlaneBlowBand4() != 20
            || detPlaneBlowBand5() != 40
            || detDisintegrateChance() != 50
            || detSummoningDmgDie() != 6
            || detSummoningDmgPerLevel() != 1
            || detIllusionDmgDie() != 6
            || detIllusionDmgPerLevel() != 1
            || detDemishadowFailDmgDice() != 10
            || detDemishadowCounterDmgDice() != 5
            || detDemishadowSaveDmgDice() != 4
            || detDemishadowSaveCounterDmgDice() != 2
            || detShadowFailDmgDice() != 10
            || detShadowCounterDmgDice() != 5
            || detShadowSecondSaveDmgDice() != 1
            || detShadowFailCounterDmgDice() != 2
            || detDemishadowMonDmgDice() != 5
            || detDemishadowMonSaveDmgDice() != 2
            || detEnergyDrainLevels() != 2
            || detEnervationDivisor() != 4
            || detEarthquakeDmgDice() != 5
            || detEarthquakeDmgSize() != 10
            || detEarthquakeCounterCount() != 6
            || detFireSeedsDmgDice() != 8
            || detFireSeedsSaveDice() != 4
            || detMagicalStoneDmgDice() != 3
            || detMagicalStoneDmgSize() != 4
            || detMeteorsPerRound() != 5
            || detMeteorDmgDie() != 4
            || detMeteorDmgBonus() != 1
            || detMomentBonus() != 4
            || detFreezingSphereMissileDice() != 6
            || detFreezingSpherePerLevelDie() != 4
            || detFreezingSpherePerLevelBonus() != 2
            || detFreezingSphereMaxDice() != 10
            || detRainbowFirstMissiles() != 4
            || detRainbowExtraMissiles() != 3
            || detRainbowDmgDie() != 6
            || detRainbowDmgBonus() != 2
            || detHeatMetalDmgPerRound() != 3
            || detHeatMetalMissileDmg() != 1
            || detHolyWordPSReduction() != 2
            || detChantCastRounds() != 2
            || detFirePurgeCastRounds() != 10
            || detFirePurgeDisruptRounds() != 9
            || detWishDuelDmgDice() != 10
            || detLimitedWishCounterMaxLevel() != 6
            || detGlobeLockMaxLevel() != 4
            || detMinorGlobeLockMaxLevel() != 3
            || detSpiritualHammerDmgDie() != 6
            || detShillelaghDmgDie() != 6
            || detWateryDoubleDmgDice() != 3
            || detTelekinesisDmgPerLevel() != 1
            || detLiveoakOneAtATime() != 1
            || detElementalAuraElementCount() != 4
            || detExampleAdvantageRollDie() != 10
            || detExClairvoyanceLevel() != 3
            || detExCalvinClairvoyancePR() != 12
            || detExClairvoyanceMv() != 5
            || detExWithdrawLevel() != 2
            || detExWithdrawPR() != 11
            || detExWithdrawMv() != 1
            || detExMonsterSumLevel() != 4
            || detExMonsterSumPR() != 13
            || detExMonsterSumMv() != 3
            || detExDispelPR() != 12
            || detExDispelMv() != 4
            || detExMagicMissilePR() != 10
            || detExMagicMissileMv() != 5
            || detExAnimatePR() != 15
            || detExAnimateMv() != 3
            || detExCalvinRoll() != 20
            || detExDelsenoraRoll() != 9
            || detT25RowCount() != 5
            || detT26RowCount() != 5
            || detT27RowCount() != 5
            || detFriendlyBandCount() != 4
            || detDeathBandCount() != 5
            || !detArenaRestartOnDisturbance()
            || !detMediatorProtectiveRequired()
            || !detContributedMustBeMemorized()
            || !detContributedLostAsCast()
            || !detContributionSecret()
            || !detMediatorKnowsAll()
            || !detCharmCannotConsent()
            || !detThreatConsentValid()
            || !detGeasSubjectFreeToRefuse()
            || !detBalanceCapWeakerLevel()
            || !detDuelistSpacesNotCounted()
            || !detOnlyHighestFactored()
            || !detFirstRoundNoMovement()
            || !detAdvantageMovesFirst()
            || !detAdvantageHighestSingleSpell()
            || !detAdvantageShiftsOnSpellDeath()
            || !detNoShiftOnSaveOrPR()
            || !detSpellNeverLeavesArena()
            || !detNoSelfCasting()
            || !detSpellsAffectConstructs()
            || !detDetectIdentifies()
            || !detDefensiveMayStay()
            || !detMustMoveOneSpace()
            || !detCastingSimultaneous()
            || !detCastingNotDisrupted()
            || !detArenaSuppliesComponents()
            || !detSpellAppearsAhead()
            || !detNoMoveOnCastRound()
            || !detAttackMustFightDefense()
            || !detDefenseMustFightAttack()
            || !detLeechMustFightLeech()
            || !detLeechSaveHalf()
            || !detADMustFightAD()
            || !detADSaveOrCombat()
            || !detMissileIgnoresMost()
            || !detMoveOrderClosestFirst()
            || !detFriendlyStackingOk()
            || !detNoBackwardMove()
            || !detFailIfHigher()
            || !detLockOnBothFail()
            || !detLockOnEqualPRTie()
            || !detHigherRollWins()
            || !detWinningSpellFinishesMove()
            || !detOneCombatPerPairPerRound()
            || !detLockedBlockPassage()
            || !detHighestMVCheckedFirst()
            || !detDisadvantagedAnnouncesType()
            || !detCharMoveBackward()
            || !detSavingThrowsByCasterLevel()
            || !detAbilityBonusesNeverApply()
            || !detZeroHpLoses()
            || !detLingeringBlocksButCounters()
            || !detPositiveHpNeverRemoved()
            || !detCharLockDestroysAttacker()
            || !detCounterBothDestroyed()
            || !detUnlimitedCountersPerRound()
            || !detDefenseVanishesAtOpponent()
            || !detPushIntoSpellTriggers()
            || !detNoCastWhileEngaged()
            || !detPowerCheckIdentify()
            || !detSpellRevealedAtSquare()
            || !detNoEquipmentInArena()
            || !detStoringItemsWork()
            || !detWandsUsuallyBanned()
            || !detDeviceLevelSaves()
            || !detProtectiveBonusesVsSpellsOnly()
            || !detAcNoEffect()
            || !detAttackBonusPersonalOnly()
            || !detArenaBlockersAbsolute()
            || !detSpecialistSavesApply()
            || !detWildSurgesNever()
            || !detLevelVariationBothWildMages()
            || !detElementalistBoostBothElementalists()
            || !detEndOnNoSpellsOrHp()
            || !detAutoEndWhenMet()
            || !detSurrenderAlwaysAllowed()
            || !detSpellLossAsCast()
            || !detContributedAlwaysLost()
            || !detWinnerCapAtCast()
            || !detExcessPermanentIfDeath()
            || !detMassiveDamageNA()
            || !detCharmIgnoresResistances()
            || !detUnconsciousKillable()
            || !detBlownEquipmentStays()
            || !detDisintegrateNoRegeneration()
            || !detBand4EquipmentSaveFire()
            || !detBand5EquipmentSaveLightning()
            || !detServiceGeasLiftNeeds()
            || !detWinnerTempCappedAtDuel()
            || !detInterferenceEndsDuel()
            || !detBothVictorsOnInterference()
            || !detTouchCombatantsEnds()
            || !detMediatorAttacksNoEffect()
            || !detMediatorChoosesIsolation()
            || !detMediatorSearchesContraband()
            || !detMediatorTouchEnds()
            || !detMediatorNoCompulsion()
            || !detMediatorMayIncludeSelf()
            || !detMentalTemporaryOnly()
            || !detNeverCompelledToLeave()
            || !detSummoningCounterOnly()
            || !detSummoningLockPersists()
            || !detIllusionAnyType()
            || !detIllusionTypeFixedAtCast()
            || !detIllusionDefenseLockDestroys()
            || !detReversedOpposite()
            || !detReverseCountersReverse()
            || !detTeleportIgnoresBarrierLocks()
            || !detTeleportCounterLockDestroys()
            || !detWishNoAgingUnlessLost()
            || !detHasteSlowMutual()
            || !detShieldDefeatsMagicMissile()
            || !detTransmuteDefeatsWallOfStone()
            || !detFlyLevitateCounterTransmute()
            || !detTrueSeeingDefeatsIllusions()
            || !detStabilizeIneffective()
            || !detMindBlankCountersLeeches()
            || !detPermanencyNoConLoss()
            || !detNeutralizePoisonCounters()
            || !detRemoveParalysisCounters()
            || !detRaiseDeadCountersDamage()
            || !detCrystalbrittleDefeatsMetal()
            || !detDisintegrateDefeatsBarriers()
            || !detDispelDestroysOnLoss()
            || !detExWithdrawForcesCombat()
            || !detExArenaTenSpaces()
        )
            ++bad;
        // the detT25Grid grid
        int CT37[5][5] = {
            {0,1,1,2,0},
            {1,0,1,2,3},
            {1,1,1,2,2},
            {2,2,2,1,0},
            {0,3,2,0,0},
            };
        for (int b = 0;
             b < detT25RowCount();
             ++b) {
            int vals[5];
            vals[0] = detT25VsA(b);
            vals[1] = detT25VsD(b);
            vals[2] = detT25VsAD(b);
            vals[3] = detT25VsL(b);
            vals[4] = detT25VsM(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT37[b][c])
                    ++bad;
            }
        }
        // the detT26Grid grid
        int CT38[5][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            };
        for (int b = 0;
             b < detT26RowCount();
             ++b) {
            int vals[1];
            vals[0] = detT26Mv(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CT38[b][c])
                    ++bad;
            }
        }
        // the detT27Grid grid
        int CT39[5][2] = {
            {0,9},
            {1,10},
            {2,11},
            {3,12},
            {4,13},
            };
        for (int b = 0;
             b < detT27RowCount();
             ++b) {
            int vals[2];
            vals[0] = detT27Bonus(b);
            vals[1] = detT27PowerScore(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT39[b][c])
                    ++bad;
            }
        }
        // the detFriendlyStakes grid
        int CT40[4][6] = {
            {-99,-99,-99,-99,-99,-99},
            {2,6,2,4,-99,-99},
            {4,6,4,4,1,6},
            {8,6,8,4,4,6},
            };
        int nT40[6] = {0,0,0,0,0,0};
        int eT40[6] = {1,1,1,1,2,2};
        for (int b = 0;
             b < detFriendlyBandCount();
             ++b) {
            int vals[6];
            vals[0] = detFriendlyLoserDmgDice(b);
            vals[1] = detFriendlyLoserDmgSize(b);
            vals[2] = detFriendlyLoserSpellDice(b);
            vals[3] = detFriendlyLoserSpellSize(b);
            vals[4] = detFriendlyWinnerSpellDice(b);
            vals[5] = detFriendlyWinnerSpellSize(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT40[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT40[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nT40[c] != eT40[c])
                ++bad;
        // the detDeathStakes grid
        int CT41[5][8] = {
            {2,6,-99,-99,-99,-99,-99,-99},
            {4,6,4,4,1,6,-99,-99},
            {6,6,8,4,2,6,1,6},
            {8,6,12,4,4,6,2,6},
            {10,6,18,4,2,6,4,6},
            };
        int nT41[8] = {0,0,0,0,0,0,0,0};
        int eT41[8] = {0,0,1,1,1,1,2,2};
        for (int b = 0;
             b < detDeathBandCount();
             ++b) {
            int vals[8];
            vals[0] = detDeathLoserDmgDice(b);
            vals[1] = detDeathLoserDmgSize(b);
            vals[2] = detDeathLoserSpellDice(b);
            vals[3] = detDeathLoserSpellSize(b);
            vals[4] = detDeathWinnerSpellDice(b);
            vals[5] = detDeathWinnerSpellSize(b);
            vals[6] = detDeathWinnerTempDice(b);
            vals[7] = detDeathWinnerTempSize(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CT41[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT41[c];
            }
        }
        for (int c = 0; c < 8; ++c)
            if (nT41[c] != eT41[c])
                ++bad;
        // the detServiceLadder band-for boundaries
    if (detServiceLadder(5) != 0
            || detServiceLadder(6) != 0
            || detServiceLadder(12) != 1
            || detServiceLadder(7) != 1
            || detServiceLadder(18) != 2
            || detServiceLadder(13) != 2
            || detServiceLadder(19) != 3
        )
            ++bad;
        // the detArenaChantTurns pin
    if (detArenaChantTurns() != 1
        )
            ++bad;
        // the detBalanceExampleWizardLevel pin
    if (detBalanceExampleWizardLevel() != 7
        )
            ++bad;
        // the detBalanceExamplePriestLevel pin
    if (detBalanceExamplePriestLevel() != 12
        )
            ++bad;
        // the detBalanceExampleCapLevel pin
    if (detBalanceExampleCapLevel() != 7
        )
            ++bad;
        // the detArenaCorridorMinSpaces pin
    if (detArenaCorridorMinSpaces() != 12
        )
            ++bad;
        // the detArenaCorridorMaxSpaces pin
    if (detArenaCorridorMaxSpaces() != 30
        )
            ++bad;
        // the detArenaBaseSpaces pin
    if (detArenaBaseSpaces() != 10
        )
            ++bad;
        // the detArenaMaxIntervening pin
    if (detArenaMaxIntervening() != 30
        )
            ++bad;
        // the detArenaLargestTotal pin
    if (detArenaLargestTotal() != 32
        )
            ++bad;
        // the detArenaExampleSpaces pin
    if (detArenaExampleSpaces() != 18
        )
            ++bad;
        // the detArenaExampleSpellA pin
    if (detArenaExampleSpellA() != 5
        )
            ++bad;
        // the detArenaExampleSpellB pin
    if (detArenaExampleSpellB() != 3
        )
            ++bad;
        // the detRoundSteps pin
    if (detRoundSteps() != 4
        )
            ++bad;
        // the detTieAdvantageDie pin
    if (detTieAdvantageDie() != 10
        )
            ++bad;
        // the detSpellTypes pin
    if (detSpellTypes() != 5
        )
            ++bad;
        // the detPRBase pin
    if (detPRBase() != 9
        )
            ++bad;
        // the detFireballPR pin
    if (detFireballPR() != 12
        )
            ++bad;
        // the detOnlyOneDefensiveStay pin
    if (detOnlyOneDefensiveStay() != 1
        )
            ++bad;
        // the detLeechDmgDie pin
    if (detLeechDmgDie() != 6
        )
            ++bad;
        // the detLeechDmgPerLevel pin
    if (detLeechDmgPerLevel() != 1
        )
            ++bad;
        // the detADDmgDie pin
    if (detADDmgDie() != 6
        )
            ++bad;
        // the detADDmgPerLevel pin
    if (detADDmgPerLevel() != 1
        )
            ++bad;
        // the detMvTouch pin
    if (detMvTouch() != 1
        )
            ++bad;
        // the detMvShort pin
    if (detMvShort() != 2
        )
            ++bad;
        // the detMvMedium pin
    if (detMvMedium() != 3
        )
            ++bad;
        // the detMvLong pin
    if (detMvLong() != 4
        )
            ++bad;
        // the detMvVeryLong pin
    if (detMvVeryLong() != 5
        )
            ++bad;
        // the detFireball5thMv pin
    if (detFireball5thMv() != 4
        )
            ++bad;
        // the detFireball15thMv pin
    if (detFireball15thMv() != 5
        )
            ++bad;
        // the detCombatDie pin
    if (detCombatDie() != 20
        )
            ++bad;
        // the detRaryCharmPR pin
    if (detRaryCharmPR() != 10
        )
            ++bad;
        // the detSertenCurePR pin
    if (detSertenCurePR() != 10
        )
            ++bad;
        // the detRaryRoll pin
    if (detRaryRoll() != 12
        )
            ++bad;
        // the detSertenRoll pin
    if (detSertenRoll() != 1
        )
            ++bad;
        // the detRaryAltRoll pin
    if (detRaryAltRoll() != 9
        )
            ++bad;
        // the detLockExampleRaryRoll pin
    if (detLockExampleRaryRoll() != 20
        )
            ++bad;
        // the detCharMoveOneSpace pin
    if (detCharMoveOneSpace() != 1
        )
            ++bad;
        // the detCharPRBase pin
    if (detCharPRBase() != 9
        )
            ++bad;
        // the detOneCounterPerIncoming pin
    if (detOneCounterPerIncoming() != 1
        )
            ++bad;
        // the detCharVsCharDmgDie pin
    if (detCharVsCharDmgDie() != 6
        )
            ++bad;
        // the detCharVsCharPushDie pin
    if (detCharVsCharPushDie() != 4
        )
            ++bad;
        // the detScrollProtectionPR pin
    if (detScrollProtectionPR() != 15
        )
            ++bad;
        // the detScrollProtectionMv pin
    if (detScrollProtectionMv() != 1
        )
            ++bad;
        // the detItemClassPrepTurns pin
    if (detItemClassPrepTurns() != 1
        )
            ++bad;
        // the detSpecificItemPrepTurns pin
    if (detSpecificItemPrepTurns() != 1
        )
            ++bad;
        // the detItemLeechMaxDice pin
    if (detItemLeechMaxDice() != 6
        )
            ++bad;
        // the detStaffLeechMaxDice pin
    if (detStaffLeechMaxDice() != 8
        )
            ++bad;
        // the detOtherItemLeechMaxDice pin
    if (detOtherItemLeechMaxDice() != 9
        )
            ++bad;
        // the detExamplePowerScore pin
    if (detExamplePowerScore() != 11
        )
            ++bad;
        // the detExampleArmorBonus pin
    if (detExampleArmorBonus() != 2
        )
            ++bad;
        // the detExampleRingBonus pin
    if (detExampleRingBonus() != 1
        )
            ++bad;
        // the detExampleAdjustedPS pin
    if (detExampleAdjustedPS() != 14
        )
            ++bad;
        // the detPreexistingPrepTurns pin
    if (detPreexistingPrepTurns() != 1
        )
            ++bad;
        // the detSpecialistPrepTurns pin
    if (detSpecialistPrepTurns() != 1
        )
            ++bad;
        // the detOppositionSchoolPRBonus pin
    if (detOppositionSchoolPRBonus() != 1
        )
            ++bad;
        // the detDispelBasePR pin
    if (detDispelBasePR() != 12
        )
            ++bad;
        // the detDispelVsIllusionistPR pin
    if (detDispelVsIllusionistPR() != 13
        )
            ++bad;
        // the detUnseenServantPR pin
    if (detUnseenServantPR() != 10
        )
            ++bad;
        // the detVariedUnseenServantPR pin
    if (detVariedUnseenServantPR() != 5
        )
            ++bad;
        // the detVariedFireballPR pin
    if (detVariedFireballPR() != 7
        )
            ++bad;
        // the detVariedFireballDmgDice pin
    if (detVariedFireballDmgDice() != 8
        )
            ++bad;
        // the detVariedFireballMv pin
    if (detVariedFireballMv() != 4
        )
            ++bad;
        // the detExtraCondPrepTurns pin
    if (detExtraCondPrepTurns() != 1
        )
            ++bad;
        // the detUnequalCondPrepTurns pin
    if (detUnequalCondPrepTurns() != 2
        )
            ++bad;
        // the detExcessAbilityLoss pin
    if (detExcessAbilityLoss() != 1
        )
            ++bad;
        // the detTempDmgRegenPerRound pin
    if (detTempDmgRegenPerRound() != 1
        )
            ++bad;
        // the detTempDeathAtMinus pin
    if (detTempDeathAtMinus() != 10
        )
            ++bad;
        // the detUnconsciousTurnsDice pin
    if (detUnconsciousTurnsDice() != 2
        )
            ++bad;
        // the detUnconsciousTurnsSize pin
    if (detUnconsciousTurnsSize() != 6
        )
            ++bad;
        // the detPlaneBlowBand4 pin
    if (detPlaneBlowBand4() != 20
        )
            ++bad;
        // the detPlaneBlowBand5 pin
    if (detPlaneBlowBand5() != 40
        )
            ++bad;
        // the detDisintegrateChance pin
    if (detDisintegrateChance() != 50
        )
            ++bad;
        // the detSummoningDmgDie pin
    if (detSummoningDmgDie() != 6
        )
            ++bad;
        // the detSummoningDmgPerLevel pin
    if (detSummoningDmgPerLevel() != 1
        )
            ++bad;
        // the detIllusionDmgDie pin
    if (detIllusionDmgDie() != 6
        )
            ++bad;
        // the detIllusionDmgPerLevel pin
    if (detIllusionDmgPerLevel() != 1
        )
            ++bad;
        // the detDemishadowFailDmgDice pin
    if (detDemishadowFailDmgDice() != 10
        )
            ++bad;
        // the detDemishadowCounterDmgDice pin
    if (detDemishadowCounterDmgDice() != 5
        )
            ++bad;
        // the detDemishadowSaveDmgDice pin
    if (detDemishadowSaveDmgDice() != 4
        )
            ++bad;
        // the detDemishadowSaveCounterDmgDice pin
    if (detDemishadowSaveCounterDmgDice() != 2
        )
            ++bad;
        // the detShadowFailDmgDice pin
    if (detShadowFailDmgDice() != 10
        )
            ++bad;
        // the detShadowCounterDmgDice pin
    if (detShadowCounterDmgDice() != 5
        )
            ++bad;
        // the detShadowSecondSaveDmgDice pin
    if (detShadowSecondSaveDmgDice() != 1
        )
            ++bad;
        // the detShadowFailCounterDmgDice pin
    if (detShadowFailCounterDmgDice() != 2
        )
            ++bad;
        // the detDemishadowMonDmgDice pin
    if (detDemishadowMonDmgDice() != 5
        )
            ++bad;
        // the detDemishadowMonSaveDmgDice pin
    if (detDemishadowMonSaveDmgDice() != 2
        )
            ++bad;
        // the detEnergyDrainLevels pin
    if (detEnergyDrainLevels() != 2
        )
            ++bad;
        // the detEnervationDivisor pin
    if (detEnervationDivisor() != 4
        )
            ++bad;
        // the detEarthquakeDmgDice pin
    if (detEarthquakeDmgDice() != 5
        )
            ++bad;
        // the detEarthquakeDmgSize pin
    if (detEarthquakeDmgSize() != 10
        )
            ++bad;
        // the detEarthquakeCounterCount pin
    if (detEarthquakeCounterCount() != 6
        )
            ++bad;
        // the detFireSeedsDmgDice pin
    if (detFireSeedsDmgDice() != 8
        )
            ++bad;
        // the detFireSeedsSaveDice pin
    if (detFireSeedsSaveDice() != 4
        )
            ++bad;
        // the detMagicalStoneDmgDice pin
    if (detMagicalStoneDmgDice() != 3
        )
            ++bad;
        // the detMagicalStoneDmgSize pin
    if (detMagicalStoneDmgSize() != 4
        )
            ++bad;
        // the detMeteorsPerRound pin
    if (detMeteorsPerRound() != 5
        )
            ++bad;
        // the detMeteorDmgDie pin
    if (detMeteorDmgDie() != 4
        )
            ++bad;
        // the detMeteorDmgBonus pin
    if (detMeteorDmgBonus() != 1
        )
            ++bad;
        // the detMomentBonus pin
    if (detMomentBonus() != 4
        )
            ++bad;
        // the detFreezingSphereMissileDice pin
    if (detFreezingSphereMissileDice() != 6
        )
            ++bad;
        // the detFreezingSpherePerLevelDie pin
    if (detFreezingSpherePerLevelDie() != 4
        )
            ++bad;
        // the detFreezingSpherePerLevelBonus pin
    if (detFreezingSpherePerLevelBonus() != 2
        )
            ++bad;
        // the detFreezingSphereMaxDice pin
    if (detFreezingSphereMaxDice() != 10
        )
            ++bad;
        // the detRainbowFirstMissiles pin
    if (detRainbowFirstMissiles() != 4
        )
            ++bad;
        // the detRainbowExtraMissiles pin
    if (detRainbowExtraMissiles() != 3
        )
            ++bad;
        // the detRainbowDmgDie pin
    if (detRainbowDmgDie() != 6
        )
            ++bad;
        // the detRainbowDmgBonus pin
    if (detRainbowDmgBonus() != 2
        )
            ++bad;
        // the detHeatMetalDmgPerRound pin
    if (detHeatMetalDmgPerRound() != 3
        )
            ++bad;
        // the detHeatMetalMissileDmg pin
    if (detHeatMetalMissileDmg() != 1
        )
            ++bad;
        // the detHolyWordPSReduction pin
    if (detHolyWordPSReduction() != 2
        )
            ++bad;
        // the detChantCastRounds pin
    if (detChantCastRounds() != 2
        )
            ++bad;
        // the detFirePurgeCastRounds pin
    if (detFirePurgeCastRounds() != 10
        )
            ++bad;
        // the detFirePurgeDisruptRounds pin
    if (detFirePurgeDisruptRounds() != 9
        )
            ++bad;
        // the detWishDuelDmgDice pin
    if (detWishDuelDmgDice() != 10
        )
            ++bad;
        // the detLimitedWishCounterMaxLevel pin
    if (detLimitedWishCounterMaxLevel() != 6
        )
            ++bad;
        // the detGlobeLockMaxLevel pin
    if (detGlobeLockMaxLevel() != 4
        )
            ++bad;
        // the detMinorGlobeLockMaxLevel pin
    if (detMinorGlobeLockMaxLevel() != 3
        )
            ++bad;
        // the detSpiritualHammerDmgDie pin
    if (detSpiritualHammerDmgDie() != 6
        )
            ++bad;
        // the detShillelaghDmgDie pin
    if (detShillelaghDmgDie() != 6
        )
            ++bad;
        // the detWateryDoubleDmgDice pin
    if (detWateryDoubleDmgDice() != 3
        )
            ++bad;
        // the detTelekinesisDmgPerLevel pin
    if (detTelekinesisDmgPerLevel() != 1
        )
            ++bad;
        // the detLiveoakOneAtATime pin
    if (detLiveoakOneAtATime() != 1
        )
            ++bad;
        // the detElementalAuraElementCount pin
    if (detElementalAuraElementCount() != 4
        )
            ++bad;
        // the detExampleAdvantageRollDie pin
    if (detExampleAdvantageRollDie() != 10
        )
            ++bad;
        // the detExClairvoyanceLevel pin
    if (detExClairvoyanceLevel() != 3
        )
            ++bad;
        // the detExCalvinClairvoyancePR pin
    if (detExCalvinClairvoyancePR() != 12
        )
            ++bad;
        // the detExClairvoyanceMv pin
    if (detExClairvoyanceMv() != 5
        )
            ++bad;
        // the detExWithdrawLevel pin
    if (detExWithdrawLevel() != 2
        )
            ++bad;
        // the detExWithdrawPR pin
    if (detExWithdrawPR() != 11
        )
            ++bad;
        // the detExWithdrawMv pin
    if (detExWithdrawMv() != 1
        )
            ++bad;
        // the detExMonsterSumLevel pin
    if (detExMonsterSumLevel() != 4
        )
            ++bad;
        // the detExMonsterSumPR pin
    if (detExMonsterSumPR() != 13
        )
            ++bad;
        // the detExMonsterSumMv pin
    if (detExMonsterSumMv() != 3
        )
            ++bad;
        // the detExDispelPR pin
    if (detExDispelPR() != 12
        )
            ++bad;
        // the detExDispelMv pin
    if (detExDispelMv() != 4
        )
            ++bad;
        // the detExMagicMissilePR pin
    if (detExMagicMissilePR() != 10
        )
            ++bad;
        // the detExMagicMissileMv pin
    if (detExMagicMissileMv() != 5
        )
            ++bad;
        // the detExAnimatePR pin
    if (detExAnimatePR() != 15
        )
            ++bad;
        // the detExAnimateMv pin
    if (detExAnimateMv() != 3
        )
            ++bad;
        // the detExCalvinRoll pin
    if (detExCalvinRoll() != 20
        )
            ++bad;
        // the detExDelsenoraRoll pin
    if (detExDelsenoraRoll() != 9
        )
            ++bad;
        // the detT25RowCount pin
    if (detT25RowCount() != 5
        )
            ++bad;
        // the detT26RowCount pin
    if (detT26RowCount() != 5
        )
            ++bad;
        // the detT27RowCount pin
    if (detT27RowCount() != 5
        )
            ++bad;
        // the detFriendlyBandCount pin
    if (detFriendlyBandCount() != 4
        )
            ++bad;
        // the detDeathBandCount pin
    if (detDeathBandCount() != 5
        )
            ++bad;
        // the detArenaRestartOnDisturbance pin
    if (detArenaRestartOnDisturbance() != 1
        )
            ++bad;
        // the detMediatorProtectiveRequired pin
    if (detMediatorProtectiveRequired() != 1
        )
            ++bad;
        // the detContributedMustBeMemorized pin
    if (detContributedMustBeMemorized() != 1
        )
            ++bad;
        // the detContributedLostAsCast pin
    if (detContributedLostAsCast() != 1
        )
            ++bad;
        // the detContributionSecret pin
    if (detContributionSecret() != 1
        )
            ++bad;
        // the detMediatorKnowsAll pin
    if (detMediatorKnowsAll() != 1
        )
            ++bad;
        // the detCharmCannotConsent pin
    if (detCharmCannotConsent() != 1
        )
            ++bad;
        // the detThreatConsentValid pin
    if (detThreatConsentValid() != 1
        )
            ++bad;
        // the detGeasSubjectFreeToRefuse pin
    if (detGeasSubjectFreeToRefuse() != 1
        )
            ++bad;
        // the detBalanceCapWeakerLevel pin
    if (detBalanceCapWeakerLevel() != 1
        )
            ++bad;
        // the detDuelistSpacesNotCounted pin
    if (detDuelistSpacesNotCounted() != 1
        )
            ++bad;
        // the detOnlyHighestFactored pin
    if (detOnlyHighestFactored() != 1
        )
            ++bad;
        // the detFirstRoundNoMovement pin
    if (detFirstRoundNoMovement() != 1
        )
            ++bad;
        // the detAdvantageMovesFirst pin
    if (detAdvantageMovesFirst() != 1
        )
            ++bad;
        // the detAdvantageHighestSingleSpell pin
    if (detAdvantageHighestSingleSpell() != 1
        )
            ++bad;
        // the detAdvantageShiftsOnSpellDeath pin
    if (detAdvantageShiftsOnSpellDeath() != 1
        )
            ++bad;
        // the detNoShiftOnSaveOrPR pin
    if (detNoShiftOnSaveOrPR() != 1
        )
            ++bad;
        // the detSpellNeverLeavesArena pin
    if (detSpellNeverLeavesArena() != 1
        )
            ++bad;
        // the detNoSelfCasting pin
    if (detNoSelfCasting() != 1
        )
            ++bad;
        // the detSpellsAffectConstructs pin
    if (detSpellsAffectConstructs() != 1
        )
            ++bad;
        // the detDetectIdentifies pin
    if (detDetectIdentifies() != 1
        )
            ++bad;
        // the detDefensiveMayStay pin
    if (detDefensiveMayStay() != 1
        )
            ++bad;
        // the detMustMoveOneSpace pin
    if (detMustMoveOneSpace() != 1
        )
            ++bad;
        // the detCastingSimultaneous pin
    if (detCastingSimultaneous() != 1
        )
            ++bad;
        // the detCastingNotDisrupted pin
    if (detCastingNotDisrupted() != 1
        )
            ++bad;
        // the detArenaSuppliesComponents pin
    if (detArenaSuppliesComponents() != 1
        )
            ++bad;
        // the detSpellAppearsAhead pin
    if (detSpellAppearsAhead() != 1
        )
            ++bad;
        // the detNoMoveOnCastRound pin
    if (detNoMoveOnCastRound() != 1
        )
            ++bad;
        // the detAttackMustFightDefense pin
    if (detAttackMustFightDefense() != 1
        )
            ++bad;
        // the detDefenseMustFightAttack pin
    if (detDefenseMustFightAttack() != 1
        )
            ++bad;
        // the detLeechMustFightLeech pin
    if (detLeechMustFightLeech() != 1
        )
            ++bad;
        // the detLeechSaveHalf pin
    if (detLeechSaveHalf() != 1
        )
            ++bad;
        // the detADMustFightAD pin
    if (detADMustFightAD() != 1
        )
            ++bad;
        // the detADSaveOrCombat pin
    if (detADSaveOrCombat() != 1
        )
            ++bad;
        // the detMissileIgnoresMost pin
    if (detMissileIgnoresMost() != 1
        )
            ++bad;
        // the detMoveOrderClosestFirst pin
    if (detMoveOrderClosestFirst() != 1
        )
            ++bad;
        // the detFriendlyStackingOk pin
    if (detFriendlyStackingOk() != 1
        )
            ++bad;
        // the detNoBackwardMove pin
    if (detNoBackwardMove() != 1
        )
            ++bad;
        // the detFailIfHigher pin
    if (detFailIfHigher() != 1
        )
            ++bad;
        // the detLockOnBothFail pin
    if (detLockOnBothFail() != 1
        )
            ++bad;
        // the detLockOnEqualPRTie pin
    if (detLockOnEqualPRTie() != 1
        )
            ++bad;
        // the detHigherRollWins pin
    if (detHigherRollWins() != 1
        )
            ++bad;
        // the detWinningSpellFinishesMove pin
    if (detWinningSpellFinishesMove() != 1
        )
            ++bad;
        // the detOneCombatPerPairPerRound pin
    if (detOneCombatPerPairPerRound() != 1
        )
            ++bad;
        // the detLockedBlockPassage pin
    if (detLockedBlockPassage() != 1
        )
            ++bad;
        // the detHighestMVCheckedFirst pin
    if (detHighestMVCheckedFirst() != 1
        )
            ++bad;
        // the detDisadvantagedAnnouncesType pin
    if (detDisadvantagedAnnouncesType() != 1
        )
            ++bad;
        // the detCharMoveBackward pin
    if (detCharMoveBackward() != 1
        )
            ++bad;
        // the detSavingThrowsByCasterLevel pin
    if (detSavingThrowsByCasterLevel() != 1
        )
            ++bad;
        // the detAbilityBonusesNeverApply pin
    if (detAbilityBonusesNeverApply() != 1
        )
            ++bad;
        // the detZeroHpLoses pin
    if (detZeroHpLoses() != 1
        )
            ++bad;
        // the detLingeringBlocksButCounters pin
    if (detLingeringBlocksButCounters() != 1
        )
            ++bad;
        // the detPositiveHpNeverRemoved pin
    if (detPositiveHpNeverRemoved() != 1
        )
            ++bad;
        // the detCharLockDestroysAttacker pin
    if (detCharLockDestroysAttacker() != 1
        )
            ++bad;
        // the detCounterBothDestroyed pin
    if (detCounterBothDestroyed() != 1
        )
            ++bad;
        // the detUnlimitedCountersPerRound pin
    if (detUnlimitedCountersPerRound() != 1
        )
            ++bad;
        // the detDefenseVanishesAtOpponent pin
    if (detDefenseVanishesAtOpponent() != 1
        )
            ++bad;
        // the detPushIntoSpellTriggers pin
    if (detPushIntoSpellTriggers() != 1
        )
            ++bad;
        // the detNoCastWhileEngaged pin
    if (detNoCastWhileEngaged() != 1
        )
            ++bad;
        // the detPowerCheckIdentify pin
    if (detPowerCheckIdentify() != 1
        )
            ++bad;
        // the detSpellRevealedAtSquare pin
    if (detSpellRevealedAtSquare() != 1
        )
            ++bad;
        // the detNoEquipmentInArena pin
    if (detNoEquipmentInArena() != 1
        )
            ++bad;
        // the detStoringItemsWork pin
    if (detStoringItemsWork() != 1
        )
            ++bad;
        // the detWandsUsuallyBanned pin
    if (detWandsUsuallyBanned() != 1
        )
            ++bad;
        // the detDeviceLevelSaves pin
    if (detDeviceLevelSaves() != 1
        )
            ++bad;
        // the detProtectiveBonusesVsSpellsOnly pin
    if (detProtectiveBonusesVsSpellsOnly() != 1
        )
            ++bad;
        // the detAcNoEffect pin
    if (detAcNoEffect() != 1
        )
            ++bad;
        // the detAttackBonusPersonalOnly pin
    if (detAttackBonusPersonalOnly() != 1
        )
            ++bad;
        // the detArenaBlockersAbsolute pin
    if (detArenaBlockersAbsolute() != 1
        )
            ++bad;
        // the detSpecialistSavesApply pin
    if (detSpecialistSavesApply() != 1
        )
            ++bad;
        // the detWildSurgesNever pin
    if (detWildSurgesNever() != 1
        )
            ++bad;
        // the detLevelVariationBothWildMages pin
    if (detLevelVariationBothWildMages() != 1
        )
            ++bad;
        // the detElementalistBoostBothElementalists pin
    if (detElementalistBoostBothElementalists() != 1
        )
            ++bad;
        // the detEndOnNoSpellsOrHp pin
    if (detEndOnNoSpellsOrHp() != 1
        )
            ++bad;
        // the detAutoEndWhenMet pin
    if (detAutoEndWhenMet() != 1
        )
            ++bad;
        // the detSurrenderAlwaysAllowed pin
    if (detSurrenderAlwaysAllowed() != 1
        )
            ++bad;
        // the detSpellLossAsCast pin
    if (detSpellLossAsCast() != 1
        )
            ++bad;
        // the detContributedAlwaysLost pin
    if (detContributedAlwaysLost() != 1
        )
            ++bad;
        // the detWinnerCapAtCast pin
    if (detWinnerCapAtCast() != 1
        )
            ++bad;
        // the detExcessPermanentIfDeath pin
    if (detExcessPermanentIfDeath() != 1
        )
            ++bad;
        // the detMassiveDamageNA pin
    if (detMassiveDamageNA() != 1
        )
            ++bad;
        // the detCharmIgnoresResistances pin
    if (detCharmIgnoresResistances() != 1
        )
            ++bad;
        // the detUnconsciousKillable pin
    if (detUnconsciousKillable() != 1
        )
            ++bad;
        // the detBlownEquipmentStays pin
    if (detBlownEquipmentStays() != 1
        )
            ++bad;
        // the detDisintegrateNoRegeneration pin
    if (detDisintegrateNoRegeneration() != 1
        )
            ++bad;
        // the detBand4EquipmentSaveFire pin
    if (detBand4EquipmentSaveFire() != 1
        )
            ++bad;
        // the detBand5EquipmentSaveLightning pin
    if (detBand5EquipmentSaveLightning() != 1
        )
            ++bad;
        // the detServiceGeasLiftNeeds pin
    if (detServiceGeasLiftNeeds() != 1
        )
            ++bad;
        // the detWinnerTempCappedAtDuel pin
    if (detWinnerTempCappedAtDuel() != 1
        )
            ++bad;
        // the detInterferenceEndsDuel pin
    if (detInterferenceEndsDuel() != 1
        )
            ++bad;
        // the detBothVictorsOnInterference pin
    if (detBothVictorsOnInterference() != 1
        )
            ++bad;
        // the detTouchCombatantsEnds pin
    if (detTouchCombatantsEnds() != 1
        )
            ++bad;
        // the detMediatorAttacksNoEffect pin
    if (detMediatorAttacksNoEffect() != 1
        )
            ++bad;
        // the detMediatorChoosesIsolation pin
    if (detMediatorChoosesIsolation() != 1
        )
            ++bad;
        // the detMediatorSearchesContraband pin
    if (detMediatorSearchesContraband() != 1
        )
            ++bad;
        // the detMediatorTouchEnds pin
    if (detMediatorTouchEnds() != 1
        )
            ++bad;
        // the detMediatorNoCompulsion pin
    if (detMediatorNoCompulsion() != 1
        )
            ++bad;
        // the detMediatorMayIncludeSelf pin
    if (detMediatorMayIncludeSelf() != 1
        )
            ++bad;
        // the detMentalTemporaryOnly pin
    if (detMentalTemporaryOnly() != 1
        )
            ++bad;
        // the detNeverCompelledToLeave pin
    if (detNeverCompelledToLeave() != 1
        )
            ++bad;
        // the detSummoningCounterOnly pin
    if (detSummoningCounterOnly() != 1
        )
            ++bad;
        // the detSummoningLockPersists pin
    if (detSummoningLockPersists() != 1
        )
            ++bad;
        // the detIllusionAnyType pin
    if (detIllusionAnyType() != 1
        )
            ++bad;
        // the detIllusionTypeFixedAtCast pin
    if (detIllusionTypeFixedAtCast() != 1
        )
            ++bad;
        // the detIllusionDefenseLockDestroys pin
    if (detIllusionDefenseLockDestroys() != 1
        )
            ++bad;
        // the detReversedOpposite pin
    if (detReversedOpposite() != 1
        )
            ++bad;
        // the detReverseCountersReverse pin
    if (detReverseCountersReverse() != 1
        )
            ++bad;
        // the detTeleportIgnoresBarrierLocks pin
    if (detTeleportIgnoresBarrierLocks() != 1
        )
            ++bad;
        // the detTeleportCounterLockDestroys pin
    if (detTeleportCounterLockDestroys() != 1
        )
            ++bad;
        // the detWishNoAgingUnlessLost pin
    if (detWishNoAgingUnlessLost() != 1
        )
            ++bad;
        // the detHasteSlowMutual pin
    if (detHasteSlowMutual() != 1
        )
            ++bad;
        // the detShieldDefeatsMagicMissile pin
    if (detShieldDefeatsMagicMissile() != 1
        )
            ++bad;
        // the detTransmuteDefeatsWallOfStone pin
    if (detTransmuteDefeatsWallOfStone() != 1
        )
            ++bad;
        // the detFlyLevitateCounterTransmute pin
    if (detFlyLevitateCounterTransmute() != 1
        )
            ++bad;
        // the detTrueSeeingDefeatsIllusions pin
    if (detTrueSeeingDefeatsIllusions() != 1
        )
            ++bad;
        // the detStabilizeIneffective pin
    if (detStabilizeIneffective() != 1
        )
            ++bad;
        // the detMindBlankCountersLeeches pin
    if (detMindBlankCountersLeeches() != 1
        )
            ++bad;
        // the detPermanencyNoConLoss pin
    if (detPermanencyNoConLoss() != 1
        )
            ++bad;
        // the detNeutralizePoisonCounters pin
    if (detNeutralizePoisonCounters() != 1
        )
            ++bad;
        // the detRemoveParalysisCounters pin
    if (detRemoveParalysisCounters() != 1
        )
            ++bad;
        // the detRaiseDeadCountersDamage pin
    if (detRaiseDeadCountersDamage() != 1
        )
            ++bad;
        // the detCrystalbrittleDefeatsMetal pin
    if (detCrystalbrittleDefeatsMetal() != 1
        )
            ++bad;
        // the detDisintegrateDefeatsBarriers pin
    if (detDisintegrateDefeatsBarriers() != 1
        )
            ++bad;
        // the detDispelDestroysOnLoss pin
    if (detDispelDestroysOnLoss() != 1
        )
            ++bad;
        // the detExWithdrawForcesCombat pin
    if (detExWithdrawForcesCombat() != 1
        )
            ++bad;
        // the detExArenaTenSpaces pin
    if (detExArenaTenSpaces() != 1
        )
            ++bad;
        // the PR read: a fireball's level plus nine is 12 (printed p. 100)
    if (detFireballPR() - detPRBase() != 3
        )
            ++bad;
        // the worked-duel clairvoyance: level 3 plus nine is PR 12 (printed
        // p. 116)
    if (detExClairvoyanceLevel() + detPRBase() != 12
            || detExCalvinClairvoyancePR() != 12
        )
            ++bad;
        // the worked-duel withdraw: level 2 plus nine is PR 11 (printed p.
        // 116)
    if (detExWithdrawLevel() + detPRBase() != 11
            || detExWithdrawPR() != 11
        )
            ++bad;
        // the worked-duel monster summoning II: level 4 plus nine is PR 13
        // (printed p. 117)
    if (detExMonsterSumLevel() + detPRBase() != 13
            || detExMonsterSumPR() != 13
        )
            ++bad;
        // the worked-duel magic missile: level 1 plus nine is PR 10 (printed
        // p. 117)
    if (1 + detPRBase() != 10
            || detExMagicMissilePR() != 10
        )
            ++bad;
        // the worked-duel dispel magic and animate object: PRs 12 and 15
        // (printed p. 117)
    if (3 + detPRBase() != 12
            || 6 + detPRBase() != 15
        )
            ++bad;
        // the arena distance: ten spaces plus five plus three is 18 (printed
        // p. 97)
    if (detArenaBaseSpaces() + detArenaExampleSpellA() +
        detArenaExampleSpellB() != 18
        )
            ++bad;
        // the corridor cap: the largest arena is 30 between plus two duelists
        // (printed p. 97)
    if (detArenaMaxIntervening() + 2 != 32
        )
            ++bad;
        // the character power score: base nine plus the Table 27 top bonus is
        // 13 (printed p. 101)
    if (detCharPRBase() + detT27Bonus(4) != 13
            || detT27PowerScore(4) != 13
        )
            ++bad;
        // the Table 27 read: a 15 ability gives bonus 1 and power score 10
        // (printed p. 101)
    if (detT27Bonus(1) != 1
            || detT27PowerScore(1) != 10
        )
            ++bad;
        // the Table 26 read: touch moves one, 101-plus moves five (printed p.
        // 99)
    if (detT26Mv(0) != 1
            || detT26Mv(4) != 5
        )
            ++bad;
        // the Table 25 read: an attack meets a defense - combat; a defense
        // meets a missile - generally ignore (printed p. 99)
    if (detT25VsD(0) != 1
            || detT25VsM(1) != 3
        )
            ++bad;
        // the Table 25 read: leeches fight leeches; missiles pass attacks
        // (printed p. 99)
    if (detT25VsL(3) != 1
            || detT25VsA(4) != 0
        )
            ++bad;
        // the Table 25 read: attack/defense fights attacks, defenses and its
        // own kind (printed p. 99)
    if (detT25VsA(2) != 1
            || detT25VsD(2) != 1
            || detT25VsAD(2) != 1
        )
            ++bad;
        // the friendly ladder: the 7-12 band costs the loser 2d6 and 2d4
        // (printed p. 105)
    if (detFriendlyLoserDmgDice(1) != 2
            || detFriendlyLoserSpellDice(1) != 2
            || detFriendlyWinnerSpellDice(1) != -99
        )
            ++bad;
        // the friendly ladder: the 19-plus band costs the loser 8d6 and 8d4,
        // the winner 4d6 (printed p. 105)
    if (detFriendlyLoserDmgDice(3) != 8
            || detFriendlyLoserSpellDice(3) != 8
            || detFriendlyWinnerSpellDice(3) != 4
        )
            ++bad;
        // the death ladder: the first band is 2d6 damage with the death save
        // (printed p. 105)
    if (detDeathLoserDmgDice(0) != 2
            || detDeathLoserSpellDice(0) != -99
        )
            ++bad;
        // the death ladder: the 23-plus band costs the loser 10d6 and 18d4,
        // the winner 4d6 temporary (printed p. 106)
    if (detDeathLoserDmgDice(4) != 10
            || detDeathLoserSpellDice(4) != 18
            || detDeathWinnerTempDice(4) != 4
        )
            ++bad;
        // the service ladder: 0-6 charm, 7-12 plus suggestion, 13-18 plus
        // geas, 19-plus domination (printed p. 106)
    if (detServiceLadder(3) != 0
            || detServiceLadder(7) != 1
            || detServiceLadder(13) != 2
            || detServiceLadder(19) != 3
        )
            ++bad;
        // the protection read: 11 plus 2 plus 1 is 14 (printed p. 104)
    if (detExamplePowerScore() + detExampleArmorBonus() +
        detExampleRingBonus() != 14
        )
            ++bad;
        // the specialist read: dispel magic at 12 gains one against
        // illusionists for 13 (printed p. 105)
    if (detDispelBasePR() + detOppositionSchoolPRBonus() != 13
        )
            ++bad;
        // the Johan read: unseen servant at 10 minus the 5 variation is 5
        // (printed p. 105)
    if (detUnseenServantPR() - 5 != 5
            || detVariedUnseenServantPR() != 5
        )
            ++bad;
        // the freeze read: 10d4 at +2 per die is the 20-damage cap (printed
        // p. 113)
    if (detFreezingSphereMaxDice() * detFreezingSpherePerLevelBonus() != 20
        )
            ++bad;
        // the chant and fire purge reads: two rounds and ten rounds with nine
        // disruptible (printed pp. 109 and 111)
    if (detChantCastRounds() != 2
            || detFirePurgeCastRounds() - detFirePurgeDisruptRounds() != 1
        )
            ++bad;
        // the enervation read: a 12th-level caster drains three levels
        // (printed p. 111)
    if (12 / detEnervationDivisor() != 3
        )
            ++bad;
        // the lock read: the Rary-Serten pair at PR 10 each ties on equal
        // rolls (printed p. 101)
    if (detRaryCharmPR() != detSertenCurePR()
            || detRaryCharmPR() != 10
        )
            ++bad;
        // the worked duel: Calvin's 20 against a PR-12 clairvoyance fails;
        // Delsenora's 9 against 11 succeeds (printed p. 117)
    if (detExCalvinRoll() <= detExCalvinClairvoyancePR()
            || detExDelsenoraRoll() > detExWithdrawPR()
        )
            ++bad;
        // the balance example: the cap is the wizard's level, seven (printed
        // p. 97)
    if (detBalanceExampleCapLevel() != detBalanceExampleWizardLevel()
            || detBalanceExamplePriestLevel() != 12
        )
            ++bad;
        // the plane blows: 20 percent on the 18-22 band, 40 percent on the
        // 23-plus band (printed p. 106)
    if (detPlaneBlowBand5() - detPlaneBlowBand4() != 20
        )
            ++bad;
        // the disintegration read: half the deaths leave dust (printed p.
        // 107)
    if (detDisintegrateChance() != 50
        )
            ++bad;
        printf("R606 DMO magical-duels audit: bad %d\n", bad);
        if (bad) return 1;
    }
