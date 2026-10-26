    // ---- R867 known planes audit ----
    // APPENDIX 1: THE KNOWN PLANES OF EXISTENCE - the D&DG walk round
    // nineteen, print pp. 128-133: the inner planes, the ethereal and astral
    // travel-and-combat rules, the seventeen Outer Planes, the two encounter
    // tables, the Ether Cyclone, the psychic wind, the silver-cord doctrine
    // and the character subtable level bands; FIG. 4/5 remain the open
    // pixel-work box.
    {
        using namespace rules;
        int bad = 0;
    if (plnRound() != 867
            || plnPrintStart() != 128
            || plnPrintEnd() != 133
            || plnOutNineAlignments() != 9
            || plnOutBorderlineCount() != 8
            || plnOutSeventeenCount() != 17
            || plnAbyssLayers() != 666
            || plnCycPct() != 5
            || plnCycMoveRate() != 120
            || plnCycLostShortLo() != 5
            || plnCycLostShortHi() != 60
            || plnCycLostLongLo() != 10
            || plnCycLostLongHi() != 120
            || plnWindPct() != 5
            || plnWindLostShortLo() != 2
            || plnWindLostShortHi() != 20
            || plnWindLostLongLo() != 4
            || plnWindLostLongHi() != 40
            || plnSubPartyLo() != 1
            || plnSubPartyHi() != 6
            || plnSubClrLo() != 9
            || plnSubClrHi() != 18
            || plnSubDrdLo() != 7
            || plnSubDrdHi() != 14
            || plnSubFtrLo() != 8
            || plnSubFtrHi() != 15
            || plnSubPalLo() != 7
            || plnSubPalHi() != 16
            || plnSubRngLo() != 7
            || plnSubRngHi() != 16
            || plnSubMuLo() != 11
            || plnSubMuHi() != 20
            || plnSubIllLo() != 10
            || plnSubIllHi() != 17
            || plnSubThfLo() != 9
            || plnSubThfHi() != 16
            || plnSubAssLo() != 10
            || plnSubAssHi() != 15
            || plnSubMnkLo() != 8
            || plnSubMnkHi() != 17
            || plnSubBrdLo() != 11
            || plnSubBrdHi() != 18
            || plnSubBardFighterLo() != 7
            || plnSubBardFighterHi() != 8
            || plnSubBardThiefLo() != 6
            || plnSubBardThiefHi() != 9
            || plnSubBardThiefDie() != 4
            || plnSubBardThiefBonus() != 5
            || plnTableCount() != 8
            || plnChainCount() != 0
            || plnEtcRows() != 31
            || plnAtcRows() != 24
            || plnOutRows() != 17
            || plnCycRows() != 4
            || plnWndRows() != 4
            || plnIrtRows() != 13
            || plnRnoRows() != 18
            || plnPelRows() != 4
            || plnRosterCount() != 39
            || plnEncounterChance() != 20
            || plnChecksFirst() != 3
            || plnChecksSecond() != 2
            || plnChecksSubsequent() != 1
            || plnAsteriskCount() != 4
            || plnSubtableRowCount() != 11
            || plnElementalCount() != 4
            || plnParaElementalCount() != 4
            || plnNexialCount() != 4
            || plnLayersWordCount() != 8
            || plnDescriptorCount() != 4
            || plnFigCount() != 5
            || !plnPluralUniverses()
            || !plnOnlyNormalTied()
            || !plnParallelsNotShown()
            || !plnRealityRefereeDependent()
            || !plnPmpCenter()
            || !plnPmpHousesUniverse()
            || !plnPmpPlaneOfTerra()
            || !plnPmpBoundedByInner()
            || !plnPmpFourElements()
            || !plnPosEnergyLight()
            || !plnPosConsumePrime()
            || !plnNegAntiMatter()
            || !plnNegUncertainCreatures()
            || !plnNegDrainPrime()
            || !plnEleSurroundPmp()
            || !plnEleInfiniteEffect()
            || !plnEleApparentSizes()
            || !plnEleMoveViaPara()
            || !plnEleHomesOfCreatures()
            || !plnEleTrafficHeaviest()
            || !plnEleTravelGatesOrEthereal()
            || !plnNexialDeepestOcean()
            || !plnNexialHighAtmosphere()
            || !plnNexialFarUnderground()
            || !plnNexialActiveVolcano()
            || !plnNexialTemporary()
            || !plnParaAtConjunctions()
            || !plnParaHomes()
            || !plnEthSurroundsAll()
            || !plnEthInsubstantial()
            || !plnEthFloatingIslands()
            || !plnEthPhantoms()
            || !plnEthPassNoDifficulty()
            || !plnEthChillSpine()
            || !plnEthRealToEachOther()
            || !plnEthNotToOuter()
            || !plnShadCoExists()
            || !plnShadInteraction()
            || !plnShadNegDarkPosLight()
            || !plnShadMutableCreatures()
            || !plnAstRadiatesNonSpace()
            || !plnAstTravelUses()
            || !plnAstTouchesUpperOnly()
            || !plnFig1Inner()
            || !plnFig2Elemental()
            || !plnFig3Outer()
            || !plnFig45PixelWork()
            || !plnOutHomesOfDeities()
            || !plnOutExactCorrespondence()
            || !plnOutDegreeNotAbsolute()
            || !plnOutLeTendsGehenna()
            || !plnOutContactTopmost()
            || !plnOutAdjacentMoves()
            || !plnOutAbyssMoves()
            || !plnOutHadesMoves()
            || !plnSevenHeavensAbsLG()
            || !plnTwinParadisesLNG()
            || !plnElysiumLayersNG()
            || !plnHappyHuntingCGNG()
            || !plnOlympusLayersACG()
            || !plnGladsheimLayersNGC()
            || !plnLimboLayersChaos()
            || !plnPandemoniumLayersNEC()
            || !plnAbyssAbsCE()
            || !plnTarterusLayersNCE()
            || !plnHadesThreeGlooms()
            || !plnGehennaFurnacesNLE()
            || !plnNineHellsAbsLE()
            || !plnAcheronNetherNEL()
            || !plnNirvanaAbsLaw()
            || !plnArcadiaNGL()
            || !plnConcordantOfOpposition()
            || !plnEthStateByMeans()
            || !plnEthMoveInnerPlanes()
            || !plnEthPlaneToPlane()
            || !plnEthWillMovement()
            || !plnEthConcentrationHalts()
            || !plnEthTirelessRapid()
            || !plnEthNoNeeds()
            || !plnEthShadowToShadow()
            || !plnEthMentalTrail()
            || !plnEncUnfamiliarTriple()
            || !plnEncEvasionFaster()
            || !plnEncEvasionFamiliar()
            || !plnEncEvasionIntelligence()
            || !plnEncMentalFunction()
            || !plnCycInnerFluctuations()
            || !plnCycOnlyBetweenPlanes()
            || !plnCycSlowAddCheck()
            || !plnCycDifferentPlane()
            || !plnCycSaveSpells()
            || !plnEthCombatReal()
            || !plnEthCombatPartial()
            || !plnEthSpellsToPmp()
            || !plnEthDamageActual()
            || !plnAstPerceptionNote()
            || !plnAstBySpellsPsionics()
            || !plnAstTouchesSeventeen()
            || !plnAstNoInnerOther()
            || !plnAstClericalSpellRef()
            || !plnAstSpeedy()
            || !plnAstNoNeeds()
            || !plnAstConcentrateMove()
            || !plnAstLearnsTheWay()
            || !plnAstEvasionAsEthereal()
            || !plnWindUnknown()
            || !plnWindSlow()
            || !plnWindLostShort()
            || !plnWindDifferentDest()
            || !plnWindSaveMagic()
            || !plnWindLostLong()
            || !plnWindNoCord()
            || !plnAstCombatReal()
            || !plnAstNoPossessions()
            || !plnAstNaturalWeaponry()
            || !plnAstDestroyBodyMost()
            || !plnAstPowerfulSnap()
            || !plnInnerViaEthereal()
            || !plnOuterCantGoEthereal()
            || !plnGatesAvoidEthereal()
            || !plnGateBySpell()
            || !plnGateByItems()
            || !plnGateByDivine()
            || !plnNexialDirect()
            || !plnOuterViaGatesOrAstral()
            || !plnAstralEntryOnly()
            || !plnGatedComplete()
            || !plnProjectionLeavesBody()
            || !plnSilverCordKilled()
            || !plnOuterBodyForms()
            || !plnBothBodiesCorded()
            || !plnOuterKilledReturnPmp()
            || !plnCordSnapUnoccupiedDies()
            || !plnSubNoClassLimits()
            || !plnSubAlwaysCleric()
            || !plnSubMinMagicUser()
            || !plnSubBardFootnote()
        )
            ++bad;
        // the the ethereal encounter grid grid
        int CplnEtc[31][6] = {
            {0,1,4,1,1,0},
            {1,5,8,1,2,1},
            {2,9,11,1,4,1},
            {3,12,16,1,4,0},
            {4,17,23,1,6,0},
            {5,24,24,1,1,0},
            {6,25,25,1,1,0},
            {7,26,27,1,3,0},
            {8,28,32,1,1,0},
            {9,33,34,1,1,0},
            {10,35,36,1,1,0},
            {11,37,37,1,1,0},
            {12,38,42,1,1,0},
            {13,43,44,1,2,1},
            {14,45,46,1,2,0},
            {15,47,51,0,0,2},
            {16,52,53,1,2,0},
            {17,54,56,1,3,0},
            {18,57,61,1,1,0},
            {19,62,68,2,8,0},
            {20,69,70,1,2,1},
            {21,71,72,1,4,0},
            {22,73,74,2,5,0},
            {23,75,77,1,1,0},
            {24,78,81,1,6,0},
            {25,82,88,1,3,0},
            {26,89,89,1,1,0},
            {27,90,92,1,1,0},
            {28,93,94,1,1,0},
            {29,95,97,2,5,0},
            {30,98,100,3,6,0},
            };
        for (int b = 0;
             b < plnEtcRows();
             ++b) {
            int vals[6];
            vals[0] = plnEtcOrd(b);
            vals[1] = plnEtcLow(b);
            vals[2] = plnEtcHigh(b);
            vals[3] = plnEtcNumLo(b);
            vals[4] = plnEtcNumHi(b);
            vals[5] = plnEtcFlag(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CplnEtc[b][c])
                    ++bad;
            }
        }
        // the the astral encounter grid grid
        int CplnAtc[24][6] = {
            {0,1,4,1,1,0},
            {1,5,10,1,2,1},
            {2,11,13,1,4,1},
            {31,14,16,1,1,0},
            {32,17,22,1,3,0},
            {33,23,23,1,1,0},
            {34,24,24,1,1,0},
            {35,25,28,1,1,0},
            {36,29,37,1,3,0},
            {5,38,38,1,1,0},
            {6,39,39,1,1,0},
            {13,40,41,1,2,1},
            {15,42,46,0,0,2},
            {16,47,49,1,2,0},
            {17,50,55,1,3,0},
            {18,56,61,1,1,0},
            {20,62,63,1,2,1},
            {37,64,71,1,4,0},
            {21,72,74,1,4,0},
            {38,75,79,1,3,0},
            {23,80,91,2,5,0},
            {26,92,92,1,1,0},
            {27,93,97,1,1,0},
            {28,98,100,1,1,0},
            };
        for (int b = 0;
             b < plnAtcRows();
             ++b) {
            int vals[6];
            vals[0] = plnAtcOrd(b);
            vals[1] = plnAtcLow(b);
            vals[2] = plnAtcHigh(b);
            vals[3] = plnAtcNumLo(b);
            vals[4] = plnAtcNumHi(b);
            vals[5] = plnAtcFlag(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CplnAtc[b][c])
                    ++bad;
            }
        }
        // the the outer planes grid grid
        int CplnOut[17][3] = {
            {1,0,0},
            {2,0,0},
            {3,1,0},
            {4,0,0},
            {5,1,0},
            {6,1,0},
            {7,1,0},
            {8,1,0},
            {9,1,1},
            {10,1,0},
            {11,0,2},
            {12,0,3},
            {13,0,0},
            {14,1,4},
            {15,0,0},
            {16,0,0},
            {17,0,0},
            };
        for (int b = 0;
             b < plnOutRows();
             ++b) {
            int vals[3];
            vals[0] = plnOutPos(b);
            vals[1] = plnOutLayers(b);
            vals[2] = plnOutDesc(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CplnOut[b][c])
                    ++bad;
            }
        }
        // the the cyclone grid grid
        int CplnCyc[4][3] = {
            {1,10,1},
            {11,15,2},
            {16,18,3},
            {19,20,4},
            };
        for (int b = 0;
             b < plnCycRows();
             ++b) {
            int vals[3];
            vals[0] = plnCycLow(b);
            vals[1] = plnCycHigh(b);
            vals[2] = plnCycEffect(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CplnCyc[b][c])
                    ++bad;
            }
        }
        // the the wind grid grid
        int CplnWnd[4][3] = {
            {1,12,1},
            {13,16,2},
            {17,19,3},
            {20,20,4},
            };
        for (int b = 0;
             b < plnWndRows();
             ++b) {
            int vals[3];
            vals[0] = plnWndLow(b);
            vals[1] = plnWndHigh(b);
            vals[2] = plnWndEffect(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CplnWnd[b][c])
                    ++bad;
            }
        }
        // the the inner random grid grid
        int CplnIrt[13][3] = {
            {1,2,0},
            {3,3,1},
            {4,4,2},
            {5,7,3},
            {8,9,4},
            {10,11,5},
            {12,13,6},
            {14,14,7},
            {15,15,8},
            {16,16,9},
            {17,17,10},
            {18,19,11},
            {20,20,12},
            };
        for (int b = 0;
             b < plnIrtRows();
             ++b) {
            int vals[3];
            vals[0] = plnIrtLow(b);
            vals[1] = plnIrtHigh(b);
            vals[2] = plnIrtPlane(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CplnIrt[b][c])
                    ++bad;
            }
        }
        // the the outer random grid grid
        int CplnRno[18][3] = {
            {1,3,0},
            {4,4,1},
            {5,5,2},
            {6,6,3},
            {7,7,4},
            {8,8,5},
            {9,9,6},
            {10,10,7},
            {11,11,8},
            {12,12,9},
            {13,13,10},
            {14,14,11},
            {15,15,12},
            {16,16,13},
            {17,17,14},
            {18,18,15},
            {19,19,16},
            {20,20,17},
            };
        for (int b = 0;
             b < plnRnoRows();
             ++b) {
            int vals[3];
            vals[0] = plnRnoLow(b);
            vals[1] = plnRnoHigh(b);
            vals[2] = plnRnoPlane(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CplnRno[b][c])
                    ++bad;
            }
        }
        // the the para-elemental grid grid
        int CplnPel[4][3] = {
            {0,0,3},
            {1,0,2},
            {2,2,1},
            {3,1,3},
            };
        for (int b = 0;
             b < plnPelRows();
             ++b) {
            int vals[3];
            vals[0] = plnPelOrd(b);
            vals[1] = plnPelElemA(b);
            vals[2] = plnPelElemB(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CplnPel[b][c])
                    ++bad;
            }
        }
        // the census walk (the eight grids, the row counts, the roster, the
        // outer-plane counts)
    if (plnRound() != 867
            || plnTableCount() != 8
            || plnChainCount() != 0
            || plnEtcRows() != 31
            || plnAtcRows() != 24
            || plnOutRows() != 17
            || plnCycRows() != 4
            || plnWndRows() != 4
            || plnIrtRows() != 13
            || plnRnoRows() != 18
            || plnPelRows() != 4
            || plnRosterCount() != 39
            || plnOutNineAlignments() != 9
            || plnOutBorderlineCount() != 8
            || plnOutSeventeenCount() != 17
            || plnAsteriskCount() != 4
            || plnElementalCount() != 4
            || plnParaElementalCount() != 4
            || plnNexialCount() != 4
            || plnLayersWordCount() != 8
            || plnDescriptorCount() != 4
            || plnFigCount() != 5
        )
            ++bad;
        // the ethereal encounter grid bands (the head and tail rows, the band
        // tiling to 100)
    if (plnEtcLow(0) != 1
            || plnEtcHigh(0) != 4
            || plnEtcLow(30) != 98
            || plnEtcHigh(30) != 100
            || plnEtcLow(15) != 47
            || plnEtcHigh(15) != 51
            || plnEtcOrd(19) != 19
            || plnEtcHigh(3) != 16
            || plnEtcLow(26) != 89
            || plnEtcHigh(26) != 89
        )
            ++bad;
        // the ethereal encounter numbers and flags (the xorn, the lammasu,
        // the asterisks, the subtable row)
    if (plnEtcNumLo(30) != 3
            || plnEtcNumHi(30) != 6
            || plnEtcNumLo(19) != 2
            || plnEtcNumHi(19) != 8
            || plnEtcNumHi(9) != 1
            || plnEtcFlag(1) != 1
            || plnEtcFlag(20) != 1
            || plnEtcFlag(15) != 2
            || plnEtcNumLo(15) != 0
            || plnEtcFlag(22) != 0
        )
            ++bad;
        // the astral encounter grid (the demons and devils, the night hag
        // band, the titan rows)
    if (plnAtcOrd(3) != 31
            || plnAtcOrd(4) != 32
            || plnAtcOrd(6) != 34
            || plnAtcOrd(8) != 36
            || plnAtcLow(17) != 64
            || plnAtcHigh(17) != 71
            || plnAtcOrd(17) != 37
            || plnAtcHigh(20) != 91
            || plnAtcLow(22) != 93
            || plnAtcHigh(22) != 97
            || plnAtcOrd(23) != 28
            || plnAtcHigh(23) != 100
        )
            ++bad;
        // the astral encounter numbers and flags (the shedu 2-5, the
        // rakshasa, the asterisk rows)
    if (plnAtcNumLo(20) != 2
            || plnAtcNumHi(20) != 5
            || plnAtcNumLo(19) != 1
            || plnAtcNumHi(19) != 3
            || plnAtcNumHi(21) != 1
            || plnAtcNumHi(23) != 1
            || plnAtcFlag(1) != 1
            || plnAtcFlag(11) != 1
            || plnAtcFlag(12) != 2
        )
            ++bad;
        // the seventeen outer planes grid (the positions, the layers words,
        // the descriptors)
    if (plnOutPos(0) != 1
            || plnOutPos(16) != 17
            || plnOutLayers(2) != 1
            || plnOutLayers(4) != 1
            || plnOutLayers(8) != 1
            || plnOutLayers(13) != 1
            || plnOutDesc(8) != 1
            || plnAbyssLayers() != 666
            || plnOutDesc(10) != 2
            || plnOutDesc(11) != 3
            || plnOutDesc(13) != 4
            || plnOutDesc(0) != 0
        )
            ++bad;
        // the cyclone and wind grids (the dice bands, the effect codes)
    if (plnCycLow(0) != 1
            || plnCycHigh(0) != 10
            || plnCycLow(1) != 11
            || plnCycHigh(1) != 15
            || plnCycLow(2) != 16
            || plnCycHigh(3) != 20
            || plnCycEffect(0) != 1
            || plnCycEffect(3) != 4
            || plnWndLow(0) != 1
            || plnWndHigh(0) != 12
            || plnWndLow(1) != 13
            || plnWndHigh(1) != 16
            || plnWndLow(3) != 20
            || plnWndEffect(3) != 4
        )
            ++bad;
        // the inner random grid (the band arithmetic, the fold-garbled bands)
    if (plnIrtLow(0) != 1
            || plnIrtHigh(0) != 2
            || plnIrtPlane(0) != 0
            || plnIrtPlane(1) != 1
            || plnIrtPlane(2) != 2
            || plnIrtLow(3) != 5
            || plnIrtHigh(3) != 7
            || plnIrtPlane(3) != 3
            || plnIrtLow(4) != 8
            || plnIrtHigh(4) != 9
            || plnIrtLow(5) != 10
            || plnIrtHigh(5) != 11
            || plnIrtPlane(12) != 12
            || plnIrtHigh(12) != 20
        )
            ++bad;
        // the outer random grid (the astral triple band, the single-plane
        // bands, the tail)
    if (plnRnoLow(0) != 1
            || plnRnoHigh(0) != 3
            || plnRnoPlane(0) != 0
            || plnRnoPlane(1) != 1
            || plnRnoHigh(9) != 12
            || plnRnoPlane(9) != 9
            || plnRnoPlane(13) != 13
            || plnRnoPlane(17) != 17
            || plnRnoHigh(17) != 20
            || plnRnoLow(17) != 20
        )
            ++bad;
        // the para-elemental grid (the conjunctions: ice, dust, heat, vapor)
    if (plnPelOrd(0) != 0
            || plnPelElemA(0) != 0
            || plnPelElemB(0) != 3
            || plnPelElemA(1) != 0
            || plnPelElemB(1) != 2
            || plnPelElemA(2) != 2
            || plnPelElemB(2) != 1
            || plnPelElemA(3) != 1
            || plnPelElemB(3) != 3
        )
            ++bad;
        // the inner planes doctrine (the center, the elements, the positive
        // and negative)
    if (plnPmpCenter() != 1
            || plnPmpFourElements() != 1
            || plnPosConsumePrime() != 1
            || plnNegDrainPrime() != 1
            || plnNegUncertainCreatures() != 1
            || plnEleSurroundPmp() != 1
            || plnEleInfiniteEffect() != 1
            || plnEleMoveViaPara() != 1
            || plnEleTrafficHeaviest() != 1
            || plnPluralUniverses() != 1
            || plnOnlyNormalTied() != 1
            || plnPmpHousesUniverse() != 1
            || plnRealityRefereeDependent() != 1
        )
            ++bad;
        // the nexial points (the four locations plus the temporary openings)
    if (plnNexialDeepestOcean() != 1
            || plnNexialHighAtmosphere() != 1
            || plnNexialFarUnderground() != 1
            || plnNexialActiveVolcano() != 1
            || plnNexialTemporary() != 1
            || plnEleTravelGatesOrEthereal() != 1
            || plnParaAtConjunctions() != 1
            || plnParaHomes() != 1
        )
            ++bad;
        // the ethereal plane and the plane of shadow
    if (plnEthSurroundsAll() != 1
            || plnEthInsubstantial() != 1
            || plnEthFloatingIslands() != 1
            || plnEthPhantoms() != 1
            || plnEthPassNoDifficulty() != 1
            || plnEthChillSpine() != 1
            || plnEthRealToEachOther() != 1
            || plnEthNotToOuter() != 1
            || plnShadCoExists() != 1
            || plnShadInteraction() != 1
            || plnShadNegDarkPosLight() != 1
            || plnShadMutableCreatures() != 1
        )
            ++bad;
        // the astral plane and the outer-planes overview (the degree
        // doctrine, the adjacency moves)
    if (plnAstRadiatesNonSpace() != 1
            || plnAstTravelUses() != 1
            || plnAstTouchesUpperOnly() != 1
            || plnOutHomesOfDeities() != 1
            || plnOutExactCorrespondence() != 1
            || plnOutDegreeNotAbsolute() != 1
            || plnOutLeTendsGehenna() != 1
            || plnOutContactTopmost() != 1
            || plnOutAdjacentMoves() != 1
            || plnOutAbyssMoves() != 1
            || plnOutHadesMoves() != 1
        )
            ++bad;
        // the seventeen list (the heavens through the concordant opposition)
    if (plnSevenHeavensAbsLG() != 1
            || plnTwinParadisesLNG() != 1
            || plnElysiumLayersNG() != 1
            || plnHappyHuntingCGNG() != 1
            || plnOlympusLayersACG() != 1
            || plnGladsheimLayersNGC() != 1
            || plnLimboLayersChaos() != 1
            || plnPandemoniumLayersNEC() != 1
            || plnAbyssAbsCE() != 1
            || plnTarterusLayersNCE() != 1
            || plnHadesThreeGlooms() != 1
            || plnGehennaFurnacesNLE() != 1
            || plnNineHellsAbsLE() != 1
            || plnAcheronNetherNEL() != 1
            || plnNirvanaAbsLaw() != 1
            || plnArcadiaNGL() != 1
            || plnConcordantOfOpposition() != 1
        )
            ++bad;
        // the ethereal travel and encounter rules (the checks ladder, the
        // evasion laws, the cyclone)
    if (plnEncounterChance() != 20
            || plnChecksFirst() != 3
            || plnChecksSecond() != 2
            || plnChecksSubsequent() != 1
            || plnEncUnfamiliarTriple() != 1
            || plnEncEvasionFaster() != 1
            || plnEncEvasionIntelligence() != 1
            || plnEncMentalFunction() != 1
            || plnCycPct() != 5
            || plnCycMoveRate() != 120
            || plnCycLostShortLo() != 5
            || plnCycLostShortHi() != 60
            || plnCycLostLongLo() != 10
            || plnCycLostLongHi() != 120
        )
            ++bad;
        // the ethereal travel means and combat (the state, the will movement,
        // the actual damage)
    if (plnEthStateByMeans() != 1
            || plnEthMoveInnerPlanes() != 1
            || plnEthWillMovement() != 1
            || plnEthConcentrationHalts() != 1
            || plnEthTirelessRapid() != 1
            || plnEthNoNeeds() != 1
            || plnEthShadowToShadow() != 1
            || plnEthMentalTrail() != 1
            || plnEthCombatReal() != 1
            || plnEthCombatPartial() != 1
            || plnEthSpellsToPmp() != 1
            || plnEthDamageActual() != 1
            || plnAstPerceptionNote() != 1
        )
            ++bad;
        // the astral travel and the psychic wind (the wind constants, the
        // cord rule)
    if (plnAstBySpellsPsionics() != 1
            || plnAstTouchesSeventeen() != 1
            || plnAstNoInnerOther() != 1
            || plnAstSpeedy() != 1
            || plnAstConcentrateMove() != 1
            || plnAstLearnsTheWay() != 1
            || plnWindPct() != 5
            || plnWindUnknown() != 1
            || plnWindLostShortLo() != 2
            || plnWindLostShortHi() != 20
            || plnWindLostLongLo() != 4
            || plnWindLostLongHi() != 40
            || plnWindSaveMagic() != 1
            || plnWindNoCord() != 1
            || plnWindSlow() != 1
            || plnWindDifferentDest() != 1
        )
            ++bad;
        // the astral combat (the possessions rule, the cord return, the
        // powerful snap)
    if (plnAstCombatReal() != 1
            || plnAstNoPossessions() != 1
            || plnAstNaturalWeaponry() != 1
            || plnAstDestroyBodyMost() != 1
            || plnAstPowerfulSnap() != 1
            || plnAstEvasionAsEthereal() != 1
            || plnAstClericalSpellRef() != 1
            || plnAstNoNeeds() != 1
        )
            ++bad;
        // the planar travel summary (the gates, the silver cord, the two
        // bodies)
    if (plnInnerViaEthereal() != 1
            || plnOuterCantGoEthereal() != 1
            || plnGatesAvoidEthereal() != 1
            || plnGateBySpell() != 1
            || plnGateByItems() != 1
            || plnGateByDivine() != 1
            || plnNexialDirect() != 1
            || plnOuterViaGatesOrAstral() != 1
            || plnAstralEntryOnly() != 1
            || plnGatedComplete() != 1
            || plnProjectionLeavesBody() != 1
            || plnSilverCordKilled() != 1
            || plnOuterBodyForms() != 1
            || plnBothBodiesCorded() != 1
            || plnOuterKilledReturnPmp() != 1
            || plnCordSnapUnoccupiedDies() != 1
        )
            ++bad;
        // the character subtable levels (the eleven class bands)
    if (plnSubClrLo() != 9
            || plnSubClrHi() != 18
            || plnSubDrdLo() != 7
            || plnSubDrdHi() != 14
            || plnSubFtrLo() != 8
            || plnSubFtrHi() != 15
            || plnSubPalLo() != 7
            || plnSubPalHi() != 16
            || plnSubRngLo() != 7
            || plnSubRngHi() != 16
            || plnSubMuLo() != 11
            || plnSubMuHi() != 20
            || plnSubIllLo() != 10
            || plnSubIllHi() != 17
            || plnSubThfLo() != 9
            || plnSubThfHi() != 16
            || plnSubAssLo() != 10
            || plnSubAssHi() != 15
            || plnSubMnkLo() != 8
            || plnSubMnkHi() != 17
            || plnSubBrdLo() != 11
            || plnSubBrdHi() != 18
            || plnSubtableRowCount() != 11
        )
            ++bad;
        // the character subtable rules and the bard footnote (the garbled
        // print cells)
    if (plnSubPartyLo() != 1
            || plnSubPartyHi() != 6
            || plnSubNoClassLimits() != 1
            || plnSubAlwaysCleric() != 1
            || plnSubMinMagicUser() != 1
            || plnSubBardFootnote() != 1
            || plnSubBardFighterLo() != 7
            || plnSubBardFighterHi() != 8
            || plnSubBardThiefLo() != 6
            || plnSubBardThiefHi() != 9
            || plnSubBardThiefDie() != 4
            || plnSubBardThiefBonus() != 5
        )
            ++bad;
        // the figure pins (FIG. 1 through 5, the pixel-work box note)
    if (plnFig1Inner() != 1
            || plnFig2Elemental() != 1
            || plnFig3Outer() != 1
            || plnFig45PixelWork() != 1
            || plnEleApparentSizes() != 1
        )
            ++bad;
        printf("R867 known planes audit: bad %d\n", bad);
        if (bad) return 1;
    }
