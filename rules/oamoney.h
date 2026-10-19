// =========================================================================================
// Adnd1 - rules/oamoney.h
// THE MONEY OPENER, THE CURRENCY DOCTRINE AND TABLES 43-44, printed capture
// pp. 73-75 - the OA money round
// census 558 -> 559.
//
// pinned from the 2018 print capture alone for this range (the settling
// authority): the first Mistral-OCR capture session is unavailable above p.
// 33, so the cross-capture agreement check is impossible. No contested cells
// detected within the single source: the T43 conversion matrix pins as the
// coin-value consts - the fen-basis values with the printed cross ratios,
// including the ch'ao-tael equality (the yuan 5 fen, the ch'ao 100 fen or 20
// yuan, the tael 100 fen, 20 yuan or one ch'ao, the ch'ien 1000 fen, 200
// yuan, 10 ch'ao and 10 tael); the T44 grid pins as five barter rows in the
// ch'ien and tael value columns (the koku 5 ch'ien, the sheep or goat 5 tael,
// the horse 2 ch'ien, the common and silk bolts 1 and 3 ch'ien). OCR
// normalization: the systems prose reads "[x]" placeholders for the printed
// blanks ("one coin can buy [x] amount of rice") - they pin nothing numeric;
// the em dashes of the print read normally. The Starting Money prose and
// Table 45 (capture pp. 75-76) and the Gajin exchange prose with Table 46
// (capture pp. 76-77) are deliberately left for the next rounds
//
// the gap census after this round: 84 closed, 151 open - the Currency prose,
// Table 43, Table 44 and the Chapter 5 parent (opens) boxes flip (census 558
// -> 559); NEXT - R637: the Starting Money prose and Table 45 (Initial
// Character Funds), capture pp. 75-76, the class funds dice, prefix dgx
// (verify free), audit "R637 OA starting money audit", include after
// rules/oamoney.h
//
namespace rules {

// ---- the coinage pins ----

// Coins prose (capture p. 75): one yuan equals five fen
inline int dgwYuanFen()
    { return 5; }

// Ch'ao prose (capture p. 75): one ch'ao equals 100 fen
inline int dgwChaoFen()
    { return 100; }

// Ch'ao prose (capture p. 75): one ch'ao equals 20 yuan
inline int dgwChaoYuan()
    { return 20; }

// Tael prose (capture p. 75): one tael equals 100 fen
inline int dgwTaelFen()
    { return 100; }

// Tael prose (capture p. 75): one tael equals 20 yuan
inline int dgwTaelYuan()
    { return 20; }

// Tael prose (capture p. 75): one tael equals one ch'ao - the two coins are
// equal in value
inline int dgwTaelChao()
    { return 1; }

// Ch'ien prose (capture p. 75): one ch'ien equals 1000 fen
inline int dgwChienFen()
    { return 1000; }

// Ch'ien prose (capture p. 75): one ch'ien equals 200 yuan
inline int dgwChienYuan()
    { return 200; }

// Ch'ien prose (capture p. 75): one ch'ien equals 10 ch'ao
inline int dgwChienChao()
    { return 10; }

// Ch'ien prose (capture p. 75): one ch'ien equals 10 tael
inline int dgwChienTael()
    { return 10; }

// Coins prose (capture p. 75): the cash strings run 50 to 100 coins
inline int dgwCashStringMin()
    { return 50; }

// Coins prose (capture p. 75): the cash string upper bound, 100 coins
inline int dgwCashStringMax()
    { return 100; }

// Ch'ao prose (capture p. 75): the most common notes run one, ten and 100
inline int dgwChaoNoteMax()
    { return 100; }

// Coins prose (capture pp. 74-75): Kara-Tur uses copper, silver and paper
// currency - gold is not a proper form of currency and is reserved for
// artistic and craft purposes
inline bool dgwGoldNotCurrency()
    { return true; }

// Coins prose (capture p. 75): each coin is pierced through the center and
// threaded on cash strings, tucked in the sleeve - simplifying the carrying
// and the counting
inline bool dgwCoinsPiercedAndStrung()
    { return true; }

// Ch'ao prose (capture p. 75): the ch'ao is a paper note, preferred when
// dealing in amounts of 100 fen or greater
inline bool dgwChaoPaperNote()
    { return true; }

// Ch'ien prose (capture p. 75): the ch'ien is rarely used in everyday
// transactions since it is awkward to carry, and is hoarded for times when
// the copper and paper money falls in value
inline bool dgwChienHoarded()
    { return true; }

// Opener prose (capture pp. 73-74): refined nobles support the arts, field
// armies, provide for followers, build public works, maintain households and
// give gifts; lesser status spends on clothing, equipment, lodgings and
// artistic tastes
inline bool dgwNobleSpending()
    { return true; }

// ---- the monetary systems pins ----

// Systems prose (capture p. 74): Shou Lung prints paper money, T'u Lung mints
// regular coinage, Kozakura uses the coins of others, the warlords
// occasionally mint coins, and the barbarian tribes live without minted coins
// - barter and direct trade only
inline bool dgwSystemsDivergent()
    { return true; }

// Established currency prose (capture p. 74): the government controls the
// minting with uniform coins backed by the imperial treasury, issues paper
// money beyond true value, oversees market prices, takes taxes in grain -
// barter uncommon, haggling expected for the larger purchases
inline bool dgwEstablishedCurrency()
    { return true; }

// Regular currency prose (capture p. 74): the coins are not always regular in
// size or shape, the value follows the metal content, weighing coins is not
// uncommon, the larger purchases run by barter - land via gems, art, services
// or a crop share
inline bool dgwRegularCurrency()
    { return true; }

// Irregular currency prose (capture p. 74): foreign coins are used without
// prejudice, every coin is worth only its precious metal content, paper money
// is useless, wealth is measured by the goods and contracts held, and the
// legal systems enforce the contracts
inline bool dgwIrregularCurrency()
    { return true; }

// Pure barter prose (capture p. 74): wealth is measured purely by the goods
// owned, contracts are generally not drawn, purchases trade equal value,
// haggling is a must, the legal systems stay informal and the reputation as
// dealer or cheat moves the prices
inline bool dgwPureBarter()
    { return true; }

// Systems prose (capture p. 74): characters normally deal with a single
// system - the DM picks by campaign area and may choose the simplest system
// so as not to slow the play
inline bool dgwDmChoosesSystem()
    { return true; }

// ---- the barter units pins ----

// Barter units prose (capture p. 75): the koku is approximately 5 to 6
// bushels of rice, the lower bound
inline int dgwKokuBushelsMin()
    { return 5; }

// Barter units prose (capture p. 75): the koku bushel upper bound
inline int dgwKokuBushelsMax()
    { return 6; }

// Barter units prose (capture p. 75): a bolt of cloth contains 20 yards of
// material
inline int dgwClothBoltYards()
    { return 20; }

// Table 44 (capture p. 75): five barter-unit rows
inline int dgwT44RowCount()
    { return 5; }

// the barter-unit value column in ch'ien - the row order pins as the 0-4
// code: koku, sheep or goat, horse, common cloth bolt, silk cloth bolt; a 0
// means the value is denominated in the tael column (capture p. 75).
inline int dgwT44Chien(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 3;
        default:
            return -99;
        }
    }

// the barter-unit value column in tael - the sheep and goat row reads 5 tael;
// the other rows are denominated in ch'ien (capture p. 75).
inline int dgwT44Tael(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        default:
            return -99;
        }
    }

// Barter units prose (capture p. 75): a barter unit is a set amount of goods
// seen as having a specific value - the farmer in koku of rice, the nomad in
// horses, the merchant in bolts of cloth
inline bool dgwBarterUnitDoctrine()
    { return true; }

// Barter units prose (capture p. 75): the buying power of livestock and cloth
// varies greatly with the quality - the well-fed horse and the fine cloth
// fetch higher prices
inline bool dgwQualityVariesValue()
    { return true; }

}   // namespace rules
