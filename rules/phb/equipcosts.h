// ============================================================================
// Adnd1 - rules/phb/equipcosts.h
// The equipment cost columns (R300; the
// general lists R308).
//
// The PHB BASIC EQUIPMENT AND SUPPLIES COSTS tables (the
// equipment section, upload line 2113; the reference-sheet
// repeat, upload line 13432): the ARMS list - 52 rows (the
// left column arrow through hammer, the right column javelin
// through voulge; together alphabetical) - and the ARMOR list
// - 14 rows, alphabetical. Every price pins in its printed
// coin: the gold-piece rows and the six silver-piece ammo
// rows (the single arrow 2 s.p., the dart 5, the javelin 10,
// the light quarrel 1, the dozen sling and bullets 15 and the
// score of sling bullets 10). Exactly one coin column is
// nonzero on every arms row (the R300a battery audit walks
// the identity). The monetary-system pin rides: 20 silver
// pieces = 1 gold piece (eqcSilverPerGold).
//
// SOURCE NOTE: the reference sheet is the legible copy; the
// equipment-section table interleaves in the OCR, but it
// confirms the left rows 1-28 and the right rows 1-24 and
// resolves the empty reference-sheet glaive cell to 6 g.p.
//
// JUDGMENTs:
//   - the armor row 1 prints Bonded in the reference sheet
//     and Banded in the equipment copy - the standard banded
//     mail row (90 g.p.), pinned under the banded name.
//   - the row names follow the R189 weaponChartName spellings
//     where the rows match (footman flail, lucern hammer,
//     awl pike and the rest; the purchase units spelled out:
//     arrow, normal, dozen and quarrel, light, single).
//
// The ENGINE side (items/items.cpp costGp) is repinned by
// this round where it diverged - the printed-table-wins
// debt; the R300 battery audit maps every engine weapon and
// armor id to its printed row. The general equipment rows
// (clothing, herbs, livestock, provisions, religious items,
// tack, transport) are the R308 general lists below - the
// R307 scope pass opened them, R308 pins them, and no
// engine site charges them yet (the town stores price
// canonically).
//
// DATA-DRIVEN (the standing scope).
//
// R1042: the price rows are registry-native
// (content/tables/equipment/, the seam below); the
// printed arrays are gone from this header and the
// accessors read registry views. The monetary pins
// stay in-file (constants, not tables).
// ============================================================================

#pragma once

#include "items/MiscItemRegistry.h"   // R1042: the price tables ride the registry

namespace rules {

// ---- the R1042 registry seam ----------------------------------------
// The three price families (arms, armor, general) ride
// items::MiscItemRegistry from content/tables/equipment/
// (set names = def keys; one row per printed row: the band
// carries the printed row index { i, i }, gp the printed
// price in its printed coin, and qty the coin code
// { 1 copper, 2 silver, 3 gold, 0 }). This seam is
// header-only like the module: the registry rides its own
// inline singleton (the R1040 appendixp.h idiom - a
// file-static is out of reach from a header). Every
// signature below is unchanged (the R300/R300a/R308
// audits and the town stores pin them); the clamp
// semantics stay verbatim.

inline items::MiscItemRegistry& eqReg() {
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory("content/tables/equipment");
    }
    return reg;
}

// the registry-backed per-view cache (the R1032-R1041
// idiom; function-local statics in inline functions are
// shared across TUs)
inline const std::vector<items::MiscItemRow>& eqView(
        const char* name) {
    static std::map<std::string,
        std::vector<items::MiscItemRow>> cache;
    auto it = cache.find(name);
    if (it == cache.end()) {
        const items::MiscItemDef* d = eqReg().find(name);
        it = cache.emplace(
            name, d ? d->rows
                   : std::vector<items::MiscItemRow>()).first;
    }
    return it->second;
}



// ---- the arms list (52 rows) ----

// The chart row count (the print: 52 arms rows).
inline int eqcArmsCount() {
    // the two printed columns together, alphabetical
    return (int)eqView("equipment_arms").size();
}

// The arms row name at index i (clamped), the print order.
inline const char* eqcArmsName(int i) {
    const auto& rows = eqView("equipment_arms");
    if (rows.empty()) return "";   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].name.c_str();
}

// The arms price in gold pieces (the silver rows pin 0
// here - exactly one unit nonzero per row).
inline int eqcArmsGold(int i) {
    const auto& rows = eqView("equipment_arms");
    if (rows.empty()) return 0;   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].qtyLo == 3 ? rows[i].gp : 0;
}

// The arms price in silver pieces (the six ammo rows).
inline int eqcArmsSilver(int i) {
    const auto& rows = eqView("equipment_arms");
    if (rows.empty()) return 0;   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].qtyLo == 2 ? rows[i].gp : 0;
}

// ---- the armor list (14 rows) ----

// The armor row count (the print: 14 armor rows).
inline int eqcArmorCount() {
    // the two printed columns together, alphabetical
    return (int)eqView("equipment_armor").size();
}

// The armor row name at index i (clamped), the print order.
inline const char* eqcArmorName(int i) {
    const auto& rows = eqView("equipment_armor");
    if (rows.empty()) return "";   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].name.c_str();
}

// The armor price in gold pieces (every armor row prints
// in gold).
inline int eqcArmorGold(int i) {
    // every armor row prints in gold
    const auto& rows = eqView("equipment_armor");
    if (rows.empty()) return 0;   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].qtyLo == 3 ? rows[i].gp : 0;
}

// ---- the general lists (R308) ----

// The EIGHT printed general lists of the BASIC
// EQUIPMENT AND SUPPLIES COSTS tables (the
// equipment section, upload lines 2344-2437; the
// reference-sheet repeat, upload lines 13473-13541):
// clothing 11 rows, herbs 3, livestock 21,
// miscellaneous equipment and items 29, provisions
// 10, religious items 6, tack and harness 9,
// transport 10 - 99 rows together. Every price pins
// in its printed coin (exactly one coin column
// nonzero per row: 11 copper, 29 silver, 59 gold).
// The row order is the R300 arms convention (the
// left column then the right, per list). The
// reference sheet is the complete legible copy: it
// resolves the scrambled herbs cells and the eight
// transport cells the equipment-section OCR drops.

// The chart row count (the print: 99 general rows).
inline int eqcGeneralCount() {
    return (int)eqView("equipment_general").size();
}

// The list row count at list index l (clamped):
// clothing 0, herbs 1, livestock 2, miscellaneous
// equipment and items 3, provisions 4, religious
// items 5, tack and harness 6, transport 7.
inline int eqcGeneralListCount(int l) {
    if (l < 0) l = 0;
    if (l > 7) l = 7;
    const auto* d = eqReg().find("equipment_general");
    if (!d) return 0;   // defensive: unloaded view
    for (const auto& t : d->tables)
        if (t.name == "list_counts")
            return (int)t.values[l];
    return 0;
}

// The first row of list l (clamped).
inline int eqcGeneralFirst(int l) {
    if (l < 0) l = 0;
    if (l > 7) l = 7;
    const auto* d = eqReg().find("equipment_general");
    if (!d) return 0;   // defensive: unloaded view
    for (const auto& t : d->tables)
        if (t.name == "list_first")
            return (int)t.values[l];
    return 0;
}

// The general row name at index i (clamped), the
// R300 name spellings (the foot marks spelled out;
// the ampersands read as and; the riding-light
// horse parens dropped). The two print apostrophe
// names ride as printed; the holy symbol and holy
// water rows serve the unholy footnote equally.
inline const char* eqcGeneralName(int i) {
    const auto& rows = eqView("equipment_general");
    if (rows.empty()) return "";   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].name.c_str();
}

// The general price in gold pieces (clamped; the 59
// gold rows).
inline int eqcGeneralGold(int i) {
    // the 59 gold rows
    const auto& rows = eqView("equipment_general");
    if (rows.empty()) return 0;   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].qtyLo == 3 ? rows[i].gp : 0;
}

// The general price in silver pieces (clamped; the
// 29 silver rows).
inline int eqcGeneralSilver(int i) {
    // the 29 silver rows
    const auto& rows = eqView("equipment_general");
    if (rows.empty()) return 0;   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].qtyLo == 2 ? rows[i].gp : 0;
}

// The general price in copper pieces (clamped; the
// 11 copper rows).
inline int eqcGeneralCopper(int i) {
    // the 11 copper rows
    const auto& rows = eqView("equipment_general");
    if (rows.empty()) return 0;   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].qtyLo == 1 ? rows[i].gp : 0;
}

// The monetary-system pins (the upload MONETARY
// SYSTEM section: 200 c.p. = 20 s.p. = 1 g.p.): the
// R300 silver pin and the R308 copper pins.
inline int eqcSilverPerGold() {
    return 20;
}

inline int eqcCopperPerSilver() {
    return 10;
}

inline int eqcCopperPerGold() {
    return 200;
}

}  // namespace rules
