-- misc magic item def: helm_of_brilliance
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part12.h (R268)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "helm_of_brilliance",
  name = "Helm of Brilliance",
  rows = {
    { name = "Helm of Brilliance",
      set = "kMisc3", band = { 30, 30 }, xp = 2500, xp_hi = 0,
      gp = 60000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 12, round = 268 },
  },
  pins = {
    { name = "helmBrilCommandWordOnly", value = 1,
      comment = "functions only upon the utterance of a special "
      .. "command word" },
    { name = "helmBrilTrueNatureVisible", value = 1,
      comment = "when empowered the true nature of the helm is visible "
      .. "to all" },
    { name = "helmBrilArmorPlus", value = 2,
      comment = "the helm is armor of +2 value" },
    { name = "helmBrilDiamondCount", value = 10,
      comment = "set with 10 diamonds of large size" },
    { name = "helmBrilRubyCount", value = 20,
      comment = "20 rubies" },
    { name = "helmBrilFireOpalCount", value = 30,
      comment = "30 fire opals" },
    { name = "helmBrilOpalCount", value = 40,
      comment = "40 opals" },
    { name = "helmBrilScintillatesInBrightLight", value = 1,
      comment = "struck by bright light it scintillates and sends "
      .. "reflective rays from the crown-like spikes set with "
      .. "gems" },
    { name = "helmBrilJewelUseSegments", value = 1,
      comment = "each gem performs its spell-like power in but 1 "
      .. "segment" },
    { name = "helmBrilJewelUsableOnce", value = 1,
      comment = "each gem is usable only once" },
    { name = "helmBrilUsesPerRound", value = 1,
      comment = "the helm may be thus used once per round" },
    { name = "helmBrilSpellLevelDoublingFactor", value = 2,
      comment = "the level of the spell is doubled for range, duration "
      .. "and such considerations" },
    { name = "helmBrilUndeadGlowRangeFeet", value = 30,
      comment = "glows with a bluish light when undead are within 30 "
      .. "feet" },
    { name = "helmBrilUndeadPainDmgMin", value = 1,
      comment = "the light causes pain and damage to undead" },
    { name = "helmBrilUndeadPainDmgMax", value = 6,
      comment = "1-6 points of damage" },
    { name = "helmBrilUndeadExemptKinds", value = 2,
      comment = "save skeletons and zombies take neither the pain nor "
      .. "the damage" },
    { name = "helmBrilFlameSwordEffectRounds", value = 1,
      comment = "1 round of time is required to effect this fire" },
    { name = "helmBrilFlameSwordAdditional", value = 1,
      comment = "the sword of flame is additional to the other special "
      .. "properties of the sword, if any" },
    { name = "helmBrilProduceFlameDruidLevel", value = 5,
      comment = "the wearer may produce flame just as if a 5th level "
      .. "druid" },
    { name = "helmBrilFireResistRingStrength", value = 2,
      comment = "protected just as if a double strength fire "
      .. "resistance ring were worn" },
    { name = "helmBrilFireResistAugmentable", value = 0,
      comment = "this protection cannot be augmented by further "
      .. "magical means" },
    { name = "helmBrilPowderOnExpenditure", value = 1,
      comment = "once all jewels lose their magic the helm loses its "
      .. "powers and the gems turn to worthless powder" },
    { name = "helmBrilJewelRemovalDestroys", value = 1,
      comment = "removing a jewel destroys the gem" },
    { name = "helmBrilJewelRemagickable", value = 0,
      comment = "the gems may not be re-magicked" },
    { name = "helmBrilRetrySaveWithoutMagic", value = 1,
      comment = "a failed save versus a magical fire attack demands "
      .. "another saving throw for the helmet without magical "
      .. "additions" },
    { name = "helmBrilOverloadDetonatesRemaining", value = 1,
      comment = "if the helmet save fails the remaining gems all "
      .. "overload and detonate" },
    { name = "helmBrilOverloadEffectsInMultiple", value = 1,
      comment = "the detonation causes in multiple whatever effects "
      .. "the gems would normally have" },
    { name = "helmBrilJewelRowCount", value = 4,
      comment = "the restored jewel functions table rows" },
  },
  tables = {
    { name = "helmBrilJewelGemCount",
      comment = "the stones set per gem row; i clamps",
      clamp_hi = 3,
      values = {
        10, 20, 30, 40,
      } },
    { name = "helmBrilJewelSpellLevel",
      comment = "the restored spell levels: 7th, 5th, 3rd, 1st; i clamps",
      clamp_hi = 3,
      values = {
        7, 5, 3, 1,
      } },
    { name = "helmBrilJewelCasterKind",
      comment = "0 illusionist, 1 druid, 2 magic-user, 3 cleric; i "
      .. "clamps",
      clamp_hi = 3,
      values = {
        0, 1, 2, 3,
      } },
    { name = "helmBrilJewelFunctionKind",
      comment = "0 prismatic spray, 1 wall of fire, 2 fireball, 3 light; "
      .. "i clamps",
      clamp_hi = 3,
      values = {
        0, 1, 2, 3,
      } },
  },
}
