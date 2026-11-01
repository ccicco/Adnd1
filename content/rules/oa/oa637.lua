-- oa637: promoted from rules/oastart.h (the STARTING MONEY AND TABLE 45, printed capture pp. 75-76 - the OA funds round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 637,
  "prefix" = "oa637",
  "banner" = {
      "title" = "STARTING MONEY AND TABLE 45, printed capture pp. 75-76 - the OA funds round",
      "provenance" = "census 559 -> 560.  pinned from the 2018 print capture alone for this range (the settling authority): the first Mistral-OCR capture session is unavailable above p. 33, so the cross-capture agreement check is impossible. No contested cells detected within the single source: the T45 grid pins as ten class rows x 8 bounds - the ch'ien, tael, yuan and fen components each as a lo-hi pair, a 0-0 pair meaning the row has no such component; the tael amounts read as (ch'ao) - the R636 ch'ao-tael equality covers the note. The class row order pins as the 0-9 code: samurai, shukenja, monk, sohei, kensai, barbarian, bushi, wu jen, ninja, yakuza. The ninja footnote (the amount in addition to the other class cash) pins as a bool. The Gajin and Rates of Exchange prose with Table 46 (capture pp. 76-77) are deliberately left for the next round  the gap census after this round: 86 closed, 149 open - the Starting Money and Table 45 boxes flip (census 559 -> 560); NEXT - R638: the Gajin and Rates of Exchange prose with Table 46 (Currency Exchange Rates), capture pp. 76-77, the real-value and exchange-rate doctrine, prefix dgy (verify free), audit \"R638 OA exchange audit\", include after rules/oastart.h",
    },
  "consts" = { {
      "name" = "dgxT45RowCount",
      "value" = 10,
      "comment" = "Table 45 (capture p. 76): ten class funds rows",
    } },
  "bools" = { {
      "name" = "dgxPcUnusualCapital",
      "value" = true,
      "comment" = "Starting money prose (capture p. 75): player characters are unusual - more daring and resourceful - and have accumulated more capital than the average, since their expenses are greater",
    }, {
      "name" = "dgxClassFundsRoll",
      "value" = true,
      "comment" = "Starting money prose (capture p. 75): the starting funds come by finding the class and rolling the appropriate dice - money available to purchase equipment, in addition to anything received as a birthright",
    }, {
      "name" = "dgxBarterTranslation",
      "value" = true,
      "comment" = "Starting money prose (capture p. 75): in barter campaigns the DM translates each character's cash into appropriate barter units, rounding leftovers to the nearest barter unit",
    }, {
      "name" = "dgxNinjaAdditionalFunds",
      "value" = true,
      "comment" = "T45 footnote (capture p. 76): the ninja amount is in addition to any cash the character receives from his other character class",
    } },
  "switches" = { {
      "name" = "dgxT45ChienLo",
      "values" = { 2, 0, 0, 0, 1, 0, 0, 1, 1, 1 },
      "default" = -99,
      "comment" = "the ch'ien funds lower bound, by class row - 0 samurai, 1 shukenja, 2 monk, 3 sohei, 4 kensai, 5 barbarian, 6 bushi, 7 wu jen, 8 ninja, 9 yakuza; a 0-0 pair means no such component (capture p. 76).",
    }, {
      "name" = "dgxT45ChienHi",
      "values" = { 12, 0, 0, 0, 4, 0, 0, 3, 2, 3 },
      "default" = -99,
      "comment" = "the ch'ien funds upper bound (capture p. 76).",
    }, {
      "name" = "dgxT45TaelLo",
      "values" = { 1, 1, 0, 1, 1, 1, 1, 2, 0, 2 },
      "default" = -99,
      "comment" = "the tael funds lower bound - the tael amounts read as (ch'ao), the equal-value note (capture p. 76).",
    }, {
      "name" = "dgxT45TaelHi",
      "values" = { 10, 5, 0, 10, 10, 6, 4, 20, 0, 20 },
      "default" = -99,
      "comment" = "the tael funds upper bound (capture p. 76).",
    }, {
      "name" = "dgxT45YuanLo",
      "values" = { 0, 2, 4, 4, 0, 1, 4, 0, 0, 0 },
      "default" = -99,
      "comment" = "the yuan funds lower bound (capture p. 76).",
    }, {
      "name" = "dgxT45YuanHi",
      "values" = { 0, 20, 40, 40, 0, 100, 40, 0, 0, 0 },
      "default" = -99,
      "comment" = "the yuan funds upper bound (capture p. 76).",
    }, {
      "name" = "dgxT45FenLo",
      "values" = { 0, 1, 2, 0, 0, 0, 2, 0, 0, 0 },
      "default" = -99,
      "comment" = "the fen funds lower bound (capture p. 76).",
    }, {
      "name" = "dgxT45FenHi",
      "values" = { 0, 100, 200, 0, 0, 0, 200, 0, 0, 0 },
      "default" = -99,
      "comment" = "the fen funds upper bound (capture p. 76).",
    } },
  "tables" = { {
      "name" = "dgxT45Grid",
      "tag" = "T45",
      "count" = "dgxT45RowCount",
      "sentinel" = -99,
      "cols" = { "dgxT45ChienLo", "dgxT45ChienHi", "dgxT45TaelLo", "dgxT45TaelHi", "dgxT45YuanLo", "dgxT45YuanHi", "dgxT45FenLo", "dgxT45FenHi" },
      "data" = { { 2, 12, 1, 10, 0, 0, 0, 0 }, { 0, 0, 1, 5, 2, 20, 1, 100 }, { 0, 0, 0, 0, 4, 40, 2, 200 }, { 0, 0, 1, 10, 4, 40, 0, 0 }, { 1, 4, 1, 10, 0, 0, 0, 0 }, { 0, 0, 1, 6, 1, 100, 0, 0 }, { 0, 0, 1, 4, 4, 40, 2, 200 }, { 1, 3, 2, 20, 0, 0, 0, 0 }, { 1, 2, 0, 0, 0, 0, 0, 0 }, { 1, 3, 2, 20, 0, 0, 0, 0 } },
      "comment" = "the Table 45 initial character funds grid (capture p. 76)",
      "col_comments" = { "the ch'ien funds lower bound, by class row - 0 samurai, 1 shukenja, 2 monk, 3 sohei, 4 kensai, 5 barbarian, 6 bushi, 7 wu jen, 8 ninja, 9 yakuza; a 0-0 pair means no such component (capture p. 76).", "the ch'ien funds upper bound (capture p. 76).", "the tael funds lower bound - the tael amounts read as (ch'ao), the equal-value note (capture p. 76).", "the tael funds upper bound (capture p. 76).", "the yuan funds lower bound (capture p. 76).", "the yuan funds upper bound (capture p. 76).", "the fen funds lower bound (capture p. 76).", "the fen funds upper bound (capture p. 76)." },
      "audit_comment" = "the Table 45 grid: the class funds bounds (capture p. 76)",
      "sentinel_census" = { 0, 0, 0, 0, 0, 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgxT45RowCount']() != 10  or  m['dgxPcUnusualCapital']() != 1  or  m['dgxClassFundsRoll']() != 1  or  m['dgxBarterTranslation']() != 1  or  m['dgxNinjaAdditionalFunds']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgxT45RowCount']() != 10",
      "note" = "the dgxT45RowCount pin",
    }, {
      "expr" = "m['dgxPcUnusualCapital']() != 1",
      "note" = "the dgxPcUnusualCapital pin",
    }, {
      "expr" = "m['dgxClassFundsRoll']() != 1",
      "note" = "the dgxClassFundsRoll pin",
    }, {
      "expr" = "m['dgxBarterTranslation']() != 1",
      "note" = "the dgxBarterTranslation pin",
    }, {
      "expr" = "m['dgxNinjaAdditionalFunds']() != 1",
      "note" = "the dgxNinjaAdditionalFunds pin",
    }, {
      "expr" = "m['dgxT45ChienLo'](0) != 2  or m['dgxT45ChienHi'](0) != 12  or m['dgxT45TaelLo'](0) != 1  or m['dgxT45TaelHi'](0) != 10",
      "note" = "the T45 samurai row - the 2-12 ch'ien and 1-10 tael (capture p. 76)",
    }, {
      "expr" = "m['dgxT45TaelLo'](1) != 1  or m['dgxT45TaelHi'](1) != 5  or m['dgxT45YuanLo'](1) != 2  or m['dgxT45YuanHi'](1) != 20  or m['dgxT45FenLo'](1) != 1  or m['dgxT45FenHi'](1) != 100",
      "note" = "the T45 shukenja row - the 1-5 tael, 2-20 yuan, 1-100 fen (capture p. 76)",
    }, {
      "expr" = "m['dgxT45YuanLo'](2) != 4  or m['dgxT45YuanHi'](2) != 40  or m['dgxT45FenLo'](2) != 2  or m['dgxT45FenHi'](2) != 200",
      "note" = "the T45 monk row - the 4-40 yuan and 2-200 fen (capture p. 76)",
    }, {
      "expr" = "m['dgxT45TaelLo'](3) != 1  or m['dgxT45TaelHi'](3) != 10  or m['dgxT45YuanLo'](3) != 4  or m['dgxT45YuanHi'](3) != 40",
      "note" = "the T45 sohei row - the 1-10 tael and 4-40 yuan (capture p. 76)",
    }, {
      "expr" = "m['dgxT45ChienLo'](4) != 1  or m['dgxT45ChienHi'](4) != 4  or m['dgxT45TaelLo'](4) != 1  or m['dgxT45TaelHi'](4) != 10",
      "note" = "the T45 kensai row - the 1-4 ch'ien and 1-10 tael (capture p. 76)",
    }, {
      "expr" = "m['dgxT45TaelLo'](5) != 1  or m['dgxT45TaelHi'](5) != 6  or m['dgxT45YuanLo'](5) != 1  or m['dgxT45YuanHi'](5) != 100",
      "note" = "the T45 barbarian row - the 1-6 tael and 1-100 yuan (capture p. 76)",
    }, {
      "expr" = "m['dgxT45TaelLo'](6) != 1  or m['dgxT45TaelHi'](6) != 4  or m['dgxT45YuanLo'](6) != 4  or m['dgxT45YuanHi'](6) != 40  or m['dgxT45FenLo'](6) != 2  or m['dgxT45FenHi'](6) != 200",
      "note" = "the T45 bushi row - the 1-4 tael, 4-40 yuan, 2-200 fen (capture p. 76)",
    }, {
      "expr" = "m['dgxT45ChienLo'](7) != 1  or m['dgxT45ChienHi'](7) != 3  or m['dgxT45TaelLo'](7) != 2  or m['dgxT45TaelHi'](7) != 20  or m['dgxT45ChienLo'](9) != 1  or m['dgxT45ChienHi'](9) != 3  or m['dgxT45TaelLo'](9) != 2  or m['dgxT45TaelHi'](9) != 20",
      "note" = "the T45 wu jen and yakuza rows - the identical 1-3 ch'ien and 2-20 tael (capture p. 76)",
    }, {
      "expr" = "m['dgxT45ChienLo'](8) != 1  or m['dgxT45ChienHi'](8) != 2  or m['dgxT45TaelLo'](8) != 0  or m['dgxT45RowCount']() != 10",
      "note" = "the T45 ninja row - the 1-2 ch'ien alone, ten rows only (capture p. 76)",
    } },
  "audit" = {
      "label" = "R637 OA starting money audit",
      "comment" = "OA round twenty-four (capture pp. 75-76): the starting money prose and the Table 45 funds grid",
    },
}
