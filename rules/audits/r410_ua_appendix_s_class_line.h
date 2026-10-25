    // ---- R410: the UA Appendix S
    // class lines pin audit ----
    // The 23 blocks x 6 lines pin;
    // the Nil census counts (29);
    // the psionic census re-derives
    // the R406 rating census; all
    // 23 psionic lines cross-check
    // the R406 rating codes live
    // (the Brandobaris missing line
    // the recorded sentinel); census
    // 336 -> 337.
    {
        using namespace rules;
        int bad = 0;
        // ---- the census ----
        if (uasclBlockCount() != 23)
            ++bad;
        if (uasclNilCount() != 29) ++bad;
        if (uasclPsnCount(UASCL_PSN_VI) != 10
                || uasclPsnCount(UASCL_PSN_III) != 5
                || uasclPsnCount(UASCL_PSN_IV) != 1
                || uasclPsnCount(UASCL_PSN_NILRC) != 6
                || uasclPsnCount(UASCL_PSN_MISSING) != 1) ++bad;
        if (uasclLines(0).cd.kind != 1
                || uasclLines(0).cd.a != 12
                || strcmp(uasclLines(0).cd.read,
                   "12th level druid") != 0) ++bad;
        if (uasclLines(2).cd.kind != 2
                || uasclLines(2).cd.a != 15
                || uasclLines(2).cd.b != 14
                || strcmp(uasclLines(2).cd.read,
                   "15th level cleric/14th level druid") != 0) ++bad;
        if (uasclLines(2).mu.kind != 4
                || uasclLines(2).mu.a != 14
                || strcmp(uasclLines(2).mu.read,
                   "Special/14th level illusionist") != 0) ++bad;
        if (uasclLines(3).ta.kind != 2
                || uasclLines(3).ta.a != 20
                || uasclLines(3).ta.b != 15
                || strcmp(uasclLines(3).ta.read,
                   "20th level thief/15th level assassin") != 0) ++bad;
        if (uasclLines(4).cd.kind != 2
                || uasclLines(4).cd.a != 15
                || uasclLines(4).cd.b != 12
                || strcmp(uasclLines(4).cd.read,
                   "15th level cleric/12th level druid") != 0) ++bad;
        if (uasclLines(5).f.kind != 1
                || uasclLines(5).f.a != 10
                || strcmp(uasclLines(5).f.read,
                   "10th level fighter") != 0) ++bad;
        if (uasclLines(5).mu.kind != 4
                || uasclLines(5).mu.a != 0
                || strcmp(uasclLines(5).mu.read,
                   "Special/Nil") != 0) ++bad;
        if (uasclLines(8).cd.kind != 2
                || uasclLines(8).cd.a != 14
                || uasclLines(8).cd.b != 10
                || strcmp(uasclLines(8).cd.read,
                   "14th level cleric/10th level druid") != 0) ++bad;
        if (uasclLines(8).mu.kind != 2
                || uasclLines(8).mu.a != 16
                || uasclLines(8).mu.b != 15
                || strcmp(uasclLines(8).mu.read,
                   "16th level m-u/15th level illusionist") != 0) ++bad;
        if (uasclLines(9).mu.kind != 2
                || uasclLines(9).mu.a != 18
                || uasclLines(9).mu.b != 16
                || strcmp(uasclLines(9).mu.read,
                   "18th level m-u/16th level illusionist") != 0) ++bad;
        if (uasclLines(12).f.kind != 1
                || uasclLines(12).f.a != 10
                || strcmp(uasclLines(12).f.read,
                   "10th level paladin") != 0) ++bad;
        if (uasclLines(12).mu.kind != 3
                || uasclLines(12).mu.a != 8
                || strcmp(uasclLines(12).mu.read,
                   "8th level in each") != 0) ++bad;
        if (uasclLines(15).f.kind != 1
                || uasclLines(15).f.a != 10
                || strcmp(uasclLines(15).f.read,
                   "10th level fighter") != 0) ++bad;
        if (uasclLines(16).mu.kind != 3
                || uasclLines(16).mu.a != 16
                || strcmp(uasclLines(16).mu.read,
                   "16th level in each") != 0) ++bad;
        if (uasclLines(17).cd.kind != 3
                || uasclLines(17).cd.a != 8
                || strcmp(uasclLines(17).cd.read,
                   "8th level in each") != 0) ++bad;
        if (uasclLines(18).f.kind != 5
                || uasclLines(18).f.a != 16
                || strcmp(uasclLines(18).f.read,
                   "As 16-HD monster") != 0) ++bad;
        if (uasclLines(19).f.kind != 5
                || uasclLines(19).f.a != 10
                || strcmp(uasclLines(19).f.read,
                   "As 10 HD monster") != 0) ++bad;
        if (uasclLines(19).ta.kind != 2
                || uasclLines(19).ta.a != 16
                || uasclLines(19).ta.b != 15
                || strcmp(uasclLines(19).ta.read,
                   "16th level thief/15th level assassin") != 0) ++bad;
        if (uasclLines(20).f.kind != 5
                || uasclLines(20).f.a != 15
                || strcmp(uasclLines(20).f.read,
                   "As 15 HD monster") != 0) ++bad;
        if (uasclLines(21).cd.kind != 1
                || uasclLines(21).cd.a != 15
                || strcmp(uasclLines(21).cd.read,
                   "15th level cleric (destructive spells only)") != 0) ++bad;
        if (uasclLines(21).mu.kind != 6
                || strcmp(uasclLines(21).mu.read,
                   "See below/Nil") != 0) ++bad;
        if (uasclLines(22).mu.kind != 3
                || uasclLines(22).mu.a != 12
                || strcmp(uasclLines(22).mu.read,
                   "12th level in each") != 0) ++bad;
        if (uasclLines(22).ta.kind != 3
                || uasclLines(22).ta.a != 6
                || strcmp(uasclLines(22).ta.read,
                   "6th level in each") != 0) ++bad;
        // ---- the psionic
        // cross-checks (R406 live) ----
        if (strcmp(uasclLines(0).psn.read,
                   "VI") != 0
                || uasclLines(0).psn.kind != 0
                || uasStat(0).rating != 0) ++bad;
        if (strcmp(uasclLines(1).psn.read,
                   "III") != 0
                || uasclLines(1).psn.kind != 1
                || uasStat(1).rating != 1) ++bad;
        if (strcmp(uasclLines(2).psn.read,
                   "VI") != 0
                || uasclLines(2).psn.kind != 0
                || uasStat(2).rating != 0) ++bad;
        if (strcmp(uasclLines(3).psn.read,
                   "III") != 0
                || uasclLines(3).psn.kind != 1
                || uasStat(3).rating != 1) ++bad;
        if (strcmp(uasclLines(4).psn.read,
                   "III") != 0
                || uasclLines(4).psn.kind != 1
                || uasStat(4).rating != 1) ++bad;
        if (strcmp(uasclLines(5).psn.read,
                   "VI") != 0
                || uasclLines(5).psn.kind != 0
                || uasStat(5).rating != 0) ++bad;
        if (strcmp(uasclLines(6).psn.read,
                   "III") != 0
                || uasclLines(6).psn.kind != 1
                || uasStat(6).rating != 1) ++bad;
        if (strcmp(uasclLines(7).psn.read,
                   "VI") != 0
                || uasclLines(7).psn.kind != 0
                || uasStat(7).rating != 0) ++bad;
        if (strcmp(uasclLines(8).psn.read,
                   "VI") != 0
                || uasclLines(8).psn.kind != 0
                || uasStat(8).rating != 0) ++bad;
        if (strcmp(uasclLines(9).psn.read,
                   "VI") != 0
                || uasclLines(9).psn.kind != 0
                || uasStat(9).rating != 0) ++bad;
        if (strcmp(uasclLines(10).psn.read,
                   "Nil") != 0
                || uasclLines(10).psn.kind != 3
                || uasStat(10).rating != 3) ++bad;
        if (strcmp(uasclLines(11).psn.read,
                   "Nil") != 0
                || uasclLines(11).psn.kind != 3
                || uasStat(11).rating != 3) ++bad;
        if (strcmp(uasclLines(12).psn.read,
                   "Nil") != 0
                || uasclLines(12).psn.kind != 3
                || uasStat(12).rating != 3) ++bad;
        if (strcmp(uasclLines(13).psn.read,
                   "none") != 0
                || uasclLines(13).psn.kind != -1
                || uasStat(13).rating != -1) ++bad;
        if (strcmp(uasclLines(14).psn.read,
                   "III") != 0
                || uasclLines(14).psn.kind != 1
                || uasStat(14).rating != 1) ++bad;
        if (strcmp(uasclLines(15).psn.read,
                   "VI") != 0
                || uasclLines(15).psn.kind != 0
                || uasStat(15).rating != 0) ++bad;
        if (strcmp(uasclLines(16).psn.read,
                   "VI") != 0
                || uasclLines(16).psn.kind != 0
                || uasStat(16).rating != 0) ++bad;
        if (strcmp(uasclLines(17).psn.read,
                   "VI") != 0
                || uasclLines(17).psn.kind != 0
                || uasStat(17).rating != 0) ++bad;
        if (strcmp(uasclLines(18).psn.read,
                   "Nil") != 0
                || uasclLines(18).psn.kind != 3
                || uasStat(18).rating != 3) ++bad;
        if (strcmp(uasclLines(19).psn.read,
                   "IV") != 0
                || uasclLines(19).psn.kind != 2
                || uasStat(19).rating != 2) ++bad;
        if (strcmp(uasclLines(20).psn.read,
                   "Nil") != 0
                || uasclLines(20).psn.kind != 3
                || uasStat(20).rating != 3) ++bad;
        if (strcmp(uasclLines(21).psn.read,
                   "VI") != 0
                || uasclLines(21).psn.kind != 0
                || uasStat(21).rating != 0) ++bad;
        if (strcmp(uasclLines(22).psn.read,
                   "Nil") != 0
                || uasclLines(22).psn.kind != 3
                || uasStat(22).rating != 3) ++bad;
        printf("R410 UA appendix S class lines pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
