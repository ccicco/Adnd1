-- encounter table def: appendixp_protective
-- The DMG Appendix P convention party (R1040 de-wire): the PROTECTIVE ITEMS chances (p.225)
-- (DMG pp.225-226, 1eonline.info compilation, OCR-verified).
-- col = the printed column in order (protective: shield, plate, banded, chain, leather, ring of protection, bracers; weapons: dagger, sword, mace, battle axe, spear, bow, the 15 bolts +2); the four fields = the per-class chance at percent (a printed dash encodes as 0).
-- DO NOT hand-edit: tools/r1040_splice.py is the only writer.

return {
  key = "appendixp_protective",
  rows = {
    { col = 1, fighter = 10, magic_user = 0, cleric = 10, thief = 0 },
    { col = 2, fighter = 6, magic_user = 0, cleric = 5, thief = 0 },
    { col = 3, fighter = 8, magic_user = 0, cleric = 6, thief = 0 },
    { col = 4, fighter = 10, magic_user = 0, cleric = 8, thief = 0 },
    { col = 5, fighter = 0, magic_user = 0, cleric = 0, thief = 10 },
    { col = 6, fighter = 0, magic_user = 15, cleric = 2, thief = 4 },
    { col = 7, fighter = 0, magic_user = 4, cleric = 0, thief = 0 },
  },
}
