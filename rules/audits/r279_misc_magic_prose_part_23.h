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
        Miscmagic_sphere_of_annihilation_to_wings_of_flying miscmagic;
        Miscmagic_table5_footnotes miscmagic_table5_footnotes;
        int bad = 0;
        // the sphere of annihilation scalars
        if (miscmagic.mmpSphereDiameterFeet() != 2 ||
            miscmagic.mmpSphereControlRangeFeet() != 40 ||
            miscmagic.mmpSphereControlPerLevelInches() != 1 ||
            miscmagic.mmpSphereBaseMoveFeetPerRound() != 10 ||
            miscmagic.mmpSphereIntBonusLowPct() != 1 ||
            miscmagic.mmpSphereIntBonusHighPct() != 3 ||
            miscmagic.mmpSphereIntBonusMaxPct() != 12 ||
            miscmagic.mmpSphereIntBonusLowStat() != 13 ||
            miscmagic.mmpSphereIntBonusHighStat() != 16 ||
            miscmagic.mmpSphereIntBonusMaxStat() != 18 ||
            miscmagic.mmpSphereDriftRoundsMin() != 1 ||
            miscmagic.mmpSphereDriftRoundsMax() != 4 ||
            miscmagic.mmpSphereDriftRangeFeet() != 30 ||
            miscmagic.mmpSphereMultiUserPenaltyPct() != 5 ||
            miscmagic.mmpSphereGateDestroyPct() != 50 ||
            miscmagic.mmpSphereGateNothingPct() != 35 ||
            miscmagic.mmpSphereGateTearPct() != 15 ||
            miscmagic.mmpSphereGateTearRadiusInches() != 18 ||
            miscmagic.mmpSphereCancelRadiusInches() != 6 ||
            miscmagic.mmpSphereCancelDmgMin() != 30 ||
            miscmagic.mmpSphereCancelDmgMax() != 120) ++bad;
        // the intelligence bonus arithmetic: three low
        // points plus three high points make the 12
        if (miscmagic.mmpSphereIntBonusLowPct() * 3 +
            miscmagic.mmpSphereIntBonusHighPct() * 3 !=
            miscmagic.mmpSphereIntBonusMaxPct()) ++bad;
        // the gate spell chances sum to 100 percent
        if (miscmagic.mmpSphereGateDestroyPct() +
            miscmagic.mmpSphereGateNothingPct() +
            miscmagic.mmpSphereGateTearPct() != 100) ++bad;
        // the drift band is ordered
        if (miscmagic.mmpSphereDriftRoundsMin() >
            miscmagic.mmpSphereDriftRoundsMax()) ++bad;
        // the sphere control grid against static twins
        if (miscmagic.mmpSphereCtlRows() != 9) ++bad;
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
            if (miscmagic.mmpSphereCtlLevelLo(i) != kSlo[i] ||
                miscmagic.mmpSphereCtlLevelHi(i) != kShi[i] ||
                miscmagic.mmpSphereCtlMoveFeet(i) != kSmov[i] ||
                miscmagic.mmpSphereCtlProbPct(i) != kSprob[i]) ++bad;
        // the level bands chain 1 through 20, the ninth
        // band open above the 20th (0 = no ceiling)
        if (miscmagic.mmpSphereCtlLevelLo(0) != 1 ||
            miscmagic.mmpSphereCtlLevelHi(7) != 20 ||
            miscmagic.mmpSphereCtlLevelLo(8) != 21 ||
            miscmagic.mmpSphereCtlLevelHi(8) != 0) ++bad;
        for (int i = 0; i < 8; ++i)
            if (miscmagic.mmpSphereCtlLevelLo(i + 1) !=
                miscmagic.mmpSphereCtlLevelHi(i) + 1) ++bad;
        // the movement and probability both rise
        for (int i = 0; i < 8; ++i)
            if (miscmagic.mmpSphereCtlMoveFeet(i) >=
                miscmagic.mmpSphereCtlMoveFeet(i + 1) ||
                miscmagic.mmpSphereCtlProbPct(i) >=
                miscmagic.mmpSphereCtlProbPct(i + 1)) ++bad;
        // the stone of controlling earth elementals scalars
        if (miscmagic.mmpEarthStoneEarthDice() != 12 ||
            miscmagic.mmpEarthStoneRoughDice() != 8 ||
            miscmagic.mmpEarthStoneWorkedStoneDice() != 0 ||
            miscmagic.mmpEarthStoneAreaFeet() != 4 ||
            miscmagic.mmpEarthStoneVolumeYards() != 4 ||
            miscmagic.mmpEarthStoneRoundsMin() != 1 ||
            miscmagic.mmpEarthStoneRoundsMax() != 4 ||
            miscmagic.mmpEarthStonePerDay() != 1) ++bad;
        // worked stone summons nothing, earth summons the 12
        if (miscmagic.mmpEarthStoneWorkedStoneDice() >=
            miscmagic.mmpEarthStoneEarthDice()) ++bad;
        if (miscmagic.mmpEarthStoneRoundsMin() >
            miscmagic.mmpEarthStoneRoundsMax()) ++bad;
        // the stone of good luck scalars
        if (miscmagic.mmpLuckSaveBonus() != 1 ||
            miscmagic.mmpLuckSavePctBonus() != 5 ||
            miscmagic.mmpLuckItemPctMin() != 1 ||
            miscmagic.mmpLuckItemPctMax() != 10) ++bad;
        if (miscmagic.mmpLuckItemPctMin() >
            miscmagic.mmpLuckItemPctMax()) ++bad;
        // the stone of weight scalars
        if (miscmagic.mmpLoadMoveReductionPct() != 50 ||
            miscmagic.mmpLoadAttackReductionPct() != 50 ||
            miscmagic.mmpLoadDispelClears() != 1) ++bad;
        // the talisman of pure good scalars
        if (miscmagic.mmpPureGoodCharges() != 7 ||
            miscmagic.mmpPureGoodRechargeable() != 0 ||
            miscmagic.mmpPureGoodNeutralDmgMin() != 7 ||
            miscmagic.mmpPureGoodNeutralDmgMax() != 28 ||
            miscmagic.mmpPureGoodEvilDmgMin() != 12 ||
            miscmagic.mmpPureGoodEvilDmgMax() != 48 ||
            miscmagic.mmpPureGoodNonClericDmg() != 0) ++bad;
        if (miscmagic.mmpPureGoodNeutralDmgMin() >
            miscmagic.mmpPureGoodNeutralDmgMax() ||
            miscmagic.mmpPureGoodEvilDmgMin() >
            miscmagic.mmpPureGoodEvilDmgMax()) ++bad;
        // evil hands take the heavier damage of the two
        if (miscmagic.mmpPureGoodEvilDmgMax() <=
            miscmagic.mmpPureGoodNeutralDmgMax()) ++bad;
        // the talisman of the sphere scalars
        if (miscmagic.mmpSphereTaliNonMuDmgMin() != 5 ||
            miscmagic.mmpSphereTaliNonMuDmgMax() != 30 ||
            miscmagic.mmpSphereTaliLowPctPerPoint() != 2 ||
            miscmagic.mmpSphereTaliHighPctPerPoint() != 6 ||
            miscmagic.mmpSphereTaliCheckIntervalRounds() != 2 ||
            miscmagic.mmpSphereTaliMaxMoveFeet() != 16 ||
            miscmagic.mmpSphereWandNegationOnTalisman() != 1 ||
            miscmagic.mmpSphereWandNegationOnSphere() != 0) ++bad;
        // the talisman doubles the sphere intelligence bonus
        if (2 * miscmagic.mmpSphereIntBonusLowPct() !=
            miscmagic.mmpSphereTaliLowPctPerPoint() ||
            2 * miscmagic.mmpSphereIntBonusHighPct() !=
            miscmagic.mmpSphereTaliHighPctPerPoint()) ++bad;
        // the talisman top speed equals the grid top move
        if (miscmagic.mmpSphereTaliMaxMoveFeet() !=
            miscmagic.mmpSphereCtlMoveFeet(8)) ++bad;
        // the wand of negation stops the talisman only
        if (miscmagic.mmpSphereWandNegationOnTalisman() ==
            miscmagic.mmpSphereWandNegationOnSphere()) ++bad;
        // the talisman of ultimate evil scalars
        if (miscmagic.mmpUltimateEvilCharges() != 6) ++bad;
        // the talisman of zagy scalars
        if (miscmagic.mmpZagyHostileDmgMin() != 5 ||
            miscmagic.mmpZagyHostileDmgMax() != 30 ||
            miscmagic.mmpZagyNeutralHoursMin() != 5 ||
            miscmagic.mmpZagyNeutralHoursMax() != 30 ||
            miscmagic.mmpZagyFriendlyMonthsPerChaPoint() != 1 ||
            miscmagic.mmpZagyWishChaDivisor() != 6 ||
            miscmagic.mmpZagyTrapRangeFeet() != 20 ||
            miscmagic.mmpZagyDiamondGp() != 10000) ++bad;
        if (miscmagic.mmpZagyHostileDmgMin() >
            miscmagic.mmpZagyHostileDmgMax() ||
            miscmagic.mmpZagyNeutralHoursMin() >
            miscmagic.mmpZagyNeutralHoursMax()) ++bad;
        // the tome of clear thought scalars
        if (miscmagic.mmpClearThoughtIntGain() != 1 ||
            miscmagic.mmpClearThoughtReadHours() != 48 ||
            miscmagic.mmpClearThoughtReadDays() != 6 ||
            miscmagic.mmpClearThoughtStartWeeks() != 1 ||
            miscmagic.mmpClearThoughtGainMonths() != 1 ||
            miscmagic.mmpClearThoughtRereadGain() != 0) ++bad;
        // the reading spreads 48 hours over 6 days
        if (miscmagic.mmpClearThoughtReadHours() !=
            8 * miscmagic.mmpClearThoughtReadDays()) ++bad;
        // the tome of leadership scalars
        if (miscmagic.mmpLeadershipChaGain() != 1) ++bad;
        // the tome of understanding scalars
        if (miscmagic.mmpUnderstandingWisGain() != 1) ++bad;
        // the trident of fish command scalars
        if (miscmagic.mmpFishCmdRadiusInches() != 6 ||
            miscmagic.mmpFishCmdChargeCost() != 1 ||
            miscmagic.mmpFishCmdProtectFeet() != 10 ||
            miscmagic.mmpFishCmdApproachFeet() != 10 ||
            miscmagic.mmpFishCmdSchoolsAsOne() != 1 ||
            miscmagic.mmpFishCmdChargesMin() != 17 ||
            miscmagic.mmpFishCmdChargesMax() != 20 ||
            miscmagic.mmpFishCmdMagicBonus() != 1) ++bad;
        if (miscmagic.mmpFishCmdChargesMin() >
            miscmagic.mmpFishCmdChargesMax()) ++bad;
        // the trident of submission scalars
        if (miscmagic.mmpSubmitMoraleDelayRounds() != 1 ||
            miscmagic.mmpSubmitHopelessRoundsMin() != 2 ||
            miscmagic.mmpSubmitHopelessRoundsMax() != 8 ||
            miscmagic.mmpSubmitChargesMin() != 17 ||
            miscmagic.mmpSubmitChargesMax() != 20 ||
            miscmagic.mmpSubmitMagicBonus() != 1) ++bad;
        if (miscmagic.mmpSubmitHopelessRoundsMin() >
            miscmagic.mmpSubmitHopelessRoundsMax() ||
            miscmagic.mmpSubmitChargesMin() >
            miscmagic.mmpSubmitChargesMax()) ++bad;
        // the trident of warning scalars
        if (miscmagic.mmpWarningRadiusInches() != 24 ||
            miscmagic.mmpWarningScanRounds() != 1 ||
            miscmagic.mmpWarningChargesMin() != 19 ||
            miscmagic.mmpWarningChargesMax() != 24 ||
            miscmagic.mmpWarningChargeRounds() != 2 ||
            miscmagic.mmpWarningMagicBonus() != 2) ++bad;
        if (miscmagic.mmpWarningChargesMin() >
            miscmagic.mmpWarningChargesMax()) ++bad;
        // the warning trident out-bonuses the other two
        if (miscmagic.mmpWarningMagicBonus() <=
            miscmagic.mmpFishCmdMagicBonus() ||
            miscmagic.mmpWarningMagicBonus() <=
            miscmagic.mmpSubmitMagicBonus()) ++bad;
        // the trident of yearning scalars
        if (miscmagic.mmpYearningMagicPenalty() != 2 ||
            miscmagic.mmpYearningFreeingSpells() != 3 ||
            miscmagic.mmpYearningGrantsWaterBreathing() != 0) ++bad;
        // the vacuous grimoire scalars
        if (miscmagic.mmpVacuousSaveCount() != 2 ||
            miscmagic.mmpVacuousIntLoss() != 1 ||
            miscmagic.mmpVacuousWisLoss() != 2 ||
            miscmagic.mmpVacuousBurnAfterRemoveCurse() != 1) ++bad;
        // the wisdom loss doubles the intelligence loss
        if (2 * miscmagic.mmpVacuousIntLoss() !=
            miscmagic.mmpVacuousWisLoss()) ++bad;
        // the well of many worlds scalars
        if (miscmagic.mmpWellTwoWay() != 1) ++bad;
        // the wings of flying scalars
        if (miscmagic.mmpWingsSpanFeet() != 20 ||
            miscmagic.mmpWingsRestHours() != 1 ||
            miscmagic.mmpWingsQuietHours() != 1 ||
            miscmagic.mmpWingsNoRestTurns() != 1 ||
            miscmagic.mmpWingsUsesPerDay() != 1 ||
            miscmagic.mmpWingsSupportPounds() != 500) ++bad;
        // the flight duration list against static twins
        if (miscmagic.mmpWingsSpeedRows() != 3) ++bad;
        static const int kWt[3] = { 2, 4, 8 };
        static const int kWi[3] = { 32, 18, 12 };
        for (int i = 0; i < 3; ++i)
            if (miscmagic.mmpWingsSpeedTurns(i) != kWt[i] ||
                miscmagic.mmpWingsSpeedInches(i) != kWi[i]) ++bad;
        // the turns double down the list, the speeds fall
        if (miscmagic.mmpWingsSpeedTurns(0) != 2 ||
            miscmagic.mmpWingsSpeedTurns(1) != 4 ||
            miscmagic.mmpWingsSpeedTurns(2) != 8) ++bad;
        for (int i = 0; i < 2; ++i)
            if (miscmagic.mmpWingsSpeedTurns(i) >=
                miscmagic.mmpWingsSpeedTurns(i + 1) ||
                miscmagic.mmpWingsSpeedInches(i) <=
                miscmagic.mmpWingsSpeedInches(i + 1)) ++bad;
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
