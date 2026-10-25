    // ---- R450 WSG swimming pin audit ----
    // The swimming slice pins the proficiency gate (only proficient swimmers
    // propel themselves; the nonproficient do not simply sink), the three
    // sub-skills (endurance, speed, diving) with encumbrance as the key
    // factor, Table 24 (the five encumbrance rows x the four functions, the
    // multipliers from x2 down to the dash - only diving survives severe
    // encumbrance, tripled), the endurance rules (the levels+con base in
    // turns, the 3-turns-per-rest-turn rate, the doubled high-speed rate with
    // the 1/10 endurance cut rounded up and the one-for-one high-speed
    // recovery), and the speed rules (the 40/30 feet base rates, the 2/3
    // subsurface cut rounded up, the strength ladder +1/+2/+3, the light 1-3
    // and strong 4-6 current modifiers, the 0-inch hold position, the
    // mercy-of-the-current drift at 1-3 inches, and the surface-only high
    // speed halved at a 0 rate) (rules/wsgswim.h, prefix wsm); census 374 ->
    // 375.
    {
        using namespace rules;
        int bad = 0;
    if (wsmSubSkillCount() != 3
            || wsmEncRowCount() != 5
            || wsmRestRegainPerTurn() != 3
            || wsmHighSpeedMult() != 2
            || wsmHighSpeedEndDiv() != 10
            || wsmHumanSwimRateFt() != 40
            || wsmOtherSwimRateFt() != 30
            || wsmSubsurfaceNum() != 2
            || wsmSubsurfaceDen() != 3
            || wsmStr1617BonusIn() != 1
            || wsmStr18BonusIn() != 2
            || wsmStr1801BonusIn() != 3
            || wsmLightCurMaxIn() != 3
            || wsmStrongCurMinIn() != 4
            || wsmStrongCurMaxIn() != 6
            || wsmMercyDriftMaxIn() != 3
            || !wsmOnlyProficientSwim()
            || !wsmNonproficientNotSink()
            || !wsmEncumbranceKeyFactor()
            || !wsmDashMeansImpossible()
            || !wsmSevereSinksCannotSurface()
            || !wsmEnduranceLevelsPlusCon()
            || !wsmHighSpeedEndTenthRoundUp()
            || !wsmHighSpeedRestOneForOne()
            || !wsmMonsterRateSupersedes()
            || !wsmZeroRateHoldPosition()
            || !wsmNegativeRateMercy()
            || !wsmCurrentDmDetermined()
            || !wsmNoHighSpeedSubsurface()
            || !wsmHighSpeedHalvedAtZero()
        )
            ++bad;
        // the Table 24 grid: the five encumbrance rows (none, light,
        // moderate, heavy, severe) x the four functions (endurance, speed,
        // diving, surfacing), each cell split into the numerator and
        // denominator of the multiplier - a 0 numerator is the printed dash
        // (impossible)
        int C24[5][8] = {
            {2,1,2,1,1,1,2,1},
            {1,1,1,1,1,1,1,1},
            {1,2,1,2,2,1,1,2},
            {1,4,1,4,3,1,1,4},
            {0,1,0,1,3,1,0,1},
            };
        for (int b = 0;
             b < wsmEncRowCount();
             ++b) {
            int vals[8];
            vals[0] = wsmEndNum(b);
            vals[1] = wsmEndDen(b);
            vals[2] = wsmSpdNum(b);
            vals[3] = wsmSpdDen(b);
            vals[4] = wsmDiveNum(b);
            vals[5] = wsmDiveDen(b);
            vals[6] = wsmSurfNum(b);
            vals[7] = wsmSurfDen(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != C24[b][c])
                    ++bad;
            }
        }
        // the two poles: the unencumbered endurance doubles, and the severely
        // encumbered dive stays tripled while everything else dashes
    if (wsmEndNum(0) != 2
            || wsmEndDen(0) != 1
            || wsmDiveNum(4) != 3
            || wsmEndNum(4) != 0
        )
            ++bad;
        // the printed endurance numbers: the three-turn rest rate, the
        // doubled high-speed rate, the one-tenth endurance cut
    if (wsmRestRegainPerTurn() != 3
            || wsmHighSpeedMult() != 2
            || wsmHighSpeedEndDiv() != 10
        )
            ++bad;
        // the base rates: 40 feet for humans, 30 for the other races - the
        // human rate is four thirds of the other rate
    if (wsmHumanSwimRateFt() != 40
            || wsmOtherSwimRateFt() != 30
            || wsmHumanSwimRateFt() != 4 * wsmOtherSwimRateFt() / 3
        )
            ++bad;
        // the strength ladder climbs one inch at a time: +1, +2, +3 for
        // strength 16-17, 18, 18/01+
    if (wsmStr1617BonusIn() != 1
            || wsmStr18BonusIn() != 2
            || wsmStr1801BonusIn() != 3
            || wsmStr18BonusIn() - wsmStr1617BonusIn() != 1
            || wsmStr1801BonusIn() - wsmStr18BonusIn() != 1
        )
            ++bad;
        // the current ranges: light tops at 3, strong starts at 4 and tops at
        // 6, and the mercy drift tops at 3
    if (wsmStrongCurMinIn() != wsmLightCurMaxIn() + 1
            || wsmStrongCurMaxIn() != 6
            || wsmMercyDriftMaxIn() != 3
        )
            ++bad;
        // the none row doubles the light baseline in endurance, speed and
        // surfacing (x2 vs x1)
    if (wsmEndNum(0) != 2 * wsmEndNum(1)
            || wsmSpdNum(0) != 2 * wsmSpdNum(1)
            || wsmSurfNum(0) != 2 * wsmSurfNum(1)
        )
            ++bad;
        // moderate halves and heavy quarters the three surface functions
        // (denominators 2 and 4)
    if (wsmEndDen(2) != 2
            || wsmSpdDen(2) != 2
            || wsmSurfDen(2) != 2
            || wsmEndDen(3) != 4
            || wsmSpdDen(3) != 4
            || wsmSurfDen(3) != 4
        )
            ++bad;
        // the dive never dashes and only climbs: 1, 1, 2, 3, 3 - moderate
        // strictly beats light, heavy strictly beats moderate, severe holds
        // the heavy triple
    if (wsmDiveNum(2) <= wsmDiveNum(1)
            || wsmDiveNum(3) <= wsmDiveNum(2)
            || wsmDiveNum(4) < wsmDiveNum(3)
        )
            ++bad;
        // the severe row dashes endurance, speed and surfacing - only diving
        // survives, a whole-number triple
    if (wsmEndNum(4) != 0
            || wsmSpdNum(4) != 0
            || wsmSurfNum(4) != 0
            || wsmDiveDen(4) != 1
        )
            ++bad;
        printf("R450 WSG swimming pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
