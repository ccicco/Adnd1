-- oa644: promoted from rules/oapiece.h (the TABLE 53 (INDIVIDUAL PIECE ARMOR CLASS), printed capture p. 95 - the OA);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 644,
  "prefix" = "oa644",
  "banner" = {
      "title" = "TABLE 53 (INDIVIDUAL PIECE ARMOR CLASS), printed capture p. 95 - the OA",
      "provenance" = "piece armor round census 566 -> 567.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read of the page - the nine-row grid cross-checked cell-by-cell between the two passes; the steps agree (2 for do-maru, hara-ate and haramaki-do, 1 elsewhere), the star set agrees (the hara-ate and hara-ate-gawa pair), and the backside footnote text agrees verbatim - zero contested cells. The definitional sentence under the table pins the steps semantics: the amount of improvement from AC 10 the piece provides; the page worked examples cross-check the arithmetic (kote alone AC 9; kote, do-maru and haidate AC 6). The backside star note pins as a bool (the starred pieces do not cover the backside at all - attacks from behind are treated as against armor class 10). The piece names are textual and ride the column comment per the T48 doctrine (the hyphenated spellings as printed). The one-piece-per-area rule, the pieces-not-with-suits rule and the o-yoroi full-suit note stay in the open armor prose box; Table 54 (capture p. 95) is deliberately left for the next round  the gap census after this round: 95 closed, 140 open - the Table 53 box flips (census 566 -> 567); NEXT - R645: Table 54 (Types of Armor & Encumbrance), capture p. 95, the armor bulk/weight/movement grid, prefix dhf (verify free), audit \"R645 OA encumbrance audit\", include after rules/oapiece.h",
    },
  "consts" = { {
      "name" = "dheT53RowCount",
      "value" = 9,
      "comment" = "Table 53 (capture p. 95): nine laced-armor piece rows",
    }, {
      "name" = "dheT53AcBase",
      "value" = 10,
      "comment" = "the definitional sentence under Table 53: the steps measure the amount of improvement from armor class 10 the piece provides (capture p. 95)",
    } },
  "bools" = { {
      "name" = "dheT53StarBacksideNote",
      "value" = true,
      "comment" = "the star note under Table 53: the starred pieces do not cover the backside at all - attacks from behind are treated as against armor class 10 (capture p. 95)",
    } },
  "switches" = { {
      "name" = "dheT53Steps",
      "values" = { 2, 1, 2, 1, 1, 2, 1, 1, 1 },
      "default" = -99,
      "comment" = "the armor class steps, by piece row (capture p. 95). The armor piece names ride this comment: 0 Do-maru, 1 Haidate, 2 Hara-ate, 3 Hara-ate-gawa, 4 Haramaki, 5 Haramaki-do, 6 Kote, 7 Sode, 8 Suneate - the spellings as printed, the hara-ate pair carrying the star; a row index outside the table returns the -99 sentinel (capture p. 95).",
    }, {
      "name" = "dheT53Star",
      "values" = { 0, 0, 1, 1, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "the star footnote markers: the hara-ate and hara-ate-gawa rows carry the star (the pieces that do not cover the backside), 0 elsewhere (capture p. 95).",
    } },
  "tables" = { {
      "name" = "dheT53Grid",
      "tag" = "T53Data",
      "count" = "dheT53RowCount",
      "sentinel" = -99,
      "cols" = { "dheT53Steps", "dheT53Star" },
      "comment" = "the Table 53 individual piece armor class grid (capture p. 95)",
      "col_comments" = { "the armor class steps, by piece row (capture p. 95). The armor piece names ride this comment: 0 Do-maru, 1 Haidate, 2 Hara-ate, 3 Hara-ate-gawa, 4 Haramaki, 5 Haramaki-do, 6 Kote, 7 Sode, 8 Suneate - the spellings as printed, the hara-ate pair carrying the star; a row index outside the table returns the -99 sentinel (capture p. 95).", "the star footnote markers: the hara-ate and hara-ate-gawa rows carry the star (the pieces that do not cover the backside), 0 elsewhere (capture p. 95)." },
      "audit_comment" = "the Table 53 grid: the piece armor class steps and the star set",
      "data" = { { 2, 0 }, { 1, 0 }, { 2, 1 }, { 1, 1 }, { 1, 0 }, { 2, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 } },
      "sentinel_census" = { 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dheT53RowCount']() != 9  or m['dheT53AcBase']() != 10  or  m['dheT53StarBacksideNote']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dheT53RowCount']() != 9",
      "note" = "the T53 row count pin",
    }, {
      "expr" = "m['dheT53AcBase']() != 10",
      "note" = "the AC-10 base pin",
    }, {
      "expr" = "m['dheT53StarBacksideNote']() != 1",
      "note" = "the backside star note pin",
    }, {
      "expr" = "m['dheT53Steps'](0) != 2",
      "note" = "the do-maru row - the 2-step chest piece (capture p. 95)",
    }, {
      "expr" = "m['dheT53Steps'](2) != 2  or m['dheT53Star'](2) != 1",
      "note" = "the hara-ate row - the 2 steps with the star, the backside pair (capture p. 95)",
    }, {
      "expr" = "m['dheT53Steps'](3) != 1  or m['dheT53Star'](3) != 1",
      "note" = "the hara-ate-gawa row - the 1 step with the star, the backside pair (capture p. 95)",
    }, {
      "expr" = "m['dheT53Steps'](5) != 2",
      "note" = "the haramaki-do row - the 2-step do variant (capture p. 95)",
    }, {
      "expr" = "m['dheT53Steps'](6) != 1  or m['dheT53AcBase']() -m['dheT53Steps'](6) != 9",
      "note" = "the kote row - the 1 step; the page worked example: kote alone gives AC 9 from the AC-10 base (capture p. 95)",
    }, {
      "expr" = "m['dheT53Steps'](0) +m['dheT53Steps'](1) +m['dheT53Steps'](6) != 4",
      "note" = "the worked example sum - kote, do-maru and haidate give 4 steps, AC 6 from the base (capture p. 95)",
    }, {
      "expr" = "m['dheT53Steps'](8) != 1  or m['dheT53Star'](8) != 0  or m['dheT53Star'](0) != 0",
      "note" = "the suneate tail row - the 1 step, no star; the star column is zero off the backside pair (capture p. 95)",
    } },
  "audit" = {
      "label" = "R644 OA piece armor audit",
      "comment" = "OA round thirty-one (capture p. 95): the Table 53 individual piece armor class - the laced-armor piece steps and the backside star note",
    },
}
