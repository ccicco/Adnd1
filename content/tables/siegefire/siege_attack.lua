-- misc magic item def: siege_attack
-- the R1061 siegefire family de-wire: the retired
-- static arrays of rules/dmg/siegefire.h ride this
-- def (rowless: flat int columns only, no rows).
-- The accessors keep their clamps and comments;
-- rules/audits/r214_war_machine_fire_and.h is the
-- print-fidelity record. DO NOT hand-edit this file;
-- tools/r1061_splice.py is the only writer.
return {
  key = "siege_attack",
  name = "DMG siege attack values",
  sources = {
    { part = 0, round = 1061 },
  },
  pins = {
    { name = "siege_attackTableCount",
      value = 5,
      comment = "the family columns" },
  },
  tables = {
    { name = "quarter_points",
      values = {
        4, 0, 2, 1, 24, 0,
        16, 8, 16, 0, 8, 4,
        0, 40, 0, 0, 8, 8,
        8, 8, 8, 40, 8, 4,
        0, 0, 0, 0, 2, 0,
        0, 0, 12, 0, 4, 2,
        8, 0, 4, 2, 4, 0,
        2, 1, 16, 0, 8, 4,
        24, 0, 16, 8, 12, 4,
        8, 4, 12, 4, 4, 2,
        72, 24, 32, 16, 2, 0,
        0, 0, 0, 80, 0, 0,
        4, 0, 1, 0, 2, 2,
        2, 1, 32, 8, 8, 4,
        32, 0, 20, 12,
      },
      comment = "from siegeAttackQuarterPoints" },
    { name = "per_round",
      values = {
        1, 0, 0, 0, 0, 1,
        0, 0, 1, 1, 1, 0,
        0, 1, 1, 0, 0, 0,
        1, 1, 1, 0,
      },
      comment = "from siegeAttackPerRound" },
    { name = "per_caster_level",
      values = {
        0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0,
        0, 0, 0, 0,
      },
      comment = "from siegeAttackPerCasterLevel" },
    { name = "quake_min",
      values = {
        5, 5, 5, 5,
      },
      comment = "from siegeAttackQuakeMin" },
    { name = "quake_max",
      values = {
        60, 30, 60, 30,
      },
      comment = "from siegeAttackQuakeMax" },
  },
}
