-- misc magic item def: lyre_of_building
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part17.h (R273)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "lyre_of_building",
  name = "Lyre of Building",
  rows = {
    { name = "Lyre of Building",
      set = "kMisc4", band = { 4, 4 }, xp = 5000, xp_hi = 0,
      gp = 30000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 17, round = 273 },
  },
  pins = {
    { name = "lyreNegateKindCount", value = 3,
      comment = "horn of blasting, disintegrate, elemental" },
    { name = "lyreNegateRounds", value = 6,
      comment = "negates 6 rounds of earth elemental attack" },
    { name = "lyreNegatePerDay", value = 1,
      comment = "the negatory chords play once per day" },
    { name = "lyreBuildPerWeek", value = 1,
      comment = "the building chords strum once per week" },
    { name = "lyreBuildTurns", value = 3,
      comment = "3 turns of such playing" },
    { name = "lyreBuildMen", value = 100,
      comment = "equal to the work of 100 men" },
    { name = "lyreBuildDays", value = 3,
      comment = "100 men laboring for 3 days" },
    { name = "lyreFalseChordPct", value = 20,
      comment = "a false chord negates 20 percent likely" },
    { name = "lyreFalseChordKnownPct", value = 5,
      comment = "only 5 percent once the proper ones known" },
    { name = "lyreFalseChordDisturbedPct", value = 50,
      comment = "disturbed while playing rises to 50 percent" },
  },
  tables = {
  },
}
