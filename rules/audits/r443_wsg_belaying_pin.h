    // ---- R443 WSG belaying pin audit ----
    // The belaying slice pins the climbing-rope intro (150 or 200 feet long,
    // 2000-pound weight limit, subject to the weakening and breaking rules),
    // the knot rules (only a rope-use proficient character ties a
    // full-strength knot; anyone else loses 500 pounds; different diameters
    // take the smaller limit minus 500), the belayer Climbing Check (failure
    // = the full fall, success bounded by the rope length), the
    // precarious-position second check on the jolt (failure = both fall) with
    // the secure-position exemption, and the paired-belay sequence (the last
    // cannot belay, the leader cannot be belayed, one belay at a time, no
    // climbing while belaying, the middle faller drags no one below, the
    // failed belayer can be saved by the character above, the first faller is
    // unhelpable) (rules/wsgbelay.h, prefix wbl); census 367 -> 368.
    {
        using namespace rules;
        int bad = 0;
    if (wblClimbRopeMinFt() != 150
            || wblClimbRopeMaxFt() != 200
            || wblClimbRopeLimitLbs() != 2000
            || wblKnotPenaltyLbs() != 500
            || wblChecksPrecarious() != 2
            || wblChecksSecure() != 1
            || wblFallersOnJoltFailure() != 2
            || !wblRopeEndTiedAroundBody()
            || !wblPayOutSmallSlack()
            || !wblFailMeansFullFall()
            || !wblSuccessBoundedByRopeLen()
            || !wblPrecariousNeedsSecondCheck()
            || !wblSecureSkipsSecondCheck()
            || !wblPairsBelayInSequence()
            || !wblLastCannotBelay()
            || !wblLeaderCannotBeBelayed()
            || !wblOneBelayAtATime()
            || !wblNoClimbWhileBelaying()
            || !wblMiddleFallerDragsNoneBelow()
            || !wblFailedBelayerSavedAbove()
            || !wblFirstFallerUnhelpable()
            || !wblProfKnotFullStrength()
            || !wblMixedDiaSmallerMinus500()
        )
            ++bad;
        // the climbing rope: 150 or 200 feet of half-inch rope with a
        // 2000-pound weight limit
    if (wblClimbRopeMinFt() != 150
            || wblClimbRopeMaxFt() != 200
            || wblClimbRopeLimitLbs() != 2000
        )
            ++bad;
        // the amateur knot: 500 pounds off the held weight; the climbing rope
        // limit is exactly four knot penalties (2000 = 4 x 500)
    if (wblKnotPenaltyLbs() != 500
            || wblClimbRopeLimitLbs() != 4 * wblKnotPenaltyLbs()
        )
            ++bad;
        // the two belay postures: the precarious belayer checks twice (the
        // halt, then the jolt), the secure belayer only once
    if (wblChecksPrecarious() != 2
            || wblChecksSecure() != 1
        )
            ++bad;
        // the jolt check is exactly one extra check on top of the halt
    if (wblChecksPrecarious() != wblChecksSecure() + 1
        )
            ++bad;
        // the failed jolt check drops both the belayer and his companion -
        // two fallers, two checks
    if (wblFallersOnJoltFailure() != 2
            || wblFallersOnJoltFailure() != wblChecksPrecarious()
        )
            ++bad;
        // the secure belayer never checks more than the precarious belayer -
        // one check against two
    if (wblChecksSecure() >= wblChecksPrecarious()
        )
            ++bad;
        // the climbing rope length range is a real range: 150 up to 200 feet
    if (wblClimbRopeMinFt() >= wblClimbRopeMaxFt()
        )
            ++bad;
        printf("R443 WSG belaying pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
