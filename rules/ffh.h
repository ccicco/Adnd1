// =========================================================================================
// Adnd1 - rules/ffh.h
// the hornet promotion - the dungeon FF surface closes
// census 762 -> 763.
//
// spec-driven; the hornet promotion round - the giant hornet def lifted from
// the FF print (p. 52, the ff_print xp class) as a new lua data file, the die
// 14 Monster Level IV dungeon cell rekeyed (the R839 holdout - the FF p. 52
// stat block the batch did not carry), the keyless FF rows drain two to one
// (the Elemental Prince row stays keyless, the settled no-def read), the
// dungeon walk-key census re-pinned (170 -> 171), the blank census drains 20
// -> 19, the registry 912 -> 913, the ff def census 102 -> 103, the source
// rows stay (ff 26 dungeon), no gap boxes flip; the def body carries the
// print-fidelity pin headers
//
namespace rules {

// ---- the hornet promotion ----

// the round
inline int ffhRound()
    { return 840; }

// the def in the hornet promotion round
inline int ffhBatchDefs()
    { return 1; }

// the dungeon cell rekeyed this round
inline int ffhDunCellsRewired()
    { return 1; }

// the dungeon walk-key census before
inline int ffhDunKeyedBefore()
    { return 170; }

// the dungeon walk-key census after
inline int ffhDunKeyedAfter()
    { return 171; }

// the blank dungeon cells before
inline int ffhDunBlankBefore()
    { return 20; }

// the blank dungeon cells after
inline int ffhDunBlankAfter()
    { return 19; }

// the character-party rows (blank by design, the DMG subtable)
inline int ffhDunPartyBlankRows()
    { return 10; }

// the (MM1) rows left blank (no def in the registry)
inline int ffhDunMm1BlankCells()
    { return 4; }

// the (MM2) rows left blank (no def in the registry)
inline int ffhDunMm2BlankCells()
    { return 2; }

// the unique-court rows left keyless (the Level X demon prince and devil duke
// rows)
inline int ffhDunCourtKeylessCells()
    { return 2; }

// the (FF) rows across the ten grids (unchanged)
inline int ffhDunFfRows()
    { return 26; }

// the FF rows keyed after the round
inline int ffhDunFfKeyed()
    { return 25; }

// the keyless FF rows before (the Elemental Prince and Hornet Giant rows)
inline int ffhDunFfKeylessBefore()
    { return 2; }

// the keyless FF rows after (the Elemental Prince row)
inline int ffhDunFfKeylessAfter()
    { return 1; }

// the Elemental Prince row (no print def, the settled no-def read)
inline int ffhDunFfElementalRows()
    { return 1; }

// the registry census before the round
inline int ffhRegistryBefore()
    { return 912; }

// the registry census after the round
inline int ffhRegistryAfter()
    { return 913; }

// the ff def census before the round
inline int ffhFfDefsBefore()
    { return 102; }

// the ff def census after the round
inline int ffhFfDefsAfter()
    { return 103; }

// the hornet def lifts the FF print
inline bool ffhDefFromFfPrint()
    { return true; }

// the source rows ride unchanged
inline bool ffhSourceRowsStay()
    { return true; }

// no MM2 gap boxes flip this round
inline bool ffhNoGapBoxesFlip()
    { return true; }

// the Elemental Prince row rides keyless (the settled no-def read)
inline bool ffhDunElementalStaysKeyless()
    { return true; }

}   // namespace rules
