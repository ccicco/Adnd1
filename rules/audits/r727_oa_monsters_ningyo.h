    // ---- R727 OA monsters Ningyo audit ----
    // OA round one hundred fourteen (capture pp. 279-280): the Chapter 12
    // monster roster - the ningyo, the stat block and the sea folk
    // description riding together, the xp ladder as consts per the R723
    // pattern, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkoAppearMin() != 2
            || dkoAppearMax() != 20
            || dkoAC() != 7
            || dkoMove() != 18
            || dkoHDMin() != 2
            || dkoHDMax() != 5
            || dkoLairPct() != 30
            || dkoAttackCount() != 1
            || dkoXP2Base() != 73
            || dkoXP2PerHP() != 2
            || dkoXP3Base() != 105
            || dkoXP3PerHP() != 3
            || dkoXP4Base() != 150
            || dkoXP4PerHP() != 4
            || dkoXP5Base() != 205
            || dkoXP5PerHP() != 5
            || dkoSurfaceLossPerRound() != 1
            || !dkoFrequencyRare()
            || !dkoTreasureI()
            || !dkoDamageByWeapon()
            || !dkoSpecialAttacksSpells()
            || !dkoSpecialDefensesSpells()
            || !dkoMRStandard()
            || !dkoIntVery()
            || !dkoAlignmentChaoticGood()
            || !dkoPsionicNil()
            || !dkoModesNil()
            || !dkoMermanRelative()
            || !dkoFlamingRedHair()
            || !dkoDwellUnderWaves()
            || !dkoServeTheSeaLord()
            || !dkoKindlyHelpful()
            || !dkoSailorsProtectors()
            || !dkoNormallyUnarmed()
            || !dkoArmedTridentOrSpear()
            || !dkoPeacefulNonCombative()
            || !dkoFightIfForced()
            || !dkoSpellcastingShukenjaWuJen()
            || !dkoNoUnderseaCommunities()
            || !dkoRoamWithCurrents()
            || !dkoCannotSurviveOutOfWater()
            || !dkoSpeakThreeLanguages()
        )
            ++bad;
        // the stat block - the stat block pins, healthy values, each
        // condition false
    if (dkoFrequencyRare() != 1
            || dkoAppearMin() != 2
            || dkoAppearMax() != 20
            || dkoAC() != 7
            || dkoMove() != 18
            || dkoHDMin() != 2
            || dkoHDMax() != 5
            || dkoLairPct() != 30
            || dkoTreasureI() != 1
            || dkoAttackCount() != 1
            || dkoDamageByWeapon() != 1
            || dkoSpecialAttacksSpells() != 1
            || dkoSpecialDefensesSpells() != 1
            || dkoMRStandard() != 1
            || dkoIntVery() != 1
            || dkoAlignmentChaoticGood() != 1
            || dkoPsionicNil() != 1
            || dkoModesNil() != 1
        )
            ++bad;
        // the xp ladder - the four-step xp ladder, healthy values, each
        // condition false
    if (dkoXP2Base() != 73
            || dkoXP2PerHP() != 2
            || dkoXP3Base() != 105
            || dkoXP3PerHP() != 3
            || dkoXP4Base() != 150
            || dkoXP4PerHP() != 4
            || dkoXP5Base() != 205
            || dkoXP5PerHP() != 5
        )
            ++bad;
        // the sea folk - the merman kin and the Sea Lord allegiance, healthy
        // values, each condition false
    if (dkoMermanRelative() != 1
            || dkoFlamingRedHair() != 1
            || dkoDwellUnderWaves() != 1
            || dkoServeTheSeaLord() != 1
            || dkoKindlyHelpful() != 1
            || dkoSailorsProtectors() != 1
        )
            ++bad;
        // the bearing - the arms and the spellcasting, healthy values, each
        // condition false
    if (dkoNormallyUnarmed() != 1
            || dkoArmedTridentOrSpear() != 1
            || dkoPeacefulNonCombative() != 1
            || dkoFightIfForced() != 1
            || dkoSpellcastingShukenjaWuJen() != 1
        )
            ++bad;
        // the life - the roaming and the water need, healthy values, each
        // condition false
    if (dkoNoUnderseaCommunities() != 1
            || dkoRoamWithCurrents() != 1
            || dkoCannotSurviveOutOfWater() != 1
            || dkoSurfaceLossPerRound() != 1
            || dkoSpeakThreeLanguages() != 1
        )
            ++bad;
        printf("R727 OA monsters Ningyo audit: bad %d\n", bad);
        if (bad) return 1;
    }
