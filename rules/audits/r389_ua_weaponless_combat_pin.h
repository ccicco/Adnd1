    // ---- R389: the UA
    // weaponless combat appendix
    // Q pin audit ----
    // The pp. 106-108 stretch:
    // six items pin - one fully
    // clean (the throwing rules)
    // plus five mechanics-clean
    // with flagged holes (the
    // System I height example
    // cell, the pummeling table
    // row bodies, the kicking
    // tail, the grappling size
    // bands, the overbearing AC
    // prose); the R160 seam the
    // DMG default, the R388 seam
    // the misc weapons ledger.
    {
        using namespace rules;
        int bad = 0;
            if (!uaqSysOneSimpleQuickSystem()) ++bad;
            if (!uaqSysTwoOutgrowthMorePowerful()) ++bad;
            if (uaqSysOneUserTypeCount() != 3) ++bad;
            if (uaqSysOneActionCount() != 3) ++bad;
            if (uaqSysOneHeightPctLimit() != 125) ++bad;
            if (uaqSysOneExampleShortFt() != 4) ++bad;
            if (uaqSysOneExampleTallFt() != 5) ++bad;
            if (uaqSysOneSixFtExampleGarbles()) ++bad;
            if (!uaqSysOneToHitStrengthOnlyMod()) ++bad;
            if (!uaqSysOneDefenderArmorDexMagic()) ++bad;
            if (uaqSysOnePummelDelaySegments() != 1) ++bad;
            if (uaqSysOnePummelDamageLo() != 1) ++bad;
            if (uaqSysOnePummelDamageHi() != 2) ++bad;
            if (!uaqSysOnePummelStrBonusNeedsWeapon()) ++bad;
            if (!uaqSysOnePummelMultiNoExtraDelay()) ++bad;
            if (!uaqSysOneGrappleNoDamage()) ++bad;
            if (uaqSysOneGrappleHoldRounds() != 1) ++bad;
            if (uaqSysOneGrappledToHitPenalty() != 2) ++bad;
            if (uaqSysOneGrappledHitByBonus() != 2) ++bad;
            if (!uaqSysOneGrappleAutoBreaksNextRound()) ++bad;
            if (!uaqSysOneOverbearKnocksProne()) ++bad;
            if (uaqSysOneProneHitByBonus() != 4) ++bad;
            if (uaqSysOneInitPenalty() != 2) ++bad;
            if (!uaqSysOneSpoiledByPriorDamage()) ++bad;
            if (!uaqPumAvailWithStrengthScore()) ++bad;
            if (uaqPumMayRosterCount() != 4) ++bad;
            if (uaqPumMayNotRosterCount() != 3) ++bad;
            if (!uaqPumTargetNonUndeadNonVegetable()) ++bad;
            if (!uaqPumTargetPrimeNative()) ++bad;
            if (uaqPumCannotRosterCount() != 5) ++bad;
            if (uaqPumDemonExceptionGarbles()) ++bad;
            if (!uaqPumSameOrSmallerSizeClass()) ++bad;
            if (!uaqPumAnySizeIfTargetProne()) ++bad;
            if (uaqPumInitPenalty() != 4) ++bad;
            if (!uaqPumDexModsStillApply()) ++bad;
            if (!uaqPumSurpriseNoInitPenalty()) ++bad;
            if (!uaqPumBehindNoInitPenalty()) ++bad;
            if (uaqPumSurpriseOrBehindToHitBonus() != 2) ++bad;
            if (!uaqPumSpoiledByPriorDamage()) ++bad;
            if (uaqPumResolutionSteps() != 4) ++bad;
            if (uaqPumObjTypeCount() != 4) ++bad;
            if (uaqPumObjSmallSoft() != 0) ++bad;
            if (uaqPumObjSmallHard() != 1) ++bad;
            if (uaqPumObjLargeSoft() != 2) ++bad;
            if (uaqPumObjLargeHard() != 3) ++bad;
            if (!uaqPumLargeObjPickupRound()) ++bad;
            if (!uaqPumMoreVulnerableCategoryWins()) ++bad;
            if (!uaqPumExposedBareHeadOrFace()) ++bad;
            if (!uaqPumExposedOrdinaryCapClothing()) ++bad;
            if (!uaqPumExposedLeatherOrPadded()) ++bad;
            if (uaqPumExposedNaturalAcWorst() != 7) ++bad;
            if (!uaqPumSemiRingToPlateMail()) ++bad;
            if (uaqPumSemiNaturalLo() != 7) ++bad;
            if (uaqPumSemiNaturalHi() != 2) ++bad;
            if (!uaqPumUnexposedFullOrFieldPlate()) ++bad;
            if (uaqPumUnexposedNaturalAcBest() != 2) ++bad;
            if (!uaqPumVulnIgnoresShieldsAndMagicArmor()) ++bad;
            if (!uaqPumEffAcShieldIgnoredUnlessBuckler()) ++bad;
            if (!uaqPumEffAcMagicAndDexCount()) ++bad;
            if (!uaqPumAcaReadsFistOrOpenHand()) ++bad;
            if (uaqPumTableRows() != 3) ++bad;
            if (uaqPumTableCols() != 3) ++bad;
            if (uaqPumExposedSmallSoftPerPt() != 2) ++bad;
            if (uaqPumExposedSmallSoftCap() != 40) ++bad;
            if (uaqPumExposedSmallHardPerPt() != 4) ++bad;
            if (uaqPumExposedSmallHardCap() != 75) ++bad;
            if (uaqPumExposedLargeHardPerPt() != 5) ++bad;
            if (uaqPumExposedLargeHardCap() != 95) ++bad;
            if (uaqPumFragPair1PerPt() != 1) ++bad;
            if (uaqPumFragPair1Cap() != 20) ++bad;
            if (uaqPumFragPair2PerPt() != 2) ++bad;
            if (uaqPumFragPair2Cap() != 40) ++bad;
            if (uaqPumFragPair3PerPt() != 4) ++bad;
            if (uaqPumFragPair3Cap() != 75) ++bad;
            if (uaqPumTableRowBodiesGarble()) ++bad;
            if (!uaqPumStr1801PlusCountsAs1801()) ++bad;
            if (uaqPumExStrength() != 15) ++bad;
            if (!uaqPumExPaddedArmorExposed()) ++bad;
            if (uaqPumExSmallSoftPct() != 30) ++bad;
            if (uaqPumExSmallHardPct() != 60) ++bad;
            if (uaqPumExLargeHardPct() != 75) ++bad;
            if (uaqPumStunSegmentsLo() != 1) ++bad;
            if (uaqPumStunSegmentsHi() != 10) ++bad;
            if (!uaqPumStunNoActions()) ++bad;
            if (!uaqPumStunSpellsLost()) ++bad;
            if (!uaqPumStunConcentrationBroken()) ++bad;
            if (uaqPumRestunUnconsciousLo() != 1) ++bad;
            if (uaqPumRestunUnconsciousHi() != 4) ++bad;
            if (!uaqPumStunnedLosesDexAndShield()) ++bad;
            if (uaqPumStunnedHitByBonus() != 4) ++bad;
            if (uaqPumSmallSoftDamageLo() != 1) ++bad;
            if (uaqPumSmallSoftDamageHi() != 2) ++bad;
            if (uaqPumSmallHardDamageLo() != 1) ++bad;
            if (uaqPumSmallHardDamageHi() != 3) ++bad;
            if (!uaqPumDamageWhetherOrNotStun()) ++bad;
            if (uaqPumLargeDamageCellsGarble()) ++bad;
            if (!uaqPumMonksNoInitPenalty()) ++bad;
            if (!uaqPumMonksPummelOrOpenHand()) ++bad;
            if (uaqPumThievesBehindToHitBonus() != 4) ++bad;
            if (uaqPumThiefTumblingNoteGarbles()) ++bad;
            if (uaqPumCavaliersBareHandToHitPenalty() != 2) ++bad;
            if (!uaqKickBareFeetSmallSoft()) ++bad;
            if (!uaqKickMetalShodSmallHard()) ++bad;
            if (!uaqKickSameSizeWaistDownArmorOnly()) ++bad;
            if (uaqKickSmallerTailGarbles()) ++bad;
            if (uaqKickJumperClassCount() != 3) ++bad;
            if (!uaqKickJumperAnyPortionSameSize()) ++bad;
            if (!uaqKickHigherElevationAnyPortion()) ++bad;
            if (uaqThrowSmallRangeFeet() != 30) ++bad;
            if (uaqThrowLargeRangeFeet() != 10) ++bad;
            if (uaqThrowToHitLongRangeMod() != -5) ++bad;
            if (!uaqThrowStrengthModApplies()) ++bad;
            if (!uaqThrowMissScattersGrenadeLike()) ++bad;
            if (!uaqGrapAvailIntelligentRestraint()) ++bad;
            if (!uaqGrapNoNonCorporeal()) ++bad;
            if (!uaqGrapNoAstralEthereal()) ++bad;
            if (!uaqGrapNoUnintelligentSlimes()) ++bad;
            if (!uaqGrapBeholderExample()) ++bad;
            if (!uaqGrapBoundOrcExample()) ++bad;
            if (!uaqGrapPurposeDelaysOrRestrains()) ++bad;
            if (uaqGrapPurposeSentenceGarbles()) ++bad;
            if (!uaqGrapLargerUnlessProne()) ++bad;
            if (uaqGrapLargerWordGarbles()) ++bad;
            if (uaqGrapInitPenalty() != 1) ++bad;
            if (!uaqGrapSpoiledByPriorDamage()) ++bad;
            if (uaqGrapResolutionSteps() != 2) ++bad;
            if (!uaqGrapEffAcIgnoresShieldMagicArmor()) ++bad;
            if (!uaqGrapRingsProtectionBracersCount()) ++bad;
            if (!uaqGrapMagicalPlateCounts()) ++bad;
            if (!uaqGrapNoDamage()) ++bad;
            if (!uaqGrapPreventsFurtherAction()) ++bad;
            if (uaqGrapVictimToHitPenalty() != 2) ++bad;
            if (uaqGrapVictimHitByBonus() != 2) ++bad;
            if (!uaqGrapDexNegatedWhileHeld()) ++bad;
            if (uaqGrapBreakWayCount() != 5) ++bad;
            if (!uaqGrapBreakByRelease()) ++bad;
            if (!uaqGrapBreakByInflictingDamage()) ++bad;
            if (uaqGrapCounterAttacksAtPenalty() != 2) ++bad;
            if (!uaqGrapCounterAttackerKeepsMagicDex()) ++bad;
            if (!uaqGrapCounterStrToHitAsAcBonus()) ++bad;
            if (uaqGrapStr17ExampleTailGarbles()) ++bad;
            if (!uaqGrapBreakByCounterGrapple()) ++bad;
            if (!uaqGrapBreakByBendBars()) ++bad;
            if (!uaqGrapBreakByAcrobatEvasion()) ++bad;
            if (!uaqGrapHeldAsLargeSoftObject()) ++bad;
            if (!uaqGrapNeutralizesOneOfMany()) ++bad;
            if (!uaqGrapScorpionExample()) ++bad;
            if (!uaqGrapSameWeaponAllNeutralized()) ++bad;
            if (!uaqGrapGroupSingleRoll()) ++bad;
            if (uaqGrapPerExtraMemberBonus() != 2) ++bad;
            if (uaqGrapDefSMaxSizeS() != 3) ++bad;
            if (uaqGrapDefSBySizeMHi() != 2) ++bad;
            if (uaqGrapDefSBySizeL() != 1) ++bad;
            if (uaqGrapDefMMaxSizeM() != 3) ++bad;
            if (uaqGrapDefMBandsGarble()) ++bad;
            if (uaqGrapDefLMaxSizeL() != 3) ++bad;
            if (uaqGrapProneMaxSizeS() != 8) ++bad;
            if (uaqGrapProneMaxSizeM() != 6) ++bad;
            if (uaqGrapProneMaxSizeL() != 4) ++bad;
            if (!uaqOvbAnyVsAny()) ++bad;
            if (!uaqOvbNeedsDiscernibleUpright()) ++bad;
            if (!uaqOvbPurpleWormCubeException()) ++bad;
            if (!uaqOvbNoInitModification()) ++bad;
            if (!uaqOvbSpoiledByPriorDamage()) ++bad;
            if (uaqOvbResolutionSteps() != 2) ++bad;
            if (!uaqOvbNoInherentDamage()) ++bad;
            if (!uaqOvbSituationMayDamage()) ++bad;
            if (uaqOvbProneHitByBonus() != 4) ++bad;
            if (uaqOvbProneStrikePenalty() != 2) ++bad;
            if (!uaqOvbProneGrapplePummelAnySize()) ++bad;
            if (uaqOvbAcProseGarbles()) ++bad;
            if (uaqOvbAcRows() != 3) ++bad;
            if (uaqOvbAcCols() != 3) ++bad;
            if (uaqOvbAcDefSVsS() != 0) ++bad;
            if (uaqOvbAcDefSVsM() != 2) ++bad;
            if (uaqOvbAcDefSVsL() != 4) ++bad;
            if (uaqOvbAcDefMVsS() != -4) ++bad;
            if (uaqOvbAcDefMVsM() != 0) ++bad;
            if (uaqOvbAcDefMVsL() != 2) ++bad;
            if (uaqOvbAcDefLVsS() != -8) ++bad;
            if (uaqOvbAcDefLVsM() != -4) ++bad;
            if (uaqOvbAcDefLVsL() != 0) ++bad;
            if (uaqOvbFootFourLegsAcAdj() != -6) ++bad;
            if (uaqOvbFootSixLegsAcAdj() != -8) ++bad;
            if (uaqOvbFootMoreLegsAcAdj() != -10) ++bad;
            if (!uaqOvbNoLegsCannotBeOverborne()) ++bad;
            if (!uaqOvbLargeMultiLegRiseAuto()) ++bad;
            if (!uaqOvbGroupSingleRoll()) ++bad;
            if (uaqOvbPerExtraFigureBonus() != 1) ++bad;
            if (!uaqOvbWeakestToHitUsed()) ++bad;
            if (uaqOvbWeakestSentenceGarbles()) ++bad;
            if (uaqOvbTargetSMaxSizeS() != 6) ++bad;
            if (uaqOvbTargetSBySizeM() != 4) ++bad;
            if (uaqOvbTargetSBySizeL() != 2) ++bad;
            if (uaqOvbTargetMMaxSizeS() != 8) ++bad;
            if (uaqOvbTargetMBySizeM() != 6) ++bad;
            if (uaqOvbTargetMBySizeL() != 4) ++bad;
            if (uaqOvbTargetLMaxSizeS() != 12) ++bad;
            if (uaqOvbTargetLBySizeM() != 8) ++bad;
            if (uaqOvbTargetLBySizeL() != 6) ++bad;
            if (!uaqR160DmgSystemStaysDefault()) ++bad;
            if (!uaqR160DivergentSystemsRunBoth()) ++bad;
            if (!uaqR160OverlapReconciled()) ++bad;
            if (uaqPartItemTotal() != 6) ++bad;
            if (uaqPartCleanCount() != 6) ++bad;
            if (uaqPartFlaggedCount() != 0) ++bad;
            if (uaqPartGarbledCount() != 0) ++bad;
        // ---- the cross-checks ----
        // the height example:
        // 4 feet at 125 percent
        // reads 5 feet
            if (uaqSysOneExampleShortFt()
                * uaqSysOneHeightPctLimit()
                / 100 != uaqSysOneExampleTallFt())
                ++bad;
        // the Str-15 example
        // multiplies the decoded
        // per-point cells exactly
            if (uaqPumExStrength()
                * uaqPumExposedSmallSoftPerPt()
                != uaqPumExSmallSoftPct())
                ++bad;
            if (uaqPumExStrength()
                * uaqPumExposedSmallHardPerPt()
                != uaqPumExSmallHardPct())
                ++bad;
            if (uaqPumExStrength()
                * uaqPumExposedLargeHardPerPt()
                != uaqPumExLargeHardPct())
                ++bad;
        // the caps climb
        // 40 < 75 < 95
            if (uaqPumExposedSmallSoftCap()
                >= uaqPumExposedSmallHardCap()
                || uaqPumExposedSmallHardCap()
                >= uaqPumExposedLargeHardCap())
                ++bad;
        // the fragment pairs
        // tile the 18/01 caps:
        // 20 = 1 x 20, 40 = 2 x 20
            if (uaqPumFragPair1PerPt() * 20
                != uaqPumFragPair1Cap()
                || uaqPumFragPair2PerPt() * 20
                != uaqPumFragPair2Cap())
                ++bad;
        // the four object ids
        // are 0-3 contiguous
            if (uaqPumObjSmallSoft() + 1
                != uaqPumObjSmallHard()
                || uaqPumObjSmallHard() + 1
                != uaqPumObjLargeSoft()
                || uaqPumObjLargeSoft() + 1
                != uaqPumObjLargeHard())
                ++bad;
        // the ledger sums
            if (uaqPartCleanCount()
                + uaqPartFlaggedCount()
                + uaqPartGarbledCount()
                != uaqPartItemTotal())
                ++bad;
        // the overbear size-AC
        // diagonal is zero and
        // the rows shift by 4,
        // 2 and 2
            if (uaqOvbAcDefSVsS() != 0
                || uaqOvbAcDefMVsM() != 0
                || uaqOvbAcDefLVsL() != 0
                || uaqOvbAcDefSVsM()
                - uaqOvbAcDefSVsS() != 2
                || uaqOvbAcDefMVsM()
                - uaqOvbAcDefMVsS() != 4
                || uaqOvbAcDefLVsM()
                - uaqOvbAcDefLVsS() != 4)
                ++bad;
        // the footing ladder
        // descends -6 -8 -10
            if (uaqOvbFootFourLegsAcAdj()
                <= uaqOvbFootSixLegsAcAdj()
                || uaqOvbFootSixLegsAcAdj()
                <= uaqOvbFootMoreLegsAcAdj())
                ++bad;
        // the overbear count
        // bands descend within
        // each row and climb
        // by row
            if (uaqOvbTargetSMaxSizeS()
                <= uaqOvbTargetSBySizeM()
                || uaqOvbTargetSBySizeM()
                <= uaqOvbTargetSBySizeL()
                || uaqOvbTargetMMaxSizeS()
                <= uaqOvbTargetMBySizeM()
                || uaqOvbTargetMBySizeM()
                <= uaqOvbTargetMBySizeL()
                || uaqOvbTargetLMaxSizeS()
                <= uaqOvbTargetLBySizeM()
                || uaqOvbTargetLBySizeM()
                <= uaqOvbTargetLBySizeL()
                || uaqOvbTargetMMaxSizeS()
                - uaqOvbTargetSMaxSizeS() != 2
                || uaqOvbTargetLMaxSizeS()
                - uaqOvbTargetMMaxSizeS() != 4)
                ++bad;
        // the grapple prone
        // bands descend 8 6 4
            if (uaqGrapProneMaxSizeS()
                - uaqGrapProneMaxSizeM() != 2
                || uaqGrapProneMaxSizeM()
                - uaqGrapProneMaxSizeL() != 2)
                ++bad;
        // the stun bands
            if (uaqPumStunSegmentsLo() != 1
                || uaqPumStunSegmentsHi() != 10
                || uaqPumRestunUnconsciousLo() != 1
                || uaqPumRestunUnconsciousHi()
                != 4) ++bad;
        // ---- the R160 seam ----
        // the DMG pp. 72-73 system
        // stays the engine default:
        // its pummel base ladder
        // reads AC x 10
            if (pummelBaseChance(10) != 100
                || pummelBaseChance(9) != 90
                || pummelBaseChance(0) != 0)
                ++bad;
        printf("R389 UA weaponless combat pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
