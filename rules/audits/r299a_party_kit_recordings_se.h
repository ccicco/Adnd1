    // ---- R299a: the party kit recordings seam audit ----
    // The kit-grant recording convention (the R299
    // rules/weaponprof.h seam): the melee slot
    // records with every class kit, the ranged slot
    // where the kit carries a missile (the thief
    // rows - the R28 sling pin), the grant count
    // per class pair, the subclass kits ride their
    // base rows, the unknown-subclass fallback
    // reads the base kit, and the identities (the
    // count is melee plus ranged; the missile kits
    // are exactly the printed thief rows). The
    // ENGINE side (the Character grant, the
    // toActor copy, the load rebuild) is the
    // engine audit below.
    {
        int bad = 0;
        // the melee slot: every class kit records
        if (rules::wpfKitRecordsMelee() != 1) ++bad;
        // the ranged slot: the thief-base kits
        // carry the sling; the other base kits
        // record melee only
        if (rules::wpfKitRecordsRanged(0, -1) != 0 ||
            rules::wpfKitRecordsRanged(1, -1) != 0 ||
            rules::wpfKitRecordsRanged(2, -1) != 0 ||
            rules::wpfKitRecordsRanged(3, -1) != 1) ++bad;
        // the subclass kits ride the base kit: the
        // paladin, ranger and monk record the melee
        // arm only; the druid and illusionist ride
        // their bases; the assassin carries the
        // thief sling
        if (rules::wpfKitRecordsRanged(0, 0) != 0 ||
            rules::wpfKitRecordsRanged(0, 1) != 0 ||
            rules::wpfKitRecordsRanged(0, 5) != 0 ||
            rules::wpfKitRecordsRanged(2, 2) != 0 ||
            rules::wpfKitRecordsRanged(1, 3) != 0 ||
            rules::wpfKitRecordsRanged(3, 4) != 1) ++bad;
        // the unknown subclass reads the base kit
        // (the wpfRowFor fallback convention)
        if (rules::wpfKitRecordsRanged(3, 99) != 1 ||
            rules::wpfKitRecordsRanged(3, -5) != 1 ||
            rules::wpfKitRecordsRanged(0, 99) != 0 ||
            rules::wpfKitRecordsRanged(0, -5) != 0) ++bad;
        // the grant count: the four base pairs
        if (rules::wpfKitGrantCount(0, -1) != 1 ||
            rules::wpfKitGrantCount(1, -1) != 1 ||
            rules::wpfKitGrantCount(2, -1) != 1 ||
            rules::wpfKitGrantCount(3, -1) != 2) ++bad;
        // the grant count identity: melee plus
        // ranged, every subclass pair
        for (int s = 0; s < 6; ++s)
            if (rules::wpfKitGrantCount(
                    rules::subclassRuntimeBase(s), s) !=
                rules::wpfKitRecordsMelee() +
                rules::wpfKitRecordsRanged(
                    rules::subclassRuntimeBase(s), -1))
                ++bad;
        // the base agreement: the seam mapping
        // reads the subclassRuntimeBase pin
        for (int s = 0; s < 6; ++s)
            if (rules::wpfKitRecordsRanged(0, s) !=
                rules::wpfKitRecordsRanged(
                    rules::subclassRuntimeBase(s), -1))
                ++bad;
        // the row identity: the kits that carry
        // the missile are exactly the printed
        // thief rows (THIEF 7 and ASSASSIN 8)
        for (int c = 0; c < 4; ++c)
            if (rules::wpfKitRecordsRanged(c, -1) !=
                ((rules::wpfRowFor(c, -1) == 7 ||
                  rules::wpfRowFor(c, -1) == 8)
                     ? 1 : 0)) ++bad;
        printf("R299a party kit recordings seam audit: bad %d\n", bad);
    }
