    // ---- R409: the UA Appendix S
    // stat lines pin audit ----
    // The 23 S/I/W/D/C/CH/CM rows
    // pin cell for cell; the R406
    // roster cross-checks name for
    // name; the R153 percentile
    // bands cross-check the 18/00
    // and 18/01 plusses live; the
    // DAMAGE/ATTACK mirror
    // cross-checks the damage
    // prints (the Bahgtru +15
    // divergence records); the R322
    // band ladder cross-checks the
    // printed CM extremes; the
    // Cyrrollalee plus pair stays
    // the recorded hole; census
    // 335 -> 336.
    {
        using namespace rules;
        int bad = 0;
        // ---- the census ----
        if (uaslLineCount() != 23) ++bad;
        // the exceptional rows: the
        // 18/00 pair, the 18/01
        if (uaslLine(10).pct != 100
                || uaslLine(14).pct != 100
                || uaslLine(16).pct != 1) ++bad;
        // the plain rows carry no
        // plusses (S:8, S:12, S:15)
        if (uaslLine(5).hit != 0
                || uaslLine(8).hit != 0
                || uaslLine(9).hit != 0
                || uaslLine(0).hit == 0)
            ++bad;
        // the Cyrrollalee hole
        if (uaslLine(12).hit != -1
                || uaslLine(12).dmg != -1) ++bad;
        if (uaslLine(0).str != 25
                || uaslLine(0).pct != 0
                || uaslLine(0).hit != 7
                || uaslLine(0).dmg != 14
                || uaslLine(0).intl != 20
                || uaslLine(0).wis != 19
                || uaslLine(0).dex != 20
                || uaslLine(0).con != 25
                || uaslLine(0).cha != 16
                || uaslLine(0).chaParen != 22
                || uaslLine(0).cm != 13
                || uaslLine(0).cmParen != 20) ++bad;
        if (uaslLine(1).str != 22
                || uaslLine(1).pct != 0
                || uaslLine(1).hit != 4
                || uaslLine(1).dmg != 10
                || uaslLine(1).intl != 23
                || uaslLine(1).wis != 20
                || uaslLine(1).dex != 23
                || uaslLine(1).con != 25
                || uaslLine(1).cha != 18
                || uaslLine(1).chaParen != 24
                || uaslLine(1).cm != 18
                || uaslLine(1).cmParen != 24) ++bad;
        if (uaslLine(2).str != 25
                || uaslLine(2).pct != 0
                || uaslLine(2).hit != 7
                || uaslLine(2).dmg != 14
                || uaslLine(2).intl != 23
                || uaslLine(2).wis != 25
                || uaslLine(2).dex != 20
                || uaslLine(2).con != 25
                || uaslLine(2).cha != 18
                || uaslLine(2).chaParen != 24
                || uaslLine(2).cm != 13
                || uaslLine(2).cmParen != 16) ++bad;
        if (uaslLine(3).str != 24
                || uaslLine(3).pct != 0
                || uaslLine(3).hit != 6
                || uaslLine(3).dmg != 12
                || uaslLine(3).intl != 22
                || uaslLine(3).wis != 16
                || uaslLine(3).dex != 24
                || uaslLine(3).con != 24
                || uaslLine(3).cha != 8
                || uaslLine(3).chaParen != 14
                || uaslLine(3).cm != 7
                || uaslLine(3).cmParen != 13) ++bad;
        if (uaslLine(4).str != 21
                || uaslLine(4).pct != 0
                || uaslLine(4).hit != 4
                || uaslLine(4).dmg != 9
                || uaslLine(4).intl != 25
                || uaslLine(4).wis != 25
                || uaslLine(4).dex != 20
                || uaslLine(4).con != 25
                || uaslLine(4).cha != 19
                || uaslLine(4).chaParen != 25
                || uaslLine(4).cm != 20
                || uaslLine(4).cmParen != 25) ++bad;
        if (uaslLine(5).str != 8
                || uaslLine(5).pct != 0
                || uaslLine(5).hit != 0
                || uaslLine(5).dmg != 0
                || uaslLine(5).intl != 24
                || uaslLine(5).wis != 22
                || uaslLine(5).dex != 24
                || uaslLine(5).con != 19
                || uaslLine(5).cha != 23
                || uaslLine(5).chaParen != 0
                || uaslLine(5).cm != 25
                || uaslLine(5).cmParen != 0) ++bad;
        if (uaslLine(6).str != 19
                || uaslLine(6).pct != 0
                || uaslLine(6).hit != 3
                || uaslLine(6).dmg != 7
                || uaslLine(6).intl != 23
                || uaslLine(6).wis != 16
                || uaslLine(6).dex != 25
                || uaslLine(6).con != 20
                || uaslLine(6).cha != 24
                || uaslLine(6).chaParen != 0
                || uaslLine(6).cm != 25
                || uaslLine(6).cmParen != 0) ++bad;
        if (uaslLine(7).str != 21
                || uaslLine(7).pct != 0
                || uaslLine(7).hit != 4
                || uaslLine(7).dmg != 9
                || uaslLine(7).intl != 22
                || uaslLine(7).wis != 21
                || uaslLine(7).dex != 25
                || uaslLine(7).con != 21
                || uaslLine(7).cha != 23
                || uaslLine(7).chaParen != 0
                || uaslLine(7).cm != 22
                || uaslLine(7).cmParen != 0) ++bad;
        if (uaslLine(8).str != 15
                || uaslLine(8).pct != 0
                || uaslLine(8).hit != 0
                || uaslLine(8).dmg != 0
                || uaslLine(8).intl != 23
                || uaslLine(8).wis != 23
                || uaslLine(8).dex != 25
                || uaslLine(8).con != 20
                || uaslLine(8).cha != 25
                || uaslLine(8).chaParen != -2
                || uaslLine(8).cm != 30
                || uaslLine(8).cmParen != 0) ++bad;
        if (uaslLine(9).str != 12
                || uaslLine(9).pct != 0
                || uaslLine(9).hit != 0
                || uaslLine(9).dmg != 0
                || uaslLine(9).intl != 25
                || uaslLine(9).wis != 25
                || uaslLine(9).dex != 19
                || uaslLine(9).con != 18
                || uaslLine(9).cha != 24
                || uaslLine(9).chaParen != 0
                || uaslLine(9).cm != 25
                || uaslLine(9).cmParen != 0) ++bad;
        if (uaslLine(10).str != 18
                || uaslLine(10).pct != 100
                || uaslLine(10).hit != 3
                || uaslLine(10).dmg != 6
                || uaslLine(10).intl != 22
                || uaslLine(10).wis != 25
                || uaslLine(10).dex != 22
                || uaslLine(10).con != 24
                || uaslLine(10).cha != 22
                || uaslLine(10).chaParen != 0
                || uaslLine(10).cm != 24
                || uaslLine(10).cmParen != 0) ++bad;
        if (uaslLine(11).str != 20
                || uaslLine(11).pct != 0
                || uaslLine(11).hit != 3
                || uaslLine(11).dmg != 8
                || uaslLine(11).intl != 21
                || uaslLine(11).wis != 23
                || uaslLine(11).dex != 24
                || uaslLine(11).con != 23
                || uaslLine(11).cha != 21
                || uaslLine(11).chaParen != 0
                || uaslLine(11).cm != 21
                || uaslLine(11).cmParen != 0) ++bad;
        if (uaslLine(12).str != 17
                || uaslLine(12).pct != 0
                || uaslLine(12).hit != -1
                || uaslLine(12).dmg != -1
                || uaslLine(12).intl != 23
                || uaslLine(12).wis != 24
                || uaslLine(12).dex != 24
                || uaslLine(12).con != 23
                || uaslLine(12).cha != 22
                || uaslLine(12).chaParen != 0
                || uaslLine(12).cm != 21
                || uaslLine(12).cmParen != 0) ++bad;
        if (uaslLine(13).str != 19
                || uaslLine(13).pct != 0
                || uaslLine(13).hit != 3
                || uaslLine(13).dmg != 7
                || uaslLine(13).intl != 24
                || uaslLine(13).wis != 17
                || uaslLine(13).dex != 25
                || uaslLine(13).con != 23
                || uaslLine(13).cha != 20
                || uaslLine(13).chaParen != 0
                || uaslLine(13).cm != 19
                || uaslLine(13).cmParen != 0) ++bad;
        if (uaslLine(14).str != 18
                || uaslLine(14).pct != 100
                || uaslLine(14).hit != 3
                || uaslLine(14).dmg != 6
                || uaslLine(14).intl != 21
                || uaslLine(14).wis != 19
                || uaslLine(14).dex != 25
                || uaslLine(14).con != 22
                || uaslLine(14).cha != 22
                || uaslLine(14).chaParen != 0
                || uaslLine(14).cm != 16
                || uaslLine(14).cmParen != 0) ++bad;
        if (uaslLine(15).str != 19
                || uaslLine(15).pct != 0
                || uaslLine(15).hit != 3
                || uaslLine(15).dmg != 7
                || uaslLine(15).intl != 20
                || uaslLine(15).wis != 14
                || uaslLine(15).dex != 20
                || uaslLine(15).con != 24
                || uaslLine(15).cha != 3
                || uaslLine(15).chaParen != 0
                || uaslLine(15).cm != -14
                || uaslLine(15).cmParen != 0) ++bad;
        if (uaslLine(16).str != 18
                || uaslLine(16).pct != 1
                || uaslLine(16).hit != 1
                || uaslLine(16).dmg != 3
                || uaslLine(16).intl != 22
                || uaslLine(16).wis != 23
                || uaslLine(16).dex != 18
                || uaslLine(16).con != 24
                || uaslLine(16).cha != 20
                || uaslLine(16).chaParen != 0
                || uaslLine(16).cm != 15
                || uaslLine(16).cmParen != 0) ++bad;
        if (uaslLine(17).str != 22
                || uaslLine(17).pct != 0
                || uaslLine(17).hit != 4
                || uaslLine(17).dmg != 10
                || uaslLine(17).intl != 18
                || uaslLine(17).wis != 20
                || uaslLine(17).dex != 17
                || uaslLine(17).con != 23
                || uaslLine(17).cha != 18
                || uaslLine(17).chaParen != 0
                || uaslLine(17).cm != 16
                || uaslLine(17).cmParen != 0) ++bad;
        if (uaslLine(18).str != 25
                || uaslLine(18).pct != 0
                || uaslLine(18).hit != 7
                || uaslLine(18).dmg != 14
                || uaslLine(18).intl != 6
                || uaslLine(18).wis != 6
                || uaslLine(18).dex != 18
                || uaslLine(18).con != 25
                || uaslLine(18).cha != 5
                || uaslLine(18).chaParen != 22
                || uaslLine(18).cm != -2
                || uaslLine(18).cmParen != 16) ++bad;
        if (uaslLine(19).str != 20
                || uaslLine(19).pct != 0
                || uaslLine(19).hit != 3
                || uaslLine(19).dmg != 8
                || uaslLine(19).intl != 19
                || uaslLine(19).wis != 15
                || uaslLine(19).dex != 24
                || uaslLine(19).con != 19
                || uaslLine(19).cha != 7
                || uaslLine(19).chaParen != 24
                || uaslLine(19).cm != 8
                || uaslLine(19).cmParen != 20) ++bad;
        if (uaslLine(20).str != 23
                || uaslLine(20).pct != 0
                || uaslLine(20).hit != 5
                || uaslLine(20).dmg != 11
                || uaslLine(20).intl != 17
                || uaslLine(20).wis != 14
                || uaslLine(20).dex != 20
                || uaslLine(20).con != 23
                || uaslLine(20).cha != 8
                || uaslLine(20).chaParen != 25
                || uaslLine(20).cm != 5
                || uaslLine(20).cmParen != 24) ++bad;
        if (uaslLine(21).str != 18
                || uaslLine(21).pct != 0
                || uaslLine(21).hit != 1
                || uaslLine(21).dmg != 2
                || uaslLine(21).intl != 18
                || uaslLine(21).wis != 11
                || uaslLine(21).dex != 10
                || uaslLine(21).con != 17
                || uaslLine(21).cha != -4
                || uaslLine(21).chaParen != 0
                || uaslLine(21).cm != -25
                || uaslLine(21).cmParen != 0) ++bad;
        if (uaslLine(22).str != 19
                || uaslLine(22).pct != 0
                || uaslLine(22).hit != 3
                || uaslLine(22).dmg != 7
                || uaslLine(22).intl != 18
                || uaslLine(22).wis != 19
                || uaslLine(22).dex != 14
                || uaslLine(22).con != 20
                || uaslLine(22).cha != 12
                || uaslLine(22).chaParen != 25
                || uaslLine(22).cm != 3
                || uaslLine(22).cmParen != 24) ++bad;
        // ---- the R406 roster ----
        // the names cross-check the
        // stat blocks name for name
        if (strcmp(uaslLine(0).name, uasStat(0).name)
                + strcmp(uaslLine(1).name, uasStat(1).name)
                + strcmp(uaslLine(2).name, uasStat(2).name)
                + strcmp(uaslLine(3).name, uasStat(3).name)
                + strcmp(uaslLine(4).name, uasStat(4).name)
                + strcmp(uaslLine(5).name, uasStat(5).name)
                + strcmp(uaslLine(6).name, uasStat(6).name)
                + strcmp(uaslLine(7).name, uasStat(7).name)
                + strcmp(uaslLine(8).name, uasStat(8).name)
                + strcmp(uaslLine(9).name, uasStat(9).name)
                + strcmp(uaslLine(10).name, uasStat(10).name)
                + strcmp(uaslLine(11).name, uasStat(11).name)
                != 0) ++bad;
        if (strcmp(uaslLine(12).name, uasStat(12).name)
                + strcmp(uaslLine(13).name, uasStat(13).name)
                + strcmp(uaslLine(14).name, uasStat(14).name)
                + strcmp(uaslLine(15).name, uasStat(15).name)
                + strcmp(uaslLine(16).name, uasStat(16).name)
                + strcmp(uaslLine(17).name, uasStat(17).name)
                + strcmp(uaslLine(18).name, uasStat(18).name)
                + strcmp(uaslLine(19).name, uasStat(19).name)
                + strcmp(uaslLine(20).name, uasStat(20).name)
                + strcmp(uaslLine(21).name, uasStat(21).name)
                + strcmp(uaslLine(22).name, uasStat(22).name)
                != 0) ++bad;
        // ---- the R153 percentile
        // bands (live) ----
        {
            ExceptionalStrength ex;
            ex.has = true;
            ex.pct = 100;
            if (ex.hitAdj() != uaslLine(10).hit
                    || ex.dmgAdj() != uaslLine(10).dmg
                    || ex.hitAdj() != uaslLine(14).hit
                    || ex.dmgAdj() != uaslLine(14).dmg) ++bad;
        }
        {
            ExceptionalStrength ex;
            ex.has = true;
            ex.pct = 1;
            if (ex.hitAdj() != uaslLine(16).hit
                    || ex.dmgAdj() != uaslLine(16).dmg) ++bad;
        }
        // ---- the damage mirror ----
        if (uaslDmgLineMirror(0) != uaslLine(0).dmg
                || uaslDmgLineMirror(1) != uaslLine(1).dmg
                || uaslDmgLineMirror(2) != uaslLine(2).dmg
                || uaslDmgLineMirror(3) != uaslLine(3).dmg
                || uaslDmgLineMirror(4) != uaslLine(4).dmg) ++bad;
        if (uaslDmgLineMirror(6) != uaslLine(6).dmg
                || uaslDmgLineMirror(10) != uaslLine(10).dmg
                || uaslDmgLineMirror(11) != uaslLine(11).dmg
                || uaslDmgLineMirror(13) != uaslLine(13).dmg
                || uaslDmgLineMirror(14) != uaslLine(14).dmg
                || uaslDmgLineMirror(15) != uaslLine(15).dmg
                || uaslDmgLineMirror(16) != uaslLine(16).dmg
                || uaslDmgLineMirror(17) != uaslLine(17).dmg
                || uaslDmgLineMirror(19) != uaslLine(19).dmg
                || uaslDmgLineMirror(20) != uaslLine(20).dmg
                || uaslDmgLineMirror(22) != uaslLine(22).dmg) ++bad;
        // the unprinted mirrors: the
        // Nil reads, "see below",
        // "by weapon type", the bare
        // ranges
        if (uaslDmgLineMirror(5) != 0
                || uaslDmgLineMirror(7) != 0
                || uaslDmgLineMirror(8) != 0
                || uaslDmgLineMirror(9) != 0
                || uaslDmgLineMirror(12) != 0
                || uaslDmgLineMirror(21) != 0) ++bad;
        // the Bahgtru divergence:
        // the damage line 15 against
        // the stat line 14 - the
        // recorded print divergence
        if (uaslDmgLineMirror(18) != 15
                || uaslLine(18).dmg != 14
                || !uaslBahgtruDmgDiverges())
            ++bad;
        // ---- the R322 band ladder
        // (live) ----
        // the printed CM extremes sit
        // in the comeliness bands: the
        // Hanali 30 atop unearthly,
        // the Yurtrus -25 repulsed,
        // the Urdlen -14 disgust, the
        // Clanggedin 13 plain
        if (uaComelinessBand(uaslLine(8).cm) != 9
                || uaComelinessBand(uaslLine(15).cm) != 1
                || uaComelinessBand(uaslLine(21).cm) != 0
                || uaComelinessBand(uaslLine(0).cm) != 5) ++bad;
        printf("R409 UA appendix S stat lines pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
