-- ua352: promoted from rules/ua/uadruidspells3.h (the The UA NEW DRUID SPELLS (pp. 44-45) pins, R352: the 3rd-level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 352,
  "prefix" = "ua352",
  "banner" = {
      "title" = "The UA NEW DRUID SPELLS (pp. 44-45) pins, R352: the 3rd-level",
      "provenance" = "spell descriptions - cloudburst, know alignment, spike growth and starshine.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the digit-garble family (the R343 precedent): the starshine duration prints \"7 turn/level\" - the family decodes 1 turn/level (starshine prints a clean \"Level: 3\" cell). - the cloudburst stat block scrambles both columns into one print: \"pid pve; 3 Effect: 1 ro 4 diam. cylinder up to Components: Casting Saving 6\" high Throw: Time: V, 5 None S, segments M (& special)\" plus the stray \"vol\" and \"Area of\" fragments. Reassembly: Components V, S, M; Level 3; Casting Time 5 segments; Saving Throw None (& special); Duration 1 round/level (the \"1 ro\" + \"vol\" split); Area of Effect a 4\" diameter cylinder up to 6\" high. The \"pid pve;\" fragment is a lost head - a hole. The range never prints - a hole. - the cloudburst prose head scrambles: \"This spell is the same as the 3rd-level clerical spell of the same name, with only the following special notations and additions:\" with the call lightning fragments interleaved - decoded as the exclusion: a call lightning spell cannot be used in the same area at the same time. - the know alignment components cell prints \"V, S\\$\" - the S-garble family (the R343 \"V, \u00a7\" precedent); decoded. - the know alignment prose: same as the 2nd-level clerical spell except as noted in the stat cells; because of the shorter duration only five creatures (maximum) can be examined, and it cannot be reversed. - the spike growth prose head prints \"This spell i ... ially the same as\" - the lost head decodes as \"is essentially\". The interleave reassembly: the affected area will radiate an aura; a detect magic [spell] will reveal the location of pits and snares; the druid must use mistletoe as an addition to the material component of spike growth, in place of the cleric's holy symbol, [and] seven small twigs or thorns. - the starshine name header prints \"Starshine (Evocation -\" [sic]) - the school tail is lost; the school pins as Evocation with the tail flagged as a hole. - the starshine prose prints clean: the vision bands (clear to 30', indistinct to 60', gleams beyond), the ultravision enhancement without infravision effect, the disbelief reveal, and the amaryllis plus holly berry components.  OCR holes (the item stays open - the 5th-7th levels pin in later rounds - note the UA prints no 4th-level druid section; these stay pending the PDF): the cloudburst \"pid pve;\" head fragment; the cloudburst range cell; the know alignment \"except as noted above\" referents beyond the stat cells; the spike growth aura/detect-magic clause beyond the fragments; the starshine school tail.",
    },
  "consts" = { {
      "name" = "uad3CloudburstName",
      "value" = "Cloudburst (Alteration)",
      "comment" = "---- cloudburst (Alteration), p. 44 ----",
    }, {
      "name" = "uad3CloudburstLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad3CloudburstCastingTimeSegments",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uad3CloudburstDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "The duration decodes from the \"1 ro\" + \"vol\" fragments as 1 round/level (the stat block interleave).",
    }, {
      "name" = "uad3CloudburstCylinderDiameterInches",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uad3CloudburstCylinderHeightInches",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uad3KnowAlignmentName",
      "value" = "Know Alignment (Divination)",
      "comment" = "---- know alignment (Divination), p. 44 ----",
    }, {
      "name" = "uad3KnowAlignmentLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad3KnowAlignmentRangeInches",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad3KnowAlignmentDurationRounds",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uad3KnowAlignmentCastingTimeSegments",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uad3KnowAlignmentMaxCreaturesExamined",
      "value" = 5,
      "comment" = "Because of the shorter duration, only five creatures (maximum) can be examined.",
    }, {
      "name" = "uad3SpikeGrowthName",
      "value" = "Spike Growth (Alteration/Enchantment)",
      "comment" = "---- spike growth (Alteration/Enchantment), p. 45 ----",
    }, {
      "name" = "uad3SpikeGrowthLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad3SpikeGrowthCastingTimeSegments",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uad3SpikeGrowthRangeInches",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uad3SpikeGrowthDurationTurnsMin",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad3SpikeGrowthDurationTurnsMax",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uad3SpikeGrowthDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad3SpikeGrowthAoeSquaresPerLevel",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uad3SpikeGrowthMaterialTwigsOrThorns",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uad3StarshineName",
      "value" = "Starshine",
      "comment" = "---- starshine (Evocation - ...), p. 45 ----",
    }, {
      "name" = "uad3StarshineLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad3StarshineCastingTimeSegments",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uad3StarshineRangeInchesPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad3StarshineDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"7 turn/level\" - the digit-garble family decodes 1 turn/level.",
    }, {
      "name" = "uad3StarshineAoeSquaresPerLevel",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uad3StarshineVisionClearFeet",
      "value" = 30,
      "comment" = "Vision is clear at up to 30 feet, indistinct out to 60 feet, and beyond that only gleams and glimmers are discernible.",
    }, {
      "name" = "uad3StarshineVisionIndistinctFeet",
      "value" = 60,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uad3CloudburstComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3CloudburstSaveNoneAndSpecial",
      "value" = true,
      "comment" = "The saving throw prints \"None (& special)\".",
    }, {
      "name" = "uad3CloudburstStatBlockInterleaveDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3CloudburstHeadFragmentLost",
      "value" = true,
      "comment" = "The \"pid pve;\" fragment and the missing range cell - holes.",
    }, {
      "name" = "uad3CloudburstRangeLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3CloudburstIdenticalToClerical3rd",
      "value" = true,
      "comment" = "The prose head scramble decodes: this spell is the same as the 3rd-level clerical spell of the same name.",
    }, {
      "name" = "uad3CloudburstCallLightningExclusion",
      "value" = true,
      "comment" = "The special notation: a call lightning spell cannot be used in the same area at the same time (the interleave decode).",
    }, {
      "name" = "uad3CloudburstProseHeadScrambleDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3CloudburstMaterialMistletoe",
      "value" = true,
      "comment" = "The druid must use mistletoe as an additional material component (prints clean).",
    }, {
      "name" = "uad3KnowAlignmentComponentsVSGarble",
      "value" = true,
      "comment" = "The components cell prints \"V, S$\" - the S-garble family.",
    }, {
      "name" = "uad3KnowAlignmentAoeOnePerRound",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3KnowAlignmentSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3KnowAlignmentIdenticalToClerical2nd",
      "value" = true,
      "comment" = "The prose head scramble decodes: this spell is the same as the 2nd-level clerical spell of the same name, except as noted in the stat cells.",
    }, {
      "name" = "uad3KnowAlignmentCannotBeReversed",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3SpikeGrowthComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3SpikeGrowthSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3SpikeGrowthIdenticalToClerical4th",
      "value" = true,
      "comment" = "The prose head prints \"This spell i ... ially the same as\" - the lost head decodes as \"is essentially\" - this spell is essentially the same as the 4th-level clerical spell of the same name, except as noted above.",
    }, {
      "name" = "uad3SpikeGrowthHeadDecodeEssentially",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3SpikeGrowthRadiatesAura",
      "value" = true,
      "comment" = "The interleave: the affected area will radiate an aura, and a detect magic [spell] will reveal the location of pits and snares.",
    }, {
      "name" = "uad3SpikeGrowthDetectMagicRevealsPitsAndSnares",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3SpikeGrowthMaterialMistletoe",
      "value" = true,
      "comment" = "The material interleave decode: mistletoe as an addition to the material component of spike growth, in place of the cleric's holy symbol, and seven small twigs or thorns.",
    }, {
      "name" = "uad3SpikeGrowthMaterialInPlaceOfHolySymbol",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3SpikeGrowthMaterialInterleaveDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3StarshineSchoolEvocation",
      "value" = true,
      "comment" = "The name header prints \"Starshine (Evocation -\" [sic]) - the school tail is lost; the school pins as Evocation with the tail flagged.",
    }, {
      "name" = "uad3StarshineSchoolTailLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3StarshineComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3StarshineSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3StarshineNightSkyIllumination",
      "value" = true,
      "comment" = "Softly illuminates an area as if exposed to a clear night sky filled with stars; regardless of the height of the open area, the ground immediately beneath is lit by starshine.",
    }, {
      "name" = "uad3StarshineRegardlessOfHeight",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3StarshineGleamsBeyond",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3StarshineAllowsShadows",
      "value" = true,
      "comment" = "The starshine allows shadows; it enhances ultravision to its full potential but does not affect infravision.",
    }, {
      "name" = "uad3StarshineEnhancesUltravision",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3StarshineNoInfravisionEffect",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3StarshineDisbeliefRevealsEvokedLights",
      "value" = true,
      "comment" = "The area appears to be a night sky, but disbelief merely allows the disbeliever to note that the \"stars\" are actually evoked lights.",
    }, {
      "name" = "uad3StarshineMaterialAmaryllisStalks",
      "value" = true,
      "comment" = "The material: several stalks from an amaryllis (especially Hypoxis) and several holly berries.",
    }, {
      "name" = "uad3StarshineMaterialHollyBerries",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad3StarshineWorksThroughReflectingPool",
      "value" = true,
      "comment" = "The R351 reflecting pool seam: starshine operates normally through the reflecting pool (see rules/ua/uadruidspells2.h).",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uad3CloudburstName'](), \"Cloudburst (Alteration)\") != 0  or  m['uad3CloudburstComponentsVSM']() != 1  or m['uad3CloudburstLevel']() != 3  or m['uad3CloudburstCastingTimeSegments']() != 5  or  m['uad3CloudburstSaveNoneAndSpecial']() != 1  or m['uad3CloudburstDurationRoundsPerLevel']() != 1  or m['uad3CloudburstCylinderDiameterInches']() != 4  or m['uad3CloudburstCylinderHeightInches']() != 6  or  m['uad3CloudburstStatBlockInterleaveDecoded']() != 1  or  m['uad3CloudburstHeadFragmentLost']() != 1  or  m['uad3CloudburstRangeLost']() != 1  or  m['uad3CloudburstIdenticalToClerical3rd']() != 1  or  m['uad3CloudburstCallLightningExclusion']() != 1  or  m['uad3CloudburstProseHeadScrambleDecoded']() != 1  or  m['uad3CloudburstMaterialMistletoe']() != 1",
      "note" = "U1: cloudburst",
    }, {
      "expr" = "strcmp(m['uad3KnowAlignmentName'](), \"Know Alignment (Divination)\") != 0  or  m['uad3KnowAlignmentComponentsVSGarble']() != 1  or m['uad3KnowAlignmentLevel']() != 3  or m['uad3KnowAlignmentRangeInches']() != 1  or m['uad3KnowAlignmentDurationRounds']() != 5  or  m['uad3KnowAlignmentAoeOnePerRound']() != 1  or m['uad3KnowAlignmentCastingTimeSegments']() != 5  or  m['uad3KnowAlignmentSaveNone']() != 1  or  m['uad3KnowAlignmentIdenticalToClerical2nd']() != 1  or m['uad3KnowAlignmentMaxCreaturesExamined']() != 5  or  m['uad3KnowAlignmentCannotBeReversed']() != 1",
      "note" = "U2: know alignment",
    }, {
      "expr" = "strcmp(m['uad3SpikeGrowthName'](), \"Spike Growth (Alteration/Enchantment)\") != 0  or  m['uad3SpikeGrowthComponentsVSM']() != 1  or m['uad3SpikeGrowthLevel']() != 3  or m['uad3SpikeGrowthCastingTimeSegments']() != 5  or m['uad3SpikeGrowthRangeInches']() != 6  or  m['uad3SpikeGrowthSaveNone']() != 1  or m['uad3SpikeGrowthDurationTurnsMin']() != 3  or m['uad3SpikeGrowthDurationTurnsMax']() != 12  or m['uad3SpikeGrowthDurationTurnsPerLevel']() != 1  or m['uad3SpikeGrowthAoeSquaresPerLevel']() != 10  or  m['uad3SpikeGrowthIdenticalToClerical4th']() != 1  or  m['uad3SpikeGrowthHeadDecodeEssentially']() != 1  or  m['uad3SpikeGrowthRadiatesAura']() != 1  or  m['uad3SpikeGrowthDetectMagicRevealsPitsAndSnares']() != 1  or  m['uad3SpikeGrowthMaterialMistletoe']() != 1  or  m['uad3SpikeGrowthMaterialInPlaceOfHolySymbol']() != 1  or m['uad3SpikeGrowthMaterialTwigsOrThorns']() != 7  or  m['uad3SpikeGrowthMaterialInterleaveDecoded']() != 1",
      "note" = "U3: spike growth",
    }, {
      "expr" = "strcmp(m['uad3StarshineName'](), \"Starshine\") != 0  or  m['uad3StarshineSchoolEvocation']() != 1  or  m['uad3StarshineSchoolTailLost']() != 1  or  m['uad3StarshineComponentsVSM']() != 1  or m['uad3StarshineLevel']() != 3  or m['uad3StarshineCastingTimeSegments']() != 5  or m['uad3StarshineRangeInchesPerLevel']() != 1  or  m['uad3StarshineSaveNone']() != 1  or m['uad3StarshineDurationTurnsPerLevel']() != 1  or m['uad3StarshineAoeSquaresPerLevel']() != 10  or  m['uad3StarshineNightSkyIllumination']() != 1  or  m['uad3StarshineRegardlessOfHeight']() != 1  or m['uad3StarshineVisionClearFeet']() != 30  or m['uad3StarshineVisionIndistinctFeet']() != 60  or  m['uad3StarshineGleamsBeyond']() != 1  or  m['uad3StarshineAllowsShadows']() != 1  or  m['uad3StarshineEnhancesUltravision']() != 1  or  m['uad3StarshineNoInfravisionEffect']() != 1  or  m['uad3StarshineDisbeliefRevealsEvokedLights']() != 1  or  m['uad3StarshineMaterialAmaryllisStalks']() != 1  or  m['uad3StarshineMaterialHollyBerries']() != 1  or  m['uad3StarshineWorksThroughReflectingPool']() != 1",
      "note" = "U4: starshine",
    }, {
      "expr" = "m['uad2ReflectingPoolStarshineOperates']() != 1  or  m['uad3StarshineWorksThroughReflectingPool']() != 1  or m['uastDruid1stCount']() != 4  or strcmp(m['uastDruid1stName'](2), \"Shillelagh\") != 0  or m['uastDruid4thCount']() != 6  or strcmp(m['uastDruid4thName'](2), \"Hallucinatory Forest\") != 0  or m['uastDruid6thCount']() != 5  or strcmp(m['uastDruid6thName'](4), \"Weather Summoning\") != 0",
      "note" = "U5: the cross-round and R341 seams",
    } },
  "audit" = {
      "label" = "R352: the UA new druid 3rd level spells pin audit",
      "comment" = "The UA NEW DRUID SPELLS (pp. 44-45), the 3rd level - cloudburst (the stat-block interleave with the call lightning exclusion), know alignment (the five-creature cap, not reversible), spike growth (the mistletoe-plus-twigs material interleave) and starshine (the school tail lost). The digit-garble family decodes the \"7 turn/level\" as 1; the cloudburst duration decodes from the \"1 ro\" + \"vol\" fragments. The item stays open (the 5th-7th levels; the UA prints no 4th-level druid section).",
    },
}
