    // ---- R168: underwater spell use audit ------------
    // DMG p.57: the general limits, the two printed
    // spell lists (cannot-cast by class and level,
    // altered effects) and the altered numerics.
    {
        Uwspells uwspells;
        int bad = 0;
        // the general paragraph
        if (!uwspells.uwSpellRangesAsDungeons() ||
            !uwspells.uwFireSpellsFailExceptInAiryWater() ||
            !uwspells.uwElectricalSpellsConductedToArea() ||
            !uwspells.uwMaterialComponentsAltered())
            ++bad;
        // the cannot-cast list: 41 entries
        // (9 cleric, 22 druid, 10 magic-user)
        if (uwspells.uwCannotCastCount() != 41) ++bad;
        if (uwspells.uwCannotCastClassCount("cleric") != 9 ||
            uwspells.uwCannotCastClassCount("druid") != 22 ||
            uwspells.uwCannotCastClassCount("magic-user") != 10)
            ++bad;
        // 11 entries carry the printed asterisk mark
        {
            Uwspells uwspells;
            int marks = 0;
            for (int i = 0; i < uwspells.uwCannotCastCount();
                 ++i)
                if (uwspells.uwCannotCast(i).printedMark) ++marks;
            if (marks != 11) ++bad;
        }
        // spot the rows: first and last of each class
        if (std::string(uwspells.uwCannotCast(0).cls) != "cleric" ||
            uwspells.uwCannotCast(0).level != 3 ||
            std::string(uwspells.uwCannotCast(0).name)
                != "speak with dead" ||
            !uwspells.uwCannotCast(0).printedMark)
            ++bad;
        if (std::string(uwspells.uwCannotCast(8).cls) != "cleric" ||
            uwspells.uwCannotCast(8).level != 7 ||
            std::string(uwspells.uwCannotCast(8).name)
                != "wind walk")
            ++bad;
        if (std::string(uwspells.uwCannotCast(9).cls) != "druid" ||
            uwspells.uwCannotCast(9).level != 1 ||
            std::string(uwspells.uwCannotCast(9).name)
                != "predict weather")
            ++bad;
        if (std::string(uwspells.uwCannotCast(30).cls) != "druid" ||
            uwspells.uwCannotCast(30).level != 7 ||
            std::string(uwspells.uwCannotCast(30).name)
                != "fire storm")
            ++bad;
        if (std::string(uwspells.uwCannotCast(31).cls)
                != "magic-user" ||
            uwspells.uwCannotCast(31).level != 1 ||
            std::string(uwspells.uwCannotCast(31).name)
                != "affect normal fires" ||
            !uwspells.uwCannotCast(31).printedMark)
            ++bad;
        if (std::string(uwspells.uwCannotCast(40).cls)
                != "magic-user" ||
            uwspells.uwCannotCast(40).level != 4 ||
            std::string(uwspells.uwCannotCast(40).name)
                != "fire trap")
            ++bad;
        // the middle rows: cleric atonement and
        // flame strike, druid produce fire
        if (std::string(uwspells.uwCannotCast(3).name)
                != "atonement" ||
            std::string(uwspells.uwCannotCast(4).name)
                != "flame strike" ||
            std::string(uwspells.uwCannotCast(17).name)
                != "produce fire" ||
            uwspells.uwCannotCast(17).level != 4)
            ++bad;
        // the membership probe, both ways
        if (!uwspells.uwIsCannotCast("cleric", 5, "flame strike") ||
            !uwspells.uwIsCannotCast("druid", 2, "produce flame") ||
            !uwspells.uwIsCannotCast("magic-user", 3, "fireball"))
            ++bad;
        if (uwspells.uwIsCannotCast("cleric", 1, "cure light wounds") ||
            uwspells.uwIsCannotCast("magic-user", 3, "fly") ||
            uwspells.uwIsCannotCast("druid", 4, "plant growth"))
            ++bad;
        // the printed reverse/shield notes
        if (!uwspells.uwHeatMetalReverseChillWorks() ||
            !uwspells.uwFireShieldColdFlameWorks())
            ++bad;
        // the altered-effects list: 10 entries
        // (2 cleric, 1 druid, 7 magic-user)
        if (uwspells.uwAlteredCount() != 10) ++bad;
        {
            int cl = 0, dr = 0, mu = 0;
            for (int i = 0; i < 10; ++i) {
                Uwspells uwspells;
                std::string c = uwspells.uwAltered(i).cls;
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
            if (uwspells.uwAltered(i).level != kAltLevel[i])
                ++bad;
        if (std::string(uwspells.uwAltered(0).name) != "part water" ||
            std::string(uwspells.uwAltered(0).cls) != "cleric" ||
            std::string(uwspells.uwAltered(2).name)
                != "conjure earth elemental" ||
            std::string(uwspells.uwAltered(4).name)
                != "lightning bolt" ||
            std::string(uwspells.uwAltered(7).name)
                != "conjure elemental" ||
            std::string(uwspells.uwAltered(8).name)
                != "freezing sphere (Otiluke)" ||
            std::string(uwspells.uwAltered(9).name) != "part water")
            ++bad;
        // the altered-effect text, spot pinned
        if (std::string(uwspells.uwAltered(0).effect)
                != "tunnel through deep water, no wider than 10 feet" ||
            std::string(uwspells.uwAltered(3).effect)
                != "swim easily at any depth, even encumbered, speed 9 inches")
            ++bad;
        // the altered-effect numerics
        if (uwspells.uwPartWaterTunnelDiameterFeet() != 10)
            ++bad;
        if (uwspells.uwEarthquakeStunRoundsMin() != 5 ||
            uwspells.uwEarthquakeStunRoundsMax() != 20 ||
            !uwspells.uwEarthquakeSaveVsDeathMagic())
            ++bad;
        if (!uwspells.uwConjureEarthElementalConfinedToFloor())
            ++bad;
        if (uwspells.uwFlyMaxSpeedInches() != 9 ||
            uwspells.uwLightningBoltRadiusInches() != 2 ||
            !uwspells.uwLightningBoltSaveForHalf())
            ++bad;
        if (uwspells.uwIceStormHailDamageMin() != 1 ||
            uwspells.uwIceStormHailDamageMax() != 10 ||
            !uwspells.uwIceStormSleetNoEffect() ||
            !uwspells.uwWallOfIceFloatsToSurface())
            ++bad;
        if (!uwspells.uwConjureElementalAirOrFireImpossible() ||
            !uwspells.uwConjureElementalWaterFine())
            ++bad;
        if (uwspells.uwFreezingSphereCubicFeetPerLevel() != 50 ||
            uwspells.uwFreezingSphereDurationRoundsPerLevel() != 1 ||
            !uwspells.uwFreezingSphereCasterSuffocates())
            ++bad;
        printf("R168 underwater spell use audit: bad %d\n", bad);
        if (bad) return 1;
    }
