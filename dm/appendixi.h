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
// R1045: the five band tables are registry-native
// (content/tables/appendixi/, the seam below);
// the printed cascades are gone from this header
// and the accessors read registry views. The enums
// stay in-file as constants (the band identity API);
// the 00-fold and the clamp semantics stay verbatim.
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

#include "items/MiscItemRegistry.h"   // R1045: the dressing bands ride the registry

namespace dm {
namespace appendixi {

// ---- the R1045 registry seam ----------------------------------------
// The five dressing band tables ride
// items::MiscItemRegistry from
// content/tables/appendixi/ (def keys
// appendixi_*). Row encoding: name = the
// enum tag at the row index, band = the
// printed percentile band; the rest zero.
// This seam is header-only (the
// R1040-R1044 idiom); every accessor
// signature below is unchanged (the r150
// audit pins them); the enums stay in-file
// as constants and the 00-fold and clamp
// semantics stay verbatim. The band scan
// relies on the battery-pinned band chain
// (1..100, contiguous, last band 100).

inline items::MiscItemRegistry& aiReg() {
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory("content/tables/appendixi");
    }
    return reg;
}

// the registry-backed per-view cache (the
// R1032-R1044 idiom; function-local statics in
// inline functions are shared across TUs)
inline const std::vector<items::MiscItemRow>& aiView(
        const char* name) {
    static std::map<std::string,
        std::vector<items::MiscItemRow>> cache;
    auto it = cache.find(name);
    if (it == cache.end()) {
        const items::MiscItemDef* d = aiReg().find(name);
        it = cache.emplace(
            name, d ? d->rows
                   : std::vector<items::MiscItemRow>()).first;
    }
    return it->second;
}


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
    const auto& rows = aiView("appendixi_air_currents");
    if (rows.empty()) return AC_BREEZE_SLIGHT;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return AirCurrent(i);
    return AirCurrent((int)rows.size() - 1);
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
    if (r <= 0)   r = 100;              // 00 folds to 100
    if (r > 100)  r = 100;
    const auto& rows = aiView("appendixi_odors");
    if (rows.empty()) return OD_ACRID;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return Odor(i);
    return Odor((int)rows.size() - 1);
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
    if (r <= 0)   r = 100;              // 00 folds to 100
    if (r > 100)  r = 100;
    const auto& rows = aiView("appendixi_air_states");
    if (rows.empty()) return AIR_CLEAR;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return AirState(i);
    return AirState((int)rows.size() - 1);
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
    if (r <= 0)   r = 100;              // 00 folds to 100
    if (r > 100)  r = 100;
    const auto& rows = aiView("appendixi_general_items");
    if (rows.empty()) return GI_ARROW_BROKEN;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return GeneralItem(i);
    return GeneralItem((int)rows.size() - 1);
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
    if (r <= 0)   r = 100;              // 00 folds to 100
    if (r > 100)  r = 100;
    const auto& rows = aiView("appendixi_unexplained_sounds");
    if (rows.empty()) return SK_BANG_SLAM;   // defensive
    for (int i = 0; i < (int)rows.size(); ++i)
        if (r <= rows[i].bandHi)
            return SoundKind(i);
    return SoundKind((int)rows.size() - 1);
}

} // namespace appendixi
} // namespace dm