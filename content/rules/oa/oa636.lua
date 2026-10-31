-- oa636: promoted from rules/oamoney.h (the THE MONEY OPENER, THE CURRENCY DOCTRINE AND TABLES 43-44, printed capture);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 636,
  "prefix" = "oa636",
  "banner" = {
      "title" = "THE MONEY OPENER, THE CURRENCY DOCTRINE AND TABLES 43-44, printed capture",
      "provenance" = "pp. 73-75 - the OA money round census 558 -> 559.  pinned from the 2018 print capture alone for this range (the settling authority): the first Mistral-OCR capture session is unavailable above p. 33, so the cross-capture agreement check is impossible. No contested cells detected within the single source: the T43 conversion matrix pins as the coin-value consts - the fen-basis values with the printed cross ratios, including the ch'ao-tael equality (the yuan 5 fen, the ch'ao 100 fen or 20 yuan, the tael 100 fen, 20 yuan or one ch'ao, the ch'ien 1000 fen, 200 yuan, 10 ch'ao and 10 tael); the T44 grid pins as five barter rows in the ch'ien and tael value columns (the koku 5 ch'ien, the sheep or goat 5 tael, the horse 2 ch'ien, the common and silk bolts 1 and 3 ch'ien). OCR normalization: the systems prose reads \"[x]\" placeholders for the printed blanks (\"one coin can buy [x] amount of rice\") - they pin nothing numeric; the em dashes of the print read normally. The Starting Money prose and Table 45 (capture pp. 75-76) and the Gajin exchange prose with Table 46 (capture pp. 76-77) are deliberately left for the next rounds  the gap census after this round: 84 closed, 151 open - the Currency prose, Table 43, Table 44 and the Chapter 5 parent (opens) boxes flip (census 558 -> 559); NEXT - R637: the Starting Money prose and Table 45 (Initial Character Funds), capture pp. 75-76, the class funds dice, prefix dgx (verify free), audit \"R637 OA starting money audit\", include after rules/oamoney.h",
    },
  "consts" = { {
      "name" = "dgwYuanFen",
      "value" = 5,
      "comment" = "Coins prose (capture p. 75): one yuan equals five fen",
    }, {
      "name" = "dgwChaoFen",
      "value" = 100,
      "comment" = "Ch'ao prose (capture p. 75): one ch'ao equals 100 fen",
    }, {
      "name" = "dgwChaoYuan",
      "value" = 20,
      "comment" = "Ch'ao prose (capture p. 75): one ch'ao equals 20 yuan",
    }, {
      "name" = "dgwTaelFen",
      "value" = 100,
      "comment" = "Tael prose (capture p. 75): one tael equals 100 fen",
    }, {
      "name" = "dgwTaelYuan",
      "value" = 20,
      "comment" = "Tael prose (capture p. 75): one tael equals 20 yuan",
    }, {
      "name" = "dgwTaelChao",
      "value" = 1,
      "comment" = "Tael prose (capture p. 75): one tael equals one ch'ao - the two coins are equal in value",
    }, {
      "name" = "dgwChienFen",
      "value" = 1000,
      "comment" = "Ch'ien prose (capture p. 75): one ch'ien equals 1000 fen",
    }, {
      "name" = "dgwChienYuan",
      "value" = 200,
      "comment" = "Ch'ien prose (capture p. 75): one ch'ien equals 200 yuan",
    }, {
      "name" = "dgwChienChao",
      "value" = 10,
      "comment" = "Ch'ien prose (capture p. 75): one ch'ien equals 10 ch'ao",
    }, {
      "name" = "dgwChienTael",
      "value" = 10,
      "comment" = "Ch'ien prose (capture p. 75): one ch'ien equals 10 tael",
    }, {
      "name" = "dgwCashStringMin",
      "value" = 50,
      "comment" = "Coins prose (capture p. 75): the cash strings run 50 to 100 coins",
    }, {
      "name" = "dgwCashStringMax",
      "value" = 100,
      "comment" = "Coins prose (capture p. 75): the cash string upper bound, 100 coins",
    }, {
      "name" = "dgwChaoNoteMax",
      "value" = 100,
      "comment" = "Ch'ao prose (capture p. 75): the most common notes run one, ten and 100",
    }, {
      "name" = "dgwKokuBushelsMin",
      "value" = 5,
      "comment" = "Barter units prose (capture p. 75): the koku is approximately 5 to 6 bushels of rice, the lower bound",
    }, {
      "name" = "dgwKokuBushelsMax",
      "value" = 6,
      "comment" = "Barter units prose (capture p. 75): the koku bushel upper bound",
    }, {
      "name" = "dgwClothBoltYards",
      "value" = 20,
      "comment" = "Barter units prose (capture p. 75): a bolt of cloth contains 20 yards of material",
    }, {
      "name" = "dgwT44RowCount",
      "value" = 5,
      "comment" = "Table 44 (capture p. 75): five barter-unit rows",
    } },
  "bools" = { {
      "name" = "dgwGoldNotCurrency",
      "value" = true,
      "comment" = "Coins prose (capture pp. 74-75): Kara-Tur uses copper, silver and paper currency - gold is not a proper form of currency and is reserved for artistic and craft purposes",
    }, {
      "name" = "dgwCoinsPiercedAndStrung",
      "value" = true,
      "comment" = "Coins prose (capture p. 75): each coin is pierced through the center and threaded on cash strings, tucked in the sleeve - simplifying the carrying and the counting",
    }, {
      "name" = "dgwChaoPaperNote",
      "value" = true,
      "comment" = "Ch'ao prose (capture p. 75): the ch'ao is a paper note, preferred when dealing in amounts of 100 fen or greater",
    }, {
      "name" = "dgwChienHoarded",
      "value" = true,
      "comment" = "Ch'ien prose (capture p. 75): the ch'ien is rarely used in everyday transactions since it is awkward to carry, and is hoarded for times when the copper and paper money falls in value",
    }, {
      "name" = "dgwNobleSpending",
      "value" = true,
      "comment" = "Opener prose (capture pp. 73-74): refined nobles support the arts, field armies, provide for followers, build public works, maintain households and give gifts; lesser status spends on clothing, equipment, lodgings and artistic tastes",
    }, {
      "name" = "dgwSystemsDivergent",
      "value" = true,
      "comment" = "Systems prose (capture p. 74): Shou Lung prints paper money, T'u Lung mints regular coinage, Kozakura uses the coins of others, the warlords occasionally mint coins, and the barbarian tribes live without minted coins - barter and direct trade only",
    }, {
      "name" = "dgwEstablishedCurrency",
      "value" = true,
      "comment" = "Established currency prose (capture p. 74): the government controls the minting with uniform coins backed by the imperial treasury, issues paper money beyond true value, oversees market prices, takes taxes in grain - barter uncommon, haggling expected for the larger purchases",
    }, {
      "name" = "dgwRegularCurrency",
      "value" = true,
      "comment" = "Regular currency prose (capture p. 74): the coins are not always regular in size or shape, the value follows the metal content, weighing coins is not uncommon, the larger purchases run by barter - land via gems, art, services or a crop share",
    }, {
      "name" = "dgwIrregularCurrency",
      "value" = true,
      "comment" = "Irregular currency prose (capture p. 74): foreign coins are used without prejudice, every coin is worth only its precious metal content, paper money is useless, wealth is measured by the goods and contracts held, and the legal systems enforce the contracts",
    }, {
      "name" = "dgwPureBarter",
      "value" = true,
      "comment" = "Pure barter prose (capture p. 74): wealth is measured purely by the goods owned, contracts are generally not drawn, purchases trade equal value, haggling is a must, the legal systems stay informal and the reputation as dealer or cheat moves the prices",
    }, {
      "name" = "dgwDmChoosesSystem",
      "value" = true,
      "comment" = "Systems prose (capture p. 74): characters normally deal with a single system - the DM picks by campaign area and may choose the simplest system so as not to slow the play",
    }, {
      "name" = "dgwBarterUnitDoctrine",
      "value" = true,
      "comment" = "Barter units prose (capture p. 75): a barter unit is a set amount of goods seen as having a specific value - the farmer in koku of rice, the nomad in horses, the merchant in bolts of cloth",
    }, {
      "name" = "dgwQualityVariesValue",
      "value" = true,
      "comment" = "Barter units prose (capture p. 75): the buying power of livestock and cloth varies greatly with the quality - the well-fed horse and the fine cloth fetch higher prices",
    } },
  "switches" = { {
      "name" = "dgwT44Chien",
      "values" = { 5, 0, 2, 1, 3 },
      "default" = -99,
      "comment" = "the barter-unit value column in ch'ien - the row order pins as the 0-4 code: koku, sheep or goat, horse, common cloth bolt, silk cloth bolt; a 0 means the value is denominated in the tael column (capture p. 75).",
    }, {
      "name" = "dgwT44Tael",
      "values" = { 0, 5, 0, 0, 0 },
      "default" = -99,
      "comment" = "the barter-unit value column in tael - the sheep and goat row reads 5 tael; the other rows are denominated in ch'ien (capture p. 75).",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgwYuanFen']() != 5  or m['dgwChaoFen']() != 100  or m['dgwChaoYuan']() != 20  or m['dgwTaelFen']() != 100  or m['dgwTaelYuan']() != 20  or m['dgwTaelChao']() != 1  or m['dgwChienFen']() != 1000  or m['dgwChienYuan']() != 200  or m['dgwChienChao']() != 10  or m['dgwChienTael']() != 10  or m['dgwCashStringMin']() != 50  or m['dgwCashStringMax']() != 100  or m['dgwChaoNoteMax']() != 100  or m['dgwKokuBushelsMin']() != 5  or m['dgwKokuBushelsMax']() != 6  or m['dgwClothBoltYards']() != 20  or m['dgwT44RowCount']() != 5  or  m['dgwGoldNotCurrency']() != 1  or  m['dgwCoinsPiercedAndStrung']() != 1  or  m['dgwChaoPaperNote']() != 1  or  m['dgwChienHoarded']() != 1  or  m['dgwNobleSpending']() != 1  or  m['dgwSystemsDivergent']() != 1  or  m['dgwEstablishedCurrency']() != 1  or  m['dgwRegularCurrency']() != 1  or  m['dgwIrregularCurrency']() != 1  or  m['dgwPureBarter']() != 1  or  m['dgwDmChoosesSystem']() != 1  or  m['dgwBarterUnitDoctrine']() != 1  or  m['dgwQualityVariesValue']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgwYuanFen']() != 5",
      "note" = "the dgwYuanFen pin",
    }, {
      "expr" = "m['dgwChaoFen']() != 100",
      "note" = "the dgwChaoFen pin",
    }, {
      "expr" = "m['dgwChaoYuan']() != 20",
      "note" = "the dgwChaoYuan pin",
    }, {
      "expr" = "m['dgwTaelFen']() != 100",
      "note" = "the dgwTaelFen pin",
    }, {
      "expr" = "m['dgwTaelYuan']() != 20",
      "note" = "the dgwTaelYuan pin",
    }, {
      "expr" = "m['dgwTaelChao']() != 1",
      "note" = "the dgwTaelChao pin",
    }, {
      "expr" = "m['dgwChienFen']() != 1000",
      "note" = "the dgwChienFen pin",
    }, {
      "expr" = "m['dgwChienYuan']() != 200",
      "note" = "the dgwChienYuan pin",
    }, {
      "expr" = "m['dgwChienChao']() != 10",
      "note" = "the dgwChienChao pin",
    }, {
      "expr" = "m['dgwChienTael']() != 10",
      "note" = "the dgwChienTael pin",
    }, {
      "expr" = "m['dgwCashStringMin']() != 50",
      "note" = "the dgwCashStringMin pin",
    }, {
      "expr" = "m['dgwCashStringMax']() != 100",
      "note" = "the dgwCashStringMax pin",
    }, {
      "expr" = "m['dgwChaoNoteMax']() != 100",
      "note" = "the dgwChaoNoteMax pin",
    }, {
      "expr" = "m['dgwKokuBushelsMin']() != 5",
      "note" = "the dgwKokuBushelsMin pin",
    }, {
      "expr" = "m['dgwKokuBushelsMax']() != 6",
      "note" = "the dgwKokuBushelsMax pin",
    }, {
      "expr" = "m['dgwClothBoltYards']() != 20",
      "note" = "the dgwClothBoltYards pin",
    }, {
      "expr" = "m['dgwT44RowCount']() != 5",
      "note" = "the dgwT44RowCount pin",
    }, {
      "expr" = "m['dgwGoldNotCurrency']() != 1",
      "note" = "the dgwGoldNotCurrency pin",
    }, {
      "expr" = "m['dgwCoinsPiercedAndStrung']() != 1",
      "note" = "the dgwCoinsPiercedAndStrung pin",
    }, {
      "expr" = "m['dgwChaoPaperNote']() != 1",
      "note" = "the dgwChaoPaperNote pin",
    }, {
      "expr" = "m['dgwChienHoarded']() != 1",
      "note" = "the dgwChienHoarded pin",
    }, {
      "expr" = "m['dgwNobleSpending']() != 1",
      "note" = "the dgwNobleSpending pin",
    }, {
      "expr" = "m['dgwSystemsDivergent']() != 1",
      "note" = "the dgwSystemsDivergent pin",
    }, {
      "expr" = "m['dgwEstablishedCurrency']() != 1",
      "note" = "the dgwEstablishedCurrency pin",
    }, {
      "expr" = "m['dgwRegularCurrency']() != 1",
      "note" = "the dgwRegularCurrency pin",
    }, {
      "expr" = "m['dgwIrregularCurrency']() != 1",
      "note" = "the dgwIrregularCurrency pin",
    }, {
      "expr" = "m['dgwPureBarter']() != 1",
      "note" = "the dgwPureBarter pin",
    }, {
      "expr" = "m['dgwDmChoosesSystem']() != 1",
      "note" = "the dgwDmChoosesSystem pin",
    }, {
      "expr" = "m['dgwBarterUnitDoctrine']() != 1",
      "note" = "the dgwBarterUnitDoctrine pin",
    }, {
      "expr" = "m['dgwQualityVariesValue']() != 1",
      "note" = "the dgwQualityVariesValue pin",
    }, {
      "expr" = "m['dgwT44Chien'](0) != 5  or m['dgwT44Tael'](0) != 0",
      "note" = "the T44 koku row - the 5 ch'ien rice measure (capture p. 75)",
    }, {
      "expr" = "m['dgwT44Chien'](1) != 0  or m['dgwT44Tael'](1) != 5",
      "note" = "the T44 sheep and goat row - the 5 tael livestock read (capture p. 75)",
    }, {
      "expr" = "m['dgwT44Chien'](2) != 2  or m['dgwT44Tael'](2) != 0",
      "note" = "the T44 horse row - the 2 ch'ien mount (capture p. 75)",
    }, {
      "expr" = "m['dgwT44Chien'](3) != 1  or m['dgwT44Chien'](4) != 3  or m['dgwT44RowCount']() != 5",
      "note" = "the T44 cloth rows - the 1 ch'ien common bolt, the 3 ch'ien silk bolt, five rows only (capture p. 75)",
    }, {
      "expr" = "m['dgwYuanFen']() != 5  or m['dgwChaoFen']() != 100  or m['dgwChaoYuan']() != 20",
      "note" = "the T43 yuan and ch'ao relations (capture p. 75)",
    }, {
      "expr" = "m['dgwTaelFen']() != 100  or m['dgwTaelYuan']() != 20  or m['dgwTaelChao']() != 1",
      "note" = "the T43 tael relations - the 100 fen, 20 yuan and the ch'ao equality (capture p. 75)",
    }, {
      "expr" = "m['dgwChienFen']() != 1000  or m['dgwChienYuan']() != 200  or m['dgwChienChao']() != 10  or m['dgwChienTael']() != 10",
      "note" = "the T43 ch'ien relations - the 1000 fen, 200 yuan, 10 ch'ao, 10 tael (capture p. 75)",
    }, {
      "expr" = "m['dgwCashStringMin']() != 50  or m['dgwCashStringMax']() != 100",
      "note" = "the cash strings - the 50-to-100 coin threading (capture p. 75)",
    }, {
      "expr" = "m['dgwKokuBushelsMin']() != 5  or m['dgwKokuBushelsMax']() != 6  or m['dgwClothBoltYards']() != 20",
      "note" = "the koku and cloth measures - the 5-to-6 bushels, the 20-yard bolt (capture p. 75)",
    } },
  "audit" = {
      "label" = "R636 OA money audit",
      "comment" = "OA round twenty-three (capture pp. 73-75): the money opener prose, the monetary systems, the coin values and the T44 barter grid",
    },
}
