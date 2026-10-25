    // ---- R220: the combined hoard table pins audit ----
    // DMG p.123: the II.C combined hoard
    // bands and their monetary and magic
    // trove references.
    {
        int bad = 0;
        // the banding: a full 1-100 walk
        if (rules::hoardBandCount() != 10) ++bad;
        static const int kBand[100] = {
            0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,
            1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,
            2,2,2,2,2,2,2,2,2,2, 2,2,2,2,2,
            3,3,3,3,3,3,3,3,3,3, 4,4,4,4,4,4,4,4,4,4,
            5,5,5,5,5, 6,6,6,6,6, 7,7,7,7,7,
            8,8,8,8,8,8, 9,9,9,9,
        };
        for (int r = 1; r <= 100; ++r)
            if (rules::hoardBandOfRoll(r) !=
                kBand[r - 1]) ++bad;
        if (rules::hoardBandOfRoll(0) != 0 ||
            rules::hoardBandOfRoll(999) != 9) ++bad;
        // the on-hand monetary rows
        static const int kMonCnt[10] = {
            1, 1, 2, 3, 2, 4, 1, 1, 0, 0,
        };
        static const int kMonRow[10][4] = {
            { 0, 0, 0, 0 },
            { 2, 2, 2, 2 },
            { 1, 2, 2, 2 },
            { 0, 1, 2, 2 },
            { 2, 3, 3, 3 },
            { 1, 2, 3, 5 },
            { 8, 8, 8, 8 },
            { 8, 8, 8, 8 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        };
        for (int b = 0; b < 10; ++b)
            if (rules::hoardMonetaryRowCount(b) != kMonCnt[b]) ++bad;
        for (int b = 0; b < 10; ++b)
            for (int i = 0; i < 4; ++i)
                if (rules::hoardMonetaryRow(b, i) !=
                    kMonRow[b][i]) ++bad;
        if (rules::hoardMonetaryRow(5, -3) != 1 ||
            rules::hoardMonetaryRow(5, 99) != 5 ||
            rules::hoardMonetaryRowCount(-2) != 1 ||
            rules::hoardMonetaryRowCount(99) != 0) ++bad;
        // the on-hand magic rows
        static const int kMagCnt[10] = {
            1, 1, 2, 2, 2, 2, 0, 0, 1, 2,
        };
        static const int kMagRow[10][2] = {
            { 0, 0 },
            { 0, 0 },
            { 0, 4 },
            { 2, 3 },
            { 1, 4 },
            { 0, 2 },
            { 0, 0 },
            { 0, 0 },
            { 6, 6 },
            { 4, 6 },
        };
        for (int b = 0; b < 10; ++b)
            if (rules::hoardMagicRowCount(b) != kMagCnt[b]) ++bad;
        for (int b = 0; b < 10; ++b)
            for (int i = 0; i < 2; ++i)
                if (rules::hoardMagicRow(b, i) !=
                    kMagRow[b][i]) ++bad;
        if (rules::hoardMagicRow(9, -1) != 4 ||
            rules::hoardMagicRow(9, 99) != 6) ++bad;
        // the map-to-monetary references
        static const int kMapMon[10] = {
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        };
        static const int kMapMonRow[10][2] = {
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 1 },
            { 3, 4 },
        };
        for (int b = 0; b < 10; ++b)
            if (rules::hoardMapsToMonetary(b) != kMapMon[b] ||
                rules::hoardMapMonetaryRowCount(b) !=
                kMapMon[b] * 2) ++bad;
        for (int b = 0; b < 10; ++b)
            for (int i = 0; i < 2; ++i)
                if (rules::hoardMapMonetaryRow(b, i) !=
                    kMapMonRow[b][i]) ++bad;
        // the map-to-magic references
        static const int kMapMag[10] = {
            0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
        };
        static const int kMapMagRow[10][2] = {
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 0, 0 },
            { 7, 7 },
            { 0, 0 },
            { 0, 0 },
        };
        for (int b = 0; b < 10; ++b)
            if (rules::hoardMapsToMagic(b) != kMapMag[b] ||
                rules::hoardMapMagicRowCount(b) != kMapMag[b]) ++bad;
        for (int b = 0; b < 10; ++b)
            for (int i = 0; i < 2; ++i)
                if (rules::hoardMapMagicRow(b, i) !=
                    kMapMagRow[b][i]) ++bad;
        // the design notes
        if (rules::hoardMustBeHiddenTrappedGuarded() != 1 ||
            rules::hoardDistantPlaces() != 1) ++bad;
        printf("R220 combined hoard table pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
