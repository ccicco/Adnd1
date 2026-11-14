-- encounter table def: city_counts
-- The R64 city family (R1035 de-wire): extracted verbatim from
-- the retired cityCountFor dice expressions of dm/encounters.cpp (DMG Appendix C
-- Premium reprint p.190-192, OCR-verified; the R146/R174 flavor
-- records 1eonline.info-verified). dice = {n, d, plus} rolls plus + nDd; nightDice replaces dice at night; fixed = a printed constant; an absent key rolls one specimen (the engine fallthrough). The bard entry is dead code in the retired engine (monk_or_bard resolves on the party path first) - preserved verbatim, documented.
-- DO NOT hand-edit: tools/r1035_splice.py is the only writer.

return {
  key = "city_counts",
  rows = {
    { key = "bandit", dice = {1,10,2} },
    { key = "beggar", dice = {1,2,0} },
    { key = "doppelganger", dice = {1,4,2} },
    { key = "giant_rat", dice = {2,4,0}, nightDice = {1,24,1} },
    { key = "ghoul", dice = {1,13,4} },
    { key = "ghast", dice = {1,13,4} },
    { key = "drunk", dice = {1,4,0} },
    { key = "gentleman", dice = {1,5,0} },
    { key = "laborer", dice = {1,11,2} },
    { key = "peddler", fixed = 1 },
    { key = "mercenary", dice = {1,11,2} },
    { key = "merchant", dice = {1,3,0} },
    { key = "bard", fixed = 1 },
    { key = "night_hag", dice = {1,2,0} },
    { key = "noble", fixed = 1 },
    { key = "pilgrim", dice = {1,11,2} },
    { key = "press_gang", dice = {1,16,1} },
    { key = "rakshasa", dice = {1,3,0} },
    { key = "ruffian", dice = {1,6,6} },
    { key = "shadow", dice = {1,7,2} },
    { key = "spectre", dice = {1,3,0} },
    { key = "tradesman", dice = {2,4,0} },
    { key = "wererat", dice = {1,4,2} },
    { key = "weretiger", dice = {1,2,0} },
    { key = "werewolf", dice = {1,4,2} },
    { key = "wight", dice = {1,4,2} },
    { key = "will_o_wisp", dice = {1,2,0} },
    { key = "wraith", dice = {1,4,0} },
  },
}
