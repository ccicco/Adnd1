-- oa646: promoted from rules/oa/oabarding.h (the TABLE 55 (BARDED WARHORSE BASE MOVEMENT RATES), printed capture p. 98 - the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 646,
  "prefix" = "oa646",
  "banner" = {
      "title" = "TABLE 55 (BARDED WARHORSE BASE MOVEMENT RATES), printed capture p. 98 - the",
      "provenance" = "OA barding round census 568 -> 569.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read of the page - the 4-row grid cross-checked cell-by-cell between the two passes; the movement pairs agree in both passes - zero numeric contested cells. The artifacts are glyph and word class: the movement prints with the prime glyph (feet) in the print capture against the compressed double-prime (the R645 class, the feet read stands, the numeric columns strip the unit) and the light-horse metal-scale pair prints 15 with a stray space before the prime in the print pass (an OCR cell artifact, the value stands). The note under the table reads Tumber before the slash in BOTH passes - an OCR slip for The number, noted; the note doctrine pins as two bools: the number before the slash is for full barding, the number after for half-barding, and an X indicates the barding is heavier than the horse can bear. The light-horse chain full cell prints X and the elephant metal and chain cells print blank - both classes pin as -99, distinguished by the column comments; the elephant padded cell prints a lone 12 without the full/half slash - the T50 lone-number lo=hi convention carries it. The warhorse names ride the column comments per the T48 doctrine. The barding prose box (the AC-factor and weight paragraph) and the misc equipment prose box stay open  the gap census after this round: 97 closed, 138 open - the Table 55 box flips (census 568 -> 569); NEXT - R647: the Miscellaneous Equipment Descriptions prose box (capture p. 98), the grenades prose, prefix dhh (verify free), audit \"R647 OA misc equipment audit\", include after rules/oa/oabarding.h - the barding prose box stays open beside it",
    },
  "consts" = { {
      "name" = "dhgT55RowCount",
      "value" = 4,
      "comment" = "Table 55 (capture p. 98): four barded warhorse rows - light, medium, heavy and elephant",
    }, {
      "name" = "dhgT55MatCount",
      "value" = 3,
      "comment" = "the three barding materials - padded/leather, metal scale and chain (capture p. 98)",
    } },
  "bools" = { {
      "name" = "dhgT55FullBeforeSlash",
      "value" = true,
      "comment" = "the note under Table 55: the number before the slash is for full barding, the number after the slash for half-barding (capture p. 98)",
    }, {
      "name" = "dhgT55XTooHeavy",
      "value" = true,
      "comment" = "the note under Table 55: an X indicates the barding is heavier than the horse can bear (capture p. 98)",
    } },
  "switches" = { {
      "name" = "dhgT55PaddedFull",
      "values" = { 21, 17, 15, 12 },
      "default" = -99,
      "comment" = "the base movement rate in feet under full padded/leather barding, by warhorse row (capture p. 98). The warhorse rows ride this comment: 0 Light, 1 Medium, 2 Heavy, 3 Elephant - the elephant padded cell prints a lone 12 without the full/half slash, the T50 lone-number lo=hi convention carries it (capture p. 98).",
    }, {
      "name" = "dhgT55PaddedHalf",
      "values" = { 24, 18, 15, 12 },
      "default" = -99,
      "comment" = "the base movement rate in feet under half padded/leather barding (capture p. 98); the elephant cell rides the lone-print lo=hi convention.",
    }, {
      "name" = "dhgT55MetalFull",
      "values" = { 15, 15, 14, -99 },
      "default" = -99,
      "comment" = "the base movement rate in feet under full metal scale barding (capture p. 98); the elephant cell prints blank - no barding given, pin as -99.",
    }, {
      "name" = "dhgT55MetalHalf",
      "values" = { 21, 17, 15, -99 },
      "default" = -99,
      "comment" = "the base movement rate in feet under half metal scale barding (capture p. 98); the elephant cell prints blank - pin as -99.",
    }, {
      "name" = "dhgT55ChainFull",
      "values" = { -99, 12, 13, -99 },
      "default" = -99,
      "comment" = "the base movement rate in feet under full chain barding (capture p. 98); the light-horse cell prints X - the barding heavier than the horse can bear, pin as -99; the elephant cell prints blank - pin as -99.",
    }, {
      "name" = "dhgT55ChainHalf",
      "values" = { 15, 15, 15, -99 },
      "default" = -99,
      "comment" = "the base movement rate in feet under half chain barding (capture p. 98); the light horse carries the 15 half-barding rate beside its too-heavy X; the elephant cell prints blank - pin as -99.",
    } },
  "tables" = { {
      "name" = "dhgT55Grid",
      "tag" = "T55Data",
      "count" = "dhgT55RowCount",
      "sentinel" = -99,
      "cols" = { "dhgT55PaddedFull", "dhgT55PaddedHalf", "dhgT55MetalFull", "dhgT55MetalHalf", "dhgT55ChainFull", "dhgT55ChainHalf" },
      "comment" = "the Table 55 barded warhorse movement grid (capture p. 98)",
      "col_comments" = { "the base movement rate in feet under full padded/leather barding, by warhorse row (capture p. 98). The warhorse rows ride this comment: 0 Light, 1 Medium, 2 Heavy, 3 Elephant - the elephant padded cell prints a lone 12 without the full/half slash, the T50 lone-number lo=hi convention carries it (capture p. 98).", "the base movement rate in feet under half padded/leather barding (capture p. 98); the elephant cell rides the lone-print lo=hi convention.", "the base movement rate in feet under full metal scale barding (capture p. 98); the elephant cell prints blank - no barding given, pin as -99.", "the base movement rate in feet under half metal scale barding (capture p. 98); the elephant cell prints blank - pin as -99.", "the base movement rate in feet under full chain barding (capture p. 98); the light-horse cell prints X - the barding heavier than the horse can bear, pin as -99; the elephant cell prints blank - pin as -99.", "the base movement rate in feet under half chain barding (capture p. 98); the light horse carries the 15 half-barding rate beside its too-heavy X; the elephant cell prints blank - pin as -99." },
      "audit_comment" = "the Table 55 grid: the full/half barding movement pairs and the X",
      "data" = { { 21, 24, 15, 21, -99, 15 }, { 17, 18, 15, 17, 12, 15 }, { 15, 15, 14, 15, 13, 15 }, { 12, 12, -99, -99, -99, -99 } },
      "sentinel_census" = { 0, 0, 1, 1, 2, 1 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhgT55RowCount']() != 4  or m['dhgT55MatCount']() != 3  or  m['dhgT55FullBeforeSlash']() != 1  or  m['dhgT55XTooHeavy']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dhgT55RowCount']() != 4",
      "note" = "the T55 row count pin",
    }, {
      "expr" = "m['dhgT55MatCount']() != 3",
      "note" = "the T55 material count pin",
    }, {
      "expr" = "m['dhgT55FullBeforeSlash']() != 1",
      "note" = "the full-before-slash note pin",
    }, {
      "expr" = "m['dhgT55XTooHeavy']() != 1",
      "note" = "the X-too-heavy note pin",
    }, {
      "expr" = "m['dhgT55PaddedFull'](0) != 21  or m['dhgT55PaddedHalf'](0) != 24",
      "note" = "the light row - the padded pair 21/24, half barding faster than full (capture p. 98)",
    }, {
      "expr" = "m['dhgT55ChainFull'](0) != -99  or m['dhgT55ChainHalf'](0) != 15",
      "note" = "the light row chain cell - the too-heavy X as -99 beside the 15 half-barding rate (capture p. 98)",
    }, {
      "expr" = "m['dhgT55MetalFull'](0) != 15  or m['dhgT55MetalHalf'](0) != 21",
      "note" = "the light row metal-scale pair - the 15/21 with the print-pass stray-space glyph artifact (capture p. 98)",
    }, {
      "expr" = "m['dhgT55PaddedFull'](1) != 17  or m['dhgT55MetalFull'](1) != 15  or m['dhgT55ChainFull'](1) != 12  or m['dhgT55ChainHalf'](1) != 15",
      "note" = "the medium row - the 17/18 padded, 15/17 metal and 12/15 chain pairs (capture p. 98)",
    }, {
      "expr" = "m['dhgT55PaddedFull'](2) != 15  or m['dhgT55MetalFull'](2) != 14  or m['dhgT55ChainFull'](2) != 13",
      "note" = "the heavy row - the 15/15 padded, 14/15 metal and 13/15 chain pairs (capture p. 98)",
    }, {
      "expr" = "m['dhgT55PaddedFull'](3) != 12  or m['dhgT55PaddedHalf'](3) != 12  or m['dhgT55MetalFull'](3) != -99  or m['dhgT55ChainFull'](3) != -99  or m['dhgT55ChainHalf'](3) != -99",
      "note" = "the elephant row - the lone 12 as the lo=hi convention, the metal and chain cells blank as -99 (capture p. 98)",
    } },
  "audit" = {
      "label" = "R646 OA barding audit",
      "comment" = "OA round thirty-three (capture p. 98): the Table 55 barded warhorse base movement rates - the full/half barding pairs and the too-heavy X",
    },
}
