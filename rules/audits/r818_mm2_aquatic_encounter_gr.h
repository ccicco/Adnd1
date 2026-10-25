    // ---- R818 MM2 aquatic encounter grids audit ----
    // THE MM2 AQUATIC ENCOUNTER TABLES WALK - the 12 surface and depths grids
    // (print p. 137 - the gap box label says pp. 150+ but the true folio is
    // 137, the printed page numbers in both scans; the 6 main areas cold,
    // temperate and tropical, each freshwater and saltwater, each surface and
    // depths), every die row 2-20 pinned as the three-cell grid (die, source,
    // special). THE SCHEMA: like the outdoor grids the aquatic grids print no
    // source and no number-encountered columns, so the source cells are
    // EDITORIAL - 1 MM1 / 2 MM2 / 3 FF / 0 none - derived from the print own
    // index and the registry provenance (the lua headers); the special cells
    // 0 the monster rows, 4 the hazard row, 5 the pointer row. THE SETTLED
    // READS (the print index, the registry provenance and the 1eonline
    // roster, three voices collated): the Quipper, Kelpie, Dragonfish, Throat
    // Leech, Vodyanoi, Thork (the Copper Stork, the Boiler Bird
    // parenthetical), the four Urchins (Green, Red, Black, Silver), Crabman,
    // Algoid and Bunyip cells all Fiend Folio per the index F-refs - the
    // registry carries no FF defs, the rows ride keyless. THE EDITORIAL PICKS
    // (all flagged here, the or-row first-creature convention the R816 rule):
    // the Mottled Worm cell the MM1 purple worm parenthetical; the Kopoacinth
    // cell the MM1 water gargoyle parenthetical; the Lacedon cells the MM1
    // ghoul entry; the Elf, Aquatic cell the MM1 elf entry marine race; the
    // Man, Pirate cell the buccaneer; the Seawolf, Giant cell the greater
    // seawolf (the print cell reads Giant, the entry Greater - flagged); the
    // Snapper, Giant cell the giant snapping turtle; the Eel, Weed cell the
    // MM2 weed entry; the Ixitachitl cells the ixitxachitl spelling; the
    // Sphinx, Andro- cell the hyphen truncation androsphinx; the Scrag cells
    // split freshwater grids vs saltwater grids (the two registry scrags);
    // the Dragonfish or Scrag row rides keyless (the FF first creature). THE
    // FLAGGED CELLS: the Dragon, Sea and Dragon, Spirit cells (3 total) are
    // the oriental lung wang and shan lung cross-refs - no registry def, the
    // OA promotion seam owns them. THE HAZARD ROWS: 13 cells - Ice x2,
    // Whirlpool x3, Island x2, Ghost Ship x3, Seaweed x3 - each cites the p.
    // 137 doctrine codified in the consts above; THE POINTER ROWS: 4 cells -
    // Surface Encounter x3, Land Encounter x1. THE DOCTRINE: the ice hull
    // bands (10-16 ft fresh, 10-60 ft salt, 1-6 damage per round, the 10
    // percent iceberg hole, the 10-20 ice fields), the ghost ship crew and
    // officer subtables (the 41-60 officer gap pinned verbatim), the sunken
    // ship chart (the 11-20 no-treasure overlap pinned verbatim), the
    // floating seaweed and seaweed bed bands, the island reef bands, the
    // whirlpool arithmetic (75 percent small craft only under 50 ft, 25
    // percent any vessel, the cumulative rate, 6 rounds to sink) - all pinned
    // as consts and bools and examples.
    {
        using namespace rules;
        int bad = 0;
    if (mm2encaRound() != 818
            || mm2encaAreaCount() != 6
            || mm2encaSubregionCount() != 2
            || mm2encaTableCount() != 12
            || mm2encaRowsPerTable() != 19
            || mm2encaTotalRows() != 228
            || mm2encaCFSCount() != 19
            || mm2encaCFDCount() != 19
            || mm2encaCSSCount() != 19
            || mm2encaCSDCount() != 19
            || mm2encaTFSCount() != 19
            || mm2encaTFDCount() != 19
            || mm2encaTSSCount() != 19
            || mm2encaTSDCount() != 19
            || mm2encaRFSCount() != 19
            || mm2encaRFDCount() != 19
            || mm2encaRSSCount() != 19
            || mm2encaRSDCount() != 19
            || mm2encaDieMin() != 2
            || mm2encaDieMax() != 20
            || mm2encaIceHullMinFresh() != 10
            || mm2encaIceHullMaxFresh() != 16
            || mm2encaIceHullMinSalt() != 10
            || mm2encaIceHullMaxSalt() != 60
            || mm2encaIceDamageMin() != 1
            || mm2encaIceDamageMax() != 6
            || mm2encaIcebergHolePct() != 10
            || mm2encaIceFieldMinPct() != 10
            || mm2encaIceFieldMaxPct() != 20
            || mm2encaGhostSkeletonPct() != 40
            || mm2encaGhostZombiePct() != 40
            || mm2encaGhostJujuZombiePct() != 20
            || mm2encaGhostWightMin() != 1
            || mm2encaGhostWightMax() != 4
            || mm2encaGhostWraithMin() != 1
            || mm2encaGhostWraithMax() != 3
            || mm2encaGhostOfficerGapMin() != 41
            || mm2encaGhostOfficerGapMax() != 60
            || mm2encaGhostSpectreMin() != 1
            || mm2encaGhostSpectreMax() != 2
            || mm2encaGhostGhostMin() != 1
            || mm2encaGhostGhostMax() != 2
            || mm2encaGhostLichCount() != 1
            || mm2encaSunkenMerchantPct() != 20
            || mm2encaSunkenNoTreasureMin() != 11
            || mm2encaSunkenNoTreasureMax() != 20
            || mm2encaSunkenLacedonMin() != 2
            || mm2encaSunkenLacedonMax() != 24
            || mm2encaSeaweedSlowPct() != 50
            || mm2encaSeaweedEncounterPct() != 40
            || mm2encaSeaweedBedMinFt() != 30
            || mm2encaSeaweedBedMaxFt() != 300
            || mm2encaSeaweedBedVisionFt() != 10
            || mm2encaSeaweedBedPct() != 30
            || mm2encaIslandReefPct() != 10
            || mm2encaIslandHullMin() != 2
            || mm2encaIslandHullMax() != 12
            || mm2encaIslandHolePct() != 20
            || mm2encaWhirlpoolSmallCraftPct() != 75
            || mm2encaWhirlpoolAnyPct() != 25
            || mm2encaWhirlpoolCraftMaxFt() != 50
            || mm2encaWhirlpoolRoundsToSink() != 6
            || mm2encaHazardRows() != 13
            || mm2encaPointerRows() != 4
            || mm2encaMm1SourceRows() != 138
            || mm2encaMm2SourceRows() != 51
            || mm2encaFfSourceRows() != 19
            || mm2encaNoSourceRows() != 20
            || mm2encaWalkKeyRows() != 192
            || mm2encaLungDragonRows() != 3
            || mm2encaOrRows() != 14
            || mm2encaRegistryFloor() != 809
            || !mm2encaSixMainAreas()
            || !mm2encaClimateTimesWaterType()
            || !mm2encaSurfaceAndDepthsSplit()
            || !mm2encaNoPrintedSourceColumn()
            || !mm2encaNoPrintedNumberColumn()
            || !mm2encaDieRowsContiguous()
            || !mm2encaHazardRowHasNoMonsterStat()
            || !mm2encaPointerRowRoutesToAnotherTable()
            || !mm2encaIceMayBlockOrDamageVessels()
            || !mm2encaGhostShipCrewIsUndead()
            || !mm2encaSunkenShipsRollOnMainChart()
            || !mm2encaFloatingSeaweedSlowsVessels()
            || !mm2encaWhirlpoolSinksInSixRounds()
            || !mm2encaDmMayModifyOrReplace()
        )
            ++bad;
        // THE COLD FRESHWATER SURFACE GRID: the 19 die rows 2-20, one row per
        // die (die, source, special). Rows: die 2 Dragon Turtle (MM1
        // dragon_turtle); die 3 Harpy (MM1 harpy); die 4 Greenhag (MM2
        // greenhag); die 5 Naga, Water (MM1 water_naga); die 6 Lacedon (MM1
        // ghoul); die 7 Turtle, Giant Snapper (MM1 snapping_turtle); die 8
        // Swan (MM2 swan); die 9 Ice (the hazard row); die 10 Surface
        // Encounter (the pointer row); die 11 Man, Merchant (MM1 merchant);
        // die 12 Surface Encounter (the pointer row); die 13 Crystal Ooze or
        // Island (MM2 crystal_ooze); die 14 Buccaneer (MM1 buccaneer); die 15
        // Merrow (MM2 merrow); die 16 Scrag (MM2 scrag_freshwater); die 17
        // Nixie (MM1 nixie); die 18 Falcon, Large (MM2 falcon_large); die 19
        // Dragon, Sea (the lung dragon cross-ref, no registry def); die 20
        // Swanmay (MM2 swanmay)
        int CCFS[19][3] = {
            {2,1,0},
            {3,1,0},
            {4,2,0},
            {5,1,0},
            {6,1,0},
            {7,1,0},
            {8,2,0},
            {9,0,4},
            {10,0,5},
            {11,1,0},
            {12,0,5},
            {13,2,0},
            {14,1,0},
            {15,2,0},
            {16,2,0},
            {17,1,0},
            {18,2,0},
            {19,0,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encaCFSCount();
             ++b) {
            int vals[3];
            vals[0] = mm2encaCFSDie(b);
            vals[1] = mm2encaCFSSrc(b);
            vals[2] = mm2encaCFSSpecial(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCFS[b][c])
                    ++bad;
            }
        }
        // THE COLD FRESHWATER DEPTHS GRID: the 19 die rows 2-20, one row per
        // die (die, source, special). Rows: die 2 Giant, Storm (MM1
        // storm_giant); die 3 Verme (MM2 verme); die 4 Quipper (FF, no
        // registry def); die 5 Vodyanoi (FF, no registry def); die 6 Sirine
        // (MM2 sirine); die 7 Lacedon (MM1 ghoul); die 8 Kopoacinth (MM1
        // gargoyle); die 9 Crab, Giant or Scrag (MM1 giant_crab); die 10
        // Pike, Giant or Nixie (MM1 giant_pike); die 11 Otter or Dragonfish
        // (MM2 otter); die 12 Octopus or Sunken Ship (MM1 octopus); die 13
        // Gar, Giant or Nixie (MM1 giant_gar); die 14 Merrow (MM2 merrow);
        // die 15 Turtle, Giant Snapping (MM1 snapping_turtle); die 16
        // Lamprey, Normal (MM1 lamprey); die 17 Hippocampus (MM1
        // hippocampus); die 18 Morkoth (MM1 morkoth); die 19 Otter, Giant
        // (MM1 giant_otter); die 20 Nereid (MM2 nereid)
        int CCFD[19][3] = {
            {2,1,0},
            {3,2,0},
            {4,3,0},
            {5,3,0},
            {6,2,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,2,0},
            {12,1,0},
            {13,1,0},
            {14,2,0},
            {15,1,0},
            {16,1,0},
            {17,1,0},
            {18,1,0},
            {19,1,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encaCFDCount();
             ++b) {
            int vals[3];
            vals[0] = mm2encaCFDDie(b);
            vals[1] = mm2encaCFDSrc(b);
            vals[2] = mm2encaCFDSpecial(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCFD[b][c])
                    ++bad;
            }
        }
        // THE COLD SALTWATER SURFACE GRID: the 19 die rows 2-20, one row per
        // die (die, source, special). Rows: die 2 Wind Walker (MM1
        // wind_walker); die 3 Whirlpool (the hazard row); die 4 Dragon, White
        // (MM1 white_dragon); die 5 Ghost Ship (the hazard row); die 6
        // Narwhale (MM2 narwhale); die 7 Turtle, Giant Sea (MM1 sea_turtle);
        // die 8 Sea Lion (MM1 sea_lion); die 9 Man, Merchant (MM1 merchant);
        // die 10 Shark (MM1 shark); die 11 Whale (MM1 whale); die 12 Pirate
        // or Hollyphant (MM1 buccaneer); die 13 Ice (the hazard row); die 14
        // Dolphin (MM1 dolphin); die 15 Island (the hazard row); die 16 Scrag
        // (MM2 scrag_saltwater); die 17 Will-o-wisp (MM1 will_o_wisp); die 18
        // Seawolf, Greater (MM2 seawolf_greater); die 19 Selkie (MM2 selkie);
        // die 20 Dragon Turtle (MM1 dragon_turtle)
        int CCSS[19][3] = {
            {2,1,0},
            {3,0,4},
            {4,1,0},
            {5,0,4},
            {6,2,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,0,4},
            {14,1,0},
            {15,0,4},
            {16,2,0},
            {17,1,0},
            {18,2,0},
            {19,2,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encaCSSCount();
             ++b) {
            int vals[3];
            vals[0] = mm2encaCSSDie(b);
            vals[1] = mm2encaCSSSrc(b);
            vals[2] = mm2encaCSSSpecial(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCSS[b][c])
                    ++bad;
            }
        }
        // THE COLD SALTWATER DEPTHS GRID: the 19 die rows 2-20, one row per
        // die (die, source, special). Rows: die 2 Verme (MM2 verme); die 3
        // Water Weird (MM1 water_weird); die 4 Seawolf, Lesser (MM2
        // seawolf_lesser); die 5 Urchin, Green (FF, no registry def); die 6
        // Urchin, Red (FF, no registry def); die 7 Dolphin (MM1 dolphin); die
        // 8 Elf, Aquatic (MM1 elf); die 9 Shark (MM1 shark); die 10 Crab,
        // Giant or Nixie (MM1 giant_crab); die 11 Narwhale or Naga, Water
        // (MM2 narwhale); die 12 Octopus or Shark, Giant (MM1 octopus); die
        // 13 Whale (MM1 whale); die 14 Sea Lion (MM1 sea_lion); die 15
        // Kopoacinth (MM1 gargoyle); die 16 Squid, Giant (MM1 giant_squid);
        // die 17 Octopus (MM1 octopus); die 18 Slime, Green (MM1
        // green_slime); die 19 Titan (MM1 titan); die 20 Dragon, Sea (the
        // lung dragon cross-ref, no registry def)
        int CCSD[19][3] = {
            {2,2,0},
            {3,1,0},
            {4,2,0},
            {5,3,0},
            {6,3,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,2,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,1,0},
            {16,1,0},
            {17,1,0},
            {18,1,0},
            {19,1,0},
            {20,0,0},
            };
        for (int b = 0;
             b < mm2encaCSDCount();
             ++b) {
            int vals[3];
            vals[0] = mm2encaCSDDie(b);
            vals[1] = mm2encaCSDSrc(b);
            vals[2] = mm2encaCSDSpecial(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CCSD[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE FRESHWATER SURFACE GRID: the 19 die rows 2-20, one
        // row per die (die, source, special). Rows: die 2 Dragonfly, Giant
        // (MM2 giant_dragonfly); die 3 Dragon, Carp (MM2 carp_giant); die 4
        // Lizardman (MM1 lizard_man); die 5 Crystal Ooze (MM2 crystal_ooze);
        // die 6 Buccaneer (MM1 buccaneer); die 7 Merrow (MM2 merrow); die 8
        // Swan (MM2 swan); die 9 Crocodile, Normal (MM1 crocodile); die 10
        // Man, Merchant (MM1 merchant); die 11 Throat Leech (FF, no registry
        // def); die 12 Crane, Giant or Dragon, Mist (MM2 crane_giant); die 13
        // Surface Encounter (the pointer row); die 14 Crayfish, Giant (MM1
        // giant_crayfish); die 15 Frog, Giant (MM1 giant_frog); die 16 Sirine
        // (MM2 sirine); die 17 Otter, Giant (MM1 giant_otter); die 18 Scrag
        // (MM2 scrag_freshwater); die 19 Dragon, Red (MM1 red_dragon); die 20
        // Boobrie (MM2 boobrie)
        int CTFS[19][3] = {
            {2,2,0},
            {3,2,0},
            {4,1,0},
            {5,2,0},
            {6,1,0},
            {7,2,0},
            {8,2,0},
            {9,1,0},
            {10,1,0},
            {11,3,0},
            {12,2,0},
            {13,0,5},
            {14,1,0},
            {15,1,0},
            {16,2,0},
            {17,1,0},
            {18,2,0},
            {19,1,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encaTFSCount();
             ++b) {
            int vals[3];
            vals[0] = mm2encaTFSDie(b);
            vals[1] = mm2encaTFSSrc(b);
            vals[2] = mm2encaTFSSpecial(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CTFS[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE FRESHWATER DEPTHS GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Mud-man (MM2 mud_man);
        // die 3 Muckdweller (MM2 muckdweller); die 4 Beaver, Giant (MM1
        // giant_beaver); die 5 Lamprey, Giant (MM1 giant_lamprey); die 6
        // Lizard Man (MM1 lizard_man); die 7 Turtle, Giant Snapper (MM1
        // snapping_turtle); die 8 Kopoacinth (MM1 gargoyle); die 9 Beetle,
        // Giant Water (MM1 water_beetle); die 10 Spider, Giant Water (MM1
        // water_spider); die 11 Throat Leech (FF, no registry def); die 12
        // Crocodile (MM1 crocodile); die 13 Otter, Giant or Nymph (MM1
        // giant_otter); die 14 Crayfish, Giant (MM1 giant_crayfish); die 15
        // Lamprey (MM1 lamprey); die 16 Dragon, Carp (MM2 carp_giant); die 17
        // Gar, Giant (MM1 giant_gar); die 18 Octopus (MM1 octopus); die 19
        // Algoid (FF, no registry def); die 20 Lizard Man with Lizard King
        // (MM1 lizard_man)
        int CTFD[19][3] = {
            {2,2,0},
            {3,2,0},
            {4,1,0},
            {5,1,0},
            {6,1,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,3,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,1,0},
            {16,2,0},
            {17,1,0},
            {18,1,0},
            {19,3,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encaTFDCount();
             ++b) {
            int vals[3];
            vals[0] = mm2encaTFDDie(b);
            vals[1] = mm2encaTFDSrc(b);
            vals[2] = mm2encaTFDSpecial(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CTFD[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE SALTWATER SURFACE GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Ki-rin (MM1 ki_rin);
        // die 3 Dragon, Cloud (MM2 cloud_dragon); die 4 Ghost Ship (the
        // hazard row); die 5 Whirlpool (the hazard row); die 6 Crabman (FF,
        // no registry def); die 7 Eel, Giant (MM1 giant_eel); die 8 Island
        // (the hazard row); die 9 Dinosaur, Plesiosaur (MM1 plesiosaurus);
        // die 10 Man, Merchant (MM1 merchant); die 11 Shark (MM1 shark); die
        // 12 Whale (MM1 whale); die 13 Seaweed, Floating (the hazard row);
        // die 14 Dinosaur, Elasmosaur (MM1 elasmosaurus); die 15 Will-o-wisp
        // (MM1 will_o_wisp); die 16 Crab, Giant (MM1 giant_crab); die 17
        // Lacedon (MM1 ghoul); die 18 Dragon, Bronze (MM1 bronze_dragon); die
        // 19 Seawolf, Giant (MM2 seawolf_greater); die 20 Verme (MM2 verme)
        int CTSS[19][3] = {
            {2,1,0},
            {3,2,0},
            {4,0,4},
            {5,0,4},
            {6,3,0},
            {7,1,0},
            {8,0,4},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,0,4},
            {14,1,0},
            {15,1,0},
            {16,1,0},
            {17,1,0},
            {18,1,0},
            {19,2,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encaTSSCount();
             ++b) {
            int vals[3];
            vals[0] = mm2encaTSSDie(b);
            vals[1] = mm2encaTSSSrc(b);
            vals[2] = mm2encaTSSSpecial(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CTSS[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE SALTWATER DEPTHS GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Morkoth (MM1 morkoth);
        // die 3 Kraken (MM2 kraken); die 4 Narwhale (MM2 narwhale); die 5
        // Lamprey, Giant (MM1 giant_lamprey); die 6 Shark, Giant (MM1
        // giant_shark); die 7 Sea Lion (MM1 sea_lion); die 8 Urchin, Black
        // (FF, no registry def); die 9 Dinosaur, Plesiosaur (MM1
        // plesiosaurus); die 10 Sea Horse (MM1 sea_horse); die 11 Shark (MM1
        // shark); die 12 Whale (MM1 whale); die 13 Seaweed (the hazard row);
        // die 14 Masher (MM1 masher); die 15 Eel, Giant (MM1 giant_eel); die
        // 16 Dragon Turtle (MM1 dragon_turtle); die 17 Mottled Worm (MM1
        // purple_worm); die 18 Seawolf, Lesser (MM2 seawolf_lesser); die 19
        // Eye of the Deep (MM1 eye_of_the_deep); die 20 Titan (MM1 titan)
        int CTSD[19][3] = {
            {2,1,0},
            {3,2,0},
            {4,2,0},
            {5,1,0},
            {6,1,0},
            {7,1,0},
            {8,3,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,0,4},
            {14,1,0},
            {15,1,0},
            {16,1,0},
            {17,1,0},
            {18,2,0},
            {19,1,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encaTSDCount();
             ++b) {
            int vals[3];
            vals[0] = mm2encaTSDDie(b);
            vals[1] = mm2encaTSDSrc(b);
            vals[2] = mm2encaTSDSpecial(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CTSD[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL FRESHWATER SURFACE GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Froghemoth (MM2
        // froghemoth); die 3 Couatl (MM1 couatl); die 4 Catfish, Giant (MM2
        // catfish_giant); die 5 Crystal Ooze (MM2 crystal_ooze); die 6
        // Dragon, Mist (MM2 mist_dragon); die 7 Spider, Giant (MM1
        // giant_spider); die 8 Crayfish, Giant (MM1 giant_crayfish); die 9
        // Man, Merchant (MM1 merchant); die 10 Land Encounter (the pointer
        // row); die 11 Crocodile, Normal (MM1 crocodile); die 12 Throat Leech
        // (FF, no registry def); die 13 Behemoth or Crane, Giant (MM2
        // behemoth); die 14 Frog, Giant (MM1 giant_frog); die 15 Hippopotamus
        // (MM1 hippopotamus); die 16 Sirine (MM2 sirine); die 17 Merman (MM1
        // merman); die 18 Manticore (MM1 manticore); die 19 Kelpie (FF, no
        // registry def); die 20 Thork (FF, no registry def)
        int CRFS[19][3] = {
            {2,2,0},
            {3,1,0},
            {4,2,0},
            {5,2,0},
            {6,2,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,0,5},
            {11,1,0},
            {12,3,0},
            {13,2,0},
            {14,1,0},
            {15,1,0},
            {16,2,0},
            {17,1,0},
            {18,1,0},
            {19,3,0},
            {20,3,0},
            };
        for (int b = 0;
             b < mm2encaRFSCount();
             ++b) {
            int vals[3];
            vals[0] = mm2encaRFSDie(b);
            vals[1] = mm2encaRFSSrc(b);
            vals[2] = mm2encaRFSSpecial(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CRFS[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL FRESHWATER DEPTHS GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Verme (MM2 verme); die
        // 3 Eel, Weed (MM1 weed); die 4 Kelpie (FF, no registry def); die 5
        // Vodyanoi (FF, no registry def); die 6 Behemoth (MM2 behemoth); die
        // 7 Merman (MM1 merman); die 8 Snapper, Giant (MM1 snapping_turtle);
        // die 9 Beetle, Giant Water (MM1 water_beetle); die 10 Dinosaur,
        // Dinichtys (MM1 dinichthys); die 11 Spider, Giant Water (MM1
        // water_spider); die 12 Throat Leech (FF, no registry def); die 13
        // Dragonfish or Scrag (FF, no registry def); die 14 Dinosaur,
        // Archelon (MM1 archelon_ischyros); die 15 Kopoacinth (MM1 gargoyle);
        // die 16 Bunyip (FF, no registry def); die 17 Lizardman (MM1
        // lizard_man); die 18 Dragon, Spirit (the lung dragon cross-ref, no
        // registry def); die 19 Sea Hag (MM1 sea_hag); die 20 Water Weird
        // (MM1 water_weird)
        int CRFD[19][3] = {
            {2,2,0},
            {3,1,0},
            {4,3,0},
            {5,3,0},
            {6,2,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,3,0},
            {13,3,0},
            {14,1,0},
            {15,1,0},
            {16,3,0},
            {17,1,0},
            {18,0,0},
            {19,1,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encaRFDCount();
             ++b) {
            int vals[3];
            vals[0] = mm2encaRFDDie(b);
            vals[1] = mm2encaRFDSrc(b);
            vals[2] = mm2encaRFDSpecial(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CRFD[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL SALTWATER SURFACE GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Wereshark (MM2
        // wereshark); die 3 Seawolf, Greater (MM2 seawolf_greater); die 4 Roc
        // (MM1 roc); die 5 Whirlpool (the hazard row); die 6 Sahuagin (MM1
        // sahuagin); die 7 Portuguese Man-o-war (MM1 portuguese_man_o_war);
        // die 8 Sea Hag (MM1 sea_hag); die 9 Crocodile, Giant (MM1
        // giant_crocodile); die 10 Dinosaur, Plesiosaur (MM1 plesiosaurus);
        // die 11 Man, Merchant (MM1 merchant); die 12 Shark (MM1 shark); die
        // 13 Whale (MM1 whale); die 14 Man, Pirate (MM1 buccaneer); die 15
        // Dinosaur, Mosasaur (MM1 mosasaurus); die 16 Ghost Ship (the hazard
        // row); die 17 Shark, Giant (MM1 giant_shark); die 18 Sphinx, Andro-
        // (MM1 androsphinx); die 19 Ixitachitl (MM1 ixitxachitl); die 20
        // Triton (MM1 triton)
        int CRSS[19][3] = {
            {2,2,0},
            {3,2,0},
            {4,1,0},
            {5,0,4},
            {6,1,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,1,0},
            {16,0,4},
            {17,1,0},
            {18,1,0},
            {19,1,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encaRSSCount();
             ++b) {
            int vals[3];
            vals[0] = mm2encaRSSDie(b);
            vals[1] = mm2encaRSSSrc(b);
            vals[2] = mm2encaRSSSpecial(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CRSS[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL SALTWATER DEPTHS GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Morkoth (MM1 morkoth);
        // die 3 Urchin, Silver (FF, no registry def); die 4 Crocodile, Giant
        // (MM1 giant_crocodile); die 5 Octopus (MM1 octopus); die 6 Pungi-ray
        // (MM1 pungi_ray); die 7 Sahuagin (MM1 sahuagin); die 8 Urchin, Black
        // (FF, no registry def); die 9 Dinosaur, Dinichtys (MM1 dinichthys);
        // die 10 Ray, Sting (MM1 sting_ray); die 11 Shark (MM1 shark); die 12
        // Seaweed (the hazard row); die 13 Strangleweed (MM1 strangle_weed);
        // die 14 Barracuda (MM1 barracuda); die 15 Dinosaur, Nothosaur (MM2
        // nothosaurus); die 16 Eel, Electric Marine (MM2 electric_eel); die
        // 17 Triton (MM1 triton); die 18 Wereshark (MM2 wereshark); die 19
        // Kraken (MM2 kraken); die 20 Ixitachitl (MM1 ixitxachitl)
        int CRSD[19][3] = {
            {2,1,0},
            {3,3,0},
            {4,1,0},
            {5,1,0},
            {6,1,0},
            {7,1,0},
            {8,3,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,0,4},
            {13,1,0},
            {14,1,0},
            {15,2,0},
            {16,2,0},
            {17,1,0},
            {18,2,0},
            {19,2,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encaRSDCount();
             ++b) {
            int vals[3];
            vals[0] = mm2encaRSDDie(b);
            vals[1] = mm2encaRSDSrc(b);
            vals[2] = mm2encaRSDSpecial(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CRSD[b][c])
                    ++bad;
            }
        }
        // the census walk (the 12-grid arithmetic)
    if (mm2encaTotalRows() != mm2encaTableCount() * mm2encaRowsPerTable()
            || mm2encaTableCount() != 12
            || mm2encaRowsPerTable() != 19
        )
            ++bad;
        // the area-subregion pairing
    if (mm2encaAreaCount() * mm2encaSubregionCount() != mm2encaTableCount()
            || mm2encaAreaCount() != 6
        )
            ++bad;
        // the die range
    if (mm2encaDieMin() != 2
            || mm2encaDieMax() != 20
        )
            ++bad;
        // the hazard and pointer censuses
    if (mm2encaHazardRows() != 13
            || mm2encaPointerRows() != 4
        )
            ++bad;
        // the source census sums to the total
    if (mm2encaMm1SourceRows() + mm2encaMm2SourceRows() +
        mm2encaFfSourceRows() + mm2encaNoSourceRows() != mm2encaTotalRows()
        )
            ++bad;
        // the no-source arithmetic (hazards + pointers + lung dragons)
    if (mm2encaHazardRows() + mm2encaPointerRows() + mm2encaLungDragonRows()
        != mm2encaNoSourceRows()
        )
            ++bad;
        // the walk-key census (the MM1 and MM2 defs the registry owns)
    if (mm2encaWalkKeyRows() != mm2encaMm1SourceRows() +
        mm2encaMm2SourceRows() + lungpCellsRewired()
        )
            ++bad;
        // the whirlpool arithmetic (75 + 25, six rounds to sink)
    if (mm2encaWhirlpoolSmallCraftPct() + mm2encaWhirlpoolAnyPct() != 100
            || mm2encaWhirlpoolRoundsToSink() != 6
            || mm2encaWhirlpoolCraftMaxFt() != 50
        )
            ++bad;
        // the ghost ship crew arithmetic (the three crew bands sum to 100)
    if (mm2encaGhostSkeletonPct() + mm2encaGhostZombiePct() +
        mm2encaGhostJujuZombiePct() != 100
            || mm2encaGhostLichCount() != 1
        )
            ++bad;
        // the ghost ship officer bands (the 41-60 print gap pinned verbatim)
    if (mm2encaGhostOfficerGapMin() != 41
            || mm2encaGhostOfficerGapMax() != 60
            || mm2encaGhostWightMax() != 4
            || mm2encaGhostWraithMax() != 3
            || mm2encaGhostSpectreMax() != 2
            || mm2encaGhostGhostMax() != 2
        )
            ++bad;
        // the sunken ship bands (the 11-20 no-treasure overlap pinned
        // verbatim)
    if (mm2encaSunkenMerchantPct() != 20
            || mm2encaSunkenNoTreasureMin() != 11
            || mm2encaSunkenNoTreasureMax() != 20
            || mm2encaSunkenLacedonMin() != 2
            || mm2encaSunkenLacedonMax() != 24
        )
            ++bad;
        // the ice doctrine (the hull thickness bands and damage per round)
    if (mm2encaIceHullMinFresh() != 10
            || mm2encaIceHullMaxFresh() != 16
            || mm2encaIceHullMinSalt() != 10
            || mm2encaIceHullMaxSalt() != 60
            || mm2encaIceDamageMax() != 6
            || mm2encaIcebergHolePct() != 10
            || mm2encaIceFieldMinPct() != 10
            || mm2encaIceFieldMaxPct() != 20
        )
            ++bad;
        // the seaweed and island doctrine
    if (mm2encaSeaweedSlowPct() != 50
            || mm2encaSeaweedEncounterPct() != 40
            || mm2encaSeaweedBedMaxFt() != 300
            || mm2encaSeaweedBedVisionFt() != 10
            || mm2encaSeaweedBedPct() != 30
            || mm2encaIslandReefPct() != 10
            || mm2encaIslandHullMax() != 12
            || mm2encaIslandHolePct() != 20
        )
            ++bad;
        printf("R818 MM2 aquatic encounter grids audit: bad %d\n", bad);
        if (bad) return 1;
    }
