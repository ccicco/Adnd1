-- wzd: promoted from tools/spec_r932.json (the The Dragon issue-17 opener part two - A Wizard With A Difference: the eight Ward area-wizard variants, the chance-of-making grid, the spell-list roster and the explanation doctrines);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 932,
  "prefix" = "wzd",
  "banner" = {
      "title" = "The Dragon issue-17 opener part two - A Wizard With A Difference: the eight Ward area-wizard variants, the chance-of-making grid, the spell-list roster and the explanation doctrines",
      "provenance" = "Pinned from The Dragon Vol. III No. 3 (August 1978), the Curtiss-provided scan voice (single voice: the issue-17 source is the uploaded Dm17.pdf with its mistral-ocr transcript; no archive.org djvu cross-check exists for issue 17). PRINT FOLIO = PDF PAGE MINUS TWO, verified at the page feet. The article prints at folios 10-13 (PDF 12-15), its list pages broken by the Strategists Club ballot at folio 12 and its Movement explanations riding folio 15 (PDF 17) alongside the R931-pinned Sights and Sounds; the cont. overleaf footer at folio 13 closes there. The pin IS the conversion: OD&D-era ink adjudicated to 1e terms, the conversion noted, never silent; Dragon pins ride a VARIANT layer with provenance, never core canon.",
      "sentinel" = "Print quirks pinned AS SCANNED, noted never silent: the single-voice transcript garbles ride the data file and the comments, never silently normalized - Dispel! Magic (the Defense third-level row), Pall-wall (the Movement fourth-level Pass-wall), Extention, Telekenisis, Ventriliquism, Animate Deat, the Defense-list Etherfulness against the explanation-head Etherialness, the Movement explanation-head Etheriainess, Replusion Field, Hold Staffs in the list against Hold Staff in the explanation, the lowercase Fire immunity, the Movement list skipping its Fifth Level row and printing no ordinal for it, the Control overflow row printing without its level label, and the End All Barriers explanation printing twice with two different texts - both pinned, the dupe noted as scanned. No printed grid in this article carries a garbled numeric cell: the chance grid and the roster counts pin clean, so no table cell rides a sentinel this round.",
    },
  "consts" = { {
      "name" = "wzdChanceLevels",
      "value" = 8,
      "comment" = "the chance-of-making table runs First through Eighth Level (print 10, PDF 12)",
    }, {
      "name" = "wzdChanceRows",
      "value" = 8,
      "comment" = "the chance table row count, one row per spell level band (print 10)",
    }, {
      "name" = "wzdNormalSpellLevels",
      "value" = 9,
      "comment" = "the normal D&D magic user carries nine spell levels - the Ward prose frame (print 10)",
    }, {
      "name" = "wzdWizardTypes",
      "value" = 8,
      "comment" = "the eight area wizard types: Aggression, Defense, All Things Rustic, Control, Tenaciousness, Detection, Fire, Movement (print 10)",
    }, {
      "name" = "wzdSpellsPerLevel",
      "value" = 2,
      "comment" = "the area wizard picks two spells per experience level from any spell level on his list (print 10)",
    }, {
      "name" = "wzdChanceBonusPerLevel",
      "value" = 5,
      "comment" = "the working chance increases by 5 percent for every level over the first (print 10)",
    }, {
      "name" = "wzdChangedSpellMarkStars",
      "value" = 1,
      "comment" = "the printed legend: one star marks a spell changed to fit the area (print 10)",
    }, {
      "name" = "wzdNewSpellMarkStars",
      "value" = 2,
      "comment" = "the printed legend: two stars mark a new spell (print 10)",
    }, {
      "name" = "wzdExampleWizardLevel",
      "value" = 5,
      "comment" = "the Ward worked example: a fifth-level wizard of fire (print 10)",
    }, {
      "name" = "wzdExampleSpellLevel",
      "value" = 6,
      "comment" = "the example casts a sixth-level spell, heat ray (print 10)",
    }, {
      "name" = "wzdExampleBonusPercent",
      "value" = 20,
      "comment" = "the fifth level over the first gives a +20 percent chance in the example - four bands at 5 percent (print 10)",
    }, {
      "name" = "wzdExampleBasePercent",
      "value" = 30,
      "comment" = "the sixth-level spell carries a 30 percent base chance in the example (print 10)",
    }, {
      "name" = "wzdExampleRollMax",
      "value" = 50,
      "comment" = "the example roll needs 1-50 percent for the spell to work (print 10)",
    }, {
      "name" = "wzdExampleFailMin",
      "value" = 51,
      "comment" = "the example fail floor - a 51 roll and the spell does not work (print 10)",
    }, {
      "name" = "wzdOfferRows",
      "value" = 8,
      "comment" = "the spell-offer count grid rows - one per wizard type in article order: Aggression, Defense, Tenaciousness, Detection, Fire, Movement, All Things Rustic, Control (print 10-15)",
    }, {
      "name" = "wzdTotalSpellsOffered",
      "value" = 206,
      "comment" = "the total spells offered across the eight lists, every level row counted (print 10-15)",
    }, {
      "name" = "wzdCtlOverflowCount",
      "value" = 3,
      "comment" = "the Control list prints an unlabeled overflow row after the Eighth Level - Gate, Monster Summoning VI, Astral Spell, Charm Golems - three spells, the level ordinal never printing (print 12, PDF 14)",
    }, {
      "name" = "wzdMarkedChanged",
      "value" = 22,
      "comment" = "the total changed spells carrying the single star (print 10-15)",
    }, {
      "name" = "wzdMarkedNew",
      "value" = 54,
      "comment" = "the total new spells carrying the double star (print 10-15)",
    }, {
      "name" = "wzdAggMagicMissileArrowsPerLevel",
      "value" = 1,
      "comment" = "the changed Magic Missile: one more arrow per level of the magic user than the old spell (print 12, PDF 14)",
    }, {
      "name" = "wzdAggHoldPersonMax",
      "value" = 6,
      "comment" = "the changed Hold Person: affects 1-6 persons instead of 1-4 (print 12)",
    }, {
      "name" = "wzdAggHoldPersonOldMax",
      "value" = 4,
      "comment" = "the old Hold Person ceiling, 1-4 (print 12)",
    }, {
      "name" = "wzdAggMagicSpearBase",
      "value" = 3,
      "comment" = "the new Magic Spear: three spears base (print 12)",
    }, {
      "name" = "wzdAggMagicSpearPerBand",
      "value" = 1,
      "comment" = "the Magic Spear adds one spear per four-level band (print 12)",
    }, {
      "name" = "wzdAggMagicSpearLevelsPerBand",
      "value" = 4,
      "comment" = "the Magic Spear band width: per every four levels of the caster (print 12)",
    }, {
      "name" = "wzdAggDancingSwordPlus",
      "value" = 1,
      "comment" = "the new Dancing Magic Sword: a plus 1 sword (print 12)",
    }, {
      "name" = "wzdAggDancingSwordTurns",
      "value" = 4,
      "comment" = "the Dancing Magic Sword fights as a hero for four melee turns at the caster command (print 12)",
    }, {
      "name" = "wzdAggMeltHotTurn",
      "value" = 1,
      "comment" = "the new Melt: the metal turns red hot in one melee turn (print 12)",
    }, {
      "name" = "wzdAggMeltMeltTurn",
      "value" = 2,
      "comment" = "the Melt melts the metal on the next melee turn - the second turn from casting (print 12)",
    }, {
      "name" = "wzdDefShieldArmorClass",
      "value" = 2,
      "comment" = "the changed Shield: armor class 2 for the caster (print 12, PDF 14)",
    }, {
      "name" = "wzdDefShieldTurns",
      "value" = 5,
      "comment" = "the changed Shield lasts five melee turns plus the level of the magic user (print 12)",
    }, {
      "name" = "wzdDefProtEvilToHitPenalty",
      "value" = 1,
      "comment" = "the changed Protection from Evil: any chaotic being takes minus one on all attempts to hit the caster (print 12)",
    }, {
      "name" = "wzdDefProtEvilTurns",
      "value" = 6,
      "comment" = "the changed Protection from Evil lasts six melee turns (print 12)",
    }, {
      "name" = "wzdDefProtSwordsTurns",
      "value" = 4,
      "comment" = "the new Protection from Swords lasts four melee turns plus the caster level (print 12)",
    }, {
      "name" = "wzdDefRepulsionTurns",
      "value" = 2,
      "comment" = "the new Repulsion Field lasts two melee turns plus the caster level (print 12)",
    }, {
      "name" = "wzdDefEtherialnessTurns",
      "value" = 3,
      "comment" = "the new Etherialness works as the potion for three melee turns plus the caster level (print 12)",
    }, {
      "name" = "wzdDefNoPuncturesTurns",
      "value" = 3,
      "comment" = "the new No Punctures lasts three melee turns (print 12)",
    }, {
      "name" = "wzdRusCommuneTurns",
      "value" = 10,
      "comment" = "the new Communicate spells - Mammals, Plants, Reptiles, Insects, Avians, Monsters - each allow speech for ten melee turns (print 12-13)",
    }, {
      "name" = "wzdRusEarthElementalDice",
      "value" = 20,
      "comment" = "the changed Conjure Earth Elemental summons a 20 die elemental in the first melee turn (print 13)",
    }, {
      "name" = "wzdRusSummonVanishTurns",
      "value" = 1,
      "comment" = "the new Summon Felines, Canines, Avians: the summoned animals vanish after one full turn or death (print 13)",
    }, {
      "name" = "wzdRusCommandStaffUses",
      "value" = 1,
      "comment" = "the new Command as the Staff: the caster commands like a staff of commanding once (print 13)",
    }, {
      "name" = "wzdCtlSleepTwoBeings",
      "value" = 2,
      "comment" = "the changed Sleep affects two beings with five dice (print 12, PDF 14)",
    }, {
      "name" = "wzdCtlSleepFiveDice",
      "value" = 5,
      "comment" = "the five-dice Sleep share for two beings (print 12)",
    }, {
      "name" = "wzdCtlSleepOneBeing",
      "value" = 1,
      "comment" = "the changed Sleep affects one being with six dice (print 12)",
    }, {
      "name" = "wzdCtlSleepSixDice",
      "value" = 6,
      "comment" = "the six-dice Sleep draw for one being (print 12)",
    }, {
      "name" = "wzdCtlGolemSaveLevel",
      "value" = 14,
      "comment" = "the new Charm Golems gives any golem the saving throw of a 14th level wizard (print 12)",
    }, {
      "name" = "wzdCtlStaffUses",
      "value" = 1,
      "comment" = "the new Control as the Staff: the caster commands like a staff of commanding once (print 12)",
    }, {
      "name" = "wzdTenWizardLockDispels",
      "value" = 2,
      "comment" = "the changed Wizard Lock: only 2 dispel magics break its power (print 13, PDF 15)",
    }, {
      "name" = "wzdTenHoldRadiusYards",
      "value" = 60,
      "comment" = "the Hold Swords and Hold Crossbows radius: 60 yards around the caster (print 13)",
    }, {
      "name" = "wzdTenHoldSwordsTurnsMin",
      "value" = 2,
      "comment" = "the Hold Swords duration floor, 2-20 melee turns (print 13)",
    }, {
      "name" = "wzdTenHoldSwordsTurnsMax",
      "value" = 20,
      "comment" = "the Hold Swords duration ceiling, 2-20 melee turns (print 13)",
    }, {
      "name" = "wzdTenHoldStaffTurnsMin",
      "value" = 3,
      "comment" = "the Hold Staff duration floor, 3-30 melee turns (print 13)",
    }, {
      "name" = "wzdTenHoldStaffTurnsMax",
      "value" = 30,
      "comment" = "the Hold Staff duration ceiling, 3-30 melee turns (print 13)",
    }, {
      "name" = "wzdTenHoldMonsterTurnsMin",
      "value" = 1,
      "comment" = "the Hold Monster duration floor, 1-10 melee turns (print 13)",
    }, {
      "name" = "wzdTenHoldMonsterTurnsMax",
      "value" = 10,
      "comment" = "the Hold Monster duration ceiling, 1-10 melee turns (print 13)",
    }, {
      "name" = "wzdTenStopMagicRadiusYards",
      "value" = 30,
      "comment" = "the Stop Magic radius: 30 yards around the caster (print 13)",
    }, {
      "name" = "wzdTenStopMagicTurns",
      "value" = 6,
      "comment" = "the Stop Magic lasts 6 melee turns (print 13)",
    }, {
      "name" = "wzdTenHoldGroupsMaxBeings",
      "value" = 12,
      "comment" = "the Hold Groups holds any enemy group of less than 12 beings (print 13)",
    }, {
      "name" = "wzdTenOpeningsHeightFeet",
      "value" = 40,
      "comment" = "the Hold Openings area: less than 40 feet tall (print 13)",
    }, {
      "name" = "wzdTenOpeningsWidthFeet",
      "value" = 30,
      "comment" = "the Hold Openings area: 30 feet wide (print 13)",
    }, {
      "name" = "wzdTenOpeningsHours",
      "value" = 24,
      "comment" = "the Hold Openings force field lasts 24 hours (print 13)",
    }, {
      "name" = "wzdTenLockOpeningsHours",
      "value" = 1,
      "comment" = "the Wizard Lock Openings covers the same area but lasts only one hour (print 13)",
    }, {
      "name" = "wzdDetFindTrapsTurnsMin",
      "value" = 1,
      "comment" = "the changed Find Traps lasts 1-4 melee turns plus the caster level, as the wand of the same name (print 13, PDF 15)",
    }, {
      "name" = "wzdDetFindTrapsTurnsMax",
      "value" = 4,
      "comment" = "the Find Traps duration ceiling, 1-4 melee turns (print 13)",
    }, {
      "name" = "wzdDetEndSurpriseTurnsMin",
      "value" = 1,
      "comment" = "the new End Surprise warns for 1-6 melee turns plus the caster level (print 13)",
    }, {
      "name" = "wzdDetEndSurpriseTurnsMax",
      "value" = 6,
      "comment" = "the End Surprise duration ceiling, 1-6 melee turns (print 13)",
    }, {
      "name" = "wzdDetRevealHours",
      "value" = 24,
      "comment" = "the new Reveal the Way lasts 24 hours (print 13)",
    }, {
      "name" = "wzdDetDivineHours",
      "value" = 24,
      "comment" = "the new Divine Any Object lasts 24 hours with no range limitation (print 13)",
    }, {
      "name" = "wzdDetTransportBeingsMin",
      "value" = 1,
      "comment" = "the new Transport to the Spot carries the caster and 1-6 other beings (print 13)",
    }, {
      "name" = "wzdDetTransportBeingsMax",
      "value" = 6,
      "comment" = "the Transport to the Spot beings ceiling, 1-6 (print 13)",
    }, {
      "name" = "wzdDetTransportRangeFeet",
      "value" = 20,
      "comment" = "the transported beings must be within 20 feet of the caster (print 13)",
    }, {
      "name" = "wzdDetStudyHours",
      "value" = 6,
      "comment" = "the caster must have studied the target thing for over 6 hours (print 13)",
    }, {
      "name" = "wzdFireBallBonusPerDie",
      "value" = 1,
      "comment" = "the changed Fire Ball adds plus 1 point to every die (print 13, PDF 15)",
    }, {
      "name" = "wzdFireWallDice",
      "value" = 10,
      "comment" = "the changed Wall of Fire is a 10 die wall (print 13)",
    }, {
      "name" = "wzdFireWallTurnsMin",
      "value" = 1,
      "comment" = "the Wall of Fire stays 1-4 melee turns after the caster stops thinking (print 13)",
    }, {
      "name" = "wzdFireWallTurnsMax",
      "value" = 4,
      "comment" = "the Wall of Fire persistence ceiling, 1-4 melee turns (print 13)",
    }, {
      "name" = "wzdFireElementalDice",
      "value" = 20,
      "comment" = "the changed Conjure Fire Elemental summons a 20 die elemental in the first melee turn (print 13)",
    }, {
      "name" = "wzdFireResistTurnsMin",
      "value" = 1,
      "comment" = "the changed Fire Resistance grants immunity to all fire damage for 1-10 melee turns (print 13)",
    }, {
      "name" = "wzdFireResistTurnsMax",
      "value" = 10,
      "comment" = "the Fire Resistance duration ceiling, 1-10 melee turns (print 13)",
    }, {
      "name" = "wzdFireHeatRayDice",
      "value" = 10,
      "comment" = "the new Heat Ray causes 10 dice of heat damage (print 13)",
    }, {
      "name" = "wzdFireHeatRayTurns",
      "value" = 1,
      "comment" = "the Heat Ray delivers its damage in 1 melee turn (print 13)",
    }, {
      "name" = "wzdFireImmunityRadiusYards",
      "value" = 10,
      "comment" = "the new Fire Immunity covers all beings in a 10 yard radius about the caster (print 13)",
    }, {
      "name" = "wzdFireImmunityTurnsMin",
      "value" = 1,
      "comment" = "the Fire Immunity lasts 1-10 melee turns (print 13)",
    }, {
      "name" = "wzdFireImmunityTurnsMax",
      "value" = 10,
      "comment" = "the Fire Immunity duration ceiling, 1-10 melee turns (print 13)",
    }, {
      "name" = "wzdFireCombustTurnsMin",
      "value" = 1,
      "comment" = "the new Combustion of All Things burns for 1-6 melee turns (print 13)",
    }, {
      "name" = "wzdFireCombustTurnsMax",
      "value" = 6,
      "comment" = "the Combustion duration ceiling, 1-6 melee turns (print 13)",
    }, {
      "name" = "wzdFireCombustDicePerTurn",
      "value" = 5,
      "comment" = "the Combustion does 5 dice of damage every turn (print 13)",
    }, {
      "name" = "wzdFireVisionTurnsMin",
      "value" = 5,
      "comment" = "the new Fire Vision lasts 5-50 melee turns (print 13)",
    }, {
      "name" = "wzdFireVisionTurnsMax",
      "value" = 50,
      "comment" = "the Fire Vision duration ceiling, 5-50 melee turns (print 13)",
    }, {
      "name" = "wzdMovWaterTravelTurns",
      "value" = 5,
      "comment" = "the new Water Travel: walk on water for up to 5 full turns (print 15, PDF 17)",
    }, {
      "name" = "wzdMovNegateFlyTurnsMin",
      "value" = 1,
      "comment" = "the new Negate the Ability to Fly: the fly muscles paralyzed 1-5 melee turns (print 15)",
    }, {
      "name" = "wzdMovNegateFlyTurnsMax",
      "value" = 5,
      "comment" = "the Negate Fly ceiling, 1-5 melee turns (print 15)",
    }, {
      "name" = "wzdMovNegateWaterTurnsMin",
      "value" = 1,
      "comment" = "the new Negate the Ability to Move on or in the Water lasts 1-6 melee turns (print 15)",
    }, {
      "name" = "wzdMovNegateWaterTurnsMax",
      "value" = 6,
      "comment" = "the Negate Water ceiling, 1-6 melee turns (print 15)",
    }, {
      "name" = "wzdMovMassTeleportBeings",
      "value" = 20,
      "comment" = "the new Mass Teleport transports a maximum of 20 beings plus the caster (print 15)",
    }, {
      "name" = "wzdMovEtherialnessTurns",
      "value" = 3,
      "comment" = "the changed Etherialness works as the potion for three melee turns plus the caster level (print 15)",
    }, {
      "name" = "wzdMovEndBarrierTurnsMin",
      "value" = 1,
      "comment" = "the new End All Barriers makes a single barrier vanish for 1-10 melee turns (print 15)",
    }, {
      "name" = "wzdMovEndBarrierTurnsMax",
      "value" = 10,
      "comment" = "the End All Barriers ceiling, 1-10 melee turns (print 15)",
    } },
  "bools" = { {
      "name" = "wzdSameLevelProgression",
      "value" = true,
      "comment" = "the area wizards raise levels of experience in the same manner as the D&D wizard (print 10)",
    }, {
      "name" = "wzdFasterSpellUse",
      "value" = true,
      "comment" = "an area wizard studies nothing but his area and is faster in spell use than the normal magic user (print 10)",
    }, {
      "name" = "wzdBetterSpellLowerChance",
      "value" = true,
      "comment" = "the better the spell, the less chance a first-level area magic user has of performing it (print 10)",
    }, {
      "name" = "wzdExampleSpellLostOnFail",
      "value" = true,
      "comment" = "a failed chance roll costs the memorized spell unless more than one was taken (print 10)",
    }, {
      "name" = "wzdEdNoteNpcBedevilment",
      "value" = true,
      "comment" = "the ED note recommends the variants as a source of NPC bedevilment (print 10)",
    }, {
      "name" = "wzdCtlOverflowRowUnlabeled",
      "value" = true,
      "comment" = "the Control overflow row prints without its level label - the ninth-row ordinal never prints, noted as scanned (print 12)",
    }, {
      "name" = "wzdMovFifthLevelRowAbsent",
      "value" = true,
      "comment" = "the Movement list prints no Fifth Level row - the grid cell pins 0, the row itself never printing (print 10, PDF 12)",
    }, {
      "name" = "wzdAggMeltMagicSaveApplicable",
      "value" = true,
      "comment" = "the Melt allows the magic saving throw (print 12)",
    }, {
      "name" = "wzdAggMeltPlateMailMassLimit",
      "value" = true,
      "comment" = "the Melt affects masses of metal no greater than a set of plate mail (print 12)",
    }, {
      "name" = "wzdDefShieldPlusLevel",
      "value" = true,
      "comment" = "the Shield duration adds the caster level (print 12)",
    }, {
      "name" = "wzdDefProtEvilChaoticOnly",
      "value" = true,
      "comment" = "the Protection from Evil penalty binds chaotic beings only (print 12)",
    }, {
      "name" = "wzdDefProtEvilRadiusSameAsBase",
      "value" = true,
      "comment" = "the Protection from Evil 10 foot Radius does the same as the base spell, affecting the circle area around the caster (print 12)",
    }, {
      "name" = "wzdDefProtSwordsSaveToHit",
      "value" = true,
      "comment" = "the Protection from Swords forces the attacker to make the magic saving throw to hit with a sword (print 12)",
    }, {
      "name" = "wzdDefProtSwordsPlusLevel",
      "value" = true,
      "comment" = "the Protection from Swords duration adds the caster level (print 12)",
    }, {
      "name" = "wzdDefProtEdgedAsSwordSpell",
      "value" = true,
      "comment" = "the new Protection from Edged Weapons matches the sword spell for all edged weapons, same duration (print 12)",
    }, {
      "name" = "wzdDefRepulsionPlusLevel",
      "value" = true,
      "comment" = "the Repulsion Field duration adds the caster level (print 12)",
    }, {
      "name" = "wzdDefRepulsionStopsPhysical",
      "value" = true,
      "comment" = "the Repulsion Field stops anything of physical matter from touching the caster (print 12)",
    }, {
      "name" = "wzdDefEtherialnessPlusLevel",
      "value" = true,
      "comment" = "the Etherialness duration adds the caster level (print 12)",
    }, {
      "name" = "wzdDefEtherialnessAsPotion",
      "value" = true,
      "comment" = "the Etherialness works as the potion of the same name (print 12)",
    }, {
      "name" = "wzdDefNoPuncturesHealsInstantly",
      "value" = true,
      "comment" = "the No Punctures stops any skin-breaking attack - all such wounds heal instantly and are not felt (print 12)",
    }, {
      "name" = "wzdDefProtAllWeaponsAsSwordSpell",
      "value" = true,
      "comment" = "the new Protection from All Weapons matches the sword spell, applying to all weapons (print 12)",
    }, {
      "name" = "wzdRusLightFullDay",
      "value" = true,
      "comment" = "the changed Light gives the light of full day (print 12)",
    }, {
      "name" = "wzdRusCommuneReptilesAsMammals",
      "value" = true,
      "comment" = "the Reptiles, Insects, Avians and Monsters Communicate spells match the Mammal spell (print 13)",
    }, {
      "name" = "wzdRusConjureElementalThinks",
      "value" = true,
      "comment" = "the conjured earth elemental thinks for itself and will not attack the caster on lost concentration - it simply vanishes (print 13)",
    }, {
      "name" = "wzdRusSummonSeenTypesOnly",
      "value" = true,
      "comment" = "the Summon Felines conjures any type of cat the caster has seen, doing whatever the caster dictates (print 13)",
    }, {
      "name" = "wzdRusSummonCaninesAsFelines",
      "value" = true,
      "comment" = "the Summon Canines matches the feline spell for any type of dog (print 13)",
    }, {
      "name" = "wzdRusSummonAviansRocExcluded",
      "value" = true,
      "comment" = "the Summon Avians matches the feline spell for any type of bird except the magical Roc (print 13)",
    }, {
      "name" = "wzdRusCharmInsectAnyTypeSize",
      "value" = true,
      "comment" = "the new Charm Insect works on any type or size of insect (print 13)",
    }, {
      "name" = "wzdRusCharmSnakeMammalAsInsect",
      "value" = true,
      "comment" = "the Charm Snake and Charm Mammal match the charm insect spell for snakes and mammals (print 13)",
    }, {
      "name" = "wzdRusInsectPlagueAsCleric",
      "value" = true,
      "comment" = "the Insect Plague in the list works as the cleric spell (print 13)",
    }, {
      "name" = "wzdCtlGolemCutsProtection",
      "value" = true,
      "comment" = "the Charm Golems cuts through the magic protection of any given golem and allows a control attempt (print 12)",
    }, {
      "name" = "wzdCtlSleepNormalOtherwise",
      "value" = true,
      "comment" = "the changed Sleep is the normal spell otherwise, adding only the two-beings-five-dice and one-being-six-dice draws (print 12)",
    }, {
      "name" = "wzdTenHoldPortalAsWizardLock",
      "value" = true,
      "comment" = "the changed Hold Portal works like a wizard lock for this wizard (print 13)",
    }, {
      "name" = "wzdTenWizardLockKnockWorks",
      "value" = true,
      "comment" = "the changed Wizard Lock falls to the normal knock spell but needs both dispel magics (print 13)",
    }, {
      "name" = "wzdTenKnockOpensBlocked",
      "value" = true,
      "comment" = "the changed Knock opens any locked, fastened or blocked thing - a passage filled with rubble and the like (print 13)",
    }, {
      "name" = "wzdTenHoldSwordsUndrawnOnly",
      "value" = true,
      "comment" = "the Hold Swords holds any sword in its scabbard that has not been drawn at the casting (print 13)",
    }, {
      "name" = "wzdTenHoldCrossbowsWhileConcentrating",
      "value" = true,
      "comment" = "the Hold Crossbows blocks the shaft only as long as the caster concentrates (print 13)",
    }, {
      "name" = "wzdTenHoldMonsterSaveStops",
      "value" = true,
      "comment" = "the Hold Monster works unless the monster makes its magic saving throw - it stops special powers like troll regeneration and dragon breath (print 13)",
    }, {
      "name" = "wzdTenStopMagicSaveStops",
      "value" = true,
      "comment" = "the Stop Magic binds only enemies failing the magic saving throw (print 13)",
    }, {
      "name" = "wzdTenHoldGroupsMixed",
      "value" = true,
      "comment" = "the Hold Groups holds even when creatures and humans are intermixed, each being saving individually (print 13)",
    }, {
      "name" = "wzdTenOpeningsCasterMayLeave",
      "value" = true,
      "comment" = "the Hold Openings needs no concentration once up - the caster may leave the area (print 13)",
    }, {
      "name" = "wzdTenOpeningsTakesDamage",
      "value" = true,
      "comment" = "the Hold Openings field takes damage like a human with the caster hit point count (print 13)",
    }, {
      "name" = "wzdTenLockOpeningsDispelOnly",
      "value" = true,
      "comment" = "the Wizard Lock Openings falls only to a dispel magic - nothing else gets through it or hurts it (print 13)",
    }, {
      "name" = "wzdTenEndArcaneAllMagicalWalls",
      "value" = true,
      "comment" = "the End Arcane Walls dissolves all magically created walls - stone, fire, ice and the like (print 13)",
    }, {
      "name" = "wzdTenHoldCubeRingsWandsDurations",
      "value" = true,
      "comment" = "the Hold a Cube of Force and Hold Wands run 2-20 melee turns, the Hold Rings 3-30 - the two duration families of the list (print 13)",
    }, {
      "name" = "wzdDetFindTrapsPlusLevel",
      "value" = true,
      "comment" = "the Find Traps duration adds the caster level (print 13)",
    }, {
      "name" = "wzdDetFindSecretDoorsAsTraps",
      "value" = true,
      "comment" = "the changed Find Secret Doors matches the trap spell for secret doors (print 13)",
    }, {
      "name" = "wzdDetEndSurprisePlusLevel",
      "value" = true,
      "comment" = "the End Surprise duration adds the caster level (print 13)",
    }, {
      "name" = "wzdDetFindPathAsCleric",
      "value" = true,
      "comment" = "the changed Find the Path works as the cleric spell (print 13)",
    }, {
      "name" = "wzdDetRevealFootstepsGlow",
      "value" = true,
      "comment" = "the Reveal the Way makes the actual footsteps or claw steps of the fleeing being glow before the caster (print 13)",
    }, {
      "name" = "wzdDetRevealFlightPathGlow",
      "value" = true,
      "comment" = "the Reveal the Way glows the flight path when the quarry flew away (print 13)",
    }, {
      "name" = "wzdDetDivineWillowWand",
      "value" = true,
      "comment" = "the Divine Any Object uses a willow wand to feel the way to the known object or being (print 13)",
    }, {
      "name" = "wzdDetTransportMustStudy",
      "value" = true,
      "comment" = "the Transport to the Spot needs the caster to know exactly what is transported near - studied, mentally projected, transported safely (print 13)",
    }, {
      "name" = "wzdFireBallNeverAffectsCaster",
      "value" = true,
      "comment" = "the fire wizard is never affected by his own fire ball (print 13)",
    }, {
      "name" = "wzdFireBallEquipmentNotProtected",
      "value" = true,
      "comment" = "the fire wizard equipment is however affected by his own fire ball (print 13)",
    }, {
      "name" = "wzdFireIllusionsFireOnly",
      "value" = true,
      "comment" = "the changed Phantasmal Force Fire Illusions makes only illusions dealing with fire (print 13)",
    }, {
      "name" = "wzdFireNegationDestroysContactedFire",
      "value" = true,
      "comment" = "the new Fire Negation destroys any fire the caster comes in contact with, lasting 2-20 melee turns (print 13)",
    }, {
      "name" = "wzdFireControlRedirectOnSave",
      "value" = true,
      "comment" = "the new Control of Fire throws directed fire spells back at the thrower when the caster makes the magic saving throw, lasting 2-20 melee turns (print 13)",
    }, {
      "name" = "wzdFireConjureElementalThinks",
      "value" = true,
      "comment" = "the conjured fire elemental thinks for itself and vanishes on lost concentration rather than attacking the caster (print 13)",
    }, {
      "name" = "wzdFireBodyInfernoCasterDice",
      "value" = true,
      "comment" = "the new Body of Fire turns the caster into an inferno for the number of dice or hit points he has, lasting 2-20 melee turns (print 13)",
    }, {
      "name" = "wzdFireHeatRayHitsFireTypes",
      "value" = true,
      "comment" = "the Heat Ray damages any creature, even a fire type creature (print 13)",
    }, {
      "name" = "wzdFireImmunityAllBeingsInRadius",
      "value" = true,
      "comment" = "the Fire Immunity covers all beings in the radius, not the caster alone (print 13)",
    }, {
      "name" = "wzdFireVisionNeedsLitFire",
      "value" = true,
      "comment" = "the Fire Vision sees into any area with a lit fire (print 13)",
    }, {
      "name" = "wzdMovNegateRunTowardFled",
      "value" = true,
      "comment" = "the new Negate the Ability to Run from a Fight forces the fleeing being, on a failed magic save, to run toward the very creature it sought to flee (print 15)",
    }, {
      "name" = "wzdMovMassTeleportAsTeleport",
      "value" = true,
      "comment" = "the Mass Teleport acts in all other respects as the teleport spell, to the area the caster mentally envisions (print 15)",
    }, {
      "name" = "wzdMovEtherialnessPlusLevel",
      "value" = true,
      "comment" = "the Movement Etherialness duration adds the caster level (print 15)",
    }, {
      "name" = "wzdMovEndBarrierPrintedTwice",
      "value" = true,
      "comment" = "the End All Barriers explanation prints TWICE with two different texts - the vanish-for-1-10 reading and the giant-disintegrate reading, both pinned, the dupe noted as scanned (print 15)",
    }, {
      "name" = "wzdMovEndBarrierGiantDisintegrate",
      "value" = true,
      "comment" = "the second End All Barriers text reads as a giant disintegrate that unblocks anything stopping the wizard of movement (print 15)",
    }, {
      "name" = "wzdMovSafeTeleportNoHighLow",
      "value" = true,
      "comment" = "the changed Safe Teleport matches the normal teleport except the caster never comes high or low on the target (print 15)",
    }, {
      "name" = "wzdMovWaterTravelCastOnOthers",
      "value" = true,
      "comment" = "the Water Travel allows the user or the being the caster casts it on to walk on water (print 15)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wzdChance",
      "tag" = "Wc",
      "count" = "wzdChanceRows",
      "sentinel" = -1,
      "audit_comment" = "the chance-of-making-per-level grid - one row per spell level band, First through Eighth, the percent chance a first-level area wizard has of working a spell of that level: 100, 85, 75, 50, 40, 30, 20, 10 (print 10, PDF 12)",
      "cols" = { "wzdChanceLevel", "wzdChancePercent" },
      "col_comments" = { "the spell level ordinal, 1-8 (print 10)", "the working percent at first caster level - the better the spell the less the chance (print 10)" },
      "data" = { { 1, 100 }, { 2, 85 }, { 3, 75 }, { 4, 50 }, { 5, 40 }, { 6, 30 }, { 7, 20 }, { 8, 10 } },
    }, {
      "name" = "wzdOffer",
      "tag" = "Wo",
      "count" = "wzdOfferRows",
      "sentinel" = -1,
      "audit_comment" = "the spell-offer count grid - one row per wizard type in article order (Aggression, Defense, Tenaciousness, Detection, Fire, Movement, All Things Rustic, Control), one column per spell level band, the count of spells offered at that level; the Movement fifth-level cell pins 0 - its row never prints; the Control overflow row rides wzdCtlOverflowCount; the totals pin 206 offered, 22 changed, 54 new (print 10-15)",
      "cols" = { "wzdOfferL1", "wzdOfferL2", "wzdOfferL3", "wzdOfferL4", "wzdOfferL5", "wzdOfferL6", "wzdOfferL7", "wzdOfferL8" },
      "col_comments" = { "the spells offered at First Level (print 10-12)", "the spells offered at Second Level (print 10-12)", "the spells offered at Third Level (print 10-12)", "the spells offered at Fourth Level (print 10-12)", "the spells offered at Fifth Level - the Movement row pins 0, no row prints (print 10-12)", "the spells offered at Sixth Level (print 10-12)", "the spells offered at Seventh Level (print 10-12)", "the spells offered at Eighth Level (print 10-12)" },
      "data" = { { 3, 2, 4, 5, 2, 2, 4, 3 }, { 2, 3, 7, 2, 3, 3, 3, 6 }, { 1, 2, 3, 4, 7, 3, 2, 3 }, { 3, 4, 4, 3, 2, 2, 1, 1 }, { 2, 2, 2, 2, 2, 2, 2, 2 }, { 3, 4, 2, 5, 0, 4, 3, 3 }, { 3, 4, 8, 5, 8, 5, 3, 3 }, { 3, 3, 3, 2, 3, 4, 5, 5 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wzdChanceLevel'](0) != 1 or m['wzdChancePercent'](0) != 100 or m['wzdChancePercent'](1) != 85 or m['wzdChancePercent'](2) != 75 or m['wzdChancePercent'](3) != 50 or m['wzdChancePercent'](4) != 40 or m['wzdChancePercent'](5) != 30 or m['wzdChancePercent'](6) != 20 or m['wzdChancePercent'](7) != 10 or m['wzdChanceLevels']() != 8",
      "note" = "the chance grid - 100 at first, 85, 75, 50, 40, 30, 20 down to 10 at eighth (print 10)",
    }, {
      "expr" = "m['wzdExampleWizardLevel']() != 5 or m['wzdExampleSpellLevel']() != 6 or m['wzdExampleBonusPercent']() != 20 or m['wzdExampleBasePercent']() != 30 or m['wzdExampleRollMax']() != 50 or m['wzdExampleFailMin']() != 51 or m['wzdChanceBonusPerLevel']() != 5 or m['wzdSpellsPerLevel']() != 2",
      "note" = "the Ward worked example - a fifth-level fire wizard casting a sixth-level heat ray: +20 percent, base 30, the 1-50 roll, 51 fails, the +5 per level over first and the two-spells-per-level pick (print 10)",
    }, {
      "expr" = "m['wzdOfferL1'](0) != 3 or m['wzdOfferL8'](0) != 3 or m['wzdOfferL8'](1) != 6 or m['wzdOfferL3'](2) != 3 or m['wzdOfferL5'](5) != 0 or m['wzdOfferL3'](6) != 8 or m['wzdOfferL5'](7) != 3 or m['wzdOfferL4'](5) != 5",
      "note" = "the offer grid edges - aggression three at first and three at eighth, defense six at eighth, tenaciousness three at third, the movement fifth-level zero and its five at fourth, rustic eight at third, control three at fifth (print 10-12)",
    }, {
      "expr" = "m['wzdTotalSpellsOffered']() != 206 or m['wzdCtlOverflowCount']() != 3 or m['wzdMarkedChanged']() != 22 or m['wzdMarkedNew']() != 54 or m['wzdWizardTypes']() != 8 or m['wzdChangedSpellMarkStars']() != 1 or m['wzdNewSpellMarkStars']() != 2",
      "note" = "the roster census - 206 spells offered across the eight lists, the unlabeled three-spell Control overflow row, 22 changed with the single star, 54 new with the double star (print 10-15)",
    }, {
      "expr" = "m['wzdAggMagicMissileArrowsPerLevel']() != 1 or m['wzdAggHoldPersonMax']() != 6 or m['wzdAggHoldPersonOldMax']() != 4 or m['wzdAggMagicSpearBase']() != 3 or m['wzdAggMagicSpearPerBand']() != 1 or m['wzdAggMagicSpearLevelsPerBand']() != 4 or m['wzdAggDancingSwordPlus']() != 1 or m['wzdAggDancingSwordTurns']() != 4 or m['wzdAggMeltHotTurn']() != 1 or m['wzdAggMeltMeltTurn']() != 2",
      "note" = "the aggression explanations - the extra missile arrow per level, Hold Person 1-6 over the old 1-4, the Magic Spear three-plus-one per four levels, the Dancing Magic Sword plus 1 for four turns, the Melt red-hot in one turn melting the next (print 12)",
    }, {
      "expr" = "m['wzdDefShieldArmorClass']() != 2 or m['wzdDefShieldTurns']() != 5 or m['wzdDefProtEvilToHitPenalty']() != 1 or m['wzdDefProtEvilTurns']() != 6 or m['wzdDefProtSwordsTurns']() != 4 or m['wzdDefRepulsionTurns']() != 2 or m['wzdDefEtherialnessTurns']() != 3 or m['wzdDefNoPuncturesTurns']() != 3",
      "note" = "the defense explanations - Shield AC 2 for five turns plus level, Protection from Evil minus one to hit for six turns, Protection from Swords four turns plus level, Repulsion Field two plus level, Etherialness three plus level, No Punctures three (print 12)",
    }, {
      "expr" = "m['wzdCtlSleepTwoBeings']() != 2 or m['wzdCtlSleepFiveDice']() != 5 or m['wzdCtlSleepOneBeing']() != 1 or m['wzdCtlSleepSixDice']() != 6 or m['wzdCtlGolemSaveLevel']() != 14 or m['wzdCtlStaffUses']() != 1 or m['wzdRusEarthElementalDice']() != 20 or m['wzdRusCommuneTurns']() != 10 or m['wzdRusSummonVanishTurns']() != 1 or m['wzdRusCommandStaffUses']() != 1",
      "note" = "the control and rustic explanations - the Sleep draws two beings at five dice and one at six, the golem saving as a 14th level wizard, the staff commands once, the 20 die earth elemental, the ten-turn communicates, the summons vanishing after one full turn (print 13)",
    }, {
      "expr" = "m['wzdTenWizardLockDispels']() != 2 or m['wzdTenHoldRadiusYards']() != 60 or m['wzdTenHoldSwordsTurnsMin']() != 2 or m['wzdTenHoldSwordsTurnsMax']() != 20 or m['wzdTenHoldStaffTurnsMin']() != 3 or m['wzdTenHoldStaffTurnsMax']() != 30 or m['wzdTenHoldMonsterTurnsMin']() != 1 or m['wzdTenHoldMonsterTurnsMax']() != 10 or m['wzdTenStopMagicRadiusYards']() != 30 or m['wzdTenStopMagicTurns']() != 6 or m['wzdTenHoldGroupsMaxBeings']() != 12 or m['wzdTenOpeningsHeightFeet']() != 40 or m['wzdTenOpeningsWidthFeet']() != 30 or m['wzdTenOpeningsHours']() != 24 or m['wzdTenLockOpeningsHours']() != 1",
      "note" = "the tenaciousness explanations - two dispels on the wizard lock, the 60 yard holds at 2-20, the 3-30 staff and rings, the 1-10 monster hold, Stop Magic at 30 yards for six turns, the 12-being group hold, the 40 by 30 foot openings for 24 hours, the locked openings one hour (print 13)",
    }, {
      "expr" = "m['wzdDetFindTrapsTurnsMin']() != 1 or m['wzdDetFindTrapsTurnsMax']() != 4 or m['wzdDetEndSurpriseTurnsMin']() != 1 or m['wzdDetEndSurpriseTurnsMax']() != 6 or m['wzdDetRevealHours']() != 24 or m['wzdDetDivineHours']() != 24 or m['wzdDetTransportBeingsMin']() != 1 or m['wzdDetTransportBeingsMax']() != 6 or m['wzdDetTransportRangeFeet']() != 20 or m['wzdDetStudyHours']() != 6",
      "note" = "the detection explanations - Find Traps 1-4 plus level, End Surprise 1-6 plus level, the 24-hour Reveal and Divine, the Transport carrying 1-6 beings within 20 feet, the over-6-hours study (print 13)",
    }, {
      "expr" = "m['wzdFireBallBonusPerDie']() != 1 or m['wzdFireWallDice']() != 10 or m['wzdFireWallTurnsMin']() != 1 or m['wzdFireWallTurnsMax']() != 4 or m['wzdFireElementalDice']() != 20 or m['wzdFireResistTurnsMin']() != 1 or m['wzdFireResistTurnsMax']() != 10 or m['wzdFireHeatRayDice']() != 10 or m['wzdFireHeatRayTurns']() != 1 or m['wzdFireImmunityRadiusYards']() != 10 or m['wzdFireCombustDicePerTurn']() != 5 or m['wzdFireVisionTurnsMin']() != 5 or m['wzdFireVisionTurnsMax']() != 50",
      "note" = "the fire explanations - the +1 per die fire ball, the 10 die wall persisting 1-4, the 20 die elemental, Fire Resistance 1-10, the 10-dice Heat Ray in one turn, Immunity over 10 yards for 1-10, the five dice per turn Combustion, the 5-50 Fire Vision (print 13)",
    }, {
      "expr" = "m['wzdMovWaterTravelTurns']() != 5 or m['wzdMovNegateFlyTurnsMin']() != 1 or m['wzdMovNegateFlyTurnsMax']() != 5 or m['wzdMovNegateWaterTurnsMin']() != 1 or m['wzdMovNegateWaterTurnsMax']() != 6 or m['wzdMovMassTeleportBeings']() != 20 or m['wzdMovEtherialnessTurns']() != 3 or m['wzdMovEndBarrierTurnsMin']() != 1 or m['wzdMovEndBarrierTurnsMax']() != 10",
      "note" = "the movement explanations - Water Travel five full turns, Negate Fly 1-5, Negate Water 1-6, the 20-being Mass Teleport, Etherialness three plus level, End All Barriers 1-10 (print 15)",
    } },
  "audit" = {
      "label" = "R932 issue-17 wizard article part two audit",
      "comment" = "THE DRAGON ISSUE-17 OPENER PART TWO - A Wizard With A Difference by James M. Ward (print 10-13, PDF 12-15, the Movement explanations riding print 15, PDF 17), the eight specialized wizard variants: the chance-of-making grid (100, 85, 75, 50, 40, 30, 20, 10 at First through Eighth Level, plus 5 percent per caster level over the first, two spells picked per level, the worked fifth-level heat-ray example with its +20 and the 1-50 roll), the spell-offer count grid (the eight types by the eight level bands, 206 spells offered, the Movement fifth-level row never printing, the unlabeled three-spell Control overflow row, 22 changed spells and 54 new spells under the printed one-star and two-star legend), and the explanation doctrines: the wizard of aggression (the Magic Missile extra arrow per level, the Hold Person 1-6 over 1-4, the Magic Spear three-plus-one per four levels, the Dancing Magic Sword plus 1 for four turns, the Melt red-hot-in-one-turn melt-the-next with the plate-mail mass limit), the wizard of defense (Shield AC 2 for five turns plus level, the chaotic minus-one Protection from Evil for six turns, the sword and edged-weapon and all-weapons protections with the save-to-hit doctrine, the Repulsion Field, the Etherialness, the No Punctures with its instant unfelt healing), the wizard of all things rustic (the ten-turn communicates, the 20-die thinking earth elemental that vanishes rather than turns on a lapsing caster, the feline, canine and avian summons with the Roc excluded and the one-full-turn vanish), the wizard of control (the Sleep draws of two beings at five dice and one at six, the staff-of-commanding once, the Charm Golems cutting golem protection down to the 14th-level save), the wizard of tenaciousness (the two-dispel wizard lock, the 60-yard sword and crossbow holds at 2-20, the 3-30 staffs and rings, the 1-10 monster hold stopping regeneration and breath, the 30-yard six-turn Stop Magic, the 12-being group hold, the 40-by-30 foot openings lasting 24 hours with the caster free to leave, the one-hour dispel-only locked openings, the End Arcane Walls), the wizard of detection (the 1-4-plus-level Find Traps, the 1-6-plus-level End Surprise, the 24-hour Reveal the Way and Divine Any Object, the Transport to the Spot carrying 1-6 beings within 20 feet after the over-six-hour study), the wizard of fire (the +1 per die fire ball that never touches its caster but does his equipment, the 10-die wall persisting 1-4, the 20-die thinking elemental, Fire Resistance 1-10, the 10-dice Heat Ray striking even fire types, the 10-yard 1-10 Fire Immunity, the five-dice-per-turn Combustion, the 5-50 Fire Vision), and the wizard of movement (the Water Travel five full turns, the Negate Fly 1-5, the Negate Water 1-6, the run-toward-the-fled Negate, the 20-being Mass Teleport, the three-plus-level Etherialness, the twice-printed End All Barriers with both its 1-10 vanish and its giant-disintegrate readings pinned, the Safe Teleport that never comes high or low). The pin IS the conversion: OD&D-era ink adjudicated to 1e terms, noted never silent; the as-scanned garbles ride the data file and the comments.",
    },
}
