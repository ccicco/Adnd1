    // ---- R293: the III.E Special artifacts
    // explanation prose part 14 ----
    // The Sceptre of Might and the
    // Sword of Kas, part2 lines
    // 1708-1743. No break absorbed -
    // the round closes on the standard
    // blank at 1743; no page seam claimed
    // (no running heads between lines 1450
    // and 1797).
    {
        int bad = 0;
        // the Sceptre scalars, bands and blanks
        if (rules::sapSceptreCount() != 3 ||
            rules::sapSceptreSourceCrownOfMight() != 1 ||
            rules::sapSceptreEvilBandLo() != 1 ||
            rules::sapSceptreEvilBandHi() != 6 ||
            rules::sapSceptreGoodBandLo() != 7 ||
            rules::sapSceptreGoodBandHi() != 14 ||
            rules::sapSceptreNeutralBandLo() != 15 ||
            rules::sapSceptreNeutralBandHi() != 20 ||
            rules::sapSceptreForeignEthosCrownEffects() != 1 ||
            rules::sapSceptreBronzeInlaidSilver() != 1 ||
            rules::sapSceptreHugeStoneTipping() != 1 ||
            rules::sapSceptreLengthFeet() != 2 ||
            rules::sapSceptreValueGp() != 150000 ||
            rules::sapSceptreRodOfBeguiling() != 1 ||
            rules::sapSceptreCrownOrbComboNote() != 1 ||
            rules::sapSceptreBlankSlotCount() != 9) ++bad;
        static const int kS[6] = {
            1, 1, 0, 0, 0, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapSceptreTableUse(i) != kS[i]) ++bad;
        if (rules::sapSceptreTableUse(0) +
            rules::sapSceptreTableUse(1) +
            rules::sapSceptreTableUse(2) +
            rules::sapSceptreTableUse(3) +
            rules::sapSceptreTableUse(4) +
            rules::sapSceptreTableUse(5) !=
            rules::sapSceptreUseTotal()) ++bad;
        // the Kas legend scalars
        if (rules::sapKasOfVecnaTheLich() != 1 ||
            rules::sapKasBodyguardRightHand() != 1 ||
            rules::sapKasFlatchetDullGrayMetal() != 1 ||
            rules::sapKasSharpPointKeenEdges() != 1 ||
            rules::sapKasServedFaithfully() != 1 ||
            rules::sapKasHubrisGrew() != 1 ||
            rules::sapKasSwordUrgedHimOn() != 1 ||
            rules::sapKasGreaterThanVecna() != 1 ||
            rules::sapKasCouldRuleInVecnaStead() != 1 ||
            rules::sapKasDestroyedVecna() != 1 ||
            rules::sapKasDoomWroughtTogether() != 1 ||
            rules::sapKasWorldBrighter() != 1) ++bad;
        // the blade scalars
        if (rules::sapKasPowersOnlyHinted() != 1 ||
            rules::sapKasRenownedSwordsman() != 1 ||
            rules::sapKasPlusBonus() != 6 ||
            rules::sapKasDefender() != 1 ||
            rules::sapKasDoubleDamageOffPlane() != 1 ||
            rules::sapKasNormalDamageOnOtherPlanes() != 1 ||
            rules::sapKasShortSword() != 1 ||
            rules::sapKasEvilChaoticAlignment() != 1 ||
            rules::sapKasIntelligence() != 15 ||
            rules::sapKasEgo() != 19 ||
            rules::sapKasTriesToControl() != 1 ||
            rules::sapKasPrintsInOrder() != 1) ++bad;
        static const int kK[6] = {
            5, 2, 1, 2, 2, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapKasTableUse(i) != kK[i]) ++bad;
        if (rules::sapKasTableUse(0) +
            rules::sapKasTableUse(1) +
            rules::sapKasTableUse(2) +
            rules::sapKasTableUse(3) +
            rules::sapKasTableUse(4) +
            rules::sapKasTableUse(5) !=
            rules::sapKasUseTotal()) ++bad;
        // each Kas use carries one blank slot
        if (rules::sapKasBlankSlotCount() !=
            rules::sapKasUseTotal()) ++bad;
        // the cross-pins: the R240 sale rows 24 and 25
        // (a range row and a fixed single-die row)
        if (rules::saRowLo(24) != 75 ||
            rules::saRowHi(24) != 91 ||
            rules::saSaleGp(24) != 150000 ||
            rules::saSaleGpHi(24) != 0 ||
            rules::saSaleGp(24) !=
            rules::sapSceptreValueGp()) ++bad;
        if (rules::saRowLo(25) != 92 ||
            rules::saRowHi(25) != 92 ||
            rules::saSaleGp(25) != 97000 ||
            rules::saSaleGpHi(25) != 0) ++bad;
        printf("R293 special artifacts prose part 14 pins audit: bad %d\n", bad);
    }
