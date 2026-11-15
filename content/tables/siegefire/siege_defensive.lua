-- misc magic item def: siege_defensive
-- the R1061 siegefire family de-wire: the retired
-- static arrays of rules/dmg/siegefire.h ride this
-- def (rowless: flat int columns only, no rows).
-- The accessors keep their clamps and comments;
-- rules/audits/r214_war_machine_fire_and.h is the
-- print-fidelity record. DO NOT hand-edit this file;
-- tools/r1061_splice.py is the only writer.
return {
  key = "siege_defensive",
  name = "DMG construction defensive values",
  sources = {
    { part = 0, round = 1061 },
  },
  pins = {
    { name = "siege_defensiveTableCount",
      value = 2,
      comment = "the family columns" },
  },
  tables = {
    { name = "defensive_min",
      values = {
        150, 25, 20, 12, 10, 8,
        20, 10, 1, 3, 10, 8,
        120, 2, 10, 6, 20, 15,
        12, 20, 40, 30, 40, 20,
        4, 12,
      },
      comment = "from constructionDefensiveMin" },
    { name = "defensive_max",
      values = {
        150, 25, 20, 12, 10, 16,
        20, 10, 1, 3, 15, 12,
        120, 2, 10, 12, 20, 15,
        12, 20, 80, 50, 40, 20,
        4, 12,
      },
      comment = "from constructionDefensiveMax" },
  },
}
