// ============================================================================
// Adnd1 - rules/equipcosts.h
// The equipment cost columns (R300).
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
// tack, transport) carry no engine layer - out of engine
// scope.
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

// The monetary-system pin: 20 silver pieces = 1 gold
// piece (the upload MONETARY SYSTEM section).
inline int eqcSilverPerGold() {
    return 20;
}

}  // namespace rules
