// ====================================================================
// Adnd1 - rules/npcpersonae.h
// R209: the NPC personae facts tables (DMG
// pp.114-115, PERSONAE OF NON-PLAYER
// CHARACTERS) - the ability dice
// adjustments for classed, occupied and
// demi-human NPCs, and the FACTS TABLES:
// alignment, possessions, appearance
// (age and general) and sanity.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// dice and the selection; the tables and
// the resolution rules read here). The
// ability enums are the engine ones
// (rules/character.h); ABILITY_COUNT is
// the none marker in the adjustment
// tables.
//
//   - The table cells are raw ints, the
//     R208 convention: the ability codes
//     are the engine Ability enum order
//     (0 STR, 1 INT, 2 WIS, 3 DEX, 4 CON,
//     5 CHA, 6 = ABILITY_COUNT, the none
//     marker); the facts tables carry
//     their own enum orders, named below.
// Conventions and judgments, named in
// place:
//   - Class order: the print class list
//     order (cleric, druid, fighter,
//     ranger, paladin, magic-user,
//     illusionist, monk, thief, assassin).
//     The pairings are the pinned
//     substance; both the book upload and
//     the live 1eonline compilation carry
//     the same class-to-adjustment map.
//   - The as-fighter rows (ranger,
//     paladin) and the as-thief row
//     (assassin) are expanded in place:
//     the row carries the base adjustments
//     plus its own minimum or extra.
//   - The d10 facts tables are indexed by
//     the roll 1..10 where 10 is the 0
//     face; rolls are clamped (0 and under
//     read 10, over 10 reads 10).
//   - JUDGMENT: the footnote - adjustments
//     are in addition to the PLAYERS
//     HANDBOOK ones, and normal ability
//     limits cannot be exceeded - reads
//     as a clamp to the 3..18 range.
//   - The p.11 die rules: general
//     characters (typical inhabitants and
//     hirelings) read any 1 as a 3 and any
//     6 as a 4; special characters
//     (including henchmen) add +1 to each
//     die of the 3 rolled which scores
//     under 6 in the abilities germane to
//     the profession.
//   - The compilation annotations NOT in
//     the print (the wealth x2/x3/x4
//     multipliers, the sanity reaction
//     percent columns) are excluded.
// ====================================================================

#pragma once

namespace rules {

// -----------------------------------------------------------------------
// The d10 face clamp: the roll 1..10,
// where 10 is the 0 face. Every facts
// table helper reads through this.
// -----------------------------------------------------------------------
inline int npcD10Face(int d) {
    if (d <= 0) return 10;
    if (d > 10) return 10;
    return d;
}

// -----------------------------------------------------------------------
// The classed NPC adjustments (p.114):
// the Minimum Score or Adjustment to
// Ability Dice Roll table. Three
// adjustment slots and three minimum
// slots per class; ABILITY_COUNT / 0
// mean none.
// -----------------------------------------------------------------------
enum NpcPcClass {
    NPCP_CLERIC = 0,
    NPCP_DRUID,
    NPCP_FIGHTER,
    NPCP_RANGER,
    NPCP_PALADIN,
    NPCP_MAGICUSER,
    NPCP_ILLUSIONIST,
    NPCP_MONK,
    NPCP_THIEF,
    NPCP_ASSASSIN,
    NPCP_CLASS_COUNT
};

inline int npcClassCount() { return 10; }

inline int npcClassAdjAbility(int cls, int slot) {
    // cleric wisdom +2; fighter and the
    // as-fighter rows (ranger, paladin)
    // strength +2, constitution +1;
    // magic-user intelligence +2,
    // dexterity +1; thief and the
    // as-thief assassin row dexterity +2,
    // intelligence +1, the assassin adding
    // strength +1; druid, illusionist and
    // monk carry minimums only
    if (cls < 0) cls = 0;
    if (cls > 9) cls = 9;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int a[30] = {
        2, 6, 6,
        6, 6, 6,
        0, 4, 6,
        0, 4, 6,
        0, 4, 6,
        1, 3, 6,
        6, 6, 6,
        6, 6, 6,
        3, 1, 6,
        3, 1, 0,
    };
    return a[cls * 3 + slot];
}

inline int npcClassAdjAmount(int cls, int slot) {
    if (cls < 0) cls = 0;
    if (cls > 9) cls = 9;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int m[30] = {
        2, 0, 0,
        0, 0, 0,
        2, 1, 0,
        2, 1, 0,
        2, 1, 0,
        2, 1, 0,
        0, 0, 0,
        0, 0, 0,
        2, 1, 0,
        2, 1, 1,
    };
    return m[cls * 3 + slot];
}

inline int npcClassMinAbility(int cls, int slot) {
    // druid wisdom/charisma 12/14, ranger
    // wisdom 12, paladin charisma 17,
    // illusionist intelligence/dexterity
    // 15/15, monk strength/wisdom/dexterity
    // 12/15/15; the rest carry none
    if (cls < 0) cls = 0;
    if (cls > 9) cls = 9;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int a[30] = {
        6, 6, 6,
        2, 5, 6,
        6, 6, 6,
        2, 6, 6,
        5, 6, 6,
        6, 6, 6,
        1, 3, 6,
        0, 2, 3,
        6, 6, 6,
        6, 6, 6,
    };
    return a[cls * 3 + slot];
}

inline int npcClassMinValue(int cls, int slot) {
    if (cls < 0) cls = 0;
    if (cls > 9) cls = 9;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int v[30] = {
        0, 0, 0,
        12, 14, 0,
        0, 0, 0,
        12, 0, 0,
        17, 0, 0,
        0, 0, 0,
        15, 15, 0,
        12, 15, 15,
        0, 0, 0,
        0, 0, 0,
    };
    return v[cls * 3 + slot];
}

inline int npcAdjustedAbility(int score, int adj) {
    // the table footnote: in spite of all
    // additions, normal ability limits
    // cannot be exceeded (JUDGMENT: a
    // clamp to the 3..18 ability range)
    int v = score + adj;
    if (v > 18) v = 18;
    if (v < 3) v = 3;
    return v;
}

// -----------------------------------------------------------------------
// The occupation adjustments (p.114):
// laborer strength +1 to +3 (a range);
// mercenary (level 0) strength +1,
// constitution +3, 4 minimum hit points;
// merchant/trader 12/12 minimum
// intelligence/charisma.
// -----------------------------------------------------------------------
enum NpcOccupation {
    NPCO_LABORER = 0,
    NPCO_MERCENARY,
    NPCO_MERCHANT,
    NPCO_COUNT
};

inline int npcOccupationCount() { return 3; }

inline int npcOccupationAdjAbility(int occ, int slot) {
    if (occ < 0) occ = 0;
    if (occ > 2) occ = 2;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int a[9] = {
        0, 6, 6,
        0, 4, 6,
        6, 6, 6,
    };
    return a[occ * 3 + slot];
}

inline int npcOccupationAdjMin(int occ, int slot) {
    if (occ < 0) occ = 0;
    if (occ > 2) occ = 2;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int m[9] = {
        1, 0, 0,
        1, 3, 0,
        0, 0, 0,
    };
    return m[occ * 3 + slot];
}

inline int npcOccupationAdjMax(int occ, int slot) {
    // only the laborer range lifts the max
    // above the min
    if (occ < 0) occ = 0;
    if (occ > 2) occ = 2;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int x[9] = {
        3, 0, 0,
        1, 3, 0,
        0, 0, 0,
    };
    return x[occ * 3 + slot];
}

inline int npcMercenaryMinHitPoints() { return 4; }

inline int npcOccupationMinAbility(int occ, int slot) {
    if (occ < 0) occ = 0;
    if (occ > 2) occ = 2;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int a[9] = {
        6, 6, 6,
        6, 6, 6,
        1, 5, 6,
    };
    return a[occ * 3 + slot];
}

inline int npcOccupationMinValue(int occ, int slot) {
    if (occ < 0) occ = 0;
    if (occ > 2) occ = 2;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int v[9] = {
        0, 0, 0,
        0, 0, 0,
        12, 12, 0,
    };
    return v[occ * 3 + slot];
}

// -----------------------------------------------------------------------
// The DMG demi-human adjustments (p.114) -
// a table of its own, NOT the PHB race
// table: dwarf strength +1, constitution
// +1, charisma -1; elf intelligence +1,
// dexterity +1; gnome wisdom +1,
// constitution +1, charisma -1; halfling
// dexterity +1, constitution +1.
// -----------------------------------------------------------------------
enum NpcDemiRace {
    NPCR_DWARF = 0,
    NPCR_ELF,
    NPCR_GNOME,
    NPCR_HALFLING,
    NPCR_COUNT
};

inline int npcDemiRaceCount() { return 4; }

inline int npcRaceAdjAbility(int race, int slot) {
    if (race < 0) race = 0;
    if (race > 3) race = 3;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int a[12] = {
        0, 4, 5,
        1, 3, 6,
        2, 4, 5,
        3, 4, 6,
    };
    return a[race * 3 + slot];
}

inline int npcRaceAdjAmount(int race, int slot) {
    if (race < 0) race = 0;
    if (race > 3) race = 3;
    if (slot < 0) slot = 0;
    if (slot > 2) slot = 2;
    static const int m[12] = {
        1, 1, -1,
        1, 1, 0,
        1, 1, -1,
        1, 1, 0,
    };
    return m[race * 3 + slot];
}

// -----------------------------------------------------------------------
// The FACTS TABLES (p.115). Alignment
// (d10), possessions (d10), appearance -
// age and general, each rolled separately
// - and sanity with the asterisk reroll
// rule.
// -----------------------------------------------------------------------
enum NpcAlign {
    NPCA_LG = 0,
    NPCA_LN,
    NPCA_LE,
    NPCA_NE,
    NPCA_CE,
    NPCA_CN,
    NPCA_CG,
    NPCA_NG,
    NPCA_TRUE,
    NPCA_COUNT
};

inline int npcFactAlign(int d10) {
    // 1 lawful good, 2 lawful neutral,
    // 3 lawful evil, 4 neutral evil,
    // 5 chaotic evil, 6 chaotic neutral,
    // 7 chaotic good, 8 neutral good,
    // 9 neutral, 0 (10) neutral
    static const int t[10] = {
        0, 1, 2, 3, 4,
        5, 6, 7, 8, 8,
    };
    return t[npcD10Face(d10) - 1];
}

enum NpcWealth {
    NPCW_NONE = 0,
    NPCW_SCANT,
    NPCW_AVERAGE,
    NPCW_ABOVE_AVERAGE,
    NPCW_EXCEPTIONAL,
    NPCW_SUPERABUNDANT,
    NPCW_COUNT
};

inline int npcFactWealth(int d10) {
    // 1 none, 2-3 scant, 4-7 average,
    // 8 above average, 9 exceptional,
    // 0 (10) superabundant
    static const int t[10] = {
        0, 1, 1,
        2, 2, 2,
        2, 3,
        4, 5,
    };
    return t[npcD10Face(d10) - 1];
}

enum NpcAgeBand {
    NPCAGE_YOUNG = 0,
    NPCAGE_YOUTHFUL,
    NPCAGE_MATURE,
    NPCAGE_MIDDLE_AGED,
    NPCAGE_OLD,
    NPCAGE_ANCIENT,
    NPCAGE_BAND_COUNT
};

inline int npcFactAgeBand(int d10) {
    // 1 young, 2-3 youthful, 4-7 mature,
    // 8 middle-aged, 9 old, 0 (10) ancient
    static const int t[10] = {
        0, 1, 1,
        2, 2, 2,
        2, 3,
        4, 5,
    };
    return t[npcD10Face(d10) - 1];
}

enum NpcGeneralLook {
    NPCG_DIRTY = 0,
    NPCG_CLEAN,
    NPCG_UNKEPT,
    NPCG_IMMACULATE,
    NPCG_ROUGH,
    NPCG_RAGGED,
    NPCG_DANDYISH,
    NPCG_FOPPISH,
    NPCG_NONDESCRIPT,
    NPCG_IMPOSING,
    NPCG_LOOK_COUNT
};

inline int npcFactGeneralLook(int d10) {
    // the ten general appearance words,
    // each on its own face: dirty, clean,
    // unkempt, immaculate, rough, ragged,
    // dandyish, foppish, non-descript,
    // imposing
    static const int t[10] = {
        0, 1, 2,
        3, 4, 5,
        6, 7,
        8, 9,
    };
    return t[npcD10Face(d10) - 1];
}

enum NpcSanity {
    NPCS_VERY_STABLE = 0,
    NPCS_NORMAL,
    NPCS_NEUROTIC,
    NPCS_UNSTABLE,
    NPCS_INSANE,
    NPCS_MANIACAL,
    NPCS_SANITY_COUNT
};

inline int npcFactSanity(int d10) {
    // 1 very stable, 2-6 normal,
    // 7 neurotic, 8 unstable, 9 insane,
    // 0 (10) maniacal - the insane and
    // maniacal faces carry the asterisk
    static const int t[10] = {
        0, 1, 1,
        1, 1, 1,
        2, 3,
        4, 5,
    };
    return t[npcD10Face(d10) - 1];
}

inline bool npcSanityIsMarked(int level) {
    // the asterisk rows: insane and
    // maniacal are rolled again
    return level == NPCS_INSANE || level == NPCS_MANIACAL;
}

inline int npcSanityResolved(int firstRoll, int secondRoll) {
    // the asterisk rule: roll again, and
    // if either insane or maniacal is
    // indicated a second time, the
    // character then conforms to that
    // sanity level; in all other cases the
    // second roll stands in place of the
    // first
    if (npcSanityIsMarked(npcFactSanity(firstRoll)))
        return npcFactSanity(secondRoll);
    return npcFactSanity(firstRoll);
}

// -----------------------------------------------------------------------
// The p.11 die rules and the tendencies
// floor.
// -----------------------------------------------------------------------
inline int npcGeneralCharacterDie(int die) {
    // general characters (typical
    // inhabitants and hirelings) roll 3d6
    // but read any 1 as a 3 and any 6 as
    // a 4
    if (die == 1) return 3;
    if (die == 6) return 4;
    return die;
}

inline int npcSpecialCharacterDieBonus(int die) {
    // special characters (including
    // henchmen), in the abilities germane
    // to the profession: +1 to each die of
    // the 3 rolled which scores under 6
    if (die < 6) return 1;
    return 0;
}

inline int npcMinGeneralTendencies() {
    // no fewer than three General
    // Tendencies are determined, more if
    // the DM desires
    return 3;
}

}  // namespace rules
