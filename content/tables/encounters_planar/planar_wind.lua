-- encounter table def: planar_wind
-- The R65 planar family (R1036 de-wire): the PSYCHIC WIND d20 table
-- (DMG Appendix C Premium reprint p.181, OCR-verified).
-- band = the d20 roll; effect = the printed result (the engine maps it to the wind enum); days = the printed day range, -1,-1 when the result prints none. The saving throw versus magic (a storm save failure snaps the silver cord) is the caller's, passed in as saveMade - the engine's logic.
-- DO NOT hand-edit: tools/r1036_splice.py is the only writer.

return {
  key = "planar_wind",
  rows = {
    { band = {1,12}, effect = "slowed", days = {-1,-1} },
    { band = {13,16}, effect = "lost_return", days = {2,20} },
    { band = {17,19}, effect = "off_course", days = {-1,-1} },
    { band = {20,20}, effect = "storm", days = {4,40} },
  },
}
