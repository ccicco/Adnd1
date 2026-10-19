// =========================================================================================
// Adnd1 - rules/oastart.h
// STARTING MONEY AND TABLE 45, printed capture pp. 75-76 - the OA funds round
// census 559 -> 560.
//
// pinned from the 2018 print capture alone for this range (the settling
// authority): the first Mistral-OCR capture session is unavailable above p.
// 33, so the cross-capture agreement check is impossible. No contested cells
// detected within the single source: the T45 grid pins as ten class rows x 8
// bounds - the ch'ien, tael, yuan and fen components each as a lo-hi pair, a
// 0-0 pair meaning the row has no such component; the tael amounts read as
// (ch'ao) - the R636 ch'ao-tael equality covers the note. The class row order
// pins as the 0-9 code: samurai, shukenja, monk, sohei, kensai, barbarian,
// bushi, wu jen, ninja, yakuza. The ninja footnote (the amount in addition to
// the other class cash) pins as a bool. The Gajin and Rates of Exchange prose
// with Table 46 (capture pp. 76-77) are deliberately left for the next round
//
// the gap census after this round: 86 closed, 149 open - the Starting Money
// and Table 45 boxes flip (census 559 -> 560); NEXT - R638: the Gajin and
// Rates of Exchange prose with Table 46 (Currency Exchange Rates), capture
// pp. 76-77, the real-value and exchange-rate doctrine, prefix dgy (verify
// free), audit "R638 OA exchange audit", include after rules/oastart.h
//
namespace rules {

// ---- the starting money pins ----

// Table 45 (capture p. 76): ten class funds rows
inline int dgxT45RowCount()
    { return 10; }

// Starting money prose (capture p. 75): player characters are unusual - more
// daring and resourceful - and have accumulated more capital than the
// average, since their expenses are greater
inline bool dgxPcUnusualCapital()
    { return true; }

// Starting money prose (capture p. 75): the starting funds come by finding
// the class and rolling the appropriate dice - money available to purchase
// equipment, in addition to anything received as a birthright
inline bool dgxClassFundsRoll()
    { return true; }

// Starting money prose (capture p. 75): in barter campaigns the DM translates
// each character's cash into appropriate barter units, rounding leftovers to
// the nearest barter unit
inline bool dgxBarterTranslation()
    { return true; }

// ---- the Table 45 grid ----

// the ch'ien funds lower bound, by class row - 0 samurai, 1 shukenja, 2 monk,
// 3 sohei, 4 kensai, 5 barbarian, 6 bushi, 7 wu jen, 8 ninja, 9 yakuza; a 0-0
// pair means no such component (capture p. 76).
inline int dgxT45ChienLo(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        default:
            return -99;
        }
    }

// the ch'ien funds upper bound (capture p. 76).
inline int dgxT45ChienHi(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 4;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 3;
        case 8:
            return 2;
        case 9:
            return 3;
        default:
            return -99;
        }
    }

// the tael funds lower bound - the tael amounts read as (ch'ao), the
// equal-value note (capture p. 76).
inline int dgxT45TaelLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 0;
        case 9:
            return 2;
        default:
            return -99;
        }
    }

// the tael funds upper bound (capture p. 76).
inline int dgxT45TaelHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 5;
        case 2:
            return 0;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 6;
        case 6:
            return 4;
        case 7:
            return 20;
        case 8:
            return 0;
        case 9:
            return 20;
        default:
            return -99;
        }
    }

// the yuan funds lower bound (capture p. 76).
inline int dgxT45YuanLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        default:
            return -99;
        }
    }

// the yuan funds upper bound (capture p. 76).
inline int dgxT45YuanHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 20;
        case 2:
            return 40;
        case 3:
            return 40;
        case 4:
            return 0;
        case 5:
            return 100;
        case 6:
            return 40;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        default:
            return -99;
        }
    }

// the fen funds lower bound (capture p. 76).
inline int dgxT45FenLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        default:
            return -99;
        }
    }

// the fen funds upper bound (capture p. 76).
inline int dgxT45FenHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 100;
        case 2:
            return 200;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 200;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        default:
            return -99;
        }
    }

// T45 footnote (capture p. 76): the ninja amount is in addition to any cash
// the character receives from his other character class
inline bool dgxNinjaAdditionalFunds()
    { return true; }

}   // namespace rules
