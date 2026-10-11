// ===========================================================================
// Adnd1 - rules/cavmoney.h
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

namespace rules {

// ---- the stations (p. 25), in social-ladder order ----
inline int cavMoneyStationCount()
    { return 6; }

inline const char* cavMoneyStationName(int i) {
    static const char* const k[6] = {
        "Lower Middle Class or less",
        "Middle Middle Class",
        "Upper Middle Class",
        "Lower Upper Class",
        "Middle Upper Class",
        "Upper Upper Class"
    };
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return k[i];
}

// 0 = Horseman (0-level track), 1 = Cavalier (1st-level Armiger).
inline const char* cavMoneyStationEntry(int i) {
    static const char* const k[6] = {
        "Horseman", "Horseman", "Horseman",
        "Cavalier", "Cavalier", "Cavalier"
    };
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return k[i];
}

// ---- the gold ranges (p. 25) ----
inline int cavMoneyGoldLow(int i) {
    static const int k[6] = {20, 20, 20, 70, 70, 130};
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return k[i];
}

inline int cavMoneyGoldHigh(int i) {
    static const int k[6] = {80, 80, 80, 180, 180, 180};
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return k[i];
}

// ---- the printed formulas (p. 25) ----
// Count 0 = no formula printed (the three Horseman
// rows); faces and bonus read 0 with it.
inline int cavMoneyDiceCount(int i) {
    static const int k[6] = {0, 0, 0, 1, 1, 1};
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return k[i];
}

inline int cavMoneyDiceFaces(int i) {
    static const int k[6] = {0, 0, 0, 12, 6, 6};
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return k[i];
}

inline int cavMoneyDiceBonus(int i) {
    static const int k[6] = {0, 0, 0, 6, 6, 12};
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return k[i];
}

// The printed formulas are plain rolls TIMES 10
// gold pieces - the PHB convention (the R190 seam).
// Verified: (1d12+6) x 10 = 70-180 and (1d6+12)
// x 10 = 130-180, the printed ranges.
inline bool cavMoneyGoldRollTimesTen()
    { return true; }

// ---- the equipment lists (p. 25) ----
inline int cavMoneyItemCount(int i) {
    static const int k[6] = {3, 4, 4, 6, 6, 7};
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return k[i];
}

inline const char* cavMoneyItemName(
        int station, int j) {
    static const char* const s0[3] = {
        "shield", "sword (any type)",
        "riding horse"
    };
    static const char* const s1[4] = {
        "shield", "dagger",
        "sword (broad or long)", "light warhorse"
    };
    static const char* const s2[4] = {
        "chain mail", "sword (broad or long)",
        "lance", "light warhorse"
    };
    static const char* const s3[6] = {
        "shield", "plate mail", "dagger",
        "sword (long or broad)", "lance",
        "medium warhorse"
    };
    static const char* const s4[6] = {
        "shield", "field plate armor", "dagger",
        "sword (long or broad)", "lance",
        "heavy warhorse"
    };
    static const char* const s5[7] = {
        "shield", "full plate armor", "dagger",
        "sword (long or broad)", "mace", "lance",
        "heavy warhorse with leather barding"
    };
    if (station < 0) station = 0;
    if (station > 5) station = 5;
    if (j < 0) j = 0;
    switch (station) {
        case 0:
            if (j > 2) j = 2;
            return s0[j];
        case 1:
            if (j > 3) j = 3;
            return s1[j];
        case 2:
            if (j > 3) j = 3;
            return s2[j];
        case 3:
            if (j > 5) j = 5;
            return s3[j];
        case 4:
            if (j > 5) j = 5;
            return s4[j];
        default:
            if (j > 6) j = 6;
            return s5[j];
    }
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