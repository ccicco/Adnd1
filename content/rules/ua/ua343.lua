-- ua343: promoted from rules/uaclericspells1.h (the The UA NEW CLERIC SPELLS (pp. 32-35) pins, R343: the 1st-level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 343,
  "prefix" = "ua343",
  "banner" = {
      "title" = "The UA NEW CLERIC SPELLS (pp. 32-35) pins, R343: the 1st-level",
      "provenance" = "spell descriptions - ceremony, combine, endure cold/heat, penetrate disguise, invisibility to undead, portent, magic stone, precipitation.  Pin-era pattern (R322): pinned data only - no engine site exists. The R341 cleric table pin (rules/uaspelltables.h) is the name seam.  JUDGMENTs (the decode method): - the digit-garble family: four \"Level: 7\" cells print where the level is position-certain 1 (the section header and the R341 table both read 1st level; ceremony, combine and magic stone print clean \"Level: 1\" cells). The same 7 prints in the casting-time and duration cells - the family decodes 7 as 1: ceremony casting time 1 hour, magic stone casting time 1 round, penetrate disguise duration 1 round. - \"lllusion/Phantasm\" = Illusion/Phantasm (the leading I lost). - the component cells \"V, S\" print as \"V, \u00a7\" (endure) and \"V, $\" (penetrate) - the same S-garble family; decoded. - the ceremony variety list prints \"Sth-level\" twice: the first (ordination, special vows, consecrate ground) is 5th by list position (1st, 3rd, then this cell), the second (anathematize) is 7th - the list order 1/3/5/7 position-forces both. The cells print head-lost: \"rdination\" = ordination, \"onsecrate ground\" = consecrate ground. - the burial sentence scrambles two columns: \"magically protects a corpse, and is best[?] shielded for one the week blessing asif by of a\" + \"from evil spell\" decodes as: the corpse is magically protected for one week as if by a protection from evil spell. - the consecrate-ground evil-cleric fragment: \"an[?] ... cleric, any undead occupying the area are treated as if they were being protected and controlled by an evil cleric of 3rd level\" - attributed to consecrate ground (the only ground-consecration passage). - combine's interleaved fragments: \"The central functions as if of higher cleric each gain encircling cleric. one level for\" = the central cleric functions as if of higher level for each encircling cleric, gaining one level; \"The maximum ... level, is four\" = the maximum gain is four levels (corroborated: the circle runs three to five clerics, so at most four encircle the central cleric); \"and the maximum duration is 3 turns\" prints clean. - combine's region-attributed sentences: \"They gain no armor class from shield or dexterity, and their attackers gain a +4 bonus on all 'to hit' rolls\" (the encircling clerics, vulnerable while joined) and \"The central cleric gains no additional spells, but may cast any spell(s), often with bonus effects\" - both print inside the combine interleave; the investiture and ordination sentences interleaved there are attributed back to ceremony (their subject matter). - the magic stone damage cell reads \"the stone will do 1 point of damage\" - pinned verbatim with doubt (possible numeral loss, pending the PDF). The range cell prints empty with an orphan \"2\" fragment on the next line - pinned verbatim with doubt (the PHB reads touch). - the R341 table hole at row 13 (between Penetrate Disguise and Precipitation) decodes as Portent - the alphabetical position is forced and this round's descriptions confirm portent as a 1st-level UA cleric spell. Noted here, not re-pinned in R341's header. - the ceremony costs: the clean pairs pin (coming of age 5-15 sp; special vows 1-100 gp or sometimes free; consecrate ground 100-600 gp; anathematize no charge); the interleaved fragments (5-50 gp, 1-100 gp, 1-20, 1-10, 200 gp) read as the remaining cost cells scrambled - noted, not pinned. - endure cold/heat prints \"Duration: 9 turns/level\" - pinned verbatim with doubt (the digit-garble family suggests 1; the 9 is not position-forced, pending the PDF). - penetrate disguise prints \"Range: 712\u00b0\" - unresolvable (the 7 decodes as 1 by the family; the tail reads as lost cells) - a hole.  OCR holes (the item stays open - the 2nd-7th levels pin in later rounds; these stay pending the PDF): the penetrate disguise range cell; the portent material component (the fragments \"The leaves. it a wheel ... y item\" scramble); the precipitation components, casting time and range (only the level fragment \"vel\", the duration and the area fragments survive); the combine components (the cell truncates at \"V,\"); the ceremony cost cells beyond the four clean pairs; the magic stone lost sentence (\"A hit from the stone ... if the victim fails ... a saving throw ... fect\") and the truncated \"it turns back it\" tail; the semi-porous surface scramble beyond the 2-segment and 5-segment fragments; the anathematize \"(e.\" fragment.",
    },
  "consts" = { {
      "name" = "uac1CeremonyName",
      "value" = "Ceremony (Invocation)",
      "comment" = "---- ceremony (Invocation), p. 32-33 ----",
    }, {
      "name" = "uac1CeremonyComponents",
      "value" = "V, S, M",
      "comment" = "",
    }, {
      "name" = "uac1CeremonyCastingTimeHours",
      "value" = 1,
      "comment" = "The casting time prints \"7 hour\" - the digit-garble family decodes 1 hour.",
    }, {
      "name" = "uac1CeremonyVarietyCount",
      "value" = 10,
      "comment" = "The ten ceremony varieties, by the cleric level that can cast them (the Sth cells decode by list position).",
    }, {
      "name" = "uac1ComingOfAgeSaveBonus",
      "value" = 1,
      "comment" = "Coming of age: a limited bless; the +1 bonus applies to any single saving throw, taken at any time after the ceremony.",
    }, {
      "name" = "uac1ComingOfAgeUsualAge",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uac1BurialProtectionWeeks",
      "value" = 1,
      "comment" = "Burial: the corpse is shielded for one week as if by a protection from evil spell; a disinterer within that time must save versus spell or stop and flee in fear for one turn.",
    }, {
      "name" = "uac1BurialDisintererFleeTurns",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac1UnconsecratedCollapsePctPerYear",
      "value" = 1,
      "comment" = "An edifice on unconsecrated ground has a 1% chance per year, cumulative, of collapsing.",
    }, {
      "name" = "uac1ConsecrateGroundEvilClericLevel",
      "value" = 3,
      "comment" = "Consecrated (unholy) ground held by an evil cleric: the undead occupying it are treated as if protected and controlled by an evil cleric of 3rd level.",
    }, {
      "name" = "uac1SpecialVowsQuestSaveMod",
      "value" = -4,
      "comment" = "",
    }, {
      "name" = "uac1CostComingOfAgeMinSp",
      "value" = 5,
      "comment" = "The clean cost pairs (the interleaved cells are holes).",
    }, {
      "name" = "uac1CostComingOfAgeMaxSp",
      "value" = 15,
      "comment" = "",
    }, {
      "name" = "uac1CostSpecialVowsMinGp",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac1CostSpecialVowsMaxGp",
      "value" = 100,
      "comment" = "",
    }, {
      "name" = "uac1CostConsecrateGroundMinGp",
      "value" = 100,
      "comment" = "",
    }, {
      "name" = "uac1CostConsecrateGroundMaxGp",
      "value" = 600,
      "comment" = "",
    }, {
      "name" = "uac1CombineName",
      "value" = "Combine (Evocation)",
      "comment" = "---- combine (Evocation), p. 33-34 ----",
    }, {
      "name" = "uac1CombineClericsMin",
      "value" = 3,
      "comment" = "Three to five clerics join hands in a circle; all cast the spell together; the highest-level other cleric stands central.",
    }, {
      "name" = "uac1CombineClericsMax",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uac1CombineLevelGainPerEncircling",
      "value" = 1,
      "comment" = "The central cleric functions as if of higher level, gaining one level per encircling cleric, to a maximum of four levels.",
    }, {
      "name" = "uac1CombineMaxGainLevels",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac1CombineMaxDurationTurns",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac1CombineAttackerToHitBonus",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac1EndureName",
      "value" = "Endure Cold / Endure Heat",
      "comment" = "---- endure cold / endure heat (Alteration), reversible, p. 34 ----",
    }, {
      "name" = "uac1EndureColdLowFLimit",
      "value" = -30,
      "comment" = "",
    }, {
      "name" = "uac1EndureHeatHighFLimit",
      "value" = 130,
      "comment" = "",
    }, {
      "name" = "uac1EndureExposureDamagePerHourPerDegree",
      "value" = 1,
      "comment" = "Beyond the limits: 1 hit point of exposure damage per hour per degree; unprotected exposure runs 1 hit point per turn per degree.",
    }, {
      "name" = "uac1UnprotectedExposureDamagePerTurnPerDegree",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac1EndureDurationTurnsPerLevel",
      "value" = 9,
      "comment" = "The duration prints \"9 turns/level\" - verbatim with doubt (the digit-garble family suggests 1).",
    }, {
      "name" = "uac1PenetrateName",
      "value" = "Penetrate Disguise (Divination)",
      "comment" = "---- penetrate disguise (Divination), p. 34 ----",
    }, {
      "name" = "uac1PenetrateCastingTimeRounds",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac1PenetrateDurationRounds",
      "value" = 1,
      "comment" = "The duration prints \"7 round\" - the digit-garble family decodes 1 round.",
    }, {
      "name" = "uac1ItuName",
      "value" = "Invisibility to Undead",
      "comment" = "---- invisibility to undead (Illusion/Phantasm), p. 34-35 ----",
    }, {
      "name" = "uac1ItuMaxHitDice",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac1ItuRadiusFeet",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uac1ItuDurationRounds",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac1ItuCastingTimeSegments",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac1ItuNeutralCasterSaveMod",
      "value" = -2,
      "comment" = "A neutral caster (re good/evil) gives the undead -2 on the save.",
    }, {
      "name" = "uac1PortentName",
      "value" = "Portent (Divination)",
      "comment" = "---- portent (Divination), p. 35 ----",
    }, {
      "name" = "uac1PortentTimingDieSides",
      "value" = 12,
      "comment" = "The DM rolls 1d12 in secret for which future roll is affected, then 1d6 for the effect.",
    }, {
      "name" = "uac1PortentEffectDieSides",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac1PortentCastingTimeTurns",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac1MagicStoneName",
      "value" = "Magic Stone (Alteration)",
      "comment" = "---- magic stone (Alteration), p. 35 ----",
    }, {
      "name" = "uac1MagicStoneToHitBonus",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac1MagicStoneDamagePoints",
      "value" = 1,
      "comment" = "The damage cell reads \"1 point of damage\" - verbatim with doubt.",
    }, {
      "name" = "uac1MagicStoneThrowRangeInches",
      "value" = 4,
      "comment" = "The stone can be thrown at a target up to 4\" distant; beyond that, or on a miss, it loses its dweomer and falls harmlessly.",
    }, {
      "name" = "uac1MagicStoneRangeInches",
      "value" = 2,
      "comment" = "The range cell prints empty with an orphan \"2\" fragment - verbatim with doubt (the PHB reads touch).",
    }, {
      "name" = "uac1MagicStoneDweomerWindowRounds",
      "value" = 6,
      "comment" = "The stone must be thrown within 6 rounds of casting or it turns back [to a normal pebble - the tail truncates].",
    }, {
      "name" = "uac1MagicStoneDurationRounds",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac1PrecipName",
      "value" = "Precipitation (Alteration)",
      "comment" = "---- precipitation (Alteration), p. 35 ----",
    }, {
      "name" = "uac1PrecipDurationSegmentsPerLevel",
      "value" = 1,
      "comment" = "The stat block scrambles; the readable fragments: duration 1 segment/level; area of effect a 3\" diameter cylinder up to 12\" high; saving throw none. The components, casting time and range are holes.",
    }, {
      "name" = "uac1PrecipCylinderDiameterInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac1PrecipCylinderHeightInches",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uac1PrecipThinMaterialDampSegments",
      "value" = 1,
      "comment" = "Thin light material damp in 1 segment, thoroughly wet thereafter; twigs and heavy material (canvas) damp in 2 segments, wet thereafter; flat relatively non-porous surfaces (stone floors, rock, painted wood) damp in 1 segment, filmed with water thereafter.",
    }, {
      "name" = "uac1PrecipHeavyMaterialDampSegments",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac1PrecipFlatSurfaceDampSegments",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac1PrecipSemiPorousWetAfterSegments",
      "value" = 5,
      "comment" = "Semi-porous surfaces progress in 2 segments and are thoroughly wet after 5 (the interleaved tail).",
    }, {
      "name" = "uac1PrecipCandleOutSegments",
      "value" = 1,
      "comment" = "Small flames (candles) are extinguished by 1 segment; small fires slow and become smoky for 1 round after the rain ceases; large fires are not materially affected.",
    }, {
      "name" = "uac1PrecipSmallFireSmokyRounds",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac1PrecipHotTempDoublesAboveF",
      "value" = 90,
      "comment" = "Above 90 F the duration doubles (except in arid regions); between 33 and 31 F the rain falls as sleet; at 30 F and below it falls as thick snow and the dampness/wetness effects are negated or postponed until the snow melts.",
    }, {
      "name" = "uac1PrecipSleetHighF",
      "value" = 33,
      "comment" = "",
    }, {
      "name" = "uac1PrecipSleetLowF",
      "value" = 31,
      "comment" = "",
    }, {
      "name" = "uac1PrecipSnowAtOrBelowF",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uac1PrecipMagicalHeatFogAreaMultiplier",
      "value" = 2,
      "comment" = "Magical heat of large area (fire, fireball, flame strike) applied to the rain forms a cloud of warm fog of double the area; magical cold applied forms normal ice.",
    } },
  "bools" = { {
      "name" = "uac1CeremonyNoSaveExceptAnathematize",
      "value" = true,
      "comment" = "No saving throw for any ceremony except anathematize (it simply fails on an unwilling recipient).",
    }, {
      "name" = "uac1SpecialVowsBestowCurseImmunity",
      "value" = true,
      "comment" = "Special vows (cavalier or paladin): immunity to bestow curse spells (not cursed items) while in effect; and -4 on saving throws against a quest spell cast by a cleric of the vows caster's alignment.",
    }, {
      "name" = "uac1CostSpecialVowsSometimesFree",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1CostAnathematizeNoCharge",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1CombineEncirclingNoShieldOrDexAc",
      "value" = true,
      "comment" = "The encircling clerics gain no armor class from shield or dexterity, and attackers gain +4 on \"to hit\" rolls against them.",
    }, {
      "name" = "uac1CentralClericNoExtraSpells",
      "value" = true,
      "comment" = "The central cleric gains no additional spells but may cast any spell(s), often with bonus effects.",
    }, {
      "name" = "uac1CombineComponentsLost",
      "value" = true,
      "comment" = "The combine components cell truncates at \"V,\" - a hole.",
    }, {
      "name" = "uac1EndureReversible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1EndureCancelledByMagicalColdOrHeat",
      "value" = true,
      "comment" = "The spell breaks on any magical cold (including white dragon breath) or magical heat (including magical fire); no damage in the breaking round; resist fire or resist cold cancels it instantly.",
    }, {
      "name" = "uac1EndureNoDamageInBreakingRound",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1EndureResistFireOrColdCancels",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1PenetrateSeesNonMagicalDisguise",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1PenetrateCannotIdClassOrStatus",
      "value" = true,
      "comment" = "The spell cannot identify the figure's class or profession, nor detect actual rank or status; it cannot reveal an illusion; it can detect whether a figure is the object of a friends spell; it cannot detect deception involving alignment.",
    }, {
      "name" = "uac1PenetrateCannotRevealIllusion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1PenetrateDetectsFriendsSpellObject",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1PenetrateCannotDetectAlignmentDeception",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1PenetrateTargetSaveEnhancesDisguise",
      "value" = true,
      "comment" = "On a successful target save the disguise is enhanced: the caster becomes convinced the target is what he claims to be. Bless, magic armor or a magic item of protection grants the target a saving throw bonus.",
    }, {
      "name" = "uac1PenetrateProtectionGrantsSaveBonus",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1PenetrateRangeLost",
      "value" = true,
      "comment" = "The range cell prints \"712\" - a hole.",
    }, {
      "name" = "uac1ItuSavePerType",
      "value" = true,
      "comment" = "A save is made per undead type within 30 feet: on a failure all undead of that type ignore the caster for the duration (this negates the caster's subsequent turning attempts); on a success they attack the caster in preference to other targets. The spell ends if the caster attacks or casts any other spell.",
    }, {
      "name" = "uac1ItuNegatesOwnTurning",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1ItuEndsIfCasterActs",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1ItuMaterialHolySymbol",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1PortentOnlyLifeOrDeathRolls",
      "value" = true,
      "comment" = "Only life-or-death rolls (combat or peril) count toward the timing; contrived saving throws against non-harmful effects suspend the count.",
    }, {
      "name" = "uac1PortentContrivedRollsSuspended",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1PortentTableHoleDecoded",
      "value" = true,
      "comment" = "The R341 table's hole at row 13 decodes as this spell (see the JUDGMENTs).",
    }, {
      "name" = "uac1PortentMaterialLost",
      "value" = true,
      "comment" = "The material component fragments scramble - a hole.",
    }, {
      "name" = "uac1MagicStoneInnateResistImmune",
      "value" = true,
      "comment" = "Any target with innate magic resistance cannot be affected; a shield spell, a brooch of shielding, protection from normal missiles, a minor globe of invulnerability or similar stronger magic protects the target.",
    }, {
      "name" = "uac1MagicStoneShieldBlocks",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1MagicStoneGiveToAnother",
      "value" = true,
      "comment" = "The enchanted stone(s) can be given to another character to throw; some religions forbid the spell (a missile weapon of sorts).",
    }, {
      "name" = "uac1MagicStoneSomeReligionsForbid",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1MagicStoneComponentsLost",
      "value" = true,
      "comment" = "The components cell truncates at \"V,\" - a hole.",
    }, {
      "name" = "uac1PrecipComponentsLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1PrecipPorousAbsorbs",
      "value" = true,
      "comment" = "Porous surfaces absorb up to their capacity - likely beyond the spell's duration.",
    }, {
      "name" = "uac1PrecipLargeFiresUnaffected",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1PrecipMagicalColdFormsIce",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac1PrecipMaterialSilverDust",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uac1CeremonyVarietyName",
      "comment" = "",
      "kind" = "string array",
      "count" = 10,
      "values" = { "Coming of Age", "Burial", "Marriage", "Dedication", "Investiture", "Consecrate Item", "Ordination", "Special Vows", "Consecrate Ground", "Anathematize" },
    }, {
      "name" = "uac1CeremonyVarietyLevel",
      "comment" = "",
      "kind" = "header pin",
      "body" = "// 1st: the first three; 3rd: the next three; 5th: the next // three; 7th: anathematize. static const int k[10] = { 1, 1, 1, 3, 3, 3, 5, 5, 5, 7, }; if (i < 0) i = 0; if (i > 9) i = 9; return k[i];",
    }, {
      "name" = "uac1PortentEffectModifier",
      "comment" = "",
      "kind" = "header pin",
      "body" = "// 1 = -3; 2 = -2; 3 = -1; 4 = +1; 5 = +2; 6 = +3. static const int k[6] = { -3, -2, -1, 1, 2, 3 }; if (roll < 1) roll = 1; if (roll > 6) roll = 6; return k[roll - 1];",
    }, {
      "name" = "uac1MagicStoneStonesForLevel",
      "comment" = "Stones per caster level: 1 through 5th level one stone; 6th through 10th two; 11th through 15th three; then one more per five levels beyond 11th (4 at 16th, 5 at 21st).",
      "kind" = "header pin",
      "body" = "if (level < 1) level = 1; if (level <= 5) return 1; if (level <= 10) return 2; return 3 + (level - 11) / 5;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uac1CeremonyName'](), \"Ceremony (Invocation)\") != 0  or strcmp(m['uac1CeremonyComponents'](), \"V, S, M\") != 0  or m['uac1CeremonyCastingTimeHours']() != 1  or m['uac1CeremonyVarietyCount']() != 10  or strcmp(m['uac1CeremonyVarietyName'](0), \"Coming of Age\") != 0  or strcmp(m['uac1CeremonyVarietyName'](5), \"Consecrate Item\") != 0  or strcmp(m['uac1CeremonyVarietyName'](9), \"Anathematize\") != 0  or m['uac1CeremonyVarietyLevel'](2) != 1  or m['uac1CeremonyVarietyLevel'](3) != 3  or m['uac1CeremonyVarietyLevel'](6) != 5  or m['uac1CeremonyVarietyLevel'](9) != 7  or  m['uac1CeremonyNoSaveExceptAnathematize']() != 1  or m['uac1ComingOfAgeSaveBonus']() != 1  or m['uac1ComingOfAgeUsualAge']() != 12  or m['uac1BurialProtectionWeeks']() != 1  or m['uac1BurialDisintererFleeTurns']() != 1  or m['uac1UnconsecratedCollapsePctPerYear']() != 1  or m['uac1ConsecrateGroundEvilClericLevel']() != 3  or  m['uac1SpecialVowsBestowCurseImmunity']() != 1  or m['uac1SpecialVowsQuestSaveMod']() != -4  or m['uac1CostComingOfAgeMinSp']() != 5  or m['uac1CostComingOfAgeMaxSp']() != 15  or m['uac1CostSpecialVowsMinGp']() != 1  or m['uac1CostSpecialVowsMaxGp']() != 100  or  m['uac1CostSpecialVowsSometimesFree']() != 1  or m['uac1CostConsecrateGroundMinGp']() != 100  or m['uac1CostConsecrateGroundMaxGp']() != 600  or  m['uac1CostAnathematizeNoCharge']() != 1",
      "note" = "U1: ceremony",
    }, {
      "expr" = "strcmp(m['uac1CombineName'](), \"Combine (Evocation)\") != 0  or m['uac1CombineClericsMin']() != 3  or m['uac1CombineClericsMax']() != 5  or m['uac1CombineLevelGainPerEncircling']() != 1  or m['uac1CombineMaxGainLevels']() != 4  or m['uac1CombineMaxDurationTurns']() != 3  or  m['uac1CombineEncirclingNoShieldOrDexAc']() != 1  or m['uac1CombineAttackerToHitBonus']() != 4  or  m['uac1CentralClericNoExtraSpells']() != 1  or  m['uac1CombineComponentsLost']() != 1",
      "note" = "U2: combine",
    }, {
      "expr" = "strcmp(m['uac1EndureName'](), \"Endure Cold / Endure Heat\") != 0  or  m['uac1EndureReversible']() != 1  or m['uac1EndureColdLowFLimit']() != -30  or m['uac1EndureHeatHighFLimit']() != 130  or m['uac1EndureExposureDamagePerHourPerDegree']() != 1  or m['uac1UnprotectedExposureDamagePerTurnPerDegree']() != 1  or m['uac1EndureDurationTurnsPerLevel']() != 9  or  m['uac1EndureCancelledByMagicalColdOrHeat']() != 1  or  m['uac1EndureNoDamageInBreakingRound']() != 1  or  m['uac1EndureResistFireOrColdCancels']() != 1",
      "note" = "U3: endure cold / endure heat",
    }, {
      "expr" = "strcmp(m['uac1PenetrateName'](), \"Penetrate Disguise (Divination)\") != 0  or m['uac1PenetrateCastingTimeRounds']() != 2  or m['uac1PenetrateDurationRounds']() != 1  or  m['uac1PenetrateSeesNonMagicalDisguise']() != 1  or  m['uac1PenetrateCannotIdClassOrStatus']() != 1  or  m['uac1PenetrateCannotRevealIllusion']() != 1  or  m['uac1PenetrateDetectsFriendsSpellObject']() != 1  or  m['uac1PenetrateCannotDetectAlignmentDeception']() != 1  or  m['uac1PenetrateTargetSaveEnhancesDisguise']() != 1  or  m['uac1PenetrateProtectionGrantsSaveBonus']() != 1  or  m['uac1PenetrateRangeLost']() != 1",
      "note" = "U4: penetrate disguise",
    }, {
      "expr" = "strcmp(m['uac1ItuName'](), \"Invisibility to Undead\") != 0  or m['uac1ItuMaxHitDice']() != 4  or m['uac1ItuRadiusFeet']() != 30  or m['uac1ItuDurationRounds']() != 6  or m['uac1ItuCastingTimeSegments']() != 4  or  m['uac1ItuSavePerType']() != 1  or  m['uac1ItuNegatesOwnTurning']() != 1  or  m['uac1ItuEndsIfCasterActs']() != 1  or m['uac1ItuNeutralCasterSaveMod']() != -2  or  m['uac1ItuMaterialHolySymbol']() != 1",
      "note" = "U5: invisibility to undead",
    }, {
      "expr" = "strcmp(m['uac1PortentName'](), \"Portent (Divination)\") != 0  or m['uac1PortentTimingDieSides']() != 12  or m['uac1PortentEffectDieSides']() != 6  or m['uac1PortentEffectModifier'](1) != -3  or m['uac1PortentEffectModifier'](3) != -1  or m['uac1PortentEffectModifier'](4) != 1  or m['uac1PortentEffectModifier'](6) != 3  or  m['uac1PortentOnlyLifeOrDeathRolls']() != 1  or  m['uac1PortentContrivedRollsSuspended']() != 1  or m['uac1PortentCastingTimeTurns']() != 1  or  m['uac1PortentTableHoleDecoded']() != 1  or  m['uac1PortentMaterialLost']() != 1",
      "note" = "U6: portent",
    }, {
      "expr" = "strcmp(m['uac1MagicStoneName'](), \"Magic Stone (Alteration)\") != 0  or m['uac1MagicStoneToHitBonus']() != 1  or m['uac1MagicStoneDamagePoints']() != 1  or m['uac1MagicStoneThrowRangeInches']() != 4  or m['uac1MagicStoneRangeInches']() != 2  or m['uac1MagicStoneDweomerWindowRounds']() != 6  or m['uac1MagicStoneStonesForLevel'](5) != 1  or m['uac1MagicStoneStonesForLevel'](6) != 2  or m['uac1MagicStoneStonesForLevel'](11) != 3  or m['uac1MagicStoneStonesForLevel'](15) != 3  or m['uac1MagicStoneStonesForLevel'](16) != 4  or m['uac1MagicStoneStonesForLevel'](21) != 5  or  m['uac1MagicStoneInnateResistImmune']() != 1  or  m['uac1MagicStoneShieldBlocks']() != 1  or m['uac1MagicStoneDurationRounds']() != 6  or  m['uac1MagicStoneGiveToAnother']() != 1  or  m['uac1MagicStoneSomeReligionsForbid']() != 1  or  m['uac1MagicStoneComponentsLost']() != 1",
      "note" = "U7: magic stone",
    }, {
      "expr" = "strcmp(m['uac1PrecipName'](), \"Precipitation (Alteration)\") != 0  or m['uac1PrecipDurationSegmentsPerLevel']() != 1  or m['uac1PrecipCylinderDiameterInches']() != 3  or m['uac1PrecipCylinderHeightInches']() != 12  or  m['uac1PrecipComponentsLost']() != 1  or m['uac1PrecipThinMaterialDampSegments']() != 1  or m['uac1PrecipHeavyMaterialDampSegments']() != 2  or m['uac1PrecipFlatSurfaceDampSegments']() != 1  or m['uac1PrecipSemiPorousWetAfterSegments']() != 5  or  m['uac1PrecipPorousAbsorbs']() != 1  or m['uac1PrecipCandleOutSegments']() != 1  or m['uac1PrecipSmallFireSmokyRounds']() != 1  or  m['uac1PrecipLargeFiresUnaffected']() != 1  or m['uac1PrecipHotTempDoublesAboveF']() != 90  or m['uac1PrecipSleetHighF']() != 33  or m['uac1PrecipSleetLowF']() != 31  or m['uac1PrecipSnowAtOrBelowF']() != 30  or m['uac1PrecipMagicalHeatFogAreaMultiplier']() != 2  or  m['uac1PrecipMagicalColdFormsIce']() != 1  or  m['uac1PrecipMaterialSilverDust']() != 1",
      "note" = "U8: precipitation",
    }, {
      "expr" = "strcmp(m['uastClericName'](1, 1), \"Ceremony\") != 0  or strcmp(m['uastClericName'](1, 2), \"Combine\") != 0  or strcmp(m['uastClericName'](1, 8), \"Endure Cold/Heat\") != 0  or strcmp(m['uastClericName'](1, 9), \"Invisibility to Undead\") != 0  or strcmp(m['uastClericName'](1, 11), \"Magic Stone\") != 0  or strcmp(m['uastClericName'](1, 12), \"Penetrate Disguise\") != 0  or strcmp(m['uastClericName'](1, 14), \"Precipitation\") != 0  or m['uastClericName'](1, 13)[0] != 0  or m['uastClericName'](1, r)[0]) ++n; if (n != 18",
      "note" = "U9: the R341 table seam",
    } },
  "audit" = {
      "label" = "R343: the UA new cleric 1st level spells pin audit",
      "comment" = "The UA NEW CLERIC SPELLS (pp. 32-35), the 1st level - ceremony (the ten varieties and their levels, the special vows and the clean cost pairs), combine (the 3-5 cleric circle, the four-level gain cap, the 3-turn duration), endure cold/heat, penetrate disguise, invisibility to undead, portent (the 1d12/1d6 mechanics), magic stone and precipitation. The digit-garble family (four \"Level: 7\" cells print where the level is position-certain 1) decodes 7 as 1; the R341 table hole at row 13 decodes as portent. The item stays open (the 2nd-7th levels).",
    },
}
