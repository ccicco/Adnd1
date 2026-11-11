-- oa733: promoted from rules/oa/oa104classuse.h (the OA TREASURE - THE MAGICAL ITEMS USABLE BY CLASS, printed capture p. 285 -);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 733,
  "prefix" = "oa733",
  "banner" = {
      "title" = "OA TREASURE - THE MAGICAL ITEMS USABLE BY CLASS, printed capture p. 285 -",
      "provenance" = "the Chapter 13 opener round census 655 -> 656.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 186 closed, 49 open - the class usage box flips (census 655 -> 656); NEXT - R734: the Random Treasure Determination prose (capture pp. 285-286), prefix dkv (verify free at the landing), audit \"R734 OA random treasure prose audit\", include after rules/oa/oa104classuse.h",
    },
  "consts" = { {
      "name" = "dkuChapterOpener",
      "value" = 1,
      "comment" = "the chapter opener - the treasure and magical items chapter of the goal of accumulating treasure (print capture p. 285)",
    }, {
      "name" = "dkuMoneyMagicPower",
      "value" = 1,
      "comment" = "the power line - money and magic is power (print capture p. 285)",
    }, {
      "name" = "dkuPowerToInfluenceDestiny",
      "value" = 1,
      "comment" = "the power to influence destiny - the first half of the power line (print capture p. 285)",
    }, {
      "name" = "dkuPowerToInfluenceOthers",
      "value" = 1,
      "comment" = "the power to influence others - the second half of the power line (print capture p. 285)",
    }, {
      "name" = "dkuTreasureGivesAccess",
      "value" = 1,
      "comment" = "the access - the treasure found gives access to the power, the use being another matter (print capture p. 285)",
    }, {
      "name" = "dkuSupplementsDMG",
      "value" = 1,
      "comment" = "the DMG relation - the information supplements the Dungeon Masters Guide (print capture p. 285)",
    }, {
      "name" = "dkuMostDMGItemsFound",
      "value" = 1,
      "comment" = "the overlap - most DMG magic items can be found in the world of the Orient (print capture p. 285)",
    }, {
      "name" = "dkuPeculiarItemsGiven",
      "value" = 1,
      "comment" = "the peculiar items - the magical items peculiar to the Oriental world given here (print capture p. 285)",
    }, {
      "name" = "dkuIntegrationTables",
      "value" = 1,
      "comment" = "the integration - the necessary tables and information to integrate them into a campaign (print capture p. 285)",
    }, {
      "name" = "dkuDMGRestrictionsApply",
      "value" = 1,
      "comment" = "the restrictions clause - the DMG item restrictions by class applied for Oriental characters as follows (print capture p. 285)",
    }, {
      "name" = "dkuCodeFighter",
      "value" = 1,
      "comment" = "the fighter code - the samurai, bushi, and kensai mapping, and the sohei half (print capture p. 285)",
    }, {
      "name" = "dkuCodeCleric",
      "value" = 2,
      "comment" = "the cleric code - the shukenja mapping, and the sohei half except staves (print capture p. 285)",
    }, {
      "name" = "dkuCodeMagicUser",
      "value" = 3,
      "comment" = "the magic-user code - the wu jen mapping (print capture p. 285)",
    }, {
      "name" = "dkuCodeThief",
      "value" = 4,
      "comment" = "the thief code - the ninja and yakuza mappings (print capture p. 285)",
    }, {
      "name" = "dkuCodeSoheiSplit",
      "value" = 5,
      "comment" = "the sohei split code - the fighter and cleric-except-staves of the sohei row (print capture p. 285)",
    }, {
      "name" = "dkuClassCount",
      "value" = 8,
      "comment" = "the class table row count - the eight Oriental classes of the mapping table (print capture p. 285)",
    }, {
      "name" = "dkuSamuraiFighter",
      "value" = 1,
      "comment" = "the samurai mapping - the fighter items (print capture p. 285)",
    }, {
      "name" = "dkuSoheiFighterClericExceptStaves",
      "value" = 1,
      "comment" = "the sohei mapping - the fighter and cleric items except for staves (print capture p. 285)",
    }, {
      "name" = "dkuShukenjaCleric",
      "value" = 1,
      "comment" = "the shukenja mapping - the cleric items (print capture p. 285)",
    }, {
      "name" = "dkuBushiFighter",
      "value" = 1,
      "comment" = "the bushi mapping - the fighter items (print capture p. 285)",
    }, {
      "name" = "dkuKensaiFighter",
      "value" = 1,
      "comment" = "the kensai mapping - the fighter items (print capture p. 285)",
    }, {
      "name" = "dkuWuJenMagicUser",
      "value" = 1,
      "comment" = "the wu jen mapping - the magic-user items (print capture p. 285)",
    }, {
      "name" = "dkuNinjaThief",
      "value" = 1,
      "comment" = "the ninja mapping - the thief items (print capture p. 285)",
    }, {
      "name" = "dkuYakuzaThief",
      "value" = 1,
      "comment" = "the yakuza mapping - the thief items (print capture p. 285)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dkuUsableCode",
      "values" = { 1, 5, 2, 1, 1, 3, 4, 4 },
      "default" = 0,
      "comment" = "the usable-by code - the fighter 1 of the samurai, bushi, and kensai; the sohei split 5; the cleric 2 of the shukenja; the magic-user 3 of the wu jen; the thief 4 of the ninja and yakuza (print capture p. 285)",
    } },
  "tables" = { {
      "name" = "dkuClassUse",
      "tag" = "ClassUse",
      "count" = "dkuClassCount",
      "comment" = "the class usage table - the eight Oriental classes row by row, each pinned to its DMG usability code (print capture p. 285)",
      "cols" = { "dkuUsableCode" },
      "col_comments" = { "the usable-by code - the fighter 1 of the samurai, bushi, and kensai; the sohei split 5; the cleric 2 of the shukenja; the magic-user 3 of the wu jen; the thief 4 of the ninja and yakuza (print capture p. 285)" },
      "data" = { { 1 }, { 5 }, { 2 }, { 1 }, { 1 }, { 3 }, { 4 }, { 4 } },
      "sentinel" = 0,
      "sentinel_census" = { 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dkuClassCount']() != 8  or m['dkuCodeFighter']() != 1  or m['dkuCodeCleric']() != 2  or m['dkuCodeMagicUser']() != 3  or m['dkuCodeThief']() != 4  or m['dkuCodeSoheiSplit']() != 5  or  m['dkuChapterOpener']() != 1  or  m['dkuMoneyMagicPower']() != 1  or  m['dkuPowerToInfluenceDestiny']() != 1  or  m['dkuPowerToInfluenceOthers']() != 1  or  m['dkuTreasureGivesAccess']() != 1  or  m['dkuSupplementsDMG']() != 1  or  m['dkuMostDMGItemsFound']() != 1  or  m['dkuPeculiarItemsGiven']() != 1  or  m['dkuIntegrationTables']() != 1  or  m['dkuDMGRestrictionsApply']() != 1  or  m['dkuSamuraiFighter']() != 1  or  m['dkuSoheiFighterClericExceptStaves']() != 1  or  m['dkuShukenjaCleric']() != 1  or  m['dkuBushiFighter']() != 1  or  m['dkuKensaiFighter']() != 1  or  m['dkuWuJenMagicUser']() != 1  or  m['dkuNinjaThief']() != 1  or  m['dkuYakuzaThief']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dkuChapterOpener']() != 1  or m['dkuMoneyMagicPower']() != 1  or m['dkuPowerToInfluenceDestiny']() != 1  or m['dkuPowerToInfluenceOthers']() != 1  or m['dkuTreasureGivesAccess']() != 1  or m['dkuSupplementsDMG']() != 1  or m['dkuMostDMGItemsFound']() != 1  or m['dkuPeculiarItemsGiven']() != 1  or m['dkuIntegrationTables']() != 1",
      "note" = "the opener prose - the Chapter 13 intro paragraph, healthy values, each condition false",
    }, {
      "expr" = "m['dkuCodeFighter']() != 1  or m['dkuCodeCleric']() != 2  or m['dkuCodeMagicUser']() != 3  or m['dkuCodeThief']() != 4  or m['dkuCodeSoheiSplit']() != 5  or m['dkuClassCount']() != 8",
      "note" = "the codes - the five usability codes and the row count, healthy values, each condition false",
    }, {
      "expr" = "m['dkuDMGRestrictionsApply']() != 1  or m['dkuSamuraiFighter']() != 1  or m['dkuSoheiFighterClericExceptStaves']() != 1  or m['dkuShukenjaCleric']() != 1  or m['dkuBushiFighter']() != 1  or m['dkuKensaiFighter']() != 1  or m['dkuWuJenMagicUser']() != 1  or m['dkuNinjaThief']() != 1  or m['dkuYakuzaThief']() != 1",
      "note" = "the mappings and the restrictions clause, healthy values, each condition false",
    }, {
      "expr" = "m['dkuClassCount']() != 8",
      "note" = "the grid - the eight-row class table, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dkuUsableCode'](0) != 1 or m['dkuUsableCode'](1) != 5 or m['dkuUsableCode'](2) != 2 or m['dkuUsableCode'](3) != 1 or m['dkuUsableCode'](4) != 1 or m['dkuUsableCode'](5) != 3 or m['dkuUsableCode'](6) != 4 or m['dkuUsableCode'](7) != 4",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkuUsableCode'](8) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R733 OA treasure class usage audit",
      "comment" = "OA round one hundred twenty (capture p. 285): the Chapter 13 treasure opener - the Magical Items Usable by Character Class table, the eight Oriental classes pinned to their DMG usability codes, the sohei staves exception carried in the split code, the opener prose riding along, single-pass pins per the Chapter 9 provenance shift",
    },
}
