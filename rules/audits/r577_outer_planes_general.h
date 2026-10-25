    // ---- R577 outer planes general audit ----
    // the Outer Planes in general, printed pp. 73-84, the general-doctrine
    // round opening the final arc: the Great Wheel (16 pieces plus the 17th
    // plane, the alignment arrangement, the Upper/Lower/Law/Chaos groupings,
    // the layer-count table with the Abyss' 666), the reaching (all travel
    // through the Astral - the conduits, the plane shift with its arrival
    // table, the gate rules, the color pools with new-body formation and the
    // harmless cord snap), the survival (the like-the-Primes-only-more-so
    // doctrine, the localized gravity, the per-realm directions, the two
    // compasses), the movement (the realm borders with their gravity shifts,
    // the Wisdom-check interlayer barriers at 70% one-way, the portal rules
    // at 1-in-6 and 50/50), the encounters (the unique-Powers 2-or-20 rule,
    // the human travelers, the native-body doctrine), the magic school by
    // school (the home-court abjurations, the cantrip pop, the Chaos-plane
    // alteration ladder at 20/40/60/80 with the d100 follow-up, the
    // divination alignment-overwhelm, the true-sight freezes, the vacant-body
    // rule at 1% per layer, the item-plus decay), the PC adjustments (the
    // cleric deity rule, the paladin lay-on-hands exception, the barbarian
    // comfort), and the features (the spell-crystals, the river Styx with its
    // forget save at 15th level, the 50% dragging, the Charon 1d100-turn
    // transit, and the wholesome Oceanus).
    {
        using namespace rules;
        int bad = 0;
    if (ddfOuterPlaneCount() != 17
            || ddfAbyssLayerEstimate() != 666
            || ddfPlaneShiftOnTargetPct() != 20
            || ddfPortalFindDenom() != 6
            || ddfPortalOneWayPct() != 50
            || ddfInterlayerOneWayPct() != 70
            || ddfChaosAlterMaxPct() != 80
            || ddfUniquePowerRollLow() != 2
            || ddfBodyHabitPctPerLayer() != 1
            || ddfTurnModMax() != 4
            || ddfStyxForgetCasterLevel() != 15
            || ddfStyxDraggedPct() != 50
            || ddfCharonTransitTurns() != 100
            || !ddfReachingDoctrine()
            || !ddfSurvivalDoctrine()
            || !ddfMagicDoctrine()
            || !ddfItemDecayRule()
            || !ddfHumanTravelerDoctrine()
            || !ddfNativeBodyRule()
            || !ddfPcAdjustments()
            || !ddfSpellCrystalRule()
            || !ddfOceanusRule()
            || !ddfStyxCourseRule()
        )
            ++bad;
        // the OuterPlaneCount pin
    if (ddfOuterPlaneCount() != 17
        )
            ++bad;
        // the AbyssLayerEstimate pin
    if (ddfAbyssLayerEstimate() != 666
        )
            ++bad;
        // the PlaneShiftOnTargetPct pin
    if (ddfPlaneShiftOnTargetPct() != 20
        )
            ++bad;
        // the PortalFindDenom pin
    if (ddfPortalFindDenom() != 6
        )
            ++bad;
        // the PortalOneWayPct pin
    if (ddfPortalOneWayPct() != 50
        )
            ++bad;
        // the InterlayerOneWayPct pin
    if (ddfInterlayerOneWayPct() != 70
        )
            ++bad;
        // the ChaosAlterMaxPct pin
    if (ddfChaosAlterMaxPct() != 80
        )
            ++bad;
        // the UniquePowerRollLow pin
    if (ddfUniquePowerRollLow() != 2
        )
            ++bad;
        // the BodyHabitPctPerLayer pin
    if (ddfBodyHabitPctPerLayer() != 1
        )
            ++bad;
        // the TurnModMax pin
    if (ddfTurnModMax() != 4
        )
            ++bad;
        // the StyxForgetCasterLevel pin
    if (ddfStyxForgetCasterLevel() != 15
        )
            ++bad;
        // the StyxDraggedPct pin
    if (ddfStyxDraggedPct() != 50
        )
            ++bad;
        // the CharonTransitTurns pin
    if (ddfCharonTransitTurns() != 100
        )
            ++bad;
        // the ReachingDoctrine pin
    if (ddfReachingDoctrine() != 1
        )
            ++bad;
        // the SurvivalDoctrine pin
    if (ddfSurvivalDoctrine() != 1
        )
            ++bad;
        // the MagicDoctrine pin
    if (ddfMagicDoctrine() != 1
        )
            ++bad;
        // the ItemDecayRule pin
    if (ddfItemDecayRule() != 1
        )
            ++bad;
        // the HumanTravelerDoctrine pin
    if (ddfHumanTravelerDoctrine() != 1
        )
            ++bad;
        // the NativeBodyRule pin
    if (ddfNativeBodyRule() != 1
        )
            ++bad;
        // the PcAdjustments pin
    if (ddfPcAdjustments() != 1
        )
            ++bad;
        // the SpellCrystalRule pin
    if (ddfSpellCrystalRule() != 1
        )
            ++bad;
        // the OceanusRule pin
    if (ddfOceanusRule() != 1
        )
            ++bad;
        // the StyxCourseRule pin
    if (ddfStyxCourseRule() != 1
        )
            ++bad;
        printf("R577 outer planes general audit: bad %d\n", bad);
        if (bad) return 1;
    }
