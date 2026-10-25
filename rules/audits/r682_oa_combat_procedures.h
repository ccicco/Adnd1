    // ---- R682 OA combat procedures audit ----
    // OA round sixty-nine (capture p. 219): the Combat Procedures - the
    // missile fire from horseback doctrine - the unmoving-horse freedom, the
    // horsemanship proficiency gate, the halved rate of fire with the
    // speed-based to-hit penalties, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (divOAHorsebackRateDivisor() != 2
            || divOAExampleMountedShotsLow() != 1
            || divOAExampleMountedNumHigh() != 3
            || divOAExampleMountedDenHigh() != 2
            || divOABowfireHandsRequired() != 2
            || !divOAMountedBowmanDoctrine()
            || !divOAUnmovingHorseAnyCharacter()
            || !divOAMovingHorseNeedsHorsemanship()
            || !divOAKneesGuidance()
            || !divOADMRoughGroundBlocksBowfire()
            || !divOASpeedBasedToHitPenalty()
        )
            ++bad;
        // the rate pins - the horseback rate of fire halved
    if (divOAHorsebackRateDivisor() != 2
        )
            ++bad;
        // the printed rate conversions - 2/1 becomes 1/1, 3/1 becomes 3/2
    if (divOAExampleMountedShotsLow() != 1
            || divOAExampleMountedNumHigh() != 3
        )
            ++bad;
        // the 3/2 denominator of the second conversion
    if (divOAExampleMountedDenHigh() != 2
        )
            ++bad;
        // the halving shape - the divisor times the mounted low-rate shots
        // equals the printed 2
    if (divOAHorsebackRateDivisor() * divOAExampleMountedShotsLow() != 2
        )
            ++bad;
        // the hands pin - the bowfire requiring two hands, the knees guiding
        // the moving horse
    if (divOABowfireHandsRequired() != 2
        )
            ++bad;
        printf("R682 OA combat procedures audit: bad %d\n", bad);
        if (bad) return 1;
    }
