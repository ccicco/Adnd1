-- ivs: promoted from tools/spec_r887.json (the The Ives attribute tables - the Dragon Magazine walk opens at issue #1 folio 7: the Wesley D. Ives non-prime-requisite adjudication system, the arc's first variant-layer pin);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 887,
  "prefix" = "ivs",
  "banner" = {
      "title" = "The Ives attribute tables - the Dragon Magazine walk opens at issue #1 folio 7: the Wesley D. Ives non-prime-requisite adjudication system, the arc's first variant-layer pin",
      "provenance" = "Pinned from The Dragon Vol. 1 No. 1 (June 1976), folio 7, by Wesley D. Ives; the voice is the chat-side OCR transcript at extract/dragon/001/p007_full.txt (all 32 issue pages and the pre-flip dragon gap report ride this round as data files). OD&D-era ink converted per the walk doctrine: the pin IS the conversion, provenance noted, never silent.",
      "sentinel" = "The variant-layer doctrine: Dragon ink is never core 1e canon - the marks here are 0/1 use flags and band indices, distinct from every core print value; the honest boundaries (the 18-super-90 glyph, the fighters-only ladder) ride the audit comment and the gap report.",
    },
  "consts" = { {
      "name" = "ivsRollMin",
      "value" = 1,
      "comment" = "the d100 floor - generate 1-100, always add the tested score",
    }, {
      "name" = "ivsRollMax",
      "value" = 100,
      "comment" = "the d100 ceiling (the score-added total may exceed it - the band chain tails)",
    }, {
      "name" = "ivsUseCount",
      "value" = 6,
      "comment" = "the use grid rows - STR INT WIS CON DEX CHA",
    } },
  "bools" = { {
      "name" = "ivsScoreAddedToRoll",
      "value" = true,
      "comment" = "the adjusted total (the d100 roll plus the score in question) selects the die band",
    }, {
      "name" = "ivsPercentIsRollTimesScore",
      "value" = true,
      "comment" = "the success chance is the band die roll times the tested score, read as a percent",
    }, {
      "name" = "ivsLadderIsFightersExStr",
      "value" = true,
      "comment" = "the extraordinary-strength ladder serves fighters only (the Grod doctrine)",
    } },
  "switches" = { {
      "name" = "ivsDieSides",
      "values" = { 4, 6, 8, 10, 12 },
      "default" = 12,
      "comment" = "the band die - band 0 the d4, band 1 the d6, band 2 the d8, band 3 the d10, band 4 the d12",
    }, {
      "name" = "ivsLadderStr",
      "values" = { 18, 19, 20, 21, 22, 23, 24, 25, 27 },
      "default" = 27,
      "comment" = "the ladder's effective strengths - 18/01-18/20 reads 18 through 18/91-18/99 reads 25, 18/00 reads 27 (the ink's 18-super-90 glyph, pinned as scanned)",
    } },
  "tables" = { {
      "name" = "ivsUses",
      "tag" = "IvsUses",
      "count" = "ivsUseCount",
      "sentinel" = 0,
      "cols" = { "ivsUseExertion", "ivsUseDevice", "ivsUseStamina", "ivsUseManipulation", "ivsUsePersuasion", "ivsUseLearning" },
      "col_comments" = { "the use grid, strength - any extraordinary physical exertion", "the use grid, devices - INT operation, WIS function recognition, DEX manual manipulation", "the use grid, constitution stamina - swimming, running, staying awake, going hungry", "the use grid, dexterity hands - manipulation, balance and climbing, tying and untying knots", "the use grid, charisma - believability, persuasiveness, the morale of followers", "the use grid, intelligence learning - patterns, cause and effect, lair types, languages and skills" },
      "data" = { { 1, 0, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0, 1 }, { 0, 1, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0 }, { 0, 1, 0, 1, 0, 0 }, { 0, 0, 0, 0, 1, 0 } },
      "audit_comment" = "the Ives use grid - six attributes x six use flags, pinned from the folio 7 use lists",
    } },
  "chains" = { {
      "name" = "ivsDieBand",
      "arg" = "total",
      "limits" = { 20, 40, 60, 80 },
      "tail" = 4,
      "comment" = "the die band - the adjusted total picks the band: 1-20 band 0, 21-40 band 1, 41-60 band 2, 61-80 band 3, 81 and up band 4",
    }, {
      "name" = "ivsExStrLadder",
      "arg" = "pct",
      "limits" = { 20, 40, 60, 70, 80, 90, 95, 99 },
      "tail" = 8,
      "comment" = "the extraordinary-strength ladder band - the 18/xx percentile picks the band: 1-20 band 0 through 96-99 band 7, 18/00 (100) band 8",
    } },
  "examples" = { {
      "expr" = "m['ivsDieSides'](m['ivsDieBand'](54)) != 8",
      "note" = "the Grod charisma band - the 42 roll plus the 12 score lands 54, the d8 band",
    }, {
      "expr" = "m['ivsDieSides'](m['ivsDieBand'](83)) != 12",
      "note" = "the Grod strength band - the 66 roll plus the 17 score lands 83, the d12 band",
    }, {
      "expr" = "7 * 12 != 84",
      "note" = "the charisma percent - the 7 die roll times the 12 score reads 84 percent",
    }, {
      "expr" = "3 * 17 != 51",
      "note" = "the strength percent - the 3 die roll times the 17 score reads 51 percent",
    }, {
      "expr" = "m['ivsDieSides'](m['ivsDieBand'](20)) != 4 or m['ivsDieSides'](m['ivsDieBand'](125)) != 12",
      "note" = "the band edges - the 20 floor reads the d4, the 125 score-added tail reads the d12",
    }, {
      "expr" = "m['ivsLadderStr'](m['ivsExStrLadder'](87)) != 23",
      "note" = "the 18/87 fighter - the ladder reads effective strength 23 for the boulder",
    }, {
      "expr" = "m['ivsLadderStr'](m['ivsExStrLadder'](20)) != 18 or m['ivsLadderStr'](m['ivsExStrLadder'](21)) != 19",
      "note" = "the ladder floor - 18/20 reads 18, 18/21 reads 19",
    }, {
      "expr" = "m['ivsLadderStr'](m['ivsExStrLadder'](100)) != 27",
      "note" = "the 18/00 top - the ink's 18-super-90 glyph prints 27, pinned as scanned",
    }, {
      "expr" = "m['ivsUseExertion'](0) != 1 or m['ivsUseStamina'](3) != 1 or m['ivsUsePersuasion'](5) != 1",
      "note" = "the use grid rows - STR exertion, CON stamina, CHA persuasion",
    }, {
      "expr" = "m['ivsUseDevice'](1) != 1 or m['ivsUseDevice'](2) != 1 or m['ivsUseDevice'](4) != 1",
      "note" = "the device column - INT operation, WIS recognition, DEX manipulation",
    }, {
      "expr" = "m['ivsUseLearning'](1) != 1 or m['ivsUseManipulation'](4) != 1",
      "note" = "the learning and hands columns - INT learning, DEX manipulation",
    } },
  "audit" = {
      "label" = "R887 Ives attribute audit",
      "comment" = "THE IVES ATTRIBUTE TABLES - the Dragon Magazine walk opens at issue #1, folio 7: generate 1-100, add the tested score, the total's band picks the die (d4 through d12), the die roll times the score is the percent chance of success. The fighters' exceptional-strength ladder converts 18/01 through 18/00 to effective strength 18 through 27 (the ink's 18-super-90 glyph reading 27 - the erratum pinned as scanned); the ladder serves fighters only. The use grid pins the six-attribute doctrine lists. HONEST BOUNDARIES: this is OD&D-era variant ink on a VARIANT layer with provenance, never core 1e canon; the article standardizes the referee's wings-it doctrine - 1e has only the enumerated attribute mechanics (the engine holds them: systemShock, resurrectionSurvival, the conduct tables), no general attribute-check layer exists at core; the example rolls (the 7 and the 3) pin as doctrine examples, the random rolls themselves unpinnable. The 32 voice pages and the pre-flip dragon gap report ride as data files; the Ives box flips at the next Dragon round (a report cannot flip in the round that creates it).",
    },
}
