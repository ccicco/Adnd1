-- misc magic item def: intro
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part1.h (R257)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "intro",
  name = "Intro (the misc magic section)",
  sources = {
    { part = 1, round = 257 },
  },
  pins = {
    { name = "introMaxDuplicates", value = 3,
      comment = "improbable to have more than 2 or 3" },
    { name = "introBooksExactWishCount", value = 2,
      comment = "a second wish determines exact contents" },
  },
  tables = {
  },
}
