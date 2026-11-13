-- misc magic item def: cloak_of_protection
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part5.h (R261)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "cloak_of_protection",
  name = "Cloak of Protection",
  rows = {
    { name = "Cloak of Protection",
      set = "kMisc2", band = { 33, 55 }, xp = 1000, xp_hi = 0,
      gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 5, round = 261 },
  },
  pins = {
    { name = "cloakProtRowCount", value = 5,
      comment = "the random plus table rows" },
    { name = "cloakProtAcPerPlus", value = 1,
      comment = "armor class better per plus" },
    { name = "cloakProtSavePerPlus", value = 1,
      comment = "saving throw added per plus" },
    { name = "cloakProtExampleBaseAc", value = 10,
      comment = "the +1 example: AC 10 becomes 9" },
  },
  tables = {
    { name = "cloakProtBandLo",
      comment = "the plus band lower edges; i clamps",
      clamp_hi = 4,
      values = {
        1, 36, 66, 86, 96,
      } },
    { name = "cloakProtBandHi",
      comment = "the plus band upper edges; i clamps",
      clamp_hi = 4,
      values = {
        35, 65, 85, 95, 100,
      } },
    { name = "cloakProtPlus",
      comment = "the cloak plus per band; i clamps",
      clamp_hi = 4,
      values = {
        1, 2, 3, 4, 5,
      } },
  },
}
