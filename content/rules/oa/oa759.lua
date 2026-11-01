-- oa759: promoted from rules/oa130table86.h (the OA TREASURE - TABLE 86, ORIENTAL MAGICAL ITEMS, printed capture pp. 296-297);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 759,
  "prefix" = "oa759",
  "banner" = {
      "title" = "OA TREASURE - TABLE 86, ORIENTAL MAGICAL ITEMS, printed capture pp. 296-297",
      "provenance" = "- the item grid round census 681 -> 682.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 212 closed, 23 open - the Table 86 box flips (census 681 -> 682); CHAPTER 13 COMPLETE - NEXT - R760: Chapter 14 An Overview of Kara-Tur, the chapter intro and the Population prose (capture pp. 301-302), prefix dlv (verify free at the landing), audit \"R760 OA Kara-Tur overview audit\", include after rules/oa130table86.h - the setting chapter, advisory prose closing on doctrine pins",
    },
  "consts" = { {
      "name" = "dluItemRowCount",
      "value" = 34,
      "comment" = "the item row count - the thirty-four d100 bands of the Table 86 magical item grid (print capture p. 296)",
    }, {
      "name" = "dluPageBreakGrid",
      "value" = 1,
      "comment" = "the page break - the grid opening on the one page and running onto the next (print capture p. 297)",
    }, {
      "name" = "dluOverlapQuirk",
      "value" = 1,
      "comment" = "the overlap quirk - the capture printing the 95-96 wheels of fire and then the 91-100 wondrous writing set, the overlapping bands pinned as printed, almost certainly the 97-100 intended (print capture p. 297)",
    }, {
      "name" = "dluClassRestrictedItems",
      "value" = 1,
      "comment" = "the class-restricted items - the minyan of the shukenja and sohei, the net of the shukenja, the seal of the ninja and yakuza, the tablet of the shukenja and wu jen (print capture p. 297)",
    }, {
      "name" = "dluWideBands",
      "value" = 1,
      "comment" = "the wide bands - the 73-85 scroll the widest, the 64-70 pearl and the 16-20 charm following (print capture p. 297)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dluItemRollMin",
      "values" = { 1, 6, 9, 12, 13, 14, 16, 21, 25, 28, 32, 33, 34, 36, 37, 38, 42, 45, 46, 48, 49, 52, 54, 59, 61, 64, 71, 72, 73, 86, 88, 93, 95, 91 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 296)",
    }, {
      "name" = "dluItemRollMax",
      "values" = { 5, 8, 11, 12, 13, 15, 20, 24, 27, 31, 32, 33, 35, 36, 37, 41, 44, 45, 47, 48, 51, 53, 58, 60, 63, 70, 71, 72, 85, 87, 92, 94, 96, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row, the wondrous writing set printing the 91-100 of the overlap quirk (print capture p. 297)",
    }, {
      "name" = "dluItemCode",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34 },
      "default" = 0,
      "comment" = "the magical item code - 1 the banner of protection; 2 the bell of protection; 3 the bell of warning; 4 the biwa of calm; 5 the biwa of charm; 6 the biwa of discord; 7 the charm of protection from disease; 8 the charm of protection from fire; 9 the charm of protection from spirits; 10 the charm of protection from theft; 11 the diamond mace; 12 the drums of thunder; 13 the eight diagram coins; 14 the everproducing rice mortar; 15 the gem of wishes; 16 the gong of dispelling; 17 the mallet of luck; 18 the minyan (shukenja, sohei); 19 the mirror of curing; 20 the mirror of enlightenment; 21 the mirror of fear; 22 the mirror of spirit seeing; 23 the net of spirit snaring (shukenja); 24 the noisome spirit chasers; 25 the paper of forms; 26 the pearl of protection from fire; 27 the pearl of the ebbing tide; 28 the pearl of the rising tide; 29 the scroll of protection from spirits; 30 the seal of deception (ninja, yakuza); 31 the seal of vigor; 32 the tablet of spirit summoning (shukenja, wu jen); 33 the wheels of fire; 34 the wondrous writing set - the capture printing the 91-100 against the 95-96 wheels, the overlapping band pinned as printed, almost certainly the 97-100 intended (print capture p. 297)",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dluItemRowCount']() != 34  or  m['dluPageBreakGrid']() != 1  or  m['dluOverlapQuirk']() != 1  or  m['dluClassRestrictedItems']() != 1  or  m['dluWideBands']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dluItemRowCount']() != 34  or m['dluItemRollMin'](0) != 1  or m['dluItemRollMax'](33) != 100  or m['dluItemCode'](0) != 1  or m['dluItemCode'](33) != 34",
      "note" = "the grid - the thirty-four-band Table 86, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dluItemRollMin'](32) != 95  or m['dluItemRollMax'](32) != 96  or m['dluItemRollMin'](33) != 91  or m['dluItemRollMax'](33) != 100  or m['dluItemRollMin'](28) != 73  or m['dluItemRollMax'](28) != 85  or m['dluOverlapQuirk']() != 1  or m['dluPageBreakGrid']() != 1  or m['dluClassRestrictedItems']() != 1  or m['dluWideBands']() != 1",
      "note" = "the quirks - the overlap band and the wide bands, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R759 OA Table 86 items audit",
      "comment" = "OA round one hundred forty-six (capture pp. 296-297): the Table 86 Oriental Magical Items - the thirty-four d100 bands of the item grid, the banner of protection through the wondrous writing set, the 91-100 overlap quirk of the tail pinned as printed, single-pass pins per the Chapter 9 provenance shift",
    },
}
