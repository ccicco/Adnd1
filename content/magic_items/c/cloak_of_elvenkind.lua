-- misc magic item def: cloak_of_elvenkind
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part5.h (R261)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "cloak_of_elvenkind",
  name = "Cloak of Elvenkind",
  rows = {
    { name = "Cloak of Elvenkind",
      set = "kMisc2", band = { 19, 27 }, xp = 1000, xp_hi = 0,
      gp = 6000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 5, round = 261 },
  },
  pins = {
    { name = "elvenkindRowCount", value = 9,
      comment = "the invisibility table rows" },
    { name = "elvenkindOutdoorNaturalRows", value = 3,
      comment = "heavy growth, light growth, open fields" },
    { name = "elvenkindOutdoorOtherRows", value = 3,
      comment = "rocky terrain, buildings, bright room" },
    { name = "elvenkindUndergroundRows", value = 3,
      comment = "torch, infravision, light" },
    { name = "elvenkindHumanoidPct", value = 90,
      comment = "human to elven sized cloaks" },
    { name = "elvenkindSmallPct", value = 10,
      comment = "smaller persons, about 4 feet" },
  },
  tables = {
    { name = "elvenkindInvisibilityPct",
      comment = "invisibility per setting; i clamps",
      clamp_hi = 8,
      values = {
        100, 99, 95, 98, 90, 50, 95, 90, 50,
      } },
  },
}
