    // ---- R560 DSG index audit ----
    // the index roster: every pinned page reference lands on a chapter this
    // arc already pinned - Ability Check p. 12, Mapping p. 114, the moral p.
    // 109, the four theories p. 71, the equipment range pp. 56-58, the player
    // types p. 99, the see-cross-references routing the roster, and the
    // back-cover blurb past the index closing the book at printed p. 128.
    {
        using namespace rules;
        int bad = 0;
    if (dcmIndexFirstPage() != 12
            || dcmMappingPage() != 114
            || dcmMoralPage() != 109
            || dcmTheoryCount() != 4
            || !dcmSeeCrossRefs()
            || !dcmPlayerTypesIndexed()
            || !dcmEquipmentRangeIndexed()
            || !dcmBackCoverPastIndex()
        )
            ++bad;
        // the Ability Check roster head at p. 12
    if (dcmIndexFirstPage() != 12
        )
            ++bad;
        // the mapping chapter ref at p. 114
    if (dcmMappingPage() != 114
        )
            ++bad;
        // the story-elements moral ref at p. 109
    if (dcmMoralPage() != 109
        )
            ++bad;
        // the four underdark theories at p. 71
    if (dcmTheoryCount() != 4
        )
            ++bad;
        // the see cross-references route the roster
    if (dcmSeeCrossRefs() != 1
        )
            ++bad;
        // the player types ref at p. 99
    if (dcmPlayerTypesIndexed() != 1
        )
            ++bad;
        // the equipment range ref pp. 56-58
    if (dcmEquipmentRangeIndexed() != 1
        )
            ++bad;
        // the back-cover blurb past the index
    if (dcmBackCoverPastIndex() != 1
        )
            ++bad;
        printf("R560 DSG index audit: bad %d\n", bad);
        if (bad) return 1;
    }
