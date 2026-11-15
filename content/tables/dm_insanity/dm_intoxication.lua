-- dm_intoxication
-- The R1053 insanity de-wire (DMG pp.82-83).
-- DMG p.82 intoxication (the five states).
-- rows[]: the intoxication states (names COMPUTED from the INTOX_* enum members) - the R1042 equipment rows idiom.
-- tables[]: the printed columns per row.
-- The accessors live in rules/dmg/insanity.h and keep their clamps and branches.
-- DO NOT hand-edit: tools/r1053_splice.py is the only writer.

return {
  key = "dm_intoxication",
  name = "DMG p.82 intoxication (the five states)",
  sources = {
    { part = 0, round = 1053 },
  },
  pins = {
    { name = "dm_intoxicationRowCount",
      value = 5,
      comment = "the table rows" },
  },
  rows = {
    { name = "sober",
      set = "dm_intoxication",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "slight",
      set = "dm_intoxication",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "moderate",
      set = "dm_intoxication",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "great",
      set = "dm_intoxication",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "comatose",
      set = "dm_intoxication",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "bravery_adjust",
      values = {
        0, 1, 2, 4, 0, 
      },
      comment = "the bravery modifier" },
    { name = "morale_adjust",
      values = {
        0, 5, 10, 15, 0, 
      },
      comment = "the NPC morale percent" },
    { name = "intelligence_adjust",
      values = {
        0, -1, -3, -6, 0, 
      },
      comment = "the intelligence modifier" },
    { name = "wisdom_adjust",
      values = {
        0, -1, -4, -7, 0, 
      },
      comment = "the wisdom modifier" },
    { name = "dexterity_adjust",
      values = {
        0, 0, -2, -5, 0, 
      },
      comment = "the dexterity modifier" },
    { name = "charisma_adjust",
      values = {
        0, 0, -1, -4, 0, 
      },
      comment = "the charisma modifier" },
    { name = "attack_dice_adjust",
      values = {
        0, 0, -1, -5, 0, 
      },
      comment = "the attack-dice penalty" },
    { name = "hit_point_adjust",
      values = {
        0, 0, 1, 3, 0, 
      },
      comment = "the hit-point bonus" },
    { name = "magic_save_raise_percent",
      values = {
        0, 0, 5, 25, 0, 
      },
      comment = "the vs-magic save raise percent" },
    { name = "recovery_min_hours",
      values = {
        0, 1, 2, 4, 7, 
      },
      comment = "recovery hours low end" },
    { name = "recovery_max_hours",
      values = {
        0, 2, 4, 6, 10, 
      },
      comment = "recovery hours high end" },
    { name = "stimulant_mild_percent",
      values = {
        100, 80, 85, 90, 95, 
      },
      comment = "the mild stimulant multiplier percent" },
    { name = "stimulant_strong_percent",
      values = {
        100, 50, 55, 55, 60, 
      },
      comment = "the strong stimulant multiplier percent" },
  },
}
