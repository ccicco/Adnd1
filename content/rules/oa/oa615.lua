-- oa615: promoted from rules/oaabilities.h (the THE ABILITY TABLES, printed capture pp. 7-13 - the OA Chapter 1 ability);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 615,
  "prefix" = "oa615",
  "banner" = {
      "title" = "THE ABILITY TABLES, printed capture pp. 7-13 - the OA Chapter 1 ability",
      "provenance" = "tables round census 537 -> 538.  verified against capture pp. 7-13 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). OCR normalizations: the Table 4 \"+\" and percent spacing read clean as numbers; the Table 5 korobokuru maximum splits from its Intelligence 15 row in the capture and merges back per book-internal settling; Table 2 Strength 3 weight allowance prints 0 - pinned as printed, flagged for the physical copy. The open-doors parentheticals pin as their own column (the engine strOpenDoors precedent); the Str 19 row prints 7-in-8 and pins as the face 7. The Table 4 footnote prints the warrior bonus (+3 at Con 17, +4 at 18) for samurai, bushi, kensai and sohei with the barbarian also entitled - all pinned as printed.  the gap census after this round: 12 closed, 223 open - the eight ability tables flip (census 537 -> 538); NEXT - R616: the six ability prose sub-items (the Dexterity, Constitution, Intelligence, Wisdom, Charisma and Comeliness prose - the column explanations, the smitten doctrine, the Comeliness reaction bands and the racial adjustments), prefix dgc (verify free), audit \"R616 OA ability prose audit\", include after rules/oaabilities.h",
    },
  "consts" = { {
      "name" = "dgbMinStrWuJen",
      "value" = 3,
      "comment" = "Table 1 (capture p. 7): minimum Strength for wu jen",
    }, {
      "name" = "dgbMinStrSpiritFolk",
      "value" = 6,
      "comment" = "Table 1 (capture p. 7): minimum Strength for spirit folk",
    }, {
      "name" = "dgbMinStrKorobokuru",
      "value" = 8,
      "comment" = "Table 1 (capture p. 7): minimum Strength for korobokuru",
    }, {
      "name" = "dgbMinStrShukenja",
      "value" = 9,
      "comment" = "Table 1 (capture p. 7): minimum Strength for shukenja",
    }, {
      "name" = "dgbMinStrBushi",
      "value" = 9,
      "comment" = "Table 1 (capture p. 7): minimum Strength for bushi",
    }, {
      "name" = "dgbMinStrHengeyokai",
      "value" = 12,
      "comment" = "Table 1 (capture p. 7): minimum Strength for hengeyokai",
    }, {
      "name" = "dgbMinStrKensai",
      "value" = 12,
      "comment" = "Table 1 (capture p. 7): minimum Strength for kensai",
    }, {
      "name" = "dgbMinStrSamurai",
      "value" = 13,
      "comment" = "Table 1 (capture p. 7): minimum Strength for samurai",
    }, {
      "name" = "dgbMinStrSohei",
      "value" = 13,
      "comment" = "Table 1 (capture p. 7): minimum Strength for sohei",
    }, {
      "name" = "dgbMinStrBarbarian",
      "value" = 15,
      "comment" = "Table 1 (capture p. 7): minimum Strength for barbarian",
    }, {
      "name" = "dgbMinStrMonk",
      "value" = 15,
      "comment" = "Table 1 (capture p. 7): minimum Strength for monk",
    }, {
      "name" = "dgbMaxStrShukenja",
      "value" = 18,
      "comment" = "Table 1 (capture p. 7): maximum Strength for shukenja",
    }, {
      "name" = "dgbMaxStrMonk",
      "value" = 18,
      "comment" = "Table 1 (capture p. 7): maximum Strength for monk",
    }, {
      "name" = "dgbMaxStrWuJen",
      "value" = 18,
      "comment" = "Table 1 (capture p. 7): maximum Strength for wu jen",
    }, {
      "name" = "dgbMaxStrYakuza",
      "value" = 18,
      "comment" = "Table 1 (capture p. 7): maximum Strength for yakuza",
    }, {
      "name" = "dgbMaxStrHuman",
      "value" = 18,
      "comment" = "Table 1 (capture p. 7): maximum Strength for human - the 18/00 row (capture p. 7)",
    }, {
      "name" = "dgbMaxStrKorobokuru",
      "value" = 19,
      "comment" = "Table 1 (capture p. 7): maximum Strength for korobokuru",
    }, {
      "name" = "dgbT2RowCount",
      "value" = 16,
      "comment" = "Table 2 (capture p. 8): sixteen rows - Strength 3, 4-5, 6-7, 8-9, 10-11, 12-13, 14-15, 16, 17, 18, 18/01-50, 18/51-75, 18/76-90, 18/91-99, 18/00, 19",
    }, {
      "name" = "dgbMinDexKorobokuru",
      "value" = 6,
      "comment" = "Table 3 (capture p. 9): minimum Dexterity for korobokuru",
    }, {
      "name" = "dgbMinDexBushi",
      "value" = 8,
      "comment" = "Table 3 (capture p. 9): minimum Dexterity for bushi",
    }, {
      "name" = "dgbMinDexHengeyokai",
      "value" = 9,
      "comment" = "Table 3 (capture p. 9): minimum Dexterity for hengeyokai",
    }, {
      "name" = "dgbMinDexSpiritFolk",
      "value" = 12,
      "comment" = "Table 3 (capture p. 9): minimum Dexterity for spirit folk",
    }, {
      "name" = "dgbMinDexKensai",
      "value" = 14,
      "comment" = "Table 3 (capture p. 9): minimum Dexterity for kensai",
    }, {
      "name" = "dgbMinDexBarbarian",
      "value" = 14,
      "comment" = "Table 3 (capture p. 9): minimum Dexterity for barbarian",
    }, {
      "name" = "dgbMinDexNinja",
      "value" = 14,
      "comment" = "Table 3 (capture p. 9): minimum Dexterity for ninja",
    }, {
      "name" = "dgbMinDexMonk",
      "value" = 15,
      "comment" = "Table 3 (capture p. 9): minimum Dexterity for monk",
    }, {
      "name" = "dgbT3RowCount",
      "value" = 17,
      "comment" = "Table 3 (capture p. 9): seventeen rows, Dexterity 3 through 19",
    }, {
      "name" = "dgbMinConSpiritFolk",
      "value" = 6,
      "comment" = "Table 4 (capture p. 10): minimum Constitution for spirit folk",
    }, {
      "name" = "dgbMinConBushi",
      "value" = 8,
      "comment" = "Table 4 (capture p. 10): minimum Constitution for bushi",
    }, {
      "name" = "dgbMinConShukenja",
      "value" = 9,
      "comment" = "Table 4 (capture p. 10): minimum Constitution for shukenja",
    }, {
      "name" = "dgbMinConSohei",
      "value" = 10,
      "comment" = "Table 4 (capture p. 10): minimum Constitution for sohei",
    }, {
      "name" = "dgbMinConMonk",
      "value" = 11,
      "comment" = "Table 4 (capture p. 10): minimum Constitution for monk",
    }, {
      "name" = "dgbMinConKorobokuru",
      "value" = 12,
      "comment" = "Table 4 (capture p. 10): minimum Constitution for korobokuru",
    }, {
      "name" = "dgbMinConHengeyokai",
      "value" = 12,
      "comment" = "Table 4 (capture p. 10): minimum Constitution for hengeyokai",
    }, {
      "name" = "dgbMinConSamurai",
      "value" = 13,
      "comment" = "Table 4 (capture p. 10): minimum Constitution for samurai",
    }, {
      "name" = "dgbMaxConSpiritFolk",
      "value" = 14,
      "comment" = "Table 4 (capture p. 10): maximum Constitution for spirit folk",
    }, {
      "name" = "dgbMinConBarbarian",
      "value" = 15,
      "comment" = "Table 4 (capture p. 10): minimum Constitution for barbarian",
    }, {
      "name" = "dgbT4RowCount",
      "value" = 16,
      "comment" = "Table 4 (capture p. 10): sixteen rows, Constitution 3 through 18",
    }, {
      "name" = "dgbMinIntKorobokuru",
      "value" = 3,
      "comment" = "Table 5 (capture p. 11): minimum Intelligence for korobokuru",
    }, {
      "name" = "dgbMinIntHengeyokai",
      "value" = 12,
      "comment" = "Table 5 (capture p. 11): minimum Intelligence for hengeyokai",
    }, {
      "name" = "dgbMinIntSpiritFolk",
      "value" = 12,
      "comment" = "Table 5 (capture p. 11): minimum Intelligence for spirit folk",
    }, {
      "name" = "dgbMinIntWuJen",
      "value" = 13,
      "comment" = "Table 5 (capture p. 11): minimum Intelligence for wu jen",
    }, {
      "name" = "dgbMinIntSamurai",
      "value" = 14,
      "comment" = "Table 5 (capture p. 11): minimum Intelligence for samurai",
    }, {
      "name" = "dgbMinIntNinja",
      "value" = 15,
      "comment" = "Table 5 (capture p. 11): minimum Intelligence for ninja",
    }, {
      "name" = "dgbMaxIntKorobokuru",
      "value" = 15,
      "comment" = "Table 5 (capture p. 11): maximum Intelligence for korobokuru - the capture splits the row; the annotation belongs to the Intelligence 15 row",
    }, {
      "name" = "dgbT5RowCount",
      "value" = 16,
      "comment" = "Table 5 (capture p. 11): sixteen rows, Intelligence 3 through 18",
    }, {
      "name" = "dgbMinWisSpiritFolk",
      "value" = 9,
      "comment" = "Table 6 (capture pp. 11-12): minimum Wisdom for spirit folk",
    }, {
      "name" = "dgbMinWisSohei",
      "value" = 10,
      "comment" = "Table 6 (capture p. 12): minimum Wisdom for sohei",
    }, {
      "name" = "dgbMinWisKensai",
      "value" = 12,
      "comment" = "Table 6 (capture p. 12): minimum Wisdom for kensai",
    }, {
      "name" = "dgbMinWisShukenja",
      "value" = 12,
      "comment" = "Table 6 (capture p. 12): minimum Wisdom for shukenja",
    }, {
      "name" = "dgbMinWisHengeyokai",
      "value" = 12,
      "comment" = "Table 6 (capture p. 12): minimum Wisdom for hengeyokai",
    }, {
      "name" = "dgbMinWisSamurai",
      "value" = 13,
      "comment" = "Table 6 (capture p. 12): minimum Wisdom for samurai",
    }, {
      "name" = "dgbMinWisMonk",
      "value" = 15,
      "comment" = "Table 6 (capture p. 12): minimum Wisdom for monk",
    }, {
      "name" = "dgbMaxWisBarbarian",
      "value" = 16,
      "comment" = "Table 6 (capture p. 12): maximum Wisdom for barbarian",
    }, {
      "name" = "dgbMaxWisKorobokuru",
      "value" = 17,
      "comment" = "Table 6 (capture p. 12): maximum Wisdom for korobokuru",
    }, {
      "name" = "dgbT6RowCount",
      "value" = 16,
      "comment" = "Table 6 (capture pp. 11-12): sixteen rows, Wisdom 3 through 18",
    }, {
      "name" = "dgbMinChaHengeyokai",
      "value" = 12,
      "comment" = "Table 7 (capture p. 12): minimum Charisma for hengeyokai",
    }, {
      "name" = "dgbMinChaSpiritFolk",
      "value" = 14,
      "comment" = "Table 7 (capture p. 12): minimum Charisma for spirit folk",
    }, {
      "name" = "dgbMinChaNinja",
      "value" = 14,
      "comment" = "Table 7 (capture p. 12): minimum Charisma for ninja",
    }, {
      "name" = "dgbMaxChaKorobokuru",
      "value" = 16,
      "comment" = "Table 7 (capture p. 12): maximum Charisma for korobokuru",
    }, {
      "name" = "dgbMaxChaHengeyokai",
      "value" = 17,
      "comment" = "Table 7 (capture p. 12): maximum Charisma for hengeyokai",
    }, {
      "name" = "dgbT7RowCount",
      "value" = 16,
      "comment" = "Table 7 (capture p. 12): sixteen rows, Charisma 3 through 18",
    }, {
      "name" = "dgbT8RowCount",
      "value" = 9,
      "comment" = "Table 8 (capture p. 13): nine Charisma bands - 2 or less, 3, 4-5, 6-8, 9-12, 13-15, 16-17, 18, 19 or more",
    } },
  "bools" = { {
      "name" = "dgbT2OpenDoorsRetry",
      "value" = true,
      "comment" = "Table 2 explanation (capture p. 8): a stuck door can be retried until it opens, each attempt noisy and slow",
    }, {
      "name" = "dgbT2LockedOneAttempt",
      "value" = true,
      "comment" = "Table 2 explanation (capture p. 8): a locked, barred or magically held door allows one attempt ever - a failure is permanent for that character",
    }, {
      "name" = "dgbT2BendBarsOneAttempt",
      "value" = true,
      "comment" = "Table 2 explanation (capture p. 8): a failed bend-bars or lift-gate attempt can never succeed at that task; the other task at the same gate stays open",
    }, {
      "name" = "dgbT2DmgFloorOne",
      "value" = true,
      "comment" = "Table 2 explanation (capture p. 8): a successful hit never causes less than 1 point of damage",
    }, {
      "name" = "dgbT2WeightSlowdown",
      "value" = true,
      "comment" = "Table 2 explanation (capture p. 8): each additional 350 coins (35 lbs.) of weight slows the character by 25 percent",
    }, {
      "name" = "dgbT4HitDieFloorOne",
      "value" = true,
      "comment" = "Table 4 explanation (capture p. 10): no hit die ever yields fewer than 1 hit point, whatever the adjustment",
    }, {
      "name" = "dgbT4WarriorFullCon",
      "value" = true,
      "comment" = "Table 4 footnote (capture p. 10): the +3 at Constitution 17 and +4 at 18 apply only to samurai, bushi, kensai and sohei",
    }, {
      "name" = "dgbT4BarbarianFullCon",
      "value" = true,
      "comment" = "Table 4 footnote (capture p. 10): the barbarian also receives the full hit-point bonus for Constitution",
    }, {
      "name" = "dgbT4OthersCapTwo",
      "value" = true,
      "comment" = "Table 4 footnote (capture p. 10): wu jen, shukenja, ninja and yakuza receive at most +2 per hit die at Constitution 18",
    }, {
      "name" = "dgbT6MindAuto",
      "value" = true,
      "comment" = "Table 6 explanation (capture p. 11): the magical attack adjustment applies automatically against mind attacks - beguiling, charm, fear, hypnosis, illusion, possession, suggestion",
    } },
  "switches" = { {
      "name" = "dgbT2HitProb",
      "values" = { -3, -2, -1, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3 },
      "default" = -99,
      "comment" = "the hit probability column: -3 at Strength 3 to +3 at 18/00 and 19 (capture p. 8).",
    }, {
      "name" = "dgbT2DmgAdj",
      "values" = { -1, -1, 0, 0, 0, 0, 0, 1, 1, 2, 3, 3, 4, 5, 6, 7 },
      "default" = -99,
      "comment" = "the damage adjustment column: -1 at Strength 3 to +7 at 19 (capture p. 8).",
    }, {
      "name" = "dgbT2Weight",
      "values" = { 0, 100, 200, 350, 350, 450, 550, 700, 850, 1100, 1350, 1600, 1850, 2350, 3350, 4850 },
      "default" = -99,
      "comment" = "the weight allowance column in coins: 0 at Strength 3 (the printed zero, pinned as printed) to 4,850 at 19 (capture p. 8).",
    }, {
      "name" = "dgbT2OpenMax",
      "values" = { 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 7 },
      "default" = -99,
      "comment" = "the open-doors max column: the highest d6 face that forces a stuck door; the Str 19 row prints 7-in-8, pinned as the face 7 (capture p. 8).",
    }, {
      "name" = "dgbT2OpenLocked",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3 },
      "default" = -99,
      "comment" = "the open-doors locked column: the parenthetical chance on a locked, barred or held door - 0 except 1 at 18/91-99, 2 at 18/00, 3 at 19 (capture p. 8).",
    }, {
      "name" = "dgbT2BendPct",
      "values" = { 0, 0, 0, 1, 2, 4, 7, 10, 13, 16, 20, 25, 30, 35, 40, 50 },
      "default" = -99,
      "comment" = "the bend-bars percent column: 0 at Strength 3 to 50 at 19 (capture p. 8).",
    }, {
      "name" = "dgbT3Reaction",
      "values" = { -3, -2, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3 },
      "default" = -99,
      "comment" = "the reaction/attacking adjustment column: -3 at Dexterity 3 to +3 at 19 (capture p. 9).",
    }, {
      "name" = "dgbT3Defensive",
      "values" = { 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -4 },
      "default" = -99,
      "comment" = "the defensive adjustment column: +4 at Dexterity 3 to -4 at 19 (capture p. 9).",
    }, {
      "name" = "dgbT4HpAdj",
      "values" = { -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2 },
      "default" = -99,
      "comment" = "the hit-point adjustment column: -2 at Constitution 3 to +2 at 18 (capture p. 10).",
    }, {
      "name" = "dgbT4WarriorHpAdj",
      "values" = { -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4 },
      "default" = -99,
      "comment" = "the warrior hit-point column: the full bonus ladder - the +3 at Constitution 17 and +4 at 18 of the printed footnote (capture p. 10).",
    }, {
      "name" = "dgbT4ShockPct",
      "values" = { 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 88, 91, 95, 97, 99 },
      "default" = -99,
      "comment" = "the system shock survival percent column: 35 at Constitution 3 to 99 at 18 (capture p. 10).",
    }, {
      "name" = "dgbT4ResPct",
      "values" = { 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 92, 94, 96, 98, 100 },
      "default" = -99,
      "comment" = "the resurrection survival percent column: 40 at Constitution 3 to 100 at 18 (capture p. 10).",
    }, {
      "name" = "dgbT5Languages",
      "values" = { 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 7 },
      "default" = -99,
      "comment" = "the additional languages column: 0 at Intelligence 3-7, 1 at 8-9, rising to 7 at 18 (capture p. 11).",
    }, {
      "name" = "dgbT5MaxSpellLevel",
      "values" = { 4, 4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 9 },
      "default" = -99,
      "comment" = "the maximum wu jen spell level column: 4 at Intelligence 3-9, 5 at 10-11, 6 at 12-14, 7 at 15, 8 at 16-17, 9 at 18 (capture p. 11).",
    }, {
      "name" = "dgbT6MagicAttack",
      "values" = { -3, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4 },
      "default" = -99,
      "comment" = "the magical attack adjustment column: -3 at Wisdom 3 to +4 at 18 (capture pp. 11-12).",
    }, {
      "name" = "dgbT7Henchmen",
      "values" = { 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 6, 7, 8, 10, 15 },
      "default" = -99,
      "comment" = "the maximum henchmen column: 1 at Charisma 3-4 rising to 15 at 18 (capture p. 12).",
    }, {
      "name" = "dgbT7Loyalty",
      "values" = { -30, -25, -20, -15, -10, -5, 0, 0, 0, 0, 0, 5, 15, 20, 30, 40 },
      "default" = -99,
      "comment" = "the loyalty base percent column: -30 at Charisma 3 to +40 at 18 (capture p. 12).",
    }, {
      "name" = "dgbT7Reaction",
      "values" = { -25, -20, -15, -10, -5, 0, 0, 0, 0, 0, 5, 10, 15, 25, 30, 35 },
      "default" = -99,
      "comment" = "the reaction adjustment percent column: -25 at Charisma 3 to +35 at 18 (capture p. 12).",
    }, {
      "name" = "dgbT8ChaMax",
      "values" = { 2, 3, 5, 8, 12, 15, 17, 18, 19 },
      "default" = -99,
      "comment" = "the band-max column: the highest Charisma score of each band - 2, 3, 5, 8, 12, 15, 17, 18, and the 19-plus tail (capture p. 13).",
    }, {
      "name" = "dgbT8Adj",
      "values" = { -8, -5, -3, -1, 0, 1, 2, 3, 5 },
      "default" = -99,
      "comment" = "the Comeliness adjustment column: -8 at Charisma 2 or less, -5 at 3, -3 at 4-5, -1 at 6-8, 0 at 9-12, +1 at 13-15, +2 at 16-17, +3 at 18, +5 at 19 or more (capture p. 13).",
    } },
  "tables" = { {
      "name" = "dgbT2Grid",
      "tag" = "T2",
      "count" = "dgbT2RowCount",
      "sentinel" = -99,
      "cols" = { "dgbT2HitProb", "dgbT2DmgAdj", "dgbT2Weight", "dgbT2OpenMax", "dgbT2OpenLocked", "dgbT2BendPct" },
      "data" = { { -3, -1, 0, 1, 0, 0 }, { -2, -1, 100, 1, 0, 0 }, { -1, 0, 200, 1, 0, 0 }, { 0, 0, 350, 2, 0, 1 }, { 0, 0, 350, 2, 0, 2 }, { 0, 0, 450, 2, 0, 4 }, { 0, 0, 550, 2, 0, 7 }, { 0, 1, 700, 3, 0, 10 }, { 1, 1, 850, 3, 0, 13 }, { 1, 2, 1100, 3, 0, 16 }, { 1, 3, 1350, 3, 0, 20 }, { 2, 3, 1600, 4, 0, 25 }, { 2, 4, 1850, 4, 0, 30 }, { 2, 5, 2350, 4, 1, 35 }, { 3, 6, 3350, 5, 2, 40 }, { 3, 7, 4850, 7, 3, 50 } },
      "comment" = "the Table 2 Strength Adjustments grid (capture p. 8)",
      "col_comments" = { "the hit probability column: -3 at Strength 3 to +3 at 18/00 and 19 (capture p. 8).", "the damage adjustment column: -1 at Strength 3 to +7 at 19 (capture p. 8).", "the weight allowance column in coins: 0 at Strength 3 (the printed zero, pinned as printed) to 4,850 at 19 (capture p. 8).", "the open-doors max column: the highest d6 face that forces a stuck door; the Str 19 row prints 7-in-8, pinned as the face 7 (capture p. 8).", "the open-doors locked column: the parenthetical chance on a locked, barred or held door - 0 except 1 at 18/91-99, 2 at 18/00, 3 at 19 (capture p. 8).", "the bend-bars percent column: 0 at Strength 3 to 50 at 19 (capture p. 8)." },
      "audit_comment" = "the Table 2 grid: hit probability, damage adjustment, weight allowance, open-doors max and locked, bend-bars percent across the sixteen Strength rows (capture p. 8)",
    }, {
      "name" = "dgbT3Grid",
      "tag" = "T3",
      "count" = "dgbT3RowCount",
      "sentinel" = -99,
      "cols" = { "dgbT3Reaction", "dgbT3Defensive" },
      "data" = { { -3, 4 }, { -2, 3 }, { -1, 2 }, { 0, 1 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, -1 }, { 1, -2 }, { 2, -3 }, { 3, -4 } },
      "comment" = "the Table 3 Dexterity grid (capture p. 9)",
      "col_comments" = { "the reaction/attacking adjustment column: -3 at Dexterity 3 to +3 at 19 (capture p. 9).", "the defensive adjustment column: +4 at Dexterity 3 to -4 at 19 (capture p. 9)." },
      "audit_comment" = "the Table 3 grid: the reaction adjustment and the defensive adjustment across Dexterity 3-19 (capture p. 9)",
    }, {
      "name" = "dgbT4Grid",
      "tag" = "T4",
      "count" = "dgbT4RowCount",
      "sentinel" = -99,
      "cols" = { "dgbT4HpAdj", "dgbT4WarriorHpAdj", "dgbT4ShockPct", "dgbT4ResPct" },
      "data" = { { -2, -2, 35, 40 }, { -1, -1, 40, 45 }, { -1, -1, 45, 50 }, { -1, -1, 50, 55 }, { 0, 0, 55, 60 }, { 0, 0, 60, 65 }, { 0, 0, 65, 70 }, { 0, 0, 70, 75 }, { 0, 0, 75, 80 }, { 0, 0, 80, 85 }, { 0, 0, 85, 90 }, { 0, 0, 88, 92 }, { 1, 1, 91, 94 }, { 2, 2, 95, 96 }, { 2, 3, 97, 98 }, { 2, 4, 99, 100 } },
      "comment" = "the Table 4 Constitution grid (capture p. 10)",
      "col_comments" = { "the hit-point adjustment column: -2 at Constitution 3 to +2 at 18 (capture p. 10).", "the warrior hit-point column: the full bonus ladder - the +3 at Constitution 17 and +4 at 18 of the printed footnote (capture p. 10).", "the system shock survival percent column: 35 at Constitution 3 to 99 at 18 (capture p. 10).", "the resurrection survival percent column: 40 at Constitution 3 to 100 at 18 (capture p. 10)." },
      "audit_comment" = "the Table 4 grid: the hit-point and warrior hit-point adjustments, the system shock and resurrection survival percents across Constitution 3-18 (capture p. 10)",
    }, {
      "name" = "dgbT5Grid",
      "tag" = "T5",
      "count" = "dgbT5RowCount",
      "sentinel" = -99,
      "cols" = { "dgbT5Languages", "dgbT5MaxSpellLevel" },
      "data" = { { 0, 4 }, { 0, 4 }, { 0, 4 }, { 0, 4 }, { 0, 4 }, { 1, 4 }, { 1, 4 }, { 2, 5 }, { 2, 5 }, { 3, 6 }, { 3, 6 }, { 4, 6 }, { 4, 7 }, { 5, 8 }, { 6, 8 }, { 7, 9 } },
      "comment" = "the Table 5 Intelligence grid (capture p. 11)",
      "col_comments" = { "the additional languages column: 0 at Intelligence 3-7, 1 at 8-9, rising to 7 at 18 (capture p. 11).", "the maximum wu jen spell level column: 4 at Intelligence 3-9, 5 at 10-11, 6 at 12-14, 7 at 15, 8 at 16-17, 9 at 18 (capture p. 11)." },
      "audit_comment" = "the Table 5 grid: the additional languages and the maximum wu jen spell level across Intelligence 3-18 (capture p. 11)",
    }, {
      "name" = "dgbT6Grid",
      "tag" = "T6",
      "count" = "dgbT6RowCount",
      "sentinel" = -99,
      "cols" = { "dgbT6MagicAttack" },
      "data" = { { -3 }, { -2 }, { -1 }, { -1 }, { -1 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 1 }, { 2 }, { 3 }, { 4 } },
      "comment" = "the Table 6 Wisdom grid (capture pp. 11-12)",
      "col_comments" = { "the magical attack adjustment column: -3 at Wisdom 3 to +4 at 18 (capture pp. 11-12)." },
      "audit_comment" = "the Table 6 grid: the magical attack adjustment across Wisdom 3-18 (capture pp. 11-12)",
    }, {
      "name" = "dgbT7Grid",
      "tag" = "T7",
      "count" = "dgbT7RowCount",
      "sentinel" = -99,
      "cols" = { "dgbT7Henchmen", "dgbT7Loyalty", "dgbT7Reaction" },
      "data" = { { 1, -30, -25 }, { 1, -25, -20 }, { 2, -20, -15 }, { 2, -15, -10 }, { 3, -10, -5 }, { 3, -5, 0 }, { 4, 0, 0 }, { 4, 0, 0 }, { 4, 0, 0 }, { 5, 0, 0 }, { 5, 0, 5 }, { 6, 5, 10 }, { 7, 15, 15 }, { 8, 20, 25 }, { 10, 30, 30 }, { 15, 40, 35 } },
      "comment" = "the Table 7 Charisma grid (capture p. 12)",
      "col_comments" = { "the maximum henchmen column: 1 at Charisma 3-4 rising to 15 at 18 (capture p. 12).", "the loyalty base percent column: -30 at Charisma 3 to +40 at 18 (capture p. 12).", "the reaction adjustment percent column: -25 at Charisma 3 to +35 at 18 (capture p. 12)." },
      "audit_comment" = "the Table 7 grid: the henchmen, loyalty base and reaction adjustment columns across Charisma 3-18 (capture p. 12)",
    }, {
      "name" = "dgbT8Grid",
      "tag" = "T8",
      "count" = "dgbT8RowCount",
      "sentinel" = -99,
      "cols" = { "dgbT8ChaMax", "dgbT8Adj" },
      "data" = { { 2, -8 }, { 3, -5 }, { 5, -3 }, { 8, -1 }, { 12, 0 }, { 15, 1 }, { 17, 2 }, { 18, 3 }, { 19, 5 } },
      "comment" = "the Table 8 Comeliness Adjustments grid (capture p. 13)",
      "col_comments" = { "the band-max column: the highest Charisma score of each band - 2, 3, 5, 8, 12, 15, 17, 18, and the 19-plus tail (capture p. 13).", "the Comeliness adjustment column: -8 at Charisma 2 or less, -5 at 3, -3 at 4-5, -1 at 6-8, 0 at 9-12, +1 at 13-15, +2 at 16-17, +3 at 18, +5 at 19 or more (capture p. 13)." },
      "audit_comment" = "the Table 8 grid: the nine Charisma bands and their Comeliness adjustments (capture p. 13)",
    } },
  "chains" = { {
      "name" = "dgbT8Band",
      "arg" = "cha",
      "limits" = { 2, 3, 5, 8, 12, 15, 17, 18 },
      "tail" = 8,
      "comment" = "the Table 8 band chain (capture p. 13): a Charisma score maps to its band - 2 or less band 0, 3 band 1, 4-5 band 2, 6-8 band 3, 9-12 band 4, 13-15 band 5, 16-17 band 6, 18 band 7, 19 or more band 8",
    } },
  "examples" = { {
      "expr" = "m['dgbMinStrWuJen']() != 3  or m['dgbMinStrSpiritFolk']() != 6  or m['dgbMinStrKorobokuru']() != 8  or m['dgbMinStrShukenja']() != 9  or m['dgbMinStrBushi']() != 9  or m['dgbMinStrHengeyokai']() != 12  or m['dgbMinStrKensai']() != 12  or m['dgbMinStrSamurai']() != 13  or m['dgbMinStrSohei']() != 13  or m['dgbMinStrBarbarian']() != 15  or m['dgbMinStrMonk']() != 15  or m['dgbMaxStrShukenja']() != 18  or m['dgbMaxStrMonk']() != 18  or m['dgbMaxStrWuJen']() != 18  or m['dgbMaxStrYakuza']() != 18  or m['dgbMaxStrHuman']() != 18  or m['dgbMaxStrKorobokuru']() != 19  or m['dgbT2RowCount']() != 16  or m['dgbMinDexKorobokuru']() != 6  or m['dgbMinDexBushi']() != 8  or m['dgbMinDexHengeyokai']() != 9  or m['dgbMinDexSpiritFolk']() != 12  or m['dgbMinDexKensai']() != 14  or m['dgbMinDexBarbarian']() != 14  or m['dgbMinDexNinja']() != 14  or m['dgbMinDexMonk']() != 15  or m['dgbT3RowCount']() != 17  or m['dgbMinConSpiritFolk']() != 6  or m['dgbMinConBushi']() != 8  or m['dgbMinConShukenja']() != 9  or m['dgbMinConSohei']() != 10  or m['dgbMinConMonk']() != 11  or m['dgbMinConKorobokuru']() != 12  or m['dgbMinConHengeyokai']() != 12  or m['dgbMinConSamurai']() != 13  or m['dgbMaxConSpiritFolk']() != 14  or m['dgbMinConBarbarian']() != 15  or m['dgbT4RowCount']() != 16  or m['dgbMinIntKorobokuru']() != 3  or m['dgbMinIntHengeyokai']() != 12  or m['dgbMinIntSpiritFolk']() != 12  or m['dgbMinIntWuJen']() != 13  or m['dgbMinIntSamurai']() != 14  or m['dgbMinIntNinja']() != 15  or m['dgbMaxIntKorobokuru']() != 15  or m['dgbT5RowCount']() != 16  or m['dgbMinWisSpiritFolk']() != 9  or m['dgbMinWisSohei']() != 10  or m['dgbMinWisKensai']() != 12  or m['dgbMinWisShukenja']() != 12  or m['dgbMinWisHengeyokai']() != 12  or m['dgbMinWisSamurai']() != 13  or m['dgbMinWisMonk']() != 15  or m['dgbMaxWisBarbarian']() != 16  or m['dgbMaxWisKorobokuru']() != 17  or m['dgbT6RowCount']() != 16  or m['dgbMinChaHengeyokai']() != 12  or m['dgbMinChaSpiritFolk']() != 14  or m['dgbMinChaNinja']() != 14  or m['dgbMaxChaKorobokuru']() != 16  or m['dgbMaxChaHengeyokai']() != 17  or m['dgbT7RowCount']() != 16  or m['dgbT8RowCount']() != 9  or  m['dgbT2OpenDoorsRetry']() != 1  or  m['dgbT2LockedOneAttempt']() != 1  or  m['dgbT2BendBarsOneAttempt']() != 1  or  m['dgbT2DmgFloorOne']() != 1  or  m['dgbT2WeightSlowdown']() != 1  or  m['dgbT4HitDieFloorOne']() != 1  or  m['dgbT4WarriorFullCon']() != 1  or  m['dgbT4BarbarianFullCon']() != 1  or  m['dgbT4OthersCapTwo']() != 1  or  m['dgbT6MindAuto']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgbT8Band'](1) != 0  or m['dgbT8Band'](2) != 0  or m['dgbT8Band'](3) != 1  or m['dgbT8Band'](3) != 1  or m['dgbT8Band'](5) != 2  or m['dgbT8Band'](4) != 2  or m['dgbT8Band'](8) != 3  or m['dgbT8Band'](6) != 3  or m['dgbT8Band'](12) != 4  or m['dgbT8Band'](9) != 4  or m['dgbT8Band'](15) != 5  or m['dgbT8Band'](13) != 5  or m['dgbT8Band'](17) != 6  or m['dgbT8Band'](16) != 6  or m['dgbT8Band'](18) != 7  or m['dgbT8Band'](18) != 7  or m['dgbT8Band'](19) != 8",
      "note" = "the dgbT8Band band-for boundaries",
    }, {
      "expr" = "m['dgbMinStrWuJen']() != 3",
      "note" = "the dgbMinStrWuJen pin",
    }, {
      "expr" = "m['dgbMinStrSpiritFolk']() != 6",
      "note" = "the dgbMinStrSpiritFolk pin",
    }, {
      "expr" = "m['dgbMinStrKorobokuru']() != 8",
      "note" = "the dgbMinStrKorobokuru pin",
    }, {
      "expr" = "m['dgbMinStrShukenja']() != 9",
      "note" = "the dgbMinStrShukenja pin",
    }, {
      "expr" = "m['dgbMinStrBushi']() != 9",
      "note" = "the dgbMinStrBushi pin",
    }, {
      "expr" = "m['dgbMinStrHengeyokai']() != 12",
      "note" = "the dgbMinStrHengeyokai pin",
    }, {
      "expr" = "m['dgbMinStrKensai']() != 12",
      "note" = "the dgbMinStrKensai pin",
    }, {
      "expr" = "m['dgbMinStrSamurai']() != 13",
      "note" = "the dgbMinStrSamurai pin",
    }, {
      "expr" = "m['dgbMinStrSohei']() != 13",
      "note" = "the dgbMinStrSohei pin",
    }, {
      "expr" = "m['dgbMinStrBarbarian']() != 15",
      "note" = "the dgbMinStrBarbarian pin",
    }, {
      "expr" = "m['dgbMinStrMonk']() != 15",
      "note" = "the dgbMinStrMonk pin",
    }, {
      "expr" = "m['dgbMaxStrShukenja']() != 18",
      "note" = "the dgbMaxStrShukenja pin",
    }, {
      "expr" = "m['dgbMaxStrMonk']() != 18",
      "note" = "the dgbMaxStrMonk pin",
    }, {
      "expr" = "m['dgbMaxStrWuJen']() != 18",
      "note" = "the dgbMaxStrWuJen pin",
    }, {
      "expr" = "m['dgbMaxStrYakuza']() != 18",
      "note" = "the dgbMaxStrYakuza pin",
    }, {
      "expr" = "m['dgbMaxStrHuman']() != 18",
      "note" = "the dgbMaxStrHuman pin",
    }, {
      "expr" = "m['dgbMaxStrKorobokuru']() != 19",
      "note" = "the dgbMaxStrKorobokuru pin",
    }, {
      "expr" = "m['dgbT2OpenDoorsRetry']() != 1",
      "note" = "the dgbT2OpenDoorsRetry pin",
    }, {
      "expr" = "m['dgbT2LockedOneAttempt']() != 1",
      "note" = "the dgbT2LockedOneAttempt pin",
    }, {
      "expr" = "m['dgbT2BendBarsOneAttempt']() != 1",
      "note" = "the dgbT2BendBarsOneAttempt pin",
    }, {
      "expr" = "m['dgbT2DmgFloorOne']() != 1",
      "note" = "the dgbT2DmgFloorOne pin",
    }, {
      "expr" = "m['dgbT2WeightSlowdown']() != 1",
      "note" = "the dgbT2WeightSlowdown pin",
    }, {
      "expr" = "m['dgbT2RowCount']() != 16",
      "note" = "the dgbT2RowCount pin",
    }, {
      "expr" = "m['dgbMinDexKorobokuru']() != 6",
      "note" = "the dgbMinDexKorobokuru pin",
    }, {
      "expr" = "m['dgbMinDexBushi']() != 8",
      "note" = "the dgbMinDexBushi pin",
    }, {
      "expr" = "m['dgbMinDexHengeyokai']() != 9",
      "note" = "the dgbMinDexHengeyokai pin",
    }, {
      "expr" = "m['dgbMinDexSpiritFolk']() != 12",
      "note" = "the dgbMinDexSpiritFolk pin",
    }, {
      "expr" = "m['dgbMinDexKensai']() != 14",
      "note" = "the dgbMinDexKensai pin",
    }, {
      "expr" = "m['dgbMinDexBarbarian']() != 14",
      "note" = "the dgbMinDexBarbarian pin",
    }, {
      "expr" = "m['dgbMinDexNinja']() != 14",
      "note" = "the dgbMinDexNinja pin",
    }, {
      "expr" = "m['dgbMinDexMonk']() != 15",
      "note" = "the dgbMinDexMonk pin",
    }, {
      "expr" = "m['dgbT3RowCount']() != 17",
      "note" = "the dgbT3RowCount pin",
    }, {
      "expr" = "m['dgbMinConSpiritFolk']() != 6",
      "note" = "the dgbMinConSpiritFolk pin",
    }, {
      "expr" = "m['dgbMinConBushi']() != 8",
      "note" = "the dgbMinConBushi pin",
    }, {
      "expr" = "m['dgbMinConShukenja']() != 9",
      "note" = "the dgbMinConShukenja pin",
    }, {
      "expr" = "m['dgbMinConSohei']() != 10",
      "note" = "the dgbMinConSohei pin",
    }, {
      "expr" = "m['dgbMinConMonk']() != 11",
      "note" = "the dgbMinConMonk pin",
    }, {
      "expr" = "m['dgbMinConKorobokuru']() != 12",
      "note" = "the dgbMinConKorobokuru pin",
    }, {
      "expr" = "m['dgbMinConHengeyokai']() != 12",
      "note" = "the dgbMinConHengeyokai pin",
    }, {
      "expr" = "m['dgbMinConSamurai']() != 13",
      "note" = "the dgbMinConSamurai pin",
    }, {
      "expr" = "m['dgbMaxConSpiritFolk']() != 14",
      "note" = "the dgbMaxConSpiritFolk pin",
    }, {
      "expr" = "m['dgbMinConBarbarian']() != 15",
      "note" = "the dgbMinConBarbarian pin",
    }, {
      "expr" = "m['dgbT4RowCount']() != 16",
      "note" = "the dgbT4RowCount pin",
    }, {
      "expr" = "m['dgbT4HitDieFloorOne']() != 1",
      "note" = "the dgbT4HitDieFloorOne pin",
    }, {
      "expr" = "m['dgbT4WarriorFullCon']() != 1",
      "note" = "the dgbT4WarriorFullCon pin",
    }, {
      "expr" = "m['dgbT4BarbarianFullCon']() != 1",
      "note" = "the dgbT4BarbarianFullCon pin",
    }, {
      "expr" = "m['dgbT4OthersCapTwo']() != 1",
      "note" = "the dgbT4OthersCapTwo pin",
    }, {
      "expr" = "m['dgbMinIntKorobokuru']() != 3",
      "note" = "the dgbMinIntKorobokuru pin",
    }, {
      "expr" = "m['dgbMinIntHengeyokai']() != 12",
      "note" = "the dgbMinIntHengeyokai pin",
    }, {
      "expr" = "m['dgbMinIntSpiritFolk']() != 12",
      "note" = "the dgbMinIntSpiritFolk pin",
    }, {
      "expr" = "m['dgbMinIntWuJen']() != 13",
      "note" = "the dgbMinIntWuJen pin",
    }, {
      "expr" = "m['dgbMinIntSamurai']() != 14",
      "note" = "the dgbMinIntSamurai pin",
    }, {
      "expr" = "m['dgbMinIntNinja']() != 15",
      "note" = "the dgbMinIntNinja pin",
    }, {
      "expr" = "m['dgbMaxIntKorobokuru']() != 15",
      "note" = "the dgbMaxIntKorobokuru pin",
    }, {
      "expr" = "m['dgbT5RowCount']() != 16",
      "note" = "the dgbT5RowCount pin",
    }, {
      "expr" = "m['dgbMinWisSpiritFolk']() != 9",
      "note" = "the dgbMinWisSpiritFolk pin",
    }, {
      "expr" = "m['dgbMinWisSohei']() != 10",
      "note" = "the dgbMinWisSohei pin",
    }, {
      "expr" = "m['dgbMinWisKensai']() != 12",
      "note" = "the dgbMinWisKensai pin",
    }, {
      "expr" = "m['dgbMinWisShukenja']() != 12",
      "note" = "the dgbMinWisShukenja pin",
    }, {
      "expr" = "m['dgbMinWisHengeyokai']() != 12",
      "note" = "the dgbMinWisHengeyokai pin",
    }, {
      "expr" = "m['dgbMinWisSamurai']() != 13",
      "note" = "the dgbMinWisSamurai pin",
    }, {
      "expr" = "m['dgbMinWisMonk']() != 15",
      "note" = "the dgbMinWisMonk pin",
    }, {
      "expr" = "m['dgbMaxWisBarbarian']() != 16",
      "note" = "the dgbMaxWisBarbarian pin",
    }, {
      "expr" = "m['dgbMaxWisKorobokuru']() != 17",
      "note" = "the dgbMaxWisKorobokuru pin",
    }, {
      "expr" = "m['dgbT6RowCount']() != 16",
      "note" = "the dgbT6RowCount pin",
    }, {
      "expr" = "m['dgbT6MindAuto']() != 1",
      "note" = "the dgbT6MindAuto pin",
    }, {
      "expr" = "m['dgbMinChaHengeyokai']() != 12",
      "note" = "the dgbMinChaHengeyokai pin",
    }, {
      "expr" = "m['dgbMinChaSpiritFolk']() != 14",
      "note" = "the dgbMinChaSpiritFolk pin",
    }, {
      "expr" = "m['dgbMinChaNinja']() != 14",
      "note" = "the dgbMinChaNinja pin",
    }, {
      "expr" = "m['dgbMaxChaKorobokuru']() != 16",
      "note" = "the dgbMaxChaKorobokuru pin",
    }, {
      "expr" = "m['dgbMaxChaHengeyokai']() != 17",
      "note" = "the dgbMaxChaHengeyokai pin",
    }, {
      "expr" = "m['dgbT7RowCount']() != 16",
      "note" = "the dgbT7RowCount pin",
    }, {
      "expr" = "m['dgbT8RowCount']() != 9",
      "note" = "the dgbT8RowCount pin",
    }, {
      "expr" = "m['dgbT8Band'](3) != 1",
      "note" = "the Table 8 band chain: Charisma 3 lands band 1",
    }, {
      "expr" = "m['dgbT8Band'](19) != 8",
      "note" = "the Table 8 band chain: Charisma 19 lands band 8",
    }, {
      "expr" = "m['dgbT2HitProb'](14) != 3  or m['dgbT2DmgAdj'](14) != 6  or m['dgbT2Weight'](14) != 3350  or m['dgbT2BendPct'](14) != 40",
      "note" = "the Table 2 18/00 row (capture p. 8)",
    }, {
      "expr" = "m['dgbT2OpenMax'](15) != 7  or m['dgbT2OpenLocked'](15) != 3",
      "note" = "the Table 2 Str 19 row prints 7-in-8 with the locked 3 (capture p. 8)",
    }, {
      "expr" = "m['dgbT3Reaction'](15) != 2  or m['dgbT3Defensive'](15) != -3",
      "note" = "the Table 3 Dexterity 18 row (capture p. 9)",
    }, {
      "expr" = "m['dgbT4WarriorHpAdj'](15) != 4  or m['dgbT4ResPct'](15) != 100",
      "note" = "the Table 4 Constitution 18 row: the warrior +4 and the 100 percent resurrection (capture p. 10)",
    }, {
      "expr" = "m['dgbT4WarriorHpAdj'](13) !=m['dgbT4HpAdj'](13)",
      "note" = "the Table 4 warrior column diverges from the common column only at 17 and 18 (capture p. 10)",
    }, {
      "expr" = "m['dgbT5Languages'](15) != 7  or m['dgbT5MaxSpellLevel'](15) != 9",
      "note" = "the Table 5 Intelligence 18 row (capture p. 11)",
    }, {
      "expr" = "m['dgbT6MagicAttack'](15) != 4",
      "note" = "the Table 6 Wisdom 18 row (capture pp. 11-12)",
    }, {
      "expr" = "m['dgbT7Henchmen'](15) != 15  or m['dgbT7Loyalty'](15) != 40  or m['dgbT7Reaction'](15) != 35",
      "note" = "the Table 7 Charisma 18 row (capture p. 12)",
    }, {
      "expr" = "m['dgbT4ShockPct'](0) != 35 or m['dgbT4ShockPct'](1) != 40 or m['dgbT4ShockPct'](2) != 45 or m['dgbT4ShockPct'](3) != 50 or m['dgbT4ShockPct'](4) != 55 or m['dgbT4ShockPct'](5) != 60 or m['dgbT4ShockPct'](6) != 65 or m['dgbT4ShockPct'](7) != 70",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgbT4ShockPct'](8) != 75 or m['dgbT4ShockPct'](9) != 80 or m['dgbT4ShockPct'](10) != 85 or m['dgbT4ShockPct'](11) != 88 or m['dgbT4ShockPct'](12) != 91 or m['dgbT4ShockPct'](13) != 95 or m['dgbT4ShockPct'](14) != 97 or m['dgbT4ShockPct'](15) != 99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgbT4ShockPct'](16) != -99 or m['dgbT8ChaMax'](0) != 2 or m['dgbT8ChaMax'](1) != 3 or m['dgbT8ChaMax'](2) != 5 or m['dgbT8ChaMax'](3) != 8 or m['dgbT8ChaMax'](4) != 12 or m['dgbT8ChaMax'](5) != 15 or m['dgbT8ChaMax'](6) != 17",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgbT8ChaMax'](7) != 18 or m['dgbT8ChaMax'](8) != 19 or m['dgbT8ChaMax'](9) != -99 or m['dgbT8Adj'](0) != -8 or m['dgbT8Adj'](1) != -5 or m['dgbT8Adj'](2) != -3 or m['dgbT8Adj'](3) != -1 or m['dgbT8Adj'](4) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgbT8Adj'](5) != 1 or m['dgbT8Adj'](6) != 2 or m['dgbT8Adj'](7) != 3 or m['dgbT8Adj'](8) != 5 or m['dgbT8Adj'](9) != -99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R615 OA ability tables audit",
      "comment" = "OA round two (capture pp. 7-13): the eight ability tables - the six grids (Strength Adjustments, Dexterity, Constitution, Intelligence, Wisdom, Charisma) with the Table 8 band chain and grid, the class and race annotations of the General Information columns, the Table 4 warrior-bonus footnote and the Table 2 one-attempt riders.",
    },
}
