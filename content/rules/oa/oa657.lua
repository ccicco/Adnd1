-- oa657: promoted from rules/oacourtprof.h (the TABLE 61 COURT PROFICIENCIES, printed capture p. 108 - the OA court);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 657,
  "prefix" = "oa657",
  "banner" = {
      "title" = "TABLE 61 COURT PROFICIENCIES, printed capture p. 108 - the OA court",
      "provenance" = "proficiencies round census 579 -> 580.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read of the table - the Table 61 grid cross-checked cell-by-cell between the two passes (the grid opening on capture p. 108 of the print pass with the religion and tea ceremony rows printing at the top of p. 109; compressed p. 56 carrying the full grid); every printed cell agrees, marker for marker - zero contested cells. The grid pins as a table: the court rows 0 calligraphy, 1 etiquette, 2 falconry, 3 flower arranging, 4 heraldry, 5 landscape gardening, 6 noh, 7 origami, 8 painting, 9 poetry, 10 religion and 11 tea ceremony riding the first column comment, three data columns - the proficiency slots required (calligraphy, falconry and tea ceremony 2, the rest 1), the base chance of success (18, 16, 17, 15, 12, 16, 17, 14, 19, 19, 12, 15) and the always-roll marker (1 for etiquette, falconry and heraldry, 0 for the other nine). The asterisk (further-explanation) markers ride the row comments - calligraphy, etiquette, falconry, heraldry, noh, religion and tea ceremony carry it; the court prose explanations stay with their own rounds. The table tag T61Data identifier-safe per the R639 lesson. This round closes the Chapter 6 proficiencies arc - the Table 56 and Tables 58-61 grids plus the weapon, missile, non-weapon and character prose all landed  the gap census after this round: 109 closed, 126 open - the Table 61 box flips (census 579 -> 580), the Chapter 6 proficiencies arc closes; NEXT - R658: the Chapter 7 parent opens - Table 62 (Shukenja Spells), capture p. 112, the full spell list by level, prefix dhs (verify free), audit \"R658 OA shukenja spells audit\", include after rules/oacourtprof.h",
    },
  "consts" = { {
      "name" = "dhrT61RowCount",
      "value" = 12,
      "comment" = "the twelve court proficiencies of the Table 61 grid (capture p. 108 of the print pass; compressed p. 56)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dhrT61Slots",
      "values" = { 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2 },
      "default" = -99,
      "comment" = "the proficiency slots required to initially gain the proficiency (capture p. 108 of the print pass; compressed p. 56). The court rows ride this comment: 0 calligraphy, 1 etiquette, 2 falconry, 3 flower arranging, 4 heraldry, 5 landscape gardening, 6 noh, 7 origami, 8 painting, 9 poetry, 10 religion, 11 tea ceremony - the printed asterisk (further-explanation) marker rides here too: calligraphy, etiquette, falconry, heraldry, noh, religion and tea ceremony carry it",
    }, {
      "name" = "dhrT61Base",
      "values" = { 18, 16, 17, 15, 12, 16, 17, 14, 19, 19, 12, 15 },
      "default" = -99,
      "comment" = "the base chance of success - the base number for the 1d20 roll (capture p. 108 of the print pass; compressed p. 56)",
    }, {
      "name" = "dhrT61AlwaysRoll",
      "values" = { 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "the always-roll marker - 1 where the printed a footnote marks a die roll always required to determine success, 0 otherwise (capture p. 108 of the print pass; compressed p. 56). The three-marked set: etiquette, falconry and heraldry",
    } },
  "tables" = { {
      "name" = "dhrT61Grid",
      "tag" = "T61Data",
      "count" = "dhrT61RowCount",
      "sentinel" = -99,
      "cols" = { "dhrT61Slots", "dhrT61Base", "dhrT61AlwaysRoll" },
      "col_comments" = { "the proficiency slots required to initially gain the proficiency (capture p. 108 of the print pass; compressed p. 56). The court rows ride this comment: 0 calligraphy, 1 etiquette, 2 falconry, 3 flower arranging, 4 heraldry, 5 landscape gardening, 6 noh, 7 origami, 8 painting, 9 poetry, 10 religion, 11 tea ceremony - the printed asterisk (further-explanation) marker rides here too: calligraphy, etiquette, falconry, heraldry, noh, religion and tea ceremony carry it", "the base chance of success - the base number for the 1d20 roll (capture p. 108 of the print pass; compressed p. 56)", "the always-roll marker - 1 where the printed a footnote marks a die roll always required to determine success, 0 otherwise (capture p. 108 of the print pass; compressed p. 56). The three-marked set: etiquette, falconry and heraldry" },
      "data" = { { 2, 18, 0 }, { 1, 16, 1 }, { 2, 17, 1 }, { 1, 15, 0 }, { 1, 12, 1 }, { 1, 16, 0 }, { 1, 17, 0 }, { 1, 14, 0 }, { 1, 19, 0 }, { 1, 19, 0 }, { 1, 12, 0 }, { 2, 15, 0 } },
      "comment" = "the Table 61 court proficiencies grid (capture p. 108 of the print pass; compressed p. 56)",
      "audit_comment" = "the Table 61 grid: the court slot costs, base chances and always-roll markers",
      "sentinel_census" = { 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhrT61RowCount']() != 12",
      "note" = "",
    }, {
      "expr" = "m['dhrT61Slots'](0) != 2  or m['dhrT61Slots'](2) != 2  or m['dhrT61Slots'](11) != 2  or m['dhrT61Slots'](1) != 1  or m['dhrT61Slots'](9) != 1",
      "note" = "the slot-cost pins - calligraphy, falconry and tea ceremony two slots, the other nine one slot",
    }, {
      "expr" = "m['dhrT61Base'](8) != 19  or m['dhrT61Base'](9) != 19  or m['dhrT61Base'](0) != 18  or m['dhrT61Base'](6) != 17  or m['dhrT61Base'](2) != 17  or m['dhrT61Base'](1) != 16  or m['dhrT61Base'](5) != 16  or m['dhrT61Base'](3) != 15  or m['dhrT61Base'](11) != 15  or m['dhrT61Base'](7) != 14  or m['dhrT61Base'](4) != 12  or m['dhrT61Base'](10) != 12",
      "note" = "the base-chance pins - painting and poetry 19, calligraphy 18, noh 17, falconry 17, etiquette and landscape gardening 16, flower arranging and tea ceremony 15, origami 14, heraldry and religion 12",
    }, {
      "expr" = "m['dhrT61AlwaysRoll'](1) != 1  or m['dhrT61AlwaysRoll'](2) != 1  or m['dhrT61AlwaysRoll'](4) != 1  or m['dhrT61AlwaysRoll'](0) != 0  or m['dhrT61AlwaysRoll'](6) != 0  or m['dhrT61AlwaysRoll'](10) != 0  or m['dhrT61AlwaysRoll'](11) != 0",
      "note" = "the always-roll pins - etiquette, falconry and heraldry roll, the other nine never do",
    }, {
      "expr" = "m['dhrT61RowCount']() != 12",
      "note" = "the row-count pin - twelve court proficiencies",
    } },
  "audit" = {
      "label" = "R657 OA court proficiencies audit",
      "comment" = "OA round forty-four (capture p. 108): Table 61 - the court proficiencies grid, the slot costs, the base chances and the always-roll markers",
    },
}
