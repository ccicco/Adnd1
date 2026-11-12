    // ---- R967 content tree creation audit ----
    // the tree audit - thirteen keeps, the 1338 lua records unchanged by the
    // move, the six rewritten path lines, the four world-tree buckets, the
    // 1313 loaded floor expected at preflight from the new path, every fact
    // fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (cntTreeKeeps() != 13
            || cntMonsterLua() != 1338
            || cntLoaderTouchLines() != 6
            || cntWorldTreeDirs() != 4
            || cntLoadedFloor() != 1313
            || !cntSkeletonCreated()
            || !cntMonstersMoved()
            || !cntLoaderPathUpdated()
            || !cntKeepEmptyDirsOnly()
            || !cntLoaderStaysEngine()
        )
            ++bad;
        // the frame - thirteen keeps, 1338 records unchanged, four world-tree
        // buckets
    if (cntTreeKeeps() != 13
            || cntMonsterLua() != 1338
            || cntWorldTreeDirs() != 4
        )
            ++bad;
        // the loader - six rewritten lines, the 1313 loaded floor from the
        // new path
    if (cntLoaderTouchLines() != 6
            || cntLoadedFloor() != 1313
        )
            ++bad;
        // the skeleton - data files create it, no keep in a full directory
    if (cntSkeletonCreated() != 1
            || cntKeepEmptyDirsOnly() != 1
        )
            ++bad;
        // the move - the registry under content/monsters, every path line
        // rewritten
    if (cntMonstersMoved() != 1
            || cntLoaderPathUpdated() != 1
        )
            ++bad;
        // the charter held - the loader code stays in monsters/, no C++ in
        // the content tree
    if (cntLoaderStaysEngine() != 1
        )
            ++bad;
        printf("R967 content tree creation audit: bad %d\n", bad);
        if (bad) return 1;
    }
