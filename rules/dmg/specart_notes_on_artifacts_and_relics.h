// ====================================================================
// Adnd1 - rules/dmg/specart_notes_on_artifacts_and_relics.h
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

// R-refactor: namespace rules -> class Specart_notes_on_artifacts_and_relics (instance methods)
class Specart_notes_on_artifacts_and_relics {
public:
    int sapOneOfEachExists();
    int sapListingCrossedWhenPlaced();
    int sapUnavailableOptionCount();
    int sapPowersPartiallyDescribed();
    int sapDmAssignsMajorPowers();
    int sapLoreFoundByChance();
    int sapNemesisSometimesNeeded();
    int sapPowerTableCount();
    int sapHenchBehaviorCount();
    int sapBehaviorEvilDestroysOrEscapes();
    int sapBehaviorNeutralDominates();
    int sapBehaviorGoodDefectsWithItem();
    int sapLoyaltyDropMinPct();
    int sapLoyaltyDropMaxPct();
    int sapDestroyedBySingleMeans();
    int sapDefaceSavePenalty();
    int sapDefaceFailureIsDeath();
    int sapCorruptionTraitCount();
    int sapEffectsArePermanent();
    int sapDeityMayReverseSome();
};
