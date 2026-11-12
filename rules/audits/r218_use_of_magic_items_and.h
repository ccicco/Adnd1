    // ---- R218: the use of magic items and energy draining pins audit ----
    // DMG pp.119-122: the potion, oil,
    // command word and scrying conventions,
    // and the energy drain level-loss
    // mechanics.
    {
        Energydrain energydrain;
        int bad = 0;
        // drinking potions and applying oils
        if (energydrain.potionOpenConsumeSegments() != 1 ||
            energydrain.potionDelayMin() != 2 ||
            energydrain.potionDelayMax() != 5) ++bad;
        if (energydrain.oilDecantSegments() != 1 ||
            energydrain.oilSpreadMin() != 2 ||
            energydrain.oilSpreadMax() != 5) ++bad;
        // command words
        if (energydrain.rodStaffWandNeedsCommandWord() != 1 ||
            energydrain.commandWordInfoSpellCount() != 3) ++bad;
        // crystal balls and scrying
        if (energydrain.scryingDetectable() != 1 ||
            energydrain.scryingDetectionUsesInvisibilityTable() != 1 ||
            energydrain.scryingDarknessStopsForSpellDuration() != 1 ||
            energydrain.scryingDispelStopsHours() != 24) ++bad;
        // the energy drain level-loss mechanics
        if (energydrain.drainLosesLevelHitPointsAndAbilities() != 1 ||
            energydrain.drainXpToMidpointOfNextLower() != 1) ++bad;
        if (energydrain.drainBelowFirstIsZeroLevel() != 1 ||
            energydrain.zeroLevelNeverGainsAgain() != 1) ++bad;
        if (energydrain.isDeadIfZeroLevelDrained(0) != 1 ||
            energydrain.isDeadIfZeroLevelDrained(-2) != 1 ||
            energydrain.isDeadIfZeroLevelDrained(1) != 0 ||
            energydrain.isDeadIfZeroLevelDrained(5) != 0) ++bad;
        // the multiclass drain rules
        if (energydrain.multiclassLosesHighestLevel() != 1 ||
            energydrain.equalLevelsLoseGreatestXpClass() != 1 ||
            energydrain.twoLevelDrainSplitsAcrossClasses() != 1) ++bad;
        // the drained-all undead fate
        if (energydrain.drainedAllMayBecomeUndead() != 1 ||
            energydrain.lesserUndeadHalfHitDice() != 1 ||
            energydrain.lesserUndeadControlledBySlayer() != 1 ||
            energydrain.fullHdRegainUponSlayerDestruction() != 1) ++bad;
        if (energydrain.lesserVampireLevel(8) != 4 ||
            energydrain.lesserVampireLevel(0) != 0 ||
            energydrain.lesserVampireLevel(-3) != 0 ||
            energydrain.lesserVampireLevel(3) != 1) ++bad;
        printf("R218 use of magic items and energy draining pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
