    // ---- R566 MotP Ethereal audit ----
    // the Ethereal chapter in one round (the R557 pattern) with the R566
    // amendment riding in the same commit: the proto-matter ocean and its
    // curtains, the Border/Deep split, the 10x subjective-time factor with
    // aging at the subjective rate, 100-yard vision, the
    // 1-in-10-per-four-hours Deep check, the one-round fade both ways, the
    // zero-base normal weapons and the one-plus magic reduction, the +20%
    // thief shadow bonus, the four named demi-planes, and the book-wide 2-20
    // d8+d12 chart doctrine from p. 7
    {
        using namespace rules;
        int bad = 0;
    if (dcuCustomChartLow() != 2
            || dcuCustomChartHigh() != 20
            || dcuEtherealTimeFactor() != 10
            || dcuEtherealVisionYards() != 100
            || dcuFadeRounds() != 1
            || dcuDeepEncounterChance() != 10
            || dcuMagicPlusReduction() != 1
            || dcuThiefShadowBonus() != 20
            || dcuDemiPlaneNamedCount() != 4
            || !dcuNoFallingEth()
            || !dcuNormalWeaponsZeroBase()
            || !dcuBorderCrossingBlind()
            || !dcuHealingSubjectiveSlow()
        )
            ++bad;
        // the CustomChartLow pin
    if (dcuCustomChartLow() != 2
        )
            ++bad;
        // the CustomChartHigh pin
    if (dcuCustomChartHigh() != 20
        )
            ++bad;
        // the EtherealTimeFactor pin
    if (dcuEtherealTimeFactor() != 10
        )
            ++bad;
        // the EtherealVisionYards pin
    if (dcuEtherealVisionYards() != 100
        )
            ++bad;
        // the FadeRounds pin
    if (dcuFadeRounds() != 1
        )
            ++bad;
        // the DeepEncounterChance pin
    if (dcuDeepEncounterChance() != 10
        )
            ++bad;
        // the MagicPlusReduction pin
    if (dcuMagicPlusReduction() != 1
        )
            ++bad;
        // the ThiefShadowBonus pin
    if (dcuThiefShadowBonus() != 20
        )
            ++bad;
        // the DemiPlaneNamedCount pin
    if (dcuDemiPlaneNamedCount() != 4
        )
            ++bad;
        // the NoFallingEth pin
    if (dcuNoFallingEth() != 1
        )
            ++bad;
        // the NormalWeaponsZeroBase pin
    if (dcuNormalWeaponsZeroBase() != 1
        )
            ++bad;
        // the BorderCrossingBlind pin
    if (dcuBorderCrossingBlind() != 1
        )
            ++bad;
        // the HealingSubjectiveSlow pin
    if (dcuHealingSubjectiveSlow() != 1
        )
            ++bad;
        printf("R566 MotP Ethereal audit: bad %d\n", bad);
        if (bad) return 1;
    }
