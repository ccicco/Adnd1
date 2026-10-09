// ====================================================================
// Adnd1 - rules/specartprose.h
// R280: the III.E Special artifacts explanation
// prose part 1 (DMG p.158-159) - the Notes
// Regarding Artifacts and Relics, part2 lines
// 1153-1182 (global = 11065 + part2 line),
// the series opener before the 29 artifact
// descriptions that follow (the Axe of the
// Dwarvish Lords onward lands with part 2).
// The notes pinned here: each artifact or
// relic is a singular thing; only 1 of each
// may exist; the listing is crossed off when
// placed or found, with a clue substituted
// or the result ignored; the powers are only
// partially described with the DM assigning
// the major powers; lore is not found by
// chance; the balance and nemesis-creature
// caution on homebrew items; the 5 tables of
// powers and side effects after the
// descriptions; the three hireling behaviors
// when an item is foisted off (evil destroys
// or escapes, neutral dominates, good
// defects with the item); the 10-30 percent
// loyalty drop when the holder is permanently
// harmed or killed; destruction by a single
// means; the deface save versus magic at
// minus 5 with failure equal to death; the
// four corruption traits; the permanent
// effects with the deity exception. This
// round has one seam restored: the p.158-159
// page break splits the opening paragraph
// between the 1153 tail (only 1 of each may
// exist. As) and the 1158 head (each is
// placed by you) across the blank pair at
// 1154-1155, the TREASURE (ARTIFACTS &
// RELICS) running head at 1156 and the 1157
// post-head blank. The upload quirks this
// round: five em dashes print true; the
// deface save minus prints true as the
// U+2212 minus sign; the employer/ master
// slash split carries a space while
// giving/forcing prints joined; the
// 10%-30% loyalty band prints with the
// percent-hyphen join - all pinned
// as plain digits and words, apostrophe-
// free here. The series opens beside the
// R240 sale table pins (specart.h): the sa
// accessors stay there, the notes land here
// as the sap accessors, no name collisions.
// 20 accessors: 20 scalars and no walkers -
// the series opens with notes only; the 5
// power tables and the destruction means
// table come after the 29 descriptions in
// later rounds. Pure data + helpers,
// header-only (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int sapOneOfEachExists() {
    // only 1 of each may exist - a singular thing
    return 1;
}

inline int sapListingCrossedWhenPlaced() {
    // draw a line through its listing on the table
    return 1;
}

inline int sapUnavailableOptionCount() {
    // substitute a clue or simply ignore the result
    return 2;
}

inline int sapPowersPartiallyDescribed() {
    // their powers are only partially described
    return 1;
}

inline int sapDmAssignsMajorPowers() {
    // the DM must at least decide the major powers
    return 1;
}

inline int sapLoreFoundByChance() {
    // discovery of such information is not by chance
    return 0;
}

inline int sapNemesisSometimesNeeded() {
    // a nemesis creature in some cases, with limits
    return 1;
}

inline int sapPowerTableCount() {
    // 5 tables list the powers and side effects
    return 5;
}

inline int sapHenchBehaviorCount() {
    // the item holder will do one of three things
    return 3;
}

inline int sapBehaviorEvilDestroysOrEscapes() {
    // an evil holder destroys or escapes once known
    return 1;
}

inline int sapBehaviorNeutralDominates() {
    // a neutral holder dominates the former employer
    return 1;
}

inline int sapBehaviorGoodDefectsWithItem() {
    // a good holder escapes with the item to a suzerain
    return 1;
}

inline int sapLoyaltyDropMinPct() {
    // the floor of the loyalty drop band
    return 10;
}

inline int sapLoyaltyDropMaxPct() {
    // the top of the 10-30 percent loyalty drop
    return 30;
}

inline int sapDestroyedBySingleMeans() {
    // each can only be destroyed by a single means
    return 1;
}

inline int sapDefaceSavePenalty() {
    // the deface save versus magic is at minus 5
    return -5;
}

inline int sapDefaceFailureIsDeath() {
    // a failed deface save equals death
    return 1;
}

inline int sapCorruptionTraitCount() {
    // reclusive, secretive, arrogant, greedy
    return 4;
}

inline int sapEffectsArePermanent() {
    // the effects are permanent, even past wishes
    return 1;
}

inline int sapDeityMayReverseSome() {
    // a creating or controlling deity may reverse some
    return 1;
}

}  // namespace rules