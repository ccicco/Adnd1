-- oa627: promoted from rules/oa/oayakuza.h (the THE YAKUZA, printed capture pp. 51-54 - the OA yakuza round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 627,
  "prefix" = "oa627",
  "banner" = {
      "title" = "THE YAKUZA, printed capture pp. 51-54 - the OA yakuza round",
      "provenance" = "census 549 -> 550.  verified against capture pp. 51-54 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). No contested cells this round - both captures agree on every pinned value. The T35 area column pins as the 1-9 code: 1, 2 and 3 blocks; 1 ward 4; 2 wards 5; 1 district 6; 2 districts 7; 3 districts 8; province 9. The T34 9-plus-N cells pin as dice 9 with the 1-per-level bonus 1, 2, 3. OCR normalization: Zing reads Zingi; 2d level reads 2nd level; hide-out and hideout both printed  the gap census after this round: 59 closed, 176 open - the yakuza boxes with Tables 34 and 35 flip (census 549 -> 550); NEXT - R628: the Character Abilities chapter opener, capture pp. 55-59, Tables 36 (Multiple Attacks), prefix dgo (verify free), audit \"R628 OA character abilities audit\", include after rules/oa/oayakuza.h",
    },
  "consts" = { {
      "name" = "dgnYakuzaMinStr",
      "value" = 11,
      "comment" = "Yakuza prose (capture p. 52): the Strength minimum",
    }, {
      "name" = "dgnYakuzaMinInt",
      "value" = 15,
      "comment" = "Yakuza prose (capture p. 52): the Intelligence minimum",
    }, {
      "name" = "dgnYakuzaMinDex",
      "value" = 15,
      "comment" = "Yakuza prose (capture p. 52): the Dexterity minimum",
    }, {
      "name" = "dgnYakuzaMinCha",
      "value" = 16,
      "comment" = "Yakuza prose (capture p. 52): the Charisma minimum",
    }, {
      "name" = "dgnYakuzaHitDie",
      "value" = 6,
      "comment" = "Yakuza prose (capture p. 52): the 6-sided hit die, one per level",
    }, {
      "name" = "dgnYakuzaSlots",
      "value" = 3,
      "comment" = "Yakuza prose (capture p. 52): three weapon proficiency slots",
    }, {
      "name" = "dgnYakuzaFamilyBirthMod",
      "value" = -5,
      "comment" = "Yakuza prose (capture p. 52): the -5 birth-rank modifier on the family-clan roll",
    }, {
      "name" = "dgnYakuzaKiDamageDiv",
      "value" = 2,
      "comment" = "Yakuza prose (capture p. 53): the ki power halves the damage, rounding up",
    }, {
      "name" = "dgnYakuzaKiPerRound",
      "value" = 1,
      "comment" = "Yakuza prose (capture p. 53): the ki power usable once per round",
    }, {
      "name" = "dgnYakuzaKiPerDayPerLevel",
      "value" = 1,
      "comment" = "Yakuza prose (capture p. 53): the ki power usable once per level per day",
    }, {
      "name" = "dgnYakuzaReactionBonusPct",
      "value" = 10,
      "comment" = "Yakuza prose (capture p. 53): the +10 percent encounter reaction bonus",
    }, {
      "name" = "dgnYakuzaInfoCommonDays",
      "value" = 1,
      "comment" = "Yakuza prose (capture p. 53): common information takes one day",
    }, {
      "name" = "dgnYakuzaInfoCommonCostCount",
      "value" = 2,
      "comment" = "Yakuza prose (capture p. 53): common information costs 2d6 fen",
    }, {
      "name" = "dgnYakuzaInfoCommonCostDice",
      "value" = 6,
      "comment" = "Yakuza prose (capture p. 53): the 2d6-fen common cost dice",
    }, {
      "name" = "dgnYakuzaInfoUncommonDaysMin",
      "value" = 1,
      "comment" = "Yakuza prose (capture p. 53): uncommon information takes 1-3 days",
    }, {
      "name" = "dgnYakuzaInfoUncommonDaysMax",
      "value" = 3,
      "comment" = "Yakuza prose (capture p. 53): the 1-3 day uncommon upper bound",
    }, {
      "name" = "dgnYakuzaInfoUncommonCostDice",
      "value" = 4,
      "comment" = "Yakuza prose (capture p. 53): uncommon information costs 2d4 yuan",
    }, {
      "name" = "dgnYakuzaInfoUncommonInacc",
      "value" = 10,
      "comment" = "Yakuza prose (capture p. 53): the 10 percent inaccurate chance, uncommon",
    }, {
      "name" = "dgnYakuzaInfoConfDaysMin",
      "value" = 2,
      "comment" = "Yakuza prose (capture p. 53): confidential information takes 2d6 days",
    }, {
      "name" = "dgnYakuzaInfoConfDaysMax",
      "value" = 12,
      "comment" = "Yakuza prose (capture p. 53): the 2d6-day confidential upper bound",
    }, {
      "name" = "dgnYakuzaInfoConfCostDice",
      "value" = 10,
      "comment" = "Yakuza prose (capture p. 53): confidential information costs 2d10 tael",
    }, {
      "name" = "dgnYakuzaInfoConfInacc",
      "value" = 25,
      "comment" = "Yakuza prose (capture p. 53): the 25 percent inaccurate chance, confidential",
    }, {
      "name" = "dgnYakuzaInfoSecretDaysMin",
      "value" = 3,
      "comment" = "Yakuza prose (capture p. 53): secret information takes 3d6 days",
    }, {
      "name" = "dgnYakuzaInfoSecretDaysMax",
      "value" = 18,
      "comment" = "Yakuza prose (capture p. 53): the 3d6-day secret upper bound",
    }, {
      "name" = "dgnYakuzaInfoSecretCostDice",
      "value" = 10,
      "comment" = "Yakuza prose (capture p. 53): secret information costs 2d10 ch'ien",
    }, {
      "name" = "dgnYakuzaInfoSecretInacc",
      "value" = 40,
      "comment" = "Yakuza prose (capture p. 53): the 40 percent inaccurate chance, secret",
    }, {
      "name" = "dgnYakuzaBrethrenMinLevel",
      "value" = 2,
      "comment" = "Yakuza prose (capture p. 54): the kyodai-bun brethren gained from 2nd level",
    }, {
      "name" = "dgnYakuzaBrethrenPerLevel",
      "value" = 1,
      "comment" = "Yakuza prose (capture p. 54): one brother gained once per level of experience",
    }, {
      "name" = "dgnYakuzaBrethrenMaxLevel",
      "value" = 8,
      "comment" = "Yakuza prose (capture p. 54): no brother ever above 8th level",
    }, {
      "name" = "dgnYakuzaStipendPerLevel",
      "value" = 2,
      "comment" = "Yakuza prose (capture p. 53): the monthly stipend, 2 ch'ien per level",
    }, {
      "name" = "dgnYakuzaContactLevelDiv",
      "value" = 2,
      "comment" = "Yakuza prose (capture p. 53): one contact per two levels of experience",
    }, {
      "name" = "dgnYakuzaContactMaxAbove",
      "value" = 4,
      "comment" = "Yakuza prose (capture p. 53): no contact more than four levels above the yakuza",
    }, {
      "name" = "dgnT34RowCount",
      "value" = 12,
      "comment" = "Table 34 (capture p. 51): twelve advancement rows",
    }, {
      "name" = "dgnYakuzaXpBeyond12th",
      "value" = 300000,
      "comment" = "Table 34 note (capture p. 51): 300,000 xp per level beyond 12th",
    }, {
      "name" = "dgnYakuzaHpPerLevelBeyond9",
      "value" = 1,
      "comment" = "Table 34 note (capture p. 51): 1 hit point per level beyond 9th",
    }, {
      "name" = "dgnT35RowCount",
      "value" = 21,
      "comment" = "Table 35 (capture p. 53): twenty-one capability rows",
    } },
  "bools" = { {
      "name" = "dgnYakuzaAlwaysLawful",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 52): the yakuza is always lawful, rarely lawful good",
    }, {
      "name" = "dgnYakuzaNoPrimeReq",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 52): no prime requisite",
    }, {
      "name" = "dgnYakuzaThiefTables",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 52): the thief combat and saving throw tables",
    }, {
      "name" = "dgnYakuzaAnyWeapon",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 52): any weapon may be used",
    }, {
      "name" = "dgnYakuzaArmorFromTable13",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 52): the armor choices from Table 13",
    }, {
      "name" = "dgnYakuzaNoShields",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 52): no shield may be used",
    }, {
      "name" = "dgnYakuzaFamilyClanRequired",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 52): the yakuza must belong to a family or clan",
    }, {
      "name" = "dgnYakuzaFreeGamingProf",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 52): the free gaming proficiency",
    }, {
      "name" = "dgnYakuzaThiefSkillsAtNinja",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 52): the thief abilities at the ninja chances",
    }, {
      "name" = "dgnYakuzaHearNoiseAsMonk",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 52): hear noise at the monk chances",
    }, {
      "name" = "dgnYakuzaKiHalvesRoundUp",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 53): the halved damage rounds up",
    }, {
      "name" = "dgnYakuzaReactionExcludesStatus",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 53): the +10 reaction bonus never applies to social-status rolls",
    }, {
      "name" = "dgnYakuzaInfoCommonAlwaysAccurate",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 53): common information is always accurate",
    }, {
      "name" = "dgnYakuzaInfoNeverMagical",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 53): the investigate ability never reveals magical items",
    }, {
      "name" = "dgnYakuzaInfoNeverLegendary",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 53): the investigate ability never reveals legendary lore",
    }, {
      "name" = "dgnYakuzaEnterpriseNeedsOyabun",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 54): major enterprises need the oyabun approval",
    }, {
      "name" = "dgnYakuzaAdoptedNoRolls",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 54): adoption into the kumi without the Table 39 or 40 rolls",
    }, {
      "name" = "dgnYakuzaTattoosNeverFaceHandsFeet",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 54): tattoos per level, never on the face, hands or feet",
    }, {
      "name" = "dgnYakuzaCastOutNonPerson",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 54): cast out below the family honor, a non-person whose death is not avenged",
    }, {
      "name" = "dgnYakuzaMembershipRegainable",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 54): cast-out membership can be regained",
    }, {
      "name" = "dgnYakuzaWaryOfLaw",
      "value" = true,
      "comment" = "Yakuza prose (capture p. 54): always criminals, wary of the law",
    } },
  "switches" = { {
      "name" = "dgnT34XpMax",
      "values" = { 2000, 4000, 8000, 16000, 30000, 60000, 130000, 260000, 520000, 800000, 1100000, 1400000 },
      "default" = -99,
      "comment" = "the experience column: the upper xp bound of each level, 2,000 at 1st to 1,400,000 at 12th (capture p. 51).",
    }, {
      "name" = "dgnT34Dice",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9 },
      "default" = -99,
      "comment" = "the accumulated d6 dice column: one per level through 9th, then held at 9 (capture p. 51).",
    }, {
      "name" = "dgnT34HpBonus",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3 },
      "default" = -99,
      "comment" = "the hit-point bonus column: the printed 9-plus-N cells - 1 hp per level beyond 9th: 0 through 9th, then 1, 2, 3 (capture p. 51).",
    }, {
      "name" = "dgnT35InvestigatePct",
      "values" = { 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 95, 95 },
      "default" = -99,
      "comment" = "the investigate column: the whole-percent ladder, 20 at 1st rising by 4 to 92 at 19th, then 95 at 20th and 21st (capture p. 53).",
    }, {
      "name" = "dgnT35AreaCode",
      "values" = { 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 9 },
      "default" = -99,
      "comment" = "the area covered column, pinned as the 1-9 code: 1, 2 and 3 blocks as 1, 2, 3; 1 ward 4; 2 wards 5; 1 district 6; 2 districts 7; 3 districts 8; province 9 (capture p. 53).",
    } },
  "tables" = { {
      "name" = "dgnT34Grid",
      "tag" = "T34",
      "count" = "dgnT34RowCount",
      "sentinel" = -99,
      "cols" = { "dgnT34XpMax", "dgnT34Dice", "dgnT34HpBonus" },
      "data" = { { 2000, 1, 0 }, { 4000, 2, 0 }, { 8000, 3, 0 }, { 16000, 4, 0 }, { 30000, 5, 0 }, { 60000, 6, 0 }, { 130000, 7, 0 }, { 260000, 8, 0 }, { 520000, 9, 0 }, { 800000, 9, 1 }, { 1100000, 9, 2 }, { 1400000, 9, 3 } },
      "comment" = "the Table 34 yakuza advancement grid (capture p. 51)",
      "col_comments" = { "the experience column: the upper xp bound of each level, 2,000 at 1st to 1,400,000 at 12th (capture p. 51).", "the accumulated d6 dice column: one per level through 9th, then held at 9 (capture p. 51).", "the hit-point bonus column: the printed 9-plus-N cells - 1 hp per level beyond 9th: 0 through 9th, then 1, 2, 3 (capture p. 51)." },
      "audit_comment" = "the Table 34 grid: the xp bounds and the accumulated dice plus bonus (capture p. 51)",
      "sentinel_census" = { 0, 0, 0 },
    }, {
      "name" = "dgnT35Grid",
      "tag" = "T35",
      "count" = "dgnT35RowCount",
      "sentinel" = -99,
      "cols" = { "dgnT35InvestigatePct", "dgnT35AreaCode" },
      "data" = { { 20, 1 }, { 24, 1 }, { 28, 2 }, { 32, 2 }, { 36, 3 }, { 40, 3 }, { 44, 4 }, { 48, 4 }, { 52, 4 }, { 56, 5 }, { 60, 5 }, { 64, 5 }, { 68, 6 }, { 72, 6 }, { 76, 6 }, { 80, 7 }, { 84, 7 }, { 88, 7 }, { 92, 8 }, { 95, 8 }, { 95, 9 } },
      "comment" = "the Table 35 yakuza capabilities grid (capture p. 53)",
      "col_comments" = { "the investigate column: the whole-percent ladder, 20 at 1st rising by 4 to 92 at 19th, then 95 at 20th and 21st (capture p. 53).", "the area covered column, pinned as the 1-9 code: 1, 2 and 3 blocks as 1, 2, 3; 1 ward 4; 2 wards 5; 1 district 6; 2 districts 7; 3 districts 8; province 9 (capture p. 53)." },
      "audit_comment" = "the Table 35 grid: the investigate ladder and the coded area column (capture p. 53)",
      "sentinel_census" = { 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgnYakuzaMinStr']() != 11  or m['dgnYakuzaMinInt']() != 15  or m['dgnYakuzaMinDex']() != 15  or m['dgnYakuzaMinCha']() != 16  or m['dgnYakuzaHitDie']() != 6  or m['dgnYakuzaSlots']() != 3  or m['dgnYakuzaFamilyBirthMod']() != -5  or m['dgnYakuzaStipendPerLevel']() != 2  or m['dgnYakuzaContactLevelDiv']() != 2  or m['dgnYakuzaContactMaxAbove']() != 4  or m['dgnYakuzaKiDamageDiv']() != 2  or m['dgnYakuzaKiPerRound']() != 1  or m['dgnYakuzaKiPerDayPerLevel']() != 1  or m['dgnYakuzaReactionBonusPct']() != 10  or m['dgnYakuzaInfoCommonDays']() != 1  or m['dgnYakuzaInfoCommonCostCount']() != 2  or m['dgnYakuzaInfoCommonCostDice']() != 6  or m['dgnYakuzaInfoUncommonDaysMin']() != 1  or m['dgnYakuzaInfoUncommonDaysMax']() != 3  or m['dgnYakuzaInfoUncommonCostDice']() != 4  or m['dgnYakuzaInfoUncommonInacc']() != 10  or m['dgnYakuzaInfoConfDaysMin']() != 2  or m['dgnYakuzaInfoConfDaysMax']() != 12  or m['dgnYakuzaInfoConfCostDice']() != 10  or m['dgnYakuzaInfoConfInacc']() != 25  or m['dgnYakuzaInfoSecretDaysMin']() != 3  or m['dgnYakuzaInfoSecretDaysMax']() != 18  or m['dgnYakuzaInfoSecretCostDice']() != 10  or m['dgnYakuzaInfoSecretInacc']() != 40  or m['dgnYakuzaBrethrenMinLevel']() != 2  or m['dgnYakuzaBrethrenPerLevel']() != 1  or m['dgnYakuzaBrethrenMaxLevel']() != 8  or m['dgnT34RowCount']() != 12  or m['dgnYakuzaXpBeyond12th']() != 300000  or m['dgnYakuzaHpPerLevelBeyond9']() != 1  or m['dgnT35RowCount']() != 21  or  m['dgnYakuzaAlwaysLawful']() != 1  or  m['dgnYakuzaNoPrimeReq']() != 1  or  m['dgnYakuzaThiefTables']() != 1  or  m['dgnYakuzaAnyWeapon']() != 1  or  m['dgnYakuzaArmorFromTable13']() != 1  or  m['dgnYakuzaNoShields']() != 1  or  m['dgnYakuzaFamilyClanRequired']() != 1  or  m['dgnYakuzaFreeGamingProf']() != 1  or  m['dgnYakuzaThiefSkillsAtNinja']() != 1  or  m['dgnYakuzaHearNoiseAsMonk']() != 1  or  m['dgnYakuzaInfoNeverMagical']() != 1  or  m['dgnYakuzaInfoNeverLegendary']() != 1  or  m['dgnYakuzaInfoCommonAlwaysAccurate']() != 1  or  m['dgnYakuzaKiHalvesRoundUp']() != 1  or  m['dgnYakuzaReactionExcludesStatus']() != 1  or  m['dgnYakuzaAdoptedNoRolls']() != 1  or  m['dgnYakuzaEnterpriseNeedsOyabun']() != 1  or  m['dgnYakuzaTattoosNeverFaceHandsFeet']() != 1  or  m['dgnYakuzaCastOutNonPerson']() != 1  or  m['dgnYakuzaMembershipRegainable']() != 1  or  m['dgnYakuzaWaryOfLaw']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgnYakuzaMinStr']() != 11",
      "note" = "the dgnYakuzaMinStr pin",
    }, {
      "expr" = "m['dgnYakuzaMinInt']() != 15",
      "note" = "the dgnYakuzaMinInt pin",
    }, {
      "expr" = "m['dgnYakuzaMinDex']() != 15",
      "note" = "the dgnYakuzaMinDex pin",
    }, {
      "expr" = "m['dgnYakuzaMinCha']() != 16",
      "note" = "the dgnYakuzaMinCha pin",
    }, {
      "expr" = "m['dgnYakuzaHitDie']() != 6",
      "note" = "the dgnYakuzaHitDie pin",
    }, {
      "expr" = "m['dgnYakuzaSlots']() != 3",
      "note" = "the dgnYakuzaSlots pin",
    }, {
      "expr" = "m['dgnYakuzaFamilyBirthMod']() != -5",
      "note" = "the dgnYakuzaFamilyBirthMod pin",
    }, {
      "expr" = "m['dgnYakuzaStipendPerLevel']() != 2",
      "note" = "the dgnYakuzaStipendPerLevel pin",
    }, {
      "expr" = "m['dgnYakuzaContactLevelDiv']() != 2",
      "note" = "the dgnYakuzaContactLevelDiv pin",
    }, {
      "expr" = "m['dgnYakuzaContactMaxAbove']() != 4",
      "note" = "the dgnYakuzaContactMaxAbove pin",
    }, {
      "expr" = "m['dgnYakuzaKiDamageDiv']() != 2",
      "note" = "the dgnYakuzaKiDamageDiv pin",
    }, {
      "expr" = "m['dgnYakuzaKiPerRound']() != 1",
      "note" = "the dgnYakuzaKiPerRound pin",
    }, {
      "expr" = "m['dgnYakuzaKiPerDayPerLevel']() != 1",
      "note" = "the dgnYakuzaKiPerDayPerLevel pin",
    }, {
      "expr" = "m['dgnYakuzaReactionBonusPct']() != 10",
      "note" = "the dgnYakuzaReactionBonusPct pin",
    }, {
      "expr" = "m['dgnYakuzaInfoCommonDays']() != 1",
      "note" = "the dgnYakuzaInfoCommonDays pin",
    }, {
      "expr" = "m['dgnYakuzaInfoCommonCostCount']() != 2",
      "note" = "the dgnYakuzaInfoCommonCostCount pin",
    }, {
      "expr" = "m['dgnYakuzaInfoCommonCostDice']() != 6",
      "note" = "the dgnYakuzaInfoCommonCostDice pin",
    }, {
      "expr" = "m['dgnYakuzaInfoUncommonDaysMin']() != 1",
      "note" = "the dgnYakuzaInfoUncommonDaysMin pin",
    }, {
      "expr" = "m['dgnYakuzaInfoUncommonDaysMax']() != 3",
      "note" = "the dgnYakuzaInfoUncommonDaysMax pin",
    }, {
      "expr" = "m['dgnYakuzaInfoUncommonCostDice']() != 4",
      "note" = "the dgnYakuzaInfoUncommonCostDice pin",
    }, {
      "expr" = "m['dgnYakuzaInfoUncommonInacc']() != 10",
      "note" = "the dgnYakuzaInfoUncommonInacc pin",
    }, {
      "expr" = "m['dgnYakuzaInfoConfDaysMin']() != 2",
      "note" = "the dgnYakuzaInfoConfDaysMin pin",
    }, {
      "expr" = "m['dgnYakuzaInfoConfDaysMax']() != 12",
      "note" = "the dgnYakuzaInfoConfDaysMax pin",
    }, {
      "expr" = "m['dgnYakuzaInfoConfCostDice']() != 10",
      "note" = "the dgnYakuzaInfoConfCostDice pin",
    }, {
      "expr" = "m['dgnYakuzaInfoConfInacc']() != 25",
      "note" = "the dgnYakuzaInfoConfInacc pin",
    }, {
      "expr" = "m['dgnYakuzaInfoSecretDaysMin']() != 3",
      "note" = "the dgnYakuzaInfoSecretDaysMin pin",
    }, {
      "expr" = "m['dgnYakuzaInfoSecretDaysMax']() != 18",
      "note" = "the dgnYakuzaInfoSecretDaysMax pin",
    }, {
      "expr" = "m['dgnYakuzaInfoSecretCostDice']() != 10",
      "note" = "the dgnYakuzaInfoSecretCostDice pin",
    }, {
      "expr" = "m['dgnYakuzaInfoSecretInacc']() != 40",
      "note" = "the dgnYakuzaInfoSecretInacc pin",
    }, {
      "expr" = "m['dgnYakuzaBrethrenMinLevel']() != 2",
      "note" = "the dgnYakuzaBrethrenMinLevel pin",
    }, {
      "expr" = "m['dgnYakuzaBrethrenPerLevel']() != 1",
      "note" = "the dgnYakuzaBrethrenPerLevel pin",
    }, {
      "expr" = "m['dgnYakuzaBrethrenMaxLevel']() != 8",
      "note" = "the dgnYakuzaBrethrenMaxLevel pin",
    }, {
      "expr" = "m['dgnT34RowCount']() != 12",
      "note" = "the dgnT34RowCount pin",
    }, {
      "expr" = "m['dgnYakuzaXpBeyond12th']() != 300000",
      "note" = "the dgnYakuzaXpBeyond12th pin",
    }, {
      "expr" = "m['dgnYakuzaHpPerLevelBeyond9']() != 1",
      "note" = "the dgnYakuzaHpPerLevelBeyond9 pin",
    }, {
      "expr" = "m['dgnT35RowCount']() != 21",
      "note" = "the dgnT35RowCount pin",
    }, {
      "expr" = "m['dgnYakuzaAlwaysLawful']() != 1",
      "note" = "the dgnYakuzaAlwaysLawful pin",
    }, {
      "expr" = "m['dgnYakuzaNoPrimeReq']() != 1",
      "note" = "the dgnYakuzaNoPrimeReq pin",
    }, {
      "expr" = "m['dgnYakuzaThiefTables']() != 1",
      "note" = "the dgnYakuzaThiefTables pin",
    }, {
      "expr" = "m['dgnYakuzaAnyWeapon']() != 1",
      "note" = "the dgnYakuzaAnyWeapon pin",
    }, {
      "expr" = "m['dgnYakuzaArmorFromTable13']() != 1",
      "note" = "the dgnYakuzaArmorFromTable13 pin",
    }, {
      "expr" = "m['dgnYakuzaNoShields']() != 1",
      "note" = "the dgnYakuzaNoShields pin",
    }, {
      "expr" = "m['dgnYakuzaFamilyClanRequired']() != 1",
      "note" = "the dgnYakuzaFamilyClanRequired pin",
    }, {
      "expr" = "m['dgnYakuzaFreeGamingProf']() != 1",
      "note" = "the dgnYakuzaFreeGamingProf pin",
    }, {
      "expr" = "m['dgnYakuzaThiefSkillsAtNinja']() != 1",
      "note" = "the dgnYakuzaThiefSkillsAtNinja pin",
    }, {
      "expr" = "m['dgnYakuzaHearNoiseAsMonk']() != 1",
      "note" = "the dgnYakuzaHearNoiseAsMonk pin",
    }, {
      "expr" = "m['dgnYakuzaInfoNeverMagical']() != 1",
      "note" = "the dgnYakuzaInfoNeverMagical pin",
    }, {
      "expr" = "m['dgnYakuzaInfoNeverLegendary']() != 1",
      "note" = "the dgnYakuzaInfoNeverLegendary pin",
    }, {
      "expr" = "m['dgnYakuzaInfoCommonAlwaysAccurate']() != 1",
      "note" = "the dgnYakuzaInfoCommonAlwaysAccurate pin",
    }, {
      "expr" = "m['dgnYakuzaKiHalvesRoundUp']() != 1",
      "note" = "the dgnYakuzaKiHalvesRoundUp pin",
    }, {
      "expr" = "m['dgnYakuzaReactionExcludesStatus']() != 1",
      "note" = "the dgnYakuzaReactionExcludesStatus pin",
    }, {
      "expr" = "m['dgnYakuzaAdoptedNoRolls']() != 1",
      "note" = "the dgnYakuzaAdoptedNoRolls pin",
    }, {
      "expr" = "m['dgnYakuzaEnterpriseNeedsOyabun']() != 1",
      "note" = "the dgnYakuzaEnterpriseNeedsOyabun pin",
    }, {
      "expr" = "m['dgnYakuzaTattoosNeverFaceHandsFeet']() != 1",
      "note" = "the dgnYakuzaTattoosNeverFaceHandsFeet pin",
    }, {
      "expr" = "m['dgnYakuzaCastOutNonPerson']() != 1",
      "note" = "the dgnYakuzaCastOutNonPerson pin",
    }, {
      "expr" = "m['dgnYakuzaMembershipRegainable']() != 1",
      "note" = "the dgnYakuzaMembershipRegainable pin",
    }, {
      "expr" = "m['dgnYakuzaWaryOfLaw']() != 1",
      "note" = "the dgnYakuzaWaryOfLaw pin",
    }, {
      "expr" = "m['dgnT34XpMax'](0) != 2000  or m['dgnT34Dice'](0) != 1  or m['dgnT34HpBonus'](0) != 0",
      "note" = "the T34 first row - 2,000 xp, one die (capture p. 51)",
    }, {
      "expr" = "m['dgnT34XpMax'](8) != 520000  or m['dgnT34Dice'](8) != 9  or m['dgnT34HpBonus'](8) != 0",
      "note" = "the T34 9th-level row - nine dice, no bonus (capture p. 51)",
    }, {
      "expr" = "m['dgnT34XpMax'](9) != 800000  or m['dgnT34Dice'](9) != 9  or m['dgnT34HpBonus'](9) != 1",
      "note" = "the T34 10th-level row - nine dice plus one (capture p. 51)",
    }, {
      "expr" = "m['dgnT34XpMax'](11) != 1400000  or m['dgnT34Dice'](11) != 9  or m['dgnT34HpBonus'](11) != 3  or m['dgnT34RowCount']() != 12",
      "note" = "the T34 capstone - 1,400,000 xp, nine dice plus three, twelve rows only (capture p. 51)",
    }, {
      "expr" = "m['dgnYakuzaXpBeyond12th']() != 300000  or m['dgnYakuzaHpPerLevelBeyond9']() != 1",
      "note" = "the T34 note pair - 300,000 xp beyond 12th, 1 hp per level beyond 9th (capture p. 51)",
    }, {
      "expr" = "m['dgnT35InvestigatePct'](0) != 20  or m['dgnT35AreaCode'](0) != 1",
      "note" = "the T35 first row - 20 percent, one block (capture p. 53)",
    }, {
      "expr" = "m['dgnT35InvestigatePct'](6) != 44  or m['dgnT35AreaCode'](6) != 4",
      "note" = "the T35 7th-level row - the first ward row, code 4 (capture p. 53)",
    }, {
      "expr" = "m['dgnT35InvestigatePct'](12) != 68  or m['dgnT35AreaCode'](12) != 6",
      "note" = "the T35 13th-level row - the first district row, code 6 (capture p. 53)",
    }, {
      "expr" = "m['dgnT35InvestigatePct'](18) != 92  or m['dgnT35AreaCode'](18) != 8",
      "note" = "the T35 19th-level row - 92 percent, the 3-district code 8 (capture p. 53)",
    }, {
      "expr" = "m['dgnT35InvestigatePct'](20) != 95  or m['dgnT35AreaCode'](20) != 9  or m['dgnT35RowCount']() != 21",
      "note" = "the T35 capstone - 95 percent, the province code 9, twenty-one rows only (capture p. 53)",
    }, {
      "expr" = "m['dgnT35InvestigatePct'](1) -m['dgnT35InvestigatePct'](0) != 4  or m['dgnT35InvestigatePct'](19) != 95  or m['dgnT35InvestigatePct'](20) -m['dgnT35InvestigatePct'](19) != 0",
      "note" = "the T35 ladder shape - the by-4 rise through 19th, then 95 twice (capture p. 53)",
    } },
  "audit" = {
      "label" = "R627 OA yakuza audit",
      "comment" = "OA round fourteen (capture pp. 51-54): the yakuza - the minima, the investigate tiers, the ki power and the brethren",
    },
}
