// ============================================================================
// Adnd1 - rules/races.h
// The PC races layer: PHB pp.15-18, Race Tables I-III.
//
// R154: the races half of the authored-but-unlanded R148
// combined splice, re-authored against current main. The
// printed tables are pinned: class limitations (Table I),
// the footnoted level caps (Table II), ability minimums
// and maximums with the racial adjustments (Table III and
// the Penalties and Bonuses list), infravision, sleep and
// charm resistance, the CON magic-save (and where printed,
// poison-save) bonuses, the goblin-kind and giant-kind
// to-hit adjustments, and the detection lists.
//
// Enum order matches dm::NpcRace (R62) exactly, so the
// fiction layer and the rules layer share one indexing.
// ============================================================================

#pragma once

#include "character.h"
#include "classes.h"

#include <cstdint>

namespace rules {

enum CharRace : int {
    RACE_HUMAN = 0,
    RACE_DWARF,
    RACE_ELF,
    RACE_GNOME,
    RACE_HALF_ELF,
    RACE_HALFLING,
    RACE_HALF_ORC,
    RACE_CHAR_COUNT
};

const char* raceName(CharRace r);

// Racial adjustment applied to the initially rolled score
// when the race is selected (PHB Penalties and Bonuses):
//   dwarf     CON +1, CHA -1
//   elf       DEX +1, CON -1
//   half-orc  STR +1, CON +1, CHA -2
//   halfling  STR -1, DEX +1
//   gnome, half-elf, human: none
int raceAbilityAdj(CharRace r, Ability a);

// Table III minimums and maximums (male/female columns).
// Minimums are eligibility, met CONSIDERING the racial
// bonuses; maximums clamp the ADJUSTED score. Human: min 3,
// max 18 across the board. The dwarf charisma parenthetical
// (recorded 16(18) for dealings with dwarves) is a display
// concern, not engine data.
int raceAbilityMin(CharRace r, Ability a, bool female);
int raceAbilityMax(CharRace r, Ability a, bool female);

// The full race-selection arithmetic: adjustment first,
// then the maximum clamp. Scores can pass 18 only via the
// bonuses the print allows (dwarf CON 19, halfling CON 19,
// half-orc CON 19, elf DEX 19). No floor: an adjusted
// score below its minimum simply fails eligibility.
void applyRacialAdjustments(AbilityScores& s, CharRace r,
                            bool female);

// eligibility: every ADJUSTED score meets the Table III
// minimum for the race (the print: minimums must be met
// considering such bonuses)
bool raceMeetsMinimums(const AbilityScores& s, CharRace r,
                       bool female);

// Infravision in feet: 60 for dwarf, elf, gnome, half-elf
// and half-orc; halfling 30 (the mixed-blood line; pure
// Stoutish 60 is sub-race narration); human 0.
int raceInfravisionFeet(CharRace r);

// Resistance to sleep and charm spells, in percent: elf
// 90, half-elf 30. The percentile roll gates the magic
// before any save is even attempted (the print: 91 or
// better on d100 lets the spell try, and then the normal
// save applies).
int raceSleepCharmResistPct(CharRace r);

// CON magic-save bonus vs. wands, staves, rods and spells:
// +1 per 3.5 points of CON (the R147 dwarf shape), for
// dwarf, gnome and halfling. Poison saves ride the same
// bonus for dwarf and halfling; the gnome print gives the
// magic bonus ONLY (its paragraph names no poison line) -
// the gap box claimed gnome poison saves; the print wins.
int raceMagicSaveBonus(CharRace r, uint8_t con);
int racePoisonSaveBonus(CharRace r, uint8_t con);

// Race Table I, class limitations, for the base four
// classes (sub-classes are not modeled; the druid,
// illusionist, assassin, monk columns are out of scope).
bool classAllowedForRace(int classIndex, CharRace r);

// Race Table II, level caps WITH the printed footnotes,
// as a single lookup. Returns 0 when the class is not
// allowed for the race, -1 for unlimited, else the cap.
// The score arguments are the ADJUSTED scores.
int raceLevelCap(int classIndex, CharRace r, uint8_t str,
                 uint8_t int_, uint8_t dex);

// The goblin-kind and giant-kind melee lists (printed
// prose): dwarf adds +1 to hit half-orcs, goblins,
// hobgoblins and orcs; gnome adds +1 vs. kobolds and
// goblins. When ATTACKED by the big kinds the foe
// SUBTRACTS 4: dwarf vs. ogres, trolls, ogre magi,
// giants, titans; gnome vs. gnolls, bugbears and the
// same giant-kind list. The lists carry the printed base
// names; family-name matching (hill giant, stone giant)
// is the combat caller concern, named for a later round.
int raceBonusVsFoeName(CharRace r, const char* foeName);
int raceFoeAttackPenalty(CharRace r, const char* foeName);

// The racial detection lists, as printed in-N chances.
// The seeking rule is the caller concern: the print
// requires active seeking (depth at any distance).
struct ChanceIn { int num; int den; };
enum DetectKind : int {
    DET_GRADE = 0,            // passage slope, up or down
    DET_NEW_CONSTRUCTION,     // new construction or passage
    DET_SLIDING_WALLS,        // sliding or shifting walls/rooms
    DET_STONE_TRAPS,          // pits, falling blocks, stonework
    DET_DEPTH,                // approximate depth underground
    DET_UNSAFE_SURFACES,      // unsafe walls, ceilings, floors
    DET_DIRECTION,            // direction of travel underground
    DET_SECRET_PASS,          // secret/concealed door, passing
    DET_SECRET_SEARCH,        // secret door, active search
    DET_CONCEALED_SEARCH,     // concealed door, active search
    DET_KIND_COUNT
};
ChanceIn raceDetectChance(CharRace r, DetectKind k);
int raceDetectPct(CharRace r, DetectKind k);   // rounded down

} // namespace rules
