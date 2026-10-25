    // ---- R124: appendix A dressing audit ----------------------------------
    // The DMG pp.169-172 tables (Appendix A), pinned
    // row-by-row in dm/appendixa.h: the periodic check,
    // doors (both halves), side passages, passage
    // width, the special passages and their
    // stream/river/chasm chances, turns, chamber and
    // room shapes, the unusual shape/size sub-tables,
    // exits (count, location, direction), room
    // contents and the stairway variant, treasure by
    // level, containers, guards, hiding, stairs, tricks
    // and traps, gas, caves, pools, lakes and magic
    // pools with their sub-tables. The walk's four
    // wired helpers follow the bands, and the
    // generator still carves.
    {
        int bad = 0;
        namespace AP = dm::appendixa;
        // TABLE I: periodic check (p.170)
        static const AP::PassageCheck kT1[21] = {
            AP::PC_COUNT,
            AP::PC_STRAIGHT, AP::PC_STRAIGHT,
            AP::PC_DOOR, AP::PC_DOOR, AP::PC_DOOR,
            AP::PC_SIDE, AP::PC_SIDE, AP::PC_SIDE,
            AP::PC_SIDE, AP::PC_SIDE,
            AP::PC_TURN, AP::PC_TURN, AP::PC_TURN,
            AP::PC_CHAMBER, AP::PC_CHAMBER, AP::PC_CHAMBER,
            AP::PC_STAIRS, AP::PC_DEAD_END, AP::PC_TRICK_TRAP,
            AP::PC_WANDERER
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::passageCheckFor(r) != kT1[r]) ++bad;
        // TABLE II: doors (p.170)
        for (int r = 1; r <= 6; ++r)
            if (AP::doorLocationFor(r) != AP::DL_LEFT) ++bad;
        for (int r = 7; r <= 12; ++r)
            if (AP::doorLocationFor(r) != AP::DL_RIGHT) ++bad;
        for (int r = 13; r <= 20; ++r)
            if (AP::doorLocationFor(r) != AP::DL_AHEAD) ++bad;
        for (int r = 1; r <= 4; ++r)
            if (AP::spaceBeyondFor(r) != AP::SB_PARALLEL) ++bad;
        for (int r = 5; r <= 8; ++r)
            if (AP::spaceBeyondFor(r) != AP::SB_STRAIGHT_AHEAD) ++bad;
        if (AP::spaceBeyondFor(9) != AP::SB_45_AHEAD) ++bad;
        if (AP::spaceBeyondFor(10) != AP::SB_45_BEHIND) ++bad;
        for (int r = 11; r <= 18; ++r)
            if (AP::spaceBeyondFor(r) != AP::SB_ROOM) ++bad;
        for (int r = 19; r <= 20; ++r)
            if (AP::spaceBeyondFor(r) != AP::SB_CHAMBER) ++bad;
        // TABLE III: side passages (p.170)
        static const AP::SidePassage kT3[21] = {
            AP::SP_COUNT,
            AP::SP_L90, AP::SP_L90,
            AP::SP_R90, AP::SP_R90,
            AP::SP_L45_AHEAD, AP::SP_R45_AHEAD,
            AP::SP_L45_BEHIND, AP::SP_R45_BEHIND,
            AP::SP_L_CURVE, AP::SP_R_CURVE,
            AP::SP_T, AP::SP_T, AP::SP_T,
            AP::SP_Y, AP::SP_Y,
            AP::SP_FOURWAY, AP::SP_FOURWAY,
            AP::SP_FOURWAY, AP::SP_FOURWAY,
            AP::SP_X
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::sidePassageFor(r) != kT3[r]) ++bad;
        // TABLE III.A: passage width (p.170)
        for (int r = 1; r <= 12; ++r)
            if (AP::passageWidthFeetFor(r) != 10) ++bad;
        for (int r = 13; r <= 16; ++r)
            if (AP::passageWidthFeetFor(r) != 20) ++bad;
        if (AP::passageWidthFeetFor(17) != 30) ++bad;
        if (AP::passageWidthFeetFor(18) != 5) ++bad;
        if (AP::passageWidthFeetFor(19) != -1 ||
            AP::passageWidthFeetFor(20) != -1) ++bad;
        // TABLE III.B: special passages (p.170)
        static const AP::SpecialPassage kSp[21] = {
            AP::SPEC_COUNT,
            AP::SPEC_COLUMNS_CENTER, AP::SPEC_COLUMNS_CENTER,
            AP::SPEC_COLUMNS_CENTER, AP::SPEC_COLUMNS_CENTER,
            AP::SPEC_COLUMNS_DOUBLE, AP::SPEC_COLUMNS_DOUBLE,
            AP::SPEC_COLUMNS_DOUBLE,
            AP::SPEC_COLUMNS_DOUBLE, AP::SPEC_COLUMNS_DOUBLE,
            AP::SPEC_COLUMNS_DOUBLE,
            AP::SPEC_COLUMNS_GALLERIES, AP::SPEC_COLUMNS_GALLERIES,
            AP::SPEC_STREAM, AP::SPEC_STREAM, AP::SPEC_STREAM,
            AP::SPEC_RIVER, AP::SPEC_RIVER,
            AP::SPEC_RIVER, AP::SPEC_RIVER, AP::SPEC_CHASM
        };
        static const int kSpW[21] = { 0,
            40, 40, 40, 40, 40, 40, 40,
            50, 50, 50, 50, 50,
            10, 10, 10, 20, 20, 40, 60, 20 };
        for (int r = 1; r <= 20; ++r) {
            AP::SpecialPass sp = AP::specialPassageFor(r);
            if (sp.kind != kSp[r] || sp.widthFt != kSpW[r]) ++bad;
        }
        // III.B footnotes: the stream/river/chasm chances
        for (int r = 1; r <= 15; ++r)
            if (!AP::streamBridged(r)) ++bad;
        for (int r = 16; r <= 20; ++r)
            if (AP::streamBridged(r)) ++bad;
        for (int r = 1; r <= 10; ++r)
            if (AP::riverFeature(r) != AP::WF_BRIDGED) ++bad;
        for (int r = 11; r <= 15; ++r)
            if (AP::riverFeature(r) != AP::WF_BOAT) ++bad;
        for (int r = 16; r <= 20; ++r)
            if (AP::riverFeature(r) != AP::WF_OBSTACLE) ++bad;
        for (int r = 1; r <= 10; ++r)
            if (AP::chasmFeature(r) != AP::CF_BRIDGED) ++bad;
        for (int r = 11; r <= 15; ++r)
            if (AP::chasmFeature(r) != AP::CF_JUMPING) ++bad;
        for (int r = 16; r <= 20; ++r)
            if (AP::chasmFeature(r) != AP::CF_OBSTACLE) ++bad;
        // TABLE IV: turns (p.170)
        static const AP::TurnKind kT4[21] = {
            AP::T_L90,
            AP::T_L90, AP::T_L90, AP::T_L90, AP::T_L90,
            AP::T_L90, AP::T_L90, AP::T_L90, AP::T_L90,
            AP::T_L45_AHEAD, AP::T_L45_BEHIND,
            AP::T_R90, AP::T_R90, AP::T_R90, AP::T_R90,
            AP::T_R90, AP::T_R90, AP::T_R90, AP::T_R90,
            AP::T_R45_AHEAD, AP::T_R45_BEHIND
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::turnFor(r) != kT4[r]) ++bad;
        // TABLE V: chamber and room shapes (p.171)
        static const int kChW[21] = { 0,
            20, 20, 20, 20, 30, 30, 40, 40,
            20, 20, 20, 20, 20, 30, 30, 40, 40, 0, 0, 0 };
        static const int kChH[21] = { 0,
            20, 20, 20, 20, 30, 30, 40, 40,
            30, 30, 30, 30, 30, 50, 50, 60, 60, 0, 0, 0 };
        for (int r = 1; r <= 20; ++r) {
            AP::SpaceShape s;
            AP::chamberShapeFor(r, s);
            if (s.unusual != (r >= 18) || s.wFt != kChW[r] ||
                s.hFt != kChH[r]) ++bad;
        }
        static const int kRmW[18] = { 0,
            10, 10, 20, 20, 30, 30, 40, 40,
            10, 10, 20, 20, 20, 20, 20, 30, 30 };
        static const int kRmH[18] = { 0,
            10, 10, 20, 20, 30, 30, 40, 40,
            20, 20, 30, 30, 30, 40, 40, 40, 40 };
        for (int r = 1; r <= 17; ++r) {
            AP::SpaceShape s;
            if (!AP::roomShapeFor(r, s)) ++bad;
            else if (s.wFt != kRmW[r] || s.hFt != kRmH[r] ||
                     s.unusual) ++bad;
        }
        for (int r = 18; r <= 20; ++r) {
            AP::SpaceShape s;
            if (AP::roomShapeFor(r, s)) ++bad;   // blank
        }
        // TABLE V.A: unusual shape (p.171)
        static const AP::UnusualShape kUs[21] = {
            AP::US_CIRCULAR,
            AP::US_CIRCULAR, AP::US_CIRCULAR,
            AP::US_CIRCULAR, AP::US_CIRCULAR,
            AP::US_CIRCULAR,
            AP::US_TRIANGULAR, AP::US_TRIANGULAR,
            AP::US_TRIANGULAR,
            AP::US_TRAPEZOIDAL, AP::US_TRAPEZOIDAL,
            AP::US_TRAPEZOIDAL,
            AP::US_ODD, AP::US_ODD,
            AP::US_OVAL, AP::US_OVAL,
            AP::US_HEXAGONAL, AP::US_HEXAGONAL,
            AP::US_OCTAGONAL, AP::US_OCTAGONAL,
            AP::US_CAVE
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::unusualShapeFor(r) != kUs[r]) ++bad;
        for (int r = 1; r <= 5; ++r)
            if (AP::circularFeatureFor(r) != AP::CIRC_POOL) ++bad;
        for (int r = 6; r <= 7; ++r)
            if (AP::circularFeatureFor(r) != AP::CIRC_WELL) ++bad;
        for (int r = 8; r <= 10; ++r)
            if (AP::circularFeatureFor(r) != AP::CIRC_SHAFT) ++bad;
        for (int r = 11; r <= 20; ++r)
            if (AP::circularFeatureFor(r) != AP::CIRC_NORMAL) ++bad;
        // TABLE V.B: unusual size (p.171)
        static const int kUB[21] = { 0,
            500, 500, 500, 900, 900, 900, 1300, 1300,
            2000, 2000, 2700, 2700, 3400, 3400,
            -1, -1, -1, -1, -1, -1 };
        for (int r = 1; r <= 20; ++r)
            if (AP::unusualSizeBaseFor(r) != kUB[r]) ++bad;
        // TABLE V.C: number of exits (p.171)
        if (AP::exitsFor(1, false) != 1 || AP::exitsFor(3, true) != 2)
            ++bad;
        if (AP::exitsFor(4, false) != 2 || AP::exitsFor(6, true) != 3)
            ++bad;
        if (AP::exitsFor(7, false) != 3 || AP::exitsFor(9, true) != 4)
            ++bad;
        if (AP::exitsFor(10, false) != 0 || AP::exitsFor(12, true) != 1)
            ++bad;
        if (AP::exitsFor(13, false) != 0 || AP::exitsFor(15, true) != 1)
            ++bad;
        if (AP::exitsFor(16, false) != AP::kExitsRollD4 ||
            AP::exitsFor(18, true) != AP::kExitsRollD4) ++bad;
        if (AP::exitsFor(19, false) != 1 || AP::exitsFor(20, true) != 1)
            ++bad;
        // TABLE V.D: exit location (p.171)
        for (int r = 1; r <= 7; ++r)
            if (AP::exitLocationFor(r) != AP::EL_OPPOSITE) ++bad;
        for (int r = 8; r <= 12; ++r)
            if (AP::exitLocationFor(r) != AP::EL_LEFT) ++bad;
        for (int r = 13; r <= 17; ++r)
            if (AP::exitLocationFor(r) != AP::EL_RIGHT) ++bad;
        for (int r = 18; r <= 20; ++r)
            if (AP::exitLocationFor(r) != AP::EL_SAME) ++bad;
        // TABLE V.E: exit direction (p.171)
        for (int r = 1; r <= 16; ++r)
            if (AP::exitDirectionFor(r) != AP::ED_STRAIGHT) ++bad;
        for (int r = 17; r <= 18; ++r)
            if (AP::exitDirectionFor(r) != AP::ED_45_LR) ++bad;
        for (int r = 19; r <= 20; ++r)
            if (AP::exitDirectionFor(r) != AP::ED_45_RL) ++bad;
        // TABLE V.F: room contents (p.171)
        static const dm::RoomContents kRC[21] = {
            dm::ROOM_EMPTY,
            dm::ROOM_EMPTY, dm::ROOM_EMPTY, dm::ROOM_EMPTY,
            dm::ROOM_EMPTY, dm::ROOM_EMPTY, dm::ROOM_EMPTY,
            dm::ROOM_EMPTY, dm::ROOM_EMPTY, dm::ROOM_EMPTY,
            dm::ROOM_EMPTY, dm::ROOM_EMPTY, dm::ROOM_EMPTY,
            dm::ROOM_MONSTER, dm::ROOM_MONSTER,
            dm::ROOM_MONSTER_TREASURE,
            dm::ROOM_MONSTER_TREASURE,
            dm::ROOM_MONSTER_TREASURE,
            dm::ROOM_SPECIAL, dm::ROOM_TRAP, dm::ROOM_TREASURE
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::roomContentsFor(r) != kRC[r]) ++bad;
        // the contents-18 stairway variant (the book's
        // print skips band 6 - pinned as printed)
        for (int r = 1; r <= 6; ++r)
            if (AP::stairwayVariantFor(r) != AP::SV_UP1) ++bad;
        for (int r = 7; r <= 8; ++r)
            if (AP::stairwayVariantFor(r) != AP::SV_UP2) ++bad;
        for (int r = 9; r <= 14; ++r)
            if (AP::stairwayVariantFor(r) != AP::SV_DOWN1) ++bad;
        for (int r = 15; r <= 19; ++r)
            if (AP::stairwayVariantFor(r) != AP::SV_DOWN2) ++bad;
        if (AP::stairwayVariantFor(20) != AP::SV_DOWN3) ++bad;
        // TABLE V.G: treasure by level (p.171, d%)
        for (int r = 1; r <= 100; ++r) {
            AP::TreasureRow t = AP::treasureFor(r);
            AP::TreasureKind ek;
            int eb = 0;
            if (r <= 25)      { ek = AP::TR_CP; eb = 1000; }
            else if (r <= 50) { ek = AP::TR_SP; eb = 1000; }
            else if (r <= 65) { ek = AP::TR_EP; eb = 750; }
            else if (r <= 80) { ek = AP::TR_GP; eb = 250; }
            else if (r <= 90) { ek = AP::TR_PP; eb = 100; }
            else if (r <= 94) { ek = AP::TR_GEMS; eb = 1; }
            else if (r <= 97) { ek = AP::TR_JEWELRY; eb = 1; }
            else              { ek = AP::TR_MAGIC; }
            if (t.kind != ek || t.basePerLevel != eb) ++bad;
        }
        // TABLE V.H: containers (p.171)
        static const AP::Container kCn[21] = {
            AP::C_LOOSE,
            AP::C_BAGS, AP::C_BAGS,
            AP::C_SACKS, AP::C_SACKS,
            AP::C_SMALL_COFFERS, AP::C_SMALL_COFFERS,
            AP::C_CHESTS, AP::C_CHESTS,
            AP::C_HUGE_CHESTS, AP::C_HUGE_CHESTS,
            AP::C_POTTERY_JARS, AP::C_POTTERY_JARS,
            AP::C_METAL_URNS, AP::C_METAL_URNS,
            AP::C_STONE_CONTAINERS, AP::C_STONE_CONTAINERS,
            AP::C_IRON_TRUNKS, AP::C_IRON_TRUNKS,
            AP::C_LOOSE, AP::C_LOOSE
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::containerFor(r) != kCn[r]) ++bad;
        for (int r = 1; r <= 8; ++r)
            if (!AP::containerGuarded(r)) ++bad;
        for (int r = 9; r <= 20; ++r)
            if (AP::containerGuarded(r)) ++bad;
        // TABLE V.I: guarded by (p.171)
        static const AP::Guard kGd[21] = {
            AP::G_SYMBOL,
            AP::G_CONTACT_POISON_CONTAINER,
            AP::G_CONTACT_POISON_CONTAINER,
            AP::G_CONTACT_POISON_TREASURE,
            AP::G_CONTACT_POISON_TREASURE,
            AP::G_NEEDLES_LOCK, AP::G_NEEDLES_LOCK,
            AP::G_NEEDLES_HANDLES,
            AP::G_DARTS_FRONT,
            AP::G_DARTS_TOP,
            AP::G_DARTS_BOTTOM,
            AP::G_BLADE_SCYTHE, AP::G_BLADE_SCYTHE,
            AP::G_CREATURES,
            AP::G_GAS,
            AP::G_TRAPDOOR_FRONT,
            AP::G_TRAPDOOR_6FT,
            AP::G_STONE_BLOCK,
            AP::G_SPEARS,
            AP::G_EXPLOSIVE_RUNES,
            AP::G_SYMBOL
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::guardedByFor(r) != kGd[r]) ++bad;
        // TABLE V.J: hidden by/in (p.171)
        static const AP::Hidden kHd[21] = {
            AP::H_SECRET_ROOM,
            AP::H_INVISIBILITY, AP::H_INVISIBILITY,
            AP::H_INVISIBILITY,
            AP::H_ILLUSION, AP::H_ILLUSION,
            AP::H_SECRET_SPACE_UNDER,
            AP::H_SECRET_COMPARTMENT, AP::H_SECRET_COMPARTMENT,
            AP::H_ORDINARY_ITEM,
            AP::H_DISGUISED,
            AP::H_TRASH_DUNG,
            AP::H_LOOSE_FLOOR_STONE, AP::H_LOOSE_FLOOR_STONE,
            AP::H_LOOSE_WALL_STONE, AP::H_LOOSE_WALL_STONE,
            AP::H_SECRET_ROOM, AP::H_SECRET_ROOM,
            AP::H_SECRET_ROOM, AP::H_SECRET_ROOM,
            AP::H_SECRET_ROOM
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::hiddenByFor(r) != kHd[r]) ++bad;
        // TABLE VI: stairs (p.172)
        static const AP::StairKind kSt[21] = {
            AP::ST_UP1_DOWN2,
            AP::ST_DOWN1, AP::ST_DOWN1, AP::ST_DOWN1,
            AP::ST_DOWN1, AP::ST_DOWN1,
            AP::ST_DOWN2,
            AP::ST_DOWN3,
            AP::ST_UP1,
            AP::ST_UP_DEAD,
            AP::ST_DOWN_DEAD,
            AP::ST_CHIMNEY_UP1,
            AP::ST_CHIMNEY_UP2,
            AP::ST_CHIMNEY_DOWN2,
            AP::ST_TRAPDOOR_DOWN1, AP::ST_TRAPDOOR_DOWN1,
            AP::ST_TRAPDOOR_DOWN1,
            AP::ST_TRAPDOOR_DOWN2,
            AP::ST_UP1_DOWN2, AP::ST_UP1_DOWN2,
            AP::ST_UP1_DOWN2
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::stairsFor(r) != kSt[r]) ++bad;
        if (AP::stairEgressDoorIn20(AP::ST_DOWN1) != 1 ||
            AP::stairEgressDoorIn20(AP::ST_DOWN2) != 2 ||
            AP::stairEgressDoorIn20(AP::ST_DOWN3) != 3) ++bad;
        if (AP::stairEgressDoorIn20(AP::ST_UP1) != 0) ++bad;
        // TABLE VII: trick/trap (p.172)
        static const AP::TrickTrap kTt[21] = {
            AP::TT_CHUTE,
            AP::TT_SECRET_DOOR, AP::TT_SECRET_DOOR,
            AP::TT_SECRET_DOOR, AP::TT_SECRET_DOOR,
            AP::TT_SECRET_DOOR,
            AP::TT_PIT, AP::TT_PIT,
            AP::TT_PIT_SPIKED,
            AP::TT_ELEVATOR_DOWN1,
            AP::TT_ELEVATOR_DOWN2,
            AP::TT_ELEVATOR_2TO5,
            AP::TT_SLIDING_WALL,
            AP::TT_OIL_CINDER,
            AP::TT_PIT_CRUSHING,
            AP::TT_ARROW_TRAP,
            AP::TT_SPEAR_TRAP,
            AP::TT_GAS,
            AP::TT_FALLING_DOOR_STONE,
            AP::TT_ILLUSIONARY_WALL,
            AP::TT_CHUTE
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::trickTrapFor(r) != kTt[r]) ++bad;
        // TABLE VII.A: gas (p.172)
        static const AP::GasKind kGs[21] = {
            AP::GAS_POISON,
            AP::GAS_OBSCURE, AP::GAS_OBSCURE,
            AP::GAS_OBSCURE, AP::GAS_OBSCURE,
            AP::GAS_OBSCURE, AP::GAS_OBSCURE,
            AP::GAS_OBSCURE,
            AP::GAS_BLIND, AP::GAS_BLIND,
            AP::GAS_FEAR, AP::GAS_FEAR, AP::GAS_FEAR,
            AP::GAS_SLEEP,
            AP::GAS_STRENGTH, AP::GAS_STRENGTH,
            AP::GAS_STRENGTH, AP::GAS_STRENGTH,
            AP::GAS_STRENGTH,
            AP::GAS_SICKNESS,
            AP::GAS_POISON
        };
        for (int r = 1; r <= 20; ++r)
            if (AP::gasFor(r) != kGs[r]) ++bad;
        // TABLE VIII: caves and caverns (p.172)
        static const int kCvW[21] = { 0,
            40, 40, 40, 40, 40, 50, 50,
            20, 20, 35, 35, 95, 95, 95, 120, 120, 150, 150,
            275, 275 };
        static const int kCvH[21] = { 0,
            60, 60, 60, 60, 60, 75, 75,
            30, 30, 50, 50, 125, 125, 125, 150, 150,
            200, 200, 375, 375 };
        static const int kCvW2[21] = { 0,
            0, 0, 0, 0, 0, 0, 0,
            60, 60, 80, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        static const int kCvH2[21] = { 0,
            0, 0, 0, 0, 0, 0, 0,
            60, 60, 90, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        static const bool kCvP[21] = { false,
            false, false, false, false, false, false, false,
            false, false, true, true, true, true, true,
            false, false, true, true, false, false };
        static const bool kCvL[21] = { false,
            false, false, false, false, false, false, false,
            false, false, false, false, false, false,
            false, false, false, false, false,
            true, true };
        for (int r = 1; r <= 20; ++r) {
            AP::CaveSize c = AP::caveFor(r);
            if (c.wFt != kCvW[r] || c.hFt != kCvH[r] ||
                c.w2Ft != kCvW2[r] || c.h2Ft != kCvH2[r] ||
                c.pool != kCvP[r] || c.lake != kCvL[r]) ++bad;
        }
        // TABLE VIII.A: pools (p.172)
        for (int r = 1; r <= 8; ++r)
            if (AP::poolFor(r) != AP::POOL_NONE) ++bad;
        for (int r = 9; r <= 10; ++r)
            if (AP::poolFor(r) != AP::POOL_NO_MONSTER) ++bad;
        for (int r = 11; r <= 12; ++r)
            if (AP::poolFor(r) != AP::POOL_MONSTER) ++bad;
        for (int r = 13; r <= 18; ++r)
            if (AP::poolFor(r) != AP::POOL_MONSTER_TREASURE) ++bad;
        for (int r = 19; r <= 20; ++r)
            if (AP::poolFor(r) != AP::POOL_MAGICAL) ++bad;
        // TABLE VIII.B: lakes (p.172)
        for (int r = 1; r <= 10; ++r)
            if (AP::lakeFor(r) != AP::LAKE_NONE) ++bad;
        for (int r = 11; r <= 15; ++r)
            if (AP::lakeFor(r) != AP::LAKE_NO_MONSTERS) ++bad;
        for (int r = 16; r <= 18; ++r)
            if (AP::lakeFor(r) != AP::LAKE_MONSTERS) ++bad;
        for (int r = 19; r <= 20; ++r)
            if (AP::lakeFor(r) != AP::LAKE_ENCHANTED) ++bad;
        // TABLE VIII.C: magic pools (p.172)
        for (int r = 1; r <= 8; ++r)
            if (AP::magicPoolFor(r) != AP::MP_GOLD_TO_PLATINUM_LEAD)
                ++bad;
        for (int r = 9; r <= 15; ++r)
            if (AP::magicPoolFor(r) != AP::MP_CHARACTERISTIC) ++bad;
        for (int r = 16; r <= 17; ++r)
            if (AP::magicPoolFor(r) != AP::MP_TALKING) ++bad;
        for (int r = 18; r <= 20; ++r)
            if (AP::magicPoolFor(r) != AP::MP_TRANSPORTER) ++bad;
        for (int r = 1; r <= 11; ++r)
            if (!AP::goldBecomesPlatinum(r)) ++bad;
        for (int r = 12; r <= 20; ++r)
            if (AP::goldBecomesPlatinum(r)) ++bad;
        for (int r = 1; r <= 6; ++r)
            if (AP::talkingPoolAlignmentFor(r) != AP::PA_LAWFUL_GOOD)
                ++bad;
        for (int r = 7; r <= 9; ++r)
            if (AP::talkingPoolAlignmentFor(r) != AP::PA_LAWFUL_EVIL)
                ++bad;
        for (int r = 10; r <= 12; ++r)
            if (AP::talkingPoolAlignmentFor(r) != AP::PA_CHAOTIC_GOOD)
                ++bad;
        for (int r = 13; r <= 17; ++r)
            if (AP::talkingPoolAlignmentFor(r) != AP::PA_CHAOTIC_EVIL)
                ++bad;
        for (int r = 18; r <= 20; ++r)
            if (AP::talkingPoolAlignmentFor(r) != AP::PA_NEUTRAL)
                ++bad;
        for (int r = 1; r <= 7; ++r)
            if (AP::transportDestFor(r) != AP::TD_SURFACE) ++bad;
        for (int r = 8; r <= 12; ++r)
            if (AP::transportDestFor(r) != AP::TD_ELSEWHERE_LEVEL)
                ++bad;
        for (int r = 13; r <= 16; ++r)
            if (AP::transportDestFor(r) != AP::TD_ONE_DOWN) ++bad;
        for (int r = 17; r <= 20; ++r)
            if (AP::transportDestFor(r) != AP::TD_100_MILES) ++bad;
        // the walk's four wired helpers follow the
        // pinned bands, and the generator still carves
        {
            rules::Rng rng(20241002u);
            rules::Dice dice(rng);
            int seen[dm::ROOM_CONTENTS_COUNT] = { 0 };
            for (int i = 0; i < 4000; ++i)
                ++seen[dm::rollRoomContents(dice)];
            for (int k = 0; k < dm::ROOM_CONTENTS_COUNT; ++k)
                if (seen[k] == 0) ++bad;
            for (int i = 0; i < 400; ++i) {
                int w = dm::rollPassageWidth(dice);
                if (w < 1 || w > 3) ++bad;
            }
            int seenF[dm::PASSAGE_FEATURE_COUNT] = { 0 };
            for (int i = 0; i < 4000; ++i)
                ++seenF[dm::rollPassageFeature(dice)];
            // Table I's carveable outcomes all appear;
            // cross is Table III data, not a Table I row
            if (seenF[dm::PASSAGE_STRAIGHT] == 0 ||
                seenF[dm::PASSAGE_TURN] == 0 ||
                seenF[dm::PASSAGE_T_JUNCTION] == 0 ||
                seenF[dm::PASSAGE_CHAMBER] == 0 ||
                seenF[dm::PASSAGE_DEAD_END] == 0) ++bad;
            for (int i = 0; i < 400; ++i) {
                int w, h;
                dm::rollRoomSize(dice, w, h);
                if (w < 1 || w > 4 || h < 1 || h > 4) ++bad;
            }
            dm::DungeonResult d = dm::generateDungeon(4242u);
            if (d.rooms.empty()) ++bad;
            for (const auto& r : d.rooms) {
                if (r.w < 1 || r.h < 1 || r.x < 0 || r.y < 0 ||
                    r.x + r.w > world::MAP_TILES_X ||
                    r.y + r.h > world::MAP_TILES_Y) ++bad;
                if (r.contents < dm::ROOM_EMPTY ||
                    r.contents >= dm::ROOM_CONTENTS_COUNT) ++bad;
            }
        }
        printf("R124 appendix A dressing audit: bad %d\n", bad);
        if (bad) return 1;
    }
