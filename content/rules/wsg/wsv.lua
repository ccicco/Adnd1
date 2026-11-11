-- wsv: promoted from tools/spec_r449.json (the The WSG OVERLAND MOVEMENT IN REDUCED VISIBILITY, R449: the visibility prose and TABLE 23 MOVEMENT IN REDUCED VISIBILITY - all movement rates previously described assume daylight under conditions that do not impair visibility. Table 23 gives the maximum safe speed, as a fraction of the character's or animal's current normal movement rate, for a character on foot or riding or driving an animal in less than ideal visibility: three light rows (daylight, moonlight, darkness) x five conditions (clear, moderate fog, heavy fog or snow, heavy snow with wind, blowing sand or dust), from 1/1 down to 1/8. All other factors (encumbrance, terrain, climbing, etc.) are applied FIRST to determine the current normal rate, and then that number is multiplied by the table entry; the 1/1 at daylight/clear means no further reduction. On foot at the maximum safe speed in daylight, short-range vision extends far enough to avoid easily visible hazards - he will not walk into a tree or stumble over an exposed root; at night the safe speed does NOT keep him safe from hazards (a pit or cliff edge unless he tests the surface or probes ahead with a pole). Infravision detects heat-detectable hazards in moonlight or darkness (a warm-blooded creature in ambush - yes; a cliff edge - usually no). Exceeding the maximum safe speed demands a Dexterity Check per obstacle - failure means he or the animal blundered into it or stopped short, possibly throwing him from the saddle, off the wagon seat or over the chariot front; and in no event can the speed exceed twice the table figure or the full normal movement rate, whichever is less. Census 373 -> 374.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 449,
  "prefix" = "wsv",
  "banner" = {
      "title" = "The WSG OVERLAND MOVEMENT IN REDUCED VISIBILITY, R449: the visibility prose and TABLE 23 MOVEMENT IN REDUCED VISIBILITY - all movement rates previously described assume daylight under conditions that do not impair visibility. Table 23 gives the maximum safe speed, as a fraction of the character's or animal's current normal movement rate, for a character on foot or riding or driving an animal in less than ideal visibility: three light rows (daylight, moonlight, darkness) x five conditions (clear, moderate fog, heavy fog or snow, heavy snow with wind, blowing sand or dust), from 1/1 down to 1/8. All other factors (encumbrance, terrain, climbing, etc.) are applied FIRST to determine the current normal rate, and then that number is multiplied by the table entry; the 1/1 at daylight/clear means no further reduction. On foot at the maximum safe speed in daylight, short-range vision extends far enough to avoid easily visible hazards - he will not walk into a tree or stumble over an exposed root; at night the safe speed does NOT keep him safe from hazards (a pit or cliff edge unless he tests the surface or probes ahead with a pole). Infravision detects heat-detectable hazards in moonlight or darkness (a warm-blooded creature in ambush - yes; a cliff edge - usually no). Exceeding the maximum safe speed demands a Dexterity Check per obstacle - failure means he or the animal blundered into it or stopped short, possibly throwing him from the saddle, off the wagon seat or over the chariot front; and in no event can the speed exceed twice the table figure or the full normal movement rate, whichever is less. Census 373 -> 374.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 40-41; the user own copy OCR (pages 41-42) cross-checked against the archive djvu word layer (Guide_0040.djvu with the Guide_0041.djvu head) - the prose reads CLEAN two-way, every number (the 2x cap and the 1/8 sandstorm-in-darkness example) matched exactly; the Table 23 grid is GARBLED in the djvu word layer, so every cell was confirmed by TWO independent IIIF eye-reads of leaf 40 - the OCR and both eye-reads agree on all 15 fractions.",
      "sentinel" = "Multiply the current normal rate by the Table 23 fraction to get the maximum safe speed - 1/1 in clear daylight, down to 1/8 in blowing sand or dust at night - and never push past twice that figure without a Dexterity check at every obstacle.",
    },
  "consts" = { {
      "name" = "wsvLightCount",
      "value" = 3,
      "comment" = "Table 23 has three light rows: daylight, moonlight and darkness.",
    }, {
      "name" = "wsvCondCount",
      "value" = 5,
      "comment" = "Table 23 has five visibility conditions: clear, moderate fog, heavy fog or snow, heavy snow with wind, and blowing sand or dust.",
    }, {
      "name" = "wsvSpeedCapMult",
      "value" = 2,
      "comment" = "A character or an animal under his control cannot exceed the maximum safe speed by more than twice the figure given, or move faster than the full normal movement rate, whichever is less.",
    } },
  "bools" = { {
      "name" = "wsvRatesAssumeDaylight",
      "value" = true,
      "comment" = "All movement rates previously described assume that the character is traveling in daylight, under conditions that do not impair visibility.",
    }, {
      "name" = "wsvOtherFactorsFirst",
      "value" = true,
      "comment" = "All other factors affecting movement (encumbrance, terrain, climbing, etc.) are applied to determine the current normal movement rate, and then that number is multiplied by the appropriate entry from Table 23.",
    }, {
      "name" = "wsvDaylightClearNoCut",
      "value" = true,
      "comment" = "The entry of 1/1 for Daylight/Clear means that movement is not further reduced under these conditions.",
    }, {
      "name" = "wsvDaylightFootHazardSafe",
      "value" = true,
      "comment" = "On foot and moving at the maximum safe speed during daylight, his short-range vision extends far enough to avoid hazards easily visible under clear daylight - he will not walk into a tree or stumble over an exposed root.",
    }, {
      "name" = "wsvNightHazardsRemain",
      "value" = true,
      "comment" = "Moving at the maximum safe speed will not necessarily keep him safe from hazards at night, in moonlight or darkness - he can fall into a pit or stroll off a cliff unless he tests the surface or probes the ground ahead with a pole.",
    }, {
      "name" = "wsvInfravisionHeatOnly",
      "value" = true,
      "comment" = "Infravision can detect certain hazards under moonlight or darkness provided they are heat-detectable - a warm-blooded creature lying in wait usually yes, a cliff edge usually no.",
    }, {
      "name" = "wsvFasterNeedsDexCheck",
      "value" = true,
      "comment" = "If a character attempts to move, or force an animal to move, faster than the maximum safe speed in any conditions of limited visibility, he must make a successful Dexterity Check whenever he or the animal encounters an obstacle.",
    }, {
      "name" = "wsvBlunderConsequences",
      "value" = true,
      "comment" = "Failure on the check indicates that he or the animal has blundered into the obstacle, or that the animal has stopped short - quite possibly throwing the character from the saddle, dislodging him from his wagon seat, or throwing him forward into or over the front of a chariot.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 23: MOVEMENT IN REDUCED VISIBILITY",
      "tag" = "23",
      "count" = "wsvLightCount",
      "col_default" = 1,
      "cols" = { "wsvNumClear", "wsvDenClear", "wsvNumModFog", "wsvDenModFog", "wsvNumHeavyFog", "wsvDenHeavyFog", "wsvNumHeavySnow", "wsvDenHeavySnow", "wsvNumBlowing", "wsvDenBlowing" },
      "col_comments" = { "The numerator of the maximum safe speed fraction under Clear conditions, by light row.", "The denominator under Clear conditions: 1/1 in daylight, 2/3 in moonlight, 1/2 in darkness.", "The numerator under Moderate Fog.", "The denominator under Moderate Fog: 5/6, 1/2, 1/3.", "The numerator under Heavy Fog or Snow.", "The denominator under Heavy Fog or Snow: 3/4, 1/3, 1/4.", "The numerator under Heavy Snow with Wind.", "The denominator under Heavy Snow with Wind: 2/3, 1/4, 1/6.", "The numerator under Blowing Sand or Dust.", "The denominator under Blowing Sand or Dust: 1/2, 1/6, 1/8 - the worst cell in the table." },
      "audit_comment" = "the Table 23 grid: the three light rows (daylight, moonlight, darkness) x the five visibility conditions (clear, moderate fog, heavy fog or snow, heavy snow with wind, blowing sand or dust), each cell split into the numerator and denominator of the maximum safe speed fraction - from 1/1 down to 1/8",
      "data" = { { 1, 1, 5, 6, 3, 4, 2, 3, 1, 2 }, { 2, 3, 1, 2, 1, 3, 1, 4, 1, 6 }, { 1, 2, 1, 3, 1, 4, 1, 6, 1, 8 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wsvNumClear'](0) != 1 or m['wsvDenClear'](0) != 1 or m['wsvNumBlowing'](2) != 1 or m['wsvDenBlowing'](2) != 8",
      "note" = "the two extremes: 1/1 in clear daylight (no further reduction) and 1/8 in blowing sand or dust at night (the sandstorm-in-darkness example)",
    }, {
      "expr" = "m['wsvNumModFog'](0) != 5 or m['wsvDenModFog'](0) != 6 or m['wsvNumHeavySnow'](1) != 1 or m['wsvDenHeavySnow'](1) != 4",
      "note" = "the mid-grid printed pair: 5/6 in daylight moderate fog, 1/4 in moonlight heavy snow with wind",
    }, {
      "expr" = "m['wsvSpeedCapMult']() != 2 or m['wsvLightCount']() != 3 or m['wsvCondCount']() != 5",
      "note" = "the printed prose numbers: the twice-the-figure speed cap, over the three light rows and the five conditions",
    } },
  "audit" = {
      "label" = "R449 WSG reduced visibility pin audit",
      "comment" = "The reduced visibility slice pins the daylight assumption behind the previously described rates, the other-factors-first multiplication by the Table 23 entry (the 1/1 clear-daylight cell means no further reduction), the on-foot daylight hazard avoidance (no trees, no roots) with the night exception (a pit or cliff unless the surface is tested or probed), the infravision heat-only detection (a warm-blooded ambush yes, a cliff edge usually no), the Dexterity Check above the maximum safe speed with the blunder/stop-short consequences (saddle, wagon seat, chariot front) and the twice-the-figure cap, and Table 23 (the three light rows x the five visibility conditions, the fractions from 1/1 down to 1/8) (rules/wsg/wsgvis.h, prefix wsv); census 373 -> 374.",
    },
}
