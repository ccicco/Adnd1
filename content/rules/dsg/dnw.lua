-- dnw: promoted from tools/spec_r511.json (the The DSG CAVE-INS PART I, R511: the printed pp. 38-39 (pdf 39-40) - the opener (cave-ins unique to the underground environment, the roof-collapse chance considered when excavating, using explosive magic or otherwise stressing the overhanging rock, the bridge and floor collapses, the trigger-as-attack ploy with its chain-reaction risk), the causes (the natural-disaster causes - floods, earthquakes, volcanic eruptions - with the spell-duplicates-disaster rule and the raise water example, the ripe areas noted on the maps, the accidental causes on the frailest locations - weight or sound, the DM-assigned percentage with the 5% ledge example, the laden/mule modification, the run and melee doublings, the sound-trigger with the 1% sword-clash example, the excavation causes - double the accidental chance, the 10% per turn, the mining and shoring seam, the sabotage causes - the sixths splits with and without miner proficiency), the random occurrences (the base 1% per day, the 10% per 10 days long-expedition option, the near-the-PCs-not-on-top rule) and the Table 17 eight-band location grid with the movement-relative directions, the higher-roll-farther-away rule, the may-go-undiscovered note and the decayed-stone double-or-triple);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 511,
  "prefix" = "dnw",
  "banner" = {
      "title" = "The DSG CAVE-INS PART I, R511: the printed pp. 38-39 (pdf 39-40) - the opener (cave-ins unique to the underground environment, the roof-collapse chance considered when excavating, using explosive magic or otherwise stressing the overhanging rock, the bridge and floor collapses, the trigger-as-attack ploy with its chain-reaction risk), the causes (the natural-disaster causes - floods, earthquakes, volcanic eruptions - with the spell-duplicates-disaster rule and the raise water example, the ripe areas noted on the maps, the accidental causes on the frailest locations - weight or sound, the DM-assigned percentage with the 5% ledge example, the laden/mule modification, the run and melee doublings, the sound-trigger with the 1% sword-clash example, the excavation causes - double the accidental chance, the 10% per turn, the mining and shoring seam, the sabotage causes - the sixths splits with and without miner proficiency), the random occurrences (the base 1% per day, the 10% per 10 days long-expedition option, the near-the-PCs-not-on-top rule) and the Table 17 eight-band location grid with the movement-relative directions, the higher-roll-farther-away rule, the may-go-undiscovered note and the decayed-stone double-or-triple",
      "provenance" = "the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf = printed + 1; the text read from the IA djvu OCR with the pdf Acrobat-Capture layer as the second read - every numeric cell dual-confirmed: the djvu garbles 596 = 5%, 196 = 1% and 1096 = 10% (the percent sign OCR) are settled by the Capture layer (the explicit 5% chance per character crossing the ledge, the 1% per round of clashing swords, the 10% chance per turn of excavation); the Table 17 bands confirmed THREE WAYS - the chapter djvu read, the compiled-tables appendix reprint (djvu.txt line 15539) and the Capture layer agree on all eight rows; the djvu/Acrobat garbles lias/tias occurred = has occurred. The CAVE-IN CHAIN REACTIONS heading and prose (Table 18) and the Effects of Cave-ins section start the NEXT round per the content-density rule (the R507-to-R508 tail precedent).",
      "sentinel" = "Table 17 pins as an 8x3 grid: the row key plus the lo and hi ends of each d100 band, with 00 read as 100 (the 96-00 band pins as 96-100). The sabotage splits pin in SIXTHS - the exact-integer encoding of the printed fractions: without miner proficiency 1/3, 1/3, 1/3 = 2+2+2 of 6; with miner proficiency 2/3, 1/6, 1/6 = 4+1+1 of 6. The R508 Battlesystem cave-in pins are the mass-combat seam and the R512 chain-reaction section follows - nothing auto-credited.",
    },
  "consts" = { {
      "name" = "dnwSabotageNoMinerSuccessSixths",
      "value" = 2,
      "comment" = "a character without miner proficiency who makes a sabotage attempt has a 1/3 chance of successfully completing his task - 2 of 6.",
    }, {
      "name" = "dnwSabotageNoMinerTooStrongSixths",
      "value" = 2,
      "comment" = "without miner proficiency, a 1/3 chance of leaving the structure too strong to collapse - 2 of 6.",
    }, {
      "name" = "dnwSabotageNoMinerSelfCollapseSixths",
      "value" = 2,
      "comment" = "without miner proficiency, a 1/3 chance of bringing the structure down upon himself - 2 of 6.",
    }, {
      "name" = "dnwSabotageMinerSuccessSixths",
      "value" = 4,
      "comment" = "a character with miner proficiency has a 2/3 chance of successfully sabotaging the area - 4 of 6.",
    }, {
      "name" = "dnwSabotageMinerUnderdamageSixths",
      "value" = 1,
      "comment" = "with miner proficiency, a 1/6 chance of not damaging the structure enough - 1 of 6.",
    }, {
      "name" = "dnwSabotageMinerSelfCollapseSixths",
      "value" = 1,
      "comment" = "with miner proficiency, a 1/6 chance of damaging it so extensively that it collapses during the sabotage attempt - 1 of 6.",
    }, {
      "name" = "dnwAccidentalLedgeExamplePct",
      "value" = 5,
      "comment" = "a ledge might have eroded to the point where it has a 5% chance of collapsing per character crossing it (the djvu garble 596, settled by the Acrobat layer).",
    }, {
      "name" = "dnwSwordClashCollapsePctPerRound",
      "value" = 1,
      "comment" = "the clashing of swords in combat might give a 1% chance per round of a cave-in on a sound-fragile area (the djvu garble 196).",
    }, {
      "name" = "dnwExcavationCollapsePctPerTurn",
      "value" = 10,
      "comment" = "there is about a 10% chance per turn that a weakened ceiling or tunnel wall collapses during excavation (the djvu garble 1096).",
    }, {
      "name" = "dnwExcavationChanceMult",
      "value" = 2,
      "comment" = "the possibility of a cave-in while digging an escape tunnel or clearing rubble is about double that of an accidental cave-in.",
    }, {
      "name" = "dnwRandomCaveInPctPerDay",
      "value" = 1,
      "comment" = "the base chance for a cave-in during underground exploration is 1% per day.",
    }, {
      "name" = "dnwRandomCaveInLongExpeditionPct",
      "value" = 10,
      "comment" = "on long expeditions the DM may wish to alter the daily roll to a 10% chance.",
    }, {
      "name" = "dnwRandomCaveInLongExpeditionDays",
      "value" = 10,
      "comment" = "the long-expedition cave-in roll is made every 10 days.",
    }, {
      "name" = "dnwDecayedChanceMultMax",
      "value" = 3,
      "comment" = "in areas of exceptionally decayed stone or rotten supporting timbers, such considerations could double, or perhaps triple, the chance of a randomly occurring cave-in.",
    }, {
      "name" = "dnwRunChanceMult",
      "value" = 2,
      "comment" = "the chance of collapse may be doubled if the characters run across a weakened ledge, since the pounding is much harder than when walking slowly.",
    }, {
      "name" = "dnwMeleeChanceMult",
      "value" = 2,
      "comment" = "the chance of collapse should be doubled for melee combat on a fragile surface, because of the additional pounding the surface takes.",
    }, {
      "name" = "dnwT17RowCount",
      "value" = 8,
      "comment" = "the Table 17 carries eight location bands: on top, immediately in front, immediately behind, in front within hearing, behind within hearing, well behind out of hearing, well in front out of hearing, and the entrance.",
    } },
  "bools" = { {
      "name" = "dnwCaveInUniqueToUnderground",
      "value" = true,
      "comment" = "cave-ins are unique to the underground environment.",
    }, {
      "name" = "dnwConsideredWhenStressingRock",
      "value" = true,
      "comment" = "the chance that the roof of an underground location may cave in must be considered especially if characters are excavating, using explosive magic, or otherwise placing stress on the overhanging rock.",
    }, {
      "name" = "dnwBridgeFloorAlsoEndanger",
      "value" = true,
      "comment" = "cave-ins can also endanger characters in other ways: a bridge being crossed may collapse, or a floor may give way, dropping those standing on it amid tons of jagged, crushing rock.",
    }, {
      "name" = "dnwTriggerAsAttackChainRisk",
      "value" = true,
      "comment" = "characters may try to trigger a cave-in as a means of attacking an enemy; such attempts must be made cautiously, since a cave-in may create a chain reaction that collapses a far larger area than intended.",
    }, {
      "name" = "dnwStrongStructureOnlyDisasters",
      "value" = true,
      "comment" = "a strong cavern, dungeon, or realm is only susceptible to cave-ins as a result of natural disasters such as floods, earthquakes, or volcanic eruptions.",
    }, {
      "name" = "dnwSpellDuplicatesDisaster",
      "value" = true,
      "comment" = "certain magical spells that duplicate natural disasters can duplicate their destructive effects; a raise water spell that creates a flood in a tunnel should be treated as a natural flood.",
    }, {
      "name" = "dnwMajorDisasterDmJudgment",
      "value" = true,
      "comment" = "in the case of a major natural disaster the DM's judgment determines the exact area of effect; the far-reaching effects of a major earthquake might actually annihilate an entire subterranean realm.",
    }, {
      "name" = "dnwRipeAreasNotedOnMaps",
      "value" = true,
      "comment" = "underground areas ripe for cave-ins - aging or recent-disaster-weakened, needing only a slight additional pressure - should be noted when the maps for an underground area are prepared.",
    }, {
      "name" = "dnwAccidentalOnlyFrailest",
      "value" = true,
      "comment" = "only the frailest of underground locations are susceptible to accidental cave-ins.",
    }, {
      "name" = "dnwAccidentalWeightOrSound",
      "value" = true,
      "comment" = "accidental collapses are triggered by the weight of a creature walking across a weak spot, or even by the sounds created by characters or creatures.",
    }, {
      "name" = "dnwDmAssignsCollapsePct",
      "value" = true,
      "comment" = "based on the weakness of the area under consideration, the DM should assign a percentage chance of a collapse occurring.",
    }, {
      "name" = "dnwLadenOrBeastsModifyPct",
      "value" = true,
      "comment" = "the collapse chance should be modified if the characters are very heavily laden, or accompanied by mules or other creatures.",
    }, {
      "name" = "dnwRunDoublesChance",
      "value" = true,
      "comment" = "the chance of collapse may be doubled if the characters run across a weakened surface.",
    }, {
      "name" = "dnwMeleeDoublesChance",
      "value" = true,
      "comment" = "if characters participate in melee combat on a fragile surface, the weight of all participating creatures must be figured in - carefully, for nonhuman creatures such as ogres - and the chance of collapse should be doubled.",
    }, {
      "name" = "dnwOffPositionReducedChance",
      "value" = true,
      "comment" = "where the weakened area is not directly beneath the characters, the chance of a cave-in is reduced; unless the characters apply weight to the area, sound is the only other likely avenue for causing an accidental collapse.",
    }, {
      "name" = "dnwSoundChanceByLoudness",
      "value" = true,
      "comment" = "the intensity of the sound must be considered, with a percentage chance of collapse assigned according to the loudness and sharpness of the noise; an area might stand no chance under normal conversation but the clashing of swords might give a 1% chance per round.",
    }, {
      "name" = "dnwExcavationRisksSupport",
      "value" = true,
      "comment" = "whenever characters or creatures are digging into the earth, they run the risk of excavating away a significant support for the ceiling, causing a cave-in.",
    }, {
      "name" = "dnwMiningMostCommonCause",
      "value" = true,
      "comment" = "mining is the most common cause of excavation cave-ins, and precautions such as shoring up an excavated passage are usually taken by the miners - the mining-rules seam.",
    }, {
      "name" = "dnwUnshoredEscapeTunnelRisk",
      "value" = true,
      "comment" = "characters digging an escape tunnel or clearing rubble from a previous cave-in are often unable to properly shore up their excavated passage; weakened surfaces then stand a fair chance of collapsing.",
    }, {
      "name" = "dnwSabotageNeedsMinerProficiency",
      "value" = true,
      "comment" = "to chip stone away to the point where a collapse is likely requires some skill at stonework and a little luck; a character must have miner proficiency to have a decent chance of successfully sabotaging an underground area.",
    }, {
      "name" = "dnwSabotageMayCrushSaboteur",
      "value" = true,
      "comment" = "many areas subject to sabotage collapse on the heads of the saboteurs themselves.",
    }, {
      "name" = "dnwSabotageTargetsAccessible",
      "value" = true,
      "comment" = "columns that support a ceiling, bridge supports, or narrow layers of rock walked over are obvious sabotage targets; the soaring ceiling of a vast chamber is very difficult to damage, while its supporting columns are much more accessible.",
    }, {
      "name" = "dnwSabotageTimeAndNoise",
      "value" = true,
      "comment" = "sabotage attempts take considerable time and create quite a bit of noise; see the excavation rules for how long it might take to chisel through a column - the page-50 seam.",
    }, {
      "name" = "dnwRandomChanceGrowsWithTime",
      "value" = true,
      "comment" = "if a campaign focuses on the underground for extended periods, the chance of a naturally occurring cave-in affecting the characters increases.",
    }, {
      "name" = "dnwRandomMeansNearNotOnTop",
      "value" = true,
      "comment" = "a successful random-occurrence roll means a cave-in has occurred somewhere in the underground region near the PCs - not on top of the characters, and not necessarily within their earshot.",
    }, {
      "name" = "dnwT17RelativeToMovement",
      "value" = true,
      "comment" = "all Table 17 directions relate to the party's direction of movement at the time of the cave-in.",
    }, {
      "name" = "dnwHigherRollFartherAway",
      "value" = true,
      "comment" = "in the categories indicating a cave-in some distance away, the higher the roll, the farther away the cave-in.",
    }, {
      "name" = "dnwCaveInMayGoUndiscovered",
      "value" = true,
      "comment" = "it is quite possible for a group of characters to fail to discover a cave-in that occurs during their adventures.",
    }, {
      "name" = "dnwDecayedStoneChanceIncrease",
      "value" = true,
      "comment" = "in areas of exceptionally decayed stone, or of rotten supporting timbers, the DM may increase the chance of a randomly occurring cave-in - possibly doubling or tripling it.",
    }, {
      "name" = "dnwExcavationChanceAboutDouble",
      "value" = true,
      "comment" = "the possibility of a cave-in while digging without proper shoring is about double that of an accidental cave-in, with about a 10% chance per turn of a weakened ceiling or tunnel wall collapsing.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 17: CAVE-IN LOCATION",
      "tag" = "17",
      "count" = "dnwT17RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnwT17Loc", "dnwT17Lo", "dnwT17Hi" },
      "col_comments" = { "the row key: 0 on top of the PCs, 1 immediately in front, 2 immediately behind, 3 in front within hearing range, 4 behind within hearing range, 5 well behind out of hearing range, 6 well in front out of hearing range, 7 at the entrance the PCs used to get underground.", "the low end of the d100 roll band.", "the high end of the d100 roll band; a rolled 00 reads as 100, so the last band pins as 96-100." },
      "audit_comment" = "the Table 17 cave-in location grid",
      "data" = { { 0, 1, 1 }, { 1, 2, 3 }, { 2, 4, 5 }, { 3, 6, 10 }, { 4, 11, 15 }, { 5, 16, 55 }, { 6, 56, 95 }, { 7, 96, 100 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnwSabotageNoMinerSuccessSixths']() != 2 or m['dnwSabotageNoMinerTooStrongSixths']() != 2 or m['dnwSabotageNoMinerSelfCollapseSixths']() != 2 or m['dnwSabotageMinerSuccessSixths']() != 4 or m['dnwSabotageMinerUnderdamageSixths']() != 1 or m['dnwSabotageMinerSelfCollapseSixths']() != 1",
      "note" = "the sabotage splits in sixths: without miner proficiency 1/3-1/3-1/3 (2+2+2 of 6), with miner proficiency 2/3-1/6-1/6 (4+1+1 of 6).",
    }, {
      "expr" = "m['dnwAccidentalLedgeExamplePct']() != 5 or m['dnwSwordClashCollapsePctPerRound']() != 1 or m['dnwExcavationCollapsePctPerTurn']() != 10 or m['dnwExcavationChanceMult']() != 2",
      "note" = "the printed percentages: the 5% ledge example, the 1% per round of clashing swords, and the 10% per turn of unshored excavation at about double the accidental chance (the djvu garbles 596/196/1096 settled by the Acrobat layer).",
    }, {
      "expr" = "m['dnwRandomCaveInPctPerDay']() != 1 or m['dnwRandomCaveInLongExpeditionPct']() != 10 or m['dnwRandomCaveInLongExpeditionDays']() != 10 or m['dnwDecayedChanceMultMax']() != 3",
      "note" = "the random occurrences: the base 1% per day, the 10% every 10 days long-expedition option, and the decayed-stone increase up to a triple.",
    }, {
      "expr" = "m['dnwRunChanceMult']() != 2 or m['dnwMeleeChanceMult']() != 2 or m['dnwLadenOrBeastsModifyPct']() != 1",
      "note" = "the collapse-chance modifiers: doubled when running, doubled in melee on a fragile surface, and modified when heavily laden or accompanied by mules or other creatures.",
    }, {
      "expr" = "m['dnwT17Loc'](0) != 0 or m['dnwT17Lo'](0) != 1 or m['dnwT17Hi'](0) != 1 or m['dnwT17Loc'](7) != 7 or m['dnwT17Lo'](7) != 96 or m['dnwT17Hi'](7) != 100",
      "note" = "the Table 17 first and last bands: 01 on top of the PCs, and 96-00 (pinned 96-100) at the entrance the PCs used to get underground.",
    }, {
      "expr" = "m['dnwT17Lo'](1) != 2 or m['dnwT17Hi'](1) != 3 or m['dnwT17Lo'](2) != 4 or m['dnwT17Hi'](2) != 5 or m['dnwT17Lo'](3) != 6 or m['dnwT17Hi'](3) != 10 or m['dnwT17Lo'](4) != 11 or m['dnwT17Hi'](4) != 15",
      "note" = "the Table 17 immediate and within-hearing bands: 02-03 immediately in front, 04-05 immediately behind, 06-10 in front within hearing, 11-15 behind within hearing.",
    }, {
      "expr" = "m['dnwT17Lo'](5) != 16 or m['dnwT17Hi'](5) != 55 or m['dnwT17Lo'](6) != 56 or m['dnwT17Hi'](6) != 95",
      "note" = "the Table 17 out-of-hearing bands: 16-55 well behind the PCs, 56-95 well in front of the PCs.",
    }, {
      "expr" = "m['dnwCaveInUniqueToUnderground']() != 1 or m['dnwConsideredWhenStressingRock']() != 1 or m['dnwBridgeFloorAlsoEndanger']() != 1 or m['dnwTriggerAsAttackChainRisk']() != 1",
      "note" = "the opener: cave-ins unique to the underground environment, considered when excavating or using explosive magic or stressing the overhanging rock, the bridge and floor collapses, and the trigger-as-attack ploy with its chain-reaction risk.",
    }, {
      "expr" = "m['dnwStrongStructureOnlyDisasters']() != 1 or m['dnwSpellDuplicatesDisaster']() != 1 or m['dnwMajorDisasterDmJudgment']() != 1 or m['dnwRipeAreasNotedOnMaps']() != 1",
      "note" = "the natural causes: only strong structures susceptible to floods, earthquakes and volcanic eruptions, the spell-duplicates-disaster rule, the major-disaster DM judgment, and the ripe areas noted on the maps.",
    }, {
      "expr" = "m['dnwAccidentalOnlyFrailest']() != 1 or m['dnwAccidentalWeightOrSound']() != 1 or m['dnwDmAssignsCollapsePct']() != 1 or m['dnwOffPositionReducedChance']() != 1 or m['dnwSoundChanceByLoudness']() != 1",
      "note" = "the accidental causes: only the frailest locations, triggered by weight or sound, with the DM-assigned percentage, the reduced off-position chance and the sound scale by loudness and sharpness.",
    }, {
      "expr" = "m['dnwExcavationRisksSupport']() != 1 or m['dnwMiningMostCommonCause']() != 1 or m['dnwUnshoredEscapeTunnelRisk']() != 1 or m['dnwExcavationChanceAboutDouble']() != 1",
      "note" = "the excavation causes: digging away a significant ceiling support, mining the most common cause with the shoring seam, and the unshored escape-tunnel risk at about double the accidental chance.",
    }, {
      "expr" = "m['dnwSabotageNeedsMinerProficiency']() != 1 or m['dnwSabotageMayCrushSaboteur']() != 1 or m['dnwSabotageTargetsAccessible']() != 1 or m['dnwSabotageTimeAndNoise']() != 1",
      "note" = "the sabotage causes: the miner-proficiency requirement, the collapses on the saboteurs themselves, the accessible targets, and the considerable time and noise.",
    }, {
      "expr" = "m['dnwRandomChanceGrowsWithTime']() != 1 or m['dnwRandomMeansNearNotOnTop']() != 1 or m['dnwT17RelativeToMovement']() != 1 or m['dnwHigherRollFartherAway']() != 1 or m['dnwCaveInMayGoUndiscovered']() != 1 or m['dnwDecayedStoneChanceIncrease']() != 1",
      "note" = "the random-occurrence reading: the chance grows with underground time, the cave-in lands near but not on the PCs, the directions are relative to the party's movement, the higher roll is the farther away, the cave-in may go undiscovered, and decayed stone can double or triple the chance.",
    } },
  "audit" = {
      "label" = "R511 DSG cave-in causes audit",
      "comment" = "The DSG cave-in causes pins the opener (cave-ins unique to the underground environment, the chance considered when excavating, using explosive magic or placing stress on the overhanging rock, the bridge and floor collapses endangering characters in other ways, the trigger-as-attack ploy that must be made cautiously for its chain-reaction risk), the natural causes (only strong structures susceptible, to floods, earthquakes and volcanic eruptions; the spell that duplicates a disaster duplicates its effect, the raise water flood example; the major-disaster DM judgment that could annihilate a realm; the ripe areas noted when the maps are prepared), the accidental causes (only the frailest locations, triggered by the weight of a creature walking or by sounds, the DM-assigned percentage by weakness, the 5% ledge example modified when laden or accompanied by mules, the doubled chance when running, the melee doubling with all participating weights figured carefully for nonhumans, the reduced chance when the weak area is not directly beneath with sound the only other avenue, the sound chance by loudness and sharpness with the no-chance conversation and the 1% sword-clash examples), the excavation causes (digging away a significant ceiling support, mining the most common cause, the shoring precaution with the mining-rules seam, the escape-tunnel and rubble-clearing risk of about double the accidental chance, the 10% per turn), the sabotage causes (the opportune collapse, the collapses on the saboteurs themselves, the accessible targets - the columns, bridge supports and narrow rock layers against the soaring ceiling - the miner-proficiency requirement, the sixths splits without and with the proficiency, the considerable time and noise with the page-50 excavation-rules seam), and the random occurrences (the chance growing with extended underground time, the 1% per day base, the 10% per 10 days long-expedition option, the cave-in near the PCs but not on top of them or within earshot, the Table 17 cross-reference, the movement-relative directions, the higher roll the farther away, the possibly-undiscovered cave-in and the decayed-stone or rotten-timber double-or-triple increase).",
    },
}
