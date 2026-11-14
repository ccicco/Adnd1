-- weapon table def: weapon_mu_illusionist
-- The PHB weapon tables, the R1043 de-wire. Name-only rows.
-- Row encoding: band = { i, i } the printed row index.
-- The accessor and clamp semantics live in
-- rules/phb/weapontables.h and are unchanged.
-- DO NOT hand-edit: tools/r1043_splice.py is the only writer.

return {
  key = "weapon_mu_illusionist",
  name = "Magic-user and illusionist allowlist (3 rows)",
  rows = {
    { name = "dagger", set = "weapon_mu_illusionist", band = { 0, 0 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "dart", set = "weapon_mu_illusionist", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "quarterstaff", set = "weapon_mu_illusionist", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1043 },
  },
  pins = {
    { name = "weapon_mu_illusionistRowCount", value = 3, comment = "the printed row count" },
  },
  tables = {},
}
