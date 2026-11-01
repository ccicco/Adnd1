-- oa631: promoted from rules/oaanc.h (the MASTER FAMILY CHART AND ANCESTRY, printed capture pp. 64-65 - the OA);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 631,
  "prefix" = "oa631",
  "banner" = {
      "title" = "MASTER FAMILY CHART AND ANCESTRY, printed capture pp. 64-65 - the OA",
      "provenance" = "ancestry round census 553 -> 554.  pinned from the 2018 print capture alone for this range (the settling authority): the first Mistral-OCR capture session is unavailable above p. 33, so the cross-capture agreement check is impossible. No contested cells detected within the single source: the T39 bands run contiguously 1 through 100 and every honor value sits on its printed row. The T39 result column pins as the 0-34 code (blank 0, roll again 1, criminal 2 through tragic event 34); the die bands pin as lo and hi bounds. OCR normalization: the T39 classic artist reads as the prose classical artist; the T39 roll-again rows 6, 10 and 20 read \"next higher die or + 10\" while row 97 reads \"+ 10 on die roll\" (the printed d100 doctrine - both pin as the roll-again code); Folk Hero capitalized as printed; the Assigning Ancestral Holdings and Birthrights prose (capture pp. 67-69) is deliberately left for the next rounds  the gap census after this round: 71 closed, 164 open - the Master Family Chart, Ancestry prose and Table 39 boxes flip (census 553 -> 554); NEXT - R632: the Assigning Ancestral Holdings prose, capture pp. 67-68, the head-of-family rule and the NPC-only holdings, prefix dgs (verify free), audit \"R632 OA holdings audit\", include after rules/oaanc.h",
    },
  "consts" = { {
      "name" = "dgrT39RowCount",
      "value" = 46,
      "comment" = "Table 39 (capture p. 65): forty-six ancestry rows",
    }, {
      "name" = "dgrAllianceBonusPct",
      "value" = 20,
      "comment" = "Ancestral alliance prose (capture p. 65): the +20 percent reaction modifier between allied families",
    }, {
      "name" = "dgrFeudModPct",
      "value" = -40,
      "comment" = "Ancestral feud prose (capture p. 65): the -40 percent reaction modifier between feud families",
    }, {
      "name" = "dgrAdvMarriageLevels",
      "value" = 3,
      "comment" = "Advantageous marriage prose (capture p. 65): the daughter married 1-3 social levels higher",
    }, {
      "name" = "dgrLandIncomeMin",
      "value" = 10,
      "comment" = "Land prose (capture p. 65): the property income lower bound, 10 ch'ien",
    }, {
      "name" = "dgrLandIncomeMax",
      "value" = 2000,
      "comment" = "Land prose (capture p. 65): the property income upper bound, 2,000 ch'ien",
    }, {
      "name" = "dgrEstateIncomeMin",
      "value" = 100,
      "comment" = "Estate prose (capture p. 65): the estate income lower bound, 100 ch'ien",
    }, {
      "name" = "dgrEstateIncomeMax",
      "value" = 1000,
      "comment" = "Estate prose (capture p. 65): the estate income upper bound, 1,000 ch'ien",
    }, {
      "name" = "dgrFleetShipsMin",
      "value" = 2,
      "comment" = "Merchant fleet prose (capture p. 65): the fleet lower bound, 2 ships",
    }, {
      "name" = "dgrFleetShipsMax",
      "value" = 5,
      "comment" = "Merchant fleet prose (capture p. 65): the fleet upper bound, 5 ships",
    }, {
      "name" = "dgrFleetIncomeMin",
      "value" = 100,
      "comment" = "Merchant fleet prose (capture p. 65): the fleet income lower bound, 100 ch'ien",
    }, {
      "name" = "dgrFleetIncomeMax",
      "value" = 1000,
      "comment" = "Merchant fleet prose (capture p. 65): the fleet income upper bound, 1,000 ch'ien",
    }, {
      "name" = "dgrFolkHeroBonusPct",
      "value" = 10,
      "comment" = "Folk hero prose (capture p. 65): the +10 percent reaction bonus with NPC commoners",
    } },
  "bools" = { {
      "name" = "dgrMasterChartPurpose",
      "value" = true,
      "comment" = "Master chart prose (capture pp. 64-65): the chart records names, birth ranks, honor, alliances and relationships for all families",
    }, {
      "name" = "dgrMasterChartCenter",
      "value" = true,
      "comment" = "Master chart prose (capture pp. 64-65): the emperor or supreme ruler holds the center space",
    }, {
      "name" = "dgrMasterChartRankDistance",
      "value" = true,
      "comment" = "Master chart prose (capture pp. 64-65): the high birth rank families sit closer to the center",
    }, {
      "name" = "dgrMasterChartLineCodes",
      "value" = true,
      "comment" = "Master chart prose (capture pp. 64-65): dashed for marriage, solid for blood, dotted for allies, arrows for enemies",
    }, {
      "name" = "dgrAncestryBeyondAncestors",
      "value" = true,
      "comment" = "Ancestry prose (capture p. 65): the ancestry covers holdings, debts, alliances, feuds and notable deeds",
    }, {
      "name" = "dgrAncestryCooperativeDetail",
      "value" = true,
      "comment" = "Ancestry prose (capture p. 65): the player and the DM supply the names and details together",
    }, {
      "name" = "dgrHonorAddsToBirth",
      "value" = true,
      "comment" = "Ancestry prose (capture p. 65): the Table 39 honor adds to the Character Birth honor for the family base honor",
    }, {
      "name" = "dgrMoneylenderExtraRoll",
      "value" = true,
      "comment" = "Notorious money lender prose (capture p. 65): the character gains an extra roll on Table 40",
    }, {
      "name" = "dgrHereditaryTitlePassesToSon",
      "value" = true,
      "comment" = "Hereditary title prose (capture p. 65): the title passes to the son when the head dies",
    }, {
      "name" = "dgrSecretSocietyContacts",
      "value" = true,
      "comment" = "Secret society prose (capture p. 65): the connection provides the player character contacts inside the society",
    }, {
      "name" = "dgrTragicEventAddsHonor",
      "value" = true,
      "comment" = "Tragic event prose (capture p. 65): the nobility of the ancestor's suffering increases the family honor",
    }, {
      "name" = "dgrRollAgainNextDie",
      "value" = true,
      "comment" = "Roll again prose (capture p. 65): reroll on the next larger die, or add 10 when already rolling d100",
    } },
  "switches" = { {
      "name" = "dgrT39DieLo",
      "values" = { 1, 4, 5, 6, 7, 9, 10, 11, 12, 16, 20, 21, 25, 27, 32, 36, 39, 40, 43, 45, 46, 47, 50, 51, 55, 57, 58, 59, 60, 64, 70, 71, 72, 73, 78, 79, 80, 81, 86, 88, 92, 94, 97, 98, 99, 100 },
      "default" = -99,
      "comment" = "the die-band lower bound column (capture p. 65).",
    }, {
      "name" = "dgrT39DieHi",
      "values" = { 3, 4, 5, 6, 8, 9, 10, 11, 15, 19, 20, 24, 26, 31, 35, 38, 39, 42, 44, 45, 46, 49, 50, 54, 56, 57, 58, 59, 63, 69, 70, 71, 72, 77, 78, 79, 80, 85, 87, 91, 93, 96, 97, 98, 99, 100 },
      "default" = -99,
      "comment" = "the die-band upper bound column - the bands run contiguously 1 through 100 (capture p. 65).",
    }, {
      "name" = "dgrT39Honor",
      "values" = { 0, -15, 0, 0, 2, 2, 0, -10, 3, 6, 0, 0, 6, 3, 2, 0, 6, 8, 10, 7, -10, 0, -10, 6, 7, 9, 1, 8, 0, 0, 10, -20, 15, 0, 12, -5, -7, 0, 4, 2, -5, 7, 0, 0, 3, 0 },
      "default" = -99,
      "comment" = "the honor column: the family honor adjustment, -20 to +15 (capture p. 65).",
    }, {
      "name" = "dgrT39Result",
      "values" = { 0, 2, 3, 1, 4, 5, 1, 6, 7, 8, 1, 0, 9, 10, 11, 0, 12, 13, 14, 15, 16, 0, 17, 18, 19, 20, 21, 22, 0, 0, 23, 24, 25, 0, 26, 27, 28, 0, 29, 30, 31, 32, 1, 33, 34, 0 },
      "default" = -99,
      "comment" = "the ancestry result column, pinned as the 0-34 code: blank 0, roll again 1, criminal 2 through tragic event 34 (capture p. 65).",
    } },
  "tables" = { {
      "name" = "dgrT39Grid",
      "tag" = "T39",
      "count" = "dgrT39RowCount",
      "sentinel" = -99,
      "cols" = { "dgrT39DieLo", "dgrT39DieHi", "dgrT39Honor", "dgrT39Result" },
      "data" = { { 1, 3, 0, 0 }, { 4, 4, -15, 2 }, { 5, 5, 0, 3 }, { 6, 6, 0, 1 }, { 7, 8, 2, 4 }, { 9, 9, 2, 5 }, { 10, 10, 0, 1 }, { 11, 11, -10, 6 }, { 12, 15, 3, 7 }, { 16, 19, 6, 8 }, { 20, 20, 0, 1 }, { 21, 24, 0, 0 }, { 25, 26, 6, 9 }, { 27, 31, 3, 10 }, { 32, 35, 2, 11 }, { 36, 38, 0, 0 }, { 39, 39, 6, 12 }, { 40, 42, 8, 13 }, { 43, 44, 10, 14 }, { 45, 45, 7, 15 }, { 46, 46, -10, 16 }, { 47, 49, 0, 0 }, { 50, 50, -10, 17 }, { 51, 54, 6, 18 }, { 55, 56, 7, 19 }, { 57, 57, 9, 20 }, { 58, 58, 1, 21 }, { 59, 59, 8, 22 }, { 60, 63, 0, 0 }, { 64, 69, 0, 0 }, { 70, 70, 10, 23 }, { 71, 71, -20, 24 }, { 72, 72, 15, 25 }, { 73, 77, 0, 0 }, { 78, 78, 12, 26 }, { 79, 79, -5, 27 }, { 80, 80, -7, 28 }, { 81, 85, 0, 0 }, { 86, 87, 4, 29 }, { 88, 91, 2, 30 }, { 92, 93, -5, 31 }, { 94, 96, 7, 32 }, { 97, 97, 0, 1 }, { 98, 98, 0, 33 }, { 99, 99, 3, 34 }, { 100, 100, 0, 0 } },
      "comment" = "the Table 39 ancestry grid (capture p. 65)",
      "col_comments" = { "the die-band lower bound column (capture p. 65).", "the die-band upper bound column - the bands run contiguously 1 through 100 (capture p. 65).", "the honor column: the family honor adjustment, -20 to +15 (capture p. 65).", "the ancestry result column, pinned as the 0-34 code: blank 0, roll again 1, criminal 2 through tragic event 34 (capture p. 65)." },
      "audit_comment" = "the Table 39 grid: the die bands, the honor column and the coded ancestry results (capture p. 65)",
      "sentinel_census" = { 0, 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgrT39RowCount']() != 46  or m['dgrAllianceBonusPct']() != 20  or m['dgrFeudModPct']() != -40  or m['dgrAdvMarriageLevels']() != 3  or m['dgrLandIncomeMin']() != 10  or m['dgrLandIncomeMax']() != 2000  or m['dgrEstateIncomeMin']() != 100  or m['dgrEstateIncomeMax']() != 1000  or m['dgrFleetShipsMin']() != 2  or m['dgrFleetShipsMax']() != 5  or m['dgrFleetIncomeMin']() != 100  or m['dgrFleetIncomeMax']() != 1000  or m['dgrFolkHeroBonusPct']() != 10  or  m['dgrMasterChartPurpose']() != 1  or  m['dgrMasterChartCenter']() != 1  or  m['dgrMasterChartRankDistance']() != 1  or  m['dgrMasterChartLineCodes']() != 1  or  m['dgrAncestryBeyondAncestors']() != 1  or  m['dgrAncestryCooperativeDetail']() != 1  or  m['dgrHonorAddsToBirth']() != 1  or  m['dgrMoneylenderExtraRoll']() != 1  or  m['dgrHereditaryTitlePassesToSon']() != 1  or  m['dgrSecretSocietyContacts']() != 1  or  m['dgrTragicEventAddsHonor']() != 1  or  m['dgrRollAgainNextDie']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgrT39RowCount']() != 46",
      "note" = "the dgrT39RowCount pin",
    }, {
      "expr" = "m['dgrAllianceBonusPct']() != 20",
      "note" = "the dgrAllianceBonusPct pin",
    }, {
      "expr" = "m['dgrFeudModPct']() != -40",
      "note" = "the dgrFeudModPct pin",
    }, {
      "expr" = "m['dgrAdvMarriageLevels']() != 3",
      "note" = "the dgrAdvMarriageLevels pin",
    }, {
      "expr" = "m['dgrLandIncomeMin']() != 10",
      "note" = "the dgrLandIncomeMin pin",
    }, {
      "expr" = "m['dgrLandIncomeMax']() != 2000",
      "note" = "the dgrLandIncomeMax pin",
    }, {
      "expr" = "m['dgrEstateIncomeMin']() != 100",
      "note" = "the dgrEstateIncomeMin pin",
    }, {
      "expr" = "m['dgrEstateIncomeMax']() != 1000",
      "note" = "the dgrEstateIncomeMax pin",
    }, {
      "expr" = "m['dgrFleetShipsMin']() != 2",
      "note" = "the dgrFleetShipsMin pin",
    }, {
      "expr" = "m['dgrFleetShipsMax']() != 5",
      "note" = "the dgrFleetShipsMax pin",
    }, {
      "expr" = "m['dgrFleetIncomeMin']() != 100",
      "note" = "the dgrFleetIncomeMin pin",
    }, {
      "expr" = "m['dgrFleetIncomeMax']() != 1000",
      "note" = "the dgrFleetIncomeMax pin",
    }, {
      "expr" = "m['dgrFolkHeroBonusPct']() != 10",
      "note" = "the dgrFolkHeroBonusPct pin",
    }, {
      "expr" = "m['dgrMasterChartPurpose']() != 1",
      "note" = "the dgrMasterChartPurpose pin",
    }, {
      "expr" = "m['dgrMasterChartCenter']() != 1",
      "note" = "the dgrMasterChartCenter pin",
    }, {
      "expr" = "m['dgrMasterChartRankDistance']() != 1",
      "note" = "the dgrMasterChartRankDistance pin",
    }, {
      "expr" = "m['dgrMasterChartLineCodes']() != 1",
      "note" = "the dgrMasterChartLineCodes pin",
    }, {
      "expr" = "m['dgrAncestryBeyondAncestors']() != 1",
      "note" = "the dgrAncestryBeyondAncestors pin",
    }, {
      "expr" = "m['dgrAncestryCooperativeDetail']() != 1",
      "note" = "the dgrAncestryCooperativeDetail pin",
    }, {
      "expr" = "m['dgrHonorAddsToBirth']() != 1",
      "note" = "the dgrHonorAddsToBirth pin",
    }, {
      "expr" = "m['dgrMoneylenderExtraRoll']() != 1",
      "note" = "the dgrMoneylenderExtraRoll pin",
    }, {
      "expr" = "m['dgrHereditaryTitlePassesToSon']() != 1",
      "note" = "the dgrHereditaryTitlePassesToSon pin",
    }, {
      "expr" = "m['dgrSecretSocietyContacts']() != 1",
      "note" = "the dgrSecretSocietyContacts pin",
    }, {
      "expr" = "m['dgrTragicEventAddsHonor']() != 1",
      "note" = "the dgrTragicEventAddsHonor pin",
    }, {
      "expr" = "m['dgrRollAgainNextDie']() != 1",
      "note" = "the dgrRollAgainNextDie pin",
    }, {
      "expr" = "m['dgrT39DieLo'](0) != 1  or m['dgrT39DieHi'](0) != 3  or m['dgrT39Honor'](0) != 0  or m['dgrT39Result'](0) != 0",
      "note" = "the T39 first row - the blank 1-3 band (capture p. 65)",
    }, {
      "expr" = "m['dgrT39Honor'](1) != -15  or m['dgrT39Result'](1) != 2",
      "note" = "the T39 criminal cell - the -15 honor at die 4 (capture p. 65)",
    }, {
      "expr" = "m['dgrT39Result'](3) != 1  or m['dgrT39Result'](6) != 1  or m['dgrT39Result'](10) != 1  or m['dgrT39Result'](42) != 1",
      "note" = "the T39 roll-again rows - 6, 10 and 20 with the next-higher-die read, 97 with the d100 add-10 read (capture p. 65)",
    }, {
      "expr" = "m['dgrT39Honor'](31) != -20  or m['dgrT39Honor'](22) != -10",
      "note" = "the T39 dishonor pair - the great betrayal -20 at 71, the defeated family -10 at 50 (capture p. 65)",
    }, {
      "expr" = "m['dgrT39Honor'](32) != 15  or m['dgrT39Result'](32) != 25",
      "note" = "the T39 great hero cell - the +15 honor at die 72 (capture p. 65)",
    }, {
      "expr" = "m['dgrT39Honor'](34) != 12  or m['dgrT39Result'](34) != 26",
      "note" = "the T39 imperial bloodline cell - the +12 honor at die 78 (capture p. 65)",
    }, {
      "expr" = "m['dgrT39Honor'](25) != 9  or m['dgrT39Honor'](26) != 1  or m['dgrT39Honor'](27) != 8",
      "note" = "the T39 famous trio - the general +9, the holy man +1, the minister +8 (capture p. 65)",
    }, {
      "expr" = "m['dgrT39Honor'](44) != 3  or m['dgrT39Result'](44) != 34  or m['dgrT39DieLo'](45) != 100  or m['dgrT39Honor'](45) != 0  or m['dgrT39RowCount']() != 46",
      "note" = "the T39 tragic event capstone - the +3 honor at die 99, the blank at 100, forty-six rows only (capture p. 65)",
    }, {
      "expr" = "m['dgrT39DieLo'](1) -m['dgrT39DieHi'](0) != 1  or m['dgrT39DieLo'](12) -m['dgrT39DieHi'](11) != 1  or m['dgrT39DieLo'](30) -m['dgrT39DieHi'](29) != 1  or m['dgrT39DieLo'](42) -m['dgrT39DieHi'](41) != 1",
      "note" = "the T39 band contiguity - 3 to 4, 24 to 25, 69 to 70, 96 to 97 (capture p. 65)",
    }, {
      "expr" = "m['dgrHonorAddsToBirth']() != 1",
      "note" = "the T39 honor-adds doctrine - the base honor is the Character Birth honor plus the Table 39 honor (capture p. 65)",
    } },
  "audit" = {
      "label" = "R631 OA ancestry audit",
      "comment" = "OA round eighteen (capture pp. 64-65): the master family chart, the ancestry doctrine and the Table 39 grid",
    },
}
