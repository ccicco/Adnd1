-- wpd: promoted from tools/spec_r498.json (the The WSG PROFICIENCIES PROSE, R498: the chapter frame and the twenty-five descriptions, printed pp. 11-17 (pdf 12-18). The Table 1/2 grids and the check/improving/expanding system stay with R425 (rules/wsg/wsgprof.h) as seams; this round pins the prose around and between them - every description mechanic from the 1-in-6 alertness surprise to the weather sense lockout.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 498,
  "prefix" = "wpd",
  "banner" = {
      "title" = "The WSG PROFICIENCIES PROSE, R498: the chapter frame and the twenty-five descriptions, printed pp. 11-17 (pdf 12-18). The Table 1/2 grids and the check/improving/expanding system stay with R425 (rules/wsg/wsgprof.h) as seams; this round pins the prose around and between them - every description mechanic from the 1-in-6 alertness surprise to the weather sense lockout.",
      "provenance" = "WSG printed pp. 11-17, pdf 12-18, extracted at r497-extraction sha 0d5f109 (tesseract full-text and tsv, x12-x18, 300 dpi) - the same pass as R497. The tesseract Table 2 read dropped rows but the grid is already pinned by R425 from the IIIF image; the descriptions prose read whole and clean.",
      "sentinel" = "THE SETTLE: the last four WSG boxes flip in the same commit; the gap report lands at 186 closed / 0 open - THE ENTIRE WILDERNESS SURVIVAL GUIDE IS PINNED; census 422 -> 423.",
    },
  "consts" = { {
      "name" = "wpdPrintedLo",
      "value" = 11,
      "comment" = "the proficiencies chapter starts at printed p. 11.",
    }, {
      "name" = "wpdPrintedHi",
      "value" = 17,
      "comment" = "the proficiencies chapter ends at printed p. 17.",
    }, {
      "name" = "wpdPdfLo",
      "value" = 12,
      "comment" = "the chapter starts at pdf page 12.",
    }, {
      "name" = "wpdPdfHi",
      "value" = 18,
      "comment" = "the chapter ends at pdf page 18.",
    }, {
      "name" = "wpdDescriptionCount",
      "value" = 25,
      "comment" = "twenty-five proficiency descriptions, alertness through weather sense - matching the twenty-five Table 2 rows pinned by R425.",
    }, {
      "name" = "wpdAlertSurpriseReductionIn6",
      "value" = 1,
      "comment" = "a successful alertness check reduces the surprise chance by 1 in 6, for the character and for any party members he can communicate with.",
    }, {
      "name" = "wpdAnimalHandlingNonprofPct",
      "value" = 20,
      "comment" = "a character without animal handling has only a 20 percent chance of calming an excited animal (the R490 seam).",
    }, {
      "name" = "wpdAnimalLoreNoInfoFailBy",
      "value" = 4,
      "comment" = "an animal lore check failed by 4 or less yields no information.",
    }, {
      "name" = "wpdAnimalLoreWrongInfoFailBy",
      "value" = 5,
      "comment" = "an animal lore check failed by 5 or more yields incorrect information.",
    }, {
      "name" = "wpdBlindTotalDarkPen",
      "value" = 2,
      "comment" = "blind-fighting: the total-darkness attack and damage penalty is only -2 (instead of -4).",
    }, {
      "name" = "wpdBlindTotalDarkBasePen",
      "value" = 4,
      "comment" = "the total-darkness penalty without blind-fighting.",
    }, {
      "name" = "wpdBlindNaturalDarkPen",
      "value" = 1,
      "comment" = "blind-fighting: the natural-darkness penalty is only -1 (instead of -3).",
    }, {
      "name" = "wpdBlindNaturalDarkBasePen",
      "value" = 3,
      "comment" = "the natural-darkness penalty without blind-fighting.",
    }, {
      "name" = "wpdDirSenseTotalDarkMod",
      "value" = 4,
      "comment" = "a direction sense check in total darkness takes a +4 modifier.",
    }, {
      "name" = "wpdDirSensePartialDarkMod",
      "value" = 2,
      "comment" = "a direction sense check in partial darkness takes a +2 modifier.",
    }, {
      "name" = "wpdDirSenseErrorDeg",
      "value" = 90,
      "comment" = "a failed direction sense check (under 20) errs by 90 degrees left or right, at the DM decision.",
    }, {
      "name" = "wpdEnduranceStrenuousMult",
      "value" = 2,
      "comment" = "endurance doubles the time of continual strenuous activity before fatigue and exhaustion apply.",
    }, {
      "name" = "wpdHealingEmergencyDie",
      "value" = 3,
      "comment" = "emergency healing restores 1d3 hit points.",
    }, {
      "name" = "wpdHealingWindowRounds",
      "value" = 1,
      "comment" = "emergency healing must begin within one round of the wound.",
    }, {
      "name" = "wpdHealingTravelHpPerDay",
      "value" = 1,
      "comment" = "continuous care restores 1 hit point per day even while traveling.",
    }, {
      "name" = "wpdHealingRestHpPerDay",
      "value" = 2,
      "comment" = "continuous care with rest restores 2 hit points per day.",
    }, {
      "name" = "wpdHealingPoisonSaveBonus",
      "value" = 2,
      "comment" = "healing aid in the poison round grants a +2 saving throw bonus versus poison.",
    }, {
      "name" = "wpdHealingPoisonRestTurns",
      "value" = 1,
      "comment" = "the poison victim must rest one full turn to keep the saving throw bonus.",
    }, {
      "name" = "wpdHealingPoisonAidRounds",
      "value" = 5,
      "comment" = "the healer must aid the poison victim for at least five rounds after the poisoning round.",
    }, {
      "name" = "wpdHealingDiseaseWindowTurns",
      "value" = 3,
      "comment" = "disease aid must begin within three turns of the onset of symptoms.",
    }, {
      "name" = "wpdHealingAidPerDay",
      "value" = 2,
      "comment" = "the diseased character needs aid from the healer twice per day at regular intervals.",
    }, {
      "name" = "wpdHealingMissRevertConsecutive",
      "value" = 2,
      "comment" = "two consecutive missed medicine sessions revert the disease to its original severity.",
    }, {
      "name" = "wpdHealingMissRevertTotal",
      "value" = 3,
      "comment" = "three total missed medicine sessions also revert the disease.",
    }, {
      "name" = "wpdHuntPartyMod1",
      "value" = 1,
      "comment" = "hunting with one extra character: +1 to the check.",
    }, {
      "name" = "wpdHuntPartyMod2",
      "value" = 3,
      "comment" = "hunting with two extra characters: +3.",
    }, {
      "name" = "wpdHuntPartyMod3",
      "value" = 6,
      "comment" = "hunting with three extra characters: +6.",
    }, {
      "name" = "wpdHuntPartyMod4",
      "value" = 10,
      "comment" = "hunting with four extra characters: +10.",
    }, {
      "name" = "wpdHuntPartyMod5",
      "value" = 15,
      "comment" = "hunting with five extra characters: +15.",
    }, {
      "name" = "wpdHuntAutoFailPartySize",
      "value" = 6,
      "comment" = "a hunting party of six or more besides the hunter fails the check automatically - no roll needed.",
    }, {
      "name" = "wpdAirborneDropMaxFt",
      "value" = 10,
      "comment" = "airborne riding: a rider can drop onto his mount from no more than 10 feet above it.",
    }, {
      "name" = "wpdAirborneSpurRateIn",
      "value" = 1,
      "comment" = "airborne riding: spurring adds 1 inch to the flying movement rate.",
    }, {
      "name" = "wpdAirborneSpurMaxTurns",
      "value" = 4,
      "comment" = "the spur lasts at most four consecutive turns.",
    }, {
      "name" = "wpdAirborneSpurFailWaitTurns",
      "value" = 3,
      "comment" = "after a failed initial spur check, no retry for at least three turns.",
    }, {
      "name" = "wpdAirborneSpurFatigueNum",
      "value" = 2,
      "comment" = "a fatigued mount slows to 2/3 of its normal maximum rate (numerator).",
    }, {
      "name" = "wpdAirborneSpurFatigueDen",
      "value" = 3,
      "comment" = "the fatigued mount fraction denominator.",
    }, {
      "name" = "wpdAirborneSpurRestTurns",
      "value" = 2,
      "comment" = "the fatigued mount must land and rest at least two turns.",
    }, {
      "name" = "wpdAirborneMCFatigueDrop",
      "value" = 1,
      "comment" = "the fatigued mount performs as if one Maneuverability Class worse.",
    }, {
      "name" = "wpdDropMeleeFt",
      "value" = 10,
      "comment" = "the hover-drop feat: leap from 10 feet or less and melee anyone within 10 feet of the landing.",
    }, {
      "name" = "wpdDropMod",
      "value" = 4,
      "comment" = "the hover-drop check takes a +4 modifier.",
    }, {
      "name" = "wpdDropFailDmgDie",
      "value" = 3,
      "comment" = "a failed hover-drop causes 1d3 points of damage.",
    }, {
      "name" = "wpdDropFailACPen",
      "value" = 4,
      "comment" = "a failed hover-drop leaves a -4 armor class penalty for the round.",
    }, {
      "name" = "wpdLandJumpNoCheckObstacleFt",
      "value" = 3,
      "comment" = "land-based riding: no check needed below a 3-foot obstacle.",
    }, {
      "name" = "wpdLandJumpNoCheckGapFt",
      "value" = 12,
      "comment" = "no check needed below a 12-foot gap.",
    }, {
      "name" = "wpdLandJumpMaxObstacleFt",
      "value" = 7,
      "comment" = "a successful check urges the mount up to 7-foot obstacles.",
    }, {
      "name" = "wpdLandJumpMaxGapFt",
      "value" = 30,
      "comment" = "a successful check clears gaps up to 30 feet wide.",
    }, {
      "name" = "wpdLandSpurRateIn",
      "value" = 1,
      "comment" = "land-based spurring adds 1 inch per round.",
    }, {
      "name" = "wpdLandSpurMaxTurns",
      "value" = 4,
      "comment" = "land-based spurring lasts up to four turns.",
    }, {
      "name" = "wpdLandSpurFailWaitTurns",
      "value" = 3,
      "comment" = "after a failed initial land spur check, no retry for three turns.",
    }, {
      "name" = "wpdLandSpurFailWalkTurns",
      "value" = 1,
      "comment" = "a failed second land spur check: the rider must dismount and lead the animal for a turn.",
    }, {
      "name" = "wpdLandKneesFailExtraDie",
      "value" = 6,
      "comment" = "failing the knees-guidance damage check causes a fall with 1d6 extra points of damage.",
    }, {
      "name" = "wpdLandShieldACSteps",
      "value" = 6,
      "comment" = "the shielded position grants 6 armor class steps (10 becomes 4, 8 becomes 2).",
    }, {
      "name" = "wpdLandDropRiseSegsLo",
      "value" = 1,
      "comment" = "a failed land hover-drop leaves the rider on the ground for 1-3 segments (low).",
    }, {
      "name" = "wpdLandDropRiseSegsHi",
      "value" = 3,
      "comment" = "the rise-segment high bound.",
    }, {
      "name" = "wpdLandDropVulnerableHitMod",
      "value" = 2,
      "comment" = "an attack on the still-grounded rider is made at +2 to hit.",
    }, {
      "name" = "wpdRopeEscapeFrontMod",
      "value" = 3,
      "comment" = "escaping rope bonds with hands tied in front: +3 to the check.",
    }, {
      "name" = "wpdRopeEscapeBehindMod",
      "value" = 6,
      "comment" = "hands tied behind the back: +6 to the check.",
    }, {
      "name" = "wpdRopeLassoHitMod",
      "value" = 2,
      "comment" = "rope use grants +2 to hit with a lasso.",
    }, {
      "name" = "wpdRopeClimbBonusPct",
      "value" = 10,
      "comment" = "rope use grants a 10 percent bonus on climbing checks with a rope.",
    }, {
      "name" = "wpdRunSprintMult",
      "value" = 2,
      "comment" = "sprinting: twice the normal maximum movement rate.",
    }, {
      "name" = "wpdRunSprintRounds",
      "value" = 5,
      "comment" = "the sprint lasts five rounds.",
    }, {
      "name" = "wpdRunSprintAltNum",
      "value" = 3,
      "comment" = "the alternative sprint: one and one-half times normal (3/2, rounded up).",
    }, {
      "name" = "wpdRunSprintAltDen",
      "value" = 2,
      "comment" = "the alternative sprint denominator.",
    }, {
      "name" = "wpdRunSprintAltTurns",
      "value" = 1,
      "comment" = "the alternative sprint lasts one turn.",
    }, {
      "name" = "wpdRunSprintExtModPerRound",
      "value" = 3,
      "comment" = "extended sprinting: each check after the first takes a cumulative +3 (+3, +6, +9...).",
    }, {
      "name" = "wpdRunStopFreshAgainTurns",
      "value" = 2,
      "comment" = "stopping a sprint before fatigue: normal rate for two turns, then sprint again.",
    }, {
      "name" = "wpdRunHalfSpeedAgainTurns",
      "value" = 1,
      "comment" = "at half the normal rate, sprint again after one turn.",
    }, {
      "name" = "wpdRunRestExampleExertTurns",
      "value" = 8,
      "comment" = "distance running: eight turns of exertion are offset by one turn of rest.",
    }, {
      "name" = "wpdRunCheckEveryTurns",
      "value" = 12,
      "comment" = "twelve turns of long-distance running require a Constitution check.",
    }, {
      "name" = "wpdRunCheckNextAfterTurns",
      "value" = 10,
      "comment" = "a successful check covers ten more turns before the next one.",
    }, {
      "name" = "wpdSurvColdEffShift",
      "value" = 20,
      "comment" = "cold survival: the effective temperature reads 20 degrees warmer.",
    }, {
      "name" = "wpdSurvColdAppliesAtOrBelow",
      "value" = 30,
      "comment" = "cold survival applies only at effective temperatures of 30 degrees or lower.",
    }, {
      "name" = "wpdSurvHeatEffShift",
      "value" = 20,
      "comment" = "heat survival: the effective temperature reads 20 degrees cooler.",
    }, {
      "name" = "wpdSurvHeatAppliesAtOrAbove",
      "value" = 80,
      "comment" = "heat survival applies only at effective temperatures of 80 degrees or higher.",
    }, {
      "name" = "wpdTrackBasePctPerLevel",
      "value" = 5,
      "comment" = "tracking: 5 percent per level of the character.",
    }, {
      "name" = "wpdTrackBaseBonusPct",
      "value" = 5,
      "comment" = "tracking: plus an additional 5 percent.",
    }, {
      "name" = "wpdTrackMaxPct",
      "value" = 55,
      "comment" = "the tracking chance caps at 55 percent - half the ranger base (the UA p. 21 seam).",
    }, {
      "name" = "wpdWeatherSenseHours",
      "value" = 6,
      "comment" = "weather sense reads the coming six hours.",
    }, {
      "name" = "wpdWeatherSenseFreePerDay",
      "value" = 1,
      "comment" = "the first weather sense attempt each day is free.",
    }, {
      "name" = "wpdWeatherSenseRepeatMod",
      "value" = 2,
      "comment" = "each attempt beyond the first takes a cumulative +2.",
    }, {
      "name" = "wpdWeatherSenseFailLockoutHours",
      "value" = 12,
      "comment" = "a failed weather sense check auto-fails every check in the next 12 hours.",
    } },
  "bools" = { {
      "name" = "wpdSystemMatchesDSG",
      "value" = true,
      "comment" = "the wilderness proficiency system is essentially the same as the Dungeoneer Survival Guide nonweapon system (the R425 seam).",
    }, {
      "name" = "wpdDualEnvironmentShared",
      "value" = true,
      "comment" = "proficiencies shared with DSG (fire-building, land-based riding) work in both underground and above-ground environments.",
    }, {
      "name" = "wpdUndergroundOnlyExists",
      "value" = true,
      "comment" = "some proficiencies are underground-only by nature: fungus identification is the DSG example.",
    }, {
      "name" = "wpdPlantLoreWildernessOnly",
      "value" = true,
      "comment" = "plant lore is useful only in the wilderness.",
    }, {
      "name" = "wpdSelectionPlayerChooses",
      "value" = true,
      "comment" = "the selection of nonweapon proficiencies is basically up to the player.",
    }, {
      "name" = "wpdBackgroundLogicRule",
      "value" = true,
      "comment" = "players should respect character background: no desert survival without desert time, no swimming skill for a desert-raised character.",
    }, {
      "name" = "wpdLevelingStillLogical",
      "value" = true,
      "comment" = "advancement selections follow the same logic: no desert survival until sizable desert time.",
    }, {
      "name" = "wpdDirectionSenseEasyJustify",
      "value" = true,
      "comment" = "direction sense is justifiable for practically any character at any time - an inborn knack or between-levels training.",
    }, {
      "name" = "wpdDMApprovalRequired",
      "value" = true,
      "comment" = "all selections are subject to DM approval; an illogical pick may - must - be disallowed.",
    }, {
      "name" = "wpdDelayAllowedNotDuringAdventure",
      "value" = true,
      "comment" = "a delayed slot fill is allowed but should never be filled during an adventure - no sudden swimming in a lake.",
    }, {
      "name" = "wpdAnimalHandlingCalmsOnCheck",
      "value" = true,
      "comment" = "a successful animal handling check calms an excited or agitated animal.",
    }, {
      "name" = "wpdBlindNoACPenalty",
      "value" = true,
      "comment" = "blind-fighting grants no armor class penalty from darkness.",
    }, {
      "name" = "wpdBlindRetainsAbilities",
      "value" = true,
      "comment" = "blind-fighting keeps special abilities and other proficiencies usable in darkness.",
    }, {
      "name" = "wpdBlindAdverseChanceHalf",
      "value" = true,
      "comment" = "blind-fighting halves the chance of stumbling, tumbling into pits or over cliffs, and slipping while climbing.",
    }, {
      "name" = "wpdBlindShortRangeOnly",
      "value" = true,
      "comment" = "blind-fighting is short-range only: no long-distance vision, tracking-scale sight excluded.",
    }, {
      "name" = "wpdBoatingFastestRate",
      "value" = true,
      "comment" = "a boating-proficient pilot moves the vessel at its fastest possible rate (the R457 seam).",
    }, {
      "name" = "wpdBoatingReducesCapsize",
      "value" = true,
      "comment" = "the boating proficiency reduces the capsize chance in rough water or high winds.",
    }, {
      "name" = "wpdCharioteerFasterRate",
      "value" = true,
      "comment" = "charioteering moves a chariot at one-third faster than the normal rate over negotiable terrain.",
    }, {
      "name" = "wpdCharioteerNoImpossibleTerrain",
      "value" = true,
      "comment" = "charioteering never moves a chariot over terrain it cannot traverse - no chariots into the mountains.",
    }, {
      "name" = "wpdDirSenseSecretRoll",
      "value" = true,
      "comment" = "the direction sense check is always rolled by the DM in secret.",
    }, {
      "name" = "wpdDirSenseNatural20Opposite",
      "value" = true,
      "comment" = "a direction sense roll of 20 means the exact opposite direction.",
    }, {
      "name" = "wpdDirSenseMultiChecker",
      "value" = true,
      "comment" = "with multiple direction-sense characters the DM checks for each; agreeing characters may both be right - or both wrong the same way.",
    }, {
      "name" = "wpdEnduranceNoFoodWaterExtension",
      "value" = true,
      "comment" = "endurance never extends the time a character can go without food or water.",
    }, {
      "name" = "wpdFireBuildNoFlintOnCheck",
      "value" = true,
      "comment" = "a successful fire-building check starts a fire without flint, steel or a tinderbox.",
    }, {
      "name" = "wpdFireBuildHalfTimeWithKit",
      "value" = true,
      "comment" = "with proper equipment the fire-building proficient character takes half the normal time.",
    }, {
      "name" = "wpdFishingBetterCatch",
      "value" = true,
      "comment" = "the fishing proficiency improves the catch - the R465 seam.",
    }, {
      "name" = "wpdForagingTwiceOrHalfTime",
      "value" = true,
      "comment" = "foraging yields twice the food in the same time, or the same food in half the time (the R463 seam).",
    }, {
      "name" = "wpdHealingCapAtWound",
      "value" = true,
      "comment" = "emergency healing never restores more than the wound caused in the preceding round.",
    }, {
      "name" = "wpdHealingOnePatientPerDay",
      "value" = true,
      "comment" = "the continuous-care benefit applies to only one character per day.",
    }, {
      "name" = "wpdHealingContinuousNoCheck",
      "value" = true,
      "comment" = "the continuous-care recovery needs no Proficiency Check, only that healer and patient share a group.",
    }, {
      "name" = "wpdHealingPoisonNoCheckNeeded",
      "value" = true,
      "comment" = "the poison saving throw bonus needs no check, only the same-round start, the one-turn rest and the five rounds of aid.",
    }, {
      "name" = "wpdHealingPoisonMissResaves",
      "value" = true,
      "comment" = "missing either time requirement forces a fresh poison saving throw with no bonus.",
    }, {
      "name" = "wpdHealingDiseaseStepDown",
      "value" = true,
      "comment" = "a successful disease check lowers the severity one step: terminal to severe, severe to mild.",
    }, {
      "name" = "wpdHealingMildHalfDuration",
      "value" = true,
      "comment" = "an already-mild disease runs its course in half the time under healing care.",
    }, {
      "name" = "wpdHuntPenaltyEvenWithProficients",
      "value" = true,
      "comment" = "the hunting party penalty applies even when the extra characters have hunting proficiency themselves.",
    }, {
      "name" = "wpdMountaineerUsesSpikes",
      "value" = true,
      "comment" = "mountaineering ascends unclimbable rock by driving spikes into cracks (the R446 seam).",
    }, {
      "name" = "wpdPlantLoreNoMisidentify",
      "value" = true,
      "comment" = "a successful plant lore check guarantees the medicinal plant is the correct sort (the R479 seam).",
    }, {
      "name" = "wpdAirbornePerCategorySelection",
      "value" = true,
      "comment" = "airborne riding is selected per flying-mount category and may be taken more than once.",
    }, {
      "name" = "wpdAirborneDropArmorBar",
      "value" = true,
      "comment" = "the airborne drop feat fails in armor heavier than leather - falling damage and a panicked mount.",
    }, {
      "name" = "wpdAirborneSameSegmentAirborneCheck",
      "value" = true,
      "comment" = "getting the mount airborne in the same segment as the landing requires a successful check.",
    }, {
      "name" = "wpdAirborneHoverDropCheck",
      "value" = true,
      "comment" = "dropping onto a hovering mount requires a successful check.",
    }, {
      "name" = "wpdAirborneSpurCheckEachTurn",
      "value" = true,
      "comment" = "the spur requires a check at the beginning of each turn.",
    }, {
      "name" = "wpdAirborneSpurFourTurnsFatigue",
      "value" = true,
      "comment" = "four consecutive successful spur turns also slow and degrade the mount until it lands and rests.",
    }, {
      "name" = "wpdAirborneKneesHandsFree",
      "value" = true,
      "comment" = "the knees-guidance feat leaves the hands free; damage forces a check.",
    }, {
      "name" = "wpdLandVaultStillNoCheck",
      "value" = true,
      "comment" = "vaulting onto a still mount needs no check, even in armor.",
    }, {
      "name" = "wpdLandVaultMovingCheck",
      "value" = true,
      "comment" = "vaulting onto a moving mount requires a check; failure is a harmless fall.",
    }, {
      "name" = "wpdLandJumpBalkOnFail",
      "value" = true,
      "comment" = "a failed jump check balks the mount, forcing a keep-your-seat check.",
    }, {
      "name" = "wpdLandSpurCheckEachTurn",
      "value" = true,
      "comment" = "the land spur requires a check at the beginning of each turn.",
    }, {
      "name" = "wpdLandSpurAfterRaceWalk",
      "value" = true,
      "comment" = "after four turns of racing the steed must be walked by its dismounted rider for a turn.",
    }, {
      "name" = "wpdLandKneesDamageCheck",
      "value" = true,
      "comment" = "knees-guidance needs a check only on taking damage; failure means a fall.",
    }, {
      "name" = "wpdLandShieldLeatherOnly",
      "value" = true,
      "comment" = "the shielded position requires armor no heavier than leather.",
    }, {
      "name" = "wpdLandShieldNoAttacks",
      "value" = true,
      "comment" = "the shielded position allows no attacks while it lasts.",
    }, {
      "name" = "wpdLandShieldMountTakesHits",
      "value" = true,
      "comment" = "attacks that would have struck the shielded rider hit the mount instead.",
    }, {
      "name" = "wpdLandShieldFullSpeed",
      "value" = true,
      "comment" = "the shielded position works even at full mount speed, with no check.",
    }, {
      "name" = "wpdRopeShelterHalfTime",
      "value" = true,
      "comment" = "rope use erects or takes down a rope shelter in half the time.",
    }, {
      "name" = "wpdRopeShelterHalfWeather",
      "value" = true,
      "comment" = "a rope-user shelter is half as likely to suffer from inclement weather.",
    }, {
      "name" = "wpdRopeClimbBonusIncludesBelay",
      "value" = true,
      "comment" = "the climbing bonus includes belaying companions (the R440/R443 seam).",
    }, {
      "name" = "wpdRunSprintEncumbranceBar",
      "value" = true,
      "comment" = "sprinting requires no encumbrance and armor no heavier than leather.",
    }, {
      "name" = "wpdRunSprintOneFailedIsFatigue",
      "value" = true,
      "comment" = "one failed extended-sprint check fatigues the character; a second failure exhausts.",
    }, {
      "name" = "wpdRunStopFatigueStays",
      "value" = true,
      "comment" = "stopping a sprint while fatigued keeps the fatigue; exhaustion forces an immediate stop.",
    }, {
      "name" = "wpdRunDistanceFatigueFavors",
      "value" = true,
      "comment" = "distance running doubles or halves every fatigue time limit in favor of the character.",
    }, {
      "name" = "wpdRunDistanceNoMidRunStrenuous",
      "value" = true,
      "comment" = "any other strenuous activity mid-run negates the distance benefits and restarts the standard clock.",
    }, {
      "name" = "wpdSurvDesertWaterHoleDoubled",
      "value" = true,
      "comment" = "desert survival doubles the daily water-hole location chance.",
    }, {
      "name" = "wpdSurvDesertForageHalfTime",
      "value" = true,
      "comment" = "desert survival locates a quantity of edible plants in half the normal time.",
    }, {
      "name" = "wpdSurvDesertConserveSupply",
      "value" = true,
      "comment" = "desert survival conserves the water supply - longer stretchs between finds, not longer without water.",
    }, {
      "name" = "wpdSwimCannotWithoutProf",
      "value" = true,
      "comment" = "a character without swimming proficiency cannot swim at all - the R450 seam.",
    }, {
      "name" = "wpdSwimHoldBreathStillWorks",
      "value" = true,
      "comment" = "the nonproficient can still hold breath and float in the right circumstances.",
    }, {
      "name" = "wpdTrackNonprofZeroBase",
      "value" = true,
      "comment" = "a nonproficient tracker has a 0 percent base chance, salvageable only by positive modifiers.",
    }, {
      "name" = "wpdWeatherSenseSecretRoll",
      "value" = true,
      "comment" = "the DM always rolls weather sense checks and need not reveal the result.",
    }, {
      "name" = "wpdWeatherSenseGeneralFact",
      "value" = true,
      "comment" = "a successful weather sense check yields at least one generally true fact about the coming six hours.",
    }, {
      "name" = "wpdWeatherSenseFailQuietOrWrong",
      "value" = true,
      "comment" = "a failed weather sense check yields nothing, or at the DM discretion something incorrect.",
    }, {
      "name" = "wpdWeatherSenseObviousNoCheck",
      "value" = true,
      "comment" = "obvious impending weather gets no check - the DM just describes what anyone can see.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the chapter spans",
      "expr" = "m['wpdPrintedLo']() != 11 or m['wpdPrintedHi']() != 17 or m['wpdPdfLo']() != 12 or m['wpdPdfHi']() != 18",
    }, {
      "note" = "twenty-five descriptions matching the twenty-five pinned Table 2 rows",
      "expr" = "m['wpdDescriptionCount']() != 25",
    }, {
      "note" = "the blind-fighting penalties are exactly half the base penalties",
      "expr" = "m['wpdBlindTotalDarkPen']() != 2 or m['wpdBlindTotalDarkBasePen']() != 4 or m['wpdBlindTotalDarkBasePen']() != m['wpdBlindTotalDarkPen']() * 2 or m['wpdBlindNaturalDarkBasePen']() != m['wpdBlindNaturalDarkPen']() * 3",
    }, {
      "note" = "the direction sense darkness ladder: +4 total, +2 partial",
      "expr" = "m['wpdDirSenseTotalDarkMod']() != 4 or m['wpdDirSensePartialDarkMod']() != 2 or m['wpdDirSenseTotalDarkMod']() != m['wpdDirSensePartialDarkMod']() * 2",
    }, {
      "note" = "the rope escape ladder: +3 front, +6 behind",
      "expr" = "m['wpdRopeEscapeFrontMod']() != 3 or m['wpdRopeEscapeBehindMod']() != 6 or m['wpdRopeEscapeBehindMod']() != m['wpdRopeEscapeFrontMod']() * 2",
    }, {
      "note" = "the hunting party ladder climbs 1, 3, 6, 10, 15",
      "expr" = "m['wpdHuntPartyMod1']() != 1 or m['wpdHuntPartyMod2']() != 3 or m['wpdHuntPartyMod3']() != 6 or m['wpdHuntPartyMod4']() != 10 or m['wpdHuntPartyMod5']() != 15",
    }, {
      "note" = "six or more companions auto-fail the hunt",
      "expr" = "m['wpdHuntAutoFailPartySize']() != 6",
    }, {
      "note" = "the survival temperature bands: cold at or below 30, heat at or above 80, both shifting 20 degrees",
      "expr" = "m['wpdSurvColdEffShift']() != 20 or m['wpdSurvHeatEffShift']() != 20 or m['wpdSurvColdAppliesAtOrBelow']() != 30 or m['wpdSurvHeatAppliesAtOrAbove']() != 80",
    }, {
      "note" = "the tracking ladder: 5 per level plus 5, capped at 55 - half a ranger",
      "expr" = "m['wpdTrackBasePctPerLevel']() != 5 or m['wpdTrackBaseBonusPct']() != 5 or m['wpdTrackMaxPct']() != 55 or m['wpdTrackMaxPct']() != m['wpdTrackBasePctPerLevel']() * 11",
    }, {
      "note" = "the weather sense day: one free try, +2 per extra try, 12-hour lockout on failure",
      "expr" = "m['wpdWeatherSenseHours']() != 6 or m['wpdWeatherSenseFreePerDay']() != 1 or m['wpdWeatherSenseRepeatMod']() != 2 or m['wpdWeatherSenseFailLockoutHours']() != 12 or m['wpdWeatherSenseFailLockoutHours']() != m['wpdWeatherSenseHours']() * 2",
    }, {
      "note" = "the healing recovery ladder: 1 traveling, 2 resting",
      "expr" = "m['wpdHealingTravelHpPerDay']() != 1 or m['wpdHealingRestHpPerDay']() != 2 or m['wpdHealingRestHpPerDay']() != m['wpdHealingTravelHpPerDay']() * 2",
    }, {
      "note" = "the healing revert rule: 2 consecutive or 3 total missed sessions",
      "expr" = "m['wpdHealingMissRevertConsecutive']() != 2 or m['wpdHealingMissRevertTotal']() != 3",
    }, {
      "note" = "the emergency healing window and die",
      "expr" = "m['wpdHealingWindowRounds']() != 1 or m['wpdHealingEmergencyDie']() != 3",
    }, {
      "note" = "the poison aid package: +2 save, 1 turn rest, 5 rounds of aid",
      "expr" = "m['wpdHealingPoisonSaveBonus']() != 2 or m['wpdHealingPoisonRestTurns']() != 1 or m['wpdHealingPoisonAidRounds']() != 5",
    }, {
      "note" = "the disease window: 3 turns, aid twice per day",
      "expr" = "m['wpdHealingDiseaseWindowTurns']() != 3 or m['wpdHealingAidPerDay']() != 2",
    }, {
      "note" = "the sprint package: 2x for 5 rounds or 3/2 for 1 turn",
      "expr" = "m['wpdRunSprintMult']() != 2 or m['wpdRunSprintRounds']() != 5 or m['wpdRunSprintAltNum']() != 3 or m['wpdRunSprintAltDen']() != 2 or m['wpdRunSprintAltTurns']() != 1",
    }, {
      "note" = "the extended sprint climbs +3 per round",
      "expr" = "m['wpdRunSprintExtModPerRound']() != 3 or m['wpdRunStopFreshAgainTurns']() != 2 or m['wpdRunHalfSpeedAgainTurns']() != 1",
    }, {
      "note" = "the distance running example: 8 exerted vs 1 rest, a check every 12 then 10 turns",
      "expr" = "m['wpdRunRestExampleExertTurns']() != 8 or m['wpdRunCheckEveryTurns']() != 12 or m['wpdRunCheckNextAfterTurns']() != 10",
    }, {
      "note" = "the airborne spur: 1 inch, 4 turns, 3-turn retry wait, 2/3 fatigue, 1 MC drop, 2 turns rest",
      "expr" = "m['wpdAirborneSpurRateIn']() != 1 or m['wpdAirborneSpurMaxTurns']() != 4 or m['wpdAirborneSpurFailWaitTurns']() != 3 or m['wpdAirborneSpurFatigueNum']() != 2 or m['wpdAirborneSpurFatigueDen']() != 3 or m['wpdAirborneMCFatigueDrop']() != 1 or m['wpdAirborneSpurRestTurns']() != 2",
    }, {
      "note" = "the hover-drop feat: 10 feet, +4, 1d3 damage, -4 AC",
      "expr" = "m['wpdDropMeleeFt']() != 10 or m['wpdDropMod']() != 4 or m['wpdDropFailDmgDie']() != 3 or m['wpdDropFailACPen']() != 4",
    }, {
      "note" = "the land jump bands: free below 3/12, maximum 7/30",
      "expr" = "m['wpdLandJumpNoCheckObstacleFt']() != 3 or m['wpdLandJumpNoCheckGapFt']() != 12 or m['wpdLandJumpMaxObstacleFt']() != 7 or m['wpdLandJumpMaxGapFt']() != 30",
    }, {
      "note" = "the land spur: 1 inch, 4 turns, 3-turn retry, 1 turn walk",
      "expr" = "m['wpdLandSpurRateIn']() != 1 or m['wpdLandSpurMaxTurns']() != 4 or m['wpdLandSpurFailWaitTurns']() != 3 or m['wpdLandSpurFailWalkTurns']() != 1",
    }, {
      "note" = "the shielded position: 6 AC steps",
      "expr" = "m['wpdLandShieldACSteps']() != 6",
    }, {
      "note" = "the failed land drop: 1-3 segments down, attacker at +2",
      "expr" = "m['wpdLandDropRiseSegsLo']() != 1 or m['wpdLandDropRiseSegsHi']() != 3 or m['wpdLandDropVulnerableHitMod']() != 2",
    }, {
      "note" = "the knees failure costs 1d6 extra",
      "expr" = "m['wpdLandKneesFailExtraDie']() != 6",
    }, {
      "note" = "the rope bonuses: +2 lasso, +10 percent climbing",
      "expr" = "m['wpdRopeLassoHitMod']() != 2 or m['wpdRopeClimbBonusPct']() != 10",
    }, {
      "note" = "the animal lore failure split: 4 or less silent, 5 or more wrong",
      "expr" = "m['wpdAnimalLoreNoInfoFailBy']() != 4 or m['wpdAnimalLoreWrongInfoFailBy']() != 5 or m['wpdAnimalLoreWrongInfoFailBy']() != m['wpdAnimalLoreNoInfoFailBy']() + 1",
    }, {
      "note" = "the alertness reduction: 1 in 6",
      "expr" = "m['wpdAlertSurpriseReductionIn6']() != 1",
    }, {
      "note" = "the animal handling nonproficient chance: 20 percent",
      "expr" = "m['wpdAnimalHandlingNonprofPct']() != 20",
    }, {
      "note" = "endurance doubles the strenuous clock only",
      "expr" = "m['wpdEnduranceStrenuousMult']() != 2",
    }, {
      "note" = "the airborne drop ceiling: 10 feet",
      "expr" = "m['wpdAirborneDropMaxFt']() != 10",
    }, {
      "note" = "wpdSystemMatchesDSG",
      "expr" = "m['wpdSystemMatchesDSG']() != 1",
    }, {
      "note" = "wpdDualEnvironmentShared",
      "expr" = "m['wpdDualEnvironmentShared']() != 1",
    }, {
      "note" = "wpdUndergroundOnlyExists",
      "expr" = "m['wpdUndergroundOnlyExists']() != 1",
    }, {
      "note" = "wpdPlantLoreWildernessOnly",
      "expr" = "m['wpdPlantLoreWildernessOnly']() != 1",
    }, {
      "note" = "wpdSelectionPlayerChooses",
      "expr" = "m['wpdSelectionPlayerChooses']() != 1",
    }, {
      "note" = "wpdBackgroundLogicRule",
      "expr" = "m['wpdBackgroundLogicRule']() != 1",
    }, {
      "note" = "wpdLevelingStillLogical",
      "expr" = "m['wpdLevelingStillLogical']() != 1",
    }, {
      "note" = "wpdDirectionSenseEasyJustify",
      "expr" = "m['wpdDirectionSenseEasyJustify']() != 1",
    }, {
      "note" = "wpdDMApprovalRequired",
      "expr" = "m['wpdDMApprovalRequired']() != 1",
    }, {
      "note" = "wpdDelayAllowedNotDuringAdventure",
      "expr" = "m['wpdDelayAllowedNotDuringAdventure']() != 1",
    }, {
      "note" = "wpdAnimalHandlingCalmsOnCheck",
      "expr" = "m['wpdAnimalHandlingCalmsOnCheck']() != 1",
    }, {
      "note" = "wpdBlindNoACPenalty",
      "expr" = "m['wpdBlindNoACPenalty']() != 1",
    }, {
      "note" = "wpdBlindRetainsAbilities",
      "expr" = "m['wpdBlindRetainsAbilities']() != 1",
    }, {
      "note" = "wpdBlindAdverseChanceHalf",
      "expr" = "m['wpdBlindAdverseChanceHalf']() != 1",
    }, {
      "note" = "wpdBlindShortRangeOnly",
      "expr" = "m['wpdBlindShortRangeOnly']() != 1",
    }, {
      "note" = "wpdBoatingFastestRate",
      "expr" = "m['wpdBoatingFastestRate']() != 1",
    }, {
      "note" = "wpdBoatingReducesCapsize",
      "expr" = "m['wpdBoatingReducesCapsize']() != 1",
    }, {
      "note" = "wpdCharioteerFasterRate",
      "expr" = "m['wpdCharioteerFasterRate']() != 1",
    }, {
      "note" = "wpdCharioteerNoImpossibleTerrain",
      "expr" = "m['wpdCharioteerNoImpossibleTerrain']() != 1",
    }, {
      "note" = "wpdDirSenseSecretRoll",
      "expr" = "m['wpdDirSenseSecretRoll']() != 1",
    }, {
      "note" = "wpdDirSenseNatural20Opposite",
      "expr" = "m['wpdDirSenseNatural20Opposite']() != 1",
    }, {
      "note" = "wpdDirSenseMultiChecker",
      "expr" = "m['wpdDirSenseMultiChecker']() != 1",
    }, {
      "note" = "wpdEnduranceNoFoodWaterExtension",
      "expr" = "m['wpdEnduranceNoFoodWaterExtension']() != 1",
    }, {
      "note" = "wpdFireBuildNoFlintOnCheck",
      "expr" = "m['wpdFireBuildNoFlintOnCheck']() != 1",
    }, {
      "note" = "wpdFireBuildHalfTimeWithKit",
      "expr" = "m['wpdFireBuildHalfTimeWithKit']() != 1",
    }, {
      "note" = "wpdFishingBetterCatch",
      "expr" = "m['wpdFishingBetterCatch']() != 1",
    }, {
      "note" = "wpdForagingTwiceOrHalfTime",
      "expr" = "m['wpdForagingTwiceOrHalfTime']() != 1",
    }, {
      "note" = "wpdHealingCapAtWound",
      "expr" = "m['wpdHealingCapAtWound']() != 1",
    }, {
      "note" = "wpdHealingOnePatientPerDay",
      "expr" = "m['wpdHealingOnePatientPerDay']() != 1",
    }, {
      "note" = "wpdHealingContinuousNoCheck",
      "expr" = "m['wpdHealingContinuousNoCheck']() != 1",
    }, {
      "note" = "wpdHealingPoisonNoCheckNeeded",
      "expr" = "m['wpdHealingPoisonNoCheckNeeded']() != 1",
    }, {
      "note" = "wpdHealingPoisonMissResaves",
      "expr" = "m['wpdHealingPoisonMissResaves']() != 1",
    }, {
      "note" = "wpdHealingDiseaseStepDown",
      "expr" = "m['wpdHealingDiseaseStepDown']() != 1",
    }, {
      "note" = "wpdHealingMildHalfDuration",
      "expr" = "m['wpdHealingMildHalfDuration']() != 1",
    }, {
      "note" = "wpdHuntPenaltyEvenWithProficients",
      "expr" = "m['wpdHuntPenaltyEvenWithProficients']() != 1",
    }, {
      "note" = "wpdMountaineerUsesSpikes",
      "expr" = "m['wpdMountaineerUsesSpikes']() != 1",
    }, {
      "note" = "wpdPlantLoreNoMisidentify",
      "expr" = "m['wpdPlantLoreNoMisidentify']() != 1",
    }, {
      "note" = "wpdAirbornePerCategorySelection",
      "expr" = "m['wpdAirbornePerCategorySelection']() != 1",
    }, {
      "note" = "wpdAirborneDropArmorBar",
      "expr" = "m['wpdAirborneDropArmorBar']() != 1",
    }, {
      "note" = "wpdAirborneSameSegmentAirborneCheck",
      "expr" = "m['wpdAirborneSameSegmentAirborneCheck']() != 1",
    }, {
      "note" = "wpdAirborneHoverDropCheck",
      "expr" = "m['wpdAirborneHoverDropCheck']() != 1",
    }, {
      "note" = "wpdAirborneSpurCheckEachTurn",
      "expr" = "m['wpdAirborneSpurCheckEachTurn']() != 1",
    }, {
      "note" = "wpdAirborneSpurFourTurnsFatigue",
      "expr" = "m['wpdAirborneSpurFourTurnsFatigue']() != 1",
    }, {
      "note" = "wpdAirborneKneesHandsFree",
      "expr" = "m['wpdAirborneKneesHandsFree']() != 1",
    }, {
      "note" = "wpdLandVaultStillNoCheck",
      "expr" = "m['wpdLandVaultStillNoCheck']() != 1",
    }, {
      "note" = "wpdLandVaultMovingCheck",
      "expr" = "m['wpdLandVaultMovingCheck']() != 1",
    }, {
      "note" = "wpdLandJumpBalkOnFail",
      "expr" = "m['wpdLandJumpBalkOnFail']() != 1",
    }, {
      "note" = "wpdLandSpurCheckEachTurn",
      "expr" = "m['wpdLandSpurCheckEachTurn']() != 1",
    }, {
      "note" = "wpdLandSpurAfterRaceWalk",
      "expr" = "m['wpdLandSpurAfterRaceWalk']() != 1",
    }, {
      "note" = "wpdLandKneesDamageCheck",
      "expr" = "m['wpdLandKneesDamageCheck']() != 1",
    }, {
      "note" = "wpdLandShieldLeatherOnly",
      "expr" = "m['wpdLandShieldLeatherOnly']() != 1",
    }, {
      "note" = "wpdLandShieldNoAttacks",
      "expr" = "m['wpdLandShieldNoAttacks']() != 1",
    }, {
      "note" = "wpdLandShieldMountTakesHits",
      "expr" = "m['wpdLandShieldMountTakesHits']() != 1",
    }, {
      "note" = "wpdLandShieldFullSpeed",
      "expr" = "m['wpdLandShieldFullSpeed']() != 1",
    }, {
      "note" = "wpdRopeShelterHalfTime",
      "expr" = "m['wpdRopeShelterHalfTime']() != 1",
    }, {
      "note" = "wpdRopeShelterHalfWeather",
      "expr" = "m['wpdRopeShelterHalfWeather']() != 1",
    }, {
      "note" = "wpdRopeClimbBonusIncludesBelay",
      "expr" = "m['wpdRopeClimbBonusIncludesBelay']() != 1",
    }, {
      "note" = "wpdRunSprintEncumbranceBar",
      "expr" = "m['wpdRunSprintEncumbranceBar']() != 1",
    }, {
      "note" = "wpdRunSprintOneFailedIsFatigue",
      "expr" = "m['wpdRunSprintOneFailedIsFatigue']() != 1",
    }, {
      "note" = "wpdRunStopFatigueStays",
      "expr" = "m['wpdRunStopFatigueStays']() != 1",
    }, {
      "note" = "wpdRunDistanceFatigueFavors",
      "expr" = "m['wpdRunDistanceFatigueFavors']() != 1",
    }, {
      "note" = "wpdRunDistanceNoMidRunStrenuous",
      "expr" = "m['wpdRunDistanceNoMidRunStrenuous']() != 1",
    }, {
      "note" = "wpdSurvDesertWaterHoleDoubled",
      "expr" = "m['wpdSurvDesertWaterHoleDoubled']() != 1",
    }, {
      "note" = "wpdSurvDesertForageHalfTime",
      "expr" = "m['wpdSurvDesertForageHalfTime']() != 1",
    }, {
      "note" = "wpdSurvDesertConserveSupply",
      "expr" = "m['wpdSurvDesertConserveSupply']() != 1",
    }, {
      "note" = "wpdSwimCannotWithoutProf",
      "expr" = "m['wpdSwimCannotWithoutProf']() != 1",
    }, {
      "note" = "wpdSwimHoldBreathStillWorks",
      "expr" = "m['wpdSwimHoldBreathStillWorks']() != 1",
    }, {
      "note" = "wpdTrackNonprofZeroBase",
      "expr" = "m['wpdTrackNonprofZeroBase']() != 1",
    }, {
      "note" = "wpdWeatherSenseSecretRoll",
      "expr" = "m['wpdWeatherSenseSecretRoll']() != 1",
    }, {
      "note" = "wpdWeatherSenseGeneralFact",
      "expr" = "m['wpdWeatherSenseGeneralFact']() != 1",
    }, {
      "note" = "wpdWeatherSenseFailQuietOrWrong",
      "expr" = "m['wpdWeatherSenseFailQuietOrWrong']() != 1",
    }, {
      "note" = "wpdWeatherSenseObviousNoCheck",
      "expr" = "m['wpdWeatherSenseObviousNoCheck']() != 1",
    } },
  "audit" = {
      "label" = "R498 WSG proficiencies prose audit",
      "comment" = "The wilderness proficiencies prose, printed pp. 11-17 (pdf 12-18): the DSG-system frame with the dual-environment ruling, the choosing-skills rules (the player chooses, the background logic, the DM approval) and all twenty-five descriptions - alertness (1-in-6 surprise), animal handling (20 percent nonproficient), animal lore (the 4-or-less/5-or-more failure split), blind-fighting (the halved penalties), boating, charioteering, direction sense (+4/+2 darkness, the 90-degree error), endurance, fire-building, fishing, foraging, healing (the emergency 1d3, the poison +2 package, the disease step-down), hunting (the party ladder 1/3/6/10/15), mountaineering, plant lore, the riding feats (airborne and land-based), rope use (+3/+6 escape), running (the sprint and distance packages), the survival trio (the 20-degree shifts), swimming, tracking (5 per level plus 5, capped 55) and weather sense (the six-hour read).",
    },
}
