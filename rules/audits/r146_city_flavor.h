    // ---- R146: city flavor subtables audit ----
    // The two flavor subtables R64 named as unmodeled:
    // the p.191 drunk identity table ("the character(s)
    // found drunk should be diced for") and the p.192
    // harlot type table, both cell-verified at the
    // raw-HTML level of the 1eonline.info compilation -
    // the repo-trusted source; the DMG re-upload's OCR
    // debt stands (the compilation's 'Haughy' is the
    // printed 'haughty', corrected). Fiction-only
    // descriptors; every band edge pinned both ways: at
    // the edge the kind, one below the edge the next.
    {
        int bad = 0;
        // the drunk's dice-for identity (p.191): 20 bands
        static const struct { int lo, hi; const char* k; }
            kDrunk[] = {
            {   1,  2, "assassin" },
            {   3,10, "bandit" },
            { 11,18, "brigand" },
            { 19,20, "city guard" },
            { 21,22, "city official" },
            { 23,25, "city watchman" },
            { 26,27, "cleric" },
            { 28,29, "druid" },
            { 30,38, "fighter" },
            { 39,45, "gentleman" },
            { 46,48, "illusionist" },
            { 49,63, "laborer" },
            { 64,65, "magic-user" },
            { 66,73, "mercenary" },
            { 74,80, "merchant" },
            { 81,82, "noble" },
            { 83,90, "rake" },
            { 91,95, "ruffian" },
            { 96,97, "thief" },
            { 98,100, "tradesman" },
        };
        for (int i = 0; i < 20; ++i) {
            if (std::string(dm::cityDrunkKind(kDrunk[i].lo))
                != kDrunk[i].k) ++bad;
            if (std::string(dm::cityDrunkKind(kDrunk[i].hi))
                != kDrunk[i].k) ++bad;
            if (kDrunk[i].lo > 1 && std::string(
                    dm::cityDrunkKind(kDrunk[i].lo - 1))
                == kDrunk[i].k) ++bad;
        }
        // the harlot's type (p.192): 12 bands
        static const struct { int lo, hi; const char* k; }
            kHarlot[] = {
            {   1,10, "slovenly trull" },
            { 11,25, "brazen strumpet" },
            { 26,35, "cheap trollop" },
            { 36,50, "typical streetwalker" },
            { 51,65, "saucy tart" },
            { 66,75, "wanton wench" },
            { 76,85, "expensive doxy" },
            { 86,90, "haughty courtesan" },
            { 91,92, "aged madam" },
            { 93,94, "wealthy procuress" },
            { 95,98, "sly pimp" },
            { 99,100, "rich panderer" },
        };
        for (int i = 0; i < 12; ++i) {
            if (std::string(dm::cityHarlotKind(kHarlot[i].lo))
                != kHarlot[i].k) ++bad;
            if (std::string(dm::cityHarlotKind(kHarlot[i].hi))
                != kHarlot[i].k) ++bad;
            if (kHarlot[i].lo > 1 && std::string(
                    dm::cityHarlotKind(kHarlot[i].lo - 1))
                == kHarlot[i].k) ++bad;
        }
        // the sweep: every percentile yields a kind on
        // both tables (the clamps cover <1 / >100)
        for (int p = 1; p <= 100; ++p) {
            if (!*dm::cityDrunkKind(p)) ++bad;
            if (!*dm::cityHarlotKind(p)) ++bad;
        }
        printf("R146 city flavor audit: bad %d\n", bad);
        if (bad) return 1;
    }
