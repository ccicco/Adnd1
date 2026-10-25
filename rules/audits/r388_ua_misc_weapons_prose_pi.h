    // ---- R388: the UA misc
    // weapons prose pin audit ----
    // The R399 clean read fills
    // every flagged hole this
    // block names.
    // The pp. 105-106 stretch:
    // nine pins - six fully
    // clean (the bullet of
    // impact, the dagger
    // Longtooth, the darts of
    // homing, the knife buckle,
    // the magic quarterstaff,
    // the scimitar of speed)
    // plus three
    // mechanics-clean with
    // flagged holes (the axe
    // of hurling's
    // familiarization tail, the
    // dagger of throwing's
    // range cells, the
    // hornblade's handle
    // sentence); the R387 seam
    // the armor ledger, the
    // R375 seam the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the axe of hurling
        // ----
            if (!uamwAohNormalHandAxeAppearance())
                ++bad;
            if (uamwAohHurledRangeIn() != 6) ++bad;
            if (!uamwAohReturnsSameRound()) ++bad;
            if (!uamwAohReturnsHitOrMiss()) ++bad;
            if (!uamwAohThrownDamageDoubled())
                ++bad;
            if (uamwAohThrownSmLo() != 2) ++bad;
            if (uamwAohThrownSmHi() != 12) ++bad;
            if (uamwAohThrownLLo() != 2) ++bad;
            if (uamwAohThrownLHi() != 8) ++bad;
            if (!uamwAohBonusAddedAfter()) ++bad;
            if (uamwAohExampleBonus() != 3) ++bad;
            if (uamwAohExampleSmLo() != 5) ++bad;
            if (uamwAohExampleSmHi() != 15) ++bad;
            if (uamwAohExampleLLo() != 5) ++bad;
            if (uamwAohExampleLHi() != 11) ++bad;
            if (!uamwAohHandheldNormalDamage())
                ++bad;
            if (uamwAohFamChanceDie() != 8) ++bad;
            if (uamwAohFamWeeksFull() != 8) ++bad;
            if (uamwAohFamTailGarbles()) ++bad;
            if (!uamwAohBonusOnD20()) ++bad;
            if (uamwAohBand1Lo() != 1) ++bad;
            if (uamwAohBand1Hi() != 5) ++bad;
            if (uamwAohBand2Lo() != 6) ++bad;
            if (uamwAohBand2Hi() != 10) ++bad;
            if (uamwAohBand3Lo() != 11) ++bad;
            if (uamwAohBand3Hi() != 15) ++bad;
            if (uamwAohBand4Lo() != 16) ++bad;
            if (uamwAohBand4Hi() != 19) ++bad;
            if (uamwAohBand5Lo() != 20) ++bad;
            if (uamwAohBand5Hi() != 20) ++bad;
            if (uamwAohXpPerPlus() != 1500) ++bad;
            if (uamwAohGpPerPlus() != 15000) ++bad;
            // the d20 bands tile the
            // die exactly, 5+5+5+4+1
            if (uamwAohBand1Hi() - uamwAohBand1Lo()
                    + 1 + uamwAohBand2Hi()
                    - uamwAohBand2Lo() + 1
                    + uamwAohBand3Hi()
                    - uamwAohBand3Lo() + 1
                    + uamwAohBand4Hi()
                    - uamwAohBand4Lo() + 1
                    + uamwAohBand5Hi()
                    - uamwAohBand5Lo() + 1
                    != 20) ++bad;
            // the +3 example adds
            // the bonus over the
            // doubled dice, 2+3 to
            // 12+3 and 2+3 to 8+3
            if (uamwAohThrownSmLo()
                    + uamwAohExampleBonus()
                    != uamwAohExampleSmLo()) ++bad;
            if (uamwAohThrownSmHi()
                    + uamwAohExampleBonus()
                    != uamwAohExampleSmHi()) ++bad;
            if (uamwAohThrownLLo()
                    + uamwAohExampleBonus()
                    != uamwAohExampleLLo()) ++bad;
            if (uamwAohThrownLHi()
                    + uamwAohExampleBonus()
                    != uamwAohExampleLHi()) ++bad;
            // the sale value is
            // ten times the XP per
            // plus
            if (10 * uamwAohXpPerPlus()
                    != uamwAohGpPerPlus()) ++bad;
        // ---- the bullet of
        // impact ----
            if (!uamwBsiWellCastAppearance())
                ++bad;
            if (!uamwBsiMinuteEngravedRunes())
                ++bad;
            if (!uamwBsiEnchantmentAura()) ++bad;
            if (!uamwBsiIronSilverLeadAlloy())
                ++bad;
            if (uamwBsiToHitBonusOnly() != 1)
                ++bad;
            if (!uamwBsiDamageExcludesBonus())
                ++bad;
            if (!uamwBsiStacksWithSlingBonus())
                ++bad;
            if (uamwBsiExtraDmgPerDiffPoint()
                    != 2) ++bad;
            if (uamwBsiExampleMinToHit() != 12)
                ++bad;
            if (uamwBsiExampleRoll13Dmg() != 2)
                ++bad;
            if (uamwBsiExampleRoll14Dmg() != 4)
                ++bad;
            if (uamwBsiExampleRoll15Dmg() != 8)
                ++bad;
            if (uamwBsiBaseDmgSmLo() != 2) ++bad;
            if (uamwBsiBaseDmgSmHi() != 5) ++bad;
            if (uamwBsiBaseDmgLLo() != 2) ++bad;
            if (uamwBsiBaseDmgLHi() != 7) ++bad;
            // the example ladder:
            // each point of die
            // difference doubles
            // through the extras,
            // 2, 4, 8
            if (2 * uamwBsiExampleRoll13Dmg()
                    != uamwBsiExampleRoll14Dmg())
                ++bad;
            if (2 * uamwBsiExampleRoll14Dmg()
                    != uamwBsiExampleRoll15Dmg())
                ++bad;
            // the base damage bands
            // ride 2-5 and 2-7
            if (uamwBsiBaseDmgSmLo()
                    >= uamwBsiBaseDmgSmHi()) ++bad;
            if (uamwBsiBaseDmgLLo()
                    >= uamwBsiBaseDmgLHi()) ++bad;
        // ---- the dagger
        // Longtooth ----
            if (!uamwDlgNormalAppearance()) ++bad;
            if (!uamwDlgBroadBladed()) ++bad;
            if (uamwDlgBonus() != 2) ++bad;
            if (!uamwDlgSmallDemiHumanLengthens())
                ++bad;
            if (!uamwDlgFunctionsAsShortSword())
                ++bad;
            if (!uamwDlgLightAsDagger()) ++bad;
            if (!uamwDlgPenetratesWoodStone())
                ++bad;
            if (!uamwDlgMaxDamageVsWoodStone())
                ++bad;
        // ---- the dagger of
        // throwing ----
            if (!uamwDthNormalButStrongDweomer())
                ++bad;
            if (!uamwDthPerfectBalance()) ++bad;
            if (!uamwDthSuperbRangedWeapon()) ++bad;
            if (uamwDthHurledRangeIn() != 6) ++bad;
            if (uamwDthRangeCellsGarbles()) ++bad;
            if (!uamwDthTwiceNormalDamage())
                ++bad;
            if (uamwDthBonusLo() != 1) ++bad;
            if (uamwDthBonusHi() != 4) ++bad;
            if (uamwDthBand1Lo() != 1) ++bad;
            if (uamwDthBand1Hi() != 35) ++bad;
            if (uamwDthBand2Lo() != 36) ++bad;
            if (uamwDthBand2Hi() != 65) ++bad;
            if (uamwDthBand3Lo() != 66) ++bad;
            if (uamwDthBand3Hi() != 90) ++bad;
            if (uamwDthBand4Lo() != 91) ++bad;
            if (uamwDthBand4Hi() != 100) ++bad;
            if (uamwDthXpBase() != 150) ++bad;
            if (uamwDthXpPerPlus() != 100) ++bad;
            if (uamwDthGpBase() != 1500) ++bad;
            if (uamwDthGpPerPlus() != 1000) ++bad;
            // the d100 bands tile
            // exactly, 35+30+25+10
            if (uamwDthBand1Hi() - uamwDthBand1Lo()
                    + 1 + uamwDthBand2Hi()
                    - uamwDthBand2Lo() + 1
                    + uamwDthBand3Hi()
                    - uamwDthBand3Lo() + 1
                    + uamwDthBand4Hi()
                    - uamwDthBand4Lo() + 1
                    != 100) ++bad;
            // the gp rate is ten
            // times the xp rate,
            // base and per plus
            if (10 * uamwDthXpBase()
                    != uamwDthGpBase()) ++bad;
            if (10 * uamwDthXpPerPlus()
                    != uamwDthGpPerPlus()) ++bad;
        // ---- the hornblade ----
            if (!uamwHblSickleLikeAppearance())
                ++bad;
            if (!uamwHblAnimalHornResemblance())
                ++bad;
            if (uamwHblInspectionUnlikelyPct()
                    != 90) ++bad;
            if (uamwHblHandleSentenceGarbles())
                ++bad;
            if (!uamwHblFaintEnchantmentDweomer())
                ++bad;
            if (!uamwHblBladeSpringsOnPressure())
                ++bad;
            if (uamwHblSmallBonusLo() != 1) ++bad;
            if (uamwHblSmallBonusHi() != 2) ++bad;
            if (uamwHblScimitarBonusLo() != 2)
                ++bad;
            if (uamwHblScimitarBonusHi() != 3)
                ++bad;
            if (!uamwHblSmallThrowable()) ++bad;
            if (!uamwHblBonusToHitAndDamage())
                ++bad;
            if (!uamwHblSickleClassUsers()) ++bad;
            if (!uamwHblNeedsCategoryProficiency())
                ++bad;
            if (!uamwHblRetractable()) ++bad;
            if (uamwHblValueTableRows() != 6)
                ++bad;
            if (uamwHblRow1Lo() != 1) ++bad;
            if (uamwHblRow1Hi() != 20) ++bad;
            if (uamwHblKnifePlus1Xp() != 500) ++bad;
            if (uamwHblKnifePlus1Gp() != 1500)
                ++bad;
            if (uamwHblRow2Lo() != 21) ++bad;
            if (uamwHblRow2Hi() != 35) ++bad;
            if (uamwHblKnifePlus2Xp() != 1000)
                ++bad;
            if (uamwHblKnifePlus2Gp() != 3000)
                ++bad;
            if (uamwHblRow3Lo() != 36) ++bad;
            if (uamwHblRow3Hi() != 50) ++bad;
            if (uamwHblDaggerPlus1Xp() != 750) ++bad;
            if (uamwHblDaggerPlus1Gp() != 2000)
                ++bad;
            if (uamwHblRow4Lo() != 51) ++bad;
            if (uamwHblRow4Hi() != 70) ++bad;
            if (uamwHblDaggerPlus2Xp() != 1500)
                ++bad;
            if (uamwHblDaggerPlus2Gp() != 4000)
                ++bad;
            if (uamwHblRow5Lo() != 71) ++bad;
            if (uamwHblRow5Hi() != 90) ++bad;
            if (uamwHblScimPlus2Xp() != 2000) ++bad;
            if (uamwHblScimPlus2Gp() != 6000)
                ++bad;
            if (uamwHblRow6Lo() != 91) ++bad;
            if (uamwHblRow6Hi() != 100) ++bad;
            if (uamwHblScimPlus3Xp() != 3000) ++bad;
            if (uamwHblScimPlus3Gp() != 9000)
                ++bad;
            // the six rows tile the
            // d100, 20+15+15+20+20+10
            if (uamwHblRow1Hi() - uamwHblRow1Lo()
                    + 1 + uamwHblRow2Hi()
                    - uamwHblRow2Lo() + 1
                    + uamwHblRow3Hi()
                    - uamwHblRow3Lo() + 1
                    + uamwHblRow4Hi()
                    - uamwHblRow4Lo() + 1
                    + uamwHblRow5Hi()
                    - uamwHblRow5Lo() + 1
                    + uamwHblRow6Hi()
                    - uamwHblRow6Lo() + 1
                    != 100) ++bad;
            // the knife and scimitar
            // rows sell at thrice
            // their XP
            if (3 * uamwHblKnifePlus1Xp()
                    != uamwHblKnifePlus1Gp()) ++bad;
            if (3 * uamwHblScimPlus3Xp()
                    != uamwHblScimPlus3Gp()) ++bad;
        // ---- the darts of
        // homing ----
            if (!uamwDhoNormalProjectileAppearance())
                ++bad;
            if (uamwDhoPlusValue() != 3) ++bad;
            if (!uamwDhoAlterationEnchantmentDweomer())
                ++bad;
            if (!uamwDhoReturnsSameRound()) ++bad;
            if (!uamwDhoReusable()) ++bad;
            if (uamwDhoDamageLo() != 4) ++bad;
            if (uamwDhoDamageHi() != 9) ++bad;
            if (uamwDhoBaseLo() != 1) ++bad;
            if (uamwDhoBaseHi() != 6) ++bad;
            if (!uamwDhoMissLosesDweomer()) ++bad;
            if (!uamwDhoTwiceOrdinaryRange())
                ++bad;
            if (uamwDhoShortRangeIn() != 3) ++bad;
            if (uamwDhoMediumRangeIn() != 8) ++bad;
            if (uamwDhoLongRangeIn() != 9) ++bad;
            // the damage band is
            // the base plus the
            // bonus, 1+3 to 6+3
            if (uamwDhoBaseLo() + uamwDhoPlusValue()
                    != uamwDhoDamageLo()) ++bad;
            if (uamwDhoBaseHi() + uamwDhoPlusValue()
                    != uamwDhoDamageHi()) ++bad;
        // ---- the knife buckle
        // ----
            if (!uamwKbuBuckleOrnamentHilt())
                ++bad;
            if (!uamwKbuEasilyGraspedDrawn())
                ++bad;
            if (!uamwKbuSharpAsLargerKnife())
                ++bad;
            if (uamwKbuVarieties() != 4) ++bad;
            if (uamwKbuPlus1Lo() != 1) ++bad;
            if (uamwKbuPlus1Hi() != 4) ++bad;
            if (uamwKbuPlus2Lo() != 5) ++bad;
            if (uamwKbuPlus2Hi() != 7) ++bad;
            if (uamwKbuPlus3Lo() != 8) ++bad;
            if (uamwKbuPlus3Hi() != 9) ++bad;
            if (uamwKbuPlus4Lo() != 10) ++bad;
            if (uamwKbuPlus4Hi() != 10) ++bad;
            if (uamwKbuXpPerPlus() != 100) ++bad;
            if (uamwKbuGpPerPlus() != 1000) ++bad;
            // the d10 bands tile,
            // 4+3+2+1
            if (uamwKbuPlus1Hi() - uamwKbuPlus1Lo()
                    + 1 + uamwKbuPlus2Hi()
                    - uamwKbuPlus2Lo() + 1
                    + uamwKbuPlus3Hi()
                    - uamwKbuPlus3Lo() + 1
                    + uamwKbuPlus4Hi()
                    - uamwKbuPlus4Lo() + 1
                    != 10) ++bad;
            // the sale value is ten
            // times the XP per plus
            if (10 * uamwKbuXpPerPlus()
                    != uamwKbuGpPerPlus()) ++bad;
        // ---- the magic
        // quarterstaff ----
            if (!uamwQstBronzewoodIronShod())
                ++bad;
            if (!uamwQstStrongAsSteel()) ++bad;
            if (!uamwQstLengthOnCommand()) ++bad;
            if (uamwQstLengthLoFt() != 6) ++bad;
            if (uamwQstLengthHiFt() != 12) ++bad;
            if (uamwQstDamageLo() != 1) ++bad;
            if (uamwQstDamageHi() != 6) ++bad;
            if (uamwQstVarieties() != 5) ++bad;
            if (uamwQstPlus1Lo() != 1) ++bad;
            if (uamwQstPlus1Hi() != 5) ++bad;
            if (uamwQstPlus2Lo() != 6) ++bad;
            if (uamwQstPlus2Hi() != 9) ++bad;
            if (uamwQstPlus3Lo() != 10) ++bad;
            if (uamwQstPlus3Hi() != 13) ++bad;
            if (uamwQstPlus4Lo() != 14) ++bad;
            if (uamwQstPlus4Hi() != 17) ++bad;
            if (uamwQstPlus5Lo() != 18) ++bad;
            if (uamwQstPlus5Hi() != 20) ++bad;
            if (uamwQstXpPerPlus() != 250) ++bad;
            if (uamwQstGpPerPlus() != 1500) ++bad;
            // the d20 bands tile,
            // 5+4+4+4+3
            if (uamwQstPlus1Hi() - uamwQstPlus1Lo()
                    + 1 + uamwQstPlus2Hi()
                    - uamwQstPlus2Lo() + 1
                    + uamwQstPlus3Hi()
                    - uamwQstPlus3Lo() + 1
                    + uamwQstPlus4Hi()
                    - uamwQstPlus4Lo() + 1
                    + uamwQstPlus5Hi()
                    - uamwQstPlus5Lo() + 1
                    != 20) ++bad;
            // the commanded length
            // doubles, 6 to 12
            if (2 * uamwQstLengthLoFt()
                    != uamwQstLengthHiFt()) ++bad;
            // the gp rate is six
            // times the xp rate
            if (6 * uamwQstXpPerPlus()
                    != uamwQstGpPerPlus()) ++bad;
        // ---- the scimitar of
        // speed ----
            if (uamwSscUsualBonus() != 2) ++bad;
            if (!uamwSscFirstAttackAlways()) ++bad;
            if (!uamwSscWorksDespiteSlowing())
                ++bad;
            if (!uamwSscFirstSegmentStrike()) ++bad;
            if (!uamwSscAttacksUpOnePlace()) ++bad;
            if (!uamwSscOneToThreeHalves()) ++bad;
            if (!uamwSscThreeHalvesToTwo()) ++bad;
            if (!uamwSscCumulativeWithBonusAttacks())
                ++bad;
            if (!uamwSscVariantForms()) ++bad;
            if (uamwSscVariantTotalPct() != 30)
                ++bad;
            if (uamwSscEachVariantPct() != 10) ++bad;
            if (uamwSscVariantCount() != 3) ++bad;
            if (uamwSscAlternateBonusChancePct()
                    != 25) ++bad;
            if (uamwSscAltPlus1Lo() != 1) ++bad;
            if (uamwSscAltPlus1Hi() != 50) ++bad;
            if (uamwSscAltPlus3Lo() != 51) ++bad;
            if (uamwSscAltPlus3Hi() != 75) ++bad;
            if (uamwSscAltPlus4Lo() != 76) ++bad;
            if (uamwSscAltPlus4Hi() != 90) ++bad;
            if (uamwSscAltPlus5Lo() != 91) ++bad;
            if (uamwSscAltPlus5Hi() != 100) ++bad;
            if (uamwSscPlus1Xp() != 2500) ++bad;
            if (uamwSscPlus1Gp() != 9000) ++bad;
            if (uamwSscPlus2Xp() != 3000) ++bad;
            if (uamwSscPlus2Gp() != 12000) ++bad;
            if (uamwSscPlus3Xp() != 3500) ++bad;
            if (uamwSscPlus3Gp() != 15000) ++bad;
            if (uamwSscPlus4Xp() != 4000) ++bad;
            if (uamwSscPlus4Gp() != 18000) ++bad;
            if (uamwSscPlus5Xp() != 4500) ++bad;
            if (uamwSscPlus5Gp() != 21000) ++bad;
            // the three variant
            // forms at 10% each sum
            // to the 30% overall
            if (uamwSscVariantCount()
                    * uamwSscEachVariantPct()
                    != uamwSscVariantTotalPct()) ++bad;
            // the alternate bonus
            // bands tile the d100,
            // 50+25+15+10
            if (uamwSscAltPlus1Hi()
                    - uamwSscAltPlus1Lo() + 1
                    + uamwSscAltPlus3Hi()
                    - uamwSscAltPlus3Lo() + 1
                    + uamwSscAltPlus4Hi()
                    - uamwSscAltPlus4Lo() + 1
                    + uamwSscAltPlus5Hi()
                    - uamwSscAltPlus5Lo() + 1
                    != 100) ++bad;
            // the xp and gp ladders
            // climb in even steps,
            // 500 and 3,000, from
            // the +1 to the +5 row
            if (uamwSscPlus2Xp() - uamwSscPlus1Xp()
                    != 500) ++bad;
            if (uamwSscPlus3Xp() - uamwSscPlus2Xp()
                    != 500) ++bad;
            if (uamwSscPlus4Xp() - uamwSscPlus3Xp()
                    != 500) ++bad;
            if (uamwSscPlus5Xp() - uamwSscPlus4Xp()
                    != 500) ++bad;
            if (uamwSscPlus2Gp() - uamwSscPlus1Gp()
                    != 3000) ++bad;
            if (uamwSscPlus3Gp() - uamwSscPlus2Gp()
                    != 3000) ++bad;
            if (uamwSscPlus4Gp() - uamwSscPlus3Gp()
                    != 3000) ++bad;
            if (uamwSscPlus5Gp() - uamwSscPlus4Gp()
                    != 3000) ++bad;
        // ---- the part ledger ----
            if (uamwPartItemTotal() != 9) ++bad;
            if (uamwPartCleanCount() != 9) ++bad;
            if (uamwPartFlaggedCount() != 0) ++bad;
            if (uamwPartGarbledCount() != 0) ++bad;
            if (uamwPartCleanCount()
                    + uamwPartFlaggedCount()
                    + uamwPartGarbledCount()
                    != uamwPartItemTotal()) ++bad;
        // ---- the R387 armor seam ----
            if (uaaspPartItemTotal() != 8) ++bad;
            if (uaaspPartCleanCount() != 8) ++bad;
            if (uaaspPartFlaggedCount() != 0)
                ++bad;
            if (uaaspPartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (uadsRowBodiesGarble()) ++bad;
        printf("R388 UA misc weapons prose pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
