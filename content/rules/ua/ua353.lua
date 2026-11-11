-- ua353: promoted from rules/ua/uadruidspells5.h (the The UA NEW DRUID SPELLS (p. 45) pins, R353: the 5th-level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 353,
  "prefix" = "ua353",
  "banner" = {
      "title" = "The UA NEW DRUID SPELLS (p. 45) pins, R353: the 5th-level",
      "provenance" = "spell descriptions - moonbeam and spike stones.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the digit-garble family (the R343 precedent): the moonbeam casting time prints \"7 segments\" - the family decodes 1 segment (moonbeam prints a clean \"Level: 5\" cell). - the moonbeam name header prints \"Moonbeam (Evocation - Alteration)\" without the \"## \" marker - a formatting loss, not a content loss; the name and school pin clean. - the moonbeam range cell prints \"Range: 1\" - the unit mark is lost; position-decoded as 1 inch (the R346 interleave precedent), pinned with doubt pending the PDF. - the spike stones school cell prints \"Alteration/ Enhancement\" while the R347 clerical pin (rules/ uaclericspells5.h) reads \"Alteration/Enchantment\" - the druid cell is pinned verbatim with the discrepancy flagged; pending the PDF. - the spike stones casting time cell prints empty - a hole; the clerical R347 pin reads 6 segments (noted, not re-pinned here). - the spike stones prose: \"This spell is the same as the 5th-level clerical spell of the same name.\" - the druid version pins as identical; every stat cell seam-checks against the R347 clerical pin (range 3\", save none, duration 3-12 turns + 1/level, area 1\" square per level with 1 spike per square foot). - the druid spike stones area cell prints \"1\" square per level, 1 spike per 1' sq.\" - corroborating the R347 decode of the clerical area cell.  OCR holes (the item stays open - the 6th and 7th levels pin in later rounds; these stay pending the PDF): the moonbeam range unit mark; the spike stones casting time cell; the spike stones school discrepancy (Enhancement vs the R347 clerical Enchantment).",
    },
  "consts" = { {
      "name" = "uad5MoonbeamName",
      "value" = "Moonbeam (Evocation - Alteration)",
      "comment" = "---- moonbeam (Evocation - Alteration), p. 45 ----",
    }, {
      "name" = "uad5MoonbeamLevel",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uad5MoonbeamCastingTimeSegments",
      "value" = 1,
      "comment" = "The casting time prints \"7 segments\" - the digit-garble family decodes 1 segment.",
    }, {
      "name" = "uad5MoonbeamRangeInches",
      "value" = 1,
      "comment" = "The range cell prints \"Range: 1\" - the unit mark is lost; position-decoded as 1 inch, with doubt.",
    }, {
      "name" = "uad5MoonbeamDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad5MoonbeamDimPerceptionInchesBeyond",
      "value" = 1,
      "comment" = "The reflected light allows dim visual perception 1 inch beyond the area of effect.",
    }, {
      "name" = "uad5SpikeStonesName",
      "value" = "Spike Stones (Alteration/Enhancement)",
      "comment" = "---- spike stones (Alteration/Enhancement), p. 45 ---- The druid school cell prints \"Alteration/Enhancement\" - the R347 clerical pin reads \"Alteration/Enchantment\"; the druid cell is pinned verbatim with the discrepancy flagged.",
    }, {
      "name" = "uad5SpikeStonesLevel",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uad5SpikeStonesRangeInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad5SpikeStonesDurationTurnsMin",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad5SpikeStonesDurationTurnsMax",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uad5SpikeStonesDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad5SpikeStonesAoeSquareInchesPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad5SpikeStonesSpikesPerSquareFoot",
      "value" = 1,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uad5MoonbeamHeaderMarkerLost",
      "value" = true,
      "comment" = "The name header prints without the \"## \" marker - a formatting loss; the name and school pin clean.",
    }, {
      "name" = "uad5MoonbeamComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad5MoonbeamRangeUnitLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad5MoonbeamSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad5MoonbeamAoeOneInchSpherePlusSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad5MoonbeamDownwardBeamOnPointedArea",
      "value" = true,
      "comment" = "A beam of soft, pale light strikes downward from overhead and illuminates whatever area the caster is pointing at.",
    }, {
      "name" = "uad5MoonbeamExactMoonlight",
      "value" = true,
      "comment" = "The light is exactly the same as moonlight - colors other than shades of black, gray, or white are not determinable.",
    }, {
      "name" = "uad5MoonbeamColorsNotDeterminable",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad5MoonbeamMovesToSeenPointedAreas",
      "value" = true,
      "comment" = "The caster can easily cause the moonbeam to move to any area he or she can see and point to - an effective spotlight, for example upon an opponent.",
    }, {
      "name" = "uad5MoonbeamEffectiveSpotlight",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad5MoonbeamAllowsShadows",
      "value" = true,
      "comment" = "The moonbeam allows shadows; a creature centered in it is most certainly under observation.",
    }, {
      "name" = "uad5MoonbeamCenteredCreatureObserved",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad5MoonbeamNoInfravisionAdverseEffect",
      "value" = true,
      "comment" = "The light does not adversely affect infravision, and enhances ultravision to its greatest potential.",
    }, {
      "name" = "uad5MoonbeamEnhancesUltravision",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad5MoonbeamMaterialMoonseedSeeds",
      "value" = true,
      "comment" = "The material: several seeds of any moonseed plant and a piece of opalescent feldspar (moonstone).",
    }, {
      "name" = "uad5MoonbeamMaterialMoonstoneFeldspar",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad5SpikeStonesSchoolDiscrepancyFlagged",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad5SpikeStonesComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad5SpikeStonesCastingTimeCellLost",
      "value" = true,
      "comment" = "The casting time cell prints empty - a hole; the R347 clerical pin reads 6 segments (noted, not re-pinned).",
    }, {
      "name" = "uad5SpikeStonesSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad5SpikeStonesIdenticalToClerical",
      "value" = true,
      "comment" = "The prose: this spell is the same as the 5th-level clerical spell of the same name.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uad5MoonbeamName'](), \"Moonbeam (Evocation - Alteration)\") != 0  or  m['uad5MoonbeamHeaderMarkerLost']() != 1  or  m['uad5MoonbeamComponentsVSM']() != 1  or m['uad5MoonbeamLevel']() != 5  or m['uad5MoonbeamCastingTimeSegments']() != 1  or m['uad5MoonbeamRangeInches']() != 1  or  m['uad5MoonbeamRangeUnitLost']() != 1  or  m['uad5MoonbeamSaveNone']() != 1  or m['uad5MoonbeamDurationRoundsPerLevel']() != 1  or  m['uad5MoonbeamAoeOneInchSpherePlusSpecial']() != 1  or  m['uad5MoonbeamDownwardBeamOnPointedArea']() != 1  or  m['uad5MoonbeamExactMoonlight']() != 1  or  m['uad5MoonbeamColorsNotDeterminable']() != 1  or  m['uad5MoonbeamMovesToSeenPointedAreas']() != 1  or  m['uad5MoonbeamEffectiveSpotlight']() != 1  or  m['uad5MoonbeamAllowsShadows']() != 1  or  m['uad5MoonbeamCenteredCreatureObserved']() != 1  or m['uad5MoonbeamDimPerceptionInchesBeyond']() != 1  or  m['uad5MoonbeamNoInfravisionAdverseEffect']() != 1  or  m['uad5MoonbeamEnhancesUltravision']() != 1  or  m['uad5MoonbeamMaterialMoonseedSeeds']() != 1  or  m['uad5MoonbeamMaterialMoonstoneFeldspar']() != 1",
      "note" = "U1: moonbeam",
    }, {
      "expr" = "strcmp(m['uad5SpikeStonesName'](), \"Spike Stones (Alteration/Enhancement)\") != 0  or  m['uad5SpikeStonesSchoolDiscrepancyFlagged']() != 1  or  m['uad5SpikeStonesComponentsVSM']() != 1  or m['uad5SpikeStonesLevel']() != 5  or  m['uad5SpikeStonesCastingTimeCellLost']() != 1  or m['uad5SpikeStonesRangeInches']() != 3  or  m['uad5SpikeStonesSaveNone']() != 1  or m['uad5SpikeStonesDurationTurnsMin']() != 3  or m['uad5SpikeStonesDurationTurnsMax']() != 12  or m['uad5SpikeStonesDurationTurnsPerLevel']() != 1  or m['uad5SpikeStonesAoeSquareInchesPerLevel']() != 1  or m['uad5SpikeStonesSpikesPerSquareFoot']() != 1  or  m['uad5SpikeStonesIdenticalToClerical']() != 1",
      "note" = "U2: spike stones",
    }, {
      "expr" = "m['uad5SpikeStonesRangeInches']() !=m['uac5SpikeStonesRangeInches']()  or m['uad5SpikeStonesDurationTurnsMin']() !=m['uac5SpikeStonesDurationTurnsMin']()  or m['uad5SpikeStonesDurationTurnsMax']() !=m['uac5SpikeStonesDurationTurnsMax']()  or m['uad5SpikeStonesDurationTurnsPerLevel']() !=m['uac5SpikeStonesDurationTurnsPerLevel']()  or m['uad5SpikeStonesAoeSquareInchesPerLevel']() !=m['uac5SpikeStonesAoeSquareInchesPerLevel']()  or m['uad5SpikeStonesSpikesPerSquareFoot']() !=m['uac5SpikeStonesSpikesPerSquareFoot']()  or  m['uac5SpikeStonesSaveNone']() != 1  or m['uastDruid5thCount']() != 6  or strcmp(m['uastDruid5thName'](0), \"Commune With Nature\") != 0  or strcmp(m['uastDruid5thName'](5), \"Wall Of Fire\") != 0",
      "note" = "U3: the R347 clerical seam",
    } },
  "audit" = {
      "label" = "R353: the UA new druid 5th level spells pin audit",
      "comment" = "The UA NEW DRUID SPELLS (p. 45), the 5th level - moonbeam (the movable spotlight beam with the color and vision effects) and spike stones (the school discrepancy vs the R347 clerical pin flagged; the stat cells seam-check). The digit-garble family decodes the \"7 segments\" as 1. The item stays open (the 6th-7th levels).",
    },
}
