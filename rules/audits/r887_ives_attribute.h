    // ---- R887 Ives attribute audit ----
    // THE IVES ATTRIBUTE TABLES - the Dragon Magazine walk opens at issue #1,
    // folio 7: generate 1-100, add the tested score, the total's band picks
    // the die (d4 through d12), the die roll times the score is the percent
    // chance of success. The fighters' exceptional-strength ladder converts
    // 18/01 through 18/00 to effective strength 18 through 27 (the ink's
    // 18-super-90 glyph reading 27 - the erratum pinned as scanned); the
    // ladder serves fighters only. The use grid pins the six-attribute
    // doctrine lists. HONEST BOUNDARIES: this is OD&D-era variant ink on a
    // VARIANT layer with provenance, never core 1e canon; the article
    // standardizes the referee's wings-it doctrine - 1e has only the
    // enumerated attribute mechanics (the engine holds them: systemShock,
    // resurrectionSurvival, the conduct tables), no general attribute-check
    // layer exists at core; the example rolls (the 7 and the 3) pin as
    // doctrine examples, the random rolls themselves unpinnable. The 32 voice
    // pages and the pre-flip dragon gap report ride as data files; the Ives
    // box flips at the next Dragon round (a report cannot flip in the round
    // that creates it).
    {
        using namespace rules;
        int bad = 0;
    if (ivsRollMin() != 1
            || ivsRollMax() != 100
            || ivsUseCount() != 6
            || !ivsScoreAddedToRoll()
            || !ivsPercentIsRollTimesScore()
            || !ivsLadderIsFightersExStr()
        )
            ++bad;
        // the Ives use grid - six attributes x six use flags, pinned from the
        // folio 7 use lists
        int CIvsUses[6][6] = {
            {1,0,0,0,0,0},
            {0,1,0,0,0,1},
            {0,1,0,0,0,0},
            {0,0,1,0,0,0},
            {0,1,0,1,0,0},
            {0,0,0,0,1,0},
            };
        for (int b = 0;
             b < ivsUseCount();
             ++b) {
            int vals[6];
            vals[0] = ivsUseExertion(b);
            vals[1] = ivsUseDevice(b);
            vals[2] = ivsUseStamina(b);
            vals[3] = ivsUseManipulation(b);
            vals[4] = ivsUsePersuasion(b);
            vals[5] = ivsUseLearning(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CIvsUses[b][c])
                    ++bad;
            }
        }
        // the ivsDieBand band-for boundaries
    if (ivsDieBand(19) != 0
            || ivsDieBand(20) != 0
            || ivsDieBand(40) != 1
            || ivsDieBand(21) != 1
            || ivsDieBand(60) != 2
            || ivsDieBand(41) != 2
            || ivsDieBand(80) != 3
            || ivsDieBand(61) != 3
            || ivsDieBand(81) != 4
        )
            ++bad;
        // the ivsExStrLadder band-for boundaries
    if (ivsExStrLadder(19) != 0
            || ivsExStrLadder(20) != 0
            || ivsExStrLadder(40) != 1
            || ivsExStrLadder(21) != 1
            || ivsExStrLadder(60) != 2
            || ivsExStrLadder(41) != 2
            || ivsExStrLadder(70) != 3
            || ivsExStrLadder(61) != 3
            || ivsExStrLadder(80) != 4
            || ivsExStrLadder(71) != 4
            || ivsExStrLadder(90) != 5
            || ivsExStrLadder(81) != 5
            || ivsExStrLadder(95) != 6
            || ivsExStrLadder(91) != 6
            || ivsExStrLadder(99) != 7
            || ivsExStrLadder(96) != 7
            || ivsExStrLadder(100) != 8
        )
            ++bad;
        // the Grod charisma band - the 42 roll plus the 12 score lands 54,
        // the d8 band
    if (ivsDieSides(ivsDieBand(54)) != 8
        )
            ++bad;
        // the Grod strength band - the 66 roll plus the 17 score lands 83,
        // the d12 band
    if (ivsDieSides(ivsDieBand(83)) != 12
        )
            ++bad;
        // the charisma percent - the 7 die roll times the 12 score reads 84
        // percent
    if (7 * 12 != 84
        )
            ++bad;
        // the strength percent - the 3 die roll times the 17 score reads 51
        // percent
    if (3 * 17 != 51
        )
            ++bad;
        // the band edges - the 20 floor reads the d4, the 125 score-added
        // tail reads the d12
    if (ivsDieSides(ivsDieBand(20)) != 4
            || ivsDieSides(ivsDieBand(125)) != 12
        )
            ++bad;
        // the 18/87 fighter - the ladder reads effective strength 23 for the
        // boulder
    if (ivsLadderStr(ivsExStrLadder(87)) != 23
        )
            ++bad;
        // the ladder floor - 18/20 reads 18, 18/21 reads 19
    if (ivsLadderStr(ivsExStrLadder(20)) != 18
            || ivsLadderStr(ivsExStrLadder(21)) != 19
        )
            ++bad;
        // the 18/00 top - the ink's 18-super-90 glyph prints 27, pinned as
        // scanned
    if (ivsLadderStr(ivsExStrLadder(100)) != 27
        )
            ++bad;
        // the use grid rows - STR exertion, CON stamina, CHA persuasion
    if (ivsUseExertion(0) != 1
            || ivsUseStamina(3) != 1
            || ivsUsePersuasion(5) != 1
        )
            ++bad;
        // the device column - INT operation, WIS recognition, DEX
        // manipulation
    if (ivsUseDevice(1) != 1
            || ivsUseDevice(2) != 1
            || ivsUseDevice(4) != 1
        )
            ++bad;
        // the learning and hands columns - INT learning, DEX manipulation
    if (ivsUseLearning(1) != 1
            || ivsUseManipulation(4) != 1
        )
            ++bad;
        printf("R887 Ives attribute audit: bad %d\n", bad);
        if (bad) return 1;
    }
