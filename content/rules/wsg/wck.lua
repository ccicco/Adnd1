-- wck: promoted from tools/spec_r436.json (the The WSG CLIMBING CHECKS, R436: Table 16 (the modifiers to the non-thief Climbing Rating - the same 13 surface rows as Table 15 x the non-slippery, slightly slippery and slippery adjustments, from the +70 rough gentle non-slippery bonus down to the -50 cliff smooth no-ledges slippery penalty) with the prose rules: the modifier is added to the non-thief Climbing Rating, a final rating of 100 percent or greater means no chance of falling and a final rating of 5 percent or lower is treated as 5 percent; the other modifiers (encumbrance: moderate -5, heavy -10, severe -20; race: dwarf -5, gnome -10, halfling -5, half-orc +5; armor: chain/splint/scale/banded -15, studded leather or padded -5, anything heavier than chain cannot climb a severe slope or cliff and climbs all else at -20; strength: +5 per full point over 15 on severe slopes or cliffs only, exceptional as 18; hands: both hands free on severe slopes and cliffs, one hand at -5 on a moderate slope, gentle slopes never need hands); the thief modifiers (a +30 or greater Table 16 value needs no check, the slightly slippery falling chance is doubled, the slippery chance quadrupled, the 5 percent floor shared); and the climbing checks (the 10-foot Initial Check - failure falls back to the start; the optional Intermediate Check past 100 feet or on smooth, slippery or severe surfaces, always recommended when traveling laterally, brief lateral stretches ignored; the always-made Final Check at the start of the completing round at +20 - failure falls to the bottom on a severe slope or cliff, and a same-round initial check stands alone with no bonus) - the round continues the movement-across-special-terrain section. Census 360 -> 361.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 436,
  "prefix" = "wck",
  "banner" = {
      "title" = "The WSG CLIMBING CHECKS, R436: Table 16 (the modifiers to the non-thief Climbing Rating - the same 13 surface rows as Table 15 x the non-slippery, slightly slippery and slippery adjustments, from the +70 rough gentle non-slippery bonus down to the -50 cliff smooth no-ledges slippery penalty) with the prose rules: the modifier is added to the non-thief Climbing Rating, a final rating of 100 percent or greater means no chance of falling and a final rating of 5 percent or lower is treated as 5 percent; the other modifiers (encumbrance: moderate -5, heavy -10, severe -20; race: dwarf -5, gnome -10, halfling -5, half-orc +5; armor: chain/splint/scale/banded -15, studded leather or padded -5, anything heavier than chain cannot climb a severe slope or cliff and climbs all else at -20; strength: +5 per full point over 15 on severe slopes or cliffs only, exceptional as 18; hands: both hands free on severe slopes and cliffs, one hand at -5 on a moderate slope, gentle slopes never need hands); the thief modifiers (a +30 or greater Table 16 value needs no check, the slightly slippery falling chance is doubled, the slippery chance quadrupled, the 5 percent floor shared); and the climbing checks (the 10-foot Initial Check - failure falls back to the start; the optional Intermediate Check past 100 feet or on smooth, slippery or severe surfaces, always recommended when traveling laterally, brief lateral stretches ignored; the always-made Final Check at the start of the completing round at +20 - failure falls to the bottom on a severe slope or cliff, and a same-round initial check stands alone with no bonus) - the round continues the movement-across-special-terrain section. Census 360 -> 361.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 35; the user own copy OCR cross-checked against the archive djvu word layer (nine of thirteen rows clean; the normal moderate, normal severe and both cliff smooth rows are absent from the djvu text layer and the smooth gentle row is garbled there) and the IIIF full-resolution eye-reads (four independent reads of the disputed rows - every value matched the user copy exactly: +50/+25/+10, +30/+15/+0, -10/-25/-40, -20/-35/-50).",
      "sentinel" = "The Table 16 numbers are percentage modifiers added to a non-thief Climbing Rating by the three conditions of the surface; the same 13 surface rows as Table 15. A final rating of 100 percent or greater means no chance of falling; a final rating of 5 percent or lower is treated as 5 percent. The Final Climbing Check is made at a +20 percent modifier.",
    },
  "consts" = { {
      "name" = "wckSurfaceCount",
      "value" = 13,
      "comment" = "The Table 16 surface-row count - the same 13 surface rows as Table 15 (the nine slope rows and the four cliff rows).",
    }, {
      "name" = "wckNoFallRating",
      "value" = 100,
      "comment" = "A final adjusted Climbing Rating of 100 percent or greater means the surface is negotiated with no chance of falling.",
    }, {
      "name" = "wckMinRatingFloor",
      "value" = 5,
      "comment" = "A final adjusted Climbing Rating of 5 percent or lower (when the character is not specifically prohibited from the surface) is treated as 5 percent.",
    }, {
      "name" = "wckThiefAutoThreshold",
      "value" = 30,
      "comment" = "A thief traveling across terrain with a Table 16 value of +30 or greater needs no Climbing Check at all.",
    }, {
      "name" = "wckThiefFallMultSlightly",
      "value" = 2,
      "comment" = "On a slightly slippery surface a thief chance of falling is twice as great as on a nonslippery surface.",
    }, {
      "name" = "wckThiefFallMultSlippery",
      "value" = 4,
      "comment" = "On a slippery surface a thief chance of falling is four times as great as on a nonslippery surface.",
    }, {
      "name" = "wckThiefScoreFloor",
      "value" = 5,
      "comment" = "A thief climb walls score can never be less than 5 percent as the result of the slippery modifiers.",
    }, {
      "name" = "wckEncModeratePenalty",
      "value" = 5,
      "comment" = "The climbing rating encumbrance penalty for a moderate load.",
    }, {
      "name" = "wckEncHeavyPenalty",
      "value" = 10,
      "comment" = "The climbing rating encumbrance penalty for a heavy load.",
    }, {
      "name" = "wckEncSeverePenalty",
      "value" = 20,
      "comment" = "The climbing rating encumbrance penalty for a severe load.",
    }, {
      "name" = "wckDwarfPenalty",
      "value" = 5,
      "comment" = "The dwarf climbing rating adjustment.",
    }, {
      "name" = "wckGnomePenalty",
      "value" = 10,
      "comment" = "The gnome climbing rating adjustment.",
    }, {
      "name" = "wckHalflingPenalty",
      "value" = 5,
      "comment" = "The halfling climbing rating adjustment.",
    }, {
      "name" = "wckHalfOrcBonus",
      "value" = 5,
      "comment" = "The half-orc climbing rating adjustment.",
    }, {
      "name" = "wckChainArmorPenalty",
      "value" = 15,
      "comment" = "The climbing rating penalty for chain, splint, scale or banded armor.",
    }, {
      "name" = "wckStuddedArmorPenalty",
      "value" = 5,
      "comment" = "The climbing rating penalty for studded leather or padded armor.",
    }, {
      "name" = "wckHeavierThanChainPenalty",
      "value" = 20,
      "comment" = "A character outfitted in anything heavier than chain mail climbs all surfaces other than severe slopes and cliffs at a 20 percent penalty.",
    }, {
      "name" = "wckStrengthBonus",
      "value" = 5,
      "comment" = "The strength climbing rating bonus per full point greater than 15, on severe slopes or cliffs only.",
    }, {
      "name" = "wckStrengthBase",
      "value" = 15,
      "comment" = "The strength bonus counts full points greater than 15; an exceptional score counts as 18.",
    }, {
      "name" = "wckOneHandPenalty",
      "value" = 5,
      "comment" = "Climbing a moderate slope with one hand holding a shield or weapon applies a 5 percent penalty to the Climbing Rating.",
    }, {
      "name" = "wckCheckMinDistance",
      "value" = 10,
      "comment" = "A Climbing Check is required to ascend or descend a non-horizontal surface when the total distance to be traveled is at least 10 feet.",
    }, {
      "name" = "wckInitialCheckDistance",
      "value" = 10,
      "comment" = "The Initial Climbing Check comes after traveling 10 feet from the start of the climb.",
    }, {
      "name" = "wckIntermediateDistance",
      "value" = 100,
      "comment" = "An Intermediate Climbing Check may be called for when the current ascent or descent covers a substantial distance - more than 100 feet.",
    }, {
      "name" = "wckFinalCheckBonus",
      "value" = 20,
      "comment" = "The Final Climbing Check is made with a +20 percent modifier to the Climbing Rating.",
    } },
  "bools" = { {
      "name" = "wckModifierAddedToRating",
      "value" = true,
      "comment" = "The appropriate Table 16 number is added to the Climbing Rating for a non-thief when determining the chance of falling.",
    }, {
      "name" = "wckEncLightNoPenalty",
      "value" = true,
      "comment" = "A light or no encumbrance applies no climbing rating penalty.",
    }, {
      "name" = "wckRaceHumanNoAdjust",
      "value" = true,
      "comment" = "A human, elf or half-elf applies no climbing rating adjustment.",
    }, {
      "name" = "wckHeavierThanChainNoSevereCliff",
      "value" = true,
      "comment" = "A character outfitted in anything heavier than chain mail cannot climb any severe slope or cliff.",
    }, {
      "name" = "wckStrengthSevereCliffOnly",
      "value" = true,
      "comment" = "The strength bonus applies on severe slopes or cliffs only.",
    }, {
      "name" = "wckStrengthExceptionalAs18",
      "value" = true,
      "comment" = "An exceptional strength score counts as 18 for the climbing bonus.",
    }, {
      "name" = "wckBothHandsFreeSevereCliff",
      "value" = true,
      "comment" = "A character cannot climb a severe slope or cliff while carrying a shield and/or a weapon at the ready - both hands must be free to grip the surface.",
    }, {
      "name" = "wckOneHandModeratePenalized",
      "value" = true,
      "comment" = "One hand can hold a shield or a weapon while climbing a moderate slope, at the one-hand penalty.",
    }, {
      "name" = "wckGentleHandsFreeNotPenalized",
      "value" = true,
      "comment" = "It is not necessary to use one hands when climbing a gentle slope, and a character with both hands full is not penalized in such a case.",
    }, {
      "name" = "wckThiefAutoAboveThreshold",
      "value" = true,
      "comment" = "A thief on terrain with a Table 16 value of +30 or greater automatically negotiates the surface - his natural ability needs no Climbing Check.",
    }, {
      "name" = "wckThiefCheckBelowThreshold",
      "value" = true,
      "comment" = "Below the +30 threshold a thief must make a successful Climbing Check - rolling his climb walls score or lower on percentile dice - to keep from falling.",
    }, {
      "name" = "wckThiefScoreFloorApplies",
      "value" = true,
      "comment" = "As with non-thieves Climbing Ratings, a thief climb walls score can never drop below the 5 percent floor from these modifiers - anyone who wants to try should be given a chance, if he feels lucky.",
    }, {
      "name" = "wckInitialCheckRequired",
      "value" = true,
      "comment" = "A character who begins a climb must make a successful Initial Climbing Check after traveling 10 feet to be able to continue climbing.",
    }, {
      "name" = "wckInitialFailBackToStart",
      "value" = true,
      "comment" = "Failure on the Initial Climbing Check indicates the character has fallen back to the point from which the climb started.",
    }, {
      "name" = "wckIntermediateOptional",
      "value" = true,
      "comment" = "Depending on the length and difficulty of the climb, the DM may require an Intermediate Climbing Check at the midpoint of the current ascent or descent.",
    }, {
      "name" = "wckIntermediateOver100Feet",
      "value" = true,
      "comment" = "The Intermediate Climbing Check may be called for when the current ascent or descent covers more than 100 feet.",
    }, {
      "name" = "wckIntermediateSmoothSlipperySevere",
      "value" = true,
      "comment" = "The Intermediate Climbing Check may also be called for when the surface is smooth, slippery, severe, or a combination of those qualities.",
    }, {
      "name" = "wckLateralAlwaysCheck",
      "value" = true,
      "comment" = "It is recommended an intermediate check always be made when a character is traveling laterally and any of the above conditions apply.",
    }, {
      "name" = "wckLateralBriefIgnored",
      "value" = true,
      "comment" = "Brief stretches of lateral movement do not count for this determination, as long as the character principal direction is either up or down.",
    }, {
      "name" = "wckFinalCheckAlways",
      "value" = true,
      "comment" = "A Final Climbing Check is always made at the beginning of the round in which the character will complete the climb if he does not fall.",
    }, {
      "name" = "wckFinalFailFallsToBottom",
      "value" = true,
      "comment" = "Failure on the Final Climbing Check indicates the character has fallen - and if the fall occurs while on a severe slope or a cliff, he will not stop until he hits bottom.",
    }, {
      "name" = "wckFinalSameRoundInitialOnly",
      "value" = true,
      "comment" = "If the distance of the climb and the movement rate put the Final Climbing Check in the same round as the Initial Climbing Check, then the initial check with no bonus applied is the only one that must be made.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 16: the modifiers to the non-thief climbing rating",
      "tag" = "16",
      "count" = "wckSurfaceCount",
      "col_default" = 0,
      "cols" = { "wckModN", "wckModS", "wckModV" },
      "col_comments" = { "The non-slippery condition modifier added to a non-thief Climbing Rating, by surface row (the same 13 rows as Table 15: the rough, normal and smooth slopes at the gentle, moderate and severe tilts, then the cliff faces by roughness and ledges).", "The slightly slippery condition modifier to the non-thief Climbing Rating.", "The slippery condition modifier to the non-thief Climbing Rating." },
      "audit_comment" = "the Table 16 grid: the 13 surface rows (the rough, normal and smooth slopes at the gentle, moderate and severe tilts, then the cliff faces by roughness and ledges) x the three condition modifiers to the non-thief Climbing Rating",
      "data" = { { 70, 55, 35 }, { 60, 40, 20 }, { 40, 20, 10 }, { 60, 40, 20 }, { 50, 25, 10 }, { 30, 15, 0 }, { 50, 25, 10 }, { 30, 10, 0 }, { 10, 0, -10 }, { 0, -10, -20 }, { -10, -20, -30 }, { -10, -25, -40 }, { -20, -35, -50 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wckModN'](0) != 70 or m['wckModS'](11) != -25 or m['wckModV'](12) != -50",
      "note" = "the extremes of Table 16: the rough gentle non-slippery +70 bonus and the cliff smooth no-ledges slippery -50 penalty",
    }, {
      "expr" = "(m['wckModN'](0) + 40) < m['wckNoFallRating']()",
      "note" = "the worked no-fall case: the base 40 percent non-thief rating plus the +70 rough gentle modifier reaches 110, at or above the 100 percent no-fall rating",
    }, {
      "expr" = "m['wckModN'](0) < m['wckThiefAutoThreshold']()",
      "note" = "the thief auto rule: the +70 rough gentle non-slippery value is at or above the +30 threshold, so no Climbing Check is needed",
    }, {
      "expr" = "m['wckThiefFallMultSlippery']() != 4 or m['wckThiefFallMultSlightly']() * 2 != 4 or m['wckThiefScoreFloor']() != 5",
      "note" = "the thief falling multipliers (twice on slightly slippery, four times on slippery) and the shared 5 percent floor",
    }, {
      "expr" = "m['wckFinalCheckBonus']() - m['wckOneHandPenalty']() * 4 != 0",
      "note" = "the final check +20 bonus equals four one-hand penalties (20) - both book values pinned in one expression",
    } },
  "audit" = {
      "label" = "R436 WSG climbing checks pin audit",
      "comment" = "The climbing-checks slice pins Table 16 (the 13 surface rows x the three condition modifiers to the non-thief Climbing Rating) with the 100 percent no-fall and 5 percent floor rules, the other modifiers (the encumbrance, race, armor, strength and hands rules), the thief modifiers (the +30 auto rule, the double and quadruple falling chances) and the initial, intermediate and final check rules (rules/wsgcheck.h, prefix wck); census 360 -> 361.",
    },
}
