-- ua366: promoted from the round R366 pin headers (the the UA DM-section spells);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 366,
  "prefix" = "ua366",
  "banner" = {
      "title" = "the UA DM-section spells",
      "provenance" = "rules/ua/uadarkness.h (the The UA EFFECTS OF DARKNESS (p. 82 print) pins,): R366: the combat to-hit ladder, the illumination exception, the converse read, the faerie fire conditions and the DM moderation closer.  Pin-era pattern (R322): pinned data only - no engine site exists. The section prints clean - no OCR holes; the printed list markers garble (numbers 1, then bullets) - the four cases pin in the printed order.  rules/ua/uaspellbooks.h (the The UA MAGIC-USER SPELL BOOKS (pp. 79-80 print) pins,): R366: the book types and capacities, the costs, the physical aspects, the values and the direct-casting and learning rules.  Pin-era pattern (R322): pinned data only - no engine site exists. The section general note applies equally to illusionists; the illusionist-side exceptions pin in the R365 acquisition header.  JUDGMENTs (the decode method): - the section opening garbles (the one-or-two starting books read survives in the cost paragraph); the readable facts pin, the rest is a hole pending the PDF. - the standard-book encumbrance cell and the travelling-book thickness/weight/encumbrance cells garble - holes, no numeric pin, pending the PDF; the travelling 500 gp cost prints as a fragment (\"costs such a 500 gold\") and pins flagged. - the direct-casting neighbor-destroy chance prints 1 percent per level of the spell; the whole-book chance prints a flat 1 percent.  rules/ua/uaspellcomment.h (the The UA SPELL EXPLANATIONS - the referee commentary): (pp. 81-82 print) pins, R366: the permanency lists and the Serten's spell immunity commentary.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the permanency object/area list interleaves with the constitution-loss note in the print - the 22 names pin from the two fragments (the note counted separately). - the Serten's bonus bands detach from their spell groups in the print (a stray +9/+7/+5 column) - the three values and the 24 spell names pin, the band assignment is flagged garbled pending the PDF. - a stray \"from normal\" fragment rides the personal permanency list - flagged, no decode.  rules/ua/uauwspelluse.h (the The UA UNDERWATER SPELL USE (pp. 81-83 print) pins,): R366: the cannot-be-used lists by class, the airy-water footnote and the altered-effects reads.  Pin-era pattern (R322): pinned data only - no engine site exists. The DMG underwater spells (R168) are a separate battery item; this is the UA adventure layer.  JUDGMENTs (the decode method): - the magic-user cannot-use list garbles at the cantrip row (dampen reads; the second cantrip cell is lost) - flagged, no name pin. - the list tail interleaves the illusionist column (haze, rainbow, whispering wind, phantom wind, solid fog, death fog) - the fragment pins as the illusionist list, corroborated by the landed UA IL spell levels (R363-R365: rainbow at 1st, whispering wind at 2nd, phantom wind at 3rd, solid fog at 4th, death fog at 6th). - the chain lightning save tail truncates (\"half dama\") - decoded as the standard save-for-half per the DMG lightning bolt. - the starred footnote: spells that can be cast and will function within the bounds of an airy water spell.",
    },
  "consts" = { {
      "name" = "uadkUnseenTargetToHitPenalty",
      "value" = 4,
      "comment" = "---- the combat to-hit ladder ----",
    }, {
      "name" = "uadkVagueBlurToHitPenalty",
      "value" = 2,
      "comment" = "If the opponent is vaguely discernible - a faint blur or a darker shape that stands out against the background - attacks are at -2 to hit.",
    }, {
      "name" = "uabkStandardCantripsCapacity",
      "value" = 36,
      "comment" = "---- the standard book capacities ----",
    }, {
      "name" = "uabkStandardLowLevelSpells",
      "value" = 24,
      "comment" = "",
    }, {
      "name" = "uabkStandardMidLevelSpells",
      "value" = 16,
      "comment" = "",
    }, {
      "name" = "uabkStandardHighLevelSpells",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uabkTravellingCantripsCapacity",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uabkTravellingLowLevelSpells",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uabkTravellingMidLevelSpells",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uabkTravellingHighLevelSpells",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uabkStandardMaterialsCostGp",
      "value" = 1000,
      "comment" = "---- the costs ---- A standard spell book costs 1,000 gp for materials plus 100 gp per spell level for each spell contained therein; cantrips count as 1st-level spells.",
    }, {
      "name" = "uabkPerSpellLevelCostGp",
      "value" = 100,
      "comment" = "",
    }, {
      "name" = "uabkInitialBookCountMax",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uabkCompositionWeeksMin",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uabkCompositionWeeksMax",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uabkEnterFirstLevelCostGp",
      "value" = 100,
      "comment" = "The printed examples: entering a 1st-level spell costs 100 gp, a 2nd-level spell 200 gp.",
    }, {
      "name" = "uabkEnterSecondLevelCostGp",
      "value" = 200,
      "comment" = "",
    }, {
      "name" = "uabkTravellingCostFragmentGp",
      "value" = 500,
      "comment" = "The travelling-book cost fragment (the cell garbles around a readable \"such a 500 gold\").",
    }, {
      "name" = "uabkStandardHeightInches",
      "value" = 16,
      "comment" = "---- the standard book physical aspects ----",
    }, {
      "name" = "uabkStandardWidthInches",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uabkStandardThicknessInches",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uabkMinSizeHeightInches",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uabkMinSizeWidthInches",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uabkMinSizeThicknessInches",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uabkMaxSizeHeightInches",
      "value" = 18,
      "comment" = "",
    }, {
      "name" = "uabkMaxSizeWidthInches",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uabkMaxSizeThicknessInches",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uabkMedianWeightGp",
      "value" = 150,
      "comment" = "The weight of a standard book of median size is 150 gold pieces (adjusted for varying sizes); the encumbrance cell garbles - a hole.",
    }, {
      "name" = "uabkSaveBonusVsAcidFireDisintLightning",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uabkTravellingTallInches",
      "value" = 12,
      "comment" = "---- the travelling book physical aspects ----",
    }, {
      "name" = "uabkTravellingWideInches",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uabkTravellingFitPerLargeSack",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uabkXpValuePerSpellLevel",
      "value" = 500,
      "comment" = "---- the values ---- A standard spell book has an Experience Point Value of 500 points per spell level contained therein (cantrips as 1st-level spells) and a Gold Piece Sale Value of 1,000 gp per spell level (all spells, including cantrips).",
    }, {
      "name" = "uabkSaleValuePerSpellLevelGp",
      "value" = 1000,
      "comment" = "",
    }, {
      "name" = "uabkNeighborDestroyPctPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uabkWholeBookDestroyPct",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uabkStudyHoursPerLevelMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uabkStudyHoursPerLevelMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uapcPermPersonalCount",
      "value" = 6,
      "comment" = "---- the personal permanency list ----",
    }, {
      "name" = "uapcPermObjectCount",
      "value" = 22,
      "comment" = "---- the object/creature or area permanency list ----",
    }, {
      "name" = "uapcConLossPctNonLiving",
      "value" = 5,
      "comment" = "---- the constitution-loss reads ---- Only a 5 percent chance of losing a constitution point when permanency is cast upon a non-living thing; 100 percent when applied as a charge in a device (a ring of spell storing, the printed example).",
    }, {
      "name" = "uapcConLossPctDeviceCharge",
      "value" = 100,
      "comment" = "",
    }, {
      "name" = "uapcSertenSpellCount",
      "value" = 24,
      "comment" = "---- the Serten's spell immunity commentary ---- The spell grants saving throw bonuses against the 24 listed magics, bestows a saving throw against all of them even if none is normally allowed, but not against the fascination effect of comeliness.",
    }, {
      "name" = "uapcSertenBonusHigh",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uapcSertenBonusMid",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uapcSertenBonusLow",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uauwClericCannotUseCount",
      "value" = 5,
      "comment" = "---- the cleric cannot-use list ----",
    }, {
      "name" = "uauwDruidCannotUseCount",
      "value" = 4,
      "comment" = "---- the druid cannot-use list ----",
    }, {
      "name" = "uauwTransmuteHoleCubicFeetPerLevel",
      "value" = 10,
      "comment" = "Transmute water to dust (6th) underwater opens a hole of 10 cubic feet per level of the caster; the surrounding water rushes in, inflicting 1-4 points of damage per level (no saving throw).",
    }, {
      "name" = "uauwTransmuteRushInDamagePerLevelDice",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uauwSaltCantripPints",
      "value" = 1,
      "comment" = "---- the magic-user altered effects ---- The salt cantrip produces about 1 pint of salt water total; unless contained it quickly disperses into the surrounding water.",
    }, {
      "name" = "uauwAcidArrowLastsRounds",
      "value" = 1,
      "comment" = "Melf's acid arrow (2nd): the acid lasts only a single round, then is washed away.",
    }, {
      "name" = "uauwChainLightningDamageDicePerLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uauwPhantomSteedMovementPerLevel",
      "value" = 4,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uadkUnseenIsAsInvisible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadkVagueMeansDarkerShapeOnBackground",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadkDaylightAndDevicesUnaffected",
      "value" = true,
      "comment" = "---- the illumination exception ---- Combat is not affected by illumination (or lack thereof) in daylight or in the light conditions produced by most light-giving devices and spells - including torches, lanterns, light spells and continual light spells.",
    }, {
      "name" = "uadkIncludesTorchLanternLightSpells",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadkIncludesContinualLight",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadkConverseHoldsForDarkDwellers",
      "value" = true,
      "comment" = "---- the converse read ---- The converse holds for creatures which function normally or at some relative advantage in darkness: infravision still sees opponents in the absence of visible-spectrum light, and creatures accustomed to operating in darkness suffer vision penalties when attacking opponents in illuminated conditions.",
    }, {
      "name" = "uadkInfravisionWorksInNoVisibleLight",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadkDarkDwellerPenalizedInLight",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadkGrayDwarfCrossRef",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadkDarkElfDarkGnomeCrossRef",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadkFaerieFireHelpsOnlyPoorLight",
      "value" = true,
      "comment" = "---- the faerie fire conditions ---- Faerie fire benefits only when outlining opponents in poor lighting conditions (a dungeon area lit only by softly glowing magic weapons, or total darkness); in torch- or light-spell illumination (or anything stronger) it functions normally but contributes nothing to the visibility of the target.",
    }, {
      "name" = "uadkFaerieFireWorksInTotalDarkness",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadkFaerieFireNoBenefitAtTorchLight",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadkFaerieFireFunctionsNormallyAnyway",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadkDmCommonSenseFinalDeterminant",
      "value" = true,
      "comment" = "---- the DM moderation closer ---- Common sense must be the final determinant of whether an act is possible or whether a bonus or penalty applies; a warranted exception is within the DM's purview.",
    }, {
      "name" = "uadkDmMayWarrantException",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkTravellingIsOneFourth",
      "value" = true,
      "comment" = "---- the travelling book (one-fourth) ----",
    }, {
      "name" = "uabkCantripsCountAsFirstLevel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkInitialBooksBorneByMaster",
      "value" = true,
      "comment" = "The new caster's former master bears the cost of the initial book or books (one or two, at no cost).",
    }, {
      "name" = "uabkLaterBooksSelfComposed",
      "value" = true,
      "comment" = "Later books are composed during the training to rise to a higher experience level: 4-7 weeks per new standard book.",
    }, {
      "name" = "uabkCompositionRidesLevelTraining",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkTravellingCostIsFragmentRead",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkDmMayResizeTheBook",
      "value" = true,
      "comment" = "The DM has leeway to reduce or enlarge this general size (nothing smaller than 12x12x6 or larger than 18x12x9 is recommended).",
    }, {
      "name" = "uabkWeightAdjustedForSize",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkEncumbranceCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkFitsBackpackOrLargeSack",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkCoverHeavyLeatherInlaidMetal",
      "value" = true,
      "comment" = "The cover is heavy leather (dragon hide or similar) inlaid with metal for durability and closing; vellum pages are sewn and secured to a leather spine backing with vellum stubs for added pages.",
    }, {
      "name" = "uabkVellumPagesSewnToSpine",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkVellumStubsForAddedPages",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkStubsDoNotChangeCapacity",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkSaveAsLeatherOrBook",
      "value" = true,
      "comment" = "A standard spell book has a saving throw equal to that of leather or book, with +2 to dice rolls made to save against acid, fireball, disintegration and lightning attacks.",
    }, {
      "name" = "uabkTravellingThickCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkTravellingWeightCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkTravellingEncumbranceCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkTravellingCoverGiantCobraLeather",
      "value" = true,
      "comment" = "The cover is strong supple leather (giant cobra and similar); hand-sewn parchment leaves glued to the spine; pages very thin and fragile; a small lock or leather ties secure the whole.",
    }, {
      "name" = "uabkTravellingPagesThinFragile",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkTravellingLockOrLeatherTies",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkTravellingSaveNoBonus",
      "value" = true,
      "comment" = "A travelling spell book saves as leather or book with no bonuses against certain forms of attack.",
    }, {
      "name" = "uabkSellImmediatelyOrTakeXp",
      "value" = true,
      "comment" = "Spell books must be sold immediately or else the x.p. value taken - a book cannot be kept while spells are transcribed and then sold.",
    }, {
      "name" = "uabkNoKeepTranscribeThenSell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkInExtremisDmMayAllowDirectCast",
      "value" = true,
      "comment" = "---- casting directly from books ---- In extremis the DM may allow a spell to be cast directly from a spell book just as if the book were a scroll; the book must match the profession of the caster and the caster must be able to know and use the spell (reading directly differs from scroll use in this regard).",
    }, {
      "name" = "uabkBookMustMatchCasterProfession",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkCasterMustKnowAndUseSpell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkDirectCastDiffersFromScrolls",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkDirectCastDestroysTheSpell",
      "value" = true,
      "comment" = "Direct casting automatically destroys that spell; a 1 percent per level chance destroys the immediately preceding and following spells; a flat 1 percent chance destroys the entire book.",
    }, {
      "name" = "uabkPermanencyDoesNotPreventLoss",
      "value" = true,
      "comment" = "A permanency spell would not prevent the loss (the writing might remain on the page but is no longer magical); the strictures apply to any book, personal or another's.",
    }, {
      "name" = "uabkWritingRemainsButNotMagical",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkStricturesApplyToAnyBook",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkReadMagicNeededForOthersBook",
      "value" = true,
      "comment" = "---- learning from another's book ----",
    }, {
      "name" = "uabkLearnSpellFromAnotherBook",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabkLearnedSpellImmediatelyUsable",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermPersonalDetectEvil",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermPersonalDetectIllusion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermPersonalDetectInvisibility",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermPersonalDetectMagic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermPersonalInfravision",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermPersonalProtectionFromEvil",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPersonalListFromNormalFragment",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectAlarm",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectDeeppockets",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectDispelMagic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectEnlarge",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectFear",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectForcecage",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectGustOfWind",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectInvisibility",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectMagicMouth",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectMissiles",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectPreserve",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectPrismaticSphere",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectReadMagic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectRun",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectStinkingCloud",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectTongues",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectUltravision",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectUnseenServant",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectWallOfFire",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectWallOfForce",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectWeb",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcPermObjectWindWall",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcObjectListInterleavedWithNote",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcDeviceExampleRingOfSpellStoring",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcSertenBandAssignmentGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcSertenSaveEvenIfNoneAllowed",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapcSertenNotVsComelinessFascination",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwClericPrecipitationFirst",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwClericDustDevilSecond",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwClericCloudburstThird",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwClericAirWalkFifth",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwClericRainbowFifth",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwClericAirWalkStarred",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwClericRainbowStarred",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwDruidPrecipitationFirst",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwDruidFlameBladeSecond",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwDruidCloudburstThird",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwDruidLiveoakSixth",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwDruidFlameBladeStarred",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwMuDampenCantripListed",
      "value" = true,
      "comment" = "---- the magic-user cannot-use list ----",
    }, {
      "name" = "uauwMuCantripSecondCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwMuMountFirst",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwMuPrecipitationFirst",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwMuFlamingSphereSecond",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwMuCloudburstThird",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwMuMinuteMeteorsThird",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwMuWindWallThird",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwMuShoutFourth",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwMuFlamingSphereStarred",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwMuWindWallStarred",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwMuShoutStarred",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwIlFragmentReadsAsIllusionist",
      "value" = true,
      "comment" = "---- the illusionist fragment ----",
    }, {
      "name" = "uauwIlHazeCantripListed",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwIlRainbowFirst",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwIlWhisperingWindSecond",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwIlPhantomWindThird",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwIlSolidFogFourth",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwIlDeathFogSixth",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwIlFragmentAllStarred",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwStarredCastableInAiryWater",
      "value" = true,
      "comment" = "---- the airy-water footnote ----",
    }, {
      "name" = "uauwWaterWalkBobsToSurface",
      "value" = true,
      "comment" = "---- the cleric altered effects ---- Water walk (3rd): the casting causes the recipient to immediately bob to the surface. Magic font (5th): requires a glass globe of pure water as opposed to a font.",
    }, {
      "name" = "uauwMagicFontNeedsGlassGlobe",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwReflectingPoolAnyWaterySpace",
      "value" = true,
      "comment" = "---- the druid altered effects ----",
    }, {
      "name" = "uauwTransmuteNoSavingThrow",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwSaltWaterDispersesUnlessContained",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwFirewaterFloatsToTop",
      "value" = true,
      "comment" = "Firewater (1st) floats to the top of the body of water and may not be ignited underwater.",
    }, {
      "name" = "uauwFirewaterNotIgnitableUnderwater",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwAcidArrowWashedAway",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwChainLightningDoubleRadius",
      "value" = true,
      "comment" = "Chain lightning (6th) underwater: effects as a lightning bolt of double normal radius but inflicts only 1d6 of damage per level of the caster (saving throw for half).",
    }, {
      "name" = "uauwChainLightningSaveForHalf",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwMuTransmuteAsDruid",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwMansionWaterFilledOrDryOption",
      "value" = true,
      "comment" = "Mordenkainen's magnificent mansion (7th): at the caster's option the mansion can be filled with water, or the membrane can prevent the influx of water, leaving the interior tidy and dry.",
    }, {
      "name" = "uauwSinkRadiatesToSurface",
      "value" = true,
      "comment" = "Sink (8th): places a creature the given number of feet below the floor of the river or sea; the containment magic radiates through the water to the surface.",
    }, {
      "name" = "uauwPhantomSteedBecomesHippocampus",
      "value" = true,
      "comment" = "---- the illusionist altered effect ---- Phantom steed (3rd) summoned underwater: hippocampi with black forebodies and silver-gray scales; no traveling or flying specials, but they gain the 4\"/level movement of the phantom steed.",
    }, {
      "name" = "uauwPhantomSteedBlackForebodySilverScales",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uauwPhantomSteedNoTravelOrFlySpecials",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uapcSertenName",
      "comment" = "",
      "kind" = "string array",
      "count" = 24,
      "values" = { "beguiling", "charm", "suggestion", "forget", "hypnotism", "ray of enfeeblement", "person-affecting cantrips", "command", "domination", "fear", "hold", "scare", "spook", "eyebite", "cloak of fear", "geas", "quest", "chaos", "feeblemind", "Otto's irresistible dance", "dolor", "demand", "torment", "Leomund's lamentable belabourment" },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uabkStandardCantripsCapacity']() != 36  or m['uabkStandardLowLevelSpells']() != 24  or m['uabkStandardMidLevelSpells']() != 16  or m['uabkStandardHighLevelSpells']() != 8  or  m['uabkTravellingIsOneFourth']() != 1  or m['uabkTravellingCantripsCapacity']() != 9  or m['uabkTravellingLowLevelSpells']() != 6  or m['uabkTravellingMidLevelSpells']() != 4  or m['uabkTravellingHighLevelSpells']() != 2  or m['uabkStandardMaterialsCostGp']() != 1000  or m['uabkPerSpellLevelCostGp']() != 100  or  m['uabkCantripsCountAsFirstLevel']() != 1  or  m['uabkInitialBooksBorneByMaster']() != 1  or m['uabkInitialBookCountMax']() != 2  or  m['uabkLaterBooksSelfComposed']() != 1  or m['uabkCompositionWeeksMin']() != 4  or m['uabkCompositionWeeksMax']() != 7  or  m['uabkCompositionRidesLevelTraining']() != 1  or m['uabkEnterFirstLevelCostGp']() != 100  or m['uabkEnterSecondLevelCostGp']() != 200  or m['uabkTravellingCostFragmentGp']() != 500  or  m['uabkTravellingCostIsFragmentRead']() != 1  or m['uabkStandardHeightInches']() != 16  or m['uabkStandardWidthInches']() != 12  or m['uabkStandardThicknessInches']() != 6  or  m['uabkDmMayResizeTheBook']() != 1  or m['uabkMinSizeHeightInches']() != 12  or m['uabkMinSizeWidthInches']() != 12  or m['uabkMinSizeThicknessInches']() != 6  or m['uabkMaxSizeHeightInches']() != 18  or m['uabkMaxSizeWidthInches']() != 12  or m['uabkMaxSizeThicknessInches']() != 9  or m['uabkMedianWeightGp']() != 150  or  m['uabkWeightAdjustedForSize']() != 1  or  m['uabkEncumbranceCellLost']() != 1  or  m['uabkFitsBackpackOrLargeSack']() != 1  or  m['uabkCoverHeavyLeatherInlaidMetal']() != 1  or  m['uabkVellumPagesSewnToSpine']() != 1  or  m['uabkVellumStubsForAddedPages']() != 1  or  m['uabkStubsDoNotChangeCapacity']() != 1  or  m['uabkSaveAsLeatherOrBook']() != 1  or m['uabkSaveBonusVsAcidFireDisintLightning']() != 2  or m['uabkTravellingTallInches']() != 12  or m['uabkTravellingWideInches']() != 6  or  m['uabkTravellingThickCellLost']() != 1  or  m['uabkTravellingWeightCellLost']() != 1  or  m['uabkTravellingEncumbranceCellLost']() != 1  or m['uabkTravellingFitPerLargeSack']() != 5  or  m['uabkTravellingCoverGiantCobraLeather']() != 1  or  m['uabkTravellingPagesThinFragile']() != 1  or  m['uabkTravellingLockOrLeatherTies']() != 1  or  m['uabkTravellingSaveNoBonus']() != 1  or m['uabkXpValuePerSpellLevel']() != 500  or m['uabkSaleValuePerSpellLevelGp']() != 1000  or  m['uabkSellImmediatelyOrTakeXp']() != 1  or  m['uabkNoKeepTranscribeThenSell']() != 1  or  m['uabkInExtremisDmMayAllowDirectCast']() != 1  or  m['uabkBookMustMatchCasterProfession']() != 1  or  m['uabkCasterMustKnowAndUseSpell']() != 1  or  m['uabkDirectCastDiffersFromScrolls']() != 1  or  m['uabkDirectCastDestroysTheSpell']() != 1  or m['uabkNeighborDestroyPctPerLevel']() != 1  or m['uabkWholeBookDestroyPct']() != 1  or  m['uabkPermanencyDoesNotPreventLoss']() != 1  or  m['uabkWritingRemainsButNotMagical']() != 1  or  m['uabkStricturesApplyToAnyBook']() != 1  or  m['uabkReadMagicNeededForOthersBook']() != 1  or  m['uabkLearnSpellFromAnotherBook']() != 1  or m['uabkStudyHoursPerLevelMin']() != 2  or m['uabkStudyHoursPerLevelMax']() != 8  or  m['uabkLearnedSpellImmediatelyUsable']() != 1",
      "note" = "---- uabk pins ----",
    }, {
      "expr" = "m['uapcPermPersonalCount']() != 6  or  m['uapcPermPersonalDetectEvil']() != 1  or  m['uapcPermPersonalDetectIllusion']() != 1  or  m['uapcPermPersonalDetectInvisibility']() != 1  or  m['uapcPermPersonalDetectMagic']() != 1  or  m['uapcPermPersonalInfravision']() != 1  or  m['uapcPermPersonalProtectionFromEvil']() != 1  or  m['uapcPersonalListFromNormalFragment']() != 1  or m['uapcPermObjectCount']() != 22  or  m['uapcPermObjectAlarm']() != 1  or  m['uapcPermObjectDeeppockets']() != 1  or  m['uapcPermObjectDispelMagic']() != 1  or  m['uapcPermObjectEnlarge']() != 1  or  m['uapcPermObjectFear']() != 1  or  m['uapcPermObjectForcecage']() != 1  or  m['uapcPermObjectGustOfWind']() != 1  or  m['uapcPermObjectInvisibility']() != 1  or  m['uapcPermObjectMagicMouth']() != 1  or  m['uapcPermObjectMissiles']() != 1  or  m['uapcPermObjectPreserve']() != 1  or  m['uapcPermObjectPrismaticSphere']() != 1  or  m['uapcPermObjectReadMagic']() != 1  or  m['uapcPermObjectRun']() != 1  or  m['uapcPermObjectStinkingCloud']() != 1  or  m['uapcPermObjectTongues']() != 1  or  m['uapcPermObjectUltravision']() != 1  or  m['uapcPermObjectUnseenServant']() != 1  or  m['uapcPermObjectWallOfFire']() != 1  or  m['uapcPermObjectWallOfForce']() != 1  or  m['uapcPermObjectWeb']() != 1  or  m['uapcPermObjectWindWall']() != 1  or  m['uapcObjectListInterleavedWithNote']() != 1  or m['uapcConLossPctNonLiving']() != 5  or m['uapcConLossPctDeviceCharge']() != 100  or  m['uapcDeviceExampleRingOfSpellStoring']() != 1  or m['uapcSertenSpellCount']() != 24  or m['uapcSertenBonusHigh']() != 9  or m['uapcSertenBonusMid']() != 7  or m['uapcSertenBonusLow']() != 5  or  m['uapcSertenBandAssignmentGarbled']() != 1  or  m['uapcSertenSaveEvenIfNoneAllowed']() != 1  or  m['uapcSertenNotVsComelinessFascination']() != 1",
      "note" = "---- uapc pins ----",
    }, {
      "expr" = "m['uauwClericCannotUseCount']() != 5  or  m['uauwClericPrecipitationFirst']() != 1  or  m['uauwClericDustDevilSecond']() != 1  or  m['uauwClericCloudburstThird']() != 1  or  m['uauwClericAirWalkFifth']() != 1  or  m['uauwClericRainbowFifth']() != 1  or  m['uauwClericAirWalkStarred']() != 1  or  m['uauwClericRainbowStarred']() != 1  or m['uauwDruidCannotUseCount']() != 4  or  m['uauwDruidPrecipitationFirst']() != 1  or  m['uauwDruidFlameBladeSecond']() != 1  or  m['uauwDruidCloudburstThird']() != 1  or  m['uauwDruidLiveoakSixth']() != 1  or  m['uauwDruidFlameBladeStarred']() != 1  or  m['uauwMuDampenCantripListed']() != 1  or  m['uauwMuCantripSecondCellLost']() != 1  or  m['uauwMuMountFirst']() != 1  or  m['uauwMuPrecipitationFirst']() != 1  or  m['uauwMuFlamingSphereSecond']() != 1  or  m['uauwMuCloudburstThird']() != 1  or  m['uauwMuMinuteMeteorsThird']() != 1  or  m['uauwMuWindWallThird']() != 1  or  m['uauwMuShoutFourth']() != 1  or  m['uauwMuFlamingSphereStarred']() != 1  or  m['uauwMuWindWallStarred']() != 1  or  m['uauwMuShoutStarred']() != 1  or  m['uauwIlFragmentReadsAsIllusionist']() != 1  or  m['uauwIlHazeCantripListed']() != 1  or  m['uauwIlRainbowFirst']() != 1  or  m['uauwIlWhisperingWindSecond']() != 1  or  m['uauwIlPhantomWindThird']() != 1  or  m['uauwIlSolidFogFourth']() != 1  or  m['uauwIlDeathFogSixth']() != 1  or  m['uauwIlFragmentAllStarred']() != 1  or  m['uauwStarredCastableInAiryWater']() != 1  or  m['uauwWaterWalkBobsToSurface']() != 1  or  m['uauwMagicFontNeedsGlassGlobe']() != 1  or  m['uauwReflectingPoolAnyWaterySpace']() != 1  or m['uauwTransmuteHoleCubicFeetPerLevel']() != 10  or m['uauwTransmuteRushInDamagePerLevelDice']() != 4  or  m['uauwTransmuteNoSavingThrow']() != 1  or m['uauwSaltCantripPints']() != 1  or  m['uauwSaltWaterDispersesUnlessContained']() != 1  or  m['uauwFirewaterFloatsToTop']() != 1  or  m['uauwFirewaterNotIgnitableUnderwater']() != 1  or m['uauwAcidArrowLastsRounds']() != 1  or  m['uauwAcidArrowWashedAway']() != 1  or  m['uauwChainLightningDoubleRadius']() != 1  or m['uauwChainLightningDamageDicePerLevel']() != 6  or  m['uauwChainLightningSaveForHalf']() != 1  or  m['uauwMuTransmuteAsDruid']() != 1  or  m['uauwMansionWaterFilledOrDryOption']() != 1  or  m['uauwSinkRadiatesToSurface']() != 1  or  m['uauwPhantomSteedBecomesHippocampus']() != 1  or  m['uauwPhantomSteedBlackForebodySilverScales']() != 1  or  m['uauwPhantomSteedNoTravelOrFlySpecials']() != 1  or m['uauwPhantomSteedMovementPerLevel']() != 4",
      "note" = "---- uauw pins ----",
    }, {
      "expr" = "m['uadkUnseenTargetToHitPenalty']() != 4  or  m['uadkUnseenIsAsInvisible']() != 1  or m['uadkVagueBlurToHitPenalty']() != 2  or  m['uadkVagueMeansDarkerShapeOnBackground']() != 1  or  m['uadkDaylightAndDevicesUnaffected']() != 1  or  m['uadkIncludesTorchLanternLightSpells']() != 1  or  m['uadkIncludesContinualLight']() != 1  or  m['uadkConverseHoldsForDarkDwellers']() != 1  or  m['uadkInfravisionWorksInNoVisibleLight']() != 1  or  m['uadkDarkDwellerPenalizedInLight']() != 1  or  m['uadkGrayDwarfCrossRef']() != 1  or  m['uadkDarkElfDarkGnomeCrossRef']() != 1  or  m['uadkFaerieFireHelpsOnlyPoorLight']() != 1  or  m['uadkFaerieFireWorksInTotalDarkness']() != 1  or  m['uadkFaerieFireNoBenefitAtTorchLight']() != 1  or  m['uadkFaerieFireFunctionsNormallyAnyway']() != 1  or  m['uadkDmCommonSenseFinalDeterminant']() != 1  or  m['uadkDmMayWarrantException']() != 1",
      "note" = "---- uadk pins ----",
    }, {
      "expr" = "strcmp(m['uapcSertenName'](i), sn[i]) != 0  or m['uapcSertenName'](-1)[0] != 0  or m['uapcSertenName'](24)[0] != 0",
      "note" = "the Serten's name table ----",
    } },
  "audit" = {
      "label" = "R366: the UA DM-section spells pin audit",
      "comment" = "The UA DM-section spell block (pp. 79-83): the MAGIC-USER SPELL BOOKS (the capacities 36/24/16/8 with the one-fourth travelling 9/6/4/2, the costs, the physical aspects, the values, the direct-casting and learning reads), the SPELL EXPLANATIONS commentary (the permanency lists, the 5/100 percent constitution-loss reads, the Serten's immunity commentary with the bonus band assignment flagged), the UNDERWATER SPELL USE lists (the cannot-use rosters with the airy-water footnote, the altered effects - the MU cantrip row and the MU/IL list boundary garble, flagged) and the EFFECTS OF DARKNESS ladder. Four items flip CLOSED; the census 292 -> 293.",
    },
}
