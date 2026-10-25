    // ---- R816 MM2 dungeon encounter grids audit ----
    // THE MM2 DUNGEON ENCOUNTER TABLES WALK - the ten Monster Level grids
    // (the tables that ride with the DMG Appendix C tables; the print pp.
    // 133-134), every die row 2-20 pinned as the five-cell grid (die, source,
    // number min, number max, special). THE SETTLED READS (the two
    // 1st-edition word layers the voices, the merged index and the registry
    // keys the cross-checks): the Bowler, Norker, Thoqqua (the index Rock
    // worm), Nupperibo (an MM2 demon, the registry def source MM2 over the
    // scan-A FF misread) and Grimlock (the scan-A word layer garbage, the
    // scan-B clean 2-12) all settle against the index and registry; the
    // scan-A Pseudowraith reads Pseudo-wraith (the scan-B hyphen), the MM2
    // pseudo-undead family def the walk key; the Daemon Mezzo- row (the
    // scan-A Mono- the misread - the mezzodaemon is the FF daemon, monodaemon
    // is not a print creature); the two word layers disagree on the Land
    // Lamprey cell (scan A 2-8, scan B 2-6) - the scan-A read pins, flagged
    // for the physical copy; the Chasme cell (scan A 1-2, scan B 1-3) settles
    // 1-3, the registry def noAppearing 1-3 or 1-6 corroborating the scan-B
    // read; the Green Slime number cell is dropped by BOTH word layers - the
    // MM1 registry def noAppearing 1-6 the settle voice, flagged for the
    // physical copy; the Level VI die 15/16 duplicate (the Troll row) settles
    // 15 Troll by the scan-B column read; the character-party rows carry no
    // source and no number (the DMG subtable reference); the four Level X
    // unique rows (the demon prince, the elemental prince of evil, Charon and
    // the devil duke) carry the court bullet instead of a number - the Orcus,
    // Tiamat and Anthraxus court examples pinned as bools; the dragon age
    // cells read Anc., Anc. O. and Anc. V.O. in both word layers (the Ancient
    // spell-outs on Level VIII and X); the Daemon Charon rows walk the
    // charonadaemon key (the lesser daemon, not the unique boatman); the
    // table heads print MONSTER LEVEL I through X with the Level VII
    // continuation heading (both scans the VII cont. reading, the scan-A word
    // layer VI cont. the single-glyph loss).
    {
        using namespace rules;
        int bad = 0;
    if (mm2encdRound() != 816
            || mm2encdTableCount() != 10
            || mm2encdRowsPerTable() != 19
            || mm2encdTotalRows() != 190
            || mm2encdDieMin() != 2
            || mm2encdDieMax() != 20
            || mm2encdCharacterPartyRows() != 10
            || mm2encdUniqueCourtRows() != 4
            || mm2encdMm1SourceRows() != 89
            || mm2encdMm2SourceRows() != 63
            || mm2encdFfSourceRows() != 26
            || mm2encdAllSourceRows() != 2
            || mm2encdRegistryFloor() != 809
            || mm2encdWalkKeyRows() != 170
            || mm2encdPartyDieD1() != 11
            || mm2encdPartyDieD2() != 11
            || mm2encdPartyDieD3() != 9
            || mm2encdPartyDieD4() != 9
            || mm2encdPartyDieD5() != 10
            || mm2encdPartyDieD6() != 11
            || mm2encdPartyDieD7() != 9
            || mm2encdPartyDieD8() != 9
            || mm2encdPartyDieD9() != 9
            || mm2encdPartyDieD10() != 13
            || mm2encdD1Count() != 19
            || mm2encdD2Count() != 19
            || mm2encdD3Count() != 19
            || mm2encdD4Count() != 19
            || mm2encdD5Count() != 19
            || mm2encdD6Count() != 19
            || mm2encdD7Count() != 19
            || mm2encdD8Count() != 19
            || mm2encdD9Count() != 19
            || mm2encdD10Count() != 19
            || !mm2encdUsesD8PlusD12()
            || !mm2encdRangeTwoToTwenty()
            || !mm2encdConjoinsDmgAppendixC()
            || !mm2encdCoversMm1Mm2AndFf()
            || !mm2encdNotACompleteListing()
            || !mm2encdDmMayModifyTables()
            || !mm2encdSeeCreatingTablesSection()
            || !mm2encdPartyRowRollsDmgSubtable()
            || !mm2encdUniqueCourtRule()
            || !mm2encdCourtOrcusWithUndead()
            || !mm2encdCourtTiamatWithAbishai()
            || !mm2encdCourtAnthraxusWithDaemons()
            || !mm2encdUniqueRowsCarryNoNumber()
        )
            ++bad;
        // THE MONSTER LEVEL I GRID: the 19 die rows 2-20, one row per die
        // (die, source, number min, number max, special). Rows: Al-miraj,
        // Webbird, Bullywug, Pedipalp, Large, Bowler, Bat, Giant, Goblin,
        // Men, Bandit, Bat, Character Party, Orc, Rat, Giant, Kobold,
        // Piercer, Skeleton, Norker, Vulchling, Gnome, Demon, Nupperibo
        int CEncD1[19][5] = {
            {2,3,1,4,0},
            {3,2,2,12,0},
            {4,3,3,18,0},
            {5,2,2,12,0},
            {6,2,1,3,0},
            {7,3,1,4,0},
            {8,1,6,15,0},
            {9,1,5,15,0},
            {10,2,2,20,0},
            {11,0,0,0,1},
            {12,1,7,12,0},
            {13,1,5,20,0},
            {14,1,6,17,0},
            {15,1,1,4,0},
            {16,1,1,4,0},
            {17,3,2,8,0},
            {18,2,2,12,0},
            {19,1,5,15,0},
            {20,2,1,3,0},
            };
        for (int b = 0;
             b < mm2encdD1Count();
             ++b) {
            int vals[5];
            vals[0] = mm2encdD1Die(b);
            vals[1] = mm2encdD1Src(b);
            vals[2] = mm2encdD1NumMin(b);
            vals[3] = mm2encdD1NumMax(b);
            vals[4] = mm2encdD1Special(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CEncD1[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL II GRID: the 19 die rows 2-20, one row per die
        // (die, source, number min, number max, special). Rows: Azer,
        // Duergar, Coffer Corpse, Gas Spore, Lizard Man, Gnoll, Land Lamprey,
        // Centipede, Giant, Toad, Giant, Character Party, Troglodyte,
        // Centipede, Huge, Grimlock, Stirge, Mongrelman, Quaggoth, Pedipalp,
        // Huge, Frog, Killer, Fire Bat
        int CEncD2[19][5] = {
            {2,2,1,6,0},
            {3,2,2,12,0},
            {4,3,1,1,0},
            {5,1,1,1,0},
            {6,1,1,12,0},
            {7,1,4,10,0},
            {8,2,2,8,0},
            {9,1,2,8,0},
            {10,1,1,4,0},
            {11,0,0,0,1},
            {12,1,2,8,0},
            {13,2,3,18,0},
            {14,3,2,12,0},
            {15,1,5,15,0},
            {16,2,2,12,0},
            {17,3,4,10,0},
            {18,2,2,8,0},
            {19,1,2,7,0},
            {20,2,1,4,0},
            };
        for (int b = 0;
             b < mm2encdD2Count();
             ++b) {
            int vals[5];
            vals[0] = mm2encdD2Die(b);
            vals[1] = mm2encdD2Src(b);
            vals[2] = mm2encdD2NumMin(b);
            vals[3] = mm2encdD2NumMax(b);
            vals[4] = mm2encdD2Special(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CEncD2[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL III GRID: the 19 die rows 2-20, one row per die
        // (die, source, number min, number max, special). Rows: Leprechaun,
        // Mephit, Fire or Smoke, Phantom, Ankheg, 4-5 HD, Ochre Jelly, Kenku,
        // Luck Eater, Character Party, Ogre, Beetle, Giant Boring, Spider,
        // Large, Scorpion, Large, Bugbear, Gelatinous Cube, Ustilagor,
        // Shocker, Weasel, Giant, Thoqqua, Elf, Drow
        int CEncD3[19][5] = {
            {2,1,1,1,0},
            {3,3,1,3,0},
            {4,2,1,1,0},
            {5,1,1,3,0},
            {6,1,1,1,0},
            {7,3,2,8,0},
            {8,2,1,1,0},
            {9,0,0,0,1},
            {10,1,1,4,0},
            {11,1,1,3,0},
            {12,1,1,4,0},
            {13,2,1,4,0},
            {14,1,2,7,0},
            {15,1,1,1,0},
            {16,2,1,3,0},
            {17,3,1,3,0},
            {18,1,1,4,0},
            {19,3,1,2,0},
            {20,3,2,8,0},
            };
        for (int b = 0;
             b < mm2encdD3Count();
             ++b) {
            int vals[5];
            vals[0] = mm2encdD3Die(b);
            vals[1] = mm2encdD3Src(b);
            vals[2] = mm2encdD3NumMin(b);
            vals[3] = mm2encdD3NumMax(b);
            vals[4] = mm2encdD3Special(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CEncD3[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL IV GRID: the 19 die rows 2-20, one row per die
        // (die, source, number min, number max, special). Rows: Lava
        // Children, Meenlock, Hook Horror, Pech, Owlbear, Rust Monster,
        // Pseudo-undead, Ghast, Character Party, Yellow Mold, Scorpion, Huge,
        // Toad, Poisonous, Gargoyle, Hornet, Giant, Hydra (5-6 heads), Ghast,
        // Caterwaul, Solifugid, Giant, Spectator, Githyanki
        int CEncD4[19][5] = {
            {2,3,1,6,0},
            {3,3,2,5,0},
            {4,3,2,5,0},
            {5,2,3,12,0},
            {6,1,1,2,0},
            {7,1,1,2,0},
            {8,2,1,4,0},
            {9,0,0,0,1},
            {10,1,1,1,0},
            {11,2,1,6,0},
            {12,1,1,4,0},
            {13,1,1,2,0},
            {14,3,1,2,0},
            {15,1,1,1,0},
            {16,1,1,4,0},
            {17,3,1,1,0},
            {18,2,1,4,0},
            {19,2,1,1,0},
            {20,3,1,4,0},
            };
        for (int b = 0;
             b < mm2encdD4Count();
             ++b) {
            int vals[5];
            vals[0] = mm2encdD4Die(b);
            vals[1] = mm2encdD4Src(b);
            vals[2] = mm2encdD4NumMin(b);
            vals[3] = mm2encdD4NumMax(b);
            vals[4] = mm2encdD4Special(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CEncD4[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL V GRID: the 19 die rows 2-20, one row per die
        // (die, source, number min, number max, special). Rows: Grue,
        // Chaggrin, Cloaker, Algoid, Phycomid, Minotaur, Snake, Giant
        // Poisonous, Lizard, Subterranean, Bear, Cave, Character Party,
        // Cockatrice, Spider, Giant, Giant, Verbeeg, Hydra, 7 Heads, Snake,
        // Poisonous, Margoyle, Rock Reptile, Doppleganger, Solifugid, Giant,
        // Hydra, Pyro- (5 heads)
        int CEncD5[19][5] = {
            {2,2,1,1,0},
            {3,2,1,1,0},
            {4,3,1,2,0},
            {5,2,1,4,0},
            {6,1,1,3,0},
            {7,2,1,3,0},
            {8,1,1,3,0},
            {9,1,1,2,0},
            {10,0,0,0,1},
            {11,1,1,2,0},
            {12,1,1,4,0},
            {13,2,2,5,0},
            {14,1,1,1,0},
            {15,2,2,5,0},
            {16,2,1,2,0},
            {17,2,1,2,0},
            {18,1,1,3,0},
            {19,2,1,3,0},
            {20,1,1,1,0},
            };
        for (int b = 0;
             b < mm2encdD5Count();
             ++b) {
            int vals[5];
            vals[0] = mm2encdD5Die(b);
            vals[1] = mm2encdD5Src(b);
            vals[2] = mm2encdD5NumMin(b);
            vals[3] = mm2encdD5NumMax(b);
            vals[4] = mm2encdD5Special(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CEncD5[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL VI GRID: the 19 die rows 2-20, one row per die
        // (die, source, number min, number max, special). Rows: Drider,
        // Rakshasa, Green Slime, Basilisk, Grell, Otyugh, Wyvern, Wraith,
        // Wight, Character Party, Pseudo-wraith, Carrion Crawler, Scorpion,
        // Giant, Troll, Devil, Abishai, Dragon, Black, Old, Ogre Mage,
        // Yuan-ti, Slaad, Red
        int CEncD6[19][5] = {
            {2,2,1,3,0},
            {3,1,1,1,0},
            {4,1,1,6,0},
            {5,1,1,1,0},
            {6,3,1,1,0},
            {7,1,1,1,0},
            {8,1,1,1,0},
            {9,1,1,2,0},
            {10,1,1,4,0},
            {11,0,0,0,1},
            {12,2,1,2,0},
            {13,1,1,2,0},
            {14,1,1,2,0},
            {15,1,1,3,0},
            {16,2,1,2,0},
            {17,1,1,1,0},
            {18,1,1,2,0},
            {19,2,1,3,0},
            {20,3,1,1,0},
            };
        for (int b = 0;
             b < mm2encdD6Count();
             ++b) {
            int vals[5];
            vals[0] = mm2encdD6Die(b);
            vals[1] = mm2encdD6Src(b);
            vals[2] = mm2encdD6NumMin(b);
            vals[3] = mm2encdD6NumMax(b);
            vals[4] = mm2encdD6Special(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CEncD6[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL VII GRID: the 19 die rows 2-20, one row per die
        // (die, source, number min, number max, special). Rows: Dao,
        // Basilisk, Greater, Umber Hulk, Mimic, Chimera, Lurker Above, Giant,
        // Frost or Fire, Character Party, Pudding, Black, Giant, Hill,
        // Will-o-wisp, Slug, Giant, Pseudo-undead, Spectre, Sundew, Giant,
        // Mummy, Spectre, Invisible Stalker, Diakk, Daemon, Mezzo-
        int CEncD7[19][5] = {
            {2,2,1,1,0},
            {3,2,1,1,0},
            {4,1,1,1,0},
            {5,1,1,1,0},
            {6,1,1,1,0},
            {7,1,1,1,0},
            {8,1,1,3,0},
            {9,0,0,0,1},
            {10,1,1,1,0},
            {11,1,1,4,0},
            {12,1,1,3,0},
            {13,1,1,1,0},
            {14,2,1,2,0},
            {15,2,1,1,0},
            {16,1,1,2,0},
            {17,1,1,1,0},
            {18,1,1,1,0},
            {19,2,1,4,0},
            {20,3,1,1,0},
            };
        for (int b = 0;
             b < mm2encdD7Count();
             ++b) {
            int vals[5];
            vals[0] = mm2encdD7Die(b);
            vals[1] = mm2encdD7Src(b);
            vals[2] = mm2encdD7NumMin(b);
            vals[3] = mm2encdD7NumMax(b);
            vals[4] = mm2encdD7Special(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CEncD7[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL VIII GRID: the 19 die rows 2-20, one row per die
        // (die, source, number min, number max, special). Rows: Foo Lion,
        // Xag-ya, Demon, Chasme, Aurumvorax, Vampire, Pudding, Deadly Brown,
        // Demon, Alu-, Character Party, Hydra (13-16 heads), Pseudo-undead,
        // Vampire, Rust Monster, Will-o-wisp, Trapper, Demon, Type V, Purple
        // Worm, Ghost, Dragon, Black, Ancient, Xeg-yi, Daemon, Charon
        int CEncD8[19][5] = {
            {2,2,1,1,0},
            {3,2,1,1,0},
            {4,2,1,3,0},
            {5,2,1,2,0},
            {6,1,1,1,0},
            {7,2,1,1,0},
            {8,2,1,2,0},
            {9,0,0,0,1},
            {10,1,1,1,0},
            {11,2,1,2,0},
            {12,1,1,2,0},
            {13,1,1,1,0},
            {14,1,1,1,0},
            {15,1,1,1,0},
            {16,1,1,1,0},
            {17,1,1,1,0},
            {18,1,1,1,0},
            {19,2,1,1,0},
            {20,2,1,1,0},
            };
        for (int b = 0;
             b < mm2encdD8Count();
             ++b) {
            int vals[5];
            vals[0] = mm2encdD8Die(b);
            vals[1] = mm2encdD8Src(b);
            vals[2] = mm2encdD8NumMin(b);
            vals[3] = mm2encdD8NumMax(b);
            vals[4] = mm2encdD8Special(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CEncD8[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL IX GRID: the 19 die rows 2-20, one row per die
        // (die, source, number min, number max, special). Rows: Demon, Type
        // VI, Deva, Monadic, Devil, Pit Fiend, Dragon, Red, Anc., Hydra,
        // Pyro- (12 heads), Slaad, Grey, Titan, Minor, Character Party, Deva,
        // Movanic, Thessalhydra, Vampire, former cleric, level 7-10, Golem,
        // Stone, Dragon, Black, Anc. O., Demodand, Kelubar, Daemon, Nyca-,
        // Titan, Major, Baku, Daemon, Ultro-, Demilich
        int CEncD9[19][5] = {
            {2,1,1,1,0},
            {3,2,1,1,0},
            {4,1,1,1,0},
            {5,1,1,1,0},
            {6,1,1,1,0},
            {7,3,1,1,0},
            {8,1,1,1,0},
            {9,0,0,0,1},
            {10,2,1,1,0},
            {11,2,1,1,0},
            {12,1,1,1,0},
            {13,1,1,1,0},
            {14,1,2,2,0},
            {15,2,1,2,0},
            {16,3,1,1,0},
            {17,1,1,1,0},
            {18,2,1,1,0},
            {19,2,1,1,0},
            {20,2,1,1,0},
            };
        for (int b = 0;
             b < mm2encdD9Count();
             ++b) {
            int vals[5];
            vals[0] = mm2encdD9Die(b);
            vals[1] = mm2encdD9Src(b);
            vals[2] = mm2encdD9NumMin(b);
            vals[3] = mm2encdD9NumMax(b);
            vals[4] = mm2encdD9Special(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CEncD9[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL X GRID: the 19 die rows 2-20, one row per die
        // (die, source, number min, number max, special). Rows: Demon Prince,
        // Elemental Prince of Evil, Modron, Quarton, Tarrasque, Dragon, Red,
        // Anc. V.O., Dragon, Blue, Anc. V.O., Solar, Golem, Iron, Planetar,
        // Slaad, Death, Beholder, Character Party, Lich, Vampire, former
        // magic-user, level 9-12, Dragon, Cloud, Ancient, Modron, Quinton,
        // Titan, Elder, Daemon, Charon, Devil, Duke or Arch-
        int CEncD10[19][5] = {
            {2,4,0,0,2},
            {3,3,0,0,2},
            {4,2,1,1,0},
            {5,2,1,1,0},
            {6,1,2,2,0},
            {7,1,2,2,0},
            {8,2,1,1,0},
            {9,1,1,1,0},
            {10,2,1,1,0},
            {11,3,1,1,0},
            {12,1,1,1,0},
            {13,0,0,0,1},
            {14,1,1,1,0},
            {15,1,1,1,0},
            {16,2,1,1,0},
            {17,2,1,1,0},
            {18,1,1,1,0},
            {19,2,0,0,2},
            {20,4,0,0,2},
            };
        for (int b = 0;
             b < mm2encdD10Count();
             ++b) {
            int vals[5];
            vals[0] = mm2encdD10Die(b);
            vals[1] = mm2encdD10Src(b);
            vals[2] = mm2encdD10NumMin(b);
            vals[3] = mm2encdD10NumMax(b);
            vals[4] = mm2encdD10Special(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CEncD10[b][c])
                    ++bad;
            }
        }
        // the census walk (the ten-grid arithmetic)
    if (mm2encdTotalRows() != mm2encdTableCount() * mm2encdRowsPerTable()
            || mm2encdTableCount() != 10
            || mm2encdRowsPerTable() != 19
        )
            ++bad;
        // the source census (the party rows carry no source)
    if (mm2encdMm1SourceRows() + mm2encdMm2SourceRows() +
        mm2encdFfSourceRows() + mm2encdAllSourceRows() +
        mm2encdCharacterPartyRows() != mm2encdTotalRows()
        )
            ++bad;
        // the die range (the 1d8+1d12 sum)
    if (mm2encdDieMax() - mm2encdDieMin() + 1 != mm2encdRowsPerTable()
        )
            ++bad;
        // the unique-court census (all four on Level X)
    if (mm2encdUniqueCourtRows() != 4
            || mm2encdPartyDieD10() != 13
        )
            ++bad;
        // the character-party census (one row per table)
    if (mm2encdCharacterPartyRows() != mm2encdTableCount()
        )
            ++bad;
        // the registry floor (no defs promoted this round)
    if (mm2encdRegistryFloor() < 809
        )
            ++bad;
        // the party-die census (the per-table dice)
    if (mm2encdPartyDieD1() != 11
            || mm2encdPartyDieD5() != 10
            || mm2encdPartyDieD10() != 13
        )
            ++bad;
        // the grid round (R816)
    if (mm2encdRound() != 816
        )
            ++bad;
        // the walk-key census (the R839 FF promotion rewire)
    if (mm2encdWalkKeyRows() != mm2encdTotalRows() -
        mm2encdCharacterPartyRows() - ffuDunMm1BlankCells() -
        ffuDunMm2BlankCells() - ffuDunCourtKeylessCells() -
        ffuDunFfKeylessAfter()
        )
            ++bad;
        // the FF row census (the Elemental Prince and Hornet Giant rows
        // stay keyless)
    if (mm2encdFfSourceRows() != ffuDunFfKeyed() +
        ffuDunFfKeylessAfter()
        )
            ++bad;
        printf("R816 MM2 dungeon encounter grids audit: bad %d\n", bad);
        if (bad) return 1;
    }
