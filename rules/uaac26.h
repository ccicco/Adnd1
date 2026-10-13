// ===========================================================================
// Adnd1 - rules/uaac26.h
// The UA ARMOR CLASS TABLE (p. 26),
// R408: the 11 composite rows AC 10
// down to 0, pinned directly from
// the print. The R392 manifest
// closed the item by derivation
// (the R371 pin pp. 75-76 + the
// R191 seam); this round pins the
// printed rows as printed and
// closes the two stale duplicate
// boxes the R392 pass missed in
// the weapons section checklist.
//
// The print (the clean djvu scan,
// agreeing with the R392 PDF read):
//   10: none;
//    9: shield only;
//    8: leather armor or padded
//       armor;
//    7: leather + shield, padded +
//       shield, studded leather,
//       ring mail;
//    6: studded leather + shield,
//       ring mail + shield, scale
//       mail;
//    5: scale mail + shield, chain
//       mail, elfin chain mail;
//    4: chain mail + shield, elfin
//       chain + shield, splint
//       mail, banded mail, bronze
//       plate mail;
//    3: splint mail + shield,
//       banded mail + shield,
//       bronze plate mail + shield,
//       plate mail;
//    2: plate mail + shield or
//       field plate armor;
//    1: field plate armor + shield
//       or full plate armor;
//    0: full plate armor + shield.
// 28 composites across the 11 rows.
//
// The cross-checks run live:
//   - the type rows read
//     armorRatingAc (the R191
//     ladder): leather 8, chain 5,
//     plate mail 3;
//   - the shield composites read
//     base minus
//     armorRatingShieldStep (the
//     leather 8 with shield 7, the
//     scale 6 with shield 5, the
//     full plate 1 with shield 0);
//   - the bronze plate mail reads 4,
//     one worse than plate mail 3 -
//     the R371 description pin;
//   - the R392 equipment costs
//     re-verify against the scan:
//     bronze plate 100 gp, full
//     plate 4000 gp, field plate
//     2000 gp, the buckler 5 gp.

#pragma once

namespace rules {

// The row count (AC 10 down to 0).
inline int uacrRowCount()
    { return 11; }

// The i-th row armor class
// (10 - i).
inline int uacrRowAc(int i)
    { return 10 - i; }

// The i-th row armor-set
// description, as printed.
inline const char* uacrRowSet(int i) {
    static const char* const k[11] = {
        "none",
        "shield only",
        "leather armor or padded armor",
        "leather + shield, padded + shield, studded leather, ring mail",
        "studded leather + shield, ring mail + shield, scale mail",
        "scale mail + shield, chain mail, elfin chain mail",
        "chain mail + shield, elfin chain"
        " + shield, splint mail, banded"
        " mail, bronze plate mail",
        "splint mail + shield, banded mail"
        " + shield, bronze plate mail"
        " + shield, plate mail",
        "plate mail + shield or field plate armor",
        "field plate armor + shield or full plate armor",
        "full plate armor + shield",
    };
    if (i < 0) i = 0;
    if (i > 10) i = 10;
    return k[i];
}

// The composite count per row:
// 1, 1, 2, 4, 3, 3, 5, 4, 2, 2, 1 -
// 28 total.
inline int uacrRowMemberCount(int i) {
    static const int k[11] = {
        1, 1, 2, 4, 3, 3, 5, 4, 2, 2, 1
    };
    if (i < 0) i = 0;
    if (i > 10) i = 10;
    return k[i];
}

// The total composite count (28).
inline int uacrCompositeCount()
    { return 28; }

// True when the row reads a shield
// composite member (rows 3-10 carry
// at least one; rows 0-2 none).
inline bool uacrRowHasShieldMember(int i) {
    return i >= 3;
}

}   // namespace rules

