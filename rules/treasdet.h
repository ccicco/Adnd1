// ====================================================================
// Adnd1 - rules/treasdet.h
// R219: the treasure random determination
// tables pins (DMG pp.120-123) - the top-
// level determination tables: map or magic,
// the map table with its outdoor and
// containment sub-tables, and the monetary
// and magic treasure trove tables.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// dice and the actual trove assembly; the
// band edges and the numeric conventions
// read here). The R122 line-diff closed the
// III.A-H item tables and the lair types;
// these top-level tables were never
// implemented and are pinned here. The II.C
// combined hoard table is the R220
// candidate.
//
// Conventions and judgments, named in
// place:
//   - Table I (map or magic): when a lair
//     indicates maps or magic, percentile
//     dice give 01-10 the Map Table (II.)
//     and 11-00 the Magic Items Table (III.).
//   - Table II (the map table): 01-05 a
//     false map, 06-70 a map to monetary
//     treasure, 71-90 a map to magic
//     treasure, 91-00 a map to a combined
//     hoard. A map never lists its treasure,
//     only its location.
//   - Outdoor map destination: 01-20 a
//     labyrinth of caves found in the lair,
//     21-60 outdoors 5-8 miles distant,
//     61-90 outdoors 10-40 miles distant,
//     91-00 outdoors 50-500 miles distant.
//     Direction is a quick d8 roll with 1
//     being north, counting round (2 is
//     northeast, 3 is east, etc.).
//   - Containment: 01-10 buried and
//     unguarded, 11-20 hidden in water, 21-70
//     guarded in a lair, 71-80 somewhere in
//     ruins, 81-90 in a burial crypt, 91-00
//     secreted in a town.
//   - Table II.A (monetary treasure, d20):
//     1-2 copper pieces 20,000-80,000 (2d4
//     x 10,000) and silver pieces 20,000-
//     50,000 (d4+1 x 10,000); 3-5 electrum
//     5,000-30,000 (5d6 x 1,000); 6-10 gold
//     3,000-18,000 (3d6 x 1,000); 11-12
//     platinum 500-2,000 (5d4 x 100); 13-15
//     gems 10-100 (d10 x 10); 16-17 jewelry
//     5-50 pieces (5d10). Row 18: roll twice,
//     discounting rolls above 17; row 19:
//     roll thrice likewise; row 20: each
//     monetary item above - read as one of
//     each row 1 through 17 (the coins, gems
//     and jewelry; rows 18/19 are re-roll
//     instructions, not items).
//   - Table II.B (magic treasure, d20): 1-5
//     any item rolled on the Magic Item Table
//     plus 4 potions; 6-8 any 2 items; 9-12
//     1 sword, 1 armor or shield, 1
//     miscellaneous weapon; 13-14 any 3
//     items with no sword or potions; 15-18
//     any 6 potions and any 6 scrolls; 19 any
//     4 items of which 1 is a ring and 1 is a
//     rod; 20 any 5 items of which 1 is a rod
//     and 1 is miscellaneous magic.
//   - Design notes: the abandonment theft
//     chance is DM-set by precautions and
//     circumstance; relatively low-value
//     treasures are not as well guarded as
//     those of great value; the magic table
//     is deliberately weighted (rings, rods
//     and miscellaneous items are only 25
//     percent of the Magic Items Table) so
//     potent magic stays rare.
// ====================================================================

#pragma once

namespace rules {

// -----------------------------------------------------------------------
// Table I: map or magic.
// -----------------------------------------------------------------------
inline int mapOrMagicIsMap(int roll) {
    // 01-10 the Map Table, 11-00 the Magic
    // Items Table; the roll is 1-100
    if (roll < 1) roll = 1;
    if (roll > 100) roll = 100;
    if (roll <= 10) return 1;
    return 0;
}

// -----------------------------------------------------------------------
// Table II: the map table.
// -----------------------------------------------------------------------
enum MapLead {
    MT_FALSE = 0,
    MT_MONETARY,
    MT_MAGIC,
    MT_COMBINED,
    MT_COUNT
};

inline int mapTableResult(int roll) {
    // 01-05 false, 06-70 monetary, 71-90
    // magic, 91-00 a combined hoard
    if (roll < 1) roll = 1;
    if (roll > 100) roll = 100;
    if (roll <= 5) return MT_FALSE;
    if (roll <= 70) return MT_MONETARY;
    if (roll <= 90) return MT_MAGIC;
    return MT_COMBINED;
}

inline int mapNeverListsTreasure() {
    // a map shows the location only, never
    // the treasure itself
    return 1;
}

// -----------------------------------------------------------------------
// The outdoor map destination sub-table.
// -----------------------------------------------------------------------
inline int mapDestIsLairCaves(int roll) {
    // 01-20 a labyrinth of caves found in
    // the lair
    if (roll < 1) roll = 1;
    if (roll > 100) roll = 100;
    if (roll <= 20) return 1;
    return 0;
}

inline int mapDestMilesMin(int roll) {
    // 21-60: 5 miles; 61-90: 10; 91-00: 50;
    // the lair-caves band is 0 miles
    if (roll < 1) roll = 1;
    if (roll > 100) roll = 100;
    if (roll <= 20) return 0;
    if (roll <= 60) return 5;
    if (roll <= 90) return 10;
    return 50;
}

inline int mapDestMilesMax(int roll) {
    // 21-60: 8 miles; 61-90: 40; 91-00: 500
    if (roll < 1) roll = 1;
    if (roll > 100) roll = 100;
    if (roll <= 20) return 0;
    if (roll <= 60) return 8;
    if (roll <= 90) return 40;
    return 500;
}

inline int mapDirectionDie() {
    // a quick roll of d8 for direction
    return 8;
}

inline int mapDirectionNorthIsOne() {
    // 1 is north, counting round (2 is
    // northeast, 3 is east, etc.)
    return 1;
}

// -----------------------------------------------------------------------
// The containment sub-table.
// -----------------------------------------------------------------------
enum MapContainment {
    MCON_BURIED_UNGUARDED = 0,
    MCON_HIDDEN_IN_WATER,
    MCON_GUARDED_IN_LAIR,
    MCON_IN_RUINS,
    MCON_BURIAL_CRYPT,
    MCON_IN_TOWN,
    MCON_COUNT
};

inline int mapContainment(int roll) {
    // 01-10 buried unguarded, 11-20 water,
    // 21-70 lair, 71-80 ruins, 81-90 crypt,
    // 91-00 town
    if (roll < 1) roll = 1;
    if (roll > 100) roll = 100;
    if (roll <= 10) return MCON_BURIED_UNGUARDED;
    if (roll <= 20) return MCON_HIDDEN_IN_WATER;
    if (roll <= 70) return MCON_GUARDED_IN_LAIR;
    if (roll <= 80) return MCON_IN_RUINS;
    if (roll <= 90) return MCON_BURIAL_CRYPT;
    return MCON_IN_TOWN;
}

inline int lowValueLessGuarded() {
    // relatively low-value treasures are not
    // as well guarded as those of great value
    return 1;
}

// -----------------------------------------------------------------------
// Table II.A: monetary treasure (d20).
// Rows 0-8 cover die results 1-2, 3-5, 6-10,
// 11-12, 13-15, 16-17, 18, 19, 20; the
// quantity is the pip roll x the multiplier.
// -----------------------------------------------------------------------
inline int monetaryRowCount() { return 9; }

inline int monetaryBandLo(int row) {
    if (row < 0) row = 0;
    if (row > 8) row = 8;
    if (row == 0) return 1;
    if (row == 1) return 3;
    if (row == 2) return 6;
    if (row == 3) return 11;
    if (row == 4) return 13;
    if (row == 5) return 16;
    if (row == 6) return 18;
    if (row == 7) return 19;
    return 20;
}

inline int monetaryBandHi(int row) {
    if (row < 0) row = 0;
    if (row > 8) row = 8;
    if (row == 0) return 2;
    if (row == 1) return 5;
    if (row == 2) return 10;
    if (row == 3) return 12;
    if (row == 4) return 15;
    if (row == 5) return 17;
    if (row == 6) return 18;
    if (row == 7) return 19;
    return 20;
}

inline int monetaryPipMin(int row) {
    // rows 0-5: cp 2d4, sp d4+1, ep 5d6,
    // gp 3d6, pp 5d4, gems d10; jewelry is
    // its own helper below
    if (row < 0) row = 0;
    if (row > 5) row = 5;
    if (row == 0) return 2;
    if (row == 1) return 2;
    if (row == 2) return 5;
    if (row == 3) return 3;
    if (row == 4) return 5;
    return 1;
}

inline int monetaryPipMax(int row) {
    if (row < 0) row = 0;
    if (row > 5) row = 5;
    if (row == 0) return 8;
    if (row == 1) return 5;
    if (row == 2) return 30;
    if (row == 3) return 18;
    if (row == 4) return 20;
    return 10;
}

inline int monetaryMult(int row) {
    // cp/sp x 10,000; ep/gp x 1,000;
    // pp x 100; gems x 10 (the gem count)
    if (row < 0) row = 0;
    if (row > 5) row = 5;
    if (row == 0) return 10000;
    if (row == 1) return 10000;
    if (row == 2) return 1000;
    if (row == 3) return 1000;
    if (row == 4) return 100;
    return 10;
}

inline int monetaryQty(int row, int pips) {
    // the trove quantity: the pip roll
    // clamped to its range, times the
    // multiplier (cp 20,000-80,000; sp
    // 20,000-50,000; ep 5,000-30,000; gp
    // 3,000-18,000; pp 500-2,000; gems
    // 10-100)
    if (row < 0) row = 0;
    if (row > 5) row = 5;
    if (pips < monetaryPipMin(row))
        pips = monetaryPipMin(row);
    if (pips > monetaryPipMax(row))
        pips = monetaryPipMax(row);
    return pips * monetaryMult(row);
}

inline int jewelryPipMin() { return 5; }

inline int jewelryPipMax() { return 50; }

inline int monetaryReRollMax() {
    // rows 18 and 19 discount rolls above 17
    return 17;
}

inline int monetaryExtraRolls(int die) {
    // row 18 rolls twice, row 19 thrice;
    // every other row rolls once
    if (die < 1) die = 1;
    if (die > 20) die = 20;
    if (die == 18) return 2;
    if (die == 19) return 3;
    return 1;
}

inline int monetaryEachItemRow() { return 20; }

inline int monetaryEachItemCoversRows() {
    // row 20 gives each monetary item above:
    // one of each row 1 through 17 (rows 18
    // and 19 are re-roll instructions, not
    // items)
    return 17;
}

inline int abandonedTheftChanceIsDmSet() {
    // the chance abandoned treasure is stolen
    // away is set by the DM from actions and
    // precautions
    return 1;
}

// -----------------------------------------------------------------------
// Table II.B: magic treasure (d20).
// Bands 0-6 cover die results 1-5, 6-8,
// 9-12, 13-14, 15-18, 19, 20.
// -----------------------------------------------------------------------
inline int magicBandCount() { return 7; }

inline int magicBandLo(int row) {
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 0) return 1;
    if (row == 1) return 6;
    if (row == 2) return 9;
    if (row == 3) return 13;
    if (row == 4) return 15;
    if (row == 5) return 19;
    return 20;
}

inline int magicBandHi(int row) {
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 0) return 5;
    if (row == 1) return 8;
    if (row == 2) return 12;
    if (row == 3) return 14;
    if (row == 4) return 18;
    if (row == 5) return 19;
    return 20;
}

inline int magicBandItems(int row) {
    // the total item count of the band: 1+4
    // potions, 2, the SAW triple, 3, the
    // 6-potion + 6-scroll dozen, 4, 5
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 0) return 1;
    if (row == 1) return 2;
    if (row == 2) return 3;
    if (row == 3) return 3;
    if (row == 4) return 12;
    if (row == 5) return 4;
    return 5;
}

inline int magicBandExtraPotions(int row) {
    // band 1-5: the item plus 4 potions
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 0) return 4;
    return 0;
}

inline int magicBandPotions(int row) {
    // band 15-18: any 6 potions
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 4) return 6;
    return 0;
}

inline int magicBandScrolls(int row) {
    // band 15-18: any 6 scrolls
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 4) return 6;
    return 0;
}

inline int magicBandSwords(int row) {
    // band 9-12: 1 sword
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 2) return 1;
    return 0;
}

inline int magicBandArmorOrShield(int row) {
    // band 9-12: 1 armor or shield
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 2) return 1;
    return 0;
}

inline int magicBandMiscWeapons(int row) {
    // band 9-12: 1 miscellaneous weapon
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 2) return 1;
    return 0;
}

inline int magicBandNoSwordOrPotions(int row) {
    // band 13-14: any 3 items, no sword or
    // potions
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 3) return 1;
    return 0;
}

inline int magicBandRings(int row) {
    // band 19: 1 of the 4 items is a ring
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 5) return 1;
    return 0;
}

inline int magicBandRods(int row) {
    // bands 19 and 20: 1 item is a rod
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 5) return 1;
    if (row == 6) return 1;
    return 0;
}

inline int magicBandMiscMagic(int row) {
    // band 20: 1 item is miscellaneous magic
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 6) return 1;
    return 0;
}

inline int magicTableWeightedByDesign() {
    // potions, scrolls, armor and arms are
    // plentiful; rings, rods and misc magic
    // are only 25 percent - keep potent magic
    // rare
    return 1;
}

}  // namespace rules
