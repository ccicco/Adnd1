// =========================================================================================
// Adnd1 - rules/oa130table86.h
// OA TREASURE - TABLE 86, ORIENTAL MAGICAL ITEMS, printed capture pp. 296-297
// - the item grid round
// census 681 -> 682.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 212 closed, 23 open - the Table 86 box
// flips (census 681 -> 682); CHAPTER 13 COMPLETE - NEXT - R760: Chapter 14 An
// Overview of Kara-Tur, the chapter intro and the Population prose (capture
// pp. 301-302), prefix dlv (verify free at the landing), audit "R760 OA
// Kara-Tur overview audit", include after rules/oa130table86.h - the setting
// chapter, advisory prose closing on doctrine pins
//
namespace rules {

// ---- the Table 86 grid ----

// the item row count - the thirty-four d100 bands of the Table 86 magical
// item grid (print capture p. 296)
inline int dluItemRowCount()
    { return 34; }

// the d100 band minimum - the low roll of the row (print capture p. 296)
inline int dluItemRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 9;
        case 3:
            return 12;
        case 4:
            return 13;
        case 5:
            return 14;
        case 6:
            return 16;
        case 7:
            return 21;
        case 8:
            return 25;
        case 9:
            return 28;
        case 10:
            return 32;
        case 11:
            return 33;
        case 12:
            return 34;
        case 13:
            return 36;
        case 14:
            return 37;
        case 15:
            return 38;
        case 16:
            return 42;
        case 17:
            return 45;
        case 18:
            return 46;
        case 19:
            return 48;
        case 20:
            return 49;
        case 21:
            return 52;
        case 22:
            return 54;
        case 23:
            return 59;
        case 24:
            return 61;
        case 25:
            return 64;
        case 26:
            return 71;
        case 27:
            return 72;
        case 28:
            return 73;
        case 29:
            return 86;
        case 30:
            return 88;
        case 31:
            return 93;
        case 32:
            return 95;
        case 33:
            return 91;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row, the wondrous writing set
// printing the 91-100 of the overlap quirk (print capture p. 297)
inline int dluItemRollMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 8;
        case 2:
            return 11;
        case 3:
            return 12;
        case 4:
            return 13;
        case 5:
            return 15;
        case 6:
            return 20;
        case 7:
            return 24;
        case 8:
            return 27;
        case 9:
            return 31;
        case 10:
            return 32;
        case 11:
            return 33;
        case 12:
            return 35;
        case 13:
            return 36;
        case 14:
            return 37;
        case 15:
            return 41;
        case 16:
            return 44;
        case 17:
            return 45;
        case 18:
            return 47;
        case 19:
            return 48;
        case 20:
            return 51;
        case 21:
            return 53;
        case 22:
            return 58;
        case 23:
            return 60;
        case 24:
            return 63;
        case 25:
            return 70;
        case 26:
            return 71;
        case 27:
            return 72;
        case 28:
            return 85;
        case 29:
            return 87;
        case 30:
            return 92;
        case 31:
            return 94;
        case 32:
            return 96;
        case 33:
            return 100;
        default:
            return 0;
        }
    }

// the magical item code - 1 the banner of protection; 2 the bell of
// protection; 3 the bell of warning; 4 the biwa of calm; 5 the biwa of charm;
// 6 the biwa of discord; 7 the charm of protection from disease; 8 the charm
// of protection from fire; 9 the charm of protection from spirits; 10 the
// charm of protection from theft; 11 the diamond mace; 12 the drums of
// thunder; 13 the eight diagram coins; 14 the everproducing rice mortar; 15
// the gem of wishes; 16 the gong of dispelling; 17 the mallet of luck; 18 the
// minyan (shukenja, sohei); 19 the mirror of curing; 20 the mirror of
// enlightenment; 21 the mirror of fear; 22 the mirror of spirit seeing; 23
// the net of spirit snaring (shukenja); 24 the noisome spirit chasers; 25 the
// paper of forms; 26 the pearl of protection from fire; 27 the pearl of the
// ebbing tide; 28 the pearl of the rising tide; 29 the scroll of protection
// from spirits; 30 the seal of deception (ninja, yakuza); 31 the seal of
// vigor; 32 the tablet of spirit summoning (shukenja, wu jen); 33 the wheels
// of fire; 34 the wondrous writing set - the capture printing the 91-100
// against the 95-96 wheels, the overlapping band pinned as printed, almost
// certainly the 97-100 intended (print capture p. 297)
inline int dluItemCode(int b)
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
        case 23:
            return 24;
        case 24:
            return 25;
        case 25:
            return 26;
        case 26:
            return 27;
        case 27:
            return 28;
        case 28:
            return 29;
        case 29:
            return 30;
        case 30:
            return 31;
        case 31:
            return 32;
        case 32:
            return 33;
        case 33:
            return 34;
        default:
            return 0;
        }
    }

// ---- the quirks ----

// the page break - the grid opening on the one page and running onto the next
// (print capture p. 297)
inline int dluPageBreakGrid()
    { return 1; }

// the overlap quirk - the capture printing the 95-96 wheels of fire and then
// the 91-100 wondrous writing set, the overlapping bands pinned as printed,
// almost certainly the 97-100 intended (print capture p. 297)
inline int dluOverlapQuirk()
    { return 1; }

// the class-restricted items - the minyan of the shukenja and sohei, the net
// of the shukenja, the seal of the ninja and yakuza, the tablet of the
// shukenja and wu jen (print capture p. 297)
inline int dluClassRestrictedItems()
    { return 1; }

// the wide bands - the 73-85 scroll the widest, the 64-70 pearl and the 16-20
// charm following (print capture p. 297)
inline int dluWideBands()
    { return 1; }

}   // namespace rules
