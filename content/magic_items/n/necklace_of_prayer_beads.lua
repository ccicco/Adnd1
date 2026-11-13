-- misc magic item def: necklace_of_prayer_beads
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part19.h (R275)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "necklace_of_prayer_beads",
  name = "Necklace of Prayer Beads",
  rows = {
    { name = "Necklace of Prayer Beads",
      set = "kMisc4", band = { 28, 33 }, xp = 500, xp_hi = 0,
      gp = 3000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 19, round = 275 },
  },
  pins = {
    { name = "beadStoneMin", value = 25,
      comment = "the necklace consists of 25-30 stones" },
    { name = "beadStoneMax", value = 30,
      comment = "the upper edge of the 25-30 stones" },
    { name = "beadSemiPreciousPct", value = 60,
      comment = "60 percent semi-precious stones" },
    { name = "beadFancyPct", value = 40,
      comment = "40 percent fancy stones" },
    { name = "beadPetitionBonusPct", value = 25,
      comment = "25 percent more likely to petition the deity" },
    { name = "beadSpecialMin", value = 3,
      comment = "3-6 special beads" },
    { name = "beadSpecialMax", value = 6,
      comment = "the upper edge of the 3-6 special beads" },
    { name = "beadGemBaseGp", value = 1000,
      comment = "precious stones of 1,000 gp base value" },
    { name = "beadUsesPerDay", value = 1,
      comment = "each special bead once per day" },
    { name = "beadKarmaLevels", value = 4,
      comment = "the karma bead casts 4 levels higher" },
    { name = "beadSummonsPct", value = 90,
      comment = "the summons bead calls the deity at 90 percent" },
  },
  tables = {
    { name = "beadRowLo",
      comment = "the printed die band lower edges; i clamps",
      clamp_hi = 5,
      values = {
        1, 6, 11, 16, 18, 19,
      } },
    { name = "beadRowHi",
      comment = "the printed die band upper edges; i clamps",
      clamp_hi = 5,
      values = {
        5, 10, 15, 17, 18, 20,
      } },
  },
}
