    // ---- R397: the UA treasure smalls pin
    // audit ----
    // The clean read fills the
    // four scrolls, the seven
    // rings, the seven rods and
    // staves, the two wand holes
    // and the five garbled
    // wands (pp. 91-98) - all
    // four items close.
    {
        using namespace rules;
        int bad = 0;
        // ---- the the protection from cold
        // scroll ----
            if (uapsColdReadingSegs() != 3) ++bad;
            if (uapsColdSphereDiamIn() != 3) ++bad;
            if (!uapsColdNormalToAbsoluteZero()) ++bad;
            if (!uapsColdActsAsResistCold()) ++bad;
            if (uapsColdMagicalSaveBonus() != 6) ++bad;
            if (!uapsColdNoSaveDmgQuarter()) ++bad;
            if (!uapsColdSavedDmgEighth()) ++bad;
            if (uapsColdDurationLoTurns() != 5) ++bad;
            if (uapsColdDurationHiTurns() != 8) ++bad;
        // ---- the the protection from
        // electricity scroll ----
            if (uapsElecReadingSegs() != 5) ++bad;
            if (uapsElecSphereDiamIn() != 2) ++bad;
            if (!uapsElecImmuneAll()) ++bad;
            if (uapsElecDurationLoRounds() != 3) ++bad;
            if (uapsElecDurationHiRounds() != 12) ++bad;
        // ---- the the protection from
        // weapons, magical scroll ----
            if (uapsWeapMagReadingRounds() != 1) ++bad;
            if (!uapsWeapMagReaderOnly()) ++bad;
            if (!uapsWeapMagExemptsSpellMissiles()) ++bad;
            if (uapsWeapMagDurationLoRounds() != 5) ++bad;
            if (uapsWeapMagDurationHiRounds() != 8) ++bad;
        // ---- the the protection from
        // weapons, non-magic scroll ----
            if (uapsWeapNonMagReadingRounds() != 1) ++bad;
            if (uapsWeapNonMagSphereDiamIn() != 1) ++bad;
            if (!uapsWeapNonMagExemptsLargeMissiles()) ++bad;
            if (uapsWeapNonMagDurationLoRounds() != 5) ++bad;
            if (uapsWeapNonMagDurationHiRounds() != 8) ++bad;
        // ---- the the ring of boccob ----
            if (!uarpBoccobAppearsNonMagical()) ++bad;
            if (!uarpBoccobUndetectable()) ++bad;
            if (!uarpBoccobContactsDeviceFails()) ++bad;
            if (!uarpBoccobFailedSaveNonMagical()) ++bad;
            if (uarpBoccobQuiescenceLoHours() != 1) ++bad;
            if (uarpBoccobQuiescenceHiHours() != 4) ++bad;
            if (!uarpBoccobSingleUseNotCancelled()) ++bad;
            if (!uarpBoccobNormalDamageStill()) ++bad;
            if (uarpBoccobSaveAutoFailRoll() != 1) ++bad;
            if (uarpBoccobSaveRelicRoll() != 2) ++bad;
            if (uarpBoccobSaveArtifactRoll() != 3) ++bad;
            if (uarpBoccobSaveHandWeaponRoll() != 4) ++bad;
            if (uarpBoccobSaveRodStaffRoll() != 5) ++bad;
            if (uarpBoccobSaveOtherRoll() != 6) ++bad;
            if (uarpBoccobSaveAnySavesLo() != 7) ++bad;
            if (uarpBoccobSaveAnySavesHi() != 20) ++bad;
        // ---- the the ring of chameleon
        // power ----
            if (uarpChamInvisibilityPct() != 90) ++bad;
            if (uarpChamAssociateIntMin() != 4) ++bad;
            if (uarpChamAssociateRangeIn() != 6) ++bad;
            if (uarpChamDetectPctPerTurn() != 5) ++bad;
            if (uarpChamMaxAssociationTurns() != 20) ++bad;
            if (uarpChamIntBonusMin() != 16) ++bad;
            if (uarpChamLowIntMax() != 3) ++bad;
            if (uarpChamLowIntRangeIn() != 1) ++bad;
        // ---- the the ring of clumsiness
        // ----
            if (!uarpClumDisguisesBanefulNature()) ++bad;
            if (!uarpClumTriggersUnderStress()) ++bad;
            if (uarpClumSecondaryPowerCount() != 7) ++bad;
            if (uarpClumFreeActionLo() != 1) ++bad;
            if (uarpClumFreeActionHi() != 10) ++bad;
            if (uarpClumFeatherFallLo() != 11) ++bad;
            if (uarpClumFeatherFallHi() != 20) ++bad;
            if (uarpClumInvisibilityLo() != 21) ++bad;
            if (uarpClumInvisibilityHi() != 35) ++bad;
            if (uarpClumJumpingLo() != 36) ++bad;
            if (uarpClumJumpingHi() != 50) ++bad;
            if (uarpClumSwimmingLo() != 51) ++bad;
            if (uarpClumSwimmingHi() != 60) ++bad;
            if (uarpClumWarmthLo() != 61) ++bad;
            if (uarpClumWarmthHi() != 80) ++bad;
            if (uarpClumWaterWalkLo() != 81) ++bad;
            if (uarpClumWaterWalkHi() != 100) ++bad;
            if (!uarpClumDexHalvedDown()) ++bad;
            if (!uarpClumStealthHalved()) ++bad;
            if (!uarpClumComponentNeedsSave()) ++bad;
            if (!uarpClumRemovalIsDispel()) ++bad;
            if (uarpClumRemovalVsLevel() != 12) ++bad;
            if (!uarpClumRemovalDestroysBoth()) ++bad;
        // ---- the the ring of faerie ----
            if (!uarpFaerieGreyElfGift()) ++bad;
            if (uarpFaerieEvilPct() != 5) ++bad;
            if (uarpFaerieGoodPct() != 75) ++bad;
            if (uarpFaerieNeutralPct() != 20) ++bad;
            if (!uarpFaerieAlignmentMustMatch()) ++bad;
            if (!uarpFaerieWoodlandHideInvisible()) ++bad;
            if (!uarpFaerieSilenceNeedsAlone()) ++bad;
            if (!uarpFaerieSilenceNoMetalArmor()) ++bad;
            if (uarpFaerieSilentSuccessHi() != 67) ++bad;
            if (uarpFaerieNoiseFeetMin() != 68) ++bad;
            if (uarpFaerieSurpriseDieMin() != 1) ++bad;
            if (uarpFaerieSurpriseDieMax() != 4) ++bad;
            if (uarpFaerieInfravisionFeet() != 60) ++bad;
            if (uarpFaerieConcealedPassDie() != 1) ++bad;
            if (uarpFaerieConcealedSearchedPct() != 50) ++bad;
            if (uarpFaerieSecretSearchedDieMin() != 1) ++bad;
            if (uarpFaerieSecretSearchedDieMax() != 2) ++bad;
        // ---- the ram ----
            if (uarpRamDmgLoOneCharge() != 1) ++bad;
            if (uarpRamDmgHiOneCharge() != 6) ++bad;
            if (uarpRamDmgLoTwoCharges() != 2) ++bad;
            if (uarpRamDmgHiTwoCharges() != 12) ++bad;
            if (uarpRamDmgLoThreeCharges() != 3) ++bad;
            if (uarpRamDmgHiThreeCharges() != 18) ++bad;
            if (uarpRamMaxChargesPerAttack() != 3) ++bad;
            if (uarpRamRangeIn() != 3) ++bad;
            if (!uarpRamFailedSaveKnockedFree()) ++bad;
            if (uarpRamAdjSmaller() != -1) ++bad;
            if (uarpRamAdjLarger() != 2) ++bad;
            if (uarpRamAdjStrUnder12() != -1) ++bad;
            if (uarpRamAdjStr18to20() != 3) ++bad;
            if (uarpRamAdjStrOver20() != 6) ++bad;
            if (uarpRamAdjFourLegs() != 4) ++bad;
            if (uarpRamAdjOver1000Lbs() != 2) ++bad;
            if (uarpRamAdjTwoCharges() != -1) ++bad;
            if (uarpRamAdjThreeCharges() != -2) ++bad;
            if (uarpRamDoorStrBase() != 18) ++bad;
            if (uarpRamDoorStrTwoCharges() != 19) ++bad;
            if (uarpRamDoorStrThreeCharges() != 20) ++bad;
            if (!uarpRamStructuralAsBatteringRam()) ++bad;
            if (!uarpRamStructuralDoubleTriple()) ++bad;
            if (!uarpRamItemsSaveOnlyAtThree()) ++bad;
            if (!uarpRamItemsSaveVsCrushing()) ++bad;
            if (uarpRamChargesLo() != 6) ++bad;
            if (uarpRamChargesHi() != 60) ++bad;
            if (!uarpRamRechargeNeedsFist()) ++bad;
        // ---- the the ring of shocking
        // grasp ----
            if (!uarpShockFaintUnidentifiable()) ++bad;
            if (!uarpShockNeedsTouchHit()) ++bad;
            if (uarpShockDmgLo() != 7) ++bad;
            if (uarpShockDmgHi() != 14) ++bad;
            if (uarpShockDmgDieSides() != 8) ++bad;
            if (uarpShockDmgPlus() != 6) ++bad;
            if (uarpShockDischargesBeforeRest() != 3) ++bad;
            if (uarpShockRestTurns() != 1) ++bad;
        // ---- the the ring of sustenance
        // ----
            if (!uarpSustNoFoodOrDrink()) ++bad;
            if (uarpSustSleepHours() != 2) ++bad;
            if (uarpSustSleepBenefitHours() != 8) ++bad;
            if (uarpSustWearWeeks() != 1) ++bad;
            if (!uarpSustRemovalResets()) ++bad;
            if (uarpSustReattuneWeeks() != 1) ++bad;
            if (uarpSustConsecutiveDays() != 7) ++bad;
            if (uarpSustRestWeeks() != 1) ++bad;
        // ---- the the rod of flailing ----
            if (!uaroFlailAlterationDweomer()) ++bad;
            if (!uaroFlailDoubleHeaded()) ++bad;
            if (!uaroFlailMountedIsHorseman()) ++bad;
            if (uaroFlailHorsemanDmgHi() != 5) ++bad;
            if (uaroFlailFootmanSmHi() != 7) ++bad;
            if (uaroFlailFootmanLHi() != 8) ++bad;
            if (uaroFlailDmgLo() != 2) ++bad;
            if (uaroFlailBonus() != 3) ++bad;
            if (!uaroFlailBothHeadsChecked()) ++bad;
            if (!uaroFlailDoubleHitsPossible()) ++bad;
            if (uaroFlailProtectionCharges() != 1) ++bad;
            if (uaroFlailProtectionBonus() != 4) ++bad;
            if (uaroFlailProtectionTurns() != 1) ++bad;
            if (!uaroFlailTransformFree()) ++bad;
        // ---- the the rod of passage ----
            if (uaroPassFunctionCount() != 5) ++bad;
            if (uaroPassPerRound() != 1) ++bad;
            if (!uaroPassEachOncePerActivation()) ++bad;
            if (uaroPassActivationCharges() != 1) ++bad;
            if (uaroPassActiveDays() != 1) ++bad;
            if (!uaroPassSecondChargeResets()) ++bad;
            if (uaroPassAstralCreaturesMax() != 5) ++bad;
            if (!uaroPassAstralCancelsRest()) ++bad;
            if (!uaroPassTravelsToAstral()) ++bad;
            if (!uaroPassUnusableUntilReturned()) ++bad;
            if (uaroPassRechargeMuLevel() != 20) ++bad;
        // ---- the the rod of splendor ----
            if (uaroSplendorChaContinual() != 18) ++bad;
            if (!uaroSplendorNoGainAt18()) ++bad;
            if (uaroSplendorGarbCharges() != 1) ++bad;
            if (uaroSplendorGarbLoGp() != 7000) ++bad;
            if (uaroSplendorGarbHiGp() != 10000) ++bad;
            if (uaroSplendorFabricGp() != 1000) ++bad;
            if (uaroSplendorFurGp() != 5000) ++bad;
            if (uaroSplendorJewelLoGp() != 1000) ++bad;
            if (uaroSplendorJewelHiGp() != 4000) ++bad;
            if (!uaroSplendorSaleDestroysAll()) ++bad;
            if (!uaroSplendorForcedDestroysAll()) ++bad;
            if (!uaroSplendorGiftPersists()) ++bad;
            if (!uaroSplendorSecondChargeWasted()) ++bad;
            if (uaroSplendorTentCharges() != 1) ++bad;
            if (uaroSplendorTentLoSqFt() != 1500) ++bad;
            if (uaroSplendorTentHiSqFt() != 3000) ++bad;
            if (uaroSplendorTentPersons() != 100) ++bad;
            if (uaroSplendorTentDays() != 1) ++bad;
            if (uaroSplendorRechargeable()) ++bad;
        // ---- the the staff-spear ----
            if (!uaroSsAlterationAura()) ++bad;
            if (uaroSsCommandCount() != 3) ++bad;
            if (uaroSsElongateFeet() != 12) ++bad;
            if (uaroSsTableRowCount() != 6) ++bad;
            if (uaroSsBonusMin() != 1) ++bad;
            if (uaroSsBonusMax() != 5) ++bad;
            if (uaroSsTopRollBonus() != 3) ++bad;
            if (!uaroSsTopRanseur()) ++bad;
            if (uaroSsRanseurDmgLo() != 2) ++bad;
            if (uaroSsRanseurDmgHi() != 8) ++bad;
            if (uaroSsXpLo() != 1000) ++bad;
            if (uaroSsXpHi() != 3500) ++bad;
            if (uaroSsGpLo() != 5000) ++bad;
            if (uaroSsGpHi() != 25000) ++bad;
        // ---- the the staff of swarming
        // insects ----
            if (!uaroSwarmClericalOnly()) ++bad;
            if (uaroSwarmRangeBaseIn() != 6) ++bad;
            if (uaroSwarmRangePerLevelIn() != 1) ++bad;
            if (uaroSwarmBaseInsects() != 60) ++bad;
            if (uaroSwarmInsectsPerLevel() != 10) ++bad;
            if (uaroSwarmInsectsPerDmg() != 10) ++bad;
            if (!uaroSwarmIgnoresArmorClass()) ++bad;
            if (uaroSwarmLargeNaturalAcMin() != 5) ++bad;
            if (uaroSwarmAttackRounds() != 1) ++bad;
            if (!uaroSwarmCarvingsVanish()) ++bad;
            if (uaroSwarmMaxCharges() != 50) ++bad;
            if (uaroSwarmRechargeable()) ++bad;
        // ---- the the staff of thunder and
        // lightning ----
            if (uaroThunderBaseBonus() != 2) ++bad;
            if (uaroThunderStrikeBonus() != 3) ++bad;
            if (uaroThunderStunCharges() != 1) ++bad;
            if (!uaroThunderStunRestOfRound()) ++bad;
            if (!uaroThunderLastInitiative()) ++bad;
            if (uaroThunderShockDmgLo() != 2) ++bad;
            if (uaroThunderShockDmgHi() != 12) ++bad;
            if (uaroThunderShockCharges() != 1) ++bad;
            if (!uaroThunderDiscountsMetal()) ++bad;
            if (uaroThunderEffectiveAc() != 10) ++bad;
            if (uaroClapCharges() != 2) ++bad;
            if (uaroClapApexHalfIn() != 1) ++bad;
            if (uaroClapLengthIn() != 4) ++bad;
            if (uaroClapFarWidthIn() != 2) ++bad;
            if (uaroClapStunLo() != 1) ++bad;
            if (uaroClapStunHi() != 2) ++bad;
            if (uaroClapDeafLo() != 1) ++bad;
            if (uaroClapDeafHi() != 2) ++bad;
            if (uaroClapSaverDeafLo() != 1) ++bad;
            if (uaroClapSaverDeafHi() != 4) ++bad;
            if (uaroStrokeCharges() != 2) ++bad;
            if (uaroStrokeDice() != 8) ++bad;
            if (uaroStrokeDmgLo() != 16) ++bad;
            if (uaroStrokeDmgHi() != 48) ++bad;
            if (!uaroStrokeOnesAsTwo()) ++bad;
            if (!uaroStrokeForkedOrSingle()) ++bad;
            if (uaroCombinedCharges() != 4) ++bad;
            if (uaroCombinedDice() != 8) ++bad;
            if (uaroCombinedDmgLo() != 24) ++bad;
            if (uaroCombinedDmgHi() != 48) ++bad;
            if (!uaroCombinedOnesTwosAsThree()) ++bad;
            if (!uaroCombinedSaveDeafHalf()) ++bad;
            if (!uaroActivationSegsEqualCharges()) ++bad;
        // ---- the woodlands ----
            if (!uaroWoodDruidOnly()) ++bad;
            if (uaroWoodChargePowerCount() != 3) ++bad;
            if (uaroWoodThornWallCharges() != 1) ++bad;
            if (uaroWoodAnimalCharges() != 1) ++bad;
            if (uaroWoodAnimateCharges() != 1) ++bad;
            if (uaroWoodAnimateMoveIn() != 3) ++bad;
            if (uaroWoodAnimateRounds() != 8) ++bad;
            if (uaroWoodAnimateRoundToStart() != 1) ++bad;
            if (uaroWoodAnimateUsableRounds() != 6) ++bad;
            if (!uaroWoodAnimateRerootsOnEighth()) ++bad;
            if (uaroWoodTopBonus() != 4) ++bad;
            if (uaroWoodPlus3Extras() != 1) ++bad;
            if (uaroWoodPlus2Extras() != 2) ++bad;
            if (uaroWoodPlus1Extras() != 3) ++bad;
            if (!uaroWoodExtrasOncePerDay()) ++bad;
            if (uaroWoodTypeDieSides() != 4) ++bad;
        // ---- the the buckler wand ----
            if (uawdBuckLengthTenthsFt() != 15) ++bad;
            if (!uawdBuckSharpTipOneEnd()) ++bad;
            if (!uawdBuckTriggerOtherEnd()) ++bad;
            if (!uawdBuckBlocksCleric()) ++bad;
            if (uawdBuckActivateSegs() != 1) ++bad;
            if (!uawdBuckTipDaggerPlusOne()) ++bad;
            if (!uawdBuckShaftBucklerPlusOne()) ++bad;
            if (!uawdBuckWholeSpikedPlusOne()) ++bad;
            if (!uawdBuckMuMayEmploy()) ++bad;
            if (!uawdBuckMuNoSpellsInForm()) ++bad;
            if (!uawdBuckMulticlassException()) ++bad;
            if (!uawdBuckThiefNoClimbing()) ++bad;
        // ---- the the wand of earth and
        // stone ----
            if (uawdEarthDigCostTenths() != 5) ++bad;
            if (uawdEarthPasswallCharges() != 1) ++bad;
            if (uawdEarthMoveEarthCharges() != 2) ++bad;
            if (uawdEarthPctWithExtras() != 50) ++bad;
            if (!uawdEarthExtrasAreHigherValued()) ++bad;
            if (uawdEarthExtraPowerCount() != 2) ++bad;
            if (uawdEarthMudToRockCharges() != 1) ++bad;
            if (uawdEarthRockToMudCharges() != 1) ++bad;
        // ---- the the wand of force ----
            if (uawdForceFunctionCount() != 3) ++bad;
            if (uawdForceShaftFeet() != 4) ++bad;
            if (!uawdForceShaftPlusFive()) ++bad;
            if (!uawdForceShaftIsBastard()) ++bad;
            if (uawdForceShaftChargesPerTurn() != 1) ++bad;
            if (uawdForceWallCasterLevel() != 10) ++bad;
            if (uawdForceWallCharges() != 1) ++bad;
            if (!uawdForceWallOncePerRound()) ++bad;
            if (!uawdForceHandNeedsMu()) ++bad;
            if (!uawdForceHandNeedsSpellRecorded()) ++bad;
            if (uawdForceHandCostTenths() != 5) ++bad;
            if (!uawdForceFightersUseFirstTwo()) ++bad;
            if (uawdForceRechargeMuLevel() != 16) ++bad;
            if (!uawdForceTouchDisintegrates()) ++bad;
            if (uawdForceTouchKinds() != 3) ++bad;
            if (!uawdForceTouchAbsorbsCharge()) ++bad;
        // ---- the the wand of size
        // alteration ----
            if (uawdSizeChangePct() != 50) ++bad;
            if (uawdSizeHillGiantFeet() != 9) ++bad;
            if (uawdSizeHillGiantStr() != 19) ++bad;
            if (uawdSizeFireGiantFeet() != 13) ++bad;
            if (uawdSizeFireGiantStr() != 22) ++bad;
            if (uawdSizeRangeIn() != 1) ++bad;
            if (!uawdSizeGearAffected()) ++bad;
            if (!uawdSizeWillingForgoesSave()) ++bad;
            if (!uawdSizeDispelNeedsShock()) ++bad;
            if (!uawdSizePossessorMayCancel()) ++bad;
            if (uawdSizeChargesPerUse() != 1) ++bad;
            if (!uawdSizeCancellationFree()) ++bad;
            if (uawdSizeRechargeMuLevel() != 12) ++bad;
        // ---- the the wand of steam and
        // vapor ----
            if (uawdSteamCharges() != 1) ++bad;
            if (uawdSteamActivateSegs() != 1) ++bad;
            if (uawdSteamConeLoIn() != 1) ++bad;
            if (uawdSteamConeMidIn() != 3) ++bad;
            if (uawdSteamConeHiIn() != 5) ++bad;
            if (uawdSteamRound1Dice() != 6) ++bad;
            if (uawdSteamRound2Dice() != 4) ++bad;
            if (uawdSteamRound3Dice() != 2) ++bad;
            if (!uawdSteamSaveForHalf()) ++bad;
            if (!uawdSteamFireCreaturesImmune()) ++bad;
            if (!uawdSteamDampnessException()) ++bad;
            if (uawdVaporCharges() != 1) ++bad;
            if (uawdVaporActivateSegs() != 1) ++bad;
            if (uawdVaporDepthIn() != 4) ++bad;
            if (uawdVaporHeightIn() != 6) ++bad;
            if (uawdVaporBreadthIn() != 8) ++bad;
            if (uawdVaporRounds() != 6) ++bad;
            if (!uawdVaporStationaryUnlessWinds()) ++bad;
            if (uawdVaporColdUserDmg() != 1) ++bad;
            if (uawdVaporColdDwellerDmg() != 2) ++bad;
        // ---- the cross-checks
        // ----
            // the boccob list runs
            // contiguously 1-20
            if (uarpBoccobSaveAutoFailRoll()
                    + 1
                    != uarpBoccobSaveRelicRoll())
                ++bad;
            if (uarpBoccobSaveAnySavesLo()
                    - uarpBoccobSaveOtherRoll()
                    != 1) ++bad;
            // the clumsiness bands
            // tile 1-100 without
            // gaps or overlap
            if (uarpClumFreeActionHi()
                    + 1
                    != uarpClumFeatherFallLo())
                ++bad;
            if (uarpClumFeatherFallHi()
                    + 1
                    != uarpClumInvisibilityLo())
                ++bad;
            if (uarpClumInvisibilityHi()
                    + 1
                    != uarpClumJumpingLo())
                ++bad;
            if (uarpClumJumpingHi()
                    + 1
                    != uarpClumSwimmingLo())
                ++bad;
            if (uarpClumSwimmingHi()
                    + 1
                    != uarpClumWarmthLo())
                ++bad;
            if (uarpClumWarmthHi()
                    + 1
                    != uarpClumWaterWalkLo())
                ++bad;
            // the faerie alignments
            // sum to a full d%
            if (uarpFaerieEvilPct()
                    + uarpFaerieGoodPct()
                    + uarpFaerieNeutralPct()
                    != 100) ++bad;
            // the ram damage is n
            // charges of d6
            if (uarpRamDmgHiTwoCharges()
                    != 2 * uarpRamDmgHiOneCharge())
                ++bad;
            if (uarpRamDmgHiThreeCharges()
                    != 3 * uarpRamDmgHiOneCharge())
                ++bad;
            // the shocking grasp
            // band is d8 + 6, so the
            // low end is one die
            // plus the bonus
            if (uarpShockDmgHi()
                    - uarpShockDmgLo() + 1
                    != uarpShockDmgDieSides())
                ++bad;
            if (uarpShockDmgLo()
                    - uarpShockDmgPlus() != 1)
                ++bad;
            // the staff-spear g.p.
            // column is five times
            // the x.p. column
            if (uaroSsGpLo()
                    != 5 * uaroSsXpLo())
                ++bad;
            if (uaroSsXpHi()
                    - uaroSsXpLo() != 2500)
                ++bad;
            // the swarm damage is
            // the insect count
            // divided by ten
            if (uaroSwarmBaseInsects()
                    / uaroSwarmInsectsPerDmg()
                    != 6) ++bad;
            // the thunder stroke
            // runs 16-48 on 8d6
            // with 1s counted as 2
            if (uaroStrokeDmgHi()
                    != 2 * uaroStrokeDice()                    * 3) ++bad;
            if (uaroStrokeDmgLo()
                    != 2 * uaroStrokeDice())
                ++bad;
            // the activation runs
            // in segments equal to
            // the charges, so the
            // 4-charge combined
            // power takes 4
            // segments
            if (uaroCombinedCharges() != 4)
                ++bad;
            // the woodlands ladder
            // counts its extras up
            // as the bonus walks
            // down
            if (uaroWoodPlus3Extras()
                    + 1
                    != uaroWoodPlus2Extras())
                ++bad;
            if (uaroWoodPlus2Extras()
                    + 1
                    != uaroWoodPlus1Extras())
                ++bad;
            if (uaroWoodTopBonus()
                    - uaroWoodPlus1Extras()
                    != 1) ++bad;
            // the steam cone is
            // 1-3-5 inches and the
            // dice halve twice
            if (uawdSteamConeMidIn()
                    - uawdSteamConeLoIn()
                    != uawdSteamConeHiIn()
                    - uawdSteamConeMidIn())
                ++bad;
            if (uawdSteamRound2Dice()
                    >= uawdSteamRound1Dice())
                ++bad;
            if (uawdSteamRound3Dice()
                    != uawdSteamRound2Dice()
                    / 2) ++bad;
            // the vapor cloud is
            // 4-6-8 inches deep,
            // high, broad
            if (uawdVaporHeightIn()
                    - uawdVaporDepthIn()
                    != uawdVaporBreadthIn()
                    - uawdVaporHeightIn())
                ++bad;
            // the cold scroll
            // quarters and then
            // halves
            if (uapsColdMagicalSaveBonus()
                    != 6) ++bad;
            // the size alteration
            // strengths rise with
            // the heights
            if (uawdSizeHillGiantStr()
                    >= uawdSizeFireGiantStr())
                ++bad;
            if (uawdSizeHillGiantFeet()
                    >= uawdSizeFireGiantFeet())
                ++bad;
        // ---- the ledger seam ----
            // the four ledgers and
            // their seams carry
            // the flipped counts
            if (uapsCleanCount() != 15)
                ++bad;
            if (uapsGarbledCount() != 0)
                ++bad;
            if (uarpCleanCount() != 13)
                ++bad;
            if (uarpGarbledCount() != 0)
                ++bad;
            if (uaroCleanCount() != 11)
                ++bad;
            if (uaroGarbledCount() != 0)
                ++bad;
            if (uawdCleanCount() != 12)
                ++bad;
            if (uawdFlaggedCount() != 0)
                ++bad;
            if (uawdGarbledCount() != 0)
                ++bad;
        printf("R397 UA treasure smalls pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
