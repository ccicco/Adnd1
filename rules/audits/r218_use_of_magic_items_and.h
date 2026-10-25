    // ---- R218: the use of magic items and energy draining pins audit ----
    // DMG pp.119-122: the potion, oil,
    // command word and scrying conventions,
    // and the energy drain level-loss
    // mechanics.
    {
        int bad = 0;
        // drinking potions and applying oils
        if (rules::potionOpenConsumeSegments() != 1 ||
            rules::potionDelayMin() != 2 ||
            rules::potionDelayMax() != 5) ++bad;
        if (rules::oilDecantSegments() != 1 ||
            rules::oilSpreadMin() != 2 ||
            rules::oilSpreadMax() != 5) ++bad;
        // command words
        if (rules::rodStaffWandNeedsCommandWord() != 1 ||
            rules::commandWordInfoSpellCount() != 3) ++bad;
        // crystal balls and scrying
        if (rules::scryingDetectable() != 1 ||
            rules::scryingDetectionUsesInvisibilityTable() != 1 ||
            rules::scryingDarknessStopsForSpellDuration() != 1 ||
            rules::scryingDispelStopsHours() != 24) ++bad;
        // the energy drain level-loss mechanics
        if (rules::drainLosesLevelHitPointsAndAbilities() != 1 ||
            rules::drainXpToMidpointOfNextLower() != 1) ++bad;
        if (rules::drainBelowFirstIsZeroLevel() != 1 ||
            rules::zeroLevelNeverGainsAgain() != 1) ++bad;
        if (rules::isDeadIfZeroLevelDrained(0) != 1 ||
            rules::isDeadIfZeroLevelDrained(-2) != 1 ||
            rules::isDeadIfZeroLevelDrained(1) != 0 ||
            rules::isDeadIfZeroLevelDrained(5) != 0) ++bad;
        // the multiclass drain rules
        if (rules::multiclassLosesHighestLevel() != 1 ||
            rules::equalLevelsLoseGreatestXpClass() != 1 ||
            rules::twoLevelDrainSplitsAcrossClasses() != 1) ++bad;
        // the drained-all undead fate
        if (rules::drainedAllMayBecomeUndead() != 1 ||
            rules::lesserUndeadHalfHitDice() != 1 ||
            rules::lesserUndeadControlledBySlayer() != 1 ||
            rules::fullHdRegainUponSlayerDestruction() != 1) ++bad;
        if (rules::lesserVampireLevel(8) != 4 ||
            rules::lesserVampireLevel(0) != 0 ||
            rules::lesserVampireLevel(-3) != 0 ||
            rules::lesserVampireLevel(3) != 1) ++bad;
        printf("R218 use of magic items and energy draining pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
