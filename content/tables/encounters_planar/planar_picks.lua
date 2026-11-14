-- encounter table def: planar_picks
-- The R65 planar family (R1036 de-wire): the seven demon/devil/titan pick-sets
-- (DMG Appendix C Premium reprint p.181, OCR-verified).
-- extracted verbatim from the retired arrays of dm/encounters.cpp; a set resolves on the second percentile modulo the set size (the R52 style). The demon-prince and arch-devil pools stay engine-side (the R52 record, shared with the dungeon family).
-- DO NOT hand-edit: tools/r1036_splice.py is the only writer.

return {
  key = "planar_picks",
  demon_minor = { "type_i_vrock", "type_ii_hezrou", "type_iii_glabrezu", "type_iv_demon_bilwhr", "type_iv_demon_johud", "type_iv_demon_nalfeshnee" },
  demon_major = { "type_v_demon_aishapra", "type_v_demon_kevokulli", "type_v_demon_marilith", "type_v_demon_rehnaremme", "type_vi_demon_alzoll", "type_vi_demon_balor", "type_vi_demon_errtu", "type_vi_demon_ndulu", "type_vi_demon_tersath", "type_vi_demon_wendonai" },
  devil_greater = { "horned_devil", "ice_devil", "pit_fiend" },
  devil_lesser = { "succubus", "erinyes", "barbed_devil", "bone_devil" },
  titan_elder = { "elder_titan_ac_2", "elder_titan_ac_3" },
  titan_lesser = { "lesser_titan_ac_1", "lesser_titan_ac_2" },
  titan_major = { "major_titan_ac_0", "major_titan_ac_1" },
}
