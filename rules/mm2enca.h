// =========================================================================================
// Adnd1 - rules/mm2enca.h
// THE MM2 AQUATIC ENCOUNTER TABLES WALK - THE 12 SURFACE AND DEPTHS GRIDS
// (print p. 137: the 6 main areas cold, temperate and tropical, each
// freshwater and saltwater, each surface and depths; the 13 hazard rows, the
// 4 pointer rows, the 3 lung dragon cross-refs), the AQUATIC-FLIP round - the
// Aquatic Random Encounter Tables gap box flips to closed
// census 740 -> 741.
//
// Round twenty-three of the MM2 arc, the sixth table-group round (Curtiss Go
// call on the landed R817 outdoor walk; the pin-time walk found 12 printed
// grids of 19 die rows each, no defs promoted - the registry stays 809)
//
// The pin header stays the print-fidelity record; the grids carry the die,
// editorial source and special cells, the row rosters ride the audit
// comments, and the walk cross-checks the registry keys live
//
namespace rules {

// ---- the R818 census ----

// The MM2 aquatic encounter tables walk round: the 12 surface and depths
// grids, the sixth table-group round (Curtiss Go call on the landed R817)
inline int mm2encaRound()
    { return 818; }

// The 6 main areas: cold, temperate and tropical, each freshwater and
// saltwater
inline int mm2encaAreaCount()
    { return 6; }

// Each area splits surface and depths subregions
inline int mm2encaSubregionCount()
    { return 2; }

// The 12 printed grids (6 areas x 2 subregions)
inline int mm2encaTableCount()
    { return 12; }

// Each grid carries 19 die rows
inline int mm2encaRowsPerTable()
    { return 19; }

// The 228 total cells (12 x 19)
inline int mm2encaTotalRows()
    { return 228; }

// The the cold freshwater surface grid die rows
inline int mm2encaCFSCount()
    { return 19; }

// The the cold freshwater depths grid die rows
inline int mm2encaCFDCount()
    { return 19; }

// The the cold saltwater surface grid die rows
inline int mm2encaCSSCount()
    { return 19; }

// The the cold saltwater depths grid die rows
inline int mm2encaCSDCount()
    { return 19; }

// The the temperate freshwater surface grid die rows
inline int mm2encaTFSCount()
    { return 19; }

// The the temperate freshwater depths grid die rows
inline int mm2encaTFDCount()
    { return 19; }

// The the temperate saltwater surface grid die rows
inline int mm2encaTSSCount()
    { return 19; }

// The the temperate saltwater depths grid die rows
inline int mm2encaTSDCount()
    { return 19; }

// The the tropical freshwater surface grid die rows
inline int mm2encaRFSCount()
    { return 19; }

// The the tropical freshwater depths grid die rows
inline int mm2encaRFDCount()
    { return 19; }

// The the tropical saltwater surface grid die rows
inline int mm2encaRSSCount()
    { return 19; }

// The the tropical saltwater depths grid die rows
inline int mm2encaRSDCount()
    { return 19; }

// The first die row
inline int mm2encaDieMin()
    { return 2; }

// The last die row
inline int mm2encaDieMax()
    { return 20; }

// Ice: freshwater hull thickness minimum, feet
inline int mm2encaIceHullMinFresh()
    { return 10; }

// Ice: freshwater hull thickness maximum, feet
inline int mm2encaIceHullMaxFresh()
    { return 16; }

// Ice: saltwater hull thickness minimum, feet
inline int mm2encaIceHullMinSalt()
    { return 10; }

// Ice: saltwater hull thickness maximum, feet
inline int mm2encaIceHullMaxSalt()
    { return 60; }

// Ice: hull damage minimum per round
inline int mm2encaIceDamageMin()
    { return 1; }

// Ice: hull damage maximum per round
inline int mm2encaIceDamageMax()
    { return 6; }

// Icebergs: the hole-in-hull chance, percent
inline int mm2encaIcebergHolePct()
    { return 10; }

// Ice fields: the minimum chance, percent
inline int mm2encaIceFieldMinPct()
    { return 10; }

// Ice fields: the maximum chance, percent
inline int mm2encaIceFieldMaxPct()
    { return 20; }

// Ghost ships: the skeleton crew chance 01-40
inline int mm2encaGhostSkeletonPct()
    { return 40; }

// Ghost ships: the zombie crew chance 41-80
inline int mm2encaGhostZombiePct()
    { return 40; }

// Ghost ships: the juju zombie crew chance 81-00
inline int mm2encaGhostJujuZombiePct()
    { return 20; }

// Ghost ship officers: wights minimum
inline int mm2encaGhostWightMin()
    { return 1; }

// Ghost ship officers: wights maximum
inline int mm2encaGhostWightMax()
    { return 4; }

// Ghost ship officers: wraiths minimum
inline int mm2encaGhostWraithMin()
    { return 1; }

// Ghost ship officers: wraiths maximum
inline int mm2encaGhostWraithMax()
    { return 3; }

// Ghost ship officers: the print gap 41-60 pinned verbatim - the missing row
inline int mm2encaGhostOfficerGapMin()
    { return 41; }

// Ghost ship officers: the print gap 41-60 pinned verbatim - the missing row
inline int mm2encaGhostOfficerGapMax()
    { return 60; }

// Ghost ship officers: spectres minimum
inline int mm2encaGhostSpectreMin()
    { return 1; }

// Ghost ship officers: spectres maximum
inline int mm2encaGhostSpectreMax()
    { return 2; }

// Ghost ship officers: ghosts minimum
inline int mm2encaGhostGhostMin()
    { return 1; }

// Ghost ship officers: ghosts maximum
inline int mm2encaGhostGhostMax()
    { return 2; }

// Ghost ship officers: the one lich
inline int mm2encaGhostLichCount()
    { return 1; }

// Sunken ships: the merchant-with-treasure chance 01-20
inline int mm2encaSunkenMerchantPct()
    { return 20; }

// Sunken ships: the no-treasure overlap 11-20 pinned verbatim (the print
// overlap)
inline int mm2encaSunkenNoTreasureMin()
    { return 11; }

// Sunken ships: the no-treasure overlap 11-20 pinned verbatim (the print
// overlap)
inline int mm2encaSunkenNoTreasureMax()
    { return 20; }

// Sunken ships: the lacedon crew minimum 21-60
inline int mm2encaSunkenLacedonMin()
    { return 2; }

// Sunken ships: the lacedon crew maximum 21-60
inline int mm2encaSunkenLacedonMax()
    { return 24; }

// Floating seaweed: the vessel slow chance, percent
inline int mm2encaSeaweedSlowPct()
    { return 50; }

// Floating seaweed: the encounter chance, percent
inline int mm2encaSeaweedEncounterPct()
    { return 40; }

// Seaweed beds: minimum depth, feet
inline int mm2encaSeaweedBedMinFt()
    { return 30; }

// Seaweed beds: maximum depth, feet
inline int mm2encaSeaweedBedMaxFt()
    { return 300; }

// Seaweed beds: vision inside, feet
inline int mm2encaSeaweedBedVisionFt()
    { return 10; }

// Seaweed beds: the encounter chance, percent
inline int mm2encaSeaweedBedPct()
    { return 30; }

// Islands: the reef chance, percent
inline int mm2encaIslandReefPct()
    { return 10; }

// Islands: the reef hull damage minimum
inline int mm2encaIslandHullMin()
    { return 2; }

// Islands: the reef hull damage maximum
inline int mm2encaIslandHullMax()
    { return 12; }

// Islands: the hole-in-hull chance, percent
inline int mm2encaIslandHolePct()
    { return 20; }

// Whirlpools: the affect-small-craft-only chance, percent
inline int mm2encaWhirlpoolSmallCraftPct()
    { return 75; }

// Whirlpools: the affect-any-vessel chance, percent
inline int mm2encaWhirlpoolAnyPct()
    { return 25; }

// Whirlpools: the small-craft maximum length, feet
inline int mm2encaWhirlpoolCraftMaxFt()
    { return 50; }

// Whirlpools: the rounds to sink at the cumulative 1 inch per round
inline int mm2encaWhirlpoolRoundsToSink()
    { return 6; }

// The hazard rows (Ice x2, Whirlpool x3, Island x2, Ghost Ship x3, Seaweed
// x3)
inline int mm2encaHazardRows()
    { return 13; }

// The pointer rows (Surface Encounter x3, Land Encounter x1)
inline int mm2encaPointerRows()
    { return 4; }

// The MM1-sourced rows
inline int mm2encaMm1SourceRows()
    { return 138; }

// The MM2-sourced rows
inline int mm2encaMm2SourceRows()
    { return 51; }

// The FF-sourced rows (keyless - the registry carries no FF defs)
inline int mm2encaFfSourceRows()
    { return 19; }

// The no-source rows: the hazards, the pointers, the lung dragon cross-refs
inline int mm2encaNoSourceRows()
    { return 20; }

// The keyed rows (the MM1, MM2, and promoted FF defs the
// registry owns; the R821 lung promotion rewired the 3
// keyless lung dragon cells, 189 -> 192)
inline int mm2encaWalkKeyRows()
    { return 192; }

// The oriental lung dragon cross-ref cells (the sea lung wang and the spirit
// shen lung) - the R821 lung promotion keyed them (the FF print defs own
// them, the walk-key census carries the rewire)
inline int mm2encaLungDragonRows()
    { return 3; }

// The or-rows (the R816 first-creature convention)
inline int mm2encaOrRows()
    { return 14; }

// The registry floor (no defs promoted this round)
inline int mm2encaRegistryFloor()
    { return 809; }

// ---- the opening doctrine (the R818 census) ----

// These tables cover the 6 main areas
inline bool mm2encaSixMainAreas()
    { return true; }

// The 6 areas are the 3 climate bands x fresh and salt water
inline bool mm2encaClimateTimesWaterType()
    { return true; }

// Each area carries a surface grid and a depths grid
inline bool mm2encaSurfaceAndDepthsSplit()
    { return true; }

// The aquatic grids print no source column (the source cells are editorial)
inline bool mm2encaNoPrintedSourceColumn()
    { return true; }

// The aquatic grids print no number-encountered column
inline bool mm2encaNoPrintedNumberColumn()
    { return true; }

// The die rows run 2-20 contiguous, one row per die
inline bool mm2encaDieRowsContiguous()
    { return true; }

// The hazard rows cite no monster stat block (ice, whirlpool, island, ghost
// ship, sunken ship, seaweed)
inline bool mm2encaHazardRowHasNoMonsterStat()
    { return true; }

// The pointer rows route to the surface table or the land tables
inline bool mm2encaPointerRowRoutesToAnotherTable()
    { return true; }

// Ice may block the passage or hole the hull
inline bool mm2encaIceMayBlockOrDamageVessels()
    { return true; }

// The ghost ship crew rolls on the undead subtables
inline bool mm2encaGhostShipCrewIsUndead()
    { return true; }

// Sunken ships roll 61-00 on the main encounter chart
inline bool mm2encaSunkenShipsRollOnMainChart()
    { return true; }

// Floating seaweed slows vessels and may hide an encounter
inline bool mm2encaFloatingSeaweedSlowsVessels()
    { return true; }

// A whirlpool sinks the vessel in 6 rounds at the cumulative rate
inline bool mm2encaWhirlpoolSinksInSixRounds()
    { return true; }

// The DM may modify or replace encounters for the party and terrain
inline bool mm2encaDmMayModifyOrReplace()
    { return true; }

// ---- the the cold freshwater surface grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encaCFSDie(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the hazard, pointer and lung dragon
// rows)
inline int mm2encaCFSSrc(int b)
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
            return 2;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 0;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 4 the hazard row, 5 the pointer row)
inline int mm2encaCFSSpecial(int b)
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
            return 4;
        case 8:
            return 5;
        case 9:
            return 0;
        case 10:
            return 5;
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

// ---- the the cold freshwater depths grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encaCFDDie(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the hazard, pointer and lung dragon
// rows)
inline int mm2encaCFDSrc(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
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
            return 2;
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

// The special cells (0 the monster rows, 4 the hazard row, 5 the pointer row)
inline int mm2encaCFDSpecial(int b)
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

// ---- the the cold saltwater surface grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encaCSSDie(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the hazard, pointer and lung dragon
// rows)
inline int mm2encaCSSSrc(int b)
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
            return 0;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 2;
        case 15:
            return 1;
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

// The special cells (0 the monster rows, 4 the hazard row, 5 the pointer row)
inline int mm2encaCSSSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 4;
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
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 4;
        case 12:
            return 0;
        case 13:
            return 4;
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

// ---- the the cold saltwater depths grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encaCSDDie(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the hazard, pointer and lung dragon
// rows)
inline int mm2encaCSDSrc(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 2;
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
            return 1;
        case 18:
            return 0;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 4 the hazard row, 5 the pointer row)
inline int mm2encaCSDSpecial(int b)
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

// ---- the the temperate freshwater surface grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encaTFSDie(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the hazard, pointer and lung dragon
// rows)
inline int mm2encaTFSSrc(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 1;
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
            return 3;
        case 10:
            return 2;
        case 11:
            return 0;
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
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 4 the hazard row, 5 the pointer row)
inline int mm2encaTFSSpecial(int b)
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
            return 5;
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

// ---- the the temperate freshwater depths grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encaTFDDie(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the hazard, pointer and lung dragon
// rows)
inline int mm2encaTFDSrc(int b)
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
            return 3;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 4 the hazard row, 5 the pointer row)
inline int mm2encaTFDSpecial(int b)
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

// ---- the the temperate saltwater surface grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encaTSSDie(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the hazard, pointer and lung dragon
// rows)
inline int mm2encaTSSSrc(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 3;
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
            return 2;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 4 the hazard row, 5 the pointer row)
inline int mm2encaTSSSpecial(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 4;
        case 3:
            return 4;
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
            return 0;
        case 10:
            return 0;
        case 11:
            return 4;
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

// ---- the the temperate saltwater depths grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encaTSDDie(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the hazard, pointer and lung dragon
// rows)
inline int mm2encaTSDSrc(int b)
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
            return 2;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 4 the hazard row, 5 the pointer row)
inline int mm2encaTSDSpecial(int b)
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
            return 4;
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

// ---- the the tropical freshwater surface grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encaRFSDie(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the hazard, pointer and lung dragon
// rows)
inline int mm2encaRFSSrc(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 2;
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
            return 0;
        case 9:
            return 1;
        case 10:
            return 3;
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
            return 3;
        case 18:
            return 3;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 4 the hazard row, 5 the pointer row)
inline int mm2encaRFSSpecial(int b)
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
            return 5;
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

// ---- the the tropical freshwater depths grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encaRFDDie(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the hazard, pointer and lung dragon
// rows)
inline int mm2encaRFDSrc(int b)
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
            return 3;
        case 11:
            return 3;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 3;
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

// The special cells (0 the monster rows, 4 the hazard row, 5 the pointer row)
inline int mm2encaRFDSpecial(int b)
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

// ---- the the tropical saltwater surface grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encaRSSDie(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the hazard, pointer and lung dragon
// rows)
inline int mm2encaRSSSrc(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 0;
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
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        default:
            return 0;
        }
    }

// The special cells (0 the monster rows, 4 the hazard row, 5 the pointer row)
inline int mm2encaRSSSpecial(int b)
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
            return 4;
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

// ---- the the tropical saltwater depths grid pins ----

// The die cells (2-20 contiguous, one row per die)
inline int mm2encaRSDDie(int b)
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

// The source cells (1 MM1, 2 MM2, 3 FF, 0 the hazard, pointer and lung dragon
// rows)
inline int mm2encaRSDSrc(int b)
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
            return 2;
        case 14:
            return 2;
        case 15:
            return 1;
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

// The special cells (0 the monster rows, 4 the hazard row, 5 the pointer row)
inline int mm2encaRSDSpecial(int b)
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
            return 4;
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
