-- misc magic item def: scarab_of_death
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part22.h (R278)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "scarab_of_death",
  name = "Scarab of Death",
  rows = {
    { name = "Scarab of Death",
      set = "kMisc5", band = { 35, 35 }, xp = 0, xp_hi = 0,
      gp = 2500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 22, round = 278 },
  },
  pins = {
    { name = "deathHoldRounds", value = 1,
      comment = "changes if held for more than 1 round" },
    { name = "deathContainerFeet", value = 1,
      comment = "or placed within 1 foot of a warm" },
    { name = "deathContainerTurns", value = 1,
      comment = "living body for 1 turn" },
    { name = "deathHeartRounds", value = 1,
      comment = "reaches the victim heart in a single round" },
  },
  tables = {
  },
}
