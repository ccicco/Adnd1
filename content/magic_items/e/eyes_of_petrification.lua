-- misc magic item def: eyes_of_petrification
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part9.h (R265)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "eyes_of_petrification",
  name = "Eyes of Petrification",
  rows = {
    { name = "Eyes of Petrification",
      set = "kMisc2", band = { 100, 100 }, xp = 0, xp_hi = 0,
      gp = 0, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 9, round = 265 },
  },
  pins = {
    { name = "eyesPetrifyBasiliskGazePct", value = 25,
      comment = "25 percent work as basilisk gaze" },
  },
  tables = {
  },
}
