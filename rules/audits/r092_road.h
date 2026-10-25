    // ---- R92: road audit ----
    {
        int bad = 0;
        // the climb: 12 turns per level
        if (ascentTurns(1) != 12) ++bad;
        if (ascentTurns(3) != 36) ++bad;
        if (ascentTurns(6) != 72) ++bad;
        // stairs symmetry: one descent (36) out-climbs three
        // levels of ascent (36) - the way down clears ground,
        // the way up re-walks it
        if (descentTurns() != ascentTurns(3)) ++bad;
        // a deep delve is expensive to leave: level 10 costs
        // 120 turns (20 hours - a full adventuring day)
        if (ascentTurns(10) != 120) ++bad;
        // clock-model coherence: a shallow delve (descend 36
        // + climb 12 + camp 48 = 96) fits a 144-turn day;
        // a deep delve to 6 does NOT (36 + 72 + 48 = 156) -
        // multi-day delves are the honest consequence of depth
        if (descentTurns() + ascentTurns(1) + restTurns(false)
            > 144) ++bad;
        if (descentTurns() + ascentTurns(6) + restTurns(false)
            <= 144) ++bad;
        printf("R92 road audit: bad %d\n", bad);
        if (bad) return 1;
    }
