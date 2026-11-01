-- dcm: promoted from tools/spec_r560.json (the THE DSG INDEX - the printed pp. 127-128 roster closing the book: the alphabetical topic list whose every page reference lands on a chapter this arc already pinned, from Ability Check (p. 12) through World design (p. 100), with the see-cross-references and the four underdark theories.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 560,
  "prefix" = "dcm",
  "banner" = {
      "title" = "THE DSG INDEX - the printed pp. 127-128 roster closing the book: the alphabetical topic list whose every page reference lands on a chapter this arc already pinned, from Ability Check (p. 12) through World design (p. 100), with the see-cross-references and the four underdark theories.",
      "provenance" = "from the DSG index, printed pp. 127-128, djvu lines 15866-16247, every entry cross-checked against the landed rounds page ranges; the roster references no page outside the pp. 6-128 book.",
      "sentinel" = "the roster is the arc own mirror: the DSG gap report and the index close together, the back-cover blurb the only prose past it.",
    },
  "consts" = { {
      "name" = "dcmIndexFirstPage",
      "value" = 12,
      "comment" = "the index opens at Ability Check, printed p. 12 - the R504 movement chapter era; the roster runs A (Ability Check) through W (World design, p. 100) across the printed pp. 127-128 spread.",
    }, {
      "name" = "dcmMappingPage",
      "value" = 114,
      "comment" = "the Mapping entry refs p. 114 with its geomorphic (117), orthographic and perspective subheads - the R557 mapping chapter and the R559 plates it served.",
    }, {
      "name" = "dcmMoralPage",
      "value" = 109,
      "comment" = "the story elements moral subhead refs p. 109 - the R553 tail closing the elements, with the story types and the storytelling techniques (pace, voice) subheads at pp. 109/112.",
    }, {
      "name" = "dcmTheoryCount",
      "value" = 4,
      "comment" = "four underdark theories indexed at p. 71: Hollow Earth, Isolated Pockets, Partial Connections and Swiss Cheese - the R-era underground environment chapter.",
    } },
  "bools" = { {
      "name" = "dcmSeeCrossRefs",
      "value" = true,
      "comment" = "the index uses see-cross-references: Illithids see Mind flayers, Smell see Odor detection - the roster routes the reader instead of double-listing.",
    }, {
      "name" = "dcmPlayerTypesIndexed",
      "value" = true,
      "comment" = "Types of players and the Role-Players / Problem-Solvers subheads are indexed at p. 99 - the R550 campaign opener.",
    }, {
      "name" = "dcmEquipmentRangeIndexed",
      "value" = true,
      "comment" = "the Equipment entry refs the pp. 56-58 range with its proficiency-equipment subhead at p. 58 - the landed new-equipment chapter.",
    }, {
      "name" = "dcmBackCoverPastIndex",
      "value" = true,
      "comment" = "the back-cover blurb (the Niles quote and the TSR addresses) follows the index - the book ends at printed p. 128, the arc's final census boundary.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the Ability Check roster head at p. 12",
      "expr" = "m['dcmIndexFirstPage']() != 12",
    }, {
      "note" = "the mapping chapter ref at p. 114",
      "expr" = "m['dcmMappingPage']() != 114",
    }, {
      "note" = "the story-elements moral ref at p. 109",
      "expr" = "m['dcmMoralPage']() != 109",
    }, {
      "note" = "the four underdark theories at p. 71",
      "expr" = "m['dcmTheoryCount']() != 4",
    }, {
      "note" = "the see cross-references route the roster",
      "expr" = "m['dcmSeeCrossRefs']() != 1",
    }, {
      "note" = "the player types ref at p. 99",
      "expr" = "m['dcmPlayerTypesIndexed']() != 1",
    }, {
      "note" = "the equipment range ref pp. 56-58",
      "expr" = "m['dcmEquipmentRangeIndexed']() != 1",
    }, {
      "note" = "the back-cover blurb past the index",
      "expr" = "m['dcmBackCoverPastIndex']() != 1",
    } },
  "audit" = {
      "label" = "R560 DSG index audit",
      "comment" = "the index roster: every pinned page reference lands on a chapter this arc already pinned - Ability Check p. 12, Mapping p. 114, the moral p. 109, the four theories p. 71, the equipment range pp. 56-58, the player types p. 99, the see-cross-references routing the roster, and the back-cover blurb past the index closing the book at printed p. 128.",
    },
}
