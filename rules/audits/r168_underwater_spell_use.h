    // ---- R168: underwater spell use audit ------------
    // DMG p.57: the general limits, the two printed
    // spell lists (cannot-cast by class and level,
    // altered effects) and the altered numerics.
    {
        int bad = 0;
        // the general paragraph
        if (!rules::uwSpellRangesAsDungeons() ||
            !rules::uwFireSpellsFailExceptInAiryWater() ||
            !rules::uwElectricalSpellsConductedToArea() ||
            !rules::uwMaterialComponentsAltered())
            ++bad;
        // the cannot-cast list: 41 entries
        // (9 cleric, 22 druid, 10 magic-user)
        if (rules::uwCannotCastCount() != 41) ++bad;
        if (rules::uwCannotCastClassCount("cleric") != 9 ||
            rules::uwCannotCastClassCount("druid") != 22 ||
            rules::uwCannotCastClassCount("magic-user") != 10)
            ++bad;
        // 11 entries carry the printed asterisk mark
        {
            int marks = 0;
            for (int i = 0; i < rules::uwCannotCastCount();
                 ++i)
                if (rules::uwCannotCast(i).printedMark) ++marks;
            if (marks != 11) ++bad;
        }
        // spot the rows: first and last of each class
        if (std::string(rules::uwCannotCast(0).cls) != "cleric" ||
            rules::uwCannotCast(0).level != 3 ||
            std::string(rules::uwCannotCast(0).name)
                != "speak with dead" ||
            !rules::uwCannotCast(0).printedMark)
            ++bad;
        if (std::string(rules::uwCannotCast(8).cls) != "cleric" ||
            rules::uwCannotCast(8).level != 7 ||
            std::string(rules::uwCannotCast(8).name)
                != "wind walk")
            ++bad;
        if (std::string(rules::uwCannotCast(9).cls) != "druid" ||
            rules::uwCannotCast(9).level != 1 ||
            std::string(rules::uwCannotCast(9).name)
                != "predict weather")
            ++bad;
        if (std::string(rules::uwCannotCast(30).cls) != "druid" ||
            rules::uwCannotCast(30).level != 7 ||
            std::string(rules::uwCannotCast(30).name)
                != "fire storm")
            ++bad;
        if (std::string(rules::uwCannotCast(31).cls)
                != "magic-user" ||
            rules::uwCannotCast(31).level != 1 ||
            std::string(rules::uwCannotCast(31).name)
                != "affect normal fires" ||
            !rules::uwCannotCast(31).printedMark)
            ++bad;
        if (std::string(rules::uwCannotCast(40).cls)
                != "magic-user" ||
            rules::uwCannotCast(40).level != 4 ||
            std::string(rules::uwCannotCast(40).name)
                != "fire trap")
            ++bad;
        // the middle rows: cleric atonement and
        // flame strike, druid produce fire
        if (std::string(rules::uwCannotCast(3).name)
                != "atonement" ||
            std::string(rules::uwCannotCast(4).name)
                != "flame strike" ||
            std::string(rules::uwCannotCast(17).name)
                != "produce fire" ||
            rules::uwCannotCast(17).level != 4)
            ++bad;
        // the membership probe, both ways
        if (!rules::uwIsCannotCast("cleric", 5, "flame strike") ||
            !rules::uwIsCannotCast("druid", 2, "produce flame") ||
            !rules::uwIsCannotCast("magic-user", 3, "fireball"))
            ++bad;
        if (rules::uwIsCannotCast("cleric", 1, "cure light wounds") ||
            rules::uwIsCannotCast("magic-user", 3, "fly") ||
            rules::uwIsCannotCast("druid", 4, "plant growth"))
            ++bad;
        // the printed reverse/shield notes
        if (!rules::uwHeatMetalReverseChillWorks() ||
            !rules::uwFireShieldColdFlameWorks())
            ++bad;
        // the altered-effects list: 10 entries
        // (2 cleric, 1 druid, 7 magic-user)
        if (rules::uwAlteredCount() != 10) ++bad;
        {
            int cl = 0, dr = 0, mu = 0;
            for (int i = 0; i < 10; ++i) {
                std::string c = rules::uwAltered(i).cls;
                if (c == "cleric") ++cl;
                else if (c == "druid") ++dr;
                else ++mu;
            }
            if (cl != 2 || dr != 1 || mu != 7) ++bad;
        }
        static const int kAltLevel[10] = {
            6, 7, 7, 3, 3, 3, 3, 5, 6, 6
        };
        for (int i = 0; i < 10; ++i)
            if (rules::uwAltered(i).level != kAltLevel[i])
                ++bad;
        if (std::string(rules::uwAltered(0).name) != "part water" ||
            std::string(rules::uwAltered(0).cls) != "cleric" ||
            std::string(rules::uwAltered(2).name)
                != "conjure earth elemental" ||
            std::string(rules::uwAltered(4).name)
                != "lightning bolt" ||
            std::string(rules::uwAltered(7).name)
                != "conjure elemental" ||
            std::string(rules::uwAltered(8).name)
                != "freezing sphere (Otiluke)" ||
            std::string(rules::uwAltered(9).name) != "part water")
            ++bad;
        // the altered-effect text, spot pinned
        if (std::string(rules::uwAltered(0).effect)
                != "tunnel through deep water, no wider than 10 feet" ||
            std::string(rules::uwAltered(3).effect)
                != "swim easily at any depth, even encumbered, speed 9 inches")
            ++bad;
        // the altered-effect numerics
        if (rules::uwPartWaterTunnelDiameterFeet() != 10)
            ++bad;
        if (rules::uwEarthquakeStunRoundsMin() != 5 ||
            rules::uwEarthquakeStunRoundsMax() != 20 ||
            !rules::uwEarthquakeSaveVsDeathMagic())
            ++bad;
        if (!rules::uwConjureEarthElementalConfinedToFloor())
            ++bad;
        if (rules::uwFlyMaxSpeedInches() != 9 ||
            rules::uwLightningBoltRadiusInches() != 2 ||
            !rules::uwLightningBoltSaveForHalf())
            ++bad;
        if (rules::uwIceStormHailDamageMin() != 1 ||
            rules::uwIceStormHailDamageMax() != 10 ||
            !rules::uwIceStormSleetNoEffect() ||
            !rules::uwWallOfIceFloatsToSurface())
            ++bad;
        if (!rules::uwConjureElementalAirOrFireImpossible() ||
            !rules::uwConjureElementalWaterFine())
            ++bad;
        if (rules::uwFreezingSphereCubicFeetPerLevel() != 50 ||
            rules::uwFreezingSphereDurationRoundsPerLevel() != 1 ||
            !rules::uwFreezingSphereCasterSuffocates())
            ++bad;
        printf("R168 underwater spell use audit: bad %d\n", bad);
        if (bad) return 1;
    }
