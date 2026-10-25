    // ---- R403: the mount layer
    // seam audit ----
    // The deferred seam lands: the
    // layer contract (no mount
    // actor site; the pins precede
    // the site; the seam gates the
    // mounted-combat charge) and
    // the live cross-checks of the
    // six feeders - R123 the
    // mounted movement, R170 the
    // followers mounts, R189 the
    // charge damage, R321 the
    // aerial environment, R328 the
    // cavalier mounted reads, R356
    // the mount spell. The flying
    // steed ladder cross-declares
    // against the cavalier
    // horsemanship tail; census
    // 329 -> 330.
    {
        using namespace rules;
        int bad = 0;
        // ---- the layer contract ----
        if (!mmlMountActorSiteExists()) ++bad;
        if (!mmlPinsPrecedeSite()) ++bad;
        if (!mmlGatesMountedCombatCharge()) ++bad;
        if (mmlMountedCombatChargeOpen()) ++bad;
        if (mmlAerialPrecedentRound() != 321) ++bad;
        // ---- the feeder registry ----
        if (mmlFeederSeamCount() != 6) ++bad;
        if (mmlFeederRound(0) != 123
                || mmlFeederRound(1) != 170
                || mmlFeederRound(2) != 189)
            ++bad;
        if (mmlFeederRound(3) != 321
                || mmlFeederRound(4) != 328
                || mmlFeederRound(5) != 356)
            ++bad;
        // ---- the R189 charge seam ----
        if (lanceChargingDouble(23)) ++bad;
        if (!lanceChargingDouble(24)
                || !lanceChargingDouble(25)
                || !lanceChargingDouble(26))
            ++bad;
        if (lanceChargingDouble(27)) ++bad;
        if (!spearSetChargingDouble()) ++bad;
        // ---- the R328 cavalier seam ----
        if (cavalierHumanMountedLevelBonus()
                != 1) ++bad;
        if (cavalierSaddlePercent(1) != 85)
            ++bad;
        if (cavalierSaddlePercent(8) != 92)
            ++bad;
        if (cavalierSteedHpBonusPerDie() != 2)
            ++bad;
        // the flying steed ladder
        // agreement (the mml
        // cross-declaration vs the
        // cavalier horsemanship tail)
        for (int i = 0;
             i < mmlFlyingSteedCount();
             ++i)
            if (mmlFlyingSteedGrantLevel(i)
                    != cavalierHorsemanshipLevel(
                        i + 3))
                ++bad;
        if (mmlFlyingSteedGrantLevel(0) != 7)
            ++bad;
        if (mmlFlyingSteedGrantLevel(2) != 11)
            ++bad;
        if (!mmlFlyingSteedsRideAerialEnv())
            ++bad;
        // ---- the R321 aerial seam ----
        if (aerialClimbRateDivisor() != 2) ++bad;
        if (aerialDiveRateMultiple() != 2) ++bad;
        // ---- the R123 movement seam ----
        if (dm::mountedMilesPerDay(
                dm::MOUNT_LIGHT, dm::TC_NORMAL)
                != 60) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_HEAVY,
                dm::TC_VERY_RUGGED) != 5) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_WAGON,
                dm::TC_VERY_RUGGED) != 0) ++bad;
        // ---- the R170 followers seam ----
        if (folPaladinWarhorseMinLevel() != 4)
            ++bad;
        if (folPaladinWarhorseServiceYears() != 10)
            ++bad;
        // ---- the R356 spell seam ----
        if (uam1MountLevel() != 1) ++bad;
        if (uam1MountCastingTimeRounds() != 1)
            ++bad;
        if (!uam1MountServesThenReturns()) ++bad;
        if (uam1MountMuleLightHorseMaxLevel()
                != 3) ++bad;
        printf("R403 mount layer seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
