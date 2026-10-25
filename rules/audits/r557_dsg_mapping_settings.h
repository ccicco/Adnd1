    // ---- R557 DSG mapping settings audit ----
    // The mapping your settings pins printed pp. 114-117: the chapter head
    // (the orthographic blueprint maps and their per-level split, the
    // perspective alternative), Basic Mapping Considerations (the effective
    // map, the tools), Perspective Mapping (the 3-D advantages, the occlusion
    // and time costs, the photocopy and tracing techniques), Selecting a Grid
    // (the shape match, the occluded-area design, the front-loaded detail),
    // Selecting a Starting Point (the front start, the control square),
    // Drawing the Map (the orthographic likeness, the outer-limit-first
    // option), Mapping Symbols (the translated symbols, the 3-D styles),
    // Splitting the Grid (the tracing and photocopy methods with the
    // 10-foot-square, 20-foot-platform example), Horizon Lines (the
    // orientation, the perpendicular verticals), Geomorphic Mapping (the
    // problem, the definitions, the shapes, the standardized connections, the
    // 60-foot section with its 1-2 connections against the square-mile 6-8,
    // the 75% entry rule), and Using Geomorphs (the random generation, the
    // placement rolls, the exploration and dead ends, the variety). The
    // Mapping your settings child flips [x] in the same commit.
    {
        using namespace rules;
        int bad = 0;
    if (dcjGridSquareFeet() != 10
            || dcjPlatformExampleFeet() != 20
            || dcjGeomorphSectionFeet() != 60
            || dcjGeomorphSmallConnsMin() != 1
            || dcjGeomorphSmallConnsMax() != 2
            || dcjGeomorphLargeConnsMin() != 6
            || dcjGeomorphLargeConnsMax() != 8
            || dcjGeomorphEntryPct() != 75
            || !dcjOrthoDefines()
            || !dcjOrthoLevelSplit()
            || !dcjPerspectiveIntro()
            || !dcjEffectiveMap()
            || !dcjMappingTools()
            || !dcjPerspective3D()
            || !dcjPerspectiveCosts()
            || !dcjPerspectiveReward()
            || !dcjStartPhotocopy()
            || !dcjStartTracing()
            || !dcjGridShapeMatch()
            || !dcjGridObscureDesign()
            || !dcjGridFrontDetail()
            || !dcjStartFront()
            || !dcjControlSquare()
            || !dcjDrawLikeOrtho()
            || !dcjDrawOuterFirst()
            || !dcjSymbolsTranslated()
            || !dcjSymbolStyles()
            || !dcjSplitGrid()
            || !dcjSplitTracing()
            || !dcjSplitPhotocopy()
            || !dcjHorizonOrient()
            || !dcjHorizonVertical()
            || !dcjGeomorphProblem()
            || !dcjGeomorphDefines()
            || !dcjGeomorphSuitable()
            || !dcjGeomorphSections()
            || !dcjGeomorphShapes()
            || !dcjGeomorphPlanConnections()
            || !dcjGeomorphStandardized()
            || !dcjGeomorphRandom()
            || !dcjGeomorphPositions()
            || !dcjGeomorphExplore()
            || !dcjGeomorphVariety()
        )
            ++bad;
        // the splitting example: 10-foot squares, the 20-foot platform.
    if (dcjGridSquareFeet() != 10
            || dcjPlatformExampleFeet() != 20
        )
            ++bad;
        // the platform grid twice the square distance above the cut line.
    if (dcjPlatformExampleFeet() / dcjGridSquareFeet() != 2
        )
            ++bad;
        // the small geomorph: the 60 x 60-foot section.
    if (dcjGeomorphSectionFeet() != 60
        )
            ++bad;
        // the small-section connections: one, perhaps two, per side.
    if (dcjGeomorphSmallConnsMin() != 1
            || dcjGeomorphSmallConnsMax() != 2
        )
            ++bad;
        // the square-mile realm: six to eight connections per side.
    if (dcjGeomorphLargeConnsMin() != 6
            || dcjGeomorphLargeConnsMax() != 8
        )
            ++bad;
        // the entry rule: at least 75% of connections providing entry.
    if (dcjGeomorphEntryPct() != 75
        )
            ++bad;
        // the geomorphs: the shapes and the standardized connections.
    if (dcjGeomorphShapes() != 1
            || dcjGeomorphStandardized() != 1
        )
            ++bad;
        // the craft: the perpendicular verticals and the control square.
    if (dcjHorizonVertical() != 1
            || dcjControlSquare() != 1
        )
            ++bad;
        printf("R557 DSG mapping settings audit: bad %d\n", bad);
        if (bad) return 1;
    }
