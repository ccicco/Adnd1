    // ---- R405: the deity layer seam
    // audit ----
    // The last in-scope seam lands: the
    // layer contract (the deity site is
    // the R782 bridge; the pins precede
    // the site; the seam gates the
    // Appendix S charge; the R782 bridge
    // closes the stat-block charge), the
    // source
    // pins (Appendix S pp. 109-122,
    // Moradin in Legends & Lore at 20
    // feet), the census (23 deities, 5
    // pantheons 5/5/4/4/5, the tiers
    // 5/16/2, the ratings VI 10 III 5
    // IV 1 Nil 6 + Brandobaris
    // unrecorded), the dwarven reads
    // (twice normal size, no living
    // symbols, dual charismas, the -4
    // giant penalty), the five 8-column
    // charts, and the live cross-checks
    // of the four feeders - R169 the
    // humanoid matrix, R322 the
    // comeliness bands, R323 the
    // subrace parents, R404 the psx
    // pins; census 331 -> 332.
    {
        using namespace rules;
        int bad = 0;
        // ---- the layer contract ----
        // R782 STRUCK: the site exists (the bridge) and
        // the stat-block charge closes with it
        if (!nhdDeitySiteExists()) ++bad;
        if (!nhdPinsPrecedeSite()) ++bad;
        if (!nhdGatesAppendixS()) ++bad;
        if (nhdStatBlocksOpen()) ++bad;
        // ---- the source pins ----
        if (nhdAppendixPageFirst() != 109)
            ++bad;
        if (nhdAppendixPageLast() != 122)
            ++bad;
        if (!nhdMoradinInLegendsLore()) ++bad;
        if (nhdMoradinHeightFeet() != 20)
            ++bad;
        // ---- the census pins ----
        if (nhdDeityCount() != 23) ++bad;
        if (nhdPantheonCount() != 5) ++bad;
        // the pantheon sizes: 5/5/4/4/5
        if (nhdPantheonSize(0) != 5
                || nhdPantheonSize(1) != 5
                || nhdPantheonSize(2) != 4
                || nhdPantheonSize(3) != 4
                || nhdPantheonSize(4) != 5)
            ++bad;
        // the pantheons add up to the census
        if (nhdPantheonSize(0)
                + nhdPantheonSize(1)
                + nhdPantheonSize(2)
                + nhdPantheonSize(3)
                + nhdPantheonSize(4)
                != nhdDeityCount()) ++bad;
        // the tiers: 5 greater, 16 lesser,
        // 2 demigods - and they add up
        if (nhdGreaterDeityCount() != 5
                || nhdLesserDeityCount() != 16
                || nhdDemigodCount() != 2)
            ++bad;
        if (nhdGreaterDeityCount()
                + nhdLesserDeityCount()
                + nhdDemigodCount()
                != nhdDeityCount()) ++bad;
        // the ratings: VI 10, III 5, IV 1,
        // Nil 6 - and with Brandobaris
        // unrecorded they add up
        if (nhdPsionicRatingCount(0) != 10
                || nhdPsionicRatingCount(1)
                    != 5
                || nhdPsionicRatingCount(2)
                    != 1
                || nhdPsionicRatingCount(3)
                    != 6)
            ++bad;
        if (nhdPsionicRatingCount(0)
                + nhdPsionicRatingCount(1)
                + nhdPsionicRatingCount(2)
                + nhdPsionicRatingCount(3)
                + nhdRatingUnrecordedCount()
                != nhdDeityCount()) ++bad;
        // ---- the dwarven reads ----
        if (nhdGreaterDwarfSizeMultiple() != 2)
            ++bad;
        if (!nhdDwarfSymbolNeverLiving()) ++bad;
        if (!nhdDwarfDeityDualCharisma()) ++bad;
        if (nhdGiantTypeAttackPenalty() != 4)
            ++bad;
        // ---- the clerical charts ----
        if (nhdChartCount() != 5) ++bad;
        if (nhdChartColumnCount() != 8) ++bad;
        // the charts carry one row per
        // deity: 23 rows across the five
        if (nhdChartCount()
                != nhdPantheonCount()) ++bad;
        // ---- the feeder registry ----
        if (nhdFeederSeamCount() != 4) ++bad;
        if (nhdFeederRound(0) != 169
                || nhdFeederRound(1) != 322
                || nhdFeederRound(2) != 323
                || nhdFeederRound(3) != 404)
            ++bad;
        // ---- the R169 humanoid matrix ----
        // the nine-race matrix carries the
        // orc row but no elf column - the
        // Appendix S Gruumsh/Corellon read
        // is the sole cross-pantheon site
        if (humRPrefRaceCount() != 9) ++bad;
        if (humRPrefRaceIndex("orc") != 7)
            ++bad;
        if (humRPrefRaceIndex("elf") != -1)
            ++bad;
        // ---- the R322 comeliness seam ----
        // Clanggedin CM:13(20) - the dual
        // comeliness values ride the R322
        // bands (13 the band-5 side, 20 the
        // band-7 side at 150 percent)
        if (uaComelinessBand(13) != 5) ++bad;
        if (uaComelinessBand(20) != 7) ++bad;
        if (uaComelinessReactionPct(20)
                != 150) ++bad;
        // ---- the R323 subrace seam ----
        // the four demi-human pantheons map
        // to their subrace parents (orcs
        // carry no subrace)
        if (subraceParentRace(SUB_DWARF_GRAY)
                != RACE_DWARF) ++bad;
        if (subraceParentRace(SUB_ELF_HIGH)
                != RACE_ELF) ++bad;
        if (subraceParentRace(SUB_GNOME_DEEP)
                != RACE_GNOME) ++bad;
        if (subraceParentRace(
                SUB_HALFLING_HAIRFOOT)
                != RACE_HALFLING) ++bad;
        // ---- the R404 psionics seam ----
        // the PC psionic reads stay
        // PC-side: the duergar doubled
        // chance and the svirfneblin ban
        // (the deity ratings are the
        // Appendix S scale, not the PC
        // chance)
        if (psxDuergarChanceMultiple() != 2)
            ++bad;
        if (!psxSvirfneblinPcNoPsionics())
            ++bad;
        printf("R405 deity layer seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
