-- wcp: promoted from tools/spec_r456.json (the The WSG CAPSIZING AND DAMAGE TO CRAFT, R456: waterborne vehicles and their passengers are to some degree at the mercy of the elements - most vessels have a chance of capsizing (turning over, and perhaps sinking) if the wind is strong or the water is rough, and violent weather can damage masts and sails on a rigged vessel. Table 26, the CHANCE OF CAPSIZING: kayak 25/40/60/80, small canoe 20/35/50/75, small rowboat 5/15/30/50, coracle 10/20/30/50, large canoe 10/20/30/40, large rowboat 0/10/25/40, small barge 0/5/10/20, and large barge 0/0/5/10, across the four wind/water conditions - MILD, MODERATE, DANGEROUS and SEVERE. The check is made whenever a character enters or leaves a boat, when someone moves abruptly from one spot to another in or on the craft, and at any other time the Dungeon Master deems appropriate. The table rates are for vessels with no sails, or with the sails furled (rolled up and tied to the mast); under sail the chance of capsizing is 20% greater in all cases where the base chance is greater than 0%. The condition bands: MILD - wind light at 15 miles per hour or less and the water calm or moving only slightly (current of 3 inches or less); MODERATE - wind 16 to 30 miles per hour, or the water running fairly fast (current faster than 3 inches, up to 6); DANGEROUS - wind 31 to 50 miles per hour, or the water running very fast (current faster than 6 inches, up to 9); SEVERE - wind more than 50 miles per hour, or a current of 9 inches or greater. As with the movement figures, all of these assume at least one character aboard with proficiency in boating/sailing. The mast damage rules: strong winds can damage sails, rigging or the mast (assuming the mast is raised) whenever the wind velocity is 40 miles per hour or greater, on a percentage chance equal to the velocity of the wind, modified downward by 30% if the mast is raised but the sail is furled - and upward if the mast is not securely rigged or is made of weak material, at the Dungeon Master discretion. The check is made once per hour or as often as the DM deems appropriate, conceivably more frequently for a poorly rigged or substandard mast. Census 380 -> 381.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 456,
  "prefix" = "wcp",
  "banner" = {
      "title" = "The WSG CAPSIZING AND DAMAGE TO CRAFT, R456: waterborne vehicles and their passengers are to some degree at the mercy of the elements - most vessels have a chance of capsizing (turning over, and perhaps sinking) if the wind is strong or the water is rough, and violent weather can damage masts and sails on a rigged vessel. Table 26, the CHANCE OF CAPSIZING: kayak 25/40/60/80, small canoe 20/35/50/75, small rowboat 5/15/30/50, coracle 10/20/30/50, large canoe 10/20/30/40, large rowboat 0/10/25/40, small barge 0/5/10/20, and large barge 0/0/5/10, across the four wind/water conditions - MILD, MODERATE, DANGEROUS and SEVERE. The check is made whenever a character enters or leaves a boat, when someone moves abruptly from one spot to another in or on the craft, and at any other time the Dungeon Master deems appropriate. The table rates are for vessels with no sails, or with the sails furled (rolled up and tied to the mast); under sail the chance of capsizing is 20% greater in all cases where the base chance is greater than 0%. The condition bands: MILD - wind light at 15 miles per hour or less and the water calm or moving only slightly (current of 3 inches or less); MODERATE - wind 16 to 30 miles per hour, or the water running fairly fast (current faster than 3 inches, up to 6); DANGEROUS - wind 31 to 50 miles per hour, or the water running very fast (current faster than 6 inches, up to 9); SEVERE - wind more than 50 miles per hour, or a current of 9 inches or greater. As with the movement figures, all of these assume at least one character aboard with proficiency in boating/sailing. The mast damage rules: strong winds can damage sails, rigging or the mast (assuming the mast is raised) whenever the wind velocity is 40 miles per hour or greater, on a percentage chance equal to the velocity of the wind, modified downward by 30% if the mast is raised but the sail is furled - and upward if the mast is not securely rigged or is made of weak material, at the Dungeon Master discretion. The check is made once per hour or as often as the DM deems appropriate, conceivably more frequently for a poorly rigged or substandard mast. Census 380 -> 381.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 45; the user own copy OCR (page 46) cross-checked against the archive djvu word layer (Guide_0045) - the prose reads clean two-way, but the djvu TRUNCATES the Table 26 large barge row (the severe cell cut off at the page break), so the grid was settled by TWO independent IIIF eye-reads of leaf $45, which agree with the OCR exactly on all eight rows and all four columns, the large barge severe cell reading 10%.",
      "sentinel" = "Watch the weather or swim: the kayak flips one time in four in mild water and four times in five in a gale, the barges barely at all. Step in, step out, or lurch across the deck and roll. Under sail add twenty, if there was anything to add. Mild is a lazy breeze under fifteen and a drift under four; moderate to thirty and six; dangerous to fifty and nine; severe beyond both. And from forty miles per hour the wind itself snaps the mast on a roll of the velocity - thirty less if the sail is furled, once an hour, more if the rigging is bad.",
    },
  "consts" = { {
      "name" = "wcpVesselCount",
      "value" = 8,
      "comment" = "Table 26 lists the same eight vessels as Table 25: kayak, small canoe, small rowboat, coracle, large canoe, large rowboat, small barge and large barge.",
    }, {
      "name" = "wcpConditionCount",
      "value" = 4,
      "comment" = "The four wind/water conditions: mild, moderate, dangerous and severe.",
    }, {
      "name" = "wcpSailModifier",
      "value" = 20,
      "comment" = "If the vessel is being operated under sail, the chance of capsizing is 20% greater in all cases where the base chance is greater than 0%.",
    }, {
      "name" = "wcpMildWindMax",
      "value" = 15,
      "comment" = "Mild conditions prevail when the wind velocity is light - 15 miles per hour or less.",
    }, {
      "name" = "wcpMildCurrentMax",
      "value" = 3,
      "comment" = "Mild: the surface of the water is calm or moving only slightly - a current of 3 inches or less.",
    }, {
      "name" = "wcpModWindMin",
      "value" = 16,
      "comment" = "Moderate conditions exist when the wind is blowing at 16 to 30 miles per hour.",
    }, {
      "name" = "wcpModWindMax",
      "value" = 30,
      "comment" = "The top of the moderate wind band: 16 to 30 miles per hour.",
    }, {
      "name" = "wcpModCurrentMax",
      "value" = 6,
      "comment" = "Moderate: the water is running fairly fast - a current faster than 3 inches, up to 6.",
    }, {
      "name" = "wcpDangerWindMin",
      "value" = 31,
      "comment" = "Dangerous conditions occur when the wind is blowing at 31 to 50 miles per hour.",
    }, {
      "name" = "wcpDangerWindMax",
      "value" = 50,
      "comment" = "The top of the dangerous wind band: 31 to 50 miles per hour.",
    }, {
      "name" = "wcpDangerCurrentMax",
      "value" = 9,
      "comment" = "Dangerous: the water is running very fast - a current faster than 6 inches, up to 9.",
    }, {
      "name" = "wcpSevereWindMin",
      "value" = 50,
      "comment" = "Severe conditions exist when the wind is blowing at more than 50 miles per hour.",
    }, {
      "name" = "wcpSevereCurrentMin",
      "value" = 9,
      "comment" = "Severe: a current of 9 inches or greater.",
    }, {
      "name" = "wcpMastDamageWindMin",
      "value" = 40,
      "comment" = "Strong winds can damage sails, rigging or the mast whenever the wind velocity is 40 miles per hour or greater.",
    }, {
      "name" = "wcpFurledReduction",
      "value" = 30,
      "comment" = "The mast damage chance is modified downward by 30% if the mast is raised but the sail is furled (not in use).",
    }, {
      "name" = "wcpMastCheckPeriodHours",
      "value" = 1,
      "comment" = "The mast damage check is made once per hour, or as often as the Dungeon Master deems appropriate.",
    } },
  "bools" = { {
      "name" = "wcpCapsizeMeansTurnOver",
      "value" = true,
      "comment" = "Capsizing is turning over, and perhaps sinking.",
    }, {
      "name" = "wcpCheckOnEnterLeave",
      "value" = true,
      "comment" = "The chance of capsizing is checked whenever a character enters or leaves a boat.",
    }, {
      "name" = "wcpCheckOnAbruptMove",
      "value" = true,
      "comment" = "The chance of capsizing is checked when someone moves abruptly from one spot to another in or on the craft.",
    }, {
      "name" = "wcpCheckOnDmCall",
      "value" = true,
      "comment" = "The check is also made at any other time the Dungeon Master deems appropriate.",
    }, {
      "name" = "wcpTableAssumesNoSail",
      "value" = true,
      "comment" = "The table rates are for vessels with no sails, or those on which the sails are furled (rolled up and tied to the mast).",
    }, {
      "name" = "wcpUnderSailIncreased",
      "value" = true,
      "comment" = "If the vessel is being operated under sail, the chance of capsizing is 20% greater in all cases where the base chance is greater than 0%.",
    }, {
      "name" = "wcpProficiencyAssumed",
      "value" = true,
      "comment" = "As with the movement figures, all of these figures assume the presence on board of at least one character with proficiency in boating/sailing.",
    }, {
      "name" = "wcpMastDamageByWind",
      "value" = true,
      "comment" = "Strong winds can damage sails, rigging or the mast on a vessel so equipped, assuming the mast is raised and has not been taken down.",
    }, {
      "name" = "wcpDamageChanceEqualsVelocity",
      "value" = true,
      "comment" = "The mast damage occurs on a percentage chance equal to the velocity of the wind.",
    }, {
      "name" = "wcpFurledSailReduced",
      "value" = true,
      "comment" = "The mast damage chance is modified downward by 30% if the mast is raised but the sail is furled.",
    }, {
      "name" = "wcpPoorRiggingIncreased",
      "value" = true,
      "comment" = "If the mast is not securely rigged, or is made of relatively weak material, the Dungeon Master adjusts the chance of damage upward.",
    }, {
      "name" = "wcpMastCheckHourly",
      "value" = true,
      "comment" = "The mast damage check is made once per hour or as often as the DM deems appropriate - more frequently for a poorly rigged or substandard mast.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 26: CHANCE OF CAPSIZING",
      "tag" = "26",
      "count" = "wcpVesselCount",
      "col_default" = 0,
      "cols" = { "wcpMildPct", "wcpModeratePct", "wcpDangerPct", "wcpSeverePct" },
      "col_comments" = { "The chance of capsizing in MILD conditions (wind 15 mph or less, current 3 inches or less): 25, 20, 5, 10, 10, 0, 0, 0.", "The chance of capsizing in MODERATE conditions (wind 16-30 mph, current 3 to 6 inches): 40, 35, 15, 20, 20, 10, 5, 0.", "The chance of capsizing in DANGEROUS conditions (wind 31-50 mph, current 6 to 9 inches): 60, 50, 30, 30, 30, 25, 10, 5.", "The chance of capsizing in SEVERE conditions (wind over 50 mph, current 9 inches or more): 80, 75, 50, 50, 40, 40, 20, 10." },
      "audit_comment" = "the Table 26 grid: the chance of capsizing for the eight vessels (kayak, small canoe, small rowboat, coracle, large canoe, large rowboat, small barge, large barge) under the four wind/water conditions (mild, moderate, dangerous, severe)",
      "data" = { { 25, 40, 60, 80 }, { 20, 35, 50, 75 }, { 5, 15, 30, 50 }, { 10, 20, 30, 50 }, { 10, 20, 30, 40 }, { 0, 10, 25, 40 }, { 0, 5, 10, 20 }, { 0, 0, 5, 10 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wcpMildWindMax']() != 15 or m['wcpModWindMin']() != 16 or m['wcpModWindMax']() != 30 or m['wcpDangerWindMin']() != 31 or m['wcpDangerWindMax']() != 50 or m['wcpSevereWindMin']() != 50",
      "note" = "the wind bands: mild to 15, moderate 16 to 30, dangerous 31 to 50, severe beyond 50 miles per hour",
    }, {
      "expr" = "m['wcpMildCurrentMax']() != 3 or m['wcpModCurrentMax']() != 6 or m['wcpDangerCurrentMax']() != 9 or m['wcpSevereCurrentMin']() != 9 or m['wcpModCurrentMax']() != 2 * m['wcpMildCurrentMax']() or m['wcpDangerCurrentMax']() != 3 * m['wcpMildCurrentMax']()",
      "note" = "the current bands: mild to 3 inches, moderate to 6, dangerous to 9, severe from 9 - the moderate is twice and the dangerous three times the mild maximum",
    }, {
      "expr" = "m['wcpSailModifier']() != 20 or m['wcpMastDamageWindMin']() != 40 or m['wcpFurledReduction']() != 30 or m['wcpMastCheckPeriodHours']() != 1",
      "note" = "the modifiers: the +20 under sail, the 40 mph mast damage threshold, the 30% furled reduction, the hourly check",
    }, {
      "expr" = "m['wcpDangerWindMax']() != 50 or m['wcpSevereWindMin']() != m['wcpDangerWindMax']() or m['wcpDangerCurrentMax']() != m['wcpSevereCurrentMin']()",
      "note" = "the band seams: severe starts where dangerous tops out, in both wind and current",
    } },
  "audit" = {
      "label" = "R456 WSG capsizing pin audit",
      "comment" = "The capsizing slice pins Table 26 (the chance of capsizing for the eight vessels under the four wind/water conditions - the kayak 25/40/60/80 down to the large barge 0/0/5/10), the check triggers (entering or leaving the boat, abrupt movement, DM discretion), the under-sail +20% wherever the base chance is greater than zero, the condition bands (mild at 15 mph and 3 inches or less, moderate 16-30 and up to 6, dangerous 31-50 and up to 9, severe beyond 50 and from 9), the boating-proficiency assumption, and the mast damage rules (the 40 mph threshold, the percentage chance equal to the wind velocity, the 30% furled-sail reduction, the upward adjustment for poor rigging and the hourly check) (rules/wsg/wsgcapsizing.h, prefix wcp); census 380 -> 381.",
    },
}
