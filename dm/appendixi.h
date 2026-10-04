// ============================================================================
// Adnd1 - dm/appendixi.h
// R150: DMG pp.217-220 - APPENDIX I, DUNGEON DRESSING (the
// corridor/room dressing lists). Pure data,
// header-only (the appendixa.h pattern: the caller
// rolls and decides when; any table luck beyond a
// row is the callers). Transcribed from the fresh
// DMG upload (2026-10-04), which the R149 book-verify
// pass read cell for cell against a clean book read.
//
// Conventions, all named in place:
//   - All five lists are d100 band tables: the
//     accessor takes the percentile roll (1-100) and
//     returns the band; 0 folds to 100 (the book
//     00), out-of-range rolls clamp (the engine
//     standing band discipline).
//   - R149 box count CORRECTIONS carried here: the
//     print reads 14 air-current bands (the box said
//     16), 54 general-item bands (the box said 100),
//     and 58 sound bands (the box said 68); the
//     odors (14) and air (6) counts were right. The
//     band CONTENT the box quoted was correct - only
//     the counts slipped.
//   - The printed wording quirks are kept as
//     printed: "mouldy" and "sulphurous" (the British
//     spellings), "roar(ing)", "bellow (ing)", and
//     the air table "foggy (or steamy)" family.
//   - The book suggests selecting, not rolling, for
//     most of these; the bands are pinned anyway -
//     the roller discipline is the callers call.
//   - The OTHER Appendix I lists (furnishings,
//     torture chamber, magic-user and religious
//     furnishings, container contents, misc items,
//     jewelry, foodstuffs - the "as desired"
//     selection lists) are selection aids, not band
//     tables, and stay unpinned (named).
// ============================================================================

#pragma once

namespace dm {
namespace appendixi {

// ---- AIR CURRENTS (p.217): 14 printed bands ------------------------------
enum AirCurrent {
    AC_BREEZE_SLIGHT = 0,        // 01-05
    AC_BREEZE_SLIGHT_DAMP,       // 06-10
    AC_BREEZE_GUSTING,           // 11-12
    AC_COLD_CURRENT,            // 13-18
    AC_DOWNDRAFT_SLIGHT,        // 19-20
    AC_DOWNDRAFT_STRONG,        // 21-22
    AC_STILL,                   // 23-69
    AC_STILL_VERY_CHILL,        // 70-75
    AC_STILL_WARM,              // 76-85
    AC_UPDRAFT_SLIGHT,          // 86-87
    AC_UPDRAFT_STRONG,          // 88-89
    AC_WIND_STRONG,             // 90-93
    AC_WIND_STRONG_GUSTING,     // 94-95
    AC_WIND_STRONG_MOANING,     // 96-00
    AC_COUNT
};

inline AirCurrent airCurrentFor(int r) {
    if (r <= 0)   r = 100;              // 00 folds to 100
    if (r > 100)  r = 100;
    if (r <= 5)   return AC_BREEZE_SLIGHT;
    if (r <= 10)  return AC_BREEZE_SLIGHT_DAMP;
    if (r <= 12)  return AC_BREEZE_GUSTING;
    if (r <= 18)  return AC_COLD_CURRENT;
    if (r <= 20)  return AC_DOWNDRAFT_SLIGHT;
    if (r <= 22)  return AC_DOWNDRAFT_STRONG;
    if (r <= 69)  return AC_STILL;
    if (r <= 75)  return AC_STILL_VERY_CHILL;
    if (r <= 85)  return AC_STILL_WARM;
    if (r <= 87)  return AC_UPDRAFT_SLIGHT;
    if (r <= 89)  return AC_UPDRAFT_STRONG;
    if (r <= 93)  return AC_WIND_STRONG;
    if (r <= 95)  return AC_WIND_STRONG_GUSTING;
    return AC_WIND_STRONG_MOANING;
}

// ---- ODORS (p.217): 14 printed bands ------------------------------------
enum Odor {
    OD_ACRID = 0,                // 01-03
    OD_CHLORINE,                 // 04-05
    OD_DANK_MOULDY,              // 06-39
    OD_EARTHY,                   // 40-49
    OD_MANURE,                   // 50-57
    OD_METALLIC,                 // 58-61
    OD_OZONE,                    // 62-65
    OD_PUTRID,                   // 66-70
    OD_ROTTING_VEGETATION,       // 71-75
    OD_SALTY_WET,                // 76-77
    OD_SMOKY,                    // 78-82
    OD_STALE_FETID,              // 83-89
    OD_SULPHUROUS,               // 90-95
    OD_URINE,                    // 96-00
    OD_COUNT
};

inline Odor odorFor(int r) {
    if (r <= 0)   r = 100;
    if (r > 100)  r = 100;
    if (r <= 3)   return OD_ACRID;
    if (r <= 5)   return OD_CHLORINE;
    if (r <= 39)  return OD_DANK_MOULDY;
    if (r <= 49)  return OD_EARTHY;
    if (r <= 57)  return OD_MANURE;
    if (r <= 61)  return OD_METALLIC;
    if (r <= 65)  return OD_OZONE;
    if (r <= 70)  return OD_PUTRID;
    if (r <= 75)  return OD_ROTTING_VEGETATION;
    if (r <= 77)  return OD_SALTY_WET;
    if (r <= 82)  return OD_SMOKY;
    if (r <= 89)  return OD_STALE_FETID;
    if (r <= 95)  return OD_SULPHUROUS;
    return OD_URINE;
}

// ---- AIR (p.219): 6 printed bands ----------------------------------------
enum AirState {
    AIR_CLEAR = 0,               // 01-70
    AIR_FOGGY,                   // 71-80
    AIR_FOGGY_NEAR_FLOOR,        // 81-88
    AIR_HAZY_DUST,               // 89-90
    AIR_HAZY_SMOKE,              // 91-98
    AIR_MISTED,                  // 99-00
    AIR_COUNT
};

inline AirState airStateFor(int r) {
    if (r <= 0)   r = 100;
    if (r > 100)  r = 100;
    if (r <= 70)  return AIR_CLEAR;
    if (r <= 80)  return AIR_FOGGY;
    if (r <= 88)  return AIR_FOGGY_NEAR_FLOOR;
    if (r <= 90)  return AIR_HAZY_DUST;
    if (r <= 98)  return AIR_HAZY_SMOKE;
    return AIR_MISTED;
}

// ---- GENERAL ITEMS (p.218): 54 printed bands ------------------------------
enum GeneralItem {
    GI_ARROW_BROKEN = 0,          // 01
    GI_ASHES,                     // 02-04
    GI_BONES,                     // 05-06
    GI_BOTTLE_BROKEN,             // 07
    GI_CHAIN_CORRODED,            // 08
    GI_CLUB_SPLINTERED,           // 09
    GI_COBWEBS,                   // 10-19
    GI_COIN_COPPER_BENT,          // 20
    GI_CRACKS_CEILING,            // 21-22
    GI_CRACKS_FLOOR,              // 23-24
    GI_CRACKS_WALL,               // 25-26
    GI_DAGGER_HILT,               // 27
    GI_DAMPNESS_CEILING,          // 28-29
    GI_DAMPNESS_WALL,             // 30-33
    GI_DRIPPING,                  // 34-40
    GI_DRIED_BLOOD,               // 41
    GI_DUNG,                      // 42-44
    GI_DUST,                      // 45-49
    GI_FLASK_CRACKED,             // 50
    GI_FOOD_SCRAPS,               // 51
    GI_FUNGI_COMMON,              // 52
    GI_GUANO,                     // 53-55
    GI_HAIR_FUR_BITS,            // 56
    GI_HAMMER_HEAD_CRACKED,       // 57
    GI_HELMET_DENTED,             // 58
    GI_IRON_BAR_BENT,             // 59
    GI_JAVELIN_HEAD_BLUNT,        // 60
    GI_LEATHER_BOOT,              // 61
    GI_LEAVES_TWIGS,              // 62-64
    GI_MOLD,                      // 65-68
    GI_PICK_HANDLE,               // 69
    GI_POLE_BROKEN,               // 70
    GI_POTTERY_SHARDS,            // 71
    GI_RAGS,                      // 72-73
    GI_ROPE_ROTTEN,               // 74
    GI_RUBBLE_DIRT,               // 75-76
    GI_SACK_TORN,                 // 77
    GI_SLIMY_CEILING,             // 78
    GI_SLIMY_FLOOR,               // 79
    GI_SLIMY_WALL,                // 80
    GI_SPIKE_RUSTED,              // 81
    GI_STICKS,                    // 82-83
    GI_STONES_SMALL,              // 84
    GI_STRAW,                     // 85
    GI_SWORD_BLADE_BROKEN,        // 86
    GI_TEETH_SCATTERED,           // 87
    GI_TORCH_STUB,                // 88
    GI_WALL_SCRATCHINGS,          // 89
    GI_WATER_SMALL_PUDDLE,        // 90-91
    GI_WATER_LARGE_PUDDLE,        // 92-93
    GI_WATER_TRICKLE,             // 94-95
    GI_WAX_DRIPPINGS,             // 96
    GI_WAX_BLOB,                  // 97
    GI_WOOD_PIECES_ROTTING,       // 98-00
    GI_COUNT
};

inline GeneralItem generalItemFor(int r) {
    if (r <= 0)   r = 100;
    if (r > 100)  r = 100;
    if (r <= 1)   return GI_ARROW_BROKEN;
    if (r <= 4)   return GI_ASHES;
    if (r <= 6)   return GI_BONES;
    if (r <= 7)   return GI_BOTTLE_BROKEN;
    if (r <= 8)   return GI_CHAIN_CORRODED;
    if (r <= 9)   return GI_CLUB_SPLINTERED;
    if (r <= 19)  return GI_COBWEBS;
    if (r <= 20)  return GI_COIN_COPPER_BENT;
    if (r <= 22)  return GI_CRACKS_CEILING;
    if (r <= 24)  return GI_CRACKS_FLOOR;
    if (r <= 26)  return GI_CRACKS_WALL;
    if (r <= 27)  return GI_DAGGER_HILT;
    if (r <= 29)  return GI_DAMPNESS_CEILING;
    if (r <= 33)  return GI_DAMPNESS_WALL;
    if (r <= 40)  return GI_DRIPPING;
    if (r <= 41)  return GI_DRIED_BLOOD;
    if (r <= 44)  return GI_DUNG;
    if (r <= 49)  return GI_DUST;
    if (r <= 50)  return GI_FLASK_CRACKED;
    if (r <= 51)  return GI_FOOD_SCRAPS;
    if (r <= 52)  return GI_FUNGI_COMMON;
    if (r <= 55)  return GI_GUANO;
    if (r <= 56)  return GI_HAIR_FUR_BITS;
    if (r <= 57)  return GI_HAMMER_HEAD_CRACKED;
    if (r <= 58)  return GI_HELMET_DENTED;
    if (r <= 59)  return GI_IRON_BAR_BENT;
    if (r <= 60)  return GI_JAVELIN_HEAD_BLUNT;
    if (r <= 61)  return GI_LEATHER_BOOT;
    if (r <= 64)  return GI_LEAVES_TWIGS;
    if (r <= 68)  return GI_MOLD;
    if (r <= 69)  return GI_PICK_HANDLE;
    if (r <= 70)  return GI_POLE_BROKEN;
    if (r <= 71)  return GI_POTTERY_SHARDS;
    if (r <= 73)  return GI_RAGS;
    if (r <= 74)  return GI_ROPE_ROTTEN;
    if (r <= 76)  return GI_RUBBLE_DIRT;
    if (r <= 77)  return GI_SACK_TORN;
    if (r <= 78)  return GI_SLIMY_CEILING;
    if (r <= 79)  return GI_SLIMY_FLOOR;
    if (r <= 80)  return GI_SLIMY_WALL;
    if (r <= 81)  return GI_SPIKE_RUSTED;
    if (r <= 83)  return GI_STICKS;
    if (r <= 84)  return GI_STONES_SMALL;
    if (r <= 85)  return GI_STRAW;
    if (r <= 86)  return GI_SWORD_BLADE_BROKEN;
    if (r <= 87)  return GI_TEETH_SCATTERED;
    if (r <= 88)  return GI_TORCH_STUB;
    if (r <= 89)  return GI_WALL_SCRATCHINGS;
    if (r <= 91)  return GI_WATER_SMALL_PUDDLE;
    if (r <= 93)  return GI_WATER_LARGE_PUDDLE;
    if (r <= 95)  return GI_WATER_TRICKLE;
    if (r <= 96)  return GI_WAX_DRIPPINGS;
    if (r <= 97)  return GI_WAX_BLOB;
    return GI_WOOD_PIECES_ROTTING;
}

// ---- UNEXPLAINED SOUNDS (p.219): 58 printed bands --------------------------
enum SoundKind {
    SK_BANG_SLAM = 0,            // 01-05
    SK_BELLOW,                    // 06
    SK_BONG,                      // 07
    SK_BUZZING,                   // 08
    SK_CHANTING,                  // 09-10
    SK_CHIMING,                   // 11
    SK_CHIRPING,                  // 12
    SK_CLANKING,                  // 13
    SK_CLASHING,                  // 14
    SK_CLICKING,                  // 15
    SK_COUGHING,                  // 16
    SK_CREAKING,                  // 17-18
    SK_DRUMMING,                  // 19
    SK_FOOTSTEPS_AHEAD,           // 20-23
    SK_FOOTSTEPS_APPROACHING,     // 24-26
    SK_FOOTSTEPS_BEHIND,          // 27-29
    SK_FOOTSTEPS_RECEDING,        // 30-31
    SK_FOOTSTEPS_SIDE,            // 32-33
    SK_GIGGLING,                  // 34-35
    SK_GONG,                      // 36
    SK_GRATING,                   // 37-39
    SK_GROANING,                  // 40-41
    SK_GRUNTING,                  // 42
    SK_HISSING,                   // 43-44
    SK_HOOTING,                   // 45
    SK_HORN,                      // 46
    SK_HOWLING,                   // 47
    SK_HUMMING,                   // 48
    SK_JINGLING,                  // 49
    SK_KNOCKING,                  // 50-53
    SK_LAUGHTER,                  // 54-55
    SK_MOANING,                   // 56-57
    SK_MURMURING,                 // 58-60
    SK_MUSIC,                     // 61
    SK_RATTLING,                  // 62
    SK_RINGING,                   // 63
    SK_ROAR,                      // 64
    SK_RUSTLING,                  // 65-68
    SK_SCRATCHING,                // 69-72
    SK_SCREAMING,                 // 73-74
    SK_SCUTTLING,                 // 75-77
    SK_SHUFFLING,                 // 78
    SK_SLITHERING,                // 79-80
    SK_SNAPPING,                  // 81
    SK_SNEEZING,                  // 82
    SK_SOBBING,                   // 83
    SK_SPLASHING,                 // 84
    SK_SPLINTERING,               // 85
    SK_SQUEAKING,                 // 86-87
    SK_SQUEALING,                 // 88
    SK_TAPPING,                   // 89-90
    SK_THUD,                      // 91-92
    SK_THUMPING,                  // 93-94
    SK_TINKLING,                  // 95
    SK_TWANGING,                  // 96
    SK_WHINING,                   // 97
    SK_WHISPERING,                // 98
    SK_WHISTLING,                 // 99-00
    SK_COUNT
};

inline SoundKind soundFor(int r) {
    if (r <= 0)   r = 100;
    if (r > 100)  r = 100;
    if (r <= 5)   return SK_BANG_SLAM;
    if (r <= 6)   return SK_BELLOW;
    if (r <= 7)   return SK_BONG;
    if (r <= 8)   return SK_BUZZING;
    if (r <= 10)  return SK_CHANTING;
    if (r <= 11)  return SK_CHIMING;
    if (r <= 12)  return SK_CHIRPING;
    if (r <= 13)  return SK_CLANKING;
    if (r <= 14)  return SK_CLASHING;
    if (r <= 15)  return SK_CLICKING;
    if (r <= 16)  return SK_COUGHING;
    if (r <= 18)  return SK_CREAKING;
    if (r <= 19)  return SK_DRUMMING;
    if (r <= 23)  return SK_FOOTSTEPS_AHEAD;
    if (r <= 26)  return SK_FOOTSTEPS_APPROACHING;
    if (r <= 29)  return SK_FOOTSTEPS_BEHIND;
    if (r <= 31)  return SK_FOOTSTEPS_RECEDING;
    if (r <= 33)  return SK_FOOTSTEPS_SIDE;
    if (r <= 35)  return SK_GIGGLING;
    if (r <= 36)  return SK_GONG;
    if (r <= 39)  return SK_GRATING;
    if (r <= 41)  return SK_GROANING;
    if (r <= 42)  return SK_GRUNTING;
    if (r <= 44)  return SK_HISSING;
    if (r <= 45)  return SK_HOOTING;
    if (r <= 46)  return SK_HORN;
    if (r <= 47)  return SK_HOWLING;
    if (r <= 48)  return SK_HUMMING;
    if (r <= 49)  return SK_JINGLING;
    if (r <= 53)  return SK_KNOCKING;
    if (r <= 55)  return SK_LAUGHTER;
    if (r <= 57)  return SK_MOANING;
    if (r <= 60)  return SK_MURMURING;
    if (r <= 61)  return SK_MUSIC;
    if (r <= 62)  return SK_RATTLING;
    if (r <= 63)  return SK_RINGING;
    if (r <= 64)  return SK_ROAR;
    if (r <= 68)  return SK_RUSTLING;
    if (r <= 72)  return SK_SCRATCHING;
    if (r <= 74)  return SK_SCREAMING;
    if (r <= 77)  return SK_SCUTTLING;
    if (r <= 78)  return SK_SHUFFLING;
    if (r <= 80)  return SK_SLITHERING;
    if (r <= 81)  return SK_SNAPPING;
    if (r <= 82)  return SK_SNEEZING;
    if (r <= 83)  return SK_SOBBING;
    if (r <= 84)  return SK_SPLASHING;
    if (r <= 85)  return SK_SPLINTERING;
    if (r <= 87)  return SK_SQUEAKING;
    if (r <= 88)  return SK_SQUEALING;
    if (r <= 90)  return SK_TAPPING;
    if (r <= 92)  return SK_THUD;
    if (r <= 94)  return SK_THUMPING;
    if (r <= 95)  return SK_TINKLING;
    if (r <= 96)  return SK_TWANGING;
    if (r <= 97)  return SK_WHINING;
    if (r <= 98)  return SK_WHISPERING;
    return SK_WHISTLING;
}

} // namespace appendixi
} // namespace dm