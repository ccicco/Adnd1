-- dnrv: promoted from tools/spec_r523.json (the The DSG MINING TAIL, R523: printed p. 53 (pdf 54) plus the claim continuation on printed p. 54 (pdf 55) - the placer value: only gold, silver or platinum can be placer-mined (copper, iron, mithril and gemstones impossible), the value following the normal page-51 quality determination then the 1d4-times-10 percentage of full value (10-40%); the smelting: one smelter-proficiency character runs the operation with unskilled workers under supervision, over a bellows-and-unmeltable-container setup with a coal (sometimes wood) fire, the smoke and smell making it almost impossible to conceal, and the underground rule that careless ventilation lets the fire consume all the oxygen; the finishing: gemstones rarely need smelting (occasional heat for crusted minerals), the gem cutter proficiency cutting and polishing at 2d20 stones per character per day (excavation usually greatly exceeding finishing), and the weekly 1d100 exceptional-stone check (a 00 unearths a stone worth 1d100 times the week's average value); the duration: the secret d100 man-weeks roll with the doubles ladder (doubles add a d100 of man-months, doubles again a d100 of man-years, repeating until a non-doubles roll; a month is four weeks, a year 48 weeks; 12 miners use 12 man-weeks per week) and the placer exception (doubles disregarded, always 1-100 man-weeks); the hazards: inherent, with success attracting problems almost automatically; and the claim: the right to remove mineral wealth, clear titles rare with rulers usually holding title, the mining charter (as little as 25 or 30%, more often 50%, a strong ruler always 50%) enforced by spies, surprise inspections, discreet observation or a ruler-employed smelter reporting the exact amounts, cheating punished usually by death (leniency never restoring the mine), and the wilderness continuation - the overnight land war among rulers with tribute and the winner-dependent claim recognition, the savage denizens raiding trespassers with cancellable charter-like monster agreements, no legal protection (the claim held by whoever can hold it), claim-jumpers in direct proportion to profitability, the rarely-working concealment (hiding the entrance with secret doors and brush, the tailings spread or dumped in water at the 25% mining rate, the chipping noise carrying to Underdark creatures, the bulette bust-in, the smelter smoke killing concealment), and the wealth-disposal risk of brazen moneychanger visits);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 523,
  "prefix" = "dnrv",
  "banner" = {
      "title" = "The DSG MINING TAIL, R523: printed p. 53 (pdf 54) plus the claim continuation on printed p. 54 (pdf 55) - the placer value: only gold, silver or platinum can be placer-mined (copper, iron, mithril and gemstones impossible), the value following the normal page-51 quality determination then the 1d4-times-10 percentage of full value (10-40%); the smelting: one smelter-proficiency character runs the operation with unskilled workers under supervision, over a bellows-and-unmeltable-container setup with a coal (sometimes wood) fire, the smoke and smell making it almost impossible to conceal, and the underground rule that careless ventilation lets the fire consume all the oxygen; the finishing: gemstones rarely need smelting (occasional heat for crusted minerals), the gem cutter proficiency cutting and polishing at 2d20 stones per character per day (excavation usually greatly exceeding finishing), and the weekly 1d100 exceptional-stone check (a 00 unearths a stone worth 1d100 times the week's average value); the duration: the secret d100 man-weeks roll with the doubles ladder (doubles add a d100 of man-months, doubles again a d100 of man-years, repeating until a non-doubles roll; a month is four weeks, a year 48 weeks; 12 miners use 12 man-weeks per week) and the placer exception (doubles disregarded, always 1-100 man-weeks); the hazards: inherent, with success attracting problems almost automatically; and the claim: the right to remove mineral wealth, clear titles rare with rulers usually holding title, the mining charter (as little as 25 or 30%, more often 50%, a strong ruler always 50%) enforced by spies, surprise inspections, discreet observation or a ruler-employed smelter reporting the exact amounts, cheating punished usually by death (leniency never restoring the mine), and the wilderness continuation - the overnight land war among rulers with tribute and the winner-dependent claim recognition, the savage denizens raiding trespassers with cancellable charter-like monster agreements, no legal protection (the claim held by whoever can hold it), claim-jumpers in direct proportion to profitability, the rarely-working concealment (hiding the entrance with secret doors and brush, the tailings spread or dumped in water at the 25% mining rate, the chipping noise carrying to Underdark creatures, the bulette bust-in, the smelter smoke killing concealment), and the wealth-disposal risk of brazen moneychanger visits",
      "provenance" = "the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf = printed + 1; the text read from the IA djvu OCR (djvu.txt lines ~6790-7060) with the pdf Acrobat-Capture layer as the second read (idx 125 = the printed pp. 52-53 window, idx 127 = the printed p. 54 window); the compiled-tables appendix has no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on every load-bearing number, and the only garbles are the standing OCR die-notation class (djvu \"14100\"/\"4100\" and Capture \"ld4\"/\"dlOO\"/\"1-1 00\" all reading as 1d100/1d4). The charter percentages multi-confirm: the djvu \"5096\" and the Capture \"50%\" both read as 50%, and both reads give the as-little-as 25-or-30% phrasing (pinned as 25 with the phrasing noted). The tailings 25% mining rate, the 2d20 finishing capacity, the 4-week month, the 48-week year, the 1-100 man-week placer cap and the exceptional-stone 1d100 weekly check with the 1d100-times-average value all appear identically in both reads. CATCH-UP: the exceptional-stone paragraph sits on printed p. 52 with no gap child of its own (it fell between the R521 products child and the R522 quality child) - it rides this round via the Finishing child flip, keeping the report lossless. The hireling loyalty section proper (child 133) starts the NEXT round at its printed p. 54 heading. The R519 placer/tunnel seam and the R521 Table 30 seam are noted; nothing auto-credits.",
      "sentinel" = "A prose round: no tables pin. The dice pin as consts per the R508 convention - the placer 1d4 x 10 percentage, the 2d20 finishing capacity, the secret d100 duration roll, and the weekly 1d100 exceptional-stone check with its 1d100-times-average value roll. The conveniences and thresholds pin as consts: the 4-week month, the 48-week year, the 1-100 man-week placer cap, the 25-or-30/50 charter shares, and the 25% tailings-scattering mining rate. The rest pins as prose bools: the placer metal restrictions, the one-smelter rule with its equipment and ventilation, the gem-cutter finishing, the doubles duration ladder with the placer exception and the man-week definition, the charter enforcement and cheating penalty, the wilderness war/denizen/no-legal-protection/claim-jumper hazards, the concealment problem set, and the wealth-disposal risk. The exceptional-stone catch-up is load-bearing: printed p. 52 prose with no child line, pinned under the Finishing child. The R519/R520/R521 seams are noted; nothing auto-credits.",
    },
  "consts" = { {
      "name" = "dnrvPlacerDice",
      "value" = 1,
      "comment" = "the placer full-value roll is one die.",
    }, {
      "name" = "dnrvPlacerSides",
      "value" = 4,
      "comment" = "the placer full-value roll is 1d4, multiplied by 10 to give the percentage of full value.",
    }, {
      "name" = "dnrvPlacerPctMult",
      "value" = 10,
      "comment" = "the d4 result times 10 is the percentage of full value gained from a placer mine (10-40%).",
    }, {
      "name" = "dnrvFinishDice",
      "value" = 2,
      "comment" = "a character finishing stones rolls 2 dice of capacity per day.",
    }, {
      "name" = "dnrvFinishSides",
      "value" = 20,
      "comment" = "a given character can only finish 2d20 stones in a day.",
    }, {
      "name" = "dnrvDurationDice",
      "value" = 1,
      "comment" = "the duration roll is one die.",
    }, {
      "name" = "dnrvDurationSides",
      "value" = 100,
      "comment" = "the DM secretly rolls d100 at the start of the mining operation: the result is the man-weeks before depletion.",
    }, {
      "name" = "dnrvMonthWeeks",
      "value" = 4,
      "comment" = "each month is treated as four weeks when totalling a mine's longevity.",
    }, {
      "name" = "dnrvYearWeeks",
      "value" = 48,
      "comment" = "each year is treated as 48 weeks, or 12 months, when totalling a mine's longevity.",
    }, {
      "name" = "dnrvCharterLowPct",
      "value" = 25,
      "comment" = "a mining charter might claim as little as 25 or 30% of the mine's profit for the ruler (the low claim only from a weak-grasping ruler avoiding conflict).",
    }, {
      "name" = "dnrvCharterCommonPct",
      "value" = 50,
      "comment" = "a charter more often requires a 50% share, and a strong ruler always asks for 50% of the mine's products.",
    }, {
      "name" = "dnrvTailingsMiningPct",
      "value" = 25,
      "comment" = "if miners scatter the tailings to hide the mine, the rate of mining is no more than 25% of what it could be.",
    }, {
      "name" = "dnrvPlacerMinWeeks",
      "value" = 1,
      "comment" = "a placer mine is always depleted after 1 man-week of work at the minimum (doubles disregarded).",
    }, {
      "name" = "dnrvPlacerMaxWeeks",
      "value" = 100,
      "comment" = "a placer mine is always depleted after at most 100 man-weeks of work.",
    }, {
      "name" = "dnrvExcepStoneDice",
      "value" = 1,
      "comment" = "the exceptional-stone check is one die (the printed p. 52 catch-up).",
    }, {
      "name" = "dnrvExcepStoneSides",
      "value" = 100,
      "comment" = "roll 1d100 each week the mine is operating: a result of 00 means an exceptional stone is unearthed.",
    } },
  "bools" = { {
      "name" = "dnrvPlacerGoldSilverPlatinumOnly",
      "value" = true,
      "comment" = "placer mining of copper, iron, mithril, or any kind of gemstone is impossible for these rules; only gold, silver, or platinum deposits can be worked with a placer mine.",
    }, {
      "name" = "dnrvPlacerUsesQualityThenPercent",
      "value" = true,
      "comment" = "calculate the placer value by the normal quality determination (page 51), then apply the 1d4-times-10 percentage of full value.",
    }, {
      "name" = "dnrvOneSmelterSuffices",
      "value" = true,
      "comment" = "as with mining, only one character with smelter proficiency is required to run a smelting operation; other, unskilled characters work under that character's supervision.",
    }, {
      "name" = "dnrvSmelterNeedsHotFire",
      "value" = true,
      "comment" = "the smelting of ore requires a fairly extensive equipment collection: because a very hot fire is crucial, smelters must have a bellows system and several unmeltable containers to hold heated ore.",
    }, {
      "name" = "dnrvMostMineralsNeedCoal",
      "value" = true,
      "comment" = "most minerals require a coal fire for smelting, but some can be smelted by wood fires.",
    }, {
      "name" = "dnrvSmeltingImpossibleToConceal",
      "value" = true,
      "comment" = "a smelting operation produces much smoke and smell, so it is almost impossible to conceal.",
    }, {
      "name" = "dnrvUndergroundSmeltingVentilation",
      "value" = true,
      "comment" = "if done underground, the ventilation of the smelting area must be carefully attended, or the smelting fire is likely to consume all the oxygen in the area.",
    }, {
      "name" = "dnrvStonesRarelyNeedSmelting",
      "value" = true,
      "comment" = "gemstones rarely require the complicated procedures needed to smelt ore from rock, though occasionally heat removes excess minerals crusted around the gemstones.",
    }, {
      "name" = "dnrvGemCutterFinishes",
      "value" = true,
      "comment" = "the usual finishing procedure requires a character with gem cutter proficiency to cut and polish the stones.",
    }, {
      "name" = "dnrvExcavationExceedsFinishing",
      "value" = true,
      "comment" = "the rate at which stones can be excavated usually greatly exceeds the 2d20-per-day rate at which they can be finished.",
    }, {
      "name" = "dnrvMineWealthFinite",
      "value" = true,
      "comment" = "a given mine always contains a finite amount of mineral wealth - occasionally a lifetime or more, much more frequently the mine plays out after a certain time.",
    }, {
      "name" = "dnrvDoublesAddMonths",
      "value" = true,
      "comment" = "if the secret d100 duration roll yields doubles (e.g., 11, 22, 33), the mine has a much longer duration: roll d100 again and read the result as man-months, added to the weeks.",
    }, {
      "name" = "dnrvDoublesAgainAddYears",
      "value" = true,
      "comment" = "if the second d100 roll also yields doubles, roll d100 a third time reading man-years; further doubles add more years until a roll comes up without doubles.",
    }, {
      "name" = "dnrvManWeekPerMiner",
      "value" = true,
      "comment" = "a man-week is the amount of work one human miner performs in a week - 12 miners engaged on a mine use up 12 man-weeks of its lifetime every week.",
    }, {
      "name" = "dnrvPlacerDisregardsDoubles",
      "value" = true,
      "comment" = "if the mine is a placer mine, disregard any doubles rolls for the duration of the find: always depleted after 1-100 man-weeks of work.",
    }, {
      "name" = "dnrvHazardsInherent",
      "value" = true,
      "comment" = "any mining operation includes an inherent set of hazards, and a very successful operation attracts additional problems almost automatically - no free lunch for avaricious player characters.",
    }, {
      "name" = "dnrvClaimIsRightToWealth",
      "value" = true,
      "comment" = "a claim is the miner's claimed right to remove mineral or gemstone wealth from the ground; with clear and undisputable legal title it is usually no problem initially.",
    }, {
      "name" = "dnrvTitleUsuallyARuler",
      "value" = true,
      "comment" = "except in the most civilized and well-developed areas, a clear and undisputable title is uncommon; if anyone holds title to the land it is usually a king or other ruler with a selfish interest in its wealth.",
    }, {
      "name" = "dnrvCharterPossible",
      "value" = true,
      "comment" = "a character might gain a mining charter from a ruler allowing mining of a given tract, with a hefty percentage of the mine's profit turned over to the ruler.",
    }, {
      "name" = "dnrvRulerEnforcesShare",
      "value" = true,
      "comment" = "the ruler takes steps to insure the fair share: a spy among the miners, surprise inspections, discreet observation from a safe distance, or a smelter/finisher in the ruler's employ loyally reporting the exact amount processed.",
    }, {
      "name" = "dnrvCheatingUsuallyDeath",
      "value" = true,
      "comment" = "a miner caught cheating his liege is usually punished by death; exceptional leniency might let the character live - perhaps retaining all body parts - but never to continue operating the mine.",
    }, {
      "name" = "dnrvWildernessClaimFreeButHazardous",
      "value" = true,
      "comment" = "a claim on wilderness land is initially free of charter negotiation, but the land is wilderness because it is too savage for settlement or no useful purpose was discovered.",
    }, {
      "name" = "dnrvLandWarOvernight",
      "value" = true,
      "comment" = "land thought worthless for centuries can become highly sought after when minerals are found: rulers war over it, and the winning ruler exacts tribute - PCs who aided the winner may continue operating with taxes; PCs who opposed the winner have little likelihood of recognized claims, at best fleeing with their lives and some small profit.",
    }, {
      "name" = "dnrvSavageDenizensRaid",
      "value" = true,
      "comment" = "raiding monsters show no favor to PCs perceived as trespassing; intelligent monsters not inclined to take over operations may be negotiated with, charter-like, but chaotic monsters have little respect for agreements and might cancel one with no more notice than a battle-cry or surprise attack.",
    }, {
      "name" = "dnrvNoLegalProtection",
      "value" = true,
      "comment" = "a wilderness claim has no legal protection: it is generally owned by whichever creature or party is most capable of holding it against interlopers.",
    }, {
      "name" = "dnrvClaimJumpersProportional",
      "value" = true,
      "comment" = "the number of claim-jumpers climbs in direct proportion to the mine's profitability - considerable wealth attracts distant creatures or high-level characters whose only purpose is taking the mine by force.",
    }, {
      "name" = "dnrvConcealmentRarelyWorks",
      "value" = true,
      "comment" = "attempting to conceal the mine is commonly attempted but rarely successful: it virtually never works in a settled area and has only a limited chance in the wilderness.",
    }, {
      "name" = "dnrvConcealmentProblems",
      "value" = true,
      "comment" = "concealment requires hiding the entrance (secret doors, piles of brush and twigs), defeating the tailings giveaway (spreading them over a large area, or dumping into a river, lake, or deep pit - at the 25% mining rate), and the noise of chipping that carries clues especially to Underdark creatures.",
    }, {
      "name" = "dnrvSmelterKillsConcealment",
      "value" = true,
      "comment" = "a mine located next to a smelter had better abandon all hope of concealment: the clouds of smoke and pervasive odor make it all but impossible except in the most remote and uninhabited areas.",
    }, {
      "name" = "dnrvWealthDisposalRisky",
      "value" = true,
      "comment" = "even in complete secrecy, wealth disposal is a problem: brazenly converting 100 pounds of solid gold at the moneychanger raises eyebrows, and NPCs getting wind of a valuable claim may follow the characters back to their mine.",
    }, {
      "name" = "dnrvExcepStoneWeeklyCheck",
      "value" = true,
      "comment" = "in addition to the week's base stone value, roll 1d100 each week the mine operates: a 00 means an exceptional stone is unearthed (the printed p. 52 catch-up, no gap child of its own).",
    }, {
      "name" = "dnrvExcepStoneValueRoll",
      "value" = true,
      "comment" = "the exceptional stone's finder rolls 1d100 and multiplies the result by the average stone value for that week - e.g., a 20 gp turquoise average and a 68 yields a 1,360 gp stone.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnrvPlacerDice']() != 1 or m['dnrvPlacerSides']() != 4 or m['dnrvPlacerPctMult']() != 10 or m['dnrvFinishDice']() != 2 or m['dnrvFinishSides']() != 20",
      "note" = "the placer and finishing rolls: the 1d4-times-10 percent of full value, and the 2d20 stones finished per day.",
    }, {
      "expr" = "m['dnrvDurationDice']() != 1 or m['dnrvDurationSides']() != 100 or m['dnrvMonthWeeks']() != 4 or m['dnrvYearWeeks']() != 48 or m['dnrvPlacerMinWeeks']() != 1 or m['dnrvPlacerMaxWeeks']() != 100",
      "note" = "the duration rolls: the secret d100 in man-weeks, the 4-week month and 48-week year conveniences, and the placer 1-100 man-week cap.",
    }, {
      "expr" = "m['dnrvCharterLowPct']() != 25 or m['dnrvCharterCommonPct']() != 50 or m['dnrvTailingsMiningPct']() != 25 or m['dnrvExcepStoneDice']() != 1 or m['dnrvExcepStoneSides']() != 100",
      "note" = "the percentages and catch-up: the 25-or-30/50 charter shares, the 25% tailings-scattering mining rate, and the weekly 1d100 exceptional-stone check.",
    }, {
      "expr" = "m['dnrvPlacerGoldSilverPlatinumOnly']() != 1 or m['dnrvOneSmelterSuffices']() != 1 or m['dnrvGemCutterFinishes']() != 1 or m['dnrvDoublesAddMonths']() != 1 or m['dnrvDoublesAgainAddYears']() != 1 or m['dnrvPlacerDisregardsDoubles']() != 1 or m['dnrvCheatingUsuallyDeath']() != 1",
      "note" = "the tail prose: the placer metal restrictions, the one-smelter rule, the gem-cutter finishing, the doubles duration ladder with the placer exception, and the cheating penalty.",
    } },
  "audit" = {
      "label" = "R523 DSG mining tail audit",
      "comment" = "The DSG mining tail pins the placer value (gold, silver or platinum only, the normal quality determination then the 1d4-times-10 percent of full value), the smelting (the one-smelter rule, the bellows and unmeltable containers over a coal fire, the impossible concealment, the underground ventilation), the finishing (the gem cutter at 2d20 stones per day with the weekly 1d100 exceptional-stone check worth 1d100 times the week's average value), the duration (the secret d100 man-weeks, the doubles ladder adding months then years until a non-doubles roll, the 4-week month, the 48-week year, the man-week definition, the placer 1-100 cap), and the claim (the 25-or-30/50 charter shares with the ruler enforcement and the usually-death cheating penalty, the wilderness war, denizens, claim-jumpers, the concealment set with the 25% tailings rate, and the wealth-disposal risk).",
    },
}
