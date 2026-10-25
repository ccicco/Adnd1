    // ---- R298: the thief function take table pins audit ----
    // The PHB Thief Function Take table (upload
    // line 1620): the base chances of the eight
    // functions at thief levels 1 through 17,
    // pinned in TENTHS of a percent (the printed
    // climb walls column carries a decimal from
    // the 11th level: 99.1% reads 991; the read
    // languages dash at levels 1-3 reads 0), the
    // six racial adjustment rows (upload lines
    // 1645-1650; the human default reads 0) and
    // DEXTERITY TABLE II (upload line 400; the
    // five printed columns, scores 9 through 18;
    // hear noise, climb walls and read languages
    // print no column and read 0). A DATA-ONLY
    // pin (the R186 poetics precedent) - the
    // engine performs no thief rolls; the seam
    // thfChanceTenths folds base + race + DEX
    // (the adjustments are additional pluses).
    {
        int bad = 0;
        // the counts: eight functions, 17 levels
        if (rules::thfFunctionCount() != 8 ||
            rules::thfLevelCount() != 17) ++bad;
        // the printed take table, cell by cell
        static const int kTake[17][8] = {
            {  300,  250,  200,  150,  100,  100,  850,    0 },
            {  350,  290,  250,  210,  150,  100,  860,    0 },
            {  400,  330,  300,  270,  200,  150,  870,    0 },
            {  450,  370,  350,  330,  250,  150,  880,  200 },
            {  500,  420,  400,  400,  310,  200,  900,  250 },
            {  550,  470,  450,  470,  370,  200,  920,  300 },
            {  600,  520,  500,  550,  430,  250,  940,  350 },
            {  650,  570,  550,  620,  490,  250,  960,  400 },
            {  700,  620,  600,  700,  560,  300,  980,  450 },
            {  800,  670,  650,  780,  630,  300,  990,  500 },
            {  900,  720,  700,  860,  700,  350,  991,  550 },
            { 1000,  770,  750,  940,  770,  350,  992,  600 },
            { 1050,  820,  800,  990,  850,  400,  993,  650 },
            { 1100,  870,  850,  990,  930,  400,  994,  700 },
            { 1150,  920,  900,  990,  990,  500,  995,  750 },
            { 1250,  970,  950,  990,  990,  500,  996,  800 },
            { 1250,  990,  990,  990,  990,  550,  997,  800 },
        };
        for (int l = 1; l <= 17; ++l)
            for (int f = 0; f < 8; ++f)
                if (rules::thfTakeTenths(f, l) !=
                    kTake[l - 1][f]) ++bad;
        // the printed read languages dash:
        // levels 1-3 read 0
        for (int l = 1; l <= 3; ++l)
            if (rules::thfTakeTenths(7, l) != 0) ++bad;
        // the take-table clamps: fn 0..7,
        // level 1..17 (the open locks probe:
        // the 16th and 17th rows differ, so a
        // slipped upper clamp cannot hide)
        if (rules::thfTakeTenths(-1, 5) != 500 ||
            rules::thfTakeTenths(9, 5) != 250 ||
            rules::thfTakeTenths(0, 0) != 300 ||
            rules::thfTakeTenths(0, 99) != 1250 ||
            rules::thfTakeTenths(1, 99) != 990 ||
            rules::thfTakeTenths(7, -3) != 0 ||
            rules::thfTakeTenths(7, 20) != 800) ++bad;
        // the printed racial rows (upload lines
        // 1645-1650), keyed to the rules/races.h
        // enum order
        static const int kRace[7][8] = {
            {   0,   0,   0,   0,   0,   0,   0,   0 },  // human
            {   0,  10,  15,   0,   0,   0, -10,  -5 },  // dwarf
            {   5,  -5,   0,   5,  10,   5,   0,   0 },  // elf
            {   0,   5,  10,   5,   5,  10, -15,   0 },  // gnome
            {  10,   0,   0,   0,   5,   0,   0,   0 },  // half-elf
            {   5,   5,   5,  10,  15,   5, -15,  -5 },  // halfling
            {  -5,   5,   5,   0,   0,   5,   5, -10 },  // half-orc
        };
        for (int r = 0; r < 7; ++r)
            for (int f = 0; f < 8; ++f)
                if (rules::thfRaceAdj(r, f) !=
                    kRace[r][f]) ++bad;
        // the racial clamps: race 0..6,
        // fn 0..7
        if (rules::thfRaceAdj(-1, 0) != 0 ||
            rules::thfRaceAdj(99, 0) != -5 ||
            rules::thfRaceAdj(1, -1) != 0 ||
            rules::thfRaceAdj(1, 9) != -5) ++bad;
        // DEXTERITY TABLE II (upload line 400),
        // cell by cell
        static const int kDex[10][5] = {
            { -15, -10, -10, -20, -10 },  // 9
            { -10,  -5, -10, -15,  -5 },  // 10
            {  -5,   0,  -5, -10,   0 },  // 11
            {   0,   0,   0,  -5,   0 },  // 12
            {   0,   0,   0,   0,   0 },  // 13
            {   0,   0,   0,   0,   0 },  // 14
            {   0,   0,   0,   0,   0 },  // 15
            {   0,   5,   0,   0,   0 },  // 16
            {   5,  10,   0,   5,   5 },  // 17
            {  10,  15,   5,  10,  10 },  // 18
        };
        for (int s = 9; s <= 18; ++s)
            for (int f = 0; f < 5; ++f)
                if (rules::thfDexAdj(s, f) !=
                    kDex[s - 9][f]) ++bad;
        // the DEX band clamps: below 9 reads
        // the 9 row, above 18 the 18 row
        if (rules::thfDexAdj(3, 0) != -15 ||
            rules::thfDexAdj(1, 0) != -15 ||
            rules::thfDexAdj(25, 0) != 10 ||
            rules::thfDexAdj(19, 1) != 15) ++bad;
        // the functions DEX Table II prints no
        // column for read 0, every score
        for (int s = 9; s <= 18; ++s)
            if (rules::thfDexAdj(s, 5) != 0 ||
                rules::thfDexAdj(s, 6) != 0 ||
                rules::thfDexAdj(s, 7) != 0) ++bad;
        // the DEX fn clamps: -1 reads the pick
        // pockets column, 12 the read
        // languages 0
        if (rules::thfDexAdj(9, -1) != -15 ||
            rules::thfDexAdj(9, 12) != 0) ++bad;
        // the seam identity: base + race + DEX,
        // every function, a 10th-level dwarf at
        // DEX 16
        for (int f = 0; f < 8; ++f)
            if (rules::thfChanceTenths(f, 10, 1, 16) !=
                rules::thfTakeTenths(f, 10) + 10 *
                (rules::thfRaceAdj(1, f) +
                 rules::thfDexAdj(16, f))) ++bad;
        // the printed pick pockets example (the
        // THIEF notes): a 12th-level half-elf
        // Master Thief with DEX 18 reads
        // 100 + 10 + 10 = 120 percent, and the
        // 12th-level victim cuts 9 x 5 = 45:
        // the chance lands at 75
        if (rules::thfChanceTenths(0, 12, 4, 18) !=
            1200 ||
            rules::thfChanceTenths(0, 12, 4, 18) -
            10 * (9 *
            rules::thfNotePocketsVictimCut()) !=
            750) ++bad;
        // the printed notes: the percentile roll
        // (equal or less succeeds), the 21%
        // notice band, the 5% victim cut, the
        // locks and traps one-try rules, the
        // additional racial pluses
        if (rules::thfNotePercentileRoll() != 1 ||
            rules::thfNotePocketsNoticeBand() != 21 ||
            rules::thfNotePocketsVictimCut() != 5 ||
            rules::thfNoteLocksOneTry() != 1 ||
            rules::thfNoteTrapsSeparate() != 1 ||
            rules::thfNoteRacialAdditional() != 1) ++bad;
        printf("R298 thief function take table pins audit: bad %d\n", bad);
    }
