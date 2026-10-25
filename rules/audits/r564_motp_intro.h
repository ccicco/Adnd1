    // ---- R564 MotP intro audit ----
    // the MotP ARC OPENER (the R503 pattern): the introduction pinned - the
    // five groupings (Prime, Ethereal, inner, Astral, outer), the
    // organization pattern every plane chapter follows, the true/subjective
    // time doctrine with its ratios (Prime/outer 1:1, Deep Ethereal 10:1,
    // inner 1:2, Astral 365000:1), the natives-unaffected rule, the Astral
    // spell exemption, and the combined-spell both-limits rule. The pdf
    // offset pinned: printed page + 1 = pdf page for this scan. The
    // spell-summary tables (pp. 8-9, GARBLED OCR) stay open for a
    // reconstruction round.
    {
        using namespace rules;
        int bad = 0;
    if (dcsPlaneGroupCount() != 5
            || dcsEtherealTimeRatio() != 10
            || dcsInnerTimeDivisor() != 2
            || dcsAstralTrueRounds() != 365000
            || !dcsTrueTimeConstant()
            || !dcsNativesUnaffected()
            || !dcsAstralSpellsExempt()
            || !dcsCombinedSpellsBothLimited()
        )
            ++bad;
        // the five planar groupings
    if (dcsPlaneGroupCount() != 5
        )
            ++bad;
        // the Deep Ethereal 10:1 ratio
    if (dcsEtherealTimeRatio() != 10
        )
            ++bad;
        // the inner planes half-duration rule
    if (dcsInnerTimeDivisor() != 2
        )
            ++bad;
        // the Astral 365,000-true-rounds ratio
    if (dcsAstralTrueRounds() != 365000
        )
            ++bad;
        // true time is constant across planes
    if (dcsTrueTimeConstant() != 1
        )
            ++bad;
        // natives unaffected by their plane
    if (dcsNativesUnaffected() != 1
        )
            ++bad;
        // Astral spell casting exempt from the differential
    if (dcsAstralSpellsExempt() != 1
        )
            ++bad;
        // combined spells limited by both types
    if (dcsCombinedSpellsBothLimited() != 1
        )
            ++bad;
        printf("R564 MotP intro audit: bad %d\n", bad);
        if (bad) return 1;
    }
