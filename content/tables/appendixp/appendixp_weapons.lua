-- encounter table def: appendixp_weapons
-- The DMG Appendix P convention party (R1040 de-wire): the WEAPONS chances (p.225-226)
-- (DMG pp.225-226, 1eonline.info compilation, OCR-verified).
-- col = the printed column in order (protective: shield, plate, banded, chain, leather, ring of protection, bracers; weapons: dagger, sword, mace, battle axe, spear, bow, the 15 bolts +2); the four fields = the per-class chance at percent (a printed dash encodes as 0).
-- DO NOT hand-edit: tools/r1040_splice.py is the only writer.

return {
  key = "appendixp_weapons",
  rows = {
    { col = 1, fighter = 10, magic_user = 15, cleric = 0, thief = 12 },
    { col = 2, fighter = 10, magic_user = 0, cleric = 0, thief = 11 },
    { col = 3, fighter = 0, magic_user = 0, cleric = 12, thief = 0 },
    { col = 4, fighter = 7, magic_user = 0, cleric = 0, thief = 0 },
    { col = 5, fighter = 8, magic_user = 0, cleric = 0, thief = 0 },
    { col = 6, fighter = 1, magic_user = 0, cleric = 0, thief = 0 },
    { col = 7, fighter = 10, magic_user = 0, cleric = 0, thief = 0 },
  },
}
