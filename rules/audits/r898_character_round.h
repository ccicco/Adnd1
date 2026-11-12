    // ---- R898 character round audit ----
    // THE CHARACTER ROUND - round D of the issue-3 walk. Smith's new-view
    // Dwarves: the nine-level Fighting Man ladder (Dwarf through Dwarf King
    // at 10+1 and 320,000, the printed dice-plus forms split to base and
    // bonus, fighting as Man+2 down to Men and back), the 17-Strength 7th and
    // 18-Strength 8th gates with the 12-Intelligence 12-Wisdom footnote
    // pinned as scanned, the seven families and the Durin 7-8 of the d8, the
    // kingship rules, the Greyhawk cleric option (15 Wisdom, 7th at 17, 8th
    // at 18, points on a d8), the thief's d6, the forbidden class list, the
    // fourteen abilities (the 4-level saving-throw bonus, the +3 War Hammer,
    // the 1-4 of a d6 detection with new construction automatic, the
    // Goblin-Orc-Hobgoblin tongues with Gnome and Kobold spoken, the Giant
    // Class +1/-1, the gem judging and the magic feeling, the Smith 9/9,
    // Armorer 12/9 and Engineer 15 trade gates, the crossbow-and-shortbow
    // rule, the six regular weapons with others at -1, the 17-Dexterity swim
    // against the water fear, and the 12-Intelligence horse reluctance across
    // the folio break), the reaction modifiers (the Goblins-and-Orcs auto
    // attack pinned as the sentinel 9, the Sindar-Silvan-Elves-and-men -2,
    // the others -1, the Hobbits-and-Noldor 0, the different Folk +1, the
    // same Folk +2 and never attacking one's own), and the folk wisdom
    // (maturity around 50, about 250 years, the hates, the unbroken oath).
    // Stock and Lane's birth tables: social class, sibling rank with the
    // orphan check and the first-son and bastard percents, the four wealth
    // ladders (with the OCR's split Very-Wealthy rows pinned as scanned), the
    // father's occupation routing, the three skills groups with the Group 1
    // banding notes, the first-five prohibition and the no-player-Adventurer
    // rule, the Interpreter, Soldier and Orator edges, the twelve crafts, the
    // nobility rolls (father's title, the royalty kinship with the immediate
    // family's 1000 and 100, the never-orphan, raise-to-wealth, the reroll
    // ignoring 96-00 and the one-notch title raise, the five position tables
    // with their adventurer percents), the adventurer fathers (levels and
    // classes by social class), the race rolls (Table 1 by class, the dice
    // grid, the Table 2 requirement bands with 'any' converted to 3-18), and
    // the previous-experience multipliers through the Noble x130. Pulsipher's
    // Eldar deltas: the Silvan frame (no requirements, all D&D powers,
    // disease and aging immunity, 8th/9th fighter and 4th/5th magic-user,
    // Lawful or Neutral never evil), the Sindar (average abilities and 63
    // total, the 8th/9th magic-user, the 4th/5th/6th fighter), the Eldar
    // proper (13 Wisdom, 67 total, the 11th one-path choice), the Eldar
    // powers (the language per intelligence point, the calmed animals, the
    // bird speech, the mind-to-mind range, the keen eyes, the True Sight with
    // its per-level percents and the unawareness), the over-sea doctrine (one
    // in a thousand, one in a hundred, one in ten thousand, no roll until
    // maximum level, the Silvan never), the half-elf rule, and the deltas
    // against the R888 Smith pin never silent. HONEST BOUNDARIES: the OCR's
    // split and column-shifted rows ride as scanned; the royalty table's
    // interleaved wealth labels pin nothing beyond the bands; the sibling
    // note 'No one receives Allowance' garbles and pins nothing; the crafts
    // pin as a count; all three clusters ride the variant layer.
    {
        using namespace rules;
        int bad = 0;
    if (chrDwarfLadderLevels() != 9
            || chrDwfStrFor7th() != 17
            || chrDwfStrFor8th() != 18
            || chrDwfKingIntMin() != 12
            || chrDwfKingWisMin() != 12
            || chrDwarfFamilies() != 7
            || chrDwarfTribeDieSides() != 8
            || chrDwarfTribeDurinLo() != 7
            || chrDwarfClericWisMin() != 15
            || chrDwarfCleric7thWis() != 17
            || chrDwarfCleric8thWis() != 18
            || chrDwarfClericHitDie() != 8
            || chrDwarfThiefHitDie() != 6
            || chrDwarfSaveBonusLevels() != 4
            || chrDwarfWarHammerBonus() != 3
            || chrDwarfSlantDieSides() != 6
            || chrDwarfSlantRollMax() != 4
            || chrDwarfGiantClassHitMod() != 1
            || chrDwarfGiantClassAcMod() != 1
            || chrDwarfSmithIntMin() != 9
            || chrDwarfSmithStrMin() != 9
            || chrDwarfArmorerIntMin() != 12
            || chrDwarfArmorerStrMin() != 9
            || chrDwarfEngineerIntMin() != 15
            || chrDwarfOtherWeaponHitMod() != 1
            || chrDwarfSwimDexMin() != 17
            || chrDwarfHorseIntMin() != 12
            || chrDwarfMaturityAge() != 50
            || chrDwarfLifespanYears() != 250
            || chrDwarfReactionCount() != 6
            || chrBirthSkillsGroups() != 3
            || chrBirthAllowanceMonths() != 12
            || chrBirthAllowanceLevelCap() != 3
            || chrBirthClassCount() != 4
            || chrSiblingBandCount() != 5
            || chrSiblingDieSides() != 8
            || chrOrphanDieSides() != 6
            || chrOrphanRoll() != 1
            || chrBirthFirstSonPct() != 10
            || chrBirthBastardPct() != 10
            || chrRankCommonerCount() != 4
            || chrRankMerchantCount() != 5
            || chrRankGentlemanCount() != 5
            || chrRankNobleCount() != 6
            || chrFatherOccCount() != 4
            || chrSkillGroup1Count() != 10
            || chrSkillsPeasantMax() != 70
            || chrSkillsWellToDoMin() != 31
            || chrSkillsWealthyMin() != 52
            || chrSkillGroup2Count() != 10
            || chrSkillGroup3Count() != 20
            || chrSkillsInterpreterIntBonus() != 3
            || chrSkillsSoldierHitBonus() != 1
            || chrSkillsSoldierLevelCap() != 4
            || chrSkillsOratorReactionBonus() != 1
            || chrCraftsCount() != 12
            || chrSkillsDieSides() != 100
            || chrNobleTitleCount() != 6
            || chrRoyaltyKinCount() != 5
            || chrRoyaltyImmediateInitial() != 1000
            || chrRoyaltyImmediateAllow() != 100
            || chrPosKnightCount() != 5
            || chrKnightAdventurerPct() != 30
            || chrPosBaronCount() != 6
            || chrBaronAdventurerPct() != 25
            || chrPosCountCount() != 6
            || chrCountAdventurerPct() != 20
            || chrPosMarquisCount() != 7
            || chrMarquisAdventurerPct() != 15
            || chrPosDukeCount() != 7
            || chrDukeAdventurerPct() != 15
            || chrAdvComLevelsCount() != 4
            || chrAdvMerLevelsCount() != 6
            || chrAdvGenLevelsCount() != 8
            || chrAdvNobLevelsCount() != 9
            || chrAdvComClassCount() != 2
            || chrAdvMerClassCount() != 4
            || chrAdvGenClassCount() != 4
            || chrAdvNobClassCount() != 4
            || chrRaceCommonerCount() != 5
            || chrRaceMerchantCount() != 4
            || chrRaceGentleNobleCount() != 5
            || chrRaceTable1DieSides() != 12
            || chrRaceDiceCount() != 6
            || chrRaceReqCount() != 6
            || chrPrevComCount() != 4
            || chrPrevMerCount() != 5
            || chrPrevGenCount() != 6
            || chrPrevNobCount() != 7
            || chrSilvanFighterMax() != 8
            || chrSilvanFighterMaxStr18() != 9
            || chrSilvanMuMax() != 4
            || chrSilvanMuMaxInt18() != 5
            || chrSindarStatMin() != 9
            || chrSindarTotalMin() != 63
            || chrSindarMuMax() != 8
            || chrSindarMuMaxInt18() != 9
            || chrSindarFighterMax() != 4
            || chrSindarFighterMaxStr17() != 5
            || chrSindarFighterMaxStr18() != 6
            || chrEldarWisMin() != 13
            || chrEldarTotalMin() != 67
            || chrEldarMuMax() != 11
            || chrEldarFighterMax() != 11
            || chrEldarMindRangePerLevel() != 5
            || chrEldarPhantasmalPerLevel() != 1
            || chrEldarIllusionPctPerLevel() != 5
            || chrEldarPolymorphPctPerLevel() != 3
            || chrEldarShapeChangePctPerLevel() != 1
            || chrSeaEldarDenominator() != 1000
            || chrSeaSindarSeenDenominator() != 100
            || chrSeaSindarUnseenDenominator() != 10000
            || !chrDwarfKingshipFirst()
            || !chrDwarfKingBlocksLevel()
            || !chrDwarfClericsAllowed()
            || !chrDwarfThievesGreyhawk()
            || !chrDwarfForbiddenClasses()
            || !chrDwarfNewConstructionAuto()
            || !chrDwarfUnderstandsGobOrcHob()
            || !chrDwarfSpeaksGnomeKobold()
            || !chrDwarfJudgesGems()
            || !chrDwarfFeelsMagic()
            || !chrDwarfBowsOnly()
            || !chrDwarfRegularWeapons()
            || !chrDwarfWaterFear()
            || !chrDwarfHatesOrcsGoblins()
            || !chrDwarfOathsNeverBroken()
            || !chrDwarfNeverAttackOwnFolk()
            || !chrBirthFirstSonInherits()
            || !chrSkillsFatherOccupation()
            || !chrSkillsGroup3FirstFiveProhibited()
            || !chrSkillsNoPlayerAdventurer()
            || !chrRoyaltyNeverOrphan()
            || !chrRoyaltyRaiseRank()
            || !chrRoyaltyRerollIgnore()
            || !chrRoyaltyTitleOneNotch()
            || !chrNobilityNonHumanEarlCap()
            || !chrRaceTable2Preferred()
            || !chrRaceVariant9To18()
            || !chrRaceLimitByRequirements()
            || !chrSilvanNoReqs()
            || !chrSilvanDdPowers()
            || !chrSilvanDiseaseImmune()
            || !chrSilvanAgingImmune()
            || !chrSilvanLawfulOrNeutral()
            || !chrEldarOnePathOnly()
            || !chrEldarLangPerIntPoint()
            || !chrEldarCalmAnimals()
            || !chrEldarBirdSpeech()
            || !chrEldarKeenEyes()
            || !chrEldarHiddenOptional()
            || !chrEldarUnawareOnSuccess()
            || !chrSeaWaitUntilMaxLevel()
            || !chrSilvanNeverCrossSea()
            || !chrHalfElfSameAsEldar()
            || !chrEldarAllLawfulGood()
            || !chrEldarNoldorShorthand()
            || !chrEldarRejectsSmithDelta()
        )
            ++bad;
        // the Dwarf Fighting Man ladder - Dwarves are not the poor fighters
        // many claim: 1st level 1+2 fighting as Man+2 through Dwarf King at
        // 10+1 and 320,000 (folio 26)
        int CCrDwfL[9][7] = {
            {1,1,1,2,0,1,2},
            {2,2,2,1,2500,2,1},
            {3,3,3,0,5000,3,0},
            {4,4,4,0,10000,4,0},
            {5,5,5,0,20000,5,0},
            {6,6,6,0,40000,6,0},
            {7,7,7,1,80000,7,1},
            {8,8,8,2,160000,8,2},
            {9,9,10,1,320000,10,1},
            };
        for (int b = 0;
             b < chrDwarfLadderLevels();
             ++b) {
            int vals[7];
            vals[0] = chrDwfLvlLevel(b);
            vals[1] = chrDwfLvlNameCode(b);
            vals[2] = chrDwfLvlHitBase(b);
            vals[3] = chrDwfLvlHitBonus(b);
            vals[4] = chrDwfLvlXp(b);
            vals[5] = chrDwfLvlFightsAs(b);
            vals[6] = chrDwfLvlFightsAsBonus(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CCrDwfL[b][c])
                    ++bad;
            }
        }
        // the Dwarf reaction modifiers - Goblins and Orcs are an AUTO ATTACK
        // pinned as the sentinel 9; minus 2 for Sindar, Silvan Elves and all
        // men; minus 1 for all others except those listed; plus 0 for Hobbits
        // and Noldor Elves; plus 1 for Dwarves of a different Folk; plus 2
        // for the same Folk (folio 27)
        int CCrDwfR[6][2] = {
            {1,9},
            {2,-2},
            {3,-1},
            {4,0},
            {5,1},
            {6,2},
            };
        for (int b = 0;
             b < chrDwarfReactionCount();
             ++b) {
            int vals[2];
            vals[0] = chrDwfReactCode(b);
            vals[1] = chrDwfReactMod(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CCrDwfR[b][c])
                    ++bad;
            }
        }
        // the social class roll - 01-30 Commoner, 31-85 Merchant, 86-95
        // Gentleman, 96-00 Noble (folio 14)
        int CCrBC[4][3] = {
            {1,30,1},
            {31,85,2},
            {86,95,3},
            {96,100,4},
            };
        for (int b = 0;
             b < chrBirthClassCount();
             ++b) {
            int vals[3];
            vals[0] = chrBCLo(b);
            vals[1] = chrBCHi(b);
            vals[2] = chrBCCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrBC[b][c])
                    ++bad;
            }
        }
        // the sibling rank on a d8 - 1 or 2 a 1st, 3 or 4 a 2nd, 5 a 3rd, 6 a
        // 4th, 7 or 8 a bastard (folio 14)
        int CCrSib[5][3] = {
            {1,2,1},
            {3,4,2},
            {5,5,3},
            {6,6,4},
            {7,8,5},
            };
        for (int b = 0;
             b < chrSiblingBandCount();
             ++b) {
            int vals[3];
            vals[0] = chrSibLo(b);
            vals[1] = chrSibHi(b);
            vals[2] = chrSibCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrSib[b][c])
                    ++bad;
            }
        }
        // the Commoner social rank - Peasant, Average, Well-to-do, Wealthy;
        // every Commoner skill letter is A (folio 15)
        int CCrCom[4][6] = {
            {1,25,10,0,0,1},
            {26,40,30,1,15,1},
            {41,70,60,5,50,1},
            {71,100,100,10,100,1},
            };
        for (int b = 0;
             b < chrRankCommonerCount();
             ++b) {
            int vals[6];
            vals[0] = chrComLo(b);
            vals[1] = chrComHi(b);
            vals[2] = chrComInitial(b);
            vals[3] = chrComAllow(b);
            vals[4] = chrComInherit(b);
            vals[5] = chrComSkills(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CCrCom[b][c])
                    ++bad;
            }
        }
        // the Merchant social rank - Small, Average, Well-to-do, Wealthy,
        // Very Wealthy; the Very Wealthy row split across two OCR lines rides
        // as scanned (folio 15)
        int CCrMer[5][6] = {
            {1,25,50,5,100,2},
            {26,60,100,10,150,2},
            {61,80,120,15,200,2},
            {81,95,170,20,250,2},
            {96,100,200,30,400,3},
            };
        for (int b = 0;
             b < chrRankMerchantCount();
             ++b) {
            int vals[6];
            vals[0] = chrMerLo(b);
            vals[1] = chrMerHi(b);
            vals[2] = chrMerInitial(b);
            vals[3] = chrMerAllow(b);
            vals[4] = chrMerInherit(b);
            vals[5] = chrMerSkills(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CCrMer[b][c])
                    ++bad;
            }
        }
        // the Gentleman social rank - Impoverished, Average, Well-to-do,
        // Wealthy, Very Wealthy; the Very Wealthy row's OCR column shift
        // rides as scanned with the D letter (folio 15)
        int CCrGen[5][6] = {
            {1,20,70,0,75,2},
            {21,65,100,5,150,3},
            {66,90,150,15,250,3},
            {91,95,200,20,350,3},
            {96,100,250,35,600,4},
            };
        for (int b = 0;
             b < chrRankGentlemanCount();
             ++b) {
            int vals[6];
            vals[0] = chrGenLo(b);
            vals[1] = chrGenHi(b);
            vals[2] = chrGenInitial(b);
            vals[3] = chrGenAllow(b);
            vals[4] = chrGenInherit(b);
            vals[5] = chrGenSkills(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CCrGen[b][c])
                    ++bad;
            }
        }
        // the Noble social rank - Impoverished, Poor, Average, Well-to-do,
        // Wealthy at 96-97, Very Wealthy at 98-00; the Very Wealthy
        // inheritance's OCR column shift rides as scanned (folio 15)
        int CCrNob[6][6] = {
            {1,20,80,0,100,4},
            {21,40,120,10,150,4},
            {41,85,200,25,300,5},
            {86,95,250,35,450,5},
            {96,97,300,45,700,6},
            {98,100,400,60,1000,6},
            };
        for (int b = 0;
             b < chrRankNobleCount();
             ++b) {
            int vals[6];
            vals[0] = chrNobLo(b);
            vals[1] = chrNobHi(b);
            vals[2] = chrNobInitial(b);
            vals[3] = chrNobAllow(b);
            vals[4] = chrNobInherit(b);
            vals[5] = chrNobSkills(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CCrNob[b][c])
                    ++bad;
            }
        }
        // the father's occupation table - Commoner 1, Merchant 2, Gentleman
        // 3, Noble 3; the number obtained indicates which skills table to use
        // (folio 15)
        int CCrFth[4][2] = {
            {1,1},
            {2,2},
            {3,3},
            {4,3},
            };
        for (int b = 0;
             b < chrFatherOccCount();
             ++b) {
            int vals[2];
            vals[0] = chrFthClassCode(b);
            vals[1] = chrFthOccGroup(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CCrFth[b][c])
                    ++bad;
            }
        }
        // the Group 1 skills - Vagabond, Farmer/Serf, Tinker, Miner,
        // Woodsman, Sailor, Fisherman, Craftsman, Soldier, Adventurer; the
        // Peasant may not roll above 70, the Well-to-do not below 31, the
        // Wealthy not below 52 with 52-55 equalling Adventurer (folio 15)
        int CCrSk1[10][3] = {
            {1,10,1},
            {11,55,2},
            {56,60,3},
            {61,65,4},
            {66,70,5},
            {71,75,6},
            {76,85,7},
            {86,95,8},
            {96,99,9},
            {100,100,10},
            };
        for (int b = 0;
             b < chrSkillGroup1Count();
             ++b) {
            int vals[3];
            vals[0] = chrSk1Lo(b);
            vals[1] = chrSk1Hi(b);
            vals[2] = chrSk1Code(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrSk1[b][c])
                    ++bad;
            }
        }
        // the Group 2 skills - Normal Merchant, Ind. Craftsman, Scribe,
        // Seaman, Slaver, Animal Trainer, Shipwright, Master Merchant, Bird
        // Trainer, Adventurer; the Independent Craftsman owns his own shop, a
        // player would know a craft, and the father rolls under Crafts (folio
        // 15)
        int CCrSk2[10][3] = {
            {1,35,1},
            {36,60,2},
            {61,65,3},
            {66,70,4},
            {71,75,5},
            {76,80,6},
            {81,85,7},
            {86,90,8},
            {91,95,9},
            {96,100,10},
            };
        for (int b = 0;
             b < chrSkillGroup2Count();
             ++b) {
            int vals[3];
            vals[0] = chrSk2Lo(b);
            vals[1] = chrSk2Hi(b);
            vals[2] = chrSk2Code(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrSk2[b][c])
                    ++bad;
            }
        }
        // the Group 3 skills - Assassin/Spytracker, Sheriff, Magistrate,
        // Sage, Alchemist, Physician, Artist/Sculptor/Musician, Engineer,
        // Soldier, Interpreter, Writer, Astronomer, Don Juan, Orator/Actor,
        // Dream Interpreter, Biologist, Seaman, Gambler, Astrologer,
        // Adventurer; a player may not choose the first 5 skills - they are
        // prohibited (folio 15)
        int CCrSk3[20][3] = {
            {1,2,1},
            {3,5,2},
            {6,8,3},
            {9,11,4},
            {12,15,5},
            {16,20,6},
            {21,25,7},
            {26,30,8},
            {31,40,9},
            {41,45,10},
            {46,50,11},
            {51,55,12},
            {56,60,13},
            {61,65,14},
            {66,70,15},
            {71,75,16},
            {76,80,17},
            {81,85,18},
            {86,90,19},
            {91,100,20},
            };
        for (int b = 0;
             b < chrSkillGroup3Count();
             ++b) {
            int vals[3];
            vals[0] = chrSk3Lo(b);
            vals[1] = chrSk3Hi(b);
            vals[2] = chrSk3Code(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrSk3[b][c])
                    ++bad;
            }
        }
        // the father's title - 01-30 Knight, 31-60 Baron, 61-80 Count (Earl),
        // 81-90 Marquis, 91-95 Duke, 96-00 Royalty going to Table 2;
        // knighthood cannot be inherited (folio 15)
        int CCrTtl[6][3] = {
            {1,30,1},
            {31,60,2},
            {61,80,3},
            {81,90,4},
            {91,95,5},
            {96,100,6},
            };
        for (int b = 0;
             b < chrNobleTitleCount();
             ++b) {
            int vals[3];
            vals[0] = chrTtlLo(b);
            vals[1] = chrTtlHi(b);
            vals[2] = chrTtlCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrTtl[b][c])
                    ++bad;
            }
        }
        // the royalty minimum-wealth roll - Distant, 3rd Cousin, 2nd Cousin,
        // 1st Cousin, then 00 Immediate Family with 1000 initial and 100
        // allowance; all traced from the Royal Family to the player, and the
        // OCR's interleaved wealth labels ride unpinned as scanned (folio 15)
        int CCrRoy[5][3] = {
            {1,30,1},
            {31,60,2},
            {61,80,3},
            {81,99,4},
            {100,100,5},
            };
        for (int b = 0;
             b < chrRoyaltyKinCount();
             ++b) {
            int vals[3];
            vals[0] = chrRoyLo(b);
            vals[1] = chrRoyHi(b);
            vals[2] = chrRoyCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrRoy[b][c])
                    ++bad;
            }
        }
        // the Knight's position - Land Holder, Orator, In Army, Courtier,
        // Sheriff, with a 30 percent chance the father is an Adventurer
        // (folio 15)
        int CCrPoK[5][3] = {
            {1,40,1},
            {41,50,2},
            {51,90,3},
            {91,95,4},
            {96,100,5},
            };
        for (int b = 0;
             b < chrPosKnightCount();
             ++b) {
            int vals[3];
            vals[0] = chrPoKLo(b);
            vals[1] = chrPoKHi(b);
            vals[2] = chrPoKCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrPoK[b][c])
                    ++bad;
            }
        }
        // the Baron's position - the Knight's five plus Magistrate, with a 25
        // percent Adventurer chance (folio 15)
        int CCrPoB[6][3] = {
            {1,40,1},
            {41,50,2},
            {51,80,3},
            {81,90,4},
            {91,95,5},
            {96,100,6},
            };
        for (int b = 0;
             b < chrPosBaronCount();
             ++b) {
            int vals[3];
            vals[0] = chrPoBLo(b);
            vals[1] = chrPoBHi(b);
            vals[2] = chrPoBCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrPoB[b][c])
                    ++bad;
            }
        }
        // the Count's (Earl's) position - with a 20 percent Adventurer chance
        // (folio 15)
        int CCrPoC[6][3] = {
            {1,35,1},
            {36,45,2},
            {46,65,3},
            {66,80,4},
            {81,90,5},
            {91,100,6},
            };
        for (int b = 0;
             b < chrPosCountCount();
             ++b) {
            int vals[3];
            vals[0] = chrPoCLo(b);
            vals[1] = chrPoCHi(b);
            vals[2] = chrPoCCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrPoC[b][c])
                    ++bad;
            }
        }
        // the Marquis's position - seven bands including the Advisor, with a
        // 15 percent Adventurer chance (folio 15)
        int CCrPoM[7][3] = {
            {1,30,1},
            {31,35,2},
            {36,50,3},
            {51,80,4},
            {81,90,5},
            {91,99,6},
            {100,100,7},
            };
        for (int b = 0;
             b < chrPosMarquisCount();
             ++b) {
            int vals[3];
            vals[0] = chrPoMLo(b);
            vals[1] = chrPoMHi(b);
            vals[2] = chrPoMCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrPoM[b][c])
                    ++bad;
            }
        }
        // the Duke's position - seven bands, with a 15 percent Adventurer
        // chance; the worked example reads a Duke father as a courtier on a
        // 52 (folios 15-16)
        int CCrPoD[7][3] = {
            {1,20,1},
            {21,25,2},
            {26,40,3},
            {41,72,4},
            {73,82,5},
            {83,95,6},
            {96,100,7},
            };
        for (int b = 0;
             b < chrPosDukeCount();
             ++b) {
            int vals[3];
            vals[0] = chrPoDLo(b);
            vals[1] = chrPoDHi(b);
            vals[2] = chrPoDCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrPoD[b][c])
                    ++bad;
            }
        }
        // the Commoner father's adventurer level roll (folio 16)
        int CCrAC[4][3] = {
            {1,50,1},
            {51,70,2},
            {71,95,3},
            {96,100,4},
            };
        for (int b = 0;
             b < chrAdvComLevelsCount();
             ++b) {
            int vals[3];
            vals[0] = chrACLo(b);
            vals[1] = chrACHi(b);
            vals[2] = chrACLevel(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrAC[b][c])
                    ++bad;
            }
        }
        // the Merchant father's adventurer level roll (folio 16)
        int CCrAM[6][3] = {
            {1,40,1},
            {41,65,2},
            {66,75,3},
            {76,85,4},
            {86,95,5},
            {96,100,6},
            };
        for (int b = 0;
             b < chrAdvMerLevelsCount();
             ++b) {
            int vals[3];
            vals[0] = chrAMLo(b);
            vals[1] = chrAMHi(b);
            vals[2] = chrAMLevel(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrAM[b][c])
                    ++bad;
            }
        }
        // the Gentleman father's adventurer level roll (folio 16)
        int CCrAG[8][3] = {
            {1,35,1},
            {36,50,2},
            {51,65,3},
            {66,80,4},
            {81,90,5},
            {91,95,6},
            {96,98,7},
            {99,100,8},
            };
        for (int b = 0;
             b < chrAdvGenLevelsCount();
             ++b) {
            int vals[3];
            vals[0] = chrAGLo(b);
            vals[1] = chrAGHi(b);
            vals[2] = chrAGLevel(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrAG[b][c])
                    ++bad;
            }
        }
        // the Noble father's adventurer level roll (folio 16)
        int CCrAN[9][3] = {
            {1,30,1},
            {31,45,2},
            {46,60,3},
            {61,75,4},
            {76,85,5},
            {86,90,6},
            {91,94,7},
            {95,98,8},
            {99,100,9},
            };
        for (int b = 0;
             b < chrAdvNobLevelsCount();
             ++b) {
            int vals[3];
            vals[0] = chrANLo(b);
            vals[1] = chrANHi(b);
            vals[2] = chrANLevel(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrAN[b][c])
                    ++bad;
            }
        }
        // the Commoner father's class on a d8 - 1-5 fighter, 6-8 thief (folio
        // 16)
        int CCrCC[2][3] = {
            {1,5,1},
            {6,8,2},
            };
        for (int b = 0;
             b < chrAdvComClassCount();
             ++b) {
            int vals[3];
            vals[0] = chrCCLo(b);
            vals[1] = chrCCHi(b);
            vals[2] = chrCCCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrCC[b][c])
                    ++bad;
            }
        }
        // the Merchant father's class on a d8 - 1-4 fighter, 5 thief, 6-7
        // cleric, 8 magic-user (folio 16)
        int CCrCM[4][3] = {
            {1,4,1},
            {5,5,2},
            {6,7,3},
            {8,8,4},
            };
        for (int b = 0;
             b < chrAdvMerClassCount();
             ++b) {
            int vals[3];
            vals[0] = chrCMLo(b);
            vals[1] = chrCMHi(b);
            vals[2] = chrCMCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrCM[b][c])
                    ++bad;
            }
        }
        // the Gentleman father's class on a d8 - 1-3 fighter, 4 thief, 5-6
        // cleric, 7-8 magic-user (folio 16)
        int CCrCG[4][3] = {
            {1,3,1},
            {4,4,2},
            {5,6,3},
            {7,8,4},
            };
        for (int b = 0;
             b < chrAdvGenClassCount();
             ++b) {
            int vals[3];
            vals[0] = chrCGLo(b);
            vals[1] = chrCGHi(b);
            vals[2] = chrCGCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrCG[b][c])
                    ++bad;
            }
        }
        // the Noble father's class on a d8 - 1-3 fighter, 4 thief, 5 cleric,
        // 6-8 magic-user; the worked example reads a Noble father as a 4th
        // level magic-user on 63 and 7 (folio 16)
        int CCrCN[4][3] = {
            {1,3,1},
            {4,4,2},
            {5,5,3},
            {6,8,4},
            };
        for (int b = 0;
             b < chrAdvNobClassCount();
             ++b) {
            int vals[3];
            vals[0] = chrCNLo(b);
            vals[1] = chrCNHi(b);
            vals[2] = chrCNCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrCN[b][c])
                    ++bad;
            }
        }
        // the Commoner race roll on a d12 - 2 Half-goblin, 3 Half-orc, 4-10
        // Human, 11 Half-elf or Dwarf, 12 Hobbit (folio 16)
        int CCrR1C[5][3] = {
            {2,2,1},
            {3,3,2},
            {4,10,3},
            {11,11,4},
            {12,12,5},
            };
        for (int b = 0;
             b < chrRaceCommonerCount();
             ++b) {
            int vals[3];
            vals[0] = chrR1CLo(b);
            vals[1] = chrR1CHi(b);
            vals[2] = chrR1CCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrR1C[b][c])
                    ++bad;
            }
        }
        // the Merchant race roll on a d12 - 2 Hobbit, 3 Half-elf, 4-11 Human,
        // 12 Dwarf (folio 16)
        int CCrR1M[4][3] = {
            {2,2,1},
            {3,3,2},
            {4,11,3},
            {12,12,4},
            };
        for (int b = 0;
             b < chrRaceMerchantCount();
             ++b) {
            int vals[3];
            vals[0] = chrR1MLo(b);
            vals[1] = chrR1MHi(b);
            vals[2] = chrR1MCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrR1M[b][c])
                    ++bad;
            }
        }
        // the Gentleman-or-Noble race roll on a d12 - 2 Hobbit, 3-4 Half-elf,
        // 5-8 Human, 9-10 Dwarf, 11-12 Elf (folio 16)
        int CCrR1G[5][3] = {
            {2,2,1},
            {3,4,2},
            {5,8,3},
            {9,10,4},
            {11,12,5},
            };
        for (int b = 0;
             b < chrRaceGentleNobleCount();
             ++b) {
            int vals[3];
            vals[0] = chrR1GLo(b);
            vals[1] = chrR1GHi(b);
            vals[2] = chrR1GCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrR1G[b][c])
                    ++bad;
            }
        }
        // the race dice-count grid - the six races by the six characteristics
        // S I W C D Ch, as scanned (folio 16)
        int CCrDice[6][7] = {
            {1,3,2,3,3,2,2},
            {2,3,3,4,3,4,4},
            {3,4,3,3,4,3,3},
            {4,3,3,3,3,3,4},
            {5,2,3,3,4,4,3},
            {6,3,3,3,3,3,3},
            };
        for (int b = 0;
             b < chrRaceDiceCount();
             ++b) {
            int vals[7];
            vals[0] = chrDiceRaceCode(b);
            vals[1] = chrDiceStr(b);
            vals[2] = chrDiceInt(b);
            vals[3] = chrDiceWis(b);
            vals[4] = chrDiceCon(b);
            vals[5] = chrDiceDex(b);
            vals[6] = chrDiceCha(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CCrDice[b][c])
                    ++bad;
            }
        }
        // the Table 2 race requirements - the printed 'any' CONVERTED to the
        // 3-18 range and '9-18'/'13-18' carried as printed: the Elf needs 9+
        // Wisdom, Constitution and Dexterity with 13+ Charisma, the Dwarf 9+
        // Strength and 13+ Constitution, the Hobbit Strength and Dexterity at
        // 3-12 and 13+ Constitution, the Half-elf 9+ Wisdom and 13+ Charisma,
        // the Half-goblin/orc Intelligence and Dexterity at 3-12 with
        // Charisma 3-15 (folio 16)
        int CCrReq[6][13] = {
            {1,3,18,3,12,3,18,3,18,3,12,3,15},
            {2,3,18,3,18,9,18,9,18,9,18,13,18},
            {3,9,18,3,18,3,18,13,18,3,18,3,18},
            {4,3,18,3,18,9,18,3,18,3,18,13,18},
            {5,3,12,3,18,3,18,13,18,13,18,3,18},
            {6,3,18,3,18,3,18,3,18,3,18,3,18},
            };
        for (int b = 0;
             b < chrRaceReqCount();
             ++b) {
            int vals[13];
            vals[0] = chrReqRaceCode(b);
            vals[1] = chrReqStrMin(b);
            vals[2] = chrReqStrMax(b);
            vals[3] = chrReqIntMin(b);
            vals[4] = chrReqIntMax(b);
            vals[5] = chrReqWisMin(b);
            vals[6] = chrReqWisMax(b);
            vals[7] = chrReqConMin(b);
            vals[8] = chrReqConMax(b);
            vals[9] = chrReqDexMin(b);
            vals[10] = chrReqDexMax(b);
            vals[11] = chrReqChaMin(b);
            vals[12] = chrReqChaMax(b);
            for (int c = 0; c < 13;
                 ++c) {
                if (vals[c] != CCrReq[b][c])
                    ++bad;
            }
        }
        // the Commoner previous-experience roll - nil through x50, the result
        // multiplied by the percent dice (folio 16)
        int CCrPC[4][3] = {
            {1,85,0},
            {86,96,20},
            {97,99,30},
            {100,100,50},
            };
        for (int b = 0;
             b < chrPrevComCount();
             ++b) {
            int vals[3];
            vals[0] = chrPCLo(b);
            vals[1] = chrPCHi(b);
            vals[2] = chrPCMult(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrPC[b][c])
                    ++bad;
            }
        }
        // the Merchant previous-experience roll - nil through x70 (folio 16)
        int CCrPM[5][3] = {
            {1,70,0},
            {71,90,20},
            {91,96,30},
            {97,99,50},
            {100,100,70},
            };
        for (int b = 0;
             b < chrPrevMerCount();
             ++b) {
            int vals[3];
            vals[0] = chrPMLo(b);
            vals[1] = chrPMHi(b);
            vals[2] = chrPMMult(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrPM[b][c])
                    ++bad;
            }
        }
        // the Gentleman previous-experience roll - nil through x100 (folio
        // 16)
        int CCrPG[6][3] = {
            {1,60,0},
            {61,80,20},
            {81,93,30},
            {94,97,50},
            {98,99,70},
            {100,100,100},
            };
        for (int b = 0;
             b < chrPrevGenCount();
             ++b) {
            int vals[3];
            vals[0] = chrPGLo(b);
            vals[1] = chrPGHi(b);
            vals[2] = chrPGMult(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrPG[b][c])
                    ++bad;
            }
        }
        // the Noble previous-experience roll - nil through x130; the worked
        // example reads a Noble 89 as x50, times a 41 on the percent dice for
        // 2050 and a 2nd level start (folio 16)
        int CCrPN[7][3] = {
            {1,50,0},
            {51,70,20},
            {71,85,30},
            {86,92,50},
            {93,97,70},
            {98,99,100},
            {100,100,130},
            };
        for (int b = 0;
             b < chrPrevNobCount();
             ++b) {
            int vals[3];
            vals[0] = chrPNLo(b);
            vals[1] = chrPNHi(b);
            vals[2] = chrPNMult(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCrPN[b][c])
                    ++bad;
            }
        }
        // the ladder's shape and gates - nine levels, 17-plus Strength for
        // the 7th, 18 for the 8th, the 12-plus Intelligence and Wisdom
        // footnote pinned as scanned (folio 26)
    if (chrDwarfLadderLevels() != 9
            || chrDwfStrFor7th() != 17
            || chrDwfStrFor8th() != 18
            || chrDwfKingIntMin() != 12
            || chrDwfKingWisMin() != 12
        )
            ++bad;
        // the kingship - only 7 families so only 7 Dwarf Kings, the tribe
        // rolled on a d8 with 7-8 the tribe of Durin, the first to obtain it
        // holds it until death, and no other dwarf of that tribe reaches 9th
        // until he dies (folio 26)
    if (chrDwarfFamilies() != 7
            || chrDwarfTribeDieSides() != 8
            || chrDwarfTribeDurinLo() != 7
            || chrDwarfKingshipFirst() != 1
            || chrDwarfKingBlocksLevel() != 1
        )
            ++bad;
        // the Dwarf clerics - a 15 Wisdom opts in, 17 reaches 7th, 18 reaches
        // 8th, points on a d8 (folio 26)
    if (chrDwarfClericsAllowed() != 1
            || chrDwarfClericWisMin() != 15
            || chrDwarfCleric7thWis() != 17
            || chrDwarfCleric8thWis() != 18
            || chrDwarfClericHitDie() != 8
        )
            ++bad;
        // the Dwarf thieves and the forbidden list - Greyhawk as listed with
        // a d6 for points, and no Magicians, Assassins, Monks, Paladins,
        // Illusionists, Rangers or Sages (folio 26)
    if (chrDwarfThievesGreyhawk() != 1
            || chrDwarfThiefHitDie() != 6
            || chrDwarfForbiddenClasses() != 1
        )
            ++bad;
        // the Dwarf resistances and senses - +4 levels on saving throws, the
        // +3 War Hammer fully employed, slants and traps noted on 1-4 of a
        // d6, new construction automatic (folio 26)
    if (chrDwarfSaveBonusLevels() != 4
            || chrDwarfWarHammerBonus() != 3
            || chrDwarfSlantDieSides() != 6
            || chrDwarfSlantRollMax() != 4
            || chrDwarfNewConstructionAuto() != 1
        )
            ++bad;
        // the Dwarf tongues and the Giant Class edge - Goblin, Orc and
        // Hobgoblin understood, Gnome and Kobold spoken, +1 to hit and -1 to
        // be hit (folio 26)
    if (chrDwarfUnderstandsGobOrcHob() != 1
            || chrDwarfSpeaksGnomeKobold() != 1
            || chrDwarfGiantClassHitMod() != 1
            || chrDwarfGiantClassAcMod() != 1
        )
            ++bad;
        // the Dwarf trades - gems judged by feel, magic felt in armor and
        // weapons, Smiths at 9/9, Armorers at 12/9, Engineers at 15 (folio
        // 26)
    if (chrDwarfJudgesGems() != 1
            || chrDwarfFeelsMagic() != 1
            || chrDwarfSmithIntMin() != 9
            || chrDwarfSmithStrMin() != 9
            || chrDwarfArmorerIntMin() != 12
            || chrDwarfArmorerStrMin() != 9
            || chrDwarfEngineerIntMin() != 15
        )
            ++bad;
        // the Dwarf gear and fears - crossbows and short bows only, the six
        // regular weapons, all others at -1, swimming natural at 17 Dexterity
        // despite the water fear, and horses only for the 12-Intelligence at
        // great need (folios 26-27)
    if (chrDwarfBowsOnly() != 1
            || chrDwarfRegularWeapons() != 1
            || chrDwarfOtherWeaponHitMod() != 1
            || chrDwarfSwimDexMin() != 17
            || chrDwarfWaterFear() != 1
            || chrDwarfHorseIntMin() != 12
        )
            ++bad;
        // the Dwarf frame - maturity around 50, about 250 years of life, the
        // hate for Orcs and Goblins, the never-broken oath, and never
        // attacking one's own Folk (folio 27)
    if (chrDwarfMaturityAge() != 50
            || chrDwarfLifespanYears() != 250
            || chrDwarfHatesOrcsGoblins() != 1
            || chrDwarfOathsNeverBroken() != 1
            || chrDwarfNeverAttackOwnFolk() != 1
        )
            ++bad;
        // the birth-table frame - three skill groups, the allowance monthly
        // for the first year or until 3rd level, the skills rolled on
        // percentile dice (folios 14-15)
    if (chrBirthSkillsGroups() != 3
            || chrBirthAllowanceMonths() != 12
            || chrBirthAllowanceLevelCap() != 3
            || chrSkillsDieSides() != 100
        )
            ++bad;
        // the sibling rules - rank on a d8, orphaned on a 1 of a d6, the 1st
        // son inherits with 10 percent more, the bastard 10 percent less
        // (folio 14)
    if (chrSiblingDieSides() != 8
            || chrOrphanDieSides() != 6
            || chrOrphanRoll() != 1
            || chrBirthFirstSonInherits() != 1
            || chrBirthFirstSonPct() != 10
            || chrBirthBastardPct() != 10
        )
            ++bad;
        // the skills doctrine - the father's occupation must be among the
        // player's skills, the first 5 Group 3 skills prohibited, no player
        // Adventurer (folio 15)
    if (chrSkillsFatherOccupation() != 1
            || chrSkillsGroup3FirstFiveProhibited() != 1
            || chrSkillsNoPlayerAdventurer() != 1
        )
            ++bad;
        // the Group 1 banding notes - the Peasant capped at 70, the
        // Well-to-do floored at 31, the Wealthy at 52 with 52-55 equalling
        // Adventurer (folio 15)
    if (chrSkillsPeasantMax() != 70
            || chrSkillsWellToDoMin() != 31
            || chrSkillsWealthyMin() != 52
        )
            ++bad;
        // the skill edges and the crafts - the Interpreter's +3 languages,
        // the Soldier's +1 hit until 4th, the Orator's +1 reaction, twelve
        // crafts (folio 15)
    if (chrSkillsInterpreterIntBonus() != 3
            || chrSkillsSoldierHitBonus() != 1
            || chrSkillsSoldierLevelCap() != 4
            || chrSkillsOratorReactionBonus() != 1
            || chrCraftsCount() != 12
        )
            ++bad;
        // the royalty rules - the immediate family's 1000 initial and 100
        // allowance, never an orphan, the social rank raised to the minimum
        // wealth, the reroll ignoring 96-00, the title one notch (folio 15)
    if (chrRoyaltyImmediateInitial() != 1000
            || chrRoyaltyImmediateAllow() != 100
            || chrRoyaltyNeverOrphan() != 1
            || chrRoyaltyRaiseRank() != 1
            || chrRoyaltyRerollIgnore() != 1
            || chrRoyaltyTitleOneNotch() != 1
        )
            ++bad;
        // the father-Adventurer chances by title - 30, 25, 20, 15, 15 percent
        // (folio 15)
    if (chrKnightAdventurerPct() != 30
            || chrBaronAdventurerPct() != 25
            || chrCountAdventurerPct() != 20
            || chrMarquisAdventurerPct() != 15
            || chrDukeAdventurerPct() != 15
        )
            ++bad;
        // the authors' rulings - a non-human no higher than Earl, the race
        // rolls on a d12, Table 2 preferred, the 9-18 variant, and limiting
        // elves by requirements rather than advancement (folio 16)
    if (chrNobilityNonHumanEarlCap() != 1
            || chrRaceTable1DieSides() != 12
            || chrRaceTable2Preferred() != 1
            || chrRaceVariant9To18() != 1
            || chrRaceLimitByRequirements() != 1
        )
            ++bad;
        // the Silvan frame - no requirements, all D&D powers, immune to
        // disease and aging as the naturally immortal, Lawful or Neutral
        // never evil (folio 21)
    if (chrSilvanNoReqs() != 1
            || chrSilvanDdPowers() != 1
            || chrSilvanDiseaseImmune() != 1
            || chrSilvanAgingImmune() != 1
            || chrSilvanLawfulOrNeutral() != 1
        )
            ++bad;
        // the Silvan advancement - 8th fighter, 9th with 18 strength, 4th
        // magic-user, 5th with 18 intelligence (folio 21)
    if (chrSilvanFighterMax() != 8
            || chrSilvanFighterMaxStr18() != 9
            || chrSilvanMuMax() != 4
            || chrSilvanMuMaxInt18() != 5
        )
            ++bad;
        // the Sindar requirements and advancement - average abilities and a
        // total of 63, 8th magic-user (9th at 18 intelligence), 4th fighter
        // (5th at 17, 6th at 18 strength) (folio 21)
    if (chrSindarStatMin() != 9
            || chrSindarTotalMin() != 63
            || chrSindarMuMax() != 8
            || chrSindarMuMaxInt18() != 9
            || chrSindarFighterMax() != 4
            || chrSindarFighterMaxStr17() != 5
            || chrSindarFighterMaxStr18() != 6
        )
            ++bad;
        // the Eldar proper - the 13 Wisdom and 67 total over the Sindar's,
        // then 11th magic-user or 11th fighter, one path chosen, never both
        // (folio 21)
    if (chrEldarWisMin() != 13
            || chrEldarTotalMin() != 67
            || chrEldarMuMax() != 11
            || chrEldarFighterMax() != 11
            || chrEldarOnePathOnly() != 1
        )
            ++bad;
        // the Eldar powers - a language per intelligence point without the
        // orcish tongues, the calmed animals, the small-bird speech, the
        // mind-to-mind range of 2 and a half per level pinned as five
        // half-units, the binocular eyesight (folio 21)
    if (chrEldarLangPerIntPoint() != 1
            || chrEldarCalmAnimals() != 1
            || chrEldarBirdSpeech() != 1
            || chrEldarMindRangePerLevel() != 5
            || chrEldarKeenEyes() != 1
        )
            ++bad;
        // the True Sight - +1 per level versus phantasmal forces, illusions
        // seen through at 5 percent per level, the polymorphed true shape at
        // 3 percent per level (the 5th-level 15 percent example), the
        // shape-changed at 1 percent, the optional hidden-enemies chance, and
        // the unawareness on success (folio 21)
    if (chrEldarPhantasmalPerLevel() != 1
            || chrEldarIllusionPctPerLevel() != 5
            || chrEldarPolymorphPctPerLevel() != 3
            || chrEldarShapeChangePctPerLevel() != 1
            || chrEldarHiddenOptional() != 1
            || chrEldarUnawareOnSuccess() != 1
        )
            ++bad;
        // the over-sea doctrine - one in a thousand per year for the Eldar
        // proper, one in a hundred for the Sindar once they have seen the
        // western ocean and one in ten thousand before, no roll until maximum
        // level, and the Silvan never (folio 21)
    if (chrSeaEldarDenominator() != 1000
            || chrSeaSindarSeenDenominator() != 100
            || chrSeaSindarUnseenDenominator() != 10000
            || chrSeaWaitUntilMaxLevel() != 1
            || chrSilvanNeverCrossSea() != 1
        )
            ++bad;
        // the Eldar frame - half-elves as Eldar proper but advancing per
        // Greyhawk, all Eldar and half-elves Lawful and good, the Noldor
        // shorthand noted inaccurate, and the deltas against the R888 Smith
        // pin never silent (folio 21)
    if (chrHalfElfSameAsEldar() != 1
            || chrEldarAllLawfulGood() != 1
            || chrEldarNoldorShorthand() != 1
            || chrEldarRejectsSmithDelta() != 1
        )
            ++bad;
        // the 1st level Dwarf - 1+2 hit dice, 0 xp, fights as Man+2 (folio
        // 26) (folio 26)
    if (chrDwfLvlLevel(0) != 1
            || chrDwfLvlNameCode(0) != 1
            || chrDwfLvlHitBase(0) != 1
            || chrDwfLvlHitBonus(0) != 2
            || chrDwfLvlXp(0) != 0
            || chrDwfLvlFightsAs(0) != 1
            || chrDwfLvlFightsAsBonus(0) != 2
            || chrDwarfLadderLevels() != 9
        )
            ++bad;
        // the 2nd level Warrior - 2+1 hit dice, 2,500 xp, fights as Men+1
        // (folio 26) (folio 26)
    if (chrDwfLvlLevel(1) != 2
            || chrDwfLvlNameCode(1) != 2
            || chrDwfLvlHitBase(1) != 2
            || chrDwfLvlHitBonus(1) != 1
            || chrDwfLvlXp(1) != 2500
            || chrDwfLvlFightsAs(1) != 2
            || chrDwfLvlFightsAsBonus(1) != 1
        )
            ++bad;
        // the 3rd level Spearman - 3 hit dice, 5,000 xp, fights as Men (folio
        // 26) (folio 26)
    if (chrDwfLvlLevel(2) != 3
            || chrDwfLvlNameCode(2) != 3
            || chrDwfLvlHitBase(2) != 3
            || chrDwfLvlHitBonus(2) != 0
            || chrDwfLvlXp(2) != 5000
            || chrDwfLvlFightsAs(2) != 3
            || chrDwfLvlFightsAsBonus(2) != 0
        )
            ++bad;
        // the 4th level Dwarf Hero - 4 hit dice, 10,000 xp, fights as Men
        // (folio 26) (folio 26)
    if (chrDwfLvlLevel(3) != 4
            || chrDwfLvlNameCode(3) != 4
            || chrDwfLvlHitBase(3) != 4
            || chrDwfLvlHitBonus(3) != 0
            || chrDwfLvlXp(3) != 10000
            || chrDwfLvlFightsAs(3) != 4
            || chrDwfLvlFightsAsBonus(3) != 0
        )
            ++bad;
        // the 5th level Swordbearer - 5 hit dice, 20,000 xp, fights as Men
        // (folio 26) (folio 26)
    if (chrDwfLvlLevel(4) != 5
            || chrDwfLvlNameCode(4) != 5
            || chrDwfLvlHitBase(4) != 5
            || chrDwfLvlHitBonus(4) != 0
            || chrDwfLvlXp(4) != 20000
            || chrDwfLvlFightsAs(4) != 5
            || chrDwfLvlFightsAsBonus(4) != 0
        )
            ++bad;
        // the 6th level Axewielder - 6 hit dice, 40,000 xp, fights as Men
        // (folio 26) (folio 26)
    if (chrDwfLvlLevel(5) != 6
            || chrDwfLvlNameCode(5) != 6
            || chrDwfLvlHitBase(5) != 6
            || chrDwfLvlHitBonus(5) != 0
            || chrDwfLvlXp(5) != 40000
            || chrDwfLvlFightsAs(5) != 6
            || chrDwfLvlFightsAsBonus(5) != 0
        )
            ++bad;
        // the 7th level Champion - 7+1 hit dice, 80,000 xp, fights as Men+1
        // (folio 26) (folio 26)
    if (chrDwfLvlLevel(6) != 7
            || chrDwfLvlNameCode(6) != 7
            || chrDwfLvlHitBase(6) != 7
            || chrDwfLvlHitBonus(6) != 1
            || chrDwfLvlXp(6) != 80000
            || chrDwfLvlFightsAs(6) != 7
            || chrDwfLvlFightsAsBonus(6) != 1
        )
            ++bad;
        // the 8th level Dwarf Lord - 8+2 hit dice, 160,000 xp, fights as
        // Men+2 (folio 26) (folio 26)
    if (chrDwfLvlLevel(7) != 8
            || chrDwfLvlNameCode(7) != 8
            || chrDwfLvlHitBase(7) != 8
            || chrDwfLvlHitBonus(7) != 2
            || chrDwfLvlXp(7) != 160000
            || chrDwfLvlFightsAs(7) != 8
            || chrDwfLvlFightsAsBonus(7) != 2
        )
            ++bad;
        // the 9th level Dwarf King - 10+1 hit dice, 320,000 xp, fights as
        // Men+1 (folio 26) (folio 26)
    if (chrDwfLvlLevel(8) != 9
            || chrDwfLvlNameCode(8) != 9
            || chrDwfLvlHitBase(8) != 10
            || chrDwfLvlHitBonus(8) != 1
            || chrDwfLvlXp(8) != 320000
            || chrDwfLvlFightsAs(8) != 10
            || chrDwfLvlFightsAsBonus(8) != 1
        )
            ++bad;
        // the Goblins and Orcs row - AUTO ATTACK, pinned as sentinel 9 (folio
        // 27) (folio 27)
    if (chrDwfReactCode(0) != 1
            || chrDwfReactMod(0) != 9
            || chrDwarfReactionCount() != 6
        )
            ++bad;
        // the Sindar, Silvan Elves and all men row - minus 2 (folio 27)
        // (folio 27)
    if (chrDwfReactCode(1) != 2
            || chrDwfReactMod(1) != -2
        )
            ++bad;
        // the all-others row - minus 1 (folio 27) (folio 27)
    if (chrDwfReactCode(2) != 3
            || chrDwfReactMod(2) != -1
        )
            ++bad;
        // the Hobbits and Noldor Elves row - plus 0 (folio 27) (folio 27)
    if (chrDwfReactCode(3) != 4
            || chrDwfReactMod(3) != 0
        )
            ++bad;
        // the different-Folk row - plus 1 (folio 27) (folio 27)
    if (chrDwfReactCode(4) != 5
            || chrDwfReactMod(4) != 1
        )
            ++bad;
        // the same-Folk row - plus 2 (folio 27) (folio 27)
    if (chrDwfReactCode(5) != 6
            || chrDwfReactMod(5) != 2
        )
            ++bad;
        // the 01-30 Commoner row (folio 14) (folio 14)
    if (chrBCLo(0) != 1
            || chrBCHi(0) != 30
            || chrBCCode(0) != 1
            || chrBirthClassCount() != 4
        )
            ++bad;
        // the 31-85 Merchant row (folio 14) (folio 14)
    if (chrBCLo(1) != 31
            || chrBCHi(1) != 85
            || chrBCCode(1) != 2
        )
            ++bad;
        // the 86-95 Gentleman row (folio 14) (folio 14)
    if (chrBCLo(2) != 86
            || chrBCHi(2) != 95
            || chrBCCode(2) != 3
        )
            ++bad;
        // the 96-00 Noble row, the 00 pinned as 100 (folio 14) (folio 14)
    if (chrBCLo(3) != 96
            || chrBCHi(3) != 100
            || chrBCCode(3) != 4
        )
            ++bad;
        // the 1-2 first-son band (folio 14) (folio 14)
    if (chrSibLo(0) != 1
            || chrSibHi(0) != 2
            || chrSibCode(0) != 1
            || chrSiblingBandCount() != 5
        )
            ++bad;
        // the 3-4 second-son band (folio 14) (folio 14)
    if (chrSibLo(1) != 3
            || chrSibHi(1) != 4
            || chrSibCode(1) != 2
        )
            ++bad;
        // the 5 third-son band (folio 14) (folio 14)
    if (chrSibLo(2) != 5
            || chrSibHi(2) != 5
            || chrSibCode(2) != 3
        )
            ++bad;
        // the 6 fourth-son band (folio 14) (folio 14)
    if (chrSibLo(3) != 6
            || chrSibHi(3) != 6
            || chrSibCode(3) != 4
        )
            ++bad;
        // the 7-8 bastard band (folio 14) (folio 14)
    if (chrSibLo(4) != 7
            || chrSibHi(4) != 8
            || chrSibCode(4) != 5
        )
            ++bad;
        // the 01-25 Peasant row - 10 initial, no allowance, no inheritance
        // (folio 15) (folio 15)
    if (chrComLo(0) != 1
            || chrComHi(0) != 25
            || chrComInitial(0) != 10
            || chrComAllow(0) != 0
            || chrComInherit(0) != 0
            || chrComSkills(0) != 1
            || chrRankCommonerCount() != 4
        )
            ++bad;
        // the 26-40 Average row - 30 initial, 1 allowance, 15 inheritance
        // (folio 15) (folio 15)
    if (chrComLo(1) != 26
            || chrComHi(1) != 40
            || chrComInitial(1) != 30
            || chrComAllow(1) != 1
            || chrComInherit(1) != 15
            || chrComSkills(1) != 1
        )
            ++bad;
        // the 41-70 Well-to-do row - 60 initial, 5 allowance, 50 inheritance
        // (folio 15) (folio 15)
    if (chrComLo(2) != 41
            || chrComHi(2) != 70
            || chrComInitial(2) != 60
            || chrComAllow(2) != 5
            || chrComInherit(2) != 50
            || chrComSkills(2) != 1
        )
            ++bad;
        // the 71-00 Wealthy row - 100 initial, 10 allowance, 100 inheritance
        // (folio 15) (folio 15)
    if (chrComLo(3) != 71
            || chrComHi(3) != 100
            || chrComInitial(3) != 100
            || chrComAllow(3) != 10
            || chrComInherit(3) != 100
            || chrComSkills(3) != 1
        )
            ++bad;
        // the 01-25 Small row - 50 initial, 5 allowance, 100 inheritance,
        // skills B (folio 15) (folio 15)
    if (chrMerLo(0) != 1
            || chrMerHi(0) != 25
            || chrMerInitial(0) != 50
            || chrMerAllow(0) != 5
            || chrMerInherit(0) != 100
            || chrMerSkills(0) != 2
            || chrRankMerchantCount() != 5
        )
            ++bad;
        // the 26-60 Average row - 100 initial, 10 allowance, 150 inheritance
        // (folio 15) (folio 15)
    if (chrMerLo(1) != 26
            || chrMerHi(1) != 60
            || chrMerInitial(1) != 100
            || chrMerAllow(1) != 10
            || chrMerInherit(1) != 150
            || chrMerSkills(1) != 2
        )
            ++bad;
        // the 61-80 Well-to-do row - 120 initial, 15 allowance, 200
        // inheritance (folio 15) (folio 15)
    if (chrMerLo(2) != 61
            || chrMerHi(2) != 80
            || chrMerInitial(2) != 120
            || chrMerAllow(2) != 15
            || chrMerInherit(2) != 200
            || chrMerSkills(2) != 2
        )
            ++bad;
        // the 81-95 Wealthy row - 170 initial, 20 allowance, 250 inheritance
        // (folio 15) (folio 15)
    if (chrMerLo(3) != 81
            || chrMerHi(3) != 95
            || chrMerInitial(3) != 170
            || chrMerAllow(3) != 20
            || chrMerInherit(3) != 250
            || chrMerSkills(3) != 2
        )
            ++bad;
        // the 96-00 Very Wealthy row - 200 initial, 30 allowance, 400
        // inheritance, skills C, the OCR-split row pinned as scanned (folio
        // 15) (folio 15)
    if (chrMerLo(4) != 96
            || chrMerHi(4) != 100
            || chrMerInitial(4) != 200
            || chrMerAllow(4) != 30
            || chrMerInherit(4) != 400
            || chrMerSkills(4) != 3
        )
            ++bad;
        // the 01-20 Impoverished row - 70 initial, no allowance, 75
        // inheritance, skills B (folio 15) (folio 15)
    if (chrGenLo(0) != 1
            || chrGenHi(0) != 20
            || chrGenInitial(0) != 70
            || chrGenAllow(0) != 0
            || chrGenInherit(0) != 75
            || chrGenSkills(0) != 2
            || chrRankGentlemanCount() != 5
        )
            ++bad;
        // the 21-65 Average row - 100 initial, 5 allowance, 150 inheritance,
        // skills C (folio 15) (folio 15)
    if (chrGenLo(1) != 21
            || chrGenHi(1) != 65
            || chrGenInitial(1) != 100
            || chrGenAllow(1) != 5
            || chrGenInherit(1) != 150
            || chrGenSkills(1) != 3
        )
            ++bad;
        // the 66-90 Well-to-do row - 150 initial, 15 allowance, 250
        // inheritance (folio 15) (folio 15)
    if (chrGenLo(2) != 66
            || chrGenHi(2) != 90
            || chrGenInitial(2) != 150
            || chrGenAllow(2) != 15
            || chrGenInherit(2) != 250
            || chrGenSkills(2) != 3
        )
            ++bad;
        // the 91-95 Wealthy row - 200 initial, 20 allowance, 350 inheritance
        // (folio 15) (folio 15)
    if (chrGenLo(3) != 91
            || chrGenHi(3) != 95
            || chrGenInitial(3) != 200
            || chrGenAllow(3) != 20
            || chrGenInherit(3) != 350
            || chrGenSkills(3) != 3
        )
            ++bad;
        // the 96-00 Very Wealthy row - 250 initial, 35 allowance, 600
        // inheritance, skills D, the column shift pinned as scanned (folio
        // 15) (folio 15)
    if (chrGenLo(4) != 96
            || chrGenHi(4) != 100
            || chrGenInitial(4) != 250
            || chrGenAllow(4) != 35
            || chrGenInherit(4) != 600
            || chrGenSkills(4) != 4
        )
            ++bad;
        // the 01-20 Impoverished row - 80 initial, no allowance, 100
        // inheritance, skills D (folio 15) (folio 15)
    if (chrNobLo(0) != 1
            || chrNobHi(0) != 20
            || chrNobInitial(0) != 80
            || chrNobAllow(0) != 0
            || chrNobInherit(0) != 100
            || chrNobSkills(0) != 4
            || chrRankNobleCount() != 6
        )
            ++bad;
        // the 21-40 Poor row - 120 initial, 10 allowance, 150 inheritance
        // (folio 15) (folio 15)
    if (chrNobLo(1) != 21
            || chrNobHi(1) != 40
            || chrNobInitial(1) != 120
            || chrNobAllow(1) != 10
            || chrNobInherit(1) != 150
            || chrNobSkills(1) != 4
        )
            ++bad;
        // the 41-85 Average row - 200 initial, 25 allowance, 300 inheritance,
        // skills E (folio 15) (folio 15)
    if (chrNobLo(2) != 41
            || chrNobHi(2) != 85
            || chrNobInitial(2) != 200
            || chrNobAllow(2) != 25
            || chrNobInherit(2) != 300
            || chrNobSkills(2) != 5
        )
            ++bad;
        // the 86-95 Well-to-do row - 250 initial, 35 allowance, 450
        // inheritance (folio 15) (folio 15)
    if (chrNobLo(3) != 86
            || chrNobHi(3) != 95
            || chrNobInitial(3) != 250
            || chrNobAllow(3) != 35
            || chrNobInherit(3) != 450
            || chrNobSkills(3) != 5
        )
            ++bad;
        // the 96-97 Wealthy row - 300 initial, 45 allowance, 700 inheritance,
        // skills F (folio 15) (folio 15)
    if (chrNobLo(4) != 96
            || chrNobHi(4) != 97
            || chrNobInitial(4) != 300
            || chrNobAllow(4) != 45
            || chrNobInherit(4) != 700
            || chrNobSkills(4) != 6
        )
            ++bad;
        // the 98-00 Very Wealthy row - 400 initial, 60 allowance, 1000
        // inheritance, the column shift pinned as scanned (folio 15) (folio
        // 15)
    if (chrNobLo(5) != 98
            || chrNobHi(5) != 100
            || chrNobInitial(5) != 400
            || chrNobAllow(5) != 60
            || chrNobInherit(5) != 1000
            || chrNobSkills(5) != 6
        )
            ++bad;
        // the Commoner row - roll under Group 1 (folio 15) (folio 15)
    if (chrFthClassCode(0) != 1
            || chrFthOccGroup(0) != 1
            || chrFatherOccCount() != 4
        )
            ++bad;
        // the Merchant row - roll under Group 2 (folio 15) (folio 15)
    if (chrFthClassCode(1) != 2
            || chrFthOccGroup(1) != 2
        )
            ++bad;
        // the Gentleman row - roll under Group 3 (folio 15) (folio 15)
    if (chrFthClassCode(2) != 3
            || chrFthOccGroup(2) != 3
        )
            ++bad;
        // the Noble row - roll under Group 3 (folio 15) (folio 15)
    if (chrFthClassCode(3) != 4
            || chrFthOccGroup(3) != 3
        )
            ++bad;
        // the 01-10 Vagabond band (folio 15) (folio 15)
    if (chrSk1Lo(0) != 1
            || chrSk1Hi(0) != 10
            || chrSk1Code(0) != 1
            || chrSkillGroup1Count() != 10
        )
            ++bad;
        // the 11-55 Farmer/Serf band (folio 15) (folio 15)
    if (chrSk1Lo(1) != 11
            || chrSk1Hi(1) != 55
            || chrSk1Code(1) != 2
        )
            ++bad;
        // the 56-60 Tinker band (folio 15) (folio 15)
    if (chrSk1Lo(2) != 56
            || chrSk1Hi(2) != 60
            || chrSk1Code(2) != 3
        )
            ++bad;
        // the 61-65 Miner band (folio 15) (folio 15)
    if (chrSk1Lo(3) != 61
            || chrSk1Hi(3) != 65
            || chrSk1Code(3) != 4
        )
            ++bad;
        // the 66-70 Woodsman band (folio 15) (folio 15)
    if (chrSk1Lo(4) != 66
            || chrSk1Hi(4) != 70
            || chrSk1Code(4) != 5
        )
            ++bad;
        // the 71-75 Sailor band (folio 15) (folio 15)
    if (chrSk1Lo(5) != 71
            || chrSk1Hi(5) != 75
            || chrSk1Code(5) != 6
        )
            ++bad;
        // the 76-85 Fisherman band (folio 15) (folio 15)
    if (chrSk1Lo(6) != 76
            || chrSk1Hi(6) != 85
            || chrSk1Code(6) != 7
        )
            ++bad;
        // the 86-95 Craftsman band - roll under Crafts for a father (folio
        // 15) (folio 15)
    if (chrSk1Lo(7) != 86
            || chrSk1Hi(7) != 95
            || chrSk1Code(7) != 8
        )
            ++bad;
        // the 96-99 Soldier band - the player receives +1 on hit probability
        // until 4th level (folio 15) (folio 15)
    if (chrSk1Lo(8) != 96
            || chrSk1Hi(8) != 99
            || chrSk1Code(8) != 9
        )
            ++bad;
        // the 00 band pinned as 100 - Adventurer, no player may take it, the
        // possibility handled under previous experience (folio 15) (folio 15)
    if (chrSk1Lo(9) != 100
            || chrSk1Hi(9) != 100
            || chrSk1Code(9) != 10
        )
            ++bad;
        // the 01-35 Normal Merchant band (folio 15) (folio 15)
    if (chrSk2Lo(0) != 1
            || chrSk2Hi(0) != 35
            || chrSk2Code(0) != 1
            || chrSkillGroup2Count() != 10
        )
            ++bad;
        // the 36-60 Ind. Craftsman band (folio 15) (folio 15)
    if (chrSk2Lo(1) != 36
            || chrSk2Hi(1) != 60
            || chrSk2Code(1) != 2
        )
            ++bad;
        // the 61-65 Scribe band (folio 15) (folio 15)
    if (chrSk2Lo(2) != 61
            || chrSk2Hi(2) != 65
            || chrSk2Code(2) != 3
        )
            ++bad;
        // the 66-70 Seaman band (folio 15) (folio 15)
    if (chrSk2Lo(3) != 66
            || chrSk2Hi(3) != 70
            || chrSk2Code(3) != 4
        )
            ++bad;
        // the 71-75 Slaver band (folio 15) (folio 15)
    if (chrSk2Lo(4) != 71
            || chrSk2Hi(4) != 75
            || chrSk2Code(4) != 5
        )
            ++bad;
        // the 76-80 Animal Trainer band (folio 15) (folio 15)
    if (chrSk2Lo(5) != 76
            || chrSk2Hi(5) != 80
            || chrSk2Code(5) != 6
        )
            ++bad;
        // the 81-85 Shipwright band (folio 15) (folio 15)
    if (chrSk2Lo(6) != 81
            || chrSk2Hi(6) != 85
            || chrSk2Code(6) != 7
        )
            ++bad;
        // the 86-90 Master Merchant band (folio 15) (folio 15)
    if (chrSk2Lo(7) != 86
            || chrSk2Hi(7) != 90
            || chrSk2Code(7) != 8
        )
            ++bad;
        // the 91-95 Bird Trainer band (folio 15) (folio 15)
    if (chrSk2Lo(8) != 91
            || chrSk2Hi(8) != 95
            || chrSk2Code(8) != 9
        )
            ++bad;
        // the 96-00 Adventurer band, the 00 pinned as 100 (folio 15) (folio
        // 15)
    if (chrSk2Lo(9) != 96
            || chrSk2Hi(9) != 100
            || chrSk2Code(9) != 10
        )
            ++bad;
        // the 01-02 Assassin/Spytracker band (folio 15) (folio 15)
    if (chrSk3Lo(0) != 1
            || chrSk3Hi(0) != 2
            || chrSk3Code(0) != 1
            || chrSkillGroup3Count() != 20
        )
            ++bad;
        // the 03-05 Sheriff band (folio 15) (folio 15)
    if (chrSk3Lo(1) != 3
            || chrSk3Hi(1) != 5
            || chrSk3Code(1) != 2
        )
            ++bad;
        // the 06-08 Magistrate band (folio 15) (folio 15)
    if (chrSk3Lo(2) != 6
            || chrSk3Hi(2) != 8
            || chrSk3Code(2) != 3
        )
            ++bad;
        // the 09-11 Sage band (folio 15) (folio 15)
    if (chrSk3Lo(3) != 9
            || chrSk3Hi(3) != 11
            || chrSk3Code(3) != 4
        )
            ++bad;
        // the 12-15 Alchemist band (folio 15) (folio 15)
    if (chrSk3Lo(4) != 12
            || chrSk3Hi(4) != 15
            || chrSk3Code(4) != 5
        )
            ++bad;
        // the 16-20 Physician band (folio 15) (folio 15)
    if (chrSk3Lo(5) != 16
            || chrSk3Hi(5) != 20
            || chrSk3Code(5) != 6
        )
            ++bad;
        // the 21-25 Artist/Sculptor/Musician band (folio 15) (folio 15)
    if (chrSk3Lo(6) != 21
            || chrSk3Hi(6) != 25
            || chrSk3Code(6) != 7
        )
            ++bad;
        // the 26-30 Engineer band (folio 15) (folio 15)
    if (chrSk3Lo(7) != 26
            || chrSk3Hi(7) != 30
            || chrSk3Code(7) != 8
        )
            ++bad;
        // the 31-40 Soldier band (folio 15) (folio 15)
    if (chrSk3Lo(8) != 31
            || chrSk3Hi(8) != 40
            || chrSk3Code(8) != 9
        )
            ++bad;
        // the 41-45 Interpreter band - languages as if intelligence were 3
        // higher (folio 15) (folio 15)
    if (chrSk3Lo(9) != 41
            || chrSk3Hi(9) != 45
            || chrSk3Code(9) != 10
        )
            ++bad;
        // the 46-50 Writer band (folio 15) (folio 15)
    if (chrSk3Lo(10) != 46
            || chrSk3Hi(10) != 50
            || chrSk3Code(10) != 11
        )
            ++bad;
        // the 51-55 Astronomer band (folio 15) (folio 15)
    if (chrSk3Lo(11) != 51
            || chrSk3Hi(11) != 55
            || chrSk3Code(11) != 12
        )
            ++bad;
        // the 56-60 Don Juan band (folio 15) (folio 15)
    if (chrSk3Lo(12) != 56
            || chrSk3Hi(12) != 60
            || chrSk3Code(12) != 13
        )
            ++bad;
        // the 61-65 Orator/Actor band - +1 on random monster reaction rolls
        // (folio 15) (folio 15)
    if (chrSk3Lo(13) != 61
            || chrSk3Hi(13) != 65
            || chrSk3Code(13) != 14
        )
            ++bad;
        // the 66-70 Dream Interpreter band (folio 15) (folio 15)
    if (chrSk3Lo(14) != 66
            || chrSk3Hi(14) != 70
            || chrSk3Code(14) != 15
        )
            ++bad;
        // the 71-75 Biologist band (folio 15) (folio 15)
    if (chrSk3Lo(15) != 71
            || chrSk3Hi(15) != 75
            || chrSk3Code(15) != 16
        )
            ++bad;
        // the 76-80 Seaman band (folio 15) (folio 15)
    if (chrSk3Lo(16) != 76
            || chrSk3Hi(16) != 80
            || chrSk3Code(16) != 17
        )
            ++bad;
        // the 81-85 Gambler band (folio 15) (folio 15)
    if (chrSk3Lo(17) != 81
            || chrSk3Hi(17) != 85
            || chrSk3Code(17) != 18
        )
            ++bad;
        // the 86-90 Astrologer band (folio 15) (folio 15)
    if (chrSk3Lo(18) != 86
            || chrSk3Hi(18) != 90
            || chrSk3Code(18) != 19
        )
            ++bad;
        // the 91-00 Adventurer band, the 00 pinned as 100 (folio 15) (folio
        // 15)
    if (chrSk3Lo(19) != 91
            || chrSk3Hi(19) != 100
            || chrSk3Code(19) != 20
        )
            ++bad;
        // the 01-30 Knight row (folio 15) (folio 15)
    if (chrTtlLo(0) != 1
            || chrTtlHi(0) != 30
            || chrTtlCode(0) != 1
            || chrNobleTitleCount() != 6
        )
            ++bad;
        // the 31-60 Baron row (folio 15) (folio 15)
    if (chrTtlLo(1) != 31
            || chrTtlHi(1) != 60
            || chrTtlCode(1) != 2
        )
            ++bad;
        // the 61-80 Count (Earl) row (folio 15) (folio 15)
    if (chrTtlLo(2) != 61
            || chrTtlHi(2) != 80
            || chrTtlCode(2) != 3
        )
            ++bad;
        // the 81-90 Marquis row (folio 15) (folio 15)
    if (chrTtlLo(3) != 81
            || chrTtlHi(3) != 90
            || chrTtlCode(3) != 4
        )
            ++bad;
        // the 91-95 Duke row (folio 15) (folio 15)
    if (chrTtlLo(4) != 91
            || chrTtlHi(4) != 95
            || chrTtlCode(4) != 5
        )
            ++bad;
        // the 96-00 Royalty row, the 00 pinned as 100, then Table 2 (folio
        // 15) (folio 15)
    if (chrTtlLo(5) != 96
            || chrTtlHi(5) != 100
            || chrTtlCode(5) != 6
        )
            ++bad;
        // the 01-30 Distant row (folio 15) (folio 15)
    if (chrRoyLo(0) != 1
            || chrRoyHi(0) != 30
            || chrRoyCode(0) != 1
            || chrRoyaltyKinCount() != 5
        )
            ++bad;
        // the 31-60 3rd Cousin row (folio 15) (folio 15)
    if (chrRoyLo(1) != 31
            || chrRoyHi(1) != 60
            || chrRoyCode(1) != 2
        )
            ++bad;
        // the 61-80 2nd Cousin row (folio 15) (folio 15)
    if (chrRoyLo(2) != 61
            || chrRoyHi(2) != 80
            || chrRoyCode(2) != 3
        )
            ++bad;
        // the 81-99 1st Cousin row (folio 15) (folio 15)
    if (chrRoyLo(3) != 81
            || chrRoyHi(3) != 99
            || chrRoyCode(3) != 4
        )
            ++bad;
        // the 00 row pinned as 100 - Immediate Family, 1000 initial, 100
        // allowance, never an orphan (folio 15) (folio 15)
    if (chrRoyLo(4) != 100
            || chrRoyHi(4) != 100
            || chrRoyCode(4) != 5
        )
            ++bad;
        // the Knight 01-40 Land Holder band (folio 15) (folio 15)
    if (chrPoKLo(0) != 1
            || chrPoKHi(0) != 40
            || chrPoKCode(0) != 1
            || chrPosKnightCount() != 5
        )
            ++bad;
        // the Knight 41-50 Orator band (folio 15) (folio 15)
    if (chrPoKLo(1) != 41
            || chrPoKHi(1) != 50
            || chrPoKCode(1) != 2
        )
            ++bad;
        // the Knight 51-90 In Army band (folio 15) (folio 15)
    if (chrPoKLo(2) != 51
            || chrPoKHi(2) != 90
            || chrPoKCode(2) != 3
        )
            ++bad;
        // the Knight 91-95 Courtier band (folio 15) (folio 15)
    if (chrPoKLo(3) != 91
            || chrPoKHi(3) != 95
            || chrPoKCode(3) != 4
        )
            ++bad;
        // the Knight 96-00 Sheriff band (folio 15) (folio 15)
    if (chrPoKLo(4) != 96
            || chrPoKHi(4) != 100
            || chrPoKCode(4) != 5
        )
            ++bad;
        // the Baron 01-40 Land Holder band (folio 15) (folio 15)
    if (chrPoBLo(0) != 1
            || chrPoBHi(0) != 40
            || chrPoBCode(0) != 1
            || chrPosBaronCount() != 6
        )
            ++bad;
        // the Baron 41-50 Orator band (folio 15) (folio 15)
    if (chrPoBLo(1) != 41
            || chrPoBHi(1) != 50
            || chrPoBCode(1) != 2
        )
            ++bad;
        // the Baron 51-80 In Army band (folio 15) (folio 15)
    if (chrPoBLo(2) != 51
            || chrPoBHi(2) != 80
            || chrPoBCode(2) != 3
        )
            ++bad;
        // the Baron 81-90 Courtier band (folio 15) (folio 15)
    if (chrPoBLo(3) != 81
            || chrPoBHi(3) != 90
            || chrPoBCode(3) != 4
        )
            ++bad;
        // the Baron 91-95 Sheriff band (folio 15) (folio 15)
    if (chrPoBLo(4) != 91
            || chrPoBHi(4) != 95
            || chrPoBCode(4) != 5
        )
            ++bad;
        // the Baron 96-00 Magistrate band (folio 15) (folio 15)
    if (chrPoBLo(5) != 96
            || chrPoBHi(5) != 100
            || chrPoBCode(5) != 6
        )
            ++bad;
        // the Count 01-35 Land Holder band (folio 15) (folio 15)
    if (chrPoCLo(0) != 1
            || chrPoCHi(0) != 35
            || chrPoCCode(0) != 1
            || chrPosCountCount() != 6
        )
            ++bad;
        // the Count 36-45 Orator band (folio 15) (folio 15)
    if (chrPoCLo(1) != 36
            || chrPoCHi(1) != 45
            || chrPoCCode(1) != 2
        )
            ++bad;
        // the Count 46-65 In Army band (folio 15) (folio 15)
    if (chrPoCLo(2) != 46
            || chrPoCHi(2) != 65
            || chrPoCCode(2) != 3
        )
            ++bad;
        // the Count 66-80 Courtier band (folio 15) (folio 15)
    if (chrPoCLo(3) != 66
            || chrPoCHi(3) != 80
            || chrPoCCode(3) != 4
        )
            ++bad;
        // the Count 81-90 Sheriff band (folio 15) (folio 15)
    if (chrPoCLo(4) != 81
            || chrPoCHi(4) != 90
            || chrPoCCode(4) != 5
        )
            ++bad;
        // the Count 91-00 Magistrate band, the 00 pinned as 100 (folio 15)
        // (folio 15)
    if (chrPoCLo(5) != 91
            || chrPoCHi(5) != 100
            || chrPoCCode(5) != 6
        )
            ++bad;
        // the Marquis 01-30 Land Holder band (folio 15) (folio 15)
    if (chrPoMLo(0) != 1
            || chrPoMHi(0) != 30
            || chrPoMCode(0) != 1
            || chrPosMarquisCount() != 7
        )
            ++bad;
        // the Marquis 31-35 Orator band (folio 15) (folio 15)
    if (chrPoMLo(1) != 31
            || chrPoMHi(1) != 35
            || chrPoMCode(1) != 2
        )
            ++bad;
        // the Marquis 36-50 In Army band (folio 15) (folio 15)
    if (chrPoMLo(2) != 36
            || chrPoMHi(2) != 50
            || chrPoMCode(2) != 3
        )
            ++bad;
        // the Marquis 51-80 Courtier band (folio 15) (folio 15)
    if (chrPoMLo(3) != 51
            || chrPoMHi(3) != 80
            || chrPoMCode(3) != 4
        )
            ++bad;
        // the Marquis 81-90 Sheriff band (folio 15) (folio 15)
    if (chrPoMLo(4) != 81
            || chrPoMHi(4) != 90
            || chrPoMCode(4) != 5
        )
            ++bad;
        // the Marquis 91-99 Magistrate band (folio 15) (folio 15)
    if (chrPoMLo(5) != 91
            || chrPoMHi(5) != 99
            || chrPoMCode(5) != 6
        )
            ++bad;
        // the Marquis 00 band pinned as 100 - Advisor to the King (folio 15)
        // (folio 15)
    if (chrPoMLo(6) != 100
            || chrPoMHi(6) != 100
            || chrPoMCode(6) != 7
        )
            ++bad;
        // the Duke 01-20 Land Holder band (folio 15) (folio 15)
    if (chrPoDLo(0) != 1
            || chrPoDHi(0) != 20
            || chrPoDCode(0) != 1
            || chrPosDukeCount() != 7
        )
            ++bad;
        // the Duke 21-25 Orator band (folio 15) (folio 15)
    if (chrPoDLo(1) != 21
            || chrPoDHi(1) != 25
            || chrPoDCode(1) != 2
        )
            ++bad;
        // the Duke 26-40 In Army band (folio 15) (folio 15)
    if (chrPoDLo(2) != 26
            || chrPoDHi(2) != 40
            || chrPoDCode(2) != 3
        )
            ++bad;
        // the Duke 41-72 Courtier band - the worked example's 52 (folio 15)
        // (folio 15)
    if (chrPoDLo(3) != 41
            || chrPoDHi(3) != 72
            || chrPoDCode(3) != 4
        )
            ++bad;
        // the Duke 73-82 Sheriff band (folio 15) (folio 15)
    if (chrPoDLo(4) != 73
            || chrPoDHi(4) != 82
            || chrPoDCode(4) != 5
        )
            ++bad;
        // the Duke 83-95 Magistrate band (folio 15) (folio 15)
    if (chrPoDLo(5) != 83
            || chrPoDHi(5) != 95
            || chrPoDCode(5) != 6
        )
            ++bad;
        // the Duke 96-00 Advisor band, the 00 pinned as 100 (folio 15) (folio
        // 15)
    if (chrPoDLo(6) != 96
            || chrPoDHi(6) != 100
            || chrPoDCode(6) != 7
        )
            ++bad;
        // the Commoner 01-50 1st level band (folio 16) (folio 16)
    if (chrACLo(0) != 1
            || chrACHi(0) != 50
            || chrACLevel(0) != 1
            || chrAdvComLevelsCount() != 4
        )
            ++bad;
        // the Commoner 51-70 2nd level band (folio 16) (folio 16)
    if (chrACLo(1) != 51
            || chrACHi(1) != 70
            || chrACLevel(1) != 2
        )
            ++bad;
        // the Commoner 71-95 3rd level band (folio 16) (folio 16)
    if (chrACLo(2) != 71
            || chrACHi(2) != 95
            || chrACLevel(2) != 3
        )
            ++bad;
        // the Commoner 96-00 4th level band (folio 16) (folio 16)
    if (chrACLo(3) != 96
            || chrACHi(3) != 100
            || chrACLevel(3) != 4
        )
            ++bad;
        // the Merchant 01-40 1st level band (folio 16) (folio 16)
    if (chrAMLo(0) != 1
            || chrAMHi(0) != 40
            || chrAMLevel(0) != 1
            || chrAdvMerLevelsCount() != 6
        )
            ++bad;
        // the Merchant 41-65 2nd level band (folio 16) (folio 16)
    if (chrAMLo(1) != 41
            || chrAMHi(1) != 65
            || chrAMLevel(1) != 2
        )
            ++bad;
        // the Merchant 66-75 3rd level band (folio 16) (folio 16)
    if (chrAMLo(2) != 66
            || chrAMHi(2) != 75
            || chrAMLevel(2) != 3
        )
            ++bad;
        // the Merchant 76-85 4th level band (folio 16) (folio 16)
    if (chrAMLo(3) != 76
            || chrAMHi(3) != 85
            || chrAMLevel(3) != 4
        )
            ++bad;
        // the Merchant 86-95 5th level band (folio 16) (folio 16)
    if (chrAMLo(4) != 86
            || chrAMHi(4) != 95
            || chrAMLevel(4) != 5
        )
            ++bad;
        // the Merchant 96-00 6th level band (folio 16) (folio 16)
    if (chrAMLo(5) != 96
            || chrAMHi(5) != 100
            || chrAMLevel(5) != 6
        )
            ++bad;
        // the Gentleman 01-35 1st level band (folio 16) (folio 16)
    if (chrAGLo(0) != 1
            || chrAGHi(0) != 35
            || chrAGLevel(0) != 1
            || chrAdvGenLevelsCount() != 8
        )
            ++bad;
        // the Gentleman 36-50 2nd level band (folio 16) (folio 16)
    if (chrAGLo(1) != 36
            || chrAGHi(1) != 50
            || chrAGLevel(1) != 2
        )
            ++bad;
        // the Gentleman 51-65 3rd level band (folio 16) (folio 16)
    if (chrAGLo(2) != 51
            || chrAGHi(2) != 65
            || chrAGLevel(2) != 3
        )
            ++bad;
        // the Gentleman 66-80 4th level band (folio 16) (folio 16)
    if (chrAGLo(3) != 66
            || chrAGHi(3) != 80
            || chrAGLevel(3) != 4
        )
            ++bad;
        // the Gentleman 81-90 5th level band (folio 16) (folio 16)
    if (chrAGLo(4) != 81
            || chrAGHi(4) != 90
            || chrAGLevel(4) != 5
        )
            ++bad;
        // the Gentleman 91-95 6th level band (folio 16) (folio 16)
    if (chrAGLo(5) != 91
            || chrAGHi(5) != 95
            || chrAGLevel(5) != 6
        )
            ++bad;
        // the Gentleman 96-98 7th level band (folio 16) (folio 16)
    if (chrAGLo(6) != 96
            || chrAGHi(6) != 98
            || chrAGLevel(6) != 7
        )
            ++bad;
        // the Gentleman 99-00 8th level band (folio 16) (folio 16)
    if (chrAGLo(7) != 99
            || chrAGHi(7) != 100
            || chrAGLevel(7) != 8
        )
            ++bad;
        // the Noble 01-30 1st level band (folio 16) (folio 16)
    if (chrANLo(0) != 1
            || chrANHi(0) != 30
            || chrANLevel(0) != 1
            || chrAdvNobLevelsCount() != 9
        )
            ++bad;
        // the Noble 31-45 2nd level band (folio 16) (folio 16)
    if (chrANLo(1) != 31
            || chrANHi(1) != 45
            || chrANLevel(1) != 2
        )
            ++bad;
        // the Noble 46-60 3rd level band (folio 16) (folio 16)
    if (chrANLo(2) != 46
            || chrANHi(2) != 60
            || chrANLevel(2) != 3
        )
            ++bad;
        // the Noble 61-75 4th level band (folio 16) (folio 16)
    if (chrANLo(3) != 61
            || chrANHi(3) != 75
            || chrANLevel(3) != 4
        )
            ++bad;
        // the Noble 76-85 5th level band (folio 16) (folio 16)
    if (chrANLo(4) != 76
            || chrANHi(4) != 85
            || chrANLevel(4) != 5
        )
            ++bad;
        // the Noble 86-90 6th level band (folio 16) (folio 16)
    if (chrANLo(5) != 86
            || chrANHi(5) != 90
            || chrANLevel(5) != 6
        )
            ++bad;
        // the Noble 91-94 7th level band (folio 16) (folio 16)
    if (chrANLo(6) != 91
            || chrANHi(6) != 94
            || chrANLevel(6) != 7
        )
            ++bad;
        // the Noble 95-98 8th level band (folio 16) (folio 16)
    if (chrANLo(7) != 95
            || chrANHi(7) != 98
            || chrANLevel(7) != 8
        )
            ++bad;
        // the Noble 99-00 9th level band (folio 16) (folio 16)
    if (chrANLo(8) != 99
            || chrANHi(8) != 100
            || chrANLevel(8) != 9
        )
            ++bad;
        // the Commoner 1-5 fighter band (folio 16) (folio 16)
    if (chrCCLo(0) != 1
            || chrCCHi(0) != 5
            || chrCCCode(0) != 1
            || chrAdvComClassCount() != 2
        )
            ++bad;
        // the Commoner 6-8 thief band (folio 16) (folio 16)
    if (chrCCLo(1) != 6
            || chrCCHi(1) != 8
            || chrCCCode(1) != 2
        )
            ++bad;
        // the Merchant 1-4 fighter band (folio 16) (folio 16)
    if (chrCMLo(0) != 1
            || chrCMHi(0) != 4
            || chrCMCode(0) != 1
            || chrAdvMerClassCount() != 4
        )
            ++bad;
        // the Merchant 5 thief band (folio 16) (folio 16)
    if (chrCMLo(1) != 5
            || chrCMHi(1) != 5
            || chrCMCode(1) != 2
        )
            ++bad;
        // the Merchant 6-7 cleric band (folio 16) (folio 16)
    if (chrCMLo(2) != 6
            || chrCMHi(2) != 7
            || chrCMCode(2) != 3
        )
            ++bad;
        // the Merchant 8 magic-user band (folio 16) (folio 16)
    if (chrCMLo(3) != 8
            || chrCMHi(3) != 8
            || chrCMCode(3) != 4
        )
            ++bad;
        // the Gentleman 1-3 fighter band (folio 16) (folio 16)
    if (chrCGLo(0) != 1
            || chrCGHi(0) != 3
            || chrCGCode(0) != 1
            || chrAdvGenClassCount() != 4
        )
            ++bad;
        // the Gentleman 4 thief band (folio 16) (folio 16)
    if (chrCGLo(1) != 4
            || chrCGHi(1) != 4
            || chrCGCode(1) != 2
        )
            ++bad;
        // the Gentleman 5-6 cleric band (folio 16) (folio 16)
    if (chrCGLo(2) != 5
            || chrCGHi(2) != 6
            || chrCGCode(2) != 3
        )
            ++bad;
        // the Gentleman 7-8 magic-user band (folio 16) (folio 16)
    if (chrCGLo(3) != 7
            || chrCGHi(3) != 8
            || chrCGCode(3) != 4
        )
            ++bad;
        // the Noble 1-3 fighter band (folio 16) (folio 16)
    if (chrCNLo(0) != 1
            || chrCNHi(0) != 3
            || chrCNCode(0) != 1
            || chrAdvNobClassCount() != 4
        )
            ++bad;
        // the Noble 4 thief band (folio 16) (folio 16)
    if (chrCNLo(1) != 4
            || chrCNHi(1) != 4
            || chrCNCode(1) != 2
        )
            ++bad;
        // the Noble 5 cleric band (folio 16) (folio 16)
    if (chrCNLo(2) != 5
            || chrCNHi(2) != 5
            || chrCNCode(2) != 3
        )
            ++bad;
        // the Noble 6-8 magic-user band - the worked example (folio 16)
        // (folio 16)
    if (chrCNLo(3) != 6
            || chrCNHi(3) != 8
            || chrCNCode(3) != 4
        )
            ++bad;
        // the Commoner 2 Half-goblin band (folio 16) (folio 16)
    if (chrR1CLo(0) != 2
            || chrR1CHi(0) != 2
            || chrR1CCode(0) != 1
            || chrRaceCommonerCount() != 5
        )
            ++bad;
        // the Commoner 3 Half-orc band (folio 16) (folio 16)
    if (chrR1CLo(1) != 3
            || chrR1CHi(1) != 3
            || chrR1CCode(1) != 2
        )
            ++bad;
        // the Commoner 4-10 Human band (folio 16) (folio 16)
    if (chrR1CLo(2) != 4
            || chrR1CHi(2) != 10
            || chrR1CCode(2) != 3
        )
            ++bad;
        // the Commoner 11 Half-elf or Dwarf band (folio 16) (folio 16)
    if (chrR1CLo(3) != 11
            || chrR1CHi(3) != 11
            || chrR1CCode(3) != 4
        )
            ++bad;
        // the Commoner 12 Hobbit band (folio 16) (folio 16)
    if (chrR1CLo(4) != 12
            || chrR1CHi(4) != 12
            || chrR1CCode(4) != 5
        )
            ++bad;
        // the Merchant 2 Hobbit band (folio 16) (folio 16)
    if (chrR1MLo(0) != 2
            || chrR1MHi(0) != 2
            || chrR1MCode(0) != 1
            || chrRaceMerchantCount() != 4
        )
            ++bad;
        // the Merchant 3 Half-elf band (folio 16) (folio 16)
    if (chrR1MLo(1) != 3
            || chrR1MHi(1) != 3
            || chrR1MCode(1) != 2
        )
            ++bad;
        // the Merchant 4-11 Human band (folio 16) (folio 16)
    if (chrR1MLo(2) != 4
            || chrR1MHi(2) != 11
            || chrR1MCode(2) != 3
        )
            ++bad;
        // the Merchant 12 Dwarf band (folio 16) (folio 16)
    if (chrR1MLo(3) != 12
            || chrR1MHi(3) != 12
            || chrR1MCode(3) != 4
        )
            ++bad;
        // the Gentleman/Noble 2 Hobbit band (folio 16) (folio 16)
    if (chrR1GLo(0) != 2
            || chrR1GHi(0) != 2
            || chrR1GCode(0) != 1
            || chrRaceGentleNobleCount() != 5
        )
            ++bad;
        // the Gentleman/Noble 3-4 Half-elf band (folio 16) (folio 16)
    if (chrR1GLo(1) != 3
            || chrR1GHi(1) != 4
            || chrR1GCode(1) != 2
        )
            ++bad;
        // the Gentleman/Noble 5-8 Human band (folio 16) (folio 16)
    if (chrR1GLo(2) != 5
            || chrR1GHi(2) != 8
            || chrR1GCode(2) != 3
        )
            ++bad;
        // the Gentleman/Noble 9-10 Dwarf band (folio 16) (folio 16)
    if (chrR1GLo(3) != 9
            || chrR1GHi(3) != 10
            || chrR1GCode(3) != 4
        )
            ++bad;
        // the Gentleman/Noble 11-12 Elf band (folio 16) (folio 16)
    if (chrR1GLo(4) != 11
            || chrR1GHi(4) != 12
            || chrR1GCode(4) != 5
        )
            ++bad;
        // the Half-goblin/Half-orc row - 3, 2, 3, 3, 2, 2 dice (folio 16)
        // (folio 16)
    if (chrDiceRaceCode(0) != 1
            || chrDiceStr(0) != 3
            || chrDiceInt(0) != 2
            || chrDiceWis(0) != 3
            || chrDiceCon(0) != 3
            || chrDiceDex(0) != 2
            || chrDiceCha(0) != 2
            || chrRaceDiceCount() != 6
        )
            ++bad;
        // the Elf row - 3, 3, 4, 3, 4, 4 dice (folio 16) (folio 16)
    if (chrDiceRaceCode(1) != 2
            || chrDiceStr(1) != 3
            || chrDiceInt(1) != 3
            || chrDiceWis(1) != 4
            || chrDiceCon(1) != 3
            || chrDiceDex(1) != 4
            || chrDiceCha(1) != 4
        )
            ++bad;
        // the Dwarf row - 4, 3, 3, 4, 3, 3 dice (folio 16) (folio 16)
    if (chrDiceRaceCode(2) != 3
            || chrDiceStr(2) != 4
            || chrDiceInt(2) != 3
            || chrDiceWis(2) != 3
            || chrDiceCon(2) != 4
            || chrDiceDex(2) != 3
            || chrDiceCha(2) != 3
        )
            ++bad;
        // the Half-elf row - 3, 3, 3, 3, 3, 4 dice (folio 16) (folio 16)
    if (chrDiceRaceCode(3) != 4
            || chrDiceStr(3) != 3
            || chrDiceInt(3) != 3
            || chrDiceWis(3) != 3
            || chrDiceCon(3) != 3
            || chrDiceDex(3) != 3
            || chrDiceCha(3) != 4
        )
            ++bad;
        // the Hobbit row - 2, 3, 3, 4, 4, 3 dice (folio 16) (folio 16)
    if (chrDiceRaceCode(4) != 5
            || chrDiceStr(4) != 2
            || chrDiceInt(4) != 3
            || chrDiceWis(4) != 3
            || chrDiceCon(4) != 4
            || chrDiceDex(4) != 4
            || chrDiceCha(4) != 3
        )
            ++bad;
        // the Human row - 3, 3, 3, 3, 3, 3 dice (folio 16) (folio 16)
    if (chrDiceRaceCode(5) != 6
            || chrDiceStr(5) != 3
            || chrDiceInt(5) != 3
            || chrDiceWis(5) != 3
            || chrDiceCon(5) != 3
            || chrDiceDex(5) != 3
            || chrDiceCha(5) != 3
        )
            ++bad;
        // the Half-goblin/orc row - Strength any, Intelligence 3-12, Wisdom
        // any, Constitution any, Dexterity 3-12, Charisma 3-15 (folio 16)
        // (folio 16)
    if (chrReqRaceCode(0) != 1
            || chrReqStrMin(0) != 3
            || chrReqStrMax(0) != 18
            || chrReqIntMin(0) != 3
            || chrReqIntMax(0) != 12
            || chrReqWisMin(0) != 3
            || chrReqWisMax(0) != 18
            || chrReqConMin(0) != 3
            || chrReqConMax(0) != 18
            || chrReqDexMin(0) != 3
            || chrReqDexMax(0) != 12
            || chrReqChaMin(0) != 3
            || chrReqChaMax(0) != 15
            || chrRaceReqCount() != 6
        )
            ++bad;
        // the Elf row - Strength any, Intelligence any, Wisdom 9-18,
        // Constitution 9-18, Dexterity 9-18, Charisma 13-18 (folio 16) (folio
        // 16)
    if (chrReqRaceCode(1) != 2
            || chrReqStrMin(1) != 3
            || chrReqStrMax(1) != 18
            || chrReqIntMin(1) != 3
            || chrReqIntMax(1) != 18
            || chrReqWisMin(1) != 9
            || chrReqWisMax(1) != 18
            || chrReqConMin(1) != 9
            || chrReqConMax(1) != 18
            || chrReqDexMin(1) != 9
            || chrReqDexMax(1) != 18
            || chrReqChaMin(1) != 13
            || chrReqChaMax(1) != 18
        )
            ++bad;
        // the Dwarf row - Strength 9-18, Intelligence any, Wisdom any,
        // Constitution 13-18, Dexterity any, Charisma any (folio 16) (folio
        // 16)
    if (chrReqRaceCode(2) != 3
            || chrReqStrMin(2) != 9
            || chrReqStrMax(2) != 18
            || chrReqIntMin(2) != 3
            || chrReqIntMax(2) != 18
            || chrReqWisMin(2) != 3
            || chrReqWisMax(2) != 18
            || chrReqConMin(2) != 13
            || chrReqConMax(2) != 18
            || chrReqDexMin(2) != 3
            || chrReqDexMax(2) != 18
            || chrReqChaMin(2) != 3
            || chrReqChaMax(2) != 18
        )
            ++bad;
        // the Half-elf row - Strength any, Intelligence any, Wisdom 9-18,
        // Constitution any, Dexterity any, Charisma 13-18 (folio 16) (folio
        // 16)
    if (chrReqRaceCode(3) != 4
            || chrReqStrMin(3) != 3
            || chrReqStrMax(3) != 18
            || chrReqIntMin(3) != 3
            || chrReqIntMax(3) != 18
            || chrReqWisMin(3) != 9
            || chrReqWisMax(3) != 18
            || chrReqConMin(3) != 3
            || chrReqConMax(3) != 18
            || chrReqDexMin(3) != 3
            || chrReqDexMax(3) != 18
            || chrReqChaMin(3) != 13
            || chrReqChaMax(3) != 18
        )
            ++bad;
        // the Hobbit row - Strength 3-12, Intelligence any, Wisdom any,
        // Constitution 13-18, Dexterity 13-18, Charisma any (folio 16) (folio
        // 16)
    if (chrReqRaceCode(4) != 5
            || chrReqStrMin(4) != 3
            || chrReqStrMax(4) != 12
            || chrReqIntMin(4) != 3
            || chrReqIntMax(4) != 18
            || chrReqWisMin(4) != 3
            || chrReqWisMax(4) != 18
            || chrReqConMin(4) != 13
            || chrReqConMax(4) != 18
            || chrReqDexMin(4) != 13
            || chrReqDexMax(4) != 18
            || chrReqChaMin(4) != 3
            || chrReqChaMax(4) != 18
        )
            ++bad;
        // the Human row - any in all six (folio 16) (folio 16)
    if (chrReqRaceCode(5) != 6
            || chrReqStrMin(5) != 3
            || chrReqStrMax(5) != 18
            || chrReqIntMin(5) != 3
            || chrReqIntMax(5) != 18
            || chrReqWisMin(5) != 3
            || chrReqWisMax(5) != 18
            || chrReqConMin(5) != 3
            || chrReqConMax(5) != 18
            || chrReqDexMin(5) != 3
            || chrReqDexMax(5) != 18
            || chrReqChaMin(5) != 3
            || chrReqChaMax(5) != 18
        )
            ++bad;
        // the Commoner 01-85 nil band (folio 16) (folio 16)
    if (chrPCLo(0) != 1
            || chrPCHi(0) != 85
            || chrPCMult(0) != 0
            || chrPrevComCount() != 4
        )
            ++bad;
        // the Commoner 86-96 x20 band (folio 16) (folio 16)
    if (chrPCLo(1) != 86
            || chrPCHi(1) != 96
            || chrPCMult(1) != 20
        )
            ++bad;
        // the Commoner 97-99 x30 band (folio 16) (folio 16)
    if (chrPCLo(2) != 97
            || chrPCHi(2) != 99
            || chrPCMult(2) != 30
        )
            ++bad;
        // the Commoner 00 x50 band, the 00 pinned as 100 (folio 16) (folio
        // 16)
    if (chrPCLo(3) != 100
            || chrPCHi(3) != 100
            || chrPCMult(3) != 50
        )
            ++bad;
        // the Merchant 01-70 nil band (folio 16) (folio 16)
    if (chrPMLo(0) != 1
            || chrPMHi(0) != 70
            || chrPMMult(0) != 0
            || chrPrevMerCount() != 5
        )
            ++bad;
        // the Merchant 71-90 x20 band (folio 16) (folio 16)
    if (chrPMLo(1) != 71
            || chrPMHi(1) != 90
            || chrPMMult(1) != 20
        )
            ++bad;
        // the Merchant 91-96 x30 band (folio 16) (folio 16)
    if (chrPMLo(2) != 91
            || chrPMHi(2) != 96
            || chrPMMult(2) != 30
        )
            ++bad;
        // the Merchant 97-99 x50 band (folio 16) (folio 16)
    if (chrPMLo(3) != 97
            || chrPMHi(3) != 99
            || chrPMMult(3) != 50
        )
            ++bad;
        // the Merchant 00 x70 band (folio 16) (folio 16)
    if (chrPMLo(4) != 100
            || chrPMHi(4) != 100
            || chrPMMult(4) != 70
        )
            ++bad;
        // the Gentleman 01-60 nil band (folio 16) (folio 16)
    if (chrPGLo(0) != 1
            || chrPGHi(0) != 60
            || chrPGMult(0) != 0
            || chrPrevGenCount() != 6
        )
            ++bad;
        // the Gentleman 61-80 x20 band (folio 16) (folio 16)
    if (chrPGLo(1) != 61
            || chrPGHi(1) != 80
            || chrPGMult(1) != 20
        )
            ++bad;
        // the Gentleman 81-93 x30 band (folio 16) (folio 16)
    if (chrPGLo(2) != 81
            || chrPGHi(2) != 93
            || chrPGMult(2) != 30
        )
            ++bad;
        // the Gentleman 94-97 x50 band (folio 16) (folio 16)
    if (chrPGLo(3) != 94
            || chrPGHi(3) != 97
            || chrPGMult(3) != 50
        )
            ++bad;
        // the Gentleman 98-99 x70 band (folio 16) (folio 16)
    if (chrPGLo(4) != 98
            || chrPGHi(4) != 99
            || chrPGMult(4) != 70
        )
            ++bad;
        // the Gentleman 00 x100 band (folio 16) (folio 16)
    if (chrPGLo(5) != 100
            || chrPGHi(5) != 100
            || chrPGMult(5) != 100
        )
            ++bad;
        // the Noble 01-50 nil band (folio 16) (folio 16)
    if (chrPNLo(0) != 1
            || chrPNHi(0) != 50
            || chrPNMult(0) != 0
            || chrPrevNobCount() != 7
        )
            ++bad;
        // the Noble 51-70 x20 band (folio 16) (folio 16)
    if (chrPNLo(1) != 51
            || chrPNHi(1) != 70
            || chrPNMult(1) != 20
        )
            ++bad;
        // the Noble 71-85 x30 band (folio 16) (folio 16)
    if (chrPNLo(2) != 71
            || chrPNHi(2) != 85
            || chrPNMult(2) != 30
        )
            ++bad;
        // the Noble 86-92 x50 band - the worked example's 89 (folio 16)
        // (folio 16)
    if (chrPNLo(3) != 86
            || chrPNHi(3) != 92
            || chrPNMult(3) != 50
        )
            ++bad;
        // the Noble 93-97 x70 band (folio 16) (folio 16)
    if (chrPNLo(4) != 93
            || chrPNHi(4) != 97
            || chrPNMult(4) != 70
        )
            ++bad;
        // the Noble 98-99 x100 band (folio 16) (folio 16)
    if (chrPNLo(5) != 98
            || chrPNHi(5) != 99
            || chrPNMult(5) != 100
        )
            ++bad;
        // the Noble 00 x130 band (folio 16) (folio 16)
    if (chrPNLo(6) != 100
            || chrPNHi(6) != 100
            || chrPNMult(6) != 130
        )
            ++bad;
        printf("R898 character round audit: bad %d\n", bad);
        if (bad) return 1;
    }
