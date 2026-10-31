-- oa624: promoted from rules/oashukenja.h (the THE SHUKENJA, printed capture pp. 42-45 - the OA shukenja round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 624,
  "prefix" = "oa624",
  "banner" = {
      "title" = "THE SHUKENJA, printed capture pp. 42-45 - the OA shukenja round",
      "provenance" = "census 546 -> 547.  verified against capture pp. 42-45 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). The T26 row-1 and row-12 xp bounds are OCR-mangled in the capture (0-1 250 and 1,200,00) and settled against the 2018 print BEFORE pinning (1,250 and 1,200,000) per the settling doctrine. The T27 spell-bonus column pins as cumulative codes and the T28 dashes pin as zeros. OCR normalization: minimum scares reads as minimum scores; principal attitude reads as principal attribute; t has failed reads as it has failed (prose only)  the gap census after this round: 49 closed, 186 open - the shukenja boxes with Tables 26, 27 and 28 flip (census 546 -> 547); NEXT - R625: the Sohei, capture pp. 45-47, Tables 29 and 30, prefix dgl (verify free), audit \"R625 OA sohei audit\", include after rules/oashukenja.h",
    },
  "consts" = { {
      "name" = "dgkShukenjaMinWis",
      "value" = 12,
      "comment" = "Shukenja prose (capture p. 43): the Wisdom minimum",
    }, {
      "name" = "dgkShukenjaMinStr",
      "value" = 9,
      "comment" = "Shukenja prose (capture p. 43): the Strength minimum",
    }, {
      "name" = "dgkShukenjaMinCon",
      "value" = 9,
      "comment" = "Shukenja prose (capture p. 43): the Constitution minimum",
    }, {
      "name" = "dgkShukenjaBonusStat",
      "value" = 15,
      "comment" = "Shukenja prose (capture p. 43): both Wisdom and Constitution 15 or greater earn the 10 percent experience bonus",
    }, {
      "name" = "dgkShukenjaBonusPct",
      "value" = 10,
      "comment" = "Shukenja prose (capture p. 43): the bonus value",
    }, {
      "name" = "dgkShukenjaHitDie",
      "value" = 6,
      "comment" = "Shukenja prose (capture p. 44): the 6-sided hit die, one per level",
    }, {
      "name" = "dgkShukenjaSlots",
      "value" = 6,
      "comment" = "Shukenja prose (capture p. 44): six proficiency slots at 1st level",
    }, {
      "name" = "dgkShukenjaWeaponSlots",
      "value" = 2,
      "comment" = "Shukenja prose (capture p. 44): only two of the slots may hold weapon proficiencies",
    }, {
      "name" = "dgkShukenjaCursePctPerLevel",
      "value" = 5,
      "comment" = "Shukenja prose (capture p. 44): the 5 percent per level chance to remove a curse with the purification ritual",
    }, {
      "name" = "dgkShukenjaSanctifyRadius",
      "value" = 5,
      "comment" = "Shukenja prose (capture p. 44): the sanctified area has a 5-foot radius",
    }, {
      "name" = "dgkShukenjaSanctifyArea",
      "value" = 75,
      "comment" = "Shukenja prose (capture p. 44): the printed 75 square feet of the sanctified area",
    }, {
      "name" = "dgkShukenjaSanctifyBonus",
      "value" = 1,
      "comment" = "Shukenja prose (capture p. 44): +1 on to hit and saving throws vs evil spirits inside the circle",
    }, {
      "name" = "dgkShukenjaMeditationDiv",
      "value" = 2,
      "comment" = "Shukenja prose (capture p. 44): one hour of uninterrupted meditation is as restful as two hours of sleep",
    }, {
      "name" = "dgkShukenjaKiSaveBonus",
      "value" = 3,
      "comment" = "Shukenja prose (capture p. 45): the ki focus improves the saving throw by +3",
    }, {
      "name" = "dgkShukenjaKiPerDayMult",
      "value" = 1,
      "comment" = "Shukenja prose (capture p. 45): the ki usable a number of times per day equal to level",
    }, {
      "name" = "dgkShukenjaDefeatedXpDiv",
      "value" = 2,
      "comment" = "Shukenja prose (capture p. 45): half the normal experience points for slaying or defeating humans and monsters",
    }, {
      "name" = "dgkShukenjaHealXpPerSpellLevel",
      "value" = 100,
      "comment" = "Shukenja prose (capture p. 45): 100 experience points per spell level used to heal or aid an NPC outside the party",
    }, {
      "name" = "dgkT26RowCount",
      "value" = 12,
      "comment" = "Table 26 (capture p. 42): twelve rows, levels 1-12",
    }, {
      "name" = "dgkT26XpBeyond",
      "value" = 250000,
      "comment" = "Table 26 note (capture p. 42): 250,000 experience points are required for each level beyond 12th",
    }, {
      "name" = "dgkT26HpBeyond",
      "value" = 1,
      "comment" = "Table 26 note (capture p. 42): shukenja gain 1 hp per level beyond 9th",
    }, {
      "name" = "dgkT27RowCount",
      "value" = 10,
      "comment" = "Table 27 (capture p. 43): ten rows, Wisdom scores 9 through 18",
    }, {
      "name" = "dgkT27FirstScore",
      "value" = 9,
      "comment" = "Table 27 (capture p. 43): the first ability score row is 9 - the row index is the score minus 9",
    }, {
      "name" = "dgkT27BonusNone",
      "value" = 0,
      "comment" = "Table 27 (capture p. 43): the spell-bonus code 0 - no bonus spells",
    }, {
      "name" = "dgkT27BonusFirst",
      "value" = 1,
      "comment" = "Table 27 (capture p. 43): the code 1 - one additional 1st-level spell",
    }, {
      "name" = "dgkT27BonusSecond",
      "value" = 2,
      "comment" = "Table 27 (capture p. 43): the code 2 - one additional 2nd-level spell",
    }, {
      "name" = "dgkT27BonusThird",
      "value" = 3,
      "comment" = "Table 27 (capture p. 43): the code 3 - one additional 3rd-level spell, Wisdom 17",
    }, {
      "name" = "dgkT27BonusFourth",
      "value" = 4,
      "comment" = "Table 27 (capture p. 43): the code 4 - one additional 4th-level spell, Wisdom 18",
    }, {
      "name" = "dgkT27Spell6WisMin",
      "value" = 17,
      "comment" = "Table 27 footnote (capture p. 43): Wisdom 17 is the minimum for use of 6th-level spells",
    }, {
      "name" = "dgkT27Spell7WisMin",
      "value" = 18,
      "comment" = "Table 27 footnote (capture p. 43): Wisdom 18 is the minimum for use of 7th-level spells",
    }, {
      "name" = "dgkT28RowCount",
      "value" = 29,
      "comment" = "Table 28 (capture pp. 43-44): twenty-nine rows, levels 1-29",
    }, {
      "name" = "dgkT28SpellLevels",
      "value" = 7,
      "comment" = "Table 28 (capture p. 43): seven spell-level columns, 1st through 7th",
    }, {
      "name" = "dgkT28MaxCastable",
      "value" = 9,
      "comment" = "Table 28 (capture pp. 43-44): the maximum castable per spell level - nine 1st through five 7th",
    } },
  "bools" = { {
      "name" = "dgkShukenjaGoodOnly",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 43): must have good alignment - lawful, neutral or chaotic",
    }, {
      "name" = "dgkShukenjaReligionSlot",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 44): one of the four non-weapon slots must be religion",
    }, {
      "name" = "dgkShukenjaCalligraphySlot",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 44): another slot must be calligraphy",
    }, {
      "name" = "dgkShukenjaClericTables",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 44): the combat and saving throw tables of clerics",
    }, {
      "name" = "dgkShukenjaStuddedLeatherCap",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 44): limited to studded leather or lesser armor, though certain individual pieces can be worn",
    }, {
      "name" = "dgkShukenjaOutsideCaste",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 43): the self-sacrifice places him outside the caste system, respected by all members of society",
    }, {
      "name" = "dgkShukenjaNoOrganizedChurch",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 44): no separate organized church - the temples are more or less independent, the beliefs intermingled",
    }, {
      "name" = "dgkShukenjaRitualTraining",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 44): the ritual training - marriages, christenings, funeral rites, holy days and purifications",
    }, {
      "name" = "dgkShukenjaSanctifyWhilePresent",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 44): the sanctified bonus lasts only while the shukenja remains within the circle",
    }, {
      "name" = "dgkShukenjaSanctifyNoStack",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 44): multiple purifications have no cumulative effect",
    }, {
      "name" = "dgkShukenjaMeditationAware",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 44): meditating, he is oblivious to hunger, thirst, heat and cold but suffers no surprise or initiative penalties",
    }, {
      "name" = "dgkShukenjaFreeStyle",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 45): the self-defense training gives a free initial unarmed-combat style outside the slots",
    }, {
      "name" = "dgkShukenjaKiBeforeDieRolled",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 45): the ki decision can be made any point in the round unless the save die is already rolled",
    }, {
      "name" = "dgkShukenjaEvilSpiritFullXp",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 45): full experience for defeating evil spirits",
    }, {
      "name" = "dgkShukenjaDonatedTreasureXp",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 45): sworn to poverty - experience only for treasure donated to charity or the poor",
    }, {
      "name" = "dgkShukenjaNoMeat",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 45): cannot eat meat, must refrain from violence whenever possible, avoid immoderate drinking and eating",
    }, {
      "name" = "dgkShukenjaRulePunishments",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 45): breaking the rules brings DM punishment - lost spell levels, lost honor or a penance; forced breaks count",
    }, {
      "name" = "dgkShukenjaNoFamily",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 45): the religious life severs all ties - no family, clan or Table 38 birth roll",
    }, {
      "name" = "dgkShukenjaHonorLight",
      "value" = true,
      "comment" = "Shukenja prose (capture p. 45): exempt from many honor penalties and bonuses - he has honor but it seldom reaches the heights",
    } },
  "switches" = { {
      "name" = "dgkT26XpMax",
      "values" = { 1250, 3000, 5500, 11000, 22000, 44000, 90000, 150000, 300000, 600000, 900000, 1200000 },
      "default" = -99,
      "comment" = "the experience column: the upper xp bound of each level, 1,250 at 1st to 1,200,000 at 12th - the row-1 and row-12 bounds OCR-mangled in the capture (0-1 250 and 1,200,00) and settled against the 2018 print (capture p. 42).",
    }, {
      "name" = "dgkT26Dice",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9 },
      "default" = -99,
      "comment" = "the accumulated d6 dice column: one per level through 9th, then held at 9 (capture p. 42).",
    }, {
      "name" = "dgkT26HpBonus",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3 },
      "default" = -99,
      "comment" = "the hit-point bonus column: the printed 9-plus-N cells - 1 hp per level beyond 9th: 0 through 9th, then 1, 2, 3 (capture p. 42).",
    }, {
      "name" = "dgkT27Bonus",
      "values" = { 0, 0, 0, 0, 1, 1, 2, 2, 3, 4 },
      "default" = -99,
      "comment" = "the spell-bonus code column: 0 none through Wisdom 12, then one additional 1st-level spell at 13-14 (code 1), one 2nd at 15-16 (code 2), one 3rd at 17 (code 3), one 4th at 18 (code 4) - cumulative (capture p. 43).",
    }, {
      "name" = "dgkT27Failure",
      "values" = { 20, 15, 10, 5, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "the spell-failure column: the percent chance a cast spell fails - 20 at Wisdom 9 down to 0 at 13 and above (capture p. 43).",
    }, {
      "name" = "dgkT28S1",
      "values" = { 1, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9 },
      "default" = -99,
      "comment" = "the 1st-level spells column: 1 at 1st to 9 from 22nd (capture pp. 43-44).",
    }, {
      "name" = "dgkT28S2",
      "values" = { 0, 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 9, 9, 9, 9, 9 },
      "default" = -99,
      "comment" = "the 2nd-level spells column: none until 4th, then 1 to 9 from 25th (capture pp. 43-44).",
    }, {
      "name" = "dgkT28S3",
      "values" = { 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 9, 9 },
      "default" = -99,
      "comment" = "the 3rd-level spells column: none until 6th, then 1 to 9 from 28th (capture pp. 43-44).",
    }, {
      "name" = "dgkT28S4",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9 },
      "default" = -99,
      "comment" = "the 4th-level spells column: none until 8th, then 1 to 9 at 29th (capture pp. 43-44).",
    }, {
      "name" = "dgkT28S5",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8 },
      "default" = -99,
      "comment" = "the 5th-level spells column: none until 10th, then 1 to 8 at 29th (capture pp. 43-44).",
    }, {
      "name" = "dgkT28S6",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7 },
      "default" = -99,
      "comment" = "the 6th-level spells column: none until 14th, then 1 to 7 at 29th (capture pp. 43-44).",
    }, {
      "name" = "dgkT28S7",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5 },
      "default" = -99,
      "comment" = "the 7th-level spells column: none until 18th, then 1 to 5 at 29th (capture pp. 43-44).",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgkShukenjaMinWis']() != 12  or m['dgkShukenjaMinStr']() != 9  or m['dgkShukenjaMinCon']() != 9  or m['dgkShukenjaBonusStat']() != 15  or m['dgkShukenjaBonusPct']() != 10  or m['dgkShukenjaHitDie']() != 6  or m['dgkShukenjaSlots']() != 6  or m['dgkShukenjaWeaponSlots']() != 2  or m['dgkShukenjaCursePctPerLevel']() != 5  or m['dgkShukenjaSanctifyRadius']() != 5  or m['dgkShukenjaSanctifyArea']() != 75  or m['dgkShukenjaSanctifyBonus']() != 1  or m['dgkShukenjaMeditationDiv']() != 2  or m['dgkShukenjaKiSaveBonus']() != 3  or m['dgkShukenjaKiPerDayMult']() != 1  or m['dgkShukenjaDefeatedXpDiv']() != 2  or m['dgkShukenjaHealXpPerSpellLevel']() != 100  or m['dgkT26RowCount']() != 12  or m['dgkT26XpBeyond']() != 250000  or m['dgkT26HpBeyond']() != 1  or m['dgkT27RowCount']() != 10  or m['dgkT27FirstScore']() != 9  or m['dgkT27BonusNone']() != 0  or m['dgkT27BonusFirst']() != 1  or m['dgkT27BonusSecond']() != 2  or m['dgkT27BonusThird']() != 3  or m['dgkT27BonusFourth']() != 4  or m['dgkT27Spell6WisMin']() != 17  or m['dgkT27Spell7WisMin']() != 18  or m['dgkT28RowCount']() != 29  or m['dgkT28SpellLevels']() != 7  or m['dgkT28MaxCastable']() != 9  or  m['dgkShukenjaGoodOnly']() != 1  or  m['dgkShukenjaOutsideCaste']() != 1  or  m['dgkShukenjaClericTables']() != 1  or  m['dgkShukenjaStuddedLeatherCap']() != 1  or  m['dgkShukenjaReligionSlot']() != 1  or  m['dgkShukenjaCalligraphySlot']() != 1  or  m['dgkShukenjaRitualTraining']() != 1  or  m['dgkShukenjaSanctifyWhilePresent']() != 1  or  m['dgkShukenjaSanctifyNoStack']() != 1  or  m['dgkShukenjaMeditationAware']() != 1  or  m['dgkShukenjaFreeStyle']() != 1  or  m['dgkShukenjaKiBeforeDieRolled']() != 1  or  m['dgkShukenjaEvilSpiritFullXp']() != 1  or  m['dgkShukenjaDonatedTreasureXp']() != 1  or  m['dgkShukenjaNoMeat']() != 1  or  m['dgkShukenjaRulePunishments']() != 1  or  m['dgkShukenjaNoFamily']() != 1  or  m['dgkShukenjaHonorLight']() != 1  or  m['dgkShukenjaNoOrganizedChurch']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgkShukenjaMinWis']() != 12",
      "note" = "the dgkShukenjaMinWis pin",
    }, {
      "expr" = "m['dgkShukenjaMinStr']() != 9",
      "note" = "the dgkShukenjaMinStr pin",
    }, {
      "expr" = "m['dgkShukenjaMinCon']() != 9",
      "note" = "the dgkShukenjaMinCon pin",
    }, {
      "expr" = "m['dgkShukenjaBonusStat']() != 15",
      "note" = "the dgkShukenjaBonusStat pin",
    }, {
      "expr" = "m['dgkShukenjaBonusPct']() != 10",
      "note" = "the dgkShukenjaBonusPct pin",
    }, {
      "expr" = "m['dgkShukenjaHitDie']() != 6",
      "note" = "the dgkShukenjaHitDie pin",
    }, {
      "expr" = "m['dgkShukenjaSlots']() != 6",
      "note" = "the dgkShukenjaSlots pin",
    }, {
      "expr" = "m['dgkShukenjaWeaponSlots']() != 2",
      "note" = "the dgkShukenjaWeaponSlots pin",
    }, {
      "expr" = "m['dgkShukenjaCursePctPerLevel']() != 5",
      "note" = "the dgkShukenjaCursePctPerLevel pin",
    }, {
      "expr" = "m['dgkShukenjaSanctifyRadius']() != 5",
      "note" = "the dgkShukenjaSanctifyRadius pin",
    }, {
      "expr" = "m['dgkShukenjaSanctifyArea']() != 75",
      "note" = "the dgkShukenjaSanctifyArea pin",
    }, {
      "expr" = "m['dgkShukenjaSanctifyBonus']() != 1",
      "note" = "the dgkShukenjaSanctifyBonus pin",
    }, {
      "expr" = "m['dgkShukenjaMeditationDiv']() != 2",
      "note" = "the dgkShukenjaMeditationDiv pin",
    }, {
      "expr" = "m['dgkShukenjaKiSaveBonus']() != 3",
      "note" = "the dgkShukenjaKiSaveBonus pin",
    }, {
      "expr" = "m['dgkShukenjaKiPerDayMult']() != 1",
      "note" = "the dgkShukenjaKiPerDayMult pin",
    }, {
      "expr" = "m['dgkShukenjaDefeatedXpDiv']() != 2",
      "note" = "the dgkShukenjaDefeatedXpDiv pin",
    }, {
      "expr" = "m['dgkShukenjaHealXpPerSpellLevel']() != 100",
      "note" = "the dgkShukenjaHealXpPerSpellLevel pin",
    }, {
      "expr" = "m['dgkT26RowCount']() != 12",
      "note" = "the dgkT26RowCount pin",
    }, {
      "expr" = "m['dgkT26XpBeyond']() != 250000",
      "note" = "the dgkT26XpBeyond pin",
    }, {
      "expr" = "m['dgkT26HpBeyond']() != 1",
      "note" = "the dgkT26HpBeyond pin",
    }, {
      "expr" = "m['dgkT27RowCount']() != 10",
      "note" = "the dgkT27RowCount pin",
    }, {
      "expr" = "m['dgkT27FirstScore']() != 9",
      "note" = "the dgkT27FirstScore pin",
    }, {
      "expr" = "m['dgkT27BonusNone']() != 0",
      "note" = "the dgkT27BonusNone pin",
    }, {
      "expr" = "m['dgkT27BonusFirst']() != 1",
      "note" = "the dgkT27BonusFirst pin",
    }, {
      "expr" = "m['dgkT27BonusSecond']() != 2",
      "note" = "the dgkT27BonusSecond pin",
    }, {
      "expr" = "m['dgkT27BonusThird']() != 3",
      "note" = "the dgkT27BonusThird pin",
    }, {
      "expr" = "m['dgkT27BonusFourth']() != 4",
      "note" = "the dgkT27BonusFourth pin",
    }, {
      "expr" = "m['dgkT27Spell6WisMin']() != 17",
      "note" = "the dgkT27Spell6WisMin pin",
    }, {
      "expr" = "m['dgkT27Spell7WisMin']() != 18",
      "note" = "the dgkT27Spell7WisMin pin",
    }, {
      "expr" = "m['dgkT28RowCount']() != 29",
      "note" = "the dgkT28RowCount pin",
    }, {
      "expr" = "m['dgkT28SpellLevels']() != 7",
      "note" = "the dgkT28SpellLevels pin",
    }, {
      "expr" = "m['dgkT28MaxCastable']() != 9",
      "note" = "the dgkT28MaxCastable pin",
    }, {
      "expr" = "m['dgkShukenjaGoodOnly']() != 1",
      "note" = "the dgkShukenjaGoodOnly pin",
    }, {
      "expr" = "m['dgkShukenjaOutsideCaste']() != 1",
      "note" = "the dgkShukenjaOutsideCaste pin",
    }, {
      "expr" = "m['dgkShukenjaClericTables']() != 1",
      "note" = "the dgkShukenjaClericTables pin",
    }, {
      "expr" = "m['dgkShukenjaStuddedLeatherCap']() != 1",
      "note" = "the dgkShukenjaStuddedLeatherCap pin",
    }, {
      "expr" = "m['dgkShukenjaReligionSlot']() != 1",
      "note" = "the dgkShukenjaReligionSlot pin",
    }, {
      "expr" = "m['dgkShukenjaCalligraphySlot']() != 1",
      "note" = "the dgkShukenjaCalligraphySlot pin",
    }, {
      "expr" = "m['dgkShukenjaRitualTraining']() != 1",
      "note" = "the dgkShukenjaRitualTraining pin",
    }, {
      "expr" = "m['dgkShukenjaSanctifyWhilePresent']() != 1",
      "note" = "the dgkShukenjaSanctifyWhilePresent pin",
    }, {
      "expr" = "m['dgkShukenjaSanctifyNoStack']() != 1",
      "note" = "the dgkShukenjaSanctifyNoStack pin",
    }, {
      "expr" = "m['dgkShukenjaMeditationAware']() != 1",
      "note" = "the dgkShukenjaMeditationAware pin",
    }, {
      "expr" = "m['dgkShukenjaFreeStyle']() != 1",
      "note" = "the dgkShukenjaFreeStyle pin",
    }, {
      "expr" = "m['dgkShukenjaKiBeforeDieRolled']() != 1",
      "note" = "the dgkShukenjaKiBeforeDieRolled pin",
    }, {
      "expr" = "m['dgkShukenjaEvilSpiritFullXp']() != 1",
      "note" = "the dgkShukenjaEvilSpiritFullXp pin",
    }, {
      "expr" = "m['dgkShukenjaDonatedTreasureXp']() != 1",
      "note" = "the dgkShukenjaDonatedTreasureXp pin",
    }, {
      "expr" = "m['dgkShukenjaNoMeat']() != 1",
      "note" = "the dgkShukenjaNoMeat pin",
    }, {
      "expr" = "m['dgkShukenjaRulePunishments']() != 1",
      "note" = "the dgkShukenjaRulePunishments pin",
    }, {
      "expr" = "m['dgkShukenjaNoFamily']() != 1",
      "note" = "the dgkShukenjaNoFamily pin",
    }, {
      "expr" = "m['dgkShukenjaHonorLight']() != 1",
      "note" = "the dgkShukenjaHonorLight pin",
    }, {
      "expr" = "m['dgkShukenjaNoOrganizedChurch']() != 1",
      "note" = "the dgkShukenjaNoOrganizedChurch pin",
    }, {
      "expr" = "m['dgkT26XpMax'](0) != 1250  or m['dgkT26Dice'](0) != 1  or m['dgkT26HpBonus'](0) != 0",
      "note" = "the T26 first row - 1,250 xp, one die (settled against the 2018 print; capture p. 42)",
    }, {
      "expr" = "m['dgkT26XpMax'](11) != 1200000  or m['dgkT26Dice'](11) != 9  or m['dgkT26HpBonus'](11) != 3",
      "note" = "the T26 capstone - 1,200,000 xp, nine dice plus three (settled; capture p. 42)",
    }, {
      "expr" = "m['dgkT26Dice'](9) != 9  or m['dgkT26HpBonus'](9) != 1",
      "note" = "the T26 9-plus-N cells open on the 10th-level row (capture p. 42)",
    }, {
      "expr" = "m['dgkT27Failure'](0) != 20  or m['dgkT27Failure'](3) != 5  or m['dgkT27Failure'](4) != 0",
      "note" = "the T27 failure ladder - 20 at Wis 9 down to 0 at 13 (capture p. 43)",
    }, {
      "expr" = "m['dgkT27Bonus'](3) != 0  or m['dgkT27Bonus'](4) != 1  or m['dgkT27Bonus'](9) != 4",
      "note" = "the T27 bonus tiers - none through 12, the 1st at 13, the 4th at 18 (capture p. 43)",
    }, {
      "expr" = "m['dgkT27Spell6WisMin']() != 17  or m['dgkT27Spell7WisMin']() != 18",
      "note" = "the T27 spell minima - Wis 17 for the 6th, 18 for the 7th (capture p. 43)",
    }, {
      "expr" = "m['dgkT28S1'](0) != 1  or m['dgkT28S2'](0) != 0  or m['dgkT28S7'](0) != 0",
      "note" = "the T28 1st-level row - one 1st-level spell only (capture p. 43)",
    }, {
      "expr" = "m['dgkT28S1'](28) != 9  or m['dgkT28S4'](28) != 9  or m['dgkT28S5'](28) != 8  or m['dgkT28S6'](28) != 7  or m['dgkT28S7'](28) != 5",
      "note" = "the T28 capstone - the 29th-level row (capture p. 44)",
    }, {
      "expr" = "m['dgkT28S2'](3) != 1  or m['dgkT28S3'](5) != 1  or m['dgkT28S7'](17) != 1",
      "note" = "the T28 openings - the 2nd at 4th, the 3rd at 6th, the 7th at 18th (capture pp. 43-44)",
    }, {
      "expr" = "m['dgkShukenjaCursePctPerLevel']() != 5  or m['dgkShukenjaSanctifyArea']() != 75",
      "note" = "the purification ladder - 5 percent per level, the 75-square-foot circle (capture p. 44)",
    }, {
      "expr" = "m['dgkT27Bonus'](6) != 2  or m['dgkT28S2'](3) != 1",
      "note" = "the Wisdom-15 example - two bonus 1st and one bonus 2nd cumulatively, the 2nd usable from 4th level (capture p. 43)",
    }, {
      "expr" = "m['dgkShukenjaMeditationDiv']() != 2  or m['dgkShukenjaKiSaveBonus']() != 3",
      "note" = "the meditation and ki ladders - the 2-to-1 rest, the +3 save (capture pp. 44-45)",
    } },
  "audit" = {
      "label" = "R624 OA shukenja audit",
      "comment" = "OA round eleven (capture pp. 42-45): the shukenja - the Wisdom minima and bonus, the training and ki, the ethos rules, and the advancement, Wisdom and spell grids",
    },
}
