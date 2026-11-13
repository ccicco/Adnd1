-- misc magic item def: efreeti_bottle
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part9.h (R265)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "efreeti_bottle",
  name = "Efreeti Bottle",
  rows = {
    { name = "Efreeti Bottle",
      set = "kMisc2", band = { 93, 93 }, xp = 9000, xp_hi = 0,
      gp = 45000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 9, round = 265 },
  },
  pins = {
    { name = "efreetiInsanePct", value = 10,
      comment = "10 percent insane, attacks at once" },
    { name = "efreetiWishesPct", value = 10,
      comment = "10 percent grants 3 wishes only" },
    { name = "efreetiServePct", value = 80,
      comment = "the other 80 percent serves normally" },
    { name = "efreetiWishCount", value = 3,
      comment = "the wishes-only bottle grants 3" },
    { name = "efreetiReleaseSegments", value = 1,
      comment = "issues from the bottle in but 1 segment" },
  },
  tables = {
  },
}
