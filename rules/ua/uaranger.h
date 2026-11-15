// ===========================================================================
// Adnd1 - rules/ua/uaranger.h
// The UA ranger expansion (pp. 21-22) pins (R333).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The registry rows and the creation-flow gates ride their own rounds.
//
// Scope = the gap-report item: the tracking rules, the giant-class
// combat bonus, the spell progression. The spell bands (druidic from
// the 8th up to 3rd, magic-user from the 9th up to 2nd) already ride
// the R327 pins and the R184 spell layers - cross-checked in the
// audit, not re-pinned here (the UA prose restating them is OCR-lost
// from the extract). The ranger weapons rules (the bow-or-crossbow
// requirement, the four required types by 4th level) are NOT in the
// gap item - they ride a later round.
//
// OCR holes documented in-header: the per-creature-beyond-first and
// per-hour-of-precipitation modifier values are lost; the indoor
// surface-condition table cells are lost (the prose fixes the same
// four-category ladder via the next-lower-category and -50%
// references); the movement-rate-while-tracking table's six rows
// survive but every rate cell is lost; the identification table's
// level column is empty (the ladder is fixed by the internal
// "As Nth level" references); the roster's "anoll" cell decodes as
// gnoll (the g->a OCR slip; the alphabetical column confirms).
// ===========================================================================

#pragma once

// R1056 applied
#include "rules/ua/uaregistry.h"

namespace rules {

// ---- the outdoor tracking base (p. 21) ----
// 10% per level plus an additional 10% (20% at 1st, 70% at 6th);
// the base rises as high as 110% (10th level or higher) and never
// more; an adjusted chance over 100% is treated as 100%.
inline int uaRangerTrackBasePerLevel()
    { return 10; }

inline int uaRangerTrackBaseBonus()
    { return 10; }

inline int uaRangerTrackBaseCap()
    { return 110; }

inline int uaRangerTrackAdjustedCap()
    { return 100; }

inline int uaRangerTrackBaseAt(int level) {
    if (level < 1) return 0;
    int p = 10 * level + 10;
    return p > 110 ? 110 : p;
}

// ---- the terrain modifiers (p. 21) ----
// Four categories: soft +20%, occasional marks +10%, infrequent 0%,
// minutest-traces -50%. Intelligent hiding drops one category; at
// the -50% category tracking is impossible.
inline int uaRangerTrackTerrainCategoryCount()
    { return 4; }

inline int uaRangerTrackTerrainModifier(int category) {
    const auto* g = uaTable(
        "ua_ranger", "terrain_mod");
    if (category < 0) category = 0;
    if (category > 3) category = 3;
    if (!g) return 20;
    return (int)(*g)[category];
}

inline bool uaRangerTrackHideDropsCategory()
    { return true; }

inline bool uaRangerTrackHideAtRockBottomImpossible()
    { return true; }

// ---- the other modifiers (p. 21) ----
// -5% per 12 hours elapsed since the trail was made. The
// per-creature-beyond-first and per-hour-of-precipitation values
// are OCR-lost (documented above) - not pinned.
inline int uaRangerTrackPer12Hours()
    { return 5; }

// ---- the indoor tracking (p. 21) ----
// Same base chance; the surface-condition ladder runs the same four
// categories (prose-verified); intelligent hiding (even through a
// secret door) drops one category, impossible at the bottom;
// indoors is impossible without an observed distinguishing feature
// and a follow-up within 10-30 minutes of the quarry making the
// trail.
inline bool uaRangerTrackIndoorBaseSame()
    { return true; }

inline bool uaRangerTrackIndoorObservationRequired()
    { return true; }

inline int uaRangerTrackFollowWindowLow()
    { return 10; }

inline int uaRangerTrackFollowWindowHigh()
    { return 30; }

// ---- the light and movement reads (p. 21) ----
// Good illumination assumed; total darkness is impossible without
// non-visual evidence; the tracking movement rate is slowed even at
// best (the six-row rate table's cells are OCR-lost).
inline bool uaRangerTrackGoodLightAssumed()
    { return true; }

inline bool uaRangerTrackTotalDarknessImpossible()
    { return true; }

inline int uaRangerTrackMoveRowCount()
    { return 6; }

// ---- the tracking-quality definitions (p. 21) ----
// Obvious 71% or better; occasional 31-70%; faint 30% or less;
// poor illumination is anything under daylight over total darkness.
inline int uaRangerTrackObviousMin()
    { return 71; }

inline int uaRangerTrackOccasionalLow()
    { return 31; }

inline int uaRangerTrackOccasionalHigh()
    { return 70; }

inline int uaRangerTrackFaintMax()
    { return 30; }

// ---- the identification ladder (p. 21) ----
// Identification needs a second roll at the same chance; the
// abilities are cumulative by level. The level cells are OCR-empty;
// the ladder is fixed by the internal "As Nth level" references.
inline bool uaRangerTrackIdentifySecondRoll()
    { return true; }

inline bool uaRangerTrackIdentifyCumulative()
    { return true; }

inline int uaRangerTrackIdentifyRowCount()
    { return 10; }

inline const char* uaRangerTrackIdentifyAbility(int level) {
    const auto& rows = uaRows("ua_ranger_identify");
    if (rows.empty())
        return "";
    if (level < 1) level = 1;
    if (level > 10) level = 10;
    if ((int)rows.size() <= (level - 1))
        return "";
    return rows[level - 1].name.c_str();
}

// ---- the giant class (p. 22) ----
// The damage bonus: +1 point per ranger level when a giant-class
// creature is engaged. The expanded roster: the 11 Players
// Handbook creatures (the R184 pins) plus the Fiend Folio and
// Monster Manual II additions, 22 in all, stored lowercase and
// sorted (the R184 matching convention); the garbled "anoll" cell
// decodes as gnoll.
inline int uaRangerGiantDamagePerLevel()
    { return 1; }

inline int uaRangerGiantRosterCount()
    { return 22; }

inline int uaRangerGiantRosterPhbCount()
    { return 11; }

inline const char* uaRangerGiantRosterName(int i) {
    const auto& rows = uaRows("ua_ranger");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 21) i = 21;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

}   // namespace rules