// ============================================================================
// Adnd1 - rules/equipcosts.h
// The equipment cost columns (R300; the
// general lists R308).
//
// The PHB BASIC EQUIPMENT AND SUPPLIES COSTS tables (the
// equipment section, upload line 2113; the reference-sheet
// repeat, upload line 13432): the ARMS list - 52 rows (the
// left column arrow through hammer, the right column javelin
// through voulge; together alphabetical) - and the ARMOR list
// - 14 rows, alphabetical. Every price pins in its printed
// coin: the gold-piece rows and the six silver-piece ammo
// rows (the single arrow 2 s.p., the dart 5, the javelin 10,
// the light quarrel 1, the dozen sling and bullets 15 and the
// score of sling bullets 10). Exactly one coin column is
// nonzero on every arms row (the R300a battery audit walks
// the identity). The monetary-system pin rides: 20 silver
// pieces = 1 gold piece (eqcSilverPerGold).
//
// SOURCE NOTE: the reference sheet is the legible copy; the
// equipment-section table interleaves in the OCR, but it
// confirms the left rows 1-28 and the right rows 1-24 and
// resolves the empty reference-sheet glaive cell to 6 g.p.
//
// JUDGMENTs:
//   - the armor row 1 prints Bonded in the reference sheet
//     and Banded in the equipment copy - the standard banded
//     mail row (90 g.p.), pinned under the banded name.
//   - the row names follow the R189 weaponChartName spellings
//     where the rows match (footman flail, lucern hammer,
//     awl pike and the rest; the purchase units spelled out:
//     arrow, normal, dozen and quarrel, light, single).
//
// The ENGINE side (items/items.cpp costGp) is repinned by
// this round where it diverged - the printed-table-wins
// debt; the R300 battery audit maps every engine weapon and
// armor id to its printed row. The general equipment rows
// (clothing, herbs, livestock, provisions, religious items,
// tack, transport) are the R308 general lists below - the
// R307 scope pass opened them, R308 pins them, and no
// engine site charges them yet (the town stores price
// canonically).
//
// DATA-DRIVEN (the standing scope).
// ============================================================================

#pragma once

namespace rules {

// ---- the arms list (52 rows) ----

// The chart row count (the print: 52 arms rows).
inline int eqcArmsCount() {
    // the two printed columns together, alphabetical
    return 52;
}

// The arms row name at index i (clamped), the print order.
inline const char* eqcArmsName(int i) {
    static const char* const kNames[52] = {
        "arrow, normal, single",
        "arrow, normal, dozen",
        "arrow, silver, single",
        "axe, battle",
        "axe, hand or throwing",
        "bardiche",
        "bec de corbin",
        "bill-guisarme",
        "bow, composite, short",
        "bow, composite, long",
        "bow, long",
        "bow, short",
        "crossbow, heavy",
        "crossbow, light",
        "dagger and scabbard",
        "dart",
        "fauchard",
        "fauchard-fork",
        "footman flail",
        "horseman flail",
        "military fork",
        "glaive",
        "glaive-guisarme",
        "guisarme",
        "guisarme-voulge",
        "halberd",
        "lucern hammer",
        "hammer",
        "javelin",
        "lance",
        "footman mace",
        "horseman mace",
        "morning star",
        "partisan",
        "footman pick",
        "horseman pick",
        "awl pike",
        "quarrel, light, single",
        "quarrel, heavy, score",
        "ranseur",
        "scimitar",
        "sling and bullets, dozen",
        "sling bullets, score",
        "spear",
        "spetum",
        "bastard sword and scabbard",
        "broad sword and scabbard",
        "long sword and scabbard",
        "short sword and scabbard",
        "two-handed sword",
        "trident",
        "voulge",
    };
    if (i < 0) i = 0;
    if (i > 51) i = 51;
    return kNames[i];
}

// The arms price in gold pieces (the silver rows pin 0
// here - exactly one unit nonzero per row).
inline int eqcArmsGold(int i) {
    static const int kGold[52] = {
         0,   1,   1,   5,   1,   7,   6,   6,  75, 100,
        60,  15,  20,  12,   2,   0,   3,   8,   3,   8,
         4,   6,  10,   5,   7,   9,   7,   1,   0,   6,
         8,   4,   5,  10,   8,   5,   3,   0,   2,   4,
        15,   0,   0,   1,   3,  25,  10,  15,   8,  30,
         4,   2,
    };
    if (i < 0) i = 0;
    if (i > 51) i = 51;
    return kGold[i];
}

// The arms price in silver pieces (the six ammo rows).
inline int eqcArmsSilver(int i) {
    static const int kSilver[52] = {
         2,   0,   0,   0,   0,   0,   0,   0,   0,   0,
         0,   0,   0,   0,   0,   5,   0,   0,   0,   0,
         0,   0,   0,   0,   0,   0,   0,   0,  10,   0,
         0,   0,   0,   0,   0,   0,   0,   1,   0,   0,
         0,  15,  10,   0,   0,   0,   0,   0,   0,   0,
         0,   0,
    };
    if (i < 0) i = 0;
    if (i > 51) i = 51;
    return kSilver[i];
}

// ---- the armor list (14 rows) ----

// The armor row count (the print: 14 armor rows).
inline int eqcArmorCount() {
    // the two printed columns together, alphabetical
    return 14;
}

// The armor row name at index i (clamped), the print order.
inline const char* eqcArmorName(int i) {
    static const char* const kNames[14] = {
        "banded",
        "chain",
        "helmet, great",
        "helmet, small",
        "leather",
        "padded",
        "plate",
        "ring",
        "scale",
        "shield, large",
        "shield, small",
        "shield, small, wooden",
        "splinted",
        "studded",
    };
    if (i < 0) i = 0;
    if (i > 13) i = 13;
    return kNames[i];
}

// The armor price in gold pieces (every armor row prints
// in gold).
inline int eqcArmorGold(int i) {
    static const int kGold[14] = {
        90,  75,  15,  10,   5,   4,
       400,  30,  45,  15,  10,   1,
        80,  15,
    };
    if (i < 0) i = 0;
    if (i > 13) i = 13;
    return kGold[i];
}

// ---- the general lists (R308) ----

// The EIGHT printed general lists of the BASIC
// EQUIPMENT AND SUPPLIES COSTS tables (the
// equipment section, upload lines 2344-2437; the
// reference-sheet repeat, upload lines 13473-13541):
// clothing 11 rows, herbs 3, livestock 21,
// miscellaneous equipment and items 29, provisions
// 10, religious items 6, tack and harness 9,
// transport 10 - 99 rows together. Every price pins
// in its printed coin (exactly one coin column
// nonzero per row: 11 copper, 29 silver, 59 gold).
// The row order is the R300 arms convention (the
// left column then the right, per list). The
// reference sheet is the complete legible copy: it
// resolves the scrambled herbs cells and the eight
// transport cells the equipment-section OCR drops.

// The chart row count (the print: 99 general rows).
inline int eqcGeneralCount() {
    return 99;
}

// The list row count at list index l (clamped):
// clothing 0, herbs 1, livestock 2, miscellaneous
// equipment and items 3, provisions 4, religious
// items 5, tack and harness 6, transport 7.
inline int eqcGeneralListCount(int l) {
    static const int kCounts[8] = {
          11,    3,   21,   29,   10,    6,    9,   10,
    };
    if (l < 0) l = 0;
    if (l > 7) l = 7;
    return kCounts[l];
}

// The first row of list l (clamped).
inline int eqcGeneralFirst(int l) {
    static const int kFirst[8] = {
           0,   11,   14,   35,   64,   74,   80,   89,
    };
    if (l < 0) l = 0;
    if (l > 7) l = 7;
    return kFirst[l];
}

// The general row name at index i (clamped), the
// R300 name spellings (the foot marks spelled out;
// the ampersands read as and; the riding-light
// horse parens dropped). The two print apostrophe
// names ride as printed; the holy symbol and holy
// water rows serve the unholy footnote equally.
inline const char* eqcGeneralName(int i) {
    static const char* const kNames[99] = {
        "belt",
        "boots, high, hard",
        "boots, high, soft",
        "boots, low, hard",
        "boots, low, soft",
        "cap",
        "cloak",
        "girdle, broad",
        "girdle, normal",
        "hat",
        "robe",
        "belladonna, sprig",
        "garlic, bud",
        "wolvesbane, sprig",
        "chicken",
        "cow",
        "dog, guard",
        "dog, hunting",
        "donkey",
        "goat",
        "hawk, large",
        "hawk, small",
        "horse, draft",
        "horse, heavy war",
        "horse, light war",
        "horse, medium war",
        "horse, riding, light",
        "mule",
        "ox",
        "pigeon",
        "piglet",
        "pig",
        "pony",
        "sheep",
        "songbird",
        "backpack, leather",
        "box, iron, large",
        "box, iron, small",
        "candle, tallow",
        "candle, wax",
        "case, bone, map or scroll",
        "case, leather, map or scroll",
        "chest, wooden, large",
        "chest, wooden, small",
        "lantern, bullseye",
        "lantern, hooded",
        "mirror, large metal",
        "mirror, small, silver",
        "oil, flask of",
        "pole, 10 foot",
        "pouch, belt, large",
        "pouch, belt, small",
        "quiver, 1 dozen arrows",
        "quiver, 1 score arrows",
        "quiver, 1 score bolts",
        "quiver, 2 score bolts",
        "rope, 50 foot",
        "sack, large",
        "sack, small",
        "skin for water or wine",
        "spike, iron, large",
        "thieves' picks and tools",
        "tinder box with flint and steel",
        "torch",
        "ale, pint",
        "beer, small, pint",
        "food, merchant's meal",
        "food, rich meal",
        "grain, horse meal, 1 day",
        "mead, pint",
        "rations, iron, 1 week",
        "rations, standard, 1 week",
        "wine, pint, good",
        "wine, pint, watered",
        "beads, prayer",
        "incense, stick",
        "symbol, holy, iron",
        "symbol, holy, silver",
        "symbol, holy, wooden",
        "water, holy, vial",
        "barding, chain",
        "barding, leather",
        "barding, plate",
        "bit and bridle",
        "harness",
        "saddle",
        "saddle bags, large",
        "saddle bags, small",
        "saddle blanket",
        "barge or raft, small",
        "boat, small",
        "boat, long",
        "cart",
        "galley, large",
        "galley, small",
        "ship, merchant, large",
        "ship, merchant, small",
        "ship, war",
        "wagon",
    };
    if (i < 0) i = 0;
    if (i > 98) i = 98;
    return kNames[i];
}

// The general price in gold pieces (clamped; the 59
// gold rows).
inline int eqcGeneralGold(int i) {
    static const int kGold[99] = {
           0,    2,    1,    1,    0,    0,    0,    2,    0,    0,
           0,    0,    0,    0,    0,   10,   25,   17,    8,    1,
          40,   18,   30,  300,  150,  225,   25,   20,   15,    0,
           1,    3,   15,    2,    0,    2,   28,    9,    0,    0,
           5,    0,    0,    0,   12,    7,   10,   20,    1,    0,
           1,    0,    0,    0,    0,    1,    0,    0,    0,    0,
           0,   30,    1,    0,    0,    0,    0,    1,    0,    0,
           5,    3,    0,    0,    1,    1,    2,   50,    0,   25,
         250,  100,  500,    0,    0,   10,    4,    3,    0,   50,
          75,  150,   50, 25000, 10000, 15000, 5000, 20000,  150,
    };
    if (i < 0) i = 0;
    if (i > 98) i = 98;
    return kGold[i];
}

// The general price in silver pieces (clamped; the
// 29 silver rows).
inline int eqcGeneralSilver(int i) {
    static const int kSilver[99] = {
           3,    0,    0,    0,    8,    1,    5,    0,   10,    7,
           6,    4,    0,   10,    0,    0,    0,    0,    0,    0,
           0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
           0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
           0,   15,   17,    8,    0,    0,    0,    0,    0,    0,
           0,   15,    8,   12,   15,    0,    4,    0,    0,   15,
           0,    0,    0,    0,    1,    0,    1,    0,    1,    5,
           0,    0,   10,    5,    0,    0,    0,    0,    7,    0,
           0,    0,    0,   15,   12,    0,    0,    0,    3,    0,
           0,    0,    0,    0,    0,    0,    0,    0,    0,
    };
    if (i < 0) i = 0;
    if (i > 98) i = 98;
    return kSilver[i];
}

// The general price in copper pieces (clamped; the
// 11 copper rows).
inline int eqcGeneralCopper(int i) {
    static const int kCopper[99] = {
           0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
           0,    0,    5,    0,    3,    0,    0,    0,    0,    0,
           0,    0,    0,    0,    0,    0,    0,    0,    0,    2,
           0,    0,    0,    0,    4,    0,    0,    0,    1,    0,
           0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
           0,    0,    0,    0,    0,    0,    0,   16,   10,    0,
           1,    0,    0,    1,    0,    5,    0,    0,    0,    0,
           0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
           0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
           0,    0,    0,    0,    0,    0,    0,    0,    0,
    };
    if (i < 0) i = 0;
    if (i > 98) i = 98;
    return kCopper[i];
}

// The monetary-system pins (the upload MONETARY
// SYSTEM section: 200 c.p. = 20 s.p. = 1 g.p.): the
// R300 silver pin and the R308 copper pins.
inline int eqcSilverPerGold() {
    return 20;
}

inline int eqcCopperPerSilver() {
    return 10;
}

inline int eqcCopperPerGold() {
    return 200;
}

}  // namespace rules
