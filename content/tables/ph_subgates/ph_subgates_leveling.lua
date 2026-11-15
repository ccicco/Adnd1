-- ph_subgates_leveling
-- The R1055 subclass gate de-wire (rules/phb/subclassgates.h).
-- PHB subclass leveling pins (hit dice, XP ladders, fixed hp, level stops).
-- rows[]: the six registry subclasses in order (paladin, ranger, druid, illusionist, assassin, monk) - the R1042 equipment rows idiom.
-- tables[]: the printed columns; the accessors live in rules/phb/subclassgates.h and keep their clamps.
-- DO NOT hand-edit: tools/r1055_splice.py is the only writer.

return {
  key = "ph_subgates_leveling",
  name = "PHB subclass leveling pins (hit dice, XP ladders, fixed hp, level stops)",
  sources = {
    { part = 0, round = 1055 },
  },
  pins = {
    { name = "ph_subgates_levelingRowCount",
      value = 6,
      comment = "the table rows" },
  },
  rows = {
    { name = "paladin",
      set = "ph_subgates_leveling",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "ranger",
      set = "ph_subgates_leveling",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "druid",
      set = "ph_subgates_leveling",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "illusionist",
      set = "ph_subgates_leveling",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "assassin",
      set = "ph_subgates_leveling",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "monk",
      set = "ph_subgates_leveling",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "hit_die",
      values = {
        10, 8, 8, 4, 6, 4, 
      },
      comment = "the subclass hit die (the registry pins)" },
    { name = "xp_len",
      values = {
        11, 12, 14, 12, 15, 17, 
      },
      comment = "the printed XP attain rows per subclass (the ladder length)" },
    { name = "xp_attain",
      values = {
        0, 2750, 5500, 12000, 24000, 45000, 95000, 175000, 350000, 700000, 
        1050000, 0, 0, 0, 0, 0, 0, 0, 2250, 4500, 
        10000, 20000, 40000, 90000, 150000, 225000, 325000, 650000, 975000, 0, 
        0, 0, 0, 0, 0, 2000, 4000, 7500, 12500, 20000, 
        35000, 60000, 90000, 125000, 200000, 300000, 750000, 1500000, 0, 0, 
        0, 0, 2250, 4500, 9000, 18000, 35000, 60000, 95000, 145000, 
        220000, 440000, 660000, 0, 0, 0, 0, 0, 0, 1500, 
        3000, 6000, 12000, 25000, 50000, 100000, 200000, 300000, 425000, 575000, 
        750000, 1000000, 1500000, 0, 0, 0, 2250, 4750, 10000, 22500, 
        47500, 98000, 200000, 350000, 500000, 700000, 950000, 1250000, 1750000, 2250000, 
        2750000, 3250000, 
      },
      comment = "the XP to ATTAIN each level, [6][17] FLATTENED sub-major; ragged rows pad with 0 (never read past xp_len)" },
    { name = "xp_add",
      values = {
        350000, 325000, 0, 220000, 0, 0, 
      },
      comment = "the XP adder past the printed rows; 0 = the top row repeats" },
    { name = "fixed_hp_level",
      values = {
        9, 10, 9, 10, 10, 17, 
      },
      comment = "the fixed-hp level (past it the fixed hp per level)" },
    { name = "hp_beyond_fixed",
      values = {
        3, 2, 2, 1, 2, 0, 
      },
      comment = "the fixed hp per level past the fixed-hp level" },
    { name = "level_stop",
      values = {
        9, 10, 14, 10, 10, 17, 
      },
      comment = "the leveling stop (the name-cap analog)" },
  },
}
