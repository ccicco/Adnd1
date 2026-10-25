    // ---- R303: the thief pockets seam audit ----
    // The street-site seams: the victim cut
    // fold (the potential victim reduces the
    // chance 5 percent per level above the
    // 3rd - the cut may drive the chance below
    // zero) and the printed notice band (a
    // failed score 21 percent or more above
    // the chance means the victim notices).
    // The printed worked example walks live: the
    // 12th level half-elf (race 4) with 18
    // dexterity reads the printed 120 percent,
    // cut to 75 by a 12th level victim, and
    // reads noticed from 96.
    {
        int bad = 0;
        // the printed worked example: the 1200
        // tenths chance cut to 750
        if (rules::thfPocketsChanceTenths(12, 4, 18, 12)
            != 750) ++bad;
        // no cut at the 3rd, the printed -5 at
        // the 4th
        if (rules::thfPocketsChanceTenths(12, 4, 18, 3)
            != 1200) ++bad;
        if (rules::thfPocketsChanceTenths(12, 4, 18, 4)
            != 1150) ++bad;
        // the cut may cross zero: the level 1
        // human dex 9 base 150 reads -200
        // against a 10th level victim
        if (rules::thfPocketsChanceTenths(1, 0, 9, 10)
            != -200) ++bad;
        // the notice band: the printed 75 chance
        // reads noticed from 96 (95 does not)
        if (rules::thfPocketsVictimNotices(959, 750) ||
            !rules::thfPocketsVictimNotices(960, 750)
            ) ++bad;
        // a plain fail inside the band stays
        // quiet; the negative chance reads
        // noticed from 10 (9 does not)
        if (rules::thfPocketsVictimNotices(755, 750) ||
            !rules::thfPocketsVictimNotices(10, -200) ||
            rules::thfPocketsVictimNotices(9, -200)
            ) ++bad;
        printf("R303a thief pockets seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
