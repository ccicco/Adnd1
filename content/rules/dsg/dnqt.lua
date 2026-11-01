-- dnqt: promoted from tools/spec_r522.json (the The DSG QUALITY OF MINE PRODUCTS, R522: printed pp. 50-51 (pdf 51-52) - the metals rules: the quality of the metal or ore equals the coins producible from the metal mined by a single miner in a week (the ore usually heavily mixed with rock, the smelter proficiency processing it to pure state, the rare pure-nugget vein), the Table 33 ore quality grid over the 1d10 roll for five metals (copper 100/200/250/300/350/400/500/750/1000/2000, iron 200/300/500/700/900/1200/1600/2000/3000/4000, silver 25/50/100/200/300/400/500/750/1000/2000, gold 10/25/50/100/200/300/400/500/750/1000, platinum 5/10/20/40/75/100/250/400/800/1000), the pure-vein rule (a 10 on the quality roll means roll again - another 10 is a pure vein requiring no smelting, 1-9 smelts normally), the unsmelted selling (no more than 25%, possibly 5%, by the buyer's transport and smelting difficulty), and the iron equivalences (1000 coins of iron = a full plate suit, 100 spear points, or 500 arrowheads); and the gemstones rules: the rough unrecognized stones identified by miner or jeweler proficiency after 1d6 turns of study, the quality as stones per man-week and average value of the finished stones (Table 34 - bloodstone 2d10 at 20 + 10d6 gp, amber 1d10 at 6d100 gp, onyx 3d10 at 10 + 10d6 gp, turquoise and agate 4d10 at 5d6 gp, aquamarine 1d10 at 10 x 5d6 gp, garnet and alexandrite 1d10 at 100 x 1d4 gp, jade 2d10 at 10 x 5d6 gp, amethyst 1d10 at 100 x 1d6 gp, topaz 2d10 at 100 x 1d4 gp, jet 1d10 at 10 x 5d6 gp, opal 1d10/3 at 200 x 1d6 gp, ruby 1d10/3 at 200 x 1d8 gp, sapphire 1d10/4 at 200 x 1d8 gp, diamond 1d10/5 at 300 x 1d6 gp, emerald 1d10/5 at 300 x 1d8 gp, the footnote rows rolling 1d10 divided by 3/4/5 and rounded up), the unfinished selling (no greater than 25%, possibly 10%), and the weekly value re-roll (the week's quality applying to all miners that week, the miner count set before the rolls));
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 522,
  "prefix" = "dnqt",
  "banner" = {
      "title" = "The DSG QUALITY OF MINE PRODUCTS, R522: printed pp. 50-51 (pdf 51-52) - the metals rules: the quality of the metal or ore equals the coins producible from the metal mined by a single miner in a week (the ore usually heavily mixed with rock, the smelter proficiency processing it to pure state, the rare pure-nugget vein), the Table 33 ore quality grid over the 1d10 roll for five metals (copper 100/200/250/300/350/400/500/750/1000/2000, iron 200/300/500/700/900/1200/1600/2000/3000/4000, silver 25/50/100/200/300/400/500/750/1000/2000, gold 10/25/50/100/200/300/400/500/750/1000, platinum 5/10/20/40/75/100/250/400/800/1000), the pure-vein rule (a 10 on the quality roll means roll again - another 10 is a pure vein requiring no smelting, 1-9 smelts normally), the unsmelted selling (no more than 25%, possibly 5%, by the buyer's transport and smelting difficulty), and the iron equivalences (1000 coins of iron = a full plate suit, 100 spear points, or 500 arrowheads); and the gemstones rules: the rough unrecognized stones identified by miner or jeweler proficiency after 1d6 turns of study, the quality as stones per man-week and average value of the finished stones (Table 34 - bloodstone 2d10 at 20 + 10d6 gp, amber 1d10 at 6d100 gp, onyx 3d10 at 10 + 10d6 gp, turquoise and agate 4d10 at 5d6 gp, aquamarine 1d10 at 10 x 5d6 gp, garnet and alexandrite 1d10 at 100 x 1d4 gp, jade 2d10 at 10 x 5d6 gp, amethyst 1d10 at 100 x 1d6 gp, topaz 2d10 at 100 x 1d4 gp, jet 1d10 at 10 x 5d6 gp, opal 1d10/3 at 200 x 1d6 gp, ruby 1d10/3 at 200 x 1d8 gp, sapphire 1d10/4 at 200 x 1d8 gp, diamond 1d10/5 at 300 x 1d6 gp, emerald 1d10/5 at 300 x 1d8 gp, the footnote rows rolling 1d10 divided by 3/4/5 and rounded up), the unfinished selling (no greater than 25%, possibly 10%), and the weekly value re-roll (the week's quality applying to all miners that week, the miner count set before the rolls)",
      "provenance" = "the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf = printed + 1; the machine reads are the IA djvu OCR (djvu.txt lines ~6625-6700), the pdf Acrobat-Capture layer (idx 121 = printed pp. 50-51 window, idx 122 = the Table 34 page) and the compiled-tables appendix reprint. THE OCR-FAILURE ROUND: both grids are the garble of the round, and the garbles are text the OCR layers simply failed - the Table 33 copper and iron rows are dropped by every machine read (the appendix keeps only a 2000/4000 tail glimpse), and the Table 34 machine reads lost the stone labels and shuffled the count/value cells into fragments. Both grids were settled by Curtiss reading the physical pages via screenshot: Table 33 from the printed p. 50 screenshot (two vision passes agreeing on all fifty cells; the iron row was read twice digit by digit), Table 34 from two printed p. 51 screenshots with the final contested cell - onyx 10 + 10d6 gp - settled by Curtiss's direct read after the vision passes wobbled the operator and die count. The machine reads corroborate the T33 silver/gold/platinum rows (djvu and Capture agree with the appendix on all three) and the T34 middle rows (the appendix fragments confirm agate 4d10, amethyst 100 x 1d6, topaz 100 x 1d4, emerald 1d10/5 at 300 x 1d8, diamond 1d10/5, the opal/ruby/sapphire 200-multiplier band, and the onyx 10d6 tail). The physical book outranks the scan (the R521 bloodstone lesson, now twice exercised). NOTE: amber appears in Table 34 but not in Table 32's gemstone list - pinned as printed per the R517 never-repair lesson. The quality grids pin as numeric engine tables (T33 five metal columns over ten rolls; T34 seven columns encoding count dice/sides/divisor and value add/mult/dice/sides). The placer-value, smelting and duration rules start the NEXT round per the content-density rule.",
      "sentinel" = "Two tables pin: Table 33 as a 10x5 quality grid (one column per metal, ten rows for the d10 rolls), and Table 34 as a 17x7 grid encoding each stone row as count dice, count sides, divide divisor, value addend, value multiplier, value dice and value sides - the dice expressions pinned as numbers per the R508 dice convention, with the divisor column carrying the /3 /4 /5 footnote rows. The 1d10 ore quality roll and the 1d6-turn identification pin as dice + sides consts. The pure-vein 10, the selling percentages (ore 25/5, stones 25/10) and the iron equivalences (1000/100/500) pin as consts. The smelter processing, the pure-vein rules, the weekly re-roll applying to all miners, and the round-up footnote pin as prose bools. The physical-read provenance is load-bearing for the T33 copper/iron rows and the T34 top rows; the R517 seam (amber absent from Table 32) is noted; nothing auto-credits.",
    },
  "consts" = { {
      "name" = "dnqtT33RowCount",
      "value" = 10,
      "comment" = "the Table 33 ore quality grid carries the ten d10 quality rolls.",
    }, {
      "name" = "dnqtT34RowCount",
      "value" = 17,
      "comment" = "the Table 34 gemstone quality grid carries seventeen stone rows.",
    }, {
      "name" = "dnqtOreQualityDice",
      "value" = 1,
      "comment" = "the ore quality roll is one die.",
    }, {
      "name" = "dnqtOreQualitySides",
      "value" = 10,
      "comment" = "the ore quality roll is 1d10 compared on Table 33; the result is the coins of metal the mine yields in one man-week.",
    }, {
      "name" = "dnqtOrePureVeinRoll",
      "value" = 10,
      "comment" = "a 10 on the quality roll means roll 1d10 again; another 10 is a pure vein of metal.",
    }, {
      "name" = "dnqtUnsmeltedOreSellMaxPct",
      "value" = 25,
      "comment" = "ore sold without smelting brings no more than 25% of the pure metal value.",
    }, {
      "name" = "dnqtUnsmeltedOreSellMinPct",
      "value" = 5,
      "comment" = "unsmelted ore might bring as low as 5% of the pure metal worth.",
    }, {
      "name" = "dnqtIronCoinPlate",
      "value" = 1000,
      "comment" = "one thousand coins worth of iron equals a full suit of plate armor.",
    }, {
      "name" = "dnqtIronCoinSpearPoints",
      "value" = 100,
      "comment" = "one thousand coins worth of iron equals 100 spear points.",
    }, {
      "name" = "dnqtIronCoinArrowheads",
      "value" = 500,
      "comment" = "one thousand coins worth of iron equals 500 arrowheads.",
    }, {
      "name" = "dnqtStoneIdentifyDice",
      "value" = 1,
      "comment" = "the stone identification study is one die of turns (miner or jeweler proficiency).",
    }, {
      "name" = "dnqtStoneIdentifySides",
      "value" = 6,
      "comment" = "a proficient character identifies a rough stone after 1d6 turns of study; others simply see another rock.",
    }, {
      "name" = "dnqtUnfinishedStonesSellMaxPct",
      "value" = 25,
      "comment" = "unfinished stones sell for no greater than 25% of the listed value.",
    }, {
      "name" = "dnqtUnfinishedStonesSellMinPct",
      "value" = 10,
      "comment" = "unfinished stones might sell for as low as 10% of the listed value.",
    } },
  "bools" = { {
      "name" = "dnqtOreMixedWithRock",
      "value" = true,
      "comment" = "a metal mine usually yields the metal in its ore form, heavily mixed with rock.",
    }, {
      "name" = "dnqtSmelterPurifies",
      "value" = true,
      "comment" = "generally a character with smelter proficiency must process the ore to its pure metallic state (a very pure nugget vein may occasionally be discovered).",
    }, {
      "name" = "dnqtQualityCoinsPerMinerWeek",
      "value" = true,
      "comment" = "the quality of the metal or ore equals the number of coins producible from the metal mined by a single miner in a week.",
    }, {
      "name" = "dnqtPureVeinNeedsNoSmelting",
      "value" = true,
      "comment" = "a 10 followed by another 10 on the quality roll is a pure vein of metal requiring no smelting.",
    }, {
      "name" = "dnqtPureVeinSmeltOtherwise",
      "value" = true,
      "comment" = "if the second quality roll is 1-9, the metal must be smelted normally.",
    }, {
      "name" = "dnqtCoinageIndicatesMetalAmount",
      "value" = true,
      "comment" = "the coinage amount indicates how much metal is produced - it does not mean the metal must be used to make coins (particularly true of iron).",
    }, {
      "name" = "dnqtStonesRoughUnrecognized",
      "value" = true,
      "comment" = "gemstones fresh from the mine are rough, often unrecognizable, and not nearly as valuable as after finishing.",
    }, {
      "name" = "dnqtMinerOrJewelerIdentifies",
      "value" = true,
      "comment" = "characters with miner or jeweler proficiency can correctly identify a stone after study; others simply see another rock.",
    }, {
      "name" = "dnqtStoneCountPerMinerWeek",
      "value" = true,
      "comment" = "the number of stones is the amount that one miner can excavate in a week; the value is the average for the finished stones.",
    }, {
      "name" = "dnqtStoneValueRolledEachWeek",
      "value" = true,
      "comment" = "the value of a gemstone find does not remain constant - it is rolled each week for that week's output.",
    }, {
      "name" = "dnqtQualityAppliesAllMinersWeek",
      "value" = true,
      "comment" = "the quality determined for the week applies to all miners working that entire week, and the number of miners is determined before the dice rolls.",
    }, {
      "name" = "dnqtDivideAndRoundUp",
      "value" = true,
      "comment" = "for the Table 34 division rows, roll 1d10, divide the result by 3, 4, or 5 as indicated, and round up.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 33: ORE QUALITY",
      "tag" = "33",
      "count" = "dnqtT33RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnqtT33Copper", "dnqtT33Iron", "dnqtT33Silver", "dnqtT33Gold", "dnqtT33Platinum" },
      "col_comments" = { "the copper coins per man-week by d10 roll 1-10: 100, 200, 250, 300, 350, 400, 500, 750, 1000, 2000 (physical read; the machine reads lost the copper row).", "the iron coins per man-week: 200, 300, 500, 700, 900, 1200, 1600, 2000, 3000, 4000 (physical read; the iron row is dropped by every machine read - the appendix keeps only the 2000/4000 tail glimpses).", "the silver coins per man-week: 25, 50, 100, 200, 300, 400, 500, 750, 1000, 2000.", "the gold coins per man-week: 10, 25, 50, 100, 200, 300, 400, 500, 750, 1000.", "the platinum coins per man-week: 5, 10, 20, 40, 75, 100, 250, 400, 800, 1000." },
      "audit_comment" = "the Table 33 ore quality grid, the 1d10 coins-per-man-week rolls for five metals",
      "data" = { { 100, 200, 25, 10, 5 }, { 200, 300, 50, 25, 10 }, { 250, 500, 100, 50, 20 }, { 300, 700, 200, 100, 40 }, { 350, 900, 300, 200, 75 }, { 400, 1200, 400, 300, 100 }, { 500, 1600, 500, 400, 250 }, { 750, 2000, 750, 500, 400 }, { 1000, 3000, 1000, 750, 800 }, { 2000, 4000, 2000, 1000, 1000 } },
    }, {
      "name" = "Table 34: GEMSTONE QUALITY",
      "tag" = "34",
      "count" = "dnqtT34RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnqtT34CountDice", "dnqtT34CountSides", "dnqtT34CountDiv", "dnqtT34ValAdd", "dnqtT34ValMult", "dnqtT34ValDice", "dnqtT34ValSides" },
      "col_comments" = { "the stones-per-man-week die count, in the printed row order bloodstone through emerald: 2, 1, 3, 4, 4, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1.", "the stones-per-man-week die sides: d10 throughout.", "the divide-and-round-up divisor (the footnote rows): 1 everywhere except opal 3, ruby 3, sapphire 4, diamond 5, emerald 5.", "the additive base of the average value: bloodstone 20 (20 + 10d6 gp), onyx 10 (10 + 10d6 gp), all other rows 0.", "the average-value multiplier: 1 except aquamarine 10, garnet 100, jade 10, alexandrite 100, amethyst 100, topaz 100, jet 10, opal 200, ruby 200, sapphire 200, diamond 300, emerald 300.", "the average-value die count: bloodstone 10, amber 6, onyx 10, turquoise 5, agate 5, aquamarine 5, garnet 1, jade 5, alexandrite 1, amethyst 1, topaz 1, jet 5, opal 1, ruby 1, sapphire 1, diamond 1, emerald 1.", "the average-value die sides: 6, 100, 6, 6, 6, 6, 4, 6, 4, 6, 4, 6, 6, 8, 8, 6, 8 (amber 6d100 gp; the printed order is as pinned)." },
      "audit_comment" = "the Table 34 gemstone quality grid, the seventeen stone rows in count and average value",
      "data" = { { 2, 10, 1, 20, 1, 10, 6 }, { 1, 10, 1, 0, 1, 6, 100 }, { 3, 10, 1, 10, 1, 10, 6 }, { 4, 10, 1, 0, 1, 5, 6 }, { 4, 10, 1, 0, 1, 5, 6 }, { 1, 10, 1, 0, 10, 5, 6 }, { 1, 10, 1, 0, 100, 1, 4 }, { 2, 10, 1, 0, 10, 5, 6 }, { 1, 10, 1, 0, 100, 1, 4 }, { 1, 10, 1, 0, 100, 1, 6 }, { 2, 10, 1, 0, 100, 1, 4 }, { 1, 10, 1, 0, 10, 5, 6 }, { 1, 10, 3, 0, 200, 1, 6 }, { 1, 10, 3, 0, 200, 1, 8 }, { 1, 10, 4, 0, 200, 1, 8 }, { 1, 10, 5, 0, 300, 1, 6 }, { 1, 10, 5, 0, 300, 1, 8 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnqtOreQualityDice']() != 1 or m['dnqtOreQualitySides']() != 10 or m['dnqtOrePureVeinRoll']() != 10 or m['dnqtStoneIdentifyDice']() != 1 or m['dnqtStoneIdentifySides']() != 6",
      "note" = "the rolls: the 1d10 ore quality roll with the roll-again pure vein 10, and the 1d6-turn stone identification study.",
    }, {
      "expr" = "m['dnqtUnsmeltedOreSellMaxPct']() != 25 or m['dnqtUnsmeltedOreSellMinPct']() != 5 or m['dnqtUnfinishedStonesSellMaxPct']() != 25 or m['dnqtUnfinishedStonesSellMinPct']() != 10 or m['dnqtIronCoinPlate']() != 1000 or m['dnqtIronCoinSpearPoints']() != 100 or m['dnqtIronCoinArrowheads']() != 500",
      "note" = "the selling and equivalence numbers: unsmelted ore 25%-5%, unfinished stones 25%-10%, and the 1000-coin iron equivalents (plate suit, 100 spear points, 500 arrowheads).",
    }, {
      "expr" = "m['dnqtQualityCoinsPerMinerWeek']() != 1 or m['dnqtPureVeinNeedsNoSmelting']() != 1 or m['dnqtPureVeinSmeltOtherwise']() != 1 or m['dnqtStoneValueRolledEachWeek']() != 1 or m['dnqtQualityAppliesAllMinersWeek']() != 1 or m['dnqtDivideAndRoundUp']() != 1",
      "note" = "the quality prose: coins per single miner per week, the pure-vein 10-again rule, the weekly value re-roll applying to all miners that week, and the divide-and-round-up footnote.",
    } },
  "audit" = {
      "label" = "R522 DSG mine product quality audit",
      "comment" = "The DSG mine product quality pins the ore quality roll (the Table 33 five-metal d10 coins-per-man-week grid - copper 100 through 2000, iron 200 through 4000, silver 25 through 2000, gold 10 through 1000, platinum 5 through 1000), the pure-vein rule (the 10-again roll, another 10 needing no smelting, 1-9 smelting normally), the unsmelted ore selling at 25% to 5%, the iron equivalences (1000 coins a plate suit, 100 spear points, 500 arrowheads), and the gemstone quality (the Table 34 seventeen rows from bloodstone 2d10 at 20 + 10d6 gp through emerald 1d10/5 at 300 x 1d8 gp, the 1d6-turn identification, the unfinished selling at 25% to 10%, and the weekly re-roll applying to all miners that week).",
    },
}
