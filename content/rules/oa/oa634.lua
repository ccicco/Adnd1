-- oa634: promoted from rules/oahonor.h (the THE HONOR OPENER AND TABLE 41, printed capture pp. 69-70 - the OA honor);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 634,
  "prefix" = "oa634",
  "banner" = {
      "title" = "THE HONOR OPENER AND TABLE 41, printed capture pp. 69-70 - the OA honor",
      "provenance" = "round census 556 -> 557.  pinned from the 2018 print capture alone for this range (the settling authority): the first Mistral-OCR capture session is unavailable above p. 33, so the cross-capture agreement check is impossible. No contested cells detected within the single source: the T41 rows are five fixed base honors plus the single die-roll row (the yakuza 1d20 + 20 read pins as the 21-40 bounds; the class row order pins as the 0-6 code: shukenja, sohei, kensai, bushi, hengeyokai, wu jen, yakuza). The T41 base-honor column pins as the lo and hi bounds. OCR normalization: none required for this range beyond the yakuza die read - the honor opener prose carries the printed em dashes. The Altering Family Honor and Effects of Honor prose and Table 42 (capture pp. 70-72) are deliberately left for the next rounds  the gap census after this round: 76 closed, 159 open - the Gaining and Losing Honor prose and Table 41 boxes flip (census 556 -> 557); NEXT - R635: the Altering Family Honor prose and the Effects of Honor prose with Table 42, capture pp. 70-72, the family ledger and the reaction doctrine, prefix dgv (verify free), audit \"R635 OA effects of honor audit\", include after rules/oahonor.h",
    },
  "consts" = { {
      "name" = "dguT41RowCount",
      "value" = 7,
      "comment" = "Table 41 (capture p. 70): seven initial-honor rows",
    }, {
      "name" = "dguHonorMax",
      "value" = 100,
      "comment" = "Gaining and losing prose (capture p. 70): no character can have more than 100 points of honor",
    } },
  "bools" = { {
      "name" = "dguHonorReflectsFamily",
      "value" = true,
      "comment" = "Honor opener prose (capture pp. 69-70): honor reflects the character and the character of his family - the family affects the character and vice versa",
    }, {
      "name" = "dguHonorBringsRespect",
      "value" = true,
      "comment" = "Honor opener prose (capture pp. 69-70): with honor comes respect, power, influence and position; without it, disrespect, humiliation and insults",
    }, {
      "name" = "dguHonorEasierToLose",
      "value" = true,
      "comment" = "Honor opener prose (capture pp. 69-70): honor is easier to lose than to gain",
    }, {
      "name" = "dguDishonorDeeds",
      "value" = true,
      "comment" = "Honor opener prose (capture pp. 69-70): breaking faith, treachery, cowardice and unavenged insults cause a loss of honor",
    }, {
      "name" = "dguHonorDeeds",
      "value" = true,
      "comment" = "Honor opener prose (capture pp. 69-70): valiant deeds, self-sacrifice, mastery of skills and keeping faith earn honor",
    }, {
      "name" = "dguHonorImprovesReactions",
      "value" = true,
      "comment" = "Honor opener prose (capture pp. 69-70): gaining honor brings better encounter reactions, gifts and better replacement characters",
    }, {
      "name" = "dguHonorNotAlignment",
      "value" = true,
      "comment" = "Honor opener prose (capture pp. 69-70): oriental honor is not a judgment of good and evil - a cruel villain can hold high honor and a heroic samurai low honor",
    }, {
      "name" = "dguHonorDeedsBoth",
      "value" = true,
      "comment" = "Honor opener prose (capture pp. 69-70): honor measures the deeds of the character and the family clan - obedience, loyalty, talent and success, regardless of alignment",
    }, {
      "name" = "dguHonorPointsTracked",
      "value" = true,
      "comment" = "Honor points prose (capture pp. 69-70): players record honor points - the DM gives them at the end of an adventure or major encounter and takes them away for dishonorable actions",
    }, {
      "name" = "dguNotEveryAdventure",
      "value" = true,
      "comment" = "Honor points prose (capture pp. 69-70): characters do not earn honor points for every adventure - they must do something special",
    }, {
      "name" = "dguClanStartByBirthRank",
      "value" = true,
      "comment" = "Starting honor prose (capture p. 70): family-clan characters start with the base honor determined by birth rank, adjusted by the Table 39 results - the family honor",
    }, {
      "name" = "dguFamilyHonorFloorZero",
      "value" = true,
      "comment" = "Starting honor prose (capture p. 70): a negative family honor is raised to 0",
    }, {
      "name" = "dguClanStartAddsBirthrights",
      "value" = true,
      "comment" = "Starting honor prose (capture p. 70): the starting honor is the family honor plus the birthright bonuses plus the character's lowest ability score",
    }, {
      "name" = "dguNoClanT41Base",
      "value" = true,
      "comment" = "Starting honor prose (capture p. 70): characters without family clans take the Table 41 base honor by class or race, plus the lowest ability score",
    }, {
      "name" = "dguClassSensitivity",
      "value" = true,
      "comment" = "Gaining and losing prose (capture p. 70): classes gain and lose honor at different rates - a samurai's honor fluctuates more than a wu jen's or shukenja's",
    }, {
      "name" = "dguDmAwardsHonor",
      "value" = true,
      "comment" = "Gaining and losing prose (capture p. 70): honor points are always awarded by the DM, normally at the end of an adventure; the DM's judgment is final; the typical awards are listed on Table 42",
    }, {
      "name" = "dguDmJudgment",
      "value" = true,
      "comment" = "Gaining and losing prose (capture p. 70): the list cannot cover every situation - the DM relies on his judgment using the table as a guideline",
    } },
  "switches" = { {
      "name" = "dguT41BaseLo",
      "values" = { 20, 15, 25, 10, 10, 15, 21 },
      "default" = -99,
      "comment" = "the initial-honor lower bound column, by class row - 0 shukenja, 1 sohei, 2 kensai, 3 bushi, 4 hengeyokai, 5 wu jen, 6 yakuza (capture p. 70).",
    }, {
      "name" = "dguT41BaseHi",
      "values" = { 20, 15, 25, 10, 10, 15, 40 },
      "default" = -99,
      "comment" = "the initial-honor upper bound column - the fixed rows pin lo equal to hi; the yakuza row reads 1d20 + 20, pinning as 21 through 40 (capture p. 70).",
    } },
  "tables" = { {
      "name" = "dguT41Grid",
      "tag" = "T41",
      "count" = "dguT41RowCount",
      "sentinel" = -99,
      "cols" = { "dguT41BaseLo", "dguT41BaseHi" },
      "data" = { { 20, 20 }, { 15, 15 }, { 25, 25 }, { 10, 10 }, { 10, 10 }, { 15, 15 }, { 21, 40 } },
      "comment" = "the Table 41 initial honor grid (capture p. 70)",
      "col_comments" = { "the initial-honor lower bound column, by class row - 0 shukenja, 1 sohei, 2 kensai, 3 bushi, 4 hengeyokai, 5 wu jen, 6 yakuza (capture p. 70).", "the initial-honor upper bound column - the fixed rows pin lo equal to hi; the yakuza row reads 1d20 + 20, pinning as 21 through 40 (capture p. 70)." },
      "audit_comment" = "the Table 41 grid: the class base-honor bounds (capture p. 70)",
      "sentinel_census" = { 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dguT41RowCount']() != 7  or m['dguHonorMax']() != 100  or  m['dguHonorReflectsFamily']() != 1  or  m['dguHonorBringsRespect']() != 1  or  m['dguHonorEasierToLose']() != 1  or  m['dguDishonorDeeds']() != 1  or  m['dguHonorDeeds']() != 1  or  m['dguHonorImprovesReactions']() != 1  or  m['dguHonorNotAlignment']() != 1  or  m['dguHonorDeedsBoth']() != 1  or  m['dguHonorPointsTracked']() != 1  or  m['dguNotEveryAdventure']() != 1  or  m['dguClanStartByBirthRank']() != 1  or  m['dguFamilyHonorFloorZero']() != 1  or  m['dguClanStartAddsBirthrights']() != 1  or  m['dguNoClanT41Base']() != 1  or  m['dguClassSensitivity']() != 1  or  m['dguDmAwardsHonor']() != 1  or  m['dguDmJudgment']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dguT41RowCount']() != 7",
      "note" = "the dguT41RowCount pin",
    }, {
      "expr" = "m['dguHonorMax']() != 100",
      "note" = "the dguHonorMax pin",
    }, {
      "expr" = "m['dguHonorReflectsFamily']() != 1",
      "note" = "the dguHonorReflectsFamily pin",
    }, {
      "expr" = "m['dguHonorBringsRespect']() != 1",
      "note" = "the dguHonorBringsRespect pin",
    }, {
      "expr" = "m['dguHonorEasierToLose']() != 1",
      "note" = "the dguHonorEasierToLose pin",
    }, {
      "expr" = "m['dguDishonorDeeds']() != 1",
      "note" = "the dguDishonorDeeds pin",
    }, {
      "expr" = "m['dguHonorDeeds']() != 1",
      "note" = "the dguHonorDeeds pin",
    }, {
      "expr" = "m['dguHonorImprovesReactions']() != 1",
      "note" = "the dguHonorImprovesReactions pin",
    }, {
      "expr" = "m['dguHonorNotAlignment']() != 1",
      "note" = "the dguHonorNotAlignment pin",
    }, {
      "expr" = "m['dguHonorDeedsBoth']() != 1",
      "note" = "the dguHonorDeedsBoth pin",
    }, {
      "expr" = "m['dguHonorPointsTracked']() != 1",
      "note" = "the dguHonorPointsTracked pin",
    }, {
      "expr" = "m['dguNotEveryAdventure']() != 1",
      "note" = "the dguNotEveryAdventure pin",
    }, {
      "expr" = "m['dguClanStartByBirthRank']() != 1",
      "note" = "the dguClanStartByBirthRank pin",
    }, {
      "expr" = "m['dguFamilyHonorFloorZero']() != 1",
      "note" = "the dguFamilyHonorFloorZero pin",
    }, {
      "expr" = "m['dguClanStartAddsBirthrights']() != 1",
      "note" = "the dguClanStartAddsBirthrights pin",
    }, {
      "expr" = "m['dguNoClanT41Base']() != 1",
      "note" = "the dguNoClanT41Base pin",
    }, {
      "expr" = "m['dguClassSensitivity']() != 1",
      "note" = "the dguClassSensitivity pin",
    }, {
      "expr" = "m['dguDmAwardsHonor']() != 1",
      "note" = "the dguDmAwardsHonor pin",
    }, {
      "expr" = "m['dguDmJudgment']() != 1",
      "note" = "the dguDmJudgment pin",
    }, {
      "expr" = "m['dguT41BaseLo'](0) != 20  or m['dguT41BaseHi'](0) != 20  or m['dguT41BaseLo'](2) != 25  or m['dguT41BaseHi'](2) != 25",
      "note" = "the T41 shukenja and kensai rows - the 20 and 25 bases (capture p. 70)",
    }, {
      "expr" = "m['dguT41BaseLo'](1) != 15  or m['dguT41BaseHi'](1) != 15  or m['dguT41BaseLo'](5) != 15  or m['dguT41BaseHi'](5) != 15",
      "note" = "the T41 sohei and wu jen rows - the 15 bases (capture p. 70)",
    }, {
      "expr" = "m['dguT41BaseLo'](3) != 10  or m['dguT41BaseHi'](3) != 10  or m['dguT41BaseLo'](4) != 10  or m['dguT41BaseHi'](4) != 10",
      "note" = "the T41 bushi and hengeyokai rows - the 10 bases (capture p. 70)",
    }, {
      "expr" = "m['dguT41BaseLo'](6) != 21  or m['dguT41BaseHi'](6) != 40",
      "note" = "the T41 yakuza row - the 1d20 + 20 read pinned as 21 through 40 (capture p. 70)",
    }, {
      "expr" = "m['dguT41RowCount']() != 7",
      "note" = "the T41 row count - seven rows only (capture p. 70)",
    }, {
      "expr" = "m['dguHonorMax']() != 100",
      "note" = "the honor cap - no character above 100 points (capture p. 70)",
    }, {
      "expr" = "m['dguClanStartByBirthRank']() != 1  or m['dguFamilyHonorFloorZero']() != 1  or m['dguClanStartAddsBirthrights']() != 1  or m['dguNoClanT41Base']() != 1",
      "note" = "the starting honor doctrine - the birth-rank base with the T39 adjustments, the 0 floor, the birthright and lowest-ability adds, the no-clan route (capture p. 70)",
    } },
  "audit" = {
      "label" = "R634 OA honor audit",
      "comment" = "OA round twenty-one (capture pp. 69-70): the honor opener prose, the starting honor doctrine and the Table 41 grid",
    },
}
