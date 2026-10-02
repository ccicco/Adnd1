// ============================================================================
// Adnd1 - dm/appendixa.h
// R124: DMG pp.169-172 - APPENDIX A, RANDOM DUNGEON
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

namespace dm {
namespace appendixa {

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
    if (r <= 2)  return PC_STRAIGHT;
    if (r <= 5)  return PC_DOOR;
    if (r <= 10) return PC_SIDE;
    if (r <= 13) return PC_TURN;
    if (r <= 16) return PC_CHAMBER;
    if (r == 17) return PC_STAIRS;
    if (r == 18) return PC_DEAD_END;
    if (r == 19) return PC_TRICK_TRAP;
    return PC_WANDERER;
}

// ---- TABLE II.: DOORS (p.170, d20, both halves) ----------------------------
enum DoorLocation {
    DL_LEFT = 0,   // 1-6
    DL_RIGHT,     // 7-12
    DL_AHEAD      // 13-20
};

inline DoorLocation doorLocationFor(int r) {
    if (r <= 6)  return DL_LEFT;
    if (r <= 12) return DL_RIGHT;
    return DL_AHEAD;
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
    if (r <= 4)  return SB_PARALLEL;
    if (r <= 8)  return SB_STRAIGHT_AHEAD;
    if (r == 9)  return SB_45_AHEAD;
    if (r == 10) return SB_45_BEHIND;
    if (r <= 18) return SB_ROOM;
    return SB_CHAMBER;
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
    if (r <= 2)  return SP_L90;
    if (r <= 4)  return SP_R90;
    if (r == 5)  return SP_L45_AHEAD;
    if (r == 6)  return SP_R45_AHEAD;
    if (r == 7)  return SP_L45_BEHIND;
    if (r == 8)  return SP_R45_BEHIND;
    if (r == 9)  return SP_L_CURVE;
    if (r == 10) return SP_R_CURVE;
    if (r <= 13) return SP_T;
    if (r <= 15) return SP_Y;
    if (r <= 19) return SP_FOURWAY;
    return SP_X;
}

// ---- TABLE III.A.: PASSAGE WIDTH (p.170, d20) ------------------------------
// Feet; -1 = SPECIAL PASSAGE (TABLE III.B. below).
inline int passageWidthFeetFor(int r) {
    if (r <= 12) return 10;
    if (r <= 16) return 20;
    if (r == 17) return 30;
    if (r == 18) return 5;
    return -1;
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
    if (r <= 4)  { s.kind = SPEC_COLUMNS_CENTER;   s.widthFt = 40; }
    else if (r <= 7)  { s.kind = SPEC_COLUMNS_DOUBLE; s.widthFt = 40; }
    else if (r <= 10) { s.kind = SPEC_COLUMNS_DOUBLE; s.widthFt = 50; }
    else if (r <= 12) { s.kind = SPEC_COLUMNS_GALLERIES; s.widthFt = 50; }
    else if (r <= 15) { s.kind = SPEC_STREAM;     s.widthFt = 10; }
    else if (r <= 17) { s.kind = SPEC_RIVER;      s.widthFt = 20; }
    else if (r == 18) { s.kind = SPEC_RIVER;      s.widthFt = 40; }
    else if (r == 19) { s.kind = SPEC_RIVER;      s.widthFt = 60; }
    else              { s.kind = SPEC_CHASM;      s.widthFt = 20; }
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
    if (r <= 10) return WF_BRIDGED;
    if (r <= 15) return WF_BOAT;
    return WF_OBSTACLE;
}

enum ChasmFeature {
    CF_BRIDGED = 0,   // 1-10
    CF_JUMPING,       // 11-15: a jumping place 5'-10' wide
    CF_OBSTACLE       // 16-20
};

inline ChasmFeature chasmFeature(int r) {
    if (r <= 10) return CF_BRIDGED;
    if (r <= 15) return CF_JUMPING;
    return CF_OBSTACLE;
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
    if (r <= 8)   return T_L90;
    if (r == 9)   return T_L45_AHEAD;
    if (r == 10)  return T_L45_BEHIND;
    if (r <= 18)  return T_R90;
    if (r == 19)  return T_R45_AHEAD;
    return T_R45_BEHIND;
}

// ---- TABLE V.: CHAMBERS AND ROOMS SHAPE AND SIZE (p.171, d20) --------------
struct SpaceShape {
    int wFt = 0, hFt = 0;
    bool unusual = false;
};

// The chamber column (18-20 = unusual -> V.A./V.B.).
inline void chamberShapeFor(int r, SpaceShape& s) {
    s.wFt = 0; s.hFt = 0; s.unusual = false;
    if (r <= 4)  { s.wFt = 20; s.hFt = 20; }
    else if (r <= 6)  { s.wFt = 30; s.hFt = 30; }
    else if (r <= 8)  { s.wFt = 40; s.hFt = 40; }
    else if (r <= 13) { s.wFt = 20; s.hFt = 30; }
    else if (r <= 15) { s.wFt = 30; s.hFt = 50; }
    else if (r <= 17) { s.wFt = 40; s.hFt = 60; }
    else s.unusual = true;   // 18-20
}

// The room column; false = the book prints it blank
// at 18-20 (unusual is chamber-only) - re-roll.
inline bool roomShapeFor(int r, SpaceShape& s) {
    s.wFt = 0; s.hFt = 0; s.unusual = false;
    if (r <= 2)  { s.wFt = 10; s.hFt = 10; }
    else if (r <= 4)  { s.wFt = 20; s.hFt = 20; }
    else if (r <= 6)  { s.wFt = 30; s.hFt = 30; }
    else if (r <= 8)  { s.wFt = 40; s.hFt = 40; }
    else if (r <= 10) { s.wFt = 10; s.hFt = 20; }
    else if (r <= 13) { s.wFt = 20; s.hFt = 30; }
    else if (r <= 15) { s.wFt = 20; s.hFt = 40; }
    else if (r <= 17) { s.wFt = 30; s.hFt = 40; }
    else return false;   // 18-20: blank in the book
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
    if (r <= 5)  return US_CIRCULAR;
    if (r <= 8)  return US_TRIANGULAR;
    if (r <= 11) return US_TRAPEZOIDAL;
    if (r <= 13) return US_ODD;
    if (r <= 15) return US_OVAL;
    if (r <= 17) return US_HEXAGONAL;
    if (r <= 19) return US_OCTAGONAL;
    return US_CAVE;
}

// the circular chamber's own d20: 1-5 pool,
// 6-7 well, 8-10 shaft, 11-20 normal
enum CircularFeature {
    CIRC_POOL = 0, CIRC_WELL, CIRC_SHAFT, CIRC_NORMAL
};

inline CircularFeature circularFeatureFor(int r) {
    if (r <= 5)  return CIRC_POOL;
    if (r <= 7)  return CIRC_WELL;
    if (r <= 10) return CIRC_SHAFT;
    return CIRC_NORMAL;
}

// ---- TABLE V.B.: UNUSUAL SIZE (p.171, d20) ---------------------------------
// Square feet; -1 = the 15-20 rule: roll again
// and add the result to the 9-10 row (2000),
// repeating on another 15-20.
inline int unusualSizeBaseFor(int r) {
    if (r <= 3)  return 500;
    if (r <= 6)  return 900;
    if (r <= 8)  return 1300;
    if (r <= 10) return 2000;
    if (r <= 12) return 2700;
    if (r <= 14) return 3400;
    return -1;
}

// ---- TABLE V.C.: NUMBER OF EXITS (p.171, d20) ------------------------------
// overThreshold: the room area is over the row's
// threshold. kExitsRollD4 = roll d4 (the 16-18 row).
const int kExitsRollD4 = -1;

inline int exitsFor(int r, bool overThreshold) {
    if (r <= 3)  return overThreshold ? 2 : 1;
    if (r <= 6)  return overThreshold ? 3 : 2;
    if (r <= 9)  return overThreshold ? 4 : 3;
    if (r <= 12) return overThreshold ? 1 : 0;
    if (r <= 15) return overThreshold ? 1 : 0;
    if (r <= 18) return kExitsRollD4;
    return 1;   // 19-20: door in chamber, passage in room
}

// ---- TABLE V.D.: EXIT LOCATION (p.171, d20) --------------------------------
enum ExitLocation {
    EL_OPPOSITE = 0,   // 1-7
    EL_LEFT,           // 8-12
    EL_RIGHT,          // 13-17
    EL_SAME            // 18-20
};

inline ExitLocation exitLocationFor(int r) {
    if (r <= 7)  return EL_OPPOSITE;
    if (r <= 12) return EL_LEFT;
    if (r <= 17) return EL_RIGHT;
    return EL_SAME;
}

// ---- TABLE V.E.: EXIT DIRECTION (p.171, d20) --------------------------------
enum ExitDirection {
    ED_STRAIGHT = 0,   // 1-16
    ED_45_LR,          // 17-18: left/right
    ED_45_RL           // 19-20: right/left
};

inline ExitDirection exitDirectionFor(int r) {
    if (r <= 16) return ED_STRAIGHT;
    if (r <= 18) return ED_45_LR;
    return ED_45_RL;
}

// ---- TABLE V.F.: CHAMBER OR ROOM CONTENTS (p.171, d20) ----------------------
// The repo's dm::RoomContents; 19 = trick/trap, 20
// = treasure.
inline RoomContents roomContentsFor(int r) {
    if (r <= 12) return ROOM_EMPTY;
    if (r <= 14) return ROOM_MONSTER;
    if (r <= 17) return ROOM_MONSTER_TREASURE;
    if (r == 18) return ROOM_SPECIAL;
    if (r == 19) return ROOM_TRAP;
    return ROOM_TREASURE;
}

// the contents-18 stairway variant (its own d20). The
// book's print covers 1-5, 7-8, 9-14, 15-19, 20 -
// band 6 is uncovered on the page; the gap is folded
// into up-1 (documented).
enum StairVariant {
    SV_UP1 = 0, SV_UP2, SV_DOWN1, SV_DOWN2, SV_DOWN3
};

inline StairVariant stairwayVariantFor(int r) {
    if (r <= 6)  return SV_UP1;   // 1-5 (+ the 6 gap)
    if (r <= 8)  return SV_UP2;
    if (r <= 14) return SV_DOWN1;
    if (r <= 19) return SV_DOWN2;
    return SV_DOWN3;   // 20: 2 flights and a slanting
                       // passage
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
    t.kind = TR_CP; t.basePerLevel = 0;
    if (r <= 25) { t.kind = TR_CP; t.basePerLevel = 1000; }
    else if (r <= 50) { t.kind = TR_SP; t.basePerLevel = 1000; }
    else if (r <= 65) { t.kind = TR_EP; t.basePerLevel = 750; }
    else if (r <= 80) { t.kind = TR_GP; t.basePerLevel = 250; }
    else if (r <= 90) { t.kind = TR_PP; t.basePerLevel = 100; }
    else if (r <= 94) { t.kind = TR_GEMS; t.basePerLevel = 1; }
    else if (r <= 97) { t.kind = TR_JEWELRY; t.basePerLevel = 1; }
    else t.kind = TR_MAGIC;
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
    if (r <= 2)  return C_BAGS;
    if (r <= 4)  return C_SACKS;
    if (r <= 6)  return C_SMALL_COFFERS;
    if (r <= 8)  return C_CHESTS;
    if (r <= 10) return C_HUGE_CHESTS;
    if (r <= 12) return C_POTTERY_JARS;
    if (r <= 14) return C_METAL_URNS;
    if (r <= 16) return C_STONE_CONTAINERS;
    if (r <= 18) return C_IRON_TRUNKS;
    return C_LOOSE;
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
    if (r <= 2)  return G_CONTACT_POISON_CONTAINER;
    if (r <= 4)  return G_CONTACT_POISON_TREASURE;
    if (r <= 6)  return G_NEEDLES_LOCK;
    if (r == 7)  return G_NEEDLES_HANDLES;
    if (r == 8)  return G_DARTS_FRONT;
    if (r == 9)  return G_DARTS_TOP;
    if (r == 10) return G_DARTS_BOTTOM;
    if (r <= 12) return G_BLADE_SCYTHE;
    if (r == 13) return G_CREATURES;
    if (r == 14) return G_GAS;
    if (r == 15) return G_TRAPDOOR_FRONT;
    if (r == 16) return G_TRAPDOOR_6FT;
    if (r == 17) return G_STONE_BLOCK;
    if (r == 18) return G_SPEARS;
    if (r == 19) return G_EXPLOSIVE_RUNES;
    return G_SYMBOL;
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
    if (r <= 3)  return H_INVISIBILITY;
    if (r <= 5)  return H_ILLUSION;
    if (r == 6)  return H_SECRET_SPACE_UNDER;
    if (r <= 8)  return H_SECRET_COMPARTMENT;
    if (r == 9)  return H_ORDINARY_ITEM;
    if (r == 10) return H_DISGUISED;
    if (r == 11) return H_TRASH_DUNG;
    if (r <= 13) return H_LOOSE_FLOOR_STONE;
    if (r <= 15) return H_LOOSE_WALL_STONE;
    return H_SECRET_ROOM;
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
    if (r <= 5)  return ST_DOWN1;
    if (r == 6)  return ST_DOWN2;
    if (r == 7)  return ST_DOWN3;
    if (r == 8)  return ST_UP1;
    if (r == 9)  return ST_UP_DEAD;
    if (r == 10) return ST_DOWN_DEAD;
    if (r == 11) return ST_CHIMNEY_UP1;
    if (r == 12) return ST_CHIMNEY_UP2;
    if (r == 13) return ST_CHIMNEY_DOWN2;
    if (r <= 16) return ST_TRAPDOOR_DOWN1;
    if (r == 17) return ST_TRAPDOOR_DOWN2;
    return ST_UP1_DOWN2;
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
    if (r <= 5)  return TT_SECRET_DOOR;
    if (r <= 7)  return TT_PIT;
    if (r == 8)  return TT_PIT_SPIKED;
    if (r == 9)  return TT_ELEVATOR_DOWN1;
    if (r == 10) return TT_ELEVATOR_DOWN2;
    if (r == 11) return TT_ELEVATOR_2TO5;
    if (r == 12) return TT_SLIDING_WALL;
    if (r == 13) return TT_OIL_CINDER;
    if (r == 14) return TT_PIT_CRUSHING;
    if (r == 15) return TT_ARROW_TRAP;
    if (r == 16) return TT_SPEAR_TRAP;
    if (r == 17) return TT_GAS;
    if (r == 18) return TT_FALLING_DOOR_STONE;
    if (r == 19) return TT_ILLUSIONARY_WALL;
    return TT_CHUTE;
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
    if (r <= 7)  return GAS_OBSCURE;
    if (r <= 9)  return GAS_BLIND;
    if (r <= 12) return GAS_FEAR;
    if (r == 13) return GAS_SLEEP;
    if (r <= 18) return GAS_STRENGTH;
    if (r == 19) return GAS_SICKNESS;
    return GAS_POISON;
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
    if (r <= 5)  { c.wFt = 40;  c.hFt = 60; }
    else if (r <= 7)  { c.wFt = 50;  c.hFt = 75; }
    else if (r <= 9)  { c.wFt = 20;  c.hFt = 30;
                        c.w2Ft = 60; c.h2Ft = 60; }
    else if (r <= 11) { c.wFt = 35;  c.hFt = 50;
                        c.w2Ft = 80; c.h2Ft = 90;
                        c.pool = true; }
    else if (r <= 14) { c.wFt = 95;  c.hFt = 125;
                        c.pool = true; }
    else if (r <= 16) { c.wFt = 120; c.hFt = 150; }
    else if (r <= 18) { c.wFt = 150; c.hFt = 200;
                        c.pool = true; }
    else { c.wFt = 275; c.hFt = 375;   // 250-300 x
          c.lake = true; }             // 350-400
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
    if (r <= 8)   return POOL_NONE;
    if (r <= 10)  return POOL_NO_MONSTER;
    if (r <= 12)  return POOL_MONSTER;
    if (r <= 18)  return POOL_MONSTER_TREASURE;
    return POOL_MAGICAL;
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
    if (r <= 10) return LAKE_NONE;
    if (r <= 15) return LAKE_NO_MONSTERS;
    if (r <= 18) return LAKE_MONSTERS;
    return LAKE_ENCHANTED;
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
    if (r <= 8)  return MP_GOLD_TO_PLATINUM_LEAD;
    if (r <= 15) return MP_CHARACTERISTIC;
    if (r <= 17) return MP_TALKING;
    return MP_TRANSPORTER;
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
    if (r <= 6)   return PA_LAWFUL_GOOD;
    if (r <= 9)   return PA_LAWFUL_EVIL;
    if (r <= 12)  return PA_CHAOTIC_GOOD;
    if (r <= 17)  return PA_CHAOTIC_EVIL;
    return PA_NEUTRAL;
}

// the transporter's destination (its own d20)
enum TransportDest {
    TD_SURFACE = 0,          // 1-7
    TD_ELSEWHERE_LEVEL,      // 8-12
    TD_ONE_DOWN,             // 13-16
    TD_100_MILES             // 17-20: outdoor adventure
};

inline TransportDest transportDestFor(int r) {
    if (r <= 7)   return TD_SURFACE;
    if (r <= 12)  return TD_ELSEWHERE_LEVEL;
    if (r <= 16)  return TD_ONE_DOWN;
    return TD_100_MILES;
}

} // namespace appendixa
} // namespace dm
