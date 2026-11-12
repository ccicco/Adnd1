    // ---- R923 issue-13 opener part two audit ----
    // THE DRAGON ISSUE-13 OPENER ROUND, PART TWO - The Japanese Mythos by
    // Jerome Arkenberg (folios 11-15), the direct sibling of the R920 Persian
    // Mythos chain, a GD&H-compatible D&D-statted mythos. THE GODS: the nine
    // Shinto gods (Amaterasu, Tsukiyomi, Susano, Izanagi and Izanami, Ryujin,
    // Hachiman, Inari, Kwannon, Suka-Na-Biko or Momotaro), the Seven Gods of
    // Luck on their common 150-hit-point 7th-level block with Bishamon the
    // Lord 10th exception, and the eleven Buddhist deities on the Patriarch
    // ladder - sixteen see-below magic cells ride the -1 sentinel with the
    // census, the Aizen-Myoo armor class prints the bar garble riding the
    // sentinel, and the Ryujin armor class minus 1 pins as a const with the
    // grid cell riding the sentinel, the genuine clean value colliding with
    // the sentinel mark (the Yig-split precedent of R920), and the
    // Shaka-Nyorai fighter cell prints the Sth garble (the 5 of 5th lost to
    // the print), pinned 5 noted as scanned, never silent; the eleven
    // prose-only Other Shinto Gods ride the transcript. THE CREATURES: the
    // Kappa with the head-water, promise and single-combat rules, the Tengu
    // colony with its king, the Oni, and the Yuki-Onna with the see-below
    // magic cell on the sentinel. THE HEROES: fourteen heroes on the common
    // warrior block and the four holy men - the seven strength cells print
    // fraction garbles (1899, 1850, 1865, 1860, 1875, 1880, 1845, all
    // 18-slash) riding the sentinel with the census, the Kiyomori 18 and the
    // Light-of-Fire and Shade-of-Fire 17 pinning clean, the Light-of-Fire
    // armor class printing the bar garble on the sentinel, the Kobo Daishi
    // fighter cell printing the Sth garble pinned 5 noted, and the Nil magic
    // and psionic cells pinning zero; the Hachiman +3 sword at 24-48 and the
    // never-missing 7-12 arrows, the Benkei hundred-men strength, the
    // Yoshi-Iye +2 and Tametomo +4 arrows. THE TREASURES: the six pieces with
    // the Imperial Sword a Dancing Sword lost at Dannoura and the Sakaki
    // branches required. THE FLIP: the part-one box in
    // tools/dragon_gap_report_013.md went [x] - 1 closed, 1 open, the closing
    // round to follow.
    {
        using namespace rules;
        int bad = 0;
    if (kmyGodRows() != 27
            || kmyShintoGods() != 9
            || kmySevenGodsOfLuck() != 7
            || kmyBuddhistGods() != 11
            || kmyOtherShintoGods() != 11
            || kmyCreatureRows() != 4
            || kmyHeroRows() != 14
            || kmySusanoJewels() != 2
            || kmyHachimanSwordPlus() != 3
            || kmyHachimanSwordDamageMin() != 24
            || kmyHachimanSwordDamageMax() != 48
            || kmyHachimanArrowDamageMin() != 7
            || kmyHachimanArrowDamageMax() != 12
            || kmyOniEyes() != 3
            || kmyBenkeiHeightFeet() != 10
            || kmyBenkeiStrengthOfMen() != 100
            || kmyYoshiiyeArrowPlus() != 2
            || kmyTametomoArrowPlus() != 4
            || kmyRyujinAc() != -1
            || kmyTreasures() != 6
            || !kmyShintoBuddhistMixture()
            || !kmyKamiInAllThings()
            || !kmySusanoJewelsOfHailAndLightning()
            || !kmyHachimanArrowsNeverMiss()
            || !kmyInariFoxMessenger()
            || !kmyKappaPowersNeedHeadWater()
            || !kmyKappaAlwaysKeepsPromise()
            || !kmyKappaChallengeMustBeAccepted()
            || !kmyOniFlyButSeldomDo()
            || !kmyTenguColonyWithKing()
            || !kmyYukiOnnaLullsToSleepDeath()
            || !kmyBenkeiStrengthOfHundredMen()
            || !kmyYoshitsuneOnlyToDefeatBenkei()
            || !kmyKiyomoriTairaRivalOfMinamoto()
            || !kmyTideJewelsPriceless()
            || !kmyImperialSwordIsDancing()
            || !kmyImperialSwordLostAtDannoura()
            || !kmySakakiBranchesRequired()
        )
            ++bad;
        // the Japanese Mythos god grid - the sixteen see-below magic cells of
        // the Shinto and Luck gods ride the -1 sentinel with the census and
        // the Aizen-Myoo armor class prints the bar garble riding the
        // sentinel; the Ryujin armor class minus 1 pins as a const with the
        // grid cell riding the sentinel, the genuine clean value colliding
        // with the sentinel mark, the Yig-split precedent of R920; the
        // Shaka-Nyorai fighter cell prints the Sth garble (the 5 of 5th lost
        // to the print) and pins 5 noted as scanned, never silent (folios
        // 11-12)
        int CJG[27][6] = {
            {-2,18,300,-1,15,6},
            {-2,18,275,-1,15,6},
            {-2,18,290,-1,15,6},
            {2,12,200,-1,10,6},
            {-1,15,250,-1,15,6},
            {2,12,200,-1,15,6},
            {2,15,175,-1,10,6},
            {0,16,175,-1,7,6},
            {3,10,175,-1,12,6},
            {2,15,150,-1,7,6},
            {2,15,150,-1,7,6},
            {2,15,150,-1,7,6},
            {2,15,150,-1,10,6},
            {2,15,150,-1,7,6},
            {2,15,150,-1,7,6},
            {2,15,150,-1,7,6},
            {2,14,275,20,5,1},
            {2,14,275,15,5,2},
            {2,14,275,17,5,1},
            {0,14,300,23,6,6},
            {4,14,275,10,5,4},
            {4,14,225,10,4,4},
            {4,12,225,9,4,4},
            {4,12,225,9,4,4},
            {4,12,225,9,4,4},
            {2,14,225,13,12,5},
            {-1,14,200,14,7,2},
            };
        int nJG[6] = {0,0,0,0,0,0};
        int eJG[6] = {2,0,0,16,0,0};
        for (int b = 0;
             b < kmyGodRows();
             ++b) {
            int vals[6];
            vals[0] = kmyGodAc(b);
            vals[1] = kmyGodMove(b);
            vals[2] = kmyGodHp(b);
            vals[3] = kmyGodMagicLvl(b);
            vals[4] = kmyGodFightLvl(b);
            vals[5] = kmyGodPsiClass(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CJG[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nJG[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nJG[c] != eJG[c])
                ++bad;
        // the creature grid - the Kappa, Tengu and Oni print Wizard magic
        // levels pinning clean and the Yuki-Onna magic cell prints See Below
        // riding the -1 sentinel with the census, noted never silent (folio
        // 13)
        int CJC[4][6] = {
            {3,10,100,14,10,6},
            {3,14,100,16,10,6},
            {3,10,100,16,10,6},
            {2,15,175,-1,7,6},
            };
        int nJC[6] = {0,0,0,0,0,0};
        int eJC[6] = {0,0,0,1,0,0};
        for (int b = 0;
             b < kmyCreatureRows();
             ++b) {
            int vals[6];
            vals[0] = kmyCreatureAc(b);
            vals[1] = kmyCreatureMove(b);
            vals[2] = kmyCreatureHp(b);
            vals[3] = kmyCreatureMagicLvl(b);
            vals[4] = kmyCreatureFightLvl(b);
            vals[5] = kmyCreaturePsiClass(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CJC[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nJC[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nJC[c] != eJC[c])
                ++bad;
        // the hero grid - the Nil magic and psionic cells pin zero and the
        // Light-of-Fire and Shade-of-Fire armor class prints the bar garble
        // riding the -1 sentinel with the census; the Kobo Daishi fighter
        // cell prints the Sth garble (the 5 of 5th lost to the print) and
        // pins 5 noted as scanned, never silent (folios 13-15)
        int CJH[14][6] = {
            {-2,5,50,0,7,0},
            {2,12,80,0,10,0},
            {2,12,80,0,10,0},
            {2,12,80,0,10,0},
            {2,14,100,0,12,0},
            {2,12,90,0,11,0},
            {-1,12,80,0,10,0},
            {2,12,80,0,10,0},
            {2,12,80,0,10,0},
            {2,12,80,0,10,0},
            {9,12,50,10,4,0},
            {9,12,60,12,4,0},
            {9,12,70,14,5,0},
            {9,12,70,14,5,0},
            };
        int nJH[6] = {0,0,0,0,0,0};
        int eJH[6] = {1,0,0,0,0,0};
        for (int b = 0;
             b < kmyHeroRows();
             ++b) {
            int vals[6];
            vals[0] = kmyHeroAc(b);
            vals[1] = kmyHeroMove(b);
            vals[2] = kmyHeroHp(b);
            vals[3] = kmyHeroMagicLvl(b);
            vals[4] = kmyHeroFightLvl(b);
            vals[5] = kmyHeroPsiClass(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CJH[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nJH[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nJH[c] != eJH[c])
                ++bad;
        // the hero ability lines - the seven strength cells print fraction
        // garbles (1899, 1850, 1865, 1860, 1875, 1880, 1845, all 18-slash)
        // and ride the -1 sentinel with the census, the Kiyomori strength 18
        // and the Light-of-Fire and Shade-of-Fire strength 17 pinning clean,
        // noted as scanned never silent (folios 13-15)
        int CJA[14][6] = {
            {12,14,13,18,18,14},
            {-1,12,17,15,16,17},
            {-1,17,13,16,17,15},
            {-1,14,12,15,17,15},
            {-1,13,10,17,17,16},
            {-1,15,12,17,18,16},
            {17,14,14,15,17,17},
            {-1,12,12,16,17,15},
            {18,14,10,15,17,17},
            {-1,15,15,16,18,15},
            {8,18,18,14,10,13},
            {7,18,12,14,17,12},
            {10,17,18,15,16,16},
            {7,15,18,15,16,12},
            };
        int nJA[6] = {0,0,0,0,0,0};
        int eJA[6] = {7,0,0,0,0,0};
        for (int b = 0;
             b < kmyHeroRows();
             ++b) {
            int vals[6];
            vals[0] = kmyHeroStr(b);
            vals[1] = kmyHeroInt(b);
            vals[2] = kmyHeroWis(b);
            vals[3] = kmyHeroCon(b);
            vals[4] = kmyHeroDex(b);
            vals[5] = kmyHeroCha(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CJA[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nJA[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nJA[c] != eJA[c])
                ++bad;
        // the Amaterasu row - armor class minus 2, move 18, 300 hit points,
        // Lord 15th, Class 6, the see-below magic cell riding the sentinel
        // (folio 11)
    if (kmyGodAc(0) != -2
            || kmyGodMove(0) != 18
            || kmyGodHp(0) != 300
            || kmyGodMagicLvl(0) != -1
            || kmyGodFightLvl(0) != 15
            || kmyGodPsiClass(0) != 6
        )
            ++bad;
        // the Susano row - armor class minus 2, 290 hit points, the two
        // hail-and-lightning jewels (folio 11)
    if (kmyGodAc(2) != -2
            || kmyGodHp(2) != 290
            || kmySusanoJewels() != 2
            || kmySusanoJewelsOfHailAndLightning() != 1
        )
            ++bad;
        // the Hachiman row - armor class 2, 200 hit points, Lord 15th, the +3
        // sword at 24-48, the never-missing arrows at 7-12 (folio 11)
    if (kmyGodAc(5) != 2
            || kmyGodHp(5) != 200
            || kmyGodFightLvl(5) != 15
            || kmyHachimanSwordPlus() != 3
            || kmyHachimanSwordDamageMin() != 24
            || kmyHachimanSwordDamageMax() != 48
            || kmyHachimanArrowDamageMin() != 7
            || kmyHachimanArrowDamageMax() != 12
            || kmyHachimanArrowsNeverMiss() != 1
        )
            ++bad;
        // the Seven Gods of Luck - 150 hit points across the common 7th-level
        // block, Bishamon the Lord 10th exception, Benten 7th (folios 11-12)
    if (kmySevenGodsOfLuck() != 7
            || kmyGodHp(9) != 150
            || kmyGodHp(14) != 150
            || kmyGodHp(15) != 150
            || kmyGodFightLvl(12) != 10
            || kmyGodFightLvl(15) != 7
        )
            ++bad;
        // the Ryujin row - 250 hit points, Lord 15th, the armor class minus 1
        // pinning as the const with the grid cell riding the sentinel, the
        // collision noted (folio 11)
    if (kmyGodAc(4) != -1
            || kmyGodHp(4) != 250
            || kmyGodFightLvl(4) != 15
            || kmyRyujinAc() != -1
        )
            ++bad;
        // the Izanagi and Izanami row - armor class 2, 200 hit points, Lord
        // 10th, the mixture and the kami-in-all-things doctrine (folio 11)
    if (kmyGodAc(3) != 2
            || kmyGodHp(3) != 200
            || kmyGodFightLvl(3) != 10
            || kmyShintoBuddhistMixture() != 1
            || kmyKamiInAllThings() != 1
        )
            ++bad;
        // the Shaka-Nyorai row - Patriarch 20th, Class 1, the fighter cell
        // printing the Sth garble (the 5 of 5th lost to the print), pinned 5
        // noted as scanned (folio 12)
    if (kmyGodAc(16) != 2
            || kmyGodHp(16) != 275
            || kmyGodMagicLvl(16) != 20
            || kmyGodFightLvl(16) != 5
            || kmyGodPsiClass(16) != 1
        )
            ++bad;
        // the Aizen-Myoo row - the armor-class cell printing the bar garble
        // riding the sentinel, 200 hit points, Patriarch 14th, 7th, Class 2
        // (folio 12)
    if (kmyGodAc(26) != -1
            || kmyGodHp(26) != 200
            || kmyGodMagicLvl(26) != 14
            || kmyGodFightLvl(26) != 7
            || kmyGodPsiClass(26) != 2
        )
            ++bad;
        // the Dainichi-Nyorai row - armor class 0, 300 hit points, Patriarch
        // 23rd, 6th level (folio 12)
    if (kmyGodAc(19) != 0
            || kmyGodHp(19) != 300
            || kmyGodMagicLvl(19) != 23
            || kmyGodFightLvl(19) != 6
        )
            ++bad;
        // the Kappa row - armor class 3, move 10, 100 hit points, Wizard
        // 14th, Lord 10th, the head-water, promise and single-combat rules
        // (folio 13)
    if (kmyCreatureAc(0) != 3
            || kmyCreatureMove(0) != 10
            || kmyCreatureHp(0) != 100
            || kmyCreatureMagicLvl(0) != 14
            || kmyCreatureFightLvl(0) != 10
            || kmyKappaPowersNeedHeadWater() != 1
            || kmyKappaAlwaysKeepsPromise() != 1
            || kmyKappaChallengeMustBeAccepted() != 1
        )
            ++bad;
        // the Yuki-Onna row - armor class 2, 175 hit points, 7th, the
        // see-below magic cell riding the sentinel, the snowstorm lull (folio
        // 13)
    if (kmyCreatureAc(3) != 2
            || kmyCreatureHp(3) != 175
            || kmyCreatureMagicLvl(3) != -1
            || kmyCreatureFightLvl(3) != 7
            || kmyYukiOnnaLullsToSleepDeath() != 1
        )
            ++bad;
        // the Issun Boshi row - armor class minus 2, move 5, 50 hit points,
        // 7th with Nil magic and psionics as zero, the 12/14/13/18/18/14 stat
        // line (folios 13-14)
    if (kmyHeroAc(0) != -2
            || kmyHeroMove(0) != 5
            || kmyHeroHp(0) != 50
            || kmyHeroMagicLvl(0) != 0
            || kmyHeroFightLvl(0) != 7
            || kmyHeroPsiClass(0) != 0
            || kmyHeroStr(0) != 12
            || kmyHeroCon(0) != 18
            || kmyHeroDex(0) != 18
        )
            ++bad;
        // the Benkei row - 100 hit points, 12th level, the 10-foot height and
        // the hundred-men strength (folio 14)
    if (kmyHeroHp(4) != 100
            || kmyHeroFightLvl(4) != 12
            || kmyBenkeiHeightFeet() != 10
            || kmyBenkeiStrengthOfMen() != 100
            || kmyBenkeiStrengthOfHundredMen() != 1
        )
            ++bad;
        // the Light-of-Fire and Shade-of-Fire row - the armor-class cell
        // printing the bar garble riding the sentinel, the 17/14/14/15/17/17
        // stat line pinning clean (folio 14)
    if (kmyHeroAc(6) != -1
            || kmyHeroStr(6) != 17
            || kmyHeroInt(6) != 14
            || kmyHeroCha(6) != 17
        )
            ++bad;
        // the Kobo Daishi row - armor class 9, 70 hit points, Patriarch 14th,
        // the fighter cell printing the Sth garble (the 5 of 5th lost to the
        // print), pinned 5 noted as scanned (folio 15)
    if (kmyHeroAc(12) != 9
            || kmyHeroHp(12) != 70
            || kmyHeroMagicLvl(12) != 14
            || kmyHeroFightLvl(12) != 5
            || kmyHeroInt(12) != 17
        )
            ++bad;
        // the archer heroes - the Yoshi-Iye arrows +2, the Tametomo arrows +4
        // (folio 15)
    if (kmyYoshiiyeArrowPlus() != 2
            || kmyTametomoArrowPlus() != 4
            || kmyHeroFightLvl(9) != 10
            || kmyHeroDex(9) != 18
        )
            ++bad;
        // the treasures - the six pieces, the Imperial Sword a Dancing Sword
        // lost at Dannoura, the Tide Jewels priceless, the Sakaki branches
        // required (folio 15)
    if (kmyTreasures() != 6
            || kmyImperialSwordIsDancing() != 1
            || kmyImperialSwordLostAtDannoura() != 1
            || kmyTideJewelsPriceless() != 1
            || kmySakakiBranchesRequired() != 1
        )
            ++bad;
        // the sixteen see-below magic cells - the nine Shinto gods and the
        // Seven Gods of Luck all ride the sentinel as-scanned, never silent
        // (folios 11-12)
    if (kmyGodMagicLvl(0) != -1
            || kmyGodMagicLvl(4) != -1
            || kmyGodMagicLvl(8) != -1
            || kmyGodMagicLvl(9) != -1
            || kmyGodMagicLvl(15) != -1
        )
            ++bad;
        // the Patriarch ladder - Yakushi 15th, Amida 17th, Miroku and Kannon
        // 10th, Monju, Fugen and Jizo 9th, Fudo 13th (folio 12)
    if (kmyGodMagicLvl(17) != 15
            || kmyGodMagicLvl(18) != 17
            || kmyGodMagicLvl(20) != 10
            || kmyGodMagicLvl(21) != 10
            || kmyGodMagicLvl(22) != 9
            || kmyGodMagicLvl(23) != 9
            || kmyGodMagicLvl(24) != 9
            || kmyGodMagicLvl(25) != 13
        )
            ++bad;
        // the Kwannon row - armor class 0, move 16, 175 hit points, 7th, the
        // Inari fox messenger (folio 11)
    if (kmyGodAc(7) != 0
            || kmyGodMove(7) != 16
            || kmyGodHp(7) != 175
            || kmyGodFightLvl(7) != 7
            || kmyInariFoxMessenger() != 1
        )
            ++bad;
        // the seven hero strength garbles - 1899, 1850, 1865, 1860, 1875,
        // 1880 and 1845, all 18-slash fraction garbles riding the sentinel
        // as-scanned, never silent (folios 13-15)
    if (kmyHeroStr(1) != -1
            || kmyHeroStr(2) != -1
            || kmyHeroStr(3) != -1
            || kmyHeroStr(4) != -1
            || kmyHeroStr(5) != -1
            || kmyHeroStr(7) != -1
            || kmyHeroStr(9) != -1
        )
            ++bad;
        // the clean hero strength cells - Light-of-Fire and Shade-of-Fire 17,
        // Kiyomori 18, Shotoku Daishi 8, Nichiren 7 (folios 14-15)
    if (kmyHeroStr(6) != 17
            || kmyHeroStr(8) != 18
            || kmyHeroStr(10) != 8
            || kmyHeroStr(13) != 7
        )
            ++bad;
        // the hero hit-point ladder - the 80s across the warrior block with
        // Yoshitsune 90 and Benkei 100, the holy men 50 through 70 (folios
        // 13-15)
    if (kmyHeroHp(1) != 80
            || kmyHeroHp(5) != 90
            || kmyHeroHp(10) != 50
            || kmyHeroHp(11) != 60
            || kmyHeroHp(13) != 70
            || kmyHeroMove(0) != 5
            || kmyHeroMove(4) != 14
        )
            ++bad;
        // the holy men - armor class 9, Shotoku Daishi Patriarch 10th, En No
        // Shokaku Wizard 12th, Nichiren Patriarch 14th, the Nil psionics
        // pinning zero (folios 14-15)
    if (kmyHeroAc(10) != 9
            || kmyHeroAc(11) != 9
            || kmyHeroAc(13) != 9
            || kmyHeroMagicLvl(10) != 10
            || kmyHeroMagicLvl(11) != 12
            || kmyHeroMagicLvl(13) != 14
            || kmyHeroPsiClass(13) != 0
        )
            ++bad;
        // the Tengu and Oni rows - Wizard 16th both, the Tengu move 14 and
        // the Oni 10, the three eyes and the fly-but-seldom rule, the Tengu
        // colony king (folio 13)
    if (kmyCreatureAc(1) != 3
            || kmyCreatureMagicLvl(1) != 16
            || kmyCreatureMagicLvl(2) != 16
            || kmyCreatureMove(1) != 14
            || kmyCreatureMove(2) != 10
            || kmyOniEyes() != 3
            || kmyOniFlyButSeldomDo() != 1
            || kmyTenguColonyWithKing() != 1
        )
            ++bad;
        printf("R923 issue-13 opener part two audit: bad %d\n", bad);
        if (bad) return 1;
    }
