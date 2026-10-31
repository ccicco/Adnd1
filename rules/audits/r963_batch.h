    // ---- R963 issue-26 table round audit ----
    // the four-chain table round audit - the Chinese Undead roster grid with
    // the six undead brackets, the nine-point alignment chart with the
    // conduct encodings, the Deck of Fate artifact with the wheel bands and
    // the strength ladder with the giant rungs and the ogre power revision
    {
        using namespace rules;
        int bad = 0;
    if (s26UndeadRosterCount() != 6
            || s26UndeadPsionicClass() != 6
            || s26UndeadNeutralCount() != 2
            || s26LostSoulDamageHi() != 10
            || s26LostSoulDrain() != 2
            || s26VampireClawHi() != 4
            || s26VampireBiteHi() != 12
            || s26VampireDiseaseUses() != 5
            || s26VampireTurnPenalty() != 2
            || s26VampireCharmPenalty() != 3
            || s26SeaBonzeBreathUses() != 3
            || s26SeaBonzeBiteHi() != 8
            || s26StagHornHi() != 6
            || s26GoatDemonButtHi() != 8
            || s26AlignSchemeCount() != 9
            || s26AlignConductRows() != 7
            || s26AlignCellCount() != 63
            || s26AlignLordLevel() != 15
            || s26AlignWordUnconditional() != 3
            || s26AlignPoisonRefusers() != 3
            || s26AlignIndifferentAuthority() != 3
            || s26AlignDistrustCount() != 3
            || s26AlignLawfulCount() != 3
            || s26AlignChaoticCount() != 3
            || s26FateWheelBands() != 7
            || s26FateGreaterArcana() != 22
            || s26FateNumberedCards() != 21
            || s26FateZonkCount() != 10
            || s26FateMagicianGain() != 1
            || s26FateGoddessWisdom() != 18
            || s26FateEmpressGoldLo() != 400
            || s26FateEmpressGoldHi() != 1000
            || s26FateJupiterSpells() != 2
            || s26FateBoneDevilPlane() != 5
            || s26FateTowerSpareGold() != 13
            || s26FateStarSaves() != 3
            || s26FateSunGoldHi() != 600
            || s26FateWorldGoldHi() != 800
            || s26FateMoonRef() != 18
            || s26StrengthLadderRows() != 21
            || s26StrengthDieFloor() != 0
            || s26StrengthCeiling() != 27
            || s26StrengthOgreHit() != 3
            || s26StrengthOgreDamageDie() != 6
            || s26StrengthGauntletsOldHit() != 2
            || s26StrengthDemonLo() != 20
            || s26StrengthDemonHi() != 25
            || s26StrengthHobbitAxeDie() != 4
            || s26StrengthHobbitDamageHi() != 5
            || s26StrengthCursedAxeHi() != 7
            || s26StrengthSexChangeCap() != 14
            || s26StrengthDamageFloor() != 1
            || !s26UndeadWesternItems()
            || !s26UndeadCharmSleepImmune()
            || !s26LowerSoulNoFly()
            || !s26LostSoulReplacementKill()
            || !s26LostSoulNoDissolve()
            || !s26TigerSkinQuest()
            || !s26SeaBonzeLairSwim()
            || !s26StagOozeForm()
            || !s26StagDaylightRule()
            || !s26GoatDemonGhoulRule()
            || !s26AlignChartPurpose()
            || !s26AlignDmLicense()
            || !s26AlignLawfulOrder()
            || !s26AlignAuthorityAxis()
            || !s26AlignBankingRule()
            || !s26AlignBelladonnaNote()
            || !s26AlignEvilUnarmed()
            || !s26AlignAidRow()
            || !s26AlignNeutralWatching()
            || !s26AlignNotFirmRules()
            || !s26FateSingleCopy()
            || !s26FateNoSavingThrow()
            || !s26FateSecondCardWrath()
            || !s26FateMagicianGate()
            || !s26FateEmpressSexGate()
            || !s26FateLoversRule()
            || !s26FateJusticeTrial()
            || !s26FateHermitMercy()
            || !s26FateMoonMadness()
            || !s26FateLesserArcana()
            || !s26StrengthArduinSource()
            || !s26StrengthRacialMaxima()
            || !s26StrengthMonsterWeaponsRule()
            || !s26StrengthSmallerTableRule()
            || !s26StrengthExceptionalRolls()
            || !s26StrengthMenAttackingTable()
            || !s26StrengthFleshAndBone()
            || !s26StrengthCumulativeRule()
            || !s26StrengthDmgModificationGate()
            || !s26StrengthGirdleQuips()
        )
            ++bad;
        // the Chinese Undead roster grid - six rows of the appearing band,
        // armor class, movement, hit dice and lair percentage
        int CUndead[6][7] = {
            {1,6,2,9,7,9,20},
            {1,6,5,12,4,4,0},
            {1,2,1,18,10,10,20},
            {1,6,2,9,6,6,20},
            {2,12,3,12,3,3,0},
            {2,24,3,9,2,2,20},
            };
        int nUndead[7] = {0,0,0,0,0,0,0};
        int eUndead[7] = {0,0,0,0,0,0,0};
        for (int b = 0;
             b < s26UndeadRosterCount();
             ++b) {
            int vals[7];
            vals[0] = s26UndeadNumLo(b);
            vals[1] = s26UndeadNumHi(b);
            vals[2] = s26UndeadAc(b);
            vals[3] = s26UndeadMove(b);
            vals[4] = s26UndeadHdLo(b);
            vals[5] = s26UndeadHdHi(b);
            vals[6] = s26UndeadLairPct(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CUndead[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nUndead[c];
            }
        }
        for (int c = 0; c < 7; ++c)
            if (nUndead[c] != eUndead[c])
                ++bad;
        // the nine-point alignment chart grid - nine boxes against the seven
        // conduct rows, two yes, one conditional, zero no
        int CAlign[9][7] = {
            {2,0,0,2,2,2,2},
            {2,1,1,1,2,2,2},
            {2,2,2,0,2,2,2},
            {1,0,0,2,1,1,1},
            {1,1,1,1,1,1,1},
            {0,2,2,0,1,1,1},
            {1,0,0,2,0,0,0},
            {1,1,1,1,0,0,0},
            {0,2,2,0,0,0,0},
            };
        int nAlign[7] = {0,0,0,0,0,0,0};
        int eAlign[7] = {0,0,0,0,0,0,0};
        for (int b = 0;
             b < s26AlignSchemeCount();
             ++b) {
            int vals[7];
            vals[0] = s26AlignWord(b);
            vals[1] = s26AlignUnarmed(b);
            vals[2] = s26AlignPoison(b);
            vals[3] = s26AlignAid(b);
            vals[4] = s26AlignTeamwork(b);
            vals[5] = s26AlignAuthority(b);
            vals[6] = s26AlignTrust(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CAlign[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nAlign[c];
            }
        }
        for (int c = 0; c < 7; ++c)
            if (nAlign[c] != eAlign[c])
                ++bad;
        // the wheel of fortune grid - the seven percentile bands from the
        // magic sword to the misc magic item
        int CFate[7][2] = {
            {20,1},
            {40,2},
            {60,3},
            {70,4},
            {80,5},
            {90,6},
            {100,7},
            };
        int nFate[2] = {0,0};
        int eFate[2] = {0,0};
        for (int b = 0;
             b < s26FateWheelBands();
             ++b) {
            int vals[2];
            vals[0] = s26FateWheelRollHi(b);
            vals[1] = s26FateWheelBand(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CFate[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nFate[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nFate[c] != eFate[c])
                ++bad;
        // the strength comparison ladder grid - twenty one rows of the
        // equivalent band and the hit adjustment, the overlapping 18/90 print
        // pinned as scanned
        int CStrength[21][3] = {
            {0,0,-99},
            {1,1,-4},
            {2,2,-1},
            {3,3,-2},
            {4,4,-2},
            {5,5,-1},
            {6,7,-1},
            {8,8,-1},
            {9,12,0},
            {13,14,1},
            {15,16,1},
            {17,18,2},
            {19,19,2},
            {20,20,2},
            {21,21,3},
            {22,22,4},
            {23,23,4},
            {24,24,5},
            {25,25,5},
            {26,26,6},
            {27,27,6},
            };
        int nStrength[3] = {0,0,0};
        int eStrength[3] = {0,0,1};
        for (int b = 0;
             b < s26StrengthLadderRows();
             ++b) {
            int vals[3];
            vals[0] = s26StrengthEqLo(b);
            vals[1] = s26StrengthEqHi(b);
            vals[2] = s26StrengthHitAdj(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CStrength[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nStrength[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nStrength[c] != eStrength[c])
                ++bad;
        // the frame - six undead, class six psionics, the two neutrals, the
        // Western item baseline with the charm and sleep immunity and the
        // grounded lower soul the Chinese Undead roster (print 20-21)
    if (s26UndeadRosterCount() != 6
            || s26UndeadPsionicClass() != 6
            || s26UndeadNeutralCount() != 2
            || s26UndeadWesternItems() != 1
            || s26UndeadCharmSleepImmune() != 1
            || s26LowerSoulNoFly() != 1
        )
            ++bad;
        // the lost soul and vampire spectre - the 1-10 attack with the two
        // level drain, the replacement kill and the turn-away, the claws,
        // bite, disease, turn and charm brackets the Chinese Undead roster
        // (print 20-21)
    if (s26LostSoulDamageHi() != 10
            || s26LostSoulDrain() != 2
            || s26VampireClawHi() != 4
            || s26VampireBiteHi() != 12
            || s26VampireDiseaseUses() != 5
            || s26VampireTurnPenalty() != 2
            || s26VampireCharmPenalty() != 3
            || s26LostSoulReplacementKill() != 1
            || s26LostSoulNoDissolve() != 1
        )
            ++bad;
        // the tail of the roster - the sea bonze breath and bite with the
        // swimming lure, the stag horns, ooze and daylight, the goat demon
        // butt and ghoul law, the tiger skin quest the Chinese Undead roster
        // (print 20-21)
    if (s26SeaBonzeBreathUses() != 3
            || s26SeaBonzeBiteHi() != 8
            || s26StagHornHi() != 6
            || s26GoatDemonButtHi() != 8
            || s26SeaBonzeLairSwim() != 1
            || s26StagOozeForm() != 1
            || s26StagDaylightRule() != 1
            || s26GoatDemonGhoulRule() != 1
            || s26TigerSkinQuest() != 1
        )
            ++bad;
        // the chart frame - nine boxes, seven rows, sixty three cells, the
        // argument ending purpose with the DM license and the closing caveat
        // the nine-point alignment chart (print 23)
    if (s26AlignSchemeCount() != 9
            || s26AlignConductRows() != 7
            || s26AlignCellCount() != 63
            || s26AlignChartPurpose() != 1
            || s26AlignDmLicense() != 1
            || s26AlignNotFirmRules() != 1
        )
            ++bad;
        // the census brackets - the three Lawful and three Chaotic columns
        // with the word keepers, poison refusers, indifference and distrust
        // counts the nine-point alignment chart (print 23)
    if (s26AlignWordUnconditional() != 3
            || s26AlignPoisonRefusers() != 3
            || s26AlignIndifferentAuthority() != 3
            || s26AlignDistrustCount() != 3
            || s26AlignLawfulCount() != 3
            || s26AlignChaoticCount() != 3
        )
            ++bad;
        // the conduct doctrine - the fifteenth level lord, the order and
        // authority axes, the banking rule, the belladonna note, the unarmed
        // and aid rows with the watching neutral the nine-point alignment
        // chart (print 23)
    if (s26AlignLordLevel() != 15
            || s26AlignLawfulOrder() != 1
            || s26AlignAuthorityAxis() != 1
            || s26AlignBankingRule() != 1
            || s26AlignBelladonnaNote() != 1
            || s26AlignEvilUnarmed() != 1
            || s26AlignAidRow() != 1
            || s26AlignNeutralWatching() != 1
        )
            ++bad;
        // the artifact frame - the twenty two arcana with the fool zonks, the
        // seven wheel bands, the single copy, the no saving throw law and the
        // Lesser Arcana note the Deck of Fate tarot artifact (print 24-25)
    if (s26FateGreaterArcana() != 22
            || s26FateNumberedCards() != 21
            || s26FateZonkCount() != 10
            || s26FateWheelBands() != 7
            || s26FateSingleCopy() != 1
            || s26FateNoSavingThrow() != 1
            || s26FateLesserArcana() != 1
        )
            ++bad;
        // the boon cards - the magician spell with the gate, the goddess
        // wisdom, the jupiter spells, the bone devil summons, the star saves
        // and the second card wrath the Deck of Fate tarot artifact (print
        // 24-25)
    if (s26FateMagicianGain() != 1
            || s26FateGoddessWisdom() != 18
            || s26FateJupiterSpells() != 2
            || s26FateBoneDevilPlane() != 5
            || s26FateStarSaves() != 3
            || s26FateMagicianGate() != 1
            || s26FateSecondCardWrath() != 1
        )
            ++bad;
        // the money cards - the empress, sun and world gold brackets with the
        // empress sex gate the Deck of Fate tarot artifact (print 24-25)
    if (s26FateEmpressGoldLo() != 400
            || s26FateEmpressGoldHi() != 1000
            || s26FateSunGoldHi() != 600
            || s26FateWorldGoldHi() != 800
            || s26FateEmpressSexGate() != 1
        )
            ++bad;
        // the trial cards - the house of god thirteen, the moon citation with
        // the chaos and madness, the lovers, the justice duel and the hermit
        // mercy the Deck of Fate tarot artifact (print 24-25)
    if (s26FateTowerSpareGold() != 13
            || s26FateMoonRef() != 18
            || s26FateMoonMadness() != 1
            || s26FateLoversRule() != 1
            || s26FateJusticeTrial() != 1
            || s26FateHermitMercy() != 1
        )
            ++bad;
        // the ladder frame - twenty one rows from the zero collapse to the
        // twenty seven ceiling, the Arduin source, the racial maxima, the
        // individual rolls and the cumulative law the strength comparison
        // ladder (print 38)
    if (s26StrengthLadderRows() != 21
            || s26StrengthDieFloor() != 0
            || s26StrengthCeiling() != 27
            || s26StrengthArduinSource() != 1
            || s26StrengthRacialMaxima() != 1
            || s26StrengthExceptionalRolls() != 1
            || s26StrengthCumulativeRule() != 1
        )
            ++bad;
        // the revisions - the ogre power plus three and the d6 against the
        // old plus two and d8, the demon twenty to twenty five band, the
        // damage floor, the flesh and bone caveat and the house fit the
        // strength comparison ladder (print 38)
    if (s26StrengthOgreHit() != 3
            || s26StrengthOgreDamageDie() != 6
            || s26StrengthGauntletsOldHit() != 2
            || s26StrengthDemonLo() != 20
            || s26StrengthDemonHi() != 25
            || s26StrengthDamageFloor() != 1
            || s26StrengthDmgModificationGate() != 1
            || s26StrengthFleshAndBone() != 1
        )
            ++bad;
        // the racial weapons - the hobbit axe d4 with the 2-5 damage, the
        // cursed human 1-7 and the sex change cap, the man sized and smaller
        // tables, the Men Attacking rule and the kobold and pixie quips the
        // strength comparison ladder (print 38)
    if (s26StrengthHobbitAxeDie() != 4
            || s26StrengthHobbitDamageHi() != 5
            || s26StrengthCursedAxeHi() != 7
            || s26StrengthSexChangeCap() != 14
            || s26StrengthMonsterWeaponsRule() != 1
            || s26StrengthSmallerTableRule() != 1
            || s26StrengthMenAttackingTable() != 1
            || s26StrengthGirdleQuips() != 1
        )
            ++bad;
        // the roster corners - the lower soul and goat demon bands, the lost
        // soul armor class, the vampire spectre movement and dice, the stag
        // at no lair the Chinese Undead roster (print 20-21)
    if (s26UndeadNumLo(0) != 1
            || s26UndeadNumHi(5) != 24
            || s26UndeadAc(1) != 5
            || s26UndeadMove(2) != 18
            || s26UndeadHdLo(2) != 10
            || s26UndeadHdHi(0) != 9
            || s26UndeadLairPct(4) != 0
        )
            ++bad;
        // the chart corners - the lawful good all-twos row, the chaotic evil
        // zeros, the neutral evil unarmed, the center box poison, the neutral
        // good aid, the lawful teamwork and authority and the lawful evil
        // trust the nine-point alignment chart (print 23)
    if (s26AlignWord(0) != 2
            || s26AlignWord(8) != 0
            || s26AlignUnarmed(5) != 2
            || s26AlignPoison(4) != 1
            || s26AlignAid(3) != 2
            || s26AlignTeamwork(1) != 2
            || s26AlignAuthority(2) != 2
            || s26AlignTrust(2) != 2
        )
            ++bad;
        // the wheel corners - the twenty sword band, the one hundred misc
        // item band, the armor and wand bands the Deck of Fate tarot artifact
        // (print 24-25)
    if (s26FateWheelRollHi(0) != 20
            || s26FateWheelRollHi(6) != 100
            || s26FateWheelBand(2) != 3
            || s26FateWheelBand(5) != 6
        )
            ++bad;
        // the ladder corners - the collapse sentinel, the normal zero, the
        // plus two rungs, the twenty seven ceiling with the plus six the
        // strength comparison ladder (print 38)
    if (s26StrengthEqLo(0) != 0
            || s26StrengthHitAdj(0) != -99
            || s26StrengthHitAdj(8) != 0
            || s26StrengthHitAdj(12) != 2
            || s26StrengthEqHi(20) != 27
            || s26StrengthHitAdj(20) != 6
        )
            ++bad;
        printf("R963 issue-26 table round audit: bad %d\n", bad);
        if (bad) return 1;
    }
