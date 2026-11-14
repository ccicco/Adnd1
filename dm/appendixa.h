// ============================================================================
// Adnd1 - dm/appendixa.h
// R124: DMG pp.169-172 - APPENDIX A, RANDOM
// R1046: the 32 band tables are registry-native
// (content/tables/appendixa/, the seam below);
// the printed cascades are gone from this header
// and the accessors read registry views. The
// enums and structs stay in-file as constants
// (the band identity API); the fall-through
// semantics stay verbatim.
// GENERATION - every table pinned row-by-row as pure
// data (inline accessors, no dice: the caller rolls;
// any table luck beyond a row is the caller's). The
// walking generator (dm/dungeon.cpp) consults these
// through the four helper rolls in dm/dm.cpp; the
// tables it does not yet render are pinned here for
// the future layers (terrain, tricks, encounters).
//
// The book's own prints, kept as printed:
//   - TABLE V.F's stairway variant reads "up 1 level
//     (1-5), up 2 levels (7-8)" - band 6 is not
//     covered on the printed page; the gap is folded
//     into up-1 (documented).
//   - TABLE V prints the ROOM column blank at 18-20
//     (the unusual shape/size sub-tables are
//     chamber-only); roomShapeFor reports the blank
//     and the walk re-rolls.
//   - TABLE III.B's footnotes carry the sub-chances:
//     streams bridged 75% (1-15); rivers bridged 50%
//     (1-10), boat 25% (11-15, either bank 50%),
//     obstacle 25%; chasms 150'-200' deep, bridged
//     50%, jumping place 5'-10' 25% (11-15),
//     obstacle 25% - pinned as the feature accessors
//     below.
// ============================================================================

#pragma once

#include "dm.h"   // dm::RoomContents
#include "items/MiscItemRegistry.h"   // R1046: the dressing bands ride
                                     // the registry

namespace dm {
namespace appendixa {

// ---- the R1046 registry seam ----------------------------------------
// The 32 Appendix A dressing band tables
// ride items::MiscItemRegistry from
// content/tables/appendixa/ (def keys
// appendixa_*). Row encoding: name the
// enum tag or the synthetic tag, band the
// printed roll band, and the shape payload
// in gp/gpHi/xp/xpHi/qty (qty[1] the enum
// ordinal - cascade order is not enum
// order; the RoomContents lesson). This
// seam is header-only (the R1040-R1045
// idiom); every accessor signature below
// is unchanged (the r124 audit and dm.cpp
// pin them); the enums and structs stay
// in-file as constants and the fall-through
// semantics (under the first band -> row
// 0, past the last -> the last row) are
// reproduced verbatim by the band scan.
// The one-threshold helpers stay in-file
// constants (the R1044 subclass-scalar
// ruling): streamBridged,
// containerGuarded, goldBecomesPlatinum,
// stairEgressDoorIn20, kExitsRollD4.

inline items::MiscItemRegistry& aaReg() {
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory("content/tables/appendixa");
    }
    return reg;
}

// the registry-backed per-view cache (the
// R1032-R1045 idiom; function-local statics in
// inline functions are shared across TUs)
inline const std::vector<items::MiscItemRow>&
aaView(const char* name) {
    static std::map<std::string,
        std::vector<items::MiscItemRow>> cache;
    auto it = cache.find(name);
    if (it == cache.end()) {
        const items::MiscItemDef* d =
            aaReg().find(name);
        it = cache.emplace(
            name, d ? d->rows
                   : std::vector<items::MiscItemRow>()).first;
    }
    return it->second;
}

// ---- TABLE I.: PERIODIC CHECK (p.170, d20) ---------------------------------
enum PassageCheck {
    PC_STRAIGHT = 0,   // 1-2: continue, check again in 60'
    PC_DOOR,           // 3-5: see TABLE II.
    PC_SIDE,           // 6-10: side passage, check again in 30'
    PC_TURN,           // 11-13: check width on TABLE III.A.
    PC_CHAMBER,        // 14-16: check 30' after leaving
    PC_STAIRS,         // 17: see TABLE VI.
    PC_DEAD_END,       // 18: walls can hide secret doors
    PC_TRICK_TRAP,     // 19: see TABLE VII., passage continues
    PC_WANDERER,       // 20: check again immediately
    PC_COUNT
};

inline PassageCheck passageCheckFor(int r) {
    const auto& rows = aaView("appendixa_periodic_check");
    if (rows.empty())
        return PC_STRAIGHT;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return PassageCheck(rows[i].qtyLo);
    return PassageCheck(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE II.: DOORS (p.170, d20, both halves) ----------------------------
enum DoorLocation {
    DL_LEFT = 0,   // 1-6
    DL_RIGHT,     // 7-12
    DL_AHEAD      // 13-20
};

inline DoorLocation doorLocationFor(int r) {
    const auto& rows = aaView("appendixa_door_location");
    if (rows.empty())
        return DL_LEFT;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return DoorLocation(rows[i].qtyLo);
    return DoorLocation(rows[(int)rows.size() - 1]
.qtyLo);
}


enum SpaceBeyond {
    SB_PARALLEL = 0,   // 1-4: parallel passage (30' both
                       // ways), or 10'x10' room if the
                       // door is straight ahead
    SB_STRAIGHT_AHEAD, // 5-8
    SB_45_AHEAD,       // 9: 45 degrees ahead/behind
    SB_45_BEHIND,      // 10: 45 degrees behind/ahead
    SB_ROOM,           // 11-18: go to TABLE V.
    SB_CHAMBER         // 19-20: go to TABLE V.
};

inline SpaceBeyond spaceBeyondFor(int r) {
    const auto& rows = aaView("appendixa_space_beyond");
    if (rows.empty())
        return SB_PARALLEL;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return SpaceBeyond(rows[i].qtyLo);
    return SpaceBeyond(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE III.: SIDE PASSAGES (p.170, d20) --------------------------------
enum SidePassage {
    SP_L90 = 0,   // 1-2
    SP_R90,       // 3-4
    SP_L45_AHEAD,   // 5
    SP_R45_AHEAD,   // 6
    SP_L45_BEHIND,  // 7: left 135 degrees
    SP_R45_BEHIND,  // 8: right 135 degrees
    SP_L_CURVE,     // 9: left curve 45 degrees ahead
    SP_R_CURVE,     // 10: right curve 45 degrees ahead
    SP_T,           // 11-13: passage "T"s
    SP_Y,           // 14-15: passage "Y"s
    SP_FOURWAY,     // 16-19: four-way intersection
    SP_X,           // 20: passage "X"s
    SP_COUNT
};

inline SidePassage sidePassageFor(int r) {
    const auto& rows = aaView("appendixa_side_passage");
    if (rows.empty())
        return SP_L90;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return SidePassage(rows[i].qtyLo);
    return SidePassage(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE III.A.: PASSAGE WIDTH (p.170, d20) ------------------------------
// Feet; -1 = SPECIAL PASSAGE (TABLE III.B. below).
inline int passageWidthFeetFor(int r) {
    const auto& rows = aaView("appendixa_passage_width");
    if (rows.empty())
        return 10;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return rows[i].gp;
    return rows[(int)rows.size() - 1].gp;
}


// ---- TABLE III.B.: SPECIAL PASSAGE (p.170, d20) -----------------------------
enum SpecialPassage {
    SPEC_COLUMNS_CENTER = 0,   // 1-4: 40', columns down center
    SPEC_COLUMNS_DOUBLE,      // 5-7: 40', double row; 8-10: 50'
    SPEC_COLUMNS_GALLERIES,   // 11-12: 50', columns support
                              // 10' galleries 20' above
    SPEC_STREAM,              // 13-15: 10' stream
    SPEC_RIVER,               // 16-17: 20'; 18: 40'; 19: 60'
    SPEC_CHASM,               // 20: 20', 150'-200' deep
    SPEC_COUNT
};

struct SpecialPass {
    SpecialPassage kind;
    int widthFt;
};

inline SpecialPass specialPassageFor(int r) {
    SpecialPass s;
    s.widthFt = 0;
    s.kind = SPEC_COLUMNS_CENTER;   // defensive
    const auto& rows = aaView("appendixa_special_passage");
    if (!rows.empty()) {
        int i = 0;
        for (; i < (int)rows.size(); ++i)
            if (r <= rows[i].bandHi) break;
        if (i >= (int)rows.size())
            i = (int)rows.size() - 1;
        s.kind = SpecialPassage(rows[i].qtyLo);
        s.widthFt = rows[i].gp;
    }
    return s;
}


// the III.B footnotes' sub-chances (d20 rolls of their own)
inline bool streamBridged(int r) {   // 75%: 1-15
    return r <= 15;
}

enum WaterFeature {
    WF_BRIDGED = 0,   // rivers: 1-10; chasms: 1-10
    WF_BOAT,          // rivers: 11-15 (either bank 50%)
    WF_OBSTACLE       // 16-20
};

inline WaterFeature riverFeature(int r) {
    const auto& rows = aaView("appendixa_river_feature");
    if (rows.empty())
        return WF_BRIDGED;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return WaterFeature(rows[i].qtyLo);
    return WaterFeature(rows[(int)rows.size() - 1]
.qtyLo);
}


enum ChasmFeature {
    CF_BRIDGED = 0,   // 1-10
    CF_JUMPING,       // 11-15: a jumping place 5'-10' wide
    CF_OBSTACLE       // 16-20
};

inline ChasmFeature chasmFeature(int r) {
    const auto& rows = aaView("appendixa_chasm_feature");
    if (rows.empty())
        return CF_BRIDGED;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return ChasmFeature(rows[i].qtyLo);
    return ChasmFeature(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE IV.: TURNS (p.170, d20) -----------------------------------------
enum TurnKind {
    T_L90 = 0,        // 1-8
    T_L45_AHEAD,      // 9
    T_L45_BEHIND,     // 10: left 135 degrees
    T_R90,            // 11-18
    T_R45_AHEAD,      // 19
    T_R45_BEHIND      // 20: right 135 degrees
};

inline TurnKind turnFor(int r) {
    const auto& rows = aaView("appendixa_turn");
    if (rows.empty())
        return T_L90;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return TurnKind(rows[i].qtyLo);
    return TurnKind(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE V.: CHAMBERS AND ROOMS SHAPE AND SIZE (p.171, d20) --------------
struct SpaceShape {
    int wFt = 0, hFt = 0;
    bool unusual = false;
};

// The chamber column (18-20 = unusual -> V.A./V.B.).
inline void chamberShapeFor(int r, SpaceShape& s) {
    s.wFt = 0; s.hFt = 0; s.unusual = false;
    const auto& rows = aaView("appendixa_chamber_shape");
    if (rows.empty()) {
        return;   // defensive
    }
    int i = 0;
    for (; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi) break;
    if (i >= (int)rows.size())
        i = (int)rows.size() - 1;
    s.wFt = rows[i].gp;
    s.hFt = rows[i].gpHi;
    s.unusual = rows[i].qtyLo != 0;
}


// The room column; false = the book prints it blank
// at 18-20 (unusual is chamber-only) - re-roll.
inline bool roomShapeFor(int r, SpaceShape& s) {
    s.wFt = 0; s.hFt = 0; s.unusual = false;
    const auto& rows = aaView("appendixa_room_shape");
    if (rows.empty()) {
        s.wFt = 10; s.hFt = 10;
        return true;   // defensive: a load
        // failure must never hang the dm.cpp
        // re-roll while-loop (10'x10' room)
    }
    int i = 0;
    for (; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi) break;
    if (i >= (int)rows.size())
        i = (int)rows.size() - 1;
    if (rows[i].name == "RMS_BLANK")   // 18-20: blank
        return false;   // in the book - re-roll
    s.wFt = rows[i].gp;
    s.hFt = rows[i].gpHi;
    s.unusual = rows[i].qtyLo != 0;
    return true;
}


// ---- TABLE V.A.: UNUSUAL SHAPE (p.171, d20) --------------------------------
enum UnusualShape {
    US_CIRCULAR = 0,   // 1-5
    US_TRIANGULAR,     // 6-8
    US_TRAPEZOIDAL,    // 9-11
    US_ODD,            // 12-13: draw what fits
    US_OVAL,           // 14-15
    US_HEXAGONAL,      // 16-17
    US_OCTAGONAL,      // 18-19
    US_CAVE            // 20
};

inline UnusualShape unusualShapeFor(int r) {
    const auto& rows = aaView("appendixa_unusual_shape");
    if (rows.empty())
        return US_CIRCULAR;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return UnusualShape(rows[i].qtyLo);
    return UnusualShape(rows[(int)rows.size() - 1]
.qtyLo);
}


// the circular chamber's own d20: 1-5 pool,
// 6-7 well, 8-10 shaft, 11-20 normal
enum CircularFeature {
    CIRC_POOL = 0, CIRC_WELL, CIRC_SHAFT, CIRC_NORMAL
};

inline CircularFeature circularFeatureFor(int r) {
    const auto& rows = aaView("appendixa_circular_feature");
    if (rows.empty())
        return CIRC_POOL;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return CircularFeature(rows[i].qtyLo);
    return CircularFeature(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE V.B.: UNUSUAL SIZE (p.171, d20) ---------------------------------
// Square feet; -1 = the 15-20 rule: roll again
// and add the result to the 9-10 row (2000),
// repeating on another 15-20.
inline int unusualSizeBaseFor(int r) {
    const auto& rows = aaView("appendixa_unusual_size");
    if (rows.empty())
        return 500;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return rows[i].gp;
    return rows[(int)rows.size() - 1].gp;
}


// ---- TABLE V.C.: NUMBER OF EXITS (p.171, d20) ------------------------------
// overThreshold: the room area is over the row's
// threshold. kExitsRollD4 = roll d4 (the 16-18 row).
const int kExitsRollD4 = -1;

inline int exitsFor(int r, bool overThreshold) {
    const auto& rows = aaView("appendixa_exits");
    if (rows.empty())
        return overThreshold ? 2 : 1;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return overThreshold ? rows[i].gpHi
                              : rows[i].gp;
    return overThreshold
        ? rows[(int)rows.size() - 1].gpHi
        : rows[(int)rows.size() - 1].gp;
}


// ---- TABLE V.D.: EXIT LOCATION (p.171, d20) --------------------------------
enum ExitLocation {
    EL_OPPOSITE = 0,   // 1-7
    EL_LEFT,           // 8-12
    EL_RIGHT,          // 13-17
    EL_SAME            // 18-20
};

inline ExitLocation exitLocationFor(int r) {
    const auto& rows = aaView("appendixa_exit_location");
    if (rows.empty())
        return EL_OPPOSITE;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return ExitLocation(rows[i].qtyLo);
    return ExitLocation(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE V.E.: EXIT DIRECTION (p.171, d20) --------------------------------
enum ExitDirection {
    ED_STRAIGHT = 0,   // 1-16
    ED_45_LR,          // 17-18: left/right
    ED_45_RL           // 19-20: right/left
};

inline ExitDirection exitDirectionFor(int r) {
    const auto& rows = aaView("appendixa_exit_direction");
    if (rows.empty())
        return ED_STRAIGHT;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return ExitDirection(rows[i].qtyLo);
    return ExitDirection(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE V.F.: CHAMBER OR ROOM CONTENTS (p.171, d20) ----------------------
// The repo's dm::RoomContents; 19 = trick/trap, 20
// = treasure.
inline RoomContents roomContentsFor(int r) {
    const auto& rows = aaView("appendixa_room_contents");
    if (rows.empty())
        return ROOM_EMPTY;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return RoomContents(rows[i].qtyLo);
    return RoomContents(rows[(int)rows.size() - 1]
.qtyLo);
}


// the contents-18 stairway variant (its own d20). The
// book's print covers 1-5, 7-8, 9-14, 15-19, 20 -
// band 6 is uncovered on the page; the gap is folded
// into up-1 (documented).
enum StairVariant {
    SV_UP1 = 0, SV_UP2, SV_DOWN1, SV_DOWN2, SV_DOWN3
};

inline StairVariant stairwayVariantFor(int r) {
    const auto& rows = aaView("appendixa_stairway_variant");
    if (rows.empty())
        return SV_UP1;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return StairVariant(rows[i].qtyLo);
    return StairVariant(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE V.G.: TREASURE (p.171, d%) --------------------------------------
// Without monster. With monster: two rolls on this
// table, +10% to the total of each roll (the book's
// optional +1% per dungeon level rides the caller).
enum TreasureKind {
    TR_CP = 0, TR_SP, TR_EP, TR_GP, TR_PP,
    TR_GEMS, TR_JEWELRY, TR_MAGIC
};

struct TreasureRow {
    TreasureKind kind;
    int basePerLevel;   // coins: pieces/level; gems:
                        // 1-4/level (base 1); jewelry: 1
};

inline TreasureRow treasureFor(int r) {
    TreasureRow t;
    t.kind = TR_CP;
    t.basePerLevel = 0;
    const auto& rows = aaView("appendixa_treasure");
    if (!rows.empty()) {
        int i = 0;
        for (; i < (int)rows.size(); ++i)
            if (r <= rows[i].bandHi) break;
        if (i >= (int)rows.size())
            i = (int)rows.size() - 1;
        t.kind = TreasureKind(rows[i].qtyLo);
        t.basePerLevel = rows[i].gp;
    }
    return t;
}


// ---- TABLE V.H.: TREASURE IS CONTAINED IN (p.171, d20) ---------------------
enum Container {
    C_BAGS = 0,          // 1-2
    C_SACKS,             // 3-4
    C_SMALL_COFFERS,     // 5-6
    C_CHESTS,            // 7-8
    C_HUGE_CHESTS,       // 9-10
    C_POTTERY_JARS,      // 11-12
    C_METAL_URNS,        // 13-14
    C_STONE_CONTAINERS,  // 15-16
    C_IRON_TRUNKS,       // 17-18
    C_LOOSE              // 19-20
};

inline Container containerFor(int r) {
    const auto& rows = aaView("appendixa_container");
    if (rows.empty())
        return C_BAGS;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return Container(rows[i].qtyLo);
    return Container(rows[(int)rows.size() - 1]
.qtyLo);
}


// the V.H footnote: 1-8 -> guarded (V.I.),
// 9-20 -> hidden (V.J.)
inline bool containerGuarded(int r) { return r <= 8; }

// ---- TABLE V.I.: TREASURE IS GUARDED BY (p.171, d20) -----------------------
enum Guard {
    G_CONTACT_POISON_CONTAINER = 0,   // 1-2
    G_CONTACT_POISON_TREASURE,        // 3-4
    G_NEEDLES_LOCK,                  // 5-6
    G_NEEDLES_HANDLES,               // 7
    G_DARTS_FRONT,                   // 8
    G_DARTS_TOP,                     // 9
    G_DARTS_BOTTOM,                  // 10
    G_BLADE_SCYTHE,                  // 11-12
    G_CREATURES,                     // 13: insects/reptiles
    G_GAS,                           // 14
    G_TRAPDOOR_FRONT,               // 15
    G_TRAPDOOR_6FT,                 // 16
    G_STONE_BLOCK,                  // 17
    G_SPEARS,                       // 18
    G_EXPLOSIVE_RUNES,              // 19
    G_SYMBOL                        // 20
};

inline Guard guardedByFor(int r) {
    const auto& rows = aaView("appendixa_guard");
    if (rows.empty())
        return G_CONTACT_POISON_CONTAINER;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return Guard(rows[i].qtyLo);
    return Guard(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE V.J.: TREASURE IS HIDDEN BY/IN (p.171, d20) ---------------------
enum Hidden {
    H_INVISIBILITY = 0,     // 1-3
    H_ILLUSION,             // 4-5
    H_SECRET_SPACE_UNDER,   // 6
    H_SECRET_COMPARTMENT,   // 7-8
    H_ORDINARY_ITEM,        // 9
    H_DISGUISED,            // 10
    H_TRASH_DUNG,           // 11
    H_LOOSE_FLOOR_STONE,    // 12-13
    H_LOOSE_WALL_STONE,     // 14-15
    H_SECRET_ROOM           // 16-20
};

inline Hidden hiddenByFor(int r) {
    const auto& rows = aaView("appendixa_hidden");
    if (rows.empty())
        return H_INVISIBILITY;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return Hidden(rows[i].qtyLo);
    return Hidden(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE VI.: STAIRS (p.172, d20) ----------------------------------------
enum StairKind {
    ST_DOWN1 = 0,        // 1-5: egress door 1 in 20
    ST_DOWN2,            // 6: 2 in 20
    ST_DOWN3,            // 7: 3 in 20
    ST_UP1,              // 8
    ST_UP_DEAD,          // 9: 1 in 6 chute down 2
    ST_DOWN_DEAD,        // 10: 1 in 6 chute down 1
    ST_CHIMNEY_UP1,      // 11
    ST_CHIMNEY_UP2,      // 12
    ST_CHIMNEY_DOWN2,    // 13
    ST_TRAPDOOR_DOWN1,   // 14-16
    ST_TRAPDOOR_DOWN2,   // 17
    ST_UP1_DOWN2         // 18-20: total down 1,
                         // chamber at end
};

inline StairKind stairsFor(int r) {
    const auto& rows = aaView("appendixa_stairs");
    if (rows.empty())
        return ST_DOWN1;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return StairKind(rows[i].qtyLo);
    return StairKind(rows[(int)rows.size() - 1]
.qtyLo);
}


// the VI footnote: a door closes egress for the
// day - 1, 2, 3 in 20 on the three down stairs
inline int stairEgressDoorIn20(StairKind k) {
    if (k == ST_DOWN1) return 1;
    if (k == ST_DOWN2) return 2;
    if (k == ST_DOWN3) return 3;
    return 0;
}

// ---- TABLE VII.: TRICK/TRAP (p.172, d20) ------------------------------------
enum TrickTrap {
    TT_SECRET_DOOR = 0,    // 1-5: non-elf 3 in 20, elf
                           // 5, device 18; unlocated
                           // -> 6-7
    TT_PIT,                // 6-7: 10' deep, 3 in 6
    TT_PIT_SPIKED,         // 8
    TT_ELEVATOR_DOWN1,     // 9: no ascent 30 turns
    TT_ELEVATOR_DOWN2,     // 10
    TT_ELEVATOR_2TO5,      // 11: no ascent 60 turns
    TT_SLIDING_WALL,       // 12: blocks 40-60 turns
    TT_OIL_CINDER,         // 13: 2-12 hp, save 1-3
    TT_PIT_CRUSHING,       // 14: crush in 2-5 rounds
    TT_ARROW_TRAP,         // 15: 1-3, 1 in 20 poisoned
    TT_SPEAR_TRAP,         // 16: 1-3, 1 in 20 poisoned
    TT_GAS,                // 17: see VII.A.
    TT_FALLING_DOOR_STONE, // 18: door 1-10, stone 2-20
    TT_ILLUSIONARY_WALL,   // 19: pit 1-6, chute 7-10,
                           // chamber 11-20
    TT_CHUTE               // 20: down 1, no ascent
};

inline TrickTrap trickTrapFor(int r) {
    const auto& rows = aaView("appendixa_trick_trap");
    if (rows.empty())
        return TT_SECRET_DOOR;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return TrickTrap(rows[i].qtyLo);
    return TrickTrap(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE VII.A.: GAS SUB-TABLE (p.172, d20) ------------------------------
enum GasKind {
    GAS_OBSCURE = 0,   // 1-7: obscures vision
    GAS_BLIND,         // 8-9: 1-6 turns
    GAS_FEAR,          // 10-12: run back 120' unless
                       // save vs. magic
    GAS_SLEEP,         // 13: 2-12 turns
    GAS_STRENGTH,      // 14-18: +1-6 to fighters,
                       // 1-10 hours
    GAS_SICKNESS,      // 19: return to surface
    GAS_POISON         // 20: save vs. poison or killed
};

inline GasKind gasFor(int r) {
    const auto& rows = aaView("appendixa_gas");
    if (rows.empty())
        return GAS_OBSCURE;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return GasKind(rows[i].qtyLo);
    return GasKind(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE VIII.: CAVES AND CAVERNS (p.172, d20) ----------------------------
struct CaveSize {
    int wFt = 0, hFt = 0;
    int w2Ft = 0, h2Ft = 0;   // the second of a double
    bool pool = false;        // roll VIII.A. within
    bool lake = false;        // roll VIII.B. within
};

inline CaveSize caveFor(int r) {
    CaveSize c;
    const auto& rows = aaView("appendixa_cave");
    if (rows.empty())
        return c;   // defensive
    int i = 0;
    for (; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi) break;
    if (i >= (int)rows.size())
        i = (int)rows.size() - 1;
    c.wFt = rows[i].gp;
    c.hFt = rows[i].gpHi;
    c.w2Ft = rows[i].xp;
    c.h2Ft = rows[i].xpHi;
    c.pool = rows[i].qtyLo != 0;
    c.lake = rows[i].qtyHi != 0;
    return c;
}


// ---- TABLE VIII.A.: POOLS (p.172, d20) -------------------------------------
enum PoolKind {
    POOL_NONE = 0,           // 1-8
    POOL_NO_MONSTER,         // 9-10
    POOL_MONSTER,            // 11-12
    POOL_MONSTER_TREASURE,   // 13-18
    POOL_MAGICAL             // 19-20: see VIII.C.
};

inline PoolKind poolFor(int r) {
    const auto& rows = aaView("appendixa_pool");
    if (rows.empty())
        return POOL_NONE;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return PoolKind(rows[i].qtyLo);
    return PoolKind(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE VIII.B.: LAKES (p.172, d20) --------------------------------------
enum LakeKind {
    LAKE_NONE = 0,       // 1-10
    LAKE_NO_MONSTERS,    // 11-15
    LAKE_MONSTERS,       // 16-18
    LAKE_ENCHANTED       // 19-20: leads elsewhere;
                         // a monster guards 90%
};

inline LakeKind lakeFor(int r) {
    const auto& rows = aaView("appendixa_lake");
    if (rows.empty())
        return LAKE_NONE;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return LakeKind(rows[i].qtyLo);
    return LakeKind(rows[(int)rows.size() - 1]
.qtyLo);
}


// ---- TABLE VIII.C.: MAGIC POOLS (p.172, d20) --------------------------------
enum MagicPool {
    MP_GOLD_TO_PLATINUM_LEAD = 0,   // 1-8: one time
    MP_CHARACTERISTIC,              // 9-15: +/- 1-3 on
                                     // a d6 stat
    MP_TALKING,                     // 16-17: 1 wish to
                                     // its aligned, 1-20
                                     // damage to others
    MP_TRANSPORTER                  // 18-20
};

inline MagicPool magicPoolFor(int r) {
    const auto& rows = aaView("appendixa_magic_pool");
    if (rows.empty())
        return MP_GOLD_TO_PLATINUM_LEAD;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return MagicPool(rows[i].qtyLo);
    return MagicPool(rows[(int)rows.size() - 1]
.qtyLo);
}


// the gold pool's own d20: platinum 1-11, lead 12-20
inline bool goldBecomesPlatinum(int r) { return r <= 11; }

// the talking pool's alignment (its own d20)
enum PoolAlignment {
    PA_LAWFUL_GOOD = 0,   // 1-6
    PA_LAWFUL_EVIL,       // 7-9
    PA_CHAOTIC_GOOD,      // 10-12
    PA_CHAOTIC_EVIL,      // 13-17
    PA_NEUTRAL            // 18-20
};

inline PoolAlignment talkingPoolAlignmentFor(int r) {
    const auto& rows = aaView("appendixa_talking_pool_alignment");
    if (rows.empty())
        return PA_LAWFUL_GOOD;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return PoolAlignment(rows[i].qtyLo);
    return PoolAlignment(rows[(int)rows.size() - 1]
.qtyLo);
}


// the transporter's destination (its own d20)
enum TransportDest {
    TD_SURFACE = 0,          // 1-7
    TD_ELSEWHERE_LEVEL,      // 8-12
    TD_ONE_DOWN,             // 13-16
    TD_100_MILES             // 17-20: outdoor adventure
};

inline TransportDest transportDestFor(int r) {
    const auto& rows = aaView("appendixa_transport_dest");
    if (rows.empty())
        return TD_SURFACE;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return TransportDest(rows[i].qtyLo);
    return TransportDest(rows[(int)rows.size() - 1]
.qtyLo);
}


} // namespace appendixa
} // namespace dm
