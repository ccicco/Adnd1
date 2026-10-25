    // ---- R536 DSG Deepearth areas 6-7 audit ----
    // The DSG Deepearth areas 6-7 pin Area 6 (the dead duergar city with its
    // domed chamber, undead palace guard and the forge-of-power anvil) and
    // Area 7 (the Grand Canyon with its mile-deep gorge, mobat swarms,
    // cloakers and disease pools).
    {
        using namespace rules;
        int bad = 0;
    if (dnaeEntryTunnelWidthFt() != 30
            || dnaeEntryTunnelCeilFt() != 10
            || dnaeDomeDiaHalfMile() != 1
            || dnaePalaceFacadeHtFt() != 100
            || dnaePalaceFacadeSideFt() != 300
            || dnaeTunnelIntervalDeg() != 60
            || dnaeSideTunnelCount() != 5
            || dnaeAirStopDice() != 2
            || dnaeAirStopSides() != 6
            || dnaeAirRecoverDice() != 1
            || dnaeAirRecoverSides() != 6
            || dnaeAnvilWeightGp() != 25000
            || dnaeAnvilBonus() != 1
            || dnaeAnvilHammerLow() != 2
            || dnaeAnvilHammerHigh() != 3
            || dnaeCanyonLenMiles() != 10
            || dnaeCanyonWidthMiles() != 1
            || dnaeCanyonCeilFt() != 200
            || dnaeGorgeDepthMiles() != 1
            || dnaeLowerCavernsDepthFt() != 3000
            || dnaeLowerCavernsSouthMiles() != 2
            || dnaeCaveMouthDeepFt() != 300
            || dnaeCaveMouthIntervalFt() != 500
            || dnaeShaftDiaLowFt() != 1
            || dnaeShaftDiaHighFt() != 3
            || dnaeMobatGroupDice() != 2
            || dnaeMobatGroupSides() != 6
            || dnaeCloakerAttractPct() != 50
            || dnaeCloakerCount() != 24
            || dnaePoolDiseasePct() != 50
            || !dnaeExcavatedCity()
            || !dnaeBrassDoors()
            || !dnaeDuergarExodus()
            || !dnaeUndeadHonorGuard()
            || !dnaeDeadAirDry()
            || !dnaeStrippedFragile()
            || !dnaeForgeOfPower()
            || !dnaeCanyonErosionOrigin()
            || !dnaeStableWalls()
            || !dnaeBatSwarms()
            || !dnaeCanyonPredators()
            || !dnaeStagnantPools()
            || !dnaeCanyonFood()
        )
            ++bad;
        // the Ancients city geography: the 30-ft tunnel with its 10-ft
        // ceiling, the half-mile dome, the 100-ft-by-300-ft palace facade,
        // the 60-degree intervals with five tunnels.
    if (dnaeEntryTunnelWidthFt() != 30
            || dnaeEntryTunnelCeilFt() != 10
            || dnaeDomeDiaHalfMile() != 1
            || dnaePalaceFacadeHtFt() != 100
            || dnaePalaceFacadeSideFt() != 300
            || dnaeTunnelIntervalDeg() != 60
            || dnaeSideTunnelCount() != 5
        )
            ++bad;
        // the dead air and the forge: the 2d6-round gasp, the 1d6-round
        // recovery, the 25,000-gp anvil with its +1 bonus and the +2/+3
        // hammer-of-substance combinations.
    if (dnaeAirStopDice() != 2
            || dnaeAirStopSides() != 6
            || dnaeAirRecoverDice() != 1
            || dnaeAirRecoverSides() != 6
            || dnaeAnvilWeightGp() != 25000
            || dnaeAnvilBonus() != 1
            || dnaeAnvilHammerLow() != 2
            || dnaeAnvilHammerHigh() != 3
        )
            ++bad;
        // the Grand Canyon dimensions: the ten-mile length, the mile width,
        // the 200-ft entry ceiling, the gorge over a mile below.
    if (dnaeCanyonLenMiles() != 10
            || dnaeCanyonWidthMiles() != 1
            || dnaeCanyonCeilFt() != 200
            || dnaeGorgeDepthMiles() != 1
        )
            ++bad;
        // the canyon's hidden depths: the 3,000-ft-down, 2-miles-south
        // caverns, the 300-ft cave mouths at 500-ft intervals, the 1-to-3-ft
        // sewer shafts.
    if (dnaeLowerCavernsDepthFt() != 3000
            || dnaeLowerCavernsSouthMiles() != 2
            || dnaeCaveMouthDeepFt() != 300
            || dnaeCaveMouthIntervalFt() != 500
            || dnaeShaftDiaLowFt() != 1
            || dnaeShaftDiaHighFt() != 3
        )
            ++bad;
        // the canyon denizens' numbers: the 2d6 mobat groups, the 50% cloaker
        // attraction, the two dozen cloakers, the 50% pool-disease chance.
    if (dnaeMobatGroupDice() != 2
            || dnaeMobatGroupSides() != 6
            || dnaeCloakerAttractPct() != 50
            || dnaeCloakerCount() != 24
            || dnaePoolDiseasePct() != 50
        )
            ++bad;
        printf("R536 DSG Deepearth areas 6-7 audit: bad %d\n", bad);
        if (bad) return 1;
    }
