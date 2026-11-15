// ===========================================================================
// Adnd1 - rules/ua/uasocialclass.h
// The UA SOCIAL CLASS AND RANK (p. 82 print) pins,
// R367: the Social Class Table (the nine-band dice
// ladder), the occupation rosters, the starting-money
// note, the non-human placements and the profession
// rule. Extends the landed R208 DMG structure header
// (rules/dmg/socialrank.h), which pins the government
// forms and the town structure but no random class
// table - the UA print adds the dice table.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the LLC roster label cell garbles ("Typloat
//     LLC: members Freed of...") - the roster list
//     itself reads; the label cell is flagged, the
//     names pin.
//   - the halfling placement prints "ULC (they are
//     small and rustic)" - the parenthetical reads
//     against the printed band; the print wins, the
//     divergence flagged pending the PDF.
//   - R394: the clean PDF read fills the LLC
//     label cell (the roster head is Freed
//     slaves) and confirms the halfling
//     parenthetical.
//   - the R336 seam: the cavalier money stations name
//     the LMC/MMC/UMC/LUC/MUC/UUC bands exactly - the
//     band names pin to the R336 spellings.
// ===========================================================================

#pragma once

// R1056 applied
#include "rules/ua/uaregistry.h"

namespace rules {

// ---- the nine bands, in social-ladder order ----
inline int uasocBandCount()
    { return 9; }

inline int uasocBandLow(int i) {
    const auto* g = uaTable(
        "ua_socialclass", "band_low");
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    if (!g) return 1;
    return (int)(*g)[i];
}

inline int uasocBandHigh(int i) {
    const auto* g = uaTable(
        "ua_socialclass", "band_high");
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    if (!g) return 4;
    return (int)(*g)[i];
}

inline const char* uasocBandFullName(int i) {
    const auto& rows = uaRows("ua_socialclass");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

inline const char* uasocBandAbbr(int i) {
    const auto& rows = uaRows("ua_socialclass_abbr");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// ---- the occupation rosters, per band ----
inline int uasocRosterCount(int i) {
    const auto* g = uaTable(
        "ua_socialclass", "roster_count");
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    if (!g) return 8;
    return (int)(*g)[i];
}

inline const char* uasocRosterName(int i, int j) {
    const auto& rows = uaRows("ua_socialclass_roster");
    const auto* cnt = uaTable("ua_socialclass",
        "roster_count");
    const auto* off = uaTable("ua_socialclass",
        "roster_offset");
    if (rows.empty() || !cnt || !off)
        return "";
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    if (j < 0) j = 0;
    int c = (int)(*cnt)[i];
    if (j >= c)
        j = c - 1;
    return rows[(int)(*off)[i]
        + j].name.c_str();
}

// The R394 clean read: the LLC label
// cell reads clean.
inline bool uasocLlcLabelCellGarbled()
    { return false; }

// ---- the intro reads ----
// The table does not include any social or political
// information; guidelines follow the table so the DM
// can model the class distinctions to the tenor of
// the individual milieu.
inline bool uasocTableExcludesPoliticalInfo()
    { return true; }

inline bool uasocGuidelinesFollowTheTable()
    { return true; }

inline bool uasocDmModelsToMilieu()
    { return true; }

// ---- the starting-money note ----
// For player characters, initial social status has
// no effect on starting money and equipment, with
// the exception of cavaliers and paladins (the Money
// heading cross-reference, the landed R336 seam).
inline bool uasocPcStartMoneyUnaffected()
    { return true; }

inline bool uasocExceptCavaliersAndPaladins()
    { return true; }

inline bool uasocCavPaladinSeeMoneyHeading()
    { return true; }

// ---- the non-human placements ----
inline bool uasocDwarvesMMC()
    { return true; }

inline bool uasocDwarvesGoldGemsReputation()
    { return true; }

inline bool uasocWoodElfULC()
    { return true; }

inline bool uasocGrayElfLUC()
    { return true; }

inline bool uasocGnomeULCToLMC()
    { return true; }

inline bool uasocHalflingULC()
    { return true; }

// The R394 clean read: the halfling
// parenthetical confirms the ULC
// band.
inline bool uasocHalflingParentheticalDivergence()
    { return false; }

inline bool uasocHalfElfSlightlyAboveHuman()
    { return true; }

inline bool uasocHalfOrcLLC()
    { return true; }

inline bool uasocNonHumanPlacementMilieuDependent()
    { return true; }

// ---- the profession rule ----
// A character must have a social status of, at the
// lowest, one rank below that specified for the
// profession in the milieu; the printed example: a
// fighter needs Middle Lower Class or higher, so a
// Lower Lower Class character can be only a thief
// or assassin.
inline bool uasocProfessionOneRankBelowMinimum()
    { return true; }

inline bool uasocFighterRequiresMlcMinimum()
    { return true; }

inline bool uasocLlcBornOnlyThiefOrAssassin()
    { return true; }

}   // namespace rules

