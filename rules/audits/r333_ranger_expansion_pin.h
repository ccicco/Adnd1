    // ---- R333: the ranger expansion pin audit ----
    // The UA ranger expansion (pp. 21-22) - the pin-era
    // pattern: the tracking base and terrain ladders, the
    // indoor reads, the identification ladder, the
    // giant-class roster expansion 11 -> 22 (the
    // per-creature and precipitation values, the surface
    // cells and the rate cells are OCR holes - documented
    // in the header). The spell-progression component and
    // the R184/R327/R331/R332 seams cross-checked.
    {
        using namespace rules;
        int bad = 0;
        // U1: the outdoor tracking base
        {
            if (uaRangerTrackBasePerLevel() != 10)
                ++bad;
            if (uaRangerTrackBaseBonus() != 10)
                ++bad;
            if (uaRangerTrackBaseCap() != 110)
                ++bad;
            if (uaRangerTrackAdjustedCap()
                != 100) ++bad;
            if (uaRangerTrackBaseAt(1) != 20)
                ++bad;
            if (uaRangerTrackBaseAt(6) != 70)
                ++bad;
            if (uaRangerTrackBaseAt(10) != 110)
                ++bad;
            if (uaRangerTrackBaseAt(20) != 110)
                ++bad;
            if (uaRangerTrackBaseAt(0) != 0)
                ++bad;
        }
        // U2: the terrain ladder and the hide rule
        {
            static const int k[4] = {
                20, 10, 0, -50
            };
            if (uaRangerTrackTerrainCategoryCount()
                != 4) ++bad;
            for (int c = 0; c < 4; ++c)
                if (uaRangerTrackTerrainModifier(c)
                    != k[c]) ++bad;
            if (!uaRangerTrackHideDropsCategory())
                ++bad;
            if (!uaRangerTrackHideAtRockBottomImpossible())
                ++bad;
        }
        // U3: the elapsed-time modifier
        {
            if (uaRangerTrackPer12Hours() != 5)
                ++bad;
        }
        // U4: the indoor reads
        {
            if (!uaRangerTrackIndoorBaseSame())
                ++bad;
            if (!uaRangerTrackIndoorObservationRequired())
                ++bad;
            if (uaRangerTrackFollowWindowLow()
                != 10) ++bad;
            if (uaRangerTrackFollowWindowHigh()
                != 30) ++bad;
        }
        // U5: the light and movement reads
        {
            if (!uaRangerTrackGoodLightAssumed())
                ++bad;
            if (!uaRangerTrackTotalDarknessImpossible())
                ++bad;
            if (uaRangerTrackMoveRowCount() != 6)
                ++bad;
        }
        // U6: the quality definitions
        {
            if (uaRangerTrackObviousMin() != 71)
                ++bad;
            if (uaRangerTrackOccasionalLow()
                != 31) ++bad;
            if (uaRangerTrackOccasionalHigh()
                != 70) ++bad;
            if (uaRangerTrackFaintMax() != 30)
                ++bad;
        }
        // U7: the identification ladder
        {
            if (!uaRangerTrackIdentifySecondRoll())
                ++bad;
            if (!uaRangerTrackIdentifyCumulative())
                ++bad;
            if (uaRangerTrackIdentifyRowCount()
                != 10) ++bad;
            if (strcmp(uaRangerTrackIdentifyAbility(
                1), "Common woodland creatures'"
                " tracks and direction of travel")
                != 0) ++bad;
            if (strcmp(uaRangerTrackIdentifyAbility(
                3), "Common woodland creatures'"
                " time of passage (outdoors"
                " only)") != 0) ++bad;
            if (strcmp(uaRangerTrackIdentifyAbility(
                4), "As 3rd level with respect"
                " to uncommon woodland"
                " creatures") != 0) ++bad;
            if (strcmp(uaRangerTrackIdentifyAbility(
                7), "As 3rd level with respect"
                " to all sorts of creatures"
                " (woodland and otherwise)"
                " within a 100-mile radius")
                != 0) ++bad;
            if (strcmp(uaRangerTrackIdentifyAbility(
                9), "As 8th level, plus the"
                " ability to determine the"
                " size and numbers of mounted"
                " creatures") != 0) ++bad;
            if (strcmp(uaRangerTrackIdentifyAbility(
                10), "As 9th level with respect"
                " to all creatures ever"
                " observed, prior to attaining"
                " 10th level or subsequently")
                != 0) ++bad;
        }
        // U8: the giant class - the damage
        // bonus, the roster, the superset
        {
            if (uaRangerGiantDamagePerLevel()
                != 1) ++bad;
            if (uaRangerGiantRosterCount() != 22)
                ++bad;
            if (uaRangerGiantRosterPhbCount()
                != 11) ++bad;
            if (strcmp(uaRangerGiantRosterName(7),
                "gnoll") != 0) ++bad;
            if (strcmp(uaRangerGiantRosterName(1),
                "cyclopskin") != 0) ++bad;
            if (strcmp(uaRangerGiantRosterName(21),
                "xvart") != 0) ++bad;
            // every R184 PHB name rides the
            // UA roster (the printed superset
            // claim)
            for (int i = 0; i < 11; ++i) {
                int found = 0;
                for (int j = 0; j < 22; ++j)
                    if (strcmp(
                        rangerGiantClassName(i),
                        uaRangerGiantRosterName(j))
                        == 0) found = 1;
                if (!found) ++bad;
            }
        }
        // U9: the seams - the spell bands
        // (R327), the R184 bonus, the R331
        // spec gate, the R332 tracking read
        {
            if (rangerDruidicFromLevel() != 8)
                ++bad;
            if (rangerDruidicMaxSpellLevel()
                != 3) ++bad;
            if (rangerMuFromLevel() != 9) ++bad;
            if (rangerMuMaxSpellLevel() != 2)
                ++bad;
            if (rangerGiantClassBonus(7) != 7)
                ++bad;
            if (!weaponSpecClassAllowed(
                UACLASS_RANGER)) ++bad;
            if (!barbarianTracksAsRanger())
                ++bad;
        }
        printf("R333 ranger expansion pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
