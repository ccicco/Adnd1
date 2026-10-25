    // ---- R504 DSG movement I audit ----
    // The DSG movement chapter part I pins the check frames (the 1d20 ability
    // check equal-or-less with the dice substitution, the proficiency check
    // strictly less), the swimming block (the proficiency gate with the 1/3
    // humanoid-monster chance, the three functions, Table 1 with the five
    // encumbrance rows x the four functions in numerator/denominator cells,
    // the levels+con endurance with the treading double and the 1/10
    // high-speed cut and the equal high-speed rest, the 4/3-inch base rates
    // with the strength damage-bonus speed addendum capped at +3, the 20-foot
    // dive with the 10-foot jump-in bonus and the 5-per-10 height ladder
    // capped at the 40-foot jump, the 20-foot surfacing with the 5-foot
    // passive-float slowdown and the armor-removal rounds), the breath
    // economy (the 1/3 con base rounded up, the cumulative halvings, the
    // one-round floor, the -2 cumulative con checks, the +1 nonswimming
    // round), the moving-water effects (the relative-speed rule with the
    // 40-foot stream example, the waterfall half damage with the breath save
    // and the 100-foot/1-10 plunge split, the 1-10 danger rating as the check
    // cadence with the 1d6 failed-check damage and the five-or-less
    // high-speed forcing), the climbing block (the surface taxonomy, Table 2
    // with the nine rows and the thief-only rates halved for others with the
    // dexterity adjustment, the 2x and 10x slippery fall multipliers, the 40
    // percent non-thief rating, the armor/race/surface modifier ladders, the
    // tools with the 1d4 spike rounds and the 10 percent arrest failure and
    // the 15 percent ice-slip, Table 3, the grapple throw at 1/3 strength x
    // 10 with the noise ladder, the rappel at +50/+30 and 120 feet per
    // round), the jumping block (the 20-foot head start, the one-segment
    // jumps, Table 4 with the seven bands, the encumbrance and race modifiers
    // with the 2-foot floor), and the rope system (the 50 percent protrusion
    // chance, Table 5, the thrown loop with Table 6 and the 20 percent +1
    // percent ladder, the +30 crossing check each round, the swing with the
    // -5 per 10 feet and the 1d6 per 20-foot section, the belay with the
    // second check and the 3-foot edge rule and the -10 per faller, the
    // roping-together cascade at -10) (rules/dsgmove.h, prefix dmv); census
    // 428 -> 429.
    {
        using namespace rules;
        int bad = 0;
    if (dmvPart1Lo() != 12
            || dmvPart1Hi() != 19
            || dmvPart1PdfLo() != 13
            || dmvPart1PdfHi() != 20
            || dmvCheckDie() != 20
            || dmvMonsterSwimNum() != 1
            || dmvMonsterSwimDen() != 3
            || dmvSwimFuncCount() != 3
            || dmvUnderwaterRateNum() != 2
            || dmvUnderwaterRateDen() != 3
            || dmvT1RowCount() != 5
            || dmvEndurExampleTurns() != 23
            || dmvEndurExampleUnencTurns() != 46
            || dmvHighSpeedEndDiv() != 10
            || dmvHumanSwimIn() != 4
            || dmvDemiSwimIn() != 3
            || dmvStrSpeedBonusMaxIn() != 3
            || dmvStrExBonusIn() != 1
            || dmvStrExSpeedIn() != 5
            || dmvDiveRateFt() != 20
            || dmvJumpDiveBonusFt() != 10
            || dmvPerHeightFt() != 10
            || dmvHeightDepthBonusFt() != 5
            || dmvMaxJumpHeightFt() != 40
            || dmvExampleDiveNormalFt() != 30
            || dmvExampleDiveHeavyFt() != 70
            || dmvSurfaceRateFt() != 20
            || dmvPassiveFloatSlowerFt() != 5
            || dmvBackpackRemoveRounds() != 1
            || dmvArmorRemoveBase() != 10
            || dmvArmorExampleRounds() != 5
            || dmvBreathConDiv() != 3
            || dmvMinBreathRounds() != 1
            || dmvBreathCheckStep() != 2
            || dmvBreathExampleRounds() != 6
            || dmvExampleStreamFt() != 40
            || dmvUpstreamHoldIn() != 4
            || dmvExampleWashdownFt() != 10
            || dmvWaterfallDamageDiv() != 2
            || dmvShortPlungeMaxFt() != 100
            || dmvLongPlungeDiv() != 10
            || dmvDangerRatingLo() != 1
            || dmvDangerRatingHi() != 10
            || dmvRockDmgDie() != 6
            || dmvPoleDiaDiv() != 4
            || dmvSlopeFallDiv() != 2
            || dmvSlightFallMult() != 2
            || dmvSlipFallMult() != 10
            || dmvExThiefRoll() != 87
            || dmvExFailurePct() != 13
            || dmvExSlightFailPct() != 26
            || dmvExSlipRoll10() != 90
            || dmvExNormalRoll10() != 99
            || dmvHeavyClimbDiv() != 2
            || dmvNonThiefRatingPct() != 40
            || dmvClimbRowCount() != 9
            || dmvArmorMidPct() != 15
            || dmvArmorLightPct() != 5
            || dmvDwarfPct() != 5
            || dmvGnomePct() != 10
            || dmvHalflingPct() != 5
            || dmvHalforcPct() != 5
            || dmvTreeModPct() != 40
            || dmvSlopeModPct() != 25
            || dmvPoleModPct() != 20
            || dmvRopeWallModPct() != 40
            || dmvSpikeRoundsDie() != 4
            || dmvSpikeNoiseMi() != 1
            || dmvSpikeFailPct() != 10
            || dmvSpikeExamplePct() != 20
            || dmvRopeFallDiv() != 2
            || dmvIceSpikeFailPct() != 15
            || dmvGrappleStrDiv() != 3
            || dmvGrappleMultFt() != 10
            || dmvGrappleExampleFt() != 50
            || dmvSwingThrowRadiusFt() != 10
            || dmvSwingThrowMult() != 2
            || dmvRecoilDie() != 4
            || dmvSelfHitLoPct() != 1
            || dmvSelfHitHiPct() != 5
            || dmvSelfHitDie() != 6
            || dmvHookNoiseLoYd() != 100
            || dmvHookNoiseHiYd() != 400
            || dmvHookFailNoiseLoYd() != 200
            || dmvHookFailNoiseHiYd() != 800
            || dmvSlipFreeDie() != 6
            || dmvGrappleTargetCount() != 2
            || dmvRappelModPct() != 50
            || dmvFreeHangModPct() != 30
            || dmvRappelRateFt() != 120
            || dmvRunHeadStartFt() != 20
            || dmvJumpFloorFt() != 2
            || dmvHeavyJumpFt() != 1
            || dmvVeryHvyJumpFt() != 2
            || dmvEncumbJumpFt() != 4
            || dmvHalflingJumpFt() != 1
            || dmvDwarfJumpFt() != 2
            || dmvJumpBandCount() != 7
            || dmvProtrusionBasePct() != 50
            || dmvTieoffProtrusionPct() != 50
            || dmvRopeCrossModPct() != 30
            || dmvCaveTargetPct() != 20
            || dmvLoopPrepRadiusFt() != 10
            || dmvLoopBaseHitPct() != 20
            || dmvLoopBonusPerFt() != 1
            || dmvLoopExampleMaxFt() != 50
            || dmvLoopExamplePct() != 40
            || dmvLoopCoilDie() != 6
            || dmvLoopBandCount() != 5
            || dmvSwingCheckStepPct() != 5
            || dmvSwingCheckPerFt() != 10
            || dmvSwingSectionFt() != 20
            || dmvSwingDmgDie() != 6
            || dmvBelayEdgeFt() != 3
            || dmvBelayPerFallerPct() != 10
            || dmvRopeSlackLoFt() != 20
            || dmvRopeSlackHiFt() != 30
            || dmvCascadePct() != 10
            || dmvCrossTargetCount() != 3
            || !dmvAbilityCheckEqualOrLess()
            || !dmvSubstituteDiceOk()
            || !dmvProfCheckStrictlyLess()
            || !dmvNoMagicAssumed()
            || !dmvSwimProfRequiredAfloat()
            || !dmvBreathHeldWithoutProf()
            || !dmvAnimalsSwimIfForced()
            || !dmvFireStoneNeverEnter()
            || !dmvEnduranceNeedsBreath()
            || !dmvEncCategoriesMatchPhb()
            || !dmvEncumberedSinks()
            || !dmvEnduranceLevelsPlusCon()
            || !dmvTreadingDoublesEndurance()
            || !dmvEndurOutMeansDrown()
            || !dmvHighSpeedDoublesRate()
            || !dmvHighSpeedRestEqual()
            || !dmvStrBonusIsDamageBonus()
            || !dmvDiveModifiedByEnc()
            || !dmvJumpBonusUnmodifiedByEnc()
            || !dmvSurfaceModifiedByEnc()
            || !dmvHeavyMustActivelySwim()
            || !dmvIntentionalLoadingDmJudged()
            || !dmvBreathRoundedUp()
            || !dmvFullyEncumBreathBarred()
            || !dmvStrenuousHalvesBreath()
            || !dmvFullyEncumAlwaysStrenuous()
            || !dmvNoDeepBreathHalves()
            || !dmvConCheckAfterBreath()
            || !dmvNonswimBreathPlusOne()
            || !dmvCantAvoidUnsuspectedGas()
            || !dmvSpeedRelativeToWater()
            || !dmvRapidTransportUntilImpact()
            || !dmvWaterfallSaveVsBreath()
            || !dmvDangerRatingIsCadence()
            || !dmvLowRatingForcesHighSpeed()
            || !dmvAllClassesLimitedClimb()
            || !dmvOnlyThievesSheer()
            || !dmvNonThiefRoughRoutes()
            || !dmvMountaineerBoosts()
            || !dmvThiefOnlySmoothTypes()
            || !dmvIceNeedsTools()
            || !dmvThiefOnlyRates()
            || !dmvDexAdjAddsToRate()
            || !dmvBarkNonslippery()
            || !dmvRopeOnlyUnbracedCat()
            || !dmvSlopeSaveVsPetr()
            || !dmvNonslipperyDrySolid()
            || !dmvEncumbNoSheerWithoutTools()
            || !dmvHeavyGearHalfRate()
            || !dmvNormalGearFullRate()
            || !dmvNonThiefCheckEqualOrLess()
            || !dmvFailMeansNeverClimb()
            || !dmvFailCostsOneRound()
            || !dmvNoPlateNoShield()
            || !dmvLeatherNoPenalty()
            || !dmvShieldSlungNoBenefit()
            || !dmvSpikeShortensFall()
            || !dmvUseMultipleSpikes()
            || !dmvIceSpikeEachRound()
            || !dmvPoleWrapTechnique()
            || !dmvRappelFailFallsFull()
            || !dmvRappelNormalRestrictions()
            || !dmvAllClassesJump()
            || !dmvJumpOneSegment()
            || !dmvNoBackwardOrExtended()
            || !dmvJumpNoNormalPenalty()
            || !dmvJumpNoRacialHumans()
            || !dmvFarSideAnchorProblem()
            || !dmvArrowRopeImpractical()
            || !dmvRopeCrossCheckEachRound()
            || !dmvRopeCrossModsApply()
            || !dmvRopeAlwaysNonslippery()
            || !dmvRopeWallRateApplies()
            || !dmvLoopThiefOrFamiliar()
            || !dmvLoopRangeHalved()
            || !dmvLoopAttemptOneRound()
            || !dmvSwingPendulum()
            || !dmvSwingCheckToHold()
            || !dmvSwingDropFractions()
            || !dmvAnyoneCanBelay()
            || !dmvBelayRopeTied()
            || !dmvBelayPaysOutSlack()
            || !dmvBelayCheckArrests()
            || !dmvBelaySecondCheck()
            || !dmvBelaySpikeAnchored()
            || !dmvBelayBothEndsNoChecks()
            || !dmvRopedNoSingleFall()
            || !dmvRopedSlowestRate()
            || !dmvRopedBothSidesCheck()
            || !dmvRopedCascadeRecheck()
            || !dmvRopedEndSingleCheck()
        )
            ++bad;
        // the Table 1 grid: the five encumbrance rows (unencumbered, normal
        // gear, heavy gear, very heavy gear, encumbered) x the four functions
        // (endurance, speed, diving, surfacing), each cell split into the
        // numerator and denominator of the multiplier - a 0 numerator is the
        // printed none (impossible)
        int C1[5][8] = {
            {2,1,2,1,1,1,2,1},
            {1,1,1,1,1,1,1,1},
            {1,2,1,2,2,1,1,2},
            {1,4,1,4,3,1,1,4},
            {0,1,0,1,3,1,0,1},
            };
        int n1[8] = {0,0,0,0,0,0,0,0};
        int e1[8] = {1,0,1,0,0,0,1,0};
        for (int b = 0;
             b < dmvT1RowCount();
             ++b) {
            int vals[8];
            vals[0] = dmvT1EndNum(b);
            vals[1] = dmvT1EndDen(b);
            vals[2] = dmvT1SpdNum(b);
            vals[3] = dmvT1SpdDen(b);
            vals[4] = dmvT1DiveNum(b);
            vals[5] = dmvT1DiveDen(b);
            vals[6] = dmvT1SurfNum(b);
            vals[7] = dmvT1SurfDen(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != C1[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++n1[c];
            }
        }
        for (int c = 0; c < 8; ++c)
            if (n1[c] != e1[c])
                ++bad;
        // the Table 2 grid: the nine surface rows (very smooth, smooth with
        // cracks, rough, rough with ledges, ice wall, pole, tree with
        // branches, sloping wall, rope and wall) x the three surface
        // conditions (nonslippery, slightly slippery, slippery), in feet per
        // round - a 0 cell is the printed dash (unclimbable: the very smooth
        // slippery cell and both ice cells except slippery-with-tools)
        int C2[9][3] = {
            {6,3,0},
            {12,6,3},
            {18,9,6},
            {24,12,9},
            {0,0,6},
            {36,24,12},
            {60,40,20},
            {60,30,15},
            {40,30,20},
            };
        int n2[3] = {0,0,0};
        int e2[3] = {1,1,1};
        for (int b = 0;
             b < dmvClimbRowCount();
             ++b) {
            int vals[3];
            vals[0] = dmvT2NonslipFt(b);
            vals[1] = dmvT2SlightFt(b);
            vals[2] = dmvT2SlipFt(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != C2[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++n2[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (n2[c] != e2[c])
                ++bad;
        // the Table 3 grid: the two grapple target rows (rocky ledge, wooden
        // wall) x the three outcomes (miss, catch and slip, catch), each cell
        // the d100 maximum of its range
        int C3[2][3] = {
            {88,93,100},
            {70,74,100},
            };
        for (int b = 0;
             b < dmvGrappleTargetCount();
             ++b) {
            int vals[3];
            vals[0] = dmvT3Miss(b);
            vals[1] = dmvT3Slip(b);
            vals[2] = dmvT3Catch(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != C3[b][c])
                    ++bad;
            }
        }
        // the Table 4 grid: the seven level bands (1-6, 7-9, 10-12, 13-15,
        // 16-18, 19-22, 23+) x the standing and running broad jumps, each
        // cell split into the die and the plus feet (non-acrobats)
        int C4[7][4] = {
            {4,1,4,5},
            {4,2,4,6},
            {6,2,6,5},
            {6,3,6,6},
            {6,4,6,9},
            {6,5,6,12},
            {6,6,6,15},
            };
        for (int b = 0;
             b < dmvJumpBandCount();
             ++b) {
            int vals[4];
            vals[0] = dmvT4StandDie(b);
            vals[1] = dmvT4StandAdd(b);
            vals[2] = dmvT4RunDie(b);
            vals[3] = dmvT4RunAdd(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C4[b][c])
                    ++bad;
            }
        }
        // the Table 5 grid: the three crossing target rows (bare stone
        // walls/floor, cave formations, ruined foundation) x the three
        // outcomes (miss, catch and slip, catch), each cell the d100 maximum
        // of its range
        int C5[3][3] = {
            {82,89,100},
            {75,80,100},
            {66,71,100},
            };
        for (int b = 0;
             b < dmvCrossTargetCount();
             ++b) {
            int vals[3];
            vals[0] = dmvT5Miss(b);
            vals[1] = dmvT5Slip(b);
            vals[2] = dmvT5Catch(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != C5[b][c])
                    ++bad;
            }
        }
        // the Table 6 grid: the five level bands (1-4, 5-8, 9-12, 13-16, 17+)
        // x the maximum thrown-loop range in feet - the 40 through 90 ladder
        int C6[5][1] = {
            {40},
            {50},
            {60},
            {75},
            {90},
            };
        for (int b = 0;
             b < dmvLoopBandCount();
             ++b) {
            int vals[1];
            vals[0] = dmvLoopRangeFt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != C6[b][c])
                    ++bad;
            }
        }
        // the dmvJumpBand band-for boundaries
    if (dmvJumpBand(5) != 0
            || dmvJumpBand(6) != 0
            || dmvJumpBand(9) != 1
            || dmvJumpBand(7) != 1
            || dmvJumpBand(12) != 2
            || dmvJumpBand(10) != 2
            || dmvJumpBand(15) != 3
            || dmvJumpBand(13) != 3
            || dmvJumpBand(18) != 4
            || dmvJumpBand(16) != 4
            || dmvJumpBand(22) != 5
            || dmvJumpBand(19) != 5
            || dmvJumpBand(23) != 6
        )
            ++bad;
        // the dmvLoopBand band-for boundaries
    if (dmvLoopBand(3) != 0
            || dmvLoopBand(4) != 0
            || dmvLoopBand(8) != 1
            || dmvLoopBand(5) != 1
            || dmvLoopBand(12) != 2
            || dmvLoopBand(9) != 2
            || dmvLoopBand(16) != 3
            || dmvLoopBand(13) != 3
            || dmvLoopBand(17) != 4
        )
            ++bad;
        // the two Table 1 poles: the unencumbered endurance doubles, and the
        // encumbered dive stays tripled while endurance dashes
    if (dmvT1EndNum(0) != 2
            || dmvT1EndDen(0) != 1
            || dmvT1DiveNum(4) != 3
            || dmvT1EndNum(4) != 0
        )
            ++bad;
        // the printed endurance example: 23 turns normal gear, 46
        // unencumbered - the Table 1 doubled endurance
    if (dmvEndurExampleTurns() != 23
            || dmvEndurExampleUnencTurns() != 46
            || dmvEndurExampleUnencTurns() != 2 * dmvEndurExampleTurns()
        )
            ++bad;
        // the high-speed economy: the doubled rate, the 1/10 endurance cut,
        // the equal rest after exit
    if (dmvHighSpeedEndDiv() != 10
            || dmvHighSpeedDoublesRate() != 1
            || dmvHighSpeedRestEqual() != 1
        )
            ++bad;
        // the base rates and the strength-damage-bonus example: +1 for
        // strength 16, swimming 5 inches
    if (dmvHumanSwimIn() != 4
            || dmvDemiSwimIn() != 3
            || dmvStrSpeedBonusMaxIn() != 3
            || dmvStrExSpeedIn() != 5
            || dmvStrExBonusIn() != 1
        )
            ++bad;
        // the dive: 20 feet per round, the 10-foot jump-in bonus, +5 per 10
        // feet of height, capped at the 40-foot jump
    if (dmvDiveRateFt() != 20
            || dmvJumpDiveBonusFt() != 10
            || dmvPerHeightFt() != 10
            || dmvHeightDepthBonusFt() != 5
            || dmvMaxJumpHeightFt() != 40
        )
            ++bad;
        // the printed dive example: 30 feet normal gear, 70 heavy gear -
        // pinned as printed with the triples-vs-doubles tension against the
        // Table 1 heavy row noted
    if (dmvExampleDiveNormalFt() != 30
            || dmvExampleDiveHeavyFt() != 70
            || dmvExampleDiveHeavyFt() - dmvExampleDiveNormalFt() != 40
        )
            ++bad;
        // surfacing at 20 feet, the passive float 5 slower, the 1-round
        // backpack, the chain-mail 5-round armor removal
    if (dmvSurfaceRateFt() != 20
            || dmvPassiveFloatSlowerFt() != 5
            || dmvBackpackRemoveRounds() != 1
            || dmvArmorExampleRounds() != 5
            || dmvArmorRemoveBase() != 10
        )
            ++bad;
        // the breath economy: the 1/3 constitution base, the one-round floor,
        // the -2 cumulative step, the 16-constitution six-round example
    if (dmvBreathConDiv() != 3
            || dmvMinBreathRounds() != 1
            || dmvBreathCheckStep() != 2
            || dmvBreathExampleRounds() != 6
        )
            ++bad;
        // the breath halvings and the nonswimming +1 round
    if (dmvStrenuousHalvesBreath() != 1
            || dmvNoDeepBreathHalves() != 1
            || dmvFullyEncumAlwaysStrenuous() != 1
            || dmvNonswimBreathPlusOne() != 1
        )
            ++bad;
        // the check frames: ability checks equal-or-less, proficiency checks
        // strictly less - the inequality distinction
    if (dmvAbilityCheckEqualOrLess() != 1
            || dmvProfCheckStrictlyLess() != 1
            || dmvCheckDie() != 20
        )
            ++bad;
        // the 40-foot stream: the 4-inch human holds position, the 3-inch
        // demi-humans wash 10 feet downstream
    if (dmvExampleStreamFt() != 40
            || dmvUpstreamHoldIn() != 4
            || dmvExampleWashdownFt() != 10
        )
            ++bad;
        // the waterfall: half damage, the saved 100-foot plunge free of
        // damage, the 1/10 beyond, the 1d6 failed-check damage
    if (dmvWaterfallDamageDiv() != 2
            || dmvShortPlungeMaxFt() != 100
            || dmvLongPlungeDiv() != 10
            || dmvRockDmgDie() != 6
        )
            ++bad;
        // the 1-10 danger rating doubles as the check cadence, and five or
        // less forces high speed
    if (dmvDangerRatingLo() != 1
            || dmvDangerRatingHi() != 10
            || dmvLowRatingForcesHighSpeed() != 1
            || dmvDangerRatingIsCadence() != 1
        )
            ++bad;
        // the 40 percent non-thief base, the thief-only rates halved for
        // others, the dexterity adjustment, the heavy-gear halving
    if (dmvNonThiefRatingPct() != 40
            || dmvThiefOnlyRates() != 1
            || dmvDexAdjAddsToRate() != 1
            || dmvHeavyClimbDiv() != 2
        )
            ++bad;
        // the fall-chance multipliers: twice on slightly slippery, ten times
        // on slippery, with the 3rd-level 87/13/26 and 10th-level 99/90
        // examples
    if (dmvSlightFallMult() != 2
            || dmvSlipFallMult() != 10
            || dmvExThiefRoll() != 87
            || dmvExFailurePct() != 13
            || dmvExSlightFailPct() != 26
            || dmvExSlipRoll10() != 90
            || dmvExNormalRoll10() != 99
        )
            ++bad;
        // the armor and race climbing modifiers
    if (dmvArmorMidPct() != 15
            || dmvArmorLightPct() != 5
            || dmvDwarfPct() != 5
            || dmvGnomePct() != 10
            || dmvHalflingPct() != 5
            || dmvHalforcPct() != 5
        )
            ++bad;
        // the climbing surface bonuses: tree +40, sloping wall +25, pole +20,
        // rope and wall +40
    if (dmvTreeModPct() != 40
            || dmvSlopeModPct() != 25
            || dmvPoleModPct() != 20
            || dmvRopeWallModPct() != 40
        )
            ++bad;
        // the spike rules: 1d4 rounds to hammer, the 10 percent per-character
        // arrest failure (20 for two), the half-damage rope-broken fall, the
        // 15 percent ice-spike slip
    if (dmvSpikeRoundsDie() != 4
            || dmvSpikeFailPct() != 10
            || dmvSpikeExamplePct() != 20
            || dmvRopeFallDiv() != 2
            || dmvIceSpikeFailPct() != 15
        )
            ++bad;
        // the grapple throw: 1/3 strength times 10 (strength 15 gives 50
        // feet), doubled horizontally with the 10-foot clear swing radius
    if (dmvGrappleExampleFt() != 50
            || dmvGrappleStrDiv() != 3
            || dmvGrappleMultFt() != 10
            || dmvSwingThrowRadiusFt() != 10
            || dmvSwingThrowMult() != 2
        )
            ++bad;
        // the 1d4 recoil, the 01-05 self-hit for 1d6, and the 100-400/200-800
        // yard noise ladder
    if (dmvRecoilDie() != 4
            || dmvSelfHitLoPct() != 1
            || dmvSelfHitHiPct() != 5
            || dmvSelfHitDie() != 6
            || dmvHookNoiseLoYd() != 100
            || dmvHookNoiseHiYd() != 400
            || dmvHookFailNoiseLoYd() != 200
            || dmvHookFailNoiseHiYd() != 800
        )
            ++bad;
        // the rappel: +50 with a wall, +30 free-hanging, 120 feet per round
    if (dmvRappelModPct() != 50
            || dmvFreeHangModPct() != 30
            || dmvRappelRateFt() != 120
        )
            ++bad;
        // the 20-foot head start, the 2-foot floor, the encumbrance and race
        // foot penalties
    if (dmvRunHeadStartFt() != 20
            || dmvJumpFloorFt() != 2
            || dmvHeavyJumpFt() != 1
            || dmvVeryHvyJumpFt() != 2
            || dmvEncumbJumpFt() != 4
            || dmvHalflingJumpFt() != 1
            || dmvDwarfJumpFt() != 2
        )
            ++bad;
        // the broad-jumping band chain boundaries: 6/9/12/15/18/22 with the
        // 23+ tail
    if (dmvJumpBand(6) != 0
            || dmvJumpBand(7) != 1
            || dmvJumpBand(10) != 2
            || dmvJumpBand(16) != 4
            || dmvJumpBand(19) != 5
            || dmvJumpBand(22) != 5
            || dmvJumpBand(23) != 6
        )
            ++bad;
        // the loop band chain and the 40 through 90 range ladder
    if (dmvLoopBand(4) != 0
            || dmvLoopBand(5) != 1
            || dmvLoopBand(13) != 3
            || dmvLoopBand(17) != 4
            || dmvLoopRangeFt(0) != 40
            || dmvLoopRangeFt(3) != 75
            || dmvLoopRangeFt(4) != 90
        )
            ++bad;
        // the 20 percent loop base +1 per foot under max (the 50/30/40
        // example), the 1d6 coil, and the three 50/20/50 percent chances
    if (dmvLoopBaseHitPct() != 20
            || dmvLoopBonusPerFt() != 1
            || dmvLoopExampleMaxFt() != 50
            || dmvLoopExamplePct() != 40
            || dmvLoopCoilDie() != 6
            || dmvCaveTargetPct() != 20
            || dmvProtrusionBasePct() != 50
            || dmvTieoffProtrusionPct() != 50
        )
            ++bad;
        // the rope crossing: the +30 check each round, the always-nonslippery
        // rope, the rope-and-wall rate
    if (dmvRopeCrossModPct() != 30
            || dmvRopeCrossCheckEachRound() != 1
            || dmvRopeAlwaysNonslippery() != 1
            || dmvRopeWallRateApplies() != 1
        )
            ++bad;
        // the swing: -5 percent per 10 feet of rope on the check, 1d6 per
        // 20-foot section, fractions dropped
    if (dmvSwingCheckStepPct() != 5
            || dmvSwingCheckPerFt() != 10
            || dmvSwingSectionFt() != 20
            || dmvSwingDmgDie() != 6
            || dmvSwingDropFractions() != 1
        )
            ++bad;
        // the belay: the 3-foot edge rule, the -10 per additional faller, the
        // second check, the both-ends crossing
    if (dmvBelayEdgeFt() != 3
            || dmvBelayPerFallerPct() != 10
            || dmvBelaySecondCheck() != 1
            || dmvBelayBothEndsNoChecks() != 1
        )
            ++bad;
        // the roping: 20-30 feet of slack, the -10 two-faller cascade
        // re-check, the both-sides and end-character check rules
    if (dmvRopeSlackLoFt() != 20
            || dmvRopeSlackHiFt() != 30
            || dmvCascadePct() != 10
            || dmvRopedBothSidesCheck() != 1
            || dmvRopedEndSingleCheck() != 1
        )
            ++bad;
        // the dive column never dashes and only climbs: normal, normal,
        // doubled, tripled, tripled
    if (dmvT1DiveNum(2) != 2
            || dmvT1DiveNum(4) != 3
            || dmvT1DiveNum(0) > dmvT1DiveNum(1)
            || dmvT1DiveNum(3) < dmvT1DiveNum(2)
            || dmvT1DiveNum(4) < dmvT1DiveNum(2)
        )
            ++bad;
        // the encumbered row dashes the surface functions, heavy halves and
        // very heavy quarters, and the dive stays a whole-number triple
    if (dmvT1EndNum(4) != 0
            || dmvT1SpdNum(4) != 0
            || dmvT1SurfNum(4) != 0
            || dmvT1EndDen(2) != 2
            || dmvT1EndDen(3) != 4
            || dmvT1DiveDen(4) != 1
        )
            ++bad;
        // the Table 2 ladder halves step by step: 6/3/0, 12/6/3, 18/9/6,
        // 24/12/9
    if (dmvT2SlightFt(0) * 2 != dmvT2NonslipFt(0)
            || dmvT2SlipFt(1) * 2 != dmvT2SlightFt(1)
            || dmvT2NonslipFt(2) != 18
            || dmvT2NonslipFt(3) != 24
        )
            ++bad;
        // the Table 2 second half: pole 36, tree 60, sloping wall 60, rope
        // and wall 40 - and the ice wall climbable only slippery, at 6
    if (dmvT2NonslipFt(5) != 36
            || dmvT2NonslipFt(6) != 60
            || dmvT2NonslipFt(7) != 60
            || dmvT2NonslipFt(8) != 40
            || dmvT2SlipFt(4) != 6
        )
            ++bad;
        // every catch column tops at 00 (100)
    if (dmvT3Catch(0) != 100
            || dmvT3Catch(1) != 100
            || dmvT5Catch(0) != 100
            || dmvT5Catch(1) != 100
            || dmvT5Catch(2) != 100
        )
            ++bad;
        // the miss range sits strictly under the catch-and-slip range in
        // every grapple row
    if (dmvT3Miss(0) >= dmvT3Slip(0)
            || dmvT3Miss(1) >= dmvT3Slip(1)
            || dmvT5Miss(2) >= dmvT5Slip(2)
        )
            ++bad;
        // running strictly exceeds standing in the sample bands, and the
        // standing die steps up to 1d6 at the 10-12 band
    if (dmvT4RunAdd(0) <= dmvT4StandAdd(0)
            || dmvT4RunAdd(3) <= dmvT4StandAdd(3)
            || dmvT4RunAdd(6) <= dmvT4StandAdd(6)
            || dmvT4StandDie(2) != 6
        )
            ++bad;
        // the running ladder caps 9/12/15 in the three biggest bands,
        // standing top 6
    if (dmvT4RunAdd(4) != 9
            || dmvT4RunAdd(5) != 12
            || dmvT4RunAdd(6) != 15
            || dmvT4StandAdd(6) != 6
        )
            ++bad;
        printf("R504 DSG movement I audit: bad %d\n", bad);
        if (bad) return 1;
    }
