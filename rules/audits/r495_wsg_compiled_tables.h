    // ---- R495 WSG compiled tables audit ----
    // The compiled tables, printed pp. 120-123 (pdf 121-124): thirty of the
    // forty-two book tables reprinted as the play-session reference, each
    // with its from-page. Twenty-nine of the thirty reprints match their
    // landed originals cell for cell (the Table 3 attire grid, Tables 4 and
    // 5, Table 9 with its damage-adjustment and Con-check companions, Tables
    // 11-19, 20-26, 28-29, 33, 36-39, 41 and the fourteen-row Table 42). The
    // ONE exception is the compiled Table 32 (fishing success): the reprint
    // reads Fair daytime 1d6-3 against the original 1d6-2, and Good daytime
    // 1d6-2 against the original 1d8-2 - pinned here as the errata record
    // with the landed rules/wsgfish.h keeping the original readings. The
    // Table 4 attack cells at 90-99 (-1) and 100-109 (-2), shredded by the
    // tesseract pass, were confirmed by direct eyeball and match the pin.
    // This closes the compiled-tables box: the WSG arc is complete.
    {
        using namespace rules;
        int bad = 0;
    if (wctCompiledCount() != 30
            || wctBookTableCount() != 42
            || wctOmittedCount() != 12
            || wctSpanPdfLo() != 121
            || wctSpanPdfHi() != 124
            || wctSpanPrintedLo() != 120
            || wctSpanPrintedHi() != 123
            || wctT3FromPage() != 19
            || wctT4FromPage() != 21
            || wctT5FromPage() != 21
            || wctT9FromPage() != 26
            || wctT11FromPage() != 30
            || wctT12FromPage() != 31
            || wctT13FromPage() != 32
            || wctT14FromPage() != 33
            || wctT15FromPage() != 33
            || wctT16FromPage() != 35
            || wctT17FromPage() != 35
            || wctT18FromPage() != 36
            || wctT19FromPage() != 36
            || wctT20FromPage() != 38
            || wctT21FromPage() != 38
            || wctT22FromPage() != 39
            || wctT23FromPage() != 40
            || wctT24FromPage() != 41
            || wctT25FromPage() != 44
            || wctT26FromPage() != 45
            || wctT28FromPage() != 50
            || wctT29FromPage() != 53
            || wctT32FromPage() != 57
            || wctT33FromPage() != 58
            || wctT36FromPage() != 62
            || wctT37FromPage() != 64
            || wctT38FromPage() != 65
            || wctT39FromPage() != 66
            || wctT41FromPage() != 73
            || wctT42FromPage() != 92
            || wctT32FairDayDie() != 6
            || wctT32FairDayMod() != -3
            || wctT32GoodDayDie() != 6
            || wctT32GoodDayMod() != -2
            || wctT9ColdStatLo() != 1
            || wctT9ColdStatHi() != 3
            || wctT9HotStatLo() != -3
            || wctT9HotStatHi() != -1
            || wctT9ColdStrenLo() != 1
            || wctT9ColdStrenHi() != 2
            || wctT9HotStrenLo() != 1
            || wctT9HotStrenHi() != 4
            || wctT9FatiguedLo() != 1
            || wctT9FatiguedHi() != 6
            || wctT9ConAdj46() != -1
            || wctT9ConAdj79() != -2
            || wctT9ConAdj1012() != -3
            || wctT9ConAdj1315() != -4
            || wctT9ConAdj16() != -5
            || !wctSelectionMostReferred()
            || !wctNotAllTablesReprinted()
            || !wctFourPageSpan()
            || !wctT3Matches()
            || !wctT4Matches()
            || !wctT5Matches()
            || !wctT9Matches()
            || !wctT11Matches()
            || !wctT12Matches()
            || !wctT13Matches()
            || !wctT14Matches()
            || !wctT15Matches()
            || !wctT16Matches()
            || !wctT17Matches()
            || !wctT18Matches()
            || !wctT19Matches()
            || !wctT20Matches()
            || !wctT21Matches()
            || !wctT22Matches()
            || !wctT23Matches()
            || !wctT24Matches()
            || !wctT25Matches()
            || !wctT26Matches()
            || !wctT28Matches()
            || !wctT29Matches()
            || wctT32Matches()
            || !wctT33Matches()
            || !wctT36Matches()
            || !wctT37Matches()
            || !wctT38Matches()
            || !wctT39Matches()
            || !wctT41Matches()
            || !wctT42Matches()
            || !wctOnlyT32Differs()
            || !wctT4AttackCellsConfirmed()
            || !wctT32NightUnchanged()
            || !wctT32ErrataIsCompiledSide()
            || !wctT9CompanionsMatch()
            || !wctT25MergedHalves()
            || !wctT36QualityBandsLabeled()
        )
            ++bad;
        // the compiled section reprints thirty of the forty-two book tables
    if (wctCompiledCount() != 30
            || wctBookTableCount() != 42
            || wctOmittedCount() != 12
        )
            ++bad;
        // the four-page span: pdf 121-124, printed 120-123
    if (wctSpanPdfLo() != 121
            || wctSpanPdfHi() != 124
            || wctSpanPrintedLo() != 120
            || wctSpanPrintedHi() != 123
        )
            ++bad;
        // the first reprint in the section is Table 3, from page 19
    if (wctT3FromPage() != 19
        )
            ++bad;
        // the last reprint in the section is Table 42, from page 92
    if (wctT42FromPage() != 92
        )
            ++bad;
        // the compiled Table 32 Fair daytime is 1d6-3 - the original pin
        // reads 1d6-2
    if (wctT32FairDayDie() != 6
            || wctT32FairDayMod() != -3
        )
            ++bad;
        // the compiled Table 32 Good daytime is 1d6-2 - the original pin
        // reads 1d8-2 (the die drops, the modifier holds)
    if (wctT32GoodDayDie() != 6
            || wctT32GoodDayMod() != -2
        )
            ++bad;
        // exactly one reprint differs from its original
    if (wctT32Matches() != 0
            || wctOnlyT32Differs() != 1
        )
            ++bad;
        // the Table 4 attack cells confirmed by eyeball: -1 at 90-99, -2 at
        // 100-109
    if (wctT4AttackCellsConfirmed() != 1
            || wctT4Matches() != 1
        )
            ++bad;
        // the fatigued adjustment is symmetric: +1 to +6 for both cold and
        // hot
    if (wctT9FatiguedLo() != 1
            || wctT9FatiguedHi() != 6
        )
            ++bad;
        // the Con-check adjustment ladder descends -1 through -5 across
        // levels 4-6 to 16+
    if (wctT9ConAdj46() != -1
            || wctT9ConAdj79() != -2
            || wctT9ConAdj1012() != -3
            || wctT9ConAdj1315() != -4
            || wctT9ConAdj16() != -5
        )
            ++bad;
        // the stationary hot adjustment is the mirror of the stationary cold
        // one
    if (wctT9HotStatLo() != -3
            || wctT9HotStatHi() != -1
            || wctT9ColdStatLo() != 1
            || wctT9ColdStatHi() != 3
        )
            ++bad;
        // the compiled Table 3 matches its original
    if (wctT3Matches() != 1
        )
            ++bad;
        // the compiled Table 4 matches its original
    if (wctT4Matches() != 1
        )
            ++bad;
        // the compiled Table 5 matches its original
    if (wctT5Matches() != 1
        )
            ++bad;
        // the compiled Table 9 matches its original
    if (wctT9Matches() != 1
        )
            ++bad;
        // the compiled Table 11 matches its original
    if (wctT11Matches() != 1
        )
            ++bad;
        // the compiled Table 12 matches its original
    if (wctT12Matches() != 1
        )
            ++bad;
        // the compiled Table 13 matches its original
    if (wctT13Matches() != 1
        )
            ++bad;
        // the compiled Table 14 matches its original
    if (wctT14Matches() != 1
        )
            ++bad;
        // the compiled Table 15 matches its original
    if (wctT15Matches() != 1
        )
            ++bad;
        // the compiled Table 16 matches its original
    if (wctT16Matches() != 1
        )
            ++bad;
        // the compiled Table 17 matches its original
    if (wctT17Matches() != 1
        )
            ++bad;
        // the compiled Table 18 matches its original
    if (wctT18Matches() != 1
        )
            ++bad;
        // the compiled Table 19 matches its original
    if (wctT19Matches() != 1
        )
            ++bad;
        // the compiled Table 20 matches its original
    if (wctT20Matches() != 1
        )
            ++bad;
        // the compiled Table 21 matches its original
    if (wctT21Matches() != 1
        )
            ++bad;
        // the compiled Table 22 matches its original
    if (wctT22Matches() != 1
        )
            ++bad;
        // the compiled Table 23 matches its original
    if (wctT23Matches() != 1
        )
            ++bad;
        // the compiled Table 24 matches its original
    if (wctT24Matches() != 1
        )
            ++bad;
        // the compiled Table 25 matches its original
    if (wctT25Matches() != 1
        )
            ++bad;
        // the compiled Table 26 matches its original
    if (wctT26Matches() != 1
        )
            ++bad;
        // the compiled Table 28 matches its original
    if (wctT28Matches() != 1
        )
            ++bad;
        // the compiled Table 29 matches its original
    if (wctT29Matches() != 1
        )
            ++bad;
        // the compiled Table 32 differs from its original
    if (wctT32Matches() != 0
        )
            ++bad;
        // the compiled Table 33 matches its original
    if (wctT33Matches() != 1
        )
            ++bad;
        // the compiled Table 36 matches its original
    if (wctT36Matches() != 1
        )
            ++bad;
        // the compiled Table 37 matches its original
    if (wctT37Matches() != 1
        )
            ++bad;
        // the compiled Table 38 matches its original
    if (wctT38Matches() != 1
        )
            ++bad;
        // the compiled Table 39 matches its original
    if (wctT39Matches() != 1
        )
            ++bad;
        // the compiled Table 41 matches its original
    if (wctT41Matches() != 1
        )
            ++bad;
        // the compiled Table 42 matches its original
    if (wctT42Matches() != 1
        )
            ++bad;
        printf("R495 WSG compiled tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
