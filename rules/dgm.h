// =========================================================================================
// Adnd1 - rules/dgm.h
// The Dragon issue-13 opener part one - the Shlump da Orc giant physics
// article (folios 5-7) and the Jon Pickens demon generation article (folio
// 9): the all-usable adjudication, the Japanese Mythos to follow
// census 844 -> 845.
//
// Pinned from The Dragon Vol. II No. 7 (April 1978), the archive.org scan
// voice (single-voice: no chat-side upload cross-check exists for issue 13;
// the source lives in the archive.org item accessory-dragon-magazine-012,
// file Accessory - Dragon Magazine #013_djvu.xml). PRINT FOLIO = PDF PAGE,
// verified at the TOC alignments (5, 8, 9, 11, 16-17, 19, 21, 22, 28-30). The
// transcripts ride extract/dragon/013/p001 through p032; the article CHAIN is
// the ink unit, not the folio.
//
// Print quirks pinned AS SCANNED, noted never silent: the giant grid pounds
// column is invisible to the djvu OCR - the R919 visual-check precedent (the
// full-res scan plus the geometry plus a text anchor) resolved it, the 23,660
// pounds of the 30-foot row matching the article own worked example; the tons
// column pins in quarter-ton units (a noted conversion) with the 5-foot-8
// through 8-foot cells blank on the -1 sentinel; the torso column rides the
// same visual read, 17-of-17 rows formula-consistent with the .2647 factor;
// the materials grid pins in tenths (a noted conversion), the Ice 57.2,
// Lignum Vitae 73-83 and Mahogany 41 cells vision-resolved with provenance
// noted, the vision Quartz and Rubber misreads caught and corrected against
// the geometry; the demon power-count grid garbles in the OCR and resolved at
// the full-res scan, cross-validated against the djvu Level-IV fragment, the
// dash cells pinning as zero; the chest-in-feet sub-column rides the
// transcript, a unit restatement of the chest inches.
//
namespace rules {

// ---- the Shlump da Orc giant physics article (folios 5-7) ----

// the formula base man - 180 pounds (folio 5)
inline int dgmBaseManWeightLbs()
    { return 180; }

// the formula base man - 5 foot 8 tall, pinned in inches (folio 5)
inline int dgmBaseManHeightInches()
    { return 68; }

// the formula base man - 38-inch chest (folio 5)
inline int dgmBaseManChestInches()
    { return 38; }

// the formula base man - 18-inch torso (folio 5)
inline int dgmBaseManTorsoInches()
    { return 18; }

// the torso amounts to 35 percent of the whole body (folio 5)
inline int dgmTorsoSharePercent()
    { return 35; }

// a cubic foot of human body weighs 47 pounds (folio 5)
inline int dgmBodyLbsPerCubicFoot()
    { return 47; }

// formula step 1 - divide the chest by 6.28, pinned in hundredths (folio 6)
inline int dgmChestDivisorHundredths()
    { return 628; }

// formula step 3 - multiply by 3.12, pinned in hundredths (folio 6)
inline int dgmPiFactorHundredths()
    { return 312; }

// the chest-size factor - height inches times .5588, pinned in
// ten-thousandths (folio 6)
inline int dgmChestFactorTenThousandths()
    { return 5588; }

// the torso-length factor - height inches times .2647, pinned in
// ten-thousandths (folio 6)
inline int dgmTorsoFactorTenThousandths()
    { return 2647; }

// formula step 6 - divide by the 1728 cubic inches per cubic foot (folio 6)
inline int dgmCubicInchesPerCubicFoot()
    { return 1728; }

// the giant size grid - 26 rows from 5-foot-8 through 30 feet (folio 5)
inline int dgmGiantRows()
    { return 26; }

// the lift ladder reference man of 160 pounds, the 5-foot-8 row of the grid
// (folios 5-6)
inline int dgmLiftReferenceManLbs()
    { return 160; }

// the 30-foot giant worked example - 23,658.539 printed as 23,660 pounds, the
// anchor of the pounds column (folio 6)
inline int dgmExampleWeightLbs()
    { return 23660; }

// a weight-trained titan presses 47,300-71,000 pounds, the floor (folio 6)
inline int dgmTitanPressMinLbs()
    { return 47300; }

// the titan press ceiling, 2-3 times body weight (folio 6)
inline int dgmTitanPressMaxLbs()
    { return 71000; }

// bronze weighs 550 pounds per cubic foot - the non-flesh giant swaps the
// flesh density for the material density (folio 6)
inline int dgmBronzeLbsPerCubicFoot()
    { return 550; }

// the worked non-flesh example - a 60-foot bronze giant named Talos (folio 6)
inline int dgmTalosHeightFeet()
    { return 60; }

// the materials density grid - 64 rows across the two print columns, the
// seasoned woods included (folio 7)
inline int dgmMaterialRows()
    { return 64; }

// a giant carries his full weight on his back, the fireman carry (folio 6)
inline bool dgmCarryOwnWeightOnBack()
    { return true; }

// a giant holds three-quarters of his weight in his arms as dead balanced
// weight (folio 6)
inline bool dgmArmsThreeQuartersWeight()
    { return true; }

// a giant fairly easily picks up half his body weight of dead weight in two
// arms (folio 6)
inline bool dgmTwoArmsHalfDeadWeight()
    { return true; }

// a giant with difficulty picks up half his body weight of a struggling
// animal (folio 6)
inline bool dgmHalfWeightStrugglingAnimal()
    { return true; }

// a giant with mild difficulty picks up a quarter of his body weight, a
// struggling animal two-handed (folio 6)
inline bool dgmQuarterWeightStrugglingTwoHanded()
    { return true; }

// a giant fairly easily picks up a quarter of his body weight one-handed of
// balanced dead weight (folio 6)
inline bool dgmQuarterWeightOneHanded()
    { return true; }

// over- and under-weight giants scale by the percent the base man differs
// from the 160-pound reference (folio 5)
inline bool dgmOverUnderBaseWeightRule()
    { return true; }

// the height in inches - 5 foot 8 through 30 feet, the mixed print units
// pinned uniformly in inches, a noted conversion (folio 5)
inline int dgmGiantHeightInches(int b)
    {
        switch (b) {
        case 0:
            return 68;
        case 1:
            return 72;
        case 2:
            return 84;
        case 3:
            return 96;
        case 4:
            return 108;
        case 5:
            return 120;
        case 6:
            return 132;
        case 7:
            return 144;
        case 8:
            return 156;
        case 9:
            return 168;
        case 10:
            return 180;
        case 11:
            return 192;
        case 12:
            return 204;
        case 13:
            return 216;
        case 14:
            return 228;
        case 15:
            return 240;
        case 16:
            return 252;
        case 17:
            return 264;
        case 18:
            return 276;
        case 19:
            return 288;
        case 20:
            return 300;
        case 21:
            return 312;
        case 22:
            return 324;
        case 23:
            return 336;
        case 24:
            return 348;
        case 25:
            return 360;
        default:
            return -1;
        }
    }

// the weight in pounds - 160 at 5 foot 8 through 23,660 at 30 feet; the
// column is invisible to the djvu OCR, resolved at the full-res scan and
// anchored by the article 23,660 worked example (folios 5-6)
inline int dgmGiantWeightPounds(int b)
    {
        switch (b) {
        case 0:
            return 160;
        case 1:
            return 185;
        case 2:
            return 300;
        case 3:
            return 450;
        case 4:
            return 630;
        case 5:
            return 875;
        case 6:
            return 1175;
        case 7:
            return 1510;
        case 8:
            return 1930;
        case 9:
            return 2240;
        case 10:
            return 2950;
        case 11:
            return 3600;
        case 12:
            return 4340;
        case 13:
            return 5120;
        case 14:
            return 6050;
        case 15:
            return 7010;
        case 16:
            return 8140;
        case 17:
            return 9075;
        case 18:
            return 10675;
        case 19:
            return 12130;
        case 20:
            return 13700;
        case 21:
            return 15425;
        case 22:
            return 17275;
        case 23:
            return 19250;
        case 24:
            return 21400;
        case 25:
            return 23660;
        default:
            return -1;
        }
    }

// the weight in tons - the fraction print (1/4 through 11 3/4) pinned in
// quarter-ton units, a noted conversion; the 5-foot-8 through 8-foot cells
// print blank and ride the -1 sentinel (folio 5)
inline int dgmGiantWeightTonsQuarter(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 5;
        case 10:
            return 6;
        case 11:
            return 7;
        case 12:
            return 9;
        case 13:
            return 10;
        case 14:
            return 12;
        case 15:
            return 14;
        case 16:
            return 16;
        case 17:
            return 18;
        case 18:
            return 21;
        case 19:
            return 24;
        case 20:
            return 27;
        case 21:
            return 31;
        case 22:
            return 34;
        case 23:
            return 38;
        case 24:
            return 43;
        case 25:
            return 47;
        default:
            return -1;
        }
    }

// the chest size in inches - 38 at 5 foot 8 through 201 at 30 feet (folio 5)
inline int dgmGiantChestInches(int b)
    {
        switch (b) {
        case 0:
            return 38;
        case 1:
            return 40;
        case 2:
            return 47;
        case 3:
            return 54;
        case 4:
            return 60;
        case 5:
            return 67;
        case 6:
            return 74;
        case 7:
            return 80;
        case 8:
            return 87;
        case 9:
            return 94;
        case 10:
            return 100;
        case 11:
            return 107;
        case 12:
            return 114;
        case 13:
            return 120;
        case 14:
            return 127;
        case 15:
            return 134;
        case 16:
            return 141;
        case 17:
            return 148;
        case 18:
            return 154;
        case 19:
            return 161;
        case 20:
            return 168;
        case 21:
            return 174;
        case 22:
            return 181;
        case 23:
            return 188;
        case 24:
            return 194;
        case 25:
            return 201;
        default:
            return -1;
        }
    }

// the torso length in inches - 18 at 5 foot 8 through 96 at 30 feet; the
// column is invisible to the djvu OCR, resolved at the full-res scan, every
// row consistent with the .2647 torso factor (folio 5)
inline int dgmGiantTorsoInches(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 19;
        case 2:
            return 22;
        case 3:
            return 25;
        case 4:
            return 29;
        case 5:
            return 32;
        case 6:
            return 35;
        case 7:
            return 38;
        case 8:
            return 41;
        case 9:
            return 45;
        case 10:
            return 48;
        case 11:
            return 51;
        case 12:
            return 54;
        case 13:
            return 57;
        case 14:
            return 60;
        case 15:
            return 64;
        case 16:
            return 67;
        case 17:
            return 70;
        case 18:
            return 73;
        case 19:
            return 76;
        case 20:
            return 79;
        case 21:
            return 83;
        case 22:
            return 86;
        case 23:
            return 89;
        case 24:
            return 92;
        case 25:
            return 96;
        default:
            return -1;
        }
    }

// the material density floor in pounds per cubic foot, pinned in tenths - a
// uniform noted conversion of the print (folio 7)
inline int dgmMaterialLbsMinTenths(int b)
    {
        switch (b) {
        case 0:
            return 1250;
        case 1:
            return 600;
        case 2:
            return 1680;
        case 3:
            return 1700;
        case 4:
            return 1060;
        case 5:
            return 870;
        case 6:
            return 530;
        case 7:
            return 2550;
        case 8:
            return 620;
        case 9:
            return 1700;
        case 10:
            return 1180;
        case 11:
            return 350;
        case 12:
            return 5070;
        case 13:
            return 1120;
        case 14:
            return 870;
        case 15:
            return 620;
        case 16:
            return 140;
        case 17:
            return 1880;
        case 18:
            return 1770;
        case 19:
            return 1590;
        case 20:
            return 1640;
        case 21:
            return 4600;
        case 22:
            return 1970;
        case 23:
            return 1500;
        case 24:
            return 1650;
        case 25:
            return 810;
        case 26:
            return 3060;
        case 27:
            return 572;
        case 28:
            return 1140;
        case 29:
            return 540;
        case 30:
            return 3060;
        case 31:
            return 2310;
        case 32:
            return 1600;
        case 33:
            return 2180;
        case 34:
            return 1370;
        case 35:
            return 440;
        case 36:
            return 540;
        case 37:
            return 670;
        case 38:
            return 1430;
        case 39:
            return 3090;
        case 40:
            return 1650;
        case 41:
            return 1360;
        case 42:
            return 740;
        case 43:
            return 690;
        case 44:
            return 1340;
        case 45:
            return 1620;
        case 46:
            return 990;
        case 47:
            return 2190;
        case 48:
            return 1120;
        case 49:
            return 410;
        case 50:
            return 400;
        case 51:
            return 70;
        case 52:
            return 190;
        case 53:
            return 300;
        case 54:
            return 690;
        case 55:
            return 730;
        case 56:
            return 410;
        case 57:
            return 370;
        case 58:
            return 220;
        case 59:
            return 230;
        case 60:
            return 240;
        case 61:
            return 410;
        case 62:
            return 610;
        case 63:
            return 240;
        default:
            return -1;
        }
    }

// the material density ceiling in pounds per cubic foot, pinned in tenths;
// single-value prints pin floor-equals-ceiling (folio 7)
inline int dgmMaterialLbsMaxTenths(int b)
    {
        switch (b) {
        case 0:
            return 1750;
        case 1:
            return 610;
        case 2:
            return 1690;
        case 3:
            return 1900;
        case 4:
            return 1250;
        case 5:
            return 1370;
        case 6:
            return 540;
        case 7:
            return 2800;
        case 8:
            return 620;
        case 9:
            return 1900;
        case 10:
            return 1750;
        case 11:
            return 350;
        case 12:
            return 5070;
        case 13:
            return 1620;
        case 14:
            return 1120;
        case 15:
            return 1050;
        case 16:
            return 160;
        case 17:
            return 2200;
        case 18:
            return 1770;
        case 19:
            return 1720;
        case 20:
            return 1640;
        case 21:
            return 4700;
        case 22:
            return 2680;
        case 23:
            return 1750;
        case 24:
            return 1720;
        case 25:
            return 870;
        case 26:
            return 3300;
        case 27:
            return 572;
        case 28:
            return 1200;
        case 29:
            return 540;
        case 30:
            return 3240;
        case 31:
            return 2560;
        case 32:
            return 1770;
        case 33:
            return 2180;
        case 34:
            return 1370;
        case 35:
            return 720;
        case 36:
            return 570;
        case 37:
            return 670;
        case 38:
            return 1560;
        case 39:
            return 3180;
        case 40:
            return 1650;
        case 41:
            return 1360;
        case 42:
            return 740;
        case 43:
            return 690;
        case 44:
            return 1470;
        case 45:
            return 1750;
        case 46:
            return 990;
        case 47:
            return 2230;
        case 48:
            return 1120;
        case 49:
            return 520;
        case 50:
            return 530;
        case 51:
            return 90;
        case 52:
            return 250;
        case 53:
            return 350;
        case 54:
            return 830;
        case 55:
            return 830;
        case 56:
            return 410;
        case 57:
            return 560;
        case 58:
            return 310;
        case 59:
            return 370;
        case 60:
            return 370;
        case 61:
            return 550;
        case 62:
            return 610;
        case 63:
            return 370;
        default:
            return -1;
        }
    }

// ---- the Jon Pickens demon generation article (folio 9) ----

// six demon levels plus the Prince tier (folio 9)
inline int dgmDemonLevels()
    { return 6; }

// magic resistance of 50 percent at Level I (folio 9)
inline int dgmDemonMrBasePercent()
    { return 50; }

// magic resistance increases 5 percent for each additional demon level (folio
// 9)
inline int dgmDemonMrPerLevelPercent()
    { return 5; }

// each ability-level column runs twelve numbered entries (folio 9)
inline int dgmDemonAbilitySlots()
    { return 12; }

// level 1-3 abilities work at twice the demon level - the equivalent caster
// multiplier (folio 9)
inline int dgmDemonCasterMultiplierLow()
    { return 2; }

// level 4-6 abilities work at thrice the demon level (folio 9)
inline int dgmDemonCasterMultiplierHigh()
    { return 3; }

// princes always have the capabilities of 19th-level magic users or clerics
// (folio 9)
inline int dgmPrinceCasterLevel()
    { return 19; }

// a prince has a 50 percent chance of an artifact (folio 9)
inline int dgmPrinceArtifactChancePercent()
    { return 50; }

// the Level-VI demon - eight hit dice (folio 9)
inline int dgmL6HitDice()
    { return 8; }

// the Level-VI demon - ten-sided hit dice (folio 9)
inline int dgmL6HitDieSides()
    { return 10; }

// the Level-VI demon gates at 70 percent (folio 9)
inline int dgmL6GatePercent()
    { return 70; }

// the Level-VI demon gates in a Level 3-4 demon, the floor (folio 9)
inline int dgmL6GateLevelMin()
    { return 3; }

// the Level-VI gate ceiling, Level 3-4 (folio 9)
inline int dgmL6GateLevelMax()
    { return 4; }

// the worked Nasthrapur example - magic resistance raised to 80 percent
// (folio 9)
inline int dgmExampleL6MrPercent()
    { return 80; }

// the demon power-count grid - six demon-level rows over six ability-level
// columns (folio 9)
inline int dgmPowerGridRows()
    { return 6; }

// no demon may have both fire and ice powers (folio 9)
inline bool dgmNoFireAndIcePowers()
    { return true; }

// demons of Level III or less are vulnerable to normal weapons (folio 9)
inline bool dgmLowLevelsNormalWeaponsVulnerable()
    { return true; }

// demons above Level III can be hit by magic weapons only (folio 9)
inline bool dgmHighLevelsMagicWeaponsOnly()
    { return true; }

// a prince has 1-6 powers of each level but never less in any category than a
// Level-VI demon (folio 9)
inline bool dgmPrincesNeverBelowLevelSix()
    { return true; }

// a prince never has more powers of a higher level than a lesser demon (folio
// 9)
inline bool dgmPrincesNeverMoreHighThanLesser()
    { return true; }

// demon appearance-crossing gains the monster abilities but never the
// abilities of men - no extra magic-user spells, thief abilities or fighter
// strength bonuses (folio 9)
inline bool dgmMenAbilitiesNotGained()
    { return true; }

// Level V and VI demons must have one appearance roll considered human or
// basic animal (folio 9)
inline bool dgmHighDemonsHumanOrAnimalRoll()
    { return true; }

// princes always have the capabilities of 19th-level magic users or clerics
// (folio 9)
inline bool dgmPrincesAlwaysNineteenth()
    { return true; }

// the count of level-1 abilities by demon level - the I through VI rows print
// 2, 3, 3, 3, 3, 3 (folio 9)
inline int dgmPowersOfLevel1(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return -1;
        }
    }

// the count of level-2 abilities - the rows print blank, 2, 2, 3, 3, 3 (folio
// 9)
inline int dgmPowersOfLevel2(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return -1;
        }
    }

// the count of level-3 abilities - the rows print blank, blank, 2, 2, 2, 3
// (folio 9)
inline int dgmPowersOfLevel3(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
        default:
            return -1;
        }
    }

// the count of level-4 abilities - the rows print blank, blank, blank, 1, 2,
// 2 (folio 9)
inline int dgmPowersOfLevel4(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        default:
            return -1;
        }
    }

// the count of level-5 abilities - the rows print blank, blank, blank, blank,
// 1, 2 (folio 9)
inline int dgmPowersOfLevel5(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 2;
        default:
            return -1;
        }
    }

// the count of level-6 abilities - the rows print blank, blank, blank, blank,
// blank, 1; the dash cells pin as zero, the grid resolved at the full-res
// scan cross-validated against the djvu Level-IV fragment (folio 9)
inline int dgmPowersOfLevel6(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        default:
            return -1;
        }
    }

}   // namespace rules
