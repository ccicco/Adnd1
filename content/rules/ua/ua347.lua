-- ua347: promoted from rules/ua/uaclericspells5.h (the The UA NEW CLERIC SPELLS (pp. 40-41) pins, R347: the 5th-level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 347,
  "prefix" = "ua347",
  "banner" = {
      "title" = "The UA NEW CLERIC SPELLS (pp. 40-41) pins, R347: the 5th-level",
      "provenance" = "spell descriptions - air walk, animate dead monsters, golem, magic font, rainbow and spike stones (the spike stones prose prints here in the cleric chapter; the druid chapter (pp. 42-45) cross-references it - the druid item will seam-check against this pin). Pin-era pattern (R322): pinned data only - no engine site exists. The R341 continued table (4th-7th) prints seven 5th-level fragments (Commune, Cure Critical Wounds, Dispel Evil, Magic Font, Plane Shift, Spike Growth, True Seeing); magic font is the one name of this round that seam-checks - the rest pin from the prose alone.  JUDGMENTs (the decode method): - the digit-garble family (established R343, corroborated R344/R346): the OCR prints 7 where 1 belongs in the stat cells. This round's three stat-cell 7s decode as 1: air walk casting \"7 segment\" = 1 segment; animate dead monsters casting \"7 segments\" = 1 segment; golem casting \"7 segments\" = 1 segment - all three family decodes without independent corroboration this round, verbatim with doubt pending the PDF. - two 7s stay genuine (not the family): the rainbow bow \"fire 7 missiles\" is corroborated by the spelled-out \"seven-hued\", \"seven-colored\" and \"seven measures\"; the golem size ceiling \"as large as 7\" tall\" is corroborated by the clean \"approximately man-sized\" prose. - the golem/rainbow page interleaves: the two stat tables print in scrambled column order. Decoded by position - the golem keeps Level 5, Range 1\", Duration Special, Area of Effect Special; the rainbow keeps Components V, S, M, Casting Time 8 segments, Duration 1 round/level, Saving Throw None. The rainbow Range cell never prints - a hole. - the straw golem SD line shatters across the air walk table (\"SD immune to\" + \"piercing weapons,\" + \"The half golem damage: is highly from blunt\" + \"ity is 30 pounds\"); decoded: immune to piercing weapons, half damage from blunt weapons, carrying capacity 30 pounds - the reverse of the rope golem's clean line. - magic font's components print \"V, S\\$, M\" - the S-cell garble decodes as the plain S (the family-standard component trio). - the bridge length cells print \"20\\\"\" and \"120\" - the degree/inch marks are OCR noise for feet (the same mark noise as the 12\" rate cells); decoded as feet. - the animate dead monsters prose garbles mid-sentence (\"the remains must ... be of bipedal ... similar to those of humans, except ... hit dice (and ... with ... 7' height)\"); the sense is pinned (bipedal, man-like, hit-dice and height the exceptions), the fragment region stays a hole. - the magic font prose garbles around the capacity rule (\"becomes Magic similar Tr to a crystal ball (see under Dungeon Masters For Guide, than each vial of capacity of the basin of the font\"); decoded: the basin becomes similar to a crystal ball, and for each vial of capacity the cleric may scry 1 round. - the rainbow bridge prose garbles at the tail (\"If the bridge's ... is exceeded at any ... time, ... the ... it will last for the length of the spell or until ordered out of ... existence ... by the caster\"); the load limit and the two dismissal modes are pinned, the fragment region stays a hole.  OCR holes (the item stays open - the 6th-7th levels pin in later rounds; these stay pending the PDF): the animate dead monsters Range cell (blank); the rainbow Range cell (never prints); the three family casting-time decodes (air walk, animate dead monsters, golem); the straw golem SD decode; the animate dead monsters and magic font prose fragment regions; the rainbow bridge tail fragment region.",
    },
  "consts" = { {
      "name" = "uac5AirwalkName",
      "value" = "Air Walk (Alteration)",
      "comment" = "---- air walk (Alteration), p. 40 ----",
    }, {
      "name" = "uac5AirwalkCastingTimeSegments",
      "value" = 1,
      "comment" = "The casting time prints \"7 segment\" - the digit-garble family decodes 1 segment; verbatim with doubt pending the PDF.",
    }, {
      "name" = "uac5AirwalkDurationTurnsBase",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac5AirwalkDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac5AirwalkAscent45Divisor",
      "value" = 2,
      "comment" = "The ascent ladder: 45 degrees at one-half normal movement, 60 degrees at one-fourth, straight up at one-eighth.",
    }, {
      "name" = "uac5AirwalkAscent60Divisor",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac5AirwalkAscentStraightDivisor",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uac5AirwalkDescentStraightMultiple",
      "value" = 8,
      "comment" = "Rapid descent inverts the ladder: straight downward can be done at eight times the normal rate (or any slower rate the traveller desires).",
    }, {
      "name" = "uac5AirwalkGustIntoDivisor",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac5AirwalkGustWithMultiple",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac5AnimateName",
      "value" = "Animate Dead Monsters (Necromantic)",
      "comment" = "---- animate dead monsters (Necromantic), p. 40 ----",
    }, {
      "name" = "uac5AnimateCastingTimeSegments",
      "value" = 1,
      "comment" = "The casting time prints \"7 segments\" - the family decodes 1 segment; verbatim with doubt pending the PDF.",
    }, {
      "name" = "uac5AnimateAnimatedPerTwoLevels",
      "value" = 1,
      "comment" = "Animates 1 humanoid or semi-humanoid skeleton or corpse for every 2 levels of experience attained.",
    }, {
      "name" = "uac5AnimateCommandWordsMax",
      "value" = 12,
      "comment" = "Direct commands or instructions of up to about 12 words in length will be obeyed (cf. the animate dead spell).",
    }, {
      "name" = "uac5AnimateExampleTypeCount",
      "value" = 6,
      "comment" = "The monster-type examples: apes (carnivorous and giant), bugbears, ettins, giants (all varieties), ogres and trolls - the list is not exclusive.",
    }, {
      "name" = "uac5AnimateLowHDThreshold",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac5GolemName",
      "value" = "Golem (Enchantment/Charm)",
      "comment" = "---- golem (Enchantment/Charm), pp. 40-41 ----",
    }, {
      "name" = "uac5GolemRangeInches",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac5GolemCastingTimeSegments",
      "value" = 1,
      "comment" = "The casting time prints \"7 segments\" - the family decodes 1 segment; verbatim with doubt pending the PDF.",
    }, {
      "name" = "uac5GolemMinHeightFeet",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac5GolemMaxHeightFeet",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uac5GolemMaterialCount",
      "value" = 4,
      "comment" = "The sort of golem depends on the material used and the level of the cleric - the four-material ladder.",
    }, {
      "name" = "uac5GolemRopeStranglePerRound",
      "value" = 6,
      "comment" = "The rope golem: strangulation inflicts 6 points per round after a hit until destroyed or caused to release its grip.",
    }, {
      "name" = "uac5GolemMindlessSpellExamples",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac5GolemInstructionWordsMax",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uac5FontName",
      "value" = "Magic Font (Divination)",
      "comment" = "---- magic font (Divination), p. 41 ----",
    }, {
      "name" = "uac5FontCastingTimeTurns",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uac5FontRoundsPerVial",
      "value" = 1,
      "comment" = "For each vial of capacity of the basin, the cleric may scry for 1 round - the duration is directly related to the size of the receptacle.",
    }, {
      "name" = "uac5RainbowName",
      "value" = "Rainbow (Evocation/Alteration)",
      "comment" = "---- rainbow (Evocation/Alteration), p. 41 ----",
    }, {
      "name" = "uac5RainbowCastingTimeSegments",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uac5RainbowDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac5RainbowApplicationCount",
      "value" = 4,
      "comment" = "Four applications; the cleric decides which is desired at the time of casting.",
    }, {
      "name" = "uac5RainbowBowStrengthMin",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac5RainbowBowMissilePlus",
      "value" = 3,
      "comment" = "Each missile equals a +3 weapon; no non-proficiency penalty; only a member of a character class permitted to use a bow may employ it.",
    }, {
      "name" = "uac5RainbowBowMissiles",
      "value" = 7,
      "comment" = "The bow fires 7 missiles before disappearing - a genuine 7, corroborated by the spelled-out \"seven-hued\" and the seven colors (not the digit-garble family).",
    }, {
      "name" = "uac5RainbowBowMaxShotsPerRound",
      "value" = 2,
      "comment" = "It fires once or twice per round, according to the user's desire; each fired missile removes one hue.",
    }, {
      "name" = "uac5RainbowBowColorCount",
      "value" = 7,
      "comment" = "Each color causes double damage to its targets:",
    }, {
      "name" = "uac5RainbowBridgeMinLengthFeet",
      "value" = 20,
      "comment" = "At least 20 feet long, up to 120 feet per the caster's desire (the inch/degree marks are OCR noise for feet).",
    }, {
      "name" = "uac5RainbowBridgeMaxLengthFeet",
      "value" = 120,
      "comment" = "",
    }, {
      "name" = "uac5RainbowElevatorRadiusFeet",
      "value" = 10,
      "comment" = "The elevator: carries the caster and all within a 10-foot radius skyward, in a path arching upward to any altitude, then down again if desired.",
    }, {
      "name" = "uac5RainbowElevatorRateInches",
      "value" = 12,
      "comment" = "Movement along the elevator is at rate 12; the arc of the rainbow trails out 12 behind those traveling upon it.",
    }, {
      "name" = "uac5RainbowElevatorTrailInches",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uac5RainbowFlagonMeasures",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uac5RainbowFlagonDraughtCount",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uac5RainbowFlagonCasterLevel",
      "value" = 12,
      "comment" = "Each draught acts as if the spell had been cast by a cleric of 12th level; the effects persist after the duration of the rainbow spell expires.",
    }, {
      "name" = "uac5RainbowDiamondMinValueGP",
      "value" = 1000,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesName",
      "value" = "Spike Stones (Alteration/Enchantment)",
      "comment" = "---- spike stones (Alteration/Enchantment), p. 41 ----",
    }, {
      "name" = "uac5SpikeStonesCastingTimeSegments",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesRangeInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesDurationTurnsMin",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesDurationTurnsMax",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesAoeSquareInchesPerLevel",
      "value" = 1,
      "comment" = "The area: 1 square inch per level, 1 spike per square foot.",
    }, {
      "name" = "uac5SpikeStonesSpikesPerSquareFoot",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesNoticeChancePct",
      "value" = 25,
      "comment" = "If an area is carefully observed, each observer is 25% likely to notice the sharp points.",
    }, {
      "name" = "uac5SpikeStonesDamageMin",
      "value" = 1,
      "comment" = "Each spike stone that hits inflicts 1-4 points; success is determined as if the caster were actually engaging in combat.",
    }, {
      "name" = "uac5SpikeStonesDamageMax",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesChargeAttacksPerInch",
      "value" = 2,
      "comment" = "Charging or running victims suffer 2 attacks per inch of movement rate over the area after the initial damage, before being able to halt; others suffer 1 additional check.",
    }, {
      "name" = "uac5SpikeStonesOthersExtraChecks",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesPitChecks",
      "value" = 6,
      "comment" = "Falling into an affected pit: 6 attack-like checks, each at +2 \"to hit\" per 10 feet fallen and +2 damage per 10 feet, spike damage in addition to falling damage.",
    }, {
      "name" = "uac5SpikeStonesPitToHitBonusPer10ft",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesPitDamageBonusPer10ft",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesStalactiteCount",
      "value" = 4,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uac5AirwalkComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5AirwalkRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5AirwalkSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5AirwalkAoeOneCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5AirwalkTreadsOnAir",
      "value" = true,
      "comment" = "Tread upon air just as if it were solid ground; ascending is like walking up a hill - the steeper, the slower.",
    }, {
      "name" = "uac5AirwalkAlwaysInControl",
      "value" = true,
      "comment" = "Always in control of the movement rate - someone descending rapidly can \"stop on a copper piece\" to avoid crashing.",
    }, {
      "name" = "uac5AirwalkStopOnCopperPiece",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5AirwalkGustInterplay",
      "value" = true,
      "comment" = "A gust of wind spell in the same area: one-half the usual rate going into the gust, twice the usual rate with it.",
    }, {
      "name" = "uac5AirwalkTargetUpToGiantSize",
      "value" = true,
      "comment" = "Placed on any creature touched, up to and including one of giant size; a trained horse could be ridden through the air.",
    }, {
      "name" = "uac5AirwalkTrainedHorseExample",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5AirwalkBeastNeedsTraining",
      "value" = true,
      "comment" = "An animal not accustomed to such movement would panic - the steed needs careful and lengthy training.",
    }, {
      "name" = "uac5AirwalkMaterialSymbolThistledown",
      "value" = true,
      "comment" = "The material: the cleric's holy/unholy symbol and a bit of thistledown.",
    }, {
      "name" = "uac5AnimateComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5AnimateRangeLost",
      "value" = true,
      "comment" = "The Range cell prints blank - unresolvable; a hole.",
    }, {
      "name" = "uac5AnimateDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5AnimateSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5AnimateAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5AnimateCfAnimateDead",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5AnimateListNotExclusive",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5AnimateBipedalManLike",
      "value" = true,
      "comment" = "The garbled specimen rule: the remains must be of bipedal creatures similar to humans, except hit dice and height - the fragment region stays a hole pending the PDF.",
    }, {
      "name" = "uac5AnimateSpecimenRuleFragmentLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5AnimateCorpseMonsterZombieMM2",
      "value" = true,
      "comment" = "Corpses: monster zombies (see Monster Manual II), or normal (living) creatures of the same form if that type normally has less than 6 hit dice.",
    }, {
      "name" = "uac5AnimateSkeletonHalfHDRoundedUp",
      "value" = true,
      "comment" = "Skeletons: monsters of half the hit dice (rounded up) of the normal sort.",
    }, {
      "name" = "uac5AnimateNormalAttacksOnly",
      "value" = true,
      "comment" = "Either type receives its normal physical attacks, but no special attacks or defenses beyond monster zombie/skeleton norms.",
    }, {
      "name" = "uac5AnimateMaterialSymbolSpecimen",
      "value" = true,
      "comment" = "The material: the cleric's holy/unholy symbol and a small specimen of the creature type to be animated.",
    }, {
      "name" = "uac5GolemComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5GolemDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5GolemSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5GolemAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5GolemRequiresPersonalConstruction",
      "value" = true,
      "comment" = "The cleric must personally construct the form of the golem and then place a prayer spell upon the construction.",
    }, {
      "name" = "uac5GolemRequiresPrayerSpell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5GolemManShapedManSized",
      "value" = true,
      "comment" = "All golems are man-shaped and approximately man-sized, from as small as 3 feet to as large as 7 feet tall.",
    }, {
      "name" = "uac5GolemStrawSDDecoded",
      "value" = true,
      "comment" = "The straw golem SD line shatters across the air walk table - the decode (immune to piercing weapons, half damage from blunt) is the reverse of the rope golem's clean line.",
    }, {
      "name" = "uac5GolemRopeStrangleUntilRelease",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5GolemWoodImmuneBluntPiercing",
      "value" = true,
      "comment" = "The wood golem: +1 or better magic weapon to hit, immune to blunt and piercing weapons (the leather golem shares the weapon gate and takes half damage from blunt).",
    }, {
      "name" = "uac5GolemLeatherHalfFromBlunt",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5GolemLesserGolemsName",
      "value" = true,
      "comment" = "Collectively the lesser golems, distinguished from the Monster Manual golems; they have no minds, so charm, fear, hold, sleep and the like have no effect.",
    }, {
      "name" = "uac5GolemNoMinds",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5GolemSavesAsCreatorLevel",
      "value" = true,
      "comment" = "The dweomer lets a lesser golem save as if a cleric of the same level as its creator.",
    }, {
      "name" = "uac5GolemCannotSpeak",
      "value" = true,
      "comment" = "They cannot speak, but comprehend and carry out simple instructions of no more than a dozen words.",
    }, {
      "name" = "uac5FontComponentsVSM",
      "value" = true,
      "comment" = "The components print \"V, S\\$, M\" - the S-cell garble decodes as the plain S (the family-standard trio).",
    }, {
      "name" = "uac5FontComponentsDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5FontRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5FontDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5FontSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5FontAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5FontScryingDevice",
      "value" = true,
      "comment" = "A holy/unholy water font serves as a scrying device; the spell will not function unless the cleric is in good standing with his or her deity.",
    }, {
      "name" = "uac5FontRequiresGoodStanding",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5FontLikeCrystalBall",
      "value" = true,
      "comment" = "The garbled capacity rule decoded: the basin of holy/unholy water becomes similar to a crystal ball (see the Dungeon Masters Guide); the fragment region stays a hole.",
    }, {
      "name" = "uac5FontCapacityRuleFragmentLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5FontDurationTiedToCapacity",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5FontDetectionSeeMagicMirror",
      "value" = true,
      "comment" = "The scrying-detection chances: the crystal ball description in the DMG and the magic-user spell magic mirror herein.",
    }, {
      "name" = "uac5FontMaterialNotExhausted",
      "value" = true,
      "comment" = "The material - the holy/unholy symbol and the font and its trappings - is not exhausted by the use of the spell.",
    }, {
      "name" = "uac5RainbowComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowRangeLost",
      "value" = true,
      "comment" = "The Range cell never prints in the scrambled table - a hole.",
    }, {
      "name" = "uac5RainbowSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowNeedsRainbowSight",
      "value" = true,
      "comment" = "The caster must be in sight of a rainbow of any sort, or have the special component (see below).",
    }, {
      "name" = "uac5RainbowSpecialComponentFallback",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowBowShimmering",
      "value" = true,
      "comment" = "The bow: a shimmering, multi-layered bow of rainbow hues, light and easy to pull - anyone of strength 6 or better can use it.",
    }, {
      "name" = "uac5RainbowBowNoNonproficiencyPenalty",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowBowBowClassOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowBowHueLeavesPerShot",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowBowArrowAppearsNocked",
      "value" = true,
      "comment" = "When drawn, an arrow of the appropriate color magically appears, nocked and ready; if no color is requested, or one already used is asked for, the next arrow in spectrum order appears.",
    }, {
      "name" = "uac5RainbowBowSpectrumFallback",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowBridgeSevenHued",
      "value" = true,
      "comment" = "The bridge: a seven-hued bridge, as many feet wide as the cleric has levels; it bears as much weight, in hundreds of pounds, as the cleric has levels.",
    }, {
      "name" = "uac5RainbowBridgeWidthFeetPerLevel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowBridgeLoadHundredsPerLevel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowBridgeLastsSpellLength",
      "value" = true,
      "comment" = "The garbled tail decoded: the bridge lasts for the length of the spell or until ordered out of existence by the caster; the fragment region stays a hole.",
    }, {
      "name" = "uac5RainbowBridgeOrderedOutOfExistence",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowBridgeTailFragmentLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowElevatorArcPath",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowElevatorDangerOnExpiry",
      "value" = true,
      "comment" = "Care must be taken to reach a place of safety before the duration expires, or the elevator disappears and leaves those on it with no support.",
    }, {
      "name" = "uac5RainbowFlagonSevenColored",
      "value" = true,
      "comment" = "The flagon: swirls and condenses into a seven-colored vessel containing seven measures of pure water; each poured measure mixes one hue into a magical draught; unused measures and the container disappear at expiration.",
    }, {
      "name" = "uac5RainbowFlagonUnusedDisappear",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowFlagonEffectsPersist",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowMaterialSymbolAndVial",
      "value" = true,
      "comment" = "The material: the holy/unholy symbol and a vial of holy/unholy water; without a rainbow in the vicinity, a diamond of not less than 1,000 gp value, prepared by the cleric when in sight of a rainbow by bless and prayer spells upon the gem; only the holy symbol remains after casting.",
    }, {
      "name" = "uac5RainbowDiamondNeedsBlessPrayer",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5RainbowOnlySymbolRemains",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesNaturalAndWorked",
      "value" = true,
      "comment" = "Rock shapes itself into long, sharp points that tend to blend into the background; effective on both natural rock and worked stone; serves to impede progress or inflict damage.",
    }, {
      "name" = "uac5SpikeStonesImpedesOrDamages",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesAttackAsCaster",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesAttackOnEntryAndSteps",
      "value" = true,
      "comment" = "Those entering are attacked immediately upon setting foot in the area and upon each step thereafter; the initial step reveals the problem only if the initial attack succeeds.",
    }, {
      "name" = "uac5SpikeStonesInitialStepAlertsOnlyOnHit",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesDamageInAdditionToFalling",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac5SpikeStonesMaterialStalactites",
      "value" = true,
      "comment" = "The material: four tiny stalactites.",
    }, {
      "name" = "uac5MagicFontSeamChecks",
      "value" = true,
      "comment" = "The R341 continued table: the 5th-level column prints seven fragments (Commune, Cure Critical Wounds, Dispel Evil, Magic Font, Plane Shift, Spike Growth, True Seeing) - magic font is the one name of this round that seam-checks; the rest pin from the prose alone.",
    }, {
      "name" = "uac5SpellsPinFromProse",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uac5AnimateExampleTypeName",
      "comment" = "",
      "kind" = "string array",
      "count" = 6,
      "values" = { "apes (carnivorous and giant)", "bugbears", "ettins", "giants (all varieties)", "ogres", "trolls" },
    }, {
      "name" = "uac5GolemMaterialName",
      "comment" = "",
      "kind" = "string array",
      "count" = 4,
      "values" = { "straw", "rope", "leather", "wood" },
    }, {
      "name" = "uac5GolemMinLevel",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[4] = { 9, 11, 13, 15 }; if (i < 0) i = 0; if (i > 3) i = 3; return k[i];",
    }, {
      "name" = "uac5GolemBuildHours",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[4] = { 1, 3, 9, 27 }; if (i < 0) i = 0; if (i > 3) i = 3; return k[i];",
    }, {
      "name" = "uac5GolemDurationHoursPerLevel",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[4] = { 1, 3, 6, 12 }; if (i < 0) i = 0; if (i > 3) i = 3; return k[i];",
    }, {
      "name" = "uac5GolemAC",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[4] = { 10, 8, 6, 4 }; if (i < 0) i = 0; if (i > 3) i = 3; return k[i];",
    }, {
      "name" = "uac5GolemMV",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[4] = { 12, 9, 6, 3 }; if (i < 0) i = 0; if (i > 3) i = 3; return k[i];",
    }, {
      "name" = "uac5GolemHDBase",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[4] = { 2, 3, 4, 5 }; if (i < 0) i = 0; if (i > 3) i = 3; return k[i];",
    }, {
      "name" = "uac5GolemHDBonus",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[4] = { 4, 6, 8, 10 }; if (i < 0) i = 0; if (i > 3) i = 3; return k[i];",
    }, {
      "name" = "uac5GolemHP",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[4] = { 20, 30, 40, 50 }; if (i < 0) i = 0; if (i > 3) i = 3; return k[i];",
    }, {
      "name" = "uac5GolemAT",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[4] = { 2, 1, 2, 1 }; if (i < 0) i = 0; if (i > 3) i = 3; return k[i];",
    }, {
      "name" = "uac5GolemDamage",
      "comment" = "",
      "kind" = "string array",
      "count" = 4,
      "values" = { "1-2/1-2", "1-6 plus strangulation", "1-6/1-6", "3-12" },
    }, {
      "name" = "uac5GolemSD",
      "comment" = "",
      "kind" = "string array",
      "count" = 4,
      "values" = { "immune to piercing, half from blunt", "immune to blunt, half from piercing", "+1 or better weapon, half from blunt", "+1 or better weapon, immune to blunt and piercing" },
    }, {
      "name" = "uac5GolemCarryPounds",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[4] = { 30, 40, 50, 60 }; if (i < 0) i = 0; if (i > 3) i = 3; return k[i];",
    }, {
      "name" = "uac5GolemMindlessSpellName",
      "comment" = "",
      "kind" = "string array",
      "count" = 4,
      "values" = { "charm", "fear", "hold", "sleep" },
    }, {
      "name" = "uac5RainbowApplicationName",
      "comment" = "",
      "kind" = "string array",
      "count" = 4,
      "values" = { "bow", "bridge", "elevator", "flagon" },
    }, {
      "name" = "uac5RainbowBowColorName",
      "comment" = "",
      "kind" = "string array",
      "count" = 7,
      "values" = { "red", "orange", "yellow", "green", "blue", "indigo", "violet" },
    }, {
      "name" = "uac5RainbowBowColorTarget",
      "comment" = "",
      "kind" = "string array",
      "count" = 7,
      "values" = { "fire dwellers/users", "earth elementals", "vegetable targets (incl. fungus creatures, shambling mounds, treants)", "aquatic creatures and water elementals", "aerial creatures, electricity-using creatures, and air elementals", "acid-using or poison-using creatures", "metallic or regenerating creatures" },
    }, {
      "name" = "uac5RainbowFlagonDraughtColor",
      "comment" = "",
      "kind" = "string array",
      "count" = 7,
      "values" = { "red", "orange", "yellow", "green", "blue", "indigo", "violet" },
    }, {
      "name" = "uac5RainbowFlagonDraughtEffect",
      "comment" = "",
      "kind" = "string array",
      "count" = 7,
      "values" = { "cure light wounds", "resist fire", "cure blindness", "slow poison", "cure disease", "resist cold", "remove paralysis" },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uac5AirwalkName'](), \"Air Walk (Alteration)\") != 0  or  m['uac5AirwalkComponentsVSM']() != 1  or  m['uac5AirwalkRangeTouch']() != 1  or m['uac5AirwalkCastingTimeSegments']() != 1  or  m['uac5AirwalkSaveNone']() != 1  or m['uac5AirwalkDurationTurnsBase']() != 6  or m['uac5AirwalkDurationTurnsPerLevel']() != 1  or  m['uac5AirwalkAoeOneCreature']() != 1  or  m['uac5AirwalkTreadsOnAir']() != 1  or m['uac5AirwalkAscent45Divisor']() != 2  or m['uac5AirwalkAscent60Divisor']() != 4  or m['uac5AirwalkAscentStraightDivisor']() != 8  or m['uac5AirwalkDescentStraightMultiple']() != 8  or  m['uac5AirwalkAlwaysInControl']() != 1  or  m['uac5AirwalkStopOnCopperPiece']() != 1  or  m['uac5AirwalkGustInterplay']() != 1  or m['uac5AirwalkGustIntoDivisor']() != 2  or m['uac5AirwalkGustWithMultiple']() != 2  or  m['uac5AirwalkTargetUpToGiantSize']() != 1  or  m['uac5AirwalkTrainedHorseExample']() != 1  or  m['uac5AirwalkBeastNeedsTraining']() != 1  or  m['uac5AirwalkMaterialSymbolThistledown']() != 1",
      "note" = "U1: air walk",
    }, {
      "expr" = "strcmp(m['uac5AnimateName'](), \"Animate Dead Monsters (Necromantic)\") != 0  or  m['uac5AnimateComponentsVSM']() != 1  or  m['uac5AnimateRangeLost']() != 1  or m['uac5AnimateCastingTimeSegments']() != 1  or  m['uac5AnimateDurationPermanent']() != 1  or  m['uac5AnimateSaveNone']() != 1  or  m['uac5AnimateAoeSpecial']() != 1  or m['uac5AnimateAnimatedPerTwoLevels']() != 1  or m['uac5AnimateCommandWordsMax']() != 12  or  m['uac5AnimateCfAnimateDead']() != 1  or m['uac5AnimateExampleTypeCount']() != 6  or m['uac5AnimateExampleTypeName'](i) == 0  or  m['uac5AnimateListNotExclusive']() != 1  or  m['uac5AnimateBipedalManLike']() != 1  or  m['uac5AnimateSpecimenRuleFragmentLost']() != 1  or  m['uac5AnimateCorpseMonsterZombieMM2']() != 1  or m['uac5AnimateLowHDThreshold']() != 6  or  m['uac5AnimateSkeletonHalfHDRoundedUp']() != 1  or  m['uac5AnimateNormalAttacksOnly']() != 1  or  m['uac5AnimateMaterialSymbolSpecimen']() != 1",
      "note" = "U2: animate dead monsters",
    }, {
      "expr" = "strcmp(m['uac5GolemName'](), \"Golem (Enchantment/Charm)\") != 0  or  m['uac5GolemComponentsVSM']() != 1  or m['uac5GolemRangeInches']() != 1  or m['uac5GolemCastingTimeSegments']() != 1  or  m['uac5GolemDurationSpecial']() != 1  or  m['uac5GolemSaveNone']() != 1  or  m['uac5GolemAoeSpecial']() != 1  or  m['uac5GolemRequiresPersonalConstruction']() != 1  or  m['uac5GolemRequiresPrayerSpell']() != 1  or  m['uac5GolemManShapedManSized']() != 1  or m['uac5GolemMinHeightFeet']() != 3  or m['uac5GolemMaxHeightFeet']() != 7  or m['uac5GolemMaterialCount']() != 4  or m['uac5GolemMaterialName'](i) == 0  or m['uac5GolemMinLevel'](i) != lvl[i]  or m['uac5GolemBuildHours'](i) != bh[i]  or m['uac5GolemDurationHoursPerLevel'](i) != dh[i]  or m['uac5GolemAC'](i) != ac[i]  or m['uac5GolemMV'](i) != mv[i]  or m['uac5GolemHDBase'](i) != hb[i]  or m['uac5GolemHDBonus'](i) != hn[i]  or m['uac5GolemHP'](i) != hp[i]  or m['uac5GolemAT'](i) != at[i]  or m['uac5GolemDamage'](i) == 0  or m['uac5GolemSD'](i) == 0  or m['uac5GolemCarryPounds'](i) != cp[i]  or  m['uac5GolemStrawSDDecoded']() != 1  or m['uac5GolemRopeStranglePerRound']() != 6  or  m['uac5GolemRopeStrangleUntilRelease']() != 1  or  m['uac5GolemWoodImmuneBluntPiercing']() != 1  or  m['uac5GolemLeatherHalfFromBlunt']() != 1  or  m['uac5GolemLesserGolemsName']() != 1  or  m['uac5GolemNoMinds']() != 1  or m['uac5GolemMindlessSpellExamples']() != 4  or m['uac5GolemMindlessSpellName'](i) == 0  or  m['uac5GolemSavesAsCreatorLevel']() != 1  or  m['uac5GolemCannotSpeak']() != 1  or m['uac5GolemInstructionWordsMax']() != 12",
      "note" = "U3: golem",
    }, {
      "expr" = "strcmp(m['uac5FontName'](), \"Magic Font (Divination)\") != 0  or  m['uac5FontComponentsVSM']() != 1  or  m['uac5FontComponentsDecoded']() != 1  or  m['uac5FontRangeTouch']() != 1  or m['uac5FontCastingTimeTurns']() != 5  or  m['uac5FontDurationSpecial']() != 1  or  m['uac5FontSaveNone']() != 1  or  m['uac5FontAoeSpecial']() != 1  or  m['uac5FontScryingDevice']() != 1  or  m['uac5FontRequiresGoodStanding']() != 1  or  m['uac5FontLikeCrystalBall']() != 1  or  m['uac5FontCapacityRuleFragmentLost']() != 1  or m['uac5FontRoundsPerVial']() != 1  or  m['uac5FontDurationTiedToCapacity']() != 1  or  m['uac5FontDetectionSeeMagicMirror']() != 1  or  m['uac5FontMaterialNotExhausted']() != 1",
      "note" = "U4: magic font",
    }, {
      "expr" = "strcmp(m['uac5RainbowName'](), \"Rainbow (Evocation/Alteration)\") != 0  or  m['uac5RainbowComponentsVSM']() != 1  or  m['uac5RainbowRangeLost']() != 1  or m['uac5RainbowCastingTimeSegments']() != 8  or m['uac5RainbowDurationRoundsPerLevel']() != 1  or  m['uac5RainbowSaveNone']() != 1  or  m['uac5RainbowAoeSpecial']() != 1  or  m['uac5RainbowNeedsRainbowSight']() != 1  or  m['uac5RainbowSpecialComponentFallback']() != 1  or m['uac5RainbowApplicationCount']() != 4  or m['uac5RainbowApplicationName'](i) == 0  or  m['uac5RainbowBowShimmering']() != 1  or m['uac5RainbowBowStrengthMin']() != 6  or m['uac5RainbowBowMissilePlus']() != 3  or  m['uac5RainbowBowNoNonproficiencyPenalty']() != 1  or  m['uac5RainbowBowBowClassOnly']() != 1  or m['uac5RainbowBowMissiles']() != 7  or m['uac5RainbowBowMaxShotsPerRound']() != 2  or  m['uac5RainbowBowHueLeavesPerShot']() != 1  or m['uac5RainbowBowColorCount']() != 7  or m['uac5RainbowBowColorName'](i) == 0  or m['uac5RainbowBowColorTarget'](i) == 0  or  m['uac5RainbowBowArrowAppearsNocked']() != 1  or  m['uac5RainbowBowSpectrumFallback']() != 1  or  m['uac5RainbowBridgeSevenHued']() != 1  or  m['uac5RainbowBridgeWidthFeetPerLevel']() != 1  or  m['uac5RainbowBridgeLoadHundredsPerLevel']() != 1  or m['uac5RainbowBridgeMinLengthFeet']() != 20  or m['uac5RainbowBridgeMaxLengthFeet']() != 120  or  m['uac5RainbowBridgeLastsSpellLength']() != 1  or  m['uac5RainbowBridgeOrderedOutOfExistence']() != 1  or  m['uac5RainbowBridgeTailFragmentLost']() != 1  or m['uac5RainbowElevatorRadiusFeet']() != 10  or  m['uac5RainbowElevatorArcPath']() != 1  or  m['uac5RainbowElevatorDangerOnExpiry']() != 1  or m['uac5RainbowElevatorRateInches']() != 12  or m['uac5RainbowElevatorTrailInches']() != 12  or  m['uac5RainbowFlagonSevenColored']() != 1  or m['uac5RainbowFlagonMeasures']() != 7  or  m['uac5RainbowFlagonUnusedDisappear']() != 1  or m['uac5RainbowFlagonDraughtCount']() != 7  or m['uac5RainbowFlagonDraughtColor'](i) == 0  or m['uac5RainbowFlagonDraughtEffect'](i) == 0  or m['uac5RainbowFlagonCasterLevel']() != 12  or  m['uac5RainbowFlagonEffectsPersist']() != 1  or  m['uac5RainbowMaterialSymbolAndVial']() != 1  or m['uac5RainbowDiamondMinValueGP']() != 1000  or  m['uac5RainbowDiamondNeedsBlessPrayer']() != 1  or  m['uac5RainbowOnlySymbolRemains']() != 1",
      "note" = "U5: rainbow",
    }, {
      "expr" = "strcmp(m['uac5SpikeStonesName'](), \"Spike Stones (Alteration/Enchantment)\") != 0  or  m['uac5SpikeStonesComponentsVSM']() != 1  or m['uac5SpikeStonesCastingTimeSegments']() != 6  or m['uac5SpikeStonesRangeInches']() != 3  or  m['uac5SpikeStonesSaveNone']() != 1  or m['uac5SpikeStonesDurationTurnsMin']() != 3  or m['uac5SpikeStonesDurationTurnsMax']() != 12  or m['uac5SpikeStonesDurationTurnsPerLevel']() != 1  or m['uac5SpikeStonesAoeSquareInchesPerLevel']() != 1  or m['uac5SpikeStonesSpikesPerSquareFoot']() != 1  or  m['uac5SpikeStonesNaturalAndWorked']() != 1  or  m['uac5SpikeStonesImpedesOrDamages']() != 1  or m['uac5SpikeStonesNoticeChancePct']() != 25  or m['uac5SpikeStonesDamageMin']() != 1  or m['uac5SpikeStonesDamageMax']() != 4  or  m['uac5SpikeStonesAttackAsCaster']() != 1  or  m['uac5SpikeStonesAttackOnEntryAndSteps']() != 1  or  m['uac5SpikeStonesInitialStepAlertsOnlyOnHit']() != 1  or m['uac5SpikeStonesChargeAttacksPerInch']() != 2  or m['uac5SpikeStonesOthersExtraChecks']() != 1  or m['uac5SpikeStonesPitChecks']() != 6  or m['uac5SpikeStonesPitToHitBonusPer10ft']() != 2  or m['uac5SpikeStonesPitDamageBonusPer10ft']() != 2  or  m['uac5SpikeStonesDamageInAdditionToFalling']() != 1  or  m['uac5SpikeStonesMaterialStalactites']() != 1  or m['uac5SpikeStonesStalactiteCount']() != 4",
      "note" = "U6: spike stones",
    }, {
      "expr" = "m['uastClericFragCount'](5) != 7  or strcmp(m['uastClericFragName'](5, i), n[i]) != 0  or  m['uac5MagicFontSeamChecks']() != 1  or  m['uac5SpellsPinFromProse']() != 1",
      "note" = "U7: the seam",
    } },
  "audit" = {
      "label" = "R347: the UA new cleric 5th level spells pin audit",
      "comment" = "The UA NEW CLERIC SPELLS (pp. 40-41), the 5th level - air walk (the ascent/descent ladder and the gust interplay), animate dead monsters (the per-two-levels ratio, the type examples and the zombie and skeleton treatments), golem (the four material ladders), magic font (the vial capacity rule), rainbow (the four applications, the seven colors and the seven draughts) and spike stones (the spike stone damage and pit rules). The digit-garble family decodes this round's three stat-cell 7s as 1; the rainbow bow 7-missiles and the golem 7-foot ceiling stay genuine (corroborated); the R341 continued table prints seven 5th-level fragments - magic font seam-checks, the rest pin from the prose. The item stays open (the 6th-7th levels).",
    },
}
