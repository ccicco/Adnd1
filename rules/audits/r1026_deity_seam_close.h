    // ---- R1026 deity seam close audit ----
    // THE DEITY SEAM CLOSES - the L&L parity inventory: 130 parity notes
    // across the pin headers, every one adjudicated (pinned by print,
    // restored from the L&L voice, the eyeball flags pin-internal, the
    // geometry verified), ZERO open divergences, ZERO derivative tesseract
    // voices needed, the at-most-one divergence round not needed, L&L a
    // parity voice not a second book; the DDG arc complete - 24 boxes closed,
    // 338 defs canonical, the registry 1338 of 1338.
    {
        using namespace rules;
        int bad = 0;
    if (ll1Round() != 1026
            || ll1DdgDefsCanonical() != 338
            || ll1RegistryCanonical() != 1338
            || ll1ParityNotes() != 130
            || ll1PrintRestores() != 8
            || ll1EyeballFlags() != 3
            || ll1ParityAdjudicated() != 130
            || ll1OpenDivergences() != 0
            || ll1DerivativeVoices() != 0
            || !ll1SeamClosed()
            || !ll1NoDivergenceRound()
            || !ll1PrimaryInkIntact()
        )
            ++bad;
        // the example
    if (ll1Round() != 1026
            || ll1ParityNotes() != 130
            || ll1DdgDefsCanonical() != 338
            || ll1RegistryCanonical() != 1338
        )
            ++bad;
        // the example
    if (ll1ParityAdjudicated() != ll1ParityNotes() - ll1OpenDivergences()
        )
            ++bad;
        // the example
    if (ll1OpenDivergences() != 0
            || ll1DerivativeVoices() != 0
        )
            ++bad;
        // the example
    if (ll1PrintRestores() + ll1EyeballFlags() > ll1ParityNotes()
        )
            ++bad;
        printf("R1026 deity seam close audit: bad %d\n", bad);
        if (bad) return 1;
    }
