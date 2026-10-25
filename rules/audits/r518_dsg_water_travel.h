    // ---- R518 DSG water travel audit ----
    // The DSG water travel pins the underground boating rules (the deepening
    // riverbeds raising old access tunnels, the low-ceiling impossibility,
    // the folding and collapsible and creature boats, the scale-model test
    // for tight bends, the Table 21 eight-boat movement grid with the Table
    // 22 standstill rounds, the movement-relative-to-water-only rule with the
    // 30/150 upstream-downstream example, the Table 23 draught and ceiling
    // minima pinned in inches and half-feet, the Table 24 nonproficiency
    // movement penalties and capsize chances with the one-proficient and
    // half-proficient exemptions and the medium-or-slower assumption, the
    // collision rules with the lantern and infravision and vision-range
    // readings, the Table 25 narrow/average/wide placid/medium/rapid
    // collision grid, the 5%-per-30-ft damage math with the
    // difference-reading hull damage, the Table 26 eight-band damage grid
    // with its 1d6-hour, 2d4+2-turn, 2d4-turn, 1d6-round and 1d6-piece
    // effects, the drop-off checks at 5% per foot with the 99/00 miraculous
    // survival and the Proficiency Check capsize save, the bailing rules
    // canceling one small hole per character, and the capsizing rules with
    // the 1d4-round refloat and the boatwright repair seam).
    {
        using namespace rules;
        int bad = 0;
    if (dnuT21RowCount() != 8
            || dnuT22RowCount() != 8
            || dnuT23RowCount() != 8
            || dnuT24RowCount() != 8
            || dnuT25RowCount() != 9
            || dnuT26RowCount() != 8
            || dnuExampleStreamFtPerRound() != 60
            || dnuExampleCanoeFtPerRound() != 90
            || dnuExampleUpstreamNetFt() != 30
            || dnuExampleDownstreamFt() != 150
            || dnuDamageBasePctPerSlice() != 5
            || dnuDamageSpeedSliceFt() != 30
            || dnuExampleDamagePct() != 15
            || dnuExampleHullDamagePct() != 10
            || dnuDropoffDamagePctPerFoot() != 5
            || dnuDropoffCapsizePctPerFoot() != 5
            || dnuRefloatRoundsDice() != 1
            || dnuRefloatRoundsSides() != 4
            || dnuT26SlightLeakHoursDice() != 1
            || dnuT26SlightLeakHoursSides() != 6
            || dnuT26SmallHoleTurnsDice() != 2
            || dnuT26SmallHoleTurnsSides() != 4
            || dnuT26SmallHoleBonusTurns() != 2
            || dnuT26ManyHolesDice() != 2
            || dnuT26ManyHolesSides() != 4
            || dnuT26LargeHoleRoundsDice() != 1
            || dnuT26LargeHoleRoundsSides() != 6
            || dnuT26PiecesDice() != 1
            || dnuT26PiecesSides() != 6
            || !dnuRiverbedDeepeningRaisesTunnels()
            || !dnuLowCeilingBlocksBoatTravel()
            || !dnuWeatherAbsentUnderground()
            || !dnuFoldingBoatIdeal()
            || !dnuCollapsibleBoatsWeaker()
            || !dnuCreatureBoatsAcquirable()
            || !dnuScaleModelForTightBends()
            || !dnuMovementRelativeToWaterOnly()
            || !dnuMaxSpeedIsHardWork()
            || !dnuCoastingReverseOfAcceleration()
            || !dnuRatesAssumeProficientCrew()
            || !dnuMoveModifierEachRound()
            || !dnuCapsizeOnEntryExitAndRisky()
            || !dnuOneProficientStopsCapsize()
            || !dnuHalfProficientStopsPenalty()
            || !dnuPenaltiesAssumeMediumOrSlower()
            || !dnuLanternAvoidsDarkCollisions()
            || !dnuVisionRuleAvoidsCollisions()
            || !dnuInfravisionCanNavigate()
            || !dnuBlindTravelChecksEachRound()
            || !dnuDamageCheckIsD100()
            || !dnuHullDamageIsDifference()
            || !dnuDropoffMiraculousSurvival()
            || !dnuCapsizeProficiencyCheckPrevents()
            || !dnuBailingStrenuousUnlessSlight()
            || !dnuBailingCancelsOneSmallHole()
            || !dnuCapsizeDropsLooseObjects()
            || !dnuRecoveryImpossibleInRapidWater()
            || !dnuCapsizedBoatsDoNotSink()
            || !dnuDamageRequiresRepairBeforeRefloat()
        )
            ++bad;
        // the Table 21 boat movement rates grid (the djvu garble Oar/Paddie =
        // Oar/Paddle)
        int C21[8][2] = {
            {90,120},
            {30,45},
            {45,60},
            {30,45},
            {20,30},
            {120,180},
            {90,120},
            {120,180},
            };
        for (int b = 0;
             b < dnuT21RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnuT21NormalFt(b);
            vals[1] = dnuT21MaxFt(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C21[b][c])
                    ++bad;
            }
        }
        // the Table 22 standstill grid
        int C22[8][2] = {
            {1,3},
            {1,3},
            {2,5},
            {2,6},
            {5,10},
            {1,2},
            {1,3},
            {1,2},
            };
        for (int b = 0;
             b < dnuT22RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnuT22ToNormalRounds(b);
            vals[1] = dnuT22ToMaxRounds(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C22[b][c])
                    ++bad;
            }
        }
        // the Table 23 draught and ceilings grid (fractions pinned as whole
        // units: draught in inches, ceiling in half-feet)
        int C23[8][2] = {
            {6,4},
            {6,6},
            {9,6},
            {9,6},
            {12,8},
            {3,3},
            {4,4},
            {3,3},
            };
        for (int b = 0;
             b < dnuT23RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnuT23DraughtInches(b);
            vals[1] = dnuT23CeilingHalfFeet(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C23[b][c])
                    ++bad;
            }
        }
        // the Table 24 nonproficiency penalties grid
        int C24[8][2] = {
            {30,5},
            {15,10},
            {15,0},
            {10,0},
            {5,0},
            {60,20},
            {30,10},
            {60,25},
            };
        for (int b = 0;
             b < dnuT24RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnuT24MovePenaltyFtPerRound(b);
            vals[1] = dnuT24CapsizePct(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C24[b][c])
                    ++bad;
            }
        }
        // the Table 25 collision probability grid (row key = width x 3 +
        // flow: 0 narrow placid through 8 wide rapid)
        int C25[9][2] = {
            {1,10},
            {5,20},
            {20,40},
            {0,5},
            {2,10},
            {10,20},
            {0,1},
            {0,4},
            {4,8},
            };
        for (int b = 0;
             b < dnuT25RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnuT25ProfPct(b);
            vals[1] = dnuT25NonprofPct(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C25[b][c])
                    ++bad;
            }
        }
        // the Table 26 boat damage grid
        int C26[8][2] = {
            {1,5},
            {6,10},
            {11,20},
            {21,45},
            {45,60},
            {61,80},
            {81,98},
            {99,100},
            };
        for (int b = 0;
             b < dnuT26RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnuT26Lo(b);
            vals[1] = dnuT26Hi(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C26[b][c])
                    ++bad;
            }
        }
        // the relative-movement example: the 90-ft canoe in the 60-ft stream
        // nets 30 ft/round upstream and 150 downstream.
    if (dnuExampleStreamFtPerRound() != 60
            || dnuExampleCanoeFtPerRound() != 90
            || dnuExampleUpstreamNetFt() != 30
            || dnuExampleDownstreamFt() != 150
        )
            ++bad;
        // the collision damage math: 5% per 30 ft/round of speed, the 90-ft
        // boat at 15%, and the 05 roll meaning 10% hull damage.
    if (dnuDamageBasePctPerSlice() != 5
            || dnuDamageSpeedSliceFt() != 30
            || dnuExampleDamagePct() != 15
            || dnuExampleHullDamagePct() != 10
        )
            ++bad;
        // the drop-off checks at 5% per foot for both damage and capsize, and
        // the 1d4-round refloating of a capsized boat.
    if (dnuDropoffDamagePctPerFoot() != 5
            || dnuDropoffCapsizePctPerFoot() != 5
            || dnuRefloatRoundsDice() != 1
            || dnuRefloatRoundsSides() != 4
        )
            ++bad;
        // the Table 26 effect dice: the slight-leak 1d6 hours, the small-hole
        // 2d4+2 turns, the many-holes 2d4 holes and 2d4 turns, the large-hole
        // 1d6 rounds, and the 1d6 pieces.
    if (dnuT26SlightLeakHoursDice() != 1
            || dnuT26SlightLeakHoursSides() != 6
            || dnuT26SmallHoleTurnsDice() != 2
            || dnuT26SmallHoleTurnsSides() != 4
            || dnuT26SmallHoleBonusTurns() != 2
            || dnuT26ManyHolesDice() != 2
            || dnuT26ManyHolesSides() != 4
            || dnuT26LargeHoleRoundsDice() != 1
            || dnuT26LargeHoleRoundsSides() != 6
            || dnuT26PiecesDice() != 1
            || dnuT26PiecesSides() != 6
        )
            ++bad;
        // Table 21 anchor rows: the small rowboat 90/120, the large barge
        // 20/30, the small canoe and kayak 120/180.
    if (dnuT21NormalFt(0) != 90
            || dnuT21MaxFt(0) != 120
            || dnuT21NormalFt(4) != 20
            || dnuT21MaxFt(4) != 30
            || dnuT21NormalFt(5) != 120
            || dnuT21MaxFt(5) != 180
            || dnuT21NormalFt(7) != 120
            || dnuT21MaxFt(7) != 180
        )
            ++bad;
        // Table 22 anchor rows: the large barge needs 5 rounds to normal and
        // 10 to maximum, the small barge/raft 2 and 6.
    if (dnuT22ToNormalRounds(4) != 5
            || dnuT22ToMaxRounds(4) != 10
            || dnuT22ToNormalRounds(3) != 2
            || dnuT22ToMaxRounds(3) != 6
        )
            ++bad;
        // Table 23 anchor rows: the small rowboat 1/2 ft draught under a 2-ft
        // ceiling, the large barge 1 ft under 4 ft, the large canoe 1/3 ft
        // and the kayak 1/4 ft.
    if (dnuT23DraughtInches(0) != 6
            || dnuT23CeilingHalfFeet(0) != 4
            || dnuT23DraughtInches(4) != 12
            || dnuT23CeilingHalfFeet(4) != 8
            || dnuT23DraughtInches(6) != 4
            || dnuT23DraughtInches(7) != 3
        )
            ++bad;
        // Table 24 anchor rows: the small rowboat -30 and 5%, the small canoe
        // -60 and 20% (the djvu garble 2096 = 20%), the kayak -60 and 25%.
    if (dnuT24MovePenaltyFtPerRound(0) != 30
            || dnuT24CapsizePct(0) != 5
            || dnuT24MovePenaltyFtPerRound(5) != 60
            || dnuT24CapsizePct(5) != 20
            || dnuT24MovePenaltyFtPerRound(7) != 60
            || dnuT24CapsizePct(7) != 25
        )
            ++bad;
        // Table 25 anchor cells: the narrow rapid 20%/40%, the narrow placid
        // 1%/10%, the wide rapid 4%/8%.
    if (dnuT25ProfPct(2) != 20
            || dnuT25NonprofPct(2) != 40
            || dnuT25ProfPct(0) != 1
            || dnuT25NonprofPct(0) != 10
            || dnuT25ProfPct(8) != 4
            || dnuT25NonprofPct(8) != 8
        )
            ++bad;
        // Table 26 anchor rows: the hull-split band pins as 45-60 exactly as
        // printed (the band overlaps the 21-45 large-holes band at 45), and
        // the no-damage band 99-00 pins as 99-100.
    if (dnuT26Lo(4) != 45
            || dnuT26Hi(4) != 60
            || dnuT26Lo(7) != 99
            || dnuT26Hi(7) != 100
        )
            ++bad;
        printf("R518 DSG water travel audit: bad %d\n", bad);
        if (bad) return 1;
    }
