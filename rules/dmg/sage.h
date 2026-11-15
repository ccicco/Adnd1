// ===========================================================================
// Adnd1 - rules/dmg/sage.h
// The sage subsection (R310).
//
// The DMG SAGE subsection (upload line 2110):
// the fields-count table, the SAGE FIELDS OF
// STUDY AND SPECIAL KNOWLEDGE CATEGORIES, the
// CHANCE OF KNOWING ANSWER TO A QUESTION table,
// the sage characteristics (the six ability dice
// rows, the nine alignment bands, the 8d4 hit
// points, the spell limits), the SUPPORT and
// SALARY offer table, the efficiency economics
// with the improvement ladder, and the INFORMATION
// DISCOVERY TIME AND COST TABLE.
//
// The fields-count table: 6 dice bands (the minor
// fields and the special categories in the major
// field). The fields: 7 percent bands carrying 68
// special knowledge categories (humankind 12,
// demi-humankind 11, humanoids and giantkind 8,
// the physical universes 10, fauna 10, flora 8,
// supernatural and unusual 9).
//
// SOURCE NOTE: the 1eonline.info compilation
// cross-read agrees on every cell. The upload OCR
// flattened the seven-column print: HISTORY
// HISTORY reads History; HISTORY CHEMISTRY splits
// History (humanoids) and restores CHEMISTRY to
// the physical universes; INSECTS TREES splits
// Insects (fauna) and restores TREES to flora - a
// third transcription confirms both recoveries.
// The chance-of-knowing print row for the major
// field interleaves three bands (61-80, 57-60,
// 26-35); the compilation resolves the order.
//
// The none cells pin -1 (the print dash): the
// out-of-fields exacting chance and the
// out-of-fields exacting time - an exacting
// question outside the fields cannot be answered
// at all. The special-category specific time band
// is the only HOURS cell (1-10 h.); every general
// band is rounds.
//
// The recorded notes ride the pin: the hiring
// restriction (only fighters, paladins, rangers,
// thieves and assassins hire permanently; any
// class may consult short-term - 100 g.p. per day
// plus the question difficulty, one week maximum,
// a one-game-month cooldown after; permanent
// offers are lifetime service only, the sage
// bringing nothing save thinking ability and
// knowledge), the location prose (large towns and
// cities only, near colleges, schools and
// libraries), the spell casting level (the minimum
// class level for the spell; a sage with
// third-level magic-user use casts at 5th), the
// excluded spells (bless, chant, prayer, commune,
// raise dead, commune with nature, contact other
// plane and their reverses), the remote doubler
// (no nearby town doubles times and costs), the
// rest rule (1 day per 3 research days, 1-2 extra
// if bothered) and the unknown-information terms
// (51-100 percent of the maximum time at half
// cost). No engine site charges any of this yet
// (no sage consultation layer exists; the town
// stores price canonically).
//
// DATA-DRIVEN (the standing scope).
// ===========================================================================

#pragma once

// R1054 applied
#include "items/MiscItemRegistry.h"

namespace rules {

// ---- the R1054 registry seam ---------------
// content/tables/dm_sage/ via
// items::MiscItemRegistry: the
// R1042 rows idiom plus named
// tables per def (the R1051 dzTable
// idiom) and the rows readers (the
// R1051 dzRows idiom - the three
// name accessors are rows readers
// now). Header-only singleton (the
// R1040 appendixp.h idiom). Every
// accessor below keeps its
// signature, clamp and branch; only
// the array read moves behind the
// registry. The five [4][3] grids
// retire FLATTENED scope-major;
// the grid accessors keep BOTH
// clamps then read the cell
// [scope * 3 + nature].

inline items::MiscItemRegistry&
szReg() {
    static items::MiscItemRegistry
        reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/"
            "dm_sage");
    }
    return reg;
}

// the name rows of one def (the
// band is the index; the name
// accessors index them 0-based)
inline const std::vector<
    items::MiscItemRow>& szRows(
        const char* key) {
    static std::map<std::string,
        std::vector<
            items::MiscItemRow>>
        cache;
    auto it = cache.find(key);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = szReg().find(key);
        it = cache.emplace(
            key, d ? d->rows
                   : std::vector<
                        items::
                        MiscItemRow>()
                   ).first;
    }
    return it->second;
}

// one named int table of one def
// (null when absent or empty)
inline const std::vector<long
    long>* szTable(const char* key,
                  const char* tag) {
    static std::map<std::string,
        std::vector<long long>>
        cache;
    const std::string kk =
        std::string(key) + "/"
        + tag;
    auto it = cache.find(kk);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = szReg().find(key);
        const std::vector<long
            long>* v = nullptr;
        if (d) {
            for (const auto& t :
                 d->tables) {
                if (t.name == tag) {
                    v = &t.values;
                    break;
                }
            }
        }
        it = cache.emplace(
            kk, v ? *v
                  : std::vector<
                        long long>()
                   ).first;
    }
    return it->second.empty()
        ? nullptr
        : &it->second;
}

// ---- the fields of study ----

// The field count (the print: 7 fields).
inline int sageFieldCount() {
    return 7;
}

// The field name at index f (clamped).
inline const char* sageFieldName(int f) {
    const auto& rows = 
        szRows("dm_sage_fields");
    if (rows.empty())
        return "";
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    if ((int)rows.size() <= f)
        return "";
    return rows[f].name.c_str();
}

// The field percent band low (clamped; the
// seven bands tile 1-100).
inline int sageFieldLo(int f) {
    const auto* g = szTable(
        "dm_sage_fields", "field_lo");
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    if (!g) return 1;
    return (int)(*g)[f];
}

// The field percent band high (clamped).
inline int sageFieldHi(int f) {
    const auto* g = szTable(
        "dm_sage_fields", "field_hi");
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    if (!g) return 30;
    return (int)(*g)[f];
}

// The special knowledge categories in the
// field (clamped).
inline int sageFieldCategoryCount(int f) {
    const auto* g = szTable(
        "dm_sage_fields", "field_category_count");
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    if (!g) return 12;
    return (int)(*g)[f];
}

// The flat index of the first category in the
// field (clamped); the categories run field by
// field in the print order.
inline int sageFieldCategoryFirst(int f) {
    const auto* g = szTable(
        "dm_sage_fields", "field_category_first");
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    if (!g) return 0;
    return (int)(*g)[f];
}

// ---- the special knowledge categories ----

// The category count (the print: 68 categories
// across the seven fields).
inline int sageCategoryCount() {
    return 68;
}

// The category name at flat index i (clamped).
inline const char* sageCategoryName(int i) {
    const auto& rows = 
        szRows("dm_sage_categories");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    if ((int)rows.size() <= i)
        return "";
    return rows[i].name.c_str();
}

// The owning field of the category at flat
// index i (clamped).
inline int sageCategoryField(int i) {
    const auto* g = szTable(
        "dm_sage_categories", "category_field");
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    if (!g) return 0;
    return (int)(*g)[i];
}

// ---- the fields-count table ----

// The dice band count.
inline int sageFieldsBandCount() {
    return 6;
}

// The dice band low (clamped; the six bands
// tile 1-100).
inline int sageFieldsBandLo(int b) {
    const auto* g = szTable(
        "dm_sage_fields", "band_lo");
    if (b < 0) b = 0;
    if (b > 5) b = 5;
    if (!g) return 1;
    return (int)(*g)[b];
}

// The dice band high (clamped).
inline int sageFieldsBandHi(int b) {
    const auto* g = szTable(
        "dm_sage_fields", "band_hi");
    if (b < 0) b = 0;
    if (b > 5) b = 5;
    if (!g) return 10;
    return (int)(*g)[b];
}

// The minor fields in the band (clamped).
inline int sageFieldsBandMinor(int b) {
    const auto* g = szTable(
        "dm_sage_fields", "band_minor");
    if (b < 0) b = 0;
    if (b > 5) b = 5;
    if (!g) return 1;
    return (int)(*g)[b];
}

// The special categories in the major field
// (clamped).
inline int sageFieldsBandSpecial(int b) {
    const auto* g = szTable(
        "dm_sage_fields", "band_special");
    if (b < 0) b = 0;
    if (b > 5) b = 5;
    if (!g) return 2;
    return (int)(*g)[b];
}

// ---- the chance of knowing an answer ----

// The knowing percent band low (both clamped).
// Scope: 0 out of fields, 1 minor field, 2 major
// field, 3 special category. Nature: 0 general,
// 1 specific, 2 exacting. -1 pins the none cell
// (the print dash - an exacting question out of
// the fields cannot be answered at all).
inline int sageKnowLo(int scope, int nature) {
    const auto* g = szTable(
        "dm_sage_knowing", "know_lo");
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    if (!g) return 31;
    return (int)(*g)[scope * 3 + nature];
}

// The knowing percent band high (both clamped).
inline int sageKnowHi(int scope, int nature) {
    const auto* g = szTable(
        "dm_sage_knowing", "know_hi");
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    if (!g) return 50;
    return (int)(*g)[scope * 3 + nature];
}

// The none flag: 1 when the cell prints a dash.
inline int sageKnowNone(int scope, int nature) {
    return sageKnowLo(scope, nature) < 0;
}

// ---- the sage characteristics ----

// The ability row count (0 STR, 1 INT, 2 WIS,
// 3 DEX, 4 CON, 5 CHA).
inline int sageAbilityCount() {
    return 6;
}

// The ability die (clamped).
inline int sageAbilityDice(int a) {
    const auto* g = szTable(
        "dm_sage_characteristics", "ability_dice");
    if (a < 0) a = 0;
    if (a > 5) a = 5;
    if (!g) return 8;
    return (int)(*g)[a];
}

// The ability dice count (clamped).
inline int sageAbilityDiceCount(int a) {
    const auto* g = szTable(
        "dm_sage_characteristics", "ability_dice_count");
    if (a < 0) a = 0;
    if (a > 5) a = 5;
    if (!g) return 1;
    return (int)(*g)[a];
}

// The ability plus (clamped); the score bands
// run plus + count to plus + count * dice.
inline int sageAbilityPlus(int a) {
    const auto* g = szTable(
        "dm_sage_characteristics", "ability_plus");
    if (a < 0) a = 0;
    if (a > 5) a = 5;
    if (!g) return 7;
    return (int)(*g)[a];
}

// The alignment band count (ascending dice
// order; the nine bands tile 1-100).
inline int sageAlignBandCount() {
    return 9;
}

// The alignment band low (clamped).
inline int sageAlignLo(int b) {
    const auto* g = szTable(
        "dm_sage_characteristics", "align_lo");
    if (b < 0) b = 0;
    if (b > 8) b = 8;
    if (!g) return 1;
    return (int)(*g)[b];
}

// The alignment band high (clamped).
inline int sageAlignHi(int b) {
    const auto* g = szTable(
        "dm_sage_characteristics", "align_hi");
    if (b < 0) b = 0;
    if (b > 8) b = 8;
    if (!g) return 5;
    return (int)(*g)[b];
}

// The alignment band name (clamped).
inline const char* sageAlignName(int b) {
    const auto& rows = 
        szRows("dm_sage_characteristics");
    if (rows.empty())
        return "";
    if (b < 0) b = 0;
    if (b > 8) b = 8;
    if ((int)rows.size() <= b)
        return "";
    return rows[b].name.c_str();
}

// The hit points: 8d4 plus the constitution
// bonus as applicable.
inline int sageHpDiceCount() {
    return 8;
}

inline int sageHpDie() {
    return 4;
}

// ---- the spell skills ----

// The spell kind count.
inline int sageSpellKindCount() {
    return 3;
}

// The field spell kind (clamped): 0 clerical,
// 1 druidical, 2 magic-user or illusionist (the
// art and music and legends and folklore
// categories read clerical or magic-user).
inline int sageSpellKind(int f) {
    const auto* g = szTable(
        "dm_sage_fields", "spell_kind");
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    if (!g) return 0;
    return (int)(*g)[f];
}

// The maximum spell level: d4 + 2, the 3-6
// band inclusive.
inline int sageSpellMaxDie() {
    return 4;
}

inline int sageSpellMaxPlus() {
    return 2;
}

inline int sageSpellMaxLo() {
    return 3;
}

inline int sageSpellMaxHi() {
    return 6;
}

// The spells held per level and the ready cap
// (1-4 per level, no more than 1 of each level
// available for use at a time).
inline int sageSpellPerLevelLo() {
    return 1;
}

inline int sageSpellPerLevelHi() {
    return 4;
}

inline int sageSpellReadyPerLevel() {
    return 1;
}

// ---- the employment offer ----

// The offer row count: row 0 the support and
// salary per month (2d6 hundred g.p.), row 1 the
// research grants per month (2d6 hundred g.p.),
// row 2 the initial material expenditure (the
// 20,000 g.p. minimum; lo equals hi).
inline int sageOfferCount() {
    return 3;
}

// The offer row low (clamped; g.p. per month).
inline int sageOfferLo(int i) {
    const auto* g = szTable(
        "dm_sage_terms", "offer_lo");
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    if (!g) return 200;
    return (int)(*g)[i];
}

// The offer row high (clamped; g.p. per month).
inline int sageOfferHi(int i) {
    const auto* g = szTable(
        "dm_sage_terms", "offer_hi");
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    if (!g) return 1200;
    return (int)(*g)[i];
}

// ---- the efficiency economics ----

// The efficiency milestone count.
inline int sageEffMilestoneCount() {
    return 3;
}

// The milestone cost (clamped): 20,000 g.p.
// buys 50 percent, 60,000 reaches 90 and
// 100,000 the full 100 (the specific and
// exacting areas).
inline int sageEffMilestoneCost(int i) {
    const auto* g = szTable(
        "dm_sage_terms", "eff_milestone_cost");
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    if (!g) return 20000;
    return (int)(*g)[i];
}

// The milestone efficiency percent (clamped).
inline int sageEffMilestonePercent(int i) {
    const auto* g = szTable(
        "dm_sage_terms", "eff_milestone_percent");
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    if (!g) return 50;
    return (int)(*g)[i];
}

// The +1 percent step cost to 90 percent.
inline int sageEffStepCost() {
    return 1000;
}

// The +1 percent step cost after 90.
inline int sageEffHighCostPerPercent() {
    return 4000;
}

// ---- the improvement ladder ----

// The improvement row count: row 0 the
// out-of-fields knowledge +1 percent (5,000
// g.p. and a month, max +5), row 1 the
// minor-field ability +1 percent (10,000 g.p.
// and a month, max +5), row 2 an extra minor
// field (100,000 g.p. and two years, three
// maximum), row 3 an extra major field
// (200,000 g.p. and two years; -1 pins no
// stated maximum).
inline int sageImproveCount() {
    return 4;
}

// The improvement cost in g.p. (clamped).
inline int sageImproveCost(int i) {
    const auto* g = szTable(
        "dm_sage_terms", "improve_cost");
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    if (!g) return 5000;
    return (int)(*g)[i];
}

// The improvement time in months (clamped).
inline int sageImproveMonths(int i) {
    const auto* g = szTable(
        "dm_sage_terms", "improve_months");
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    if (!g) return 1;
    return (int)(*g)[i];
}

// The improvement maximum (clamped; -1 pins
// no stated maximum).
inline int sageImproveMax(int i) {
    const auto* g = szTable(
        "dm_sage_terms", "improve_max");
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    if (!g) return 5;
    return (int)(*g)[i];
}

// ---- the information discovery table ----

// The discovery time band low (both clamped).
// Scope and nature read as the knowing table;
// -1 pins the none cell (the print dash).
inline int sageTimeLo(int scope, int nature) {
    const auto* g = szTable(
        "dm_sage_discovery", "time_lo");
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    if (!g) return 1;
    return (int)(*g)[scope * 3 + nature];
}

// The discovery time band high (both clamped).
inline int sageTimeHi(int scope, int nature) {
    const auto* g = szTable(
        "dm_sage_discovery", "time_hi");
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    if (!g) return 6;
    return (int)(*g)[scope * 3 + nature];
}

// The discovery time unit (both clamped):
// 0 rounds, 1 hours, 2 days (the lone HOURS
// cell the special-category specific band).
inline int sageTimeUnit(int scope, int nature) {
    const auto* g = szTable(
        "dm_sage_discovery", "time_unit");
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    if (!g) return 0;
    return (int)(*g)[scope * 3 + nature];
}

// The none flag: 1 when the cell prints a dash.
inline int sageTimeNone(int scope, int nature) {
    return sageTimeLo(scope, nature) < 0;
}

// The g.p. cost per day for the scope (clamped).
inline int sageCostPerDay(int scope) {
    const auto* g = szTable(
        "dm_sage_discovery", "cost_per_day");
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (!g) return 100;
    return (int)(*g)[scope];
}

// The free-cost spread threshold (clamped):
// a knowing roll in the lower 20 percent of
// the spread means the materials are on hand;
// the special category widens to the lower 80
// percent.
inline int sageFreeSpreadPercent(int scope) {
    const auto* g = szTable(
        "dm_sage_discovery", "free_spread_percent");
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (!g) return 20;
    return (int)(*g)[scope];
}

// The unknown-information band: 51-100
// percent of the maximum time.
inline int sageUnknownPercentLo() {
    return 51;
}

inline int sageUnknownPercentHi() {
    return 100;
}

// The unknown-information cost divisor (the
// costs accrue at half the stated amount).
inline int sageUnknownCostDivisor() {
    return 2;
}

// The short-term terms: 100 g.p. per day plus
// the question difficulty, one week maximum,
// a one-game-month cooldown after.
inline int sageShortTermCostPerDay() {
    return 100;
}

inline int sageShortTermMaxDays() {
    return 7;
}

inline int sageShortTermCooldownMonths() {
    return 1;
}

// The permanent offer is lifetime service only.
inline int sagePermanentHireOnly() {
    return 1;
}

}  // namespace rules
