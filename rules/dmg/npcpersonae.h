// ====================================================================
// Adnd1 - rules/dmg/npcpersonae.h
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
// (rules/engine/character.h); ABILITY_COUNT is
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


enum NpcWealth {
    NPCW_NONE = 0,
    NPCW_SCANT,
    NPCW_AVERAGE,
    NPCW_ABOVE_AVERAGE,
    NPCW_EXCEPTIONAL,
    NPCW_SUPERABUNDANT,
    NPCW_COUNT
};


enum NpcAgeBand {
    NPCAGE_YOUNG = 0,
    NPCAGE_YOUTHFUL,
    NPCAGE_MATURE,
    NPCAGE_MIDDLE_AGED,
    NPCAGE_OLD,
    NPCAGE_ANCIENT,
    NPCAGE_BAND_COUNT
};


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


enum NpcSanity {
    NPCS_VERY_STABLE = 0,
    NPCS_NORMAL,
    NPCS_NEUROTIC,
    NPCS_UNSTABLE,
    NPCS_INSANE,
    NPCS_MANIACAL,
    NPCS_SANITY_COUNT
};

// R-refactor: namespace rules -> class Npcpersonae (instance methods)
class Npcpersonae {
public:


// -----------------------------------------------------------------------
// The d10 face clamp: the roll 1..10,
// where 10 is the 0 face. Every facts
// table helper reads through this.
// -----------------------------------------------------------------------
    int npcD10Face(int d);
    int npcClassCount();
    int npcClassAdjAbility(int cls, int slot);
    int npcClassAdjAmount(int cls, int slot);
    int npcClassMinAbility(int cls, int slot);
    int npcClassMinValue(int cls, int slot);
    int npcAdjustedAbility(int score, int adj);
    int npcOccupationCount();
    int npcOccupationAdjAbility(int occ, int slot);
    int npcOccupationAdjMin(int occ, int slot);
    int npcOccupationAdjMax(int occ, int slot);
    int npcMercenaryMinHitPoints();
    int npcOccupationMinAbility(int occ, int slot);
    int npcOccupationMinValue(int occ, int slot);
    int npcDemiRaceCount();
    int npcRaceAdjAbility(int race, int slot);
    int npcRaceAdjAmount(int race, int slot);
    int npcFactAlign(int d10);
    int npcFactWealth(int d10);
    int npcFactAgeBand(int d10);
    int npcFactGeneralLook(int d10);
    int npcFactSanity(int d10);
    bool npcSanityIsMarked(int level);
    int npcSanityResolved(int firstRoll, int secondRoll);


// -----------------------------------------------------------------------
// The p.11 die rules and the tendencies
// floor.
// -----------------------------------------------------------------------
    int npcGeneralCharacterDie(int die);
    int npcSpecialCharacterDieBonus(int die);
    int npcMinGeneralTendencies();
};
