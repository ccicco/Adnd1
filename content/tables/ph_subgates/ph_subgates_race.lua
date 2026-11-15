-- ph_subgates_race
-- The R1055 subclass gate de-wire (rules/phb/subclassgates.h).
-- PHB Character Race Tables I and II (eligibility and level caps).
-- rows[]: the six registry subclasses in order (paladin, ranger, druid, illusionist, assassin, monk) - the R1042 equipment rows idiom.
-- tables[]: the printed columns; the accessors live in rules/phb/subclassgates.h and keep their clamps.
-- DO NOT hand-edit: tools/r1055_splice.py is the only writer.

return {
  key = "ph_subgates_race",
  name = "PHB Character Race Tables I and II (eligibility and level caps)",
  sources = {
    { part = 0, round = 1055 },
  },
  pins = {
    { name = "ph_subgates_raceRowCount",
      value = 6,
      comment = "the table rows" },
  },
  rows = {
    { name = "paladin",
      set = "ph_subgates_race",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "ranger",
      set = "ph_subgates_race",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "druid",
      set = "ph_subgates_race",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "illusionist",
      set = "ph_subgates_race",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "assassin",
      set = "ph_subgates_race",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "monk",
      set = "ph_subgates_race",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "race_allowed",
      values = {
        1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 
        0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 
        0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 
        1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 
        0, 0, 
      },
      comment = "Character Race Table I (class limitations), [6][7] FLATTENED sub-major, columns human dwarf elf gnome half-elf halfling half-orc; 1 = player-character eligible" },
    { name = "race_cap",
      values = {
        -1, 0, 0, 0, 0, 0, 0, -1, 0, 0, 
        0, 8, 0, 0, -1, 0, 0, 0, -1, -6, 
        0, -1, 0, 0, 7, 0, 0, 0, -1, 9, 
        10, 8, 11, 0, -1, -1, 0, 0, 0, 0, 
        0, 0, 
      },
      comment = "Character Race Table II (level caps), [6][7] FLATTENED sub-major; 0 = forbidden, -1 = unlimited, positive = the printed player cap, -n (n >= 2) = NPC-only cap n" },
  },
}
