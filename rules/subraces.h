// ===========================================================================
// Adnd1 - rules/subraces.h
// The UA subrace layer (R323) - the seam that
// opens the UA races section. Header-only
// pins, the humrpref.h / comeliness.h
// pattern: pure data plus accessors, no
// engine callers yet (the race-selection
// site and the R117 reaction table remain
// caller-free; the seam lands first, the
// wiring rounds follow).
//
// UNEARTHED ARCANA pp. 7-12: the 15
// racial types of Character Race Table I
// (17 in the preferences matrix, where
// the halfling strains split and half-orc
// and human stand as their own columns),
// the class-limitation matrix with its
// alignment-requirements column, the
// Racial Preferences Table (the P/G/T/
// N/A/H letters), and the sub-race
// mechanics: duergar, the six elf strains,
// svirfneblin, the halfling strains, the
// half-elf ancestries. Race Table II (the
// level-limit sub-tables with the
// footnoted ability gates and the
// single-class +2 rule) is NOT here - its
// own round now that the seam exists.
//
// The outcast reads: player drow LOSE the
// NPC 50% magic resistance and the innate
// combat gear; player svirfneblin LOSE the
// NPC magic resistance and the natural-AC
// progression. The print is explicit that
// these are NPC properties, abandoned with
// the homeland - pinned as such here.
// ===========================================================================

#pragma once

#include "races.h"

#include <cstdint>

namespace rules {

// ---------------------------------------------------------------------------
// The sub-race enum: the 17 racial types
// of the preferences matrix (UA p.12)
// ---------------------------------------------------------------------------

enum CharSubRace : int {
    SUB_NONE = 0,   // no sub-race recorded
                    // (the PHB-only game state)
    SUB_DWARF_GRAY,      // duergar
    SUB_DWARF_HILL,
    SUB_DWARF_MOUNTAIN,
    SUB_ELF_DARK,        // drow
    SUB_ELF_GRAY,
    SUB_ELF_HIGH,
    SUB_ELF_VALLEY,
    SUB_ELF_WILD,        // grugach
    SUB_ELF_WOOD,        // sylvan
    SUB_GNOME_DEEP,      // svirfneblin
    SUB_GNOME_SURFACE,
    SUB_HALFELF,         // ancestry is a
                         // separate read
    SUB_HALFLING_HAIRFOOT,
    SUB_HALFLING_STOUT,
    SUB_HALFLING_TALLFELLOW,
    SUB_HALF_ORC,
    SUB_HUMAN,
    SUBRACE_COUNT
};

// The parent CharRace of each sub-race
// (SUB_NONE maps to RACE_HUMAN as the
// inert default; the caller checks for it).
inline CharRace subraceParentRace(CharSubRace s) {
    switch (s) {
        case SUB_DWARF_GRAY:
        case SUB_DWARF_HILL:
        case SUB_DWARF_MOUNTAIN:
            return RACE_DWARF;
        case SUB_ELF_DARK:
        case SUB_ELF_GRAY:
        case SUB_ELF_HIGH:
        case SUB_ELF_VALLEY:
        case SUB_ELF_WILD:
        case SUB_ELF_WOOD:
            return RACE_ELF;
        case SUB_GNOME_DEEP:
        case SUB_GNOME_SURFACE:
            return RACE_GNOME;
        case SUB_HALFELF:
            return RACE_HALF_ELF;
        case SUB_HALFLING_HAIRFOOT:
        case SUB_HALFLING_STOUT:
        case SUB_HALFLING_TALLFELLOW:
            return RACE_HALFLING;
        case SUB_HALF_ORC:
            return RACE_HALF_ORC;
        case SUB_HUMAN:
        case SUB_NONE:
        default:
            return RACE_HUMAN;
    }
}

// The sub-race display name, as the UA
// prints it (the parenthetical is the
// common name, not a second entry).
inline const char* subraceName(CharSubRace s) {
    switch (s) {
        case SUB_DWARF_GRAY:
            return "Gray Dwarf (Duergar)";
        case SUB_DWARF_HILL: return "Hill Dwarf";
        case SUB_DWARF_MOUNTAIN:
            return "Mountain Dwarf";
        case SUB_ELF_DARK:
            return "Dark Elf (Drow)";
        case SUB_ELF_GRAY: return "Gray Elf";
        case SUB_ELF_HIGH: return "High Elf";
        case SUB_ELF_VALLEY:
            return "Valley Elf";
        case SUB_ELF_WILD:
            return "Wild Elf (Grugach)";
        case SUB_ELF_WOOD:
            return "Wood Elf (Sylvan)";
        case SUB_GNOME_DEEP:
            return "Deep Gnome (Svirfneblin)";
        case SUB_GNOME_SURFACE:
            return "Surface Gnome";
        case SUB_HALFELF: return "Half-Elf";
        case SUB_HALFLING_HAIRFOOT:
            return "Hairfoot Halfling";
        case SUB_HALFLING_STOUT:
            return "Stout Halfling";
        case SUB_HALFLING_TALLFELLOW:
            return "Tallfellow Halfling";
        case SUB_HALF_ORC: return "Half-Orc";
        case SUB_HUMAN: return "Human";
        case SUB_NONE:
        default: return "None";
    }
}

// ---------------------------------------------------------------------------
// The 14 UA classes of Race Table I
// ---------------------------------------------------------------------------

enum UaClass : int {
    UACLASS_CAVALIER = 0,
    UACLASS_PALADIN,
    UACLASS_CLERIC,
    UACLASS_DRUID,
    UACLASS_FIGHTER,
    UACLASS_BARBARIAN,
    UACLASS_RANGER,
    UACLASS_MAGIC_USER,
    UACLASS_ILLUSIONIST,
    UACLASS_THIEF,
    UACLASS_ACROBAT,
    UACLASS_ASSASSIN,
    UACLASS_MONK,
    UACLASS_BARD,
    UACLASS_COUNT
};

// The alignment-requirements column of
// Race Table I (applies to every race).
enum UaAlignReq : int {
    UA_ALIGN_ANY = 0,
    UA_ALIGN_ANY_GOOD,      // cavalier
                            // (at start),
                            // ranger
    UA_ALIGN_LG_ONLY,        // paladin
    UA_ALIGN_TRUE_NEUTRAL,  // druid
    UA_ALIGN_NON_LAWFUL,    // barbarian
    UA_ALIGN_NON_GOOD,      // thief,
                            // acrobat
    UA_ALIGN_ANY_EVIL,      // assassin
    UA_ALIGN_ANY_LAWFUL,    // monk
    UA_ALIGN_ANY_NEUTRAL    // bard
};

inline UaAlignReq uaClassAlignmentReq(UaClass c) {
    switch (c) {
        case UACLASS_CAVALIER:
        case UACLASS_RANGER:
            return UA_ALIGN_ANY_GOOD;
        case UACLASS_PALADIN:
            return UA_ALIGN_LG_ONLY;
        case UACLASS_DRUID:
            return UA_ALIGN_TRUE_NEUTRAL;
        case UACLASS_BARBARIAN:
            return UA_ALIGN_NON_LAWFUL;
        case UACLASS_THIEF:
        case UACLASS_ACROBAT:
            return UA_ALIGN_NON_GOOD;
        case UACLASS_ASSASSIN:
            return UA_ALIGN_ANY_EVIL;
        case UACLASS_MONK:
            return UA_ALIGN_ANY_LAWFUL;
        case UACLASS_BARD:
            return UA_ALIGN_ANY_NEUTRAL;
        case UACLASS_CLERIC:
        case UACLASS_FIGHTER:
        case UACLASS_MAGIC_USER:
        case UACLASS_ILLUSIONIST:
        default:
            return UA_ALIGN_ANY;
    }
}

// Race Table I (UA p.7): may this
// sub-race enter this UA class? The
// halfling strains share one column in
// the print (marked All); the dwarf
// strains and the gnome strains are
// listed separately but print the same
// allowances, pinned per type anyway.
inline bool subraceClassAllowed(CharSubRace s,
                                UaClass c) {
    switch (s) {
        case SUB_DWARF_GRAY:
        case SUB_DWARF_HILL:
        case SUB_DWARF_MOUNTAIN:
            return c == UACLASS_CLERIC
                || c == UACLASS_FIGHTER
                || c == UACLASS_THIEF
                || c == UACLASS_ACROBAT
                || c == UACLASS_ASSASSIN;
        case SUB_ELF_DARK:
            return c == UACLASS_CAVALIER
                || c == UACLASS_CLERIC
                || c == UACLASS_FIGHTER
                || c == UACLASS_RANGER
                || c == UACLASS_MAGIC_USER
                || c == UACLASS_THIEF
                || c == UACLASS_ACROBAT
                || c == UACLASS_ASSASSIN;
        case SUB_ELF_GRAY:
        case SUB_ELF_HIGH:
        case SUB_ELF_WOOD:
            return c == UACLASS_CAVALIER
                || c == UACLASS_CLERIC
                || c == UACLASS_DRUID
                || c == UACLASS_FIGHTER
                || c == UACLASS_RANGER
                || c == UACLASS_MAGIC_USER
                || c == UACLASS_THIEF
                || c == UACLASS_ACROBAT
                || c == UACLASS_ASSASSIN;
        case SUB_ELF_VALLEY:
            return c == UACLASS_CLERIC
                || c == UACLASS_DRUID
                || c == UACLASS_FIGHTER
                || c == UACLASS_RANGER
                || c == UACLASS_THIEF
                || c == UACLASS_ACROBAT
                || c == UACLASS_ASSASSIN;
        case SUB_ELF_WILD:
            // grugach: druids, fighters,
            // thieves (with assassin and
            // acrobat) only; fighter/thief
            // is the only multi-class
            return c == UACLASS_DRUID
                || c == UACLASS_FIGHTER
                || c == UACLASS_THIEF
                || c == UACLASS_ACROBAT
                || c == UACLASS_ASSASSIN;
        case SUB_GNOME_DEEP:
        case SUB_GNOME_SURFACE:
            return c == UACLASS_CLERIC
                || c == UACLASS_FIGHTER
                || c == UACLASS_ILLUSIONIST
                || c == UACLASS_THIEF
                || c == UACLASS_ACROBAT
                || c == UACLASS_ASSASSIN;
        case SUB_HALFELF:
            return c != UACLASS_BARBARIAN
                && c != UACLASS_ILLUSIONIST
                && c != UACLASS_MONK;
        case SUB_HALFLING_HAIRFOOT:
        case SUB_HALFLING_STOUT:
        case SUB_HALFLING_TALLFELLOW:
            return c == UACLASS_CLERIC
                || c == UACLASS_DRUID
                || c == UACLASS_FIGHTER
                || c == UACLASS_THIEF
                || c == UACLASS_ACROBAT;
        case SUB_HALF_ORC:
            return c == UACLASS_CLERIC
                || c == UACLASS_FIGHTER
                || c == UACLASS_THIEF
                || c == UACLASS_ACROBAT
                || c == UACLASS_ASSASSIN;
        case SUB_HUMAN:
            return true;
        case SUB_NONE:
        default:
            return false;
    }
}

// ---------------------------------------------------------------------------
// The Racial Preferences Table (UA p.12):
// how the viewing race reads the viewed
// race. The six letters, the print key:
//   P preferred   G goodwill
//   T tolerated   N neutral
//   A antipathy   H hatred
// The half-elf footnote rides the matrix:
// elves react to a half-elf as the worse
// of half-elf or the full-blooded
// ancestor type - a caller concern,
// named here.
// ---------------------------------------------------------------------------

enum RacePref : int {
    PREF_P = 0, PREF_G, PREF_T,
    PREF_N, PREF_A, PREF_H
};

inline const char* racePrefLetter(RacePref p) {
    static const char* L[6] = {
        "P", "G", "T", "N", "A", "H" };
    return (p >= PREF_P && p <= PREF_H)
        ? L[p] : "?";
}

// The matrix rows, in SUB_ order from
// SUB_DWARF_GRAY (1) through SUB_HUMAN
// (17), each 17 letters against the same
// order. Row = viewer, column = viewed.
inline RacePref subracePrefers(
        CharSubRace viewer, CharSubRace viewed) {
    static const uint8_t M[17][17] = {
        // DG DH DM ED EG EH EV EWi EWd GD
        // GS hE HH HS HT hO H
        { 0, 4, 4, 1, 5, 5, 5, 5, 5, 4, 4, 3, 3, 2, 3, 3, 3 },
        { 4, 0, 1, 5, 4, 4, 4, 4, 4, 3, 1, 3, 2, 1, 1, 5, 3 },
        { 4, 1, 0, 5, 4, 4, 4, 4, 4, 2, 2, 3, 2, 1, 2, 5, 3 },
        { 1, 4, 4, 0, 5, 5, 4, 5, 5, 5, 4, 4, 4, 4, 4, 2, 3 },
        { 4, 4, 4, 5, 0, 1, 4, 2, 1, 3, 2, 1, 2, 2, 1, 4, 3 },
        { 4, 4, 4, 5, 1, 0, 4, 3, 1, 2, 2, 1, 2, 2, 1, 4, 3 },
        { 4, 4, 4, 4, 3, 3, 0, 3, 3, 1, 1, 2, 3, 3, 2, 4, 4 },
        { 4, 4, 4, 5, 3, 3, 4, 0, 3, 4, 4, 4, 4, 4, 3, 4, 4 },
        { 4, 4, 4, 5, 1, 1, 4, 3, 0, 3, 3, 1, 2, 2, 1, 4, 3 },
        { 4, 3, 2, 5, 3, 3, 2, 3, 3, 0, 1, 3, 2, 2, 2, 4, 3 },
        { 4, 1, 1, 4, 2, 2, 1, 3, 3, 1, 0, 2, 1, 1, 1, 5, 3 },
        { 3, 3, 3, 0, 0, 0, 0, 4, 0, 3, 2, 0, 3, 3, 2, 4, 2 },
        { 3, 2, 2, 4, 2, 2, 3, 3, 2, 3, 2, 3, 0, 0, 0, 3, 2 },
        { 2, 1, 1, 4, 2, 2, 3, 3, 2, 2, 2, 3, 0, 0, 0, 3, 3 },
        { 3, 2, 2, 3, 1, 1, 2, 2, 1, 3, 2, 1, 0, 0, 0, 3, 3 },
        { 3, 5, 5, 3, 4, 4, 4, 4, 4, 4, 5, 4, 3, 3, 4, 0, 2 },
        { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 3, 3, 3, 3, 0 },
    };
    if (viewer < SUB_DWARF_GRAY
        || viewer > SUB_HUMAN
        || viewed < SUB_DWARF_GRAY
        || viewed > SUB_HUMAN)
        return PREF_N;
    return (RacePref)M[viewer - 1][viewed - 1];
}

// ---------------------------------------------------------------------------
// The sub-race mechanics (UA pp. 10-12),
// as one traits record per sub-race. Zero
// means the racial standard of the parent
// (races.h); only the deltas the print
// names are pinned here.
// ---------------------------------------------------------------------------

struct SubRaceTraits {
    // die-roll adjustments to the initially
    // generated scores (the UA sub-race
    // bonuses, in ABILITY_ order):
    // gray elf +1 INT (max 19); wood elf
    // +1 STR (max 18) and -1 INT; wild
    // elf +2 STR (max 18). All others 0.
    int adj[ABILITY_COUNT];
    // per-ability maxima, 0 = the racial
    // standard (the parent-race Table III
    // maximum); 19 only where the print
    // lifts it (gray elf INT)
    int max[ABILITY_COUNT];
    // infravision in feet; 0 = the racial
    // standard (120 for the three deep
    // strains: duergar, drow, svirfneblin)
    int infravisionFeet;
    // save bonuses pinned by the print:
    // drow +2 versus magical effects;
    // svirfneblin +2 versus poison and
    // +3 on all other saves
    int saveVsMagicBonus;
    int saveVsPoisonBonus;
    int saveOtherBonus;
    // the immunity flags
    int illusionImmune;        // duergar,
                               // svirfneblin
    int paralysisImmune;       // duergar
    int magicPoisonImmune;     // duergar:
                              // immune to
                              // non-natural
                              // (magical or
                              // alchemical)
                              // poisons
    // surprise arithmetic: N-in-D to
    // surprise others (alone or in the
    // company of the same sub-race);
    // N-in-D to be surprised. 0 = the
    // standard (duergar 3-in-6 and
    // 1-in-10; drow 1-in-8; svirfneblin
    // 9-in-10 and 1-in-12)
    int surpriseOn, surpriseDie;
    int surprisedOn, surprisedDie;
    // the drow sex-split movement rates
    // (female 15, male 12); 0 = standard
    int moveFemale, moveMale;
    // the outcast flags
    int twoWeaponFree;   // drow: fight
                         // two-weapon
                         // without
                         // penalty, no
                         // shield, spiked
                         // buckler allowed
    int losesSwordBowBonus;  // drow: no
                            // surface-elf
                            // sword/bow
                            // combat bonus
    int maleOnlyPC;      // svirfneblin
    int noPsionics;      // svirfneblin
                         // player chars
};

inline const SubRaceTraits& subraceTraits(
        CharSubRace s) {
    static const SubRaceTraits T[SUBRACE_COUNT] = {
        // SUB_NONE
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_DWARF_GRAY (duergar)
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          120, 0, 0, 0, 1, 1, 1,
          3, 6, 1, 10, 0, 0, 0, 0, 0, 0 },
        // SUB_DWARF_HILL
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_DWARF_MOUNTAIN
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_ELF_DARK (drow, outcast)
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          120, 2, 0, 0, 0, 0, 0,
          0, 0, 1, 8, 15, 12, 1, 1, 0, 0 },
        // SUB_ELF_GRAY
        { {0, 1, 0, 0, 0, 0},
          {0, 19, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_ELF_HIGH
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_ELF_VALLEY (gray + gnomish)
        { {0, 1, 0, 0, 0, 0},
          {0, 19, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_ELF_WILD (grugach)
        { {2, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_ELF_WOOD (sylvan)
        { {1, -1, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_GNOME_DEEP (svirfneblin)
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          120, 0, 2, 3, 1, 0, 0,
          9, 10, 1, 12, 0, 0, 0, 0, 1, 1 },
        // SUB_GNOME_SURFACE
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_HALFELF (ancestry separate)
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_HALFLING_HAIRFOOT
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_HALFLING_STOUT (mixed blood reads as stout)
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_HALFLING_TALLFELLOW
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_HALF_ORC
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        // SUB_HUMAN
        { {0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0},
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    return T[s < SUBRACE_COUNT ? s : SUB_NONE];
}

// The duergar daylight ladder (UA p.10):
// exposed to daylight or continual light
// the surprise bonus is negated, DEX is
// effectively -2, attacks -2 to hit and
// the opponents save at +2 versus gray
// dwarf attacks; attacking from darkness
// into lit foes: -1 to hit, opponents
// save at +1. The dim sources (torches,
// lanterns, light spells, faerie fire,
// magical weapons) do NOT affect duergar.
// Drow are affected in the same manner.
inline int duergarDayDexPenalty()  { return 2; }
inline int duergarDayToHitPenalty()
    { return 2; }
inline int duergarDayOpponentSaveBonus()
    { return 2; }
inline int duergarShadowToHitPenalty()
    { return 1; }
inline int duergarShadowSaveBonus()
    { return 1; }

// The duergar multi-class list (the
// print): fighter/cleric, fighter/thief,
// cleric/thief, cleric/assassin.
inline int duergarMultiClassCount() { return 4; }

// The grugach reads (UA p.10): the
// fighter/thief-only multi-class gate and
// the 90% pit, snare and natural-trap
// success.
inline int wildElfMultiClassCount() { return 1; }
inline int wildElfTrapSuccessPct() { return 90; }

// The grugach also deal with woodland
// creatures as if animal friendship were
// in operation (a caller concern, named
// here - the flag lives in the callers).
inline int wildElfAnimalFriendshipDeal()
    { return 1; }

// The svirfneblin reads (UA p.11): the
// 60% camouflage against natural rock
// deep underground (until move, attack
// or another negating action), the
// non-detection the character radiates
// (self only, not an area), and the
// bright-light reads (all vision
// reduced to 3, -1 to hit while
// fighting in such light).
inline int svirfCamouflagePct()   { return 60; }
inline int svirfBrightLightFeet() { return 30; }
inline int svirfBrightToHitPenalty()
    { return 1; }

// The svirfneblin earth elemental table
// (d20, once per day at 6th level for
// non-illusionists, conjure elemental
// fashion): six outcome rows.
struct EarthElementalRow {
    int lo, hi;          // the d20 span
    const char* result;  // the summon
                         // outcome
};
inline const EarthElementalRow*
svirfEarthElementalTable(int& n) {
    static const EarthElementalRow R[6] = {
        { 1, 1,  "24 HD earth elemental" },
        { 2, 6,  "16 HD earth elemental" },
        { 7, 10, "12 HD earth elemental" },
        { 11, 15, "8 HD earth elemental" },
        { 16, 18, "xorn" },
        { 19, 20,
          "summoning fails, not retryable"
          " that day" }
    };
    n = 6;
    return R;
}

// The innate spell lists (once per day,
// pinned by name; the spell-registry
// linkage is the wiring round):
//   drow base: dancing lights, faerie
//   fire, darkness 5 ft radius
//   drow 4th level (any class): detect
//   magic, know alignment, levitate
//   drow female 4th level+: clairvoyance,
//   detect lie (or reverse), suggestion,
//   dispel magic
//   svirfneblin: blindness, blur, change
//   self (as an illusionist of the
//   highest class level)
inline int drowInnateBase(const char**& L) {
    static const char* B[3] = {
        "dancing lights", "faerie fire",
        "darkness 5 ft radius" };
    L = B; return 3;
}
inline int drowInnateAt4(const char**& L) {
    static const char* B[3] = {
        "detect magic", "know alignment",
        "levitate" };
    L = B; return 3;
}
inline int drowInnateFemale4(const char**& L) {
    static const char* B[4] = {
        "clairvoyance", "detect lie",
        "suggestion", "dispel magic" };
    L = B; return 4;
}
inline int svirfInnate(const char**& L) {
    static const char* B[3] = {
        "blindness", "blur", "change self" };
    L = B; return 3;
}

// The drow silent tongue: the hand-signal
// language of the subterranean dwellers,
// 30 ft range, full mastery drow only
// (others may learn the basic signs).
inline int drowSilentTongueRangeFeet()
    { return 30; }

// The svirfneblin melee bonus: +1 to hit
// AND damage versus drow and kuo-toa
// (the enemies of the deep race); the
// giant-kind attack penalties read as
// the surface gnomes (the races.h foe
// lists).
inline int svirfDeepFoeToHitBonus()  { return 1; }
inline int svirfDeepFoeDamageBonus() { return 1; }

// The half-elf ancestries (UA p.11):
// high-elf descent is the PHB half-elf;
// gray, wood and valley descent carry
// similar abilities; grugach descent is
// unknown (the print: no instances
// known); drow descent keeps the
// light-sensitivity penalty, gains NO
// drow advantages, and is outcast to the
// dark elves. Pinned as the recorded
// ancestry read; the caller layers it.
enum HalfElfAncestry : int {
    HE_ANCESTRY_HIGH = 0,
    HE_ANCESTRY_GRAY,
    HE_ANCESTRY_WOOD,
    HE_ANCESTRY_VALLEY,
    HE_ANCESTRY_GRUGACH,  // no instances
                         // known - the
                         // print
    HE_ANCESTRY_DROW,     // the light
                         // penalty,
                         // no drow
                         // advantages,
                         // outcast
    HE_ANCESTRY_COUNT
};
inline int halfElfAncestryExists(
        HalfElfAncestry a) {
    // grugach descent: no instances known
    return a == HE_ANCESTRY_GRUGACH
        ? 0 : 1;
}

// The comeliness sub-race grain (the
// R322 recorded read, now homed): the
// viewed-race adjustments for the elf
// strains - the engine elf carries the
// +1 sylvan read; the gray and high
// strains read +2 against other-race
// viewers. Point-for-point pairs (gray
// and high; half-elf and sylvan) treat
// as same race - the caller concern.
inline int uaComelinessViewedSubraceAdj(
        CharSubRace viewed) {
    switch (viewed) {
        case SUB_ELF_GRAY:
        case SUB_ELF_HIGH:
            return 2;
        case SUB_ELF_WOOD:
            return 1;   // the sylvan read
        default:
            return 0;   // the parent-race
                        // adjustment rules
    }
}

} // namespace rules