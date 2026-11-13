-- misc magic item def: quaals_feather_token
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part20.h (R276)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "quaals_feather_token",
  name = "Quaal's Feather Token",
  rows = {
    { name = "Quaal's Feather Token",
      set = "kMisc4", band = { 86, 100 }, xp = 500, xp_hi = 1000,
      gp = 2000, gp_hi = 7000, qty = { 0, 0 } },
  },
  sources = {
    { part = 20, round = 276 },
  },
  pins = {
    { name = "tokenUses", value = 1,
      comment = "each token is usable but once" },
    { name = "tokenAnchorDays", value = 1,
      comment = "the anchor moors a craft immobile for 1 full day" },
    { name = "tokenBirdDays", value = 1,
      comment = "the bird equals a roc of the largest size (1 day "
      .. "duration)" },
    { name = "tokenFanHours", value = 8,
      comment = "the fan works up to eight hours a day" },
    { name = "tokenSwanSpeedInches", value = 24,
      comment = "the swan boat swims at 24 inch speed" },
    { name = "tokenSwanHorses", value = 8,
      comment = "it carries 8 horses and gear" },
    { name = "tokenSwanMen", value = 32,
      comment = "or 32 men" },
    { name = "tokenSwanDays", value = 1,
      comment = "duration 1 day" },
    { name = "tokenTreeTrunkFeet", value = 6,
      comment = "a great oak with a 6 foot diameter trunk" },
    { name = "tokenTreeHeightFeet", value = 60,
      comment = "60 foot height" },
    { name = "tokenTreeTopFeet", value = 40,
      comment = "40 foot top diameter" },
    { name = "tokenWhipPlus", value = 1,
      comment = "a +1 weapon" },
    { name = "tokenWhipLevel", value = 9,
      comment = "9th level fighter to hit probability" },
    { name = "tokenWhipDmgMin", value = 2,
      comment = "2-7 hit points damage" },
    { name = "tokenWhipDmgMax", value = 7 },
    { name = "tokenWhipBindMin", value = 2,
      comment = "save versus magic or be bound fast for 2-7 rounds" },
    { name = "tokenWhipBindMax", value = 7 },
    { name = "tokenWhipTurns", value = 6,
      comment = "wielded for up to 6 turns" },
  },
  tables = {
    { name = "tokenRowLo",
      comment = "the printed token band lower edges; i clamps",
      clamp_hi = 5,
      values = {
        1, 5, 8, 11, 14, 19,
      } },
    { name = "tokenRowHi",
      comment = "the printed token band upper edges; i clamps",
      clamp_hi = 5,
      values = {
        4, 7, 10, 13, 18, 20,
      } },
  },
}
