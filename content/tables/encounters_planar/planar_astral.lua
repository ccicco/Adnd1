-- encounter table def: planar_astral
-- The R65 planar family (R1036 de-wire): the ASTRAL encounter table
-- (DMG Appendix C Premium reprint p.181, OCR-verified).
-- band = the percentile column; key = the bestiary key or the printed pseudo-key (the PLANAR_* rows resolve through the pick-sets); numbers = the printed Numbers column (uniform lo..hi; 0,0 marks the traveller, which builds a party instead); primeOnly = the (*) footnote: prime-material perception creatures appear only when the encounter allows effect to extend from the Prime Material Plane - the caller re-rolls otherwise.
-- DO NOT hand-edit: tools/r1036_splice.py is the only writer.

return {
  key = "planar_astral",
  rows = {
    { band = {1,4}, key = "aerial_servant", numbers = {1,1}, primeOnly = false },
    { band = {5,10}, key = "basilisk", numbers = {1,2}, primeOnly = true },
    { band = {11,13}, key = "cockatrice", numbers = {1,4}, primeOnly = true },
    { band = {14,16}, key = "PLANAR_DEMON_MAJOR", numbers = {1,1}, primeOnly = false },
    { band = {17,22}, key = "PLANAR_DEMON_MINOR", numbers = {1,3}, primeOnly = false },
    { band = {23,23}, key = "PLANAR_DEMON_PRINCE", numbers = {1,1}, primeOnly = false },
    { band = {24,24}, key = "PLANAR_DEVIL_ARCH", numbers = {1,1}, primeOnly = false },
    { band = {25,28}, key = "PLANAR_DEVIL_GREATER", numbers = {1,1}, primeOnly = false },
    { band = {29,37}, key = "PLANAR_DEVIL_LESSER", numbers = {1,3}, primeOnly = false },
    { band = {38,38}, key = "chromatic_dragon", numbers = {1,1}, primeOnly = false },
    { band = {39,39}, key = "platinum_dragon", numbers = {1,1}, primeOnly = false },
    { band = {40,41}, key = "gorgon", numbers = {1,2}, primeOnly = true },
    { band = {42,46}, key = "PLANAR_TRAVELLER", numbers = {0,0}, primeOnly = false },
    { band = {47,49}, key = "intellect_devourer", numbers = {1,2}, primeOnly = false },
    { band = {50,55}, key = "invisible_stalker", numbers = {1,3}, primeOnly = false },
    { band = {56,61}, key = "ki_rin", numbers = {1,1}, primeOnly = false },
    { band = {62,63}, key = "medusa", numbers = {1,2}, primeOnly = true },
    { band = {64,71}, key = "night_hag", numbers = {1,4}, primeOnly = false },
    { band = {72,74}, key = "nightmare", numbers = {1,4}, primeOnly = false },
    { band = {75,79}, key = "rakshasa", numbers = {1,3}, primeOnly = false },
    { band = {80,91}, key = "shedu", numbers = {2,5}, primeOnly = false },
    { band = {92,92}, key = "PLANAR_TITAN_ELDER", numbers = {1,1}, primeOnly = false },
    { band = {93,97}, key = "PLANAR_TITAN_LESSER", numbers = {1,1}, primeOnly = false },
    { band = {98,100}, key = "PLANAR_TITAN_MAJOR", numbers = {1,1}, primeOnly = false },
  },
}
