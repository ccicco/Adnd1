// ====================================================================
// Adnd1 - rules/miscprose12.h
// R268: the III.E misc magic explanation prose part 12
// (DMG p.137-139) - Helm of Brilliance through the Horn
// of Bubbles, part2 lines 532-579 (global =
// 11065 + part2 line). ONE page header inside the slice
// (541, the TREASURE page) falls between the jewel
// functions table and the Each gem paragraph of the
// Brilliance item. The jewel functions table: the book
// upload flattens the four gem rows into the Diamond
// cell (the Ruby, Fire Opal and Opal cells empty) -
// the four-row table restored from the compilation
// (the R175 precedent): Diamond prismatic spray (7th
// illusionist), Ruby wall of fire (5th druid), Fire
// Opal fireball (3rd magic-user), Opal light (1st
// cleric). 91 accessors: 87 scalars + 4 array walkers
// (the jewel functions table), no name collisions with
// miscprose1.h through miscprose11.h.
// The slice pins kMisc3 rows 10-17, no class marks and
// no asterisks ride these rows. Pure data + helpers,
// header-only (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpHelmBrilCommandWordOnly() {
    // functions only upon the utterance of a
    // special command word
    return 1;
}

inline int mmpHelmBrilTrueNatureVisible() {
    // when empowered the true nature of the helm
    // is visible to all
    return 1;
}

inline int mmpHelmBrilArmorPlus() {
    // the helm is armor of +2 value
    return 2;
}

inline int mmpHelmBrilDiamondCount() {
    // set with 10 diamonds of large size
    return 10;
}

inline int mmpHelmBrilRubyCount() {
    // 20 rubies
    return 20;
}

inline int mmpHelmBrilFireOpalCount() {
    // 30 fire opals
    return 30;
}

inline int mmpHelmBrilOpalCount() {
    // 40 opals
    return 40;
}

inline int mmpHelmBrilScintillatesInBrightLight() {
    // struck by bright light it scintillates and
    // sends reflective rays from the crown-like
    // spikes set with gems
    return 1;
}

inline int mmpHelmBrilJewelUseSegments() {
    // each gem performs its spell-like power in
    // but 1 segment
    return 1;
}

inline int mmpHelmBrilJewelUsableOnce() {
    // each gem is usable only once
    return 1;
}

inline int mmpHelmBrilUsesPerRound() {
    // the helm may be thus used once per round
    return 1;
}

inline int mmpHelmBrilSpellLevelDoublingFactor() {
    // the level of the spell is doubled for range,
    // duration and such considerations
    return 2;
}

inline int mmpHelmBrilUndeadGlowRangeFeet() {
    // glows with a bluish light when undead are
    // within 30 feet
    return 30;
}

inline int mmpHelmBrilUndeadPainDmgMin() {
    // the light causes pain and damage to undead
    return 1;
}

inline int mmpHelmBrilUndeadPainDmgMax() {
    // 1-6 points of damage
    return 6;
}

inline int mmpHelmBrilUndeadExemptKinds() {
    // save skeletons and zombies take neither
    // the pain nor the damage
    return 2;
}

inline int mmpHelmBrilFlameSwordEffectRounds() {
    // 1 round of time is required to effect
    // this fire
    return 1;
}

inline int mmpHelmBrilFlameSwordAdditional() {
    // the sword of flame is additional to the
    // other special properties of the sword,
    // if any
    return 1;
}

inline int mmpHelmBrilProduceFlameDruidLevel() {
    // the wearer may produce flame just as if
    // a 5th level druid
    return 5;
}

inline int mmpHelmBrilFireResistRingStrength() {
    // protected just as if a double strength
    // fire resistance ring were worn
    return 2;
}

inline int mmpHelmBrilFireResistAugmentable() {
    // this protection cannot be augmented by
    // further magical means
    return 0;
}

inline int mmpHelmBrilPowderOnExpenditure() {
    // once all jewels lose their magic the helm
    // loses its powers and the gems turn to
    // worthless powder
    return 1;
}

inline int mmpHelmBrilJewelRemovalDestroys() {
    // removing a jewel destroys the gem
    return 1;
}

inline int mmpHelmBrilJewelRemagickable() {
    // the gems may not be re-magicked
    return 0;
}

inline int mmpHelmBrilRetrySaveWithoutMagic() {
    // a failed save versus a magical fire attack
    // demands another saving throw for the
    // helmet without magical additions
    return 1;
}

inline int mmpHelmBrilOverloadDetonatesRemaining() {
    // if the helmet save fails the remaining
    // gems all overload and detonate
    return 1;
}

inline int mmpHelmBrilOverloadEffectsInMultiple() {
    // the detonation causes in multiple
    // whatever effects the gems would
    // normally have
    return 1;
}

inline int mmpHelmBrilJewelRowCount() {
    // the restored jewel functions table rows
    return 4;
}

inline int mmpHelmBrilJewelGemCount(int i) {
    // the stones set per gem row; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        10, 20, 30, 40,
    };
    return t[i];
}

inline int mmpHelmBrilJewelSpellLevel(int i) {
    // the restored spell levels: 7th, 5th,
    // 3rd, 1st; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        7, 5, 3, 1,
    };
    return t[i];
}

inline int mmpHelmBrilJewelCasterKind(int i) {
    // 0 illusionist, 1 druid, 2 magic-user,
    // 3 cleric; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 2, 3,
    };
    return t[i];
}

inline int mmpHelmBrilJewelFunctionKind(int i) {
    // 0 prismatic spray, 1 wall of fire,
    // 2 fireball, 3 light; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 2, 3,
    };
    return t[i];
}

inline int mmpHelmComprStrangeTonguesPct() {
    // understand 90 percent of strange tongues
    // and writings
    return 90;
}

inline int mmpHelmComprMagicalWritingsPct() {
    // 80 percent of magical writings
    return 80;
}

inline int mmpHelmComprAllOrNone() {
    // the figures apply to whether all or none
    // of the tongue or inscription is
    // understandable
    return 1;
}

inline int mmpHelmComprImpliesSpellUse() {
    // understanding does not necessarily imply
    // spell use
    return 0;
}

inline int mmpHelmComprHelmetOfAcValue() {
    // equal to a normal helmet of the type
    // accompanying armor class 5
    return 5;
}

inline int mmpHelmOppAlignIndeterminateDweomer() {
    // by test it radiates an indeterminate
    // dweomer
    return 1;
}

inline int mmpHelmOppAlignCurseOnDonning() {
    // once placed upon the head the curse
    // immediately takes place
    return 1;
}

inline int mmpHelmOppAlignAbsoluteKinds() {
    // neutral goes to some absolute
    // commitment: LE, LG, CE or CG
    return 4;
}

inline int mmpHelmOppAlignAlterationDesired() {
    // the alteration, once effected, is
    // desired by the individual the magic
    // changed
    return 1;
}

inline int mmpHelmOppAlignRestoreSpellKinds() {
    // only a wish, or alter reality, can
    // restore the former alignment
    return 2;
}

inline int mmpHelmOppAlignSelfRestoreAttempts() {
    // the affected individual will make no
    // attempt to return to the former
    // alignment
    return 0;
}

inline int mmpHelmOppAlignPaladinQuestAndAtone() {
    // a paladin must undergo a special quest
    // and atone for the curse to be
    // obliterated
    return 1;
}

inline int mmpHelmOppAlignPowersAfterFunctioning() {
    // once functioned the helm loses all of
    // its magical properties
    return 0;
}

inline int mmpHelmTelepathyRangeInches() {
    // the thoughts of creatures within a
    // 6 inch range
    return 6;
}

inline int mmpHelmTelepathyStoneBarrierFeet() {
    // no more than 3 feet of solid stone
    // between the wearer and the creatures
    return 3;
}

inline int mmpHelmTelepathyIronBarrierQuarterFeet() {
    // a quarter foot of iron
    return 1;
}

inline int mmpHelmTelepathyLeadGoldSheetBlocks() {
    // any solid sheeting of lead or gold
    // blocks the pick-up entirely
    return 1;
}

inline int mmpHelmTelepathyDirectional() {
    // the thought pick-up is directional
    return 1;
}

inline int mmpHelmTelepathyConsciousEffort() {
    // conscious effort must be made to pick
    // up thoughts
    return 1;
}

inline int mmpHelmTelepathySuggestPctPer2IntAbove() {
    // for every 2 points of intelligence
    // greater than the subject the wearer is
    // 5 percent more likely to implant
    return 5;
}

inline int mmpHelmTelepathySuggestPctPer1IntBelow() {
    // for every 1 point lower the probability
    // decreases by 5 percent
    return 5;
}

inline int mmpHelmTelepathySavePenaltyPer2IntBelow() {
    // the subject saves versus magic with a
    // minus 1 for every 2 points of
    // intelligence lower than the telepathist
    return 1;
}

inline int mmpHelmTelepathySaveBonusPer1IntAbove() {
    // the subject saves with a plus 1 for
    // every 1 point of intelligence higher
    // than the wearer of the helm
    return 1;
}

inline int mmpHelmTelepathyEqualIntSaveAdjustment() {
    // if intelligence is equal no adjustment
    // is made
    return 0;
}

inline int mmpHelmTelepathyPsionicAttackBonus() {
    // a plus 4 with respect to psionic related
    // attacks
    return 4;
}

inline int mmpHelmTelepathyPsionicStrengthBonus() {
    // increases total psionic strength by
    // 40 points
    return 40;
}

inline int mmpHelmTeleportPerDay() {
    // the wearer may teleport once per day,
    // exactly as if a magic-user: destination
    // known, a risk involved
    return 1;
}

inline int mmpHelmTeleportMuRefreshRepeats() {
    // a magic-user may memorize the spell and
    // use the helm to refresh memory,
    // repeating the spell up to 3 times
    return 3;
}

inline int mmpHelmTeleportMuStillPersonalAfterRefresh() {
    // and still be able to personally
    // teleport by means of the helm
    return 1;
}

inline int mmpHelmTeleportMuUncastPersonalCount() {
    // while the spell is retained uncast the
    // magic-user can personally teleport up
    // to 6 times before the memory is lost
    return 6;
}

inline int mmpHelmTeleportUsageAfterMemoryLost() {
    // even then a usage of the helm remains
    return 1;
}

inline int mmpHelmUnderwaterSeeAndBreathe() {
    // the possessor is able to both see and
    // breathe under water
    return 1;
}

inline int mmpHelmUnderwaterLensCompartments() {
    // small lenses drawn across the device
    // from compartments on either side
    return 2;
}

inline int mmpHelmUnderwaterVisionFactor() {
    // see 5 times farther than normal water
    // and light conditions allow for normal
    // human vision
    return 5;
}

inline int mmpHelmUnderwaterObstructionsBlock() {
    // weeds, obstructions and such block
    // vision in the usual manner
    return 1;
}

inline int mmpHelmUnderwaterAirGlobeUntilRepeat() {
    // the command word creates a globe of air
    // around the head, maintained until the
    // word is again spoken
    return 1;
}

inline int mmpHornBlastingConeLengthInches() {
    // a cone of sound 12 inches long
    return 12;
}

inline int mmpHornBlastingConeBaseWidthInches() {
    // 3 inches wide at the base
    return 3;
}

inline int mmpHornBlastingSaveStunRounds() {
    // those saving versus magic are stunned
    // for 1 round
    return 1;
}

inline int mmpHornBlastingSaveDeafRounds() {
    // those saving are deafened for 2
    return 2;
}

inline int mmpHornBlastingFailDmgMin() {
    // those failing the save sustain damage
    return 1;
}

inline int mmpHornBlastingFailDmgMax() {
    // 1-10 hit points of damage
    return 10;
}

inline int mmpHornBlastingFailStunRounds() {
    // those failing are stunned for 2 rounds
    return 2;
}

inline int mmpHornBlastingFailDeafRounds() {
    // those failing are deafened for 4
    return 4;
}

inline int mmpHornBlastingPulseWidthFeet() {
    // a wave of ultrasonic sound, a 1 foot
    // wide pulse
    return 1;
}

inline int mmpHornBlastingPulseLengthInches() {
    // the pulse is 10 inches long
    return 10;
}

inline int mmpHornBlastingCatapultMultiplier() {
    // the weakening of metal, stone and wood
    // equals 3 times a large catapult
    // missile hit
    return 3;
}

inline int mmpHornBlastingCatapultHitDamage() {
    // the large catapult missile hit damage
    // (derived: 18 structural at triple)
    return 6;
}

inline int mmpHornBlastingStructuralPoints() {
    // 18 structural points, sufficient to
    // smash a drawbridge or flatten a normal
    // cottage
    return 18;
}

inline int mmpHornBlastingExplodePctPerExtraUse() {
    // winded magically more than once per
    // day: a 10 percent cumulative chance to
    // explode itself
    return 10;
}

inline int mmpHornBlastingExplodeDmgMin() {
    // the explosion inflicts 5-50 hit points
    // of damage on the person sounding it
    return 5;
}

inline int mmpHornBlastingExplodeDmgMax() {
    // the 5-50 upper edge
    return 50;
}

inline int mmpHornBlastingCharges() {
    // there are no charges upon a horn
    return 0;
}

inline int mmpHornBlastingShiverPctPerUse() {
    // each magical use: a 2 percent
    // cumulative chance of shivering itself
    return 2;
}

inline int mmpHornBlastingShiverWielderDamage() {
    // a shiver inflicts no damage on the
    // character blowing it
    return 0;
}

inline int mmpHornBubblesBlindRoundsMin() {
    // the bubbles surround and blind the
    // individual who blew the horn
    return 2;
}

inline int mmpHornBubblesBlindRoundsMax() {
    // blinded for 2-20 rounds
    return 20;
}

inline int mmpHornBubblesOnlyWhenSlayerSeeks() {
    // the bubbles only appear in the presence
    // of a creature actively seeking to slay
    // the character who winded the horn
    return 1;
}

inline int mmpHornBubblesAppearanceMayDelay() {
    // the appearance might be delayed for a
    // very short or extremely lengthy period
    return 1;
}

}  // namespace rules