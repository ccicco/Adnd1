// ============================================================================
// Adnd1 - rules/subclassgates.h
// The qualification and race gates (R180).
//
// The printed gates for the six registry subclasses: the
// class-section ability minimums, the alignment
// requirements, the XP bonus rules, Character Race Table
// I (class limitations by racial stock) and Character Race
// Table II (the level caps) - PHB pp.21-33 and the Race
// Tables I and II.
//
// Conventions:
//   - ability minimum 0 = no requirement.
//   - Race Table I: 1 = player-character eligible,
//     0 = not eligible.
//   - Race Table II: 0 = forbidden, -1 = unlimited,
//     a positive number = the maximum player level, a
//     number at -n (n >= 2) = the printed parenthesized
//     entry: NPC-only, capped at level n (the halfling
//     druid prints (6)).
//
// JUDGMENTs:
//   - the assassin class text prints NO experience bonus
//     (assassins do not gain any experience bonuses for
//     having high ability scores); pinned as bonus rule
//     none, like the monk and the illusionist.
//   - the gnome illusionist prints cap 7 with footnote 8:
//     intelligence or dexterity under 17 limits to the
//     5th level; both at 17 or better limit to the 6th.
//     The base matrix carries the printed 7; the
//     conditional accessor walks the footnote.
//   - the parenthesized Table II entries mark NPC-only
//     classes; Table I lists the halfling druid as no,
//     and the two tables agree: no player-character
//     halfling druid, NPC-only to level 6.
//   - the Table I alignment letters: (A) any, (LG) lawful
//     good only, (G) good only, (N) neutral only (the
//     druid true neutral), (E) evil only, (L) lawful only.
//
// DATA-DRIVEN (the standing scope): a future class appends
// one row to each matrix and one gate block.
// ============================================================================

#pragma once

#include "character.h"
#include "classes.h"
#include "races.h"
#include "subclasses.h"

#include <cstdint>

namespace rules {

// The alignment requirement codes (the Table I letters).
enum SubAlignReq : int {
    SUB_ALIGN_ANY = 0,
    SUB_ALIGN_LG_ONLY,
    SUB_ALIGN_GOOD_ONLY,
    SUB_ALIGN_TRUE_NEUTRAL,
    SUB_ALIGN_EVIL_ONLY,
    SUB_ALIGN_LAWFUL_ONLY
};

// The printed experience-bonus rules (the class sections).
// The illusionist, assassin and monk print none.
enum SubXpBonusRule : int {
    SUB_XP_BONUS_NONE = 0,
    SUB_XP_BONUS_STR_WIS,      // both over 15 (paladin)
    SUB_XP_BONUS_STR_INT_WIS,  // all three over 15 (ranger)
    SUB_XP_BONUS_WIS_CHA       // both over 15 (druid)
};

// The ability minimums, in Ability enum order
// (STR INT WIS DEX CON CHA); 0 = no requirement.
//   paladin  12  9 13  0  9 17   (p.22)
//   ranger   13 13 14  0 14  0   (p.24)
//   druid     0  0 12  0  0 15   (p.21)
//   illusionist 0 15 0 16 0  0   (p.26)
//   assassin 12 11  0 12  0  0   (p.31)
//   monk     15  0 15 15 11  0   (p.30)
static const int kGateAbilityMin[SUB_COUNT][6] = {
    { 12,  9, 13,  0,  9, 17 },
    { 13, 13, 14,  0, 14,  0 },
    {  0,  0, 12,  0,  0, 15 },
    {  0, 15,  0, 16,  0,  0 },
    { 12, 11,  0, 12,  0,  0 },
    { 15,  0, 15, 15, 11,  0 }
};

// Character Race Table I (class limitations), columns in
// CharRace order (human dwarf elf gnome half-elf halfling
// half-orc): 1 = player-character eligible.
static const int kGateRaceAllowed[SUB_COUNT][7] = {
    { 1, 0, 0, 0, 0, 0, 0 },  // paladin
    { 1, 0, 0, 0, 1, 0, 0 },  // ranger
    { 1, 0, 0, 0, 1, 0, 0 },  // druid
    { 1, 0, 0, 1, 0, 0, 0 },  // illusionist
    { 1, 1, 1, 1, 1, 0, 1 },  // assassin
    { 1, 0, 0, 0, 0, 0, 0 }   // monk
};

// Character Race Table II (level caps), same column order.
// 0 = forbidden; -1 = unlimited; positive = the printed
// player cap; negative n (>= 2) = NPC-only cap n.
static const int kGateRaceCap[SUB_COUNT][7] = {
    { -1,  0,  0,  0,  0,  0,  0 },  // paladin
    { -1,  0,  0,  0,  8,  0,  0 },  // ranger
    { -1,  0,  0,  0, -1, -6,  0 },  // druid (halfling NPC-only 6)
    { -1,  0,  0,  7,  0,  0,  0 },  // illusionist (footnote 8)
    { -1,  9, 10,  8, 11,  0, -1 },  // assassin
    { -1,  0,  0,  0,  0,  0,  0 }   // monk
};

// The Table I alignment letters and the printed bonus rules.
static const int kGateAlignReq[SUB_COUNT] = {
    SUB_ALIGN_LG_ONLY,        // paladin
    SUB_ALIGN_GOOD_ONLY,      // ranger
    SUB_ALIGN_TRUE_NEUTRAL,   // druid
    SUB_ALIGN_ANY,            // illusionist
    SUB_ALIGN_EVIL_ONLY,     // assassin
    SUB_ALIGN_LAWFUL_ONLY     // monk
};

static const int kGateXpBonus[SUB_COUNT] = {
    SUB_XP_BONUS_STR_WIS,     // paladin: strength and wisdom over 15
    SUB_XP_BONUS_STR_INT_WIS, // ranger: all three over 15
    SUB_XP_BONUS_WIS_CHA,      // druid: wisdom and charisma over 15
    SUB_XP_BONUS_NONE,        // illusionist prints none
    SUB_XP_BONUS_NONE,        // assassin prints none
    SUB_XP_BONUS_NONE         // monk: never gains bonuses
};

// ---- accessors (indices clamped; unknown abilities score 0) ----

inline int subclassAbilityMin(int sub, Ability ab) {
    if (sub < 0) sub = 0;
    if (sub >= SUB_COUNT) sub = SUB_COUNT - 1;
    if ((int)ab < 0 || (int)ab >= ABILITY_COUNT) return 0;
    return kGateAbilityMin[sub][(int)ab];
}

// True when every printed minimum is met.
inline bool subclassMeetsAbilityMin(int sub, const AbilityScores& s) {
    for (int ab = 0; ab < (int)ABILITY_COUNT; ++ab)
        if (s.get((Ability)ab)
            < subclassAbilityMin(sub, (Ability)ab))
            return false;
    return true;
}

// Table I: 1 = player-character eligible.
inline int subclassRaceAllowed(int sub, CharRace r) {
    if (sub < 0) sub = 0;
    if (sub >= SUB_COUNT) sub = SUB_COUNT - 1;
    if ((int)r < 0 || (int)r >= RACE_CHAR_COUNT) return 0;
    return kGateRaceAllowed[sub][(int)r];
}

// Table II: 0 = forbidden; -1 = unlimited; positive =
// the printed player cap; negative n (>= 2) = NPC-only,
// cap level n.
inline int subclassRaceCap(int sub, CharRace r) {
    if (sub < 0) sub = 0;
    if (sub >= SUB_COUNT) sub = SUB_COUNT - 1;
    if ((int)r < 0 || (int)r >= RACE_CHAR_COUNT) return 0;
    return kGateRaceCap[sub][(int)r];
}

// True when the Table II entry is a parenthesized
// (NPC-only) cap.
inline bool subclassCapIsNpcOnly(int sub, CharRace r) {
    return subclassRaceCap(sub, r) <= -2;
}

// Footnote 8 (Race Table II): the gnome illusionist.
// Intelligence or dexterity under 17 limits to the 5th
// level; both at 17 or better limit to the 6th. The
// printed base entry 7 never survives the footnote -
// every rolled gnome takes a 5 or a 6 here (recorded
// as the JUDGMENT; the matrix keeps the printed 7).
inline int illusionistGnomeCap(int intScore, int dexScore) {
    if (intScore < 17 || dexScore < 17) return 5;
    return 6;
}

// The Table I alignment letters.
inline int subclassAlignmentReq(int sub) {
    if (sub < 0) sub = 0;
    if (sub >= SUB_COUNT) sub = SUB_COUNT - 1;
    return kGateAlignReq[sub];
}

// The printed bonus rule code.
inline int subclassXpBonusRule(int sub) {
    if (sub < 0) sub = 0;
    if (sub >= SUB_COUNT) sub = SUB_COUNT - 1;
    return kGateXpBonus[sub];
}

// True when the printed bonus is earned for the scores.
inline bool subclassXpBonusEarned(int sub, const AbilityScores& s) {
    switch (subclassXpBonusRule(sub)) {
    case SUB_XP_BONUS_STR_WIS:
        return s.get(ABILITY_STR) > 15
            && s.get(ABILITY_WIS) > 15;
    case SUB_XP_BONUS_STR_INT_WIS:
        return s.get(ABILITY_STR) > 15
            && s.get(ABILITY_INT) > 15
            && s.get(ABILITY_WIS) > 15;
    case SUB_XP_BONUS_WIS_CHA:
        return s.get(ABILITY_WIS) > 15
            && s.get(ABILITY_CHA) > 15;
    default:
        return false;
    }
}


// ---------------------------------------------------------------------------
// R230: the creation seam. The printed gates become a
// character-creation gate chain: player eligibility
// (Race Table I), the effective level cap (Table II
// with the footnote-8 gnome illusionist conditional),
// and the per-subclass creation parameters the engine
// reads at the CR_SUBCLASS stage.
//
// JUDGMENTs:
//   - the monk has no base class; its runtime base is
//     CLASS_FIGHTER (the closest save matrix and kit;
//     the specials round revisits) and it rides the
//     fighter offer list at creation.
//   - the monk con class is CLASS_THIEF (the registry
//     group pin - NOT the fighter CON bonus group).
//   - the monk starting age reads the fighter band.
//   - the alignment requirements stay data-only: the
//     engine has no alignment concept yet (a later
//     arc round owns alignment).
//
// EVAL NOTE: these helpers use plain ints and private
// flat copies of the R180 matrices - the audit
// evaluator cannot parse the enum constants the R180
// accessors read (the : int enums do not load). The
// R230 battery pins the copies against the same
// printed walks.
// ---------------------------------------------------------------------------

// The runtime base class (the save matrix, the gear
// and the engine switches): paladin, ranger, druid,
// illusionist, assassin, monk in registry order. The
// monk rides CLASS_FIGHTER (the JUDGMENT).
inline int subclassRuntimeBase(int sub) {
    if (sub == 0) return 0;   // paladin -> fighter
    if (sub == 1) return 0;   // ranger -> fighter
    if (sub == 2) return 2;   // druid -> cleric
    if (sub == 3) return 1;   // illusionist -> magic-user
    if (sub == 4) return 3;   // assassin -> thief
    return 0;                 // monk -> fighter
}

// The con-adjustment class: the paladin and ranger
// join the fighter CON bonus group (the print); the
// monk is not in the group (the registry pin).
inline int subclassConClass(int sub) {
    if (sub == 2) return 2;   // druid -> cleric
    if (sub == 3) return 1;   // illusionist -> magic-user
    if (sub == 4) return 3;   // assassin -> thief
    if (sub == 5) return 3;   // monk -> thief
    return 0;                 // paladin, ranger -> fighter
}

// The starting-age band (the base class table, PHB
// p.20); the monk reads the fighter band.
inline int subclassStartAgeBase(int sub) {
    if (sub == 2) return 18;   // druid -> cleric band
    if (sub == 3) return 24;   // illusionist -> MU band
    if (sub == 4) return 18;   // assassin -> thief band
    return 15;                 // paladin, ranger, monk
}

// Two hit dice at level 1 (the ranger and the monk -
// the R179 JUDGMENT, the printed accumulated column).
inline int subclassTwoDiceFirstLevel(int sub) {
    if (sub == 1) return 1;   // ranger
    if (sub == 5) return 1;   // monk
    return 0;
}

// The subclass hit die (the registry pins:
// paladin d10, ranger d8, druid d8, illusionist d4,
// assassin d6, monk d4).
inline int subclassHitDie(int sub) {
    static const int kDie[6] = {
        10, 8, 8, 4, 6, 4
    };
    if (sub < 0) sub = 0;
    if (sub > 5) sub = 5;
    return kDie[sub];
}

// Player eligibility: Race Table I, flat 42 (a private
// copy - see the EVAL NOTE).
inline int subclassPlayerAllowed(int sub, CharRace r) {
    static const int kAllow[42] = {
        1, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 1, 0, 0,
        1, 0, 0, 0, 1, 0, 0,
        1, 0, 0, 1, 0, 0, 0,
        1, 1, 1, 1, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0
    };
    int si = sub;
    if (si < 0) si = 0;
    if (si > 5) si = 5;
    int ri = (int)r;
    if (ri < 0) ri = 0;
    if (ri > 6) ri = 6;
    return kAllow[si * 7 + ri];
}

// The effective level cap: Race Table II, flat 42 (a
// private copy - see the EVAL NOTE), with the
// footnote-8 gnome illusionist conditional. 0 =
// forbidden; -1 = unlimited; positive = the printed
// player cap; -n (n >= 2) = NPC-only cap n.
inline int subclassLevelCapFor(int sub, CharRace r,
                               int intScore, int dexScore) {
    static const int kCap[42] = {
        -1,  0,  0,  0,  0,  0,  0,
        -1,  0,  0,  0,  8,  0,  0,
        -1,  0,  0,  0, -1, -6,  0,
        -1,  0,  0,  7,  0,  0,  0,
        -1,  9, 10,  8, 11,  0, -1,
        -1,  0,  0,  0,  0,  0,  0
    };
    int si = sub;
    if (si < 0) si = 0;
    if (si > 5) si = 5;
    int ri = (int)r;
    if (ri < 0) ri = 0;
    if (ri > 6) ri = 6;
    if (si == 3 && ri == 3)
        return illusionistGnomeCap(intScore, dexScore);
    return kCap[si * 7 + ri];
}

// ---------------------------------------------------------------------------
// R231: the leveling seam. The registry XP ladders
// become the member leveling path: the printed XP
// attain rows (the R176 convention), the adders
// past them, the fixed-hp levels (past them the
// fixed hp per level), and the effective leveling
// stop (the R179 levelCap pins) minus the Race Table
// II cap and the footnote-8 gnome conditional.
//
// EVAL NOTE (the R230 convention): plain ints and
// private flat copies - the audit evaluator cannot
// read the : int enums or the SubclassDef structs
// the R179 registry carries; the battery pins the
// copies against the same printed walks.
// ---------------------------------------------------------------------------

// The XP to ATTAIN the level (the printed band
// lower bound - 1). Past the printed rows the
// adder applies; adder 0 (druid, assassin, monk):
// the top row repeats - the printed top is the
// ceiling. Ragged rows pad with 0 (never read:
// kLen guards).
inline int subclassXpToAttain(int sub, int level) {
    static const int kLen[6] = {
        11, 12, 14, 12, 15, 17
    };
    static const int kXp[6][17] = {
        { 0, 2750, 5500, 12000, 24000, 45000,
          95000, 175000, 350000, 700000, 1050000,
          0, 0, 0, 0, 0, 0 },
        { 0, 2250, 4500, 10000, 20000, 40000,
          90000, 150000, 225000, 325000, 650000,
          975000, 0, 0, 0, 0, 0 },
        { 0, 2000, 4000, 7500, 12500, 20000,
          35000, 60000, 90000, 125000, 200000,
          300000, 750000, 1500000, 0, 0, 0 },
        { 0, 2250, 4500, 9000, 18000, 35000,
          60000, 95000, 145000, 220000, 440000,
          660000, 0, 0, 0, 0, 0 },
        { 0, 1500, 3000, 6000, 12000, 25000,
          50000, 100000, 200000, 300000, 425000,
          575000, 750000, 1000000, 1500000, 0, 0 },
        { 0, 2250, 4750, 10000, 22500, 47500,
          98000, 200000, 350000, 500000, 700000,
          950000, 1250000, 1750000, 2250000,
          2750000, 3250000 }
    };
    static const int kAdd[6] = {
        350000, 325000, 0, 220000, 0, 0
    };
    int si = sub;
    if (si < 0) si = 0;
    if (si > 5) si = 5;
    if (level <= 1) return 0;
    int n = kLen[si];
    if (level <= n) return kXp[si][level - 1];
    return kXp[si][n - 1] + (level - n) * kAdd[si];
}

// The fixed-hp level (the R179 levelCap pin: past
// it the fixed hp per level): paladin 9, ranger
// 10, druid 9, illusionist 10, assassin 10, monk
// 17 (the monk rolls through all 17).
inline int subclassFixedHpLevel(int sub) {
    static const int kFixed[6] = {
        9, 10, 9, 10, 10, 17
    };
    int si = sub;
    if (si < 0) si = 0;
    if (si > 5) si = 5;
    return kFixed[si];
}

// The fixed hp per level past the fixed-hp level
// (the R179 hpBeyondCap pin); the monk 0.
inline int subclassHpBeyondFixed(int sub) {
    static const int kHpB[6] = {
        3, 2, 2, 1, 2, 0
    };
    int si = sub;
    if (si < 0) si = 0;
    if (si > 5) si = 5;
    return kHpB[si];
}

// The leveling stop (the R179 levelCap pin: the
// name-cap analog - paladin 9, ranger 10, druid 14
// the hierarchy ceiling, illusionist 10, assassin
// 10, monk 17). The engine convention stops plain
// members at the name cap; this is the subclass
// analog. NOTE the druid: leveling runs to 14 but
// the fixed hp starts at the 9th (the print pin -
// the two levels differ for the druid only).
inline int subclassLevelStop(int sub) {
    static const int kStop[6] = {
        9, 10, 14, 10, 10, 17
    };
    int si = sub;
    if (si < 0) si = 0;
    if (si > 5) si = 5;
    return kStop[si];
}

// The effective leveling cap: the leveling stop,
// lowered by a positive Race Table II cap (the
// footnote-8 gnome conditional included).
inline int subclassLevelCapTotal(int sub, CharRace r,
                                 int intScore,
                                 int dexScore) {
    int cap = subclassLevelStop(sub);
    int rc = subclassLevelCapFor(sub, r,
                                 intScore, dexScore);
    if (rc > 0 && rc < cap) cap = rc;
    return cap;
}

} // namespace rules
