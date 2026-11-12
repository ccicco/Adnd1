    // ---- R941 issue-20 opener part two audit ----
    // THE DRAGON ISSUE-20 OPENER PART TWO - the two-chain round of the
    // issue-20 three-round shape. Two chains pinned from the Curtiss-provided
    // Dm20.pdf scan: the Fitzgerald It Is A Good Day To Die - the 600-death
    // Saskatoon wilderness-campaign census, thirty-one causes with the
    // percentage column in tenths; the Sagui Demonic Possession in the
    // Dungeon - the type-IV-or-greater possession doctrine, the amulet rules,
    // the host-death and repossession ladders, the exorcism ritual with the
    // wraith and spectre turning mirrors and the victim outcomes. The closing
    // flip rides R942, closing both report-020 boxes.
    {
        using namespace rules;
        int bad = 0;
    if (dstDeathRows() != 31
            || dstDeathTotal() != 600
            || dstDeathPctSumTenths() != 1001
            || dstDeathCampaignYears() != 4
            || dstDeathCompileMinYears() != 2
            || dstDeathCompileMaxYears() != 3
            || dstDeathEstimate() != 1000
            || dstMenTypesMinPct() != 20
            || dstMenTypesMaxPct() != 25
            || dstGoblinBandMin() != 300
            || dstGoblinBandMax() != 400
            || dstDeathFiveCauses() != 3
            || dstDeathFourCauses() != 3
            || dstDeathThreeCauses() != 8
            || dstDeathFactors() != 4
            || dstPossessMinType() != 4
            || dstAmuletMileRange() != 1
            || dstPossessPaladinBonus() != 1
            || dstPossessPrincePenalty() != 2
            || dstHostDeathRepossessPct() != 20
            || dstPostDeathStaySpiritPct() != 35
            || dstPostDeathBodyPlanePct() != 35
            || dstPostDeathBodyFightPct() != 30
            || dstRaisedRepossessPct() != 10
            || dstExorcismPrepRounds() != 2
            || dstExorcismEveryRounds() != 5
            || dstExorcismClericHpMin() != 1
            || dstExorcismClericHpMax() != 6
            || dstVictimFreedPct() != 55
            || dstVictimFreedDmgMin() != 1
            || dstVictimFreedDmgMax() != 10
            || dstVictimInsanePct() != 25
            || dstVictimDeadPct() != 20
            || dstRemoveCurseDemonLevel() != 13
            || dstFullWishDemonLevel() != 9
            || dstPrinceSaveBonus() != 2
            || dstSubdueStrFloor() != 18
            || dstSubdueStrRoll() != 1
            || dstSubdueFighterCount() != 2
            || !dstWildernessCampaign()
            || !dstPlayersAndHirelingsOnly()
            || !dstPatriarchsNoDeaths()
            || !dstSurpriseWorstHazard()
            || !dstTwoPlaneRuleOfThumb()
            || !dstRandomVictim()
            || !dstOnePerBody()
            || !dstKeepsVictimAc()
            || !dstAnyWeaponExceptLawful()
            || !dstAttacksAsDemonLevel()
            || !dstKeepsPowersExceptGate()
            || !dstNoFlightWithoutWings()
            || !dstHostTakesDamage()
            || !dstDetectEvilRegisters()
            || !dstDropsAlignedGear()
            || !dstNoAlignmentShock()
            || !dstBreaksRopesLeather()
            || !dstPrincesNotSubdued()
            || !dstNoChaosBlame()
            || !dstDemonsTurnAsWraiths()
            || !dstPrincesTurnAsSpectres()
            || !dstExorcisedNoRepossession()
            || !dstAmuletHolderImmune()
            || !dstAmuletContactInstantDeath()
            || !dstAmuletCommandNoDamage()
            || !dstNoTreasureInRoom()
            || !dstDanglingDashPrintCatch()
        )
            ++bad;
        // the death-cause grid - thirty-one causes down, the death count and
        // the printed percentage across; the percentage column is printed to
        // one decimal and pinned in tenths, the conversion noted, and the
        // column sums to 1001 tenths - 100.1 percent - a print catch the
        // death statistics census (print 26, PDF 28)
        int CDe[31][2] = {
            {61,101},
            {45,75},
            {34,57},
            {26,43},
            {24,40},
            {23,38},
            {21,35},
            {20,33},
            {20,33},
            {18,30},
            {18,30},
            {17,28},
            {16,27},
            {14,23},
            {13,22},
            {13,22},
            {13,22},
            {13,22},
            {12,20},
            {12,20},
            {12,20},
            {11,18},
            {9,14},
            {8,13},
            {8,13},
            {8,13},
            {8,13},
            {6,10},
            {6,10},
            {6,10},
            {85,146},
            };
        for (int b = 0;
             b < dstDeathRows();
             ++b) {
            int vals[2];
            vals[0] = dstDeathCount(b);
            vals[1] = dstDeathPct(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CDe[b][c])
                    ++bad;
            }
        }
        // the death census - thirty-one causes, 600 compiled deaths against
        // the thousand estimate, the percentage column summing to 1001
        // tenths, the 100.1 percent print catch the death statistics census
        // (print 26, PDF 28)
    if (dstDeathRows() != 31
            || dstDeathTotal() != 600
            || dstDeathPctSumTenths() != 1001
            || dstDeathCampaignYears() != 4
            || dstDeathEstimate() != 1000
        )
            ++bad;
        // the compile window and bands - 2 to 3 years of statistics, the
        // 20-25 percent men-types band, the 300-400 goblin encounter band and
        // the four deadly factors the death statistics census (print 26, PDF
        // 28)
    if (dstDeathCompileMinYears() != 2
            || dstDeathCompileMaxYears() != 3
            || dstMenTypesMinPct() != 20
            || dstMenTypesMaxPct() != 25
            || dstGoblinBandMin() != 300
            || dstGoblinBandMax() != 400
            || dstDeathFactors() != 4
        )
            ++bad;
        // the misc bands and doctrine - three five-death, three four-death
        // and eight three-death causes, the wilderness campaign, the
        // players-and-hirelings census, the no-patriarch-deaths and the
        // surprise doctrine the death statistics census (print 26, PDF 28)
    if (dstDeathFiveCauses() != 3
            || dstDeathFourCauses() != 3
            || dstDeathThreeCauses() != 8
            || dstWildernessCampaign() != 1
            || dstPlayersAndHirelingsOnly() != 1
            || dstPatriarchsNoDeaths() != 1
            || dstSurpriseWorstHazard() != 1
        )
            ++bad;
        // the possession doctrine - type IV or greater only, the one-mile
        // amulet, the plus one paladin-cleric and minus two prince saves, the
        // two-plane rule, the random victim and the one-per-body rule the
        // demonic possession doctrine (print 32, PDF 34)
    if (dstPossessMinType() != 4
            || dstAmuletMileRange() != 1
            || dstPossessPaladinBonus() != 1
            || dstPossessPrincePenalty() != 2
            || dstTwoPlaneRuleOfThumb() != 1
            || dstRandomVictim() != 1
            || dstOnePerBody() != 1
        )
            ++bad;
        // the possessed state - the victim armor class kept, any weapon but
        // the Lawful, attacks at demon level, all powers but the gate, the
        // shape preclusions and the host taking the damage the demonic
        // possession doctrine (print 32, PDF 34)
    if (dstKeepsVictimAc() != 1
            || dstAnyWeaponExceptLawful() != 1
            || dstAttacksAsDemonLevel() != 1
            || dstKeepsPowersExceptGate() != 1
            || dstNoFlightWithoutWings() != 1
            || dstHostTakesDamage() != 1
        )
            ++bad;
        // the host-death and repossession ladder - the 20 percent killer
        // repossession, the 35-35-30 post-death outcomes and the 10 percent
        // raised-victim repossession the demonic possession doctrine (print
        // 32, PDF 34)
    if (dstHostDeathRepossessPct() != 20
            || dstPostDeathStaySpiritPct() != 35
            || dstPostDeathBodyPlanePct() != 35
            || dstPostDeathBodyFightPct() != 30
            || dstRaisedRepossessPct() != 10
        )
            ++bad;
        // the exorcism ritual - 2 rounds of preparation, every 5 rounds, the
        // 1-6 cleric hit-point cost, the wraith and spectre turning mirrors
        // and the no-repossession ban the demonic possession doctrine (print
        // 32, PDF 34)
    if (dstExorcismPrepRounds() != 2
            || dstExorcismEveryRounds() != 5
            || dstExorcismClericHpMin() != 1
            || dstExorcismClericHpMax() != 6
            || dstDemonsTurnAsWraiths() != 1
            || dstPrincesTurnAsSpectres() != 1
            || dstExorcisedNoRepossession() != 1
        )
            ++bad;
        // the exorcism victim ladder - freed 55 percent taking 1-10, insane
        // 25 percent, dead 20 percent, the dangling-dash print catch riding
        // the freed line the demonic possession doctrine (print 32, PDF 34)
    if (dstVictimFreedPct() != 55
            || dstVictimFreedDmgMin() != 1
            || dstVictimFreedDmgMax() != 10
            || dstVictimInsanePct() != 25
            || dstVictimDeadPct() != 20
            || dstDanglingDashPrintCatch() != 1
        )
            ++bad;
        // the spell-save and subdual doctrine - the 13th-level remove curse
        // save, the 9th-level full wish save, the plus two princes, the two
        // 18(01) fighters and the unsubduable princes the demonic possession
        // doctrine (print 32, PDF 34)
    if (dstRemoveCurseDemonLevel() != 13
            || dstFullWishDemonLevel() != 9
            || dstPrinceSaveBonus() != 2
            || dstSubdueStrFloor() != 18
            || dstSubdueStrRoll() != 1
            || dstSubdueFighterCount() != 2
            || dstPrincesNotSubdued() != 1
        )
            ++bad;
        // the detection and amulet doctrine - Detect Evil and Holy Water, the
        // aligned-gear drop, no alignment shock, the broken restraints, no
        // chaos blame, the holder immunity, instant death, the no-damage
        // command and the treasureless room the demonic possession doctrine
        // (print 32, PDF 34)
    if (dstDetectEvilRegisters() != 1
            || dstDropsAlignedGear() != 1
            || dstNoAlignmentShock() != 1
            || dstBreaksRopesLeather() != 1
            || dstNoChaosBlame() != 1
            || dstAmuletHolderImmune() != 1
            || dstAmuletContactInstantDeath() != 1
            || dstAmuletCommandNoDamage() != 1
            || dstNoTreasureInRoom() != 1
        )
            ++bad;
        // the death grid corners - the goblin races 61 and 10.1 percent, the
        // misc band 85 and 14.6 percent, the trolls 16 and the 1.0 percent
        // band the death statistics census (print 26, PDF 28)
    if (dstDeathCount(0) != 61
            || dstDeathPct(0) != 101
            || dstDeathCount(30) != 85
            || dstDeathPct(30) != 146
            || dstDeathCount(12) != 16
            || dstDeathPct(12) != 27
            || dstDeathCount(27) != 6
            || dstDeathPct(27) != 10
        )
            ++bad;
        printf("R941 issue-20 opener part two audit: bad %d\n", bad);
        if (bad) return 1;
    }
