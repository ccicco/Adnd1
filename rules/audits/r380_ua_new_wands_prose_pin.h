    // ---- R380: the UA new wands
    // prose pin audit ----
    // The seven pinnable wand
    // types (pp. 96-97): five
    // fully clean (anything,
    // fireballs, flame
    // extinguishing, ice
    // storms, lightning bolts)
    // plus two mechanics-clean
    // with flagged holes
    // (defoliation, metal
    // command), their holes
    // and the five garbled
    // types filled by the
    // R397 clean read. The
    // R379 seam
    // cross-checks the rods
    // ledger, the R375 seam the
    // wand band; the census
    // 306 -> 307.
    {
        using namespace rules;
        int bad = 0;
        // ---- the anything wand ----
            if (!uawdAnyIsWonderLike()) ++bad;
            if (uawdAnyMaxUsages() != 50) ++bad;
            if (!uawdAnyDuplicatesAnyKnownWand())
                ++bad;
            if (!uawdAnyEachKindOnce()) ++bad;
            if (!uawdAnyRepeatCommandInert())
                ++bad;
            if (uawdAnyDrainDemands() != 3) ++bad;
            if (!uawdAnyDrainCountsFailed()) ++bad;
            if (uawdAnyRechargeable()) ++bad;
        // ---- the wand of fireballs ----
            if (uawdFbCasterLevel() != 6) ++bad;
            if (uawdFbActivateSegs() != 1) ++bad;
            if (uawdFbDischargeSegs() != 1) ++bad;
            if (uawdFbDmgDice() != 6) ++bad;
            if (uawdFbDmgLo() != 6) ++bad;
            if (uawdFbDmgHi() != 36) ++bad;
            if (!uawdFbSaveForHalf()) ++bad;
            if (uawdFbRechargeMuLevel() != 8) ++bad;
        // ---- the wand of flame
        // extinguishing ----
            if (!uawdFxNormalFree()) ++bad;
            if (uawdFxNormalBilletsLo() != 4)
                ++bad;
            if (uawdFxNormalBilletsHi() != 6)
                ++bad;
            if (uawdFxLargeNormalCharges() != 1)
                ++bad;
            if (uawdFxOilGallonMin() != 1) ++bad;
            if (uawdFxSuppressionRounds() != 6)
                ++bad;
            if (uawdFxLargeMagicalCharges() != 2)
                ++bad;
            if (uawdFxCreatureCharges() != 1)
                ++bad;
            if (uawdFxCreatureDmgDice() != 6)
                ++bad;
            if (uawdFxCreatureDmgLo() != 6) ++bad;
            if (uawdFxCreatureDmgHi() != 36)
                ++bad;
            // the creature blast
            // mirrors the fireball
            // damage band
            if (uawdFxCreatureDmgLo()
                    != uawdFbDmgLo()
                    || uawdFxCreatureDmgHi()
                    != uawdFbDmgHi()) ++bad;
        // ---- the wand of ice storms ----
            if (uawdIceCasterLevel() != 7) ++bad;
            if (uawdIceFormsCount() != 2) ++bad;
            if (uawdIceActivateSegs() != 1) ++bad;
            if (uawdIceEmergeSegs() != 1) ++bad;
            if (uawdIceRechargeMuLevel() != 9)
                ++bad;
        // ---- the wand of lightning bolts ----
            if (uawdLbCasterLevel() != 6) ++bad;
            if (!uawdLbForkedOrSingle()) ++bad;
            if (uawdLbDmgDice() != 6) ++bad;
            if (uawdLbDmgLo() != 6) ++bad;
            if (uawdLbDmgHi() != 36) ++bad;
            if (!uawdLbSaveForHalf()) ++bad;
            if (uawdLbActivateSegs() != 1) ++bad;
            if (uawdLbDischargeSegs() != 1) ++bad;
            if (uawdLbRechargeMuLevel() != 8)
                ++bad;
            // the lightning bolt
            // mirrors the fireball:
            // same caster level,
            // same damage band, the
            // same recharge level
            if (uawdLbCasterLevel()
                    != uawdFbCasterLevel()) ++bad;
            if (uawdLbDmgLo() != uawdFbDmgLo()
                    || uawdLbDmgHi()
                    != uawdFbDmgHi()) ++bad;
            if (uawdLbRechargeMuLevel()
                    != uawdFbRechargeMuLevel())
                ++bad;
        // ---- the wand of defoliation ----
            if (uawdDefOpeningHoleFlagged())
                ++bad;
            if (uawdDefChlorophyllCharges() != 1)
                ++bad;
            if (uawdDefChlorophyllRadiusIn() != 3)
                ++bad;
            if (uawdDefWitherCharges() != 2) ++bad;
            if (uawdDefWitherRadiusIn() != 3)
                ++bad;
            if (uawdDefSentientDmgLo() != 1)
                ++bad;
            if (uawdDefSentientDmgHi() != 6) ++bad;
            if (uawdDefConeLengthIn() != 3) ++bad;
            if (uawdDefConeFarDiamIn() != 1) ++bad;
            if (uawdDefConeDmgDice() != 6) ++bad;
            if (uawdDefConeDmgLo() != 6) ++bad;
            if (uawdDefConeDmgHi() != 36) ++bad;
            if (!uawdDefConeSaveForHalf()) ++bad;
            if (uawdDefConeHalfDice() != 3) ++bad;
            // the cone's half-damage
            // is half the dice
            if (2 * uawdDefConeHalfDice()
                    != uawdDefConeDmgDice()) ++bad;
        // ---- the wand of metal command ----
            if (uawdMcVerbHoleFlagged()) ++bad;
            if (!uawdMcAppearsDetection()) ++bad;
            if (!uawdMcDwarfGnomeOnly()) ++bad;
            if (uawdMcTransmuteCharges() != 1)
                ++bad;
            if (uawdMcTransmuteRangeIn() != 3)
                ++bad;
            if (uawdMcTransmuteLbsLo() != 1) ++bad;
            if (uawdMcTransmuteLbsHi() != 6) ++bad;
            if (uawdMcTransmuteGpLo() != 10) ++bad;
            if (uawdMcTransmuteGpHi() != 60) ++bad;
            // ten gp per pound rides
            // the transmutation
            if (uawdMcTransmuteGpLo()
                    != 10 * uawdMcTransmuteLbsLo()
                    || uawdMcTransmuteGpHi()
                    != 10 * uawdMcTransmuteLbsHi())
                ++bad;
            if (uawdMcHeatCharges() != 2) ++bad;
            if (uawdMcHeatRangeIn() != 3) ++bad;
            if (uawdMcHeatAreaDiamFt() != 3) ++bad;
            if (uawdMcHeatMaxGp() != 600) ++bad;
            if (uawdMcSpellCharges() != 3) ++bad;
            if (uawdMcSpellCount() != 3) ++bad;
            if (uawdMcSpellCasterLevel() != 18)
                ++bad;
        // ---- the extract ledger ----
            if (uawdCleanCount() != 12) ++bad;
            if (uawdFlaggedCount() != 0) ++bad;
            if (uawdGarbledCount() != 0) ++bad;
            if (uawdTotalTypes() != 12) ++bad;
            if (uawdCleanCount() + uawdFlaggedCount()
                    + uawdGarbledCount()
                    != uawdTotalTypes()) ++bad;
        // ---- the R379 rods seam ----
            if (uaroCleanCount() != 11) ++bad;
            if (uaroGarbledCount() != 0) ++bad;
        // ---- the R375 skeleton seam ----
            // the wands ride the
            // rods staves wands band
            // as its II.D.2 second
            // table
            if (strcmp(uadsCategoryName(3),
                    "Rods, Staves & Wands") != 0)
                ++bad;
            if (!uadsIsTheRevisedTable()) ++bad;
            if (!uadsRodSecondTableIsIID2())
                ++bad;
            if (uadsRowBodiesGarble()) ++bad;
        printf("R380 UA new wands prose pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
