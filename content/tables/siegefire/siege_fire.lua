-- misc magic item def: siege_fire
-- the R1061 siegefire family de-wire: the retired
-- static arrays of rules/dmg/siegefire.h ride this
-- def (rowless: flat int columns only, no rows).
-- The accessors keep their clamps and comments;
-- rules/audits/r214_war_machine_fire_and.h is the
-- print-fidelity record. DO NOT hand-edit this file;
-- tools/r1061_splice.py is the only writer.
return {
  key = "siege_fire",
  name = "DMG war machine fire table",
  sources = {
    { part = 0, round = 1061 },
  },
  pins = {
    { name = "siege_fireTableCount",
      value = 11,
      comment = "the family columns" },
  },
  tables = {
    { name = "field_of_fire",
      values = {
        45, 15, 30, 0, 0, 10,
      },
      comment = "from siegeFieldOfFireDegrees" },
    { name = "range_min_qi",
      values = {
        1, 72, 60, 0, 0, 96,
      },
      comment = "from siegeRangeMinQuarterInches" },
    { name = "range_max_qi",
      values = {
        128, 144, 120, 1, 1, 192,
      },
      comment = "from siegeRangeMaxQuarterInches" },
    { name = "damage_sm_min",
      values = {
        2, 2, 2, 9, 9, 3,
      },
      comment = "from siegeDamageSMMin" },
    { name = "damage_sm_max",
      values = {
        12, 24, 20, 16, 16, 30,
      },
      comment = "from siegeDamageSMMax" },
    { name = "damage_l_min",
      values = {
        3, 4, 3, 7, 13, 5,
      },
      comment = "from siegeDamageLMin" },
    { name = "damage_l_max",
      values = {
        18, 16, 12, 12, 24, 20,
      },
      comment = "from siegeDamageLMax" },
    { name = "rate_of_fire_min_h",
      values = {
        25, 25, 25, 50, 50, 25,
      },
      comment = "from siegeRateOfFireMinHundredths" },
    { name = "rate_of_fire_max_h",
      values = {
        50, 25, 25, 50, 50, 25,
      },
      comment = "from siegeRateOfFireMaxHundredths" },
    { name = "crew_min",
      values = {
        2, 6, 4, 10, 10, 8,
      },
      comment = "from siegeCrewMin" },
    { name = "crew_max",
      values = {
        4, 10, 6, 20, 20, 12,
      },
      comment = "from siegeCrewMax" },
  },
}
