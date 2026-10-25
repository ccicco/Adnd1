    // ---- R373: the UA comeliness
    // note pin audit ----
    // The UA comeliness creation
    // note (p. 74): the DM
    // pointer - the attribute fully
    // described on pages 6 and 7
    // of this volume, while it
    // might more properly be
    // called a characteristic, it
    // does have effects in game
    // terms upon those viewing or
    // reacting to the character.
    // The item rides the R322
    // pins; the weapon descriptions
    // item rides the R340 pins. The
    // R322 seam cross-checks the
    // creation roll and the charisma
    // ladder; the R340 seam the
    // 16-entry roster with the 14
    // item-list types; the R337
    // seam the pole-arm rows; two
    // items flip CLOSED; the census
    // 299 -> 300.
    {
        using namespace rules;
        int bad = 0;
        // ---- the note pins ----
            if (uacmPointerFirstPage() != 6)
                ++bad;
            if (uacmPointerSecondPage() != 7)
                ++bad;
            if (!uacmFullyDescribedOnPointerPages())
                ++bad;
            if (!uacmMoreProperlyCharacteristic())
                ++bad;
            if (!uacmAffectsViewers()) ++bad;
            if (!uacmAffectsReactors()) ++bad;
            if (!uacmShownAboveForHumans())
                ++bad;
            if (!uacmTrailingSentenceGarbles())
                ++bad;
        // ---- the R322 seam ----
            // the creation roll and the
            // charisma ladder the note
            // rides
            if (uaComelinessBaseDieCount() != 3)
                ++bad;
            if (uaComelinessBaseDieSides() != 6)
                ++bad;
            if (uaComelinessChaAdj(2) != -8)
                ++bad;
            if (uaComelinessChaAdj(3) != -5)
                ++bad;
            if (uaComelinessChaAdj(4) != -3)
                ++bad;
            if (uaComelinessChaAdj(8) != -1)
                ++bad;
            if (uaComelinessChaAdj(9) != 0)
                ++bad;
            if (uaComelinessChaAdj(15) != 1)
                ++bad;
            if (uaComelinessChaAdj(16) != 2)
                ++bad;
            if (uaComelinessChaAdj(17) != 2)
                ++bad;
            if (uaComelinessChaAdj(18) != 3)
                ++bad;
            if (uaComelinessChaAdj(19) != 5)
                ++bad;
            if (uaComelinessBand(-16) != 0)
                ++bad;
            if (uaComelinessBand(-9) != 1)
                ++bad;
            if (uaComelinessBand(0) != 2)
                ++bad;
            if (uaComelinessBand(30) != 9)
                ++bad;
        // ---- the R340 seam ----
            // the 16-entry roster with
            // the 14 item-list types
            if (uanwCount() != 16) ++bad;
            int inList = 0;
            for (int i = 0; i < 16; ++i)
                if (uanwInGapItemList(i))
                    ++inList;
            if (inList != 14) ++bad;
            if (strcmp(uanwName(0), "Aklys") != 0)
                ++bad;
            if (strcmp(uanwName(4),
                    "Crossbow, Hand-held") != 0)
                ++bad;
            if (strcmp(uanwName(13),
                    "Sword, Falchion") != 0) ++bad;
            if (strcmp(uanwName(15), "Whip") != 0)
                ++bad;
            if (uanwHookFauchardDismountPct()
                    != 20) ++bad;
            if (uanwManCatcherPoleCuttingDmg()
                    != 6) ++bad;
            if (!uanwStaffSlingMediumOrLongOnly())
                ++bad;
        // ---- the R337 seam ----
            // the pole-arm cross-refs
            // ride the data rows
            {
                bool hook = false, mc = false,
                     lasso = false, harp = false;
                int n = uawtRowCount();
                for (int i = 0; i < n; ++i) {
                    const char* w = uawtName(i);
                    if (strcmp(w,
                            "Hook Fauchard") == 0)
                        hook = true;
                    if (strcmp(w,
                            "Man Catcher") == 0)
                        mc = true;
                    if (strcmp(w, "Lasso") == 0)
                        lasso = true;
                    if (strcmp(w, "Harpoon") == 0)
                        harp = true;
                }
                if (!hook || !mc || !lasso || !harp)
                    ++bad;
            }
        printf("R373 UA comeliness note pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
