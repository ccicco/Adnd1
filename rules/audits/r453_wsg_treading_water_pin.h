    // ---- R453 WSG treading water pin audit ----
    // The treading water slice pins the proficient calm-water hold (turns
    // equal to twice the endurance score, one endurance point per two turns),
    // the nonproficient limit (rounds equal to the strength score, modified
    // for encumbrance the same way a swimmer's endurance is modified), the
    // expiry checks (a Strength Check at expiration and every round
    // thereafter, cumulative +1 after the first, per the 6-strength/12-round
    // example), and the current rules (carried at the current speed modified
    // for encumbrance, the proficient hold-position effectively swimming with
    // endurance assessed, the nonproficient sinking immediately if he
    // resists) (rules/wsgtread.h, prefix wtw); census 377 -> 378.
    {
        using namespace rules;
        int bad = 0;
    if (wtwProfTurnsPerEndPt() != 2
            || wtwNonprofRoundsPerStrPt() != 1
            || wtwCumCheckStep() != 1
            || wtwExampleStr() != 6
            || wtwExampleRounds() != 12
            || wtwExampleFirstModRound() != 13
            || !wtwProfCalmWaterHold()
            || !wtwProfLimitTwiceEndurance()
            || !wtwNonprofLimitIsStrength()
            || !wtwNonprofLimitEncModified()
            || !wtwStrengthCheckAtExpiry()
            || !wtwChecksCumulativePlusOne()
            || !wtwCurrentCarriesTreader()
            || !wtwProfHoldsPositionButSwims()
            || !wtwNonprofResistingSinks()
        )
            ++bad;
        // the printed numbers: twice the endurance in turns for the
        // proficient, the strength score in rounds for the nonproficient, the
        // cumulative +1 check step
    if (wtwProfTurnsPerEndPt() != 2
            || wtwNonprofRoundsPerStrPt() != 1
            || wtwCumCheckStep() != 1
        )
            ++bad;
        // the printed example: strength 6 unencumbered treads at least 12
        // rounds - the strength limit doubled by the unencumbered endurance
        // modifier (the x2 none row)
    if (wtwExampleStr() != 6
            || wtwExampleRounds() != 12
            || wtwExampleRounds() != 2 * wtwExampleStr()
            || wtwExampleRounds() != wtwNonprofRoundsPerStrPt() *
            wtwExampleStr() * 2
        )
            ++bad;
        // the example cadence: the unmodified check lands at the end of the
        // 12th round and the first +1 modifier at the end of the 13th - one
        // round later
    if (wtwExampleFirstModRound() != wtwExampleRounds() + 1
            || wtwExampleFirstModRound() - wtwExampleRounds() != 1
        )
            ++bad;
        printf("R453 WSG treading water pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
