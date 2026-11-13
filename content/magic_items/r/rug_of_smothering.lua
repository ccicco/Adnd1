-- misc magic item def: rug_of_smothering
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part22.h (R278)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "rug_of_smothering",
  name = "Rug of Smothering",
  rows = {
    { name = "Rug of Smothering",
      set = "kMisc5", band = { 32, 32 }, xp = 0, xp_hi = 0,
      gp = 1500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 22, round = 278 },
  },
  pins = {
    { name = "smotherRoundsMin", value = 3,
      comment = "suffocates its victim in 3-6 rounds" },
    { name = "smotherRoundsMax", value = 6,
      comment = "the suffocation ceiling" },
    { name = "smotherBlockingSpells", value = 4,
      comment = "four spells prevent the smothering: alter reality, "
      .. "animate object, hold plant, wish" },
  },
  tables = {
  },
}
