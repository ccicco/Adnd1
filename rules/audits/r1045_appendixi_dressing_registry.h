    // ==== R1045: appendixi dressing registry ================================
    // The R1045 de-wire: the five DMG Appendix I
    // dressing band tables (air currents 14,
    // odors 14, air 6, general items 54,
    // unexplained sounds 58; 146 bands) ride
    // items::MiscItemRegistry from
    // content/tables/appendixi/ (def keys
    // appendixi_*). This audit loads its own
    // registry instance and cross-reads every
    // band through the inline accessor surface
    // (airCurrentFor/odorFor/airStateFor/
    // generalItemFor/soundFor) and the aiView
    // seam, so the r150 audit and this registry
    // audit read the same data through the same
    // signatures.
    {
        int bad = 0;
        // -- 1. load --------------------------------------
        {
            items::MiscItemRegistry t;
            if (t.loadDirectory("content/tables/appendixi") != 5)
                ++bad;
            if (!t.errors().empty()) ++bad;
            if (t.all().size() != 5) ++bad;
            if (t.all().count("appendixi_air_currents") != 1) ++bad;
            if (t.all().count("appendixi_odors") != 1) ++bad;
            if (t.all().count("appendixi_air_states") != 1) ++bad;
            if (t.all().count("appendixi_general_items") != 1) ++bad;
            if (t.all().count("appendixi_unexplained_sounds") != 1) ++bad;
            if (t.all().count("appendixi_air")) ++bad;
            if (t.all().count("treasure_swords")) ++bad;
            if (t.all().count("weapon_chart")) ++bad;
            if (t.all().count("")) ++bad;
        }
        printf("R1045 appendixi dressing registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts ------------------------------------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/appendixi");
            const auto* v_AC_COUNT = t.find("appendixi_air_currents");
            if (!v_AC_COUNT || (int)v_AC_COUNT->rows.size() != 14) ++bad;
            if (v_AC_COUNT && ((int)v_AC_COUNT->pins.size() != 1
                       || v_AC_COUNT->pins[0].name
                              != std::string("appendixi_air_currentsRowCount")
                       || v_AC_COUNT->pins[0].value != 14)) ++bad;
            if (v_AC_COUNT && (int)v_AC_COUNT->sources.size() != 1) ++bad;
            if (dm::appendixi::AC_COUNT != (v_AC_COUNT ? (int)v_AC_COUNT->rows.size() : -1))
                ++bad;
            const auto* v_OD_COUNT = t.find("appendixi_odors");
            if (!v_OD_COUNT || (int)v_OD_COUNT->rows.size() != 14) ++bad;
            if (v_OD_COUNT && ((int)v_OD_COUNT->pins.size() != 1
                       || v_OD_COUNT->pins[0].name
                              != std::string("appendixi_odorsRowCount")
                       || v_OD_COUNT->pins[0].value != 14)) ++bad;
            if (v_OD_COUNT && (int)v_OD_COUNT->sources.size() != 1) ++bad;
            if (dm::appendixi::OD_COUNT != (v_OD_COUNT ? (int)v_OD_COUNT->rows.size() : -1))
                ++bad;
            const auto* v_AIR_COUNT = t.find("appendixi_air_states");
            if (!v_AIR_COUNT || (int)v_AIR_COUNT->rows.size() != 6) ++bad;
            if (v_AIR_COUNT && ((int)v_AIR_COUNT->pins.size() != 1
                       || v_AIR_COUNT->pins[0].name
                              != std::string("appendixi_air_statesRowCount")
                       || v_AIR_COUNT->pins[0].value != 6)) ++bad;
            if (v_AIR_COUNT && (int)v_AIR_COUNT->sources.size() != 1) ++bad;
            if (dm::appendixi::AIR_COUNT != (v_AIR_COUNT ? (int)v_AIR_COUNT->rows.size() : -1))
                ++bad;
            const auto* v_GI_COUNT = t.find("appendixi_general_items");
            if (!v_GI_COUNT || (int)v_GI_COUNT->rows.size() != 54) ++bad;
            if (v_GI_COUNT && ((int)v_GI_COUNT->pins.size() != 1
                       || v_GI_COUNT->pins[0].name
                              != std::string("appendixi_general_itemsRowCount")
                       || v_GI_COUNT->pins[0].value != 54)) ++bad;
            if (v_GI_COUNT && (int)v_GI_COUNT->sources.size() != 1) ++bad;
            if (dm::appendixi::GI_COUNT != (v_GI_COUNT ? (int)v_GI_COUNT->rows.size() : -1))
                ++bad;
            const auto* v_SK_COUNT = t.find("appendixi_unexplained_sounds");
            if (!v_SK_COUNT || (int)v_SK_COUNT->rows.size() != 58) ++bad;
            if (v_SK_COUNT && ((int)v_SK_COUNT->pins.size() != 1
                       || v_SK_COUNT->pins[0].name
                              != std::string("appendixi_unexplained_soundsRowCount")
                       || v_SK_COUNT->pins[0].value != 58)) ++bad;
            if (v_SK_COUNT && (int)v_SK_COUNT->sources.size() != 1) ++bad;
            if (dm::appendixi::SK_COUNT != (v_SK_COUNT ? (int)v_SK_COUNT->rows.size() : -1))
                ++bad;
        }
        printf("R1045 appendixi dressing registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. bands (the percentile axis) ---------------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/appendixi");
            for (const auto& kv : t.all()) {
                const auto& d = kv.second;
                int prevHi = 0;
                for (const auto& r : d.rows) {
                    if (r.bandLo != prevHi + 1
                        || r.bandHi < r.bandLo
                        || r.bandHi > 100
                        || r.set != d.key
                        || r.name.empty()
                        || r.gp != 0
                        || r.gpHi != 0
                        || r.xp != 0
                        || r.xpHi != 0
                        || r.qtyLo != 0
                        || r.qtyHi != 0) ++bad;
                    prevHi = r.bandHi;
                }
                if (prevHi != 100) ++bad;   // last band is 00
            }
        }
        printf("R1045 appendixi dressing registry bands audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. data (famous pins, all computed) ----------
        {
            namespace AI = dm::appendixi;
            if (AI::airCurrentFor(1) != AI::AC_BREEZE_SLIGHT) ++bad;
            if (AI::airCurrentFor(5) != AI::AC_BREEZE_SLIGHT) ++bad;
            if (AI::airCurrentFor(6) != AI::AC_BREEZE_SLIGHT_DAMP) ++bad;
            if (AI::airCurrentFor(70) != AI::AC_STILL_VERY_CHILL
                || AI::airCurrentFor(75) != AI::AC_STILL_VERY_CHILL) ++bad;
            if (AI::airCurrentFor(96) != AI::AC_WIND_STRONG_MOANING
                || AI::airCurrentFor(100) != AI::AC_WIND_STRONG_MOANING) ++bad;
            if (AI::aiView("appendixi_air_currents")[7].name
                    != std::string("AC_STILL_VERY_CHILL")) ++bad;
            if (AI::odorFor(1) != AI::OD_ACRID) ++bad;
            if (AI::odorFor(3) != AI::OD_ACRID) ++bad;
            if (AI::odorFor(4) != AI::OD_CHLORINE) ++bad;
            if (AI::odorFor(66) != AI::OD_PUTRID
                || AI::odorFor(70) != AI::OD_PUTRID) ++bad;
            if (AI::odorFor(96) != AI::OD_URINE
                || AI::odorFor(100) != AI::OD_URINE) ++bad;
            if (AI::aiView("appendixi_odors")[7].name
                    != std::string("OD_PUTRID")) ++bad;
            if (AI::airStateFor(1) != AI::AIR_CLEAR) ++bad;
            if (AI::airStateFor(70) != AI::AIR_CLEAR) ++bad;
            if (AI::airStateFor(71) != AI::AIR_FOGGY) ++bad;
            if (AI::airStateFor(89) != AI::AIR_HAZY_DUST
                || AI::airStateFor(90) != AI::AIR_HAZY_DUST) ++bad;
            if (AI::airStateFor(99) != AI::AIR_MISTED
                || AI::airStateFor(100) != AI::AIR_MISTED) ++bad;
            if (AI::aiView("appendixi_air_states")[3].name
                    != std::string("AIR_HAZY_DUST")) ++bad;
            if (AI::generalItemFor(1) != AI::GI_ARROW_BROKEN) ++bad;
            if (AI::generalItemFor(1) != AI::GI_ARROW_BROKEN) ++bad;
            if (AI::generalItemFor(2) != AI::GI_ASHES) ++bad;
            if (AI::generalItemFor(61) != AI::GI_LEATHER_BOOT
                || AI::generalItemFor(61) != AI::GI_LEATHER_BOOT) ++bad;
            if (AI::generalItemFor(98) != AI::GI_WOOD_PIECES_ROTTING
                || AI::generalItemFor(100) != AI::GI_WOOD_PIECES_ROTTING) ++bad;
            if (AI::aiView("appendixi_general_items")[27].name
                    != std::string("GI_LEATHER_BOOT")) ++bad;
            if (AI::soundFor(1) != AI::SK_BANG_SLAM) ++bad;
            if (AI::soundFor(5) != AI::SK_BANG_SLAM) ++bad;
            if (AI::soundFor(6) != AI::SK_BELLOW) ++bad;
            if (AI::soundFor(50) != AI::SK_KNOCKING
                || AI::soundFor(53) != AI::SK_KNOCKING) ++bad;
            if (AI::soundFor(99) != AI::SK_WHISTLING
                || AI::soundFor(100) != AI::SK_WHISTLING) ++bad;
            if (AI::aiView("appendixi_unexplained_sounds")[29].name
                    != std::string("SK_KNOCKING")) ++bad;
        }
        printf("R1045 appendixi dressing registry data audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. rows (the full band cross-read) -----------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/appendixi");
            const auto* v_AC_COUNT = t.find("appendixi_air_currents");
            if (!v_AC_COUNT) { ++bad; } else {
                static const char* const k1045_AC_COUNT[] = {
                    "AC_BREEZE_SLIGHT", "AC_BREEZE_SLIGHT_DAMP", "AC_BREEZE_GUSTING",
                    "AC_COLD_CURRENT", "AC_DOWNDRAFT_SLIGHT", "AC_DOWNDRAFT_STRONG",
                    "AC_STILL", "AC_STILL_VERY_CHILL", "AC_STILL_WARM",
                    "AC_UPDRAFT_SLIGHT", "AC_UPDRAFT_STRONG", "AC_WIND_STRONG",
                    "AC_WIND_STRONG_GUSTING", "AC_WIND_STRONG_MOANING",
                };
                if ((int)(sizeof(k1045_AC_COUNT) / sizeof(k1045_AC_COUNT[0]))
                        != (int)v_AC_COUNT->rows.size()) ++bad;
                for (int i = 0; i < (int)v_AC_COUNT->rows.size(); ++i)
                    if (v_AC_COUNT->rows[i].name
                            != std::string(k1045_AC_COUNT[i])) ++bad;
                for (int r = 1; r <= 100; ++r) {
                    int want = 0;
                    for (int i = 0;
                         i < (int)v_AC_COUNT->rows.size(); ++i) {
                        if (r <= v_AC_COUNT->rows[i].bandHi) {
                            want = i;
                            break;
                        }
                    }
                    if (dm::appendixi::airCurrentFor(r) != want) ++bad;
                }
            }
            const auto* v_OD_COUNT = t.find("appendixi_odors");
            if (!v_OD_COUNT) { ++bad; } else {
                static const char* const k1045_OD_COUNT[] = {
                    "OD_ACRID", "OD_CHLORINE", "OD_DANK_MOULDY",
                    "OD_EARTHY", "OD_MANURE", "OD_METALLIC",
                    "OD_OZONE", "OD_PUTRID", "OD_ROTTING_VEGETATION",
                    "OD_SALTY_WET", "OD_SMOKY", "OD_STALE_FETID",
                    "OD_SULPHUROUS", "OD_URINE",
                };
                if ((int)(sizeof(k1045_OD_COUNT) / sizeof(k1045_OD_COUNT[0]))
                        != (int)v_OD_COUNT->rows.size()) ++bad;
                for (int i = 0; i < (int)v_OD_COUNT->rows.size(); ++i)
                    if (v_OD_COUNT->rows[i].name
                            != std::string(k1045_OD_COUNT[i])) ++bad;
                for (int r = 1; r <= 100; ++r) {
                    int want = 0;
                    for (int i = 0;
                         i < (int)v_OD_COUNT->rows.size(); ++i) {
                        if (r <= v_OD_COUNT->rows[i].bandHi) {
                            want = i;
                            break;
                        }
                    }
                    if (dm::appendixi::odorFor(r) != want) ++bad;
                }
            }
            const auto* v_AIR_COUNT = t.find("appendixi_air_states");
            if (!v_AIR_COUNT) { ++bad; } else {
                static const char* const k1045_AIR_COUNT[] = {
                    "AIR_CLEAR", "AIR_FOGGY", "AIR_FOGGY_NEAR_FLOOR",
                    "AIR_HAZY_DUST", "AIR_HAZY_SMOKE", "AIR_MISTED",
                };
                if ((int)(sizeof(k1045_AIR_COUNT) / sizeof(k1045_AIR_COUNT[0]))
                        != (int)v_AIR_COUNT->rows.size()) ++bad;
                for (int i = 0; i < (int)v_AIR_COUNT->rows.size(); ++i)
                    if (v_AIR_COUNT->rows[i].name
                            != std::string(k1045_AIR_COUNT[i])) ++bad;
                for (int r = 1; r <= 100; ++r) {
                    int want = 0;
                    for (int i = 0;
                         i < (int)v_AIR_COUNT->rows.size(); ++i) {
                        if (r <= v_AIR_COUNT->rows[i].bandHi) {
                            want = i;
                            break;
                        }
                    }
                    if (dm::appendixi::airStateFor(r) != want) ++bad;
                }
            }
            const auto* v_GI_COUNT = t.find("appendixi_general_items");
            if (!v_GI_COUNT) { ++bad; } else {
                static const char* const k1045_GI_COUNT[] = {
                    "GI_ARROW_BROKEN", "GI_ASHES", "GI_BONES",
                    "GI_BOTTLE_BROKEN", "GI_CHAIN_CORRODED", "GI_CLUB_SPLINTERED",
                    "GI_COBWEBS", "GI_COIN_COPPER_BENT", "GI_CRACKS_CEILING",
                    "GI_CRACKS_FLOOR", "GI_CRACKS_WALL", "GI_DAGGER_HILT",
                    "GI_DAMPNESS_CEILING", "GI_DAMPNESS_WALL", "GI_DRIPPING",
                    "GI_DRIED_BLOOD", "GI_DUNG", "GI_DUST",
                    "GI_FLASK_CRACKED", "GI_FOOD_SCRAPS", "GI_FUNGI_COMMON",
                    "GI_GUANO", "GI_HAIR_FUR_BITS", "GI_HAMMER_HEAD_CRACKED",
                    "GI_HELMET_DENTED", "GI_IRON_BAR_BENT", "GI_JAVELIN_HEAD_BLUNT",
                    "GI_LEATHER_BOOT", "GI_LEAVES_TWIGS", "GI_MOLD",
                    "GI_PICK_HANDLE", "GI_POLE_BROKEN", "GI_POTTERY_SHARDS",
                    "GI_RAGS", "GI_ROPE_ROTTEN", "GI_RUBBLE_DIRT",
                    "GI_SACK_TORN", "GI_SLIMY_CEILING", "GI_SLIMY_FLOOR",
                    "GI_SLIMY_WALL", "GI_SPIKE_RUSTED", "GI_STICKS",
                    "GI_STONES_SMALL", "GI_STRAW", "GI_SWORD_BLADE_BROKEN",
                    "GI_TEETH_SCATTERED", "GI_TORCH_STUB", "GI_WALL_SCRATCHINGS",
                    "GI_WATER_SMALL_PUDDLE", "GI_WATER_LARGE_PUDDLE", "GI_WATER_TRICKLE",
                    "GI_WAX_DRIPPINGS", "GI_WAX_BLOB", "GI_WOOD_PIECES_ROTTING",
                };
                if ((int)(sizeof(k1045_GI_COUNT) / sizeof(k1045_GI_COUNT[0]))
                        != (int)v_GI_COUNT->rows.size()) ++bad;
                for (int i = 0; i < (int)v_GI_COUNT->rows.size(); ++i)
                    if (v_GI_COUNT->rows[i].name
                            != std::string(k1045_GI_COUNT[i])) ++bad;
                for (int r = 1; r <= 100; ++r) {
                    int want = 0;
                    for (int i = 0;
                         i < (int)v_GI_COUNT->rows.size(); ++i) {
                        if (r <= v_GI_COUNT->rows[i].bandHi) {
                            want = i;
                            break;
                        }
                    }
                    if (dm::appendixi::generalItemFor(r) != want) ++bad;
                }
            }
            const auto* v_SK_COUNT = t.find("appendixi_unexplained_sounds");
            if (!v_SK_COUNT) { ++bad; } else {
                static const char* const k1045_SK_COUNT[] = {
                    "SK_BANG_SLAM", "SK_BELLOW", "SK_BONG",
                    "SK_BUZZING", "SK_CHANTING", "SK_CHIMING",
                    "SK_CHIRPING", "SK_CLANKING", "SK_CLASHING",
                    "SK_CLICKING", "SK_COUGHING", "SK_CREAKING",
                    "SK_DRUMMING", "SK_FOOTSTEPS_AHEAD", "SK_FOOTSTEPS_APPROACHING",
                    "SK_FOOTSTEPS_BEHIND", "SK_FOOTSTEPS_RECEDING", "SK_FOOTSTEPS_SIDE",
                    "SK_GIGGLING", "SK_GONG", "SK_GRATING",
                    "SK_GROANING", "SK_GRUNTING", "SK_HISSING",
                    "SK_HOOTING", "SK_HORN", "SK_HOWLING",
                    "SK_HUMMING", "SK_JINGLING", "SK_KNOCKING",
                    "SK_LAUGHTER", "SK_MOANING", "SK_MURMURING",
                    "SK_MUSIC", "SK_RATTLING", "SK_RINGING",
                    "SK_ROAR", "SK_RUSTLING", "SK_SCRATCHING",
                    "SK_SCREAMING", "SK_SCUTTLING", "SK_SHUFFLING",
                    "SK_SLITHERING", "SK_SNAPPING", "SK_SNEEZING",
                    "SK_SOBBING", "SK_SPLASHING", "SK_SPLINTERING",
                    "SK_SQUEAKING", "SK_SQUEALING", "SK_TAPPING",
                    "SK_THUD", "SK_THUMPING", "SK_TINKLING",
                    "SK_TWANGING", "SK_WHINING", "SK_WHISPERING",
                    "SK_WHISTLING",
                };
                if ((int)(sizeof(k1045_SK_COUNT) / sizeof(k1045_SK_COUNT[0]))
                        != (int)v_SK_COUNT->rows.size()) ++bad;
                for (int i = 0; i < (int)v_SK_COUNT->rows.size(); ++i)
                    if (v_SK_COUNT->rows[i].name
                            != std::string(k1045_SK_COUNT[i])) ++bad;
                for (int r = 1; r <= 100; ++r) {
                    int want = 0;
                    for (int i = 0;
                         i < (int)v_SK_COUNT->rows.size(); ++i) {
                        if (r <= v_SK_COUNT->rows[i].bandHi) {
                            want = i;
                            break;
                        }
                    }
                    if (dm::appendixi::soundFor(r) != want) ++bad;
                }
            }
        }
        printf("R1045 appendixi dressing registry rows audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. edges (folds, clamps, negatives) -----------
        {
            namespace AI = dm::appendixi;
            if (AI::airCurrentFor(0) != AI::AC_WIND_STRONG_MOANING) ++bad;
            if (AI::airCurrentFor(-5) != AI::AC_WIND_STRONG_MOANING) ++bad;
            if (AI::airCurrentFor(101) != AI::AC_WIND_STRONG_MOANING) ++bad;
            if (AI::airCurrentFor(999) != AI::AC_WIND_STRONG_MOANING) ++bad;
            if (AI::odorFor(0) != AI::OD_URINE) ++bad;
            if (AI::odorFor(-5) != AI::OD_URINE) ++bad;
            if (AI::odorFor(101) != AI::OD_URINE) ++bad;
            if (AI::odorFor(999) != AI::OD_URINE) ++bad;
            if (AI::airStateFor(0) != AI::AIR_MISTED) ++bad;
            if (AI::airStateFor(-5) != AI::AIR_MISTED) ++bad;
            if (AI::airStateFor(101) != AI::AIR_MISTED) ++bad;
            if (AI::airStateFor(999) != AI::AIR_MISTED) ++bad;
            if (AI::generalItemFor(0) != AI::GI_WOOD_PIECES_ROTTING) ++bad;
            if (AI::generalItemFor(-5) != AI::GI_WOOD_PIECES_ROTTING) ++bad;
            if (AI::generalItemFor(101) != AI::GI_WOOD_PIECES_ROTTING) ++bad;
            if (AI::generalItemFor(999) != AI::GI_WOOD_PIECES_ROTTING) ++bad;
            if (AI::soundFor(0) != AI::SK_WHISTLING) ++bad;
            if (AI::soundFor(-5) != AI::SK_WHISTLING) ++bad;
            if (AI::soundFor(101) != AI::SK_WHISTLING) ++bad;
            if (AI::soundFor(999) != AI::SK_WHISTLING) ++bad;
            if (!dm::appendixi::aiView("appendixi_air").empty())
                ++bad;
            if (!dm::appendixi::aiView("no_such_table").empty())
                ++bad;
            if (dm::appendixi::aiReg().find("treasure_swords")
                    != nullptr) ++bad;
            if (dm::appendixi::aiReg().find("") != nullptr) ++bad;
        }
        printf("R1045 appendixi dressing registry edges audit: bad %d\n", bad);
    }
