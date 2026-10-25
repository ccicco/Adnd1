    // ---- R649 OA armor descriptions audit ----
    // OA round thirty-six (capture pp. 93-98): the armor prose and the armor
    // descriptions - the suits-and-pieces doctrine, the piece-combination
    // rules and the armor description entries
    {
        using namespace rules;
        int bad = 0;
    if (dhjArmorGroupCount() != 2
            || dhjCommonSuitCount() != 6
            || dhjRareSuitCount() != 4
            || dhjUnknownSuitCount() != 3
            || dhjCorseletAc() != 7
            || dhjKoteOnlyAc() != 9
            || dhjKoteDomaruHaidateAc() != 6
            || dhjSodeSideFeet() != 1
            || dhjHoroMissileAc() != 1
            || dhjKabutoHeadAc() != 3
            || dhjOyoroiPieceCount() != 6
            || dhjOyoroiSmallCount() != 5
            || dhjScaleTypeCount() != 2
            || !dhjClothLeatherCommon()
            || !dhjFieldPlateSeldom()
            || !dhjPiecesAreLaced()
            || !dhjSuitSetsAc()
            || !dhjAveragedAc()
            || !dhjSpecialNoGeneral()
            || !dhjOyoroiBelowPieces()
            || !dhjOnePiecePerArea()
            || !dhjPiecesNotWithSuits()
            || !dhjBucklerSameHand()
            || !dhjChainConcealable()
            || !dhjDomaruLamellar()
            || !dhjKoteUnderRobes()
            || !dhjHaraateGawaLeather()
            || !dhjHaraateRearAc10()
            || !dhjHaramakiConcealable()
            || !dhjHaramakidoExposed()
            || !dhjHideBetterThanLeather()
            || !dhjHoroRidingOnly()
            || !dhjHoroNoOtherUse()
            || !dhjSodeNeedsCorselet()
            || !dhjOyoroiMatchedBetter()
            || !dhjScaleLeatherCommoner()
            || !dhjShieldsLighter()
            || !dhjSuneateCrippling()
            || !dhjPieceMovementDrop()
            || !dhjMovementFloorOyoroi()
        )
            ++bad;
        // the two-group doctrine pin - suits and pieces
    if (dhjArmorGroupCount() != 2
        )
            ++bad;
        // the suit-list pins - the common, rare and virtually-unknown counts
    if (dhjCommonSuitCount() != 6
            || dhjRareSuitCount() != 4
            || dhjUnknownSuitCount() != 3
        )
            ++bad;
        // the intro doctrine pins - cloth and leather common, field plate
        // seldom, pieces are laced
    if (dhjClothLeatherCommon() != 1
            || dhjFieldPlateSeldom() != 1
            || dhjPiecesAreLaced() != 1
        )
            ++bad;
        // the suit-sets-AC and averaging doctrine pins
    if (dhjSuitSetsAc() != 1
            || dhjAveragedAc() != 1
        )
            ++bad;
        // the corselet AC pin - AC 7, equal to studded leather
    if (dhjCorseletAc() != 7
        )
            ++bad;
        // the printed piece-example pins - kote only AC 9,
        // kote-do-maru-haidate AC 6 (the T53 cross-checks)
    if (dhjKoteOnlyAc() != 9
            || dhjKoteDomaruHaidateAc() != 6
        )
            ++bad;
        // the piece-combination rule pins - the specialized small pieces, the
        // o-yoroi floor rule, one per area, not with suits
    if (dhjSpecialNoGeneral() != 1
            || dhjOyoroiBelowPieces() != 1
            || dhjOnePiecePerArea() != 1
            || dhjPiecesNotWithSuits() != 1
        )
            ++bad;
        // the sode pins - one foot square, needs a corselet
    if (dhjSodeSideFeet() != 1
            || dhjSodeNeedsCorselet() != 1
        )
            ++bad;
        // the concealability pins - chain under clothing, kote under robes,
        // haramaki concealable, haramaki-do not
    if (dhjChainConcealable() != 1
            || dhjKoteUnderRobes() != 1
            || dhjHaramakiConcealable() != 1
            || dhjHaramakidoExposed() != 1
        )
            ++bad;
        // the hara-ate pair pins - the leather corselet and the
        // rear-attacks-AC-10 rule
    if (dhjHaraateGawaLeather() != 1
            || dhjHaraateRearAc10() != 1
        )
            ++bad;
        // the horo pins - the back-missile bonus, riding only, no other use
    if (dhjHoroMissileAc() != 1
            || dhjHoroRidingOnly() != 1
            || dhjHoroNoOtherUse() != 1
        )
            ++bad;
        // the kabuto head-AC pin - AC 3
    if (dhjKabutoHeadAc() != 3
        )
            ++bad;
        // the o-yoroi pins - six pieces, five smaller pieces, the matched-set
        // rule
    if (dhjOyoroiPieceCount() != 6
            || dhjOyoroiSmallCount() != 5
            || dhjOyoroiMatchedBetter() != 1
        )
            ++bad;
        // the entry pins - buckler same hand, do-maru lamellar, hide better
        // than leather
    if (dhjBucklerSameHand() != 1
            || dhjDomaruLamellar() != 1
            || dhjHideBetterThanLeather() != 1
        )
            ++bad;
        // the scale pins - two types, leather the commoner
    if (dhjScaleTypeCount() != 2
            || dhjScaleLeatherCommoner() != 1
        )
            ++bad;
        // the shields and sune-ate pins - lighter construction,
        // crippling-blow protection
    if (dhjShieldsLighter() != 1
            || dhjSuneateCrippling() != 1
        )
            ++bad;
        // the movement pins - the category drop and the o-yoroi floor
    if (dhjPieceMovementDrop() != 1
            || dhjMovementFloorOyoroi() != 1
        )
            ++bad;
        printf("R649 OA armor descriptions audit: bad %d\n", bad);
        if (bad) return 1;
    }
