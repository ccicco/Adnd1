    // ---- R777 saddle audit ----
    // THE SADDLE ACQUISITION - the R776 site gets its writer. The town stable
    // sells the R300 livestock horse rows best-affordable-first (the price
    // reads the pinned equipcosts cells by NAME plus the tack saddle row,
    // never a hardcode), the save carries the optional "mount" line (v1 saves
    // load as afoot), and the party.h comment flips from the seam promise to
    // the wiring fact. The steed GRANT ladder stays book-side: the engine has
    // no cavalier or paladin class to key a grant on, so the mml/cavalier
    // grant pins stay contract-side. The kind ladder rides this header (the
    // sdd consts) and the state TUs read it through explicit includes (the
    // R400 lesson)
    {
        using namespace rules;
        int bad = 0;
    if (sddMountKindCount() != 7
            || sddKindDraft() != 1
            || sddKindLightWar() != 2
            || sddKindMediumWar() != 3
            || sddKindHeavyWar() != 4
            || sddKindRiding() != 5
            || sddKindPony() != 6
            || sddStableStockCount() != 5
            || !sddTownStableSellsMounts()
            || !sddStableReadsPinnedCells()
            || !sddSaveCarriesMountLine()
            || !sddV1SaveLoadsAfoot()
        )
            ++bad;
        printf("R777 saddle audit: bad %d\n", bad);
        if (bad) return 1;
    }
