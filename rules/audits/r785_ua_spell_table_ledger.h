    // ---- R785 UA spell table ledger audit ----
    // THE UA SPELL TABLE LEDGER - the R342 PDF-ledger holes close (Curtiss's
    // "stay in covered books" call). The archive.org full-text OCR reads the
    // continued table: the 6th-level column repairs (17 names), the drifted
    // cells re-seat, Clone and Otiluke's Telekinetic Sphere newly read, and
    // the fragment holes resolve against the UA-new description rosters and
    // the R80 registry. Glassteel and Power Word Kill stay open holes.
    // THIRTEEN consts + TWENTY bools + the 4 x 3 ledger grid; the string
    // rosters ride 13 file patches (7 on rules/uaspelltables2.h, 6 on
    // regtest.cpp including the R361/R362 seam reversals).
    {
        using namespace rules;
        int bad = 0;
    if (sldLedgerRound() != 785
            || sldFeederRound() != 342
            || sldColumnCount() != 4
            || sldMu6thRosterCount() != 17
            || sldMu7thRosterCount() != 16
            || sldMu8thRosterCount() != 10
            || sldMu9thRosterCount() != 8
            || sldIl3rdNewCount() != 4
            || sldIl4thNewCount() != 4
            || sldIl5thNewCount() != 4
            || sldIl6thNewCount() != 4
            || sldIl7thNewCount() != 2
            || sldIlNewTotalCount() != 18
            || !sldSixthColumnRead()
            || !sldContaminationRepaired()
            || !sldWhipDoubtStruck()
            || !sldFlamingIsFlamingSphere()
            || !sldProtectionFromIsCantrips()
            || !sldDetectIsDetectIllusion()
            || !sldItemResolves()
            || !sldMaterialResolves()
            || !sldDispelIsDispelIllusion()
            || !sldDolorResolves()
            || !sldTruenameResolves()
            || !sldGravityIsReverseGravity()
            || !sldProjectImIsProjectImage()
            || !sldMirrorImagIsMirrorImage()
            || !sldPhantomWindResolves()
            || !sldToFleshIsSixthColumnBleed()
            || !sldSixthPhbRowsStayOpen()
            || !sldEighthHolesStayOpen()
            || !sldIlColumnsPhbSideLost()
            || !sldRowNumbersUnreliable()
        )
            ++bad;
        // THE MU COLUMN LEDGER - one row per repaired level (6th-9th): the
        // readable cells plus the UA-new description names plus the registry
        // rows must sum to the roster count. Row 0 the 6th (12+3+2=17), row 1
        // the 7th (9+6+1=16), row 2 the 8th (9+1+0=10), row 3 the 9th
        // (5+3+0=8)
        int CMuLedger[4][3] = {
            {12,3,2},
            {9,6,1},
            {9,1,0},
            {5,3,0},
            };
        int nMuLedger[3] = {0,0,0};
        int eMuLedger[3] = {0,0,0};
        for (int b = 0;
             b < sldColumnCount();
             ++b) {
            int vals[3];
            vals[0] = sldReadableCells(b);
            vals[1] = sldDescNewUnreadable(b);
            vals[2] = sldRegistryRows(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CMuLedger[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nMuLedger[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nMuLedger[c] != eMuLedger[c])
                ++bad;
        // the 6th ledger row sums to the roster count
    if (sldMu6thRosterCount() != sldReadableCells(0) + sldDescNewUnreadable(0)
        + sldRegistryRows(0)
        )
            ++bad;
        // the 7th ledger row sums to the roster count
    if (sldMu7thRosterCount() != sldReadableCells(1) + sldDescNewUnreadable(1)
        + sldRegistryRows(1)
        )
            ++bad;
        // the 8th ledger row sums to the roster count
    if (sldMu8thRosterCount() != sldReadableCells(2) + sldDescNewUnreadable(2)
        + sldRegistryRows(2)
        )
            ++bad;
        // the 9th ledger row sums to the roster count
    if (sldMu9thRosterCount() != sldReadableCells(3) + sldDescNewUnreadable(3)
        + sldRegistryRows(3)
        )
            ++bad;
        // the round consts (the ledger round, the feeder round, the grid
        // census)
    if (sldLedgerRound() != 785
            || sldFeederRound() != 342
            || sldColumnCount() != 4
        )
            ++bad;
        // the illusionist UA-new censuses sum to the total
    if (sldIlNewTotalCount() != 18
            || sldIl3rdNewCount() + sldIl4thNewCount() + sldIl5thNewCount() +
            sldIl6thNewCount() + sldIl7thNewCount() != sldIlNewTotalCount()
        )
            ++bad;
        // the doctrine bools (the column read, the contamination repair, the
        // strikes, the standing losses)
    if (sldSixthColumnRead() != 1
            || sldContaminationRepaired() != 1
            || sldWhipDoubtStruck() != 1
            || sldToFleshIsSixthColumnBleed() != 1
            || sldSixthPhbRowsStayOpen() != 1
            || sldEighthHolesStayOpen() != 1
            || sldIlColumnsPhbSideLost() != 1
            || sldRowNumbersUnreliable() != 1
        )
            ++bad;
        // the fragment-resolution bools (every R342 fragment hole resolves)
    if (sldFlamingIsFlamingSphere() != 1
            || sldProtectionFromIsCantrips() != 1
            || sldDetectIsDetectIllusion() != 1
            || sldItemResolves() != 1
            || sldMaterialResolves() != 1
            || sldDispelIsDispelIllusion() != 1
            || sldDolorResolves() != 1
            || sldTruenameResolves() != 1
            || sldGravityIsReverseGravity() != 1
            || sldProjectImIsProjectImage() != 1
            || sldMirrorImagIsMirrorImage() != 1
            || sldPhantomWindResolves() != 1
        )
            ++bad;
        printf("R785 UA spell table ledger audit: bad %d\n", bad);
        if (bad) return 1;
    }
