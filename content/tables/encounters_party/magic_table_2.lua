-- encounter table def: magic_table_2
-- The R53/R55 party family (R1039 de-wire): MAGIC ITEM TABLE 2
-- (DMG Appendix C Premium reprint p.176-177, OCR-verified).
-- die = the die face (the table's own notation, 1-20 / the 16-face "(d8, d6)" reading / 1-12 - the half-dice split stays engine-side); kind = the item-kind token (none / wpn / rng / arm / shd / arm_set); a, b = the pluses (b = the shield plus on arm_set rows). Fiction-only rows ride kind = none (the R55 convention).
-- DO NOT hand-edit: tools/r1039_splice.py is the only writer.

return {
  key = "magic_table_2",
  rows = {
    { die = 1, kind = "none", a = 0, b = 0 },
    { die = 2, kind = "none", a = 0, b = 0 },
    { die = 3, kind = "none", a = 0, b = 0 },
    { die = 4, kind = "none", a = 0, b = 0 },
    { die = 5, kind = "none", a = 0, b = 0 },
    { die = 6, kind = "none", a = 0, b = 0 },
    { die = 7, kind = "none", a = 0, b = 0 },
    { die = 8, kind = "none", a = 0, b = 0 },
    { die = 9, kind = "none", a = 0, b = 0 },
    { die = 10, kind = "none", a = 0, b = 0 },
    { die = 11, kind = "none", a = 0, b = 0 },
    { die = 12, kind = "none", a = 0, b = 0 },
    { die = 13, kind = "arm_set", a = 1, b = 2 },
    { die = 14, kind = "arm", a = 4, b = 0 },
    { die = 15, kind = "wpn", a = 3, b = 0 },
    { die = 16, kind = "wpn", a = 2, b = 0 },
  },
}
