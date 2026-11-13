-- misc magic item def: phylactery_of_monstrous_attention
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part20.h (R276)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "phylactery_of_monstrous_attention",
  name = "Phylactery of Monstrous Attention",
  rows = {
    { name = "Phylactery of Monstrous Attention",
      set = "kMisc4", band = { 75, 76 }, xp = 0, xp_hi = 0,
      gp = 2000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 20, round = 276 },
  },
  pins = {
    { name = "attentionMinLevel", value = 10,
      comment = "at 10th or higher level the deity most powerful enemy "
      .. "interferes directly" },
  },
  tables = {
  },
}
