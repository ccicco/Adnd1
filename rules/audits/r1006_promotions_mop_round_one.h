    // ---- R1006 promotions mop round one audit ----
    // THE PROMOTIONS MOP OPENER - the registry never-load repair. Twenty-five
    // Fiend Folio promotion defs of the R836-R842 arc carried raw newlines in
    // their text fields where the backslash-n escapes belong; the Lua loader
    // read unfinished-string errors and the battery line held 1313 loaded,
    // errors 25 since the R924 re-measure. The repair is mechanical: the
    // paragraph breaks escape, no ink touched, the round-trip proof equal,
    // and the battery line moves to loaded 1338, errors 0 - the registry
    // floor meets the file count. The historical snapshot pins (cfc
    // 1311/1333/25, d21/l22/l23 1313/1338/25) stand as landed; the never-load
    // doctrine retires at this round.
    {
        using namespace rules;
        int bad = 0;
    if (pm1Round() != 1006
            || pm1RepairedDefs() != 25
            || pm1ParagraphBreaksEscaped() != 174
            || pm1RegistryLoadedAfter() != 1338
            || pm1BaseLuaFiles() != 1338
            || pm1NeverLoadAfter() != 0
            || pm1PreviousNeverLoad() != 25
            || !pm1RepairMechanical()
            || !pm1RoundTripGreen()
            || !pm1GroundTruthReplaced()
        )
            ++bad;
        // the repair census - twenty-five defs, the escaped paragraph breaks,
        // the opener round
    if (pm1RepairedDefs() != 25
            || pm1ParagraphBreaksEscaped() != 174
            || pm1Round() != 1006
        )
            ++bad;
        // the ground truth - loaded 1338 of 1338 base files, zero never-load,
        // the 25 the retired historical count
    if (pm1RegistryLoadedAfter() != 1338
            || pm1BaseLuaFiles() != 1338
            || pm1NeverLoadAfter() != 0
            || pm1PreviousNeverLoad() != 25
        )
            ++bad;
        // the repair doctrines - mechanical only, the tree clean, the battery
        // line the only truth
    if (pm1RepairMechanical() != 1
            || pm1RoundTripGreen() != 1
            || pm1GroundTruthReplaced() != 1
        )
            ++bad;
        printf("R1006 promotions mop round one audit: bad %d\n", bad);
        if (bad) return 1;
    }
