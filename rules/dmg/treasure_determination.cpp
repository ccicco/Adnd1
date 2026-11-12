// R-refactor: split from treasure_determination.h - definitions
#include "rules/dmg/treasure_determination.h"

int Treasure_determination::mapOrMagicIsMap(int roll) {
    // 01-10 the Map Table, 11-00 the Magic
    // Items Table; the roll is 1-100
    if (roll < 1) roll = 1;
    if (roll > 100) roll = 100;
    if (roll <= 10) return 1;
    return 0;
}

int Treasure_determination::mapTableResult(int roll) {
    // 01-05 false, 06-70 monetary, 71-90
    // magic, 91-00 a combined hoard
    if (roll < 1) roll = 1;
    if (roll > 100) roll = 100;
    if (roll <= 5) return MT_FALSE;
    if (roll <= 70) return MT_MONETARY;
    if (roll <= 90) return MT_MAGIC;
    return MT_COMBINED;
}

int Treasure_determination::mapNeverListsTreasure() {
    // a map shows the location only, never
    // the treasure itself
    return 1;
}

int Treasure_determination::mapDestIsLairCaves(int roll) {
    // 01-20 a labyrinth of caves found in
    // the lair
    if (roll < 1) roll = 1;
    if (roll > 100) roll = 100;
    if (roll <= 20) return 1;
    return 0;
}

int Treasure_determination::mapDestMilesMin(int roll) {
    // 21-60: 5 miles; 61-90: 10; 91-00: 50;
    // the lair-caves band is 0 miles
    if (roll < 1) roll = 1;
    if (roll > 100) roll = 100;
    if (roll <= 20) return 0;
    if (roll <= 60) return 5;
    if (roll <= 90) return 10;
    return 50;
}

int Treasure_determination::mapDestMilesMax(int roll) {
    // 21-60: 8 miles; 61-90: 40; 91-00: 500
    if (roll < 1) roll = 1;
    if (roll > 100) roll = 100;
    if (roll <= 20) return 0;
    if (roll <= 60) return 8;
    if (roll <= 90) return 40;
    return 500;
}

int Treasure_determination::mapDirectionDie() {
    // a quick roll of d8 for direction
    return 8;
}

int Treasure_determination::mapDirectionNorthIsOne() {
    // 1 is north, counting round (2 is
    // northeast, 3 is east, etc.)
    return 1;
}

int Treasure_determination::mapContainment(int roll) {
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

int Treasure_determination::lowValueLessGuarded() {
    // relatively low-value treasures are not
    // as well guarded as those of great value
    return 1;
}

int Treasure_determination::monetaryRowCount() { return 9; }

int Treasure_determination::monetaryBandLo(int row) {
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

int Treasure_determination::monetaryBandHi(int row) {
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

int Treasure_determination::monetaryPipMin(int row) {
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

int Treasure_determination::monetaryPipMax(int row) {
    if (row < 0) row = 0;
    if (row > 5) row = 5;
    if (row == 0) return 8;
    if (row == 1) return 5;
    if (row == 2) return 30;
    if (row == 3) return 18;
    if (row == 4) return 20;
    return 10;
}

int Treasure_determination::monetaryMult(int row) {
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

int Treasure_determination::monetaryQty(int row, int pips) {
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

int Treasure_determination::jewelryPipMin() { return 5; }

int Treasure_determination::jewelryPipMax() { return 50; }

int Treasure_determination::monetaryReRollMax() {
    // rows 18 and 19 discount rolls above 17
    return 17;
}

int Treasure_determination::monetaryExtraRolls(int die) {
    // row 18 rolls twice, row 19 thrice;
    // every other row rolls once
    if (die < 1) die = 1;
    if (die > 20) die = 20;
    if (die == 18) return 2;
    if (die == 19) return 3;
    return 1;
}

int Treasure_determination::monetaryEachItemRow() { return 20; }

int Treasure_determination::monetaryEachItemCoversRows() {
    // row 20 gives each monetary item above:
    // one of each row 1 through 17 (rows 18
    // and 19 are re-roll instructions, not
    // items)
    return 17;
}

int Treasure_determination::abandonedTheftChanceIsDmSet() {
    // the chance abandoned treasure is stolen
    // away is set by the DM from actions and
    // precautions
    return 1;
}

int Treasure_determination::magicBandCount() { return 7; }

int Treasure_determination::magicBandLo(int row) {
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

int Treasure_determination::magicBandHi(int row) {
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

int Treasure_determination::magicBandItems(int row) {
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

int Treasure_determination::magicBandExtraPotions(int row) {
    // band 1-5: the item plus 4 potions
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 0) return 4;
    return 0;
}

int Treasure_determination::magicBandPotions(int row) {
    // band 15-18: any 6 potions
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 4) return 6;
    return 0;
}

int Treasure_determination::magicBandScrolls(int row) {
    // band 15-18: any 6 scrolls
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 4) return 6;
    return 0;
}

int Treasure_determination::magicBandSwords(int row) {
    // band 9-12: 1 sword
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 2) return 1;
    return 0;
}

int Treasure_determination::magicBandArmorOrShield(int row) {
    // band 9-12: 1 armor or shield
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 2) return 1;
    return 0;
}

int Treasure_determination::magicBandMiscWeapons(int row) {
    // band 9-12: 1 miscellaneous weapon
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 2) return 1;
    return 0;
}

int Treasure_determination::magicBandNoSwordOrPotions(int row) {
    // band 13-14: any 3 items, no sword or
    // potions
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 3) return 1;
    return 0;
}

int Treasure_determination::magicBandRings(int row) {
    // band 19: 1 of the 4 items is a ring
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 5) return 1;
    return 0;
}

int Treasure_determination::magicBandRods(int row) {
    // bands 19 and 20: 1 item is a rod
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 5) return 1;
    if (row == 6) return 1;
    return 0;
}

int Treasure_determination::magicBandMiscMagic(int row) {
    // band 20: 1 item is miscellaneous magic
    if (row < 0) row = 0;
    if (row > 6) row = 6;
    if (row == 6) return 1;
    return 0;
}

int Treasure_determination::magicTableWeightedByDesign() {
    // potions, scrolls, armor and arms are
    // plentiful; rings, rods and misc magic
    // are only 25 percent - keep potent magic
    // rare
    return 1;
}
