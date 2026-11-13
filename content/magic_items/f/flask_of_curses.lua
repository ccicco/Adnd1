-- misc magic item def: flask_of_curses
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part11.h (R267)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "flask_of_curses",
  name = "Flask of Curses",
  rows = {
    { name = "Flask of Curses",
      set = "kMisc3", band = { 16, 16 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 11, round = 267 },
  },
  pins = {
    { name = "flaskCurseOnFirstOpen", value = 1,
      comment = "first unstoppering visits a curse nearby" },
    { name = "flaskHarmlessAfterUse", value = 1,
      comment = "subsequently the flask is harmless" },
  },
  tables = {
  },
}
