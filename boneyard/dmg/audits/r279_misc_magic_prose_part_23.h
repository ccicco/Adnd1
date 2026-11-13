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
        int bad = 0;
        // the sphere of annihilation scalars
        if (rules::mmpSphereDiameterFeet() != 2 ||
            rules::mmpSphereControlRangeFeet() != 40 ||
            rules::mmpSphereControlPerLevelInches() != 1 ||
            rules::mmpSphereBaseMoveFeetPerRound() != 10 ||
            rules::mmpSphereIntBonusLowPct() != 1 ||
            rules::mmpSphereIntBonusHighPct() != 3 ||
            rules::mmpSphereIntBonusMaxPct() != 12 ||
            rules::mmpSphereIntBonusLowStat() != 13 ||
            rules::mmpSphereIntBonusHighStat() != 16 ||
            rules::mmpSphereIntBonusMaxStat() != 18 ||
            rules::mmpSphereDriftRoundsMin() != 1 ||
            rules::mmpSphereDriftRoundsMax() != 4 ||
            rules::mmpSphereDriftRangeFeet() != 30 ||
            rules::mmpSphereMultiUserPenaltyPct() != 5 ||
            rules::mmpSphereGateDestroyPct() != 50 ||
            rules::mmpSphereGateNothingPct() != 35 ||
            rules::mmpSphereGateTearPct() != 15 ||
            rules::mmpSphereGateTearRadiusInches() != 18 ||
            rules::mmpSphereCancelRadiusInches() != 6 ||
            rules::mmpSphereCancelDmgMin() != 30 ||
            rules::mmpSphereCancelDmgMax() != 120) ++bad;
        // the intelligence bonus arithmetic: three low
        // points plus three high points make the 12
        if (rules::mmpSphereIntBonusLowPct() * 3 +
            rules::mmpSphereIntBonusHighPct() * 3 !=
            rules::mmpSphereIntBonusMaxPct()) ++bad;
        // the gate spell chances sum to 100 percent
        if (rules::mmpSphereGateDestroyPct() +
            rules::mmpSphereGateNothingPct() +
            rules::mmpSphereGateTearPct() != 100) ++bad;
        // the drift band is ordered
        if (rules::mmpSphereDriftRoundsMin() >
            rules::mmpSphereDriftRoundsMax()) ++bad;
        // the sphere control grid against static twins
        if (rules::mmpSphereCtlRows() != 9) ++bad;
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
            if (rules::mmpSphereCtlLevelLo(i) != kSlo[i] ||
                rules::mmpSphereCtlLevelHi(i) != kShi[i] ||
                rules::mmpSphereCtlMoveFeet(i) != kSmov[i] ||
                rules::mmpSphereCtlProbPct(i) != kSprob[i]) ++bad;
        // the level bands chain 1 through 20, the ninth
        // band open above the 20th (0 = no ceiling)
        if (rules::mmpSphereCtlLevelLo(0) != 1 ||
            rules::mmpSphereCtlLevelHi(7) != 20 ||
            rules::mmpSphereCtlLevelLo(8) != 21 ||
            rules::mmpSphereCtlLevelHi(8) != 0) ++bad;
        for (int i = 0; i < 8; ++i)
            if (rules::mmpSphereCtlLevelLo(i + 1) !=
                rules::mmpSphereCtlLevelHi(i) + 1) ++bad;
        // the movement and probability both rise
        for (int i = 0; i < 8; ++i)
            if (rules::mmpSphereCtlMoveFeet(i) >=
                rules::mmpSphereCtlMoveFeet(i + 1) ||
                rules::mmpSphereCtlProbPct(i) >=
                rules::mmpSphereCtlProbPct(i + 1)) ++bad;
        // the stone of controlling earth elementals scalars
        if (rules::mmpEarthStoneEarthDice() != 12 ||
            rules::mmpEarthStoneRoughDice() != 8 ||
            rules::mmpEarthStoneWorkedStoneDice() != 0 ||
            rules::mmpEarthStoneAreaFeet() != 4 ||
            rules::mmpEarthStoneVolumeYards() != 4 ||
            rules::mmpEarthStoneRoundsMin() != 1 ||
            rules::mmpEarthStoneRoundsMax() != 4 ||
            rules::mmpEarthStonePerDay() != 1) ++bad;
        // worked stone summons nothing, earth summons the 12
        if (rules::mmpEarthStoneWorkedStoneDice() >=
            rules::mmpEarthStoneEarthDice()) ++bad;
        if (rules::mmpEarthStoneRoundsMin() >
            rules::mmpEarthStoneRoundsMax()) ++bad;
        // the stone of good luck scalars
        if (rules::mmpLuckSaveBonus() != 1 ||
            rules::mmpLuckSavePctBonus() != 5 ||
            rules::mmpLuckItemPctMin() != 1 ||
            rules::mmpLuckItemPctMax() != 10) ++bad;
        if (rules::mmpLuckItemPctMin() >
            rules::mmpLuckItemPctMax()) ++bad;
        // the stone of weight scalars
        if (rules::mmpLoadMoveReductionPct() != 50 ||
            rules::mmpLoadAttackReductionPct() != 50 ||
            rules::mmpLoadDispelClears() != 1) ++bad;
        // the talisman of pure good scalars
        if (rules::mmpPureGoodCharges() != 7 ||
            rules::mmpPureGoodRechargeable() != 0 ||
            rules::mmpPureGoodNeutralDmgMin() != 7 ||
            rules::mmpPureGoodNeutralDmgMax() != 28 ||
            rules::mmpPureGoodEvilDmgMin() != 12 ||
            rules::mmpPureGoodEvilDmgMax() != 48 ||
            rules::mmpPureGoodNonClericDmg() != 0) ++bad;
        if (rules::mmpPureGoodNeutralDmgMin() >
            rules::mmpPureGoodNeutralDmgMax() ||
            rules::mmpPureGoodEvilDmgMin() >
            rules::mmpPureGoodEvilDmgMax()) ++bad;
        // evil hands take the heavier damage of the two
        if (rules::mmpPureGoodEvilDmgMax() <=
            rules::mmpPureGoodNeutralDmgMax()) ++bad;
        // the talisman of the sphere scalars
        if (rules::mmpSphereTaliNonMuDmgMin() != 5 ||
            rules::mmpSphereTaliNonMuDmgMax() != 30 ||
            rules::mmpSphereTaliLowPctPerPoint() != 2 ||
            rules::mmpSphereTaliHighPctPerPoint() != 6 ||
            rules::mmpSphereTaliCheckIntervalRounds() != 2 ||
            rules::mmpSphereTaliMaxMoveFeet() != 16 ||
            rules::mmpSphereWandNegationOnTalisman() != 1 ||
            rules::mmpSphereWandNegationOnSphere() != 0) ++bad;
        // the talisman doubles the sphere intelligence bonus
        if (2 * rules::mmpSphereIntBonusLowPct() !=
            rules::mmpSphereTaliLowPctPerPoint() ||
            2 * rules::mmpSphereIntBonusHighPct() !=
            rules::mmpSphereTaliHighPctPerPoint()) ++bad;
        // the talisman top speed equals the grid top move
        if (rules::mmpSphereTaliMaxMoveFeet() !=
            rules::mmpSphereCtlMoveFeet(8)) ++bad;
        // the wand of negation stops the talisman only
        if (rules::mmpSphereWandNegationOnTalisman() ==
            rules::mmpSphereWandNegationOnSphere()) ++bad;
        // the talisman of ultimate evil scalars
        if (rules::mmpUltimateEvilCharges() != 6) ++bad;
        // the talisman of zagy scalars
        if (rules::mmpZagyHostileDmgMin() != 5 ||
            rules::mmpZagyHostileDmgMax() != 30 ||
            rules::mmpZagyNeutralHoursMin() != 5 ||
            rules::mmpZagyNeutralHoursMax() != 30 ||
            rules::mmpZagyFriendlyMonthsPerChaPoint() != 1 ||
            rules::mmpZagyWishChaDivisor() != 6 ||
            rules::mmpZagyTrapRangeFeet() != 20 ||
            rules::mmpZagyDiamondGp() != 10000) ++bad;
        if (rules::mmpZagyHostileDmgMin() >
            rules::mmpZagyHostileDmgMax() ||
            rules::mmpZagyNeutralHoursMin() >
            rules::mmpZagyNeutralHoursMax()) ++bad;
        // the tome of clear thought scalars
        if (rules::mmpClearThoughtIntGain() != 1 ||
            rules::mmpClearThoughtReadHours() != 48 ||
            rules::mmpClearThoughtReadDays() != 6 ||
            rules::mmpClearThoughtStartWeeks() != 1 ||
            rules::mmpClearThoughtGainMonths() != 1 ||
            rules::mmpClearThoughtRereadGain() != 0) ++bad;
        // the reading spreads 48 hours over 6 days
        if (rules::mmpClearThoughtReadHours() !=
            8 * rules::mmpClearThoughtReadDays()) ++bad;
        // the tome of leadership scalars
        if (rules::mmpLeadershipChaGain() != 1) ++bad;
        // the tome of understanding scalars
        if (rules::mmpUnderstandingWisGain() != 1) ++bad;
        // the trident of fish command scalars
        if (rules::mmpFishCmdRadiusInches() != 6 ||
            rules::mmpFishCmdChargeCost() != 1 ||
            rules::mmpFishCmdProtectFeet() != 10 ||
            rules::mmpFishCmdApproachFeet() != 10 ||
            rules::mmpFishCmdSchoolsAsOne() != 1 ||
            rules::mmpFishCmdChargesMin() != 17 ||
            rules::mmpFishCmdChargesMax() != 20 ||
            rules::mmpFishCmdMagicBonus() != 1) ++bad;
        if (rules::mmpFishCmdChargesMin() >
            rules::mmpFishCmdChargesMax()) ++bad;
        // the trident of submission scalars
        if (rules::mmpSubmitMoraleDelayRounds() != 1 ||
            rules::mmpSubmitHopelessRoundsMin() != 2 ||
            rules::mmpSubmitHopelessRoundsMax() != 8 ||
            rules::mmpSubmitChargesMin() != 17 ||
            rules::mmpSubmitChargesMax() != 20 ||
            rules::mmpSubmitMagicBonus() != 1) ++bad;
        if (rules::mmpSubmitHopelessRoundsMin() >
            rules::mmpSubmitHopelessRoundsMax() ||
            rules::mmpSubmitChargesMin() >
            rules::mmpSubmitChargesMax()) ++bad;
        // the trident of warning scalars
        if (rules::mmpWarningRadiusInches() != 24 ||
            rules::mmpWarningScanRounds() != 1 ||
            rules::mmpWarningChargesMin() != 19 ||
            rules::mmpWarningChargesMax() != 24 ||
            rules::mmpWarningChargeRounds() != 2 ||
            rules::mmpWarningMagicBonus() != 2) ++bad;
        if (rules::mmpWarningChargesMin() >
            rules::mmpWarningChargesMax()) ++bad;
        // the warning trident out-bonuses the other two
        if (rules::mmpWarningMagicBonus() <=
            rules::mmpFishCmdMagicBonus() ||
            rules::mmpWarningMagicBonus() <=
            rules::mmpSubmitMagicBonus()) ++bad;
        // the trident of yearning scalars
        if (rules::mmpYearningMagicPenalty() != 2 ||
            rules::mmpYearningFreeingSpells() != 3 ||
            rules::mmpYearningGrantsWaterBreathing() != 0) ++bad;
        // the vacuous grimoire scalars
        if (rules::mmpVacuousSaveCount() != 2 ||
            rules::mmpVacuousIntLoss() != 1 ||
            rules::mmpVacuousWisLoss() != 2 ||
            rules::mmpVacuousBurnAfterRemoveCurse() != 1) ++bad;
        // the wisdom loss doubles the intelligence loss
        if (2 * rules::mmpVacuousIntLoss() !=
            rules::mmpVacuousWisLoss()) ++bad;
        // the well of many worlds scalars
        if (rules::mmpWellTwoWay() != 1) ++bad;
        // the wings of flying scalars
        if (rules::mmpWingsSpanFeet() != 20 ||
            rules::mmpWingsRestHours() != 1 ||
            rules::mmpWingsQuietHours() != 1 ||
            rules::mmpWingsNoRestTurns() != 1 ||
            rules::mmpWingsUsesPerDay() != 1 ||
            rules::mmpWingsSupportPounds() != 500) ++bad;
        // the flight duration list against static twins
        if (rules::mmpWingsSpeedRows() != 3) ++bad;
        static const int kWt[3] = { 2, 4, 8 };
        static const int kWi[3] = { 32, 18, 12 };
        for (int i = 0; i < 3; ++i)
            if (rules::mmpWingsSpeedTurns(i) != kWt[i] ||
                rules::mmpWingsSpeedInches(i) != kWi[i]) ++bad;
        // the turns double down the list, the speeds fall
        if (rules::mmpWingsSpeedTurns(0) != 2 ||
            rules::mmpWingsSpeedTurns(1) != 4 ||
            rules::mmpWingsSpeedTurns(2) != 8) ++bad;
        for (int i = 0; i < 2; ++i)
            if (rules::mmpWingsSpeedTurns(i) >=
                rules::mmpWingsSpeedTurns(i + 1) ||
                rules::mmpWingsSpeedInches(i) <=
                rules::mmpWingsSpeedInches(i + 1)) ++bad;
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
            if (rules::m5RowLo(17 + i) != kRlo[i] ||
                rules::m5RowHi(17 + i) != kRhi[i]) ++bad;
        // the slice bands run 48 through 100 with no gaps
        if (rules::m5RowLo(17) != 48 ||
            rules::m5RowHi(34) != 100) ++bad;
        for (int i = 17; i < 34; ++i)
            if (rules::m5RowLo(i + 1) !=
                rules::m5RowHi(i) + 1) ++bad;
        for (int i = 17; i < 35; ++i)
            if (rules::m5RowLo(i) >
                rules::m5RowHi(i)) ++bad;
        // the cleric marks: the Pure Good, the Ultimate
        // Evil and the two command/warning Tridents
        for (int i = 17; i < 35; ++i)
            if (i != 21 && i != 23 && i != 28 && i != 30 &&
                rules::m5UsableByCleric(i) != 0) ++bad;
        if (rules::m5UsableByCleric(21) != 1 ||
            rules::m5UsableByCleric(23) != 1 ||
            rules::m5UsableByCleric(28) != 1 ||
            rules::m5UsableByCleric(30) != 1) ++bad;
        // the fighter marks: the Submission and the two
        // command/warning Tridents
        for (int i = 17; i < 35; ++i)
            if (i != 28 && i != 29 && i != 30 &&
                rules::m5UsableByFighter(i) != 0) ++bad;
        if (rules::m5UsableByFighter(28) != 1 ||
            rules::m5UsableByFighter(29) != 1 ||
            rules::m5UsableByFighter(30) != 1) ++bad;
        // the magic-user marks: the Sphere and its Talisman
        for (int i = 17; i < 35; ++i)
            if (i != 17 && i != 22 &&
                rules::m5UsableByMagicUser(i) != 0) ++bad;
        if (rules::m5UsableByMagicUser(17) != 1 ||
            rules::m5UsableByMagicUser(22) != 1) ++bad;
        // the thief marks: the two command/warning Tridents
        for (int i = 17; i < 35; ++i)
            if (i != 28 && i != 30 &&
                rules::m5UsableByThief(i) != 0) ++bad;
        if (rules::m5UsableByThief(28) != 1 ||
            rules::m5UsableByThief(30) != 1) ++bad;
        // the whole-table counts and row census
        if (rules::m5ClericCount() != 5 ||
            rules::m5FighterCount() != 5 ||
            rules::m5MagicUserCount() != 8 ||
            rules::m5ThiefCount() != 2 ||
            rules::m5RowCount() != 35) ++bad;
        printf("R279 misc magic prose part 23 pins audit: bad %d\n", bad);
    }
