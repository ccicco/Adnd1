-- class ladder def: paladin
-- The PHB class xp-title ladder, the R1044 de-wire. The six subclass ladders of rules/phb/subclasses.h.
-- Row encoding: band = { level, level } the printed
-- level, gp the XP to attain it (0 at level 1),
-- name the printed title. The accessor and clamp
-- semantics live in rules/phb/subclasses.h and are unchanged.
-- DO NOT hand-edit: tools/r1044_splice.py is the only writer.

return {
  key = "paladin",
  name = "The paladin xp and title ladder (11 rows)",
  rows = {
    { name = "Gallant", set = "paladin", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Keeper", set = "paladin", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 2750, gp_hi = 0, qty = { 0, 0 } },
    { name = "Protector", set = "paladin", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 5500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Defender", set = "paladin", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 12000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Warder", set = "paladin", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 24000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Guardian", set = "paladin", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 45000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Chevalier", set = "paladin", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 95000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Justiciar", set = "paladin", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 175000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Paladin", set = "paladin", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 350000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Paladin (10th level)", set = "paladin", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 700000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Paladin (11th level)", set = "paladin", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 1050000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1044 },
  },
  pins = {
    { name = "paladinRowCount", value = 11, comment = "the printed row count" },
  },
  tables = {},
}
