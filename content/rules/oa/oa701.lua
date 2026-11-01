-- oa701: promoted from rules/oa73daily.h (the OA TABLE 73, printed capture pp. 247-248 - the daily events round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 701,
  "prefix" = "oa701",
  "banner" = {
      "title" = "OA TABLE 73, printed capture pp. 247-248 - the daily events round",
      "provenance" = "census 623 -> 624.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE GRID: the twenty-eight die-range rows of the daily events across the percentile die, the ranges contiguous and complete 1-100, each row read across the five location columns - the court, the city/town, the rural, the wilderness, the ocean. THE TWENTY-NINE NAMES by ordinal: Bandit Camp the 1; Bandits the 2; Becalmed the 3; Contest the 4; Crime the 5; Duel the 6; Entreaty the 7; Fire Small the 8; Haunting the 9; Illness the 10; Insult the 11; Invitation the 12; Kidnapping the 13; Land the 14; Maiden the 15; Monster the 16; Mystery the 17; No Event the 18; Nobles the 19; Pirates the 20; Plot the 21; Ruins the 22; Ship the 23; Shrine the 24; Special the 25; Storm the 26; Stranger the 27; Traveler the 28; VIP the 29. THE OPEN: the rows 01-50 No Event in all five columns, the first possible event at 51. THE FREQUENCY CHART: the events possible per day by location - court 0-1, city and town 0-1, rural 0-2, wilderness 0-3, sea and ocean 0-2; the roll on the column best fitting the location, the maximum rolled for the area (three die rolls in wilderness), many rolls no event. THE OCR REPAIR: the row 88 cell-drop resolved to Shrine/Ruins/Ship per the column bands. The grid codifies per the R431 calculus  the gap census after this round: 154 closed, 81 open - the Table 73 box flips (census 623 -> 624); NEXT - R702: the Daily Events prose and explanations (capture pp. 247-251), prefix djp (verify free at the landing), audit \"R702 OA daily events prose audit\", include after rules/oa73daily.h",
    },
  "consts" = { {
      "name" = "djoOA73RowCount",
      "value" = 28,
      "comment" = "the Table 73 row count - the twenty-eight die-range rows spanning the percentile die 1-100 (print capture pp. 247-248)",
    }, {
      "name" = "djoOA73NameCount",
      "value" = 29,
      "comment" = "the Table 73 event name count - the twenty-nine distinct daily events named across the five columns (print capture pp. 247-248)",
    }, {
      "name" = "djoOA73NoEventId",
      "value" = 18,
      "comment" = "the No Event ordinal - the eighteenth of the twenty-nine names, the rows 01-50 No Event in all five columns (print capture p. 247)",
    }, {
      "name" = "djoOA73NoEventMinRoll",
      "value" = 51,
      "comment" = "the first eventful roll - the rows 01-50 No Event, the first possible event at 51 (print capture p. 247)",
    }, {
      "name" = "djoOA73CourtMaxPerDay",
      "value" = 1,
      "comment" = "the court frequency - 0-1 events possible per day (print capture p. 247)",
    }, {
      "name" = "djoOA73CityMaxPerDay",
      "value" = 1,
      "comment" = "the city, town frequency - 0-1 events possible per day (print capture p. 247)",
    }, {
      "name" = "djoOA73RuralMaxPerDay",
      "value" = 2,
      "comment" = "the rural area frequency - 0-2 events possible per day (print capture p. 247)",
    }, {
      "name" = "djoOA73WildernessMaxPerDay",
      "value" = 3,
      "comment" = "the wilderness frequency - 0-3 events possible per day, the maximum number rolled for the area (print capture p. 247)",
    }, {
      "name" = "djoOA73OceanMaxPerDay",
      "value" = 2,
      "comment" = "the sea, ocean frequency - 0-2 events possible per day (print capture p. 247)",
    } },
  "bools" = { {
      "name" = "djoOA73ColumnByLocation",
      "value" = true,
      "comment" = "the daily roll - roll percentile dice on the column best fitting the current location for that day, the mountain pass Wilderness, the farmland Rural (print capture p. 247)",
    }, {
      "name" = "djoOA73RollTheMax",
      "value" = true,
      "comment" = "the area maximum - the maximum number of events rolled for in the area, in wilderness three die rolls made (print capture p. 247)",
    }, {
      "name" = "djoOA73ManyRollsNoEvent",
      "value" = true,
      "comment" = "the no-event common - many of the die rolls may result in no event, the rows 01-50 blank in every column (print capture p. 247)",
    } },
  "switches" = { {
      "name" = "djoOA73MinRoll",
      "values" = { 1, 51, 52, 54, 56, 61, 64, 66, 70, 71, 73, 78, 80, 81, 82, 83, 84, 85, 87, 88, 89, 91, 92, 93, 94, 95, 96, 99 },
      "default" = 0,
      "comment" = "the Table 73 minimum rolls by row ordinal (print capture pp. 247-248): 1, 51, 52, 54, 56, 61, 64, 66, 70, 71, 73, 78, 80, 81, 82, 83, 84, 85, 87, 88, 89, 91, 92, 93, 94, 95, 96, 99 - the twenty-eight rows contiguous 1-100",
    }, {
      "name" = "djoOA73MaxRoll",
      "values" = { 50, 51, 53, 55, 60, 63, 65, 69, 70, 72, 77, 79, 80, 81, 82, 83, 84, 86, 87, 88, 90, 91, 92, 93, 94, 95, 98, 100 },
      "default" = 0,
      "comment" = "the Table 73 maximum rolls by row ordinal (print capture pp. 247-248): 50, 51, 53, 55, 60, 63, 65, 69, 70, 72, 77, 79, 80, 81, 82, 83, 84, 86, 87, 88, 90, 91, 92, 93, 94, 95, 98, 100 - the 100 the close",
    }, {
      "name" = "djoOA73CourtEvent",
      "values" = { 18, 4, 4, 4, 4, 6, 6, 7, 10, 10, 12, 12, 15, 15, 15, 16, 21, 21, 25, 25, 25, 25, 29, 29, 29, 29, 29, 29 },
      "default" = 0,
      "comment" = "the court column event ordinals by row ordinal (print capture pp. 247-248): Contest 4; Duel 6; Entreaty 7; Illness 10; Invitation 12; Maiden 15; Monster 16; No Event 18; Plot 21; Special 25; VIP 29",
    }, {
      "name" = "djoOA73CityEvent",
      "values" = { 18, 6, 6, 6, 7, 8, 11, 11, 11, 12, 12, 13, 15, 15, 16, 16, 16, 29, 29, 29, 29, 29, 29, 29, 29, 18, 18, 18 },
      "default" = 0,
      "comment" = "the city/town column event ordinals by row ordinal (print capture pp. 247-248), the dashes the No Event: Duel 6; Entreaty 7; Fire Small 8; Insult 11; Invitation 12; Kidnapping 13; Maiden 15; Monster 16; No Event 18; VIP 29",
    }, {
      "name" = "djoOA73RuralEvent",
      "values" = { 18, 2, 2, 2, 2, 5, 5, 9, 9, 16, 16, 16, 16, 27, 27, 27, 24, 24, 24, 24, 17, 29, 29, 29, 29, 29, 18, 18 },
      "default" = 0,
      "comment" = "the rural column event ordinals by row ordinal (print capture pp. 247-248): Bandits 2; Crime 5; Haunting 9; Monster 16; Mystery 17; No Event 18; Shrine 24; Stranger 27; VIP 29",
    }, {
      "name" = "djoOA73WildEvent",
      "values" = { 18, 1, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 19, 22, 22, 22, 22, 22, 24, 24, 26, 26, 27, 28, 28, 28 },
      "default" = 0,
      "comment" = "the wilderness column event ordinals by row ordinal (print capture pp. 247-248), the row 88 OCR cell-drop resolved to Ruins per the column bands: Bandit Camp 1; Monster 16; No Event 18; Nobles 19; Ruins 22; Shrine 24; Storm 26; Stranger 27; Traveler 28",
    }, {
      "name" = "djoOA73OceanEvent",
      "values" = { 18, 3, 3, 16, 16, 16, 16, 16, 16, 16, 16, 20, 20, 20, 20, 20, 20, 20, 20, 23, 23, 23, 23, 26, 26, 26, 26, 14 },
      "default" = 0,
      "comment" = "the ocean column event ordinals by row ordinal (print capture pp. 247-248): Becalmed 3; Land 14; Monster 16; No Event 18; Pirates 20; Ship 23; Storm 26",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['djoOA73RowCount']() != 28  or m['djoOA73NameCount']() != 29  or m['djoOA73NoEventId']() != 18  or m['djoOA73NoEventMinRoll']() != 51  or m['djoOA73CourtMaxPerDay']() != 1  or m['djoOA73CityMaxPerDay']() != 1  or m['djoOA73RuralMaxPerDay']() != 2  or m['djoOA73WildernessMaxPerDay']() != 3  or m['djoOA73OceanMaxPerDay']() != 2  or  m['djoOA73ColumnByLocation']() != 1  or  m['djoOA73RollTheMax']() != 1  or  m['djoOA73ManyRollsNoEvent']() != 1",
      "note" = "",
    }, {
      "expr" = "m['djoOA73MinRoll'](0) != 1  or m['djoOA73MaxRoll'](0) != 50  or m['djoOA73CourtEvent'](0) != 18  or m['djoOA73CityEvent'](0) != 18  or m['djoOA73RuralEvent'](0) != 18  or m['djoOA73WildEvent'](0) != 18  or m['djoOA73OceanEvent'](0) != 18  or m['djoOA73MinRoll'](1) != 51  or m['djoOA73CourtEvent'](1) != 4  or m['djoOA73CityEvent'](1) != 6  or m['djoOA73RuralEvent'](1) != 2  or m['djoOA73WildEvent'](1) != 1  or m['djoOA73OceanEvent'](1) != 3",
      "note" = "the open - the rows 01-50 No Event ordinal 18 in all five columns, the first event at 51",
    }, {
      "expr" = "m['djoOA73CourtEvent'](22) != 29  or m['djoOA73CourtEvent'](27) != 29  or m['djoOA73CityEvent'](25) != 18  or m['djoOA73WildEvent'](25) != 28  or m['djoOA73WildEvent'](27) != 28  or m['djoOA73OceanEvent'](27) != 14  or m['djoOA73MaxRoll'](27) != 100",
      "note" = "the close - VIP 92-100 ordinal 29 in court, the city dashes No Event from 95, the Traveler 95-100, Land the 99-100",
    }, {
      "expr" = "m['djoOA73OceanEvent'](2) != 3  or m['djoOA73OceanEvent'](4) != 16  or m['djoOA73OceanEvent'](11) != 20  or m['djoOA73OceanEvent'](19) != 23  or m['djoOA73OceanEvent'](22) != 23  or m['djoOA73OceanEvent'](23) != 26  or m['djoOA73OceanEvent'](26) != 26  or m['djoOA73OceanEvent'](27) != 14",
      "note" = "the ocean bands - Becalmed 51-53 ordinal 3, Monster 54-77, Pirates 78-87 ordinal 20, Ship 88-92 ordinal 23, Storm 93-98, Land the lone close",
    }, {
      "expr" = "m['djoOA73WildEvent'](1) != 1  or m['djoOA73WildEvent'](2) != 16  or m['djoOA73WildEvent'](13) != 16  or m['djoOA73WildEvent'](14) != 19  or m['djoOA73WildEvent'](15) != 22  or m['djoOA73WildEvent'](19) != 22  or m['djoOA73WildEvent'](20) != 24  or m['djoOA73WildEvent'](21) != 24  or m['djoOA73WildEvent'](22) != 26  or m['djoOA73WildEvent'](24) != 27",
      "note" = "the wilderness bands - Bandit Camp the lone 51 ordinal 1, Monster 52-81, Nobles the lone 82 ordinal 19, Ruins 83-88 ordinal 22, Shrine 89-91 ordinal 24, Storm 92-93, Stranger the lone 94 ordinal 27",
    }, {
      "expr" = "m['djoOA73CourtEvent'](1) != 4  or m['djoOA73CourtEvent'](4) != 4  or m['djoOA73CourtEvent'](5) != 6  or m['djoOA73CourtEvent'](7) != 7  or m['djoOA73CourtEvent'](8) != 10  or m['djoOA73CourtEvent'](10) != 12  or m['djoOA73CourtEvent'](12) != 15  or m['djoOA73CourtEvent'](16) != 21  or m['djoOA73CourtEvent'](18) != 25",
      "note" = "the court bands - Contest 51-60 ordinal 4, Duel 61-65 ordinal 6, Entreaty 66-69 ordinal 7, Illness 70-72 ordinal 10, Invitation 73-79 ordinal 12, Maiden 80-83 ordinal 15, Plot 84-86 ordinal 21, Special 87-91 ordinal 25",
    }, {
      "expr" = "m['djoOA73RuralEvent'](1) != 2  or m['djoOA73RuralEvent'](4) != 2  or m['djoOA73RuralEvent'](6) != 5  or m['djoOA73RuralEvent'](8) != 9  or m['djoOA73RuralEvent'](9) != 16  or m['djoOA73RuralEvent'](15) != 27  or m['djoOA73RuralEvent'](16) != 24  or m['djoOA73RuralEvent'](19) != 24  or m['djoOA73RuralEvent'](20) != 17  or m['djoOA73RuralEvent'](24) != 29",
      "note" = "the rural bands - Bandits 51-60 ordinal 2, Crime 61-65 ordinal 5, Haunting 66-70 ordinal 9, Monster 71-80 ordinal 16, Stranger 81-83 ordinal 27, Shrine 84-88 ordinal 24, Mystery 89-90 ordinal 17, VIP 91-94 ordinal 29",
    }, {
      "expr" = "m['djoOA73CityEvent'](1) != 6  or m['djoOA73CityEvent'](3) != 6  or m['djoOA73CityEvent'](4) != 7  or m['djoOA73CityEvent'](5) != 8  or m['djoOA73CityEvent'](6) != 11  or m['djoOA73CityEvent'](8) != 11  or m['djoOA73CityEvent'](9) != 12  or m['djoOA73CityEvent'](11) != 13",
      "note" = "the city bands - Duel 51-55 ordinal 6, Entreaty 56-60 ordinal 7, Fire Small 61-63 ordinal 8, Insult 64-70 ordinal 11, Invitation 71-79 ordinal 12, Kidnapping 78-79 ordinal 13",
    }, {
      "expr" = "m['djoOA73CourtEvent'](19) != 25  or m['djoOA73CityEvent'](19) != 29  or m['djoOA73RuralEvent'](19) != 24  or m['djoOA73WildEvent'](19) != 22  or m['djoOA73OceanEvent'](19) != 23",
      "note" = "the row 88 OCR repair - Special 25 / VIP 29 / Shrine 24 / Ruins 22 / Ship 23 read from the column bands",
    }, {
      "expr" = "m['djoOA73CourtMaxPerDay']() != 1  or m['djoOA73CityMaxPerDay']() != 1  or m['djoOA73RuralMaxPerDay']() != 2  or m['djoOA73WildernessMaxPerDay']() != 3  or m['djoOA73OceanMaxPerDay']() != 2  or m['djoOA73ColumnByLocation']() != 1  or m['djoOA73RollTheMax']() != 1  or m['djoOA73ManyRollsNoEvent']() != 1",
      "note" = "the frequency chart - the 1/1/2/3/2 events per day, the column by location, the max rolled, the common no-event",
    }, {
      "expr" = "m['djoOA73MinRoll'](1) !=m['djoOA73MaxRoll'](0) + 1  or m['djoOA73MinRoll'](5) !=m['djoOA73MaxRoll'](4) + 1  or m['djoOA73MinRoll'](12) !=m['djoOA73MaxRoll'](11) + 1  or m['djoOA73MinRoll'](18) !=m['djoOA73MaxRoll'](17) + 1  or m['djoOA73MinRoll'](27) !=m['djoOA73MaxRoll'](26) + 1  or m['djoOA73MaxRoll'](27) != 100",
      "note" = "the contiguity - each row beginning where the last ended, the 100 the close",
    } },
  "audit" = {
      "label" = "R701 OA daily events audit",
      "comment" = "OA round eighty-eight (capture pp. 247-248): Table 73 - the daily events grid, the twenty-eight die-range rows across the five location columns with the twenty-nine event names, plus the frequency chart, single-pass pins per the Chapter 9 provenance shift",
    },
}
