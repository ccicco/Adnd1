-- encounter table def: planar_ethereal
-- The R65 planar family (R1036 de-wire): the ETHEREAL encounter table
-- (DMG Appendix C Premium reprint p.181, OCR-verified).
-- band = the percentile column; key = the bestiary key or the printed pseudo-key (the PLANAR_* rows resolve through the pick-sets); numbers = the printed Numbers column (uniform lo..hi; 0,0 marks the traveller, which builds a party instead); primeOnly = the (*) footnote: prime-material perception creatures appear only when the encounter allows effect to extend from the Prime Material Plane - the caller re-rolls otherwise.
-- DO NOT hand-edit: tools/r1036_splice.py is the only writer.

return {
  key = "planar_ethereal",
  rows = {
    { band = {1,5}, key = "aerial_servant", numbers = {1,1}, primeOnly = false },
    { band = {6,10}, key = "basilisk", numbers = {1,2}, primeOnly = true },
    { band = {11,13}, key = "cockatrice", numbers = {1,4}, primeOnly = true },
    { band = {14,18}, key = "couatl", numbers = {1,4}, primeOnly = false },
    { band = {19,26}, key = "djinni", numbers = {1,6}, primeOnly = false },
    { band = {27,27}, key = "chromatic_dragon", numbers = {1,1}, primeOnly = false },
    { band = {28,28}, key = "platinum_dragon", numbers = {1,1}, primeOnly = false },
    { band = {29,30}, key = "efreeti", numbers = {1,3}, primeOnly = false },
    { band = {31,37}, key = "air_elemental", numbers = {1,1}, primeOnly = false },
    { band = {38,39}, key = "earth_elemental", numbers = {1,1}, primeOnly = false },
    { band = {40,41}, key = "fire_elemental", numbers = {1,1}, primeOnly = false },
    { band = {42,42}, key = "water_elemental", numbers = {1,1}, primeOnly = false },
    { band = {43,48}, key = "ghost", numbers = {1,1}, primeOnly = false },
    { band = {49,50}, key = "gorgon", numbers = {1,2}, primeOnly = true },
    { band = {51,52}, key = "groaning_spirit", numbers = {1,2}, primeOnly = false },
    { band = {53,57}, key = "PLANAR_TRAVELLER", numbers = {0,0}, primeOnly = false },
    { band = {58,59}, key = "intellect_devourer", numbers = {1,2}, primeOnly = false },
    { band = {60,62}, key = "invisible_stalker", numbers = {1,3}, primeOnly = false },
    { band = {63,68}, key = "ki_rin", numbers = {1,1}, primeOnly = false },
    { band = {69,76}, key = "lammasu", numbers = {2,8}, primeOnly = false },
    { band = {77,78}, key = "medusa", numbers = {1,2}, primeOnly = true },
    { band = {79,80}, key = "nightmare", numbers = {1,4}, primeOnly = false },
    { band = {81,82}, key = "salamander", numbers = {2,5}, primeOnly = false },
    { band = {83,87}, key = "phase_spider", numbers = {1,6}, primeOnly = false },
    { band = {88,94}, key = "thought_eater", numbers = {1,3}, primeOnly = false },
    { band = {95,97}, key = "wind_walker", numbers = {2,5}, primeOnly = false },
    { band = {98,100}, key = "xorn", numbers = {3,6}, primeOnly = false },
  },
}
