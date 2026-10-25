    // ---- R565 MotP spell summary audit ----
    // the garbled pp. 8-9 spread closed by reconstruction: the eight school
    // groups, the C/D/I/M class-code legend, the parenthetical pair codes,
    // and 35 sample spell entries verified legible in the OCR and matching
    // the canonical PHB levels (magic missile 1M, fireball 3M, wall of force
    // 4M, cure light wounds 1C, holy word 7C, and kin) - the summary mirrors
    // the p. 10 school definitions pinned at R564.
    {
        using namespace rules;
        int bad = 0;
    if (dctSpellSummarySchoolCount() != 8
            || dctSpellSummaryClassCodeCount() != 4
            || dctSpellSummaryVerifiedCount() != 35
            || !dctSpellSummaryPairCodes()
            || !dctSpellSummaryReconstructed()
        )
            ++bad;
        // the eight school groups
    if (dctSpellSummarySchoolCount() != 8
        )
            ++bad;
        // the four class codes
    if (dctSpellSummaryClassCodeCount() != 4
        )
            ++bad;
        // the 35 verified sample entries
    if (dctSpellSummaryVerifiedCount() != 35
        )
            ++bad;
        // the parenthetical pair codes
    if (dctSpellSummaryPairCodes() != 1
        )
            ++bad;
        // the reconstruction complete
    if (dctSpellSummaryReconstructed() != 1
        )
            ++bad;
        printf("R565 MotP spell summary audit: bad %d\n", bad);
        if (bad) return 1;
    }
