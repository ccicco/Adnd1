-- encounter table def: psionic_table
-- The R66 psionic family (R1037 de-wire): the PSIONIC ENCOUNTER TABLE
-- (DMG Appendix C Premium reprint p.182, OCR-verified).
-- band = the percentile column; key = the bestiary key or the printed pseudo-key (the PSI_* demon/devil rows resolve through the R1036 planar pick-sets on the second percentile; PSI_MEN builds a character party); numbers = the printed Numbers column (0,0 marks the Men party and the yellow mold dash - the engine handles both). primeOnly is always false here (the psionic table prints no (*) footnote) but rides the shared planar row shape.
-- DO NOT hand-edit: tools/r1037_splice.py is the only writer.

return {
  key = "psionic_table",
  rows = {
    { band = {1,5}, key = "brain_mole", numbers = {1,3}, primeOnly = false },
    { band = {6,12}, key = "cerebral_parasite", numbers = {3,12}, primeOnly = false },
    { band = {13,15}, key = "couatl", numbers = {1,4}, primeOnly = false },
    { band = {16,18}, key = "PSI_DEMON_MAJOR", numbers = {1,2}, primeOnly = false },
    { band = {19,24}, key = "PSI_DEMON_MINOR", numbers = {1,4}, primeOnly = false },
    { band = {25,26}, key = "PSI_DEMON_PRINCE", numbers = {1,1}, primeOnly = false },
    { band = {27,28}, key = "PSI_DEVIL_ARCH", numbers = {1,1}, primeOnly = false },
    { band = {29,34}, key = "PSI_DEVIL_GREATER", numbers = {1,2}, primeOnly = false },
    { band = {35,38}, key = "gray_ooze", numbers = {1,3}, primeOnly = false },
    { band = {39,48}, key = "intellect_devourer", numbers = {1,2}, primeOnly = false },
    { band = {49,51}, key = "ki_rin", numbers = {1,1}, primeOnly = false },
    { band = {52,56}, key = "lich", numbers = {1,1}, primeOnly = false },
    { band = {57,62}, key = "PSI_MEN", numbers = {0,0}, primeOnly = false },
    { band = {63,69}, key = "mind_flayer", numbers = {1,4}, primeOnly = false },
    { band = {70,72}, key = "yellow_mold", numbers = {0,0}, primeOnly = false },
    { band = {73,82}, key = "shedu", numbers = {2,8}, primeOnly = false },
    { band = {83,92}, key = "su_monster", numbers = {1,12}, primeOnly = false },
    { band = {93,98}, key = "titan", numbers = {1,2}, primeOnly = false },
    { band = {99,100}, key = "triton", numbers = {10,60}, primeOnly = false },
  },
}
