    // ---- R464 WSG hunting pin audit ----
    // The Table 31 grid cell by cell (33 terrain rows across the five climate
    // regions, the percent per season), the 1d6 game-encounter list (the size
    // band, the creature dice and the yardage range), the four-turn hunting
    // check with the party and midday modifiers, the 1d10 hit procedure and
    // the wounded-animal stalking rules - every cell, const, bool, switch and
    // chain limit verified against the model.
    {
        using namespace rules;
        int bad = 0;
    if (whnRowCount() != 33
            || whnEncRowCount() != 6
            || whnCheckTurns() != 4
            || whnPartyPenaltyPct() != 5
            || whnMiddayPenaltyPct() != 10
            || whnMissileMinAvgDamage() != 3
            || whnHitDieSize() != 10
            || whnRetryTurns() != 4
            || whnStalkRangeFeet() != 20
            || whnWoundedLChargePct() != 50
            || whnWoundedLChargeDie() != 8
            || whnWoundedAC() != 5
            || whnWoundedMFleeRate() != 18
            || whnWoundedMKillRangeFeet() != 20
            || !whnNightNeedsVision()
            || !whnMeleeFinishOnly()
            || !whnHitsOneAnimalAtATime()
            || !whnWoundedLChargesClosest()
            || !whnWoundedMEscapesOnFirstMiss()
        )
            ++bad;
        // the Table 31 hunting success grid (the percent chance per terrain
        // per season)
        int C31A[33][4] = {
            {5,5,10,5},
            {5,5,10,10},
            {5,5,5,5},
            {5,10,10,5},
            {5,10,10,5},
            {5,10,10,5},
            {5,10,10,5},
            {5,10,15,15},
            {5,5,10,5},
            {5,10,15,15},
            {5,15,20,20},
            {5,10,15,10},
            {10,5,5,10},
            {30,50,50,50},
            {25,40,40,40},
            {25,30,30,30},
            {25,40,50,50},
            {20,40,50,50},
            {20,35,50,50},
            {10,5,5,5},
            {50,50,50,50},
            {50,50,50,50},
            {35,35,35,35},
            {50,50,50,50},
            {50,50,50,50},
            {40,50,50,50},
            {5,5,5,5},
            {50,50,50,50},
            {50,50,50,50},
            {40,40,40,40},
            {50,50,50,50},
            {50,50,50,50},
            {50,50,50,50},
            };
        for (int b = 0;
             b < whnRowCount();
             ++b) {
            int vals[4];
            vals[0] = whnWin(b);
            vals[1] = whnSpr(b);
            vals[2] = whnSum(b);
            vals[3] = whnAut(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C31A[b][c])
                    ++bad;
            }
        }
        // the 1d6 game-encounter list (the size band, the creature dice and
        // the yardage range)
        int C31B[6][5] = {
            {0,2,6,20,40},
            {0,1,6,20,40},
            {1,1,10,20,40},
            {1,1,6,40,60},
            {1,1,3,40,60},
            {2,1,3,60,80},
            };
        for (int b = 0;
             b < whnEncRowCount();
             ++b) {
            int vals[5];
            vals[0] = whnEncSize(b);
            vals[1] = whnEncDice(b);
            vals[2] = whnEncDie(b);
            vals[3] = whnEncRangeMin(b);
            vals[4] = whnEncRangeMax(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != C31B[b][c])
                    ++bad;
            }
        }
        // the whnWoundedMFleeBand band-for boundaries
    if (whnWoundedMFleeBand(0) != 0
            || whnWoundedMFleeBand(1) != 0
            || whnWoundedMFleeBand(3) != 1
            || whnWoundedMFleeBand(2) != 1
            || whnWoundedMFleeBand(4) != 2
        )
            ++bad;
        // the solitary temperate forest hunter: 30% winter, 50% in the other
        // seasons
    if (whnWin(13) != 30
            || whnSpr(13) != 50
            || whnSum(13) != 50
            || whnAut(13) != 50
        )
            ++bad;
        // two hunters in a tropical forest: 50% less the one-member penalty =
        // 45%
    if (whnSpr(28) - whnPartyPenaltyPct() != 45
        )
            ++bad;
        // the three-hunter party: 50% less two cumulative member penalties =
        // 40%
    if (whnSpr(28) - 2 * whnPartyPenaltyPct() != 40
        )
            ++bad;
        // hunting from mid-morning to mid-evening: 50% less the 10% midday
        // shift = 40%
    if (whnSpr(28) - whnMiddayPenaltyPct() != 40
        )
            ++bad;
        // the arctic desert winter: a 5% chance
    if (whnWin(0) != 5
        )
            ++bad;
        // the subarctic swamp autumn: a 10% chance
    if (whnAut(11) != 10
        )
            ++bad;
        // the 1d10 procedure: a roll of 4 beats a creature count of 3, a roll
        // of 2 does not
    if (whnHitDieSize() != 10
            || 4 <= 3
            || 2 > 3
        )
            ++bad;
        // a roll of 6 on the encounter list: size L, 1d3 creatures at 60-80
        // yards (the pixel-confirmed cell)
    if (whnEncSize(5) != 2
            || whnEncDice(5) != 1
            || whnEncDie(5) != 3
            || whnEncRangeMin(5) != 60
            || whnEncRangeMax(5) != 80
        )
            ++bad;
        // the book own roll-5 example: size M, 1d3 creatures at 40-60 yards
    if (whnEncSize(4) != 1
            || whnEncDice(4) != 1
            || whnEncDie(4) != 3
            || whnEncRangeMin(4) != 40
            || whnEncRangeMax(4) != 60
        )
            ++bad;
        // hits to kill: one for size S, two for size M, four for size L
    if (whnHitsToKill(0) != 1
            || whnHitsToKill(1) != 2
            || whnHitsToKill(2) != 4
        )
            ++bad;
        // the panicked flight directions: 1 toward, 2 and 3 perpendicular, 4
        // away
    if (whnWoundedMFleeBand(1) != 0
            || whnWoundedMFleeBand(2) != 1
            || whnWoundedMFleeBand(3) != 1
            || whnWoundedMFleeBand(4) != 2
        )
            ++bad;
        // the enraged charge: a 50% chance of 1d8 damage before retaliation,
        // the stalk to hit against AC 5
    if (whnWoundedLChargePct() != 50
            || whnWoundedLChargeDie() != 8
            || whnWoundedAC() != 5
        )
            ++bad;
        // the encounter list rows stay inside their range bands and the min
        // stays below the max
    if (whnEncRangeMax(0) - whnEncRangeMin(0) != 20
            || whnEncRangeMax(5) - whnEncRangeMin(5) != 20
        )
            ++bad;
        // the subtropical mountains row is a flat 35%
    if (whnWin(22) != 35
            || whnSpr(22) != 35
            || whnSum(22) != 35
            || whnAut(22) != 35
        )
            ++bad;
        // the tropical swamp row is a flat 50%
    if (whnWin(32) != 50
            || whnSpr(32) != 50
            || whnSum(32) != 50
            || whnAut(32) != 50
        )
            ++bad;
        printf("R464 WSG hunting pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
