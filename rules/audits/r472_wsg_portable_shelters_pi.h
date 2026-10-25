    // ---- R472 WSG portable shelters pin audit ----
    // The Table 36 grid (the four-quality-band by three-size portable shelter
    // characteristics: encumbrance value, cost, setup time dice, moisture
    // tier, wind resistance, life span), the simple shelter mechanics (the
    // 6-10 foot pole, the waterproof cloth, the 30-45 degree pitch, the ropes
    // and stakes, the opening away from the wind), the occupancy limits (one
    // human, two smaller characters, two men in a pinch), the hauling rules
    // and the p. 61 cave-slope seam tail - every const, bool and table cell
    // verified against the model.
    {
        using namespace rules;
        int bad = 0;
    if (wpsQualityBands() != 4
            || wpsSizesPerBand() != 3
            || wpsRowCount() != 12
            || wpsPoleMinFeet() != 6
            || wpsPoleMaxFeet() != 10
            || wpsPitchMinAngle() != 30
            || wpsPitchMaxAngle() != 45
            || wpsMaxPolePieces() != 3
            || !wpsCaveSlopeSuperior()
            || !wpsDmJudgmentPrevails()
            || !wpsMindfulCarryGear()
            || !wpsPackAnimalHauls()
            || !wpsAvgCharHauls()
            || !wpsWaterproofClothCover()
            || !wpsMultiPiecePole()
            || !wpsPitchAwayFromWind()
            || !wpsSimpleFitsOneHuman()
            || !wpsTwoMenInPinch()
            || !wpsElaborateForVicious()
            || !wpsCategoryByQualityAndCapacity()
        )
            ++bad;
        // Table 36: portable shelter characteristics, the four-quality-band
        // by three-size grid (encumbrance value, cost, setup time dice,
        // moisture resistance tier, wind resistance, life span), printed p.
        // 62
        int C36[12][7] = {
            {350,10,2,1,0,20,40},
            {450,20,2,2,0,20,40},
            {600,30,2,3,0,20,40},
            {500,30,3,1,1,30,80},
            {600,50,3,2,1,30,80},
            {750,75,3,3,1,30,80},
            {600,75,3,1,2,40,120},
            {800,120,3,2,2,40,120},
            {1000,180,4,2,2,40,120},
            {750,200,4,1,3,50,180},
            {1000,300,4,2,3,50,180},
            {1500,400,4,3,3,50,180},
            };
        int n36[7] = {0,0,0,0,0,0,0};
        int e36[7] = {0,0,0,0,0,0,0};
        for (int b = 0;
             b < wpsRowCount();
             ++b) {
            int vals[7];
            vals[0] = wpsEncValue(b);
            vals[1] = wpsCost(b);
            vals[2] = wpsSetupDie(b);
            vals[3] = wpsSetupMod(b);
            vals[4] = wpsMoistTier(b);
            vals[5] = wpsWindRes(b);
            vals[6] = wpsLifeSpan(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != C36[b][c])
                    ++bad;
                if (vals[c] == 999)
                    ++n36[c];
            }
        }
        for (int c = 0; c < 7; ++c)
            if (n36[c] != e36[c])
                ++bad;
        // the pole ladder: 6-10 feet
    if (wpsPoleMinFeet() != 6
            || wpsPoleMaxFeet() != 10
            || wpsPoleMinFeet() >= wpsPoleMaxFeet()
        )
            ++bad;
        // the pitch ladder: 30 to 45 degrees
    if (wpsPitchMinAngle() != 30
            || wpsPitchMaxAngle() != 45
            || wpsPitchMinAngle() >= wpsPitchMaxAngle()
        )
            ++bad;
        // the pole pieces: a two- or three-piece apparatus at most
    if (wpsMaxPolePieces() != 3
        )
            ++bad;
        // the grid geometry: four bands of three sizes, twelve rows
    if (wpsQualityBands() != 4
            || wpsSizesPerBand() != 3
            || wpsRowCount() != 12
        )
            ++bad;
        // the p. 61 seam tail and the DM judgment
    if (wpsCaveSlopeSuperior() != 1
            || wpsDmJudgmentPrevails() != 1
        )
            ++bad;
        // the hauling rules: the pack animal and the average-strength
        // character
    if (wpsMindfulCarryGear() != 1
            || wpsPackAnimalHauls() != 1
            || wpsAvgCharHauls() != 1
        )
            ++bad;
        // the simple shelter: waterproof cloth, the multi-piece pole option
        // and the pitch discipline
    if (wpsWaterproofClothCover() != 1
            || wpsMultiPiecePole() != 1
            || wpsPitchAwayFromWind() != 1
        )
            ++bad;
        // the occupancy: one human or a pair of smaller characters, two men
        // in a pinch
    if (wpsSimpleFitsOneHuman() != 1
            || wpsTwoMenInPinch() != 1
        )
            ++bad;
        // the category basis and the vicious-weather escalation
    if (wpsCategoryByQualityAndCapacity() != 1
            || wpsElaborateForVicious() != 1
        )
            ++bad;
        // the encumbrance value column: 350/450/600 poor, 500/600/750
        // adequate, 600/800/1000 good, 750/1000/1500 superior
    if (wpsEncValue(0) != 350
            || wpsEncValue(1) != 450
            || wpsEncValue(2) != 600
            || wpsEncValue(3) != 500
            || wpsEncValue(4) != 600
            || wpsEncValue(5) != 750
            || wpsEncValue(6) != 600
            || wpsEncValue(7) != 800
            || wpsEncValue(8) != 1000
            || wpsEncValue(9) != 750
            || wpsEncValue(10) != 1000
            || wpsEncValue(11) != 1500
        )
            ++bad;
        // the cost column: 10/20/30 poor through 200/300/400 superior
    if (wpsCost(0) != 10
            || wpsCost(1) != 20
            || wpsCost(2) != 30
            || wpsCost(3) != 30
            || wpsCost(4) != 50
            || wpsCost(5) != 75
            || wpsCost(6) != 75
            || wpsCost(7) != 120
            || wpsCost(8) != 180
            || wpsCost(9) != 200
            || wpsCost(10) != 300
            || wpsCost(11) != 400
        )
            ++bad;
        // the setup time die column: 1d2 in the poor band, 1d3 in adequate
        // and good except the good large 1d4, 1d4 in superior
    if (wpsSetupDie(0) != 2
            || wpsSetupDie(1) != 2
            || wpsSetupDie(2) != 2
            || wpsSetupDie(3) != 3
            || wpsSetupDie(4) != 3
            || wpsSetupDie(5) != 3
            || wpsSetupDie(6) != 3
            || wpsSetupDie(7) != 3
            || wpsSetupDie(8) != 4
            || wpsSetupDie(9) != 4
            || wpsSetupDie(10) != 4
            || wpsSetupDie(11) != 4
        )
            ++bad;
        // the setup time modifier column: +1/+2/+3 by size except the good
        // large +2
    if (wpsSetupMod(0) != 1
            || wpsSetupMod(1) != 2
            || wpsSetupMod(2) != 3
            || wpsSetupMod(3) != 1
            || wpsSetupMod(4) != 2
            || wpsSetupMod(5) != 3
            || wpsSetupMod(6) != 1
            || wpsSetupMod(7) != 2
            || wpsSetupMod(8) != 2
            || wpsSetupMod(9) != 1
            || wpsSetupMod(10) != 2
            || wpsSetupMod(11) != 3
        )
            ++bad;
        // the moisture tier column: light, moderate, heavy, downpour by band
    if (wpsMoistTier(0) != 0
            || wpsMoistTier(1) != 0
            || wpsMoistTier(2) != 0
            || wpsMoistTier(3) != 1
            || wpsMoistTier(4) != 1
            || wpsMoistTier(5) != 1
            || wpsMoistTier(6) != 2
            || wpsMoistTier(7) != 2
            || wpsMoistTier(8) != 2
            || wpsMoistTier(9) != 3
            || wpsMoistTier(10) != 3
            || wpsMoistTier(11) != 3
        )
            ++bad;
        // the wind resistance column: 20 poor, 30 adequate, 40 good, 50
        // superior
    if (wpsWindRes(0) != 20
            || wpsWindRes(1) != 20
            || wpsWindRes(2) != 20
            || wpsWindRes(3) != 30
            || wpsWindRes(4) != 30
            || wpsWindRes(5) != 30
            || wpsWindRes(6) != 40
            || wpsWindRes(7) != 40
            || wpsWindRes(8) != 40
            || wpsWindRes(9) != 50
            || wpsWindRes(10) != 50
            || wpsWindRes(11) != 50
        )
            ++bad;
        // the life span column: 40/80/120/180 days by band
    if (wpsLifeSpan(0) != 40
            || wpsLifeSpan(1) != 40
            || wpsLifeSpan(2) != 40
            || wpsLifeSpan(3) != 80
            || wpsLifeSpan(4) != 80
            || wpsLifeSpan(5) != 80
            || wpsLifeSpan(6) != 120
            || wpsLifeSpan(7) != 120
            || wpsLifeSpan(8) != 120
            || wpsLifeSpan(9) != 180
            || wpsLifeSpan(10) != 180
            || wpsLifeSpan(11) != 180
        )
            ++bad;
        // the setup time ladders: the good large outlier 1d4+2 breaks the
        // 1d3+ pattern of its band
    if (wpsSetupDie(8) != 4
            || wpsSetupMod(8) != 2
            || wpsSetupDie(7) != 3
            || wpsSetupMod(7) != 2
        )
            ++bad;
        // within each size the encumbrance value rises with quality: 350 <
        // 500 < 600 < 750 small, 450 < 600 < 800 < 1000 medium, 600 < 750 <
        // 1000 < 1500 large
    if (wpsEncValue(0) >= wpsEncValue(3)
            || wpsEncValue(3) >= wpsEncValue(6)
            || wpsEncValue(6) >= wpsEncValue(9)
            || wpsEncValue(1) >= wpsEncValue(4)
            || wpsEncValue(4) >= wpsEncValue(7)
            || wpsEncValue(7) >= wpsEncValue(10)
            || wpsEncValue(2) >= wpsEncValue(5)
            || wpsEncValue(5) >= wpsEncValue(8)
            || wpsEncValue(8) >= wpsEncValue(11)
        )
            ++bad;
        // within each band the encumbrance value and cost rise with size
    if (wpsEncValue(0) >= wpsEncValue(1)
            || wpsEncValue(1) >= wpsEncValue(2)
            || wpsEncValue(3) >= wpsEncValue(4)
            || wpsEncValue(4) >= wpsEncValue(5)
            || wpsEncValue(6) >= wpsEncValue(7)
            || wpsEncValue(7) >= wpsEncValue(8)
            || wpsEncValue(9) >= wpsEncValue(10)
            || wpsEncValue(10) >= wpsEncValue(11)
            || wpsCost(0) >= wpsCost(1)
            || wpsCost(1) >= wpsCost(2)
            || wpsCost(3) >= wpsCost(4)
            || wpsCost(4) >= wpsCost(5)
            || wpsCost(6) >= wpsCost(7)
            || wpsCost(7) >= wpsCost(8)
            || wpsCost(9) >= wpsCost(10)
            || wpsCost(10) >= wpsCost(11)
        )
            ++bad;
        // every cell in bounds: each encumbrance value at least 350, each
        // wind resistance at least 20, each life span at least 40
    if (wpsEncValue(0) < 350
            || wpsEncValue(1) < 350
            || wpsEncValue(2) < 350
            || wpsEncValue(3) < 350
            || wpsEncValue(4) < 350
            || wpsEncValue(5) < 350
            || wpsEncValue(6) < 350
            || wpsEncValue(7) < 350
            || wpsEncValue(8) < 350
            || wpsEncValue(9) < 350
            || wpsEncValue(10) < 350
            || wpsEncValue(11) < 350
            || wpsWindRes(0) < 20
            || wpsWindRes(11) < 20
            || wpsLifeSpan(0) < 40
            || wpsLifeSpan(11) < 40
        )
            ++bad;
        printf("R472 WSG portable shelters pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
