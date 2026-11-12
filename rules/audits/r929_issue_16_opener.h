    // ---- R929 issue-16 opener audit ----
    // THE DRAGON ISSUE-16 OPENER ROUND - both engine-relevant chains in one
    // round. CHAIN ONE, the Near Eastern Mythos by Jerome Arkenberg (print
    // 4-6, PDF 6-8), the direct sibling of the R920 Persian and R923 Japanese
    // Mythos chains: the Sumerian-Babylonian-Canaanite pantheon - An-Anu-El
    // armor class minus 2 at 300 hit points Lord 15th psionic class 6,
    // Enlil-Marduk-Baal Lord 18th with the chariot horses at 36 feet the
    // dagger +3 vs chaotic and 30 arrows of slaying, Enki-Ea the Wizard 35th
    // at psionic class 1, Nanna-Sin-Yerah, Ninhursag-Asherah, Utu-Shamash
    // Lord 16th, Inanna-Ishtar, Dumuzi-Tammuz, Ereshkigal-Mot, Nergal-Mekal,
    // Namtar, Tiamat-Lotan armor class minus 3 at Wizard 20th, Apsu-Yamm
    // armor class minus 3 at Wizard 18th, Kingsu with the Sword of Cold,
    // Nebo, the Skilful and Percipient One Wizard 14th Lord 11th; the heroes
    // - Gilgamesh strength and charisma 20, Enkidu the wild man, Lugulbanda
    // all stats 20, Ziusudra-Utnapishtim the Wizard 15th at class 5, King
    // Krt, King Dn-il, Aqht, the Maiden; the monsters Humbaba and the
    // scorpion men; the artifacts - the Axe Might of Heroes +3 for 2-16, the
    // Bow of Anshan +3 to arrows, the Breastplate Voice of Heroes armor +5 at
    // 30 shekels, the Mace Driver +3 for 3-18 vs Lotan only, the Mace
    // Expeller +3 for 3-18 vs Yamm only; twenty one-line other deities. CHAIN
    // TWO, The Ultimate NPC: Ninja by Sheldon Price (print 7-10, PDF 9-12),
    // the DM hit-man class: strict neutrality with the 20 percent
    // same-alignment chance rolled once per encounter, languages at
    // intelligence minus six, night vision 30 then 60 feet, the level cap at
    // 16, the six-type poison system with the kill poison 0-5 per strength
    // level half damage on save the paralyze double-level suffocation the
    // instant 1-2 slow 10-60 delayed 90-140 onset and the viscous life of 12
    // hours, the -3 unmastered-weapon penalty removed per weapon, the
    // thievery of a thief three levels below with the race and sex bonuses,
    // the multiple damage of a thief one level higher, the assassination of
    // an assassin two levels higher at 15 percent of the fee to the jonin,
    // the seventeen-row progression grid with the save bands 15, 12, 8 and 3
    // and the W D T E draws, the seventeen-row thieving grid, the
    // seventeen-row assassination probability and hiring grid with the K
    // price unit at 1000 gold, and the special-device gear from the bo staff
    // to the kakae ozutsu.
    {
        using namespace rules;
        int bad = 0;
    if (ninGodRows() != 16
            || ninEnlilChariotHorsesMoveFeet() != 36
            || ninEnlilArrowsOfSlaying() != 30
            || ninEnlilDaggerPlus() != 3
            || ninHeroRows() != 8
            || ninCreatureRows() != 2
            || ninOtherDeities() != 20
            || ninAxeMightPlus() != 3
            || ninAxeMightDamageMin() != 2
            || ninAxeMightDamageMax() != 16
            || ninBowOfAnshanPlus() != 3
            || ninBreastplateArmorBonus() != 5
            || ninBreastplateShekels() != 30
            || ninMaceDriverPlus() != 3
            || ninMaceDriverDamageMin() != 3
            || ninMaceDriverDamageMax() != 18
            || ninMaceExpellerPlus() != 3
            || ninMaceExpellerDamageMin() != 3
            || ninMaceExpellerDamageMax() != 18
            || ninLevelCap() != 16
            || ninSameAlignmentPercent() != 20
            || ninLanguageBase() != 6
            || ninNightVisionFeetLevel1() != 30
            || ninNightVisionFeetLevel6() != 60
            || ninTrackingPenaltyPercent() != 20
            || ninSimulateDeathDiceSides() != 6
            || ninSimulateDeathTurnsBonus() != 1
            || ninTravelMilesLevel2() != 50
            || ninTravelMilesLevel6() != 75
            || ninTravelMilesLevel10() != 100
            || ninPoisonTypes() != 6
            || ninKillPoisonDamageMax() != 5
            || ninInstantPoisonMaxRounds() != 2
            || ninSlowPoisonMinRounds() != 10
            || ninSlowPoisonMaxRounds() != 60
            || ninDelayedPoisonMinRounds() != 90
            || ninDelayedPoisonMaxRounds() != 140
            || ninLevel6PoisonTypes() != 3
            || ninLevel6PoisonStrengthMin() != 2
            || ninLevel12PoisonStrengthMin() != 1
            || ninViscousLifeHours() != 12
            || ninPoisonNoticedPercent() != 20
            || ninAlchemistLevelsBelow() != 3
            || ninUnmasteredAttackPenalty() != 3
            || ninDisguiseAdvantagePercent() != 4
            || ninNonNinjaAttackPenalty() != 3
            || ninNonNinjaDamagePenalty() != 2
            || ninDisguiseClasses() != 10
            || ninSpecialDisguiseRequires() != 3
            || ninNobilityDisguiseRequires() != 5
            || ninTeachMonthsMin() != 1
            || ninProgressionRows() != 17
            || ninBasicKitItems() != 5
            || ninThieveryLevelsBelow() != 3
            || ninMultipleDamageLevelsAbove() != 1
            || ninAssassinationLevelsAbove() != 2
            || ninFeeJoninPercent() != 15
            || ninRaceRows() != 5
            || ninThievingRows() != 17
            || ninAssassinationRows() != 17
            || ninAssassinationKGold() != 1000
            || ninShurikenCarried() != 9
            || ninShurikenCostGold() != 3
            || ninShurikenDays() != 3
            || ninShurikenKinds() != 3
            || ninShurikenPerLevels() != 2
            || ninShurikenShieldPenalty() != 1
            || ninShurikenRangeFeet() != 30
            || ninDartShurikenPlus() != 2
            || ninDartShurikenDamageMax() != 6
            || ninFukumiNeedlesPerRound() != 2
            || ninFukumiMouthMax() != 5
            || ninFukumiRangeFeet() != 15
            || ninFukumiPoisonPercent() != 50
            || ninFukumiCostSilver() != 1
            || ninBoStaffCostGold() != 0
            || ninNinjaToCostGold() != 10
            || ninSageoCostGold() != 1
            || ninNageTeppoCostGold() != 20
            || ninNageTeppoDamageMin() != 2
            || ninNageTeppoDamageMax() != 8
            || ninSodeTsutsuCostGold() != 50
            || ninSodeTsutsuRangeFeet() != 30
            || ninSodeTsutsuConeFeet() != 10
            || ninSodeTsutsuDamageMax() != 24
            || ninKakaeOzutsuCostGold() != 50
            || ninKakaeMinRangeFeet() != 30
            || ninKakaeMaxRangeFeet() != 90
            || ninKakaeBlastRadiusFeet() != 10
            || ninKakaeDamageMax() != 20
            || ninUzumeBiCostGold() != 20
            || ninUzumeBiDays() != 3
            || ninUzumeBiDamageMax() != 10
            || ninKyoketsuShogeCostGold() != 4
            || ninKyoketsuShogeDays() != 7
            || ninShinobiZueCostGold() != 6
            || ninShinobiZueDays() != 4
            || ninMetsubushiDamageMax() != 2
            || ninTetsuBishiDamageMaxMan() != 4
            || ninTetsuBishiDamageMaxLarger() != 6
            || ninHankyuDamageMax() != 6
            || !ninEnlilDaggerVsChaoticOnly()
            || !ninMaceDriverLotanOnly()
            || !ninMaceExpellerYammOnly()
            || !ninStrictNeutrality()
            || !ninAlignmentIncorruptible()
            || !ninSameAlignmentRolledOnce()
            || !ninSurprisedAsMonk()
            || !ninNonpsychic()
            || !ninDieBeforeRevealingSecrets()
            || !ninDoNotTalkInSleep()
            || !ninPoisonStrengthCappedByLevels()
            || !ninKillPoisonHalfDamageOnSave()
            || !ninParalyzeDoubleLevelSuffocation()
            || !ninPoisonFluidOrViscous()
            || !ninViscousAsBladeVenom()
            || !ninNeutralizeNoSavingThrow()
            || !ninCureHalfEffectOffDesign()
            || !ninParalyzeKillCuresDoNotCross()
            || !ninRefusesPlate()
            || !ninAdvancesInCombatAsFighter()
            || !ninOpenHandedAsMonk()
            || !ninJudoAsSamurai()
            || !ninSpecialSaveVsDamage()
            || !ninSavesAsMagicianOneHigherVsSpells()
            || !ninHobbitsDwarvesNoFourLevelsVsSpells()
            || !ninSavesAsFighter()
            || !ninPenaltyRemovedOncePerWeapon()
            || !ninSkillsGainedImmediatelyOnLevel()
            || !ninNonNinjaMasteryNeverRemovesPenalty()
            || !ninFallsAsMonk()
        )
            ++bad;
        // the near eastern pantheon grid - sixteen full stat-block deities in
        // printed order, the see-below magic cells riding the transcript at
        // the sentinel, the dual move entries (Namtar 18/36, Nebo 15/25)
        // pinned at the first figure with the second riding the transcript
        // (folios 4-5, PDF 6-7)
        int CNG[16][6] = {
            {-2,18,300,-1,15,6},
            {-2,18,290,-1,18,6},
            {-1,18,250,35,15,1},
            {0,20,200,-1,14,6},
            {-1,18,275,-1,15,6},
            {0,20,200,-1,16,6},
            {0,18,200,-1,15,6},
            {2,15,150,-1,13,5},
            {-1,18,200,-1,14,6},
            {-1,18,175,-1,16,6},
            {2,18,150,-1,12,4},
            {-3,20,300,20,16,6},
            {-3,20,300,18,15,6},
            {-2,18,200,-1,14,6},
            {2,15,150,-1,10,6},
            {2,15,150,14,11,6},
            };
        int nNG[6] = {0,0,0,0,0,0};
        int eNG[6] = {4,0,0,12,0,0};
        for (int b = 0;
             b < ninGodRows();
             ++b) {
            int vals[6];
            vals[0] = ninGodAc(b);
            vals[1] = ninGodMove(b);
            vals[2] = ninGodHp(b);
            vals[3] = ninGodMagicLvl(b);
            vals[4] = ninGodFightLvl(b);
            vals[5] = ninGodPsiClass(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CNG[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nNG[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nNG[c] != eNG[c])
                ++bad;
        // the two monsters - Humbaba the cedar forest guardian, the scorpion
        // men of the Dilmun gate (folios 5-6, PDF 7-8)
        int CNC[2][6] = {
            {1,25,230,-1,13,-1},
            {1,20,240,15,15,1},
            };
        int nNC[6] = {0,0,0,0,0,0};
        int eNC[6] = {0,0,0,1,0,1};
        for (int b = 0;
             b < ninCreatureRows();
             ++b) {
            int vals[6];
            vals[0] = ninCreatureAc(b);
            vals[1] = ninCreatureMove(b);
            vals[2] = ninCreatureHp(b);
            vals[3] = ninCreatureMagicLvl(b);
            vals[4] = ninCreatureFightLvl(b);
            vals[5] = ninCreaturePsiClass(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CNC[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nNC[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nNC[c] != eNC[c])
                ++bad;
        // the hero and king stat grid - eight full stat blocks in printed
        // order, the as-a-normal-man armor classes pinning sentinel, the nil
        // magic and psionic cells pinning sentinel (folio 5, PDF 7)
        int CNH[8][6] = {
            {2,12,120,-1,15,-1},
            {-1,12,100,-1,13,-1},
            {1,13,140,11,15,6},
            {2,13,140,15,11,5},
            {-1,12,80,-1,10,-1},
            {-1,12,88,-1,11,-1},
            {-1,12,100,-1,13,-1},
            {-1,12,70,-1,9,-1},
            };
        int nNH[6] = {0,0,0,0,0,0};
        int eNH[6] = {5,0,0,6,0,6};
        for (int b = 0;
             b < ninHeroRows();
             ++b) {
            int vals[6];
            vals[0] = ninHeroAc(b);
            vals[1] = ninHeroMove(b);
            vals[2] = ninHeroHp(b);
            vals[3] = ninHeroMagicLvl(b);
            vals[4] = ninHeroFightLvl(b);
            vals[5] = ninHeroPsiClass(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CNH[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nNH[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nNH[c] != eNH[c])
                ++bad;
        // the hero ability grid - the Enkidu strength printing 1895 and the
        // Aqht strength printing 1875 are the 18-slash-percentile garble
        // class, pinned sentinel, never guessed; every other stat line prints
        // clean (folio 5, PDF 7)
        int CNA[8][6] = {
            {20,15,10,18,17,20},
            {-1,12,15,17,18,15},
            {20,20,20,20,20,20},
            {16,19,20,18,17,15},
            {15,17,12,13,16,16},
            {16,13,18,14,14,15},
            {-1,16,10,13,17,17},
            {14,14,13,15,17,18},
            };
        int nNA[6] = {0,0,0,0,0,0};
        int eNA[6] = {2,0,0,0,0,0};
        for (int b = 0;
             b < ninHeroRows();
             ++b) {
            int vals[6];
            vals[0] = ninHeroStr(b);
            vals[1] = ninHeroInt(b);
            vals[2] = ninHeroWis(b);
            vals[3] = ninHeroCon(b);
            vals[4] = ninHeroDex(b);
            vals[5] = ninHeroCha(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CNA[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nNA[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nNA[c] != eNA[c])
                ++bad;
        // the progression grid - the save-vs-damage bands 15, 12, 8 and 3
        // plus the weapons, disguises, tools and equipment draws per level;
        // the chigo and bushi rows print no draws, pinned sentinel; the
        // hit-dice column (1D4 through 8D12+2D4) rides the transcript (folio
        // 8, PDF 10)
        int CNP[17][5] = {
            {15,-1,-1,-1,-1},
            {15,-1,-1,-1,-1},
            {15,1,0,1,1},
            {15,0,0,0,1},
            {15,1,1,0,1},
            {12,0,1,1,1},
            {12,1,0,1,1},
            {12,1,1,0,1},
            {12,1,0,1,1},
            {12,1,1,0,1},
            {8,1,1,1,1},
            {8,1,1,0,0},
            {8,1,1,0,0},
            {8,1,1,0,0},
            {8,1,1,0,0},
            {3,1,1,0,0},
            {3,0,1,0,0},
            };
        int nNP[5] = {0,0,0,0,0};
        int eNP[5] = {0,2,2,2,2};
        for (int b = 0;
             b < ninProgressionRows();
             ++b) {
            int vals[5];
            vals[0] = ninSaveVsDamage(b);
            vals[1] = ninDrawWeapons(b);
            vals[2] = ninDrawDisguises(b);
            vals[3] = ninDrawTools(b);
            vals[4] = ninDrawEquipment(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CNP[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nNP[c];
            }
        }
        for (int c = 0; c < 5; ++c)
            if (nNP[c] != eNP[c])
                ++bad;
        // the race and sex thieving bonus grid - human, elf, dwarf, hobbit,
        // female, all bonuses additive (folio 9, PDF 11)
        int CNR[5][6] = {
            {0,0,0,0,0,0},
            {0,0,5,10,15,0},
            {5,15,0,5,5,0},
            {10,5,5,10,10,15},
            {5,5,5,5,5,5},
            };
        for (int b = 0;
             b < ninRaceRows();
             ++b) {
            int vals[6];
            vals[0] = ninRacePickLock(b);
            vals[1] = ninRaceRemoveTrap(b);
            vals[2] = ninRacePickPocket(b);
            vals[3] = ninRaceMoveSilent(b);
            vals[4] = ninRaceHideShadows(b);
            vals[5] = ninRaceHearNoise(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CNR[b][c])
                    ++bad;
            }
        }
        // the ninja thieving grid - levels 0-16 x pick lock, remove trap,
        // pick pocket, move silent, hide in shadows, hear noise, fall off
        // walls; the level-4 hide cell prints 70 and the level-5 cell 60
        // against the +5 drift, pinned as scanned; the 100+ rule (subtract
        // 100 and repeat) rides the transcript (folio 9, PDF 11)
        int CNT[17][7] = {
            {-5,-10,0,20,30,20,15},
            {0,-5,5,40,40,50,14},
            {5,0,10,45,45,58,13},
            {10,5,15,50,50,67,12},
            {15,10,20,55,70,70,11},
            {20,15,25,60,60,73,10},
            {25,20,30,65,65,77,9},
            {35,30,35,70,70,80,8},
            {40,35,45,75,75,83,7},
            {45,40,55,80,80,88,6},
            {55,50,60,90,90,94,5},
            {65,60,65,95,95,100,4},
            {75,70,75,100,100,104,3},
            {85,80,85,105,105,108,2},
            {95,90,95,110,110,112,1},
            {100,95,100,115,115,117,0},
            {105,100,105,120,120,121,-1},
            };
        for (int b = 0;
             b < ninThievingRows();
             ++b) {
            int vals[7];
            vals[0] = ninPickLock(b);
            vals[1] = ninRemoveTrap(b);
            vals[2] = ninPickPocket(b);
            vals[3] = ninMoveSilent(b);
            vals[4] = ninHideShadows(b);
            vals[5] = ninHearNoise(b);
            vals[6] = ninFallOffWalls(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CNT[b][c])
                    ++bad;
            }
        }
        // the assassination probability and hiring grid - seventeen levels,
        // the cost column in half-K units (K = 1000 gold), the ten percent
        // columns in printed order; the bullet cells pin sentinel; the row-12
        // 99, row-13 sixth-column 110 and row-15 eighth-column 99 prints pin
        // as scanned (folio 9, PDF 11)
        int CNK[17][11] = {
            {2,50,45,40,30,20,5,-1,1,1,-1},
            {3,85,80,75,65,55,40,25,10,1,-1},
            {4,90,85,80,70,60,45,30,15,1,-1},
            {5,95,90,85,75,65,50,35,20,5,-1},
            {6,100,95,90,80,70,55,40,25,10,1},
            {7,100,100,95,85,75,60,45,30,15,1},
            {8,105,100,100,90,80,65,50,35,20,5},
            {16,105,105,100,95,85,70,55,45,25,10},
            {32,105,105,105,100,90,75,60,45,30,15},
            {64,110,105,105,100,95,80,65,50,35,20},
            {128,110,110,105,105,100,85,70,55,40,25},
            {256,110,110,110,105,100,90,75,60,45,30},
            {512,115,110,110,105,105,99,95,80,65,50},
            {1024,115,115,110,110,105,110,100,90,75,60},
            {2012,115,115,115,110,105,100,100,95,85,80},
            {3036,120,115,115,110,110,100,100,99,95,85},
            {4024,120,120,115,115,110,105,105,100,100,90},
            };
        int nNK[11] = {0,0,0,0,0,0,0,0,0,0,0};
        int eNK[11] = {0,0,0,0,0,0,0,1,0,0,4};
        for (int b = 0;
             b < ninAssassinationRows();
             ++b) {
            int vals[11];
            vals[0] = ninAssassCostHalfK(b);
            vals[1] = ninAssassBand1(b);
            vals[2] = ninAssassBand2(b);
            vals[3] = ninAssassBand3(b);
            vals[4] = ninAssassBand4(b);
            vals[5] = ninAssassBand5(b);
            vals[6] = ninAssassBand6(b);
            vals[7] = ninAssassBand7(b);
            vals[8] = ninAssassBand8(b);
            vals[9] = ninAssassBand9(b);
            vals[10] = ninAssassBand10(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CNK[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nNK[c];
            }
        }
        for (int c = 0; c < 11; ++c)
            if (nNK[c] != eNK[c])
                ++bad;
        // the mythos artifacts and god gear - the axe +3 for 2-16, the bow +3
        // to arrows, the breastplate +5 at 30 shekels, both maces +3 for
        // 3-18, the Enlil chariot horses at 36 feet, 30 arrows of slaying,
        // twenty other deities (folio 6, PDF 8)
    if (ninAxeMightPlus() != 3
            || ninAxeMightDamageMin() != 2
            || ninAxeMightDamageMax() != 16
            || ninBowOfAnshanPlus() != 3
            || ninBreastplateArmorBonus() != 5
            || ninBreastplateShekels() != 30
            || ninMaceDriverPlus() != 3
            || ninMaceDriverDamageMax() != 18
            || ninMaceExpellerPlus() != 3
            || ninEnlilChariotHorsesMoveFeet() != 36
            || ninEnlilArrowsOfSlaying() != 30
            || ninOtherDeities() != 20
        )
            ++bad;
        // the ninja headline - the 16th-level cap, the 20 percent
        // same-alignment chance rolled once per encounter, languages at
        // intelligence minus six, night vision 30 then 60 feet, travel 50, 75
        // and 100 miles, tracking at a 20 percent penalty, simulated death at
        // (1-6) x level + 1 turns (folio 7, PDF 9)
    if (ninLevelCap() != 16
            || ninSameAlignmentPercent() != 20
            || ninLanguageBase() != 6
            || ninNightVisionFeetLevel1() != 30
            || ninNightVisionFeetLevel6() != 60
            || ninTravelMilesLevel2() != 50
            || ninTravelMilesLevel6() != 75
            || ninTravelMilesLevel10() != 100
            || ninTrackingPenaltyPercent() != 20
            || ninSimulateDeathDiceSides() != 6
            || ninSimulateDeathTurnsBonus() != 1
        )
            ++bad;
        // the ninja poison system - six types, kill poison 0-5 per strength
        // level and half damage on save, instant 1-2, slow 10-60, delayed
        // 90-120 rounds, level 6 at three types of strength 2, level 12 at
        // six types of strength 1, viscous gone in 12 hours, 20 percent
        // noticed, alchemist three levels lower (folio 8, PDF 10)
    if (ninPoisonTypes() != 6
            || ninKillPoisonDamageMax() != 5
            || ninInstantPoisonMaxRounds() != 2
            || ninSlowPoisonMinRounds() != 10
            || ninSlowPoisonMaxRounds() != 60
            || ninDelayedPoisonMinRounds() != 90
            || ninDelayedPoisonMaxRounds() != 140
            || ninLevel6PoisonTypes() != 3
            || ninLevel6PoisonStrengthMin() != 2
            || ninLevel12PoisonStrengthMin() != 1
            || ninViscousLifeHours() != 12
            || ninPoisonNoticedPercent() != 20
            || ninAlchemistLevelsBelow() != 3
        )
            ++bad;
        // the ninja gear - fukumi-bari two needles a round, five in the
        // mouth, 15 feet, 50 percent poison; nine shuriken, one per two
        // levels, 30 feet, the dart as a +2 dagger; the sode tsutsu 3-24, the
        // kakae ozutsu 1-20 in a 10-foot blast; the five-item basic kit; the
        // 15 percent fee to the jonin (folios 9-10, PDF 11-12)
    if (ninFukumiNeedlesPerRound() != 2
            || ninFukumiMouthMax() != 5
            || ninFukumiRangeFeet() != 15
            || ninFukumiPoisonPercent() != 50
            || ninShurikenCarried() != 9
            || ninShurikenPerLevels() != 2
            || ninShurikenRangeFeet() != 30
            || ninDartShurikenPlus() != 2
            || ninSodeTsutsuDamageMax() != 24
            || ninKakaeBlastRadiusFeet() != 10
            || ninKakaeDamageMax() != 20
            || ninBasicKitItems() != 5
            || ninFeeJoninPercent() != 15
        )
            ++bad;
        // the An-Anu-El row - armor class minus 2, 300 hit points, Lord 15th,
        // Class 6, the see-below magic riding the sentinel; Enlil-Marduk-Baal
        // at Lord 18th, 290 hit points (folio 4, PDF 6)
    if (ninGodAc(0) != -2
            || ninGodMove(0) != 18
            || ninGodHp(0) != 300
            || ninGodMagicLvl(0) != -1
            || ninGodFightLvl(0) != 15
            || ninGodPsiClass(0) != 6
            || ninGodFightLvl(1) != 18
            || ninGodHp(1) != 290
        )
            ++bad;
        // the pantheon mid rows - Enki-Ea the Wizard 35th at psionic class 1,
        // Tiamat-Lotan armor class minus 3 at Wizard 20th, Apsu-Yamm minus 3
        // at Wizard 18th, the Skilful and Percipient One Wizard 14th and Lord
        // 11th (folios 4-5, PDF 6-7)
    if (ninGodMagicLvl(2) != 35
            || ninGodPsiClass(2) != 1
            || ninGodAc(11) != -3
            || ninGodHp(11) != 300
            || ninGodMagicLvl(11) != 20
            || ninGodAc(12) != -3
            || ninGodMagicLvl(12) != 18
            || ninGodMagicLvl(15) != 14
            || ninGodFightLvl(15) != 11
        )
            ++bad;
        // the monsters - Humbaba 230 hit points at Lord 13th, the scorpion
        // men 240 hit points at Wizard 15th and psionic class 1 (folios 5-6,
        // PDF 7-8)
    if (ninCreatureHp(0) != 230
            || ninCreatureFightLvl(0) != 13
            || ninCreatureMagicLvl(1) != 15
            || ninCreaturePsiClass(1) != 1
            || ninCreatureHp(1) != 240
        )
            ++bad;
        // the hero abilities - Gilgamesh strength and charisma 20,
        // constitution 18; Lugulbanda all stats 20; Enkidu armor class and
        // strength at the sentinel, the 1895 garble riding the transcript;
        // Ziusudra the Wizard 15th at class 5 (folio 5, PDF 7)
    if (ninHeroStr(0) != 20
            || ninHeroCha(0) != 20
            || ninHeroCon(0) != 18
            || ninHeroStr(2) != 20
            || ninHeroInt(2) != 20
            || ninHeroWis(2) != 20
            || ninHeroStr(1) != -1
            || ninHeroCha(1) != 15
            || ninHeroAc(1) != -1
            || ninHeroMagicLvl(3) != 15
            || ninHeroPsiClass(3) != 5
        )
            ++bad;
        // the thieving grid - chigo lock -5, trap -10, fall 15; the hide
        // cells 70 and 60 at levels 4 and 5 pinned as scanned against the
        // drift; hear noise 100 at 11th; the 16th-level lock 105 with the
        // fall off walls at the genuine minus 1 (folio 9, PDF 11)
    if (ninPickLock(0) != -5
            || ninRemoveTrap(0) != -10
            || ninFallOffWalls(0) != 15
            || ninHideShadows(4) != 70
            || ninHideShadows(5) != 60
            || ninHearNoise(11) != 100
            || ninPickLock(16) != 105
            || ninFallOffWalls(16) != -1
        )
            ++bad;
        // the race bonuses - the hobbit lock 10 and hear 15, the dwarf trap
        // 15, the elf hide 15, the female all-fives (folio 9, PDF 11)
    if (ninRacePickLock(3) != 10
            || ninRaceRemoveTrap(2) != 15
            || ninRaceHideShadows(1) != 15
            || ninRaceHearNoise(3) != 15
            || ninRaceMoveSilent(4) != 5
        )
            ++bad;
        // the assassination grid - chigo cost 1 K at 50 percent vs the first
        // band with the bullet sentinel; level 6 at 105 percent; the costs
        // 512 K at 13th, then the as-scanned 1006 and 2012 K prints; the
        // 16th-level tenth column 90; the row-12 99 print as scanned (folio
        // 9, PDF 11)
    if (ninAssassCostHalfK(0) != 2
            || ninAssassBand1(0) != 50
            || ninAssassBand7(0) != -1
            || ninAssassBand1(6) != 105
            || ninAssassCostHalfK(13) != 1024
            || ninAssassCostHalfK(14) != 2012
            || ninAssassCostHalfK(16) != 4024
            || ninAssassBand10(16) != 90
            || ninAssassBand6(12) != 99
        )
            ++bad;
        // the progression grid - genin at save 15 drawing one weapon, one
        // tool, one equipment; the chigo draws at the sentinel; jonin 10th at
        // save 8 with all four draws; 16th level at save 3 with the printed
        // 0-1-0-0 draws (folio 8, PDF 10)
    if (ninSaveVsDamage(2) != 15
            || ninDrawWeapons(2) != 1
            || ninDrawDisguises(2) != 0
            || ninDrawTools(2) != 1
            || ninDrawEquipment(2) != 1
            || ninDrawWeapons(0) != -1
            || ninSaveVsDamage(10) != 8
            || ninDrawEquipment(10) != 1
            || ninSaveVsDamage(16) != 3
            || ninDrawWeapons(16) != 0
            || ninDrawDisguises(16) != 1
        )
            ++bad;
        printf("R929 issue-16 opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
