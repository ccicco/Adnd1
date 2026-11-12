    // ---- R910 issue-8 opener audit ----
    // THE DRAGON ISSUE-8 OPENER ROUND - three adjudicated chains. The Gygax
    // Planes article (folios 4-5): the planar census, the travel split and
    // restrictions, and the planar-existence law for weapons and
    // special-metal creatures. The Watson towns article (folios 5-7): the
    // town chances, services and fees, Falgrave's and the three-floor
    // doctrine. The Kuntz gems re-evaluation (folios 22-23): the carat,
    // basic-value, metal, gem-count and jewelry-type substitution tables with
    // the AS-SCANNED garbles noted.
    {
        using namespace rules;
        int bad = 0;
    if (dgoInnerPlanesCount() != 7
            || dgoOuterPlanesCount() != 16
            || dgoSevenHeavensLevels() != 7
            || dgoNineHellsLayers() != 9
            || dgoAbyssLayers() != 666
            || dgoCreaturePlanesAtPlus1() != 2
            || dgoCreaturePlanesAtPlus2() != 3
            || dgoWeaponPlanesPerPlus() != 1
            || dgoWalkAdjacentPlanes() != 1
            || dgoPawnshopDefectiveChance() != 6
            || dgoCartographerMapMin() != 100
            || dgoCartographerMapMax() != 600
            || dgoBarberFeeGp() != 1
            || dgoStableBoardMin() != 2
            || dgoStableBoardMax() != 3
            || dgoForeignMerchantChance() != 4
            || dgoThievesQuarterEncounter() != 8
            || dgoSoothsayerFeeGp() != 20
            || dgoMagicianFeePerLevel() != 50
            || dgoBrothelFeeGp() != 20
            || dgoBrothelInfoBribeMin() != 10
            || dgoBrothelInfoBribeMax() != 100
            || dgoBrothelPatronsMin() != 1
            || dgoBrothelPatronsMax() != 6
            || dgoSurgeonWoundFeeGp() != 25
            || dgoSurgeonWoundCureMin() != 1
            || dgoSurgeonWoundCureMax() != 6
            || dgoSurgeonPoisonFeeGp() != 35
            || dgoSurgeonPoisonChance() != 6
            || dgoSurgeonWoundSuccessPct() != 50
            || dgoLibraryBaseFeeGp() != 100
            || dgoFalgravePatronsMin() != 3
            || dgoFalgravePatronsMax() != 18
            || dgoFalgraveWayfarersMin() != 1
            || dgoFalgraveWayfarersMax() != 4
            || dgoMaxFloors() != 3
            || dgoGemACaratCount() != 11
            || dgoGemBValueCount() != 10
            || dgoGemDMetalCount() != 10
            || dgoGemECountCount() != 7
            || dgoGemFTypeCount() != 15
            || !dgoEtherealReachesInner()
            || !dgoAstralReachesOuter()
            || !dgoAstralFromPrimeOnly()
            || !dgoAstralNotFromInner()
            || !dgoAstralFirstLevelOnly()
            || !dgoSpecialMetalCreaturesDualPlanar()
            || !dgoMagicWeaponAttacksAcrossPlanes()
            || !dgoWeaponLosesMagicBeyondLimit()
            || !dgoSwordOfSharpnessSpecialCase()
            || !dgoTownLayoutSharesDungeonScale()
            || !dgoTownWalledOnBorder()
            || !dgoKeepHousesTheLord()
            || !dgoFalgraveNonhumanThirds()
            || !dgoSurgeonOneAttemptPerDay()
            || !dgoMarketRumorMill()
        )
            ++bad;
        // the Kuntz carat determination table - eleven percentile bands from
        // 1 carat to the 100-carat 00 row, the asterisked rows re-rolled
        // 86-98 as 100-300, 99 as 200-500, 00 as 500-1,000 carats (folio 22)
        int CGmA[11][2] = {
            {1,1},
            {2,2},
            {3,3},
            {4,4},
            {5,5},
            {6,9},
            {10,10},
            {20,50},
            {20,70},
            {30,80},
            {100,100},
            };
        for (int b = 0;
             b < dgoGemACaratCount();
             ++b) {
            int vals[2];
            vals[0] = dgoGemACaratMin(b);
            vals[1] = dgoGemACaratMax(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CGmA[b][c])
                    ++bad;
            }
        }
        // the Kuntz gems basic values table - ten percentile bands at 10 to
        // 200 gold pieces per carat (folio 22)
        int CGmB[10][1] = {
            {10},
            {20},
            {25},
            {50},
            {75},
            {100},
            {125},
            {150},
            {175},
            {200},
            };
        for (int b = 0;
             b < dgoGemBValueCount();
             ++b) {
            int vals[1];
            vals[0] = dgoGemBValueGp(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CGmB[b][c])
                    ++bad;
            }
        }
        // the Kuntz jewelry composition metal table - bronze through mithril
        // plus platinum filigree, ten bands from 10-40 to 2,000-5,000 gold
        // pieces (folio 23)
        int CGmD[10][2] = {
            {10,40},
            {20,80},
            {100,400},
            {500,1000},
            {500,1500},
            {1000,2000},
            {1000,3000},
            {1000,4000},
            {1500,4500},
            {2000,5000},
            };
        for (int b = 0;
             b < dgoGemDMetalCount();
             ++b) {
            int vals[2];
            vals[0] = dgoGemDMetalMin(b);
            vals[1] = dgoGemDMetalMax(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CGmD[b][c])
                    ++bad;
            }
        }
        // the Kuntz jewelry composition table - seven percentile bands of gem
        // counts with the carat caps and at-least minimums as printed (folio
        // 23)
        int CGmE[7][3] = {
            {2,12,5},
            {3,18,10},
            {3,36,20},
            {2,20,0},
            {3,24,5},
            {3,30,10},
            {10,40,20},
            };
        for (int b = 0;
             b < dgoGemECountCount();
             ++b) {
            int vals[3];
            vals[0] = dgoGemEGemsMin(b);
            vals[1] = dgoGemEGemsMax(b);
            vals[2] = dgoGemECaratCap(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CGmE[b][c])
                    ++bad;
            }
        }
        // the Kuntz jewelry types table - fifteen die bands, the type names
        // riding the transcript and this comment: rings, bracers, bracelets,
        // chalices, cups, tankards, earrings, necklaces, tableware,
        // candelabra, anklets, neckbands, mirrors, snuff boxes, statuettes
        // (folio 23)
        int CGmF[15][2] = {
            {1,10},
            {11,20},
            {21,25},
            {26,30},
            {31,35},
            {36,40},
            {41,50},
            {51,60},
            {61,70},
            {71,75},
            {76,80},
            {81,85},
            {86,90},
            {91,95},
            {96,100},
            };
        for (int b = 0;
             b < dgoGemFTypeCount();
             ++b) {
            int vals[2];
            vals[0] = dgoGemFBandMin(b);
            vals[1] = dgoGemFBandMax(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CGmF[b][c])
                    ++bad;
            }
        }
        // the planar census - seven inner, sixteen outer, seven levels in the
        // Seven Heavens, nine layers of the Hells, the 666 layers of the
        // Abyss (folios 4-5)
    if (dgoInnerPlanesCount() != 7
            || dgoOuterPlanesCount() != 16
            || dgoSevenHeavensLevels() != 7
            || dgoNineHellsLayers() != 9
            || dgoAbyssLayers() != 666
        )
            ++bad;
        // the planar-existence law - a +1-only creature in two planes, a +2
        // in three, weapons removed one plane per plus, walking one plane to
        // either side (folios 4-5)
    if (dgoCreaturePlanesAtPlus1() != 2
            || dgoCreaturePlanesAtPlus2() != 3
            || dgoWeaponPlanesPerPlus() != 1
            || dgoWalkAdjacentPlanes() != 1
        )
            ++bad;
        // the planar doctrines - the ethereal/astral split, the astral
        // restrictions, the dual-planar special-metal creatures, the
        // cross-plane weapon attacks, the plane-removal law, the sharpness
        // and vorpal special cases (folios 4-5)
    if (dgoEtherealReachesInner() != 1
            || dgoAstralReachesOuter() != 1
            || dgoAstralFromPrimeOnly() != 1
            || dgoAstralNotFromInner() != 1
            || dgoAstralFirstLevelOnly() != 1
            || dgoSpecialMetalCreaturesDualPlanar() != 1
            || dgoMagicWeaponAttacksAcrossPlanes() != 1
            || dgoWeaponLosesMagicBeyondLimit() != 1
            || dgoSwordOfSharpnessSpecialCase() != 1
        )
            ++bad;
        // the town chances - the 1-in-6 defective pawnshop, the 1-in-4
        // foreign merchants, the 1-in-8 thieves' quarter encounter per turn
        // (folios 5-6)
    if (dgoPawnshopDefectiveChance() != 6
            || dgoForeignMerchantChance() != 4
            || dgoThievesQuarterEncounter() != 8
        )
            ++bad;
        // the town services - the 100-600 gp maps, the 1 gp barber, the 2-3
        // gp weekly stable (folios 5-6)
    if (dgoCartographerMapMin() != 100
            || dgoCartographerMapMax() != 600
            || dgoBarberFeeGp() != 1
            || dgoStableBoardMin() != 2
            || dgoStableBoardMax() != 3
        )
            ++bad;
        // the dark side of town - the 20 gp soothsayer, the 50 gp per level
        // magician, the 20 gp brothel with its 10-100 gp information bribes
        // and 1-6 patrons (folio 6)
    if (dgoSoothsayerFeeGp() != 20
            || dgoMagicianFeePerLevel() != 50
            || dgoBrothelFeeGp() != 20
            || dgoBrothelInfoBribeMin() != 10
            || dgoBrothelInfoBribeMax() != 100
            || dgoBrothelPatronsMin() != 1
            || dgoBrothelPatronsMax() != 6
        )
            ++bad;
        // the surgeon - 25 gp for the 1-6 wound-point cure at 50 percent, 35
        // gp for the 1-in-6 poison cure, one attempt per day and one success
        // per week (folio 7)
    if (dgoSurgeonWoundFeeGp() != 25
            || dgoSurgeonWoundCureMin() != 1
            || dgoSurgeonWoundCureMax() != 6
            || dgoSurgeonPoisonFeeGp() != 35
            || dgoSurgeonPoisonChance() != 6
            || dgoSurgeonWoundSuccessPct() != 50
            || dgoSurgeonOneAttemptPerDay() != 1
        )
            ++bad;
        // the library at 100 gp base and Falgrave's - 3-18 patrons, two
        // thirds non-human, half of those warriors, 1-4 wayfarers (folio 7)
    if (dgoLibraryBaseFeeGp() != 100
            || dgoFalgravePatronsMin() != 3
            || dgoFalgravePatronsMax() != 18
            || dgoFalgraveWayfarersMin() != 1
            || dgoFalgraveWayfarersMax() != 4
            || dgoFalgraveNonhumanThirds() != 1
        )
            ++bad;
        // the town doctrines - the three-floor limit, the shared dungeon
        // scale, the border walls, the keep, the rumor mill (folios 5-6)
    if (dgoMaxFloors() != 3
            || dgoTownLayoutSharesDungeonScale() != 1
            || dgoTownWalledOnBorder() != 1
            || dgoKeepHousesTheLord() != 1
            || dgoMarketRumorMill() != 1
        )
            ++bad;
        // the Kuntz carat table - 1 carat at 01-30, 6-9 at 81-85, 100 carats
        // at 00 (folio 22)
    if (dgoGemACaratMin(0) != 1
            || dgoGemACaratMax(5) != 9
            || dgoGemACaratMin(10) != 100
            || dgoGemACaratCount() != 11
        )
            ++bad;
        // the print's starred rows - 91-95 at 20-50 carats, 86-90 at 20-70 by
        // its own overlapping arithmetic; as scanned, the re-roll footnote
        // noted (folio 22)
    if (dgoGemACaratMin(8) != 20
            || dgoGemACaratMax(7) != 50
        )
            ++bad;
        // the Kuntz basic values - 75 gp at 51-60, 200 gp at 96-00 (folio 22)
    if (dgoGemBValueGp(4) != 75
            || dgoGemBValueGp(9) != 200
            || dgoGemBValueCount() != 10
        )
            ++bad;
        // the print's worked example - 3 gems rolled as a group: 55 gives 75
        // gp per carat and 77 gives 5 carats each, 75 x 5 x 3 = 1,125 gp; the
        // example's table labels read swapped against the printed tables' own
        // bands, as scanned (folios 22-23)
    if (dgoGemBValueGp(4) != 75
            || dgoGemACaratMax(4) != 5
        )
            ++bad;
        // the jewelry metals - bronze 10-40 through mithril 1,500-4,500 and
        // mithril plus platinum 2,000-5,000 (folio 23)
    if (dgoGemDMetalMin(0) != 10
            || dgoGemDMetalMax(0) != 40
            || dgoGemDMetalMin(8) != 1500
            || dgoGemDMetalMax(8) != 4500
            || dgoGemDMetalMin(9) != 2000
            || dgoGemDMetalMax(9) != 5000
        )
            ++bad;
        // the jewelry gem counts - 2-12 capped at 5 carats, 3-36 capped at
        // 20, the no-limitations row at 0, 10-40 at least 20 carats (folio
        // 23)
    if (dgoGemEGemsMin(0) != 2
            || dgoGemEGemsMax(2) != 36
            || dgoGemECaratCap(3) != 0
            || dgoGemEGemsMin(6) != 10
            || dgoGemEGemsMax(6) != 40
        )
            ++bad;
        // the jewelry types - rings at 01-10, bracelets ending at 25,
        // statuettes at 96-00; fifteen bands, the type names in the audit
        // comment (folio 23)
    if (dgoGemFBandMin(0) != 1
            || dgoGemFBandMax(2) != 25
            || dgoGemFBandMin(14) != 96
            || dgoGemFBandMax(14) != 100
            || dgoGemFTypeCount() != 15
        )
            ++bad;
        printf("R910 issue-8 opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
