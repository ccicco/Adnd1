    // ---- R484 WSG ultravision pin audit ----
    // The ultravision and infravision effectiveness rules: infravision is
    // useless in daylight or under artificial illumination stronger than
    // moonlight, the normally visible light overriding the heat radiation. A
    // character using infravision sees heat as light - very cold objects very
    // dark, hot objects very bright, temperatures between the two as varying
    // shades of gray - with the color of objects classified on a scale from 1
    // (pitch black, below -50) to 10 (excruciatingly bright, above 130), the
    // interior bands -50 to -11, -10 to 15, 16 to 32, 33 to 50, 51 to 70, 71
    // to 90, 91 to 110 and 111 to 130 each contiguous with its neighbors. The
    // air temperature dictates the overall brightness; a surface temperature
    // warmer or colder than the air shows as a brighter or darker image. A
    // human (body temperature approximately 98 degrees) in normal clothing
    // appears brighter than his surroundings when the air is 90 or lower, as
    // do demi-humans and most size M humanoids; a human bundled in heavy
    // clothing matches the air and is undetectable, save small uncovered
    // spots of brightness - or darkness in very hot air. Obstruction blocks
    // detection as with normal vision, but a great source of heat or cold may
    // be indirectly detectable through the air it warms: a campfire behind a
    // large rock shows the rock's near side as a dark shape against a lighter
    // background. Extreme heat or cold with everything at one temperature
    // renders infravision useless - below -50 all pitch black, above 130 a
    // blanket of almost blinding brightness - and sudden close proximity to
    // great heat (a wall of fire) inflicts heat blindness, burning the power
    // out until cure blindness, or temporarily blinding to infrared rays for
    // 5-10 turns (1d6+4). Cold-blooded creatures (reptiles, insects, most
    // nonmammalians) are undetectable at air temperature, but magic that
    // abruptly changes the air temperature reveals them briefly. Ultravision,
    // or night vision, sees into the ultraviolet range, distinguishing
    // colors, shapes and relative positions even in darkness; only the deep
    // gnome has it inborn, night vision to 30 yards as if by normal vision in
    // daylight; others gain it temporarily by magic (lens of ultravision, the
    // magic-user or illusionist ultravision spell), capabilities varying by
    // means. It is useless under any light brighter than moonlight - daylight
    // or artificial illumination yields nothing but blackness - and works
    // best on a moonless night under a clear sky: partly cloudy x 2/3,
    // overcast x 1/2, moonlight partly cloudy x 1/3, moonlight overcast x
    // 1/4, viewer under thick cover x 1/4, the last cumulative - a thick
    // forest on a moonlit overcast night leaves only 1/16 of the ideal range.
    {
        using namespace rules;
        int bad = 0;
    if (wuvColorScaleMin() != 1
            || wuvColorScaleMax() != 10
            || wuvBand2Low() != -50
            || wuvBand2High() != -11
            || wuvBand3Low() != -10
            || wuvBand3High() != 15
            || wuvBand4Low() != 16
            || wuvBand4High() != 32
            || wuvBand5Low() != 33
            || wuvBand5High() != 50
            || wuvBand6Low() != 51
            || wuvBand6High() != 70
            || wuvBand7Low() != 71
            || wuvBand7High() != 90
            || wuvBand8Low() != 91
            || wuvBand8High() != 110
            || wuvBand9Low() != 111
            || wuvBand9High() != 130
            || wuvHumanBodyTempF() != 98
            || wuvBrightBelowAirF() != 90
            || wuvTempBlindMinTurns() != 5
            || wuvTempBlindMaxTurns() != 10
            || wuvTempBlindDice() != 6
            || wuvTempBlindPlus() != 4
            || wuvDeepGnomeRangeYards() != 30
            || wuvMoonlessCloudyNum() != 2
            || wuvMoonlessCloudyDen() != 3
            || wuvMoonlessOvercastNum() != 1
            || wuvMoonlessOvercastDen() != 2
            || wuvMoonlightCloudyNum() != 1
            || wuvMoonlightCloudyDen() != 3
            || wuvMoonlightOvercastNum() != 1
            || wuvMoonlightOvercastDen() != 4
            || wuvThickCoverNum() != 1
            || wuvThickCoverDen() != 4
            || wuvForestExampleNum() != 1
            || wuvForestExampleDen() != 16
            || !wuvUselessInDaylight()
            || !wuvVisibleLightOverrides()
            || !wuvSeesHeatAsLight()
            || !wuvColdDarkHotBright()
            || !wuvScale1PitchBlack()
            || !wuvScale10Excruciating()
            || !wuvAirTempDictates()
            || !wuvWarmerColderShows()
            || !wuvHumanBrightAt90OrBelow()
            || !wuvDemiHumanSameRule()
            || !wuvBundledUndetectable()
            || !wuvUncoveredSpotsShow()
            || !wuvUncoveredDarkIfHot()
            || !wuvObstructionBlocks()
            || !wuvStrongHeatIndirect()
            || !wuvCampfireRockExample()
            || !wuvExtremeSameTempUseless()
            || !wuvVeryColdPitchBlack()
            || !wuvVeryHotBlinding()
            || !wuvHeatBlindnessRisk()
            || !wuvWallOfFireBurnout()
            || !wuvTempBlindRecover()
            || !wuvColdBloodedUndetected()
            || !wuvMagicTempReveals()
            || !wuvNightVisionDefinition()
            || !wuvDarknessRedefined()
            || !wuvDeepGnomeOnly()
            || !wuvDeepGnomeDaylightQuality()
            || !wuvMagicalAcquisition()
            || !wuvMagicalCapabilitiesVary()
            || !wuvUltraUselessInLight()
            || !wuvUltraDaylightBlackness()
            || !wuvBestMoonlessClear()
            || !wuvThickCoverCumulative()
        )
            ++bad;
        // the interior color bands are contiguous: each band's low is one
        // above the previous band's high
    if (wuvBand3Low() != wuvBand2High() + 1
            || wuvBand4Low() != wuvBand3High() + 1
            || wuvBand5Low() != wuvBand4High() + 1
            || wuvBand6Low() != wuvBand5High() + 1
            || wuvBand7Low() != wuvBand6High() + 1
            || wuvBand8Low() != wuvBand7High() + 1
            || wuvBand9Low() != wuvBand8High() + 1
        )
            ++bad;
        // the 5-10 turn recovery is 1d6+4: min is one on the die plus the
        // plus, max is sides plus the plus
    if (wuvTempBlindMinTurns() != 1 + wuvTempBlindPlus()
            || wuvTempBlindMaxTurns() != wuvTempBlindDice() +
            wuvTempBlindPlus()
        )
            ++bad;
        // the worked human example: body 98, brighter than surroundings at
        // air 90 or lower
    if (wuvHumanBodyTempF() != 98
            || wuvBrightBelowAirF() != 90
        )
            ++bad;
        // the thick forest on a moonlit overcast night: 1/4 times 1/4 = 1/16
        // of ideal range
    if (wuvForestExampleNum() != wuvThickCoverNum() *
        wuvMoonlightOvercastNum()
            || wuvForestExampleDen() != wuvThickCoverDen() *
            wuvMoonlightOvercastDen()
        )
            ++bad;
        // the modifier ladder descends: 2/3 over 1/2 over 1/3
        // (cross-multiplied, strict)
    if (wuvMoonlessCloudyNum() * wuvMoonlessOvercastDen() <=
        wuvMoonlessCloudyDen() * wuvMoonlessOvercastNum()
            || wuvMoonlessOvercastNum() * wuvMoonlightCloudyDen() <=
            wuvMoonlessOvercastDen() * wuvMoonlightCloudyNum()
            || wuvMoonlightCloudyNum() * wuvMoonlightOvercastDen() <=
            wuvMoonlightCloudyDen() * wuvMoonlightOvercastNum()
        )
            ++bad;
        printf("R484 WSG ultravision pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
