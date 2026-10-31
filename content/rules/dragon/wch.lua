-- wch: promoted from tools/spec_r902.json (the The Dragon issue-5 opener - the Witchcraft Supplement (folios 4-9), the Anhkheg lore pin (folios 12, 28) and the Wizard Research Rules (folios 24-26, 28));
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 902,
  "prefix" = "wch",
  "banner" = {
      "title" = "The Dragon issue-5 opener - the Witchcraft Supplement (folios 4-9), the Anhkheg lore pin (folios 12, 28) and the Wizard Research Rules (folios 24-26, 28)",
      "provenance" = "Pinned from The Dragon Vol. 1 No. 5 (March 1977), the archive.org scan. The Witchcraft Supplement - the anonymous ms. the editor could not attribute, received over fifteen months prior: the witch encounter doctrine (rolls 5 or 7 on the wilderness chart, the 35/65 Lawful/Chaotic split), the 12-sided Order ladder (Low 1-8, High 9-11, Secret 12, one Secret means all Secret), the spell quotas (good 7, Priestess 10 plus one weekly, Low 4 Minor, High 4 Minor and 2 Major, Secret 6 Group A and 3 Group B), the spell matrix ranges and durations, the covens' trade economy (the willingness die, the Table A and B price bands, the 10 gp instructress) and the lair treasure caches by lair type. The Anhkheg - the Featured Creature at folios 12 and 28, its first magazine appearance, pinned lore-against-def: the merged MM1 ankheg def exists, so the print rides the bulette/Remorhaz precedent with its divergences (lair 25 vs 15, enzyme 1-10 vs 1-4, treasure B2 vs C) noted, never silent. The Wizard Research Rules by Charles Preston Goforth, Jr. - the spell research ladder (20 percent at every level, the investment doubling per level), the +1 and serious enchanting costs, the duplication, the ringmaking ladders up to the True Ring, the Wizard Blade with its d8 property roll over the 11-property list, and the Memorial Enchanting In Distress. The voice rides extract/dragon/005/ (all 32 issue pages, the chat-side DjVu OCR transcript); the issue-5 gap report ships pre-flip. The editor's standing caution rides: none of this is official.",
      "sentinel" = "The variant-layer doctrine holds: Dragon ink is never core 1e canon. The Witchcraft Supplement and the Wizard Research Rules pin as variant layers with provenance; the Anhkheg rides the lore-against-def precedent against the merged MM1 def - the print divergences (the 25 vs 15 lair percent, the 1-10 vs 1-4 enzyme, the B2 vs C treasure, the 1-6-dice acid squirt vs the def 8-32) noted in the audit, never silent, and no new registry def is created. The witchcraft wilderness encounter table is scoped out on OCR garble per the standing caution - the clean scalars pin, the garbled grid does not; the lair treasure table pins the printed cache bands with the Secret lair unprinted jewelry line as the 0 sentinel and its ring and Secret-item extras in the audit note; the spell matrix pins R and D as printed with 0 the no-printed-duration sentinel; the research ladder pins the doubling investments exactly as printed at all ten levels.",
    },
  "consts" = { {
      "name" = "wchAnhkhegNaMin",
      "value" = 1,
      "comment" = "the Anhkheg number appearing, minimum - 1 (folio 12)",
    }, {
      "name" = "wchAnhkhegNaMax",
      "value" = 6,
      "comment" = "the Anhkheg number appearing, maximum - 6 (folio 12)",
    }, {
      "name" = "wchAnhkhegLengthMin",
      "value" = 10,
      "comment" = "the Anhkheg length, minimum - 10 feet (folio 12)",
    }, {
      "name" = "wchAnhkhegLengthMax",
      "value" = 20,
      "comment" = "the Anhkheg length, maximum - 20 feet (folio 12)",
    }, {
      "name" = "wchAnhkhegAcOverall",
      "value" = 2,
      "comment" = "the Anhkheg armor class, the brown chitin overall - 2 (folio 12)",
    }, {
      "name" = "wchAnhkhegAcUnder",
      "value" = 4,
      "comment" = "the Anhkheg armor class, the pink underside - 4 (folio 12)",
    }, {
      "name" = "wchAnhkhegMoveSurface",
      "value" = 12,
      "comment" = "the Anhkheg movement - 12 inches on the surface (folio 12)",
    }, {
      "name" = "wchAnhkhegMoveBurrow",
      "value" = 6,
      "comment" = "the Anhkheg movement - 6 through the ground (folio 12)",
    }, {
      "name" = "wchAnhkhegHdMin",
      "value" = 3,
      "comment" = "the Anhkheg hit dice, minimum - 3 (folio 12)",
    }, {
      "name" = "wchAnhkhegHdMax",
      "value" = 8,
      "comment" = "the Anhkheg hit dice, maximum - 8 (folio 12)",
    }, {
      "name" = "wchAnhkhegHdDieSides",
      "value" = 8,
      "comment" = "the Anhkheg hit-die type - 8 sided (folio 12)",
    }, {
      "name" = "wchAnhkhegLairPct",
      "value" = 25,
      "comment" = "the Anhkheg percent in lair - 25 (folio 12); the merged MM1 def carries 15 - the print divergence noted, never silent",
    }, {
      "name" = "wchAnhkhegBiteMin",
      "value" = 3,
      "comment" = "the Anhkheg bite damage, minimum - 3 points (folio 12)",
    }, {
      "name" = "wchAnhkhegBiteMax",
      "value" = 18,
      "comment" = "the Anhkheg bite damage, maximum - 18 points (folio 12)",
    }, {
      "name" = "wchAnhkhegAcidDiceMax",
      "value" = 6,
      "comment" = "the Anhkheg acid squirt - up to 1-6 dice of damage according to size (folio 12); the merged MM1 def carries the 8-32 squirt - the divergence noted",
    }, {
      "name" = "wchAnhkhegAcidRangeFeet",
      "value" = 30,
      "comment" = "the Anhkheg acid squirt range - 30 feet (folio 28)",
    }, {
      "name" = "wchAnhkhegAcidRechargeHours",
      "value" = 6,
      "comment" = "the Anhkheg acid squirt rate - once per six hours, with digestion suspended the same length (folio 28)",
    }, {
      "name" = "wchAnhkhegEnzymeMin",
      "value" = 1,
      "comment" = "the Anhkheg digestive enzyme, minimum - 1 point per turn until the prey dissolves (folio 28)",
    }, {
      "name" = "wchAnhkhegEnzymeMax",
      "value" = 10,
      "comment" = "the Anhkheg digestive enzyme, maximum - 10 points per turn (folio 28); the merged MM1 def carries 1-4 - the divergence noted",
    }, {
      "name" = "wchAnhkhegAmbushMin",
      "value" = 5,
      "comment" = "the Anhkheg ambush depth, minimum - 5 feet under the ground (folio 28)",
    }, {
      "name" = "wchAnhkhegAmbushMax",
      "value" = 10,
      "comment" = "the Anhkheg ambush depth, maximum - 10 feet under the ground (folio 28)",
    }, {
      "name" = "wchWitchWildRollA",
      "value" = 5,
      "comment" = "the wilderness witch encounter roll, first - 5 on the die means witches present 50 percent of the time (folio 4)",
    }, {
      "name" = "wchWitchWildRollB",
      "value" = 7,
      "comment" = "the wilderness witch encounter roll, second - 7 (folio 4)",
    }, {
      "name" = "wchWitchLawfulPct",
      "value" = 35,
      "comment" = "the witch alignment split - Lawful 35 percent of the time (folio 4)",
    }, {
      "name" = "wchWitchChaoticPct",
      "value" = 65,
      "comment" = "the witch alignment split - Chaotic 65 percent (folio 4)",
    }, {
      "name" = "wchWitchOrderDieSides",
      "value" = 12,
      "comment" = "the chaotic witch Order check - a 12-sided die, checked per witch (folio 4)",
    }, {
      "name" = "wchWitchOrderLowMin",
      "value" = 1,
      "comment" = "the Low Order band, minimum - 1 on the 12-sided die (folio 4)",
    }, {
      "name" = "wchWitchOrderLowMax",
      "value" = 8,
      "comment" = "the Low Order band, maximum - 8 (folio 4)",
    }, {
      "name" = "wchWitchOrderHighMin",
      "value" = 9,
      "comment" = "the High Order band, minimum - 9 (folio 4)",
    }, {
      "name" = "wchWitchOrderHighMax",
      "value" = 11,
      "comment" = "the High Order band, maximum - 11 (folio 4)",
    }, {
      "name" = "wchWitchOrderSecretRoll",
      "value" = 12,
      "comment" = "the forbidden Secret Order - a roll of 12; one Secret witch present means all present are (folio 4)",
    }, {
      "name" = "wchSecretWitchLairPct",
      "value" = 75,
      "comment" = "the Secret Order witch in lair - 75 percent of the time, in any terrain (folio 4)",
    }, {
      "name" = "wchGoodWitchSpellsDaily",
      "value" = 7,
      "comment" = "a good (Lawful) witch performs 7 spells per day (folio 4)",
    }, {
      "name" = "wchPriestessAncientPct",
      "value" = 4,
      "comment" = "the chance a Lawful witch encountered is ancient - 4 percent, qualifying her as a Priestess (folio 4)",
    }, {
      "name" = "wchPriestessSpellsDaily",
      "value" = 10,
      "comment" = "a Priestess performs any ten ordinary spells daily (folio 4)",
    }, {
      "name" = "wchPriestessWeeklySpells",
      "value" = 1,
      "comment" = "a Priestess may employ one of her own more powerful spells each week (folio 4)",
    }, {
      "name" = "wchPriestessSaveLevel",
      "value" = 11,
      "comment" = "a Priestess has saving throws equal to an eleventh level wizard (folio 4)",
    }, {
      "name" = "wchLowWitchMinorDaily",
      "value" = 4,
      "comment" = "a Low Order witch performs four Minor spells daily (folio 4)",
    }, {
      "name" = "wchHighWitchMinorDaily",
      "value" = 4,
      "comment" = "a High Order witch performs four Minor spells daily (folio 4)",
    }, {
      "name" = "wchHighWitchMajorDaily",
      "value" = 2,
      "comment" = "a High Order witch performs two Major spells daily (folio 4)",
    }, {
      "name" = "wchSecretGroupADaily",
      "value" = 6,
      "comment" = "a Secret Order witch performs 6 Group A spells daily (folio 7)",
    }, {
      "name" = "wchSecretGroupBDaily",
      "value" = 3,
      "comment" = "a Secret Order witch performs 3 Group B spells daily (folio 7)",
    }, {
      "name" = "wchSecretWitchSneakPct",
      "value" = 50,
      "comment" = "the Secret witch near her lair - impossible to surprise, a 50 percent chance of sneaking up (folio 7)",
    }, {
      "name" = "wchSecretItemMinLevel",
      "value" = 13,
      "comment" = "the Secret witch items - usable only by a Priestess, a High Order evil witch, or a wizard above the 13th level (folio 7)",
    }, {
      "name" = "wchPriestessLocatePriceGp",
      "value" = 10000,
      "comment" = "the Priestess super-Locate performance price - a magic item or 10,000 gold pieces, whichever seems more valuable (folio 4)",
    }, {
      "name" = "wchWitchTrainFeeGp",
      "value" = 10,
      "comment" = "a witch instructress earns 10 gold pieces per student per object (folio 8)",
    }, {
      "name" = "wchSellDieWillingMax",
      "value" = 3,
      "comment" = "the willingness die - 1-3 on a six-sided die, she sells at the indicated price (folio 9)",
    }, {
      "name" = "wchSellDieDoubleRoll",
      "value" = 4,
      "comment" = "the willingness die - 4, she asks double the usual price (folio 9)",
    }, {
      "name" = "wchSellDieRefuseMin",
      "value" = 5,
      "comment" = "the willingness die - 5-6, she refuses to part with the item (folio 9)",
    }, {
      "name" = "wchSellDieRefuseMax",
      "value" = 6,
      "comment" = "the willingness die refuse band, maximum - 6 (folio 9)",
    }, {
      "name" = "wchTableACostMin",
      "value" = 6000,
      "comment" = "a Table A witch item costs 6-15 thousand gold pieces or equivalent (folio 9)",
    }, {
      "name" = "wchTableACostMax",
      "value" = 15000,
      "comment" = "the Table A cost band, maximum - 15 thousand (folio 9)",
    }, {
      "name" = "wchTableBCostMin",
      "value" = 10000,
      "comment" = "a Table B witch item - magic items plus 10-50,000 gold pieces, by hard bargaining (folio 9)",
    }, {
      "name" = "wchTableBCostMax",
      "value" = 50000,
      "comment" = "the Table B gold band, maximum - 50,000 (folio 9)",
    }, {
      "name" = "wchTreasureMapCutPct",
      "value" = 20,
      "comment" = "a witch commonly asks 20 percent of the haul for a treasure map (folio 9)",
    }, {
      "name" = "wchMapAllianceRollMax",
      "value" = 4,
      "comment" = "the treasure-map alliance die - 1-4 on a six-sided die and the witch joins the expedition as an ally (folio 9)",
    }, {
      "name" = "wchSkullRegenPerTurn",
      "value" = 5,
      "comment" = "the Skull of Death - the wearer regenerates 5 points per turn, even if killed unless beheaded (folio 7)",
    }, {
      "name" = "wchSkullUndeadDiceMax",
      "value" = 3,
      "comment" = "the Skull of Death - mental command of undead up to three dice at any range (folio 7)",
    }, {
      "name" = "wchLuckCharmDieSides",
      "value" = 20,
      "comment" = "the Luck Charm strength check - a 20-sided die roll per category (folios 9, 28)",
    }, {
      "name" = "wchGuardianEggWeightGp",
      "value" = 250,
      "comment" = "the Guardian Egg brass orb weighs as much as 250 gold pieces (folio 9)",
    }, {
      "name" = "wchGuardianEggReuseHours",
      "value" = 48,
      "comment" = "the Guardian Egg servant - employable once every 48 hours, until the next sunrise (folio 9)",
    }, {
      "name" = "wchGuardianEggServantAc",
      "value" = 2,
      "comment" = "the Guardian Egg metal servants - armor class 2 by their metal bodies (folio 9)",
    }, {
      "name" = "wchGuardianEggGiantDice",
      "value" = 8,
      "comment" = "the Guardian Egg on the ground - a metal Hill Giant of 8 dice (folio 9)",
    }, {
      "name" = "wchGuardianEggRocDice",
      "value" = 8,
      "comment" = "the Guardian Egg thrown in the air - a metal Roc of 8 dice (folio 9)",
    }, {
      "name" = "wchGuardianEggTurtleDice",
      "value" = 10,
      "comment" = "the Guardian Egg in a pool - a 7 foot Dragon Turtle of 10 dice (folio 9)",
    }, {
      "name" = "wchHornetCapeSpeed",
      "value" = 36,
      "comment" = "the Hornet Cape flight - 36 inches per turn indefinitely (folio 8)",
    }, {
      "name" = "wchHornetCapeCommandRange",
      "value" = 50,
      "comment" = "the Hornet Cape commands flying creatures within 50 inches, lost on touchdown (folio 8)",
    }, {
      "name" = "wchHornetCapeStingsPerTurn",
      "value" = 3,
      "comment" = "the Hornet Cape - as many as three stings per turn (folio 8)",
    }, {
      "name" = "wchHornetCapeStingRange",
      "value" = 7,
      "comment" = "the Hornet Cape sting - a 7 inch range (folio 8)",
    }, {
      "name" = "wchHornetCapeStingDice",
      "value" = 3,
      "comment" = "the Hornet Cape sting - 3 dice of damage (folio 8)",
    }, {
      "name" = "wchSeedSatchelMin",
      "value" = 7,
      "comment" = "the Seed Satchel - a package of 7-12 magic seeds (folio 8)",
    }, {
      "name" = "wchSeedSatchelMax",
      "value" = 12,
      "comment" = "the Seed Satchel count, maximum - 12 seeds (folio 8)",
    }, {
      "name" = "wchSeedFeatureHours",
      "value" = 1,
      "comment" = "a seed feature disappears in one hour, the seed usable once (folio 8)",
    }, {
      "name" = "wchWandSpellsDaily",
      "value" = 7,
      "comment" = "the Witch Wand performs 7 spells each day, for years before the power wanes (folio 7)",
    }, {
      "name" = "wchSerpentBeltStretchFeet",
      "value" = 10,
      "comment" = "the Serpent Belt can stretch to 10 feet (folio 8)",
    }, {
      "name" = "wchSerpentBeltDamageDice",
      "value" = 2,
      "comment" = "the Serpent Belt - 2 dice of damage to targets (folio 8)",
    }, {
      "name" = "wchPotionCauldronLairMin",
      "value" = 3,
      "comment" = "a lair with three or more witches holds a Potion Cauldron (folio 8)",
    }, {
      "name" = "wchPotionPriceMin",
      "value" = 500,
      "comment" = "witch potions cost between 500 gold pieces (folio 8)",
    }, {
      "name" = "wchPotionPriceMax",
      "value" = 3000,
      "comment" = "and 3000 gold pieces, by a die roll (folio 8)",
    }, {
      "name" = "wchBroomFlyingPct",
      "value" = 35,
      "comment" = "a witch out of the lair is flying her broom 35 percent of the time, at 4 to 40 feet (folio 8)",
    }, {
      "name" = "wchLoveLocketCutPct",
      "value" = 20,
      "comment" = "the Love Locket - a good witch accepts no more than 20 percent of the victim's wealth (folio 9)",
    }, {
      "name" = "wchLoveLocketItemMax",
      "value" = 2,
      "comment" = "the Love Locket - no more than 2 magic items kept (folio 9)",
    }, {
      "name" = "wchDartRingShotsPerTurn",
      "value" = 2,
      "comment" = "the Dart Ring fires twice per turn up to 30 feet, inexhaustible and never missing (folio 9)",
    }, {
      "name" = "wchDartRingRangeFeet",
      "value" = 30,
      "comment" = "the Dart Ring range - 30 feet (folio 9)",
    }, {
      "name" = "wchThornTwineLengthFeet",
      "value" = 40,
      "comment" = "the Thorn Twine - a 40 foot thorn vine flexible as rope (folio 9)",
    }, {
      "name" = "wchThornTwineDicePerTurn",
      "value" = 4,
      "comment" = "the Thorn Twine - 4 dice of damage each turn the victim stays ensnared (folio 9)",
    }, {
      "name" = "wchHillSeedNumberMin",
      "value" = 1,
      "comment" = "the Table B Hill Seeds come 1-3 in number (folio 9)",
    }, {
      "name" = "wchHillSeedNumberMax",
      "value" = 3,
      "comment" = "the Hill Seeds count, maximum - 3 (folio 9)",
    }, {
      "name" = "wchSpellMatrixCount",
      "value" = 21,
      "comment" = "the wchSpellMatrix row count - 21 rows as scanned",
    }, {
      "name" = "wchLairTreasureCount",
      "value" = 4,
      "comment" = "the wchLairTreasure row count - 4 rows as scanned",
    }, {
      "name" = "wchResearchSuccessPct",
      "value" = 20,
      "comment" = "the spell research chance of success - 20 percent at every level, the certain line doubling the investment (folio 24)",
    }, {
      "name" = "wchEnchantPlusOneMonths",
      "value" = 2,
      "comment" = "anything enchanted to +1 - 2 months (folio 24)",
    }, {
      "name" = "wchEnchantPlusOneGp",
      "value" = 2000,
      "comment" = "the +1 enchantment investment - 2,000 gold pieces (folio 24)",
    }, {
      "name" = "wchSeriousEnchantMonths",
      "value" = 10,
      "comment" = "serious enchanting above +1 - 10 months (folio 24)",
    }, {
      "name" = "wchSeriousEnchantGp",
      "value" = 10000,
      "comment" = "the serious enchantment investment - 10,000 gold pieces (folio 24)",
    }, {
      "name" = "wchDuplicateGp",
      "value" = 10000,
      "comment" = "enchanting a duplicate - 10,000 gold pieces (folio 26)",
    }, {
      "name" = "wchDuplicateMonths",
      "value" = 10,
      "comment" = "the duplication time - 10 months times the Miscellaneous Magic Table number (folio 26)",
    }, {
      "name" = "wchRingMakeGp",
      "value" = 10000,
      "comment" = "serious ringmaking - 10,000 gold pieces (folio 26)",
    }, {
      "name" = "wchRingMakeMonths",
      "value" = 10,
      "comment" = "the serious ringmaking time - 10 months (folio 26)",
    }, {
      "name" = "wchTrueRingGp",
      "value" = 10000,
      "comment" = "the True Ring - 10,000 gold pieces (folio 26)",
    }, {
      "name" = "wchTrueRingMonths",
      "value" = 10,
      "comment" = "the True Ring time - 10 months (folio 26)",
    }, {
      "name" = "wchTrueRingXp",
      "value" = 300000,
      "comment" = "the True Ring experience point cost - 300,000, drained and permanently lost (folio 26)",
    }, {
      "name" = "wchWizardBladeGp",
      "value" = 10000,
      "comment" = "the Wizard Blade - 10,000 gold pieces (folio 26)",
    }, {
      "name" = "wchWizardBladeMonths",
      "value" = 10,
      "comment" = "the Wizard Blade time - 10 months (folio 26)",
    }, {
      "name" = "wchWizardBladeXp",
      "value" = 200000,
      "comment" = "the Wizard Blade experience point cost - 200,000, drained and permanently lost (folio 26)",
    }, {
      "name" = "wchWizardBladeDieSides",
      "value" = 8,
      "comment" = "the Wizard Blade - roll one 8-sided die and choose that many properties (folio 26)",
    }, {
      "name" = "wchWizardBladePropertyCount",
      "value" = 11,
      "comment" = "the Wizard Blade property list - 11: flaming, a purpose, another purpose, vorpal blade, a curse, another curse, life draining, sharpness, holy, dancing, disruption (folio 26)",
    }, {
      "name" = "wchWizardBladeLevelMax",
      "value" = 6,
      "comment" = "the Wizard Blade named level, maximum - +6 (folio 26)",
    }, {
      "name" = "wchWizardBladeLevelMin",
      "value" = -6,
      "comment" = "the Wizard Blade named level, minimum - -6 (folio 26)",
    }, {
      "name" = "wchWandStaffCharges",
      "value" = 100,
      "comment" = "embedded rings carry unlimited charges; wands and staffs 100 charges of the new spell (folio 26)",
    }, {
      "name" = "wchMemorialEnchantDie",
      "value" = 8,
      "comment" = "the Sorcerer's Memorial Enchanting In Distress - roll one 8-sided die for hits, the magical distress hits uncured by time or healing (folios 26, 28)",
    }, {
      "name" = "wchBladeLargerDie300k",
      "value" = 12,
      "comment" = "the larger Wizard Blade rolls - 300,000 experience points buys the 12-sided die (folio 26)",
    }, {
      "name" = "wchBladeLargerDie400k",
      "value" = 16,
      "comment" = "400,000 experience points buys the 16-sided die (folio 26)",
    }, {
      "name" = "wchBladeLargerDie500k",
      "value" = 20,
      "comment" = "500,000 experience points buys the 20-sided die (folio 26)",
    }, {
      "name" = "wchResearchCostCount",
      "value" = 10,
      "comment" = "the wchResearchCost row count - 10 rows as scanned",
    } },
  "bools" = { {
      "name" = "wchAnhkhegLoreAgainstDef",
      "value" = true,
      "comment" = "the Dragon-print Anhkheg rides the lore-against-def precedent (the bulette/Remorhaz line) - the merged MM1 ankheg def exists at monsters/monsters/a/ankheg.lua, so this is a provenance pin, never a competing registry def (folios 12, 28)",
    }, {
      "name" = "wchAnhkhegPrintDivergent",
      "value" = true,
      "comment" = "the Dragon print diverges from the merged MM1 def - lair 25 vs 15 percent, enzyme 1-10 vs 1-4, treasure B2 vs C - the divergences noted in the audit, never silent (folios 12, 28)",
    }, {
      "name" = "wchAnhkhegTreasureB2",
      "value" = true,
      "comment" = "the Anhkheg treasure - B2 at folio 12, pinned as scanned against the merged MM1 def's C (the divergence noted)",
    }, {
      "name" = "wchAnhkhegNeutral",
      "value" = true,
      "comment" = "the Anhkheg alignment - neutral (folio 12)",
    }, {
      "name" = "wchAnhkhegNoMagicResistance",
      "value" = true,
      "comment" = "the Anhkheg magic resistance - none (folio 12)",
    }, {
      "name" = "wchAnhkhegBurrowHunter",
      "value" = true,
      "comment" = "the Anhkheg favorite attack - lying 5-10 feet under the ground until its antenna detect prey overhead, then burrowing out directly underneath (folio 28)",
    }, {
      "name" = "wchWitchImmunities",
      "value" = true,
      "comment" = "witchcraft - including the Clerical- and wizard-resembling spells - will not affect Djinn, Efreet, or Clerics of any alignment: the three immune types (folio 4)",
    }, {
      "name" = "wchWitchSavesAsWarlock",
      "value" = true,
      "comment" = "all witches except a Priestess have saving throws equal to warlocks (folio 4)",
    }, {
      "name" = "wchWitchMagicTreatedAsSpell",
      "value" = true,
      "comment" = "saving throws against witch magic treat it as a spell on the Saving Throw Matrix (folio 4)",
    }, {
      "name" = "wchSecretWitchLoner",
      "value" = true,
      "comment" = "a Secret witch is a loner - never encountered in a group of mutually protective members (folios 4, 7)",
    }, {
      "name" = "wchSecretWitchAnyTerrain",
      "value" = true,
      "comment" = "the Secret witches may be found in ANY terrain, including water, with only one regardless of location (folio 4)",
    }, {
      "name" = "wchSecretWitchNoGear",
      "value" = true,
      "comment" = "Secret Order witches have no brooms, no crystal balls and no familiar (folio 7)",
    }, {
      "name" = "wchSecretItemClericDeath",
      "value" = true,
      "comment" = "any Cleric touching a Secret witch item meets with instant death - the Secret witches recognize no power but their own (folio 7)",
    }, {
      "name" = "wchSecretItemsGroupBNoDispel",
      "value" = true,
      "comment" = "the Secret Group B spells are not vulnerable to Dispell Magic (folio 7)",
    }, {
      "name" = "wchLairNoHighOnly",
      "value" = true,
      "comment" = "never find a lair with only High Order witches - the Curtainwall note (folio 8)",
    }, {
      "name" = "wchLawfulLairNoCurseGuard",
      "value" = true,
      "comment" = "Lawful witch lairs are not curse-guarded; good witch lairs carry ordinary manual traps (folio 8)",
    }, {
      "name" = "wchGoodWitchPolymorphFamiliar",
      "value" = true,
      "comment" = "good witches keep only small birds or fur animals, polymorphed into a dragon bodyguard in an emergency (folio 8)",
    }, {
      "name" = "wchConcentrationImmune",
      "value" = true,
      "comment" = "a witch in her circle of concentration is immune to Charm/Hold person, Sleep, feeblemind and control items (folio 8)",
    }, {
      "name" = "wchClericPoisonTouchImmune",
      "value" = true,
      "comment" = "clerics are immune to the witch's paralyzing-poison contamination, but cannot detect it (folio 5)",
    }, {
      "name" = "wchStatSpellOncePerStat",
      "value" = true,
      "comment" = "the permanent stat-increase spell - usable once per stat per character, including all clones, never stacked (folio 24)",
    }, {
      "name" = "wchEmbeddedRingsUnlimited",
      "value" = true,
      "comment" = "spells embedded in rings carry unlimited charges (folio 26)",
    }, {
      "name" = "wchNoReenchant",
      "value" = true,
      "comment" = "already enchanted objects may not be re-enchanted, though new spells may be embedded (folio 26)",
    }, {
      "name" = "wchOnlyEnchantersCreate",
      "value" = true,
      "comment" = "only wizards, patriarchs, witches and matriarchs may create or change magic items through research, in a magic furnace fed with gold (folio 24)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wchSpellMatrix",
      "tag" = "SpMx",
      "count" = "wchSpellMatrixCount",
      "sentinel" = 0,
      "cols" = { "wchSpellRange", "wchSpellDuration" },
      "col_comments" = { "the spell range in inches - R as printed (folios 4-7)", "the spell duration in turns - D as printed, 0 the sentinel for no printed duration (folios 4-7)" },
      "data" = { { 5, 0 }, { 7, 6 }, { 10, 6 }, { 5, 2 }, { 7, 3 }, { 10, 4 }, { 2, 0 }, { 7, 3 }, { 1, 0 }, { 2, 3 }, { 15, 1 }, { 7, 0 }, { 10, 6 }, { 50, 2 }, { 3, 0 }, { 3, 0 }, { 8, 2 }, { 7, 6 }, { 1, 0 }, { 5, 0 }, { 2, 36 } },
      "audit_comment" = "the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "name" = "wchLairTreasure",
      "tag" = "LrTr",
      "count" = "wchLairTreasureCount",
      "sentinel" = 0,
      "cols" = { "wchLairGpMin", "wchLairGpMax", "wchLairGemMin", "wchLairGemMax", "wchLairJewMin", "wchLairJewMax", "wchLairWiMin", "wchLairWiMax" },
      "col_comments" = { "the gold-piece cache minimum, in thousands - as printed (folio 8)", "the gold-piece cache maximum, in thousands (folio 8)", "the gem cache minimum (folio 8)", "the gem cache maximum (folio 8)", "the jewelry cache minimum - 0 the sentinel for no printed jewelry line (folio 8)", "the jewelry cache maximum (folio 8)", "the witch item cache minimum (folio 8)", "the witch item cache maximum (folio 8)" },
      "data" = { { 1, 4, 1, 10, 1, 8, 1, 3 }, { 1, 6, 6, 11, 1, 10, 1, 3 }, { 11, 20, 6, 11, 1, 8, 1, 2 }, { 1, 4, 1, 3, 0, 0, 1, 6 } },
      "audit_comment" = "the lair treasure caches by lair type - Good 1-4k GP with 1-10k SP riding the audit note, Low 1-6k, High 11-20k, Secret 1-4k with the gems of superior value and no printed jewelry line; the Secret lair extras (1 ring, 1-2 Secret witch items) ride the audit note (folio 8)",
    }, {
      "name" = "wchResearchCost",
      "tag" = "RsC",
      "count" = "wchResearchCostCount",
      "sentinel" = 0,
      "cols" = { "wchResearchWeeks", "wchResearchGold", "wchResearchGoldCertain" },
      "col_comments" = { "the research time in weeks - the spell level (folio 24)", "the gold investment at the 20 percent chance - doubling per level from 2,000 (folio 24)", "the gold investment at the 100 percent certain line - doubling per level from 10,000 (folio 24)" },
      "data" = { { 1, 2000, 10000 }, { 2, 4000, 20000 }, { 3, 8000, 40000 }, { 4, 16000, 80000 }, { 5, 32000, 160000 }, { 6, 64000, 320000 }, { 7, 128000, 640000 }, { 8, 256000, 1280000 }, { 9, 512000, 2560000 }, { 10, 1024000, 5120000 } },
      "audit_comment" = "the spell research cost ladder by spell level 1-10 - weeks equal the level, the standard investment doubling per level from 2,000 and the certain line from 10,000 (folio 24)",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wchAnhkhegNaMin']() != 1 or m['wchAnhkhegNaMax']() != 6 or m['wchAnhkhegLengthMin']() != 10 or m['wchAnhkhegLengthMax']() != 20",
      "note" = "the Anhkheg stat block - number appearing 1-6, length 10-20 feet (folio 12)",
    }, {
      "expr" = "m['wchAnhkhegAcOverall']() != 2 or m['wchAnhkhegAcUnder']() != 4 or m['wchAnhkhegMoveSurface']() != 12 or m['wchAnhkhegMoveBurrow']() != 6",
      "note" = "the Anhkheg armor classes 2 over and 4 under, the 12/6 movement (folio 12)",
    }, {
      "expr" = "m['wchAnhkhegHdMin']() != 3 or m['wchAnhkhegHdMax']() != 8 or m['wchAnhkhegHdDieSides']() != 8 or m['wchAnhkhegLairPct']() != 25",
      "note" = "the Anhkheg hit dice 3-8 on the 8-sided die, 25 percent in lair (folio 12)",
    }, {
      "expr" = "m['wchAnhkhegBiteMin']() != 3 or m['wchAnhkhegBiteMax']() != 18 or m['wchAnhkhegAcidDiceMax']() != 6 or m['wchAnhkhegAcidRangeFeet']() != 30 or m['wchAnhkhegAcidRechargeHours']() != 6",
      "note" = "the Anhkheg bite 3-18, the acid squirt up to 1-6 dice at 30 feet once per six hours (folios 12, 28)",
    }, {
      "expr" = "m['wchAnhkhegEnzymeMin']() != 1 or m['wchAnhkhegEnzymeMax']() != 10 or m['wchAnhkhegAmbushMin']() != 5 or m['wchAnhkhegAmbushMax']() != 10",
      "note" = "the Anhkheg enzyme 1-10 per turn, the 5-10 foot ambush depth (folio 28)",
    }, {
      "expr" = "m['wchAnhkhegLoreAgainstDef']() != 1 or m['wchAnhkhegPrintDivergent']() != 1 or m['wchAnhkhegTreasureB2']() != 1 or m['wchAnhkhegNeutral']() != 1 or m['wchAnhkhegNoMagicResistance']() != 1 or m['wchAnhkhegBurrowHunter']() != 1",
      "note" = "the Anhkheg doctrines - lore-against-def against the merged MM1 ankheg, the divergences noted, treasure B2, neutral, no magic resistance, the burrow ambush (folios 12, 28)",
    }, {
      "expr" = "m['wchWitchWildRollA']() != 5 or m['wchWitchWildRollB']() != 7 or m['wchWitchLawfulPct']() != 35 or m['wchWitchChaoticPct']() != 65",
      "note" = "the witch encounter doctrine - rolls 5 or 7, the 35/65 Lawful/Chaotic split (folio 4)",
    }, {
      "expr" = "m['wchWitchOrderDieSides']() != 12 or m['wchWitchOrderLowMin']() != 1 or m['wchWitchOrderLowMax']() != 8 or m['wchWitchOrderHighMin']() != 9 or m['wchWitchOrderHighMax']() != 11 or m['wchWitchOrderSecretRoll']() != 12 or m['wchSecretWitchLairPct']() != 75",
      "note" = "the 12-sided Order check - Low 1-8, High 9-11, Secret 12; the Secret lair percent (folio 4)",
    }, {
      "expr" = "m['wchGoodWitchSpellsDaily']() != 7 or m['wchPriestessAncientPct']() != 4 or m['wchPriestessSpellsDaily']() != 10 or m['wchPriestessWeeklySpells']() != 1 or m['wchPriestessSaveLevel']() != 11 or m['wchPriestessLocatePriceGp']() != 10000",
      "note" = "the good witch 7 spells daily, the 4 percent ancient Priestess - ten daily, one weekly, 11th level saves, the 10,000 gp locate (folio 4)",
    }, {
      "expr" = "m['wchLowWitchMinorDaily']() != 4 or m['wchHighWitchMinorDaily']() != 4 or m['wchHighWitchMajorDaily']() != 2 or m['wchSecretGroupADaily']() != 6 or m['wchSecretGroupBDaily']() != 3 or m['wchSecretWitchSneakPct']() != 50",
      "note" = "the spell quotas - Low 4 Minor, High 4 Minor + 2 Major, Secret 6 Group A + 3 Group B, the 50 percent sneak (folios 4, 7)",
    }, {
      "expr" = "m['wchSecretItemMinLevel']() != 13 or m['wchWitchTrainFeeGp']() != 10 or m['wchTableACostMin']() != 6000 or m['wchTableACostMax']() != 15000 or m['wchTableBCostMin']() != 10000 or m['wchTableBCostMax']() != 50000",
      "note" = "the trade economy - the 13th level Secret item bar, the 10 gp instructress fee, the Table A and B price bands (folios 7, 8, 9)",
    }, {
      "expr" = "m['wchSellDieWillingMax']() != 3 or m['wchSellDieDoubleRoll']() != 4 or m['wchSellDieRefuseMin']() != 5 or m['wchSellDieRefuseMax']() != 6 or m['wchTreasureMapCutPct']() != 20 or m['wchMapAllianceRollMax']() != 4",
      "note" = "the willingness die 1-3/4/5-6, the 20 percent map cut, the 1-4 alliance die (folio 9)",
    }, {
      "expr" = "m['wchSkullRegenPerTurn']() != 5 or m['wchSkullUndeadDiceMax']() != 3 or m['wchLuckCharmDieSides']() != 20",
      "note" = "the Secret weapons - the Skull of Death 5 points per turn regen and 3 dice undead command, the Luck Charm d20 (folios 7, 9, 28)",
    }, {
      "expr" = "m['wchGuardianEggWeightGp']() != 250 or m['wchGuardianEggReuseHours']() != 48 or m['wchGuardianEggServantAc']() != 2 or m['wchGuardianEggGiantDice']() != 8 or m['wchGuardianEggRocDice']() != 8 or m['wchGuardianEggTurtleDice']() != 10",
      "note" = "the Guardian Egg - 250 gp weight, 48 hour reuse, armor class 2, the Hill Giant 8, Roc 8 and Dragon Turtle 10 dice forms (folio 9)",
    }, {
      "expr" = "m['wchHornetCapeSpeed']() != 36 or m['wchHornetCapeCommandRange']() != 50 or m['wchHornetCapeStingsPerTurn']() != 3 or m['wchHornetCapeStingRange']() != 7 or m['wchHornetCapeStingDice']() != 3",
      "note" = "the Hornet Cape - 36 inches per turn, the 50 inch command, three 7-inch 3-dice stings per turn (folio 8)",
    }, {
      "expr" = "m['wchSeedSatchelMin']() != 7 or m['wchSeedSatchelMax']() != 12 or m['wchSeedFeatureHours']() != 1 or m['wchHillSeedNumberMin']() != 1 or m['wchHillSeedNumberMax']() != 3",
      "note" = "the Seed Satchel 7-12 seeds, one-hour features; the Hill Seeds 1-3 (folios 8, 9)",
    }, {
      "expr" = "m['wchWandSpellsDaily']() != 7 or m['wchSerpentBeltStretchFeet']() != 10 or m['wchSerpentBeltDamageDice']() != 2 or m['wchPotionCauldronLairMin']() != 3 or m['wchPotionPriceMin']() != 500 or m['wchPotionPriceMax']() != 3000 or m['wchBroomFlyingPct']() != 35",
      "note" = "the Witch Wand 7 spells, the Serpent Belt 10-foot 2-dice, the cauldron at 3+ witches, the 500-3000 potions, the 35 percent broom (folios 7, 8)",
    }, {
      "expr" = "m['wchLoveLocketCutPct']() != 20 or m['wchLoveLocketItemMax']() != 2 or m['wchDartRingShotsPerTurn']() != 2 or m['wchDartRingRangeFeet']() != 30 or m['wchThornTwineLengthFeet']() != 40 or m['wchThornTwineDicePerTurn']() != 4",
      "note" = "the good witch Love Locket 20 percent and 2 items, the Dart Ring twice per 30 feet, the 40-foot 4-dice Thorn Twine (folio 9)",
    }, {
      "expr" = "m['wchWitchImmunities']() != 1 or m['wchWitchSavesAsWarlock']() != 1 or m['wchWitchMagicTreatedAsSpell']() != 1 or m['wchClericPoisonTouchImmune']() != 1",
      "note" = "the witch doctrines - the Djinn/Efreet/Cleric immunity, warlock saves, the spell save treatment, the cleric poison-touch immunity (folios 4, 5)",
    }, {
      "expr" = "m['wchSecretWitchLoner']() != 1 or m['wchSecretWitchAnyTerrain']() != 1 or m['wchSecretWitchNoGear']() != 1 or m['wchSecretItemClericDeath']() != 1 or m['wchSecretItemsGroupBNoDispel']() != 1",
      "note" = "the Secret Order doctrines - loner, any terrain, no gear, the cleric-touch death, the no-dispel Group B (folios 4, 7)",
    }, {
      "expr" = "m['wchLairNoHighOnly']() != 1 or m['wchLawfulLairNoCurseGuard']() != 1 or m['wchGoodWitchPolymorphFamiliar']() != 1 or m['wchConcentrationImmune']() != 1",
      "note" = "the lair doctrines - no High-only lairs, no Lawful curse guard, the good witch polymorph familiar, the concentration immunity (folio 8)",
    }, {
      "expr" = "m['wchSpellRange'](0) != 5 or m['wchSpellDuration'](0) != 0 or m['wchSpellMatrixCount']() != 21",
      "note" = "the wchSpellMatrix, row 0 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](1) != 7 or m['wchSpellDuration'](1) != 6",
      "note" = "the wchSpellMatrix, row 1 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](2) != 10 or m['wchSpellDuration'](2) != 6",
      "note" = "the wchSpellMatrix, row 2 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](3) != 5 or m['wchSpellDuration'](3) != 2",
      "note" = "the wchSpellMatrix, row 3 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](4) != 7 or m['wchSpellDuration'](4) != 3",
      "note" = "the wchSpellMatrix, row 4 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](5) != 10 or m['wchSpellDuration'](5) != 4",
      "note" = "the wchSpellMatrix, row 5 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](6) != 2 or m['wchSpellDuration'](6) != 0",
      "note" = "the wchSpellMatrix, row 6 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](7) != 7 or m['wchSpellDuration'](7) != 3",
      "note" = "the wchSpellMatrix, row 7 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](8) != 1 or m['wchSpellDuration'](8) != 0",
      "note" = "the wchSpellMatrix, row 8 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](9) != 2 or m['wchSpellDuration'](9) != 3",
      "note" = "the wchSpellMatrix, row 9 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](10) != 15 or m['wchSpellDuration'](10) != 1",
      "note" = "the wchSpellMatrix, row 10 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](11) != 7 or m['wchSpellDuration'](11) != 0",
      "note" = "the wchSpellMatrix, row 11 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](12) != 10 or m['wchSpellDuration'](12) != 6",
      "note" = "the wchSpellMatrix, row 12 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](13) != 50 or m['wchSpellDuration'](13) != 2",
      "note" = "the wchSpellMatrix, row 13 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](14) != 3 or m['wchSpellDuration'](14) != 0",
      "note" = "the wchSpellMatrix, row 14 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](15) != 3 or m['wchSpellDuration'](15) != 0",
      "note" = "the wchSpellMatrix, row 15 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](16) != 8 or m['wchSpellDuration'](16) != 2",
      "note" = "the wchSpellMatrix, row 16 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](17) != 7 or m['wchSpellDuration'](17) != 6",
      "note" = "the wchSpellMatrix, row 17 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](18) != 1 or m['wchSpellDuration'](18) != 0",
      "note" = "the wchSpellMatrix, row 18 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](19) != 5 or m['wchSpellDuration'](19) != 0",
      "note" = "the wchSpellMatrix, row 19 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchSpellRange'](20) != 2 or m['wchSpellDuration'](20) != 36",
      "note" = "the wchSpellMatrix, row 20 of 21 - the Witchcraft Supplement spell matrix - range and duration as printed: Pit 5, FireBox 7/6, Diminish 10/6, Plant Entrapment 5/2, Paralyzing Pit 7/3, Undead Control 10/4, Aging 2, Circle of Blindness 7/3, Curse 1, Curtain Wall 2/3, Intensify 15/1, Wither 7, Weight Concentration 10/6, Quake 50/2, Vaporize 3, Solidify 3, Volcanic Circle 8/2, Calm 7/6, Rejuvenation 1, Dissipation 5, Comfort 2/36 (folios 4-7)",
    }, {
      "expr" = "m['wchLairGpMin'](0) != 1 or m['wchLairGpMax'](0) != 4 or m['wchLairGemMin'](0) != 1 or m['wchLairGemMax'](0) != 10 or m['wchLairJewMin'](0) != 1 or m['wchLairJewMax'](0) != 8 or m['wchLairWiMin'](0) != 1 or m['wchLairWiMax'](0) != 3 or m['wchLairTreasureCount']() != 4",
      "note" = "the wchLairTreasure, row 0 of 4 - the lair treasure caches by lair type - Good 1-4k GP with 1-10k SP riding the audit note, Low 1-6k, High 11-20k, Secret 1-4k with the gems of superior value and no printed jewelry line; the Secret lair extras (1 ring, 1-2 Secret witch items) ride the audit note (folio 8)",
    }, {
      "expr" = "m['wchLairGpMin'](1) != 1 or m['wchLairGpMax'](1) != 6 or m['wchLairGemMin'](1) != 6 or m['wchLairGemMax'](1) != 11 or m['wchLairJewMin'](1) != 1 or m['wchLairJewMax'](1) != 10 or m['wchLairWiMin'](1) != 1 or m['wchLairWiMax'](1) != 3",
      "note" = "the wchLairTreasure, row 1 of 4 - the lair treasure caches by lair type - Good 1-4k GP with 1-10k SP riding the audit note, Low 1-6k, High 11-20k, Secret 1-4k with the gems of superior value and no printed jewelry line; the Secret lair extras (1 ring, 1-2 Secret witch items) ride the audit note (folio 8)",
    }, {
      "expr" = "m['wchLairGpMin'](2) != 11 or m['wchLairGpMax'](2) != 20 or m['wchLairGemMin'](2) != 6 or m['wchLairGemMax'](2) != 11 or m['wchLairJewMin'](2) != 1 or m['wchLairJewMax'](2) != 8 or m['wchLairWiMin'](2) != 1 or m['wchLairWiMax'](2) != 2",
      "note" = "the wchLairTreasure, row 2 of 4 - the lair treasure caches by lair type - Good 1-4k GP with 1-10k SP riding the audit note, Low 1-6k, High 11-20k, Secret 1-4k with the gems of superior value and no printed jewelry line; the Secret lair extras (1 ring, 1-2 Secret witch items) ride the audit note (folio 8)",
    }, {
      "expr" = "m['wchLairGpMin'](3) != 1 or m['wchLairGpMax'](3) != 4 or m['wchLairGemMin'](3) != 1 or m['wchLairGemMax'](3) != 3 or m['wchLairJewMin'](3) != 0 or m['wchLairJewMax'](3) != 0 or m['wchLairWiMin'](3) != 1 or m['wchLairWiMax'](3) != 6",
      "note" = "the wchLairTreasure, row 3 of 4 - the lair treasure caches by lair type - Good 1-4k GP with 1-10k SP riding the audit note, Low 1-6k, High 11-20k, Secret 1-4k with the gems of superior value and no printed jewelry line; the Secret lair extras (1 ring, 1-2 Secret witch items) ride the audit note (folio 8)",
    }, {
      "expr" = "m['wchResearchSuccessPct']() != 20 or m['wchEnchantPlusOneMonths']() != 2 or m['wchEnchantPlusOneGp']() != 2000 or m['wchSeriousEnchantMonths']() != 10 or m['wchSeriousEnchantGp']() != 10000",
      "note" = "the research base - 20 percent success, the +1 at 2 months and 2,000 gp, serious enchanting 10 months and 10,000 gp (folio 24)",
    }, {
      "expr" = "m['wchDuplicateGp']() != 10000 or m['wchDuplicateMonths']() != 10 or m['wchRingMakeGp']() != 10000 or m['wchRingMakeMonths']() != 10",
      "note" = "the duplication and serious ringmaking costs (folio 26)",
    }, {
      "expr" = "m['wchTrueRingGp']() != 10000 or m['wchTrueRingMonths']() != 10 or m['wchTrueRingXp']() != 300000",
      "note" = "the True Ring - 10,000 gp, 10 months, 300,000 experience points (folio 26)",
    }, {
      "expr" = "m['wchWizardBladeGp']() != 10000 or m['wchWizardBladeMonths']() != 10 or m['wchWizardBladeXp']() != 200000 or m['wchWizardBladeDieSides']() != 8 or m['wchWizardBladePropertyCount']() != 11 or m['wchWizardBladeLevelMax']() != 6 or m['wchWizardBladeLevelMin']() != -6",
      "note" = "the Wizard Blade - 10,000 gp, 10 months, 200,000 xp, the d8 property roll over 11 properties, the named level +6 to -6 (folio 26)",
    }, {
      "expr" = "m['wchWandStaffCharges']() != 100 or m['wchMemorialEnchantDie']() != 8 or m['wchBladeLargerDie300k']() != 12 or m['wchBladeLargerDie400k']() != 16 or m['wchBladeLargerDie500k']() != 20",
      "note" = "the 100-charge wands and staffs, the Memorial d8 distress hits, the larger blade dice at 300k/400k/500k xp (folios 26, 28)",
    }, {
      "expr" = "m['wchStatSpellOncePerStat']() != 1 or m['wchEmbeddedRingsUnlimited']() != 1 or m['wchNoReenchant']() != 1 or m['wchOnlyEnchantersCreate']() != 1",
      "note" = "the research doctrines - once per stat, unlimited ring charges, no re-enchanting, only the four creator classes (folios 24, 26)",
    }, {
      "expr" = "m['wchResearchWeeks'](0) != 1 or m['wchResearchGold'](0) != 2000 or m['wchResearchGoldCertain'](0) != 10000 or m['wchResearchCostCount']() != 10",
      "note" = "the wchResearchCost, row 0 of 10 - the spell research cost ladder by spell level 1-10 - weeks equal the level, the standard investment doubling per level from 2,000 and the certain line from 10,000 (folio 24)",
    }, {
      "expr" = "m['wchResearchWeeks'](1) != 2 or m['wchResearchGold'](1) != 4000 or m['wchResearchGoldCertain'](1) != 20000",
      "note" = "the wchResearchCost, row 1 of 10 - the spell research cost ladder by spell level 1-10 - weeks equal the level, the standard investment doubling per level from 2,000 and the certain line from 10,000 (folio 24)",
    }, {
      "expr" = "m['wchResearchWeeks'](2) != 3 or m['wchResearchGold'](2) != 8000 or m['wchResearchGoldCertain'](2) != 40000",
      "note" = "the wchResearchCost, row 2 of 10 - the spell research cost ladder by spell level 1-10 - weeks equal the level, the standard investment doubling per level from 2,000 and the certain line from 10,000 (folio 24)",
    }, {
      "expr" = "m['wchResearchWeeks'](3) != 4 or m['wchResearchGold'](3) != 16000 or m['wchResearchGoldCertain'](3) != 80000",
      "note" = "the wchResearchCost, row 3 of 10 - the spell research cost ladder by spell level 1-10 - weeks equal the level, the standard investment doubling per level from 2,000 and the certain line from 10,000 (folio 24)",
    }, {
      "expr" = "m['wchResearchWeeks'](4) != 5 or m['wchResearchGold'](4) != 32000 or m['wchResearchGoldCertain'](4) != 160000",
      "note" = "the wchResearchCost, row 4 of 10 - the spell research cost ladder by spell level 1-10 - weeks equal the level, the standard investment doubling per level from 2,000 and the certain line from 10,000 (folio 24)",
    }, {
      "expr" = "m['wchResearchWeeks'](5) != 6 or m['wchResearchGold'](5) != 64000 or m['wchResearchGoldCertain'](5) != 320000",
      "note" = "the wchResearchCost, row 5 of 10 - the spell research cost ladder by spell level 1-10 - weeks equal the level, the standard investment doubling per level from 2,000 and the certain line from 10,000 (folio 24)",
    }, {
      "expr" = "m['wchResearchWeeks'](6) != 7 or m['wchResearchGold'](6) != 128000 or m['wchResearchGoldCertain'](6) != 640000",
      "note" = "the wchResearchCost, row 6 of 10 - the spell research cost ladder by spell level 1-10 - weeks equal the level, the standard investment doubling per level from 2,000 and the certain line from 10,000 (folio 24)",
    }, {
      "expr" = "m['wchResearchWeeks'](7) != 8 or m['wchResearchGold'](7) != 256000 or m['wchResearchGoldCertain'](7) != 1280000",
      "note" = "the wchResearchCost, row 7 of 10 - the spell research cost ladder by spell level 1-10 - weeks equal the level, the standard investment doubling per level from 2,000 and the certain line from 10,000 (folio 24)",
    }, {
      "expr" = "m['wchResearchWeeks'](8) != 9 or m['wchResearchGold'](8) != 512000 or m['wchResearchGoldCertain'](8) != 2560000",
      "note" = "the wchResearchCost, row 8 of 10 - the spell research cost ladder by spell level 1-10 - weeks equal the level, the standard investment doubling per level from 2,000 and the certain line from 10,000 (folio 24)",
    }, {
      "expr" = "m['wchResearchWeeks'](9) != 10 or m['wchResearchGold'](9) != 1024000 or m['wchResearchGoldCertain'](9) != 5120000",
      "note" = "the wchResearchCost, row 9 of 10 - the spell research cost ladder by spell level 1-10 - weeks equal the level, the standard investment doubling per level from 2,000 and the certain line from 10,000 (folio 24)",
    } },
  "audit" = {
      "label" = "R902 Dragon issue-5 audit",
      "comment" = "THE DRAGON ISSUE-5 OPENER ROUND - three adjudicated chains. The Witchcraft Supplement (folios 4-9, the anonymous ms.): the encounter doctrine (rolls 5 or 7, witches present 50 percent of the time, the 35/65 alignment split), the 12-sided Order ladder (Low 1-8, High 9-11, Secret 12 - one Secret means all Secret), the Secret witch doctrines (75 percent in lair, any terrain, the loner law, no brooms or balls or familiar, the 50 percent sneak, the 13th-level item bar, the cleric-touch instant death, the no-dispel Group B), the spell quotas (good 7, the 4 percent ancient Priestess with ten daily and one weekly at 11th-level saves, Low 4 Minor, High 4 Minor and 2 Major, Secret 6 Group A and 3 Group B), the immunities (witchcraft never affecting Djinn, Efreet or Clerics; the concentration circle; the cleric poison-touch immunity), the trade economy (the willingness die 1-3/4/5-6, Table A 6-15k and Table B 10-50k plus magic items, the 10 gp instructress fee, the 20 percent map cut, the 1-4 alliance die), the witch items (the Skull of Death 5 points per turn and 3 dice undead command, the Luck Charm d20, the Guardian Egg at 250 gp weight and 48-hour reuse with its armor-class-2 Hill Giant 8, Roc 8 and Dragon Turtle 10 dice forms, the Hornet Cape at 36 inches with three 7-inch 3-dice stings, the Seed Satchel 7-12, the Witch Wand 7 spells, the Serpent Belt 10-foot 2-dice, the Love Locket 20 percent and 2 items, the Dart Ring twice per 30 feet, the 40-foot 4-dice Thorn Twine, the 1-3 Hill Seeds), the spell matrix as a 21-row range/duration table with 0 the no-printed-duration sentinel, and the lair treasure as a 4-row cache table by lair type with the Good lair's 1-10 thousand SP and the Secret lair's ring and Secret-item extras riding this note. The Anhkheg (folios 12, 28): the Featured Creature's first magazine appearance, pinned lore-against-def - the merged MM1 ankheg def exists at monsters/monsters/a/ankheg.lua, so this is a provenance pin, never a competing def; the stat block (1-6 appearing, 10-20 feet, armor class 2 over and 4 under, 12/6 move, 3-8 hit dice on the 8-sided die, 25 percent in lair, treasure B2, bite 3-18, the 1-6-dice acid squirt at 30 feet once per six hours, the 1-10 enzyme, the 5-10 foot ambush depth) with every print divergence from the def noted (lair 25 vs 15, enzyme 1-10 vs 1-4, B2 vs C, the acid squirt vs the def 8-32). The Wizard Research Rules (folios 24-26, 28, Goforth): the research ladder as a 10-row table - weeks equal the spell level, the standard investment doubling per level from 2,000 and the certain line from 10,000 at the flat 20 percent success chance - the once-per-stat permanent stat spell, the +1 enchanting at 2 months and 2,000 gp, serious enchanting at 10 months and 10,000 gp, the duplication at 10,000 gp and 10 months times the table number, the ringmaking ladders (serious 10,000 and 10 months; the True Ring at 300,000 xp drained; the Wizard Blade at 200,000 xp with the d8 property roll over the 11-property list and the +6 to -6 named level, the larger 12/16/20-sided dice at 300k/400k/500k), the unlimited ring charges against the 100-charge wands and staffs, the no-reenchanting law, and the Memorial Enchanting In Distress d8 hits. The garbled wilderness encounter grid at folio 4 is scoped out on OCR garble per the standing caution.",
    },
}
