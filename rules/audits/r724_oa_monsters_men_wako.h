    // ---- R724 OA monsters Men Wako audit ----
    // OA round one hundred eleven (capture pp. 275-276): the Chapter 12
    // monster roster - the men wako, the stat block and the sea raider
    // description riding together with the six-row arms table, single-pass
    // pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dklWakoCount() != 6
            || dklAppearMin() != 30
            || dklAppearMax() != 180
            || dklMove() != 12
            || dklHD() != 1
            || dklHPMin() != 2
            || dklHPMax() != 7
            || dklLairPct() != 100
            || dklAttackCount() != 1
            || dklHitPlus() != 2
            || dklDmgPlus() != 1
            || dklBushiLevel() != 5
            || dklBushiPer() != 30
            || dklBarbarianLevel() != 7
            || dklBarbarianPer() != 60
            || dklSamuraiLevel() != 10
            || dklLieutenantLevel() != 8
            || dklMatesMin() != 1
            || dklMatesMax() != 3
            || dklMateLevel() != 6
            || dklWuJenChancePct() != 5
            || dklWuJenPer() != 30
            || dklWuJenLevelMin() != 6
            || dklWuJenLevelMax() != 9
            || dklXPBase() != 14
            || dklXPPerHP() != 1
            || !dklFrequencyUncommon()
            || !dklACSeeBelow()
            || !dklTreasureA()
            || !dklDamageByWeapon()
            || !dklSpecialAttacksLeaderTypes()
            || !dklSpecialDefensesLeaderTypes()
            || !dklMRStandard()
            || !dklIntelligenceAvgToVery()
            || !dklAlignmentLawfulEvil()
            || !dklSizeMedium()
            || !dklPsionicLeaderTypes()
            || !dklModesLeaderTypes()
            || !dklPlyTheWarmSeas()
            || !dklFearedScourge()
            || !dklLowClassOrigins()
            || !dklWesternPirateFear()
            || !dklDisregardForDeath()
            || !dklFightToLastMan()
            || !dklNoPrisonersButWomen()
            || !dklUtterlyFerocious()
            || !dklLeadersInAdditionToDice()
            || !dklAlwaysSamuraiLed()
            || !dklLeadersWearOYoroi()
            || !dklLairPermanentSettlement()
            || !dklLairOnSponsorLands()
            || !dklLairWalledPatrolled()
        )
            ++bad;
        // the dklArms grid
        int CArms[6][1] = {
            {50},
            {10},
            {15},
            {10},
            {5},
            {10},
            };
        int nArms[1] = {0};
        int eArms[1] = {0};
        for (int b = 0;
             b < dklWakoCount();
             ++b) {
            int vals[1];
            vals[0] = dklArmsPct(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CArms[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nArms[c];
            }
        }
        for (int c = 0; c < 1; ++c)
            if (nArms[c] != eArms[c])
                ++bad;
        // the stat block - the stat block pins, healthy values, each
        // condition false
    if (dklFrequencyUncommon() != 1
            || dklAppearMin() != 30
            || dklAppearMax() != 180
            || dklACSeeBelow() != 1
            || dklMove() != 12
            || dklHD() != 1
            || dklHPMin() != 2
            || dklHPMax() != 7
            || dklLairPct() != 100
            || dklTreasureA() != 1
            || dklAttackCount() != 1
            || dklDamageByWeapon() != 1
            || dklSpecialAttacksLeaderTypes() != 1
            || dklSpecialDefensesLeaderTypes() != 1
            || dklMRStandard() != 1
            || dklIntelligenceAvgToVery() != 1
            || dklAlignmentLawfulEvil() != 1
            || dklSizeMedium() != 1
            || dklPsionicLeaderTypes() != 1
            || dklModesLeaderTypes() != 1
        )
            ++bad;
        // the xp line - the 1/14 + 1 per hp, healthy values, each condition
        // false
    if (dklXPBase() != 14
            || dklXPPerHP() != 1
        )
            ++bad;
        // the sea raiders - the trade and the reputation, healthy values,
        // each condition false
    if (dklPlyTheWarmSeas() != 1
            || dklFearedScourge() != 1
            || dklLowClassOrigins() != 1
            || dklWesternPirateFear() != 1
        )
            ++bad;
        // the ferocity - the death disregard and the fight bonuses, healthy
        // values, each condition false
    if (dklDisregardForDeath() != 1
            || dklFightToLastMan() != 1
            || dklNoPrisonersButWomen() != 1
            || dklUtterlyFerocious() != 1
            || dklHitPlus() != 2
            || dklDmgPlus() != 1
        )
            ++bad;
        // the leaders - the bushi and barbarian rates and the command staff,
        // healthy values, each condition false
    if (dklBushiLevel() != 5
            || dklBushiPer() != 30
            || dklBarbarianLevel() != 7
            || dklBarbarianPer() != 60
            || dklLeadersInAdditionToDice() != 1
            || dklAlwaysSamuraiLed() != 1
            || dklSamuraiLevel() != 10
            || dklLieutenantLevel() != 8
            || dklMatesMin() != 1
            || dklMatesMax() != 3
            || dklMateLevel() != 6
            || dklWuJenChancePct() != 5
            || dklWuJenPer() != 30
            || dklWuJenLevelMin() != 6
            || dklWuJenLevelMax() != 9
        )
            ++bad;
        // the arms table - the six-row arms table, audited cell by cell by
        // the table audit
    if (dklWakoCount() != 6
            || dklLeadersWearOYoroi() != 1
        )
            ++bad;
        // the lair - the settlement and its defense, healthy values, each
        // condition false
    if (dklLairPermanentSettlement() != 1
            || dklLairOnSponsorLands() != 1
            || dklLairWalledPatrolled() != 1
        )
            ++bad;
        printf("R724 OA monsters Men Wako audit: bad %d\n", bad);
        if (bad) return 1;
    }
