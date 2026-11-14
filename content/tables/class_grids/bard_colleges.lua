-- class grid def: bard_colleges
-- The PHB bard college column, the R1047
-- de-wire. Bards Table II, rules/phb/bard.h.
-- Row encoding: name = the printed
-- college, band = { level, level } the
-- bard level, rest zero. The accessor and
-- the clamp semantics live in
-- rules/phb/bard.h and are unchanged.
-- DO NOT hand-edit: tools/r1047_splice.py
-- is the only writer.

return {
  key = "bard_colleges",
  name = "The bard college ladder (23 rows)",
  rows = {
    { name = "Probationer", set = "bard_colleges", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Fochlucan", set = "bard_colleges", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Fochlucan", set = "bard_colleges", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Fochlucan", set = "bard_colleges", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Mac-Fuirmidh", set = "bard_colleges", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Mac-Fuirmidh", set = "bard_colleges", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Mac-Fuirmidh", set = "bard_colleges", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Doss", set = "bard_colleges", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Doss", set = "bard_colleges", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Doss", set = "bard_colleges", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Canaith", set = "bard_colleges", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Canaith", set = "bard_colleges", band = { 12, 12 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Canaith", set = "bard_colleges", band = { 13, 13 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Cli", set = "bard_colleges", band = { 14, 14 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Cli", set = "bard_colleges", band = { 15, 15 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Cli", set = "bard_colleges", band = { 16, 16 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Anstruth", set = "bard_colleges", band = { 17, 17 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Anstruth", set = "bard_colleges", band = { 18, 18 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Anstruth", set = "bard_colleges", band = { 19, 19 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ollamh", set = "bard_colleges", band = { 20, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ollamh", set = "bard_colleges", band = { 21, 21 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ollamh", set = "bard_colleges", band = { 22, 22 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Magna Alumnae", set = "bard_colleges", band = { 23, 23 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1047 },
  },
  pins = {
    { name = "bard_collegesRowCount", value = 23, comment = "the bard levels" },
  },
  tables = {},
}
