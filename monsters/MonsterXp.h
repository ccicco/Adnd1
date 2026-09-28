// ============================================================================
// Adnd1 — monsters/MonsterXp.h
// R49+: runtime XP resolution for monsters whose XP is not a fixed
// number in the MM1 data (xpSource in the lua schema).
//
//   merged_mm1    : xp/xpPerHp/xpValue are book values — use as-is.
//   perm_x10      : unique demon/devil princes — printed lump XP (xp field).
//   role_variant  : variant of a base race — xp/xpValue already set.
//   by_hit_dice   : variable-HD animals (horses, whales, sharks) —
//                   roll HD at spawn, then DMG p.85 formula.
//   age_bracket   : dragons — age bracket (1-8) sets hp/die and the
//                   effective HD tier for the DMG formula.
//   by_head_count : hydra — heads = hit dice.
//   by_level      : classed NPCs (men-types, sahuagin clerics) —
//                   wired to rules/classes: per the p.85 footnote
//                   "all levels as the n + 1 hit dice category", a
//                   level-n character reads bracket row n+1; hp from
//                   the class hit die + Con; spell use is an
//                   exceptional ability (casters add EAXPA). Falls
//                   back to the generic approximation when
//                   ctx.classIndex is unknown.
//
// The 355 merged_mm1 entries carry exact cross-checked book XP; the
// dispatch entries (43) resolve here at kill time from spawn context.
// ============================================================================

#pragma once

#include "MonsterRegistry.h"
#include "../rules/classes.h"

namespace monsters {
namespace xp {

// ----------------------------------------------------------------------------
// SpawnContext: what the encounter generator knows when the monster
// is placed. Fields are optional (-1/0 = unknown); xpForKill falls
// back to sane defaults (documented per dispatch type in the .cpp).
// ----------------------------------------------------------------------------
struct SpawnContext {
    int hd          = -1; // effective hit dice (by_hit_dice/age_bracket/
                          //   by_head_count). -1 = use def.hitDiceNum.
    int level       = 0;  // classed-NPC level (by_level). 0 = 0-level man.
    int classIndex  = -1; // rules::CharClass (by_level). -1 = unknown:
                          //   falls back to the generic approximation.
    int conAdj      = 0;  // Con hp adjustment per die (by_level). 0 = avg.
    int heads       = 0;  // hydra heads (by_head_count). 0 = use def's HD.
    int ageBracket  = 0;  // dragon age 1-8 (age_bracket). 0 = use 5
                          //   (adult) for average-specimen figures.
    int actualHp    = 0;  // hit points of the killed specimen. 0 = book avg.
};

// R59: DMG p.85 printed ladders, verified against the Premium
// reprint (OCR page 86 of the upload). The pre-R59 ladders were
// derived from merged-data minima and diverged from print above
// 10 HD (and at HD 1/5/8 per-hp); they now follow the table:
//
//   bracket (HD)     BXPV   XP/HP   SAXPB   EAXPA
//   up to 1-1          5      1       2      25
//   1-1 to 1          10      1       4      35
//   1+1 to 2          20      2       8      45
//   2+1 to 3          35      3      15      55
//   3+1 to 4          60      4      25      65
//   4+1 to 5          90      5      40      75
//   5+1 to 6         150      6      75     125
//   6+1 to 7         225      8     125     175
//   7+1 to 8         375     10     175     275
//   8+1 to 9         600     12     300     400
//   9+1 to 10+       900     14     450     600
//   11 to 12+       1300     16     700     850
//   13 to 14+       1800     18     950    1200
//   15 to 16+       2400     20    1250    1600
//   17 to 18+       3000     25    1550    2000
//   19 to 20+       4000     30    2100    2500
//   21 and up       5000     35    2600    3000
//
// The int argument is the bracket-ending row: a monster of n+1 HD
// sits in the bracket ending at n+1 (rowForHd in the .cpp applies
// the "+1" rule when the def carries hit dice bonus). Row 0 is
// the sub-1-HD bracket. 21+ is FLAT per print (the pre-R59 code
// compounded x1.15/hd past 20 — retired).
int baseForHd(int hd);

// DMG p.85 XP-per-hit-point ladder (printed bands; see the table
// above). XP is awarded per hit point of the ACTUAL specimen.
int perHpForHd(int hd);

// DMG p.85 Special Ability X.P. Bonus (SAXPB) by the same bracket
// rows. Additive per special ability, cumulative per the book
// ("a gargoyle attacks 4 times per round and can be hit only by
// magic weapons, so a double Special Ability X.P. Bonus should be
// awarded").
int saxpbForHd(int hd);

// DMG p.85 Exceptional Ability X.P. Addition (EAXPA) by the same
// bracket rows. Additive per exceptional ability, cumulative; may
// be doubled for particularly powerful monsters (not modeled).
int eaxpaForHd(int hd);

// R59: the award is the printed ADDITIVE formula
//   BXPV + XP/HP x hp + SAXPB x nSpecial + EAXPA x nExceptional
// (book example: owlbear 30 hp = 150 + 180 + 75 = 405). The pre-R59
// x2/x3/x4 tier multipliers are retired. Ability counts come from
// the def: typed specials (poison/paralysis/drain/breath), magic
// resistance, hit-only-by-magic, 4+ attacks, AC 0 or lower, high
// damage (max > 24), high intelligence, and strong text markers.
// Heuristic — the book hand-tunes its own suggested values.
int specialCountOf(const MonsterDef& def);
int exceptionalCountOf(const MonsterDef& def);

// Total XP for killing one specimen. Dispatches on def.xpSource.
int xpForKill(const MonsterDef& def, const SpawnContext& ctx);

// R53: XP for a classed NPC killed OUTSIDE the lua registry —
// Character Subtable party members (the def-free by_level
// path; same DMG p.85 formula xpForKill dispatches to).
int xpForNpc(const SpawnContext& ctx);

} // namespace xp
} // namespace monsters
