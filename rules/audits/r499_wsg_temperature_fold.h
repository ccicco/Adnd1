    // ---- R499 WSG temperature fold audit ----
    // The WSG temperature-chain fold, the first seam round after gap closure:
    // no new book pages. Every pinned value is a landed original re-read from
    // its header and pinned again on the fold side, so each identity compiles
    // and rides the mutant battery. The chain: one wilderness temperature
    // feeds the dress Table 3 column dispatch (rules/wsgdress.h
    // wsdColForTemp, boundaries below 0, 0-30, 31-75, 76 plus), the Table 9
    // damage band dispatch (rules/wsgheat.h wshHeatBandFor, 25 bands,
    // no-damage band 16 at 31-84, frostbite threshold 0), the weather letter
    // codes (rules/wsgweather.h wwsTempCodeHi, D tops at 0, H at 30) and the
    // R498 survival shifts (plus 20 at 30 or lower, minus 20 at 80 or
    // higher). Three boundary alignments are true (31 with 31, 30 with 30, 0
    // with 0); one is a deliberate non-alignment (the hot column opens at 76,
    // eight degrees inside the no-damage band - attire adjusts before damage
    // resumes at 85); the protected no-damage span is wider on both ends (6
    // through 89).
    {
        using namespace rules;
        int bad = 0;
    if (wtfDressColCount() != 4
            || wtfDressBelow0Bound() != 0
            || wtfDressColdTop() != 30
            || wtfDressModLo() != 31
            || wtfDressModTop() != 75
            || wtfDressHotLo() != 76
            || wtfBandCount() != 25
            || wtfBandNoDmg() != 16
            || wtfNoDmgLo() != 31
            || wtfNoDmgHi() != 84
            || wtfDmgResume() != 85
            || wtfBandFrostTop() != 0
            || wtfBandPreNoDmgTop() != 30
            || wtfFrostMax() != 0
            || wtfDash() != 99
            || wtfDashUnprot() != 2
            || wtfDashProt() != 14
            || wtfProtNoDmgLo() != 6
            || wtfProtNoDmgHi() != 89
            || wtfCodeCount() != 26
            || wtfCodeDHi() != 0
            || wtfCodeHHi() != 30
            || wtfCodePeakHi() != 115
            || wtfSurvColdShift() != 20
            || wtfSurvColdBound() != 30
            || wtfSurvHeatShift() != 20
            || wtfSurvHeatBound() != 80
            || !wtfModOpensWithNoDmg()
            || !wtfFrostAtBelow0Bound()
            || !wtfBand15TopsWithColdCol()
            || !wtfHotOpensInsideNoDmg()
            || !wtfModNarrowerThanNoDmg()
            || !wtfSurvColdLandsNoDmg()
            || !wtfSurvHeatLandsModCol()
            || !wtfProtWiderThanUnprot()
            || !wtfCodesSpanChain()
            || !wtfChainHasNoGaps()
        )
            ++bad;
        // the dress column boundaries
    if (wtfDressColCount() != 4
            || wtfDressBelow0Bound() != 0
            || wtfDressColdTop() != 30
            || wtfDressModLo() != 31
            || wtfDressModTop() != 75
            || wtfDressHotLo() != 76
        )
            ++bad;
        // the moderate column opens exactly where the no-damage band opens -
        // the first true alignment
    if (wtfDressModLo() != wtfNoDmgLo()
        )
            ++bad;
        // the frostbite threshold sits at the below-0 boundary value
    if (wtfFrostMax() != wtfDressBelow0Bound()
            || wtfBandFrostTop() != wtfDressBelow0Bound()
        )
            ++bad;
        // band 15 tops where the cold column tops - the second true alignment
    if (wtfBandPreNoDmgTop() != wtfDressColdTop()
        )
            ++bad;
        // the hot column opens inside the no-damage band
    if (wtfDressHotLo() < wtfNoDmgLo()
            || wtfDressHotLo() > wtfNoDmgHi()
        )
            ++bad;
        // the overlap runs eight degrees
    if (wtfNoDmgHi() - wtfDressHotLo() != 8
        )
            ++bad;
        // the moderate column is narrower than the no-damage band
    if (wtfDressModTop() >= wtfNoDmgHi()
        )
            ++bad;
        // unprotected damage resumes one degree past the no-damage top
    if (wtfDmgResume() != wtfNoDmgHi() + 1
        )
            ++bad;
        // the dash censuses match Table 9
    if (wtfDashUnprot() + wtfDashProt() != 16
            || wtfDash() != 99
        )
            ++bad;
        // protected no-damage is wider on both ends
    if (wtfProtNoDmgLo() >= wtfNoDmgLo()
            || wtfProtNoDmgHi() <= wtfNoDmgHi()
        )
            ++bad;
        // cold survival at its bound lands inside the no-damage band
    if (wtfSurvColdBound() + wtfSurvColdShift() < wtfNoDmgLo()
            || wtfSurvColdBound() + wtfSurvColdShift() > wtfNoDmgHi()
        )
            ++bad;
        // heat survival at its bound lands inside the moderate column
    if (wtfSurvHeatBound() - wtfSurvHeatShift() < wtfDressModLo()
            || wtfSurvHeatBound() - wtfSurvHeatShift() > wtfDressModTop()
        )
            ++bad;
        // the letter codes bracket the chain
    if (wtfCodeCount() != 26
            || wtfCodeDHi() != wtfFrostMax()
            || wtfCodeHHi() != wtfDressColdTop()
            || wtfCodePeakHi() < 90
        )
            ++bad;
        printf("R499 WSG temperature fold audit: bad %d\n", bad);
        if (bad) return 1;
    }
