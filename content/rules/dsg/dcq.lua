-- dcq: promoted from tools/spec_r562.json (the THE DSG WHAT-IS-IT FRONT MATTER - the printed p. 6 chapter frame opening the book: the mystery of the underdark, the new rules for underground play, the denizens of the underdark, the underground campaign and the using-this-information player/DM split - the parent and all five children closed in one round.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 562,
  "prefix" = "dcq",
  "banner" = {
      "title" = "THE DSG WHAT-IS-IT FRONT MATTER - the printed p. 6 chapter frame opening the book: the mystery of the underdark, the new rules for underground play, the denizens of the underdark, the underground campaign and the using-this-information player/DM split - the parent and all five children closed in one round.",
      "provenance" = "from the DSG chapter on printed p. 6, djvu lines 466-585, between the credits and the Overview of the Underdark (the R503 extraction round); every promise cross-checked against the chapter that later lands it - the climbing and proficiencies the movement chapter, the cultures the R532 round, the generators the R533 Deepearth frame, the 3-D mapping the R557 doctrine.",
      "sentinel" = "the front-matter frame is the arc's own table of contents in prose: each subhead is a promise the landed rounds already keep.",
    },
  "consts" = { {
      "name" = "dcqFramePage",
      "value" = 6,
      "comment" = "the chapter sits on printed p. 6 between the credits and the Overview of the Underdark - the front-matter frame opening the whole book.",
    }, {
      "name" = "dcqNamedCultureCount",
      "value" = 4,
      "comment" = "the denizens subhead names four cultures - the drow, duergar, kuo-toa and myconids revealed in their natural environments - the cultures the R532 chapter later lands in full.",
    }, {
      "name" = "dcqSectionCount",
      "value" = 2,
      "comment" = "the book splits into two sections: the first for player and DM alike (the expanded rules, the spells, the proficiencies, the new equipment), the latter tailored to the DM alone.",
    }, {
      "name" = "dcqPlayerLureCount",
      "value" = 3,
      "comment" = "the mystery subhead counts three subterranean lures beneath the earth - the most fearsome foes, the most fabulous treasures and the most mysterious locales.",
    } },
  "bools" = { {
      "name" = "dcqNonthiefClimbCovered",
      "value" = true,
      "comment" = "the new-rules subhead asks whether a non-thief can climb a rough stone wall, fight while clinging to the wall, or duel atop a swaying footbridge - all covered by the rules this book introduces (the movement chapter era).",
    }, {
      "name" = "dcqProficienciesFromOA",
      "value" = true,
      "comment" = "the proficiencies were first introduced in the AD&D Oriental Adventures book; the DSG reintroduces them and adds many more suited to the underearth.",
    }, {
      "name" = "dcqRandomGenerators",
      "value" = true,
      "comment" = "the denizens subhead promises the detailed random location and encounter generators - exciting adventuring with little or no preparation time (the Deepearth R533 generators).",
    }, {
      "name" = "dcqForbiddenDMHalf",
      "value" = true,
      "comment" = "the using-this-information subhead marks the latter portion the DM's Forbidden Territory - players should avoid it or face the wrath of the DM.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the frame chapter at printed p. 6",
      "expr" = "m['dcqFramePage']() != 6",
    }, {
      "note" = "the four named denizen cultures",
      "expr" = "m['dcqNamedCultureCount']() != 4",
    }, {
      "note" = "the two player/DM sections",
      "expr" = "m['dcqSectionCount']() != 2",
    }, {
      "note" = "the three subterranean lures",
      "expr" = "m['dcqPlayerLureCount']() != 3",
    }, {
      "note" = "the non-thief wall and footbridge rules",
      "expr" = "m['dcqNonthiefClimbCovered']() != 1",
    }, {
      "note" = "the Oriental Adventures proficiency origin",
      "expr" = "m['dcqProficienciesFromOA']() != 1",
    }, {
      "note" = "the random generators with no prep time",
      "expr" = "m['dcqRandomGenerators']() != 1",
    }, {
      "note" = "the DM-only Forbidden Territory",
      "expr" = "m['dcqForbiddenDMHalf']() != 1",
    } },
  "audit" = {
      "label" = "R562 DSG intro frame audit",
      "comment" = "the printed p. 6 chapter frame: the mystery of the underdark (the sunless realms question), the new rules for underground play (the non-thief climbing, the Oriental Adventures proficiencies), the denizens (the four named cultures, the random generators), the underground campaign (the DM half, the 3-D mapping, the story conflicts) and the using-this-information player/DM split with the Forbidden Territory.",
    },
}
