-- oa667: promoted from rules/oa/oat64speakdead.h (the TABLE 64 SPEAK WITH DEAD, printed capture p. 132 - the OA speak with dead);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 667,
  "prefix" = "oa667",
  "banner" = {
      "title" = "TABLE 64 SPEAK WITH DEAD, printed capture p. 132 - the OA speak with dead",
      "provenance" = "round census 589 -> 590.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read (print p. 132; compressed pp. 64-65); the six band rows cross-checked line by line between the passes, zero contested reads - the one OCR variance is the compressed 2 turn on the 13-15 questioning row against the print's 2 turns (the print settles). The table answers the third level speak with dead spell: the number of questions is dependent on level. The bands pin as a chain (the shukenja's level mapped to its band: 6 and below the least band, 7-8, 9-12, 13-15, 16-20, more than 20 the tail) and a three-column grid: the maximum dead time in days (the 7-day week, the 30-day month and the 365-day year conventions, then a decade climb per band up to the 1000-year greatest band pinned 365000), the questioning time in segments (one round, three rounds, one turn, two turns, three turns, six turns - the round = 10 and turn = 60 conventions) and the question counts climbing one per band from two to seven - the band ordinal plus the dibT64QuestionsBase pin. The band names ride the column comments, the spell prose closes in its own round. The table tag T64Data identifier-safe per the R639 lesson  the gap census after this round: 120 closed, 115 open - the Table 64 Speak with Dead box flips (census 589 -> 590); NEXT - R668: the Table 65 Fate (print p. 135), prefix dic (verify free), audit \"R668 OA fate audit\"",
    },
  "consts" = { {
      "name" = "dibT64BandCount",
      "value" = 6,
      "comment" = "the six speak with dead level bands (print p. 132; compressed pp. 64-65)",
    }, {
      "name" = "dibT64QuestionsBase",
      "value" = 2,
      "comment" = "the question count ladder base - each band grants its band ordinal plus two questions, from two in the least band to seven in the greatest (print p. 132; compressed pp. 64-65)",
    }, {
      "name" = "dibT64MaxQuestions",
      "value" = 7,
      "comment" = "the greatest question count - the more-than-20th level band (print p. 132; compressed pp. 64-65)",
    }, {
      "name" = "dibT64DeadWeekDays",
      "value" = 7,
      "comment" = "the least band's maximum dead time - one week, pinned as seven days (print p. 132; compressed pp. 64-65)",
    }, {
      "name" = "dibT64DeadMonthDays",
      "value" = 30,
      "comment" = "the second band's maximum dead time - one month, pinned as 30 days (the 30-day month convention) (print p. 132; compressed pp. 64-65)",
    }, {
      "name" = "dibT64DeadYearDays",
      "value" = 365,
      "comment" = "the third band's maximum dead time - one year, pinned as 365 days (the 365-day year convention) (print p. 132; compressed pp. 64-65)",
    }, {
      "name" = "dibT64LongestDeadDays",
      "value" = 365000,
      "comment" = "the greatest maximum dead time - the 1000 years of the more-than-20th band, pinned as 365000 days, the ladder climbing a decade per band from the one-year band (print p. 132; compressed pp. 64-65)",
    }, {
      "name" = "dibT64ShortestQuestionSegments",
      "value" = 10,
      "comment" = "the least band's questioning time - one round, pinned as 10 segments (print p. 132; compressed pp. 64-65)",
    }, {
      "name" = "dibT64LongestQuestionSegments",
      "value" = 360,
      "comment" = "the greatest questioning time - the six turns of the more-than-20th band, pinned as 360 segments (the turn = 60 convention) (print p. 132; compressed pp. 64-65)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dibT64DeadDays",
      "values" = { 7, 30, 365, 3650, 36500, 365000 },
      "default" = 0,
      "comment" = "the maximum length of time the subject has been dead by band, pinned in days (print p. 132; compressed pp. 64-65). The band list rides this comment: 0 less than 7, 1 levels 7-8, 2 levels 9-12, 3 levels 13-15, 4 levels 16-20, 5 more than 20 - the ladder: one week (7 days), one month (30, the 30-day month convention), one year (365, the 365-day year convention), then a decade climb per band - 10 years (3650), 100 years (36500) and 1000 years (365000)",
    }, {
      "name" = "dibT64QuestionSegments",
      "values" = { 10, 30, 60, 120, 180, 360 },
      "default" = 0,
      "comment" = "the questioning time by band, pinned in segments (print p. 132; compressed pp. 64-65). The band list rides this comment: 0 less than 7, 1 levels 7-8, 2 levels 9-12, 3 levels 13-15, 4 levels 16-20, 5 more than 20 - the ladder: one round (10 segments, the round = 10 convention), three rounds (30), one turn (60), two turns (120), three turns (180) and six turns (360, the turn = 60 convention)",
    }, {
      "name" = "dibT64Questions",
      "values" = { 2, 3, 4, 5, 6, 7 },
      "default" = 0,
      "comment" = "the number of questions by band (print p. 132; compressed pp. 64-65). The band list rides this comment: 0 less than 7, 1 levels 7-8, 2 levels 9-12, 3 levels 13-15, 4 levels 16-20, 5 more than 20 - the count climbs one per band from two in the least band to seven in the greatest - the band ordinal plus the dibT64QuestionsBase pin",
    } },
  "tables" = { {
      "name" = "dibT64Grid",
      "tag" = "T64Data",
      "count" = "dibT64BandCount",
      "col_default" = 0,
      "cols" = { "dibT64DeadDays", "dibT64QuestionSegments", "dibT64Questions" },
      "col_comments" = { "the maximum length of time the subject has been dead by band, pinned in days (print p. 132; compressed pp. 64-65). The band list rides this comment: 0 less than 7, 1 levels 7-8, 2 levels 9-12, 3 levels 13-15, 4 levels 16-20, 5 more than 20 - the ladder: one week (7 days), one month (30, the 30-day month convention), one year (365, the 365-day year convention), then a decade climb per band - 10 years (3650), 100 years (36500) and 1000 years (365000)", "the questioning time by band, pinned in segments (print p. 132; compressed pp. 64-65). The band list rides this comment: 0 less than 7, 1 levels 7-8, 2 levels 9-12, 3 levels 13-15, 4 levels 16-20, 5 more than 20 - the ladder: one round (10 segments, the round = 10 convention), three rounds (30), one turn (60), two turns (120), three turns (180) and six turns (360, the turn = 60 convention)", "the number of questions by band (print p. 132; compressed pp. 64-65). The band list rides this comment: 0 less than 7, 1 levels 7-8, 2 levels 9-12, 3 levels 13-15, 4 levels 16-20, 5 more than 20 - the count climbs one per band from two in the least band to seven in the greatest - the band ordinal plus the dibT64QuestionsBase pin" },
      "data" = { { 7, 10, 2 }, { 30, 30, 3 }, { 365, 60, 4 }, { 3650, 120, 5 }, { 36500, 180, 6 }, { 365000, 360, 7 } },
      "comment" = "the Table 64 speak with dead band grid (print p. 132; compressed pp. 64-65)",
      "audit_comment" = "the speak with dead grid: the maximum dead time, questioning time and question counts by level band",
    } },
  "chains" = { {
      "name" = "dibT64LevelBand",
      "arg" = "lvl",
      "limits" = { 6, 8, 12, 15, 20 },
      "tail" = 5,
      "comment" = "the shukenja's level mapped to its band (print p. 132; compressed pp. 64-65): level 6 and below the least band 0, 7-8 band 1, 9-12 band 2, 13-15 band 3, 16-20 band 4, more than 20 the tail band 5",
    } },
  "examples" = { {
      "expr" = "m['dibT64BandCount']() != 6  or m['dibT64QuestionsBase']() != 2  or m['dibT64MaxQuestions']() != 7  or m['dibT64DeadWeekDays']() != 7  or m['dibT64DeadMonthDays']() != 30  or m['dibT64DeadYearDays']() != 365  or m['dibT64LongestDeadDays']() != 365000  or m['dibT64ShortestQuestionSegments']() != 10  or m['dibT64LongestQuestionSegments']() != 360",
      "note" = "",
    }, {
      "expr" = "m['dibT64LevelBand'](5) != 0  or m['dibT64LevelBand'](6) != 0  or m['dibT64LevelBand'](8) != 1  or m['dibT64LevelBand'](7) != 1  or m['dibT64LevelBand'](12) != 2  or m['dibT64LevelBand'](9) != 2  or m['dibT64LevelBand'](15) != 3  or m['dibT64LevelBand'](13) != 3  or m['dibT64LevelBand'](20) != 4  or m['dibT64LevelBand'](16) != 4  or m['dibT64LevelBand'](21) != 5",
      "note" = "the dibT64LevelBand band-for boundaries",
    }, {
      "expr" = "m['dibT64BandCount']() != 6  or m['dibT64QuestionsBase']() != 2  or m['dibT64MaxQuestions']() != 7  or m['dibT64DeadWeekDays']() != 7  or m['dibT64DeadMonthDays']() != 30  or m['dibT64DeadYearDays']() != 365  or m['dibT64LongestDeadDays']() != 365000  or m['dibT64ShortestQuestionSegments']() != 10  or m['dibT64LongestQuestionSegments']() != 360",
      "note" = "the count pins - six bands, the question ladder base two and maximum seven, the week, month and year day conventions, the longest dead time and the shortest and longest questioning times",
    }, {
      "expr" = "m['dibT64LevelBand'](1) != 0  or m['dibT64LevelBand'](6) != 0  or m['dibT64LevelBand'](7) != 1  or m['dibT64LevelBand'](8) != 1  or m['dibT64LevelBand'](9) != 2  or m['dibT64LevelBand'](12) != 2  or m['dibT64LevelBand'](13) != 3  or m['dibT64LevelBand'](15) != 3  or m['dibT64LevelBand'](16) != 4  or m['dibT64LevelBand'](20) != 4  or m['dibT64LevelBand'](21) != 5",
      "note" = "the chain pins - the shukenja's level mapped to its band: level 1 and level 6 the least band 0, 7 and 8 band 1, 9 and 12 band 2, 13 and 15 band 3, 16 and 20 band 4, 21 the tail band 5",
    }, {
      "expr" = "m['dibT64DeadDays'](0) != 7  or m['dibT64DeadDays'](1) != 30  or m['dibT64DeadDays'](2) != 365  or m['dibT64DeadDays'](3) != 3650  or m['dibT64DeadDays'](4) != 36500  or m['dibT64DeadDays'](5) != 365000",
      "note" = "the dead time pins - the week, month and year bands, then the decade climb: 10 years, 100 years and the 1000-year greatest band",
    }, {
      "expr" = "m['dibT64DeadDays'](3) != 10 *m['dibT64DeadDays'](2)  or m['dibT64DeadDays'](4) != 10 *m['dibT64DeadDays'](3)  or m['dibT64DeadDays'](5) != 10 *m['dibT64DeadDays'](4)",
      "note" = "the decade ladder pins - each band from the one-year band climbs exactly a decade",
    }, {
      "expr" = "m['dibT64QuestionSegments'](0) != 10  or m['dibT64QuestionSegments'](1) != 30  or m['dibT64QuestionSegments'](2) != 60  or m['dibT64QuestionSegments'](3) != 120  or m['dibT64QuestionSegments'](4) != 180  or m['dibT64QuestionSegments'](5) != 360",
      "note" = "the questioning time pins - one round, three rounds, one turn, two turns, three turns and the six-turn greatest band (the compressed reads 2 turn on the two-turn row - the print settles 2 turns)",
    }, {
      "expr" = "m['dibT64Questions'](0) != 2  or m['dibT64Questions'](1) != 3  or m['dibT64Questions'](2) != 4  or m['dibT64Questions'](3) != 5  or m['dibT64Questions'](4) != 6  or m['dibT64Questions'](5) != 7",
      "note" = "the question count pins - the ladder climbing one per band from two to seven",
    }, {
      "expr" = "m['dibT64Questions'](0) != 0 +m['dibT64QuestionsBase']()  or m['dibT64Questions'](3) != 3 +m['dibT64QuestionsBase']()  or m['dibT64Questions'](5) != 5 +m['dibT64QuestionsBase']()",
      "note" = "the question ladder identity pins - each band's question count is its band ordinal plus the base two, checked at both ladder ends and the middle",
    } },
  "audit" = {
      "label" = "R667 OA speak with dead audit",
      "comment" = "OA round fifty-four (capture p. 132): Table 64 - the speak with dead ladder by shukenja level, the maximum dead time, questioning time and question counts per band, cross-checked between the passes",
    },
}
