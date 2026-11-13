-- misc magic item def: book_of_vile_darkness
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part3.h (R259)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "book_of_vile_darkness",
  name = "Book of Vile Darkness",
  rows = {
    { name = "Book of Vile Darkness",
      set = "kMisc1", band = { 35, 35 }, xp = 8000, xp_hi = 0,
      gp = 40000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 3, round = 259 },
  },
  pins = {
    { name = "vileReadingWeeks", value = 1,
      comment = "full consumption requires 1 week" },
    { name = "vileWisdomGain", value = 1,
      comment = "the evil cleric gains 1 wisdom" },
    { name = "vileHalfwayPct", value = 50,
      comment = "XP to exactly half way into next level" },
    { name = "vileNeutralXpLossMin", value = 30000,
      comment = "neutral clerics lose 30,000-120,000 XP" },
    { name = "vileNeutralXpLossMax", value = 120000,
      comment = "or become evil, 50% for either" },
    { name = "vileNeutralSplitPct", value = 50,
      comment = "the either-or chance" },
    { name = "vileGoodSaveCount", value = 2,
      comment = "good clerics: poison or die, then magic or become "
      .. "permanently insane - two saves" },
    { name = "vileGoodXpLossBase", value = 250000,
      comment = "the good cleric XP loss base" },
    { name = "vileGoodXpLossPerWis", value = 10000,
      comment = "less 10,000 per wisdom point" },
    { name = "vileGoodHandlingHpMin", value = 5,
      comment = "other good characters take 5-30 hp" },
    { name = "vileGoodHandlingHpMax", value = 30,
      comment = "the top of the good handling damage" },
    { name = "vileNightHagPct", value = 80,
      comment = "80% a night hag comes if they look inside" },
    { name = "vileNeutralHandlingHpMin", value = 5,
      comment = "non-evil neutral handling: 5-20 hp" },
    { name = "vileNeutralHandlingHpMax", value = 20,
      comment = "the top of the neutral handling damage" },
  },
  tables = {
  },
}
