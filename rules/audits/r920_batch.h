    // ---- R920 issue-12 opener part two audit ----
    // THE DRAGON ISSUE-12 OPENER ROUND, PART TWO - the mythos pair, both
    // GD&H-compatible D&D-statted chains. The Persian Mythos by Jerome
    // Arkenberg (folios 8-11): the dualist split of the gods, the Ahura Mazda
    // and Ahriman supreme pair, the seven archangels on their common stat
    // block, the seven yazatas with Vayu, Tishtrya, Ardvi Sura Anahita,
    // Verethragna, Rapithwin, Atar and Haoma, the six heroes on the common
    // Lord-12th block with their stat lines, and the archdemons and demons -
    // the Atar armor-class and psionic cells print bar garbles and the hero
    // strength cells print as fraction garbles (185, 189, 1859, 18;;, 18,5),
    // all riding the sentinel as-scanned, never silent. The Lovecraftian
    // Mythos by Rob Kuntz with J. Eric Holmes, the Sorcerer's Scroll (folios
    // 18-21): the calling risks, the five Great Old Ones plus Cthuga,
    // Ithaqua, Yig and Yog Sothoth on the stat grid, the six partly-human
    // races, the Necronomicon madness roll and the Elder Sign - the Yig split
    // armor class (3 head, 5 chest) pins as consts with the grid cell riding
    // the sentinel, and the see-below magic cells and resistant-to-psionics
    // cells ride the sentinel with the census. THE FLIP: the part-one box in
    // tools/dragon_gap_report_012.md went [x] - 1 closed, 1 open, the closing
    // round to follow.
    {
        using namespace rules;
        int bad = 0;
    if (mytPersianRows() != 13
            || mytPersianHeroRows() != 6
            || mytPersianArchangels() != 7
            || mytPersianYazatas() != 7
            || mytSraoshaBattleAxePlus() != 3
            || mytMithraPikePlus() != 1
            || mytMithraArmorPlus() != 3
            || mytVayuSpearPlus() != 1
            || mytVayuGoldWeaponsPlus() != 2
            || mytTishtryaForms() != 3
            || mytVerethragnaForms() != 10
            || mytGOORows() != 9
            || mytRaceRows() != 6
            || mytCallDestroyedPercent() != 25
            || mytCallServantPercent() != 50
            || mytCallGodPercent() != 25
            || mytRavageMinTurns() != 1
            || mytRavageMaxTurns() != 6
            || mytAzathothSaveVsMagic() != 5
            || mytCthulhuRegen() != 10
            || mytCthulhuInsanityRadiusMiles() != 100
            || mytCthulhuDeepOnesMin() != 10
            || mytCthulhuDeepOnesMax() != 100
            || mytHasturRegen() != 5
            || mytHasturFlyInches() != 36
            || mytHasturCallsMin() != 1
            || mytHasturCallsMax() != 10
            || mytNyarlathotepCharmRadiusFeet() != 30
            || mytNyarlathotepCharmSavePenalty() != 2
            || mytNyarlathotepArmyMin() != 10
            || mytNyarlathotepArmyMax() != 1000
            || mytShubPoolDiameterFeet() != 100
            || mytShubSpawnMin() != 1
            || mytShubSpawnMax() != 10
            || mytShubCharmLevel() != 15
            || mytCthugaFireSpellsPerDay() != 3
            || mytCthugaFireElementals() != 8
            || mytCthugaElementalHD() != 12
            || mytCthugaDamageMin() != 3
            || mytCthugaDamageMax() != 30
            || mytCthugaIgnitionRadiusYards() != 10
            || mytCthugaWeaponPlusNeeded() != 3
            || mytIthaquaAirElementalHD() != 16
            || mytIthaquaDamageMin() != 2
            || mytIthaquaDamageMax() != 16
            || mytIthaquaFireExtraPerDie() != 2
            || mytYigHeadAc() != 3
            || mytYigBodyAc() != 5
            || mytYigSurpriseMin() != 1
            || mytYigSurpriseMax() != 4
            || mytYigControlRadiusMiles() != 1
            || mytYigSnakesMin() != 2
            || mytYigSnakesMax() != 20
            || mytYigSnakeHDMin() != 4
            || mytYigSnakeHDMax() != 6
            || mytYigFangDamageMin() != 2
            || mytYigFangDamageMax() != 11
            || mytYigPoisonSavePenalty() != 3
            || mytYogGatesPerMelee() != 1
            || mytByakheeTalonDamageMin() != 2
            || mytByakheeTalonDamageMax() != 12
            || mytByakheeBeakDamageMin() != 2
            || mytByakheeBeakDamageMax() != 9
            || mytDeepOnesMin() != 1
            || mytDeepOnesMax() != 100
            || mytDeepOnesClericMin() != 3
            || mytDeepOnesClericMax() != 10
            || mytMiGoFlyInches() != 30
            || mytElderSignAc() != -2
            || mytNecronomiconMadnessPercent() != 25
            || mytNecronomiconLevelCutoff() != 5
            || !mytPersianDualistSplit()
            || !mytHaomaPlantAndGod()
            || !mytTishtryaSustainedBySacrifice()
            || !mytAzathothMindless()
            || !mytCthulhuResistantWaterColdVacuum()
            || !mytCthulhuRetreatsAtElderSign()
            || !mytHasturImmuneColdVacuum()
            || !mytHasturFearSaveRequired()
            || !mytNyarlathotepCharmOneSaveOnly()
            || !mytShubMonstersAttackOnCommand()
            || !mytCthugaPlusThreeWeaponsOnly()
            || !mytCthugaMetalMelts()
            || !mytIthaquaWindWalkAtWill()
            || !mytIthaquaAirElementalRoamsFree()
            || !mytYigRangerSenses()
            || !mytYigPoisonSaveFailsDies()
            || !mytYogNotSubjectToSpaceTime()
            || !mytByakheeProtectedColdVacuum()
            || !mytByakheeElderSignObeys()
            || !mytDeepOnesAmphibious()
            || !mytGreatRaceMindSwap()
            || !mytGreatRaceLawfulNeutral()
            || !mytMiGoImmuneColdVacuum()
            || !mytElderSignCharmVsMinions()
            || !mytElderSignWeakerVsGOO()
        )
            ++bad;
        // the Persian Mythos stat grid - the Atar armor-class and psionic
        // cells print bar garbles, the Vayu move prints the 187/36 fraction
        // garble, and the Ahura Mazda and Ahriman unlimited hit-point and
        // spell cells print words: all ride the -1 sentinel as scanned, the
        // hero block riding As a Normal Man, noted never silent (folios 8-10)
        int CPS[13][6] = {
            {-2,20,-1,-1,40,6},
            {-2,20,300,-1,40,6},
            {2,18,250,20,15,1},
            {2,-1,250,14,15,2},
            {2,15,225,14,14,2},
            {2,15,175,14,11,2},
            {2,15,250,14,15,2},
            {2,15,225,14,14,2},
            {-1,18,250,14,14,-1},
            {3,15,175,12,10,3},
            {-1,12,100,0,12,0},
            {2,18,250,20,15,1},
            {2,15,200,14,14,2},
            };
        int nPS[6] = {0,0,0,0,0,0};
        int ePS[6] = {2,1,1,2,0,1};
        for (int b = 0;
             b < mytPersianRows();
             ++b) {
            int vals[6];
            vals[0] = mytPersianAc(b);
            vals[1] = mytPersianMove(b);
            vals[2] = mytPersianHp(b);
            vals[3] = mytPersianMagicLvl(b);
            vals[4] = mytPersianFightLvl(b);
            vals[5] = mytPersianPsiClass(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CPS[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nPS[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nPS[c] != ePS[c])
                ++bad;
        // the six Persian hero stat lines - the strength cells print as
        // fraction garbles (185, 189, 1859, 18;;, 18,5), five cells riding
        // the -1 sentinel with the census, Thrita the one clean strength line
        // pinning clean, noted as scanned never silent (folio 10)
        int CPH[6][6] = {
            {-1,17,9,17,17,17},
            {-1,17,13,18,17,16},
            {-1,16,12,16,16,16},
            {15,17,18,15,12,12},
            {-1,14,8,17,17,15},
            {-1,14,12,17,17,17},
            };
        int nPH[6] = {0,0,0,0,0,0};
        int ePH[6] = {5,0,0,0,0,0};
        for (int b = 0;
             b < mytPersianHeroRows();
             ++b) {
            int vals[6];
            vals[0] = mytPersianHeroStr(b);
            vals[1] = mytPersianHeroInt(b);
            vals[2] = mytPersianHeroWis(b);
            vals[3] = mytPersianHeroCon(b);
            vals[4] = mytPersianHeroDex(b);
            vals[5] = mytPersianHeroCha(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CPH[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nPH[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nPH[c] != ePH[c])
                ++bad;
        // the Great Old Ones stat grid - the Yig split armor class pins as
        // the head-3 chest-5 consts with the grid cell riding the -1
        // sentinel; the Azathoth infinite move, the Shub-Niggurath see-below
        // fighter level, the six see-below magic cells and the Azathoth and
        // Hastur psionic-resistance text cells all ride the sentinel with the
        // census, noted never silent (folios 18-20)
        int CGO[9][6] = {
            {-2,-1,300,20,0,-1},
            {2,12,200,15,-1,1},
            {2,12,200,20,-1,-1},
            {2,12,150,15,15,2},
            {4,6,300,-1,-1,2},
            {2,12,175,17,-1,6},
            {2,12,175,16,-1,6},
            {-1,18,125,15,-1,6},
            {2,24,300,20,15,1},
            };
        int nGO[6] = {0,0,0,0,0,0};
        int eGO[6] = {1,1,0,1,6,2};
        for (int b = 0;
             b < mytGOORows();
             ++b) {
            int vals[6];
            vals[0] = mytGOOAc(b);
            vals[1] = mytGOOMove(b);
            vals[2] = mytGOOHp(b);
            vals[3] = mytGOOFightLvl(b);
            vals[4] = mytGOOMagicLvl(b);
            vals[5] = mytGOOPsiClass(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CGO[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nGO[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nGO[c] != eGO[c])
                ++bad;
        // the inhuman and partly-human races grid - the Byakhee and Mi-Go
        // see-below magic cells and the Shaggoth psionic-resistance cell ride
        // the -1 sentinel with the census, the none cells pinning zero, noted
        // never silent (folio 21)
        int CMR[6][6] = {
            {5,36,100,10,-1,5},
            {3,12,10,3,0,0},
            {5,12,30,6,0,1},
            {5,12,50,8,0,0},
            {3,15,35,8,-1,5},
            {4,18,70,8,0,-1},
            };
        int nMR[6] = {0,0,0,0,0,0};
        int eMR[6] = {0,0,0,0,2,1};
        for (int b = 0;
             b < mytRaceRows();
             ++b) {
            int vals[6];
            vals[0] = mytRaceAc(b);
            vals[1] = mytRaceMove(b);
            vals[2] = mytRaceHp(b);
            vals[3] = mytRaceFightLvl(b);
            vals[4] = mytRaceMagicLvl(b);
            vals[5] = mytRacePsiClass(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CMR[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nMR[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nMR[c] != eMR[c])
                ++bad;
        // the Ahura Mazda row - armor class minus 2, move 20, Lord 40th,
        // psionic Class 6, the unlimited hit-point and spell cells riding the
        // sentinel (folio 8)
    if (mytPersianAc(0) != -2
            || mytPersianMove(0) != 20
            || mytPersianFightLvl(0) != 40
            || mytPersianPsiClass(0) != 6
        )
            ++bad;
        // the Ahriman row - armor class minus 2, 300 hit points, move 20,
        // Class 6 (folio 10)
    if (mytPersianAc(1) != -2
            || mytPersianHp(1) != 300
            || mytPersianMove(1) != 20
            || mytPersianPsiClass(1) != 6
        )
            ++bad;
        // the archangel common block - armor class 2, move 18, 250 hit
        // points, Wizard 20th, Lord 15th, Class 1 (folios 8-9)
    if (mytPersianAc(2) != 2
            || mytPersianMove(2) != 18
            || mytPersianHp(2) != 250
            || mytPersianMagicLvl(2) != 20
            || mytPersianFightLvl(2) != 15
            || mytPersianPsiClass(2) != 1
        )
            ++bad;
        // the Atar row - the armor-class and psionic cells print bar garbles
        // and ride the sentinel, 250 hit points and move 18 pinning clean
        // (folio 9)
    if (mytPersianAc(8) != -1
            || mytPersianPsiClass(8) != -1
            || mytPersianHp(8) != 250
            || mytPersianMove(8) != 18
        )
            ++bad;
        // the Haoma row - armor class 3, 175 hit points, Wizard 12th, Lord
        // 10th, Class 3 (folio 9)
    if (mytPersianAc(9) != 3
            || mytPersianHp(9) != 175
            || mytPersianMagicLvl(9) != 12
            || mytPersianFightLvl(9) != 10
            || mytPersianPsiClass(9) != 3
        )
            ++bad;
        // the hero common block - move 12, 100 hit points, Lord 12th, the Nil
        // magic and psionic cells pinning zero (folio 10)
    if (mytPersianMove(10) != 12
            || mytPersianHp(10) != 100
            || mytPersianMagicLvl(10) != 0
            || mytPersianFightLvl(10) != 12
            || mytPersianPsiClass(10) != 0
        )
            ++bad;
        // the Thrita line - the one clean hero stat line, 15/17/18/15/12/12
        // (folio 10)
    if (mytPersianHeroStr(3) != 15
            || mytPersianHeroInt(3) != 17
            || mytPersianHeroWis(3) != 18
            || mytPersianHeroCon(3) != 15
            || mytPersianHeroDex(3) != 12
            || mytPersianHeroCha(3) != 12
        )
            ++bad;
        // the Azathoth row - armor class minus 2, 300 hit points, Fighter
        // 20th, magic none, save 5 versus magic, the infinite move and
        // psionic-resistance cells riding the sentinel (folio 18)
    if (mytGOOAc(0) != -2
            || mytGOOHp(0) != 300
            || mytGOOFightLvl(0) != 20
            || mytGOOMagicLvl(0) != 0
            || mytAzathothSaveVsMagic() != 5
        )
            ++bad;
        // the Cthulhu row - armor class 2, move 12, 200 hit points, Fighter
        // 15th, Class 1, regenerating 10 per melee with the 100-mile insanity
        // radius (folio 18)
    if (mytGOOAc(1) != 2
            || mytGOOMove(1) != 12
            || mytGOOHp(1) != 200
            || mytGOOFightLvl(1) != 15
            || mytGOOPsiClass(1) != 1
            || mytCthulhuRegen() != 10
            || mytCthulhuInsanityRadiusMiles() != 100
        )
            ++bad;
        // the Yig row - the split armor class pinning as the head-3 chest-5
        // consts with the grid cell riding the sentinel, 125 hit points, the
        // 2-11 fang damage at minus 3 on the poison save (folio 20)
    if (mytYigHeadAc() != 3
            || mytYigBodyAc() != 5
            || mytGOOAc(7) != -1
            || mytGOOHp(7) != 125
            || mytYigFangDamageMin() != 2
            || mytYigFangDamageMax() != 11
            || mytYigPoisonSavePenalty() != 3
        )
            ++bad;
        // the calling risks - 25 percent destruction, 50 percent a servant,
        // 25 percent the god, the ravage running 1-6 turns (folio 18)
    if (mytCallDestroyedPercent() != 25
            || mytCallServantPercent() != 50
            || mytCallGodPercent() != 25
            || mytRavageMinTurns() != 1
            || mytRavageMaxTurns() != 6
        )
            ++bad;
        // the Cthuga block - fire spells three times a day, the eight
        // 12-hit-die fire elementals once per week, the 3-30 strike,
        // +3-or-better weapons only (folio 20)
    if (mytCthugaFireSpellsPerDay() != 3
            || mytCthugaFireElementals() != 8
            || mytCthugaElementalHD() != 12
            || mytCthugaDamageMin() != 3
            || mytCthugaDamageMax() != 30
            || mytCthugaWeaponPlusNeeded() != 3
            || mytCthugaPlusThreeWeaponsOnly() != 1
        )
            ++bad;
        // the Ithaqua block - the 16-die air elemental per day, two 2-16
        // buffet strikes, plus 2 per die of magical fire, wind walking at
        // will (folio 20)
    if (mytIthaquaAirElementalHD() != 16
            || mytIthaquaDamageMin() != 2
            || mytIthaquaDamageMax() != 16
            || mytIthaquaFireExtraPerDie() != 2
            || mytIthaquaWindWalkAtWill() != 1
        )
            ++bad;
        // the Wizard levels - the yazatas 14th, the demon block 14th, the
        // archdemon block 20th (folios 8-10)
    if (mytPersianMagicLvl(3) != 14
            || mytPersianMagicLvl(4) != 14
            || mytPersianMagicLvl(5) != 14
            || mytPersianMagicLvl(6) != 14
            || mytPersianMagicLvl(7) != 14
            || mytPersianMagicLvl(8) != 14
            || mytPersianMagicLvl(11) != 20
            || mytPersianMagicLvl(12) != 14
        )
            ++bad;
        // the hit-point ladder - the yazatas 225 through 175, the archdemons
        // 250, the demons 200 (folios 9-10)
    if (mytPersianHp(4) != 225
            || mytPersianHp(5) != 175
            || mytPersianHp(6) != 250
            || mytPersianHp(7) != 225
            || mytPersianHp(8) != 250
            || mytPersianHp(9) != 175
            || mytPersianHp(11) != 250
            || mytPersianHp(12) != 200
        )
            ++bad;
        // the five hero strength garbles - 185, 189, 1859, 18;; and 18,5, all
        // riding the sentinel as-scanned, never silent (folio 10)
    if (mytPersianHeroStr(0) != -1
            || mytPersianHeroStr(1) != -1
            || mytPersianHeroStr(2) != -1
            || mytPersianHeroStr(4) != -1
            || mytPersianHeroStr(5) != -1
        )
            ++bad;
        // the clean hero cells - Hoshang intelligence 17 and constitution 18,
        // Takhmoruw wisdom 12, Faridun charisma 15, Keresaspa dexterity 17
        // (folio 10)
    if (mytPersianHeroInt(1) != 17
            || mytPersianHeroWis(2) != 12
            || mytPersianHeroCon(1) != 18
            || mytPersianHeroDex(5) != 17
            || mytPersianHeroCha(4) != 15
        )
            ++bad;
        // the pinned god cells - Nyarlathotep and Yog Sothoth 15th-level
        // magic, the psionic classes two through six across the grid (folios
        // 18-20)
    if (mytGOOMagicLvl(3) != 15
            || mytGOOMagicLvl(8) != 15
            || mytGOOPsiClass(3) != 2
            || mytGOOPsiClass(4) != 2
            || mytGOOPsiClass(5) != 6
            || mytGOOPsiClass(6) != 6
            || mytGOOPsiClass(8) != 1
        )
            ++bad;
        // the god-grid sentinels - the Yig split armor class, the Azathoth
        // infinite move, the Shub-Niggurath see-below fighter level, the six
        // see-below magic cells and the two psionic-resistance cells (folios
        // 18-20)
    if (mytGOOAc(7) != -1
            || mytGOOMove(0) != -1
            || mytGOOFightLvl(4) != -1
            || mytGOOMagicLvl(1) != -1
            || mytGOOMagicLvl(2) != -1
            || mytGOOMagicLvl(4) != -1
            || mytGOOMagicLvl(5) != -1
            || mytGOOMagicLvl(6) != -1
            || mytGOOMagicLvl(7) != -1
            || mytGOOPsiClass(0) != -1
            || mytGOOPsiClass(2) != -1
        )
            ++bad;
        // the Byakhee and Deep One rows - 36 move and 100 hit points at Class
        // 5 versus armor class 3 and 10 hit points at 3rd level (folio 21)
    if (mytRaceAc(0) != 5
            || mytRaceMove(0) != 36
            || mytRaceHp(0) != 100
            || mytRaceFightLvl(0) != 10
            || mytRacePsiClass(0) != 5
            || mytRaceAc(1) != 3
            || mytRaceHp(1) != 10
            || mytRaceFightLvl(1) != 3
        )
            ++bad;
        // the remaining races - the Great Race 30, the Old Ones 50, the Mi-Go
        // 35 at move 15, the Shaggoths 70 (folio 21)
    if (mytRaceAc(2) != 5
            || mytRaceHp(2) != 30
            || mytRaceFightLvl(2) != 6
            || mytRacePsiClass(2) != 1
            || mytRaceHp(3) != 50
            || mytRaceAc(4) != 3
            || mytRaceMove(4) != 15
            || mytRaceHp(4) != 35
            || mytRaceHp(5) != 70
        )
            ++bad;
        // the race-grid sentinels - the Byakhee and Mi-Go see-below magic
        // cells and the Shaggoth psionic-resistance cell (folio 21)
    if (mytRaceMagicLvl(0) != -1
            || mytRaceMagicLvl(4) != -1
            || mytRacePsiClass(5) != -1
        )
            ++bad;
        printf("R920 issue-12 opener part two audit: bad %d\n", bad);
        if (bad) return 1;
    }
