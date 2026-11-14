-- encounter table def: planar_cyclone
-- The R65 planar family (R1036 de-wire): the ETHER CYCLONE d20 table
-- (DMG Appendix C Premium reprint p.181, OCR-verified).
-- band = the d20 roll; effect = the printed result (the engine maps it to the cyclone enum); days = the printed day range, -1,-1 when the result prints none. A storm save failure blows the traveller to the astral plane - the engine's logic, saveMade passed in by the caller.
-- DO NOT hand-edit: tools/r1036_splice.py is the only writer.

return {
  key = "planar_cyclone",
  rows = {
    { band = {1,10}, effect = "blown_about", days = {-1,-1} },
    { band = {11,15}, effect = "different_plane", days = {-1,-1} },
    { band = {16,18}, effect = "lost_new_plane", days = {5,60} },
    { band = {19,20}, effect = "storm_astral", days = {10,120} },
  },
}
