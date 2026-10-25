    // ---- R784 worship sites audit ----
    // THE WORSHIP SITES - the last unpinned Appendix S chart read (Curtiss's
    // five-chart-rows call, resolved by the print). The R783 handoff flagged
    // the five clerical chart rows blocked on extraction contamination; this
    // round re-read the chart three ways - the 1eonline.info compilation
    // pages, the R407 pins, and the print itself (the archive.org full-text
    // OCR of pp. 121-122) - and the verdict is clean: EVERY R407 PIN STANDS.
    // The contamination rides the compilation side, not the repo: the site's
    // Hanali row carries Solonor's cells wholesale (sphere, animal, raiment,
    // colors, form, and site - the deep forest), Labelas's sphere cell prints
    // Erevan's sphere, and the Arvoreen, Segojan, and Aerdrie rows carry
    // site-side spelling variants (defence, Nature, sky-blue, semi-annually).
    // THE GRID: 23 x 2 - the place-of-worship kinds (16 distinct codes: the
    // two battlefield rows, the four dwarven underground temples, Aerdrie's
    // open hilltops, Hanali's fountain or spring, Labelas's small grove,
    // Solonor's deep forest, Erevan's never-the-same-place-twice, Sheela's
    // open field, Cyrrollalee's the home, the four anywhere rows, Baervan's
    // forest clearing, Urdlen's cavern, Segojan's subterranean temple,
    // Flandal's underground forge, Yurtrus's crypt, Luthic's cave temple) and
    // the cleric-gender reads (12 males-only rows, the lone Berronar
    // females-only row, 10 either-gender rows with the Luthic exception). THE
    // STRINGS: the printed site phrases ride rules/uascharts.h (the
    // uscWorshipSite accessor) with a live regtest strings block checking all
    // 23 row for row (the R782 site-block precedent). Honest boundaries: the
    // M, F, and N-H columns on the compilation pages are the compilation's
    // own additions, not print chart columns - they stay contract-side; the
    // print's own typos ("can by worshiped", the one-r Cyrollalee) ride the
    // prose; the pantheon prose stays open (R423 stands)
    {
        using namespace rules;
        int bad = 0;
    if (plcDeityRowCount() != 23
            || plcWorshipSiteRound() != 784
            || plcChartFeederRound() != 407
            || plcSiteKindCount() != 16
            || plcMaleOnlyClericRows() != 12
            || plcFemaleOnlyClericRows() != 1
            || plcEitherGenderClericRows() != 10
            || plcAnywhereSiteRows() != 4
            || plcUndergroundSiteRows() != 9
            || plcFountainSiteKind() != 3
            || plcNeverSamePlaceKind() != 6
            || plcFemaleOnlyDeityRow() != 4
            || !plcSitesRideTheChartProse()
            || !plcChartRowsVerifiedAgainstPrint()
            || !plcHanaliRowContaminationStandsPrint()
            || !plcErevanNeverSamePlaceTwice()
            || !plcDwarvenRestWorshipInTemples()
            || !plcHalflingAnywherePair()
            || !plcOrcAnywherePair()
            || !plcLuthicAllowsBothGenders()
            || !plcGenderColumnsRideTheCompilation()
        )
            ++bad;
        // the 23 x 2 worship-site grid - the place-of-worship kinds and the
        // cleric-gender reads, in the R405/R406/R783 registry order (no -1
        // sentinel rides; every cell prints)
        int CPlcSites[23][2] = {
            {0,0},
            {1,0},
            {1,0},
            {1,0},
            {1,1},
            {2,2},
            {6,2},
            {5,2},
            {3,2},
            {4,2},
            {7,2},
            {9,2},
            {8,2},
            {9,2},
            {10,0},
            {11,0},
            {12,0},
            {13,0},
            {0,0},
            {9,0},
            {9,0},
            {14,0},
            {15,2},
            };
        int nPlcSites[2] = {0,0};
        int ePlcSites[2] = {0,0};
        for (int b = 0;
             b < plcDeityRowCount();
             ++b) {
            int vals[2];
            vals[0] = plcSiteKind(b);
            vals[1] = plcClericGender(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CPlcSites[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nPlcSites[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nPlcSites[c] != ePlcSites[c])
                ++bad;
        // the worship-site kind walk - all 23 rows against the print prose
        // reads
    if (plcSiteKind(0) != 0
            || plcSiteKind(1) != 1
            || plcSiteKind(2) != 1
            || plcSiteKind(3) != 1
            || plcSiteKind(4) != 1
            || plcSiteKind(5) != 2
            || plcSiteKind(6) != 6
            || plcSiteKind(7) != 5
            || plcSiteKind(8) != 3
            || plcSiteKind(9) != 4
            || plcSiteKind(10) != 7
            || plcSiteKind(11) != 9
            || plcSiteKind(12) != 8
            || plcSiteKind(13) != 9
            || plcSiteKind(14) != 10
            || plcSiteKind(15) != 11
            || plcSiteKind(16) != 12
            || plcSiteKind(17) != 13
            || plcSiteKind(18) != 0
            || plcSiteKind(19) != 9
            || plcSiteKind(20) != 9
            || plcSiteKind(21) != 14
            || plcSiteKind(22) != 15
        )
            ++bad;
        // the cleric-gender walk - all 23 rows (the dwarven split, the
        // either-gender elves and halflings, the all-male gnomes, the Luthic
        // exception)
    if (plcClericGender(0) != 0
            || plcClericGender(1) != 0
            || plcClericGender(2) != 0
            || plcClericGender(3) != 0
            || plcClericGender(4) != 1
            || plcClericGender(5) != 2
            || plcClericGender(6) != 2
            || plcClericGender(7) != 2
            || plcClericGender(8) != 2
            || plcClericGender(9) != 2
            || plcClericGender(10) != 2
            || plcClericGender(11) != 2
            || plcClericGender(12) != 2
            || plcClericGender(13) != 2
            || plcClericGender(14) != 0
            || plcClericGender(15) != 0
            || plcClericGender(16) != 0
            || plcClericGender(17) != 0
            || plcClericGender(18) != 0
            || plcClericGender(19) != 0
            || plcClericGender(20) != 0
            || plcClericGender(21) != 0
            || plcClericGender(22) != 2
        )
            ++bad;
        // the contamination repairs and the notable prints (Hanali fountain,
        // Erevan never-twice, the anywhere four, the battlefield pair,
        // Berronar lone female)
    if (plcSiteKind(8) != 3
            || plcSiteKind(6) != 6
            || plcSiteKind(11) != 9
            || plcSiteKind(13) != 9
            || plcSiteKind(19) != 9
            || plcSiteKind(20) != 9
            || plcSiteKind(0) != 0
            || plcSiteKind(18) != 0
            || plcClericGender(4) != 1
            || plcClericGender(22) != 2
        )
            ++bad;
        // the feeder keys and the censuses (the R407 feed, the kind count,
        // the gender and anywhere and underground censuses)
    if (plcChartFeederRound() != 407
            || plcWorshipSiteRound() != 784
            || plcDeityRowCount() != 23
            || plcSiteKindCount() != 16
            || plcMaleOnlyClericRows() != 12
            || plcFemaleOnlyClericRows() != 1
            || plcEitherGenderClericRows() != 10
            || plcAnywhereSiteRows() != 4
            || plcUndergroundSiteRows() != 9
            || plcFemaleOnlyDeityRow() != 4
            || plcFountainSiteKind() != 3
            || plcNeverSamePlaceKind() != 6
        )
            ++bad;
        printf("R784 worship sites audit: bad %d\n", bad);
        if (bad) return 1;
    }
