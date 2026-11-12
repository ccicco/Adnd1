    // ---- R281: the III.E Special artifacts
    // explanation prose part 2 ----
    // The Axe of the Dwarvish Lords, the Baba Yaga
    // Hut and the Codex of the Infinite Planes,
    // part2 lines 1184-1235 (DMG p.159-160) - the
    // first three of the 29 artifact descriptions.
    // One seam restored: the p.159-160 page break
    // splits the Codex paragraph between the 1216
    // tail and the 1221 head.
    {
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the Axe scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapAxeBladeSharpness() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxeHammerBonus() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxeHandleForms() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxeReturnFeet() != 30 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxeDwarfAbilityMultiplier() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxeLifespanBonusPct() != 50 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxeBearsCurse() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxeInvokedDevastationLost() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxePowerTotal() != 7) ++bad;
        // the Hut scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapHutDiameterFeet() != 15 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutHeightFeet() != 10 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutLegCount() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutLegLengthFeet() != 12 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutInfravisionFeet() != 120 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutRoomCount() != 30 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutFloorCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutMoveTerrainCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutCommanderCount() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutCallRangeLeagues() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutLegAttacksPerRound() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutLegArmorClass() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutLegHpEach() != 48 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutLegRegenPerRound() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutWallGraniteFeet() != 5 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutLegsHillGiantBlows() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutPowerTotal() != 10) ++bad;
        // the Codex scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCodexDamnedPages() != 99 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexDoomChancePct() != 99 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexPerilPerPagePct() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexTouchKillBelowLevel() != 11 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexCommandMinLevel() != 11 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexPerusalActivation() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexPowerTotal() != 16) ++bad;
        // the Axe powers per table I-VI
        static const int kAxp[6] = {
            2, 1, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapAxePowerCount(i) != kAxp[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapAxePowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxePowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxePowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxePowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxePowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxePowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapAxePowerTotal()) ++bad;
        // the Hut powers per table I-VI
        static const int kHup[6] = {
            4, 2, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapHutPowerCount(i) != kHup[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapHutPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapHutPowerTotal()) ++bad;
        // the Hut movement over its three terrains
        static const int kHum[3] = {
            48, 36, 12,
        };
        for (int i = 0; i < 3; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapHutMoveInches(i) != kHum[i]) ++bad;
        // the Codex powers per table I-VI
        static const int kCdp[6] = {
            4, 4, 2, 2, 2, 2,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapCodexPowerCount(i) != kCdp[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCodexPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexPowerTotal()) ++bad;
        // the Hut legs: two at 48 hit points each
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapHutLegCount() * specart_axe_of_the_dwarvish_lords_to_codex.sapHutLegHpEach()
            != 96) ++bad;
        // the Codex doom: 1 percent per page over 99
        // pages equals the 99 percent chance
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCodexPerilPerPagePct() *
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexDamnedPages() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexDoomChancePct()) ++bad;
        // the Codex level gates meet at the 11th
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCodexTouchKillBelowLevel() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCodexCommandMinLevel()) ++bad;
        // the cross-pins: the R240 sale table rows
        if (specart.saRowLo(0) != 1 ||
            specart.saRowHi(0) != 1 ||
            specart.saRowLo(1) != 2 ||
            specart.saRowHi(1) != 2 ||
            specart.saRowLo(2) != 3 ||
            specart.saRowHi(2) != 4 ||
            specart.saSaleGp(0) != 55000 ||
            specart.saSaleGp(1) != 90000 ||
            specart.saSaleGp(2) != 62500) ++bad;
        printf("R281 special artifacts prose part 2 pins audit: bad %d\n", bad);
    }
