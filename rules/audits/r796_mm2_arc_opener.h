    // ---- R796 MM2 arc opener audit ----
    // THE MM2 ARC OPENER - round zero of the Monster Manual II arc (the user
    // Go call on the new-book candidate, after the next-arc audit found every
    // standing book arc closed). The report mirrors the book structure
    // lossless: the front matter with the preface and acknowledgements, the
    // how-to-use doctrine in three boxes (the number-ranges table, the
    // general entries, the special entries), the A-Z letter boxes with the
    // pin-time sub-census doctrine (the R792 lesson applied at opener - the
    // family sub-rosters walk from the print, never from OCR), the three
    // encounter-table groups, the Index. THIS ROUND pins the front-matter
    // doctrine: the frequency percentages (very rare 3, rare 7, uncommon 20,
    // common 65, unique one), the magic resistance 11th-level base with the
    // 5-percent step, the 8-sided hit-die default, the intelligence ladder
    // bands with the godlike 21 floor, the multi-mode move notation, the MM1
    // treasure-type reference, the human attack matrix for the demihuman
    // types, the plane and class lines of the special entries. FIVE FLIPS:
    // the front matter, the how-to-use parent and its three doctrine boxes.
    // The gap report is NEW (the R564 opener pattern): published PRE-FLIP,
    // rverify in working-tree mode.
    {
        using namespace rules;
        int bad = 0;
    if (mmaOpenerRound() != 796
            || mmaBookPages() != 156
            || mmaAZFirstPage() != 8
            || mmaAZLastPage() != 132
            || mmaTablesFirstPage() != 133
            || mmaFreqVeryRarePct() != 3
            || mmaFreqRarePct() != 7
            || mmaFreqUncommonPct() != 20
            || mmaFreqCommonPct() != 65
            || mmaFreqUniqueCount() != 1
            || mmaMagicResistBaseLevel() != 11
            || mmaMagicResistStepPct() != 5
            || mmaHitDieSides() != 8
            || mmaIntelGodlikeLow() != 21
            || !mmaMonsterTermIsGeneric()
            || !mmaFrequencyPercentsPinned()
            || !mmaMoveNotationMultiMode()
            || !mmaManeuverabilityFromDMG()
            || !mmaHitDiceEightSidedDefault()
            || !mmaTreasureTypesFromMM1()
            || !mmaMagicResistanceElevenBase()
            || !mmaHumanMatrixForDemiHumans()
            || !mmaIntelligenceLadderIQ()
            || !mmaSpecialEntriesPlaneAndClass()
            || !mmaSizeBandsAreThree()
            || !mmaLevelXpRideDMGMethod()
        )
            ++bad;
        // the MM2 front matter walk (the doctrine ints)
    if (mmaOpenerRound() != 796
            || mmaBookPages() != 156
            || mmaAZFirstPage() != 8
            || mmaAZLastPage() != 132
            || mmaTablesFirstPage() != 133
            || mmaFreqVeryRarePct() != 3
            || mmaFreqRarePct() != 7
            || mmaFreqUncommonPct() != 20
            || mmaFreqCommonPct() != 65
            || mmaFreqUniqueCount() != 1
            || mmaMagicResistBaseLevel() != 11
            || mmaMagicResistStepPct() != 5
            || mmaHitDieSides() != 8
            || mmaIntelGodlikeLow() != 21
        )
            ++bad;
        // the MM2 front matter doctrine bools
    if (mmaMonsterTermIsGeneric() != 1
            || mmaFrequencyPercentsPinned() != 1
            || mmaMoveNotationMultiMode() != 1
            || mmaManeuverabilityFromDMG() != 1
            || mmaHitDiceEightSidedDefault() != 1
            || mmaTreasureTypesFromMM1() != 1
            || mmaMagicResistanceElevenBase() != 1
            || mmaHumanMatrixForDemiHumans() != 1
            || mmaIntelligenceLadderIQ() != 1
            || mmaSpecialEntriesPlaneAndClass() != 1
            || mmaSizeBandsAreThree() != 1
            || mmaLevelXpRideDMGMethod() != 1
        )
            ++bad;
        printf("R796 MM2 arc opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
