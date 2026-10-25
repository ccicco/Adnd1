    // ---- R722 OA monsters Kappa audit ----
    // OA round one hundred nine (capture pp. 273-274): the Chapter 12 monster
    // roster - the kappa, the paired Common and Vampiric stat table riding
    // one flip, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkjKappaCount() != 2
            || dkjStrength() != 18
            || dkjToHitBonus() != 3
            || dkjManeuverDice() != 1
            || dkjManeuverSides() != 6
            || dkjDrainPerRound() != 1
            || dkjDiseaseChancePct() != 50
            || dkjDiseaseMinPerDay() != 1
            || dkjDiseaseMaxPerDay() != 3
            || dkjRecoveryMinPerDay() != 2
            || dkjRecoveryMaxPerDay() != 5
            || dkjRegenPerRound() != 1
            || dkjDehydratePerRound() != 2
            || dkjHeightFeet() != 2
            || dkjCommonXPBase() != 135
            || dkjCommonXPPerHP() != 4
            || dkjVampXPBase() != 1000
            || dkjVampXPPerHP() != 10
            || !dkjFrequencyRare()
            || !dkjVampFrequencyVeryRare()
            || !dkjTreasureTypeD()
            || !dkjSpecialAttackNil()
            || !dkjVampStrengthDrain()
            || !dkjSpecialDefenseRegeneration()
            || !dkjMagicResistStandard()
            || !dkjIntelligenceLowToAverage()
            || !dkjVampIntelligenceAverage()
            || !dkjAlignmentChaoticEvil()
            || !dkjSizeSmall()
            || !dkjPsionicNil()
            || !dkjCommonLevelIII()
            || !dkjVampLevelVI()
            || !dkjAmphibiousHumanoids()
            || !dkjFreshWaterHabitat()
            || !dkjBoyProportions()
            || !dkjTortoiseShell()
            || !dkjConcaveBowlHead()
            || !dkjVampRedGlowingEyes()
            || !dkjMartialArtsMasters()
            || !dkjClawedHands()
            || !dkjVampBiteAttack()
            || !dkjVampRetainsGrip()
            || !dkjGripNoFurtherDamage()
            || !dkjGripBrokenBySlaying()
            || !dkjGripBrokenByEmptyBowl()
            || !dkjGripBrokenByBendBars()
            || !dkjSlainAtZeroStrength()
            || !dkjBiteDisease()
            || !dkjDiseaseDrainsUntilCured()
            || !dkjDiseaseRecoveredByRest()
            || !dkjPowerFromWater()
            || !dkjBowlFilledFromLair()
            || !dkjPowersWhileFilled()
            || !dkjLosesPowersWhenEmptied()
            || !dkjEmptyStrengthNormal()
            || !dkjEmptyLosesRegeneration()
            || !dkjEmptyLosesHPPerRound()
            || !dkjTrickedByBowing()
            || !dkjCleverAboutBowTrick()
            || !dkjSpillByBendBars()
            || !dkjSpillByThrowManeuver()
            || !dkjAgilityPreventsSpillage()
            || !dkjImmuneToWaterSpells()
            || !dkjLairsUnderRocksAndBridges()
            || !dkjWaylaysLoneTravelers()
            || !dkjFondOfHorseflesh()
            || !dkjFondOfMelonsAndCucumbers()
            || !dkjOfferingsBeforeCrossing()
        )
            ++bad;
        // the dkjKappa grid
        int CKappa[2][9] = {
            {1,6,3,6,4,70,2,5,10},
            {1,2,0,9,7,80,3,5,10},
            };
        int nKappa[9] = {0,0,0,0,0,0,0,0,0};
        int eKappa[9] = {0,0,1,0,0,0,0,0,0};
        for (int b = 0;
             b < dkjKappaCount();
             ++b) {
            int vals[9];
            vals[0] = dkjKappaAppearMin(b);
            vals[1] = dkjKappaAppearMax(b);
            vals[2] = dkjKappaFrontAC(b);
            vals[3] = dkjKappaMove(b);
            vals[4] = dkjKappaHD(b);
            vals[5] = dkjKappaLairPct(b);
            vals[6] = dkjKappaAttacks(b);
            vals[7] = dkjKappaClawMin(b);
            vals[8] = dkjKappaClawMax(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CKappa[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nKappa[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (nKappa[c] != eKappa[c])
                ++bad;
        // the stat table - the paired stat columns, audited cell by cell by
        // the table audit
    if (dkjKappaCount() != 2
        )
            ++bad;
        // the shared stat lines - the column lines, healthy values, each
        // condition false
    if (dkjFrequencyRare() != 1
            || dkjVampFrequencyVeryRare() != 1
            || dkjTreasureTypeD() != 1
            || dkjSpecialAttackNil() != 1
            || dkjVampStrengthDrain() != 1
            || dkjSpecialDefenseRegeneration() != 1
            || dkjMagicResistStandard() != 1
            || dkjIntelligenceLowToAverage() != 1
            || dkjVampIntelligenceAverage() != 1
            || dkjAlignmentChaoticEvil() != 1
            || dkjSizeSmall() != 1
            || dkjPsionicNil() != 1
            || dkjCommonLevelIII() != 1
            || dkjCommonXPBase() != 135
            || dkjCommonXPPerHP() != 4
            || dkjVampLevelVI() != 1
            || dkjVampXPBase() != 1000
            || dkjVampXPPerHP() != 10
        )
            ++bad;
        // the water sprite - the bowl-headed sprite, healthy values, each
        // condition false
    if (dkjAmphibiousHumanoids() != 1
            || dkjFreshWaterHabitat() != 1
            || dkjHeightFeet() != 2
            || dkjBoyProportions() != 1
            || dkjTortoiseShell() != 1
            || dkjConcaveBowlHead() != 1
            || dkjVampRedGlowingEyes() != 1
        )
            ++bad;
        // the strength and the arts - the 18/00 strength and the maneuvers,
        // healthy values, each condition false
    if (dkjStrength() != 18
            || dkjToHitBonus() != 3
            || dkjMartialArtsMasters() != 1
            || dkjManeuverDice() != 1
            || dkjManeuverSides() != 6
            || dkjClawedHands() != 1
            || dkjVampBiteAttack() != 1
        )
            ++bad;
        // the vampiric grip - the bite grip and the disease, healthy values,
        // each condition false
    if (dkjVampRetainsGrip() != 1
            || dkjGripNoFurtherDamage() != 1
            || dkjDrainPerRound() != 1
            || dkjGripBrokenBySlaying() != 1
            || dkjGripBrokenByEmptyBowl() != 1
            || dkjGripBrokenByBendBars() != 1
            || dkjSlainAtZeroStrength() != 1
            || dkjBiteDisease() != 1
            || dkjDiseaseChancePct() != 50
            || dkjDiseaseMinPerDay() != 1
            || dkjDiseaseMaxPerDay() != 3
            || dkjDiseaseDrainsUntilCured() != 1
            || dkjDiseaseRecoveredByRest() != 1
            || dkjRecoveryMinPerDay() != 2
            || dkjRecoveryMaxPerDay() != 5
        )
            ++bad;
        // the bowl and the water - the power source and the spill, healthy
        // values, each condition false
    if (dkjPowerFromWater() != 1
            || dkjBowlFilledFromLair() != 1
            || dkjPowersWhileFilled() != 1
            || dkjLosesPowersWhenEmptied() != 1
            || dkjEmptyStrengthNormal() != 1
            || dkjEmptyLosesRegeneration() != 1
            || dkjEmptyLosesHPPerRound() != 1
            || dkjDehydratePerRound() != 2
            || dkjTrickedByBowing() != 1
            || dkjCleverAboutBowTrick() != 1
            || dkjSpillByBendBars() != 1
            || dkjSpillByThrowManeuver() != 1
            || dkjAgilityPreventsSpillage() != 1
            || dkjImmuneToWaterSpells() != 1
        )
            ++bad;
        // the lair and the cravings - the bridges and the cucumbers, healthy
        // values, each condition false
    if (dkjLairsUnderRocksAndBridges() != 1
            || dkjWaylaysLoneTravelers() != 1
            || dkjFondOfHorseflesh() != 1
            || dkjFondOfMelonsAndCucumbers() != 1
            || dkjOfferingsBeforeCrossing() != 1
        )
            ++bad;
        // the regeneration - the 1-per-round regeneration, healthy value, the
        // condition false
    if (dkjRegenPerRound() != 1
        )
            ++bad;
        printf("R722 OA monsters Kappa audit: bad %d\n", bad);
        if (bad) return 1;
    }
