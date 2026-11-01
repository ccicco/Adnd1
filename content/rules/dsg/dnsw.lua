-- dnsw: promoted from tools/spec_r524.json (the The DSG HIRELING LOYALTY AND THE P. 55 HAZARDS, R524: printed pp. 54-55 (pdf 55-56) - the hireling loyalty: a PC group cannot usually run a mine alone (even with a miner-proficiency supervisor, a large mine needs hired strong arms; adventurers better used as scouts and guards when the claim is questionable or monsters possible), loyalty insignificant in iron or copper mines but a precious-metal or gemstone find a great temptation, the standard DMG page-36 Loyalty Check with the foreman as the liege, the + or - 10% security modifiers (a post-shift search +10%, no PCs present at shift end -10%), pay evaluated against the mine's value (the 1,000 gp of diamonds for a 20 gp wage), and the failed check not an immediate grab-and-run - the DM weighs the NPC's Intelligence, only perhaps 8-or-less attempting unplanned theft, exceptionally high Intelligence preparing the theft and the getaway or concealment, the thief stealing 1d6 x 10% of his daily output; the natural hazards: flooding from a tapped underground water body or digging below the water table (adjudicated from the DM's map, the below-level escape very difficult, at-level a race to the exit, above-level easy; the flooded mine needing draining or pumping), and mine cave-ins (shoring partially preventing but never eliminating - a tunnel shored every 10 feet at 2% weekly, no shoring 50%, partial shoring interpolated; external forces adding an earthquake 1d4 x 10%, a heavy rain or flood 1d3 x 10%, burrowers like umber hulks and ankhegs 1% per hit die; the d100 location roll from one designated end 01 to the other 100; the automatic 20-foot-long, 10-foot-thick fallen ceiling; chain reactions checked normally); and the unnatural hazards: the unnamed evil lurking deep in the earth at DM creativity (the burial-ground undead, the concerned deep monsters), the drow and duergar regarding mineral wealth as their own with intervention rising in direct proportion to the mine's value, and the planar-gate risk - the vigorous miners breaking through to another plane, or much more likely some horrid lower-plane denizen finding a path into the world up the deep-plunging tunnel);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 524,
  "prefix" = "dnsw",
  "banner" = {
      "title" = "The DSG HIRELING LOYALTY AND THE P. 55 HAZARDS, R524: printed pp. 54-55 (pdf 55-56) - the hireling loyalty: a PC group cannot usually run a mine alone (even with a miner-proficiency supervisor, a large mine needs hired strong arms; adventurers better used as scouts and guards when the claim is questionable or monsters possible), loyalty insignificant in iron or copper mines but a precious-metal or gemstone find a great temptation, the standard DMG page-36 Loyalty Check with the foreman as the liege, the + or - 10% security modifiers (a post-shift search +10%, no PCs present at shift end -10%), pay evaluated against the mine's value (the 1,000 gp of diamonds for a 20 gp wage), and the failed check not an immediate grab-and-run - the DM weighs the NPC's Intelligence, only perhaps 8-or-less attempting unplanned theft, exceptionally high Intelligence preparing the theft and the getaway or concealment, the thief stealing 1d6 x 10% of his daily output; the natural hazards: flooding from a tapped underground water body or digging below the water table (adjudicated from the DM's map, the below-level escape very difficult, at-level a race to the exit, above-level easy; the flooded mine needing draining or pumping), and mine cave-ins (shoring partially preventing but never eliminating - a tunnel shored every 10 feet at 2% weekly, no shoring 50%, partial shoring interpolated; external forces adding an earthquake 1d4 x 10%, a heavy rain or flood 1d3 x 10%, burrowers like umber hulks and ankhegs 1% per hit die; the d100 location roll from one designated end 01 to the other 100; the automatic 20-foot-long, 10-foot-thick fallen ceiling; chain reactions checked normally); and the unnatural hazards: the unnamed evil lurking deep in the earth at DM creativity (the burial-ground undead, the concerned deep monsters), the drow and duergar regarding mineral wealth as their own with intervention rising in direct proportion to the mine's value, and the planar-gate risk - the vigorous miners breaking through to another plane, or much more likely some horrid lower-plane denizen finding a path into the world up the deep-plunging tunnel",
      "provenance" = "the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf = printed + 1; the text read from the IA djvu OCR (djvu.txt lines ~7048-7215) with the pdf Acrobat-Capture layer as the second read (idx 127 = the printed p. 54 window, idx 129 = the printed p. 55 window); the compiled-tables appendix has no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on every load-bearing number - the 10% modifiers, the Intelligence-8 threshold, the 1d6 x 10% theft, the 2%/50% shored/unshored weekly cave-in chances, the 1d4 x 10% earthquake and 1d3 x 10% rain adds, the 1% per hit die, the d100 location roll, the 20 x 10 ft ceiling, and the 1200-ft/30-roll/360-ft worked example. SEAMS: the DMG page-36 Loyalty Check (cross-book, nothing auto-credited), the R520 shoring rules (the every-10-foot interval matching the R520 per-10-foot-section braces), the R511 chain-reaction cave-in rules, the R518 water-travel rules, and the R503 hazards survey. The mining block is fully closed with this round (all children 118-133 flipped); the natural/unnatural hazards are the last open children of the big underground-environment chapter (pp. 36-55), so the chapter parent line becomes closeable at the next census check. The new-equipment chapter (Table 35) starts the NEXT round per the content-density rule.",
      "sentinel" = "A prose round: no tables pin. The dice pin as consts per the R508 convention - the 1d6 x 10% theft of daily output, the 1d4 x 10% earthquake and 1d3 x 10% rain cave-in adds, and the d100 end-to-end cave-in location roll. The thresholds pin as consts: the 10% loyalty modifiers, the Intelligence-8 unplanned-theft line, the 2%/50% shored/unshored weekly chances, the 1% per hit die of burrowers, and the 20 x 10 ft fallen ceiling. The rest pins as prose bools: the hired-help and scout/guard split, the temptation and pay-evaluation rules, the foreman-as-liege check, the Intelligence-driven theft planning, the flooding adjudication and escape gradient, the shoring interpolation, the chain-reaction reference, and the unnamed-evil, burial-ground, deep-monster, jealous-race and planar-gate threats. The DMG-36, R520, R511 and R518 seams are noted; nothing auto-credits.",
    },
  "consts" = { {
      "name" = "dnswLoyaltyModPct",
      "value" = 10,
      "comment" = "the mine-security loyalty modifiers are + or - 10% (a post-shift search +10%, no PCs present at the shift end -10%).",
    }, {
      "name" = "dnswTheftDice",
      "value" = 1,
      "comment" = "the thief-output roll is one die.",
    }, {
      "name" = "dnswTheftSides",
      "value" = 6,
      "comment" = "the thief steals 1d6 x 10% of his daily output.",
    }, {
      "name" = "dnswTheftPctMult",
      "value" = 10,
      "comment" = "the 1d6 result times 10 is the percent of daily output stolen.",
    }, {
      "name" = "dnswLowIntUnplanned",
      "value" = 8,
      "comment" = "only workers with low Intelligence, perhaps 8 or less, attempt a theft with no planning.",
    }, {
      "name" = "dnswShoredCaveInPct",
      "value" = 2,
      "comment" = "a tunnel shored at every 10-foot interval stands only a 2% chance per week of a cave-in (the R520 shoring seam).",
    }, {
      "name" = "dnswUnshoredCaveInPct",
      "value" = 50,
      "comment" = "a tunnel with no shoring whatsoever runs a 50% weekly chance of a cave-in.",
    }, {
      "name" = "dnswQuakeDice",
      "value" = 1,
      "comment" = "the earthquake modifier roll is one die.",
    }, {
      "name" = "dnswQuakeSides",
      "value" = 4,
      "comment" = "an earthquake adds 1d4 x 10% to the cave-in chance.",
    }, {
      "name" = "dnswQuakePctMult",
      "value" = 10,
      "comment" = "the 1d4 result times 10 is the earthquake percent add.",
    }, {
      "name" = "dnswRainDice",
      "value" = 1,
      "comment" = "the heavy-rain modifier roll is one die.",
    }, {
      "name" = "dnswRainSides",
      "value" = 3,
      "comment" = "a heavy rain or flood increases the cave-in chance by 1d3 x 10%.",
    }, {
      "name" = "dnswRainPctMult",
      "value" = 10,
      "comment" = "the 1d3 result times 10 is the rain percent add.",
    }, {
      "name" = "dnswBurrowerPctPerHitDie",
      "value" = 1,
      "comment" = "burrowing creatures such as umber hulks and ankhegs increase the cave-in chance by 1% per hit die of intruding monsters.",
    }, {
      "name" = "dnswCaveInLocDice",
      "value" = 1,
      "comment" = "the cave-in location roll is one die.",
    }, {
      "name" = "dnswCaveInLocSides",
      "value" = 100,
      "comment" = "the DM designates one end of the mine 01 and the other 100 and rolls d100: the result places the cave-in along the tunnel (a 30 on a 1200-foot shaft is about 360 feet from the entrance).",
    }, {
      "name" = "dnswCaveInLenFt",
      "value" = 20,
      "comment" = "a cave-in automatically brings down a ceiling section 20 feet long.",
    }, {
      "name" = "dnswCaveInThickFt",
      "value" = 10,
      "comment" = "the fallen ceiling section is 10 feet thick.",
    } },
  "bools" = { {
      "name" = "dnswHiredHelpRequired",
      "value" = true,
      "comment" = "a PC group cannot usually run a mining operation by themselves - even with a miner-proficiency supervisor, a large mine requires hired strong arms.",
    }, {
      "name" = "dnswAdventurersScoutAndGuard",
      "value" = true,
      "comment" = "if the claim is of questionable legality or a monster attack is possible, skilled adventurers are better used as scouts and guards while low-level laborers excavate.",
    }, {
      "name" = "dnswPreciousFindsTempt",
      "value" = true,
      "comment" = "hireling loyalty is not a significant problem in an iron or copper mine, but a precious metal or gemstone find presents employees a great opportunity to steal.",
    }, {
      "name" = "dnswDmg36LoyaltyCheck",
      "value" = true,
      "comment" = "the NPC reaction to temptation uses the standard Loyalty Check procedure outlined in the DMG on page 36 (the cross-book seam).",
    }, {
      "name" = "dnswForemanIsLiege",
      "value" = true,
      "comment" = "for this Loyalty Check, treat the foreman of the mining operation as the liege when determining modifiers.",
    }, {
      "name" = "dnswSecurityModifiers",
      "value" = true,
      "comment" = "additional + or - 10% modifiers reflect the mine's security: a post-shift search deters theft (+10%), while no PCs present as the miners leave invites it (-10%).",
    }, {
      "name" = "dnswPayJudgedAgainstMineValue",
      "value" = true,
      "comment" = "for loyalty modification, the NPC's pay is evaluated against the value of the mine - a miner excavating 1,000 gp of diamonds for 20 gp feels underpaid however good the wage.",
    }, {
      "name" = "dnswFailedCheckNotImmediate",
      "value" = true,
      "comment" = "a failed Loyalty Check does not mean the NPC immediately pockets valuables and runs - the DM must consider the NPC's Intelligence and concoct a suitable theft plan.",
    }, {
      "name" = "dnswHighIntPlansTheft",
      "value" = true,
      "comment" = "an exceptionally high Intelligence thief goes to great lengths preparing the theft and ensuring the getaway or concealing that the theft occurred.",
    }, {
      "name" = "dnswFloodFromTappedWater",
      "value" = true,
      "comment" = "flooding occurs if excavators accidentally tap an underground body of water or dig below the water table; the chance depends on the proximity of such bodies, adjudicated from a carefully drawn DM map.",
    }, {
      "name" = "dnswFloodEscapeGradient",
      "value" = true,
      "comment" = "characters below the water level have a very difficult time escaping, characters at the flow level race the water to the nearest exit, and characters above escape with relative ease.",
    }, {
      "name" = "dnswFloodedMineNeedsPumping",
      "value" = true,
      "comment" = "after a flood disaster a mine is very difficult to work unless the water can be drained or pumped away; a mine reaching the water table slowly fills and closes unless water is removed faster than it flows in.",
    }, {
      "name" = "dnswShoringPartialNotTotal",
      "value" = true,
      "comment" = "proper shoring partially prevents but cannot eliminate cave-ins; a partially shored tunnel's chance is calculated by the DM between the 2% and 50% extremes.",
    }, {
      "name" = "dnswExternalForcesAdd",
      "value" = true,
      "comment" = "external forces add to the cave-in chance: an earthquake 1d4 x 10%, a heavy rain or flood 1d3 x 10%, and burrowing creatures 1% per hit die.",
    }, {
      "name" = "dnswChainReactionNormal",
      "value" = true,
      "comment" = "chain reaction cave-ins are checked for normally (the R511 seam).",
    }, {
      "name" = "dnswUnnamedEvilLurks",
      "value" = true,
      "comment" = "a common element of Underdark campaigns is the unnamed evil lurking deep within the earth - the exact encounter is the DM's creativity, with many things possible where magic is common.",
    }, {
      "name" = "dnswBurialGroundUndead",
      "value" = true,
      "comment" = "the excavation might penetrate a long-forgotten burial ground, awakening its hideous undead denizens.",
    }, {
      "name" = "dnswDeepMonstersConcerned",
      "value" = true,
      "comment" = "deep-dwelling monsters may become concerned about surface dwellers penetrating so far under the earth.",
    }, {
      "name" = "dnswUnderdarkRacesJealous",
      "value" = true,
      "comment" = "Underdark races such as the drow and the duergar regard mineral wealth as their own and look jealously on outsiders exploiting it - the intervention threat rises in direct proportion to the mine's value.",
    }, {
      "name" = "dnswPlanarGateRisk",
      "value" = true,
      "comment" = "vigorous mining might discover a gate to another plane: miners might pass through inadvertently, or - much more likely - some horrid lower-plane denizen finds a path into the world up the deep-plunging tunnel.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnswLoyaltyModPct']() != 10 or m['dnswTheftDice']() != 1 or m['dnswTheftSides']() != 6 or m['dnswTheftPctMult']() != 10 or m['dnswLowIntUnplanned']() != 8",
      "note" = "the loyalty numbers: the 10% security modifiers, the 1d6 x 10% daily-output theft, and the Intelligence-8 unplanned threshold.",
    }, {
      "expr" = "m['dnswShoredCaveInPct']() != 2 or m['dnswUnshoredCaveInPct']() != 50 or m['dnswQuakeDice']() != 1 or m['dnswQuakeSides']() != 4 or m['dnswQuakePctMult']() != 10 or m['dnswRainDice']() != 1 or m['dnswRainSides']() != 3 or m['dnswRainPctMult']() != 10 or m['dnswBurrowerPctPerHitDie']() != 1",
      "note" = "the cave-in chances: 2% shored vs 50% unshored weekly, the 1d4 x 10% earthquake and 1d3 x 10% rain adds, and the 1% per hit die of burrowers.",
    }, {
      "expr" = "m['dnswCaveInLocDice']() != 1 or m['dnswCaveInLocSides']() != 100 or m['dnswCaveInLenFt']() != 20 or m['dnswCaveInThickFt']() != 10",
      "note" = "the cave-in geometry: the d100 end-to-end location roll and the 20-foot-long, 10-foot-thick fallen ceiling section.",
    }, {
      "expr" = "m['dnswDmg36LoyaltyCheck']() != 1 or m['dnswForemanIsLiege']() != 1 or m['dnswFailedCheckNotImmediate']() != 1 or m['dnswHighIntPlansTheft']() != 1 or m['dnswFloodFromTappedWater']() != 1 or m['dnswShoringPartialNotTotal']() != 1 or m['dnswUnderdarkRacesJealous']() != 1 or m['dnswPlanarGateRisk']() != 1",
      "note" = "the prose seams: the DMG p. 36 check with the foreman as liege, the Intelligence-driven theft planning, the flooding adjudication, the partial-shoring interpolation, and the jealous-race and planar-gate threats.",
    } },
  "audit" = {
      "label" = "R524 DSG loyalty hazards audit",
      "comment" = "The DSG hireling loyalty and p. 55 hazards pins the loyalty check (the DMG page-36 procedure with the foreman as liege, the 10% security modifiers, the pay judged against the mine value, the Intelligence-driven theft planning at the 8-or-less unplanned threshold, and the 1d6 x 10% daily-output theft), the flooding hazard (the tapped water body and water table, the escape gradient, the drained-or-pumped recovery), the mine cave-ins (the 2%/50% shored/unshored weekly chances with interpolation, the 1d4 x 10% earthquake, 1d3 x 10% rain and 1%-per-hit-die burrower adds, the d100 location roll, and the 20 x 10 ft fallen ceiling with normal chain reactions), and the unnatural hazards (the unnamed evil, the burial-ground undead, the jealous drow and duergar with intervention proportional to the mine's value, and the planar-gate risk).",
    },
}
