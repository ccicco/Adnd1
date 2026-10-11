

# ============================================================================
# Adnd1 - tools/r323b_splice.py
# The R323 splice: the UA subrace layer.
#
# Patches (all idempotent; each patch
# is guarded and re-runnable):
#   (a) doc/vibe/adnd1_knowledge_seed_v2.md -
#       the R322 round-state entry (the
#       paste-safe lesson, the md5/newline
#       lesson, the OUT/DEFERRED axis
#       lesson).
#   (b) rules/subraces.h - NEW FILE: the
#       subrace seam - the CharSubRace
#       enum (the 17 racial types), the
#       UaClass enum and Race Table I
#       with the alignment-requirements
#       column, the Racial Preferences
#       matrix (17x17, the P/G/T/N/A/H
#       letters, verified cell by cell
#       against the print), the
#       SubRaceTraits records (duergar,
#       the elf strains, svirfneblin,
#       the half-elf ancestries, the
#       halfling strains), the duergar
#       daylight ladder, the grugach
#       reads, the svirfneblin reads
#       with the earth elemental table,
#       the drow innate spell lists, the
#       comeliness subrace grain (the
#       R322 recorded read, homed).
#   (c) tools/ua_gap_report.md - four
#       boxes close (Race Table I, the
#       sub-race mechanics, the
#       preferences matrix, the subrace
#       layer seam) and Race Table II is
#       marked UNBLOCKED; the comeliness
#       grain note updated.
#   (d) regtest.cpp - the include and
#       the R323 subrace layer seam
#       audit; the battery census moves
#       249 -> 250.
# ============================================================================

import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
Q = chr(39)
DQ = chr(34)
BS = chr(92)
applied, already = [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit):
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

def cleanNB(s, limit):
    # the content that carries a built
    # backslash byte (the printf newline)
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

SR_FILE = NL.join([
    '// ===========================================================================',
    '// Adnd1 - rules/subraces.h',
    '// The UA subrace layer (R323) - the seam that',
    '// opens the UA races section. Header-only',
    '// pins, the humrpref.h / comeliness.h',
    '// pattern: pure data plus accessors, no',
    '// engine callers yet (the race-selection',
    '// site and the R117 reaction table remain',
    '// caller-free; the seam lands first, the',
    '// wiring rounds follow).',
    '//',
    '// UNEARTHED ARCANA pp. 7-12: the 15',
    '// racial types of Character Race Table I',
    '// (17 in the preferences matrix, where',
    '// the halfling strains split and half-orc',
    '// and human stand as their own columns),',
    '// the class-limitation matrix with its',
    '// alignment-requirements column, the',
    '// Racial Preferences Table (the P/G/T/',
    '// N/A/H letters), and the sub-race',
    '// mechanics: duergar, the six elf strains,',
    '// svirfneblin, the halfling strains, the',
    '// half-elf ancestries. Race Table II (the',
    '// level-limit sub-tables with the',
    '// footnoted ability gates and the',
    '// single-class +2 rule) is NOT here - its',
    '// own round now that the seam exists.',
    '//',
    '// The outcast reads: player drow LOSE the',
    '// NPC 50% magic resistance and the innate',
    '// combat gear; player svirfneblin LOSE the',
    '// NPC magic resistance and the natural-AC',
    '// progression. The print is explicit that',
    '// these are NPC properties, abandoned with',
    '// the homeland - pinned as such here.',
    '// ===========================================================================',
    '',
    '#pragma once',
    '',
    '#include "races.h"',
    '',
    '#include <cstdint>',
    '',
    'namespace rules {',
    '',
    '// ---------------------------------------------------------------------------',
    '// The sub-race enum: the 17 racial types',
    '// of the preferences matrix (UA p.12)',
    '// ---------------------------------------------------------------------------',
    '',
    'enum CharSubRace : int {',
    '    SUB_NONE = 0,   // no sub-race recorded',
    '                    // (the PHB-only game state)',
    '    SUB_DWARF_GRAY,      // duergar',
    '    SUB_DWARF_HILL,',
    '    SUB_DWARF_MOUNTAIN,',
    '    SUB_ELF_DARK,        // drow',
    '    SUB_ELF_GRAY,',
    '    SUB_ELF_HIGH,',
    '    SUB_ELF_VALLEY,',
    '    SUB_ELF_WILD,        // grugach',
    '    SUB_ELF_WOOD,        // sylvan',
    '    SUB_GNOME_DEEP,      // svirfneblin',
    '    SUB_GNOME_SURFACE,',
    '    SUB_HALFELF,         // ancestry is a',
    '                         // separate read',
    '    SUB_HALFLING_HAIRFOOT,',
    '    SUB_HALFLING_STOUT,',
    '    SUB_HALFLING_TALLFELLOW,',
    '    SUB_HALF_ORC,',
    '    SUB_HUMAN,',
    '    SUBRACE_COUNT',
    '};',
    '',
    '// The parent CharRace of each sub-race',
    '// (SUB_NONE maps to RACE_HUMAN as the',
    '// inert default; the caller checks for it).',
    'inline CharRace subraceParentRace(CharSubRace s) {',
    '    switch (s) {',
    '        case SUB_DWARF_GRAY:',
    '        case SUB_DWARF_HILL:',
    '        case SUB_DWARF_MOUNTAIN:',
    '            return RACE_DWARF;',
    '        case SUB_ELF_DARK:',
    '        case SUB_ELF_GRAY:',
    '        case SUB_ELF_HIGH:',
    '        case SUB_ELF_VALLEY:',
    '        case SUB_ELF_WILD:',
    '        case SUB_ELF_WOOD:',
    '            return RACE_ELF;',
    '        case SUB_GNOME_DEEP:',
    '        case SUB_GNOME_SURFACE:',
    '            return RACE_GNOME;',
    '        case SUB_HALFELF:',
    '            return RACE_HALF_ELF;',
    '        case SUB_HALFLING_HAIRFOOT:',
    '        case SUB_HALFLING_STOUT:',
    '        case SUB_HALFLING_TALLFELLOW:',
    '            return RACE_HALFLING;',
    '        case SUB_HALF_ORC:',
    '            return RACE_HALF_ORC;',
    '        case SUB_HUMAN:',
    '        case SUB_NONE:',
    '        default:',
    '            return RACE_HUMAN;',
    '    }',
    '}',
    '',
    '// The sub-race display name, as the UA',
    '// prints it (the parenthetical is the',
    '// common name, not a second entry).',
    'inline const char* subraceName(CharSubRace s) {',
    '    switch (s) {',
    '        case SUB_DWARF_GRAY:',
    '            return "Gray Dwarf (Duergar)";',
    '        case SUB_DWARF_HILL: return "Hill Dwarf";',
    '        case SUB_DWARF_MOUNTAIN:',
    '            return "Mountain Dwarf";',
    '        case SUB_ELF_DARK:',
    '            return "Dark Elf (Drow)";',
    '        case SUB_ELF_GRAY: return "Gray Elf";',
    '        case SUB_ELF_HIGH: return "High Elf";',
    '        case SUB_ELF_VALLEY:',
    '            return "Valley Elf";',
    '        case SUB_ELF_WILD:',
    '            return "Wild Elf (Grugach)";',
    '        case SUB_ELF_WOOD:',
    '            return "Wood Elf (Sylvan)";',
    '        case SUB_GNOME_DEEP:',
    '            return "Deep Gnome (Svirfneblin)";',
    '        case SUB_GNOME_SURFACE:',
    '            return "Surface Gnome";',
    '        case SUB_HALFELF: return "Half-Elf";',
    '        case SUB_HALFLING_HAIRFOOT:',
    '            return "Hairfoot Halfling";',
    '        case SUB_HALFLING_STOUT:',
    '            return "Stout Halfling";',
    '        case SUB_HALFLING_TALLFELLOW:',
    '            return "Tallfellow Halfling";',
    '        case SUB_HALF_ORC: return "Half-Orc";',
    '        case SUB_HUMAN: return "Human";',
    '        case SUB_NONE:',
    '        default: return "None";',
    '    }',
    '}',
    '',
    '// ---------------------------------------------------------------------------',
    '// The 14 UA classes of Race Table I',
    '// ---------------------------------------------------------------------------',
    '',
    'enum UaClass : int {',
    '    UACLASS_CAVALIER = 0,',
    '    UACLASS_PALADIN,',
    '    UACLASS_CLERIC,',
    '    UACLASS_DRUID,',
    '    UACLASS_FIGHTER,',
    '    UACLASS_BARBARIAN,',
    '    UACLASS_RANGER,',
    '    UACLASS_MAGIC_USER,',
    '    UACLASS_ILLUSIONIST,',
    '    UACLASS_THIEF,',
    '    UACLASS_ACROBAT,',
    '    UACLASS_ASSASSIN,',
    '    UACLASS_MONK,',
    '    UACLASS_BARD,',
    '    UACLASS_COUNT',
    '};',
    '',
    '// The alignment-requirements column of',
    '// Race Table I (applies to every race).',
    'enum UaAlignReq : int {',
    '    UA_ALIGN_ANY = 0,',
    '    UA_ALIGN_ANY_GOOD,      // cavalier',
    '                            // (at start),',
    '                            // ranger',
    '    UA_ALIGN_LG_ONLY,        // paladin',
    '    UA_ALIGN_TRUE_NEUTRAL,  // druid',
    '    UA_ALIGN_NON_LAWFUL,    // barbarian',
    '    UA_ALIGN_NON_GOOD,      // thief,',
    '                            // acrobat',
    '    UA_ALIGN_ANY_EVIL,      // assassin',
    '    UA_ALIGN_ANY_LAWFUL,    // monk',
    '    UA_ALIGN_ANY_NEUTRAL    // bard',
    '};',
    '',
    'inline UaAlignReq uaClassAlignmentReq(UaClass c) {',
    '    switch (c) {',
    '        case UACLASS_CAVALIER:',
    '        case UACLASS_RANGER:',
    '            return UA_ALIGN_ANY_GOOD;',
    '        case UACLASS_PALADIN:',
    '            return UA_ALIGN_LG_ONLY;',
    '        case UACLASS_DRUID:',
    '            return UA_ALIGN_TRUE_NEUTRAL;',
    '        case UACLASS_BARBARIAN:',
    '            return UA_ALIGN_NON_LAWFUL;',
    '        case UACLASS_THIEF:',
    '        case UACLASS_ACROBAT:',
    '            return UA_ALIGN_NON_GOOD;',
    '        case UACLASS_ASSASSIN:',
    '            return UA_ALIGN_ANY_EVIL;',
    '        case UACLASS_MONK:',
    '            return UA_ALIGN_ANY_LAWFUL;',
    '        case UACLASS_BARD:',
    '            return UA_ALIGN_ANY_NEUTRAL;',
    '        case UACLASS_CLERIC:',
    '        case UACLASS_FIGHTER:',
    '        case UACLASS_MAGIC_USER:',
    '        case UACLASS_ILLUSIONIST:',
    '        default:',
    '            return UA_ALIGN_ANY;',
    '    }',
    '}',
    '',
    '// Race Table I (UA p.7): may this',
    '// sub-race enter this UA class? The',
    '// halfling strains share one column in',
    '// the print (marked All); the dwarf',
    '// strains and the gnome strains are',
    '// listed separately but print the same',
    '// allowances, pinned per type anyway.',
    'inline bool subraceClassAllowed(CharSubRace s,',
    '                                UaClass c) {',
    '    switch (s) {',
    '        case SUB_DWARF_GRAY:',
    '        case SUB_DWARF_HILL:',
    '        case SUB_DWARF_MOUNTAIN:',
    '            return c == UACLASS_CLERIC',
    '                || c == UACLASS_FIGHTER',
    '                || c == UACLASS_THIEF',
    '                || c == UACLASS_ACROBAT',
    '                || c == UACLASS_ASSASSIN;',
    '        case SUB_ELF_DARK:',
    '            return c == UACLASS_CAVALIER',
    '                || c == UACLASS_CLERIC',
    '                || c == UACLASS_FIGHTER',
    '                || c == UACLASS_RANGER',
    '                || c == UACLASS_MAGIC_USER',
    '                || c == UACLASS_THIEF',
    '                || c == UACLASS_ACROBAT',
    '                || c == UACLASS_ASSASSIN;',
    '        case SUB_ELF_GRAY:',
    '        case SUB_ELF_HIGH:',
    '        case SUB_ELF_WOOD:',
    '            return c == UACLASS_CAVALIER',
    '                || c == UACLASS_CLERIC',
    '                || c == UACLASS_DRUID',
    '                || c == UACLASS_FIGHTER',
    '                || c == UACLASS_RANGER',
    '                || c == UACLASS_MAGIC_USER',
    '                || c == UACLASS_THIEF',
    '                || c == UACLASS_ACROBAT',
    '                || c == UACLASS_ASSASSIN;',
    '        case SUB_ELF_VALLEY:',
    '            return c == UACLASS_CLERIC',
    '                || c == UACLASS_DRUID',
    '                || c == UACLASS_FIGHTER',
    '                || c == UACLASS_RANGER',
    '                || c == UACLASS_THIEF',
    '                || c == UACLASS_ACROBAT',
    '                || c == UACLASS_ASSASSIN;',
    '        case SUB_ELF_WILD:',
    '            // grugach: druids, fighters,',
    '            // thieves (with assassin and',
    '            // acrobat) only; fighter/thief',
    '            // is the only multi-class',
    '            return c == UACLASS_DRUID',
    '                || c == UACLASS_FIGHTER',
    '                || c == UACLASS_THIEF',
    '                || c == UACLASS_ACROBAT',
    '                || c == UACLASS_ASSASSIN;',
    '        case SUB_GNOME_DEEP:',
    '        case SUB_GNOME_SURFACE:',
    '            return c == UACLASS_CLERIC',
    '                || c == UACLASS_FIGHTER',
    '                || c == UACLASS_ILLUSIONIST',
    '                || c == UACLASS_THIEF',
    '                || c == UACLASS_ACROBAT',
    '                || c == UACLASS_ASSASSIN;',
    '        case SUB_HALFELF:',
    '            return c != UACLASS_BARBARIAN',
    '                && c != UACLASS_ILLUSIONIST',
    '                && c != UACLASS_MONK;',
    '        case SUB_HALFLING_HAIRFOOT:',
    '        case SUB_HALFLING_STOUT:',
    '        case SUB_HALFLING_TALLFELLOW:',
    '            return c == UACLASS_CLERIC',
    '                || c == UACLASS_DRUID',
    '                || c == UACLASS_FIGHTER',
    '                || c == UACLASS_THIEF',
    '                || c == UACLASS_ACROBAT;',
    '        case SUB_HALF_ORC:',
    '            return c == UACLASS_CLERIC',
    '                || c == UACLASS_FIGHTER',
    '                || c == UACLASS_THIEF',
    '                || c == UACLASS_ACROBAT',
    '                || c == UACLASS_ASSASSIN;',
    '        case SUB_HUMAN:',
    '            return true;',
    '        case SUB_NONE:',
    '        default:',
    '            return false;',
    '    }',
    '}',
    '',
    '// ---------------------------------------------------------------------------',
    '// The Racial Preferences Table (UA p.12):',
    '// how the viewing race reads the viewed',
    '// race. The six letters, the print key:',
    '//   P preferred   G goodwill',
    '//   T tolerated   N neutral',
    '//   A antipathy   H hatred',
    '// The half-elf footnote rides the matrix:',
    '// elves react to a half-elf as the worse',
    '// of half-elf or the full-blooded',
    '// ancestor type - a caller concern,',
    '// named here.',
    '// ---------------------------------------------------------------------------',
    '',
    'enum RacePref : int {',
    '    PREF_P = 0, PREF_G, PREF_T,',
    '    PREF_N, PREF_A, PREF_H',
    '};',
    '',
    'inline const char* racePrefLetter(RacePref p) {',
    '    static const char* L[6] = {',
    '        "P", "G", "T", "N", "A", "H" };',
    '    return (p >= PREF_P && p <= PREF_H)',
    '        ? L[p] : "?";',
    '}',
    '',
    '// The matrix rows, in SUB_ order from',
    '// SUB_DWARF_GRAY (1) through SUB_HUMAN',
    '// (17), each 17 letters against the same',
    '// order. Row = viewer, column = viewed.',
    'inline RacePref subracePrefers(',
    '        CharSubRace viewer, CharSubRace viewed) {',
    '    static const uint8_t M[17][17] = {',
    '        // DG DH DM ED EG EH EV EWi EWd GD',
    '        // GS hE HH HS HT hO H',
    '        { 0, 4, 4, 1, 5, 5, 5, 5, 5, 4, 4, 3, 3, 2, 3, 3, 3 },',
    '        { 4, 0, 1, 5, 4, 4, 4, 4, 4, 3, 1, 3, 2, 1, 1, 5, 3 },',
    '        { 4, 1, 0, 5, 4, 4, 4, 4, 4, 2, 2, 3, 2, 1, 2, 5, 3 },',
    '        { 1, 4, 4, 0, 5, 5, 4, 5, 5, 5, 4, 4, 4, 4, 4, 2, 3 },',
    '        { 4, 4, 4, 5, 0, 1, 4, 2, 1, 3, 2, 1, 2, 2, 1, 4, 3 },',
    '        { 4, 4, 4, 5, 1, 0, 4, 3, 1, 2, 2, 1, 2, 2, 1, 4, 3 },',
    '        { 4, 4, 4, 4, 3, 3, 0, 3, 3, 1, 1, 2, 3, 3, 2, 4, 4 },',
    '        { 4, 4, 4, 5, 3, 3, 4, 0, 3, 4, 4, 4, 4, 4, 3, 4, 4 },',
    '        { 4, 4, 4, 5, 1, 1, 4, 3, 0, 3, 3, 1, 2, 2, 1, 4, 3 },',
    '        { 4, 3, 2, 5, 3, 3, 2, 3, 3, 0, 1, 3, 2, 2, 2, 4, 3 },',
    '        { 4, 1, 1, 4, 2, 2, 1, 3, 3, 1, 0, 2, 1, 1, 1, 5, 3 },',
    '        { 3, 3, 3, 0, 0, 0, 0, 4, 0, 3, 2, 0, 3, 3, 2, 4, 2 },',
    '        { 3, 2, 2, 4, 2, 2, 3, 3, 2, 3, 2, 3, 0, 0, 0, 3, 2 },',
    '        { 2, 1, 1, 4, 2, 2, 3, 3, 2, 2, 2, 3, 0, 0, 0, 3, 3 },',
    '        { 3, 2, 2, 3, 1, 1, 2, 2, 1, 3, 2, 1, 0, 0, 0, 3, 3 },',
    '        { 3, 5, 5, 3, 4, 4, 4, 4, 4, 4, 5, 4, 3, 3, 4, 0, 2 },',
    '        { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 3, 3, 3, 3, 0 },',
    '    };',
    '    if (viewer < SUB_DWARF_GRAY',
    '        || viewer > SUB_HUMAN',
    '        || viewed < SUB_DWARF_GRAY',
    '        || viewed > SUB_HUMAN)',
    '        return PREF_N;',
    '    return (RacePref)M[viewer - 1][viewed - 1];',
    '}',
    '',
    '// ---------------------------------------------------------------------------',
    '// The sub-race mechanics (UA pp. 10-12),',
    '// as one traits record per sub-race. Zero',
    '// means the racial standard of the parent',
    '// (races.h); only the deltas the print',
    '// names are pinned here.',
    '// ---------------------------------------------------------------------------',
    '',
    'struct SubRaceTraits {',
    '    // die-roll adjustments to the initially',
    '    // generated scores (the UA sub-race',
    '    // bonuses, in ABILITY_ order):',
    '    // gray elf +1 INT (max 19); wood elf',
    '    // +1 STR (max 18) and -1 INT; wild',
    '    // elf +2 STR (max 18). All others 0.',
    '    int adj[ABILITY_COUNT];',
    '    // per-ability maxima, 0 = the racial',
    '    // standard (the parent-race Table III',
    '    // maximum); 19 only where the print',
    '    // lifts it (gray elf INT)',
    '    int max[ABILITY_COUNT];',
    '    // infravision in feet; 0 = the racial',
    '    // standard (120 for the three deep',
    '    // strains: duergar, drow, svirfneblin)',
    '    int infravisionFeet;',
    '    // save bonuses pinned by the print:',
    '    // drow +2 versus magical effects;',
    '    // svirfneblin +2 versus poison and',
    '    // +3 on all other saves',
    '    int saveVsMagicBonus;',
    '    int saveVsPoisonBonus;',
    '    int saveOtherBonus;',
    '    // the immunity flags',
    '    int illusionImmune;        // duergar,',
    '                               // svirfneblin',
    '    int paralysisImmune;       // duergar',
    '    int magicPoisonImmune;     // duergar:',
    '                              // immune to',
    '                              // non-natural',
    '                              // (magical or',
    '                              // alchemical)',
    '                              // poisons',
    '    // surprise arithmetic: N-in-D to',
    '    // surprise others (alone or in the',
    '    // company of the same sub-race);',
    '    // N-in-D to be surprised. 0 = the',
    '    // standard (duergar 3-in-6 and',
    '    // 1-in-10; drow 1-in-8; svirfneblin',
    '    // 9-in-10 and 1-in-12)',
    '    int surpriseOn, surpriseDie;',
    '    int surprisedOn, surprisedDie;',
    '    // the drow sex-split movement rates',
    '    // (female 15, male 12); 0 = standard',
    '    int moveFemale, moveMale;',
    '    // the outcast flags',
    '    int twoWeaponFree;   // drow: fight',
    '                         // two-weapon',
    '                         // without',
    '                         // penalty, no',
    '                         // shield, spiked',
    '                         // buckler allowed',
    '    int losesSwordBowBonus;  // drow: no',
    '                            // surface-elf',
    '                            // sword/bow',
    '                            // combat bonus',
    '    int maleOnlyPC;      // svirfneblin',
    '    int noPsionics;      // svirfneblin',
    '                         // player chars',
    '};',
    '',
    'inline const SubRaceTraits& subraceTraits(',
    '        CharSubRace s) {',
    '    static const SubRaceTraits T[SUBRACE_COUNT] = {',
    '        // SUB_NONE',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_DWARF_GRAY (duergar)',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          120, 0, 0, 0, 1, 1, 1,',
    '          3, 6, 1, 10, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_DWARF_HILL',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_DWARF_MOUNTAIN',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_ELF_DARK (drow, outcast)',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          120, 2, 0, 0, 0, 0, 0,',
    '          0, 0, 1, 8, 15, 12, 1, 1, 0, 0 },',
    '        // SUB_ELF_GRAY',
    '        { {0, 1, 0, 0, 0, 0},',
    '          {0, 19, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_ELF_HIGH',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_ELF_VALLEY (gray + gnomish)',
    '        { {0, 1, 0, 0, 0, 0},',
    '          {0, 19, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_ELF_WILD (grugach)',
    '        { {2, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_ELF_WOOD (sylvan)',
    '        { {1, -1, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_GNOME_DEEP (svirfneblin)',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          120, 0, 2, 3, 1, 0, 0,',
    '          9, 10, 1, 12, 0, 0, 0, 0, 1, 1 },',
    '        // SUB_GNOME_SURFACE',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_HALFELF (ancestry separate)',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_HALFLING_HAIRFOOT',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_HALFLING_STOUT (mixed blood reads as stout)',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_HALFLING_TALLFELLOW',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_HALF_ORC',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '        // SUB_HUMAN',
    '        { {0, 0, 0, 0, 0, 0},',
    '          {0, 0, 0, 0, 0, 0},',
    '          0, 0, 0, 0, 0, 0, 0,',
    '          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },',
    '    };',
    '    return T[s < SUBRACE_COUNT ? s : SUB_NONE];',
    '}',
    '',
    '// The duergar daylight ladder (UA p.10):',
    '// exposed to daylight or continual light',
    '// the surprise bonus is negated, DEX is',
    '// effectively -2, attacks -2 to hit and',
    '// the opponents save at +2 versus gray',
    '// dwarf attacks; attacking from darkness',
    '// into lit foes: -1 to hit, opponents',
    '// save at +1. The dim sources (torches,',
    '// lanterns, light spells, faerie fire,',
    '// magical weapons) do NOT affect duergar.',
    '// Drow are affected in the same manner.',
    'inline int duergarDayDexPenalty()  { return 2; }',
    'inline int duergarDayToHitPenalty()',
    '    { return 2; }',
    'inline int duergarDayOpponentSaveBonus()',
    '    { return 2; }',
    'inline int duergarShadowToHitPenalty()',
    '    { return 1; }',
    'inline int duergarShadowSaveBonus()',
    '    { return 1; }',
    '',
    '// The duergar multi-class list (the',
    '// print): fighter/cleric, fighter/thief,',
    '// cleric/thief, cleric/assassin.',
    'inline int duergarMultiClassCount() { return 4; }',
    '',
    '// The grugach reads (UA p.10): the',
    '// fighter/thief-only multi-class gate and',
    '// the 90% pit, snare and natural-trap',
    '// success.',
    'inline int wildElfMultiClassCount() { return 1; }',
    'inline int wildElfTrapSuccessPct() { return 90; }',
    '',
    '// The grugach also deal with woodland',
    '// creatures as if animal friendship were',
    '// in operation (a caller concern, named',
    '// here - the flag lives in the callers).',
    'inline int wildElfAnimalFriendshipDeal()',
    '    { return 1; }',
    '',
    '// The svirfneblin reads (UA p.11): the',
    '// 60% camouflage against natural rock',
    '// deep underground (until move, attack',
    '// or another negating action), the',
    '// non-detection the character radiates',
    '// (self only, not an area), and the',
    '// bright-light reads (all vision',
    '// reduced to 3, -1 to hit while',
    '// fighting in such light).',
    'inline int svirfCamouflagePct()   { return 60; }',
    'inline int svirfBrightLightFeet() { return 30; }',
    'inline int svirfBrightToHitPenalty()',
    '    { return 1; }',
    '',
    '// The svirfneblin earth elemental table',
    '// (d20, once per day at 6th level for',
    '// non-illusionists, conjure elemental',
    '// fashion): six outcome rows.',
    'struct EarthElementalRow {',
    '    int lo, hi;          // the d20 span',
    '    const char* result;  // the summon',
    '                         // outcome',
    '};',
    'inline const EarthElementalRow*',
    'svirfEarthElementalTable(int& n) {',
    '    static const EarthElementalRow R[6] = {',
    '        { 1, 1,  "24 HD earth elemental" },',
    '        { 2, 6,  "16 HD earth elemental" },',
    '        { 7, 10, "12 HD earth elemental" },',
    '        { 11, 15, "8 HD earth elemental" },',
    '        { 16, 18, "xorn" },',
    '        { 19, 20,',
    '          "summoning fails, not retryable"',
    '          " that day" }',
    '    };',
    '    n = 6;',
    '    return R;',
    '}',
    '',
    '// The innate spell lists (once per day,',
    '// pinned by name; the spell-registry',
    '// linkage is the wiring round):',
    '//   drow base: dancing lights, faerie',
    '//   fire, darkness 5 ft radius',
    '//   drow 4th level (any class): detect',
    '//   magic, know alignment, levitate',
    '//   drow female 4th level+: clairvoyance,',
    '//   detect lie (or reverse), suggestion,',
    '//   dispel magic',
    '//   svirfneblin: blindness, blur, change',
    '//   self (as an illusionist of the',
    '//   highest class level)',
    'inline int drowInnateBase(const char**& L) {',
    '    static const char* B[3] = {',
    '        "dancing lights", "faerie fire",',
    '        "darkness 5 ft radius" };',
    '    L = B; return 3;',
    '}',
    'inline int drowInnateAt4(const char**& L) {',
    '    static const char* B[3] = {',
    '        "detect magic", "know alignment",',
    '        "levitate" };',
    '    L = B; return 3;',
    '}',
    'inline int drowInnateFemale4(const char**& L) {',
    '    static const char* B[4] = {',
    '        "clairvoyance", "detect lie",',
    '        "suggestion", "dispel magic" };',
    '    L = B; return 4;',
    '}',
    'inline int svirfInnate(const char**& L) {',
    '    static const char* B[3] = {',
    '        "blindness", "blur", "change self" };',
    '    L = B; return 3;',
    '}',
    '',
    '// The drow silent tongue: the hand-signal',
    '// language of the subterranean dwellers,',
    '// 30 ft range, full mastery drow only',
    '// (others may learn the basic signs).',
    'inline int drowSilentTongueRangeFeet()',
    '    { return 30; }',
    '',
    '// The svirfneblin melee bonus: +1 to hit',
    '// AND damage versus drow and kuo-toa',
    '// (the enemies of the deep race); the',
    '// giant-kind attack penalties read as',
    '// the surface gnomes (the races.h foe',
    '// lists).',
    'inline int svirfDeepFoeToHitBonus()  { return 1; }',
    'inline int svirfDeepFoeDamageBonus() { return 1; }',
    '',
    '// The half-elf ancestries (UA p.11):',
    '// high-elf descent is the PHB half-elf;',
    '// gray, wood and valley descent carry',
    '// similar abilities; grugach descent is',
    '// unknown (the print: no instances',
    '// known); drow descent keeps the',
    '// light-sensitivity penalty, gains NO',
    '// drow advantages, and is outcast to the',
    '// dark elves. Pinned as the recorded',
    '// ancestry read; the caller layers it.',
    'enum HalfElfAncestry : int {',
    '    HE_ANCESTRY_HIGH = 0,',
    '    HE_ANCESTRY_GRAY,',
    '    HE_ANCESTRY_WOOD,',
    '    HE_ANCESTRY_VALLEY,',
    '    HE_ANCESTRY_GRUGACH,  // no instances',
    '                         // known - the',
    '                         // print',
    '    HE_ANCESTRY_DROW,     // the light',
    '                         // penalty,',
    '                         // no drow',
    '                         // advantages,',
    '                         // outcast',
    '    HE_ANCESTRY_COUNT',
    '};',
    'inline int halfElfAncestryExists(',
    '        HalfElfAncestry a) {',
    '    // grugach descent: no instances known',
    '    return a == HE_ANCESTRY_GRUGACH',
    '        ? 0 : 1;',
    '}',
    '',
    '// The comeliness sub-race grain (the',
    '// R322 recorded read, now homed): the',
    '// viewed-race adjustments for the elf',
    '// strains - the engine elf carries the',
    '// +1 sylvan read; the gray and high',
    '// strains read +2 against other-race',
    '// viewers. Point-for-point pairs (gray',
    '// and high; half-elf and sylvan) treat',
    '// as same race - the caller concern.',
    'inline int uaComelinessViewedSubraceAdj(',
    '        CharSubRace viewed) {',
    '    switch (viewed) {',
    '        case SUB_ELF_GRAY:',
    '        case SUB_ELF_HIGH:',
    '            return 2;',
    '        case SUB_ELF_WOOD:',
    '            return 1;   // the sylvan read',
    '        default:',
    '            return 0;   // the parent-race',
    '                        // adjustment rules',
    '    }',
    '}',
    '',
    '} // namespace rules',
])

AUD_BLOCK = NL.join([
    '    // ---- R323: the subrace layer seam audit ----',
    '    // The UA subrace seam (rules/subraces.h):',
    '    // the 17 racial types, Race Table I',
    '    // with the alignment column, the',
    '    // Racial Preferences matrix, the',
    '    // sub-race mechanics traits. Pinned',
    '    // data only - the wiring rounds',
    '    // follow. Draw-independent.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // U1: the enum shape',
    '        {',
    '            if (SUBRACE_COUNT != 18) ++bad;',
    '            if (UACLASS_COUNT != 14) ++bad;',
    '            if (HE_ANCESTRY_COUNT != 6) ++bad;',
    '            if (subraceName(SUB_NONE)[0]',
    '                != \'N\') ++bad;',
    '        }',
    '        // U2: the parent mapping',
    '        {',
    '            if (subraceParentRace(',
    '                    SUB_DWARF_GRAY)',
    '                != RACE_DWARF) ++bad;',
    '            if (subraceParentRace(',
    '                    SUB_DWARF_MOUNTAIN)',
    '                != RACE_DWARF) ++bad;',
    '            if (subraceParentRace(',
    '                    SUB_ELF_DARK)',
    '                != RACE_ELF) ++bad;',
    '            if (subraceParentRace(',
    '                    SUB_ELF_WOOD)',
    '                != RACE_ELF) ++bad;',
    '            if (subraceParentRace(',
    '                    SUB_GNOME_DEEP)',
    '                != RACE_GNOME) ++bad;',
    '            if (subraceParentRace(',
    '                    SUB_HALFELF)',
    '                != RACE_HALF_ELF) ++bad;',
    '            if (subraceParentRace(',
    '                    SUB_HALFLING_STOUT)',
    '                != RACE_HALFLING) ++bad;',
    '            if (subraceParentRace(',
    '                    SUB_HALF_ORC)',
    '                != RACE_HALF_ORC) ++bad;',
    '            if (subraceParentRace(',
    '                    SUB_HUMAN)',
    '                != RACE_HUMAN) ++bad;',
    '        }',
    '        // U3: Race Table I - the spot cells',
    '        // (the drow cavalier, the valley',
    '        // gate, the grugach limits, the',
    '        // gnome illusionist, the halfling',
    '        // assassin ban, the half-elf bard,',
    '        // the human full row)',
    '        {',
    '            if (!subraceClassAllowed(',
    '                SUB_ELF_DARK,',
    '                UACLASS_CAVALIER)) ++bad;',
    '            if (subraceClassAllowed(',
    '                SUB_ELF_VALLEY,',
    '                UACLASS_CAVALIER)) ++bad;',
    '            if (subraceClassAllowed(',
    '                SUB_ELF_VALLEY,',
    '                UACLASS_MAGIC_USER)) ++bad;',
    '            if (subraceClassAllowed(',
    '                SUB_ELF_WILD,',
    '                UACLASS_RANGER)) ++bad;',
    '            if (subraceClassAllowed(',
    '                SUB_ELF_WILD,',
    '                UACLASS_DRUID) != true)',
    '                ++bad;',
    '            if (subraceClassAllowed(',
    '                SUB_GNOME_DEEP,',
    '                UACLASS_ILLUSIONIST)',
    '                != true) ++bad;',
    '            if (subraceClassAllowed(',
    '                SUB_HALFLING_STOUT,',
    '                UACLASS_ASSASSIN)) ++bad;',
    '            if (subraceClassAllowed(',
    '                SUB_HALFELF,',
    '                UACLASS_BARD) != true) ++bad;',
    '            if (subraceClassAllowed(',
    '                SUB_HALFELF,',
    '                UACLASS_ILLUSIONIST))',
    '                ++bad;',
    '            if (subraceClassAllowed(',
    '                SUB_HALF_ORC,',
    '                UACLASS_DRUID)) ++bad;',
    '            if (subraceClassAllowed(',
    '                SUB_DWARF_GRAY,',
    '                UACLASS_DRUID)) ++bad;',
    '            if (subraceClassAllowed(',
    '                SUB_ELF_WOOD,',
    '                UACLASS_MAGIC_USER)',
    '                != true) ++bad;',
    '            if (subraceClassAllowed(',
    '                SUB_ELF_DARK,',
    '                UACLASS_PALADIN)) ++bad;',
    '            int all = 0;',
    '            for (int c = 0;',
    '                 c < UACLASS_COUNT; ++c) {',
    '                if (!subraceClassAllowed(',
    '                    SUB_HUMAN,',
    '                    (UaClass)c)) ++all;',
    '            }',
    '            if (all) ++bad;',
    '        }',
    '        // U4: the alignment column',
    '        {',
    '            if (uaClassAlignmentReq(',
    '                UACLASS_PALADIN)',
    '                != UA_ALIGN_LG_ONLY) ++bad;',
    '            if (uaClassAlignmentReq(',
    '                UACLASS_DRUID)',
    '                != UA_ALIGN_TRUE_NEUTRAL)',
    '                ++bad;',
    '            if (uaClassAlignmentReq(',
    '                UACLASS_ASSASSIN)',
    '                != UA_ALIGN_ANY_EVIL) ++bad;',
    '            if (uaClassAlignmentReq(',
    '                UACLASS_MONK)',
    '                != UA_ALIGN_ANY_LAWFUL) ++bad;',
    '            if (uaClassAlignmentReq(',
    '                UACLASS_BARD)',
    '                != UA_ALIGN_ANY_NEUTRAL)',
    '                ++bad;',
    '            if (uaClassAlignmentReq(',
    '                UACLASS_BARBARIAN)',
    '                != UA_ALIGN_NON_LAWFUL) ++bad;',
    '            if (uaClassAlignmentReq(',
    '                UACLASS_THIEF)',
    '                != UA_ALIGN_NON_GOOD) ++bad;',
    '            if (uaClassAlignmentReq(',
    '                UACLASS_CLERIC)',
    '                != UA_ALIGN_ANY) ++bad;',
    '        }',
    '        // U5: the preferences matrix - all',
    '        // 289 cells in range, the diagonal',
    '        // all P, the print asymmetries',
    '        {',
    '            for (int v = SUB_DWARF_GRAY;',
    '                 v <= SUB_HUMAN; ++v) {',
    '                for (int w = SUB_DWARF_GRAY;',
    '                     w <= SUB_HUMAN; ++w) {',
    '                    RacePref p =',
    '                        subracePrefers(',
    '                        (CharSubRace)v,',
    '                        (CharSubRace)w);',
    '                    if (p < PREF_P',
    '                        || p > PREF_H) ++bad;',
    '                }',
    '            }',
    '            for (int v = SUB_DWARF_GRAY;',
    '                 v <= SUB_HUMAN; ++v) {',
    '                if (subracePrefers(',
    '                    (CharSubRace)v,',
    '                    (CharSubRace)v)',
    '                    != PREF_P) ++bad;',
    '            }',
    '            // the print pins: dark elves',
    '            // view all halflings with',
    '            // antipathy, tallfellows read',
    '            // dark elves neutral',
    '            if (subracePrefers(',
    '                SUB_ELF_DARK,',
    '                SUB_HALFLING_HAIRFOOT)',
    '                != PREF_A) ++bad;',
    '            if (subracePrefers(',
    '                SUB_HALFLING_TALLFELLOW,',
    '                SUB_ELF_DARK)',
    '                != PREF_N) ++bad;',
    '            // half-orcs hate both dwarf',
    '            // strains; humans tolerate',
    '            // half-elves',
    '            if (subracePrefers(',
    '                SUB_HALF_ORC,',
    '                SUB_DWARF_HILL)',
    '                != PREF_H) ++bad;',
    '            if (subracePrefers(',
    '                SUB_HALF_ORC,',
    '                SUB_DWARF_MOUNTAIN)',
    '                != PREF_H) ++bad;',
    '            if (subracePrefers(',
    '                SUB_HUMAN, SUB_HALFELF)',
    '                != PREF_T) ++bad;',
    '            // the letter roundtrip',
    '            if (racePrefLetter(PREF_P)[0]',
    '                != \'P\') ++bad;',
    '            if (racePrefLetter(PREF_H)[0]',
    '                != \'H\') ++bad;',
    '            // out-of-range reads neutral',
    '            if (subracePrefers(SUB_NONE,',
    '                SUB_HUMAN)',
    '                != PREF_N) ++bad;',
    '        }',
    '        // U6: the traits - the ability',
    '        // grain, the deep-strain reads',
    '        {',
    '            const SubRaceTraits& g =',
    '                subraceTraits(SUB_ELF_GRAY);',
    '            if (g.adj[ABILITY_INT] != 1',
    '                || g.max[ABILITY_INT] != 19)',
    '                ++bad;',
    '            const SubRaceTraits& v =',
    '                subraceTraits(SUB_ELF_VALLEY);',
    '            if (v.adj[ABILITY_INT] != 1',
    '                || v.max[ABILITY_INT] != 19)',
    '                ++bad;',
    '            const SubRaceTraits& w =',
    '                subraceTraits(SUB_ELF_WOOD);',
    '            if (w.adj[ABILITY_STR] != 1',
    '                || w.adj[ABILITY_INT] != -1)',
    '                ++bad;',
    '            const SubRaceTraits& g2 =',
    '                subraceTraits(SUB_ELF_WILD);',
    '            if (g2.adj[ABILITY_STR] != 2)',
    '                ++bad;',
    '            const SubRaceTraits& d =',
    '                subraceTraits(SUB_DWARF_GRAY);',
    '            if (d.illusionImmune != 1',
    '                || d.paralysisImmune != 1',
    '                || d.magicPoisonImmune',
    '                != 1) ++bad;',
    '            if (d.surpriseOn != 3',
    '                || d.surpriseDie != 6',
    '                || d.surprisedOn != 1',
    '                || d.surprisedDie != 10)',
    '                ++bad;',
    '            if (d.infravisionFeet != 120)',
    '                ++bad;',
    '            const SubRaceTraits& e =',
    '                subraceTraits(SUB_ELF_DARK);',
    '            if (e.saveVsMagicBonus != 2',
    '                || e.surprisedOn != 1',
    '                || e.surprisedDie != 8',
    '                || e.moveFemale != 15',
    '                || e.moveMale != 12',
    '                || e.twoWeaponFree != 1',
    '                || e.losesSwordBowBonus != 1',
    '                || e.infravisionFeet != 120)',
    '                ++bad;',
    '            const SubRaceTraits& n =',
    '                subraceTraits(SUB_GNOME_DEEP);',
    '            if (n.saveVsPoisonBonus != 2',
    '                || n.saveOtherBonus != 3',
    '                || n.illusionImmune != 1',
    '                || n.surpriseOn != 9',
    '                || n.surpriseDie != 10',
    '                || n.surprisedOn != 1',
    '                || n.surprisedDie != 12',
    '                || n.maleOnlyPC != 1',
    '                || n.noPsionics != 1',
    '                || n.infravisionFeet != 120)',
    '                ++bad;',
    '        }',
    '        // U7: the prose pins - the',
    '        // daylight ladders, the grugach',
    '        // and svirfneblin reads, the',
    '        // elemental table, the innate',
    '        // spell lists',
    '        {',
    '            if (duergarDayDexPenalty() != 2',
    '                || duergarDayToHitPenalty()',
    '                != 2',
    '                || duergarDayOpponentSaveBonus()',
    '                != 2',
    '                || duergarShadowToHitPenalty()',
    '                != 1',
    '                || duergarShadowSaveBonus()',
    '                != 1) ++bad;',
    '            if (wildElfTrapSuccessPct() != 90',
    '                || wildElfMultiClassCount()',
    '                != 1',
    '                || wildElfAnimalFriendshipDeal()',
    '                != 1) ++bad;',
    '            if (svirfCamouflagePct() != 60',
    '                || svirfBrightLightFeet() != 30',
    '                || svirfBrightToHitPenalty()',
    '                != 1',
    '                || svirfDeepFoeToHitBonus() != 1',
    '                || svirfDeepFoeDamageBonus()',
    '                != 1) ++bad;',
    '            int n = 0;',
    '            const EarthElementalRow* R =',
    '                svirfEarthElementalTable(n);',
    '            if (n != 6) ++bad;',
    '            if (R[0].lo != 1 || R[0].hi != 1)',
    '                ++bad;',
    '            if (R[1].lo != 2 || R[1].hi != 6)',
    '                ++bad;',
    '            if (R[2].lo != 7 || R[2].hi != 10)',
    '                ++bad;',
    '            if (R[3].lo != 11 || R[3].hi != 15)',
    '                ++bad;',
    '            if (R[4].lo != 16 || R[4].hi != 18)',
    '                ++bad;',
    '            if (R[5].lo != 19 || R[5].hi != 20)',
    '                ++bad;',
    '            if (R[5].result[0] != \'s\') ++bad;',
    '            // the spans tile the d20',
    '            for (int i = 0; i < n; ++i) {',
    '                if (i && R[i].lo',
    '                    != R[i-1].hi + 1) ++bad;',
    '            }',
    '            const char** L = 0;',
    '            if (drowInnateBase(L) != 3) ++bad;',
    '            if (L[0][0] != \'d\'',
    '                || L[1][0] != \'f\'',
    '                || L[2][0] != \'d\') ++bad;',
    '            if (drowInnateAt4(L) != 3) ++bad;',
    '            if (L[0][0] != \'d\') ++bad;',
    '            if (drowInnateFemale4(L) != 4)',
    '                ++bad;',
    '            if (svirfInnate(L) != 3) ++bad;',
    '            if (L[0][0] != \'b\') ++bad;',
    '            if (drowSilentTongueRangeFeet()',
    '                != 30) ++bad;',
    '            if (duergarMultiClassCount() != 4)',
    '                ++bad;',
    '        }',
    '        // U8: the half-elf ancestries and',
    '        // the comeliness subrace grain',
    '        {',
    '            if (halfElfAncestryExists(',
    '                HE_ANCESTRY_GRUGACH))',
    '                ++bad;',
    '            if (!halfElfAncestryExists(',
    '                HE_ANCESTRY_HIGH)) ++bad;',
    '            if (!halfElfAncestryExists(',
    '                HE_ANCESTRY_DROW)) ++bad;',
    '            if (uaComelinessViewedSubraceAdj(',
    '                SUB_ELF_GRAY) != 2) ++bad;',
    '            if (uaComelinessViewedSubraceAdj(',
    '                SUB_ELF_HIGH) != 2) ++bad;',
    '            if (uaComelinessViewedSubraceAdj(',
    '                SUB_ELF_WOOD) != 1) ++bad;',
    '            if (uaComelinessViewedSubraceAdj(',
    '                SUB_HUMAN) != 0) ++bad;',
    '        }',
    '        printf("R323 subrace layer seam audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
])

GP_EDITS = [
    ('- [ ] **Race Table I** (p. 7, the\n' 
      '      class-limit matrix, 15 racial types\n' 
      '      against 13 classes) - reads clean;\n' 
      '      needs the subrace layer first.',     '- [x] **Race Table I** (p. 7, the\n' 
      '      class-limit matrix, 15 racial\n' 
      '      types against the 14 UA classes)\n' 
      '      - CLOSED R323: the CharSubRace\n' 
      '      and UaClass enums, the matrix\n' 
      '      and the alignment-requirements\n' 
      '      column, rules/subraces.h; the\n' 
      '      R323 seam audit.'),
    ('      single-class +2 level bonus rule\n' 
      '      ride with them.',     '      single-class +2 level bonus rule\n' 
      '      ride with them. UNBLOCKED R323:\n' 
      '      the seam exists; this is now a\n' 
      '      plain engine charge (its own\n' 
      '      round).'),
    ('- [ ] **The sub-races** (pp. 10-12) -\n' 
      '      the per-type mechanics: gray dwarves\n' 
      '      (duergar: the illusion immunity, the\n' 
      '      paralyzation and poison immunities,\n' 
      '      the daylight penalty ladder, the\n' 
      '      3-in-6 surprise, the undercommon\n' 
      '      tongue), gray elves (the +1\n' 
      '      intelligence, max 19), wood/sylvan\n' 
      '      elves, wild/grugach elves (the trap\n' 
      '      success bonuses), valley elves,\n' 
      '      dark elves, deep gnomes (the\n' 
      '      stone-cunning reads), the halfling\n' 
      '      strains (hairfoot, stout,\n' 
      '      tallfellow), the half-elf variants,\n' 
      '      the half-orcs. The engine CharRace\n' 
      '      enum carries seven races and no\n' 
      '      subrace layer - the subrace layer\n' 
      '      is the gateway pin for the whole\n' 
      '      section.',     '- [x] **The sub-races** (pp. 10-12) -\n' 
      '      CLOSED R323: the SubRaceTraits\n' 
      '      records - the duergar immunities,\n' 
      '      surprise and daylight ladder;\n' 
      '      the gray/valley +1 INT max 19;\n' 
      '      the wood +1 STR/-1 INT; the\n' 
      '      grugach +2 STR, the 90 traps,\n' 
      '      the fighter/thief gate; the drow\n' 
      '      +2 magic saves, the sex-split\n' 
      '      movement, the two-weapon read,\n' 
      '      the innate spell lists, the\n' 
      '      light penalties; the svirfneblin\n' 
      '      saves, the camouflage, the\n' 
      '      earth elemental table, the\n' 
      '      innate spells; the half-elf\n' 
      '      ancestries with the grugach\n' 
      '      no-instances read; the halfling\n' 
      '      strains with the mixed-blood\n' 
      '      stout read - rules/subraces.h.'),
    ('- [ ] **The Racial Preferences matrix**\n' 
      '      (p. 12) - reads clean (the P/G/T/\n' 
      '      N/A/H codes, 17x17); depends on the\n' 
      '      subrace layer; the R117 reaction\n' 
      '      table has no callers, so this is a\n' 
      '      pin-only charge.',     '- [x] **The Racial Preferences matrix**\n' 
      '      (p. 12) - CLOSED R323: the 17x17\n' 
      '      letter matrix (the P/G/T/N/A/H\n' 
      '      codes), the diagonal-P check and\n' 
      '      the print asymmetries pinned; the\n' 
      '      half-elf footnote (elves react as\n' 
      '      the worse of half-elf or the\n' 
      '      ancestor) named for the caller;\n' 
      '      rules/subraces.h; pin-only until\n' 
      '      the reaction site exists.'),
    ('- [ ] The subrace layer - gates Race\n' 
      '      Table I, Race Table II, the\n' 
      '      sub-race mechanics, the Racial\n' 
      '      Preferences matrix.',     '- [x] The subrace layer - CLOSED R323\n' 
      '      (rules/subraces.h; the R323 seam\n' 
      '      audit, census 250). Race Table\n' 
      '      II and the wiring (the race\n' 
      '      selection site, the R117\n' 
      '      reactions) remain its open\n' 
      '      dependents.'),
    ('      read; the +2 gray/high subrace\n' 
      '      grain stays recorded - no subrace\n' 
      '      layer); the ten reaction bands; the',     '      read; the +2 gray/high subrace\n' 
      '      grain pins in the R323 subrace\n' 
      '      layer); the ten reaction bands; the'),
]

SEED_ENTRY = NL.join([
    '',
    '- R322 landed 2026-10-11: commit',
    '  f83e11b, census 249, the UA arc',
    '  opener: the comeliness pins',
    '  (rules/comeliness.h) and the',
    '  lossless ua gap report',
    '  (tools/ua_gap_report.md) with the',
    '  DEFERRED ontology (OUT nearly',
    '  empty by design), the',
    '  deferred-seams dependency graph,',
    '  the playability closure criterion,',
    '  the switchable treasure decision.',
    '  GREEN on the second paste.',
    '  Lessons: (1) a ritual block must',
    '  be paste-safe - prose annotations',
    '  in a shell block run as commands;',
    '  the first paste executed nothing',
    '  but noise and the splice never',
    '  ran (preflight RED caught it',
    '  before any git damage); (2) a',
    '  pasted splice can hash off by a',
    '  trailing newline (the nano save)',
    '  - wc -c against the recorded',
    '  byte count confirms the case, and',
    '  the internal asserts plus the',
    '  double-run are the content proof;',
    '  (3) the OUT/DEFERRED axis lesson:',
    '  the survey axis (can the engine',
    '  hold it today) is not the intent',
    '  axis (is it wanted, ever) -',
    '  DEFERRED is the default resting',
    '  state under the everything-and-',
    '  the-kitchen-sink mission.',
]) + NL


# ---- (a) the seed: the R322 entry ----
SEED = 'doc/vibe/adnd1_knowledge_seed_v2.md'
s = rd(SEED)
clean(SEED_ENTRY, 72)
if '- R322 landed 2026-10-11: commit' in s:
    already.append('the seed: the R322 entry')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'seed anchor'
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SEED, s)
    applied.append('the seed: the R322 entry')
s = rd(SEED)
assert s.count('- R322 landed 2026-10-11: commit') == 1, 'a once'
assert s.count('- R321 landed 2026-10-11: commit') == 1, 'a r321 kept'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) rules/subraces.h: the seam ----
SR = 'rules/subraces.h'
cleanNB(SR_FILE, 78)
if os.path.exists(os.path.join(ROOT, SR)):
    s = rd(SR)
    if 'SUB_COUNT' in s:
        # the v1 seam landed under the
        # name that collides with the
        # subclasses.h SUB_COUNT - the
        # in-place rename, 3 sites
        assert s.count('SUB_COUNT') == 3, 'b legacy'
        wr(SR, s.replace('SUB_COUNT',
                         'SUBRACE_COUNT'))
        applied.append('subraces.h: the seam'
                       ' (the SUBRACE_COUNT'
                       ' rename)')
    else:
        already.append('subraces.h: the seam')
else:
    wr(SR, SR_FILE)
    applied.append('subraces.h: the seam')
s = rd(SR)
assert s.count('enum CharSubRace : int') == 1, 'b enum'
assert s.count('SUBRACE_COUNT') == 3, 'b sub count'
assert 'SUB_COUNT' not in s, 'b rename clean'
assert s.count('UACLASS_COUNT') == 1, 'b ua count'
assert s.count('subraceClassAllowed') == 1, 'b table i'
assert s.count('subracePrefers') == 1, 'b matrix'
assert s.count('subraceTraits') == 1, 'b traits'
assert s.count('uaComelinessViewedSubraceAdj') == 1, 'b grain'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) the gap report: the box flips ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
changed = False
for old, new in GP_EDITS:
    clean(old, 57)
    clean(new, 57)
    assert Q not in old and Q not in new, 'apostrophe in gp edit'
    if new in s:
        continue
    assert s.count(old) == 1, 'gp anchor not unique'
    s = s.replace(old, new)
    changed = True
if changed:
    wr(GP, s)
    applied.append('ua_gap_report.md: the box flips')
else:
    already.append('ua_gap_report.md: the box flips')
s = rd(GP)
assert s.count('CLOSED R323') == 4, 'c four closes'
assert s.count('UNBLOCKED R323') == 1, 'c unblock'
assert s.count('CLOSED R322') == 1, 'c r322 kept'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) regtest.cpp: the include and the audit ----
RG = 'regtest.cpp'
s = rd(RG)
INC_OLD = (NL + '#include "rules/comeliness.h"'
           '  // R322: UA comeliness pins')
INC_NEW = (INC_OLD + NL
           + '#include "rules/subraces.h"'
           '  // R323: UA subrace layer')
cleanNB(INC_NEW, 76)
AUD_ANCH = ('    // ---- R227: the wis mental'
            ' save wiring audit ----')
if 'R323 subrace layer seam audit' not in s:
    assert s.count(INC_OLD) == 1, 'd include anchor'
    s = s.replace(INC_OLD, INC_NEW)
    assert s.count(AUD_ANCH) == 1, 'd audit anchor'
    cleanNB(AUD_BLOCK, 76)
    s = s.replace(AUD_ANCH, AUD_BLOCK + NL + AUD_ANCH)
    wr(RG, s)
    applied.append('regtest.cpp: the include'
                   ' and the audit')
elif '(SUB_COUNT != 18)' in s:
    # the v1 audit landed under the
    # colliding name - the in-place
    # rename, one site
    assert s.count('(SUB_COUNT != 18)') == 1, 'd legacy'
    s = s.replace('(SUB_COUNT != 18)',
                  '(SUBRACE_COUNT != 18)')
    wr(RG, s)
    applied.append('regtest.cpp: the include'
                   ' and the audit (the'
                   ' SUBRACE_COUNT rename)')
else:
    already.append('regtest.cpp: the include'
                   ' and the audit')
s = rd(RG)
assert s.count('audit: bad') == 250, 'd census count'
assert s.count('(SUBRACE_COUNT != 18)') == 1, 'd u1'
assert '(SUB_COUNT != 18)' not in s, 'd rename'
assert s.count('R323 subrace layer seam audit') == 1, 'd print once'
assert s.count('rules/subraces.h') == 2, 'd include refs'
assert len(applied) + len(already) == 4, 'patch d count wrong'

if len(applied) + len(already) != 4:
    print('R323 splice: FAIL - expected 4 patches, '
          'counted ' + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R323 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R323b note: the SUBRACE_COUNT')
print('rename (the subclasses.h')
print('collision); the subrace layer seam')
print('opens the UA races section (Table I,')
print('the preferences matrix, the')
print('sub-race mechanics; Table II unblocked)')
print('the battery census moves 249 -> 250')
print('commit: R323: the UA subrace layer -')
print('the races seam (census 250)')

