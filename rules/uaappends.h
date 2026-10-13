// ===========================================================================
// Adnd1 - rules/uaappends.h
// The UA APPENDIX S stat blocks,
// R406: the 23 non-human deity
// stat blocks (pp. 110-120) - the
// ungated data round riding the
// R405 deity layer seam. The
// R337/R391 pin-round precedent:
// the scan-clean stat-line numerics
// pin; the messy reads stay open
// (the six class/level lines, the
// MOVE values, the S/I/W/D/C/CH/CM
// stat lines, the prose).
//
// The census (live cross-checked
// against the R405 seam): 23
// blocks, 5 pantheons (dwarves 0-4,
// elves 5-9, halflings 10-13,
// gnomes 14-17, orcs 18-22); the
// tiers 5 greater / 16 lesser / 2
// demigods; the psionic ratings
// VI 10, III 5, IV 1, Nil 6, plus
// Brandobaris unrecorded (no
// rating line in the print).
//
// The fields per block: tier,
// armor class, hit points, magic
// resistance percent, psionic
// rating code, size, the
// attacks per round (in HALVES:
// 4 = 2/round, 3 = 3/2, 8 = 4),
// the damage range min/max, and
// the printed alignment and plane
// strings.
//
// The scan holes record as
// sentinels, not guesses:
//   - UAS_AC_HOLE (99): the Hanali
//     armor class - the scan garbles
//     the line (one hole);
//   - UAS_ATK_HOLE (-1): the
//     Shargaas attacks line - the
//     scan garbles it (one hole);
//   - UAS_DMG_UNRECORDED (-1): the
//     unprinted damage reads -
//     Labelas and Yurtrus print
//     "see below", Cyrrollalee
//     "by weapon type", and the
//     Brandobaris range garbles
//     (four unrecorded); Hanali
//     prints Nil - 0/0, clean.
//
// The damage ranges read min-max
// as printed (Urdlen "S: 4-16"
// pins 4-16; the parenthetical
// plusses ride the stat lines,
// unpinned).
//
// The tier codes: 0 greater, 1
// lesser, 2 demigod. The rating
// codes: 0 VI, 1 III, 2 IV, 3 Nil,
// -1 unrecorded. The size codes:
// 0 S, 1 M, 2 L.

#pragma once

namespace rules {

enum UasTier {
    UAS_TIER_GREATER = 0,
    UAS_TIER_LESSER,
    UAS_TIER_DEMI
};

enum UasRating {
    UAS_RATING_VI = 0,
    UAS_RATING_III,
    UAS_RATING_IV,
    UAS_RATING_NIL,
    UAS_RATING_UNRECORDED = -1
};

enum UasSize {
    UAS_SIZE_S = 0,
    UAS_SIZE_M,
    UAS_SIZE_L
};

const int UAS_AC_HOLE = 99;
const int UAS_ATK_HOLE = -1;
const int UAS_DMG_UNRECORDED = -1;

struct UasStatBlock {
    const char* name;
    int tier;
    int ac;
    int hp;
    int mr;
    int rating;
    int size;
    int atkHalves;
    int dmgMin;
    int dmgMax;
    const char* align;
    const char* plane;
};

// The 23 stat blocks, in pantheon
// order (the R405 registry order):
// dwarves, elves, halflings,
// gnomes, orcs.
inline const UasStatBlock& uasStat(
        int i) {
    static const UasStatBlock T[23] = {
        // ---- the dwarves (pp. 110-111) ----
        { "CLANGGEDIN SILVERBEARD",
          0, -4, 375, 50, 0, 2, 4,
          3, 36, "Lawful neutral",
          "Arcadia" },
        { "VERGADAIN",
          0, -5, 345, 70, 1, 2, 3,
          3, 30, "Neutral",
          "Concordant Opposition" },
        { "DUMATHOIN",
          0, -2, 366, 70, 0, 2, 4,
          10, 40, "Neutral",
          "Concordant Opposition" },
        { "ABBATHOR",
          0, 0, 330, 50, 1, 2, 4,
          2, 24, "Neutral evil",
          "Hades" },
        { "BERRONAR",
          0, -4, 370, 80, 1, 2, 4,
          6, 36, "Lawful good",
          "Seven Heavens" },
        // ---- the elves (pp. 112-113) ----
        { "AERDRIE FAENYA",
          1, -5, 322, 80, 0, 1, 4,
          6, 20, "Chaotic good",
          "Olympus and Gladsheim" },
        { "EREVAN ILESERE",
          1, -1, 290, 85, 1, 0, 2,
          2, 24, "Chaotic neutral",
          "Olympus" },
        { "SOLONOR THELANDIRA",
          1, -2, 308, 85, 0, 1, 8,
          2, 16, "Chaotic good",
          "Olympus" },
        { "HANALI CELANIL",
          1, 99, 312, 95, 0, 1, 0,
          0, 0, "Chaotic good",
          "Olympus" },
        { "LABELAS ENORETH",
          1, -3, 310, 93, 0, 1, 2,
          -1, -1, "Chaotic good",
          "Olympus" },
        // ---- the halflings (pp. 114-115) ----
        { "SHEELA PERYROYL",
          1, 3, 306, 80, 3, 0, 2,
          2, 16, "Neutral",
          "Concordant Opposition" },
        { "ARVOREEN",
          1, 1, 298, 65, 3, 1, 3,
          2, 20, "Lawful good",
          "Seven Heavens" },
        { "CYRROLLALEE",
          1, 3, 260, 75, 3, 0, 3,
          -1, -1, "Lawful good",
          "Seven Heavens" },
        { "BRANDOBARIS",
          2, 0, 185, 60, -1, 0, 2,
          -1, -1, "Neutral",
          "Prime Material" },
        // ---- the gnomes (pp. 116-117) ----
        { "BAERVAN WILDWANDERER",
          1, 1, 295, 20, 1, 0, 3,
          2, 24, "Neutral good",
          "Twin Paradises or Prime Material Plane" },
        { "URDLEN",
          1, 2, 272, 30, 0, 2, 4,
          4, 16, "Chaotic evil",
          "Abyss" },
        { "SEGOJAN EARTHCALLER",
          1, 0, 285, 20, 0, 1, 2,
          3, 30, "Neutral good",
          "Twin Paradises" },
        { "FLANDAL STEELSKIN",
          2, 2, 230, 10, 0, 0, 3,
          3, 24, "Neutral good",
          "Twin Paradises" },
        // ---- the orcs (pp. 118-120) ----
        { "BAHGTRU",
          1, 1, 340, 35, 3, 2, 4,
          10, 60, "Lawful evil",
          "Nine Hells" },
        { "SHARGAAS",
          1, 2, 265, 65, 2, 2, -1,
          3, 30, "Neutral evil",
          "Gehenna" },
        { "ILNEVAL",
          1, -1, 331, 55, 3, 2, 4,
          6, 36, "Lawful evil",
          "Nine Hells" },
        { "YURTRUS",
          1, 0, 303, 75, 0, 2, 4,
          -1, -1, "Neutral evil",
          "Hades" },
        { "LUTHIC",
          1, 3, 287, 80, 3, 2, 4,
          5, 20, "Lawful evil",
          "Nine Hells" },
    };
    if (i < 0) i = 0;
    if (i > 22) i = 22;
    return T[i];
}

inline int uasDeityCount()
    { return 23; }

// The tier census: 5 greater,
// 16 lesser, 2 demigods.
inline int uasTierCount(int tier) {
    int n = 0;
    for (int i = 0; i < 23; ++i)
        if (uasStat(i).tier == tier) ++n;
    return n;
}

// The rating census: VI 10, III 5,
// IV 1, Nil 6, unrecorded 1 -
// matching the R405 seam counts
// for the four printed codes.
inline int uasRatingCount(int code) {
    int n = 0;
    for (int i = 0; i < 23; ++i)
        if (uasStat(i).rating == code) ++n;
    return n;
}

// The pantheon slices: dwarves,
// elves, halflings, gnomes, orcs.
inline int uasPantheonSize(int p) {
    if (p == 0) return 5;
    if (p == 1) return 5;
    if (p == 2) return 4;
    if (p == 3) return 4;
    return 5;
}

// The scan holes: one AC garble
// (Hanali), one attacks garble
// (Shargaas).
inline int uasAcHoleCount() {
    int n = 0;
    for (int i = 0; i < 23; ++i)
        if (uasStat(i).ac == UAS_AC_HOLE) ++n;
    return n;
}

inline int uasAtkHoleCount() {
    int n = 0;
    for (int i = 0; i < 23; ++i)
        if (uasStat(i).atkHalves
                == UAS_ATK_HOLE) ++n;
    return n;
}

// The unprinted damage reads: 4.
inline int uasDamageUnrecordedCount() {
    int n = 0;
    for (int i = 0; i < 23; ++i)
        if (uasStat(i).dmgMin
                == UAS_DMG_UNRECORDED) ++n;
    return n;
}

// The total hit points across the
// 23 blocks - the drift catch:
// any single cell change moves it.
inline int uasTotalHitPoints() {
    int n = 0;
    for (int i = 0; i < 23; ++i)
        n += uasStat(i).hp;
    return n;
}

}   // namespace rules

