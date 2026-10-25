    // ---- R732 OA monsters Tengu audit ----
    // OA round one hundred nineteen (capture pp. 284-285): the Chapter 12
    // monster roster - the tengu, the paired stat grid and the two xp ladders
    // riding together with the crow and humanoid descriptions, the capture
    // misreads pinned against the print, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dktTenguCount() != 2
            || dktCrowXPCount() != 4
            || dktHumXPCount() != 6
            || dktPolymorphPerDay() != 3
            || dktManeuverCountMin() != 2
            || dktManeuverCountMax() != 5
            || dktKensaiTutorMonthsMin() != 1
            || dktKensaiTutorMonthsMax() != 3
            || dktKensaiTutorXP() != 1000
            || !dktCrowRare()
            || !dktHumRare()
            || !dktMCC()
            || !dktTreasureC()
            || !dktCrowSpecialAttacksSpells()
            || !dktHumSpecialAttacksSpells()
            || !dktCrowDefensesNil()
            || !dktHumInvisibility()
            || !dktMRStandard()
            || !dktCrowIntLowToAverage()
            || !dktHumIntHighToVery()
            || !dktCrowChaoticEvil()
            || !dktHumChaoticNeutral()
            || !dktSizeSmall()
            || !dktPsionicNil()
            || !dktModesNil()
            || !dktHumMoveHalf()
            || !dktHumDamageByWeapon()
            || !dktBirdlikeHumanoids()
            || !dktOriginalInhabitants()
            || !dktPushedIntoMountains()
            || !dktGladesAndBanks()
            || !dktNoVillages()
            || !dktTwoTypes()
            || !dktCrowTwoToThreeFeet()
            || !dktCrowFeatheredWings()
            || !dktCrowEvilMalicious()
            || !dktCrowKatanaWakizashi()
            || !dktCrowSpeaksThree()
            || !dktCrowPerfectMimicry()
            || !dktCrowPolymorphAndShout()
            || !dktCrowLowerStatus()
            || !dktHumThreeToFourFeet()
            || !dktHumLongNoses()
            || !dktHumStuntedWings()
            || !dktHumThricePowers()
            || !dktHumInvisibleAtWill()
            || !dktHumWeeklyPowers()
            || !dktHumMisdirectionPerTurn()
            || !dktHumGhostLightPerRound()
            || !dktHumPerfectMimicry()
            || !dktHumSpeaksThree()
            || !dktHumShukenjaAndKensai()
            || !dktHumOneMartialStyle()
            || !dktHumFeatherFan()
            || !dktHumFanAsKatana()
            || !dktHumFanWindAndGrowth()
            || !dktHumCruelTricks()
            || !dktHumLikesSwordSpecialists()
            || !dktHumTutorsKensai()
            || !dktSecretiveCapricious()
            || !dktLittleKnown()
            || !dktFondOfSake()
            || !dktTasteForMusic()
        )
            ++bad;
        // the dktTengu grid
        int CTengu[2][11] = {
            {1,4,6,9,24,2,5,10,1,1,8},
            {1,3,4,12,15,5,10,20,2,1,6},
            };
        int nTengu[11] = {0,0,0,0,0,0,0,0,0,0,0};
        int eTengu[11] = {0,0,0,0,0,0,0,0,0,0,0};
        for (int b = 0;
             b < dktTenguCount();
             ++b) {
            int vals[11];
            vals[0] = dktTenguAppearMin(b);
            vals[1] = dktTenguAppearMax(b);
            vals[2] = dktTenguAC(b);
            vals[3] = dktTenguMoveGround(b);
            vals[4] = dktTenguMoveFly(b);
            vals[5] = dktTenguHDMin(b);
            vals[6] = dktTenguHDMax(b);
            vals[7] = dktTenguLairPct(b);
            vals[8] = dktTenguAttacks(b);
            vals[9] = dktTenguDmgMin(b);
            vals[10] = dktTenguDmgMax(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CTengu[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nTengu[c];
            }
        }
        for (int c = 0; c < 11; ++c)
            if (nTengu[c] != eTengu[c])
                ++bad;
        // the dktXPCrow grid
        int CXPCrow[4][2] = {
            {28,2},
            {50,3},
            {85,4},
            {130,5},
            };
        int nXPCrow[2] = {0,0};
        int eXPCrow[2] = {0,0};
        for (int b = 0;
             b < dktCrowXPCount();
             ++b) {
            int vals[2];
            vals[0] = dktXPCrowBase(b);
            vals[1] = dktXPCrowPerHP(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CXPCrow[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nXPCrow[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nXPCrow[c] != eXPCrow[c])
                ++bad;
        // the dktXPHum grid
        int CXPHum[6][2] = {
            {360,5},
            {625,6},
            {950,8},
            {1450,10},
            {2300,12},
            {3450,14},
            };
        int nXPHum[2] = {0,0};
        int eXPHum[2] = {0,0};
        for (int b = 0;
             b < dktHumXPCount();
             ++b) {
            int vals[2];
            vals[0] = dktXPHumBase(b);
            vals[1] = dktXPHumPerHP(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CXPHum[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nXPHum[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nXPHum[c] != eXPHum[c])
                ++bad;
        // the stat grid - the per-column lines, healthy values, each
        // condition false
    if (dktCrowRare() != 1
            || dktHumRare() != 1
            || dktMCC() != 1
            || dktTreasureC() != 1
            || dktCrowSpecialAttacksSpells() != 1
            || dktHumSpecialAttacksSpells() != 1
            || dktCrowDefensesNil() != 1
            || dktHumInvisibility() != 1
            || dktMRStandard() != 1
            || dktCrowIntLowToAverage() != 1
            || dktHumIntHighToVery() != 1
            || dktCrowChaoticEvil() != 1
            || dktHumChaoticNeutral() != 1
            || dktSizeSmall() != 1
            || dktPsionicNil() != 1
            || dktModesNil() != 1
            || dktHumMoveHalf() != 1
            || dktHumDamageByWeapon() != 1
        )
            ++bad;
        // the grids - the paired stat table and the two xp ladders, audited
        // cell by cell by the table audit
    if (dktTenguCount() != 2
            || dktCrowXPCount() != 4
            || dktHumXPCount() != 6
        )
            ++bad;
        // the race - the mountain dwellers, healthy values, each condition
        // false
    if (dktBirdlikeHumanoids() != 1
            || dktOriginalInhabitants() != 1
            || dktPushedIntoMountains() != 1
            || dktGladesAndBanks() != 1
            || dktNoVillages() != 1
            || dktTwoTypes() != 1
        )
            ++bad;
        // the crow-headed tengu - the build, the malice, and the powers,
        // healthy values, each condition false
    if (dktCrowTwoToThreeFeet() != 1
            || dktCrowFeatheredWings() != 1
            || dktCrowEvilMalicious() != 1
            || dktCrowKatanaWakizashi() != 1
            || dktCrowSpeaksThree() != 1
            || dktCrowPerfectMimicry() != 1
            || dktCrowPolymorphAndShout() != 1
            || dktPolymorphPerDay() != 3
            || dktCrowLowerStatus() != 1
        )
            ++bad;
        // the humanoid tengu - the look, the powers, and the fan, healthy
        // values, each condition false
    if (dktHumThreeToFourFeet() != 1
            || dktHumLongNoses() != 1
            || dktHumStuntedWings() != 1
            || dktHumThricePowers() != 1
            || dktHumInvisibleAtWill() != 1
            || dktHumWeeklyPowers() != 1
            || dktHumMisdirectionPerTurn() != 1
            || dktHumGhostLightPerRound() != 1
            || dktHumPerfectMimicry() != 1
            || dktHumSpeaksThree() != 1
            || dktHumShukenjaAndKensai() != 1
            || dktHumOneMartialStyle() != 1
            || dktManeuverCountMin() != 2
            || dktManeuverCountMax() != 5
            || dktHumFeatherFan() != 1
            || dktHumFanAsKatana() != 1
            || dktHumFanWindAndGrowth() != 1
        )
            ++bad;
        // the tricks and the tutoring - the temper and the kensai lessons,
        // healthy values, each condition false
    if (dktHumCruelTricks() != 1
            || dktHumLikesSwordSpecialists() != 1
            || dktHumTutorsKensai() != 1
            || dktKensaiTutorMonthsMin() != 1
            || dktKensaiTutorMonthsMax() != 3
            || dktKensaiTutorXP() != 1000
            || dktSecretiveCapricious() != 1
            || dktLittleKnown() != 1
            || dktFondOfSake() != 1
            || dktTasteForMusic() != 1
        )
            ++bad;
        printf("R732 OA monsters Tengu audit: bad %d\n", bad);
        if (bad) return 1;
    }
