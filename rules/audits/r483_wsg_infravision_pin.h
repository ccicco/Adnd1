    // ---- R483 WSG infravision pin audit ----
    // The infravision and Table 41 rules: infravision, or heat vision, is the
    // ability to see the shapes of objects by sensing radiation in the
    // infrared spectrum; all nonhuman player characters have it, most out to
    // 60 yards (outdoor scale); halflings other than pure-blooded Stouts see
    // 30 yards; drow, duergar and deep gnomes see 120. Table 41 gives the
    // outdoor range of normal vision in yards for six conditions across four
    // light levels: clear 500/300/50/25; overcast 400/250/50/25; moderate fog
    // 150/100/25/15; heavy fog, rain or snow 50/30/15/10; heavy snow with
    // wind 35/25/10/5; blowing sand or dust 20/20/10/5. The given range is
    // the distance at which a viewer discerns a size M object that stands out
    // from the terrain; double it for size L, halve it for size S. The range
    // assumes long-range concentration and a target that is not concealed:
    // the orc lying down on the plain is greatly harder to spot, and prone in
    // three-foot grass it is effectively invisible until the viewer is very
    // close. In daylight or twilight a character can scan long and short
    // range at once by shifting his gaze every few seconds, even at full
    // speed; in moonlight or darkness that fails - a moving character may
    // step into a crevasse he just looked at, so a lone traveler watches his
    // footing, a group splits lookout duty, and stopping to peer is safest
    // but still no guard against a nearby silent moving hazard.
    {
        using namespace rules;
        int bad = 0;
    if (wivConditionCount() != 6
            || wivLightLevelCount() != 4
            || wivSizeLDoubleFactor() != 2
            || wivSizeSHalfFactor() != 2
            || wivInfravisionRangeYards() != 60
            || wivHalflingRangeYards() != 30
            || wivDeepRangeYards() != 120
            || !wivYardsUnits()
            || !wivSizeMStandsOut()
            || !wivAssumesLongRangeFocus()
            || !wivTargetNotConcealed()
            || !wivLyingDownReduces()
            || !wivGrassHidesUntilClose()
            || !wivDaylightDualScan()
            || !wivGazeShiftEveryFewSeconds()
            || !wivFullSpeedDualScan()
            || !wivDarkScanDegrades()
            || !wivDarkFootingFirst()
            || !wivLookoutDutySplit()
            || !wivStopAndPeerSafest()
            || !wivMovingHazardUnseen()
            || !wivHeatVisionDefinition()
            || !wivAllNonhumanHaveInfravision()
            || !wivMostOutTo60Yards()
            || !wivHalfling30UnlessStout()
            || !wivDeepRaces120()
            || !wivOutdoorScaleNote()
        )
            ++bad;
        // the wivRangeGrid grid
        int C41[6][4] = {
            {500,300,50,25},
            {400,250,50,25},
            {150,100,25,15},
            {50,30,15,10},
            {35,25,10,5},
            {20,20,10,5},
            };
        for (int b = 0;
             b < wivConditionCount();
             ++b) {
            int vals[4];
            vals[0] = wivDaylightYards(b);
            vals[1] = wivTwilightYards(b);
            vals[2] = wivMoonlightYards(b);
            vals[3] = wivDarknessYards(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C41[b][c])
                    ++bad;
            }
        }
        // clear daylight is 500 yards, the R482 effective range; doubled for
        // size L it is the 1000 floor
    if (wivDaylightYards(0) != 500
            || wivDaylightYards(0) * wivSizeLDoubleFactor() != 1000
        )
            ++bad;
        // clear daylight halved for size S is the 250 size S distance
    if (wivDaylightYards(0) / wivSizeSHalfFactor() != 250
        )
            ++bad;
        // moonlight never below darkness, and blowing sand twilight EQUALS
        // daylight (no strict drop)
    if (wivMoonlightYards(0) < wivDarknessYards(0)
            || wivTwilightYards(5) < wivDaylightYards(5)
        )
            ++bad;
        // the deep-race range doubles the standard range, which doubles the
        // halfling range
    if (wivDeepRangeYards() != 2 * wivInfravisionRangeYards()
            || wivInfravisionRangeYards() != 2 * wivHalflingRangeYards()
        )
            ++bad;
        // overcast drops clear by exactly 100 in daylight and 50 in twilight
    if (wivDaylightYards(0) - wivDaylightYards(1) != 100
            || wivTwilightYards(0) - wivTwilightYards(1) != 50
        )
            ++bad;
        // the darkness column: clear and overcast tie at 25, and the two
        // worst conditions bottom out at 5
    if (wivDarknessYards(0) != wivDarknessYards(1)
            || wivDarknessYards(4) != 5
            || wivDarknessYards(5) != 5
        )
            ++bad;
        printf("R483 WSG infravision pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
