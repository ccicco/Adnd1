// =========================================================================================
// Adnd1 - rules/ffn.h
// THE FF MONSTER LEVEL TABLES - THE TEN LEVEL GRIDS AND THE ELEVEN SUBTABLES
// (the print pp. 100-110: the ten Monster Level tables I through X, the eight
// Dragon Subtables keyed to Levels III-X, the Sphinx, Human and Character
// Subtables), the first of the three FF table-group rounds (the Encounter
// Listings and the Magic Item Tables follow)
// census 768 -> 769.
//
// The FF arc table-group opener (Curtiss Go call on the landed R845 FF
// promotion walk; the three-round queue rides the R846 record). The pin-time
// walk found 21 printed grids and 461 rows - the R816 MM2 dungeon grids round
// the mechanics precedent - adjudicated from the three-voice scan collation
// (the djvu text, the word-geometry xml, the abbyy char xml) with the landed
// registry defs advisory. No defs promoted: the registry floor holds at 995.
//
// The spliced rounds never edit the landed audits: the battery reads every
// table cell live, the census walks the arithmetic, and the double engine run
// lands GREEN before the commit.
//
namespace rules {

// ---- the R846 census ----

// The FF monster level tables round: the ten Monster Level grids and the
// eleven subtables, the first table-group round of the FF arc (Curtiss Go
// call on the landed R845)
inline int ffnRound()
    { return 846; }

// The 21 grids: the ten Monster Level tables, the eight Dragon Subtables
// (Levels III-X), the Sphinx, Human and Character Subtables
inline int ffnTableCount()
    { return 21; }

// The rows pinned across the ten level grids
inline int ffnLevelRows()
    { return 360; }

// The rows pinned across the eight Dragon Subtables
inline int ffnDragonBandRows()
    { return 83; }

// The rows pinned across the Sphinx (4), Human (4) and Character (10)
// Subtables
inline int ffnSubtableRows()
    { return 18; }

// The total rows pinned across the 21 grids
inline int ffnTotalRows()
    { return 461; }

// The round roster: every creature label, routing label, sphinx type, human
// row, character class and dragon type the 21 grids walk, first-appearance
// order
inline int ffnRosterCount()
    { return 333; }

// The registry floor: no defs promoted this round, the 995 landed defs the
// advisory voice
inline int ffnRegistryFloor()
    { return 995; }

// The forced repairs (the R703 pattern: every repair forced by the 01-00
// contiguity or corroborated by the def)
inline int ffnRepairs()
    { return 39; }

// The two pinned print defects: the Level III wererat band overlap and the
// Level VIII die hole 27-28
inline int ffnDefectPins()
    { return 2; }

// The Level III defect rows: the wererat band 56-63 double-lists the four
// following rows (59, 60, 61-62, 63), pinned as ink
inline int ffnL3DefectRows()
    { return 5; }

// The Level VIII print defect: the ink skips the die band 27-28 (the Giant,
// cloud row 25-26 jumps to the Giant, fog row 29-30 in both voices), pinned
// as ink
inline int ffnL8HoleLo()
    { return 27; }

// The high end of the Level VIII die hole
inline int ffnL8HoleHi()
    { return 28; }

// The MM1-sourced rows across the level grids (the source census: 1 MM1, 2
// MM2, 3 FF, 4 unkeyed, 0 routing)
inline int ffnMm1SourceRows()
    { return 193; }

// The MM2-sourced rows: none walk the FF tables (the print lists MM1 and FF
// creatures only)
inline int ffnMm2SourceRows()
    { return 0; }

// The FF-sourced rows
inline int ffnFfSourceRows()
    { return 133; }

// The unkeyed rows: the pyrohydra (six levels), the piercer (three levels,
// the four MM1 size defs), the green slaad, the brigand, the four Level X
// court rows
inline int ffnUnkeyedRows()
    { return 14; }

// The routing rows (the Human, Character, Dragon, Sphinx and Elemental bands)
inline int ffnRoutingRows()
    { return 20; }

// The Character routing rows (one on every level but I, where the Human row
// routes instead)
inline int ffnRoutingCharacter()
    { return 9; }

// The Dragon routing rows (Levels III through X; the Levels I and II grids
// carry no dragon rows)
inline int ffnRoutingDragon()
    { return 8; }

// The Human routing row (Level I, dies 39-46)
inline int ffnRoutingHuman()
    { return 1; }

// The Sphinx routing row (Level VII, dies 89-90)
inline int ffnRoutingSphinx()
    { return 1; }

// The Elemental group row (Level VII, dies 29-30)
inline int ffnRoutingElemental()
    { return 1; }

// The Monster Level I grid rows
inline int ffnL1Rows()
    { return 33; }

// The Monster Level II grid rows
inline int ffnL2Rows()
    { return 30; }

// The Monster Level III grid rows
inline int ffnL3Rows()
    { return 55; }

// The Monster Level IV grid rows
inline int ffnL4Rows()
    { return 42; }

// The Monster Level V grid rows
inline int ffnL5Rows()
    { return 33; }

// The Monster Level VI grid rows
inline int ffnL6Rows()
    { return 40; }

// The Monster Level VII grid rows
inline int ffnL7Rows()
    { return 58; }

// The Monster Level VIII grid rows
inline int ffnL8Rows()
    { return 31; }

// The Monster Level IX grid rows
inline int ffnL9Rows()
    { return 23; }

// The Monster Level X grid rows
inline int ffnL10Rows()
    { return 15; }

// The Dragon Subtable rows keyed to Level III
inline int ffnD3Rows()
    { return 3; }

// The Dragon Subtable rows keyed to Level IV
inline int ffnD4Rows()
    { return 11; }

// The Dragon Subtable rows keyed to Level V
inline int ffnD5Rows()
    { return 11; }

// The Dragon Subtable rows keyed to Level VI
inline int ffnD6Rows()
    { return 11; }

// The Dragon Subtable rows keyed to Level VII
inline int ffnD7Rows()
    { return 12; }

// The Dragon Subtable rows keyed to Level VIII
inline int ffnD8Rows()
    { return 12; }

// The Dragon Subtable rows keyed to Level IX
inline int ffnD9Rows()
    { return 12; }

// The Dragon Subtable rows keyed to Level X
inline int ffnD10Rows()
    { return 11; }

// The Sphinx Subtable rows
inline int ffnSpxRows()
    { return 4; }

// The Human Subtable rows
inline int ffnHumRows()
    { return 4; }

// The Character Subtable rows
inline int ffnChrRows()
    { return 10; }

// ---- the opening doctrine (the R846 census) ----

// Every grid scores on percentile dice (the 00 cell read as 100), unlike the
// MM2 dungeon grids (the 1d8+1d12 sum)
inline bool ffnDiceScoreD100()
    { return true; }

// The tables list the common dungeon dwellers, not a complete listing (the
// print doctrine)
inline bool ffnNotACompleteListing()
    { return true; }

// The DM may modify the tables as desired (the print doctrine)
inline bool ffnDmMayModify()
    { return true; }

// The eight Dragon Subtables ride Levels III through X (the Levels I and II
// grids carry no dragon rows)
inline bool ffnDragonSubtablesKeyedIIItoX()
    { return true; }

// The Dragon Subtable footnote: determine the number of hit dice for a dragon
// as normal
inline bool ffnDragonHdNote()
    { return true; }

// The Human Subtable footnote: upper level leaders and sub-leaders are not
// with groups numbering under 30, and at only 50% of normal level
// (rounded-up) for groups under 60
inline bool ffnHumanLeadersNote()
    { return true; }

// The Level I halfling footnote: not encountered below the 4th level, treat
// as a roll of 71-77 (Rat, giant) thereafter
inline bool ffnHalflingDeepNote()
    { return true; }

// The Level II giant badger footnote: not encountered below the 3rd level,
// treat as a roll of 44-48 (Gnoll) thereafter
inline bool ffnBadgerThirdLevelNote()
    { return true; }

// The Level VII elemental footnote: choose, or use equal probabilities as
// applicable
inline bool ffnElementalChooseNote()
    { return true; }

// The Level IX vampire footnote: former evil cleric, with full powers of
// 7th-10th level
inline bool ffnL9VampireFootnote()
    { return true; }

// The Level X vampire footnote: former magic-user, with full powers, of
// 9th-12th level
inline bool ffnL10VampireFootnote()
    { return true; }

// The Level X asterisk rows (the demon prince, the arch devil, the elemental
// prince of evil, the slaad lord): select one or find randomly
inline bool ffnL10AsteriskSelect()
    { return true; }

// The Level X AC column prints blank except the Beholder (0/2/7) and the
// Elemental Prince of Evil (Var)
inline bool ffnL10AcColumnBlank()
    { return true; }

// The Character Subtable monk or bard row reads "1 or 1" in the ink
inline bool ffnCharMonkNote()
    { return true; }

// The Level III wererat band 56-63 is a print defect (the ink double-lists
// dies 59-63 inside the band), pinned as ink
inline bool ffnL3Defect()
    { return true; }

// The Level VIII ink skips the die band 27-28 (both voices), pinned as ink
inline bool ffnL8HoleDefect()
    { return true; }

// The ink name variants pin as scanned (Anhkheg, Korn, Elf drew, Meazle,
// Snayd, XIII and the rest) - the roster rides the cleaned print names
inline bool ffnInkNameVariants()
    { return true; }

// ---- the party-row and routing-die pins (the R846 walk) ----

// The die the party routing row starts at on the Monster Level I grid (the
// Human row)
inline int ffnPartyDieD1()
    { return 39; }

// The die the party routing row starts at on the Monster Level II grid (the
// Character row)
inline int ffnPartyDieD2()
    { return 15; }

// The die the party routing row starts at on the Monster Level III grid (the
// Character row)
inline int ffnPartyDieD3()
    { return 16; }

// The die the party routing row starts at on the Monster Level IV grid (the
// Character row)
inline int ffnPartyDieD4()
    { return 13; }

// The die the party routing row starts at on the Monster Level V grid (the
// Character row)
inline int ffnPartyDieD5()
    { return 7; }

// The die the party routing row starts at on the Monster Level VI grid (the
// Character row)
inline int ffnPartyDieD6()
    { return 12; }

// The die the party routing row starts at on the Monster Level VII grid (the
// Character row)
inline int ffnPartyDieD7()
    { return 6; }

// The die the party routing row starts at on the Monster Level VIII grid (the
// Character row)
inline int ffnPartyDieD8()
    { return 7; }

// The die the party routing row starts at on the Monster Level IX grid (the
// Character row)
inline int ffnPartyDieD9()
    { return 7; }

// The die the party routing row starts at on the Monster Level X grid (the
// Character row)
inline int ffnPartyDieD10()
    { return 20; }

// The die the Sphinx routing row starts at (Level VII)
inline int ffnSphinxDieLo()
    { return 89; }

// The die the Dragon routing row starts at on the Monster Level III grid
inline int ffnDragonDieD3()
    { return 27; }

// The die the Dragon routing row starts at on the Monster Level IV grid
inline int ffnDragonDieD4()
    { return 25; }

// The die the Dragon routing row starts at on the Monster Level V grid
inline int ffnDragonDieD5()
    { return 31; }

// The die the Dragon routing row starts at on the Monster Level VI grid
inline int ffnDragonDieD6()
    { return 22; }

// The die the Dragon routing row starts at on the Monster Level VII grid
inline int ffnDragonDieD7()
    { return 26; }

// The die the Dragon routing row starts at on the Monster Level VIII grid
inline int ffnDragonDieD8()
    { return 20; }

// The die the Dragon routing row starts at on the Monster Level IX grid
inline int ffnDragonDieD9()
    { return 20; }

// The die the Dragon routing row starts at on the Monster Level X grid
inline int ffnDragonDieD10()
    { return 31; }

// ---- the Level I grid pins (the R846 walk) ----

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnL1Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 7;
        case 4:
            return 14;
        case 5:
            return 16;
        case 6:
            return 18;
        case 7:
            return 20;
        case 8:
            return 21;
        case 9:
            return 23;
        case 10:
            return 24;
        case 11:
            return 25;
        case 12:
            return 26;
        case 13:
            return 29;
        case 14:
            return 30;
        case 15:
            return 34;
        case 16:
            return 35;
        case 17:
            return 39;
        case 18:
            return 47;
        case 19:
            return 51;
        case 20:
            return 55;
        case 21:
            return 57;
        case 22:
            return 58;
        case 23:
            return 60;
        case 24:
            return 68;
        case 25:
            return 71;
        case 26:
            return 78;
        case 27:
            return 80;
        case 28:
            return 85;
        case 29:
            return 87;
        case 30:
            return 91;
        case 31:
            return 98;
        case 32:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnL1Hi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 13;
        case 4:
            return 15;
        case 5:
            return 17;
        case 6:
            return 19;
        case 7:
            return 20;
        case 8:
            return 22;
        case 9:
            return 23;
        case 10:
            return 24;
        case 11:
            return 25;
        case 12:
            return 28;
        case 13:
            return 29;
        case 14:
            return 33;
        case 15:
            return 34;
        case 16:
            return 38;
        case 17:
            return 46;
        case 18:
            return 50;
        case 19:
            return 54;
        case 20:
            return 56;
        case 21:
            return 57;
        case 22:
            return 59;
        case 23:
            return 67;
        case 24:
            return 70;
        case 25:
            return 77;
        case 26:
            return 79;
        case 27:
            return 84;
        case 28:
            return 86;
        case 29:
            return 90;
        case 30:
            return 97;
        case 31:
            return 98;
        case 32:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// grids)
inline int ffnL1Ord(int b)
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
        case 17:
            return 17;
        case 18:
            return 18;
        case 19:
            return 19;
        case 20:
            return 20;
        case 21:
            return 21;
        case 22:
            return 22;
        case 23:
            return 23;
        case 24:
            return 24;
        case 25:
            return 25;
        case 26:
            return 26;
        case 27:
            return 27;
        case 28:
            return 28;
        case 29:
            return 29;
        case 30:
            return 30;
        case 31:
            return 31;
        case 32:
            return 32;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffnL1Src(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 3;
        case 9:
            return 1;
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
            return 1;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 3;
        case 19:
            return 1;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 1;
        case 24:
            return 4;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 3;
        case 30:
            return 3;
        case 31:
            return 3;
        case 32:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the routing rows and the ink-dash rows)
inline int ffnL1NumMin(int b)
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
            return 3;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 4;
        case 10:
            return 1;
        case 11:
            return 4;
        case 12:
            return 6;
        case 13:
            return 5;
        case 14:
            return 6;
        case 15:
            return 9;
        case 16:
            return 2;
        case 17:
            return 0;
        case 18:
            return 6;
        case 19:
            return 6;
        case 20:
            return 3;
        case 21:
            return 2;
        case 22:
            return 1;
        case 23:
            return 7;
        case 24:
            return 1;
        case 25:
            return 5;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 8;
        case 32:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells
inline int ffnL1NumMax(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 4;
        case 4:
            return 18;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 14;
        case 10:
            return 1;
        case 11:
            return 11;
        case 12:
            return 17;
        case 13:
            return 15;
        case 14:
            return 15;
        case 15:
            return 16;
        case 16:
            return 8;
        case 17:
            return 0;
        case 18:
            return 20;
        case 19:
            return 17;
        case 20:
            return 18;
        case 21:
            return 8;
        case 22:
            return 4;
        case 23:
            return 12;
        case 24:
            return 4;
        case 25:
            return 20;
        case 26:
            return 3;
        case 27:
            return 2;
        case 28:
            return 4;
        case 29:
            return 8;
        case 30:
            return 1;
        case 31:
            return 15;
        case 32:
            return 3;
        default:
            return 0;
        }
    }

// The special cells (0 a creature row, 1 Character, 2 Dragon, 3 Human, 4
// Sphinx, 5 the Elemental group)
inline int ffnL1Sp(int b)
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
            return 3;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level II grid pins (the R846 walk) ----

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnL2Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 7;
        case 4:
            return 15;
        case 5:
            return 25;
        case 6:
            return 27;
        case 7:
            return 29;
        case 8:
            return 31;
        case 9:
            return 34;
        case 10:
            return 38;
        case 11:
            return 39;
        case 12:
            return 41;
        case 13:
            return 42;
        case 14:
            return 44;
        case 15:
            return 49;
        case 16:
            return 51;
        case 17:
            return 55;
        case 18:
            return 59;
        case 19:
            return 60;
        case 20:
            return 62;
        case 21:
            return 66;
        case 22:
            return 67;
        case 23:
            return 71;
        case 24:
            return 74;
        case 25:
            return 76;
        case 26:
            return 79;
        case 27:
            return 87;
        case 28:
            return 95;
        case 29:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnL2Hi(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 14;
        case 4:
            return 24;
        case 5:
            return 26;
        case 6:
            return 28;
        case 7:
            return 30;
        case 8:
            return 33;
        case 9:
            return 37;
        case 10:
            return 38;
        case 11:
            return 40;
        case 12:
            return 41;
        case 13:
            return 43;
        case 14:
            return 48;
        case 15:
            return 50;
        case 16:
            return 54;
        case 17:
            return 58;
        case 18:
            return 59;
        case 19:
            return 61;
        case 20:
            return 65;
        case 21:
            return 66;
        case 22:
            return 70;
        case 23:
            return 73;
        case 24:
            return 75;
        case 25:
            return 78;
        case 26:
            return 86;
        case 27:
            return 94;
        case 28:
            return 98;
        case 29:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// grids)
inline int ffnL2Ord(int b)
    {
        switch (b) {
        case 0:
            return 33;
        case 1:
            return 34;
        case 2:
            return 35;
        case 3:
            return 36;
        case 4:
            return 37;
        case 5:
            return 38;
        case 6:
            return 39;
        case 7:
            return 40;
        case 8:
            return 41;
        case 9:
            return 42;
        case 10:
            return 43;
        case 11:
            return 44;
        case 12:
            return 45;
        case 13:
            return 46;
        case 14:
            return 47;
        case 15:
            return 48;
        case 16:
            return 49;
        case 17:
            return 50;
        case 18:
            return 51;
        case 19:
            return 52;
        case 20:
            return 53;
        case 21:
            return 54;
        case 22:
            return 24;
        case 23:
            return 55;
        case 24:
            return 56;
        case 25:
            return 57;
        case 26:
            return 58;
        case 27:
            return 59;
        case 28:
            return 60;
        case 29:
            return 61;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffnL2Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 1;
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
            return 3;
        case 17:
            return 3;
        case 18:
            return 3;
        case 19:
            return 3;
        case 20:
            return 1;
        case 21:
            return 3;
        case 22:
            return 4;
        case 23:
            return 3;
        case 24:
            return 3;
        case 25:
            return 3;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 3;
        case 29:
            return 3;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the routing rows and the ink-dash rows)
inline int ffnL2NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
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
            return 4;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 4;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 4;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 2;
        case 28:
            return 1;
        case 29:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells
inline int ffnL2NumMax(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 13;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 8;
        case 7:
            return 8;
        case 8:
            return 8;
        case 9:
            return 6;
        case 10:
            return 7;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 2;
        case 14:
            return 10;
        case 15:
            return 12;
        case 16:
            return 8;
        case 17:
            return 12;
        case 18:
            return 6;
        case 19:
            return 6;
        case 20:
            return 10;
        case 21:
            return 6;
        case 22:
            return 4;
        case 23:
            return 8;
        case 24:
            return 10;
        case 25:
            return 8;
        case 26:
            return 4;
        case 27:
            return 8;
        case 28:
            return 8;
        case 29:
            return 8;
        default:
            return 0;
        }
    }

// The special cells (0 a creature row, 1 Character, 2 Dragon, 3 Human, 4
// Sphinx, 5 the Elemental group)
inline int ffnL2Sp(int b)
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
            return 1;
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
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level III grid pins (the R846 walk) ----

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnL3Lo(int b)
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
            return 9;
        case 6:
            return 10;
        case 7:
            return 11;
        case 8:
            return 12;
        case 9:
            return 16;
        case 10:
            return 22;
        case 11:
            return 23;
        case 12:
            return 24;
        case 13:
            return 27;
        case 14:
            return 28;
        case 15:
            return 29;
        case 16:
            return 30;
        case 17:
            return 31;
        case 18:
            return 32;
        case 19:
            return 34;
        case 20:
            return 35;
        case 21:
            return 36;
        case 22:
            return 37;
        case 23:
            return 38;
        case 24:
            return 39;
        case 25:
            return 42;
        case 26:
            return 45;
        case 27:
            return 46;
        case 28:
            return 47;
        case 29:
            return 48;
        case 30:
            return 51;
        case 31:
            return 53;
        case 32:
            return 56;
        case 33:
            return 59;
        case 34:
            return 60;
        case 35:
            return 61;
        case 36:
            return 63;
        case 37:
            return 64;
        case 38:
            return 67;
        case 39:
            return 72;
        case 40:
            return 74;
        case 41:
            return 75;
        case 42:
            return 76;
        case 43:
            return 77;
        case 44:
            return 78;
        case 45:
            return 82;
        case 46:
            return 86;
        case 47:
            return 89;
        case 48:
            return 90;
        case 49:
            return 91;
        case 50:
            return 92;
        case 51:
            return 94;
        case 52:
            return 95;
        case 53:
            return 97;
        case 54:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnL3Hi(int b)
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
            return 8;
        case 5:
            return 9;
        case 6:
            return 10;
        case 7:
            return 11;
        case 8:
            return 15;
        case 9:
            return 21;
        case 10:
            return 22;
        case 11:
            return 23;
        case 12:
            return 26;
        case 13:
            return 27;
        case 14:
            return 28;
        case 15:
            return 29;
        case 16:
            return 30;
        case 17:
            return 31;
        case 18:
            return 33;
        case 19:
            return 34;
        case 20:
            return 35;
        case 21:
            return 36;
        case 22:
            return 37;
        case 23:
            return 38;
        case 24:
            return 41;
        case 25:
            return 44;
        case 26:
            return 45;
        case 27:
            return 46;
        case 28:
            return 47;
        case 29:
            return 50;
        case 30:
            return 52;
        case 31:
            return 55;
        case 32:
            return 63;
        case 33:
            return 59;
        case 34:
            return 60;
        case 35:
            return 62;
        case 36:
            return 63;
        case 37:
            return 66;
        case 38:
            return 71;
        case 39:
            return 73;
        case 40:
            return 74;
        case 41:
            return 75;
        case 42:
            return 76;
        case 43:
            return 77;
        case 44:
            return 81;
        case 45:
            return 85;
        case 46:
            return 88;
        case 47:
            return 89;
        case 48:
            return 90;
        case 49:
            return 91;
        case 50:
            return 93;
        case 51:
            return 94;
        case 52:
            return 96;
        case 53:
            return 98;
        case 54:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// grids)
inline int ffnL3Ord(int b)
    {
        switch (b) {
        case 0:
            return 62;
        case 1:
            return 33;
        case 2:
            return 63;
        case 3:
            return 64;
        case 4:
            return 65;
        case 5:
            return 66;
        case 6:
            return 67;
        case 7:
            return 68;
        case 8:
            return 69;
        case 9:
            return 37;
        case 10:
            return 70;
        case 11:
            return 71;
        case 12:
            return 72;
        case 13:
            return 73;
        case 14:
            return 74;
        case 15:
            return 75;
        case 16:
            return 76;
        case 17:
            return 77;
        case 18:
            return 78;
        case 19:
            return 79;
        case 20:
            return 80;
        case 21:
            return 81;
        case 22:
            return 82;
        case 23:
            return 83;
        case 24:
            return 84;
        case 25:
            return 85;
        case 26:
            return 86;
        case 27:
            return 87;
        case 28:
            return 88;
        case 29:
            return 89;
        case 30:
            return 90;
        case 31:
            return 91;
        case 32:
            return 92;
        case 33:
            return 93;
        case 34:
            return 94;
        case 35:
            return 95;
        case 36:
            return 96;
        case 37:
            return 97;
        case 38:
            return 98;
        case 39:
            return 24;
        case 40:
            return 99;
        case 41:
            return 100;
        case 42:
            return 101;
        case 43:
            return 102;
        case 44:
            return 103;
        case 45:
            return 104;
        case 46:
            return 105;
        case 47:
            return 106;
        case 48:
            return 107;
        case 49:
            return 108;
        case 50:
            return 109;
        case 51:
            return 110;
        case 52:
            return 111;
        case 53:
            return 112;
        case 54:
            return 113;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffnL3Src(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 3;
        case 18:
            return 3;
        case 19:
            return 3;
        case 20:
            return 3;
        case 21:
            return 1;
        case 22:
            return 3;
        case 23:
            return 3;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 3;
        case 27:
            return 3;
        case 28:
            return 3;
        case 29:
            return 3;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 3;
        case 34:
            return 3;
        case 35:
            return 3;
        case 36:
            return 3;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 4;
        case 40:
            return 3;
        case 41:
            return 3;
        case 42:
            return 3;
        case 43:
            return 3;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 1;
        case 47:
            return 3;
        case 48:
            return 3;
        case 49:
            return 3;
        case 50:
            return 1;
        case 51:
            return 3;
        case 52:
            return 1;
        case 53:
            return 3;
        case 54:
            return 3;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the routing rows and the ink-dash rows)
inline int ffnL3NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
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
            return 2;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 0;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 2;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 1;
        case 44:
            return 1;
        case 45:
            return 2;
        case 46:
            return 5;
        case 47:
            return 1;
        case 48:
            return 1;
        case 49:
            return 1;
        case 50:
            return 1;
        case 51:
            return 1;
        case 52:
            return 1;
        case 53:
            return 1;
        case 54:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells
inline int ffnL3NumMax(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 11;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 3;
        case 8:
            return 7;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 12;
        case 12:
            return 5;
        case 13:
            return 0;
        case 14:
            return 7;
        case 15:
            return 1;
        case 16:
            return 6;
        case 17:
            return 16;
        case 18:
            return 6;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 3;
        case 22:
            return 4;
        case 23:
            return 3;
        case 24:
            return 1;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 4;
        case 30:
            return 4;
        case 31:
            return 3;
        case 32:
            return 5;
        case 33:
            return 3;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 3;
        case 39:
            return 4;
        case 40:
            return 6;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 3;
        case 44:
            return 3;
        case 45:
            return 5;
        case 46:
            return 15;
        case 47:
            return 1;
        case 48:
            return 1;
        case 49:
            return 2;
        case 50:
            return 3;
        case 51:
            return 1;
        case 52:
            return 4;
        case 53:
            return 2;
        case 54:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 a creature row, 1 Character, 2 Dragon, 3 Human, 4
// Sphinx, 5 the Elemental group)
inline int ffnL3Sp(int b)
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
            return 2;
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
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level IV grid pins (the R846 walk) ----

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnL4Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 7;
        case 3:
            return 9;
        case 4:
            return 11;
        case 5:
            return 13;
        case 6:
            return 22;
        case 7:
            return 23;
        case 8:
            return 24;
        case 9:
            return 25;
        case 10:
            return 27;
        case 11:
            return 29;
        case 12:
            return 30;
        case 13:
            return 32;
        case 14:
            return 33;
        case 15:
            return 35;
        case 16:
            return 39;
        case 17:
            return 41;
        case 18:
            return 43;
        case 19:
            return 45;
        case 20:
            return 46;
        case 21:
            return 48;
        case 22:
            return 49;
        case 23:
            return 53;
        case 24:
            return 54;
        case 25:
            return 56;
        case 26:
            return 57;
        case 27:
            return 58;
        case 28:
            return 66;
        case 29:
            return 67;
        case 30:
            return 71;
        case 31:
            return 73;
        case 32:
            return 78;
        case 33:
            return 80;
        case 34:
            return 81;
        case 35:
            return 82;
        case 36:
            return 86;
        case 37:
            return 87;
        case 38:
            return 91;
        case 39:
            return 93;
        case 40:
            return 95;
        case 41:
            return 97;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnL4Hi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 10;
        case 4:
            return 12;
        case 5:
            return 21;
        case 6:
            return 22;
        case 7:
            return 23;
        case 8:
            return 24;
        case 9:
            return 26;
        case 10:
            return 28;
        case 11:
            return 29;
        case 12:
            return 31;
        case 13:
            return 32;
        case 14:
            return 34;
        case 15:
            return 38;
        case 16:
            return 40;
        case 17:
            return 42;
        case 18:
            return 44;
        case 19:
            return 45;
        case 20:
            return 47;
        case 21:
            return 48;
        case 22:
            return 52;
        case 23:
            return 53;
        case 24:
            return 55;
        case 25:
            return 56;
        case 26:
            return 57;
        case 27:
            return 65;
        case 28:
            return 66;
        case 29:
            return 70;
        case 30:
            return 72;
        case 31:
            return 77;
        case 32:
            return 79;
        case 33:
            return 80;
        case 34:
            return 81;
        case 35:
            return 85;
        case 36:
            return 86;
        case 37:
            return 90;
        case 38:
            return 92;
        case 39:
            return 94;
        case 40:
            return 96;
        case 41:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// grids)
inline int ffnL4Ord(int b)
    {
        switch (b) {
        case 0:
            return 33;
        case 1:
            return 114;
        case 2:
            return 115;
        case 3:
            return 116;
        case 4:
            return 117;
        case 5:
            return 37;
        case 6:
            return 118;
        case 7:
            return 119;
        case 8:
            return 120;
        case 9:
            return 73;
        case 10:
            return 121;
        case 11:
            return 122;
        case 12:
            return 123;
        case 13:
            return 124;
        case 14:
            return 125;
        case 15:
            return 126;
        case 16:
            return 127;
        case 17:
            return 128;
        case 18:
            return 129;
        case 19:
            return 130;
        case 20:
            return 131;
        case 21:
            return 132;
        case 22:
            return 133;
        case 23:
            return 134;
        case 24:
            return 135;
        case 25:
            return 136;
        case 26:
            return 137;
        case 27:
            return 138;
        case 28:
            return 139;
        case 29:
            return 140;
        case 30:
            return 141;
        case 31:
            return 142;
        case 32:
            return 143;
        case 33:
            return 144;
        case 34:
            return 145;
        case 35:
            return 146;
        case 36:
            return 147;
        case 37:
            return 148;
        case 38:
            return 149;
        case 39:
            return 150;
        case 40:
            return 151;
        case 41:
            return 152;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffnL4Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 0;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 3;
        case 19:
            return 1;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 1;
        case 23:
            return 4;
        case 24:
            return 3;
        case 25:
            return 3;
        case 26:
            return 3;
        case 27:
            return 1;
        case 28:
            return 3;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 3;
        case 33:
            return 3;
        case 34:
            return 3;
        case 35:
            return 1;
        case 36:
            return 3;
        case 37:
            return 1;
        case 38:
            return 3;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 3;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the routing rows and the ink-dash rows)
inline int ffnL4NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
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
        case 19:
            return 1;
        case 20:
            return 2;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 2;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 2;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 2;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells
inline int ffnL4NumMax(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 3;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 2;
        case 16:
            return 4;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 5;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 12;
        case 26:
            return 6;
        case 27:
            return 2;
        case 28:
            return 8;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 2;
        case 33:
            return 2;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 2;
        case 37:
            return 2;
        case 38:
            return 2;
        case 39:
            return 1;
        case 40:
            return 3;
        case 41:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 a creature row, 1 Character, 2 Dragon, 3 Human, 4
// Sphinx, 5 the Elemental group)
inline int ffnL4Sp(int b)
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
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 2;
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
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level V grid pins (the R846 walk) ----

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnL5Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 7;
        case 3:
            return 20;
        case 4:
            return 26;
        case 5:
            return 27;
        case 6:
            return 29;
        case 7:
            return 31;
        case 8:
            return 33;
        case 9:
            return 34;
        case 10:
            return 35;
        case 11:
            return 36;
        case 12:
            return 40;
        case 13:
            return 41;
        case 14:
            return 43;
        case 15:
            return 44;
        case 16:
            return 45;
        case 17:
            return 48;
        case 18:
            return 56;
        case 19:
            return 60;
        case 20:
            return 64;
        case 21:
            return 66;
        case 22:
            return 67;
        case 23:
            return 70;
        case 24:
            return 72;
        case 25:
            return 74;
        case 26:
            return 82;
        case 27:
            return 86;
        case 28:
            return 94;
        case 29:
            return 96;
        case 30:
            return 98;
        case 31:
            return 99;
        case 32:
            return 100;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnL5Hi(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 19;
        case 3:
            return 25;
        case 4:
            return 26;
        case 5:
            return 28;
        case 6:
            return 30;
        case 7:
            return 32;
        case 8:
            return 33;
        case 9:
            return 34;
        case 10:
            return 35;
        case 11:
            return 39;
        case 12:
            return 40;
        case 13:
            return 42;
        case 14:
            return 43;
        case 15:
            return 44;
        case 16:
            return 47;
        case 17:
            return 55;
        case 18:
            return 59;
        case 19:
            return 63;
        case 20:
            return 65;
        case 21:
            return 66;
        case 22:
            return 69;
        case 23:
            return 71;
        case 24:
            return 73;
        case 25:
            return 81;
        case 26:
            return 85;
        case 27:
            return 93;
        case 28:
            return 95;
        case 29:
            return 97;
        case 30:
            return 98;
        case 31:
            return 99;
        case 32:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// grids)
inline int ffnL5Ord(int b)
    {
        switch (b) {
        case 0:
            return 33;
        case 1:
            return 6;
        case 2:
            return 37;
        case 3:
            return 153;
        case 4:
            return 154;
        case 5:
            return 155;
        case 6:
            return 156;
        case 7:
            return 73;
        case 8:
            return 74;
        case 9:
            return 157;
        case 10:
            return 158;
        case 11:
            return 133;
        case 12:
            return 134;
        case 13:
            return 159;
        case 14:
            return 160;
        case 15:
            return 161;
        case 16:
            return 162;
        case 17:
            return 163;
        case 18:
            return 164;
        case 19:
            return 165;
        case 20:
            return 166;
        case 21:
            return 167;
        case 22:
            return 168;
        case 23:
            return 169;
        case 24:
            return 170;
        case 25:
            return 171;
        case 26:
            return 172;
        case 27:
            return 173;
        case 28:
            return 174;
        case 29:
            return 175;
        case 30:
            return 176;
        case 31:
            return 177;
        case 32:
            return 178;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffnL5Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 1;
        case 12:
            return 4;
        case 13:
            return 3;
        case 14:
            return 1;
        case 15:
            return 3;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 3;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 3;
        case 29:
            return 3;
        case 30:
            return 3;
        case 31:
            return 3;
        case 32:
            return 3;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the routing rows and the ink-dash rows)
inline int ffnL5NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
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
            return 3;
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
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 2;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells
inline int ffnL5NumMax(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 0;
        case 8:
            return 12;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 3;
        case 19:
            return 3;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 3;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 2;
        case 28:
            return 5;
        case 29:
            return 2;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 a creature row, 1 Character, 2 Dragon, 3 Human, 4
// Sphinx, 5 the Elemental group)
inline int ffnL5Sp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 2;
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
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level VI grid pins (the R846 walk) ----

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnL6Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 8;
        case 4:
            return 12;
        case 5:
            return 20;
        case 6:
            return 21;
        case 7:
            return 22;
        case 8:
            return 24;
        case 9:
            return 27;
        case 10:
            return 30;
        case 11:
            return 34;
        case 12:
            return 35;
        case 13:
            return 37;
        case 14:
            return 39;
        case 15:
            return 40;
        case 16:
            return 42;
        case 17:
            return 44;
        case 18:
            return 48;
        case 19:
            return 50;
        case 20:
            return 51;
        case 21:
            return 52;
        case 22:
            return 54;
        case 23:
            return 60;
        case 24:
            return 62;
        case 25:
            return 64;
        case 26:
            return 66;
        case 27:
            return 68;
        case 28:
            return 72;
        case 29:
            return 73;
        case 30:
            return 75;
        case 31:
            return 76;
        case 32:
            return 77;
        case 33:
            return 78;
        case 34:
            return 84;
        case 35:
            return 86;
        case 36:
            return 87;
        case 37:
            return 91;
        case 38:
            return 93;
        case 39:
            return 97;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnL6Hi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 7;
        case 3:
            return 11;
        case 4:
            return 19;
        case 5:
            return 20;
        case 6:
            return 21;
        case 7:
            return 23;
        case 8:
            return 26;
        case 9:
            return 29;
        case 10:
            return 33;
        case 11:
            return 34;
        case 12:
            return 36;
        case 13:
            return 38;
        case 14:
            return 39;
        case 15:
            return 41;
        case 16:
            return 43;
        case 17:
            return 47;
        case 18:
            return 49;
        case 19:
            return 50;
        case 20:
            return 51;
        case 21:
            return 53;
        case 22:
            return 59;
        case 23:
            return 61;
        case 24:
            return 63;
        case 25:
            return 65;
        case 26:
            return 67;
        case 27:
            return 71;
        case 28:
            return 72;
        case 29:
            return 74;
        case 30:
            return 75;
        case 31:
            return 76;
        case 32:
            return 77;
        case 33:
            return 83;
        case 34:
            return 85;
        case 35:
            return 86;
        case 36:
            return 90;
        case 37:
            return 92;
        case 38:
            return 96;
        case 39:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// grids)
inline int ffnL6Ord(int b)
    {
        switch (b) {
        case 0:
            return 33;
        case 1:
            return 179;
        case 2:
            return 180;
        case 3:
            return 181;
        case 4:
            return 37;
        case 5:
            return 182;
        case 6:
            return 183;
        case 7:
            return 73;
        case 8:
            return 184;
        case 9:
            return 185;
        case 10:
            return 133;
        case 11:
            return 134;
        case 12:
            return 186;
        case 13:
            return 187;
        case 14:
            return 188;
        case 15:
            return 164;
        case 16:
            return 189;
        case 17:
            return 190;
        case 18:
            return 191;
        case 19:
            return 140;
        case 20:
            return 192;
        case 21:
            return 193;
        case 22:
            return 194;
        case 23:
            return 195;
        case 24:
            return 196;
        case 25:
            return 197;
        case 26:
            return 198;
        case 27:
            return 199;
        case 28:
            return 200;
        case 29:
            return 201;
        case 30:
            return 202;
        case 31:
            return 203;
        case 32:
            return 204;
        case 33:
            return 205;
        case 34:
            return 206;
        case 35:
            return 207;
        case 36:
            return 208;
        case 37:
            return 209;
        case 38:
            return 210;
        case 39:
            return 211;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffnL6Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 3;
        case 10:
            return 1;
        case 11:
            return 4;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 3;
        case 24:
            return 3;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 3;
        case 29:
            return 1;
        case 30:
            return 3;
        case 31:
            return 3;
        case 32:
            return 3;
        case 33:
            return 1;
        case 34:
            return 3;
        case 35:
            return 3;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the routing rows and the ink-dash rows)
inline int ffnL6NumMin(int b)
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
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
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
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells
inline int ffnL6NumMax(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 0;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 2;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 4;
        case 21:
            return 2;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 4;
        case 26:
            return 2;
        case 27:
            return 3;
        case 28:
            return 1;
        case 29:
            return 3;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 3;
        case 34:
            return 2;
        case 35:
            return 1;
        case 36:
            return 4;
        case 37:
            return 1;
        case 38:
            return 2;
        case 39:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 a creature row, 1 Character, 2 Dragon, 3 Human, 4
// Sphinx, 5 the Elemental group)
inline int ffnL6Sp(int b)
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
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 2;
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
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level VII grid pins (the R846 walk) ----

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnL7Lo(int b)
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
            return 15;
        case 5:
            return 17;
        case 6:
            return 18;
        case 7:
            return 19;
        case 8:
            return 20;
        case 9:
            return 21;
        case 10:
            return 22;
        case 11:
            return 23;
        case 12:
            return 24;
        case 13:
            return 25;
        case 14:
            return 26;
        case 15:
            return 28;
        case 16:
            return 29;
        case 17:
            return 31;
        case 18:
            return 32;
        case 19:
            return 33;
        case 20:
            return 35;
        case 21:
            return 36;
        case 22:
            return 39;
        case 23:
            return 40;
        case 24:
            return 42;
        case 25:
            return 43;
        case 26:
            return 45;
        case 27:
            return 46;
        case 28:
            return 47;
        case 29:
            return 48;
        case 30:
            return 52;
        case 31:
            return 53;
        case 32:
            return 54;
        case 33:
            return 55;
        case 34:
            return 56;
        case 35:
            return 57;
        case 36:
            return 58;
        case 37:
            return 62;
        case 38:
            return 63;
        case 39:
            return 65;
        case 40:
            return 67;
        case 41:
            return 69;
        case 42:
            return 71;
        case 43:
            return 73;
        case 44:
            return 74;
        case 45:
            return 75;
        case 46:
            return 76;
        case 47:
            return 78;
        case 48:
            return 80;
        case 49:
            return 82;
        case 50:
            return 83;
        case 51:
            return 87;
        case 52:
            return 89;
        case 53:
            return 91;
        case 54:
            return 93;
        case 55:
            return 94;
        case 56:
            return 96;
        case 57:
            return 100;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnL7Hi(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 12;
        case 3:
            return 14;
        case 4:
            return 16;
        case 5:
            return 17;
        case 6:
            return 18;
        case 7:
            return 19;
        case 8:
            return 20;
        case 9:
            return 21;
        case 10:
            return 22;
        case 11:
            return 23;
        case 12:
            return 24;
        case 13:
            return 25;
        case 14:
            return 27;
        case 15:
            return 28;
        case 16:
            return 30;
        case 17:
            return 31;
        case 18:
            return 32;
        case 19:
            return 34;
        case 20:
            return 35;
        case 21:
            return 38;
        case 22:
            return 39;
        case 23:
            return 41;
        case 24:
            return 42;
        case 25:
            return 44;
        case 26:
            return 45;
        case 27:
            return 46;
        case 28:
            return 47;
        case 29:
            return 51;
        case 30:
            return 52;
        case 31:
            return 53;
        case 32:
            return 54;
        case 33:
            return 55;
        case 34:
            return 56;
        case 35:
            return 57;
        case 36:
            return 61;
        case 37:
            return 62;
        case 38:
            return 64;
        case 39:
            return 66;
        case 40:
            return 68;
        case 41:
            return 70;
        case 42:
            return 72;
        case 43:
            return 73;
        case 44:
            return 74;
        case 45:
            return 75;
        case 46:
            return 77;
        case 47:
            return 79;
        case 48:
            return 81;
        case 49:
            return 82;
        case 50:
            return 86;
        case 51:
            return 88;
        case 52:
            return 90;
        case 53:
            return 92;
        case 54:
            return 93;
        case 55:
            return 95;
        case 56:
            return 99;
        case 57:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// grids)
inline int ffnL7Ord(int b)
    {
        switch (b) {
        case 0:
            return 212;
        case 1:
            return 213;
        case 2:
            return 37;
        case 3:
            return 214;
        case 4:
            return 215;
        case 5:
            return 216;
        case 6:
            return 217;
        case 7:
            return 218;
        case 8:
            return 219;
        case 9:
            return 220;
        case 10:
            return 221;
        case 11:
            return 222;
        case 12:
            return 223;
        case 13:
            return 224;
        case 14:
            return 73;
        case 15:
            return 225;
        case 16:
            return 226;
        case 17:
            return 227;
        case 18:
            return 228;
        case 19:
            return 229;
        case 20:
            return 230;
        case 21:
            return 231;
        case 22:
            return 232;
        case 23:
            return 233;
        case 24:
            return 234;
        case 25:
            return 235;
        case 26:
            return 236;
        case 27:
            return 237;
        case 28:
            return 238;
        case 29:
            return 133;
        case 30:
            return 134;
        case 31:
            return 239;
        case 32:
            return 240;
        case 33:
            return 241;
        case 34:
            return 242;
        case 35:
            return 243;
        case 36:
            return 244;
        case 37:
            return 245;
        case 38:
            return 246;
        case 39:
            return 247;
        case 40:
            return 248;
        case 41:
            return 249;
        case 42:
            return 250;
        case 43:
            return 251;
        case 44:
            return 252;
        case 45:
            return 253;
        case 46:
            return 254;
        case 47:
            return 255;
        case 48:
            return 256;
        case 49:
            return 257;
        case 50:
            return 258;
        case 51:
            return 259;
        case 52:
            return 260;
        case 53:
            return 261;
        case 54:
            return 262;
        case 55:
            return 263;
        case 56:
            return 264;
        case 57:
            return 265;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffnL7Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
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
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 3;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 3;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 3;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 3;
        case 28:
            return 3;
        case 29:
            return 1;
        case 30:
            return 4;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 3;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 3;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 1;
        case 44:
            return 3;
        case 45:
            return 3;
        case 46:
            return 1;
        case 47:
            return 1;
        case 48:
            return 1;
        case 49:
            return 3;
        case 50:
            return 1;
        case 51:
            return 1;
        case 52:
            return 0;
        case 53:
            return 1;
        case 54:
            return 3;
        case 55:
            return 1;
        case 56:
            return 1;
        case 57:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the routing rows and the ink-dash rows)
inline int ffnL7NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
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
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 1;
        case 42:
            return 1;
        case 43:
            return 1;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 1;
        case 47:
            return 1;
        case 48:
            return 1;
        case 49:
            return 1;
        case 50:
            return 1;
        case 51:
            return 1;
        case 52:
            return 0;
        case 53:
            return 1;
        case 54:
            return 1;
        case 55:
            return 1;
        case 56:
            return 1;
        case 57:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells
inline int ffnL7NumMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 2;
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
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 2;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 2;
        case 21:
            return 3;
        case 22:
            return 2;
        case 23:
            return 3;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 2;
        case 34:
            return 1;
        case 35:
            return 3;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 2;
        case 40:
            return 2;
        case 41:
            return 2;
        case 42:
            return 1;
        case 43:
            return 2;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 2;
        case 47:
            return 2;
        case 48:
            return 2;
        case 49:
            return 1;
        case 50:
            return 1;
        case 51:
            return 1;
        case 52:
            return 0;
        case 53:
            return 1;
        case 54:
            return 1;
        case 55:
            return 2;
        case 56:
            return 3;
        case 57:
            return 3;
        default:
            return 0;
        }
    }

// The special cells (0 a creature row, 1 Character, 2 Dragon, 3 Human, 4
// Sphinx, 5 the Elemental group)
inline int ffnL7Sp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
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
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 2;
        case 15:
            return 0;
        case 16:
            return 5;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 4;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level VIII grid pins (the R846 walk) ----

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnL8Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 7;
        case 3:
            return 15;
        case 4:
            return 16;
        case 5:
            return 17;
        case 6:
            return 18;
        case 7:
            return 19;
        case 8:
            return 20;
        case 9:
            return 22;
        case 10:
            return 25;
        case 11:
            return 29;
        case 12:
            return 31;
        case 13:
            return 33;
        case 14:
            return 38;
        case 15:
            return 39;
        case 16:
            return 41;
        case 17:
            return 45;
        case 18:
            return 53;
        case 19:
            return 57;
        case 20:
            return 60;
        case 21:
            return 62;
        case 22:
            return 71;
        case 23:
            return 73;
        case 24:
            return 76;
        case 25:
            return 77;
        case 26:
            return 78;
        case 27:
            return 81;
        case 28:
            return 88;
        case 29:
            return 95;
        case 30:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnL8Hi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 14;
        case 3:
            return 15;
        case 4:
            return 16;
        case 5:
            return 17;
        case 6:
            return 18;
        case 7:
            return 19;
        case 8:
            return 21;
        case 9:
            return 24;
        case 10:
            return 26;
        case 11:
            return 30;
        case 12:
            return 32;
        case 13:
            return 37;
        case 14:
            return 38;
        case 15:
            return 40;
        case 16:
            return 44;
        case 17:
            return 52;
        case 18:
            return 56;
        case 19:
            return 59;
        case 20:
            return 61;
        case 21:
            return 70;
        case 22:
            return 72;
        case 23:
            return 75;
        case 24:
            return 76;
        case 25:
            return 77;
        case 26:
            return 80;
        case 27:
            return 87;
        case 28:
            return 94;
        case 29:
            return 98;
        case 30:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// grids)
inline int ffnL8Ord(int b)
    {
        switch (b) {
        case 0:
            return 266;
        case 1:
            return 6;
        case 2:
            return 37;
        case 3:
            return 267;
        case 4:
            return 268;
        case 5:
            return 269;
        case 6:
            return 270;
        case 7:
            return 271;
        case 8:
            return 73;
        case 9:
            return 272;
        case 10:
            return 273;
        case 11:
            return 274;
        case 12:
            return 275;
        case 13:
            return 133;
        case 14:
            return 134;
        case 15:
            return 239;
        case 16:
            return 244;
        case 17:
            return 276;
        case 18:
            return 247;
        case 19:
            return 277;
        case 20:
            return 250;
        case 21:
            return 278;
        case 22:
            return 279;
        case 23:
            return 142;
        case 24:
            return 280;
        case 25:
            return 281;
        case 26:
            return 258;
        case 27:
            return 261;
        case 28:
            return 282;
        case 29:
            return 264;
        case 30:
            return 265;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffnL8Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 3;
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
            return 3;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 4;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 3;
        case 23:
            return 1;
        case 24:
            return 3;
        case 25:
            return 4;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the routing rows and the ink-dash rows)
inline int ffnL8NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 0;
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
            return 0;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 2;
        case 30:
            return 2;
        default:
            return 0;
        }
    }

// The number-encountered high cells
inline int ffnL8NumMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 8;
        case 2:
            return 0;
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
            return 2;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 2;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 4;
        case 19:
            return 2;
        case 20:
            return 2;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 5;
        case 30:
            return 5;
        default:
            return 0;
        }
    }

// The special cells (0 a creature row, 1 Character, 2 Dragon, 3 Human, 4
// Sphinx, 5 the Elemental group)
inline int ffnL8Sp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
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
            return 2;
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
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level IX grid pins (the R846 walk) ----

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnL9Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 7;
        case 3:
            return 17;
        case 4:
            return 20;
        case 5:
            return 23;
        case 6:
            return 29;
        case 7:
            return 31;
        case 8:
            return 34;
        case 9:
            return 41;
        case 10:
            return 44;
        case 11:
            return 46;
        case 12:
            return 48;
        case 13:
            return 50;
        case 14:
            return 62;
        case 15:
            return 65;
        case 16:
            return 68;
        case 17:
            return 70;
        case 18:
            return 73;
        case 19:
            return 76;
        case 20:
            return 83;
        case 21:
            return 86;
        case 22:
            return 95;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnL9Hi(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 16;
        case 3:
            return 19;
        case 4:
            return 22;
        case 5:
            return 28;
        case 6:
            return 30;
        case 7:
            return 33;
        case 8:
            return 40;
        case 9:
            return 43;
        case 10:
            return 45;
        case 11:
            return 47;
        case 12:
            return 49;
        case 13:
            return 61;
        case 14:
            return 64;
        case 15:
            return 67;
        case 16:
            return 69;
        case 17:
            return 72;
        case 18:
            return 75;
        case 19:
            return 82;
        case 20:
            return 85;
        case 21:
            return 94;
        case 22:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// grids)
inline int ffnL9Ord(int b)
    {
        switch (b) {
        case 0:
            return 283;
        case 1:
            return 213;
        case 2:
            return 37;
        case 3:
            return 284;
        case 4:
            return 73;
        case 5:
            return 285;
        case 6:
            return 286;
        case 7:
            return 235;
        case 8:
            return 133;
        case 9:
            return 134;
        case 10:
            return 287;
        case 11:
            return 277;
        case 12:
            return 288;
        case 13:
            return 278;
        case 14:
            return 279;
        case 15:
            return 142;
        case 16:
            return 289;
        case 17:
            return 290;
        case 18:
            return 291;
        case 19:
            return 263;
        case 20:
            return 282;
        case 21:
            return 264;
        case 22:
            return 265;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffnL9Src(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 4;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 3;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the routing rows and the ink-dash rows)
inline int ffnL9NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 0;
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
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 2;
        case 22:
            return 2;
        default:
            return 0;
        }
    }

// The number-encountered high cells
inline int ffnL9NumMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 2;
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
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 4;
        case 20:
            return 1;
        case 21:
            return 5;
        case 22:
            return 9;
        default:
            return 0;
        }
    }

// The special cells (0 a creature row, 1 Character, 2 Dragon, 3 Human, 4
// Sphinx, 5 the Elemental group)
inline int ffnL9Sp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 2;
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
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Level X grid pins (the R846 walk) ----

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnL10Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 13;
        case 2:
            return 20;
        case 3:
            return 27;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 40;
        case 7:
            return 42;
        case 8:
            return 51;
        case 9:
            return 54;
        case 10:
            return 63;
        case 11:
            return 76;
        case 12:
            return 79;
        case 13:
            return 80;
        case 14:
            return 90;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnL10Hi(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 19;
        case 2:
            return 26;
        case 3:
            return 29;
        case 4:
            return 30;
        case 5:
            return 39;
        case 6:
            return 41;
        case 7:
            return 50;
        case 8:
            return 53;
        case 9:
            return 62;
        case 10:
            return 75;
        case 11:
            return 78;
        case 12:
            return 79;
        case 13:
            return 89;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// grids)
inline int ffnL10Ord(int b)
    {
        switch (b) {
        case 0:
            return 292;
        case 1:
            return 293;
        case 2:
            return 37;
        case 3:
            return 294;
        case 4:
            return 295;
        case 5:
            return 73;
        case 6:
            return 296;
        case 7:
            return 297;
        case 8:
            return 242;
        case 9:
            return 298;
        case 10:
            return 278;
        case 11:
            return 299;
        case 12:
            return 300;
        case 13:
            return 301;
        case 14:
            return 282;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffnL10Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 0;
        case 6:
            return 4;
        case 7:
            return 1;
        case 8:
            return 3;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 3;
        case 12:
            return 4;
        case 13:
            return 1;
        case 14:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the routing rows and the ink-dash rows)
inline int ffnL10NumMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
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
        case 13:
            return 1;
        case 14:
            return 1;
        default:
            return 0;
        }
    }

// The number-encountered high cells
inline int ffnL10NumMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
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
        case 13:
            return 1;
        case 14:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 a creature row, 1 Character, 2 Dragon, 3 Human, 4
// Sphinx, 5 the Elemental group)
inline int ffnL10Sp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 2;
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
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// ---- the Dragon Subtable pins (the R846 walk) ----

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnD3Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 29;
        case 2:
            return 63;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnD3Hi(int b)
    {
        switch (b) {
        case 0:
            return 28;
        case 1:
            return 62;
        case 2:
            return 100;
        default:
            return 0;
        }
    }

// The type cells (the round-roster ordinal of the dragon type)
inline int ffnD3Type(int b)
    {
        switch (b) {
        case 0:
            return 319;
        case 1:
            return 320;
        case 2:
            return 321;
        default:
            return 0;
        }
    }

// The age cells (-1 the unique court rows, else the first age category: 0
// very young, 1 young, 2 sub-adult, 3 young adult, 4 adult, 5 old, 6 very
// old, 7 ancient)
inline int ffnD3Age(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        default:
            return 0;
        }
    }

// The hit-points-per-die high cells (0 the unreadable or missing ink)
inline int ffnD3Hd1(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        default:
            return 0;
        }
    }

// The hit-points-per-die low cells (0 the unreadable or missing ink)
inline int ffnD3Hd2(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnD4Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 10;
        case 2:
            return 21;
        case 3:
            return 31;
        case 4:
            return 37;
        case 5:
            return 50;
        case 6:
            return 54;
        case 7:
            return 70;
        case 8:
            return 75;
        case 9:
            return 83;
        case 10:
            return 89;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnD4Hi(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 36;
        case 4:
            return 49;
        case 5:
            return 53;
        case 6:
            return 69;
        case 7:
            return 74;
        case 8:
            return 82;
        case 9:
            return 88;
        case 10:
            return 100;
        default:
            return 0;
        }
    }

// The type cells (the round-roster ordinal of the dragon type)
inline int ffnD4Type(int b)
    {
        switch (b) {
        case 0:
            return 319;
        case 1:
            return 322;
        case 2:
            return 320;
        case 3:
            return 323;
        case 4:
            return 324;
        case 5:
            return 325;
        case 6:
            return 326;
        case 7:
            return 327;
        case 8:
            return 328;
        case 9:
            return 329;
        case 10:
            return 321;
        default:
            return 0;
        }
    }

// The age cells (-1 the unique court rows, else the first age category: 0
// very young, 1 young, 2 sub-adult, 3 young adult, 4 adult, 5 old, 6 very
// old, 7 ancient)
inline int ffnD4Age(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
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
        default:
            return 0;
        }
    }

// The hit-points-per-die high cells (0 the unreadable or missing ink)
inline int ffnD4Hd1(int b)
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
            return 0;
        default:
            return 0;
        }
    }

// The hit-points-per-die low cells (0 the unreadable or missing ink)
inline int ffnD4Hd2(int b)
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
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnD5Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 10;
        case 2:
            return 21;
        case 3:
            return 31;
        case 4:
            return 37;
        case 5:
            return 50;
        case 6:
            return 54;
        case 7:
            return 70;
        case 8:
            return 75;
        case 9:
            return 83;
        case 10:
            return 89;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnD5Hi(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 36;
        case 4:
            return 49;
        case 5:
            return 53;
        case 6:
            return 69;
        case 7:
            return 74;
        case 8:
            return 82;
        case 9:
            return 88;
        case 10:
            return 100;
        default:
            return 0;
        }
    }

// The type cells (the round-roster ordinal of the dragon type)
inline int ffnD5Type(int b)
    {
        switch (b) {
        case 0:
            return 319;
        case 1:
            return 322;
        case 2:
            return 320;
        case 3:
            return 323;
        case 4:
            return 324;
        case 5:
            return 325;
        case 6:
            return 326;
        case 7:
            return 327;
        case 8:
            return 328;
        case 9:
            return 329;
        case 10:
            return 321;
        default:
            return 0;
        }
    }

// The age cells (-1 the unique court rows, else the first age category: 0
// very young, 1 young, 2 sub-adult, 3 young adult, 4 adult, 5 old, 6 very
// old, 7 ancient)
inline int ffnD5Age(int b)
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
            return 3;
        default:
            return 0;
        }
    }

// The hit-points-per-die high cells (0 the unreadable or missing ink)
inline int ffnD5Hd1(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 3;
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
            return 4;
        default:
            return 0;
        }
    }

// The hit-points-per-die low cells (0 the unreadable or missing ink)
inline int ffnD5Hd2(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 5;
        default:
            return 0;
        }
    }

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnD6Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 10;
        case 2:
            return 21;
        case 3:
            return 31;
        case 4:
            return 37;
        case 5:
            return 50;
        case 6:
            return 54;
        case 7:
            return 70;
        case 8:
            return 75;
        case 9:
            return 83;
        case 10:
            return 89;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnD6Hi(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 36;
        case 4:
            return 49;
        case 5:
            return 53;
        case 6:
            return 69;
        case 7:
            return 74;
        case 8:
            return 82;
        case 9:
            return 88;
        case 10:
            return 100;
        default:
            return 0;
        }
    }

// The type cells (the round-roster ordinal of the dragon type)
inline int ffnD6Type(int b)
    {
        switch (b) {
        case 0:
            return 319;
        case 1:
            return 322;
        case 2:
            return 320;
        case 3:
            return 323;
        case 4:
            return 324;
        case 5:
            return 325;
        case 6:
            return 326;
        case 7:
            return 327;
        case 8:
            return 328;
        case 9:
            return 329;
        case 10:
            return 321;
        default:
            return 0;
        }
    }

// The age cells (-1 the unique court rows, else the first age category: 0
// very young, 1 young, 2 sub-adult, 3 young adult, 4 adult, 5 old, 6 very
// old, 7 ancient)
inline int ffnD6Age(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 5;
        default:
            return 0;
        }
    }

// The hit-points-per-die high cells (0 the unreadable or missing ink)
inline int ffnD6Hd1(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 5;
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
            return 5;
        case 10:
            return 6;
        default:
            return 0;
        }
    }

// The hit-points-per-die low cells (0 the unreadable or missing ink)
inline int ffnD6Hd2(int b)
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
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnD7Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 10;
        case 2:
            return 21;
        case 3:
            return 31;
        case 4:
            return 37;
        case 5:
            return 50;
        case 6:
            return 54;
        case 7:
            return 70;
        case 8:
            return 75;
        case 9:
            return 82;
        case 10:
            return 88;
        case 11:
            return 90;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnD7Hi(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 36;
        case 4:
            return 49;
        case 5:
            return 53;
        case 6:
            return 69;
        case 7:
            return 74;
        case 8:
            return 81;
        case 9:
            return 87;
        case 10:
            return 89;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// The type cells (the round-roster ordinal of the dragon type)
inline int ffnD7Type(int b)
    {
        switch (b) {
        case 0:
            return 319;
        case 1:
            return 322;
        case 2:
            return 320;
        case 3:
            return 323;
        case 4:
            return 324;
        case 5:
            return 325;
        case 6:
            return 326;
        case 7:
            return 327;
        case 8:
            return 328;
        case 9:
            return 329;
        case 10:
            return 330;
        case 11:
            return 321;
        default:
            return 0;
        }
    }

// The age cells (-1 the unique court rows, else the first age category: 0
// very young, 1 young, 2 sub-adult, 3 young adult, 4 adult, 5 old, 6 very
// old, 7 ancient)
inline int ffnD7Age(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 5;
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
            return 5;
        case 10:
            return 4;
        case 11:
            return 6;
        default:
            return 0;
        }
    }

// The hit-points-per-die high cells (0 the unreadable or missing ink)
inline int ffnD7Hd1(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 6;
        case 2:
            return 7;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 5;
        case 11:
            return 7;
        default:
            return 0;
        }
    }

// The hit-points-per-die low cells (0 the unreadable or missing ink)
inline int ffnD7Hd2(int b)
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
            return 0;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnD8Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 10;
        case 2:
            return 21;
        case 3:
            return 31;
        case 4:
            return 37;
        case 5:
            return 50;
        case 6:
            return 54;
        case 7:
            return 68;
        case 8:
            return 73;
        case 9:
            return 82;
        case 10:
            return 88;
        case 11:
            return 90;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnD8Hi(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 36;
        case 4:
            return 49;
        case 5:
            return 53;
        case 6:
            return 67;
        case 7:
            return 72;
        case 8:
            return 81;
        case 9:
            return 87;
        case 10:
            return 89;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// The type cells (the round-roster ordinal of the dragon type)
inline int ffnD8Type(int b)
    {
        switch (b) {
        case 0:
            return 319;
        case 1:
            return 322;
        case 2:
            return 320;
        case 3:
            return 323;
        case 4:
            return 324;
        case 5:
            return 325;
        case 6:
            return 326;
        case 7:
            return 327;
        case 8:
            return 328;
        case 9:
            return 329;
        case 10:
            return 330;
        case 11:
            return 321;
        default:
            return 0;
        }
    }

// The age cells (-1 the unique court rows, else the first age category: 0
// very young, 1 young, 2 sub-adult, 3 young adult, 4 adult, 5 old, 6 very
// old, 7 ancient)
inline int ffnD8Age(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 6;
        case 2:
            return 7;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 5;
        case 11:
            return 7;
        default:
            return 0;
        }
    }

// The hit-points-per-die high cells (0 the unreadable or missing ink)
inline int ffnD8Hd1(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 7;
        case 2:
            return 8;
        case 3:
            return 7;
        case 4:
            return 7;
        case 5:
            return 7;
        case 6:
            return 7;
        case 7:
            return 7;
        case 8:
            return 7;
        case 9:
            return 7;
        case 10:
            return 6;
        case 11:
            return 8;
        default:
            return 0;
        }
    }

// The hit-points-per-die low cells (0 the unreadable or missing ink)
inline int ffnD8Hd2(int b)
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
            return 0;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnD9Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 10;
        case 2:
            return 21;
        case 3:
            return 31;
        case 4:
            return 37;
        case 5:
            return 50;
        case 6:
            return 54;
        case 7:
            return 68;
        case 8:
            return 73;
        case 9:
            return 82;
        case 10:
            return 88;
        case 11:
            return 90;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnD9Hi(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return 36;
        case 4:
            return 49;
        case 5:
            return 53;
        case 6:
            return 67;
        case 7:
            return 72;
        case 8:
            return 81;
        case 9:
            return 87;
        case 10:
            return 89;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// The type cells (the round-roster ordinal of the dragon type)
inline int ffnD9Type(int b)
    {
        switch (b) {
        case 0:
            return 319;
        case 1:
            return 322;
        case 2:
            return 320;
        case 3:
            return 323;
        case 4:
            return 324;
        case 5:
            return 325;
        case 6:
            return 326;
        case 7:
            return 327;
        case 8:
            return 328;
        case 9:
            return 329;
        case 10:
            return 330;
        case 11:
            return 321;
        default:
            return 0;
        }
    }

// The age cells (-1 the unique court rows, else the first age category: 0
// very young, 1 young, 2 sub-adult, 3 young adult, 4 adult, 5 old, 6 very
// old, 7 ancient)
inline int ffnD9Age(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 7;
        case 3:
            return 7;
        case 4:
            return 7;
        case 5:
            return 7;
        case 6:
            return 7;
        case 7:
            return 7;
        case 8:
            return 7;
        case 9:
            return 7;
        case 10:
            return 6;
        case 11:
            return 7;
        default:
            return 0;
        }
    }

// The hit-points-per-die high cells (0 the unreadable or missing ink)
inline int ffnD9Hd1(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 8;
        case 2:
            return 8;
        case 3:
            return 8;
        case 4:
            return 8;
        case 5:
            return 8;
        case 6:
            return 8;
        case 7:
            return 8;
        case 8:
            return 8;
        case 9:
            return 8;
        case 10:
            return 7;
        case 11:
            return 8;
        default:
            return 0;
        }
    }

// The hit-points-per-die low cells (0 the unreadable or missing ink)
inline int ffnD9Hd2(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 0;
        case 2:
            return 6;
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
            return 6;
        default:
            return 0;
        }
    }

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnD10Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 20;
        case 2:
            return 26;
        case 3:
            return 33;
        case 4:
            return 34;
        case 5:
            return 39;
        case 6:
            return 56;
        case 7:
            return 63;
        case 8:
            return 64;
        case 9:
            return 93;
        case 10:
            return 95;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnD10Hi(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 25;
        case 2:
            return 32;
        case 3:
            return 33;
        case 4:
            return 38;
        case 5:
            return 55;
        case 6:
            return 62;
        case 7:
            return 63;
        case 8:
            return 92;
        case 9:
            return 94;
        case 10:
            return 100;
        default:
            return 0;
        }
    }

// The type cells (the round-roster ordinal of the dragon type)
inline int ffnD10Type(int b)
    {
        switch (b) {
        case 0:
            return 322;
        case 1:
            return 323;
        case 2:
            return 324;
        case 3:
            return 331;
        case 4:
            return 325;
        case 5:
            return 326;
        case 6:
            return 327;
        case 7:
            return 332;
        case 8:
            return 328;
        case 9:
            return 330;
        case 10:
            return 329;
        default:
            return 0;
        }
    }

// The age cells (-1 the unique court rows, else the first age category: 0
// very young, 1 young, 2 sub-adult, 3 young adult, 4 adult, 5 old, 6 very
// old, 7 ancient)
inline int ffnD10Age(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 7;
        case 3:
            return -1;
        case 4:
            return 7;
        case 5:
            return 7;
        case 6:
            return 7;
        case 7:
            return -1;
        case 8:
            return 7;
        case 9:
            return 4;
        case 10:
            return 7;
        default:
            return 0;
        }
    }

// The hit-points-per-die high cells (0 the unreadable or missing ink)
inline int ffnD10Hd1(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 8;
        case 2:
            return 8;
        case 3:
            return 0;
        case 4:
            return 8;
        case 5:
            return 8;
        case 6:
            return 8;
        case 7:
            return 0;
        case 8:
            return 8;
        case 9:
            return 8;
        case 10:
            return 8;
        default:
            return 0;
        }
    }

// The hit-points-per-die low cells (0 the unreadable or missing ink)
inline int ffnD10Hd2(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 7;
        case 3:
            return 0;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 7;
        case 7:
            return 0;
        case 8:
            return 6;
        case 9:
            return 4;
        case 10:
            return 6;
        default:
            return 0;
        }
    }

// ---- the Sphinx, Human and Character Subtable pins (the R846 walk) ----

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnSpxLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 16;
        case 2:
            return 44;
        case 3:
            return 73;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnSpxHi(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 43;
        case 2:
            return 72;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the sphinx-type ordinals)
inline int ffnSpxOrd(int b)
    {
        switch (b) {
        case 0:
            return 302;
        case 1:
            return 303;
        case 2:
            return 304;
        case 3:
            return 305;
        default:
            return 0;
        }
    }

// The number-encountered low cells
inline int ffnSpxNumMin(int b)
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
        default:
            return 0;
        }
    }

// The number-encountered high cells
inline int ffnSpxNumMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 3;
        default:
            return 0;
        }
    }

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnHumLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 26;
        case 2:
            return 31;
        case 3:
            return 46;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnHumHi(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 30;
        case 2:
            return 45;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// grids)
inline int ffnHumOrd(int b)
    {
        switch (b) {
        case 0:
            return 306;
        case 1:
            return 307;
        case 2:
            return 308;
        case 3:
            return 37;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffnHumSrc(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 4;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the routing rows and the ink-dash rows)
inline int ffnHumNumMin(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The number-encountered high cells
inline int ffnHumNumMax(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 9;
        case 2:
            return 15;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The special cells (0 a creature row, 1 Character, 2 Dragon, 3 Human, 4
// Sphinx, 5 the Elemental group)
inline int ffnHumSp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        default:
            return 0;
        }
    }

// The die-low cells (the percentile bands, 00 read as 100)
inline int ffnChrLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 18;
        case 2:
            return 21;
        case 3:
            return 61;
        case 4:
            return 63;
        case 5:
            return 66;
        case 6:
            return 87;
        case 7:
            return 89;
        case 8:
            return 99;
        case 9:
            return 100;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffnChrHi(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 20;
        case 2:
            return 60;
        case 3:
            return 62;
        case 4:
            return 65;
        case 5:
            return 86;
        case 6:
            return 88;
        case 7:
            return 98;
        case 8:
            return 99;
        case 9:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the character-class ordinals)
inline int ffnChrOrd(int b)
    {
        switch (b) {
        case 0:
            return 309;
        case 1:
            return 310;
        case 2:
            return 311;
        case 3:
            return 312;
        case 4:
            return 313;
        case 5:
            return 314;
        case 6:
            return 315;
        case 7:
            return 316;
        case 8:
            return 317;
        case 9:
            return 318;
        default:
            return 0;
        }
    }

// The number-in-party low cells
inline int ffnChrNumMin(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 5;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 4;
        case 8:
            return 2;
        case 9:
            return 1;
        default:
            return 0;
        }
    }

// The number-in-party high cells
inline int ffnChrNumMax(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 5;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 4;
        case 8:
            return 2;
        case 9:
            return 1;
        default:
            return 0;
        }
    }

}   // namespace rules
