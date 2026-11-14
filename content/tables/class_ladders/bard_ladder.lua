-- class ladder def: bard_ladder
-- The PHB class xp-title ladder, the R1044 de-wire. Bards Table I, rules/phb/bard.h.
-- Row encoding: band = { level, level } the printed
-- level, gp the XP to attain it (0 at level 1),
-- name the printed title. The accessor and clamp
-- semantics live in rules/phb/bard.h and are unchanged.
-- DO NOT hand-edit: tools/r1044_splice.py is the only writer.

return {
  key = "bard_ladder",
  name = "The bard xp and title ladder (23 rows)",
  rows = {
    { name = "Rhymer", set = "bard_ladder", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Lyrist", set = "bard_ladder", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 2001, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sonnateer", set = "bard_ladder", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 4001, gp_hi = 0, qty = { 0, 0 } },
    { name = "Skald", set = "bard_ladder", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 8001, gp_hi = 0, qty = { 0, 0 } },
    { name = "Racaraide", set = "bard_ladder", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 16001, gp_hi = 0, qty = { 0, 0 } },
    { name = "Joungleur", set = "bard_ladder", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 25001, gp_hi = 0, qty = { 0, 0 } },
    { name = "Troubador", set = "bard_ladder", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 40001, gp_hi = 0, qty = { 0, 0 } },
    { name = "Minstrel", set = "bard_ladder", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 60001, gp_hi = 0, qty = { 0, 0 } },
    { name = "Muse", set = "bard_ladder", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 85001, gp_hi = 0, qty = { 0, 0 } },
    { name = "Lorist", set = "bard_ladder", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 110001, gp_hi = 0, qty = { 0, 0 } },
    { name = "Bard", set = "bard_ladder", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 150001, gp_hi = 0, qty = { 0, 0 } },
    { name = "Master Bard", set = "bard_ladder", band = { 12, 12 }, xp = 0, xp_hi = 0, gp = 200001, gp_hi = 0, qty = { 0, 0 } },
    { name = "M. Bard 13th", set = "bard_ladder", band = { 13, 13 }, xp = 0, xp_hi = 0, gp = 400001, gp_hi = 0, qty = { 0, 0 } },
    { name = "M. Bard 14th", set = "bard_ladder", band = { 14, 14 }, xp = 0, xp_hi = 0, gp = 600001, gp_hi = 0, qty = { 0, 0 } },
    { name = "M. Bard 15th", set = "bard_ladder", band = { 15, 15 }, xp = 0, xp_hi = 0, gp = 800001, gp_hi = 0, qty = { 0, 0 } },
    { name = "M. Bard 16th", set = "bard_ladder", band = { 16, 16 }, xp = 0, xp_hi = 0, gp = 1000001, gp_hi = 0, qty = { 0, 0 } },
    { name = "M. Bard 17th", set = "bard_ladder", band = { 17, 17 }, xp = 0, xp_hi = 0, gp = 1200001, gp_hi = 0, qty = { 0, 0 } },
    { name = "M. Bard 18th", set = "bard_ladder", band = { 18, 18 }, xp = 0, xp_hi = 0, gp = 1400001, gp_hi = 0, qty = { 0, 0 } },
    { name = "M. Bard 19th", set = "bard_ladder", band = { 19, 19 }, xp = 0, xp_hi = 0, gp = 1600001, gp_hi = 0, qty = { 0, 0 } },
    { name = "M. Bard 20th", set = "bard_ladder", band = { 20, 20 }, xp = 0, xp_hi = 0, gp = 1800001, gp_hi = 0, qty = { 0, 0 } },
    { name = "M. Bard 21st", set = "bard_ladder", band = { 21, 21 }, xp = 0, xp_hi = 0, gp = 2000001, gp_hi = 0, qty = { 0, 0 } },
    { name = "M. Bard 22nd", set = "bard_ladder", band = { 22, 22 }, xp = 0, xp_hi = 0, gp = 2200001, gp_hi = 0, qty = { 0, 0 } },
    { name = "M. Bard 23rd", set = "bard_ladder", band = { 23, 23 }, xp = 0, xp_hi = 0, gp = 3000001, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1044 },
  },
  pins = {
    { name = "bard_ladderRowCount", value = 23, comment = "the printed row count" },
  },
  tables = {},
}
