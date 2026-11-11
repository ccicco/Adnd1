-- ua362: promoted from the round R362 pin headers (the the UA new magic-user 8th and 9th level spells);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 362,
  "prefix" = "ua362",
  "banner" = {
      "title" = "the UA new magic-user 8th and 9th level spells",
      "provenance" = "rules/ua/uamuspells8.h (the The UA NEW MAGIC-USER SPELLS (pp. 71-74) pins, R362: the): 8th-level spell descriptions - binding, demand, the Otiluke telekinetic sphere and sink.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - no digit-garble 7s print in this level's cells; the sink chant of 4 segments and casting of 8 segments both pin clean from the prose ladder. - the binding range and duration cells are lost (the range prints a bare ge fragment, the duration cell never prints) - holes pending the PDF; the casting Special and the save Special pin from the stat block. - the demand components cell garbles (a bare sign fragment) - the V, S, M pin from the prose; the material list scrambles (the pair of open containers and the copper wire) - flagged pending the PDF. - the Otiluke telekinetic sphere name header garbles - the Telekinetic word and the school tail are lost; the name pins from the gap item list and the prose (the same as the 4th-level Otiluke resilient sphere). The range cell prints a bare hash fragment - a hole pending the PDF; the weightless fraction garbles (the ss fragment) and the range-of-control number is lost - flagged pending the PDF, not pinned as data. - the sink level cell is lost (a bare 3 fragment prints above the casting time) - the level pins from the section heading; the duration Special displaces into the stat scramble; the area unit garbles (the asterisk for feet) - decoded as one cubic foot per level, flagged pending the PDF. - the R342 MU table seam prints 11 8th-level names - demand at index 0 and sink at index 8 seam-check; binding and the telekinetic sphere are absent, asserted in the audit.  rules/ua/uamuspells9.h (the The UA NEW MAGIC-USER SPELLS (pp. 74-77) pins, R362: the): 9th-level spell descriptions - crystalbrittle, succor, energy drain and the Mordenkainen disjunction.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the crystalbrittle casting head loses the Casting word (a bare Time: 9 segments) - pinned as printed; the components cell garbles the sign (V, S) - the M pins from the stat pattern, flagged pending the PDF. - the succor stat head prints only the Duration and Area cells; the Components, Casting Time and Saving Throw cells print in an interleaved tail after the prose - the casting garbles (a 17-to-4 print; the leading fragment reads as 1, flagged pending the PDF). The level cell is lost - the level pins from the section heading. The spell is reversible. - the energy drain stat block scrambles - the 3 segments displace above the Casting Time line, and the duration and save cells never print - holes pending the PDF; the material sentence scrambles the spectre word (an essence-of fragment) and the three-segments phrase - flagged pending the PDF. - the Mordenkainen disjunction name header garbles to a bare possessive-fragment; the name pins from the gap item list and the prose. The school is lost pending the PDF; the components cell prints bare - a hole pending the PDF. - the R342 MU table seam prints only two 9th-level names (Prismatic Sphere, Shape Change) - none of the new names seam-checks, asserted in the audit.",
    },
  "consts" = { {
      "name" = "uam8BindName",
      "value" = "Binding (Enchantment - Evocation)",
      "comment" = "---- binding (Enchantment - Evocation) ----",
    }, {
      "name" = "uam8BindLevel",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam8BindGemGpPerHitDie",
      "value" = 1000,
      "comment" = "A diamond or corundum gem of great size - 1,000 gp value per hit die of the subject.",
    }, {
      "name" = "uam8BindNoSaveCasterLevelMultiple",
      "value" = 2,
      "comment" = "No save applies while the caster level(s) are at least twice the subject's hit dice.",
    }, {
      "name" = "uam8BindAssistantMax",
      "value" = 6,
      "comment" = "No more than six other magic-users can assist.",
    }, {
      "name" = "uam8BindChainingYearsPerLevel",
      "value" = 1,
      "comment" = "Chaining: restraints generating an antipathy affecting all who approach except the caster; up to one year per caster level; the subject stays within the diagram.",
    }, {
      "name" = "uam8BindSlumberYearsPerLevel",
      "value" = 1,
      "comment" = "Slumber: a comatose sleep of up to one year per caster level.",
    }, {
      "name" = "uam8BindBoundSlumberMonthsPerLevel",
      "value" = 1,
      "comment" = "Bound slumber: chaining plus slumber, up to one month per caster level.",
    }, {
      "name" = "uam8BindMinimusHeightInches",
      "value" = 1,
      "comment" = "Minimus containment: shrunk to one inch or less, held within the hedged prison of a gem or similar object.",
    }, {
      "name" = "uam8BindSaveAdjChaining",
      "value" = 0,
      "comment" = "The save ladder: chaining normal, slumber +1, bound slumber +2, hedged prison +3, metamorphosis +4, minimus containment +5.",
    }, {
      "name" = "uam8BindSaveAdjSlumber",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam8BindSaveAdjBoundSlumber",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam8BindSaveAdjHedgedPrison",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam8BindSaveAdjMetamorphosis",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam8BindSaveAdjMinimus",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uam8BindAdjDolor",
      "value" = -1,
      "comment" = "A subject weakened by dolor or torment adjusts by -1 and -2 respectively, -4 for both in successive combination.",
    }, {
      "name" = "uam8BindAdjTorment",
      "value" = -2,
      "comment" = "",
    }, {
      "name" = "uam8BindAdjBoth",
      "value" = -4,
      "comment" = "",
    }, {
      "name" = "uam8BindRenewalSaveAfterYears",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam8DemandName",
      "value" = "Demand (Evocation - Enchantment/Charm)",
      "comment" = "---- demand (Evocation - Enchantment/Charm) ----",
    }, {
      "name" = "uam8DemandLevel",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam8DemandCastingTimeTurns",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam8OtilukeName",
      "value" = "Otiluke's Telekinetic Sphere",
      "comment" = "---- the Otiluke telekinetic sphere ---- The name header garbles - the Telekinetic word and the school tail are lost; the name pins from the gap item list and the prose.",
    }, {
      "name" = "uam8OtilukeLevel",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam8OtilukeCastingTimeSegments",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam8OtilukeDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam8OtilukeLiftPoundsMax",
      "value" = 5000,
      "comment" = "A subject of up to 5,000 pounds can be telekinetically lifted in the sphere.",
    }, {
      "name" = "uam8SinkName",
      "value" = "Sink (Enchantment - Alteration)",
      "comment" = "---- sink (Enchantment - Alteration) ----",
    }, {
      "name" = "uam8SinkLevel",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam8SinkChantSegments",
      "value" = 4,
      "comment" = "The caster must chant the spell for 4 segments without interruption.",
    }, {
      "name" = "uam8SinkCastingTimeSegments",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam8SinkAoeCuFtPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam8SinkCeaseTurns",
      "value" = 4,
      "comment" = "If the caster ceases, the dweomer loses power in 4 turns and the subject returns to normal.",
    }, {
      "name" = "uam8SinkSinkingStartSegment",
      "value" = 5,
      "comment" = "Proceeding, the subject sinks: a quarter of its height on the 5th segment, another on the 6th, another on the 7th, totally sunken on the 8th.",
    }, {
      "name" = "uam8SinkSinkingQuarterPerSegment",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam8SinkTotallySunkenSegment",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam9CrystalName",
      "value" = "Crystalbrittle (Alteration)",
      "comment" = "---- crystalbrittle (Alteration) ----",
    }, {
      "name" = "uam9CrystalLevel",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uam9CrystalCastingTimeSegments",
      "value" = 9,
      "comment" = "The casting head loses the Casting word - a bare Time: 9 segments; pinned as printed.",
    }, {
      "name" = "uam9CrystalAoeCuFtPerLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam9CrystalSwordSavePct",
      "value" = 10,
      "comment" = "Items save by their magical bonus value or protection: a +1/+3 sword gets a 10% chance (the average of the two plusses).",
    }, {
      "name" = "uam9CrystalArmorSavePct",
      "value" = 25,
      "comment" = "+5 magic armor gets a 25% chance to be unaffected.",
    }, {
      "name" = "uam9CrystalGolemSavePct",
      "value" = 15,
      "comment" = "An iron golem gets a 15% chance (hit only by +3 or better weapons).",
    }, {
      "name" = "uam9CrystalArtifactSavePct",
      "value" = 95,
      "comment" = "Artifacts and relics of metal have a 95% chance to be unaffected.",
    }, {
      "name" = "uam9SuccorName",
      "value" = "Succor (Alteration - Enchantment)",
      "comment" = "---- succor (Alteration - Enchantment), reversible ----",
    }, {
      "name" = "uam9SuccorLevel",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uam9SuccorCastingTimeDaysMin",
      "value" = 1,
      "comment" = "The casting garbles - a 17-to-4 days print; the leading fragment reads as 1, flagged pending the PDF.",
    }, {
      "name" = "uam9SuccorCastingTimeDaysMax",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam9SuccorGemGpMin",
      "value" = 5000,
      "comment" = "The material component is gem material of not less than 5,000 gp value; faceted or not is immaterial.",
    }, {
      "name" = "uam9EnergyName",
      "value" = "Energy Drain (Evocation)",
      "comment" = "---- energy drain (Evocation) ----",
    }, {
      "name" = "uam9EnergyLevel",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uam9EnergyCastingTimeSegments",
      "value" = 3,
      "comment" = "The stat block scrambles - the 3 segments displace above the Casting Time line; pinned as printed.",
    }, {
      "name" = "uam9EnergyLevelsDrained",
      "value" = 2,
      "comment" = "A touch (equal to a hit in melee) drains two energy levels from any living creature, as if struck by a spectre.",
    }, {
      "name" = "uam9EnergyHitDiceDrained",
      "value" = 2,
      "comment" = "A monster loses two hit dice permanently - hit points and attack ability both.",
    }, {
      "name" = "uam9EnergyCasterRiskPct",
      "value" = 5,
      "comment" = "A 5% chance (1 in 20) that the caster is also drained of one energy level as the victim loses two.",
    }, {
      "name" = "uam9EnergyCasterRiskLevels",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam9DisjunctionName",
      "value" = "Mordenkainen's Disjunction",
      "comment" = "---- the Mordenkainen disjunction ---- The name header garbles to a bare possessive fragment; the name pins from the gap item list and the prose. The school is lost pending the PDF.",
    }, {
      "name" = "uam9DisjunctionLevel",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uam9DisjunctionRangeZero",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uam9DisjunctionCastingTimeSegments",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uam9DisjunctionAoeRadiusInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam9DisjunctionArtifactPctPerLevel",
      "value" = 1,
      "comment" = "Even artifacts and relics are subject to the disjunction - a 1% chance per caster level of actually affecting such powerful items.",
    }, {
      "name" = "uam9DisjunctionArtifactAttentionPct",
      "value" = 95,
      "comment" = "Destroying artifacts is dangerous business - 95% likely to attract the attention of some powerful being with an interest or connection with the device.",
    }, {
      "name" = "uam9DisjunctionArtifactDestroySaveAdj",
      "value" = -4,
      "comment" = "If an artifact is destroyed, the casting magic-user must save versus spell at -4 or permanently lose all spell casting abilities.",
    } },
  "bools" = { {
      "name" = "uam8BindComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8BindLevelCellLost",
      "value" = true,
      "comment" = "The level cell is lost - the level pins from the section heading.",
    }, {
      "name" = "uam8BindRangeCellLost",
      "value" = true,
      "comment" = "The range cell prints a bare ge fragment - a hole pending the PDF.",
    }, {
      "name" = "uam8BindCastingTimeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8BindDurationCellLost",
      "value" = true,
      "comment" = "The duration cell never prints - a hole pending the PDF; the forms below pin their own durations.",
    }, {
      "name" = "uam8BindSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8BindAoeOneCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8BindCapturesLowerPlanesCreature",
      "value" = true,
      "comment" = "The spell captures a creature from the lower planes already confined by a restraining diagram; the duration depends on the form, the caster level(s) and the length of the utterance.",
    }, {
      "name" = "uam8BindRequiresRestrainingDiagram",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8BindContinuousChantFromScroll",
      "value" = true,
      "comment" = "The utterance: a continuous chant read from a scroll or book page, gestures appropriate to the form, and the materials.",
    }, {
      "name" = "uam8BindGesturesMatchTheForm",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8BindChainIronSilverNickel",
      "value" = true,
      "comment" = "The material chains: iron for demonkind, silver for diabolical creatures, nickel for the minions of Hades.",
    }, {
      "name" = "uam8BindMaterialSoporificHerbs",
      "value" = true,
      "comment" = "Soporific herbs of the rarest sort.",
    }, {
      "name" = "uam8BindMaterialVellumOrStatuette",
      "value" = true,
      "comment" = "A vellum depiction or carved statuette of the subject.",
    }, {
      "name" = "uam8BindSaveModifiedByFormAndRatio",
      "value" = true,
      "comment" = "Otherwise the subject saves versus spell, modified by the form and the ratio of caster level(s) to hit dice.",
    }, {
      "name" = "uam8BindAssistantNinthPlusThird",
      "value" = true,
      "comment" = "The principal caster's level is augmented by one-third of the level of each assistant of 9th or higher level.",
    }, {
      "name" = "uam8BindAssistantFourthToEighthOne",
      "value" = true,
      "comment" = "An additional level per assistant of 4th to 8th level.",
    }, {
      "name" = "uam8BindChainingAntipathy",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8BindChainingStaysInDiagram",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8BindHedgedPrisonUntilBroken",
      "value" = true,
      "comment" = "Hedged prison: the subject is confined within an area it may not wander from until the hedge is broken.",
    }, {
      "name" = "uam8BindMetamorphosisNoncorporeal",
      "value" = true,
      "comment" = "Metamorphosis: a noncorporeal form save for the head or face; permanent until a prescribed act frees it.",
    }, {
      "name" = "uam8BindMetamorphosisUntilPrescribedAct",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8BindMinimusHeldInGem",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8BindFormsRadiateFaintAura",
      "value" = true,
      "comment" = "The minimus, metamorphosis and hedged prison subjects radiate a very faint aura of magic.",
    }, {
      "name" = "uam8BindSaveSuccessBurstsBonds",
      "value" = true,
      "comment" = "A successful save bursts the bonds; the subject does as it pleases.",
    }, {
      "name" = "uam8BindFirstThreeRenewable",
      "value" = true,
      "comment" = "The first three forms can be renewed - the subject gets no chance to break the bonds; after one year it gains a save versus spell, and a success breaks the binding.",
    }, {
      "name" = "uam8BindWeakenedRenewalNormalSave",
      "value" = true,
      "comment" = "A weakened chaining or slumber (contact or magical touch attempts) allows a normal save on the renewal.",
    }, {
      "name" = "uam8DemandComponentsCellGarbled",
      "value" = true,
      "comment" = "The components cell garbles - a bare sign fragment; the V, S, M pin from the prose and the material list.",
    }, {
      "name" = "uam8DemandComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8DemandRangeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8DemandDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8DemandSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8DemandAoeOneCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8DemandSameAsSending",
      "value" = true,
      "comment" = "The spell is the same as a sending spell, except the message may contain a suggestion; a failed save versus spell means the subject carries out the demand.",
    }, {
      "name" = "uam8DemandCarriesSuggestion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8DemandFailedSaveCarriesOut",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8DemandImpossibleNoSave",
      "value" = true,
      "comment" = "An impossible or incongruous message gets no save.",
    }, {
      "name" = "uam8DemandMaterialCopperWire",
      "value" = true,
      "comment" = "The materials: a pair of small open containers connected by a thin copper wire, and a small part of the subject - a hair, bit of nail, etc. The container list scrambles in the print - flagged pending the PDF.",
    }, {
      "name" = "uam8DemandMaterialSubjectPart",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8DemandMaterialListScrambled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8OtilukeNameHeaderGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8OtilukeSchoolLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8OtilukeRangeCellLost",
      "value" = true,
      "comment" = "The range cell prints a bare hash fragment - a hole pending the PDF.",
    }, {
      "name" = "uam8OtilukeSaveNeg",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8OtilukeAoeFeetPerLevel",
      "value" = true,
      "comment" = "The area: a 1-foot diameter sphere per level of the caster.",
    }, {
      "name" = "uam8OtilukeSameAsResilientSphere",
      "value" = true,
      "comment" = "The spell is exactly the same as the 4th-level resilient sphere plus a virtually weightless interior - the weightless fraction garbles (the ss fragment), flagged pending the PDF.",
    }, {
      "name" = "uam8OtilukeInteriorWeightless",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8OtilukeWeightFractionGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8OtilukeRolledWithoutEffort",
      "value" = true,
      "comment" = "Even beyond 5,000 pounds englobed, the essential weight is a fraction of actual - the orb can be rolled without exceptional effort.",
    }, {
      "name" = "uam8OtilukeControlRangeNumberLost",
      "value" = true,
      "comment" = "The range-of-control number is lost in the print - a hole pending the PDF, not pinned as data.",
    }, {
      "name" = "uam8OtilukeControlPerLevel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8OtilukeFallingHarmless",
      "value" = true,
      "comment" = "Rapid motion or falling within the field is relatively harmless - but the globe vanishing high above a hard surface is disastrous.",
    }, {
      "name" = "uam8OtilukeVanishHighDangerous",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8OtilukeMaterialBarMagnets",
      "value" = true,
      "comment" = "Beyond the resilient sphere materials, the caster needs a pair of small bar magnets.",
    }, {
      "name" = "uam8SinkLevelCellLost",
      "value" = true,
      "comment" = "The level cell is lost - a bare 3 fragment prints above the casting time; the level pins from the section heading.",
    }, {
      "name" = "uam8SinkDurationSpecial",
      "value" = true,
      "comment" = "The duration Special displaces into the stat scramble - pinned as printed.",
    }, {
      "name" = "uam8SinkSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8SinkAoeOneCreatureOrObject",
      "value" = true,
      "comment" = "The area: one creature, or one object of 1 cubic foot per level - the unit garbles (the asterisk fragment), flagged pending the PDF.",
    }, {
      "name" = "uam8SinkAoeUnitGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8SinkRootsUnlessSave",
      "value" = true,
      "comment" = "At the chant's juncture the subject roots to the spot unless it saves - versus spell for a creature, versus disintegration for a magical object.",
    }, {
      "name" = "uam8SinkCreatureSaveVsSpell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8SinkMagicObjectSaveVsDisintegration",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8SinkMagicalPropertiesDefined",
      "value" = true,
      "comment" = "Magical properties: DMG magic items, enchanted or magical-origin items, and items with magic-type or similar spells upon them.",
    }, {
      "name" = "uam8SinkNonMagicNoSave",
      "value" = true,
      "comment" = "Non-magical items are not entitled to a save.",
    }, {
      "name" = "uam8SinkSameDensityAsSurface",
      "value" = true,
      "comment" = "A failed save also makes the subject the same density as the surface it stands on.",
    }, {
      "name" = "uam8SinkLivingStasisUnharmed",
      "value" = true,
      "comment" = "The entombment places a living subject in stasis without harm; non-living subjects exist undamaged in the surface.",
    }, {
      "name" = "uam8SinkNonLivingUndamaged",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam8SinkDepthEqualsHeight",
      "value" = true,
      "comment" = "The upper extremity rests as far beneath the surface as the subject has height - a 6-foot subject 6 feet beneath, a 60-foot subject 60 feet below.",
    }, {
      "name" = "uam8SinkGroundRemovalBreaks",
      "value" = true,
      "comment" = "Removing the ground around the subject breaks the spell and returns it to normal - though it will not rise up.",
    }, {
      "name" = "uam8SinkRecoverySpellsHelpful",
      "value" = true,
      "comment" = "Dig, transmute rock to mud, and freedom (the reverse of imprisonment) do not harm the subject and help recover it in many cases.",
    }, {
      "name" = "uam8SinkDetectMagicFaintDweomer",
      "value" = true,
      "comment" = "A detect magic over the sunk area reveals a faint dweomer of undefinable nature, even beyond detection range; within range it notes enchantment-alteration magic.",
    }, {
      "name" = "uam8SinkDetectNotesEnchantAlteration",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9CrystalComponentsVSM",
      "value" = true,
      "comment" = "The components cell garbles the sign for the M - pinned as V, S, M, flagged pending the PDF.",
    }, {
      "name" = "uam9CrystalComponentsCellGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9CrystalCastingHeadLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9CrystalRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9CrystalDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9CrystalSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9CrystalTurnsMetalToCrystal",
      "value" = true,
      "comment" = "The dweomer turns metal - as soft as gold or as hard as adamantite - into a crystalline substance as brittle and fragile as crystal.",
    }, {
      "name" = "uam9CrystalShattersByBlow",
      "value" = true,
      "comment" = "A sword, metal shield, metal armor, or even an iron golem becomes delicate, glass-like material easily shattered by any forceful blow.",
    }, {
      "name" = "uam9CrystalReversibleOnlyByWish",
      "value" = true,
      "comment" = "The change is unalterable short of a wish - dispel magic will not reverse it.",
    }, {
      "name" = "uam9CrystalTouchRequiresHit",
      "value" = true,
      "comment" = "The caster must physically touch the target - equal to a hit in combat if worn, wielded, or a monster.",
    }, {
      "name" = "uam9CrystalSingleItemPerCasting",
      "value" = true,
      "comment" = "A single metal item is affected per casting - a worn suit of armor changes but the shield does not, or vice versa.",
    }, {
      "name" = "uam9CrystalDestroyedByWeightyBlow",
      "value" = true,
      "comment" = "Unprotected items are shattered and permanently destroyed if struck by a normal blow from a metal tool or any weighty weapon, including a staff.",
    }, {
      "name" = "uam9SuccorReversible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9SuccorLevelCellLost",
      "value" = true,
      "comment" = "The level cell is lost - the level pins from the section heading.",
    }, {
      "name" = "uam9SuccorStatTailInterleaved",
      "value" = true,
      "comment" = "The stat head prints only the Duration and Area cells; the Components, Casting Time and Save print in an interleaved tail after the prose.",
    }, {
      "name" = "uam9SuccorComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9SuccorCastingPrintGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9SuccorDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9SuccorSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9SuccorAoeOneIndividual",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9SuccorSameAsClericSeventh",
      "value" = true,
      "comment" = "The spell is the same as the 7th-level cleric spell of the same name.",
    }, {
      "name" = "uam9SuccorTeleportsWithoutError",
      "value" = true,
      "comment" = "The magic-user version teleports without error the individual who breaks the object and speaks the command word - the R361 teleport exception.",
    }, {
      "name" = "uam9SuccorReverseBringsArchmage",
      "value" = true,
      "comment" = "The reverse likewise brings the archmage to the presence of the individual.",
    }, {
      "name" = "uam9SuccorArchmageHasNoChoice",
      "value" = true,
      "comment" = "Unlike the cleric spell, the summoned archmage has no choice but to answer - making this version rare indeed.",
    }, {
      "name" = "uam9SuccorInterferenceIrrevocableLoss",
      "value" = true,
      "comment" = "Interference causes irrevocable loss of the individual or spell caster involved in the succor - the sentence scrambles, flagged pending the PDF.",
    }, {
      "name" = "uam9SuccorInterferenceSentenceScrambled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9SuccorEnchantedOncePerMonth",
      "value" = true,
      "comment" = "The components can only be enchanted once per month - usually on the night of a clear, full moon - set then for the type of succor and its final destination.",
    }, {
      "name" = "uam9SuccorSetOnFullMoonNight",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9SuccorSetForTypeAndDestination",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9EnergyComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9EnergyCastingCellDisplaced",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9EnergyRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9EnergyDurationCellLost",
      "value" = true,
      "comment" = "The duration and save cells never print - holes pending the PDF, not pinned as data.",
    }, {
      "name" = "uam9EnergySaveCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9EnergyAoeOneCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9EnergyNegativePlaneChannel",
      "value" = true,
      "comment" = "The spell opens a channel between the caster's plane and the Negative Material Plane, the caster becoming the conductor between the two.",
    }, {
      "name" = "uam9EnergyCasterIsConductor",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9EnergyAsSpectre",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9EnergyCharacterLossPermanent",
      "value" = true,
      "comment" = "A character loses levels, hit dice, hit points and abilities permanently - until regained through adventuring, if applicable.",
    }, {
      "name" = "uam9EnergyMaterialSpectreOrVampireDust",
      "value" = true,
      "comment" = "The material: essence of spectre or vampire dust - the print loses the spectre word, flagged pending the PDF.",
    }, {
      "name" = "uam9EnergyMaterialWordLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9EnergyMaterialSentenceScrambled",
      "value" = true,
      "comment" = "The three-segments phrase scrambles into the material sentence - flagged pending the PDF.",
    }, {
      "name" = "uam9EnergyTriggeringWord",
      "value" = true,
      "comment" = "The component is cast forth; upon touching the victim the caster speaks the triggering word, and the dweomer takes effect instantly.",
    }, {
      "name" = "uam9EnergyZeroLevelJujuZombies",
      "value" = true,
      "comment" = "Humans or humanoids brought to zero energy level become juju zombies.",
    }, {
      "name" = "uam9DisjunctionNameHeaderGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9DisjunctionSchoolLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9DisjunctionComponentsCellLost",
      "value" = true,
      "comment" = "The components cell prints bare - a hole pending the PDF, not pinned as data.",
    }, {
      "name" = "uam9DisjunctionDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9DisjunctionSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9DisjunctionDisjoinsAllMagic",
      "value" = true,
      "comment" = "All magic and magic items within the radius are disjoined, except those on the person of or being touched by the spell caster.",
    }, {
      "name" = "uam9DisjunctionCasterPersonExempt",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9DisjunctionSpoilsSpellsBeingCast",
      "value" = true,
      "comment" = "Spells being cast are separated into their individual components and the effect spoiled, as does a dispel magic.",
    }, {
      "name" = "uam9DisjunctionItemsSaveOrBecomeNormal",
      "value" = true,
      "comment" = "Items must save - versus spell if actually cast upon a creature, versus dispel magic otherwise - or be turned into normal items.",
    }, {
      "name" = "uam9DisjunctionItemSaveVsSpellIfCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam9DisjunctionAffectsAllItemClasses",
      "value" = true,
      "comment" = "Thus all potions, scrolls, rings, rods et al, miscellaneous magic items, artifacts and relics, arms and armor, swords and miscellaneous weapons within 3 inches of the caster can possibly lose all their magical properties.",
    }, {
      "name" = "uam9DisjunctionCasterMayLoseCasting",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uam8BindName'](), \"Binding (Enchantment - Evocation)\") != 0  or  m['uam8BindComponentsVSM']() != 1  or  m['uam8BindLevelCellLost']() != 1  or m['uam8BindLevel']() != 8  or  m['uam8BindRangeCellLost']() != 1  or  m['uam8BindCastingTimeSpecial']() != 1  or  m['uam8BindDurationCellLost']() != 1  or  m['uam8BindSaveSpecial']() != 1  or  m['uam8BindAoeOneCreature']() != 1  or  m['uam8BindCapturesLowerPlanesCreature']() != 1  or  m['uam8BindRequiresRestrainingDiagram']() != 1  or  m['uam8BindContinuousChantFromScroll']() != 1  or  m['uam8BindGesturesMatchTheForm']() != 1  or  m['uam8BindChainIronSilverNickel']() != 1  or  m['uam8BindMaterialSoporificHerbs']() != 1  or m['uam8BindGemGpPerHitDie']() != 1000  or  m['uam8BindMaterialVellumOrStatuette']() != 1  or m['uam8BindNoSaveCasterLevelMultiple']() != 2  or  m['uam8BindSaveModifiedByFormAndRatio']() != 1  or  m['uam8BindAssistantNinthPlusThird']() != 1  or  m['uam8BindAssistantFourthToEighthOne']() != 1  or m['uam8BindAssistantMax']() != 6  or m['uam8BindChainingYearsPerLevel']() != 1  or  m['uam8BindChainingAntipathy']() != 1  or  m['uam8BindChainingStaysInDiagram']() != 1  or m['uam8BindSlumberYearsPerLevel']() != 1  or m['uam8BindBoundSlumberMonthsPerLevel']() != 1  or  m['uam8BindHedgedPrisonUntilBroken']() != 1  or  m['uam8BindMetamorphosisNoncorporeal']() != 1  or  m['uam8BindMetamorphosisUntilPrescribedAct']() != 1  or m['uam8BindMinimusHeightInches']() != 1  or  m['uam8BindMinimusHeldInGem']() != 1  or  m['uam8BindFormsRadiateFaintAura']() != 1  or m['uam8BindSaveAdjChaining']() != 0  or m['uam8BindSaveAdjSlumber']() != 1  or m['uam8BindSaveAdjBoundSlumber']() != 2  or m['uam8BindSaveAdjHedgedPrison']() != 3  or m['uam8BindSaveAdjMetamorphosis']() != 4  or m['uam8BindSaveAdjMinimus']() != 5  or m['uam8BindAdjDolor']() != -1  or m['uam8BindAdjTorment']() != -2  or m['uam8BindAdjBoth']() != -4  or  m['uam8BindSaveSuccessBurstsBonds']() != 1  or  m['uam8BindFirstThreeRenewable']() != 1  or m['uam8BindRenewalSaveAfterYears']() != 1  or  m['uam8BindWeakenedRenewalNormalSave']() != 1",
      "note" = "U1: binding",
    }, {
      "expr" = "strcmp(m['uam8DemandName'](), \"Demand (Evocation - Enchantment/Charm)\") != 0  or  m['uam8DemandComponentsCellGarbled']() != 1  or  m['uam8DemandComponentsVSM']() != 1  or m['uam8DemandLevel']() != 8  or  m['uam8DemandRangeSpecial']() != 1  or m['uam8DemandCastingTimeTurns']() != 1  or  m['uam8DemandDurationSpecial']() != 1  or  m['uam8DemandSaveSpecial']() != 1  or  m['uam8DemandAoeOneCreature']() != 1  or  m['uam8DemandSameAsSending']() != 1  or  m['uam8DemandCarriesSuggestion']() != 1  or  m['uam8DemandFailedSaveCarriesOut']() != 1  or  m['uam8DemandImpossibleNoSave']() != 1  or  m['uam8DemandMaterialCopperWire']() != 1  or  m['uam8DemandMaterialSubjectPart']() != 1  or  m['uam8DemandMaterialListScrambled']() != 1",
      "note" = "U2: demand",
    }, {
      "expr" = "strcmp(m['uam8OtilukeName'](), \"Otiluke's Telekinetic Sphere\") != 0  or  m['uam8OtilukeNameHeaderGarbled']() != 1  or  m['uam8OtilukeSchoolLost']() != 1  or m['uam8OtilukeLevel']() != 8  or  m['uam8OtilukeRangeCellLost']() != 1  or m['uam8OtilukeCastingTimeSegments']() != 4  or  m['uam8OtilukeSaveNeg']() != 1  or m['uam8OtilukeDurationRoundsPerLevel']() != 1  or  m['uam8OtilukeAoeFeetPerLevel']() != 1  or  m['uam8OtilukeSameAsResilientSphere']() != 1  or  m['uam8OtilukeInteriorWeightless']() != 1  or  m['uam8OtilukeWeightFractionGarbled']() != 1  or m['uam8OtilukeLiftPoundsMax']() != 5000  or  m['uam8OtilukeRolledWithoutEffort']() != 1  or  m['uam8OtilukeControlRangeNumberLost']() != 1  or  m['uam8OtilukeControlPerLevel']() != 1  or  m['uam8OtilukeFallingHarmless']() != 1  or  m['uam8OtilukeVanishHighDangerous']() != 1  or  m['uam8OtilukeMaterialBarMagnets']() != 1",
      "note" = "U3: the Otiluke telekinetic sphere",
    }, {
      "expr" = "strcmp(m['uam8SinkName'](), \"Sink (Enchantment - Alteration)\") != 0  or  m['uam8SinkLevelCellLost']() != 1  or m['uam8SinkLevel']() != 8  or m['uam8SinkChantSegments']() != 4  or m['uam8SinkCastingTimeSegments']() != 8  or  m['uam8SinkDurationSpecial']() != 1  or  m['uam8SinkSaveSpecial']() != 1  or  m['uam8SinkAoeOneCreatureOrObject']() != 1  or m['uam8SinkAoeCuFtPerLevel']() != 1  or  m['uam8SinkAoeUnitGarbled']() != 1  or  m['uam8SinkRootsUnlessSave']() != 1  or  m['uam8SinkCreatureSaveVsSpell']() != 1  or  m['uam8SinkMagicObjectSaveVsDisintegration']() != 1  or  m['uam8SinkMagicalPropertiesDefined']() != 1  or  m['uam8SinkNonMagicNoSave']() != 1  or  m['uam8SinkSameDensityAsSurface']() != 1  or m['uam8SinkCeaseTurns']() != 4  or m['uam8SinkSinkingStartSegment']() != 5  or m['uam8SinkSinkingQuarterPerSegment']() != 1  or m['uam8SinkTotallySunkenSegment']() != 8  or  m['uam8SinkLivingStasisUnharmed']() != 1  or  m['uam8SinkNonLivingUndamaged']() != 1  or  m['uam8SinkDepthEqualsHeight']() != 1  or  m['uam8SinkGroundRemovalBreaks']() != 1  or  m['uam8SinkRecoverySpellsHelpful']() != 1  or  m['uam8SinkDetectMagicFaintDweomer']() != 1  or  m['uam8SinkDetectNotesEnchantAlteration']() != 1",
      "note" = "U4: sink",
    }, {
      "expr" = "strcmp(m['uam9CrystalName'](), \"Crystalbrittle (Alteration)\") != 0  or  m['uam9CrystalComponentsVSM']() != 1  or  m['uam9CrystalComponentsCellGarbled']() != 1  or m['uam9CrystalLevel']() != 9  or m['uam9CrystalCastingTimeSegments']() != 9  or  m['uam9CrystalCastingHeadLost']() != 1  or  m['uam9CrystalRangeTouch']() != 1  or  m['uam9CrystalDurationPermanent']() != 1  or  m['uam9CrystalSaveSpecial']() != 1  or m['uam9CrystalAoeCuFtPerLevel']() != 2  or  m['uam9CrystalTurnsMetalToCrystal']() != 1  or  m['uam9CrystalShattersByBlow']() != 1  or  m['uam9CrystalReversibleOnlyByWish']() != 1  or  m['uam9CrystalTouchRequiresHit']() != 1  or  m['uam9CrystalSingleItemPerCasting']() != 1  or m['uam9CrystalSwordSavePct']() != 10  or m['uam9CrystalArmorSavePct']() != 25  or m['uam9CrystalGolemSavePct']() != 15  or m['uam9CrystalArtifactSavePct']() != 95  or  m['uam9CrystalDestroyedByWeightyBlow']() != 1",
      "note" = "U5: crystalbrittle",
    }, {
      "expr" = "strcmp(m['uam9SuccorName'](), \"Succor (Alteration - Enchantment)\") != 0  or  m['uam9SuccorReversible']() != 1  or  m['uam9SuccorLevelCellLost']() != 1  or m['uam9SuccorLevel']() != 9  or  m['uam9SuccorStatTailInterleaved']() != 1  or  m['uam9SuccorComponentsVSM']() != 1  or m['uam9SuccorCastingTimeDaysMin']() != 1  or m['uam9SuccorCastingTimeDaysMax']() != 4  or  m['uam9SuccorCastingPrintGarbled']() != 1  or  m['uam9SuccorDurationSpecial']() != 1  or  m['uam9SuccorSaveNone']() != 1  or  m['uam9SuccorAoeOneIndividual']() != 1  or  m['uam9SuccorSameAsClericSeventh']() != 1  or  m['uam9SuccorTeleportsWithoutError']() != 1  or  m['uam9SuccorReverseBringsArchmage']() != 1  or  m['uam9SuccorArchmageHasNoChoice']() != 1  or  m['uam9SuccorInterferenceIrrevocableLoss']() != 1  or  m['uam9SuccorInterferenceSentenceScrambled']() != 1  or m['uam9SuccorGemGpMin']() != 5000  or  m['uam9SuccorEnchantedOncePerMonth']() != 1  or  m['uam9SuccorSetOnFullMoonNight']() != 1  or  m['uam9SuccorSetForTypeAndDestination']() != 1",
      "note" = "U6: succor",
    }, {
      "expr" = "strcmp(m['uam9EnergyName'](), \"Energy Drain (Evocation)\") != 0  or  m['uam9EnergyComponentsVSM']() != 1  or m['uam9EnergyLevel']() != 9  or m['uam9EnergyCastingTimeSegments']() != 3  or  m['uam9EnergyCastingCellDisplaced']() != 1  or  m['uam9EnergyRangeTouch']() != 1  or  m['uam9EnergyDurationCellLost']() != 1  or  m['uam9EnergySaveCellLost']() != 1  or  m['uam9EnergyAoeOneCreature']() != 1  or  m['uam9EnergyNegativePlaneChannel']() != 1  or  m['uam9EnergyCasterIsConductor']() != 1  or m['uam9EnergyLevelsDrained']() != 2  or  m['uam9EnergyAsSpectre']() != 1  or m['uam9EnergyHitDiceDrained']() != 2  or  m['uam9EnergyCharacterLossPermanent']() != 1  or  m['uam9EnergyMaterialSpectreOrVampireDust']() != 1  or  m['uam9EnergyMaterialWordLost']() != 1  or  m['uam9EnergyMaterialSentenceScrambled']() != 1  or  m['uam9EnergyTriggeringWord']() != 1  or m['uam9EnergyCasterRiskPct']() != 5  or m['uam9EnergyCasterRiskLevels']() != 1  or  m['uam9EnergyZeroLevelJujuZombies']() != 1",
      "note" = "U7: energy drain",
    }, {
      "expr" = "strcmp(m['uam9DisjunctionName'](), \"Mordenkainen's Disjunction\") != 0  or  m['uam9DisjunctionNameHeaderGarbled']() != 1  or  m['uam9DisjunctionSchoolLost']() != 1  or  m['uam9DisjunctionComponentsCellLost']() != 1  or m['uam9DisjunctionLevel']() != 9  or m['uam9DisjunctionRangeZero']() != 0  or m['uam9DisjunctionCastingTimeSegments']() != 9  or  m['uam9DisjunctionDurationPermanent']() != 1  or  m['uam9DisjunctionSaveSpecial']() != 1  or m['uam9DisjunctionAoeRadiusInches']() != 3  or  m['uam9DisjunctionDisjoinsAllMagic']() != 1  or  m['uam9DisjunctionCasterPersonExempt']() != 1  or  m['uam9DisjunctionSpoilsSpellsBeingCast']() != 1  or  m['uam9DisjunctionItemsSaveOrBecomeNormal']() != 1  or  m['uam9DisjunctionItemSaveVsSpellIfCreature']() != 1  or m['uam9DisjunctionArtifactPctPerLevel']() != 1  or  m['uam9DisjunctionAffectsAllItemClasses']() != 1  or m['uam9DisjunctionArtifactAttentionPct']() != 95  or m['uam9DisjunctionArtifactDestroySaveAdj']() != -4  or  m['uam9DisjunctionCasterMayLoseCasting']() != 1",
      "note" = "U8: the Mordenkainen disjunction",
    }, {
      "expr" = "m['uas2Mu8thCount']() != 10  or strcmp(m['uas2Mu8thName'](0), \"Binding\") != 0  or strcmp(m['uas2Mu8thName'](1), \"Clone\") != 0  or strcmp(m['uas2Mu8thName'](2), \"Demand\") != 0  or strcmp(m['uas2Mu8thName'](6), \"Otiluke's Telekinetic Sphere\") != 0  or strcmp(m['uas2Mu8thName'](9), \"Sink\") != 0  or m['uas2Mu9thCount']() != 8  or strcmp(m['uas2Mu9thName'](0), \"Crystalbrittle\") != 0  or strcmp(m['uas2Mu9thName'](1), \"Energy Drain\") != 0  or strcmp(m['uas2Mu9thName'](2), \"Gate\") != 0  or strcmp(m['uas2Mu9thName'](3), \"Mordenkainen's Disjunction\") != 0  or strcmp(m['uas2Mu9thName'](4), \"Prismatic Sphere\") != 0  or strcmp(m['uas2Mu9thName'](5), \"Shape Change\") != 0  or strcmp(m['uas2Mu9thName'](6), \"Succor\") != 0  or strcmp(m['uas2Mu9thName'](7), \"Wish\") != 0",
      "note" = "the R785 seam repair (the table now carries binding and the telekinetic sphere; the 9th roster repairs; the absent-name loops reverse)",
    }, {
      "expr" = "m['uam7TeleportSuccorException']() != 1  or strcmp(m['uam9SuccorName'](), \"Succor (Alteration - Enchantment)\") != 0",
      "note" = "the R361 teleport exception names this succor - the cross-level link",
    } },
  "audit" = {
      "label" = "R362: the UA new magic-user 8th and 9th level spells pin audit",
      "comment" = "The UA NEW MAGIC-USER SPELLS (pp. 71-77), the 8th and 9th levels - binding behind the lost range and duration cells, demand behind the garbled components cell, the Otiluke telekinetic sphere behind the garbled name header, sink behind the lost level cell; crystalbrittle with the item save ladder, succor with the interleaved stat tail, energy drain with the displaced casting cell, the Mordenkainen disjunction behind the garbled name header. The R342 seam checks demand at index 0 and sink at index 8; only the two PHB 9th names print. The item CLOSES with this round.",
    },
}
