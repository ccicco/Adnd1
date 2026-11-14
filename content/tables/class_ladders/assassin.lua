-- class ladder def: assassin
-- The PHB class xp-title ladder, the R1044 de-wire. The six subclass ladders of rules/phb/subclasses.h.
-- Row encoding: band = { level, level } the printed
-- level, gp the XP to attain it (0 at level 1),
-- name the printed title. The accessor and clamp
-- semantics live in rules/phb/subclasses.h and are unchanged.
-- DO NOT hand-edit: tools/r1044_splice.py is the only writer.

return {
  key = "assassin",
  name = "The assassin xp and title ladder (15 rows)",
  rows = {
    { name = "Bravo (Apprentice)", set = "assassin", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Rutterkin", set = "assassin", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 1500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Waghalter", set = "assassin", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 3000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Murderer", set = "assassin", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 6000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Thug", set = "assassin", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 12000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Killer", set = "assassin", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 25000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Cutthroat", set = "assassin", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 50000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Executioner", set = "assassin", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 100000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Assassin", set = "assassin", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 200000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Expert Assassin", set = "assassin", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 300000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Senior Assassin", set = "assassin", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 425000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Chief Assassin", set = "assassin", band = { 12, 12 }, xp = 0, xp_hi = 0, gp = 575000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Prime Assassin", set = "assassin", band = { 13, 13 }, xp = 0, xp_hi = 0, gp = 750000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Guildmaster Assassin", set = "assassin", band = { 14, 14 }, xp = 0, xp_hi = 0, gp = 1000000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Grandfather of Assassins", set = "assassin", band = { 15, 15 }, xp = 0, xp_hi = 0, gp = 1500000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1044 },
  },
  pins = {
    { name = "assassinRowCount", value = 15, comment = "the printed row count" },
  },
  tables = {},
}
