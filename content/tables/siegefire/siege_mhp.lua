-- misc magic item def: siege_mhp
-- the R1061 siegefire family de-wire: the retired
-- static arrays of rules/dmg/siegefire.h ride this
-- def (rowless: flat int columns only, no rows).
-- The accessors keep their clamps and comments;
-- rules/audits/r214_war_machine_fire_and.h is the
-- print-fidelity record. DO NOT hand-edit this file;
-- tools/r1061_splice.py is the only writer.
return {
  key = "siege_mhp",
  name = "DMG siege device hit points",
  sources = {
    { part = 0, round = 1061 },
  },
  pins = {
    { name = "siege_mhpTableCount",
      value = 1,
      comment = "the family columns" },
  },
  tables = {
    { name = "mhp",
      values = {
        2, 6, 4, 2, 10, 4,
        3, 12, 0, 16, 12, 8,
      },
      comment = "from siegeDeviceMhp" },
  },
}
