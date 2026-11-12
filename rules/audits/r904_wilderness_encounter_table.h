    // ---- R904 wilderness encounter table audit ----
    // THE WITCHCRAFT WILDERNESS ENCOUNTER TABLE ROUND - the folio-4 grid the
    // DjVu OCR garbled, made legible by the chat-side upload cross-check and
    // pinned as scanned: the number-appearing terrain bands as a 4-row table
    // (Mts/Desert none at the 0 sentinel, Riv/Swamps 2-4, Clear 1-3,
    // Towns/Woods 2-13), armor class 8, movement 9 on foot and 24 on broom,
    // hit dice 4-7, the Lawful 30 percent and Chaotic 45 percent lair lines,
    // the terrain factor doctrine (the woodlands and orchards favored), and
    // the lair device access (every portable magic device in the hoard). The
    // Secret Order exception stays pinned at R902 - no duplicate ink. The
    // cross-check also confirmed every R902 pages-1-5 pin against the upload:
    // the rolls 5 or 7 encounter doctrine, the 35/65 split, the 12-sided
    // Order ladder, the spell quotas, the immunities, and the spell matrix
    // rows Pit, Fire Box, Diminish, Plant Entrapment, Paralyzing Pit, Undead
    // Control, Aging, Circle of Blindness, Curse, Calm, Rejuvenation,
    // Dissipation and Comfort. The Comfort quirk is noted and settled: the
    // upload reads D = 3b (6 hours), the archive.org scan reads D = 36, and 6
    // hours at 10 minutes per turn is 36 turns - the pin stands. The
    // scoped-out sentence in tools/dragon_gap_report_005.md updates by file
    // patch to record the resolution. The R903 record seats in the seed via
    // prev_record.
    {
        using namespace rules;
        int bad = 0;
    if (wwtWitchAc() != 8
            || wwtWitchMoveFoot() != 9
            || wwtWitchMoveBroom() != 24
            || wwtWitchHdMin() != 4
            || wwtWitchHdMax() != 7
            || wwtLawfulWitchLairPct() != 30
            || wwtChaoticWitchLairPct() != 45
            || wwtTerrainNaCount() != 4
            || !wwtTableAppliesToAll()
            || !wwtTerrainFactor()
            || !wwtLairDeviceAccess()
        )
            ++bad;
        // the number-appearing band by terrain - Mts/Desert none, Riv/Swamps
        // 2-4, Clear 1-3, Towns/Woods 2-13 (folio 4)
        int CNaTr[4][2] = {
            {0,0},
            {2,4},
            {1,3},
            {2,13},
            };
        for (int b = 0;
             b < wwtTerrainNaCount();
             ++b) {
            int vals[2];
            vals[0] = wwtTerrainNaMin(b);
            vals[1] = wwtTerrainNaMax(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CNaTr[b][c])
                    ++bad;
            }
        }
        // the witch armor class 8, the 9 on foot and 24 on broom movement
        // (folio 4)
    if (wwtWitchAc() != 8
            || wwtWitchMoveFoot() != 9
            || wwtWitchMoveBroom() != 24
        )
            ++bad;
        // the witch hit dice 4-7, the 30 percent Lawful and 45 percent
        // Chaotic lair lines (folio 4)
    if (wwtWitchHdMin() != 4
            || wwtWitchHdMax() != 7
            || wwtLawfulWitchLairPct() != 30
            || wwtChaoticWitchLairPct() != 45
        )
            ++bad;
        // the encounter table doctrines - all non-Secret witches comply,
        // terrain factors the numbers, the lair device access (folio 4)
    if (wwtTableAppliesToAll() != 1
            || wwtTerrainFactor() != 1
            || wwtLairDeviceAccess() != 1
        )
            ++bad;
        // the number-appearing band, row %d of 4 - Mts/Desert none,
        // Riv/Swamps 2-4, Clear 1-3, Towns/Woods 2-13 (folio 4)
    if (wwtTerrainNaMin(0) != 0
            || wwtTerrainNaMax(0) != 0
            || wwtTerrainNaCount() != 4
        )
            ++bad;
        // the number-appearing band, row %d of 4 - Mts/Desert none,
        // Riv/Swamps 2-4, Clear 1-3, Towns/Woods 2-13 (folio 4)
    if (wwtTerrainNaMin(1) != 2
            || wwtTerrainNaMax(1) != 4
        )
            ++bad;
        // the number-appearing band, row %d of 4 - Mts/Desert none,
        // Riv/Swamps 2-4, Clear 1-3, Towns/Woods 2-13 (folio 4)
    if (wwtTerrainNaMin(2) != 1
            || wwtTerrainNaMax(2) != 3
        )
            ++bad;
        // the number-appearing band, row %d of 4 - Mts/Desert none,
        // Riv/Swamps 2-4, Clear 1-3, Towns/Woods 2-13 (folio 4)
    if (wwtTerrainNaMin(3) != 2
            || wwtTerrainNaMax(3) != 13
        )
            ++bad;
        printf("R904 wilderness encounter table audit: bad %d\n", bad);
        if (bad) return 1;
    }
