    // ---- R817 MM2 outdoor encounter grids audit ----
    // THE MM2 OUTDOOR ENCOUNTER TABLES WALK - the 36 terrain grids (print pp.
    // 140-141+, the 6 main areas x 6 terrains), every die row 2-20 pinned as
    // the three-cell grid (die, source, special). THE SCHEMA: the outdoor
    // grids print no source and no number-encountered columns (the dungeon
    // grids carry both), so the source cells are EDITORIAL - 1 MM1 / 2 MM2 /
    // 3 FF / 0 none - derived from the print own index (the M/F/bare page
    // refs) and the registry provenance (the lua headers); the special cells
    // 1 the Character Party row (the DMG character subtable), 2 the
    // Castle/Fortress structure row, 3 the Patrol men row. THE SETTLED READS
    // (the two word layers, the print index, the registry provenance and the
    // 1eonline FF roster the voices): the Giant, Mountain cell is the print
    // own index pointer - FF p.42, the Lambeosaurus parenthetical - no
    // registry def; the Tween cells are the index Luck Changer, FF p.91; the
    // Dragon, Earth cells the index Li Lung (the FF oriental earth dragon),
    // FF p.28; the Troll, Ice cells the index FF p.90 pointer; the Volt,
    // Vortex, Ettercap, Poltergeist, Rothe, Xvart, Norker, Dakon,
    // Penanggalan, Revenant, Sandman, Scarecrow, Huecuva, Shadow Demon, Blood
    // Hawk, Hoar Fox, Jermlaine, Killmoulis, Kelpie, Kenku, Khargra, Meazel,
    // Ogrillon, Osquip, Quaggoth, Snyad, Tiger Fly, Witherweed, Caterwaul,
    // Coffer Corpse, Crypt Thing, Denzelian, Devil Dog, Disenchanter, Dune
    // Stalker, Firedrake, Firenewt, Forlarren, Gambado, Grabman (the FF
    // Crabman, the print own misspelling) and Aarakocra, Algoid, Assassin
    // Bug, Cifal, Clubnek all FF per the index F-refs and the 1eonline FF
    // roster - the registry carries no FF defs, the rows ride keyless. THE
    // MEN ROWS: the Men, Nomad cells key dervish (the index: Nomad
    // (Dervish)); the Man, Patrol rows (15 cells) cite no stat block anywhere
    // in the MM1/MM2/FF prints - they ride the men row class, keyless. THE
    // EDITORIAL PICKS (all flagged here, the or-row first-creature convention
    // the R816 rule): the Aspis cell aspis_drone, the Formian cell
    // formian_worker, the Grue Elemental cell chaggrin (the first variant of
    // the MM2 p.72 elemental grue entry), the plain Camel cells
    // camel_dromedary, the Bee Giant Honey cells bee_worker, the Treant cell
    // the mature treant, the Bat cells bat_ordinary/bat_mobat, the plain
    // Vulture cells vulture_ordinary, the Demon Type I cell the vrock, the
    // plain Snake cells the MM1 constrictor/poisonous keys (the registry MM2
    // snake_constrictor/snake_poisonous stay with the MM2 S-walk), the Dwarf
    // Hill and Dwarf Mountain cells the dwarf def, the Volt or Ghoul and
    // Quaggoth or Deadly White Pudding rows keyless (the first creature FF).
    // THE SCAN NOTES: the scan-B Worker cells are Norker misreads (the R816
    // lesson); the coldSnake cells read Poisonous (white-furred) - the MM1
    // poisonous snake arctic parenthetical, keyed poisonous_snake. THE
    // FLAGGED CELLS: the Pterodactyl, Small cell (tropical wilderness
    // mountains die 10) - no index entry, no MM1/MM2/FF body def survives in
    // the registry sources - rides keyless for the physical copy; the
    // Lammasu, Greater cells (temperate civilized plains die 2, tropical
    // civilized hills die 20) point at a real MM2 stat block, LAMMASU GREATER
    // p. 79 (between the kraken and the land lamprey) that the R808 LMN walk
    // never promoted - src MM2, keyless pending that promotion round. THE
    // PARTY ROWS: 17 Character Party rows on 16 grids; the cold civilized
    // desert grid alone carries two (dies 7 and 14); the cold wilderness
    // hills grid the one wilderness grid with a party row.
    {
        using namespace rules;
        int bad = 0;
    if (mm2encoRound() != 817
            || mm2encoAreaCount() != 6
            || mm2encoTerrainCount() != 6
            || mm2encoTableCount() != 36
            || mm2encoRowsPerTable() != 19
            || mm2encoTotalRows() != 684
            || mm2encoCW1Count() != 19
            || mm2encoCW2Count() != 19
            || mm2encoCW3Count() != 19
            || mm2encoCW4Count() != 19
            || mm2encoCW5Count() != 19
            || mm2encoCW6Count() != 19
            || mm2encoCC1Count() != 19
            || mm2encoCC2Count() != 19
            || mm2encoCC3Count() != 19
            || mm2encoCC4Count() != 19
            || mm2encoCC5Count() != 19
            || mm2encoCC6Count() != 19
            || mm2encoTW1Count() != 19
            || mm2encoTW2Count() != 19
            || mm2encoTW3Count() != 19
            || mm2encoTW4Count() != 19
            || mm2encoTW5Count() != 19
            || mm2encoTW6Count() != 19
            || mm2encoTC1Count() != 19
            || mm2encoTC2Count() != 19
            || mm2encoTC3Count() != 19
            || mm2encoTC4Count() != 19
            || mm2encoTC5Count() != 19
            || mm2encoTC6Count() != 19
            || mm2encoRW1Count() != 19
            || mm2encoRW2Count() != 19
            || mm2encoRW3Count() != 19
            || mm2encoRW4Count() != 19
            || mm2encoRW5Count() != 19
            || mm2encoRW6Count() != 19
            || mm2encoRC1Count() != 19
            || mm2encoRC2Count() != 19
            || mm2encoRC3Count() != 19
            || mm2encoRC4Count() != 19
            || mm2encoRC5Count() != 19
            || mm2encoRC6Count() != 19
            || mm2encoDieMin() != 2
            || mm2encoDieMax() != 20
            || mm2encoCharacterPartyRows() != 17
            || mm2encoGridsWithPartyRow() != 16
            || mm2encoColdCivDesertPartyRows() != 2
            || mm2encoStructureRows() != 5
            || mm2encoPatrolRows() != 15
            || mm2encoMm1SourceRows() != 413
            || mm2encoMm2SourceRows() != 159
            || mm2encoFfSourceRows() != 74
            || mm2encoWalkKeyRows() != 645
            || mm2encoUnresolvedRows() != 1
            || mm2encoRegistryFloor() != 809
            || mm2encoOrRows() != 20
            || mm2encoLammasuGreaterRows() != 2
            || !mm2encoSixMainAreas()
            || !mm2encoColdIncludesArcticSubarctic()
            || !mm2encoTropicalIncludesSubtropical()
            || !mm2encoCivilizedIncludesInhabitedAndPatrolled()
            || !mm2encoEncountersTypicalToTerrain()
            || !mm2encoDmMayModifyOrReplace()
            || !mm2encoPartyRowRollsDmgSubtable()
            || !mm2encoNoPrintedSourceColumn()
            || !mm2encoNoPrintedNumberColumn()
            || !mm2encoDieRowsContiguous()
            || !mm2encoStructureRowIsCastleOrFortress()
            || !mm2encoPatrolRowIsMenType()
        )
            ++bad;
        // THE COLD WILDERNESS MOUNTAINS GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Giant, Mountain (FF, no
        // registry def); die 3 Hoar Fox (FF, no registry def); die 4 Galeb
        // Duhr (MM2 galeb_duh); die 5 Toad, Ice (MM1 ice_toad); die 6
        // Lycanthrope, Werebear (MM1 werebear); die 7 Dragon, White (MM1
        // white_dragon); die 8 Wolverine (MM1 wolverine); die 9 Dwarf,
        // Mountain (MM1 dwarf); die 10 Rhinoceros, Woolly (MM1
        // woolly_rhinoceros); die 11 Mammoth (MM1 mammoth); die 12 Raven,
        // Normal (MM2 raven_ordinary); die 13 Ogre (MM1 ogre); die 14 Lion,
        // Mountain (MM1 mountain_lion); die 15 Giant, Hill (MM1 hill_giant);
        // die 16 Giant, Frost (MM1 frost_giant); die 17 Fortress (the
        // Fortress row (the structure row)); die 18 Taer (MM2 taer); die 19
        // Yeti (MM1 yeti); die 20 Dragon, Red (MM1 red_dragon)
        int CEncoCW1[19][3] = {
            {2,3,0},
            {3,3,0},
            {4,2,0},
            {5,1,0},
            {6,1,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,2,0},
            {13,1,0},
            {14,1,0},
            {15,1,0},
            {16,1,0},
            {17,0,2},
            {18,2,0},
            {19,1,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoCW1Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoCW1Die(b);
            vals[1] = mm2encoCW1Src(b);
            vals[2] = mm2encoCW1Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoCW1[b][c])
                    ++bad;
            }
        }
        // THE COLD WILDERNESS HILLS AND ROUGH TERRAIN GRID: the 19 die rows
        // 2-20, one row per die (die, source, special). Rows: die 2 Wolf,
        // Winter (MM1 winter_wolf); die 3 Owl, Giant (MM1 giant_owl); die 4
        // Badger (MM1 badger); die 5 Character Party (the Character Party row
        // (the DMG subtable)); die 6 Bear, Northern (Polar Bear) (MM2
        // bear_northern); die 7 Troll, Ice (FF, no registry def); die 8
        // Mammoth (MM1 mammoth); die 9 Giant, Hill (MM1 hill_giant); die 10
        // Herd Animal (MM1 herd_animal); die 11 Wolf (MM1 wolf); die 12 Orc
        // (MM1 orc); die 13 Dwarf, Hill (MM1 dwarf); die 14 Bear, Cave (MM1
        // cave_bear); die 15 Snake, Poisonous (white-furred) (MM1
        // poisonous_snake); die 16 Boar, Wild (MM1 wild_boar); die 17
        // Wolverine, Giant (MM1 giant_wolverine); die 18 Irish Deer (MM1
        // irish_deer); die 19 Remorhaz (MM1 remorhaz); die 20 Elf, Grugach
        // (MM2 grugach)
        int CEncoCW2[19][3] = {
            {2,1,0},
            {3,1,0},
            {4,1,0},
            {5,0,1},
            {6,2,0},
            {7,3,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,1,0},
            {16,1,0},
            {17,1,0},
            {18,1,0},
            {19,1,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoCW2Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoCW2Die(b);
            vals[1] = mm2encoCW2Src(b);
            vals[2] = mm2encoCW2Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoCW2[b][c])
                    ++bad;
            }
        }
        // THE COLD WILDERNESS FOREST GRID: the 19 die rows 2-20, one row per
        // die (die, source, special). Rows: die 2 Giant, Frost (MM1
        // frost_giant); die 3 Forlarren (FF, no registry def); die 4 Treant
        // (MM1 treant_mature_middle_aged); die 5 Pudding, White (MM2
        // pudding_white); die 6 Bear, Northern (Polar Bear) (MM2
        // bear_northern); die 7 Porcupine, Giant (MM1 giant_porcupine); die 8
        // Bugbear (MM1 bugbear); die 9 Wolf (MM1 wolf); die 10 Ogre (MM1
        // ogre); die 11 Orc (MM1 orc); die 12 Dog, Wild (MM1 wild_dog); die
        // 13 Lycanthrope, Werewolf (MM1 werewolf); die 14 Manticore (MM1
        // manticore); die 15 Dragon, White (MM1 white_dragon); die 16
        // Baluchitherium (MM1 baluchitherium); die 17 Ogrillon (FF, no
        // registry def); die 18 Grim (MM2 grim); die 19 Korred (MM2 korred);
        // die 20 Lycanthrope, Foxwoman (MM2 foxwoman)
        int CEncoCW3[19][3] = {
            {2,1,0},
            {3,3,0},
            {4,1,0},
            {5,2,0},
            {6,2,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,1,0},
            {16,1,0},
            {17,3,0},
            {18,2,0},
            {19,2,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoCW3Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoCW3Die(b);
            vals[1] = mm2encoCW3Src(b);
            vals[2] = mm2encoCW3Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoCW3[b][c])
                    ++bad;
            }
        }
        // THE COLD WILDERNESS SWAMP AND MARSH GRID: the 19 die rows 2-20, one
        // row per die (die, source, special). Rows: die 2 Troll, Ice (FF, no
        // registry def); die 3 Wolf, Winter (MM1 winter_wolf); die 4 Wolf,
        // Dire (MM1 dire_wolf); die 5 Tiger or Spectre (Night) (MM1 tiger);
        // die 6 Crystal Ooze (MM2 crystal_ooze); die 7 Pseudo-undead, Spectre
        // (MM2 pseudo_undead); die 8 Hydra (MM1 hydra); die 9 Dog, Wild (MM1
        // wild_dog); die 10 Orc (MM1 orc); die 11 Quaggoth or Deadly White
        // Pudding (FF, no registry def); die 12 Ogre (MM1 ogre); die 13 Rat,
        // Giant (MM1 giant_rat); die 14 Volt or Ghoul (Night) (FF, no
        // registry def); die 15 Herd Animal (MM1 herd_animal); die 16 Irish
        // Deer (MM1 irish_deer); die 17 Moon Dog (MM2 moon_dog); die 18
        // Dragon, White (MM1 white_dragon); die 19 Owl, Giant (MM1
        // giant_owl); die 20 Black Willow (MM2 willow_black)
        int CEncoCW4[19][3] = {
            {2,3,0},
            {3,1,0},
            {4,1,0},
            {5,1,0},
            {6,2,0},
            {7,2,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,3,0},
            {12,1,0},
            {13,1,0},
            {14,3,0},
            {15,1,0},
            {16,1,0},
            {17,2,0},
            {18,1,0},
            {19,1,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoCW4Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoCW4Die(b);
            vals[1] = mm2encoCW4Src(b);
            vals[2] = mm2encoCW4Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoCW4[b][c])
                    ++bad;
            }
        }
        // THE COLD WILDERNESS PLAINS AND SCRUB GRID: the 19 die rows 2-20,
        // one row per die (die, source, special). Rows: die 2 Gorgon (MM1
        // gorgon); die 3 Yeth Hound (MM2 yeth_hound); die 4 Troll, Ice (FF,
        // no registry def); die 5 Men, Dervishes (MM1 dervish); die 6 Giant,
        // Hill (MM1 hill_giant); die 7 Snake, Poisonous (white-furred) (MM1
        // poisonous_snake); die 8 Men, Bandit (MM1 bandit); die 9 Mammoth
        // (MM1 mammoth); die 10 Mastodon (MM1 mastodon); die 11 Herd Animal
        // (MM1 herd_animal); die 12 Ogre (MM1 ogre); die 13 Camel, Bactrian
        // (MM1 camel_bactrian); die 14 Men, Nomad (MM1 dervish); die 15
        // Dragon, White (MM1 white_dragon); die 16 Devil Dog (FF, no registry
        // def); die 17 Wolf (MM1 wolf); die 18 Wolfwere (MM2 wolfwere); die
        // 19 Lynx, Giant (MM1 giant_lynx); die 20 Remorhaz (MM1 remorhaz)
        int CEncoCW5[19][3] = {
            {2,1,0},
            {3,2,0},
            {4,3,0},
            {5,1,0},
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
            {16,3,0},
            {17,1,0},
            {18,2,0},
            {19,1,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoCW5Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoCW5Die(b);
            vals[1] = mm2encoCW5Src(b);
            vals[2] = mm2encoCW5Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoCW5[b][c])
                    ++bad;
            }
        }
        // THE COLD WILDERNESS DESERT GRID: the 19 die rows 2-20, one row per
        // die (die, source, special). Rows: die 2 Dragon, Gold (MM1
        // gold_dragon); die 3 Hobgoblin (MM1 hobgoblin); die 4 Rock Reptile
        // (MM2 rock_reptile); die 5 Sandling (MM2 sandling); die 6 Hoar Fox
        // (FF, no registry def); die 7 Men, Nomad (MM1 dervish); die 8
        // Scorpion, Huge (MM2 scorpion_huge); die 9 Dog, Wild (MM1 wild_dog);
        // die 10 Camel, Bactrian (MM1 camel_bactrian); die 11 Herd Animal
        // (MM1 herd_animal); die 12 Scorpion, Large (MM2 scorpion_large); die
        // 13 Raven, Normal (MM2 raven_ordinary); die 14 Tiger (MM1 tiger);
        // die 15 Raven, Giant (MM2 raven_giant); die 16 Wolf (MM1 wolf); die
        // 17 Devil Dog (FF, no registry def); die 18 Bugbear (MM1 bugbear);
        // die 19 Gambado (FF, no registry def); die 20 Succubus (MM1
        // succubus)
        int CEncoCW6[19][3] = {
            {2,1,0},
            {3,1,0},
            {4,2,0},
            {5,2,0},
            {6,3,0},
            {7,1,0},
            {8,2,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,2,0},
            {13,2,0},
            {14,1,0},
            {15,2,0},
            {16,1,0},
            {17,3,0},
            {18,1,0},
            {19,3,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoCW6Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoCW6Die(b);
            vals[1] = mm2encoCW6Src(b);
            vals[2] = mm2encoCW6Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoCW6[b][c])
                    ++bad;
            }
        }
        // THE COLD CIVILIZED MOUNTAINS GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Denzelian (FF, no
        // registry def); die 3 Xorn (MM1 xorn); die 4 Aarakocra (FF, no
        // registry def); die 5 Men, Berserker (MM1 berserker); die 6 Quaggoth
        // (FF, no registry def); die 7 Goblin (MM1 goblin); die 8 Bugbear
        // (MM1 bugbear); die 9 Man, Bandit (MM1 bandit); die 10 Character
        // Party (the Character Party row (the DMG subtable)); die 11 Man,
        // Patrol (the Patrol men row (no print def)); die 12 Dwarf, Mountain
        // (MM1 dwarf); die 13 Falcon, Small (MM2 falcon_small); die 14
        // Hobgoblin (MM1 hobgoblin); die 15 Pilgrim (MM1 pilgrim); die 16
        // Man, Merchant (MM1 merchant); die 17 Minotaur (MM1 minotaur); die
        // 18 Castle (the Castle row (the structure row)); die 19 Wolf, Dire
        // (MM1 dire_wolf); die 20 Vampire (MM1 vampire)
        int CEncoCC1[19][3] = {
            {2,3,0},
            {3,1,0},
            {4,3,0},
            {5,1,0},
            {6,3,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,0,1},
            {11,0,3},
            {12,1,0},
            {13,2,0},
            {14,1,0},
            {15,1,0},
            {16,1,0},
            {17,1,0},
            {18,0,2},
            {19,1,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoCC1Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoCC1Die(b);
            vals[1] = mm2encoCC1Src(b);
            vals[2] = mm2encoCC1Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoCC1[b][c])
                    ++bad;
            }
        }
        // THE COLD CIVILIZED HILLS AND ROUGH TERRAIN GRID: the 19 die rows
        // 2-20, one row per die (die, source, special). Rows: die 2 Vampire
        // (MM1 vampire); die 3 Toad, Ice (MM1 ice_toad); die 4 Snyad (FF, no
        // registry def); die 5 Wolf, Dire (MM1 dire_wolf); die 6 Man,
        // Berserker (MM1 berserker); die 7 Pseudo-undead, Vampire (MM2
        // pseudo_undead); die 8 Hobgoblin (MM1 hobgoblin); die 9 Man, Bandit
        // (MM1 bandit); die 10 Man, Patrol (the Patrol men row (no print
        // def)); die 11 Character Party (the Character Party row (the DMG
        // subtable)); die 12 Man, Merchant (MM1 merchant); die 13 Dwarf, Hill
        // (MM1 dwarf); die 14 Mammoth (MM1 mammoth); die 15 Bat (MM2
        // bat_ordinary); die 16 Halfling (MM1 halfling); die 17 Goblin (MM1
        // goblin); die 18 Gnome (MM1 gnome); die 19 Bugbear (MM1 bugbear);
        // die 20 Xaren (MM2 xaren)
        int CEncoCC2[19][3] = {
            {2,1,0},
            {3,1,0},
            {4,3,0},
            {5,1,0},
            {6,1,0},
            {7,2,0},
            {8,1,0},
            {9,1,0},
            {10,0,3},
            {11,0,1},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,2,0},
            {16,1,0},
            {17,1,0},
            {18,1,0},
            {19,1,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoCC2Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoCC2Die(b);
            vals[1] = mm2encoCC2Src(b);
            vals[2] = mm2encoCC2Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoCC2[b][c])
                    ++bad;
            }
        }
        // THE COLD CIVILIZED FOREST GRID: the 19 die rows 2-20, one row per
        // die (die, source, special). Rows: die 2 Shedu (MM1 shedu); die 3
        // Groaning Spirit (MM1 groaning_spirit); die 4 Castle (the Castle row
        // (the structure row)); die 5 Lycanthrope, Werebear (MM1 werebear);
        // die 6 Hobgoblin (MM1 hobgoblin); die 7 Bat (MM2 bat_ordinary); die
        // 8 Bugbear (MM1 bugbear); die 9 Man, Patrol (the Patrol men row (no
        // print def)); die 10 Boar, Wild (MM1 wild_boar); die 11 Wolf (MM1
        // wolf); die 12 Ogre (MM1 ogre); die 13 Man, Bandit (MM1 bandit); die
        // 14 Elf, Wood (MM1 elf); die 15 Character Party (the Character Party
        // row (the DMG subtable)); die 16 Goblin (MM1 goblin); die 17 Shadow
        // (MM1 shadow); die 18 Norker (FF, no registry def); die 19 Bookworm
        // (MM2 bookworm); die 20 Shadow Mastiff or Ghost (Night) (MM2
        // shadow_mastiff)
        int CEncoCC3[19][3] = {
            {2,1,0},
            {3,1,0},
            {4,0,2},
            {5,1,0},
            {6,1,0},
            {7,2,0},
            {8,1,0},
            {9,0,3},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,0,1},
            {16,1,0},
            {17,1,0},
            {18,3,0},
            {19,2,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoCC3Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoCC3Die(b);
            vals[1] = mm2encoCC3Src(b);
            vals[2] = mm2encoCC3Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoCC3[b][c])
                    ++bad;
            }
        }
        // THE COLD CIVILIZED SWAMP AND MARSH GRID: the 19 die rows 2-20, one
        // row per die (die, source, special). Rows: die 2 Demon, Alu- (MM2
        // alu_demon); die 3 Poltergeist (FF, no registry def); die 4 Luck
        // Eater (MM2 luck_eater); die 5 Man, Berserker (MM1 berserker); die 6
        // Crab, Giant (MM1 giant_crab); die 7 Hobgoblin (MM1 hobgoblin); die
        // 8 Man, Patrol (the Patrol men row (no print def)); die 9 Centipede,
        // Giant or Huge (MM1 giant_centipede); die 10 Rat or Giant Rat (MM2
        // rat_ordinary); die 11 Man, Bandit (MM1 bandit); die 12 Ogre (MM1
        // ogre); die 13 Character Party (the Character Party row (the DMG
        // subtable)); die 14 Ghoul (MM1 ghoul); die 15 Pseudo-undead, Ghoul
        // (MM2 pseudo_undead); die 16 Ghast (MM1 ghast); die 17 Penanggalan
        // (FF, no registry def); die 18 Coffer Corpse (FF, no registry def);
        // die 19 Bugbear (MM1 bugbear); die 20 Grue, Varrdig (MM2 varrdig)
        int CEncoCC4[19][3] = {
            {2,2,0},
            {3,3,0},
            {4,2,0},
            {5,1,0},
            {6,1,0},
            {7,1,0},
            {8,0,3},
            {9,1,0},
            {10,2,0},
            {11,1,0},
            {12,1,0},
            {13,0,1},
            {14,1,0},
            {15,2,0},
            {16,1,0},
            {17,3,0},
            {18,3,0},
            {19,1,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoCC4Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoCC4Die(b);
            vals[1] = mm2encoCC4Src(b);
            vals[2] = mm2encoCC4Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoCC4[b][c])
                    ++bad;
            }
        }
        // THE COLD CIVILIZED PLAINS AND SCRUB GRID: the 19 die rows 2-20, one
        // row per die (die, source, special). Rows: die 2 Disenchanter (FF,
        // no registry def); die 3 Hollyphant (MM2 hollyphant); die 4 Dragon,
        // Earth (FF, no registry def); die 5 Wolf, Dire (MM1 dire_wolf); die
        // 6 Quaggoth (FF, no registry def); die 7 Osquip (FF, no registry
        // def); die 8 Owl (MM2 owl); die 9 Man, Bandit (MM1 bandit); die 10
        // Man, Patrol (the Patrol men row (no print def)); die 11 Man,
        // Merchant (MM1 merchant); die 12 Ogre (MM1 ogre); die 13 Wolf (MM1
        // wolf); die 14 Bugbear (MM1 bugbear); die 15 Character Party (the
        // Character Party row (the DMG subtable)); die 16 Lycanthrope,
        // Werewolf (MM1 werewolf); die 17 Goblin (MM1 goblin); die 18 Man,
        // Dervish (MM1 dervish); die 19 Lycanthrope, Wererat (MM1 wererat);
        // die 20 Tween (FF, no registry def)
        int CEncoCC5[19][3] = {
            {2,3,0},
            {3,2,0},
            {4,3,0},
            {5,1,0},
            {6,3,0},
            {7,3,0},
            {8,2,0},
            {9,1,0},
            {10,0,3},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,0,1},
            {16,1,0},
            {17,1,0},
            {18,1,0},
            {19,1,0},
            {20,3,0},
            };
        for (int b = 0;
             b < mm2encoCC5Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoCC5Die(b);
            vals[1] = mm2encoCC5Src(b);
            vals[2] = mm2encoCC5Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoCC5[b][c])
                    ++bad;
            }
        }
        // THE COLD CIVILIZED DESERT GRID: the 19 die rows 2-20, one row per
        // die (die, source, special). Rows: die 2 Shedu, Greater (MM1 shedu);
        // die 3 Vortex (FF, no registry def); die 4 Dragon, Gold (MM1
        // gold_dragon); die 5 Falcon, Large (MM2 falcon_large); die 6 Wolf,
        // Dire (MM1 dire_wolf); die 7 Character Party (the Character Party
        // row (the DMG subtable)); die 8 Pilgrim (MM1 pilgrim); die 9 Man,
        // Merchant (MM1 merchant); die 10 Man, Bandit (MM1 bandit); die 11
        // Goblin or Jermlaine (MM1 goblin); die 12 Raven, Normal (MM2
        // raven_ordinary); die 13 Camel, Bactrian (MM1 camel_bactrian); die
        // 14 Character Party (the Character Party row (the DMG subtable));
        // die 15 Wolf (MM1 wolf); die 16 Man, Dervish (MM1 dervish); die 17
        // Man, Berserker (MM1 berserker); die 18 Griffon (MM1 griffon); die
        // 19 Crypt Thing (FF, no registry def); die 20 Deva, Movanic (MM2
        // movanic_deva)
        int CEncoCC6[19][3] = {
            {2,1,0},
            {3,3,0},
            {4,1,0},
            {5,2,0},
            {6,1,0},
            {7,0,1},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,2,0},
            {13,1,0},
            {14,0,1},
            {15,1,0},
            {16,1,0},
            {17,1,0},
            {18,1,0},
            {19,3,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoCC6Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoCC6Die(b);
            vals[1] = mm2encoCC6Src(b);
            vals[2] = mm2encoCC6Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoCC6[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE WILDERNESS MOUNTAINS GRID: the 19 die rows 2-20, one
        // row per die (die, source, special). Rows: die 2 Cave Fisher (MM2
        // cave_fisher); die 3 Gorgimera (MM2 gorgimera); die 4 Dragon, Red
        // (MM1 red_dragon); die 5 Lion, Spotted (MM1 spotted_lion); die 6
        // Bat, Giant (MM2 bat_mobat); die 7 Giant, Stone (MM1 stone_giant);
        // die 8 Bloodhawk (FF, no registry def); die 9 Vulture, Normal (MM2
        // vulture_ordinary); die 10 Spider, Large (MM1 large_spider); die 11
        // Dwarf, Mountain (MM1 dwarf); die 12 Bat (MM2 bat_ordinary); die 13
        // Orc (MM1 orc); die 14 Lion, Mountain (MM1 mountain_lion); die 15
        // Cockatrice (MM1 cockatrice); die 16 Bear, Black (MM1 black_bear);
        // die 17 Caveman (MM1 caveman); die 18 Chimera (MM1 chimera); die 19
        // Khargra (FF, no registry def); die 20 Galeb Duhr (MM2 galeb_duh)
        int CEncoTW1[19][3] = {
            {2,2,0},
            {3,2,0},
            {4,1,0},
            {5,1,0},
            {6,2,0},
            {7,1,0},
            {8,3,0},
            {9,2,0},
            {10,1,0},
            {11,1,0},
            {12,2,0},
            {13,1,0},
            {14,1,0},
            {15,1,0},
            {16,1,0},
            {17,1,0},
            {18,1,0},
            {19,3,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoTW1Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoTW1Die(b);
            vals[1] = mm2encoTW1Src(b);
            vals[2] = mm2encoTW1Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoTW1[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE WILDERNESS HILLS AND ROUGH TERRAIN GRID: the 19 die
        // rows 2-20, one row per die (die, source, special). Rows: die 2
        // Gorgon (MM1 gorgon); die 3 Displacer Beast (MM1 displacer_beast);
        // die 4 Ant Lion, Giant (MM2 ant_lion); die 5 Bee, Giant Bumble- (MM2
        // bee_bumblebee); die 6 Harpy (MM1 harpy); die 7 Giant, Verbeeg (MM2
        // verbeeg); die 8 Scorpion, Large (MM2 scorpion_large); die 9 Giant,
        // Hill (MM1 hill_giant); die 10 Wolf (MM1 wolf); die 11 Orc (MM1
        // orc); die 12 Ogre (MM1 ogre); die 13 Lycanthrope, Werewolf (MM1
        // werewolf); die 14 Tiger (MM1 tiger); die 15 Spider, Huge (MM1
        // huge_spider); die 16 Mantis, Giant (MM2 giant_mantis); die 17 Aspis
        // (MM2 aspis_drone); die 18 Hybsil (MM2 hybsil); die 19 Vulture,
        // Giant (MM2 vulture_giant); die 20 Manticore (MM1 manticore)
        int CEncoTW2[19][3] = {
            {2,1,0},
            {3,1,0},
            {4,2,0},
            {5,2,0},
            {6,1,0},
            {7,2,0},
            {8,2,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,1,0},
            {16,2,0},
            {17,2,0},
            {18,2,0},
            {19,2,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoTW2Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoTW2Die(b);
            vals[1] = mm2encoTW2Src(b);
            vals[2] = mm2encoTW2Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoTW2[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE WILDERNESS FOREST GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Death Watch Beetle (MM2
        // beetle_death_watch); die 3 Elf, Grugach (MM2 grugach); die 4 Atomie
        // (MM2 atomie); die 5 Bee, Giant Honey (MM2 bee_worker); die 6
        // Dragon, Green (MM1 green_dragon); die 7 Boar, Giant (MM1
        // giant_boar); die 8 Kobold (MM1 kobold); die 9 Boar, Warthog (MM1
        // warthog); die 10 Rhinoceros (MM1 rhinoceros); die 11 Centipede,
        // Giant or Huge (MM1 giant_centipede); die 12 Bear, Black (MM1
        // black_bear); die 13 Beetle, Giant Stag (MM1 stag_beetle); die 14
        // Porcupine, Giant (MM1 giant_porcupine); die 15 Clubnek (FF, no
        // registry def); die 16 Owlbear (MM1 owlbear); die 17 Kech (MM2
        // kech); die 18 Green Hag (MM2 greenhag); die 19 Elfin Cat (MM2
        // elfin_cat); die 20 Basilisk, Greater (MM2 basilisk_greater)
        int CEncoTW3[19][3] = {
            {2,2,0},
            {3,2,0},
            {4,2,0},
            {5,2,0},
            {6,1,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,3,0},
            {16,1,0},
            {17,2,0},
            {18,2,0},
            {19,2,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoTW3Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoTW3Die(b);
            vals[1] = mm2encoTW3Src(b);
            vals[2] = mm2encoTW3Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoTW3[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE WILDERNESS SWAMP AND MARSH GRID: the 19 die rows
        // 2-20, one row per die (die, source, special). Rows: die 2 Algoid
        // (FF, no registry def); die 3 Dragon, Mist (MM2 mist_dragon); die 4
        // Troll, Giant (MM1 troll); die 5 Shambling Mound (MM1
        // shambling_mound); die 6 Phycomid (MM2 phycomid); die 7 Toad,
        // Poisonous (MM1 poisonous_toad); die 8 Lizard, Giant (MM1
        // giant_lizard); die 9 Toad, Giant (MM1 giant_toad); die 10 Vulture,
        // Normal (MM2 vulture_ordinary); die 11 Spider, Large or Huge (MM1
        // large_spider); die 12 Crocodile, Normal (MM1 crocodile); die 13 Orc
        // (MM1 orc); die 14 Wyvern (MM1 wyvern); die 15 Basidirond (MM2
        // basidirond); die 16 Caterwaul (FF, no registry def); die 17 Eblis
        // (MM2 eblis); die 18 Pseudo-undead, Wight (MM2 pseudo_undead); die
        // 19 Crayfish, Giant (MM1 giant_crayfish); die 20 Beholder (MM1
        // beholder)
        int CEncoTW4[19][3] = {
            {2,3,0},
            {3,2,0},
            {4,1,0},
            {5,1,0},
            {6,2,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,2,0},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,2,0},
            {16,3,0},
            {17,2,0},
            {18,2,0},
            {19,1,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoTW4Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoTW4Die(b);
            vals[1] = mm2encoTW4Src(b);
            vals[2] = mm2encoTW4Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoTW4[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE WILDERNESS PLAINS AND SCRUB GRID: the 19 die rows
        // 2-20, one row per die (die, source, special). Rows: die 2 Ascomoid
        // (MM2 ascomoid); die 3 Giant, Firbolg or Verbeeg (MM2 firbolg); die
        // 4 Xvart (FF, no registry def); die 5 Troll (MM1 troll); die 6 Tiger
        // Fly (FF, no registry def); die 7 Kenku (FF, no registry def); die 8
        // Lion (MM1 lion); die 9 Boar, Wild (MM1 wild_boar); die 10 Cattle,
        // Wild (MM1 wild_cattle); die 11 Wolf (MM1 wolf); die 12 Jackal (MM1
        // jackal); die 13 Scorpion, Huge (MM2 scorpion_huge); die 14 Shadow
        // Mastiff (MM2 shadow_mastiff); die 15 Titanothere (MM1
        // titanotherium); die 16 Bee, Giant Bumble- (MM2 bee_bumblebee); die
        // 17 Blink Dog (MM1 blink_dog); die 18 Gnoll (MM1 gnoll); die 19 Yeth
        // Hound (MM2 yeth_hound); die 20 Bulette (MM1 bulette)
        int CEncoTW5[19][3] = {
            {2,2,0},
            {3,2,0},
            {4,3,0},
            {5,1,0},
            {6,3,0},
            {7,3,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,2,0},
            {14,2,0},
            {15,1,0},
            {16,2,0},
            {17,1,0},
            {18,1,0},
            {19,2,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoTW5Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoTW5Die(b);
            vals[1] = mm2encoTW5Src(b);
            vals[2] = mm2encoTW5Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoTW5[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE WILDERNESS DESERT GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Giant, Fire (MM1
        // fire_giant); die 3 Dune Stalker (FF, no registry def); die 4
        // Lammasu (MM1 lammasu); die 5 Purple Worm (MM1 purple_worm); die 6
        // Fly, Giant Horse- (MM2 fly_horsefly); die 7 Scorpion, Giant or Huge
        // (MM1 giant_scorpion); die 8 Dustdigger (MM2 dustdigger); die 9
        // Camel, Bactrian (MM1 camel_bactrian); die 10 Spider, Large or Huge
        // (MM1 large_spider); die 11 Jackal (MM1 jackal); die 12 Vulture,
        // Normal (MM2 vulture_ordinary); die 13 Scorpion, Large (MM2
        // scorpion_large); die 14 Ogre (MM1 ogre); die 15 Snake, Giant
        // Poisonous (MM1 poisonous_snake); die 16 Ant Lion, Giant (MM2
        // ant_lion); die 17 Man, Dervish (MM1 dervish); die 18 Thunderherder
        // (MM2 thunderherder); die 19 Lamia (MM1 lamia); die 20 Wind Walker
        // (MM1 wind_walker)
        int CEncoTW6[19][3] = {
            {2,1,0},
            {3,3,0},
            {4,1,0},
            {5,1,0},
            {6,2,0},
            {7,1,0},
            {8,2,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,2,0},
            {13,2,0},
            {14,1,0},
            {15,1,0},
            {16,2,0},
            {17,1,0},
            {18,2,0},
            {19,1,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoTW6Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoTW6Die(b);
            vals[1] = mm2encoTW6Src(b);
            vals[2] = mm2encoTW6Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoTW6[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE CIVILIZED MOUNTAINS GRID: the 19 die rows 2-20, one
        // row per die (die, source, special). Rows: die 2 Dragonnel (MM2
        // dragonnel); die 3 Spider, Giant (MM1 giant_spider); die 4 Minotaur
        // (MM1 minotaur); die 5 Ghouls with Ghast (MM1 ghoul); die 6 Dragon,
        // Earth (FF, no registry def); die 7 Gnoll (MM1 gnoll); die 8 Bugbear
        // (MM1 bugbear); die 9 Man, Bandit (MM1 bandit); die 10 Character
        // Party (the Character Party row (the DMG subtable)); die 11 Dwarf,
        // Mountain (MM1 dwarf); die 12 Ogre (MM1 ogre); die 13 Spider, Large
        // (MM1 large_spider); die 14 Goblins (MM1 goblin); die 15 Man, Patrol
        // (the Patrol men row (no print def)); die 16 Norker (FF, no registry
        // def); die 17 Spider, Phase (MM1 phase_spider); die 18 Vampire (MM1
        // vampire); die 19 Rakshasa (MM1 rakshasa); die 20 Ki-rin (MM1
        // ki_rin)
        int CEncoTC1[19][3] = {
            {2,2,0},
            {3,1,0},
            {4,1,0},
            {5,1,0},
            {6,3,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,0,1},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,0,3},
            {16,3,0},
            {17,1,0},
            {18,1,0},
            {19,1,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoTC1Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoTC1Die(b);
            vals[1] = mm2encoTC1Src(b);
            vals[2] = mm2encoTC1Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoTC1[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE CIVILIZED HILLS AND ROUGH TERRAIN GRID: the 19 die
        // rows 2-20, one row per die (die, source, special). Rows: die 2
        // Hollyphant (MM2 hollyphant); die 3 Obliviax (MM2 obliviax); die 4
        // Scarecrow (FF, no registry def); die 5 Snyad (FF, no registry def);
        // die 6 Beetle, Giant Fire (MM1 fire_beetle); die 7 Basilisk (MM1
        // basilisk); die 8 Killmoulis (FF, no registry def); die 9 Man,
        // Bandit (MM1 bandit); die 10 Lycanthrope, Werewolf (MM1 werewolf);
        // die 11 Man, Merchant (MM1 merchant); die 12 Man, Patrol (the Patrol
        // men row (no print def)); die 13 Wolf (MM1 wolf); die 14 Gnoll (MM1
        // gnoll); die 15 Hobgoblin (MM1 hobgoblin); die 16 Jackal (MM1
        // jackal); die 17 Pedipalp, Large or Huge (MM2 pedipalp_large); die
        // 18 Wolf, Dire (MM1 dire_wolf); die 19 Jackalwere (MM1 jackalwere);
        // die 20 Huecuva (FF, no registry def)
        int CEncoTC2[19][3] = {
            {2,2,0},
            {3,2,0},
            {4,3,0},
            {5,3,0},
            {6,1,0},
            {7,1,0},
            {8,3,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,0,3},
            {13,1,0},
            {14,1,0},
            {15,1,0},
            {16,1,0},
            {17,2,0},
            {18,1,0},
            {19,1,0},
            {20,3,0},
            };
        for (int b = 0;
             b < mm2encoTC2Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoTC2Die(b);
            vals[1] = mm2encoTC2Src(b);
            vals[2] = mm2encoTC2Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoTC2[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE CIVILIZED FOREST GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Vampire (MM1 vampire);
        // die 3 Bulette (MM1 bulette); die 4 Centipede, Megalo- (MM2
        // centipede_megalo); die 5 Ankheg (MM1 ankheg); die 6 Man, Berserker
        // (MM1 berserker); die 7 Troll (MM1 troll); die 8 Leprechaun (MM1
        // leprechaun); die 9 Beetle, Giant Stag (MM1 stag_beetle); die 10
        // Bull (MM1 bull); die 11 Man, Bandit (MM1 bandit); die 12 Spider,
        // Large (MM1 large_spider); die 13 Man, Patrol (the Patrol men row
        // (no print def)); die 14 Character Party (the Character Party row
        // (the DMG subtable)); die 15 Man, Pilgrim (MM1 pilgrim); die 16
        // Thessalhydra (MM2 thessalhydra); die 17 Spider, Giant (MM1
        // giant_spider); die 18 Demon, Bar-lgura (MM2 bar_lgura); die 19
        // Norker (FF, no registry def); die 20 Shedu, Greater (MM1 shedu)
        int CEncoTC3[19][3] = {
            {2,1,0},
            {3,1,0},
            {4,2,0},
            {5,1,0},
            {6,1,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,0,3},
            {14,0,1},
            {15,1,0},
            {16,2,0},
            {17,1,0},
            {18,2,0},
            {19,3,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoTC3Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoTC3Die(b);
            vals[1] = mm2encoTC3Src(b);
            vals[2] = mm2encoTC3Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoTC3[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE CIVILIZED SWAMP AND MARSH GRID: the 19 die rows 2-20,
        // one row per die (die, source, special). Rows: die 2 Kelpie (FF, no
        // registry def); die 3 Crayfish, Giant (MM1 giant_crayfish); die 4
        // Goblin (MM1 goblin); die 5 Frog, Poisonous (MM1 poisonous_frog);
        // die 6 Boar, Wild (MM1 wild_boar); die 7 Lycanthrope, Wererat (MM1
        // wererat); die 8 Man, Patrol (the Patrol men row (no print def));
        // die 9 Man, Bandit (MM1 bandit); die 10 Rat, Normal or Giant (MM2
        // rat_ordinary); die 11 Centipede, Giant or Huge (MM1
        // giant_centipede); die 12 Vulture, Normal (MM2 vulture_ordinary);
        // die 13 Spider, Giant or Huge (MM1 giant_spider); die 14 Vulture,
        // Giant (MM2 vulture_giant); die 15 Basilisk (MM1 basilisk); die 16
        // Man, Berserker (MM1 berserker); die 17 Crane, Giant (MM2
        // crane_giant); die 18 Crab, Giant (MM1 giant_crab); die 19 Mud-man
        // (MM2 mud_man); die 20 Zygom (MM2 zygom)
        int CEncoTC4[19][3] = {
            {2,3,0},
            {3,1,0},
            {4,1,0},
            {5,1,0},
            {6,1,0},
            {7,1,0},
            {8,0,3},
            {9,1,0},
            {10,2,0},
            {11,1,0},
            {12,2,0},
            {13,1,0},
            {14,2,0},
            {15,1,0},
            {16,1,0},
            {17,2,0},
            {18,1,0},
            {19,2,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoTC4Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoTC4Die(b);
            vals[1] = mm2encoTC4Src(b);
            vals[2] = mm2encoTC4Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoTC4[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE CIVILIZED PLAINS AND SCRUB GRID: the 19 die rows
        // 2-20, one row per die (die, source, special). Rows: die 2 Lammasu,
        // Greater (MM2 ); die 3 Ghost (MM1 ghost); die 4 Lycanthrope, Wererat
        // (MM1 wererat); die 5 Castle (the Castle row (the structure row));
        // die 6 Ankheg (MM1 ankheg); die 7 Owl (MM2 owl); die 8 Man, Pilgrim
        // (MM1 pilgrim); die 9 Men, Bandit (MM1 bandit); die 10 Cattle, Wild
        // (MM1 wild_cattle); die 11 Man, Merchant (MM1 merchant); die 12
        // Falcon, Small (MM2 falcon_small); die 13 Man, Patrol (the Patrol
        // men row (no print def)); die 14 Character Party (the Character
        // Party row (the DMG subtable)); die 15 Bugbear (MM1 bugbear); die 16
        // Halfling (MM1 halfling); die 17 Man, Dervish (MM1 dervish); die 18
        // Goblin (MM1 goblin); die 19 Oliphant (MM2 oliphant); die 20
        // Quasi-elemental, Lightning (MM2 quasi_elemental_lightning)
        int CEncoTC5[19][3] = {
            {2,2,0},
            {3,1,0},
            {4,1,0},
            {5,0,2},
            {6,1,0},
            {7,2,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,2,0},
            {13,0,3},
            {14,0,1},
            {15,1,0},
            {16,1,0},
            {17,1,0},
            {18,1,0},
            {19,2,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoTC5Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoTC5Die(b);
            vals[1] = mm2encoTC5Src(b);
            vals[2] = mm2encoTC5Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoTC5[b][c])
                    ++bad;
            }
        }
        // THE TEMPERATE CIVILIZED DESERT GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Dragon, Copper (MM1
        // copper_dragon); die 3 Hellhound (MM1 hell_hound); die 4 Bat (MM2
        // bat_ordinary); die 5 Goblins & Barghest (MM1 goblin); die 6 Man,
        // Dervish (MM1 dervish); die 7 Lion (MM1 lion); die 8 Character Party
        // (the Character Party row (the DMG subtable)); die 9 Man, Bandit
        // (MM1 bandit); die 10 Man, Merchant (MM1 merchant); die 11 Spider,
        // Huge or Large (MM1 huge_spider); die 12 Camel, Bactrian (MM1
        // camel_bactrian); die 13 Jackal (MM1 jackal); die 14 Man, Pilgrim
        // (MM1 pilgrim); die 15 Osquip (FF, no registry def); die 16 Falcon,
        // Large (MM2 falcon_large); die 17 Pedipalp, Large or Huge (MM2
        // pedipalp_large); die 18 Vortex (FF, no registry def); die 19
        // Griffon (MM1 griffon); die 20 Demon, Type I (MM1 type_i_vrock)
        int CEncoTC6[19][3] = {
            {2,1,0},
            {3,1,0},
            {4,2,0},
            {5,1,0},
            {6,1,0},
            {7,1,0},
            {8,0,1},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,3,0},
            {16,2,0},
            {17,2,0},
            {18,3,0},
            {19,1,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoTC6Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoTC6Die(b);
            vals[1] = mm2encoTC6Src(b);
            vals[2] = mm2encoTC6Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoTC6[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL WILDERNESS MOUNTAINS GRID: the 19 die rows 2-20, one
        // row per die (die, source, special). Rows: die 2 Aarakocra (FF, no
        // registry def); die 3 Dragon, Black (MM1 black_dragon); die 4 Wind
        // Walker (MM1 wind_walker); die 5 Dragon, Red (MM1 red_dragon); die 6
        // Caveman (MM1 caveman); die 7 Dragon, Copper (MM1 copper_dragon);
        // die 8 Bugbear (MM1 bugbear); die 9 Spider, Large (MM1
        // large_spider); die 10 Pterodactyl, Small (no print def determined
        // (flagged)); die 11 Dog, Wild (MM1 wild_dog); die 12 Bat (MM2
        // bat_ordinary); die 13 Ogre (MM1 ogre); die 14 Giant, Fire (MM1
        // fire_giant); die 15 Manticore (MM1 manticore); die 16 Firedrake
        // (FF, no registry def); die 17 Giant, Storm (MM1 storm_giant); die
        // 18 Pyrolisk (MM2 pyrolisk); die 19 Ogre Magi (MM1 ogre_magi); die
        // 20 Grue, Elemental (MM2 chaggrin)
        int CEncoRW1[19][3] = {
            {2,3,0},
            {3,1,0},
            {4,1,0},
            {5,1,0},
            {6,1,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,0,0},
            {11,1,0},
            {12,2,0},
            {13,1,0},
            {14,1,0},
            {15,1,0},
            {16,3,0},
            {17,1,0},
            {18,2,0},
            {19,1,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoRW1Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoRW1Die(b);
            vals[1] = mm2encoRW1Src(b);
            vals[2] = mm2encoRW1Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoRW1[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL WILDERNESS HILLS AND ROUGH TERRAIN GRID: the 19 die
        // rows 2-20, one row per die (die, source, special). Rows: die 2
        // Zorbo (MM2 zorbo); die 3 Hangman Tree (MM2 hangman_tree); die 4
        // Firenewt (FF, no registry def); die 5 Bee, Giant Bumble- (MM2
        // bee_bumblebee); die 6 Ant, Giant (MM1 giant_ant); die 7 Witherweed
        // (FF, no registry def); die 8 Kenku (FF, no registry def); die 9
        // Cattle, Wild (MM1 wild_cattle); die 10 Giant, Hill (MM1
        // hill_giant); die 11 Lycanthrope, Werewolf (MM1 werewolf); die 12
        // Spider, Large (MM1 large_spider); die 13 Wolf (MM1 wolf); die 14
        // Basilisk (MM1 basilisk); die 15 Scorpion, Large (MM2
        // scorpion_large); die 16 Hyena (MM1 hyena); die 17 Sphinx, Hieraco-
        // (MM1 hieracosphinx); die 18 Assassin Bug (FF, no registry def); die
        // 19 Axebeak (MM1 axe_beak); die 20 Vilstrak (MM2 vilstrak)
        int CEncoRW2[19][3] = {
            {2,2,0},
            {3,2,0},
            {4,3,0},
            {5,2,0},
            {6,1,0},
            {7,3,0},
            {8,3,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,2,0},
            {16,1,0},
            {17,1,0},
            {18,3,0},
            {19,1,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoRW2Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoRW2Die(b);
            vals[1] = mm2encoRW2Src(b);
            vals[2] = mm2encoRW2Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoRW2[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL WILDERNESS FOREST GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Dragon, Green (MM1
        // green_dragon); die 3 Bloodthorn (MM2 bloodthorn); die 4 Grippli
        // (MM2 grippli); die 5 Ettercap (FF, no registry def); die 6
        // Baluchitherium (MM1 baluchitherium); die 7 Ophidian (MM2 ophidian);
        // die 8 Kobold (MM1 kobold); die 9 Baboon (MM1 baboon); die 10 Boar,
        // Warthog (MM1 warthog); die 11 Flightless Bird (MM1
        // flightless_bird); die 12 Elephant, African (MM1 elephant_african);
        // die 13 Ogre (MM1 ogre); die 14 Beetle, Giant Rhino (MM1
        // rhinoceros_beetle); die 15 Jaguar (MM1 jaguar); die 16 Basidirond
        // (MM2 basidirond); die 17 Buckawn (MM2 buckawn); die 18 Forester's
        // Bane (MM2 foresters_bane); die 19 Choke Creeper (MM2
        // choke_creeper); die 20 Stegocentipede (MM2 stegocentipede)
        int CEncoRW3[19][3] = {
            {2,1,0},
            {3,2,0},
            {4,2,0},
            {5,3,0},
            {6,1,0},
            {7,2,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,1,0},
            {16,2,0},
            {17,2,0},
            {18,2,0},
            {19,2,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoRW3Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoRW3Die(b);
            vals[1] = mm2encoRW3Src(b);
            vals[2] = mm2encoRW3Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoRW3[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL WILDERNESS SWAMP AND MARSH GRID: the 19 die rows 2-20,
        // one row per die (die, source, special). Rows: die 2 Basilisk,
        // Greater (MM2 basilisk_greater); die 3 Grabman (FF, no registry
        // def); die 4 Shambling Mound (MM1 shambling_mound); die 5 Mongrelman
        // (MM2 mongrelman); die 6 Muckdweller (MM2 muckdweller); die 7
        // Basilisk (MM1 basilisk); die 8 Meazel (FF, no registry def); die 9
        // Centipede, Giant or Huge (MM1 giant_centipede); die 10 Scorpion,
        // Large (MM2 scorpion_large); die 11 Spider, Huge (MM1 huge_spider);
        // die 12 Toad, Giant (MM1 giant_toad); die 13 Rat, Normal or Giant
        // (MM2 rat_ordinary); die 14 Sundew, Giant (MM2 sundew_giant); die 15
        // Troll (MM1 troll); die 16 Caterwaul (FF, no registry def); die 17
        // Cifal (FF, no registry def); die 18 Dragonfly, Giant (MM2
        // giant_dragonfly); die 19 Naga, Guardian (MM1 guardian_naga); die 20
        // Dragon, Black (MM1 black_dragon)
        int CEncoRW4[19][3] = {
            {2,2,0},
            {3,3,0},
            {4,1,0},
            {5,2,0},
            {6,2,0},
            {7,1,0},
            {8,3,0},
            {9,1,0},
            {10,2,0},
            {11,1,0},
            {12,1,0},
            {13,2,0},
            {14,2,0},
            {15,1,0},
            {16,3,0},
            {17,3,0},
            {18,2,0},
            {19,1,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoRW4Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoRW4Die(b);
            vals[1] = mm2encoRW4Src(b);
            vals[2] = mm2encoRW4Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoRW4[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL WILDERNESS PLAINS AND SCRUB GRID: the 19 die rows
        // 2-20, one row per die (die, source, special). Rows: die 2 Ascomoid
        // (MM2 ascomoid); die 3 Cockatrice (MM1 cockatrice); die 4 Wyvern
        // (MM1 wyvern); die 5 Thri-kreen (MM2 thri_kreen); die 6 Hybsil (MM2
        // hybsil); die 7 Dakon (FF, no registry def); die 8 Owl (MM2 owl);
        // die 9 Baboon (MM1 baboon); die 10 Boar, Wild (MM1 wild_boar); die
        // 11 Cattle, Wild (MM1 wild_cattle); die 12 Ogre (MM1 ogre); die 13
        // Scorpion, Large (MM2 scorpion_large); die 14 Man, Nomad (MM1
        // dervish); die 15 Ghoul (MM1 ghoul); die 16 Cheetah (MM2 cheetah);
        // die 17 Axebeak (MM1 axe_beak); die 18 Giant, Hill (MM1 hill_giant);
        // die 19 Dragon, Blue (MM1 blue_dragon); die 20 Deva, Movanic (MM2
        // movanic_deva)
        int CEncoRW5[19][3] = {
            {2,2,0},
            {3,1,0},
            {4,1,0},
            {5,2,0},
            {6,2,0},
            {7,3,0},
            {8,2,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,2,0},
            {14,1,0},
            {15,1,0},
            {16,2,0},
            {17,1,0},
            {18,1,0},
            {19,1,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoRW5Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoRW5Die(b);
            vals[1] = mm2encoRW5Src(b);
            vals[2] = mm2encoRW5Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoRW5[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL WILDERNESS DESERT GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Giant, Fire (MM1
        // fire_giant); die 3 Boalisk (MM2 boalisk); die 4 Sphinx, Gyno- (MM1
        // gynosphinx); die 5 Sandman (FF, no registry def); die 6 Pudding,
        // Deadly (Dun) (MM2 pudding_dun); die 7 Kenku (FF, no registry def);
        // die 8 Flightless Bird (MM1 flightless_bird); die 9 Camel (MM1
        // camel_dromedary); die 10 Hyena (MM1 hyena); die 11 Jackal (MM1
        // jackal); die 12 Scorpion, Giant (MM1 giant_scorpion); die 13
        // Spider, Large or Huge (MM1 large_spider); die 14 Dustdigger (MM2
        // dustdigger); die 15 Scorpion, Large or Huge (MM2 scorpion_large);
        // die 16 Ant Lion, Giant (MM2 ant_lion); die 17 Moon Dog (MM2
        // moon_dog); die 18 Dune Stalker (FF, no registry def); die 19
        // Formian (MM2 formian_worker); die 20 Jann (MM2 jann)
        int CEncoRW6[19][3] = {
            {2,1,0},
            {3,2,0},
            {4,1,0},
            {5,3,0},
            {6,2,0},
            {7,3,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,2,0},
            {15,2,0},
            {16,2,0},
            {17,2,0},
            {18,3,0},
            {19,2,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoRW6Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoRW6Die(b);
            vals[1] = mm2encoRW6Src(b);
            vals[2] = mm2encoRW6Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoRW6[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL CIVILIZED MOUNTAINS GRID: the 19 die rows 2-20, one
        // row per die (die, source, special). Rows: die 2 Xaren (MM2 xaren);
        // die 3 Castle (the Castle row (the structure row)); die 4 Lammasu
        // (MM1 lammasu); die 5 Norker (FF, no registry def); die 6 Quaggoth
        // (FF, no registry def); die 7 Character Party (the Character Party
        // row (the DMG subtable)); die 8 Bugbear (MM1 bugbear); die 9 Man,
        // Bandit (MM1 bandit); die 10 Bat (MM2 bat_ordinary); die 11 Ogre
        // (MM1 ogre); die 12 Vulture, Normal (MM2 vulture_ordinary); die 13
        // Spider, Large (MM1 large_spider); die 14 Man, Patrol (the Patrol
        // men row (no print def)); die 15 Man, Pilgrim (MM1 pilgrim); die 16
        // Dwarf, Hill (MM1 dwarf); die 17 Dragon, Earth (FF, no registry
        // def); die 18 Rothe (FF, no registry def); die 19 Lycanthrope,
        // Wererat (MM1 wererat); die 20 Hell Hound (MM1 hell_hound)
        int CEncoRC1[19][3] = {
            {2,2,0},
            {3,0,2},
            {4,1,0},
            {5,3,0},
            {6,3,0},
            {7,0,1},
            {8,1,0},
            {9,1,0},
            {10,2,0},
            {11,1,0},
            {12,2,0},
            {13,1,0},
            {14,0,3},
            {15,1,0},
            {16,1,0},
            {17,3,0},
            {18,3,0},
            {19,1,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoRC1Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoRC1Die(b);
            vals[1] = mm2encoRC1Src(b);
            vals[2] = mm2encoRC1Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoRC1[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL CIVILIZED HILLS AND ROUGH TERRAIN GRID: the 19 die
        // rows 2-20, one row per die (die, source, special). Rows: die 2
        // Penanggalan (FF, no registry def); die 3 Lycanthrope, Wereboar (MM1
        // wereboar); die 4 Beetle, Fire (MM1 fire_beetle); die 5 Boar, Wild
        // (MM1 wild_boar); die 6 Falcon, Large (MM2 falcon_large); die 7 Man,
        // Pilgrim (MM1 pilgrim); die 8 Pseudo-undead, Ghoul (MM2
        // pseudo_undead); die 9 Cattle, Wild (MM1 wild_cattle); die 10 Dwarf,
        // Hill (MM1 dwarf); die 11 Lycanthrope, Werewolf (MM1 werewolf); die
        // 12 Man, Patrol (the Patrol men row (no print def)); die 13 Man,
        // Merchant (MM1 merchant); die 14 Character Party (the Character
        // Party row (the DMG subtable)); die 15 Hobgoblin (MM1 hobgoblin);
        // die 16 Oliphant (MM2 oliphant); die 17 Pedipalp, Huge and Large
        // (MM2 pedipalp_huge); die 18 Shedu (MM1 shedu); die 19 Rakshasa (MM1
        // rakshasa); die 20 Lammasu, Greater (MM2 )
        int CEncoRC2[19][3] = {
            {2,3,0},
            {3,1,0},
            {4,1,0},
            {5,1,0},
            {6,2,0},
            {7,1,0},
            {8,2,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,0,3},
            {13,1,0},
            {14,0,1},
            {15,1,0},
            {16,2,0},
            {17,2,0},
            {18,1,0},
            {19,1,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoRC2Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoRC2Die(b);
            vals[1] = mm2encoRC2Src(b);
            vals[2] = mm2encoRC2Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoRC2[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL CIVILIZED FOREST GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Shadow Demon (FF, no
        // registry def); die 3 Snake, Giant Amphisbaena (MM1
        // amphisbaena_snake); die 4 Goblin (MM1 goblin); die 5 Hobgoblin (MM1
        // hobgoblin); die 6 Cattle, Wild (MM1 wild_cattle); die 7 Man,
        // Merchant (MM1 merchant); die 8 Stirge (MM1 stirge); die 9 Man,
        // Bandit (MM1 bandit); die 10 Elephant (MM1 elephant); die 11 Herd
        // Animal (MM1 herd_animal); die 12 Man, Patrol (the Patrol men row
        // (no print def)); die 13 Bull (MM1 bull); die 14 Character Party
        // (the Character Party row (the DMG subtable)); die 15 Elf, Wood (MM1
        // elf); die 16 Shadow (MM1 shadow); die 17 Jackal (MM1 jackal); die
        // 18 Halfling (MM1 halfling); die 19 Centipede, Megalo- (MM2
        // centipede_megalo); die 20 Revenant (FF, no registry def)
        int CEncoRC3[19][3] = {
            {2,3,0},
            {3,1,0},
            {4,1,0},
            {5,1,0},
            {6,1,0},
            {7,1,0},
            {8,1,0},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,0,3},
            {13,1,0},
            {14,0,1},
            {15,1,0},
            {16,1,0},
            {17,1,0},
            {18,1,0},
            {19,2,0},
            {20,3,0},
            };
        for (int b = 0;
             b < mm2encoRC3Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoRC3Die(b);
            vals[1] = mm2encoRC3Src(b);
            vals[2] = mm2encoRC3Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoRC3[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL CIVILIZED SWAMP AND MARSH GRID: the 19 die rows 2-20,
        // one row per die (die, source, special). Rows: die 2 Haunt (MM2
        // haunt); die 3 Crayfish, Giant (MM1 giant_crayfish); die 4 Mud-man
        // (MM2 mud_man); die 5 Frog, Poisonous (MM1 poisonous_frog); die 6
        // Man, Patrol (the Patrol men row (no print def)); die 7 Lion (MM1
        // lion); die 8 Crane, Giant (MM2 crane_giant); die 9 Man, Bandit (MM1
        // bandit); die 10 Centipede, Giant or Huge (MM1 giant_centipede); die
        // 11 Rat, Normal or Giant (MM2 rat_ordinary); die 12 Spider, Huge or
        // Large (MM1 huge_spider); die 13 Toad, Giant (MM1 giant_toad); die
        // 14 Lycanthrope, Wererat (MM1 wererat); die 15 Ghoul (MM1 ghoul);
        // die 16 Vapor Rat (MM2 rat_vapor); die 17 Zombie, Juju (MM2
        // zombie_juju); die 18 Skeleton, Animal (MM2 skeleton_animal); die 19
        // Vampire (MM1 vampire); die 20 Shade (MM2 shade)
        int CEncoRC4[19][3] = {
            {2,2,0},
            {3,1,0},
            {4,2,0},
            {5,1,0},
            {6,0,3},
            {7,1,0},
            {8,2,0},
            {9,1,0},
            {10,1,0},
            {11,2,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,1,0},
            {16,2,0},
            {17,2,0},
            {18,2,0},
            {19,1,0},
            {20,2,0},
            };
        for (int b = 0;
             b < mm2encoRC4Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoRC4Die(b);
            vals[1] = mm2encoRC4Src(b);
            vals[2] = mm2encoRC4Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoRC4[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL CIVILIZED PLAINS AND SCRUB GRID: the 19 die rows 2-20,
        // one row per die (die, source, special). Rows: die 2 Tween (FF, no
        // registry def); die 3 Zygom (MM2 zygom); die 4 Snake, Giant
        // Amphisbaena (MM1 amphisbaena_snake); die 5 Jackalwere (MM1
        // jackalwere); die 6 Ankheg (MM1 ankheg); die 7 Lion (MM1 lion); die
        // 8 Character Party (the Character Party row (the DMG subtable)); die
        // 9 Man, Bandit (MM1 bandit); die 10 Man, Patrol (the Patrol men row
        // (no print def)); die 11 Man, Merchant (MM1 merchant); die 12 Herd
        // Animal (MM1 herd_animal); die 13 Jackal (MM1 jackal); die 14
        // Pilgrims (MM1 pilgrim); die 15 Snake, Poisonous (MM1
        // poisonous_snake); die 16 Troll (MM1 troll); die 17 Shedu (MM1
        // shedu); die 18 Basilisk (MM1 basilisk); die 19 Disenchanter (FF, no
        // registry def); die 20 Dragon, Gold (MM1 gold_dragon)
        int CEncoRC5[19][3] = {
            {2,3,0},
            {3,2,0},
            {4,1,0},
            {5,1,0},
            {6,1,0},
            {7,1,0},
            {8,0,1},
            {9,1,0},
            {10,0,3},
            {11,1,0},
            {12,1,0},
            {13,1,0},
            {14,1,0},
            {15,1,0},
            {16,1,0},
            {17,1,0},
            {18,1,0},
            {19,3,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoRC5Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoRC5Die(b);
            vals[1] = mm2encoRC5Src(b);
            vals[2] = mm2encoRC5Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoRC5[b][c])
                    ++bad;
            }
        }
        // THE TROPICAL CIVILIZED DESERT GRID: the 19 die rows 2-20, one row
        // per die (die, source, special). Rows: die 2 Thunderherder (MM2
        // thunderherder); die 3 Griffon (MM1 griffon); die 4 Vortex (FF, no
        // registry def); die 5 Jermlaine (FF, no registry def); die 6 Dervish
        // (MM1 dervish); die 7 Snake, Constrictor (MM1 constrictor_snake);
        // die 8 Character Party (the Character Party row (the DMG subtable));
        // die 9 Man, Bandit (MM1 bandit); die 10 Man, Merchant (MM1
        // merchant); die 11 Jackal (MM1 jackal); die 12 Camel (MM1
        // camel_dromedary); die 13 Vulture (MM2 vulture_ordinary); die 14
        // Osquip (FF, no registry def); die 15 Snake, Poisonous (MM1
        // poisonous_snake); die 16 Man, Berserker (MM1 berserker); die 17
        // Snake, Giant Constrictor (MM1 constrictor_snake); die 18
        // Lycanthrope, Weretiger (MM1 weretiger); die 19 Jann (MM2 jann); die
        // 20 Demon, Succubus (MM1 succubus)
        int CEncoRC6[19][3] = {
            {2,2,0},
            {3,1,0},
            {4,3,0},
            {5,3,0},
            {6,1,0},
            {7,1,0},
            {8,0,1},
            {9,1,0},
            {10,1,0},
            {11,1,0},
            {12,1,0},
            {13,2,0},
            {14,3,0},
            {15,1,0},
            {16,1,0},
            {17,1,0},
            {18,1,0},
            {19,2,0},
            {20,1,0},
            };
        for (int b = 0;
             b < mm2encoRC6Count();
             ++b) {
            int vals[3];
            vals[0] = mm2encoRC6Die(b);
            vals[1] = mm2encoRC6Src(b);
            vals[2] = mm2encoRC6Special(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEncoRC6[b][c])
                    ++bad;
            }
        }
        // the census walk (the 36-grid arithmetic)
    if (mm2encoTotalRows() != mm2encoTableCount() * mm2encoRowsPerTable()
            || mm2encoTableCount() != 36
            || mm2encoRowsPerTable() != 19
        )
            ++bad;
        // the area-terrain pairing
    if (mm2encoAreaCount() * mm2encoTerrainCount() != mm2encoTableCount()
            || mm2encoAreaCount() != 6
        )
            ++bad;
        // the die range
    if (mm2encoDieMin() != 2
            || mm2encoDieMax() != 20
        )
            ++bad;
        // the party-row arithmetic (the 17 rows on 16 grids)
    if (mm2encoCharacterPartyRows() != mm2encoGridsWithPartyRow() + 1
        )
            ++bad;
        // the cold civilized desert double party row
    if (mm2encoColdCivDesertPartyRows() != 2
        )
            ++bad;
        // the structure, patrol and unresolved rows
    if (mm2encoStructureRows() != 5
            || mm2encoPatrolRows() != 15
            || mm2encoUnresolvedRows() != 1
        )
            ++bad;
        // the source census sums to the total
    if (mm2encoMm1SourceRows() + mm2encoMm2SourceRows() +
        mm2encoFfSourceRows() + mm2encoCharacterPartyRows() +
        mm2encoStructureRows() + mm2encoPatrolRows() + mm2encoUnresolvedRows()
        != mm2encoTotalRows()
        )
            ++bad;
        // the walk-key census (the MM1 and MM2 defs the registry owns)
    if (mm2encoWalkKeyRows() != mm2encoMm1SourceRows() +
        mm2encoMm2SourceRows() + ffpOutCellsRewired() +
        ffsOutCellsRewired() + fftOutCellsRewired()
        )
            ++bad;
        printf("R817 MM2 outdoor encounter grids audit: bad %d\n", bad);
        if (bad) return 1;
    }
