    // ---- R286: the III.E Special artifacts
    // explanation prose part 7 ----
    // The Iron Flask of Tuerny,
    // The Jacinth of Inestimable Beauty
    // and The Johydees Mask, part2
    // lines 1405-1451 (DMG p.162-163)
    // - the 12th through the 14th of
    // the 29 descriptions.
    // One seam restored: the p.162-163
    // page break falls between the Mask
    // power table and the Kuroth Quill
    // opener across the blank pair at
    // 1448-1449, the running head at
    // 1450 and the 1451 post-head
    // blank - nothing severed this
    // time.
    {
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the Flask scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskHeavyUrn() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskTurnipPlug() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskSigilRunes() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskWordCount() != 3) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskPrisonerCount() != 5 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskServantEvilOnly() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskKillBeforeReturn() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskPowerTotal() != 6) ++bad;
        // the Flask powers per table I-VI
        static const int kFla[6] = {
            3, 0, 1, 0, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskPowerCount(i) != kFla[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskPowerTotal()) ++bad;
        // the 3 words: 2 fewer than the 5 prisoners
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskPrisonerCount() -
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskWordCount() != 2) ++bad;
        // the Jacinth scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthGodFashioned() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthMountainHeart() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthFacetedBeams() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthCharmRangeFt() != 20 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthSultanPossessed() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthKeolandTrailLost() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthGraspPowers() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthPowerTotal() != 8) ++bad;
        // the Jacinth powers per table I-VI
        static const int kJac[6] = {
            2, 2, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthPowerCount(i) != kJac[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapJacinthPowerTotal()) ++bad;
        // the Mask scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapMaskJohydeeTrickedEvil() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaskOverthrewNation() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaskCoversFace() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaskAssumeLikeness() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaskBlocksMindContact() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaskGazeImmunity() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaskGazeCreatureCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaskPowerTotal() != 4) ++bad;
        // the Mask powers per table I-VI
        static const int kMsk[6] = {
            2, 1, 0, 0, 0, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapMaskPowerCount(i) != kMsk[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapMaskPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaskPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaskPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaskPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaskPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaskPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapMaskPowerTotal()) ++bad;
        // the gaze trio and the Flask words agree
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapMaskGazeCreatureCount() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapFlaskWordCount()) ++bad;
        // the cross-pins: the R240 sale table rows
        if (specart.saRowLo(11) != 30 ||
            specart.saRowHi(11) != 31 ||
            specart.saSaleGp(11) != 50000 ||
            specart.saRowLo(12) != 32 ||
            specart.saRowHi(12) != 32 ||
            specart.saSaleGp(12) != 100000 ||
            specart.saRowLo(13) != 33 ||
            specart.saRowHi(13) != 33 ||
            specart.saSaleGp(13) != 40000) ++bad;
        printf("R286 special artifacts prose part 7 pins audit: bad %d\n", bad);
    }
