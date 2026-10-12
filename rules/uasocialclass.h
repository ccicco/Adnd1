// ===========================================================================
// Adnd1 - rules/uasocialclass.h
// The UA SOCIAL CLASS AND RANK (p. 82 print) pins,
// R367: the Social Class Table (the nine-band dice
// ladder), the occupation rosters, the starting-money
// note, the non-human placements and the profession
// rule. Extends the landed R208 DMG structure header
// (rules/socialrank.h), which pins the government
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
//   - the R336 seam: the cavalier money stations name
//     the LMC/MMC/UMC/LUC/MUC/UUC bands exactly - the
//     band names pin to the R336 spellings.
// ===========================================================================

#pragma once

namespace rules {

// ---- the nine bands, in social-ladder order ----
inline int uasocBandCount()
    { return 9; }

inline int uasocBandLow(int i) {
    static const int k[9] = {
        1, 5, 11, 21, 36, 56, 88, 97, 100,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline int uasocBandHigh(int i) {
    static const int k[9] = {
        4, 10, 20, 35, 55, 87, 96, 99, 100,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline const char* uasocBandFullName(int i) {
    static const char* const k[9] = {
        "Lower Lower Class",
        "Middle Lower Class",
        "Upper Lower Class",
        "Lower Middle Class",
        "Middle Middle Class",
        "Upper Middle Class",
        "Lower Upper Class",
        "Middle Upper Class",
        "Upper Upper Class",
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline const char* uasocBandAbbr(int i) {
    static const char* const k[9] = {
        "LLC", "MLC", "ULC", "LMC", "MMC",
        "UMC", "LUC", "MUC", "UUC",
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

// ---- the occupation rosters, per band ----
inline int uasocRosterCount(int i) {
    static const int k[9] = {
        8, 10, 7, 8, 8, 9, 9, 6, 3,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline const char* uasocRosterName(int i, int j) {
    static const char* const r0[8] = {
        "slaves", "peasants", "tinkers",
        "vagabonds", "beggars", "criminals",
        "low-level thieves",
        "low-level and mid-level assassins",
    };
    static const char* const r1[10] = {
        "herdsmen", "laborers", "peddlers",
        "actors", "jugglers", "men-at-arms",
        "low-level barbarians",
        "mid-level thieves",
        "high-level assassins",
        "low-level bards",
    };
    static const char* const r2[7] = {
        "freemen", "tradesmen", "petty officers",
        "money-changers", "fences",
        "low-level fighters", "high-level thieves",
    };
    static const char* const r3[8] = {
        "artisans", "craftsmen", "petty merchants",
        "junior officers", "bankers",
        "landless knights", "druids", "rangers",
    };
    static const char* const r4[8] = {
        "landed gentry", "merchants",
        "petty officials", "senior officers",
        "landless petty nobles",
        "mid-level fighters",
        "low-level magic-users",
        "low-level illusionists",
    };
    static const char* const r5[9] = {
        "guild masters", "great merchants",
        "military commanders", "officials",
        "landless nobles", "lesser clerics",
        "high-level fighters",
        "mid-level magic-users",
        "mid-level illusionists",
    };
    static const char* const r6[9] = {
        "great landed gentry",
        "generals and marshals",
        "greater officials", "knights",
        "mid-level clerics", "cavaliers",
        "paladins", "high-level magic-users",
        "high-level illusionists",
    };
    static const char* const r7[6] = {
        "knights", "commanders", "great clerics",
        "nobles", "high-level paladins",
        "very high-level magic-users and"
        " illusionists",
    };
    static const char* const r8[3] = {
        "great nobles", "sovereign nobility",
        "royalty",
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    if (j < 0) j = 0;
    switch (i) {
        case 0:
            if (j > 7) j = 7;
            return r0[j];
        case 1:
            if (j > 9) j = 9;
            return r1[j];
        case 2:
            if (j > 6) j = 6;
            return r2[j];
        case 3:
            if (j > 7) j = 7;
            return r3[j];
        case 4:
            if (j > 7) j = 7;
            return r4[j];
        case 5:
            if (j > 8) j = 8;
            return r5[j];
        case 6:
            if (j > 8) j = 8;
            return r6[j];
        case 7:
            if (j > 5) j = 5;
            return r7[j];
        default:
            if (j > 2) j = 2;
            return r8[j];
    }
}

inline bool uasocLlcLabelCellGarbled()
    { return true; }

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

inline bool uasocHalflingParentheticalDivergence()
    { return true; }

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

