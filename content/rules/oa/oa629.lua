-- oa629: promoted from rules/oabirth.h (the FAMILIES, CLASS, AND CASTE, printed capture pp. 60-62 - the OA Chapter 3);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 629,
  "prefix" = "oa629",
  "banner" = {
      "title" = "FAMILIES, CLASS, AND CASTE, printed capture pp. 60-62 - the OA Chapter 3",
      "provenance" = "opener round census 551 -> 552.  verified against capture pp. 60-62 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). ONE CONTESTED CELL SETTLED AGAINST THE 2018 PRINT BEFORE PINNING: the T38 row-27 ancestry cell d100/8 (the first capture printed d100/9, the second d100/8 - the settled reading stands). The T38 holds seventeen printed rows (the 2d10 bands 2 through 30 - the first preflight run mispinned eighteen and the battery caught bad 14); the T38 rank column pins as the 0-16 code (outcast 0 through the 1st Rank 16); the ancestry and birthright dice pin as die codes (d4=4 through d100=100) with the rolls as the after-slash counts; the T37 requirement columns pin as the 0/1 code. OCR normalization: \"should affect and NPC\" reads as should affect an NPC; \"1 d6\" reads as 1d6; the Table 38 header spans two rows in the second capture (the printed six-column header stands)  the gap census after this round: 67 closed, 168 open - the Birth Rank prose, Table 37 and Table 38 boxes flip (census 551 -> 552); NEXT - R630: the Family Structure and Additional Family Structures prose, capture pp. 62-64, the family chart rows with the honor-by-position doctrine, prefix dgq (verify free), audit \"R630 OA family structures audit\", include after rules/oabirth.h",
    },
  "consts" = { {
      "name" = "dgpT37RowCount",
      "value" = 9,
      "comment" = "Table 37 (capture p. 60): nine class rows",
    }, {
      "name" = "dgpBirthRollDice",
      "value" = 2,
      "comment" = "Birth rank prose (capture p. 61): roll 2d10 for the birth rank",
    }, {
      "name" = "dgpBirthRollSides",
      "value" = 10,
      "comment" = "Birth rank prose (capture p. 61): the 2d10 birth roll dice sides",
    }, {
      "name" = "dgpT38RowCount",
      "value" = 17,
      "comment" = "Table 38 (capture p. 61): seventeen birth rows",
    }, {
      "name" = "dgpNpcExampleDiffPct",
      "value" = 25,
      "comment" = "NPC reaction prose (capture p. 62): the Chang Lui example, the -25 percent modifier",
    }, {
      "name" = "dgpNpcExamplePc",
      "value" = 30,
      "comment" = "NPC reaction prose (capture p. 62): the lower upper class base score in the example",
    }, {
      "name" = "dgpNpcExampleNpc",
      "value" = 55,
      "comment" = "NPC reaction prose (capture p. 62): the 7th Rank base score in the example",
    }, {
      "name" = "dgpFamilyChartRows",
      "value" = 3,
      "comment" = "Family structure prose (capture p. 62): three generational rows on the Family Chart",
    }, {
      "name" = "dgpHeadPosition",
      "value" = 1,
      "comment" = "Family structure prose (capture p. 62): the head of family always occupies position 1",
    }, {
      "name" = "dgpRowSpacesDice",
      "value" = 8,
      "comment" = "Family structure prose (capture p. 62): 1d8 spaces used per row",
    }, {
      "name" = "dgpMaleChancePct",
      "value" = 70,
      "comment" = "Family structure prose (capture p. 62): the 70 percent male chance per space",
    } },
  "bools" = { {
      "name" = "dgpFamilyIncludesAllRelations",
      "value" = true,
      "comment" = "Family prose (capture p. 60): the family or clan means the entire set of relations",
    }, {
      "name" = "dgpAncestorsAddHonor",
      "value" = true,
      "comment" = "Family prose (capture p. 60): ancestors add great honor to a family",
    }, {
      "name" = "dgpClassesMayAdoptProfession",
      "value" = true,
      "comment" = "Family prose (capture p. 60): certain classes adopt the profession as a new family",
    }, {
      "name" = "dgpShukenjaSeversConnections",
      "value" = true,
      "comment" = "Family prose (capture p. 60): a shukenja severs all connections with his past",
    }, {
      "name" = "dgpOptionalFamilyFollowsRules",
      "value" = true,
      "comment" = "Family prose (capture p. 60): an optional family background must abide by the family rules",
    }, {
      "name" = "dgpBirthRankNpcReaction",
      "value" = true,
      "comment" = "Birth rank prose (capture p. 61): the rank modifies NPC reactions where title and respect matter",
    }, {
      "name" = "dgpBirthRankAncestryBirthright",
      "value" = true,
      "comment" = "Birth rank prose (capture p. 61): the rank determines the ancestors and the starting birthright",
    }, {
      "name" = "dgpHonorIsFamilyNotCharacter",
      "value" = true,
      "comment" = "Birth rank prose (capture p. 62): the honor column is gained by the family, not the character",
    }, {
      "name" = "dgpKorobokuruSamuraiNoRoll",
      "value" = true,
      "comment" = "Table 37 prose (capture p. 61): korobokuru samurai do not roll on Table 38",
    }, {
      "name" = "dgpKorobokuruSamuraiLowestRank",
      "value" = true,
      "comment" = "Table 37 prose (capture p. 61): korobokuru samurai take the lowest allowable samurai rank",
    }, {
      "name" = "dgpNinjaAutomaticClan",
      "value" = true,
      "comment" = "Table 37 prose (capture p. 61): a ninja automatically belongs to the Ninja clan",
    }, {
      "name" = "dgpNinjaBirthRankOptional",
      "value" = true,
      "comment" = "Table 37 prose (capture p. 61): the ninja birth rank can still be determined normally",
    }, {
      "name" = "dgpHeadAutoMale",
      "value" = true,
      "comment" = "Family structure prose (capture p. 62): the head, grandfather and father are automatically male",
    }, {
      "name" = "dgpFamilyNameFirst",
      "value" = true,
      "comment" = "Family structure prose (capture p. 62): the family name is written and spoken before the individual name",
    } },
  "switches" = { {
      "name" = "dgpT37Mod",
      "values" = { 10, 0, 0, 0, 0, 0, 0, 0, -10 },
      "default" = -99,
      "comment" = "the modifier column: the samurai +10, the yakuza -10, all others 0 (capture pp. 60-61).",
    }, {
      "name" = "dgpT37BirthReq",
      "values" = { 1, 0, 0, 1, 1, 1, 0, 0, 0 },
      "default" = -99,
      "comment" = "the birth-table-required column, pinned as the 0/1 code (capture pp. 60-61).",
    }, {
      "name" = "dgpT37FamilyReq",
      "values" = { 1, 0, 0, 1, 1, 1, 0, 1, 1 },
      "default" = -99,
      "comment" = "the family-required column, pinned as the 0/1 code (capture pp. 60-61).",
    }, {
      "name" = "dgpT38RankCode",
      "values" = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 },
      "default" = -99,
      "comment" = "the birth rank code column: outcast 0, lower class 1, lower middle 2, middle 3, upper middle 4, lower upper 5, upper 6, then the 10th through 1st ranks as 7-16 (capture p. 61).",
    }, {
      "name" = "dgpT38NpcPct",
      "values" = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 90 },
      "default" = -99,
      "comment" = "the NPC reaction base score column, pinned as the whole percent 5 to 90 (capture p. 61).",
    }, {
      "name" = "dgpT38AncDie",
      "values" = { 6, 4, 6, 10, 20, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 },
      "default" = -99,
      "comment" = "the ancestry die column, pinned as the die code: d4=4, d6=6, d8=8, d10=10, d20=20, d100=100 (capture p. 61).",
    }, {
      "name" = "dgpT38AncRolls",
      "values" = { 1, 2, 2, 1, 2, 2, 4, 5, 6, 7, 7, 7, 8, 8, 9, 9, 10 },
      "default" = -99,
      "comment" = "the ancestry rolls column: the number after the slash - the row-27 cell was contested (the first capture printed 9, the second 8) and settled against the 2018 print as 8 (capture p. 61).",
    }, {
      "name" = "dgpT38BirthDie",
      "values" = { 4, 4, 6, 8, 20, 20, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 },
      "default" = -99,
      "comment" = "the birthright die column, pinned as the die code (capture p. 61).",
    }, {
      "name" = "dgpT38BirthRolls",
      "values" = { 1, 2, 1, 2, 2, 4, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 },
      "default" = -99,
      "comment" = "the birthright rolls column: the number after the slash (capture p. 61).",
    }, {
      "name" = "dgpT38Honor",
      "values" = { 0, 1, 5, 8, 10, 15, 17, 20, 22, 24, 25, 26, 27, 28, 29, 30, 35 },
      "default" = -99,
      "comment" = "the honor column: the family honor 0 to 35 (capture p. 61).",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgpT37RowCount']() != 9  or m['dgpBirthRollDice']() != 2  or m['dgpBirthRollSides']() != 10  or m['dgpT38RowCount']() != 17  or m['dgpNpcExampleDiffPct']() != 25  or m['dgpNpcExamplePc']() != 30  or m['dgpNpcExampleNpc']() != 55  or m['dgpFamilyChartRows']() != 3  or m['dgpHeadPosition']() != 1  or m['dgpRowSpacesDice']() != 8  or m['dgpMaleChancePct']() != 70  or  m['dgpFamilyIncludesAllRelations']() != 1  or  m['dgpAncestorsAddHonor']() != 1  or  m['dgpClassesMayAdoptProfession']() != 1  or  m['dgpShukenjaSeversConnections']() != 1  or  m['dgpOptionalFamilyFollowsRules']() != 1  or  m['dgpKorobokuruSamuraiNoRoll']() != 1  or  m['dgpKorobokuruSamuraiLowestRank']() != 1  or  m['dgpNinjaAutomaticClan']() != 1  or  m['dgpNinjaBirthRankOptional']() != 1  or  m['dgpBirthRankNpcReaction']() != 1  or  m['dgpBirthRankAncestryBirthright']() != 1  or  m['dgpHonorIsFamilyNotCharacter']() != 1  or  m['dgpHeadAutoMale']() != 1  or  m['dgpFamilyNameFirst']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgpT37RowCount']() != 9",
      "note" = "the dgpT37RowCount pin",
    }, {
      "expr" = "m['dgpBirthRollDice']() != 2",
      "note" = "the dgpBirthRollDice pin",
    }, {
      "expr" = "m['dgpBirthRollSides']() != 10",
      "note" = "the dgpBirthRollSides pin",
    }, {
      "expr" = "m['dgpT38RowCount']() != 17",
      "note" = "the dgpT38RowCount pin",
    }, {
      "expr" = "m['dgpNpcExampleDiffPct']() != 25",
      "note" = "the dgpNpcExampleDiffPct pin",
    }, {
      "expr" = "m['dgpNpcExamplePc']() != 30",
      "note" = "the dgpNpcExamplePc pin",
    }, {
      "expr" = "m['dgpNpcExampleNpc']() != 55",
      "note" = "the dgpNpcExampleNpc pin",
    }, {
      "expr" = "m['dgpFamilyChartRows']() != 3",
      "note" = "the dgpFamilyChartRows pin",
    }, {
      "expr" = "m['dgpHeadPosition']() != 1",
      "note" = "the dgpHeadPosition pin",
    }, {
      "expr" = "m['dgpRowSpacesDice']() != 8",
      "note" = "the dgpRowSpacesDice pin",
    }, {
      "expr" = "m['dgpMaleChancePct']() != 70",
      "note" = "the dgpMaleChancePct pin",
    }, {
      "expr" = "m['dgpFamilyIncludesAllRelations']() != 1",
      "note" = "the dgpFamilyIncludesAllRelations pin",
    }, {
      "expr" = "m['dgpAncestorsAddHonor']() != 1",
      "note" = "the dgpAncestorsAddHonor pin",
    }, {
      "expr" = "m['dgpClassesMayAdoptProfession']() != 1",
      "note" = "the dgpClassesMayAdoptProfession pin",
    }, {
      "expr" = "m['dgpShukenjaSeversConnections']() != 1",
      "note" = "the dgpShukenjaSeversConnections pin",
    }, {
      "expr" = "m['dgpOptionalFamilyFollowsRules']() != 1",
      "note" = "the dgpOptionalFamilyFollowsRules pin",
    }, {
      "expr" = "m['dgpKorobokuruSamuraiNoRoll']() != 1",
      "note" = "the dgpKorobokuruSamuraiNoRoll pin",
    }, {
      "expr" = "m['dgpKorobokuruSamuraiLowestRank']() != 1",
      "note" = "the dgpKorobokuruSamuraiLowestRank pin",
    }, {
      "expr" = "m['dgpNinjaAutomaticClan']() != 1",
      "note" = "the dgpNinjaAutomaticClan pin",
    }, {
      "expr" = "m['dgpNinjaBirthRankOptional']() != 1",
      "note" = "the dgpNinjaBirthRankOptional pin",
    }, {
      "expr" = "m['dgpBirthRankNpcReaction']() != 1",
      "note" = "the dgpBirthRankNpcReaction pin",
    }, {
      "expr" = "m['dgpBirthRankAncestryBirthright']() != 1",
      "note" = "the dgpBirthRankAncestryBirthright pin",
    }, {
      "expr" = "m['dgpHonorIsFamilyNotCharacter']() != 1",
      "note" = "the dgpHonorIsFamilyNotCharacter pin",
    }, {
      "expr" = "m['dgpHeadAutoMale']() != 1",
      "note" = "the dgpHeadAutoMale pin",
    }, {
      "expr" = "m['dgpFamilyNameFirst']() != 1",
      "note" = "the dgpFamilyNameFirst pin",
    }, {
      "expr" = "m['dgpT37Mod'](0) != 10  or m['dgpT37BirthReq'](0) != 1  or m['dgpT37FamilyReq'](0) != 1",
      "note" = "the T37 samurai row - the +10 modifier, both requirements (capture pp. 60-61)",
    }, {
      "expr" = "m['dgpT37Mod'](8) != -10  or m['dgpT37BirthReq'](8) != 0  or m['dgpT37FamilyReq'](8) != 1",
      "note" = "the T37 yakuza row - the -10 modifier, no birth roll, family required (capture p. 61)",
    }, {
      "expr" = "m['dgpT37Mod'](7) != 0  or m['dgpT37BirthReq'](7) != 0  or m['dgpT37FamilyReq'](7) != 1",
      "note" = "the T37 ninja row - no modifier, no birth roll, family required (capture p. 61)",
    }, {
      "expr" = "m['dgpT37BirthReq'](1) != 0  or m['dgpT37BirthReq'](2) != 0  or m['dgpT37BirthReq'](6) != 0  or m['dgpT37FamilyReq'](6) != 0",
      "note" = "the T37 middle block - shukenja, sohei and wu jen require neither (capture pp. 60-61)",
    }, {
      "expr" = "m['dgpT38RankCode'](0) != 0  or m['dgpT38NpcPct'](0) != 5  or m['dgpT38AncDie'](0) != 6  or m['dgpT38AncRolls'](0) != 1  or m['dgpT38BirthDie'](0) != 4  or m['dgpT38BirthRolls'](0) != 1  or m['dgpT38Honor'](0) != 0",
      "note" = "the T38 outcast row - 5 percent, d6/1 ancestry, d4/1 birthright, 0 honor (capture p. 61)",
    }, {
      "expr" = "m['dgpT38AncDie'](13) != 100  or m['dgpT38AncRolls'](13) != 8",
      "note" = "the T38 row-3 settled cell - the ancestry d100/8 read against the 2018 print (capture p. 61)",
    }, {
      "expr" = "m['dgpT38RankCode'](16) != 16  or m['dgpT38NpcPct'](16) != 90  or m['dgpT38AncRolls'](16) != 10  or m['dgpT38BirthRolls'](16) != 10  or m['dgpT38Honor'](16) != 35  or m['dgpT38RowCount']() != 17",
      "note" = "the T38 1st Rank capstone - 90 percent, d100/10 both, honor 35, seventeen rows only (capture p. 61)",
    }, {
      "expr" = "m['dgpT38Honor'](0) != 0  or m['dgpT38Honor'](6) != 17  or m['dgpT38Honor'](16) != 35",
      "note" = "the T38 honor ladder - 0 at outcast, 35 at 1st Rank (capture p. 61)",
    }, {
      "expr" = "m['dgpNpcExampleNpc']() -m['dgpNpcExamplePc']() != 25  or m['dgpNpcExampleDiffPct']() != 25",
      "note" = "the T38 reaction example - the 55-minus-30 read for the -25 modifier (capture p. 62)",
    }, {
      "expr" = "m['dgpBirthRollDice']() != 2  or m['dgpBirthRollSides']() != 10",
      "note" = "the birth roll doctrine - 2d10 with the modifier applied (capture p. 61)",
    }, {
      "expr" = "m['dgpRowSpacesDice']() != 8  or m['dgpFamilyChartRows']() != 3  or m['dgpHeadPosition']() != 1",
      "note" = "the family chart doctrine - 1d8 spaces per row, three rows, head at position 1 (capture p. 62)",
    } },
  "audit" = {
      "label" = "R629 OA families audit",
      "comment" = "OA round sixteen (capture pp. 60-62): the Chapter 3 opener - the family doctrine, the birth rank prose and the Tables 37 and 38 grids",
    },
}
