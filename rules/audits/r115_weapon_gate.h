    // ---- R115: magic weapon gate audit ----
    {
        int bad = 0;
        // the book's gate (p.76): a defender struck only
        // by +N weapons is hit by +N or better - pinned
        // so no refactor can flip the convention
        if (!rules::weaponSufficient(0, 0)) ++bad;
        if (rules::weaponSufficient(1, 0)) ++bad;
        if (!rules::weaponSufficient(1, 1)) ++bad;
        if (rules::weaponSufficient(2, 1)) ++bad;
        if (!rules::weaponSufficient(2, 2)) ++bad;
        if (rules::weaponSufficient(3, 2)) ++bad;
        if (!rules::weaponSufficient(3, 3)) ++bad;
        if (rules::weaponSufficient(4, 3)) ++bad;
        if (!rules::weaponSufficient(4, 4)) ++bad;
        printf("R115 magic weapon gate audit: bad %d\n", bad);
        if (bad) return 1;
    }
