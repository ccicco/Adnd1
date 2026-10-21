// =========================================================================================
// Adnd1 - rules/oa74terrain.h
// OA CHAPTER 11, printed capture pp. 251-252 - the terrain encounter tables
// round
// census 625 -> 626.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE GRID: the sixteen terrain columns of the encounter
// tables, each column the nineteen rolls 2-20, one roll per band - the
// City/Town, the Tropical/Sub-tropical Mountains, the Tropical/Sub-tropical
// Ocean, the Temperate Swamp, the Rural, the Tropical/Sub-tropical Forest,
// the Temperate Mountain, the Temperate Freshwater, the Steppes, the
// Tropical/Sub-tropical Swamp, the Temperate Forest, the Temperate Ocean, the
// Aerial, the Tropical/Sub-tropical Freshwater, the Temperate Plain, the Cold
// Regions (the all-terrain-types column). THE 164 NAMES by ordinal: Afanc the
// 1; Bajang the 2; Bakemono the 3; Baku or lycanthrope, weretiger the 4;
// Bandits the 5; Bat, giant the 6; Bear, black the 7; Bear, northern the 8;
// Bee, giant bumble bee or crane, giant the 9; Bee, giant soldier or vulture,
// giant the 10; Beetle, giant water the 11; Behemoth the 12; Bisan the 13;
// Brigands the 14; Brigands or merchant the 15; Buffalo the 16; Buso,
// tagamaling the 17; Buso, tigbauna the 18; Carp, giant the 19; Cat lord the
// 20; Catfish, giant the 21; Centipede, giant the 22; Centipede, huge the 23;
// Centipede, megalo- the 24; Crab, giant the 25; Crane, giant the 26;
// Crayfish, giant the 27; Crocodile, normal the 28; Doc cu'o'c the 29; Dragon
// horse the 30; Dragon turtle the 31; Dragon, chiang lung the 32; Dragon,
// cloud or dragon, gold the 33; Dragon, gold the 34; Dragon, li lung the 35;
// Dragon, lung wang the 36; Dragon, mist the 37; Dragon, pan lung the 38;
// Dragon, shen lung the 39; Dragon, tun mi lung the 40; Dragon, tun mi lung
// or elemental, air the 41; Dragon, turtle the 42; Dragon, yu lung the 43;
// Dragonfly, giant the 44; Dragonfly, giant or dragon horse the 45; Eagle the
// 46; Eagle or bee, giant worker the 47; Eblis the 48; Elemental, water the
// 49; Falcon, large the 50; Falcon, small the 51; Falcon, small or owl, giant
// the 52; Falcon, small or vulture, ordinary the 53; Frog, giant the 54;
// Gaijin character party the 55; Gaijin NPC party the 56; Game animals the
// 57; Gargantua, humanoid the 58; Gargantua, insectoid the 59; Gargantua,
// insectoid or owl, giant the 60; Gargantua, reptilian the 61; Ghost the 62;
// Giant, hill the 63; Giant, mountain the 64; Goblin rat the 65; Goblin
// spider the 66; Hai nu the 67; Hengeyokai the 68; Herd animal the 69;
// Hippopotamus the 70; Hoarfox the 71; Horse, wild the 72; Hsing-sing the 73;
// Hu hsien the 74; Hu hsien or ogre the 75; Ikiryo the 76; Jiki-ketsu-gaki
// the 77; Jiki-niku-gaki the 78; Jinki-niku-gaki the 79; Jishin mushi the 80;
// Jishin mushi or doc cu'o'c the 81; Kala, cave the 82; Kala, earth the 83;
// Kech the 84; Kenku the 85; Ki-rin the 86; Ki-rin or phoenix the 87; Kuei
// the 88; Leech, giant the 89; Lycanthrope, foxwoman the 90; Lycanthrope,
// wereshark the 91; Lycanthrope, weretiger the 92; Mantis, giant the 93; Men,
// gajin buccaneers the 94; Men, wako the 95; Merchant the 96; Merman the 97;
// Naga, water the 98; Nat, hkum yeng the 99; Nat, lu the 100; Nature spirit,
// greater the 101; Nature spirit, lesser the 102; Ningyo the 103; Noble the
// 104; Nomads the 105; Octopus, giant the 106; Ogre the 107; Ogre mage the
// 108; Ogre magi the 109; Ogre, aquatic the 110; Oni the 111; Oriental
// character party the 112; Oriental NPC party the 113; Oriental NPC party or
// brigands the 114; Owl the 115; Owl, giant the 116; P'oh the 117; Phantom
// the 118; Phoenix the 119; Pilgrim the 120; Pilgrims the 121; Quicksand the
// 122; Rakshasa the 123; Ram the 124; Rat, giant the 125; Rat, ordinary the
// 126; Raven, giant the 127; Raven, huge or raven, giant the 128; Raven,
// ordinary the 129; School of fish the 130; Scorpion, giant the 131;
// Scorpion, huge the 132; Scorpion, large the 133; Seawolf the 134; Shan sao
// the 135; Shikko-gaki the 136; Shinen-gaki the 137; Skeleton the 138; Snake,
// constrictor the 139; Snake, giant constrictor the 140; Snake, giant
// poisonous the 141; Snake, giant spitting the 142; Snake, poisonous the 143;
// Snake, sea the 144; Spider, giant the 145; Spider, giant marine the 146;
// Spider, giant water the 147; Spider, huge the 148; Spirits of the air or
// dragon, t'ien lung the 149; Squid, giant the 150; Stag the 151; Stag, giant
// the 152; Tasloi the 153; Tengu the 154; Termite, giant harvester the 155;
// Tribesmen the 156; Troll, marine the 157; Turtle, giant sea the 158;
// Utoyasukata the 159; Verme the 160; Vulture, giant the 161; Weasel the 162;
// Yellow musk creeper the 163; Yuan ti the 164. THE OCR REPAIRS: the
// City/Town 15 Busho read as the Buso, tigbauna (the monster of the T/S
// Forest 7 and the Temperate Mountain 8); the Temperate Mountain 9 Giang read
// as the Giant, hill (the Giant, mountain at 19 the sibling); the hai nu
// capitalization normalized at both ocean 16s. AS PRINTED: the Temperate
// Ocean School of fish at both 10 and 12, the Men, wako at both 7 and 14. The
// grid codifies per the R431 calculus
//
// the gap census after this round: 156 closed, 79 open - the terrain
// encounter tables box flips (census 625 -> 626); NEXT - R704: the Climate
// Groupings with Creatures from Previous Books (capture p. 252), prefix djr
// (verify free at the landing), audit "R704 OA climate groupings audit",
// include after rules/oa74terrain.h
//
namespace rules {

// ---- the terrain encounter grid ----

// the City/Town column - the nineteen encounter names by ordinal for the
// rolls 2-20 (print capture pp. 251-252): 109, 77, 79, 88, 65, 3, 136, 96,
// 120, 104, 102, 113, 137, 18, 68, 74, 20, 56, 76
inline int djqOA74CityTown(int b)
    {
        switch (b) {
        case 0:
            return 109;
        case 1:
            return 77;
        case 2:
            return 79;
        case 3:
            return 88;
        case 4:
            return 65;
        case 5:
            return 3;
        case 6:
            return 136;
        case 7:
            return 96;
        case 8:
            return 120;
        case 9:
            return 104;
        case 10:
            return 102;
        case 11:
            return 113;
        case 12:
            return 137;
        case 13:
            return 18;
        case 14:
            return 68;
        case 15:
            return 74;
        case 16:
            return 20;
        case 17:
            return 56;
        case 18:
            return 76;
        default:
            return 0;
        }
    }

// the Tropical/Sub-tropical Mountains column - the nineteen encounter names
// by ordinal for the rolls 2-20 (print capture pp. 251-252): 34, 164, 92,
// 153, 155, 143, 139, 156, 16, 125, 57, 6, 5, 140, 61, 24, 35, 123, 163
inline int djqOA74TSMountains(int b)
    {
        switch (b) {
        case 0:
            return 34;
        case 1:
            return 164;
        case 2:
            return 92;
        case 3:
            return 153;
        case 4:
            return 155;
        case 5:
            return 143;
        case 6:
            return 139;
        case 7:
            return 156;
        case 8:
            return 16;
        case 9:
            return 125;
        case 10:
            return 57;
        case 11:
            return 6;
        case 12:
            return 5;
        case 13:
            return 140;
        case 14:
            return 61;
        case 15:
            return 24;
        case 16:
            return 35;
        case 17:
            return 123;
        case 18:
            return 163;
        default:
            return 0;
        }
    }

// the Tropical/Sub-tropical Ocean column - the nineteen encounter names by
// ordinal for the rolls 2-20 (print capture pp. 251-252): 42, 94, 1, 25, 106,
// 91, 146, 110, 158, 95, 130, 144, 103, 157, 67, 160, 40, 36, 49
inline int djqOA74TSOcean(int b)
    {
        switch (b) {
        case 0:
            return 42;
        case 1:
            return 94;
        case 2:
            return 1;
        case 3:
            return 25;
        case 4:
            return 106;
        case 5:
            return 91;
        case 6:
            return 146;
        case 7:
            return 110;
        case 8:
            return 158;
        case 9:
            return 95;
        case 10:
            return 130;
        case 11:
            return 144;
        case 12:
            return 103;
        case 13:
            return 157;
        case 14:
            return 67;
        case 15:
            return 160;
        case 16:
            return 40;
        case 17:
            return 36;
        case 18:
            return 49;
        default:
            return 0;
        }
    }

// the Temperate Swamp column - the nineteen encounter names by ordinal for
// the rolls 2-20 (print capture pp. 251-252): 118, 62, 59, 38, 101, 137, 145,
// 122, 102, 148, 147, 107, 3, 162, 65, 66, 159, 78, 90
inline int djqOA74TempSwamp(int b)
    {
        switch (b) {
        case 0:
            return 118;
        case 1:
            return 62;
        case 2:
            return 59;
        case 3:
            return 38;
        case 4:
            return 101;
        case 5:
            return 137;
        case 6:
            return 145;
        case 7:
            return 122;
        case 8:
            return 102;
        case 9:
            return 148;
        case 10:
            return 147;
        case 11:
            return 107;
        case 12:
            return 3;
        case 13:
            return 162;
        case 14:
            return 65;
        case 15:
            return 66;
        case 16:
            return 159;
        case 17:
            return 78;
        case 18:
            return 90;
        default:
            return 0;
        }
    }

// the Rural column - the nineteen encounter names by ordinal for the rolls
// 2-20 (print capture pp. 251-252): 77, 58, 2, 154, 65, 16, 113, 23, 14, 121,
// 75, 22, 81, 85, 35, 66, 117, 76, 99
inline int djqOA74Rural(int b)
    {
        switch (b) {
        case 0:
            return 77;
        case 1:
            return 58;
        case 2:
            return 2;
        case 3:
            return 154;
        case 4:
            return 65;
        case 5:
            return 16;
        case 6:
            return 113;
        case 7:
            return 23;
        case 8:
            return 14;
        case 9:
            return 121;
        case 10:
            return 75;
        case 11:
            return 22;
        case 12:
            return 81;
        case 13:
            return 85;
        case 14:
            return 35;
        case 15:
            return 66;
        case 16:
            return 117;
        case 17:
            return 76;
        case 18:
            return 99;
        default:
            return 0;
        }
    }

// the Tropical/Sub-tropical Forest column - the nineteen encounter names by
// ordinal for the rolls 2-20 (print capture pp. 251-252): 99, 13, 46, 153,
// 12, 18, 17, 156, 5, 84, 102, 23, 14, 4, 73, 100, 101, 29, 2
inline int djqOA74TSForest(int b)
    {
        switch (b) {
        case 0:
            return 99;
        case 1:
            return 13;
        case 2:
            return 46;
        case 3:
            return 153;
        case 4:
            return 12;
        case 5:
            return 18;
        case 6:
            return 17;
        case 7:
            return 156;
        case 8:
            return 5;
        case 9:
            return 84;
        case 10:
            return 102;
        case 11:
            return 23;
        case 12:
            return 14;
        case 13:
            return 4;
        case 14:
            return 73;
        case 15:
            return 100;
        case 16:
            return 101;
        case 17:
            return 29;
        case 18:
            return 2;
        default:
            return 0;
        }
    }

// the Temperate Mountain column - the nineteen encounter names by ordinal for
// the rolls 2-20 (print capture pp. 251-252): 80, 58, 35, 51, 152, 3, 18, 63,
// 151, 107, 102, 129, 115, 143, 101, 154, 111, 64, 92
inline int djqOA74TempMountain(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 58;
        case 2:
            return 35;
        case 3:
            return 51;
        case 4:
            return 152;
        case 5:
            return 3;
        case 6:
            return 18;
        case 7:
            return 63;
        case 8:
            return 151;
        case 9:
            return 107;
        case 10:
            return 102;
        case 11:
            return 129;
        case 12:
            return 115;
        case 13:
            return 143;
        case 14:
            return 101;
        case 15:
            return 154;
        case 16:
            return 111;
        case 17:
            return 64;
        case 18:
            return 92;
        default:
            return 0;
        }
    }

// the Temperate Freshwater column - the nineteen encounter names by ordinal
// for the rolls 2-20 (print capture pp. 251-252): 21, 95, 39, 43, 98, 27, 54,
// 28, 147, 102, 11, 96, 19, 89, 32, 101, 37, 30, 160
inline int djqOA74TempFreshwater(int b)
    {
        switch (b) {
        case 0:
            return 21;
        case 1:
            return 95;
        case 2:
            return 39;
        case 3:
            return 43;
        case 4:
            return 98;
        case 5:
            return 27;
        case 6:
            return 54;
        case 7:
            return 28;
        case 8:
            return 147;
        case 9:
            return 102;
        case 10:
            return 11;
        case 11:
            return 96;
        case 12:
            return 19;
        case 13:
            return 89;
        case 14:
            return 32;
        case 15:
            return 101;
        case 16:
            return 37;
        case 17:
            return 30;
        case 18:
            return 160;
        default:
            return 0;
        }
    }

// the Steppes column - the nineteen encounter names by ordinal for the rolls
// 2-20 (print capture pp. 251-252): 101, 74, 46, 124, 152, 72, 131, 16, 105,
// 133, 151, 107, 5, 132, 102, 161, 112, 117, 55
inline int djqOA74Steppes(int b)
    {
        switch (b) {
        case 0:
            return 101;
        case 1:
            return 74;
        case 2:
            return 46;
        case 3:
            return 124;
        case 4:
            return 152;
        case 5:
            return 72;
        case 6:
            return 131;
        case 7:
            return 16;
        case 8:
            return 105;
        case 9:
            return 133;
        case 10:
            return 151;
        case 11:
            return 107;
        case 12:
            return 5;
        case 13:
            return 132;
        case 14:
            return 102;
        case 15:
            return 161;
        case 16:
            return 112;
        case 17:
            return 117;
        case 18:
            return 55;
        default:
            return 0;
        }
    }

// the Tropical/Sub-tropical Swamp column - the nineteen encounter names by
// ordinal for the rolls 2-20 (print capture pp. 251-252): 164, 111, 100, 12,
// 26, 139, 143, 126, 102, 125, 156, 107, 140, 141, 38, 142, 138, 108, 48
inline int djqOA74TSSwamp(int b)
    {
        switch (b) {
        case 0:
            return 164;
        case 1:
            return 111;
        case 2:
            return 100;
        case 3:
            return 12;
        case 4:
            return 26;
        case 5:
            return 139;
        case 6:
            return 143;
        case 7:
            return 126;
        case 8:
            return 102;
        case 9:
            return 125;
        case 10:
            return 156;
        case 11:
            return 107;
        case 12:
            return 140;
        case 13:
            return 141;
        case 14:
            return 38;
        case 15:
            return 142;
        case 16:
            return 138;
        case 17:
            return 108;
        case 18:
            return 48;
        default:
            return 0;
        }
    }

// the Temperate Forest column - the nineteen encounter names by ordinal for
// the rolls 2-20 (print capture pp. 251-252): 80, 24, 154, 84, 93, 135, 137,
// 107, 52, 102, 112, 15, 3, 162, 66, 74, 101, 90, 92
inline int djqOA74TempForest(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 24;
        case 2:
            return 154;
        case 3:
            return 84;
        case 4:
            return 93;
        case 5:
            return 135;
        case 6:
            return 137;
        case 7:
            return 107;
        case 8:
            return 52;
        case 9:
            return 102;
        case 10:
            return 112;
        case 11:
            return 15;
        case 12:
            return 3;
        case 13:
            return 162;
        case 14:
            return 66;
        case 15:
            return 74;
        case 16:
            return 101;
        case 17:
            return 90;
        case 18:
            return 92;
        default:
            return 0;
        }
    }

// the Temperate Ocean column - the nineteen encounter names by ordinal for
// the rolls 2-20 (print capture pp. 251-252): 31, 94, 1, 25, 150, 95, 158,
// 110, 130, 103, 130, 97, 95, 157, 67, 134, 40, 36, 49
inline int djqOA74TempOcean(int b)
    {
        switch (b) {
        case 0:
            return 31;
        case 1:
            return 94;
        case 2:
            return 1;
        case 3:
            return 25;
        case 4:
            return 150;
        case 5:
            return 95;
        case 6:
            return 158;
        case 7:
            return 110;
        case 8:
            return 130;
        case 9:
            return 103;
        case 10:
            return 130;
        case 11:
            return 97;
        case 12:
            return 95;
        case 13:
            return 157;
        case 14:
            return 67;
        case 15:
            return 134;
        case 16:
            return 40;
        case 17:
            return 36;
        case 18:
            return 49;
        default:
            return 0;
        }
    }

// the Aerial column - the nineteen encounter names by ordinal for the rolls
// 2-20 (print capture pp. 251-252): 149, 87, 41, 32, 35, 85, 6, 47, 9, 128,
// 53, 45, 50, 60, 39, 38, 37, 10, 33
inline int djqOA74Aerial(int b)
    {
        switch (b) {
        case 0:
            return 149;
        case 1:
            return 87;
        case 2:
            return 41;
        case 3:
            return 32;
        case 4:
            return 35;
        case 5:
            return 85;
        case 6:
            return 6;
        case 7:
            return 47;
        case 8:
            return 9;
        case 9:
            return 128;
        case 10:
            return 53;
        case 11:
            return 45;
        case 12:
            return 50;
        case 13:
            return 60;
        case 14:
            return 39;
        case 15:
            return 38;
        case 16:
            return 37;
        case 17:
            return 10;
        case 18:
            return 33;
        default:
            return 0;
        }
    }

// the Tropical/Sub-tropical Freshwater column - the nineteen encounter names
// by ordinal for the rolls 2-20 (print capture pp. 251-252): 21, 44, 25, 12,
// 101, 19, 95, 54, 102, 11, 28, 156, 96, 70, 32, 39, 43, 48, 160
inline int djqOA74TSFreshwater(int b)
    {
        switch (b) {
        case 0:
            return 21;
        case 1:
            return 44;
        case 2:
            return 25;
        case 3:
            return 12;
        case 4:
            return 101;
        case 5:
            return 19;
        case 6:
            return 95;
        case 7:
            return 54;
        case 8:
            return 102;
        case 9:
            return 11;
        case 10:
            return 28;
        case 11:
            return 156;
        case 12:
            return 96;
        case 13:
            return 70;
        case 14:
            return 32;
        case 15:
            return 39;
        case 16:
            return 43;
        case 17:
            return 48;
        case 18:
            return 160;
        default:
            return 0;
        }
    }

// the Temperate Plain column - the nineteen encounter names by ordinal for
// the rolls 2-20 (print capture pp. 251-252): 77, 111, 108, 137, 26, 72, 16,
// 107, 133, 69, 102, 114, 3, 143, 152, 61, 86, 119, 118
inline int djqOA74TempPlain(int b)
    {
        switch (b) {
        case 0:
            return 77;
        case 1:
            return 111;
        case 2:
            return 108;
        case 3:
            return 137;
        case 4:
            return 26;
        case 5:
            return 72;
        case 6:
            return 16;
        case 7:
            return 107;
        case 8:
            return 133;
        case 9:
            return 69;
        case 10:
            return 102;
        case 11:
            return 114;
        case 12:
            return 3;
        case 13:
            return 143;
        case 14:
            return 152;
        case 15:
            return 61;
        case 16:
            return 86;
        case 17:
            return 119;
        case 18:
            return 118;
        default:
            return 0;
        }
    }

// the Cold Regions (All terrain types) column - the nineteen encounter names
// by ordinal for the rolls 2-20 (print capture pp. 251-252): 127, 116, 71,
// 82, 83, 129, 50, 107, 7, 63, 151, 162, 8, 135, 152, 51, 74, 74, 3
inline int djqOA74ColdRegions(int b)
    {
        switch (b) {
        case 0:
            return 127;
        case 1:
            return 116;
        case 2:
            return 71;
        case 3:
            return 82;
        case 4:
            return 83;
        case 5:
            return 129;
        case 6:
            return 50;
        case 7:
            return 107;
        case 8:
            return 7;
        case 9:
            return 63;
        case 10:
            return 151;
        case 11:
            return 162;
        case 12:
            return 8;
        case 13:
            return 135;
        case 14:
            return 152;
        case 15:
            return 51;
        case 16:
            return 74;
        case 17:
            return 74;
        case 18:
            return 3;
        default:
            return 0;
        }
    }

// the terrain grid minimum roll - the 2 of the 2-20 roll (print capture pp.
// 251-252)
inline int djqOA74RollMin()
    { return 2; }

// the terrain grid maximum roll - the 20 of the 2-20 roll (print capture pp.
// 251-252)
inline int djqOA74RollMax()
    { return 20; }

// the terrain grid row count - the nineteen rolls 2-20, one band per roll
// (print capture pp. 251-252)
inline int djqOA74RowCount()
    { return 19; }

// the Chapter 11 terrain column count - the sixteen columns of the terrain
// encounter grid (print capture pp. 251-252)
inline int djqOA74ColumnCount()
    { return 16; }

// the terrain grid encounter name count - the 164 distinct names across the
// sixteen columns (print capture pp. 251-252)
inline int djqOA74NameCount()
    { return 164; }

// ---- the column doctrine ----

// the Cold Regions column - the one column that applies to all terrain types
// (print capture pp. 251-252)
inline bool djqOA74ColdRegionsAllTerrains()
    { return true; }

// the Chapter 11 doctrine - the encounter table chosen by terrain type, the
// sixteen columns (print capture p. 251)
inline bool djqOA74ColumnByTerrainType()
    { return true; }

}   // namespace rules
