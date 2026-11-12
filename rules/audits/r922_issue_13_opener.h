    // ---- R922 issue-13 opener audit ----
    // THE DRAGON ISSUE-13 OPENER ROUND, PART ONE - the all-usable
    // adjudication, every engine-relevant chain of the issue. The How Heavy
    // Is My Giant article by Shlump da Orc (folios 5-7): the 180-pound
    // 5-foot-8 base man of the formula, the 35-percent torso share, the
    // 47-pounds-per-cubic-foot flesh density, the formula scalars (6.28,
    // 3.12, .5588, .2647, 1728), the 26-row size grid from 5-foot-8 through
    // 30 feet with its pounds column (invisible to the OCR, visually
    // confirmed and anchored by the article 23,660 worked example), the tons
    // column pinned in quarter-ton units with the 5-foot-8 through 8-foot
    // cells blank on the sentinel, the chest and torso columns, the six-step
    // lift ladder, the over-under base-weight rule on the 160-pound reference
    // man, the 47,300 to 71,000 titan press, and the 64-row materials density
    // grid pinned in tenths - the Ice 57.2, Lignum Vitae 73-83 and Mahogany
    // 41 cells resolved at the full-res scan, provenance noted. The Demon
    // Generation article by Jon Pickens (folio 9): the six demon levels, the
    // 50-percent magic resistance plus 5 per level, the power-count grid
    // (visually confirmed against the djvu fragments) with the dash cells
    // pinned as zero, the 12-entry ability slots, the 2-and-3 caster
    // multipliers, the no-fire-and-ice rule, the weapon-vulnerability tiers,
    // the Prince rules (19th-level casters, the 50-percent artifact) and the
    // Level-VI worked constants (8 ten-sided hit dice, the 70-percent Level
    // 3-4 gate). The issue-13 report rides pre-flip; the Japanese Mythos box
    // closes at the part-two round.
    {
        using namespace rules;
        int bad = 0;
    if (dgmBaseManWeightLbs() != 180
            || dgmBaseManHeightInches() != 68
            || dgmBaseManChestInches() != 38
            || dgmBaseManTorsoInches() != 18
            || dgmTorsoSharePercent() != 35
            || dgmBodyLbsPerCubicFoot() != 47
            || dgmChestDivisorHundredths() != 628
            || dgmPiFactorHundredths() != 312
            || dgmChestFactorTenThousandths() != 5588
            || dgmTorsoFactorTenThousandths() != 2647
            || dgmCubicInchesPerCubicFoot() != 1728
            || dgmGiantRows() != 26
            || dgmLiftReferenceManLbs() != 160
            || dgmExampleWeightLbs() != 23660
            || dgmTitanPressMinLbs() != 47300
            || dgmTitanPressMaxLbs() != 71000
            || dgmBronzeLbsPerCubicFoot() != 550
            || dgmTalosHeightFeet() != 60
            || dgmMaterialRows() != 64
            || dgmDemonLevels() != 6
            || dgmDemonMrBasePercent() != 50
            || dgmDemonMrPerLevelPercent() != 5
            || dgmDemonAbilitySlots() != 12
            || dgmDemonCasterMultiplierLow() != 2
            || dgmDemonCasterMultiplierHigh() != 3
            || dgmPrinceCasterLevel() != 19
            || dgmPrinceArtifactChancePercent() != 50
            || dgmL6HitDice() != 8
            || dgmL6HitDieSides() != 10
            || dgmL6GatePercent() != 70
            || dgmL6GateLevelMin() != 3
            || dgmL6GateLevelMax() != 4
            || dgmExampleL6MrPercent() != 80
            || dgmPowerGridRows() != 6
            || !dgmCarryOwnWeightOnBack()
            || !dgmArmsThreeQuartersWeight()
            || !dgmTwoArmsHalfDeadWeight()
            || !dgmHalfWeightStrugglingAnimal()
            || !dgmQuarterWeightStrugglingTwoHanded()
            || !dgmQuarterWeightOneHanded()
            || !dgmOverUnderBaseWeightRule()
            || !dgmNoFireAndIcePowers()
            || !dgmLowLevelsNormalWeaponsVulnerable()
            || !dgmHighLevelsMagicWeaponsOnly()
            || !dgmPrincesNeverBelowLevelSix()
            || !dgmPrincesAlwaysNineteenth()
            || !dgmPrincesNeverMoreHighThanLesser()
            || !dgmMenAbilitiesNotGained()
            || !dgmHighDemonsHumanOrAnimalRoll()
        )
            ++bad;
        // the giant size grid - the pounds and torso columns are invisible to
        // the djvu OCR and resolved at the full-res scan (the R919
        // visual-check precedent), the pounds anchored by the article 23,660
        // worked example and the torso by the .2647 factor row by row; the
        // tons pin in quarter-ton units with the four blank short rows on the
        // sentinel, noted never silent (folio 5)
        int CGS[26][5] = {
            {68,160,-1,38,18},
            {72,185,-1,40,19},
            {84,300,-1,47,22},
            {96,450,-1,54,25},
            {108,630,1,60,29},
            {120,875,1,67,32},
            {132,1175,2,74,35},
            {144,1510,3,80,38},
            {156,1930,4,87,41},
            {168,2240,5,94,45},
            {180,2950,6,100,48},
            {192,3600,7,107,51},
            {204,4340,9,114,54},
            {216,5120,10,120,57},
            {228,6050,12,127,60},
            {240,7010,14,134,64},
            {252,8140,16,141,67},
            {264,9075,18,148,70},
            {276,10675,21,154,73},
            {288,12130,24,161,76},
            {300,13700,27,168,79},
            {312,15425,31,174,83},
            {324,17275,34,181,86},
            {336,19250,38,188,89},
            {348,21400,43,194,92},
            {360,23660,47,201,96},
            };
        int nGS[5] = {0,0,0,0,0};
        int eGS[5] = {0,0,4,0,0};
        for (int b = 0;
             b < dgmGiantRows();
             ++b) {
            int vals[5];
            vals[0] = dgmGiantHeightInches(b);
            vals[1] = dgmGiantWeightPounds(b);
            vals[2] = dgmGiantWeightTonsQuarter(b);
            vals[3] = dgmGiantChestInches(b);
            vals[4] = dgmGiantTorsoInches(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CGS[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nGS[c];
            }
        }
        for (int c = 0; c < 5; ++c)
            if (nGS[c] != eGS[c])
                ++bad;
        // the 64-row materials density grid for non-flesh giants - the print
        // is two columns with ranges and singles, pinned in tenths (a noted
        // conversion); the Ice 57.2, Lignum Vitae 73-83 and Mahogany 41 cells
        // resolve only at the full-res scan with provenance noted, the vision
        // Quartz and Rubber misreads caught against the geometry (folio 7)
        int CMD[64][2] = {
            {1250,1750},
            {600,610},
            {1680,1690},
            {1700,1900},
            {1060,1250},
            {870,1370},
            {530,540},
            {2550,2800},
            {620,620},
            {1700,1900},
            {1180,1750},
            {350,350},
            {5070,5070},
            {1120,1620},
            {870,1120},
            {620,1050},
            {140,160},
            {1880,2200},
            {1770,1770},
            {1590,1720},
            {1640,1640},
            {4600,4700},
            {1970,2680},
            {1500,1750},
            {1650,1720},
            {810,870},
            {3060,3300},
            {572,572},
            {1140,1200},
            {540,540},
            {3060,3240},
            {2310,2560},
            {1600,1770},
            {2180,2180},
            {1370,1370},
            {440,720},
            {540,570},
            {670,670},
            {1430,1560},
            {3090,3180},
            {1650,1650},
            {1360,1360},
            {740,740},
            {690,690},
            {1340,1470},
            {1620,1750},
            {990,990},
            {2190,2230},
            {1120,1120},
            {410,520},
            {400,530},
            {70,90},
            {190,250},
            {300,350},
            {690,830},
            {730,830},
            {410,410},
            {370,560},
            {220,310},
            {230,370},
            {240,370},
            {410,550},
            {610,610},
            {240,370},
            };
        int nMD[2] = {0,0};
        int eMD[2] = {0,0};
        for (int b = 0;
             b < dgmMaterialRows();
             ++b) {
            int vals[2];
            vals[0] = dgmMaterialLbsMinTenths(b);
            vals[1] = dgmMaterialLbsMaxTenths(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CMD[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nMD[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nMD[c] != eMD[c])
                ++bad;
        // the demon power-count grid - the OCR garbles it whole (L223 An SG);
        // the full-res scan resolved it and the djvu Level-IV fragment (3, 3,
        // 2, 1) cross-validates; the not-applicable dash cells pin as zero,
        // noted never silent (folio 9)
        int CDP[6][6] = {
            {2,0,0,0,0,0},
            {3,2,0,0,0,0},
            {3,2,2,0,0,0},
            {3,3,2,1,0,0},
            {3,3,2,2,1,0},
            {3,3,3,2,2,1},
            };
        int nDP[6] = {0,0,0,0,0,0};
        int eDP[6] = {0,0,0,0,0,0};
        for (int b = 0;
             b < dgmPowerGridRows();
             ++b) {
            int vals[6];
            vals[0] = dgmPowersOfLevel1(b);
            vals[1] = dgmPowersOfLevel2(b);
            vals[2] = dgmPowersOfLevel3(b);
            vals[3] = dgmPowersOfLevel4(b);
            vals[4] = dgmPowersOfLevel5(b);
            vals[5] = dgmPowersOfLevel6(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CDP[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nDP[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nDP[c] != eDP[c])
                ++bad;
        // the base man block - 180 pounds, 5 foot 8, a 38-inch chest, an
        // 18-inch torso, the lift ladder referenced to the 160-pound man
        // (folio 5)
    if (dgmBaseManWeightLbs() != 180
            || dgmBaseManHeightInches() != 68
            || dgmBaseManChestInches() != 38
            || dgmBaseManTorsoInches() != 18
            || dgmLiftReferenceManLbs() != 160
        )
            ++bad;
        // the formula scalars - 6.28, 3.12, .5588, .2647, 1728, 47 pounds per
        // cubic foot and the 35-percent torso share, pinned scaled as
        // printed-decimal conversions (folios 5-6)
    if (dgmChestDivisorHundredths() != 628
            || dgmPiFactorHundredths() != 312
            || dgmChestFactorTenThousandths() != 5588
            || dgmTorsoFactorTenThousandths() != 2647
            || dgmCubicInchesPerCubicFoot() != 1728
            || dgmBodyLbsPerCubicFoot() != 47
            || dgmTorsoSharePercent() != 35
        )
            ++bad;
        // the 30-foot row - 360 inches, 23,660 pounds (the article worked
        // example), 11 3/4 tons as 47 quarter-tons, a 201-inch chest and a
        // 96-inch torso (folio 5)
    if (dgmGiantHeightInches(25) != 360
            || dgmGiantWeightPounds(25) != 23660
            || dgmGiantWeightTonsQuarter(25) != 47
            || dgmGiantChestInches(25) != 201
            || dgmGiantTorsoInches(25) != 96
            || dgmExampleWeightLbs() != 23660
        )
            ++bad;
        // the 5-foot-8 row - 160 pounds on the blank tons sentinel, the
        // base-man measurements (folio 5)
    if (dgmGiantHeightInches(0) != 68
            || dgmGiantWeightPounds(0) != 160
            || dgmGiantWeightTonsQuarter(0) != -1
            || dgmGiantChestInches(0) != 38
            || dgmGiantTorsoInches(0) != 18
        )
            ++bad;
        // the titan press and the non-flesh example - 47,300-71,000 pressed,
        // bronze at 550 pounds per cubic foot, the 60-foot Talos (folio 6)
    if (dgmTitanPressMinLbs() != 47300
            || dgmTitanPressMaxLbs() != 71000
            || dgmBronzeLbsPerCubicFoot() != 550
            || dgmTalosHeightFeet() != 60
        )
            ++bad;
        // the six-step lift ladder and the over-under base-weight rule
        // (folios 5-6)
    if (dgmCarryOwnWeightOnBack() != 1
            || dgmArmsThreeQuartersWeight() != 1
            || dgmTwoArmsHalfDeadWeight() != 1
            || dgmHalfWeightStrugglingAnimal() != 1
            || dgmQuarterWeightStrugglingTwoHanded() != 1
            || dgmQuarterWeightOneHanded() != 1
            || dgmOverUnderBaseWeightRule() != 1
        )
            ++bad;
        // the demon magic resistance - 50 percent at Level I plus 5 per
        // level, the worked example raised to 80 (folio 9)
    if (dgmDemonLevels() != 6
            || dgmDemonMrBasePercent() != 50
            || dgmDemonMrPerLevelPercent() != 5
            || dgmExampleL6MrPercent() != 80
        )
            ++bad;
        // the Level-VI worked constants - eight ten-sided hit dice, the
        // 70-percent Level 3-4 gate (folio 9)
    if (dgmL6HitDice() != 8
            || dgmL6HitDieSides() != 10
            || dgmL6GatePercent() != 70
            || dgmL6GateLevelMin() != 3
            || dgmL6GateLevelMax() != 4
        )
            ++bad;
        // the Prince tier - 19th-level caster capability, the 50-percent
        // artifact, never below a Level-VI demon (folio 9)
    if (dgmPrinceCasterLevel() != 19
            || dgmPrinceArtifactChancePercent() != 50
            || dgmPrincesNeverBelowLevelSix() != 1
            || dgmPrincesAlwaysNineteenth() != 1
        )
            ++bad;
        // the caster multipliers and the twelve-entry ability slots (folio 9)
    if (dgmDemonCasterMultiplierLow() != 2
            || dgmDemonCasterMultiplierHigh() != 3
            || dgmDemonAbilitySlots() != 12
        )
            ++bad;
        // the demon restrictions - no fire-and-ice, the weapon tiers, no men
        // abilities gained, the human or animal roll (folio 9)
    if (dgmNoFireAndIcePowers() != 1
            || dgmLowLevelsNormalWeaponsVulnerable() != 1
            || dgmHighLevelsMagicWeaponsOnly() != 1
            || dgmMenAbilitiesNotGained() != 1
            || dgmHighDemonsHumanOrAnimalRoll() != 1
        )
            ++bad;
        // the pounds ladder - 630 at 9 feet, 2,950 at 15, 8,140 at 21 and
        // 15,425 at 26, the OCR-invisible column (folio 5)
    if (dgmGiantWeightPounds(4) != 630
            || dgmGiantWeightTonsQuarter(4) != 1
            || dgmGiantChestInches(4) != 60
            || dgmGiantTorsoInches(4) != 29
            || dgmGiantWeightPounds(10) != 2950
            || dgmGiantWeightPounds(16) != 8140
            || dgmGiantWeightPounds(21) != 15425
        )
            ++bad;
        // the quarter-ton tonnage - 1 ton at 13 feet, 3 1/2 at 20, 6 at 24,
        // 10 3/4 at 29, the four short rows blank on the sentinel (folio 5)
    if (dgmGiantWeightTonsQuarter(8) != 4
            || dgmGiantWeightTonsQuarter(15) != 14
            || dgmGiantWeightTonsQuarter(19) != 24
            || dgmGiantWeightTonsQuarter(24) != 43
            || dgmGiantWeightTonsQuarter(1) != -1
            || dgmGiantWeightTonsQuarter(2) != -1
            || dgmGiantWeightTonsQuarter(3) != -1
        )
            ++bad;
        // the chest and torso ladders - 134/64 at 20 feet, 161 at 24, 181 at
        // 27, the torso 83 at 26 feet and 92 at 29 (folio 5)
    if (dgmGiantChestInches(15) != 134
            || dgmGiantChestInches(19) != 161
            || dgmGiantChestInches(22) != 181
            || dgmGiantTorsoInches(15) != 64
            || dgmGiantTorsoInches(21) != 83
            || dgmGiantTorsoInches(24) != 92
        )
            ++bad;
        // the power-count low columns - a Level-I demon gets 2 level-1
        // abilities, the grid running 2, 3, 3, 3, 3, 3 down and the level-2
        // and level-3 stairs (folio 9)
    if (dgmPowersOfLevel1(0) != 2
            || dgmPowersOfLevel1(5) != 3
            || dgmPowersOfLevel2(1) != 2
            || dgmPowersOfLevel2(3) != 3
            || dgmPowersOfLevel3(2) != 2
            || dgmPowersOfLevel3(5) != 3
        )
            ++bad;
        // the power-count high columns - the level-4, 5 and 6 stairs to the
        // Level-VI demon 3, 3, 3, 2, 2, 1 row, the dashes as zero (folio 9)
    if (dgmPowersOfLevel4(3) != 1
            || dgmPowersOfLevel4(5) != 2
            || dgmPowersOfLevel5(4) != 1
            || dgmPowersOfLevel5(5) != 2
            || dgmPowersOfLevel6(5) != 1
            || dgmPowersOfLevel6(0) != 0
        )
            ++bad;
        // the dense materials - diamond 1880-2200 and galena 4600-4700 pounds
        // per cubic foot, in tenths (folio 7)
    if (dgmMaterialLbsMinTenths(17) != 1880
            || dgmMaterialLbsMaxTenths(17) != 2200
            || dgmMaterialLbsMinTenths(21) != 4600
            || dgmMaterialLbsMaxTenths(21) != 4700
        )
            ++bad;
        // the vision-resolved cells - ice 57.2, lignum vitae 73-83 and
        // mahogany 41, pinned in tenths with the visual provenance noted
        // (folio 7)
    if (dgmMaterialLbsMinTenths(27) != 572
            || dgmMaterialLbsMaxTenths(27) != 572
            || dgmMaterialLbsMinTenths(55) != 730
            || dgmMaterialLbsMaxTenths(55) != 830
            || dgmMaterialLbsMinTenths(56) != 410
            || dgmMaterialLbsMaxTenths(56) != 410
        )
            ++bad;
        // the singles - hard rubber 74, soft rubber 69, charcoal 35 and flint
        // 164, the vision misreads corrected against the geometry (folio 7)
    if (dgmMaterialLbsMinTenths(42) != 740
            || dgmMaterialLbsMaxTenths(42) != 740
            || dgmMaterialLbsMinTenths(43) != 690
            || dgmMaterialLbsMaxTenths(43) != 690
            || dgmMaterialLbsMinTenths(11) != 350
            || dgmMaterialLbsMaxTenths(11) != 350
            || dgmMaterialLbsMinTenths(20) != 1640
        )
            ++bad;
        // the seasoned woods - oak 370-560, balsa 70-90, African teak 61
        // (folio 7)
    if (dgmMaterialLbsMinTenths(57) != 370
            || dgmMaterialLbsMaxTenths(57) != 560
            || dgmMaterialLbsMinTenths(51) != 70
            || dgmMaterialLbsMaxTenths(51) != 90
            || dgmMaterialLbsMinTenths(62) != 610
            || dgmMaterialLbsMaxTenths(62) != 610
        )
            ++bad;
        printf("R922 issue-13 opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
