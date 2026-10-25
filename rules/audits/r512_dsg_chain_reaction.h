    // ---- R512 DSG chain reaction audit ----
    // The DSG chain reaction pins the opener (gravity constantly working
    // destruction on underworld ceilings, a small cave-in weakening
    // supporting structures for an immediate or near-future massive chain
    // reaction, the nearby ceilings and walls checked, the per-section d100
    // vs Table 18 determining the extent), the chain reading (equal-or-less
    // collapses the adjacent area at about the same area as the original, the
    // miss within 10% of the chance significantly weakening the area that
    // might collapse at any moment, the chain collapses forcing checks in all
    // their adjacent areas, the tertiary chance half rounded up, each
    // subsequent roll at 1/2 the forcing roll chance), the decayed exception
    // (the DM may keep the original chance for all subsequent rolls in
    // heavily eroded or ancient-ruin areas), the worked example (the
    // 9th-level druid, the 100x80x10 ft transmuted ceiling, the 31-vs-48
    // collapse above, the 42-vs-24 hold of the second layer, the side rolls
    // 12/65/97/33 with exactly one side continuing, the secondary checks at
    // 1/2 and the tertiary at 1/4), the base area (the falling distance and
    // rough landing on top, the bridge along its entire unsupported length,
    // the tunnel ceiling never wider than the tunnel, the random 20x20
    // roughly square base area, the chain checks per adjacent square and
    // above, radically increasing the total size), the falling layer (the
    // three-foot assumption unless otherwise, the two-foot ceiling-and-floor
    // example, the stone above a collapsed layer checked for a chain
    // reaction), the falling damage (4d8 per 10 feet or less of thickness,
    // the save vs petrification for half, the 30-foot 12d8 example reduced to
    // 6d8), and the mud and water damage (mud, silt and sludgy substances at
    // half rock damage with the save halving again, water at half with a save
    // for 1/4, the damage for the first 10-foot thickness only, no additional
    // damage from the weight of the pouring column, and the drowning risk).
    {
        using namespace rules;
        int bad = 0;
    if (dnxWeakenedWithinPct() != 10
            || dnxTertiaryChanceDiv() != 2
            || dnxSubsequentRollDiv() != 2
            || dnxExampleDruidLevel() != 9
            || dnxExampleSpellLengthFt() != 100
            || dnxExampleSpellWidthFt() != 80
            || dnxExampleSpellThickFt() != 10
            || dnxExampleAboveRoll() != 31
            || dnxExampleAboveSecondChance() != 24
            || dnxExampleAboveSecondRoll() != 42
            || dnxExampleSideRoll1() != 12
            || dnxExampleSideRoll2() != 65
            || dnxExampleSideRoll3() != 97
            || dnxExampleSideRoll4() != 33
            || dnxExampleSecondaryDiv() != 2
            || dnxExampleTertiaryDiv() != 4
            || dnxBaseAreaFtX() != 20
            || dnxBaseAreaFtY() != 20
            || dnxLayerThickFtDefault() != 3
            || dnxFloorLayerExampleFt() != 2
            || dnxFallingDamageDice() != 4
            || dnxFallingDamageSides() != 8
            || dnxDamagePerThicknessFt() != 10
            || dnxExampleThicknessFt() != 30
            || dnxExampleDamageDice() != 12
            || dnxExampleSaveDice() != 6
            || dnxMudDamageDiv() != 2
            || dnxWaterDamageDiv() != 2
            || dnxWaterSaveDiv() != 4
            || dnxWaterChargedThicknessFt() != 10
            || dnxT18RowCount() != 4
            || !dnxSmallCaveInWeakensSupports()
            || !dnxAdjacentAreasMustBeChecked()
            || !dnxDmRollsD100PerSection()
            || !dnxEqualOrLessCollapses()
            || !dnxCollapseSameAreaAsOriginal()
            || !dnxWeakenedMayCollapseAnyMoment()
            || !dnxChainCollapseForcesMoreChecks()
            || !dnxTertiaryRoundedUp()
            || !dnxEachSubsequentRollHalved()
            || !dnxDecayedIgnoresDecline()
            || !dnxDecayedErodedOrAncient()
            || !dnxExampleAboveCollapses()
            || !dnxExampleSecondLayerHolds()
            || !dnxExampleOneSideContinues()
            || !dnxExampleSecondaryChecksRequired()
            || !dnxEffectDependsOnPositionAndRock()
            || !dnxOnTopUseFallingRules()
            || !dnxBaseAreaFromStructure()
            || !dnxBridgeFallsUnsupportedLength()
            || !dnxTunnelCeilingNeverWider()
            || !dnxBaseAreaRoughlySquare()
            || !dnxChainCheckedPerAdjacentSquare()
            || !dnxChainRadicallyIncreasesSize()
            || !dnxLayerThickUnlessOtherwise()
            || !dnxThinFloorLayerExample()
            || !dnxThreeFtLeavesStoneCheckChain()
            || !dnxSavePetrificationHalf()
            || !dnxMudHalfRockDamage()
            || !dnxMudSaveHalvesAgain()
            || !dnxWaterHalfRockDamage()
            || !dnxWaterNoWeightDamage()
            || !dnxWaterColumnDrowningRisk()
        )
            ++bad;
        // the Table 18 cave-in chain reaction grid
        int C18[4][3] = {
            {0,48,32},
            {1,32,12},
            {2,5,12},
            {3,80,4},
            };
        for (int b = 0;
             b < dnxT18RowCount();
             ++b) {
            int vals[3];
            vals[0] = dnxT18Loc(b);
            vals[1] = dnxT18Above(b);
            vals[2] = dnxT18Next(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != C18[b][c])
                    ++bad;
            }
        }
        // the Table 18 first and last rows: a ceiling chain 48% above and 32%
        // next, a support column 80% above and 4% next.
    if (dnxT18Loc(0) != 0
            || dnxT18Above(0) != 48
            || dnxT18Next(0) != 32
            || dnxT18Loc(3) != 3
            || dnxT18Above(3) != 80
            || dnxT18Next(3) != 4
        )
            ++bad;
        // the Table 18 middle rows: a wall 32% above and 12% next, a ledge or
        // bridge 5% above and 12% next.
    if (dnxT18Above(1) != 32
            || dnxT18Next(1) != 12
            || dnxT18Above(2) != 5
            || dnxT18Next(2) != 12
        )
            ++bad;
        // the chain reaction reading: equal-or-less collapses the adjacent
        // area at about the same size, and a miss within 10% of the chance
        // significantly weakens it.
    if (dnxWeakenedWithinPct() != 10
            || dnxEqualOrLessCollapses() != 1
            || dnxCollapseSameAreaAsOriginal() != 1
        )
            ++bad;
        // the cascade: chain collapses force checks in all adjacent areas,
        // the tertiary chance is half the original rounded up, and each
        // subsequent roll halves the forcing roll chance.
    if (dnxTertiaryChanceDiv() != 2
            || dnxSubsequentRollDiv() != 2
            || dnxTertiaryRoundedUp() != 1
            || dnxChainCollapseForcesMoreChecks() != 1
            || dnxEachSubsequentRollHalved() != 1
        )
            ++bad;
        // the decayed exception: the DM may keep the original chance for all
        // subsequent rolls in water-eroded or ancient ruin areas.
    if (dnxDecayedIgnoresDecline() != 1
            || dnxDecayedErodedOrAncient() != 1
        )
            ++bad;
        // the worked example opener: a 9th-level druid transmuting a
        // 100x80x10 ft rock ceiling to mud.
    if (dnxExampleDruidLevel() != 9
            || dnxExampleSpellLengthFt() != 100
            || dnxExampleSpellWidthFt() != 80
            || dnxExampleSpellThickFt() != 10
        )
            ++bad;
        // the example vertical chain: the 31 against 48 collapses the layer
        // above, and the 42 against the halved 24 holds the second layer.
    if (dnxExampleAboveRoll() != 31
            || dnxExampleAboveCollapses() != 1
            || dnxExampleAboveSecondChance() != 24
            || dnxExampleAboveSecondRoll() != 42
            || dnxExampleSecondLayerHolds() != 1
        )
            ++bad;
        // the example side checks: rolls 12, 65, 97 and 33 leave one side
        // collapsing, its secondary checks at 1/2 and any tertiary checks at
        // 1/4.
    if (dnxExampleSideRoll1() != 12
            || dnxExampleSideRoll2() != 65
            || dnxExampleSideRoll3() != 97
            || dnxExampleSideRoll4() != 33
            || dnxExampleOneSideContinues() != 1
            || dnxExampleSecondaryChecksRequired() != 1
            || dnxExampleSecondaryDiv() != 2
            || dnxExampleTertiaryDiv() != 4
        )
            ++bad;
        // the base area: falling distance and rough landing on top, the
        // bridge along its unsupported length, and the tunnel ceiling never
        // wider than the tunnel.
    if (dnxOnTopUseFallingRules() != 1
            || dnxBridgeFallsUnsupportedLength() != 1
            || dnxTunnelCeilingNeverWider() != 1
            || dnxBaseAreaFromStructure() != 1
        )
            ++bad;
        // the random base area: 20 by 20 feet and roughly square, with chain
        // reactions checked per adjacent square, radically increasing the
        // total size.
    if (dnxBaseAreaFtX() != 20
            || dnxBaseAreaFtY() != 20
            || dnxBaseAreaRoughlySquare() != 1
            || dnxChainCheckedPerAdjacentSquare() != 1
            || dnxChainRadicallyIncreasesSize() != 1
        )
            ++bad;
        // the falling layer: three feet thick unless otherwise, the two-foot
        // ceiling-and-floor example, and the stone above a collapsed layer
        // checked for a chain reaction.
    if (dnxLayerThickFtDefault() != 3
            || dnxLayerThickUnlessOtherwise() != 1
            || dnxFloorLayerExampleFt() != 2
            || dnxThinFloorLayerExample() != 1
            || dnxThreeFtLeavesStoneCheckChain() != 1
        )
            ++bad;
        // the falling damage: 4d8 per 10 feet or less of thickness, with a
        // saving throw vs. petrification for half.
    if (dnxFallingDamageDice() != 4
            || dnxFallingDamageSides() != 8
            || dnxDamagePerThicknessFt() != 10
            || dnxSavePetrificationHalf() != 1
        )
            ++bad;
        // the worked damage example: a 30-foot thickness inflicts 12d8,
        // reduced to 6d8 by the save (the djvu garble 648 settled by the
        // Acrobat layer).
    if (dnxExampleThicknessFt() != 30
            || dnxExampleDamageDice() != 12
            || dnxExampleSaveDice() != 6
        )
            ++bad;
        // the mud and water damage: mud and silt at half rock damage with a
        // save halving again, and water at half with a save for 1/4.
    if (dnxMudDamageDiv() != 2
            || dnxMudHalfRockDamage() != 1
            || dnxMudSaveHalvesAgain() != 1
            || dnxWaterDamageDiv() != 2
            || dnxWaterSaveDiv() != 4
            || dnxWaterHalfRockDamage() != 1
        )
            ++bad;
        // the water tail: damage for the first 10-foot thickness only, no
        // weight damage under a pouring column, and the drowning risk.
    if (dnxWaterChargedThicknessFt() != 10
            || dnxWaterNoWeightDamage() != 1
            || dnxWaterColumnDrowningRisk() != 1
        )
            ++bad;
        // the chain reaction opener: gravity working on the ceilings,
        // adjacent areas checked, the per-section d100, and the weakened area
        // ready to collapse at any moment.
    if (dnxSmallCaveInWeakensSupports() != 1
            || dnxAdjacentAreasMustBeChecked() != 1
            || dnxDmRollsD100PerSection() != 1
            || dnxWeakenedMayCollapseAnyMoment() != 1
        )
            ++bad;
        // the effects opener: the effect depends on where the characters are
        // and the amount of falling rock.
    if (dnxEffectDependsOnPositionAndRock() != 1
            || dnxOnTopUseFallingRules() != 1
        )
            ++bad;
        // the Table 18 carries four original-location rows.
    if (dnxT18RowCount() != 4
        )
            ++bad;
        // the Table 18 grid cell-for-cell, rows 0-1: the ceiling and wall
        // chain chances.
    if (dnxT18Loc(0) != 0
            || dnxT18Above(0) != 48
            || dnxT18Next(0) != 32
            || dnxT18Loc(1) != 1
            || dnxT18Above(1) != 32
            || dnxT18Next(1) != 12
        )
            ++bad;
        // the Table 18 grid cell-for-cell, rows 2-3: the ledge/bridge and
        // support column chain chances.
    if (dnxT18Loc(2) != 2
            || dnxT18Above(2) != 5
            || dnxT18Next(2) != 12
            || dnxT18Loc(3) != 3
            || dnxT18Above(3) != 80
            || dnxT18Next(3) != 4
        )
            ++bad;
        printf("R512 DSG chain reaction audit: bad %d\n", bad);
        if (bad) return 1;
    }
