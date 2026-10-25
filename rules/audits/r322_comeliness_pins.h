    // ---- R322: the comeliness pins audit ----
    // The UA arc opener: the comeliness
    // pins (rules/comeliness.h) - pinned
    // data only, no engine site (the
    // pin-era pattern). Draw-independent:
    // every pin reads fixed.
    {
        int bad = 0;
        // U1: the charisma ladder - every
        // band edge
        {
            if (rules::uaComelinessChaAdj(2)
                != -8) ++bad;
            if (rules::uaComelinessChaAdj(3)
                != -5) ++bad;
            if (rules::uaComelinessChaAdj(4)
                != -3) ++bad;
            if (rules::uaComelinessChaAdj(5)
                != -3) ++bad;
            if (rules::uaComelinessChaAdj(6)
                != -1) ++bad;
            if (rules::uaComelinessChaAdj(8)
                != -1) ++bad;
            if (rules::uaComelinessChaAdj(9)
                != 0) ++bad;
            if (rules::uaComelinessChaAdj(12)
                != 0) ++bad;
            if (rules::uaComelinessChaAdj(13)
                != 1) ++bad;
            if (rules::uaComelinessChaAdj(15)
                != 1) ++bad;
            if (rules::uaComelinessChaAdj(16)
                != 2) ++bad;
            if (rules::uaComelinessChaAdj(17)
                != 2) ++bad;
            if (rules::uaComelinessChaAdj(18)
                != 3) ++bad;
            if (rules::uaComelinessChaAdj(19)
                != 5) ++bad;
            if (rules::uaComelinessChaAdj(25)
                != 5) ++bad;
        }
        // U2: the racial adjustments -
        // every engine race
        {
            if (rules::uaComelinessRacialAdj(
                    rules::RACE_HALF_ORC)
                != -3) ++bad;
            if (rules::uaComelinessRacialAdj(
                    rules::RACE_DWARF)
                != -1) ++bad;
            if (rules::uaComelinessRacialAdj(
                    rules::RACE_GNOME)
                != -1) ++bad;
            if (rules::uaComelinessRacialAdj(
                    rules::RACE_HUMAN) != 0) ++bad;
            if (rules::uaComelinessRacialAdj(
                    rules::RACE_HALFLING)
                != 0) ++bad;
            if (rules::uaComelinessRacialAdj(
                    rules::RACE_HALF_ELF)
                != 1) ++bad;
            if (rules::uaComelinessRacialAdj(
                    rules::RACE_ELF) != 1) ++bad;
        }
        // U3: the band edges - all ten
        // bands
        {
            if (rules::uaComelinessBand(-16)
                != 0) ++bad;
            if (rules::uaComelinessBand(-15)
                != 1) ++bad;
            if (rules::uaComelinessBand(-9)
                != 1) ++bad;
            if (rules::uaComelinessBand(-8)
                != 2) ++bad;
            if (rules::uaComelinessBand(0)
                != 2) ++bad;
            if (rules::uaComelinessBand(1)
                != 3) ++bad;
            if (rules::uaComelinessBand(6)
                != 3) ++bad;
            if (rules::uaComelinessBand(7)
                != 4) ++bad;
            if (rules::uaComelinessBand(9)
                != 4) ++bad;
            if (rules::uaComelinessBand(10)
                != 5) ++bad;
            if (rules::uaComelinessBand(13)
                != 5) ++bad;
            if (rules::uaComelinessBand(14)
                != 6) ++bad;
            if (rules::uaComelinessBand(17)
                != 6) ++bad;
            if (rules::uaComelinessBand(18)
                != 7) ++bad;
            if (rules::uaComelinessBand(21)
                != 7) ++bad;
            if (rules::uaComelinessBand(22)
                != 8) ++bad;
            if (rules::uaComelinessBand(25)
                != 8) ++bad;
            if (rules::uaComelinessBand(26)
                != 9) ++bad;
            if (rules::uaComelinessBand(30)
                != 9) ++bad;
        }
        // U4: the reaction multipliers
        {
            if (rules::uaComelinessReactionPct(
                    13) != 0) ++bad;
            if (rules::uaComelinessReactionPct(
                    15) != 100) ++bad;
            if (rules::uaComelinessReactionPct(
                    17) != 100) ++bad;
            if (rules::uaComelinessReactionPct(
                    18) != 150) ++bad;
            if (rules::uaComelinessReactionPct(
                    21) != 150) ++bad;
            if (rules::uaComelinessReactionPct(
                    22) != 200) ++bad;
            if (rules::uaComelinessReactionPct(
                    26) != 200) ++bad;
            if (rules::uaComelinessReactionPct(
                    -10) != 0) ++bad;
        }
        // U5: the fascinate floors, the
        // sought minimums, the save
        {
            if (rules::
                uaComelinessFascinateWisMin(
                    15, true) != 7) ++bad;
            if (rules::
                uaComelinessFascinateWisMin(
                    15, false) != -1) ++bad;
            if (rules::
                uaComelinessFascinateWisMin(
                    20, true) != 13) ++bad;
            if (rules::
                uaComelinessFascinateWisMin(
                    20, false) != 10) ++bad;
            if (rules::
                uaComelinessFascinateWisMin(
                    24, true) != 16) ++bad;
            if (rules::
                uaComelinessFascinateWisMin(
                    24, false) != 16) ++bad;
            if (rules::
                uaComelinessFascinateWisMin(
                    28, true) != 21) ++bad;
            if (rules::
                uaComelinessFascinateWisMin(
                    28, false) != 21) ++bad;
            if (rules::
                uaComelinessFascinateWisMin(
                    10, true) != -1) ++bad;
            if (rules::uaComelinessSoughtWisMin(
                    20) != 0) ++bad;
            if (rules::uaComelinessSoughtWisMin(
                    24) != 18) ++bad;
            if (rules::uaComelinessSoughtWisMin(
                    28) != 20) ++bad;
            if (rules::
                uaComelinessUnearthlySaveWis(
                    24) != 0) ++bad;
            if (rules::
                uaComelinessUnearthlySaveWis(
                    28) != 19) ++bad;
        }
        // U6: the caps and the dice
        {
            if (rules::
                uaComelinessBaseDieCount()
                != 3) ++bad;
            if (rules::
                uaComelinessBaseDieSides()
                != 6) ++bad;
            if (rules::
                uaComelinessIllusionAdjustMax()
                != 1) ++bad;
            if (rules::
                uaComelinessOrderDieCount()
                != 3) ++bad;
            if (rules::
                uaComelinessOrderDieSides()
                != 6) ++bad;
        }
        printf("R322 comeliness pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
