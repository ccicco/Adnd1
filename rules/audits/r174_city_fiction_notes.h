    // ---- R174: city fiction notes audit ----
    // The two remaining R64 flavor notes, pinned from
    // the fresh DMG upload (p.191-192): the noble
    // gender coin (nobleman-with-retainers 75% /
    // noblewoman 25%, the R149-corrected reading)
    // with the noblewoman 75% sedan-chair likelihood
    // (carriers and linkboys at night), and the
    // ruffian matrix footnote - 1 in 4 half-orc or
    // humanoid (goblin, hobgoblin, kobold, orc),
    // banded as five equal fifths of the quarter
    // (the weights unstated, documented). Every band
    // edge pinned both ways plus the 1-100 sweep.
    {
        int bad = 0;
        // the noble gender coin (p.191): 2 bands
        static const struct { int lo, hi; const char* k; }
            kNoble[] = {
            {  1, 75, "nobleman" },
            { 76,100, "noblewoman" },
        };
        for (int i = 0; i < 2; ++i) {
            if (std::string(dm::cityNobleKind(kNoble[i].lo))
                != kNoble[i].k) ++bad;
            if (std::string(dm::cityNobleKind(kNoble[i].hi))
                != kNoble[i].k) ++bad;
            if (kNoble[i].lo > 1 && std::string(
                    dm::cityNobleKind(kNoble[i].lo - 1))
                == kNoble[i].k) ++bad;
        }
        // the noblewoman ride (p.192): 2 bands
        static const struct { int lo, hi; const char* k; }
            kSedan[] = {
            {  1, 75, "sedan chair" },
            { 76,100, "on foot" },
        };
        for (int i = 0; i < 2; ++i) {
            if (std::string(
                    dm::cityNoblewomanSedan(kSedan[i].lo))
                != kSedan[i].k) ++bad;
            if (std::string(
                    dm::cityNoblewomanSedan(kSedan[i].hi))
                != kSedan[i].k) ++bad;
            if (kSedan[i].lo > 1 && std::string(
                    dm::cityNoblewomanSedan(kSedan[i].lo - 1))
                == kSedan[i].k) ++bad;
        }
        // the ruffian 1-in-4 note (p.191): 6 bands
        static const struct { int lo, hi; const char* k; }
            kRuff[] = {
            {   1, 75, "human" },
            {  76, 80, "half-orc" },
            {  81, 85, "goblin" },
            {  86, 90, "hobgoblin" },
            {  91, 95, "kobold" },
            {  96,100, "orc" },
        };
        for (int i = 0; i < 6; ++i) {
            if (std::string(dm::cityRuffianKind(kRuff[i].lo))
                != kRuff[i].k) ++bad;
            if (std::string(dm::cityRuffianKind(kRuff[i].hi))
                != kRuff[i].k) ++bad;
            if (kRuff[i].lo > 1 && std::string(
                    dm::cityRuffianKind(kRuff[i].lo - 1))
                == kRuff[i].k) ++bad;
        }
        // the sweep: every percentile yields a kind on
        // all three tables (the clamps cover <1 / >100)
        for (int p = 1; p <= 100; ++p) {
            if (!*dm::cityNobleKind(p)) ++bad;
            if (!*dm::cityNoblewomanSedan(p)) ++bad;
            if (!*dm::cityRuffianKind(p)) ++bad;
        }
        printf("R174 city fiction notes audit: bad %d\n", bad);
        if (bad) return 1;
    }
