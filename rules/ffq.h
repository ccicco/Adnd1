// =========================================================================================
// Adnd1 - rules/ffq.h
// THE FF MAGIC ITEM TABLES - THE PARTY MAGIC BANDS AND THE FOUR ITEM TABLES
// (the print pp. 101-102: the 13 Individual-is-Nth-level party bands and
// Tables I through IV), the third and closing round of the three FF
// table-group rounds (the FF table-group arc closes here)
// census 770 -> 771.
//
// The FF arc table-group continuation (Curtiss Go call on the landed R847 FF
// encounter listings; the three-round queue rides the R846 record). The
// pin-time walk found 5 printed tables and 77 rows - the R846/R847 grid
// rounds the mechanics precedent - adjudicated from the four-voice scan
// collation (the djvu text, the word-geometry xml, the abbyy char xml, the
// pdf hidden Acrobat Capture layer) with the DMG npcparty parity (the
// 1eonline transcription) the tie-breaker. No defs promoted: the registry
// floor holds at 995.
//
// The spliced rounds never edit the landed audits: the battery reads every
// table cell live, the census walks the arithmetic, and the double engine run
// lands GREEN before the commit.
//
namespace rules {

// ---- the R848 census ----

// the FF magic item tables round: the party magic bands and the four item
// tables, the third and closing round of the three FF table-group arc
// (Curtiss Go call on the landed R847)
inline int ffqRound()
    { return 848; }

// the 5 tables: the party band table and the four item tables (Table I
// through Table IV)
inline int ffqTableCount()
    { return 5; }

// the 13 party band rows (the Individual-is-Nth-level rows, N 1-13)
inline int ffqBndRows()
    { return 13; }

// the Table I rows (the d20 item list)
inline int ffqT1Rows()
    { return 20; }

// the Table II rows (the (d8, d6) item list)
inline int ffqT2Rows()
    { return 16; }

// the Table III rows (the (d8, d6) item list)
inline int ffqT3Rows()
    { return 16; }

// the Table IV rows (the d12 item list)
inline int ffqT4Rows()
    { return 12; }

// the total rows pinned across the 5 tables
inline int ffqTotalRows()
    { return 77; }

// the 64 distinct item labels the four tables carry (the roster ordinal walks
// first appearance, Tables I-IV)
inline int ffqRosterCount()
    { return 64; }

// the landed registry census pin: no defs promoted this round (the item rows
// are not monster listings)
inline int ffqRegistryFloor()
    { return 995; }

// the forced repairs (the R703 pattern): the party-prose garbles, the
// Table-name garbles, the digit and name garbles and the pdf voice garbles
inline int ffqRepairs()
    { return 18; }

// the two FF-vs-DMG divergences pinned: the dust of appearance (the DMG
// prints dust of disappearance) and the dagger et al row (the DMG expands the
// six daggers, the FF prints no footnote)
inline int ffqDivergences()
    { return 2; }

// ---- the R848 doctrine ----

// the party magic prose opens the section: In order to simulate a party of
// adventurers it is absolutely necessary that characters and henchmen have
// and employ some magic devices (the print p. 101 prose)
inline bool ffqPartyMagicProse()
    { return true; }

// the band rule: each Individual-is-Nth-level row carries one percent chance
// and count pair per offered table, the percentage dropped at the automatic
// rows (Table I automatic from 10th, Table II from 12th, Table III at 13th)
inline bool ffqBandRule()
    { return true; }

// Table I scores on d20 (the 20-item die column, the die is the row ordinal)
inline bool ffqD20Header()
    { return true; }

// Tables II and III score (d8, d6) as the 1-16 linear convention: d6 1-3
// reads the d8 result (1-8), d6 4-6 reads d8+8 (9-16) - the DMG linear-range
// dice convention
inline bool ffqD8D6Linear()
    { return true; }

// Table IV scores on d12 (the 12-item die column)
inline bool ffqD12Header()
    { return true; }

// the closing advice: It is suggested that you personally select appropriate
// items, using random determination only when any item would be suitable to
// the particular individual
inline bool ffqPersonalSelect()
    { return true; }

// the closing note: Note that some items are groups or multiples
inline bool ffqGroupsOrMultiples()
    { return true; }

// the Table II item 10 reads dust of appearance in the FF print (both char
// voices and the pdf Capture voice agree) - the DMG prints dust of
// disappearance; the FF ink is pinned and the divergence noted
inline bool ffqDustAppearance()
    { return true; }

// the Table I item 12 ring of protection +1: both char voices drop the +1,
// the pdf Capture voice carries it (read +7, the 1 class) and the DMG parity
// agrees - the +1 is pinned
inline bool ffqRingProtectionPlus1()
    { return true; }

// the Table I item 18 reads +1 (or +2) et al with no footnote expansion - the
// DMG expands the six daggers behind the et al; the FF prints none
inline bool ffqDaggerEtAl()
    { return true; }

// the 13 bands and all 64 items match the DMG npcparty listing (the 1eonline
// transcription) modulo the two pinned divergences
inline bool ffqDmgParity()
    { return true; }

// ---- the R848 tables ----

// The level cells (the Individual-is-Nth-level ordinal, 1-13)
inline int ffqBndOrd(int b)
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
        default:
            return 0;
        }
    }

// The Table I percent cells (0 with count 0 = not offered, 0 with count above
// 0 = the automatic row)
inline int ffqBndIPct(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 40;
        case 4:
            return 50;
        case 5:
            return 60;
        case 6:
            return 70;
        case 7:
            return 80;
        case 8:
            return 90;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The Table I count cells (the item count drawn on a hit)
inline int ffqBndINum(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 3;
        default:
            return 0;
        }
    }

// The Table II percent cells (the same 0 convention)
inline int ffqBndIIPct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 10;
        case 3:
            return 20;
        case 4:
            return 30;
        case 5:
            return 40;
        case 6:
            return 50;
        case 7:
            return 60;
        case 8:
            return 70;
        case 9:
            return 80;
        case 10:
            return 90;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The Table II count cells
inline int ffqBndIINum(int b)
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
            return 1;
        case 5:
            return 2;
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
            return 2;
        case 12:
            return 2;
        default:
            return 0;
        }
    }

// The Table III percent cells (the same 0 convention)
inline int ffqBndIIIPct(int b)
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
            return 10;
        case 7:
            return 20;
        case 8:
            return 30;
        case 9:
            return 40;
        case 10:
            return 50;
        case 11:
            return 60;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The Table III count cells
inline int ffqBndIIINum(int b)
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
            return 1;
        case 12:
            return 1;
        default:
            return 0;
        }
    }

// The Table IV percent cells (the same 0 convention)
inline int ffqBndIVPct(int b)
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
            return 0;
        case 10:
            return 10;
        case 11:
            return 20;
        case 12:
            return 60;
        default:
            return 0;
        }
    }

// The Table IV count cells
inline int ffqBndIVNum(int b)
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
            return 0;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        default:
            return 0;
        }
    }

// The roster cells (the 64-label item roster ordinal, first appearance across
// Tables I-IV)
inline int ffqT1Ord(int b)
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
        default:
            return 0;
        }
    }

// The count cells (the printed leading count: 2 Potions, 1 Scroll, 10 Arrows,
// 4 Bolts, 3 Javelins, 2 Ropes)
inline int ffqT1Ct(int b)
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
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 1;
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
            return 10;
        case 16:
            return 4;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        default:
            return 0;
        }
    }

// The roster cells (the 64-label item roster ordinal, first appearance across
// Tables I-IV)
inline int ffqT2Ord(int b)
    {
        switch (b) {
        case 0:
            return 21;
        case 1:
            return 22;
        case 2:
            return 23;
        case 3:
            return 24;
        case 4:
            return 25;
        case 5:
            return 26;
        case 6:
            return 27;
        case 7:
            return 28;
        case 8:
            return 29;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 32;
        case 12:
            return 33;
        case 13:
            return 34;
        case 14:
            return 35;
        case 15:
            return 36;
        default:
            return 0;
        }
    }

// The count cells (the printed leading count: 2 Potions, 1 Scroll, 10 Arrows,
// 4 Bolts, 3 Javelins, 2 Ropes)
inline int ffqT2Ct(int b)
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
            return 1;
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
            return 3;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 2;
        default:
            return 0;
        }
    }

// The roster cells (the 64-label item roster ordinal, first appearance across
// Tables I-IV)
inline int ffqT3Ord(int b)
    {
        switch (b) {
        case 0:
            return 37;
        case 1:
            return 38;
        case 2:
            return 39;
        case 3:
            return 40;
        case 4:
            return 41;
        case 5:
            return 42;
        case 6:
            return 43;
        case 7:
            return 44;
        case 8:
            return 45;
        case 9:
            return 46;
        case 10:
            return 47;
        case 11:
            return 48;
        case 12:
            return 49;
        case 13:
            return 50;
        case 14:
            return 51;
        case 15:
            return 52;
        default:
            return 0;
        }
    }

// The count cells (the printed leading count: 2 Potions, 1 Scroll, 10 Arrows,
// 4 Bolts, 3 Javelins, 2 Ropes)
inline int ffqT3Ct(int b)
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
            return 1;
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
        default:
            return 0;
        }
    }

// The roster cells (the 64-label item roster ordinal, first appearance across
// Tables I-IV)
inline int ffqT4Ord(int b)
    {
        switch (b) {
        case 0:
            return 53;
        case 1:
            return 54;
        case 2:
            return 55;
        case 3:
            return 56;
        case 4:
            return 57;
        case 5:
            return 58;
        case 6:
            return 59;
        case 7:
            return 60;
        case 8:
            return 61;
        case 9:
            return 62;
        case 10:
            return 63;
        case 11:
            return 64;
        default:
            return 0;
        }
    }

// The count cells (the printed leading count: 2 Potions, 1 Scroll, 10 Arrows,
// 4 Bolts, 3 Javelins, 2 Ropes)
inline int ffqT4Ct(int b)
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
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        default:
            return 0;
        }
    }

}   // namespace rules
