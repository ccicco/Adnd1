-- oa643: promoted from rules/oaarmor.h (the TABLE 52 (ARMOR CLASS TABLE), printed capture p. 94 - the OA armor round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 643,
  "prefix" = "oa643",
  "banner" = {
      "title" = "TABLE 52 (ARMOR CLASS TABLE), printed capture p. 94 - the OA armor round",
      "provenance" = "census 565 -> 566.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read of the page - the eight-row table cross-checked cell-by-cell between the two passes; the numeric rating ladder agrees in both passes (10 through 3, one step per row, no contested cells). The one contest is a name, not a number: the AC-4 row third type reads branded mail in the print pass against the compressed banded mail - the print capture own page prose prints banded mail twice in the rare-suits sentence, so the row read is an OCR slip and the name pins as banded mail (a read contradicting its own page does not stand). The type-of-armor names are textual and ride the column comment per the T48 doctrine (the kote and o-yori spellings as printed; the suit rows enumerate multiple types per rating). The corselet-of-laced-armor prose example (armor class 7, equal to studded leather) cross-checks the row-3 rating - the prose itself stays in the open armor prose box. The suits-versus-pieces doctrine and the averaging paragraph stay open; Table 53 (capture p. 95) is deliberately left for the next round  the gap census after this round: 94 closed, 141 open - the Table 52 box flips (census 565 -> 566); NEXT - R644: Table 53 (Individual Piece Armor Class), capture p. 95, the laced-armor piece class steps, prefix dhe (verify free), audit \"R644 OA piece armor audit\", include after rules/oaarmor.h",
    },
  "consts" = { {
      "name" = "dhdT52RowCount",
      "value" = 8,
      "comment" = "Table 52 (capture p. 94): eight suit armor rows",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dhdT52Ac",
      "values" = { 10, 9, 8, 7, 6, 5, 4, 3 },
      "default" = -99,
      "comment" = "the armor class rating, by suit row (capture p. 94). The type-of-armor names ride this comment: 0 None, 1 Shield/kote, 2 Leather or padded armor, 3 Leather, padded armor, & shield/studded leather/leather scale/ring mail, 4 Studded leather, ring mail, leather scale & shield/hide/metal scale/brigandine, 5 Hide, metal scale, brigandine & shield/chain mail, 6 Chain mail & shield/splint mail/banded mail, 7 Splint or banded mail & shield/o-yori - the ratings run 10 through 3, one step per row; the row-6 third type pins as banded mail (the print pass branded read is an OCR slip against its own page prose); a row index outside the table returns the -99 sentinel (capture p. 94).",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhdT52RowCount']() != 8",
      "note" = "",
    }, {
      "expr" = "m['dhdT52RowCount']() != 8",
      "note" = "the T52 row count pin",
    }, {
      "expr" = "m['dhdT52Ac'](0) != 10",
      "note" = "the unarmored rating pin",
    }, {
      "expr" = "m['dhdT52Ac'](7) != 3",
      "note" = "the best suit rating pin",
    }, {
      "expr" = "m['dhdT52Ac'](0) != 10",
      "note" = "the None row - the unarmored rating 10 (capture p. 94)",
    }, {
      "expr" = "m['dhdT52Ac'](1) != 9",
      "note" = "the shield/kote row - the shield-alone rating 9, the kote spelling as printed (capture p. 94)",
    }, {
      "expr" = "m['dhdT52Ac'](3) != 7",
      "note" = "the studded-leather row - the rating 7, the corselet-equality cross-check from the page prose (capture p. 94)",
    }, {
      "expr" = "m['dhdT52Ac'](5) != 5  or m['dhdT52Ac'](6) != 4",
      "note" = "the hide and chain-mail rows - the ratings 5 and 4, the chain-mail row third type settling as banded mail (capture p. 94)",
    }, {
      "expr" = "m['dhdT52Ac'](7) != 3",
      "note" = "the o-yori tail row - the best suit rating 3 (capture p. 94)",
    }, {
      "expr" = "m['dhdT52Ac'](2) != 8  or m['dhdT52Ac'](4) != 6",
      "note" = "the ladder - one step per row from 10 through 3, no gaps (capture p. 94)",
    } },
  "audit" = {
      "label" = "R643 OA armor audit",
      "comment" = "OA round thirty (capture p. 94): the Table 52 armor class table - the suit armor class ratings",
    },
}
