// R-refactor: re-split from miscmagic_alchemy_jug_to_wings_of_flying.cpp - definitions
#include "rules/dmg/misc_magic/miscmagic_helm_of_brilliance_to_horn_of_bubbles.h"

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilCommandWordOnly() {
    // functions only upon the utterance of a
    // special command word
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilTrueNatureVisible() {
    // when empowered the true nature of the helm
    // is visible to all
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilArmorPlus() {
    // the helm is armor of +2 value
    return 2;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilDiamondCount() {
    // set with 10 diamonds of large size
    return 10;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilRubyCount() {
    // 20 rubies
    return 20;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilFireOpalCount() {
    // 30 fire opals
    return 30;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilOpalCount() {
    // 40 opals
    return 40;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilScintillatesInBrightLight() {
    // struck by bright light it scintillates and
    // sends reflective rays from the crown-like
    // spikes set with gems
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilJewelUseSegments() {
    // each gem performs its spell-like power in
    // but 1 segment
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilJewelUsableOnce() {
    // each gem is usable only once
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilUsesPerRound() {
    // the helm may be thus used once per round
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilSpellLevelDoublingFactor() {
    // the level of the spell is doubled for range,
    // duration and such considerations
    return 2;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilUndeadGlowRangeFeet() {
    // glows with a bluish light when undead are
    // within 30 feet
    return 30;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilUndeadPainDmgMin() {
    // the light causes pain and damage to undead
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilUndeadPainDmgMax() {
    // 1-6 points of damage
    return 6;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilUndeadExemptKinds() {
    // save skeletons and zombies take neither
    // the pain nor the damage
    return 2;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilFlameSwordEffectRounds() {
    // 1 round of time is required to effect
    // this fire
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilFlameSwordAdditional() {
    // the sword of flame is additional to the
    // other special properties of the sword,
    // if any
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilProduceFlameDruidLevel() {
    // the wearer may produce flame just as if
    // a 5th level druid
    return 5;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilFireResistRingStrength() {
    // protected just as if a double strength
    // fire resistance ring were worn
    return 2;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilFireResistAugmentable() {
    // this protection cannot be augmented by
    // further magical means
    return 0;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilPowderOnExpenditure() {
    // once all jewels lose their magic the helm
    // loses its powers and the gems turn to
    // worthless powder
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilJewelRemovalDestroys() {
    // removing a jewel destroys the gem
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilJewelRemagickable() {
    // the gems may not be re-magicked
    return 0;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilRetrySaveWithoutMagic() {
    // a failed save versus a magical fire attack
    // demands another saving throw for the
    // helmet without magical additions
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilOverloadDetonatesRemaining() {
    // if the helmet save fails the remaining
    // gems all overload and detonate
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilOverloadEffectsInMultiple() {
    // the detonation causes in multiple
    // whatever effects the gems would
    // normally have
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilJewelRowCount() {
    // the restored jewel functions table rows
    return 4;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilJewelGemCount(int i) {
    // the stones set per gem row; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        10, 20, 30, 40,
    };
    return t[i];
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilJewelSpellLevel(int i) {
    // the restored spell levels: 7th, 5th,
    // 3rd, 1st; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        7, 5, 3, 1,
    };
    return t[i];
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilJewelCasterKind(int i) {
    // 0 illusionist, 1 druid, 2 magic-user,
    // 3 cleric; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 2, 3,
    };
    return t[i];
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmBrilJewelFunctionKind(int i) {
    // 0 prismatic spray, 1 wall of fire,
    // 2 fireball, 3 light; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 2, 3,
    };
    return t[i];
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmComprStrangeTonguesPct() {
    // understand 90 percent of strange tongues
    // and writings
    return 90;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmComprMagicalWritingsPct() {
    // 80 percent of magical writings
    return 80;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmComprAllOrNone() {
    // the figures apply to whether all or none
    // of the tongue or inscription is
    // understandable
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmComprImpliesSpellUse() {
    // understanding does not necessarily imply
    // spell use
    return 0;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmComprHelmetOfAcValue() {
    // equal to a normal helmet of the type
    // accompanying armor class 5
    return 5;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmOppAlignIndeterminateDweomer() {
    // by test it radiates an indeterminate
    // dweomer
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmOppAlignCurseOnDonning() {
    // once placed upon the head the curse
    // immediately takes place
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmOppAlignAbsoluteKinds() {
    // neutral goes to some absolute
    // commitment: LE, LG, CE or CG
    return 4;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmOppAlignAlterationDesired() {
    // the alteration, once effected, is
    // desired by the individual the magic
    // changed
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmOppAlignRestoreSpellKinds() {
    // only a wish, or alter reality, can
    // restore the former alignment
    return 2;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmOppAlignSelfRestoreAttempts() {
    // the affected individual will make no
    // attempt to return to the former
    // alignment
    return 0;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmOppAlignPaladinQuestAndAtone() {
    // a paladin must undergo a special quest
    // and atone for the curse to be
    // obliterated
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmOppAlignPowersAfterFunctioning() {
    // once functioned the helm loses all of
    // its magical properties
    return 0;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTelepathyRangeInches() {
    // the thoughts of creatures within a
    // 6 inch range
    return 6;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTelepathyStoneBarrierFeet() {
    // no more than 3 feet of solid stone
    // between the wearer and the creatures
    return 3;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTelepathyIronBarrierQuarterFeet() {
    // a quarter foot of iron
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTelepathyLeadGoldSheetBlocks() {
    // any solid sheeting of lead or gold
    // blocks the pick-up entirely
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTelepathyDirectional() {
    // the thought pick-up is directional
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTelepathyConsciousEffort() {
    // conscious effort must be made to pick
    // up thoughts
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTelepathySuggestPctPer2IntAbove() {
    // for every 2 points of intelligence
    // greater than the subject the wearer is
    // 5 percent more likely to implant
    return 5;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTelepathySuggestPctPer1IntBelow() {
    // for every 1 point lower the probability
    // decreases by 5 percent
    return 5;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTelepathySavePenaltyPer2IntBelow() {
    // the subject saves versus magic with a
    // minus 1 for every 2 points of
    // intelligence lower than the telepathist
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTelepathySaveBonusPer1IntAbove() {
    // the subject saves with a plus 1 for
    // every 1 point of intelligence higher
    // than the wearer of the helm
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTelepathyEqualIntSaveAdjustment() {
    // if intelligence is equal no adjustment
    // is made
    return 0;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTelepathyPsionicAttackBonus() {
    // a plus 4 with respect to psionic related
    // attacks
    return 4;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTelepathyPsionicStrengthBonus() {
    // increases total psionic strength by
    // 40 points
    return 40;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTeleportPerDay() {
    // the wearer may teleport once per day,
    // exactly as if a magic-user: destination
    // known, a risk involved
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTeleportMuRefreshRepeats() {
    // a magic-user may memorize the spell and
    // use the helm to refresh memory,
    // repeating the spell up to 3 times
    return 3;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTeleportMuStillPersonalAfterRefresh() {
    // and still be able to personally
    // teleport by means of the helm
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTeleportMuUncastPersonalCount() {
    // while the spell is retained uncast the
    // magic-user can personally teleport up
    // to 6 times before the memory is lost
    return 6;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmTeleportUsageAfterMemoryLost() {
    // even then a usage of the helm remains
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmUnderwaterSeeAndBreathe() {
    // the possessor is able to both see and
    // breathe under water
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmUnderwaterLensCompartments() {
    // small lenses drawn across the device
    // from compartments on either side
    return 2;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmUnderwaterVisionFactor() {
    // see 5 times farther than normal water
    // and light conditions allow for normal
    // human vision
    return 5;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmUnderwaterObstructionsBlock() {
    // weeds, obstructions and such block
    // vision in the usual manner
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHelmUnderwaterAirGlobeUntilRepeat() {
    // the command word creates a globe of air
    // around the head, maintained until the
    // word is again spoken
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingConeLengthInches() {
    // a cone of sound 12 inches long
    return 12;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingConeBaseWidthInches() {
    // 3 inches wide at the base
    return 3;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingSaveStunRounds() {
    // those saving versus magic are stunned
    // for 1 round
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingSaveDeafRounds() {
    // those saving are deafened for 2
    return 2;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingFailDmgMin() {
    // those failing the save sustain damage
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingFailDmgMax() {
    // 1-10 hit points of damage
    return 10;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingFailStunRounds() {
    // those failing are stunned for 2 rounds
    return 2;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingFailDeafRounds() {
    // those failing are deafened for 4
    return 4;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingPulseWidthFeet() {
    // a wave of ultrasonic sound, a 1 foot
    // wide pulse
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingPulseLengthInches() {
    // the pulse is 10 inches long
    return 10;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingCatapultMultiplier() {
    // the weakening of metal, stone and wood
    // equals 3 times a large catapult
    // missile hit
    return 3;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingCatapultHitDamage() {
    // the large catapult missile hit damage
    // (derived: 18 structural at triple)
    return 6;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingStructuralPoints() {
    // 18 structural points, sufficient to
    // smash a drawbridge or flatten a normal
    // cottage
    return 18;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingExplodePctPerExtraUse() {
    // winded magically more than once per
    // day: a 10 percent cumulative chance to
    // explode itself
    return 10;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingExplodeDmgMin() {
    // the explosion inflicts 5-50 hit points
    // of damage on the person sounding it
    return 5;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingExplodeDmgMax() {
    // the 5-50 upper edge
    return 50;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingCharges() {
    // there are no charges upon a horn
    return 0;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingShiverPctPerUse() {
    // each magical use: a 2 percent
    // cumulative chance of shivering itself
    return 2;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBlastingShiverWielderDamage() {
    // a shiver inflicts no damage on the
    // character blowing it
    return 0;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBubblesBlindRoundsMin() {
    // the bubbles surround and blind the
    // individual who blew the horn
    return 2;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBubblesBlindRoundsMax() {
    // blinded for 2-20 rounds
    return 20;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBubblesOnlyWhenSlayerSeeks() {
    // the bubbles only appear in the presence
    // of a creature actively seeking to slay
    // the character who winded the horn
    return 1;
}

int Miscmagic_helm_of_brilliance_to_horn_of_bubbles::mmpHornBubblesAppearanceMayDelay() {
    // the appearance might be delayed for a
    // very short or extremely lengthy period
    return 1;
}
