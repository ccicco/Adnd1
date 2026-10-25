    // ---- R94: nerve audit ----
    {
        int bad = 0;
        // the event deltas
        if (loyaltyDriftDeepDescent() != -2) ++bad;
        if (loyaltyDriftDelveDone()   !=  3) ++bad;
        if (loyaltyDriftHardWatch()   != -1) ++bad;
        // the clamp: 0..125 (the loader's bounds)
        if (clampLoyalty(-5) != 0) ++bad;
        if (clampLoyalty(130) != 125) ++bad;
        if (clampLoyalty(50) != 50) ++bad;
        // a simulated career: hired at 50 (CHA 10, no adj),
        // one record descent (48), a hard watch (47), then
        // the completed delve (50) - a rough delve nets even;
        // a clean one gains
        {
            int loy = 50;
            loy = loyaltyDrift(loy, loyaltyDriftDeepDescent());
            if (loy != 48) ++bad;
            loy = loyaltyDrift(loy, loyaltyDriftHardWatch());
            if (loy != 47) ++bad;
            loy = loyaltyDrift(loy, loyaltyDriftDelveDone());
            if (loy != 50) ++bad;
            // a clean delve (record + done only): 48 + 3 = 51
            loy = loyaltyDrift(loy, loyaltyDriftDeepDescent());
            loy = loyaltyDrift(loy, loyaltyDriftDelveDone());
            if (loy != 51) ++bad;
        }
        // the floor holds under a cowardly streak
        {
            int loy = 1;
            for (int i = 0; i < 5; ++i)
                loy = loyaltyDrift(loy, loyaltyDriftHardWatch());
            if (loy != 0) ++bad;
        }
        printf("R94 nerve audit: bad %d\n", bad);
        if (bad) return 1;
    }
