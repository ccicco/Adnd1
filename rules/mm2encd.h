// =========================================================================================
// Adnd1 - rules/mm2encd.h
// THE MM2 DUNGEON ENCOUNTER TABLES WALK - THE TEN MONSTER LEVEL GRIDS (pp.
// 133-134: the ten tables I through X, the 1d8+1d12 method, the
// character-party rows, and the unique-court rows of Level X), the
// DUNGEON-FLIP round - the Dungeon Random Encounter Tables gap box flips to
// closed
// census 738 -> 739.
//
// Round twenty-one of the MM2 arc, the first table-group round (Curtiss Go
// call on the landed R815 WXYZ walk; the pin-time walk found ten printed
// grids of 19 die rows each, no defs promoted - the registry stays 809)
//
// The pin header stays the print-fidelity record; the grids carry the die,
// source, number and special cells, the row rosters ride the audit comments,
// and the walk cross-checks the registry keys live
//
namespace rules {

// ---- the R816 census ----

// The MM2 dungeon encounter tables walk round: the ten monster level grids,
// the fourth table-group round (Curtiss Go call on the landed R815)
inline int mm2encdRound()
    { return 816; }

// The ten Monster Level tables (I through X)
inline int mm2encdTableCount()
    { return 10; }

// Every table carries the 19 die rows 2-20 (the 1d8+1d12 sum)
inline int mm2encdRowsPerTable()
    { return 19; }

// The 10 x 19 rows pinned across the ten grids
inline int mm2encdTotalRows()
    { return 190; }

// The lowest die roll on every table (1d8+1d12)
inline int mm2encdDieMin()
    { return 2; }

// The highest die roll on every table
inline int mm2encdDieMax()
    { return 20; }

// One character-party row per table (see the character subtable in the DMG)
inline int mm2encdCharacterPartyRows()
    { return 10; }

// The four unique-court rows (Level X dies 2, 3, 19 and 20)
inline int mm2encdUniqueCourtRows()
    { return 4; }

// The (MM1) rows across the ten tables
inline int mm2encdMm1SourceRows()
    { return 89; }

// The (MM2) rows across the ten tables
inline int mm2encdMm2SourceRows()
    { return 63; }

// The (FF) rows across the ten tables
inline int mm2encdFfSourceRows()
    { return 26; }

// The (ALL) rows (the Level X unique demon prince and devil duke rows)
inline int mm2encdAllSourceRows()
    { return 2; }

// The registry census floor (the landed R815 count; this round promotes no
// defs)
inline int mm2encdRegistryFloor()
    { return 809; }

// The character-party die on Monster Level I
inline int mm2encdPartyDieD1()
    { return 11; }

// The character-party die on Monster Level II
inline int mm2encdPartyDieD2()
    { return 11; }

// The character-party die on Monster Level III
inline int mm2encdPartyDieD3()
    { return 9; }

// The character-party die on Monster Level IV
inline int mm2encdPartyDieD4()
    { return 9; }

// The character-party die on Monster Level V
inline int mm2encdPartyDieD5()
    { return 10; }

// The character-party die on Monster Level VI
inline int mm2encdPartyDieD6()
    { return 11; }

// The character-party die on Monster Level VII
inline int mm2encdPartyDieD7()
    { return 9; }

// The character-party die on Monster Level VIII
inline int mm2encdPartyDieD8()
    { return 9; }

// The character-party die on Monster Level IX
inline int mm2encdPartyDieD9()
    { return 9; }

// The character-party die on Monster Level X
inline int mm2encdPartyDieD10()
    { return 13; }

// The 19 rows of the Monster Level I grid
inline int mm2encdD1Count()
    { return 19; }

// The 19 rows of the Monster Level II grid
inline int mm2encdD2Count()
    { return 19; }

// The 19 rows of the Monster Level III grid
inline int mm2encdD3Count()
    { return 19; }

// The 19 rows of the Monster Level IV grid
inline int mm2encdD4Count()
    { return 19; }

// The 19 rows of the Monster Level V grid
inline int mm2encdD5Count()
    { return 19; }

// The 19 rows of the Monster Level VI grid
inline int mm2encdD6Count()
    { return 19; }

// The 19 rows of the Monster Level VII grid
inline int mm2encdD7Count()
    { return 19; }

// The 19 rows of the Monster Level VIII grid
inline int mm2encdD8Count()
    { return 19; }

// The 19 rows of the Monster Level IX grid
inline int mm2encdD9Count()
    { return 19; }

// The 19 rows of the Monster Level X grid
inline int mm2encdD10Count()
    { return 19; }

// ---- the opening doctrine (the R816 census) ----

// All dice scores on the tables are produced from the sum of 1 8-sided and 1
// 12-sided die
inline bool mm2encdUsesD8PlusD12()
    { return true; }

// The 1d8+1d12 sum produces the range 2-20
inline bool mm2encdRangeTwoToTwenty()
    { return true; }

// The tables are used in conjunction with those in Appendix C of the DUNGEON
// MASTER GUIDE
inline bool mm2encdConjoinsDmgAppendixC()
    { return true; }

// The tables include creatures from MM2, the first MONSTER MANUAL and the
// FIEND FOLIO
inline bool mm2encdCoversMm1Mm2AndFf()
    { return true; }

// The tables are not a complete listing but typical encounters for easy use
// by the DM
inline bool mm2encdNotACompleteListing()
    { return true; }

// Modification of the tables or creation of new ones can be undertaken as
// desired
inline bool mm2encdDmMayModifyTables()
    { return true; }

// See the Creating Encounter Tables section following the listing
inline bool mm2encdSeeCreatingTablesSection()
    { return true; }

// The character-party row consults the character subtable in the DMG
inline bool mm2encdPartyRowRollsDmgSubtable()
    { return true; }

// Powerful unique creatures (demon princes, daemon masters, dukes of the
// hells) are always accompanied by a court of servants and vassals
inline bool mm2encdUniqueCourtRule()
    { return true; }

// Orcus will be found with undead
inline bool mm2encdCourtOrcusWithUndead()
    { return true; }

// Tiamat with her abishai devils and several huge dragons
inline bool mm2encdCourtTiamatWithAbishai()
    { return true; }

// Anthraxus the Oinodaemon with lesser powerful daemons
inline bool mm2encdCourtAnthraxusWithDaemons()
    { return true; }

// The unique-court rows carry the bullet instead of a number encountered
inline bool mm2encdUniqueRowsCarryNoNumber()
    { return true; }

// ---- the Level I grid pins (the R816 walk) ----

// The die cells (2-20 contiguous, the 1d8+1d12 sum)
inline int mm2encdD1Die(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 14;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 17;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 20;
        default:
            return 0;
        }
    }

// The source cells (1 MM1, 2 MM2, 3 FF, 4 ALL, 0 the character-party row)
inline int mm2encdD1Src(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 3;
        case 16:
            return 2;
        case 17:
            return 1;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the party and unique-court rows)
inline int mm2encdD1NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 6;
        case 7:
            return 5;
        case 8:
            return 2;
        case 9:
            return 0;
        case 10:
            return 7;
        case 11:
            return 5;
        case 12:
            return 6;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 5;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells (0 the party and unique-court rows)
inline int mm2encdD1NumMax(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 12;
        case 2:
            return 18;
        case 3:
            return 12;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 15;
        case 7:
            return 15;
        case 8:
            return 20;
        case 9:
            return 0;
        case 10:
            return 12;
        case 11:
            return 20;
        case 12:
            return 17;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 8;
        case 16:
            return 12;
        case 17:
            return 15;
        case 18:
            return 3;
        default:
            return 0;
        }
    }

// The special cells (0 normal, 1 the character-party row, 2 a unique-court
// row)
inline int mm2encdD1Special(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level II grid pins (the R816 walk) ----

// The die cells (2-20 contiguous, the 1d8+1d12 sum)
inline int mm2encdD2Die(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 14;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 17;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 20;
        default:
            return 0;
        }
    }

// The source cells (1 MM1, 2 MM2, 3 FF, 4 ALL, 0 the character-party row)
inline int mm2encdD2Src(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 3;
        case 16:
            return 2;
        case 17:
            return 1;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the party and unique-court rows)
inline int mm2encdD2NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 4;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 5;
        case 14:
            return 2;
        case 15:
            return 4;
        case 16:
            return 2;
        case 17:
            return 2;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells (0 the party and unique-court rows)
inline int mm2encdD2NumMax(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 12;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 12;
        case 5:
            return 10;
        case 6:
            return 8;
        case 7:
            return 8;
        case 8:
            return 4;
        case 9:
            return 0;
        case 10:
            return 8;
        case 11:
            return 18;
        case 12:
            return 12;
        case 13:
            return 15;
        case 14:
            return 12;
        case 15:
            return 10;
        case 16:
            return 8;
        case 17:
            return 7;
        case 18:
            return 4;
        default:
            return 0;
        }
    }

// The special cells (0 normal, 1 the character-party row, 2 a unique-court
// row)
inline int mm2encdD2Special(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level III grid pins (the R816 walk) ----

// The die cells (2-20 contiguous, the 1d8+1d12 sum)
inline int mm2encdD3Die(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 14;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 17;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 20;
        default:
            return 0;
        }
    }

// The source cells (1 MM1, 2 MM2, 3 FF, 4 ALL, 0 the character-party row)
inline int mm2encdD3Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 3;
        case 16:
            return 1;
        case 17:
            return 3;
        case 18:
            return 3;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the party and unique-court rows)
inline int mm2encdD3NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The number-encountered high cells (0 the party and unique-court rows)
inline int mm2encdD3NumMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 1;
        case 5:
            return 8;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 4;
        case 9:
            return 3;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 7;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 4;
        case 17:
            return 2;
        case 18:
            return 8;
        default:
            return 0;
        }
    }

// The special cells (0 normal, 1 the character-party row, 2 a unique-court
// row)
inline int mm2encdD3Special(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level IV grid pins (the R816 walk) ----

// The die cells (2-20 contiguous, the 1d8+1d12 sum)
inline int mm2encdD4Die(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 14;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 17;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 20;
        default:
            return 0;
        }
    }

// The source cells (1 MM1, 2 MM2, 3 FF, 4 ALL, 0 the character-party row)
inline int mm2encdD4Src(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 3;
        case 16:
            return 2;
        case 17:
            return 2;
        case 18:
            return 3;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the party and unique-court rows)
inline int mm2encdD4NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells (0 the party and unique-court rows)
inline int mm2encdD4NumMax(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 12;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 4;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 6;
        case 10:
            return 4;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 4;
        case 15:
            return 1;
        case 16:
            return 4;
        case 17:
            return 1;
        case 18:
            return 4;
        default:
            return 0;
        }
    }

// The special cells (0 normal, 1 the character-party row, 2 a unique-court
// row)
inline int mm2encdD4Special(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level V grid pins (the R816 walk) ----

// The die cells (2-20 contiguous, the 1d8+1d12 sum)
inline int mm2encdD5Die(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 14;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 17;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 20;
        default:
            return 0;
        }
    }

// The source cells (1 MM1, 2 MM2, 3 FF, 4 ALL, 0 the character-party row)
inline int mm2encdD5Src(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the party and unique-court rows)
inline int mm2encdD5NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells (0 the party and unique-court rows)
inline int mm2encdD5NumMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 0;
        case 9:
            return 2;
        case 10:
            return 4;
        case 11:
            return 5;
        case 12:
            return 1;
        case 13:
            return 5;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 3;
        case 17:
            return 3;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 normal, 1 the character-party row, 2 a unique-court
// row)
inline int mm2encdD5Special(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level VI grid pins (the R816 walk) ----

// The die cells (2-20 contiguous, the 1d8+1d12 sum)
inline int mm2encdD6Die(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 14;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 17;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 20;
        default:
            return 0;
        }
    }

// The source cells (1 MM1, 2 MM2, 3 FF, 4 ALL, 0 the character-party row)
inline int mm2encdD6Src(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 3;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the party and unique-court rows)
inline int mm2encdD6NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells (0 the party and unique-court rows)
inline int mm2encdD6NumMax(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 6;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 4;
        case 9:
            return 0;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 normal, 1 the character-party row, 2 a unique-court
// row)
inline int mm2encdD6Special(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level VII grid pins (the R816 walk) ----

// The die cells (2-20 contiguous, the 1d8+1d12 sum)
inline int mm2encdD7Die(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 14;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 17;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 20;
        default:
            return 0;
        }
    }

// The source cells (1 MM1, 2 MM2, 3 FF, 4 ALL, 0 the character-party row)
inline int mm2encdD7Src(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 3;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the party and unique-court rows)
inline int mm2encdD7NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells (0 the party and unique-court rows)
inline int mm2encdD7NumMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 3;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 4;
        case 10:
            return 3;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 4;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 normal, 1 the character-party row, 2 a unique-court
// row)
inline int mm2encdD7Special(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level VIII grid pins (the R816 walk) ----

// The die cells (2-20 contiguous, the 1d8+1d12 sum)
inline int mm2encdD8Die(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 14;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 17;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 20;
        default:
            return 0;
        }
    }

// The source cells (1 MM1, 2 MM2, 3 FF, 4 ALL, 0 the character-party row)
inline int mm2encdD8Src(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the party and unique-court rows)
inline int mm2encdD8NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells (0 the party and unique-court rows)
inline int mm2encdD8NumMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 normal, 1 the character-party row, 2 a unique-court
// row)
inline int mm2encdD8Special(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level IX grid pins (the R816 walk) ----

// The die cells (2-20 contiguous, the 1d8+1d12 sum)
inline int mm2encdD9Die(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 14;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 17;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 20;
        default:
            return 0;
        }
    }

// The source cells (1 MM1, 2 MM2, 3 FF, 4 ALL, 0 the character-party row)
inline int mm2encdD9Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 2;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the party and unique-court rows)
inline int mm2encdD9NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells (0 the party and unique-court rows)
inline int mm2encdD9NumMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 normal, 1 the character-party row, 2 a unique-court
// row)
inline int mm2encdD9Special(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level X grid pins (the R816 walk) ----

// The die cells (2-20 contiguous, the 1d8+1d12 sum)
inline int mm2encdD10Die(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 14;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 17;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 20;
        default:
            return 0;
        }
    }

// The source cells (1 MM1, 2 MM2, 3 FF, 4 ALL, 0 the character-party row)
inline int mm2encdD10Src(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 4;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the party and unique-court rows)
inline int mm2encdD10NumMin(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// The number-encountered high cells (0 the party and unique-court rows)
inline int mm2encdD10NumMax(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// The special cells (0 normal, 1 the character-party row, 2 a unique-court
// row)
inline int mm2encdD10Special(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 2;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

}   // namespace rules
