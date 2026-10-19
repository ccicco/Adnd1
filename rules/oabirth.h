// =========================================================================================
// Adnd1 - rules/oabirth.h
// FAMILIES, CLASS, AND CASTE, printed capture pp. 60-62 - the OA Chapter 3
// opener round
// census 551 -> 552.
//
// verified against capture pp. 60-62 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). ONE CONTESTED CELL SETTLED
// AGAINST THE 2018 PRINT BEFORE PINNING: the T38 row-27 ancestry cell d100/8
// (the first capture printed d100/9, the second d100/8 - the settled reading
// stands). The T38 holds seventeen printed rows (the 2d10 bands 2 through 30
// - the first preflight run mispinned eighteen and the battery caught bad
// 14); the T38 rank column pins as the 0-16 code (outcast 0 through the 1st
// Rank 16); the ancestry and birthright dice pin as die codes (d4=4 through
// d100=100) with the rolls as the after-slash counts; the T37 requirement
// columns pin as the 0/1 code. OCR normalization: "should affect and NPC"
// reads as should affect an NPC; "1 d6" reads as 1d6; the Table 38 header
// spans two rows in the second capture (the printed six-column header stands)
//
// the gap census after this round: 67 closed, 168 open - the Birth Rank
// prose, Table 37 and Table 38 boxes flip (census 551 -> 552); NEXT - R630:
// the Family Structure and Additional Family Structures prose, capture pp.
// 62-64, the family chart rows with the honor-by-position doctrine, prefix
// dgq (verify free), audit "R630 OA family structures audit", include after
// rules/oabirth.h
//
namespace rules {

// ---- the family doctrine pins ----

// Table 37 (capture p. 60): nine class rows
inline int dgpT37RowCount()
    { return 9; }

// Family prose (capture p. 60): the family or clan means the entire set of
// relations
inline bool dgpFamilyIncludesAllRelations()
    { return true; }

// Family prose (capture p. 60): ancestors add great honor to a family
inline bool dgpAncestorsAddHonor()
    { return true; }

// Family prose (capture p. 60): certain classes adopt the profession as a new
// family
inline bool dgpClassesMayAdoptProfession()
    { return true; }

// Family prose (capture p. 60): a shukenja severs all connections with his
// past
inline bool dgpShukenjaSeversConnections()
    { return true; }

// Family prose (capture p. 60): an optional family background must abide by
// the family rules
inline bool dgpOptionalFamilyFollowsRules()
    { return true; }

// ---- the birth rank doctrine pins ----

// Birth rank prose (capture p. 61): roll 2d10 for the birth rank
inline int dgpBirthRollDice()
    { return 2; }

// Birth rank prose (capture p. 61): the 2d10 birth roll dice sides
inline int dgpBirthRollSides()
    { return 10; }

// Table 38 (capture p. 61): seventeen birth rows
inline int dgpT38RowCount()
    { return 17; }

// Birth rank prose (capture p. 61): the rank modifies NPC reactions where
// title and respect matter
inline bool dgpBirthRankNpcReaction()
    { return true; }

// Birth rank prose (capture p. 61): the rank determines the ancestors and the
// starting birthright
inline bool dgpBirthRankAncestryBirthright()
    { return true; }

// Birth rank prose (capture p. 62): the honor column is gained by the family,
// not the character
inline bool dgpHonorIsFamilyNotCharacter()
    { return true; }

// NPC reaction prose (capture p. 62): the Chang Lui example, the -25 percent
// modifier
inline int dgpNpcExampleDiffPct()
    { return 25; }

// NPC reaction prose (capture p. 62): the lower upper class base score in the
// example
inline int dgpNpcExamplePc()
    { return 30; }

// NPC reaction prose (capture p. 62): the 7th Rank base score in the example
inline int dgpNpcExampleNpc()
    { return 55; }

// ---- the Table 37 doctrine pins ----

// Table 37 prose (capture p. 61): korobokuru samurai do not roll on Table 38
inline bool dgpKorobokuruSamuraiNoRoll()
    { return true; }

// Table 37 prose (capture p. 61): korobokuru samurai take the lowest
// allowable samurai rank
inline bool dgpKorobokuruSamuraiLowestRank()
    { return true; }

// Table 37 prose (capture p. 61): a ninja automatically belongs to the Ninja
// clan
inline bool dgpNinjaAutomaticClan()
    { return true; }

// Table 37 prose (capture p. 61): the ninja birth rank can still be
// determined normally
inline bool dgpNinjaBirthRankOptional()
    { return true; }

// ---- the family structure pins ----

// Family structure prose (capture p. 62): three generational rows on the
// Family Chart
inline int dgpFamilyChartRows()
    { return 3; }

// Family structure prose (capture p. 62): the head of family always occupies
// position 1
inline int dgpHeadPosition()
    { return 1; }

// Family structure prose (capture p. 62): 1d8 spaces used per row
inline int dgpRowSpacesDice()
    { return 8; }

// Family structure prose (capture p. 62): the 70 percent male chance per
// space
inline int dgpMaleChancePct()
    { return 70; }

// Family structure prose (capture p. 62): the head, grandfather and father
// are automatically male
inline bool dgpHeadAutoMale()
    { return true; }

// Family structure prose (capture p. 62): the family name is written and
// spoken before the individual name
inline bool dgpFamilyNameFirst()
    { return true; }

// ---- the Table 37 and Table 38 grids ----

// the modifier column: the samurai +10, the yakuza -10, all others 0 (capture
// pp. 60-61).
inline int dgpT37Mod(int b)
    {
        switch (b) {
        case 0:
            return 10;
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
            return -10;
        default:
            return -99;
        }
    }

// the birth-table-required column, pinned as the 0/1 code (capture pp.
// 60-61).
inline int dgpT37BirthReq(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// the family-required column, pinned as the 0/1 code (capture pp. 60-61).
inline int dgpT37FamilyReq(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 1;
        default:
            return -99;
        }
    }

// the birth rank code column: outcast 0, lower class 1, lower middle 2,
// middle 3, upper middle 4, lower upper 5, upper 6, then the 10th through 1st
// ranks as 7-16 (capture p. 61).
inline int dgpT38RankCode(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        case 9:
            return 9;
        case 10:
            return 10;
        case 11:
            return 11;
        case 12:
            return 12;
        case 13:
            return 13;
        case 14:
            return 14;
        case 15:
            return 15;
        case 16:
            return 16;
        default:
            return -99;
        }
    }

// the NPC reaction base score column, pinned as the whole percent 5 to 90
// (capture p. 61).
inline int dgpT38NpcPct(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 20;
        case 4:
            return 25;
        case 5:
            return 30;
        case 6:
            return 35;
        case 7:
            return 40;
        case 8:
            return 45;
        case 9:
            return 50;
        case 10:
            return 55;
        case 11:
            return 60;
        case 12:
            return 65;
        case 13:
            return 70;
        case 14:
            return 75;
        case 15:
            return 80;
        case 16:
            return 90;
        default:
            return -99;
        }
    }

// the ancestry die column, pinned as the die code: d4=4, d6=6, d8=8, d10=10,
// d20=20, d100=100 (capture p. 61).
inline int dgpT38AncDie(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 10;
        case 4:
            return 20;
        case 5:
            return 100;
        case 6:
            return 100;
        case 7:
            return 100;
        case 8:
            return 100;
        case 9:
            return 100;
        case 10:
            return 100;
        case 11:
            return 100;
        case 12:
            return 100;
        case 13:
            return 100;
        case 14:
            return 100;
        case 15:
            return 100;
        case 16:
            return 100;
        default:
            return -99;
        }
    }

// the ancestry rolls column: the number after the slash - the row-27 cell was
// contested (the first capture printed 9, the second 8) and settled against
// the 2018 print as 8 (capture p. 61).
inline int dgpT38AncRolls(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 4;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 7;
        case 11:
            return 7;
        case 12:
            return 8;
        case 13:
            return 8;
        case 14:
            return 9;
        case 15:
            return 9;
        case 16:
            return 10;
        default:
            return -99;
        }
    }

// the birthright die column, pinned as the die code (capture p. 61).
inline int dgpT38BirthDie(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 100;
        case 7:
            return 100;
        case 8:
            return 100;
        case 9:
            return 100;
        case 10:
            return 100;
        case 11:
            return 100;
        case 12:
            return 100;
        case 13:
            return 100;
        case 14:
            return 100;
        case 15:
            return 100;
        case 16:
            return 100;
        default:
            return -99;
        }
    }

// the birthright rolls column: the number after the slash (capture p. 61).
inline int dgpT38BirthRolls(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 4;
        case 6:
            return 3;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 6;
        case 10:
            return 7;
        case 11:
            return 8;
        case 12:
            return 9;
        case 13:
            return 10;
        case 14:
            return 10;
        case 15:
            return 10;
        case 16:
            return 10;
        default:
            return -99;
        }
    }

// the honor column: the family honor 0 to 35 (capture p. 61).
inline int dgpT38Honor(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 5;
        case 3:
            return 8;
        case 4:
            return 10;
        case 5:
            return 15;
        case 6:
            return 17;
        case 7:
            return 20;
        case 8:
            return 22;
        case 9:
            return 24;
        case 10:
            return 25;
        case 11:
            return 26;
        case 12:
            return 27;
        case 13:
            return 28;
        case 14:
            return 29;
        case 15:
            return 30;
        case 16:
            return 35;
        default:
            return -99;
        }
    }

}   // namespace rules
