    // ---- R127: waterborne line-diff audit ----
    {
        int bad = 0;
        namespace OE = dm;
        // the four p.190 waterborne tables chain 1 -> 100:
        // no gap, no overlap, no inverted band (the R122
        // line-diff shape on the p.190 waterborne set)
        for (int body = 0; body < 2; ++body) {
            for (int dep = 0; dep < 2; ++dep) {
                std::vector<OE::WaterborneBand> b =
                    OE::waterborneBands(
                        (OE::WaterBody)body,
                        (OE::WaterDepth)dep);
                if (b.empty()) { ++bad; continue; }
                int lo = 1;
                for (const OE::WaterborneBand& x : b) {
                    if (x.lo != lo || x.hi < x.lo) ++bad;
                    lo = x.hi + 1;
                }
                if (lo != 101) ++bad;
            }
        }
        // the shared p.190 Dinosaur Subtable chains likewise
        {
            std::vector<OE::WaterborneBand> b =
                OE::dinosaurSubBands();
            int lo = 1;
            for (const OE::WaterborneBand& x : b) {
                if (x.lo != lo || x.hi < x.lo) ++bad;
                lo = x.hi + 1;
            }
            if (lo != 101) ++bad;
        }
        // spot pins from the verified transcription - flags:
        // 1 = cool only, 2 = warm only, 4 = deep only
        {
            std::vector<OE::WaterborneBand> b = OE::waterborneBands(
                OE::WaterBody::FRESH, OE::WaterDepth::SHALLOW);
            if (!waterBandHas(b, "giant_beaver", 1, 15, 1)) ++bad;
            if (!waterBandHas(b, "nixie", 61, 65, 1)) ++bad;
        }
        {
            std::vector<OE::WaterborneBand> b = OE::waterborneBands(
                OE::WaterBody::FRESH, OE::WaterDepth::DEEP);
            if (!waterBandHas(b, "DINOSAUR", 11, 15, 2)) ++bad;
            if (!waterBandHas(b, "nixie", 86, 90, 2)) ++bad;
            if (!waterBandHas(b, "buccaneer", 34, 48, 0)) ++bad;
            if (!waterBandHas(b, "merchant", 49, 78, 0)) ++bad;
            if (!waterBandHas(b, "buccaneer", 79, 84, 0)) ++bad;
        }
        {
            std::vector<OE::WaterborneBand> b = OE::waterborneBands(
                OE::WaterBody::SALT, OE::WaterDepth::SHALLOW);
            if (!waterBandHas(b, "giant_crocodile", 1, 2, 2)) ++bad;
            if (!waterBandHas(b, "DINOSAUR", 3, 10, 0)) ++bad;
            if (!waterBandHas(b, "caveman", 68, 70, 0)) ++bad;
            if (!waterBandHas(b, "merman", 71, 73, 0)) ++bad;
            if (!waterBandHas(b, "black_whale", 91, 96, 0)) ++bad;
            if (!waterBandHas(b, "white_whale_beluga", 97, 100, 0)) ++bad;
        }
        {
            std::vector<OE::WaterborneBand> b = OE::waterborneBands(
                OE::WaterBody::SALT, OE::WaterDepth::DEEP);
            if (!waterBandHas(b, "DINOSAUR", 1, 5, 0)) ++bad;
            if (!waterBandHas(b, "giant_squid", 54, 55, 0)) ++bad;
            if (!waterBandHas(b, "sperm_whale", 69, 72, 0)) ++bad;
            if (!waterBandHas(b, "whale", 86, 90, 0)) ++bad;
            if (!waterBandHas(b, "right_whale", 91, 95, 0)) ++bad;
            if (!waterBandHas(b, "white_whale_beluga", 96, 100, 0)) ++bad;
        }
        {
            std::vector<OE::WaterborneBand> b =
                OE::dinosaurSubBands();
            if (!waterBandHas(b, "archelon_ischyros", 1, 15, 0)) ++bad;
            if (!waterBandHas(b, "dinichthys", 16, 35, 4)) ++bad;
            if (!waterBandHas(b, "plesiosaurus", 76, 100, 0)) ++bad;
        }
        {
            // the Men substitutions resolve, and no phantom
            // mermaid/pirate key survives
            std::vector<std::string> k = OE::waterborneEncounterKeys(
                reg, OE::WaterBody::SALT, OE::WaterDepth::DEEP);
            int seen = 0;
            for (const std::string& x : k) {
                if (x == "merman" || x == "buccaneer" ||
                    x == "merchant" || x == "giant_squid" ||
                    x == "sperm_whale") ++seen;
            }
            if (seen != 5) ++bad;
        }
        {
            std::vector<std::string> k = OE::waterborneEncounterKeys(
                reg, OE::WaterBody::SALT, OE::WaterDepth::SHALLOW);
            int seen = 0;
            for (const std::string& x : k) {
                if (x == "mermaid" || x == "pirate") ++bad;
                if (x == "caveman" || x == "merman") ++seen;
            }
            if (seen != 2) ++bad;
        }
        printf("R127 waterborne line-diff audit: bad %d\n", bad);
        if (bad) return 1;
    }
