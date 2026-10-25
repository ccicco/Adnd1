    // ---- R433 WSG animals pin audit ----
    // The land-based animals slice pins Table 13 (the 18 mounts and beasts of
    // burden x the normal and maximum loads and the unencumbered/encumbered
    // rates over the three terrain classes), the forced-move stamina rules
    // (the half-rate hour cap, the cumulative fatigue chances) and the
    // accelerated no-rest spillover (rules/wsganimal.h, prefix wam); census
    // 357 -> 358.
    {
        using namespace rules;
        int bad = 0;
    if (wamAnimalCount() != 18
            || wamForcedHoursDen() != 2
            || wamForcedHoursMax() != 12
            || wamFatNormPct() != 20
            || wamFatRugPct() != 35
            || wamFatVrPct() != 50
            || wamAccelNorestNum() != 1
            || wamAccelNorestDen() != 3
            || !wamCharCategoriesDontApply()
            || !wamTwoDesignationsOnly()
            || !wamNormalLoadUnencumbered()
            || !wamMaxLoadStillMoves()
            || !wamRateVariesWithTerrain()
            || !wamRateIndicatesStamina()
            || !wamFatigueCumulative()
            || !wamLeftIsUnencumbered()
            || !wamRightIsEncumbered()
            || !wamZeroCannotMove()
            || !wamTableNotExhaustive()
            || !wamDmComparesSimilarBeast()
        )
            ++bad;
        // the Table 13 grid: the 18 animal rows x the normal and maximum
        // loads and the unencumbered and encumbered rates over the three
        // terrain classes
        int C13[18][8] = {
            {2000,4000,12,6,9,6,6,3},
            {3000,6000,12,6,9,6,3,0},
            {4000,6000,18,6,9,6,3,0},
            {4000,6000,21,9,12,6,3,0},
            {3000,6000,12,9,6,3,0,0},
            {1500,2500,12,6,9,6,6,3},
            {5000,10000,15,9,9,6,0,0},
            {5000,10000,12,9,6,6,0,0},
            {4000,8000,12,6,6,3,3,3},
            {5000,7500,15,9,9,6,6,3},
            {3000,5000,24,12,12,6,6,3},
            {4000,6500,18,9,9,6,6,3},
            {3000,6000,24,12,12,6,6,3},
            {5000,7500,12,6,9,6,6,3},
            {2000,3000,12,6,6,3,3,0},
            {2500,4000,15,9,12,9,6,3},
            {250,500,9,6,6,3,6,3},
            {2250,3500,12,6,9,6,6,3},
            };
        for (int b = 0;
             b < wamAnimalCount();
             ++b) {
            int vals[8];
            vals[0] = wamNormLoad(b);
            vals[1] = wamMaxLoad(b);
            vals[2] = wamMvNormU(b);
            vals[3] = wamMvNormE(b);
            vals[4] = wamMvRugU(b);
            vals[5] = wamMvRugE(b);
            vals[6] = wamMvVrU(b);
            vals[7] = wamMvVrE(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != C13[b][c])
                    ++bad;
            }
        }
        // the light warhorse, unencumbered, normal terrain: rate 24
    if (wamMvNormU(10) != 24
        )
            ++bad;
        // the forced-move window: 24 over 2 = 12 hours without adverse
        // effects
    if (wamMvNormU(10) / wamForcedHoursDen() != 12
        )
            ++bad;
        // at the end of 13 hours: a 20 percent chance of fatigue
    if (wamFatNormPct() * (13 - wamMvNormU(10) / wamForcedHoursDen()) != 20
        )
            ++bad;
        // after 14 hours: the chance rises to 40 percent
    if (wamFatNormPct() * (14 - wamMvNormU(10) / wamForcedHoursDen()) != 40
        )
            ++bad;
        // the medium warhorse, encumbered, rugged terrain: rate 6
    if (wamMvRugE(11) != 6
        )
            ++bad;
        // the forced-move window: 6 over 2 = three consecutive hours without
        // incident
    if (wamMvRugE(11) / wamForcedHoursDen() != 3
        )
            ++bad;
        // at the end of four hours: a 35 percent chance of fatigue
    if (wamFatRugPct() * (4 - wamMvRugE(11) / wamForcedHoursDen()) != 35
        )
            ++bad;
        // after five hours: the chance rises to 70 percent
    if (wamFatRugPct() * (5 - wamMvRugE(11) / wamForcedHoursDen()) != 70
        )
            ++bad;
        // six hours: a 105 percent chance - fatigue is automatic
    if (wamFatRugPct() * (6 - wamMvRugE(11) / wamForcedHoursDen()) != 105
        )
            ++bad;
        // the accelerated pace kept up without the rest stops: 16 + 5 = 21
        // (the +1/3 of 16 rounded to the nearest whole is 5 - written
        // division-free, the rounding inequality)
    if (2 * 16 * wamAccelNorestNum() - 2 * 5 * wamAccelNorestDen() <
        -wamAccelNorestDen()
            || 2 * 16 * wamAccelNorestNum() - 2 * 5 * wamAccelNorestDen() >
            wamAccelNorestDen()
        )
            ++bad;
        // the dromedary unencumbered normal rate: 21
    if (wamMvNormU(3) != 21
        )
            ++bad;
        // the tiger comparison: the yak normal load is 2250 gp
    if (wamNormLoad(17) != 2250
        )
            ++bad;
        // every Table 13 row: the maximum load is greater than the normal
        // load
    if (wamMaxLoad(0) <= wamNormLoad(0)
            || wamMaxLoad(1) <= wamNormLoad(1)
            || wamMaxLoad(2) <= wamNormLoad(2)
            || wamMaxLoad(3) <= wamNormLoad(3)
            || wamMaxLoad(4) <= wamNormLoad(4)
            || wamMaxLoad(5) <= wamNormLoad(5)
            || wamMaxLoad(6) <= wamNormLoad(6)
            || wamMaxLoad(7) <= wamNormLoad(7)
            || wamMaxLoad(8) <= wamNormLoad(8)
            || wamMaxLoad(9) <= wamNormLoad(9)
            || wamMaxLoad(10) <= wamNormLoad(10)
            || wamMaxLoad(11) <= wamNormLoad(11)
            || wamMaxLoad(12) <= wamNormLoad(12)
            || wamMaxLoad(13) <= wamNormLoad(13)
            || wamMaxLoad(14) <= wamNormLoad(14)
            || wamMaxLoad(15) <= wamNormLoad(15)
            || wamMaxLoad(16) <= wamNormLoad(16)
            || wamMaxLoad(17) <= wamNormLoad(17)
        )
            ++bad;
        // the encumbered rate is never above the unencumbered rate in the
        // same Table 13 cell
    if (wamMvNormE(0) > wamMvNormU(0)
            || wamMvRugE(0) > wamMvRugU(0)
            || wamMvVrE(0) > wamMvVrU(0)
            || wamMvNormE(1) > wamMvNormU(1)
            || wamMvRugE(1) > wamMvRugU(1)
            || wamMvVrE(1) > wamMvVrU(1)
            || wamMvNormE(2) > wamMvNormU(2)
            || wamMvRugE(2) > wamMvRugU(2)
            || wamMvVrE(2) > wamMvVrU(2)
            || wamMvNormE(3) > wamMvNormU(3)
            || wamMvRugE(3) > wamMvRugU(3)
            || wamMvVrE(3) > wamMvVrU(3)
            || wamMvNormE(4) > wamMvNormU(4)
            || wamMvRugE(4) > wamMvRugU(4)
            || wamMvVrE(4) > wamMvVrU(4)
            || wamMvNormE(5) > wamMvNormU(5)
            || wamMvRugE(5) > wamMvRugU(5)
            || wamMvVrE(5) > wamMvVrU(5)
            || wamMvNormE(6) > wamMvNormU(6)
            || wamMvRugE(6) > wamMvRugU(6)
            || wamMvVrE(6) > wamMvVrU(6)
            || wamMvNormE(7) > wamMvNormU(7)
            || wamMvRugE(7) > wamMvRugU(7)
            || wamMvVrE(7) > wamMvVrU(7)
            || wamMvNormE(8) > wamMvNormU(8)
            || wamMvRugE(8) > wamMvRugU(8)
            || wamMvVrE(8) > wamMvVrU(8)
            || wamMvNormE(9) > wamMvNormU(9)
            || wamMvRugE(9) > wamMvRugU(9)
            || wamMvVrE(9) > wamMvVrU(9)
            || wamMvNormE(10) > wamMvNormU(10)
            || wamMvRugE(10) > wamMvRugU(10)
            || wamMvVrE(10) > wamMvVrU(10)
            || wamMvNormE(11) > wamMvNormU(11)
            || wamMvRugE(11) > wamMvRugU(11)
            || wamMvVrE(11) > wamMvVrU(11)
            || wamMvNormE(12) > wamMvNormU(12)
            || wamMvRugE(12) > wamMvRugU(12)
            || wamMvVrE(12) > wamMvVrU(12)
            || wamMvNormE(13) > wamMvNormU(13)
            || wamMvRugE(13) > wamMvRugU(13)
            || wamMvVrE(13) > wamMvVrU(13)
            || wamMvNormE(14) > wamMvNormU(14)
            || wamMvRugE(14) > wamMvRugU(14)
            || wamMvVrE(14) > wamMvVrU(14)
            || wamMvNormE(15) > wamMvNormU(15)
            || wamMvRugE(15) > wamMvRugU(15)
            || wamMvVrE(15) > wamMvVrU(15)
            || wamMvNormE(16) > wamMvNormU(16)
            || wamMvRugE(16) > wamMvRugU(16)
            || wamMvVrE(16) > wamMvVrU(16)
            || wamMvNormE(17) > wamMvNormU(17)
            || wamMvRugE(17) > wamMvRugU(17)
            || wamMvVrE(17) > wamMvVrU(17)
        )
            ++bad;
        printf("R433 WSG animals pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
