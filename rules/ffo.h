// =========================================================================================
// Adnd1 - rules/ffo.h
// THE FF ENCOUNTER LISTINGS - THE SIX TERRAIN TABLES, THE TWELVE SUBTABLES
// AND THE TWO PLANE TABLES (the print pp. 111-119: the Arctic, Sub-Arctic,
// temperate uninhabited, temperate inhabited and patrolled, Faerie and
// tropical tables, the Demi-Human through Undead subtables, the Astral and
// Ethereal listings and the class level table), the second of the three FF
// table-group rounds (the Magic Item Tables follow)
// census 769 -> 770.
//
// The FF arc table-group continuation (Curtiss Go call on the landed R846 FF
// monster level tables; the three-round queue rides the R846 record). The
// pin-time walk found 21 printed tables and 489 rows - the R846 level-grid
// round the mechanics precedent - adjudicated from the three-voice scan
// collation (the djvu text, the word-geometry xml, the abbyy char xml, the
// pdf hidden Capture layer the fourth voice on the void pages) with the
// landed registry defs advisory and the DMG Appendix C parity (the 1eonline
// transcription) the tie-breaker. No defs promoted: the registry floor holds
// at 995.
//
// The spliced rounds never edit the landed audits: the battery reads every
// table cell live, the census walks the arithmetic, and the double engine run
// lands GREEN before the commit.
//
namespace rules {

// ---- the R847 census ----

// the FF encounter listings round: the outdoor terrain tables, their
// subtables and the Astral and Ethereal plane tables, the second table-group
// round of the FF arc (Curtiss Go call on the landed R846)
inline int ffoRound()
    { return 847; }

// the 21 tables: the six terrain tables (Arctic, Sub-Arctic, temperate
// uninhabited, temperate inhabited and patrolled, Faerie, tropical), the
// twelve subtables (Demi-Human through Undead and the tropical Sphinx
// Subtable), the Astral and Ethereal tables, the class level table
inline int ffoTableCount()
    { return 21; }

// the rows pinned across the six terrain tables
inline int ffoOutdoorRows()
    { return 341; }

// the rows pinned across the twelve subtables
inline int ffoSubtableRows()
    { return 86; }

// the rows pinned across the Astral and Ethereal tables
inline int ffoPlaneRows()
    { return 51; }

// the total rows pinned across the 21 tables
inline int ffoTotalRows()
    { return 489; }

// the round roster: every creature label, routing label, subtable type, plane
// row and character class the 21 tables walk, first-appearance order
inline int ffoRosterCount()
    { return 356; }

// the registry floor: no defs promoted this round, the 995 landed defs the
// advisory voice
inline int ffoRegistryFloor()
    { return 995; }

// the forced repairs (the R703 pattern: 49 digit repairs, 16 ink
// star-for-hyphen repairs, 14 dash recoveries; every repair forced by the
// 01-00 column contiguity or corroborated by a second voice or the DMG
// parity)
inline int ffoRepairs()
    { return 79; }

// the four pinned print defects: the Dragon Subtable Forest hole 23, the
// patrolled Mountains gap 42-49 and the two patrolled Marsh gaps 38 and 85
inline int ffoDefectPins()
    { return 4; }

// the Dragon Subtable print defect: the Forest column prints no band 23 (the
// Bronze row ends 22, the Chimera row starts 24-29); the DMG carries the same
// hole - pinned as ink, the column does NOT assert its full tiling
inline int ffoDrgForHole()
    { return 23; }

// the patrolled-table print defect: the Mountains column prints the Men,
// merchant band 50-51 (the DMG reads 42-51) leaving the gap 42-49 unassigned,
// with the Men, nomad Mountains cell a dash - pinned as ink
inline int ffoPatMtnHoleLo()
    { return 42; }

// the patrolled-table Mountains gap ceiling (the Men, merchant band 50-51)
inline int ffoPatMtnHoleHi()
    { return 49; }

// the patrolled-table print defect: the Marsh column prints the Men, pilgrim
// band 35-37 then the Ogre band 39-46 leaving the single gap 38 unassigned -
// pinned as ink
inline int ffoPatMshHole1()
    { return 38; }

// the patrolled-table print defect: the Marsh column prints the Vampire band
// 80-84 then the Will-o-wisp band 86-00 leaving the single gap 85 unassigned
// - pinned as ink
inline int ffoPatMshHole2()
    { return 85; }

// the source census: the MM1 rows
inline int ffoMm1SourceRows()
    { return 327; }

// the source census: the MM2 rows - ZERO (the print lists MM1 and FF
// creatures only; a census pin)
inline int ffoMm2SourceRows()
    { return 0; }

// the source census: the FF rows
inline int ffoFfSourceRows()
    { return 113; }

// the source census: the unkeyed rows (the demon and devil type rows, the
// titan rows, the slash pairs and the rest - no single standing def keys the
// row)
inline int ffoUnkeyedRows()
    { return 23; }

// the source census: the routing rows (the dagger rows, the Men Character
// row, the Human traveller rows and the eleven class rows)
inline int ffoRoutingRows()
    { return 26; }

// the rows pinned across the the Arctic encounter table
inline int ffoArcRows()
    { return 16; }

// the rows pinned across the the Sub-Arctic encounter table
inline int ffoSubRows()
    { return 31; }

// the rows pinned across the the temperate uninhabited encounter table
inline int ffoTemRows()
    { return 98; }

// the rows pinned across the the Demi-Human Subtable
inline int ffoDmiRows()
    { return 4; }

// the rows pinned across the the Dragon Subtable
inline int ffoDrgRows()
    { return 15; }

// the rows pinned across the the Frog Subtable
inline int ffoFrgRows()
    { return 3; }

// the rows pinned across the the Giant Subtable
inline int ffoGntRows()
    { return 12; }

// the rows pinned across the the Humanoid Subtable
inline int ffoHumRows()
    { return 7; }

// the rows pinned across the the Lycanthrope Subtable
inline int ffoLycRows()
    { return 5; }

// the rows pinned across the the Men Subtable
inline int ffoMenRows()
    { return 9; }

// the rows pinned across the the Snake Subtable
inline int ffoSnkRows()
    { return 4; }

// the rows pinned across the the Sphinx Subtable
inline int ffoSpxRows()
    { return 4; }

// the rows pinned across the the Spider Subtable
inline int ffoSpiRows()
    { return 4; }

// the rows pinned across the the Undead Subtable
inline int ffoUndRows()
    { return 15; }

// the rows pinned across the the temperate inhabited and patrolled encounter
// table
inline int ffoPatRows()
    { return 60; }

// the rows pinned across the the Faerie and sylvan encounter table
inline int ffoFaeRows()
    { return 47; }

// the rows pinned across the the tropical encounter table
inline int ffoTroRows()
    { return 89; }

// the rows pinned across the the tropical Sphinx Subtable
inline int ffoTrxRows()
    { return 4; }

// the rows pinned across the the Astral encounter table
inline int ffoAstRows()
    { return 24; }

// the rows pinned across the the Ethereal encounter table
inline int ffoEthRows()
    { return 27; }

// the rows pinned across the the Human Subtable character level ranges
inline int ffoClsRows()
    { return 11; }

// ---- the R847 doctrine ----

// every terrain column scores on percentile dice (the 00 cell read as 100),
// one contiguous 01-00 band walk per column modulo the pinned print defects
inline bool ffoDiceScoreD100()
    { return true; }

// the dagger rows route to their subtables (the Demi-Human, Dragon, Frog,
// Giant, Humanoid, Lycanthrope, Men, Snake, Sphinx, Spider and Undead bands
// walk their subtable cells; the tropical Sphinx band walks the tropical
// Sphinx Subtable)
inline bool ffoDaggerRouting()
    { return true; }

// the tropical Shore/Sm.Isle column rides the FF print only - the DMG
// Appendix C tropical table carries no shore column (an FF invention)
inline bool ffoShoreColumnFfInvention()
    { return true; }

// the Men Subtable Character row prints 10% in all cases with no bands - the
// per-column bands are tiling-recovered, the print note rides the row
inline bool ffoMenCharacter10Pct()
    { return true; }

// the Men Subtable special note: men encountered in the wilderness are 90%
// likely to be mounted (the ink reads 00% in one voice; the DMG parity reads
// 90%)
inline bool ffoMenMounted90Pct()
    { return true; }

// the arctic page note: monsters in italic type are 75% likely to be
// encountered while they are airborne
inline bool ffoArcticAirborne75Pct()
    { return true; }

// the ruins footnotes: the arctic, sub-arctic and patrolled column heads
// carry the includes-ruins note (the cities, temples and fortresses within up
// to five miles of the party)
inline bool ffoRuinsFootnotes()
    { return true; }

// the gnoll footnotes: 10% (20% sub-arctic) of the gnoll encounters include
// flinds
inline bool ffoGnollFlindsFootnote()
    { return true; }

// the lizard man footnote: 10% of the temperate encounters include babblers
// and 5% include a lizard king among the lizard men (the tropical print
// carries the 5% lizard king note)
inline bool ffoLizardKingFootnote()
    { return true; }

// the orc footnote: 5% of the orc encounters include ogrillons
inline bool ffoOrcOgrillonsFootnote()
    { return true; }

// the plane-table slash rows read 50% each (the printed pair splits the band
// - the first-listed creature walks the roster cell)
inline bool ffoAstralSlashPairs()
    { return true; }

// the plane-table asterisk rows carry the perception note (the djinni,
// ki-rin, githyanki and the rest read the special perception doctrine)
inline bool ffoPlanePerceptionNote()
    { return true; }

// the class level table pairs the Human Subtable character levels (the DMG
// parity): the traveller parties always carry a cleric, a second character
// adds a magic-user, the party size reads 1-6
inline bool ffoClassLevelTable()
    { return true; }

// the Astral table squares note: the plane tables walk the Astral and
// Ethereal encounter listings of the print pp. 118-119 (print pp. 111-119 the
// whole outdoor walk)
inline bool ffoAstralSquaresToAstral()
    { return true; }

// ---- the terrain tables ----

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoArcOrd(int b)
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
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoArcSrc(int b)
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
            return 1;
        case 6:
            return 3;
        case 7:
            return 3;
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
        default:
            return 0;
        }
    }

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoArcPlnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 10;
        case 4:
            return 11;
        case 5:
            return 14;
        case 6:
            return 54;
        case 7:
            return 57;
        case 8:
            return 58;
        case 9:
            return 68;
        case 10:
            return 73;
        case 11:
            return 75;
        case 12:
            return 81;
        case 13:
            return 84;
        case 14:
            return 93;
        case 15:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Plain; 0 the dash)
inline int ffoArcPlnHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 7;
        case 2:
            return 9;
        case 3:
            return 10;
        case 4:
            return 13;
        case 5:
            return 53;
        case 6:
            return 56;
        case 7:
            return 57;
        case 8:
            return 67;
        case 9:
            return 72;
        case 10:
            return 74;
        case 11:
            return 80;
        case 12:
            return 83;
        case 13:
            return 92;
        case 14:
            return 95;
        case 15:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoArcRghLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 7;
        case 2:
            return 9;
        case 3:
            return 11;
        case 4:
            return 12;
        case 5:
            return 15;
        case 6:
            return 55;
        case 7:
            return 58;
        case 8:
            return 59;
        case 9:
            return 68;
        case 10:
            return 76;
        case 11:
            return 78;
        case 12:
            return 83;
        case 13:
            return 85;
        case 14:
            return 94;
        case 15:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoArcRghHi(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 8;
        case 2:
            return 10;
        case 3:
            return 11;
        case 4:
            return 14;
        case 5:
            return 54;
        case 6:
            return 57;
        case 7:
            return 58;
        case 8:
            return 67;
        case 9:
            return 75;
        case 10:
            return 77;
        case 11:
            return 82;
        case 12:
            return 84;
        case 13:
            return 93;
        case 14:
            return 95;
        case 15:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountain; 0 the dash, the 00 cell reads 100)
inline int ffoArcMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 10;
        case 3:
            return 16;
        case 4:
            return 19;
        case 5:
            return 24;
        case 6:
            return 56;
        case 7:
            return 59;
        case 8:
            return 61;
        case 9:
            return 67;
        case 10:
            return 76;
        case 11:
            return 78;
        case 12:
            return 82;
        case 13:
            return 84;
        case 14:
            return 89;
        case 15:
            return 91;
        default:
            return 0;
        }
    }

// The die-high cells (Mountain; 0 the dash)
inline int ffoArcMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 9;
        case 2:
            return 15;
        case 3:
            return 18;
        case 4:
            return 23;
        case 5:
            return 55;
        case 6:
            return 58;
        case 7:
            return 60;
        case 8:
            return 66;
        case 9:
            return 75;
        case 10:
            return 77;
        case 11:
            return 81;
        case 12:
            return 83;
        case 13:
            return 88;
        case 14:
            return 90;
        case 15:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoSubOrd(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 17;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 18;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 19;
        case 8:
            return 20;
        case 9:
            return 6;
        case 10:
            return 7;
        case 11:
            return 8;
        case 12:
            return 21;
        case 13:
            return 22;
        case 14:
            return 23;
        case 15:
            return 9;
        case 16:
            return 10;
        case 17:
            return 24;
        case 18:
            return 25;
        case 19:
            return 26;
        case 20:
            return 11;
        case 21:
            return 27;
        case 22:
            return 28;
        case 23:
            return 13;
        case 24:
            return 29;
        case 25:
            return 30;
        case 26:
            return 14;
        case 27:
            return 15;
        case 28:
            return 31;
        case 29:
            return 32;
        case 30:
            return 16;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoSubSrc(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 3;
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
            return 3;
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
            return 3;
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

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoSubPlnLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 7;
        case 7:
            return 11;
        case 8:
            return 0;
        case 9:
            return 16;
        case 10:
            return 41;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 45;
        case 14:
            return 50;
        case 15:
            return 59;
        case 16:
            return 68;
        case 17:
            return 73;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 75;
        case 22:
            return 83;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 91;
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

// The die-high cells (Plain; 0 the dash)
inline int ffoSubPlnHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 6;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 10;
        case 7:
            return 15;
        case 8:
            return 0;
        case 9:
            return 40;
        case 10:
            return 44;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 49;
        case 14:
            return 58;
        case 15:
            return 67;
        case 16:
            return 72;
        case 17:
            return 74;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 82;
        case 22:
            return 90;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 100;
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

// The die-low cells (Scrub; 0 the dash, the 00 cell reads 100)
inline int ffoSubScrLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 5;
        case 3:
            return 7;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 11;
        case 7:
            return 15;
        case 8:
            return 0;
        case 9:
            return 20;
        case 10:
            return 37;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 41;
        case 14:
            return 50;
        case 15:
            return 55;
        case 16:
            return 65;
        case 17:
            return 70;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 74;
        case 22:
            return 82;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 90;
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

// The die-high cells (Scrub; 0 the dash)
inline int ffoSubScrHi(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 0;
        case 2:
            return 6;
        case 3:
            return 10;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 14;
        case 7:
            return 19;
        case 8:
            return 0;
        case 9:
            return 36;
        case 10:
            return 40;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 49;
        case 14:
            return 54;
        case 15:
            return 64;
        case 16:
            return 69;
        case 17:
            return 73;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 81;
        case 22:
            return 89;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 100;
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

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoSubForLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 9;
        case 2:
            return 13;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 15;
        case 7:
            return 19;
        case 8:
            return 23;
        case 9:
            return 25;
        case 10:
            return 35;
        case 11:
            return 0;
        case 12:
            return 37;
        case 13:
            return 42;
        case 14:
            return 51;
        case 15:
            return 56;
        case 16:
            return 65;
        case 17:
            return 70;
        case 18:
            return 0;
        case 19:
            return 74;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 78;
        case 23:
            return 0;
        case 24:
            return 82;
        case 25:
            return 0;
        case 26:
            return 87;
        case 27:
            return 0;
        case 28:
            return 97;
        case 29:
            return 99;
        case 30:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoSubForHi(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 12;
        case 2:
            return 14;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 18;
        case 7:
            return 22;
        case 8:
            return 24;
        case 9:
            return 34;
        case 10:
            return 36;
        case 11:
            return 0;
        case 12:
            return 41;
        case 13:
            return 50;
        case 14:
            return 55;
        case 15:
            return 64;
        case 16:
            return 69;
        case 17:
            return 73;
        case 18:
            return 0;
        case 19:
            return 77;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 81;
        case 23:
            return 0;
        case 24:
            return 86;
        case 25:
            return 0;
        case 26:
            return 96;
        case 27:
            return 0;
        case 28:
            return 98;
        case 29:
            return 100;
        case 30:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoSubRghLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 13;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 17;
        case 7:
            return 21;
        case 8:
            return 26;
        case 9:
            return 28;
        case 10:
            return 40;
        case 11:
            return 43;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 44;
        case 16:
            return 54;
        case 17:
            return 59;
        case 18:
            return 63;
        case 19:
            return 68;
        case 20:
            return 73;
        case 21:
            return 0;
        case 22:
            return 75;
        case 23:
            return 0;
        case 24:
            return 79;
        case 25:
            return 83;
        case 26:
            return 85;
        case 27:
            return 0;
        case 28:
            return 93;
        case 29:
            return 97;
        case 30:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoSubRghHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 12;
        case 3:
            return 16;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 20;
        case 7:
            return 25;
        case 8:
            return 27;
        case 9:
            return 39;
        case 10:
            return 42;
        case 11:
            return 43;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 53;
        case 16:
            return 58;
        case 17:
            return 62;
        case 18:
            return 67;
        case 19:
            return 72;
        case 20:
            return 74;
        case 21:
            return 0;
        case 22:
            return 78;
        case 23:
            return 0;
        case 24:
            return 82;
        case 25:
            return 84;
        case 26:
            return 92;
        case 27:
            return 0;
        case 28:
            return 96;
        case 29:
            return 98;
        case 30:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoSubHilLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 9;
        case 3:
            return 11;
        case 4:
            return 0;
        case 5:
            return 15;
        case 6:
            return 16;
        case 7:
            return 20;
        case 8:
            return 24;
        case 9:
            return 26;
        case 10:
            return 42;
        case 11:
            return 44;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 45;
        case 16:
            return 63;
        case 17:
            return 67;
        case 18:
            return 71;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 75;
        case 22:
            return 79;
        case 23:
            return 0;
        case 24:
            return 83;
        case 25:
            return 87;
        case 26:
            return 89;
        case 27:
            return 93;
        case 28:
            return 95;
        case 29:
            return 97;
        case 30:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoSubHilHi(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 8;
        case 2:
            return 10;
        case 3:
            return 14;
        case 4:
            return 0;
        case 5:
            return 15;
        case 6:
            return 19;
        case 7:
            return 23;
        case 8:
            return 25;
        case 9:
            return 41;
        case 10:
            return 43;
        case 11:
            return 44;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 62;
        case 16:
            return 66;
        case 17:
            return 70;
        case 18:
            return 74;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 78;
        case 22:
            return 82;
        case 23:
            return 0;
        case 24:
            return 86;
        case 25:
            return 88;
        case 26:
            return 92;
        case 27:
            return 94;
        case 28:
            return 96;
        case 29:
            return 98;
        case 30:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountains; 0 the dash, the 00 cell reads 100)
inline int ffoSubMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 11;
        case 4:
            return 17;
        case 5:
            return 19;
        case 6:
            return 21;
        case 7:
            return 25;
        case 8:
            return 29;
        case 9:
            return 33;
        case 10:
            return 53;
        case 11:
            return 55;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 57;
        case 16:
            return 62;
        case 17:
            return 66;
        case 18:
            return 70;
        case 19:
            return 0;
        case 20:
            return 75;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 79;
        case 25:
            return 87;
        case 26:
            return 89;
        case 27:
            return 94;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Mountains; 0 the dash)
inline int ffoSubMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 16;
        case 4:
            return 18;
        case 5:
            return 20;
        case 6:
            return 24;
        case 7:
            return 28;
        case 8:
            return 32;
        case 9:
            return 52;
        case 10:
            return 54;
        case 11:
            return 56;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 61;
        case 16:
            return 65;
        case 17:
            return 69;
        case 18:
            return 74;
        case 19:
            return 0;
        case 20:
            return 78;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 86;
        case 25:
            return 88;
        case 26:
            return 93;
        case 27:
            return 95;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Marsh; 0 the dash, the 00 cell reads 100)
inline int ffoSubMshLo(int b)
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
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 5;
        case 8:
            return 0;
        case 9:
            return 20;
        case 10:
            return 50;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 52;
        case 15:
            return 56;
        case 16:
            return 65;
        case 17:
            return 73;
        case 18:
            return 0;
        case 19:
            return 75;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 83;
        case 24:
            return 87;
        case 25:
            return 97;
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

// The die-high cells (Marsh; 0 the dash)
inline int ffoSubMshHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 4;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 19;
        case 8:
            return 0;
        case 9:
            return 49;
        case 10:
            return 51;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 55;
        case 15:
            return 64;
        case 16:
            return 72;
        case 17:
            return 74;
        case 18:
            return 0;
        case 19:
            return 82;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 86;
        case 24:
            return 96;
        case 25:
            return 100;
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

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoTemOrd(int b)
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
            return 1;
        case 10:
            return 42;
        case 11:
            return 43;
        case 12:
            return 44;
        case 13:
            return 45;
        case 14:
            return 46;
        case 15:
            return 47;
        case 16:
            return 48;
        case 17:
            return 49;
        case 18:
            return 50;
        case 19:
            return 51;
        case 20:
            return 52;
        case 21:
            return 53;
        case 22:
            return 54;
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
        case 30:
            return 62;
        case 31:
            return 63;
        case 32:
            return 64;
        case 33:
            return 65;
        case 34:
            return 66;
        case 35:
            return 67;
        case 36:
            return 68;
        case 37:
            return 69;
        case 38:
            return 70;
        case 39:
            return 71;
        case 40:
            return 72;
        case 41:
            return 73;
        case 42:
            return 74;
        case 43:
            return 75;
        case 44:
            return 76;
        case 45:
            return 77;
        case 46:
            return 78;
        case 47:
            return 79;
        case 48:
            return 80;
        case 49:
            return 81;
        case 50:
            return 6;
        case 51:
            return 82;
        case 52:
            return 83;
        case 53:
            return 84;
        case 54:
            return 85;
        case 55:
            return 86;
        case 56:
            return 87;
        case 57:
            return 88;
        case 58:
            return 89;
        case 59:
            return 90;
        case 60:
            return 91;
        case 61:
            return 92;
        case 62:
            return 93;
        case 63:
            return 94;
        case 64:
            return 21;
        case 65:
            return 95;
        case 66:
            return 96;
        case 67:
            return 97;
        case 68:
            return 98;
        case 69:
            return 10;
        case 70:
            return 99;
        case 71:
            return 100;
        case 72:
            return 101;
        case 73:
            return 102;
        case 74:
            return 103;
        case 75:
            return 104;
        case 76:
            return 105;
        case 77:
            return 106;
        case 78:
            return 107;
        case 79:
            return 108;
        case 80:
            return 109;
        case 81:
            return 110;
        case 82:
            return 111;
        case 83:
            return 112;
        case 84:
            return 113;
        case 85:
            return 114;
        case 86:
            return 29;
        case 87:
            return 115;
        case 88:
            return 116;
        case 89:
            return 117;
        case 90:
            return 118;
        case 91:
            return 119;
        case 92:
            return 120;
        case 93:
            return 121;
        case 94:
            return 122;
        case 95:
            return 123;
        case 96:
            return 14;
        case 97:
            return 124;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoTemSrc(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 3;
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
            return 3;
        case 22:
            return 3;
        case 23:
            return 1;
        case 24:
            return 3;
        case 25:
            return 1;
        case 26:
            return 3;
        case 27:
            return 3;
        case 28:
            return 0;
        case 29:
            return 3;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 0;
        case 33:
            return 1;
        case 34:
            return 3;
        case 35:
            return 1;
        case 36:
            return 4;
        case 37:
            return 3;
        case 38:
            return 3;
        case 39:
            return 3;
        case 40:
            return 3;
        case 41:
            return 0;
        case 42:
            return 3;
        case 43:
            return 3;
        case 44:
            return 3;
        case 45:
            return 1;
        case 46:
            return 0;
        case 47:
            return 3;
        case 48:
            return 1;
        case 49:
            return 1;
        case 50:
            return 1;
        case 51:
            return 1;
        case 52:
            return 3;
        case 53:
            return 1;
        case 54:
            return 0;
        case 55:
            return 1;
        case 56:
            return 3;
        case 57:
            return 4;
        case 58:
            return 4;
        case 59:
            return 1;
        case 60:
            return 1;
        case 61:
            return 1;
        case 62:
            return 1;
        case 63:
            return 0;
        case 64:
            return 1;
        case 65:
            return 3;
        case 66:
            return 1;
        case 67:
            return 0;
        case 68:
            return 1;
        case 69:
            return 1;
        case 70:
            return 1;
        case 71:
            return 1;
        case 72:
            return 3;
        case 73:
            return 4;
        case 74:
            return 1;
        case 75:
            return 1;
        case 76:
            return 0;
        case 77:
            return 0;
        case 78:
            return 0;
        case 79:
            return 1;
        case 80:
            return 3;
        case 81:
            return 3;
        case 82:
            return 1;
        case 83:
            return 3;
        case 84:
            return 1;
        case 85:
            return 4;
        case 86:
            return 1;
        case 87:
            return 3;
        case 88:
            return 0;
        case 89:
            return 3;
        case 90:
            return 3;
        case 91:
            return 1;
        case 92:
            return 1;
        case 93:
            return 3;
        case 94:
            return 1;
        case 95:
            return 1;
        case 96:
            return 1;
        case 97:
            return 1;
        default:
            return 0;
        }
    }

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoTemPlnLo(int b)
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
            return 2;
        case 6:
            return 3;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 4;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 5;
        case 15:
            return 6;
        case 16:
            return 7;
        case 17:
            return 9;
        case 18:
            return 10;
        case 19:
            return 11;
        case 20:
            return 12;
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
            return 14;
        case 29:
            return 15;
        case 30:
            return 0;
        case 31:
            return 16;
        case 32:
            return 18;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 20;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 21;
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
            return 22;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 24;
        case 50:
            return 25;
        case 51:
            return 31;
        case 52:
            return 0;
        case 53:
            return 33;
        case 54:
            return 36;
        case 55:
            return 39;
        case 56:
            return 43;
        case 57:
            return 45;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 46;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 55;
        case 64:
            return 0;
        case 65:
            return 56;
        case 66:
            return 0;
        case 67:
            return 57;
        case 68:
            return 74;
        case 69:
            return 78;
        case 70:
            return 0;
        case 71:
            return 79;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 0;
        case 76:
            return 81;
        case 77:
            return 0;
        case 78:
            return 82;
        case 79:
            return 84;
        case 80:
            return 85;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 86;
        case 85:
            return 0;
        case 86:
            return 87;
        case 87:
            return 0;
        case 88:
            return 0;
        case 89:
            return 89;
        case 90:
            return 90;
        case 91:
            return 0;
        case 92:
            return 91;
        case 93:
            return 0;
        case 94:
            return 0;
        case 95:
            return 0;
        case 96:
            return 92;
        case 97:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells (Plain; 0 the dash)
inline int ffoTemPlnHi(int b)
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
            return 2;
        case 6:
            return 3;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 4;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 5;
        case 15:
            return 6;
        case 16:
            return 8;
        case 17:
            return 9;
        case 18:
            return 10;
        case 19:
            return 11;
        case 20:
            return 13;
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
            return 14;
        case 29:
            return 15;
        case 30:
            return 0;
        case 31:
            return 17;
        case 32:
            return 19;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 20;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 21;
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
            return 23;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 24;
        case 50:
            return 30;
        case 51:
            return 32;
        case 52:
            return 0;
        case 53:
            return 35;
        case 54:
            return 38;
        case 55:
            return 42;
        case 56:
            return 44;
        case 57:
            return 45;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 54;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 55;
        case 64:
            return 0;
        case 65:
            return 56;
        case 66:
            return 0;
        case 67:
            return 73;
        case 68:
            return 77;
        case 69:
            return 78;
        case 70:
            return 0;
        case 71:
            return 80;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 0;
        case 76:
            return 81;
        case 77:
            return 0;
        case 78:
            return 83;
        case 79:
            return 84;
        case 80:
            return 85;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 86;
        case 85:
            return 0;
        case 86:
            return 88;
        case 87:
            return 0;
        case 88:
            return 0;
        case 89:
            return 89;
        case 90:
            return 90;
        case 91:
            return 0;
        case 92:
            return 91;
        case 93:
            return 0;
        case 94:
            return 0;
        case 95:
            return 0;
        case 96:
            return 98;
        case 97:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Scrub; 0 the dash, the 00 cell reads 100)
inline int ffoTemScrLo(int b)
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
            return 3;
        case 6:
            return 4;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 6;
        case 15:
            return 7;
        case 16:
            return 8;
        case 17:
            return 9;
        case 18:
            return 11;
        case 19:
            return 12;
        case 20:
            return 13;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 16;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 17;
        case 29:
            return 18;
        case 30:
            return 0;
        case 31:
            return 19;
        case 32:
            return 20;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 21;
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
            return 22;
        case 43:
            return 23;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 24;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 26;
        case 50:
            return 27;
        case 51:
            return 33;
        case 52:
            return 35;
        case 53:
            return 37;
        case 54:
            return 39;
        case 55:
            return 43;
        case 56:
            return 44;
        case 57:
            return 45;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 46;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 49;
        case 68:
            return 67;
        case 69:
            return 72;
        case 70:
            return 0;
        case 71:
            return 73;
        case 72:
            return 0;
        case 73:
            return 74;
        case 74:
            return 76;
        case 75:
            return 0;
        case 76:
            return 77;
        case 77:
            return 0;
        case 78:
            return 78;
        case 79:
            return 84;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 87;
        case 83:
            return 88;
        case 84:
            return 89;
        case 85:
            return 0;
        case 86:
            return 90;
        case 87:
            return 91;
        case 88:
            return 0;
        case 89:
            return 92;
        case 90:
            return 0;
        case 91:
            return 0;
        case 92:
            return 93;
        case 93:
            return 0;
        case 94:
            return 0;
        case 95:
            return 0;
        case 96:
            return 94;
        case 97:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells (Scrub; 0 the dash)
inline int ffoTemScrHi(int b)
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
            return 3;
        case 6:
            return 4;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 6;
        case 15:
            return 7;
        case 16:
            return 8;
        case 17:
            return 10;
        case 18:
            return 11;
        case 19:
            return 12;
        case 20:
            return 15;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 16;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 17;
        case 29:
            return 18;
        case 30:
            return 0;
        case 31:
            return 19;
        case 32:
            return 20;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 21;
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
            return 22;
        case 43:
            return 23;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 25;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 26;
        case 50:
            return 32;
        case 51:
            return 34;
        case 52:
            return 36;
        case 53:
            return 38;
        case 54:
            return 42;
        case 55:
            return 43;
        case 56:
            return 44;
        case 57:
            return 45;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 48;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 66;
        case 68:
            return 71;
        case 69:
            return 72;
        case 70:
            return 0;
        case 71:
            return 73;
        case 72:
            return 0;
        case 73:
            return 75;
        case 74:
            return 76;
        case 75:
            return 0;
        case 76:
            return 77;
        case 77:
            return 0;
        case 78:
            return 83;
        case 79:
            return 86;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 87;
        case 83:
            return 88;
        case 84:
            return 89;
        case 85:
            return 0;
        case 86:
            return 90;
        case 87:
            return 91;
        case 88:
            return 0;
        case 89:
            return 92;
        case 90:
            return 0;
        case 91:
            return 0;
        case 92:
            return 93;
        case 93:
            return 0;
        case 94:
            return 0;
        case 95:
            return 0;
        case 96:
            return 98;
        case 97:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoTemForLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 0;
        case 9:
            return 7;
        case 10:
            return 0;
        case 11:
            return 9;
        case 12:
            return 10;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 11;
        case 16:
            return 12;
        case 17:
            return 13;
        case 18:
            return 14;
        case 19:
            return 0;
        case 20:
            return 15;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 16;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 17;
        case 29:
            return 0;
        case 30:
            return 19;
        case 31:
            return 20;
        case 32:
            return 21;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 22;
        case 36:
            return 23;
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
            return 24;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 25;
        case 47:
            return 26;
        case 48:
            return 0;
        case 49:
            return 28;
        case 50:
            return 29;
        case 51:
            return 31;
        case 52:
            return 32;
        case 53:
            return 34;
        case 54:
            return 36;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 40;
        case 58:
            return 41;
        case 59:
            return 0;
        case 60:
            return 42;
        case 61:
            return 44;
        case 62:
            return 0;
        case 63:
            return 45;
        case 64:
            return 47;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 49;
        case 68:
            return 57;
        case 69:
            return 61;
        case 70:
            return 63;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 65;
        case 74:
            return 67;
        case 75:
            return 68;
        case 76:
            return 69;
        case 77:
            return 71;
        case 78:
            return 73;
        case 79:
            return 76;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 78;
        case 83:
            return 0;
        case 84:
            return 80;
        case 85:
            return 81;
        case 86:
            return 83;
        case 87:
            return 84;
        case 88:
            return 85;
        case 89:
            return 0;
        case 90:
            return 0;
        case 91:
            return 87;
        case 92:
            return 88;
        case 93:
            return 89;
        case 94:
            return 91;
        case 95:
            return 0;
        case 96:
            return 92;
        case 97:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoTemForHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 0;
        case 9:
            return 8;
        case 10:
            return 0;
        case 11:
            return 9;
        case 12:
            return 10;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 11;
        case 16:
            return 12;
        case 17:
            return 13;
        case 18:
            return 14;
        case 19:
            return 0;
        case 20:
            return 15;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 16;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 18;
        case 29:
            return 0;
        case 30:
            return 19;
        case 31:
            return 20;
        case 32:
            return 21;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 22;
        case 36:
            return 23;
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
            return 24;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 25;
        case 47:
            return 27;
        case 48:
            return 0;
        case 49:
            return 28;
        case 50:
            return 30;
        case 51:
            return 31;
        case 52:
            return 33;
        case 53:
            return 35;
        case 54:
            return 39;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 40;
        case 58:
            return 41;
        case 59:
            return 0;
        case 60:
            return 43;
        case 61:
            return 44;
        case 62:
            return 0;
        case 63:
            return 46;
        case 64:
            return 48;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 56;
        case 68:
            return 60;
        case 69:
            return 62;
        case 70:
            return 64;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 66;
        case 74:
            return 67;
        case 75:
            return 68;
        case 76:
            return 70;
        case 77:
            return 72;
        case 78:
            return 75;
        case 79:
            return 77;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 79;
        case 83:
            return 0;
        case 84:
            return 80;
        case 85:
            return 82;
        case 86:
            return 83;
        case 87:
            return 84;
        case 88:
            return 86;
        case 89:
            return 0;
        case 90:
            return 0;
        case 91:
            return 87;
        case 92:
            return 88;
        case 93:
            return 90;
        case 94:
            return 91;
        case 95:
            return 0;
        case 96:
            return 98;
        case 97:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoTemRghLo(int b)
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
            return 2;
        case 7:
            return 3;
        case 8:
            return 5;
        case 9:
            return 6;
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
            return 7;
        case 16:
            return 8;
        case 17:
            return 10;
        case 18:
            return 11;
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
            return 12;
        case 29:
            return 0;
        case 30:
            return 13;
        case 31:
            return 14;
        case 32:
            return 15;
        case 33:
            return 16;
        case 34:
            return 0;
        case 35:
            return 17;
        case 36:
            return 18;
        case 37:
            return 19;
        case 38:
            return 20;
        case 39:
            return 0;
        case 40:
            return 21;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 22;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 23;
        case 47:
            return 0;
        case 48:
            return 25;
        case 49:
            return 26;
        case 50:
            return 27;
        case 51:
            return 29;
        case 52:
            return 0;
        case 53:
            return 31;
        case 54:
            return 33;
        case 55:
            return 0;
        case 56:
            return 38;
        case 57:
            return 39;
        case 58:
            return 0;
        case 59:
            return 40;
        case 60:
            return 42;
        case 61:
            return 44;
        case 62:
            return 0;
        case 63:
            return 46;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 48;
        case 68:
            return 57;
        case 69:
            return 61;
        case 70:
            return 0;
        case 71:
            return 62;
        case 72:
            return 0;
        case 73:
            return 63;
        case 74:
            return 0;
        case 75:
            return 0;
        case 76:
            return 64;
        case 77:
            return 66;
        case 78:
            return 68;
        case 79:
            return 70;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 71;
        case 84:
            return 72;
        case 85:
            return 0;
        case 86:
            return 73;
        case 87:
            return 0;
        case 88:
            return 79;
        case 89:
            return 83;
        case 90:
            return 0;
        case 91:
            return 84;
        case 92:
            return 87;
        case 93:
            return 0;
        case 94:
            return 89;
        case 95:
            return 0;
        case 96:
            return 91;
        case 97:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoTemRghHi(int b)
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
            return 2;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 6;
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
            return 7;
        case 16:
            return 9;
        case 17:
            return 10;
        case 18:
            return 11;
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
            return 12;
        case 29:
            return 0;
        case 30:
            return 13;
        case 31:
            return 14;
        case 32:
            return 15;
        case 33:
            return 16;
        case 34:
            return 0;
        case 35:
            return 17;
        case 36:
            return 18;
        case 37:
            return 19;
        case 38:
            return 20;
        case 39:
            return 0;
        case 40:
            return 21;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 22;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 24;
        case 47:
            return 0;
        case 48:
            return 25;
        case 49:
            return 26;
        case 50:
            return 28;
        case 51:
            return 30;
        case 52:
            return 0;
        case 53:
            return 32;
        case 54:
            return 37;
        case 55:
            return 0;
        case 56:
            return 38;
        case 57:
            return 39;
        case 58:
            return 0;
        case 59:
            return 41;
        case 60:
            return 43;
        case 61:
            return 45;
        case 62:
            return 0;
        case 63:
            return 47;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 56;
        case 68:
            return 60;
        case 69:
            return 61;
        case 70:
            return 0;
        case 71:
            return 62;
        case 72:
            return 0;
        case 73:
            return 63;
        case 74:
            return 0;
        case 75:
            return 0;
        case 76:
            return 65;
        case 77:
            return 67;
        case 78:
            return 69;
        case 79:
            return 70;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 71;
        case 84:
            return 72;
        case 85:
            return 0;
        case 86:
            return 78;
        case 87:
            return 0;
        case 88:
            return 82;
        case 89:
            return 83;
        case 90:
            return 0;
        case 91:
            return 86;
        case 92:
            return 88;
        case 93:
            return 0;
        case 94:
            return 90;
        case 95:
            return 0;
        case 96:
            return 98;
        case 97:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Desert; 0 the dash, the 00 cell reads 100)
inline int ffoTemDesLo(int b)
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
            return 1;
        case 16:
            return 2;
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
            return 3;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 6;
        case 28:
            return 0;
        case 29:
            return 7;
        case 30:
            return 0;
        case 31:
            return 8;
        case 32:
            return 12;
        case 33:
            return 14;
        case 34:
            return 15;
        case 35:
            return 16;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 17;
        case 39:
            return 0;
        case 40:
            return 19;
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
            return 20;
        case 50:
            return 22;
        case 51:
            return 23;
        case 52:
            return 0;
        case 53:
            return 25;
        case 54:
            return 29;
        case 55:
            return 0;
        case 56:
            return 37;
        case 57:
            return 39;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 40;
        case 61:
            return 49;
        case 62:
            return 0;
        case 63:
            return 52;
        case 64:
            return 0;
        case 65:
            return 53;
        case 66:
            return 0;
        case 67:
            return 54;
        case 68:
            return 0;
        case 69:
            return 66;
        case 70:
            return 0;
        case 71:
            return 67;
        case 72:
            return 70;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 0;
        case 76:
            return 72;
        case 77:
            return 77;
        case 78:
            return 86;
        case 79:
            return 0;
        case 80:
            return 90;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 0;
        case 88:
            return 0;
        case 89:
            return 91;
        case 90:
            return 93;
        case 91:
            return 0;
        case 92:
            return 94;
        case 93:
            return 0;
        case 94:
            return 0;
        case 95:
            return 0;
        case 96:
            return 96;
        case 97:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Desert; 0 the dash)
inline int ffoTemDesHi(int b)
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
            return 1;
        case 16:
            return 2;
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
            return 5;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 6;
        case 28:
            return 0;
        case 29:
            return 7;
        case 30:
            return 0;
        case 31:
            return 11;
        case 32:
            return 13;
        case 33:
            return 14;
        case 34:
            return 15;
        case 35:
            return 16;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 18;
        case 39:
            return 0;
        case 40:
            return 19;
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
            return 21;
        case 50:
            return 22;
        case 51:
            return 24;
        case 52:
            return 0;
        case 53:
            return 28;
        case 54:
            return 36;
        case 55:
            return 0;
        case 56:
            return 38;
        case 57:
            return 39;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 48;
        case 61:
            return 51;
        case 62:
            return 0;
        case 63:
            return 52;
        case 64:
            return 0;
        case 65:
            return 53;
        case 66:
            return 0;
        case 67:
            return 65;
        case 68:
            return 0;
        case 69:
            return 66;
        case 70:
            return 0;
        case 71:
            return 69;
        case 72:
            return 71;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 0;
        case 76:
            return 76;
        case 77:
            return 85;
        case 78:
            return 89;
        case 79:
            return 0;
        case 80:
            return 90;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 0;
        case 88:
            return 0;
        case 89:
            return 92;
        case 90:
            return 93;
        case 91:
            return 0;
        case 92:
            return 95;
        case 93:
            return 0;
        case 94:
            return 0;
        case 95:
            return 0;
        case 96:
            return 100;
        case 97:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoTemHilLo(int b)
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
            return 2;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 3;
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
            return 5;
        case 16:
            return 6;
        case 17:
            return 0;
        case 18:
            return 7;
        case 19:
            return 10;
        case 20:
            return 11;
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
            return 12;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 22;
        case 32:
            return 24;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 26;
        case 36:
            return 27;
        case 37:
            return 28;
        case 38:
            return 29;
        case 39:
            return 0;
        case 40:
            return 30;
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
            return 31;
        case 47:
            return 0;
        case 48:
            return 33;
        case 49:
            return 35;
        case 50:
            return 37;
        case 51:
            return 40;
        case 52:
            return 0;
        case 53:
            return 42;
        case 54:
            return 44;
        case 55:
            return 0;
        case 56:
            return 54;
        case 57:
            return 55;
        case 58:
            return 56;
        case 59:
            return 0;
        case 60:
            return 57;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 59;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 62;
        case 68:
            return 71;
        case 69:
            return 77;
        case 70:
            return 0;
        case 71:
            return 78;
        case 72:
            return 0;
        case 73:
            return 79;
        case 74:
            return 0;
        case 75:
            return 0;
        case 76:
            return 80;
        case 77:
            return 81;
        case 78:
            return 82;
        case 79:
            return 84;
        case 80:
            return 86;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 87;
        case 84:
            return 88;
        case 85:
            return 0;
        case 86:
            return 89;
        case 87:
            return 0;
        case 88:
            return 90;
        case 89:
            return 91;
        case 90:
            return 0;
        case 91:
            return 92;
        case 92:
            return 93;
        case 93:
            return 0;
        case 94:
            return 0;
        case 95:
            return 0;
        case 96:
            return 94;
        case 97:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoTemHilHi(int b)
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
            return 2;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 4;
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
            return 5;
        case 16:
            return 6;
        case 17:
            return 0;
        case 18:
            return 9;
        case 19:
            return 10;
        case 20:
            return 11;
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
            return 21;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 23;
        case 32:
            return 25;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 26;
        case 36:
            return 27;
        case 37:
            return 28;
        case 38:
            return 29;
        case 39:
            return 0;
        case 40:
            return 30;
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
            return 32;
        case 47:
            return 0;
        case 48:
            return 34;
        case 49:
            return 36;
        case 50:
            return 39;
        case 51:
            return 41;
        case 52:
            return 0;
        case 53:
            return 43;
        case 54:
            return 53;
        case 55:
            return 0;
        case 56:
            return 54;
        case 57:
            return 55;
        case 58:
            return 56;
        case 59:
            return 0;
        case 60:
            return 58;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 61;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 70;
        case 68:
            return 76;
        case 69:
            return 77;
        case 70:
            return 0;
        case 71:
            return 78;
        case 72:
            return 0;
        case 73:
            return 79;
        case 74:
            return 0;
        case 75:
            return 0;
        case 76:
            return 80;
        case 77:
            return 81;
        case 78:
            return 83;
        case 79:
            return 85;
        case 80:
            return 86;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 87;
        case 84:
            return 88;
        case 85:
            return 0;
        case 86:
            return 89;
        case 87:
            return 0;
        case 88:
            return 90;
        case 89:
            return 91;
        case 90:
            return 0;
        case 91:
            return 92;
        case 92:
            return 93;
        case 93:
            return 0;
        case 94:
            return 0;
        case 95:
            return 0;
        case 96:
            return 98;
        case 97:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountains; 0 the dash, the 00 cell reads 100)
inline int ffoTemMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
            return 3;
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
            return 5;
        case 16:
            return 6;
        case 17:
            return 0;
        case 18:
            return 7;
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
            return 9;
        case 29:
            return 0;
        case 30:
            return 12;
        case 31:
            return 13;
        case 32:
            return 14;
        case 33:
            return 16;
        case 34:
            return 0;
        case 35:
            return 17;
        case 36:
            return 0;
        case 37:
            return 19;
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
            return 21;
        case 46:
            return 23;
        case 47:
            return 0;
        case 48:
            return 35;
        case 49:
            return 36;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 37;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 47;
        case 58:
            return 0;
        case 59:
            return 48;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 49;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 52;
        case 68:
            return 69;
        case 69:
            return 74;
        case 70:
            return 0;
        case 71:
            return 75;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 0;
        case 76:
            return 76;
        case 77:
            return 77;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 81;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 0;
        case 88:
            return 82;
        case 89:
            return 0;
        case 90:
            return 0;
        case 91:
            return 87;
        case 92:
            return 0;
        case 93:
            return 0;
        case 94:
            return 89;
        case 95:
            return 93;
        case 96:
            return 95;
        case 97:
            return 97;
        default:
            return 0;
        }
    }

// The die-high cells (Mountains; 0 the dash)
inline int ffoTemMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
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
            return 4;
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
            return 5;
        case 16:
            return 6;
        case 17:
            return 0;
        case 18:
            return 8;
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
            return 11;
        case 29:
            return 0;
        case 30:
            return 12;
        case 31:
            return 13;
        case 32:
            return 15;
        case 33:
            return 16;
        case 34:
            return 0;
        case 35:
            return 18;
        case 36:
            return 0;
        case 37:
            return 20;
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
            return 22;
        case 46:
            return 34;
        case 47:
            return 0;
        case 48:
            return 35;
        case 49:
            return 36;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 46;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 47;
        case 58:
            return 0;
        case 59:
            return 48;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 51;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 68;
        case 68:
            return 73;
        case 69:
            return 74;
        case 70:
            return 0;
        case 71:
            return 75;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 0;
        case 76:
            return 76;
        case 77:
            return 80;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 81;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 0;
        case 88:
            return 86;
        case 89:
            return 0;
        case 90:
            return 0;
        case 91:
            return 88;
        case 92:
            return 0;
        case 93:
            return 0;
        case 94:
            return 92;
        case 95:
            return 94;
        case 96:
            return 96;
        case 97:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Marsh; 0 the dash, the 00 cell reads 100)
inline int ffoTemMshLo(int b)
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
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 3;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 4;
        case 14:
            return 0;
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
            return 6;
        case 22:
            return 8;
        case 23:
            return 0;
        case 24:
            return 9;
        case 25:
            return 10;
        case 26:
            return 12;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 14;
        case 31:
            return 0;
        case 32:
            return 15;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 16;
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
            return 17;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 23;
        case 45:
            return 25;
        case 46:
            return 26;
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
            return 27;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 38;
        case 58:
            return 0;
        case 59:
            return 39;
        case 60:
            return 0;
        case 61:
            return 40;
        case 62:
            return 44;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 48;
        case 66:
            return 49;
        case 67:
            return 52;
        case 68:
            return 0;
        case 69:
            return 64;
        case 70:
            return 65;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 66;
        case 76:
            return 70;
        case 77:
            return 80;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 82;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 83;
        case 85:
            return 0;
        case 86:
            return 86;
        case 87:
            return 0;
        case 88:
            return 89;
        case 89:
            return 0;
        case 90:
            return 0;
        case 91:
            return 94;
        case 92:
            return 96;
        case 93:
            return 0;
        case 94:
            return 97;
        case 95:
            return 0;
        case 96:
            return 0;
        case 97:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Marsh; 0 the dash)
inline int ffoTemMshHi(int b)
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
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 3;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 4;
        case 14:
            return 0;
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
            return 7;
        case 22:
            return 8;
        case 23:
            return 0;
        case 24:
            return 9;
        case 25:
            return 11;
        case 26:
            return 13;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 14;
        case 31:
            return 0;
        case 32:
            return 15;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 16;
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
            return 22;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 24;
        case 45:
            return 25;
        case 46:
            return 26;
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
            return 37;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 38;
        case 58:
            return 0;
        case 59:
            return 39;
        case 60:
            return 0;
        case 61:
            return 43;
        case 62:
            return 47;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 48;
        case 66:
            return 51;
        case 67:
            return 63;
        case 68:
            return 0;
        case 69:
            return 64;
        case 70:
            return 65;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 69;
        case 76:
            return 79;
        case 77:
            return 81;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 82;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 85;
        case 85:
            return 0;
        case 86:
            return 88;
        case 87:
            return 0;
        case 88:
            return 93;
        case 89:
            return 0;
        case 90:
            return 0;
        case 91:
            return 95;
        case 92:
            return 96;
        case 93:
            return 0;
        case 94:
            return 100;
        case 95:
            return 0;
        case 96:
            return 0;
        case 97:
            return 0;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoPatOrd(int b)
    {
        switch (b) {
        case 0:
            return 206;
        case 1:
            return 38;
        case 2:
            return 191;
        case 3:
            return 39;
        case 4:
            return 207;
        case 5:
            return 208;
        case 6:
            return 43;
        case 7:
            return 44;
        case 8:
            return 46;
        case 9:
            return 49;
        case 10:
            return 209;
        case 11:
            return 51;
        case 12:
            return 54;
        case 13:
            return 56;
        case 14:
            return 192;
        case 15:
            return 61;
        case 16:
            return 66;
        case 17:
            return 125;
        case 18:
            return 126;
        case 19:
            return 71;
        case 20:
            return 193;
        case 21:
            return 194;
        case 22:
            return 195;
        case 23:
            return 210;
        case 24:
            return 19;
        case 25:
            return 127;
        case 26:
            return 159;
        case 27:
            return 211;
        case 28:
            return 128;
        case 29:
            return 160;
        case 30:
            return 196;
        case 31:
            return 87;
        case 32:
            return 212;
        case 33:
            return 213;
        case 34:
            return 93;
        case 35:
            return 214;
        case 36:
            return 215;
        case 37:
            return 216;
        case 38:
            return 217;
        case 39:
            return 218;
        case 40:
            return 219;
        case 41:
            return 220;
        case 42:
            return 221;
        case 43:
            return 222;
        case 44:
            return 223;
        case 45:
            return 224;
        case 46:
            return 225;
        case 47:
            return 226;
        case 48:
            return 98;
        case 49:
            return 162;
        case 50:
            return 227;
        case 51:
            return 199;
        case 52:
            return 101;
        case 53:
            return 26;
        case 54:
            return 228;
        case 55:
            return 229;
        case 56:
            return 203;
        case 57:
            return 117;
        case 58:
            return 122;
        case 59:
            return 14;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoPatSrc(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 3;
        case 9:
            return 1;
        case 10:
            return 3;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 3;
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
            return 3;
        case 31:
            return 3;
        case 32:
            return 3;
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
            return 4;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 4;
        case 47:
            return 1;
        case 48:
            return 1;
        case 49:
            return 1;
        case 50:
            return 3;
        case 51:
            return 3;
        case 52:
            return 3;
        case 53:
            return 1;
        case 54:
            return 3;
        case 55:
            return 1;
        case 56:
            return 1;
        case 57:
            return 3;
        case 58:
            return 1;
        case 59:
            return 1;
        default:
            return 0;
        }
    }

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoPatPlnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 0;
        case 3:
            return 6;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 0;
        case 9:
            return 9;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 14;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 15;
        case 19:
            return 16;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 17;
        case 24:
            return 18;
        case 25:
            return 20;
        case 26:
            return 21;
        case 27:
            return 23;
        case 28:
            return 24;
        case 29:
            return 26;
        case 30:
            return 0;
        case 31:
            return 27;
        case 32:
            return 28;
        case 33:
            return 29;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 30;
        case 39:
            return 31;
        case 40:
            return 33;
        case 41:
            return 34;
        case 42:
            return 39;
        case 43:
            return 41;
        case 44:
            return 45;
        case 45:
            return 47;
        case 46:
            return 70;
        case 47:
            return 72;
        case 48:
            return 78;
        case 49:
            return 81;
        case 50:
            return 85;
        case 51:
            return 86;
        case 52:
            return 0;
        case 53:
            return 87;
        case 54:
            return 0;
        case 55:
            return 89;
        case 56:
            return 91;
        case 57:
            return 92;
        case 58:
            return 0;
        case 59:
            return 94;
        default:
            return 0;
        }
    }

// The die-high cells (Plain; 0 the dash)
inline int ffoPatPlnHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 0;
        case 3:
            return 6;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 0;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 14;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 15;
        case 19:
            return 16;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 17;
        case 24:
            return 19;
        case 25:
            return 20;
        case 26:
            return 22;
        case 27:
            return 23;
        case 28:
            return 25;
        case 29:
            return 26;
        case 30:
            return 0;
        case 31:
            return 27;
        case 32:
            return 28;
        case 33:
            return 29;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 30;
        case 39:
            return 32;
        case 40:
            return 33;
        case 41:
            return 38;
        case 42:
            return 40;
        case 43:
            return 44;
        case 44:
            return 46;
        case 45:
            return 69;
        case 46:
            return 71;
        case 47:
            return 77;
        case 48:
            return 80;
        case 49:
            return 84;
        case 50:
            return 85;
        case 51:
            return 86;
        case 52:
            return 0;
        case 53:
            return 88;
        case 54:
            return 0;
        case 55:
            return 90;
        case 56:
            return 91;
        case 57:
            return 93;
        case 58:
            return 0;
        case 59:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Scrub; 0 the dash, the 00 cell reads 100)
inline int ffoPatScrLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 4;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        case 9:
            return 9;
        case 10:
            return 11;
        case 11:
            return 12;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 13;
        case 15:
            return 14;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 15;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 17;
        case 24:
            return 18;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 19;
        case 28:
            return 20;
        case 29:
            return 21;
        case 30:
            return 0;
        case 31:
            return 23;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 24;
        case 37:
            return 26;
        case 38:
            return 27;
        case 39:
            return 0;
        case 40:
            return 28;
        case 41:
            return 29;
        case 42:
            return 33;
        case 43:
            return 35;
        case 44:
            return 39;
        case 45:
            return 41;
        case 46:
            return 59;
        case 47:
            return 61;
        case 48:
            return 68;
        case 49:
            return 75;
        case 50:
            return 0;
        case 51:
            return 85;
        case 52:
            return 0;
        case 53:
            return 86;
        case 54:
            return 89;
        case 55:
            return 90;
        case 56:
            return 0;
        case 57:
            return 92;
        case 58:
            return 0;
        case 59:
            return 93;
        default:
            return 0;
        }
    }

// The die-high cells (Scrub; 0 the dash)
inline int ffoPatScrHi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        case 9:
            return 10;
        case 10:
            return 11;
        case 11:
            return 12;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 13;
        case 15:
            return 14;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 16;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 17;
        case 24:
            return 18;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 19;
        case 28:
            return 20;
        case 29:
            return 22;
        case 30:
            return 0;
        case 31:
            return 23;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 25;
        case 37:
            return 26;
        case 38:
            return 27;
        case 39:
            return 0;
        case 40:
            return 28;
        case 41:
            return 32;
        case 42:
            return 34;
        case 43:
            return 38;
        case 44:
            return 40;
        case 45:
            return 58;
        case 46:
            return 60;
        case 47:
            return 67;
        case 48:
            return 74;
        case 49:
            return 84;
        case 50:
            return 0;
        case 51:
            return 85;
        case 52:
            return 0;
        case 53:
            return 88;
        case 54:
            return 89;
        case 55:
            return 91;
        case 56:
            return 0;
        case 57:
            return 92;
        case 58:
            return 0;
        case 59:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoPatForLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 0;
        case 3:
            return 5;
        case 4:
            return 0;
        case 5:
            return 6;
        case 6:
            return 9;
        case 7:
            return 11;
        case 8:
            return 13;
        case 9:
            return 14;
        case 10:
            return 17;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 18;
        case 14:
            return 19;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 20;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 24;
        case 24:
            return 25;
        case 25:
            return 26;
        case 26:
            return 28;
        case 27:
            return 0;
        case 28:
            return 29;
        case 29:
            return 30;
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
            return 31;
        case 36:
            return 32;
        case 37:
            return 0;
        case 38:
            return 33;
        case 39:
            return 34;
        case 40:
            return 0;
        case 41:
            return 35;
        case 42:
            return 38;
        case 43:
            return 40;
        case 44:
            return 45;
        case 45:
            return 47;
        case 46:
            return 0;
        case 47:
            return 57;
        case 48:
            return 62;
        case 49:
            return 72;
        case 50:
            return 0;
        case 51:
            return 84;
        case 52:
            return 0;
        case 53:
            return 85;
        case 54:
            return 87;
        case 55:
            return 89;
        case 56:
            return 93;
        case 57:
            return 0;
        case 58:
            return 0;
        case 59:
            return 94;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoPatForHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 0;
        case 3:
            return 5;
        case 4:
            return 0;
        case 5:
            return 8;
        case 6:
            return 10;
        case 7:
            return 12;
        case 8:
            return 13;
        case 9:
            return 16;
        case 10:
            return 17;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 18;
        case 14:
            return 19;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 23;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 24;
        case 24:
            return 25;
        case 25:
            return 27;
        case 26:
            return 28;
        case 27:
            return 0;
        case 28:
            return 29;
        case 29:
            return 30;
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
            return 31;
        case 36:
            return 32;
        case 37:
            return 0;
        case 38:
            return 33;
        case 39:
            return 34;
        case 40:
            return 0;
        case 41:
            return 37;
        case 42:
            return 39;
        case 43:
            return 44;
        case 44:
            return 46;
        case 45:
            return 56;
        case 46:
            return 0;
        case 47:
            return 61;
        case 48:
            return 71;
        case 49:
            return 83;
        case 50:
            return 0;
        case 51:
            return 84;
        case 52:
            return 0;
        case 53:
            return 86;
        case 54:
            return 88;
        case 55:
            return 92;
        case 56:
            return 93;
        case 57:
            return 0;
        case 58:
            return 0;
        case 59:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoPatRghLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 8;
        case 9:
            return 9;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 11;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 12;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 14;
        case 21:
            return 16;
        case 22:
            return 17;
        case 23:
            return 20;
        case 24:
            return 22;
        case 25:
            return 24;
        case 26:
            return 26;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 28;
        case 30:
            return 0;
        case 31:
            return 29;
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
            return 31;
        case 38:
            return 0;
        case 39:
            return 33;
        case 40:
            return 34;
        case 41:
            return 35;
        case 42:
            return 39;
        case 43:
            return 41;
        case 44:
            return 45;
        case 45:
            return 49;
        case 46:
            return 57;
        case 47:
            return 59;
        case 48:
            return 64;
        case 49:
            return 69;
        case 50:
            return 81;
        case 51:
            return 82;
        case 52:
            return 0;
        case 53:
            return 84;
        case 54:
            return 86;
        case 55:
            return 87;
        case 56:
            return 0;
        case 57:
            return 89;
        case 58:
            return 90;
        case 59:
            return 92;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoPatRghHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 7;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 8;
        case 9:
            return 10;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 11;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 13;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 15;
        case 21:
            return 16;
        case 22:
            return 19;
        case 23:
            return 21;
        case 24:
            return 23;
        case 25:
            return 25;
        case 26:
            return 27;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 28;
        case 30:
            return 0;
        case 31:
            return 30;
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
            return 32;
        case 38:
            return 0;
        case 39:
            return 33;
        case 40:
            return 34;
        case 41:
            return 38;
        case 42:
            return 40;
        case 43:
            return 44;
        case 44:
            return 48;
        case 45:
            return 56;
        case 46:
            return 58;
        case 47:
            return 63;
        case 48:
            return 68;
        case 49:
            return 80;
        case 50:
            return 81;
        case 51:
            return 83;
        case 52:
            return 0;
        case 53:
            return 85;
        case 54:
            return 86;
        case 55:
            return 88;
        case 56:
            return 0;
        case 57:
            return 89;
        case 58:
            return 91;
        case 59:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Desert; 0 the dash, the 00 cell reads 100)
inline int ffoPatDesLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
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
            return 2;
        case 16:
            return 3;
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
            return 4;
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
            return 7;
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
            return 8;
        case 41:
            return 10;
        case 42:
            return 13;
        case 43:
            return 15;
        case 44:
            return 19;
        case 45:
            return 29;
        case 46:
            return 50;
        case 47:
            return 68;
        case 48:
            return 0;
        case 49:
            return 72;
        case 50:
            return 82;
        case 51:
            return 86;
        case 52:
            return 87;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 90;
        case 57:
            return 91;
        case 58:
            return 0;
        case 59:
            return 95;
        default:
            return 0;
        }
    }

// The die-high cells (Desert; 0 the dash)
inline int ffoPatDesHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
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
            return 2;
        case 16:
            return 3;
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
            return 6;
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
            return 7;
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
            return 9;
        case 41:
            return 12;
        case 42:
            return 14;
        case 43:
            return 18;
        case 44:
            return 28;
        case 45:
            return 49;
        case 46:
            return 67;
        case 47:
            return 71;
        case 48:
            return 0;
        case 49:
            return 81;
        case 50:
            return 85;
        case 51:
            return 86;
        case 52:
            return 89;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 90;
        case 57:
            return 94;
        case 58:
            return 0;
        case 59:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoPatHilLo(int b)
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
            return 0;
        case 5:
            return 0;
        case 6:
            return 5;
        case 7:
            return 0;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 0;
        case 11:
            return 9;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 10;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 11;
        case 18:
            return 13;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 15;
        case 24:
            return 19;
        case 25:
            return 21;
        case 26:
            return 24;
        case 27:
            return 26;
        case 28:
            return 27;
        case 29:
            return 30;
        case 30:
            return 0;
        case 31:
            return 31;
        case 32:
            return 0;
        case 33:
            return 32;
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
            return 34;
        case 40:
            return 35;
        case 41:
            return 36;
        case 42:
            return 40;
        case 43:
            return 42;
        case 44:
            return 48;
        case 45:
            return 50;
        case 46:
            return 62;
        case 47:
            return 64;
        case 48:
            return 68;
        case 49:
            return 76;
        case 50:
            return 85;
        case 51:
            return 86;
        case 52:
            return 0;
        case 53:
            return 87;
        case 54:
            return 90;
        case 55:
            return 91;
        case 56:
            return 0;
        case 57:
            return 93;
        case 58:
            return 0;
        case 59:
            return 94;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoPatHilHi(int b)
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
            return 0;
        case 5:
            return 0;
        case 6:
            return 5;
        case 7:
            return 0;
        case 8:
            return 6;
        case 9:
            return 8;
        case 10:
            return 0;
        case 11:
            return 9;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 10;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 12;
        case 18:
            return 14;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 18;
        case 24:
            return 20;
        case 25:
            return 23;
        case 26:
            return 25;
        case 27:
            return 26;
        case 28:
            return 29;
        case 29:
            return 30;
        case 30:
            return 0;
        case 31:
            return 31;
        case 32:
            return 0;
        case 33:
            return 33;
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
            return 34;
        case 40:
            return 35;
        case 41:
            return 39;
        case 42:
            return 41;
        case 43:
            return 47;
        case 44:
            return 49;
        case 45:
            return 61;
        case 46:
            return 63;
        case 47:
            return 67;
        case 48:
            return 75;
        case 49:
            return 84;
        case 50:
            return 85;
        case 51:
            return 86;
        case 52:
            return 0;
        case 53:
            return 89;
        case 54:
            return 90;
        case 55:
            return 92;
        case 56:
            return 0;
        case 57:
            return 93;
        case 58:
            return 0;
        case 59:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountains; 0 the dash, the 00 cell reads 100)
inline int ffoPatMtnLo(int b)
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
            return 16;
        case 24:
            return 18;
        case 25:
            return 20;
        case 26:
            return 22;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 25;
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
            return 27;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 28;
        case 40:
            return 30;
        case 41:
            return 31;
        case 42:
            return 33;
        case 43:
            return 35;
        case 44:
            return 40;
        case 45:
            return 50;
        case 46:
            return 0;
        case 47:
            return 52;
        case 48:
            return 60;
        case 49:
            return 67;
        case 50:
            return 0;
        case 51:
            return 80;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 81;
        case 57:
            return 0;
        case 58:
            return 88;
        case 59:
            return 90;
        default:
            return 0;
        }
    }

// The die-high cells (Mountains; 0 the dash)
inline int ffoPatMtnHi(int b)
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
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 15;
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
            return 17;
        case 24:
            return 19;
        case 25:
            return 21;
        case 26:
            return 24;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 26;
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
            return 27;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 29;
        case 40:
            return 30;
        case 41:
            return 32;
        case 42:
            return 34;
        case 43:
            return 39;
        case 44:
            return 41;
        case 45:
            return 51;
        case 46:
            return 0;
        case 47:
            return 59;
        case 48:
            return 66;
        case 49:
            return 79;
        case 50:
            return 0;
        case 51:
            return 80;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 87;
        case 57:
            return 0;
        case 58:
            return 89;
        case 59:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Marsh; 0 the dash, the 00 cell reads 100)
inline int ffoPatMshLo(int b)
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
            return 5;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 7;
        case 13:
            return 9;
        case 14:
            return 10;
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
            return 11;
        case 23:
            return 0;
        case 24:
            return 13;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 16;
        case 30:
            return 17;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 20;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 21;
        case 38:
            return 0;
        case 39:
            return 22;
        case 40:
            return 23;
        case 41:
            return 25;
        case 42:
            return 28;
        case 43:
            return 30;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 35;
        case 48:
            return 39;
        case 49:
            return 47;
        case 50:
            return 0;
        case 51:
            return 65;
        case 52:
            return 0;
        case 53:
            return 66;
        case 54:
            return 79;
        case 55:
            return 0;
        case 56:
            return 80;
        case 57:
            return 0;
        case 58:
            return 86;
        case 59:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Marsh; 0 the dash)
inline int ffoPatMshHi(int b)
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
        case 4:
            return 0;
        case 5:
            return 4;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 6;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 8;
        case 13:
            return 9;
        case 14:
            return 10;
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
            return 12;
        case 23:
            return 0;
        case 24:
            return 15;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 16;
        case 30:
            return 19;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 20;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 21;
        case 38:
            return 0;
        case 39:
            return 22;
        case 40:
            return 24;
        case 41:
            return 27;
        case 42:
            return 29;
        case 43:
            return 34;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 37;
        case 48:
            return 46;
        case 49:
            return 64;
        case 50:
            return 0;
        case 51:
            return 65;
        case 52:
            return 0;
        case 53:
            return 78;
        case 54:
            return 79;
        case 55:
            return 0;
        case 56:
            return 84;
        case 57:
            return 0;
        case 58:
            return 100;
        case 59:
            return 0;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoFaeOrd(int b)
    {
        switch (b) {
        case 0:
            return 37;
        case 1:
            return 230;
        case 2:
            return 231;
        case 3:
            return 1;
        case 4:
            return 232;
        case 5:
            return 233;
        case 6:
            return 234;
        case 7:
            return 56;
        case 8:
            return 235;
        case 9:
            return 133;
        case 10:
            return 236;
        case 11:
            return 237;
        case 12:
            return 125;
        case 13:
            return 126;
        case 14:
            return 238;
        case 15:
            return 127;
        case 16:
            return 239;
        case 17:
            return 240;
        case 18:
            return 81;
        case 19:
            return 241;
        case 20:
            return 82;
        case 21:
            return 242;
        case 22:
            return 243;
        case 23:
            return 213;
        case 24:
            return 244;
        case 25:
            return 214;
        case 26:
            return 219;
        case 27:
            return 220;
        case 28:
            return 223;
        case 29:
            return 226;
        case 30:
            return 9;
        case 31:
            return 245;
        case 32:
            return 98;
        case 33:
            return 100;
        case 34:
            return 246;
        case 35:
            return 247;
        case 36:
            return 248;
        case 37:
            return 249;
        case 38:
            return 250;
        case 39:
            return 251;
        case 40:
            return 252;
        case 41:
            return 253;
        case 42:
            return 114;
        case 43:
            return 29;
        case 44:
            return 254;
        case 45:
            return 255;
        case 46:
            return 14;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoFaeSrc(int b)
    {
        switch (b) {
        case 0:
            return 3;
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
            return 3;
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
            return 3;
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
            return 3;
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
            return 4;
        case 43:
            return 1;
        case 44:
            return 1;
        case 45:
            return 3;
        case 46:
            return 1;
        default:
            return 0;
        }
    }

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoFaePlnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 4;
        case 7:
            return 0;
        case 8:
            return 10;
        case 9:
            return 14;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 16;
        case 14:
            return 17;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 20;
        case 18:
            return 23;
        case 19:
            return 27;
        case 20:
            return 28;
        case 21:
            return 0;
        case 22:
            return 32;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 34;
        case 27:
            return 38;
        case 28:
            return 40;
        case 29:
            return 43;
        case 30:
            return 48;
        case 31:
            return 0;
        case 32:
            return 53;
        case 33:
            return 61;
        case 34:
            return 67;
        case 35:
            return 71;
        case 36:
            return 78;
        case 37:
            return 79;
        case 38:
            return 81;
        case 39:
            return 83;
        case 40:
            return 0;
        case 41:
            return 85;
        case 42:
            return 0;
        case 43:
            return 88;
        case 44:
            return 90;
        case 45:
            return 0;
        case 46:
            return 92;
        default:
            return 0;
        }
    }

// The die-high cells (Plain; 0 the dash)
inline int ffoFaePlnHi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 9;
        case 7:
            return 0;
        case 8:
            return 13;
        case 9:
            return 15;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 16;
        case 14:
            return 19;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 22;
        case 18:
            return 26;
        case 19:
            return 27;
        case 20:
            return 31;
        case 21:
            return 0;
        case 22:
            return 33;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 37;
        case 27:
            return 39;
        case 28:
            return 42;
        case 29:
            return 47;
        case 30:
            return 52;
        case 31:
            return 0;
        case 32:
            return 60;
        case 33:
            return 66;
        case 34:
            return 70;
        case 35:
            return 77;
        case 36:
            return 78;
        case 37:
            return 80;
        case 38:
            return 82;
        case 39:
            return 84;
        case 40:
            return 0;
        case 41:
            return 87;
        case 42:
            return 0;
        case 43:
            return 89;
        case 44:
            return 91;
        case 45:
            return 0;
        case 46:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoFaeForLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 8;
        case 5:
            return 10;
        case 6:
            return 11;
        case 7:
            return 12;
        case 8:
            return 14;
        case 9:
            return 15;
        case 10:
            return 16;
        case 11:
            return 17;
        case 12:
            return 0;
        case 13:
            return 18;
        case 14:
            return 21;
        case 15:
            return 22;
        case 16:
            return 24;
        case 17:
            return 26;
        case 18:
            return 27;
        case 19:
            return 0;
        case 20:
            return 28;
        case 21:
            return 29;
        case 22:
            return 31;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 34;
        case 26:
            return 35;
        case 27:
            return 37;
        case 28:
            return 41;
        case 29:
            return 42;
        case 30:
            return 43;
        case 31:
            return 45;
        case 32:
            return 46;
        case 33:
            return 0;
        case 34:
            return 49;
        case 35:
            return 51;
        case 36:
            return 55;
        case 37:
            return 64;
        case 38:
            return 69;
        case 39:
            return 74;
        case 40:
            return 77;
        case 41:
            return 84;
        case 42:
            return 85;
        case 43:
            return 87;
        case 44:
            return 89;
        case 45:
            return 96;
        case 46:
            return 98;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoFaeForHi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 7;
        case 4:
            return 9;
        case 5:
            return 10;
        case 6:
            return 11;
        case 7:
            return 13;
        case 8:
            return 14;
        case 9:
            return 15;
        case 10:
            return 16;
        case 11:
            return 17;
        case 12:
            return 0;
        case 13:
            return 20;
        case 14:
            return 21;
        case 15:
            return 23;
        case 16:
            return 25;
        case 17:
            return 26;
        case 18:
            return 27;
        case 19:
            return 0;
        case 20:
            return 28;
        case 21:
            return 30;
        case 22:
            return 33;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 34;
        case 26:
            return 36;
        case 27:
            return 40;
        case 28:
            return 41;
        case 29:
            return 42;
        case 30:
            return 44;
        case 31:
            return 45;
        case 32:
            return 48;
        case 33:
            return 0;
        case 34:
            return 50;
        case 35:
            return 54;
        case 36:
            return 63;
        case 37:
            return 68;
        case 38:
            return 73;
        case 39:
            return 76;
        case 40:
            return 83;
        case 41:
            return 84;
        case 42:
            return 86;
        case 43:
            return 88;
        case 44:
            return 95;
        case 45:
            return 97;
        case 46:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoFaeHilLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 4;
        case 5:
            return 6;
        case 6:
            return 9;
        case 7:
            return 0;
        case 8:
            return 11;
        case 9:
            return 15;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 17;
        case 13:
            return 19;
        case 14:
            return 23;
        case 15:
            return 24;
        case 16:
            return 28;
        case 17:
            return 29;
        case 18:
            return 30;
        case 19:
            return 32;
        case 20:
            return 33;
        case 21:
            return 0;
        case 22:
            return 35;
        case 23:
            return 36;
        case 24:
            return 37;
        case 25:
            return 38;
        case 26:
            return 39;
        case 27:
            return 41;
        case 28:
            return 43;
        case 29:
            return 45;
        case 30:
            return 47;
        case 31:
            return 0;
        case 32:
            return 50;
        case 33:
            return 52;
        case 34:
            return 53;
        case 35:
            return 55;
        case 36:
            return 57;
        case 37:
            return 59;
        case 38:
            return 61;
        case 39:
            return 64;
        case 40:
            return 0;
        case 41:
            return 69;
        case 42:
            return 0;
        case 43:
            return 74;
        case 44:
            return 79;
        case 45:
            return 0;
        case 46:
            return 84;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoFaeHilHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 5;
        case 5:
            return 8;
        case 6:
            return 10;
        case 7:
            return 0;
        case 8:
            return 14;
        case 9:
            return 16;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 18;
        case 13:
            return 22;
        case 14:
            return 23;
        case 15:
            return 27;
        case 16:
            return 28;
        case 17:
            return 29;
        case 18:
            return 31;
        case 19:
            return 32;
        case 20:
            return 34;
        case 21:
            return 0;
        case 22:
            return 35;
        case 23:
            return 36;
        case 24:
            return 37;
        case 25:
            return 38;
        case 26:
            return 40;
        case 27:
            return 42;
        case 28:
            return 44;
        case 29:
            return 46;
        case 30:
            return 49;
        case 31:
            return 0;
        case 32:
            return 51;
        case 33:
            return 52;
        case 34:
            return 54;
        case 35:
            return 56;
        case 36:
            return 58;
        case 37:
            return 60;
        case 38:
            return 63;
        case 39:
            return 68;
        case 40:
            return 0;
        case 41:
            return 73;
        case 42:
            return 0;
        case 43:
            return 78;
        case 44:
            return 83;
        case 45:
            return 0;
        case 46:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountains; 0 the dash, the 00 cell reads 100)
inline int ffoFaeMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 4;
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
            return 9;
        case 10:
            return 15;
        case 11:
            return 16;
        case 12:
            return 17;
        case 13:
            return 24;
        case 14:
            return 25;
        case 15:
            return 28;
        case 16:
            return 0;
        case 17:
            return 30;
        case 18:
            return 31;
        case 19:
            return 33;
        case 20:
            return 35;
        case 21:
            return 0;
        case 22:
            return 38;
        case 23:
            return 0;
        case 24:
            return 39;
        case 25:
            return 41;
        case 26:
            return 42;
        case 27:
            return 43;
        case 28:
            return 44;
        case 29:
            return 45;
        case 30:
            return 47;
        case 31:
            return 0;
        case 32:
            return 48;
        case 33:
            return 53;
        case 34:
            return 57;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 60;
        case 39:
            return 62;
        case 40:
            return 0;
        case 41:
            return 67;
        case 42:
            return 0;
        case 43:
            return 72;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 87;
        default:
            return 0;
        }
    }

// The die-high cells (Mountains; 0 the dash)
inline int ffoFaeMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 8;
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
            return 14;
        case 10:
            return 15;
        case 11:
            return 16;
        case 12:
            return 23;
        case 13:
            return 24;
        case 14:
            return 27;
        case 15:
            return 29;
        case 16:
            return 0;
        case 17:
            return 30;
        case 18:
            return 32;
        case 19:
            return 34;
        case 20:
            return 37;
        case 21:
            return 0;
        case 22:
            return 38;
        case 23:
            return 0;
        case 24:
            return 40;
        case 25:
            return 41;
        case 26:
            return 42;
        case 27:
            return 43;
        case 28:
            return 44;
        case 29:
            return 46;
        case 30:
            return 47;
        case 31:
            return 0;
        case 32:
            return 52;
        case 33:
            return 56;
        case 34:
            return 59;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 61;
        case 39:
            return 66;
        case 40:
            return 0;
        case 41:
            return 71;
        case 42:
            return 0;
        case 43:
            return 86;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoTroOrd(int b)
    {
        switch (b) {
        case 0:
            return 33;
        case 1:
            return 36;
        case 2:
            return 38;
        case 3:
            return 256;
        case 4:
            return 257;
        case 5:
            return 258;
        case 6:
            return 231;
        case 7:
            return 208;
        case 8:
            return 259;
        case 9:
            return 260;
        case 10:
            return 261;
        case 11:
            return 53;
        case 12:
            return 55;
        case 13:
            return 262;
        case 14:
            return 263;
        case 15:
            return 58;
        case 16:
            return 264;
        case 17:
            return 265;
        case 18:
            return 266;
        case 19:
            return 267;
        case 20:
            return 268;
        case 21:
            return 269;
        case 22:
            return 270;
        case 23:
            return 59;
        case 24:
            return 61;
        case 25:
            return 66;
        case 26:
            return 271;
        case 27:
            return 272;
        case 28:
            return 273;
        case 29:
            return 274;
        case 30:
            return 70;
        case 31:
            return 275;
        case 32:
            return 71;
        case 33:
            return 72;
        case 34:
            return 276;
        case 35:
            return 277;
        case 36:
            return 278;
        case 37:
            return 279;
        case 38:
            return 280;
        case 39:
            return 6;
        case 40:
            return 281;
        case 41:
            return 282;
        case 42:
            return 86;
        case 43:
            return 283;
        case 44:
            return 242;
        case 45:
            return 284;
        case 46:
            return 285;
        case 47:
            return 286;
        case 48:
            return 287;
        case 49:
            return 288;
        case 50:
            return 243;
        case 51:
            return 91;
        case 52:
            return 93;
        case 53:
            return 289;
        case 54:
            return 217;
        case 55:
            return 95;
        case 56:
            return 220;
        case 57:
            return 223;
        case 58:
            return 224;
        case 59:
            return 225;
        case 60:
            return 226;
        case 61:
            return 290;
        case 62:
            return 9;
        case 63:
            return 291;
        case 64:
            return 292;
        case 65:
            return 293;
        case 66:
            return 294;
        case 67:
            return 101;
        case 68:
            return 295;
        case 69:
            return 296;
        case 70:
            return 297;
        case 71:
            return 298;
        case 72:
            return 299;
        case 73:
            return 300;
        case 74:
            return 301;
        case 75:
            return 302;
        case 76:
            return 202;
        case 77:
            return 106;
        case 78:
            return 303;
        case 79:
            return 304;
        case 80:
            return 305;
        case 81:
            return 306;
        case 82:
            return 110;
        case 83:
            return 28;
        case 84:
            return 307;
        case 85:
            return 113;
        case 86:
            return 308;
        case 87:
            return 309;
        case 88:
            return 310;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoTroSrc(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
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
            return 1;
        case 10:
            return 1;
        case 11:
            return 3;
        case 12:
            return 1;
        case 13:
            return 3;
        case 14:
            return 1;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 3;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 3;
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
        case 30:
            return 3;
        case 31:
            return 1;
        case 32:
            return 3;
        case 33:
            return 3;
        case 34:
            return 1;
        case 35:
            return 3;
        case 36:
            return 3;
        case 37:
            return 3;
        case 38:
            return 3;
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
            return 1;
        case 46:
            return 3;
        case 47:
            return 1;
        case 48:
            return 4;
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
        case 55:
            return 3;
        case 56:
            return 1;
        case 57:
            return 1;
        case 58:
            return 1;
        case 59:
            return 4;
        case 60:
            return 1;
        case 61:
            return 1;
        case 62:
            return 1;
        case 63:
            return 1;
        case 64:
            return 1;
        case 65:
            return 3;
        case 66:
            return 3;
        case 67:
            return 3;
        case 68:
            return 1;
        case 69:
            return 1;
        case 70:
            return 1;
        case 71:
            return 1;
        case 72:
            return 1;
        case 73:
            return 1;
        case 74:
            return 1;
        case 75:
            return 1;
        case 76:
            return 1;
        case 77:
            return 0;
        case 78:
            return 1;
        case 79:
            return 1;
        case 80:
            return 1;
        case 81:
            return 3;
        case 82:
            return 3;
        case 83:
            return 1;
        case 84:
            return 3;
        case 85:
            return 1;
        case 86:
            return 1;
        case 87:
            return 4;
        case 88:
            return 1;
        default:
            return 0;
        }
    }

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoTroPlnLo(int b)
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
            return 3;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 5;
        case 10:
            return 7;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 11;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 12;
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
            return 14;
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
            return 15;
        case 32:
            return 20;
        case 33:
            return 22;
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
            return 23;
        case 40:
            return 0;
        case 41:
            return 39;
        case 42:
            return 44;
        case 43:
            return 48;
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
            return 49;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 58;
        case 56:
            return 59;
        case 57:
            return 63;
        case 58:
            return 64;
        case 59:
            return 71;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 73;
        case 70:
            return 81;
        case 71:
            return 86;
        case 72:
            return 90;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 92;
        case 76:
            return 0;
        case 77:
            return 0;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 95;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 96;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Plain; 0 the dash)
inline int ffoTroPlnHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 4;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 6;
        case 10:
            return 10;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 11;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 13;
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
            return 14;
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
            return 19;
        case 32:
            return 21;
        case 33:
            return 22;
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
            return 38;
        case 40:
            return 0;
        case 41:
            return 43;
        case 42:
            return 47;
        case 43:
            return 48;
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
            return 57;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 58;
        case 56:
            return 62;
        case 57:
            return 63;
        case 58:
            return 70;
        case 59:
            return 72;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 80;
        case 70:
            return 85;
        case 71:
            return 89;
        case 72:
            return 91;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 94;
        case 76:
            return 0;
        case 77:
            return 0;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 95;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 100;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (Scrub; 0 the dash, the 00 cell reads 100)
inline int ffoTroScrLo(int b)
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
            return 3;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 6;
        case 10:
            return 8;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 11;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 13;
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
            return 14;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 15;
        case 27:
            return 18;
        case 28:
            return 21;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 23;
        case 32:
            return 0;
        case 33:
            return 25;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 26;
        case 39:
            return 28;
        case 40:
            return 0;
        case 41:
            return 38;
        case 42:
            return 42;
        case 43:
            return 45;
        case 44:
            return 46;
        case 45:
            return 0;
        case 46:
            return 47;
        case 47:
            return 0;
        case 48:
            return 48;
        case 49:
            return 0;
        case 50:
            return 49;
        case 51:
            return 53;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 58;
        case 57:
            return 0;
        case 58:
            return 62;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 67;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 73;
        case 70:
            return 78;
        case 71:
            return 84;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 87;
        case 75:
            return 0;
        case 76:
            return 0;
        case 77:
            return 0;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 91;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 94;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 96;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Scrub; 0 the dash)
inline int ffoTroScrHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 5;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 7;
        case 10:
            return 10;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 12;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 13;
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
            return 14;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 17;
        case 27:
            return 20;
        case 28:
            return 22;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 24;
        case 32:
            return 0;
        case 33:
            return 25;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 27;
        case 39:
            return 37;
        case 40:
            return 0;
        case 41:
            return 41;
        case 42:
            return 44;
        case 43:
            return 45;
        case 44:
            return 46;
        case 45:
            return 0;
        case 46:
            return 47;
        case 47:
            return 0;
        case 48:
            return 48;
        case 49:
            return 0;
        case 50:
            return 52;
        case 51:
            return 57;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 61;
        case 57:
            return 0;
        case 58:
            return 66;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 72;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 77;
        case 70:
            return 83;
        case 71:
            return 86;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 90;
        case 75:
            return 0;
        case 76:
            return 0;
        case 77:
            return 0;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 93;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 95;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 100;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoTroForLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 6;
        case 6:
            return 0;
        case 7:
            return 7;
        case 8:
            return 11;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 14;
        case 12:
            return 0;
        case 13:
            return 15;
        case 14:
            return 17;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 20;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 22;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 24;
        case 27:
            return 29;
        case 28:
            return 34;
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
            return 36;
        case 39:
            return 39;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 42;
        case 45:
            return 44;
        case 46:
            return 49;
        case 47:
            return 50;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 52;
        case 51:
            return 58;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 61;
        case 55:
            return 0;
        case 56:
            return 63;
        case 57:
            return 0;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 66;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 0;
        case 70:
            return 0;
        case 71:
            return 69;
        case 72:
            return 0;
        case 73:
            return 72;
        case 74:
            return 77;
        case 75:
            return 80;
        case 76:
            return 0;
        case 77:
            return 0;
        case 78:
            return 82;
        case 79:
            return 85;
        case 80:
            return 0;
        case 81:
            return 89;
        case 82:
            return 0;
        case 83:
            return 91;
        case 84:
            return 0;
        case 85:
            return 97;
        case 86:
            return 99;
        case 87:
            return 0;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoTroForHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 5;
        case 4:
            return 0;
        case 5:
            return 6;
        case 6:
            return 0;
        case 7:
            return 10;
        case 8:
            return 13;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 14;
        case 12:
            return 0;
        case 13:
            return 16;
        case 14:
            return 19;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 21;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 23;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 28;
        case 27:
            return 33;
        case 28:
            return 35;
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
            return 38;
        case 39:
            return 41;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 43;
        case 45:
            return 48;
        case 46:
            return 49;
        case 47:
            return 51;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 57;
        case 51:
            return 60;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 62;
        case 55:
            return 0;
        case 56:
            return 65;
        case 57:
            return 0;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 68;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 0;
        case 70:
            return 0;
        case 71:
            return 71;
        case 72:
            return 0;
        case 73:
            return 76;
        case 74:
            return 79;
        case 75:
            return 81;
        case 76:
            return 0;
        case 77:
            return 0;
        case 78:
            return 84;
        case 79:
            return 88;
        case 80:
            return 0;
        case 81:
            return 90;
        case 82:
            return 0;
        case 83:
            return 96;
        case 84:
            return 0;
        case 85:
            return 98;
        case 86:
            return 100;
        case 87:
            return 0;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoTroRghLo(int b)
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
            return 3;
        case 6:
            return 7;
        case 7:
            return 9;
        case 8:
            return 0;
        case 9:
            return 11;
        case 10:
            return 14;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 16;
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
            return 18;
        case 30:
            return 20;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 22;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 23;
        case 39:
            return 25;
        case 40:
            return 0;
        case 41:
            return 28;
        case 42:
            return 34;
        case 43:
            return 37;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 38;
        case 47:
            return 39;
        case 48:
            return 44;
        case 49:
            return 0;
        case 50:
            return 46;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 48;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 52;
        case 57:
            return 55;
        case 58:
            return 57;
        case 59:
            return 60;
        case 60:
            return 66;
        case 61:
            return 0;
        case 62:
            return 72;
        case 63:
            return 76;
        case 64:
            return 78;
        case 65:
            return 80;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 81;
        case 69:
            return 0;
        case 70:
            return 84;
        case 71:
            return 87;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 89;
        case 75:
            return 91;
        case 76:
            return 93;
        case 77:
            return 95;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 97;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoTroRghHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 6;
        case 6:
            return 8;
        case 7:
            return 10;
        case 8:
            return 0;
        case 9:
            return 13;
        case 10:
            return 15;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 17;
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
            return 19;
        case 30:
            return 21;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 22;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 24;
        case 39:
            return 27;
        case 40:
            return 0;
        case 41:
            return 33;
        case 42:
            return 36;
        case 43:
            return 37;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 38;
        case 47:
            return 43;
        case 48:
            return 45;
        case 49:
            return 0;
        case 50:
            return 47;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 51;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 54;
        case 57:
            return 56;
        case 58:
            return 59;
        case 59:
            return 65;
        case 60:
            return 71;
        case 61:
            return 0;
        case 62:
            return 75;
        case 63:
            return 77;
        case 64:
            return 79;
        case 65:
            return 80;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 83;
        case 69:
            return 0;
        case 70:
            return 86;
        case 71:
            return 88;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 90;
        case 75:
            return 92;
        case 76:
            return 94;
        case 77:
            return 96;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 100;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (Desert; 0 the dash, the 00 cell reads 100)
inline int ffoTroDesLo(int b)
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
            return 4;
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
            return 6;
        case 13:
            return 0;
        case 14:
            return 11;
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
            return 14;
        case 24:
            return 16;
        case 25:
            return 17;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 19;
        case 30:
            return 21;
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
            return 23;
        case 38:
            return 0;
        case 39:
            return 25;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 27;
        case 43:
            return 32;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 33;
        case 48:
            return 36;
        case 49:
            return 0;
        case 50:
            return 40;
        case 51:
            return 42;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 45;
        case 56:
            return 46;
        case 57:
            return 50;
        case 58:
            return 58;
        case 59:
            return 65;
        case 60:
            return 78;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 80;
        case 67:
            return 81;
        case 68:
            return 0;
        case 69:
            return 0;
        case 70:
            return 0;
        case 71:
            return 83;
        case 72:
            return 88;
        case 73:
            return 0;
        case 74:
            return 90;
        case 75:
            return 92;
        case 76:
            return 0;
        case 77:
            return 94;
        case 78:
            return 0;
        case 79:
            return 99;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 0;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Desert; 0 the dash)
inline int ffoTroDesHi(int b)
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
            return 3;
        case 6:
            return 5;
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
            return 10;
        case 13:
            return 0;
        case 14:
            return 13;
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
            return 15;
        case 24:
            return 16;
        case 25:
            return 18;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 20;
        case 30:
            return 22;
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
            return 24;
        case 38:
            return 0;
        case 39:
            return 26;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 31;
        case 43:
            return 32;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 35;
        case 48:
            return 39;
        case 49:
            return 0;
        case 50:
            return 41;
        case 51:
            return 44;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 45;
        case 56:
            return 49;
        case 57:
            return 57;
        case 58:
            return 64;
        case 59:
            return 77;
        case 60:
            return 79;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 80;
        case 67:
            return 82;
        case 68:
            return 0;
        case 69:
            return 0;
        case 70:
            return 0;
        case 71:
            return 87;
        case 72:
            return 89;
        case 73:
            return 0;
        case 74:
            return 91;
        case 75:
            return 93;
        case 76:
            return 0;
        case 77:
            return 98;
        case 78:
            return 0;
        case 79:
            return 100;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 0;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 0;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (Hill; 0 the dash, the 00 cell reads 100)
inline int ffoTroHilLo(int b)
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
            return 3;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 7;
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
            return 8;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 11;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 13;
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
            return 14;
        case 40:
            return 0;
        case 41:
            return 22;
        case 42:
            return 26;
        case 43:
            return 30;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 31;
        case 47:
            return 0;
        case 48:
            return 32;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 34;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 40;
        case 55:
            return 0;
        case 56:
            return 42;
        case 57:
            return 47;
        case 58:
            return 49;
        case 59:
            return 55;
        case 60:
            return 63;
        case 61:
            return 0;
        case 62:
            return 68;
        case 63:
            return 74;
        case 64:
            return 75;
        case 65:
            return 78;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 79;
        case 69:
            return 0;
        case 70:
            return 81;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 86;
        case 76:
            return 0;
        case 77:
            return 88;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 90;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 95;
        case 88:
            return 100;
        default:
            return 0;
        }
    }

// The die-high cells (Hill; 0 the dash)
inline int ffoTroHilHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
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
            return 6;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 7;
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
            return 10;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 12;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 13;
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
            return 21;
        case 40:
            return 0;
        case 41:
            return 25;
        case 42:
            return 29;
        case 43:
            return 30;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 31;
        case 47:
            return 0;
        case 48:
            return 33;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 39;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 41;
        case 55:
            return 0;
        case 56:
            return 46;
        case 57:
            return 48;
        case 58:
            return 54;
        case 59:
            return 62;
        case 60:
            return 67;
        case 61:
            return 0;
        case 62:
            return 73;
        case 63:
            return 74;
        case 64:
            return 77;
        case 65:
            return 78;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 80;
        case 69:
            return 0;
        case 70:
            return 85;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 87;
        case 76:
            return 0;
        case 77:
            return 89;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 94;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 99;
        case 88:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountain; 0 the dash, the 00 cell reads 100)
inline int ffoTroMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 3;
        case 6:
            return 0;
        case 7:
            return 6;
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
            return 9;
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
            return 13;
        case 49:
            return 0;
        case 50:
            return 18;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 23;
        case 55:
            return 0;
        case 56:
            return 25;
        case 57:
            return 31;
        case 58:
            return 33;
        case 59:
            return 0;
        case 60:
            return 38;
        case 61:
            return 0;
        case 62:
            return 41;
        case 63:
            return 52;
        case 64:
            return 55;
        case 65:
            return 57;
        case 66:
            return 58;
        case 67:
            return 0;
        case 68:
            return 59;
        case 69:
            return 0;
        case 70:
            return 64;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 74;
        case 75:
            return 0;
        case 76:
            return 0;
        case 77:
            return 78;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 82;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 91;
        case 88:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells (Mountain; 0 the dash)
inline int ffoTroMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 5;
        case 6:
            return 0;
        case 7:
            return 8;
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
            return 12;
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
            return 17;
        case 49:
            return 0;
        case 50:
            return 22;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 24;
        case 55:
            return 0;
        case 56:
            return 30;
        case 57:
            return 32;
        case 58:
            return 37;
        case 59:
            return 0;
        case 60:
            return 40;
        case 61:
            return 0;
        case 62:
            return 51;
        case 63:
            return 54;
        case 64:
            return 56;
        case 65:
            return 57;
        case 66:
            return 58;
        case 67:
            return 0;
        case 68:
            return 63;
        case 69:
            return 0;
        case 70:
            return 73;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 77;
        case 75:
            return 0;
        case 76:
            return 0;
        case 77:
            return 81;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 0;
        case 83:
            return 90;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 98;
        case 88:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Marsh; 0 the dash, the 00 cell reads 100)
inline int ffoTroMshLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 3;
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
            return 4;
        case 11:
            return 12;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 15;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 17;
        case 21:
            return 30;
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
            return 32;
        case 35:
            return 35;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 37;
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
            return 47;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 56;
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
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 62;
        case 63:
            return 0;
        case 64:
            return 74;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 0;
        case 70:
            return 0;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 76;
        case 74:
            return 81;
        case 75:
            return 0;
        case 76:
            return 0;
        case 77:
            return 0;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 86;
        case 81:
            return 0;
        case 82:
            return 89;
        case 83:
            return 0;
        case 84:
            return 0;
        case 85:
            return 91;
        case 86:
            return 97;
        case 87:
            return 0;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Marsh; 0 the dash)
inline int ffoTroMshHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 3;
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
            return 11;
        case 11:
            return 14;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 16;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 29;
        case 21:
            return 31;
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
            return 34;
        case 35:
            return 36;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 46;
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
            return 55;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 61;
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
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 73;
        case 63:
            return 0;
        case 64:
            return 75;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 0;
        case 70:
            return 0;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 80;
        case 74:
            return 85;
        case 75:
            return 0;
        case 76:
            return 0;
        case 77:
            return 0;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 88;
        case 81:
            return 0;
        case 82:
            return 90;
        case 83:
            return 0;
        case 84:
            return 0;
        case 85:
            return 96;
        case 86:
            return 100;
        case 87:
            return 0;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (Shore/Sm.Isle; 0 the dash, the 00 cell reads 100)
inline int ffoTroShrLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
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
            return 0;
        case 18:
            return 5;
        case 19:
            return 12;
        case 20:
            return 19;
        case 21:
            return 32;
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
            return 36;
        case 35:
            return 0;
        case 36:
            return 49;
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
            return 53;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 60;
        case 56:
            return 0;
        case 57:
            return 0;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 67;
        case 62:
            return 71;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 0;
        case 70:
            return 0;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 0;
        case 76:
            return 0;
        case 77:
            return 0;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 93;
        case 83:
            return 0;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 0;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Shore/Sm.Isle; 0 the dash)
inline int ffoTroShrHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 4;
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
            return 0;
        case 18:
            return 11;
        case 19:
            return 18;
        case 20:
            return 31;
        case 21:
            return 35;
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
            return 48;
        case 35:
            return 0;
        case 36:
            return 52;
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
            return 59;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 66;
        case 56:
            return 0;
        case 57:
            return 0;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 70;
        case 62:
            return 92;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 0;
        case 70:
            return 0;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 0;
        case 76:
            return 0;
        case 77:
            return 0;
        case 78:
            return 0;
        case 79:
            return 0;
        case 80:
            return 0;
        case 81:
            return 0;
        case 82:
            return 100;
        case 83:
            return 0;
        case 84:
            return 0;
        case 85:
            return 0;
        case 86:
            return 0;
        case 87:
            return 0;
        case 88:
            return 0;
        default:
            return 0;
        }
    }

// ---- the subtables ----

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoDmiOrd(int b)
    {
        switch (b) {
        case 0:
            return 125;
        case 1:
            return 126;
        case 2:
            return 127;
        case 3:
            return 128;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoDmiSrc(int b)
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

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoDmiPlnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 71;
        case 3:
            return 81;
        default:
            return 0;
        }
    }

// The die-high cells (Plain; 0 the dash)
inline int ffoDmiPlnHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 70;
        case 2:
            return 80;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Scrub; 0 the dash, the 00 cell reads 100)
inline int ffoDmiScrLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 61;
        case 3:
            return 81;
        default:
            return 0;
        }
    }

// The die-high cells (Scrub; 0 the dash)
inline int ffoDmiScrHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 60;
        case 2:
            return 80;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoDmiForLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 71;
        case 3:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoDmiForHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 70;
        case 2:
            return 95;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoDmiRghLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 16;
        case 3:
            return 86;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoDmiRghHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 15;
        case 2:
            return 85;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoDmiHilLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 21;
        case 2:
            return 31;
        case 3:
            return 71;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoDmiHilHi(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 30;
        case 2:
            return 70;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountains; 0 the dash, the 00 cell reads 100)
inline int ffoDmiMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 71;
        case 2:
            return 76;
        case 3:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Mountains; 0 the dash)
inline int ffoDmiMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 70;
        case 1:
            return 75;
        case 2:
            return 95;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoDrgOrd(int b)
    {
        switch (b) {
        case 0:
            return 129;
        case 1:
            return 130;
        case 2:
            return 131;
        case 3:
            return 132;
        case 4:
            return 133;
        case 5:
            return 134;
        case 6:
            return 135;
        case 7:
            return 136;
        case 8:
            return 137;
        case 9:
            return 138;
        case 10:
            return 139;
        case 11:
            return 140;
        case 12:
            return 141;
        case 13:
            return 142;
        case 14:
            return 143;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoDrgSrc(int b)
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
            return 3;
        case 9:
            return 1;
        case 10:
            return 3;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 1;
        default:
            return 0;
        }
    }

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoDrgPlnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 7;
        case 4:
            return 9;
        case 5:
            return 11;
        case 6:
            return 13;
        case 7:
            return 29;
        case 8:
            return 31;
        case 9:
            return 33;
        case 10:
            return 35;
        case 11:
            return 0;
        case 12:
            return 37;
        case 13:
            return 41;
        case 14:
            return 43;
        default:
            return 0;
        }
    }

// The die-high cells (Plain; 0 the dash)
inline int ffoDrgPlnHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 10;
        case 5:
            return 12;
        case 6:
            return 28;
        case 7:
            return 30;
        case 8:
            return 32;
        case 9:
            return 34;
        case 10:
            return 36;
        case 11:
            return 0;
        case 12:
            return 40;
        case 13:
            return 42;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Scrub; 0 the dash, the 00 cell reads 100)
inline int ffoDrgScrLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 7;
        case 4:
            return 9;
        case 5:
            return 11;
        case 6:
            return 15;
        case 7:
            return 17;
        case 8:
            return 37;
        case 9:
            return 39;
        case 10:
            return 41;
        case 11:
            return 0;
        case 12:
            return 43;
        case 13:
            return 46;
        case 14:
            return 48;
        default:
            return 0;
        }
    }

// The die-high cells (Scrub; 0 the dash)
inline int ffoDrgScrHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 10;
        case 5:
            return 14;
        case 6:
            return 16;
        case 7:
            return 36;
        case 8:
            return 38;
        case 9:
            return 40;
        case 10:
            return 42;
        case 11:
            return 0;
        case 12:
            return 45;
        case 13:
            return 47;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoDrgForLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 17;
        case 2:
            return 19;
        case 3:
            return 21;
        case 4:
            return 24;
        case 5:
            return 30;
        case 6:
            return 34;
        case 7:
            return 38;
        case 8:
            return 78;
        case 9:
            return 80;
        case 10:
            return 82;
        case 11:
            return 0;
        case 12:
            return 84;
        case 13:
            return 86;
        case 14:
            return 88;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoDrgForHi(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 18;
        case 2:
            return 20;
        case 3:
            return 22;
        case 4:
            return 29;
        case 5:
            return 33;
        case 6:
            return 37;
        case 7:
            return 77;
        case 8:
            return 79;
        case 9:
            return 81;
        case 10:
            return 83;
        case 11:
            return 0;
        case 12:
            return 85;
        case 13:
            return 87;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoDrgRghLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 31;
        case 2:
            return 33;
        case 3:
            return 41;
        case 4:
            return 46;
        case 5:
            return 51;
        case 6:
            return 56;
        case 7:
            return 58;
        case 8:
            return 60;
        case 9:
            return 62;
        case 10:
            return 67;
        case 11:
            return 0;
        case 12:
            return 69;
        case 13:
            return 72;
        case 14:
            return 74;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoDrgRghHi(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 32;
        case 2:
            return 40;
        case 3:
            return 45;
        case 4:
            return 50;
        case 5:
            return 55;
        case 6:
            return 57;
        case 7:
            return 59;
        case 8:
            return 61;
        case 9:
            return 66;
        case 10:
            return 68;
        case 11:
            return 0;
        case 12:
            return 71;
        case 13:
            return 73;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Desert; 0 the dash, the 00 cell reads 100)
inline int ffoDrgDesLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 21;
        case 3:
            return 65;
        case 4:
            return 67;
        case 5:
            return 69;
        case 6:
            return 78;
        case 7:
            return 80;
        case 8:
            return 82;
        case 9:
            return 84;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 88;
        case 13:
            return 90;
        case 14:
            return 92;
        default:
            return 0;
        }
    }

// The die-high cells (Desert; 0 the dash)
inline int ffoDrgDesHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 20;
        case 2:
            return 64;
        case 3:
            return 66;
        case 4:
            return 68;
        case 5:
            return 77;
        case 6:
            return 79;
        case 7:
            return 81;
        case 8:
            return 83;
        case 9:
            return 87;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 89;
        case 13:
            return 91;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoDrgHilLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 7;
        case 2:
            return 11;
        case 3:
            return 21;
        case 4:
            return 26;
        case 5:
            return 36;
        case 6:
            return 46;
        case 7:
            return 51;
        case 8:
            return 53;
        case 9:
            return 55;
        case 10:
            return 63;
        case 11:
            return 0;
        case 12:
            return 65;
        case 13:
            return 69;
        case 14:
            return 71;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoDrgHilHi(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 25;
        case 4:
            return 35;
        case 5:
            return 45;
        case 6:
            return 50;
        case 7:
            return 52;
        case 8:
            return 54;
        case 9:
            return 62;
        case 10:
            return 64;
        case 11:
            return 0;
        case 12:
            return 68;
        case 13:
            return 70;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountains; 0 the dash, the 00 cell reads 100)
inline int ffoDrgMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 16;
        case 3:
            return 18;
        case 4:
            return 26;
        case 5:
            return 31;
        case 6:
            return 41;
        case 7:
            return 46;
        case 8:
            return 48;
        case 9:
            return 50;
        case 10:
            return 67;
        case 11:
            return 69;
        case 12:
            return 74;
        case 13:
            return 79;
        case 14:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Mountains; 0 the dash)
inline int ffoDrgMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 15;
        case 2:
            return 17;
        case 3:
            return 25;
        case 4:
            return 30;
        case 5:
            return 40;
        case 6:
            return 45;
        case 7:
            return 47;
        case 8:
            return 49;
        case 9:
            return 66;
        case 10:
            return 68;
        case 11:
            return 73;
        case 12:
            return 78;
        case 13:
            return 95;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Marsh; 0 the dash, the 00 cell reads 100)
inline int ffoDrgMshLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 41;
        case 2:
            return 43;
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
            return 61;
        case 9:
            return 76;
        case 10:
            return 78;
        case 11:
            return 0;
        case 12:
            return 82;
        case 13:
            return 84;
        case 14:
            return 86;
        default:
            return 0;
        }
    }

// The die-high cells (Marsh; 0 the dash)
inline int ffoDrgMshHi(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 42;
        case 2:
            return 44;
        case 3:
            return 46;
        case 4:
            return 48;
        case 5:
            return 50;
        case 6:
            return 52;
        case 7:
            return 60;
        case 8:
            return 75;
        case 9:
            return 77;
        case 10:
            return 81;
        case 11:
            return 0;
        case 12:
            return 83;
        case 13:
            return 85;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoFrgOrd(int b)
    {
        switch (b) {
        case 0:
            return 144;
        case 1:
            return 145;
        case 2:
            return 146;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoFrgSrc(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return 0;
        }
    }

// The die-low cells (Marsh; 0 the dash, the 00 cell reads 100)
inline int ffoFrgMshLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 71;
        case 2:
            return 81;
        default:
            return 0;
        }
    }

// The die-high cells (Marsh; 0 the dash)
inline int ffoFrgMshHi(int b)
    {
        switch (b) {
        case 0:
            return 70;
        case 1:
            return 80;
        case 2:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoGntOrd(int b)
    {
        switch (b) {
        case 0:
            return 147;
        case 1:
            return 148;
        case 2:
            return 149;
        case 3:
            return 150;
        case 4:
            return 151;
        case 5:
            return 152;
        case 6:
            return 153;
        case 7:
            return 154;
        case 8:
            return 155;
        case 9:
            return 156;
        case 10:
            return 157;
        case 11:
            return 158;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoGntSrc(int b)
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
            return 1;
        case 5:
            return 1;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 3;
        case 11:
            return 3;
        default:
            return 0;
        }
    }

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoGntPlnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 7;
        case 4:
            return 9;
        case 5:
            return 11;
        case 6:
            return 81;
        case 7:
            return 83;
        case 8:
            return 86;
        case 9:
            return 87;
        case 10:
            return 88;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// The die-high cells (Plain; 0 the dash)
inline int ffoGntPlnHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 10;
        case 5:
            return 80;
        case 6:
            return 82;
        case 7:
            return 85;
        case 8:
            return 86;
        case 9:
            return 87;
        case 10:
            return 99;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Scrub; 0 the dash, the 00 cell reads 100)
inline int ffoGntScrLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 10;
        case 5:
            return 12;
        case 6:
            return 81;
        case 7:
            return 83;
        case 8:
            return 87;
        case 9:
            return 88;
        case 10:
            return 89;
        case 11:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells (Scrub; 0 the dash)
inline int ffoGntScrHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 7;
        case 3:
            return 9;
        case 4:
            return 11;
        case 5:
            return 80;
        case 6:
            return 82;
        case 7:
            return 86;
        case 8:
            return 87;
        case 9:
            return 88;
        case 10:
            return 98;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoGntForLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 10;
        case 3:
            return 12;
        case 4:
            return 21;
        case 5:
            return 23;
        case 6:
            return 82;
        case 7:
            return 84;
        case 8:
            return 89;
        case 9:
            return 90;
        case 10:
            return 91;
        case 11:
            return 98;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoGntForHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 9;
        case 2:
            return 11;
        case 3:
            return 20;
        case 4:
            return 22;
        case 5:
            return 81;
        case 6:
            return 83;
        case 7:
            return 88;
        case 8:
            return 89;
        case 9:
            return 90;
        case 10:
            return 97;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoGntRghLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 10;
        case 3:
            return 19;
        case 4:
            return 21;
        case 5:
            return 25;
        case 6:
            return 75;
        case 7:
            return 77;
        case 8:
            return 89;
        case 9:
            return 90;
        case 10:
            return 91;
        case 11:
            return 98;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoGntRghHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 9;
        case 2:
            return 18;
        case 3:
            return 20;
        case 4:
            return 24;
        case 5:
            return 74;
        case 6:
            return 76;
        case 7:
            return 88;
        case 8:
            return 89;
        case 9:
            return 90;
        case 10:
            return 97;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoGntHilLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 11;
        case 3:
            return 16;
        case 4:
            return 18;
        case 5:
            return 22;
        case 6:
            return 73;
        case 7:
            return 76;
        case 8:
            return 89;
        case 9:
            return 90;
        case 10:
            return 91;
        case 11:
            return 98;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoGntHilHi(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 17;
        case 4:
            return 21;
        case 5:
            return 72;
        case 6:
            return 75;
        case 7:
            return 88;
        case 8:
            return 89;
        case 9:
            return 90;
        case 10:
            return 97;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountains; 0 the dash, the 00 cell reads 100)
inline int ffoGntMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 15;
        case 2:
            return 20;
        case 3:
            return 30;
        case 4:
            return 32;
        case 5:
            return 44;
        case 6:
            return 49;
        case 7:
            return 60;
        case 8:
            return 89;
        case 9:
            return 96;
        case 10:
            return 98;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// The die-high cells (Mountains; 0 the dash)
inline int ffoGntMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 19;
        case 2:
            return 29;
        case 3:
            return 31;
        case 4:
            return 43;
        case 5:
            return 48;
        case 6:
            return 59;
        case 7:
            return 88;
        case 8:
            return 95;
        case 9:
            return 97;
        case 10:
            return 99;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Marsh; 0 the dash, the 00 cell reads 100)
inline int ffoGntMshLo(int b)
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
            return 36;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Marsh; 0 the dash)
inline int ffoGntMshHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 35;
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
            return 100;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoHumOrd(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 159;
        case 2:
            return 160;
        case 3:
            return 161;
        case 4:
            return 162;
        case 5:
            return 163;
        case 6:
            return 164;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoHumSrc(int b)
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
            return 3;
        case 6:
            return 3;
        default:
            return 0;
        }
    }

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoHumPlnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 0;
        case 4:
            return 16;
        case 5:
            return 95;
        case 6:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Plain; 0 the dash)
inline int ffoHumPlnHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 0;
        case 4:
            return 94;
        case 5:
            return 95;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Scrub; 0 the dash, the 00 cell reads 100)
inline int ffoHumScrLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 16;
        case 3:
            return 49;
        case 4:
            return 78;
        case 5:
            return 98;
        case 6:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells (Scrub; 0 the dash)
inline int ffoHumScrHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 15;
        case 2:
            return 48;
        case 3:
            return 77;
        case 4:
            return 97;
        case 5:
            return 98;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoHumForLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 10;
        case 2:
            return 19;
        case 3:
            return 28;
        case 4:
            return 75;
        case 5:
            return 95;
        case 6:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoHumForHi(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 18;
        case 2:
            return 27;
        case 3:
            return 74;
        case 4:
            return 94;
        case 5:
            return 95;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoHumRghLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 19;
        case 2:
            return 29;
        case 3:
            return 47;
        case 4:
            return 51;
        case 5:
            return 85;
        case 6:
            return 86;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoHumRghHi(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 28;
        case 2:
            return 46;
        case 3:
            return 50;
        case 4:
            return 84;
        case 5:
            return 85;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoHumHilLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 22;
        case 2:
            return 43;
        case 3:
            return 0;
        case 4:
            return 64;
        case 5:
            return 85;
        case 6:
            return 86;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoHumHilHi(int b)
    {
        switch (b) {
        case 0:
            return 21;
        case 1:
            return 42;
        case 2:
            return 63;
        case 3:
            return 0;
        case 4:
            return 84;
        case 5:
            return 85;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountains; 0 the dash, the 00 cell reads 100)
inline int ffoHumMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 15;
        case 2:
            return 47;
        case 3:
            return 0;
        case 4:
            return 61;
        case 5:
            return 91;
        case 6:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Mountains; 0 the dash)
inline int ffoHumMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 46;
        case 2:
            return 60;
        case 3:
            return 0;
        case 4:
            return 90;
        case 5:
            return 95;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Marsh; 0 the dash, the 00 cell reads 100)
inline int ffoHumMshLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 24;
        case 2:
            return 34;
        case 3:
            return 0;
        case 4:
            return 72;
        case 5:
            return 95;
        case 6:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Marsh; 0 the dash)
inline int ffoHumMshHi(int b)
    {
        switch (b) {
        case 0:
            return 23;
        case 1:
            return 33;
        case 2:
            return 71;
        case 3:
            return 0;
        case 4:
            return 94;
        case 5:
            return 95;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoLycOrd(int b)
    {
        switch (b) {
        case 0:
            return 165;
        case 1:
            return 166;
        case 2:
            return 167;
        case 3:
            return 168;
        case 4:
            return 169;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoLycSrc(int b)
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
        default:
            return 0;
        }
    }

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoLycPlnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 26;
        case 3:
            return 31;
        case 4:
            return 41;
        default:
            return 0;
        }
    }

// The die-high cells (Plain; 0 the dash)
inline int ffoLycPlnHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 25;
        case 2:
            return 30;
        case 3:
            return 40;
        case 4:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoLycForLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 0;
        case 3:
            return 71;
        case 4:
            return 91;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoLycForHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 70;
        case 2:
            return 0;
        case 3:
            return 90;
        case 4:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoLycRghLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 16;
        case 3:
            return 0;
        case 4:
            return 91;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoLycRghHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 15;
        case 2:
            return 90;
        case 3:
            return 0;
        case 4:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoLycHilLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 16;
        case 3:
            return 21;
        case 4:
            return 31;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoLycHilHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 15;
        case 2:
            return 20;
        case 3:
            return 30;
        case 4:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountains; 0 the dash, the 00 cell reads 100)
inline int ffoLycMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 76;
        case 3:
            return 81;
        case 4:
            return 91;
        default:
            return 0;
        }
    }

// The die-high cells (Mountains; 0 the dash)
inline int ffoLycMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 0;
        case 2:
            return 80;
        case 3:
            return 90;
        case 4:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoMenOrd(int b)
    {
        switch (b) {
        case 0:
            return 170;
        case 1:
            return 171;
        case 2:
            return 172;
        case 3:
            return 173;
        case 4:
            return 174;
        case 5:
            return 175;
        case 6:
            return 176;
        case 7:
            return 177;
        case 8:
            return 178;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoMenSrc(int b)
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
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 1;
        case 8:
            return 1;
        default:
            return 0;
        }
    }

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoMenPlnLo(int b)
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
            return 21;
        case 5:
            return 23;
        case 6:
            return 61;
        case 7:
            return 91;
        case 8:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Plain; 0 the dash)
inline int ffoMenPlnHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 7;
        case 2:
            return 10;
        case 3:
            return 20;
        case 4:
            return 22;
        case 5:
            return 60;
        case 6:
            return 90;
        case 7:
            return 95;
        case 8:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Scrub; 0 the dash, the 00 cell reads 100)
inline int ffoMenScrLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 13;
        case 3:
            return 16;
        case 4:
            return 26;
        case 5:
            return 28;
        case 6:
            return 61;
        case 7:
            return 81;
        case 8:
            return 86;
        default:
            return 0;
        }
    }

// The die-high cells (Scrub; 0 the dash)
inline int ffoMenScrHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 12;
        case 2:
            return 15;
        case 3:
            return 25;
        case 4:
            return 27;
        case 5:
            return 60;
        case 6:
            return 80;
        case 7:
            return 85;
        case 8:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoMenForLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 11;
        case 3:
            return 16;
        case 4:
            return 0;
        case 5:
            return 26;
        case 6:
            return 0;
        case 7:
            return 41;
        case 8:
            return 46;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoMenForHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 0;
        case 2:
            return 15;
        case 3:
            return 25;
        case 4:
            return 0;
        case 5:
            return 40;
        case 6:
            return 0;
        case 7:
            return 45;
        case 8:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoMenRghLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 13;
        case 3:
            return 16;
        case 4:
            return 26;
        case 5:
            return 28;
        case 6:
            return 51;
        case 7:
            return 61;
        case 8:
            return 81;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoMenRghHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 12;
        case 2:
            return 15;
        case 3:
            return 25;
        case 4:
            return 27;
        case 5:
            return 50;
        case 6:
            return 60;
        case 7:
            return 80;
        case 8:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Desert; 0 the dash, the 00 cell reads 100)
inline int ffoMenDesLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 6;
        case 3:
            return 11;
        case 4:
            return 21;
        case 5:
            return 51;
        case 6:
            return 76;
        case 7:
            return 96;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Desert; 0 the dash)
inline int ffoMenDesHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 0;
        case 2:
            return 10;
        case 3:
            return 20;
        case 4:
            return 50;
        case 5:
            return 75;
        case 6:
            return 95;
        case 7:
            return 100;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoMenHilLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 13;
        case 3:
            return 21;
        case 4:
            return 31;
        case 5:
            return 41;
        case 6:
            return 66;
        case 7:
            return 81;
        case 8:
            return 91;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoMenHilHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 12;
        case 2:
            return 20;
        case 3:
            return 30;
        case 4:
            return 40;
        case 5:
            return 65;
        case 6:
            return 80;
        case 7:
            return 90;
        case 8:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountains; 0 the dash, the 00 cell reads 100)
inline int ffoMenMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 21;
        case 4:
            return 31;
        case 5:
            return 36;
        case 6:
            return 0;
        case 7:
            return 51;
        case 8:
            return 66;
        default:
            return 0;
        }
    }

// The die-high cells (Mountains; 0 the dash)
inline int ffoMenMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 30;
        case 4:
            return 35;
        case 5:
            return 50;
        case 6:
            return 0;
        case 7:
            return 65;
        case 8:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Marsh; 0 the dash, the 00 cell reads 100)
inline int ffoMenMshLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 6;
        case 3:
            return 11;
        case 4:
            return 0;
        case 5:
            return 21;
        case 6:
            return 36;
        case 7:
            return 0;
        case 8:
            return 51;
        default:
            return 0;
        }
    }

// The die-high cells (Marsh; 0 the dash)
inline int ffoMenMshHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 0;
        case 2:
            return 10;
        case 3:
            return 20;
        case 4:
            return 0;
        case 5:
            return 35;
        case 6:
            return 50;
        case 7:
            return 0;
        case 8:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoSnkOrd(int b)
    {
        switch (b) {
        case 0:
            return 179;
        case 1:
            return 180;
        case 2:
            return 181;
        case 3:
            return 182;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoSnkSrc(int b)
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

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoSnkPlnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 11;
        case 3:
            return 81;
        default:
            return 0;
        }
    }

// The die-high cells (Plain; 0 the dash)
inline int ffoSnkPlnHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 0;
        case 2:
            return 80;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Scrub; 0 the dash, the 00 cell reads 100)
inline int ffoSnkScrLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 81;
        default:
            return 0;
        }
    }

// The die-high cells (Scrub; 0 the dash)
inline int ffoSnkScrHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 80;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoSnkForLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 66;
        case 3:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoSnkForHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 65;
        case 2:
            return 95;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoSnkRghLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 6;
        case 3:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoSnkRghHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 95;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Desert; 0 the dash, the 00 cell reads 100)
inline int ffoSnkDesLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 16;
        case 3:
            return 91;
        default:
            return 0;
        }
    }

// The die-high cells (Desert; 0 the dash)
inline int ffoSnkDesHi(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 0;
        case 2:
            return 90;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoSnkHilLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 91;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoSnkHilHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 90;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountains; 0 the dash, the 00 cell reads 100)
inline int ffoSnkMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 91;
        default:
            return 0;
        }
    }

// The die-high cells (Mountains; 0 the dash)
inline int ffoSnkMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 90;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Marsh; 0 the dash, the 00 cell reads 100)
inline int ffoSnkMshLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 71;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Marsh; 0 the dash)
inline int ffoSnkMshHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 70;
        case 2:
            return 100;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoSpxOrd(int b)
    {
        switch (b) {
        case 0:
            return 183;
        case 1:
            return 184;
        case 2:
            return 185;
        case 3:
            return 186;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoSpxSrc(int b)
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

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoSpxForLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 76;
        case 3:
            return 81;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoSpxForHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 75;
        case 2:
            return 80;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoSpxRghLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 31;
        case 3:
            return 51;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoSpxRghHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 30;
        case 2:
            return 50;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Desert; 0 the dash, the 00 cell reads 100)
inline int ffoSpxDesLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 41;
        case 2:
            return 51;
        case 3:
            return 91;
        default:
            return 0;
        }
    }

// The die-high cells (Desert; 0 the dash)
inline int ffoSpxDesHi(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 50;
        case 2:
            return 90;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoSpxHilLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 71;
        case 3:
            return 81;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoSpxHilHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 70;
        case 2:
            return 80;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountains; 0 the dash, the 00 cell reads 100)
inline int ffoSpxMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 16;
        case 2:
            return 36;
        case 3:
            return 56;
        default:
            return 0;
        }
    }

// The die-high cells (Mountains; 0 the dash)
inline int ffoSpxMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 35;
        case 2:
            return 55;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Marsh; 0 the dash, the 00 cell reads 100)
inline int ffoSpxMshLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 56;
        case 3:
            return 66;
        default:
            return 0;
        }
    }

// The die-high cells (Marsh; 0 the dash)
inline int ffoSpxMshHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 55;
        case 2:
            return 65;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoSpiOrd(int b)
    {
        switch (b) {
        case 0:
            return 187;
        case 1:
            return 188;
        case 2:
            return 189;
        case 3:
            return 190;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoSpiSrc(int b)
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

// The die-low cells (Plain; 0 the dash, the 00 cell reads 100)
inline int ffoSpiPlnLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 16;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Plain; 0 the dash)
inline int ffoSpiPlnHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 15;
        case 2:
            return 100;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (Scrub; 0 the dash, the 00 cell reads 100)
inline int ffoSpiScrLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 26;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Scrub; 0 the dash)
inline int ffoSpiScrHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 25;
        case 2:
            return 100;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoSpiForLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 56;
        case 2:
            return 76;
        case 3:
            return 81;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoSpiForHi(int b)
    {
        switch (b) {
        case 0:
            return 55;
        case 1:
            return 75;
        case 2:
            return 80;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoSpiRghLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 21;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoSpiRghHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 20;
        case 2:
            return 100;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (Desert; 0 the dash, the 00 cell reads 100)
inline int ffoSpiDesLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Desert; 0 the dash)
inline int ffoSpiDesHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 100;
        case 2:
            return 0;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoSpiHilLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 21;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoSpiHilHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 20;
        case 2:
            return 100;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The roster cells (the round-roster ordinal, first appearance across the
// tables)
inline int ffoUndOrd(int b)
    {
        switch (b) {
        case 0:
            return 191;
        case 1:
            return 192;
        case 2:
            return 193;
        case 3:
            return 194;
        case 4:
            return 195;
        case 5:
            return 196;
        case 6:
            return 197;
        case 7:
            return 198;
        case 8:
            return 199;
        case 9:
            return 200;
        case 10:
            return 201;
        case 11:
            return 202;
        case 12:
            return 203;
        case 13:
            return 204;
        case 14:
            return 205;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoUndSrc(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
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
            return 1;
        case 8:
            return 3;
        case 9:
            return 1;
        case 10:
            return 3;
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

// The die-low cells (Forest; 0 the dash, the 00 cell reads 100)
inline int ffoUndForLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 8;
        case 3:
            return 20;
        case 4:
            return 22;
        case 5:
            return 53;
        case 6:
            return 55;
        case 7:
            return 0;
        case 8:
            return 56;
        case 9:
            return 61;
        case 10:
            return 74;
        case 11:
            return 77;
        case 12:
            return 85;
        case 13:
            return 91;
        case 14:
            return 98;
        default:
            return 0;
        }
    }

// The die-high cells (Forest; 0 the dash)
inline int ffoUndForHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 7;
        case 2:
            return 19;
        case 3:
            return 21;
        case 4:
            return 52;
        case 5:
            return 54;
        case 6:
            return 55;
        case 7:
            return 0;
        case 8:
            return 60;
        case 9:
            return 73;
        case 10:
            return 76;
        case 11:
            return 84;
        case 12:
            return 90;
        case 13:
            return 97;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Rough; 0 the dash, the 00 cell reads 100)
inline int ffoUndRghLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 7;
        case 3:
            return 20;
        case 4:
            return 23;
        case 5:
            return 54;
        case 6:
            return 57;
        case 7:
            return 60;
        case 8:
            return 68;
        case 9:
            return 73;
        case 10:
            return 83;
        case 11:
            return 85;
        case 12:
            return 88;
        case 13:
            return 90;
        case 14:
            return 99;
        default:
            return 0;
        }
    }

// The die-high cells (Rough; 0 the dash)
inline int ffoUndRghHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 6;
        case 2:
            return 19;
        case 3:
            return 22;
        case 4:
            return 53;
        case 5:
            return 56;
        case 6:
            return 59;
        case 7:
            return 67;
        case 8:
            return 72;
        case 9:
            return 82;
        case 10:
            return 84;
        case 11:
            return 87;
        case 12:
            return 89;
        case 13:
            return 98;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Hills; 0 the dash, the 00 cell reads 100)
inline int ffoUndHilLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 7;
        case 3:
            return 17;
        case 4:
            return 19;
        case 5:
            return 39;
        case 6:
            return 41;
        case 7:
            return 44;
        case 8:
            return 59;
        case 9:
            return 64;
        case 10:
            return 69;
        case 11:
            return 71;
        case 12:
            return 73;
        case 13:
            return 81;
        case 14:
            return 98;
        default:
            return 0;
        }
    }

// The die-high cells (Hills; 0 the dash)
inline int ffoUndHilHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 6;
        case 2:
            return 16;
        case 3:
            return 18;
        case 4:
            return 38;
        case 5:
            return 40;
        case 6:
            return 43;
        case 7:
            return 58;
        case 8:
            return 63;
        case 9:
            return 68;
        case 10:
            return 70;
        case 11:
            return 72;
        case 12:
            return 80;
        case 13:
            return 97;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Mountains; 0 the dash, the 00 cell reads 100)
inline int ffoUndMtnLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 7;
        case 3:
            return 17;
        case 4:
            return 19;
        case 5:
            return 0;
        case 6:
            return 34;
        case 7:
            return 37;
        case 8:
            return 42;
        case 9:
            return 47;
        case 10:
            return 57;
        case 11:
            return 59;
        case 12:
            return 69;
        case 13:
            return 80;
        case 14:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Mountains; 0 the dash)
inline int ffoUndMtnHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 6;
        case 2:
            return 16;
        case 3:
            return 18;
        case 4:
            return 33;
        case 5:
            return 0;
        case 6:
            return 36;
        case 7:
            return 41;
        case 8:
            return 46;
        case 9:
            return 56;
        case 10:
            return 58;
        case 11:
            return 68;
        case 12:
            return 79;
        case 13:
            return 95;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The die-low cells (Marsh; 0 the dash, the 00 cell reads 100)
inline int ffoUndMshLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 7;
        case 3:
            return 20;
        case 4:
            return 22;
        case 5:
            return 64;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 72;
        case 9:
            return 77;
        case 10:
            return 82;
        case 11:
            return 85;
        case 12:
            return 94;
        case 13:
            return 0;
        case 14:
            return 96;
        default:
            return 0;
        }
    }

// The die-high cells (Marsh; 0 the dash)
inline int ffoUndMshHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 6;
        case 2:
            return 19;
        case 3:
            return 21;
        case 4:
            return 63;
        case 5:
            return 71;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 76;
        case 9:
            return 81;
        case 10:
            return 84;
        case 11:
            return 93;
        case 12:
            return 95;
        case 13:
            return 0;
        case 14:
            return 100;
        default:
            return 0;
        }
    }

// The roster cells (the first appearance across the tables)
inline int ffoTrxOrd(int b)
    {
        switch (b) {
        case 0:
            return 183;
        case 1:
            return 184;
        case 2:
            return 185;
        case 3:
            return 186;
        default:
            return 0;
        }
    }

// The source cells (1 MM1)
inline int ffoTrxSrc(int b)
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

// The die-low cells
inline int ffoTrxLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 41;
        case 3:
            return 71;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffoTrxHi(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 40;
        case 2:
            return 70;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// ---- the plane tables and the class table ----

// The roster cells (the first creature of the row)
inline int ffoAstOrd(int b)
    {
        switch (b) {
        case 0:
            return 311;
        case 1:
            return 231;
        case 2:
            return 236;
        case 3:
            return 313;
        case 4:
            return 314;
        case 5:
            return 315;
        case 6:
            return 316;
        case 7:
            return 317;
        case 8:
            return 318;
        case 9:
            return 319;
        case 10:
            return 320;
        case 11:
            return 321;
        case 12:
            return 322;
        case 13:
            return 323;
        case 14:
            return 324;
        case 15:
            return 325;
        case 16:
            return 326;
        case 17:
            return 327;
        case 18:
            return 328;
        case 19:
            return 295;
        case 20:
            return 329;
        case 21:
            return 330;
        case 22:
            return 331;
        case 23:
            return 332;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoAstSrc(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
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
            return 1;
        case 10:
            return 1;
        case 11:
            return 4;
        case 12:
            return 0;
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
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        default:
            return 0;
        }
    }

// The die-low cells (the 00 cell reads 100)
inline int ffoAstLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 11;
        case 3:
            return 14;
        case 4:
            return 17;
        case 5:
            return 23;
        case 6:
            return 24;
        case 7:
            return 25;
        case 8:
            return 29;
        case 9:
            return 38;
        case 10:
            return 39;
        case 11:
            return 40;
        case 12:
            return 42;
        case 13:
            return 47;
        case 14:
            return 50;
        case 15:
            return 56;
        case 16:
            return 62;
        case 17:
            return 64;
        case 18:
            return 72;
        case 19:
            return 75;
        case 20:
            return 80;
        case 21:
            return 92;
        case 22:
            return 93;
        case 23:
            return 98;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffoAstHi(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 10;
        case 2:
            return 13;
        case 3:
            return 16;
        case 4:
            return 22;
        case 5:
            return 23;
        case 6:
            return 24;
        case 7:
            return 28;
        case 8:
            return 37;
        case 9:
            return 38;
        case 10:
            return 39;
        case 11:
            return 41;
        case 12:
            return 46;
        case 13:
            return 49;
        case 14:
            return 55;
        case 15:
            return 61;
        case 16:
            return 63;
        case 17:
            return 71;
        case 18:
            return 74;
        case 19:
            return 79;
        case 20:
            return 91;
        case 21:
            return 92;
        case 22:
            return 97;
        case 23:
            return 100;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the routing rows)
inline int ffoAstNumLo(int b)
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
        case 12:
            return 0;
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
        default:
            return 0;
        }
    }

// The number-encountered high cells (0 the routing rows)
inline int ffoAstNumHi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
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
            return 3;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 2;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 3;
        case 20:
            return 5;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 a creature row, 1 the slash pair, 2 the Human Subtable
// routing)
inline int ffoAstSp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
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
            return 2;
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
        default:
            return 0;
        }
    }

// The roster cells (the first creature of the row)
inline int ffoEthOrd(int b)
    {
        switch (b) {
        case 0:
            return 311;
        case 1:
            return 231;
        case 2:
            return 236;
        case 3:
            return 265;
        case 4:
            return 334;
        case 5:
            return 319;
        case 6:
            return 320;
        case 7:
            return 335;
        case 8:
            return 336;
        case 9:
            return 337;
        case 10:
            return 338;
        case 11:
            return 339;
        case 12:
            return 194;
        case 13:
            return 240;
        case 14:
            return 211;
        case 15:
            return 322;
        case 16:
            return 323;
        case 17:
            return 324;
        case 18:
            return 325;
        case 19:
            return 340;
        case 20:
            return 326;
        case 21:
            return 328;
        case 22:
            return 342;
        case 23:
            return 343;
        case 24:
            return 344;
        case 25:
            return 345;
        case 26:
            return 310;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows, 1 MM1, 2 MM2, 3 FF, 4 the unkeyed
// rows)
inline int ffoEthSrc(int b)
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
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 0;
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
        default:
            return 0;
        }
    }

// The die-low cells (the 00 cell reads 100)
inline int ffoEthLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 14;
        case 4:
            return 19;
        case 5:
            return 27;
        case 6:
            return 28;
        case 7:
            return 29;
        case 8:
            return 31;
        case 9:
            return 38;
        case 10:
            return 40;
        case 11:
            return 42;
        case 12:
            return 43;
        case 13:
            return 49;
        case 14:
            return 51;
        case 15:
            return 53;
        case 16:
            return 58;
        case 17:
            return 60;
        case 18:
            return 63;
        case 19:
            return 69;
        case 20:
            return 77;
        case 21:
            return 79;
        case 22:
            return 81;
        case 23:
            return 83;
        case 24:
            return 88;
        case 25:
            return 95;
        case 26:
            return 98;
        default:
            return 0;
        }
    }

// The die-high cells
inline int ffoEthHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 13;
        case 3:
            return 18;
        case 4:
            return 26;
        case 5:
            return 27;
        case 6:
            return 28;
        case 7:
            return 30;
        case 8:
            return 37;
        case 9:
            return 39;
        case 10:
            return 41;
        case 11:
            return 42;
        case 12:
            return 48;
        case 13:
            return 50;
        case 14:
            return 52;
        case 15:
            return 57;
        case 16:
            return 59;
        case 17:
            return 62;
        case 18:
            return 68;
        case 19:
            return 76;
        case 20:
            return 78;
        case 21:
            return 80;
        case 22:
            return 82;
        case 23:
            return 87;
        case 24:
            return 94;
        case 25:
            return 97;
        case 26:
            return 100;
        default:
            return 0;
        }
    }

// The number-encountered low cells (0 the routing rows)
inline int ffoEthNumLo(int b)
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
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 2;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 2;
        case 26:
            return 3;
        default:
            return 0;
        }
    }

// The number-encountered high cells (0 the routing rows)
inline int ffoEthNumHi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 6;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 3;
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
            return 2;
        case 14:
            return 2;
        case 15:
            return 0;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 1;
        case 19:
            return 8;
        case 20:
            return 2;
        case 21:
            return 4;
        case 22:
            return 5;
        case 23:
            return 6;
        case 24:
            return 3;
        case 25:
            return 5;
        case 26:
            return 6;
        default:
            return 0;
        }
    }

// The special cells (0 a creature row, 1 the slash pair, 2 the Human Subtable
// routing)
inline int ffoEthSp(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
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
            return 0;
        case 15:
            return 2;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 1;
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
        default:
            return 0;
        }
    }

// The roster cells (the class row ordinal)
inline int ffoClsOrd(int b)
    {
        switch (b) {
        case 0:
            return 346;
        case 1:
            return 347;
        case 2:
            return 348;
        case 3:
            return 349;
        case 4:
            return 350;
        case 5:
            return 351;
        case 6:
            return 352;
        case 7:
            return 353;
        case 8:
            return 354;
        case 9:
            return 355;
        case 10:
            return 356;
        default:
            return 0;
        }
    }

// The source cells (0 the routing rows)
inline int ffoClsSrc(int b)
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

// The level-low cells (the character level range floor)
inline int ffoClsLo(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 7;
        case 2:
            return 8;
        case 3:
            return 7;
        case 4:
            return 7;
        case 5:
            return 11;
        case 6:
            return 10;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 8;
        case 10:
            return 11;
        default:
            return 0;
        }
    }

// The level-high cells (the character level range ceiling)
inline int ffoClsHi(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 14;
        case 2:
            return 15;
        case 3:
            return 16;
        case 4:
            return 16;
        case 5:
            return 20;
        case 6:
            return 17;
        case 7:
            return 16;
        case 8:
            return 15;
        case 9:
            return 17;
        case 10:
            return 18;
        default:
            return 0;
        }
    }

}   // namespace rules
