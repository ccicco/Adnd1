    // ---- R636 OA money audit ----
    // OA round twenty-three (capture pp. 73-75): the money opener prose, the
    // monetary systems, the coin values and the T44 barter grid
    {
        using namespace rules;
        int bad = 0;
    if (dgwYuanFen() != 5
            || dgwChaoFen() != 100
            || dgwChaoYuan() != 20
            || dgwTaelFen() != 100
            || dgwTaelYuan() != 20
            || dgwTaelChao() != 1
            || dgwChienFen() != 1000
            || dgwChienYuan() != 200
            || dgwChienChao() != 10
            || dgwChienTael() != 10
            || dgwCashStringMin() != 50
            || dgwCashStringMax() != 100
            || dgwChaoNoteMax() != 100
            || dgwKokuBushelsMin() != 5
            || dgwKokuBushelsMax() != 6
            || dgwClothBoltYards() != 20
            || dgwT44RowCount() != 5
            || !dgwGoldNotCurrency()
            || !dgwCoinsPiercedAndStrung()
            || !dgwChaoPaperNote()
            || !dgwChienHoarded()
            || !dgwNobleSpending()
            || !dgwSystemsDivergent()
            || !dgwEstablishedCurrency()
            || !dgwRegularCurrency()
            || !dgwIrregularCurrency()
            || !dgwPureBarter()
            || !dgwDmChoosesSystem()
            || !dgwBarterUnitDoctrine()
            || !dgwQualityVariesValue()
        )
            ++bad;
        // the Table 44 grid: the barter-unit values (capture p. 75)
        int CT44[5][2] = {
            {5,0},
            {0,5},
            {2,0},
            {1,0},
            {3,0},
            };
        int nT44[2] = {0,0};
        int eT44[2] = {0,0};
        for (int b = 0;
             b < dgwT44RowCount();
             ++b) {
            int vals[2];
            vals[0] = dgwT44Chien(b);
            vals[1] = dgwT44Tael(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT44[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT44[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nT44[c] != eT44[c])
                ++bad;
        // the dgwYuanFen pin
    if (dgwYuanFen() != 5
        )
            ++bad;
        // the dgwChaoFen pin
    if (dgwChaoFen() != 100
        )
            ++bad;
        // the dgwChaoYuan pin
    if (dgwChaoYuan() != 20
        )
            ++bad;
        // the dgwTaelFen pin
    if (dgwTaelFen() != 100
        )
            ++bad;
        // the dgwTaelYuan pin
    if (dgwTaelYuan() != 20
        )
            ++bad;
        // the dgwTaelChao pin
    if (dgwTaelChao() != 1
        )
            ++bad;
        // the dgwChienFen pin
    if (dgwChienFen() != 1000
        )
            ++bad;
        // the dgwChienYuan pin
    if (dgwChienYuan() != 200
        )
            ++bad;
        // the dgwChienChao pin
    if (dgwChienChao() != 10
        )
            ++bad;
        // the dgwChienTael pin
    if (dgwChienTael() != 10
        )
            ++bad;
        // the dgwCashStringMin pin
    if (dgwCashStringMin() != 50
        )
            ++bad;
        // the dgwCashStringMax pin
    if (dgwCashStringMax() != 100
        )
            ++bad;
        // the dgwChaoNoteMax pin
    if (dgwChaoNoteMax() != 100
        )
            ++bad;
        // the dgwKokuBushelsMin pin
    if (dgwKokuBushelsMin() != 5
        )
            ++bad;
        // the dgwKokuBushelsMax pin
    if (dgwKokuBushelsMax() != 6
        )
            ++bad;
        // the dgwClothBoltYards pin
    if (dgwClothBoltYards() != 20
        )
            ++bad;
        // the dgwT44RowCount pin
    if (dgwT44RowCount() != 5
        )
            ++bad;
        // the dgwGoldNotCurrency pin
    if (dgwGoldNotCurrency() != 1
        )
            ++bad;
        // the dgwCoinsPiercedAndStrung pin
    if (dgwCoinsPiercedAndStrung() != 1
        )
            ++bad;
        // the dgwChaoPaperNote pin
    if (dgwChaoPaperNote() != 1
        )
            ++bad;
        // the dgwChienHoarded pin
    if (dgwChienHoarded() != 1
        )
            ++bad;
        // the dgwNobleSpending pin
    if (dgwNobleSpending() != 1
        )
            ++bad;
        // the dgwSystemsDivergent pin
    if (dgwSystemsDivergent() != 1
        )
            ++bad;
        // the dgwEstablishedCurrency pin
    if (dgwEstablishedCurrency() != 1
        )
            ++bad;
        // the dgwRegularCurrency pin
    if (dgwRegularCurrency() != 1
        )
            ++bad;
        // the dgwIrregularCurrency pin
    if (dgwIrregularCurrency() != 1
        )
            ++bad;
        // the dgwPureBarter pin
    if (dgwPureBarter() != 1
        )
            ++bad;
        // the dgwDmChoosesSystem pin
    if (dgwDmChoosesSystem() != 1
        )
            ++bad;
        // the dgwBarterUnitDoctrine pin
    if (dgwBarterUnitDoctrine() != 1
        )
            ++bad;
        // the dgwQualityVariesValue pin
    if (dgwQualityVariesValue() != 1
        )
            ++bad;
        // the T44 koku row - the 5 ch'ien rice measure (capture p. 75)
    if (dgwT44Chien(0) != 5
            || dgwT44Tael(0) != 0
        )
            ++bad;
        // the T44 sheep and goat row - the 5 tael livestock read (capture p.
        // 75)
    if (dgwT44Chien(1) != 0
            || dgwT44Tael(1) != 5
        )
            ++bad;
        // the T44 horse row - the 2 ch'ien mount (capture p. 75)
    if (dgwT44Chien(2) != 2
            || dgwT44Tael(2) != 0
        )
            ++bad;
        // the T44 cloth rows - the 1 ch'ien common bolt, the 3 ch'ien silk
        // bolt, five rows only (capture p. 75)
    if (dgwT44Chien(3) != 1
            || dgwT44Chien(4) != 3
            || dgwT44RowCount() != 5
        )
            ++bad;
        // the T43 yuan and ch'ao relations (capture p. 75)
    if (dgwYuanFen() != 5
            || dgwChaoFen() != 100
            || dgwChaoYuan() != 20
        )
            ++bad;
        // the T43 tael relations - the 100 fen, 20 yuan and the ch'ao
        // equality (capture p. 75)
    if (dgwTaelFen() != 100
            || dgwTaelYuan() != 20
            || dgwTaelChao() != 1
        )
            ++bad;
        // the T43 ch'ien relations - the 1000 fen, 200 yuan, 10 ch'ao, 10
        // tael (capture p. 75)
    if (dgwChienFen() != 1000
            || dgwChienYuan() != 200
            || dgwChienChao() != 10
            || dgwChienTael() != 10
        )
            ++bad;
        // the cash strings - the 50-to-100 coin threading (capture p. 75)
    if (dgwCashStringMin() != 50
            || dgwCashStringMax() != 100
        )
            ++bad;
        // the koku and cloth measures - the 5-to-6 bushels, the 20-yard bolt
        // (capture p. 75)
    if (dgwKokuBushelsMin() != 5
            || dgwKokuBushelsMax() != 6
            || dgwClothBoltYards() != 20
        )
            ++bad;
        printf("R636 OA money audit: bad %d\n", bad);
        if (bad) return 1;
    }
