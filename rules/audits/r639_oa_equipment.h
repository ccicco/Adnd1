    // ---- R639 OA equipment audit ----
    // OA round twenty-six (capture pp. 76-78): the equipping the character
    // prose and the Table 47 cost lists
    {
        using namespace rules;
        int bad = 0;
    if (dgzT47RowCount() != 256
            || dgzT47ArmorCount() != 28
            || dgzT47ArmsCount() != 76
            || dgzT47ClothingCount() != 22
            || dgzT47LivestockCount() != 25
            || dgzT47MiscCount() != 42
            || dgzT47ProvisionsCount() != 11
            || dgzT47ReligiousCount() != 8
            || dgzT47ServicesCount() != 15
            || dgzT47TackCount() != 16
            || dgzT47TransportCount() != 13
            || !dgzEquipAfterCreation()
            || !dgzEquipAdventuringReason()
            || !dgzEquipEstablishedPrices()
            || !dgzEquipBarterPurchase()
            || !dgzEquipIncompleteList()
            || !dgzEquipPriceChange()
            || !dgzEquipAvailability()
            || !dgzT47ArmorPieceNote()
            || !dgzT47NinjaPrefNote()
        )
            ++bad;
        // the Table 47 armor grid: cost, unit, star (capture pp. 77-78)
        int CT47Armor[28][3] = {
            {5,4,0},
            {5,2,0},
            {5,4,0},
            {5,4,1},
            {1,4,1},
            {1,3,0},
            {1,4,1},
            {5,3,1},
            {2,4,1},
            {3,4,1},
            {2,3,0},
            {8,3,0},
            {2,3,1},
            {1,3,0},
            {5,4,0},
            {8,3,1},
            {2,3,0},
            {20,4,0},
            {1,3,0},
            {1,4,0},
            {4,3,0},
            {2,4,0},
            {2,3,0},
            {30,2,0},
            {8,3,1},
            {4,4,0},
            {4,3,0},
            {5,3,1},
            };
        int nT47Armor[3] = {0,0,0};
        int eT47Armor[3] = {0,0,0};
        for (int b = 0;
             b < dgzT47ArmorCount();
             ++b) {
            int vals[3];
            vals[0] = dgzT47ArmorCost(b);
            vals[1] = dgzT47ArmorUnit(b);
            vals[2] = dgzT47ArmorStar(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT47Armor[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT47Armor[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT47Armor[c] != eT47Armor[c])
                ++bad;
        // the Table 47 arms grid: cost, unit, star (capture pp. 77-78)
        int CT47Arms[76][3] = {
            {5,2,0},
            {10,2,0},
            {10,2,0},
            {1,3,0},
            {2,2,0},
            {5,3,0},
            {2,3,0},
            {2,2,0},
            {2,1,0},
            {6,2,0},
            {1,4,0},
            {5,3,0},
            {10,2,0},
            {6,3,1},
            {3,4,0},
            {8,3,0},
            {6,3,0},
            {1,3,0},
            {10,4,0},
            {1,1,0},
            {8,2,0},
            {1,3,0},
            {4,3,0},
            {1,4,0},
            {1,4,0},
            {1,3,0},
            {10,2,0},
            {1,1,0},
            {1,3,0},
            {10,4,0},
            {1,3,0},
            {5,2,0},
            {50,2,0},
            {1,3,0},
            {3,3,0},
            {1,3,0},
            {7,3,0},
            {3,3,0},
            {6,3,0},
            {2,3,0},
            {6,3,0},
            {8,3,0},
            {3,1,0},
            {3,3,0},
            {4,3,0},
            {1,3,0},
            {15,2,0},
            {5,3,0},
            {1,2,0},
            {1,3,0},
            {10,2,0},
            {1,4,0},
            {2,3,0},
            {5,3,0},
            {7,3,0},
            {4,2,0},
            {1,3,0},
            {6,2,0},
            {2,3,0},
            {2,2,0},
            {5,2,0},
            {10,2,0},
            {5,3,0},
            {3,3,0},
            {4,3,0},
            {6,3,0},
            {3,3,0},
            {2,4,0},
            {5,2,0},
            {2,3,0},
            {2,3,0},
            {5,3,0},
            {5,2,0},
            {3,2,0},
            {6,4,0},
            {1,3,0},
            };
        int nT47Arms[3] = {0,0,0};
        int eT47Arms[3] = {0,0,0};
        for (int b = 0;
             b < dgzT47ArmsCount();
             ++b) {
            int vals[3];
            vals[0] = dgzT47ArmsCost(b);
            vals[1] = dgzT47ArmsUnit(b);
            vals[2] = dgzT47ArmsStar(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT47Arms[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT47Arms[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT47Arms[c] != eT47Arms[c])
                ++bad;
        // the Table 47 clothing grid: cost, unit, star (capture pp. 77-78)
        int CT47Clothing[22][3] = {
            {5,2,0},
            {3,2,0},
            {8,1,0},
            {1,3,0},
            {4,3,0},
            {5,2,0},
            {2,2,0},
            {1,1,0},
            {1,1,0},
            {4,2,0},
            {1,2,0},
            {2,2,0},
            {3,3,0},
            {3,3,0},
            {4,1,0},
            {1,2,0},
            {5,2,0},
            {3,2,0},
            {1,3,0},
            {2,2,0},
            {2,3,0},
            {1,3,0},
            };
        int nT47Clothing[3] = {0,0,0};
        int eT47Clothing[3] = {0,0,0};
        for (int b = 0;
             b < dgzT47ClothingCount();
             ++b) {
            int vals[3];
            vals[0] = dgzT47ClothingCost(b);
            vals[1] = dgzT47ClothingUnit(b);
            vals[2] = dgzT47ClothingStar(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT47Clothing[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT47Clothing[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT47Clothing[c] != eT47Clothing[c])
                ++bad;
        // the Table 47 livestock grid: cost, unit, star (capture pp. 77-78)
        int CT47Livestock[25][3] = {
            {5,3,0},
            {2,2,0},
            {3,1,0},
            {1,3,0},
            {5,3,0},
            {3,3,0},
            {8,3,0},
            {1,4,0},
            {5,3,0},
            {50,4,0},
            {2,3,0},
            {5,3,0},
            {5,4,0},
            {20,4,0},
            {15,3,0},
            {5,4,0},
            {25,3,0},
            {3,4,0},
            {2,4,0},
            {8,3,0},
            {1,4,0},
            {2,4,0},
            {6,3,0},
            {15,3,0},
            {2,4,0},
            };
        int nT47Livestock[3] = {0,0,0};
        int eT47Livestock[3] = {0,0,0};
        for (int b = 0;
             b < dgzT47LivestockCount();
             ++b) {
            int vals[3];
            vals[0] = dgzT47LivestockCost(b);
            vals[1] = dgzT47LivestockUnit(b);
            vals[2] = dgzT47LivestockStar(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT47Livestock[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT47Livestock[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT47Livestock[c] != eT47Livestock[c])
                ++bad;
        // the Table 47 misc grid: cost, unit, star (capture pp. 77-78)
        int CT47Misc[42][3] = {
            {5,2,0},
            {4,2,0},
            {2,2,0},
            {1,2,0},
            {3,1,0},
            {5,3,0},
            {3,3,0},
            {30,2,0},
            {1,4,0},
            {6,3,0},
            {4,2,0},
            {1,4,0},
            {3,4,0},
            {2,1,0},
            {10,2,1},
            {3,3,1},
            {1,3,1},
            {1,4,1},
            {2,2,0},
            {1,3,0},
            {10,2,0},
            {3,3,0},
            {5,3,0},
            {2,3,0},
            {1,4,0},
            {3,2,0},
            {4,3,0},
            {6,2,0},
            {1,3,0},
            {10,2,0},
            {5,4,1},
            {1,3,0},
            {2,3,0},
            {1,4,0},
            {2,3,0},
            {1,3,0},
            {1,4,0},
            {8,2,0},
            {5,2,0},
            {1,3,0},
            {10,3,0},
            {1,1,0},
            };
        int nT47Misc[3] = {0,0,0};
        int eT47Misc[3] = {0,0,0};
        for (int b = 0;
             b < dgzT47MiscCount();
             ++b) {
            int vals[3];
            vals[0] = dgzT47MiscCost(b);
            vals[1] = dgzT47MiscUnit(b);
            vals[2] = dgzT47MiscStar(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT47Misc[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT47Misc[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT47Misc[c] != eT47Misc[c])
                ++bad;
        // the Table 47 provisions grid: cost, unit, star (capture pp. 77-78)
        int CT47Provisions[11][3] = {
            {2,2,0},
            {1,3,0},
            {1,2,0},
            {4,3,0},
            {2,1,0},
            {10,2,0},
            {10,2,0},
            {5,4,0},
            {15,2,0},
            {5,2,0},
            {1,3,0},
            };
        int nT47Provisions[3] = {0,0,0};
        int eT47Provisions[3] = {0,0,0};
        for (int b = 0;
             b < dgzT47ProvisionsCount();
             ++b) {
            int vals[3];
            vals[0] = dgzT47ProvisionsCost(b);
            vals[1] = dgzT47ProvisionsUnit(b);
            vals[2] = dgzT47ProvisionsStar(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT47Provisions[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT47Provisions[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT47Provisions[c] != eT47Provisions[c])
                ++bad;
        // the Table 47 religious grid: cost, unit, star (capture pp. 77-78)
        int CT47Religious[8][3] = {
            {1,2,0},
            {3,2,0},
            {50,4,0},
            {1,4,0},
            {3,1,0},
            {1,1,0},
            {1,3,0},
            {3,3,0},
            };
        int nT47Religious[3] = {0,0,0};
        int eT47Religious[3] = {0,0,0};
        for (int b = 0;
             b < dgzT47ReligiousCount();
             ++b) {
            int vals[3];
            vals[0] = dgzT47ReligiousCost(b);
            vals[1] = dgzT47ReligiousUnit(b);
            vals[2] = dgzT47ReligiousStar(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT47Religious[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT47Religious[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT47Religious[c] != eT47Religious[c])
                ++bad;
        // the Table 47 services grid: cost, unit, star (capture pp. 77-78)
        int CT47Services[15][3] = {
            {3,2,0},
            {5,2,0},
            {10,2,0},
            {7,3,0},
            {2,2,0},
            {3,2,0},
            {6,3,0},
            {1,1,0},
            {4,1,0},
            {6,1,0},
            {2,1,0},
            {1,1,0},
            {3,2,0},
            {5,3,0},
            {3,1,0},
            };
        int nT47Services[3] = {0,0,0};
        int eT47Services[3] = {0,0,0};
        for (int b = 0;
             b < dgzT47ServicesCount();
             ++b) {
            int vals[3];
            vals[0] = dgzT47ServicesCost(b);
            vals[1] = dgzT47ServicesUnit(b);
            vals[2] = dgzT47ServicesStar(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT47Services[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT47Services[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT47Services[c] != eT47Services[c])
                ++bad;
        // the Table 47 tack grid: cost, unit, star (capture pp. 77-78)
        int CT47Tack[16][3] = {
            {10,4,0},
            {20,4,0},
            {2,4,0},
            {5,4,0},
            {1,4,0},
            {8,4,0},
            {2,3,0},
            {15,2,0},
            {4,3,0},
            {5,4,0},
            {3,3,0},
            {1,3,0},
            {15,2,0},
            {1,2,0},
            {5,3,0},
            {8,3,0},
            };
        int nT47Tack[3] = {0,0,0};
        int eT47Tack[3] = {0,0,0};
        for (int b = 0;
             b < dgzT47TackCount();
             ++b) {
            int vals[3];
            vals[0] = dgzT47TackCost(b);
            vals[1] = dgzT47TackUnit(b);
            vals[2] = dgzT47TackStar(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT47Tack[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT47Tack[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT47Tack[c] != eT47Tack[c])
                ++bad;
        // the Table 47 transport grid: cost, unit, star (capture pp. 77-78)
        int CT47Transport[13][3] = {
            {300,4,0},
            {100,4,0},
            {20,4,0},
            {3,4,0},
            {8,4,0},
            {50,4,0},
            {100,4,0},
            {500,4,0},
            {300,4,0},
            {800,4,0},
            {5,4,0},
            {5,4,0},
            {20,4,0},
            };
        int nT47Transport[3] = {0,0,0};
        int eT47Transport[3] = {0,0,0};
        for (int b = 0;
             b < dgzT47TransportCount();
             ++b) {
            int vals[3];
            vals[0] = dgzT47TransportCost(b);
            vals[1] = dgzT47TransportUnit(b);
            vals[2] = dgzT47TransportStar(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT47Transport[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT47Transport[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT47Transport[c] != eT47Transport[c])
                ++bad;
        // the T47 total row count pin
    if (dgzT47RowCount() != 256
        )
            ++bad;
        // the armor count pin
    if (dgzT47ArmorCount() != 28
        )
            ++bad;
        // the arms count pin
    if (dgzT47ArmsCount() != 76
        )
            ++bad;
        // the clothing count pin
    if (dgzT47ClothingCount() != 22
        )
            ++bad;
        // the livestock count pin
    if (dgzT47LivestockCount() != 25
        )
            ++bad;
        // the misc count pin
    if (dgzT47MiscCount() != 42
        )
            ++bad;
        // the provisions count pin
    if (dgzT47ProvisionsCount() != 11
        )
            ++bad;
        // the religious count pin
    if (dgzT47ReligiousCount() != 8
        )
            ++bad;
        // the services count pin
    if (dgzT47ServicesCount() != 15
        )
            ++bad;
        // the tack count pin
    if (dgzT47TackCount() != 16
        )
            ++bad;
        // the transport count pin
    if (dgzT47TransportCount() != 13
        )
            ++bad;
        // the EquipAfterCreation pin
    if (dgzEquipAfterCreation() != 1
        )
            ++bad;
        // the EquipAdventuringReason pin
    if (dgzEquipAdventuringReason() != 1
        )
            ++bad;
        // the EquipEstablishedPrices pin
    if (dgzEquipEstablishedPrices() != 1
        )
            ++bad;
        // the EquipBarterPurchase pin
    if (dgzEquipBarterPurchase() != 1
        )
            ++bad;
        // the EquipIncompleteList pin
    if (dgzEquipIncompleteList() != 1
        )
            ++bad;
        // the EquipPriceChange pin
    if (dgzEquipPriceChange() != 1
        )
            ++bad;
        // the EquipAvailability pin
    if (dgzEquipAvailability() != 1
        )
            ++bad;
        // the T47ArmorPieceNote pin
    if (dgzT47ArmorPieceNote() != 1
        )
            ++bad;
        // the T47NinjaPrefNote pin
    if (dgzT47NinjaPrefNote() != 1
        )
            ++bad;
        // the T47 armor O-yoroi row - the great armor at 20 ch'ien (capture
        // p. 77)
    if (dgzT47ArmorCost(17) != 20
            || dgzT47ArmorUnit(17) != 4
        )
            ++bad;
        // the T47 arms katana row - the katana and scabbard at 10 ch'ien
        // (capture p. 77)
    if (dgzT47ArmsCost(29) != 10
            || dgzT47ArmsUnit(29) != 4
        )
            ++bad;
        // the T47 arms kiseru row - the iron pipe at 50 yuan (capture p. 77)
    if (dgzT47ArmsCost(32) != 50
            || dgzT47ArmsUnit(32) != 2
        )
            ++bad;
        // the T47 clothing silk robe row - the silk kosode at 3 tael (capture
        // p. 77)
    if (dgzT47ClothingCost(13) != 3
            || dgzT47ClothingUnit(13) != 3
        )
            ++bad;
        // the T47 livestock elephant row - the war elephant at 50 ch'ien
        // (capture p. 78)
    if (dgzT47LivestockCost(9) != 50
            || dgzT47LivestockUnit(9) != 4
        )
            ++bad;
        // the T47 misc poison-smoke grenade row - 1 ch'ien, starred (capture
        // p. 78)
    if (dgzT47MiscCost(17) != 1
            || dgzT47MiscUnit(17) != 4
            || dgzT47MiscStar(17) != 1
        )
            ++bad;
        // the T47 misc silk rope row - 5 ch'ien, starred (capture p. 78)
    if (dgzT47MiscCost(30) != 5
            || dgzT47MiscUnit(30) != 4
            || dgzT47MiscStar(30) != 1
        )
            ++bad;
        // the T47 provisions rice row - the koku at 5 ch'ien (capture p. 78)
    if (dgzT47ProvisionsCost(7) != 5
            || dgzT47ProvisionsUnit(7) != 4
        )
            ++bad;
        // the T47 religious temple bell row - 50 ch'ien (capture p. 78)
    if (dgzT47ReligiousCost(2) != 50
            || dgzT47ReligiousUnit(2) != 4
        )
            ++bad;
        // the T47 services rows - the servant 5 tael, the clerk 7 tael
        // (capture p. 78)
    if (dgzT47ServicesCost(13) != 5
            || dgzT47ServicesCost(3) != 7
            || dgzT47ServicesUnit(3) != 3
        )
            ++bad;
        // the T47 tack elephant barding row - 20 ch'ien (capture p. 78)
    if (dgzT47TackCost(1) != 20
            || dgzT47TackUnit(1) != 4
        )
            ++bad;
        // the T47 transport war junk row - 800 ch'ien (capture p. 78)
    if (dgzT47TransportCost(9) != 800
            || dgzT47TransportUnit(9) != 4
        )
            ++bad;
        // the T47 star flags - the Do-maru and Sune-ate armor pieces, the
        // chijiriki, the unstarred wakizashi (capture pp. 77-78)
    if (dgzT47ArmorStar(3) != 1
            || dgzT47ArmorStar(27) != 1
            || dgzT47ArmsStar(13) != 1
            || dgzT47ArmsStar(74) != 0
        )
            ++bad;
        printf("R639 OA equipment audit: bad %d\n", bad);
        if (bad) return 1;
    }
