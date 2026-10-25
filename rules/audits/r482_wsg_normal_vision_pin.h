    // ---- R482 WSG normal vision pin audit ----
    // The normal vision rules: normal vision is what humans and most other
    // creatures and character races use most of the time - the ability to see
    // images, colors and other visual phenomena within the visible spectrum,
    // between the infrared and ultraviolet ranges. In clear air during
    // daylight the effective range is 500 yards: a character with an
    // unobstructed view recognizes the basic form of a size M creature or
    // object at that distance; a size S creature is visible from 250 yards; a
    // size L creature from at least 1000 yards - or much greater for
    // exceptionally large creatures or objects such as a dragon or a tall
    // building. Practically anything in the line of sight can be an
    // obstruction, and ideal viewing conditions are rare when viewer and
    // target share the ground and elevation: a six-foot-tall orc on a flat
    // featureless plain is visible at 500 yards, but under a three-foot
    // height of grass and foliage only half its body shows, so it is only
    // viewed from 250 yards - as if it were size S. Drastically different
    // elevations often give an unobstructed view: a character on a lone
    // mountain peak sees for miles, but his effective range is unchanged - he
    // must still be within 500 yards of a size M object to distinguish its
    // basic form. The converse holds too: the man on the peak is himself
    // visible and recognizable to any viewer within 500 yards - long-range
    // visibility is a blessing and a curse at once.
    {
        using namespace rules;
        int bad = 0;
    if (wnvVisualSenseCount() != 3
            || wnvRangeYards() != 500
            || wnvSizeSYards() != 250
            || wnvSizeLYards() != 1000
            || wnvExOrcHeightFeet() != 6
            || wnvExGrassHeightFeet() != 3
            || wnvHalfNum() != 1
            || wnvHalfDen() != 2
            || !wnvNormalVisionMostCommon()
            || !wnvVisibleSpectrumBetween()
            || !wnvSightMeansFastOrSlow()
            || !wnvEachSenseHasTradeoffs()
            || !wnvSizeMRecognizedAtRange()
            || !wnvSizeLMayExceed()
            || !wnvAnythingObstructs()
            || !wnvGrassHalvesToSizeS()
            || !wnvElevationUnobstructs()
            || !wnvRangeUnchangedOnPeak()
            || !wnvConverseViewerVisible()
            || !wnvBlessingAndCurse()
        )
            ++bad;
        // the three senses, and the size S distance is half the effective
        // range while the size L floor is double it
    if (wnvVisualSenseCount() != 3
            || 2 * wnvSizeSYards() != wnvRangeYards()
            || wnvSizeLYards() != 2 * wnvRangeYards()
        )
            ++bad;
        // the worked example: a six-foot orc over three-foot grass shows half
        // its body and drops to the size S distance
    if (wnvExOrcHeightFeet() != 6
            || wnvExGrassHeightFeet() != 3
            || wnvHalfDen() != 2 * wnvHalfNum()
            || wnvRangeYards() != 500
        )
            ++bad;
        printf("R482 WSG normal vision pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
