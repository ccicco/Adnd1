-- ph_subgates_qualify
-- The R1055 subclass gate de-wire (rules/phb/subclassgates.h).
-- PHB subclass qualification gates (ability minimums, alignment, xp bonus).
-- rows[]: the six registry subclasses in order (paladin, ranger, druid, illusionist, assassin, monk) - the R1042 equipment rows idiom.
-- tables[]: the printed columns; the accessors live in rules/phb/subclassgates.h and keep their clamps.
-- DO NOT hand-edit: tools/r1055_splice.py is the only writer.

return {
  key = "ph_subgates_qualify",
  name = "PHB subclass qualification gates (ability minimums, alignment, xp bonus)",
  sources = {
    { part = 0, round = 1055 },
  },
  pins = {
    { name = "ph_subgates_qualifyRowCount",
      value = 6,
      comment = "the table rows" },
  },
  rows = {
    { name = "paladin",
      set = "ph_subgates_qualify",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "ranger",
      set = "ph_subgates_qualify",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "druid",
      set = "ph_subgates_qualify",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "illusionist",
      set = "ph_subgates_qualify",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "assassin",
      set = "ph_subgates_qualify",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "monk",
      set = "ph_subgates_qualify",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "ability_min",
      values = {
        12, 9, 13, 0, 9, 17, 13, 13, 14, 0, 
        14, 0, 0, 0, 12, 0, 0, 15, 0, 15, 
        0, 16, 0, 0, 12, 11, 0, 12, 0, 0, 
        15, 0, 15, 15, 11, 0, 
      },
      comment = "the class-section ability minimums, STR INT WIS DEX CON CHA columns, [6][6] FLATTENED sub-major; 0 = no requirement" },
    { name = "align_req",
      values = {
        1, 2, 3, 0, 4, 5, 
      },
      comment = "the Table I alignment requirement codes (the SubAlignReq enum order)" },
    { name = "xp_bonus",
      values = {
        1, 2, 3, 0, 0, 0, 
      },
      comment = "the printed experience-bonus rule codes (the SubXpBonusRule enum order)" },
  },
}
