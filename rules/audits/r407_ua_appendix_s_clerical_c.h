    // ---- R407: the UA Appendix S
    // clerical charts pin audit ----
    // The second data round rides
    // the R405 seam: the five
    // 8-column charts pin their 23
    // rows (sphere, raiment, colors,
    // holy days, the sacrifice
    // frequency and form), the 13
    // named sacred animals pin, the
    // cleric gender reads pin, and
    // the frequency counts (monthly
    // 10, annually 4, before battle
    // 2) catch any cell drift; the
    // pantheon prose stays open;
    // census 333 -> 334.
    {
        using namespace rules;
        int bad = 0;
        // ---- the census ----
        if (uscChartRowCount() != 23) ++bad;
        if (uscChartRowCount()
                != uasDeityCount()) ++bad;
        if (uscChartCount() != 5)
            ++bad;
        if (uscChartCount()
                != nhdChartCount()) ++bad;
        // ---- the spot checks ----
        // Clanggedin (the first row)
        if (strcmp(uscChartRow(0).name,
                   "Clanggedin") != 0)
            ++bad;
        if (strcmp(uscChartRow(0).sphere,
                   "war, battle") != 0)
            ++bad;
        if (strcmp(uscChartRow(0).head,
                   "war helm") != 0) ++bad;
        if (strcmp(uscChartRow(0).form,
                   "weapons") != 0) ++bad;
        // Berronar: the new-year day
        if (strcmp(uscChartRow(4).days,
                   "new year's day") != 0)
            ++bad;
        // Aerdrie: the equinoxes
        if (strcmp(uscChartRow(5).days,
                   "spring & fall equinoxes")
                != 0)
            ++bad;
        // Solonor: the elfin chain
        if (strcmp(uscChartRow(7).body,
                   "elfin chain & silver")
                != 0)
            ++bad;
        // Sheela: the seeds
        if (strcmp(uscChartRow(10).form,
                   "seeds") != 0) ++bad;
        // Brandobaris: the stolen items
        if (strcmp(uscChartRow(13).form,
                   "stolen items") != 0) ++bad;
        // Segojan: the season days
        if (strcmp(uscChartRow(16).days,
                   "first day of each season")
                != 0)
            ++bad;
        if (strcmp(uscChartRow(16).freq,
                   "quarterly") != 0) ++bad;
        // Flandal: the forged weapons
        if (strcmp(uscChartRow(17).form,
                   "forged weapons") != 0)
            ++bad;
        // Bahgtru: the n/a color
        if (strcmp(uscChartRow(18).color,
                   "n/a") != 0) ++bad;
        if (strcmp(uscChartRow(18).form,
                   "bones of enemies") != 0)
            ++bad;
        // Ilneval: the two-sided days
        if (strcmp(uscChartRow(20).freq,
                   "before & after battle")
                != 0)
            ++bad;
        // Luthic: the cave goddess
        if (strcmp(uscChartRow(22).sphere,
                   "caves, healing, females")
                != 0)
            ++bad;
        if (strcmp(uscChartRow(22).freq,
                   "yearly") != 0) ++bad;
        if (strcmp(uscChartRow(22).form,
                   "treasures") != 0) ++bad;
        // ---- the sacred animals ----
        if (uscNamedSacredAnimalCount()
                != 13) ++bad;
        // the dwarven no-animal read:
        // all five null
        if (uscSacredAnimal(0) != 0
                || uscSacredAnimal(1) != 0
                || uscSacredAnimal(2) != 0
                || uscSacredAnimal(3) != 0
                || uscSacredAnimal(4) != 0)
            ++bad;
        if (strcmp(uscSacredAnimal(5),
                   "any bird") != 0) ++bad;
        if (strcmp(uscSacredAnimal(7),
                   "stag") != 0) ++bad;
        if (strcmp(uscSacredAnimal(10),
                   "butterfly") != 0) ++bad;
        if (strcmp(uscSacredAnimal(11),
                   "war dog") != 0) ++bad;
        if (strcmp(uscSacredAnimal(12),
                   "squirrel") != 0) ++bad;
        if (strcmp(uscSacredAnimal(13),
                   "mouse") != 0) ++bad;
        if (strcmp(uscSacredAnimal(14),
                   "raccoon") != 0) ++bad;
        if (strcmp(uscSacredAnimal(15),
                   "white mole") != 0) ++bad;
        if (strcmp(uscSacredAnimal(16),
                   "badger") != 0) ++bad;
        if (uscSacredAnimal(17) != 0) ++bad;
        if (strcmp(uscSacredAnimal(18),
                   "ox") != 0) ++bad;
        if (strcmp(uscSacredAnimal(19),
                   "bat") != 0) ++bad;
        if (uscSacredAnimal(20) != 0) ++bad;
        if (strcmp(uscSacredAnimal(21),
                   "skeleton") != 0) ++bad;
        if (strcmp(uscSacredAnimal(22),
                   "cave bear") != 0) ++bad;
        // ---- the cleric gender reads ----
        if (!uscDwarfClericGenderSplit()) ++bad;
        if (!uscElfClericsEitherGender()) ++bad;
        if (!uscHalflingClericsEitherGender())
            ++bad;
        if (!uscGnomeClericsNeverDruids()) ++bad;
        if (!uscGnomishClericsAllMale()) ++bad;
        // ---- the frequency drift catch ----
        if (uscFrequencyCount("monthly") != 10)
            ++bad;
        if (uscFrequencyCount("annually") != 4)
            ++bad;
        if (uscFrequencyCount(
                "before battle") != 2) ++bad;
        if (uscFrequencyCount("quarterly")
                != 1)
            ++bad;
        printf("R407 UA appendix S clerical charts pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
