// ===========================================================================
// Adnd1 - rules/uadetskel.h
// The UA RANDOM TREASURE
// DETERMINATION - MAGIC ITEMS
// (Revised Table) skeleton pins
// (pp. 84-89), R375: the
// top-level category bands and
// the sub-table splits. The row
// bodies ride R395 - the clean
// PDF read fills every row
// (rules/uadetrows.h); the
// extract markers below flip
// with it. The dial ride: the
// R374 seam (checked in the
// regtest audit, not here).
namespace rules {

// ---- the top-level categories ----
// The printed order, eight
// categories.
inline int uadsCategoryCount()
    { return 8; }

inline const char* uadsCategoryName(int i) {
    static const char* const k[8] = {
        "Potions", "Scrolls", "Rings",
        "Rods, Staves & Wands",
        "Miscellaneous Magic",
        "Armor & Shields", "Swords",
        "Miscellaneous Weapons",
    };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return k[i];
}

inline int uadsCategoryLo(int i) {
    static const int k[8] = {
        1, 21, 36, 41, 46, 61, 76, 87
    };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return k[i];
}

inline int uadsCategoryHi(int i) {
    static const int k[8] = {
        20, 35, 40, 45, 60, 75, 86, 100
    };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return k[i];
}

// The printed heading: MAGIC
// ITEMS (Revised Table).
inline bool uadsIsTheRevisedTable()
    { return true; }

// ---- the sub-table splits ----
// Each category's second roll
// splits low/high; the low band
// is the new UA table, the high
// band the original DMG table
// (the potions low band carries
// the new potions - the elixirs
// and oils).
inline int uadsPotionSplitLo()
    { return 65; }

inline bool uadsPotionLowBandIsNewPotions()
    { return true; }

inline int uadsScrollSplitLo()
    { return 85; }

inline int uadsRingSplitLo()
    { return 67; }

inline int uadsRodSplitLo()
    { return 40; }

inline int uadsArmorSplitLo()
    { return 50; }

inline int uadsSwordSplitLo()
    { return 95; }

inline int uadsWeaponSplitLo()
    { return 50; }

// The named second tables the
// print carries: the scroll
// II.B.2, the rod II.D.2, the
// sword II.G and II.G.2.
inline bool uadsScrollSecondTableIsIIB2()
    { return true; }

inline bool uadsRodSecondTableIsIID2()
    { return true; }

inline bool uadsSwordFirstTableIsIIG()
    { return true; }

inline bool uadsSwordSecondTableIsIIG2()
    { return true; }

// ---- the miscellaneous magic
// sub-tables ----
// SEVEN sub-bands, all named -
// III.E.1 through III.E.7; the
// R395 clean read names the
// seventh the extract lost.
inline int uadsMiscSubCount()
    { return 7; }

inline int uadsMiscSubNamedCount()
    { return 7; }

inline bool uadsMiscSubSeventhNameGarbles()
    { return false; }

inline int uadsMiscSubLo(int i) {
    static const int k[7] = {
        1, 15, 29, 43, 57, 71, 86
    };
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    return k[i];
}

inline int uadsMiscSubHi(int i) {
    static const int k[7] = {
        14, 28, 42, 56, 70, 85, 100
    };
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    return k[i];
}

// ---- the scroll footnotes ----
// 30% of all spell scrolls are
// clerical (the dice 71-00 band);
// 25% of clerical scrolls are
// druidical; 10% of MU spell
// scrolls are illusionist - the
// applies-only-to-01-60 clause.
inline int uadsScrollClericalPct()
    { return 30; }

inline int uadsScrollClericalDruidPct()
    { return 25; }

inline int uadsScrollMuIllusionistPct()
    { return 10; }

inline bool uadsScrollFootnoteBandIs71To00()
    { return true; }

// The cursed-scroll footnote
// points at the DMG, p. 121.
inline int uadsScrollCurseDmgPage()
    { return 121; }

// ---- the extract read ----
// The R395 clean read delivers
// every row body - the marker
// flips false (the rows pin in
// rules/uadetrows.h).
inline bool uadsRowBodiesGarble()
    { return false; }

}   // namespace rules

