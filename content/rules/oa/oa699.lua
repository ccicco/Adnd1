-- oa699: promoted from rules/oa72monthly.h (the OA TABLE 72, printed capture p. 238 - the monthly events round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 699,
  "prefix" = "oa699",
  "banner" = {
      "title" = "OA TABLE 72, printed capture p. 238 - the monthly events round",
      "provenance" = "census 621 -> 622.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE GRID: the forty die-range rows of the monthly events across the percentile die, the ranges contiguous and complete 1-100, each row read across the three columns - the first for months of armed violence or its potential (war, uprisings, assassinations, political power plays), the second for natural disasters and their aftermaths (floods, typhoons, droughts, famines, plagues and the like), the third when all is right with the world. THE THIRTY NAMES by ordinal: Accident the 1; Bandit Activity the 2; Bad Harvest the 3; Bad Weather the 4; Birth the 5; Death the 6; Earthquake Minor the 7; Excessive Taxes the 8; Famous Person the 9; Fire Major the 10; Fire Minor the 11; Flooding the 12; Haunting the 13; Horrendous Monster the 14; Incursion Major the 15; Incursion Minor the 16; Injustice the 17; Landslide the 18; Maiden of Virtue the 19; Major Battle the 20; Maneater the 21; Marriage the 22; No Event the 23; Notorious Criminal the 24; Plague the 25; Recruiting the 26; Troop Movements the 27; Uprising the 28; Vengeful Stranger the 29; VIP Visit the 30. THE OPEN: the rows 01-05 Accident in all three columns, the rows 95-100 No Event in all three. THE USE: one event per month from the proper column steered by the yearly event, the DM noting each beside the month, free to substitute and to add beyond the list. The grid codifies per the R431 calculus  the gap census after this round: 152 closed, 83 open - the Table 72 box flips (census 621 -> 622); NEXT - R700: the Monthly Events prose and explanations (capture pp. 238-247), prefix djn (verify free at the landing), audit \"R700 OA monthly events prose audit\", include after rules/oa72monthly.h",
    },
  "consts" = { {
      "name" = "djmOA72RowCount",
      "value" = 40,
      "comment" = "the Table 72 row count - the forty die-range rows spanning the percentile die 1-100 (print capture p. 238)",
    }, {
      "name" = "djmOA72NameCount",
      "value" = 30,
      "comment" = "the Table 72 event name count - the thirty distinct monthly events named across the three columns (print capture p. 238)",
    }, {
      "name" = "djmOA72NoEventId",
      "value" = 23,
      "comment" = "the No Event ordinal - the twenty-third of the thirty names, the rows 95-100 No Event in all three columns (print capture p. 238)",
    }, {
      "name" = "djmOA72AccidentId",
      "value" = 1,
      "comment" = "the Accident ordinal - the first of the thirty names, the rows 01-05 Accident in all three columns (print capture p. 238)",
    }, {
      "name" = "djmOA72WarNoEventMin",
      "value" = 81,
      "comment" = "the war column No Event start - the rolls 81-100 No Event in the months of armed violence or its potential (print capture p. 238)",
    }, {
      "name" = "djmOA72WarNoEventMax",
      "value" = 100,
      "comment" = "the war column No Event close - the No Event stretch ending the first column at 100 (print capture p. 238)",
    }, {
      "name" = "djmOA72DisasterNoEventMin",
      "value" = 95,
      "comment" = "the natural disaster column No Event start - the rolls 95-100 No Event in the aftermath months (print capture p. 238)",
    }, {
      "name" = "djmOA72OtherNoEventMin",
      "value" = 93,
      "comment" = "the other column No Event start - the rolls 93-100 No Event when all is right with the world (print capture p. 238)",
    } },
  "bools" = { {
      "name" = "djmOA72OneEventPerMonth",
      "value" = true,
      "comment" = "the monthly roll - one event determined per month from the proper column, the DM noting each beside the month on a sheet of paper (print capture pp. 238-239)",
    }, {
      "name" = "djmOA72YearlyEventSteersColumn",
      "value" = true,
      "comment" = "the column steering - the yearly event steering the column: the first for war, uprisings, assassinations and political power plays; the second for natural disasters and their aftermaths; the third when all is right with the world (print capture p. 239)",
    }, {
      "name" = "djmOA72DMMaySubstitute",
      "value" = true,
      "comment" = "the DM substitution - the DM free to change any event felt inappropriate, especially compared to the other events of the year, and encouraged to add creativity beyond the list (print capture p. 239)",
    } },
  "switches" = { {
      "name" = "djmOA72MinRoll",
      "values" = { 1, 6, 8, 11, 16, 21, 23, 26, 28, 29, 31, 33, 34, 36, 38, 41, 42, 44, 45, 50, 51, 52, 55, 56, 61, 62, 66, 67, 69, 70, 72, 74, 79, 81, 83, 84, 88, 93, 94, 95 },
      "default" = 0,
      "comment" = "the Table 72 minimum rolls by row ordinal (print capture p. 238): 1, 6, 8, 11, 16, 21, 23, 26, 28, 29, 31, 33, 34, 36, 38, 41, 42, 44, 45, 50, 51, 52, 55, 56, 61, 62, 66, 67, 69, 70, 72, 74, 79, 81, 83, 84, 88, 93, 94, 95 - the forty rows contiguous 1-100",
    }, {
      "name" = "djmOA72MaxRoll",
      "values" = { 5, 7, 10, 15, 20, 22, 25, 27, 28, 30, 32, 33, 35, 37, 40, 41, 43, 44, 49, 50, 51, 54, 55, 60, 61, 65, 66, 68, 69, 71, 73, 78, 80, 82, 83, 87, 92, 93, 94, 100 },
      "default" = 0,
      "comment" = "the Table 72 maximum rolls by row ordinal (print capture p. 238): 5, 7, 10, 15, 20, 22, 25, 27, 28, 30, 32, 33, 35, 37, 40, 41, 43, 44, 49, 50, 51, 54, 55, 60, 61, 65, 66, 68, 69, 71, 73, 78, 80, 82, 83, 87, 92, 93, 94, 100 - the 100 the close",
    }, {
      "name" = "djmOA72WarEvent",
      "values" = { 1, 2, 2, 5, 6, 8, 8, 9, 10, 13, 14, 14, 15, 15, 15, 15, 16, 16, 16, 16, 16, 17, 20, 20, 24, 26, 26, 27, 27, 27, 28, 28, 29, 23, 23, 23, 23, 23, 23, 23 },
      "default" = 0,
      "comment" = "the war column event ordinals by row ordinal (print capture p. 238), the months of armed violence or its potential: Accident 1; Bandit Activity 2; Birth 5; Death 6; Excessive Taxes 8; Famous Person 9; Fire Major 10; Haunting 13; Horrendous Monster 14; Incursion Major 15; Incursion Minor 16; Injustice 17; Major Battle 20; No Event 23; Notorious Criminal 24; Recruiting 26; Troop Movements 27; Uprising 28; Vengeful Stranger 29",
    }, {
      "name" = "djmOA72DisasterEvent",
      "values" = { 1, 3, 3, 3, 4, 4, 2, 2, 2, 2, 2, 5, 5, 5, 6, 6, 6, 6, 7, 8, 8, 8, 11, 11, 12, 12, 12, 13, 13, 14, 14, 17, 18, 18, 21, 21, 25, 28, 30, 23 },
      "default" = 0,
      "comment" = "the natural disaster column event ordinals by row ordinal (print capture p. 238), the months of disasters and their aftermaths: Accident 1; Bad Harvest 3; Bad Weather 4; Bandit Activity 2; Birth 5; Death 6; Earthquake Minor 7; Excessive Taxes 8; Fire Minor 11; Flooding 12; Haunting 13; Horrendous Monster 14; Injustice 17; Landslide 18; Maneater 21; No Event 23; Plague 25; Uprising 28; VIP Visit 30",
    }, {
      "name" = "djmOA72OtherEvent",
      "values" = { 1, 3, 4, 2, 5, 5, 5, 5, 6, 6, 9, 9, 9, 11, 11, 13, 13, 17, 17, 17, 19, 19, 19, 21, 22, 22, 22, 22, 24, 24, 24, 24, 29, 29, 29, 30, 30, 23, 23, 23 },
      "default" = 0,
      "comment" = "the other column event ordinals by row ordinal (print capture p. 238), the months when all is right with the world: Accident 1; Bad Harvest 3; Bad Weather 4; Bandit Activity 2; Birth 5; Death 6; Famous Person 9; Fire Minor 11; Haunting 13; Injustice 17; Maiden of Virtue 19; Maneater 21; Marriage 22; No Event 23; Notorious Criminal 24; VIP Visit 30; Vengeful Stranger 29",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['djmOA72RowCount']() != 40  or m['djmOA72NameCount']() != 30  or m['djmOA72NoEventId']() != 23  or m['djmOA72AccidentId']() != 1  or m['djmOA72WarNoEventMin']() != 81  or m['djmOA72WarNoEventMax']() != 100  or m['djmOA72DisasterNoEventMin']() != 95  or m['djmOA72OtherNoEventMin']() != 93  or  m['djmOA72OneEventPerMonth']() != 1  or  m['djmOA72YearlyEventSteersColumn']() != 1  or  m['djmOA72DMMaySubstitute']() != 1",
      "note" = "",
    }, {
      "expr" = "m['djmOA72MinRoll'](0) != 1  or m['djmOA72MaxRoll'](0) != 5  or m['djmOA72WarEvent'](0) != 1  or m['djmOA72DisasterEvent'](0) != 1  or m['djmOA72OtherEvent'](0) != 1  or m['djmOA72MinRoll'](39) != 95  or m['djmOA72MaxRoll'](39) != 100  or m['djmOA72WarEvent'](39) != 23  or m['djmOA72DisasterEvent'](39) != 23  or m['djmOA72OtherEvent'](39) != 23",
      "note" = "the open rows - Accident 01-05 in all three columns, No Event 95-100 in all three",
    }, {
      "expr" = "m['djmOA72WarEvent'](12) != 15  or m['djmOA72WarEvent'](15) != 15  or m['djmOA72MaxRoll'](15) != 41  or m['djmOA72WarEvent'](16) != 16  or m['djmOA72WarEvent'](20) != 16  or m['djmOA72MaxRoll'](20) != 51  or m['djmOA72MinRoll'](16) != 42",
      "note" = "the war column mid - Incursion Major 34-41 ordinal 15, Incursion Minor 42-51 ordinal 16",
    }, {
      "expr" = "m['djmOA72DisasterEvent'](1) != 3  or m['djmOA72DisasterEvent'](3) != 3  or m['djmOA72DisasterEvent'](18) != 7  or m['djmOA72DisasterEvent'](36) != 25  or m['djmOA72MinRoll'](36) != 88  or m['djmOA72MaxRoll'](18) != 49",
      "note" = "the disaster column - Bad Harvest 06-15 ordinal 3, Earthquake Minor 45-49 ordinal 7, Plague 88-92 ordinal 25",
    }, {
      "expr" = "m['djmOA72OtherEvent'](20) != 19  or m['djmOA72OtherEvent'](22) != 19  or m['djmOA72OtherEvent'](23) != 21  or m['djmOA72OtherEvent'](24) != 22  or m['djmOA72OtherEvent'](27) != 22  or m['djmOA72OtherEvent'](35) != 30  or m['djmOA72OtherEvent'](36) != 30",
      "note" = "the other column - Maiden of Virtue 51-55 ordinal 19, Maneater 56-60 ordinal 21, Marriage 61-68 ordinal 22, VIP Visit 84-92 ordinal 30",
    }, {
      "expr" = "m['djmOA72MinRoll'](25) != 62  or m['djmOA72MaxRoll'](25) != 65  or m['djmOA72MinRoll'](26) != 66  or m['djmOA72MaxRoll'](26) != 66  or m['djmOA72WarEvent'](25) != 26  or m['djmOA72WarEvent'](26) != 26  or m['djmOA72DisasterEvent'](26) != 12  or m['djmOA72OtherEvent'](26) != 22",
      "note" = "the duplicate rows - 62-65 and 66 both Recruiting, Flooding, Marriage in the print",
    }, {
      "expr" = "m['djmOA72WarEvent'](33) != 23  or m['djmOA72WarEvent'](32) != 29  or m['djmOA72OtherEvent'](32) != 29  or m['djmOA72MinRoll'](33) != 81  or m['djmOA72OtherEvent'](37) != 23  or m['djmOA72MinRoll'](37) != 93  or m['djmOA72DisasterEvent'](39) != 23",
      "note" = "the No Event thresholds - war 81, disaster 95, other 93; Vengeful Stranger 79-80 ordinal 29 in war and other",
    }, {
      "expr" = "m['djmOA72MinRoll'](1) !=m['djmOA72MaxRoll'](0) + 1  or m['djmOA72MinRoll'](2) !=m['djmOA72MaxRoll'](1) + 1  or m['djmOA72MinRoll'](8) !=m['djmOA72MaxRoll'](7) + 1  or m['djmOA72MinRoll'](18) !=m['djmOA72MaxRoll'](17) + 1  or m['djmOA72MinRoll'](30) !=m['djmOA72MaxRoll'](29) + 1  or m['djmOA72MinRoll'](39) !=m['djmOA72MaxRoll'](38) + 1  or m['djmOA72MaxRoll'](39) != 100",
      "note" = "the contiguity - each row beginning where the last ended, the 100 the close",
    } },
  "audit" = {
      "label" = "R699 OA monthly events audit",
      "comment" = "OA round eighty-six (capture p. 238): Table 72 - the monthly events grid, the forty die-range rows across the three columns with the thirty event names and the contiguous ranges, single-pass pins per the Chapter 9 provenance shift",
    },
}
