    // ---- R404: the psionics seam
    // audit ----
    // The deferred seam lands: the
    // layer contract (no psionic site;
    // the pins precede the charge; the
    // seam gates the psionic
    // expansions), the open and OUT
    // records (the PHB sections OPEN;
    // the DMG p.77 combat OUT), the
    // UA pp. 10-11 pins (the duergar
    // doubled chance, the svirfneblin
    // PC ban) and the live
    // cross-checks of the three
    // feeders - R166 the insanity seam,
    // R323 the subrace layer, R328 the
    // cavalier mind powers; census
    // 330 -> 331.
    {
        using namespace rules;
        int bad = 0;
        // ---- the layer contract ----
        if (psxPsionicSiteExists()) ++bad;
        if (!psxPinsPrecedeCharge()) ++bad;
        if (!psxGatesPsionicExpansions()) ++bad;
        if (!psxPsionicChargeOpen()) ++bad;
        // ---- the open and OUT records ----
        if (!psxPhbSectionsOpen()) ++bad;
        if (psxDmgPsionicCombatPage() != 77)
            ++bad;
        if (!psxDmgCombatOutOfScope()) ++bad;
        // ---- the duergar pin ----
        if (!psxDuergarNotAllPsionic()) ++bad;
        if (psxDuergarChanceMultiple() != 2)
            ++bad;
        if (!psxDuergarDoublesIntWisCha()) ++bad;
        if (!psxDuergarDoubledOnlyIfUsed()) ++bad;
        // the doubled bonus arithmetic:
        // every usual bonus doubles
        if (psxDuergarDoubledBonus(1) != 2
                || psxDuergarDoubledBonus(
                    5) != 10
                || psxDuergarDoubledBonus(
                    10) != 20)
            ++bad;
        if (psxDuergarDoubledBonus(0) != 0) ++bad;
        // ---- the svirfneblin pin ----
        if (!psxSvirfneblinPcNoPsionics()) ++bad;
        // ---- the feeder registry ----
        if (psxFeederSeamCount() != 3) ++bad;
        if (psxFeederRound(0) != 166
                || psxFeederRound(1) != 323
                || psxFeederRound(2) != 328)
            ++bad;
        // ---- the R166 insanity seam ----
        // the four MILD forms (1-4) are
        // subject to psionic attack;
        // 5+ are not
        for (int i = 1; i <= 4; ++i)
            if (!insanityIsMild(i)) ++bad;
        if (insanityIsMild(0)
                || insanityIsMild(5)
                || insanityIsMild(20)) ++bad;
        // the duration classes ride the
        // psionic section (2-12 temporary,
        // 1-4 mild)
        if (insanityTemporaryWeeksMin() != 2
                || insanityTemporaryWeeksMax()
                    != 12)
            ++bad;
        if (insanityMildWeeksMin() != 1
                || insanityMildWeeksMax() != 4)
            ++bad;
        // ---- the R323 subrace seam ----
        // the svirfneblin PC ban rides the
        // trait table; the duergar row
        // carries no ban (the not-all
        // read)
        if (subraceTraits(SUB_GNOME_DEEP)
                .noPsionics != 1) ++bad;
        if (subraceTraits(SUB_DWARF_GRAY)
                .noPsionics != 0) ++bad;
        // ---- the R328 cavalier seam ----
        if (cavalierMindAffectResistPercent()
                != 90) ++bad;
        if (strcmp(cavalierMindPowerName(9),
                   "psionic mind blast") != 0)
            ++bad;
        printf("R404 psionics seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
