    // ==== R1046: appendix A dressing registry ================================
    // The R1046 de-wire: the 32 DMG Appendix A
    // dungeon dressing band tables (224 printed
    // bands, d20 with one d%) ride
    // items::MiscItemRegistry from
    // content/tables/appendixa/ (def keys
    // appendixa_*). This audit loads its own
    // registry instance and cross-reads every
    // band through the inline accessor surface
    // and the aaView seam, so the r124 audit and
    // this registry audit read the same data
    // through the same signatures.
    {
        int bad = 0;
        // -- 1. load --------------------------------------
        {
            items::MiscItemRegistry t;
            if (t.loadDirectory("content/tables/appendixa")
                != 32) ++bad;
            if (!t.errors().empty()) ++bad;
            if (t.all().size() != 32) ++bad;
            if (t.all().count("appendixa_periodic_check") != 1) ++bad;
            if (t.all().count("appendixa_door_location") != 1) ++bad;
            if (t.all().count("appendixa_space_beyond") != 1) ++bad;
            if (t.all().count("appendixa_side_passage") != 1) ++bad;
            if (t.all().count("appendixa_passage_width") != 1) ++bad;
            if (t.all().count("appendixa_special_passage") != 1) ++bad;
            if (t.all().count("appendixa_width")) ++bad;
            if (t.all().count("treasure_swords")) ++bad;
            if (t.all().count("")) ++bad;
        }
        printf("R1046 appendix A dressing registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts ------------------------------------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/appendixa");
            const auto* v_periodic_check = t.find("appendixa_periodic_check");
            if (!v_periodic_check || (int)v_periodic_check->rows.size() != 9)
                ++bad;
            if (v_periodic_check && ((int)v_periodic_check->pins.size() != 1
                       || v_periodic_check->pins[0].name
                              != std::string("appendixa_periodic_checkRowCount")
                       || v_periodic_check->pins[0].value != 9))
                ++bad;
            if (v_periodic_check && (int)v_periodic_check->sources.size() != 1)
                ++bad;
            const auto* v_door_location = t.find("appendixa_door_location");
            if (!v_door_location || (int)v_door_location->rows.size() != 3)
                ++bad;
            if (v_door_location && ((int)v_door_location->pins.size() != 1
                       || v_door_location->pins[0].name
                              != std::string("appendixa_door_locationRowCount")
                       || v_door_location->pins[0].value != 3))
                ++bad;
            if (v_door_location && (int)v_door_location->sources.size() != 1)
                ++bad;
            const auto* v_space_beyond = t.find("appendixa_space_beyond");
            if (!v_space_beyond || (int)v_space_beyond->rows.size() != 6)
                ++bad;
            if (v_space_beyond && ((int)v_space_beyond->pins.size() != 1
                       || v_space_beyond->pins[0].name
                              != std::string("appendixa_space_beyondRowCount")
                       || v_space_beyond->pins[0].value != 6))
                ++bad;
            if (v_space_beyond && (int)v_space_beyond->sources.size() != 1)
                ++bad;
            const auto* v_side_passage = t.find("appendixa_side_passage");
            if (!v_side_passage || (int)v_side_passage->rows.size() != 12)
                ++bad;
            if (v_side_passage && ((int)v_side_passage->pins.size() != 1
                       || v_side_passage->pins[0].name
                              != std::string("appendixa_side_passageRowCount")
                       || v_side_passage->pins[0].value != 12))
                ++bad;
            if (v_side_passage && (int)v_side_passage->sources.size() != 1)
                ++bad;
            const auto* v_passage_width = t.find("appendixa_passage_width");
            if (!v_passage_width || (int)v_passage_width->rows.size() != 5)
                ++bad;
            if (v_passage_width && ((int)v_passage_width->pins.size() != 1
                       || v_passage_width->pins[0].name
                              != std::string("appendixa_passage_widthRowCount")
                       || v_passage_width->pins[0].value != 5))
                ++bad;
            if (v_passage_width && (int)v_passage_width->sources.size() != 1)
                ++bad;
            const auto* v_special_passage = t.find("appendixa_special_passage");
            if (!v_special_passage || (int)v_special_passage->rows.size() != 9)
                ++bad;
            if (v_special_passage && ((int)v_special_passage->pins.size() != 1
                       || v_special_passage->pins[0].name
                              != std::string("appendixa_special_passageRowCount")
                       || v_special_passage->pins[0].value != 9))
                ++bad;
            if (v_special_passage && (int)v_special_passage->sources.size() != 1)
                ++bad;
            const auto* v_river_feature = t.find("appendixa_river_feature");
            if (!v_river_feature || (int)v_river_feature->rows.size() != 3)
                ++bad;
            if (v_river_feature && ((int)v_river_feature->pins.size() != 1
                       || v_river_feature->pins[0].name
                              != std::string("appendixa_river_featureRowCount")
                       || v_river_feature->pins[0].value != 3))
                ++bad;
            if (v_river_feature && (int)v_river_feature->sources.size() != 1)
                ++bad;
            const auto* v_chasm_feature = t.find("appendixa_chasm_feature");
            if (!v_chasm_feature || (int)v_chasm_feature->rows.size() != 3)
                ++bad;
            if (v_chasm_feature && ((int)v_chasm_feature->pins.size() != 1
                       || v_chasm_feature->pins[0].name
                              != std::string("appendixa_chasm_featureRowCount")
                       || v_chasm_feature->pins[0].value != 3))
                ++bad;
            if (v_chasm_feature && (int)v_chasm_feature->sources.size() != 1)
                ++bad;
            const auto* v_turn = t.find("appendixa_turn");
            if (!v_turn || (int)v_turn->rows.size() != 6)
                ++bad;
            if (v_turn && ((int)v_turn->pins.size() != 1
                       || v_turn->pins[0].name
                              != std::string("appendixa_turnRowCount")
                       || v_turn->pins[0].value != 6))
                ++bad;
            if (v_turn && (int)v_turn->sources.size() != 1)
                ++bad;
            const auto* v_chamber_shape = t.find("appendixa_chamber_shape");
            if (!v_chamber_shape || (int)v_chamber_shape->rows.size() != 7)
                ++bad;
            if (v_chamber_shape && ((int)v_chamber_shape->pins.size() != 1
                       || v_chamber_shape->pins[0].name
                              != std::string("appendixa_chamber_shapeRowCount")
                       || v_chamber_shape->pins[0].value != 7))
                ++bad;
            if (v_chamber_shape && (int)v_chamber_shape->sources.size() != 1)
                ++bad;
            const auto* v_room_shape = t.find("appendixa_room_shape");
            if (!v_room_shape || (int)v_room_shape->rows.size() != 9)
                ++bad;
            if (v_room_shape && ((int)v_room_shape->pins.size() != 1
                       || v_room_shape->pins[0].name
                              != std::string("appendixa_room_shapeRowCount")
                       || v_room_shape->pins[0].value != 9))
                ++bad;
            if (v_room_shape && (int)v_room_shape->sources.size() != 1)
                ++bad;
            const auto* v_unusual_shape = t.find("appendixa_unusual_shape");
            if (!v_unusual_shape || (int)v_unusual_shape->rows.size() != 8)
                ++bad;
            if (v_unusual_shape && ((int)v_unusual_shape->pins.size() != 1
                       || v_unusual_shape->pins[0].name
                              != std::string("appendixa_unusual_shapeRowCount")
                       || v_unusual_shape->pins[0].value != 8))
                ++bad;
            if (v_unusual_shape && (int)v_unusual_shape->sources.size() != 1)
                ++bad;
            const auto* v_circular_feature = t.find("appendixa_circular_feature");
            if (!v_circular_feature || (int)v_circular_feature->rows.size() != 4)
                ++bad;
            if (v_circular_feature && ((int)v_circular_feature->pins.size() != 1
                       || v_circular_feature->pins[0].name
                              != std::string("appendixa_circular_featureRowCount")
                       || v_circular_feature->pins[0].value != 4))
                ++bad;
            if (v_circular_feature && (int)v_circular_feature->sources.size() != 1)
                ++bad;
            const auto* v_unusual_size = t.find("appendixa_unusual_size");
            if (!v_unusual_size || (int)v_unusual_size->rows.size() != 7)
                ++bad;
            if (v_unusual_size && ((int)v_unusual_size->pins.size() != 1
                       || v_unusual_size->pins[0].name
                              != std::string("appendixa_unusual_sizeRowCount")
                       || v_unusual_size->pins[0].value != 7))
                ++bad;
            if (v_unusual_size && (int)v_unusual_size->sources.size() != 1)
                ++bad;
            const auto* v_exits = t.find("appendixa_exits");
            if (!v_exits || (int)v_exits->rows.size() != 7)
                ++bad;
            if (v_exits && ((int)v_exits->pins.size() != 1
                       || v_exits->pins[0].name
                              != std::string("appendixa_exitsRowCount")
                       || v_exits->pins[0].value != 7))
                ++bad;
            if (v_exits && (int)v_exits->sources.size() != 1)
                ++bad;
            const auto* v_exit_location = t.find("appendixa_exit_location");
            if (!v_exit_location || (int)v_exit_location->rows.size() != 4)
                ++bad;
            if (v_exit_location && ((int)v_exit_location->pins.size() != 1
                       || v_exit_location->pins[0].name
                              != std::string("appendixa_exit_locationRowCount")
                       || v_exit_location->pins[0].value != 4))
                ++bad;
            if (v_exit_location && (int)v_exit_location->sources.size() != 1)
                ++bad;
            const auto* v_exit_direction = t.find("appendixa_exit_direction");
            if (!v_exit_direction || (int)v_exit_direction->rows.size() != 3)
                ++bad;
            if (v_exit_direction && ((int)v_exit_direction->pins.size() != 1
                       || v_exit_direction->pins[0].name
                              != std::string("appendixa_exit_directionRowCount")
                       || v_exit_direction->pins[0].value != 3))
                ++bad;
            if (v_exit_direction && (int)v_exit_direction->sources.size() != 1)
                ++bad;
            const auto* v_room_contents = t.find("appendixa_room_contents");
            if (!v_room_contents || (int)v_room_contents->rows.size() != 6)
                ++bad;
            if (v_room_contents && ((int)v_room_contents->pins.size() != 1
                       || v_room_contents->pins[0].name
                              != std::string("appendixa_room_contentsRowCount")
                       || v_room_contents->pins[0].value != 6))
                ++bad;
            if (v_room_contents && (int)v_room_contents->sources.size() != 1)
                ++bad;
            const auto* v_stairway_variant = t.find("appendixa_stairway_variant");
            if (!v_stairway_variant || (int)v_stairway_variant->rows.size() != 5)
                ++bad;
            if (v_stairway_variant && ((int)v_stairway_variant->pins.size() != 1
                       || v_stairway_variant->pins[0].name
                              != std::string("appendixa_stairway_variantRowCount")
                       || v_stairway_variant->pins[0].value != 5))
                ++bad;
            if (v_stairway_variant && (int)v_stairway_variant->sources.size() != 1)
                ++bad;
            const auto* v_treasure = t.find("appendixa_treasure");
            if (!v_treasure || (int)v_treasure->rows.size() != 8)
                ++bad;
            if (v_treasure && ((int)v_treasure->pins.size() != 1
                       || v_treasure->pins[0].name
                              != std::string("appendixa_treasureRowCount")
                       || v_treasure->pins[0].value != 8))
                ++bad;
            if (v_treasure && (int)v_treasure->sources.size() != 1)
                ++bad;
            const auto* v_container = t.find("appendixa_container");
            if (!v_container || (int)v_container->rows.size() != 10)
                ++bad;
            if (v_container && ((int)v_container->pins.size() != 1
                       || v_container->pins[0].name
                              != std::string("appendixa_containerRowCount")
                       || v_container->pins[0].value != 10))
                ++bad;
            if (v_container && (int)v_container->sources.size() != 1)
                ++bad;
            const auto* v_guard = t.find("appendixa_guard");
            if (!v_guard || (int)v_guard->rows.size() != 16)
                ++bad;
            if (v_guard && ((int)v_guard->pins.size() != 1
                       || v_guard->pins[0].name
                              != std::string("appendixa_guardRowCount")
                       || v_guard->pins[0].value != 16))
                ++bad;
            if (v_guard && (int)v_guard->sources.size() != 1)
                ++bad;
            const auto* v_hidden = t.find("appendixa_hidden");
            if (!v_hidden || (int)v_hidden->rows.size() != 10)
                ++bad;
            if (v_hidden && ((int)v_hidden->pins.size() != 1
                       || v_hidden->pins[0].name
                              != std::string("appendixa_hiddenRowCount")
                       || v_hidden->pins[0].value != 10))
                ++bad;
            if (v_hidden && (int)v_hidden->sources.size() != 1)
                ++bad;
            const auto* v_stairs = t.find("appendixa_stairs");
            if (!v_stairs || (int)v_stairs->rows.size() != 12)
                ++bad;
            if (v_stairs && ((int)v_stairs->pins.size() != 1
                       || v_stairs->pins[0].name
                              != std::string("appendixa_stairsRowCount")
                       || v_stairs->pins[0].value != 12))
                ++bad;
            if (v_stairs && (int)v_stairs->sources.size() != 1)
                ++bad;
            const auto* v_trick_trap = t.find("appendixa_trick_trap");
            if (!v_trick_trap || (int)v_trick_trap->rows.size() != 15)
                ++bad;
            if (v_trick_trap && ((int)v_trick_trap->pins.size() != 1
                       || v_trick_trap->pins[0].name
                              != std::string("appendixa_trick_trapRowCount")
                       || v_trick_trap->pins[0].value != 15))
                ++bad;
            if (v_trick_trap && (int)v_trick_trap->sources.size() != 1)
                ++bad;
            const auto* v_gas = t.find("appendixa_gas");
            if (!v_gas || (int)v_gas->rows.size() != 7)
                ++bad;
            if (v_gas && ((int)v_gas->pins.size() != 1
                       || v_gas->pins[0].name
                              != std::string("appendixa_gasRowCount")
                       || v_gas->pins[0].value != 7))
                ++bad;
            if (v_gas && (int)v_gas->sources.size() != 1)
                ++bad;
            const auto* v_cave = t.find("appendixa_cave");
            if (!v_cave || (int)v_cave->rows.size() != 8)
                ++bad;
            if (v_cave && ((int)v_cave->pins.size() != 1
                       || v_cave->pins[0].name
                              != std::string("appendixa_caveRowCount")
                       || v_cave->pins[0].value != 8))
                ++bad;
            if (v_cave && (int)v_cave->sources.size() != 1)
                ++bad;
            const auto* v_pool = t.find("appendixa_pool");
            if (!v_pool || (int)v_pool->rows.size() != 5)
                ++bad;
            if (v_pool && ((int)v_pool->pins.size() != 1
                       || v_pool->pins[0].name
                              != std::string("appendixa_poolRowCount")
                       || v_pool->pins[0].value != 5))
                ++bad;
            if (v_pool && (int)v_pool->sources.size() != 1)
                ++bad;
            const auto* v_lake = t.find("appendixa_lake");
            if (!v_lake || (int)v_lake->rows.size() != 4)
                ++bad;
            if (v_lake && ((int)v_lake->pins.size() != 1
                       || v_lake->pins[0].name
                              != std::string("appendixa_lakeRowCount")
                       || v_lake->pins[0].value != 4))
                ++bad;
            if (v_lake && (int)v_lake->sources.size() != 1)
                ++bad;
            const auto* v_magic_pool = t.find("appendixa_magic_pool");
            if (!v_magic_pool || (int)v_magic_pool->rows.size() != 4)
                ++bad;
            if (v_magic_pool && ((int)v_magic_pool->pins.size() != 1
                       || v_magic_pool->pins[0].name
                              != std::string("appendixa_magic_poolRowCount")
                       || v_magic_pool->pins[0].value != 4))
                ++bad;
            if (v_magic_pool && (int)v_magic_pool->sources.size() != 1)
                ++bad;
            const auto* v_talking_pool_alignment = t.find("appendixa_talking_pool_alignment");
            if (!v_talking_pool_alignment || (int)v_talking_pool_alignment->rows.size() != 5)
                ++bad;
            if (v_talking_pool_alignment && ((int)v_talking_pool_alignment->pins.size() != 1
                       || v_talking_pool_alignment->pins[0].name
                              != std::string("appendixa_talking_pool_alignmentRowCount")
                       || v_talking_pool_alignment->pins[0].value != 5))
                ++bad;
            if (v_talking_pool_alignment && (int)v_talking_pool_alignment->sources.size() != 1)
                ++bad;
            const auto* v_transport_dest = t.find("appendixa_transport_dest");
            if (!v_transport_dest || (int)v_transport_dest->rows.size() != 4)
                ++bad;
            if (v_transport_dest && ((int)v_transport_dest->pins.size() != 1
                       || v_transport_dest->pins[0].name
                              != std::string("appendixa_transport_destRowCount")
                       || v_transport_dest->pins[0].value != 4))
                ++bad;
            if (v_transport_dest && (int)v_transport_dest->sources.size() != 1)
                ++bad;
        }
        printf("R1046 appendix A dressing registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. bands (the roll axis) ---------------------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/appendixa");
            for (const auto& kv : t.all()) {
                const auto& d = kv.second;
                int prevHi = 0;
                for (const auto& r : d.rows) {
                    if (r.bandLo != prevHi + 1
                        || r.bandHi < r.bandLo
                        || r.bandHi > 100
                        || r.set != d.key
                        || r.name.empty()) ++bad;
                    prevHi = r.bandHi;
                }
            }
            const auto* v_periodic_check = t.find("appendixa_periodic_check");
            if (!v_periodic_check || v_periodic_check->rows.empty()
                || v_periodic_check->rows.back().bandHi != 20)
                ++bad;
            const auto* v_door_location = t.find("appendixa_door_location");
            if (!v_door_location || v_door_location->rows.empty()
                || v_door_location->rows.back().bandHi != 20)
                ++bad;
            const auto* v_space_beyond = t.find("appendixa_space_beyond");
            if (!v_space_beyond || v_space_beyond->rows.empty()
                || v_space_beyond->rows.back().bandHi != 20)
                ++bad;
            const auto* v_side_passage = t.find("appendixa_side_passage");
            if (!v_side_passage || v_side_passage->rows.empty()
                || v_side_passage->rows.back().bandHi != 20)
                ++bad;
            const auto* v_passage_width = t.find("appendixa_passage_width");
            if (!v_passage_width || v_passage_width->rows.empty()
                || v_passage_width->rows.back().bandHi != 20)
                ++bad;
            const auto* v_special_passage = t.find("appendixa_special_passage");
            if (!v_special_passage || v_special_passage->rows.empty()
                || v_special_passage->rows.back().bandHi != 20)
                ++bad;
            const auto* v_river_feature = t.find("appendixa_river_feature");
            if (!v_river_feature || v_river_feature->rows.empty()
                || v_river_feature->rows.back().bandHi != 20)
                ++bad;
            const auto* v_chasm_feature = t.find("appendixa_chasm_feature");
            if (!v_chasm_feature || v_chasm_feature->rows.empty()
                || v_chasm_feature->rows.back().bandHi != 20)
                ++bad;
            const auto* v_turn = t.find("appendixa_turn");
            if (!v_turn || v_turn->rows.empty()
                || v_turn->rows.back().bandHi != 20)
                ++bad;
            const auto* v_chamber_shape = t.find("appendixa_chamber_shape");
            if (!v_chamber_shape || v_chamber_shape->rows.empty()
                || v_chamber_shape->rows.back().bandHi != 20)
                ++bad;
            const auto* v_room_shape = t.find("appendixa_room_shape");
            if (!v_room_shape || v_room_shape->rows.empty()
                || v_room_shape->rows.back().bandHi != 20)
                ++bad;
            const auto* v_unusual_shape = t.find("appendixa_unusual_shape");
            if (!v_unusual_shape || v_unusual_shape->rows.empty()
                || v_unusual_shape->rows.back().bandHi != 20)
                ++bad;
            const auto* v_circular_feature = t.find("appendixa_circular_feature");
            if (!v_circular_feature || v_circular_feature->rows.empty()
                || v_circular_feature->rows.back().bandHi != 20)
                ++bad;
            const auto* v_unusual_size = t.find("appendixa_unusual_size");
            if (!v_unusual_size || v_unusual_size->rows.empty()
                || v_unusual_size->rows.back().bandHi != 20)
                ++bad;
            const auto* v_exits = t.find("appendixa_exits");
            if (!v_exits || v_exits->rows.empty()
                || v_exits->rows.back().bandHi != 20)
                ++bad;
            const auto* v_exit_location = t.find("appendixa_exit_location");
            if (!v_exit_location || v_exit_location->rows.empty()
                || v_exit_location->rows.back().bandHi != 20)
                ++bad;
            const auto* v_exit_direction = t.find("appendixa_exit_direction");
            if (!v_exit_direction || v_exit_direction->rows.empty()
                || v_exit_direction->rows.back().bandHi != 20)
                ++bad;
            const auto* v_room_contents = t.find("appendixa_room_contents");
            if (!v_room_contents || v_room_contents->rows.empty()
                || v_room_contents->rows.back().bandHi != 20)
                ++bad;
            const auto* v_stairway_variant = t.find("appendixa_stairway_variant");
            if (!v_stairway_variant || v_stairway_variant->rows.empty()
                || v_stairway_variant->rows.back().bandHi != 20)
                ++bad;
            const auto* v_treasure = t.find("appendixa_treasure");
            if (!v_treasure || v_treasure->rows.empty()
                || v_treasure->rows.back().bandHi != 100)
                ++bad;
            const auto* v_container = t.find("appendixa_container");
            if (!v_container || v_container->rows.empty()
                || v_container->rows.back().bandHi != 20)
                ++bad;
            const auto* v_guard = t.find("appendixa_guard");
            if (!v_guard || v_guard->rows.empty()
                || v_guard->rows.back().bandHi != 20)
                ++bad;
            const auto* v_hidden = t.find("appendixa_hidden");
            if (!v_hidden || v_hidden->rows.empty()
                || v_hidden->rows.back().bandHi != 20)
                ++bad;
            const auto* v_stairs = t.find("appendixa_stairs");
            if (!v_stairs || v_stairs->rows.empty()
                || v_stairs->rows.back().bandHi != 20)
                ++bad;
            const auto* v_trick_trap = t.find("appendixa_trick_trap");
            if (!v_trick_trap || v_trick_trap->rows.empty()
                || v_trick_trap->rows.back().bandHi != 20)
                ++bad;
            const auto* v_gas = t.find("appendixa_gas");
            if (!v_gas || v_gas->rows.empty()
                || v_gas->rows.back().bandHi != 20)
                ++bad;
            const auto* v_cave = t.find("appendixa_cave");
            if (!v_cave || v_cave->rows.empty()
                || v_cave->rows.back().bandHi != 20)
                ++bad;
            const auto* v_pool = t.find("appendixa_pool");
            if (!v_pool || v_pool->rows.empty()
                || v_pool->rows.back().bandHi != 20)
                ++bad;
            const auto* v_lake = t.find("appendixa_lake");
            if (!v_lake || v_lake->rows.empty()
                || v_lake->rows.back().bandHi != 20)
                ++bad;
            const auto* v_magic_pool = t.find("appendixa_magic_pool");
            if (!v_magic_pool || v_magic_pool->rows.empty()
                || v_magic_pool->rows.back().bandHi != 20)
                ++bad;
            const auto* v_talking_pool_alignment = t.find("appendixa_talking_pool_alignment");
            if (!v_talking_pool_alignment || v_talking_pool_alignment->rows.empty()
                || v_talking_pool_alignment->rows.back().bandHi != 20)
                ++bad;
            const auto* v_transport_dest = t.find("appendixa_transport_dest");
            if (!v_transport_dest || v_transport_dest->rows.empty()
                || v_transport_dest->rows.back().bandHi != 20)
                ++bad;
        }
        printf("R1046 appendix A dressing registry bands audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. data (famous pins, all computed) ----------
        {
            namespace AA = dm::appendixa;
            if (AA::passageCheckFor(1)
                != AA::PC_STRAIGHT) ++bad;
            if (AA::passageCheckFor(14)
                != AA::PC_CHAMBER) ++bad;
            if (AA::passageCheckFor(20)
                != AA::PC_WANDERER) ++bad;
            if (AA::doorLocationFor(1)
                != AA::DL_LEFT) ++bad;
            if (AA::doorLocationFor(7)
                != AA::DL_RIGHT) ++bad;
            if (AA::doorLocationFor(20)
                != AA::DL_AHEAD) ++bad;
            if (AA::spaceBeyondFor(1)
                != AA::SB_PARALLEL) ++bad;
            if (AA::spaceBeyondFor(10)
                != AA::SB_45_BEHIND) ++bad;
            if (AA::spaceBeyondFor(20)
                != AA::SB_CHAMBER) ++bad;
            if (AA::sidePassageFor(1)
                != AA::SP_L90) ++bad;
            if (AA::sidePassageFor(9)
                != AA::SP_L_CURVE) ++bad;
            if (AA::sidePassageFor(20)
                != AA::SP_X) ++bad;
            if (AA::passageWidthFeetFor(1) != 10) ++bad;
            if (AA::passageWidthFeetFor(17) != 30) ++bad;
            if (AA::passageWidthFeetFor(20) != -1) ++bad;
            if (AA::specialPassageFor(1).kind
                    != AA::SPEC_COLUMNS_CENTER
                || AA::specialPassageFor(1).widthFt
                    != 40) ++bad;
            if (AA::specialPassageFor(13).kind
                    != AA::SPEC_STREAM
                || AA::specialPassageFor(13).widthFt
                    != 10) ++bad;
            if (AA::specialPassageFor(20).kind
                    != AA::SPEC_CHASM
                || AA::specialPassageFor(20).widthFt
                    != 20) ++bad;
            if (AA::riverFeature(1)
                != AA::WF_BRIDGED) ++bad;
            if (AA::riverFeature(11)
                != AA::WF_BOAT) ++bad;
            if (AA::riverFeature(20)
                != AA::WF_OBSTACLE) ++bad;
            if (AA::chasmFeature(1)
                != AA::CF_BRIDGED) ++bad;
            if (AA::chasmFeature(11)
                != AA::CF_JUMPING) ++bad;
            if (AA::chasmFeature(20)
                != AA::CF_OBSTACLE) ++bad;
            if (AA::turnFor(1)
                != AA::T_L90) ++bad;
            if (AA::turnFor(11)
                != AA::T_R90) ++bad;
            if (AA::turnFor(20)
                != AA::T_R45_BEHIND) ++bad;
            { AA::SpaceShape s;
              AA::chamberShapeFor(1, s);
              if (s.wFt != 20
                  || s.hFt != 20
                  || s.unusual
                     != false) ++bad; }
            { AA::SpaceShape s;
              AA::chamberShapeFor(9, s);
              if (s.wFt != 20
                  || s.hFt != 30
                  || s.unusual
                     != false) ++bad; }
            { AA::SpaceShape s;
              AA::chamberShapeFor(20, s);
              if (s.wFt != 0
                  || s.hFt != 0
                  || s.unusual
                     != true) ++bad; }
            { AA::SpaceShape s;
              AA::roomShapeFor(1, s);
              if (s.wFt != 10
                  || s.hFt != 10
                  || s.unusual
                     != false) ++bad; }
            { AA::SpaceShape s;
              AA::roomShapeFor(9, s);
              if (s.wFt != 10
                  || s.hFt != 20
                  || s.unusual
                     != false) ++bad; }
            { AA::SpaceShape s;
              if (AA::roomShapeFor(20, s)
                  || s.wFt != 0
                  || s.hFt != 0)
                  ++bad; }
            if (AA::unusualShapeFor(1)
                != AA::US_CIRCULAR) ++bad;
            if (AA::unusualShapeFor(14)
                != AA::US_OVAL) ++bad;
            if (AA::unusualShapeFor(20)
                != AA::US_CAVE) ++bad;
            if (AA::circularFeatureFor(1)
                != AA::CIRC_POOL) ++bad;
            if (AA::circularFeatureFor(8)
                != AA::CIRC_SHAFT) ++bad;
            if (AA::circularFeatureFor(20)
                != AA::CIRC_NORMAL) ++bad;
            if (AA::unusualSizeBaseFor(1) != 500) ++bad;
            if (AA::unusualSizeBaseFor(9) != 2000) ++bad;
            if (AA::unusualSizeBaseFor(20) != -1) ++bad;
            if (AA::exitsFor(1, false) != 1
                || AA::exitsFor(1, true)
                    != 2) ++bad;
            if (AA::exitsFor(10, false) != 0
                || AA::exitsFor(10, true)
                    != 1) ++bad;
            if (AA::exitsFor(20, false) != 1
                || AA::exitsFor(20, true)
                    != 1) ++bad;
            if (AA::exitLocationFor(1)
                != AA::EL_OPPOSITE) ++bad;
            if (AA::exitLocationFor(13)
                != AA::EL_RIGHT) ++bad;
            if (AA::exitLocationFor(20)
                != AA::EL_SAME) ++bad;
            if (AA::exitDirectionFor(1)
                != AA::ED_STRAIGHT) ++bad;
            if (AA::exitDirectionFor(17)
                != AA::ED_45_LR) ++bad;
            if (AA::exitDirectionFor(20)
                != AA::ED_45_RL) ++bad;
            if (AA::roomContentsFor(1)
                != dm::ROOM_EMPTY) ++bad;
            if (AA::roomContentsFor(18)
                != dm::ROOM_SPECIAL) ++bad;
            if (AA::roomContentsFor(20)
                != dm::ROOM_TREASURE) ++bad;
            if (AA::stairwayVariantFor(1)
                != AA::SV_UP1) ++bad;
            if (AA::stairwayVariantFor(9)
                != AA::SV_DOWN1) ++bad;
            if (AA::stairwayVariantFor(20)
                != AA::SV_DOWN3) ++bad;
            if (AA::treasureFor(1).kind
                    != AA::TR_CP
                || AA::treasureFor(1).basePerLevel
                    != 1000) ++bad;
            if (AA::treasureFor(81).kind
                    != AA::TR_PP
                || AA::treasureFor(81).basePerLevel
                    != 100) ++bad;
            if (AA::treasureFor(100).kind
                    != AA::TR_MAGIC
                || AA::treasureFor(100).basePerLevel
                    != 0) ++bad;
            if (AA::containerFor(1)
                != AA::C_BAGS) ++bad;
            if (AA::containerFor(11)
                != AA::C_POTTERY_JARS) ++bad;
            if (AA::containerFor(20)
                != AA::C_LOOSE) ++bad;
            if (AA::guardedByFor(1)
                != AA::G_CONTACT_POISON_CONTAINER) ++bad;
            if (AA::guardedByFor(13)
                != AA::G_CREATURES) ++bad;
            if (AA::guardedByFor(20)
                != AA::G_SYMBOL) ++bad;
            if (AA::hiddenByFor(1)
                != AA::H_INVISIBILITY) ++bad;
            if (AA::hiddenByFor(10)
                != AA::H_DISGUISED) ++bad;
            if (AA::hiddenByFor(20)
                != AA::H_SECRET_ROOM) ++bad;
            if (AA::stairsFor(1)
                != AA::ST_DOWN1) ++bad;
            if (AA::stairsFor(11)
                != AA::ST_CHIMNEY_UP1) ++bad;
            if (AA::stairsFor(20)
                != AA::ST_UP1_DOWN2) ++bad;
            if (AA::trickTrapFor(1)
                != AA::TT_SECRET_DOOR) ++bad;
            if (AA::trickTrapFor(13)
                != AA::TT_OIL_CINDER) ++bad;
            if (AA::trickTrapFor(20)
                != AA::TT_CHUTE) ++bad;
            if (AA::gasFor(1)
                != AA::GAS_OBSCURE) ++bad;
            if (AA::gasFor(13)
                != AA::GAS_SLEEP) ++bad;
            if (AA::gasFor(20)
                != AA::GAS_POISON) ++bad;
            { AA::CaveSize c = AA::caveFor(1);
              if (c.wFt != 40
                  || c.hFt != 60
                  || c.w2Ft != 0
                  || c.h2Ft != 0
                  || c.pool != false
                  || c.lake != false)
                  ++bad; }
            { AA::CaveSize c = AA::caveFor(12);
              if (c.wFt != 95
                  || c.hFt != 125
                  || c.w2Ft != 0
                  || c.h2Ft != 0
                  || c.pool != true
                  || c.lake != false)
                  ++bad; }
            { AA::CaveSize c = AA::caveFor(20);
              if (c.wFt != 275
                  || c.hFt != 375
                  || c.w2Ft != 0
                  || c.h2Ft != 0
                  || c.pool != false
                  || c.lake != true)
                  ++bad; }
            if (AA::poolFor(1)
                != AA::POOL_NONE) ++bad;
            if (AA::poolFor(11)
                != AA::POOL_MONSTER) ++bad;
            if (AA::poolFor(20)
                != AA::POOL_MAGICAL) ++bad;
            if (AA::lakeFor(1)
                != AA::LAKE_NONE) ++bad;
            if (AA::lakeFor(16)
                != AA::LAKE_MONSTERS) ++bad;
            if (AA::lakeFor(20)
                != AA::LAKE_ENCHANTED) ++bad;
            if (AA::magicPoolFor(1)
                != AA::MP_GOLD_TO_PLATINUM_LEAD) ++bad;
            if (AA::magicPoolFor(16)
                != AA::MP_TALKING) ++bad;
            if (AA::magicPoolFor(20)
                != AA::MP_TRANSPORTER) ++bad;
            if (AA::talkingPoolAlignmentFor(1)
                != AA::PA_LAWFUL_GOOD) ++bad;
            if (AA::talkingPoolAlignmentFor(10)
                != AA::PA_CHAOTIC_GOOD) ++bad;
            if (AA::talkingPoolAlignmentFor(20)
                != AA::PA_NEUTRAL) ++bad;
            if (AA::transportDestFor(1)
                != AA::TD_SURFACE) ++bad;
            if (AA::transportDestFor(13)
                != AA::TD_ONE_DOWN) ++bad;
            if (AA::transportDestFor(20)
                != AA::TD_100_MILES) ++bad;
        }
        printf("R1046 appendix A dressing registry data audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. rows (the full band cross-read) -----------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/appendixa");
            const auto* v_periodic_check = t.find("appendixa_periodic_check");
            if (!v_periodic_check) { ++bad; } else {
                static const char* const k1046_periodic_check[] = {
                    "PC_STRAIGHT", "PC_DOOR", "PC_SIDE",
                    "PC_TURN", "PC_CHAMBER", "PC_STAIRS",
                    "PC_DEAD_END", "PC_TRICK_TRAP", "PC_WANDERER",
                };
                if ((int)(sizeof(k1046_periodic_check)
                        / sizeof(k1046_periodic_check[0]))
                        != (int)v_periodic_check->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_periodic_check->rows.size(); ++i) {
                    const auto& rr = v_periodic_check->rows[i];
                    if (rr.name
                            != std::string(k1046_periodic_check[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::passageCheckFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_door_location = t.find("appendixa_door_location");
            if (!v_door_location) { ++bad; } else {
                static const char* const k1046_door_location[] = {
                    "DL_LEFT", "DL_RIGHT", "DL_AHEAD",
                };
                if ((int)(sizeof(k1046_door_location)
                        / sizeof(k1046_door_location[0]))
                        != (int)v_door_location->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_door_location->rows.size(); ++i) {
                    const auto& rr = v_door_location->rows[i];
                    if (rr.name
                            != std::string(k1046_door_location[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::doorLocationFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_space_beyond = t.find("appendixa_space_beyond");
            if (!v_space_beyond) { ++bad; } else {
                static const char* const k1046_space_beyond[] = {
                    "SB_PARALLEL", "SB_STRAIGHT_AHEAD", "SB_45_AHEAD",
                    "SB_45_BEHIND", "SB_ROOM", "SB_CHAMBER",
                };
                if ((int)(sizeof(k1046_space_beyond)
                        / sizeof(k1046_space_beyond[0]))
                        != (int)v_space_beyond->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_space_beyond->rows.size(); ++i) {
                    const auto& rr = v_space_beyond->rows[i];
                    if (rr.name
                            != std::string(k1046_space_beyond[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::spaceBeyondFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_side_passage = t.find("appendixa_side_passage");
            if (!v_side_passage) { ++bad; } else {
                static const char* const k1046_side_passage[] = {
                    "SP_L90", "SP_R90", "SP_L45_AHEAD",
                    "SP_R45_AHEAD", "SP_L45_BEHIND", "SP_R45_BEHIND",
                    "SP_L_CURVE", "SP_R_CURVE", "SP_T",
                    "SP_Y", "SP_FOURWAY", "SP_X",
                };
                if ((int)(sizeof(k1046_side_passage)
                        / sizeof(k1046_side_passage[0]))
                        != (int)v_side_passage->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_side_passage->rows.size(); ++i) {
                    const auto& rr = v_side_passage->rows[i];
                    if (rr.name
                            != std::string(k1046_side_passage[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::sidePassageFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_passage_width = t.find("appendixa_passage_width");
            if (!v_passage_width) { ++bad; } else {
                static const char* const k1046_passage_width[] = {
                    "PW_10", "PW_20", "PW_30",
                    "PW_5", "PW_-1",
                };
                if ((int)(sizeof(k1046_passage_width)
                        / sizeof(k1046_passage_width[0]))
                        != (int)v_passage_width->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_passage_width->rows.size(); ++i) {
                    const auto& rr = v_passage_width->rows[i];
                    if (rr.name
                            != std::string(k1046_passage_width[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if (dm::appendixa::passageWidthFeetFor(r)
                                != rr.gp)
                            ++bad;
                    }
                }
            }
            const auto* v_special_passage = t.find("appendixa_special_passage");
            if (!v_special_passage) { ++bad; } else {
                static const char* const k1046_special_passage[] = {
                    "SPEC_COLUMNS_CENTER", "SPEC_COLUMNS_DOUBLE", "SPEC_COLUMNS_DOUBLE",
                    "SPEC_COLUMNS_GALLERIES", "SPEC_STREAM", "SPEC_RIVER",
                    "SPEC_RIVER", "SPEC_RIVER", "SPEC_CHASM",
                };
                if ((int)(sizeof(k1046_special_passage)
                        / sizeof(k1046_special_passage[0]))
                        != (int)v_special_passage->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_special_passage->rows.size(); ++i) {
                    const auto& rr = v_special_passage->rows[i];
                    if (rr.name
                            != std::string(k1046_special_passage[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        dm::appendixa::SpecialPass sp
                            = dm::appendixa::specialPassageFor(r);
                        if ((int)sp.kind != rr.qtyLo
                            || sp.widthFt != rr.gp)
                            ++bad;
                    }
                }
            }
            const auto* v_river_feature = t.find("appendixa_river_feature");
            if (!v_river_feature) { ++bad; } else {
                static const char* const k1046_river_feature[] = {
                    "WF_BRIDGED", "WF_BOAT", "WF_OBSTACLE",
                };
                if ((int)(sizeof(k1046_river_feature)
                        / sizeof(k1046_river_feature[0]))
                        != (int)v_river_feature->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_river_feature->rows.size(); ++i) {
                    const auto& rr = v_river_feature->rows[i];
                    if (rr.name
                            != std::string(k1046_river_feature[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::riverFeature(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_chasm_feature = t.find("appendixa_chasm_feature");
            if (!v_chasm_feature) { ++bad; } else {
                static const char* const k1046_chasm_feature[] = {
                    "CF_BRIDGED", "CF_JUMPING", "CF_OBSTACLE",
                };
                if ((int)(sizeof(k1046_chasm_feature)
                        / sizeof(k1046_chasm_feature[0]))
                        != (int)v_chasm_feature->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_chasm_feature->rows.size(); ++i) {
                    const auto& rr = v_chasm_feature->rows[i];
                    if (rr.name
                            != std::string(k1046_chasm_feature[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::chasmFeature(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_turn = t.find("appendixa_turn");
            if (!v_turn) { ++bad; } else {
                static const char* const k1046_turn[] = {
                    "T_L90", "T_L45_AHEAD", "T_L45_BEHIND",
                    "T_R90", "T_R45_AHEAD", "T_R45_BEHIND",
                };
                if ((int)(sizeof(k1046_turn)
                        / sizeof(k1046_turn[0]))
                        != (int)v_turn->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_turn->rows.size(); ++i) {
                    const auto& rr = v_turn->rows[i];
                    if (rr.name
                            != std::string(k1046_turn[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::turnFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_chamber_shape = t.find("appendixa_chamber_shape");
            if (!v_chamber_shape) { ++bad; } else {
                static const char* const k1046_chamber_shape[] = {
                    "CHS_20x20", "CHS_30x30", "CHS_40x40",
                    "CHS_20x30", "CHS_30x50", "CHS_40x60",
                    "CHS_UNUSUAL",
                };
                if ((int)(sizeof(k1046_chamber_shape)
                        / sizeof(k1046_chamber_shape[0]))
                        != (int)v_chamber_shape->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_chamber_shape->rows.size(); ++i) {
                    const auto& rr = v_chamber_shape->rows[i];
                    if (rr.name
                            != std::string(k1046_chamber_shape[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        dm::appendixa::SpaceShape s;
                        dm::appendixa::chamberShapeFor(r, s);
                        (void)0;
                        if (false
                            || s.wFt != rr.gp
                            || s.hFt != rr.gpHi
                            || s.unusual
                               != (rr.qtyLo != 0))
                            ++bad;
                    }
                }
            }
            const auto* v_room_shape = t.find("appendixa_room_shape");
            if (!v_room_shape) { ++bad; } else {
                static const char* const k1046_room_shape[] = {
                    "RMS_10x10", "RMS_20x20", "RMS_30x30",
                    "RMS_40x40", "RMS_10x20", "RMS_20x30",
                    "RMS_20x40", "RMS_30x40", "RMS_BLANK",
                };
                if ((int)(sizeof(k1046_room_shape)
                        / sizeof(k1046_room_shape[0]))
                        != (int)v_room_shape->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_room_shape->rows.size(); ++i) {
                    const auto& rr = v_room_shape->rows[i];
                    if (rr.name
                            != std::string(k1046_room_shape[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        dm::appendixa::SpaceShape s;
                        bool ok =
                            dm::appendixa::roomShapeFor(r, s);
                        if (ok
                            == (rr.name
                                == std::string("RMS_BLANK")))
                            ++bad;
                        if (ok
                            && (s.wFt != rr.gp
                                || s.hFt != rr.gpHi
                                || s.unusual
                                   != (rr.qtyLo != 0)))
                            ++bad;
                    }
                }
            }
            const auto* v_unusual_shape = t.find("appendixa_unusual_shape");
            if (!v_unusual_shape) { ++bad; } else {
                static const char* const k1046_unusual_shape[] = {
                    "US_CIRCULAR", "US_TRIANGULAR", "US_TRAPEZOIDAL",
                    "US_ODD", "US_OVAL", "US_HEXAGONAL",
                    "US_OCTAGONAL", "US_CAVE",
                };
                if ((int)(sizeof(k1046_unusual_shape)
                        / sizeof(k1046_unusual_shape[0]))
                        != (int)v_unusual_shape->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_unusual_shape->rows.size(); ++i) {
                    const auto& rr = v_unusual_shape->rows[i];
                    if (rr.name
                            != std::string(k1046_unusual_shape[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::unusualShapeFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_circular_feature = t.find("appendixa_circular_feature");
            if (!v_circular_feature) { ++bad; } else {
                static const char* const k1046_circular_feature[] = {
                    "CIRC_POOL", "CIRC_WELL", "CIRC_SHAFT",
                    "CIRC_NORMAL",
                };
                if ((int)(sizeof(k1046_circular_feature)
                        / sizeof(k1046_circular_feature[0]))
                        != (int)v_circular_feature->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_circular_feature->rows.size(); ++i) {
                    const auto& rr = v_circular_feature->rows[i];
                    if (rr.name
                            != std::string(k1046_circular_feature[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::circularFeatureFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_unusual_size = t.find("appendixa_unusual_size");
            if (!v_unusual_size) { ++bad; } else {
                static const char* const k1046_unusual_size[] = {
                    "SIZE_500", "SIZE_900", "SIZE_1300",
                    "SIZE_2000", "SIZE_2700", "SIZE_3400",
                    "SIZE_-1",
                };
                if ((int)(sizeof(k1046_unusual_size)
                        / sizeof(k1046_unusual_size[0]))
                        != (int)v_unusual_size->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_unusual_size->rows.size(); ++i) {
                    const auto& rr = v_unusual_size->rows[i];
                    if (rr.name
                            != std::string(k1046_unusual_size[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if (dm::appendixa::unusualSizeBaseFor(r)
                                != rr.gp)
                            ++bad;
                    }
                }
            }
            const auto* v_exits = t.find("appendixa_exits");
            if (!v_exits) { ++bad; } else {
                static const char* const k1046_exits[] = {
                    "EXITS_1", "EXITS_2", "EXITS_3",
                    "EXITS_4", "EXITS_5", "EXITS_6",
                    "EXITS_7",
                };
                if ((int)(sizeof(k1046_exits)
                        / sizeof(k1046_exits[0]))
                        != (int)v_exits->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_exits->rows.size(); ++i) {
                    const auto& rr = v_exits->rows[i];
                    if (rr.name
                            != std::string(k1046_exits[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if (dm::appendixa::exitsFor(r, false)
                                != rr.gp
                            || dm::appendixa::exitsFor(r, true)
                                   != rr.gpHi)
                            ++bad;
                    }
                }
            }
            const auto* v_exit_location = t.find("appendixa_exit_location");
            if (!v_exit_location) { ++bad; } else {
                static const char* const k1046_exit_location[] = {
                    "EL_OPPOSITE", "EL_LEFT", "EL_RIGHT",
                    "EL_SAME",
                };
                if ((int)(sizeof(k1046_exit_location)
                        / sizeof(k1046_exit_location[0]))
                        != (int)v_exit_location->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_exit_location->rows.size(); ++i) {
                    const auto& rr = v_exit_location->rows[i];
                    if (rr.name
                            != std::string(k1046_exit_location[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::exitLocationFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_exit_direction = t.find("appendixa_exit_direction");
            if (!v_exit_direction) { ++bad; } else {
                static const char* const k1046_exit_direction[] = {
                    "ED_STRAIGHT", "ED_45_LR", "ED_45_RL",
                };
                if ((int)(sizeof(k1046_exit_direction)
                        / sizeof(k1046_exit_direction[0]))
                        != (int)v_exit_direction->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_exit_direction->rows.size(); ++i) {
                    const auto& rr = v_exit_direction->rows[i];
                    if (rr.name
                            != std::string(k1046_exit_direction[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::exitDirectionFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_room_contents = t.find("appendixa_room_contents");
            if (!v_room_contents) { ++bad; } else {
                static const char* const k1046_room_contents[] = {
                    "ROOM_EMPTY", "ROOM_MONSTER", "ROOM_MONSTER_TREASURE",
                    "ROOM_SPECIAL", "ROOM_TRAP", "ROOM_TREASURE",
                };
                if ((int)(sizeof(k1046_room_contents)
                        / sizeof(k1046_room_contents[0]))
                        != (int)v_room_contents->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_room_contents->rows.size(); ++i) {
                    const auto& rr = v_room_contents->rows[i];
                    if (rr.name
                            != std::string(k1046_room_contents[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::roomContentsFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_stairway_variant = t.find("appendixa_stairway_variant");
            if (!v_stairway_variant) { ++bad; } else {
                static const char* const k1046_stairway_variant[] = {
                    "SV_UP1", "SV_UP2", "SV_DOWN1",
                    "SV_DOWN2", "SV_DOWN3",
                };
                if ((int)(sizeof(k1046_stairway_variant)
                        / sizeof(k1046_stairway_variant[0]))
                        != (int)v_stairway_variant->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_stairway_variant->rows.size(); ++i) {
                    const auto& rr = v_stairway_variant->rows[i];
                    if (rr.name
                            != std::string(k1046_stairway_variant[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::stairwayVariantFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_treasure = t.find("appendixa_treasure");
            if (!v_treasure) { ++bad; } else {
                static const char* const k1046_treasure[] = {
                    "TR_CP", "TR_SP", "TR_EP",
                    "TR_GP", "TR_PP", "TR_GEMS",
                    "TR_JEWELRY", "TR_MAGIC",
                };
                if ((int)(sizeof(k1046_treasure)
                        / sizeof(k1046_treasure[0]))
                        != (int)v_treasure->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_treasure->rows.size(); ++i) {
                    const auto& rr = v_treasure->rows[i];
                    if (rr.name
                            != std::string(k1046_treasure[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        dm::appendixa::TreasureRow tr
                            = dm::appendixa::treasureFor(r);
                        if ((int)tr.kind != rr.qtyLo
                            || tr.basePerLevel
                               != rr.gp)
                            ++bad;
                    }
                }
            }
            const auto* v_container = t.find("appendixa_container");
            if (!v_container) { ++bad; } else {
                static const char* const k1046_container[] = {
                    "C_BAGS", "C_SACKS", "C_SMALL_COFFERS",
                    "C_CHESTS", "C_HUGE_CHESTS", "C_POTTERY_JARS",
                    "C_METAL_URNS", "C_STONE_CONTAINERS", "C_IRON_TRUNKS",
                    "C_LOOSE",
                };
                if ((int)(sizeof(k1046_container)
                        / sizeof(k1046_container[0]))
                        != (int)v_container->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_container->rows.size(); ++i) {
                    const auto& rr = v_container->rows[i];
                    if (rr.name
                            != std::string(k1046_container[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::containerFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_guard = t.find("appendixa_guard");
            if (!v_guard) { ++bad; } else {
                static const char* const k1046_guard[] = {
                    "G_CONTACT_POISON_CONTAINER", "G_CONTACT_POISON_TREASURE", "G_NEEDLES_LOCK",
                    "G_NEEDLES_HANDLES", "G_DARTS_FRONT", "G_DARTS_TOP",
                    "G_DARTS_BOTTOM", "G_BLADE_SCYTHE", "G_CREATURES",
                    "G_GAS", "G_TRAPDOOR_FRONT", "G_TRAPDOOR_6FT",
                    "G_STONE_BLOCK", "G_SPEARS", "G_EXPLOSIVE_RUNES",
                    "G_SYMBOL",
                };
                if ((int)(sizeof(k1046_guard)
                        / sizeof(k1046_guard[0]))
                        != (int)v_guard->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_guard->rows.size(); ++i) {
                    const auto& rr = v_guard->rows[i];
                    if (rr.name
                            != std::string(k1046_guard[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::guardedByFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_hidden = t.find("appendixa_hidden");
            if (!v_hidden) { ++bad; } else {
                static const char* const k1046_hidden[] = {
                    "H_INVISIBILITY", "H_ILLUSION", "H_SECRET_SPACE_UNDER",
                    "H_SECRET_COMPARTMENT", "H_ORDINARY_ITEM", "H_DISGUISED",
                    "H_TRASH_DUNG", "H_LOOSE_FLOOR_STONE", "H_LOOSE_WALL_STONE",
                    "H_SECRET_ROOM",
                };
                if ((int)(sizeof(k1046_hidden)
                        / sizeof(k1046_hidden[0]))
                        != (int)v_hidden->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_hidden->rows.size(); ++i) {
                    const auto& rr = v_hidden->rows[i];
                    if (rr.name
                            != std::string(k1046_hidden[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::hiddenByFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_stairs = t.find("appendixa_stairs");
            if (!v_stairs) { ++bad; } else {
                static const char* const k1046_stairs[] = {
                    "ST_DOWN1", "ST_DOWN2", "ST_DOWN3",
                    "ST_UP1", "ST_UP_DEAD", "ST_DOWN_DEAD",
                    "ST_CHIMNEY_UP1", "ST_CHIMNEY_UP2", "ST_CHIMNEY_DOWN2",
                    "ST_TRAPDOOR_DOWN1", "ST_TRAPDOOR_DOWN2", "ST_UP1_DOWN2",
                };
                if ((int)(sizeof(k1046_stairs)
                        / sizeof(k1046_stairs[0]))
                        != (int)v_stairs->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_stairs->rows.size(); ++i) {
                    const auto& rr = v_stairs->rows[i];
                    if (rr.name
                            != std::string(k1046_stairs[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::stairsFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_trick_trap = t.find("appendixa_trick_trap");
            if (!v_trick_trap) { ++bad; } else {
                static const char* const k1046_trick_trap[] = {
                    "TT_SECRET_DOOR", "TT_PIT", "TT_PIT_SPIKED",
                    "TT_ELEVATOR_DOWN1", "TT_ELEVATOR_DOWN2", "TT_ELEVATOR_2TO5",
                    "TT_SLIDING_WALL", "TT_OIL_CINDER", "TT_PIT_CRUSHING",
                    "TT_ARROW_TRAP", "TT_SPEAR_TRAP", "TT_GAS",
                    "TT_FALLING_DOOR_STONE", "TT_ILLUSIONARY_WALL", "TT_CHUTE",
                };
                if ((int)(sizeof(k1046_trick_trap)
                        / sizeof(k1046_trick_trap[0]))
                        != (int)v_trick_trap->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_trick_trap->rows.size(); ++i) {
                    const auto& rr = v_trick_trap->rows[i];
                    if (rr.name
                            != std::string(k1046_trick_trap[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::trickTrapFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_gas = t.find("appendixa_gas");
            if (!v_gas) { ++bad; } else {
                static const char* const k1046_gas[] = {
                    "GAS_OBSCURE", "GAS_BLIND", "GAS_FEAR",
                    "GAS_SLEEP", "GAS_STRENGTH", "GAS_SICKNESS",
                    "GAS_POISON",
                };
                if ((int)(sizeof(k1046_gas)
                        / sizeof(k1046_gas[0]))
                        != (int)v_gas->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_gas->rows.size(); ++i) {
                    const auto& rr = v_gas->rows[i];
                    if (rr.name
                            != std::string(k1046_gas[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::gasFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_cave = t.find("appendixa_cave");
            if (!v_cave) { ++bad; } else {
                static const char* const k1046_cave[] = {
                    "CAVE_1", "CAVE_2", "CAVE_3",
                    "CAVE_4", "CAVE_5", "CAVE_6",
                    "CAVE_7", "CAVE_8",
                };
                if ((int)(sizeof(k1046_cave)
                        / sizeof(k1046_cave[0]))
                        != (int)v_cave->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_cave->rows.size(); ++i) {
                    const auto& rr = v_cave->rows[i];
                    if (rr.name
                            != std::string(k1046_cave[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        dm::appendixa::CaveSize c =
                            dm::appendixa::caveFor(r);
                        if (c.wFt != rr.gp
                            || c.hFt != rr.gpHi
                            || c.w2Ft != rr.xp
                            || c.h2Ft != rr.xpHi
                            || c.pool
                               != (rr.qtyLo != 0)
                            || c.lake
                               != (rr.qtyHi != 0))
                            ++bad;
                    }
                }
            }
            const auto* v_pool = t.find("appendixa_pool");
            if (!v_pool) { ++bad; } else {
                static const char* const k1046_pool[] = {
                    "POOL_NONE", "POOL_NO_MONSTER", "POOL_MONSTER",
                    "POOL_MONSTER_TREASURE", "POOL_MAGICAL",
                };
                if ((int)(sizeof(k1046_pool)
                        / sizeof(k1046_pool[0]))
                        != (int)v_pool->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_pool->rows.size(); ++i) {
                    const auto& rr = v_pool->rows[i];
                    if (rr.name
                            != std::string(k1046_pool[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::poolFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_lake = t.find("appendixa_lake");
            if (!v_lake) { ++bad; } else {
                static const char* const k1046_lake[] = {
                    "LAKE_NONE", "LAKE_NO_MONSTERS", "LAKE_MONSTERS",
                    "LAKE_ENCHANTED",
                };
                if ((int)(sizeof(k1046_lake)
                        / sizeof(k1046_lake[0]))
                        != (int)v_lake->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_lake->rows.size(); ++i) {
                    const auto& rr = v_lake->rows[i];
                    if (rr.name
                            != std::string(k1046_lake[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::lakeFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_magic_pool = t.find("appendixa_magic_pool");
            if (!v_magic_pool) { ++bad; } else {
                static const char* const k1046_magic_pool[] = {
                    "MP_GOLD_TO_PLATINUM_LEAD", "MP_CHARACTERISTIC", "MP_TALKING",
                    "MP_TRANSPORTER",
                };
                if ((int)(sizeof(k1046_magic_pool)
                        / sizeof(k1046_magic_pool[0]))
                        != (int)v_magic_pool->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_magic_pool->rows.size(); ++i) {
                    const auto& rr = v_magic_pool->rows[i];
                    if (rr.name
                            != std::string(k1046_magic_pool[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::magicPoolFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_talking_pool_alignment = t.find("appendixa_talking_pool_alignment");
            if (!v_talking_pool_alignment) { ++bad; } else {
                static const char* const k1046_talking_pool_alignment[] = {
                    "PA_LAWFUL_GOOD", "PA_LAWFUL_EVIL", "PA_CHAOTIC_GOOD",
                    "PA_CHAOTIC_EVIL", "PA_NEUTRAL",
                };
                if ((int)(sizeof(k1046_talking_pool_alignment)
                        / sizeof(k1046_talking_pool_alignment[0]))
                        != (int)v_talking_pool_alignment->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_talking_pool_alignment->rows.size(); ++i) {
                    const auto& rr = v_talking_pool_alignment->rows[i];
                    if (rr.name
                            != std::string(k1046_talking_pool_alignment[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::talkingPoolAlignmentFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
            const auto* v_transport_dest = t.find("appendixa_transport_dest");
            if (!v_transport_dest) { ++bad; } else {
                static const char* const k1046_transport_dest[] = {
                    "TD_SURFACE", "TD_ELSEWHERE_LEVEL", "TD_ONE_DOWN",
                    "TD_100_MILES",
                };
                if ((int)(sizeof(k1046_transport_dest)
                        / sizeof(k1046_transport_dest[0]))
                        != (int)v_transport_dest->rows.size())
                    ++bad;
                for (int i = 0;
                     i < (int)v_transport_dest->rows.size(); ++i) {
                    const auto& rr = v_transport_dest->rows[i];
                    if (rr.name
                            != std::string(k1046_transport_dest[i]))
                        ++bad;
                    for (int r = rr.bandLo;
                         r <= rr.bandHi; ++r) {
                        if ((int)dm::appendixa::transportDestFor(r)
                                != rr.qtyLo)
                            ++bad;
                    }
                }
            }
        }
        printf("R1046 appendix A dressing registry rows audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. edges (fall-through, negatives) -----------
        {
            namespace AA = dm::appendixa;
            if ((int)AA::passageCheckFor(0) != 0)
                ++bad;
            if ((int)AA::passageCheckFor(-5) != 0)
                ++bad;
            if ((int)AA::passageCheckFor(21) != 8)
                ++bad;
            if ((int)AA::passageCheckFor(999) != 8)
                ++bad;
            if ((int)AA::doorLocationFor(0) != 0)
                ++bad;
            if ((int)AA::doorLocationFor(-5) != 0)
                ++bad;
            if ((int)AA::doorLocationFor(21) != 2)
                ++bad;
            if ((int)AA::doorLocationFor(999) != 2)
                ++bad;
            if ((int)AA::spaceBeyondFor(0) != 0)
                ++bad;
            if ((int)AA::spaceBeyondFor(-5) != 0)
                ++bad;
            if ((int)AA::spaceBeyondFor(21) != 5)
                ++bad;
            if ((int)AA::spaceBeyondFor(999) != 5)
                ++bad;
            if ((int)AA::sidePassageFor(0) != 0)
                ++bad;
            if ((int)AA::sidePassageFor(-5) != 0)
                ++bad;
            if ((int)AA::sidePassageFor(21) != 11)
                ++bad;
            if ((int)AA::sidePassageFor(999) != 11)
                ++bad;
            if (AA::passageWidthFeetFor(0) != 10)
                ++bad;
            if (AA::passageWidthFeetFor(-5) != 10)
                ++bad;
            if (AA::passageWidthFeetFor(21) != -1)
                ++bad;
            if (AA::passageWidthFeetFor(999) != -1)
                ++bad;
            if ((int)AA::specialPassageFor(0).kind != 0
                || AA::specialPassageFor(0).widthFt
                    != 40) ++bad;
            if ((int)AA::specialPassageFor(-5).kind != 0
                || AA::specialPassageFor(-5).widthFt
                    != 40) ++bad;
            if ((int)AA::specialPassageFor(21).kind != 5
                || AA::specialPassageFor(21).widthFt
                    != 20) ++bad;
            if ((int)AA::specialPassageFor(999).kind != 5
                || AA::specialPassageFor(999).widthFt
                    != 20) ++bad;
            if ((int)AA::riverFeature(0) != 0)
                ++bad;
            if ((int)AA::riverFeature(-5) != 0)
                ++bad;
            if ((int)AA::riverFeature(21) != 2)
                ++bad;
            if ((int)AA::riverFeature(999) != 2)
                ++bad;
            if ((int)AA::chasmFeature(0) != 0)
                ++bad;
            if ((int)AA::chasmFeature(-5) != 0)
                ++bad;
            if ((int)AA::chasmFeature(21) != 2)
                ++bad;
            if ((int)AA::chasmFeature(999) != 2)
                ++bad;
            if ((int)AA::turnFor(0) != 0)
                ++bad;
            if ((int)AA::turnFor(-5) != 0)
                ++bad;
            if ((int)AA::turnFor(21) != 5)
                ++bad;
            if ((int)AA::turnFor(999) != 5)
                ++bad;
            { AA::SpaceShape s;
              AA::chamberShapeFor(0, s);
              if (s.wFt != 20
                  || s.hFt != 20
                  || s.unusual != false)
                  ++bad; }
            { AA::SpaceShape s;
              AA::chamberShapeFor(-5, s);
              if (s.wFt != 20
                  || s.hFt != 20
                  || s.unusual != false)
                  ++bad; }
            { AA::SpaceShape s;
              AA::chamberShapeFor(21, s);
              if (s.wFt != 0
                  || s.hFt != 0
                  || s.unusual != true)
                  ++bad; }
            { AA::SpaceShape s;
              AA::chamberShapeFor(999, s);
              if (s.wFt != 0
                  || s.hFt != 0
                  || s.unusual != true)
                  ++bad; }
            { AA::SpaceShape s;
              AA::roomShapeFor(0, s);
              if (s.wFt != 10
                  || s.hFt != 10
                  || s.unusual != false)
                  ++bad; }
            { AA::SpaceShape s;
              AA::roomShapeFor(-5, s);
              if (s.wFt != 10
                  || s.hFt != 10
                  || s.unusual != false)
                  ++bad; }
            { AA::SpaceShape s;
              if (AA::roomShapeFor(21, s)) ++bad; }
            { AA::SpaceShape s;
              if (AA::roomShapeFor(999, s)) ++bad; }
            if ((int)AA::unusualShapeFor(0) != 0)
                ++bad;
            if ((int)AA::unusualShapeFor(-5) != 0)
                ++bad;
            if ((int)AA::unusualShapeFor(21) != 7)
                ++bad;
            if ((int)AA::unusualShapeFor(999) != 7)
                ++bad;
            if ((int)AA::circularFeatureFor(0) != 0)
                ++bad;
            if ((int)AA::circularFeatureFor(-5) != 0)
                ++bad;
            if ((int)AA::circularFeatureFor(21) != 3)
                ++bad;
            if ((int)AA::circularFeatureFor(999) != 3)
                ++bad;
            if (AA::unusualSizeBaseFor(0) != 500)
                ++bad;
            if (AA::unusualSizeBaseFor(-5) != 500)
                ++bad;
            if (AA::unusualSizeBaseFor(21) != -1)
                ++bad;
            if (AA::unusualSizeBaseFor(999) != -1)
                ++bad;
            if (AA::exitsFor(0, false) != 1
                || AA::exitsFor(0, true)
                    != 2) ++bad;
            if (AA::exitsFor(-5, false) != 1
                || AA::exitsFor(-5, true)
                    != 2) ++bad;
            if (AA::exitsFor(21, false) != 1
                || AA::exitsFor(21, true)
                    != 1) ++bad;
            if (AA::exitsFor(999, false) != 1
                || AA::exitsFor(999, true)
                    != 1) ++bad;
            if ((int)AA::exitLocationFor(0) != 0)
                ++bad;
            if ((int)AA::exitLocationFor(-5) != 0)
                ++bad;
            if ((int)AA::exitLocationFor(21) != 3)
                ++bad;
            if ((int)AA::exitLocationFor(999) != 3)
                ++bad;
            if ((int)AA::exitDirectionFor(0) != 0)
                ++bad;
            if ((int)AA::exitDirectionFor(-5) != 0)
                ++bad;
            if ((int)AA::exitDirectionFor(21) != 2)
                ++bad;
            if ((int)AA::exitDirectionFor(999) != 2)
                ++bad;
            if ((int)AA::roomContentsFor(0) != 0)
                ++bad;
            if ((int)AA::roomContentsFor(-5) != 0)
                ++bad;
            if ((int)AA::roomContentsFor(21) != 3)
                ++bad;
            if ((int)AA::roomContentsFor(999) != 3)
                ++bad;
            if ((int)AA::stairwayVariantFor(0) != 0)
                ++bad;
            if ((int)AA::stairwayVariantFor(-5) != 0)
                ++bad;
            if ((int)AA::stairwayVariantFor(21) != 4)
                ++bad;
            if ((int)AA::stairwayVariantFor(999) != 4)
                ++bad;
            if ((int)AA::treasureFor(0).kind != 0
                || AA::treasureFor(0).basePerLevel
                    != 1000) ++bad;
            if ((int)AA::treasureFor(-5).kind != 0
                || AA::treasureFor(-5).basePerLevel
                    != 1000) ++bad;
            if ((int)AA::treasureFor(101).kind != 7
                || AA::treasureFor(101).basePerLevel
                    != 0) ++bad;
            if ((int)AA::treasureFor(999).kind != 7
                || AA::treasureFor(999).basePerLevel
                    != 0) ++bad;
            if ((int)AA::containerFor(0) != 0)
                ++bad;
            if ((int)AA::containerFor(-5) != 0)
                ++bad;
            if ((int)AA::containerFor(21) != 9)
                ++bad;
            if ((int)AA::containerFor(999) != 9)
                ++bad;
            if ((int)AA::guardedByFor(0) != 0)
                ++bad;
            if ((int)AA::guardedByFor(-5) != 0)
                ++bad;
            if ((int)AA::guardedByFor(21) != 15)
                ++bad;
            if ((int)AA::guardedByFor(999) != 15)
                ++bad;
            if ((int)AA::hiddenByFor(0) != 0)
                ++bad;
            if ((int)AA::hiddenByFor(-5) != 0)
                ++bad;
            if ((int)AA::hiddenByFor(21) != 9)
                ++bad;
            if ((int)AA::hiddenByFor(999) != 9)
                ++bad;
            if ((int)AA::stairsFor(0) != 0)
                ++bad;
            if ((int)AA::stairsFor(-5) != 0)
                ++bad;
            if ((int)AA::stairsFor(21) != 11)
                ++bad;
            if ((int)AA::stairsFor(999) != 11)
                ++bad;
            if ((int)AA::trickTrapFor(0) != 0)
                ++bad;
            if ((int)AA::trickTrapFor(-5) != 0)
                ++bad;
            if ((int)AA::trickTrapFor(21) != 14)
                ++bad;
            if ((int)AA::trickTrapFor(999) != 14)
                ++bad;
            if ((int)AA::gasFor(0) != 0)
                ++bad;
            if ((int)AA::gasFor(-5) != 0)
                ++bad;
            if ((int)AA::gasFor(21) != 6)
                ++bad;
            if ((int)AA::gasFor(999) != 6)
                ++bad;
            { AA::CaveSize c = AA::caveFor(0);
              if (c.wFt != 40
                  || c.hFt != 60
                  || c.w2Ft != 0
                  || c.h2Ft != 0
                  || c.pool != false
                  || c.lake != false)
                  ++bad; }
            { AA::CaveSize c = AA::caveFor(-5);
              if (c.wFt != 40
                  || c.hFt != 60
                  || c.w2Ft != 0
                  || c.h2Ft != 0
                  || c.pool != false
                  || c.lake != false)
                  ++bad; }
            { AA::CaveSize c = AA::caveFor(21);
              if (c.wFt != 275
                  || c.hFt != 375
                  || c.w2Ft != 0
                  || c.h2Ft != 0
                  || c.pool != false
                  || c.lake != true)
                  ++bad; }
            { AA::CaveSize c = AA::caveFor(999);
              if (c.wFt != 275
                  || c.hFt != 375
                  || c.w2Ft != 0
                  || c.h2Ft != 0
                  || c.pool != false
                  || c.lake != true)
                  ++bad; }
            if ((int)AA::poolFor(0) != 0)
                ++bad;
            if ((int)AA::poolFor(-5) != 0)
                ++bad;
            if ((int)AA::poolFor(21) != 4)
                ++bad;
            if ((int)AA::poolFor(999) != 4)
                ++bad;
            if ((int)AA::lakeFor(0) != 0)
                ++bad;
            if ((int)AA::lakeFor(-5) != 0)
                ++bad;
            if ((int)AA::lakeFor(21) != 3)
                ++bad;
            if ((int)AA::lakeFor(999) != 3)
                ++bad;
            if ((int)AA::magicPoolFor(0) != 0)
                ++bad;
            if ((int)AA::magicPoolFor(-5) != 0)
                ++bad;
            if ((int)AA::magicPoolFor(21) != 3)
                ++bad;
            if ((int)AA::magicPoolFor(999) != 3)
                ++bad;
            if ((int)AA::talkingPoolAlignmentFor(0) != 0)
                ++bad;
            if ((int)AA::talkingPoolAlignmentFor(-5) != 0)
                ++bad;
            if ((int)AA::talkingPoolAlignmentFor(21) != 4)
                ++bad;
            if ((int)AA::talkingPoolAlignmentFor(999) != 4)
                ++bad;
            if ((int)AA::transportDestFor(0) != 0)
                ++bad;
            if ((int)AA::transportDestFor(-5) != 0)
                ++bad;
            if ((int)AA::transportDestFor(21) != 3)
                ++bad;
            if ((int)AA::transportDestFor(999) != 3)
                ++bad;
            if (!dm::appendixa::aaView("appendixa").empty())
                ++bad;
            if (!dm::appendixa::aaView("no_such").empty())
                ++bad;
            if (dm::appendixa::aaReg().find("treasure_swords")
                    != nullptr) ++bad;
            if (dm::appendixa::aaReg().find("") != nullptr)
                ++bad;
        }
        printf("R1046 appendix A dressing registry edges audit: bad %d\n", bad);
    }
