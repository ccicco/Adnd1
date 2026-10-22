// =========================================================================================
// Adnd1 - rules/oa115table75.h
// OA TREASURE - TABLE 75, MAGICAL ARMOR, printed capture p. 289 - the armor
// type grid round
// census 666 -> 667.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 197 closed, 38 open - the Table 75 box
// flips (census 666 -> 667); NEXT - R745: Table 76. Magical Armor Properties
// (capture p. 289, the caption prints a period), prefix dlg (verify free at
// the landing), audit "R745 OA Table 76 properties audit", include after
// rules/oa115table75.h
//
namespace rules {

// ---- the Table 75 grid ----

// the armor row count - the twenty-three d100 bands of the Table 75 armor
// type grid (print capture p. 289)
inline int dlfArmorRowCount()
    { return 23; }

// the d100 band minimum - the low roll of the row (print capture p. 289)
inline int dlfArmorRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 13;
        case 4:
            return 17;
        case 5:
            return 18;
        case 6:
            return 23;
        case 7:
            return 27;
        case 8:
            return 31;
        case 9:
            return 36;
        case 10:
            return 45;
        case 11:
            return 47;
        case 12:
            return 56;
        case 13:
            return 63;
        case 14:
            return 67;
        case 15:
            return 71;
        case 16:
            return 75;
        case 17:
            return 79;
        case 18:
            return 83;
        case 19:
            return 87;
        case 20:
            return 86;
        case 21:
            return 93;
        case 22:
            return 100;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row (print capture p. 289)
inline int dlfArmorRollMax(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 12;
        case 3:
            return 16;
        case 4:
            return 17;
        case 5:
            return 22;
        case 6:
            return 26;
        case 7:
            return 30;
        case 8:
            return 35;
        case 9:
            return 44;
        case 10:
            return 46;
        case 11:
            return 55;
        case 12:
            return 62;
        case 13:
            return 66;
        case 14:
            return 70;
        case 15:
            return 74;
        case 16:
            return 78;
        case 17:
            return 82;
        case 18:
            return 86;
        case 19:
            return 87;
        case 20:
            return 92;
        case 21:
            return 99;
        case 22:
            return 100;
        default:
            return 0;
        }
    }

// the armor type code - 1 the banded; 2 the buckler; 3 the chain; 4 the
// do-maru; 5 the haidate; 6 the hara-ate; 7 the hara-ate-gawa; 8 the
// haramaki; 9 the haramaki-do; 10 the hide; 11 the kote; 12 the leather; 13
// the o-yoroi; 14 the padded; 15 the ring; 16 the scale, leather; 17 the
// scale, metal; 18 the shield, large; 19 the shield, medium; 20 the sode,
// pair; 21 the splinted; 22 the studded; 23 the gajin armor of the DMG Armor
// and Shield Table (print capture p. 289)
inline int dlfArmorType(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        case 10:
            return 11;
        case 11:
            return 12;
        case 12:
            return 13;
        case 13:
            return 14;
        case 14:
            return 15;
        case 15:
            return 16;
        case 16:
            return 17;
        case 17:
            return 18;
        case 18:
            return 19;
        case 19:
            return 20;
        case 20:
            return 21;
        case 21:
            return 22;
        case 22:
            return 23;
        default:
            return 0;
        }
    }

// ---- the capture quirks ----

// the sode asterisk - the sode, pair row carrying the asterisk of the print
// (print capture p. 289)
inline int dlfSodePairAsterisk()
    { return 1; }

// the splinted overlap - the capture printing the 86-92 splinted band below
// the 87 sode row, an overlap with the 87 row (likely the 88-92 intended),
// pinned as printed (print capture p. 289)
inline int dlfSplintedOverlapMisprint()
    { return 1; }

// the gajin armor - the 100 row rolling on the DMG Armor and Shield Table,
// the capture misreading gaijin (print capture p. 289)
inline int dlfGajinArmorRollOnDMG()
    { return 1; }

}   // namespace rules
