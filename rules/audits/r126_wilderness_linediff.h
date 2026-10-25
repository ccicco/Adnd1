    // ---- R126: wilderness line-diff audit ----
    {
        int bad = 0;
        namespace OE = dm;
        // every served climate/terrain column chains 1 -> 100:
        // no gap, no overlap, no inverted band (the R122
        // line-diff shape on the R63 outdoor tables)
        for (int c = 0; c < 8; ++c) {
            for (int t = 0; t < 8; ++t) {
                std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                    (OE::OutdoorClime)c, (OE::OutdoorTerrain)t);
                if (b.empty()) continue;
                int lo = 1;
                for (const OE::OutdoorBand& x : b) {
                    if (x.lo != lo || x.hi < x.lo) ++bad;
                    lo = x.hi + 1;
                }
                if (lo != 101) ++bad;
            }
        }
        // the eleven terrain-column subtables chain likewise;
        // SUB_SPHINX_T is the tropical single-column footnote
        static const char* kSubs[12] = {
            "SUB_DEMIHUMAN", "SUB_DRAGON", "SUB_FROG",
            "SUB_GIANT", "SUB_HUMANOID", "SUB_LYCANTHROPE",
            "SUB_MEN", "SUB_SNAKE", "SUB_SPHINX",
            "SUB_SPIDER", "SUB_UNDEAD", "SUB_SPHINX_T"
        };
        for (const char* s : kSubs) {
            for (int t = 0; t < 8; ++t) {
                std::vector<OE::OutdoorBand> b = OE::outdoorSubBands(
                    s, (OE::OutdoorTerrain)t);
                if (b.empty()) continue;
                int lo = 1;
                for (const OE::OutdoorBand& x : b) {
                    if (x.lo != lo || x.hi < x.lo) ++bad;
                    lo = x.hi + 1;
                }
                if (lo != 101) ++bad;
            }
        }
        // spot pins from the verified transcription - the
        // documented OCR/print folds (R63 header, R126
        // line-diff vs. the 1eonline Appendix C compilation)
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_TEMPERATE_WILD, OE::T_SCRUB);
            if (!bandHas(b, "SUB_HUMANOID", 26, 32)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_TEMPERATE_WILD, OE::T_PLAIN);
            if (!bandHas(b, "giant_eagle", 15, 16)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_TROPICAL, OE::T_ROUGH);
            if (!bandHas(b, "giant_scorpion", 84, 85)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_TROPICAL, OE::T_MOUNTAINS);
            if (!bandHas(b, "bandit", 23, 30)) ++bad;
        }
        {
            // the tropical mountains Sphinx row resolves off
            // the p.189 single-column footnote - all four
            std::vector<std::string> k = OE::outdoorEncounterKeys(
                reg, OE::OC_TROPICAL, OE::T_MOUNTAINS);
            int seen = 0;
            for (const std::string& x : k) {
                if (x == "androsphinx" || x == "criosphinx" ||
                    x == "gynosphinx" || x == "hieracosphinx") ++seen;
            }
            if (seen != 4) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_SUB_ARCTIC, OE::T_MARSH);
            if (!bandHas(b, "caveman", 56, 65)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorBands(
                OE::OC_ARCTIC, OE::T_MOUNTAINS);
            if (!bandHas(b, "yeti", 91, 100)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorSubBands(
                "SUB_DRAGON", OE::T_FOREST);
            if (!bandHas(b, "chimera", 23, 30)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorSubBands(
                "SUB_GIANT", OE::T_HILLS);
            if (!bandHas(b, "stone_giant", 82, 98)) ++bad;
        }
        {
            std::vector<OE::OutdoorBand> b = OE::outdoorSubBands(
                "SUB_MEN", OE::T_MARSH);
            if (!bandHas(b, "pilgrim", 36, 50)) ++bad;
            if (!bandHas(b, "caveman", 51, 100)) ++bad;
        }
        printf("R126 wilderness line-diff audit: bad %d\n", bad);
        if (bad) return 1;
    }
