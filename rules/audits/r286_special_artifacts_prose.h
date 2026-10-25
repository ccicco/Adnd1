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
        int bad = 0;
        // the Flask scalars
        if (rules::sapFlaskHeavyUrn() != 1 ||
            rules::sapFlaskTurnipPlug() != 1 ||
            rules::sapFlaskSigilRunes() != 1 ||
            rules::sapFlaskWordCount() != 3) ++bad;
        if (rules::sapFlaskPrisonerCount() != 5 ||
            rules::sapFlaskServantEvilOnly() != 1 ||
            rules::sapFlaskKillBeforeReturn() != 1 ||
            rules::sapFlaskPowerTotal() != 6) ++bad;
        // the Flask powers per table I-VI
        static const int kFla[6] = {
            3, 0, 1, 0, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapFlaskPowerCount(i) != kFla[i]) ++bad;
        if (rules::sapFlaskPowerCount(0) +
            rules::sapFlaskPowerCount(1) +
            rules::sapFlaskPowerCount(2) +
            rules::sapFlaskPowerCount(3) +
            rules::sapFlaskPowerCount(4) +
            rules::sapFlaskPowerCount(5) !=
            rules::sapFlaskPowerTotal()) ++bad;
        // the 3 words: 2 fewer than the 5 prisoners
        if (rules::sapFlaskPrisonerCount() -
            rules::sapFlaskWordCount() != 2) ++bad;
        // the Jacinth scalars
        if (rules::sapJacinthGodFashioned() != 1 ||
            rules::sapJacinthMountainHeart() != 1 ||
            rules::sapJacinthFacetedBeams() != 1 ||
            rules::sapJacinthCharmRangeFt() != 20 ||
            rules::sapJacinthSultanPossessed() != 1 ||
            rules::sapJacinthKeolandTrailLost() != 1 ||
            rules::sapJacinthGraspPowers() != 1 ||
            rules::sapJacinthPowerTotal() != 8) ++bad;
        // the Jacinth powers per table I-VI
        static const int kJac[6] = {
            2, 2, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapJacinthPowerCount(i) != kJac[i]) ++bad;
        if (rules::sapJacinthPowerCount(0) +
            rules::sapJacinthPowerCount(1) +
            rules::sapJacinthPowerCount(2) +
            rules::sapJacinthPowerCount(3) +
            rules::sapJacinthPowerCount(4) +
            rules::sapJacinthPowerCount(5) !=
            rules::sapJacinthPowerTotal()) ++bad;
        // the Mask scalars
        if (rules::sapMaskJohydeeTrickedEvil() != 1 ||
            rules::sapMaskOverthrewNation() != 1 ||
            rules::sapMaskCoversFace() != 1 ||
            rules::sapMaskAssumeLikeness() != 1 ||
            rules::sapMaskBlocksMindContact() != 1 ||
            rules::sapMaskGazeImmunity() != 1 ||
            rules::sapMaskGazeCreatureCount() != 3 ||
            rules::sapMaskPowerTotal() != 4) ++bad;
        // the Mask powers per table I-VI
        static const int kMsk[6] = {
            2, 1, 0, 0, 0, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapMaskPowerCount(i) != kMsk[i]) ++bad;
        if (rules::sapMaskPowerCount(0) +
            rules::sapMaskPowerCount(1) +
            rules::sapMaskPowerCount(2) +
            rules::sapMaskPowerCount(3) +
            rules::sapMaskPowerCount(4) +
            rules::sapMaskPowerCount(5) !=
            rules::sapMaskPowerTotal()) ++bad;
        // the gaze trio and the Flask words agree
        if (rules::sapMaskGazeCreatureCount() !=
            rules::sapFlaskWordCount()) ++bad;
        // the cross-pins: the R240 sale table rows
        if (rules::saRowLo(11) != 30 ||
            rules::saRowHi(11) != 31 ||
            rules::saSaleGp(11) != 50000 ||
            rules::saRowLo(12) != 32 ||
            rules::saRowHi(12) != 32 ||
            rules::saSaleGp(12) != 100000 ||
            rules::saRowLo(13) != 33 ||
            rules::saRowHi(13) != 33 ||
            rules::saSaleGp(13) != 40000) ++bad;
        printf("R286 special artifacts prose part 7 pins audit: bad %d\n", bad);
    }
