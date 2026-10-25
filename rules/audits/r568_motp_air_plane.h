    // ---- R568 MotP Air plane audit ----
    // the Plane of Elemental Air, printed pp. 31-36, the whole chapter: the
    // hospitable-plane doctrine with the four border gradations (Smoke, Ice,
    // Lightning, Vacuum), the 1,000-yard sighting, the 1-in-20-per-12-hours
    // encounter check with its three-way split, the d12 phenomena table
    // (cloud banks through the maelstrom and the Prime vortex), the
    // WSG-adapted high-winds table with the 80-mph verbal cutoff and the
    // 1d8-per-10-mph impact damage, the d20 pocket table with the sixteen
    // pocket types, the d8+d12 encounter chart, the invisible natives, and
    // the features (Yan-C-Bin, Akadi, Bahamut's citadel, the djinn landholds,
    // the hooks and bubbles) - magic as the inner planes in general (p. 35).
    {
        using namespace rules;
        int bad = 0;
    if (dcwAirSightingYards() != 1000
            || dcwAirEncounterDenom() != 20
            || dcwAirPhenomenaDieSides() != 12
            || dcwAirPocketTableDie() != 20
            || dcwAirChartDieSides() != 12
            || dcwAirWindCutoffMPH() != 80
            || dcwAirMaelstromEscapeFt() != 2000
            || dcwAirVortexDenom() != 50
            || !dcwAirHospitable()
            || !dcwAirBordersGrade()
            || !dcwAirNativesInvisible()
            || !dcwAirDjinnLandhold()
        )
            ++bad;
        // the AirSightingYards pin
    if (dcwAirSightingYards() != 1000
        )
            ++bad;
        // the AirEncounterDenom pin
    if (dcwAirEncounterDenom() != 20
        )
            ++bad;
        // the AirPhenomenaDieSides pin
    if (dcwAirPhenomenaDieSides() != 12
        )
            ++bad;
        // the AirPocketTableDie pin
    if (dcwAirPocketTableDie() != 20
        )
            ++bad;
        // the AirChartDieSides pin
    if (dcwAirChartDieSides() != 12
        )
            ++bad;
        // the AirWindCutoffMPH pin
    if (dcwAirWindCutoffMPH() != 80
        )
            ++bad;
        // the AirMaelstromEscapeFt pin
    if (dcwAirMaelstromEscapeFt() != 2000
        )
            ++bad;
        // the AirVortexDenom pin
    if (dcwAirVortexDenom() != 50
        )
            ++bad;
        // the AirHospitable pin
    if (dcwAirHospitable() != 1
        )
            ++bad;
        // the AirBordersGrade pin
    if (dcwAirBordersGrade() != 1
        )
            ++bad;
        // the AirNativesInvisible pin
    if (dcwAirNativesInvisible() != 1
        )
            ++bad;
        // the AirDjinnLandhold pin
    if (dcwAirDjinnLandhold() != 1
        )
            ++bad;
        printf("R568 MotP Air plane audit: bad %d\n", bad);
        if (bad) return 1;
    }
