// ============================================================================
// Adnd1 - dm/appendixo.h
// R151: DMG p.225 - APPENDIX O, ENCUMBRANCE OF
// STANDARD ITEMS. Pure data, header-only (the
// appendixa.h pattern: the caller decides when to
// weigh; the band thresholds themselves live in
// items::encumbranceBand, PHB p.38 - this header is
// the printed per-item weight list that table feeds
// on). Transcribed from the fresh DMG upload
// (2026-10-04), readable cell for cell.
//
// Conventions, all named in place:
//   - Weights are in gold-piece units (1 g.p. = 1/10
//     pound), the printed encumbrance column - the
//     combined weight and bulkiness of the item, not
//     its scale weight (the book says so in as many
//     words).
//   - The printed sub-rows (an indented "small" under
//     "Belt pouch, large") are carried as their own
//     fully-named entries, printed order kept.
//   - The seven printed ranges (the four chests, gem,
//     small jewelry, tapestry) carry lo and hi; the
//     commas in the printed figures (1,000-5,000) are
//     print formatting only.
//   - The tapestry row is open-ended (50-1,000 +):
//     openEnded is true for it alone.
//   - The printed max a normal-strength person can
//     carry and still move: 1500 g.p. (150#) - pinned
//     as MAX_CARRY_GP.
//   - The printed footnote: the musical-instrument
//     row means only large and bulky instruments such
//     as lutes and drums.
//   - The printed exemption list (items not figured
//     into encumbrance) is pinned as the four
//     EXEMPT_* wordings.
//   - Armor, weapons, and spell-table weights live
//     elsewhere (items.h weightGp); this is the
//     standard gear list the DMG prints.
// ============================================================================

#pragma once

namespace dm {
namespace appendixo {

enum Gear : int {
    GR_BACKPACK,
    GR_BELT,
    GR_BELT_POUCH_LARGE,
    GR_BELT_POUCH_SMALL,
    GR_BOOK_LARGE_METAL_BOUND,
    GR_BOOTS_HARD,
    GR_BOOTS_SOFT,
    GR_BOTTLES_FLAGONS,
    GR_BOW_COMPOSITE_LONG,
    GR_BOW_COMPOSITE_SHORT,
    GR_BOW_LONG,
    GR_BOW_SHORT,
    GR_CALTROP,
    GR_CANDLE,
    GR_CHEST_LARGE_SOLID_IRON,
    GR_CHEST_SMALL_SOLID_IRON,
    GR_CHEST_SMALL_WOODEN,
    GR_CHEST_LARGE_WOODEN,
    GR_CLOTHES_ONE_SET,
    GR_CORD_10FT,
    GR_CROSSBOW_HEAVY,
    GR_CROSSBOW_LIGHT,
    GR_CRYSTAL_BALL,
    GR_FLASK_EMPTY,
    GR_FLASK_FULL,
    GR_GEM,
    GR_GRAPNEL,
    GR_HAND_TOOL,
    GR_HELM,
    GR_HELM_GREAT,
    GR_HOLY_WATER_BOTTLE,
    GR_HORN,
    GR_JEWELRY_LARGE,
    GR_JEWELRY_SMALL,
    GR_LANTERN,
    GR_MIRROR,
    GR_MUSICAL_INSTRUMENT,
    GR_POLE_10FT,
    GR_PURSE,
    GR_QUIVER,
    GR_RATIONS_IRON,
    GR_RATIONS_STANDARD,
    GR_ROBE_FOLDED,
    GR_ROBE_WORN,
    GR_ROD,
    GR_ROPE_50FT,
    GR_SACK_LARGE,
    GR_SACK_SMALL,
    GR_SADDLE_LIGHT_HORSE,
    GR_SADDLE_HEAVY_HORSE,
    GR_SADDLEBAG,
    GR_SADDLE_BLANKET,
    GR_SCROLL_CASE_BONE_IVORY,
    GR_SCROLL_CASE_LEATHER,
    GR_SPIKE,
    GR_STAFF,
    GR_TAPESTRY,
    GR_TINDERBOX,
    GR_TORCH,
    GR_WAND_BONE_IVORY_CASE,
    GR_WAND_BOX,
    GR_WAND_LEATHER_CASE,
    GR_WATERSKIN_EMPTY,
    GR_WATERSKIN_FULL,
    GR_COUNT,
};

// One printed row. lo and hi are the printed
// encumbrance in g.p.; the 57 exact rows carry
// lo == hi, the 7 printed ranges carry both ends.
// openEnded marks the printed tapestry tail (50-
// 1,000 +) alone. The printed foot marks (10 ft,
// 50 ft) are rendered "ft." here - an apostrophe-
// free spelling of the printed prime.
struct GearEntry {
    const char* name;
    int lo;
    int hi;
    bool openEnded;
};

inline const GearEntry& entry(Gear g) {
    static const GearEntry kGear[GR_COUNT] = {
        { "Backpack", 20, 20, false },
        { "Belt", 3, 3, false },
        { "Belt pouch, large", 10, 10, false },
        { "Belt pouch, small", 5, 5, false },
        { "Book, large metal-bound", 200, 200, false },
        { "Boots, hard", 60, 60, false },
        { "Boots, soft", 30, 30, false },
        { "Bottles, flagons", 60, 60, false },
        { "Bow, composite long", 80, 80, false },
        { "Bow, composite short", 50, 50, false },
        { "Bow, long", 100, 100, false },
        { "Bow, short", 50, 50, false },
        { "Caltrop", 50, 50, false },
        { "Candle", 5, 5, false },
        { "Chest, large solid iron", 1000, 5000, false },
        { "Chest, small solid iron", 200, 500, false },
        { "Chest, small wooden", 100, 250, false },
        { "Chest, large wooden", 500, 1500, false },
        { "Clothes (1 set)", 30, 30, false },
        { "Cord, 10 ft.", 2, 2, false },
        { "Crossbow, heavy", 80, 80, false },
        { "Crossbow, light", 50, 50, false },
        { "Crystal ball, base and wrapping", 150, 150, false },
        { "Flask, empty", 7, 7, false },
        { "Flask, full", 20, 20, false },
        { "Gem", 1, 5, false },
        { "Grapnel", 100, 100, false },
        { "Hand tool", 10, 10, false },
        { "Helm", 45, 45, false },
        { "Helm, great", 100, 100, false },
        { "Holy water, potion bottles", 25, 25, false },
        { "Horn", 50, 50, false },
        { "Jewelry, large", 50, 50, false },
        { "Jewelry, small", 1, 5, false },
        { "Lantern", 60, 60, false },
        { "Mirror", 5, 5, false },
        { "Musical instrument", 350, 350, false },
        { "Pole, 10 ft.", 100, 100, false },
        { "Purse", 1, 1, false },
        { "Quiver", 30, 30, false },
        { "Rations, iron", 75, 75, false },
        { "Rations, standard", 200, 200, false },
        { "Robe or cloak, folded", 50, 50, false },
        { "Robe or cloak, worn", 25, 25, false },
        { "Rod", 60, 60, false },
        { "Rope, 50 ft.", 75, 75, false },
        { "Sack, large", 20, 20, false },
        { "Sack, small", 5, 5, false },
        { "Saddle, light horse", 250, 250, false },
        { "Saddle, heavy horse", 500, 500, false },
        { "Saddlebag", 150, 150, false },
        { "Saddle blanket (pad)", 20, 20, false },
        { "Scroll case, bone or ivory", 50, 50, false },
        { "Scroll case, leather", 25, 25, false },
        { "Spike", 10, 10, false },
        { "Staff", 100, 100, false },
        { "Tapestry (very small to huge)", 50, 1000, true },
        { "Tinderbox", 2, 2, false },
        { "Torch", 25, 25, false },
        { "Wand, bone or ivory case", 60, 60, false },
        { "Wand, box", 80, 80, false },
        { "Wand, leather case", 30, 30, false },
        { "Waterskin or wineskin, empty", 5, 5, false },
        { "Waterskin or wineskin, full", 50, 50, false },
    };
    return kGear[g];
}

inline const char* name(Gear g) { return entry(g).name; }
inline int lo(Gear g) { return entry(g).lo; }
inline int hi(Gear g) { return entry(g).hi; }
inline bool openEnded(Gear g) { return entry(g).openEnded; }

// The printed max a normal-strength person can carry
// and still move: 1500 g.p. (150#).
const int MAX_CARRY_GP = 1500;

// The printed footnote, named: the musical-instrument
// row means only large and bulky instruments such as
// lutes and drums (the row name stays as printed).

// The printed exemptions - the items NOT figured into
// encumbrance - four wordings as printed:
enum Exempt : int {
    EX_MATERIAL_COMPONENTS = 0,
    EX_HELM,
    EX_CLOTHING,
    EX_THIEVES_PICKS,
    EX_COUNT,
};

inline const char* exemptName(Exempt e) {
    switch (e) {
    case EX_MATERIAL_COMPONENTS:
        return "material components (unless large and bulky)";
    case EX_HELM:
        return "any helm but great helm, if the character has any armor";
    case EX_CLOTHING:
        return "one set of clothing";
    case EX_THIEVES_PICKS:
        return "thieves' picks and tools";
    case EX_COUNT: break;
    }
    return "";
}

} // namespace appendixo
} // namespace dm
