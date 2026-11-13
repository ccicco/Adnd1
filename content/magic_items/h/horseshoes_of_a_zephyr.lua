-- misc magic item def: horseshoes_of_a_zephyr
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part13.h (R269)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "horseshoes_of_a_zephyr",
  name = "Horseshoes of a Zephyr",
  rows = {
    { name = "Horseshoes of a Zephyr",
      set = "kMisc3", band = { 64, 65 }, xp = 1500, xp_hi = 0,
      gp = 7500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 13, round = 269 },
  },
  pins = {
    { name = "horseshoesZephyrGroundless", value = 1,
      comment = "the horse travels without touching the ground" },
    { name = "horseshoesZephyrNoTracks", value = 1,
      comment = "water can be passed over and no tracks are made on "
      .. "any sort of ground" },
    { name = "horseshoesZephyrNoTireHours", value = 12,
      comment = "the horse will not tire for 12 hours of continuous "
      .. "riding" },
    { name = "horseshoesZephyrPerDay", value = 1,
      comment = "per day of continuous riding" },
  },
  tables = {
  },
}
