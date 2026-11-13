-- misc magic item def: helm_of_comprehending_languages_reading_magic
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part12.h (R268)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "helm_of_comprehending_languages_reading_magic",
  name = "Helm of Comprehending Languages & Reading Magic",
  rows = {
    { name = "Helm of Comprehending Languages & Reading Magic",
      set = "kMisc3", band = { 31, 35 }, xp = 1000, xp_hi = 0,
      gp = 12500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 12, round = 268 },
  },
  pins = {
    { name = "helmComprStrangeTonguesPct", value = 90,
      comment = "understand 90 percent of strange tongues and writings" },
    { name = "helmComprMagicalWritingsPct", value = 80,
      comment = "80 percent of magical writings" },
    { name = "helmComprAllOrNone", value = 1,
      comment = "the figures apply to whether all or none of the "
      .. "tongue or inscription is understandable" },
    { name = "helmComprImpliesSpellUse", value = 0,
      comment = "understanding does not necessarily imply spell use" },
    { name = "helmComprHelmetOfAcValue", value = 5,
      comment = "equal to a normal helmet of the type accompanying "
      .. "armor class 5" },
  },
  tables = {
  },
}
