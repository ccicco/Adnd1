-- misc magic item def: specart_prose
-- The R1062 special-artifact family de-wire: the
-- retired static arrays of rules/dmg/specart.h and
-- rules/dmg/specart_prose_part2.h ride this def
-- (rowless: flat int columns only, no rows). The
-- accessors keep their clamps and comments; the
-- r280-r29x pin fragments and the headers are the
-- print-fidelity record. DO NOT hand-edit this
-- file; tools/r1062_splice.py is the only writer.
return {
  key = "specart_prose",
  name = "DMG special artifact prose columns",
  sources = {
    { part = 0, round = 1062 },
  },
  pins = {
    { name = "specart_proseTableCount",
      value = 49,
      comment = "the family columns" },
  },
  tables = {
    { name = "axe_power_count",
      values = {
        2, 1, 1, 1, 1, 1,
      },
      comment = "from sapAxePowerCount" },
    { name = "hut_move_inches",
      values = {
        48, 36, 12,
      },
      comment = "from sapHutMoveInches" },
    { name = "hut_power_count",
      values = {
        4, 2, 1, 1, 1, 1,
      },
      comment = "from sapHutPowerCount" },
    { name = "codex_power_count",
      values = {
        4, 4, 2, 2, 2, 2,
      },
      comment = "from sapCodexPowerCount" },
    { name = "crown_align_band_lo",
      values = {
        1, 7, 15,
      },
      comment = "from sapCrownAlignBandLo" },
    { name = "crown_align_band_hi",
      values = {
        6, 14, 20,
      },
      comment = "from sapCrownAlignBandHi" },
    { name = "crown_worn_power_count",
      values = {
        2, 1, 1,
      },
      comment = "from sapCrownWornPowerCount" },
    { name = "crown_set2nd_power_count",
      values = {
        1, 1,
      },
      comment = "from sapCrownSet2ndPowerCount" },
    { name = "crown_set3rd_power_count",
      values = {
        1, 1, 1, 1, 1,
      },
      comment = "from sapCrownSet3rdPowerCount" },
    { name = "crystal_power_count",
      values = {
        4, 2, 1, 1, 1, 1,
      },
      comment = "from sapCrystalPowerCount" },
    { name = "cup_power_count",
      values = {
        4, 0, 1,
      },
      comment = "from sapCupPowerCount" },
    { name = "talisman_power_count",
      values = {
        0, 2, 0, 1,
      },
      comment = "from sapTalismanPowerCount" },
    { name = "cup_talisman_both_power_count",
      values = {
        1, 1,
      },
      comment = "from sapCupTalismanBothPowerCount" },
    { name = "cup_talisman_potion_band_lo",
      values = {
        1, 6, 11, 16, 18, 20,
      },
      comment = "from sapCupTalismanPotionBandLo" },
    { name = "cup_talisman_potion_band_hi",
      values = {
        5, 10, 15, 17, 19, 20,
      },
      comment = "from sapCupTalismanPotionBandHi" },
    { name = "eye_power_count",
      values = {
        2, 2, 0, 1, 1,
      },
      comment = "from sapEyePowerCount" },
    { name = "hand_power_count",
      values = {
        10, 5, 2, 2, 2, 1,
      },
      comment = "from sapHandPowerCount" },
    { name = "organ_power_count",
      values = {
        7, 7, 3, 7, 7, 3,
      },
      comment = "from sapOrganPowerCount" },
    { name = "horn_blast_power_table",
      values = {
        1, 2, 5,
      },
      comment = "from sapHornBlastPowerTable" },
    { name = "horn_blast_effect_table",
      values = {
        3, 6, 4,
      },
      comment = "from sapHornBlastEffectTable" },
    { name = "coat_power_count",
      values = {
        3, 2, 2, 1, 1, 1,
      },
      comment = "from sapCoatPowerCount" },
    { name = "flask_power_count",
      values = {
        3, 0, 1, 0, 1, 1,
      },
      comment = "from sapFlaskPowerCount" },
    { name = "jacinth_power_count",
      values = {
        2, 2, 1, 1, 1, 1,
      },
      comment = "from sapJacinthPowerCount" },
    { name = "mask_power_count",
      values = {
        2, 1, 0, 0, 0, 1,
      },
      comment = "from sapMaskPowerCount" },
    { name = "quill_power_count",
      values = {
        2, 0, 1, 1, 0, 1,
      },
      comment = "from sapQuillPowerCount" },
    { name = "mace_power_count",
      values = {
        3, 2, 0, 0, 0, 1,
      },
      comment = "from sapMacePowerCount" },
    { name = "machine_power_count",
      values = {
        15, 15, 10, 10, 15, 5,
      },
      comment = "from sapMachinePowerCount" },
    { name = "servant_power_count",
      values = {
        6, 6, 1, 2, 0, 2,
      },
      comment = "from sapServantPowerCount" },
    { name = "orb_hatchling_power_count",
      values = {
        3, 0, 0, 0, 0, 0,
      },
      comment = "from sapOrbHatchlingPowerCount" },
    { name = "orb_wyrmkin_power_count",
      values = {
        2, 1, 0, 0, 0, 0,
      },
      comment = "from sapOrbWyrmkinPowerCount" },
    { name = "orb_dragonette_power_count",
      values = {
        3, 1, 1, 0, 0, 0,
      },
      comment = "from sapOrbDragonettePowerCount" },
    { name = "orb_dragon_power_count",
      values = {
        4, 1, 1, 0, 0, 0,
      },
      comment = "from sapOrbDragonPowerCount" },
    { name = "orb_great_serpent_power_count",
      values = {
        3, 2, 1, 0, 0, 1,
      },
      comment = "from sapOrbGreatSerpentPowerCount" },
    { name = "orb_firedrake_power_count",
      values = {
        3, 3, 2, 0, 0, 1,
      },
      comment = "from sapOrbFiredrakePowerCount" },
    { name = "orb_elder_wyrm_power_count",
      values = {
        4, 3, 2, 1, 1, 1,
      },
      comment = "from sapOrbElderWyrmPowerCount" },
    { name = "orb_eternal_power_count",
      values = {
        4, 3, 2, 1, 2, 1,
      },
      comment = "from sapOrbEternalPowerCount" },
    { name = "orb_might_power_count",
      values = {
        2, 0, 1, 0, 0, 0,
      },
      comment = "from sapOrbMightPowerCount" },
    { name = "nightingale_power_count",
      values = {
        4, 0, 1, 1, 1, 1,
      },
      comment = "from sapNightingalePowerCount" },
    { name = "recorder_power_count",
      values = {
        5, 2, 1, 1, 1, 1,
      },
      comment = "from sapRecorderPowerCount" },
    { name = "gaxx_power_count",
      values = {
        3, 2, 1, 1, 1, 1,
      },
      comment = "from sapGaxxPowerCount" },
    { name = "rod_joint_table",
      values = {
        3, 1, 1, 4, 2, 6,
      },
      comment = "from sapRodJointTable" },
    { name = "rod_joint_use_count",
      values = {
        1, 1, 1, 1, 1, 1,
      },
      comment = "from sapRodJointUseCount" },
    { name = "rod_complete_table_use",
      values = {
        1, 1, 2, 1, 2, 0,
      },
      comment = "from sapRodCompleteTableUse" },
    { name = "sceptre_table_use",
      values = {
        1, 1, 0, 0, 0, 1,
      },
      comment = "from sapSceptreTableUse" },
    { name = "kas_table_use",
      values = {
        5, 2, 1, 2, 2, 1,
      },
      comment = "from sapKasTableUse" },
    { name = "tooth_table_use",
      values = {
        21, 4, 4, 1, 0, 2,
      },
      comment = "from sapToothTableUse" },
    { name = "tooth_set_right_use",
      values = {
        0, 0, 4, 2, 0, 2,
      },
      comment = "from sapToothSetRightUse" },
    { name = "throne_table_use",
      values = {
        3, 3, 2, 2, 2, 2,
      },
      comment = "from sapThroneTableUse" },
    { name = "wand_table_use",
      values = {
        4, 2, 2, 1, 0, 1,
      },
      comment = "from sapWandTableUse" },
  },
}
