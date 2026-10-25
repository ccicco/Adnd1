    // ---- R737 OA Table III Orient audit ----
    // OA round one hundred twenty-four (capture p. 287): the Table III.
    // (Orient) Magical Items - the twelve d100 bands, the category and
    // subtable codes of the DMG III.A. through III.E.5 riding with the band
    // edges, the oriental items band of this book, the armor and shields of
    // the capture misreading 8 for the &, the footnote to the DMG pages
    // 121-124, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkyRowCount() != 12
            || dkyDMGPageFirst() != 121
            || dkyDMGPageLast() != 124
            || dkyCatPotions() != 1
            || dkyCatScrolls() != 2
            || dkyCatRings() != 3
            || dkyCatRods() != 4
            || dkyCatMiscMagic() != 5
            || dkyCatOriental() != 6
            || dkyCatArmorShields() != 7
            || dkyCatWeapons() != 8
            || !dkyFootnoteDMGTables()
            || !dkyBandPotions()
            || !dkyBandScrolls()
            || !dkyBandRings()
            || !dkyBandRods()
            || !dkyBandMiscMagic()
            || !dkyBandOriental()
            || !dkyBandArmorShields()
            || !dkyBandWeapons()
        )
            ++bad;
        // the dkyIII grid
        int CIII[12][4] = {
            {1,10,1,1},
            {11,35,2,2},
            {36,40,3,3},
            {41,45,4,4},
            {46,47,5,1},
            {48,49,5,2},
            {50,51,5,3},
            {52,53,5,4},
            {54,55,5,5},
            {56,60,6,0},
            {61,75,7,0},
            {76,100,8,0},
            };
        int nIII[4] = {0,0,0,0};
        int eIII[4] = {0,0,0,3};
        for (int b = 0;
             b < dkyRowCount();
             ++b) {
            int vals[4];
            vals[0] = dkyRollMin(b);
            vals[1] = dkyRollMax(b);
            vals[2] = dkyCat(b);
            vals[3] = dkySub(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CIII[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nIII[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nIII[c] != eIII[c])
                ++bad;
        // the band bools - the eight category walkthrough, healthy values,
        // each condition false
    if (dkyBandPotions() != 1
            || dkyBandScrolls() != 1
            || dkyBandRings() != 1
            || dkyBandRods() != 1
            || dkyBandMiscMagic() != 1
            || dkyBandOriental() != 1
            || dkyBandArmorShields() != 1
            || dkyBandWeapons() != 1
            || dkyFootnoteDMGTables() != 1
        )
            ++bad;
        // the codes - the eight category codes and the DMG footnote pages,
        // healthy values, each condition false
    if (dkyCatPotions() != 1
            || dkyCatScrolls() != 2
            || dkyCatRings() != 3
            || dkyCatRods() != 4
            || dkyCatMiscMagic() != 5
            || dkyCatOriental() != 6
            || dkyCatArmorShields() != 7
            || dkyCatWeapons() != 8
            || dkyDMGPageFirst() != 121
            || dkyDMGPageLast() != 124
        )
            ++bad;
        // the grid - the twelve-band Table III, audited cell by cell by the
        // table audit
    if (dkyRowCount() != 12
        )
            ++bad;
        printf("R737 OA Table III Orient audit: bad %d\n", bad);
        if (bad) return 1;
    }
