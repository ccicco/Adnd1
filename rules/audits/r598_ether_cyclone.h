    // ---- R598 Ether cyclone audit ----
    // ETHER CYCLONE, printed p. 17: the sinuous storm of the Deep Ethereal -
    // the 50% warning (the 1d6-round deep-hum herald), the one-roll-per-group
    // doctrine, the d20 effects from the disrupted flow (+4 hours, one extra
    // encounter check) through the curtain blows (the random Border, and the
    // farther-plane +5d12 days) to the saving throw of the lowest-level
    // member (success: an unexplored section with 10d12 days added; failure:
    // the Astral tumble, as plane shift, no silver cord), and the aftermath:
    // the Prime fallback saves, the inner-plane Border stop, and the
    // demi-plane of Time caveat.
    {
        using namespace rules;
        int bad = 0;
    if (dedCycloneWarningChance() != 50
            || dedCycloneWarningRoundsHigh() != 6
            || dedCycloneDisruptedHigh() != 10
            || dedCycloneDisruptedHours() != 4
            || dedCycloneCurtainHigh() != 15
            || dedCycloneFartherHigh() != 18
            || dedCycloneFartherDaysDice() != 5
            || dedCycloneFartherDaysSides() != 12
            || dedCycloneSaveHigh() != 20
            || dedCycloneLostDaysDice() != 10
            || dedCycloneLostDaysSides() != 12
            || !dedCycloneGroupRoll()
            || !dedCycloneLowestLevelSaves()
            || !dedCycloneAstralNoCord()
            || !dedCyclonePrimeFallback()
            || !dedCycloneInnerBorderStop()
            || !dedCycloneTimeBorderDanger()
        )
            ++bad;
        // the dedCycloneWarningChance pin
    if (dedCycloneWarningChance() != 50
        )
            ++bad;
        // the dedCycloneWarningRoundsHigh pin
    if (dedCycloneWarningRoundsHigh() != 6
        )
            ++bad;
        // the dedCycloneDisruptedHigh pin
    if (dedCycloneDisruptedHigh() != 10
        )
            ++bad;
        // the dedCycloneDisruptedHours pin
    if (dedCycloneDisruptedHours() != 4
        )
            ++bad;
        // the dedCycloneCurtainHigh pin
    if (dedCycloneCurtainHigh() != 15
        )
            ++bad;
        // the dedCycloneFartherHigh pin
    if (dedCycloneFartherHigh() != 18
        )
            ++bad;
        // the dedCycloneFartherDaysDice pin
    if (dedCycloneFartherDaysDice() != 5
        )
            ++bad;
        // the dedCycloneFartherDaysSides pin
    if (dedCycloneFartherDaysSides() != 12
        )
            ++bad;
        // the dedCycloneSaveHigh pin
    if (dedCycloneSaveHigh() != 20
        )
            ++bad;
        // the dedCycloneLostDaysDice pin
    if (dedCycloneLostDaysDice() != 10
        )
            ++bad;
        // the dedCycloneLostDaysSides pin
    if (dedCycloneLostDaysSides() != 12
        )
            ++bad;
        // the dedCycloneGroupRoll pin
    if (dedCycloneGroupRoll() != 1
        )
            ++bad;
        // the dedCycloneLowestLevelSaves pin
    if (dedCycloneLowestLevelSaves() != 1
        )
            ++bad;
        // the dedCycloneAstralNoCord pin
    if (dedCycloneAstralNoCord() != 1
        )
            ++bad;
        // the dedCyclonePrimeFallback pin
    if (dedCyclonePrimeFallback() != 1
        )
            ++bad;
        // the dedCycloneInnerBorderStop pin
    if (dedCycloneInnerBorderStop() != 1
        )
            ++bad;
        // the dedCycloneTimeBorderDanger pin
    if (dedCycloneTimeBorderDanger() != 1
        )
            ++bad;
        printf("R598 Ether cyclone audit: bad %d\n", bad);
        if (bad) return 1;
    }
