// =========================================================================================
// Adnd1 - rules/oacalendar.h
// OA THE CALENDAR, printed capture pp. 236-237 - the months and festivals
// round
// census 618 -> 619.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE CALENDAR: devised in ancient times by one of the
// great emperors of Shou Lung to fix the regular holidays and festivals, a
// success used throughout all the civilized lands of Kara-Tur, the first of
// the year falling sometime in modern-day February or March. THE TWELVE
// MONTHS with their days and festival counts: Tsou the 30 of eight
// observances - the New Year's Festival, the God of Heaven, the Feast of
// Lanterns, the God of Spring, the God of Wealth, the Fertility Festival, the
// God of Happiness, the God of Learning; Ju the 30 of the God of North and
// the Goddess of Mercy; Yu the 30 of the God of Central Mound, the Queen of
// Heaven, the Cherry Blossom Festival; Kao the 30 of the God of Medicine and
// the God of South; Kao II the 29 of the Thunder God, the Dragon Boat
// Festival, the God of War; Chu the 30 with none printed; Hsiang the 29 of
// the God of Fire and the Purification Festival; Chuang the 30 of the Moon
// Feast Festival, the God of Land and Grain, the God of Furnace, the Great
// Sage's Birthday; Hsuan the 30 of the Wine God, the Yang Feast, the Polar
// Gods, the God of Wealth; Yang the 29 of the God of Disease; Ku the 30 with
// none printed; Tu the 29 of the Kings' Festival. THE YEAR: eight months of
// 30 days and four of 29 - Kao II, Hsiang, Yang and Tu - the 356-day year.
// THE OBSERVANCE KINDS: the festivals lasting several days to weeks; the
// feasts the banquet gatherings; the holy days observed or not per the
// religion of the area and the character of the inhabitants; the observances
// simple, the excuse for a feast. The calendar pins per the R431 calculus
//
// the gap census after this round: 149 closed, 86 open - the Calendar box
// flips (census 618 -> 619); NEXT - R697: Table 71 the yearly events grid
// (capture p. 237), prefix djk (verify free at the landing), audit "R697 OA
// yearly events audit", include after rules/oacalendar.h
//
namespace rules {

// ---- the calendar grid ----

// the calendar days by month ordinal (print capture pp. 236-237): the 30 of
// Tsou, Ju, Yu, Kao, Chu, Chuang, Hsuan and Ku; the 29 of Kao II, Hsiang,
// Yang and Tu - the four short months spread across the year, the 356-day
// total
inline int djjOAMonthDays(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 30;
        case 2:
            return 30;
        case 3:
            return 30;
        case 4:
            return 29;
        case 5:
            return 30;
        case 6:
            return 29;
        case 7:
            return 30;
        case 8:
            return 30;
        case 9:
            return 29;
        case 10:
            return 30;
        case 11:
            return 29;
        default:
            return 0;
        }
    }

// the calendar festival counts by month ordinal (print capture pp. 236-237):
// Tsou 8 the richest - the New Year's Festival, God of Heaven, Feast of
// Lanterns, God of Spring, God of Wealth, Fertility Festival, God of
// Happiness, God of Learning; Ju 2, Yu 3, Kao 2, Kao II 3, Chu 0 - none
// printed, Hsiang 2, Chuang 4, Hsuan 4, Yang 1, Ku 0 - none printed, Tu 1 the
// Kings' Festival
inline int djjOAMonthFestivals(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 1;
        default:
            return 0;
        }
    }

// the calendar month count - the twelve months of the Shou Lung calendar, the
// loop bound of the emitted grid audit (print capture pp. 236-237)
inline int djjOACalendarRowCount()
    { return 12; }

// the calendar year length - the eight thirty-day months plus the four
// twenty-nine-day months total 356 days (print capture pp. 236-237)
inline int djjOAYearDays()
    { return 356; }

// the calendar origin - devised in ancient times by one of the great emperors
// of Shou Lung to fix the occurrence of the regular holidays and festivals
// (print capture p. 236)
inline bool djjOACalendarEmperorOrigin()
    { return true; }

// the calendar spread - highly successful and commonly used throughout all
// the civilized lands of Kara-Tur (print capture p. 236)
inline bool djjOACalendarCommonUse()
    { return true; }

// the new year - the first of the year falls sometime in modern-day February
// or March (print capture p. 236)
inline bool djjOANewYearFebMar()
    { return true; }

// the festivals - celebrations lasting several days, possibly even weeks
// (print capture p. 237)
inline bool djjOAFestivalsLong()
    { return true; }

// the feasts - reasons to gather together for as sumptuous a banquet as can
// be afforded (print capture p. 237)
inline bool djjOAFeastsBanquets()
    { return true; }

// the holy days - may or may not be observed, depending greatly on the
// religion of the area and the character of the inhabitants (print capture p.
// 237)
inline bool djjOAHolyDaysOptional()
    { return true; }

// the observances - simple, often used as an excuse to have a feast (print
// capture p. 237)
inline bool djjOAObservancesSimple()
    { return true; }

}   // namespace rules
