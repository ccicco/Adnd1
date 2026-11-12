    // ---- R279: the III.E misc magic explanation
    // prose part 23 ----
    // The Sphere of Annihilation, the three Stones, the
    // four Talismans, the three Tomes, the four Tridents,
    // the Vacuous Grimoire, the Well of Many Worlds and
    // the Wings of Flying, part2 lines 1083-1149 - the
    // closing slice pinning the kMisc5 rows 17-34 of the
    // 35-row III.E.5 table (rows 0-5 by part 21 and
    // 6-16 by part 22; the table is complete).
    {
        Miscmagic_sphere_of_annihilation_to_wings_of_flying miscmagic_sphere_of_annihilation_to_wings_of_flying;
        Miscmagic_table5_footnotes miscmagic_table5_footnotes;
        int bad = 0;
        // the sphere of annihilation scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereDiameterFeet() != 2 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereControlRangeFeet() != 40 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereControlPerLevelInches() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereBaseMoveFeetPerRound() != 10 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereIntBonusLowPct() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereIntBonusHighPct() != 3 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereIntBonusMaxPct() != 12 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereIntBonusLowStat() != 13 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereIntBonusHighStat() != 16 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereIntBonusMaxStat() != 18 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereDriftRoundsMin() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereDriftRoundsMax() != 4 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereDriftRangeFeet() != 30 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereMultiUserPenaltyPct() != 5 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereGateDestroyPct() != 50 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereGateNothingPct() != 35 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereGateTearPct() != 15 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereGateTearRadiusInches() != 18 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCancelRadiusInches() != 6 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCancelDmgMin() != 30 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCancelDmgMax() != 120) ++bad;
        // the intelligence bonus arithmetic: three low
        // points plus three high points make the 12
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereIntBonusLowPct() * 3 +
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereIntBonusHighPct() * 3 !=
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereIntBonusMaxPct()) ++bad;
        // the gate spell chances sum to 100 percent
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereGateDestroyPct() +
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereGateNothingPct() +
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereGateTearPct() != 100) ++bad;
        // the drift band is ordered
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereDriftRoundsMin() >
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereDriftRoundsMax()) ++bad;
        // the sphere control grid against static twins
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlRows() != 9) ++bad;
        static const int kSlo[9] = {
            1, 6, 8, 10, 12, 14, 16, 18, 21,
        };
        static const int kShi[9] = {
            5, 7, 9, 11, 13, 15, 17, 20, 0,
        };
        static const int kSmov[9] = {
            8, 9, 10, 11, 12, 13, 14, 15, 16,
        };
        static const int kSprob[9] = {
            15, 20, 30, 40, 50, 60, 70, 75, 80,
        };
        for (int i = 0; i < 9; ++i)
            if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlLevelLo(i) != kSlo[i] ||
                miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlLevelHi(i) != kShi[i] ||
                miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlMoveFeet(i) != kSmov[i] ||
                miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlProbPct(i) != kSprob[i]) ++bad;
        // the level bands chain 1 through 20, the ninth
        // band open above the 20th (0 = no ceiling)
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlLevelLo(0) != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlLevelHi(7) != 20 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlLevelLo(8) != 21 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlLevelHi(8) != 0) ++bad;
        for (int i = 0; i < 8; ++i)
            if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlLevelLo(i + 1) !=
                miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlLevelHi(i) + 1) ++bad;
        // the movement and probability both rise
        for (int i = 0; i < 8; ++i)
            if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlMoveFeet(i) >=
                miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlMoveFeet(i + 1) ||
                miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlProbPct(i) >=
                miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlProbPct(i + 1)) ++bad;
        // the stone of controlling earth elementals scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpEarthStoneEarthDice() != 12 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpEarthStoneRoughDice() != 8 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpEarthStoneWorkedStoneDice() != 0 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpEarthStoneAreaFeet() != 4 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpEarthStoneVolumeYards() != 4 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpEarthStoneRoundsMin() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpEarthStoneRoundsMax() != 4 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpEarthStonePerDay() != 1) ++bad;
        // worked stone summons nothing, earth summons the 12
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpEarthStoneWorkedStoneDice() >=
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpEarthStoneEarthDice()) ++bad;
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpEarthStoneRoundsMin() >
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpEarthStoneRoundsMax()) ++bad;
        // the stone of good luck scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpLuckSaveBonus() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpLuckSavePctBonus() != 5 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpLuckItemPctMin() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpLuckItemPctMax() != 10) ++bad;
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpLuckItemPctMin() >
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpLuckItemPctMax()) ++bad;
        // the stone of weight scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpLoadMoveReductionPct() != 50 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpLoadAttackReductionPct() != 50 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpLoadDispelClears() != 1) ++bad;
        // the talisman of pure good scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpPureGoodCharges() != 7 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpPureGoodRechargeable() != 0 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpPureGoodNeutralDmgMin() != 7 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpPureGoodNeutralDmgMax() != 28 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpPureGoodEvilDmgMin() != 12 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpPureGoodEvilDmgMax() != 48 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpPureGoodNonClericDmg() != 0) ++bad;
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpPureGoodNeutralDmgMin() >
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpPureGoodNeutralDmgMax() ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpPureGoodEvilDmgMin() >
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpPureGoodEvilDmgMax()) ++bad;
        // evil hands take the heavier damage of the two
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpPureGoodEvilDmgMax() <=
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpPureGoodNeutralDmgMax()) ++bad;
        // the talisman of the sphere scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereTaliNonMuDmgMin() != 5 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereTaliNonMuDmgMax() != 30 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereTaliLowPctPerPoint() != 2 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereTaliHighPctPerPoint() != 6 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereTaliCheckIntervalRounds() != 2 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereTaliMaxMoveFeet() != 16 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereWandNegationOnTalisman() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereWandNegationOnSphere() != 0) ++bad;
        // the talisman doubles the sphere intelligence bonus
        if (2 * miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereIntBonusLowPct() !=
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereTaliLowPctPerPoint() ||
            2 * miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereIntBonusHighPct() !=
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereTaliHighPctPerPoint()) ++bad;
        // the talisman top speed equals the grid top move
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereTaliMaxMoveFeet() !=
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereCtlMoveFeet(8)) ++bad;
        // the wand of negation stops the talisman only
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereWandNegationOnTalisman() ==
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSphereWandNegationOnSphere()) ++bad;
        // the talisman of ultimate evil scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpUltimateEvilCharges() != 6) ++bad;
        // the talisman of zagy scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpZagyHostileDmgMin() != 5 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpZagyHostileDmgMax() != 30 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpZagyNeutralHoursMin() != 5 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpZagyNeutralHoursMax() != 30 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpZagyFriendlyMonthsPerChaPoint() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpZagyWishChaDivisor() != 6 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpZagyTrapRangeFeet() != 20 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpZagyDiamondGp() != 10000) ++bad;
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpZagyHostileDmgMin() >
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpZagyHostileDmgMax() ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpZagyNeutralHoursMin() >
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpZagyNeutralHoursMax()) ++bad;
        // the tome of clear thought scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpClearThoughtIntGain() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpClearThoughtReadHours() != 48 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpClearThoughtReadDays() != 6 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpClearThoughtStartWeeks() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpClearThoughtGainMonths() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpClearThoughtRereadGain() != 0) ++bad;
        // the reading spreads 48 hours over 6 days
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpClearThoughtReadHours() !=
            8 * miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpClearThoughtReadDays()) ++bad;
        // the tome of leadership scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpLeadershipChaGain() != 1) ++bad;
        // the tome of understanding scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpUnderstandingWisGain() != 1) ++bad;
        // the trident of fish command scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpFishCmdRadiusInches() != 6 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpFishCmdChargeCost() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpFishCmdProtectFeet() != 10 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpFishCmdApproachFeet() != 10 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpFishCmdSchoolsAsOne() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpFishCmdChargesMin() != 17 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpFishCmdChargesMax() != 20 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpFishCmdMagicBonus() != 1) ++bad;
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpFishCmdChargesMin() >
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpFishCmdChargesMax()) ++bad;
        // the trident of submission scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSubmitMoraleDelayRounds() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSubmitHopelessRoundsMin() != 2 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSubmitHopelessRoundsMax() != 8 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSubmitChargesMin() != 17 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSubmitChargesMax() != 20 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSubmitMagicBonus() != 1) ++bad;
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSubmitHopelessRoundsMin() >
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSubmitHopelessRoundsMax() ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSubmitChargesMin() >
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSubmitChargesMax()) ++bad;
        // the trident of warning scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWarningRadiusInches() != 24 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWarningScanRounds() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWarningChargesMin() != 19 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWarningChargesMax() != 24 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWarningChargeRounds() != 2 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWarningMagicBonus() != 2) ++bad;
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWarningChargesMin() >
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWarningChargesMax()) ++bad;
        // the warning trident out-bonuses the other two
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWarningMagicBonus() <=
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpFishCmdMagicBonus() ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWarningMagicBonus() <=
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpSubmitMagicBonus()) ++bad;
        // the trident of yearning scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpYearningMagicPenalty() != 2 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpYearningFreeingSpells() != 3 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpYearningGrantsWaterBreathing() != 0) ++bad;
        // the vacuous grimoire scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpVacuousSaveCount() != 2 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpVacuousIntLoss() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpVacuousWisLoss() != 2 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpVacuousBurnAfterRemoveCurse() != 1) ++bad;
        // the wisdom loss doubles the intelligence loss
        if (2 * miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpVacuousIntLoss() !=
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpVacuousWisLoss()) ++bad;
        // the well of many worlds scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWellTwoWay() != 1) ++bad;
        // the wings of flying scalars
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsSpanFeet() != 20 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsRestHours() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsQuietHours() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsNoRestTurns() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsUsesPerDay() != 1 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsSupportPounds() != 500) ++bad;
        // the flight duration list against static twins
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsSpeedRows() != 3) ++bad;
        static const int kWt[3] = { 2, 4, 8 };
        static const int kWi[3] = { 32, 18, 12 };
        for (int i = 0; i < 3; ++i)
            if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsSpeedTurns(i) != kWt[i] ||
                miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsSpeedInches(i) != kWi[i]) ++bad;
        // the turns double down the list, the speeds fall
        if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsSpeedTurns(0) != 2 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsSpeedTurns(1) != 4 ||
            miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsSpeedTurns(2) != 8) ++bad;
        for (int i = 0; i < 2; ++i)
            if (miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsSpeedTurns(i) >=
                miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsSpeedTurns(i + 1) ||
                miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsSpeedInches(i) <=
                miscmagic_sphere_of_annihilation_to_wings_of_flying.mmpWingsSpeedInches(i + 1)) ++bad;
        // the kMisc5 table rows 17-34 against static twins
        static const int kRlo[18] = {
            48, 49, 51, 53, 55, 58, 59, 61, 67, 68,
            69, 70, 77, 79, 84, 86, 88, 91,
        };
        static const int kRhi[18] = {
            48, 50, 52, 54, 57, 58, 60, 66, 67, 68,
            69, 76, 78, 83, 85, 87, 90, 100,
        };
        for (int i = 0; i < 18; ++i)
            if (miscmagic_table5_footnotes.m5RowLo(17 + i) != kRlo[i] ||
                miscmagic_table5_footnotes.m5RowHi(17 + i) != kRhi[i]) ++bad;
        // the slice bands run 48 through 100 with no gaps
        if (miscmagic_table5_footnotes.m5RowLo(17) != 48 ||
            miscmagic_table5_footnotes.m5RowHi(34) != 100) ++bad;
        for (int i = 17; i < 34; ++i)
            if (miscmagic_table5_footnotes.m5RowLo(i + 1) !=
                miscmagic_table5_footnotes.m5RowHi(i) + 1) ++bad;
        for (int i = 17; i < 35; ++i)
            if (miscmagic_table5_footnotes.m5RowLo(i) >
                miscmagic_table5_footnotes.m5RowHi(i)) ++bad;
        // the cleric marks: the Pure Good, the Ultimate
        // Evil and the two command/warning Tridents
        for (int i = 17; i < 35; ++i)
            if (i != 21 && i != 23 && i != 28 && i != 30 &&
                miscmagic_table5_footnotes.m5UsableByCleric(i) != 0) ++bad;
        if (miscmagic_table5_footnotes.m5UsableByCleric(21) != 1 ||
            miscmagic_table5_footnotes.m5UsableByCleric(23) != 1 ||
            miscmagic_table5_footnotes.m5UsableByCleric(28) != 1 ||
            miscmagic_table5_footnotes.m5UsableByCleric(30) != 1) ++bad;
        // the fighter marks: the Submission and the two
        // command/warning Tridents
        for (int i = 17; i < 35; ++i)
            if (i != 28 && i != 29 && i != 30 &&
                miscmagic_table5_footnotes.m5UsableByFighter(i) != 0) ++bad;
        if (miscmagic_table5_footnotes.m5UsableByFighter(28) != 1 ||
            miscmagic_table5_footnotes.m5UsableByFighter(29) != 1 ||
            miscmagic_table5_footnotes.m5UsableByFighter(30) != 1) ++bad;
        // the magic-user marks: the Sphere and its Talisman
        for (int i = 17; i < 35; ++i)
            if (i != 17 && i != 22 &&
                miscmagic_table5_footnotes.m5UsableByMagicUser(i) != 0) ++bad;
        if (miscmagic_table5_footnotes.m5UsableByMagicUser(17) != 1 ||
            miscmagic_table5_footnotes.m5UsableByMagicUser(22) != 1) ++bad;
        // the thief marks: the two command/warning Tridents
        for (int i = 17; i < 35; ++i)
            if (i != 28 && i != 30 &&
                miscmagic_table5_footnotes.m5UsableByThief(i) != 0) ++bad;
        if (miscmagic_table5_footnotes.m5UsableByThief(28) != 1 ||
            miscmagic_table5_footnotes.m5UsableByThief(30) != 1) ++bad;
        // the whole-table counts and row census
        if (miscmagic_table5_footnotes.m5ClericCount() != 5 ||
            miscmagic_table5_footnotes.m5FighterCount() != 5 ||
            miscmagic_table5_footnotes.m5MagicUserCount() != 8 ||
            miscmagic_table5_footnotes.m5ThiefCount() != 2 ||
            miscmagic_table5_footnotes.m5RowCount() != 35) ++bad;
        printf("R279 misc magic prose part 23 pins audit: bad %d\n", bad);
    }
