    // ---- R781 set spear and speed seam audit ----
    // THE SET SPEAR AND THE SPEED SEAM - three feeds in one round. (1) The
    // R189 chart's set-spear asterisk meets its charging FOE at last: the S
    // command plants the stance (round one + a spear - the stance CONSUMES
    // the round), and the closing monster blow answers to the counterstrike
    // FIRST - the receive multiplier doubles that one blow, the flag clears
    // after it (the JUDGMENT: the monster's round-one melee reads as the
    // charge, the R232 surprise pattern again). (2) The DMG p.66 speed cases
    // leave contract-side: the R158 name-keyed ladder gains its engine
    // callers in the round scheduler - case 1 the tie orders the blows (the
    // lower factor first, a +1 shift on the slower side), case 2 the
    // extra-attack window opens after round one (the before-count minus one
    // rides the +5 routine spacing - the JUDGMENT; the closing charge exempts
    // it, speedFactorApplies), case 3 the weapon-vs-spell segment (the factor
    // minus the losing die, negatives positive, clamped 1..10). The cases
    // read each side's FRONT melee actor - no reach layer exists (the
    // JUDGMENT); missile weapons carry no factor (the R158 print) and read
    // unknown. (3) The R779 zero-row JUDGMENT is STRUCK: the 1eonline.info
    // compilation (the repo-trusted source the R189 duty already reads)
    // carries the full lance vs-AC rows - light -3..0, medium -1..+1, heavy
    // +4..0 - and the R145 audit kRows pin them cell for cell (19 x 11 = 209
    // pins). Honest boundaries: the printed lengths and space-required cells
    // still ride no engine concept, and the spear keeps its R158 default 7 on
    // this seam
    {
        using namespace rules;
        int bad = 0;
    if (spsSetFeederRound() != 189
            || spsSpearSetRound() != 781
            || spsAcFeederRound() != 145
            || spsSpeedPage() != 66
            || spsSetDamageMultiplier() != 2
            || spsLanceAcRowCount() != 3
            || !spsSpearSetReceivesTheClosingFoe()
            || !spsTheStanceConsumesTheRound()
            || !spsLanceAcCellsRideTheCompilation()
            || !spsTieReadsTheSpeedLadder()
            || !spsWeaponVsSpellReadsTheSegment()
            || !spsExtraAttacksOpenAfterRoundOne()
            || !spsMissileWeaponsCarryNoFactor()
        )
            ++bad;
        printf("R781 set spear and speed seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
