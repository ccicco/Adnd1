// R-refactor: split from specart_notes_on_artifacts_and_relics.h - definitions
#include "rules/dmg/specart_notes_on_artifacts_and_relics.h"

int Specart_notes_on_artifacts_and_relics::sapOneOfEachExists() {
    // only 1 of each may exist - a singular thing
    return 1;
}

int Specart_notes_on_artifacts_and_relics::sapListingCrossedWhenPlaced() {
    // draw a line through its listing on the table
    return 1;
}

int Specart_notes_on_artifacts_and_relics::sapUnavailableOptionCount() {
    // substitute a clue or simply ignore the result
    return 2;
}

int Specart_notes_on_artifacts_and_relics::sapPowersPartiallyDescribed() {
    // their powers are only partially described
    return 1;
}

int Specart_notes_on_artifacts_and_relics::sapDmAssignsMajorPowers() {
    // the DM must at least decide the major powers
    return 1;
}

int Specart_notes_on_artifacts_and_relics::sapLoreFoundByChance() {
    // discovery of such information is not by chance
    return 0;
}

int Specart_notes_on_artifacts_and_relics::sapNemesisSometimesNeeded() {
    // a nemesis creature in some cases, with limits
    return 1;
}

int Specart_notes_on_artifacts_and_relics::sapPowerTableCount() {
    // 5 tables list the powers and side effects
    return 5;
}

int Specart_notes_on_artifacts_and_relics::sapHenchBehaviorCount() {
    // the item holder will do one of three things
    return 3;
}

int Specart_notes_on_artifacts_and_relics::sapBehaviorEvilDestroysOrEscapes() {
    // an evil holder destroys or escapes once known
    return 1;
}

int Specart_notes_on_artifacts_and_relics::sapBehaviorNeutralDominates() {
    // a neutral holder dominates the former employer
    return 1;
}

int Specart_notes_on_artifacts_and_relics::sapBehaviorGoodDefectsWithItem() {
    // a good holder escapes with the item to a suzerain
    return 1;
}

int Specart_notes_on_artifacts_and_relics::sapLoyaltyDropMinPct() {
    // the floor of the loyalty drop band
    return 10;
}

int Specart_notes_on_artifacts_and_relics::sapLoyaltyDropMaxPct() {
    // the top of the 10-30 percent loyalty drop
    return 30;
}

int Specart_notes_on_artifacts_and_relics::sapDestroyedBySingleMeans() {
    // each can only be destroyed by a single means
    return 1;
}

int Specart_notes_on_artifacts_and_relics::sapDefaceSavePenalty() {
    // the deface save versus magic is at minus 5
    return -5;
}

int Specart_notes_on_artifacts_and_relics::sapDefaceFailureIsDeath() {
    // a failed deface save equals death
    return 1;
}

int Specart_notes_on_artifacts_and_relics::sapCorruptionTraitCount() {
    // reclusive, secretive, arrogant, greedy
    return 4;
}

int Specart_notes_on_artifacts_and_relics::sapEffectsArePermanent() {
    // the effects are permanent, even past wishes
    return 1;
}

int Specart_notes_on_artifacts_and_relics::sapDeityMayReverseSome() {
    // a creating or controlling deity may reverse some
    return 1;
}
