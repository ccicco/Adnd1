    // ---- R394: the UA DM tables
    // manifest sweep pin audit ----
    // The clean PDF read (pp. 74, 76,
    // 82-83, 106-108) fills the flagged
    // holes and closes the DM tables
    // manifest: Method V (the 12 x 7
    // dice-count matrix), the barding
    // movement column repin (the R370
    // labels sat one column off), the
    // LLC label, the high-elf sign, the
    // Appendix Q hole set. Ten manifest
    // items flip CLOSED; the census
    // 320 -> 321.
    {
        using namespace rules;
        int bad = 0;
        // ---- the Method V matrix ----
            static const int mv[12][7] = {
                {8, 6, 4, 7, 9, 3, 5},
                {7, 5, 8, 3, 6, 9, 4},
                {7, 4, 9, 5, 8, 6, 3},
                {7, 4, 8, 5, 6, 9, 3},
                {9, 3, 5, 7, 8, 6, 4},
                {9, 3, 5, 7, 8, 6, 4},
                {7, 6, 8, 5, 9, 4, 3},
                {4, 9, 7, 8, 6, 5, 3},
                {3, 8, 7, 9, 5, 6, 4},
                {6, 5, 3, 9, 7, 4, 8},
                {6, 7, 4, 9, 8, 3, 5},
                {7, 5, 9, 8, 6, 4, 3},
            };
            if (uasm1MethodVClassCount() != 12)
                ++bad;
            if (uasm1MethodVAbilityCount() != 7)
                ++bad;
            for (int c = 0; c < 12; ++c) {
                for (int a = 0; a < 7; ++a) {
                    if (uasm1MethodVDice(c, a)
                            != mv[c][a]) ++bad;
                }
            }
            // the fighter strength cell
            // matches the printed example
            if (uasm1MethodVDice(4, 0)
                    != uasm1MethodVFighterStrengthDice())
                ++bad;
            // every cell between 3 and 9
            for (int c = 0; c < 12; ++c) {
                for (int a = 0; a < 7; ++a) {
                    if (uasm1MethodVDice(c, a) < 3)
                        ++bad;
                    if (uasm1MethodVDice(c, a) > 9)
                        ++bad;
                }
            }
        // ---- the barding repin ----
            if (uasm1BardLightLeather()
                    <= uasm1BardLightScale()) ++bad;
            if (uasm1BardMediumLeather()
                    <= uasm1BardMediumScale()) ++bad;
            if (uasm1BardMediumScale()
                    <= uasm1BardMediumChain()) ++bad;
            if (uasm1BardHeavyLeather()
                    <= uasm1BardHeavyScale()) ++bad;
            if (uasm1BardHeavyScale()
                    <= uasm1BardHeavyChain()) ++bad;
            if (uasm1BardHeavyChain()
                    <= uasm1BardHeavyPlate()) ++bad;
            // the ladder: lighter horses
            // run faster in leather
            if (uasm1BardMediumLeather()
                    <= uasm1BardHeavyLeather())
                ++bad;
        // ---- the social class fill ----
            if (strcmp(uasocRosterName(0, 0),
                    "Freed slaves") != 0) ++bad;
            if (uasocLlcLabelCellGarbled()) ++bad;
            if (uasocHalflingParentheticalDivergence())
                ++bad;
        // ---- the birth fill ----
            if (uabirthElfHighMod() != -20) ++bad;
            if (uabirthElfHighModMagnitude() != 20) ++bad;
            if (uabirthElfHighModSignLost()) ++bad;
        // ---- the Appendix Q fills ----
            if (uaqSysOneSixFtExampleFt() != 6)
                ++bad;
            if (uaqSysOneSixFtLimitTenths() != 75)
                ++bad;
            // 6 feet at 125 percent is
            // 75 tenths (7 1/2 feet)
            if (uaqSysOneSixFtExampleFt()
                    * uaqSysOneHeightPctLimit()
                    / 10 != uaqSysOneSixFtLimitTenths())
                ++bad;
            if (!uaqPumSemiDemonException()) ++bad;
            if (!uaqPumMergedMiddleColumn()) ++bad;
            if (!uaqPumUnexSmallSoftNoEffect())
                ++bad;
            if (uaqPumUnexMergedPerPt() != 1) ++bad;
            if (uaqPumUnexMergedCap() != 20) ++bad;
            if (uaqPumUnexLargeHardPerPt() != 2)
                ++bad;
            if (uaqPumUnexLargeHardCap() != 40)
                ++bad;
            if (uaqPumSemiSmallSoftPerPt() != 1)
                ++bad;
            if (uaqPumSemiSmallSoftCap() != 20)
                ++bad;
            if (uaqPumSemiMergedPerPt() != 2) ++bad;
            if (uaqPumSemiMergedCap() != 40) ++bad;
            if (uaqPumSemiLargeHardPerPt() != 4)
                ++bad;
            if (uaqPumSemiLargeHardCap() != 75)
                ++bad;
            // the exposed row completes
            // the 3 x 3 walk (the R389
            // pins seam-agree)
            if (uaqPumExposedSmallSoftPerPt()
                    != uaqPumSemiMergedPerPt())
                ++bad;
            if (uaqPumExposedSmallHardPerPt()
                    != uaqPumSemiLargeHardPerPt())
                ++bad;
            // the R389 fragment pairs
            // attribute to the cells
            if (uaqPumFragPair1PerPt()
                    != uaqPumSemiSmallSoftPerPt())
                ++bad;
            if (uaqPumFragPair2PerPt()
                    != uaqPumSemiMergedPerPt())
                ++bad;
            if (uaqPumFragPair3PerPt()
                    != uaqPumSemiLargeHardPerPt())
                ++bad;
            if (uaqPumUnexMergedPerPt()
                    != uaqPumFragPair1PerPt())
                ++bad;
            if (uaqPumLargeDamageLo() != 1) ++bad;
            if (uaqPumLargeDamageHi() != 4) ++bad;
            if (!uaqPumAcrobatAttackAdds()) ++bad;
            if (uaqPumAcrobatStunCap() != 95) ++bad;
            if (!uaqPumAcrobatDefenseSubtracts()) ++bad;
            if (!uaqKickSmallerOverallArmor())
                ++bad;
            if (!uaqGrapStr17OneStepBetterAc())
                ++bad;
            if (uaqGrapDefMBySizeLHi()
                    < uaqGrapDefSBySizeL())
                ++bad;
            if (!uaqOvbAllBonusesConsidered()) ++bad;
            if (!uaqOvbAcModifiedForRelativeSize())
                ++bad;
            if (!uaqOvbAcAffectedFourPlusLegs())
                ++bad;
        printf("R394 UA DM tables manifest pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
