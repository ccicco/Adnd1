// =========================================================================================
// Adnd1 - rules/oaexch.h
// GAJIN AND RATES OF EXCHANGE AND TABLE 46, printed capture pp. 76-77 - the
// OA exchange round
// census 560 -> 561.
//
// pinned from the 2018 print capture alone for this range (the settling
// authority): the first Mistral-OCR capture session is unavailable above p.
// 33, so the cross-capture agreement check is impossible. No contested cells
// detected within the single source: the T46 grid pins as nine currency rows
// x 4 cols - the real value as a fen-based absolute (every printed
// multi-value cell agrees in fen: the silver 10 fen or 2 yuan, the electrum
// 100 fen or 20 yuan or 1 tael, the gold 200 fen or 40 yuan or 2 tael, the
// platinum 1000 fen or 200 yuan or 10 tael or 1 ch'ien), the exchange rate as
// per-row lo-hi bounds in the row's own unit, the market-value rows pinned as
// the -99 sentinel with a market flag; the row order pins as the 0-8 code:
// fen, yuan, tael, ch'ien, copper piece, silver piece, electrum piece, gold
// piece, platinum piece. The prose street rates and the T46 standard rates
// differ AS PRINTED - the yuan 'also equal to one copper piece' beside the
// T46 five-copper real value, the tael 4-14 sp (2d6-2) street fetch beside
// the T46 2-12 sp - both pinned as printed, the prose as the export street
// rate, the table as the standard doctrine. OCR normalization: the silver
// rate prints '(1d6 - 7)' and reads as 1d6+7 fen (spanning 8-13), pinned as
// the dgySilverFenDieOffset const. The Equipping the Character prose with
// Table 47 (capture pp. 77-84) is deliberately left for the next round
//
// the gap census after this round: 88 closed, 147 open - the Gajin and Rates
// of Exchange and Table 46 boxes flip (census 560 -> 561); NEXT - R639: the
// Equipping the Character prose with Table 47 (Basic Equipment and Supplies
// Cost), capture pp. 77-84, the eight cost lists, prefix dgz (verify free),
// audit "R639 OA equipment audit", include after rules/oaexch.h
//
namespace rules {

// ---- the gajin exchange pins ----

// exchange prose (capture p. 77): one fen is equal to one copper piece - the
// export equality, agreeing with the T46 fen row real value
inline int dgyProseFenCp()
    { return 1; }

// exchange prose (capture p. 77): a yuan is also equal to one copper piece
// when taken out - the export street rate, printed beside the T46 five-copper
// real value
inline int dgyProseYuanCp()
    { return 1; }

// exchange prose (capture p. 77): a tael generally fetches 4-14 silver pieces
// abroad
inline int dgyProseTaelSpLo()
    { return 4; }

// the upper bound of the tael street fetch in silver pieces (capture p. 77)
inline int dgyProseTaelSpHi()
    { return 14; }

// exchange prose (capture p. 77): the tael street fetch rolls as 2d6-2 silver
// pieces
inline int dgyTaelSpDieSub()
    { return 2; }

// gajin prose (capture p. 76): gold prices typically range from 2-7 tael per
// gold piece when the coins are sold in Kara-Tur
inline int dgyProseGoldTaelLo()
    { return 2; }

// the upper bound of the gold-piece sale price in tael (capture p. 76)
inline int dgyProseGoldTaelHi()
    { return 7; }

// gajin prose (capture p. 76): the silver-piece rate 8-13 fen rolls as 1d6+7
// - the capture prints '(1d6 - 7)', a dash OCR read (1d6+7 spans 8-13)
inline int dgySilverFenDieOffset()
    { return 7; }

// gajin prose (capture p. 76): a campaign with gajin contact sooner or later
// has money crossing both ways, and the different coinages force the rates of
// exchange to be figured
inline bool dgyGajinExchangeNeed()
    { return true; }

// gajin prose (capture p. 76): along established caravan routes and in major
// trading ports moneylenders do business in exchanging the two coin types
inline bool dgyMoneylendersExchange()
    { return true; }

// gajin prose (capture p. 76): the ch'ao is worthless except as an oddity
// outside of Kara-Tur - and even in some areas of Kara-Tur
inline bool dgyChaoWorthlessOutside()
    { return true; }

// gajin prose (capture p. 76): before traveling to gajin lands the character
// is well-advised to convert his ch'ao to something more substantial
inline bool dgyChaoConvertAdvice()
    { return true; }

// gajin prose (capture p. 76): gold coins are not accepted currency for
// purchases in Kara-Tur - they can only be sold, because they are gold, at
// the going price of gold
inline bool dgyGoldNotAccepted()
    { return true; }

// gajin prose (capture p. 76): the gold price moves on the amount of gold on
// the market, the purity (gold coins generally not too pure in content), and
// the amount sold at once - a large sale floods the market and drives the
// price down
inline bool dgyGoldMarketFactors()
    { return true; }

// gajin prose (capture p. 76): the foreign silver coins are somewhat smaller
// and of poorer quality than those found in Kara-Tur, and being foreign are
// not desired by merchants
inline bool dgySilverForeignUndesired()
    { return true; }

// gajin prose (capture p. 76): copper pieces are somewhat more standard -
// characters can normally get one fen for every two copper pieces
inline bool dgyCopperMoreStandard()
    { return true; }

// gajin prose (capture p. 77): lands with established currency keep their
// coins within their own lands - minted coinage leaving the country is bad
// for the economy, and exporting coins is smuggling, a criminal offense
inline bool dgyExportSmuggling()
    { return true; }

// gajin prose (capture p. 77): Kara-Tur coins smuggled out are more readily
// accepted abroad, other lands lacking a strong currency system
inline bool dgyKtCoinsAbroad()
    { return true; }

// gajin prose (capture p. 77): it is possible for characters to gain or lose
// money (buying power) by speculating in coins - the motivation of the
// exchange doctrine
inline bool dgyCoinSpeculation()
    { return true; }

// ---- the Table 46 grid ----

// Table 46 (capture p. 77): nine currency exchange rows
inline int dgyT46RowCount()
    { return 9; }

// the real value as a fen-based absolute, by currency row - 0 fen, 1 yuan, 2
// tael, 3 ch'ien, 4 copper piece, 5 silver piece, 6 electrum piece, 7 gold
// piece, 8 platinum piece; every printed multi-value cell agrees in fen - the
// silver 10 fen or 2 yuan, the electrum 100 fen or 20 yuan or 1 tael, the
// gold 200 fen or 40 yuan or 2 tael, the platinum 1000 fen or 200 yuan or 10
// tael or 1 ch'ien (capture p. 77).
inline int dgyT46RealFen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 100;
        case 3:
            return 1000;
        case 4:
            return 1;
        case 5:
            return 10;
        case 6:
            return 100;
        case 7:
            return 200;
        case 8:
            return 1000;
        default:
            return -99;
        }
    }

// the exchange-rate lower bound in the row's own unit - the fen and yuan rows
// one copper piece apiece, the tael 2-12 silver pieces, the ch'ien 2-8 gold
// pieces, the copper piece two coppers per fen, the silver piece 8-13 fen;
// -99 marks the market-value rows (capture p. 77).
inline int dgyT46ExchLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 8;
        case 6:
            return -99;
        case 7:
            return -99;
        case 8:
            return -99;
        default:
            return -99;
        }
    }

// the exchange-rate upper bound in the row's own unit (capture p. 77).
inline int dgyT46ExchHi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 12;
        case 3:
            return 8;
        case 4:
            return 2;
        case 5:
            return 13;
        case 6:
            return -99;
        case 7:
            return -99;
        case 8:
            return -99;
        default:
            return -99;
        }
    }

// 1 marks the market-value-of-metal rows - the electrum, gold and platinum
// pieces have no equivalent in the other land and are not accepted as normal
// currency (capture p. 77).
inline int dgyT46Market(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        default:
            return -99;
        }
    }

// the T46 notes (capture p. 77): Real Value is the absolute value of the coin
// exchanged, figured as if the two currencies were absolutely identical and
// exchanged at perfectly equal rates
inline bool dgyRealValueDoctrine()
    { return true; }

// the T46 notes (capture p. 77): Exchange Value is the normal rate of
// exchange expected from merchants and moneylenders, normally given as a die
// range allowing less or more than the real value
inline bool dgyExchangeValueDoctrine()
    { return true; }

// the T46 notes (capture p. 77): Market Price of Metal marks a coin with no
// equivalent in the other land and not accepted as normal currency - the
// character has to make a deal for the amount he receives
inline bool dgyMarketPriceDoctrine()
    { return true; }

}   // namespace rules
