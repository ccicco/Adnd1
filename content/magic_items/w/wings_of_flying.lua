-- misc magic item def: wings_of_flying
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "wings_of_flying",
  name = "Wings of Flying",
  rows = {
    { name = "Wings of Flying",
      set = "kMisc5", band = { 91, 100 }, xp = 750, xp_hi = 0,
      gp = 7500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "wingsSpanFeet", value = 20,
      comment = "gigantic bat wings of 20 foot span" },
    { name = "wingsRestHours", value = 1,
      comment = "after maximum flight the wearer rests 1 hour" },
    { name = "wingsQuietHours", value = 1,
      comment = "shorter flights need only 1 hour of quiet" },
    { name = "wingsNoRestTurns", value = 1,
      comment = "flights under 1 turn need no rest at all" },
    { name = "wingsUsesPerDay", value = 1,
      comment = "the wings work but once per day" },
    { name = "wingsSupportPounds", value = 500,
      comment = "they support up to 500 pounds weight" },
    { name = "wingsSpeedRows", value = 3,
      comment = "the duration list has three entries" },
  },
  tables = {
    { name = "wingsSpeedTurns",
      comment = "the turns flown per speed entry; i clamps 2 turns at 32 "
      .. "inches, 4 at 18, 8 at 12",
      clamp_hi = 2,
      values = {
        2, 4, 8,
      } },
    { name = "wingsSpeedInches",
      comment = "the flight speed per entry; i clamps",
      clamp_hi = 2,
      values = {
        32, 18, 12,
      } },
  },
}
