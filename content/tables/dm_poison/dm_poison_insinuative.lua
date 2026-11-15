-- dm_poison_insinuative
-- The R1052 poison de-wire (DMG p.20).
-- DMG p.20 purchased poison, insinuative (grades A-D).
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
  key = "dm_poison_insinuative",
  name = "DMG p.20 purchased poison, insinuative (grades A-D)",
  sources = {
    { part = 0, round = 1052 },
  },
  pins = {
    { name = "dm_poison_insinuativeRowCount",
      value = 4,
      comment = "the table rows" },
  },
  rows = {
    { name = "A",
      set = "dm_poison_insinuative",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "B",
      set = "dm_poison_insinuative",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "C",
      set = "dm_poison_insinuative",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "D",
      set = "dm_poison_insinuative",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "cost_per_dose",
      values = {
        10, 75, 600, 1500, 
      },
      comment = "gp per dose" },
    { name = "onset_min",
      values = {
        2, 1, 1, 1, 
      },
      comment = "the onset range low end" },
    { name = "onset_max",
      values = {
        5, 3, 1, 1, 
      },
      comment = "the onset range high end" },
    { name = "damage_if_no_save",
      values = {
        15, 25, 35, 0, 
      },
      comment = "pre-kill damage on a failed save" },
  },
}
