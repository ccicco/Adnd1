    // ---- R718 OA monsters Hai Nu audit ----
    // OA round one hundred five (capture pp. 268-269): the Chapter 12 monster
    // roster - the hai nu, the stat block and the description riding together
    // with the four-row arms table, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkfArmsCount() != 4
            || dkfAppearMin() != 4
            || dkfAppearMax() != 40
            || dkfAC() != 7
            || dkfMoveWalk() != 6
            || dkfMoveSwim() != 15
            || dkfHDMin() != 1
            || dkfHDMax() != 4
            || dkfLairPct() != 30
            || dkfAttackCount() != 1
            || dkfXP1Base() != 14
            || dkfXP1PerHP() != 1
            || dkfXP2Base() != 28
            || dkfXP2PerHP() != 2
            || dkfXP3Base() != 50
            || dkfXP3PerHP() != 3
            || dkfXP4Base() != 85
            || dkfXP4PerHP() != 4
            || dkfFemalePct() != 75
            || dkfMatronHD() != 6
            || dkfMatronAC() != 5
            || dkfSharkDice() != 2
            || dkfSharkSides() != 6
            || dkfEscortPct() != 40
            || dkfEscortDice() != 3
            || dkfEscortSides() != 4
            || dkfOutOfWaterDmgPerRound() != 1
            || dkfFireDamageMult() != 2
            || dkfColdBonusPerDie() != 1
            || !dkfFrequencyRare()
            || !dkfTreasureTypeU()
            || !dkfDamageByWeaponType()
            || !dkfSpecialAttacksNil()
            || !dkfImmuneToWaterAttacks()
            || !dkfMagicResistStandard()
            || !dkfIntelligenceAvgToHigh()
            || !dkfAlignmentLawfulNeutral()
            || !dkfSizeMedium()
            || !dkfPsionicNil()
            || !dkfAquaticRace()
            || !dkfWebbedHandsAndFeet()
            || !dkfShimmeringFur()
            || !dkfWarmShallowSeas()
            || !dkfGathersFish()
            || !dkfAttendsSeaLordCourt()
            || !dkfSpeaksOnlyOwnAndCourt()
            || !dkfLairSunkenShipsAndKelp()
            || !dkfLovesBrightTreasures()
            || !dkfSocietyMatriarchal()
            || !dkfMatronLeadsCommunity()
            || !dkfTamedSharkGuards()
            || !dkfGoodRelationsSeaCreatures()
            || !dkfSeldomAttackVessels()
            || !dkfPeacefulAndFriendly()
            || !dkfDefendsHuntingGrounds()
            || !dkfCutsFishermenLines()
            || !dkfPetitionsSeaLord()
            || !dkfCannotLongSurviveOutOfWater()
            || !dkfImmuneToAllWaterForms()
        )
            ++bad;
        // the dkfArms grid
        int CArms[4][1] = {
            {20},
            {50},
            {20},
            {10},
            };
        int nArms[1] = {0};
        int eArms[1] = {0};
        for (int b = 0;
             b < dkfArmsCount();
             ++b) {
            int vals[1];
            vals[0] = dkfArmsPct(b);
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
    if (dkfAppearMin() != 4
            || dkfAppearMax() != 40
            || dkfAC() != 7
            || dkfMoveWalk() != 6
            || dkfMoveSwim() != 15
            || dkfHDMin() != 1
            || dkfHDMax() != 4
            || dkfLairPct() != 30
            || dkfFrequencyRare() != 1
            || dkfTreasureTypeU() != 1
            || dkfAttackCount() != 1
            || dkfDamageByWeaponType() != 1
            || dkfSpecialAttacksNil() != 1
            || dkfImmuneToWaterAttacks() != 1
            || dkfMagicResistStandard() != 1
            || dkfIntelligenceAvgToHigh() != 1
            || dkfAlignmentLawfulNeutral() != 1
            || dkfSizeMedium() != 1
            || dkfPsionicNil() != 1
        )
            ++bad;
        // the xp ladder - the four-step xp ladder, healthy values, each
        // condition false
    if (dkfXP1Base() != 14
            || dkfXP1PerHP() != 1
            || dkfXP2Base() != 28
            || dkfXP2PerHP() != 2
            || dkfXP3Base() != 50
            || dkfXP3PerHP() != 3
            || dkfXP4Base() != 85
            || dkfXP4PerHP() != 4
        )
            ++bad;
        // the aquatic servitor - the sea race and the court, healthy values,
        // each condition false
    if (dkfAquaticRace() != 1
            || dkfWebbedHandsAndFeet() != 1
            || dkfShimmeringFur() != 1
            || dkfWarmShallowSeas() != 1
            || dkfGathersFish() != 1
            || dkfAttendsSeaLordCourt() != 1
            || dkfSpeaksOnlyOwnAndCourt() != 1
        )
            ++bad;
        // the matriarchal community - the matron, the guards, and the escort,
        // healthy values, each condition false
    if (dkfLairSunkenShipsAndKelp() != 1
            || dkfLovesBrightTreasures() != 1
            || dkfSocietyMatriarchal() != 1
            || dkfFemalePct() != 75
            || dkfMatronHD() != 6
            || dkfMatronAC() != 5
            || dkfMatronLeadsCommunity() != 1
            || dkfTamedSharkGuards() != 1
            || dkfSharkDice() != 2
            || dkfSharkSides() != 6
            || dkfGoodRelationsSeaCreatures() != 1
            || dkfEscortPct() != 40
            || dkfEscortDice() != 3
            || dkfEscortSides() != 4
        )
            ++bad;
        // the arms table - the arms table rows, audited cell by cell by the
        // table audit
    if (dkfArmsCount() != 4
        )
            ++bad;
        // the fisherman feud - the peaceful defense, healthy values, each
        // condition false
    if (dkfSeldomAttackVessels() != 1
            || dkfPeacefulAndFriendly() != 1
            || dkfDefendsHuntingGrounds() != 1
            || dkfCutsFishermenLines() != 1
            || dkfPetitionsSeaLord() != 1
        )
            ++bad;
        // the element vulnerabilities - the water need and the fire and cold
        // edges, healthy values, each condition false
    if (dkfCannotLongSurviveOutOfWater() != 1
            || dkfOutOfWaterDmgPerRound() != 1
            || dkfFireDamageMult() != 2
            || dkfColdBonusPerDie() != 1
            || dkfImmuneToAllWaterForms() != 1
        )
            ++bad;
        printf("R718 OA monsters Hai Nu audit: bad %d\n", bad);
        if (bad) return 1;
    }
