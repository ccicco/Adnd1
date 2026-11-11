-- oa655: promoted from rules/oa/oabarbprof.h (the TABLE 59 BARBARIAN PROFICIENCIES, printed capture p. 104 - the OA barbarian);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 655,
  "prefix" = "oa655",
  "banner" = {
      "title" = "TABLE 59 BARBARIAN PROFICIENCIES, printed capture p. 104 - the OA barbarian",
      "provenance" = "proficiencies round census 577 -> 578.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read of the table - the Table 59 grid cross-checked cell-by-cell between the two passes (the table opening at the bottom of capture p. 104 of the print pass with the eight grid rows printing at the top of p. 105; compressed p. 53 carrying the full grid); every printed cell agrees - zero contested cells, marker for marker. The print pass read here comes from the recovered capture session: the original print OCR session was lost to an extraction failure at the R655 open, the re-uploaded scan extracted at 315 pages with its pagination aligned to the book (its p. 101 cross-checked verbatim against the prior session read, its p. 103 corroborating the R654 marker reads). The grid pins as a table: the barbarian rows 0 chanting, 1 fire building, 2 running, 3 signaling, 4 snare building, 5 sound imitation, 6 survival and 7 tracking riding the first column comment, three data columns - the proficiency slots required (1, 1, 1, 1, 1, 2, 2, 3), the base chance of success (15, 8, 16, 12, 14, 16, 15, 17) and the always-roll marker (1 for fire building, running, signaling, snare building, sound imitation and tracking, 0 for chanting and survival). The asterisk (further-explanation) markers ride the row comments - all but chanting carry it; the barbarian prose explanations (the fire-building 30 minutes, the running doctrine, the tracking terrain modifiers) stay with their own rounds. The table tag T59Data identifier-safe per the R639 lesson  the gap census after this round: 107 closed, 128 open - the Table 59 box flips (census 577 -> 578); NEXT - R656: Table 60 (Common Proficiencies), capture p. 106, prefix dhq (verify free), audit \"R656 OA common proficiencies audit\", include after rules/oa/oabarbprof.h",
    },
  "consts" = { {
      "name" = "dhpT59RowCount",
      "value" = 8,
      "comment" = "the eight barbarian proficiencies of the Table 59 grid (capture p. 104 of the print pass; compressed p. 53)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dhpT59Slots",
      "values" = { 1, 1, 1, 1, 1, 2, 2, 3 },
      "default" = -99,
      "comment" = "the proficiency slots required to initially gain the proficiency (capture p. 104 of the print pass; compressed p. 53). The barbarian rows ride this comment: 0 chanting, 1 fire building, 2 running, 3 signaling, 4 snare building, 5 sound imitation, 6 survival, 7 tracking - the printed asterisk (further-explanation) marker rides here too: all but chanting carry it",
    }, {
      "name" = "dhpT59Base",
      "values" = { 15, 8, 16, 12, 14, 16, 15, 17 },
      "default" = -99,
      "comment" = "the base chance of success - the base number for the 1d20 roll (capture p. 104 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhpT59AlwaysRoll",
      "values" = { 0, 1, 1, 1, 1, 1, 0, 1 },
      "default" = -99,
      "comment" = "the always-roll marker - 1 where the printed a footnote marks a die roll always required to determine success, 0 otherwise (capture p. 104 of the print pass; compressed p. 53). The six-marked set: fire building, running, signaling, snare building, sound imitation and tracking - chanting and survival carry no marker in either pass",
    } },
  "tables" = { {
      "name" = "dhpT59Grid",
      "tag" = "T59Data",
      "count" = "dhpT59RowCount",
      "sentinel" = -99,
      "cols" = { "dhpT59Slots", "dhpT59Base", "dhpT59AlwaysRoll" },
      "col_comments" = { "the proficiency slots required to initially gain the proficiency (capture p. 104 of the print pass; compressed p. 53). The barbarian rows ride this comment: 0 chanting, 1 fire building, 2 running, 3 signaling, 4 snare building, 5 sound imitation, 6 survival, 7 tracking - the printed asterisk (further-explanation) marker rides here too: all but chanting carry it", "the base chance of success - the base number for the 1d20 roll (capture p. 104 of the print pass; compressed p. 53)", "the always-roll marker - 1 where the printed a footnote marks a die roll always required to determine success, 0 otherwise (capture p. 104 of the print pass; compressed p. 53). The six-marked set: fire building, running, signaling, snare building, sound imitation and tracking - chanting and survival carry no marker in either pass" },
      "data" = { { 1, 15, 0 }, { 1, 8, 1 }, { 1, 16, 1 }, { 1, 12, 1 }, { 1, 14, 1 }, { 2, 16, 1 }, { 2, 15, 0 }, { 3, 17, 1 } },
      "comment" = "the Table 59 barbarian proficiencies grid (capture p. 104 of the print pass; compressed p. 53)",
      "audit_comment" = "the Table 59 grid: the barbarian slot costs, base chances and always-roll markers",
      "sentinel_census" = { 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhpT59RowCount']() != 8",
      "note" = "",
    }, {
      "expr" = "m['dhpT59Slots'](0) != 1  or m['dhpT59Slots'](4) != 1  or m['dhpT59Slots'](5) != 2  or m['dhpT59Slots'](6) != 2  or m['dhpT59Slots'](7) != 3",
      "note" = "the slot-cost pins - chanting through snare building one slot, sound imitation and survival two, tracking three",
    }, {
      "expr" = "m['dhpT59Base'](1) != 8  or m['dhpT59Base'](3) != 12  or m['dhpT59Base'](4) != 14  or m['dhpT59Base'](0) != 15  or m['dhpT59Base'](6) != 15  or m['dhpT59Base'](2) != 16  or m['dhpT59Base'](5) != 16  or m['dhpT59Base'](7) != 17",
      "note" = "the base-chance pins - fire building 8, signaling 12, snare building 14, chanting and survival 15, running and sound imitation 16, tracking 17",
    }, {
      "expr" = "m['dhpT59AlwaysRoll'](1) != 1  or m['dhpT59AlwaysRoll'](2) != 1  or m['dhpT59AlwaysRoll'](3) != 1  or m['dhpT59AlwaysRoll'](4) != 1  or m['dhpT59AlwaysRoll'](5) != 1  or m['dhpT59AlwaysRoll'](7) != 1  or m['dhpT59AlwaysRoll'](0) != 0  or m['dhpT59AlwaysRoll'](6) != 0",
      "note" = "the always-roll pins - fire building, running, signaling, snare building, sound imitation and tracking roll, chanting and survival never do",
    }, {
      "expr" = "m['dhpT59RowCount']() != 8",
      "note" = "the row-count pin - eight barbarian proficiencies",
    } },
  "audit" = {
      "label" = "R655 OA barbarian proficiencies audit",
      "comment" = "OA round forty-two (capture p. 104): Table 59 - the barbarian proficiencies grid, the slot costs, the base chances and the always-roll markers",
    },
}
