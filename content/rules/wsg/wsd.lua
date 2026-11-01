-- wsd: promoted from rules/wsgdress.h (the The WSG DRESSING FOR THE WEATHER, R426:);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 426,
  "prefix" = "wsd",
  "banner" = {
      "title" = "The WSG DRESSING FOR THE WEATHER, R426:",
      "provenance" = "the first WSG pin round after the arc opener. The personal temperature system pins whole: the four clothing categories (the temperature ranges, the encumbrance equivalents, the outfit costs), Table 3 (the 15 attire rows x the 4 temperature columns, cumulative), the protected/unprotected rules, the exertion regimes and the clothing-as-armor option; census 351 -> 352.  Provenance: the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 18-20; the Table 3 grid, the row set and the clothing costs read from the IIIF page images (the text layer drops grid rows and mangles the figures); the rule prose verified whole against the text layer.",
    },
  "consts" = { {
      "name" = "wsdClothingCount",
      "value" = 4,
      "comment" = "The census: 4 categories, the book order (very cold, cold, moderate, hot).",
    }, {
      "name" = "wsdHotClothingCostSp",
      "value" = 6,
      "comment" = "The hot-clothing outfit cost ceiling: a robe at 6 sp.",
    }, {
      "name" = "wsdVcEncWeightGp",
      "value" = 450,
      "comment" = "The plate mail encumbrance weight, in gp.",
    }, {
      "name" = "wsdColdEncWeightGp",
      "value" = 250,
      "comment" = "",
    }, {
      "name" = "wsdModEncWeightGp",
      "value" = 150,
      "comment" = "",
    }, {
      "name" = "wsdVcEqColdLayers",
      "value" = 2,
      "comment" = "Very cold clothing equals two layers of cold clothing or four layers of moderate.",
    }, {
      "name" = "wsdVcEqModLayers",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "wsdAttireCount",
      "value" = 15,
      "comment" = "The census: 15 attire rows (the 4 clothing categories + the 11 armor types).",
    }, {
      "name" = "wsdColCount",
      "value" = 4,
      "comment" = "The census: 4 effective-temperature columns.",
    }, {
      "name" = "wsdVcUnprotectedAbove",
      "value" = 30,
      "comment" = "Very cold clothing leaves a character unprotected above 30 degrees effective.",
    }, {
      "name" = "wsdColdUnprotBelow",
      "value" = 0,
      "comment" = "Cold clothing: below 0 or above 50.",
    }, {
      "name" = "wsdColdUnprotAbove",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "wsdModUnprotBelow",
      "value" = 30,
      "comment" = "Moderate clothing: below 30 or above 80.",
    }, {
      "name" = "wsdModUnprotAbove",
      "value" = 80,
      "comment" = "",
    }, {
      "name" = "wsdHotUnprotBelow",
      "value" = 50,
      "comment" = "Hot clothing: below 50.",
    }, {
      "name" = "wsdMetalHighTemp",
      "value" = 80,
      "comment" = "Any metal armor (not studded leather) works above this effective temperature, regardless of clothing.",
    }, {
      "name" = "wsdExertGainBelow0",
      "value" = 5,
      "comment" = "Effective temperature below 0: a protected character gains 5 degrees per 4 consecutive turns of exertion.",
    }, {
      "name" = "wsdExertTurnsBelow0",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "wsdExertRestHoldBelow0",
      "value" = 1,
      "comment" = "One turn of rest holds the gain; resting longer loses it.",
    }, {
      "name" = "wsdExertMaxBelow0",
      "value" = 20,
      "comment" = "The 4-on/1-off cycle caps the gain at 20.",
    }, {
      "name" = "wsdExertGainWarm",
      "value" = 5,
      "comment" = "Effective temperature 0 to 30: a protected character gains 5 degrees after 6 consecutive turns, 10 (the maximum) after 12.",
    }, {
      "name" = "wsdExertTurnsWarm",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "wsdExertMaxWarm",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "wsdExertTurnsWarmMax",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "wsdExertRestLoseWarm",
      "value" = 2,
      "comment" = "The gain is retained until the character rests more than 2 turns in a row.",
    }, {
      "name" = "wsdExertGainHot",
      "value" = 5,
      "comment" = "Effective temperature 80 or higher: an UNPROTECTED character gains 5 degrees per 3 consecutive turns, up to a 25-degree maximum.",
    }, {
      "name" = "wsdExertTurnsHot",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "wsdExertMaxHot",
      "value" = 25,
      "comment" = "",
    }, {
      "name" = "wsdExertRestDropHot",
      "value" = 5,
      "comment" = "Resting drops the gain 5 degrees per 3 turns; resting AND taking off the armor drops 10 per 3 turns.",
    }, {
      "name" = "wsdExertRestDropHotRelieved",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "wsdVcArmorClass",
      "value" = 8,
      "comment" = "At the DM discretion, very cold clothing may impart armor class 8; cold clothing, armor class 9.",
    }, {
      "name" = "wsdColdArmorClass",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "wsdClothingMiscastChance",
      "value" = 10,
      "comment" = "The optional somatic miscast risk for casting in bulky clothing: 10 percent.",
    } },
  "bools" = { {
      "name" = "wsdVcEncEqPlateMail",
      "value" = true,
      "comment" = "Very cold clothing encumbers as plate mail (bulky).",
    }, {
      "name" = "wsdColdEncEqRingMail",
      "value" = true,
      "comment" = "Cold clothing encumbers as ring mail (fairly bulky).",
    }, {
      "name" = "wsdModEncEqLeather",
      "value" = true,
      "comment" = "Moderate clothing has no encumbrance value, or counts as leather armor (non-bulky) if heavy.",
    }, {
      "name" = "wsdHotEncumbranceNone",
      "value" = true,
      "comment" = "Hot clothing has no encumbrance value.",
    }, {
      "name" = "wsdDegreesAreFahrenheit",
      "value" = true,
      "comment" = "The temperatures are degrees Fahrenheit.",
    }, {
      "name" = "wsdTempAdjCumulative",
      "value" = true,
      "comment" = "Table 3 entries are cumulative, no matter whether armor is worn over clothing or vice versa.",
    }, {
      "name" = "wsdStuddedLeatherNotMetal",
      "value" = true,
      "comment" = "Studded leather is not metal armor for this rule.",
    }, {
      "name" = "wsdExertDropFloored",
      "value" = true,
      "comment" = "The drop is floored at the non-exerting personal temperature.",
    }, {
      "name" = "wsdMiscastIsOptional",
      "value" = true,
      "comment" = "",
    } },
  "switches" = { {
      "name" = "wsdCategoryLo",
      "values" = { -99, 0, 31, 76 },
      "default" = 0,
      "comment" = "The category range, low end; -99 = the range is open at the low end (very cold clothing suits anything below 0).",
    }, {
      "name" = "wsdCategoryHi",
      "values" = { -1, 30, 75, 99 },
      "default" = 0,
      "comment" = "The category range, high end; 99 = open (hot clothing suits anything above 75).",
    }, {
      "name" = "wsdCategoryCostGp",
      "values" = { 15, 7, 3, 0 },
      "default" = 0,
      "comment" = "The outfit cost, gold pieces (the hot category prices in silver - below).",
    }, {
      "name" = "wsdTempAdjBelow0",
      "values" = { 30, 20, 10, 0, 10, 10, 10, 5, 5, 0, 0, 0, 5, 20, 10 },
      "default" = 0,
      "comment" = "Column 0: the -1 or lower band (the value read per attire row).",
    }, {
      "name" = "wsdTempAdjCold",
      "values" = { 40, 30, 20, 0, 20, 20, 20, 10, 10, 5, 5, 5, 0, 30, 5 },
      "default" = 0,
      "comment" = "Column 1: the 0 to 30 band.",
    }, {
      "name" = "wsdTempAdjModerate",
      "values" = { 50, 40, 20, 0, 30, 30, 30, 15, 15, 10, 10, 10, 15, 40, 10 },
      "default" = 0,
      "comment" = "Column 2: the 31 to 75 band.",
    }, {
      "name" = "wsdTempAdjHot",
      "values" = { 60, 50, 30, 0, 40, 40, 30, 20, 20, 20, 20, 15, 30, 50, 20 },
      "default" = 0,
      "comment" = "Column 3: the 76 or higher band.",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['wsdClothingCount']() != 4  or m['wsdAttireCount']() != 15  or m['wsdColCount']() != 4  or  m['wsdDegreesAreFahrenheit']() != 1  or  m['wsdTempAdjCumulative']() != 1  or  m['wsdStuddedLeatherNotMetal']() != 1  or  m['wsdExertDropFloored']() != 1  or  m['wsdMiscastIsOptional']() != 1",
      "note" = "",
    }, {
      "expr" = "m['wsdCategoryLo'](0) != -99  or m['wsdCategoryLo'](1) != 0  or m['wsdCategoryLo'](2) != 31  or m['wsdCategoryLo'](3) != 76  or m['wsdCategoryHi'](0) != -1  or m['wsdCategoryHi'](1) != 30  or m['wsdCategoryHi'](2) != 75  or m['wsdCategoryHi'](3) != 99",
      "note" = "",
    }, {
      "expr" = "m['wsdCategoryCostGp'](0) != 15  or m['wsdCategoryCostGp'](1) != 7  or m['wsdCategoryCostGp'](2) != 3  or m['wsdCategoryCostGp'](3) != 0  or m['wsdHotClothingCostSp']() != 6  or  m['wsdVcEncEqPlateMail']() != 1  or m['wsdVcEncWeightGp']() != 450  or  m['wsdColdEncEqRingMail']() != 1  or m['wsdColdEncWeightGp']() != 250  or  m['wsdModEncEqLeather']() != 1  or m['wsdModEncWeightGp']() != 150  or  m['wsdHotEncumbranceNone']() != 1  or m['wsdVcEqColdLayers']() != 2  or m['wsdVcEqModLayers']() != 4",
      "note" = "",
    }, {
      "expr" = "m['wsdVcUnprotectedAbove']() != 30  or m['wsdColdUnprotBelow']() != 0  or m['wsdColdUnprotAbove']() != 50  or m['wsdModUnprotBelow']() != 30  or m['wsdModUnprotAbove']() != 80  or m['wsdHotUnprotBelow']() != 50  or m['wsdMetalHighTemp']() != 80",
      "note" = "the thresholds",
    }, {
      "expr" = "m['wsdExertGainBelow0']() != 5  or m['wsdExertTurnsBelow0']() != 4  or m['wsdExertRestHoldBelow0']() != 1  or m['wsdExertMaxBelow0']() != 20  or m['wsdExertGainWarm']() != 5  or m['wsdExertTurnsWarm']() != 6  or m['wsdExertMaxWarm']() != 10  or m['wsdExertTurnsWarmMax']() != 12  or m['wsdExertRestLoseWarm']() != 2  or m['wsdExertGainHot']() != 5  or m['wsdExertTurnsHot']() != 3  or m['wsdExertMaxHot']() != 25  or m['wsdExertRestDropHot']() != 5  or m['wsdExertRestDropHotRelieved']() != 10",
      "note" = "the exertion pins",
    }, {
      "expr" = "m['wsdVcArmorClass']() != 8  or m['wsdColdArmorClass']() != 9  or m['wsdClothingMiscastChance']() != 10",
      "note" = "clothing as armor",
    }, {
      "expr" = "m['wsdTempAdjBelow0'](0) != 30 or m['wsdTempAdjBelow0'](1) != 20 or m['wsdTempAdjBelow0'](2) != 10 or m['wsdTempAdjBelow0'](3) != 0 or m['wsdTempAdjBelow0'](4) != 10 or m['wsdTempAdjBelow0'](5) != 10 or m['wsdTempAdjBelow0'](6) != 10 or m['wsdTempAdjBelow0'](7) != 5",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wsdTempAdjBelow0'](8) != 5 or m['wsdTempAdjBelow0'](9) != 0 or m['wsdTempAdjBelow0'](10) != 0 or m['wsdTempAdjBelow0'](11) != 0 or m['wsdTempAdjBelow0'](12) != 5 or m['wsdTempAdjBelow0'](13) != 20 or m['wsdTempAdjBelow0'](14) != 10 or m['wsdTempAdjBelow0'](15) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wsdTempAdjCold'](0) != 40 or m['wsdTempAdjCold'](1) != 30 or m['wsdTempAdjCold'](2) != 20 or m['wsdTempAdjCold'](3) != 0 or m['wsdTempAdjCold'](4) != 20 or m['wsdTempAdjCold'](5) != 20 or m['wsdTempAdjCold'](6) != 20 or m['wsdTempAdjCold'](7) != 10",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wsdTempAdjCold'](8) != 10 or m['wsdTempAdjCold'](9) != 5 or m['wsdTempAdjCold'](10) != 5 or m['wsdTempAdjCold'](11) != 5 or m['wsdTempAdjCold'](12) != 0 or m['wsdTempAdjCold'](13) != 30 or m['wsdTempAdjCold'](14) != 5 or m['wsdTempAdjCold'](15) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wsdTempAdjModerate'](0) != 50 or m['wsdTempAdjModerate'](1) != 40 or m['wsdTempAdjModerate'](2) != 20 or m['wsdTempAdjModerate'](3) != 0 or m['wsdTempAdjModerate'](4) != 30 or m['wsdTempAdjModerate'](5) != 30 or m['wsdTempAdjModerate'](6) != 30 or m['wsdTempAdjModerate'](7) != 15",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wsdTempAdjModerate'](8) != 15 or m['wsdTempAdjModerate'](9) != 10 or m['wsdTempAdjModerate'](10) != 10 or m['wsdTempAdjModerate'](11) != 10 or m['wsdTempAdjModerate'](12) != 15 or m['wsdTempAdjModerate'](13) != 40 or m['wsdTempAdjModerate'](14) != 10 or m['wsdTempAdjModerate'](15) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wsdTempAdjHot'](0) != 60 or m['wsdTempAdjHot'](1) != 50 or m['wsdTempAdjHot'](2) != 30 or m['wsdTempAdjHot'](3) != 0 or m['wsdTempAdjHot'](4) != 40 or m['wsdTempAdjHot'](5) != 40 or m['wsdTempAdjHot'](6) != 30 or m['wsdTempAdjHot'](7) != 20",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['wsdTempAdjHot'](8) != 20 or m['wsdTempAdjHot'](9) != 20 or m['wsdTempAdjHot'](10) != 20 or m['wsdTempAdjHot'](11) != 15 or m['wsdTempAdjHot'](12) != 30 or m['wsdTempAdjHot'](13) != 50 or m['wsdTempAdjHot'](14) != 20 or m['wsdTempAdjHot'](15) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R426: the WSG dressing pin audit",
      "comment" = "The first WSG pin round after the arc opener closes the dressing-for-the-weather chapter whole (rules/wsgdress.h, prefix wsd): the four clothing categories (the ranges, the encumbrance equivalents, the outfit costs), the Table 3 grid (the 15 attire rows x the 4 temperature columns, cumulative) verified cell for cell with the row/column censuses, the protected/unprotected truth table, the three exertion regimes with the book own chain mail example and the clothing-as-armor option; census 351 -> 352.",
    },
}
