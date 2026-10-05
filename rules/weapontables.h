// ============================================================================
// Adnd1 - rules/weapontables.h
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
// ============================================================================

#pragma once

#include <cstdint>

namespace rules {

// ---- the weight and damage chart ----

static const int WEAPON_CHART_ROWS = 50;

// The chart row count (the print: 50 weapons).
inline int weaponChartRowCount() { return WEAPON_CHART_ROWS; }

// The weapon name at index i (clamped to 0-49),
// the print order.
inline const char* weaponChartName(int i) {
    static const char* const kNames[50] = {
        "arrow",
        "battle axe",
        "hand axe",
        "bardiche",
        "bec de corbin",
        "bill-guisarme",
        "bo stick",
        "club",
        "dagger",
        "dart",
        "fauchard",
        "fauchard-fork",
        "footman flail",
        "horseman flail",
        "military fork",
        "glaive",
        "glaive-guisarme",
        "guisarme",
        "guisarme-voulge",
        "halberd",
        "lucern hammer",
        "hammer",
        "javelin",
        "jo stick",
        "lance, light horse",
        "lance, medium horse",
        "lance, heavy horse",
        "footman mace",
        "horseman mace",
        "morning star",
        "partisan",
        "footman pick",
        "horseman pick",
        "awl pike",
        "light quarrel",
        "heavy quarrel",
        "ranseur",
        "scimitar",
        "sling bullet",
        "sling stone",
        "spear",
        "spetum",
        "quarterstaff",
        "bastard sword",
        "broad sword",
        "long sword",
        "short sword",
        "two-handed sword",
        "trident",
        "voulge",
    };
    if (i < 0) i = 0;
    if (i > 49) i = 49;
    return kNames[i];
}

// The approximate weight in gold pieces (the
// spear prints 40-60; this reads the minimum).
inline int weaponChartWeight(int i) {
    static const int kWeight[50] = {
        2,
        75,
        50,
        125,
        100,
        150,
        15,
        30,
        10,
        5,
        60,
        80,
        150,
        35,
        75,
        75,
        100,
        80,
        150,
        175,
        150,
        50,
        20,
        40,
        50,
        100,
        150,
        100,
        50,
        125,
        80,
        60,
        40,
        80,
        1,
        2,
        50,
        40,
        2,
        1,
        40,
        50,
        50,
        100,
        75,
        60,
        35,
        250,
        50,
        125,
    };
    if (i < 0) i = 0;
    if (i > 49) i = 49;
    return kWeight[i];
}

// The damage vs. size S or M opponents: the
// min and max of the printed range.
inline int weaponChartDamageSMMin(int i) {
    static const int kMin[50] = {
        1,
        1,
        1,
        2,
        1,
        2,
        1,
        1,
        1,
        1,
        1,
        1,
        2,
        2,
        1,
        1,
        2,
        2,
        2,
        1,
        2,
        2,
        1,
        1,
        1,
        2,
        3,
        2,
        1,
        2,
        1,
        2,
        2,
        1,
        1,
        2,
        2,
        1,
        2,
        1,
        1,
        2,
        1,
        2,
        2,
        1,
        1,
        1,
        2,
        2,
    };
    if (i < 0) i = 0;
    if (i > 49) i = 49;
    return kMin[i];
}

inline int weaponChartDamageSMMax(int i) {
    static const int kMax[50] = {
        6,
        8,
        6,
        8,
        8,
        8,
        6,
        6,
        4,
        3,
        6,
        8,
        7,
        5,
        8,
        6,
        8,
        8,
        8,
        10,
        8,
        5,
        6,
        6,
        6,
        7,
        9,
        7,
        6,
        8,
        6,
        7,
        5,
        6,
        4,
        5,
        8,
        8,
        5,
        4,
        6,
        7,
        6,
        8,
        8,
        8,
        6,
        10,
        7,
        8,
    };
    if (i < 0) i = 0;
    if (i > 49) i = 49;
    return kMax[i];
}

// The damage vs. size L opponents: the min
// and max of the printed range.
inline int weaponChartDamageLMin(int i) {
    static const int kMin[50] = {
        1,
        1,
        1,
        3,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        2,
        2,
        2,
        1,
        2,
        1,
        2,
        2,
        1,
        1,
        1,
        1,
        1,
        2,
        3,
        1,
        1,
        2,
        2,
        2,
        1,
        1,
        1,
        2,
        2,
        1,
        2,
        1,
        1,
        2,
        1,
        2,
        2,
        1,
        1,
        3,
        3,
        2,
    };
    if (i < 0) i = 0;
    if (i > 49) i = 49;
    return kMin[i];
}

inline int weaponChartDamageLMax(int i) {
    static const int kMax[50] = {
        6,
        8,
        4,
        12,
        6,
        10,
        3,
        3,
        3,
        2,
        8,
        10,
        8,
        5,
        8,
        10,
        12,
        8,
        8,
        12,
        6,
        4,
        6,
        4,
        8,
        12,
        18,
        6,
        4,
        7,
        7,
        8,
        4,
        12,
        4,
        7,
        8,
        8,
        7,
        4,
        8,
        12,
        6,
        16,
        7,
        12,
        8,
        18,
        12,
        8,
    };
    if (i < 0) i = 0;
    if (i > 49) i = 49;
    return kMax[i];
}

// The spear weight spread: the print 40-60.
inline void spearWeightRange(int& lo, int& hi) {
    lo = 40; hi = 60;
}

// ---- the speed verify (the R189 duty) ----

// The count of engine-named weapons whose
// printed speed factor was readable and
// verified against the R158 ladder.
inline int weaponSpeedVerifiedCount() { return 18; }

// The i-th verified pair: the engine weapon
// name and its printed speed factor (the
// spear entry is the engine default 7 of
// the printed 6-8 spread).
inline const char* weaponSpeedVerifiedName(int i) {
    static const char* const kNames[18] = {
        "fist",
        "dagger",
        "short sword",
        "hammer",
        "club",
        "hand axe",
        "quarterstaff",
        "scimitar",
        "long sword",
        "broad sword",
        "horseman mace",
        "spear",
        "footman mace",
        "footman flail",
        "morning star",
        "battle axe",
        "two-handed sword",
        "pike",
    };
    if (i < 0) i = 0;
    if (i > 17) i = 17;
    return kNames[i];
}

inline int weaponSpeedVerifiedFactor(int i) {
    static const int kFactor[18] = {
        1,
        2,
        3,
        4,
        4,
        4,
        4,
        4,
        5,
        5,
        6,
        7,
        7,
        7,
        7,
        7,
        10,
        13,
    };
    if (i < 0) i = 0;
    if (i > 17) i = 17;
    return kFactor[i];
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

    static const char* const kCleric[7] = {
        "club", "footman flail", "horseman flail",
        "hammer", "footman mace", "horseman mace",
        "quarterstaff"
    };
    static const char* const kDruid[9] = {
        "club", "dagger", "dart", "hammer", "scimitar",
        "sling bullet", "sling stone", "spear",
        "quarterstaff"
    };
    static const char* const kMuIll[3] = {
        "dagger", "dart", "quarterstaff"
    };
    static const char* const kThief[8] = {
        "club", "dagger", "dart", "sling bullet",
        "sling stone", "short sword", "broad sword",
        "long sword"
    };
    static const char* const kMonk[24] = {
        "bo stick", "club", "crossbow", "dagger",
        "hand axe", "javelin", "jo stick", "spear",
        "quarterstaff",
        "bardiche", "bec de corbin", "bill-guisarme",
        "fauchard", "fauchard-fork", "military fork",
        "glaive", "glaive-guisarme", "guisarme",
        "guisarme-voulge", "halberd", "partisan",
        "ransseur", "spetum", "voulge"
    };

inline bool classUsesAnyWeapon(int cls) {
    return cls == 2 || cls == 3 || cls == 4 || cls == 8;
}

// The allowed weapon count, -1 on the any-weapon rows.
inline int classAllowedWeaponCount(int cls) {
    if (classUsesAnyWeapon(cls)) return -1;
    if (cls == 0) return 7;    // cleric
    if (cls == 1) return 9;    // druid
    if (cls == 5 || cls == 6) return 3;    // MU, illusionist
    if (cls == 7) return 8;    // thief
    if (cls == 9) return 24;   // monk
    return 0;
}

// The allowed chart name at index i (clamped).
inline const char* classAllowedWeaponName(int cls, int i) {
    if (i < 0) i = 0;
    if (cls == 0) {
        if (i > 6) i = 6;
        return kCleric[i];   // cleric
    }
    if (cls == 1) {
        if (i > 8) i = 8;
        return kDruid[i];   // druid
    }
    if (cls == 5) {
        if (i > 2) i = 2;
        return kMuIll[i];   // MU and illusionist
    }
    if (cls == 6) {
        if (i > 2) i = 2;
        return kMuIll[i];   // illusionist, the same list
    }
    if (cls == 7) {
        if (i > 7) i = 7;
        return kThief[i];   // thief
    }
    if (cls == 9) {
        if (i > 23) i = 23;
        return kMonk[i];   // monk
    }
    return "club";   // out-of-range clamps
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
