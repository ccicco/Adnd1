    // ---- R511 DSG cave-in causes audit ----
    // The DSG cave-in causes pins the opener (cave-ins unique to the
    // underground environment, the chance considered when excavating, using
    // explosive magic or placing stress on the overhanging rock, the bridge
    // and floor collapses endangering characters in other ways, the
    // trigger-as-attack ploy that must be made cautiously for its
    // chain-reaction risk), the natural causes (only strong structures
    // susceptible, to floods, earthquakes and volcanic eruptions; the spell
    // that duplicates a disaster duplicates its effect, the raise water flood
    // example; the major-disaster DM judgment that could annihilate a realm;
    // the ripe areas noted when the maps are prepared), the accidental causes
    // (only the frailest locations, triggered by the weight of a creature
    // walking or by sounds, the DM-assigned percentage by weakness, the 5%
    // ledge example modified when laden or accompanied by mules, the doubled
    // chance when running, the melee doubling with all participating weights
    // figured carefully for nonhumans, the reduced chance when the weak area
    // is not directly beneath with sound the only other avenue, the sound
    // chance by loudness and sharpness with the no-chance conversation and
    // the 1% sword-clash examples), the excavation causes (digging away a
    // significant ceiling support, mining the most common cause, the shoring
    // precaution with the mining-rules seam, the escape-tunnel and
    // rubble-clearing risk of about double the accidental chance, the 10% per
    // turn), the sabotage causes (the opportune collapse, the collapses on
    // the saboteurs themselves, the accessible targets - the columns, bridge
    // supports and narrow rock layers against the soaring ceiling - the
    // miner-proficiency requirement, the sixths splits without and with the
    // proficiency, the considerable time and noise with the page-50
    // excavation-rules seam), and the random occurrences (the chance growing
    // with extended underground time, the 1% per day base, the 10% per 10
    // days long-expedition option, the cave-in near the PCs but not on top of
    // them or within earshot, the Table 17 cross-reference, the
    // movement-relative directions, the higher roll the farther away, the
    // possibly-undiscovered cave-in and the decayed-stone or rotten-timber
    // double-or-triple increase).
    {
        using namespace rules;
        int bad = 0;
    if (dnwSabotageNoMinerSuccessSixths() != 2
            || dnwSabotageNoMinerTooStrongSixths() != 2
            || dnwSabotageNoMinerSelfCollapseSixths() != 2
            || dnwSabotageMinerSuccessSixths() != 4
            || dnwSabotageMinerUnderdamageSixths() != 1
            || dnwSabotageMinerSelfCollapseSixths() != 1
            || dnwAccidentalLedgeExamplePct() != 5
            || dnwSwordClashCollapsePctPerRound() != 1
            || dnwExcavationCollapsePctPerTurn() != 10
            || dnwExcavationChanceMult() != 2
            || dnwRandomCaveInPctPerDay() != 1
            || dnwRandomCaveInLongExpeditionPct() != 10
            || dnwRandomCaveInLongExpeditionDays() != 10
            || dnwDecayedChanceMultMax() != 3
            || dnwRunChanceMult() != 2
            || dnwMeleeChanceMult() != 2
            || dnwT17RowCount() != 8
            || !dnwCaveInUniqueToUnderground()
            || !dnwConsideredWhenStressingRock()
            || !dnwBridgeFloorAlsoEndanger()
            || !dnwTriggerAsAttackChainRisk()
            || !dnwStrongStructureOnlyDisasters()
            || !dnwSpellDuplicatesDisaster()
            || !dnwMajorDisasterDmJudgment()
            || !dnwRipeAreasNotedOnMaps()
            || !dnwAccidentalOnlyFrailest()
            || !dnwAccidentalWeightOrSound()
            || !dnwDmAssignsCollapsePct()
            || !dnwLadenOrBeastsModifyPct()
            || !dnwRunDoublesChance()
            || !dnwMeleeDoublesChance()
            || !dnwOffPositionReducedChance()
            || !dnwSoundChanceByLoudness()
            || !dnwExcavationRisksSupport()
            || !dnwMiningMostCommonCause()
            || !dnwUnshoredEscapeTunnelRisk()
            || !dnwSabotageNeedsMinerProficiency()
            || !dnwSabotageMayCrushSaboteur()
            || !dnwSabotageTargetsAccessible()
            || !dnwSabotageTimeAndNoise()
            || !dnwRandomChanceGrowsWithTime()
            || !dnwRandomMeansNearNotOnTop()
            || !dnwT17RelativeToMovement()
            || !dnwHigherRollFartherAway()
            || !dnwCaveInMayGoUndiscovered()
            || !dnwDecayedStoneChanceIncrease()
            || !dnwExcavationChanceAboutDouble()
        )
            ++bad;
        // the Table 17 cave-in location grid
        int C17[8][3] = {
            {0,1,1},
            {1,2,3},
            {2,4,5},
            {3,6,10},
            {4,11,15},
            {5,16,55},
            {6,56,95},
            {7,96,100},
            };
        for (int b = 0;
             b < dnwT17RowCount();
             ++b) {
            int vals[3];
            vals[0] = dnwT17Loc(b);
            vals[1] = dnwT17Lo(b);
            vals[2] = dnwT17Hi(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != C17[b][c])
                    ++bad;
            }
        }
        // the sabotage splits in sixths: without miner proficiency
        // 1/3-1/3-1/3 (2+2+2 of 6), with miner proficiency 2/3-1/6-1/6 (4+1+1
        // of 6).
    if (dnwSabotageNoMinerSuccessSixths() != 2
            || dnwSabotageNoMinerTooStrongSixths() != 2
            || dnwSabotageNoMinerSelfCollapseSixths() != 2
            || dnwSabotageMinerSuccessSixths() != 4
            || dnwSabotageMinerUnderdamageSixths() != 1
            || dnwSabotageMinerSelfCollapseSixths() != 1
        )
            ++bad;
        // the printed percentages: the 5% ledge example, the 1% per round of
        // clashing swords, and the 10% per turn of unshored excavation at
        // about double the accidental chance (the djvu garbles 596/196/1096
        // settled by the Acrobat layer).
    if (dnwAccidentalLedgeExamplePct() != 5
            || dnwSwordClashCollapsePctPerRound() != 1
            || dnwExcavationCollapsePctPerTurn() != 10
            || dnwExcavationChanceMult() != 2
        )
            ++bad;
        // the random occurrences: the base 1% per day, the 10% every 10 days
        // long-expedition option, and the decayed-stone increase up to a
        // triple.
    if (dnwRandomCaveInPctPerDay() != 1
            || dnwRandomCaveInLongExpeditionPct() != 10
            || dnwRandomCaveInLongExpeditionDays() != 10
            || dnwDecayedChanceMultMax() != 3
        )
            ++bad;
        // the collapse-chance modifiers: doubled when running, doubled in
        // melee on a fragile surface, and modified when heavily laden or
        // accompanied by mules or other creatures.
    if (dnwRunChanceMult() != 2
            || dnwMeleeChanceMult() != 2
            || dnwLadenOrBeastsModifyPct() != 1
        )
            ++bad;
        // the Table 17 first and last bands: 01 on top of the PCs, and 96-00
        // (pinned 96-100) at the entrance the PCs used to get underground.
    if (dnwT17Loc(0) != 0
            || dnwT17Lo(0) != 1
            || dnwT17Hi(0) != 1
            || dnwT17Loc(7) != 7
            || dnwT17Lo(7) != 96
            || dnwT17Hi(7) != 100
        )
            ++bad;
        // the Table 17 immediate and within-hearing bands: 02-03 immediately
        // in front, 04-05 immediately behind, 06-10 in front within hearing,
        // 11-15 behind within hearing.
    if (dnwT17Lo(1) != 2
            || dnwT17Hi(1) != 3
            || dnwT17Lo(2) != 4
            || dnwT17Hi(2) != 5
            || dnwT17Lo(3) != 6
            || dnwT17Hi(3) != 10
            || dnwT17Lo(4) != 11
            || dnwT17Hi(4) != 15
        )
            ++bad;
        // the Table 17 out-of-hearing bands: 16-55 well behind the PCs, 56-95
        // well in front of the PCs.
    if (dnwT17Lo(5) != 16
            || dnwT17Hi(5) != 55
            || dnwT17Lo(6) != 56
            || dnwT17Hi(6) != 95
        )
            ++bad;
        // the opener: cave-ins unique to the underground environment,
        // considered when excavating or using explosive magic or stressing
        // the overhanging rock, the bridge and floor collapses, and the
        // trigger-as-attack ploy with its chain-reaction risk.
    if (dnwCaveInUniqueToUnderground() != 1
            || dnwConsideredWhenStressingRock() != 1
            || dnwBridgeFloorAlsoEndanger() != 1
            || dnwTriggerAsAttackChainRisk() != 1
        )
            ++bad;
        // the natural causes: only strong structures susceptible to floods,
        // earthquakes and volcanic eruptions, the spell-duplicates-disaster
        // rule, the major-disaster DM judgment, and the ripe areas noted on
        // the maps.
    if (dnwStrongStructureOnlyDisasters() != 1
            || dnwSpellDuplicatesDisaster() != 1
            || dnwMajorDisasterDmJudgment() != 1
            || dnwRipeAreasNotedOnMaps() != 1
        )
            ++bad;
        // the accidental causes: only the frailest locations, triggered by
        // weight or sound, with the DM-assigned percentage, the reduced
        // off-position chance and the sound scale by loudness and sharpness.
    if (dnwAccidentalOnlyFrailest() != 1
            || dnwAccidentalWeightOrSound() != 1
            || dnwDmAssignsCollapsePct() != 1
            || dnwOffPositionReducedChance() != 1
            || dnwSoundChanceByLoudness() != 1
        )
            ++bad;
        // the excavation causes: digging away a significant ceiling support,
        // mining the most common cause with the shoring seam, and the
        // unshored escape-tunnel risk at about double the accidental chance.
    if (dnwExcavationRisksSupport() != 1
            || dnwMiningMostCommonCause() != 1
            || dnwUnshoredEscapeTunnelRisk() != 1
            || dnwExcavationChanceAboutDouble() != 1
        )
            ++bad;
        // the sabotage causes: the miner-proficiency requirement, the
        // collapses on the saboteurs themselves, the accessible targets, and
        // the considerable time and noise.
    if (dnwSabotageNeedsMinerProficiency() != 1
            || dnwSabotageMayCrushSaboteur() != 1
            || dnwSabotageTargetsAccessible() != 1
            || dnwSabotageTimeAndNoise() != 1
        )
            ++bad;
        // the random-occurrence reading: the chance grows with underground
        // time, the cave-in lands near but not on the PCs, the directions are
        // relative to the party's movement, the higher roll is the farther
        // away, the cave-in may go undiscovered, and decayed stone can double
        // or triple the chance.
    if (dnwRandomChanceGrowsWithTime() != 1
            || dnwRandomMeansNearNotOnTop() != 1
            || dnwT17RelativeToMovement() != 1
            || dnwHigherRollFartherAway() != 1
            || dnwCaveInMayGoUndiscovered() != 1
            || dnwDecayedStoneChanceIncrease() != 1
        )
            ++bad;
        // the Table 17 carries eight location bands.
    if (dnwT17RowCount() != 8
        )
            ++bad;
        // the Table 17 grid cell-for-cell, rows 0-4: on top, immediately in
        // front, immediately behind, and the two within-hearing bands.
    if (dnwT17Loc(0) != 0
            || dnwT17Lo(0) != 1
            || dnwT17Hi(0) != 1
            || dnwT17Loc(1) != 1
            || dnwT17Lo(1) != 2
            || dnwT17Hi(1) != 3
            || dnwT17Loc(2) != 2
            || dnwT17Lo(2) != 4
            || dnwT17Hi(2) != 5
            || dnwT17Loc(3) != 3
            || dnwT17Lo(3) != 6
            || dnwT17Hi(3) != 10
            || dnwT17Loc(4) != 4
            || dnwT17Lo(4) != 11
            || dnwT17Hi(4) != 15
        )
            ++bad;
        // the Table 17 grid cell-for-cell, rows 5-7: the two out-of-hearing
        // bands and the entrance band.
    if (dnwT17Loc(5) != 5
            || dnwT17Lo(5) != 16
            || dnwT17Hi(5) != 55
            || dnwT17Loc(6) != 6
            || dnwT17Lo(6) != 56
            || dnwT17Hi(6) != 95
            || dnwT17Loc(7) != 7
            || dnwT17Lo(7) != 96
            || dnwT17Hi(7) != 100
        )
            ++bad;
        printf("R511 DSG cave-in causes audit: bad %d\n", bad);
        if (bad) return 1;
    }
