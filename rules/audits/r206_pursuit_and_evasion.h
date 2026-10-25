    // ---- R206: the pursuit and evasion audit ----
    // DMG pp.67-69: the underground pursuit
    // likelihood ladder, the three end-condition
    // cases by relative speed, the food and
    // treasure distractions, the multiple-choice
    // and detection radii, and the outdoor
    // evasion table (base 80 with the speed,
    // terrain, size and light adjustments).
    {
        int bad = 0;
        // the motivated semi-intelligent band
        if (rules::pursueLikelihoodMotivatedSemi() != 80)
            ++bad;
        // the low-intelligence ladder: 20 / 40 /
        // 80, and 100 when the outnumbering
        // pursuers feel greatly superior
        if (rules::pursueLikelihoodLowInt(
                true, false, false) != 20 ||
            rules::pursueLikelihoodLowInt(
                false, true, false) != 40 ||
            rules::pursueLikelihoodLowInt(
                false, false, false) != 80 ||
            rules::pursueLikelihoodLowInt(
                false, false, true) != 100) ++bad;
        // the end-condition distances and caps by
        // relative speed: 100/50/5 rounds,
        // 150/80/1 turn, 200/none/no cap
        if (rules::pursuitEndSightFeet(
                rules::PURS_PURSUED_FASTER) != 100 ||
            rules::pursuitEndSightFeet(
                rules::PURS_EQUAL_SPEED) != 150 ||
            rules::pursuitEndSightFeet(
                rules::PURS_PURSUER_FASTER) != 0) ++bad;
        if (rules::pursuitEndOutOfSightFeet(
                rules::PURS_PURSUED_FASTER) != 50 ||
            rules::pursuitEndOutOfSightFeet(
                rules::PURS_EQUAL_SPEED) != 80 ||
            rules::pursuitEndOutOfSightFeet(
                rules::PURS_PURSUER_FASTER) != 200) ++bad;
        if (rules::pursuitEndRoundCap(
                rules::PURS_PURSUED_FASTER) != 5 ||
            rules::pursuitEndRoundCap(
                rules::PURS_EQUAL_SPEED) != 10 ||
            rules::pursuitEndRoundCap(
                rules::PURS_PURSUER_FASTER) != -1) ++bad;
        // the composition: in sight at 101 feet
        // ends the faster-pursued case; 100 does
        // not; out of sight lost at 201 ends the
        // pursuer-faster case; past the round cap
        // without a gain ends it
        if (!rules::pursuitEnds(
                rules::PURS_PURSUED_FASTER, true, 101,
                false, 0, 0, false)) ++bad;
        if (rules::pursuitEnds(
                rules::PURS_PURSUED_FASTER, true, 100,
                false, 0, 0, false)) ++bad;
        if (!rules::pursuitEnds(
                rules::PURS_PURSUER_FASTER, false, 0,
                true, 201, 0, false)) ++bad;
        if (rules::pursuitEnds(
                rules::PURS_PURSUER_FASTER, false, 0,
                true, 200, 0, false)) ++bad;
        if (!rules::pursuitEnds(
                rules::PURS_EQUAL_SPEED, false, 0,
                false, 0, 11, false)) ++bad;
        if (rules::pursuitEnds(
                rules::PURS_EQUAL_SPEED, false, 0,
                false, 0, 11, true)) ++bad;
        // the movement procedure: 3 phases per
        // round, contact at 10 feet
        if (rules::pursuitPhasesPerRound() != 3 ||
            rules::pursuitConfrontFeet() != 10) ++bad;
        // the food distraction: 100 percent for
        // non-intelligent; d10 base + 10 per point
        // below 5; the confirm roll at or under
        if (rules::foodDistractionPercent(0, 0) != 100 ||
            rules::foodDistractionPercent(5, 5) != 50 ||
            rules::foodDistractionPercent(5, 2) != 80 ||
            rules::foodDistractionPercent(9, 1) != 100 ||
            rules::foodDistractionPercent(3, 7) != 30)
            ++bad;
        // at 100 percent the distraction is automatic -
        // the print spares the second d10 - so the
        // function returns true: pinned as correct
        if (!rules::foodDistractionSucceeds(100, 1) ||
            !rules::foodDistractionSucceeds(80, 8) ||
            rules::foodDistractionSucceeds(80, 9) ||
            !rules::foodDistractionSucceeds(30, 3) ||
            rules::foodDistractionSucceeds(30, 4) ||
            rules::foodDistractionBreakRounds() != 1)
            ++bad;
        // the treasure distraction: +10 per 10
        // items for low intelligence, +10 per
        // 100 gp of value
        if (rules::treasureDistractionLowInt(
                20, 20) != 40 ||
            rules::treasureDistractionLowInt(
                20, 100) != 100 ||
            rules::treasureDistractionValueBonus(
                250) != 20 ||
            rules::treasureDistractionValueBonus(
                99) != 0) ++bad;
        // the multiple-choice and detection radii
        if (rules::pursuitWrongChoiceWays(3) != 2 ||
            rules::pursuitWrongChoiceWays(2) != 1)
            ++bad;
        if (rules::pursuitCornerSightFeet() != 60 ||
            rules::pursuitHearingMetalFeet() != 90 ||
            rules::pursuitHearingBootsFeet() != 60 ||
            rules::pursuitHearingQuietFeet() != 30)
            ++bad;
        // the outdoor table: base 80, every
        // adjustment row cell for cell
        if (rules::evadeOutdoorBase() != 80) ++bad;
        if (rules::evadeOutdoorSpeedAdj(
                rules::PURS_PURSUED_FASTER) != 10 ||
            rules::evadeOutdoorSpeedAdj(
                rules::PURS_EQUAL_SPEED) != 0 ||
            rules::evadeOutdoorSpeedAdj(
                rules::PURS_PURSUER_FASTER) != -20) ++bad;
        if (rules::evadeOutdoorTerrainAdj(
                rules::EVT_PLAIN_DESERT_WATER) != -50 ||
            rules::evadeOutdoorTerrainAdj(
                rules::EVT_SCRUB_ROUGH_HILLS_MARSH) != 10 ||
            rules::evadeOutdoorTerrainAdj(
                rules::EVT_FOREST_MOUNTAINS) != 30) ++bad;
        if (rules::evadeOutdoorPursuedSizeAdj(5) != 10 ||
            rules::evadeOutdoorPursuedSizeAdj(6) != 0 ||
            rules::evadeOutdoorPursuedSizeAdj(11) != 0 ||
            rules::evadeOutdoorPursuedSizeAdj(12)
                != -20 ||
            rules::evadeOutdoorPursuedSizeAdj(50)
                != -20 ||
            rules::evadeOutdoorPursuedSizeAdj(51)
                != -50) ++bad;
        if (rules::evadeOutdoorPursuerSizeAdj(11)
                != -20 ||
            rules::evadeOutdoorPursuerSizeAdj(12) != 0 ||
            rules::evadeOutdoorPursuerSizeAdj(24) != 0 ||
            rules::evadeOutdoorPursuerSizeAdj(25)
                != 10) ++bad;
        if (rules::evadeOutdoorLightAdj(
                rules::EVL_FULL_DAYLIGHT) != -30 ||
            rules::evadeOutdoorLightAdj(
                rules::EVL_TWILIGHT) != -10 ||
            rules::evadeOutdoorLightAdj(
                rules::EVL_BRIGHT_MOONLIGHT) != 0 ||
            rules::evadeOutdoorLightAdj(
                rules::EVL_STARLIGHT) != 20 ||
            rules::evadeOutdoorLightAdj(
                rules::EVL_DARK_NIGHT) != 50) ++bad;
        // the assembly: a lone pursued party,
        // pursuer faster, plain, dark night -
        // 80 - 20 - 50 + 10 + 10 + 50 = 80; a
        // 6-member party, equal speed, forest,
        // 12-24 pursuers, daylight - 80 + 30 -
        // 30 = 80; and a 12-member party, equal
        // speed, plain, twilight, 30 pursuers -
        // 80 - 50 - 20 + 10 - 10 = 10 (the +10
        // is the over-24-pursuers band)
        if (rules::evadeOutdoorChance(
                rules::PURS_PURSUER_FASTER,
                rules::EVT_PLAIN_DESERT_WATER,
                1, 25, rules::EVL_DARK_NIGHT) != 80 ||
            rules::evadeOutdoorChance(
                rules::PURS_EQUAL_SPEED,
                rules::EVT_FOREST_MOUNTAINS,
                6, 12, rules::EVL_FULL_DAYLIGHT) != 80 ||
            rules::evadeOutdoorChance(
                rules::PURS_EQUAL_SPEED,
                rules::EVT_PLAIN_DESERT_WATER,
                12, 30, rules::EVL_TWILIGHT) != 10)
            ++bad;
        // the outdoor surprise rule and the
        // hourly recheck
        if (!rules::evadeAutoOnSurprise(true) ||
            rules::evadeAutoOnSurprise(false) ||
            !rules::evadePossibleWhenSurprised(false) ||
            rules::evadePossibleWhenSurprised(true) ||
            !rules::evadeOutdoorConfronts(0) ||
            !rules::evadeOutdoorConfronts(-10) ||
            rules::evadeOutdoorConfronts(1)) ++bad;
        printf("R206 pursuit and evasion audit: bad %d\n", bad);
        if (bad) return 1;
    }
