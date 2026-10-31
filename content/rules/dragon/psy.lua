-- psy: promoted from tools/spec_r934.json (the The Dragon issue-18 opener part one - the insanity chart and doctrine, the laws of magic, the godgame hazard and the NPC pride, greed and work-quality tables: the four-chain round);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 934,
  "prefix" = "psy",
  "banner" = {
      "title" = "The Dragon issue-18 opener part one - the insanity chart and doctrine, the laws of magic, the godgame hazard and the NPC pride, greed and work-quality tables: the four-chain round",
      "provenance" = "Pinned from The Dragon Vol. III No. 4 (September 1978), the Curtiss-provided scan voice (single voice: the issue-18 source is the uploaded Dm18.pdf with its mistral-ocr transcript; no archive.org djvu cross-check exists for issue 18). PRINT FOLIO = PDF PAGE MINUS TWO, verified at the page feet (folios 3, 9, 13, 14, 19, 21, 24 and 31 print at the PDF pages 5, 11, 15, 16, 21, 23, 26 and 33). The chains of this round: Insanity by Kevin Thompson (print 9, PDF 11); Magic: Governed by Laws of Theory by Thomas A. McCloud (print 14 + 19, PDF 16 + 21, its continuation sharing print 19 with the godgame); The Chamber of the Godgame by Mick McAllister (print 19, PDF 21); the unsigned Non-Player Character Statistics (print 31-32, PDF 33-34). The pin IS the conversion: OD&D-era ink adjudicated to 1e terms, the conversion noted, never silent; Dragon pins ride a VARIANT layer with provenance, never core canon.",
      "sentinel" = "Print quirks pinned AS SCANNED, noted never silent: the work-quality table jumps from the 01-02 band to 21-99 - the 03-20 band never prints, the gap flagged as scanned; the greed bands print the odd compound forms (96 - 00 + 4, 00 + 5 to + 9 and the rest) - each pins its own row; the pride 00 band pins as the 100 percentile cell; the insanity chart carries the odd 12 at the wisdom 9-12 by intelligence 9-12 crossing (higher than both neighboring columns - pinned as printed, the odd bump noted); no numeric cell garbles beyond that, so no table cell rides a sentinel this round.",
    },
  "consts" = { {
      "name" = "psyInsWisBands",
      "value" = 9,
      "comment" = "the insanity saving-throw chart rows - nine wisdom bands from less than 3 to over 18 (print 9, PDF 11)",
    }, {
      "name" = "psyInsIntBands",
      "value" = 6,
      "comment" = "the chart columns - six intelligence bands from less than 3 to over 18 (print 9)",
    }, {
      "name" = "psyInsSaveDieSides",
      "value" = 20,
      "comment" = "the insanity save rolls a twenty-sided die against the chart number plus level (print 9)",
    }, {
      "name" = "psyInsChartDieSides",
      "value" = 12,
      "comment" = "a failed save rolls the twelve-entry insanity chart on a twelve-sided die (print 9)",
    }, {
      "name" = "psyInsChartEntries",
      "value" = 12,
      "comment" = "the insanity chart carries twelve psychoses, Nutty through Catatonic (print 9)",
    }, {
      "name" = "psyInsSchizoidDieSides",
      "value" = 10,
      "comment" = "the schizoid personality rolls a ten-sided die each turn (print 9)",
    }, {
      "name" = "psyInsSchizoidRevertRoll",
      "value" = 1,
      "comment" = "a 1 on the schizoid die reverts to the other personality (print 9)",
    }, {
      "name" = "psyInsSuicideDieSides",
      "value" = 6,
      "comment" = "the suicidal victim rolls a six-sided die at each harrowing or deadly problem (print 9)",
    }, {
      "name" = "psyInsSuicideAttemptRoll",
      "value" = 1,
      "comment" = "a 1 on the suicide die means he attempts to kill himself (print 9)",
    }, {
      "name" = "psyInsSaveRows",
      "value" = 9,
      "comment" = "the psySave table row count (print 9)",
    }, {
      "name" = "psyPrideRows",
      "value" = 9,
      "comment" = "the pride table row count - nine bands from 01 to 00 (print 31)",
    }, {
      "name" = "psyGreedRows",
      "value" = 11,
      "comment" = "the greed table row count - eleven bands from any negative to 00 + 20 (print 31)",
    }, {
      "name" = "psyLawCount",
      "value" = 6,
      "comment" = "the theory of magic runs six laws: Similarity, Contagion, Mana, Artistry, Obscurity and Harmony (print 14, PDF 16)",
    }, {
      "name" = "psyActParts",
      "value" = 3,
      "comment" = "every act of magic has three parts: the spell, the rite and the condition of the magician (print 14)",
    }, {
      "name" = "psyLawFatigueDieSides",
      "value" = 20,
      "comment" = "the fatigue-factor cast check rolls a twenty-sided die against the fatigue-adjusted intelligence (print 19, PDF 21)",
    }, {
      "name" = "psyContestJudges",
      "value" = 3,
      "comment" = "the Kemble magic contest scores by three judges (print 19)",
    }, {
      "name" = "psyContestPointsMin",
      "value" = 1,
      "comment" = "each contest judge awards 1-10 points (print 19)",
    }, {
      "name" = "psyContestPointsMax",
      "value" = 10,
      "comment" = "each contest judge awards 1-10 points, the ceiling (print 19)",
    }, {
      "name" = "psyContestCategories",
      "value" = 2,
      "comment" = "the contest runs two categories: Implementation of Standard Spells and Original Spells (print 19)",
    }, {
      "name" = "psyContestSimilarityMin",
      "value" = 1,
      "comment" = "to be effective each contest spell must invoke at least one similarity (print 19)",
    }, {
      "name" = "psyGodDiceCount",
      "value" = 4,
      "comment" = "the chamber table carries a set of 4 DG - four dice (print 19, PDF 21)",
    }, {
      "name" = "psyGodLosingRoll",
      "value" = 1,
      "comment" = "rolling a one on the selected die fulfills the Hazard - the die goes in the mouth (print 19)",
    }, {
      "name" = "psyGodTreasureShareX",
      "value" = 2,
      "comment" = "the self-sacrifice recompense: a treasure equal to 2x a share of what the party brings out (print 19)",
    }, {
      "name" = "psyGodXpShareXLow",
      "value" = 2,
      "comment" = "the experience recompense runs 2 or 3x those accumulated by the others (print 19)",
    }, {
      "name" = "psyGodXpShareXHigh",
      "value" = 3,
      "comment" = "the experience recompense ceiling, 3x (print 19)",
    }, {
      "name" = "psyGodExPartyGold",
      "value" = 4000,
      "comment" = "the worked example: the four come out with 4,000 GP (print 19)",
    }, {
      "name" = "psyGodExPartyXp",
      "value" = 1500,
      "comment" = "the worked example: 1,500 experience points each (print 19)",
    }, {
      "name" = "psyGodExShareGold",
      "value" = 1000,
      "comment" = "the example party share: 1,000 GP each (print 19)",
    }, {
      "name" = "psyGodExShareXp",
      "value" = 375,
      "comment" = "the example party share: 375 EP each (print 19)",
    }, {
      "name" = "psyGodExRewardGold",
      "value" = 2000,
      "comment" = "the example recompense: Malcolm is given 2,000 GP by the Godgame Master (print 19)",
    }, {
      "name" = "psyGodExRewardXp",
      "value" = 1125,
      "comment" = "the example recompense: 1,125 EP - the 3x share (print 19)",
    }, {
      "name" = "psyGodSoloDiceCount",
      "value" = 4,
      "comment" = "the solitary variant: four dice on the table (print 19)",
    }, {
      "name" = "psyNpcGreedBaseMethodSubtract",
      "value" = 10,
      "comment" = "the base percentage method: roll greed as normal, then subtract ten and note the result (print 32, PDF 34)",
    }, {
      "name" = "psyNpcGreedDieSides",
      "value" = 20,
      "comment" = "the base percentage method rolls a twenty-sided die and adds it to the base (print 32)",
    }, {
      "name" = "psyNpcGreedCapPlus",
      "value" = 20,
      "comment" = "greed never exceeds 00 + 20 (print 32)",
    }, {
      "name" = "psyNpcShopkeeperGreedFloor",
      "value" = 20,
      "comment" = "shop-owners never have a greed below 20 (print 32)",
    }, {
      "name" = "psyNpcSpyPrideFloor",
      "value" = 8,
      "comment" = "spies never have a pride factor below 08 (print 32)",
    }, {
      "name" = "psyNpcThiefGreedFloor",
      "value" = 21,
      "comment" = "hired thieves tend to be greedy, with a greed factor above 21 (print 32)",
    }, {
      "name" = "psyNpcArmorerPrideFloor",
      "value" = 13,
      "comment" = "armorers have a pride factor above 13 (print 32)",
    }, {
      "name" = "psyNpcInterestNormalPercent",
      "value" = 5,
      "comment" = "the greed column doubles as interest demanded per game year: normal greed 5 percent (print 32)",
    }, {
      "name" = "psyNpcInterestDoublePercent",
      "value" = 100,
      "comment" = "a double-price greed demands 100 percent interest, the printed correspondence (print 32)",
    }, {
      "name" = "psyNpcInterestZeroPercent",
      "value" = 0,
      "comment" = "fraction greed demands 0 percent interest (print 32)",
    }, {
      "name" = "psyWorkTrashUsesDieMax",
      "value" = 6,
      "comment" = "the below-01 work quality: trash falls apart in 1-6 uses (print 32)",
    }, {
      "name" = "psyWorkTrashPricePercent",
      "value" = 10,
      "comment" = "the trash work is worth about 1/10 price (print 32)",
    }, {
      "name" = "psyWorkCheapPriceMinPercent",
      "value" = 20,
      "comment" = "the 01-02 cheap work is worth 1/5 to 1/2 price - the floor 20 percent (print 32)",
    }, {
      "name" = "psyWorkCheapPriceMaxPercent",
      "value" = 50,
      "comment" = "the cheap work price ceiling, 50 percent (print 32)",
    }, {
      "name" = "psyWorkCheapLifespanPercent",
      "value" = 50,
      "comment" = "the cheap work wears out in half the normal time, 50 percent (print 32)",
    }, {
      "name" = "psyWorkNormalPricePercent",
      "value" = 100,
      "comment" = "the 21-99 band is normal work, 100 percent (print 32)",
    }, {
      "name" = "psyWorkSturdyLifespanPercent",
      "value" = 200,
      "comment" = "the 00-00+5 sturdy work lasts twice as long as normal (print 32)",
    }, {
      "name" = "psyWorkSturdyPricePercent",
      "value" = 250,
      "comment" = "the sturdy work is worth up to 2-1/2 times normal price, 250 percent (print 32)",
    } },
  "bools" = { {
      "name" = "psyInsIntBelowWisVulnerable",
      "value" = true,
      "comment" = "where intelligence is less than wisdom there is lesser knowledge and more vulnerability to insanity (print 9)",
    }, {
      "name" = "psyInsIntAboveWisMoreSusceptible",
      "value" = true,
      "comment" = "a higher intelligence than wisdom carries even greater susceptibility - facts understood without the judgment to place them (print 9)",
    }, {
      "name" = "psyInsLevelAddedToSave",
      "value" = true,
      "comment" = "the character level, at least 1, is added to the chart number before the save roll (print 9)",
    }, {
      "name" = "psyInsSaveRollLowAvoids",
      "value" = true,
      "comment" = "a die roll at or under the adjusted number avoids insanity (print 9)",
    }, {
      "name" = "psyInsPsychosesNotImmediate",
      "value" = true,
      "comment" = "none of the psychoses are evident immediately unless otherwise stated (print 9)",
    }, {
      "name" = "psyInsGibberingImmediate",
      "value" = true,
      "comment" = "the gibbering state is obvious immediately (print 9)",
    }, {
      "name" = "psyInsViolentImmediate",
      "value" = true,
      "comment" = "the violent state is obvious immediately (print 9)",
    }, {
      "name" = "psyInsCatatonicImmediate",
      "value" = true,
      "comment" = "the catatonic state is obvious immediately (print 9)",
    }, {
      "name" = "psyInsMagicFunctionalExcept",
      "value" = true,
      "comment" = "all magic and clerical abilities stay functional except when gibbering or catatonic (print 9)",
    }, {
      "name" = "psyInsSchizoidNoPhysicalChange",
      "value" = true,
      "comment" = "the schizoid split personality has no physical changes - it is all in the mind and actions, one personality not remembering the other (print 9)",
    }, {
      "name" = "psyInsCausesDmSet",
      "value" = true,
      "comment" = "the cause of insanity is the DM call - chests, rings, horns, failed responsibility, mindbending creatures like a lich or demon (print 9)",
    }, {
      "name" = "psyInsNutty",
      "value" = true,
      "comment" = "chart entry 1 - Nutty: slightly silly, eccentric, odd ideas and plans (print 9)",
    }, {
      "name" = "psyInsKleptomaniac",
      "value" = true,
      "comment" = "chart entry 2 - Kleptomaniac: compulsive thief with no thief abilities, sneaks small objects without regard to value (print 9)",
    }, {
      "name" = "psyInsPerverse",
      "value" = true,
      "comment" = "chart entry 3 - Perverse: pleasure in the gruesome, dismemberment a casual result, mad laughter (print 9)",
    }, {
      "name" = "psyInsPsychoticHatred",
      "value" = true,
      "comment" = "chart entry 4 - Psychotic Hatred: immediate deadly actions against the chosen type - magic users, warriors, clerics, thieves, monks, rangers, men, women, elves, dwarves, hobbits, giants, royalty, police-types, witches, tall, short, bearded, rich, peasants, leaders, opposing alliance (print 9)",
    }, {
      "name" = "psyInsChildlikeTrusting",
      "value" = true,
      "comment" = "chart entry 5 - Childlike Trusting: total gullibility, believes anyone (print 9)",
    }, {
      "name" = "psyInsSchizoid",
      "value" = true,
      "comment" = "chart entry 6 - Schizoid: split personality, the young-old, violent-gentle, arrogant-shy, confident-unsure, brave-coward, male-female, lawful-chaotic, good-evil, generous-greedy, trusting-paranoid, honest-secretive, trustworthy-untrustworthy pairs (print 9)",
    }, {
      "name" = "psyInsSevereParanoia",
      "value" = true,
      "comment" = "chart entry 7 - Severe Paranoia: trusts no one, may kill in self defense on sudden moves, every whisper is about him (print 9)",
    }, {
      "name" = "psyInsAcuteParanoia",
      "value" = true,
      "comment" = "chart entry 8 - Acute Paranoia: convinced everyone wants to kill him immediately, tries to escape or kill (print 9)",
    }, {
      "name" = "psyInsGibbering",
      "value" = true,
      "comment" = "chart entry 9 - Gibbering: walks, eats and sleeps but is otherwise totally useless, cannot find his own food (print 9)",
    }, {
      "name" = "psyInsSuicidal",
      "value" = true,
      "comment" = "chart entry 10 - Suicidal: attempts his own life on a 1 of 6 at any harrowing problem (print 9)",
    }, {
      "name" = "psyInsViolent",
      "value" = true,
      "comment" = "chart entry 11 - Violent: tries to kill as many as he can as fast as he can, not clever, just deadly (print 9)",
    }, {
      "name" = "psyInsCatatonic",
      "value" = true,
      "comment" = "chart entry 12 - Catatonic: sits doing nothing, will not eat, talk or move, ignores all outside stimuli including pain (print 9)",
    }, {
      "name" = "psyLawSimilarity",
      "value" = true,
      "comment" = "the Law of Similarity - an effect resembles its cause, the voodoo doll and the Hand of Glory (print 14)",
    }, {
      "name" = "psyLawContagion",
      "value" = true,
      "comment" = "the Law of Contagion - things once joined, when separated, remember each other and remain effectively similar - the hair clippings and the cooled weapon (print 14)",
    }, {
      "name" = "psyLawMana",
      "value" = true,
      "comment" = "the Law of Mana - magic power is based on a mysterious supernatural force, with no consensus on how it works (print 14)",
    }, {
      "name" = "psyLawArtistry",
      "value" = true,
      "comment" = "the Law of Artistry, the McCloud own-dungeon law - mana derives from art, good or evil (print 14)",
    }, {
      "name" = "psyLawObscurity",
      "value" = true,
      "comment" = "the Law of Obscurity - potency is proportional to abstrusity, the strange ingredients and the arcane languages (print 14)",
    }, {
      "name" = "psyLawHarmony",
      "value" = true,
      "comment" = "the Law of Harmony - the balance of the universe must be maintained, a price is paid for the use of magic (print 14)",
    }, {
      "name" = "psyActPartSpell",
      "value" = true,
      "comment" = "the spell - the words recited - is by far the most important part, the spoken word is always used (print 14)",
    }, {
      "name" = "psyActPartRite",
      "value" = true,
      "comment" = "the rite - the actions and gestures - gives the magic direction, the wand is a pointer (print 14)",
    }, {
      "name" = "psyActPartCondition",
      "value" = true,
      "comment" = "the condition of the performer - taboos avoided, emotions raised, and the level appropriate for the magic (print 14)",
    }, {
      "name" = "psyLawSpellMustDescribeSimilarity",
      "value" = true,
      "comment" = "the spell must above all describe the similarities invoked (print 14)",
    }, {
      "name" = "psyLawFatigueSubtractsAll",
      "value" = true,
      "comment" = "the fatigue factor is subtracted from all characteristics, including intelligence (print 19)",
    }, {
      "name" = "psyLawFatigueBackfire",
      "value" = true,
      "comment" = "a fatigue roll higher than the adjusted intelligence means the spell was done wrong and may backfire (print 19)",
    }, {
      "name" = "psyLawSpellPoetic",
      "value" = true,
      "comment" = "the dungeon spell should be poetic, use archaic language and refer to the mana sources - assists but not necessary (print 14)",
    }, {
      "name" = "psyContestWrittenSpellRequired",
      "value" = true,
      "comment" = "the contest entrant gives the DM a written copy of the spell with the exact words and the rite gestures (print 19)",
    }, {
      "name" = "psyContestFleshGolems",
      "value" = true,
      "comment" = "flesh golems are provided as lawful targets for combat magic (print 19)",
    }, {
      "name" = "psyContestNoBlackMagic",
      "value" = true,
      "comment" = "no purely black magic is allowed at the contest (print 19)",
    }, {
      "name" = "psyContestResurrected",
      "value" = true,
      "comment" = "anyone killed at the contest will be resurrected if possible (print 19)",
    }, {
      "name" = "psyContestSpectatorsOwnHazard",
      "value" = true,
      "comment" = "all spectators view the proceedings at their own hazard (print 19)",
    }, {
      "name" = "psyGodCyanideDie",
      "value" = true,
      "comment" = "each die contains a cyanide syrup which kills painlessly and instantaneously when bitten (print 19)",
    }, {
      "name" = "psyGodDoorOpensOnFulfillment",
      "value" = true,
      "comment" = "the door opens the moment the terms of the Hazard are fulfilled (print 19)",
    }, {
      "name" = "psyGodEscapeProof",
      "value" = true,
      "comment" = "the chamber defeats Knock, Dispel Magic, Dimension Door, Pass-Wall and Teleport - there is only one way out (print 19)",
    }, {
      "name" = "psyGodScrollMayLie",
      "value" = true,
      "comment" = "the variants are posited on the probability that the scroll contains one or more falsehoods (print 19)",
    }, {
      "name" = "psyGodBenignSuspension",
      "value" = true,
      "comment" = "the benign variant puts the volunteer in suspended animation and teleports him outside to wait (print 19)",
    }, {
      "name" = "psyGodRewardXpAndTreasure",
      "value" = true,
      "comment" = "the volunteer is rewarded with both experience and treasure - he believed he had given up both (print 19)",
    }, {
      "name" = "psyGodEvilRansom",
      "value" = true,
      "comment" = "an evil magician honors the agreement, accepting one life as ransom of the others (print 19)",
    }, {
      "name" = "psyGodEvilPartySelect",
      "value" = true,
      "comment" = "the more evil variant lets the party select the victim themselves, without the voluntary agreement (print 19)",
    }, {
      "name" = "psyGodNeutralPunishesCoercers",
      "value" = true,
      "comment" = "a benign or neutral Power punishes a party coercing a weaker member into submitting (print 19)",
    }, {
      "name" = "psyGodNeutralCoercerDies",
      "value" = true,
      "comment" = "the Neutral Godgame Master slays the coercer in the victim place at the fulfillment of Hazard (print 19)",
    }, {
      "name" = "psyGodNeutralSlayOrFree",
      "value" = true,
      "comment" = "the Neutral GM might slay them all - or set them all free, the die not poisoned, to finish in mutual distrust (print 19)",
    }, {
      "name" = "psyGodUnpoisonedVariant",
      "value" = true,
      "comment" = "the benign possibilities: the die not poisoned after all, a secret door revealing treasure, or the shortest path cleared and lighted (print 19)",
    }, {
      "name" = "psyGodSoloCrushedDie",
      "value" = true,
      "comment" = "the solitary variant: a device crushes one die releasing the odor of bitter almonds, the scroll claims only one other die is poisoned (print 19)",
    }, {
      "name" = "psyGodLoadedDiceOption",
      "value" = true,
      "comment" = "the loaded-dice option: the DM rolls secretly for the character or buys loaded dice at a novelty shop (print 19)",
    }, {
      "name" = "psyPrideRolledOnce",
      "value" = true,
      "comment" = "the pride ego factor is rolled once and left unaltered (print 32)",
    }, {
      "name" = "psyGreedBaseMethodOption",
      "value" = true,
      "comment" = "greed can be rolled like pride, or by the referee base percentage method (print 32)",
    }, {
      "name" = "psyWorkRolledPerItem",
      "value" = true,
      "comment" = "the quality of work is rolled once per item (print 32)",
    }, {
      "name" = "psyNpcBarteringHirelingWages",
      "value" = true,
      "comment" = "with these statistics bartering becomes part of the game, especially with hirelings wages (print 32)",
    }, {
      "name" = "psyWorkCheapBandGap",
      "value" = true,
      "comment" = "the work quality table jumps from the 01-02 band to 21-99 - the 03-20 band never prints, noted as scanned (print 32)",
    }, {
      "name" = "psyNpcGreedShareDoctrine",
      "value" = true,
      "comment" = "the greed percentage is the share of due treasure a hireling will accept or demand - the -15 example takes 5 GP of 50, the 00+20 demands 150 GP of a 50 GP share (print 31-32)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "psySave",
      "tag" = "Ps",
      "count" = "psyInsSaveRows",
      "sentinel" = -99,
      "audit_comment" = "the insanity saving-throw chart - nine wisdom bands down, six intelligence bands across, the unadjusted save number before the level is added; roll that number or less on the d20 to avoid (print 9, PDF 11)",
      "cols" = { "psySaveIntLt3", "psySaveInt3to8", "psySaveInt9to12", "psySaveInt13to15", "psySaveInt16to18", "psySaveIntOver18" },
      "col_comments" = { "the intelligence band less than 3: 7, 8, 9, 10, 11, 12, 13, 14 and 15 down the nine wisdom bands (print 9)", "the intelligence band 3-8: 5, 9, 10, 11, 12, 13, 14, 15 and 16 (print 9)", "the intelligence band 9-12: 3, 7, 8, the odd 12 at wisdom 9-12, 13, 14, 15, 16 and 17 - the bump higher than both neighboring columns, pinned as printed (print 9)", "the intelligence band 13-15: 1, 5, 6, 10, 14, 15, 16, 17 and 18 (print 9)", "the intelligence band 16-18: -2, 2, 3, 7, 11, 12, 17, 18 and 19 (print 9)", "the intelligence band over 18: -5, -1, 0, 4, 8, 9, 14, 15 and 20 (print 9)" },
      "data" = { { 7, 5, 3, 1, -2, -5 }, { 8, 9, 7, 5, 2, -1 }, { 9, 10, 8, 6, 3, 0 }, { 10, 11, 12, 10, 7, 4 }, { 11, 12, 13, 14, 11, 8 }, { 12, 13, 14, 15, 12, 9 }, { 13, 14, 15, 16, 17, 14 }, { 14, 15, 16, 17, 18, 15 }, { 15, 16, 17, 18, 19, 20 } },
    }, {
      "name" = "psyPride",
      "tag" = "Pp",
      "count" = "psyPrideRows",
      "sentinel" = -99,
      "audit_comment" = "the pride ego table - nine percentile bands with the charisma and constitution modifiers and the greed and work-quality percent adjustments; the 00 band is the egomaniac (print 31, PDF 33)",
      "cols" = { "psyPrideLo", "psyPrideHi", "psyPrideChr", "psyPrideCons", "psyPrideGreedPct", "psyPrideWorkPct" },
      "col_comments" = { "the band floor on the percentile dice (print 31)", "the band ceiling - 100 carries the 00 print (print 31)", "the charisma modifier - vain -1, egotist -2, egomaniac -3, the 90-91 well-being +1 (print 31)", "the constitution modifier - the 01 band -1, the well-being and vain and egotist and egomaniac bands +1 (print 31)", "the greed percent adjustment, -15 at 01 up to +20 at 00 (print 31)", "the work quality percent adjustment, -5 at 01 to +5 at 92-93 (print 31)" },
      "data" = { { 1, 1, 0, -1, -15, -5 }, { 2, 7, 0, 0, -10, -1 }, { 8, 13, 0, 0, -5, 0 }, { 14, 89, 0, 0, 0, 0 }, { 90, 91, 1, 1, 0, 0 }, { 92, 93, 0, 1, 5, 5 }, { 94, 98, -1, 1, 10, 2 }, { 99, 99, -2, 1, 15, 0 }, { 100, 100, -3, 1, 20, 0 } },
    }, {
      "name" = "psyGreed",
      "tag" = "Pg",
      "count" = "psyGreedRows",
      "sentinel" = -99,
      "audit_comment" = "the greed table - eleven bands from any negative to 00 + 20: the loan chance as a numerator over denominator (0/0 gives away, 1/1 loans freely, 2/3, 1/3, 1/6, 1/12 and 1/20 may-loan chances, 0/1 never loans) and the selling price as a percent of normal (10 through 300) (print 31, PDF 33)",
      "cols" = { "psyGreedLoanNum", "psyGreedLoanDen", "psyGreedPricePercent" },
      "col_comments" = { "the loan chance numerator - 0 with den 0 gives things away, 0 with den 1 never loans (print 31)", "the loan chance denominator - 3, 6, 12 and 20 for the may-loan bands (print 31)", "the selling price in percent of normal - 1/10 at negative, 1/5 at zero, 1/2 at 01-20, normal, +10, +20, +50, double, 2-1/2 and triple at 00 + 20 (print 31)" },
      "data" = { { 0, 0, 10 }, { 0, 0, 20 }, { 1, 1, 50 }, { 1, 1, 100 }, { 2, 3, 100 }, { 1, 3, 110 }, { 1, 6, 120 }, { 1, 12, 150 }, { 1, 20, 200 }, { 0, 1, 250 }, { 0, 1, 300 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['psySaveIntLt3'](0) != 7 or m['psySaveIntLt3'](8) != 15 or m['psySaveInt9to12'](3) != 12 or m['psySaveInt16to18'](6) != 17 or m['psySaveIntOver18'](8) != 20 or m['psyInsSaveDieSides']() != 20 or m['psyInsChartDieSides']() != 12 or m['psyInsWisBands']() != 9 or m['psyInsIntBands']() != 6",
      "note" = "the insanity save chart edges - 7 and 15 on the low intelligence column, the odd 12 at wisdom 9-12 crossed with intelligence 9-12, the 17 at wisdom 17 crossed with intelligence 16-18, 20 at the far corner, the d20 and d12, the 9x6 bands (print 9)",
    }, {
      "expr" = "m['psyInsSchizoidDieSides']() != 10 or m['psyInsSchizoidRevertRoll']() != 1 or m['psyInsSuicideDieSides']() != 6 or m['psyInsSuicideAttemptRoll']() != 1 or m['psyInsChartEntries']() != 12",
      "note" = "the per-psychosis doctrine - the schizoid d10 reverting on 1 each turn, the suicidal d6 attempt on 1, the twelve chart entries (print 9)",
    }, {
      "expr" = "m['psyLawCount']() != 6 or m['psyActParts']() != 3 or m['psyLawFatigueDieSides']() != 20 or m['psyContestJudges']() != 3 or m['psyContestPointsMin']() != 1 or m['psyContestPointsMax']() != 10 or m['psyContestCategories']() != 2 or m['psyContestSimilarityMin']() != 1",
      "note" = "the magic theory - six laws, three act parts, the d20 fatigue check, the Kemble contest with its three judges awarding 1-10 in two categories, the one-similarity minimum (print 14 + 19)",
    }, {
      "expr" = "m['psyGodDiceCount']() != 4 or m['psyGodLosingRoll']() != 1 or m['psyGodTreasureShareX']() != 2 or m['psyGodXpShareXLow']() != 2 or m['psyGodXpShareXHigh']() != 3 or m['psyGodExPartyGold']() != 4000 or m['psyGodExPartyXp']() != 1500 or m['psyGodExShareGold']() != 1000 or m['psyGodExShareXp']() != 375 or m['psyGodExRewardGold']() != 2000 or m['psyGodExRewardXp']() != 1125 or m['psyGodSoloDiceCount']() != 4",
      "note" = "the godgame - four dice, the 1 roll, the 2x treasure and 2-or-3x experience recompense, the worked 4,000 GP / 1,500 EP example with its 1,000/375 shares and the 2,000 GP / 1,125 EP reward, the four-dice solo variant (print 19)",
    }, {
      "expr" = "m['psyPrideLo'](0) != 1 or m['psyPrideHi'](0) != 1 or m['psyPrideCons'](0) != -1 or m['psyPrideGreedPct'](0) != -15 or m['psyPrideWorkPct'](0) != -5 or m['psyPrideChr'](8) != -3 or m['psyPrideGreedPct'](8) != 20 or m['psyPrideChr'](6) != -1 or m['psyPrideCons'](6) != 1 or m['psyPrideWorkPct'](5) != 5 or m['psyPrideGreedPct'](6) != 10",
      "note" = "the pride bands - the 01 none with its -1 cons, -15 greed and -5 work, the 00 egomaniac -3 chr and +20 greed, the 94-98 vain -1 chr, the 92-93 well-being +1 cons and +5 work (print 31)",
    }, {
      "expr" = "m['psyGreedLoanNum'](0) != 0 or m['psyGreedLoanDen'](0) != 0 or m['psyGreedPricePercent'](0) != 10 or m['psyGreedLoanNum'](4) != 2 or m['psyGreedLoanDen'](4) != 3 or m['psyGreedPricePercent'](4) != 100 or m['psyGreedLoanNum'](7) != 1 or m['psyGreedLoanDen'](7) != 12 or m['psyGreedPricePercent'](7) != 150 or m['psyGreedLoanNum'](10) != 0 or m['psyGreedLoanDen'](10) != 1 or m['psyGreedPricePercent'](10) != 300",
      "note" = "the greed bands - gives-away at negative and zero with 1/10 and 1/5 prices, the 2/3 may-loan at 85-95, the 1/12 chance at 00+10-14 with +50 percent, the never-loan 00+20 triple price (print 31)",
    }, {
      "expr" = "m['psyNpcGreedBaseMethodSubtract']() != 10 or m['psyNpcGreedDieSides']() != 20 or m['psyNpcGreedCapPlus']() != 20 or m['psyNpcShopkeeperGreedFloor']() != 20 or m['psyNpcSpyPrideFloor']() != 8 or m['psyNpcThiefGreedFloor']() != 21 or m['psyNpcArmorerPrideFloor']() != 13 or m['psyNpcInterestNormalPercent']() != 5 or m['psyNpcInterestDoublePercent']() != 100",
      "note" = "the NPC doctrine - the base method subtract-10 with the d20 add and the 00+20 cap, the shop-owner 20, spy 08, thief 21 and armorer 13 floors, the 5 and 100 percent interest correspondences (print 32)",
    }, {
      "expr" = "m['psyWorkTrashUsesDieMax']() != 6 or m['psyWorkTrashPricePercent']() != 10 or m['psyWorkCheapPriceMinPercent']() != 20 or m['psyWorkCheapPriceMaxPercent']() != 50 or m['psyWorkCheapLifespanPercent']() != 50 or m['psyWorkNormalPricePercent']() != 100 or m['psyWorkSturdyLifespanPercent']() != 200 or m['psyWorkSturdyPricePercent']() != 250",
      "note" = "the work quality bands - trash at 1-6 uses and 1/10 price, the cheap 1/5-to-1/2 at half lifespan, normal 100, the sturdy twice as long at up to 2-1/2 price (print 32)",
    } },
  "audit" = {
      "label" = "R934 issue-18 opener part one audit",
      "comment" = "THE DRAGON ISSUE-18 OPENER PART ONE - the four system and doctrine chains of the issue. CHAIN ONE, Insanity or Why Is My Character Eating Leaves by Kevin Thompson (print 9, PDF 11): the 9x6 insanity saving-throw chart (nine wisdom bands crossed with six intelligence bands, the unadjusted number, the level added, the d20 roll), the twelve-type insanity chart (Nutty, Kleptomaniac, Perverse, Psychotic Hatred, Childlike Trusting, Schizoid, Severe Paranoia, Acute Paranoia, Gibbering, Suicidal, Violent, Catatonic) with the per-type doctrine (the schizoid d10 each turn reverting on 1, the suicidal d6 attempt on 1, the immediate gibbering, violent and catatonic states, the magic staying functional except when gibbering or catatonic). CHAIN TWO, Magic: Governed by Laws of Theory by Thomas A. McCloud (print 14 + 19, PDF 16 + 21): the six laws (Similarity, Contagion, Mana, Artistry, Obscurity, Harmony), the three parts of the act (the spell, the rite, the condition), the fatigue-factor cast check (the d20 against the fatigue-adjusted intelligence, the backfire on a high roll), and the Kemble magic contest rules (three judges at 1-10 points, two categories, the one-similarity minimum, the flesh golems, the no-black-magic rule). CHAIN THREE, The Chamber of the Godgame by Mick McAllister (print 19, PDF 21): the four-dice hazard (the cyanide die, the 1 roll, the door opening on fulfillment, the escape-proof chamber), the benign, evil and neutral Godgame Master variants, the recompense doctrine (the 2x treasure share, the 2-or-3x experience share, the worked 4,000 GP / 1,500 EP example with its 1,000/375 shares and the 2,000/1,125 reward), the loaded-dice option and the four-dice solitary variant with its crushed-die bitter almonds. CHAIN FOUR, the Non-Player Character Statistics (print 31-32, PDF 33-34): the nine-band pride table (the charisma, constitution, greed-percent and work-percent modifiers from the 01 none band to the 00 egomaniac), the eleven-band greed table (the loan chances and the selling prices from gives-away at 1/10 to never-loans at triple price), the four-band work-quality table (trash at 1-6 uses and 1/10 price, the cheap 1/5-to-1/2 at half lifespan, normal, the sturdy twice-as-long at up to 2-1/2 price), the base percentage method (subtract ten, add the d20, the 00+20 cap), the interest correspondences (0, 5 and 100 percent) and the NPC restriction floors (shop-owner greed 20, spy pride 08, hired thief greed above 21, armorer pride above 13). The pin IS the conversion: OD&D-era ink adjudicated to 1e terms, noted never silent; the as-scanned quirks ride the comments and the transcripts.",
    },
}
