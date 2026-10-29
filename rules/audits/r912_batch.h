    // ---- R912 issue-9 opener audit ----
    // THE DRAGON ISSUE-9 OPENER ROUND - two adjudicated chains. The Gygax
    // alignment article (folios 5-6): the alignment-unknown default, the
    // concealed-alignment doctrine with its survival trigger, the Greyhawk
    // good-majority precept, the good-vs-good war possibility, the
    // mixed-alignment census of places, the Free City's neutral oligarchs
    // with free commerce and thwarted preeminence, the cleric's
    // shrine-to-temple escalation with its enmity, taxes and bribes, the
    // influence-proportionate-to-power doctrine with
    // influence-allowed-dictation-not, the uncoerced choice and the DM
    // intervention law. The Ward Tombs & Crypts article (folio 25): the
    // twelve-occupant d12 with its nine item rolls, the overflow 100 and
    // floor 01 rules, the map and special-item bands, the five-band guardian
    // chain with the 1-4 invisible stalkers, the seven-band tomb structure
    // with the 1-20 corridor band, and the gold, gems, jewelry and misc-magic
    // tables - the five clean gold bands to the 2-40 thousand row, the gems
    // at base 100 to 10,000, the jewelry at base 500 to 50,000, the
    // misc-magic none plus the five Greyhawk tables.
    {
        using namespace rules;
        int bad = 0;
    if (dgnTombOccupantTypes() != 12
            || dgnTombItemRolls() != 9
            || dgnTombOverflowCeiling() != 100
            || dgnTombFloorRoll() != 1
            || dgnTombGoldBands() != 5
            || dgnTombGemsBands() != 7
            || dgnTombJewelryBands() != 7
            || dgnTombMiscMagicBands() != 6
            || dgnTombItselfBands() != 7
            || dgnGuardianStalkerMin() != 1
            || dgnGuardianStalkerMax() != 4
            || dgnTombCorridorsMin() != 1
            || dgnTombCorridorsMax() != 20
            || !dgnAlignmentUnknownByDefault()
            || !dgnDissemblingAlignmentAllowed()
            || !dgnConcealedChangeAtStrength()
            || !dgnGreyhawkGoodMajorityPrecept()
            || !dgnGoodVsGoodWarPossible()
            || !dgnMixedAlignmentsUsual()
            || !dgnGreyhawkOligarchsNeutralOutlook()
            || !dgnGreyhawkCommerceFree()
            || !dgnGreyhawkPreeminenceThwarted()
            || !dgnClericShrineSelfSupporting()
            || !dgnTempleEscalationArousesEnmity()
            || !dgnTaxesLeviedBribesPaid()
            || !dgnInfluenceProportionateToPower()
            || !dgnInfluenceAllowedDictationNot()
            || !dgnUncoercedAlignmentChoice()
            || !dgnDmInterventionDoctrine()
            || !dgnTombPairIsTwoBuried()
            || !dgnTombMatedPairShared()
            || !dgnTombBeingCryptOfHonor()
            || !dgnTombOverflowDropsBonus()
            || !dgnTombFinalWordNotInside()
        )
            ++bad;
        // the Ward gold-piece table - the five clean bands: 1-100 pieces at
        // 1-50, 1-6 thousand at 61-70, 1-12 thousand at 71-80, 1-20 thousand
        // at 81-90, 2-40 thousand at 91-99; the 51-60 x2 row and the garbled
        // 100 row ride the transcript as scanned (folio 25)
        int CGd[5][2] = {
            {1,100},
            {1000,6000},
            {1000,12000},
            {1000,20000},
            {2000,40000},
            };
        for (int b = 0;
             b < dgnTombGoldBands();
             ++b) {
            int vals[2];
            vals[0] = dgnTombGoldPiecesMin(b);
            vals[1] = dgnTombGoldPiecesMax(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CGd[b][c])
                    ++bad;
            }
        }
        // the Ward gems table - seven bands: 1-6 base 100 at 1-50, 1-6 base
        // 500 at 51-60, 1-8 base 500 at 61-70, 1-12 base 500 at 71-80, 1-12
        // base 1,000 at 81-90, 1-6 base 5,000 at 91-99, 1-20 base 10,000 at
        // 100 with the re-roll (folio 25)
        int CGm[7][3] = {
            {1,6,100},
            {1,6,500},
            {1,8,500},
            {1,12,500},
            {1,12,1000},
            {1,6,5000},
            {1,20,10000},
            };
        for (int b = 0;
             b < dgnTombGemsBands();
             ++b) {
            int vals[3];
            vals[0] = dgnTombGemCountMin(b);
            vals[1] = dgnTombGemCountMax(b);
            vals[2] = dgnTombGemBaseValue(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CGm[b][c])
                    ++bad;
            }
        }
        // the Ward jewelry table - seven bands: 1-6 base 500 through 1-6 base
        // 30,000, the 1-20 base 50,000 row at 100 with the re-roll (folio 25)
        int CJw[7][3] = {
            {1,6,500},
            {1,6,1000},
            {1,6,5000},
            {1,6,10000},
            {1,6,20000},
            {1,6,30000},
            {1,20,50000},
            };
        for (int b = 0;
             b < dgnTombJewelryBands();
             ++b) {
            int vals[3];
            vals[0] = dgnTombJewelryCountMin(b);
            vals[1] = dgnTombJewelryCountMax(b);
            vals[2] = dgnTombJewelryBaseValue(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CJw[b][c])
                    ++bad;
            }
        }
        // the Ward misc-magic table - none at 1-60, the Greyhawk tables I
        // through V at 61-70, 71-80, 81-90, 91-99 and 100 with the re-roll
        // (folio 25)
        int CMm[6][1] = {
            {0},
            {1},
            {2},
            {3},
            {4},
            {5},
            };
        int nMm[1] = {0};
        int eMm[1] = {1};
        for (int b = 0;
             b < dgnTombMiscMagicBands();
             ++b) {
            int vals[1];
            vals[0] = dgnTombMiscMagicTable(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CMm[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nMm[c];
            }
        }
        for (int c = 0; c < 1; ++c)
            if (nMm[c] != eMm[c])
                ++bad;
        // the Ward tomb-structure grid - seven bands: the 1 room/cave/mound,
        // the hall with its spring trap, the 2-6 room complex, the 1-10 rooms
        // with 1-10 traps, the 1-10 rooms with 2-20 traps, the connecting
        // rooms with magical guards, the 1-20 room special-word tomb; the
        // unstated trap counts ride prose, sentinel -1 (folio 25)
        int CTi[7][4] = {
            {1,1,-1,-1},
            {1,1,1,1},
            {2,6,-1,-1},
            {1,10,1,10},
            {1,10,2,20},
            {1,10,-1,-1},
            {1,20,-1,-1},
            };
        int nTi[4] = {0,0,0,0};
        int eTi[4] = {0,0,4,4};
        for (int b = 0;
             b < dgnTombItselfBands();
             ++b) {
            int vals[4];
            vals[0] = dgnTombItselfRoomsMin(b);
            vals[1] = dgnTombItselfRoomsMax(b);
            vals[2] = dgnTombItselfTrapsMin(b);
            vals[3] = dgnTombItselfTrapsMax(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CTi[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nTi[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nTi[c] != eTi[c])
                ++bad;
        // the dgnTombMapBand band-for boundaries
    if (dgnTombMapBand(79) != 0
            || dgnTombMapBand(80) != 0
            || dgnTombMapBand(81) != 1
        )
            ++bad;
        // the dgnTombSpecialBand band-for boundaries
    if (dgnTombSpecialBand(84) != 0
            || dgnTombSpecialBand(85) != 0
            || dgnTombSpecialBand(86) != 1
        )
            ++bad;
        // the dgnTombGuardianBand band-for boundaries
    if (dgnTombGuardianBand(29) != 0
            || dgnTombGuardianBand(30) != 0
            || dgnTombGuardianBand(50) != 1
            || dgnTombGuardianBand(31) != 1
            || dgnTombGuardianBand(80) != 2
            || dgnTombGuardianBand(51) != 2
            || dgnTombGuardianBand(99) != 3
            || dgnTombGuardianBand(81) != 3
            || dgnTombGuardianBand(100) != 4
        )
            ++bad;
        // the dgnTombItselfBand band-for boundaries
    if (dgnTombItselfBand(39) != 0
            || dgnTombItselfBand(40) != 0
            || dgnTombItselfBand(50) != 1
            || dgnTombItselfBand(41) != 1
            || dgnTombItselfBand(60) != 2
            || dgnTombItselfBand(51) != 2
            || dgnTombItselfBand(80) != 3
            || dgnTombItselfBand(61) != 3
            || dgnTombItselfBand(90) != 4
            || dgnTombItselfBand(81) != 4
            || dgnTombItselfBand(99) != 5
            || dgnTombItselfBand(91) != 5
            || dgnTombItselfBand(100) != 6
        )
            ++bad;
        // the tomb census - the d12 occupant, the nine item rolls, the
        // overflow 100 and the floor 01 (folio 25)
    if (dgnTombOccupantTypes() != 12
            || dgnTombItemRolls() != 9
            || dgnTombOverflowCeiling() != 100
            || dgnTombFloorRoll() != 1
        )
            ++bad;
        // the table band census - five gold, seven gems, seven jewelry, six
        // misc-magic, seven structure bands (folio 25)
    if (dgnTombGoldBands() != 5
            || dgnTombGemsBands() != 7
            || dgnTombJewelryBands() != 7
            || dgnTombMiscMagicBands() != 6
            || dgnTombItselfBands() != 7
        )
            ++bad;
        // the guardian stalkers 1-4 and the 1-20 corridor band (folio 25)
    if (dgnGuardianStalkerMin() != 1
            || dgnGuardianStalkerMax() != 4
            || dgnTombCorridorsMin() != 1
            || dgnTombCorridorsMax() != 20
        )
            ++bad;
        // the maps and special-item band boundaries (folio 25)
    if (dgnTombMapBand(80) != 0
            || dgnTombMapBand(81) != 1
            || dgnTombSpecialBand(85) != 0
            || dgnTombSpecialBand(86) != 1
        )
            ++bad;
        // the gold-piece table - 1-100 pieces at the bottom, 2-40 thousand at
        // the top (folio 25)
    if (dgnTombGoldPiecesMin(0) != 1
            || dgnTombGoldPiecesMax(0) != 100
            || dgnTombGoldPiecesMin(1) != 1000
            || dgnTombGoldPiecesMax(4) != 40000
        )
            ++bad;
        // the gems table - 1-8 base 500 at 61-70, base 5,000 and 10,000 at
        // the top (folio 25)
    if (dgnTombGemCountMin(2) != 1
            || dgnTombGemCountMax(2) != 8
            || dgnTombGemBaseValue(5) != 5000
            || dgnTombGemBaseValue(6) != 10000
        )
            ++bad;
        // the jewelry table - base 500 at the bottom, 1-20 base 50,000 at the
        // 100 row (folio 25)
    if (dgnTombJewelryBaseValue(0) != 500
            || dgnTombJewelryBaseValue(6) != 50000
            || dgnTombJewelryCountMax(6) != 20
        )
            ++bad;
        // the misc-magic table - none then the Greyhawk tables I through V
        // (folio 25)
    if (dgnTombMiscMagicTable(0) != 0
            || dgnTombMiscMagicTable(1) != 1
            || dgnTombMiscMagicTable(5) != 5
        )
            ++bad;
        // the tomb-structure grid - the 2-6 room complex, the 2-20 trap band,
        // the 1-20 room tomb (folio 25)
    if (dgnTombItselfRoomsMin(2) != 2
            || dgnTombItselfRoomsMax(2) != 6
            || dgnTombItselfTrapsMin(4) != 2
            || dgnTombItselfTrapsMax(4) != 20
            || dgnTombItselfRoomsMax(6) != 20
        )
            ++bad;
        printf("R912 issue-9 opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
