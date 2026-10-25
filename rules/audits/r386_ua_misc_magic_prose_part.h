    // ---- R386: the UA misc magic
    // prose part 6 pin audit ----
    // The R398 clean read fills
    // every flagged hole this
    // block names.
    // The S-Z close-out: five pins -
    // two fully clean (the wind fan,
    // Zagyg's flowing flagon) plus
    // three mechanics-clean with
    // flagged holes (the stone
    // horse's activation word seam,
    // the ultimate solution's
    // transmutation seam, Zagyg's
    // spell component case's gp
    // tail); the R385 seam the
    // part-5 ledger, the R375 seam
    // the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the stone horse ----
            if (!uamm6ShStatueAppearance()) ++bad;
            if (!uamm6ShCarvedFromHardStone())
                ++bad;
            if (uamm6ShTwoSorts() != 2) ++bad;
            if (!uamm6ShActivationWord()) ++bad;
            if (!uamm6ShAnimateCarryAttack())
                ++bad;
            if (uamm6ShActivationSeamGarbles())
                ++bad;
            if (uamm6ShCarriesLbs() != 1000)
                ++bad;
            if (!uamm6ShTirelessNoFeeding())
                ++bad;
            if (!uamm6ShRepairByStoneToFlesh())
                ++bad;
            if (uamm6ShHealPerDay() != 1) ++bad;
            if (!uamm6ShRevertsWhenHealed())
                ++bad;
        // ---- the courser ----
            if (!uamm6CrsLightHorseRate()) ++bad;
            if (!uamm6CrsMediumWarhorseAttacks())
                ++bad;
            if (uamm6CrsAttacksPerRound() != 3)
                ++bad;
            if (uamm6CrsHoofDamageLo() != 1)
                ++bad;
            if (uamm6CrsHoofDamageHi() != 6)
                ++bad;
            if (uamm6CrsThirdAttackDamageLo()
                    != 1) ++bad;
            if (uamm6CrsThirdAttackDamageHi()
                    != 3) ++bad;
            if (uamm6CrsArmorClass() != 3) ++bad;
            if (uamm6CrsHitPoints() != 18) ++bad;
            if (!uamm6CrsSavesAsHardMetal())
                ++bad;
        // ---- the destrier ----
            if (!uamm6DstMediumHorseRate())
                ++bad;
            if (!uamm6DstHeavyWarhorseAttacks())
                ++bad;
            if (uamm6DstAttacksPerRound() != 3)
                ++bad;
            if (uamm6DstHoofDamageLo() != 1)
                ++bad;
            if (uamm6DstHoofDamageHi() != 8)
                ++bad;
            if (uamm6DstThirdAttackDamageLo()
                    != 1) ++bad;
            if (uamm6DstThirdAttackDamageHi()
                    != 3) ++bad;
            if (uamm6DstArmorClass() != 1) ++bad;
            if (uamm6DstHitPoints() != 26) ++bad;
            if (!uamm6DstSavesAsHardMetal())
                ++bad;
            // both steeds attack
            // three times with the
            // same rear-attack die
            if (uamm6CrsAttacksPerRound()
                    != uamm6DstAttacksPerRound())
                ++bad;
            if (uamm6CrsThirdAttackDamageLo()
                    != uamm6DstThirdAttackDamageLo())
                ++bad;
            if (uamm6CrsThirdAttackDamageHi()
                    != uamm6DstThirdAttackDamageHi())
                ++bad;
            // the destrier bests the
            // courser by two armor
            // classes and eight hit
            // points, with hoof dice
            // 8 over 6
            if (uamm6CrsArmorClass()
                    - uamm6DstArmorClass() != 2)
                ++bad;
            if (uamm6DstHitPoints()
                    - uamm6CrsHitPoints() != 8)
                ++bad;
            if (uamm6DstHoofDamageHi()
                    - uamm6CrsHoofDamageHi()
                    != 2) ++bad;
        // ---- the ultimate
        // solution ----
            if (!uamm6UsoMinorOilAppearance())
                ++bad;
            if (!uamm6UsoSeemsSlipperinessAndDelusion())
                ++bad;
            if (!uamm6UsoDissolvesAdhesives())
                ++bad;
            if (!uamm6UsoNegatesSovereignGlue())
                ++bad;
            if (uamm6UsoCuFtPerOunce() != 1)
                ++bad;
            if (uamm6UsoContainerOunces() != 27)
                ++bad;
            if (!uamm6UsoDistillToThird()) ++bad;
            if (uamm6UsoDistilledOunces() != 9)
                ++bad;
            if (uamm6UsoDistilledCuFtPerOunce()
                    != 1) ++bad;
            if (uamm6UsoTransmutationSeamGarbles())
                ++bad;
            if (!uamm6UsoLivingNeedsToHit())
                ++bad;
            if (!uamm6UsoLivingSaveVsSpell())
                ++bad;
            if (!uamm6UsoInanimateAutomatic())
                ++bad;
            if (!uamm6UsoMagicItemsSaveVsDisintegrate())
                ++bad;
            // the distillation to a
            // third: 27 ounces down
            // to 9
            if (3 * uamm6UsoDistilledOunces()
                    != uamm6UsoContainerOunces())
                ++bad;
        // ---- the wind fan ----
            if (!uamm6WfaCoolingBreezeAppearance())
                ++bad;
            if (!uamm6WfaWordTriggersGust())
                ++bad;
            if (uamm6WfaCasterLevel() != 5) ++bad;
            if (!uamm6WfaOncePerDaySafe()) ++bad;
            if (uamm6WfaTearChancePctPerUse()
                    != 20) ++bad;
            if (!uamm6WfaTearsNonMagical())
                ++bad;
            // the cumulative 20%
            // reaches certainty at
            // the fifth extra usage
            if (5 * uamm6WfaTearChancePctPerUse()
                    != 100) ++bad;
        // ---- Zagyg's flowing
        // flagon ----
            if (!uamm6ZffNickelSilverVessel())
                ++bad;
            if (!uamm6ZffEngravedDrinkingScenes())
                ++bad;
            if (!uamm6ZffToastLineOnVessel())
                ++bad;
            if (!uamm6ZffFirstPickerReadsOnly())
                ++bad;
            if (!uamm6ZffOwnerOnlyUntilOwned())
                ++bad;
            if (!uamm6ZffReadToActivate()) ++bad;
            if (!uamm6ZffPhraseChangesEachUse())
                ++bad;
            if (uamm6ZffDraughtCount() != 6) ++bad;
            if (uamm6ZffFirstAlcoholPct() != 7)
                ++bad;
            if (uamm6ZffSecondAlcoholPct() != 10)
                ++bad;
            if (uamm6ZffThirdAlcoholPct() != 13)
                ++bad;
            if (uamm6ZffFourthAlcoholPct() != 20)
                ++bad;
            if (uamm6ZffFifthAlcoholPct() != 40)
                ++bad;
            if (uamm6ZffSixthAlcoholPct() != 80)
                ++bad;
            if (uamm6ZffPintOunces() != 16) ++bad;
            if (uamm6ZffNoticeUnlikelyPct() != 90)
                ++bad;
            if (uamm6ZffUsesPerDay() != 3) ++bad;
            // the wine ladder: two
            // steps of three, then
            // doubling to the top
            if (uamm6ZffSecondAlcoholPct()
                    - uamm6ZffFirstAlcoholPct()
                    != 3) ++bad;
            if (uamm6ZffThirdAlcoholPct()
                    - uamm6ZffSecondAlcoholPct()
                    != 3) ++bad;
            if (2 * uamm6ZffFourthAlcoholPct()
                    != uamm6ZffFifthAlcoholPct())
                ++bad;
            if (2 * uamm6ZffFifthAlcoholPct()
                    != uamm6ZffSixthAlcoholPct())
                ++bad;
            // the noticing chance is
            // the certain remainder
            if (100 - uamm6ZffNoticeUnlikelyPct()
                    != 10) ++bad;
        // ---- Zagyg's spell
        // component case ----
            if (!uamm6ZscBeltPouchAppearance())
                ++bad;
            if (!uamm6ZscFaintMagicAura()) ++bad;
            if (!uamm6ZscComponentsOnThought())
                ++bad;
            if (uamm6ZscVanishAfterRounds() != 1)
                ++bad;
            if (!uamm6ZscWastedIfUnused()) ++bad;
            if (!uamm6ZscVanishOnCasting()) ++bad;
            if (uamm6ZscTableRows() != 6) ++bad;
            if (uamm6ZscUsesLo() != 2) ++bad;
            if (uamm6ZscUsesHi() != 7) ++bad;
            if (uamm6ZscXpPerUse() != 100) ++bad;
            if (uamm6ZscGpPerUse() != 1000) ++bad;
            if (uamm6ZscGpTailGarbles()) ++bad;
            // the xp and gp values
            // ride the uses band:
            // 200 to 700 XP, 2,000
            // to 7,000 gp
            if (uamm6ZscXpPerUse()
                    * uamm6ZscUsesLo() != 200)
                ++bad;
            if (uamm6ZscXpPerUse()
                    * uamm6ZscUsesHi() != 700)
                ++bad;
            if (uamm6ZscGpPerUse()
                    * uamm6ZscUsesLo() != 2000)
                ++bad;
            if (uamm6ZscGpPerUse()
                    * uamm6ZscUsesHi() != 7000)
                ++bad;
            // the gp rate is ten
            // times the xp rate
            if (10 * uamm6ZscXpPerUse()
                    != uamm6ZscGpPerUse()) ++bad;
        // ---- the part ledger ----
            if (uamm6PartItemTotal() != 5) ++bad;
            if (uamm6PartCleanCount() != 5) ++bad;
            if (uamm6PartFlaggedCount() != 0)
                ++bad;
            if (uamm6PartGarbledCount() != 0)
                ++bad;
            if (uamm6PartCleanCount()
                    + uamm6PartFlaggedCount()
                    + uamm6PartGarbledCount()
                    != uamm6PartItemTotal()) ++bad;
        // ---- the R385 part-5 seam ----
            if (uamm5PartItemTotal() != 11) ++bad;
            if (uamm5PartCleanCount() != 11) ++bad;
            if (uamm5PartFlaggedCount() != 0)
                ++bad;
            if (uamm5PartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (uadsRowBodiesGarble()) ++bad;
        printf("R386 UA misc magic prose part 6 pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
