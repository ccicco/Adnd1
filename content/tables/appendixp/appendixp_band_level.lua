-- encounter table def: appendixp_band_level
-- The DMG Appendix P convention party (R1040 de-wire): the LEVEL options (p.225)
-- (DMG pp.225-226, 1eonline.info compilation, OCR-verified).
-- band = the printed band (1 low / 2 medium / 3 upper); option = the printed option (1-3); level = the printed level range for that band x option.
-- DO NOT hand-edit: tools/r1040_splice.py is the only writer.

return {
  key = "appendixp_band_level",
  rows = {
    { band = 1, option = 1, level = {1,2} },
    { band = 1, option = 2, level = {1,3} },
    { band = 1, option = 3, level = {2,4} },
    { band = 2, option = 1, level = {5,7} },
    { band = 2, option = 2, level = {5,8} },
    { band = 2, option = 3, level = {7,9} },
    { band = 3, option = 1, level = {8,10} },
    { band = 3, option = 2, level = {8,11} },
    { band = 3, option = 3, level = {9,12} },
  },
}
