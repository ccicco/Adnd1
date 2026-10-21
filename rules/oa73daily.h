// =========================================================================================
// Adnd1 - rules/oa73daily.h
// OA TABLE 73, printed capture pp. 247-248 - the daily events round
// census 623 -> 624.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE GRID: the twenty-eight die-range rows of the daily
// events across the percentile die, the ranges contiguous and complete 1-100,
// each row read across the five location columns - the court, the city/town,
// the rural, the wilderness, the ocean. THE TWENTY-NINE NAMES by ordinal:
// Bandit Camp the 1; Bandits the 2; Becalmed the 3; Contest the 4; Crime the
// 5; Duel the 6; Entreaty the 7; Fire Small the 8; Haunting the 9; Illness
// the 10; Insult the 11; Invitation the 12; Kidnapping the 13; Land the 14;
// Maiden the 15; Monster the 16; Mystery the 17; No Event the 18; Nobles the
// 19; Pirates the 20; Plot the 21; Ruins the 22; Ship the 23; Shrine the 24;
// Special the 25; Storm the 26; Stranger the 27; Traveler the 28; VIP the 29.
// THE OPEN: the rows 01-50 No Event in all five columns, the first possible
// event at 51. THE FREQUENCY CHART: the events possible per day by location -
// court 0-1, city and town 0-1, rural 0-2, wilderness 0-3, sea and ocean 0-2;
// the roll on the column best fitting the location, the maximum rolled for
// the area (three die rolls in wilderness), many rolls no event. THE OCR
// REPAIR: the row 88 cell-drop resolved to Shrine/Ruins/Ship per the column
// bands. The grid codifies per the R431 calculus
//
// the gap census after this round: 154 closed, 81 open - the Table 73 box
// flips (census 623 -> 624); NEXT - R702: the Daily Events prose and
// explanations (capture pp. 247-251), prefix djp (verify free at the
// landing), audit "R702 OA daily events prose audit", include after
// rules/oa73daily.h
//
namespace rules {

// ---- the Table 73 daily events grid ----

// the Table 73 minimum rolls by row ordinal (print capture pp. 247-248): 1,
// 51, 52, 54, 56, 61, 64, 66, 70, 71, 73, 78, 80, 81, 82, 83, 84, 85, 87, 88,
// 89, 91, 92, 93, 94, 95, 96, 99 - the twenty-eight rows contiguous 1-100
inline int djoOA73MinRoll(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 51;
        case 2:
            return 52;
        case 3:
            return 54;
        case 4:
            return 56;
        case 5:
            return 61;
        case 6:
            return 64;
        case 7:
            return 66;
        case 8:
            return 70;
        case 9:
            return 71;
        case 10:
            return 73;
        case 11:
            return 78;
        case 12:
            return 80;
        case 13:
            return 81;
        case 14:
            return 82;
        case 15:
            return 83;
        case 16:
            return 84;
        case 17:
            return 85;
        case 18:
            return 87;
        case 19:
            return 88;
        case 20:
            return 89;
        case 21:
            return 91;
        case 22:
            return 92;
        case 23:
            return 93;
        case 24:
            return 94;
        case 25:
            return 95;
        case 26:
            return 96;
        case 27:
            return 99;
        default:
            return 0;
        }
    }

// the Table 73 maximum rolls by row ordinal (print capture pp. 247-248): 50,
// 51, 53, 55, 60, 63, 65, 69, 70, 72, 77, 79, 80, 81, 82, 83, 84, 86, 87, 88,
// 90, 91, 92, 93, 94, 95, 98, 100 - the 100 the close
inline int djoOA73MaxRoll(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 51;
        case 2:
            return 53;
        case 3:
            return 55;
        case 4:
            return 60;
        case 5:
            return 63;
        case 6:
            return 65;
        case 7:
            return 69;
        case 8:
            return 70;
        case 9:
            return 72;
        case 10:
            return 77;
        case 11:
            return 79;
        case 12:
            return 80;
        case 13:
            return 81;
        case 14:
            return 82;
        case 15:
            return 83;
        case 16:
            return 84;
        case 17:
            return 86;
        case 18:
            return 87;
        case 19:
            return 88;
        case 20:
            return 90;
        case 21:
            return 91;
        case 22:
            return 92;
        case 23:
            return 93;
        case 24:
            return 94;
        case 25:
            return 95;
        case 26:
            return 98;
        case 27:
            return 100;
        default:
            return 0;
        }
    }

// the court column event ordinals by row ordinal (print capture pp. 247-248):
// Contest 4; Duel 6; Entreaty 7; Illness 10; Invitation 12; Maiden 15;
// Monster 16; No Event 18; Plot 21; Special 25; VIP 29
inline int djoOA73CourtEvent(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 6;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 10;
        case 9:
            return 10;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 15;
        case 13:
            return 15;
        case 14:
            return 15;
        case 15:
            return 16;
        case 16:
            return 21;
        case 17:
            return 21;
        case 18:
            return 25;
        case 19:
            return 25;
        case 20:
            return 25;
        case 21:
            return 25;
        case 22:
            return 29;
        case 23:
            return 29;
        case 24:
            return 29;
        case 25:
            return 29;
        case 26:
            return 29;
        case 27:
            return 29;
        default:
            return 0;
        }
    }

// the city/town column event ordinals by row ordinal (print capture pp.
// 247-248), the dashes the No Event: Duel 6; Entreaty 7; Fire Small 8; Insult
// 11; Invitation 12; Kidnapping 13; Maiden 15; Monster 16; No Event 18; VIP
// 29
inline int djoOA73CityEvent(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 11;
        case 7:
            return 11;
        case 8:
            return 11;
        case 9:
            return 12;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 15;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 16;
        case 16:
            return 16;
        case 17:
            return 29;
        case 18:
            return 29;
        case 19:
            return 29;
        case 20:
            return 29;
        case 21:
            return 29;
        case 22:
            return 29;
        case 23:
            return 29;
        case 24:
            return 29;
        case 25:
            return 18;
        case 26:
            return 18;
        case 27:
            return 18;
        default:
            return 0;
        }
    }

// the rural column event ordinals by row ordinal (print capture pp. 247-248):
// Bandits 2; Crime 5; Haunting 9; Monster 16; Mystery 17; No Event 18; Shrine
// 24; Stranger 27; VIP 29
inline int djoOA73RuralEvent(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 9;
        case 8:
            return 9;
        case 9:
            return 16;
        case 10:
            return 16;
        case 11:
            return 16;
        case 12:
            return 16;
        case 13:
            return 27;
        case 14:
            return 27;
        case 15:
            return 27;
        case 16:
            return 24;
        case 17:
            return 24;
        case 18:
            return 24;
        case 19:
            return 24;
        case 20:
            return 17;
        case 21:
            return 29;
        case 22:
            return 29;
        case 23:
            return 29;
        case 24:
            return 29;
        case 25:
            return 29;
        case 26:
            return 18;
        case 27:
            return 18;
        default:
            return 0;
        }
    }

// the wilderness column event ordinals by row ordinal (print capture pp.
// 247-248), the row 88 OCR cell-drop resolved to Ruins per the column bands:
// Bandit Camp 1; Monster 16; No Event 18; Nobles 19; Ruins 22; Shrine 24;
// Storm 26; Stranger 27; Traveler 28
inline int djoOA73WildEvent(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 1;
        case 2:
            return 16;
        case 3:
            return 16;
        case 4:
            return 16;
        case 5:
            return 16;
        case 6:
            return 16;
        case 7:
            return 16;
        case 8:
            return 16;
        case 9:
            return 16;
        case 10:
            return 16;
        case 11:
            return 16;
        case 12:
            return 16;
        case 13:
            return 16;
        case 14:
            return 19;
        case 15:
            return 22;
        case 16:
            return 22;
        case 17:
            return 22;
        case 18:
            return 22;
        case 19:
            return 22;
        case 20:
            return 24;
        case 21:
            return 24;
        case 22:
            return 26;
        case 23:
            return 26;
        case 24:
            return 27;
        case 25:
            return 28;
        case 26:
            return 28;
        case 27:
            return 28;
        default:
            return 0;
        }
    }

// the ocean column event ordinals by row ordinal (print capture pp. 247-248):
// Becalmed 3; Land 14; Monster 16; No Event 18; Pirates 20; Ship 23; Storm 26
inline int djoOA73OceanEvent(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 16;
        case 4:
            return 16;
        case 5:
            return 16;
        case 6:
            return 16;
        case 7:
            return 16;
        case 8:
            return 16;
        case 9:
            return 16;
        case 10:
            return 16;
        case 11:
            return 20;
        case 12:
            return 20;
        case 13:
            return 20;
        case 14:
            return 20;
        case 15:
            return 20;
        case 16:
            return 20;
        case 17:
            return 20;
        case 18:
            return 20;
        case 19:
            return 23;
        case 20:
            return 23;
        case 21:
            return 23;
        case 22:
            return 23;
        case 23:
            return 26;
        case 24:
            return 26;
        case 25:
            return 26;
        case 26:
            return 26;
        case 27:
            return 14;
        default:
            return 0;
        }
    }

// the Table 73 row count - the twenty-eight die-range rows spanning the
// percentile die 1-100 (print capture pp. 247-248)
inline int djoOA73RowCount()
    { return 28; }

// the Table 73 event name count - the twenty-nine distinct daily events named
// across the five columns (print capture pp. 247-248)
inline int djoOA73NameCount()
    { return 29; }

// the No Event ordinal - the eighteenth of the twenty-nine names, the rows
// 01-50 No Event in all five columns (print capture p. 247)
inline int djoOA73NoEventId()
    { return 18; }

// the first eventful roll - the rows 01-50 No Event, the first possible event
// at 51 (print capture p. 247)
inline int djoOA73NoEventMinRoll()
    { return 51; }

// ---- the daily frequency chart ----

// the court frequency - 0-1 events possible per day (print capture p. 247)
inline int djoOA73CourtMaxPerDay()
    { return 1; }

// the city, town frequency - 0-1 events possible per day (print capture p.
// 247)
inline int djoOA73CityMaxPerDay()
    { return 1; }

// the rural area frequency - 0-2 events possible per day (print capture p.
// 247)
inline int djoOA73RuralMaxPerDay()
    { return 2; }

// the wilderness frequency - 0-3 events possible per day, the maximum number
// rolled for the area (print capture p. 247)
inline int djoOA73WildernessMaxPerDay()
    { return 3; }

// the sea, ocean frequency - 0-2 events possible per day (print capture p.
// 247)
inline int djoOA73OceanMaxPerDay()
    { return 2; }

// the daily roll - roll percentile dice on the column best fitting the
// current location for that day, the mountain pass Wilderness, the farmland
// Rural (print capture p. 247)
inline bool djoOA73ColumnByLocation()
    { return true; }

// the area maximum - the maximum number of events rolled for in the area, in
// wilderness three die rolls made (print capture p. 247)
inline bool djoOA73RollTheMax()
    { return true; }

// the no-event common - many of the die rolls may result in no event, the
// rows 01-50 blank in every column (print capture p. 247)
inline bool djoOA73ManyRollsNoEvent()
    { return true; }

}   // namespace rules
