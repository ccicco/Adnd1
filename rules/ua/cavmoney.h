// ===========================================================================
// Adnd1 - rules/ua/cavmoney.h
// The UA Starting Money and Equipment for Cavaliers (p. 25) pins
// (R336).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs:
//   - the six stations pin in social-ladder order: the three
//     Horseman rows (Lower Middle Class or less, Middle Middle,
//     Upper Middle) then the three Cavalier rows (Lower Upper,
//     Middle Upper, Upper Upper). The UMC row prints no shield
//     and no dagger - pinned exactly as printed.
//   - the gold: the two printed formulas, (1d12 + 6) and
//     (1d6 + 12), are plain rolls TIMES 10 - the PHB convention
//     landed as the R190 seam. Verified, not inferred: 7-18 x 10
//     = 70-180 and 13-18 x 10 = 130-180, the printed ranges. The
//     three Horseman rows print only "20-80 gp" with no formula -
//     the range pins, the formula does not (the 2d4 x 10 guess
//     is NOT pinned).
//   - the equipment lists pin item-by-item exactly as printed;
//     the UUC horse prints as one item, "heavy warhorse with
//     leather barding".
//
// OCR holes: none in the section. The paladin is the one hole:
// the DMG note (pp. 88-89) excepts "cavaliers and paladins" from
// the social-class exemption, but the UA section details
// cavaliers only - the paladin money rules are not printed here
// (pinned as the exception's existence; the specifics stay a
// hole pending the PDF).
// ===========================================================================

#pragma once

// R1056 applied
#include "rules/ua/uaregistry.h"

namespace rules {

// ---- the stations (p. 25), in social-ladder order ----
inline int cavMoneyStationCount()
    { return 6; }

inline const char* cavMoneyStationName(int i) {
    const auto& rows = uaRows("ua_cavmoney");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// 0 = Horseman (0-level track), 1 = Cavalier (1st-level Armiger).
inline const char* cavMoneyStationEntry(int i) {
    const auto& rows = uaRows("ua_cavmoney_entry");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// ---- the gold ranges (p. 25) ----
inline int cavMoneyGoldLow(int i) {
    const auto* g = uaTable(
        "ua_cavmoney", "gold_low");
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    if (!g) return 20;
    return (int)(*g)[i];
}

inline int cavMoneyGoldHigh(int i) {
    const auto* g = uaTable(
        "ua_cavmoney", "gold_high");
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    if (!g) return 80;
    return (int)(*g)[i];
}

// ---- the printed formulas (p. 25) ----
// Count 0 = no formula printed (the three Horseman
// rows); faces and bonus read 0 with it.
inline int cavMoneyDiceCount(int i) {
    const auto* g = uaTable(
        "ua_cavmoney", "dice_count");
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int cavMoneyDiceFaces(int i) {
    const auto* g = uaTable(
        "ua_cavmoney", "dice_faces");
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int cavMoneyDiceBonus(int i) {
    const auto* g = uaTable(
        "ua_cavmoney", "dice_bonus");
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    if (!g) return 0;
    return (int)(*g)[i];
}

// The printed formulas are plain rolls TIMES 10
// gold pieces - the PHB convention (the R190 seam).
// Verified: (1d12+6) x 10 = 70-180 and (1d6+12)
// x 10 = 130-180, the printed ranges.
inline bool cavMoneyGoldRollTimesTen()
    { return true; }

// ---- the equipment lists (p. 25) ----
inline int cavMoneyItemCount(int i) {
    const auto* g = uaTable(
        "ua_cavmoney", "item_count");
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    if (!g) return 3;
    return (int)(*g)[i];
}

inline const char* cavMoneyItemName(
        int station, int j) {
    const auto& rows = uaRows("ua_cavmoney_items");
    const auto* cnt = uaTable("ua_cavmoney",
        "item_count");
    const auto* off = uaTable("ua_cavmoney",
        "item_offset");
    if (rows.empty() || !cnt || !off)
        return "";
    if (station < 0) station = 0;
    if (station > 5) station = 5;
    if (j < 0) j = 0;
    int c = (int)(*cnt)[station];
    if (j >= c)
        j = c - 1;
    return rows[(int)(*off)[station]
        + j].name.c_str();
}

// ---- the prose pins (p. 25) ----
inline bool cavMoneyHorsesCompleteWithTack()
    { return true; }

inline bool cavMoneyBelowUpperStartHorseman()
    { return true; }

inline bool cavMoneyBelowUpperEsquired()
    { return true; }

// The DMG note (pp. 88-89): starting money and
// equipment are exempt from social-class effects
// only for cavaliers AND paladins; the section
// details the cavalier only.
inline bool cavMoneyPaladinExceptionNoted()
    { return true; }

}   // namespace rules