    // ---- R638 OA exchange audit ----
    // OA round twenty-five (capture pp. 76-77): the gajin and rates of
    // exchange prose and the Table 46 exchange grid
    {
        using namespace rules;
        int bad = 0;
    if (dgyT46RowCount() != 9
            || dgyProseFenCp() != 1
            || dgyProseYuanCp() != 1
            || dgyProseTaelSpLo() != 4
            || dgyProseTaelSpHi() != 14
            || dgyTaelSpDieSub() != 2
            || dgyProseGoldTaelLo() != 2
            || dgyProseGoldTaelHi() != 7
            || dgySilverFenDieOffset() != 7
            || !dgyGajinExchangeNeed()
            || !dgyMoneylendersExchange()
            || !dgyChaoWorthlessOutside()
            || !dgyChaoConvertAdvice()
            || !dgyGoldNotAccepted()
            || !dgyGoldMarketFactors()
            || !dgySilverForeignUndesired()
            || !dgyCopperMoreStandard()
            || !dgyExportSmuggling()
            || !dgyKtCoinsAbroad()
            || !dgyCoinSpeculation()
            || !dgyRealValueDoctrine()
            || !dgyExchangeValueDoctrine()
            || !dgyMarketPriceDoctrine()
        )
            ++bad;
        // the Table 46 grid: the currency real values, exchange bounds and
        // market flags (capture p. 77)
        int CT46[9][4] = {
            {1,1,1,0},
            {5,1,1,0},
            {100,2,12,0},
            {1000,2,8,0},
            {1,2,2,0},
            {10,8,13,0},
            {100,-99,-99,1},
            {200,-99,-99,1},
            {1000,-99,-99,1},
            };
        int nT46[4] = {0,0,0,0};
        int eT46[4] = {0,3,3,0};
        for (int b = 0;
             b < dgyT46RowCount();
             ++b) {
            int vals[4];
            vals[0] = dgyT46RealFen(b);
            vals[1] = dgyT46ExchLo(b);
            vals[2] = dgyT46ExchHi(b);
            vals[3] = dgyT46Market(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CT46[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT46[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nT46[c] != eT46[c])
                ++bad;
        // the dgyT46RowCount pin
    if (dgyT46RowCount() != 9
        )
            ++bad;
        // the fen-copper equality pin
    if (dgyProseFenCp() != 1
        )
            ++bad;
        // the yuan street rate pin
    if (dgyProseYuanCp() != 1
        )
            ++bad;
        // the tael street fetch lo pin
    if (dgyProseTaelSpLo() != 4
        )
            ++bad;
        // the tael street fetch hi pin
    if (dgyProseTaelSpHi() != 14
        )
            ++bad;
        // the tael 2d6-2 formula pin
    if (dgyTaelSpDieSub() != 2
        )
            ++bad;
        // the gold sale lo pin
    if (dgyProseGoldTaelLo() != 2
        )
            ++bad;
        // the gold sale hi pin
    if (dgyProseGoldTaelHi() != 7
        )
            ++bad;
        // the silver 1d6+7 offset pin
    if (dgySilverFenDieOffset() != 7
        )
            ++bad;
        // the gajin-contact need pin
    if (dgyGajinExchangeNeed() != 1
        )
            ++bad;
        // the moneylender pin
    if (dgyMoneylendersExchange() != 1
        )
            ++bad;
        // the worthless ch'ao pin
    if (dgyChaoWorthlessOutside() != 1
        )
            ++bad;
        // the ch'ao convert advice pin
    if (dgyChaoConvertAdvice() != 1
        )
            ++bad;
        // the gold-not-currency pin
    if (dgyGoldNotAccepted() != 1
        )
            ++bad;
        // the gold market factors pin
    if (dgyGoldMarketFactors() != 1
        )
            ++bad;
        // the undesired foreign silver pin
    if (dgySilverForeignUndesired() != 1
        )
            ++bad;
        // the standard copper pin
    if (dgyCopperMoreStandard() != 1
        )
            ++bad;
        // the export smuggling pin
    if (dgyExportSmuggling() != 1
        )
            ++bad;
        // the Kara-Tur coins abroad pin
    if (dgyKtCoinsAbroad() != 1
        )
            ++bad;
        // the coin speculation pin
    if (dgyCoinSpeculation() != 1
        )
            ++bad;
        // the real-value doctrine pin
    if (dgyRealValueDoctrine() != 1
        )
            ++bad;
        // the exchange-value doctrine pin
    if (dgyExchangeValueDoctrine() != 1
        )
            ++bad;
        // the market-price doctrine pin
    if (dgyMarketPriceDoctrine() != 1
        )
            ++bad;
        // the T46 fen row - real one copper piece, one copper piece for one
        // fen (capture p. 77)
    if (dgyT46RealFen(0) != 1
            || dgyT46ExchLo(0) != 1
            || dgyT46ExchHi(0) != 1
            || dgyT46Market(0) != 0
        )
            ++bad;
        // the T46 yuan row - real five copper pieces, one copper piece for
        // one yuan (capture p. 77)
    if (dgyT46RealFen(1) != 5
            || dgyT46ExchLo(1) != 1
            || dgyT46ExchHi(1) != 1
            || dgyT46Market(1) != 0
        )
            ++bad;
        // the T46 tael row - real ten silver pieces (100 fen), 2-12 silver
        // pieces for one tael (capture p. 77)
    if (dgyT46RealFen(2) != 100
            || dgyT46ExchLo(2) != 2
            || dgyT46ExchHi(2) != 12
            || dgyT46Market(2) != 0
        )
            ++bad;
        // the T46 ch'ien row - real 100 silver pieces or 5 gold pieces (1000
        // fen), 2-8 gold pieces for one ch'ien (capture p. 77)
    if (dgyT46RealFen(3) != 1000
            || dgyT46ExchLo(3) != 2
            || dgyT46ExchHi(3) != 8
            || dgyT46Market(3) != 0
        )
            ++bad;
        // the T46 copper piece row - real one fen, one fen for two copper
        // pieces (capture p. 77)
    if (dgyT46RealFen(4) != 1
            || dgyT46ExchLo(4) != 2
            || dgyT46ExchHi(4) != 2
            || dgyT46Market(4) != 0
        )
            ++bad;
        // the T46 silver piece row - real 10 fen or 2 yuan, 8-13 fen for one
        // silver piece (capture p. 77)
    if (dgyT46RealFen(5) != 10
            || dgyT46ExchLo(5) != 8
            || dgyT46ExchHi(5) != 13
            || dgyT46Market(5) != 0
        )
            ++bad;
        // the T46 electrum piece row - real 100 fen or 20 yuan or one tael,
        // market value of metal (capture p. 77)
    if (dgyT46RealFen(6) != 100
            || dgyT46ExchLo(6) != -99
            || dgyT46ExchHi(6) != -99
            || dgyT46Market(6) != 1
        )
            ++bad;
        // the T46 gold piece row - real 200 fen or 40 yuan or two tael,
        // market value of metal (capture p. 77)
    if (dgyT46RealFen(7) != 200
            || dgyT46ExchLo(7) != -99
            || dgyT46ExchHi(7) != -99
            || dgyT46Market(7) != 1
        )
            ++bad;
        // the T46 platinum piece row - real 1000 fen or 200 yuan or 10 tael
        // or one ch'ien, market value of metal (capture p. 77)
    if (dgyT46RealFen(8) != 1000
            || dgyT46ExchLo(8) != -99
            || dgyT46ExchHi(8) != -99
            || dgyT46Market(8) != 1
        )
            ++bad;
        printf("R638 OA exchange audit: bad %d\n", bad);
        if (bad) return 1;
    }
