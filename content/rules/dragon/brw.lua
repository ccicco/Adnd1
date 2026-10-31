-- brw: promoted from tools/spec_r917.json (the The Dragon issue-11 opener - the Kuntz brawling article (folio 7) and the Ward quarterstaff article (folios 26-27): two adjudicated chains in one round);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 917,
  "prefix" = "brw",
  "banner" = {
      "title" = "The Dragon issue-11 opener - the Kuntz brawling article (folio 7) and the Ward quarterstaff article (folios 26-27): two adjudicated chains in one round",
      "provenance" = "Pinned from The Dragon Vol. II No. 5 (December 1977), the archive.org scan voice (single-voice: no chat-side upload cross-check exists for issue 11; the source lives in the archive.org item accessory-dragon-magazine-012, file Accessory - Dragon Magazine #011_djvu.xml). PRINT FOLIO = PDF PAGE, verified at the TOC alignments - the guest editorial at 5, the brawling article at 7, the Sorcerer's Scroll column at 16, the Sea Magic byline at 17, the quarterstaff rules at 26 and the Fineous Fingers comic at 29; no printed footer digits survive this scan. The transcripts ride extract/dragon/011/p001 through p038; the article CHAIN is the ink unit, not the folio.",
      "sentinel" = "The punch grid's row-2 plus-four-or-higher cell garbles in the DjVu OCR (a quoted 3) and rides the -9 sentinel with its one-cell census; the four clean row-2 cells anchor to the print's own snake-eyes note (the plus-3 -4 for 40 percent, the 0-or-lower -1 for 10); the -5 haymaker of the legend never prints clean in the grid. The quarterstaff worked example's 7-or-more hit floor reads against the rules text's third-stage 9 less the dexterity-18 plus-3 = 6 - the rules text is the pin, the discrepancy noted never silent.",
    },
  "consts" = { {
      "name" = "brwFirstMoveDexGap",
      "value" = 2,
      "comment" = "the first-move gap - a dexterity +2 or more comparatively moves first (folio 7)",
    }, {
      "name" = "brwBrawlDiceCount",
      "value" = 2,
      "comment" = "two six-sided dice drive the brawl (folio 7)",
    }, {
      "name" = "brwBrawlDiceSides",
      "value" = 6,
      "comment" = "the six-sided brawl die (folio 7)",
    }, {
      "name" = "brwPunchHitMax",
      "value" = 7,
      "comment" = "a punch hits on a 2-7 roll, above that a miss (folio 7)",
    }, {
      "name" = "brwPunchSecondHitMax",
      "value" = 6,
      "comment" = "second and further punches need a 2-6 (folio 7)",
    }, {
      "name" = "brwExtraPunchPenalty",
      "value" = 1,
      "comment" = "each extra punch rides at -1 per die roll (folio 7)",
    }, {
      "name" = "brwUnconsciousAtCon",
      "value" = 0,
      "comment" = "zero constitution points drops the brawler unconscious (folio 7)",
    }, {
      "name" = "brwKnockoutPercentPerPoint",
      "value" = 10,
      "comment" = "the snake-eyes knockout chance is the netted score times 10 percent (folio 7)",
    }, {
      "name" = "brwBreakFreeMinG",
      "value" = 2,
      "comment" = "a G2 or higher is needed to break a grapple (folio 7)",
    }, {
      "name" = "brwGrappleRows",
      "value" = 11,
      "comment" = "the grappling grid rows - the 2d6 rolls 2 through 12 (folio 7)",
    }, {
      "name" = "brwPunchRows",
      "value" = 11,
      "comment" = "the punch grid rows - the 2d6 rolls 2 through 12 (folio 7)",
    }, {
      "name" = "brwStageOneHit",
      "value" = 12,
      "comment" = "a first-stage staffer hits on a 12 or more (folio 26)",
    }, {
      "name" = "brwStageTwoHit",
      "value" = 11,
      "comment" = "a second-stage staffer hits on an 11 (folio 26)",
    }, {
      "name" = "brwStageThreeHit",
      "value" = 9,
      "comment" = "a third-stage staffer hits on a 9 (folio 26)",
    }, {
      "name" = "brwStaffDamageSides",
      "value" = 6,
      "comment" = "a hit rolls a six-sided die for damage plus strength bonuses (folio 26)",
    }, {
      "name" = "brwNaturalTwentyBonus",
      "value" = 1,
      "comment" = "an unmodified hit of 20 adds one point of damage to the die (folio 26)",
    }, {
      "name" = "brwDoubleAttackExtraDamage",
      "value" = 3,
      "comment" = "a double attacker takes an extra three points of damage if hit that turn, not per hit (folio 26)",
    }, {
      "name" = "brwForcedDefendThreshold",
      "value" = 4,
      "comment" = "two strikes doing more than four points force the opponent to defend twice next turn (folio 26)",
    }, {
      "name" = "brwFullNegateNextBonus",
      "value" = 1,
      "comment" = "a double defense negating all damage grants plus one on the first strike next turn (folio 26)",
    }, {
      "name" = "brwChainmailAbsorb",
      "value" = 4,
      "comment" = "chainmail absorbs four points of damage every time the wearer is hit (folio 26)",
    }, {
      "name" = "brwChainmailHitPenalty",
      "value" = 3,
      "comment" = "chainmail adds 3 to the wearer's hit roll (folio 26)",
    }, {
      "name" = "brwPlateAbsorb",
      "value" = 6,
      "comment" = "platemail absorbs six points of damage every time the wearer is hit (folio 26)",
    }, {
      "name" = "brwPlateHitPenalty",
      "value" = 5,
      "comment" = "platemail adds 5 to the wearer's hit roll (folio 26)",
    }, {
      "name" = "brwOutColdAtPoints",
      "value" = 1,
      "comment" = "a staffer fights until he is down to one Combat Index point, then out cold (folio 26)",
    }, {
      "name" = "brwAdvanceMatches",
      "value" = 50,
      "comment" = "50 matches against equal-or-better opponents drive the stage ladder (folio 26)",
    }, {
      "name" = "brwAdvanceWins",
      "value" = 30,
      "comment" = "winning 30 of the 50 matches raises a first-stage staffer to second (folio 26)",
    }, {
      "name" = "brwAdvanceDoubleFactor",
      "value" = 2,
      "comment" = "doubling the matches-and-wins raises a second-stage staffer to third (folio 26)",
    }, {
      "name" = "brwStrBonusEighteen",
      "value" = 2,
      "comment" = "an 18 strength adds plus 2 on damage (folio 26)",
    }, {
      "name" = "brwStrBonusSeventeen",
      "value" = 1,
      "comment" = "a 17 strength adds plus 1 on damage (folio 26)",
    }, {
      "name" = "brwConAbsorbEighteen",
      "value" = 2,
      "comment" = "an 18 constitution absorbs 2 points of damage every melee turn (folio 26)",
    }, {
      "name" = "brwConAbsorbSeventeen",
      "value" = 1,
      "comment" = "a 17 constitution absorbs 1 point of damage every melee turn (folio 26)",
    }, {
      "name" = "brwDexLadderRows",
      "value" = 3,
      "comment" = "the dexterity ladder rows - the 16, 17 and 18 bonuses (folio 26)",
    }, {
      "name" = "brwMerryMen",
      "value" = 9,
      "comment" = "the nine merry men of Robin Hood's band statted for historical simulations (folio 27)",
    } },
  "bools" = { {
      "name" = "brwAveragedGrappleRoundsDown",
      "value" = true,
      "comment" = "combine and average the grapple dexterity and strength of both players, rounded down (folio 7)",
    }, {
      "name" = "brwConstitutionIsBrawlPool",
      "value" = true,
      "comment" = "brawl damage subtracts from the constitution score (folio 7)",
    }, {
      "name" = "brwRecompareOnConChange",
      "value" = true,
      "comment" = "constitution changes force re-comparisons during the next round (folio 7)",
    }, {
      "name" = "brwDexMultiplesGrantExtraPunches",
      "value" = true,
      "comment" = "a dexterity doubling or trebling the opponent's grants that many more punches (folio 7)",
    }, {
      "name" = "brwContinueHoldNgFrees",
      "value" = true,
      "comment" = "an NG on the attacker's continue-hold roll frees the defender to punch or grapple (folio 7)",
    }, {
      "name" = "brwSnakeEyesKnockoutRoll",
      "value" = true,
      "comment" = "a roll of snake eyes on the punch grid opens the automatic-knockout chance (folio 7)",
    }, {
      "name" = "brwGCodesAreDamage",
      "value" = true,
      "comment" = "G1 through G4 mean grappled for that many points of damage, NG no grapple (folio 7)",
    }, {
      "name" = "brwThreeMeleeOptions",
      "value" = true,
      "comment" = "each staffer chooses attack-attack, attack-defend or defend-defend each melee turn (folio 26)",
    }, {
      "name" = "brwCombatSimultaneous",
      "value" = true,
      "comment" = "all staff combat is simultaneous regardless of any first hit (folio 26)",
    }, {
      "name" = "brwSecretOrdersOption",
      "value" = true,
      "comment" = "the suggested option - secretly write down each melee turn's plan (folio 26)",
    }, {
      "name" = "brwArmorAbsorbsPerHit",
      "value" = true,
      "comment" = "chainmail and platemail absorb their points every time the wearer is hit (folio 26)",
    }, {
      "name" = "brwDoubleStrikeForcesDefend",
      "value" = true,
      "comment" = "a staffer struck twice for more than four points is forced to defend twice next turn (folio 26)",
    }, {
      "name" = "brwFullNegateGrantsPlusOne",
      "value" = true,
      "comment" = "a double defense negating all the damage grants plus one on the first strike next turn (folio 26)",
    }, {
      "name" = "brwCombatIndexIsStrCon",
      "value" = true,
      "comment" = "the Combat Index is the strength plus constitution scores added together (folio 26)",
    }, {
      "name" = "brwStageAdvancementByMatches",
      "value" = true,
      "comment" = "experience raises the stage - the 50-match ladder at 30 wins (folio 26)",
    }, {
      "name" = "brwMerryMenForHistoricalSim",
      "value" = true,
      "comment" = "the merry men carry their probable qualities for historical simulations (folio 27)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "brwGrapple",
      "tag" = "GA",
      "count" = "brwGrappleRows",
      "sentinel" = -1,
      "cols" = { "brwGrapplePlus4Hi", "brwGrapplePlus3", "brwGrapplePlus2", "brwGrapplePlus1", "brwGrappleZeroLo" },
      "col_comments" = { "the grappling grid, +4 or higher column - the 2d6 rows 2 through 12 as G-code 1-4, 0 the NG (folio 7)", "the grappling grid, +3 column (folio 7)", "the grappling grid, +2 column (folio 7)", "the grappling grid, +1 column (folio 7)", "the grappling grid, 0-or-lower column (folio 7)" },
      "data" = { { 4, 3, 3, 2, 2 }, { 3, 3, 3, 2, 2 }, { 3, 3, 2, 2, 2 }, { 3, 3, 2, 2, 2 }, { 2, 2, 1, 1, 1 }, { 2, 2, 1, 1, 1 }, { 2, 2, 1, 1, 0 }, { 1, 1, 1, 1, 0 }, { 1, 1, 1, 0, 0 }, { 1, 1, 0, 0, 0 }, { 1, 0, 0, 0, 0 } },
    }, {
      "name" = "brwPunch",
      "tag" = "PB",
      "count" = "brwPunchRows",
      "sentinel" = -9,
      "sentinel_census" = { 1, 0, 0, 0, 0 },
      "audit_comment" = "the punch damage grid - the row-2 plus-four-or-higher cell garbles in the DjVu OCR (a quoted 3) and rides the -9 sentinel; the four clean row-2 cells anchor to the print's own snake-eyes note; the -5 haymaker of the legend never prints clean in the grid (folio 7)",
      "cols" = { "brwPunchPlus4Hi", "brwPunchPlus3", "brwPunchPlus2", "brwPunchPlus1", "brwPunchZeroLo" },
      "col_comments" = { "the punch grid, +4 or higher column - the 2d6 rows as damage points, 0 the miss, the row-2 cell riding the -9 sentinel (folio 7)", "the punch grid, +3 column - the row-2 -4 solid punch of the snake-eyes note (folio 7)", "the punch grid, +2 column (folio 7)", "the punch grid, +1 column (folio 7)", "the punch grid, 0-or-lower column - the row-2 -1 of the 10-percent note (folio 7)" },
      "data" = { { -9, -4, -3, -2, -1 }, { -3, -3, -2, -2, -1 }, { -3, -3, -2, -1, -1 }, { -3, -2, -2, -1, -1 }, { -2, -2, -2, -1, -1 }, { -2, -2, -1, -1, -1 }, { -2, -1, -1, -1, 0 }, { -2, -1, -1, 0, 0 }, { -2, -1, 0, 0, 0 }, { -1, -1, 0, 0, 0 }, { -1, 0, 0, 0, 0 } },
    }, {
      "name" = "brwDexLadder",
      "tag" = "DX",
      "count" = "brwDexLadderRows",
      "sentinel" = -1,
      "cols" = { "brwDexHitPlus", "brwDexAbsorb" },
      "col_comments" = { "the dexterity ladder hit pluses - the rows the 16, 17 and 18 dexterity (folio 26)", "the dexterity ladder absorbs - plus 2, 1 and none across the ladder (folio 26)" },
      "data" = { { 1, 0 }, { 2, 1 }, { 3, 2 } },
    }, {
      "name" = "brwMerryMen",
      "tag" = "MM",
      "count" = "brwMerryMen",
      "sentinel" = -1,
      "audit_comment" = "the nine merry men - Robin Hood, Little John, Will Scarlet, Will Stutely, Friar Tuck, Arthur-a-Bland, David of Doncaster, Wat of the Crab Staff and Much the Miller's Son, in the print order (folio 27)",
      "cols" = { "brwMerryStr", "brwMerryDex", "brwMerryCon", "brwMerryStage" },
      "col_comments" = { "the merry men strength scores (folio 27)", "the merry men dexterity scores (folio 27)", "the merry men constitution scores (folio 27)", "the merry men proficiency stages (folio 27)" },
      "data" = { { 17, 18, 17, 3 }, { 18, 18, 18, 3 }, { 18, 17, 17, 3 }, { 17, 17, 15, 3 }, { 18, 16, 17, 3 }, { 17, 18, 18, 3 }, { 17, 17, 17, 2 }, { 17, 16, 18, 3 }, { 17, 17, 17, 2 } },
    } },
  "chains" = { {
      "name" = "brwDiffBand",
      "limits" = { 0, 1, 2, 3 },
      "tail" = 4,
      "comment" = "the difference band - call with 4 minus the attacker's advantage: band 0 the +4-or-higher column, 1 the +3, 2 the +2, 3 the +1, the tail the 0-or-lower (folio 7)",
    } },
  "examples" = { {
      "expr" = "m['brwFirstMoveDexGap']() != 2 or m['brwDiffBand'](0) != 0 or m['brwDiffBand'](4) != 4",
      "note" = "the first-move gap and the difference bands - a +4 advantage opens band 0, the 0-or-lower rides the tail (folio 7)",
    }, {
      "expr" = "m['brwGrapplePlus1'](1) != 2",
      "note" = "the worked grapple - the +1 band at the roll of 3 nets G2, two points held (folio 7)",
    }, {
      "expr" = "m['brwGrappleZeroLo'](1) != 2 or m['brwBreakFreeMinG']() != 2",
      "note" = "the worked break - the 0-or-lower band at the roll of 3 nets the G2 break minimum (folio 7)",
    }, {
      "expr" = "m['brwPunchPlus3'](0) != -4 or m['brwPunchZeroLo'](0) != -1 or m['brwKnockoutPercentPerPoint']() != 10",
      "note" = "the snake-eyes knockout - the +3 band nets -4 for the 40 percent chance, the 0-or-lower nets -1 for 10 (folio 7)",
    }, {
      "expr" = "m['brwGrapplePlus4Hi'](0) != 4 or m['brwGrapplePlus4Hi'](10) != 1 or m['brwGrappleZeroLo'](0) != 2 or m['brwGrappleZeroLo'](10) != 0",
      "note" = "the grappling grid corners - G4 at the top of the plus-4 column, G1 at the bottom, G2 to NG across the 0-or-lower (folio 7)",
    }, {
      "expr" = "m['brwPunchPlus3'](0) != -4 or m['brwPunchPlus3'](10) != 0 or m['brwPunchZeroLo'](10) != 0",
      "note" = "the punch grid census - the -4 solid punch tops the plus-3 column, the missed-punch 0s ride the bottom right (folio 7)",
    }, {
      "expr" = "m['brwDexHitPlus'](2) != 3 or m['brwDexAbsorb'](2) != 2 or m['brwDexAbsorb'](0) != 0",
      "note" = "the dexterity ladder - the 18 gives plus 3 to hit and 2 absorbed, the 16 gives plus 1 and none (folio 26)",
    }, {
      "expr" = "m['brwConAbsorbEighteen']() + m['brwDexAbsorb'](2) != 4 or m['brwConAbsorbSeventeen']() + m['brwDexAbsorb'](2) != 3",
      "note" = "the worked match - Little John's con-18 plus dex-18 absorbs 4, Will Scarlet's con-17 plus dex-18 absorbs 3 (folio 27)",
    }, {
      "expr" = "m['brwStageThreeHit']() - m['brwDexHitPlus'](2) != 6",
      "note" = "the rules-text hit floor - the third-stage 9 less the dex-18 plus-3 reads 6; the print's worked example says 7 or more, the discrepancy noted never silent (folios 26-27)",
    }, {
      "expr" = "m['brwChainmailAbsorb']() != 4 or m['brwChainmailHitPenalty']() != 3 or m['brwPlateAbsorb']() != 6 or m['brwPlateHitPenalty']() != 5",
      "note" = "the armor - chainmail absorbs 4 at plus 3 to the roll, plate absorbs 6 at plus 5 (folio 26)",
    }, {
      "expr" = "m['brwAdvanceMatches']() != 50 or m['brwAdvanceWins']() != 30 or m['brwAdvanceDoubleFactor']() != 2",
      "note" = "the stage ladder - 50 matches with 30 wins raise stage one, doubled for stage two to three (folio 26)",
    } },
  "audit" = {
      "label" = "R917 issue-11 opener audit",
      "comment" = "THE DRAGON ISSUE-11 OPENER ROUND - two adjudicated chains. The Kuntz brawling article (folio 7): the first-move dexterity gap, the averaged grapple score rounded down, the eleven-row 2d6 grappling grid G1-G4/NG with the G2 break minimum, the eleven-row punch damage grid -1 light through -4 solid with the missed-punch 0s, the snake-eyes knockout at the netted score times 10 percent, the constitution damage pool with re-comparison each round, the dexterity-multiple extra punches at their per-die penalty. The Ward quarterstaff article (folios 26-27): the three proficiency stages at 12/11/9, the attack-attack / attack-defend / defend-defend option set with simultaneous resolution, the strength, constitution and dexterity ladders, the chainmail and plate absorbs at their hit penalties, the Combat Index down to the out-cold point, the stage advancement ladder and the nine merry men statted for historical simulations. The long-term-effects teaser (the Sorcerer's Scroll column, next issue) harvests at issue 12 if it prints.",
    },
}
