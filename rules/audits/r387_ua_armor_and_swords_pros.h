    // ---- R387: the UA armor and
    // swords prose pin audit ----
    // The R399 clean read fills
    // every flagged hole this
    // block names.
    // The pp. 104-105 stretch:
    // eight pins - four fully
    // clean (the anything armor,
    // the short sword of
    // quickness, the sword of
    // the planes, the anything
    // sword) plus four
    // mechanics-clean with
    // flagged holes (the elfin
    // chain mail's size-table
    // garble, the plate's
    // conform seam, the sun
    // blade's radiance seam, the
    // Final Word broadswords'
    // names tail); the R386 seam
    // the part-6 ledger, the
    // R375 seam the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the construction
        // rule ----
            if (uaaspCnsBonus3Material() != 3)
                ++bad;
            if (!uaaspCnsBonus3MeteoriteIron())
                ++bad;
            if (uaaspCnsBonus4Material() != 4)
                ++bad;
            if (!uaaspCnsBonus4MithralAlloyed())
                ++bad;
            if (uaaspCnsBonus5Material() != 5)
                ++bad;
            if (!uaaspCnsBonus5AdamantiteAlloyed())
                ++bad;
            // the material ladder
            // steps one bonus at a
            // time, 3, 4, 5
            if (uaaspCnsBonus3Material() + 1
                    != uaaspCnsBonus4Material()) ++bad;
            if (uaaspCnsBonus4Material() + 1
                    != uaaspCnsBonus5Material()) ++bad;
        // ---- the anything armor
        // ----
            if (!uaaspAamAnyConstruction()) ++bad;
            if (uaaspAamOriginalBonus() != 1) ++bad;
            if (!uaaspAamChangesOnCommand()) ++bad;
            if (!uaaspAamTypeNeedNotMatchConstruction())
                ++bad;
            if (!uaaspAamEachChangeSingular()) ++bad;
            if (!uaaspAamNoTypeTwice()) ++bad;
            if (uaaspAamNonSpecialChangeHours()
                    != 24) ++bad;
            if (!uaaspAamNonSpecialLastsOneDay())
                ++bad;
            if (!uaaspAamRevertsToPlusOne()) ++bad;
            if (uaaspAamSpecialChangeHours() != 1)
                ++bad;
            if (uaaspAamChangesAllowed() != 3) ++bad;
            if (!uaaspAamLosesAllMagicAfter()) ++bad;
            // the non-special change
            // is a full day of 24
            // hours, twenty-four
            // times the special one
            if (24 * uaaspAamSpecialChangeHours()
                    != uaaspAamNonSpecialChangeHours())
                ++bad;
        // ---- the elfin chain
        // mail ----
            if (!uaaspEcmWornUnderClothing()) ++bad;
            if (!uaaspEcmThievesCanUtilize()) ++bad;
            if (!uaaspEcmMaySlightlyHinder()) ++bad;
            if (!uaaspEcmRareForNonElves()) ++bad;
            if (uaaspEcmSizeTableRows() != 5) ++bad;
            if (uaaspEcmHairfootLo() != 1) ++bad;
            if (uaaspEcmHairfootHi() != 10) ++bad;
            if (uaaspEcmDwarfHalflingLo() != 11)
                ++bad;
            if (uaaspEcmDwarfHalflingHi() != 15)
                ++bad;
            if (uaaspEcmElfHalfElfLo() != 16) ++bad;
            if (uaaspEcmElfHalfElfHi() != 80) ++bad;
            if (uaaspEcmManNormalLo() != 81) ++bad;
            if (uaaspEcmManNormalHi() != 95) ++bad;
            if (uaaspEcmManLargeLo() != 96) ++bad;
            if (uaaspEcmManLargeHi() != 100) ++bad;
            if (uaaspEcmManNormalLbs() != 200) ++bad;
            if (uaaspEcmManLargeLbs() != 250) ++bad;
            if (uaaspEcmSizeTableGarbles()) ++bad;
            // the five size bands
            // tile the d100 exactly,
            // 10+5+65+15+5 = 100
            if (uaaspEcmHairfootHi()
                    - uaaspEcmHairfootLo() + 1
                    + uaaspEcmDwarfHalflingHi()
                    - uaaspEcmDwarfHalflingLo() + 1
                    + uaaspEcmElfHalfElfHi()
                    - uaaspEcmElfHalfElfLo() + 1
                    + uaaspEcmManNormalHi()
                    - uaaspEcmManNormalLo() + 1
                    + uaaspEcmManLargeHi()
                    - uaaspEcmManLargeLo() + 1
                    != 100) ++bad;
            // the bands chain
            // head to tail, 1
            // through 100
            if (uaaspEcmHairfootHi() + 1
                    != uaaspEcmDwarfHalflingLo()) ++bad;
            if (uaaspEcmDwarfHalflingHi() + 1
                    != uaaspEcmElfHalfElfLo()) ++bad;
            if (uaaspEcmElfHalfElfHi() + 1
                    != uaaspEcmManNormalLo()) ++bad;
            if (uaaspEcmManNormalHi() + 1
                    != uaaspEcmManLargeLo()) ++bad;
            // the large man-sized
            // suit carries fifty
            // more pounds
            if (uaaspEcmManLargeLbs()
                    - uaaspEcmManNormalLbs() != 50)
                ++bad;
        // ---- the plate ----
            if (!uaaspPltFieldOrFullPlate()) ++bad;
            if (!uaaspPltConformsToWearer()) ++bad;
            if (!uaaspPltSameRaceRequired()) ++bad;
            if (uaaspPltConformSeamGarbles()) ++bad;
            if (uaaspPltFieldAbsorbPerPlus() != 10)
                ++bad;
            if (uaaspPltFullAbsorbPerPlus() != 16)
                ++bad;
            if (uaaspPltFieldRepairDays() != 1) ++bad;
            if (uaaspPltFieldRepairGp() != 100) ++bad;
            if (uaaspPltFullRepairDays() != 2) ++bad;
            if (uaaspPltFullRepairGp() != 200) ++bad;
            if (!uaaspPltRepairsNeedMagicArmorer())
                ++bad;
            // the full plate repair
            // doubles the field
            // plate, in days and gp
            if (2 * uaaspPltFieldRepairDays()
                    != uaaspPltFullRepairDays()) ++bad;
            if (2 * uaaspPltFieldRepairGp()
                    != uaaspPltFullRepairGp()) ++bad;
            // the full plate absorbs
            // six more points per
            // plus than the field
            if (uaaspPltFullAbsorbPerPlus()
                    - uaaspPltFieldAbsorbPerPlus()
                    != 6) ++bad;
        // ---- the short sword
        // of quickness ----
            if (!uaaspQswStrikesFirstEveryRound())
                ++bad;
            if (uaaspQswBonus() != 2) ++bad;
            if (!uaaspQswBonusToHitAndDamage())
                ++bad;
        // ---- the sword of the
        // planes ----
            if (!uaaspPlnBroadswordOnly()) ++bad;
            if (uaaspPlnPrimeBonus() != 1) ++bad;
            if (uaaspPlnInnerPlanesBonus() != 2)
                ++bad;
            if (!uaaspPlnInnerAppliesVsOpponents())
                ++bad;
            if (uaaspPlnOuterPlanesBonus() != 3)
                ++bad;
            if (!uaaspPlnOuterAppliesVsOpponents())
                ++bad;
            if (uaaspPlnAstralEtherealBonus() != 4)
                ++bad;
            if (!uaaspPlnAstralAppliesVsOpponents())
                ++bad;
            // the planar bonus
            // ladder steps one at a
            // time, 1 through 4
            if (uaaspPlnPrimeBonus() + 1
                    != uaaspPlnInnerPlanesBonus())
                ++bad;
            if (uaaspPlnInnerPlanesBonus() + 1
                    != uaaspPlnOuterPlanesBonus())
                ++bad;
            if (uaaspPlnOuterPlanesBonus() + 1
                    != uaaspPlnAstralEtherealBonus())
                ++bad;
        // ---- the sun blade ----
            if (!uaaspSubTreatedAsBastard()) ++bad;
            if (!uaaspSubWieldedAsShortSword())
                ++bad;
            if (!uaaspSubEitherProficiencyServes())
                ++bad;
            if (uaaspSubNormalBonus() != 2) ++bad;
            if (uaaspSubEvilBonus() != 4) ++bad;
            if (!uaaspSubDoubleDamageVsNegative())
                ++bad;
            if (!uaaspSubRadianceOnCommand()) ++bad;
            if (uaaspSubRadianceSeamGarbles())
                ++bad;
            if (uaaspSubRadianceStartFt() != 10)
                ++bad;
            if (uaaspSubRadianceSpreadPerRoundFt()
                    != 5) ++bad;
            if (uaaspSubRadianceSpreadRounds()
                    != 10) ++bad;
            if (uaaspSubRadianceFullRadiusFt()
                    != 60) ++bad;
            if (uaaspSubDimGlowRounds() != 10)
                ++bad;
            if (!uaaspSubOncePerDay()) ++bad;
            if (!uaaspSubGoodAlignment()) ++bad;
            // the evil bonus doubles
            // the normal one
            if (2 * uaaspSubNormalBonus()
                    != uaaspSubEvilBonus()) ++bad;
            // the radiance starts at
            // 10 feet and spreads 5
            // per round for 10
            // rounds: 10 + 50 = 60
            if (uaaspSubRadianceStartFt()
                    + uaaspSubRadianceSpreadPerRoundFt()
                    * uaaspSubRadianceSpreadRounds()
                    != uaaspSubRadianceFullRadiusFt())
                ++bad;
            // the dim glow persists
            // as long as the spread
            if (uaaspSubDimGlowRounds()
                    != uaaspSubRadianceSpreadRounds())
                ++bad;
        // ---- the anything sword
        // ----
            if (uaaspAswOriginalBonus() != 1) ++bad;
            if (!uaaspAswAnyOriginalType()) ++bad;
            if (!uaaspAswChangesOnCommand()) ++bad;
            if (!uaaspAswAnyPower()) ++bad;
            if (uaaspAswExampleAvengerBonus() != 5)
                ++bad;
            if (uaaspAswFormHours() != 24) ++bad;
            if (!uaaspAswEndsOnSpecialFunction())
                ++bad;
            if (uaaspAswChangesAllowed() != 3) ++bad;
            if (!uaaspAswEachFormSingular()) ++bad;
            if (!uaaspAswNoFormRepeated()) ++bad;
            if (!uaaspAswOrdinaryAfterThird()) ++bad;
            if (!uaaspAswNeverIntelligent()) ++bad;
            // the commanded form
            // lasts a full day of 24
            // hours
            if (uaaspAswFormHours() != 24) ++bad;
            // the example avenger
            // rides the +5 cap of
            // the bonus ladder
            if (uaaspAswExampleAvengerBonus()
                    != uaaspCnsBonus5Material()) ++bad;
        // ---- the Final Word
        // broadswords ----
            if (uaaspFwbKnownCount() != 9) ++bad;
            if (!uaaspFwbPatternedAfterFragarach())
                ++bad;
            if (!uaaspFwbFragarachMeansFinalWord())
                ++bad;
            if (!uaaspFwbDifferingAlignments())
                ++bad;
            if (!uaaspFwbUnlikeAlignmentNoBonuses())
                ++bad;
            if (uaaspFwbLikeAlignmentBonus() != 3)
                ++bad;
            if (!uaaspFwbAlwaysStrikesLast()) ++bad;
            if (!uaaspFwbUnerringCounterstrike())
                ++bad;
            if (!uaaspFwbCounterstrikesHitOrMiss())
                ++bad;
            if (!uaaspFwbUpToWielderAttacks()) ++bad;
            if (!uaaspFwbPlus3Only()) ++bad;
            if (uaaspFwbPommelGemGp() != 10000)
                ++bad;
            if (!uaaspFwbEachGemDifferent()) ++bad;
            if (uaaspFwbNamesTailGarbles()) ++bad;
            // the nine blades with
            // differing alignments
            // still share the one
            // +3 counterstrike bonus
            if (uaaspFwbKnownCount() != 9) ++bad;
        // ---- the part ledger ----
            if (uaaspPartItemTotal() != 8) ++bad;
            if (uaaspPartCleanCount() != 8) ++bad;
            if (uaaspPartFlaggedCount() != 0) ++bad;
            if (uaaspPartGarbledCount() != 0) ++bad;
            if (uaaspPartCleanCount()
                    + uaaspPartFlaggedCount()
                    + uaaspPartGarbledCount()
                    != uaaspPartItemTotal()) ++bad;
        // ---- the R386 part-6 seam ----
            if (uamm6PartItemTotal() != 5) ++bad;
            if (uamm6PartCleanCount() != 5) ++bad;
            if (uamm6PartFlaggedCount() != 0)
                ++bad;
            if (uamm6PartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (uadsRowBodiesGarble()) ++bad;
        printf("R387 UA armor and swords prose pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
