-- sdm: promoted from tools/spec_r938.json (the The Dragon issue-19 opener part two - the Origins 78 tourney and victory-point scoring, the creative treasures and location charts, and the hostile magic-user spell determination: the three-chain round);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 938,
  "prefix" = "sdm",
  "banner" = {
      "title" = "The Dragon issue-19 opener part two - the Origins 78 tourney and victory-point scoring, the creative treasures and location charts, and the hostile magic-user spell determination: the three-chain round",
      "provenance" = "Pinned from The Dragon Vol. III No. 5 (October 1978), the Curtiss-provided scan voice (single voice: the issue-19 source is the uploaded Dm19.pdf with its mistral-ocr transcript; no archive.org djvu cross-check exists for issue 19). PRINT FOLIO = PDF PAGE MINUS TWO, verified at the page feet in the R937 intake (folios 12, 18, 21, 24, 26 and 31 print at the PDF pages 14, 20, 23, 26, 28 and 33); this round pins print 3-4 + 6 (PDF 5-6 + 8), print 13 + 25 (PDF 15 + 27) and print 24-25 (PDF 26-27).",
      "sentinel" = "Print quirks pinned AS SCANNED, noted never silent: the scoring formula prints (G=R=C) x S = VP - the pluses for the sum pinned in the audit comment, the formula kept as printed; the Snurre Hall continuation rides the tail of the Ettins article stamped Smurre with an S; the shrine prints Kuo-Tao while the fight paragraph prints Kuo-Toa; the location chart prints 13-13 for the pot then jumps to 16-17 loose, the d20 bands 14-15 never assigned; the assassin kit dagger prints a plus +2 dagger, the doubled plus; the enchanter spell list trails into a printed ellipsis after the 4 first level and 3 second level counts; the second-level table prints -01-05 for Levitate, the leading dash; Hold Portal and Time Stop carry the asterisk that means dungeons only, reroll for wilderness encounters.",
    },
  "consts" = { {
      "name" = "sdmOriginsPlayers",
      "value" = 275,
      "comment" = "the Origins 78 scale - over 275 players and judges over two days the Origins 78 tourney (print 3, PDF 5)",
    }, {
      "name" = "sdmTeamSize",
      "value" = 9,
      "comment" = "the tournament team size - teams of nine each the Origins 78 tourney (print 3, PDF 5)",
    }, {
      "name" = "sdmTourneyRounds",
      "value" = 3,
      "comment" = "the tournament depth - up to three rounds the Origins 78 tourney (print 3, PDF 5)",
    }, {
      "name" = "sdmDmCountGenconX",
      "value" = 15,
      "comment" = "the GenCon X DM count - fifteen needed the Blake tournament scoring (print 6, PDF 8)",
    }, {
      "name" = "sdmDmCountOrigins78",
      "value" = 16,
      "comment" = "the Origins 78 DM count - sixteen needed (print 6, PDF 8)",
    }, {
      "name" = "sdmDmCountGenconXI",
      "value" = 20,
      "comment" = "the GenCon XI DM count - twenty needed (print 6, PDF 8)",
    }, {
      "name" = "sdmBriefingHours",
      "value" = 4,
      "comment" = "the briefing session length - four hour plus meetings the Blake tournament scoring (print 6, PDF 8)",
    }, {
      "name" = "sdmRoundOneMinutesFloor",
      "value" = 120,
      "comment" = "the first-portion length floor - two hours, pinned 120 minutes the Origins 78 tourney (print 3, PDF 5)",
    }, {
      "name" = "sdmRoundOneMinutesCeil",
      "value" = 150,
      "comment" = "the first-portion length ceiling - two and a half hours, pinned 150 minutes (print 4, PDF 6)",
    }, {
      "name" = "sdmWallFeet",
      "value" = 20,
      "comment" = "the corridor-block marks - the blade barrier and wall of fire centered 20 feet down the west hall (print 4, PDF 6)",
    }, {
      "name" = "sdmHallWidthFeet",
      "value" = 30,
      "comment" = "the hallway width - 30 feet, the party on the invisible dusted rope (print 4, PDF 6)",
    }, {
      "name" = "sdmG1PriceCents",
      "value" = 449,
      "comment" = "the module price - G1 Steading of the Hill Giant Chief at 449 cents (print 4, PDF 6)",
    }, {
      "name" = "sdmG2PriceCents",
      "value" = 449,
      "comment" = "the module price - G2 Glacial Rift of the Frost Giant Jarl at 449 cents (print 4, PDF 6)",
    }, {
      "name" = "sdmG3PriceCents",
      "value" = 498,
      "comment" = "the module price - G3 Hall of the Fire Giant King at 498 cents (print 4, PDF 6)",
    }, {
      "name" = "sdmFormulaTerms",
      "value" = 3,
      "comment" = "the victory-point terms - G giant kills, R rooms, C clues, the survivor S multiplier (print 6, PDF 8)",
    }, {
      "name" = "sdmGenconXRoundTeams",
      "value" = 2,
      "comment" = "the GenCon X first round - two teams competing in the town adventure for the magical key (print 6, PDF 8)",
    }, {
      "name" = "sdmTrapChanceDenominator",
      "value" = 4,
      "comment" = "the trap chance - one in four treasures carries a trap the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmDaggerCountMin",
      "value" = 1,
      "comment" = "the dagger trap floor - 1-8 daggers, 1 in 6 poisoned the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmDaggerCountMax",
      "value" = 8,
      "comment" = "the dagger trap ceiling - 8 daggers the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmTrapPoisonDenominator",
      "value" = 6,
      "comment" = "the trap poison chance - 1 in 6 on daggers and spears the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmArrowCountMax",
      "value" = 6,
      "comment" = "the arrow trap ceiling - 1-6 arrows the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmSpearCountMax",
      "value" = 3,
      "comment" = "the spear trap ceiling - 1-3 spears, 1 in 6 poisoned the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmExplodingDiceMin",
      "value" = 2,
      "comment" = "the exploding chest floor - 2-7 dice of damage the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmExplodingDiceMax",
      "value" = 7,
      "comment" = "the exploding chest ceiling - 7 dice the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasDieCount",
      "value" = 2,
      "comment" = "the gas roll - two dice, the 6-sided first digit and 4-sided second the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasBlindHoursMax",
      "value" = 100,
      "comment" = "the blinding gas - 01-100 hours of blindness the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasFearFightsMin",
      "value" = 2,
      "comment" = "the fear gas floor - fear during the next 2-9 fights the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasFearFightsMax",
      "value" = 9,
      "comment" = "the fear gas ceiling - 9 fights the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasSleepMin",
      "value" = 6,
      "comment" = "the sleep gas floor - 6-36 rounds the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasSleepMax",
      "value" = 36,
      "comment" = "the sleep gas ceiling - 36 rounds the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasAbilityMin",
      "value" = 1,
      "comment" = "the ability-drain gas floor - 1-4 points to a random ability the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasAbilityMax",
      "value" = 4,
      "comment" = "the ability-drain gas ceiling - 4 points the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasAbilityHours",
      "value" = 8,
      "comment" = "the ability-drain gas duration - 8 hours the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasAbilityPermanentDenominator",
      "value" = 10,
      "comment" = "the ability-drain permanence - 1 in 10 permanent the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmSickComaDenominator",
      "value" = 6,
      "comment" = "the sick gas - return to the surface, 1 in 6 in coma the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasAmnesiaMinDays",
      "value" = 1,
      "comment" = "the amnesia gas floor - 1-20 days the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasAmnesiaMaxDays",
      "value" = 20,
      "comment" = "the amnesia gas ceiling - 20 days the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasAmnesiaPermanentDenominator",
      "value" = 6,
      "comment" = "the amnesia permanence - 1 in 6 permanent the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmIntelligentChestMinLevel",
      "value" = 2,
      "comment" = "the intelligent chest floor - a 2nd-7th level magic user the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmIntelligentChestMaxLevel",
      "value" = 7,
      "comment" = "the intelligent chest ceiling - 7th level the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmBouncerFeet",
      "value" = 12,
      "comment" = "the alchemist bar bouncers - 12 feet tall in their hobnail boots the Schroeder creative treasures (print 13, PDF 15)",
    }, {
      "name" = "sdmLocKinds",
      "value" = 8,
      "comment" = "the location-chart kinds - chest, urn, bag, pot, loose, carried, hidden and the referee choice (print 25, PDF 27)",
    }, {
      "name" = "sdmTrapKinds",
      "value" = 13,
      "comment" = "the trap-chart kinds - thirteen from the dagger trap to the roll-twice (print 25, PDF 27)",
    }, {
      "name" = "sdmGasKinds",
      "value" = 16,
      "comment" = "the gas-chart kinds - sixteen outcomes from obscured vision to the berserk attack (print 25, PDF 27)",
    }, {
      "name" = "sdmSpellLevels",
      "value" = 9,
      "comment" = "the determination depth - nine percentile tables, first through ninth level the Miller spell determination (print 24, PDF 26)",
    }, {
      "name" = "sdmDetSpellsTotal",
      "value" = 75,
      "comment" = "the total pinned spell rows - 75 across the nine tables (print 24-25, PDF 26-27)",
    }, {
      "name" = "sdmL1Spells",
      "value" = 7,
      "comment" = "the first-level table count - 7 spells, Hold Portal through Ventriloquism (print 24, PDF 26)",
    }, {
      "name" = "sdmL2Spells",
      "value" = 9,
      "comment" = "the second-level table count - 9 spells, Levitate through Mirror Image (print 24, PDF 26)",
    }, {
      "name" = "sdmL3Spells",
      "value" = 11,
      "comment" = "the third-level table count - 11 spells, Fly through Suggestion (print 24, PDF 26)",
    }, {
      "name" = "sdmL4Spells",
      "value" = 8,
      "comment" = "the fourth-level table count - 8 spells, Polymorph Self through Fear (print 24, PDF 26)",
    }, {
      "name" = "sdmL5Spells",
      "value" = 9,
      "comment" = "the fifth-level table count - 9 spells, Teleport through Growth of Animals (print 24, PDF 26)",
    }, {
      "name" = "sdmL6Spells",
      "value" = 11,
      "comment" = "the sixth-level table count - 11 spells, Stone to Flesh through Monster Summoning IV (print 25, PDF 27)",
    }, {
      "name" = "sdmL7Spells",
      "value" = 7,
      "comment" = "the seventh-level table count - 7 spells, Delayed Blast Fire Ball through Monster Summoning V (print 25, PDF 27)",
    }, {
      "name" = "sdmL8Spells",
      "value" = 5,
      "comment" = "the eighth-level table count - 5 spells, Mass Charm through Monster Summoning VI (print 25, PDF 27)",
    }, {
      "name" = "sdmL9Spells",
      "value" = 8,
      "comment" = "the ninth-level table count - 8 spells, Meteor Swarm through Monster Summoning VII (print 25, PDF 27)",
    }, {
      "name" = "sdmEnchanterSpells",
      "value" = 10,
      "comment" = "the worked example - the enchanter with 10 spells to choose from the Miller spell determination (print 24, PDF 26)",
    }, {
      "name" = "sdmEnchanterL1",
      "value" = 4,
      "comment" = "the worked example - 4 first-level spells the Miller spell determination (print 24, PDF 26)",
    }, {
      "name" = "sdmEnchanterL2",
      "value" = 3,
      "comment" = "the worked example - 3 second-level spells, the remaining levels cut off by the printed ellipsis (print 24, PDF 26)",
    }, {
      "name" = "sdmMethodDieSides",
      "value" = 20,
      "comment" = "the level die in the worked example - the 20-sided roll for the spell level the Miller spell determination (print 24, PDF 26)",
    }, {
      "name" = "sdmConjurerDieSides",
      "value" = 4,
      "comment" = "the conjurer level die - four-sided the Miller spell determination (print 24, PDF 26)",
    }, {
      "name" = "sdmMagicianDieSides",
      "value" = 8,
      "comment" = "the magician level die - eight-sided the Miller spell determination (print 24, PDF 26)",
    } },
  "bools" = { {
      "name" = "sdmSurvivorMultiplied",
      "value" = true,
      "comment" = "the scoring formula - the printed (G=R=C) x S = VP, the terms summed then multiplied by the survivors, pinned as scanned the Blake tournament scoring (print 6, PDF 8)",
    }, {
      "name" = "sdmRoomClueEqualGiant",
      "value" = true,
      "comment" = "the point weighting - the total room value plus the total clue value equals the total giant value available in the module (print 6, PDF 8)",
    }, {
      "name" = "sdmDoOrDieDesirable",
      "value" = true,
      "comment" = "the do-or-dont situation - one of the easiest and most desirable scoring means the Blake tournament scoring (print 6, PDF 8)",
    }, {
      "name" = "sdmSubjectivityLeastDesirable",
      "value" = true,
      "comment" = "the subjective DM-vote assessment is the least desirable means the Blake tournament scoring (print 6, PDF 8)",
    }, {
      "name" = "sdmObjectivityBetterAloneInadequate",
      "value" = true,
      "comment" = "strict point objectivity is better but still inadequate alone - it may warp the design intent the Blake tournament scoring (print 6, PDF 8)",
    }, {
      "name" = "sdmCombinationBest",
      "value" = true,
      "comment" = "the best approach is the combination of subjectivity and objectivity the Blake tournament scoring (print 6, PDF 8)",
    }, {
      "name" = "sdmSuperiorMethodGreaterReward",
      "value" = true,
      "comment" = "a super clever team may find a far superior method and deserve a greater reward the Blake tournament scoring (print 6, PDF 8)",
    }, {
      "name" = "sdmGenconXDoOrDie",
      "value" = true,
      "comment" = "GenCon X ran the do-or-dont - the tower skull, the wilderness trap, one team close to defusing it (print 6, PDF 8)",
    }, {
      "name" = "sdmSkullPiecesFudged",
      "value" = true,
      "comment" = "the GenCon X skull - pieces to be assembled, few teams got them all, some fudging done (print 6, PDF 8)",
    }, {
      "name" = "sdmGenconXISurvivorMultiplier",
      "value" = true,
      "comment" = "the GenCon XI survivor multiplier - casualties counted as slain or captured for sacrifice (print 6, PDF 8)",
    }, {
      "name" = "sdmGenconXIDemonWipe",
      "value" = true,
      "comment" = "the GenCon XI round two - every team but one died to the demon encounter, one casualty survived (print 6, PDF 8)",
    }, {
      "name" = "sdmGenconXIBye",
      "value" = true,
      "comment" = "the GenCon XI winners took a bye in the third round, second and third slots left to fill (print 6, PDF 8)",
    }, {
      "name" = "sdmSubjectiveNeverAgain",
      "value" = true,
      "comment" = "the post-GenCon XI vow - never use the subjective DM-meeting approach again if at all possible (print 6, PDF 8)",
    }, {
      "name" = "sdmBriefingSessionsMust",
      "value" = true,
      "comment" = "DM briefing sessions are a must - the designer intent must be clear to all the Blake tournament scoring (print 6, PDF 8)",
    }, {
      "name" = "sdmStandardRulesSheet",
      "value" = true,
      "comment" = "a short standard-rules compilation for every DM - movement, turn order, scenario modifications the Blake tournament scoring (print 6, PDF 8)",
    }, {
      "name" = "sdmBattleOfTriangular",
      "value" = true,
      "comment" = "the Battle of the Triangular - the two fire giant guards at the T intersection, the alarm, the chimera (print 4, PDF 6)",
    }, {
      "name" = "sdmObmiBetrayal",
      "value" = true,
      "comment" = "Obmi the rescued dwarf - the ballista and the water and flour traced back to him, never trusted (print 4, PDF 6)",
    }, {
      "name" = "sdmHasteTurningPoint",
      "value" = true,
      "comment" = "the DM verdict - the haste spell the real turning point of the battle, all ten on their feet (print 4, PDF 6)",
    }, {
      "name" = "sdmKingOnlyPretending",
      "value" = true,
      "comment" = "King Snurre was not really dead, only pretending - the severed head confirmed the apparent death (print 4, PDF 6)",
    }, {
      "name" = "sdmHeadInBagHolding",
      "value" = true,
      "comment" = "the thief cut the head off and placed it in his bag of holding - a regular part of any coup they staged (print 4, PDF 6)",
    }, {
      "name" = "sdmSmurreContTypo",
      "value" = true,
      "comment" = "the print catch - the Snurre Hall continuation rides the tail of the Ettins article stamped Smurre with an S, pinned as scanned (print 6, PDF 8)",
    }, {
      "name" = "sdmGenconXIShrinePassage",
      "value" = true,
      "comment" = "the GenCon XI Shrine of the Kuo-Tao - one way through unscathed worth considerable points, fights otherwise (print 6, PDF 8)",
    }, {
      "name" = "sdmKuoSpellingCrossed",
      "value" = true,
      "comment" = "the print catch - the shrine prints Kuo-Tao while the fight paragraph prints Kuo-Toa, pinned as scanned (print 6, PDF 8)",
    }, {
      "name" = "sdmChooseThemeFirst",
      "value" = true,
      "comment" = "the creative-treasure doctrine - first of all choose a theme the Schroeder creative treasures (print 13, PDF 15)",
    }, {
      "name" = "sdmItemConnections",
      "value" = true,
      "comment" = "the item-connection doctrine - a connection between the treasure contents and their guardian the Schroeder creative treasures (print 13, PDF 15)",
    }, {
      "name" = "sdmFirstAidKitDoctrine",
      "value" = true,
      "comment" = "the first aid kit - healing potion, smelling salts, the poison bottle, the oil of slipperiness, the scrolls the Schroeder creative treasures (print 13, PDF 15)",
    }, {
      "name" = "sdmThiefToolkitDoctrine",
      "value" = true,
      "comment" = "the thief toolkit - plus 1 dagger, trap-glowing gem, gauntlets, skeleton key, waldos, periscope, bag of holding the Schroeder creative treasures (print 13, PDF 15)",
    }, {
      "name" = "sdmDisguiseKitDoctrine",
      "value" = true,
      "comment" = "the assassin disguise kit - polymorph potions, the plus +2 dagger, poisons, wigs, the girdle, the scareb the Schroeder creative treasures (print 13, PDF 15)",
    }, {
      "name" = "sdmAssassinDaggerPlusTwo",
      "value" = true,
      "comment" = "the print catch - the assassin kit dagger prints a plus +2 dagger, the doubled plus pinned as scanned the Schroeder creative treasures (print 13, PDF 15)",
    }, {
      "name" = "sdmYouthPotionBishop",
      "value" = true,
      "comment" = "the paranoid high-level example - the bishop with dozens of bottles of youth potion the Schroeder creative treasures (print 13, PDF 15)",
    }, {
      "name" = "sdmDetectionGemNecklace",
      "value" = true,
      "comment" = "the paranoid magic-user - the necklace of detection gems, detect magic, evil, good, weres, gold, doors, invisible the Schroeder creative treasures (print 13, PDF 15)",
    }, {
      "name" = "sdmMonsterSizeAttention",
      "value" = true,
      "comment" = "the monster-in-chest trap - pay attention to the monster size the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmTrapRollTwice",
      "value" = true,
      "comment" = "the trap chart 00 - roll twice the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmLocBandsGap",
      "value" = true,
      "comment" = "the print catch - the location chart prints 13-13 for the pot then 16-17 loose, the bands 14-15 never assigned, pinned as scanned the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmGasD64Method",
      "value" = true,
      "comment" = "the gas-roll method - the 6-sided die for the first digit and the 4-sided for the second the Guritzky treasure charts (print 25, PDF 27)",
    }, {
      "name" = "sdmRerollAllowed",
      "value" = true,
      "comment" = "the reroll rule - insufficient range, a dungeon spell in a wilderness encounter or the obviously inappropriate allows a reroll the Miller spell determination (print 24, PDF 26)",
    }, {
      "name" = "sdmAsteriskDungeonRerull",
      "value" = true,
      "comment" = "the footnote pair - the range reroll note and the asterisk dungeons-only reroll for wilderness, Hold Portal and Time Stop carrying the asterisk (print 24-25, PDF 26-27)",
    }, {
      "name" = "sdmInappropriateReroll",
      "value" = true,
      "comment" = "the obviously inappropriate example - throwing feeblemind on a fighter the Miller spell determination (print 24, PDF 26)",
    }, {
      "name" = "sdmChartsModifiable",
      "value" = true,
      "comment" = "the charts can be modified to suit individual campaigns the Miller spell determination (print 24, PDF 26)",
    }, {
      "name" = "sdmHasteInvisLevitateOpening",
      "value" = true,
      "comment" = "the doctrine example - one wizard hasted himself and his henchmen, invisible, levitated, then opened up (print 24, PDF 26)",
    }, {
      "name" = "sdmProtectionThenSleep",
      "value" = true,
      "comment" = "the bowman response - protection from normal missiles on himself, sleep on the archers (print 24, PDF 26)",
    }, {
      "name" = "sdmLowerLevelPreferred",
      "value" = true,
      "comment" = "the doctrine - hostile MUs spend plentiful lower-level spells instead of blowing groups away with the big three immediately (print 24, PDF 26)",
    }, {
      "name" = "sdmL2LeadingDash",
      "value" = true,
      "comment" = "the print catch - the second-level table prints -01-05 for Levitate, the leading dash pinned as scanned (print 24, PDF 26)",
    }, {
      "name" = "sdmEnchanterEllipsis",
      "value" = true,
      "comment" = "the print catch - the enchanter spell list prints 4 first level and 3 second level then trails into a printed ellipsis, pinned as scanned (print 24, PDF 26)",
    }, {
      "name" = "sdmLightningBoltOpening",
      "value" = true,
      "comment" = "the re-done encounter - the enchanter opens with a lightning bolt and disposes of one of the magic users (print 24, PDF 26)",
    }, {
      "name" = "sdmMagicMissileCleric",
      "value" = true,
      "comment" = "the re-done encounter - a magic missile stabs out and scratches one cleric (print 24, PDF 26)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "sdmLoc",
      "tag" = "Lc",
      "sentinel" = 0,
      "count" = "sdmLocKinds",
      "audit_comment" = "the treasure location grid - eight kinds down, the d20 band across, chest 1-6, urn 7-9, bag 10-12, pot 13, loose 16-17, carried 18, hidden 19, referee choice 20; the bands 14-15 never assigned, pinned as scanned (print 25, PDF 27)",
      "cols" = { "sdmLocLow", "sdmLocHigh" },
      "col_comments" = { "the location band lows - 1, 7, 10, 13, 16, 18, 19 and 20, the pot a lone 13 with the 14-15 gap (print 25, PDF 27)", "the location band highs - 6, 9, 12, 13, 17, 18, 19 and 20 (print 25, PDF 27)" },
      "data" = { { 1, 6 }, { 7, 9 }, { 10, 12 }, { 13, 13 }, { 16, 17 }, { 18, 18 }, { 19, 19 }, { 20, 20 } },
    }, {
      "name" = "sdmTrap",
      "tag" = "Tr",
      "sentinel" = 0,
      "count" = "sdmTrapKinds",
      "audit_comment" = "the trap grid - thirteen kinds down, the percentile band across, the dagger 01-20, arrow 21-36, spear 37-46, gas 47-62, poison lock 63-78, monster 79-88, exploding chest 89-92, chest spell 93-95, mirror of life trapping 96, intelligent chest 97, level loss 98, item loss 99 and roll twice 100 (print 25, PDF 27)",
      "cols" = { "sdmTrapLow", "sdmTrapHigh" },
      "col_comments" = { "the trap band lows - 01 through 96 with the singleton traps at 96, 97, 98, 99 and 100 (print 25, PDF 27)", "the trap band highs - the dagger 20 through the roll-twice 100, the contiguous run (print 25, PDF 27)" },
      "data" = { { 1, 20 }, { 21, 36 }, { 37, 46 }, { 47, 62 }, { 63, 78 }, { 79, 88 }, { 89, 92 }, { 93, 95 }, { 96, 96 }, { 97, 97 }, { 98, 98 }, { 99, 99 }, { 100, 100 } },
    }, {
      "name" = "sdmGas",
      "tag" = "Gs",
      "sentinel" = 0,
      "count" = "sdmGasKinds",
      "audit_comment" = "the gas grid - sixteen outcomes down, the d6-by-d4 band across, obscured vision 11-12, blind 13-14, fear 21-22, sleep 23-24, ability drain 31, sick 32-33, paralysis 34, stone 41, death 42, polymorph 43, amnesia 44, alignment change 51-52, slow 53-54, haste 61-62, cloud kill 63 and berserk 64 (print 25, PDF 27)",
      "cols" = { "sdmGasLow", "sdmGasHigh" },
      "col_comments" = { "the gas band lows - 11, 13, 21, 23, 31, 32, 34, 41, 42, 43, 44, 51, 53, 61, 63, 64 (print 25, PDF 27)", "the gas band highs - 12, 14, 22, 24, 31, 33, 34, 41, 42, 43, 44, 52, 54, 62, 63, 64 (print 25, PDF 27)" },
      "data" = { { 11, 12 }, { 13, 14 }, { 21, 22 }, { 23, 24 }, { 31, 31 }, { 32, 33 }, { 34, 34 }, { 41, 41 }, { 42, 42 }, { 43, 43 }, { 44, 44 }, { 51, 52 }, { 53, 54 }, { 61, 62 }, { 63, 63 }, { 64, 64 } },
    }, {
      "name" = "sdmDet1",
      "tag" = "S1",
      "sentinel" = 0,
      "count" = "sdmL1Spells",
      "audit_comment" = "the level-1 determination grid - the percentile bands contiguous from 01 to 100 (print 24, PDF 26-27)",
      "cols" = { "sdmL1Low", "sdmL1High" },
      "col_comments" = { "the level-1 band lows - row one opens at 01 (print 24, PDF 26)", "the level-1 band highs - the last row closes at 100 (print 24, PDF 26)" },
      "data" = { { 1, 5 }, { 6, 10 }, { 11, 30 }, { 31, 55 }, { 56, 75 }, { 76, 95 }, { 96, 100 } },
    }, {
      "name" = "sdmDet2",
      "tag" = "S2",
      "sentinel" = 0,
      "count" = "sdmL2Spells",
      "audit_comment" = "the level-2 determination grid - the percentile bands contiguous from 01 to 100 (print 24, PDF 26-27)",
      "cols" = { "sdmL2Low", "sdmL2High" },
      "col_comments" = { "the level-2 band lows - row one opens at 01 (print 24, PDF 26)", "the level-2 band highs - the last row closes at 100 (print 24, PDF 26)" },
      "data" = { { 1, 5 }, { 6, 10 }, { 11, 30 }, { 31, 40 }, { 41, 50 }, { 51, 65 }, { 66, 70 }, { 71, 90 }, { 91, 100 } },
    }, {
      "name" = "sdmDet3",
      "tag" = "S3",
      "sentinel" = 0,
      "count" = "sdmL3Spells",
      "audit_comment" = "the level-3 determination grid - the percentile bands contiguous from 01 to 100 (print 24, PDF 26-27)",
      "cols" = { "sdmL3Low", "sdmL3High" },
      "col_comments" = { "the level-3 band lows - row one opens at 01 (print 24, PDF 26)", "the level-3 band highs - the last row closes at 100 (print 24, PDF 26)" },
      "data" = { { 1, 5 }, { 6, 15 }, { 16, 20 }, { 21, 40 }, { 41, 50 }, { 51, 55 }, { 56, 60 }, { 61, 75 }, { 76, 80 }, { 81, 90 }, { 91, 100 } },
    }, {
      "name" = "sdmDet4",
      "tag" = "S4",
      "sentinel" = 0,
      "count" = "sdmL4Spells",
      "audit_comment" = "the level-4 determination grid - the percentile bands contiguous from 01 to 100 (print 24, PDF 26-27)",
      "cols" = { "sdmL4Low", "sdmL4High" },
      "col_comments" = { "the level-4 band lows - row one opens at 01 (print 24, PDF 26)", "the level-4 band highs - the last row closes at 100 (print 24, PDF 26)" },
      "data" = { { 1, 10 }, { 11, 20 }, { 21, 25 }, { 26, 30 }, { 31, 40 }, { 41, 50 }, { 51, 70 }, { 71, 100 } },
    }, {
      "name" = "sdmDet5",
      "tag" = "S5",
      "sentinel" = 0,
      "count" = "sdmL5Spells",
      "audit_comment" = "the level-5 determination grid - the percentile bands contiguous from 01 to 100 (print 24, PDF 26-27)",
      "cols" = { "sdmL5Low", "sdmL5High" },
      "col_comments" = { "the level-5 band lows - row one opens at 01 (print 24, PDF 26)", "the level-5 band highs - the last row closes at 100 (print 24, PDF 26)" },
      "data" = { { 1, 5 }, { 6, 25 }, { 26, 35 }, { 36, 45 }, { 46, 55 }, { 56, 60 }, { 61, 85 }, { 86, 95 }, { 96, 100 } },
    }, {
      "name" = "sdmDet6",
      "tag" = "S6",
      "sentinel" = 0,
      "count" = "sdmL6Spells",
      "audit_comment" = "the level-6 determination grid - the percentile bands contiguous from 01 to 100 (print 25, PDF 26-27)",
      "cols" = { "sdmL6Low", "sdmL6High" },
      "col_comments" = { "the level-6 band lows - row one opens at 01 (print 25, PDF 27)", "the level-6 band highs - the last row closes at 100 (print 25, PDF 27)" },
      "data" = { { 1, 5 }, { 6, 25 }, { 26, 35 }, { 36, 40 }, { 41, 60 }, { 61, 65 }, { 66, 75 }, { 76, 80 }, { 81, 85 }, { 86, 95 }, { 96, 100 } },
    }, {
      "name" = "sdmDet7",
      "tag" = "S7",
      "sentinel" = 0,
      "count" = "sdmL7Spells",
      "audit_comment" = "the level-7 determination grid - the percentile bands contiguous from 01 to 100 (print 25, PDF 26-27)",
      "cols" = { "sdmL7Low", "sdmL7High" },
      "col_comments" = { "the level-7 band lows - row one opens at 01 (print 25, PDF 27)", "the level-7 band highs - the last row closes at 100 (print 25, PDF 27)" },
      "data" = { { 1, 10 }, { 11, 30 }, { 31, 55 }, { 56, 75 }, { 76, 80 }, { 81, 90 }, { 91, 100 } },
    }, {
      "name" = "sdmDet8",
      "tag" = "S8",
      "sentinel" = 0,
      "count" = "sdmL8Spells",
      "audit_comment" = "the level-8 determination grid - the percentile bands contiguous from 01 to 100 (print 25, PDF 26-27)",
      "cols" = { "sdmL8Low", "sdmL8High" },
      "col_comments" = { "the level-8 band lows - row one opens at 01 (print 25, PDF 27)", "the level-8 band highs - the last row closes at 100 (print 25, PDF 27)" },
      "data" = { { 1, 35 }, { 36, 55 }, { 56, 60 }, { 61, 90 }, { 91, 100 } },
    }, {
      "name" = "sdmDet9",
      "tag" = "S9",
      "sentinel" = 0,
      "count" = "sdmL9Spells",
      "audit_comment" = "the level-9 determination grid - the percentile bands contiguous from 01 to 100 (print 25, PDF 26-27)",
      "cols" = { "sdmL9Low", "sdmL9High" },
      "col_comments" = { "the level-9 band lows - row one opens at 01 (print 25, PDF 27)", "the level-9 band highs - the last row closes at 100 (print 25, PDF 27)" },
      "data" = { { 1, 30 }, { 31, 45 }, { 46, 50 }, { 51, 70 }, { 71, 75 }, { 76, 85 }, { 86, 95 }, { 96, 100 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['sdmOriginsPlayers']() != 275 or m['sdmTeamSize']() != 9 or m['sdmTourneyRounds']() != 3 or m['sdmDmCountGenconX']() != 15 or m['sdmDmCountOrigins78']() != 16 or m['sdmDmCountGenconXI']() != 20 or m['sdmBriefingHours']() != 4 or m['sdmGenconXRoundTeams']() != 2",
      "note" = "the tourney census - 275 players and judges, teams of nine, three rounds, the DM counts 15, 16 and 20, the four-hour briefing, the two-team GenCon X town round (print 3 + 6, PDF 5 + 8)",
    }, {
      "expr" = "m['sdmRoundOneMinutesFloor']() != 120 or m['sdmRoundOneMinutesCeil']() != 150 or m['sdmWallFeet']() != 20 or m['sdmHallWidthFeet']() != 30 or m['sdmG1PriceCents']() != 449 or m['sdmG2PriceCents']() != 449 or m['sdmG3PriceCents']() != 498",
      "note" = "the Snurre Hall numbers - the two-to-two-and-a-half-hour first portion, the 20-foot block marks, the 30-foot hall, the module prices 449, 449 and 498 cents (print 4, PDF 6)",
    }, {
      "expr" = "m['sdmSurvivorMultiplied']() != 1 or m['sdmFormulaTerms']() != 3 or m['sdmRoomClueEqualGiant']() != 1 or m['sdmDoOrDieDesirable']() != 1 or m['sdmSubjectivityLeastDesirable']() != 1 or m['sdmObjectivityBetterAloneInadequate']() != 1 or m['sdmCombinationBest']() != 1 or m['sdmSuperiorMethodGreaterReward']() != 1",
      "note" = "the scoring doctrine - the three-term survivor-multiplied formula, the room-plus-clue-equals-giant weighting, the desirability ladder from do-or-dont through subjectivity and objectivity to the combination (print 6, PDF 8)",
    }, {
      "expr" = "m['sdmTrapChanceDenominator']() != 4 or m['sdmDaggerCountMin']() != 1 or m['sdmDaggerCountMax']() != 8 or m['sdmTrapPoisonDenominator']() != 6 or m['sdmArrowCountMax']() != 6 or m['sdmSpearCountMax']() != 3 or m['sdmExplodingDiceMin']() != 2 or m['sdmExplodingDiceMax']() != 7 or m['sdmIntelligentChestMinLevel']() != 2 or m['sdmIntelligentChestMaxLevel']() != 7",
      "note" = "the trap doctrine - the one-in-four chance, 1-8 daggers and 1-6 arrows and 1-3 spears at 1 in 6 poison, the 2-7-dice exploding chest, the 2nd-7th-level intelligent chest (print 25, PDF 27)",
    }, {
      "expr" = "m['sdmGasDieCount']() != 2 or m['sdmGasBlindHoursMax']() != 100 or m['sdmGasFearFightsMin']() != 2 or m['sdmGasFearFightsMax']() != 9 or m['sdmGasSleepMin']() != 6 or m['sdmGasSleepMax']() != 36 or m['sdmGasAbilityMin']() != 1 or m['sdmGasAbilityMax']() != 4 or m['sdmGasAbilityHours']() != 8 or m['sdmGasAbilityPermanentDenominator']() != 10",
      "note" = "the gas doctrine - the d6-and-d4 roll, the 01-100-hour blindness, the 2-9-fight fear, the 6-36-round sleep, the 1-4-point eight-hour ability drain at 1 in 10 permanent (print 25, PDF 27)",
    }, {
      "expr" = "m['sdmGasAmnesiaMinDays']() != 1 or m['sdmGasAmnesiaMaxDays']() != 20 or m['sdmGasAmnesiaPermanentDenominator']() != 6 or m['sdmSickComaDenominator']() != 6 or m['sdmGasD64Method']() != 1 or m['sdmTrapRollTwice']() != 1 or m['sdmLocBandsGap']() != 1",
      "note" = "the gas tail and print catches - the 1-20-day amnesia at 1 in 6 permanent, the sick 1-in-6 coma, the d6-d4 method, the roll-twice 00, the unassigned 14-15 location bands (print 25, PDF 27)",
    }, {
      "expr" = "m['sdmSpellLevels']() != 9 or m['sdmDetSpellsTotal']() != 75 or m['sdmL1Spells']() != 7 or m['sdmL2Spells']() != 9 or m['sdmL3Spells']() != 11 or m['sdmL4Spells']() != 8 or m['sdmL5Spells']() != 9 or m['sdmL6Spells']() != 11 or m['sdmL7Spells']() != 7 or m['sdmL8Spells']() != 5 or m['sdmL9Spells']() != 8",
      "note" = "the determination census - nine tables, 75 rows, the per-level counts 7, 9, 11, 8, 9, 11, 7, 5 and 8 (print 24-25, PDF 26-27)",
    }, {
      "expr" = "m['sdmEnchanterSpells']() != 10 or m['sdmEnchanterL1']() != 4 or m['sdmEnchanterL2']() != 3 or m['sdmMethodDieSides']() != 20 or m['sdmConjurerDieSides']() != 4 or m['sdmMagicianDieSides']() != 8 or m['sdmEnchanterEllipsis']() != 1 or m['sdmL2LeadingDash']() != 1",
      "note" = "the method - the 10-spell enchanter, the 4/3 printed counts with the trailing ellipsis, the d20 level die, the conjurer d4 and magician d8, the -01-05 leading dash (print 24, PDF 26)",
    }, {
      "expr" = "m['sdmRerollAllowed']() != 1 or m['sdmAsteriskDungeonRerull']() != 1 or m['sdmInappropriateReroll']() != 1 or m['sdmChartsModifiable']() != 1 or m['sdmHasteInvisLevitateOpening']() != 1 or m['sdmProtectionThenSleep']() != 1 or m['sdmLowerLevelPreferred']() != 1 or m['sdmLightningBoltOpening']() != 1 or m['sdmMagicMissileCleric']() != 1",
      "note" = "the determination doctrine - the reroll family with the feeblemind-on-a-fighter example, the modifiable charts, the haste-invisibility-levitate opening, the lightning bolt and magic missile redo (print 24, PDF 26)",
    }, {
      "expr" = "m['sdmChooseThemeFirst']() != 1 or m['sdmItemConnections']() != 1 or m['sdmFirstAidKitDoctrine']() != 1 or m['sdmThiefToolkitDoctrine']() != 1 or m['sdmDisguiseKitDoctrine']() != 1 or m['sdmAssassinDaggerPlusTwo']() != 1 or m['sdmYouthPotionBishop']() != 1 or m['sdmDetectionGemNecklace']() != 1 or m['sdmBouncerFeet']() != 12",
      "note" = "the creative-treasure doctrine - the theme first, the connections, the three kits, the doubled-plus print catch, the youth-potion bishop, the detection necklace and the 12-foot bouncers (print 13, PDF 15)",
    } },
  "audit" = {
      "label" = "R938 issue-19 opener part two audit",
      "comment" = "THE DRAGON ISSUE-19 OPENER PART TWO - the three table-and-doctrine chains of the issue. CHAIN ONE, the Origins 78 tournament synopsis by Bryan and Kathy Bullinger with the Blake competitive D&D scoring (print 3-4 + 6, PDF 5-6 + 8): the Battle for Snurre Hall walk - the triangular alcove, Obmi the treacherous rescued dwarf, the blade barrier and wall of fire blocks, the haste turning point, the king only pretending and the head in the bag of holding; the Blake victory-point doctrine - the G, R, C terms times the survivor S, the room-plus-clue-equals-giant weighting, the subjectivity-objectivity-combination ladder, the GenCon X and GenCon XI stories and the DM consistency doctrine. CHAIN TWO, Planning Creative Treasures by Dave Schroeder (print 13, PDF 15) and the Charts for Determining the Location of Treasure by Ronald Guritzky (print 25, PDF 27): the sdmLoc, sdmTrap and sdmGas grids - the d20 location chart with the unassigned 14-15 bands, the thirteen-kind percentile trap chart, the sixteen-outcome d6-by-d4 gas chart; the kit and theme doctrine. CHAIN THREE, Spell Determination for Hostile Magic Users by Steve Miller (print 24-25, PDF 26-27): the die-for-level method - the worked 10-spell enchanter with the d20, the conjurer d4, the magician d8 - and the nine contiguous percentile grids sdmDet1 through sdmDet9, 75 rows from Hold Portal through Monster Summoning VII with the reroll doctrine.",
    },
}
