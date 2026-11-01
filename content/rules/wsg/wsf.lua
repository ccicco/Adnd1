-- wsf: promoted from tools/spec_r439.json (the The WSG STOPPING A FALL, R439: Table 19 (the chance of stopping a fall or tumble - the four surface rows x the non-slippery, slightly slippery and slippery conditions, each entry a fraction of the Climbing Rating: gentle 7/8, 3/4, 2/3; moderate 3/4, 2/3, 1/2; severe 2/3, 1/2, 1/4; cliff face 1/2, 1/4 and the slippery dash - no chance at all) with the prose rules: a character can attempt to halt his descent and reduce the damage, the chances much greater tumbling down a gentle slope than in free fall; the DM either requires the attempt announced before it becomes impossible or allows an automatic attempt right after the fall begins (holding a sword and shield means no attempt unless dropped); only one attempt may be made, within the first 50 feet from a cliff or severe slope, 75 feet down a moderate slope or 100 feet down a gentle slope - past the window the velocity is too great; the cliff and severe attempt only succeeds if a protrusion exists to grab, while a moderate or gentle tumble presses arms and legs against the slope itself; a stopped fall still takes impact and/or abrasion damage for the distance fallen, but an immediate successful hands-free attempt can halt a moderate or gentle tumble before any damage - the round continues the movement-across-special-terrain section. Census 363 -> 364.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 439,
  "prefix" = "wsf",
  "banner" = {
      "title" = "The WSG STOPPING A FALL, R439: Table 19 (the chance of stopping a fall or tumble - the four surface rows x the non-slippery, slightly slippery and slippery conditions, each entry a fraction of the Climbing Rating: gentle 7/8, 3/4, 2/3; moderate 3/4, 2/3, 1/2; severe 2/3, 1/2, 1/4; cliff face 1/2, 1/4 and the slippery dash - no chance at all) with the prose rules: a character can attempt to halt his descent and reduce the damage, the chances much greater tumbling down a gentle slope than in free fall; the DM either requires the attempt announced before it becomes impossible or allows an automatic attempt right after the fall begins (holding a sword and shield means no attempt unless dropped); only one attempt may be made, within the first 50 feet from a cliff or severe slope, 75 feet down a moderate slope or 100 feet down a gentle slope - past the window the velocity is too great; the cliff and severe attempt only succeeds if a protrusion exists to grab, while a moderate or gentle tumble presses arms and legs against the slope itself; a stopped fall still takes impact and/or abrasion damage for the distance fallen, but an immediate successful hands-free attempt can halt a moderate or gentle tumble before any damage - the round continues the movement-across-special-terrain section. Census 363 -> 364.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 36; the user own copy OCR cross-checked against the archive djvu word layer (the djvu table zone is heavily garbled - only the cliff slightly-slippery 1/4 cell legible there) and the IIIF full-resolution eye-reads (two independent reads of the full table; every value matched the user copy exactly). The fraction-of-rating worked example (3/4 of 60) is written cross-multiplied, division-free.",
      "sentinel" = "Each Table 19 entry is the chance of stopping a fall or tumble as a fraction of the Climbing Rating, by the surface fallen from and the condition of the surface. The cliff face slippery cell is the printed dash - no chance at all. Only one attempt may be made, within the 50/75/100-foot windows.",
    },
  "consts" = { {
      "name" = "wsfSurfaceCount",
      "value" = 4,
      "comment" = "The Table 19 row count (the gentle, moderate and severe slopes and the cliff face).",
    }, {
      "name" = "wsfAttemptCliffSevereFt",
      "value" = 50,
      "comment" = "The stop attempt must be made within the first 50 feet of a fall from a cliff face or down a severe slope.",
    }, {
      "name" = "wsfAttemptModerateFt",
      "value" = 75,
      "comment" = "The stop attempt must be made within the first 75 feet of a fall down a moderate slope.",
    }, {
      "name" = "wsfAttemptGentleFt",
      "value" = 100,
      "comment" = "The stop attempt must be made within the first 100 feet of a fall down a gentle slope.",
    } },
  "bools" = { {
      "name" = "wsfChanceIsFractionOfRating",
      "value" = true,
      "comment" = "The Table 19 entries are the chance of stopping a fall or tumble, expressed as a fraction of the character Climbing Rating.",
    }, {
      "name" = "wsfOneAttemptOnly",
      "value" = true,
      "comment" = "Only one attempt to stop the fall may be made.",
    }, {
      "name" = "wsfProtrusionRequired",
      "value" = true,
      "comment" = "In a fall from a cliff or a severe slope, the attempt can only succeed if some protrusion exists for the character to grab onto.",
    }, {
      "name" = "wsfSlopeSelfHalt",
      "value" = true,
      "comment" = "Tumbling down a moderate or gentle slope, the character can use the slope itself to halt his fall by pressing down against it with his arms and legs.",
    }, {
      "name" = "wsfTooLateAfterWindow",
      "value" = true,
      "comment" = "If the attempt is not made before the fall or tumble exceeds the indicated distance, it cannot be made at all - the character velocity is too great to make the attempt worthwhile.",
    }, {
      "name" = "wsfStopStillTakesDamage",
      "value" = true,
      "comment" = "A character who stops his fall still takes impact and/or abrasion damage for the distance fallen, if such damage applies.",
    }, {
      "name" = "wsfCanHaltBeforeDamage",
      "value" = true,
      "comment" = "It is entirely possible to halt a tumble down a moderate or gentle slope before suffering any damage, if the hands are free and the attempt is made successfully immediately after the tumble starts.",
    }, {
      "name" = "wsfAnnounceOrAutomatic",
      "value" = true,
      "comment" = "The DM can either require the player to announce the attempt before it becomes impossible, or simply allow any character an automatic attempt right after the fall begins, as long as the character is able to make it.",
    }, {
      "name" = "wsfHandsMustBeFree",
      "value" = true,
      "comment" = "Someone who begins to tumble down a gentle slope and insists on holding his sword and shield cannot try to stop his fall unless he drops what he is holding.",
    }, {
      "name" = "wsfGentleEasierThanFreeFall",
      "value" = true,
      "comment" = "The chances of success are much greater for a character tumbling down a gentle slope than for a character in free fall.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 19: the chance of stopping a fall or tumble",
      "tag" = "19",
      "count" = "wsfSurfaceCount",
      "col_default" = 0,
      "cols" = { "wsfNumN", "wsfNumS", "wsfNumV", "wsfDenN", "wsfDenS", "wsfDenV" },
      "col_comments" = { "The numerator of the non-slippery stop fraction, by surface row (the gentle, moderate and severe slopes and the cliff face; the fraction is of the Climbing Rating).", "The numerator of the slightly slippery stop fraction.", "The numerator of the slippery stop fraction (0 for the cliff face - the printed dash, no chance).", "The denominator of the non-slippery stop fraction.", "The denominator of the slightly slippery stop fraction.", "The denominator of the slippery stop fraction (0 for the cliff face - the printed dash, no chance)." },
      "audit_comment" = "the Table 19 grid: the four surface rows (the gentle, moderate and severe slopes and the cliff face) x the three condition stop fractions, each encoded as its numerator and denominator (the cliff slippery dash = 0/0, no chance at all)",
      "data" = { { 7, 3, 2, 8, 4, 3 }, { 3, 2, 1, 4, 3, 2 }, { 2, 1, 1, 3, 2, 4 }, { 1, 1, 0, 2, 4, 0 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wsfNumN'](0) != 7 or m['wsfDenN'](0) != 8 or m['wsfNumN'](3) != 1 or m['wsfDenN'](3) != 2",
      "note" = "the range of Table 19: the gentle non-slippery 7/8 chance at the top, the cliff non-slippery 1/2 at the bottom",
    }, {
      "expr" = "m['wsfNumV'](3) != 0 or m['wsfDenV'](3) != 0",
      "note" = "the cliff face slippery cell is the printed dash - no chance of stopping at all, encoded as the 0/0 sentinel",
    }, {
      "expr" = "m['wsfAttemptCliffSevereFt']() != 50 or m['wsfAttemptModerateFt']() - m['wsfAttemptCliffSevereFt']() != 25 or m['wsfAttemptGentleFt']() - m['wsfAttemptModerateFt']() != 25",
      "note" = "the attempt windows: within the first 50 feet from a cliff or severe slope, 75 feet down a moderate slope, 100 feet down a gentle slope (the two steps are 25 feet each)",
    }, {
      "expr" = "m['wsfNumN'](1) * 60 != 45 * m['wsfDenN'](1)",
      "note" = "the fraction-of-rating reading, written cross-multiplied: a 60 percent Climbing Rating on a moderate non-slippery slope stops 3/4 of 60 = 45 percent of the time",
    } },
  "audit" = {
      "label" = "R439 WSG stopping a fall pin audit",
      "comment" = "The stopping-a-fall slice pins Table 19 (the four surface rows x the three condition stop fractions, the cliff slippery dash as the 0/0 no-chance sentinel) with the fraction-of-rating reading, the one-attempt-only rule, the 50/75/100-foot attempt windows, the protrusion requirement on cliff and severe, the slope-self-halt rule on moderate and gentle, the damage-still-applies rule and the halt-before-damage possibility (rules/wsgstop.h, prefix wsf); census 363 -> 364.",
    },
}
