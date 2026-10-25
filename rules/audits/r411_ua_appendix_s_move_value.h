    // ---- R411: the UA Appendix S
    // MOVE values pin audit ----
    // The 23 movement rates pin;
    // the five parenthetical
    // alternates pin (Dumathoin
    // 48, Sheela 24, Urdlen 36,
    // Segojan 36, Luthic 12); the
    // Aerdrie flight-only flag
    // pins; the Shargaas garble
    // records as the hole sentinel
    // ("MOVE: 78-", no independent
    // confirmation); the sanity
    // ladders run live (every clean
    // base a multiple of 3, every
    // alternate a multiple of 12);
    // the base sum catches a drift
    // in ANY clean cell; census
    // 337 -> 338.
    {
        using namespace rules;
        int bad = 0;
        // ---- the census ----
        if (umvMoveCount() != 23)
            ++bad;
        if (umvAltCount() != 5) ++bad;
        if (umvBaseSum() != 297) ++bad;
        if (!umvBasesAreMultiplesOf3())
            ++bad;
        if (!umvAltsAreMultiplesOf12())
            ++bad;
        if (!umvAerdrieFlightOnly())
            ++bad;
        // the flight flag rides the
        // Aerdrie row ALONE
        if (umvMove(0).flightOnly
                || umvMove(2).flightOnly
                || umvMove(14).flightOnly
                || umvMove(19).flightOnly
                || umvMove(22).flightOnly)
            ++bad;
        if (umvMove(19).base != UMV_MOVE_HOLE) ++bad;
        if (umvMove(0).base != 12
                || umvMove(0).alt != 0) ++bad;
        if (umvMove(1).base != 18
                || umvMove(1).alt != 0) ++bad;
        if (umvMove(2).base != 9
                || umvMove(2).alt != 48) ++bad;
        if (umvMove(3).base != 12
                || umvMove(3).alt != 0) ++bad;
        if (umvMove(4).base != 12
                || umvMove(4).alt != 0) ++bad;
        if (umvMove(5).base != 48
                || umvMove(5).alt != 0) ++bad;
        if (umvMove(6).base != 18
                || umvMove(6).alt != 0) ++bad;
        if (umvMove(7).base != 15
                || umvMove(7).alt != 0) ++bad;
        if (umvMove(8).base != 12
                || umvMove(8).alt != 0) ++bad;
        if (umvMove(9).base != 12
                || umvMove(9).alt != 0) ++bad;
        if (umvMove(10).base != 9
                || umvMove(10).alt != 24) ++bad;
        if (umvMove(11).base != 12
                || umvMove(11).alt != 0) ++bad;
        if (umvMove(12).base != 12
                || umvMove(12).alt != 0) ++bad;
        if (umvMove(13).base != 12
                || umvMove(13).alt != 0) ++bad;
        if (umvMove(14).base != 15
                || umvMove(14).alt != 0) ++bad;
        if (umvMove(15).base != 12
                || umvMove(15).alt != 36) ++bad;
        if (umvMove(16).base != 9
                || umvMove(16).alt != 36) ++bad;
        if (umvMove(17).base != 6
                || umvMove(17).alt != 0) ++bad;
        if (umvMove(18).base != 9
                || umvMove(18).alt != 0) ++bad;
        if (umvMove(20).base != 12
                || umvMove(20).alt != 0) ++bad;
        if (umvMove(21).base != 6
                || umvMove(21).alt != 0) ++bad;
        if (umvMove(22).base != 15
                || umvMove(22).alt != 12) ++bad;
        printf("R411 UA appendix S MOVE values pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
