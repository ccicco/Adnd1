    // ---- R703 OA terrain encounter tables audit ----
    // OA round ninety (capture pp. 251-252): the Chapter 11 terrain encounter
    // tables - the sixteen terrain columns of the 2-20 roll grid with the
    // encounter names by ordinal, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djqOA74ColumnCount() != 16
            || djqOA74RowCount() != 19
            || djqOA74RollMin() != 2
            || djqOA74RollMax() != 20
            || djqOA74NameCount() != 164
            || !djqOA74ColdRegionsAllTerrains()
            || !djqOA74ColumnByTerrainType()
        )
            ++bad;
        // the terrain grid audit - each of the 304 pinned cells against the
        // sixteen columns
        int CTerrain[19][16] = {
            {109,34,42,118,77,99,80,21,101,164,80,31,149,21,77,127},
            {77,164,94,62,58,13,58,95,74,111,24,94,87,44,111,116},
            {79,92,1,59,2,46,35,39,46,100,154,1,41,25,108,71},
            {88,153,25,38,154,153,51,43,124,12,84,25,32,12,137,82},
            {65,155,106,101,65,12,152,98,152,26,93,150,35,101,26,83},
            {3,143,91,137,16,18,3,27,72,139,135,95,85,19,72,129},
            {136,139,146,145,113,17,18,54,131,143,137,158,6,95,16,50},
            {96,156,110,122,23,156,63,28,16,126,107,110,47,54,107,107},
            {120,16,158,102,14,5,151,147,105,102,52,130,9,102,133,7},
            {104,125,95,148,121,84,107,102,133,125,102,103,128,11,69,63},
            {102,57,130,147,75,102,102,11,151,156,112,130,53,28,102,151},
            {113,6,144,107,22,23,129,96,107,107,15,97,45,156,114,162},
            {137,5,103,3,81,14,115,19,5,140,3,95,50,96,3,8},
            {18,140,157,162,85,4,143,89,132,141,162,157,60,70,143,135},
            {68,61,67,65,35,73,101,32,102,38,66,67,39,32,152,152},
            {74,24,160,66,66,100,154,101,161,142,74,134,38,39,61,51},
            {20,35,40,159,117,101,111,37,112,138,101,40,37,43,86,74},
            {56,123,36,78,76,29,64,30,117,108,90,36,10,48,119,74},
            {76,163,49,90,99,2,92,160,55,48,92,49,33,160,118,3},
            };
        for (int b = 0;
             b < djqOA74RowCount();
             ++b) {
            int vals[16];
            vals[0] = djqOA74CityTown(b);
            vals[1] = djqOA74TSMountains(b);
            vals[2] = djqOA74TSOcean(b);
            vals[3] = djqOA74TempSwamp(b);
            vals[4] = djqOA74Rural(b);
            vals[5] = djqOA74TSForest(b);
            vals[6] = djqOA74TempMountain(b);
            vals[7] = djqOA74TempFreshwater(b);
            vals[8] = djqOA74Steppes(b);
            vals[9] = djqOA74TSSwamp(b);
            vals[10] = djqOA74TempForest(b);
            vals[11] = djqOA74TempOcean(b);
            vals[12] = djqOA74Aerial(b);
            vals[13] = djqOA74TSFreshwater(b);
            vals[14] = djqOA74TempPlain(b);
            vals[15] = djqOA74ColdRegions(b);
            for (int c = 0; c < 16;
                 ++c) {
                if (vals[c] != CTerrain[b][c])
                    ++bad;
            }
        }
        // the open - the roll 2 of all sixteen columns, the first band of the
        // grid
    if (djqOA74CityTown(0) != 109
            || djqOA74TSMountains(0) != 34
            || djqOA74TSOcean(0) != 42
            || djqOA74TempSwamp(0) != 118
            || djqOA74Rural(0) != 77
            || djqOA74TSForest(0) != 99
            || djqOA74TempMountain(0) != 80
            || djqOA74TempFreshwater(0) != 21
            || djqOA74Steppes(0) != 101
            || djqOA74TSSwamp(0) != 164
            || djqOA74TempForest(0) != 80
            || djqOA74TempOcean(0) != 31
            || djqOA74Aerial(0) != 149
            || djqOA74TSFreshwater(0) != 21
            || djqOA74TempPlain(0) != 77
            || djqOA74ColdRegions(0) != 127
        )
            ++bad;
        // the close - the roll 20 of all sixteen columns, the last band of
        // the grid
    if (djqOA74CityTown(18) != 76
            || djqOA74TSMountains(18) != 163
            || djqOA74TSOcean(18) != 49
            || djqOA74TempSwamp(18) != 90
            || djqOA74Rural(18) != 99
            || djqOA74TSForest(18) != 2
            || djqOA74TempMountain(18) != 92
            || djqOA74TempFreshwater(18) != 160
            || djqOA74Steppes(18) != 55
            || djqOA74TSSwamp(18) != 48
            || djqOA74TempForest(18) != 92
            || djqOA74TempOcean(18) != 49
            || djqOA74Aerial(18) != 33
            || djqOA74TSFreshwater(18) != 160
            || djqOA74TempPlain(18) != 118
            || djqOA74ColdRegions(18) != 3
        )
            ++bad;
        // the City/Town ladder - Jiki-ketsu-gaki the 3, Kuei the 5, Merchant
        // the 9, Noble the 11, Oriental NPC party the 13, Gaijin NPC party
        // the 19
    if (djqOA74CityTown(1) != 77
            || djqOA74CityTown(3) != 88
            || djqOA74CityTown(7) != 96
            || djqOA74CityTown(9) != 104
            || djqOA74CityTown(11) != 113
            || djqOA74CityTown(17) != 56
        )
            ++bad;
        // the Aerial dragon ladder - Spirits of the air or dragon, t'ien lung
        // the 2, Dragon, tun mi lung or elemental, air the 4, Dragon, chiang
        // lung the 5, Dragon, li lung the 6, Dragon, shen lung the 16,
        // Dragon, pan lung the 17, Dragon, mist the 18, Dragon, cloud or
        // dragon, gold the 20
    if (djqOA74Aerial(0) != 149
            || djqOA74Aerial(2) != 41
            || djqOA74Aerial(3) != 32
            || djqOA74Aerial(4) != 35
            || djqOA74Aerial(14) != 39
            || djqOA74Aerial(15) != 38
            || djqOA74Aerial(16) != 37
            || djqOA74Aerial(18) != 33
        )
            ++bad;
        // the Cold Regions ladder - Hoarfox the 4, Bear, black the 10, Giant,
        // hill the 11, Bear, northern the 14, the Hu hsien twice at 18 and 19
    if (djqOA74ColdRegions(2) != 71
            || djqOA74ColdRegions(8) != 7
            || djqOA74ColdRegions(9) != 63
            || djqOA74ColdRegions(12) != 8
            || djqOA74ColdRegions(16) != 74
            || djqOA74ColdRegions(17) != 74
        )
            ++bad;
        // the OCR repairs - the Buso, tigbauna at the City/Town 15, the
        // Giant, hill at the Temperate Mountain 9, the Hai nu at both ocean
        // 16s
    if (djqOA74CityTown(13) != 18
            || djqOA74TempMountain(7) != 63
            || djqOA74TSOcean(14) != 67
            || djqOA74TempOcean(14) != 67
        )
            ++bad;
        // as printed - the Temperate Ocean the School of fish at 10 and at
        // 12, the Men, wako at 7 and at 14
    if (djqOA74TempOcean(8) != 130
            || djqOA74TempOcean(10) != 130
            || djqOA74TempOcean(5) != 95
            || djqOA74TempOcean(12) != 95
        )
            ++bad;
        // the shape - the sixteen columns, the nineteen rows, the 2-20 roll,
        // the 164 names, the cold regions all terrain types, the column by
        // terrain type
    if (djqOA74ColumnCount() != 16
            || djqOA74RowCount() != 19
            || djqOA74RollMin() != 2
            || djqOA74RollMax() != 20
            || djqOA74NameCount() != 164
            || djqOA74ColdRegionsAllTerrains() != 1
            || djqOA74ColumnByTerrainType() != 1
        )
            ++bad;
        printf("R703 OA terrain encounter tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
