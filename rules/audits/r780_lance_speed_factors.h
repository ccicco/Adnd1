    // ---- R780 lance speed factors audit ----
    // THE LANCE SPEED FACTORS - the R158 ladder grows its three lance rows.
    // The PHB p.38 speed column cells (the 1eonline.info compilation, the
    // repo-trusted source the R189 speed-verify duty already reads): light
    // horse 7, medium horse 6, heavy horse 8 - the medium horse lance OUTRUNS
    // the light (a 12-foot shaft faster than a 10-foot one: the print is the
    // print, the engine follows it, the R779 zero-row pattern in reverse).
    // The ladder stays PURE DATA - no engine caller exists, the DMG p.66
    // caller-detected cases stay contract-side, and the printed lengths
    // (10/12/14 feet) ride no engine concept. The standing weaponspeed.h
    // pragma once is UNTOUCHED - the R778 classic-guard rule governs new
    // guards, not standing files; the R158 audit gains the three ladder
    // checks against the header pins
    {
        using namespace rules;
        int bad = 0;
    if (lspSpeedFeederRound() != 158
            || lspLanceSpeedRound() != 780
            || lspLanceSpeedRowCount() != 3
            || lspLightLanceSpeedFactor() != 7
            || lspMediumLanceSpeedFactor() != 6
            || lspHeavyLanceSpeedFactor() != 8
            || !lspLancesRideTheR158Ladder()
            || !lspMediumOutrunsTheLight()
            || !lspLadderStaysPureData()
            || !lspLanceLengthsStayContractSide()
        )
            ++bad;
        printf("R780 lance speed factors audit: bad %d\n", bad);
        if (bad) return 1;
    }
