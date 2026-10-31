-- wmn: promoted from tools/spec_r895.json (the The issue-3 opener - Lakofka's Notes on Women & Magic: Bringing the Distaff Gamer into D&D (folios 7-10));
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 895,
  "prefix" = "wmn",
  "banner" = {
      "title" = "The issue-3 opener - Lakofka's Notes on Women & Magic: Bringing the Distaff Gamer into D&D (folios 7-10)",
      "provenance" = "Pinned from The Dragon Vol. 1 No. 3 (October 1976): folios 7-10, Len Lakofka's Notes on Women & Magic - the Beauty attribute on two 1-10 twenty-siders, the four female class ladders to War Lady, Matriarch, Sibyl and Witch 22nd, the Seduction and Charm Men and Charm Humanoid Monster spell family with the beauty matrix and the save ladders, the Horrid Beauty tiers, Poison, Magic Mount, Mind Meld, Spirit and the chaotic cleric Worship. The opener round also seats the issue voice: all 32 folio pages committed as the transcript, and the issue-3 gap report ships pre-flip. The folio-3 War of the Empires wargame history and all fiction and ads are scoped out per the R895 adjudication.",
      "sentinel" = "The variant-layer doctrine holds: Dragon ink is never core 1e canon. The printed hit-dice forms X+Y are CONVERTED to base-plus-bonus columns, the conversion noted; the 1.8x maximum load pins as 18 tenths; the folio-7 strength line garbles in OCR as '18 sided die' and pins as 1d8+1d6 per the folio-8 range 2-14, never silent. The beauty matrix, the Witch-grid odd hit-dice cells (10+4, 11+7) and the ugly-tier flee sign ride AS SCANNED - no figure pixels ride the OCR artifact to verify against - the honest boundary pinned beside each. OD&D-era ink converted per the walk doctrine: the pin IS the conversion, noted, never silent.",
    },
  "consts" = { {
      "name" = "wmnBeautyDiceCount",
      "value" = 2,
      "comment" = "BEAUTY replaces Charisma for women, rated on TWO twenty-sided dice (folio 7)",
    }, {
      "name" = "wmnBeautyDieMax",
      "value" = 10,
      "comment" = "each beauty die is numbered one to ten, so the beauty range is 2-20, not 2-40 (folio 7)",
    }, {
      "name" = "wmnStrengthDieEight",
      "value" = 8,
      "comment" = "the woman's strength rolls one 8-sided die plus one 6-sided die - the folio-7 line garbles in OCR as \"18 sided die\", pinned as 1d8 per the folio-8 strength range 2-14, the conversion noted, never silent (folio 7)",
    }, {
      "name" = "wmnStrengthDieSix",
      "value" = 6,
      "comment" = "the second strength die is the 6-sider (folio 7)",
    }, {
      "name" = "wmnStrengthMin",
      "value" = 2,
      "comment" = "women's strength scores range from 2 (folio 8)",
    }, {
      "name" = "wmnStrengthMax",
      "value" = 14,
      "comment" = "to 14 at the top (folio 8)",
    }, {
      "name" = "wmnStrConBonusMin",
      "value" = 13,
      "comment" = "any woman scoring 13 (folio 7)",
    }, {
      "name" = "wmnStrConBonusMax",
      "value" = 14,
      "comment" = "or 14 in strength (folio 7)",
    }, {
      "name" = "wmnStrConBonus",
      "value" = 1,
      "comment" = "may add 1 to her constitution score (folio 7)",
    }, {
      "name" = "wmnThiefSpellIntMin",
      "value" = 12,
      "comment" = "to cast spells a female thief needs intelligence 12 or higher (folio 8)",
    }, {
      "name" = "wmnThiefCharmIntMin",
      "value" = 9,
      "comment" = "except Seduction, Charm Men and Charm Humanoid Monster, where intelligence 9 suffices (folio 8)",
    }, {
      "name" = "wmnThiefCharmBeautyMin",
      "value" = 13,
      "comment" = "the thief casting those three spells must also carry a beauty score of 13 or better (folio 8)",
    }, {
      "name" = "wmnEncumbranceBase",
      "value" = 1000,
      "comment" = "women are allowed 1000 points of encumbrance (folio 8)",
    }, {
      "name" = "wmnEncumbrancePerStr",
      "value" = 50,
      "comment" = "plus fifty times the strength rating, at no movement loss (folio 8)",
    }, {
      "name" = "wmnMaxLoadTenths",
      "value" = 18,
      "comment" = "maximum load is 1.8 times the encumbrance score - pinned as 18 tenths, the decimal-to-integer conversion noted (folio 8)",
    }, {
      "name" = "wmnGroupOnePenalty",
      "value" = 1,
      "comment" = "women of strength 10 or lower wield flail, battle axes and morning stars at -1 (folio 8)",
    }, {
      "name" = "wmnGroupTwoPenaltyTen",
      "value" = 2,
      "comment" = "and at strength 10 or lower the pole arms, halberd, pike and two-handed sword go at -2 (folio 8)",
    }, {
      "name" = "wmnGroupTwoPenaltyTwelve",
      "value" = 1,
      "comment" = "women of strength 12 or lower wield only that latter group at -1 (folio 8)",
    }, {
      "name" = "wmnDaggerBonus",
      "value" = 1,
      "comment" = "ALL WOMEN wield a dagger at an additional +1 (folio 8)",
    }, {
      "name" = "wmnPlateFatigueTen",
      "value" = 20,
      "comment" = "plate armor carries a 20 percent greater fatigue rating in women of strength 10 or lower (folio 8)",
    }, {
      "name" = "wmnPlateFatigueTwelve",
      "value" = 10,
      "comment" = "and 10 percent at strength 11 or 12 (folio 8)",
    }, {
      "name" = "wmnChainFatigueEleven",
      "value" = 10,
      "comment" = "chainmail has a 10 percent greater fatigue factor in women of strength 11 or lower (folio 8)",
    }, {
      "name" = "wmnWitchEqualLevel",
      "value" = 13,
      "comment" = "female magic users go without limit; from Witch level 13 they equal Wizard level 13 (folio 8)",
    }, {
      "name" = "wmnSeduceRangeFeet",
      "value" = 6,
      "comment" = "the seduction spell's range is six feet, one figure at a time (folio 9)",
    }, {
      "name" = "wmnSeduceEffectTurns",
      "value" = 2,
      "comment" = "the enchanted victim is at the lowered rate for two full turns after a first-level seduction succeeds (folio 9)",
    }, {
      "name" = "wmnSeduceAttackPenalty",
      "value" = 3,
      "comment" = "while enchanted he will attack at three levels lower (folio 9)",
    }, {
      "name" = "wmnSeduceThiefBonus",
      "value" = 2,
      "comment" = "for thieves add 2 to each beauty-matrix score (folio 9)",
    }, {
      "name" = "wmnSeduceFighterBonus",
      "value" = 4,
      "comment" = "for fighters add 4 to each beauty-matrix score (folio 9)",
    }, {
      "name" = "wmnSeduceSaveFighter",
      "value" = 13,
      "comment" = "a fighter needs a 13 or higher on the summed roll to be saved (folio 9)",
    }, {
      "name" = "wmnSeduceSaveThief",
      "value" = 12,
      "comment" = "a thief needs 12 or better (folio 9)",
    }, {
      "name" = "wmnSeduceSavePaladin",
      "value" = 10,
      "comment" = "a paladin needs 10 or better (folio 9)",
    }, {
      "name" = "wmnSeduceSaveMage",
      "value" = 9,
      "comment" = "a magic user needs 9 or better (folio 9)",
    }, {
      "name" = "wmnSeduceSaveCleric",
      "value" = 8,
      "comment" = "a cleric needs an 8 or higher to stay celibate (folio 9)",
    }, {
      "name" = "wmnCharmRangeFeet",
      "value" = 16,
      "comment" = "the Charm Men spell's range is sixteen feet (folio 9)",
    }, {
      "name" = "wmnCharmTakeoverTurns",
      "value" = 2,
      "comment" = "charmed hirelings may be taken over by the charmer after 2 turns of catatonia (folio 9)",
    }, {
      "name" = "wmnCharmBossDie",
      "value" = 8,
      "comment" = "the stronger figure attempts to prevent the charm with an 8-sided die roll (folio 9)",
    }, {
      "name" = "wmnCharmBossDispels",
      "value" = 6,
      "comment" = "a 6 or higher dispels the charm (folio 9)",
    }, {
      "name" = "wmnCharmBeautyMage",
      "value" = 11,
      "comment" = "magic users require beauty 11 to Charm Men (folio 9)",
    }, {
      "name" = "wmnCharmBeautyThief",
      "value" = 13,
      "comment" = "thieves require beauty 13 (folio 9)",
    }, {
      "name" = "wmnCharmBeautyFighter",
      "value" = 16,
      "comment" = "fighters require beauty 16 (folio 9)",
    }, {
      "name" = "wmnChmBeautyMage",
      "value" = 11,
      "comment" = "Charm Humanoid Monster needs beauty 11 or higher for magic users (folio 9)",
    }, {
      "name" = "wmnChmBeautyThiefFighter",
      "value" = 13,
      "comment" = "and 13 or higher for thieves or fighters (folio 9)",
    }, {
      "name" = "wmnChmCatatoniaDie",
      "value" = 4,
      "comment" = "the charmed male monster becomes catatonic for 1-4 turns only if not attacked (folio 9)",
    }, {
      "name" = "wmnChmBreakPercent",
      "value" = 70,
      "comment" = "any attack may break the spell, 70 percent of breaking it (folio 9)",
    }, {
      "name" = "wmnChmKillRoll",
      "value" = 8,
      "comment" = "if she tries to fight, an 8 or higher on a 20-sided die means he will try to kill her (folio 9)",
    }, {
      "name" = "wmnChmGrappleRoll",
      "value" = 9,
      "comment" = "a 9 or higher means he tries to grapple her (folio 9)",
    }, {
      "name" = "wmnChmHarmPercent",
      "value" = 50,
      "comment" = "in the grapple he may harm her, 50 percent chance (folio 9)",
    }, {
      "name" = "wmnChmLevelBonus",
      "value" = 2,
      "comment" = "vampires, gargoyles and centaurs add 2 points to their level for intelligence/wisdom (folio 10)",
    }, {
      "name" = "wmnChmCarryRollMin",
      "value" = 12,
      "comment" = "on the summed 20-sided roll a 12 (folio 9)",
    }, {
      "name" = "wmnChmCarryRollMax",
      "value" = 16,
      "comment" = "to 16 means he will carry her off; 17 or more is catatonia (folio 9)",
    }, {
      "name" = "wmnHbRangeFeet",
      "value" = 16,
      "comment" = "Horrid Beauty requires direct sight of the witch within 16 feet (folio 10)",
    }, {
      "name" = "wmnHbDurationTurns",
      "value" = 6,
      "comment" = "the Horrid Beauty duration is 6 turns, longer in the case of seduction spells (folio 10)",
    }, {
      "name" = "wmnPoisonRangeInches",
      "value" = 18,
      "comment" = "any food or water may be poisoned from up to 18 inches away (folio 10)",
    }, {
      "name" = "wmnPoisonDamagePerTurn",
      "value" = 3,
      "comment" = "the poison is deadly, inflicting 3 hits per turn with unconsciousness at once (folio 10)",
    }, {
      "name" = "wmnPoisonPurifyPct",
      "value" = 40,
      "comment" = "Purify Food & Water rids the affected food or water only 40 percent of the time (folio 10)",
    }, {
      "name" = "wmnPoisonNeutralizePct",
      "value" = 60,
      "comment" = "Neutralize Poison succeeds only 60 percent of the time (folio 10)",
    }, {
      "name" = "wmnPoisonCurePct",
      "value" = 10,
      "comment" = "Cure Disease succeeds only 10 percent of the time (folio 10)",
    }, {
      "name" = "wmnPoisonDetectPct",
      "value" = 30,
      "comment" = "a Detect Magic spell detects the poison spell as it is being cast 30 percent of the time (folio 10)",
    }, {
      "name" = "wmnMeldCastRangeInches",
      "value" = 6,
      "comment" = "the two Mind Meld magic users must be within 6 inches of each other when casting (folio 10)",
    }, {
      "name" = "wmnMeldRangeInches",
      "value" = 12,
      "comment" = "and within 12 inches of each other at all times while the meld is in effect (folio 10)",
    }, {
      "name" = "wmnMeldLowGainDiv",
      "value" = 2,
      "comment" = "after 1 full turn the lower-ranked magic user increases by HALF the difference in levels (folio 10)",
    }, {
      "name" = "wmnMeldStrongerGain",
      "value" = 1,
      "comment" = "and the stronger magic user's level goes up by 1 (folio 10)",
    }, {
      "name" = "wmnMeldInsanityDamaged",
      "value" = 85,
      "comment" = "if either receives damage points there is an 85 percent chance of insanity for the MU actually damaged (folio 10)",
    }, {
      "name" = "wmnMeldInsanityOther",
      "value" = 50,
      "comment" = "and 50 percent for the other (folio 10)",
    }, {
      "name" = "wmnMeldDurationBase",
      "value" = 6,
      "comment" = "the meld stays in force for 6 turns (folio 10)",
    }, {
      "name" = "wmnMeldDurationDie",
      "value" = 8,
      "comment" = "plus 1-8 turns, then the spell must be broken (folio 10)",
    }, {
      "name" = "wmnMountHeavyCount",
      "value" = 3,
      "comment" = "the Magic Mount Wind Horse fights as 3 heavy horse (folio 10)",
    }, {
      "name" = "wmnMountRiders",
      "value" = 2,
      "comment" = "two people may ride the horse at full speed (folio 10)",
    }, {
      "name" = "wmnSpiritMoveInches",
      "value" = 12,
      "comment" = "the Spirit form moves laterally only at 12 inches per turn (folio 10)",
    }, {
      "name" = "wmnSpiritDurationBase",
      "value" = 4,
      "comment" = "the Spirit duration runs from 4 turns (folio 10)",
    }, {
      "name" = "wmnSpiritDurationDie",
      "value" = 8,
      "comment" = "plus 1-8 turns, with the judge warning one turn before the end (folio 10)",
    }, {
      "name" = "wmnSpiritMagicDamagePct",
      "value" = 50,
      "comment" = "while in spirit form magic weapons do only 50 percent damage (folio 10)",
    }, {
      "name" = "wmnSpiritSpellPct",
      "value" = 30,
      "comment" = "spells are only 30 percent effective (folio 10)",
    }, {
      "name" = "wmnWorshipLevel",
      "value" = 4,
      "comment" = "Worship is a 4th-level cleric spell used by chaotic clerics of beauty 11 or more (folio 10)",
    }, {
      "name" = "wmnWorshipBeautyMin",
      "value" = 11,
      "comment" = "the chaotic cleric casting Worship needs beauty 11 or higher (folio 10)",
    }, {
      "name" = "wmnWorshipRangeFeet",
      "value" = 12,
      "comment" = "all men within 12 feet will idolize the cleric (folio 10)",
    }, {
      "name" = "wmnWorshipDurationBase",
      "value" = 4,
      "comment" = "the trance holds for 4 turns (folio 10)",
    }, {
      "name" = "wmnWorshipDurationDie",
      "value" = 8,
      "comment" = "plus 1-8 turns (folio 10)",
    }, {
      "name" = "wmnWorshipSaveHd",
      "value" = 5,
      "comment" = "those with 4+1 hit dice (five) may have a saving throw as in a 4th-level seduction (folio 10)",
    }, {
      "name" = "wmnFtrLevels",
      "value" = 10,
      "comment" = "the Fighting Woman ladder runs ten levels, Fighting Woman to War Lady (folio 7)",
    }, {
      "name" = "wmnClrLevels",
      "value" = 12,
      "comment" = "the female Cleric ladder runs twelve levels, Novice to Matriarch 12th (folios 7-8)",
    }, {
      "name" = "wmnThfLevels",
      "value" = 8,
      "comment" = "the female Thief ladder runs eight levels, Wench to Sibyl (folios 7-8)",
    }, {
      "name" = "wmnMageLevels",
      "value" = 22,
      "comment" = "the female Magic-User ladder runs twenty-two levels, Medium to Witch 22nd (folios 7-8)",
    }, {
      "name" = "wmnSeduceRaces",
      "value" = 5,
      "comment" = "five charmer races in the beauty matrix - Elf, Woman, Hobbit, Orc, Dwarf (folio 9)",
    }, {
      "name" = "wmnSeduceBands",
      "value" = 9,
      "comment" = "nine magic-user level bands in the seduction duration table (folio 9)",
    }, {
      "name" = "wmnCharmMenLevels",
      "value" = 3,
      "comment" = "three Charm Men grades - I, II and III (folio 9)",
    }, {
      "name" = "wmnHbTiers",
      "value" = 5,
      "comment" = "five Horrid Beauty tiers - Grotesque, Ugly, Ordinary, Beautiful, Gorgeous (folio 10)",
    } },
  "bools" = { {
      "name" = "wmnWomenSurpassMenThieves",
      "value" = true,
      "comment" = "women may progress to the level of men in magic and, in some ways, surpass men as thieves (folio 7)",
    }, {
      "name" = "wmnChaoticClericsUseBeauty",
      "value" = true,
      "comment" = "clerics may not use beauty if they are lawful or neutral; chaotic clerics may use their beauty score (folio 7)",
    }, {
      "name" = "wmnClericsRateCharisma",
      "value" = true,
      "comment" = "for neutral and lawful clerics rate Charisma instead of beauty (folio 10)",
    }, {
      "name" = "wmnAlternateSystemLevelCut",
      "value" = true,
      "comment" = "if the Alternate Combat System is used instead of Chainmail, subtract one level from all levels over one - else women fight as well as men for far fewer experience points (folio 7)",
    }, {
      "name" = "wmnSeductionMalesOnly",
      "value" = true,
      "comment" = "Seduction may be used on living humanoid unharmed males only (folio 8)",
    }, {
      "name" = "wmnOrdinaryEffectCoinFlip",
      "value" = true,
      "comment" = "ordinary witches may have either Horrid Beauty effect on a 50/50 basis, dice cast for every figure individually (folio 10)",
    }, {
      "name" = "wmnMeldRequiresStillness",
      "value" = true,
      "comment" = "to break the Mind Meld neither magic user must move or be damaged for two full turns (folio 10)",
    }, {
      "name" = "wmnMountBridleAtOnce",
      "value" = true,
      "comment" = "the Wind Horse's cloth must be placed about its neck as a bridle at once or the horse dispels (folio 10)",
    }, {
      "name" = "wmnTarotYesNoOnly",
      "value" = true,
      "comment" = "the Tarot reading may be asked simple yes/no questions only, relating to the immediate future of one day at most (folio 8)",
    }, {
      "name" = "wmnTarotSibylReads",
      "value" = true,
      "comment" = "the Sibyl at level 9 and beyond can tell something from the three cards used; Sibyl level 8 and below cannot (folio 8)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wmnFtrLadder",
      "tag" = "WmnFtr",
      "count" = "wmnFtrLevels",
      "sentinel" = 9,
      "cols" = { "wmnFtrXp", "wmnFtrHitBase", "wmnFtrHitBonus" },
      "col_comments" = { "the Fighting Woman experience ladder - Fighting Woman 0 through War Lady 10th at 300000 (folio 7)", "the hit-dice base split from the printed \"X+Y\" form - the conversion noted, never silent (folio 7)", "the hit-dice bonus - 1+1 at first level, +2 from Myrmidon on (folio 7)" },
      "data" = { { 0, 1, 1 }, { 1600, 2, 0 }, { 3200, 3, 0 }, { 6400, 4, 0 }, { 12800, 5, 0 }, { 25000, 5, 2 }, { 50000, 6, 2 }, { 100000, 7, 2 }, { 200000, 8, 2 }, { 300000, 9, 2 } },
      "audit_comment" = "the Fighting Woman ladder - Fighting Woman, Swordswoman, Gladiator, Battle Maiden, Shield Maiden, Myrmidon, Heroine, Valkyrie, War Lady, War Lady 10th (folio 7)",
    }, {
      "name" = "wmnClrLadder",
      "tag" = "WmnClr",
      "count" = "wmnClrLevels",
      "sentinel" = 9,
      "cols" = { "wmnClrXp", "wmnClrHitBase", "wmnClrHitBonus" },
      "col_comments" = { "the female Cleric experience ladder - Novice 0 through Matriarch 12th at 400000 (folios 7-8)", "the hit-dice base split from the printed \"X+Y\" form - the conversion noted (folio 8)", "the hit-dice bonus - Apostolate 3+1, Deaconess 4+1, +2 from Superioress on (folio 8)" },
      "data" = { { 0, 1, 0 }, { 1200, 2, 0 }, { 2400, 3, 0 }, { 4800, 3, 1 }, { 9600, 4, 0 }, { 20000, 4, 1 }, { 40000, 5, 0 }, { 80000, 6, 0 }, { 160000, 6, 2 }, { 240000, 7, 2 }, { 320000, 8, 2 }, { 400000, 9, 2 } },
      "audit_comment" = "the female Cleric ladder - Novice, Initiate, Postulant, Apostolate, Sister, Deaconess, Canoness, Prioress, Superioress, Matriarch 10th-12th (folios 7-8)",
    }, {
      "name" = "wmnThfLadder",
      "tag" = "WmnThf",
      "count" = "wmnThfLevels",
      "sentinel" = 9,
      "cols" = { "wmnThfXp", "wmnThfHitBase", "wmnThfHitBonus" },
      "col_comments" = { "the female Thief experience ladder - Wench 0 through Sibyl at 70000 (folios 7-8)", "the hit-dice base split from the printed \"X+Y\" form - the conversion noted (folio 8)", "the hit-dice bonus - Adventuress 4+1, Soothsayer 4+2, Sibyl 5+2 (folio 8)" },
      "data" = { { 0, 1, 0 }, { 1000, 2, 0 }, { 2000, 3, 0 }, { 4000, 4, 0 }, { 8000, 4, 1 }, { 16000, 4, 2 }, { 35000, 5, 0 }, { 70000, 5, 2 } },
      "audit_comment" = "the female Thief ladder - Wench, Hag, Jade, Succubus, Adventuress, Soothsayer, Gypsy, Sibyl; the duplicate Succubus row in the transcript is an OCR artifact, eight titles pin (folios 7-8)",
    }, {
      "name" = "wmnMageLadder",
      "tag" = "WmnMge",
      "count" = "wmnMageLevels",
      "sentinel" = 9,
      "cols" = { "wmnMageXp", "wmnMageHitBase", "wmnMageHitBonus" },
      "col_comments" = { "the female Magic-User ladder - Medium 0 through Witch 22nd at 2400000, without limit above 13th (folios 7-8)", "the hit-dice base split from the printed \"X+Y\" form (folio 8)", "the hit-dice bonus AS SCANNED - the odd cells (Witch 18th 10+4, Witch 22nd 11+7) ride the transcript with no figure to check, the honest boundary noted (folio 8)" },
      "data" = { { 0, 1, 0 }, { 2400, 1, 1 }, { 4800, 2, 0 }, { 9600, 2, 1 }, { 20000, 3, 0 }, { 40000, 3, 1 }, { 65000, 4, 0 }, { 90000, 5, 0 }, { 180000, 6, 0 }, { 270000, 7, 0 }, { 360000, 8, 0 }, { 450000, 8, 1 }, { 600000, 8, 2 }, { 700000, 9, 2 }, { 800000, 9, 3 }, { 900000, 10, 2 }, { 1000000, 10, 3 }, { 1200000, 10, 4 }, { 1400000, 11, 3 }, { 1600000, 11, 4 }, { 2000000, 11, 5 }, { 2400000, 11, 7 } },
      "audit_comment" = "the female Magic-User ladder - Medium, Seer, Sage, Mystic, Oracle, Enchantress, Illusionist, Sorceress, Witch 9th-22nd (folios 7-8)",
    }, {
      "name" = "wmnSeduceMatrix",
      "tag" = "WmnSed",
      "count" = "wmnSeduceRaces",
      "sentinel" = 9,
      "cols" = { "wmnSeduceVsMen", "wmnSeduceVsElves", "wmnSeduceVsOrcs", "wmnSeduceVsHobbits", "wmnSeduceVsDwarves" },
      "col_comments" = { "the minimum beauty to seduce a man of Men (folio 9)", "of the Elves (folio 9)", "of the Orcs (folio 9)", "of the Hobbits (folio 9)", "of the Dwarves (folio 9)" },
      "data" = { { 10, 11, 10, 10, 10 }, { 11, 12, 11, 12, 12 }, { 12, 14, 13, 11, 12 }, { 15, 20, 11, 14, 17 }, { 13, 15, 14, 13, 11 } },
      "audit_comment" = "the beauty matrix AS SCANNED - rows Elf, Woman, Hobbit, Orc, Dwarf against the defender races; no figure pixels ride the OCR artifact to verify against, the honest boundary noted; women with a lower beauty score cannot seduce the given man of the other race (folio 9)",
    }, {
      "name" = "wmnSeduceDuration",
      "tag" = "WmnSdd",
      "count" = "wmnSeduceBands",
      "sentinel" = 9,
      "cols" = { "wmnSedBase", "wmnSedDie" },
      "col_comments" = { "the base turns a seduction lasts at this magic-user level band - flat 2 at levels 1-2, rising to 5 at 17-18 (folio 9)", "the bonus die - 0 at the first band, 1-2 through 1-8 by band (folio 9)" },
      "data" = { { 2, 0 }, { 1, 2 }, { 1, 3 }, { 2, 3 }, { 3, 4 }, { 3, 6 }, { 4, 6 }, { 4, 8 }, { 5, 8 } },
      "audit_comment" = "the seduction duration by level bands 1-2, 3-4, 5-6, 7-8, 9-10, 11-12, 13-14, 15-16, 17-18 (folio 9)",
    }, {
      "name" = "wmnCharmMenLadder",
      "tag" = "WmnCm",
      "count" = "wmnCharmMenLevels",
      "sentinel" = 9,
      "cols" = { "wmnCmHdCap", "wmnCmCataBase", "wmnCmCataDie", "wmnCmAffBase", "wmnCmAffDie" },
      "col_comments" = { "the hit-dice cap of the men affected - 3 or fewer for I, 4 for II, 5 for III (folio 9)", "the catatonia base turns - 3, 4, 5 by grade (folio 9)", "the catatonia bonus die - 1-4, 1-6, 1-8 by grade (folio 9)", "the base count of men affected - 4, 6, 8 by grade (folio 9)", "the affected bonus die - 1-4, 1-6, 1-8 by grade (folio 9)" },
      "data" = { { 3, 3, 4, 4, 4 }, { 4, 4, 6, 6, 6 }, { 5, 5, 8, 8, 8 } },
      "audit_comment" = "the Charm Men grades I, II, III - catatonia occurs if no figure with more hit dice is within 12 feet; weakest figures are always affected first (folio 9)",
    }, {
      "name" = "wmnHorridBeauty",
      "tag" = "WmnHb",
      "count" = "wmnHbTiers",
      "sentinel" = 9,
      "cols" = { "wmnHbBeautyMin", "wmnHbScareHd", "wmnHbSeduceHd", "wmnHbSeduceLevel", "wmnHbMoraleDrop", "wmnHbFleeBase", "wmnHbFleeDie" },
      "col_comments" = { "the beauty floor of the tier - Grotesque 2-5, Ugly 6-9, Ordinary 10-12, Beautiful 13-16, Gorgeous 17+ (folio 10)", "the hit dice scared to death - Grotesque 3 or fewer, Ugly 2 or fewer (folio 10)", "the no-save seduction hit-dice cap - Beautiful 4 or fewer, Gorgeous 5 or fewer; the figures above the cap may save (folio 10)", "the equivalent seduction spell level - Beautiful casts as 6th, Gorgeous as 7th (folio 10)", "the morale points lowered on the flee - Grotesque 2, Ugly 1 (folio 10)", "the flee-duration base turns - Grotesque 4, Ugly 2 (folio 10)", "the flee-duration bonus die - Grotesque 1-6, Ugly 1-4, the printed sign AS SCANNED where ambiguous, the honest boundary noted (folio 10)" },
      "data" = { { 2, 3, 0, 0, 2, 4, 6 }, { 6, 2, 0, 0, 1, 2, 4 }, { 10, 0, 0, 0, 0, 0, 0 }, { 13, 0, 4, 6, 0, 0, 0 }, { 17, 0, 5, 7, 0, 0, 0 } },
      "audit_comment" = "the Horrid Beauty tiers - Grotesque, Ugly, Ordinary, Beautiful, Gorgeous; the ordinary tier flips a coin between the scare and the seduce effects (folio 10)",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wmnFtrXp'](0) != 0 or m['wmnFtrXp'](4) != 12800 or m['wmnFtrXp'](9) != 300000",
      "note" = "the Fighting Woman ladder bookends - 0, Shield Maiden 12800, War Lady 10th 300000 (folio 7)",
    }, {
      "expr" = "m['wmnFtrHitBase'](5) != 5 or m['wmnFtrHitBonus'](5) != 2 or m['wmnFtrHitBonus'](0) != 1",
      "note" = "the Myrmidon rolls 5+2 hit dice, the Fighting Woman 1+1 (folio 7)",
    }, {
      "expr" = "m['wmnClrXp'](11) != 400000 or m['wmnClrHitBase'](11) != 9 or m['wmnClrHitBonus'](11) != 2",
      "note" = "the Matriarch 12th caps at 400000 experience, 9+2 hit dice (folios 7-8)",
    }, {
      "expr" = "m['wmnClrHitBonus'](3) != 1 or m['wmnClrHitBonus'](5) != 1 or m['wmnClrHitBonus'](8) != 2",
      "note" = "the Apostolate 3+1, the Deaconess 4+1, the Superioress 6+2 (folio 8)",
    }, {
      "expr" = "m['wmnThfXp'](6) != 35000 or m['wmnThfXp'](7) != 70000",
      "note" = "the Gypsy at 35000, the Sibyl at 70000 (folio 7)",
    }, {
      "expr" = "m['wmnThfHitBase'](5) != 4 or m['wmnThfHitBonus'](5) != 2 or m['wmnThfHitBonus'](7) != 2",
      "note" = "the Soothsayer 4+2, the Sibyl 5+2 (folio 8)",
    }, {
      "expr" = "m['wmnMageXp'](8) != 180000 or m['wmnMageXp'](20) != 2000000 or m['wmnMageXp'](21) != 2400000",
      "note" = "the Witch ladder - Witch at 180000 through Witch 22nd at 2400000 (folio 7)",
    }, {
      "expr" = "m['wmnMageHitBase'](15) != 10 or m['wmnMageHitBonus'](17) != 4 or m['wmnMageHitBonus'](21) != 7",
      "note" = "the Witch-grid hit-dice column as scanned - Witch 16th 10+2 base, Witch 18th +4, Witch 22nd +7 (folio 8)",
    }, {
      "expr" = "m['wmnBeautyDiceCount']() != 2 or m['wmnBeautyDieMax']() != 10",
      "note" = "beauty on two twenty-sided dice numbered 1-10, range 2-20 not 2-40 (folio 7)",
    }, {
      "expr" = "m['wmnStrengthMin']() != 2 or m['wmnStrengthMax']() != 14 or m['wmnStrengthDieEight']() != 8 or m['wmnStrengthDieSix']() != 6",
      "note" = "strength 2-14 on one 8-sider plus one 6-sider (folios 7-8)",
    }, {
      "expr" = "m['wmnStrConBonusMin']() != 13 or m['wmnStrConBonusMax']() != 14 or m['wmnStrConBonus']() != 1",
      "note" = "strength 13 or 14 adds 1 to constitution (folio 7)",
    }, {
      "expr" = "m['wmnThiefSpellIntMin']() != 12 or m['wmnThiefCharmIntMin']() != 9 or m['wmnThiefCharmBeautyMin']() != 13",
      "note" = "the thief spell gates - intelligence 12 for spells, 9 for the three charm spells, beauty 13 (folio 8)",
    }, {
      "expr" = "m['wmnEncumbranceBase']() != 1000 or m['wmnEncumbrancePerStr']() != 50 or m['wmnMaxLoadTenths']() != 18",
      "note" = "the encumbrance frame - 1000 plus fifty times strength, max load 1.8x as 18 tenths (folio 8)",
    }, {
      "expr" = "m['wmnGroupOnePenalty']() != 1 or m['wmnGroupTwoPenaltyTen']() != 2 or m['wmnGroupTwoPenaltyTwelve']() != 1",
      "note" = "the weapon penalties by strength - the flail group at -1, the pole-arm group -2 at ten or lower, -1 at twelve or lower (folio 8)",
    }, {
      "expr" = "m['wmnDaggerBonus']() != 1",
      "note" = "ALL WOMEN wield the dagger at an additional +1 (folio 8)",
    }, {
      "expr" = "m['wmnPlateFatigueTen']() != 20 or m['wmnPlateFatigueTwelve']() != 10 or m['wmnChainFatigueEleven']() != 10",
      "note" = "the armor fatigue percentages (folio 8)",
    }, {
      "expr" = "m['wmnWitchEqualLevel']() != 13 or m['wmnWomenSurpassMenThieves']() != 1 or m['wmnAlternateSystemLevelCut']() != 1",
      "note" = "Witch 13 equals Wizard 13; women surpass men as thieves; the Alternate Combat System cuts one level (folios 7-8)",
    }, {
      "expr" = "m['wmnSeduceVsMen'](1) != 11 or m['wmnSeduceVsElves'](3) != 20 or m['wmnSeduceVsOrcs'](4) != 14",
      "note" = "the beauty matrix as scanned - a woman needs 11 versus Men, an orc 20 versus Elves, a dwarf 14 versus Orcs (folio 9)",
    }, {
      "expr" = "m['wmnSeduceThiefBonus']() != 2 or m['wmnSeduceFighterBonus']() != 4",
      "note" = "thieves add 2, fighters add 4 to each matrix score (folio 9)",
    }, {
      "expr" = "m['wmnSeduceSaveFighter']() != 13 or m['wmnSeduceSaveThief']() != 12 or m['wmnSeduceSavePaladin']() != 10",
      "note" = "the fighter, thief and paladin save thresholds (folio 9)",
    }, {
      "expr" = "m['wmnSeduceSaveMage']() != 9 or m['wmnSeduceSaveCleric']() != 8",
      "note" = "the magic-user and cleric save thresholds (folio 9)",
    }, {
      "expr" = "m['wmnSeduceRangeFeet']() != 6 or m['wmnSeduceEffectTurns']() != 2 or m['wmnSeduceAttackPenalty']() != 3",
      "note" = "seduction at six feet, two full turns at three levels lower (folio 9)",
    }, {
      "expr" = "m['wmnSedBase'](0) != 2 or m['wmnSedDie'](0) != 0",
      "note" = "the first duration band is a flat two turns (folio 9)",
    }, {
      "expr" = "m['wmnSedBase'](8) != 5 or m['wmnSedDie'](8) != 8 or m['wmnSedBase'](3) != 2 or m['wmnSedDie'](3) != 3",
      "note" = "the 17-18 band runs 5+(1-8) turns, the 7-8 band 2+(1-3) (folio 9)",
    }, {
      "expr" = "m['wmnCmHdCap'](0) != 3 or m['wmnCmHdCap'](1) != 4 or m['wmnCmHdCap'](2) != 5",
      "note" = "the Charm Men hit-dice caps - 3, 4, 5 by grade (folio 9)",
    }, {
      "expr" = "m['wmnCmCataBase'](1) != 4 or m['wmnCmCataDie'](1) != 6 or m['wmnCmAffBase'](1) != 6 or m['wmnCmAffDie'](1) != 6",
      "note" = "Charm Men II - 4+(1-6) turns of catatonia, 6+(1-6) men affected (folio 9)",
    }, {
      "expr" = "m['wmnCharmRangeFeet']() != 16 or m['wmnCharmTakeoverTurns']() != 2 or m['wmnCharmBossDie']() != 8 or m['wmnCharmBossDispels']() != 6",
      "note" = "the charm frame - range 16 feet, takeover after 2 turns, the boss rolls a d8 and dispels at 6+ (folio 9)",
    }, {
      "expr" = "m['wmnCharmBeautyMage']() != 11 or m['wmnCharmBeautyThief']() != 13 or m['wmnCharmBeautyFighter']() != 16",
      "note" = "the charm beauty gates - magic user 11, thief 13, fighter 16 (folio 9)",
    }, {
      "expr" = "m['wmnChmBeautyMage']() != 11 or m['wmnChmBeautyThiefFighter']() != 13 or m['wmnChmBreakPercent']() != 70",
      "note" = "the humanoid charm gates and the 70 percent break (folio 9)",
    }, {
      "expr" = "m['wmnChmCatatoniaDie']() != 4 or m['wmnChmLevelBonus']() != 2 or m['wmnChmHarmPercent']() != 50",
      "note" = "catatonia 1-4 turns, vampires, gargoyles and centaurs +2 level, the 50 percent grapple harm (folios 9-10)",
    }, {
      "expr" = "m['wmnChmKillRoll']() != 8 or m['wmnChmGrappleRoll']() != 9 or m['wmnChmCarryRollMin']() != 12 or m['wmnChmCarryRollMax']() != 16",
      "note" = "the fight-break roll - 8+ kill, 9+ grapple, 12-16 carry-off, 17+ catatonia (folio 9)",
    }, {
      "expr" = "m['wmnHbBeautyMin'](0) != 2 or m['wmnHbBeautyMin'](1) != 6 or m['wmnHbBeautyMin'](3) != 13 or m['wmnHbBeautyMin'](4) != 17",
      "note" = "the tier floors - Grotesque 2, Ugly 6, Beautiful 13, Gorgeous 17 (folio 10)",
    }, {
      "expr" = "m['wmnHbScareHd'](0) != 3 or m['wmnHbScareHd'](1) != 2",
      "note" = "Grotesque scares 3 hit dice to death, Ugly 2 (folio 10)",
    }, {
      "expr" = "m['wmnHbSeduceHd'](3) != 4 or m['wmnHbSeduceLevel'](3) != 6 or m['wmnHbSeduceHd'](4) != 5 or m['wmnHbSeduceLevel'](4) != 7",
      "note" = "Beautiful seduces 4 hit dice as a 6th-level spell, Gorgeous 5 as a 7th (folio 10)",
    }, {
      "expr" = "m['wmnHbMoraleDrop'](0) != 2 or m['wmnHbMoraleDrop'](1) != 1 or m['wmnHbFleeBase'](1) != 2 or m['wmnHbFleeDie'](1) != 4",
      "note" = "the flee morale hits - 2 and 1, the ugly flee as scanned 2+(1-4) (folio 10)",
    }, {
      "expr" = "m['wmnOrdinaryEffectCoinFlip']() != 1 or m['wmnHbRangeFeet']() != 16 or m['wmnHbDurationTurns']() != 6",
      "note" = "the ordinary 50/50, sight within 16 feet, 6-turn duration (folio 10)",
    }, {
      "expr" = "m['wmnPoisonRangeInches']() != 18 or m['wmnPoisonDamagePerTurn']() != 3",
      "note" = "poison to 18 inches, 3 hits per turn (folio 10)",
    }, {
      "expr" = "m['wmnPoisonPurifyPct']() != 40 or m['wmnPoisonNeutralizePct']() != 60 or m['wmnPoisonCurePct']() != 10 or m['wmnPoisonDetectPct']() != 30",
      "note" = "the counter-spell chances (folio 10)",
    }, {
      "expr" = "m['wmnMeldCastRangeInches']() != 6 or m['wmnMeldRangeInches']() != 12 or m['wmnMeldDurationBase']() != 6 or m['wmnMeldDurationDie']() != 8",
      "note" = "the Mind Meld frame (folio 10)",
    }, {
      "expr" = "m['wmnMeldInsanityDamaged']() != 85 or m['wmnMeldInsanityOther']() != 50 or m['wmnMeldLowGainDiv']() != 2 or m['wmnMeldStrongerGain']() != 1",
      "note" = "the insanity chances and the level gains (folio 10)",
    }, {
      "expr" = "m['wmnMountHeavyCount']() != 3 or m['wmnMountRiders']() != 2 or m['wmnMountBridleAtOnce']() != 1",
      "note" = "the Wind Horse fights as 3 heavy horse, carries two, bridled at once (folio 10)",
    }, {
      "expr" = "m['wmnSpiritMoveInches']() != 12 or m['wmnSpiritDurationBase']() != 4 or m['wmnSpiritDurationDie']() != 8",
      "note" = "the spirit form - lateral 12, 4+(1-8) turns (folio 10)",
    }, {
      "expr" = "m['wmnSpiritMagicDamagePct']() != 50 or m['wmnSpiritSpellPct']() != 30",
      "note" = "magic weapons half damage, spells 30 percent (folio 10)",
    }, {
      "expr" = "m['wmnWorshipLevel']() != 4 or m['wmnWorshipBeautyMin']() != 11 or m['wmnWorshipRangeFeet']() != 12",
      "note" = "Worship - the 4th-level chaotic cleric spell, beauty 11, within 12 feet (folio 10)",
    }, {
      "expr" = "m['wmnWorshipDurationBase']() != 4 or m['wmnWorshipDurationDie']() != 8 or m['wmnWorshipSaveHd']() != 5",
      "note" = "the trance 4+(1-8) turns, the save at 4+1 hit dice (folio 10)",
    }, {
      "expr" = "m['wmnChaoticClericsUseBeauty']() != 1 or m['wmnClericsRateCharisma']() != 1",
      "note" = "the cleric beauty rules - chaotic beauty, lawful and neutral charisma (folios 7, 10)",
    }, {
      "expr" = "m['wmnSeductionMalesOnly']() != 1 or m['wmnTarotYesNoOnly']() != 1 or m['wmnTarotSibylReads']() != 1",
      "note" = "males only for seduction, the tarot yes/no frame, the Sibyl read (folio 8)",
    }, {
      "expr" = "m['wmnMeldRequiresStillness']() != 1",
      "note" = "the meld breaks only through two full turns of stillness (folio 10)",
    } },
  "audit" = {
      "label" = "R895 women magic audit",
      "comment" = "THE ISSUE-3 OPENER - the Dragon #3 walk opens: the 32 voice pages ride as data files, the issue-3 gap report ships pre-flip with five boxes (the women opener, the specialists, the fighting sub-classes, the character, the comedy and small-variants rounds), and the Ward box flips closing the issue-1 report at 4 closed / 0 open. THE LAKOFKA WOMEN: the Beauty attribute (2d20 as 1-10s, 2-20), the strength frame (1d8+1d6, 2-14, the 13-14 constitution bump), the four ladders - Fighting Woman to War Lady 10th, Novice to Matriarch 12th, Wench to Sibyl, Medium to Witch 22nd - with the hit-dice X+Y forms CONVERTED to base-plus-bonus columns; the seduction family - the five-race beauty matrix with the thief +2 and fighter +4 adders, the nine duration bands, the Charm Men grades with hit-dice caps and catatonia dice, the humanoid charm gates with the 70 percent break and the 12-16 carry-off; the witch additions - the five Horrid Beauty tiers with the scare and seduce caps, Poison with the counter-spell percentages, Magic Mount, Mind Meld with the insanity chances, Spirit, and the chaotic cleric Worship. HONEST BOUNDARIES: the beauty matrix, the Witch-grid odd hit-dice cells and the ugly-tier flee sign ride as scanned, no figure to check; the OCR duplicate Succubus row pins eight thief titles; the female ladders ride the variant layer against the engine's canon class tables, never a rewrite.",
    },
}
