// ============================================================================
// Adnd1 - rules/phb/weapontables.h
// The weapon weight and damage table (R189).
//
// The PHB WEIGHT AND DAMAGE BY WEAPON TYPE chart (50 rows,
// every printed cell): the approximate weight in gold pieces,
// the damage vs. size S or M opponents and the damage vs. size
// L. The speed-factor verify of the WEAPON TYPES chart and the
// printed combat notes ride with it.
//
// JUDGMENTs:
//   - the spear weight prints 40-60 (grip-dependent); it pins
//     as a range - weaponWeight reads the minimum 40,
//     spearWeightRange exposes the spread.
//   - the SPEED VERIFY (the R189 duty): every readable cell of
//     the WEAPON TYPES speed column confirms the R158 engine
//     ladder row for row (the 18 named weapons below). The
//     horseman flail chart cell is OCR-mangled, so the engine
//     6 stays ENGINE CONVENTION, recorded. The partisan prints
//     9, the awl pike 13, the voulge 10, the partisan-family
//     pole arms all readable - none are engine weapons yet.
//   - the R144/R145 p.38 AC-adjustment standing note CLOSES:
//     R149 book-verified 8 of the 15 engine rows cell for cell
//     against this upload; the remaining AC cells are
//     OCR-mangled (digit runs like -1000000 where single
//     modifiers belong) and stay pinned to the 1eonline.info
//     compilation - the repo-trusted source. The engine
//     approximations R149 named (the full-effective-AC column,
//     the every-defender rows, the below-0 clamp) stand.
//   - the italics roster of the first chart footnote (the
//     pole arms that do double damage vs. L when SET to
//     receive a charge) is not recoverable from this OCR -
//     recorded, not pinned. The explicit asterisked notes ARE
//     pinned: the three lances do twice indicated damage
//     against any size when employed from a charging mount;
//     the spear set to receive a charge does twice damage to
//     any opponent.
//   - the chart-2 combat note pins as constants: any weapon
//     strikes +2 against a back or similarly unseen opponent,
//     +4 against stunned, prone and motionless opponents.
//
// DATA-DRIVEN (the standing scope).
//
// R1043: the chart, speed and allowlist rows are
// registry-native (content/tables/weapons/, the seam
// below); the printed arrays are gone from this
// header and the accessors read registry views. The
// combat note constants and the oil/poison columns
// stay in-file (constants, not tables).
// ============================================================================

#pragma once

#include <cstdint>

#include "items/MiscItemRegistry.h"   // R1043: the weapon tables ride the registry

namespace rules {

// ---- the R1043 registry seam ----------------------------------------
// The weapon chart, the speed verify list and the five
// class allowlists ride items::MiscItemRegistry from
// content/tables/weapons/ (set names = def keys). Chart
// row encoding: band = { i, i } the print row index,
// gp the printed weight in gold pieces (the spear
// minimum 40), qty the S-M damage pair, xp/xp_hi the L
// damage pair. Speed rows pin the factor in gp; list
// rows are name-only. This seam is header-only like the
// module (the R1040/R1042 idiom); every signature below
// is unchanged (the r158/r189/r198/r337 audits and the
// combat engine pin them); the clamp semantics stay
// verbatim.

inline items::MiscItemRegistry& wtReg() {
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory("content/tables/weapons");
    }
    return reg;
}

// the registry-backed per-view cache (the R1032-R1042
// idiom; function-local statics in inline functions are
// shared across TUs)
inline const std::vector<items::MiscItemRow>& wtView(
        const char* name) {
    static std::map<std::string,
        std::vector<items::MiscItemRow>> cache;
    auto it = cache.find(name);
    if (it == cache.end()) {
        const items::MiscItemDef* d = wtReg().find(name);
        it = cache.emplace(
            name, d ? d->rows
                   : std::vector<items::MiscItemRow>()).first;
    }
    return it->second;
}


// ---- the weight and damage chart ----

// The chart row count (the print: 50 weapons).
inline int weaponChartRowCount() {
    return (int)wtView("weapon_chart").size();
}


// The weapon name at index i (clamped to 0-49),
// the print order.
inline const char* weaponChartName(int i) {
    const auto& rows = wtView("weapon_chart");
    if (rows.empty()) return "";   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].name.c_str();
}

// The approximate weight in gold pieces (the
// spear prints 40-60; this reads the minimum).
inline int weaponChartWeight(int i) {
    const auto& rows = wtView("weapon_chart");
    if (rows.empty()) return 0;   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].gp;
}

// The damage vs. size S or M opponents: the
// min and max of the printed range.
inline int weaponChartDamageSMMin(int i) {
    const auto& rows = wtView("weapon_chart");
    if (rows.empty()) return 0;   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].qtyLo;
}

inline int weaponChartDamageSMMax(int i) {
    const auto& rows = wtView("weapon_chart");
    if (rows.empty()) return 0;   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].qtyHi;
}

// The damage vs. size L opponents: the min
// and max of the printed range.
inline int weaponChartDamageLMin(int i) {
    const auto& rows = wtView("weapon_chart");
    if (rows.empty()) return 0;   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].xp;
}

inline int weaponChartDamageLMax(int i) {
    const auto& rows = wtView("weapon_chart");
    if (rows.empty()) return 0;   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].xpHi;
}

// The spear weight spread: the print 40-60.
inline void spearWeightRange(int& lo, int& hi) {
    lo = 40; hi = 60;
}

// ---- the speed verify (the R189 duty) ----

// The count of engine-named weapons whose
// printed speed factor was readable and
// verified against the R158 ladder.
inline int weaponSpeedVerifiedCount() {
    return (int)wtView("weapon_speed").size();
}


// The i-th verified pair: the engine weapon
// name and its printed speed factor (the
// spear entry is the engine default 7 of
// the printed 6-8 spread).
inline const char* weaponSpeedVerifiedName(int i) {
    const auto& rows = wtView("weapon_speed");
    if (rows.empty()) return "";   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].name.c_str();
}

inline int weaponSpeedVerifiedFactor(int i) {
    const auto& rows = wtView("weapon_speed");
    if (rows.empty()) return 0;   // defensive: unloaded view
    if (i < 0) i = 0;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].gp;
}

// ---- the printed notes ----

// The three lances do twice the indicated
// damage against creatures of any size when
// employed by an attacker riding a charging
// mount (the chart asterisk).
inline bool lanceChargingDouble(int i) {
    return i >= 24 && i <= 26;   // the three lance rows
}

// The spear set to receive a charge does
// twice the damage to any opponent (the
// chart double asterisk).
inline bool spearSetChargingDouble() {
    return true;
}

// The chart-2 combat note: any weapon
// strikes +2 against a back or similarly
// unseen opponent.
inline int weaponBackOrUnseenBonus() { return 2; }

// ... and +4 against stunned, prone and
// motionless opponents.
inline int weaponStunnedProneMotionlessBonus() {
    return 4;
}

// ----------------------------------------------------------------------------
// R198: the class weapon allowlists - the CHARACTER CLASSES
// TABLE II weapons column (the print, cell for cell). The
// class rows in the printed order:
//   0 cleric, 1 druid, 2 fighter, 3 paladin, 4 ranger,
//   5 magic-user, 6 illusionist, 7 thief, 8 assassin,
//   9 monk.
// The fighter, paladin, ranger and assassin rows read any
// - classUsesAnyWeapon; the limited rows name the chart
// rows they allow. JUDGMENTs: the family words expand to
// the chart variants - flail = footman and horseman flail,
// mace = footman and horseman mace, staff = quarterstaff,
// sling = sling bullet and sling stone, hammer = the plain
// hammer alone - the lucern hammer is a pole arm, not the
// cleric print row. The thief footnote: short, broad or
// long sword but not bastard or two-handed. The monk pole
// arm = the chart 15 pole-arm rows below; the awl pike and
// the picks stay out. The crossbow prints no chart row of
// its own - only its quarrels do - so it pins by name for
// the monk and no one else.
// ----------------------------------------------------------------------------


inline bool classUsesAnyWeapon(int cls) {
    return cls == 2 || cls == 3 || cls == 4 || cls == 8;
}

// The allowed weapon count, -1 on the any-weapon rows.
inline int classAllowedWeaponCount(int cls) {
    if (classUsesAnyWeapon(cls)) return -1;
    switch (cls) {
    case 0: return (int)wtView("weapon_cleric").size();   // cleric
    case 1: return (int)wtView("weapon_druid").size();   // druid
    case 5: case 6:
        return (int)wtView("weapon_mu_illusionist").size();  // MU, illusionist
    case 7: return (int)wtView("weapon_thief").size();   // thief
    case 9: return (int)wtView("weapon_monk").size();   // monk
    default: return 0;
    }
}

// The allowed chart name at index i (clamped).
inline const char* classAllowedWeaponName(int cls, int i) {
    if (i < 0) i = 0;
    const char* key = 0;
    int n = 0;
    switch (cls) {
    case 0: key = "weapon_cleric"; n = 7; break;   // cleric
    case 1: key = "weapon_druid"; n = 9; break;   // druid
    case 5: key = "weapon_mu_illusionist"; n = 3; break;   // MU
    case 6: key = "weapon_mu_illusionist"; n = 3; break;   // illusionist
    case 7: key = "weapon_thief"; n = 8; break;   // thief
    case 9: key = "weapon_monk"; n = 24; break;   // monk
    default: return "club";   // out-of-range clamps
    }
    const auto& rows = wtView(key);
    if (rows.empty()) return "club";   // defensive
    if (i >= n) i = n - 1;
    if (i >= (int)rows.size()) i = (int)rows.size() - 1;
    return rows[i].name.c_str();
}

// The engine question: can class cls use the named
// weapon? The any-weapon rows take everything.
inline bool weaponAllowedForClass(int cls,
                                   const char* weaponName) {
    if (weaponName == 0) return false;
    if (classUsesAnyWeapon(cls)) return true;
    int n = classAllowedWeaponCount(cls);
    if (n <= 0) return false;
    for (int i = 0; i < n; ++i) {
        const char* a = classAllowedWeaponName(cls, i);
        const char* b = weaponName;
        while (*a && *b && *a == *b) { ++a; ++b; }
        if (*a == 0 && *b == 0) return true;   // exact match
    }
    return false;
}

// ----------------------------------------------------------------------------
// R199: the oil and poison columns of the CHARACTER CLASSES
// TABLE II - the two columns right of the weapons column
// R198 pinned. The allowance encoding, both columns:
//   1 = yes, 0 = never, -1 = referee discretion.
// Oil: yes for every class but the monk - the monk cell
// prints no, and the monk prose confirms: not even
// flaming oil is usable by them. Poison: cleric never -
// the footnote: the prohibition is strictly for clerics
// not of evil alignment; paladin never, assassin yes,
// every other class the question mark - the Note
// Regarding Poison: the referee so allows.
// ----------------------------------------------------------------------------

// The three-valued allowance encoding, both columns:
// 1 = yes, 0 = never, -1 = referee discretion.
inline int classAllowanceYes() { return 1; }
inline int classAllowanceNever() { return 0; }
inline int classAllowanceReferee() { return -1; }

// The Oil column, cell for cell. The class rows
// in the printed order: 0 cleric, 1 druid, 2 fighter,
// 3 paladin, 4 ranger, 5 magic-user, 6 illusionist,
// 7 thief, 8 assassin, 9 monk. The monk cell prints no.
inline int classOilUse(int cls) {
    if (cls == 9) return 0;    // the monk: not even
                                // flaming oil
    return 1;    // yes - every other class row
}

// The Poison column, cell for cell. The cleric
// cell prints never - but the footnote makes it
// strictly for clerics not of evil alignment;
// see classPoisonUseForAlignment below.
inline int classPoisonUse(int cls) {
    if (cls == 0) return 0;    // cleric: never
    if (cls == 3) return 0;    // paladin: never
    if (cls == 8) return 1;    // assassin: yes
    return -1;   // the question mark: the referee
                 // so allows - druid, fighter,
                 // ranger, MU, illusionist, thief,
                 // monk
}

// The cleric footnote, the alignment modifier: the
// poison prohibition is strictly for clerics NOT
// of evil alignment. An evil cleric reads the
// discretion the footnote grants; a non-evil cleric
// stays never. The paladin never is unconditional.
// isEvil: the caller reads the alignment axis - here
// a bool, true = evil.
inline int classPoisonUseForAlignment(int cls,
                                        bool isEvil) {
    if (cls == 0 && isEvil) return -1;   // the footnote
    return classPoisonUse(cls);
}

} // namespace rules
