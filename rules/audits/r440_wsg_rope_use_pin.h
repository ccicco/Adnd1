    // ---- R440 WSG rope use pin audit ----
    // The rope-use slice pins the standard 50-foot coil (the most important
    // climbing equipment), the 1500-pound support limit, the 20 percent
    // per-turn non-cumulative overload break chance, the cumulative
    // 10/30/60/100 weakening ladder and the 40 percent weakened-rope break
    // chance (rules/wsgrope.h, prefix wsr); census 364 -> 365.
    {
        using namespace rules;
        int bad = 0;
    if (wsrCoilLengthFt() != 50
            || wsrMaxLoadLbs() != 1500
            || wsrOverloadBreakPct() != 20
            || wsrWeakenedBreakPct() != 40
            || !wsrNotHandsAndFeetAlone()
            || !wsrEquipmentOftenNecessary()
            || !wsrRopeMostImportant()
            || !wsrCoilUnderHalfInch()
            || !wsrOverloadBreakNonCumulative()
            || !wsrWeakenCumulativePerTurn()
            || !wsrWeakenedBreakNonCumulative()
        )
            ++bad;
        // the standard coil: 50 feet of rope supporting up to 1500 pounds
        // without fraying or breaking
    if (wsrCoilLengthFt() != 50
            || wsrMaxLoadLbs() != 1500
        )
            ++bad;
        // the cumulative weakening ladder: 10 percent after one turn of
        // strain, 30 after two, 60 after three, 100 after four
    if (wsrWeakenPct(1) != 10
            || wsrWeakenPct(2) != 30
            || wsrWeakenPct(3) != 60
            || wsrWeakenPct(4) != 100
        )
            ++bad;
        // the two break chances: the weakened rope breaks at 40 percent per
        // turn - twice the 20 percent overload break chance of a healthy rope
    if (wsrOverloadBreakPct() * 2 != wsrWeakenedBreakPct()
        )
            ++bad;
        // the weakening ladder is strictly increasing turn by turn
        // (cumulative), from 0 to 100 percent
    if (wsrWeakenPct(0) >= wsrWeakenPct(1)
            || wsrWeakenPct(1) >= wsrWeakenPct(2)
            || wsrWeakenPct(2) >= wsrWeakenPct(3)
            || wsrWeakenPct(3) >= wsrWeakenPct(4)
        )
            ++bad;
        printf("R440 WSG rope use pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
