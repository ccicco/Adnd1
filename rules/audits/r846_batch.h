    // ---- R846 FF monster level tables audit ----
    // THE FF MONSTER LEVEL TABLES - the ten Monster Level grids (the print
    // pp. 100-110) with their eleven subtables: the eight Dragon Subtables
    // keyed to Levels III through X (the Levels I and II grids carry no
    // dragon rows), the Sphinx Subtable (the Level VII routing target), the
    // Human Subtable (the Level I routing target) and the Character Subtable
    // (the every-level routing target). THE WALK: 21 grids, 461 rows, every
    // cell pinned (die band, roster ordinal, source, numbers, special; the
    // dragon rows die band, type, age, hit points per die). THE SOURCES: the
    // three-voice scan collation from the archive.org item tsr02012fiendfolio
    // (the djvu text, the word-geometry xml, the abbyy char xml) with the 995
    // landed registry defs the advisory voice - the src census walks 193 MM1
    // rows, 133 FF rows, 20 routing rows and 14 unkeyed rows and NO MM2 row
    // (the print lists MM1 and FF creatures only). THE REPAIRS (39, the R703
    // pattern): every repair forced by the 01-00 contiguity or corroborated
    // by the def - the Level I shrieker band (the ink 60-84 reads 80-84) and
    // the snyad numbers, the Level II crabman band and the poltergeist
    // numbers, the Level III drow and garbug bands, the Level IV blink dog
    // and werewolf bands and the yellow musk creeper rows, the Level V snake
    // band and the xill row 00, the Level VI carrion crawler, lammasu and
    // medusa bands, the Level VII efreeti band (the ink 23 reads 28) and the
    // xorn row 00 (the ink Korn), the Level VIII ice devil band (the ink T9
    // reads 19), the Level IX guardian naga and nycadaemon bands and the
    // vampire band, the Dragon Subtable red and silver bands (the D4 ink
    // 75-02 and 83-38) and the D7 bronze and red bands. THE DEFECT PINS (2):
    // the Level III wererat band 56-63 double-lists the four following rows
    // (59, 60, 61-62, 63) - pinned as ink, the grid does NOT assert its full
    // tiling; the Level VIII ink skips the die band 27-28 (the Giant, cloud
    // row 25-26 jumps to the Giant, fog row 29-30 in both voices) - pinned as
    // ink. THE NOTED INK: the D3 hit-points cells garble (pinned unreadable),
    // the D4 subtable carries no hit-points column, the D10 hit-points cells
    // garble beyond the Copper row (pinned unreadable), the Level X AC column
    // prints blank except the Beholder (0/2/7) and the Elemental Prince of
    // Evil (Var), the Level X asterisk rows read select one or find randomly,
    // the vampire footnotes ride the Level IX (former evil cleric, 7th-10th
    // level) and Level X (former magic-user, 9th-12th level) rows, the Level
    // IX xorn numbers read 2-9 in both voices (the def reads 2-5), the
    // pyrohydra and piercer rows ride no single registry def (the four MM1
    // piercer size defs; unkeyed), and the ink name variants (Anhkheg, Korn,
    // Elf drew, Meazle, Snayd, XIII, BuJette and the rest) pin as scanned
    // with the roster riding the cleaned print names. No defs promoted this
    // round - the registry floor holds at 995; the round-roster ordinal (333
    // labels) walks every creature, routing label, sphinx type, human row,
    // character class and dragon type the grids carry.
    {
        using namespace rules;
        int bad = 0;
    if (ffnRound() != 846
            || ffnTableCount() != 21
            || ffnLevelRows() != 360
            || ffnDragonBandRows() != 83
            || ffnSubtableRows() != 18
            || ffnTotalRows() != 461
            || ffnRosterCount() != 333
            || ffnRegistryFloor() != 995
            || ffnRepairs() != 39
            || ffnDefectPins() != 2
            || ffnL3DefectRows() != 5
            || ffnL8HoleLo() != 27
            || ffnL8HoleHi() != 28
            || ffnMm1SourceRows() != 193
            || ffnMm2SourceRows() != 0
            || ffnFfSourceRows() != 133
            || ffnUnkeyedRows() != 14
            || ffnRoutingRows() != 20
            || ffnRoutingCharacter() != 9
            || ffnRoutingDragon() != 8
            || ffnRoutingHuman() != 1
            || ffnRoutingSphinx() != 1
            || ffnRoutingElemental() != 1
            || ffnL1Rows() != 33
            || ffnL2Rows() != 30
            || ffnL3Rows() != 55
            || ffnL4Rows() != 42
            || ffnL5Rows() != 33
            || ffnL6Rows() != 40
            || ffnL7Rows() != 58
            || ffnL8Rows() != 31
            || ffnL9Rows() != 23
            || ffnL10Rows() != 15
            || ffnD3Rows() != 3
            || ffnD4Rows() != 11
            || ffnD5Rows() != 11
            || ffnD6Rows() != 11
            || ffnD7Rows() != 12
            || ffnD8Rows() != 12
            || ffnD9Rows() != 12
            || ffnD10Rows() != 11
            || ffnSpxRows() != 4
            || ffnHumRows() != 4
            || ffnChrRows() != 10
            || ffnPartyDieD1() != 39
            || ffnPartyDieD2() != 15
            || ffnPartyDieD3() != 16
            || ffnPartyDieD4() != 13
            || ffnPartyDieD5() != 7
            || ffnPartyDieD6() != 12
            || ffnPartyDieD7() != 6
            || ffnPartyDieD8() != 7
            || ffnPartyDieD9() != 7
            || ffnPartyDieD10() != 20
            || ffnSphinxDieLo() != 89
            || ffnDragonDieD3() != 27
            || ffnDragonDieD4() != 25
            || ffnDragonDieD5() != 31
            || ffnDragonDieD6() != 22
            || ffnDragonDieD7() != 26
            || ffnDragonDieD8() != 20
            || ffnDragonDieD9() != 20
            || ffnDragonDieD10() != 31
            || !ffnDiceScoreD100()
            || !ffnNotACompleteListing()
            || !ffnDmMayModify()
            || !ffnDragonSubtablesKeyedIIItoX()
            || !ffnDragonHdNote()
            || !ffnHumanLeadersNote()
            || !ffnHalflingDeepNote()
            || !ffnBadgerThirdLevelNote()
            || !ffnElementalChooseNote()
            || !ffnL9VampireFootnote()
            || !ffnL10VampireFootnote()
            || !ffnL10AsteriskSelect()
            || !ffnL10AcColumnBlank()
            || !ffnCharMonkNote()
            || !ffnL3Defect()
            || !ffnL8HoleDefect()
            || !ffnInkNameVariants()
        )
            ++bad;
        // THE MONSTER LEVEL I GRID: the 33 die rows, one row per band (die
        // low, die high, roster ord, source, number min, number max,
        // special). Rows: Al-Mi'Raj 01 (numbers 1-4, src FF): AC 6 MV 18" HD
        // 1 #AT 1 D 1-4; Ant, Giant 02-03 (numbers 1-4, src MM1): AC 3 MV 18"
        // HD 2 #AT 1 D 1-6; Bat, Giant 04-06 (numbers 1-6, src FF): AC 8 MV
        // 3"/18" HD - (the ink cell drops; the def reads 1-4 hp or 1) #AT 1
        // or 2 (ink Vt or 1) D 1-2 or 1-4; Beetle, Giant, Fire 07-13 (numbers
        // 1-4, src MM1): AC 4 MV 12" HD 1+2 #AT 1 D 2-8; Bullywug 14-15
        // (numbers 3-18, src FF): AC 6 MV 3"/15" HD 1 #AT 3 or 1 D BW or
        // 1-2/1-2/2-5; Carbuncle 16-17 (numbers 1-1, src FF): AC 2 MV 3" HD 1
        // #AT 0 D Nil; Cerebral Parasite 18-19 (numbers 0-0, src MM1):
        // numbers n/a; AC n/a MV n/a HD n/a #AT 0 D Nil; Manes 20 (numbers
        // 1-4, src MM1): printed "Demon, manes"; AC 7 MV 3" HD 1 #AT 3 D
        // 1-2/1-2/1-4; Dire Corby 21-22 (numbers 2-5, src FF): AC 6 MV 12" HD
        // 2 #AT 2 D 1-6/1-6 (ink 1-6/1-B; the def reads 1-6/1-6); Dwarf 23
        // (numbers 4-14, src MM1): numbers 4-14 (2d6+2); AC 4 MV 6" HD 1 #AT
        // 1 D BW or 1-8; Ear Seeker 24 (numbers 1-1, src MM1): AC 9 MV 1" HD
        // 1 hp #AT spec. D spec.; Elf 25 (numbers 4-11, src MM1): numbers
        // 4-11 (1d8+3); AC 5 MV 12" HD 1+1 #AT 1 D BW or 1-10; Gibberling
        // 26-28 (numbers 6-17, src FF): numbers 6-17 (d12+5); AC 10 MV 9" HD
        // 1 #AT 1 D 1-8; Gnome 29 (numbers 5-15, src MM1): numbers 5-15
        // (2d6+3); AC 5 MV 6" HD 1 #AT 1 D BW or 1-6; Goblin 30-33 (numbers
        // 6-15, src MM1): numbers 6-15 (d10+5); AC 6 MV 6" HD 1-1 #AT 1 D BW
        // or 1-6; Halfling 34 (numbers 9-16, src MM1): numbers 9-16 (d8+8);
        // AC 7 MV 9" HD 1d6 #AT 1 D BW or 1-6; the print footnote reads: not
        // encountered below the 4th level, treat as a roll of 71-77 (Rat,
        // giant) thereafter; Hobgoblin 35-38 (numbers 2-8, src MM1): AC 5 MV
        // 9" HD 1+1 #AT 1 D BW or 1-8; Human 39-46: the routing row: see the
        // Human Subtable; Jermlaine 47-50 (numbers 6-20, src FF): numbers
        // 6-20 (2d8+4); AC 7 MV 15" HD V* (ink; the def reads 1-4 hp) #AT 1 D
        // 1-2 or 1-4; Kobold 51-54 (numbers 6-17, src MM1): numbers 6-17
        // (d12+5); AC 7 MV 6" HD 1-4 (ink 14; the def reads 1-4 hp) #AT 1 D
        // BW or 1-4; Mite 55-56 (numbers 3-18, src FF): AC 8 MV 3" HD 1-1 #AT
        // 1 D 1-3; Norker 57 (numbers 2-8, src FF): AC 3 MV 9" HD 1+2 #AT 2 D
        // 1-3/1-6; Ogrillon 58-59 (numbers 1-4, src FF): AC 6 MV 12" HD 2 #AT
        // 2 D 2-7/2-7; Orc 60-67 (numbers 7-12, src MM1): numbers 7-12
        // (d6+6); AC 6 MV 9" HD 1 #AT 1 D BW or 1-8 (ink 1-0; the def reads
        // 1-8 or by weapon type); Piercer 68-70 (numbers 1-4, src unkeyed):
        // no single registry def keys the piercer (the four MM1 size defs,
        // smallest 1 HD through largest 4 HD); AC 3 MV 1" HD 1 or 2 #AT 1 D
        // 1-6 or 2-12 (unkeyed); Rat, Giant 71-77 (numbers 5-20, src MM1):
        // numbers 5-20 (the def reads 5-50); AC 2 (ink 2 12; the def reads 7)
        // MV 12"//6" HD V (ink Vj) #AT 1 D 1-3; Rot Grub 78-79 (numbers 1-3,
        // src MM1): AC 9 MV V (ink V") HD 1 hp #AT 0 D Nil; Shrieker 80-84
        // (numbers 1-2, src MM1): AC 7 MV 1" HD 3 #AT 0 D Nil; Skeleton 85-86
        // (numbers 1-4, src MM1): AC 7 MV 12" HD 1 #AT 1 D 1-6; Snyad 87-90
        // (numbers 1-8, src FF): printed "Snayd" (both voices); AC -4 MV 21"
        // HD 1-1 #AT 0 D Nil; Tween 91-97 (numbers 1-1, src FF): AC 10 MV Var
        // HD 1 #AT 1 D BW; Xvart 98 (numbers 8-15, src FF): numbers 8-15
        // (d10+5); AC 7 MV 6" HD 1-1 (ink 1-t; the def reads 1-1) #AT 1 D BW
        // or 2-5; Zombie 99-00 (numbers 1-3, src MM1): AC 8 MV 6" HD 2 #AT 1
        // D 1-8.
        int CL1[33][7] = {
            {1,1,0,3,1,4,0},
            {2,3,1,1,1,4,0},
            {4,6,2,3,1,6,0},
            {7,13,3,1,1,4,0},
            {14,15,4,3,3,18,0},
            {16,17,5,3,1,1,0},
            {18,19,6,1,0,0,0},
            {20,20,7,1,1,4,0},
            {21,22,8,3,2,5,0},
            {23,23,9,1,4,14,0},
            {24,24,10,1,1,1,0},
            {25,25,11,1,4,11,0},
            {26,28,12,3,6,17,0},
            {29,29,13,1,5,15,0},
            {30,33,14,1,6,15,0},
            {34,34,15,1,9,16,0},
            {35,38,16,1,2,8,0},
            {39,46,17,0,0,0,3},
            {47,50,18,3,6,20,0},
            {51,54,19,1,6,17,0},
            {55,56,20,3,3,18,0},
            {57,57,21,3,2,8,0},
            {58,59,22,3,1,4,0},
            {60,67,23,1,7,12,0},
            {68,70,24,4,1,4,0},
            {71,77,25,1,5,20,0},
            {78,79,26,1,1,3,0},
            {80,84,27,1,1,2,0},
            {85,86,28,1,1,4,0},
            {87,90,29,3,1,8,0},
            {91,97,30,3,1,1,0},
            {98,98,31,3,8,15,0},
            {99,100,32,1,1,3,0},
            };
        for (int b = 0;
             b < ffnL1Rows();
             ++b) {
            int vals[7];
            vals[0] = ffnL1Lo(b);
            vals[1] = ffnL1Hi(b);
            vals[2] = ffnL1Ord(b);
            vals[3] = ffnL1Src(b);
            vals[4] = ffnL1NumMin(b);
            vals[5] = ffnL1NumMax(b);
            vals[6] = ffnL1Sp(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CL1[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL II GRID: the 30 die rows, one row per band (die
        // low, die high, roster ord, source, number min, number max,
        // special). Rows: Ankheg 01-03 (numbers 1-3, src MM1): D 3-18 (+1-4);
        // printed "Anhkheg" (both voices); Assassin Bug 04-05 (numbers 2-2,
        // src FF): D 1-4; Giant Badger 06 (numbers 1-4, src MM1): D
        // 1-3/1-3/1-6; the print footnote reads: not encountered below the
        // 3rd level, treat as a roll of 44-48 (Gnoll) thereafter; Giant
        // Centipede 07-14 (numbers 3-13, src MM1): numbers 3-13 (2d6+1); D
        // Nil +S; Character 15-24: the routing row: see the Character
        // Subtable; Coffer Corpse 25-26 (numbers 1-1, src FF): D BW or 1-6;
        // Crabman 27-28 (numbers 2-8, src FF): D 1-4/1-4; Flind 29-30
        // (numbers 2-8, src FF): printed "Rind" (both voices); D 1-6 or 1-4
        // +S; Flumph 31-33 (numbers 2-8, src FF): printed "Rump" (both
        // voices); D 1-8 (+1-4); Giant Frog 34-37 (numbers 1-6, src MM1): D
        // 1-3 or 1-6 or 2-8; Killer Frog 38 (numbers 2-7, src MM1): printed
        // "Frog killer"; D 1-2/1-2/2-5; Poisonous Frog 39-40 (numbers 1-4,
        // src MM1): printed "Frog, poisonous"; D 1 pt. +S; Galltrit 41
        // (numbers 1-4, src FF): printed "Galttrit" (both voices); D 1-2; Gas
        // Spore 42-43 (numbers 1-2, src MM1): D (blank in the ink); Gnoll
        // 44-48 (numbers 4-10, src MM1): numbers 4-10 (2d4+2); printed
        // "Gnotl" (both voices); D BW or 2-8; Goldbug 49-50 (numbers 1-12,
        // src FF): D 1-4; Gorbel 51-54 (numbers 1-8, src FF): D 1-4 or 1-6;
        // Grimlock 55-58 (numbers 2-12, src FF): printed "Grim lock"; D BW or
        // 1-6; Gryph 59 (numbers 1-6, src FF): D 2-12; Ice Troll 60-61
        // (numbers 1-6, src FF): printed "Troll, ice"; D 1-8/1-8; Lizard Man
        // 62-65 (numbers 4-10, src MM1): numbers 4-10 (2d4+2); D 1-2/1-2/1-8;
        // Nilbog 66 (numbers 1-6, src FF): printed "Nlibog" (both voices); D
        // BW or 1-6; Piercer 67-70 (numbers 1-4, src unkeyed): no single
        // registry def keys the piercer (the four MM1 size defs); D 3-18
        // (unkeyed); Poltergeist 71-73 (numbers 1-8, src FF): D Nil; Quaggoth
        // 74-75 (numbers 4-10, src FF): numbers 4-10 (2d4+2); D 1-4/1-4 or
        // BW; Skulk 76-78 (numbers 1-8, src FF): D BW; Giant Toad 79-86
        // (numbers 1-4, src MM1): printed "Toad, giant"; D 2-8; Troglodyte
        // 87-94 (numbers 2-8, src MM1): D 1-3/1-3/2-5 or BW; Volt 95-98
        // (numbers 1-8, src FF): printed "Voll" (both voices); D 1-4 and
        // 2-12; Vortex 99-00 (numbers 1-8, src FF): D 1-3 +S.
        int CL2[30][7] = {
            {1,3,33,1,1,3,0},
            {4,5,34,3,2,2,0},
            {6,6,35,1,1,4,0},
            {7,14,36,1,3,13,0},
            {15,24,37,0,0,0,1},
            {25,26,38,3,1,1,0},
            {27,28,39,3,2,8,0},
            {29,30,40,3,2,8,0},
            {31,33,41,3,2,8,0},
            {34,37,42,1,1,6,0},
            {38,38,43,1,2,7,0},
            {39,40,44,1,1,4,0},
            {41,41,45,3,1,4,0},
            {42,43,46,1,1,2,0},
            {44,48,47,1,4,10,0},
            {49,50,48,3,1,12,0},
            {51,54,49,3,1,8,0},
            {55,58,50,3,2,12,0},
            {59,59,51,3,1,6,0},
            {60,61,52,3,1,6,0},
            {62,65,53,1,4,10,0},
            {66,66,54,3,1,6,0},
            {67,70,24,4,1,4,0},
            {71,73,55,3,1,8,0},
            {74,75,56,3,4,10,0},
            {76,78,57,3,1,8,0},
            {79,86,58,1,1,4,0},
            {87,94,59,1,2,8,0},
            {95,98,60,3,1,8,0},
            {99,100,61,3,1,8,0},
            };
        for (int b = 0;
             b < ffnL2Rows();
             ++b) {
            int vals[7];
            vals[0] = ffnL2Lo(b);
            vals[1] = ffnL2Hi(b);
            vals[2] = ffnL2Ord(b);
            vals[3] = ffnL2Src(b);
            vals[4] = ffnL2NumMin(b);
            vals[5] = ffnL2NumMax(b);
            vals[6] = ffnL2Sp(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CL2[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL III GRID: the 55 die rows, one row per band (die
        // low, die high, roster ord, source, number min, number max,
        // special). Rows: Adherer 01 (numbers 1-4, src FF): AC 3 MV 9" HD 4
        // #AT 1 D 1-3; Ankheg 02 (numbers 1-3, src MM1): printed "Anhkheg"
        // (both voices); AC 2/4 MV 12" (6") HD 4 or 5 #AT 1 D 3-18 (+1-4)
        // (ink 3-16; the def reads 3-18 (+1-4)); Astral Searcher 03 (numbers
        // 2-11, src FF): AC 10 MV 12" HD 2 #AT 1 D 1-6; Babbler 04 (numbers
        // 1-4, src FF): AC 6 MV 6" or 12" HD 5 #AT 2 (the def reads 3; the
        // ink reads 2 in both voices) D 1-6/1-6/1-8; Boring Beetle 05-08
        // (numbers 1-3, src MM1): printed "Beetle, giant, boring"; AC 3 MV 6"
        // HD 5 #AT 1 D 5-20; Berbalang 09 (numbers 1-1, src FF): AC 6 MV
        // 6"/24" HD 1+1 #AT 3 D 1-4/1-4/1-6; Blindheim 10 (numbers 1-4, src
        // FF): AC 5 MV 9" HD 4+2 #AT 1 D 1-8; Bonesnapper 11 (numbers 1-3,
        // src FF): AC 4 MV 6" HD 4 #AT 2 D 1-6/1-4 (the def reads 1-8/1-4;
        // the ink reads 1-6/1-4 in both voices); Bugbear 12-15 (numbers 2-7,
        // src MM1): AC 5 MV 9" HD 3+1 #AT 1 D BW or 2-8; Character 16-21: the
        // routing row: see the Character Subtable; Dark Creeper 22 (numbers
        // 1-1, src FF): AC 0 MV 9" HD 1+1 #AT 1 D 1-4; Death Dog 23 (numbers
        // 3-12, src FF): AC 7 MV 12" HD 2+1 #AT 2 D 1-10/1-10 +S; Lemure
        // 24-26 (numbers 2-5, src MM1): printed "Devil, lemure"; AC 7 MV 3"
        // HD 3 #AT 1 D 1-3; Dragon 27: the routing row: see the Dragon
        // Subtable (Level III); Drow 28 (numbers 2-7, src FF): printed "Elf,
        // drew" (both voices); AC 4 (+) MV 12" or 15" HD 2 (+) #AT 1 or 2 D
        // BW; Enveloper 29 (numbers 1-1, src FF): printed "Enveloper" (ink
        // "En veto per", both voices); AC 4 MV 9" HD Var. #AT 2 D 1-8/1-8 +S;
        // Firedrake 30 (numbers 1-6, src FF): AC 5 MV 6"/18" HD 4 #AT 1 D
        // 2-8; Firenewt 31 (numbers 2-16, src FF): printed "Firenewt" (ink
        // "Fi renew!", both voices); AC 5 MV 9" HD 2+2 #AT 1 D BW; Fire Snake
        // 32-33 (numbers 1-6, src FF): AC 6 MV 4" HD 2 #AT 1 D 1-4 +S;
        // Forlarren 34 (numbers 1-1, src FF): AC 2 MV 9" HD 3 #AT 2 D 1-4/1-4
        // +S; Frost Man 35 (numbers 1-1, src FF): AC 5 MV 12" HD 4 #AT 1 D
        // BW; Violet Fungus 36 (numbers 1-3, src MM1): printed "Fungi,
        // violet"; AC 7 MV 1" HD 3 #AT 1-4 D S; Gambado 37 (numbers 1-4, src
        // FF): AC 6 MV 12" HD 4 #AT 3 D 1-8/1-4/1-4; Garbug, Violet 38
        // (numbers 1-3, src FF): printed "Garbug, violet" (ink "Gar bug.
        // violet", both voices); AC 5 MV 6"/9" HD 3+1 #AT 2 D 1-6/1-6 +S;
        // Gelatinous Cube 39-41 (numbers 1-1, src MM1): printed "Gelatinous
        // cube" (ink "Gelantinous cube", both voices); AC 8 MV 6" HD 4 #AT 1
        // D 2-6 +S; Ghoul 42-44 (numbers 1-4, src MM1): AC 6 MV 9" HD 2 #AT 3
        // D 1-3/1-3/1-6 +S; Huecuva 45 (numbers 1-4, src FF): AC 3 MV 9" HD 2
        // #AT 1 D 1-6 +S; Imorph 46 (numbers 1-1, src FF): printed "Imorph"
        // (ink "tmorph", both voices); AC 5 MV 6" HD 5 #AT 2 D 1-4/1-4; Iron
        // Cobra 47 (numbers 1-1, src FF): AC 0 MV 12" HD 1 #AT 1 D 1-3 +S;
        // Kenku 48-50 (numbers 1-4, src FF): AC 5 MV 6"/18" HD 2-5 #AT 3 or 1
        // D 1-4/1-4/1-6 or BW; Leprechaun 51-52 (numbers 1-4, src MM1): AC 8
        // MV 15" HD 2-5 hp #AT 0 D Nil (S); Giant Lizard 53-55 (numbers 1-3,
        // src MM1): printed "Lizard, giant"; AC 5 MV 15" HD 3+1 #AT 1 D 1-8;
        // Wererat 56-63 (numbers 2-5, src MM1): printed "Lycanthrope,
        // wererat"; AC 6 MV 12" HD 3+1 #AT 1 D 1-8; PRINT DEFECT: the ink
        // band 56-63 overlaps the four following rows (the double-listed
        // 59-63), pinned as ink; Mantari 59 (numbers 1-3, src FF): AC 8 (the
        // def reads 9) MV 18" HD 1+1 #AT 1 D S; PRINT DEFECT: the ink die 59
        // double-lists inside the wererat band; Meazel 60 (numbers 1-1, src
        // FF): printed "Meazel" (ink "Meazle"); AC 8 MV 12" HD 4 #AT 2 D
        // 1-4/1-4; PRINT DEFECT: the ink die 60 double-lists inside the
        // wererat band; Mephit 61-62 (numbers 1-1, src FF): printed
        // "Mephit*"; AC Var. MV Var HD Var. #AT Var. D Var.; PRINT DEFECT:
        // the ink band 61-62 double-lists inside the wererat band;
        // Necrophidius 63 (numbers 1-1, src FF): AC 2 MV 9" HD 2 #AT 1 D 1-8
        // +S; PRINT DEFECT: the ink die 63 double-lists inside the wererat
        // band; Ochre Jelly 64-66 (numbers 1-1, src MM1): AC 8 MV 3" HD 6 #AT
        // 1 D 3-12; Ogre 67-71 (numbers 1-3, src MM1): AC 5 MV 9" HD 4+1 #AT
        // 1 D 1-10 or BW; Piercer 72-73 (numbers 1-4, src unkeyed): no single
        // registry def keys the piercer (the four MM1 size defs); AC 3 MV 1"
        // HD 4 #AT 1 D 4-24 (unkeyed); Qullan 74 (numbers 1-6, src FF):
        // printed "Quilan" (both voices); AC 10 MV 12" HD 2 #AT 1 D 5-11
        // (2d4+3); Screaming Devilkin 75 (numbers 1-1, src FF): printed
        // "Screaming devilkin" (ink "Screaming devllkin"); AC 2 MV 12" HD 3
        // #AT 1 D 1-6; Sheet Phantom 76 (numbers 1-1, src FF): AC 3 MV 6" HD
        // 3 #AT 1 D 1-4 +S; Shocker 77 (numbers 1-3, src FF): AC 0 MV 9" HD
        // 1+2 #AT 1 D 10 pts.; Huge Spider 78-81 (numbers 1-3, src MM1):
        // printed "Spider, huge"; AC 6 MV 18" HD 2+2 #AT 1 D 1-6 +S; Large
        // Spider 82-85 (numbers 2-5, src MM1): printed "Spider, large"; AC 8
        // MV 6"/15" HD 1+1 #AT 1 D 1 +S; Stirge 86-88 (numbers 5-15, src
        // MM1): numbers 5-15 (2d6+3); AC 8 MV 3"/18" HD 1+1 #AT 1 D 1-3 +S;
        // Stunjelly 89 (numbers 1-1, src FF): printed "Stun jelly"; AC 8 MV
        // 3" HD 4 #AT 1 D 2-8 +S; Symbiotic Jelly 90 (numbers 1-1, src FF):
        // printed "Symbiotic jelly" (ink "Symbiotic felly"); AC 8 MV 1" HD 2
        // #AT 0 D Nil; Thoqqua 91 (numbers 1-2, src FF): AC 2 MV 12" (3") HD
        // 3 #AT 2 D 4-32/2-12; Giant Tick 92-93 (numbers 1-3, src MM1):
        // printed "Tick, giant"; AC 3 MV 3" HD 2-4 #AT 1 D 1-4 +S; Tirapheg
        // 94 (numbers 1-1, src FF): AC 4 (the def reads 10) MV 3" HD 2 #AT 3
        // D 1-4 (x3); Giant Weasel 95-96 (numbers 1-4, src MM1): printed
        // "Weasel, giant"; AC 6 MV 15" HD 3+3 #AT 1 D 2-12; Whipweed 97-98
        // (numbers 1-2, src FF): AC 6/4 MV 3" HD (2+4)+(1+4) #AT 2 D
        // 1-10/1-10; Witherweed 99-00 (numbers 1-1, src FF): printed
        // "Witherweed" (ink "Wilherweed", both voices); AC 8 MV Nil (ink Mil)
        // HD 3-12 (+) #AT 0 D S.
        int CL3[55][7] = {
            {1,1,62,3,1,4,0},
            {2,2,33,1,1,3,0},
            {3,3,63,3,2,11,0},
            {4,4,64,3,1,4,0},
            {5,8,65,1,1,3,0},
            {9,9,66,3,1,1,0},
            {10,10,67,3,1,4,0},
            {11,11,68,3,1,3,0},
            {12,15,69,1,2,7,0},
            {16,21,37,0,0,0,1},
            {22,22,70,3,1,1,0},
            {23,23,71,3,3,12,0},
            {24,26,72,1,2,5,0},
            {27,27,73,0,0,0,2},
            {28,28,74,3,2,7,0},
            {29,29,75,3,1,1,0},
            {30,30,76,3,1,6,0},
            {31,31,77,3,2,16,0},
            {32,33,78,3,1,6,0},
            {34,34,79,3,1,1,0},
            {35,35,80,3,1,1,0},
            {36,36,81,1,1,3,0},
            {37,37,82,3,1,4,0},
            {38,38,83,3,1,3,0},
            {39,41,84,1,1,1,0},
            {42,44,85,1,1,4,0},
            {45,45,86,3,1,4,0},
            {46,46,87,3,1,1,0},
            {47,47,88,3,1,1,0},
            {48,50,89,3,1,4,0},
            {51,52,90,1,1,4,0},
            {53,55,91,1,1,3,0},
            {56,63,92,1,2,5,0},
            {59,59,93,3,1,3,0},
            {60,60,94,3,1,1,0},
            {61,62,95,3,1,1,0},
            {63,63,96,3,1,1,0},
            {64,66,97,1,1,1,0},
            {67,71,98,1,1,3,0},
            {72,73,24,4,1,4,0},
            {74,74,99,3,1,6,0},
            {75,75,100,3,1,1,0},
            {76,76,101,3,1,1,0},
            {77,77,102,3,1,3,0},
            {78,81,103,1,1,3,0},
            {82,85,104,1,2,5,0},
            {86,88,105,1,5,15,0},
            {89,89,106,3,1,1,0},
            {90,90,107,3,1,1,0},
            {91,91,108,3,1,2,0},
            {92,93,109,1,1,3,0},
            {94,94,110,3,1,1,0},
            {95,96,111,1,1,4,0},
            {97,98,112,3,1,2,0},
            {99,100,113,3,1,1,0},
            };
        for (int b = 0;
             b < ffnL3Rows();
             ++b) {
            int vals[7];
            vals[0] = ffnL3Lo(b);
            vals[1] = ffnL3Hi(b);
            vals[2] = ffnL3Ord(b);
            vals[3] = ffnL3Src(b);
            vals[4] = ffnL3NumMin(b);
            vals[5] = ffnL3NumMax(b);
            vals[6] = ffnL3Sp(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CL3[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL IV GRID: the 42 die rows, one row per band (die
        // low, die high, roster ord, source, number min, number max,
        // special). Rows: Ankheg 01-02 (numbers 1-3, src MM1): printed
        // "Anhkheg" (both voices); AC 2/4 MV 12" (6") HD 6 #AT 1 D 3-18
        // (+1-4) +S; Carnivorous Ape 03-06 (numbers 1-3, src MM1): printed
        // "Ape, carnivorous"; AC 6 MV 12" HD 5 #AT 3 D 1-4/1-4/1-6 +S; Blink
        // Dog 07-08 (numbers 2-5, src MM1): AC 5 MV 12" HD 4 #AT 1 D 1-6 +S;
        // Giant Bloodworm 09-10 (numbers 1-3, src FF): printed "Bloodworm,
        // giant"; AC 4 MV 6" HD 6 #AT 1 D 1-8 +S; Caterwaul 11-12 (numbers
        // 1-1, src FF): AC 6 (+) MV 18"-24" (+) HD 4+2 #AT 3 D 1-4/1-4/1-6
        // +S; Character 13-21: the routing row: see the Character Subtable;
        // Dark Stalker 22 (numbers 1-1, src FF): AC 0/8 MV 9" HD 2+1 #AT 1 D
        // 1-6 +S; Denzelian 23 (numbers 1-2, src FF): AC 0 MV 1" HD 6 #AT Nil
        // D Nil; Disenchanter 24 (numbers 1-1, src FF): AC 5 MV 12" HD 5 #AT
        // 1 D S; Dragon 25-26: the routing row: see the Dragon Subtable
        // (Level IV); Ettercap 27-28 (numbers 1-2, src FF): AC 6 MV 12" HD 5
        // #AT 3 D 1-3/1-3/1-8 +S (ink +3); Eye Killer 29 (numbers 1-1, src
        // FF): AC 5 MV 9" HD 4 #AT 1 D 1-6 +S; Firetoad 30-31 (numbers 1-3,
        // src FF): AC 10 MV 6" HD 4+1 #AT 1 D S; Flail Snail 32 (numbers 1-1,
        // src FF): AC 4-6 MV 3" HD 4-6 #AT T (+) D 1-8 (+); Garbug, Black
        // 33-34 (numbers 1-3, src FF): AC 5 MV 6"/9" HD 2+2 #AT 1+6 (the ink
        // reads 1 + 6 in both voices) D 1-4 +S; Gargoyle 35-38 (numbers 1-2,
        // src MM1): AC 5 MV 9"/15" HD 4+4 #AT 4 D 1-3/1-3/1-6/1-4; Ghast
        // 39-40 (numbers 1-4, src MM1): printed "Ghast" (ink "Ghasl"); AC 4
        // MV 15" HD 4 #AT 3 D 1-4/1-4/1-8 +S; Gray Ooze 41-42 (numbers 1-1,
        // src MM1): AC 8 MV 1" HD 3+3 #AT T D 2-16 +S; Grell 43-44 (numbers
        // 1-1, src FF): AC 4 MV 12" HD 5 #AT 11 D 1-4 (x10)/1-6; Hell Hound
        // 45 (numbers 1-2, src MM1): AC 4 MV 12" HD 4-7 #AT 1 D 1-10 +S; Hook
        // Horror 46-47 (numbers 2-5, src FF): AC 3 MV 9" HD 5 #AT 2 D
        // 1-8/1-8; Hornet, Giant 48 (numbers 1-1, src FF): AC 2/4 MV 24" HD 5
        // #AT 1 D 1-4 +S; Hydra 49-52 (numbers 1-1, src MM1): AC 5 MV 9" HD 5
        // #AT 5 D 1-6 (x5) +S; Pyrohydra 53 (numbers 1-1, src unkeyed):
        // printed "Hydra, pyro-"; no registry def keys the pyrohydra
        // (unkeyed); AC 5 MV 9" HD 5 #AT 5 D 1-6 (x5) +S; Kamadan 54-55
        // (numbers 1-1, src FF): printed "Kamadan" (ink "K a mad an", both
        // voices); AC 4 MV 18" HD 4+2 #AT 3 (+) D 1-3/1-3/1-6 + 1-4; Kuo-Toa
        // 56 (numbers 2-12, src FF): AC 4 MV 9"/18" HD 2 #AT 1-2 D BW or 2-5;
        // Lava Children 57 (numbers 1-6, src FF): AC 4 MV 9" HD 4 (+) #AT 3 D
        // 1-6/1-6/2-12 +S (ink +5); Werewolf 58-65 (numbers 1-2, src MM1):
        // printed "Lycanthrope, werewolf"; AC 5 MV 15" HD 4+3 #AT 1 D 2-8;
        // Meenlock 66 (numbers 2-8, src FF): AC 7 (S) MV 9" HD 4 #AT 2 D
        // 1-4/1-4 +S; Yellow Mold 67-70 (numbers 1-1, src MM1): printed
        // "Mold, yellow"; AC 9 MV 0" HD Nil #AT 1 D 1-8 +S; Owlbear 71-72
        // (numbers 1-1, src MM1): printed "Owl bear"; AC 5 MV 12" HD 5+2 #AT
        // 3 D 1-6/1-6/2-12 +S; Rust Monster 73-77 (numbers 1-1, src MM1): AC
        // 2 MV 18" HD 5 #AT 2 D S; Sandman 78-79 (numbers 1-2, src FF): AC 3
        // MV 9" HD 4 #AT 1 D 3 (the ink cells read 1 3 in both voices; the
        // def reads Nil/Nil); Scarecrow 80 (numbers 1-2, src FF): AC 6 MV 6"
        // HD 5 #AT 1 D 1-6 +S; Shadow Demon 81 (numbers 1-1, src FF): AC
        // 9/5/1 MV 12" (S) HD 7+3 #AT 3 D 1-8/1-6/1-6 +S; Constrictor Snake
        // 82-85 (numbers 1-1, src MM1): printed "Snake, giant, constrictor";
        // AC 5 MV 9" HD 6+1 #AT 2 D 1-4/2-8 +S; Son of Kyuss 86 (numbers 1-2,
        // src FF): AC 10 MV 9" HD 4 #AT 1 D 1-8 +S; Su-Monster 87-90 (numbers
        // 1-2, src MM1): AC 6 MV 9" HD 5+5 #AT 5 D 1-4 (x4)/2-8; Tiger Fly
        // 91-92 (numbers 2-2, src FF): AC 4 MV 6"/18" HD 6 or 4 #AT 3 or 1 D
        // 1-8/1-8/4-24 +S or 4-16 +S; Ice Toad 93-94 (numbers 1-1, src MM1):
        // printed "Toad, ice"; AC 4 MV 9" HD 5 #AT 1 D 3-12 +S; Poisonous
        // Toad 95-96 (numbers 1-3, src MM1): printed "Toad, poisonous"; AC 7
        // MV 6"+6" hop HD 2 #AT 1 D 2-5 +S; Yellow Musk Creeper 97-00
        // (numbers 1-1, src FF): AC 7 MV Nil HD 3 #AT 2-12 D S.
        int CL4[42][7] = {
            {1,2,33,1,1,3,0},
            {3,6,114,1,1,3,0},
            {7,8,115,1,2,5,0},
            {9,10,116,3,1,3,0},
            {11,12,117,3,1,1,0},
            {13,21,37,0,0,0,1},
            {22,22,118,3,1,1,0},
            {23,23,119,3,1,2,0},
            {24,24,120,3,1,1,0},
            {25,26,73,0,0,0,2},
            {27,28,121,3,1,2,0},
            {29,29,122,3,1,1,0},
            {30,31,123,3,1,3,0},
            {32,32,124,3,1,1,0},
            {33,34,125,3,1,3,0},
            {35,38,126,1,1,2,0},
            {39,40,127,1,1,4,0},
            {41,42,128,1,1,1,0},
            {43,44,129,3,1,1,0},
            {45,45,130,1,1,2,0},
            {46,47,131,3,2,5,0},
            {48,48,132,3,1,1,0},
            {49,52,133,1,1,1,0},
            {53,53,134,4,1,1,0},
            {54,55,135,3,1,1,0},
            {56,56,136,3,2,12,0},
            {57,57,137,3,1,6,0},
            {58,65,138,1,1,2,0},
            {66,66,139,3,2,8,0},
            {67,70,140,1,1,1,0},
            {71,72,141,1,1,1,0},
            {73,77,142,1,1,1,0},
            {78,79,143,3,1,2,0},
            {80,80,144,3,1,2,0},
            {81,81,145,3,1,1,0},
            {82,85,146,1,1,1,0},
            {86,86,147,3,1,2,0},
            {87,90,148,1,1,2,0},
            {91,92,149,3,2,2,0},
            {93,94,150,1,1,1,0},
            {95,96,151,1,1,3,0},
            {97,100,152,3,1,1,0},
            };
        for (int b = 0;
             b < ffnL4Rows();
             ++b) {
            int vals[7];
            vals[0] = ffnL4Lo(b);
            vals[1] = ffnL4Hi(b);
            vals[2] = ffnL4Ord(b);
            vals[3] = ffnL4Src(b);
            vals[4] = ffnL4NumMin(b);
            vals[5] = ffnL4NumMax(b);
            vals[6] = ffnL4Sp(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CL4[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL V GRID: the 33 die rows, one row per band (die
        // low, die high, roster ord, source, number min, number max,
        // special). Rows: Ankheg 01-04 (numbers 1-3, src MM1): printed
        // "Anhkheg" (both voices); AC 2/4 MV 12" (6") HD 7 #AT 1 D 3-18
        // (+1-4) +S; Cerebral Parasite 05-06 (numbers 1-3, src MM1): AC Nil
        // MV Nil HD Nil #AT 0 D S; Character 07-19: the routing row: see the
        // Character Subtable; Cockatrice 20-25 (numbers 1-2, src MM1): AC 6
        // MV 6"/18" HD 5 #AT 1 D 1-3 +S; Crypt Thing 26 (numbers 1-1, src
        // FF): AC 3 MV 12" HD 6 #AT 1 D 1-8 +S; Displacer Beast 27-28
        // (numbers 1-2, src MM1): AC 4 MV 15" HD 6 #AT 2 D 2-8/2-8;
        // Doppelganger 29-30 (numbers 1-3, src MM1): printed "Doppleganger";
        // AC 5 MV 9" HD 4 #AT 1 D 1-12 +S; Dragon 31-32: the routing row: see
        // the Dragon Subtable (Level V); Drow 33 (numbers 3-12, src FF):
        // printed "Elf, drow" (ink "Elf. drow"); AC 4 (+) MV 12" or 15" HD 2
        // (+) #AT 1 or 2 D BW; Githyanki 34 (numbers 1-4, src FF): AC All
        // Variable (the ink row garbles in both voices) HD Variable #AT 1 D
        // BW; Githzerai 35 (numbers 1-4, src FF): AC All Variable (the ink
        // row garbles in both voices) HD Variable #AT 1 D BW +S; Hydra 36-39
        // (numbers 1-1, src MM1): AC 5 MV 9" HD 7 #AT 7 D 1-8 (x7) +S;
        // Pyrohydra 40 (numbers 1-1, src unkeyed): printed "Hydra, pyro-"; no
        // registry def keys the pyrohydra (unkeyed); AC 5 MV 9" HD 6 #AT 6 D
        // 1-8 (x6) +S; Ice Lizard 41-42 (numbers 1-2, src FF): AC 1 MV 9"/15"
        // HD 3+3 (ink 34-3) #AT 3 D 1-3/1-3/1-6 +S; Imp 43 (numbers 1-2, src
        // MM1): AC 2 MV 6"/18" HD 2+2 #AT 1 D 1-4 +S; Khargra 44 (numbers
        // 1-2, src FF): AC -3 MV 3"/15" HD 6 #AT 1 D 3-18 +S; Leucrotta 45-47
        // (numbers 1-2, src MM1): AC 4 MV 18" HD 6+1 #AT 1 D 3-18;
        // Subterranean Lizard 48-55 (numbers 1-3, src MM1): printed "Lizard,
        // subterranean"; AC 5 MV 12" HD 6 #AT 1 D 2-12; Werebear 56-59
        // (numbers 1-3, src MM1): printed "Lycanthrope, werebear" (ink
        // "werebaar"); AC 4 MV 12" HD 5+2 #AT 1 D 2-12; Minotaur 60-63
        // (numbers 1-3, src MM1): AC 6 MV 12" HD 6+3 #AT 2 D 2-8 or 1-4/BW;
        // Phantom Stalker 64-65 (numbers 1-1, src FF): AC 3 MV 12"/24" HD 6
        // #AT 2 D 1-4/1-4 +S; Quasit 66 (numbers 1-1, src MM1): AC 2 MV 15"
        // HD 3 #AT 3 D 1-2/1-2/1-4 +S; Shadow 67-69 (numbers 1-3, src MM1):
        // AC 7 MV 12" HD 3+3 #AT 1 D 2-5 +S; Slithering Tracker 70-71
        // (numbers 1-1, src MM1): AC 5 MV 12" HD 5 #AT 0 D S; Amphisbaena
        // Snake 72-73 (numbers 1-1, src MM1): printed "Snake, giant,
        // amphisbaena"; AC 3 MV 12" HD 6 #AT 2 D 1-3/1-3 +S; Poisonous Snake
        // 74-81 (numbers 1-1, src MM1): printed "Snake, giant, poisonous"; AC
        // 5 MV 15" HD 4+2 #AT 1 D 1-3 +S; Spitting Snake 82-85 (numbers 1-1,
        // src MM1): printed "Snake, giant, spitting"; AC 5 MV 12" HD 4+2 #AT
        // 1 D 1-3 +S; Giant Spider 86-93 (numbers 1-2, src MM1): printed
        // "Spider, giant"; AC 4 MV 3"/12" HD 4+4 #AT 1 D 2-8 +S; Svirfneblin
        // 94-95 (numbers 2-5, src FF): printed "Svirfneblin" (ink
        // "Svirfneblln", both voices); AC (blank in the ink) MV 9" HD 3+6 #AT
        // 1 or 2 D BW +S; Tentamort 96-97 (numbers 1-2, src FF): printed
        // "Tentamort" (ink "Tent amort"); AC 3 (ink m) MV 1" HD 2/4 #AT 2 D
        // 1-6/1-6 +S; Trilloch 98 (numbers 1-1, src FF): AC n/a MV 12" HD n/a
        // #AT n/a D S; Umpleby 99 (numbers 1-1, src FF): AC 4 MV 9" HD 6 #AT
        // 1 D 1-4 +S; Xill 00 (numbers 1-2, src FF): printed "Xill" (ink
        // "XIII", both voices); AC 0 MV 15" (the def reads 12") HD 5 #AT 4 D
        // 1-4 (x4) BW +S.
        int CL5[33][7] = {
            {1,4,33,1,1,3,0},
            {5,6,6,1,1,3,0},
            {7,19,37,0,0,0,1},
            {20,25,153,1,1,2,0},
            {26,26,154,3,1,1,0},
            {27,28,155,1,1,2,0},
            {29,30,156,1,1,3,0},
            {31,32,73,0,0,0,2},
            {33,33,74,3,3,12,0},
            {34,34,157,3,1,4,0},
            {35,35,158,3,1,4,0},
            {36,39,133,1,1,1,0},
            {40,40,134,4,1,1,0},
            {41,42,159,3,1,2,0},
            {43,43,160,1,1,2,0},
            {44,44,161,3,1,2,0},
            {45,47,162,1,1,2,0},
            {48,55,163,1,1,3,0},
            {56,59,164,1,1,3,0},
            {60,63,165,1,1,3,0},
            {64,65,166,3,1,1,0},
            {66,66,167,1,1,1,0},
            {67,69,168,1,1,3,0},
            {70,71,169,1,1,1,0},
            {72,73,170,1,1,1,0},
            {74,81,171,1,1,1,0},
            {82,85,172,1,1,1,0},
            {86,93,173,1,1,2,0},
            {94,95,174,3,2,5,0},
            {96,97,175,3,1,2,0},
            {98,98,176,3,1,1,0},
            {99,99,177,3,1,1,0},
            {100,100,178,3,1,2,0},
            };
        for (int b = 0;
             b < ffnL5Rows();
             ++b) {
            int vals[7];
            vals[0] = ffnL5Lo(b);
            vals[1] = ffnL5Hi(b);
            vals[2] = ffnL5Ord(b);
            vals[3] = ffnL5Src(b);
            vals[4] = ffnL5NumMin(b);
            vals[5] = ffnL5NumMax(b);
            vals[6] = ffnL5Sp(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CL5[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL VI GRID: the 40 die rows, one row per band (die
        // low, die high, roster ord, source, number min, number max,
        // special). Rows: Ankheg 01-02 (numbers 1-3, src MM1): printed
        // "Anhkheg" (both voices); AC 2/4 MV 12" (6") HD 8 #AT 1 D 3-18
        // (+1-4) +S; Apparition 03 (numbers 1-1, src FF): AC 0 MV 24" HD 8
        // #AT 1 D S; Basilisk 04-07 (numbers 1-1, src MM1): AC 4 MV 6" HD 6+1
        // #AT 1 D 1-10 +S; Carrion Crawler 08-11 (numbers 1-2, src MM1): AC
        // 3/7 MV 12" HD 3+1 #AT 8 D S; Character 12-19: the routing row: see
        // the Character Subtable; Erinyes 20 (numbers 1-2, src MM1): printed
        // "Devil, erinyes"; AC 2 MV 6"/21" HD 6+6 #AT 1 D 2-8 +S; Djinni 21
        // (numbers 1-1, src MM1): printed "Djinn*" (ink "D|inn*"); AC 4 MV
        // 9"/24" HD 7+3 #AT 1 D 2-16 +S; Dragon 22-23: the routing row: see
        // the Dragon Subtable (Level VI); Green Slime 24-26 (numbers 0-0, src
        // MM1): numbers - (the ink dash); AC 9 MV 0" HD 2 #AT 0 D 3; Hellcat
        // 27-29 (numbers 1-1, src FF): AC 6 MV 12" HD 7+2 #AT 3 D
        // 2-5/2-5/2-12; Hydra 30-33 (numbers 1-1, src MM1): AC 5 MV 9" HD 9
        // #AT 9 D 1-8 (x9) +S; Pyrohydra 34 (numbers 1-1, src unkeyed):
        // printed "Hydra, pyro"; no registry def keys the pyrohydra
        // (unkeyed); AC 5 MV 9" HD 7 #AT 7 D 1-8 (x7) +S; Jackalwere 35-36
        // (numbers 1-2, src MM1): printed "Jackal were"; AC 4 MV 12" HD 4 #AT
        // 1 D 2-8 +S; Lammasu 37-38 (numbers 1-3, src MM1): AC 6 MV 12"/24"
        // HD 7+7 #AT 2 D 1-6/1-6 +S; Lizard King 39 (numbers 1-1, src FF): AC
        // 3 MV 15"/12" HD 8 #AT 1 D 5-20 +S; Werebear 40-41 (numbers 1-1, src
        // MM1): printed "Lycanthrope, werebear"; AC 2 MV 9" HD 7+3 #AT 3 D
        // 1-3/1-3/2-8 +S (ink Z-8); Weretiger 42-43 (numbers 1-2, src MM1):
        // printed "Lycanthrope, weretiger" (ink "Lycantftrope, were tiger");
        // AC 3 MV 12" HD 6+2 #AT 3 D 1-4/1-4/1-12 +S; Manticore 44-47
        // (numbers 1-2, src MM1): printed "Manticore" (ink "M anti core",
        // both voices); AC 4 MV 12"/18" HD 6+3 #AT 3 D 1-3/1-3/1-8 +S; Medusa
        // 48-49 (numbers 1-1, src MM1): AC 5 MV 9" HD 6 #AT 1 D 1-4 +S;
        // Yellow Mold 50 (numbers 0-0, src MM1): numbers - (the ink dash);
        // printed "Mold, yellow"; AC 9 MV 0" HD n/a #AT 1 D 1-8 +S; Nightmare
        // 51 (numbers 1-4, src MM1): AC -4 MV 15"/36" HD 6+6 #AT 3 D
        // 2-8/4-10/4-10; Ogre Magi 52-53 (numbers 1-2, src MM1): printed
        // "Ogre mage"; AC 4 MV 9"/15" HD 5+2 #AT 1 D 1-12 +S; Otyugh 54-59
        // (numbers 1-1, src MM1): AC 3 MV 6" HD 6-8 #AT 3 D 1-8/1-8/2-5 +S;
        // Penanggalan 60-61 (numbers 1-1, src FF): printed "Penanggalan*"; AC
        // 10/8 MV 12"/9" HD Var #AT 1 D 1-6 +S; Protein Polymorph 62-63
        // (numbers 1-1, src FF): AC 2 MV 9" HD 6-8 #AT Var. D BW/6-36;
        // Rakshasa 64-65 (numbers 1-4, src MM1): AC -4 MV 15" HD 7 #AT 3 D
        // 1-3/1-3/2-5 +S; Salamander 66-67 (numbers 1-2, src MM1): AC 5/3 MV
        // 9" HD 7+7 #AT 2 D BW/2-12; Giant Scorpion 68-71 (numbers 1-3, src
        // MM1): printed "Scorpion, giant"; AC 3 MV 15" HD 5+5 #AT 3 D
        // 1-10/1-10/1-4 +S; Red Slaad 72 (numbers 1-1, src FF): printed
        // "Slaad, red"; AC 6 MV 6" (9") HD 7 #AT 3 D 1-4/1-4/2-16 +S; Phase
        // Spider 73-74 (numbers 1-3, src MM1): printed "Spider, phase"; AC 7
        // MV 6"/15" HD 5+5 #AT 1 D 1-6 +S; Spirit Troll 75 (numbers 1-1, src
        // FF): AC 2 MV 15" HD 5+5 #AT 3 D 1-6/1-3/1-3 +S; Sussurus 76
        // (numbers 1-1, src FF): AC 4 MV 15" HD 8 #AT 2 D 1-8/1-8 (ink
        // 1-B/1-8; the def reads 1-8/1-8); Terithran 77 (numbers 1-1, src
        // FF): AC 3 (6) MV 15" (18") HD 5+1 (ink 5-1) #AT 2 D 2-5/2-5 +S;
        // Troll 78-83 (numbers 1-3, src MM1): AC 4 MV 12" HD 6+6 #AT 3 D
        // 5-8/5-8/2-12; Giant Troll 84-85 (numbers 1-2, src FF): printed
        // "Troll, giant"; AC 4 MV 12" HD 8 #AT 1 D 2-16; Vision 86 (numbers
        // 1-1, src FF): AC 0 (10) MV 15" HD 8 #AT Nil D S; Wight 87-90
        // (numbers 1-4, src MM1): AC 5 MV 12" HD 4+3 #AT 1 D 1-4 +S; Wind
        // Walker 91-92 (numbers 1-1, src MM1): AC 7 MV 15"/30" HD 6+3 #AT 1 D
        // 3-18; Wraith 93-96 (numbers 1-2, src MM1): AC 4 MV 12"/24" HD 5+3
        // #AT 1 D 1-6 +S; Wyvern 97-00 (numbers 1-1, src MM1): printed
        // "Wyvern" (ink "Wyvem", both voices); AC 3 MV 6"/24" HD 7+7 #AT 2 D
        // 2-16/1-6 +S.
        int CL6[40][7] = {
            {1,2,33,1,1,3,0},
            {3,3,179,3,1,1,0},
            {4,7,180,1,1,1,0},
            {8,11,181,1,1,2,0},
            {12,19,37,0,0,0,1},
            {20,20,182,1,1,2,0},
            {21,21,183,1,1,1,0},
            {22,23,73,0,0,0,2},
            {24,26,184,1,0,0,0},
            {27,29,185,3,1,1,0},
            {30,33,133,1,1,1,0},
            {34,34,134,4,1,1,0},
            {35,36,186,1,1,2,0},
            {37,38,187,1,1,3,0},
            {39,39,188,3,1,1,0},
            {40,41,164,1,1,1,0},
            {42,43,189,1,1,2,0},
            {44,47,190,1,1,2,0},
            {48,49,191,1,1,1,0},
            {50,50,140,1,0,0,0},
            {51,51,192,1,1,4,0},
            {52,53,193,1,1,2,0},
            {54,59,194,1,1,1,0},
            {60,61,195,3,1,1,0},
            {62,63,196,3,1,1,0},
            {64,65,197,1,1,4,0},
            {66,67,198,1,1,2,0},
            {68,71,199,1,1,3,0},
            {72,72,200,3,1,1,0},
            {73,74,201,1,1,3,0},
            {75,75,202,3,1,1,0},
            {76,76,203,3,1,1,0},
            {77,77,204,3,1,1,0},
            {78,83,205,1,1,3,0},
            {84,85,206,3,1,2,0},
            {86,86,207,3,1,1,0},
            {87,90,208,1,1,4,0},
            {91,92,209,1,1,1,0},
            {93,96,210,1,1,2,0},
            {97,100,211,1,1,1,0},
            };
        for (int b = 0;
             b < ffnL6Rows();
             ++b) {
            int vals[7];
            vals[0] = ffnL6Lo(b);
            vals[1] = ffnL6Hi(b);
            vals[2] = ffnL6Ord(b);
            vals[3] = ffnL6Src(b);
            vals[4] = ffnL6NumMin(b);
            vals[5] = ffnL6NumMax(b);
            vals[6] = ffnL6Sp(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CL6[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL VII GRID: the 58 die rows, one row per band (die
        // low, die high, roster ord, source, number min, number max,
        // special). Rows: Black Pudding 01-04 (numbers 1-1, src MM1): AC 6 MV
        // 6" HD 10 #AT 1 D 3-24 +S; Bulette 05 (numbers 1-1, src MM1):
        // printed "Bulette" (ink "BuJette", both voices); AC -2/4/6 MV 14"
        // (3") HD 9 #AT 3 D 4-48/3-18/3-18 +S; Character 06-12: the routing
        // row: see the Character Subtable; Chimera 13-14 (numbers 1-2, src
        // MM1): AC 6/5/2 MV 9"/18" HD 9 #AT 6 D 1-3/1-3/1-4/1-4/2-8/3-12 +S;
        // Cifal 15-16 (numbers 1-2, src FF): AC 6 MV 6" HD 6 (10) #AT 1 D
        // 1-12; Couatl 17 (numbers 1-1, src MM1): printed "Couatl" (ink
        // "Couall"); AC 5 MV 18"/9" HD 9 #AT 2 D 1-3/2-8 +S; Succubus 18
        // (numbers 1-1, src MM1): printed "Demon, succubus"; AC 0 MV 12"/18"
        // HD 6 #AT 2 D 1-3/1-3 +S; Type I (vrock) 19 (numbers 1-1, src MM1):
        // printed "Demon, type I (vrock)"; AC 0 MV 12"/18" HD 8 #AT 5 D
        // 1-4/1-4/1-8/1-8/1-6 +S; Type II (hezrou) 20 (numbers 1-1, src MM1):
        // printed "Demon, type II (hezrou)"; AC -2 MV 6"//12" HD 9 #AT 3 D
        // 1-3/1-3/4-16 +S; Type III (glabrezu) 21 (numbers 1-1, src MM1):
        // printed "Demon, type III (glabrezu)"; AC -4 MV 9" HD 10 #AT 5 D
        // 2-12/2-12/1-3/1-3/2-5 +S; Barbed Devil 22 (numbers 1-1, src MM1):
        // printed "Devil, barbed"; AC 0 MV 12" HD 6 #AT 3 D 2-8/2-8/3-12 +S
        // (ink 2-0/2-8); Bone Devil 23 (numbers 1-1, src MM1): printed
        // "Devil, bone"; AC -1 MV 15" HD 9 #AT 1 D 3-12 +S; Horned Devil 24
        // (numbers 1-1, src MM1): printed "Devil, horned"; AC -5 MV 9"/18" HD
        // 5+5 #AT 4 or 1+1 D 1-4/1-4/2-5/1-3 or 1-3/BW; Styx Devil 25
        // (numbers 1-1, src FF): printed "Devil, styx"; AC -1 MV 6"/15" HD
        // 6+6 #AT 1 D 2-6; Dragon 26-27: the routing row: see the Dragon
        // Subtable (Level VII); Efreeti 28 (numbers 1-1, src MM1): printed
        // "Efreeti" (ink "Efreeti" reading 23 in both voices, repaired to
        // 28); AC 2 MV 9"/24" HD 10 #AT 1 D 3-24 +S; Elemental 29-30: the
        // elemental group (choose, or use equal probabilities as applicable):
        // Air AC 2 MV 36" HD 12 #AT 1 D 2-20 +S; Earth AC 2 MV 6" HD 12 #AT 1
        // D 4-32 +S; Fire AC 2 MV 12" HD 12 #AT 1 D 3-24 +S; Water AC 2 MV
        // 0"/18" HD 12 #AT 1 D 5-30 +S; Ettin 31 (numbers 1-2, src MM1):
        // printed "Ettin" (ink "Ettln", both voices); AC 3 MV 12" HD 10 #AT 2
        // D 2-16/3-18; Eye of Fear and Flame 32 (numbers 1-1, src FF): AC 2
        // MV 9" HD 12 #AT S D S; Fire Giant 33-34 (numbers 1-2, src MM1):
        // printed "Giant, fire"; AC 3 MV 12" HD 11+2-5 #AT 1 D 5-30 +S; Frost
        // Giant 35 (numbers 1-2, src MM1): printed "Giant, frost"; AC 4 MV
        // 12" HD 10+1-4 #AT 1 D 4-24 +S; Hill Giant 36-38 (numbers 1-3, src
        // MM1): printed "Giant, hill"; AC 4 MV 12" HD 8+1-2 #AT 1 D 2-16 +S;
        // Mountain Giant 39 (numbers 1-2, src FF): printed "Giant, mountain";
        // AC 4 MV 12" HD 12 #AT 1 D 4-40 +S; Stone Giant 40-41 (numbers 1-3,
        // src MM1): printed "Giant, stone"; AC 0 MV 12" HD 9+1-3 #AT 1 D 3-18
        // +S; Flesh Golem 42 (numbers 1-1, src MM1): printed "Golem, flesh";
        // AC 9 MV 8" HD 40 hp #AT 2 D 2-16/2-16 +S; Gorgon 43-44 (numbers
        // 1-1, src MM1): AC 2 MV 12" HD 8 #AT 1 D 2-12 +S; Groaning Spirit 45
        // (numbers 1-1, src MM1): AC 0 MV 15" HD 7 #AT 1 D 1-8 +S; Guardian
        // Daemon 46 (numbers 1-1, src FF): AC 1 MV 9" (S) HD 8 #AT 3 D
        // 1-6/1-12/1-12 +S; Guardian Familiar 47 (numbers 1-1, src FF): AC 8
        // MV 12" HD 1 (9) #AT 3 D 1-6/1-4/1-4; Hydra 48-51 (numbers 1-1, src
        // MM1): AC 5 MV 9" HD 10 #AT 10 D 1-10 (x10); Pyrohydra 52 (numbers
        // 1-1, src unkeyed): printed "Hydra, pyro"; no registry def keys the
        // pyrohydra (unkeyed); AC 5 MV 9" HD 8 #AT 8 D 1-10 (x8) +S;
        // Intellect Devourer 53 (numbers 1-1, src MM1): printed "Intellect
        // devourer"; AC 4 MV 15" HD 6+6 #AT 4 D 1-4 (x4) +S; Invisible
        // Stalker 54 (numbers 1-1, src MM1): AC 3 MV 12" HD 8 #AT 1 D 4-16
        // +S; Lamia 55 (numbers 1-2, src MM1): AC 3 MV 24" HD 9 #AT 1 D 1-4
        // +S; Lamia Noble 56 (numbers 1-1, src FF): printed "Lamia noble"
        // (ink "Lamia nobie"); AC 6 MV 9" HD 10+1 #AT 1 D 1-6 +S; Fire Lizard
        // 57 (numbers 1-3, src MM1): printed "Lizard, fire"; AC 3 MV 9" HD 10
        // #AT 3 D 1-8/1-8/2-16 +S; Lurker Above 58-61 (numbers 1-1, src MM1):
        // AC 6 MV 1"/9" HD 10 #AT 1 D 1-6 +S; Magnesium Spirit 62 (numbers
        // 1-1, src FF): printed "Magnesium spirit"; AC 0 MV 36" HD 6+1 #AT 1
        // D 3-12 +S; Mimic 63-64 (numbers 1-1, src MM1): AC 7 MV 3" HD 7-10
        // #AT 1 D 3-12 +S; Mind Flayer 65-66 (numbers 1-2, src MM1): AC 5 MV
        // 12" HD 8+4 #AT 4 D S; Mummy 67-68 (numbers 1-2, src MM1): AC 3 MV
        // 6" HD 6+3 #AT 1 D 1-12 +S; Spirit Naga 69-70 (numbers 1-2, src
        // MM1): printed "Naga, spirit"; AC 4 MV 12" HD 9-10 #AT 1 D 1-3 +S;
        // Neo-Otyugh 71-72 (numbers 1-1, src MM1): AC 0 MV 6" HD 9-12 #AT 3 D
        // 2-12/2-12/1-3 +S; Night Hag 73 (numbers 1-2, src MM1): AC 9 MV 9"
        // HD 8 #AT 1 D 2-12 +S; Nonafel 74 (numbers 1-1, src FF): AC 5 (6) MV
        // 9" (12") HD 9 #AT 1 D 2-20 or 1-8; Revenant 75 (numbers 1-1, src
        // FF): AC 10 MV 9" HD 8 #AT 1 D 2-16 +S; Roper 76-77 (numbers 1-2,
        // src MM1): AC 0 MV 3" HD 10-12 #AT 1 D 5-20 +S; Shambling Mound
        // 78-79 (numbers 1-2, src MM1): AC 0 MV 6" HD 8-11 #AT 2 D 2-16/2-16
        // +S; Shedu 80-81 (numbers 1-2, src MM1): printed "Shedu" (ink
        // "Sbedu", both voices); AC 4 MV 12"/24" HD 9+9 #AT 2 D 1-6/1-6 +S;
        // Slaad (Blue) 82 (numbers 1-1, src FF): printed "Slaad, blue"; AC 5
        // MV 7" HD 8+4 #AT 5 D 2-16/2-12 (x4) +S; Giant Slug 83-86 (numbers
        // 1-1, src MM1): printed "Slug, giant"; AC 8 MV 6" HD 12 #AT 1 D 1-12
        // +S; Spectre 87-88 (numbers 1-1, src MM1): AC 2 MV 15"/30" HD 7+3
        // #AT 1 D 1-8 +S; Sphinx 89-90: the routing row: see the Sphinx
        // Subtable; Trapper 91-92 (numbers 1-1, src MM1): AC 3 MV 3" HD 12
        // #AT 4 + D S (the ink reads 4 +); Giant Two-Headed Troll 93 (numbers
        // 1-1, src FF): printed "Troll, giant two-headed"; AC 4 MV 12" HD 10
        // #AT 4 D 1-6/1-6/1-10/1-10; Umber Hulk 94-95 (numbers 1-2, src MM1):
        // AC 2 MV 6" (1"-6") HD 8+8 #AT 3 D 3-12/3-12/2-10 +S; Will-o-wisp
        // 96-99 (numbers 1-3, src MM1): printed "Will-o-wisp" (ink "Wil
        // i-o-wisp"); AC -8 MV 18" HD 9 #AT 1 D 2-16 +S; Xorn 00 (numbers
        // 1-3, src MM1): printed "Xorn" (ink "Korn", both voices); AC -2 MV
        // 9" HD 7+7 #AT 4 D 1-3 (x3)/6-24 +S.
        int CL7[58][7] = {
            {1,4,212,1,1,1,0},
            {5,5,213,1,1,1,0},
            {6,12,37,0,0,0,1},
            {13,14,214,1,1,2,0},
            {15,16,215,3,1,2,0},
            {17,17,216,1,1,1,0},
            {18,18,217,1,1,1,0},
            {19,19,218,1,1,1,0},
            {20,20,219,1,1,1,0},
            {21,21,220,1,1,1,0},
            {22,22,221,1,1,1,0},
            {23,23,222,1,1,1,0},
            {24,24,223,1,1,1,0},
            {25,25,224,3,1,1,0},
            {26,27,73,0,0,0,2},
            {28,28,225,1,1,1,0},
            {29,30,226,0,0,0,5},
            {31,31,227,1,1,2,0},
            {32,32,228,3,1,1,0},
            {33,34,229,1,1,2,0},
            {35,35,230,1,1,2,0},
            {36,38,231,1,1,3,0},
            {39,39,232,3,1,2,0},
            {40,41,233,1,1,3,0},
            {42,42,234,1,1,1,0},
            {43,44,235,1,1,1,0},
            {45,45,236,1,1,1,0},
            {46,46,237,3,1,1,0},
            {47,47,238,3,1,1,0},
            {48,51,133,1,1,1,0},
            {52,52,134,4,1,1,0},
            {53,53,239,1,1,1,0},
            {54,54,240,1,1,1,0},
            {55,55,241,1,1,2,0},
            {56,56,242,3,1,1,0},
            {57,57,243,1,1,3,0},
            {58,61,244,1,1,1,0},
            {62,62,245,3,1,1,0},
            {63,64,246,1,1,1,0},
            {65,66,247,1,1,2,0},
            {67,68,248,1,1,2,0},
            {69,70,249,1,1,2,0},
            {71,72,250,1,1,1,0},
            {73,73,251,1,1,2,0},
            {74,74,252,3,1,1,0},
            {75,75,253,3,1,1,0},
            {76,77,254,1,1,2,0},
            {78,79,255,1,1,2,0},
            {80,81,256,1,1,2,0},
            {82,82,257,3,1,1,0},
            {83,86,258,1,1,1,0},
            {87,88,259,1,1,1,0},
            {89,90,260,0,0,0,4},
            {91,92,261,1,1,1,0},
            {93,93,262,3,1,1,0},
            {94,95,263,1,1,2,0},
            {96,99,264,1,1,3,0},
            {100,100,265,1,1,3,0},
            };
        for (int b = 0;
             b < ffnL7Rows();
             ++b) {
            int vals[7];
            vals[0] = ffnL7Lo(b);
            vals[1] = ffnL7Hi(b);
            vals[2] = ffnL7Ord(b);
            vals[3] = ffnL7Src(b);
            vals[4] = ffnL7NumMin(b);
            vals[5] = ffnL7NumMax(b);
            vals[6] = ffnL7Sp(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CL7[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL VIII GRID: the 31 die rows, one row per band (die
        // low, die high, roster ord, source, number min, number max,
        // special). Rows: Aerial Servant 01 (numbers 1-1, src MM1): AC 3 MV
        // 24" HD 16 #AT 1 D 8-32; Cerebral Parasite 02-06 (numbers 2-8, src
        // MM1): AC n/a MV n/a HD n/a #AT 0 D S; Character 07-14: the routing
        // row: see the Character Subtable; Death Knight 15 (numbers 1-1, src
        // FF): AC 0 MV Var HD 9 #AT 1 D BW +S; Type IV Demon (nalfeshnee) 16
        // (numbers 1-1, src MM1): printed "Demon, type IV"; AC -1 MV 9"/12"
        // HD 11 #AT 3 D 1-4/1-4/2-8 +S; Type V Demon (marilith) 17 (numbers
        // 1-1, src MM1): printed "Demon, type V"; AC -7/-5 MV 12" HD 7+7 #AT
        // 7 D 2-8/d6 BW +S; Type VI Demon (balor) 18 (numbers 1-1, src MM1):
        // printed "Demon, type VI"; AC -2 MV 6"/15" HD 8+8 #AT 1 D 2-13 +S;
        // Ice Devil 19 (numbers 1-1, src MM1): printed "Devil, ice" (ink die
        // T9, repaired to 19); AC -4 MV 6" HD 11 #AT 4 D 1-4/1-4/2-8/3-12 +S;
        // Dragon 20-21: the routing row: see the Dragon Subtable (Level
        // VIII); Ghost 22-24 (numbers 1-1, src MM1): AC 0 (ink m; the def
        // reads 0 (or 8)) MV 9" HD 10 #AT 1 D S; Cloud Giant 25-26 (numbers
        // 1-2, src MM1): printed "Giant, cloud"; AC 2 MV 15" HD 12+2-7 #AT 1
        // D 6-36 +S; Fog Giant 29-30 (numbers 1-2, src FF): printed "Giant,
        // fog"; AC 1 MV 15" HD 14 #AT 1 D 4-24 +S; PRINT DEFECT: the ink
        // skips the die band 27-28 (the Giant, cloud row 25-26 jumps to the
        // Giant, fog row 29-30 in both voices), pinned as ink; Clay Golem
        // 31-32 (numbers 1-1, src MM1): printed "Golem, clay"; AC 7 MV 7" HD
        // 50 hp #AT 1 D 3-30 +S; Hydra 33-37 (numbers 1-1, src MM1): AC 5 MV
        // 9" HD 11 #AT 11 D 1-10 (x11) +S; Pyrohydra 38 (numbers 1-1, src
        // unkeyed): printed "Hydra, pyro"; no registry def keys the pyrohydra
        // (unkeyed); AC 5 MV 9" HD 9 #AT 9 D 1-10 (x9) +S; Intellect Devourer
        // 39-40 (numbers 1-2, src MM1): AC 4 MV 15" HD 6+6 #AT 4 D 1-4 (x4)
        // +S; Lurker Above 41-44 (numbers 1-1, src MM1): AC 6 MV 1"/9" HD 10
        // #AT 1 D 1-6 +S; Brown Mold 45-52 (numbers 0-0, src MM1): numbers -
        // (the ink dash); printed "Mold, brown"; AC 9 MV 0" HD 0 #AT 0 D S;
        // Mind Flayer 53-56 (numbers 1-4, src MM1): AC 5 MV 12" HD 8+4 #AT 4
        // D S; Guardian Naga 57-59 (numbers 1-2, src MM1): printed "Naga,
        // guardian"; AC 3 MV 15" HD 11-12 #AT 2 D 1-6/2-8 +S; Neo-Otyugh
        // 60-61 (numbers 1-2, src MM1): AC 0 MV 6" HD 9-12 #AT 3 D
        // 2-12/2-12/1-3 +S; Purple Worm 62-70 (numbers 1-1, src MM1): AC 6 MV
        // 9" HD 15 #AT 1 D 2-24/2-8 +S (the ink HD cell reads 15 161 in both
        // voices); Retriever 71-72 (numbers 1-1, src FF): AC -2 MV 18" HD 10
        // #AT 4 D 3-18 (x4); Rust Monster 73-75 (numbers 1-1, src MM1): AC 2
        // MV 18" (ink 16"; the def reads 18") HD 5 #AT 2 D S; Skeleton
        // Warrior 76 (numbers 1-1, src FF): AC 2 MV 6" HD 9+2 to 9+12 #AT 1 D
        // BW; Slaad, Green 77 (numbers 1-1, src unkeyed): printed "Slaad,
        // green" (ink "Siaad, green"); no registry def keys the green slaad
        // (unkeyed); AC 3 MV 9" HD 9+3 #AT 3 D 2-16/3-8/3-8 +S; Giant Slug
        // 78-80 (numbers 1-1, src MM1): printed "Slug, giant"; AC 8 MV 6" HD
        // 12 #AT 1 D 1-12 +S; Trapper 81-87 (numbers 1-1, src MM1): printed
        // "Trapper" (ink "T rapper"); AC 3 MV 3" HD 12 #AT 4 + D S; Vampire
        // 88-94 (numbers 1-1, src MM1): AC 1 MV 12"/18" HD 8+3 #AT 1 D 5-10
        // +S; Will-o-wisp 95-98 (numbers 2-5, src MM1): printed "Will-o-wisp"
        // (ink "Will-o-wlsp"); AC -8 MV 18" HD 9 #AT 1 D 2-16 +S; Xorn 99-00
        // (numbers 2-5, src MM1): AC -2 MV 9" HD 7+7 #AT 4 D 1-3 (x3)/6-24
        // +S.
        int CL8[31][7] = {
            {1,1,266,1,1,1,0},
            {2,6,6,1,2,8,0},
            {7,14,37,0,0,0,1},
            {15,15,267,3,1,1,0},
            {16,16,268,1,1,1,0},
            {17,17,269,1,1,1,0},
            {18,18,270,1,1,1,0},
            {19,19,271,1,1,1,0},
            {20,21,73,0,0,0,2},
            {22,24,272,1,1,1,0},
            {25,26,273,1,1,2,0},
            {29,30,274,3,1,2,0},
            {31,32,275,1,1,1,0},
            {33,37,133,1,1,1,0},
            {38,38,134,4,1,1,0},
            {39,40,239,1,1,2,0},
            {41,44,244,1,1,1,0},
            {45,52,276,1,0,0,0},
            {53,56,247,1,1,4,0},
            {57,59,277,1,1,2,0},
            {60,61,250,1,1,2,0},
            {62,70,278,1,1,1,0},
            {71,72,279,3,1,1,0},
            {73,75,142,1,1,1,0},
            {76,76,280,3,1,1,0},
            {77,77,281,4,1,1,0},
            {78,80,258,1,1,1,0},
            {81,87,261,1,1,1,0},
            {88,94,282,1,1,1,0},
            {95,98,264,1,2,5,0},
            {99,100,265,1,2,5,0},
            };
        for (int b = 0;
             b < ffnL8Rows();
             ++b) {
            int vals[7];
            vals[0] = ffnL8Lo(b);
            vals[1] = ffnL8Hi(b);
            vals[2] = ffnL8Ord(b);
            vals[3] = ffnL8Src(b);
            vals[4] = ffnL8NumMin(b);
            vals[5] = ffnL8NumMax(b);
            vals[6] = ffnL8Sp(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CL8[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL IX GRID: the 23 die rows, one row per band (die
        // low, die high, roster ord, source, number min, number max,
        // special). Rows: Achaierai 01-03 (numbers 1-2, src FF): AC 8/-1 MV
        // 18" HD 40 hp/15 hp #AT 3 D 1-8/1-8/1-10; Bulette 04-06 (numbers
        // 1-3, src MM1): AC -2/4/6 MV 14" (3") HD 9 #AT 3 D 4-48/3-18/3-18
        // +S; Character 07-16: the routing row: see the Character Subtable
        // (the ink reads "Character Suitable"); Pit Fiend 17-19 (numbers 1-1,
        // src MM1): printed "Devil, pit fiend"; AC -3 MV 6"/15" HD 13 #AT 2 D
        // 5-8/7-12 +S; Dragon 20-22: the routing row: see the Dragon Subtable
        // (Level IX); Storm Giant 23-28 (numbers 1-2, src MM1): printed
        // "Giant, storm"; AC 1 MV 15" HD 15+2-7 #AT 1 D 7-42 +S; Stone Golem
        // 29-30 (numbers 1-1, src MM1): printed "Golem, stone"; AC 5 MV 6" HD
        // 60 hp #AT 1 D 3-24 +S; Gorgon 31-33 (numbers 1-2, src MM1): AC 2 MV
        // 12" HD 8 #AT 1 D 2-12 +S; Hydra 34-40 (numbers 1-1, src MM1): AC 5
        // MV 9" HD 12 #AT 12 D 1-10 (x12) +S; Pyrohydra 41-43 (numbers 1-1,
        // src unkeyed): printed "Hydra, pyro-"; no registry def keys the
        // pyrohydra (unkeyed); AC 5 MV 9" HD 10 #AT 10 D 1-10 (x10) +S;
        // Ki-rin 44-45 (numbers 1-1, src MM1): AC -5 MV 24"/48" HD 12 #AT 3 D
        // 2-8/2-8/3-18 +S; Guardian Naga 46-47 (numbers 1-3, src MM1):
        // printed "Naga, guardian" (ink die 46*47, repaired to 46-47); AC -3
        // MV 15" HD 11-12 #AT 2 D 1-6/2-8 +S; Nycadaemon 48-49 (numbers 1-1,
        // src FF): printed "Nycadaemon" (ink "My cad demon", both voices; ink
        // die 48*49, repaired to 48-49); AC -4 MV 12"/36" HD 12+36 #AT 2 or 1
        // D 9-16/9-16 or BW +S (the def reads +6; the ink reads +S); Purple
        // Worm 50-61 (numbers 1-1, src MM1): AC 6 MV 9" HD 15 #AT 1 D
        // 2-24/2-8 +S (the ink reads 15 141); Retriever 62-64 (numbers 1-1,
        // src FF): AC -2 MV 18" HD 10 #AT 4 D 3-18 (x4) +S; Rust Monster
        // 65-67 (numbers 1-1, src MM1): AC 2 MV 18" HD 5 #AT 2 D S; Slaad
        // (Grey) 68-69 (numbers 1-1, src FF): printed "Slaad, grey"; AC 1 MV
        // 12" HD 10+6 #AT 3 or 2 D 2-16/4-10/4-10 or 2 BW + 1-8 +S; Lesser
        // Titan (AC 2) 70-72 (numbers 1-1, src MM1): printed "Titan, lesser";
        // AC 2 MV 21" HD 17 #AT 1 D 7-42 +S; Major Titan (AC 0) 73-75
        // (numbers 1-1, src MM1): printed "Titan, major"; AC 0 MV 15" HD 19
        // #AT 1 D 7-42 +S; Umber Hulk 76-82 (numbers 1-4, src MM1): AC 2 MV
        // 6" HD 8+8 #AT 3 D 3-12/3-12/2-10 +S; Vampire 83-85 (numbers 1-1,
        // src MM1): printed "Vampire*" (ink die 83-65, repaired to 83-85); AC
        // 1 MV 12"/18" HD 6+3 #AT 1 D 5-10 +S; the print footnote reads:
        // former evil cleric, with full powers of 7th-10th level; Will-o-wisp
        // 86-94 (numbers 2-5, src MM1): printed "Will-o-wisp" (ink
        // "Wilt-o-wisp"); AC -8 MV 18" HD 9 #AT 1 D 2-16 +S; Xorn 95-00
        // (numbers 2-9, src MM1): AC -2 MV 9" HD 7+7 #AT 4 D 1-3 (x3)/6-24 +S
        // (numbers 2-9 in both voices; the def reads 2-5).
        int CL9[23][7] = {
            {1,3,283,3,1,2,0},
            {4,6,213,1,1,3,0},
            {7,16,37,0,0,0,1},
            {17,19,284,1,1,1,0},
            {20,22,73,0,0,0,2},
            {23,28,285,1,1,2,0},
            {29,30,286,1,1,1,0},
            {31,33,235,1,1,2,0},
            {34,40,133,1,1,1,0},
            {41,43,134,4,1,1,0},
            {44,45,287,1,1,1,0},
            {46,47,277,1,1,3,0},
            {48,49,288,3,1,1,0},
            {50,61,278,1,1,1,0},
            {62,64,279,3,1,1,0},
            {65,67,142,1,1,1,0},
            {68,69,289,3,1,1,0},
            {70,72,290,1,1,1,0},
            {73,75,291,1,1,1,0},
            {76,82,263,1,1,4,0},
            {83,85,282,1,1,1,0},
            {86,94,264,1,2,5,0},
            {95,100,265,1,2,9,0},
            };
        for (int b = 0;
             b < ffnL9Rows();
             ++b) {
            int vals[7];
            vals[0] = ffnL9Lo(b);
            vals[1] = ffnL9Hi(b);
            vals[2] = ffnL9Ord(b);
            vals[3] = ffnL9Src(b);
            vals[4] = ffnL9NumMin(b);
            vals[5] = ffnL9NumMax(b);
            vals[6] = ffnL9Sp(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CL9[b][c])
                    ++bad;
            }
        }
        // THE MONSTER LEVEL X GRID: the 15 die rows, one row per band (die
        // low, die high, roster ord, source, number min, number max,
        // special). Rows: Beholder 01-12 (numbers 1-1, src MM1): AC 0/2/7 D
        // (blank in the ink); Catoblepas 13-19 (numbers 1-1, src MM1):
        // printed "Catoblepas" (ink "CatobJepas"); AC (blank in the ink) D
        // (blank in the ink); Character 20-26: the routing row: see the
        // Character Subtable; Demon Prince 27-29 (numbers 1-1, src unkeyed):
        // printed "Demon, prince*"; no registry def keys the row (unkeyed);
        // AC (blank in the ink) D (blank in the ink); select one or find
        // randomly; Arch Devil 30 (numbers 1-1, src unkeyed): printed "Devil,
        // arch-*"; no registry def keys the row (unkeyed); AC (blank in the
        // ink) D (blank in the ink); select one or find randomly; Dragon
        // 31-39: the routing row: see the Dragon Subtable (Level X);
        // Elemental Prince of Evil 40-41 (numbers 1-1, src unkeyed): printed
        // "Elemental prince of evil*"; no registry def keys the row
        // (unkeyed); AC Var (ink Van) D (blank in the ink); select one or
        // find randomly; Iron Golem 42-50 (numbers 1-1, src MM1): printed
        // "Golem, iron"; D 4-40 +S; Lamia Noble 51-53 (numbers 1-1, src FF):
        // printed "Lamia noble"; D 1-6 +S; Lich 54-62 (numbers 1-1, src MM1):
        // printed "Lich" (ink "Uch", both voices); D 1-10 +S; Purple Worm
        // 63-75 (numbers 1-1, src MM1): printed "Purple worm"; D 2-24/2-8 +S;
        // Slaad (Death) 76-78 (numbers 1-1, src FF): printed "Slaad, death"
        // (ink "Siaad, death"); D 2-20/3-18/3-18 or 2 +1-8 +S; Slaad Lord 79
        // (numbers 1-1, src unkeyed): printed "Slaad, lord*"; no registry def
        // keys the row (unkeyed); D 2-16/2-16/2-16 +S; select one or find
        // randomly; Elder Titan (AC -2) 80-89 (numbers 1-1, src MM1): printed
        // "Titan, elder" (ink "Titan, eider"); D 8-48 +S; Vampire 90-00
        // (numbers 1-1, src MM1): printed "Vampire*"; D 5-10 +S; the print
        // footnote reads: former magic-user, with full powers, of 9th-12th
        // level.
        int CL10[15][7] = {
            {1,12,292,1,1,1,0},
            {13,19,293,1,1,1,0},
            {20,26,37,0,0,0,1},
            {27,29,294,4,1,1,0},
            {30,30,295,4,1,1,0},
            {31,39,73,0,0,0,2},
            {40,41,296,4,1,1,0},
            {42,50,297,1,1,1,0},
            {51,53,242,3,1,1,0},
            {54,62,298,1,1,1,0},
            {63,75,278,1,1,1,0},
            {76,78,299,3,1,1,0},
            {79,79,300,4,1,1,0},
            {80,89,301,1,1,1,0},
            {90,100,282,1,1,1,0},
            };
        for (int b = 0;
             b < ffnL10Rows();
             ++b) {
            int vals[7];
            vals[0] = ffnL10Lo(b);
            vals[1] = ffnL10Hi(b);
            vals[2] = ffnL10Ord(b);
            vals[3] = ffnL10Src(b);
            vals[4] = ffnL10NumMin(b);
            vals[5] = ffnL10NumMax(b);
            vals[6] = ffnL10Sp(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CL10[b][c])
                    ++bad;
            }
        }
        // THE DRAGON SUBTABLE FOR LEVEL III: the 3 die rows (die low, die
        // high, type ord, age, hit points/die high, hit points/die low).
        // Rows: Black 01-28, age very young: age very young; the (hit
        // points/die) cell garbles in both voices (the ink reads (D and 0 )),
        // pinned unreadable; Brass 29-62, age very young: age very young; the
        // (hit points/die) cell garbles in both voices, pinned unreadable;
        // White 63-00, age very young: age very young; the (hit points/die)
        // cell garbles in both voices, pinned unreadable.
        int CD3[3][6] = {
            {1,28,319,0,0,0},
            {29,62,320,0,0,0},
            {63,100,321,0,0,0},
            };
        for (int b = 0;
             b < ffnD3Rows();
             ++b) {
            int vals[6];
            vals[0] = ffnD3Lo(b);
            vals[1] = ffnD3Hi(b);
            vals[2] = ffnD3Type(b);
            vals[3] = ffnD3Age(b);
            vals[4] = ffnD3Hd1(b);
            vals[5] = ffnD3Hd2(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CD3[b][c])
                    ++bad;
            }
        }
        // THE DRAGON SUBTABLE FOR LEVEL IV: the 11 die rows (die low, die
        // high, type ord, age, hit points/die high, hit points/die low).
        // Rows: Black 01-09, age young: age young/sub-adult; no hit-points
        // column on the Level IV subtable; Blue 10-20, age very young: age
        // very young/young; Brass 21-30, age young: age young/sub-adult;
        // Bronze 31-36, age very young: age very young/young; Copper 37-49,
        // age very young: age very young/young; Gold 50-53, age very young:
        // age very young/young; Green 54-69, age very young: age very
        // young/young; Li lung 70-74, age very young: age very young/young;
        // Red 75-82, age very young: age very young/young; Silver 83-88, age
        // very young: age very young/young; White 89-00, age young: age
        // young/sub-adult.
        int CD4[11][6] = {
            {1,9,319,1,0,0},
            {10,20,322,0,0,0},
            {21,30,320,1,0,0},
            {31,36,323,0,0,0},
            {37,49,324,0,0,0},
            {50,53,325,0,0,0},
            {54,69,326,0,0,0},
            {70,74,327,0,0,0},
            {75,82,328,0,0,0},
            {83,88,329,0,0,0},
            {89,100,321,1,0,0},
            };
        for (int b = 0;
             b < ffnD4Rows();
             ++b) {
            int vals[6];
            vals[0] = ffnD4Lo(b);
            vals[1] = ffnD4Hi(b);
            vals[2] = ffnD4Type(b);
            vals[3] = ffnD4Age(b);
            vals[4] = ffnD4Hd1(b);
            vals[5] = ffnD4Hd2(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CD4[b][c])
                    ++bad;
            }
        }
        // THE DRAGON SUBTABLE FOR LEVEL V: the 11 die rows (die low, die
        // high, type ord, age, hit points/die high, hit points/die low).
        // Rows: Black 01-09, age young adult: age young adult/adult, hit
        // points/die (4/5); Blue 10-20, age sub-adult: age sub-adult/young
        // adult, (3/4); Brass 21-30, age young adult: age young adult/adult,
        // (4/5); Bronze 31-36, age sub-adult: age sub-adult/young adult,
        // (3/4); Copper 37-49, age sub-adult: age sub-adult/young adult,
        // (3/4); Gold 50-53, age sub-adult: age sub-adult/young adult, (3/4);
        // Green 54-69, age sub-adult: age sub-adult/young adult, (3/4); Li
        // lung 70-74, age sub-adult: age sub-adult/young adult, (3/4); Red
        // 75-82, age sub-adult: age sub-adult/young adult, (3/4); Silver
        // 83-88, age sub-adult: age sub-adult/young adult, (3/4); White
        // 89-00, age young adult: age young adult/adult, (4/5).
        int CD5[11][6] = {
            {1,9,319,3,4,5},
            {10,20,322,2,3,4},
            {21,30,320,3,4,5},
            {31,36,323,2,3,4},
            {37,49,324,2,3,4},
            {50,53,325,2,3,4},
            {54,69,326,2,3,4},
            {70,74,327,2,3,4},
            {75,82,328,2,3,4},
            {83,88,329,2,3,4},
            {89,100,321,3,4,5},
            };
        for (int b = 0;
             b < ffnD5Rows();
             ++b) {
            int vals[6];
            vals[0] = ffnD5Lo(b);
            vals[1] = ffnD5Hi(b);
            vals[2] = ffnD5Type(b);
            vals[3] = ffnD5Age(b);
            vals[4] = ffnD5Hd1(b);
            vals[5] = ffnD5Hd2(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CD5[b][c])
                    ++bad;
            }
        }
        // THE DRAGON SUBTABLE FOR LEVEL VI: the 11 die rows (die low, die
        // high, type ord, age, hit points/die high, hit points/die low).
        // Rows: Black 01-09, age old: age old, hit points/die (6); Blue
        // 10-20, age adult: age adult, (5); Brass 21-30, age old: age old,
        // (6); Bronze 31-36, age adult: age adult, (5); Copper 37-49, age
        // adult: age adult, (5); Gold 50-53, age adult: age adult, (5); Green
        // 54-69, age adult: age adult, (5); Li lung 70-74, age adult: age
        // adult, (5); Red 75-82, age adult: age adult, (5); Silver 83-88, age
        // adult: age adult, (5); White 89-00, age old: age old, (6).
        int CD6[11][6] = {
            {1,9,319,5,6,0},
            {10,20,322,4,5,0},
            {21,30,320,5,6,0},
            {31,36,323,4,5,0},
            {37,49,324,4,5,0},
            {50,53,325,4,5,0},
            {54,69,326,4,5,0},
            {70,74,327,4,5,0},
            {75,82,328,4,5,0},
            {83,88,329,4,5,0},
            {89,100,321,5,6,0},
            };
        for (int b = 0;
             b < ffnD6Rows();
             ++b) {
            int vals[6];
            vals[0] = ffnD6Lo(b);
            vals[1] = ffnD6Hi(b);
            vals[2] = ffnD6Type(b);
            vals[3] = ffnD6Age(b);
            vals[4] = ffnD6Hd1(b);
            vals[5] = ffnD6Hd2(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CD6[b][c])
                    ++bad;
            }
        }
        // THE DRAGON SUBTABLE FOR LEVEL VII: the 12 die rows (die low, die
        // high, type ord, age, hit points/die high, hit points/die low).
        // Rows: Black 01-09, age very old: age very old, hit points/die (7);
        // Blue 10-20, age old: age old, (6); Brass 21-30, age very old: age
        // very old, (7); Bronze 31-36, age old: age old, (6); Copper 37-49,
        // age old: age old, (6); Gold 50-53, age old: age old, (6); Green
        // 54-69, age old: age old, (6); Li lung 70-74, age old: age old, (6);
        // Red 75-81, age old: age old, (6); Silver 82-87, age old: age old,
        // (6); T'ien lung 88-89, age adult: age adult, (5); White 90-00, age
        // very old: age very old, (7).
        int CD7[12][6] = {
            {1,9,319,6,7,0},
            {10,20,322,5,6,0},
            {21,30,320,6,7,0},
            {31,36,323,5,6,0},
            {37,49,324,5,6,0},
            {50,53,325,5,6,0},
            {54,69,326,5,6,0},
            {70,74,327,5,6,0},
            {75,81,328,5,6,0},
            {82,87,329,5,6,0},
            {88,89,330,4,5,0},
            {90,100,321,6,7,0},
            };
        for (int b = 0;
             b < ffnD7Rows();
             ++b) {
            int vals[6];
            vals[0] = ffnD7Lo(b);
            vals[1] = ffnD7Hi(b);
            vals[2] = ffnD7Type(b);
            vals[3] = ffnD7Age(b);
            vals[4] = ffnD7Hd1(b);
            vals[5] = ffnD7Hd2(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CD7[b][c])
                    ++bad;
            }
        }
        // THE DRAGON SUBTABLE FOR LEVEL VIII: the 12 die rows (die low, die
        // high, type ord, age, hit points/die high, hit points/die low).
        // Rows: Black 01-09, age ancient: age ancient, hit points/die (8);
        // Blue 10-20, age very old: age very old, (7); Brass 21-30, age
        // ancient: age ancient, (8); Bronze 31-36, age very old: age very
        // old, (7); Copper 37-49, age very old: age very old, (7); Gold
        // 50-53, age very old: age very old, (7); Green 54-67, age very old:
        // age very old, (7); Li lung 68-72, age very old: age very old, (7);
        // Red 73-81, age very old: age very old, (7); Silver 82-87, age very
        // old: age very old, (7); T'ien lung 88-89, age old: age old, (6);
        // White 90-00, age ancient: age ancient, (8).
        int CD8[12][6] = {
            {1,9,319,7,8,0},
            {10,20,322,6,7,0},
            {21,30,320,7,8,0},
            {31,36,323,6,7,0},
            {37,49,324,6,7,0},
            {50,53,325,6,7,0},
            {54,67,326,6,7,0},
            {68,72,327,6,7,0},
            {73,81,328,6,7,0},
            {82,87,329,6,7,0},
            {88,89,330,5,6,0},
            {90,100,321,7,8,0},
            };
        for (int b = 0;
             b < ffnD8Rows();
             ++b) {
            int vals[6];
            vals[0] = ffnD8Lo(b);
            vals[1] = ffnD8Hi(b);
            vals[2] = ffnD8Type(b);
            vals[3] = ffnD8Age(b);
            vals[4] = ffnD8Hd1(b);
            vals[5] = ffnD8Hd2(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CD8[b][c])
                    ++bad;
            }
        }
        // THE DRAGON SUBTABLE FOR LEVEL IX: the 12 die rows (die low, die
        // high, type ord, age, hit points/die high, hit points/die low).
        // Rows: Black 01-09, age ancient: age ancient & old, hit points/die
        // (8 & 6); Blue 10-20, age ancient: age ancient, (8); Brass 21-30,
        // age ancient: age ancient & old, (8 & 6); Bronze 31-36, age ancient:
        // age ancient, (8); Copper 37-49, age ancient: age ancient, (8); Gold
        // 50-53, age ancient: age ancient, (8); Green 54-67, age ancient: age
        // ancient, (8); Li lung 68-72, age ancient: age ancient, (8); Red
        // 73-81, age ancient: age ancient, (8); Silver 82-87, age ancient:
        // age ancient, (8); T'ien lung 88-89, age very old: age very old,
        // (7); White 90-00, age ancient: age ancient & old, (8 & 6).
        int CD9[12][6] = {
            {1,9,319,7,8,6},
            {10,20,322,7,8,0},
            {21,30,320,7,8,6},
            {31,36,323,7,8,0},
            {37,49,324,7,8,0},
            {50,53,325,7,8,0},
            {54,67,326,7,8,0},
            {68,72,327,7,8,0},
            {73,81,328,7,8,0},
            {82,87,329,7,8,0},
            {88,89,330,6,7,0},
            {90,100,321,7,8,6},
            };
        for (int b = 0;
             b < ffnD9Rows();
             ++b) {
            int vals[6];
            vals[0] = ffnD9Lo(b);
            vals[1] = ffnD9Hi(b);
            vals[2] = ffnD9Type(b);
            vals[3] = ffnD9Age(b);
            vals[4] = ffnD9Hd1(b);
            vals[5] = ffnD9Hd2(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CD9[b][c])
                    ++bad;
            }
        }
        // THE DRAGON SUBTABLE FOR LEVEL X: the 11 die rows (die low, die
        // high, type ord, age, hit points/die high, hit points/die low).
        // Rows: Blue 01-19, age ancient: number 2; age ancient & very old,
        // hit points/die (8 & 7); Bronze 20-25, age ancient: number 2; age
        // ancient & very old, (8 & 7); Copper 26-32, age ancient: number 2;
        // age ancient & very old, (8 & 7); Chromatic (Tiamat) 33, age the
        // unique court: the unique court row: Chromatic (Tiamat); Gold 34-38,
        // age ancient: number 2; age ancient & old; the hit points/die cells
        // garble beyond Copper in both voices; Green 39-55, age ancient:
        // number 2; age ancient & very old; the hit points/die cells garble,
        // pinned unreadable; Li lung 56-62, age ancient: number 2; age
        // ancient & very old; the hit points/die cells garble, pinned
        // unreadable; Platinum (Bahamut) 63, age the unique court: the unique
        // court row: Platinum (Bahamut); Red 64-92, age ancient: number 2;
        // age ancient & old; the hit points/die cells garble, pinned
        // unreadable; T'ien lung 93-94, age adult: number 2; age ancient &
        // adult; the hit points/die cells garble, pinned unreadable; Silver
        // 95-00, age ancient: number 2; age ancient & old; the hit points/die
        // cells garble, pinned unreadable.
        int CD10[11][6] = {
            {1,19,322,7,8,7},
            {20,25,323,7,8,7},
            {26,32,324,7,8,7},
            {33,33,331,-1,0,0},
            {34,38,325,7,8,6},
            {39,55,326,7,8,7},
            {56,62,327,7,8,7},
            {63,63,332,-1,0,0},
            {64,92,328,7,8,6},
            {93,94,330,4,8,4},
            {95,100,329,7,8,6},
            };
        for (int b = 0;
             b < ffnD10Rows();
             ++b) {
            int vals[6];
            vals[0] = ffnD10Lo(b);
            vals[1] = ffnD10Hi(b);
            vals[2] = ffnD10Type(b);
            vals[3] = ffnD10Age(b);
            vals[4] = ffnD10Hd1(b);
            vals[5] = ffnD10Hd2(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CD10[b][c])
                    ++bad;
            }
        }
        // THE SPHINX SUBTABLE (the Level VII routing target): the 4 die rows
        // (die low, die high, type ord, number min, number max). Rows:
        // Androsphinx 01-15 (numbers 1-1, src MM1); Criosphinx 16-43 (numbers
        // 1-2, src MM1); Gynosphinx 44-72 (numbers 1-1, src MM1);
        // Hieracosphinx 73-00 (numbers 1-3, src MM1).
        int CSpx[4][5] = {
            {1,15,302,1,1},
            {16,43,303,1,2},
            {44,72,304,1,1},
            {73,100,305,1,3},
            };
        for (int b = 0;
             b < ffnSpxRows();
             ++b) {
            int vals[5];
            vals[0] = ffnSpxLo(b);
            vals[1] = ffnSpxHi(b);
            vals[2] = ffnSpxOrd(b);
            vals[3] = ffnSpxNumMin(b);
            vals[4] = ffnSpxNumMax(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CSpx[b][c])
                    ++bad;
            }
        }
        // THE HUMAN SUBTABLE (the Level I routing target): the 4 die rows
        // (die low, die high, roster ord, source, number min, number max,
        // special). Rows: Bandit 01-25 (numbers 5-15, src MM1): printed
        // "Bandit*"; Berserker 26-30 (numbers 3-9, src MM1): printed
        // "Berserker*"; Brigand 31-45 (numbers 5-15, src unkeyed): printed
        // "Brigand*"; no registry def keys the brigand (unkeyed); Character
        // 46-00 (numbers 0-0, src routing): the routing row: see the
        // Character Subtable.
        int CHum[4][7] = {
            {1,25,306,1,5,15,0},
            {26,30,307,1,3,9,0},
            {31,45,308,4,5,15,0},
            {46,100,37,0,0,0,1},
            };
        for (int b = 0;
             b < ffnHumRows();
             ++b) {
            int vals[7];
            vals[0] = ffnHumLo(b);
            vals[1] = ffnHumHi(b);
            vals[2] = ffnHumOrd(b);
            vals[3] = ffnHumSrc(b);
            vals[4] = ffnHumNumMin(b);
            vals[5] = ffnHumNumMax(b);
            vals[6] = ffnHumSp(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CHum[b][c])
                    ++bad;
            }
        }
        // THE CHARACTER SUBTABLE (the every-level routing target): the 10 die
        // rows (die low, die high, class ord, number min, number max). Rows:
        // Cleric 01-17 (number 3); Druid 18-20 (number 2); Fighter 21-60
        // (number 5); Paladin 61-62 (number 2); Ranger 63-65 (number 2);
        // Magic-user 66-86 (number 3); Illusionist 87-88 (number 1); Thief
        // 89-98 (number 4); Assassin 99 (number 2); Monk or Bard 00 (number
        // 1); the monk or bard row reads "1 or 1" in the ink.
        int CChr[10][5] = {
            {1,17,309,3,3},
            {18,20,310,2,2},
            {21,60,311,5,5},
            {61,62,312,2,2},
            {63,65,313,2,2},
            {66,86,314,3,3},
            {87,88,315,1,1},
            {89,98,316,4,4},
            {99,99,317,2,2},
            {100,100,318,1,1},
            };
        for (int b = 0;
             b < ffnChrRows();
             ++b) {
            int vals[5];
            vals[0] = ffnChrLo(b);
            vals[1] = ffnChrHi(b);
            vals[2] = ffnChrOrd(b);
            vals[3] = ffnChrNumMin(b);
            vals[4] = ffnChrNumMax(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CChr[b][c])
                    ++bad;
            }
        }
        // the census walk (the 21-grid arithmetic)
    if (ffnTotalRows() != 461
            || ffnTableCount() != 21
            || ffnLevelRows() != 360
            || ffnDragonBandRows() != 83
            || ffnSubtableRows() != 18
        )
            ++bad;
        // the level-grid rows census
    if (ffnL1Rows() != 33
            || ffnL2Rows() != 30
            || ffnL3Rows() != 55
            || ffnL4Rows() != 42
            || ffnL5Rows() != 33
            || ffnL6Rows() != 40
            || ffnL7Rows() != 58
            || ffnL8Rows() != 31
            || ffnL9Rows() != 23
            || ffnL10Rows() != 15
            || ffnL1Rows() + ffnL2Rows() + ffnL3Rows() + ffnL4Rows() +
            ffnL5Rows() + ffnL6Rows() + ffnL7Rows() + ffnL8Rows() +
            ffnL9Rows() + ffnL10Rows() != ffnLevelRows()
        )
            ++bad;
        // the Dragon Subtable rows census
    if (ffnD3Rows() != 3
            || ffnD4Rows() != 11
            || ffnD5Rows() != 11
            || ffnD6Rows() != 11
            || ffnD7Rows() != 12
            || ffnD8Rows() != 12
            || ffnD9Rows() != 12
            || ffnD10Rows() != 11
            || ffnD3Rows() + ffnD4Rows() + ffnD5Rows() + ffnD6Rows() +
            ffnD7Rows() + ffnD8Rows() + ffnD9Rows() + ffnD10Rows() !=
            ffnDragonBandRows()
            || ffnSpxRows() + ffnHumRows() + ffnChrRows() != ffnSubtableRows()
        )
            ++bad;
        // the source census (no MM2 creature rows walk the FF tables)
    if (ffnMm1SourceRows() != 193
            || ffnMm2SourceRows() != 0
            || ffnFfSourceRows() != 133
            || ffnUnkeyedRows() != 14
            || ffnRoutingRows() != 20
            || ffnMm1SourceRows() + ffnMm2SourceRows() + ffnFfSourceRows() +
            ffnUnkeyedRows() + ffnRoutingRows() != ffnLevelRows()
        )
            ++bad;
        // the routing census (the special rows)
    if (ffnRoutingCharacter() != 9
            || ffnRoutingDragon() != 8
            || ffnRoutingHuman() != 1
            || ffnRoutingSphinx() != 1
            || ffnRoutingElemental() != 1
            || ffnRoutingCharacter() + ffnRoutingDragon() + ffnRoutingHuman()
            + ffnRoutingSphinx() + ffnRoutingElemental() != ffnRoutingRows()
        )
            ++bad;
        // the registry floor (no defs promoted this round)
    if (ffnRegistryFloor() != 995
        )
            ++bad;
        // the roster and repair census
    if (ffnRosterCount() != 333
            || ffnRepairs() != 39
            || ffnDefectPins() != 2
        )
            ++bad;
        // the defect pins (the Level III overlap, the Level VIII hole)
    if (ffnL3DefectRows() != 5
            || ffnL8HoleLo() != 27
            || ffnL8HoleHi() != 28
            || ffnL8HoleHi() - ffnL8HoleLo() != 1
        )
            ++bad;
        // the party-row dice (the Human row on I, the Character rows)
    if (ffnPartyDieD1() != 39
            || ffnPartyDieD2() != 15
            || ffnPartyDieD3() != 16
            || ffnPartyDieD4() != 13
            || ffnPartyDieD5() != 7
            || ffnPartyDieD6() != 12
            || ffnPartyDieD7() != 6
            || ffnPartyDieD8() != 7
            || ffnPartyDieD9() != 7
            || ffnPartyDieD10() != 20
        )
            ++bad;
        // the sphinx and dragon routing dice
    if (ffnSphinxDieLo() != 89
            || ffnDragonDieD3() != 27
            || ffnDragonDieD4() != 25
            || ffnDragonDieD5() != 31
            || ffnDragonDieD6() != 22
            || ffnDragonDieD7() != 26
            || ffnDragonDieD8() != 20
            || ffnDragonDieD9() != 20
            || ffnDragonDieD10() != 31
        )
            ++bad;
        // the Level I shrieker repair and the band walk
    if (ffnL1Lo(27) != 80
            || ffnL1Hi(27) != 84
            || ffnL1Lo(27) != ffnL1Hi(26) + 1
        )
            ++bad;
        // the Level II crabman repair and the band walk
    if (ffnL2Lo(6) != 27
            || ffnL2Hi(6) != 28
            || ffnL2Lo(6) != ffnL2Hi(5) + 1
        )
            ++bad;
        // the Level IV werewolf repair and the band walk
    if (ffnL4Lo(27) != 58
            || ffnL4Hi(27) != 65
            || ffnL4Lo(27) != ffnL4Hi(26) + 1
        )
            ++bad;
        // the Level V xill row 00 (the ink XIII)
    if (ffnL5Lo(32) != 100
            || ffnL5Hi(32) != 100
            || ffnL5Lo(32) != ffnL5Hi(31) + 1
        )
            ++bad;
        // the Level VI carrion crawler repair and the band walk
    if (ffnL6Lo(3) != 8
            || ffnL6Hi(3) != 11
            || ffnL6Lo(3) != ffnL6Hi(2) + 1
        )
            ++bad;
        // the Level VII xorn row 00 (the ink Korn) and the routing rows
    if (ffnL7Lo(57) != 100
            || ffnL7Hi(57) != 100
            || ffnL7Sp(52) != 4
            || ffnL7Lo(52) != 89
            || ffnL7Sp(16) != 5
            || ffnL7Lo(16) != 29
            || ffnL7Hi(16) != 30
        )
            ++bad;
        // the Level VIII hole (the ink jumps 25-26 to 29-30)
    if (ffnL8Hi(10) != 26
            || ffnL8Lo(11) != 29
            || ffnL8Hi(11) != 30
            || ffnL8Lo(11) - ffnL8Hi(10) != 3
        )
            ++bad;
        // the Level IX vampire repair and the band walk
    if (ffnL9Lo(20) != 83
            || ffnL9Hi(20) != 85
            || ffnL9Lo(20) != ffnL9Hi(19) + 1
        )
            ++bad;
        // the Level X dragon routing row and the band walk
    if (ffnL10Lo(5) != 31
            || ffnL10Hi(5) != 39
            || ffnL10Sp(5) != 2
            || ffnL10Lo(6) != ffnL10Hi(5) + 1
        )
            ++bad;
        // the Level III defect rows (the wererat band 56-63)
    if (ffnL3Lo(32) != 56
            || ffnL3Hi(32) != 63
            || ffnL3Lo(33) != 59
            || ffnL3Hi(33) != 59
        )
            ++bad;
        // the Human and Character routing rows (src 0)
    if (ffnL1Src(17) != 0
            || ffnL1Sp(17) != 3
            || ffnL1Hi(17) != 46
            || ffnL2Src(4) != 0
            || ffnL2Sp(4) != 1
        )
            ++bad;
        // the Sphinx Subtable criosphinx repair and the band walk
    if (ffnSpxLo(1) != 16
            || ffnSpxHi(1) != 43
            || ffnSpxHi(3) != 100
            || ffnSpxNumMin(1) != 1
            || ffnSpxNumMax(1) != 2
        )
            ++bad;
        // the Human Subtable (the brigand unkeyed, the Character routing)
    if (ffnHumLo(2) != 31
            || ffnHumHi(2) != 45
            || ffnHumSrc(2) != 4
            || ffnHumLo(3) != 46
            || ffnHumHi(3) != 100
            || ffnHumSp(3) != 1
        )
            ++bad;
        // the Character Subtable (the fighter 5, the monk or bard row 00)
    if (ffnChrLo(0) != 1
            || ffnChrHi(9) != 100
            || ffnChrNumMin(2) != 5
            || ffnChrNumMax(2) != 5
            || ffnChrNumMin(9) != 1
            || ffnChrNumMax(9) != 1
        )
            ++bad;
        // the Dragon Subtable unique courts (Tiamat 33, Bahamut 63)
    if (ffnD10Lo(3) != 33
            || ffnD10Age(3) != -1
            || ffnD10Lo(7) != 63
            || ffnD10Age(7) != -1
        )
            ++bad;
        // the Dragon Subtable band walk (D5, D8)
    if (ffnD5Lo(1) != 10
            || ffnD5Hi(0) != 9
            || ffnD8Hi(10) != 89
            || ffnD8Lo(11) != 90
            || ffnD8Hi(11) != 100
        )
            ++bad;
        // the Dragon Subtable unreadable ink (the D3 and D4 hit-points cells
        // pin 0)
    if (ffnD3Hd1(0) != 0
            || ffnD3Hd2(0) != 0
            || ffnD4Hd1(0) != 0
            || ffnD4Hd2(0) != 0
        )
            ++bad;
        printf("R846 FF monster level tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
