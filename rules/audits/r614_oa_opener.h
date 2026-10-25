    // ---- R614 OA opener audit ----
    // OA round one (capture pp. 1-8): the arc opener - the front-matter
    // doctrine (the monk retirement, the Kara-Tur naming, the honor thesis),
    // the four generation methods with the NPC rules and the wish ladder, and
    // the Strength yardstick with its exceptional-Strength ladder.
    {
        using namespace rules;
        int bad = 0;
    if (dgaMethodCount() != 4
            || dgaWishLowCeiling() != 15
            || dgaWishesFrom16To17() != 9
            || dgaPressLbsPerPoint() != 10
            || dgaBodyWeightCap() != 2
            || dgaExceptionalLift() != 470
            || dgaBushiXpFloor() != 15
            || !dgaMonkRetired()
            || !dgaKaraTurNamed()
            || !dgaHonorThesis()
            || !dgaMethodI()
            || !dgaMethodII()
            || !dgaMethodIII()
            || !dgaMethodIV()
            || !dgaNpcAveraging()
            || !dgaNpcProfessionBoost()
            || !dgaWishHighTenth()
            || !dgaWishBooksExempt()
            || !dgaPressOrBodyWeight()
            || !dgaExceptionalLiftLadder()
            || !dgaBushiXpBonus()
            || !dgaExceptionalClasses()
        )
            ++bad;
        // the dgaMonkRetired pin
    if (dgaMonkRetired() != 1
        )
            ++bad;
        // the dgaKaraTurNamed pin
    if (dgaKaraTurNamed() != 1
        )
            ++bad;
        // the dgaHonorThesis pin
    if (dgaHonorThesis() != 1
        )
            ++bad;
        // the dgaMethodCount pin
    if (dgaMethodCount() != 4
        )
            ++bad;
        // the dgaMethodI pin
    if (dgaMethodI() != 1
        )
            ++bad;
        // the dgaMethodII pin
    if (dgaMethodII() != 1
        )
            ++bad;
        // the dgaMethodIII pin
    if (dgaMethodIII() != 1
        )
            ++bad;
        // the dgaMethodIV pin
    if (dgaMethodIV() != 1
        )
            ++bad;
        // the dgaNpcAveraging pin
    if (dgaNpcAveraging() != 1
        )
            ++bad;
        // the dgaNpcProfessionBoost pin
    if (dgaNpcProfessionBoost() != 1
        )
            ++bad;
        // the dgaWishLowCeiling pin
    if (dgaWishLowCeiling() != 15
        )
            ++bad;
        // the dgaWishHighTenth pin
    if (dgaWishHighTenth() != 1
        )
            ++bad;
        // the dgaWishesFrom16To17 pin
    if (dgaWishesFrom16To17() != 9
        )
            ++bad;
        // the dgaWishBooksExempt pin
    if (dgaWishBooksExempt() != 1
        )
            ++bad;
        // the dgaPressLbsPerPoint pin
    if (dgaPressLbsPerPoint() != 10
        )
            ++bad;
        // the dgaPressOrBodyWeight pin
    if (dgaPressOrBodyWeight() != 1
        )
            ++bad;
        // the dgaBodyWeightCap pin
    if (dgaBodyWeightCap() != 2
        )
            ++bad;
        // the dgaExceptionalLiftLadder pin
    if (dgaExceptionalLiftLadder() != 1
        )
            ++bad;
        // the dgaExceptionalLift pin
    if (dgaExceptionalLift() != 470
        )
            ++bad;
        // the dgaBushiXpFloor pin
    if (dgaBushiXpFloor() != 15
        )
            ++bad;
        // the dgaBushiXpBonus pin
    if (dgaBushiXpBonus() != 1
        )
            ++bad;
        // the dgaExceptionalClasses pin
    if (dgaExceptionalClasses() != 1
        )
            ++bad;
        // the press yardstick consistency, Strength 3 and 18 (capture p. 7)
    if (dgaPressLbsPerPoint() * 3 != 30
            || dgaPressLbsPerPoint() * 18 != 180
        )
            ++bad;
        // the exceptional ladder sums to the 18/00 press (capture p. 7)
    if (dgaPressLbsPerPoint() * 18 + 290 != dgaExceptionalLift()
        )
            ++bad;
        // the wish ladder boundary cross-check (capture p. 6)
    if (dgaWishLowCeiling() + 1 != 16
            || dgaWishesFrom16To17() + 1 != 10
        )
            ++bad;
        printf("R614 OA opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
