    // ---- R848 FF magic item tables audit ----
    // THE FF MAGIC ITEM TABLES - the party magic bands and the four item
    // tables of the print pp. 101-102 (the third and closing round of the
    // three FF table-group rounds): the 13 Individual-is-Nth-level party
    // bands (N 1-13, one percent-chance and count pair per offered item
    // table, the percentage dropped at the automatic rows - Table I automatic
    // from 10th, Table II from 12th, Table III at 13th) and the four die
    // tables - Table I the d20 list (20 items: the potions, scrolls, rings,
    // armor, shield, swords, arrows, bolts, dagger, javelin, mace), Table II
    // the (d8, d6) list (16 items: the scroll, rings, staff, wands, bracers,
    // brooch, cloak, dust, figurine, javelins, chainmail set, splint mail,
    // sword, the weapons pair), Table III the (d8, d6) list (16 items: the
    // ring, rod, staff, bag, boots, cloak, gauntlets, pipe, robe, the ropes
    // pair, plate set, shield, sword, mace, spear) and Table IV the d12 list
    // (12 items: the rings, rod, wand, cube, eyes, horn, robe, talisman,
    // plate set, sword, arrow). THE WALK: 5 tables, 77 rows, every cell
    // pinned (band percent, band count, roster ordinal, printed leading
    // count; the roster ordinal walks the 64 distinct item labels in
    // first-appearance order, Tables I through IV). THE SOURCES: the
    // four-voice scan collation from the archive.org item tsr02012fiendfolio
    // (the djvu text, the word-geometry xml, the abbyy char xml and the pdf
    // hidden Acrobat Capture layer) with the DMG npcparty parity (the
    // 1eonline transcription, its editorial angle-bracket notes ignored) the
    // tie-breaker; the party bands walk the p. 101 prose twice (the top bands
    // 6-13 and the bottom bands 1-5), the tables ride pp. 101-102. THE CENSUS
    // PINS: 13 band rows, 64 item rows (20/16/16/12), 64 roster labels, ZERO
    // registry defs touched - the item rows are not monster listings, no defs
    // promoted, the registry floor holds at 995. THE REPAIRS (18, the R703
    // pattern): the party-prose garbles (Ittirm = Items, i item = 1 item, the
    // Table i/M/ML/111/lit/1 name garbles, the (d8 n d6) header), the Table I
    // garbles (41 = +1, the super-heroism comma, the ring protection +1
    // restored from the pdf Capture voice), the Table II garbles (chairman =
    // chainmail), the Table III robe garble (b fending = blending), the Table
    // IV garbles (the talisman of, the robe line-order split) and the pdf
    // voice garbles (1 ,BLE = TABLE, sdint = splint). THE NOTED INK: the ring
    // of protection +1 (both char voices drop the +1, the pdf Capture voice
    // carries it, the DMG parity agrees), the FF dust of appearance against
    // the DMG dust of disappearance (the FF ink pinned, the divergence
    // noted), the +1 (or +2) et al dagger row without the DMG six-dagger
    // footnote expansion, the closing prose (the personal-select advice and
    // the groups-or-multiples note), the (d8, d6) linear convention (d6 1-3
    // reads the d8 result 1-8, d6 4-6 reads d8+8, 9-16 - the DMG linear-range
    // dice convention), and the bands match the DMG listing exactly. No defs
    // promoted this round - the registry floor holds at 995; the round closes
    // the three-round FF table-group arc.
    {
        using namespace rules;
        int bad = 0;
    if (ffqRound() != 848
            || ffqTableCount() != 5
            || ffqBndRows() != 13
            || ffqT1Rows() != 20
            || ffqT2Rows() != 16
            || ffqT3Rows() != 16
            || ffqT4Rows() != 12
            || ffqTotalRows() != 77
            || ffqRosterCount() != 64
            || ffqRegistryFloor() != 995
            || ffqRepairs() != 18
            || ffqDivergences() != 2
            || !ffqPartyMagicProse()
            || !ffqBandRule()
            || !ffqD20Header()
            || !ffqD8D6Linear()
            || !ffqD12Header()
            || !ffqPersonalSelect()
            || !ffqGroupsOrMultiples()
            || !ffqDustAppearance()
            || !ffqRingProtectionPlus1()
            || !ffqDaggerEtAl()
            || !ffqDmgParity()
        )
            ++bad;
        // Rows: THE PARTY MAGIC BANDS (print p. 101, the 13
        // Individual-is-Nth-level rows; Pct 0 with Count 0 = the table not
        // offered at this level, Pct 0 with Count above 0 = the automatic row
        // - Table I automatic from 10th, Table II from 12th, Table III at
        // 13th): 1st 10%/1 from Table I; 2nd 20%/2; 3rd 30%/2 + 10%/1 from
        // Table II; 4th 40%/2 + 20%/1; 5th 50%/2 + 30%/1; 6th 60%/3 + 40%/2;
        // 7th 70%/3 + 50%/2 + 10%/1 from Table III; 8th 80%/3 + 60%/2 +
        // 20%/1; 9th 90%/3 + 70%/2 + 30%/1; 10th 3 automatic + 80%/2 + 40%/1;
        // 11th 3 + 90%/2 + 50%/1 + 10%/1 from Table IV; 12th 3 + 2 automatic
        // + 60%/1 + 20%/1; 13th 3 + 2 + 1 automatic + 60%/1.
        int CBnd[13][9] = {
            {1,10,1,0,0,0,0,0,0},
            {2,20,2,0,0,0,0,0,0},
            {3,30,2,10,1,0,0,0,0},
            {4,40,2,20,1,0,0,0,0},
            {5,50,2,30,1,0,0,0,0},
            {6,60,3,40,2,0,0,0,0},
            {7,70,3,50,2,10,1,0,0},
            {8,80,3,60,2,20,1,0,0},
            {9,90,3,70,2,30,1,0,0},
            {10,0,3,80,2,40,1,0,0},
            {11,0,3,90,2,50,1,10,1},
            {12,0,3,0,2,60,1,20,1},
            {13,0,3,0,2,0,1,60,1},
            };
        for (int b = 0;
             b < ffqBndRows();
             ++b) {
            int vals[9];
            vals[0] = ffqBndOrd(b);
            vals[1] = ffqBndIPct(b);
            vals[2] = ffqBndINum(b);
            vals[3] = ffqBndIIPct(b);
            vals[4] = ffqBndIINum(b);
            vals[5] = ffqBndIIIPct(b);
            vals[6] = ffqBndIIINum(b);
            vals[7] = ffqBndIVPct(b);
            vals[8] = ffqBndIVNum(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CBnd[b][c])
                    ++bad;
            }
        }
        // Rows: THE MAGIC ITEM TABLE T1 (print p. 101, the d20 die column,
        // the die is the row ordinal; Ord the roster ordinal, Ct the printed
        // leading count): 1 [2 Potions: climbing, flying]; 2 [2 Potions:
        // extra-healing, polymorph self]; 3 [2 Potions: fire resistance,
        // speed]; 4 [2 Potions: healing, giant strength]; 5 [2 Potions:
        // heroism, invulnerability]; 6 [2 Potions: human control,
        // levitation]; 7 [2 Potions: super-heroism, animal control]; 8 [1
        // Scroll: 1 spell, level 1-6]; 9 [1 Scroll: 2 spells, level 1-4]; 10
        // [1 Scroll, protection from magic]; 11 [1 Ring: mammal control]; 12
        // [1 Ring: protection +1]; 13 [1 Armor: leather +1]; 14 [1 Shield:
        // +1]; 15 [1 Sword: +1 (no special abilities)]; 16 [10 Arrows: +1];
        // 17 [4 Bolts: +2]; 18 [1 Dagger: +1 (or +2) et al]; 19 [1 Javelin:
        // +2]; 20 [1 Mace: +1].
        int CT1[20][2] = {
            {1,2},
            {2,2},
            {3,2},
            {4,2},
            {5,2},
            {6,2},
            {7,2},
            {8,1},
            {9,1},
            {10,1},
            {11,1},
            {12,1},
            {13,1},
            {14,1},
            {15,1},
            {16,10},
            {17,4},
            {18,1},
            {19,1},
            {20,1},
            };
        for (int b = 0;
             b < ffqT1Rows();
             ++b) {
            int vals[2];
            vals[0] = ffqT1Ord(b);
            vals[1] = ffqT1Ct(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT1[b][c])
                    ++bad;
            }
        }
        // Rows: THE MAGIC ITEM TABLE T2 (print p. 102, the (d8, d6) die pair;
        // Ord the roster ordinal, Ct the printed leading count): 21 [1
        // Scroll: 3 spells, level 2-9 or 2-7]; 22 [2 Rings: fire resistance,
        // invisibility]; 23 [1 Ring: protection +3]; 24 [1 Staff: striking];
        // 25 [1 Wand: illusion]; 26 [1 Wand: negation]; 27 [1 Bracers of
        // defense, armor class 4]; 28 [1 Brooch of shielding]; 29 [1 Cloak of
        // elvenkind]; 30 [1 Dust of appearance]; 31 [1 Figurine of wondrous
        // power: serpentine owl]; 32 [3 Javelins of lightning]; 33 [1 Set:
        // chainmail +1, shield +2]; 34 [1 Armor: splint mail +4]; 35 [1
        // Sword: +3 (no special abilities)]; 36 [2 Weapons: crossbow of
        // speed, +2 hammer].
        int CT2[16][2] = {
            {21,1},
            {22,2},
            {23,1},
            {24,1},
            {25,1},
            {26,1},
            {27,1},
            {28,1},
            {29,1},
            {30,1},
            {31,1},
            {32,3},
            {33,1},
            {34,1},
            {35,1},
            {36,2},
            };
        for (int b = 0;
             b < ffqT2Rows();
             ++b) {
            int vals[2];
            vals[0] = ffqT2Ord(b);
            vals[1] = ffqT2Ct(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT2[b][c])
                    ++bad;
            }
        }
        // Rows: THE MAGIC ITEM TABLE T3 (print p. 102, the (d8, d6) die pair;
        // Ord the roster ordinal, Ct the printed leading count): 37 [1 Ring:
        // spell storing]; 38 [1 Rod: cancellation]; 39 [1 Staff: serpent -
        // python or adder]; 40 [1 Bag of tricks]; 41 [1 Boots of speed]; 42
        // [1 Boots of striding and leaping]; 43 [1 Cloak of displacement]; 44
        // [1 Gauntlets of ogre power]; 45 [1 Pipe of the sewers]; 46 [1 Robe
        // of blending]; 47 [2 Ropes: climbing, entanglement]; 48 [1 Set:
        // plate mail +3, shield +2]; 49 [1 Shield: +5]; 50 [1 Sword: +4,
        // defender]; 51 [1 Mace: +3]; 52 [1 Spear: +3].
        int CT3[16][2] = {
            {37,1},
            {38,1},
            {39,1},
            {40,1},
            {41,1},
            {42,1},
            {43,1},
            {44,1},
            {45,1},
            {46,1},
            {47,2},
            {48,1},
            {49,1},
            {50,1},
            {51,1},
            {52,1},
            };
        for (int b = 0;
             b < ffqT3Rows();
             ++b) {
            int vals[2];
            vals[0] = ffqT3Ord(b);
            vals[1] = ffqT3Ct(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT3[b][c])
                    ++bad;
            }
        }
        // Rows: THE MAGIC ITEM TABLE T4 (print p. 102, the d12 die column;
        // Ord the roster ordinal, Ct the printed leading count): 53 [1 Ring:
        // djinni summoning]; 54 [1 Ring: spell turning]; 55 [1 Rod: smiting];
        // 56 [1 Wand: fire]; 57 [1 Cube of force]; 58 [1 Eyes of charming];
        // 59 [1 Horn of Valhalla]; 60 [1 Robe of scintillating colors]; 61 [1
        // Talisman of either ultimate evil or pure good]; 62 [1 Set: plate
        // mail +4, shield +3]; 63 [1 Sword: wounding]; 64 [1 Arrow of slaying
        // (select character type)].
        int CT4[12][2] = {
            {53,1},
            {54,1},
            {55,1},
            {56,1},
            {57,1},
            {58,1},
            {59,1},
            {60,1},
            {61,1},
            {62,1},
            {63,1},
            {64,1},
            };
        for (int b = 0;
             b < ffqT4Rows();
             ++b) {
            int vals[2];
            vals[0] = ffqT4Ord(b);
            vals[1] = ffqT4Ct(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT4[b][c])
                    ++bad;
            }
        }
        // the census walk (the 5-table arithmetic)
    if (ffqTotalRows() != 77
            || ffqTableCount() != 5
            || ffqBndRows() + ffqT1Rows() + ffqT2Rows() + ffqT3Rows() +
            ffqT4Rows() != ffqTotalRows()
        )
            ++bad;
        // the rows census
    if (ffqBndRows() != 13
            || ffqT1Rows() != 20
            || ffqT2Rows() != 16
            || ffqT3Rows() != 16
            || ffqT4Rows() != 12
        )
            ++bad;
        // the roster census (the 64-label walk)
    if (ffqRosterCount() != 64
            || ffqT1Ord(0) != 1
            || ffqT1Ord(19) != 20
            || ffqT2Ord(0) != 21
            || ffqT2Ord(15) != 36
            || ffqT3Ord(0) != 37
            || ffqT3Ord(15) != 52
            || ffqT4Ord(0) != 53
            || ffqT4Ord(11) != 64
        )
            ++bad;
        // the band walk (the 13 levels)
    if (ffqBndOrd(0) != 1
            || ffqBndOrd(12) != 13
        )
            ++bad;
        // the Table I percent band
    if (ffqBndIPct(0) != 10
            || ffqBndIPct(1) != 20
            || ffqBndIPct(2) != 30
            || ffqBndIPct(3) != 40
            || ffqBndIPct(4) != 50
            || ffqBndIPct(5) != 60
            || ffqBndIPct(6) != 70
            || ffqBndIPct(7) != 80
            || ffqBndIPct(8) != 90
        )
            ++bad;
        // the automatic rows (the dropped percentage)
    if (ffqBndIPct(9) != 0
            || ffqBndINum(9) != 3
            || ffqBndIIPct(11) != 0
            || ffqBndIINum(11) != 2
            || ffqBndIIIPct(12) != 0
            || ffqBndIIINum(12) != 1
        )
            ++bad;
        // the not-offered cells (1st level: Table I alone)
    if (ffqBndIIPct(0) != 0
            || ffqBndIINum(0) != 0
            || ffqBndIIIPct(0) != 0
            || ffqBndIIINum(0) != 0
            || ffqBndIVPct(0) != 0
            || ffqBndIVNum(0) != 0
        )
            ++bad;
        // the Table II percent walk
    if (ffqBndIIPct(2) != 10
            || ffqBndIIPct(6) != 50
            || ffqBndIIPct(10) != 90
        )
            ++bad;
        // the Table III percent walk
    if (ffqBndIIIPct(6) != 10
            || ffqBndIIIPct(10) != 50
            || ffqBndIIIPct(11) != 60
        )
            ++bad;
        // the Table IV percent walk
    if (ffqBndIVPct(10) != 10
            || ffqBndIVPct(11) != 20
            || ffqBndIVPct(12) != 60
        )
            ++bad;
        // the Table I counts (the potions, arrows, bolts)
    if (ffqT1Ct(0) != 2
            || ffqT1Ct(15) != 10
            || ffqT1Ct(16) != 4
            || ffqT1Ct(19) != 1
        )
            ++bad;
        // the Table II counts (rings, javelins, weapons)
    if (ffqT2Ct(1) != 2
            || ffqT2Ct(11) != 3
            || ffqT2Ct(15) != 2
        )
            ++bad;
        // the Table III counts (the ropes pair)
    if (ffqT3Ct(10) != 2
            || ffqT3Ct(0) != 1
        )
            ++bad;
        // the Table IV counts (all single items)
    if (ffqT4Ct(0) != 1
            || ffqT4Ct(11) != 1
        )
            ++bad;
        // the repair census
    if (ffqRepairs() != 18
            || ffqDivergences() != 2
        )
            ++bad;
        // the registry floor
    if (ffqRegistryFloor() != 995
        )
            ++bad;
        printf("R848 FF magic item tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
