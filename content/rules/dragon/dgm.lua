-- dgm: promoted from tools/spec_r922.json (the The Dragon issue-13 opener part one - the Shlump da Orc giant physics article (folios 5-7) and the Jon Pickens demon generation article (folio 9): the all-usable adjudication, the Japanese Mythos to follow);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 922,
  "prefix" = "dgm",
  "banner" = {
      "title" = "The Dragon issue-13 opener part one - the Shlump da Orc giant physics article (folios 5-7) and the Jon Pickens demon generation article (folio 9): the all-usable adjudication, the Japanese Mythos to follow",
      "provenance" = "Pinned from The Dragon Vol. II No. 7 (April 1978), the archive.org scan voice (single-voice: no chat-side upload cross-check exists for issue 13; the source lives in the archive.org item accessory-dragon-magazine-012, file Accessory - Dragon Magazine #013_djvu.xml). PRINT FOLIO = PDF PAGE, verified at the TOC alignments (5, 8, 9, 11, 16-17, 19, 21, 22, 28-30). The transcripts ride extract/dragon/013/p001 through p032; the article CHAIN is the ink unit, not the folio.",
      "sentinel" = "Print quirks pinned AS SCANNED, noted never silent: the giant grid pounds column is invisible to the djvu OCR - the R919 visual-check precedent (the full-res scan plus the geometry plus a text anchor) resolved it, the 23,660 pounds of the 30-foot row matching the article own worked example; the tons column pins in quarter-ton units (a noted conversion) with the 5-foot-8 through 8-foot cells blank on the -1 sentinel; the torso column rides the same visual read, 17-of-17 rows formula-consistent with the .2647 factor; the materials grid pins in tenths (a noted conversion), the Ice 57.2, Lignum Vitae 73-83 and Mahogany 41 cells vision-resolved with provenance noted, the vision Quartz and Rubber misreads caught and corrected against the geometry; the demon power-count grid garbles in the OCR and resolved at the full-res scan, cross-validated against the djvu Level-IV fragment, the dash cells pinning as zero; the chest-in-feet sub-column rides the transcript, a unit restatement of the chest inches.",
    },
  "consts" = { {
      "name" = "dgmBaseManWeightLbs",
      "value" = 180,
      "comment" = "the formula base man - 180 pounds (folio 5)",
    }, {
      "name" = "dgmBaseManHeightInches",
      "value" = 68,
      "comment" = "the formula base man - 5 foot 8 tall, pinned in inches (folio 5)",
    }, {
      "name" = "dgmBaseManChestInches",
      "value" = 38,
      "comment" = "the formula base man - 38-inch chest (folio 5)",
    }, {
      "name" = "dgmBaseManTorsoInches",
      "value" = 18,
      "comment" = "the formula base man - 18-inch torso (folio 5)",
    }, {
      "name" = "dgmTorsoSharePercent",
      "value" = 35,
      "comment" = "the torso amounts to 35 percent of the whole body (folio 5)",
    }, {
      "name" = "dgmBodyLbsPerCubicFoot",
      "value" = 47,
      "comment" = "a cubic foot of human body weighs 47 pounds (folio 5)",
    }, {
      "name" = "dgmChestDivisorHundredths",
      "value" = 628,
      "comment" = "formula step 1 - divide the chest by 6.28, pinned in hundredths (folio 6)",
    }, {
      "name" = "dgmPiFactorHundredths",
      "value" = 312,
      "comment" = "formula step 3 - multiply by 3.12, pinned in hundredths (folio 6)",
    }, {
      "name" = "dgmChestFactorTenThousandths",
      "value" = 5588,
      "comment" = "the chest-size factor - height inches times .5588, pinned in ten-thousandths (folio 6)",
    }, {
      "name" = "dgmTorsoFactorTenThousandths",
      "value" = 2647,
      "comment" = "the torso-length factor - height inches times .2647, pinned in ten-thousandths (folio 6)",
    }, {
      "name" = "dgmCubicInchesPerCubicFoot",
      "value" = 1728,
      "comment" = "formula step 6 - divide by the 1728 cubic inches per cubic foot (folio 6)",
    }, {
      "name" = "dgmGiantRows",
      "value" = 26,
      "comment" = "the giant size grid - 26 rows from 5-foot-8 through 30 feet (folio 5)",
    }, {
      "name" = "dgmLiftReferenceManLbs",
      "value" = 160,
      "comment" = "the lift ladder reference man of 160 pounds, the 5-foot-8 row of the grid (folios 5-6)",
    }, {
      "name" = "dgmExampleWeightLbs",
      "value" = 23660,
      "comment" = "the 30-foot giant worked example - 23,658.539 printed as 23,660 pounds, the anchor of the pounds column (folio 6)",
    }, {
      "name" = "dgmTitanPressMinLbs",
      "value" = 47300,
      "comment" = "a weight-trained titan presses 47,300-71,000 pounds, the floor (folio 6)",
    }, {
      "name" = "dgmTitanPressMaxLbs",
      "value" = 71000,
      "comment" = "the titan press ceiling, 2-3 times body weight (folio 6)",
    }, {
      "name" = "dgmBronzeLbsPerCubicFoot",
      "value" = 550,
      "comment" = "bronze weighs 550 pounds per cubic foot - the non-flesh giant swaps the flesh density for the material density (folio 6)",
    }, {
      "name" = "dgmTalosHeightFeet",
      "value" = 60,
      "comment" = "the worked non-flesh example - a 60-foot bronze giant named Talos (folio 6)",
    }, {
      "name" = "dgmMaterialRows",
      "value" = 64,
      "comment" = "the materials density grid - 64 rows across the two print columns, the seasoned woods included (folio 7)",
    }, {
      "name" = "dgmDemonLevels",
      "value" = 6,
      "comment" = "six demon levels plus the Prince tier (folio 9)",
    }, {
      "name" = "dgmDemonMrBasePercent",
      "value" = 50,
      "comment" = "magic resistance of 50 percent at Level I (folio 9)",
    }, {
      "name" = "dgmDemonMrPerLevelPercent",
      "value" = 5,
      "comment" = "magic resistance increases 5 percent for each additional demon level (folio 9)",
    }, {
      "name" = "dgmDemonAbilitySlots",
      "value" = 12,
      "comment" = "each ability-level column runs twelve numbered entries (folio 9)",
    }, {
      "name" = "dgmDemonCasterMultiplierLow",
      "value" = 2,
      "comment" = "level 1-3 abilities work at twice the demon level - the equivalent caster multiplier (folio 9)",
    }, {
      "name" = "dgmDemonCasterMultiplierHigh",
      "value" = 3,
      "comment" = "level 4-6 abilities work at thrice the demon level (folio 9)",
    }, {
      "name" = "dgmPrinceCasterLevel",
      "value" = 19,
      "comment" = "princes always have the capabilities of 19th-level magic users or clerics (folio 9)",
    }, {
      "name" = "dgmPrinceArtifactChancePercent",
      "value" = 50,
      "comment" = "a prince has a 50 percent chance of an artifact (folio 9)",
    }, {
      "name" = "dgmL6HitDice",
      "value" = 8,
      "comment" = "the Level-VI demon - eight hit dice (folio 9)",
    }, {
      "name" = "dgmL6HitDieSides",
      "value" = 10,
      "comment" = "the Level-VI demon - ten-sided hit dice (folio 9)",
    }, {
      "name" = "dgmL6GatePercent",
      "value" = 70,
      "comment" = "the Level-VI demon gates at 70 percent (folio 9)",
    }, {
      "name" = "dgmL6GateLevelMin",
      "value" = 3,
      "comment" = "the Level-VI demon gates in a Level 3-4 demon, the floor (folio 9)",
    }, {
      "name" = "dgmL6GateLevelMax",
      "value" = 4,
      "comment" = "the Level-VI gate ceiling, Level 3-4 (folio 9)",
    }, {
      "name" = "dgmExampleL6MrPercent",
      "value" = 80,
      "comment" = "the worked Nasthrapur example - magic resistance raised to 80 percent (folio 9)",
    }, {
      "name" = "dgmPowerGridRows",
      "value" = 6,
      "comment" = "the demon power-count grid - six demon-level rows over six ability-level columns (folio 9)",
    } },
  "bools" = { {
      "name" = "dgmCarryOwnWeightOnBack",
      "value" = true,
      "comment" = "a giant carries his full weight on his back, the fireman carry (folio 6)",
    }, {
      "name" = "dgmArmsThreeQuartersWeight",
      "value" = true,
      "comment" = "a giant holds three-quarters of his weight in his arms as dead balanced weight (folio 6)",
    }, {
      "name" = "dgmTwoArmsHalfDeadWeight",
      "value" = true,
      "comment" = "a giant fairly easily picks up half his body weight of dead weight in two arms (folio 6)",
    }, {
      "name" = "dgmHalfWeightStrugglingAnimal",
      "value" = true,
      "comment" = "a giant with difficulty picks up half his body weight of a struggling animal (folio 6)",
    }, {
      "name" = "dgmQuarterWeightStrugglingTwoHanded",
      "value" = true,
      "comment" = "a giant with mild difficulty picks up a quarter of his body weight, a struggling animal two-handed (folio 6)",
    }, {
      "name" = "dgmQuarterWeightOneHanded",
      "value" = true,
      "comment" = "a giant fairly easily picks up a quarter of his body weight one-handed of balanced dead weight (folio 6)",
    }, {
      "name" = "dgmOverUnderBaseWeightRule",
      "value" = true,
      "comment" = "over- and under-weight giants scale by the percent the base man differs from the 160-pound reference (folio 5)",
    }, {
      "name" = "dgmNoFireAndIcePowers",
      "value" = true,
      "comment" = "no demon may have both fire and ice powers (folio 9)",
    }, {
      "name" = "dgmLowLevelsNormalWeaponsVulnerable",
      "value" = true,
      "comment" = "demons of Level III or less are vulnerable to normal weapons (folio 9)",
    }, {
      "name" = "dgmHighLevelsMagicWeaponsOnly",
      "value" = true,
      "comment" = "demons above Level III can be hit by magic weapons only (folio 9)",
    }, {
      "name" = "dgmPrincesNeverBelowLevelSix",
      "value" = true,
      "comment" = "a prince has 1-6 powers of each level but never less in any category than a Level-VI demon (folio 9)",
    }, {
      "name" = "dgmPrincesAlwaysNineteenth",
      "value" = true,
      "comment" = "princes always have the capabilities of 19th-level magic users or clerics (folio 9)",
    }, {
      "name" = "dgmPrincesNeverMoreHighThanLesser",
      "value" = true,
      "comment" = "a prince never has more powers of a higher level than a lesser demon (folio 9)",
    }, {
      "name" = "dgmMenAbilitiesNotGained",
      "value" = true,
      "comment" = "demon appearance-crossing gains the monster abilities but never the abilities of men - no extra magic-user spells, thief abilities or fighter strength bonuses (folio 9)",
    }, {
      "name" = "dgmHighDemonsHumanOrAnimalRoll",
      "value" = true,
      "comment" = "Level V and VI demons must have one appearance roll considered human or basic animal (folio 9)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "dgmGiantSize",
      "tag" = "GS",
      "count" = "dgmGiantRows",
      "sentinel" = -1,
      "sentinel_census" = { 0, 0, 4, 0, 0 },
      "audit_comment" = "the giant size grid - the pounds and torso columns are invisible to the djvu OCR and resolved at the full-res scan (the R919 visual-check precedent), the pounds anchored by the article 23,660 worked example and the torso by the .2647 factor row by row; the tons pin in quarter-ton units with the four blank short rows on the sentinel, noted never silent (folio 5)",
      "cols" = { "dgmGiantHeightInches", "dgmGiantWeightPounds", "dgmGiantWeightTonsQuarter", "dgmGiantChestInches", "dgmGiantTorsoInches" },
      "col_comments" = { "the height in inches - 5 foot 8 through 30 feet, the mixed print units pinned uniformly in inches, a noted conversion (folio 5)", "the weight in pounds - 160 at 5 foot 8 through 23,660 at 30 feet; the column is invisible to the djvu OCR, resolved at the full-res scan and anchored by the article 23,660 worked example (folios 5-6)", "the weight in tons - the fraction print (1/4 through 11 3/4) pinned in quarter-ton units, a noted conversion; the 5-foot-8 through 8-foot cells print blank and ride the -1 sentinel (folio 5)", "the chest size in inches - 38 at 5 foot 8 through 201 at 30 feet (folio 5)", "the torso length in inches - 18 at 5 foot 8 through 96 at 30 feet; the column is invisible to the djvu OCR, resolved at the full-res scan, every row consistent with the .2647 torso factor (folio 5)" },
      "data" = { { 68, 160, -1, 38, 18 }, { 72, 185, -1, 40, 19 }, { 84, 300, -1, 47, 22 }, { 96, 450, -1, 54, 25 }, { 108, 630, 1, 60, 29 }, { 120, 875, 1, 67, 32 }, { 132, 1175, 2, 74, 35 }, { 144, 1510, 3, 80, 38 }, { 156, 1930, 4, 87, 41 }, { 168, 2240, 5, 94, 45 }, { 180, 2950, 6, 100, 48 }, { 192, 3600, 7, 107, 51 }, { 204, 4340, 9, 114, 54 }, { 216, 5120, 10, 120, 57 }, { 228, 6050, 12, 127, 60 }, { 240, 7010, 14, 134, 64 }, { 252, 8140, 16, 141, 67 }, { 264, 9075, 18, 148, 70 }, { 276, 10675, 21, 154, 73 }, { 288, 12130, 24, 161, 76 }, { 300, 13700, 27, 168, 79 }, { 312, 15425, 31, 174, 83 }, { 324, 17275, 34, 181, 86 }, { 336, 19250, 38, 188, 89 }, { 348, 21400, 43, 194, 92 }, { 360, 23660, 47, 201, 96 } },
    }, {
      "name" = "dgmMaterialDensity",
      "tag" = "MD",
      "count" = "dgmMaterialRows",
      "sentinel" = -1,
      "sentinel_census" = { 0, 0 },
      "audit_comment" = "the 64-row materials density grid for non-flesh giants - the print is two columns with ranges and singles, pinned in tenths (a noted conversion); the Ice 57.2, Lignum Vitae 73-83 and Mahogany 41 cells resolve only at the full-res scan with provenance noted, the vision Quartz and Rubber misreads caught against the geometry (folio 7)",
      "cols" = { "dgmMaterialLbsMinTenths", "dgmMaterialLbsMaxTenths" },
      "col_comments" = { "the material density floor in pounds per cubic foot, pinned in tenths - a uniform noted conversion of the print (folio 7)", "the material density ceiling in pounds per cubic foot, pinned in tenths; single-value prints pin floor-equals-ceiling (folio 7)" },
      "data" = { { 1250, 1750 }, { 600, 610 }, { 1680, 1690 }, { 1700, 1900 }, { 1060, 1250 }, { 870, 1370 }, { 530, 540 }, { 2550, 2800 }, { 620, 620 }, { 1700, 1900 }, { 1180, 1750 }, { 350, 350 }, { 5070, 5070 }, { 1120, 1620 }, { 870, 1120 }, { 620, 1050 }, { 140, 160 }, { 1880, 2200 }, { 1770, 1770 }, { 1590, 1720 }, { 1640, 1640 }, { 4600, 4700 }, { 1970, 2680 }, { 1500, 1750 }, { 1650, 1720 }, { 810, 870 }, { 3060, 3300 }, { 572, 572 }, { 1140, 1200 }, { 540, 540 }, { 3060, 3240 }, { 2310, 2560 }, { 1600, 1770 }, { 2180, 2180 }, { 1370, 1370 }, { 440, 720 }, { 540, 570 }, { 670, 670 }, { 1430, 1560 }, { 3090, 3180 }, { 1650, 1650 }, { 1360, 1360 }, { 740, 740 }, { 690, 690 }, { 1340, 1470 }, { 1620, 1750 }, { 990, 990 }, { 2190, 2230 }, { 1120, 1120 }, { 410, 520 }, { 400, 530 }, { 70, 90 }, { 190, 250 }, { 300, 350 }, { 690, 830 }, { 730, 830 }, { 410, 410 }, { 370, 560 }, { 220, 310 }, { 230, 370 }, { 240, 370 }, { 410, 550 }, { 610, 610 }, { 240, 370 } },
    }, {
      "name" = "dgmDemonPowerGrid",
      "tag" = "DP",
      "count" = "dgmPowerGridRows",
      "sentinel" = -1,
      "sentinel_census" = { 0, 0, 0, 0, 0, 0 },
      "audit_comment" = "the demon power-count grid - the OCR garbles it whole (L223 An SG); the full-res scan resolved it and the djvu Level-IV fragment (3, 3, 2, 1) cross-validates; the not-applicable dash cells pin as zero, noted never silent (folio 9)",
      "cols" = { "dgmPowersOfLevel1", "dgmPowersOfLevel2", "dgmPowersOfLevel3", "dgmPowersOfLevel4", "dgmPowersOfLevel5", "dgmPowersOfLevel6" },
      "col_comments" = { "the count of level-1 abilities by demon level - the I through VI rows print 2, 3, 3, 3, 3, 3 (folio 9)", "the count of level-2 abilities - the rows print blank, 2, 2, 3, 3, 3 (folio 9)", "the count of level-3 abilities - the rows print blank, blank, 2, 2, 2, 3 (folio 9)", "the count of level-4 abilities - the rows print blank, blank, blank, 1, 2, 2 (folio 9)", "the count of level-5 abilities - the rows print blank, blank, blank, blank, 1, 2 (folio 9)", "the count of level-6 abilities - the rows print blank, blank, blank, blank, blank, 1; the dash cells pin as zero, the grid resolved at the full-res scan cross-validated against the djvu Level-IV fragment (folio 9)" },
      "data" = { { 2, 0, 0, 0, 0, 0 }, { 3, 2, 0, 0, 0, 0 }, { 3, 2, 2, 0, 0, 0 }, { 3, 3, 2, 1, 0, 0 }, { 3, 3, 2, 2, 1, 0 }, { 3, 3, 3, 2, 2, 1 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgmBaseManWeightLbs']() != 180 or m['dgmBaseManHeightInches']() != 68 or m['dgmBaseManChestInches']() != 38 or m['dgmBaseManTorsoInches']() != 18 or m['dgmLiftReferenceManLbs']() != 160",
      "note" = "the base man block - 180 pounds, 5 foot 8, a 38-inch chest, an 18-inch torso, the lift ladder referenced to the 160-pound man (folio 5)",
    }, {
      "expr" = "m['dgmChestDivisorHundredths']() != 628 or m['dgmPiFactorHundredths']() != 312 or m['dgmChestFactorTenThousandths']() != 5588 or m['dgmTorsoFactorTenThousandths']() != 2647 or m['dgmCubicInchesPerCubicFoot']() != 1728 or m['dgmBodyLbsPerCubicFoot']() != 47 or m['dgmTorsoSharePercent']() != 35",
      "note" = "the formula scalars - 6.28, 3.12, .5588, .2647, 1728, 47 pounds per cubic foot and the 35-percent torso share, pinned scaled as printed-decimal conversions (folios 5-6)",
    }, {
      "expr" = "m['dgmGiantHeightInches'](25) != 360 or m['dgmGiantWeightPounds'](25) != 23660 or m['dgmGiantWeightTonsQuarter'](25) != 47 or m['dgmGiantChestInches'](25) != 201 or m['dgmGiantTorsoInches'](25) != 96 or m['dgmExampleWeightLbs']() != 23660",
      "note" = "the 30-foot row - 360 inches, 23,660 pounds (the article worked example), 11 3/4 tons as 47 quarter-tons, a 201-inch chest and a 96-inch torso (folio 5)",
    }, {
      "expr" = "m['dgmGiantHeightInches'](0) != 68 or m['dgmGiantWeightPounds'](0) != 160 or m['dgmGiantWeightTonsQuarter'](0) != -1 or m['dgmGiantChestInches'](0) != 38 or m['dgmGiantTorsoInches'](0) != 18",
      "note" = "the 5-foot-8 row - 160 pounds on the blank tons sentinel, the base-man measurements (folio 5)",
    }, {
      "expr" = "m['dgmTitanPressMinLbs']() != 47300 or m['dgmTitanPressMaxLbs']() != 71000 or m['dgmBronzeLbsPerCubicFoot']() != 550 or m['dgmTalosHeightFeet']() != 60",
      "note" = "the titan press and the non-flesh example - 47,300-71,000 pressed, bronze at 550 pounds per cubic foot, the 60-foot Talos (folio 6)",
    }, {
      "expr" = "m['dgmCarryOwnWeightOnBack']() != 1 or m['dgmArmsThreeQuartersWeight']() != 1 or m['dgmTwoArmsHalfDeadWeight']() != 1 or m['dgmHalfWeightStrugglingAnimal']() != 1 or m['dgmQuarterWeightStrugglingTwoHanded']() != 1 or m['dgmQuarterWeightOneHanded']() != 1 or m['dgmOverUnderBaseWeightRule']() != 1",
      "note" = "the six-step lift ladder and the over-under base-weight rule (folios 5-6)",
    }, {
      "expr" = "m['dgmDemonLevels']() != 6 or m['dgmDemonMrBasePercent']() != 50 or m['dgmDemonMrPerLevelPercent']() != 5 or m['dgmExampleL6MrPercent']() != 80",
      "note" = "the demon magic resistance - 50 percent at Level I plus 5 per level, the worked example raised to 80 (folio 9)",
    }, {
      "expr" = "m['dgmL6HitDice']() != 8 or m['dgmL6HitDieSides']() != 10 or m['dgmL6GatePercent']() != 70 or m['dgmL6GateLevelMin']() != 3 or m['dgmL6GateLevelMax']() != 4",
      "note" = "the Level-VI worked constants - eight ten-sided hit dice, the 70-percent Level 3-4 gate (folio 9)",
    }, {
      "expr" = "m['dgmPrinceCasterLevel']() != 19 or m['dgmPrinceArtifactChancePercent']() != 50 or m['dgmPrincesNeverBelowLevelSix']() != 1 or m['dgmPrincesAlwaysNineteenth']() != 1",
      "note" = "the Prince tier - 19th-level caster capability, the 50-percent artifact, never below a Level-VI demon (folio 9)",
    }, {
      "expr" = "m['dgmDemonCasterMultiplierLow']() != 2 or m['dgmDemonCasterMultiplierHigh']() != 3 or m['dgmDemonAbilitySlots']() != 12",
      "note" = "the caster multipliers and the twelve-entry ability slots (folio 9)",
    }, {
      "expr" = "m['dgmNoFireAndIcePowers']() != 1 or m['dgmLowLevelsNormalWeaponsVulnerable']() != 1 or m['dgmHighLevelsMagicWeaponsOnly']() != 1 or m['dgmMenAbilitiesNotGained']() != 1 or m['dgmHighDemonsHumanOrAnimalRoll']() != 1",
      "note" = "the demon restrictions - no fire-and-ice, the weapon tiers, no men abilities gained, the human or animal roll (folio 9)",
    } },
  "audit" = {
      "label" = "R922 issue-13 opener audit",
      "comment" = "THE DRAGON ISSUE-13 OPENER ROUND, PART ONE - the all-usable adjudication, every engine-relevant chain of the issue. The How Heavy Is My Giant article by Shlump da Orc (folios 5-7): the 180-pound 5-foot-8 base man of the formula, the 35-percent torso share, the 47-pounds-per-cubic-foot flesh density, the formula scalars (6.28, 3.12, .5588, .2647, 1728), the 26-row size grid from 5-foot-8 through 30 feet with its pounds column (invisible to the OCR, visually confirmed and anchored by the article 23,660 worked example), the tons column pinned in quarter-ton units with the 5-foot-8 through 8-foot cells blank on the sentinel, the chest and torso columns, the six-step lift ladder, the over-under base-weight rule on the 160-pound reference man, the 47,300 to 71,000 titan press, and the 64-row materials density grid pinned in tenths - the Ice 57.2, Lignum Vitae 73-83 and Mahogany 41 cells resolved at the full-res scan, provenance noted. The Demon Generation article by Jon Pickens (folio 9): the six demon levels, the 50-percent magic resistance plus 5 per level, the power-count grid (visually confirmed against the djvu fragments) with the dash cells pinned as zero, the 12-entry ability slots, the 2-and-3 caster multipliers, the no-fire-and-ice rule, the weapon-vulnerability tiers, the Prince rules (19th-level casters, the 50-percent artifact) and the Level-VI worked constants (8 ten-sided hit dice, the 70-percent Level 3-4 gate). The issue-13 report rides pre-flip; the Japanese Mythos box closes at the part-two round.",
    },
}
