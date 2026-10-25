    // ---- R442 WSG rappelling pin audit ----
    // The rappelling slice pins the rope-secured descent of a non-horizontal
    // surface - the 120-feet-per-round base speed (encumbrance and other
    // penalties apply as for an ascent), the +50% Climbing Check modifier per
    // round or part of a round, the lost-grip failure state (hanging upside
    // down, spinning, until rescued or a successful Dexterity Check - allowed
    // once per round), and the free-hanging-rope variant (no surface to brace
    // against: +30% instead of +50%, Dex checks at +2) (rules/wsgrapp.h,
    // prefix wrl); census 366 -> 367.
    {
        using namespace rules;
        int bad = 0;
    if (wrlBaseSpeedFtPerRound() != 120
            || wrlSlopeCheckModPct() != 50
            || wrlFreeHangCheckModPct() != 30
            || wrlFreeHangDexMod() != 2
            || !wrlEncumbrancePenaltiesApply()
            || !wrlCheckPerRoundOrPart()
            || !wrlFailureHangsUpsideDown()
            || !wrlDexCheckOncePerRound()
            || !wrlFreeHangNoSurfaceToBrace()
        )
            ++bad;
        // the controlled descent: 120 feet per round at base speed
    if (wrlBaseSpeedFtPerRound() != 120
        )
            ++bad;
        // the two rappel modifiers: +50% against a surface, +30% on a
        // free-hanging rope
    if (wrlSlopeCheckModPct() != 50
            || wrlFreeHangCheckModPct() != 30
        )
            ++bad;
        // the free-hanging rope costs 20 points of the Climbing Rating
        // modifier (50 - 30)
    if (wrlSlopeCheckModPct() - wrlFreeHangCheckModPct() != 20
        )
            ++bad;
        // the failed free-hanging check: Dexterity Checks at +2 on the die
        // roll; the speed and slope modifier together anchor the section (120
        // = 50 + 70)
    if (wrlFreeHangDexMod() != 2
            || wrlBaseSpeedFtPerRound() != wrlSlopeCheckModPct() + 70
        )
            ++bad;
        // the surface modifier must beat the free-hanging modifier - +50%
        // against the slope, only +30% with nothing to brace against
    if (wrlSlopeCheckModPct() <= wrlFreeHangCheckModPct()
        )
            ++bad;
        // the descent speed (120 feet per round) clears the combined check
        // modifiers (50 + 30 = 80) - rappelling is faster than climbing,
        // checks aside
    if (wrlBaseSpeedFtPerRound() < wrlSlopeCheckModPct() +
        wrlFreeHangCheckModPct()
        )
            ++bad;
        printf("R442 WSG rappelling pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
