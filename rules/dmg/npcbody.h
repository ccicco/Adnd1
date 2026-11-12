// ====================================================================
// Adnd1 - rules/dmg/npcbody.h
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

// R-refactor: namespace rules -> class Npcbody (instance methods)
class Npcbody {
public:


// -----------------------------------------------------------------------
// The die packing: count * 100 + sides.
// -----------------------------------------------------------------------
    int npcDieCount(int packed);
    int npcDieSides(int packed);
    int npcBodyRaceCount();
    int npcHeightAvgInches(int female, int race);
    int npcWeightAvgPounds(int female, int race);
    int npcHeightDie(int female, int race, int over);
    int npcWeightDie(int female, int race, int over);


// -----------------------------------------------------------------------
// The determination bands (per race, both
// sexes): the d100 under/average/over edges
// for height and weight.
// -----------------------------------------------------------------------
    int npcHeightBandUnderEdge(int race);
    int npcHeightBandAvgEdge(int race);
    int npcWeightBandUnderEdge(int race);
    int npcWeightBandAvgEdge(int race);
    int npcBandClass(int pct, int underEdge, int avgEdge);
    int npcDetermineHeightClass(int race, int pct);
    int npcDetermineWeightClass(int race, int pct);
    int npcLanguageKindCount();
    int npcLanguageFor(int pct);
};
