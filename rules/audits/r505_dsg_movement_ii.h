    // ---- R505 DSG movement II audit ----
    // The DSG movement chapter part II pins the bridge rules (the maintained
    // no-check rule; the suspension 25-percent-per-character give-way with
    // the one-hand catch at -25; the anchor sabotage 1d8 rounds detectable
    // only by a thief; the sawed rope one round and visible; the wooden
    // 5-percent-per-year rot with the 1d20+20-year beams and the 50-percent
    // rotten step; the stone impervious, the arch collapse 1d4 rounds and the
    // instant foundation collapse; the rope bridge +50 with the -20 sabotaged
    // cling; the log bridge +40, +20 sloped, +80 crawling, with the move-log
    // ladder), the expanded falling rules (the cumulative dice with the
    // 6d6-at-30 example, the 20d6 and 10d6 caps, the 1,000-feet-per-round
    // rate, the 50-foot stop window, the landing ladder, the slope slide),
    // spelunking (the 2/3 ceiling, the hands-and-knees and prone penalties,
    // Table 7), excavation (the rubble and solid-barrier rates, Table 8),
    // fatigue and exhaustion (the 4/2 cycle, the shrinking check interval,
    // the -2 and -4 effects, the recoveries), the darkness movement (the
    // rates, the secret d12 course roll, Table 9), and the slippery surfaces
    // (the dex checks, the melee fall penalties, the crampons).
    {
        using namespace rules;
        int bad = 0;
    if (dmxSuspensionGiveWayPct() != 25
            || dmxSuspensionCatchBridgeModPct() != -25
            || dmxAnchorSabotageDie() != 8
            || dmxSawRopeRounds() != 1
            || dmxWoodRotPctPerYear() != 5
            || dmxWoodBeamDie() != 20
            || dmxWoodBeamBaseYears() != 20
            || dmxRottenStepPct() != 50
            || dmxArchCenterCollapseDie() != 4
            || dmxRopeBridgeModPct() != 50
            || dmxRopeSabotageClingModPct() != -20
            || dmxLogDiaHeightDiv() != 4
            || dmxLogBridgeModPct() != 40
            || dmxLogSlopedModPct() != 20
            || dmxLogCrawlModPct() != 80
            || dmxHumanLogFt() != 10
            || dmxStr17LogFt() != 20
            || dmxHillGiantLogFt() != 30
            || dmxLargeGiantLogLoFt() != 40
            || dmxLargeGiantLogHiFt() != 50
            || dmxFallIncrementPer10Ft() != 1
            || dmxThirtyFtFallDice() != 6
            || dmxFallCapDice() != 20
            || dmxWaterfallCapDice() != 10
            || dmxFallFtPerRound() != 1000
            || dmxStopWindowFt() != 50
            || dmxStopNonslipDiv() != 2
            || dmxStopSlightDiv() != 4
            || dmxRoughLandingMult() != 2
            || dmxSpikeDamageDie() != 6
            || dmxSparseSpikeMinDice() != 1
            || dmxSparseSpikeMaxDice() != 6
            || dmxDenseSpikeMinDice() != 3
            || dmxDenseSpikeMaxDice() != 18
            || dmxSoftLandingDiv() != 2
            || dmxVerySoftFailDiv() != 2
            || dmxWaterLandingDiePer100Ft() != 1
            || dmxExample250FtWaterDice() != 3
            || dmxSlideFreeFt() != 20
            || dmxSlideDiePer10Ft() != 1
            || dmxSlideLandingDiePer40Ft() != 1
            || dmxSlipperySlideLandingMult() != 2
            || dmxUprightMinCeilNum() != 2
            || dmxUprightMinCeilDen() != 3
            || dmxUprightRateNum() != 2
            || dmxUprightRateDen() != 3
            || dmxHandsKneesRateDiv() != 2
            || dmxHandsKneesAtkMod() != -5
            || dmxProneCeilDiv() != 4
            || dmxProneRateDiv() != 4
            || dmxProneAtkMod() != -8
            || dmxRubbleClearFtDie() != 4
            || dmxRubblePartialDieMult() != 2
            || dmxSolidRateDiv() != 4
            || dmxPassagewayRowCount() != 6
            || dmxArmorWidthRowCount() != 11
            || dmxCourseChangeRowCount() != 12
            || dmxT9RolledDirDie() != 6
            || dmxT9RolledRightLo() != 1
            || dmxT9RolledRightHi() != 3
            || dmxFatigueWorkTurns() != 4
            || dmxFatigueRestTurns() != 2
            || dmxFatigueFirstCheckTurns() != 6
            || dmxFatigueSecondCheckAfterTurns() != 5
            || dmxFatigueIntervalStepTurns() != 1
            || dmxFatigueRecoveryTurns() != 6
            || dmxFatigueAttrMod() != -2
            || dmxFatigueCombatMod() != -2
            || dmxFatigueEffectTurns() != 12
            || dmxExhaustedMod() != -4
            || dmxExhaustRecoveryTurns() != 6
            || dmxDarkSafeRateDiv() != 3
            || dmxDarkCourseDie() != 12
            || dmxDarkCourseRollEveryTurns() != 3
            || dmxDarkCourseShortModPerTurn() != -1
            || dmxDarkRoughFallDamage() != 1
            || dmxDarkRoughSafeRateDiv() != 6
            || dmxSlipRiseRounds() != 1
            || dmxSlipSlowdownRounds() != 1
            || dmxSlipFailAcPenalty() != 4
            || dmxSlipFailRiseRounds() != 1
            || dmxSlipGroundAtkMod() != -4
            || dmxCramponAttachTurns() != 1
            || dmxCramponNoiseMult() != 2
            || dmxCramponWearDie() != 6
            || !dmxMaintainedBridgeNoChecks()
            || !dmxSuspensionGiveWayPerChar()
            || !dmxAnchorSabotageThiefDetectOnly()
            || !dmxSawRopeVisible()
            || !dmxRottenStepSuspensionChecks()
            || !dmxStoneBridgeSabotageImmune()
            || !dmxStoneWeightCollapseRare()
            || !dmxFoundationCollapseInstant()
            || !dmxFoundationCollapseToNext()
            || !dmxRopeBridgeArmorRaceApply()
            || !dmxRopeSabotageUnmodifiedCheck()
            || !dmxLogWiderAutoCross()
            || !dmxStopSlipperyImpossible()
            || !dmxVerySoftSaveVsParalysis()
            || !dmxWaterLandingRoundUp()
            || !dmxNoCatchAndWaterSameRound()
            || !dmxWaterCheckSecondRoundAllowed()
            || !dmxSlipperySlideNoDamage()
            || !dmxHandsKneesLoseDexShieldAc()
            || !dmxHandsKneesLongWeaponsUnusable()
            || !dmxProneNoShieldDexAc()
            || !dmxProneWeaponLimitsWorse()
            || !dmxDragPackTighter()
            || !dmxSolidPickaxesAssumed()
            || !dmxFatigueHenchmenStay()
            || !dmxFatigueContinuingCheckEveryTurn()
            || !dmxFatigueCheckVsRevisedCon()
            || !dmxFatigueMarchNotStrenuous()
            || !dmxExhaustedNoVoluntaryLabor()
            || !dmxExhaustedInsteadOfFatigue()
            || !dmxExhaustCheckToFatigued()
            || !dmxDarkObstacleDexCheck()
            || !dmxDarkNeedDirectionMeans()
            || !dmxSlipStraightLineSafe()
            || !dmxSlipTurnStopRunDexCheck()
            || !dmxSlipFallNoDamage()
            || !dmxSlipHalfRateTurnFree()
            || !dmxSlipMeleeCheckEveryAttack()
            || !dmxCramponsNeverFall()
            || !dmxCramponRemoveHalfTurn()
        )
            ++bad;
        // the Table 7 grid: the six race rows x the tunnel-width and
        // crawl-height columns, pinned in inches (the feet-and-fraction print
        // converted at 12 inches the foot); the human, dwarf and half-orc
        // rows were image-only reads cross-checked against the tsv fragments.
        int C7[6][2] = {
            {24,12},
            {24,16},
            {24,12},
            {18,9},
            {18,9},
            {12,8},
            };
        for (int b = 0;
             b < dmxPassagewayRowCount();
             ++b) {
            int vals[2];
            vals[0] = dmxT7WidthIn(b);
            vals[1] = dmxT7HeightIn(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C7[b][c])
                    ++bad;
            }
        }
        // the Table 8 grid: the eleven armor rows x the width-increase
        // column, pinned in inches; the splint, banded, plate and field-plate
        // cells were image-only reads cross-checked against the tsv
        // fragments.
        int C8[11][1] = {
            {0},
            {2},
            {2},
            {3},
            {2},
            {3},
            {3},
            {6},
            {8},
            {10},
            {12},
            };
        for (int b = 0;
             b < dmxArmorWidthRowCount();
             ++b) {
            int vals[1];
            vals[0] = dmxT8WidthAddIn(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != C8[b][c])
                    ++bad;
            }
        }
        // the Table 9 grid: the twelve d12 rows x the degrees and direction
        // columns; rows 1-7 were image-only reads cross-checked against the
        // tsv fragments.
        int C9[12][2] = {
            {0,0},
            {0,0},
            {0,0},
            {45,1},
            {45,1},
            {45,2},
            {45,2},
            {60,1},
            {60,2},
            {90,1},
            {90,2},
            {135,3},
            };
        for (int b = 0;
             b < dmxCourseChangeRowCount();
             ++b) {
            int vals[2];
            vals[0] = dmxT9Deg(b);
            vals[1] = dmxT9Dir(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C9[b][c])
                    ++bad;
            }
        }
        // the printed fall ladder: a 30-foot fall totals 6d6 (1+2+3 dice),
        // the hard cap 20d6, the waterfall cap 10d6, the 1,000-feet-per-round
        // fall rate.
    if (dmxFallIncrementPer10Ft() != 1
            || dmxThirtyFtFallDice() != 6
            || dmxFallCapDice() != 20
            || dmxWaterfallCapDice() != 10
            || dmxFallFtPerRound() != 1000
        )
            ++bad;
        // the stop window is the first 50 feet; the slightly-slippery catch
        // at 1/4 is exactly half the nonslippery 1/2 chance.
    if (dmxStopWindowFt() != 50
            || dmxStopNonslipDiv() != 2
            || dmxStopSlightDiv() != 4
            || dmxStopSlightDiv() != 2 * dmxStopNonslipDiv()
        )
            ++bad;
        // the suspension bridge: 25 percent per character of giving way, the
        // one-hand catch at -25.
    if (dmxSuspensionGiveWayPct() != 25
            || dmxSuspensionCatchBridgeModPct() != -25
        )
            ++bad;
        // the wooden bridge: 5 percent rot per uninspected year, the beams
        // 1d20+20 years, the rotten step 50 percent.
    if (dmxWoodRotPctPerYear() != 5
            || dmxWoodBeamDie() != 20
            || dmxWoodBeamBaseYears() != 20
            || dmxRottenStepPct() != 50
        )
            ++bad;
        // the destroyed arch center collapses the stone bridge in 1d4 rounds.
    if (dmxArchCenterCollapseDie() != 4
        )
            ++bad;
        // the move-log ladder: a normal human 10 feet, Str 17-18 or an ogre
        // 20, a hill giant or young dragon 30, a large giant or dragon 40-50.
    if (dmxHumanLogFt() != 10
            || dmxStr17LogFt() != 20
            || dmxStr17LogFt() != 2 * dmxHumanLogFt()
            || dmxHillGiantLogFt() != 30
            || dmxLargeGiantLogLoFt() != 40
            || dmxLargeGiantLogHiFt() != 50
        )
            ++bad;
        // the log bridge +40, sloped +20, crawling or both hands free +80; a
        // log over 1/4 the character height is crossed automatically.
    if (dmxLogBridgeModPct() != 40
            || dmxLogSlopedModPct() != 20
            || dmxLogCrawlModPct() != 80
            || dmxLogDiaHeightDiv() != 4
        )
            ++bad;
        // the rope bridge +50 with the -20 sabotaged cling; the anchor
        // sabotage 1d8 rounds, the sawed rope one round.
    if (dmxRopeBridgeModPct() != 50
            || dmxRopeSabotageClingModPct() != -20
            || dmxAnchorSabotageDie() != 8
            || dmxSawRopeRounds() != 1
        )
            ++bad;
        // the landing ladder: rough doubles, soft halves, a failed very-soft
        // save still halves.
    if (dmxRoughLandingMult() != 2
            || dmxSoftLandingDiv() != 2
            || dmxVerySoftFailDiv() != 2
            || dmxVerySoftFailDiv() != dmxSoftLandingDiv()
        )
            ++bad;
        // the spike groupings: a 1d6 group impales on 1-6 spikes, a 3d6 group
        // on 3-18 (18 = 6 x 3), each spike an extra d6.
    if (dmxSparseSpikeMinDice() != 1
            || dmxSparseSpikeMaxDice() != 6
            || dmxDenseSpikeMinDice() != 3
            || dmxDenseSpikeMaxDice() != 18
            || dmxDenseSpikeMaxDice() != dmxSparseSpikeMaxDice() *
            dmxDenseSpikeMinDice()
            || dmxSpikeDamageDie() != 6
        )
            ++bad;
        // the printed water landing: a clean 250-foot entry costs 3d6, 1d6
        // per 100 feet rounded up.
    if (dmxWaterLandingDiePer100Ft() != 1
            || dmxExample250FtWaterDice() != 3
        )
            ++bad;
        // the slope slide: 20 feet free, 1d6 per 10 feet of slide, 1d6 per 40
        // feet of landing, a slippery slope lands double.
    if (dmxSlideFreeFt() != 20
            || dmxSlideDiePer10Ft() != 1
            || dmxSlideLandingDiePer40Ft() != 1
            || dmxSlipperySlideLandingMult() != 2
        )
            ++bad;
        // the tight squeeze: a 2/3 ceiling walks upright at 2/3 rate, hands
        // and knees at 1/2 rate with -5 attacks, prone at 1/4 rate with -8.
    if (dmxUprightMinCeilNum() != 2
            || dmxUprightMinCeilDen() != 3
            || dmxUprightRateNum() != 2
            || dmxUprightRateDen() != 3
            || dmxHandsKneesRateDiv() != 2
            || dmxHandsKneesAtkMod() != -5
            || dmxProneRateDiv() != 4
            || dmxProneAtkMod() != -8
        )
            ++bad;
        // the prone penalties are strictly worse than the hands-and-knees
        // penalties on both axes.
    if (dmxProneAtkMod() >= dmxHandsKneesAtkMod()
            || dmxProneRateDiv() <= dmxHandsKneesRateDiv()
        )
            ++bad;
        // the excavation: 1d4 feet of rubble per turn, 2d4 on a partial
        // block, solid barriers at 1/4 rate without pickaxes.
    if (dmxRubbleClearFtDie() != 4
            || dmxRubblePartialDieMult() != 2
            || dmxSolidRateDiv() != 4
        )
            ++bad;
        // the fatigue cycle: 4 turns of work against 2 of rest, the first
        // Constitution Check at 6 turns, the next after 5 more, the interval
        // then shrinking by one turn per check.
    if (dmxFatigueWorkTurns() != 4
            || dmxFatigueRestTurns() != 2
            || dmxFatigueFirstCheckTurns() != 6
            || dmxFatigueSecondCheckAfterTurns() != 5
            || dmxFatigueIntervalStepTurns() != 1
        )
            ++bad;
        // fatigued: -2 attributes and -2 attacks, damage and saves until 12
        // turns of rest; exhausted -4 instead (twice the fatigue drop); both
        // recoveries six turns.
    if (dmxFatigueAttrMod() != -2
            || dmxFatigueCombatMod() != dmxFatigueAttrMod()
            || dmxFatigueEffectTurns() != 12
            || dmxExhaustedMod() != 2 * dmxFatigueAttrMod()
            || dmxFatigueRecoveryTurns() != 6
            || dmxExhaustRecoveryTurns() != dmxFatigueRecoveryTurns()
        )
            ++bad;
        // the darkness rates: 1/3 safe probing, 1/6 over rough floors (twice
        // as slow again), the course roll every 3 turns with -1 per short
        // turn, the rough fall 1 point.
    if (dmxDarkSafeRateDiv() != 3
            || dmxDarkRoughSafeRateDiv() != 6
            || dmxDarkRoughSafeRateDiv() != 2 * dmxDarkSafeRateDiv()
            || dmxDarkCourseRollEveryTurns() != 3
            || dmxDarkCourseShortModPerTurn() != -1
            || dmxDarkRoughFallDamage() != 1
        )
            ++bad;
        // the course machinery: the secret 1d12 roll, the 135-degree row
        // resolving its direction on 1d6 with 1-3 to the right.
    if (dmxDarkCourseDie() != 12
            || dmxT9RolledDirDie() != 6
            || dmxT9RolledRightLo() != 1
            || dmxT9RolledRightHi() != 3
        )
            ++bad;
        // the melee fall: +4 AC penalty and no attack that round, rising the
        // next round; fighting from the ground keeps the +4 AC at -4 attacks.
    if (dmxSlipFailAcPenalty() != 4
            || dmxSlipGroundAtkMod() != -4
            || dmxSlipRiseRounds() != 1
            || dmxSlipFailRiseRounds() != dmxSlipRiseRounds()
            || dmxSlipFailAcPenalty() != -1 * dmxSlipGroundAtkMod()
        )
            ++bad;
        // the crampons: one turn to attach, twice the noise on nonslippery
        // ground, worn out in 1d6 miles of such abuse.
    if (dmxCramponAttachTurns() != 1
            || dmxCramponNoiseMult() != 2
            || dmxCramponWearDie() != 6
        )
            ++bad;
        // the one-round slowdown from normal to 1/2 speed buys a check-free
        // turn.
    if (dmxSlipSlowdownRounds() != 1
        )
            ++bad;
        // the Table 7 human row is 2 x 1 feet (24 x 12 inches), the halfling
        // 1 x 2/3 feet (12 x 8 inches).
    if (dmxT7WidthIn(0) != 24
            || dmxT7HeightIn(0) != 12
            || dmxT7WidthIn(5) != 12
            || dmxT7HeightIn(5) != 8
        )
            ++bad;
        // the half-orc row is 2 x 1 1/3 feet (a 16-inch crawl height), the
        // dwarf 2 x 1, the gnome and the elf 1 1/2 x 3/4 (18 x 9 inches).
    if (dmxT7WidthIn(1) != 24
            || dmxT7HeightIn(1) != 16
            || dmxT7HeightIn(2) != 12
            || dmxT7HeightIn(3) != 9
            || dmxT7HeightIn(4) != 9
            || dmxT7WidthIn(2) != 24
            || dmxT7WidthIn(3) != 18
            || dmxT7WidthIn(4) != 18
        )
            ++bad;
        // the cross-race reads: the half-orc crawl height runs 4 inches over
        // the human, the gnome width 6 inches over the halfling.
    if (dmxT7HeightIn(1) != dmxT7HeightIn(0) + 4
            || dmxT7WidthIn(3) != dmxT7WidthIn(5) + 6
        )
            ++bad;
        // the light armors: leather adds nothing; padded, studded leather and
        // ring add 1/6 foot (2 inches); scale, chain and splint 1/4 foot (3
        // inches).
    if (dmxT8WidthAddIn(0) != 0
            || dmxT8WidthAddIn(1) != 2
            || dmxT8WidthAddIn(2) != 2
            || dmxT8WidthAddIn(4) != 2
            || dmxT8WidthAddIn(3) != 3
            || dmxT8WidthAddIn(5) != 3
            || dmxT8WidthAddIn(6) != 3
        )
            ++bad;
        // the heavy armors: banded 1/2 foot (6 inches), plate 2/3 (8), field
        // plate 5/6 (10), full plate 1 foot (12).
    if (dmxT8WidthAddIn(7) != 6
            || dmxT8WidthAddIn(8) != 8
            || dmxT8WidthAddIn(9) != 10
            || dmxT8WidthAddIn(10) != 12
        )
            ++bad;
        // the width ladder identities: the full-plate 1-foot increase is six
        // times the padded 1/6, the plate 2/3 four times the padded.
    if (dmxT8WidthAddIn(10) != 6 * dmxT8WidthAddIn(1)
            || dmxT8WidthAddIn(8) != 4 * dmxT8WidthAddIn(1)
        )
            ++bad;
        // the Table 9 degrees: straight ahead, 45, 60, 90, and the 135
        // maximum (three times the 45).
    if (dmxT9Deg(0) != 0
            || dmxT9Deg(3) != 45
            || dmxT9Deg(7) != 60
            || dmxT9Deg(9) != 90
            || dmxT9Deg(11) != 135
            || dmxT9Deg(11) != 3 * dmxT9Deg(3)
        )
            ++bad;
        // the Table 9 directions: rows 1-3 straight, the 45/60/90 rows
        // alternating right and left, the 135 row rolled.
    if (dmxT9Dir(0) != 0
            || dmxT9Dir(3) != 1
            || dmxT9Dir(5) != 2
            || dmxT9Dir(7) != 1
            || dmxT9Dir(8) != 2
            || dmxT9Dir(9) != 1
            || dmxT9Dir(10) != 2
            || dmxT9Dir(11) != 3
        )
            ++bad;
        printf("R505 DSG movement II audit: bad %d\n", bad);
        if (bad) return 1;
    }
