// ====================================================================
// Adnd1 - rules/npcbody.h
// R211: the NPC height and weight tables
// and the language determination (DMG
// pp.115-116, the personae chapter tail) -
// the MALES and FEMALES tables, the
// determination percent bands, and the
// random language table.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// dice and the campaign milieu; the
// averages, the dice and the bands read
// here).
//
// Conventions and judgments, named in
// place:
//   - Race order: the print table order
//     (dwarf, elf, gnome, half-elf,
//     halfling, half-orc, human). Sex: 0
//     male, 1 female - the print MALES and
//     FEMALES tables.
//   - The print dice cells are ranges
//     (1-4, 2-16, 4-40); each encodes a
//     dice sum: 1-4 = 1d4, 2-16 = 2d8,
//     4-40 = 4d10, 5-60 = 5d12. Packed as
//     count * 100 + sides (212 = 2d12,
//     410 = 4d10); npcDieCount/npcDieSides
//     unpack.
//   - GROUND TRUTH NOTE: the live 1eonline
//     compilation editorializes this seam
//     (it splits Human into NPC and PC rows
//     with d20x10-style entries and cites
//     OSRIC; it reads the half-orc male
//     over-weight as d20 and the human male
//     over-weight as 5d6). The book upload
//     carries the print ranges (4-40 and
//     5-60) and ONE human row - the upload
//     is pinned; the compilation additions
//     are excluded (the R209/R210 rule).
//   - The determination bands are per race,
//     shared by both sexes (the print
//     HEIGHT AND WEIGHT DETERMINATION
//     table): a d100 roll picks under /
//     average / over for height, then
//     again for weight.
//   - The language table: the print reads
//     primarily for NPC (and magic sword)
//     language knowledge - player
//     characters learn foreign languages
//     from others. The ten dragon faces
//     (05-14), the eight giant faces
//     (28-35, hill on 31-33) and the three
//     naga faces (62-64) are each a
//     separate kind; 86-00 is human
//     foreign or other (the campaign
//     footnote - the caller names it).
// ====================================================================

#pragma once

namespace rules {

// -----------------------------------------------------------------------
// The die packing: count * 100 + sides.
// -----------------------------------------------------------------------
inline int npcDieCount(int packed) { return packed / 100; }

inline int npcDieSides(int packed) { return packed % 100; }

// -----------------------------------------------------------------------
// The height and weight tables: 7 races,
// two sexes. Averages and the under/over
// adjustment dice.
// -----------------------------------------------------------------------
enum NpcBodyRace {
    NBR_DWARF = 0,
    NBR_ELF,
    NBR_GNOME,
    NBR_HALFELF,
    NBR_HALFLING,
    NBR_HALFORC,
    NBR_HUMAN,
    NBR_COUNT
};

inline int npcBodyRaceCount() { return 7; }

inline int npcHeightAvgInches(int female, int race) {
    // the print averages: male 48/60/42/
    // 66/36/66/72, female 46/54/39/62/33/
    // 62/66
    if (female < 0) female = 0;
    if (female > 1) female = 1;
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    static const int t[14] = {
        48, 60, 42, 66, 36, 66, 72,
        46, 54, 39, 62, 33, 62, 66,
    };
    return t[female * 7 + race];
}

inline int npcWeightAvgPounds(int female, int race) {
    // male 150/100/80/130/60/150/175,
    // female 120/80/75/100/50/120/130
    if (female < 0) female = 0;
    if (female > 1) female = 1;
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    static const int t[14] = {
        150, 100, 80, 130, 60, 150, 175,
        120, 80, 75, 100, 50, 120, 130,
    };
    return t[female * 7 + race];
}

inline int npcHeightDie(int female, int race, int over) {
    // the under/over adjustment dice,
    // packed count*100+sides: male dwarf
    // 1d4/1d6 ... female human 1d6/1d8
    if (female < 0) female = 0;
    if (female > 1) female = 1;
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    if (over < 0) over = 0;
    if (over > 1) over = 1;
    static const int t[28] = {
        104, 104, 103, 106, 103, 104, 112,
        106, 106, 103, 106, 106, 104, 112,
        104, 104, 103, 106, 103, 103, 106,
        104, 106, 103, 106, 103, 103, 108,
    };
    return t[female * 14 + over * 7 + race];
}

inline int npcWeightDie(int female, int race, int over) {
    // male dwarf 2d8/2d12 ... half-orc
    // 2d8/4d10, human 3d12/5d12; female
    // half-orc 3d6/4d8, human 3d10/4d12
    if (female < 0) female = 0;
    if (female > 1) female = 1;
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    if (over < 0) over = 0;
    if (over > 1) over = 1;
    static const int t[28] = {
        208, 110, 204, 120, 204, 208, 312,
        212, 120, 206, 120, 206, 410, 512,
        208, 110, 108, 112, 204, 306, 310,
        210, 206, 108, 208, 204, 408, 412,
    };
    return t[female * 14 + over * 7 + race];
}

// -----------------------------------------------------------------------
// The determination bands (per race, both
// sexes): the d100 under/average/over edges
// for height and weight.
// -----------------------------------------------------------------------
inline int npcHeightBandUnderEdge(int race) {
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    static const int e[7] = { 15, 10, 20, 35, 10, 45, 20 };
    return e[race];
}

inline int npcHeightBandAvgEdge(int race) {
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    static const int e[7] = { 80, 80, 85, 90, 90, 75, 80 };
    return e[race];
}

inline int npcWeightBandUnderEdge(int race) {
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    static const int e[7] = { 20, 15, 20, 20, 10, 30, 25 };
    return e[race];
}

inline int npcWeightBandAvgEdge(int race) {
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    static const int e[7] = { 65, 90, 75, 85, 50, 55, 75 };
    return e[race];
}

inline int npcBandClass(int pct, int underEdge, int avgEdge) {
    // 0 under, 1 average, 2 over; the roll
    // clamps to 1..100
    if (pct < 1) pct = 1;
    if (pct > 100) pct = 100;
    if (pct <= underEdge) return 0;
    if (pct <= avgEdge) return 1;
    return 2;
}

inline int npcDetermineHeightClass(int race, int pct) {
    return npcBandClass(pct,
        npcHeightBandUnderEdge(race),
        npcHeightBandAvgEdge(race));
}

inline int npcDetermineWeightClass(int race, int pct) {
    return npcBandClass(pct,
        npcWeightBandUnderEdge(race),
        npcWeightBandAvgEdge(race));
}

// -----------------------------------------------------------------------
// The random language determination table:
// 100 faces, 55 kinds, in print order -
// brownie, bugbear, centaur, the ten
// dragons, dryad, dwarvish, elvish, ettin,
// gargoyle, the eight giants, goblin,
// gnoll, gnome, halfling, hobgoblin,
// kobold, lammasu, lizard man, manticore,
// medusian, minotaur, the three nagas,
// nixie, nymph, ogrish, ogre magian,
// orcish, pixie, salamander, satyr, shedu,
// sprite, sylph, titan, troll, xorn, and
// 86-00 human foreign or other.
// -----------------------------------------------------------------------
enum NpcLang {
    NPC_LG_BROWNIE = 0,
    NPC_LG_BUGBEAR,
    NPC_LG_CENTAUR,
    NPC_LG_DRAGON_BLACK,
    NPC_LG_DRAGON_BLUE,
    NPC_LG_DRAGON_BRASS,
    NPC_LG_DRAGON_BRONZE,
    NPC_LG_DRAGON_COPPER,
    NPC_LG_DRAGON_GOLD,
    NPC_LG_DRAGON_GREEN,
    NPC_LG_DRAGON_RED,
    NPC_LG_DRAGON_SILVER,
    NPC_LG_DRAGON_WHITE,
    NPC_LG_DRYAD,
    NPC_LG_DWARVISH,
    NPC_LG_ELVISH,
    NPC_LG_ETTIN,
    NPC_LG_GARGOYLE,
    NPC_LG_GIANT_CLOUD,
    NPC_LG_GIANT_FIRE,
    NPC_LG_GIANT_FROST,
    NPC_LG_GIANT_HILL_1,
    NPC_LG_GIANT_HILL_2,
    NPC_LG_GIANT_HILL_3,
    NPC_LG_GIANT_STONE,
    NPC_LG_GIANT_STORM,
    NPC_LG_GOBLIN,
    NPC_LG_GNOLL,
    NPC_LG_GNOME,
    NPC_LG_HALFLING,
    NPC_LG_HOBGOBLIN,
    NPC_LG_KOBOLD,
    NPC_LG_LAMMASU,
    NPC_LG_LIZARD_MAN,
    NPC_LG_MANTICORE,
    NPC_LG_MEDUSIAN,
    NPC_LG_MINOTAUR,
    NPC_LG_NAGA_GUARDIAN,
    NPC_LG_NAGA_SPIRIT,
    NPC_LG_NAGA_WATER,
    NPC_LG_NIXIE,
    NPC_LG_NYMPH,
    NPC_LG_OGRISH,
    NPC_LG_OGRE_MAGIAN,
    NPC_LG_ORCISH,
    NPC_LG_PIXIE,
    NPC_LG_SALAMANDER,
    NPC_LG_SATYR,
    NPC_LG_SHEDU,
    NPC_LG_SPRITE,
    NPC_LG_SYLPH,
    NPC_LG_TITAN,
    NPC_LG_TROLL,
    NPC_LG_XORN,
    NPC_LG_HUMAN_FOREIGN,
    NPC_LG_COUNT
};

inline int npcLanguageKindCount() { return 55; }

inline int npcLanguageFor(int pct) {
    // the 100-face table, d100; the roll
    // clamps to 1..100
    if (pct < 1) pct = 1;
    if (pct > 100) pct = 100;
    static const int t[100] = {
        0, 1, 1, 2,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
        13,
        14, 14, 14, 14, 14,
        15, 15, 15, 15, 15,
        16,
        17,
        18, 19, 20, 21, 22, 23, 24, 25,
        26, 26, 26, 26,
        27,
        28, 28, 28, 28,
        29, 29, 29, 29, 29,
        30, 30,
        31, 31, 31,
        32,
        33, 33, 33,
        34,
        35,
        36,
        37, 38, 39,
        40,
        41,
        42, 42, 42, 42,
        43,
        44, 44, 44, 44, 44,
        45,
        46,
        47,
        48,
        49,
        50,
        51,
        52,
        53,
        54, 54, 54, 54, 54, 54, 54, 54,
        54, 54, 54, 54, 54, 54, 54,
    };
    return t[pct - 1];
}

}  // namespace rules
