#!/usr/bin/env python3
# R124 splice: APPENDIX A DUNGEON DRESSING
# DETAILS (DMG pp.169-172). Every table
# of the random dungeon generation
# appendix, pinned row-by-row in the new
# header-only dm/appendixa.h: TABLE I
# (periodic check), II (doors), III (side
# passages), III.A (width), III.B
# (special passages + the stream/river/
# chasm bridge-boat-jumping chances),
# IV (turns), V (chamber and room shape
# and size), V.A (unusual shape), V.B
# (unusual size), V.C (exits), V.D (exit
# location), V.E (exit direction), V.F
# (room contents + the stairway variant
# on the 18 - the book's own print
# leaves band 6 uncovered, 1-5 then 7-8;
# pinned as printed, documented), V.G
# (treasure by level), V.H (containers),
# V.I (guarded by), V.J (hidden by/in),
# VI (stairs + egress-door chances),
# VII (trick/trap), VII.A (gas), VIII
# (caves and caverns), VIII.A (pools),
# VIII.B (lakes), VIII.C (magic pools +
# the gold/alignment/transporter
# sub-tables).
# WIRED: the walk's four helper rolls in
# dm/dm.cpp - rollPassageWidth (III.A
# feet -> tiles, clamped 1-3: 5' is half
# a tile, the 40'-60' special passages
# are pinned data for a future terrain
# layer), rollPassageFeature (Table I
# mapped to the walk's carveable
# outcomes: doors open onto parallel
# space the walk does not render -
# straight; stairs end the passage;
# tricks and wandering monsters are
# data/encounters, not carves),
# rollRoomSize (Table V's room column in
# feet -> 10' tiles; the book prints the
# room column blank at 18-20 - re-roll),
# rollRoomContents (Table V.F exact:
# 1-12 empty, 13-14 monster, 15-17
# monster and treasure, 18 special,
# 19 trick/trap, 20 treasure). R8's
# stand-in shapes and their
# verification-debt comments are gone.
# The walking generator's architecture
# is unchanged (tile budget, bounds and
# clamps guard every table); rooms are
# the room column - the chamber column
# is pinned data.
# New battery audit R124 (census 42):
# every row of every table diffed
# against the book, the wired helpers'
# bands, and a generator smoke. ASCII-
# only. Idempotent (marker checks per
# patch): run twice - the second run
# must print every patch already
# applied. Refuses non-unique anchors,
# all-or-nothing.
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def read(rel):
    with open(os.path.join(ROOT, rel), "r", encoding="ascii") as f:
        return f.read()


def write(rel, text):
    with open(os.path.join(ROOT, rel), "w", encoding="ascii") as f:
        f.write(text)


def replace_exact(text, old, new, label):
    n = text.count(old)
    if n != 1:
        print("REFUSED " + label + ": anchor not unique or missing (count %d)" % n)
        return text, False
    return text.replace(old, new, 1), True


# ---- patch bodies ----------------------------------------------------------

HDR_TEXT = """// ============================================================================
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
"""

DI_OLD = '#include "dm.h"'

DI_NEW = """#include "dm.h"
#include "appendixa.h"   // R124: pp.169-172 pinned tables"""

PW_OLD = """int rollPassageWidth(Dice& dice) {
    int r = (int)dice.d20();
    if (r <= 12) return 1;   // 10'
    if (r <= 19) return 2;   // 20'
    return 3;                // 30'
}"""

PW_NEW = """int rollPassageWidth(Dice& dice) {
    // R124: the book's TABLE III.A (p.170), pinned in
    // appendixa.h: 1-12 10', 13-16 20', 17 30', 18 5',
    // 19-20 SPECIAL (III.B). Feet to 10' tiles, clamped
    // 1-3 for the walk: 5' is half a tile; the 40'-60'
    // special passages with columns, streams, rivers and
    // chasms are pinned data for a future terrain
    // layer - the walk keeps corridor carving.
    int ft = appendixa::passageWidthFeetFor((int)dice.d20());
    if (ft < 0) ft = 40;   // special -> III.B's floor
    int tiles = (ft + 9) / 10;
    if (tiles > 3) tiles = 3;
    return tiles;
}"""

PF_OLD = """PassageFeature rollPassageFeature(Dice& dice) {
    int r = (int)dice.d20();
    // Appendix A "passage" table shape (verification debt: exact
    // weights vs printed table)
    if (r <= 8)  return PASSAGE_STRAIGHT;
    if (r <= 12) return PASSAGE_TURN;
    if (r <= 15) return PASSAGE_T_JUNCTION;
    if (r <= 17) return PASSAGE_CROSS;
    if (r <= 19) return PASSAGE_CHAMBER;
    return PASSAGE_DEAD_END;
}"""

PF_NEW = """PassageFeature rollPassageFeature(Dice& dice) {
    // R124: the book's TABLE I (p.170), pinned in
    // appendixa.h, mapped to the walk's carveable
    // outcomes: a door (3-5) opens onto parallel space
    // the walk does not render - straight; stairs (17)
    // end the passage; a trick/trap (19) is pinned data
    // (TABLE VII.), not a carve; a wandering monster
    // (20) is an encounter cadence, not a feature.
    switch (appendixa::passageCheckFor((int)dice.d20())) {
        case appendixa::PC_SIDE:     return PASSAGE_T_JUNCTION;
        case appendixa::PC_TURN:     return PASSAGE_TURN;
        case appendixa::PC_CHAMBER:  return PASSAGE_CHAMBER;
        case appendixa::PC_STAIRS:
        case appendixa::PC_DEAD_END: return PASSAGE_DEAD_END;
        default: break;
    }
    return PASSAGE_STRAIGHT;
}"""

RS_OLD = """void rollRoomSize(Dice& dice, int& w, int& h) {
    // Appendix A room size: d6+d6 pairs; standard shape
    int a = (int)dice.d6();
    int b = (int)dice.d6();
    // small 1-2, medium 3-4, large 5-6 scale factor
    int scale = (a <= 2) ? 1 : (a <= 4) ? 2 : 3;
    w = 1 + (b / 2) + scale;             // rough 2-6 tiles
    h = 1 + ((int)dice.d6() / 2) + (scale == 3 ? 1 : 0);
    if (w < 2) w = 2;
    if (h < 2) h = 2;
}"""

RS_NEW = """void rollRoomSize(Dice& dice, int& w, int& h) {
    // R124: the book's TABLE V (p.171), the room column,
    // pinned in appendixa.h: 10'x10' .. 30'x40' in feet
    // -> 10' tiles. The book prints the room column blank
    // at 18-20 (the unusual shape/size sub-tables are
    // chamber-only) - re-roll. The chamber column is
    // pinned data for the future layer.
    appendixa::SpaceShape s;
    while (!appendixa::roomShapeFor((int)dice.d20(), s)) {}
    w = s.wFt / 10;
    h = s.hFt / 10;
    if (w < 1) w = 1;
    if (h < 1) h = 1;
}"""

RC_OLD = """RoomContents rollRoomContents(Dice& dice) {
    int r = (int)dice.d20();
    // Appendix A room contents weighted shape (verification debt)
    if (r <= 8)  return ROOM_EMPTY;             // ~40%
    if (r <= 13) return ROOM_MONSTER;           // ~30%
    if (r <= 16) return ROOM_MONSTER_TREASURE;  // ~15%
    if (r <= 18) return ROOM_TREASURE;          // ~10%
    if (r == 19) return ROOM_SPECIAL;           // 5%
    return ROOM_TRAP;                           // 5%
}"""

RC_NEW = """RoomContents rollRoomContents(Dice& dice) {
    // R124: the book's TABLE V.F (p.171), pinned in
    // appendixa.h: 1-12 empty, 13-14 monster, 15-17
    // monster and treasure, 18 special, 19 trick/trap,
    // 20 treasure.
    return appendixa::roomContentsFor((int)dice.d20());
}"""

HW_OLD = """// Passage width (in 10' tiles): 1 = 10' wide, 2 = 20' wide, 3 = 30'.
int rollPassageWidth(Dice& dice);          // d20: 1-12 -> 1, 13-19 -> 2, 20 -> 3"""

HW_NEW = """// R124: TABLE III.A (p.170) via appendixa.h - feet ->
// 10' tiles, clamped 1-3 (5' is half a tile; the
// special passages are pinned data, the walk clamps).
int rollPassageWidth(Dice& dice);"""

HF_OLD = """PassageFeature rollPassageFeature(Dice& dice);   // d20 table, App A"""

HF_NEW = """PassageFeature rollPassageFeature(Dice& dice);   // R124: Table I via appendixa.h, mapped to the walk"""

HS_OLD = """// Room size in tiles: d6 pairs -> small/medium/large + dimensions.
// Returns width x height in 10' tiles (e.g. 2x3, 4x6).
void rollRoomSize(Dice& dice, int& w, int& h);"""

HS_NEW = """// R124: TABLE V's room column (p.171) via appendixa.h
// - 10'x10' .. 30'x40' in feet -> 10' tiles; the
// book's blank 18-20 rows re-roll.
void rollRoomSize(Dice& dice, int& w, int& h);"""

HC_OLD = """RoomContents rollRoomContents(Dice& dice);   // d20 weighted table"""

HC_NEW = """RoomContents rollRoomContents(Dice& dice);   // R124: Table V.F via appendixa.h - exact bands"""

RI_OLD = '#include "dm/outdoormove.h"   // R123: pp.58-59 daily rates'

RI_NEW = """#include "dm/outdoormove.h"   // R123: pp.58-59 daily rates
#include "dm/appendixa.h"   // R124: pp.169-172 Appendix A tables
#include "dm/dungeon.h"    // R124: generator smoke in the audit"""

RT_OLD = """        printf("R123 outdoor movement audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

RT_NEW = """        printf("R123 outdoor movement audit: bad %d\\n", bad);
        if (bad) return 1;
    }

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
        printf("R124 appendix A dressing audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

GH_OLD = """the mounted and afloat tables pinned
as data. Census 41."""

GH_NEW = """the mounted and afloat tables pinned
as data. Census 41.
R124 CLOSED Appendix A dressing
details (pp.169-172) - every table of
the random dungeon generation appendix
pinned row-by-row in the new
dm/appendixa.h: periodic check, doors,
side passages, widths, special passages
with their bridge/boat/jumping
chances, turns, chamber and room
shapes, unusual shape and size, exits,
contents and the stairway variant,
treasure by level, containers, guards,
hiding, stairs, tricks/traps, gas,
caves, pools, lakes and magic pools.
The walk's four helper rolls (width,
features, room size, contents) are
rewired to the exact tables - the
verification debt paid. Census 42."""

GB_OLD = """- [ ] **Appendix A dungeon dressing details
      (pp.169-172)** - beyond what the generator
      already pins."""

GB_NEW = """- [x] **Appendix A dungeon dressing details
      (pp.169-172)** - CLOSED R124: all tables
      pinned row-by-row in the new
      dm/appendixa.h (Tables I-VIII.C:
      periodic check, doors, side passages,
      passage width, special passages with
      the stream/river/chasm bridge-boat-
      jumping chances, turns, chamber/room
      shape and size, unusual shape and
      size, exits count/location/direction,
      room contents + the stairway variant
      (the book's print skips band 6 - 1-5,
      7-8 - pinned as printed, documented),
      treasure by level, containers,
      guarded-by, hidden-by, stairs with
      their egress doors, trick/trap, gas,
      caves, pools, lakes, magic pools and
      their sub-tables). The walk's four
      helpers (passage width, passage
      features, room size, room contents)
      are rewired to the exact tables -
      R8's stand-in shapes and their
      verification-debt notes are gone
      (rooms use Table V's room column -
      the blank 18-20 rows re-roll; the
      chamber column and all unrendered
      tables are pinned data for the future
      layers). Pinned by the R124 battery
      audit; census 42."""


# ---- patch table: (file, marker, old, new, label) --------------------------

PATCHES = [
    ("dm/appendixa.h", "NEWFILE", "", HDR_TEXT,
     "dm/appendixa.h the pp.169-172 tables"),
    ("dm/dm.cpp", '#include "appendixa.h"   // R124: pp.169-172 pinned tables',
     DI_OLD, DI_NEW, "dm.cpp appendixa include"),
    ("dm/dm.cpp", "int ft = appendixa::passageWidthFeetFor",
     PW_OLD, PW_NEW, "dm.cpp passage width"),
    ("dm/dm.cpp", "case appendixa::PC_SIDE:     return PASSAGE_T_JUNCTION;",
     PF_OLD, PF_NEW, "dm.cpp passage features"),
    ("dm/dm.cpp", "while (!appendixa::roomShapeFor((int)dice.d20(), s)) {}",
     RS_OLD, RS_NEW, "dm.cpp room size"),
    ("dm/dm.cpp", "return appendixa::roomContentsFor((int)dice.d20());",
     RC_OLD, RC_NEW, "dm.cpp room contents"),
    ("dm/dm.h", "// R124: TABLE III.A (p.170) via appendixa.h",
     HW_OLD, HW_NEW, "dm.h width comment"),
    ("dm/dm.h", "// R124: Table I via appendixa.h, mapped to the walk",
     HF_OLD, HF_NEW, "dm.h features comment"),
    ("dm/dm.h", "// R124: TABLE V's room column (p.171) via appendixa.h",
     HS_OLD, HS_NEW, "dm.h room size comment"),
    ("dm/dm.h", "// R124: Table V.F via appendixa.h - exact bands",
     HC_OLD, HC_NEW, "dm.h contents comment"),
    ("regtest.cpp", '#include "dm/appendixa.h"   // R124: pp.169-172 Appendix A tables',
     RI_OLD, RI_NEW, "regtest appendixa include"),
    ("regtest.cpp", "R124 appendix A dressing audit",
     RT_OLD, RT_NEW, "regtest R124 audit"),
    ("tools/dmg_gap_report.md", "R124 CLOSED Appendix A dressing",
     GH_OLD, GH_NEW, "gap report header note"),
    ("tools/dmg_gap_report.md", "CLOSED R124: all tables",
     GB_OLD, GB_NEW, "gap report appendix A box"),
]


def main():
    # all-or-nothing: compute every patch, write only if
    # every patch applied or was already applied
    texts = {}
    newfiles = []
    applied = 0
    already = 0
    failed = []
    for rel, marker, old, new, label in PATCHES:
        if marker == "NEWFILE":
            if os.path.exists(os.path.join(ROOT, rel)):
                print("already applied: " + label)
                already += 1
            else:
                newfiles.append((rel, new))
                applied += 1
            continue
        if rel not in texts:
            texts[rel] = read(rel)
        t = texts[rel]
        if marker in t:
            print("already applied: " + label)
            already += 1
        else:
            t2, did = replace_exact(t, old, new, label)
            if not did:
                failed.append(label)
            else:
                texts[rel] = t2
                applied += 1
    if failed:
        print("R124 splice: REFUSED - %d of %d patches applied, "
              "nothing written" % (applied, len(PATCHES)))
        return
    for rel, text in newfiles:
        write(rel, text)
    for rel in texts:
        write(rel, texts[rel])
    if applied == len(PATCHES):
        print("R124 splice: ALL OK (%d patches)" % applied)
    elif applied == 0:
        print("R124 splice: nothing to do (already applied)")
    else:
        print("R124 splice: PARTIAL (%d applied, %d already) - "
              "inspect before committing" % (applied, already))


if __name__ == "__main__":
    main()
