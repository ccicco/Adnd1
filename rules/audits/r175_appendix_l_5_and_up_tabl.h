    // ---- R175: appendix L 5-and-up table audit -----
    // DMG p.222: the full 5-and-up section the
    // book upload drops - pinned from the
    // 1eonline.info compilation (the repo-trusted
    // source). Hit dice categories 5-14, 26 rows
    // cell by cell: the banded categories (5, 6,
    // 7, 8, 10, 12) with every dice-score column;
    // the bandless rows (9, 11, 13, 14) the print
    // dashes, pinned as lo/hi 0. JUDGMENT: the
    // compilation spelling woolly (the R171 wooly
    // corrected); the bandless rows carry no
    // dice-score column, so only the contiguity
    // walk gates the banded ones.
    {
        int bad = 0;
        static const int kCat[26] = {
            5, 5, 5, 5, 5, 5, 5,
            6, 6, 6, 6,
            7, 7,
            8, 8, 8,
            9,
            10, 10,
            11,
            12, 12,
            13, 13,
            14, 14
        };
        static const int kLo[26] = {
             1, 11, 26, 36, 51, 71, 86,
             1, 41, 61, 81,
             1, 66,
             1, 31, 71,
             0,
             1, 61,
             0,
             1, 61,
             0, 0,
             0, 0
        };
        static const int kHi[26] = {
            10, 25, 35, 50, 70, 85, 100,
            40, 60, 80, 100,
            65, 100,
            30, 70, 100,
            0,
            60, 100,
            0,
            60, 100,
            0, 0,
            0, 0
        };
        static const char* const kNm[26] = {
            "ape, carnivorous",
            "buffalo",
            "hyena, giant",
            "otter, giant",
            "skunk, giant",
            "stag, giant",
            "wolverine, giant",
            "bear, brown",
            "lion",
            "porcupine, giant",
            "tiger",
            "boar, giant",
            "lion, spotted",
            "bear, cave",
            "hippopotamus",
            "tiger, sabre-tooth",
            "rhinoceros",
            "elephant",
            "rhinoceros, woolly",
            "elephant (loxodont)",
            "mastodon",
            "titanothere",
            "mammoth",
            "whale (small)",
            "baluchitherium",
            "whale (small)"
        };
        static const int kCost[26] = {
            20, 20, 20, 20, 20, 20, 20,
            25, 22, 24, 25,
            28, 26,
            30, 32, 30,
            34,
            40, 40,
            44,
            48, 48,
            52, 52,
            56, 56
        };
        if (rules::klmConjHigherCount() != 26) ++bad;
        for (int i = 0; i < 26; ++i) {
            const rules::ConjHigherRow& r =
                rules::klmConjHigherRow(i);
            if (r.cat  != kCat[i])  ++bad;
            if (r.lo   != kLo[i])   ++bad;
            if (r.hi   != kHi[i])   ++bad;
            if (std::string(r.name) != kNm[i]) ++bad;
            if (r.cost != kCost[i]) ++bad;
        }
        // the clamps: index -1 and 26+ read the ends
        if (rules::klmConjHigherRow(-1).cat != 5 ||
            rules::klmConjHigherRow(99).cat != 14)
            ++bad;
        // the banded categories: first row lo 1,
        // contiguous bands, last row hi 100
        for (int i = 0; i < 26; ++i) {
            const rules::ConjHigherRow& r =
                rules::klmConjHigherRow(i);
            if (r.lo == 0) continue;   // bandless
            bool first = (i == 0) ||
                rules::klmConjHigherRow(i - 1).cat
                    != r.cat;
            bool last = (i == 25) ||
                rules::klmConjHigherRow(i + 1).cat
                    != r.cat;
            if (first && r.lo != 1) ++bad;
            if (last) {
                if (r.hi != 100) ++bad;
            } else {
                const rules::ConjHigherRow& n =
                    rules::klmConjHigherRow(i + 1);
                if (r.hi + 1 != n.lo) ++bad;
            }
        }
        // the bandless categories are 9, 11, 13, 14
        for (int i = 0; i < 26; ++i) {
            const rules::ConjHigherRow& r =
                rules::klmConjHigherRow(i);
            if ((r.cat == 9 || r.cat == 11 ||
                 r.cat == 13 || r.cat == 14)
                && (r.lo != 0 || r.hi != 0)) ++bad;
        }
        // the whale cap and the water note stand
        if (rules::klmConjWhaleMaxHitDiceCost() != 36)
            ++bad;
        if (!rules::klmConjWaterSwimmersAndFlyersOnly())
            ++bad;
        printf("R175 appendix L 5-and-up table audit: bad %d\n", bad);
        if (bad) return 1;
    }
