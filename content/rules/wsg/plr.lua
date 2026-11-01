-- plr: promoted from tools/spec_r479.json (the R479: the WSG PLANT LORE PROFICIENCY slice, printed p. 70 - the ninth camping-arc round, a pure prose round with NO table, the short bridge section between the Table 40 availability pin (R478) and the injuries and treatment chapter: the party survival benefit, the no-vegetation bar, the greater-chance-in-greenery rule and the pointer to the Wilderness Proficiencies section.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 479,
  "prefix" = "plr",
  "banner" = {
      "title" = "R479: the WSG PLANT LORE PROFICIENCY slice, printed p. 70 - the ninth camping-arc round, a pure prose round with NO table, the short bridge section between the Table 40 availability pin (R478) and the injuries and treatment chapter: the party survival benefit, the no-vegetation bar, the greater-chance-in-greenery rule and the pointer to the Wilderness Proficiencies section.",
      "provenance" = "The settle: two-way clean on the first pass - the tesseract full-text read and the pdfy layout read agree on every word of the section, and the tsv confirms the heading geometry; no contested cells, no vision reads needed. The section carries no numbers at all - only qualifications, pinned as bools.",
      "sentinel" = "This is a qualification-only round: five bools, no consts, no grids - the audit proves each qualification pinned exactly once.",
    },
  "consts" = {},
  "bools" = { {
      "name" = "plrAidsPartySurvival",
      "value" = true,
      "comment" = "a party without ready access to healing and curing magic has increased chances of survival if it contains someone with proficiency in plant lore",
    }, {
      "name" = "plrSafeguardsLostAid",
      "value" = true,
      "comment" = "the proficiency is also sought to safeguard against losing healing and curing aid along the way",
    }, {
      "name" = "plrNoVegetationNoFind",
      "value" = true,
      "comment" = "such a character cannot locate vegetation where it does not exist",
    }, {
      "name" = "plrGreaterChanceInGreenery",
      "value" = true,
      "comment" = "if there is greenery to search through, a proficient character has a greater chance of finding the type of plant desired",
    }, {
      "name" = "plrBenefitsInWildernessProficiencies",
      "value" = true,
      "comment" = "the benefits such a character brings to the party are detailed in the section on Wilderness Proficiencies",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = {},
  "audit" = {
      "label" = "R479 WSG plant lore pin audit",
      "comment" = "The proficiency in plant lore prose: a party venturing into the wilderness without ready access to healing and curing magic, or safeguarding against losing that aid along the way, has increased chances of survival if it contains someone with the proficiency; such a character cannot locate vegetation where it does not exist; but if there is greenery to search through, a proficient character has a greater chance of finding the type of plant desired - with the benefits detailed in the Wilderness Proficiencies section.",
    },
}
