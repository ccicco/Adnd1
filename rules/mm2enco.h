// =========================================================================================
// Adnd1 - rules/mm2enco.h
// THE MM2 OUTDOOR ENCOUNTER TABLES WALK - THE 36 TERRAIN GRIDS (pp. 140-141+:
// the 6 main areas cold, temperate and tropical, wilderness and civilized,
// each x 6 terrains, the Character Party rows, the Castle/Fortress structure
// rows and the Patrol men rows), the OUTDOOR-FLIP round - the Outdoor Random
// Encounter Tables gap box flips to closed
// census 739 -> 740.
//
// Round twenty-two of the MM2 arc, the fifth table-group round (Curtiss Go
// call on the landed R816 dungeon walk; the pin-time walk found 36 printed
// grids of 19 die rows each, no defs promoted - the registry stays 809)
//
// The pin header stays the print-fidelity record; the grids carry the die,
// editorial source and special cells, the row rosters ride the audit
// comments, and the walk cross-checks the registry keys live
//
namespace rules {

// ---- the R817 census ----

// The MM2 outdoor encounter tables walk round: the 36 terrain grids, the
// fifth table-group round (Curtiss Go call on the landed R816)
inline int mm2encoRound()
    { return 817; }

// The tables cover 6 main areas: cold, temperate and tropical, each in
// wilderness and civilized versions
inline int mm2encoAreaCount()
    { return 6; }

// Each main area subdivides into mountains, hills and rough terrain, forest,
// swamp and marsh, plains and scrub, and desert
inline int mm2encoTerrainCount()
    { return 6; }

// The 6 x 6 terrain grids (one area-terrain pairing per grid)
inline int mm2encoTableCount()
    { return 36; }

// Every grid carries the 19 die rows 2-20
inline int mm2encoRowsPerTable()
    { return 19; }

// The 36 x 19 rows pinned across the grids
inline int mm2encoTotalRows()
    { return 684; }

// The 19 rows of the the cold wilderness mountains encounter grid
inline int mm2encoCW1Count()
    { return 19; }

// The 19 rows of the the cold wilderness hills and rough terrain encounter
// grid
inline int mm2encoCW2Count()
    { return 19; }

// The 19 rows of the the cold wilderness forest encounter grid
inline int mm2encoCW3Count()
    { return 19; }

// The 19 rows of the the cold wilderness swamp and marsh encounter grid
inline int mm2encoCW4Count()
    { return 19; }

// The 19 rows of the the cold wilderness plains and scrub encounter grid
inline int mm2encoCW5Count()
    { return 19; }

// The 19 rows of the the cold wilderness desert encounter grid
inline int mm2encoCW6Count()
    { return 19; }

// The 19 rows of the the cold civilized mountains encounter grid
inline int mm2encoCC1Count()
    { return 19; }

// The 19 rows of the the cold civilized hills and rough terrain encounter
// grid
inline int mm2encoCC2Count()
    { return 19; }

// The 19 rows of the the cold civilized forest encounter grid
inline int mm2encoCC3Count()
    { return 19; }

// The 19 rows of the the cold civilized swamp and marsh encounter grid
inline int mm2encoCC4Count()
    { return 19; }

// The 19 rows of the the cold civilized plains and scrub encounter grid
inline int mm2encoCC5Count()
    { return 19; }

// The 19 rows of the the cold civilized desert encounter grid
inline int mm2encoCC6Count()
    { return 19; }

// The 19 rows of the the temperate wilderness mountains encounter grid
inline int mm2encoTW1Count()
    { return 19; }

// The 19 rows of the the temperate wilderness hills and rough terrain
// encounter grid
inline int mm2encoTW2Count()
    { return 19; }

// The 19 rows of the the temperate wilderness forest encounter grid
inline int mm2encoTW3Count()
    { return 19; }

// The 19 rows of the the temperate wilderness swamp and marsh encounter grid
inline int mm2encoTW4Count()
    { return 19; }

// The 19 rows of the the temperate wilderness plains and scrub encounter grid
inline int mm2encoTW5Count()
    { return 19; }

// The 19 rows of the the temperate wilderness desert encounter grid
inline int mm2encoTW6Count()
    { return 19; }

// The 19 rows of the the temperate civilized mountains encounter grid
inline int mm2encoTC1Count()
    { return 19; }

// The 19 rows of the the temperate civilized hills and rough terrain
// encounter grid
inline int mm2encoTC2Count()
    { return 19; }

// The 19 rows of the the temperate civilized forest encounter grid
inline int mm2encoTC3Count()
    { return 19; }

// The 19 rows of the the temperate civilized swamp and marsh encounter grid
inline int mm2encoTC4Count()
    { return 19; }

// The 19 rows of the the temperate civilized plains and scrub encounter grid
inline int mm2encoTC5Count()
    { return 19; }

// The 19 rows of the the temperate civilized desert encounter grid
inline int mm2encoTC6Count()
    { return 19; }

// The 19 rows of the the tropical wilderness mountains encounter grid
inline int mm2encoRW1Count()
    { return 19; }

// The 19 rows of the the tropical wilderness hills and rough terrain
// encounter grid
inline int mm2encoRW2Count()
    { return 19; }

// The 19 rows of the the tropical wilderness forest encounter grid
inline int mm2encoRW3Count()
    { return 19; }

// The 19 rows of the the tropical wilderness swamp and marsh encounter grid
inline int mm2encoRW4Count()
    { return 19; }

// The 19 rows of the the tropical wilderness plains and scrub encounter grid
inline int mm2encoRW5Count()
    { return 19; }

// The 19 rows of the the tropical wilderness desert encounter grid
inline int mm2encoRW6Count()
    { return 19; }

// The 19 rows of the the tropical civilized mountains encounter grid
inline int mm2encoRC1Count()
    { return 19; }

// The 19 rows of the the tropical civilized hills and rough terrain encounter
// grid
inline int mm2encoRC2Count()
    { return 19; }

// The 19 rows of the the tropical civilized forest encounter grid
inline int mm2encoRC3Count()
    { return 19; }

// The 19 rows of the the tropical civilized swamp and marsh encounter grid
inline int mm2encoRC4Count()
    { return 19; }

// The 19 rows of the the tropical civilized plains and scrub encounter grid
inline int mm2encoRC5Count()
    { return 19; }

// The 19 rows of the the tropical civilized desert encounter grid
inline int mm2encoRC6Count()
    { return 19; }

// The lowest die roll on every grid
inline int mm2encoDieMin()
    { return 2; }

// The highest die roll on every grid
inline int mm2encoDieMax()
    { return 20; }

// The Character Party rows across the grids (the DMG character subtable
// pointer)
inline int mm2encoCharacterPartyRows()
    { return 17; }

// The grids that carry a Character Party row (the cold wilderness hills grid
// the one wild grid with one)
inline int mm2encoGridsWithPartyRow()
    { return 16; }

// The cold civilized desert grid carries TWO Character Party rows (dies 7 and
// 14) - every other party grid exactly one
inline int mm2encoColdCivDesertPartyRows()
    { return 2; }

// The Castle and Fortress rows (the print structure rows, no monster)
inline int mm2encoStructureRows()
    { return 5; }

// The Man, Patrol men-type rows - the print cites no stat block anywhere for
// the patrol (the men rows without defs)
inline int mm2encoPatrolRows()
    { return 15; }

// The MM1-provenance rows (the editorial source cells; the registry lua
// headers the authority)
inline int mm2encoMm1SourceRows()
    { return 413; }

// The MM2-provenance rows (the registry lua headers the authority)
inline int mm2encoMm2SourceRows()
    { return 159; }

// The Fiend Folio rows (the print index F-refs the authority; the registry
// carries no FF defs - the rows ride keyless)
inline int mm2encoFfSourceRows()
    { return 74; }

// The rows with a registry walk key (the MM1 and MM2 defs the
// registry owns; the R820 lammasu promotion rewired the 2
// keyless cells, 570 -> 572; the R836 FF promotion rewired
// 18 more, 572 -> 590)
inline int mm2encoWalkKeyRows()
    { return 590; }

// The one row with no print def determined (the Pterodactyl, Small cell -
// flagged for the physical copy)
inline int mm2encoUnresolvedRows()
    { return 1; }

// The registry census floor (the walk requires at least this many defs
// loaded)
inline int mm2encoRegistryFloor()
    { return 809; }

// The or-rows and cross-referenced variant rows (the first creature keys the
// row, the R816 convention)
inline int mm2encoOrRows()
    { return 20; }

// The Lammasu, Greater cells - the MM2 p. 79 stat block the R808 LMN walk
// never promoted; the cells ride keyless pending that promotion
inline int mm2encoLammasuGreaterRows()
    { return 2; }

// ---- the opening doctrine (the R817 census) ----

// These tables cover 6 main areas
inline bool mm2encoSixMainAreas()
    { return true; }

// The cold wilderness area includes arctic and subarctic regions
inline bool mm2encoColdIncludesArcticSubarctic()
    { return true; }

// The tropical areas include subtropical regions
inline bool mm2encoTropicalIncludesSubtropical()
    { return true; }

// Civilized regions include inhabited and patrolled areas
inline bool mm2encoCivilizedIncludesInhabitedAndPatrolled()
    { return true; }

// Encounters in each terrain are typical to it
inline bool mm2encoEncountersTypicalToTerrain()
    { return true; }

// Feel free to modify or replace these tables, using the suggestions in the
// section on creating tables
inline bool mm2encoDmMayModifyOrReplace()
    { return true; }

// The Character Party row consults the character subtable in the DMG
inline bool mm2encoPartyRowRollsDmgSubtable()
    { return true; }

// The outdoor grids print no source column (unlike the dungeon grids) - the
// source cells are editorial, the print index M/F/bare refs and the registry
// provenance the voices
inline bool mm2encoNoPrintedSourceColumn()
    { return true; }

// The outdoor grids print no number-encountered column (unlike the dungeon
// grids); the number rides the individual monster entries
inline bool mm2encoNoPrintedNumberColumn()
    { return true; }

// Every grid runs the die rows 2-20 contiguous, one row per die
inline bool mm2encoDieRowsContiguous()
    { return true; }

// The Castle and Fortress rows are the print structure rows (an inhabited
// site, not a monster)
inline bool mm2encoStructureRowIsCastleOrFortress()
    { return true; }

// The Patrol rows are men-type encounter rows; no patrol stat block exists in
// the MM1/MM2/FF prints (the cells ride the men row class)
inline bool mm2encoPatrolRowIsMenType()
    { return true; }

// ---- the cold wilderness mountains grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoCW1Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoCW1Src(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
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
            return 0;
        case 16:
            return 2;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoCW1Special(int b)
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
            return 2;
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

// ---- the cold wilderness hills and rough terrain grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoCW2Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoCW2Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 2;
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
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoCW2Special(int b)
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

// ---- the cold wilderness forest grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoCW3Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoCW3Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 1;
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
            return 1;
        case 15:
            return 3;
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

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoCW3Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the cold wilderness swamp and marsh grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoCW4Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoCW4Src(int b)
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
            return 3;
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
            return 2;
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

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoCW4Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the cold wilderness plains and scrub grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoCW5Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoCW5Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
            return 3;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoCW5Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the cold wilderness desert grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoCW6Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoCW6Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 3;
        case 16:
            return 1;
        case 17:
            return 3;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoCW6Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the cold civilized mountains grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoCC1Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoCC1Src(int b)
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
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoCC1Special(int b)
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
            return 0;
        case 16:
            return 2;
        case 17:
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the cold civilized hills and rough terrain grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoCC2Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoCC2Src(int b)
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
            return 2;
        case 6:
            return 1;
        case 7:
            return 1;
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
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoCC2Special(int b)
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
            return 3;
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

// ---- the cold civilized forest grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoCC3Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoCC3Src(int b)
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
            return 1;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 3;
        case 17:
            return 2;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoCC3Special(int b)
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
            return 3;
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
            return 1;
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

// ---- the cold civilized swamp and marsh grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoCC4Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoCC4Src(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 2;
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
            return 2;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 1;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoCC4Special(int b)
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
            return 3;
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the cold civilized plains and scrub grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoCC5Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoCC5Src(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 2;
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
            return 0;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 3;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoCC5Special(int b)
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
            return 3;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
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

// ---- the cold civilized desert grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoCC6Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoCC6Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 2;
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
            return 2;
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
            return 3;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoCC6Special(int b)
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
            return 1;
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

// ---- the temperate wilderness mountains grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoTW1Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoTW1Src(int b)
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
            return 2;
        case 5:
            return 1;
        case 6:
            return 3;
        case 7:
            return 2;
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
        case 16:
            return 1;
        case 17:
            return 3;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoTW1Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the temperate wilderness hills and rough terrain grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoTW2Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoTW2Src(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
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
            return 2;
        case 15:
            return 2;
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

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoTW2Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the temperate wilderness forest grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoTW3Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoTW3Src(int b)
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
            return 1;
        case 15:
            return 2;
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

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoTW3Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the temperate wilderness swamp and marsh grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoTW4Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoTW4Src(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
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
            return 3;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoTW4Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the temperate wilderness plains and scrub grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoTW5Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoTW5Src(int b)
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
            return 3;
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
            return 1;
        case 11:
            return 2;
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
            return 2;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoTW5Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the temperate wilderness desert grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoTW6Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoTW6Src(int b)
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
            return 2;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 1;
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
            return 2;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoTW6Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the temperate civilized mountains grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoTC1Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoTC1Src(int b)
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
            return 0;
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
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoTC1Special(int b)
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
            return 3;
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

// ---- the temperate civilized hills and rough terrain grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoTC2Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoTC2Src(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
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
            return 0;
        case 11:
            return 1;
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
            return 1;
        case 18:
            return 3;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoTC2Special(int b)
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
            return 3;
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

// ---- the temperate civilized forest grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoTC3Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoTC3Src(int b)
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
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
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

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoTC3Special(int b)
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
            return 3;
        case 12:
            return 1;
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

// ---- the temperate civilized swamp and marsh grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoTC4Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoTC4Src(int b)
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
            return 0;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 2;
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

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoTC4Special(int b)
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
            return 3;
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
        default:
            return 0;
        }
    }

// ---- the temperate civilized plains and scrub grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoTC5Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoTC5Src(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 1;
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
            return 2;
        case 11:
            return 0;
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
            return 2;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoTC5Special(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 2;
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
            return 3;
        case 12:
            return 1;
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

// ---- the temperate civilized desert grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoTC6Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoTC6Src(int b)
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
            return 0;
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
            return 2;
        case 15:
            return 2;
        case 16:
            return 3;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoTC6Special(int b)
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
        default:
            return 0;
        }
    }

// ---- the tropical wilderness mountains grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoRW1Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoRW1Src(int b)
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
            return 1;
        case 8:
            return 0;
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
            return 3;
        case 15:
            return 1;
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

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoRW1Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the tropical wilderness hills and rough terrain grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoRW2Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoRW2Src(int b)
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
            return 3;
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
            return 2;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 3;
        case 17:
            return 1;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoRW2Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the tropical wilderness forest grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoRW3Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoRW3Src(int b)
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
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 2;
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

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoRW3Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the tropical wilderness swamp and marsh grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoRW4Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoRW4Src(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 2;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoRW4Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the tropical wilderness plains and scrub grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoRW5Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoRW5Src(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
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
            return 2;
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
            return 1;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoRW5Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the tropical wilderness desert grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoRW6Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoRW6Src(int b)
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
            return 2;
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
            return 1;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 3;
        case 17:
            return 2;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoRW6Special(int b)
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
            return 0;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// ---- the tropical civilized mountains grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoRC1Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoRC1Src(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 1;
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
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoRC1Special(int b)
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
            return 3;
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

// ---- the tropical civilized hills and rough terrain grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoRC2Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoRC2Src(int b)
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
            return 2;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 2;
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

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoRC2Special(int b)
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
            return 3;
        case 11:
            return 0;
        case 12:
            return 1;
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

// ---- the tropical civilized forest grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoRC3Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoRC3Src(int b)
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
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 0;
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
            return 2;
        case 18:
            return 3;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoRC3Special(int b)
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
            return 3;
        case 11:
            return 0;
        case 12:
            return 1;
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

// ---- the tropical civilized swamp and marsh grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoRC4Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoRC4Src(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 1;
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
            return 2;
        case 15:
            return 2;
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

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoRC4Special(int b)
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

// ---- the tropical civilized plains and scrub grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoRC5Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoRC5Src(int b)
    {
        switch (b) {
        case 0:
            return 3;
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
            return 0;
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
            return 3;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoRC5Special(int b)
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
            return 0;
        case 8:
            return 3;
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

// ---- the tropical civilized desert grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encoRC6Die(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the party, structure, patrol and
// unresolved rows)
inline int mm2encoRC6Src(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 3;
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
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
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
            return 2;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 1 the Character Party row, 2 the
// Castle/Fortress structure row, 3 the Patrol men row)
inline int mm2encoRC6Special(int b)
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
        default:
            return 0;
        }
    }

}   // namespace rules
