-- ilv: promoted from tools/spec_r919.json (the The Dragon issue-12 opener part one - the Ovalle illusionist article (folios 6-7) and the Endersby and Carroll ship cargo article (folio 12): two adjudicated chains, the mythos pair to follow);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 919,
  "prefix" = "ilv",
  "banner" = {
      "title" = "The Dragon issue-12 opener part one - the Ovalle illusionist article (folios 6-7) and the Endersby and Carroll ship cargo article (folio 12): two adjudicated chains, the mythos pair to follow",
      "provenance" = "Pinned from The Dragon Vol. II No. 6 (February 1978), the archive.org scan voice (single-voice: no chat-side upload cross-check exists for issue 12; the source lives in the archive.org item accessory-dragon-magazine-012, file Accessory - Dragon Magazine #012_djvu.xml). PRINT FOLIO = PDF PAGE, verified at the TOC alignments (5, 6, 8, 12, 13, 18, 28); the TOC's folio 2 for the lightning bolt essay is a print misprint, the article riding folio 12, noted as scanned. The transcripts ride extract/dragon/012/p001 through p032; the article CHAIN is the ink unit, not the folio.",
      "sentinel" = "The cargo grid's Spice and Ivory value cells print blank in the scan and the Foreign slaves cell prints a count (20-60 people) not a gold figure - all three ride the -1 sentinel with the census, the count riding the transcript. The illusionist ladder's fifth-level header garbles as Sth and the Cause Serious Wounds damage garbles as a bar reading 1 point - the ladder's arithmetic is the anchor. Two slipped teasers noted: the brawling long-term-effects sequel and the Name That Monster winners both fail to print, harvestable later.",
    },
  "consts" = { {
      "name" = "ilvRecognizePercentPerLevel",
      "value" = 7,
      "comment" = "a 7 percent chance per level of recognizing a disguised creature or polymorphed object (folio 6)",
    }, {
      "name" = "ilvWallOfFogMinTurns",
      "value" = 3,
      "comment" = "Wall of Fog lasts 3-12 plus level turns after concentration ceases (folio 7)",
    }, {
      "name" = "ilvWallOfFogMaxTurns",
      "value" = 12,
      "comment" = "the Wall of Fog duration ceiling (folio 7)",
    }, {
      "name" = "ilvDisplacementMinFeet",
      "value" = 0,
      "comment" = "Displacement places the image 0-10 feet from the true location (folio 7)",
    }, {
      "name" = "ilvDisplacementMaxFeet",
      "value" = 10,
      "comment" = "the Displacement image distance ceiling, variable at will (folio 7)",
    }, {
      "name" = "ilvDisplacementMinTurns",
      "value" = 1,
      "comment" = "Displacement lasts 1-6 turns plus level of caster (folio 7)",
    }, {
      "name" = "ilvDisplacementMaxTurns",
      "value" = 6,
      "comment" = "the Displacement duration die ceiling (folio 7)",
    }, {
      "name" = "ilvMultipleHypnosisMinTargets",
      "value" = 1,
      "comment" = "Multiple Hypnosis affects 1-4 (folio 7)",
    }, {
      "name" = "ilvMultipleHypnosisMaxTargets",
      "value" = 4,
      "comment" = "the Multiple Hypnosis target ceiling (folio 7)",
    }, {
      "name" = "ilvHypnotizeMonsterCharmBonus",
      "value" = 2,
      "comment" = "Hypnotize Monster affects all creatures, treat as charm monster +2 (folio 7)",
    }, {
      "name" = "ilvFeeblemindMuSavePenalty",
      "value" = 30,
      "comment" = "Feeblemind at Magic User 30 percent off saving throw (folio 7)",
    }, {
      "name" = "ilvFeeblemindClericSavePenalty",
      "value" = 10,
      "comment" = "Feeblemind at Cleric 10 percent off; illusionists save normal (folio 7)",
    }, {
      "name" = "ilvFingerOfDeathLevelDrain",
      "value" = 2,
      "comment" = "Shadow Magic Finger of Death causes disease or affects 2 levels (folio 7)",
    }, {
      "name" = "ilvBladeBarrierMinDamage",
      "value" = 1,
      "comment" = "Shadow Magic Blade Barrier does 1-8 points damage (folio 7)",
    }, {
      "name" = "ilvBladeBarrierMaxDamage",
      "value" = 8,
      "comment" = "the Blade Barrier damage ceiling (folio 7)",
    }, {
      "name" = "ilvCauseSeriousWoundsDamage",
      "value" = 1,
      "comment" = "Shadow Magic Cause Serious Wounds does 1 point damage - the print's garbled bar reading 1 (folio 7)",
    }, {
      "name" = "ilvGazeRangeNearInches",
      "value" = 6,
      "comment" = "the Gaze of Umber Hulk range - as far as can be seen, 6 or 12 inches (folio 7)",
    }, {
      "name" = "ilvGazeRangeFarInches",
      "value" = 12,
      "comment" = "the gaze range far reading (folio 7)",
    }, {
      "name" = "ilvPowerWordKillMinHp",
      "value" = 1,
      "comment" = "Demi Shadow Magic Power Word Kill affects 1-4 hit points (folio 7)",
    }, {
      "name" = "ilvPowerWordKillMaxHp",
      "value" = 4,
      "comment" = "the Power Word Kill hit-point ceiling (folio 7)",
    }, {
      "name" = "ilvHolyWordMinFirstLevelTypes",
      "value" = 2,
      "comment" = "Demi Shadow Magic Holy Word affects 2-16 first-level types (folio 7)",
    }, {
      "name" = "ilvHolyWordMaxFirstLevelTypes",
      "value" = 16,
      "comment" = "the Holy Word first-level-type ceiling (folio 7)",
    }, {
      "name" = "ilvPrismaticWallDamageLow",
      "value" = 2,
      "comment" = "Demi Shadow Magic Prismatic Wall does 2 or 4 points damage (folio 7)",
    }, {
      "name" = "ilvPrismaticWallDamageHigh",
      "value" = 4,
      "comment" = "the Prismatic Wall damage high reading (folio 7)",
    }, {
      "name" = "ilvIceStormMinDamage",
      "value" = 1,
      "comment" = "Demi Shadow Magic Ice Storm does 1-6 points damage (folio 7)",
    }, {
      "name" = "ilvIceStormMaxDamage",
      "value" = 6,
      "comment" = "the Ice Storm damage ceiling (folio 7)",
    }, {
      "name" = "ilvMUSpellResearchWaitWeeks",
      "value" = 2,
      "comment" = "the first-level MU spell research - save vs magic or wait two game weeks, then save by intelligence or wait two more (folio 7)",
    }, {
      "name" = "ilvShieldIllusionistSpellLevel",
      "value" = 4,
      "comment" = "shield is a fourth-level illusionist spell - defensive spells trade with less penalty (folios 6-7)",
    }, {
      "name" = "ilvImprovedInvisibilityMuSpellLevel",
      "value" = 5,
      "comment" = "improved invisibility is a fifth-level magic-user spell (folio 6)",
    }, {
      "name" = "ilvSecondLevelWaitMultiplier",
      "value" = 2,
      "comment" = "second-level MU spells - same as first level except double the time penalty (folio 7)",
    }, {
      "name" = "ilvSpellLadderLevels",
      "value" = 7,
      "comment" = "the explanation-of-spells ladder runs the first through seventh levels (folio 7)",
    }, {
      "name" = "ilvSmallMerchantUnits",
      "value" = 12,
      "comment" = "a small merchant ship holds up to twelve units of cargo (folio 12)",
    }, {
      "name" = "ilvLargeMerchantUnits",
      "value" = 30,
      "comment" = "a large merchant ship holds up to thirty units (folio 12)",
    }, {
      "name" = "ilvCargoKindDieSides",
      "value" = 6,
      "comment" = "roll a six-sided die for each kind of treasure possible (folio 12)",
    }, {
      "name" = "ilvCargoUnitsMin",
      "value" = 1,
      "comment" = "each roll of a one means one to six units of that cargo on board (folio 12)",
    }, {
      "name" = "ilvCargoUnitsMax",
      "value" = 6,
      "comment" = "the cargo unit ceiling per one-roll (folio 12)",
    }, {
      "name" = "ilvPassengerChancePercent",
      "value" = 15,
      "comment" = "a 15 percent chance that a few passengers are aboard - merchants, adventurers or noblemen (folio 12)",
    }, {
      "name" = "ilvCargoRows",
      "value" = 12,
      "comment" = "the cargo value grid rows - spice, silk, precious stones, ivory, precious wood, tea, cotton, jewelry, cloth, exotic livestock, fruits and vegetables, foreign slaves (folio 12)",
    } },
  "bools" = { {
      "name" = "ilvRecognizesColleagueWork",
      "value" = true,
      "comment" = "an illusionist innately discriminates illusionist-thrown spells from the same spells thrown by a magic user or cleric (folio 6)",
    }, {
      "name" = "ilvNoFireballOrLightning",
      "value" = true,
      "comment" = "illusionists cannot use fireballs or lightning (folio 6)",
    }, {
      "name" = "ilvOffensiveSpellsCostlyToTrade",
      "value" = true,
      "comment" = "offensive spells cannot be traded without great penalty (folio 6)",
    }, {
      "name" = "ilvDefensiveSpellsTradeEasier",
      "value" = true,
      "comment" = "defensive spells can be traded with less penalty (folio 6)",
    }, {
      "name" = "ilvInformationalSpellsFreelyTradeable",
      "value" = true,
      "comment" = "informational spells like detect magic, contact higher plane and legend lore are freely tradeable at the same level (folio 6)",
    }, {
      "name" = "ilvVisionNeverResearchable",
      "value" = true,
      "comment" = "Vision as an exception can never be researched (folio 6)",
    }, {
      "name" = "ilvAttacksAstralAndEthereal",
      "value" = true,
      "comment" = "illusionists have the ability to attack astral and ethereal monsters (folio 6)",
    }, {
      "name" = "ilvEyeFocusSpellsSilent",
      "value" = true,
      "comment" = "spells using the eyes as point of focus need no speech or overt hand motions (folio 7)",
    }, {
      "name" = "ilvGazeReflectionBouncesVisualOnly",
      "value" = true,
      "comment" = "Gaze Reflection bounces visual spells or rays of light, not other magic (folio 7)",
    }, {
      "name" = "ilvPosthypnoticSuggestionSaves",
      "value" = true,
      "comment" = "posthypnotic suggestions take effect after hypnosis is released, a save for each, on saving the charm breaks (folio 7)",
    }, {
      "name" = "ilvDispelAutoVsMuCast",
      "value" = true,
      "comment" = "Dispel Illusion works against any illusion-type spell and automatically dispels MU-cast illusionist spells (folio 7)",
    }, {
      "name" = "ilvPersonalSilenceClone",
      "value" = true,
      "comment" = "Personal Silence is as clerical silence for the caster (folio 7)",
    }, {
      "name" = "ilvImprovedDisplacementUnlimited",
      "value" = true,
      "comment" = "Improved Displacement is as displacement 10-foot radius with unlimited duration (folio 7)",
    }, {
      "name" = "ilvSensoryDisplacementBlinds",
      "value" = true,
      "comment" = "Sensory Displacement - save vs magic or the victim is blind, deaf and disoriented until dispelled (folio 7)",
    }, {
      "name" = "ilvDiscordDelusionEffect",
      "value" = true,
      "comment" = "Discord - save vs magic or the victim acts as if wearing rings of delusion and contrariness (folio 7)",
    }, {
      "name" = "ilvGazeReflectedBack",
      "value" = true,
      "comment" = "the Gaze of Umber Hulk can affect the illusionist by reflection; must meet eyes, lasts while he concentrates (folio 7)",
    }, {
      "name" = "ilvSpectresWeaponImmune",
      "value" = true,
      "comment" = "Create Spectres - the spectres have no draining ability, harmed by neither weapons nor magic save haste (halving lifespan) and time stop (destroying) (folio 7)",
    }, {
      "name" = "ilvMUSpellResearchPermanent",
      "value" = true,
      "comment" = "the researched first-level MU spell use never wears off unless level-drained, feebleminded or dispelled (folio 7)",
    }, {
      "name" = "ilvBasiliskGazeTurnsToStone",
      "value" = true,
      "comment" = "the sixth-level Basilisk Gaze - same as Umber Hulk Gaze except the save is against turning to stone (folio 7)",
    }, {
      "name" = "ilvAlterRealityFullWish",
      "value" = true,
      "comment" = "the seventh-level Alter Reality is the same as before but a full wish, not limited wish (folio 7)",
    }, {
      "name" = "ilvCargoAfterSurrenderOnly",
      "value" = true,
      "comment" = "cargo is determined only after grappling and surrender or annihilation of enemy forces (folio 12)",
    }, {
      "name" = "ilvOverflowDropsLeastValuable",
      "value" = true,
      "comment" = "if the total units exceed the ship's capacity, neglect the least valuable cargo (folio 12)",
    }, {
      "name" = "ilvCargoTreasureTypeA",
      "value" = true,
      "comment" = "also roll for treasure - type A (folio 12)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "ilvCargoValue",
      "tag" = "CG",
      "count" = "ilvCargoRows",
      "sentinel" = -1,
      "sentinel_census" = { 3 },
      "audit_comment" = "the cargo value grid - the Spice, Ivory and Foreign-slaves value cells ride the -1 sentinel: Spice and Ivory print blank in the scan, the Foreign slaves cell prints a count (20-60 people) not a gold figure, the count riding the transcript (folio 12)",
      "cols" = { "ilvCargoGoldPerUnit" },
      "col_comments" = { "the value-per-unit gold pieces - spice sentinel, silk 1000, precious stones 1000, ivory sentinel, precious wood 300, tea 350, cotton 250, jewelry 1000, cloth 250, exotic livestock 250, fruits and vegetables 100, foreign slaves sentinel (folio 12)" },
      "data" = { { -1 }, { 1000 }, { 1000 }, { -1 }, { 300 }, { 350 }, { 250 }, { 1000 }, { 250 }, { 250 }, { 100 }, { -1 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['ilvRecognizePercentPerLevel']() != 7 or m['ilvSpellLadderLevels']() != 7",
      "note" = "the illusionist recognition ladder - 7 percent per level across the seven-level spell ladder (folios 6-7)",
    }, {
      "expr" = "m['ilvDisplacementMinFeet']() != 0 or m['ilvDisplacementMaxFeet']() != 10 or m['ilvDisplacementMinTurns']() != 1 or m['ilvDisplacementMaxTurns']() != 6",
      "note" = "the Displacement bounds - the image 0-10 feet out for 1-6 turns plus the caster's level (folio 7)",
    }, {
      "expr" = "m['ilvFeeblemindMuSavePenalty']() != 30 or m['ilvFeeblemindClericSavePenalty']() != 10",
      "note" = "the Feeblemind saves - magic users 30 percent off, clerics 10 percent off, illusionists normal (folio 7)",
    }, {
      "expr" = "m['ilvPowerWordKillMaxHp']() != 4 or m['ilvHolyWordMaxFirstLevelTypes']() != 16 or m['ilvPrismaticWallDamageHigh']() != 4 or m['ilvIceStormMaxDamage']() != 6",
      "note" = "the Demi Shadow Magic variants - Power Word Kill 1-4 hit points, Holy Word 2-16 first-level types, Prismatic Wall 2 or 4, Ice Storm 1-6, Symbol no effect (folio 7)",
    }, {
      "expr" = "m['ilvShieldIllusionistSpellLevel']() != 4 or m['ilvImprovedInvisibilityMuSpellLevel']() != 5",
      "note" = "the trading ladder - shield a fourth-level illusionist spell, improved invisibility a fifth-level magic-user spell (folio 6)",
    }, {
      "expr" = "m['ilvMUSpellResearchWaitWeeks']() != 2 or m['ilvSecondLevelWaitMultiplier']() != 2",
      "note" = "the research waits - two game weeks per failed save, doubled for second-level spells (folio 7)",
    }, {
      "expr" = "m['ilvSmallMerchantUnits']() != 12 or m['ilvLargeMerchantUnits']() != 30 or m['ilvCargoKindDieSides']() != 6 or m['ilvCargoUnitsMax']() != 6",
      "note" = "the cargo procedure - twelve units small, thirty large, the d6 per kind with the one-roll's 1-6 units (folio 12)",
    }, {
      "expr" = "m['ilvPassengerChancePercent']() != 15",
      "note" = "the passenger chance - 15 percent, merchants, adventurers or noblemen (folio 12)",
    } },
  "audit" = {
      "label" = "R919 issue-12 opener audit",
      "comment" = "THE DRAGON ISSUE-12 OPENER ROUND, PART ONE - two adjudicated chains, the mythos pair to follow in part two. The Ovalle illusionist article (folios 6-7): the 7-percent-per-level recognition of disguised creatures, the no-fireball-no-lightning restriction, the astral and ethereal attack ability, the trading rules, and the spell ladder from Wall of Fog and Displacement through Feeblemind, the Shadow Magic variants, the Demi Shadow Magic variants, Create Spectres and the seventh-level Alter Reality full wish. The Endersby and Carroll ship cargo article (folio 12): the twelve-unit small and thirty-unit large merchant capacities, the d6 per cargo kind with the one-roll's 1-6 units, the overflow-drops-least-valuable rule, the treasure type A roll, the 15 percent passenger chance and the twelve-row value grid with its three sentinel cells.",
    },
}
