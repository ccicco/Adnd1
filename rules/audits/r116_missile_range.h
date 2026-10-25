    // ---- R116: missile range audit ----
    {
        int bad = 0;
        // the book's note (DMG p.75): missiles -2 at
        // medium range, -5 at long. Medium is twice the
        // registry's short range, long three times
        // (documented derivation); beyond long, no
        // shot is possible
        // helper sweep at short = 40' (the sling): the
        // short band is 0..40 (mod 0, in range)
        if (!rules::missileInRange(0, 40)) ++bad;
        if (!rules::missileInRange(40, 40)) ++bad;
        if (rules::missileRangeMod(0, 40) != 0) ++bad;
        if (rules::missileRangeMod(40, 40) != 0) ++bad;
        if (!rules::missileInRange(120, 40)) ++bad;
        if (rules::missileInRange(121, 40)) ++bad;
        if (rules::missileRangeMod(41, 40) != -2) ++bad;
        if (rules::missileRangeMod(80, 40) != -2) ++bad;
        if (rules::missileRangeMod(81, 40) != -5) ++bad;
        if (rules::missileRangeMod(120, 40) != -5) ++bad;
        if (rules::missileRangeMod(39, 40) != 0) ++bad;
        // the registry's missile weapons, pinned: sling
        // 40, short bow 50, long bow 70, crossbow 60
        if (items::weapon(items::WPN_SLING).rangeTens != 4)
            ++bad;
        if (items::weapon(items::WPN_SHORT_BOW).rangeTens != 5)
            ++bad;
        if (items::weapon(items::WPN_LONG_BOW).rangeTens != 7)
            ++bad;
        if (items::weapon(items::WPN_CROSSBOW_LIGHT).rangeTens
                != 6) ++bad;
        // the engagement's geometry (R43): 50' at the
        // opening band - the sling's first-round volley
        // is at medium (-2), the bows' at short (0)
        if (rules::missileRangeMod(50, 40) != -2) ++bad;
        if (rules::missileRangeMod(50, 50) != 0) ++bad;
        if (rules::missileRangeMod(50, 60) != 0) ++bad;
        if (rules::missileRangeMod(50, 70) != 0) ++bad;
        printf("R116 missile range audit: bad %d\n", bad);
        if (bad) return 1;
    }
