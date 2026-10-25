    // ---- R820 lammasu promotion audit ----
    // THE LAMMASU PROMOTION - the queued R817 discovery closed (Curtiss Go
    // call lammasu on the landed R819 index walk): the Lammasu, Greater stat
    // block, MM2 print p. 79 (between the kraken and the land lamprey), the
    // block the R808 LMN walk never promoted, rides as a def. THE DEF: the
    // key lammasu_greater, promoted from the MM2 print (the xpSource
    // mm2_print class), AC 3, HD 12+7 (the book-average 61), MOVE 15/30 (MC:
    // B), 2 attacks for 2-12/2-12, MR 40 percent, level VIII XP 3,950 + 18/hp
    // (the full kill XP 5,048), lawful good, supra-genius, size L (5 feet
    // high at the shoulder), nil treasure and nil lair, psionic nil. THE
    // TWO-VOICE SETTLE: the djvu OCR garbles the move stat (the 5V3Q read) -
    // the 1eonline transcription reads 15/30 MC B and the compendium tables
    // agree (15, Fl 30, B). THE REWIRE: the two R817 outdoor cells (the
    // temperate civilized plains die 2, grid 22; the tropical civilized hills
    // die 20, grid 31) rekey lammasu_greater - the src cells stay 2, the R817
    // source census unchanged; the walk-key census bumps 570 to 572 (the
    // mm2enco header const and the R817 audit const chain and expression all
    // ride this round as file patches, the LammasuGreaterRows const stays 2).
    // THE REGISTRY: 809 to 810 defs, the MM2 defs 331 to 332; the R817-R819
    // registry-floor consts stand as their own round snapshots (the >= floor
    // checks stay green). THE DOCTRINE (the p. 79 prose): the greater lammasu
    // travel the Astral and Ethereal Planes at will, become invisible,
    // dimension door and teleport without error (1 at a time, 1 per round),
    // radiate protection from evil for a 20-foot radius with double effect
    // (-4 to evil attacks, +4 on saves), use clerical spells at 5th-level
    // ability (5/4/3/2/1 spells of levels 1-5), the cures double strength
    // based on 1d6+1 (cure light wounds 4-14, cure serious wounds 8-28), 50
    // percent speak a holy word, the spell-like ability level 12 (as hit
    // dice), dwell with 6 or more ordinary lammasu. NO gap boxes flip this
    // round - the MM2 arc gap stays 37 closed 0 open.
    {
        using namespace rules;
        int bad = 0;
    if (lmpRound() != 820
            || lmpPrintPage() != 79
            || lmpStatArmorClass() != 3
            || lmpStatHitDice() != 12
            || lmpStatHitDiceBonus() != 7
            || lmpStatAvgHp() != 61
            || lmpStatNumAttacks() != 2
            || lmpStatXp() != 3950
            || lmpStatXpPerHp() != 18
            || lmpStatXpValue() != 5048
            || lmpStatMagicResistance() != 40
            || lmpHolyWordPct() != 50
            || lmpProtectionRadius() != 20
            || lmpClericalSpellLevel() != 5
            || lmpSpellAbilityLevel() != 12
            || lmpPrideSize() != 6
            || lmpRegistryBefore() != 809
            || lmpRegistryAfter() != 810
            || lmpMm2DefsBefore() != 331
            || lmpMm2DefsAfter() != 332
            || lmpCellsRewired() != 2
            || lmpGridTC5Index() != 22
            || lmpGridRC2Index() != 31
            || lmpWalkKeyRowsBefore() != 570
            || lmpWalkKeyRowsAfter() != 645
            || !lmpPromotedFromMM2Print()
            || !lmpMoveSettledByTwoVoices()
            || !lmpNilTreasureAndLair()
            || !lmpLawfulGoodSupraGenius()
            || !lmpAstralEtherealTravel()
            || !lmpInvisibleDimensionDoorTeleport()
            || !lmpCuresDoubleStrength()
            || !lmpSourceCellsUnchanged()
            || !lmpFloorConstsStaySnapshots()
            || !lmpNoGapBoxesFlip()
        )
            ++bad;
        // the xpValue formula (the level VIII base plus per-hp)
    if (lmpStatXpValue() != lmpStatXp() + lmpStatAvgHp() * lmpStatXpPerHp()
        )
            ++bad;
        // the registry arithmetic (one def promoted)
    if (lmpRegistryAfter() != lmpRegistryBefore() + 1
            || lmpMm2DefsAfter() != lmpMm2DefsBefore() + 1
            || lmpRegistryAfter() != 810
        )
            ++bad;
        // the hit dice arithmetic
    if (lmpStatHitDice() + lmpStatHitDiceBonus() != 19
            || lmpStatAvgHp() != 61
            || lmpStatNumAttacks() != 2
        )
            ++bad;
        // the walk-key rewire (the 2 cells)
    if (lmpWalkKeyRowsAfter() != lmpWalkKeyRowsBefore() +
        lmpCellsRewired() + ffpOutCellsRewired() +
        ffsOutCellsRewired() + fftOutCellsRewired()
            || lmpWalkKeyRowsAfter() != 645
        )
            ++bad;
        // the rewired cell grids
    if (lmpGridTC5Index() != 22
            || lmpGridRC2Index() != 31
            || lmpCellsRewired() != 2
        )
            ++bad;
        // the stat block cells
    if (lmpPrintPage() != 79
            || lmpStatArmorClass() != 3
            || lmpStatMagicResistance() != 40
        )
            ++bad;
        // the doctrine cells (the holy word, the protection radius)
    if (lmpHolyWordPct() != 50
            || lmpProtectionRadius() != 20
            || lmpPrideSize() != 6
        )
            ++bad;
        // the spell ability
    if (lmpClericalSpellLevel() != 5
            || lmpSpellAbilityLevel() != 12
        )
            ++bad;
        printf("R820 lammasu promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
