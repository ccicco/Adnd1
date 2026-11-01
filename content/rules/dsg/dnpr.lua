-- dnpr: promoted from tools/spec_r521.json (the The DSG MINING PRODUCTS OF A MINE, R521: printed p. 50 (pdf 51) - the products rules: when a miner successfully locates minerals the player rolls 1d100 on Table 30 Mining Products (the nine bands - copper 01-30, tin 31-40, lead 41-66, iron 67-84, silver 85-92, gold 93-97, platinum 98, mithril 99, gemstones 00), the mithril possibility (the material needed for elven chain mail, a mithril mine only deep under the earth in the most solid of bedrock - if the locale qualifies the player rolls 1d10 on Table 31 Mithril Check, otherwise reroll on Table 30; Table 31 gives silver, gold and platinum at highest quality on 1-5/6-8/9 and mithril on 10), and the gemstone determination on Table 32 (sixteen stone types in d100 bands from bloodstone 01-08 and onyx 09-18 through emerald 93-96, with 97-99 rolling twice and 00 rolling three times - the 97-or-greater result grants its additional rolls immediately and any additional 97+ grants them again with no limit, a duplicated substance is noted as Jade x2 and yields twice the usual amount, and one quality level applies to all stones of a single type in a mine));
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 521,
  "prefix" = "dnpr",
  "banner" = {
      "title" = "The DSG MINING PRODUCTS OF A MINE, R521: printed p. 50 (pdf 51) - the products rules: when a miner successfully locates minerals the player rolls 1d100 on Table 30 Mining Products (the nine bands - copper 01-30, tin 31-40, lead 41-66, iron 67-84, silver 85-92, gold 93-97, platinum 98, mithril 99, gemstones 00), the mithril possibility (the material needed for elven chain mail, a mithril mine only deep under the earth in the most solid of bedrock - if the locale qualifies the player rolls 1d10 on Table 31 Mithril Check, otherwise reroll on Table 30; Table 31 gives silver, gold and platinum at highest quality on 1-5/6-8/9 and mithril on 10), and the gemstone determination on Table 32 (sixteen stone types in d100 bands from bloodstone 01-08 and onyx 09-18 through emerald 93-96, with 97-99 rolling twice and 00 rolling three times - the 97-or-greater result grants its additional rolls immediately and any additional 97+ grants them again with no limit, a duplicated substance is noted as Jade x2 and yields twice the usual amount, and one quality level applies to all stones of a single type in a mine)",
      "provenance" = "the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf = printed + 1; the text read from the IA djvu OCR (djvu.txt lines ~6588-6650) with the pdf Acrobat-Capture layer as the second read (idx 119-121 = printed pp. 49-51 window) and the compiled-tables appendix reprint as the third read. THE BLOODSTONE READ: the Table 32 01-08 row is the garble of the round - the djvu drops the row entirely (the table jumps from the header to 09-18 onyx), the Capture layer renders it as a \"-1/^^\" fragment, and the appendix reprint drops it too; all three machine reads fail the row, and it was settled as BLOODSTONE (01-08) by Curtiss reading the physical printed page 50 - the physical read outranks the scan. Everything else multi-confirms: the Table 30 nine bands (djvu clean, Capture corroborating iron 67-84 through gold 93-97, the appendix reprint corroborating the full ladder), the Table 31 four bands (djvu, Capture and appendix all agree on 1-5/6-8/9/10 with the highest-quality silver/gold/platinum), and the Table 32 bands from 09-18 onyx through 00 (djvu and Capture agree; the appendix adds the 55-60 amethyst row the chapter djvu dropped). The 1d10 mithril check pins as dice + sides consts per the R508 convention (the djvu \"1410\" and Capture \"ldlO\" garbles both read as 1d10). The 00 band pins as roll 100. The Tables 33-34 quality grids start the NEXT round per the content-density rule.",
      "sentinel" = "Three tables pin: Table 30 as a 9x2 d100 band grid (the 00 gemstones band pinned as roll 100), Table 31 as a 4x2 d10 band grid, and Table 32 as an 18x2 d100 band grid (sixteen stone types plus the roll-twice and roll-three-times bands, the 00 band as 100). The 1d100 products roll and the 1d10 mithril check pin as dice + sides consts per the R508 convention. The 97-or-greater extra-roll threshold pins as a const; the unlimited recursion, the duplicate doubling and the one-quality-per-type rules pin as prose bools. The 01-08 bloodstone row pins from the physical book read (the standing physical-outranks-scan lesson). The R518/R520 seams (DMG 106 rates, DSG 53 duration) are noted; nothing auto-credits.",
    },
  "consts" = { {
      "name" = "dnprT30RowCount",
      "value" = 9,
      "comment" = "the Table 30 mining products grid carries nine d100 bands (the 00 gemstones band pinned as roll 100).",
    }, {
      "name" = "dnprT30Dice",
      "value" = 1,
      "comment" = "the products roll is one die.",
    }, {
      "name" = "dnprT30Sides",
      "value" = 100,
      "comment" = "the products roll is 1d100 when a miner successfully locates minerals.",
    }, {
      "name" = "dnprMithrilCheckDice",
      "value" = 1,
      "comment" = "the mithril check roll is one die.",
    }, {
      "name" = "dnprMithrilCheckSides",
      "value" = 10,
      "comment" = "the mithril check roll is 1d10 compared to Table 31 (the djvu \"1410\" and Capture \"ldlO\" garbles both read as 1d10).",
    }, {
      "name" = "dnprT31RowCount",
      "value" = 4,
      "comment" = "the Table 31 mithril check grid carries the four d10 bands.",
    }, {
      "name" = "dnprT32RowCount",
      "value" = 18,
      "comment" = "the Table 32 gemstones grid carries eighteen d100 bands (sixteen stone types plus the roll-twice and roll-three-times bands).",
    }, {
      "name" = "dnprT32ExtraRollThreshold",
      "value" = 97,
      "comment" = "a roll of 97 or greater on Table 32 immediately grants the additional rolls indicated.",
    } },
  "bools" = { {
      "name" = "dnprRollT30OnLocatingMinerals",
      "value" = true,
      "comment" = "when a miner successfully locates minerals, the player rolls 1d100 and finds the result on Table 30: Mining Products.",
    }, {
      "name" = "dnprMithrilForElvenChainMail",
      "value" = true,
      "comment" = "the Table 30 mithril entry is the possibility of mithril, the material needed to create elven chain mail.",
    }, {
      "name" = "dnprMithrilOnlyDeepSolidBedrock",
      "value" = true,
      "comment" = "a mithril mine can only exist deep under the earth in the most solid of bedrock.",
    }, {
      "name" = "dnprMithrilElseRerollT30",
      "value" = true,
      "comment" = "if the locale of the mine is in such an area, the player rolls 1d10 against Table 31: Mithril Check; otherwise, reroll on the Mining Products table.",
    }, {
      "name" = "dnprT31MetalsHighestQuality",
      "value" = true,
      "comment" = "the Table 31 silver, gold and platinum results are the highest quality of their metal.",
    }, {
      "name" = "dnprT32ExtraRollsImmediate",
      "value" = true,
      "comment" = "if a 97 or greater is rolled on Table 32, the player immediately makes the additional rolls indicated.",
    }, {
      "name" = "dnprT32ExtraRollsNoLimit",
      "value" = true,
      "comment" = "any additional roll that again yields 97 or better grants its additional rolls - there is no limit to the number of rolls possible.",
    }, {
      "name" = "dnprT32DuplicateDoublesYield",
      "value" = true,
      "comment" = "a result yielding the same substance twice is noted (e.g., Jade x2) - the mine yields twice the usual amount of that mineral.",
    }, {
      "name" = "dnprT32OneQualityPerType",
      "value" = true,
      "comment" = "the same level of quality applies to all of a single type of stone found in a mine.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 30: MINING PRODUCTS",
      "tag" = "30",
      "count" = "dnprT30RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnprT30Lo", "dnprT30Hi" },
      "col_comments" = { "the product band low roll: 0 copper 01-30, 1 tin 31-40, 2 lead 41-66, 3 iron 67-84, 4 silver 85-92, 5 gold 93-97, 6 platinum 98, 7 mithril 99 (the elven-chain material, check Table 31 in deep solid bedrock, else reroll here), 8 gemstones 00 (roll on Table 32).", "the product band high roll: 30, 40, 66, 84, 92, 97, 98, 99, 100 (the 00 band pinned as 100)." },
      "audit_comment" = "the Table 30 mining products grid, the 1d100 products roll",
      "data" = { { 1, 30 }, { 31, 40 }, { 41, 66 }, { 67, 84 }, { 85, 92 }, { 93, 97 }, { 98, 98 }, { 99, 99 }, { 100, 100 } },
    }, {
      "name" = "Table 31: MITHRIL CHECK",
      "tag" = "31",
      "count" = "dnprT31RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnprT31Lo", "dnprT31Hi" },
      "col_comments" = { "the mithril check band low roll: 0 silver (highest quality) 1-5, 1 gold (highest quality) 6-8, 2 platinum (highest quality) 9, 3 mithril 10.", "the mithril check band high roll: 5, 8, 9, 10." },
      "audit_comment" = "the Table 31 mithril check grid, the 1d10 deep-bedrock locale check",
      "data" = { { 1, 5 }, { 6, 8 }, { 9, 9 }, { 10, 10 } },
    }, {
      "name" = "Table 32: GEMSTONES",
      "tag" = "32",
      "count" = "dnprT32RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnprT32Lo", "dnprT32Hi" },
      "col_comments" = { "the gemstone band low roll: 0 bloodstone 01-08, 1 onyx 09-18, 2 turquoise 19-24, 3 agate 25-30, 4 aquamarine 31-36, 5 garnet 37-42, 6 jade 43-48, 7 alexandrite 49-54, 8 amethyst 55-60, 9 topaz 61-66, 10 jet 67-72, 11 opal 73-77, 12 ruby 78-82, 13 sapphire 83-87, 14 diamond 88-92, 15 emerald 93-96, 16 roll twice 97-99, 17 roll three times 00.", "the gemstone band high roll: 8, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 77, 82, 87, 92, 96, 99, 100 (the 00 band pinned as 100)." },
      "audit_comment" = "the Table 32 gemstones grid, the products-roll gemstone lookup",
      "data" = { { 1, 8 }, { 9, 18 }, { 19, 24 }, { 25, 30 }, { 31, 36 }, { 37, 42 }, { 43, 48 }, { 49, 54 }, { 55, 60 }, { 61, 66 }, { 67, 72 }, { 73, 77 }, { 78, 82 }, { 83, 87 }, { 88, 92 }, { 93, 96 }, { 97, 99 }, { 100, 100 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnprT30Dice']() != 1 or m['dnprT30Sides']() != 100 or m['dnprMithrilCheckDice']() != 1 or m['dnprMithrilCheckSides']() != 10 or m['dnprT32ExtraRollThreshold']() != 97",
      "note" = "the products rolls: 1d100 on Table 30 when minerals are located, the 1d10 mithril check, and the 97-or-greater gemstone threshold.",
    }, {
      "expr" = "m['dnprT30RowCount']() != 9 or m['dnprT31RowCount']() != 4 or m['dnprT32RowCount']() != 18",
      "note" = "the grid row counts: nine product bands, four mithril-check bands, eighteen gemstone bands.",
    }, {
      "expr" = "m['dnprRollT30OnLocatingMinerals']() != 1 or m['dnprMithrilOnlyDeepSolidBedrock']() != 1 or m['dnprMithrilElseRerollT30']() != 1 or m['dnprT32ExtraRollsNoLimit']() != 1 or m['dnprT32DuplicateDoublesYield']() != 1",
      "note" = "the products prose: the roll-on-locate rule, the deep-solid-bedrock mithril locale with the Table 30 reroll, the unlimited 97+ recursion, and the Jade-x2 duplicate doubling.",
    } },
  "audit" = {
      "label" = "R521 DSG mining products audit",
      "comment" = "The DSG mining products pins the 1d100 products roll (the Table 30 nine bands from copper 01-30 through mithril 99 and gemstones 00, the 00 band pinned as 100), the mithril possibility (the elven-chain-mail material, a mine only deep under the earth in the most solid of bedrock, the 1d10 Table 31 check with the Table 30 reroll otherwise, silver/gold/platinum at highest quality on 1-5/6-8/9 and mithril on 10), and the gemstone determination (the Table 32 eighteen bands - bloodstone 01-08 from the physical book read, onyx through emerald, 97-99 twice, 00 three times, the 97+ immediate recursion without limit, the Jade-x2 duplicate doubling, and one quality level per stone type).",
    },
}
