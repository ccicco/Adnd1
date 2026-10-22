// =========================================================================================
// Adnd1 - rules/oa108tableiii.h
// OA TREASURE - TABLE III. (ORIENT), MAGICAL ITEMS, printed capture p. 287 -
// the item draw round
// census 659 -> 660.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 190 closed, 45 open - the Table III box
// flips (census 659 -> 660); NEXT - R738: the Modifications to Standard
// Magical Items prose (capture p. 286), prefix dkz (verify free at the
// landing), audit "R738 OA standard item mods audit", include after
// rules/oa108tableiii.h
//
namespace rules {

// ---- the Table III grid ----

// the Table III row count - the twelve d100 bands of the Oriental magical
// items table (print capture p. 287)
inline int dkyRowCount()
    { return 12; }

// the d100 band minimum - the low roll of the row (print capture p. 287)
inline int dkyRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 36;
        case 3:
            return 41;
        case 4:
            return 46;
        case 5:
            return 48;
        case 6:
            return 50;
        case 7:
            return 52;
        case 8:
            return 54;
        case 9:
            return 56;
        case 10:
            return 61;
        case 11:
            return 76;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row (print capture p. 287)
inline int dkyRollMax(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 35;
        case 2:
            return 40;
        case 3:
            return 45;
        case 4:
            return 47;
        case 5:
            return 49;
        case 6:
            return 51;
        case 7:
            return 53;
        case 8:
            return 55;
        case 9:
            return 60;
        case 10:
            return 75;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// the category code - the potions 1, scrolls 2, rings 3, rods 4, misc magic
// 5, oriental 6, armor and shields 7, weapons 8 (print capture p. 287)
inline int dkyCat(int b)
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
            return 5;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 6;
        case 10:
            return 7;
        case 11:
            return 8;
        default:
            return 0;
        }
    }

// the subtable code - the IIIA 1, IIIB 2, IIIC 3, IIID 4, and the IIIE.1
// through IIIE.5 of the five misc bands, the 0 the none of the untabled rows
// (print capture p. 287)
inline int dkySub(int b)
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
            return 1;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

// ---- the category codes ----

// the potions category - the 01-10 band of the DMG Table III.A. (print
// capture p. 287)
inline int dkyCatPotions()
    { return 1; }

// the scrolls category - the 11-35 band of the DMG Table III.B. (print
// capture p. 287)
inline int dkyCatScrolls()
    { return 2; }

// the rings category - the 36-40 band of the DMG Table III.C. (print capture
// p. 287)
inline int dkyCatRings()
    { return 3; }

// the rods, staves, and wands category - the 41-45 band of the DMG Table
// III.D. (print capture p. 287)
inline int dkyCatRods()
    { return 4; }

// the miscellaneous magic category - the five IIIE bands of the DMG Table
// III.E.1 through III.E.5 (print capture p. 287)
inline int dkyCatMiscMagic()
    { return 5; }

// the oriental magical items category - the 56-60 band of this book (print
// capture p. 287)
inline int dkyCatOriental()
    { return 6; }

// the armor and shields category - the 61-75 band, the capture misreading 8
// for the and of the Armor & Shields (print capture p. 287)
inline int dkyCatArmorShields()
    { return 7; }

// the magical weapons category - the 76-100 band (print capture p. 287)
inline int dkyCatWeapons()
    { return 8; }

// ---- the bands ----

// the potions band - the 01-10 roll of the IIIA subtable (print capture p.
// 287)
inline int dkyBandPotions()
    { return 1; }

// the scrolls band - the 11-35 roll of the IIIB subtable (print capture p.
// 287)
inline int dkyBandScrolls()
    { return 1; }

// the rings band - the 36-40 roll of the IIIC subtable (print capture p. 287)
inline int dkyBandRings()
    { return 1; }

// the rods, staves, and wands band - the 41-45 roll of the IIID subtable
// (print capture p. 287)
inline int dkyBandRods()
    { return 1; }

// the misc magic bands - the five 46-55 sub-bands of the IIIE.1 through
// IIIE.5 subtables (print capture p. 287)
inline int dkyBandMiscMagic()
    { return 1; }

// the oriental items band - the 56-60 roll of the Table 86 items of this book
// (print capture p. 287)
inline int dkyBandOriental()
    { return 1; }

// the armor and shields band - the 61-75 roll, the capture misreading the 8
// for the & (print capture p. 287)
inline int dkyBandArmorShields()
    { return 1; }

// the magical weapons band - the 76-100 roll (print capture p. 287)
inline int dkyBandWeapons()
    { return 1; }

// ---- the footnote ----

// the DMG first page - the 121 of the footnote, the parentheses referring to
// the DMG tables of the pages 121-124 (print capture p. 287)
inline int dkyDMGPageFirst()
    { return 121; }

// the DMG last page - the 124 of the footnote (print capture p. 287)
inline int dkyDMGPageLast()
    { return 124; }

// the footnote - the parentheses referring to the tables in the DMG, the
// pages 121-124 (print capture p. 287)
inline int dkyFootnoteDMGTables()
    { return 1; }

}   // namespace rules
