    // ---- R206: the pursuit and evasion audit ----
    // DMG pp.67-69: the underground pursuit
    // likelihood ladder, the three end-condition
    // cases by relative speed, the food and
    // treasure distractions, the multiple-choice
    // and detection radii, and the outdoor
    // evasion table (base 80 with the speed,
    // terrain, size and light adjustments).
    {
        Pursuit pursuit;
        int bad = 0;
        // the motivated semi-intelligent band
        if (pursuit.pursueLikelihoodMotivatedSemi() != 80)
            ++bad;
        // the low-intelligence ladder: 20 / 40 /
        // 80, and 100 when the outnumbering
        // pursuers feel greatly superior
        if (pursuit.pursueLikelihoodLowInt(
                true, false, false) != 20 ||
            pursuit.pursueLikelihoodLowInt(
                false, true, false) != 40 ||
            pursuit.pursueLikelihoodLowInt(
                false, false, false) != 80 ||
            pursuit.pursueLikelihoodLowInt(
                false, false, true) != 100) ++bad;
        // the end-condition distances and caps by
        // relative speed: 100/50/5 rounds,
        // 150/80/1 turn, 200/none/no cap
        if (pursuit.endSightFeet(
                PURS_PURSUED_FASTER) != 100 ||
            pursuit.endSightFeet(
                PURS_EQUAL_SPEED) != 150 ||
            pursuit.endSightFeet(
                PURS_PURSUER_FASTER) != 0) ++bad;
        if (pursuit.endOutOfSightFeet(
                PURS_PURSUED_FASTER) != 50 ||
            pursuit.endOutOfSightFeet(
                PURS_EQUAL_SPEED) != 80 ||
            pursuit.endOutOfSightFeet(
                PURS_PURSUER_FASTER) != 200) ++bad;
        if (pursuit.endRoundCap(
                PURS_PURSUED_FASTER) != 5 ||
            pursuit.endRoundCap(
                PURS_EQUAL_SPEED) != 10 ||
            pursuit.endRoundCap(
                PURS_PURSUER_FASTER) != -1) ++bad;
        // the composition: in sight at 101 feet
        // ends the faster-pursued case; 100 does
        // not; out of sight lost at 201 ends the
        // pursuer-faster case; past the round cap
        // without a gain ends it
        if (!pursuit.ends(
                PURS_PURSUED_FASTER, true, 101,
                false, 0, 0, false)) ++bad;
        if (pursuit.ends(
                PURS_PURSUED_FASTER, true, 100,
                false, 0, 0, false)) ++bad;
        if (!pursuit.ends(
                PURS_PURSUER_FASTER, false, 0,
                true, 201, 0, false)) ++bad;
        if (pursuit.ends(
                PURS_PURSUER_FASTER, false, 0,
                true, 200, 0, false)) ++bad;
        if (!pursuit.ends(
                PURS_EQUAL_SPEED, false, 0,
                false, 0, 11, false)) ++bad;
        if (pursuit.ends(
                PURS_EQUAL_SPEED, false, 0,
                false, 0, 11, true)) ++bad;
        // the movement procedure: 3 phases per
        // round, contact at 10 feet
        if (pursuit.phasesPerRound() != 3 ||
            pursuit.confrontFeet() != 10) ++bad;
        // the food distraction: 100 percent for
        // non-intelligent; d10 base + 10 per point
        // below 5; the confirm roll at or under
        if (pursuit.foodDistractionPercent(0, 0) != 100 ||
            pursuit.foodDistractionPercent(5, 5) != 50 ||
            pursuit.foodDistractionPercent(5, 2) != 80 ||
            pursuit.foodDistractionPercent(9, 1) != 100 ||
            pursuit.foodDistractionPercent(3, 7) != 30)
            ++bad;
        // at 100 percent the distraction is automatic -
        // the print spares the second d10 - so the
        // function returns true: pinned as correct
        if (!pursuit.foodDistractionSucceeds(100, 1) ||
            !pursuit.foodDistractionSucceeds(80, 8) ||
            pursuit.foodDistractionSucceeds(80, 9) ||
            !pursuit.foodDistractionSucceeds(30, 3) ||
            pursuit.foodDistractionSucceeds(30, 4) ||
            pursuit.foodDistractionBreakRounds() != 1)
            ++bad;
        // the treasure distraction: +10 per 10
        // items for low intelligence, +10 per
        // 100 gp of value
        if (pursuit.treasureDistractionLowInt(
                20, 20) != 40 ||
            pursuit.treasureDistractionLowInt(
                20, 100) != 100 ||
            pursuit.treasureDistractionValueBonus(
                250) != 20 ||
            pursuit.treasureDistractionValueBonus(
                99) != 0) ++bad;
        // the multiple-choice and detection radii
        if (pursuit.wrongChoiceWays(3) != 2 ||
            pursuit.wrongChoiceWays(2) != 1)
            ++bad;
        if (pursuit.cornerSightFeet() != 60 ||
            pursuit.hearingMetalFeet() != 90 ||
            pursuit.hearingBootsFeet() != 60 ||
            pursuit.hearingQuietFeet() != 30)
            ++bad;
        // the outdoor table: base 80, every
        // adjustment row cell for cell
        if (pursuit.evadeOutdoorBase() != 80) ++bad;
        if (pursuit.evadeOutdoorSpeedAdj(
                PURS_PURSUED_FASTER) != 10 ||
            pursuit.evadeOutdoorSpeedAdj(
                PURS_EQUAL_SPEED) != 0 ||
            pursuit.evadeOutdoorSpeedAdj(
                PURS_PURSUER_FASTER) != -20) ++bad;
        if (pursuit.evadeOutdoorTerrainAdj(
                EVT_PLAIN_DESERT_WATER) != -50 ||
            pursuit.evadeOutdoorTerrainAdj(
                EVT_SCRUB_ROUGH_HILLS_MARSH) != 10 ||
            pursuit.evadeOutdoorTerrainAdj(
                EVT_FOREST_MOUNTAINS) != 30) ++bad;
        if (pursuit.evadeOutdoorPursuedSizeAdj(5) != 10 ||
            pursuit.evadeOutdoorPursuedSizeAdj(6) != 0 ||
            pursuit.evadeOutdoorPursuedSizeAdj(11) != 0 ||
            pursuit.evadeOutdoorPursuedSizeAdj(12)
                != -20 ||
            pursuit.evadeOutdoorPursuedSizeAdj(50)
                != -20 ||
            pursuit.evadeOutdoorPursuedSizeAdj(51)
                != -50) ++bad;
        if (pursuit.evadeOutdoorPursuerSizeAdj(11)
                != -20 ||
            pursuit.evadeOutdoorPursuerSizeAdj(12) != 0 ||
            pursuit.evadeOutdoorPursuerSizeAdj(24) != 0 ||
            pursuit.evadeOutdoorPursuerSizeAdj(25)
                != 10) ++bad;
        if (pursuit.evadeOutdoorLightAdj(
                EVL_FULL_DAYLIGHT) != -30 ||
            pursuit.evadeOutdoorLightAdj(
                EVL_TWILIGHT) != -10 ||
            pursuit.evadeOutdoorLightAdj(
                EVL_BRIGHT_MOONLIGHT) != 0 ||
            pursuit.evadeOutdoorLightAdj(
                EVL_STARLIGHT) != 20 ||
            pursuit.evadeOutdoorLightAdj(
                EVL_DARK_NIGHT) != 50) ++bad;
        // the assembly: a lone pursued party,
        // pursuer faster, plain, dark night -
        // 80 - 20 - 50 + 10 + 10 + 50 = 80; a
        // 6-member party, equal speed, forest,
        // 12-24 pursuers, daylight - 80 + 30 -
        // 30 = 80; and a 12-member party, equal
        // speed, plain, twilight, 30 pursuers -
        // 80 - 50 - 20 + 10 - 10 = 10 (the +10
        // is the over-24-pursuers band)
        if (pursuit.evadeOutdoorChance(
                PURS_PURSUER_FASTER,
                EVT_PLAIN_DESERT_WATER,
                1, 25, EVL_DARK_NIGHT) != 80 ||
            pursuit.evadeOutdoorChance(
                PURS_EQUAL_SPEED,
                EVT_FOREST_MOUNTAINS,
                6, 12, EVL_FULL_DAYLIGHT) != 80 ||
            pursuit.evadeOutdoorChance(
                PURS_EQUAL_SPEED,
                EVT_PLAIN_DESERT_WATER,
                12, 30, EVL_TWILIGHT) != 10)
            ++bad;
        // the outdoor surprise rule and the
        // hourly recheck
        if (!pursuit.evadeAutoOnSurprise(true) ||
            pursuit.evadeAutoOnSurprise(false) ||
            !pursuit.evadePossibleWhenSurprised(false) ||
            pursuit.evadePossibleWhenSurprised(true) ||
            !pursuit.evadeOutdoorConfronts(0) ||
            !pursuit.evadeOutdoorConfronts(-10) ||
            pursuit.evadeOutdoorConfronts(1)) ++bad;
        printf("R206 pursuit and evasion audit: bad %d\n", bad);
        if (bad) return 1;
    }
