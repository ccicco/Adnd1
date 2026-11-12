    // ---- R874 clerical chart batch six audit ----
    // APPENDIX 3: THE CLERICAL QUICK-REFERENCE CHARTS, BATCH SIX - the D&DG
    // walk round twenty-six, print p. 141: the sixth batch of deity rows -
    // the thirteen Nehwon rows - riding the roster data file, the block below
    // the R873 Melnibonean tail on the same pdf page; the App 3 gap box stays
    // open until the last chart batch lands. The print voice is the ROTATED
    // tesseract pass, collated against the 1eonline L&L per-deity chart rows.
    // The headline divergences: the print reads the Aarth flags male + female
    // only where the L&L voice reads a third X, and the Red God sphere fire
    // where the L&L voice reads underground areas - pinned by print, eyeball
    // flags.
    {
        using namespace rules;
        int bad = 0;
    if (cqc6Round() != 874
            || cqc6Batch() != 6
            || cqc6PrintStart() != 141
            || cqc6PrintEnd() != 141
            || cqc6Rows() != 13
            || cqc6NehwonRows() != 13
            || cqc6MaleRows() != 12
            || cqc6FemaleRows() != 11
            || cqc6NonHumanRows() != 2
            || cqc6PrintedColumns() != 13
            || cqc6SphereCount() != 13
            || cqc6AnimalCount() != 9
            || cqc6HeadCount() != 10
            || cqc6BodyCount() != 13
            || cqc6ColorCount() != 12
            || cqc6HolyDayCount() != 7
            || cqc6FreqCount() != 4
            || cqc6FormCount() != 8
            || cqc6PlaceCount() != 4
            || cqc6TableCount() != 1
            || cqc6ChainCount() != 0
            || !cqc6AarthMfOnlyPrint()
            || !cqc6RedGodSphereFire()
            || !cqc6HatePlaceUnderground()
            || !cqc6EarthGodNamePin()
            || !cqc6YearsEndRestored()
            || !cqc6RedTailedRestored()
            || !cqc6SummerRestored()
            || !cqc6RatGodNhGeometry()
            || !cqc6GodsOfTroubleStrayDot()
            || !cqc6TyaaFemaleOnly()
        )
            ++bad;
        // the the clerical chart batch six grid grid
        int Ccqc6Chart[13][13] = {
            {0,0,0,1,1,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,1,1,1,1,1,1,1,1},
            {2,2,2,1,1,0,2,2,2,2,1,1,0},
            {3,3,2,1,1,0,3,3,3,1,1,1,1},
            {4,4,2,1,1,0,4,4,4,3,0,2,2},
            {5,5,2,1,1,0,0,5,5,0,0,3,3},
            {6,6,3,1,1,0,5,6,6,4,0,4,0},
            {7,7,2,1,0,0,6,7,7,5,2,5,0},
            {8,8,4,1,0,1,0,8,4,4,0,5,0},
            {9,9,5,1,1,0,7,9,8,6,0,6,0},
            {10,10,6,1,1,0,0,10,9,6,3,5,0},
            {11,11,7,0,1,0,8,11,10,4,2,7,0},
            {12,12,8,1,1,0,9,12,11,0,2,7,0},
            };
        for (int b = 0;
             b < cqc6Rows();
             ++b) {
            int vals[13];
            vals[0] = cqc6ChartOrd(b);
            vals[1] = cqc6ChartSphere(b);
            vals[2] = cqc6ChartAnimal(b);
            vals[3] = cqc6ChartM(b);
            vals[4] = cqc6ChartF(b);
            vals[5] = cqc6ChartNh(b);
            vals[6] = cqc6ChartHead(b);
            vals[7] = cqc6ChartBody(b);
            vals[8] = cqc6ChartColor(b);
            vals[9] = cqc6ChartHolyday(b);
            vals[10] = cqc6ChartFreq(b);
            vals[11] = cqc6ChartForm(b);
            vals[12] = cqc6ChartPlace(b);
            for (int c = 0; c < 13;
                 ++c) {
                if (vals[c] != Ccqc6Chart[b][c])
                    ++bad;
            }
        }
        // the census walk (the batch rows, the Nehwon count, the roster
        // counts, the cleric flags)
    if (cqc6Round() != 874
            || cqc6Batch() != 6
            || cqc6PrintStart() != 141
            || cqc6PrintEnd() != 141
            || cqc6Rows() != 13
            || cqc6NehwonRows() != 13
            || cqc6MaleRows() != 12
            || cqc6FemaleRows() != 11
            || cqc6NonHumanRows() != 2
            || cqc6PrintedColumns() != 13
            || cqc6SphereCount() != 13
            || cqc6AnimalCount() != 9
            || cqc6HeadCount() != 10
            || cqc6BodyCount() != 13
            || cqc6ColorCount() != 12
            || cqc6HolyDayCount() != 7
            || cqc6FreqCount() != 4
            || cqc6FormCount() != 8
            || cqc6PlaceCount() != 4
            || cqc6TableCount() != 1
            || cqc6ChainCount() != 0
        )
            ++bad;
        // the parity pins (the Aarth and Red God divergences, the garble
        // restorations, the geometry pins)
    if (cqc6AarthMfOnlyPrint() != 1
            || cqc6RedGodSphereFire() != 1
            || cqc6HatePlaceUnderground() != 1
            || cqc6EarthGodNamePin() != 1
            || cqc6YearsEndRestored() != 1
            || cqc6RedTailedRestored() != 1
            || cqc6SummerRestored() != 1
            || cqc6RatGodNhGeometry() != 1
            || cqc6GodsOfTroubleStrayDot() != 1
            || cqc6TyaaFemaleOnly() != 1
        )
            ++bad;
        // the head and tail rows (Aarth 0, Votishal 12, the ordinals run)
    if (cqc6ChartOrd(0) != 0
            || cqc6ChartM(0) != 1
            || cqc6ChartF(0) != 1
            || cqc6ChartNh(0) != 0
            || cqc6ChartHead(0) != 0
            || cqc6ChartBody(0) != 0
            || cqc6ChartColor(0) != 0
            || cqc6ChartHolyday(0) != 0
            || cqc6ChartFreq(0) != 0
            || cqc6ChartForm(0) != 0
            || cqc6ChartPlace(0) != 0
            || cqc6ChartOrd(12) != 12
            || cqc6ChartSphere(12) != 12
            || cqc6ChartAnimal(12) != 8
            || cqc6ChartHead(12) != 9
            || cqc6ChartBody(12) != 12
            || cqc6ChartColor(12) != 11
            || cqc6ChartFreq(12) != 2
            || cqc6ChartForm(12) != 7
        )
            ++bad;
        // the mid rows (the year-s end and suffering classes, the color wrap,
        // the Rat God geometry)
    if (cqc6ChartSphere(2) != 2
            || cqc6ChartHead(2) != 2
            || cqc6ChartColor(2) != 2
            || cqc6ChartHolyday(2) != 2
            || cqc6ChartSphere(3) != 3
            || cqc6ChartColor(3) != 3
            || cqc6ChartForm(3) != 1
            || cqc6ChartSphere(4) != 4
            || cqc6ChartForm(4) != 2
            || cqc6ChartPlace(4) != 2
            || cqc6ChartHead(5) != 0
            || cqc6ChartForm(5) != 3
            || cqc6ChartPlace(5) != 3
            || cqc6ChartAnimal(6) != 3
            || cqc6ChartHead(6) != 5
            || cqc6ChartForm(6) != 4
            || cqc6ChartHead(7) != 6
            || cqc6ChartColor(7) != 7
            || cqc6ChartHolyday(7) != 5
            || cqc6ChartFreq(7) != 2
            || cqc6ChartSphere(8) != 8
            || cqc6ChartM(8) != 1
            || cqc6ChartF(8) != 0
            || cqc6ChartNh(8) != 1
            || cqc6ChartHead(8) != 0
        )
            ++bad;
        // the god rows (the fire sphere pin, the red-tailed hawk, the
        // female-only Tyaa)
    if (cqc6ChartSphere(9) != 9
            || cqc6ChartAnimal(9) != 5
            || cqc6ChartHead(9) != 7
            || cqc6ChartBody(9) != 9
            || cqc6ChartColor(9) != 8
            || cqc6ChartHolyday(9) != 6
            || cqc6ChartForm(9) != 6
            || cqc6ChartSphere(10) != 10
            || cqc6ChartBody(10) != 10
            || cqc6ChartColor(10) != 9
            || cqc6ChartFreq(10) != 3
            || cqc6ChartSphere(11) != 11
            || cqc6ChartAnimal(11) != 7
            || cqc6ChartM(11) != 0
            || cqc6ChartF(11) != 1
            || cqc6ChartNh(11) != 0
            || cqc6ChartHead(11) != 8
            || cqc6ChartColor(11) != 10
            || cqc6ChartFreq(11) != 2
            || cqc6ChartForm(11) != 7
        )
            ++bad;
        // the cleric flags (the female and non-human census cells)
    if (cqc6ChartF(0) != 1
            || cqc6ChartF(1) != 1
            || cqc6ChartF(2) != 1
            || cqc6ChartF(3) != 1
            || cqc6ChartF(4) != 1
            || cqc6ChartF(5) != 1
            || cqc6ChartF(6) != 1
            || cqc6ChartF(7) != 0
            || cqc6ChartF(8) != 0
            || cqc6ChartF(9) != 1
            || cqc6ChartF(10) != 1
            || cqc6ChartF(11) != 1
            || cqc6ChartF(12) != 1
            || cqc6ChartM(7) != 1
            || cqc6ChartM(8) != 1
            || cqc6ChartM(11) != 0
            || cqc6ChartNh(0) != 0
            || cqc6ChartNh(1) != 1
            || cqc6ChartNh(2) != 0
            || cqc6ChartNh(3) != 0
            || cqc6ChartNh(4) != 0
            || cqc6ChartNh(5) != 0
            || cqc6ChartNh(6) != 0
            || cqc6ChartNh(7) != 0
            || cqc6ChartNh(8) != 1
            || cqc6ChartNh(9) != 0
            || cqc6ChartNh(10) != 0
            || cqc6ChartNh(11) != 0
            || cqc6ChartNh(12) != 0
        )
            ++bad;
        printf("R874 clerical chart batch six audit: bad %d\n", bad);
        if (bad) return 1;
    }
