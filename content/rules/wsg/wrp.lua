-- wrp: promoted from tools/spec_r441.json (the The WSG ROPING TOGETHER, R441: the cascade prose (no table this round) - if two or more characters are roped together on a climb and one fails a Climbing Check, the character or characters adjacent to the one who fell must make additional successful Climbing Checks (even if they had just made a successful check earlier in the same round) to keep from being pulled off the slope or cliff face and also falling; a fallen end character forces a check only on his one neighbor, a fallen middle character forces checks on both sides; for each character who fails beyond the first the adjacent checks take a -10% penalty to their Climbing Ratings per extra fallen character, until characters on either side succeed or the entire group has fallen; if the last two characters both check at the same time and only one succeeds, that character makes one more check to keep the entire group from falling. The example: five characters on a 200-foot rope (a 50-foot rope ties two together, one more per additional 50 feet) - the cascade reaches -10, -20 and -30 percent. Census 365 -> 366.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 441,
  "prefix" = "wrp",
  "banner" = {
      "title" = "The WSG ROPING TOGETHER, R441: the cascade prose (no table this round) - if two or more characters are roped together on a climb and one fails a Climbing Check, the character or characters adjacent to the one who fell must make additional successful Climbing Checks (even if they had just made a successful check earlier in the same round) to keep from being pulled off the slope or cliff face and also falling; a fallen end character forces a check only on his one neighbor, a fallen middle character forces checks on both sides; for each character who fails beyond the first the adjacent checks take a -10% penalty to their Climbing Ratings per extra fallen character, until characters on either side succeed or the entire group has fallen; if the last two characters both check at the same time and only one succeeds, that character makes one more check to keep the entire group from falling. The example: five characters on a 200-foot rope (a 50-foot rope ties two together, one more per additional 50 feet) - the cascade reaches -10, -20 and -30 percent. Census 365 -> 366.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 37; the user own copy OCR cross-checked against the archive djvu word layer (Guide_0037.djvu) - the section reads CLEAN in the djvu, every number (the 50-foot tie capacity, the 200-foot rope, the five characters, the -10/-20/-30 cascade) matched exactly; no eye-reads were needed. Scope note: the tie-capacity rule sits in the USING ROPE: BELAYING intro but is the roping-together enabler, so it lands here; the climbing-rope stats and the knot rules stay for the belaying round.",
      "sentinel" = "A 50-foot rope will suffice to tie two characters together, and another character can be added to the string for every additional 50 feet of rope. For each character who fails his Climbing Check beyond the first, the adjacent characters check at a -10% penalty per extra fallen character - the five-character example on a 200-foot rope cascades through -10, -20 and -30 percent.",
    },
  "consts" = { {
      "name" = "wrpTieTwoCharFt",
      "value" = 50,
      "comment" = "A 50-foot rope will suffice to tie two characters together.",
    }, {
      "name" = "wrpExtraCharPerFt",
      "value" = 50,
      "comment" = "Another character can be added to the string for every additional 50 feet of rope in the coil.",
    }, {
      "name" = "wrpCascadeStepPct",
      "value" = 10,
      "comment" = "For each character who fails his Climbing Check beyond the first, the adjacent character(s) must make Climbing Checks with a -10% penalty to their Climbing Ratings.",
    }, {
      "name" = "wrpExamplePartySize",
      "value" = 5,
      "comment" = "Five characters are strung together on the example rope, attempting to scale a cliff face.",
    }, {
      "name" = "wrpExampleRopeFt",
      "value" = 200,
      "comment" = "The example rope is 200 feet long - exactly what five roped characters need: 50 feet for two, plus 50 more for each additional character.",
    } },
  "bools" = { {
      "name" = "wrpAdjacentMustRecheck",
      "value" = true,
      "comment" = "The characters adjacent to the one who fell must make additional successful Climbing Checks even if they had just made a successful check earlier in the same round.",
    }, {
      "name" = "wrpEndFallerOneAdjacent",
      "value" = true,
      "comment" = "If a character on either end of the rope falls, only the character adjacent to him needs to make a Climbing Check.",
    }, {
      "name" = "wrpMiddleFallerBothSides",
      "value" = true,
      "comment" = "If a character in the middle of the group falls, the climbers on both sides must make successful checks to halt his fall.",
    }, {
      "name" = "wrpCascadeUntilHaltOrAll",
      "value" = true,
      "comment" = "The process continues until characters on either side make successful Climbing Checks, or until everyone in the group fails a Climbing Check - which means the entire group has fallen.",
    }, {
      "name" = "wrpLastPairSingleSuccessExtra",
      "value" = true,
      "comment" = "If the last two characters in a group are both required to make checks at the same time and only one of them succeeds, the successful character must make one more check to keep the entire group from falling.",
    } },
  "switches" = { {
      "name" = "wrpCascadePenaltyPct",
      "values" = { 0, 10, 20, 30, 40 },
      "default" = 40,
      "comment" = "The penalty to the adjacent climbers Climbing Ratings, by the number of fallen characters BEYOND the first: 0 with only one fallen, and -10% more for each extra fallen character - -10% with two fallen, -20% with three, -30% with four, -40% beyond five.",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['wrpTieTwoCharFt']() != 50 or m['wrpExtraCharPerFt']() != 50",
      "note" = "the tie capacity: a 50-foot rope ties two characters, one more per additional 50 feet",
    }, {
      "expr" = "(m['wrpExamplePartySize']() - 1) * m['wrpExtraCharPerFt']() != m['wrpExampleRopeFt']()",
      "note" = "the example party: five roped characters need (5-1) x 50 = 200 feet of rope - the 200-foot rope of the example",
    }, {
      "expr" = "m['wrpCascadePenaltyPct'](0) != 0 or m['wrpCascadePenaltyPct'](1) != 10 or m['wrpCascadePenaltyPct'](2) != 20 or m['wrpCascadePenaltyPct'](3) != 30 or m['wrpCascadePenaltyPct'](4) != 40",
      "note" = "the cascade ladder: one fallen 0, two fallen -10%, three -20%, four -30%, five -40%",
    }, {
      "expr" = "m['wrpCascadePenaltyPct'](1) != m['wrpCascadeStepPct']()",
      "note" = "the example first step: with two fallen (one beyond the first) the third character checks at the -10% step",
    }, {
      "expr" = "m['wrpCascadePenaltyPct'](2) != 2 * m['wrpCascadeStepPct']() or m['wrpCascadePenaltyPct'](3) != 3 * m['wrpCascadeStepPct']()",
      "note" = "the example deep cells: three fallen - the -20% checks of the first and fifth characters; four fallen - the -30% final check",
    } },
  "audit" = {
      "label" = "R441 WSG roping-together pin audit",
      "comment" = "The roping-together slice pins the adjacent-recheck rule (even after a successful check earlier in the same round), the end/middle faller rules, the -10%-per-extra-faller cascade penalty ladder (0/10/20/30/40), the last-pair extra check and the 50-feet-per-character tie capacity (rules/wsgtog.h, prefix wrp); census 365 -> 366.",
    },
}
