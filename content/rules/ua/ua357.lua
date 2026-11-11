-- ua357: promoted from rules/ua/uamuspells2.h (the The UA NEW MAGIC-USER SPELLS (pp. 51-52) pins, R357: the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 357,
  "prefix" = "ua357",
  "banner" = {
      "title" = "The UA NEW MAGIC-USER SPELLS (pp. 51-52) pins, R357: the",
      "provenance" = "2nd-level spell descriptions - bind, deeppockets, flaming sphere, irritation, know alignment, the Melf acid arrow, preserve, protection from cantrips, the Tasha laughter, vocalize, whip and zephyr.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the digit-garble family (the R343 precedent): the casting-time and duration 7s decode as 1 - the deeppockets \"7 turn\" as 1 turn; the know alignment \"7 round\" and \"7 round/level\" as 1 round and 1 round per level; the vocalize \"7 round\" as 1 round; the zephyr \"7 segment\" as 1 segment; the flaming sphere \"7\\\"\" range as 1 inch, corroborated by the prose (the globe appears up to 1\" distant). - the deeppockets name header is lost entirely - no header line prints between the bind tail and the scrambled stat block; the name pins as Deeppockets from the gap item list and the prose (\"The deeppockets spell then makes...\"). - the protection from cantrips header prints only \"From Cantrips\" - the \"Protection\" head is lost; the name pins from the gap item list. - the whip level cell is lost in the interleave; the spell pins as 2nd level from the section heading. - the preserve area-of-effect cell loses its leading number - only \"cu. ft. per level of caster\" pins; a hole pending the PDF. - the know alignment range cell prints empty and the components cell truncates at \"V,\" - holes; the spell is reversible and same as the 2nd-level clerical (a PHB spell - no UA pin to seam-check). - the zephyr casting-time cell prints \"2\" with the unit lost (the whip block prints the split \"2\" + \"segments\"); the 2 pins, decoded as segments with doubt pending the PDF. The zephyr area path length prints a garbled fraction - flagged pending the PDF. - the degree-mark family: the foot marks print as degrees - the bind \"50 degrees\" as 50 feet and 5 feet per level; the flaming sphere barrier as 4 feet; the Melf range \"3 degrees\" as 3 inches; the Tasha range \"5 degrees\" as 5 inches. - the deeppockets components cell garbles: \"V, S [section-mark], M\" - the mark decodes as S. - interleave garbles pinned verbatim with flags: the bind \"as atrip line\" [sic]; the flaming sphere \"atarate of save\" sequence; the preserve \"il effectual sled\" opener; the protection \"creatures that trip she\" sequence; the vocalize \"speli(s)\" [sic]; the whip split casting cell. - the R342 table seam: the MU 2nd-level table prints 30 names - eight of the twelve new spells appear there (bind, irritation, know alignment, the Melf arrow, preserve, the Tasha laughter, whip, zephyr); deeppockets, flaming sphere, protection from cantrips and vocalize do not.  OCR holes (the item stays open - the 3rd through 9th levels pin in later rounds; these stay pending the PDF): the preserve area number; the know alignment range; the zephyr casting unit and path fraction; the four absent table names.",
    },
  "consts" = { {
      "name" = "uam2BindName",
      "value" = "Bind (Alteration/Enchantment)",
      "comment" = "---- bind (Alteration/Enchantment), p. 51 ----",
    }, {
      "name" = "uam2BindLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2BindRangeInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam2BindDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam2BindCastingTimeSegments",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2BindBaseFeet",
      "value" = 50,
      "comment" = "About 50 feet of normal 1-inch-diameter rope, plus 5 feet per level of the caster (the degree-mark family).",
    }, {
      "name" = "uam2BindFeetPerLevel",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uam2BindHalvingBonusPct",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uam2BindRespondWithinFeet",
      "value" = 1,
      "comment" = "The rope must be within about 1 foot of any object to respond - it must usually be thrown or hurled nearby.",
    }, {
      "name" = "uam2BindSlashingDamageToBreak",
      "value" = 2,
      "comment" = "The rope takes 2 points of slashing damage before breaking.",
    }, {
      "name" = "uam2DeeppocketsName",
      "value" = "Deeppockets",
      "comment" = "---- deeppockets, p. 51 ---- The name header is lost entirely; the name pins from the gap item list and the prose.",
    }, {
      "name" = "uam2DeeppocketsLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsCastingTimeTurns",
      "value" = 1,
      "comment" = "The casting time prints \"7 turn\" - the family decodes 1 turn.",
    }, {
      "name" = "uam2DeeppocketsDurationTurnsBase",
      "value" = 24,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsDurationTurnsPerLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsGarmentMinGp",
      "value" = 300,
      "comment" = "The garment: finely sewn, high-quality material of at least 300 gp value; one dozen pockets minimum.",
    }, {
      "name" = "uam2DeeppocketsMinPockets",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsSpecialPocketGp",
      "value" = 1000,
      "comment" = "One pocket holds 1,000 gp of weight (5 cubic feet) as if only 100 gp, with no discernible bulge.",
    }, {
      "name" = "uam2DeeppocketsSpecialPocketCuFt",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsAsIfGp",
      "value" = 100,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsAltPocketCount",
      "value" = 10,
      "comment" = "The alternative: 10 pockets of 100 gp weight each, 1 cubic foot each (the leading 1 lost in the cell).",
    }, {
      "name" = "uam2DeeppocketsAltPocketGp",
      "value" = 100,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsHundredPocketGarmentGp",
      "value" = 1000,
      "comment" = "The 100-pocket garment (1,000 gp minimum cost): 100 pockets of 10 gp weight each, a fraction of a cubic foot each (the fraction garbles).",
    }, {
      "name" = "uam2DeeppocketsHundredPocketCount",
      "value" = 100,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsHundredPocketGp",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereName",
      "value" = "Flaming Sphere (Alteration/Evocation)",
      "comment" = "---- flaming sphere (Alteration/Evocation), p. 51 ----",
    }, {
      "name" = "uam2FlamingSphereLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereRangeInches",
      "value" = 1,
      "comment" = "The range cell prints \"7\\\"\" - the family decodes 1 inch, corroborated by the prose (up to 1\" distant).",
    }, {
      "name" = "uam2FlamingSphereCastingTimeSegments",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereDiameterFeet",
      "value" = 6,
      "comment" = "The area of effect: a 6-foot diameter sphere.",
    }, {
      "name" = "uam2FlamingSphereAppearsWithinInches",
      "value" = 1,
      "comment" = "A burning globe of normal-type fire comes into being up to 1 inch distant from the caster.",
    }, {
      "name" = "uam2FlamingSphereBarrierMaxFeet",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereDamageMin",
      "value" = 2,
      "comment" = "Creatures struck suffer 2-8 fire damage; the sphere moves at 1 inch per round as long as the caster points (the interleave garble decoded).",
    }, {
      "name" = "uam2FlamingSphereDamageMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereMoveInchesPerRound",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereBlastRadiusFeet",
      "value" = 5,
      "comment" = "All creatures within a 5-foot radius of the center save versus spell or take the damage; success negates.",
    }, {
      "name" = "uam2IrritationName",
      "value" = "Irritation (Alteration)",
      "comment" = "---- irritation (Alteration), p. 51 ----",
    }, {
      "name" = "uam2IrritationLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2IrritationRangeInchesPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam2IrritationCastingTimeSegments",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2IrritationScratchSegmentsMin",
      "value" = 5,
      "comment" = "Itching: an instant itching sensation; if 5-8 segments are not immediately spent scratching, the next 3 rounds squirm - armor class worse by 4, to-hit by 2; spells ruined the initial round only.",
    }, {
      "name" = "uam2IrritationScratchSegmentsMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam2IrritationSquirmRounds",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam2IrritationAcWorseBy",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam2IrritationToHitWorseBy",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2IrritationRashLatencyMinRounds",
      "value" = 1,
      "comment" = "Rash: nothing for 1-4 rounds, then red welts faintly itching; persists until cure disease or dispel magic; comeliness -1 per day to a maximum of 4, dexterity -1 after one week; symptoms vanish on removal.",
    }, {
      "name" = "uam2IrritationRashLatencyMaxRounds",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam2IrritationRashComelinessPerDay",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam2IrritationRashComelinessMaxLoss",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam2IrritationRashDexLossAfterWeek",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam2KnowAlignmentName",
      "value" = "Know Alignment (Divination)",
      "comment" = "---- know alignment (Divination), reversible, p. 51 ----",
    }, {
      "name" = "uam2KnowAlignmentLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2KnowAlignmentCastingTimeRounds",
      "value" = 1,
      "comment" = "The casting time prints \"7 round\" - the family decodes 1 round.",
    }, {
      "name" = "uam2KnowAlignmentDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"7 round/level\" - the family decodes 1 round per level.",
    }, {
      "name" = "uam2KnowAlignmentAoeCreaturesPer2Rounds",
      "value" = 1,
      "comment" = "One creature per 2 rounds may be scried.",
    }, {
      "name" = "uam2AcidArrowName",
      "value" = "Melf's Acid Arrow (Evocation)",
      "comment" = "---- Melf's acid arrow (Evocation), p. 51 ----",
    }, {
      "name" = "uam2AcidArrowLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowRangeInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowCastingTimeSegments",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowPlusForHit",
      "value" = 1,
      "comment" = "The arrow equals a +1 weapon for hit determination.",
    }, {
      "name" = "uam2AcidArrowDamageMin",
      "value" = 2,
      "comment" = "The arrow itself does 2-5 points of damage.",
    }, {
      "name" = "uam2AcidArrowDamageMax",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowAcidVolumeOunces",
      "value" = 8,
      "comment" = "The gushing acid: an 8-ounce volume, 2-8 hit points damage, plus item saving throw; splash does not apply.",
    }, {
      "name" = "uam2AcidArrowAcidDamageMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowAcidDamageMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowExtraRoundsPer3Levels",
      "value" = 1,
      "comment" = "The acid strength increases by one round of damage per 3 levels above the 3rd - two rounds of damage from a 4th-6th level caster, unless neutralized.",
    }, {
      "name" = "uam2AcidArrowExtraRoundsFromLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam2PreserveName",
      "value" = "Preserve (Abjuration)",
      "comment" = "---- preserve (Abjuration), p. 51 ----",
    }, {
      "name" = "uam2PreserveLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2PreserveCastingTimeRounds",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2PreserveHardDryMinLevel",
      "value" = 2,
      "comment" = "The material ladder by caster level: hard, dry material 2nd-4th; soft, wet material 5th-7th; semi-liquid and liquid 8th and up.",
    }, {
      "name" = "uam2PreserveHardDryMaxLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam2PreserveSoftWetMinLevel",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uam2PreserveSoftWetMaxLevel",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uam2PreserveLiquidMinLevel",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam2PfcName",
      "value" = "Protection From Cantrips",
      "comment" = "---- protection from cantrips, p. 52 ---- The header prints only \"From Cantrips\" - the Protection head is lost; the name pins from the gap item list.",
    }, {
      "name" = "uam2PfcLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2PfcCastingTimeSegments",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2PfcDurationDaysPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam2TashaName",
      "value" = "Tasha's Uncontrollable Hideous Laughter (Evocation)",
      "comment" = "---- Tasha's hideous laughter (Evocation), p. 52 ----",
    }, {
      "name" = "uam2TashaLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2TashaCastingTimeSegments",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2TashaRangeInches",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uam2TashaDurationRounds",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam2TashaMinusTwoRounds",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2TashaPenaltyRounds",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2TashaUnaffectedIntMax",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam2TashaInt4to8SaveMod",
      "value" = -6,
      "comment" = "",
    }, {
      "name" = "uam2TashaInt9to12SaveMod",
      "value" = -4,
      "comment" = "",
    }, {
      "name" = "uam2TashaInt13to15SaveMod",
      "value" = -2,
      "comment" = "",
    }, {
      "name" = "uam2VocalizeName",
      "value" = "Vocalize (Alteration)",
      "comment" = "---- vocalize (Alteration), p. 52 ----",
    }, {
      "name" = "uam2VocalizeLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2VocalizeCastingTimeRounds",
      "value" = 1,
      "comment" = "The casting time prints \"7 round\" - the family decodes 1 round.",
    }, {
      "name" = "uam2VocalizeDurationRounds",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uam2WhipName",
      "value" = "Whip (Evocation)",
      "comment" = "---- whip (Evocation), p. 52 ----",
    }, {
      "name" = "uam2WhipLevel",
      "value" = 2,
      "comment" = "The level cell is lost in the interleave; the spell pins as 2nd level from the section heading.",
    }, {
      "name" = "uam2WhipDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam2WhipCastingTimeSegments",
      "value" = 2,
      "comment" = "The casting cell prints \"2\" and \"segments\" on split lines - the interleave decoded.",
    }, {
      "name" = "uam2WhipReachInches",
      "value" = 1,
      "comment" = "The caster creates a material whip-like substance up to 1 inch distant, wielded by moving the hand as if holding an actual whip.",
    }, {
      "name" = "uam2WhipAnimalSaveModMin",
      "value" = -1,
      "comment" = "A struck animal (normal hit die roll) saves versus spell at -1 to -4 or slinks away, not returning for at least an hour; the whip does no actual damage.",
    }, {
      "name" = "uam2WhipAnimalSaveModMax",
      "value" = -4,
      "comment" = "",
    }, {
      "name" = "uam2WhipSlinkAwayHours",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam2WhipUnaffectedIntAbove",
      "value" = 3,
      "comment" = "Creatures of intelligence above 3 are unaffected, nor giant-sized animals above bear-size, nor monsters.",
    }, {
      "name" = "uam2WhipEdgedSaveVsCrushingBlow",
      "value" = 13,
      "comment" = "",
    }, {
      "name" = "uam2WhipNonEdgedSaveVsNormalBlow",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uam2WhipWeaponRecoverRounds",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam2ZephyrName",
      "value" = "Zephyr (Evocation)",
      "comment" = "---- zephyr (Evocation), p. 52 ----",
    }, {
      "name" = "uam2ZephyrLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam2ZephyrRangeZero",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uam2ZephyrCastingTimeSegments",
      "value" = 2,
      "comment" = "The casting cell prints \"2\" with the unit lost - a hole; decoded as segments with doubt pending the PDF.",
    }, {
      "name" = "uam2ZephyrDurationSegments",
      "value" = 1,
      "comment" = "The duration prints \"7 segment\" - the family decodes 1 segment.",
    }, {
      "name" = "uam2ZephyrFanDamageBonus",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam2ZephyrHoldVaporsRounds",
      "value" = 1,
      "comment" = "It holds back moving clouds of vapors (such as a cloudkill) for 1 round.",
    }, {
      "name" = "uam2ZephyrMoveGasesBackInches",
      "value" = 1,
      "comment" = "It moves stagnant air, vapors, or poisonous gases backwards by 1 inch, halving duration and potency, unless renewed by some source.",
    } },
  "bools" = { {
      "name" = "uam2BindAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2BindComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2BindSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2BindRopelikeNonLiving",
      "value" = true,
      "comment" = "Any ropelike object of non-living material - string, yarn, cord, line, rope, or even a cable.",
    }, {
      "name" = "uam2BindBehavesAsOrdered",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2BindReduceWithDiameter",
      "value" = true,
      "comment" = "Reduce length proportionately when diameter increases; increase by 50 percent when halved.",
    }, {
      "name" = "uam2BindCommandsCoilLoopTie",
      "value" = true,
      "comment" = "The commands: Coil, Coil & Knot, Loop, Loop & Knot, Tie & Knot, and the reverses of all of the above.",
    }, {
      "name" = "uam2BindReversesAvailable",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2BindUsuallyThrown",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2BindCreatureHoldOverrides",
      "value" = true,
      "comment" = "A creature affected by the object interacts with it as normal; the creature hold overrides the dweomer.",
    }, {
      "name" = "uam2BindNoGarrotUse",
      "value" = true,
      "comment" = "No garrot use; a trip line [sic] or an entangle as the druid spell against a single opponent.",
    }, {
      "name" = "uam2BindTripLineOrEntangle",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2BindNoMagicBeyondCommands",
      "value" = true,
      "comment" = "The dweomer grants no magic beyond obeying commands (cf. rope of climbing, rope of entanglement).",
    }, {
      "name" = "uam2DeeppocketsNameHeaderLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsComponentsGarbled",
      "value" = true,
      "comment" = "The components cell garbles: \"V, [section], M\" - the mark decodes as S.",
    }, {
      "name" = "uam2DeeppocketsRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsAoeOneGarment",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsNoBulge",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsAltVolumeNumberLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsHundredPocketFractionGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsExpirySaveVsSpell",
      "value" = true,
      "comment" = "On expiry with material inside, or on dispel: the wearer saves versus spell; failure sends the material from extra-dimensional to astral space - lost forever; success drops it around the wearer, suddenly and totally, to the ground.",
    }, {
      "name" = "uam2DeeppocketsFailAstralLostForever",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsSuccessAppearsAndFalls",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2DeeppocketsMaterialGoldenNeedle",
      "value" = true,
      "comment" = "The materials: a tiny golden needle and a strip of fine cloth given a half-twist and fastened at the ends.",
    }, {
      "name" = "uam2DeeppocketsMaterialClothHalfTwist",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereRangeGarbleDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereSaveNegates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereRollsAsPointed",
      "value" = true,
      "comment" = "The sphere rolls in the pointed direction, even uphill, rolling over low barriers not over 4 feet tall.",
    }, {
      "name" = "uam2FlamingSphereSetsFlammablesAfire",
      "value" = true,
      "comment" = "Flammable substances are set afire by contact.",
    }, {
      "name" = "uam2FlamingSphereInterleaveGarbleDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereRestsUnpointed",
      "value" = true,
      "comment" = "Otherwise the sphere merely stays at rest and flames; it is extinguished as any normal fire of its size.",
    }, {
      "name" = "uam2FlamingSphereExtinguishedAsNormalFire",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereMaterialTallow",
      "value" = true,
      "comment" = "The materials: a bit of tallow, a pinch of sulphur, and a dusting of powdered iron.",
    }, {
      "name" = "uam2FlamingSphereMaterialSulphur",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2FlamingSphereMaterialPowderedIron",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2IrritationSaveNegates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2IrritationDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2IrritationAoeOneCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2IrritationComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2IrritationAffectsEpidermis",
      "value" = true,
      "comment" = "The spell affects the epidermis; very thick or insensitive skins (buffalo, elephants, scaled creatures) are basically unaffected.",
    }, {
      "name" = "uam2IrritationThickSkinnedUnaffected",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2IrritationTwoVersions",
      "value" = true,
      "comment" = "Two versions cast from the standard preparation.",
    }, {
      "name" = "uam2IrritationSpellsRuinedFirstRoundOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2IrritationRashPersistsUntilCureOrDispel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2IrritationRashVanishesOnRemoval",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2IrritationMaterialPoisonLeaf",
      "value" = true,
      "comment" = "The material: powdered leaf from poison ivy, oak, or sumac.",
    }, {
      "name" = "uam2KnowAlignmentReversible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2KnowAlignmentComponentsCellLost",
      "value" = true,
      "comment" = "The components cell truncates at \"V,\" - a hole.",
    }, {
      "name" = "uam2KnowAlignmentRangeCellLost",
      "value" = true,
      "comment" = "The range cell prints empty - a hole.",
    }, {
      "name" = "uam2KnowAlignmentSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2KnowAlignmentSameAsClerical",
      "value" = true,
      "comment" = "Except as noted, the spell is the same as the 2nd-level clerical spell of the same name (a PHB spell - no UA pin to seam-check).",
    }, {
      "name" = "uam2KnowAlignmentOneRoundEthicOnly",
      "value" = true,
      "comment" = "A target scried for only one round reveals only its alignment ethic (law/chaos).",
    }, {
      "name" = "uam2AcidArrowDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowAoeOneTarget",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowSpeedsAsFighterBow",
      "value" = true,
      "comment" = "The arrow speeds to its target as if fired from the bow of a fighter of the caster level.",
    }, {
      "name" = "uam2AcidArrowAcidBypassesPlusOneImmunity",
      "value" = true,
      "comment" = "A hit may damage even a target not normally harmed by a +1 weapon - the acid.",
    }, {
      "name" = "uam2AcidArrowItemSavingThrowApplies",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowNoSplash",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowNeutralizationStops",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowMaterialDart",
      "value" = true,
      "comment" = "The materials: a dart, powdered rhubarb leaf, and an adder stomach.",
    }, {
      "name" = "uam2AcidArrowMaterialRhubarbLeaf",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2AcidArrowMaterialAdderStomach",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PreserveRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PreserveSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PreserveDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PreserveAoeNumberLost",
      "value" = true,
      "comment" = "The area cell loses its leading number - only cubic feet per level pins; a hole pending the PDF.",
    }, {
      "name" = "uam2PreserveAoeCuFtPerLevel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PreserveComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PreserveRetainsItemFresh",
      "value" = true,
      "comment" = "The spell retains an item fresh and whole until needed in a spell; the heavily garbled opener decodes as ineffective for materials such as mistletoe and holly berries, which must be gathered periodically.",
    }, {
      "name" = "uam2PreserveIneffectiveForFreshGather",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PreserveOpenerGarbleDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PreserveContainerOnlyForMoisture",
      "value" = true,
      "comment" = "A container is necessary only where a high degree of moisture is involved.",
    }, {
      "name" = "uam2PreserveMaterialDust",
      "value" = true,
      "comment" = "The materials: a pinch of dust, a bit of resin (or amber), and a drop of brandy.",
    }, {
      "name" = "uam2PreserveMaterialResinOrAmber",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PreserveMaterialBrandy",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PfcNameHeaderGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PfcRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PfcSaveNoneOrNegates",
      "value" = true,
      "comment" = "The save cell prints \"None or Neg.\"",
    }, {
      "name" = "uam2PfcAoeOneCreatureOrObject",
      "value" = true,
      "comment" = "The area of effect: one creature or object; the components cell truncates at \"V,\" - a hole.",
    }, {
      "name" = "uam2PfcComponentsCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PfcImmunityToCantrips",
      "value" = true,
      "comment" = "The spell grants immunity to cantrips cast by other magic-users or creatures; the protection prose interleaves (the \"creatures that trip she\" garble).",
    }, {
      "name" = "uam2PfcProseInterleaveDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2PfcProtectsCasterOrItem",
      "value" = true,
      "comment" = "It protects the caster, or one item or person - a spell book or a drawer of spell components.",
    }, {
      "name" = "uam2PfcCantripDissipatesWithPop",
      "value" = true,
      "comment" = "Any cantrip cast against the protected person or item dissipates with an audible popping sound.",
    }, {
      "name" = "uam2PfcMischievousApprenticesUse",
      "value" = true,
      "comment" = "The classic use: a magic-user with mischievous apprentices, who must clean or shine with elbow grease instead of magic.",
    }, {
      "name" = "uam2PfcUnwillingToHitAndSave",
      "value" = true,
      "comment" = "An unwilling target must be touched via a to-hit roll and is allowed a save versus spell to escape.",
    }, {
      "name" = "uam2TashaSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2TashaAoeOneCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2TashaComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2TashaEverythingHilarious",
      "value" = true,
      "comment" = "The subject perceives everything as hilariously funny; the effect is not immediate - a slight tingling the round the dweomer is placed.",
    }, {
      "name" = "uam2TashaTinglingFirstRound",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2TashaLaughterSequenceDecoded",
      "value" = true,
      "comment" = "The next round: smiling, chuckling, tittering, snickering, into gales of hideous laughter (the interleave garble decoded).",
    }, {
      "name" = "uam2TashaNextRoundRegainFeet",
      "value" = true,
      "comment" = "The mirth lasts a single round; the next round regains feet; -2 strength (or -2 to hit and damage) on the 3rd and 4th rounds.",
    }, {
      "name" = "uam2TashaSaveNegates",
      "value" = true,
      "comment" = "A successful save versus spell negates; the save depends on intelligence: 3 or less totally unaffected; 4-8 save at -6; 9-12 at -4; 13-15 at -2; 16 or greater normal.",
    }, {
      "name" = "uam2TashaInt16PlusNormalSave",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2TashaMaterialFeather",
      "value" = true,
      "comment" = "The materials: a small feather waved in one hand, a tiny wooden paddle tapped against the caster posterior, and a minute tort hurled at the subject.",
    }, {
      "name" = "uam2TashaMaterialPaddle",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2TashaMaterialTort",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2VocalizeComponentsSM",
      "value" = true,
      "comment" = "The components print S, M - no verbal component.",
    }, {
      "name" = "uam2VocalizeRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2VocalizeSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2VocalizeAoeOneSpellCastingCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2VocalizeCastsSilently",
      "value" = true,
      "comment" = "The recipient casts verbal spells silently, so long as the casting takes place entirely within the vocalize duration (the \"speli(s)\" [sic] garble).",
    }, {
      "name" = "uam2VocalizeWithinDurationOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2VocalizeSpeliGarble",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2VocalizeUsefulUnderSilence",
      "value" = true,
      "comment" = "Of great use where quiet is desired, or under a silence spell; it does not negate the silence but offsets it for subsequent spell casting - audible effects are masked while the silence remains.",
    }, {
      "name" = "uam2VocalizeOffsetsNotNegates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2VocalizeMasksAudibleEffects",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2VocalizeNoInfoBackToCaster",
      "value" = true,
      "comment" = "The interleave garble: no vocal communication from within the silence, and no information transmitted back to the caster.",
    }, {
      "name" = "uam2VocalizeMaterialBellNoClapper",
      "value" = true,
      "comment" = "The material: a bell without a clapper, or else a jailbird's tongue.",
    }, {
      "name" = "uam2VocalizeMaterialJailbirdsTongue",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2WhipLevelCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2WhipAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2WhipComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2WhipCastingCellSplitDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2WhipSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2WhipWieldedByHandMovement",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2WhipCrackAndStrikeEachTurn",
      "value" = true,
      "comment" = "The lash makes both a whistling crack and an actual strike each turn.",
    }, {
      "name" = "uam2WhipSoundKeepsAnimalsAtBay",
      "value" = true,
      "comment" = "The sound alone keeps normal animals at bay unless they save versus spell.",
    }, {
      "name" = "uam2WhipNoActualDamage",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2WhipGiantAboveBearSizeUnaffected",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2WhipMonstersUnaffected",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2WhipMeleeWrapsWeapon",
      "value" = true,
      "comment" = "In melee: a to-hit indicates the lash wrapped the opponent weapon; an edged weapon forces the whip to save versus crushing blow (13 or better), a non-edged versus normal blow (6 or better).",
    }, {
      "name" = "uam2WhipSuccessTearsFromHand",
      "value" = true,
      "comment" = "Success tears the weapon from the hand unless the opponent succeeds on a save versus spell; the weapon is cast to the ground and takes 1 round to recover.",
    }, {
      "name" = "uam2WhipOpponentSaveKeepsWeapon",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2WhipMagicBonusPenalizesSave",
      "value" = true,
      "comment" = "The magic bonus of the target weapon penalizes the whip save; the magic resistance of the intended target must fail for a to-hit to be possible.",
    }, {
      "name" = "uam2WhipMagicResistanceMustFail",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2WhipMaterialSilkBraided",
      "value" = true,
      "comment" = "The material: a small bit of silk braided so as to form a miniature whip.",
    }, {
      "name" = "uam2ZephyrComponentsVSM",
      "value" = true,
      "comment" = "The components cell splits: \"V, S,\" then \"M\".",
    }, {
      "name" = "uam2ZephyrComponentsCellSplit",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2ZephyrCastingUnitLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2ZephyrSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2ZephyrAoeOnePath",
      "value" = true,
      "comment" = "The area: one path, a garbled fraction of an inch per level in length - flagged pending the PDF.",
    }, {
      "name" = "uam2ZephyrPathFractionGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2ZephyrDraftInFacedDirection",
      "value" = true,
      "comment" = "A gentle draft moves from the caster in the faced direction, continuing until the maximum area of effect is reached.",
    }, {
      "name" = "uam2ZephyrSmallFlamesWaver",
      "value" = true,
      "comment" = "The force causes small flames to waver and dance, fans larger flames hotter (+1 on damage dice, if applicable).",
    }, {
      "name" = "uam2ZephyrHalvesFogDuration",
      "value" = true,
      "comment" = "It weakens fog cloud and wall of fog so as to halve their duration.",
    }, {
      "name" = "uam2ZephyrHalvesGasDurationAndPotency",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2ZephyrUnlessRenewed",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam2ZephyrMaterialParchmentFolded",
      "value" = true,
      "comment" = "The material: fine parchment, accordion-folded and tacked near the bottom with a pin or ivory or silver.",
    }, {
      "name" = "uam2ZephyrMaterialPinIvorySilver",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uam2BindName'](), \"Bind (Alteration/Enchantment)\") != 0  or m['uam2BindLevel']() != 2  or m['uam2BindRangeInches']() != 3  or m['uam2BindDurationRoundsPerLevel']() != 1  or  m['uam2BindAoeSpecial']() != 1  or  m['uam2BindComponentsVSM']() != 1  or m['uam2BindCastingTimeSegments']() != 2  or  m['uam2BindSaveNone']() != 1  or  m['uam2BindRopelikeNonLiving']() != 1  or  m['uam2BindBehavesAsOrdered']() != 1  or m['uam2BindBaseFeet']() != 50  or m['uam2BindFeetPerLevel']() != 5  or  m['uam2BindReduceWithDiameter']() != 1  or m['uam2BindHalvingBonusPct']() != 50  or  m['uam2BindCommandsCoilLoopTie']() != 1  or  m['uam2BindReversesAvailable']() != 1  or m['uam2BindRespondWithinFeet']() != 1  or  m['uam2BindUsuallyThrown']() != 1  or  m['uam2BindCreatureHoldOverrides']() != 1  or m['uam2BindSlashingDamageToBreak']() != 2  or  m['uam2BindNoGarrotUse']() != 1  or  m['uam2BindTripLineOrEntangle']() != 1  or  m['uam2BindNoMagicBeyondCommands']() != 1",
      "note" = "U1: bind",
    }, {
      "expr" = "strcmp(m['uam2DeeppocketsName'](), \"Deeppockets\") != 0  or  m['uam2DeeppocketsNameHeaderLost']() != 1  or  m['uam2DeeppocketsComponentsGarbled']() != 1  or m['uam2DeeppocketsLevel']() != 2  or m['uam2DeeppocketsCastingTimeTurns']() != 1  or  m['uam2DeeppocketsRangeTouch']() != 1  or  m['uam2DeeppocketsSaveNone']() != 1  or m['uam2DeeppocketsDurationTurnsBase']() != 24  or m['uam2DeeppocketsDurationTurnsPerLevel']() != 6  or  m['uam2DeeppocketsAoeOneGarment']() != 1  or m['uam2DeeppocketsGarmentMinGp']() != 300  or m['uam2DeeppocketsMinPockets']() != 12  or m['uam2DeeppocketsSpecialPocketGp']() != 1000  or m['uam2DeeppocketsSpecialPocketCuFt']() != 5  or m['uam2DeeppocketsAsIfGp']() != 100  or  m['uam2DeeppocketsNoBulge']() != 1  or m['uam2DeeppocketsAltPocketCount']() != 10  or m['uam2DeeppocketsAltPocketGp']() != 100  or  m['uam2DeeppocketsAltVolumeNumberLost']() != 1  or m['uam2DeeppocketsHundredPocketGarmentGp']() != 1000  or m['uam2DeeppocketsHundredPocketCount']() != 100  or m['uam2DeeppocketsHundredPocketGp']() != 10  or  m['uam2DeeppocketsHundredPocketFractionGarbled']() != 1  or  m['uam2DeeppocketsExpirySaveVsSpell']() != 1  or  m['uam2DeeppocketsFailAstralLostForever']() != 1  or  m['uam2DeeppocketsSuccessAppearsAndFalls']() != 1  or  m['uam2DeeppocketsMaterialGoldenNeedle']() != 1  or  m['uam2DeeppocketsMaterialClothHalfTwist']() != 1",
      "note" = "U2: deeppockets",
    }, {
      "expr" = "strcmp(m['uam2FlamingSphereName'](), \"Flaming Sphere (Alteration/Evocation)\") != 0  or m['uam2FlamingSphereLevel']() != 2  or m['uam2FlamingSphereRangeInches']() != 1  or  m['uam2FlamingSphereRangeGarbleDecoded']() != 1  or m['uam2FlamingSphereCastingTimeSegments']() != 2  or  m['uam2FlamingSphereSaveNegates']() != 1  or m['uam2FlamingSphereDurationRoundsPerLevel']() != 1  or m['uam2FlamingSphereDiameterFeet']() != 6  or  m['uam2FlamingSphereComponentsVSM']() != 1  or m['uam2FlamingSphereAppearsWithinInches']() != 1  or  m['uam2FlamingSphereRollsAsPointed']() != 1  or m['uam2FlamingSphereBarrierMaxFeet']() != 4  or  m['uam2FlamingSphereSetsFlammablesAfire']() != 1  or m['uam2FlamingSphereDamageMin']() != 2  or m['uam2FlamingSphereDamageMax']() != 8  or m['uam2FlamingSphereMoveInchesPerRound']() != 1  or  m['uam2FlamingSphereInterleaveGarbleDecoded']() != 1  or m['uam2FlamingSphereBlastRadiusFeet']() != 5  or  m['uam2FlamingSphereRestsUnpointed']() != 1  or  m['uam2FlamingSphereExtinguishedAsNormalFire']() != 1  or  m['uam2FlamingSphereMaterialTallow']() != 1  or  m['uam2FlamingSphereMaterialSulphur']() != 1  or  m['uam2FlamingSphereMaterialPowderedIron']() != 1",
      "note" = "U3: flaming sphere",
    }, {
      "expr" = "strcmp(m['uam2IrritationName'](), \"Irritation (Alteration)\") != 0  or m['uam2IrritationLevel']() != 2  or m['uam2IrritationRangeInchesPerLevel']() != 1  or m['uam2IrritationCastingTimeSegments']() != 2  or  m['uam2IrritationSaveNegates']() != 1  or  m['uam2IrritationDurationSpecial']() != 1  or  m['uam2IrritationAoeOneCreature']() != 1  or  m['uam2IrritationComponentsVSM']() != 1  or  m['uam2IrritationAffectsEpidermis']() != 1  or  m['uam2IrritationThickSkinnedUnaffected']() != 1  or  m['uam2IrritationTwoVersions']() != 1  or m['uam2IrritationScratchSegmentsMin']() != 5  or m['uam2IrritationScratchSegmentsMax']() != 8  or m['uam2IrritationSquirmRounds']() != 3  or m['uam2IrritationAcWorseBy']() != 4  or m['uam2IrritationToHitWorseBy']() != 2  or  m['uam2IrritationSpellsRuinedFirstRoundOnly']() != 1  or m['uam2IrritationRashLatencyMinRounds']() != 1  or m['uam2IrritationRashLatencyMaxRounds']() != 4  or  m['uam2IrritationRashPersistsUntilCureOrDispel']() != 1  or m['uam2IrritationRashComelinessPerDay']() != 1  or m['uam2IrritationRashComelinessMaxLoss']() != 4  or m['uam2IrritationRashDexLossAfterWeek']() != 1  or  m['uam2IrritationRashVanishesOnRemoval']() != 1  or  m['uam2IrritationMaterialPoisonLeaf']() != 1",
      "note" = "U4: irritation",
    }, {
      "expr" = "strcmp(m['uam2KnowAlignmentName'](), \"Know Alignment (Divination)\") != 0  or m['uam2KnowAlignmentLevel']() != 2  or  m['uam2KnowAlignmentReversible']() != 1  or  m['uam2KnowAlignmentComponentsCellLost']() != 1  or m['uam2KnowAlignmentCastingTimeRounds']() != 1  or  m['uam2KnowAlignmentRangeCellLost']() != 1  or  m['uam2KnowAlignmentSaveNone']() != 1  or m['uam2KnowAlignmentDurationRoundsPerLevel']() != 1  or m['uam2KnowAlignmentAoeCreaturesPer2Rounds']() != 1  or  m['uam2KnowAlignmentSameAsClerical']() != 1  or  m['uam2KnowAlignmentOneRoundEthicOnly']() != 1",
      "note" = "U5: know alignment",
    }, {
      "expr" = "strcmp(m['uam2AcidArrowName'](), \"Melf's Acid Arrow (Evocation)\") != 0  or m['uam2AcidArrowLevel']() != 2  or m['uam2AcidArrowRangeInches']() != 3  or  m['uam2AcidArrowDurationSpecial']() != 1  or  m['uam2AcidArrowAoeOneTarget']() != 1  or  m['uam2AcidArrowComponentsVSM']() != 1  or m['uam2AcidArrowCastingTimeSegments']() != 4  or  m['uam2AcidArrowSaveSpecial']() != 1  or  m['uam2AcidArrowSpeedsAsFighterBow']() != 1  or m['uam2AcidArrowPlusForHit']() != 1  or  m['uam2AcidArrowAcidBypassesPlusOneImmunity']() != 1  or m['uam2AcidArrowDamageMin']() != 2  or m['uam2AcidArrowDamageMax']() != 5  or m['uam2AcidArrowAcidVolumeOunces']() != 8  or m['uam2AcidArrowAcidDamageMin']() != 2  or m['uam2AcidArrowAcidDamageMax']() != 8  or  m['uam2AcidArrowItemSavingThrowApplies']() != 1  or  m['uam2AcidArrowNoSplash']() != 1  or m['uam2AcidArrowExtraRoundsPer3Levels']() != 1  or m['uam2AcidArrowExtraRoundsFromLevel']() != 4  or  m['uam2AcidArrowNeutralizationStops']() != 1  or  m['uam2AcidArrowMaterialDart']() != 1  or  m['uam2AcidArrowMaterialRhubarbLeaf']() != 1  or  m['uam2AcidArrowMaterialAdderStomach']() != 1",
      "note" = "U6: the Melf acid arrow",
    }, {
      "expr" = "strcmp(m['uam2PreserveName'](), \"Preserve (Abjuration)\") != 0  or m['uam2PreserveLevel']() != 2  or m['uam2PreserveCastingTimeRounds']() != 2  or  m['uam2PreserveRangeTouch']() != 1  or  m['uam2PreserveSaveNone']() != 1  or  m['uam2PreserveDurationPermanent']() != 1  or  m['uam2PreserveAoeNumberLost']() != 1  or  m['uam2PreserveAoeCuFtPerLevel']() != 1  or  m['uam2PreserveComponentsVSM']() != 1  or  m['uam2PreserveRetainsItemFresh']() != 1  or  m['uam2PreserveIneffectiveForFreshGather']() != 1  or  m['uam2PreserveOpenerGarbleDecoded']() != 1  or m['uam2PreserveHardDryMinLevel']() != 2  or m['uam2PreserveHardDryMaxLevel']() != 4  or m['uam2PreserveSoftWetMinLevel']() != 5  or m['uam2PreserveSoftWetMaxLevel']() != 7  or m['uam2PreserveLiquidMinLevel']() != 8  or  m['uam2PreserveContainerOnlyForMoisture']() != 1  or  m['uam2PreserveMaterialDust']() != 1  or  m['uam2PreserveMaterialResinOrAmber']() != 1  or  m['uam2PreserveMaterialBrandy']() != 1",
      "note" = "U7: preserve",
    }, {
      "expr" = "strcmp(m['uam2PfcName'](), \"Protection From Cantrips\") != 0  or  m['uam2PfcNameHeaderGarbled']() != 1  or m['uam2PfcLevel']() != 2  or  m['uam2PfcRangeTouch']() != 1  or m['uam2PfcCastingTimeSegments']() != 2  or  m['uam2PfcSaveNoneOrNegates']() != 1  or m['uam2PfcDurationDaysPerLevel']() != 1  or  m['uam2PfcAoeOneCreatureOrObject']() != 1  or  m['uam2PfcComponentsCellLost']() != 1  or  m['uam2PfcImmunityToCantrips']() != 1  or  m['uam2PfcProseInterleaveDecoded']() != 1  or  m['uam2PfcProtectsCasterOrItem']() != 1  or  m['uam2PfcCantripDissipatesWithPop']() != 1  or  m['uam2PfcMischievousApprenticesUse']() != 1  or  m['uam2PfcUnwillingToHitAndSave']() != 1",
      "note" = "U8: protection from cantrips",
    }, {
      "expr" = "strcmp(m['uam2TashaName'](), \"Tasha's Uncontrollable Hideous Laughter (Evo\" \"cation)\") != 0  or m['uam2TashaLevel']() != 2  or m['uam2TashaCastingTimeSegments']() != 2  or m['uam2TashaRangeInches']() != 5  or  m['uam2TashaSaveSpecial']() != 1  or m['uam2TashaDurationRounds']() != 1  or  m['uam2TashaAoeOneCreature']() != 1  or  m['uam2TashaComponentsVSM']() != 1  or  m['uam2TashaEverythingHilarious']() != 1  or  m['uam2TashaTinglingFirstRound']() != 1  or  m['uam2TashaLaughterSequenceDecoded']() != 1  or  m['uam2TashaNextRoundRegainFeet']() != 1  or m['uam2TashaMinusTwoRounds']() != 2  or m['uam2TashaPenaltyRounds']() != 2  or  m['uam2TashaSaveNegates']() != 1  or m['uam2TashaUnaffectedIntMax']() != 3  or m['uam2TashaInt4to8SaveMod']() != -6  or m['uam2TashaInt9to12SaveMod']() != -4  or m['uam2TashaInt13to15SaveMod']() != -2  or  m['uam2TashaInt16PlusNormalSave']() != 1  or  m['uam2TashaMaterialFeather']() != 1  or  m['uam2TashaMaterialPaddle']() != 1  or  m['uam2TashaMaterialTort']() != 1",
      "note" = "U9: the Tasha laughter",
    }, {
      "expr" = "strcmp(m['uam2VocalizeName'](), \"Vocalize (Alteration)\") != 0  or  m['uam2VocalizeComponentsSM']() != 1  or m['uam2VocalizeLevel']() != 2  or  m['uam2VocalizeRangeTouch']() != 1  or m['uam2VocalizeCastingTimeRounds']() != 1  or  m['uam2VocalizeSaveNone']() != 1  or m['uam2VocalizeDurationRounds']() != 5  or  m['uam2VocalizeAoeOneSpellCastingCreature']() != 1  or  m['uam2VocalizeCastsSilently']() != 1  or  m['uam2VocalizeWithinDurationOnly']() != 1  or  m['uam2VocalizeSpeliGarble']() != 1  or  m['uam2VocalizeUsefulUnderSilence']() != 1  or  m['uam2VocalizeOffsetsNotNegates']() != 1  or  m['uam2VocalizeMasksAudibleEffects']() != 1  or  m['uam2VocalizeNoInfoBackToCaster']() != 1  or  m['uam2VocalizeMaterialBellNoClapper']() != 1  or  m['uam2VocalizeMaterialJailbirdsTongue']() != 1",
      "note" = "U10: vocalize",
    }, {
      "expr" = "strcmp(m['uam2WhipName'](), \"Whip (Evocation)\") != 0  or m['uam2WhipLevel']() != 2  or  m['uam2WhipLevelCellLost']() != 1  or m['uam2WhipDurationRoundsPerLevel']() != 1  or  m['uam2WhipAoeSpecial']() != 1  or  m['uam2WhipComponentsVSM']() != 1  or m['uam2WhipCastingTimeSegments']() != 2  or  m['uam2WhipCastingCellSplitDecoded']() != 1  or  m['uam2WhipSaveSpecial']() != 1  or m['uam2WhipReachInches']() != 1  or  m['uam2WhipWieldedByHandMovement']() != 1  or  m['uam2WhipCrackAndStrikeEachTurn']() != 1  or  m['uam2WhipSoundKeepsAnimalsAtBay']() != 1  or m['uam2WhipAnimalSaveModMin']() != -1  or m['uam2WhipAnimalSaveModMax']() != -4  or m['uam2WhipSlinkAwayHours']() != 1  or  m['uam2WhipNoActualDamage']() != 1  or m['uam2WhipUnaffectedIntAbove']() != 3  or  m['uam2WhipGiantAboveBearSizeUnaffected']() != 1  or  m['uam2WhipMonstersUnaffected']() != 1  or  m['uam2WhipMeleeWrapsWeapon']() != 1  or m['uam2WhipEdgedSaveVsCrushingBlow']() != 13  or m['uam2WhipNonEdgedSaveVsNormalBlow']() != 6  or  m['uam2WhipSuccessTearsFromHand']() != 1  or  m['uam2WhipOpponentSaveKeepsWeapon']() != 1  or m['uam2WhipWeaponRecoverRounds']() != 1  or  m['uam2WhipMagicBonusPenalizesSave']() != 1  or  m['uam2WhipMagicResistanceMustFail']() != 1  or  m['uam2WhipMaterialSilkBraided']() != 1",
      "note" = "U11: whip",
    }, {
      "expr" = "strcmp(m['uam2ZephyrName'](), \"Zephyr (Evocation)\") != 0  or  m['uam2ZephyrComponentsVSM']() != 1  or  m['uam2ZephyrComponentsCellSplit']() != 1  or m['uam2ZephyrLevel']() != 2  or m['uam2ZephyrRangeZero']() != 0  or m['uam2ZephyrCastingTimeSegments']() != 2  or  m['uam2ZephyrCastingUnitLost']() != 1  or  m['uam2ZephyrSaveNone']() != 1  or m['uam2ZephyrDurationSegments']() != 1  or  m['uam2ZephyrAoeOnePath']() != 1  or  m['uam2ZephyrPathFractionGarbled']() != 1  or  m['uam2ZephyrDraftInFacedDirection']() != 1  or  m['uam2ZephyrSmallFlamesWaver']() != 1  or m['uam2ZephyrFanDamageBonus']() != 1  or m['uam2ZephyrHoldVaporsRounds']() != 1  or  m['uam2ZephyrHalvesFogDuration']() != 1  or m['uam2ZephyrMoveGasesBackInches']() != 1  or  m['uam2ZephyrHalvesGasDurationAndPotency']() != 1  or  m['uam2ZephyrUnlessRenewed']() != 1  or  m['uam2ZephyrMaterialParchmentFolded']() != 1  or  m['uam2ZephyrMaterialPinIvorySilver']() != 1",
      "note" = "U12: zephyr",
    }, {
      "expr" = "m['uas2Mu2ndCount']() != 30  or strcmp(m['uas2Mu2ndName'](1), \"Bind\") != 0  or strcmp(m['uas2Mu2ndName'](9), \"Irritation\") != 0  or strcmp(m['uas2Mu2ndName'](11), \"Know Alignment\") != 0  or strcmp(m['uas2Mu2ndName'](16), \"Melf's Acid Arrow\") != 0  or strcmp(m['uas2Mu2ndName'](18), \"Preserve\") != 0  or strcmp(m['uas2Mu2ndName'](26), \"Tasha's Uncontrollable \" \"Hideous Laughter\") != 0  or strcmp(m['uas2Mu2ndName'](27), \"Whip\") != 0  or strcmp(m['uas2Mu2ndName'](29), \"Zephyr\") != 0",
      "note" = "the R342 table seam (8 of 12 names)",
    }, {
      "expr" = "strcmp(n, \"Deeppockets\") == 0  or strcmp(n, \"Flaming Sphere\") == 0  or strcmp(n, \"Protection From \" \"Cantrips\") == 0  or strcmp(n, \"Vocalize\") == 0",
      "note" = "the four names absent from the seam",
    } },
  "audit" = {
      "label" = "R357: the UA new magic-user 2nd level spells pin audit",
      "comment" = "The UA NEW MAGIC-USER SPELLS (pp. 51-52), the 2nd level - bind, deeppockets (the lost name header), flaming sphere, irritation, know alignment, the Melf acid arrow, preserve, protection from cantrips, the Tasha laughter, vocalize, whip and zephyr. The family decodes the 7s as 1. The R342 table seam pins 8 of 12; the item stays open (the 3rd-9th levels).",
    },
}
