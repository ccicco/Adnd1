-- wpu: promoted from tools/spec_r470.json (the R470: the WSG PURIFYING WATER slice with the TAINTED-WATER EFFECTS - the purification trigger (characters suspecting scavenged water is tainted, a possibility that almost always exists, can greatly reduce the chance of harm by purifying before drinking), the boil rule (assuming no magical purification, boiling the best way to remove impurities: a sufficiently long boil leaves only a 10% chance of remaining tainted, the required time 2-5 rounds - 1d4+1 - at an elevation close to sea level plus an extra 1d2 minutes for every 1,000 feet of elevation above sea level, taking the water off the fire before the required time expires doing no good), the evaporation cost (boiling reduces the volume to be drunk: at relatively low elevation - 5,000 feet or less - 5% of the water's volume lost per minute boiled, at higher elevation only 3% per minute, characters facing a shortage often going for quantity over quality), the tainted-water effects (the same as eating tainted or spoiled food: mildly tainted water hits as tainted food but with a 6-hour minimum duration instead of 12, severely tainted water as spoiled food with an 18-hour minimum instead of 24), the severity ruling (the DM decides mild or severe; severely tainted water relatively more likely in areas of low elevation such as swamps and in perennially warm or hot climates where bacteria prosper - extreme heat kills bacteria, extreme cold does not necessarily, subarctic melt ice almost as likely to carry organic impurities as temperate lake water) and the bad-water warnings (taste and appearance not reliable purity indicators - the murky brown water may be less harmful than the fresh clear liquid; some wilderness water carries illness-producing bacteria above and beyond the taint effects and some is naturally poisonous, both DM matters; a waterhole devoid of vegetation and especially one ringed with skeletal remains a dead giveaway to find a different source; even without magical aids such as detect poison, caution and common sense go a long way), printed p. 60.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 470,
  "prefix" = "wpu",
  "banner" = {
      "title" = "R470: the WSG PURIFYING WATER slice with the TAINTED-WATER EFFECTS - the purification trigger (characters suspecting scavenged water is tainted, a possibility that almost always exists, can greatly reduce the chance of harm by purifying before drinking), the boil rule (assuming no magical purification, boiling the best way to remove impurities: a sufficiently long boil leaves only a 10% chance of remaining tainted, the required time 2-5 rounds - 1d4+1 - at an elevation close to sea level plus an extra 1d2 minutes for every 1,000 feet of elevation above sea level, taking the water off the fire before the required time expires doing no good), the evaporation cost (boiling reduces the volume to be drunk: at relatively low elevation - 5,000 feet or less - 5% of the water's volume lost per minute boiled, at higher elevation only 3% per minute, characters facing a shortage often going for quantity over quality), the tainted-water effects (the same as eating tainted or spoiled food: mildly tainted water hits as tainted food but with a 6-hour minimum duration instead of 12, severely tainted water as spoiled food with an 18-hour minimum instead of 24), the severity ruling (the DM decides mild or severe; severely tainted water relatively more likely in areas of low elevation such as swamps and in perennially warm or hot climates where bacteria prosper - extreme heat kills bacteria, extreme cold does not necessarily, subarctic melt ice almost as likely to carry organic impurities as temperate lake water) and the bad-water warnings (taste and appearance not reliable purity indicators - the murky brown water may be less harmful than the fresh clear liquid; some wilderness water carries illness-producing bacteria above and beyond the taint effects and some is naturally poisonous, both DM matters; a waterhole devoid of vegetation and especially one ringed with skeletal remains a dead giveaway to find a different source; even without magical aids such as detect poison, caution and common sense go a long way), printed p. 60.",
      "provenance" = "Ground truth two-way, pure prose: the user-run tesseract text of printed p. 60 (the --psm 4 run from the R469 extraction) vs the pdf embedded text layer (pdftotext -layout, pdf page 61; the archive.org djvu item still dark, the pdf layer the standing second reader). The two readers agree on every mechanic and every number: the 10% remainder, the 2-5 round boil, the 1d4+1 dice, the 1d2-minute adder per 1,000 feet, the 5,000-foot break, the 5%/3% evaporation ladder, the 6/18-hour minimum durations against the 12/24 food bases, and the skeletal-remains waterhole warning. The pdfy garbles resolve cleanly against the tesseract reads: ld4+ 1 = 1d4+1, detectpoison = detect poison, Punfymg Water = Purifying Water. No contested cells - no physical-page reads needed.",
      "sentinel" = "No printed grid in this slice - the boil rule, the elevation ladders, the taint durations and the bad-water warnings pin as consts and bools, every one audit-verified against the model.",
    },
  "consts" = { {
      "name" = "wpuBoilTaintRemainPct",
      "value" = 10,
      "comment" = "if the water is boiled sufficiently long there is only a 10% chance that it will remain tainted",
    }, {
      "name" = "wpuBoilRoundsMin",
      "value" = 2,
      "comment" = "the required boil time at an elevation close to sea level: 2-5 rounds (1d4+1), the dice floor",
    }, {
      "name" = "wpuBoilRoundsMax",
      "value" = 5,
      "comment" = "the required boil time at sea level: the dice ceiling (4+1)",
    }, {
      "name" = "wpuElevStepFt",
      "value" = 1000,
      "comment" = "an extra 1d2 minutes of boiling for every 1,000 feet of elevation above sea level: the step in feet",
    }, {
      "name" = "wpuEvapBreakFt",
      "value" = 5000,
      "comment" = "the evaporation-ladder break: relatively low elevation means 5,000 feet or less",
    }, {
      "name" = "wpuEvapLowPctPerMin",
      "value" = 5,
      "comment" = "at relatively low elevation (5,000 feet or less) 5% of the water volume is lost to evaporation for every minute boiled",
    }, {
      "name" = "wpuEvapHighPctPerMin",
      "value" = 3,
      "comment" = "at higher elevation the evaporation loss is only 3% per minute",
    }, {
      "name" = "wpuMildMinHours",
      "value" = 6,
      "comment" = "mildly tainted water hits like tainted food but with a minimum duration of 6 hours instead of 12",
    }, {
      "name" = "wpuMildFoodBaseHours",
      "value" = 12,
      "comment" = "the tainted-food minimum duration baseline that the mild water taint replaces: 12 hours",
    }, {
      "name" = "wpuSevereMinHours",
      "value" = 18,
      "comment" = "severely tainted water hits like spoiled food but with a minimum duration of 18 hours instead of 24",
    }, {
      "name" = "wpuSevereFoodBaseHours",
      "value" = 24,
      "comment" = "the spoiled-food minimum duration baseline that the severe water taint replaces: 24 hours",
    } },
  "bools" = { {
      "name" = "wpuSuspectTaintAlmostAlways",
      "value" = true,
      "comment" = "characters having reason to suspect scavenged water is tainted - a possibility that almost always exists - can greatly reduce the chance of harm by purifying before drinking",
    }, {
      "name" = "wpuBoilBestNonmagical",
      "value" = true,
      "comment" = "assuming no magical means of purification is available, the best way to remove impurities from water is by boiling it",
    }, {
      "name" = "wpuEarlyRemovalNoGood",
      "value" = true,
      "comment" = "if the water is taken off the fire before the required time has expired, the boiling will have done no good",
    }, {
      "name" = "wpuQuantityOverQuality",
      "value" = true,
      "comment" = "faced with a choice between not having enough water and risking the ill effects of unpurified water, characters may often decide to go for quantity over quality - the evaporation cost is why one would stop boiling early",
    }, {
      "name" = "wpuEffectsMatchTaintedFood",
      "value" = true,
      "comment" = "in essence the effects of drinking tainted water are the same as the effects of eating tainted or spoiled food (see the Food Gathering text); only the minimum durations differ",
    }, {
      "name" = "wpuSeverityDMRuling",
      "value" = true,
      "comment" = "the Dungeon Master must decide whether a certain supply of bad water is mildly or severely tainted",
    }, {
      "name" = "wpuSevereLikelyLowWarm",
      "value" = true,
      "comment" = "severely tainted water is relatively more likely in areas of low elevation (such as swamps) and in perennially warm or hot climates where bacteria prosper because of the temperature",
    }, {
      "name" = "wpuColdDoesNotKill",
      "value" = true,
      "comment" = "extreme heat (boiling) kills bacteria, but extreme cold does not necessarily have the same effect: water melted from subarctic ice is almost as likely to contain organic impurities as water dipped from a temperate lake",
    }, {
      "name" = "wpuTasteNotIndicator",
      "value" = true,
      "comment" = "the taste and appearance of water are not always indicators of its purity: characters should not necessarily refrain from murky or strangely colored water - the brown water may actually be less harmful than the fresh, clear liquid saved for a special occasion",
    }, {
      "name" = "wpuBacteriaAndPoisonLayer",
      "value" = true,
      "comment" = "some wilderness water may carry bacteria producing illness above and beyond the taint effects, and some naturally occurring water may actually be poisonous - whether these occur and their effects are DM matters",
    }, {
      "name" = "wpuWaterholeDeadGiveaway",
      "value" = true,
      "comment" = "if the area surrounding a waterhole is devoid of vegetation, and especially if it contains skeletal remains, characters should consider those signs strong evidence for finding a different water source - a dead giveaway",
    }, {
      "name" = "wpuCautionCommonSense",
      "value" = true,
      "comment" = "even in the absence of magical aids (such as detect poison), caution and common sense can go a long way toward steering clear of very bad water",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the boil time at sea level: 2-5 rounds (1d4+1)",
      "expr" = "m['wpuBoilRoundsMin']() != 2 or m['wpuBoilRoundsMax']() != 5 or m['wpuBoilRoundsMin']() >= m['wpuBoilRoundsMax']()",
    }, {
      "note" = "the taint remainder after a sufficient boil: only 10%",
      "expr" = "m['wpuBoilTaintRemainPct']() != 10",
    }, {
      "note" = "the evaporation ladder: the 5,000-foot break with 5% below and 3% above",
      "expr" = "m['wpuEvapBreakFt']() != 5000 or m['wpuEvapLowPctPerMin']() != 5 or m['wpuEvapHighPctPerMin']() != 3 or m['wpuEvapLowPctPerMin']() <= m['wpuEvapHighPctPerMin']()",
    }, {
      "note" = "the elevation adder: an extra 1d2 minutes per 1,000 feet",
      "expr" = "m['wpuElevStepFt']() != 1000",
    }, {
      "note" = "the mild taint: a 6-hour minimum against the 12-hour food baseline",
      "expr" = "m['wpuMildMinHours']() != 6 or m['wpuMildFoodBaseHours']() != 12 or m['wpuMildMinHours']() >= m['wpuMildFoodBaseHours']()",
    }, {
      "note" = "the severe taint: an 18-hour minimum against the 24-hour food baseline",
      "expr" = "m['wpuSevereMinHours']() != 18 or m['wpuSevereFoodBaseHours']() != 24 or m['wpuSevereMinHours']() >= m['wpuSevereFoodBaseHours']()",
    }, {
      "note" = "the severe ladder climbs above the mild ladder",
      "expr" = "m['wpuSevereMinHours']() <= m['wpuMildMinHours']()",
    }, {
      "note" = "the boil mechanics: the best nonmagical purification, the early-removal nullification and the quantity-over-quality tradeoff",
      "expr" = "m['wpuBoilBestNonmagical']() != 1 or m['wpuEarlyRemovalNoGood']() != 1 or m['wpuQuantityOverQuality']() != 1",
    }, {
      "note" = "the taint-severity geography: the low-warm likelihood and the cold-does-not-kill exception",
      "expr" = "m['wpuSevereLikelyLowWarm']() != 1 or m['wpuColdDoesNotKill']() != 1 or m['wpuSeverityDMRuling']() != 1",
    }, {
      "note" = "the bad-water warnings: the taste deception, the bacteria-and-poison layer, the skeletal-remains waterhole and the caution-and-common-sense close",
      "expr" = "m['wpuTasteNotIndicator']() != 1 or m['wpuBacteriaAndPoisonLayer']() != 1 or m['wpuWaterholeDeadGiveaway']() != 1 or m['wpuCautionCommonSense']() != 1",
    } },
  "audit" = {
      "label" = "R470 WSG purifying water pin audit",
      "comment" = "The purification baseline (the 10% taint remainder after a sufficient boil, the 2-5 round boil at sea level plus the elevation time adder, the early-removal nullification, the evaporation cost ladder at the 5,000-foot break), the tainted-water effects (the mild 6-hour and severe 18-hour minimum durations vs the food 12/24), the taint-severity geography (low elevation and warm climates) and the bad-water warnings (the taste-and-appearance deception, the bacteria and poison layer, the skeletal-remains waterhole) - every const and bool verified against the model.",
    },
}
