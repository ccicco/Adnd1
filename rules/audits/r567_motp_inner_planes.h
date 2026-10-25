    // ---- R567 MotP inner planes audit ----
    // the inner-planes general doctrine (pp. 22-31): the 18-plane sphere (six
    // major, twelve minor), the inborn hostility, the three reaching methods
    // (the Ethereal curtains, the para-/quasi- borders, the vortices), the
    // 2d4 breathless rule, the 1:2 subjective-time reversal, the
    // local-gravity doctrine with the 1,000-feet-per-round fall rate, the
    // elemental-guide system with the 100-gp-per-hour inducements, the
    // native-frequency one-rank decay rule, and the school-effects matrix
    // (divinations all work; abjuration and alteration limited; conjurations
    // plane-tied; illusions and enchantments normal; necromancy split by
    // energy)
    {
        using namespace rules;
        int bad = 0;
    if (dcvInnerMajorPlaneCount() != 6
            || dcvInnerMinorPlaneCount() != 12
            || dcvBreathlessDieSides() != 4
            || dcvFallRateFeet() != 1000
            || dcvGuideBorderHours() != 100
            || dcvGuideInducementGP() != 100
            || dcvHumanLoneMinLevel() != 20
            || !dcvInbornHostility()
            || !dcvNativesSeeBorderEthereal()
            || !dcvTimeFasterInner()
            || !dcvLocalGravity()
            || !dcvUltravisionFails()
            || !dcvUnguidedRandomDirection()
            || !dcvElementalImmunityHome()
        )
            ++bad;
        // the InnerMajorPlaneCount pin
    if (dcvInnerMajorPlaneCount() != 6
        )
            ++bad;
        // the InnerMinorPlaneCount pin
    if (dcvInnerMinorPlaneCount() != 12
        )
            ++bad;
        // the BreathlessDieSides pin
    if (dcvBreathlessDieSides() != 4
        )
            ++bad;
        // the FallRateFeet pin
    if (dcvFallRateFeet() != 1000
        )
            ++bad;
        // the GuideBorderHours pin
    if (dcvGuideBorderHours() != 100
        )
            ++bad;
        // the GuideInducementGP pin
    if (dcvGuideInducementGP() != 100
        )
            ++bad;
        // the HumanLoneMinLevel pin
    if (dcvHumanLoneMinLevel() != 20
        )
            ++bad;
        // the InbornHostility pin
    if (dcvInbornHostility() != 1
        )
            ++bad;
        // the NativesSeeBorderEthereal pin
    if (dcvNativesSeeBorderEthereal() != 1
        )
            ++bad;
        // the TimeFasterInner pin
    if (dcvTimeFasterInner() != 1
        )
            ++bad;
        // the LocalGravity pin
    if (dcvLocalGravity() != 1
        )
            ++bad;
        // the UltravisionFails pin
    if (dcvUltravisionFails() != 1
        )
            ++bad;
        // the UnguidedRandomDirection pin
    if (dcvUnguidedRandomDirection() != 1
        )
            ++bad;
        // the ElementalImmunityHome pin
    if (dcvElementalImmunityHome() != 1
        )
            ++bad;
        printf("R567 MotP inner planes audit: bad %d\n", bad);
        if (bad) return 1;
    }
