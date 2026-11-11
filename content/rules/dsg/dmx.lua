-- dmx: promoted from tools/spec_r505.json (the The DSG MOVEMENT CHAPTER PART II, R505: the printed pp. 19-22 (pdf 20-23) second half of the movement chapter - the bridge rules (the maintained no-check rule, the suspension/wooden/stone permanent bridges, the rope and log impromptu bridges with the move-log ladder), the expanded falling rules (the cumulative 1d6-per-10-feet dice, the 20d6 and 10d6 caps, the 50-foot stop window, the landing ladder, the slope slides), spelunking with TABLE 7 MINIMUM PASSAGEWAY SIZES, the excavation with TABLE 8 ARMOR EFFECTS ON CHARACTER WIDTH, the fatigue and exhaustion ladders, the darkness movement with TABLE 9 COURSE CHANGES IN DARKNESS, and the slippery horizontal surfaces with the crampon rules. The movement chapter parent closes this round: the whole chapter is pinned.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 505,
  "prefix" = "dmx",
  "banner" = {
      "title" = "The DSG MOVEMENT CHAPTER PART II, R505: the printed pp. 19-22 (pdf 20-23) second half of the movement chapter - the bridge rules (the maintained no-check rule, the suspension/wooden/stone permanent bridges, the rope and log impromptu bridges with the move-log ladder), the expanded falling rules (the cumulative 1d6-per-10-feet dice, the 20d6 and 10d6 caps, the 50-foot stop window, the landing ladder, the slope slides), spelunking with TABLE 7 MINIMUM PASSAGEWAY SIZES, the excavation with TABLE 8 ARMOR EFFECTS ON CHARACTER WIDTH, the fatigue and exhaustion ladders, the darkness movement with TABLE 9 COURSE CHANGES IN DARKNESS, and the slippery horizontal surfaces with the crampon rules. The movement chapter parent closes this round: the whole chapter is pinned.",
      "provenance" = "the DSG scan (the user own copy), printed pp. 19-22 = pdf 20-23, pulled per-page on the r504-extraction branch (p020-p023) with the tsv confidence tables and the 300-dpi page images under extract/r504/ on main; the Table 7 human/dwarf/half-orc rows and the Table 8 splint/banded/plate/field cells were image-only reads, each cross-checked against the tsv fragments (the residual cautions live in the r504 extraction grids file).",
      "sentinel" = "THE SETTLE: census 429 -> 430; the gap report 27/128 -> 38 closed / 117 open (the seven movement-chapter boxes from bridges through slippery surfaces, the movement parent, and the manifest tables 7-9; the movement chapter is now fully closed). CROSS-BOOK SEAM: the fall dice ladder, the 20d6 cap and the 50-foot stop window verified const-for-const against rules/wsg/wsgfall.h and rules/wsg/wsgstop.h (agreement at every compared value); the slippery rules against rules/wsg/wsgslip.h and the waterfall against the WSG water pins (no divergence; the 10d6 waterfall cap is DSG-only, the WSG has no cap pin); the fatigue against rules/wsg/wsgfatig.h (const-for-const agreement on the 4/2 cycle, the 6-then-5-then-shrinking check interval, the -2 effects, the 12-turn clear and the 6-turn recoveries - ONE FRAMING DIVERGENCE: the WSG exhausted penalty is an additional -2, the DSG a -4 instead of the fatigue -2; both total -4 and the DSG pins as printed). NOTHING auto-credited.",
    },
  "consts" = { {
      "name" = "dmxSuspensionGiveWayPct",
      "value" = 25,
      "comment" = "an old suspension bridge stands a 25 percent chance per character crossing it of giving way at some crucial point.",
    }, {
      "name" = "dmxSuspensionCatchBridgeModPct",
      "value" = -25,
      "comment" = "a character who fails the first suspension check and tries to catch a piece of the bridge with only one hand free checks at -25 percent; he can drop what he is holding to free both hands.",
    }, {
      "name" = "dmxAnchorSabotageDie",
      "value" = 8,
      "comment" = "sabotaging an anchor point of a suspension bridge takes 1d8 rounds.",
    }, {
      "name" = "dmxSawRopeRounds",
      "value" = 1,
      "comment" = "sawing through a rope support of a suspension bridge can be done in one round.",
    }, {
      "name" = "dmxWoodRotPctPerYear",
      "value" = 5,
      "comment" = "a wooden bridge not inspected and repaired within the past year stands a 5 percent chance per year of sustaining rot.",
    }, {
      "name" = "dmxWoodBeamDie",
      "value" = 20,
      "comment" = "the actual supporting beams of a wooden bridge last 1d20+20 years before beginning to rot; rot first affects the planks and railings.",
    }, {
      "name" = "dmxWoodBeamBaseYears",
      "value" = 20,
      "comment" = "the beam-rot base: 1d20 plus 20 years.",
    }, {
      "name" = "dmxRottenStepPct",
      "value" = 50,
      "comment" = "each character crossing a rotted wooden bridge stands a 50 percent chance of stepping onto a rotten portion.",
    }, {
      "name" = "dmxArchCenterCollapseDie",
      "value" = 4,
      "comment" = "if the center of a stone bridge arch is destroyed (transmute rock to mud), the entire bridge collapses in 1d4 rounds.",
    }, {
      "name" = "dmxRopeBridgeModPct",
      "value" = 50,
      "comment" = "a character crossing a rope bridge (one rope for the feet, one for the hands) makes a Climbing Check with a +50 percent modifier.",
    }, {
      "name" = "dmxRopeSabotageClingModPct",
      "value" = -20,
      "comment" = "a character clinging to the sabotaged rope with his hands checks at -20 percent, or may elect to hold on and swing down with it.",
    }, {
      "name" = "dmxLogDiaHeightDiv",
      "value" = 4,
      "comment" = "a log bridge must be 1/4 or less of the character height in diameter to require a check; wider log bridges are crossed automatically.",
    }, {
      "name" = "dmxLogBridgeModPct",
      "value" = 40,
      "comment" = "crossing a log bridge requires a Climbing Check with a +40 percent modifier.",
    }, {
      "name" = "dmxLogSlopedModPct",
      "value" = 20,
      "comment" = "if the log bridge slopes upward or downward, the modifier drops to +20 percent.",
    }, {
      "name" = "dmxLogCrawlModPct",
      "value" = 80,
      "comment" = "if the character crawls or has both hands free, the log bridge modifier is +80 percent.",
    }, {
      "name" = "dmxHumanLogFt",
      "value" = 10,
      "comment" = "the move-log ladder floor: a normal human can move a log of 10 feet or shorter length (a 1 1/2-foot diameter log).",
    }, {
      "name" = "dmxStr17LogFt",
      "value" = 20,
      "comment" = "a human with 17 or 18 Strength, or a creature like an ogre, can move a 20-foot log.",
    }, {
      "name" = "dmxHillGiantLogFt",
      "value" = 30,
      "comment" = "a hill giant, or a fairly young dragon, can move a 30-foot log.",
    }, {
      "name" = "dmxLargeGiantLogLoFt",
      "value" = 40,
      "comment" = "a large giant or dragon can move a 40-foot log.",
    }, {
      "name" = "dmxLargeGiantLogHiFt",
      "value" = 50,
      "comment" = "a large giant or dragon can move a log of up to 50 feet in length.",
    }, {
      "name" = "dmxFallIncrementPer10Ft",
      "value" = 1,
      "comment" = "falling damage is 1d6 for the first 10 feet, 2d6 for the second, 3d6 for the third, and so on - each 10-foot band adds one more die, cumulative.",
    }, {
      "name" = "dmxThirtyFtFallDice",
      "value" = 6,
      "comment" = "the printed example: a 30-foot fall inflicts a total of 6d6 (1+2+3).",
    }, {
      "name" = "dmxFallCapDice",
      "value" = 20,
      "comment" = "the maximum damage any fall can inflict is 20d6, regardless of the height.",
    }, {
      "name" = "dmxWaterfallCapDice",
      "value" = 10,
      "comment" = "the maximum damage a character can sustain by falling over a waterfall is 10d6.",
    }, {
      "name" = "dmxFallFtPerRound",
      "value" = 1000,
      "comment" = "for purposes of game balance, a character falls 1,000 feet in one round unless the fall is interrupted.",
    }, {
      "name" = "dmxStopWindowFt",
      "value" = 50,
      "comment" = "an attempt to slow a fall by catching onto a wall or climbing surface can only be made in the first 50 feet - past that the momentum is too great.",
    }, {
      "name" = "dmxStopNonslipDiv",
      "value" = 2,
      "comment" = "on a nonslippery climbing surface the fall is stopped on a d100 roll less than or equal to 1/2 the Climbing Rating.",
    }, {
      "name" = "dmxStopSlightDiv",
      "value" = 4,
      "comment" = "a slightly slippery surface can be caught on 1/4 the Climbing Rating - half the nonslippery chance.",
    }, {
      "name" = "dmxRoughLandingMult",
      "value" = 2,
      "comment" = "a landing on broken rocks, debris, or a slanted surface that ricochets the character inflicts double the normal fall damage.",
    }, {
      "name" = "dmxSpikeDamageDie",
      "value" = 6,
      "comment" = "each spike or weapon-like feature of a landing area inflicts an extra d6 of damage beyond the fall.",
    }, {
      "name" = "dmxSparseSpikeMinDice",
      "value" = 1,
      "comment" = "a 1d6 grouping of spikes means the character impales himself on 1 to 6 of them.",
    }, {
      "name" = "dmxSparseSpikeMaxDice",
      "value" = 6,
      "comment" = "the sparse spike grouping impales on up to 6 spikes.",
    }, {
      "name" = "dmxDenseSpikeMinDice",
      "value" = 3,
      "comment" = "a 3d6 grouping of densely packed spikes impales on 3 to 18 spikes.",
    }, {
      "name" = "dmxDenseSpikeMaxDice",
      "value" = 18,
      "comment" = "the dense spike grouping impales on up to 18 spikes, 3-18 d6 of damage in addition to the fall.",
    }, {
      "name" = "dmxSoftLandingDiv",
      "value" = 2,
      "comment" = "a soft landing on sand, mud, soft loam, pine branches or flesh inflicts only half the normal fall damage.",
    }, {
      "name" = "dmxVerySoftFailDiv",
      "value" = 2,
      "comment" = "a failed very-soft save still halves the fall damage.",
    }, {
      "name" = "dmxWaterLandingDiePer100Ft",
      "value" = 1,
      "comment" = "a successful Dexterity Check into water costs 1d6 of damage for every 100 feet of the fall.",
    }, {
      "name" = "dmxExample250FtWaterDice",
      "value" = 3,
      "comment" = "the printed example: a character falling 250 feet into water with a successful Dexterity Check suffers only 3d6.",
    }, {
      "name" = "dmxSlideFreeFt",
      "value" = 20,
      "comment" = "a character sliding down a sloping surface suffers no damage in the first 20 feet of the slide.",
    }, {
      "name" = "dmxSlideDiePer10Ft",
      "value" = 1,
      "comment" = "past the first 20 feet, a slide inflicts 1d6 of damage for each 10 feet of the slide (the abrasions), unless the slope is very slippery.",
    }, {
      "name" = "dmxSlideLandingDiePer40Ft",
      "value" = 1,
      "comment" = "the landing after a slide inflicts 1d6 for each 40 feet of the slide.",
    }, {
      "name" = "dmxSlipperySlideLandingMult",
      "value" = 2,
      "comment" = "a slide down a slippery slope takes double the normal damage upon landing.",
    }, {
      "name" = "dmxUprightMinCeilNum",
      "value" = 2,
      "comment" = "if the tunnel ceiling is lower than the character height but at least 2/3 of it, he can walk upright.",
    }, {
      "name" = "dmxUprightMinCeilDen",
      "value" = 3,
      "comment" = "the upright-walk ceiling floor is 2/3 the character height.",
    }, {
      "name" = "dmxUprightRateNum",
      "value" = 2,
      "comment" = "walking upright under a low ceiling moves at 2/3 of the normal movement rate, with no adverse combat effects.",
    }, {
      "name" = "dmxUprightRateDen",
      "value" = 3,
      "comment" = "the upright low-ceiling rate denominator: 2/3 normal.",
    }, {
      "name" = "dmxHandsKneesRateDiv",
      "value" = 2,
      "comment" = "a character traveling on hands and knees (a tunnel under 2/3 his height) moves at 1/2 his normal movement rate.",
    }, {
      "name" = "dmxHandsKneesAtkMod",
      "value" = -5,
      "comment" = "a character fighting on hands and knees suffers a -5 penalty to all his attack rolls.",
    }, {
      "name" = "dmxProneCeilDiv",
      "value" = 4,
      "comment" = "in a tunnel whose diameter is 1/4 or less of his height, the character must slither along prone.",
    }, {
      "name" = "dmxProneRateDiv",
      "value" = 4,
      "comment" = "a prone character is limited to 1/4 of his normal rate of movement.",
    }, {
      "name" = "dmxProneAtkMod",
      "value" = -8,
      "comment" = "a prone character suffers a -8 modifier to all his attack rolls.",
    }, {
      "name" = "dmxRubbleClearFtDie",
      "value" = 4,
      "comment" = "in one turn of excavation a character can clear 1d4 feet of loosely packed rubble passageway to the Table 7 minimum width.",
    }, {
      "name" = "dmxRubblePartialDieMult",
      "value" = 2,
      "comment" = "if the passage is only partially blocked, the distance cleared in a turn is 2d4 feet.",
    }, {
      "name" = "dmxSolidRateDiv",
      "value" = 4,
      "comment" = "if other metal tools (shovels, swords) are substituted for pickaxes, the excavation rate is only 1/4 the Table 27 rate.",
    }, {
      "name" = "dmxPassagewayRowCount",
      "value" = 6,
      "comment" = "Table 7 has six race rows: human, half-orc, dwarf, gnome, elf and halfling.",
    }, {
      "name" = "dmxArmorWidthRowCount",
      "value" = 11,
      "comment" = "Table 8 has eleven armor rows: leather, padded, studded leather, scale, ring, chain, splint, banded, plate, field plate and full plate.",
    }, {
      "name" = "dmxCourseChangeRowCount",
      "value" = 12,
      "comment" = "Table 9 has twelve d12 rows, 1 through 12.",
    }, {
      "name" = "dmxT9RolledDirDie",
      "value" = 6,
      "comment" = "the 135-degree row resolves its direction on 1d6.",
    }, {
      "name" = "dmxT9RolledRightLo",
      "value" = 1,
      "comment" = "on the 135-degree row, a 1-3 rolls the course to the right.",
    }, {
      "name" = "dmxT9RolledRightHi",
      "value" = 3,
      "comment" = "the right-direction ceiling on the rolled row: 1-3 of the 1d6.",
    }, {
      "name" = "dmxFatigueWorkTurns",
      "value" = 4,
      "comment" = "a character can avoid fatigue by resting for two turns after each four turns of unusually strenuous activity - keep the pattern and he is never susceptible.",
    }, {
      "name" = "dmxFatigueRestTurns",
      "value" = 2,
      "comment" = "the paired rest: two turns of rest per four turns of work.",
    }, {
      "name" = "dmxFatigueFirstCheckTurns",
      "value" = 6,
      "comment" = "six turns of unusually strenuous activity without the two turns of rest force a Constitution Check; failure fatigues the character.",
    }, {
      "name" = "dmxFatigueSecondCheckAfterTurns",
      "value" = 5,
      "comment" = "after a successful first check, five more turns of strenuous activity force another Constitution Check.",
    }, {
      "name" = "dmxFatigueIntervalStepTurns",
      "value" = 1,
      "comment" = "each subsequent successful check shortens the interval by one turn - five, then four, and so on until the character must check every turn.",
    }, {
      "name" = "dmxFatigueRecoveryTurns",
      "value" = 6,
      "comment" = "a character whose checks have all succeeded fully recovers by spending an hour (six turns) resting.",
    }, {
      "name" = "dmxFatigueAttrMod",
      "value" = -2,
      "comment" = "a fatigued character has all his attribute scores lowered by 2, with the attendant temporary losses of hit points, spells and combat bonuses.",
    }, {
      "name" = "dmxFatigueCombatMod",
      "value" = -2,
      "comment" = "a fatigued character applies a -2 penalty to all his attack rolls, damage rolls and saves.",
    }, {
      "name" = "dmxFatigueEffectTurns",
      "value" = 12,
      "comment" = "the fatigue effects last until the character rests for two hours (12 turns).",
    }, {
      "name" = "dmxExhaustedMod",
      "value" = -4,
      "comment" = "an exhausted character forced to act suffers a -4 penalty to all the attribute and combat scores affected by fatigue.",
    }, {
      "name" = "dmxExhaustRecoveryTurns",
      "value" = 6,
      "comment" = "after one hour of uninterrupted rest an exhausted character rolls a Constitution Check (revised score); success makes him merely fatigued, failure forces another full hour.",
    }, {
      "name" = "dmxDarkSafeRateDiv",
      "value" = 3,
      "comment" = "characters in the dark can safely move at 1/3 their normal movement rates, probing the ground ahead.",
    }, {
      "name" = "dmxDarkCourseDie",
      "value" = 12,
      "comment" = "the DM makes a secret roll on 1d12 for the unknown course changes that occur walking in complete darkness.",
    }, {
      "name" = "dmxDarkCourseRollEveryTurns",
      "value" = 3,
      "comment" = "the course roll is made after every three turns spent walking in darkness.",
    }, {
      "name" = "dmxDarkCourseShortModPerTurn",
      "value" = -1,
      "comment" = "if the uncharted movement lasted less than three turns, the roll is still made, with a -1 modifier to the d12 for each turn short.",
    }, {
      "name" = "dmxDarkRoughFallDamage",
      "value" = 1,
      "comment" = "each failed Dexterity Check on a rough or uneven floor means the character sustains 1 point of damage in a rough fall.",
    }, {
      "name" = "dmxDarkRoughSafeRateDiv",
      "value" = 6,
      "comment" = "characters traveling rough floors in darkness prevent the accidents by slowing to 1/6 their normal rate.",
    }, {
      "name" = "dmxSlipRiseRounds",
      "value" = 1,
      "comment" = "a character who falls on a slippery surface spends a full round climbing to his feet.",
    }, {
      "name" = "dmxSlipSlowdownRounds",
      "value" = 1,
      "comment" = "a character can spend a round slowing down from normal speed to 1/2 speed, and then turn without a check.",
    }, {
      "name" = "dmxSlipFailAcPenalty",
      "value" = 4,
      "comment" = "a character who fails the melee Dexterity Check on a slippery surface suffers a +4 penalty to his Armor Class for the round.",
    }, {
      "name" = "dmxSlipFailRiseRounds",
      "value" = 1,
      "comment" = "after a failed melee slip the character spends the next round getting to his feet, the AC penalty remaining in effect, and cannot attack that round.",
    }, {
      "name" = "dmxSlipGroundAtkMod",
      "value" = -4,
      "comment" = "a character who elects to fight from the ground keeps the +4 AC penalty and incurs a -4 penalty on all his attack rolls.",
    }, {
      "name" = "dmxCramponAttachTurns",
      "value" = 1,
      "comment" = "a pair of crampons requires one turn to attach.",
    }, {
      "name" = "dmxCramponNoiseMult",
      "value" = 2,
      "comment" = "a character walking on a nonslippery surface in crampons makes twice as much noise as he otherwise would.",
    }, {
      "name" = "dmxCramponWearDie",
      "value" = 6,
      "comment" = "walking on nonslippery surfaces wears the crampons out in 1d6 miles of such abuse.",
    } },
  "bools" = { {
      "name" = "dmxMaintainedBridgeNoChecks",
      "value" = true,
      "comment" = "a bridge maintained periodically and not sabotaged is crossed without any checks, regardless of type.",
    }, {
      "name" = "dmxSuspensionGiveWayPerChar",
      "value" = true,
      "comment" = "the suspension give-way chance is rolled per character crossing, not per crossing.",
    }, {
      "name" = "dmxAnchorSabotageThiefDetectOnly",
      "value" = true,
      "comment" = "anchor sabotage can only be detected by a thief find traps roll.",
    }, {
      "name" = "dmxSawRopeVisible",
      "value" = true,
      "comment" = "a sawed rope support is readily visible to any character who examines the bridge.",
    }, {
      "name" = "dmxRottenStepSuspensionChecks",
      "value" = true,
      "comment" = "a character who steps onto a rotten portion makes Climbing Checks to determine whether he falls, as described for suspension bridges.",
    }, {
      "name" = "dmxStoneBridgeSabotageImmune",
      "value" = true,
      "comment" = "stone bridges are the most solid, virtually impervious to the effects of sabotage and age.",
    }, {
      "name" = "dmxStoneWeightCollapseRare",
      "value" = true,
      "comment" = "even a weakened stone bridge will rarely collapse because of the added weight of a character.",
    }, {
      "name" = "dmxFoundationCollapseInstant",
      "value" = true,
      "comment" = "if a stone bridge foundation is destroyed, the bridge collapses instantly.",
    }, {
      "name" = "dmxFoundationCollapseToNext",
      "value" = true,
      "comment" = "a foundation collapse runs in both directions from the ruined foundation until it reaches the next foundation or the end of the bridge.",
    }, {
      "name" = "dmxRopeBridgeArmorRaceApply",
      "value" = true,
      "comment" = "armor and race modifiers affect the rope bridge roll normally.",
    }, {
      "name" = "dmxRopeSabotageUnmodifiedCheck",
      "value" = true,
      "comment" = "a character on a rope bridge when one rope is chopped through makes an unmodified Climbing Check or falls.",
    }, {
      "name" = "dmxLogWiderAutoCross",
      "value" = true,
      "comment" = "a log bridge wider than 1/4 the character height is crossed without a check.",
    }, {
      "name" = "dmxStopSlipperyImpossible",
      "value" = true,
      "comment" = "a slippery climbing surface cannot be used to stop a fall.",
    }, {
      "name" = "dmxVerySoftSaveVsParalysis",
      "value" = true,
      "comment" = "a character making a very soft landing (a prepared cushion of feathers or straw) makes a saving throw vs. paralyzation.",
    }, {
      "name" = "dmxWaterLandingRoundUp",
      "value" = true,
      "comment" = "the water-landing damage dice are rounded up: a 250-foot fall costs 3d6.",
    }, {
      "name" = "dmxNoCatchAndWaterSameRound",
      "value" = true,
      "comment" = "a character cannot attempt to stop a fall by catching a climbing surface and make a Dexterity Check to land in water during the same round.",
    }, {
      "name" = "dmxWaterCheckSecondRoundAllowed",
      "value" = true,
      "comment" = "if the fall lasts more than one round, the character can attempt the Dexterity Check on the second round.",
    }, {
      "name" = "dmxSlipperySlideNoDamage",
      "value" = true,
      "comment" = "on a smooth and relatively slippery slope the character sustains no damage while sliding.",
    }, {
      "name" = "dmxHandsKneesLoseDexShieldAc",
      "value" = true,
      "comment" = "a hands-and-knees character also loses all Dexterity and shield bonuses to AC.",
    }, {
      "name" = "dmxHandsKneesLongWeaponsUnusable",
      "value" = true,
      "comment" = "weapons such as longbows, broadswords and battleaxes cannot be employed in these close quarters (the Space Required listing on the Weapons Tables is the guide).",
    }, {
      "name" = "dmxProneNoShieldDexAc",
      "value" = true,
      "comment" = "a prone character can gain no Armor Class benefits from a shield or a Dexterity bonus.",
    }, {
      "name" = "dmxProneWeaponLimitsWorse",
      "value" = true,
      "comment" = "the prone space limits his choice of weapons even further than the hands-and-knees position.",
    }, {
      "name" = "dmxDragPackTighter",
      "value" = true,
      "comment" = "the passageway sizes assume no bulky armor or backpack - a character usually drags his pack behind him, negotiating tighter passages.",
    }, {
      "name" = "dmxSolidPickaxesAssumed",
      "value" = true,
      "comment" = "the solid-barrier excavation rates assume the characters use pickaxes.",
    }, {
      "name" = "dmxFatigueHenchmenStay",
      "value" = true,
      "comment" = "henchmen will not desert because of the temporary Charisma lowering.",
    }, {
      "name" = "dmxFatigueContinuingCheckEveryTurn",
      "value" = true,
      "comment" = "a fatigued character who continues the strenuous activity must make a Constitution Check every turn.",
    }, {
      "name" = "dmxFatigueCheckVsRevisedCon",
      "value" = true,
      "comment" = "the fatigued every-turn checks roll against his revised Constitution score.",
    }, {
      "name" = "dmxFatigueMarchNotStrenuous",
      "value" = true,
      "comment" = "merely marching along, even over difficult terrain, is not an unusually strenuous activity; fighting, running, continuous climbing, chopping wood, rough or swift swimming, and moving while encumbered are.",
    }, {
      "name" = "dmxExhaustedNoVoluntaryLabor",
      "value" = true,
      "comment" = "an exhausted character cannot perform any voluntary physical labor and must rest until he recovers.",
    }, {
      "name" = "dmxExhaustedInsteadOfFatigue",
      "value" = true,
      "comment" = "the exhausted -4 is instead of, not in addition to, the fatigue penalties (a WSG divergence - the WSG frames exhaustion as an additional -2; both books total -4).",
    }, {
      "name" = "dmxExhaustCheckToFatigued",
      "value" = true,
      "comment" = "a successful exhaustion-recovery check leaves the character fatigued, not fresh.",
    }, {
      "name" = "dmxDarkObstacleDexCheck",
      "value" = true,
      "comment" = "a character moving at normal rates in darkness who encounters an obstacle must make a Dexterity Check or his momentum carries him into it.",
    }, {
      "name" = "dmxDarkNeedDirectionMeans",
      "value" = true,
      "comment" = "without some means of determining direction, such as trailing a hand along a corridor wall, it is virtually impossible to walk a straight line in complete darkness.",
    }, {
      "name" = "dmxSlipStraightLineSafe",
      "value" = true,
      "comment" = "characters cautiously treading a slippery surface can travel at their normal movement rate as long as they move in a straight line.",
    }, {
      "name" = "dmxSlipTurnStopRunDexCheck",
      "value" = true,
      "comment" = "if the character attempts to turn, stop suddenly, or break into a run on a slippery surface, he must make a Dexterity Check or fall down.",
    }, {
      "name" = "dmxSlipFallNoDamage",
      "value" = true,
      "comment" = "a character who falls down on a slippery surface suffers no damage.",
    }, {
      "name" = "dmxSlipHalfRateTurnFree",
      "value" = true,
      "comment" = "a character moving at 1/2 his normal movement rate can turn without making a Dexterity Check.",
    }, {
      "name" = "dmxSlipMeleeCheckEveryAttack",
      "value" = true,
      "comment" = "characters engaging in melee combat on a slippery surface must make a Dexterity Check before every attack; a failed check means no attack and a fall.",
    }, {
      "name" = "dmxCramponsNeverFall",
      "value" = true,
      "comment" = "characters wearing crampons always retain their footing on slick surfaces - no Dexterity Checks are needed while turning or fighting.",
    }, {
      "name" = "dmxCramponRemoveHalfTurn",
      "value" = true,
      "comment" = "crampons take half a turn to remove.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 7: MINIMUM PASSAGEWAY SIZES",
      "tag" = "7",
      "count" = "dmxPassagewayRowCount",
      "col_default" = 0,
      "cols" = { "dmxT7WidthIn", "dmxT7HeightIn" },
      "col_comments" = { "The minimum tunnel width in inches by race row: human 24, half-orc 24, dwarf 24, gnome 18, elf 18, halfling 12 - the printed 2, 2, 2, 1 1/2, 1 1/2 and 1 feet.", "The minimum tunnel crawl height in inches by race row: human 12, half-orc 16, dwarf 12, gnome 9, elf 9, halfling 8 - the printed 1, 1 1/3, 1, 3/4, 3/4 and 2/3 feet." },
      "audit_comment" = "the Table 7 grid: the six race rows x the tunnel-width and crawl-height columns, pinned in inches (the feet-and-fraction print converted at 12 inches the foot); the human, dwarf and half-orc rows were image-only reads cross-checked against the tsv fragments.",
      "data" = { { 24, 12 }, { 24, 16 }, { 24, 12 }, { 18, 9 }, { 18, 9 }, { 12, 8 } },
    }, {
      "name" = "Table 8: ARMOR EFFECTS ON CHARACTER WIDTH",
      "tag" = "8",
      "count" = "dmxArmorWidthRowCount",
      "col_default" = 0,
      "cols" = { "dmxT8WidthAddIn" },
      "col_comments" = { "The increase in the character width in inches by armor row: leather 0, padded 2, studded leather 2, scale 3, ring 2, chain 3, splint 3, banded 6, plate 8, field plate 10, full plate 12 - the printed none, 1/6, 1/6, 1/4, 1/6, 1/4, 1/4, 1/2, 2/3, 5/6 and 1 foot." },
      "audit_comment" = "the Table 8 grid: the eleven armor rows x the width-increase column, pinned in inches; the splint, banded, plate and field-plate cells were image-only reads cross-checked against the tsv fragments.",
      "data" = { { 0 }, { 2 }, { 2 }, { 3 }, { 2 }, { 3 }, { 3 }, { 6 }, { 8 }, { 10 }, { 12 } },
    }, {
      "name" = "Table 9: COURSE CHANGES IN DARKNESS",
      "tag" = "9",
      "count" = "dmxCourseChangeRowCount",
      "col_default" = 0,
      "cols" = { "dmxT9Deg", "dmxT9Dir" },
      "col_comments" = { "The course change in degrees by d12 row: rows 1-3 straight ahead (0), rows 4-5 forty-five right, rows 6-7 forty-five left, row 8 sixty right, row 9 sixty left, row 10 ninety right, row 11 ninety left, row 12 one hundred thirty-five.", "The direction by d12 row: 0 straight, 1 right, 2 left, and 3 the 135-degree row whose direction rolls on 1d6 (1-3 right, 4-6 left)." },
      "audit_comment" = "the Table 9 grid: the twelve d12 rows x the degrees and direction columns; rows 1-7 were image-only reads cross-checked against the tsv fragments.",
      "data" = { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 45, 1 }, { 45, 1 }, { 45, 2 }, { 45, 2 }, { 60, 1 }, { 60, 2 }, { 90, 1 }, { 90, 2 }, { 135, 3 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dmxFallIncrementPer10Ft']() != 1 or m['dmxThirtyFtFallDice']() != 6 or m['dmxFallCapDice']() != 20 or m['dmxWaterfallCapDice']() != 10 or m['dmxFallFtPerRound']() != 1000",
      "note" = "the printed fall ladder: a 30-foot fall totals 6d6 (1+2+3 dice), the hard cap 20d6, the waterfall cap 10d6, the 1,000-feet-per-round fall rate.",
    }, {
      "expr" = "m['dmxStopWindowFt']() != 50 or m['dmxStopNonslipDiv']() != 2 or m['dmxStopSlightDiv']() != 4 or m['dmxStopSlightDiv']() != 2 * m['dmxStopNonslipDiv']()",
      "note" = "the stop window is the first 50 feet; the slightly-slippery catch at 1/4 is exactly half the nonslippery 1/2 chance.",
    }, {
      "expr" = "m['dmxSuspensionGiveWayPct']() != 25 or m['dmxSuspensionCatchBridgeModPct']() != -25",
      "note" = "the suspension bridge: 25 percent per character of giving way, the one-hand catch at -25.",
    }, {
      "expr" = "m['dmxWoodRotPctPerYear']() != 5 or m['dmxWoodBeamDie']() != 20 or m['dmxWoodBeamBaseYears']() != 20 or m['dmxRottenStepPct']() != 50",
      "note" = "the wooden bridge: 5 percent rot per uninspected year, the beams 1d20+20 years, the rotten step 50 percent.",
    }, {
      "expr" = "m['dmxArchCenterCollapseDie']() != 4",
      "note" = "the destroyed arch center collapses the stone bridge in 1d4 rounds.",
    }, {
      "expr" = "m['dmxHumanLogFt']() != 10 or m['dmxStr17LogFt']() != 20 or m['dmxStr17LogFt']() != 2 * m['dmxHumanLogFt']() or m['dmxHillGiantLogFt']() != 30 or m['dmxLargeGiantLogLoFt']() != 40 or m['dmxLargeGiantLogHiFt']() != 50",
      "note" = "the move-log ladder: a normal human 10 feet, Str 17-18 or an ogre 20, a hill giant or young dragon 30, a large giant or dragon 40-50.",
    }, {
      "expr" = "m['dmxLogBridgeModPct']() != 40 or m['dmxLogSlopedModPct']() != 20 or m['dmxLogCrawlModPct']() != 80 or m['dmxLogDiaHeightDiv']() != 4",
      "note" = "the log bridge +40, sloped +20, crawling or both hands free +80; a log over 1/4 the character height is crossed automatically.",
    }, {
      "expr" = "m['dmxRopeBridgeModPct']() != 50 or m['dmxRopeSabotageClingModPct']() != -20 or m['dmxAnchorSabotageDie']() != 8 or m['dmxSawRopeRounds']() != 1",
      "note" = "the rope bridge +50 with the -20 sabotaged cling; the anchor sabotage 1d8 rounds, the sawed rope one round.",
    }, {
      "expr" = "m['dmxRoughLandingMult']() != 2 or m['dmxSoftLandingDiv']() != 2 or m['dmxVerySoftFailDiv']() != 2 or m['dmxVerySoftFailDiv']() != m['dmxSoftLandingDiv']()",
      "note" = "the landing ladder: rough doubles, soft halves, a failed very-soft save still halves.",
    }, {
      "expr" = "m['dmxSparseSpikeMinDice']() != 1 or m['dmxSparseSpikeMaxDice']() != 6 or m['dmxDenseSpikeMinDice']() != 3 or m['dmxDenseSpikeMaxDice']() != 18 or m['dmxDenseSpikeMaxDice']() != m['dmxSparseSpikeMaxDice']() * m['dmxDenseSpikeMinDice']() or m['dmxSpikeDamageDie']() != 6",
      "note" = "the spike groupings: a 1d6 group impales on 1-6 spikes, a 3d6 group on 3-18 (18 = 6 x 3), each spike an extra d6.",
    }, {
      "expr" = "m['dmxWaterLandingDiePer100Ft']() != 1 or m['dmxExample250FtWaterDice']() != 3",
      "note" = "the printed water landing: a clean 250-foot entry costs 3d6, 1d6 per 100 feet rounded up.",
    }, {
      "expr" = "m['dmxSlideFreeFt']() != 20 or m['dmxSlideDiePer10Ft']() != 1 or m['dmxSlideLandingDiePer40Ft']() != 1 or m['dmxSlipperySlideLandingMult']() != 2",
      "note" = "the slope slide: 20 feet free, 1d6 per 10 feet of slide, 1d6 per 40 feet of landing, a slippery slope lands double.",
    }, {
      "expr" = "m['dmxUprightMinCeilNum']() != 2 or m['dmxUprightMinCeilDen']() != 3 or m['dmxUprightRateNum']() != 2 or m['dmxUprightRateDen']() != 3 or m['dmxHandsKneesRateDiv']() != 2 or m['dmxHandsKneesAtkMod']() != -5 or m['dmxProneRateDiv']() != 4 or m['dmxProneAtkMod']() != -8",
      "note" = "the tight squeeze: a 2/3 ceiling walks upright at 2/3 rate, hands and knees at 1/2 rate with -5 attacks, prone at 1/4 rate with -8.",
    }, {
      "expr" = "m['dmxProneAtkMod']() >= m['dmxHandsKneesAtkMod']() or m['dmxProneRateDiv']() <= m['dmxHandsKneesRateDiv']()",
      "note" = "the prone penalties are strictly worse than the hands-and-knees penalties on both axes.",
    }, {
      "expr" = "m['dmxRubbleClearFtDie']() != 4 or m['dmxRubblePartialDieMult']() != 2 or m['dmxSolidRateDiv']() != 4",
      "note" = "the excavation: 1d4 feet of rubble per turn, 2d4 on a partial block, solid barriers at 1/4 rate without pickaxes.",
    }, {
      "expr" = "m['dmxFatigueWorkTurns']() != 4 or m['dmxFatigueRestTurns']() != 2 or m['dmxFatigueFirstCheckTurns']() != 6 or m['dmxFatigueSecondCheckAfterTurns']() != 5 or m['dmxFatigueIntervalStepTurns']() != 1",
      "note" = "the fatigue cycle: 4 turns of work against 2 of rest, the first Constitution Check at 6 turns, the next after 5 more, the interval then shrinking by one turn per check.",
    }, {
      "expr" = "m['dmxFatigueAttrMod']() != -2 or m['dmxFatigueCombatMod']() != m['dmxFatigueAttrMod']() or m['dmxFatigueEffectTurns']() != 12 or m['dmxExhaustedMod']() != 2 * m['dmxFatigueAttrMod']() or m['dmxFatigueRecoveryTurns']() != 6 or m['dmxExhaustRecoveryTurns']() != m['dmxFatigueRecoveryTurns']()",
      "note" = "fatigued: -2 attributes and -2 attacks, damage and saves until 12 turns of rest; exhausted -4 instead (twice the fatigue drop); both recoveries six turns.",
    }, {
      "expr" = "m['dmxDarkSafeRateDiv']() != 3 or m['dmxDarkRoughSafeRateDiv']() != 6 or m['dmxDarkRoughSafeRateDiv']() != 2 * m['dmxDarkSafeRateDiv']() or m['dmxDarkCourseRollEveryTurns']() != 3 or m['dmxDarkCourseShortModPerTurn']() != -1 or m['dmxDarkRoughFallDamage']() != 1",
      "note" = "the darkness rates: 1/3 safe probing, 1/6 over rough floors (twice as slow again), the course roll every 3 turns with -1 per short turn, the rough fall 1 point.",
    }, {
      "expr" = "m['dmxDarkCourseDie']() != 12 or m['dmxT9RolledDirDie']() != 6 or m['dmxT9RolledRightLo']() != 1 or m['dmxT9RolledRightHi']() != 3",
      "note" = "the course machinery: the secret 1d12 roll, the 135-degree row resolving its direction on 1d6 with 1-3 to the right.",
    }, {
      "expr" = "m['dmxSlipFailAcPenalty']() != 4 or m['dmxSlipGroundAtkMod']() != -4 or m['dmxSlipRiseRounds']() != 1 or m['dmxSlipFailRiseRounds']() != m['dmxSlipRiseRounds']() or m['dmxSlipFailAcPenalty']() != -1 * m['dmxSlipGroundAtkMod']()",
      "note" = "the melee fall: +4 AC penalty and no attack that round, rising the next round; fighting from the ground keeps the +4 AC at -4 attacks.",
    }, {
      "expr" = "m['dmxCramponAttachTurns']() != 1 or m['dmxCramponNoiseMult']() != 2 or m['dmxCramponWearDie']() != 6",
      "note" = "the crampons: one turn to attach, twice the noise on nonslippery ground, worn out in 1d6 miles of such abuse.",
    }, {
      "expr" = "m['dmxSlipSlowdownRounds']() != 1",
      "note" = "the one-round slowdown from normal to 1/2 speed buys a check-free turn.",
    } },
  "audit" = {
      "label" = "R505 DSG movement II audit",
      "comment" = "The DSG movement chapter part II pins the bridge rules (the maintained no-check rule; the suspension 25-percent-per-character give-way with the one-hand catch at -25; the anchor sabotage 1d8 rounds detectable only by a thief; the sawed rope one round and visible; the wooden 5-percent-per-year rot with the 1d20+20-year beams and the 50-percent rotten step; the stone impervious, the arch collapse 1d4 rounds and the instant foundation collapse; the rope bridge +50 with the -20 sabotaged cling; the log bridge +40, +20 sloped, +80 crawling, with the move-log ladder), the expanded falling rules (the cumulative dice with the 6d6-at-30 example, the 20d6 and 10d6 caps, the 1,000-feet-per-round rate, the 50-foot stop window, the landing ladder, the slope slide), spelunking (the 2/3 ceiling, the hands-and-knees and prone penalties, Table 7), excavation (the rubble and solid-barrier rates, Table 8), fatigue and exhaustion (the 4/2 cycle, the shrinking check interval, the -2 and -4 effects, the recoveries), the darkness movement (the rates, the secret d12 course roll, Table 9), and the slippery surfaces (the dex checks, the melee fall penalties, the crampons).",
    },
}
