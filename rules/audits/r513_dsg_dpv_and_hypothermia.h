    // ---- R513 DSG DPV and hypothermia audit ----
    // The DSG DPV pins the defensive point values section (the constructed
    // fortifications with DPVs per the DMG page 110, the natural and
    // constructed formations assigned values, the use to determine if an area
    // is destroyed by an attack or spell, the cubic open space where the
    // value is the damage needed to collapse the ceiling, and the follow-up
    // chain reaction check per the R512 procedure after a collapse) and the
    // Table 19 grid (the 10-ft tube room 50, the 20-ft cube room 90, the 3-ft
    // column 10, the 10-ft column 100, the 10-ft square wall 20, the small
    // wooden bridge 12, the small stone bridge 40, the large stone bridge 80,
    // the per-1-ft rock ledge 10, the small-cavern ceiling 100, the
    // large-cavern ceiling 250, the small stalactite 8 and the large
    // stalactite 20). The hypothermia pins the damp-chill preamble with the
    // one-turn swimming onset assuming no subterranean heat source, the
    // shallow-water reduction (knee-to-waist deep one hour, shallower than
    // knee no threat), the Constitution Check after onset with 1d6 lost on a
    // failure and repeated every turn, the losses accumulating until an
    // external heat source is reached and continuing even out of the water,
    // the 1d6-per-turn recovery by a fire or the close presence of
    // warm-blooded creatures until fully recovered, the cold-adapted and
    // ring-of-warmth immunity, and the grease or oil coating doubling both
    // the pre-check time and the check interval.
    {
        using namespace rules;
        int bad = 0;
    if (dnyT19RowCount() != 13
            || dnySwimTurnsToOnset() != 1
            || dnyWadingOnsetHours() != 1
            || dnyLossPerFailDice() != 1
            || dnyLossPerFailSides() != 6
            || dnyCheckEveryTurns() != 1
            || dnyRecoveryPerTurnDice() != 1
            || dnyRecoveryPerTurnSides() != 6
            || dnyGreaseTimeMult() != 2
            || !dnyFortificationsHaveDpv()
            || !dnyDpvDestroysOnAttackOrSpell()
            || !dnyCubicOpenSpaceCeiling()
            || !dnyCollapseChecksChainReaction()
            || !dnyDampChillUnhealthy()
            || !dnyNoHeatSourceAssumed()
            || !dnyShallowWaterReducesRisk()
            || !dnyKneeToWaistOneHour()
            || !dnyShallowerThanKneeNoThreat()
            || !dnyConCheckOnOnset()
            || !dnyLossesAccumulateUntilHeat()
            || !dnyLossContinuesOutOfWater()
            || !dnyFireOrWarmCreaturesRecover()
            || !dnyRecoveryUntilFullyRecovered()
            || !dnyColdAdaptedOrRingImmune()
            || !dnyGreaseDoublesInterval()
        )
            ++bad;
        // the Table 19 underground structure DPV grid
        int C19[13][2] = {
            {0,50},
            {1,90},
            {2,10},
            {3,100},
            {4,20},
            {5,12},
            {6,40},
            {7,80},
            {8,10},
            {9,100},
            {10,250},
            {11,8},
            {12,20},
            };
        for (int b = 0;
             b < dnyT19RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnyT19Key(b);
            vals[1] = dnyT19Dpv(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C19[b][c])
                    ++bad;
            }
        }
        // the Table 19 rooms and columns: the 10-ft tube 50, the 20-ft cube
        // 90, the 3-ft column 10 and the 10-ft column 100 (the Capture garble
        // 104 = 10-ft, settled by the chapter and appendix reads).
    if (dnyT19Key(0) != 0
            || dnyT19Dpv(0) != 50
            || dnyT19Key(1) != 1
            || dnyT19Dpv(1) != 90
            || dnyT19Key(2) != 2
            || dnyT19Dpv(2) != 10
            || dnyT19Key(3) != 3
            || dnyT19Dpv(3) != 100
        )
            ++bad;
        // the Table 19 wall and bridges: the 10-ft square wall 20, the small
        // wooden bridge 12, the small stone bridge 40 and the large stone
        // bridge 80.
    if (dnyT19Key(4) != 4
            || dnyT19Dpv(4) != 20
            || dnyT19Key(5) != 5
            || dnyT19Dpv(5) != 12
            || dnyT19Key(6) != 6
            || dnyT19Dpv(6) != 40
            || dnyT19Key(7) != 7
            || dnyT19Dpv(7) != 80
        )
            ++bad;
        // the Table 19 ledges, ceilings and stalactites: the per-1-ft rock
        // ledge 10, the small-cavern ceiling 100, the large-cavern ceiling
        // 250, the small stalactite 8 and the large stalactite 20.
    if (dnyT19Key(8) != 8
            || dnyT19Dpv(8) != 10
            || dnyT19Key(9) != 9
            || dnyT19Dpv(9) != 100
            || dnyT19Key(10) != 10
            || dnyT19Dpv(10) != 250
            || dnyT19Key(11) != 11
            || dnyT19Dpv(11) != 8
            || dnyT19Key(12) != 12
            || dnyT19Dpv(12) != 20
        )
            ++bad;
        // the DPV section: the DMG page-110 fortification seam, the
        // destroy-on-attack-or-spell use, the cubic-open-space
        // ceiling-collapse reading, and the chain reaction follow-up check.
    if (dnyFortificationsHaveDpv() != 1
            || dnyDpvDestroysOnAttackOrSpell() != 1
            || dnyCubicOpenSpaceCeiling() != 1
            || dnyCollapseChecksChainReaction() != 1
        )
            ++bad;
        // the hypothermia onset: one turn of swimming in typical underground
        // water, assuming no subterranean heat source warming it.
    if (dnySwimTurnsToOnset() != 1
            || dnyNoHeatSourceAssumed() != 1
            || dnyDampChillUnhealthy() != 1
        )
            ++bad;
        // the shallow-water risk reduction: knee-to-waist deep delays onset
        // to one hour, and shallower than knee deep is no threat at all.
    if (dnyKneeToWaistOneHour() != 1
            || dnyWadingOnsetHours() != 1
            || dnyShallowerThanKneeNoThreat() != 1
            || dnyShallowWaterReducesRisk() != 1
        )
            ++bad;
        // the hypothermia check cycle: a Constitution Check after onset, 1d6
        // lost on a failure, repeated every turn with losses accumulating
        // until an external heat source is reached - even out of the water.
    if (dnyConCheckOnOnset() != 1
            || dnyLossPerFailDice() != 1
            || dnyLossPerFailSides() != 6
            || dnyCheckEveryTurns() != 1
            || dnyLossesAccumulateUntilHeat() != 1
            || dnyLossContinuesOutOfWater() != 1
        )
            ++bad;
        // the recovery: a fire or the close presence of warm-blooded
        // creatures restores 1d6 hit points per turn until the losses are
        // fully recovered.
    if (dnyFireOrWarmCreaturesRecover() != 1
            || dnyRecoveryPerTurnDice() != 1
            || dnyRecoveryPerTurnSides() != 6
            || dnyRecoveryUntilFullyRecovered() != 1
        )
            ++bad;
        // the immunity: cold-adapted creatures and a ring of warmth are not
        // susceptible.
    if (dnyColdAdaptedOrRingImmune() != 1
        )
            ++bad;
        // the grease or oil coating: doubles both the time before the first
        // Constitution Check and the interval between checks.
    if (dnyGreaseTimeMult() != 2
            || dnyGreaseDoublesInterval() != 1
        )
            ++bad;
        // the Table 19 carries thirteen formations.
    if (dnyT19RowCount() != 13
        )
            ++bad;
        // the Table 19 grid cell-for-cell, rows 0-6: the rooms, columns,
        // wall, and the wooden and small stone bridges.
    if (dnyT19Key(0) != 0
            || dnyT19Dpv(0) != 50
            || dnyT19Key(1) != 1
            || dnyT19Dpv(1) != 90
            || dnyT19Key(2) != 2
            || dnyT19Dpv(2) != 10
            || dnyT19Key(3) != 3
            || dnyT19Dpv(3) != 100
            || dnyT19Key(4) != 4
            || dnyT19Dpv(4) != 20
            || dnyT19Key(5) != 5
            || dnyT19Dpv(5) != 12
            || dnyT19Key(6) != 6
            || dnyT19Dpv(6) != 40
        )
            ++bad;
        // the Table 19 grid cell-for-cell, rows 7-12: the large stone bridge,
        // rock ledge, both cavern ceilings and both stalactites.
    if (dnyT19Key(7) != 7
            || dnyT19Dpv(7) != 80
            || dnyT19Key(8) != 8
            || dnyT19Dpv(8) != 10
            || dnyT19Key(9) != 9
            || dnyT19Dpv(9) != 100
            || dnyT19Key(10) != 10
            || dnyT19Dpv(10) != 250
            || dnyT19Key(11) != 11
            || dnyT19Dpv(11) != 8
            || dnyT19Key(12) != 12
            || dnyT19Dpv(12) != 20
        )
            ++bad;
        printf("R513 DSG DPV and hypothermia audit: bad %d\n", bad);
        if (bad) return 1;
    }
