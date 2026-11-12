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
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the Sceptre scalars, bands and blanks
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreSourceCrownOfMight() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreEvilBandLo() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreEvilBandHi() != 6 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreGoodBandLo() != 7 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreGoodBandHi() != 14 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreNeutralBandLo() != 15 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreNeutralBandHi() != 20 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreForeignEthosCrownEffects() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreBronzeInlaidSilver() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreHugeStoneTipping() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreLengthFeet() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreValueGp() != 150000 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreRodOfBeguiling() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreCrownOrbComboNote() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreBlankSlotCount() != 9) ++bad;
        static const int kS[6] = {
            1, 1, 0, 0, 0, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreTableUse(i) != kS[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreTableUse(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreTableUse(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreTableUse(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreTableUse(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreTableUse(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreTableUse(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreUseTotal()) ++bad;
        // the Kas legend scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapKasOfVecnaTheLich() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasBodyguardRightHand() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasFlatchetDullGrayMetal() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasSharpPointKeenEdges() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasServedFaithfully() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasHubrisGrew() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasSwordUrgedHimOn() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasGreaterThanVecna() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasCouldRuleInVecnaStead() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasDestroyedVecna() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasDoomWroughtTogether() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasWorldBrighter() != 1) ++bad;
        // the blade scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapKasPowersOnlyHinted() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasRenownedSwordsman() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasPlusBonus() != 6 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasDefender() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasDoubleDamageOffPlane() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasNormalDamageOnOtherPlanes() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasShortSword() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasEvilChaoticAlignment() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasIntelligence() != 15 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasEgo() != 19 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasTriesToControl() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasPrintsInOrder() != 1) ++bad;
        static const int kK[6] = {
            5, 2, 1, 2, 2, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapKasTableUse(i) != kK[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapKasTableUse(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasTableUse(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasTableUse(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasTableUse(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasTableUse(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasTableUse(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasUseTotal()) ++bad;
        // each Kas use carries one blank slot
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapKasBlankSlotCount() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapKasUseTotal()) ++bad;
        // the cross-pins: the R240 sale rows 24 and 25
        // (a range row and a fixed single-die row)
        if (specart.saRowLo(24) != 75 ||
            specart.saRowHi(24) != 91 ||
            specart.saSaleGp(24) != 150000 ||
            specart.saSaleGpHi(24) != 0 ||
            specart.saSaleGp(24) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapSceptreValueGp()) ++bad;
        if (specart.saRowLo(25) != 92 ||
            specart.saRowHi(25) != 92 ||
            specart.saSaleGp(25) != 97000 ||
            specart.saSaleGpHi(25) != 0) ++bad;
        printf("R293 special artifacts prose part 14 pins audit: bad %d\n", bad);
    }
