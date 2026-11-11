-- oa696: promoted from rules/oa/oacalendar.h (the OA THE CALENDAR, printed capture pp. 236-237 - the months and festivals);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 696,
  "prefix" = "oa696",
  "banner" = {
      "title" = "OA THE CALENDAR, printed capture pp. 236-237 - the months and festivals",
      "provenance" = "round census 618 -> 619.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE CALENDAR: devised in ancient times by one of the great emperors of Shou Lung to fix the regular holidays and festivals, a success used throughout all the civilized lands of Kara-Tur, the first of the year falling sometime in modern-day February or March. THE TWELVE MONTHS with their days and festival counts: Tsou the 30 of eight observances - the New Year's Festival, the God of Heaven, the Feast of Lanterns, the God of Spring, the God of Wealth, the Fertility Festival, the God of Happiness, the God of Learning; Ju the 30 of the God of North and the Goddess of Mercy; Yu the 30 of the God of Central Mound, the Queen of Heaven, the Cherry Blossom Festival; Kao the 30 of the God of Medicine and the God of South; Kao II the 29 of the Thunder God, the Dragon Boat Festival, the God of War; Chu the 30 with none printed; Hsiang the 29 of the God of Fire and the Purification Festival; Chuang the 30 of the Moon Feast Festival, the God of Land and Grain, the God of Furnace, the Great Sage's Birthday; Hsuan the 30 of the Wine God, the Yang Feast, the Polar Gods, the God of Wealth; Yang the 29 of the God of Disease; Ku the 30 with none printed; Tu the 29 of the Kings' Festival. THE YEAR: eight months of 30 days and four of 29 - Kao II, Hsiang, Yang and Tu - the 356-day year. THE OBSERVANCE KINDS: the festivals lasting several days to weeks; the feasts the banquet gatherings; the holy days observed or not per the religion of the area and the character of the inhabitants; the observances simple, the excuse for a feast. The calendar pins per the R431 calculus  the gap census after this round: 149 closed, 86 open - the Calendar box flips (census 618 -> 619); NEXT - R697: Table 71 the yearly events grid (capture p. 237), prefix djk (verify free at the landing), audit \"R697 OA yearly events audit\", include after rules/oa/oacalendar.h",
    },
  "consts" = { {
      "name" = "djjOACalendarRowCount",
      "value" = 12,
      "comment" = "the calendar month count - the twelve months of the Shou Lung calendar, the loop bound of the emitted grid audit (print capture pp. 236-237)",
    }, {
      "name" = "djjOAYearDays",
      "value" = 356,
      "comment" = "the calendar year length - the eight thirty-day months plus the four twenty-nine-day months total 356 days (print capture pp. 236-237)",
    } },
  "bools" = { {
      "name" = "djjOACalendarEmperorOrigin",
      "value" = true,
      "comment" = "the calendar origin - devised in ancient times by one of the great emperors of Shou Lung to fix the occurrence of the regular holidays and festivals (print capture p. 236)",
    }, {
      "name" = "djjOACalendarCommonUse",
      "value" = true,
      "comment" = "the calendar spread - highly successful and commonly used throughout all the civilized lands of Kara-Tur (print capture p. 236)",
    }, {
      "name" = "djjOANewYearFebMar",
      "value" = true,
      "comment" = "the new year - the first of the year falls sometime in modern-day February or March (print capture p. 236)",
    }, {
      "name" = "djjOAFestivalsLong",
      "value" = true,
      "comment" = "the festivals - celebrations lasting several days, possibly even weeks (print capture p. 237)",
    }, {
      "name" = "djjOAFeastsBanquets",
      "value" = true,
      "comment" = "the feasts - reasons to gather together for as sumptuous a banquet as can be afforded (print capture p. 237)",
    }, {
      "name" = "djjOAHolyDaysOptional",
      "value" = true,
      "comment" = "the holy days - may or may not be observed, depending greatly on the religion of the area and the character of the inhabitants (print capture p. 237)",
    }, {
      "name" = "djjOAObservancesSimple",
      "value" = true,
      "comment" = "the observances - simple, often used as an excuse to have a feast (print capture p. 237)",
    } },
  "switches" = { {
      "name" = "djjOAMonthDays",
      "values" = { 30, 30, 30, 30, 29, 30, 29, 30, 30, 29, 30, 29 },
      "default" = 0,
      "comment" = "the calendar days by month ordinal (print capture pp. 236-237): the 30 of Tsou, Ju, Yu, Kao, Chu, Chuang, Hsuan and Ku; the 29 of Kao II, Hsiang, Yang and Tu - the four short months spread across the year, the 356-day total",
    }, {
      "name" = "djjOAMonthFestivals",
      "values" = { 8, 2, 3, 2, 3, 0, 2, 4, 4, 1, 0, 1 },
      "default" = 0,
      "comment" = "the calendar festival counts by month ordinal (print capture pp. 236-237): Tsou 8 the richest - the New Year's Festival, God of Heaven, Feast of Lanterns, God of Spring, God of Wealth, Fertility Festival, God of Happiness, God of Learning; Ju 2, Yu 3, Kao 2, Kao II 3, Chu 0 - none printed, Hsiang 2, Chuang 4, Hsuan 4, Yang 1, Ku 0 - none printed, Tu 1 the Kings' Festival",
    } },
  "tables" = { {
      "name" = "djjOACalendarGrid",
      "tag" = "OACalendarData",
      "count" = "djjOACalendarRowCount",
      "col_default" = 0,
      "cols" = { "djjOAMonthDays", "djjOAMonthFestivals" },
      "col_comments" = { "the calendar days by month ordinal (print capture pp. 236-237): the 30 of Tsou, Ju, Yu, Kao, Chu, Chuang, Hsuan and Ku; the 29 of Kao II, Hsiang, Yang and Tu - the four short months spread across the year, the 356-day total", "the calendar festival counts by month ordinal (print capture pp. 236-237): Tsou 8 the richest - the New Year's Festival, God of Heaven, Feast of Lanterns, God of Spring, God of Wealth, Fertility Festival, God of Happiness, God of Learning; Ju 2, Yu 3, Kao 2, Kao II 3, Chu 0 - none printed, Hsiang 2, Chuang 4, Hsuan 4, Yang 1, Ku 0 - none printed, Tu 1 the Kings' Festival" },
      "data" = { { 30, 8 }, { 30, 2 }, { 30, 3 }, { 30, 2 }, { 29, 3 }, { 30, 0 }, { 29, 2 }, { 30, 4 }, { 30, 4 }, { 29, 1 }, { 30, 0 }, { 29, 1 } },
      "comment" = "the Shou Lung calendar - the twelve months with their day and festival counts (print capture pp. 236-237)",
      "audit_comment" = "the calendar grid - the twelve months across two columns",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['djjOACalendarRowCount']() != 12  or m['djjOAYearDays']() != 356  or  m['djjOACalendarEmperorOrigin']() != 1  or  m['djjOACalendarCommonUse']() != 1  or  m['djjOANewYearFebMar']() != 1  or  m['djjOAFestivalsLong']() != 1  or  m['djjOAFeastsBanquets']() != 1  or  m['djjOAHolyDaysOptional']() != 1  or  m['djjOAObservancesSimple']() != 1",
      "note" = "",
    }, {
      "expr" = "m['djjOAMonthDays'](0) != 30  or m['djjOAMonthDays'](1) != 30  or m['djjOAMonthDays'](3) != 30  or m['djjOAMonthDays'](5) != 30  or m['djjOAMonthDays'](7) != 30  or m['djjOAMonthDays'](8) != 30  or m['djjOAMonthDays'](10) != 30",
      "note" = "the 30-day months - Tsou, Ju, Yu, Kao, Chu, Chuang, Hsuan, Ku",
    }, {
      "expr" = "m['djjOAMonthDays'](4) != 29  or m['djjOAMonthDays'](6) != 29  or m['djjOAMonthDays'](9) != 29  or m['djjOAMonthDays'](11) != 29",
      "note" = "the 29-day months - Kao II, Hsiang, Yang, Tu",
    }, {
      "expr" = "m['djjOAMonthFestivals'](0) != 8  or m['djjOAMonthFestivals'](7) != 4  or m['djjOAMonthFestivals'](8) != 4",
      "note" = "the festival counts - Tsou the eight, Chuang and Hsuan the four",
    }, {
      "expr" = "m['djjOAMonthFestivals'](5) != 0  or m['djjOAMonthFestivals'](10) != 0  or m['djjOAMonthFestivals'](11) != 1",
      "note" = "the bare months - Chu and Ku with none printed, Tu the single Kings' Festival",
    }, {
      "expr" = "m['djjOAYearDays']() != 356  or m['djjOAMonthDays'](0) +m['djjOAMonthDays'](4) +m['djjOAMonthDays'](9) != 88",
      "note" = "the year length - the eight 30s plus the four 29s the 356",
    } },
  "audit" = {
      "label" = "R696 OA calendar audit",
      "comment" = "OA round eighty-three (capture p. 236): the Calendar - the twelve months of the Shou Lung emperor's calendar with their days and the festivals, feasts and holy days counted, single-pass pins per the Chapter 9 provenance shift",
    },
}
