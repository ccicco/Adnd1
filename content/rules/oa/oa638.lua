-- oa638: promoted from rules/oa/oaexch.h (the GAJIN AND RATES OF EXCHANGE AND TABLE 46, printed capture pp. 76-77 - the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 638,
  "prefix" = "oa638",
  "banner" = {
      "title" = "GAJIN AND RATES OF EXCHANGE AND TABLE 46, printed capture pp. 76-77 - the",
      "provenance" = "OA exchange round census 560 -> 561.  pinned from the 2018 print capture alone for this range (the settling authority): the first Mistral-OCR capture session is unavailable above p. 33, so the cross-capture agreement check is impossible. No contested cells detected within the single source: the T46 grid pins as nine currency rows x 4 cols - the real value as a fen-based absolute (every printed multi-value cell agrees in fen: the silver 10 fen or 2 yuan, the electrum 100 fen or 20 yuan or 1 tael, the gold 200 fen or 40 yuan or 2 tael, the platinum 1000 fen or 200 yuan or 10 tael or 1 ch'ien), the exchange rate as per-row lo-hi bounds in the row's own unit, the market-value rows pinned as the -99 sentinel with a market flag; the row order pins as the 0-8 code: fen, yuan, tael, ch'ien, copper piece, silver piece, electrum piece, gold piece, platinum piece. The prose street rates and the T46 standard rates differ AS PRINTED - the yuan 'also equal to one copper piece' beside the T46 five-copper real value, the tael 4-14 sp (2d6-2) street fetch beside the T46 2-12 sp - both pinned as printed, the prose as the export street rate, the table as the standard doctrine. OCR normalization: the silver rate prints '(1d6 - 7)' and reads as 1d6+7 fen (spanning 8-13), pinned as the dgySilverFenDieOffset const. The Equipping the Character prose with Table 47 (capture pp. 77-84) is deliberately left for the next round  the gap census after this round: 88 closed, 147 open - the Gajin and Rates of Exchange and Table 46 boxes flip (census 560 -> 561); NEXT - R639: the Equipping the Character prose with Table 47 (Basic Equipment and Supplies Cost), capture pp. 77-84, the eight cost lists, prefix dgz (verify free), audit \"R639 OA equipment audit\", include after rules/oa/oaexch.h",
    },
  "consts" = { {
      "name" = "dgyProseFenCp",
      "value" = 1,
      "comment" = "exchange prose (capture p. 77): one fen is equal to one copper piece - the export equality, agreeing with the T46 fen row real value",
    }, {
      "name" = "dgyProseYuanCp",
      "value" = 1,
      "comment" = "exchange prose (capture p. 77): a yuan is also equal to one copper piece when taken out - the export street rate, printed beside the T46 five-copper real value",
    }, {
      "name" = "dgyProseTaelSpLo",
      "value" = 4,
      "comment" = "exchange prose (capture p. 77): a tael generally fetches 4-14 silver pieces abroad",
    }, {
      "name" = "dgyProseTaelSpHi",
      "value" = 14,
      "comment" = "the upper bound of the tael street fetch in silver pieces (capture p. 77)",
    }, {
      "name" = "dgyTaelSpDieSub",
      "value" = 2,
      "comment" = "exchange prose (capture p. 77): the tael street fetch rolls as 2d6-2 silver pieces",
    }, {
      "name" = "dgyProseGoldTaelLo",
      "value" = 2,
      "comment" = "gajin prose (capture p. 76): gold prices typically range from 2-7 tael per gold piece when the coins are sold in Kara-Tur",
    }, {
      "name" = "dgyProseGoldTaelHi",
      "value" = 7,
      "comment" = "the upper bound of the gold-piece sale price in tael (capture p. 76)",
    }, {
      "name" = "dgySilverFenDieOffset",
      "value" = 7,
      "comment" = "gajin prose (capture p. 76): the silver-piece rate 8-13 fen rolls as 1d6+7 - the capture prints '(1d6 - 7)', a dash OCR read (1d6+7 spans 8-13)",
    }, {
      "name" = "dgyT46RowCount",
      "value" = 9,
      "comment" = "Table 46 (capture p. 77): nine currency exchange rows",
    } },
  "bools" = { {
      "name" = "dgyGajinExchangeNeed",
      "value" = true,
      "comment" = "gajin prose (capture p. 76): a campaign with gajin contact sooner or later has money crossing both ways, and the different coinages force the rates of exchange to be figured",
    }, {
      "name" = "dgyMoneylendersExchange",
      "value" = true,
      "comment" = "gajin prose (capture p. 76): along established caravan routes and in major trading ports moneylenders do business in exchanging the two coin types",
    }, {
      "name" = "dgyChaoWorthlessOutside",
      "value" = true,
      "comment" = "gajin prose (capture p. 76): the ch'ao is worthless except as an oddity outside of Kara-Tur - and even in some areas of Kara-Tur",
    }, {
      "name" = "dgyChaoConvertAdvice",
      "value" = true,
      "comment" = "gajin prose (capture p. 76): before traveling to gajin lands the character is well-advised to convert his ch'ao to something more substantial",
    }, {
      "name" = "dgyGoldNotAccepted",
      "value" = true,
      "comment" = "gajin prose (capture p. 76): gold coins are not accepted currency for purchases in Kara-Tur - they can only be sold, because they are gold, at the going price of gold",
    }, {
      "name" = "dgyGoldMarketFactors",
      "value" = true,
      "comment" = "gajin prose (capture p. 76): the gold price moves on the amount of gold on the market, the purity (gold coins generally not too pure in content), and the amount sold at once - a large sale floods the market and drives the price down",
    }, {
      "name" = "dgySilverForeignUndesired",
      "value" = true,
      "comment" = "gajin prose (capture p. 76): the foreign silver coins are somewhat smaller and of poorer quality than those found in Kara-Tur, and being foreign are not desired by merchants",
    }, {
      "name" = "dgyCopperMoreStandard",
      "value" = true,
      "comment" = "gajin prose (capture p. 76): copper pieces are somewhat more standard - characters can normally get one fen for every two copper pieces",
    }, {
      "name" = "dgyExportSmuggling",
      "value" = true,
      "comment" = "gajin prose (capture p. 77): lands with established currency keep their coins within their own lands - minted coinage leaving the country is bad for the economy, and exporting coins is smuggling, a criminal offense",
    }, {
      "name" = "dgyKtCoinsAbroad",
      "value" = true,
      "comment" = "gajin prose (capture p. 77): Kara-Tur coins smuggled out are more readily accepted abroad, other lands lacking a strong currency system",
    }, {
      "name" = "dgyCoinSpeculation",
      "value" = true,
      "comment" = "gajin prose (capture p. 77): it is possible for characters to gain or lose money (buying power) by speculating in coins - the motivation of the exchange doctrine",
    }, {
      "name" = "dgyRealValueDoctrine",
      "value" = true,
      "comment" = "the T46 notes (capture p. 77): Real Value is the absolute value of the coin exchanged, figured as if the two currencies were absolutely identical and exchanged at perfectly equal rates",
    }, {
      "name" = "dgyExchangeValueDoctrine",
      "value" = true,
      "comment" = "the T46 notes (capture p. 77): Exchange Value is the normal rate of exchange expected from merchants and moneylenders, normally given as a die range allowing less or more than the real value",
    }, {
      "name" = "dgyMarketPriceDoctrine",
      "value" = true,
      "comment" = "the T46 notes (capture p. 77): Market Price of Metal marks a coin with no equivalent in the other land and not accepted as normal currency - the character has to make a deal for the amount he receives",
    } },
  "switches" = { {
      "name" = "dgyT46RealFen",
      "values" = { 1, 5, 100, 1000, 1, 10, 100, 200, 1000 },
      "default" = -99,
      "comment" = "the real value as a fen-based absolute, by currency row - 0 fen, 1 yuan, 2 tael, 3 ch'ien, 4 copper piece, 5 silver piece, 6 electrum piece, 7 gold piece, 8 platinum piece; every printed multi-value cell agrees in fen - the silver 10 fen or 2 yuan, the electrum 100 fen or 20 yuan or 1 tael, the gold 200 fen or 40 yuan or 2 tael, the platinum 1000 fen or 200 yuan or 10 tael or 1 ch'ien (capture p. 77).",
    }, {
      "name" = "dgyT46ExchLo",
      "values" = { 1, 1, 2, 2, 2, 8, -99, -99, -99 },
      "default" = -99,
      "comment" = "the exchange-rate lower bound in the row's own unit - the fen and yuan rows one copper piece apiece, the tael 2-12 silver pieces, the ch'ien 2-8 gold pieces, the copper piece two coppers per fen, the silver piece 8-13 fen; -99 marks the market-value rows (capture p. 77).",
    }, {
      "name" = "dgyT46ExchHi",
      "values" = { 1, 1, 12, 8, 2, 13, -99, -99, -99 },
      "default" = -99,
      "comment" = "the exchange-rate upper bound in the row's own unit (capture p. 77).",
    }, {
      "name" = "dgyT46Market",
      "values" = { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
      "default" = -99,
      "comment" = "1 marks the market-value-of-metal rows - the electrum, gold and platinum pieces have no equivalent in the other land and are not accepted as normal currency (capture p. 77).",
    } },
  "tables" = { {
      "name" = "dgyT46Grid",
      "tag" = "T46",
      "count" = "dgyT46RowCount",
      "sentinel" = -99,
      "cols" = { "dgyT46RealFen", "dgyT46ExchLo", "dgyT46ExchHi", "dgyT46Market" },
      "data" = { { 1, 1, 1, 0 }, { 5, 1, 1, 0 }, { 100, 2, 12, 0 }, { 1000, 2, 8, 0 }, { 1, 2, 2, 0 }, { 10, 8, 13, 0 }, { 100, -99, -99, 1 }, { 200, -99, -99, 1 }, { 1000, -99, -99, 1 } },
      "comment" = "the Table 46 currency exchange rates grid (capture p. 77)",
      "col_comments" = { "the real value as a fen-based absolute, by currency row - 0 fen, 1 yuan, 2 tael, 3 ch'ien, 4 copper piece, 5 silver piece, 6 electrum piece, 7 gold piece, 8 platinum piece; every printed multi-value cell agrees in fen - the silver 10 fen or 2 yuan, the electrum 100 fen or 20 yuan or 1 tael, the gold 200 fen or 40 yuan or 2 tael, the platinum 1000 fen or 200 yuan or 10 tael or 1 ch'ien (capture p. 77).", "the exchange-rate lower bound in the row's own unit - the fen and yuan rows one copper piece apiece, the tael 2-12 silver pieces, the ch'ien 2-8 gold pieces, the copper piece two coppers per fen, the silver piece 8-13 fen; -99 marks the market-value rows (capture p. 77).", "the exchange-rate upper bound in the row's own unit (capture p. 77).", "1 marks the market-value-of-metal rows - the electrum, gold and platinum pieces have no equivalent in the other land and are not accepted as normal currency (capture p. 77)." },
      "audit_comment" = "the Table 46 grid: the currency real values, exchange bounds and market flags (capture p. 77)",
      "sentinel_census" = { 0, 3, 3, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgyT46RowCount']() != 9  or m['dgyProseFenCp']() != 1  or m['dgyProseYuanCp']() != 1  or m['dgyProseTaelSpLo']() != 4  or m['dgyProseTaelSpHi']() != 14  or m['dgyTaelSpDieSub']() != 2  or m['dgyProseGoldTaelLo']() != 2  or m['dgyProseGoldTaelHi']() != 7  or m['dgySilverFenDieOffset']() != 7  or  m['dgyGajinExchangeNeed']() != 1  or  m['dgyMoneylendersExchange']() != 1  or  m['dgyChaoWorthlessOutside']() != 1  or  m['dgyChaoConvertAdvice']() != 1  or  m['dgyGoldNotAccepted']() != 1  or  m['dgyGoldMarketFactors']() != 1  or  m['dgySilverForeignUndesired']() != 1  or  m['dgyCopperMoreStandard']() != 1  or  m['dgyExportSmuggling']() != 1  or  m['dgyKtCoinsAbroad']() != 1  or  m['dgyCoinSpeculation']() != 1  or  m['dgyRealValueDoctrine']() != 1  or  m['dgyExchangeValueDoctrine']() != 1  or  m['dgyMarketPriceDoctrine']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgyT46RowCount']() != 9",
      "note" = "the dgyT46RowCount pin",
    }, {
      "expr" = "m['dgyProseFenCp']() != 1",
      "note" = "the fen-copper equality pin",
    }, {
      "expr" = "m['dgyProseYuanCp']() != 1",
      "note" = "the yuan street rate pin",
    }, {
      "expr" = "m['dgyProseTaelSpLo']() != 4",
      "note" = "the tael street fetch lo pin",
    }, {
      "expr" = "m['dgyProseTaelSpHi']() != 14",
      "note" = "the tael street fetch hi pin",
    }, {
      "expr" = "m['dgyTaelSpDieSub']() != 2",
      "note" = "the tael 2d6-2 formula pin",
    }, {
      "expr" = "m['dgyProseGoldTaelLo']() != 2",
      "note" = "the gold sale lo pin",
    }, {
      "expr" = "m['dgyProseGoldTaelHi']() != 7",
      "note" = "the gold sale hi pin",
    }, {
      "expr" = "m['dgySilverFenDieOffset']() != 7",
      "note" = "the silver 1d6+7 offset pin",
    }, {
      "expr" = "m['dgyGajinExchangeNeed']() != 1",
      "note" = "the gajin-contact need pin",
    }, {
      "expr" = "m['dgyMoneylendersExchange']() != 1",
      "note" = "the moneylender pin",
    }, {
      "expr" = "m['dgyChaoWorthlessOutside']() != 1",
      "note" = "the worthless ch'ao pin",
    }, {
      "expr" = "m['dgyChaoConvertAdvice']() != 1",
      "note" = "the ch'ao convert advice pin",
    }, {
      "expr" = "m['dgyGoldNotAccepted']() != 1",
      "note" = "the gold-not-currency pin",
    }, {
      "expr" = "m['dgyGoldMarketFactors']() != 1",
      "note" = "the gold market factors pin",
    }, {
      "expr" = "m['dgySilverForeignUndesired']() != 1",
      "note" = "the undesired foreign silver pin",
    }, {
      "expr" = "m['dgyCopperMoreStandard']() != 1",
      "note" = "the standard copper pin",
    }, {
      "expr" = "m['dgyExportSmuggling']() != 1",
      "note" = "the export smuggling pin",
    }, {
      "expr" = "m['dgyKtCoinsAbroad']() != 1",
      "note" = "the Kara-Tur coins abroad pin",
    }, {
      "expr" = "m['dgyCoinSpeculation']() != 1",
      "note" = "the coin speculation pin",
    }, {
      "expr" = "m['dgyRealValueDoctrine']() != 1",
      "note" = "the real-value doctrine pin",
    }, {
      "expr" = "m['dgyExchangeValueDoctrine']() != 1",
      "note" = "the exchange-value doctrine pin",
    }, {
      "expr" = "m['dgyMarketPriceDoctrine']() != 1",
      "note" = "the market-price doctrine pin",
    }, {
      "expr" = "m['dgyT46RealFen'](0) != 1  or m['dgyT46ExchLo'](0) != 1  or m['dgyT46ExchHi'](0) != 1  or m['dgyT46Market'](0) != 0",
      "note" = "the T46 fen row - real one copper piece, one copper piece for one fen (capture p. 77)",
    }, {
      "expr" = "m['dgyT46RealFen'](1) != 5  or m['dgyT46ExchLo'](1) != 1  or m['dgyT46ExchHi'](1) != 1  or m['dgyT46Market'](1) != 0",
      "note" = "the T46 yuan row - real five copper pieces, one copper piece for one yuan (capture p. 77)",
    }, {
      "expr" = "m['dgyT46RealFen'](2) != 100  or m['dgyT46ExchLo'](2) != 2  or m['dgyT46ExchHi'](2) != 12  or m['dgyT46Market'](2) != 0",
      "note" = "the T46 tael row - real ten silver pieces (100 fen), 2-12 silver pieces for one tael (capture p. 77)",
    }, {
      "expr" = "m['dgyT46RealFen'](3) != 1000  or m['dgyT46ExchLo'](3) != 2  or m['dgyT46ExchHi'](3) != 8  or m['dgyT46Market'](3) != 0",
      "note" = "the T46 ch'ien row - real 100 silver pieces or 5 gold pieces (1000 fen), 2-8 gold pieces for one ch'ien (capture p. 77)",
    }, {
      "expr" = "m['dgyT46RealFen'](4) != 1  or m['dgyT46ExchLo'](4) != 2  or m['dgyT46ExchHi'](4) != 2  or m['dgyT46Market'](4) != 0",
      "note" = "the T46 copper piece row - real one fen, one fen for two copper pieces (capture p. 77)",
    }, {
      "expr" = "m['dgyT46RealFen'](5) != 10  or m['dgyT46ExchLo'](5) != 8  or m['dgyT46ExchHi'](5) != 13  or m['dgyT46Market'](5) != 0",
      "note" = "the T46 silver piece row - real 10 fen or 2 yuan, 8-13 fen for one silver piece (capture p. 77)",
    }, {
      "expr" = "m['dgyT46RealFen'](6) != 100  or m['dgyT46ExchLo'](6) != -99  or m['dgyT46ExchHi'](6) != -99  or m['dgyT46Market'](6) != 1",
      "note" = "the T46 electrum piece row - real 100 fen or 20 yuan or one tael, market value of metal (capture p. 77)",
    }, {
      "expr" = "m['dgyT46RealFen'](7) != 200  or m['dgyT46ExchLo'](7) != -99  or m['dgyT46ExchHi'](7) != -99  or m['dgyT46Market'](7) != 1",
      "note" = "the T46 gold piece row - real 200 fen or 40 yuan or two tael, market value of metal (capture p. 77)",
    }, {
      "expr" = "m['dgyT46RealFen'](8) != 1000  or m['dgyT46ExchLo'](8) != -99  or m['dgyT46ExchHi'](8) != -99  or m['dgyT46Market'](8) != 1",
      "note" = "the T46 platinum piece row - real 1000 fen or 200 yuan or 10 tael or one ch'ien, market value of metal (capture p. 77)",
    } },
  "audit" = {
      "label" = "R638 OA exchange audit",
      "comment" = "OA round twenty-five (capture pp. 76-77): the gajin and rates of exchange prose and the Table 46 exchange grid",
    },
}
