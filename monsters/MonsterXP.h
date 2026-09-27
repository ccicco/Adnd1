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
//                   XP by class & level (approximated until wired
//                   to rules/classes; see note in the .cpp).
//
// The 355 merged_mm1 entries carry exact cross-checked book XP; the
// dispatch entries (43) resolve here at kill time from spawn context.
// ============================================================================

#pragma once

#include "MonsterRegistry.h"

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
    int heads       = 0;  // hydra heads (by_head_count). 0 = use def's HD.
    int ageBracket  = 0;  // dragon age 1-8 (age_bracket). 0 = use 5
                          //   (adult) for average-specimen figures.
    int actualHp    = 0;  // hit points of the killed specimen. 0 = book avg.
};

// DMG p.85 base XP for a monster of the given hit dice (tier 1, no
// exceptional abilities). Rows 1-10 verified against the merged data:
// minima of (hitDiceNum -> xp) over the 355 cross-checked entries.
// 11-20 interpolate the observed minima (12 HD -> 1300, 13 HD -> 1800);
// 21+ is an x1.15/hd extension (MM1 prints no XP up there).
int baseForHd(int hd);

// DMG p.85 XP-per-hit-point ladder. Verified against the merged data
// (e.g. aerial servant 16 HD -> 20/hp, elder titan 22 HD -> 35/hp).
int perHpForHd(int hd);

// Special-ability tier multiplier (DMG p.85): x1 none, x2 exceptional,
// x3 special, x4 special+exceptional. Heuristic from the loaded def:
// typed specials, magic resistance, weapon-plus requirement, and
// strong text markers. Callers may override the result when the
// encounter generator knows better (e.g. dragon spell ability).
int tierOf(const MonsterDef& def);

// Total XP for killing one specimen. Dispatches on def.xpSource.
int xpForKill(const MonsterDef& def, const SpawnContext& ctx);

} // namespace xp
} // namespace monsters
