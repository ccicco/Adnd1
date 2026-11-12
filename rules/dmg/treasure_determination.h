// ====================================================================
// Adnd1 - rules/dmg/treasure_determination.h
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

// R-refactor: namespace rules -> class Treasure_determination (instance methods)
class Treasure_determination {
public:


// -----------------------------------------------------------------------
// Table I: map or magic.
// -----------------------------------------------------------------------
    int mapOrMagicIsMap(int roll);
    int mapTableResult(int roll);
    int mapNeverListsTreasure();


// -----------------------------------------------------------------------
// The outdoor map destination sub-table.
// -----------------------------------------------------------------------
    int mapDestIsLairCaves(int roll);
    int mapDestMilesMin(int roll);
    int mapDestMilesMax(int roll);
    int mapDirectionDie();
    int mapDirectionNorthIsOne();
    int mapContainment(int roll);
    int lowValueLessGuarded();


// -----------------------------------------------------------------------
// Table II.A: monetary treasure (d20).
// Rows 0-8 cover die results 1-2, 3-5, 6-10,
// 11-12, 13-15, 16-17, 18, 19, 20; the
// quantity is the pip roll x the multiplier.
// -----------------------------------------------------------------------
    int monetaryRowCount();
    int monetaryBandLo(int row);
    int monetaryBandHi(int row);
    int monetaryPipMin(int row);
    int monetaryPipMax(int row);
    int monetaryMult(int row);
    int monetaryQty(int row, int pips);
    int jewelryPipMin();
    int jewelryPipMax();
    int monetaryReRollMax();
    int monetaryExtraRolls(int die);
    int monetaryEachItemRow();
    int monetaryEachItemCoversRows();
    int abandonedTheftChanceIsDmSet();


// -----------------------------------------------------------------------
// Table II.B: magic treasure (d20).
// Bands 0-6 cover die results 1-5, 6-8,
// 9-12, 13-14, 15-18, 19, 20.
// -----------------------------------------------------------------------
    int magicBandCount();
    int magicBandLo(int row);
    int magicBandHi(int row);
    int magicBandItems(int row);
    int magicBandExtraPotions(int row);
    int magicBandPotions(int row);
    int magicBandScrolls(int row);
    int magicBandSwords(int row);
    int magicBandArmorOrShield(int row);
    int magicBandMiscWeapons(int row);
    int magicBandNoSwordOrPotions(int row);
    int magicBandRings(int row);
    int magicBandRods(int row);
    int magicBandMiscMagic(int row);
    int magicTableWeightedByDesign();
};
