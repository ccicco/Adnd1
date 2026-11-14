-- encounter table def: appendixp_kit
-- The DMG Appendix P convention party (R1040 de-wire): the kit builder chances (p.225)
-- (DMG pp.225-226, 1eonline.info compilation, OCR-verified).
-- class = the engine class (1-4); armorPct/weaponPct = the "only one sort" kit chances; shieldPct = the shield try (the armored classes fighter and cleric at 10%, the others none - printed as no shield).
-- DO NOT hand-edit: tools/r1040_splice.py is the only writer.

return {
  key = "appendixp_kit",
  rows = {
    { class = 1, armorPct = 10, weaponPct = 10, shieldPct = 10 },
    { class = 2, armorPct = 15, weaponPct = 15, shieldPct = 0 },
    { class = 3, armorPct = 8, weaponPct = 12, shieldPct = 10 },
    { class = 4, armorPct = 10, weaponPct = 11, shieldPct = 0 },
  },
}
