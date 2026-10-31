-- dso: promoted from tools/spec_r906.json (the The Dragon issue-6 opener - the Sea Trade system (folio 6), the psionic determination option (folio 25), the morale system (folios 26-27) and the Death Angel (folio 29): four adjudicated engine-relevant chains in one round);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 906,
  "prefix" = "dso",
  "banner" = {
      "title" = "The Dragon issue-6 opener - the Sea Trade system (folio 6), the psionic determination option (folio 25), the morale system (folios 26-27) and the Death Angel (folio 29): four adjudicated engine-relevant chains in one round",
      "provenance" = "Pinned from The Dragon Vol. 1 No. 6 (April 1977), the archive.org scan voice (single-voice: no chat-side upload cross-check exists for issue 6). The folios: 6, the Sea Trade in D&D Campaigns by Ronald C. Spencer, Jr. - the Bardukian coastal trade, the cargo capacities and pilot fees, the 5 percent import tax and the sixteen-band profit/loss grid with the ship-lost X sentinel; 25, the D&D Option: Determination of Psionic Abilities by David W. Miller - the human 91 and half-human 95 percentile gates, the thirty-seven abilities and the three learning ladders against the Eldritch Wizardry base; 26-27, the Morale in D&D system by Jim Hayes and Bill Gilbert - the 3d6 bravery/charisma/loyalty modifier ladder, the level and loss adjustments and the eleven-chart by ten-die outcome grid; 29, the Featured Creature: Death Angel by John Sullivan - the oracle of death on a single-victim mission. The transcripts ride extract/dragon/006/ (all 32 issue pages); the issue-6 gap report ships pre-flip. PRINT FOLIO = PDF PAGE, verified at the printed 6, 26 and 29 footers.",
      "sentinel" = "The variant-layer doctrine holds: Dragon ink is never core 1e canon. The sea trade, psionic and morale systems pin as variant layers with provenance; the Death Angel, with no 1e def existing, pins as a NEW registry monster with the R900 Creature Features precedent and carries the dragon_print xp source in its lua. The XP conversion rides the DMG p.85 additive formula - 225 base + 2 x 175 specials + 275 exceptional at the 6+1 to 7 dice category, plus 8 per hit point at the floored 31 average - noted, never silent. The profit/loss grid's garbled 10 cell rides AS SCANNED, and the folio-25 '1%' weeks per level reads as 1 1/2, pinned as 15 tenths - both garbles noted, never silent. The editor's standing caution rides: none of this is official.",
    },
  "consts" = { {
      "name" = "dsoSeaCargoSmallGp",
      "value" = 10000,
      "comment" = "the small merchant cargo capacity in gold - 10,000 G.P. (folio 6)",
    }, {
      "name" = "dsoSeaCargoLargeGp",
      "value" = 50000,
      "comment" = "the large merchant cargo capacity in gold - 50,000 G.P. (folio 6)",
    }, {
      "name" = "dsoSeaPilotFeeSmall",
      "value" = 500,
      "comment" = "the pilot fee at every port but the home port, the small merchant - 500 G.P. (folio 6)",
    }, {
      "name" = "dsoSeaPilotFeeLarge",
      "value" = 2500,
      "comment" = "the pilot fee at every port but the home port, the large merchant - 2,500 G.P. (folio 6)",
    }, {
      "name" = "dsoSeaImportTaxPct",
      "value" = 5,
      "comment" = "the import tax every country levies on the sale value in the receiving port - 5 percent (folio 6)",
    }, {
      "name" = "dsoSeaPortsOnCoast",
      "value" = 9,
      "comment" = "the ports along the Bardukian coast - nine (folio 6)",
    }, {
      "name" = "dsoSeaRouteMiles",
      "value" = 2500,
      "comment" = "the distance between the northernmost and southernmost port - about 2,500 miles (folio 6)",
    }, {
      "name" = "dsoSeaCoastalMilesMax",
      "value" = 50,
      "comment" = "the coastal-trade limit - ships rarely venture more than fifty miles from land (folio 6)",
    }, {
      "name" = "dsoSeaDelayWeeksMin",
      "value" = 1,
      "comment" = "the delay at each port other than home - 1-4 weeks, the minimum (folio 6)",
    }, {
      "name" = "dsoSeaDelayWeeksMax",
      "value" = 4,
      "comment" = "the delay at each port other than home - 1-4 weeks, the maximum (folio 6)",
    }, {
      "name" = "dsoSeaLossNoticeWeeksMin",
      "value" = 3,
      "comment" = "the owner learns of a lost ship 3-8 weeks later - the minimum (folio 6)",
    }, {
      "name" = "dsoSeaLossNoticeWeeksMax",
      "value" = 8,
      "comment" = "the owner learns of a lost ship 3-8 weeks later - the maximum (folio 6)",
    }, {
      "name" = "dsoSeaProfitLossCount",
      "value" = 16,
      "comment" = "the dsoSeaProfitLoss table runs 16 rows - the percentile bands of the profit/loss table (folio 6)",
    }, {
      "name" = "dsoPsiHumanRollMin",
      "value" = 91,
      "comment" = "humans require a percentile roll of 91 or better for psionic potential (folio 25)",
    }, {
      "name" = "dsoPsiHalfHumanRollMin",
      "value" = 95,
      "comment" = "half-humans require a percentile roll of 95 or better for psionic potential (folio 25)",
    }, {
      "name" = "dsoPsiAbilitiesCount",
      "value" = 37,
      "comment" = "any character can have any of the thirty-seven known psionic abilities (folio 25)",
    }, {
      "name" = "dsoPsiBasicWeeksPerLevel",
      "value" = 1,
      "comment" = "learning a new basic ability takes one week per level of difficulty (folio 25)",
    }, {
      "name" = "dsoPsiSuperiorWeeksTenths",
      "value" = 15,
      "comment" = "the superior abilities take the print's garbled '1%' weeks per level - read as 1 1/2, pinned as 15 tenths, the garble noted (folio 25)",
    }, {
      "name" = "dsoPsiAttackDefenseWeeks",
      "value" = 9,
      "comment" = "the attack and defense modes take nine weeks each to learn (folio 25)",
    }, {
      "name" = "dsoMorBrave3",
      "value" = -4,
      "comment" = "the personal bravery modifier at a 3 on 3d6 (folio 27)",
    }, {
      "name" = "dsoMorBrave4",
      "value" = -3,
      "comment" = "the personal bravery modifier at a 4 on 3d6 (folio 27)",
    }, {
      "name" = "dsoMorBrave56",
      "value" = -2,
      "comment" = "the personal bravery modifier at a 5 or 6 on 3d6 (folio 27)",
    }, {
      "name" = "dsoMorBrave78",
      "value" = -1,
      "comment" = "the personal bravery modifier at a 7 or 8 on 3d6 (folio 27)",
    }, {
      "name" = "dsoMorBrave912",
      "value" = 0,
      "comment" = "the personal bravery modifier at a 9-12 on 3d6 (folio 27)",
    }, {
      "name" = "dsoMorBrave1314",
      "value" = 1,
      "comment" = "the personal bravery modifier at a 13 or 14 on 3d6 (folio 27)",
    }, {
      "name" = "dsoMorBrave1516",
      "value" = 2,
      "comment" = "the personal bravery modifier at a 15 or 16 on 3d6 (folio 27)",
    }, {
      "name" = "dsoMorBrave17",
      "value" = 3,
      "comment" = "the personal bravery modifier at a 17 on 3d6 (folio 27)",
    }, {
      "name" = "dsoMorBrave18",
      "value" = 4,
      "comment" = "the personal bravery modifier at an 18 on 3d6 (folio 27)",
    }, {
      "name" = "dsoMorBrave19",
      "value" = 5,
      "comment" = "the bravery-table modifier at a 19 or more - the print's exceptional tail (folio 27)",
    }, {
      "name" = "dsoMorLvl34",
      "value" = 1,
      "comment" = "each fighter, MU or cleric of level 3-4 adds +1 to the chart number (folio 27)",
    }, {
      "name" = "dsoMorLvl56",
      "value" = 2,
      "comment" = "each fighter, MU or cleric of level 5-6 adds +2 to the chart number (folio 27)",
    }, {
      "name" = "dsoMorLvl78",
      "value" = 3,
      "comment" = "each fighter, MU or cleric of level 7-8 adds +3 to the chart number (folio 27)",
    }, {
      "name" = "dsoMorAdjComradeBreaks",
      "value" = -1,
      "comment" = "each comrade that breaks, is disabled or killed adjusts the recheck by -1 (folio 27)",
    }, {
      "name" = "dsoMorAdjMuClericBreaks",
      "value" = -2,
      "comment" = "each MU or cleric that breaks, is disabled or killed adjusts the recheck by -2 (folio 27)",
    }, {
      "name" = "dsoMorAdjLeaderBreaks",
      "value" = -4,
      "comment" = "if the leader breaks, is disabled or killed the recheck adjusts by -4 (folio 27)",
    }, {
      "name" = "dsoMorAdjEnemyLeader",
      "value" = 4,
      "comment" = "if an enemy leader breaks, is disabled or killed the recheck adjusts by +4 (folio 27)",
    }, {
      "name" = "dsoMorAdjEnemyMuCleric",
      "value" = 2,
      "comment" = "each enemy MU or cleric that breaks, is disabled or killed adjusts the recheck by +2 (folio 27)",
    }, {
      "name" = "dsoMorAdjEnemyFighter",
      "value" = 1,
      "comment" = "every enemy fighter that breaks, is disabled or killed adjusts the recheck by +1 (folio 27)",
    }, {
      "name" = "dsoMorSurpriseMod",
      "value" = -1,
      "comment" = "each side surprised takes -1 to morale (folio 27)",
    }, {
      "name" = "dsoMorBerserkPctPerRound",
      "value" = 10,
      "comment" = "F - fights! No further morale check; 10 percent per round will berserk (folio 27)",
    }, {
      "name" = "dsoMorOutcomeCount",
      "value" = 11,
      "comment" = "the dsoMorOutcome table runs 11 rows - the chart numbers -5 or less through +5 or more (folios 26-27)",
    }, {
      "name" = "dsoDaHd",
      "value" = 7,
      "comment" = "the Death Angel hit dice - 7 (folio 29)",
    }, {
      "name" = "dsoDaHdSides",
      "value" = 8,
      "comment" = "the Death Angel hit-die sides - eight-sided (folio 29)",
    }, {
      "name" = "dsoDaAc",
      "value" = 4,
      "comment" = "the Death Angel armor class - 4 (folio 29)",
    }, {
      "name" = "dsoDaMove",
      "value" = 12,
      "comment" = "the Death Angel movement - 12 (folio 29)",
    }, {
      "name" = "dsoDaMoveFly",
      "value" = 20,
      "comment" = "the Death Angel flying movement - 20, the golden wings (folio 29)",
    }, {
      "name" = "dsoDaNumAppearing",
      "value" = 1,
      "comment" = "the Death Angel number appearing - 1 (folio 29)",
    }, {
      "name" = "dsoDaScytheMin",
      "value" = 1,
      "comment" = "the Death Scythe damage minimum - 1 (folio 29)",
    }, {
      "name" = "dsoDaScytheMax",
      "value" = 12,
      "comment" = "the Death Scythe damage maximum - 12 (folio 29)",
    }, {
      "name" = "dsoDaSavePenalty",
      "value" = 3,
      "comment" = "every scythe hit forces a save vs. Death at -3 (folio 29)",
    }, {
      "name" = "dsoDaConLostPerSave",
      "value" = 1,
      "comment" = "a successful save still costs one point of constitution, restored only by clerical Restoration or a Healer Energy spell (folio 29)",
    }, {
      "name" = "dsoDaRiseDays",
      "value" = 3,
      "comment" = "those killed by a Death Angel rise as Death Angels after three days unless raised (folio 29)",
    }, {
      "name" = "dsoDaMagicResistPct",
      "value" = 95,
      "comment" = "the Death Angel resistance to all magic including clerical - 95 percent (folio 29)",
    }, {
      "name" = "dsoDaRaiseConAsIf",
      "value" = 3,
      "comment" = "the percent chance for raising rolls as if the victim's constitution were 3 (folio 29)",
    }, {
      "name" = "dsoDaKillsIrreversible",
      "value" = 3,
      "comment" = "a being killed three times by a Death Angel is gone - not even a Wish brings it back (folio 29)",
    }, {
      "name" = "dsoDaMasterPriestLevelMin",
      "value" = 20,
      "comment" = "the Death Angel's very few evil priest masters are of 20th level or higher (folio 29)",
    }, {
      "name" = "dsoDaAvgHp",
      "value" = 31,
      "comment" = "the average hit points - 7 eight-sided dice at 4.5 per die, floored (folio 29)",
    }, {
      "name" = "dsoDaXp",
      "value" = 850,
      "comment" = "the base XP - the DMG p.85 formula at 7 dice: 225 base + 2 specials x 175 + 1 exceptional x 275; the conversion noted (folio 29)",
    }, {
      "name" = "dsoDaXpPerHp",
      "value" = 8,
      "comment" = "the XP per hit point - the DMG p.85 per-hit-die value at the 6+1 to 7 dice category (folio 29)",
    }, {
      "name" = "dsoDaXpValue",
      "value" = 1098,
      "comment" = "the XP value - 850 + 8 x 31, the DMG p.85 additive formula (folio 29)",
    } },
  "bools" = { {
      "name" = "dsoSeaCoastalTradeOnly",
      "value" = true,
      "comment" = "all trading and sailing is coastal in nature (folio 6)",
    }, {
      "name" = "dsoSeaNoForcedLossSale",
      "value" = true,
      "comment" = "the player/merchant is not required to sell a cargo at a loss - a loss port can be departed (folio 6)",
    }, {
      "name" = "dsoSeaDepartedPortCountsBypassed",
      "value" = true,
      "comment" = "a port departed without sale counts as a port bypassed (folio 6)",
    }, {
      "name" = "dsoSeaWildernessRulesWhenAboard",
      "value" = true,
      "comment" = "when the merchant accompanies the vessel the Wilderness Adventure rules govern - this layer covers the absent owner (folio 6)",
    }, {
      "name" = "dsoPsiAnyClass",
      "value" = true,
      "comment" = "it does not matter what class the character may choose - humanity is the basis of psionic potential (folio 25)",
    }, {
      "name" = "dsoPsiNoAcquisitionPenalty",
      "value" = true,
      "comment" = "the character does not incur a penalty for acquiring additional abilities (folio 25)",
    }, {
      "name" = "dsoPsiLearnByEspAndProjection",
      "value" = true,
      "comment" = "learning from a teacher requires the learner to have ESP (or an ESP Medallion) and the teacher Telepathic Projection (or a Helm of Telepathy) (folio 25)",
    }, {
      "name" = "dsoPsiSpontaneousAtNextLevel",
      "value" = true,
      "comment" = "spontaneous development as stated in Eldritch Wizardry - the percentile roll is made as the next level is attained (folio 25)",
    }, {
      "name" = "dsoPsiMagicalAcquisition",
      "value" = true,
      "comment" = "any character can acquire a psionic ability magically, but without becoming psionic except through magic (folio 25)",
    }, {
      "name" = "dsoPsiLowIntelligenceLimits",
      "value" = true,
      "comment" = "a low intelligence limits the number of abilities learnable and extends the learning time (folio 25)",
    }, {
      "name" = "dsoMorCharismaSameTable",
      "value" = true,
      "comment" = "the leader's charisma uses the same 3d6 modifier table as personal bravery (folio 27)",
    }, {
      "name" = "dsoMorLoyaltySameTable",
      "value" = true,
      "comment" = "loyalty as rolled and adjusted for charisma and other incentives uses the same modifier table (folio 27)",
    }, {
      "name" = "dsoMorBreakDexDamageRoll",
      "value" = true,
      "comment" = "B - break and run: roll Dexterity to see if the runner takes one round of damage (folio 27)",
    }, {
      "name" = "dsoMorHesitateRecheckNextRound",
      "value" = true,
      "comment" = "H - hesitates: does not fight, check again next melee round (folio 27)",
    }, {
      "name" = "dsoMorRecheckOnChartChange",
      "value" = true,
      "comment" = "S - stands and fights: check again if the morale chart number changes (folio 27)",
    }, {
      "name" = "dsoDaNeutral",
      "value" = true,
      "comment" = "the Death Angel alignment - Neutral (folio 29)",
    }, {
      "name" = "dsoDaVanishesWhenSlain",
      "value" = true,
      "comment" = "when killed the Death Angel vanishes entirely, leaving no remains (folio 29)",
    }, {
      "name" = "dsoDaTeleportNoFail",
      "value" = true,
      "comment" = "the Death Angel teleport has no chance of failure (folio 29)",
    }, {
      "name" = "dsoDaNoTeleportFromMelee",
      "value" = true,
      "comment" = "the Death Angel cannot teleport out of melee (folio 29)",
    }, {
      "name" = "dsoDaTurnedLikeVampire",
      "value" = true,
      "comment" = "the Death Angel can be turned like a Vampire by a Cleric (folio 29)",
    }, {
      "name" = "dsoDaReturnsNextDay",
      "value" = true,
      "comment" = "a turned Death Angel returns the next day (or night) - the mission of death must be fulfilled (folio 29)",
    }, {
      "name" = "dsoDaVictimsRiseAsAngels",
      "value" = true,
      "comment" = "those successfully killed by a Death Angel become Death Angels after three days unless raised (folio 29)",
    }, {
      "name" = "dsoDaRaiseDeadFullyOnly",
      "value" = true,
      "comment" = "a normal Raise Dead will not work on a Death Angel victim - only Raise Dead Fully, and even then it raises like a regular Raise Dead (folio 29)",
    }, {
      "name" = "dsoDaWishRaisesAutomatically",
      "value" = true,
      "comment" = "a Wish works automatically to raise a Death Angel victim (folio 29)",
    }, {
      "name" = "dsoDaOnlyAttacksVictim",
      "value" = true,
      "comment" = "the Death Angel only attacks its intended victim, ignoring all others, and leaves after the kill (folio 29)",
    }, {
      "name" = "dsoDaRemoveCurseGrantsPeace",
      "value" = true,
      "comment" = "a remove curse thrown upon a slain Death Angel grants it eternal peace - the only permanent dispelling (folio 29)",
    }, {
      "name" = "dsoDaOnePerMaster",
      "value" = true,
      "comment" = "there can be no more than one Death Angel serving any one master (folio 29)",
    }, {
      "name" = "dsoDaTelepathicAllLanguages",
      "value" = true,
      "comment" = "the Death Angel is highly intelligent and speaks all languages telepathically (folio 29)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "dsoSeaProfitLoss",
      "tag" = "StP",
      "count" = "dsoSeaProfitLossCount",
      "sentinel" = 0,
      "cols" = { "dsoSeaSaleCol0", "dsoSeaSaleCol1", "dsoSeaSaleCol2", "dsoSeaSaleCol3", "dsoSeaSaleCol4", "dsoSeaSaleCol5", "dsoSeaSaleCol6" },
      "col_comments" = { "the sale percentage of cargo value at 0 port bypassed - the profit/loss table rows run the percentile bands 01-05 through 91-00 (folio 6)", "the sale percentage of cargo value at 1 ports bypassed - the profit/loss table rows run the percentile bands 01-05 through 91-00 (folio 6)", "the sale percentage of cargo value at 2 ports bypassed - the profit/loss table rows run the percentile bands 01-05 through 91-00 (folio 6)", "the sale percentage of cargo value at 3 ports bypassed - the profit/loss table rows run the percentile bands 01-05 through 91-00 (folio 6)", "the sale percentage of cargo value at 4 ports bypassed - the profit/loss table rows run the percentile bands 01-05 through 91-00 (folio 6)", "the sale percentage at 5 ports bypassed - the folio's 16-20 row prints 10 in this column where the arithmetic of its neighbours reads about 70; the cell rides AS SCANNED, the garble noted (folio 6)", "the sale percentage of cargo value at 6 ports bypassed - the profit/loss table rows run the percentile bands 01-05 through 91-00 (folio 6)" },
      "data" = { { 85, 80, 70, 60, 50, 40, 30 }, { 90, 85, 80, 70, 60, 50, 40 }, { 95, 90, 85, 80, 70, 60, 50 }, { 100, 95, 90, 85, 80, 10, 60 }, { 105, 100, 95, 90, 90, 85, 80 }, { 105, 105, 110, 115, 115, 120, 120 }, { 110, 110, 115, 120, 125, 140, 150 }, { 110, 115, 120, 130, 135, 160, 200 }, { 110, 120, 130, 140, 150, 200, 300 }, { 115, 125, 150, 160, 200, 300, 500 }, { 120, 130, 160, 180, 250, 400, 0 }, { 125, 135, 180, 200, 350, 0, 0 }, { 130, 140, 200, 300, 0, 0, 0 }, { 140, 150, 250, 0, 0, 0, 0 }, { 150, 200, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0 } },
      "sentinel_census" = { 1, 1, 2, 3, 4, 5, 6 },
      "audit_comment" = "the Spencer profit/loss grid - percentages of cargo value by percentile band and ports bypassed 0 through 6+; the X cells (ship lost, owner notified 3-8 weeks later) ride as the 0 sentinel (folio 6)",
    }, {
      "name" = "dsoMorOutcome",
      "tag" = "StM",
      "count" = "dsoMorOutcomeCount",
      "sentinel" = 0,
      "col_default" = 0,
      "cols" = { "dsoMorCol1", "dsoMorCol2", "dsoMorCol3", "dsoMorCol4", "dsoMorCol5", "dsoMorCol6", "dsoMorCol7", "dsoMorCol8", "dsoMorCol9", "dsoMorCol10" },
      "col_comments" = { "the morale outcome on the d10 roll of 1 (0 reads as 10) across the chart numbers -5 or less through +5 or more: B = 0 break and run, H = 1 hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)", "the morale outcome on the d10 roll of 2 (0 reads as 10) across the chart numbers -5 or less through +5 or more: B = 0 break and run, H = 1 hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)", "the morale outcome on the d10 roll of 3 (0 reads as 10) across the chart numbers -5 or less through +5 or more: B = 0 break and run, H = 1 hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)", "the morale outcome on the d10 roll of 4 (0 reads as 10) across the chart numbers -5 or less through +5 or more: B = 0 break and run, H = 1 hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)", "the morale outcome on the d10 roll of 5 (0 reads as 10) across the chart numbers -5 or less through +5 or more: B = 0 break and run, H = 1 hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)", "the morale outcome on the d10 roll of 6 (0 reads as 10) across the chart numbers -5 or less through +5 or more: B = 0 break and run, H = 1 hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)", "the morale outcome on the d10 roll of 7 (0 reads as 10) across the chart numbers -5 or less through +5 or more: B = 0 break and run, H = 1 hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)", "the morale outcome on the d10 roll of 8 (0 reads as 10) across the chart numbers -5 or less through +5 or more: B = 0 break and run, H = 1 hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)", "the morale outcome on the d10 roll of 9 (0 reads as 10) across the chart numbers -5 or less through +5 or more: B = 0 break and run, H = 1 hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)", "the morale outcome on the d10 roll of 10 (0 reads as 10) across the chart numbers -5 or less through +5 or more: B = 0 break and run, H = 1 hesitates, S = 2 stands and fights, F = 3 fights (folios 26-27)" },
      "data" = { { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 }, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2 }, { 0, 0, 0, 0, 0, 1, 1, 2, 2, 2 }, { 0, 0, 0, 1, 1, 1, 2, 2, 2, 2 }, { 0, 0, 1, 1, 2, 2, 2, 2, 2, 3 }, { 0, 1, 2, 2, 2, 2, 2, 2, 3, 3 }, { 1, 2, 2, 2, 2, 2, 2, 3, 3, 3 }, { 2, 2, 2, 2, 2, 3, 3, 3, 3, 3 }, { 2, 2, 2, 2, 3, 3, 3, 3, 3, 3 }, { 2, 2, 3, 3, 3, 3, 3, 3, 3, 3 } },
      "audit_comment" = "the Hayes-Gilbert morale grid - chart number -5 or less to +5 or more against the ten-sided die; the B/H/S/F letters ride coded 0/1/2/3 (folios 26-27)",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dsoSeaCargoSmallGp']() != 10000 or m['dsoSeaCargoLargeGp']() != 50000 or m['dsoSeaPilotFeeSmall']() != 500 or m['dsoSeaPilotFeeLarge']() != 2500",
      "note" = "the cargo capacities and the pilot fees (folio 6)",
    }, {
      "expr" = "m['dsoSeaImportTaxPct']() != 5 or m['dsoSeaPortsOnCoast']() != 9 or m['dsoSeaRouteMiles']() != 2500 or m['dsoSeaCoastalMilesMax']() != 50",
      "note" = "the 5 percent import tax, the nine ports, the 2,500-mile route and the fifty-mile coastal limit (folio 6)",
    }, {
      "expr" = "m['dsoSeaDelayWeeksMin']() != 1 or m['dsoSeaDelayWeeksMax']() != 4 or m['dsoSeaLossNoticeWeeksMin']() != 3 or m['dsoSeaLossNoticeWeeksMax']() != 8",
      "note" = "the 1-4 week port delay and the 3-8 week loss notice (folio 6)",
    }, {
      "expr" = "m['dsoSeaCoastalTradeOnly']() != 1 or m['dsoSeaNoForcedLossSale']() != 1 or m['dsoSeaDepartedPortCountsBypassed']() != 1 or m['dsoSeaWildernessRulesWhenAboard']() != 1",
      "note" = "the sea-trade doctrines - coastal only, no forced loss sale, a departed port counts bypassed, the Wilderness rules when aboard (folio 6)",
    }, {
      "expr" = "m['dsoSeaSaleCol1'](9) != 125 or m['dsoSeaSaleCol0'](9) != 115",
      "note" = "the print's worked example - 10,000 G.P. cargo, dice 62, sale 11,500 G.P. - matches the 61-65 row at ZERO ports bypassed (115), while the one-bypassed cell prints 125; the grid is the pin, the worked example's discrepancy noted (folio 6)",
    }, {
      "expr" = "m['dsoPsiHumanRollMin']() != 91 or m['dsoPsiHalfHumanRollMin']() != 95 or m['dsoPsiAbilitiesCount']() != 37",
      "note" = "the psionic gates - humans 91, half-humans 95, thirty-seven abilities (folio 25)",
    }, {
      "expr" = "m['dsoPsiBasicWeeksPerLevel']() != 1 or m['dsoPsiSuperiorWeeksTenths']() != 15 or m['dsoPsiAttackDefenseWeeks']() != 9",
      "note" = "the learning ladder - one week per level basic, the garbled 1 1/2 read as 15 tenths superior, nine weeks per attack or defense mode (folio 25)",
    }, {
      "expr" = "m['dsoPsiAnyClass']() != 1 or m['dsoPsiNoAcquisitionPenalty']() != 1 or m['dsoPsiLearnByEspAndProjection']() != 1 or m['dsoPsiSpontaneousAtNextLevel']() != 1 or m['dsoPsiMagicalAcquisition']() != 1 or m['dsoPsiLowIntelligenceLimits']() != 1",
      "note" = "the psionic doctrines - any class, no acquisition penalty, the ESP/Projection learning gate, spontaneous development, magical acquisition, low intelligence limits (folio 25)",
    }, {
      "expr" = "m['dsoMorBrave3']() != -4 or m['dsoMorBrave4']() != -3 or m['dsoMorBrave56']() != -2 or m['dsoMorBrave78']() != -1 or m['dsoMorBrave912']() != 0 or m['dsoMorBrave1314']() != 1 or m['dsoMorBrave1516']() != 2 or m['dsoMorBrave17']() != 3 or m['dsoMorBrave18']() != 4 or m['dsoMorBrave19']() != 5",
      "note" = "the bravery modifier ladder on 3d6, 3 through 19 or more (folio 27)",
    }, {
      "expr" = "m['dsoMorLvl34']() != 1 or m['dsoMorLvl56']() != 2 or m['dsoMorLvl78']() != 3",
      "note" = "the level additions to the chart number - +1 at 3-4, +2 at 5-6, +3 at 7-8 (folio 27)",
    }, {
      "expr" = "m['dsoMorAdjComradeBreaks']() != -1 or m['dsoMorAdjMuClericBreaks']() != -2 or m['dsoMorAdjLeaderBreaks']() != -4 or m['dsoMorAdjEnemyLeader']() != 4 or m['dsoMorAdjEnemyMuCleric']() != 2 or m['dsoMorAdjEnemyFighter']() != 1",
      "note" = "the post-melee recheck adjustments - own losses subtract, enemy losses add (folio 27)",
    }, {
      "expr" = "m['dsoMorSurpriseMod']() != -1 or m['dsoMorBerserkPctPerRound']() != 10",
      "note" = "the surprised-side -1 and the F-fights 10 percent berserk per round (folio 27)",
    }, {
      "expr" = "m['dsoMorCharismaSameTable']() != 1 or m['dsoMorLoyaltySameTable']() != 1 or m['dsoMorBreakDexDamageRoll']() != 1 or m['dsoMorHesitateRecheckNextRound']() != 1 or m['dsoMorRecheckOnChartChange']() != 1",
      "note" = "the morale doctrines - charisma and loyalty on the same table, the Dex roll on a break, the hesitate recheck, the chart-change recheck (folios 26-27)",
    }, {
      "expr" = "m['dsoDaHd']() != 7 or m['dsoDaHdSides']() != 8 or m['dsoDaAc']() != 4 or m['dsoDaMove']() != 12 or m['dsoDaMoveFly']() != 20 or m['dsoDaNumAppearing']() != 1",
      "note" = "the Death Angel stat line - 7 eight-sided dice, AC 4, move 12/20, number appearing 1 (folio 29)",
    }, {
      "expr" = "m['dsoDaScytheMin']() != 1 or m['dsoDaScytheMax']() != 12 or m['dsoDaSavePenalty']() != 3 or m['dsoDaConLostPerSave']() != 1",
      "note" = "the Death Scythe - 1-12 with a save vs. Death at -3, one constitution point lost on a successful save (folio 29)",
    }, {
      "expr" = "m['dsoDaRiseDays']() != 3 or m['dsoDaMagicResistPct']() != 95 or m['dsoDaRaiseConAsIf']() != 3 or m['dsoDaKillsIrreversible']() != 3 or m['dsoDaMasterPriestLevelMin']() != 20",
      "note" = "the Death Angel numerics - the three-day rise, the 95 percent resistance, the raise-as-con-3, the third-kill irreversibility, the 20th-level priest masters (folio 29)",
    }, {
      "expr" = "m['dsoDaAvgHp']() != 31 or m['dsoDaXp']() != 850 or m['dsoDaXpPerHp']() != 8 or m['dsoDaXpValue']() != 1098",
      "note" = "the Death Angel XP conversion - the DMG p.85 additive formula: 225 base + 2 x 175 + 275, plus 8 per hit point at the floored 31 average; the conversion noted, never silent (folio 29)",
    }, {
      "expr" = "m['dsoDaNeutral']() != 1 or m['dsoDaVanishesWhenSlain']() != 1 or m['dsoDaTeleportNoFail']() != 1 or m['dsoDaNoTeleportFromMelee']() != 1 or m['dsoDaTurnedLikeVampire']() != 1 or m['dsoDaReturnsNextDay']() != 1",
      "note" = "the Death Angel doctrines - Neutral, vanishes when slain, the no-fail teleport that cannot leave melee, turned like a Vampire yet returns next day (folio 29)",
    }, {
      "expr" = "m['dsoDaVictimsRiseAsAngels']() != 1 or m['dsoDaRaiseDeadFullyOnly']() != 1 or m['dsoDaWishRaisesAutomatically']() != 1 or m['dsoDaOnlyAttacksVictim']() != 1 or m['dsoDaRemoveCurseGrantsPeace']() != 1 or m['dsoDaOnePerMaster']() != 1 or m['dsoDaTelepathicAllLanguages']() != 1",
      "note" = "the Death Angel mission doctrines - the victim's rise, the Raise Dead Fully limit, the automatic Wish, the single victim, the remove-curse peace, one per master, telepathic speech (folio 29)",
    } },
  "audit" = {
      "label" = "R906 issue-6 opener audit",
      "comment" = "THE DRAGON ISSUE-6 OPENER ROUND - four adjudicated chains. The Sea Trade system (folio 6, Spencer): the cargo and fee pins, the coastal doctrines and the sixteen-band profit/loss grid with the ship-lost sentinel. The psionic option (folio 25, Miller): the percentile gates, the thirty-seven abilities and the learning ladders. The morale system (folios 26-27, Hayes and Gilbert): the modifier ladders, the recheck adjustments and the eleven-chart outcome grid with B/H/S/F coded 0-3. The Death Angel (folio 29, Sullivan): the stat pin, the mission doctrines and the DMG p.85 XP conversion.",
    },
}
