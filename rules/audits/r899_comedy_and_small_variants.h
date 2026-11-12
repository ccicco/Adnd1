    // ---- R899 comedy and small-variants audit ----
    // THE COMEDY AND SMALL-VARIANTS ROUND - round E of the issue-3 walk,
    // closing the adjudicated chain. Davidson's Idiot: the 160-gold hireling
    // with the 50 percent city chance and the 200-gold midget adding 5
    // percent, the confusion purpose with its 3 melee turns and the 15
    // percent attack-anyhow chance, the seven-row first-level confusion chart
    // (65 down to 5 percent), the Idiot-level confusion grid pinned as
    // scanned (the even monster rows 2, 4 and 6 across eleven Idiot levels,
    // the odd rows and the 12th column garbling in the OCR's interleaved
    // label column and riding unpinned), the constitution prime requisite
    // with the above-12 bonus and the 6 floor on Wisdom and Intelligence with
    // the 3-for-1 and 4-for-1 trades, the one-per-expedition rule, the full
    // armor with the above-9th 5 percent penalties flipping under cursed
    // armor, the no-weapons rule, the Tantrum price (2 rest days, 10 gold on
    // the spot, the wounded half-percent pinned as five tenths with the
    // week's wait), the man-minus-2 melee with 1 point at best, the
    // Exceptionally BAD Abilities chart (3, 5, 7 and 10 out of 10 with the
    // shifting dexterity bands), the fall consequences (the 100-foot trip,
    // the 1-in-6 breakage, the 2-in-6 bloody nose, the 1-in-10 arm pinned as
    // 10 percent, the 1 and 2 out of 10 normal chances), and the twelve-level
    // ladder from Dummy at 0 through Idiot at 200,101 with the 200,001 step.
    // The Jester: the 15 Intelligence, 15 Dexterity and 6-or-less Charisma
    // requisites, neutral or chaotic only, the Dwarves infinite with the
    // Hobbits 10th, Elves 6th (Village Idiot), Men 5th (Fool) and others 4th
    // (Comic), no armor, thieves allowed, the 4-sided hit die with 10 dice
    // then +1 per level, the nine joke weapons (the smelly sock 1-4 turn stun
    // with poison save, the dagger 1-6 at 3 feet, the acid-squirting flower,
    // the bursting pillow with its 1-inch blind, the jester stick, the
    // laughing gas at 30 feet, the pies at 20, the dirty underwear at 10, the
    // tomatoes at 30), the intelligence-only saving-throw doctrine with Table
    // 1 (4 through 18) and Table 2 (19 down to 5), the fourteen-row
    // experience grid pinned as scanned with the caps noted (the 15 of the
    // Dwarf-infinite track, the 5 of the Fool track, the 4 of the Comic
    // track), the eight joke levels (Giggle, Pun, Funny Face I-III, Body
    // Contortion I-II at Armor Class 0 and -4, Pause, Joke, Wonder,
    // Ventriloquism, Thighslapper, Obscenity, Boring Joke, Decrepitating,
    // Bellyacher, the Extensions I-III, Pity, Gutbuster, Insult, Quick Puns,
    // Die Laughing, Uncontrollable Laughter, Killer, Ballbuster, Voice
    // Projector) with their ranges, durations and damage pins, and the
    // wisdom-based spell chance. Cline's dexterity mods: the twelve-band grid
    // - dex 3-4 at -1/-2/-1/-1 through 18 at +1/+2/+1/+4, the printed N
    // converted to 0, with the four percent-band rows riding as scanned.
    // HONEST BOUNDARIES: the confusion grid's odd rows and 12th column, the
    // Jester experience grid's column semantics and Cline's percent rows are
    // OCR garbles that ride as scanned, pinned or noted honestly, no figure
    // pixels to check; all three clusters ride the variant layer, comedy
    // never canon.
    {
        using namespace rules;
        int bad = 0;
    if (cmvIdiotCostGold() != 160
            || cmvIdiotCityFindPct() != 50
            || cmvMidgetCostGold() != 200
            || cmvMidgetBonusPct() != 5
            || cmvIdiotConfuseTurns() != 3
            || cmvIdiotAttackAnyhowPct() != 15
            || cmvIdiotConThreshold() != 12
            || cmvIdiotConBonusPerPoint() != 1
            || cmvIdiotWisIntFloor() != 6
            || cmvIdiotTradeWisRatio() != 3
            || cmvIdiotTradeIntRatio() != 4
            || cmvIdiotLevelThreshold() != 9
            || cmvIdiotArmorLosePctPerLevel() != 5
            || cmvIdiotRestDays() != 2
            || cmvIdiotPayGold() != 10
            || cmvIdiotWoundedTenthPct() != 5
            || cmvIdiotWoundedWaitWeeks() != 1
            || cmvIdiotMeleeAsManMod() != 2
            || cmvIdiotMaxDamage() != 1
            || cmvIdiotFirstLevelCount() != 7
            || cmvIdiotConfuseGridCount() != 3
            || cmvIdiotBadDexCount() != 4
            || cmvIdiotFallDistanceFeet() != 100
            || cmvIdiotBreakDie() != 6
            || cmvIdiotBreakChance() != 1
            || cmvIdiotNoseDie() != 6
            || cmvIdiotNoseChance() != 2
            || cmvIdiotArmPct() != 10
            || cmvIdiotAvgFallOutOf10() != 1
            || cmvIdiotBelowFallOutOf10() != 2
            || cmvIdiotLadderCount() != 12
            || cmvIdiotAboveStepXp() != 200001
            || cmvJesterIntMin() != 15
            || cmvJesterDexMin() != 15
            || cmvJesterChaMax() != 6
            || cmvJesterHobbitMax() != 10
            || cmvJesterElfMax() != 6
            || cmvJesterMenMax() != 5
            || cmvJesterOtherMax() != 4
            || cmvJesterHitDieSides() != 4
            || cmvJesterHitDiceMax() != 10
            || cmvJesterHitDieAfterBonus() != 1
            || cmvJesterWeaponCount() != 9
            || cmvJesSockStunMin() != 1
            || cmvJesSockStunMax() != 4
            || cmvJesDaggerMaxDamage() != 6
            || cmvJesDaggerRangeFeet() != 3
            || cmvJesPillowBurstDie() != 6
            || cmvJesPillowBurstMax() != 2
            || cmvJesPillowBlindDiameter() != 1
            || cmvJesPillowBlindTurns() != 3
            || cmvJesPillowStunTurns() != 1
            || cmvJesGasRangeFeet() != 30
            || cmvJesGasLaughterTurns() != 3
            || cmvJesPiesRangeFeet() != 20
            || cmvJesPiesBlindMin() != 1
            || cmvJesPiesBlindMax() != 4
            || cmvJesUnderwearRangeFeet() != 10
            || cmvJesUnderwearStunMin() != 1
            || cmvJesUnderwearStunMax() != 6
            || cmvJesTomatoRangeFeet() != 30
            || cmvJesTomatoBlindTurns() != 1
            || cmvJesterSavesHighCount() != 7
            || cmvJesterSavesLowCount() != 7
            || cmvJesterXpGridCount() != 14
            || cmvJesGiggleHdMax() != 3
            || cmvJesGiggleTurns() != 1
            || cmvJesLaughHitMod() != 4
            || cmvJesGiggleRangeInches() != 2
            || cmvJesPunTurns() != 1
            || cmvJesPunRangeInches() != 2
            || cmvJesFF1First() != 10
            || cmvJesFF1Second() != 5
            || cmvJesFF1Third() != 1
            || cmvJesFF1Turns() != 1
            || cmvJesFF1RangeInches() != 2
            || cmvJesBC1Ac() != 0
            || cmvJesBC1Turns() != 1
            || cmvJesPauseTurns() != 2
            || cmvJesPauseRangeInches() != 2
            || cmvJesJokeTurns() != 2
            || cmvJesJokeHdMax() != 6
            || cmvJesJokeRangeInches() != 2
            || cmvJesFF2Third() != 3
            || cmvJesFF2Fourth() != 2
            || cmvJesFF2Fifth() != 1
            || cmvJesBC2Ac() != 4
            || cmvJesWonderTurns() != 4
            || cmvJesWonderRangeInches() != 2
            || cmvJesVentriloquismRangeInches() != 3
            || cmvJesThighTurnsToUtter() != 2
            || cmvJesThighLaughterTurns() != 8
            || cmvJesThighFirst() != 10
            || cmvJesThighSecond() != 9
            || cmvJesThighThird() != 8
            || cmvJesThighRangeInches() != 3
            || cmvJesFF3Level() != 18
            || cmvJesFF3Seventh() != 2
            || cmvJesFF3RangeInches() != 2
            || cmvJesObscenityTurns() != 3
            || cmvJesBoringTurnsToUtter() != 4
            || cmvJesBoringTenthTurns() != 2
            || cmvJesBoringNinthTurns() != 4
            || cmvJesBoringRangeInches() != 2
            || cmvJesDecrepSeventhTurns() != 2
            || cmvJesDecrepEighthTurns() != 4
            || cmvJesDecrepPerHourMax() != 3
            || cmvJesDecrepRangeInches() != 3
            || cmvJesBellyTurnsToUtter() != 2
            || cmvJesBellyLaughterTurns() != 8
            || cmvJesExt1Resistance() != 1
            || cmvJesExt2Resistance() != 2
            || cmvJesGutbusterMinDamage() != 1
            || cmvJesGutbusterMaxDamage() != 4
            || cmvJesInsultFleePct() != 50
            || cmvJesInsultFleeDie() != 6
            || cmvJesInsultFleeDieMax() != 3
            || cmvJesInsultEnragePct() != 50
            || cmvJesInsultDieSides() != 20
            || cmvJesInsultTurnsMin() != 1
            || cmvJesInsultTurnsMax() != 20
            || cmvJesQuickPunsLevelBase() != 8
            || cmvJesQuickPunsRangeInches() != 3
            || cmvJesExt3Resistance() != 3
            || cmvJesDieLaughTurnsToTell() != 3
            || cmvJesDieLaughHdMax() != 8
            || cmvJesDieLaughSavePctMaxHp() != 50
            || cmvJesDieLaughDieTurns() != 2
            || cmvJesDieLaughPerTurnPct() != 25
            || cmvJesDieLaughRangeInches() != 2
            || cmvJesUnctrlTurns() != 10
            || cmvJesUnctrlTenth() != 1
            || cmvJesUnctrlNinth() != 2
            || cmvJesUnctrlRangeInches() != 2
            || cmvJesKillerHdMax() != 12
            || cmvJesKillerTurnsToUtter() != 3
            || cmvJesKillerSavePctMaxHp() != 50
            || cmvJesKillerDieTurns() != 2
            || cmvJesKillerPerTurnPct() != 25
            || cmvJesKillerRangeInches() != 3
            || cmvJesBallbustTurnsToUtter() != 3
            || cmvJesBallbustMinTurns() != 1
            || cmvJesBallbustMaxTurns() != 10
            || cmvJesBallbustRangeInches() != 3
            || cmvJesVoiceRangeMult() != 2
            || cmvJesVoiceTurns() != 4
            || cmvClineDexCount() != 12
            || !cmvIdiotConfusePurpose()
            || !cmvIdiotConIsPrime()
            || !cmvIdiotOnePerExpedition()
            || !cmvIdiotFullArmor()
            || !cmvIdiotCursedArmorOpposite()
            || !cmvIdiotNoWeapons()
            || !cmvIdiotDexShifting()
            || !cmvJesterNeutralOrChaotic()
            || !cmvJesterDwarfInfinite()
            || !cmvJesterNoArmor()
            || !cmvJesterThiefAlso()
            || !cmvJesterWeaponExclusive()
            || !cmvJesterIntOnlySaves()
            || !cmvJesSaveTotalOrAbove()
            || !cmvJesSpellsByWisdom()
            || !cmvJesStrangeActions()
            || !cmvJesPityBefriending()
            || !cmvClineHitHandHeld()
        )
            ++bad;
        // the chances of confusing at first level - 65, 55, 45, 35, 20, 10,
        // 05 percent by monster level 1 through 7 (folio 28)
        int CCrIdF[7][2] = {
            {1,65},
            {2,55},
            {3,45},
            {4,35},
            {5,20},
            {6,10},
            {7,5},
            };
        for (int b = 0;
             b < cmvIdiotFirstLevelCount();
             ++b) {
            int vals[2];
            vals[0] = cmvIdFirstMonLevel(b);
            vals[1] = cmvIdFirstPct(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CCrIdF[b][c])
                    ++bad;
            }
        }
        // the Idiot-level versus monster-level confusion grid, AS SCANNED -
        // Idiots raise levels and become more effective with higher level
        // monsters but less effective with the lower ones, the more refined
        // idiocy that accompanies experience; the OCR interleaves the odd
        // monster rows into the label column and truncates the 12th
        // Idiot-level column, both noted, no figure pixels to check (folio
        // 28)
        int CCrIdG[3][12] = {
            {2,55,57,53,51,49,47,45,43,41,39,36},
            {4,35,37,39,41,43,45,47,45,43,41,40},
            {6,10,12,14,16,18,20,22,24,26,28,30},
            };
        for (int b = 0;
             b < cmvIdiotConfuseGridCount();
             ++b) {
            int vals[12];
            vals[0] = cmvIdGridMonLevel(b);
            vals[1] = cmvIdGridIgL1(b);
            vals[2] = cmvIdGridIgL2(b);
            vals[3] = cmvIdGridIgL3(b);
            vals[4] = cmvIdGridIgL4(b);
            vals[5] = cmvIdGridIgL5(b);
            vals[6] = cmvIdGridIgL6(b);
            vals[7] = cmvIdGridIgL7(b);
            vals[8] = cmvIdGridIgL8(b);
            vals[9] = cmvIdGridIgL9(b);
            vals[10] = cmvIdGridIgL10(b);
            vals[11] = cmvIdGridIgL11(b);
            for (int c = 0; c < 12;
                 ++c) {
                if (vals[c] != CCrIdG[b][c])
                    ++bad;
            }
        }
        // the Exceptionally BAD Abilities chart on the percentile dice -
        // 01-50 a 3 out of 10 chance, 51-75 a 5, 76-90 a 7, 91-00 a 10 out of
        // 10 (folio 28)
        int CCrIdB[4][3] = {
            {1,50,3},
            {51,75,5},
            {76,90,7},
            {91,100,10},
            };
        for (int b = 0;
             b < cmvIdiotBadDexCount();
             ++b) {
            int vals[3];
            vals[0] = cmvIdBadLo(b);
            vals[1] = cmvIdBadHi(b);
            vals[2] = cmvIdBadOutOf10(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrIdB[b][c])
                    ++bad;
            }
        }
        // the Idiot's level ladder - 1 Dummy, 2 Dope, 3 Dolt, 4 Dullard, 5
        // Cluck, 6 Klutz, 7 Cretin, 8 Weirdo, 9 Nut, 10 Fool, 11 Imbecile, 12
        // Idiot (folio 28)
        int CCrIdL[12][2] = {
            {1,0},
            {2,1001},
            {3,2623},
            {4,6157},
            {5,9738},
            {6,11432},
            {7,19832},
            {8,30876},
            {9,61423},
            {10,88749},
            {11,120456},
            {12,200101},
            };
        for (int b = 0;
             b < cmvIdiotLadderCount();
             ++b) {
            int vals[2];
            vals[0] = cmvIdLvlIndex(b);
            vals[1] = cmvIdLvlXp(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CCrIdL[b][c])
                    ++bad;
            }
        }
        // Table 1, saving throws for jokes aimed at high intellects - the
        // smarter they are, the harder they laugh: 4 through 18 (folio 29)
        int CCrJs1[7][3] = {
            {1,3,4},
            {4,6,6},
            {7,9,8},
            {10,12,10},
            {13,15,14},
            {16,17,16},
            {18,18,18},
            };
        for (int b = 0;
             b < cmvJesterSavesHighCount();
             ++b) {
            int vals[3];
            vals[0] = cmvJs1Lo(b);
            vals[1] = cmvJs1Hi(b);
            vals[2] = cmvJs1Save(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrJs1[b][c])
                    ++bad;
            }
        }
        // Table 2, saving throws for jokes aimed at those with low
        // intelligence - the dumb ones laugh hardest: 19 down to 5 (folio 29)
        int CCrJs2[7][3] = {
            {1,3,19},
            {4,6,16},
            {7,9,14},
            {10,12,11},
            {13,15,9},
            {16,17,7},
            {18,18,5},
            };
        for (int b = 0;
             b < cmvJesterSavesLowCount();
             ++b) {
            int vals[3];
            vals[0] = cmvJs2Lo(b);
            vals[1] = cmvJs2Hi(b);
            vals[2] = cmvJs2Save(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrJs2[b][c])
                    ++bad;
            }
        }
        // the Jester experience grid AS SCANNED - the OCR prints eight
        // unlabeled progression columns; the first caps at 15 (the
        // Dwarf-infinite track), the sixth at 5 (the Men/Fool track) and the
        // seventh at 4 (the Comic track) matching the printed racial caps,
        // and the rest ride as scanned with the column semantics garbled, the
        // staircase blanks CONVERTED to 0 (folio 29)
        int CCrJsX[14][9] = {
            {2000,2,1,0,0,0,0,0,0},
            {4000,3,2,0,0,0,0,0,0},
            {8000,4,3,1,0,0,0,0,0},
            {16000,5,4,2,0,0,0,0,0},
            {32000,6,4,2,1,0,0,0,0},
            {64000,7,4,3,2,0,0,0,0},
            {128000,8,5,4,3,1,0,0,0},
            {228000,9,5,4,4,2,0,0,0},
            {328000,10,5,5,4,3,1,0,0},
            {428000,11,6,5,5,4,2,1,0},
            {528000,12,6,5,5,5,3,1,0},
            {628000,13,6,6,5,5,4,2,1},
            {728000,14,7,6,6,5,4,3,2},
            {828000,15,7,6,6,6,5,4,2},
            };
        for (int b = 0;
             b < cmvJesterXpGridCount();
             ++b) {
            int vals[9];
            vals[0] = cmvJxXp(b);
            vals[1] = cmvJxC1(b);
            vals[2] = cmvJxC2(b);
            vals[3] = cmvJxC3(b);
            vals[4] = cmvJxC4(b);
            vals[5] = cmvJxC5(b);
            vals[6] = cmvJxC6(b);
            vals[7] = cmvJxC7(b);
            vals[8] = cmvJxC8(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CCrJsX[b][c])
                    ++bad;
            }
        }
        // Cline's combat modifications for dexterity - the printed 'N'
        // entries CONVERT to 0 and the signs ride as printed; the four
        // percent-band rows (51-75, 76-90, 91-99, 00 pinned as 100) garble
        // against the 3-18 dex scale and ride AS SCANNED, no figure pixels to
        // check (folio 30)
        int CCrCl[12][6] = {
            {3,4,-1,-2,-1,-1},
            {5,8,0,-1,0,0},
            {9,12,0,0,0,0},
            {13,14,0,1,0,0},
            {15,15,0,1,0,1},
            {16,16,1,1,0,2},
            {17,17,1,2,-1,3},
            {18,18,1,2,1,4},
            {51,75,2,3,2,4},
            {76,90,2,3,2,4},
            {91,99,2,4,2,5},
            {100,100,3,5,3,6},
            };
        for (int b = 0;
             b < cmvClineDexCount();
             ++b) {
            int vals[6];
            vals[0] = cmvClDexLo(b);
            vals[1] = cmvClDexHi(b);
            vals[2] = cmvClHit(b);
            vals[3] = cmvClMissile(b);
            vals[4] = cmvClDamage(b);
            vals[5] = cmvClDefense(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CCrCl[b][c])
                    ++bad;
            }
        }
        // the Idiot's hire - 160 gold pieces, a 50 percent city chance, and
        // the 200-gold midget adding 5 percent to all base chances (folio 28)
    if (cmvIdiotCostGold() != 160
            || cmvIdiotCityFindPct() != 50
            || cmvMidgetCostGold() != 200
            || cmvMidgetBonusPct() != 5
        )
            ++bad;
        // the Idiot's purpose - the confused enemy runs away, attacks a wall,
        // commits Hari Kari or eats its treasure for 3 melee turns, with a 15
        // percent chance it attacks anyhow (folio 28)
    if (cmvIdiotConfusePurpose() != 1
            || cmvIdiotConfuseTurns() != 3
            || cmvIdiotAttackAnyhowPct() != 15
        )
            ++bad;
        // the Idiot's prime requisite - constitution so he can stay goofy, +1
        // confuse per point above 12, Wisdom and Intelligence floored at 6
        // with the 3-for-1 and 4-for-1 trades (folio 28)
    if (cmvIdiotConIsPrime() != 1
            || cmvIdiotConThreshold() != 12
            || cmvIdiotConBonusPerPoint() != 1
            || cmvIdiotWisIntFloor() != 6
            || cmvIdiotTradeWisRatio() != 3
            || cmvIdiotTradeIntRatio() != 4
        )
            ++bad;
        // the Idiot's gear - one per expedition, full armor worn but 5
        // percent lost per level above 9, cursed armor the opposite, and no
        // weapons employed though any articles carried (folio 28)
    if (cmvIdiotOnePerExpedition() != 1
            || cmvIdiotFullArmor() != 1
            || cmvIdiotLevelThreshold() != 9
            || cmvIdiotArmorLosePctPerLevel() != 5
            || cmvIdiotCursedArmorOpposite() != 1
            || cmvIdiotNoWeapons() != 1
        )
            ++bad;
        // the Tantrum's price - 2 days of rest and 10 gold on the spot or the
        // held breath, the wounded Idiot confusing at a half percent pinned
        // as five tenths with a week's wait, melees as a man -2 with 1 point
        // at best (folio 28)
    if (cmvIdiotRestDays() != 2
            || cmvIdiotPayGold() != 10
            || cmvIdiotWoundedTenthPct() != 5
            || cmvIdiotWoundedWaitWeeks() != 1
            || cmvIdiotMeleeAsManMod() != 2
            || cmvIdiotMaxDamage() != 1
        )
            ++bad;
        // the Idiot's falls - every 100 feet a trip and a drop, carried
        // articles breaking 1 in 6, a bloody nose 2 in 6, a broken arm 1 in
        // 10 pinned as 10 percent (folio 28)
    if (cmvIdiotFallDistanceFeet() != 100
            || cmvIdiotBreakDie() != 6
            || cmvIdiotBreakChance() != 1
            || cmvIdiotNoseDie() != 6
            || cmvIdiotNoseChance() != 2
            || cmvIdiotArmPct() != 10
        )
            ++bad;
        // the normal falls and the shifting - 1 out of 10 at average
        // dexterity, 2 out of 10 below, the dexterity bands shifting down on
        // the dice, and 200,001 points per level above Idiot (folio 28)
    if (cmvIdiotAvgFallOutOf10() != 1
            || cmvIdiotBelowFallOutOf10() != 2
            || cmvIdiotDexShifting() != 1
            || cmvIdiotAboveStepXp() != 200001
        )
            ++bad;
        // the Jester's gates - Intelligence 15 or better, Dexterity 15 or
        // better, Charisma 6 or less, always neutral or chaotic (folios
        // 28-29)
    if (cmvJesterIntMin() != 15
            || cmvJesterDexMin() != 15
            || cmvJesterChaMax() != 6
            || cmvJesterNeutralOrChaotic() != 1
        )
            ++bad;
        // the Jester's advancement caps - Dwarves infinite as the best
        // jesters, Hobbits 10th, Elves 6th as the Village Idiot, Men 5th as
        // the Fool, others 4th as the Comic (folios 28-29)
    if (cmvJesterDwarfInfinite() != 1
            || cmvJesterHobbitMax() != 10
            || cmvJesterElfMax() != 6
            || cmvJesterMenMax() != 5
            || cmvJesterOtherMax() != 4
        )
            ++bad;
        // the Jester's frame - no armor, thieves allowed as well as funnymen,
        // a 4-sided hit die with 10 dice maximum then +1 per level (folios
        // 28-29)
    if (cmvJesterNoArmor() != 1
            || cmvJesterThiefAlso() != 1
            || cmvJesterHitDieSides() != 4
            || cmvJesterHitDiceMax() != 10
            || cmvJesterHitDieAfterBonus() != 1
        )
            ++bad;
        // the joke weapons - nine of them, all but the dagger Jester-only,
        // the smelly sock stunning 1-4 turns with a poison save, the dagger
        // 1-6 at 3 feet (folios 28-29)
    if (cmvJesterWeaponExclusive() != 1
            || cmvJesterWeaponCount() != 9
            || cmvJesSockStunMin() != 1
            || cmvJesSockStunMax() != 4
            || cmvJesDaggerMaxDamage() != 6
            || cmvJesDaggerRangeFeet() != 3
        )
            ++bad;
        // the pillow and the gas - bursting on 1-2 of a d6 to blind a 1-inch
        // diameter for 3 turns, else a 1-turn Morningstar stun; the laughing
        // gas at 30 feet with 3 turns of uncontrollable laughter (folio 29)
    if (cmvJesPillowBurstDie() != 6
            || cmvJesPillowBurstMax() != 2
            || cmvJesPillowBlindDiameter() != 1
            || cmvJesPillowBlindTurns() != 3
            || cmvJesPillowStunTurns() != 1
            || cmvJesGasRangeFeet() != 30
            || cmvJesGasLaughterTurns() != 3
        )
            ++bad;
        // the pies, the underwear, the tomatoes - pies blinding 1-4 turns at
        // 20 feet, the dirty underwear stunning 1-6 with a poison save at 10
        // feet, the tomatoes blinding 1 turn at 30 feet (folio 29)
    if (cmvJesPiesRangeFeet() != 20
            || cmvJesPiesBlindMin() != 1
            || cmvJesPiesBlindMax() != 4
            || cmvJesUnderwearRangeFeet() != 10
            || cmvJesUnderwearStunMin() != 1
            || cmvJesUnderwearStunMax() != 6
            || cmvJesTomatoRangeFeet() != 30
            || cmvJesTomatoBlindTurns() != 1
        )
            ++bad;
        // the saving-throw doctrine - the battler's level is inconsequential,
        // intelligence the only factor, and failure to make the total or
        // above means full effect (folio 29)
    if (cmvJesterIntOnlySaves() != 1
            || cmvJesSaveTotalOrAbove() != 1
        )
            ++bad;
        // the 1st-level jokes - Giggle (under 3 hit dice, 1 turn of laughter,
        // -4 to hit, range 2) and the Pun (the Wha-a pause for 1 turn, range
        // 2) (folio 29)
    if (cmvJesGiggleHdMax() != 3
            || cmvJesGiggleTurns() != 1
            || cmvJesLaughHitMod() != 4
            || cmvJesGiggleRangeInches() != 2
            || cmvJesPunTurns() != 1
            || cmvJesPunRangeInches() != 2
        )
            ++bad;
        // more 1st level - Funny Face I (10 1st, 5 2nd or 1 3rd level types,
        // 1 turn, range 2) and Body Contortion I (Armor Class 0 for 1 turn)
        // (folio 29)
    if (cmvJesFF1First() != 10
            || cmvJesFF1Second() != 5
            || cmvJesFF1Third() != 1
            || cmvJesFF1Turns() != 1
            || cmvJesFF1RangeInches() != 2
            || cmvJesBC1Ac() != 0
            || cmvJesBC1Turns() != 1
        )
            ++bad;
        // the 2nd level - Pause (2 melee turns, range 2), Joke (2 turns, 6
        // hit dice, range 2), Funny Face II (3 3rds, 2 4ths, 1 5th) and Body
        // Contortion II (Armor Class -4 pinned as 4) (folio 29)
    if (cmvJesPauseTurns() != 2
            || cmvJesPauseRangeInches() != 2
            || cmvJesJokeTurns() != 2
            || cmvJesJokeHdMax() != 6
            || cmvJesJokeRangeInches() != 2
            || cmvJesFF2Third() != 3
            || cmvJesFF2Fourth() != 2
            || cmvJesFF2Fifth() != 1
            || cmvJesBC2Ac() != 4
        )
            ++bad;
        // the 3rd level - Wonder (4 turns, range 2), Ventriloquism (range 3),
        // Thighslapper (2 turns to utter, 8 of laughter, 10-9-8 and so on,
        // range 3) (folio 29)
    if (cmvJesWonderTurns() != 4
            || cmvJesWonderRangeInches() != 2
            || cmvJesVentriloquismRangeInches() != 3
            || cmvJesThighTurnsToUtter() != 2
            || cmvJesThighLaughterTurns() != 8
            || cmvJesThighFirst() != 10
            || cmvJesThighSecond() != 9
            || cmvJesThighThird() != 8
            || cmvJesThighRangeInches() != 3
        )
            ++bad;
        // more 3rd level - Funny Face III (1 18th level type, 2 7ths, 1 turn,
        // range 2) and Obscenity (the Clerics ineffective for 3 turns) (folio
        // 29)
    if (cmvJesFF3Level() != 18
            || cmvJesFF3Seventh() != 2
            || cmvJesFF3RangeInches() != 2
            || cmvJesObscenityTurns() != 3
        )
            ++bad;
        // the 4th level - Boring Joke (4 turns to utter, the Sleep with 2
        // turns at 10th and 4 at 9th, range 2) and Decrepitating (2 turns at
        // 7th, 4 at 8th, 3 per game hour, range 3) (folio 29)
    if (cmvJesBoringTurnsToUtter() != 4
            || cmvJesBoringTenthTurns() != 2
            || cmvJesBoringNinthTurns() != 4
            || cmvJesBoringRangeInches() != 2
            || cmvJesDecrepSeventhTurns() != 2
            || cmvJesDecrepEighthTurns() != 4
            || cmvJesDecrepPerHourMax() != 3
            || cmvJesDecrepRangeInches() != 3
        )
            ++bad;
        // more 4th level - Bellyacher (2 turns to utter, 8 turns plus level),
        // Extension I (resistance lowered by 1) and Strange Actions (the Joke
        // with Body Contortion I) (folio 29)
    if (cmvJesBellyTurnsToUtter() != 2
            || cmvJesBellyLaughterTurns() != 8
            || cmvJesExt1Resistance() != 1
            || cmvJesStrangeActions() != 1
        )
            ++bad;
        // the 5th level - Extension II (resistance lowered by 2), Pity (the
        // Charm Person to befriending) and Gutbuster (Bellyacher plus 1-4
        // damage) (folio 29)
    if (cmvJesExt2Resistance() != 2
            || cmvJesPityBefriending() != 1
            || cmvJesGutbusterMinDamage() != 1
            || cmvJesGutbusterMaxDamage() != 4
        )
            ++bad;
        // more 5th level - Insult (50 percent flee on 1-3 of a d6, 50 percent
        // enrage, 1-20 turns on a d20) and Quick Puns (one per level above
        // 8th, no save, range 3) (folio 29)
    if (cmvJesInsultFleePct() != 50
            || cmvJesInsultFleeDie() != 6
            || cmvJesInsultFleeDieMax() != 3
            || cmvJesInsultEnragePct() != 50
            || cmvJesInsultDieSides() != 20
            || cmvJesInsultTurnsMin() != 1
            || cmvJesInsultTurnsMax() != 20
            || cmvJesQuickPunsLevelBase() != 8
            || cmvJesQuickPunsRangeInches() != 3
        )
            ++bad;
        // the 6th level - Extension III (resistance by 3) and Die Laughing (3
        // turns to tell, kills under 8 hit dice, others half total hit points
        // pinned as 50 percent, 2 turns to die or 25 percent per turn on a
        // save, range 2) (folio 30)
    if (cmvJesExt3Resistance() != 3
            || cmvJesDieLaughTurnsToTell() != 3
            || cmvJesDieLaughHdMax() != 8
            || cmvJesDieLaughSavePctMaxHp() != 50
            || cmvJesDieLaughDieTurns() != 2
            || cmvJesDieLaughPerTurnPct() != 25
            || cmvJesDieLaughRangeInches() != 2
        )
            ++bad;
        // more 6th level - Uncontrollable Laughter (10 turns of
        // incapacitation, 1 10th or 2 9ths and so on, no save, range 2)
        // (folio 30)
    if (cmvJesUnctrlTurns() != 10
            || cmvJesUnctrlTenth() != 1
            || cmvJesUnctrlNinth() != 2
            || cmvJesUnctrlRangeInches() != 2
        )
            ++bad;
        // the 7th level - Killer (kills under 12 hit dice, 3 turns to utter,
        // half damage pinned as 50 percent on a save, 2 turns to die or 25
        // percent per turn, range 3) (folio 30)
    if (cmvJesKillerHdMax() != 12
            || cmvJesKillerTurnsToUtter() != 3
            || cmvJesKillerSavePctMaxHp() != 50
            || cmvJesKillerDieTurns() != 2
            || cmvJesKillerPerTurnPct() != 25
            || cmvJesKillerRangeInches() != 3
        )
            ++bad;
        // more 7th level - Ballbuster (3 turns to utter, 1-10 turns of
        // incapacity, any thinking creature, no save, range 3) (folio 30)
    if (cmvJesBallbustTurnsToUtter() != 3
            || cmvJesBallbustMinTurns() != 1
            || cmvJesBallbustMaxTurns() != 10
            || cmvJesBallbustRangeInches() != 3
        )
            ++bad;
        // the 8th level and the spell chance - Voice Projector doubling any
        // joke's range for 4 turns, and the Magic User's chance with wisdom
        // as the base (folio 30)
    if (cmvJesVoiceRangeMult() != 2
            || cmvJesVoiceTurns() != 4
            || cmvJesSpellsByWisdom() != 1
        )
            ++bad;
        // Cline's frame - the Hit column means to hit with a hand-held weapon
        // (folio 30)
    if (cmvClineHitHandHeld() != 1
        )
            ++bad;
        // the 1st-level monster row - 65 percent (folio 28) (folio 28)
    if (cmvIdFirstMonLevel(0) != 1
            || cmvIdFirstPct(0) != 65
            || cmvIdiotFirstLevelCount() != 7
        )
            ++bad;
        // the 2nd-level monster row - 55 percent (folio 28) (folio 28)
    if (cmvIdFirstMonLevel(1) != 2
            || cmvIdFirstPct(1) != 55
        )
            ++bad;
        // the 3rd-level monster row - 45 percent (folio 28) (folio 28)
    if (cmvIdFirstMonLevel(2) != 3
            || cmvIdFirstPct(2) != 45
        )
            ++bad;
        // the 4th-level monster row - 35 percent (folio 28) (folio 28)
    if (cmvIdFirstMonLevel(3) != 4
            || cmvIdFirstPct(3) != 35
        )
            ++bad;
        // the 5th-level monster row - 20 percent (folio 28) (folio 28)
    if (cmvIdFirstMonLevel(4) != 5
            || cmvIdFirstPct(4) != 20
        )
            ++bad;
        // the 6th-level monster row - 10 percent (folio 28) (folio 28)
    if (cmvIdFirstMonLevel(5) != 6
            || cmvIdFirstPct(5) != 10
        )
            ++bad;
        // the 7th-level monster row - 05 percent, pinned as 5 (folio 28)
        // (folio 28)
    if (cmvIdFirstMonLevel(6) != 7
            || cmvIdFirstPct(6) != 5
        )
            ++bad;
        // the monster-level-2 row - 55 up to 57 then down to 36 across Idiot
        // levels 1-11, as scanned (folio 28) (folio 28)
    if (cmvIdGridMonLevel(0) != 2
            || cmvIdGridIgL1(0) != 55
            || cmvIdGridIgL2(0) != 57
            || cmvIdGridIgL3(0) != 53
            || cmvIdGridIgL4(0) != 51
            || cmvIdGridIgL5(0) != 49
            || cmvIdGridIgL6(0) != 47
            || cmvIdGridIgL7(0) != 45
            || cmvIdGridIgL8(0) != 43
            || cmvIdGridIgL9(0) != 41
            || cmvIdGridIgL10(0) != 39
            || cmvIdGridIgL11(0) != 36
            || cmvIdiotConfuseGridCount() != 3
        )
            ++bad;
        // the monster-level-4 row - 35 up through 47 at level 7 then back to
        // 40, as scanned (folio 28) (folio 28)
    if (cmvIdGridMonLevel(1) != 4
            || cmvIdGridIgL1(1) != 35
            || cmvIdGridIgL2(1) != 37
            || cmvIdGridIgL3(1) != 39
            || cmvIdGridIgL4(1) != 41
            || cmvIdGridIgL5(1) != 43
            || cmvIdGridIgL6(1) != 45
            || cmvIdGridIgL7(1) != 47
            || cmvIdGridIgL8(1) != 45
            || cmvIdGridIgL9(1) != 43
            || cmvIdGridIgL10(1) != 41
            || cmvIdGridIgL11(1) != 40
        )
            ++bad;
        // the monster-level-6 row - 10 up to 30 in even steps, as scanned
        // (folio 28) (folio 28)
    if (cmvIdGridMonLevel(2) != 6
            || cmvIdGridIgL1(2) != 10
            || cmvIdGridIgL2(2) != 12
            || cmvIdGridIgL3(2) != 14
            || cmvIdGridIgL4(2) != 16
            || cmvIdGridIgL5(2) != 18
            || cmvIdGridIgL6(2) != 20
            || cmvIdGridIgL7(2) != 22
            || cmvIdGridIgL8(2) != 24
            || cmvIdGridIgL9(2) != 26
            || cmvIdGridIgL10(2) != 28
            || cmvIdGridIgL11(2) != 30
        )
            ++bad;
        // the 01-50 band - a 3 out of 10 chance of falling (folio 28) (folio
        // 28)
    if (cmvIdBadLo(0) != 1
            || cmvIdBadHi(0) != 50
            || cmvIdBadOutOf10(0) != 3
            || cmvIdiotBadDexCount() != 4
        )
            ++bad;
        // the 51-75 band - a 5 out of 10 chance (folio 28) (folio 28)
    if (cmvIdBadLo(1) != 51
            || cmvIdBadHi(1) != 75
            || cmvIdBadOutOf10(1) != 5
        )
            ++bad;
        // the 76-90 band - a 7 out of 10 chance (folio 28) (folio 28)
    if (cmvIdBadLo(2) != 76
            || cmvIdBadHi(2) != 90
            || cmvIdBadOutOf10(2) != 7
        )
            ++bad;
        // the 91-00 band pinned as 100 - a 10 out of 10 chance (folio 28)
        // (folio 28)
    if (cmvIdBadLo(3) != 91
            || cmvIdBadHi(3) != 100
            || cmvIdBadOutOf10(3) != 10
        )
            ++bad;
        // the 1st level Dummy - 0 experience points (folio 28) (folio 28)
    if (cmvIdLvlIndex(0) != 1
            || cmvIdLvlXp(0) != 0
            || cmvIdiotLadderCount() != 12
        )
            ++bad;
        // the 2nd level Dope - 1,001 experience points (folio 28) (folio 28)
    if (cmvIdLvlIndex(1) != 2
            || cmvIdLvlXp(1) != 1001
        )
            ++bad;
        // the 3rd level Dolt - 2,623 experience points (folio 28) (folio 28)
    if (cmvIdLvlIndex(2) != 3
            || cmvIdLvlXp(2) != 2623
        )
            ++bad;
        // the 4th level Dullard - 6,157 experience points (folio 28) (folio
        // 28)
    if (cmvIdLvlIndex(3) != 4
            || cmvIdLvlXp(3) != 6157
        )
            ++bad;
        // the 5th level Cluck - 9,738 experience points (folio 28) (folio 28)
    if (cmvIdLvlIndex(4) != 5
            || cmvIdLvlXp(4) != 9738
        )
            ++bad;
        // the 6th level Klutz - 11,432 experience points (folio 28) (folio
        // 28)
    if (cmvIdLvlIndex(5) != 6
            || cmvIdLvlXp(5) != 11432
        )
            ++bad;
        // the 7th level Cretin - 19,832 experience points (folio 28) (folio
        // 28)
    if (cmvIdLvlIndex(6) != 7
            || cmvIdLvlXp(6) != 19832
        )
            ++bad;
        // the 8th level Weirdo - 30,876 experience points (folio 28) (folio
        // 28)
    if (cmvIdLvlIndex(7) != 8
            || cmvIdLvlXp(7) != 30876
        )
            ++bad;
        // the 9th level Nut - 61,423 experience points (folio 28) (folio 28)
    if (cmvIdLvlIndex(8) != 9
            || cmvIdLvlXp(8) != 61423
        )
            ++bad;
        // the 10th level Fool - 88,749 experience points (folio 28) (folio
        // 28)
    if (cmvIdLvlIndex(9) != 10
            || cmvIdLvlXp(9) != 88749
        )
            ++bad;
        // the 11th level Imbecile - 120,456 experience points (folio 28)
        // (folio 28)
    if (cmvIdLvlIndex(10) != 11
            || cmvIdLvlXp(10) != 120456
        )
            ++bad;
        // the 12th level Idiot - 200,101 experience points (folio 28) (folio
        // 28)
    if (cmvIdLvlIndex(11) != 12
            || cmvIdLvlXp(11) != 200101
        )
            ++bad;
        // the Intelligence 1-3 row - saving throw 4 (folio 29) (folio 29)
    if (cmvJs1Lo(0) != 1
            || cmvJs1Hi(0) != 3
            || cmvJs1Save(0) != 4
            || cmvJesterSavesHighCount() != 7
        )
            ++bad;
        // the Intelligence 4-6 row - saving throw 6 (folio 29) (folio 29)
    if (cmvJs1Lo(1) != 4
            || cmvJs1Hi(1) != 6
            || cmvJs1Save(1) != 6
        )
            ++bad;
        // the Intelligence 7-9 row - saving throw 8 (folio 29) (folio 29)
    if (cmvJs1Lo(2) != 7
            || cmvJs1Hi(2) != 9
            || cmvJs1Save(2) != 8
        )
            ++bad;
        // the Intelligence 10-12 row - saving throw 10 (folio 29) (folio 29)
    if (cmvJs1Lo(3) != 10
            || cmvJs1Hi(3) != 12
            || cmvJs1Save(3) != 10
        )
            ++bad;
        // the Intelligence 13-15 row - saving throw 14 (folio 29) (folio 29)
    if (cmvJs1Lo(4) != 13
            || cmvJs1Hi(4) != 15
            || cmvJs1Save(4) != 14
        )
            ++bad;
        // the Intelligence 16-17 row - saving throw 16 (folio 29) (folio 29)
    if (cmvJs1Lo(5) != 16
            || cmvJs1Hi(5) != 17
            || cmvJs1Save(5) != 16
        )
            ++bad;
        // the Intelligence 18 row - saving throw 18 (folio 29) (folio 29)
    if (cmvJs1Lo(6) != 18
            || cmvJs1Hi(6) != 18
            || cmvJs1Save(6) != 18
        )
            ++bad;
        // the Intelligence 1-3 row - saving throw 19 (folio 29) (folio 29)
    if (cmvJs2Lo(0) != 1
            || cmvJs2Hi(0) != 3
            || cmvJs2Save(0) != 19
            || cmvJesterSavesLowCount() != 7
        )
            ++bad;
        // the Intelligence 4-6 row - saving throw 16 (folio 29) (folio 29)
    if (cmvJs2Lo(1) != 4
            || cmvJs2Hi(1) != 6
            || cmvJs2Save(1) != 16
        )
            ++bad;
        // the Intelligence 7-9 row - saving throw 14 (folio 29) (folio 29)
    if (cmvJs2Lo(2) != 7
            || cmvJs2Hi(2) != 9
            || cmvJs2Save(2) != 14
        )
            ++bad;
        // the Intelligence 10-12 row - saving throw 11 (folio 29) (folio 29)
    if (cmvJs2Lo(3) != 10
            || cmvJs2Hi(3) != 12
            || cmvJs2Save(3) != 11
        )
            ++bad;
        // the Intelligence 13-15 row - saving throw 9 (folio 29) (folio 29)
    if (cmvJs2Lo(4) != 13
            || cmvJs2Hi(4) != 15
            || cmvJs2Save(4) != 9
        )
            ++bad;
        // the Intelligence 16-17 row - saving throw 7 (folio 29) (folio 29)
    if (cmvJs2Lo(5) != 16
            || cmvJs2Hi(5) != 17
            || cmvJs2Save(5) != 7
        )
            ++bad;
        // the Intelligence 18 row - saving throw 5 (folio 29) (folio 29)
    if (cmvJs2Lo(6) != 18
            || cmvJs2Hi(6) != 18
            || cmvJs2Save(6) != 5
        )
            ++bad;
        // the 2,000 xp row - column 1 at 2, column 2 at 1 (folio 29)
    if (cmvJxXp(0) != 2000
            || cmvJxC1(0) != 2
            || cmvJxC2(0) != 1
            || cmvJxC3(0) != 0
            || cmvJxC4(0) != 0
            || cmvJxC5(0) != 0
            || cmvJxC6(0) != 0
            || cmvJxC7(0) != 0
            || cmvJxC8(0) != 0
            || cmvJesterXpGridCount() != 14
        )
            ++bad;
        // the 4,000 xp row - column 1 at 3, column 2 at 2 (folio 29)
    if (cmvJxXp(1) != 4000
            || cmvJxC1(1) != 3
            || cmvJxC2(1) != 2
            || cmvJxC3(1) != 0
            || cmvJxC4(1) != 0
            || cmvJxC5(1) != 0
            || cmvJxC6(1) != 0
            || cmvJxC7(1) != 0
            || cmvJxC8(1) != 0
        )
            ++bad;
        // the 8,000 xp row - column 1 at 4, column 2 at 3, column 3 at 1
        // (folio 29)
    if (cmvJxXp(2) != 8000
            || cmvJxC1(2) != 4
            || cmvJxC2(2) != 3
            || cmvJxC3(2) != 1
            || cmvJxC4(2) != 0
            || cmvJxC5(2) != 0
            || cmvJxC6(2) != 0
            || cmvJxC7(2) != 0
            || cmvJxC8(2) != 0
        )
            ++bad;
        // the 16,000 xp row - column 1 at 5, column 2 at 4, column 3 at 2
        // (folio 29)
    if (cmvJxXp(3) != 16000
            || cmvJxC1(3) != 5
            || cmvJxC2(3) != 4
            || cmvJxC3(3) != 2
            || cmvJxC4(3) != 0
            || cmvJxC5(3) != 0
            || cmvJxC6(3) != 0
            || cmvJxC7(3) != 0
            || cmvJxC8(3) != 0
        )
            ++bad;
        // the 32,000 xp row - column 1 at 6, column 2 at 4, column 3 at 2,
        // column 4 at 1 (folio 29)
    if (cmvJxXp(4) != 32000
            || cmvJxC1(4) != 6
            || cmvJxC2(4) != 4
            || cmvJxC3(4) != 2
            || cmvJxC4(4) != 1
            || cmvJxC5(4) != 0
            || cmvJxC6(4) != 0
            || cmvJxC7(4) != 0
            || cmvJxC8(4) != 0
        )
            ++bad;
        // the 64,000 xp row - column 1 at 7, column 2 at 4, column 3 at 3,
        // column 4 at 2 (folio 29)
    if (cmvJxXp(5) != 64000
            || cmvJxC1(5) != 7
            || cmvJxC2(5) != 4
            || cmvJxC3(5) != 3
            || cmvJxC4(5) != 2
            || cmvJxC5(5) != 0
            || cmvJxC6(5) != 0
            || cmvJxC7(5) != 0
            || cmvJxC8(5) != 0
        )
            ++bad;
        // the 128,000 xp row - column 1 at 8, column 2 at 5, column 3 at 4,
        // column 4 at 3, column 5 at 1 (folio 29)
    if (cmvJxXp(6) != 128000
            || cmvJxC1(6) != 8
            || cmvJxC2(6) != 5
            || cmvJxC3(6) != 4
            || cmvJxC4(6) != 3
            || cmvJxC5(6) != 1
            || cmvJxC6(6) != 0
            || cmvJxC7(6) != 0
            || cmvJxC8(6) != 0
        )
            ++bad;
        // the 228,000 xp row - column 1 at 9, column 2 at 5, column 3 at 4,
        // column 4 at 4, column 5 at 2 (folio 29)
    if (cmvJxXp(7) != 228000
            || cmvJxC1(7) != 9
            || cmvJxC2(7) != 5
            || cmvJxC3(7) != 4
            || cmvJxC4(7) != 4
            || cmvJxC5(7) != 2
            || cmvJxC6(7) != 0
            || cmvJxC7(7) != 0
            || cmvJxC8(7) != 0
        )
            ++bad;
        // the 328,000 xp row - column 1 at 10, column 2 at 5, column 3 at 5,
        // column 4 at 4, column 5 at 3, column 6 at 1 (folio 29)
    if (cmvJxXp(8) != 328000
            || cmvJxC1(8) != 10
            || cmvJxC2(8) != 5
            || cmvJxC3(8) != 5
            || cmvJxC4(8) != 4
            || cmvJxC5(8) != 3
            || cmvJxC6(8) != 1
            || cmvJxC7(8) != 0
            || cmvJxC8(8) != 0
        )
            ++bad;
        // the 428,000 xp row - column 1 at 11, column 2 at 6, column 3 at 5,
        // column 4 at 5, column 5 at 4, column 6 at 2, column 7 at 1 (folio
        // 29)
    if (cmvJxXp(9) != 428000
            || cmvJxC1(9) != 11
            || cmvJxC2(9) != 6
            || cmvJxC3(9) != 5
            || cmvJxC4(9) != 5
            || cmvJxC5(9) != 4
            || cmvJxC6(9) != 2
            || cmvJxC7(9) != 1
            || cmvJxC8(9) != 0
        )
            ++bad;
        // the 528,000 xp row - column 1 at 12, column 2 at 6, column 3 at 5,
        // column 4 at 5, column 5 at 5, column 6 at 3, column 7 at 1 (folio
        // 29)
    if (cmvJxXp(10) != 528000
            || cmvJxC1(10) != 12
            || cmvJxC2(10) != 6
            || cmvJxC3(10) != 5
            || cmvJxC4(10) != 5
            || cmvJxC5(10) != 5
            || cmvJxC6(10) != 3
            || cmvJxC7(10) != 1
            || cmvJxC8(10) != 0
        )
            ++bad;
        // the 628,000 xp row - column 1 at 13, column 2 at 6, column 3 at 6,
        // column 4 at 5, column 5 at 5, column 6 at 4, column 7 at 2, column
        // 8 at 1 (folio 29)
    if (cmvJxXp(11) != 628000
            || cmvJxC1(11) != 13
            || cmvJxC2(11) != 6
            || cmvJxC3(11) != 6
            || cmvJxC4(11) != 5
            || cmvJxC5(11) != 5
            || cmvJxC6(11) != 4
            || cmvJxC7(11) != 2
            || cmvJxC8(11) != 1
        )
            ++bad;
        // the 728,000 xp row - column 1 at 14, column 2 at 7, column 3 at 6,
        // column 4 at 6, column 5 at 5, column 6 at 4, column 7 at 3, column
        // 8 at 2 (folio 29)
    if (cmvJxXp(12) != 728000
            || cmvJxC1(12) != 14
            || cmvJxC2(12) != 7
            || cmvJxC3(12) != 6
            || cmvJxC4(12) != 6
            || cmvJxC5(12) != 5
            || cmvJxC6(12) != 4
            || cmvJxC7(12) != 3
            || cmvJxC8(12) != 2
        )
            ++bad;
        // the 828,000 xp row - column 1 at 15, column 2 at 7, column 3 at 6,
        // column 4 at 6, column 5 at 6, column 6 at 5, column 7 at 4, column
        // 8 at 2 (folio 29)
    if (cmvJxXp(13) != 828000
            || cmvJxC1(13) != 15
            || cmvJxC2(13) != 7
            || cmvJxC3(13) != 6
            || cmvJxC4(13) != 6
            || cmvJxC5(13) != 6
            || cmvJxC6(13) != 5
            || cmvJxC7(13) != 4
            || cmvJxC8(13) != 2
        )
            ++bad;
        // the dex 3-4 row - hit -1, missile -2, damage -1, defense -1 (folio
        // 30) (folio 30)
    if (cmvClDexLo(0) != 3
            || cmvClDexHi(0) != 4
            || cmvClHit(0) != -1
            || cmvClMissile(0) != -2
            || cmvClDamage(0) != -1
            || cmvClDefense(0) != -1
            || cmvClineDexCount() != 12
        )
            ++bad;
        // the dex 5-8 row - missile -1 only (folio 30) (folio 30)
    if (cmvClDexLo(1) != 5
            || cmvClDexHi(1) != 8
            || cmvClHit(1) != 0
            || cmvClMissile(1) != -1
            || cmvClDamage(1) != 0
            || cmvClDefense(1) != 0
        )
            ++bad;
        // the dex 9-12 row - all nil (folio 30) (folio 30)
    if (cmvClDexLo(2) != 9
            || cmvClDexHi(2) != 12
            || cmvClHit(2) != 0
            || cmvClMissile(2) != 0
            || cmvClDamage(2) != 0
            || cmvClDefense(2) != 0
        )
            ++bad;
        // the dex 13-14 row - missile +1 (folio 30) (folio 30)
    if (cmvClDexLo(3) != 13
            || cmvClDexHi(3) != 14
            || cmvClHit(3) != 0
            || cmvClMissile(3) != 1
            || cmvClDamage(3) != 0
            || cmvClDefense(3) != 0
        )
            ++bad;
        // the dex 15 row - missile +1, defense +1 (folio 30) (folio 30)
    if (cmvClDexLo(4) != 15
            || cmvClDexHi(4) != 15
            || cmvClHit(4) != 0
            || cmvClMissile(4) != 1
            || cmvClDamage(4) != 0
            || cmvClDefense(4) != 1
        )
            ++bad;
        // the dex 16 row - hit +1, missile +1, defense +2 (folio 30) (folio
        // 30)
    if (cmvClDexLo(5) != 16
            || cmvClDexHi(5) != 16
            || cmvClHit(5) != 1
            || cmvClMissile(5) != 1
            || cmvClDamage(5) != 0
            || cmvClDefense(5) != 2
        )
            ++bad;
        // the dex 17 row - hit +1, missile +2, damage -1, defense +3 (folio
        // 30) (folio 30)
    if (cmvClDexLo(6) != 17
            || cmvClDexHi(6) != 17
            || cmvClHit(6) != 1
            || cmvClMissile(6) != 2
            || cmvClDamage(6) != -1
            || cmvClDefense(6) != 3
        )
            ++bad;
        // the dex 18 row - hit +1, missile +2, damage +1, defense +4 (folio
        // 30) (folio 30)
    if (cmvClDexLo(7) != 18
            || cmvClDexHi(7) != 18
            || cmvClHit(7) != 1
            || cmvClMissile(7) != 2
            || cmvClDamage(7) != 1
            || cmvClDefense(7) != 4
        )
            ++bad;
        // the 51-75 percent row - hit +2, missile +3, damage +2, defense +4,
        // as scanned (folio 30) (folio 30)
    if (cmvClDexLo(8) != 51
            || cmvClDexHi(8) != 75
            || cmvClHit(8) != 2
            || cmvClMissile(8) != 3
            || cmvClDamage(8) != 2
            || cmvClDefense(8) != 4
        )
            ++bad;
        // the 76-90 row - hit +2, missile +3, damage +2, defense +4, as
        // scanned (folio 30) (folio 30)
    if (cmvClDexLo(9) != 76
            || cmvClDexHi(9) != 90
            || cmvClHit(9) != 2
            || cmvClMissile(9) != 3
            || cmvClDamage(9) != 2
            || cmvClDefense(9) != 4
        )
            ++bad;
        // the 91-99 row - hit +2, missile +4, damage +2, defense +5, as
        // scanned (folio 30) (folio 30)
    if (cmvClDexLo(10) != 91
            || cmvClDexHi(10) != 99
            || cmvClHit(10) != 2
            || cmvClMissile(10) != 4
            || cmvClDamage(10) != 2
            || cmvClDefense(10) != 5
        )
            ++bad;
        // the 00 row pinned as 100 - hit +3, missile +5, damage +3, defense
        // +6, as scanned (folio 30) (folio 30)
    if (cmvClDexLo(11) != 100
            || cmvClDexHi(11) != 100
            || cmvClHit(11) != 3
            || cmvClMissile(11) != 5
            || cmvClDamage(11) != 3
            || cmvClDefense(11) != 6
        )
            ++bad;
        printf("R899 comedy and small-variants audit: bad %d\n", bad);
        if (bad) return 1;
    }
