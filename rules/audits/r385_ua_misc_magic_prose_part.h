    // ---- R385: the UA misc magic
    // prose part 5 pin audit ----
    // The R398 clean read fills
    // every flagged hole this
    // block names.
    // The Q-S stretch: eleven pins -
    // seven fully clean (the robe
    // of stars, the scarab versus
    // golems, the shadow lanthorn,
    // the shoes of Fharlanghn, the
    // slippers of kicking, the
    // slippers of spider climbing,
    // the sovereign glue) plus four
    // mechanics-clean with flagged
    // holes (the quiver of
    // Ehlonna's command sentence,
    // the robe of vermin's removal
    // tail, the sheet of smallness'
    // intro seam, the spoon of
    // stirring's table cell); the
    // R384 seam the part-4 ledger,
    // the R375 seam the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the quiver of Ehlonna
        // ----
            if (!uamm5QehAppearsTypicalArrowCase())
                ++bad;
            if (uamm5QehAppearsToHoldShafts() != 20)
                ++bad;
            if (!uamm5QehAlterationAura()) ++bad;
            if (!uamm5QehThreeDistinctPortions())
                ++bad;
            if (uamm5QehArrowPortionCapacity()
                    != 60) ++bad;
            if (uamm5QehJavelinPortionCapacity()
                    != 18) ++bad;
            if (uamm5QehSpearPortionCapacity() != 6)
                ++bad;
            if (!uamm5QehProducesOnCommand()) ++bad;
            if (!uamm5QehOnePerRound()) ++bad;
            if (uamm5QehCommandSentenceGarbles())
                ++bad;
            // the javelin portion holds
            // three times the spear
            // portion, the arrow ten
            if (3 * uamm5QehSpearPortionCapacity()
                    != uamm5QehJavelinPortionCapacity())
                ++bad;
            if (10 * uamm5QehSpearPortionCapacity()
                    != uamm5QehArrowPortionCapacity())
                ++bad;
        // ---- the robe of stars ----
            if (!uamm5RstOrdinaryAppearance()) ++bad;
            if (!uamm5RstStrongAlterationEvocationAura())
                ++bad;
            if (!uamm5RstAstralTravelPhysical())
                ++bad;
            if (!uamm5RstCarriesGearAlong()) ++bad;
            if (!uamm5RstVoidSurvivalComfort()) ++bad;
            if (uamm5RstSaveBonus() != 1) ++bad;
            if (uamm5RstStarMissiles() != 6) ++bad;
            if (!uamm5RstNeedsDartProficiency())
                ++bad;
            if (uamm5RstStarBonus() != 5) ++bad;
            if (uamm5RstStarRangeIn() != 6) ++bad;
            if (uamm5RstStarDamageLo() != 2) ++bad;
            if (uamm5RstStarDamageHi() != 8) ++bad;
            if (!uamm5RstStarsOnChest()) ++bad;
            if (uamm5RstStarsRegrowPerDay() != 1)
                ++bad;
            if (!uamm5RstAllUsedLosesPowerForever())
                ++bad;
            // the star damage rides
            // the 2-8 spread, four
            // lows to a high
            if (4 * uamm5RstStarDamageLo()
                    != uamm5RstStarDamageHi()) ++bad;
            // the star count matches
            // the maximum range, six
            if (uamm5RstStarMissiles()
                    != uamm5RstStarRangeIn()) ++bad;
        // ---- the robe of vermin
        // ----
            if (!uamm5RveDimEnchantmentAura())
                ++bad;
            if (!uamm5RveSeemsBeneficialAtFirst())
                ++bad;
            if (uamm5RveInitialProtectionBonus()
                    != 1) ++bad;
            if (!uamm5RveVerminBiteInCombat()) ++bad;
            if (!uamm5RveCannotGainInitiative())
                ++bad;
            if (uamm5RveSpellFailurePct() != 50)
                ++bad;
            if (!uamm5RveManualActionsHalfProb())
                ++bad;
            if (uamm5RveRemovalTailGarbles()) ++bad;
            if (!uamm5RveRemovalNeedsRemoveCurse())
                ++bad;
            // the spell-failure
            // chance is half of a
            // certainty
            if (2 * uamm5RveSpellFailurePct()
                    != 100) ++bad;
        // ---- the scarab versus
        // golems ----
            if (!uamm5SvgPinDetectsGolems()) ++bad;
            if (uamm5SvgDetectRangeFt() != 60) ++bad;
            if (!uamm5SvgNeedsConcentration()) ++bad;
            if (!uamm5SvgCombatsAsNormalMonster())
                ++bad;
            if (!uamm5SvgLesserGolemsOnly()) ++bad;
            if (uamm5SvgClericalSpellLevel() != 5)
                ++bad;
            if (uamm5SvgTableRows() != 6) ++bad;
            if (uamm5SvgFleshXp() != 400) ++bad;
            if (uamm5SvgFleshGp() != 3200) ++bad;
            if (uamm5SvgAnyGolemRowLo() != 96) ++bad;
            if (uamm5SvgAnyGolemRowHi() != 100)
                ++bad;
            if (uamm5SvgAnyGolemXp() != 1250) ++bad;
            if (uamm5SvgAnyGolemGp() != 12500) ++bad;
            // the any-golem row spans
            // the last five points of
            // the table, 96 through 00
            if (uamm5SvgAnyGolemRowHi()
                    - uamm5SvgAnyGolemRowLo() != 4)
                ++bad;
            // the any-golem sale value
            // is ten times its XP
            if (10 * uamm5SvgAnyGolemXp()
                    != uamm5SvgAnyGolemGp()) ++bad;
        // ---- the shadow
        // lanthorn ----
            if (!uamm5SlaMundaneAppearance()) ++bad;
            if (!uamm5SlaFaintEvilDweomer()) ++bad;
            if (!uamm5SlaNeedsCorpseFatOil()) ++bad;
            if (uamm5SlaShadowsLo() != 5) ++bad;
            if (uamm5SlaShadowsHi() != 8) ++bad;
            if (!uamm5SlaShadowsServePossessor())
                ++bad;
            if (!uamm5SlaShadowsVanishWhenConsumed())
                ++bad;
            if (uamm5SlaBurningHours() != 1) ++bad;
            if (!uamm5SlaGoodLosesXpIfKept()) ++bad;
            // the shadow band rides
            // the 5-8 spread
            if (uamm5SlaShadowsLo()
                    >= uamm5SlaShadowsHi()) ++bad;
        // ---- the sheet of
        // smallness ----
            if (!uamm5SsmFineClothAppearance())
                ++bad;
            if (!uamm5SsmOneSideWhite()) ++bad;
            if (!uamm5SsmOtherSideBlack()) ++bad;
            if (uamm5SsmIntroSeamGarbles()) ++bad;
            if (!uamm5SsmAlterationAura()) ++bad;
            if (!uamm5SsmShrinksToTwelfth()) ++bad;
            if (!uamm5SsmNoArtifactsOrRelics())
                ++bad;
            if (!uamm5SsmReverseSideRestores())
                ++bad;
            if (!uamm5SsmNoLivingMaterial()) ++bad;
            if (!uamm5SsmNonFunctionalWhenSmall())
                ++bad;
            if (uamm5SsmChangeRounds() != 2) ++bad;
            // the two-round change
            // shrinks to a twelfth:
            // 2 rounds x 6 = 12
            if (6 * uamm5SsmChangeRounds() != 12)
                ++bad;
        // ---- the shoes of
        // Fharlanghn ----
            if (!uamm5SfaNeverWearOut()) ++bad;
            if (!uamm5SfaNeverFatigued()) ++bad;
            if (uamm5SfaMilesPerDayLo() != 20) ++bad;
            if (uamm5SfaMilesPerDayHi() != 30) ++bad;
            if (!uamm5SfaNeverTripsOrSnared())
                ++bad;
            if (uamm5SfaHillClimbAngleDeg() != 45)
                ++bad;
            if (!uamm5SfaSureFootedOnLedges()) ++bad;
            if (!uamm5SfaWorshipperNeverLost())
                ++bad;
            if (!uamm5SfaWorshipperNoSurprise())
                ++bad;
            if (uamm5SfaWorshipperRunIn() != 18)
                ++bad;
            if (uamm5SfaWorshipperJumpFt() != 20)
                ++bad;
            if (uamm5SfaWorshipperThiefClimbLevel()
                    != 10) ++bad;
            if (!uamm5SfaWorshipperEarthAsRoad())
                ++bad;
            if (uamm5SfaKnownPairs() != 12) ++bad;
            // the daily pace rides
            // the 20-30 mile band
            if (uamm5SfaMilesPerDayLo()
                    >= uamm5SfaMilesPerDayHi()) ++bad;
        // ---- the slippers of
        // kicking ----
            if (!uamm5SkiFeetAsWeapons()) ++bad;
            if (uamm5SkiAttacksPerRound() != 2)
                ++bad;
            if (!uamm5SkiSpecialNeedsForegoing())
                ++bad;
            if (!uamm5SkiAttackLevelUnchanged())
                ++bad;
            if (uamm5SkiDamageManSizedLo() != 1)
                ++bad;
            if (uamm5SkiDamageManSizedHi() != 6)
                ++bad;
            if (uamm5SkiDamageLargerLo() != 1) ++bad;
            if (uamm5SkiDamageLargerHi() != 4) ++bad;
            if (!uamm5SkiDoubleDamageSeparate())
                ++bad;
            if (!uamm5SkiExtraRecoveredAfterTurn())
                ++bad;
            if (uamm5SkiExamplePlusOne() != 3) ++bad;
            if (uamm5SkiExamplePlusTwo() != 4) ++bad;
            if (uamm5SkiExampleRecovered() != 7)
                ++bad;
            if (uamm5SkiMartialArtsBonus() != 1)
                ++bad;
            if (!uamm5SkiMartialArtsNoDouble())
                ++bad;
            // the printed example
            // recovers the two pluses,
            // 3 + 4 = 7
            if (uamm5SkiExamplePlusOne()
                    + uamm5SkiExamplePlusTwo()
                    != uamm5SkiExampleRecovered())
                ++bad;
        // ---- the slippers of
        // spider climbing ----
            if (!uamm5SscUnremarkableAppearance())
                ++bad;
            if (!uamm5SscFaintAlterationDweomer())
                ++bad;
            if (uamm5SscClimbRateIn() != 6) ++bad;
            if (!uamm5SscCeilingsToo()) ++bad;
            if (!uamm5SscHandsFree()) ++bad;
            if (!uamm5SscUselessOnSlippery())
                ++bad;
        // ---- the sovereign
        // glue ----
            if (!uamm5SglPaleAmberViscous()) ++bad;
            if (!uamm5SglNeedsSlipperinessFlask())
                ++bad;
            if (uamm5SglReoilWithinRounds() != 1)
                ++bad;
            if (!uamm5SglElseAdheresToFlask())
                ++bad;
            if (uamm5SglSqFtPerOunce() != 1) ++bad;
            if (!uamm5SglPermanentBond()) ++bad;
            if (uamm5SglSetRounds() != 1) ++bad;
            if (!uamm5SglEarlyPullRuinsApplication())
                ++bad;
            if (!uamm5SglSetBondRends()) ++bad;
            if (!uamm5SglDissolvedByEtherealnessOrUltimate())
                ++bad;
            if (uamm5SglOuncesLo() != 1) ++bad;
            if (uamm5SglOuncesHi() != 10) ++bad;
            // the typical container
            // rides the 1-10 ounce
            // band
            if (uamm5SglOuncesLo()
                    >= uamm5SglOuncesHi()) ++bad;
        // ---- the spoon of
        // stirring ----
            if (!uamm5SstUnremarkableSpoon()) ++bad;
            if (!uamm5SstRadiatesOnlyInPotion())
                ++bad;
            if (!uamm5SstAlterationBurst()) ++bad;
            if (!uamm5SstChangesPotion()) ++bad;
            if (!uamm5SstReusable()) ++bad;
            if (uamm5SstMaxUsesPerPotion() != 3)
                ++bad;
            if (!uamm5SstFourthUseRuins()) ++bad;
            if (uamm5SstTableCellGarbles()) ++bad;
            if (!uamm5SstDeterminedByTable()) ++bad;
            if (!uamm5SstSameResultChangesAppearance())
                ++bad;
            if (uamm5SstTwiceStrengthLo() != 1)
                ++bad;
            if (uamm5SstTwiceStrengthHi() != 50)
                ++bad;
            if (uamm5SstHalfStrengthLo() != 51) ++bad;
            if (uamm5SstHalfStrengthHi() != 100)
                ++bad;
            // the fourth usage ruins:
            // three good uses plus
            // the one too many
            if (uamm5SstMaxUsesPerPotion() + 1
                    != 4) ++bad;
            // the twice and half
            // bands split the table,
            // 50 and 50
            if (uamm5SstTwiceStrengthHi()
                    + uamm5SstHalfStrengthHi()
                    - uamm5SstHalfStrengthLo()
                    + 1 != 100) ++bad;
        // ---- the part ledger ----
            if (uamm5PartItemTotal() != 11) ++bad;
            if (uamm5PartCleanCount() != 11) ++bad;
            if (uamm5PartFlaggedCount() != 0)
                ++bad;
            if (uamm5PartGarbledCount() != 0)
                ++bad;
            if (uamm5PartCleanCount()
                    + uamm5PartFlaggedCount()
                    + uamm5PartGarbledCount()
                    != uamm5PartItemTotal()) ++bad;
        // ---- the R384 part-4 seam ----
            if (uamm4PartItemTotal() != 9) ++bad;
            if (uamm4PartCleanCount() != 9) ++bad;
            if (uamm4PartFlaggedCount() != 0)
                ++bad;
            if (uamm4PartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (uadsRowBodiesGarble()) ++bad;
        printf("R385 UA misc magic prose part 5 pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
