// ===========================================================================
// Adnd1 - rules/classtables.h
// The UA Character Classes Tables I and
// II (pp. 12-13) pins (R327).
//
// Table I: the Hit Die column (cavalier
// d10, barbarian d12, ranger d8 with two
// dice at 1st, monk d4 with two dice at
// 1st), the note-1 social-standing
// generators (the cavalier and paladin
// 1st-level hp 4-13 via 3d4+1 on the
// 0-level track or d10+3 Upper Class),
// the dice maxima (ranger 11 at the 10th,
// monk 18 at the 17th), the druid class
// level limit (23, Hierophant of the
// Cabal) and the spell-ability legs
// (notes 2, 4, 5).
//
// Table II: the station footnotes for
// the cavalier and paladin (no leather,
// padded or studded leather armor; no
// pole arms or missile weapons; the oil
// siege-warfare exception) and the
// acrobat as-thief-plus row. The weapon
// and oil/poison columns of the ten
// landed classes ride the R198/R199
// pins (rules/weapontables.h) - not
// re-pinned here.
//
// Pin-era pattern (R322): pinned data
// only - no engine site exists. The
// cavalier and barbarian level ladders
// ride their own class rounds (the
// registry is data-driven; append the
// rows there).
// ===========================================================================

#pragma once

#include "subraces.h"  // UaClass (the 14)

namespace rules {

// ---- Table I, the Hit Die column ----
// The UA grain (the four classes the
// gap report names); the PHB classes
// read the engine registry.
inline int uaClassHitDie(UaClass c) {
    switch (c) {
        case UACLASS_CAVALIER:
            return 10;
        case UACLASS_BARBARIAN:
            return 12;
        case UACLASS_RANGER:
            return 8;
        case UACLASS_MONK:
            return 4;
        default:
            return 0;   // the PHB classes:
                        // the registry read
    }
}

// The first-level dice count (notes 3
// and 6: the ranger 2d8 and the monk 2d4
// starts).
inline int uaClassFirstLevelDice(
        UaClass c) {
    if (c == UACLASS_RANGER
        || c == UACLASS_MONK)
        return 2;
    return 1;
}

// ---- Table I note 1: the cavalier and
// paladin 1st-level generators (the
// social-standing read; both tracks
// yield the printed 4-13 range) ----
enum CavalierTrack : int {
    CAVALIER_TRACK_ZERO = 0,  // the 0-level
                              // track: 3d4+1
    CAVALIER_TRACK_UPPER = 1  // Upper Class:
                              // d10+3
};

inline int cavalierTrackDice(
        int track) {
    return track == CAVALIER_TRACK_UPPER
        ? 1 : 3;
}

inline int cavalierTrackSides(
        int track) {
    return track == CAVALIER_TRACK_UPPER
        ? 10 : 4;
}

inline int cavalierTrackBonus(
        int track) {
    return track == CAVALIER_TRACK_UPPER
        ? 3 : 1;
}

// ---- Table I: the dice maxima (notes 3
// and 6) and the druid limit ----
inline int rangerMaxHitDice()
    { return 11; }
inline int rangerMaxHitDiceLevel()
    { return 10; }
inline int monkMaxHitDice()
    { return 18; }
inline int monkMaxHitDiceLevel()
    { return 17; }

// The druid Class Level Limit (Table I:
// 23, Hierophant of the Cabal).
inline int druidClassLevelLimit()
    { return 23; }

// ---- Table I, the spell-ability legs
// (notes 2, 4 and 5) ----
// Paladin: clerical spells from the 9th,
// up to 4th level of power.
inline int paladinClericalFromLevel()
    { return 9; }
inline int paladinClericalMaxSpellLevel()
    { return 4; }

// Ranger: druidic from the 8th up to 3rd;
// magic-user from the 9th up to 2nd.
inline int rangerDruidicFromLevel()
    { return 8; }
inline int rangerDruidicMaxSpellLevel()
    { return 3; }
inline int rangerMuFromLevel()
    { return 9; }
inline int rangerMuMaxSpellLevel()
    { return 2; }

// Thief 10th and assassin 12th: the
// scroll-reading ability (note 5).
inline int thiefScrollFromLevel()
    { return 10; }
inline int assassinScrollFromLevel()
    { return 12; }

// ---- Table II, the footnotes ----
// Footnote 1: the cavalier and paladin
// will not wear leather, padded or
// studded leather armor (beneath the
// station), and will not use pole arms
// or missile weapons (the lower social
// classes).
inline bool uaStationArmorBan(UaClass c) {
    return c == UACLASS_CAVALIER
        || c == UACLASS_PALADIN;
}

inline bool uaStationWeaponBan(
        UaClass c) {
    return c == UACLASS_CAVALIER
        || c == UACLASS_PALADIN;
}

// Footnote 2: oil is unacceptable to
// the cavalier and paladin in personal
// combat, but allowed in siege warfare.
inline bool uaOilSiegeException(
        UaClass c) {
    return c == UACLASS_CAVALIER
        || c == UACLASS_PALADIN;
}

// The acrobat row: armor and weapons as
// thief, plus lasso and staff.
inline int acrobatExtraWeaponCount()
    { return 2; }
inline const char* acrobatExtraWeaponName(
        int i) {
    static const char* const k[2] = {
        "lasso", "staff"
    };
    if (i < 0) i = 0;
    if (i > 1) i = 1;
    return k[i];
}

}   // namespace rules