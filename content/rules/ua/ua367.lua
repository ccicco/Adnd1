-- ua367: promoted from the round R367 pin headers (the the UA campaign social class and birth);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 367,
  "prefix" = "ua367",
  "banner" = {
      "title" = "the UA campaign social class and birth",
      "provenance" = "rules/ua/uabirth.h (the The UA CIRCUMSTANCES OF BIRTH (p. 83 print) pins,): R367: the Birth Table (the 12-child ladder with the only-child row), the Parents' Marital Status Table and the racial modifiers.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the section intro garbles (\"By the nature for of the topic...\") - the readable tail pins (the DM decides, the tables are a starting point), the rest is a hole pending the PDF. - the high-elf modifier cell prints a bare \"20\" with the sign lost (every other cell carries an explicit sign) - the magnitude pins, the sign is a hole pending the PDF. - the marital-status print interleaves the married/unmarried labels across the dice columns (01-80 / 81-00) - the split pins from the readable dice cells.  rules/ua/uasocialclass.h (the The UA SOCIAL CLASS AND RANK (p. 82 print) pins,): R367: the Social Class Table (the nine-band dice ladder), the occupation rosters, the starting-money note, the non-human placements and the profession rule. Extends the landed R208 DMG structure header (rules/dmg/socialrank.h), which pins the government forms and the town structure but no random class table - the UA print adds the dice table.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the LLC roster label cell garbles (\"Typloat LLC: members Freed of...\") - the roster list itself reads; the label cell is flagged, the names pin. - the halfling placement prints \"ULC (they are small and rustic)\" - the parenthetical reads against the printed band; the print wins, the divergence flagged pending the PDF. - R394: the clean PDF read fills the LLC label cell (the roster head is Freed slaves) and confirms the halfling parenthetical. - the R336 seam: the cavalier money stations name the LMC/MMC/UMC/LUC/MUC/UUC bands exactly - the band names pin to the R336 spellings.",
    },
  "consts" = { {
      "name" = "uabirthRowCount",
      "value" = 13,
      "comment" = "---- the birth table, 13 rows ----",
    }, {
      "name" = "uabirthMarriedLow",
      "value" = 1,
      "comment" = "---- the parents' marital status table ----",
    }, {
      "name" = "uabirthMarriedHigh",
      "value" = 80,
      "comment" = "",
    }, {
      "name" = "uabirthUnmarriedLow",
      "value" = 81,
      "comment" = "",
    }, {
      "name" = "uabirthUnmarriedHigh",
      "value" = 100,
      "comment" = "",
    }, {
      "name" = "uabirthDwarfMod",
      "value" = -15,
      "comment" = "---- the racial modifiers (both tables) ----",
    }, {
      "name" = "uabirthElfDrowMod",
      "value" = -15,
      "comment" = "",
    }, {
      "name" = "uabirthElfGrayMod",
      "value" = -30,
      "comment" = "",
    }, {
      "name" = "uabirthElfHighModMagnitude",
      "value" = 20,
      "comment" = "The R394 clean read: the high-elf cell prints -20 - the sign pins negative like every other cell.",
    }, {
      "name" = "uabirthElfHighMod",
      "value" = -20,
      "comment" = "",
    }, {
      "name" = "uabirthElfWoodMod",
      "value" = -10,
      "comment" = "",
    }, {
      "name" = "uabirthElfOtherMod",
      "value" = -15,
      "comment" = "",
    }, {
      "name" = "uabirthGnomeMod",
      "value" = -20,
      "comment" = "",
    }, {
      "name" = "uabirthHalfElfMod",
      "value" = -10,
      "comment" = "",
    }, {
      "name" = "uabirthHalflingMod",
      "value" = -10,
      "comment" = "",
    }, {
      "name" = "uabirthHalfOrcBirthMod",
      "value" = 10,
      "comment" = "The half-orc split: +10 on the Birth Table, +75 on the Marital Status Table.",
    }, {
      "name" = "uabirthHalfOrcMaritalMod",
      "value" = 75,
      "comment" = "",
    }, {
      "name" = "uasocBandCount",
      "value" = 9,
      "comment" = "---- the nine bands, in social-ladder order ----",
    } },
  "bools" = { {
      "name" = "uabirthUnmarriedOneClassBelowFather",
      "value" = true,
      "comment" = "The child of unmarried parents is typically one social class lower than the social class of the father.",
    }, {
      "name" = "uabirthElfHighModSignLost",
      "value" = false,
      "comment" = "",
    }, {
      "name" = "uabirthHumanNoMods",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabirthIntroGarbled",
      "value" = false,
      "comment" = "---- the intro reads ---- The R394 clean read: the section intro reads clean in the PDF.",
    }, {
      "name" = "uabirthDmDecidesToMilieu",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uabirthTablesAStartingPoint",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocLlcLabelCellGarbled",
      "value" = false,
      "comment" = "The R394 clean read: the LLC label cell reads clean.",
    }, {
      "name" = "uasocTableExcludesPoliticalInfo",
      "value" = true,
      "comment" = "---- the intro reads ---- The table does not include any social or political information; guidelines follow the table so the DM can model the class distinctions to the tenor of the individual milieu.",
    }, {
      "name" = "uasocGuidelinesFollowTheTable",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocDmModelsToMilieu",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocPcStartMoneyUnaffected",
      "value" = true,
      "comment" = "---- the starting-money note ---- For player characters, initial social status has no effect on starting money and equipment, with the exception of cavaliers and paladins (the Money heading cross-reference, the landed R336 seam).",
    }, {
      "name" = "uasocExceptCavaliersAndPaladins",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocCavPaladinSeeMoneyHeading",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocDwarvesMMC",
      "value" = true,
      "comment" = "---- the non-human placements ----",
    }, {
      "name" = "uasocDwarvesGoldGemsReputation",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocWoodElfULC",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocGrayElfLUC",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocGnomeULCToLMC",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocHalflingULC",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocHalflingParentheticalDivergence",
      "value" = false,
      "comment" = "The R394 clean read: the halfling parenthetical confirms the ULC band.",
    }, {
      "name" = "uasocHalfElfSlightlyAboveHuman",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocHalfOrcLLC",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocNonHumanPlacementMilieuDependent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocProfessionOneRankBelowMinimum",
      "value" = true,
      "comment" = "---- the profession rule ---- A character must have a social status of, at the lowest, one rank below that specified for the profession in the milieu; the printed example: a fighter needs Middle Lower Class or higher, so a Lower Lower Class character can be only a thief or assassin.",
    }, {
      "name" = "uasocFighterRequiresMlcMinimum",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasocLlcBornOnlyThiefOrAssassin",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uabirthRowLow",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[13] = { 1, 6, 11, 21, 36, 51, 66, 81, 86, 91, 95, 98, 100, }; if (i < 0) i = 0; if (i > 12) i = 12; return k[i];",
    }, {
      "name" = "uabirthRowHigh",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[13] = { 5, 10, 20, 35, 50, 65, 80, 85, 90, 94, 97, 99, 100, }; if (i < 0) i = 0; if (i > 12) i = 12; return k[i];",
    }, {
      "name" = "uabirthOrderLabel",
      "comment" = "",
      "kind" = "string array",
      "count" = 13,
      "values" = { "Only child", "1st child", "2nd child", "3rd child", "4th child", "5th child", "6th child", "7th child", "8th child", "9th child", "10th child", "11th child", "12th child" },
    }, {
      "name" = "uasocBandLow",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[9] = { 1, 5, 11, 21, 36, 56, 88, 97, 100, }; if (i < 0) i = 0; if (i > 8) i = 8; return k[i];",
    }, {
      "name" = "uasocBandHigh",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[9] = { 4, 10, 20, 35, 55, 87, 96, 99, 100, }; if (i < 0) i = 0; if (i > 8) i = 8; return k[i];",
    }, {
      "name" = "uasocBandFullName",
      "comment" = "",
      "kind" = "string array",
      "count" = 9,
      "values" = { "Lower Lower Class", "Middle Lower Class", "Upper Lower Class", "Lower Middle Class", "Middle Middle Class", "Upper Middle Class", "Lower Upper Class", "Middle Upper Class", "Upper Upper Class" },
    }, {
      "name" = "uasocBandAbbr",
      "comment" = "",
      "kind" = "string array",
      "count" = 9,
      "values" = { "LLC", "MLC", "ULC", "LMC", "MMC", "UMC", "LUC", "MUC", "UUC" },
    }, {
      "name" = "uasocRosterCount",
      "comment" = "---- the occupation rosters, per band ----",
      "kind" = "header pin",
      "body" = "static const int k[9] = { 8, 10, 7, 8, 8, 9, 9, 6, 3, }; if (i < 0) i = 0; if (i > 8) i = 8; return k[i];",
    }, {
      "name" = "uasocRosterName",
      "comment" = "",
      "kind" = "string array",
      "count" = 8,
      "values" = { "Freed slaves", "peasants", "tinkers", "vagabonds", "beggars", "criminals", "low-level thieves", "low-level and mid-level assassins", "herdsmen", "laborers", "peddlers", "actors", "jugglers", "men-at-arms", "low-level barbarians", "mid-level thieves", "high-level assassins", "low-level bards", "freemen", "tradesmen", "petty officers", "money-changers", "fences", "low-level fighters", "high-level thieves", "artisans", "craftsmen", "petty merchants", "junior officers", "bankers", "landless knights", "druids", "rangers", "landed gentry", "merchants", "petty officials", "senior officers", "landless petty nobles", "mid-level fighters", "low-level magic-users", "low-level illusionists", "guild masters", "great merchants", "military commanders", "officials", "landless nobles", "lesser clerics", "high-level fighters", "mid-level magic-users", "mid-level illusionists", "great landed gentry", "generals and marshals", "greater officials", "knights", "mid-level clerics", "cavaliers", "paladins", "high-level magic-users", "high-level illusionists", "knights", "commanders", "great clerics", "nobles", "high-level paladins", "very high-level magic-users and illusionists", "great nobles", "sovereign nobility", "royalty" },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uasocBandCount']() != 9  or m['uasocLlcLabelCellGarbled']()  or  m['uasocTableExcludesPoliticalInfo']() != 1  or  m['uasocGuidelinesFollowTheTable']() != 1  or  m['uasocDmModelsToMilieu']() != 1  or  m['uasocPcStartMoneyUnaffected']() != 1  or  m['uasocExceptCavaliersAndPaladins']() != 1  or  m['uasocCavPaladinSeeMoneyHeading']() != 1  or  m['uasocDwarvesMMC']() != 1  or  m['uasocDwarvesGoldGemsReputation']() != 1  or  m['uasocWoodElfULC']() != 1  or  m['uasocGrayElfLUC']() != 1  or  m['uasocGnomeULCToLMC']() != 1  or  m['uasocHalflingULC']() != 1  or m['uasocHalflingParentheticalDivergence']()  or  m['uasocHalfElfSlightlyAboveHuman']() != 1  or  m['uasocHalfOrcLLC']() != 1  or  m['uasocNonHumanPlacementMilieuDependent']() != 1  or  m['uasocProfessionOneRankBelowMinimum']() != 1  or  m['uasocFighterRequiresMlcMinimum']() != 1  or  m['uasocLlcBornOnlyThiefOrAssassin']() != 1",
      "note" = "---- the uasoc pins ----",
    }, {
      "expr" = "m['uabirthRowCount']() != 13  or m['uabirthMarriedLow']() != 1  or m['uabirthMarriedHigh']() != 80  or m['uabirthUnmarriedLow']() != 81  or m['uabirthUnmarriedHigh']() != 100  or  m['uabirthUnmarriedOneClassBelowFather']() != 1  or m['uabirthDwarfMod']() != -15  or m['uabirthElfDrowMod']() != -15  or m['uabirthElfGrayMod']() != -30  or m['uabirthElfHighModMagnitude']() != 20  or m['uabirthElfHighModSignLost']()  or m['uabirthElfWoodMod']() != -10  or m['uabirthElfOtherMod']() != -15  or m['uabirthGnomeMod']() != -20  or m['uabirthHalfElfMod']() != -10  or m['uabirthHalflingMod']() != -10  or m['uabirthHalfOrcBirthMod']() != 10  or m['uabirthHalfOrcMaritalMod']() != 75  or  m['uabirthHumanNoMods']() != 1  or m['uabirthIntroGarbled']()  or  m['uabirthDmDecidesToMilieu']() != 1  or  m['uabirthTablesAStartingPoint']() != 1",
      "note" = "---- the uabirth pins ----",
    }, {
      "expr" = "m['uasocBandLow'](i) != bl[i]  or m['uasocBandHigh'](i) != bh[i]  or i < 8 && bh[i] + 1 != bl[i + 1]  or m['uasocBandCount']() != 9  or strcmp(m['uasocBandAbbr'](0), \"LLC\") != 0  or strcmp(m['uasocBandAbbr'](8), \"UUC\") != 0  or strcmp(m['uasocBandFullName'](4), \"Middle Middle Class\") != 0",
      "note" = "---- the band table ----",
    }, {
      "expr" = "m['uasocRosterCount'](i) != rc[i]  or rsum != 68  or strcmp(m['uasocRosterName'](0, 5), \"criminals\") != 0  or strcmp(m['uasocRosterName'](6, 5), \"cavaliers\") != 0  or strcmp(m['uasocRosterName'](6, 6), \"paladins\") != 0  or strcmp(m['uasocRosterName'](8, 0), \"great nobles\") != 0",
      "note" = "---- the rosters ----",
    }, {
      "expr" = "m['cavMoneyStationCount']() != 6  or strcmp(m['cavMoneyStationName'](3),m['uasocBandFullName'](6)) != 0  or strcmp(m['cavMoneyStationName'](4),m['uasocBandFullName'](7)) != 0  or strcmp(m['cavMoneyStationName'](5),m['uasocBandFullName'](8)) != 0  or strncmp(m['cavMoneyStationName'](0),m['uasocBandFullName'](3), 18) != 0  or  m['cavMoneyPaladinExceptionNoted']() != 1",
      "note" = "---- the R336 seam ----",
    }, {
      "expr" = "m['uabirthRowLow'](i) != wl[i]  or m['uabirthRowHigh'](i) != wh[i]  or i < 12 && wh[i] + 1 != wl[i + 1]  or m['uabirthRowCount']() != 13  or strcmp(m['uabirthOrderLabel'](0), \"Only child\") != 0  or strcmp(m['uabirthOrderLabel'](12), \"12th child\") != 0",
      "note" = "---- the birth table ----",
    } },
  "audit" = {
      "label" = "R367: the UA campaign social class and birth pin audit",
      "comment" = "The UA CAMPAIGN section (pp. 82-83): the SOCIAL CLASS AND RANK - the nine-band dice ladder (LLC 01-04 through UUC 00), the occupation rosters per band (the LLC label cell garbles, flagged), the no-effect-on-starting-money note with the cavalier/paladin exception, the non-human placements (the halfling ULC parenthetical divergence flagged), the one-rank-below profession rule; the CIRCUMSTANCES OF BIRTH - the 13-row birth ladder, the marital status split 01-80/81-00 with the one-class-below-the- father read, the racial modifiers (the high-elf sign cell lost, the half-orc +10/+75 split). The R336 seam cross-checks the cavalier money stations against the band names. Both items flip CLOSED; the census 293 -> 294.",
    },
}
