-- misc magic item def: helm_of_teleportation
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part12.h (R268)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "helm_of_teleportation",
  name = "Helm of Teleportation",
  rows = {
    { name = "Helm of Teleportation",
      set = "kMisc3", band = { 40, 40 }, xp = 2500, xp_hi = 0,
      gp = 30000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 12, round = 268 },
  },
  pins = {
    { name = "helmTeleportPerDay", value = 1,
      comment = "the wearer may teleport once per day, exactly as if a "
      .. "magic-user: destination known, a risk involved" },
    { name = "helmTeleportMuRefreshRepeats", value = 3,
      comment = "a magic-user may memorize the spell and use the helm "
      .. "to refresh memory, repeating the spell up to 3 times" },
    { name = "helmTeleportMuStillPersonalAfterRefresh", value = 1,
      comment = "and still be able to personally teleport by means of "
      .. "the helm" },
    { name = "helmTeleportMuUncastPersonalCount", value = 6,
      comment = "while the spell is retained uncast the magic-user can "
      .. "personally teleport up to 6 times before the memory "
      .. "is lost" },
    { name = "helmTeleportUsageAfterMemoryLost", value = 1,
      comment = "even then a usage of the helm remains" },
  },
  tables = {
  },
}
