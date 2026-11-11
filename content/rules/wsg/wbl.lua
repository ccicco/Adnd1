-- wbl: promoted from tools/spec_r443.json (the The WSG BELAYING, R443: the belay prose (no table this round) - a climbing rope is 150 or 200 feet long and half an inch in diameter, with a weight limit of 2000 pounds, subject to the weakening and breaking rules; a rope can tie a group together so a fall can be arrested, and only a rope-use proficient character can knot two ropes at full strength - anyone else reduces the held weight by 500 pounds, and two different diameters take the smaller limit minus 500. Belaying itself: the belayed character has a rope end tied securely around his body, the belayer pays out the rope with just a small amount of slack (reversed, pulling in, for an ascent); if the climber falls, the belayer halts the fall with a successful Climbing Check - failure means the climber falls the full distance, success means no farther than the length of the rope. A precarious belayer (handholds and footholds only) who halts the fall must make a SECOND check against the jolt of the rope going taut - failure drops both; a secure belayer (a plateau or wide ledge) needs no second check. A string of pairs can belay in sequence - the last character cannot belay, the leader cannot be belayed, only one belay at a time, no climbing while belaying - slow but safer; a middle faller drags no one below, a failed belayer can be saved by the character above belaying him, but nothing can help the first character who fell, since only two characters are connected to the same rope. Census 367 -> 368.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 443,
  "prefix" = "wbl",
  "banner" = {
      "title" = "The WSG BELAYING, R443: the belay prose (no table this round) - a climbing rope is 150 or 200 feet long and half an inch in diameter, with a weight limit of 2000 pounds, subject to the weakening and breaking rules; a rope can tie a group together so a fall can be arrested, and only a rope-use proficient character can knot two ropes at full strength - anyone else reduces the held weight by 500 pounds, and two different diameters take the smaller limit minus 500. Belaying itself: the belayed character has a rope end tied securely around his body, the belayer pays out the rope with just a small amount of slack (reversed, pulling in, for an ascent); if the climber falls, the belayer halts the fall with a successful Climbing Check - failure means the climber falls the full distance, success means no farther than the length of the rope. A precarious belayer (handholds and footholds only) who halts the fall must make a SECOND check against the jolt of the rope going taut - failure drops both; a secure belayer (a plateau or wide ledge) needs no second check. A string of pairs can belay in sequence - the last character cannot belay, the leader cannot be belayed, only one belay at a time, no climbing while belaying - slow but safer; a middle faller drags no one below, a failed belayer can be saved by the character above belaying him, but nothing can help the first character who fell, since only two characters are connected to the same rope. Census 367 -> 368.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 37; the user own copy OCR cross-checked against the archive djvu word layer (Guide_0037.djvu, with the paired-belay continuation at the head of Guide_0038.djvu) - the section reads CLEAN, every number (the 150/200 feet, the half inch, the 2000 pounds, the 500-pound knot penalty, the two checks) matched exactly; no eye-reads were needed.",
      "sentinel" = "The belayer halts a fall with a successful Climbing Check: failure drops the climber the full distance, success bounds the fall by the rope length. A precarious belayer who halts the fall makes a second check against the jolt - failure drops both; a secure belayer skips it. Only two characters share a rope: the first faller cannot be helped, and the climbing rope holds 2000 pounds minus 500 for an amateur knot.",
    },
  "consts" = { {
      "name" = "wblClimbRopeMinFt",
      "value" = 150,
      "comment" = "A climbing rope is 150 or 200 feet long and half an inch in diameter.",
    }, {
      "name" = "wblClimbRopeMaxFt",
      "value" = 200,
      "comment" = "A climbing rope is 150 or 200 feet long - the 200-foot rope strings the five-character roping example.",
    }, {
      "name" = "wblClimbRopeLimitLbs",
      "value" = 2000,
      "comment" = "A climbing rope has a weight limit of 2000 pounds, and is subject to weakening or breaking as described for the standard coil.",
    }, {
      "name" = "wblKnotPenaltyLbs",
      "value" = 500,
      "comment" = "A knot made by anyone other than a rope-use proficient character reduces the weight the rope will hold without weakening or breaking by 500 pounds.",
    }, {
      "name" = "wblChecksPrecarious",
      "value" = 2,
      "comment" = "A precarious belayer who halts his companion fall makes TWO successful Climbing Checks: the first to halt the fall, the second to keep from being pulled down by the jolt of the rope going taut.",
    }, {
      "name" = "wblChecksSecure",
      "value" = 1,
      "comment" = "A secure belayer (a plateau or a wide ledge, where he does not need to hold himself onto the slope or cliff) needs only the ONE check - the second check is not necessary.",
    }, {
      "name" = "wblFallersOnJoltFailure",
      "value" = 2,
      "comment" = "If the precarious belayer fails his second check, both the belayer and his companion will fall.",
    } },
  "bools" = { {
      "name" = "wblRopeEndTiedAroundBody",
      "value" = true,
      "comment" = "The character to be belayed must have one end of a rope tied securely around his body.",
    }, {
      "name" = "wblPayOutSmallSlack",
      "value" = true,
      "comment" = "The belayer holds the rope and pays it out as the character moves farther down or away, always keeping just a small amount of slack in the line; for an ascent the process is reversed - he pulls the rope in.",
    }, {
      "name" = "wblFailMeansFullFall",
      "value" = true,
      "comment" = "Failure on the belayer Climbing Check indicates he has lost his hold on the rope, and the climber will fall the full distance possible.",
    }, {
      "name" = "wblSuccessBoundedByRopeLen",
      "value" = true,
      "comment" = "Success means the belayer has hung onto the rope, and at worst the climber will fall no farther than the length of the rope.",
    }, {
      "name" = "wblPrecariousNeedsSecondCheck",
      "value" = true,
      "comment" = "A belayer in a precarious position (relying on handholds and footholds) who succeeds in halting the fall must make a second successful check against the jolt of the rope going taut.",
    }, {
      "name" = "wblSecureSkipsSecondCheck",
      "value" = true,
      "comment" = "A belayer in a secure position (the top of a plateau or a wide ledge) does not need the second check.",
    }, {
      "name" = "wblPairsBelayInSequence",
      "value" = true,
      "comment" = "A string of characters connected in pairs with different ropes can belay one another in sequence.",
    }, {
      "name" = "wblLastCannotBelay",
      "value" = true,
      "comment" = "The last character in line cannot belay anyone.",
    }, {
      "name" = "wblLeaderCannotBeBelayed",
      "value" = true,
      "comment" = "The leader cannot be belayed.",
    }, {
      "name" = "wblOneBelayAtATime",
      "value" = true,
      "comment" = "Only one belay can be performed at any time.",
    }, {
      "name" = "wblNoClimbWhileBelaying",
      "value" = true,
      "comment" = "A character cannot climb while he is belaying someone else - the method is relatively slow but safer for the group as a whole.",
    }, {
      "name" = "wblMiddleFallerDragsNoneBelow",
      "value" = true,
      "comment" = "A character in the middle of a string of belayers who begins to fall will not drag down anyone beneath him, as would be the case if all characters were roped together.",
    }, {
      "name" = "wblFailedBelayerSavedAbove",
      "value" = true,
      "comment" = "If the belayer of a falling character fails to arrest the fall, that belayer has a chance of being saved by the character above who is belaying him.",
    }, {
      "name" = "wblFirstFallerUnhelpable",
      "value" = true,
      "comment" = "Nothing can help the first character who fell, since only two characters are connected to the same rope.",
    }, {
      "name" = "wblProfKnotFullStrength",
      "value" = true,
      "comment" = "Only a character with proficiency in rope use can make a knot that will hold the same amount of weight as the ropes on either side.",
    }, {
      "name" = "wblMixedDiaSmallerMinus500",
      "value" = true,
      "comment" = "If two ropes of different diameters are tied together, the weight limit of the smaller rope (minus 500 pounds, for the knot) applies to the combined line.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['wblClimbRopeMinFt']() != 150 or m['wblClimbRopeMaxFt']() != 200 or m['wblClimbRopeLimitLbs']() != 2000",
      "note" = "the climbing rope: 150 or 200 feet of half-inch rope with a 2000-pound weight limit",
    }, {
      "expr" = "m['wblKnotPenaltyLbs']() != 500 or m['wblClimbRopeLimitLbs']() != 4 * m['wblKnotPenaltyLbs']()",
      "note" = "the amateur knot: 500 pounds off the held weight; the climbing rope limit is exactly four knot penalties (2000 = 4 x 500)",
    }, {
      "expr" = "m['wblChecksPrecarious']() != 2 or m['wblChecksSecure']() != 1",
      "note" = "the two belay postures: the precarious belayer checks twice (the halt, then the jolt), the secure belayer only once",
    }, {
      "expr" = "m['wblChecksPrecarious']() != m['wblChecksSecure']() + 1",
      "note" = "the jolt check is exactly one extra check on top of the halt",
    }, {
      "expr" = "m['wblFallersOnJoltFailure']() != 2 or m['wblFallersOnJoltFailure']() != m['wblChecksPrecarious']()",
      "note" = "the failed jolt check drops both the belayer and his companion - two fallers, two checks",
    } },
  "audit" = {
      "label" = "R443 WSG belaying pin audit",
      "comment" = "The belaying slice pins the climbing-rope intro (150 or 200 feet long, 2000-pound weight limit, subject to the weakening and breaking rules), the knot rules (only a rope-use proficient character ties a full-strength knot; anyone else loses 500 pounds; different diameters take the smaller limit minus 500), the belayer Climbing Check (failure = the full fall, success bounded by the rope length), the precarious-position second check on the jolt (failure = both fall) with the secure-position exemption, and the paired-belay sequence (the last cannot belay, the leader cannot be belayed, one belay at a time, no climbing while belaying, the middle faller drags no one below, the failed belayer can be saved by the character above, the first faller is unhelpable) (rules/wsg/wsgbelay.h, prefix wbl); census 367 -> 368.",
    },
}
