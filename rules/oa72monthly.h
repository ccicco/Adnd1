// =========================================================================================
// Adnd1 - rules/oa72monthly.h
// OA TABLE 72, printed capture p. 238 - the monthly events round
// census 621 -> 622.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE GRID: the forty die-range rows of the monthly events
// across the percentile die, the ranges contiguous and complete 1-100, each
// row read across the three columns - the first for months of armed violence
// or its potential (war, uprisings, assassinations, political power plays),
// the second for natural disasters and their aftermaths (floods, typhoons,
// droughts, famines, plagues and the like), the third when all is right with
// the world. THE THIRTY NAMES by ordinal: Accident the 1; Bandit Activity the
// 2; Bad Harvest the 3; Bad Weather the 4; Birth the 5; Death the 6;
// Earthquake Minor the 7; Excessive Taxes the 8; Famous Person the 9; Fire
// Major the 10; Fire Minor the 11; Flooding the 12; Haunting the 13;
// Horrendous Monster the 14; Incursion Major the 15; Incursion Minor the 16;
// Injustice the 17; Landslide the 18; Maiden of Virtue the 19; Major Battle
// the 20; Maneater the 21; Marriage the 22; No Event the 23; Notorious
// Criminal the 24; Plague the 25; Recruiting the 26; Troop Movements the 27;
// Uprising the 28; Vengeful Stranger the 29; VIP Visit the 30. THE OPEN: the
// rows 01-05 Accident in all three columns, the rows 95-100 No Event in all
// three. THE USE: one event per month from the proper column steered by the
// yearly event, the DM noting each beside the month, free to substitute and
// to add beyond the list. The grid codifies per the R431 calculus
//
// the gap census after this round: 152 closed, 83 open - the Table 72 box
// flips (census 621 -> 622); NEXT - R700: the Monthly Events prose and
// explanations (capture pp. 238-247), prefix djn (verify free at the
// landing), audit "R700 OA monthly events prose audit", include after
// rules/oa72monthly.h
//
namespace rules {

// ---- the Table 72 monthly events grid ----

// the Table 72 minimum rolls by row ordinal (print capture p. 238): 1, 6, 8,
// 11, 16, 21, 23, 26, 28, 29, 31, 33, 34, 36, 38, 41, 42, 44, 45, 50, 51, 52,
// 55, 56, 61, 62, 66, 67, 69, 70, 72, 74, 79, 81, 83, 84, 88, 93, 94, 95 -
// the forty rows contiguous 1-100
inline int djmOA72MinRoll(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 11;
        case 4:
            return 16;
        case 5:
            return 21;
        case 6:
            return 23;
        case 7:
            return 26;
        case 8:
            return 28;
        case 9:
            return 29;
        case 10:
            return 31;
        case 11:
            return 33;
        case 12:
            return 34;
        case 13:
            return 36;
        case 14:
            return 38;
        case 15:
            return 41;
        case 16:
            return 42;
        case 17:
            return 44;
        case 18:
            return 45;
        case 19:
            return 50;
        case 20:
            return 51;
        case 21:
            return 52;
        case 22:
            return 55;
        case 23:
            return 56;
        case 24:
            return 61;
        case 25:
            return 62;
        case 26:
            return 66;
        case 27:
            return 67;
        case 28:
            return 69;
        case 29:
            return 70;
        case 30:
            return 72;
        case 31:
            return 74;
        case 32:
            return 79;
        case 33:
            return 81;
        case 34:
            return 83;
        case 35:
            return 84;
        case 36:
            return 88;
        case 37:
            return 93;
        case 38:
            return 94;
        case 39:
            return 95;
        default:
            return 0;
        }
    }

// the Table 72 maximum rolls by row ordinal (print capture p. 238): 5, 7, 10,
// 15, 20, 22, 25, 27, 28, 30, 32, 33, 35, 37, 40, 41, 43, 44, 49, 50, 51, 54,
// 55, 60, 61, 65, 66, 68, 69, 71, 73, 78, 80, 82, 83, 87, 92, 93, 94, 100 -
// the 100 the close
inline int djmOA72MaxRoll(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 7;
        case 2:
            return 10;
        case 3:
            return 15;
        case 4:
            return 20;
        case 5:
            return 22;
        case 6:
            return 25;
        case 7:
            return 27;
        case 8:
            return 28;
        case 9:
            return 30;
        case 10:
            return 32;
        case 11:
            return 33;
        case 12:
            return 35;
        case 13:
            return 37;
        case 14:
            return 40;
        case 15:
            return 41;
        case 16:
            return 43;
        case 17:
            return 44;
        case 18:
            return 49;
        case 19:
            return 50;
        case 20:
            return 51;
        case 21:
            return 54;
        case 22:
            return 55;
        case 23:
            return 60;
        case 24:
            return 61;
        case 25:
            return 65;
        case 26:
            return 66;
        case 27:
            return 68;
        case 28:
            return 69;
        case 29:
            return 71;
        case 30:
            return 73;
        case 31:
            return 78;
        case 32:
            return 80;
        case 33:
            return 82;
        case 34:
            return 83;
        case 35:
            return 87;
        case 36:
            return 92;
        case 37:
            return 93;
        case 38:
            return 94;
        case 39:
            return 100;
        default:
            return 0;
        }
    }

// the war column event ordinals by row ordinal (print capture p. 238), the
// months of armed violence or its potential: Accident 1; Bandit Activity 2;
// Birth 5; Death 6; Excessive Taxes 8; Famous Person 9; Fire Major 10;
// Haunting 13; Horrendous Monster 14; Incursion Major 15; Incursion Minor 16;
// Injustice 17; Major Battle 20; No Event 23; Notorious Criminal 24;
// Recruiting 26; Troop Movements 27; Uprising 28; Vengeful Stranger 29
inline int djmOA72WarEvent(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 8;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 13;
        case 10:
            return 14;
        case 11:
            return 14;
        case 12:
            return 15;
        case 13:
            return 15;
        case 14:
            return 15;
        case 15:
            return 15;
        case 16:
            return 16;
        case 17:
            return 16;
        case 18:
            return 16;
        case 19:
            return 16;
        case 20:
            return 16;
        case 21:
            return 17;
        case 22:
            return 20;
        case 23:
            return 20;
        case 24:
            return 24;
        case 25:
            return 26;
        case 26:
            return 26;
        case 27:
            return 27;
        case 28:
            return 27;
        case 29:
            return 27;
        case 30:
            return 28;
        case 31:
            return 28;
        case 32:
            return 29;
        case 33:
            return 23;
        case 34:
            return 23;
        case 35:
            return 23;
        case 36:
            return 23;
        case 37:
            return 23;
        case 38:
            return 23;
        case 39:
            return 23;
        default:
            return 0;
        }
    }

// the natural disaster column event ordinals by row ordinal (print capture p.
// 238), the months of disasters and their aftermaths: Accident 1; Bad Harvest
// 3; Bad Weather 4; Bandit Activity 2; Birth 5; Death 6; Earthquake Minor 7;
// Excessive Taxes 8; Fire Minor 11; Flooding 12; Haunting 13; Horrendous
// Monster 14; Injustice 17; Landslide 18; Maneater 21; No Event 23; Plague
// 25; Uprising 28; VIP Visit 30
inline int djmOA72DisasterEvent(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 5;
        case 12:
            return 5;
        case 13:
            return 5;
        case 14:
            return 6;
        case 15:
            return 6;
        case 16:
            return 6;
        case 17:
            return 6;
        case 18:
            return 7;
        case 19:
            return 8;
        case 20:
            return 8;
        case 21:
            return 8;
        case 22:
            return 11;
        case 23:
            return 11;
        case 24:
            return 12;
        case 25:
            return 12;
        case 26:
            return 12;
        case 27:
            return 13;
        case 28:
            return 13;
        case 29:
            return 14;
        case 30:
            return 14;
        case 31:
            return 17;
        case 32:
            return 18;
        case 33:
            return 18;
        case 34:
            return 21;
        case 35:
            return 21;
        case 36:
            return 25;
        case 37:
            return 28;
        case 38:
            return 30;
        case 39:
            return 23;
        default:
            return 0;
        }
    }

// the other column event ordinals by row ordinal (print capture p. 238), the
// months when all is right with the world: Accident 1; Bad Harvest 3; Bad
// Weather 4; Bandit Activity 2; Birth 5; Death 6; Famous Person 9; Fire Minor
// 11; Haunting 13; Injustice 17; Maiden of Virtue 19; Maneater 21; Marriage
// 22; No Event 23; Notorious Criminal 24; VIP Visit 30; Vengeful Stranger 29
inline int djmOA72OtherEvent(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 2;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 9;
        case 11:
            return 9;
        case 12:
            return 9;
        case 13:
            return 11;
        case 14:
            return 11;
        case 15:
            return 13;
        case 16:
            return 13;
        case 17:
            return 17;
        case 18:
            return 17;
        case 19:
            return 17;
        case 20:
            return 19;
        case 21:
            return 19;
        case 22:
            return 19;
        case 23:
            return 21;
        case 24:
            return 22;
        case 25:
            return 22;
        case 26:
            return 22;
        case 27:
            return 22;
        case 28:
            return 24;
        case 29:
            return 24;
        case 30:
            return 24;
        case 31:
            return 24;
        case 32:
            return 29;
        case 33:
            return 29;
        case 34:
            return 29;
        case 35:
            return 30;
        case 36:
            return 30;
        case 37:
            return 23;
        case 38:
            return 23;
        case 39:
            return 23;
        default:
            return 0;
        }
    }

// the Table 72 row count - the forty die-range rows spanning the percentile
// die 1-100 (print capture p. 238)
inline int djmOA72RowCount()
    { return 40; }

// the Table 72 event name count - the thirty distinct monthly events named
// across the three columns (print capture p. 238)
inline int djmOA72NameCount()
    { return 30; }

// the No Event ordinal - the twenty-third of the thirty names, the rows
// 95-100 No Event in all three columns (print capture p. 238)
inline int djmOA72NoEventId()
    { return 23; }

// the Accident ordinal - the first of the thirty names, the rows 01-05
// Accident in all three columns (print capture p. 238)
inline int djmOA72AccidentId()
    { return 1; }

// ---- the No Event stretches ----

// the war column No Event start - the rolls 81-100 No Event in the months of
// armed violence or its potential (print capture p. 238)
inline int djmOA72WarNoEventMin()
    { return 81; }

// the war column No Event close - the No Event stretch ending the first
// column at 100 (print capture p. 238)
inline int djmOA72WarNoEventMax()
    { return 100; }

// the natural disaster column No Event start - the rolls 95-100 No Event in
// the aftermath months (print capture p. 238)
inline int djmOA72DisasterNoEventMin()
    { return 95; }

// the other column No Event start - the rolls 93-100 No Event when all is
// right with the world (print capture p. 238)
inline int djmOA72OtherNoEventMin()
    { return 93; }

// ---- the monthly use rules ----

// the monthly roll - one event determined per month from the proper column,
// the DM noting each beside the month on a sheet of paper (print capture pp.
// 238-239)
inline bool djmOA72OneEventPerMonth()
    { return true; }

// the column steering - the yearly event steering the column: the first for
// war, uprisings, assassinations and political power plays; the second for
// natural disasters and their aftermaths; the third when all is right with
// the world (print capture p. 239)
inline bool djmOA72YearlyEventSteersColumn()
    { return true; }

// the DM substitution - the DM free to change any event felt inappropriate,
// especially compared to the other events of the year, and encouraged to add
// creativity beyond the list (print capture p. 239)
inline bool djmOA72DMMaySubstitute()
    { return true; }

}   // namespace rules
