-- misc magic item def: boat_folding
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part2.h (R258)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "boat_folding",
  name = "Boat, Folding",
  rows = {
    { name = "Boat, Folding",
      set = "kMisc1", band = { 32, 32 }, xp = 10000, xp_hi = 0,
      gp = 25000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 2, round = 258 },
  },
  pins = {
    { name = "boatBoxLengthInches", value = 12,
      comment = "the box: 1 foot long" },
    { name = "boatBoxWidthInches", value = 6,
      comment = "the box: half a foot wide" },
    { name = "boatBoxDepthInches", value = 6,
      comment = "the box: half a foot deep" },
    { name = "boatLengthFeet", value = 10,
      comment = "first word: the boat, 10 feet long" },
    { name = "boatWidthFeet", value = 4,
      comment = "the boat, 4 feet wide" },
    { name = "boatDepthFeet", value = 2,
      comment = "the boat, 2 feet deep" },
    { name = "boatShipLengthFeet", value = 24,
      comment = "second word: the ship, 24 feet long" },
    { name = "boatShipWidthFeet", value = 8,
      comment = "the ship, 8 feet wide" },
    { name = "boatShipDepthFeet", value = 6,
      comment = "the ship, 6 feet deep" },
    { name = "boatOarPairs", value = 1,
      comment = "the boat: 1 pair of oars" },
    { name = "boatComponentCount", value = 4,
      comment = "oars, anchor, mast, lateen sail" },
    { name = "boatShipOarSets", value = 5,
      comment = "the ship: 5 sets of oars" },
    { name = "boatShipComponentCount", value = 7,
      comment = "rowing seats, oar sets, steering oar, anchor, deck "
      .. "cabin, mast, square sail" },
    { name = "boatPersonsMin", value = 3,
      comment = "the boat holds 3 or 4 persons" },
    { name = "boatPersonsMax", value = 4,
      comment = "the comfortable top" },
    { name = "boatShipPersons", value = 15,
      comment = "the ship carries 15 persons" },
    { name = "boatCommandWordCount", value = 3,
      comment = "third word folds it to a box again" },
  },
  tables = {
  },
}
