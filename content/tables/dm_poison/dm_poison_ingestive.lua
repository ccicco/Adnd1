-- dm_poison_ingestive
-- The R1052 poison de-wire (DMG p.20).
-- DMG p.20 purchased poison, ingestive (grades A-E).
-- rows[]: the grade letters (name the
-- string, band the grade index, all
-- price/xp/qty keys 0 - the R1042
-- equipment rows idiom). tables[]: the
-- per-grade columns of the p.20 print.
-- damage_if_no_save holds the PRE-KILL
-- printed values (a kill grade reads -1
-- through poisonKillsIfNoSave).
-- The accessors live in rules/dmg/poison.h
-- and keep their guards and branches.
-- DO NOT hand-edit: tools/r1052_splice.py
-- is the only writer.

return {
  key = "dm_poison_ingestive",
  name = "DMG p.20 purchased poison, ingestive (grades A-E)",
  sources = {
    { part = 0, round = 1052 },
  },
  pins = {
    { name = "dm_poison_ingestiveRowCount",
      value = 5,
      comment = "the table rows" },
  },
  rows = {
    { name = "A",
      set = "dm_poison_ingestive",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "B",
      set = "dm_poison_ingestive",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "C",
      set = "dm_poison_ingestive",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "D",
      set = "dm_poison_ingestive",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "E",
      set = "dm_poison_ingestive",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "cost_per_dose",
      values = {
        5, 30, 200, 500, 1000, 
      },
      comment = "gp per dose" },
    { name = "onset_min",
      values = {
        2, 2, 1, 1, 1, 
      },
      comment = "the onset range low end" },
    { name = "onset_max",
      values = {
        8, 5, 2, 1, 4, 
      },
      comment = "the onset range high end" },
    { name = "detect_chance",
      values = {
        80, 65, 40, 15, 0, 
      },
      comment = "the taste/smell/see percent" },
    { name = "damage_if_save",
      values = {
        10, 15, 20, 25, 30, 
      },
      comment = "damage on a made save (ingestive print)" },
    { name = "damage_if_no_save",
      values = {
        20, 30, 40, 0, 0, 
      },
      comment = "pre-kill damage on a failed save" },
  },
}
