    // ---- R782 owed pins audit ----
    // THE OWED PINS AND THE DEITY SITE - four feeds in one round (Curtiss's
    // all-four pick). (1) The lance printed cells the R780 boundary owed: the
    // lengths 10/12/14 feet and the 1-foot space-required cell pin as data
    // (the compilation print the R189 duty already trusts; the R780 engine
    // sense stands - no caller reads a length yet). (2) The spear 6..8 spread
    // ends its contract-side stay: weaponspeed.h gains the length-keyed
    // companion to the R158 range helper - 5 feet and under reads 6, 13 and
    // over reads 8, the middle keeps the default 7. (3) The deity layer site
    // lands: the R405 no-site contract is STRUCK - the bridge copies every
    // Appendix S stat block onto a monster-side Actor (the printed hp and AC
    // whole, the halves halved, the damage span floored), the stat-block
    // charge closes with it, and a live site block in regtest walks all 23
    // blocks through the bridge (the five charts stay their own seam). (4)
    // The DMG p.66 closing bar reads the fronts: a mounted front in round one
    // is a closing charge, and the print exempts the charging round from the
    // tie order (case 1) and the extra-attack window (case 2) - the monster
    // side never lance-charges (the R779 boundary); its mounted round one
    // reads as the closing bar alone. Honest boundaries: the deity attack
    // matrix stays on the monster HD convention (the bridge pins hitDice
    // 1.0), the spawn path stays contract-side, the R406 hole cells ride
    // their sentinels verbatim (the attack holes floor to one routine on the
    // bridge and the AC hole 99 round-trips whole), and the site block printf
    // carries no census marker (the census counts this audit alone)
    {
        using namespace rules;
        int bad = 0;
    if (owdLanceCellsFeederRound() != 780
            || owdSpearSpreadFeederRound() != 158
            || owdDeitySeamRound() != 405
            || owdDeityBridgeRound() != 782
            || owdDeityStatBlockCount() != 23
            || owdLightLanceLengthFt() != 10
            || owdMediumLanceLengthFt() != 12
            || owdHeavyLanceLengthFt() != 14
            || owdLanceSpaceRequiredFt() != 1
            || owdSpearShortLengthFt() != 5
            || owdSpearLongLengthFt() != 13
            || owdSpearShortSpeedFactor() != 6
            || owdSpearMiddleSpeedFactor() != 7
            || owdSpearLongSpeedFactor() != 8
            || !owdLanceCellsRideThePrint()
            || !owdSpearSpreadEndsPin()
            || !owdSpearMiddleKeepsDefault()
            || !owdDeitySiteExistsNow()
            || !owdDeityBridgeCopiesTheBlock()
            || !owdDeityChargeCloses()
            || !owdChargingFrontReadsTheBar()
            || !owdChargingExemptsTheTieOrder()
            || !owdChargingExemptsTheExtraWindow()
            || !owdMonsterSideNeverCharges()
        )
            ++bad;
        // the lance printed length and space-required cells
    if (owdLightLanceLengthFt() != 10
            || owdMediumLanceLengthFt() != 12
            || owdHeavyLanceLengthFt() != 14
            || owdLanceSpaceRequiredFt() != 1
        )
            ++bad;
        // the spear length spread and its 6/7/8 cells
    if (owdSpearShortLengthFt() != 5
            || owdSpearLongLengthFt() != 13
            || owdSpearShortSpeedFactor() != 6
            || owdSpearMiddleSpeedFactor() != 7
            || owdSpearLongSpeedFactor() != 8
        )
            ++bad;
        // the deity bridge census and feeder seams
    if (owdDeityStatBlockCount() != 23
            || owdDeityBridgeRound() != 782
            || owdDeitySeamRound() != 405
        )
            ++bad;
        // the feeder seam keys (the R780 and R158 feeds)
    if (owdLanceCellsFeederRound() != 780
            || owdSpearSpreadFeederRound() != 158
        )
            ++bad;
        printf("R782 owed pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
