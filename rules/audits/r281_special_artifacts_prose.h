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
        int bad = 0;
        // the Axe scalars
        if (rules::sapAxeBladeSharpness() != 1 ||
            rules::sapAxeHammerBonus() != 3 ||
            rules::sapAxeHandleForms() != 2 ||
            rules::sapAxeReturnFeet() != 30 ||
            rules::sapAxeDwarfAbilityMultiplier() != 2 ||
            rules::sapAxeLifespanBonusPct() != 50 ||
            rules::sapAxeBearsCurse() != 1 ||
            rules::sapAxeInvokedDevastationLost() != 1 ||
            rules::sapAxePowerTotal() != 7) ++bad;
        // the Hut scalars
        if (rules::sapHutDiameterFeet() != 15 ||
            rules::sapHutHeightFeet() != 10 ||
            rules::sapHutLegCount() != 2 ||
            rules::sapHutLegLengthFeet() != 12 ||
            rules::sapHutInfravisionFeet() != 120 ||
            rules::sapHutRoomCount() != 30 ||
            rules::sapHutFloorCount() != 3 ||
            rules::sapHutMoveTerrainCount() != 3 ||
            rules::sapHutCommanderCount() != 1 ||
            rules::sapHutCallRangeLeagues() != 1 ||
            rules::sapHutLegAttacksPerRound() != 2 ||
            rules::sapHutLegArmorClass() != 2 ||
            rules::sapHutLegHpEach() != 48 ||
            rules::sapHutLegRegenPerRound() != 1 ||
            rules::sapHutWallGraniteFeet() != 5 ||
            rules::sapHutLegsHillGiantBlows() != 1 ||
            rules::sapHutPowerTotal() != 10) ++bad;
        // the Codex scalars
        if (rules::sapCodexDamnedPages() != 99 ||
            rules::sapCodexDoomChancePct() != 99 ||
            rules::sapCodexPerilPerPagePct() != 1 ||
            rules::sapCodexTouchKillBelowLevel() != 11 ||
            rules::sapCodexCommandMinLevel() != 11 ||
            rules::sapCodexPerusalActivation() != 1 ||
            rules::sapCodexPowerTotal() != 16) ++bad;
        // the Axe powers per table I-VI
        static const int kAxp[6] = {
            2, 1, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapAxePowerCount(i) != kAxp[i]) ++bad;
        if (rules::sapAxePowerCount(0) +
            rules::sapAxePowerCount(1) +
            rules::sapAxePowerCount(2) +
            rules::sapAxePowerCount(3) +
            rules::sapAxePowerCount(4) +
            rules::sapAxePowerCount(5) !=
            rules::sapAxePowerTotal()) ++bad;
        // the Hut powers per table I-VI
        static const int kHup[6] = {
            4, 2, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapHutPowerCount(i) != kHup[i]) ++bad;
        if (rules::sapHutPowerCount(0) +
            rules::sapHutPowerCount(1) +
            rules::sapHutPowerCount(2) +
            rules::sapHutPowerCount(3) +
            rules::sapHutPowerCount(4) +
            rules::sapHutPowerCount(5) !=
            rules::sapHutPowerTotal()) ++bad;
        // the Hut movement over its three terrains
        static const int kHum[3] = {
            48, 36, 12,
        };
        for (int i = 0; i < 3; ++i)
            if (rules::sapHutMoveInches(i) != kHum[i]) ++bad;
        // the Codex powers per table I-VI
        static const int kCdp[6] = {
            4, 4, 2, 2, 2, 2,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapCodexPowerCount(i) != kCdp[i]) ++bad;
        if (rules::sapCodexPowerCount(0) +
            rules::sapCodexPowerCount(1) +
            rules::sapCodexPowerCount(2) +
            rules::sapCodexPowerCount(3) +
            rules::sapCodexPowerCount(4) +
            rules::sapCodexPowerCount(5) !=
            rules::sapCodexPowerTotal()) ++bad;
        // the Hut legs: two at 48 hit points each
        if (rules::sapHutLegCount() * rules::sapHutLegHpEach()
            != 96) ++bad;
        // the Codex doom: 1 percent per page over 99
        // pages equals the 99 percent chance
        if (rules::sapCodexPerilPerPagePct() *
            rules::sapCodexDamnedPages() !=
            rules::sapCodexDoomChancePct()) ++bad;
        // the Codex level gates meet at the 11th
        if (rules::sapCodexTouchKillBelowLevel() !=
            rules::sapCodexCommandMinLevel()) ++bad;
        // the cross-pins: the R240 sale table rows
        if (rules::saRowLo(0) != 1 ||
            rules::saRowHi(0) != 1 ||
            rules::saRowLo(1) != 2 ||
            rules::saRowHi(1) != 2 ||
            rules::saRowLo(2) != 3 ||
            rules::saRowHi(2) != 4 ||
            rules::saSaleGp(0) != 55000 ||
            rules::saSaleGp(1) != 90000 ||
            rules::saSaleGp(2) != 62500) ++bad;
        printf("R281 special artifacts prose part 2 pins audit: bad %d\n", bad);
    }
