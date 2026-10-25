    // ---- R723 OA monsters Kuei audit ----
    // OA round one hundred ten (capture pp. 274-275): the Chapter 12 monster
    // roster - the kuei, the stat block and the description riding together
    // with the four-row powers table, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkkKueiCount() != 4
            || dkkAppear() != 1
            || dkkAC() != -4
            || dkkMove() != 18
            || dkkHDMin() != 3
            || dkkHDMax() != 6
            || dkkAttackCount() != 1
            || dkkMRPct() != 10
            || dkkPossessPerDay() != 3
            || dkkXP3Base() != 180
            || dkkXP3PerHP() != 3
            || dkkXP4Base() != 275
            || dkkXP4PerHP() != 4
            || dkkXP5Base() != 405
            || dkkXP5PerHP() != 5
            || dkkXP6Base() != 725
            || dkkXP6PerHP() != 6
            || dkkMagicalFireColdMult() != 2
            || !dkkFrequencyRare()
            || !dkkLairNil()
            || !dkkTreasureNil()
            || !dkkSpecialAttackPossession()
            || !dkkSpecialDefensesSeeBelow()
            || !dkkIntelligenceAvgToVery()
            || !dkkAlignmentSeeBelow()
            || !dkkSizeMedium()
            || !dkkPsionicNil()
            || !dkkModesSeeBelow()
            || !dkkSpiritOfTheDead()
            || !dkkDiesUnburied()
            || !dkkDiesUnfulfilled()
            || !dkkDiesViolenceUnavenged()
            || !dkkAppearsAsInLife()
            || !dkkCannotBeTouched()
            || !dkkUnaffectedBySunlight()
            || !dkkMostActiveAtNight()
            || !dkkAlignmentByTask()
            || !dkkPowersByHitDice()
            || !dkkEtherealAtWill()
            || !dkkPossessAsPerSpell()
            || !dkkImmuneToESP()
            || !dkkImmuneToCharmEnchantIllusionWater()
            || !dkkImmuneToPsionicAttack()
            || !dkkNoNormalFireColdDamage()
            || !dkkHalfMagicalFireCold()
            || !dkkAttemptsPossessionFirst()
            || !dkkFormDisappearsOnPossession()
            || !dkkUsesBodyForTask()
            || !dkkTaskVengeance()
            || !dkkTaskFulfillOath()
            || !dkkTaskTempleCeremonies()
            || !dkkLongPossessionPossible()
            || !dkkSisterMarriageStory()
            || !dkkBreakByVictimDeath()
            || !dkkBreakByTaskFulfilled()
            || !dkkBreakByExorcism()
            || !dkkVictimRemembersNothing()
        )
            ++bad;
        // the dkkPowers grid
        int CPowers[4][3] = {
            {1,1,6},
            {2,1,8},
            {3,1,10},
            {4,1,12},
            };
        int nPowers[3] = {0,0,0};
        int ePowers[3] = {0,0,0};
        for (int b = 0;
             b < dkkKueiCount();
             ++b) {
            int vals[3];
            vals[0] = dkkPowersWeaponPlus(b);
            vals[1] = dkkPowersDmgMin(b);
            vals[2] = dkkPowersDmgMax(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CPowers[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nPowers[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nPowers[c] != ePowers[c])
                ++bad;
        // the stat block - the stat block pins, healthy values, each
        // condition false
    if (dkkFrequencyRare() != 1
            || dkkAppear() != 1
            || dkkAC() != -4
            || dkkMove() != 18
            || dkkHDMin() != 3
            || dkkHDMax() != 6
            || dkkLairNil() != 1
            || dkkTreasureNil() != 1
            || dkkAttackCount() != 1
            || dkkSpecialAttackPossession() != 1
            || dkkSpecialDefensesSeeBelow() != 1
            || dkkMRPct() != 10
            || dkkIntelligenceAvgToVery() != 1
            || dkkAlignmentSeeBelow() != 1
            || dkkSizeMedium() != 1
            || dkkPsionicNil() != 1
            || dkkModesSeeBelow() != 1
        )
            ++bad;
        // the xp ladder - the four-step xp ladder, healthy values, each
        // condition false
    if (dkkXP3Base() != 180
            || dkkXP3PerHP() != 3
            || dkkXP4Base() != 275
            || dkkXP4PerHP() != 4
            || dkkXP5Base() != 405
            || dkkXP5PerHP() != 5
            || dkkXP6Base() != 725
            || dkkXP6PerHP() != 6
        )
            ++bad;
        // the demon ghost - the three origins and the night clause, healthy
        // values, each condition false
    if (dkkSpiritOfTheDead() != 1
            || dkkDiesUnburied() != 1
            || dkkDiesUnfulfilled() != 1
            || dkkDiesViolenceUnavenged() != 1
            || dkkAppearsAsInLife() != 1
            || dkkCannotBeTouched() != 1
            || dkkUnaffectedBySunlight() != 1
            || dkkMostActiveAtNight() != 1
            || dkkAlignmentByTask() != 1
        )
            ++bad;
        // the powers table - the HD ladder table, audited cell by cell by the
        // table audit
    if (dkkKueiCount() != 4
            || dkkPowersByHitDice() != 1
        )
            ++bad;
        // the immunities - the ethereal power and the immunity roster,
        // healthy values, each condition false
    if (dkkEtherealAtWill() != 1
            || dkkPossessAsPerSpell() != 1
            || dkkPossessPerDay() != 3
            || dkkImmuneToESP() != 1
            || dkkImmuneToCharmEnchantIllusionWater() != 1
            || dkkImmuneToPsionicAttack() != 1
            || dkkNoNormalFireColdDamage() != 1
            || dkkHalfMagicalFireCold() != 1
            || dkkMagicalFireColdMult() != 2
        )
            ++bad;
        // the possession - the takeover and the three releases, healthy
        // values, each condition false
    if (dkkAttemptsPossessionFirst() != 1
            || dkkFormDisappearsOnPossession() != 1
            || dkkUsesBodyForTask() != 1
            || dkkTaskVengeance() != 1
            || dkkTaskFulfillOath() != 1
            || dkkTaskTempleCeremonies() != 1
            || dkkLongPossessionPossible() != 1
            || dkkSisterMarriageStory() != 1
            || dkkBreakByVictimDeath() != 1
            || dkkBreakByTaskFulfilled() != 1
            || dkkBreakByExorcism() != 1
            || dkkVictimRemembersNothing() != 1
        )
            ++bad;
        printf("R723 OA monsters Kuei audit: bad %d\n", bad);
        if (bad) return 1;
    }
