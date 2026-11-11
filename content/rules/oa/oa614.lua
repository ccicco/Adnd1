-- oa614: promoted from rules/oa/oacreating.h (the CREATING THE PLAYER CHARACTER, printed capture pp. 5-8 - the OA arc opener);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 614,
  "prefix" = "oa614",
  "banner" = {
      "title" = "CREATING THE PLAYER CHARACTER, printed capture pp. 5-8 - the OA arc opener",
      "provenance" = "census 536 -> 537.  verified against capture pp. 1-8 of the oa.pdf OCR session (315 capture pages, single Mistral-OCR capture; the book prints no page numbers in the capture margin so all cites are capture pages; contested cells settle book-internal first, then against the physical copy). THE OA GAP REPORT LANDS WITH THIS ROUND IN THE SAME COMMIT - the R564 MotP opener pattern: tools/oa_gap_report.md ships pre-flip (235 boxes, 0 closed) beside the spec, and the engine flips the opener boxes in place.  the gap census after this round: 4 closed, 231 open - the OA arc begins (R613b closed the DMO arc at 96/0 with the Chapter 2 parent flip; census 536 -> 537); NEXT - R615: the Chapter 1 ability tables (Tables 1-8) close on grid pins, prefix dgb, audit \"R615 OA ability tables audit\", include after rules/oa/oacreating.h",
    },
  "consts" = { {
      "name" = "dgaMethodCount",
      "value" = 4,
      "comment" = "the four PC generation methods offered for creating player characters (capture p. 6)",
    }, {
      "name" = "dgaWishLowCeiling",
      "value" = 15,
      "comment" = "the wish ladder boundary: a wish or alter reality raises a score of 3-15 by one full point (capture p. 6)",
    }, {
      "name" = "dgaWishesFrom16To17",
      "value" = 9,
      "comment" = "the printed wish example: nine more wishes are needed to reach 17 after the first one-tenth step (capture p. 6)",
    }, {
      "name" = "dgaPressLbsPerPoint",
      "value" = 10,
      "comment" = "the military-press yardstick: 10 pounds lifted per point of Strength (capture p. 7)",
    }, {
      "name" = "dgaBodyWeightCap",
      "value" = 2,
      "comment" = "the overhead ceiling: no human or humanoid presses more than twice its own body weight (capture p. 7)",
    }, {
      "name" = "dgaExceptionalLift",
      "value" = 470,
      "comment" = "the Strength 18/00 maximum military press in pounds (capture p. 7)",
    }, {
      "name" = "dgaBushiXpFloor",
      "value" = 15,
      "comment" = "the bushi Strength prime-requisite floor for the experience bonus (capture p. 7)",
    } },
  "bools" = { {
      "name" = "dgaMonkRetired",
      "value" = true,
      "comment" = "the preface doctrine: remove the monk from European-type campaigns - what is found herein is superior and in the proper surroundings (capture p. 3)",
    }, {
      "name" = "dgaKaraTurNamed",
      "value" = true,
      "comment" = "the Kara-Tur framework: the book names Shou Lung, T'i Lung and Kozakura as the modeled lands (capture p. 5)",
    }, {
      "name" = "dgaHonorThesis",
      "value" = true,
      "comment" = "the honor thesis: social skills and personal honor are as important as combat abilities (capture p. 5)",
    }, {
      "name" = "dgaMethodI",
      "value" = true,
      "comment" = "Method I: roll 4d6 discard the lowest, total the rest, six times, assign the six results freely (capture p. 6)",
    }, {
      "name" = "dgaMethodII",
      "value" = true,
      "comment" = "Method II: roll 3d6 twelve times, retain any six scores, assign as desired (capture p. 6)",
    }, {
      "name" = "dgaMethodIII",
      "value" = true,
      "comment" = "Method III: roll 3d6 six times, assign one result to Strength, then repeat per ability in order (capture p. 6)",
    }, {
      "name" = "dgaMethodIV",
      "value" = true,
      "comment" = "Method IV: roll 3d6 in ability order to create twelve characters, then choose the preferred one (capture p. 6)",
    }, {
      "name" = "dgaNpcAveraging",
      "value" = true,
      "comment" = "the run-of-the-mill NPC rule: roll 3d6 per ability, counting any 1 as 3 and any 6 as 4 (capture p. 6)",
    }, {
      "name" = "dgaNpcProfessionBoost",
      "value" = true,
      "comment" = "the special-character rule: profession abilities roll 3d6 with +1 added to each die that rolls 5 or less (capture p. 6)",
    }, {
      "name" = "dgaWishHighTenth",
      "value" = true,
      "comment" = "the wish rule above the boundary: scores of 16 or better rise only one-tenth of a point per wish (capture p. 6)",
    }, {
      "name" = "dgaWishBooksExempt",
      "value" = true,
      "comment" = "the wish exemption: magical books and devices can still raise scores of 16 or better a full point (capture p. 6)",
    }, {
      "name" = "dgaPressOrBodyWeight",
      "value" = true,
      "comment" = "the 18-Strength press: 180 pounds or own body weight, whichever is greater (capture p. 7)",
    }, {
      "name" = "dgaExceptionalLiftLadder",
      "value" = true,
      "comment" = "the exceptional-Strength lift ladder: 1 pound per percentage point 1-50, 4 pounds per point 51-90, 8 pounds per point 91-100 (capture p. 7)",
    }, {
      "name" = "dgaBushiXpBonus",
      "value" = true,
      "comment" = "the bushi prime requisite: Strength 15 or more earns a 10 percent experience bonus (capture p. 7)",
    }, {
      "name" = "dgaExceptionalClasses",
      "value" = true,
      "comment" = "the exceptional-Strength roll: samurai, kensai, barbarians and bushi with Strength 18 roll percentile dice (capture p. 7)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgaMethodCount']() != 4  or m['dgaWishLowCeiling']() != 15  or m['dgaWishesFrom16To17']() != 9  or m['dgaPressLbsPerPoint']() != 10  or m['dgaBodyWeightCap']() != 2  or m['dgaExceptionalLift']() != 470  or m['dgaBushiXpFloor']() != 15  or  m['dgaMonkRetired']() != 1  or  m['dgaKaraTurNamed']() != 1  or  m['dgaHonorThesis']() != 1  or  m['dgaMethodI']() != 1  or  m['dgaMethodII']() != 1  or  m['dgaMethodIII']() != 1  or  m['dgaMethodIV']() != 1  or  m['dgaNpcAveraging']() != 1  or  m['dgaNpcProfessionBoost']() != 1  or  m['dgaWishHighTenth']() != 1  or  m['dgaWishBooksExempt']() != 1  or  m['dgaPressOrBodyWeight']() != 1  or  m['dgaExceptionalLiftLadder']() != 1  or  m['dgaBushiXpBonus']() != 1  or  m['dgaExceptionalClasses']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgaMonkRetired']() != 1",
      "note" = "the dgaMonkRetired pin",
    }, {
      "expr" = "m['dgaKaraTurNamed']() != 1",
      "note" = "the dgaKaraTurNamed pin",
    }, {
      "expr" = "m['dgaHonorThesis']() != 1",
      "note" = "the dgaHonorThesis pin",
    }, {
      "expr" = "m['dgaMethodCount']() != 4",
      "note" = "the dgaMethodCount pin",
    }, {
      "expr" = "m['dgaMethodI']() != 1",
      "note" = "the dgaMethodI pin",
    }, {
      "expr" = "m['dgaMethodII']() != 1",
      "note" = "the dgaMethodII pin",
    }, {
      "expr" = "m['dgaMethodIII']() != 1",
      "note" = "the dgaMethodIII pin",
    }, {
      "expr" = "m['dgaMethodIV']() != 1",
      "note" = "the dgaMethodIV pin",
    }, {
      "expr" = "m['dgaNpcAveraging']() != 1",
      "note" = "the dgaNpcAveraging pin",
    }, {
      "expr" = "m['dgaNpcProfessionBoost']() != 1",
      "note" = "the dgaNpcProfessionBoost pin",
    }, {
      "expr" = "m['dgaWishLowCeiling']() != 15",
      "note" = "the dgaWishLowCeiling pin",
    }, {
      "expr" = "m['dgaWishHighTenth']() != 1",
      "note" = "the dgaWishHighTenth pin",
    }, {
      "expr" = "m['dgaWishesFrom16To17']() != 9",
      "note" = "the dgaWishesFrom16To17 pin",
    }, {
      "expr" = "m['dgaWishBooksExempt']() != 1",
      "note" = "the dgaWishBooksExempt pin",
    }, {
      "expr" = "m['dgaPressLbsPerPoint']() != 10",
      "note" = "the dgaPressLbsPerPoint pin",
    }, {
      "expr" = "m['dgaPressOrBodyWeight']() != 1",
      "note" = "the dgaPressOrBodyWeight pin",
    }, {
      "expr" = "m['dgaBodyWeightCap']() != 2",
      "note" = "the dgaBodyWeightCap pin",
    }, {
      "expr" = "m['dgaExceptionalLiftLadder']() != 1",
      "note" = "the dgaExceptionalLiftLadder pin",
    }, {
      "expr" = "m['dgaExceptionalLift']() != 470",
      "note" = "the dgaExceptionalLift pin",
    }, {
      "expr" = "m['dgaBushiXpFloor']() != 15",
      "note" = "the dgaBushiXpFloor pin",
    }, {
      "expr" = "m['dgaBushiXpBonus']() != 1",
      "note" = "the dgaBushiXpBonus pin",
    }, {
      "expr" = "m['dgaExceptionalClasses']() != 1",
      "note" = "the dgaExceptionalClasses pin",
    }, {
      "expr" = "m['dgaPressLbsPerPoint']() * 3 != 30  or m['dgaPressLbsPerPoint']() * 18 != 180",
      "note" = "the press yardstick consistency, Strength 3 and 18 (capture p. 7)",
    }, {
      "expr" = "m['dgaPressLbsPerPoint']() * 18 + 290 !=m['dgaExceptionalLift']()",
      "note" = "the exceptional ladder sums to the 18/00 press (capture p. 7)",
    }, {
      "expr" = "m['dgaWishLowCeiling']() + 1 != 16  or m['dgaWishesFrom16To17']() + 1 != 10",
      "note" = "the wish ladder boundary cross-check (capture p. 6)",
    } },
  "audit" = {
      "label" = "R614 OA opener audit",
      "comment" = "OA round one (capture pp. 1-8): the arc opener - the front-matter doctrine (the monk retirement, the Kara-Tur naming, the honor thesis), the four generation methods with the NPC rules and the wish ladder, and the Strength yardstick with its exceptional-Strength ladder.",
    },
}
