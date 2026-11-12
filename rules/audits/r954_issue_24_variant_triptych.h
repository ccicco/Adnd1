    // ---- R954 issue-24 variant triptych audit ----
    // the three-chain variant triptych audit - the lost civilizations
    // supplement, the Chinese dragons roster and the lycanthropy infection
    // types
    {
        using namespace rules;
        int bad = 0;
    if (t24LostCityRollHi() != 3
            || t24TyrantBandHi() != 3
            || t24TyrantWarriorAdd() != 10
            || t24PriestWarriorAdd() != 5
            || t24ReactionAdd() != 9
            || t24GoddessReactionBonus() != 1
            || t24GuideReactionPenalty() != 1
            || t24AskariKill() != 1
            || t24ExplorerKill() != 2
            || t24MissionaryKill() != 1
            || t24BearersFleeDivisor() != 2
            || t24EscapeGold() != 100
            || t24EscapeDiamonds() != 500
            || t24TriumphDiamonds() != 1000
            || t24DesertLootGems() != 1000
            || t24BearerGold() != 200
            || t24NovelistFee() != 500
            || t24CurseDiePenalty() != 2
            || t24ReenterBonus() != 1
            || t24WifeBonus() != 2
            || t24UnderdogStake() != 700
            || t24UnderdogPoints() != 5
            || t24LairPct() != 60
            || t24PsionicClass() != 6
            || t24EspRadiusMult() != 5
            || t24ScalyCommandHoursLo() != 2
            || t24ScalyCommandHoursHi() != 12
            || t24WaterFireRoundsLo() != 20
            || t24WaterFireRoundsHi() != 120
            || t24TienFirePerDay() != 6
            || t24TienControlMult() != 2
            || t24TienServantPct() != 50
            || t24ShenSpellPerDay() != 3
            || t24ShenBiteHi() != 24
            || t24ShenWaterFireHi() != 12
            || t24ShenInsectRadius() != 6
            || t24LiQuakeMult() != 3
            || t24LiBiteHi() != 20
            || t24PanConstrictHi() != 12
            || t24PanCharmPerDay() != 3
            || t24PanScalyHi() != 10
            || t24WangSteamPerDay() != 3
            || t24WangBiteHi() != 36
            || t24WangScalyHi() != 40
            || t24YuAdultCap() != 5
            || t24YuLandHour() != 1
            || t24DragonTypeCount() != 6
            || t24InfectionThresholdPct() != 50
            || t24OnsetAHi() != 8
            || t24OnsetBHi() != 36
            || t24OnsetCHi() != 24
            || t24OnsetDHi() != 12
            || t24OnsetEfHi() != 16
            || t24OnsetGHi() != 10
            || t24CureClericCLevel() != 7
            || t24CureClericGLevel() != 8
            || t24FullMoonPct() != 95
            || t24StressBasePct() != 40
            || t24FormDurationHi() != 12
            || t24HalvedPowersDivisor() != 2
            || t24TypeGRatSummonHi() != 50
            || t24ShieldKeepPct() != 10
            || t24WerewolfShieldAc() != 4
            || t24DropSuppliesPct() != 65
            || t24DropTypeGPct() != 40
            || t24MaxLevelDivisor() != 3
            || t24PoisonSaveExample() != 9
            || t24LycanBandCount() != 7
            || t24LycanAlignCount() != 9
            || t24LycanAttrCount() != 5
            || !t24SotnFantasySupplement()
            || !t24DesertCityUninhabited()
            || !t24AtlantisSurvivors()
            || !t24AncientGreekSpeech()
            || !t24GuestsOfTheCity()
            || !t24SurpriseMuskets()
            || !t24MosasaurusPool()
            || !t24RebelAspirant()
            || !t24GoddessLovesExplorer()
            || !t24DuelOfMagic()
            || !t24DesertCurseRides()
            || !t24ExclusiveReturn()
            || !t24PowersByType()
            || !t24OnlyYuSubduable()
            || !t24PolymorphHuman()
            || !t24VisibleWhenAttacking()
            || !t24ScalyCommandImmune()
            || !t24ScalyCommandNoSave()
            || !t24WaterFireImmune()
            || !t24TienWinglessFlight()
            || t24ShenNoBreath()
            || !t24ShenLightningImmune()
            || !t24ShenDoubleFire()
            || !t24ShenPoisonImmune()
            || !t24LiQuakeImmune()
            || !t24LiHulkTunnel()
            || !t24PanGraspConstrict()
            || !t24WangTribute()
            || t24YuNoPolymorph()
            || !t24YuMetamorphosis()
            || !t24SevenInfectionTypes()
            || !t24TypeANewCharacter()
            || !t24TypeBMentalOnly()
            || !t24TypeCPhysicalOnly()
            || !t24MoonStressTypes()
            || !t24PartManPartMonster()
            || !t24AlignmentFixedFirst()
            || !t24LawfulGoodChaoticEvil()
            || !t24SeparateSheet()
            || !t24GFormAdvantage()
            || !t24WerebearLawfulGood()
            || !t24ArmorSense()
            || !t24LevelStepsUnchanged()
            || !t24LanguagesAutomatic()
            || !t24DungeonmasterFinalWord()
        )
            ++bad;
        // the Chinese dragon summary roster by print order - the Celestial
        // Tien Lung through the Carp Yu Lung, number appearing, hit dice,
        // armor class and the walk fly swim rates with the no-fly sentinel at
        // the Lung Wang and Yu Lung rows
        int CDg[6][8] = {
            {1,1,11,13,-2,9,48,6},
            {1,4,9,11,1,12,12,9},
            {1,4,7,9,4,9,24,6},
            {1,4,6,8,2,12,12,9},
            {1,1,11,13,0,3,-99,9},
            {1,4,5,7,3,6,-99,18},
            };
        for (int b = 0;
             b < t24DragonTypeCount();
             ++b) {
            int vals[8];
            vals[0] = t24DgAppearLo(b);
            vals[1] = t24DgAppearHi(b);
            vals[2] = t24DgHdLo(b);
            vals[3] = t24DgHdHi(b);
            vals[4] = t24DgAc(b);
            vals[5] = t24DgWalk(b);
            vals[6] = t24DgFly(b);
            vals[7] = t24DgSwim(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CDg[b][c])
                    ++bad;
            }
        }
        // the infection dice-roll bands - the seven lycanthrope types A
        // through G from the one-to-fifteen band through the
        // seventy-one-to-double-nought read as one hundred
        int CLy[7][2] = {
            {1,15},
            {16,20},
            {21,25},
            {26,50},
            {51,60},
            {61,70},
            {71,100},
            };
        for (int b = 0;
             b < t24LycanBandCount();
             ++b) {
            int vals[2];
            vals[0] = t24LyLo(b);
            vals[1] = t24LyHi(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CLy[b][c])
                    ++bad;
            }
        }
        // the alignment comparison matrix - the creature alignment against
        // the player alignment, the lawful neutral chaotic percentage chances
        // with the dashes pinned as zero, the lawful-chaotic crosses reading
        // twenty sixty twenty both directions
        int CAl[9][3] = {
            {100,0,0},
            {60,40,0},
            {20,60,20},
            {45,55,0},
            {0,100,0},
            {0,55,45},
            {20,60,20},
            {0,40,60},
            {0,0,100},
            };
        for (int b = 0;
             b < t24LycanAlignCount();
             ++b) {
            int vals[3];
            vals[0] = t24AlLawful(b);
            vals[1] = t24AlNeutral(b);
            vals[2] = t24AlChaotic(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CAl[b][c])
                    ++bad;
            }
        }
        // the attribute modifier table as printed - rat, wolf, boar, tiger
        // and the duplicate Boar row which reads the bear line, the printed
        // dashes pinned as zero, the conversion noted at the fifth row
        int CAt[5][6] = {
            {0,0,1,0,-3,4},
            {-1,2,5,-2,-3,3},
            {-4,4,3,-4,-5,1},
            {-3,5,4,-3,-4,2},
            {-1,6,4,-1,-2,0},
            };
        for (int b = 0;
             b < t24LycanAttrCount();
             ++b) {
            int vals[6];
            vals[0] = t24AtInt(b);
            vals[1] = t24AtStr(b);
            vals[2] = t24AtCon(b);
            vals[3] = t24AtWis(b);
            vals[4] = t24AtCha(b);
            vals[5] = t24AtDex(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CAt[b][c])
                    ++bad;
            }
        }
        // the lost-city frame - the two-or-three discovery roll and the
        // tyrant and priest organization counts the lost civilizations Source
        // of the Nile variant (print 5-6)
    if (t24LostCityRollHi() != 3
            || t24TyrantBandHi() != 3
            || t24TyrantWarriorAdd() != 10
            || t24PriestWarriorAdd() != 5
            || t24AtlantisSurvivors() != 1
        )
            ++bad;
        // the reaction modifiers - the nine add, the goddess bonus one and
        // the neighboring-guide penalty the lost civilizations Source of the
        // Nile variant (print 5-6)
    if (t24ReactionAdd() != 9
            || t24GoddessReactionBonus() != 1
            || t24GuideReactionPenalty() != 1
            || t24AncientGreekSpeech() != 1
        )
            ++bad;
        // the battle math - the musket kills, the Modified Gygax missionary
        // rule and the bearers halved the lost civilizations Source of the
        // Nile variant (print 5-6)
    if (t24AskariKill() != 1
            || t24ExplorerKill() != 2
            || t24MissionaryKill() != 1
            || t24BearersFleeDivisor() != 2
            || t24SurpriseMuskets() != 1
        )
            ++bad;
        // the treasure ladder - one hundred at the breakout, five hundred
        // through the duel and volcano, one thousand at the triumph the lost
        // civilizations Source of the Nile variant (print 5-6)
    if (t24EscapeGold() != 100
            || t24EscapeDiamonds() != 500
            || t24TriumphDiamonds() != 1000
            || t24BearerGold() != 200
            || t24NovelistFee() != 500
            || t24DesertLootGems() != 1000
        )
            ++bad;
        // the curse and return - the two-man penalty, the re-entry and wife
        // bonuses and the Underdog saga the lost civilizations Source of the
        // Nile variant (print 5-6)
    if (t24CurseDiePenalty() != 2
            || t24ReenterBonus() != 1
            || t24WifeBonus() != 2
            || t24UnderdogPoints() != 5
            || t24UnderdogStake() != 700
            || t24DesertCurseRides() != 1
        )
            ++bad;
        // the general frame - the sixty percent lair, psionic class six and
        // the five-times ESP radius the Chinese dragons variant roster (print
        // 8-9)
    if (t24LairPct() != 60
            || t24PsionicClass() != 6
            || t24EspRadiusMult() != 5
            || t24OnlyYuSubduable() != 1
            || t24PowersByType() != 1
        )
            ++bad;
        // the shared powers - the Scaly Command duration and the Water Fire
        // real-fire absence the Chinese dragons variant roster (print 8-9)
    if (t24ScalyCommandHoursHi() != 12
            || t24ScalyCommandHoursLo() != 2
            || t24WaterFireRoundsHi() != 120
            || t24WaterFireRoundsLo() != 20
            || t24ScalyCommandImmune() != 1
            || t24WaterFireImmune() != 1
        )
            ++bad;
        // the Celestial sort - six fire cones a day, Control Weather at
        // double the age level and the fifty percent servants the Chinese
        // dragons variant roster (print 8-9)
    if (t24TienFirePerDay() != 6
            || t24TienControlMult() != 2
            || t24TienServantPct() != 50
            || t24TienWinglessFlight() != 1
        )
            ++bad;
        // the river sort - the three spells, the two-to-twenty-four bite and
        // the no-breath-weapon pin the Chinese dragons variant roster (print
        // 8-9)
    if (t24ShenSpellPerDay() != 3
            || t24ShenBiteHi() != 24
            || t24ShenWaterFireHi() != 12
            || t24ShenInsectRadius() != 6
            || t24ShenNoBreath() != 0
        )
            ++bad;
        // the earth sort - the tripled Earthquake and the Umber Hulk
        // tunneling the Chinese dragons variant roster (print 8-9)
    if (t24LiQuakeMult() != 3
            || t24LiBiteHi() != 20
            || t24LiQuakeImmune() != 1
            || t24LiHulkTunnel() != 1
        )
            ++bad;
        // the coiled and sea sorts - the constrict, the Charm Monster and the
        // steam and tribute brute the Chinese dragons variant roster (print
        // 8-9)
    if (t24PanConstrictHi() != 12
            || t24PanCharmPerDay() != 3
            || t24PanScalyHi() != 10
            || t24WangSteamPerDay() != 3
            || t24WangBiteHi() != 36
            || t24WangScalyHi() != 40
        )
            ++bad;
        // the carp sort - the adult cap at five, the one-hour landfall and
        // the metamorphosis the Chinese dragons variant roster (print 8-9)
    if (t24YuAdultCap() != 5
            || t24YuLandHour() != 1
            || t24YuMetamorphosis() != 1
            || t24YuNoPolymorph() != 0
        )
            ++bad;
        // the infection frame - the fifty-percent threshold and the A B C
        // onset bands the lycanthropy infection variant (print 10-11)
    if (t24InfectionThresholdPct() != 50
            || t24OnsetAHi() != 8
            || t24OnsetBHi() != 36
            || t24OnsetCHi() != 24
            || t24SevenInfectionTypes() != 1
        )
            ++bad;
        // the stress types - the D E F G onsets and the two-to-twelve-turn
        // hold the lycanthropy infection variant (print 10-11)
    if (t24OnsetDHi() != 12
            || t24OnsetEfHi() != 16
            || t24OnsetGHi() != 10
            || t24FormDurationHi() != 12
            || t24MoonStressTypes() != 1
        )
            ++bad;
        // the G sort - the ninety-five percent full moon, the forty-percent
        // stress base and the halved powers the lycanthropy infection variant
        // (print 10-11)
    if (t24FullMoonPct() != 95
            || t24StressBasePct() != 40
            || t24PartManPartMonster() != 1
            || t24HalvedPowersDivisor() != 2
            || t24TypeGRatSummonHi() != 50
        )
            ++bad;
        // the cures and the worked save - the seventh and eighth cleric
        // levels and the nine needed in were-wolf form the lycanthropy
        // infection variant (print 10-11)
    if (t24CureClericCLevel() != 7
            || t24CureClericGLevel() != 8
            || t24PoisonSaveExample() != 9
            || t24AlignmentFixedFirst() != 1
            || t24LawfulGoodChaoticEvil() != 1
        )
            ++bad;
        // the equipment bookkeeping - the shield chance, the drop percentages
        // and the max-level third the lycanthropy infection variant (print
        // 10-11)
    if (t24ShieldKeepPct() != 10
            || t24WerewolfShieldAc() != 4
            || t24DropSuppliesPct() != 65
            || t24DropTypeGPct() != 40
            || t24MaxLevelDivisor() != 3
            || t24WerebearLawfulGood() != 1
        )
            ++bad;
        // the Celestial row - solitary, eleven to thirteen dice, minus two
        // and the forty-eight fly the Chinese dragons variant roster (print
        // 8-9)
    if (t24DgAppearLo(0) != 1
            || t24DgHdLo(0) != 11
            || t24DgHdHi(0) != 13
            || t24DgAc(0) != -2
            || t24DgWalk(0) != 9
            || t24DgFly(0) != 48
            || t24DgSwim(0) != 6
        )
            ++bad;
        // the middle sorts - the Shen Li and Pan armor classes and walk rates
        // the Chinese dragons variant roster (print 8-9)
    if (t24DgAc(1) != 1
            || t24DgWalk(1) != 12
            || t24DgAc(2) != 4
            || t24DgWalk(2) != 9
            || t24DgAc(3) != 2
            || t24DgWalk(3) != 12
        )
            ++bad;
        // the sea and carp rows - the zero-class no-fly brute and the
        // eighteen-swim carp the Chinese dragons variant roster (print 8-9)
    if (t24DgAc(4) != 0
            || t24DgWalk(4) != 3
            || t24DgFly(4) != -99
            || t24DgSwim(4) != 9
            || t24DgHdLo(5) != 5
            || t24DgFly(5) != -99
            || t24DgSwim(5) != 18
        )
            ++bad;
        // the infection band spot check - the A D and G bands the lycanthropy
        // infection variant (print 10-11)
    if (t24LyLo(0) != 1
            || t24LyHi(0) != 15
            || t24LyLo(3) != 26
            || t24LyHi(3) != 50
            || t24LyLo(6) != 71
            || t24LyHi(6) != 100
        )
            ++bad;
        // the alignment matrix spot check - the matched lawful row and the
        // twenty-sixty-twenty lawful-chaotic cross the lycanthropy infection
        // variant (print 10-11)
    if (t24AlLawful(0) != 100
            || t24AlNeutral(0) != 0
            || t24AlLawful(2) != 20
            || t24AlNeutral(2) != 60
            || t24AlChaotic(2) != 20
        )
            ++bad;
        // the matched neutral and chaotic rows with the neutral-chaotic cross
        // the lycanthropy infection variant (print 10-11)
    if (t24AlNeutral(4) != 100
            || t24AlLawful(4) != 0
            || t24AlChaotic(8) != 100
            || t24AlNeutral(5) != 55
            || t24AlChaotic(5) != 45
        )
            ++bad;
        // the rat and wolf rows - the constitution, charisma and dexterity
        // modifiers the lycanthropy infection variant (print 10-11)
    if (t24AtCon(0) != 1
            || t24AtCha(0) != -3
            || t24AtDex(0) != 4
            || t24AtCon(1) != 5
            || t24AtDex(1) != 3
        )
            ++bad;
        // the duplicate-Boar bear row and the true boar row as printed, the
        // conversion noted the lycanthropy infection variant (print 10-11)
    if (t24AtStr(4) != 6
            || t24AtCon(4) != 4
            || t24AtWis(4) != -1
            || t24AtInt(2) != -4
            || t24AtCha(2) != -5
        )
            ++bad;
        printf("R954 issue-24 variant triptych audit: bad %d\n", bad);
        if (bad) return 1;
    }
