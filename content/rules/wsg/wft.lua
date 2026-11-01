-- wft: promoted from tools/spec_r489.json (the R489: the WSG FATIGUE chapter slice, printed pp. 87-89 - the round CLOSING the wilderness combat chapter with the close-to-the-ground dismount tail and landing the FULL fatigue and exhaustion chapter: the character strenuous rhythm with the shrinking check intervals and the fatigue and exhaustion penalties with their recovery chains and the carried-rest rules, the land-based mount nourishment and overwork rules with the fatigued movement and armor class effects and the cumulative exhaustion chance with the collapse ladder and the trauma drain, and the flying-mount stamina rules with the 1d10 fatigue check and the steep-dive buffet and thrown-rider damage - the mounts and beasts of burden catalog rides to R490.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 489,
  "prefix" = "wft",
  "banner" = {
      "title" = "R489: the WSG FATIGUE chapter slice, printed pp. 87-89 - the round CLOSING the wilderness combat chapter with the close-to-the-ground dismount tail and landing the FULL fatigue and exhaustion chapter: the character strenuous rhythm with the shrinking check intervals and the fatigue and exhaustion penalties with their recovery chains and the carried-rest rules, the land-based mount nourishment and overwork rules with the fatigued movement and armor class effects and the cumulative exhaustion chance with the collapse ladder and the trauma drain, and the flying-mount stamina rules with the 1d10 fatigue check and the steep-dive buffet and thrown-rider damage - the mounts and beasts of burden catalog rides to R490.",
      "provenance" = "THE SETTLE: two-way clean on the first pass - the tesseract full-text reads, the pdftotext layout read and the tsv coordinate reads agree on every number (the 4-turn risk, the 2-turn rest, the 6-turn check, the 5 more turns, the 1-turn step and minimum, the score drop of 2 with the 2-hour clear, the example scores 18 18 and 14 with the temporary 16 and effective 12, the per-turn check, the 1-hour exhausted recovery, the 2 and 3 day animal nutrition bars with the 8-hour rest, the 12-plus-2 overwork formula with the 18-hour horse example, the half rate with the 1-round bursts, the 3-inch terrain bar, the 7-to-9 armor class example, the 20 percent cumulative chance with the 1-hour reset, the 25 50 75 collapse ladder, the flat 50 percent death chance within 1d4 hours, the 1d6-minus-3 trauma drain through 8 hours with the 2-per-hour regain, the 24/6 black dragon with the 1-4 on 1d10, the 30-turn non-block window, the two-thirds rate with 10 yards per round, the 100-yard same-turn landing bar, the 1d2 buffet per 10 yards, the 11-40 thrown damage as 3d10 plus 10, and the three-times 18-turn post-fatigue rest). The garbles settled without contest: the layout l d 4 l d 6 l d l O l d 2 and 1dlO classes are 1d4 1d6 1d10 and 1d2, Constutition and conscutive are the book typos for constitution and consecutive, 3 inches renders the 3-inch terrain bar, and hump(s) survives the hump-at glyph. The p. 87 cut turned out to be a column wrap WITHIN the page, not a page cut: the right column carries the Dungeon Master may allow a character with proficiency in riding the mount to leap from its back and land safely on the ground - the dismount section is complete and only the connective pin rides to this round.",
      "sentinel" = "Bounds held: the fatigue score drop equals the exhausted extra drop equals the attack and save penalty, the shrinking check interval floors at the step size, the animal nutrition bars run 2 and 3 days with the 8-hour recovery, the overwork formula makes the 3-hour horse rest 18, the fatigued animal moves at half rate with the 3-inch bar and the two-place armor class example, the collapse ladder climbs 25 50 75 in equal steps, the trauma roll floors at zero with the 8-hour critical period, the black dragon stamina runs 24 turns in 4 hours and 6 turns in 1 hour, the 1d10 fatigue chance is 10 minus the rest number, the fatigued flying rate is two-thirds with the 100-yard same-turn landing bar, the thrown damage is exactly 3d10 plus 10 spanning 11 to 40, and the post-fatigue rest is three times the normal period at 18 turns.",
    },
  "consts" = { {
      "name" = "wftStrenuousRiskTurns",
      "value" = 4,
      "comment" = "a character runs the risk of becoming fatigued whenever he engages in strenuous activity for more than four turns in succession",
    }, {
      "name" = "wftAvoidRiskRestTurns",
      "value" = 2,
      "comment" = "to avoid the risk of fatigue a character must rest for two consecutive turns after four turns of strenuous activity",
    }, {
      "name" = "wftFirstConCheckTurns",
      "value" = 6,
      "comment" = "if the character chooses not to rest, he must make a Constitution Check after exerting himself for six consecutive turns",
    }, {
      "name" = "wftSuccessExtraTurns",
      "value" = 5,
      "comment" = "a successful check indicates he can remain active for at least five more turns",
    }, {
      "name" = "wftCheckStepReductionTurns",
      "value" = 1,
      "comment" = "every time a check is successful, the time until the next required check is reduced by one turn",
    }, {
      "name" = "wftCheckIntervalMinTurns",
      "value" = 1,
      "comment" = "the shrinking check interval bottoms out at a minimum of one turn",
    }, {
      "name" = "wftFatigueScoreDrop",
      "value" = 2,
      "comment" = "all of the ability scores of a fatigued character except comeliness are lowered by 2 until he rests for two consecutive hours",
    }, {
      "name" = "wftFatigueClearRestHours",
      "value" = 2,
      "comment" = "the fatigue penalties remain in effect until the character rests for two consecutive hours",
    }, {
      "name" = "wftExampleStrScore",
      "value" = 18,
      "comment" = "the strength example: a character with 18 strength who becomes fatigued loses his +1 bonus on to-hit rolls and has his damage bonus reduced from +2 to +1",
    }, {
      "name" = "wftExampleConScore",
      "value" = 18,
      "comment" = "the constitution example: a fighter with 18 constitution who becomes fatigued immediately loses 2 hit points for each hit die he has, reflecting his temporary constitution of 16",
    }, {
      "name" = "wftExampleWisScore",
      "value" = 14,
      "comment" = "the wisdom example: a cleric with 14 wisdom who becomes fatigued loses both of his bonus 1st-level spells, his effective wisdom now 12",
    }, {
      "name" = "wftFatigueAtkSavePenalty",
      "value" = 2,
      "comment" = "in addition to the ability-score penalties, a fatigued character suffers a -2 penalty on all attack rolls (to hit and damage) and saving throws",
    }, {
      "name" = "wftFatigueCheckEveryTurns",
      "value" = 1,
      "comment" = "a fatigued character continuing strenuous activity must make a Constitution Check once per turn, using his fatigue-reduced constitution score",
    }, {
      "name" = "wftExhaustExtraScoreDrop",
      "value" = 2,
      "comment" = "an exhausted character takes an additional -2 penalty on all of his ability scores, attack rolls and saving throws",
    }, {
      "name" = "wftExhaustRecoverRestHours",
      "value" = 1,
      "comment" = "if an exhausted character rests for one hour without interruption, he can recover from exhaustion by making a successful Constitution Check with his temporarily reduced score",
    }, {
      "name" = "wftFatigueAfterExhaustRestHours",
      "value" = 2,
      "comment" = "a character who recovers from exhaustion is only fatigued, and then recovers from fatigue by resting for another two hours",
    }, {
      "name" = "wftAnimalNoFoodDays",
      "value" = 2,
      "comment" = "an animal becomes fatigued if forced to go for two consecutive days without any food and water",
    }, {
      "name" = "wftAnimalShortRationDays",
      "value" = 3,
      "comment" = "an animal becomes fatigued if forced to subsist on less than its full normal daily ration for more than three consecutive days",
    }, {
      "name" = "wftRationRecoveryRestHours",
      "value" = 8,
      "comment" = "to recover from fatigue due to lack of nourishment, an animal must be given a full normal ration of food and water and allowed to rest for eight hours afterward",
    }, {
      "name" = "wftOverworkBaseRestHours",
      "value" = 12,
      "comment" = "to recover from fatigue due to overexertion, an animal must rest for 12 hours plus two hours for every hour it was overworked",
    }, {
      "name" = "wftOverworkRestPerHour",
      "value" = 2,
      "comment" = "the overwork recovery adds two hours of rest per hour of overwork",
    }, {
      "name" = "wftHorseExampleOverworkHours",
      "value" = 3,
      "comment" = "the horse example: pushed three hours beyond the normal limit of its stamina",
    }, {
      "name" = "wftHorseExampleRestHours",
      "value" = 18,
      "comment" = "the horse example: it remains fatigued until allowed to rest for at least 18 hours without interruption (12 + 2 per overworked hour)",
    }, {
      "name" = "wftAnimalFatigueMoveNum",
      "value" = 1,
      "comment" = "a fatigued animal moves at one-half of its normal movement rate - the numerator",
    }, {
      "name" = "wftAnimalFatigueMoveDen",
      "value" = 2,
      "comment" = "the fatigued animal movement fraction - the denominator",
    }, {
      "name" = "wftBurstFullRateRoundsPerTurn",
      "value" = 1,
      "comment" = "a fatigued animal is capable of occasional bursts of speed enabling it to move at its full normal rate for one round per turn",
    }, {
      "name" = "wftFatiguedTerrainBarInches",
      "value" = 3,
      "comment" = "a fatigued animal is not able to negotiate any terrain in which its full normal movement rate is 3 inches",
    }, {
      "name" = "wftAnimalFatigueAcPlaces",
      "value" = 2,
      "comment" = "the armor class of a fatigued animal is two places worse than normal, accounting for its slower reflexes",
    }, {
      "name" = "wftAnimalFatigueAcFrom",
      "value" = 7,
      "comment" = "the fatigued armor class example - the normal class",
    }, {
      "name" = "wftAnimalFatigueAcTo",
      "value" = 9,
      "comment" = "the fatigued armor class example - the worsened class",
    }, {
      "name" = "wftExhaustionHourChancePct",
      "value" = 20,
      "comment" = "if a fatigued animal is forced to keep working or moving, there is a 20 percent chance per hour, cumulative, that it will become exhausted",
    }, {
      "name" = "wftExhaustionResetRestHours",
      "value" = 1,
      "comment" = "after any rest period of at least one hour the cumulative chance of exhaustion begins again at 20 percent",
    }, {
      "name" = "wftCollapseUnburdenedPct",
      "value" = 25,
      "comment" = "an exhausted animal may collapse: 25 percent chance if unburdened",
    }, {
      "name" = "wftCollapseBurdenedPct",
      "value" = 50,
      "comment" = "the collapse chance if carrying a rider or a normal load: 50 percent",
    }, {
      "name" = "wftCollapseOverloadedPct",
      "value" = 75,
      "comment" = "the collapse chance if carrying more than a normal load: 75 percent",
    }, {
      "name" = "wftExhaustDeathChancePct",
      "value" = 50,
      "comment" = "there is a flat 50 percent chance that an animal driven to exhaustion will die within 1d4 hours, checked as soon as it collapses",
    }, {
      "name" = "wftExhaustDeathWindowDie",
      "value" = 4,
      "comment" = "the death window: the animal may die within 1d4 hours of collapse",
    }, {
      "name" = "wftTraumaDie",
      "value" = 6,
      "comment" = "once per hour for eight consecutive hours the Dungeon Master rolls 1d6 for the collapsed animal",
    }, {
      "name" = "wftTraumaSubtract",
      "value" = 3,
      "comment" = "the trauma roll subtracts 3 from the 1d6 result",
    }, {
      "name" = "wftTraumaMaxLoss",
      "value" = 3,
      "comment" = "the trauma roll yields a number in the range 0-3, the hit points lost during that hour",
    }, {
      "name" = "wftTraumaHours",
      "value" = 8,
      "comment" = "the trauma rolls run once per hour for eight consecutive hours - the critical period",
    }, {
      "name" = "wftTraumaRegainPerHour",
      "value" = 2,
      "comment" = "an animal that survives the critical period regains its lost hit points at the rate of 2 per hour",
    }, {
      "name" = "wftDragonSafeTurns",
      "value" = 24,
      "comment" = "the black dragon example: stamina values 24/6, safe flying time 24 consecutive turns",
    }, {
      "name" = "wftDragonRestTurns",
      "value" = 6,
      "comment" = "the black dragon rest value: 6 turns of landed rest to regain stamina",
    }, {
      "name" = "wftDragonSafeHours",
      "value" = 4,
      "comment" = "the black dragon safe flying time in hours: 24 turns is four hours",
    }, {
      "name" = "wftDragonRestHours",
      "value" = 1,
      "comment" = "the black dragon rest period in hours: 6 turns is one hour",
    }, {
      "name" = "wftFatigueCheckDie",
      "value" = 10,
      "comment" = "past the safe flying time the Dungeon Master rolls 1d10 on a turn-by-turn basis to see if the flying mount becomes fatigued",
    }, {
      "name" = "wftFatigueChanceBase",
      "value" = 10,
      "comment" = "the chance of fatigue is equal to 10 minus the second number of the stamina value",
    }, {
      "name" = "wftDragonFatigueRollLow",
      "value" = 1,
      "comment" = "the black dragon fatigues on any turn past its safe time when the 1d10 roll is 1-4 - the low end",
    }, {
      "name" = "wftDragonFatigueRollHigh",
      "value" = 4,
      "comment" = "the black dragon fatigue roll high end: 1-4 on 1d10 (10 minus its rest value of 6)",
    }, {
      "name" = "wftExampleWindowTurns",
      "value" = 30,
      "comment" = "the non-block example: over a period of 30 turns the dragon is aloft 24 and rests 6, within the safe limit",
    }, {
      "name" = "wftExampleLastFlightTurns",
      "value" = 7,
      "comment" = "the example variant: a 7-turn last flight period puts the dragon aloft 25 turns without 6 turns of rest, risking fatigue on the 7th turn",
    }, {
      "name" = "wftFatigueMoveNum",
      "value" = 2,
      "comment" = "on the turn fatigue sets in the flying mount movement rate drops to two-thirds of full normal - the numerator",
    }, {
      "name" = "wftFatigueMoveDen",
      "value" = 3,
      "comment" = "the fatigued flying mount movement fraction - the denominator",
    }, {
      "name" = "wftFatigueLossPerRoundYards",
      "value" = 10,
      "comment" = "a fatigued flying mount gradually loses altitude at 10 yards per round",
    }, {
      "name" = "wftSameTurnLandingAltitudeYards",
      "value" = 100,
      "comment" = "a flying mount not more than 100 yards above the ground and not forced to remain aloft can descend and make a safe landing in the same turn fatigue sets in",
    }, {
      "name" = "wftBuffetDieSides",
      "value" = 2,
      "comment" = "for every 10 yards dived a rider suffers 1d2 hit points of damage at the end of the flight",
    }, {
      "name" = "wftBuffetPerYards",
      "value" = 10,
      "comment" = "the buffet damage accrues per 10 yards of dive distance",
    }, {
      "name" = "wftThrownDmgMin",
      "value" = 11,
      "comment" = "an unstrapped rider thrown on landing suffers 11-40 hit points of damage - the minimum",
    }, {
      "name" = "wftThrownDmgMax",
      "value" = 40,
      "comment" = "the thrown-rider damage maximum: 40",
    }, {
      "name" = "wftThrownDiceCount",
      "value" = 3,
      "comment" = "the thrown-rider damage is 3d10 plus 10",
    }, {
      "name" = "wftThrownDieSides",
      "value" = 10,
      "comment" = "the thrown-rider damage die: 3d10",
    }, {
      "name" = "wftThrownBase",
      "value" = 10,
      "comment" = "the thrown-rider damage base: +10 on 3d10",
    }, {
      "name" = "wftPostFatigueRestMult",
      "value" = 3,
      "comment" = "a fatigued flying mount that lands refuses to take off again for at least three times its normal rest period",
    }, {
      "name" = "wftDragonPostFatigueRestTurns",
      "value" = 18,
      "comment" = "the black dragon post-fatigue rest: 18 turns (three times its 6-turn rest period)",
    } },
  "bools" = { {
      "name" = "wftOpenerThreat",
      "value" = true,
      "comment" = "even the strongest and hardiest characters and creatures cannot exert themselves indefinitely without becoming tired and needing rest; a long journey pressed too hard may exhaust the party long before the destination, and taking measures to avoid fatigue and exhaustion is not difficult and usually not inconvenient",
    }, {
      "name" = "wftGroundDeathProficientLeap",
      "value" = true,
      "comment" = "the R488 cut tail: if the flying mount dies close to the ground, the Dungeon Master may allow a character with proficiency in riding the mount to leap from its back and land safely on the ground",
    }, {
      "name" = "wftStrenuousOverfullMove",
      "value" = true,
      "comment" = "a character moving at greater than his full normal movement rate is engaged in strenuous activity",
    }, {
      "name" = "wftStrenuousMelee",
      "value" = true,
      "comment" = "a character involved in melee combat is engaged in strenuous activity",
    }, {
      "name" = "wftStrenuousOtherExamples",
      "value" = true,
      "comment" = "continuous climbing, swimming against a strong current, and moving while severely encumbered are other examples of strenuous activity",
    }, {
      "name" = "wftCheckFailFatigued",
      "value" = true,
      "comment" = "failure on the Constitution Check indicates the character is fatigued",
    }, {
      "name" = "wftIntervalShrinksPerSuccess",
      "value" = true,
      "comment" = "each successful check grants activity but shortens the interval to the next required check, to a minimum of one turn",
    }, {
      "name" = "wftHighConEventuallyCaught",
      "value" = true,
      "comment" = "a character with an extremely high constitution may keep performing a strenuous activity for several hours, but the odds will eventually catch up with him",
    }, {
      "name" = "wftFatigueScoresExceptComeliness",
      "value" = true,
      "comment" = "all of the ability scores of a fatigued character except comeliness are lowered by 2, and most incidental benefits bestowed by the higher scores are also lost as long as he remains fatigued",
    }, {
      "name" = "wftStr18ExampleDetail",
      "value" = true,
      "comment" = "the 18-strength fatigued example: the +1 to-hit bonus is lost and the damage bonus drops from +2 to +1, among other penalties",
    }, {
      "name" = "wftCon18ExampleDetail",
      "value" = true,
      "comment" = "the 18-constitution fatigued example: the fighter loses 2 hit points for each hit die, his actual temporary constitution score being only 16",
    }, {
      "name" = "wftWis14ExampleDetail",
      "value" = true,
      "comment" = "the 14-wisdom fatigued example: the cleric loses both bonus 1st-level spells; if spells are in memory two 1st-level spells are lost at random, higher-level spells lost instead if fewer than two are held, the bonus spells cannot be regained, and every spell cast carries a chance of failure until he is no longer fatigued",
    }, {
      "name" = "wftChecksUseReducedScores",
      "value" = true,
      "comment" = "any Proficiency Check or Ability Check required of a fatigued character has a smaller chance of success, the die roll compared to the current ability score instead of the normal score",
    }, {
      "name" = "wftFatiguedCanContinue",
      "value" = true,
      "comment" = "a fatigued character can continue to perform strenuous activity, but must make a Constitution Check once per turn while doing so",
    }, {
      "name" = "wftFatiguedFailExhausted",
      "value" = true,
      "comment" = "if a fatigued character fails a Constitution Check, he becomes exhausted",
    }, {
      "name" = "wftExhaustedOnlyDefense",
      "value" = true,
      "comment" = "an exhausted character can attempt to defend himself or perform some other physical action only when failure to move would mean risking death",
    }, {
      "name" = "wftExhaustedCannotAct",
      "value" = true,
      "comment" = "otherwise an exhausted character is not capable of any voluntary physical activity: he cannot move under his own power, put on or take off armor, build a fire, or do anything else requiring minimal strength and muscle control",
    }, {
      "name" = "wftExhaustRecoverByCheck",
      "value" = true,
      "comment" = "one hour of uninterrupted rest plus a successful Constitution Check (at the reduced score) leaves the character only fatigued instead of exhausted",
    }, {
      "name" = "wftExhaustRecoverFailLoop",
      "value" = true,
      "comment" = "if the recovery check fails, the character remains exhausted and must rest for another hour before trying again",
    }, {
      "name" = "wftRestWhileCarried",
      "value" = true,
      "comment" = "a fatigued or exhausted character can rest while being carried, as long as no strength or balance is needed to remain in position and he is not bounced or jostled; a fighter draping a frail magic-user across his shoulders works, but a choppy or zig-zagging path across rugged or very rugged terrain spoils the rest",
    }, {
      "name" = "wftRestTiedToMount",
      "value" = true,
      "comment" = "an exhausted character can rest while securely tied to the back of a horse or other mount, but only if the mount moves easily (no faster than normal movement rate) over terrain that is not difficult for the animal to negotiate",
    }, {
      "name" = "wftAnimalCrossRefs",
      "value" = true,
      "comment" = "the stamina process is in the Encumbrance and Movement section, the animal-care specifics are in Mounts and Beasts of Burden, and these general fatigue rules apply in all cases not specifically accounted for elsewhere",
    }, {
      "name" = "wftAnimalFatiguedNoFood",
      "value" = true,
      "comment" = "two consecutive days without any food and water fatigues the animal",
    }, {
      "name" = "wftAnimalFatiguedShortRation",
      "value" = true,
      "comment" = "less than the full normal daily ration for more than three consecutive days fatigues the animal",
    }, {
      "name" = "wftRationRecoveryNeedsBoth",
      "value" = true,
      "comment" = "nourishment recovery requires BOTH the full ration and the full eight hours of rest; missing either leaves the animal fatigued",
    }, {
      "name" = "wftOverworkRecoveryFormula",
      "value" = true,
      "comment" = "overwork recovery is 12 hours of rest plus two hours per hour overworked; the pushed horse example rests 18 hours",
    }, {
      "name" = "wftFatiguedHalfMoveWithBursts",
      "value" = true,
      "comment" = "a fatigued animal moves at half its normal rate with occasional one-round-per-turn bursts of full speed",
    }, {
      "name" = "wftFatiguedTerrainBarDetail",
      "value" = true,
      "comment" = "the fatigued terrain bar: no terrain whose full normal rate is 3 inches; a fatigued horse cannot move in very rugged terrain carrying more than a normal load, and a fatigued camel cannot move in very rugged terrain under any circumstances",
    }, {
      "name" = "wftFatiguedAcWorse",
      "value" = true,
      "comment" = "a fatigued animal is two armor class places worse (7 to 9, for instance) - slower reflexes",
    }, {
      "name" = "wftExcitedOnlyHandlerCalms",
      "value" = true,
      "comment" = "if a fatigued animal becomes excited, only a character with proficiency in animal handling can get it to calm down, and that chance is only as great as the normal chance for a nonproficient character",
    }, {
      "name" = "wftWorkedFatiguedExhaustionChance",
      "value" = true,
      "comment" = "a fatigued animal forced to keep working faces a cumulative 20 percent chance per hour of becoming exhausted",
    }, {
      "name" = "wftBriefWorkRestResets",
      "value" = true,
      "comment" = "worked briefly without exhaustion and then rested at least an hour, the animal recovers somewhat and the cumulative chance starts again at 20 percent",
    }, {
      "name" = "wftExhaustedStopsInTracks",
      "value" = true,
      "comment" = "an exhausted animal stops in its tracks, incapable of moving or working; near death, its survival without magical aid depends entirely on chance",
    }, {
      "name" = "wftExhaustedCollapseOblivious",
      "value" = true,
      "comment" = "the exhausted animal may collapse (25/50/75 percent by burden) and while incapacitated is oblivious to anything going on around it",
    }, {
      "name" = "wftExhaustedNoPanicNoDefense",
      "value" = true,
      "comment" = "an exhausted animal will not become excited or panicked even if threatened by fire, but will make no attempt to protect itself from attack or injury",
    }, {
      "name" = "wftExhaustedDeathCheck",
      "value" = true,
      "comment" = "a flat 50 percent chance that the exhausted animal dies within 1d4 hours, checked by the Dungeon Master as soon as it collapses",
    }, {
      "name" = "wftExhaustedTraumaDrain",
      "value" = true,
      "comment" = "once per hour for eight consecutive hours the trauma roll is 1d6 minus 3, losing 0-3 hit points per hour; at a hit-point total of 0 the animal is dead",
    }, {
      "name" = "wftExhaustedTraumaRecovery",
      "value" = true,
      "comment" = "surviving the eight-hour critical period, the animal regains lost hit points at 2 per hour and is recovered from exhaustion (but still fatigued) when the total reaches its pre-exhaustion level",
    }, {
      "name" = "wftFlyingNeverExhausted",
      "value" = true,
      "comment" = "a flying mount can never become exhausted; but if it becomes fatigued, the rider stands to suffer at least as much as the animal, and perhaps a whole lot more",
    }, {
      "name" = "wftStaminaTableCrossRef",
      "value" = true,
      "comment" = "the Characteristics of Flying Mounts table in the Movement and Encumbrance section gives the stamina values; the first number is the safe flying time",
    }, {
      "name" = "wftHeavyLoadReducesSafe",
      "value" = true,
      "comment" = "the safe flying time may be reduced if the creature is heavily loaded down",
    }, {
      "name" = "wftFatigueRollPastSafe",
      "value" = true,
      "comment" = "once aloft for consecutive turns equal to its safe flying time, the Dungeon Master begins rolling 1d10 each turn thereafter",
    }, {
      "name" = "wftFatigueChanceFormula",
      "value" = true,
      "comment" = "the chance of fatigue is equal to 10 minus the second number of the stamina value",
    }, {
      "name" = "wftDragonExample",
      "value" = true,
      "comment" = "the black dragon 24/6: ridden through the air 24 consecutive turns (four hours) without risk, then it must land and rest (not fly) 6 turns (one hour) to regain stamina; past the 24th turn it fatigues on a 1d10 roll of 1-4",
    }, {
      "name" = "wftFlyingRestNotFullBlocks",
      "value" = true,
      "comment" = "flying time and rest time need not be taken in full blocks: flown 12, rested 3, flown 6, rested 2, flown 6, rested 1 - 24 aloft and 6 rest in a 30-turn window is safe; but the 7-turn last flight means 25 turns aloft without the 6 turns of rest, risking fatigue",
    }, {
      "name" = "wftExceedNeedsFullRest",
      "value" = true,
      "comment" = "a creature that exceeds its safe flying time and is brought to a safe landing must have a FULL rest period or it is subject to fatigue as soon as it takes to the air again",
    }, {
      "name" = "wftTrackAloftAndRest",
      "value" = true,
      "comment" = "keep careful track of how much the mount has flown and rested; exceeding the safe flying time by even a small amount can cause an extended delay on a long-distance journey",
    }, {
      "name" = "wftFatigueTwoThirdsMove",
      "value" = true,
      "comment" = "on the turn fatigue sets in the movement rate drops to two-thirds of normal and the mount begins losing altitude at 10 yards per round",
    }, {
      "name" = "wftFatigueSafeLandingSameTurn",
      "value" = true,
      "comment" = "not more than 100 yards up and not forced to remain aloft, the fatigued mount can descend and land safely in the same turn",
    }, {
      "name" = "wftSecondTurnSteepDive",
      "value" = true,
      "comment" = "more than 100 yards up when fatigue sets in, the mount is still aloft when its second turn of fatigue begins: it stops descending gradually and goes into a steep dive toward a resting place; riders face an increased chance of falling and the sudden stop at the end",
    }, {
      "name" = "wftDiveBuffetDamage",
      "value" = true,
      "comment" = "for every 10 yards dived before reaching the ground a rider suffers 1d2 hit points at the end of the flight from the buffeting of the crash, bounce or skid to a stop",
    }, {
      "name" = "wftBuffetHalvedFor",
      "value" = true,
      "comment" = "the buffet damage is halved for a character with proficiency in airborne riding or one securely strapped (upper and lower body) to the back of the mount",
    }, {
      "name" = "wftUnstrappedThrown",
      "value" = true,
      "comment" = "a rider without at least his lower body strapped suffers no buffeting damage but is thrown from the mount when it lands, suffering 11-40 hit points (3d10 + 10) from the abrasion and impact of the tumble",
    }, {
      "name" = "wftPostFatigueGroundRefusal",
      "value" = true,
      "comment" = "a fatigued flying mount that lands refuses to take off again for at least three times its normal rest period (18 turns for a black dragon), unless self-preservation dictates that it become airborne",
    }, {
      "name" = "wftEarlyTakeoffFatigueRisk",
      "value" = true,
      "comment" = "taking off again for any reason before the full post-fatigue rest period expires, the mount has a chance of becoming fatigued on every turn it remains aloft",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the strenuous rhythm: risk after more than 4 turns, 2 turns of rest avoids it, the first Constitution Check at 6 turns, 5 more turns on success, the interval shrinking by 1 to a minimum of 1",
      "expr" = "m['wftStrenuousRiskTurns']() != 4 or m['wftAvoidRiskRestTurns']() != 2 or m['wftFirstConCheckTurns']() != 6 or m['wftSuccessExtraTurns']() != 5 or m['wftCheckStepReductionTurns']() != m['wftCheckIntervalMinTurns']()",
    }, {
      "note" = "the fatigue penalties: the score drop 2, the exhausted extra drop equal to it, the attack/save penalty equal to it, and the 2-hour clear equal to the post-exhaustion fatigue clear",
      "expr" = "m['wftFatigueScoreDrop']() != 2 or m['wftExhaustExtraScoreDrop']() != m['wftFatigueScoreDrop']() or m['wftFatigueAtkSavePenalty']() != m['wftFatigueScoreDrop']() or m['wftFatigueClearRestHours']() != m['wftFatigueAfterExhaustRestHours']()",
    }, {
      "note" = "the example scores: strength 18, constitution 18, wisdom 14",
      "expr" = "m['wftExampleStrScore']() != 18 or m['wftExampleConScore']() != 18 or m['wftExampleWisScore']() != 14",
    }, {
      "note" = "the recovery rhythm: the fatigued check once per turn and the exhausted recovery rest of 1 hour",
      "expr" = "m['wftFatigueCheckEveryTurns']() != 1 or m['wftExhaustRecoverRestHours']() != 1",
    }, {
      "note" = "the animal nourishment rules: 2 days without food and water, 3 days short rations, 8 hours rest to recover",
      "expr" = "m['wftAnimalNoFoodDays']() != 2 or m['wftAnimalShortRationDays']() != 3 or m['wftRationRecoveryRestHours']() != 8",
    }, {
      "note" = "the overwork formula: 12 hours plus 2 per overworked hour, the 3-hour horse needing 18 hours of rest",
      "expr" = "m['wftOverworkBaseRestHours']() + m['wftOverworkRestPerHour']() * m['wftHorseExampleOverworkHours']() != m['wftHorseExampleRestHours']()",
    }, {
      "note" = "the fatigued animal effects: half movement, the 3-inch terrain bar, and the armor class example 7 to 9 being exactly 2 places",
      "expr" = "m['wftAnimalFatigueMoveNum']() * 2 != m['wftAnimalFatigueMoveDen']() or m['wftFatiguedTerrainBarInches']() != 3 or m['wftAnimalFatigueAcTo']() - m['wftAnimalFatigueAcFrom']() != m['wftAnimalFatigueAcPlaces']()",
    }, {
      "note" = "the exhaustion chance: 20 percent per hour cumulative, resetting after a rest of at least 1 hour",
      "expr" = "m['wftExhaustionHourChancePct']() != 20 or m['wftExhaustionResetRestHours']() != 1",
    }, {
      "note" = "the collapse ladder: 25 unburdened, 50 with a rider or normal load, 75 overloaded, in equal 25-point steps",
      "expr" = "m['wftCollapseUnburdenedPct']() + 25 != m['wftCollapseBurdenedPct']() or m['wftCollapseBurdenedPct']() + 25 != m['wftCollapseOverloadedPct']()",
    }, {
      "note" = "the trauma rules: 1d6 minus 3 yields 0-3, the floor at zero, the 8-hour critical period and the 2-per-hour regain",
      "expr" = "m['wftTraumaDie']() - m['wftTraumaSubtract']() != m['wftTraumaMaxLoss']() or m['wftTraumaDie']() - 2 * m['wftTraumaSubtract']() != 0 or m['wftTraumaHours']() != 8 or m['wftTraumaRegainPerHour']() != 2",
    }, {
      "note" = "the black dragon stamina: 24 turns safe, 6 turns rest, four hours and one hour",
      "expr" = "m['wftDragonSafeTurns']() != 24 or m['wftDragonRestTurns']() != 6 or m['wftDragonSafeHours']() * 6 != m['wftDragonSafeTurns']() or m['wftDragonRestTurns']() != 6 * m['wftDragonRestHours']()",
    }, {
      "note" = "the fatigue roll: 1d10 past the safe time, the chance 10 minus the rest number, the dragon fatiguing on 1-4",
      "expr" = "m['wftFatigueCheckDie']() != 10 or m['wftFatigueChanceBase']() - m['wftDragonRestTurns']() != m['wftDragonFatigueRollHigh']() or m['wftDragonFatigueRollLow']() != 1 or m['wftDragonFatigueRollHigh']() != 4",
    }, {
      "note" = "the non-block example: the 30-turn window holding 24 aloft and 6 rest, and the 7-turn last flight risking the fatigue",
      "expr" = "m['wftExampleWindowTurns']() - m['wftDragonSafeTurns']() != m['wftDragonRestTurns']() or m['wftExampleLastFlightTurns']() != 7",
    }, {
      "note" = "the fatigued flying mount: two-thirds movement, 10 yards lost per round, the same-turn safe landing bar at 100 yards",
      "expr" = "m['wftFatigueMoveNum']() * 3 != m['wftFatigueMoveDen']() * 2 or m['wftFatigueLossPerRoundYards']() != 10 or m['wftSameTurnLandingAltitudeYards']() != 100",
    }, {
      "note" = "the dive damage: 1d2 per 10 yards dived, the thrown rider at 11-40 which is exactly 3d10 plus 10",
      "expr" = "m['wftBuffetDieSides']() != 2 or m['wftBuffetPerYards']() != 10 or m['wftThrownDiceCount']() * m['wftThrownDieSides']() + m['wftThrownBase']() != m['wftThrownDmgMax']() or m['wftThrownDmgMin']() != m['wftThrownBase']() + 1",
    }, {
      "note" = "the post-fatigue rest: three times the normal rest period, 18 turns for the black dragon",
      "expr" = "m['wftPostFatigueRestMult']() * m['wftDragonRestTurns']() != m['wftDragonPostFatigueRestTurns']() or m['wftDragonPostFatigueRestTurns']() != 18",
    } },
  "audit" = {
      "label" = "R489 WSG fatigue chapter pin audit",
      "comment" = "The fatigue and exhaustion chapter with the p. 87 dismount tail: the close-to-the-ground flying-mount death allowing the proficient rider to leap and land safely, closing the wilderness combat chapter. Characters: strenuous activity past 4 turns risks fatigue (over-full movement, melee, continuous climbing, swimming against a strong current, severe encumbrance), 2 consecutive turns of rest avoid the risk, the first Constitution Check at 6 turns, success buying 5 more turns with the interval shrinking by 1 to a minimum of 1; fatigue drops every ability score except comeliness by 2 until 2 consecutive hours of rest, with the 18-strength, 18-constitution and 14-wisdom examples (lost to-hit and reduced damage, 2 hit points per hit die at a temporary 16, and both bonus 1st-level spells lost with a spell-failure chance at an effective 12); checks read the current score, a further -2 on attacks and saves, a per-turn Constitution Check while continuing, failure meaning exhaustion with another -2 and no voluntary action except when failure to move risks death; 1 hour of rest plus a successful check leaves only fatigue, cleared by 2 more hours; rest while carried when no strength or balance is needed and no jostling occurs, and rest tied to a mount moving easily over easy ground. Land-based mounts: 2 days without food and water or 3 days short rations fatigues, full ration plus 8 hours rest recovers, overwork recovery is 12 hours plus 2 per hour overworked (the 3-hour horse resting 18); the fatigued animal moves at half rate with 1-round-per-turn bursts, cannot negotiate 3-inch terrain (the loaded horse and the camel in very rugged ground), and is 2 armor class places worse (7 to 9); only an animal-handling proficient character can calm the excited fatigued animal and only at the nonproficient chance; forced work risks a cumulative 20 percent exhaustion chance per hour, reset by an hour of rest; the exhausted animal stops in its tracks, may collapse (25 unburdened, 50 burdened, 75 overloaded), is oblivious, will not panic and will not defend itself, faces a flat 50 percent death chance within 1d4 hours, and drains 1d6 minus 3 hit points per hour through an 8-hour critical period, regaining 2 per hour after survival but still fatigued. Flying mounts: never exhausted; the stamina table first number is safe flying time (reduced when heavily loaded), past it a 1d10 per turn with the fatigue chance 10 minus the rest number (the black dragon 24/6 fatiguing on 1-4); flying and rest need not be full blocks (the 30-turn window with 24 aloft and 6 rest, the 7-turn last flight risking fatigue), exceeding the safe time then landing demands a full rest period; on fatigue the rate drops to two-thirds with 10 yards of altitude lost per round, a same-turn safe landing within 100 yards, past that a second-turn steep dive with 1d2 buffet damage per 10 yards dived halved for airborne-riding proficiency or secure strapping, the unstrapped rider thrown for 11-40 (3d10 plus 10); after landing the mount refuses flight for three times its rest period (18 turns for the dragon) unless self-preservation dictates otherwise, early takeoff risking fatigue every turn aloft.",
    },
}
