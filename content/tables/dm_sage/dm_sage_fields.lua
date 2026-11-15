-- dm_sage_fields
-- The R1054 sage de-wire (the DMG sage subsection).
-- DMG sage fields of study (the seven fields).
-- rows[]: the printed fields of study in order - the R1042 equipment rows idiom.
-- tables[]: the printed columns; the accessors live in rules/dmg/sage.h and keep their clamps.
-- DO NOT hand-edit: tools/r1054_splice.py is the only writer.

return {
  key = "dm_sage_fields",
  name = "DMG sage fields of study (the seven fields)",
  sources = {
    { part = 0, round = 1054 },
  },
  pins = {
    { name = "dm_sage_fieldsRowCount",
      value = 7,
      comment = "the table rows" },
  },
  rows = {
    { name = "Humankind",
      set = "dm_sage_fields",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Demi-Humankind",
      set = "dm_sage_fields",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Humanoids & Giantkind",
      set = "dm_sage_fields",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Physical Universe(s)",
      set = "dm_sage_fields",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Fauna",
      set = "dm_sage_fields",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Flora",
      set = "dm_sage_fields",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Supernatural & Unusual",
      set = "dm_sage_fields",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "field_lo",
      values = {
        1, 31, 51, 61, 71, 81, 91, 
      },
      comment = "the field percent band low" },
    { name = "field_hi",
      values = {
        30, 50, 60, 70, 80, 90, 100, 
      },
      comment = "the field percent band high" },
    { name = "field_category_count",
      values = {
        12, 11, 8, 10, 10, 8, 9, 
      },
      comment = "the special knowledge categories in the field" },
    { name = "field_category_first",
      values = {
        0, 12, 23, 31, 41, 51, 59, 
      },
      comment = "the flat index of the first category in the field" },
    { name = "spell_kind",
      values = {
        0, 0, 0, 0, 1, 1, 2, 
      },
      comment = "the field spell kind (0 clerical, 1 druidical, 2 magic-user or illusionist)" },
    { name = "band_lo",
      values = {
        1, 11, 31, 51, 71, 91, 
      },
      comment = "the fields-count dice band low" },
    { name = "band_hi",
      values = {
        10, 30, 50, 70, 90, 100, 
      },
      comment = "the fields-count dice band high" },
    { name = "band_minor",
      values = {
        1, 1, 1, 2, 2, 2, 
      },
      comment = "the minor fields in the band" },
    { name = "band_special",
      values = {
        2, 3, 4, 2, 3, 4, 
      },
      comment = "the special categories in the major field" },
  },
}
