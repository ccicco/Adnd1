    // ---- R573 MotP energy planes audit ----
    // the Energy Planes, printed p. 54, Positive and Negative in one round:
    // the Plane-of-Life/Plane-of-Death doctrine, the 2d6-per-round hit-point
    // gain exploding at twice the original total (extra points fading in 1d20
    // true turns), the 2d6-plus-one-level drain, the protection-spell paradox
    // (the only protections cannot be cast in the planes), the
    // no-breathing-energy rule, the 10-yard vision, the 10%-per-turn weakened
    // Border Ethereal, the no-random-encounters doctrine, the magic max/min
    // rule with created matter destroyed in one round, and the features (the
    // xeg-ya and xeg-yi with their 2d6-8 guide roll, the trilloch, the undead
    // Negative link).
    {
        using namespace rules;
        int bad = 0;
    if (ddbPositiveGainDieSides() != 6
            || ddbNegativeDrainDieSides() != 6
            || ddbEnergyVisionYards() != 10
            || ddbBorderCollapsePct() != 10
            || ddbXegGuideRoll() != 8
            || !ddbEnergyHostile()
            || !ddbProtectionParadox()
            || !ddbNoBreathingEnergy()
            || !ddbNoRandomEncounters()
            || !ddbMagicMaxMinRule()
            || !ddbUndeadNegativeLink()
        )
            ++bad;
        // the PositiveGainDieSides pin
    if (ddbPositiveGainDieSides() != 6
        )
            ++bad;
        // the NegativeDrainDieSides pin
    if (ddbNegativeDrainDieSides() != 6
        )
            ++bad;
        // the EnergyVisionYards pin
    if (ddbEnergyVisionYards() != 10
        )
            ++bad;
        // the BorderCollapsePct pin
    if (ddbBorderCollapsePct() != 10
        )
            ++bad;
        // the XegGuideRoll pin
    if (ddbXegGuideRoll() != 8
        )
            ++bad;
        // the EnergyHostile pin
    if (ddbEnergyHostile() != 1
        )
            ++bad;
        // the ProtectionParadox pin
    if (ddbProtectionParadox() != 1
        )
            ++bad;
        // the NoBreathingEnergy pin
    if (ddbNoBreathingEnergy() != 1
        )
            ++bad;
        // the NoRandomEncounters pin
    if (ddbNoRandomEncounters() != 1
        )
            ++bad;
        // the MagicMaxMinRule pin
    if (ddbMagicMaxMinRule() != 1
        )
            ++bad;
        // the UndeadNegativeLink pin
    if (ddbUndeadNegativeLink() != 1
        )
            ++bad;
        printf("R573 MotP energy planes audit: bad %d\n", bad);
        if (bad) return 1;
    }
