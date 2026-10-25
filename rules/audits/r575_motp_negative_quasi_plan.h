    // ---- R575 MotP negative quasi-planes audit ----
    // the Negative Quasi-Planes, printed pp. 57-59, the four in one round:
    // Vacuum, Ash, Dust and Salt - the increasing-absence doctrine (what is
    // missing in the Positive is present here, thinning toward the Negative),
    // the per-plane survival (the Vacuum hold-breath-only rule with the
    // airy-element uselessness, the 1-HD-per-round elemental loss and the
    // 1,000-yard doubled infravision; the Ash warmth depletion with the
    // fire-creature drain and the cold-protection halving at 30 yards; the
    // Dust crumbling with the gaseous-form protection and the 10d3 vision;
    // the Salt per-TURN elemental drain), the tenuous movement (falling
    // fastest, the borders discourage it), the 1-in-10-per-12-hours encounter
    // check AMENDED against the report's 1-in-20 (the 1-20/21-00
    // phenomenon/creature split, no elemental pockets), the black wall
    // intrusion at 3d6 per round for 2d10 turns, the 1-in-10 native
    // life-level drain per touch, the native rules (the Ash flee-or-explode
    // save vs. poison at 1d4 per hit die within 20 feet, the Dust 50% split
    // with the earth-spell immunity, the Salt water-shatter with the 30-foot
    // shard radius), the magic decay (the Vacuum same-round dissipation, the
    // 1d4-round Dust and Salt rules), the doubled guide prices, no
    // archoments, and the Foreword doctrines riding this round (the Fibber
    // McGee closet, what-has-been-written-is-true, the made-it-up admission).
    {
        using namespace rules;
        int bad = 0;
    if (dddQuasiPlaneCount() != 4
            || dddVacuumHdLossPerRound() != 1
            || dddVacuumVisionYards() != 1000
            || dddAshVisionYards() != 30
            || dddQuasiVisionDieSides() != 3
            || dddDepletionDamageDieSides() != 6
            || dddSaltElementalTurnLoss() != 1
            || dddBlackWallAdvanceDieSides() != 6
            || dddEncounterDenom() != 10
            || !dddNativeLevelDrain()
            || !dddAshNativeRule()
            || !dddDustNativeRule()
            || !dddSaltNativeRule()
            || !dddMagicDecayRule()
            || !dddGuidePriceDoubled()
            || !dddForewordDoctrine()
        )
            ++bad;
        // the QuasiPlaneCount pin
    if (dddQuasiPlaneCount() != 4
        )
            ++bad;
        // the VacuumHdLossPerRound pin
    if (dddVacuumHdLossPerRound() != 1
        )
            ++bad;
        // the VacuumVisionYards pin
    if (dddVacuumVisionYards() != 1000
        )
            ++bad;
        // the AshVisionYards pin
    if (dddAshVisionYards() != 30
        )
            ++bad;
        // the QuasiVisionDieSides pin
    if (dddQuasiVisionDieSides() != 3
        )
            ++bad;
        // the DepletionDamageDieSides pin
    if (dddDepletionDamageDieSides() != 6
        )
            ++bad;
        // the SaltElementalTurnLoss pin
    if (dddSaltElementalTurnLoss() != 1
        )
            ++bad;
        // the BlackWallAdvanceDieSides pin
    if (dddBlackWallAdvanceDieSides() != 6
        )
            ++bad;
        // the EncounterDenom pin
    if (dddEncounterDenom() != 10
        )
            ++bad;
        // the NativeLevelDrain pin
    if (dddNativeLevelDrain() != 1
        )
            ++bad;
        // the AshNativeRule pin
    if (dddAshNativeRule() != 1
        )
            ++bad;
        // the DustNativeRule pin
    if (dddDustNativeRule() != 1
        )
            ++bad;
        // the SaltNativeRule pin
    if (dddSaltNativeRule() != 1
        )
            ++bad;
        // the MagicDecayRule pin
    if (dddMagicDecayRule() != 1
        )
            ++bad;
        // the GuidePriceDoubled pin
    if (dddGuidePriceDoubled() != 1
        )
            ++bad;
        // the ForewordDoctrine pin
    if (dddForewordDoctrine() != 1
        )
            ++bad;
        printf("R575 MotP negative quasi-planes audit: bad %d\n", bad);
        if (bad) return 1;
    }
