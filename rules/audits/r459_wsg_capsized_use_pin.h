    // ---- R459 WSG capsized use pin audit ----
    // The capsized-use slice pins the natural buoyancy (most vessels remain
    // afloat just beneath the surface after capsizing or hull damage), the
    // flotation preconditions (no passengers and no more than 10% of the
    // listed maximum cargo capacity, with the small-rowboat 200 gp example),
    // the cling-to-the-sides flotation with the even-weight-distribution
    // requirement, the twice-capacity support figure (eight characters around
    // a large rowboat), and the sink rules when the weight limit is exceeded
    // or the weight is unevenly distributed (rules/wsgcapsized.h, prefix
    // wcv); census 383 -> 384.
    {
        using namespace rules;
        int bad = 0;
    if (wcvVesselCount() != 8
            || wcvMaxCargoPercent() != 10
            || wcvSupportMultiplier() != 2
            || wcvExampleRowboatCargoGp() != 200
            || wcvExampleRowboatSupport() != 8
            || !wcvBuoyantJustBeneathSurface()
            || !wcvWorksAfterCapsizeOrHullDamage()
            || !wcvRequiresNoPassengers()
            || !wcvCargoWithinMaxPercent()
            || !wcvClingToSidesAsFlotation()
            || !wcvWeightMustBeEven()
            || !wcvExcessWeightSinks()
            || !wcvUnevenWeightSinks()
        )
            ++bad;
        // the 10% cargo condition with the small-rowboat example: 200 gp is
        // ten percent of the 2000 gp listed maximum cargo capacity
    if (wcvMaxCargoPercent() != 10
            || wcvExampleRowboatCargoGp() != 200
            || wcvExampleRowboatCargoGp() != 20 * wcvMaxCargoPercent()
        )
            ++bad;
        // the twice-capacity support: the large rowboat with a normal
        // capacity of four supports eight clinging characters - twice its
        // capacity
    if (wcvSupportMultiplier() != 2
            || wcvExampleRowboatSupport() != 8
            || wcvExampleRowboatSupport() != 4 * wcvSupportMultiplier()
        )
            ++bad;
        // the three preconditions: no passengers, cargo within the 10% limit,
        // and the clinging weight evenly distributed
    if (wcvRequiresNoPassengers() != 1
            || wcvCargoWithinMaxPercent() != 1
            || wcvWeightMustBeEven() != 1
        )
            ++bad;
        // the two sink triggers: exceeding the twice-capacity weight limit,
        // or uneven weight distribution - either sinks the craft too far
        // below the surface to be usable
    if (wcvExcessWeightSinks() != 1
            || wcvUnevenWeightSinks() != 1
        )
            ++bad;
        printf("R459 WSG capsized use pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
