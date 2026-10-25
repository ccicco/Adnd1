    // ---- R648 OA barding prose audit ----
    // OA round thirty-five (capture pp. 98-99): the barding prose - the AC
    // factors, the weights and the half-barding doctrine
    {
        using namespace rules;
        int bad = 0;
    if (dhiBardingMatCount() != 3
            || dhiLeatherAcFactor() != 1
            || dhiLeatherWeight() != 160
            || dhiMetalAcFactor() != 2
            || dhiMetalWeight() != 250
            || dhiChainAcFactor() != 3
            || dhiChainWeight() != 350
            || dhiHalfWeightDiv() != 2
            || !dhiHalfMoreCommon()
            || !dhiPlateNeverUsed()
            || !dhiHalfFrontalOnly()
            || !dhiRearNoBonus()
            || !dhiMustCarryWeight()
        )
            ++bad;
        // the barding material count pin - the AC-factor list
    if (dhiBardingMatCount() != 3
        )
            ++bad;
        // the leather-or-padded factor and weight pins - 1 factor, 160#
    if (dhiLeatherAcFactor() != 1
            || dhiLeatherWeight() != 160
        )
            ++bad;
        // the metal-scale factor and weight pins - 2 factors, 250#
    if (dhiMetalAcFactor() != 2
            || dhiMetalWeight() != 250
        )
            ++bad;
        // the chain factor and weight pins - 3 factors, 350#
    if (dhiChainAcFactor() != 3
            || dhiChainWeight() != 350
        )
            ++bad;
        // the half-barding weight divisor pin - half of full
    if (dhiHalfWeightDiv() != 2
        )
            ++bad;
        // the half-barding doctrine pins - frontal only, rear no bonus, more
        // common
    if (dhiHalfFrontalOnly() != 1
            || dhiRearNoBonus() != 1
            || dhiHalfMoreCommon() != 1
        )
            ++bad;
        // the plate-never-used rule pin
    if (dhiPlateNeverUsed() != 1
        )
            ++bad;
        // the must-carry-weight rule pin
    if (dhiMustCarryWeight() != 1
        )
            ++bad;
        printf("R648 OA barding prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
