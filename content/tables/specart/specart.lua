-- misc magic item def: specart
-- The R1062 special-artifact family de-wire: the
-- retired static arrays of rules/dmg/specart.h and
-- rules/dmg/specart_prose_part2.h ride this def
-- (rowless: flat int columns only, no rows). The
-- accessors keep their clamps and comments; the
-- r280-r29x pin fragments and the headers are the
-- print-fidelity record. DO NOT hand-edit this
-- file; tools/r1062_splice.py is the only writer.
return {
  key = "specart",
  name = "DMG special artifact band table",
  sources = {
    { part = 0, round = 1062 },
  },
  pins = {
    { name = "specartTableCount",
      value = 5,
      comment = "the family columns" },
  },
  tables = {
    { name = "row_lo",
      values = {
        1, 2, 3, 5, 21, 22,
        23, 25, 26, 27, 28, 30,
        32, 33, 34, 36, 38, 39,
        41, 48, 64, 65, 67, 69,
        75, 92, 93, 99, 100,
      },
      comment = "from saRowLo" },
    { name = "row_hi",
      values = {
        1, 2, 4, 20, 21, 22,
        24, 25, 26, 27, 29, 31,
        32, 33, 35, 37, 38, 40,
        47, 63, 64, 66, 68, 74,
        91, 92, 98, 99, 100,
      },
      comment = "from saRowHi" },
    { name = "sale_gp",
      values = {
        55000, 90000, 62500, 50000, 75000, 85000,
        35000, 60000, 25000, 20000, 47500, 50000,
        100000, 40000, 27500, 35000, 72500, 185000,
        10000, 100000, 112500, 80000, 17500, 25000,
        150000, 97000, 5000, 0, 10000,
      },
      comment = "from saSaleGp" },
    { name = "sale_gp_hi",
      values = {
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        80000, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
      },
      comment = "from saSaleGpHi" },
    { name = "xp_value",
      values = {
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
      },
      comment = "from saXpValue" },
  },
}
