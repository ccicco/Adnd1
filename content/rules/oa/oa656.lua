-- oa656: promoted from rules/oa/oacomprof.h (the TABLE 60 COMMON PROFICIENCIES, printed capture p. 106 - the OA common);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 656,
  "prefix" = "oa656",
  "banner" = {
      "title" = "TABLE 60 COMMON PROFICIENCIES, printed capture p. 106 - the OA common",
      "provenance" = "proficiencies round census 578 -> 579.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read of the table - the Table 60 grid cross-checked cell-by-cell between the two passes (the table printing on capture p. 106 of the print pass; compressed p. 55 carrying the full grid). The arc's first contested numeric reads: the compressed pass reads the fishing base 14 against the print 17, and the juggling and small water craft bases 13 against the print 16 - the print pass is the settling authority, the three bases pin per the print (17, 16, 16) with the compressed deltas recorded as its OCR artifact. One footnote-marker read settles against the prose: the print pass drops the hunting a marker where the compressed carries it and the hunting prose mandates the die roll, so the marker pins per the compressed-plus-prose reading, the print drop reading as an OCR omission - the R654 precedent. Every other cell agrees - zero further contested reads. The grid pins as a table: the common rows 0 agriculture through 16 swimming riding the first column comment, three data columns - the proficiency slots required (animal handling 2, the rest 1), the base chance of success (15, 14, 16, 17, 17, 16, 18, 16, 14, the iaijutsu printed dash as the sentinel, 16, 17, 10, 15, 17, 16, 10) and the always-roll marker (1 for animal handling, gaming, horsemanship, hunting, juggling and swimming, 0 for the other eleven). The iaijutsu dash pins as the sentinel - a weapon skill listed among the common proficiencies but with no peaceful base chance. The asterisk (further-explanation) markers ride the row comments; the common prose explanations stay with their own rounds. The table tag T60Data identifier-safe per the R639 lesson  the gap census after this round: 108 closed, 127 open - the Table 60 box flips (census 578 -> 579); NEXT - R657: Table 61 (Court Proficiencies), capture p. 108, prefix dhr (verify free), audit \"R657 OA court proficiencies audit\", include after rules/oa/oacomprof.h",
    },
  "consts" = { {
      "name" = "dhqT60RowCount",
      "value" = 17,
      "comment" = "the seventeen common proficiencies of the Table 60 grid (capture p. 106 of the print pass; compressed p. 55)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dhqT60Slots",
      "values" = { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
      "default" = -99,
      "comment" = "the proficiency slots required to initially gain the proficiency (capture p. 106 of the print pass; compressed p. 55). The common rows ride this comment: 0 agriculture, 1 animal handling, 2 cooking, 3 dance, 4 fishing, 5 gaming, 6 horsemanship, 7 hunting, 8 husbandry, 9 iaijutsu, 10 juggling, 11 music, 12 reading/writing, 13 sailing craft, 14 singing, 15 small water craft, 16 swimming - the printed asterisk (further-explanation) marker rides here too: all but agriculture, cooking, dance, husbandry, music and singing carry it",
    }, {
      "name" = "dhqT60Base",
      "values" = { 15, 14, 16, 17, 17, 16, 18, 16, 14, -99, 16, 17, 10, 15, 17, 16, 10 },
      "default" = -99,
      "comment" = "the base chance of success - the base number for the 1d20 roll, the sentinel standing in for the iaijutsu printed dash (a weapon skill with no peaceful base chance; capture p. 106 of the print pass; compressed p. 55)",
    }, {
      "name" = "dhqT60AlwaysRoll",
      "values" = { 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
      "default" = -99,
      "comment" = "the always-roll marker - 1 where the printed a footnote marks a die roll always required to determine success, 0 otherwise (capture p. 106 of the print pass; compressed p. 55). The six-marked set: animal handling, gaming, horsemanship, hunting, juggling and swimming - the print pass drops the hunting marker where the compressed carries it and the hunting prose mandates the die roll, so the marker pins per the compressed-plus-prose reading",
    } },
  "tables" = { {
      "name" = "dhqT60Grid",
      "tag" = "T60Data",
      "count" = "dhqT60RowCount",
      "sentinel" = -99,
      "cols" = { "dhqT60Slots", "dhqT60Base", "dhqT60AlwaysRoll" },
      "col_comments" = { "the proficiency slots required to initially gain the proficiency (capture p. 106 of the print pass; compressed p. 55). The common rows ride this comment: 0 agriculture, 1 animal handling, 2 cooking, 3 dance, 4 fishing, 5 gaming, 6 horsemanship, 7 hunting, 8 husbandry, 9 iaijutsu, 10 juggling, 11 music, 12 reading/writing, 13 sailing craft, 14 singing, 15 small water craft, 16 swimming - the printed asterisk (further-explanation) marker rides here too: all but agriculture, cooking, dance, husbandry, music and singing carry it", "the base chance of success - the base number for the 1d20 roll, the sentinel standing in for the iaijutsu printed dash (a weapon skill with no peaceful base chance; capture p. 106 of the print pass; compressed p. 55)", "the always-roll marker - 1 where the printed a footnote marks a die roll always required to determine success, 0 otherwise (capture p. 106 of the print pass; compressed p. 55). The six-marked set: animal handling, gaming, horsemanship, hunting, juggling and swimming - the print pass drops the hunting marker where the compressed carries it and the hunting prose mandates the die roll, so the marker pins per the compressed-plus-prose reading" },
      "data" = { { 1, 15, 0 }, { 2, 14, 1 }, { 1, 16, 0 }, { 1, 17, 0 }, { 1, 17, 0 }, { 1, 16, 1 }, { 1, 18, 1 }, { 1, 16, 1 }, { 1, 14, 0 }, { 1, -99, 0 }, { 1, 16, 1 }, { 1, 17, 0 }, { 1, 10, 0 }, { 1, 15, 0 }, { 1, 17, 0 }, { 1, 16, 0 }, { 1, 10, 1 } },
      "comment" = "the Table 60 common proficiencies grid (capture p. 106 of the print pass; compressed p. 55)",
      "audit_comment" = "the Table 60 grid: the common slot costs, base chances and always-roll markers",
      "sentinel_census" = { 0, 1, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhqT60RowCount']() != 17",
      "note" = "",
    }, {
      "expr" = "m['dhqT60Slots'](1) != 2  or m['dhqT60Slots'](0) != 1  or m['dhqT60Slots'](9) != 1  or m['dhqT60Slots'](16) != 1",
      "note" = "the slot-cost pins - animal handling two slots, the other sixteen one slot",
    }, {
      "expr" = "m['dhqT60Base'](12) != 10  or m['dhqT60Base'](16) != 10  or m['dhqT60Base'](6) != 18  or m['dhqT60Base'](4) != 17  or m['dhqT60Base'](10) != 16  or m['dhqT60Base'](15) != 16  or m['dhqT60Base'](9) != -99",
      "note" = "the base-chance pins - reading/writing and swimming 10, horsemanship 18, fishing and juggling and small water craft 16 per the print read, the iaijutsu dash as the sentinel",
    }, {
      "expr" = "m['dhqT60Base'](0) != 15  or m['dhqT60Base'](1) != 14  or m['dhqT60Base'](8) != 14  or m['dhqT60Base'](2) != 16  or m['dhqT60Base'](3) != 17  or m['dhqT60Base'](5) != 16  or m['dhqT60Base'](11) != 17  or m['dhqT60Base'](13) != 15  or m['dhqT60Base'](14) != 17",
      "note" = "the base-chance ladder pins - the uncontested cells (agriculture 15, animal handling and husbandry 14, cooking 16, dance and music and singing 17, gaming 16, sailing craft 15)",
    }, {
      "expr" = "m['dhqT60AlwaysRoll'](1) != 1  or m['dhqT60AlwaysRoll'](5) != 1  or m['dhqT60AlwaysRoll'](6) != 1  or m['dhqT60AlwaysRoll'](7) != 1  or m['dhqT60AlwaysRoll'](10) != 1  or m['dhqT60AlwaysRoll'](16) != 1  or m['dhqT60AlwaysRoll'](0) != 0  or m['dhqT60AlwaysRoll'](9) != 0  or m['dhqT60AlwaysRoll'](12) != 0  or m['dhqT60AlwaysRoll'](15) != 0",
      "note" = "the always-roll pins - animal handling, gaming, horsemanship, hunting, juggling and swimming roll, the others never do",
    }, {
      "expr" = "m['dhqT60RowCount']() != 17",
      "note" = "the row-count pin - seventeen common proficiencies",
    } },
  "audit" = {
      "label" = "R656 OA common proficiencies audit",
      "comment" = "OA round forty-three (capture p. 106): Table 60 - the common proficiencies grid, the slot costs, the base chances and the always-roll markers",
    },
}
