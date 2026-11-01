-- ua380: promoted from rules/uawandprose.h (the The UA TREASURE (WANDS));
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 380,
  "prefix" = "ua380",
  "banner" = {
      "title" = "The UA TREASURE (WANDS)",
      "provenance" = "prose pins, R380: the seven pinnable new-wand types (pp. 96-97) - five fully clean (anything, fireballs, flame extinguishing, ice storms, lightning bolts) plus two whose holes (defoliation's opening sentence, metal command's dropped verb) and five garbled types (buckler, earth and stone, force, size alteration, steam and vapor) the R397 clean read filled - the gap item closed. The rods and skeleton seams ride in the regtest audit, not here.",
    },
  "consts" = { {
      "name" = "uawdAnyMaxUsages",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uawdAnyDrainDemands",
      "value" = 3,
      "comment" = "After three such demands, successful or not, the wand is totally drained and useless; it cannot be recharged.",
    }, {
      "name" = "uawdFbCasterLevel",
      "value" = 6,
      "comment" = "---- the wand of fireballs ---- Casts fireball as a magic-user of 6th level; 1 segment to activate, 1 segment to loose the fireball.",
    }, {
      "name" = "uawdFbActivateSegs",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdFbDischargeSegs",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdFbDmgDice",
      "value" = 6,
      "comment" = "Damage 6-36 (6d6), save for half; recharge by a magic-user of 8th or higher.",
    }, {
      "name" = "uawdFbDmgLo",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdFbDmgHi",
      "value" = 36,
      "comment" = "",
    }, {
      "name" = "uawdFbRechargeMuLevel",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uawdFxNormalBilletsLo",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uawdFxNormalBilletsHi",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdFxLargeNormalCharges",
      "value" = 1,
      "comment" = "Large normal fires - a gallon or more of flaming oil, demon or devil fire, flame tongue, burning hands - cost 1 charge; continual magical flames suppress 6 rounds then flare up again.",
    }, {
      "name" = "uawdFxOilGallonMin",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdFxSuppressionRounds",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdFxLargeMagicalCharges",
      "value" = 2,
      "comment" = "Large magical fires - fireball, flame strike, wall of fire - cost 2 charges.",
    }, {
      "name" = "uawdFxCreatureCharges",
      "value" = 1,
      "comment" = "One charge against a fire creature (a fire elemental) inflicts 6-36 (6d6).",
    }, {
      "name" = "uawdFxCreatureDmgDice",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdFxCreatureDmgLo",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdFxCreatureDmgHi",
      "value" = 36,
      "comment" = "",
    }, {
      "name" = "uawdIceCasterLevel",
      "value" = 7,
      "comment" = "---- the wand of ice storms ---- Ice storm as a magic-user of 7th level; hail or sleet forms; 1 segment to activate, 1 segment for the dweomer to emerge; recharge by a magic-user of 9th or higher.",
    }, {
      "name" = "uawdIceFormsCount",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uawdIceActivateSegs",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdIceEmergeSegs",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdIceRechargeMuLevel",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uawdLbCasterLevel",
      "value" = 6,
      "comment" = "---- the wand of lightning bolts ---- Lightning bolt as a magic-user of 6th level; forked or single stroke; 1 segment to activate, 1 segment to discharge; recharge by a magic-user of 8th or higher.",
    }, {
      "name" = "uawdLbDmgDice",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdLbDmgLo",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdLbDmgHi",
      "value" = 36,
      "comment" = "",
    }, {
      "name" = "uawdLbActivateSegs",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdLbDischargeSegs",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdLbRechargeMuLevel",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uawdDefChlorophyllCharges",
      "value" = 1,
      "comment" = "One charge: all chlorophyll in a 3\" radius destroyed - leaves turn autumnal and drop, grass browns.",
    }, {
      "name" = "uawdDefChlorophyllRadiusIn",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uawdDefWitherCharges",
      "value" = 2,
      "comment" = "Two charges: normal plant life in the 3\" radius withers and dies; sentient and non-normal plants suffer 1-6 (1d6) instead.",
    }, {
      "name" = "uawdDefWitherRadiusIn",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uawdDefSentientDmgLo",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdDefSentientDmgHi",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdDefConeLengthIn",
      "value" = 3,
      "comment" = "The cone option: 3\" length, 1\" diameter at the far point; sentient and non-normal plants there suffer 6-36 (6d6), save versus rods staves wands for half (3d6).",
    }, {
      "name" = "uawdDefConeFarDiamIn",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdDefConeDmgDice",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdDefConeDmgLo",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdDefConeDmgHi",
      "value" = 36,
      "comment" = "",
    }, {
      "name" = "uawdDefConeHalfDice",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uawdMcTransmuteCharges",
      "value" = 1,
      "comment" = "One charge: gold to lead or lead to gold, range 3\", 1-6 pounds (10-60 gp weight).",
    }, {
      "name" = "uawdMcTransmuteRangeIn",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uawdMcTransmuteLbsLo",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdMcTransmuteLbsHi",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdMcTransmuteGpLo",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uawdMcTransmuteGpHi",
      "value" = 60,
      "comment" = "",
    }, {
      "name" = "uawdMcHeatCharges",
      "value" = 2,
      "comment" = "Two charges: heat metal as the druid spell, range 3\", a single 3-foot diameter target area, up to 600 gp weight of metal.",
    }, {
      "name" = "uawdMcHeatRangeIn",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uawdMcHeatAreaDiamFt",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uawdMcHeatMaxGp",
      "value" = 600,
      "comment" = "",
    }, {
      "name" = "uawdMcSpellCharges",
      "value" = 3,
      "comment" = "Three charges: crystalbrittle, glassee, or glassteel as an 18th-level magic-user.",
    }, {
      "name" = "uawdMcSpellCount",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uawdMcSpellCasterLevel",
      "value" = 18,
      "comment" = "",
    }, {
      "name" = "uawdBuckLengthTenthsFt",
      "value" = 15,
      "comment" = "---- the buckler wand (the R397 clean read) ---- A shortish, thick wand about one and a half feet long; an exceptionally sharp point at one end, the trigger mechanism at the blunt other end.",
    }, {
      "name" = "uawdBuckActivateSegs",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdEarthDigCostTenths",
      "value" = 5,
      "comment" = "---- the wand of earth and stone (the R397 clean read) ---- A shortish mineral-tipped wand: dig costs a half charge, passwall 1, move earth 2.",
    }, {
      "name" = "uawdEarthPasswallCharges",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdEarthMoveEarthCharges",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uawdEarthPctWithExtras",
      "value" = 50,
      "comment" = "Half of these wands (the higher-valued) add transmute mud to rock and transmute rock to mud, 1 charge each.",
    }, {
      "name" = "uawdEarthExtraPowerCount",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uawdEarthMudToRockCharges",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdEarthRockToMudCharges",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdForceFunctionCount",
      "value" = 3,
      "comment" = "---- the wand of force (the R397 clean read) ---- A tri-function device; the third demands operator knowledge.",
    }, {
      "name" = "uawdForceShaftFeet",
      "value" = 4,
      "comment" = "First: a nearly invisible blue-white shaft of energy, 4 feet long, equal to a +5 bastard sword; 1 charge per turn.",
    }, {
      "name" = "uawdForceShaftChargesPerTurn",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdForceWallCasterLevel",
      "value" = 10,
      "comment" = "Second: a wall of force as a 10th-level magic-user; 1 charge per wall, a single usage per round.",
    }, {
      "name" = "uawdForceWallCharges",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdForceHandCostTenths",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uawdForceRechargeMuLevel",
      "value" = 16,
      "comment" = "",
    }, {
      "name" = "uawdForceTouchKinds",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uawdSizeChangePct",
      "value" = 50,
      "comment" = "---- the wand of size alteration (the R397 clean read) ---- Any single creature enlarges or diminishes by half; strength and power scale proportionally for humanoids - 9 feet matches a hill giant's Strength 19, 13 feet a fire giant's 22.",
    }, {
      "name" = "uawdSizeHillGiantFeet",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uawdSizeHillGiantStr",
      "value" = 19,
      "comment" = "",
    }, {
      "name" = "uawdSizeFireGiantFeet",
      "value" = 13,
      "comment" = "",
    }, {
      "name" = "uawdSizeFireGiantStr",
      "value" = 22,
      "comment" = "",
    }, {
      "name" = "uawdSizeRangeIn",
      "value" = 1,
      "comment" = "Range 1\"; the target and all it wears or carries are affected unless the save succeeds - a willing target forgoes the save.",
    }, {
      "name" = "uawdSizeChargesPerUse",
      "value" = 1,
      "comment" = "Each usage expends 1 charge; the cancellation is free; recharge by a magic-user of 12th or higher.",
    }, {
      "name" = "uawdSizeRechargeMuLevel",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uawdSteamCharges",
      "value" = 1,
      "comment" = "---- the wand of steam and vapor (the R397 clean read) ---- Two functions, 1 charge each.",
    }, {
      "name" = "uawdSteamActivateSegs",
      "value" = 1,
      "comment" = "STEAM: in one segment a jet of superheated steam, a cone of 1\" by 3\" by 5\"; 6-36 (6d6) the first round, 4d6 the second, 2d6 the third and last; saves apply for half.",
    }, {
      "name" = "uawdSteamConeLoIn",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdSteamConeMidIn",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uawdSteamConeHiIn",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uawdSteamRound1Dice",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdSteamRound2Dice",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uawdSteamRound3Dice",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uawdVaporCharges",
      "value" = 1,
      "comment" = "VAPOR: in one segment billows of warm steamy vapor, a fog cloud of 4\" depth, 6\" height, 8\" breadth; it persists 6 rounds, stationary unless winds move it.",
    }, {
      "name" = "uawdVaporActivateSegs",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uawdVaporDepthIn",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uawdVaporHeightIn",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdVaporBreadthIn",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uawdVaporRounds",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uawdVaporColdUserDmg",
      "value" = 1,
      "comment" = "Cold-using creatures inside suffer 1 point per round; cold-dwelling creatures take twice that.",
    }, {
      "name" = "uawdVaporColdDwellerDmg",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uawdCleanCount",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uawdFlaggedCount",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uawdGarbledCount",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uawdTotalTypes",
      "value" = 12,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uawdAnyIsWonderLike",
      "value" = true,
      "comment" = "---- the anything wand ---- Performs as an ordinary wand of wonder, with no more than 50 usages.",
    }, {
      "name" = "uawdAnyDuplicatesAnyKnownWand",
      "value" = true,
      "comment" = "Upon command it performs as any other known wand, but each kind only once - a repeated command has no effect.",
    }, {
      "name" = "uawdAnyEachKindOnce",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdAnyRepeatCommandInert",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdAnyDrainCountsFailed",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdAnyRechargeable",
      "value" = false,
      "comment" = "",
    }, {
      "name" = "uawdFbSaveForHalf",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdFxNormalFree",
      "value" = true,
      "comment" = "---- the wand of flame extinguishing ---- Normal fires: no charges - up to a bonfire or hearth fire, four to six billets burning hotly.",
    }, {
      "name" = "uawdLbForkedOrSingle",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdLbSaveForHalf",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdDefNeverWood",
      "value" = true,
      "comment" = "---- the wand of defoliation ---- The opening construction sentence reads clean in the R397 PDF pass: the wand is never constructed of wood - ivory or bone is the major component.",
    }, {
      "name" = "uawdDefIvoryOrBone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdDefOpeningHoleFlagged",
      "value" = false,
      "comment" = "",
    }, {
      "name" = "uawdDefConeSaveForHalf",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdMcPowersOperational",
      "value" = true,
      "comment" = "---- the wand of metal command ---- The transmutation sentence reads clean in the R397 PDF pass: in the hands of a dwarf or gnome its exceptional powers become operational. Appears as a wand of metal and mineral detection.",
    }, {
      "name" = "uawdMcVerbHoleFlagged",
      "value" = false,
      "comment" = "",
    }, {
      "name" = "uawdMcAppearsDetection",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdMcDwarfGnomeOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdBuckSharpTipOneEnd",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdBuckTriggerOtherEnd",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdBuckBlocksCleric",
      "value" = true,
      "comment" = "Usable by any character except a cleric; activation takes a single segment.",
    }, {
      "name" = "uawdBuckTipDaggerPlusOne",
      "value" = true,
      "comment" = "Grasped thick end, trigger pressed: the tip equals a dagger +1, the shaft a buckler +1 shield; the whole a spiked buckler +1.",
    }, {
      "name" = "uawdBuckShaftBucklerPlusOne",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdBuckWholeSpikedPlusOne",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdBuckMuMayEmploy",
      "value" = true,
      "comment" = "Magic-users may employ it, but no spells may be cast while it is in buckler form unless the caster is multi-classed with fighter and magic-user abilities.",
    }, {
      "name" = "uawdBuckMuNoSpellsInForm",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdBuckMulticlassException",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdBuckThiefNoClimbing",
      "value" = true,
      "comment" = "A thief employing it cannot climb walls or use other hand-requiring abilities while holding the device.",
    }, {
      "name" = "uawdEarthExtrasAreHigherValued",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdForceShaftPlusFive",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdForceShaftIsBastard",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdForceWallOncePerRound",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdForceHandNeedsMu",
      "value" = true,
      "comment" = "Third: a Bigby's Forceful Hand plane; the user must be a magic-user with a Bigby's Hand or Fist spell recorded in the books; half a charge per round.",
    }, {
      "name" = "uawdForceHandNeedsSpellRecorded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdForceFightersUseFirstTwo",
      "value" = true,
      "comment" = "Fighters of all types use the first and second functions; recharge by a magic-user of 16th or higher.",
    }, {
      "name" = "uawdForceTouchDisintegrates",
      "value" = true,
      "comment" = "Touching a Bigby's Hand or Fist, a Mordenkainen's Sword, or a wall of force disintegrates the manifestation and absorbs one charge.",
    }, {
      "name" = "uawdForceTouchAbsorbsCharge",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdSizeGearAffected",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdSizeWillingForgoesSave",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdSizeDispelNeedsShock",
      "value" = true,
      "comment" = "A dispel magic removal demands a system shock roll; the possessor may cancel the effect at will before it expires.",
    }, {
      "name" = "uawdSizePossessorMayCancel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdSizeCancellationFree",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdSteamSaveForHalf",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdSteamFireCreaturesImmune",
      "value" = true,
      "comment" = "Fire-dwelling or fire-using creatures are unharmed - unless dampness harms them.",
    }, {
      "name" = "uawdSteamDampnessException",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uawdVaporStationaryUnlessWinds",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['uawdAnyIsWonderLike']() != 1  or m['uawdAnyMaxUsages']() != 50  or  m['uawdAnyDuplicatesAnyKnownWand']() != 1  or  m['uawdAnyEachKindOnce']() != 1  or  m['uawdAnyRepeatCommandInert']() != 1  or m['uawdAnyDrainDemands']() != 3  or  m['uawdAnyDrainCountsFailed']() != 1  or m['uawdAnyRechargeable']()",
      "note" = "---- the anything wand ----",
    }, {
      "expr" = "m['uawdFbCasterLevel']() != 6  or m['uawdFbActivateSegs']() != 1  or m['uawdFbDischargeSegs']() != 1  or m['uawdFbDmgDice']() != 6  or m['uawdFbDmgLo']() != 6  or m['uawdFbDmgHi']() != 36  or  m['uawdFbSaveForHalf']() != 1  or m['uawdFbRechargeMuLevel']() != 8",
      "note" = "---- the wand of fireballs ----",
    }, {
      "expr" = "m['uawdFxNormalFree']() != 1  or m['uawdFxNormalBilletsLo']() != 4  or m['uawdFxNormalBilletsHi']() != 6  or m['uawdFxLargeNormalCharges']() != 1  or m['uawdFxOilGallonMin']() != 1  or m['uawdFxSuppressionRounds']() != 6  or m['uawdFxLargeMagicalCharges']() != 2  or m['uawdFxCreatureCharges']() != 1  or m['uawdFxCreatureDmgDice']() != 6  or m['uawdFxCreatureDmgLo']() != 6  or m['uawdFxCreatureDmgHi']() != 36  or m['uawdFxCreatureDmgLo']() !=m['uawdFbDmgLo']()  or m['uawdFxCreatureDmgHi']() !=m['uawdFbDmgHi']()",
      "note" = "---- the wand of flame extinguishing ----",
    }, {
      "expr" = "m['uawdIceCasterLevel']() != 7  or m['uawdIceFormsCount']() != 2  or m['uawdIceActivateSegs']() != 1  or m['uawdIceEmergeSegs']() != 1  or m['uawdIceRechargeMuLevel']() != 9",
      "note" = "---- the wand of ice storms ----",
    }, {
      "expr" = "m['uawdLbCasterLevel']() != 6  or  m['uawdLbForkedOrSingle']() != 1  or m['uawdLbDmgDice']() != 6  or m['uawdLbDmgLo']() != 6  or m['uawdLbDmgHi']() != 36  or  m['uawdLbSaveForHalf']() != 1  or m['uawdLbActivateSegs']() != 1  or m['uawdLbDischargeSegs']() != 1  or m['uawdLbRechargeMuLevel']() != 8  or m['uawdLbCasterLevel']() !=m['uawdFbCasterLevel']()  or m['uawdLbDmgLo']() !=m['uawdFbDmgLo']()  or m['uawdLbDmgHi']() !=m['uawdFbDmgHi']()  or m['uawdLbRechargeMuLevel']() !=m['uawdFbRechargeMuLevel']()",
      "note" = "---- the wand of lightning bolts ----",
    }, {
      "expr" = "m['uawdDefOpeningHoleFlagged']()  or m['uawdDefChlorophyllCharges']() != 1  or m['uawdDefChlorophyllRadiusIn']() != 3  or m['uawdDefWitherCharges']() != 2  or m['uawdDefWitherRadiusIn']() != 3  or m['uawdDefSentientDmgLo']() != 1  or m['uawdDefSentientDmgHi']() != 6  or m['uawdDefConeLengthIn']() != 3  or m['uawdDefConeFarDiamIn']() != 1  or m['uawdDefConeDmgDice']() != 6  or m['uawdDefConeDmgLo']() != 6  or m['uawdDefConeDmgHi']() != 36  or  m['uawdDefConeSaveForHalf']() != 1  or m['uawdDefConeHalfDice']() != 3  or 2 *m['uawdDefConeHalfDice']() !=m['uawdDefConeDmgDice']()",
      "note" = "---- the wand of defoliation ----",
    }, {
      "expr" = "m['uawdMcVerbHoleFlagged']()  or  m['uawdMcAppearsDetection']() != 1  or  m['uawdMcDwarfGnomeOnly']() != 1  or m['uawdMcTransmuteCharges']() != 1  or m['uawdMcTransmuteRangeIn']() != 3  or m['uawdMcTransmuteLbsLo']() != 1  or m['uawdMcTransmuteLbsHi']() != 6  or m['uawdMcTransmuteGpLo']() != 10  or m['uawdMcTransmuteGpHi']() != 60  or m['uawdMcTransmuteGpLo']() != 10 *m['uawdMcTransmuteLbsLo']()  or m['uawdMcTransmuteGpHi']() != 10 *m['uawdMcTransmuteLbsHi']()  or m['uawdMcHeatCharges']() != 2  or m['uawdMcHeatRangeIn']() != 3  or m['uawdMcHeatAreaDiamFt']() != 3  or m['uawdMcHeatMaxGp']() != 600  or m['uawdMcSpellCharges']() != 3  or m['uawdMcSpellCount']() != 3  or m['uawdMcSpellCasterLevel']() != 18",
      "note" = "---- the wand of metal command ----",
    }, {
      "expr" = "m['uawdCleanCount']() != 12  or m['uawdFlaggedCount']() != 0  or m['uawdGarbledCount']() != 0  or m['uawdTotalTypes']() != 12  or m['uawdCleanCount']() +m['uawdFlaggedCount']() +m['uawdGarbledCount']() !=m['uawdTotalTypes']()",
      "note" = "---- the extract ledger ----",
    }, {
      "expr" = "m['uaroCleanCount']() != 11  or m['uaroGarbledCount']() != 0",
      "note" = "---- the R379 rods seam ----",
    }, {
      "expr" = "strcmp(m['uadsCategoryName'](3), \"Rods, Staves & Wands\") != 0  or  m['uadsIsTheRevisedTable']() != 1  or  m['uadsRodSecondTableIsIID2']() != 1  or m['uadsRowBodiesGarble']()",
      "note" = "---- the R375 skeleton seam ----",
    } },
  "audit" = {
      "label" = "R380: the UA new wands prose pin audit",
      "comment" = "The seven pinnable wand types (pp. 96-97): five fully clean (anything, fireballs, flame extinguishing, ice storms, lightning bolts) plus two mechanics-clean with flagged holes (defoliation, metal command), their holes and the five garbled types filled by the R397 clean read. The R379 seam cross-checks the rods ledger, the R375 seam the wand band; the census 306 -> 307.",
    },
}
