// =========================================================================================
// Adnd1 - rules/ffu.h
// the fourth FF promotion batch - the dungeon cells rekey
// census 761 -> 762.
//
// spec-driven; the fourth Fiend Folio promotion batch - twenty-five defs
// lifted from the ff print as new lua data files (the fifteen NEW defs that
// key the dungeon FF rows: al_miraj, bullywug, bat_giant, grimlock,
// mephit_fire, drow, lava_children, meenlock, hook_horror, githyanki, grell,
// mezzodaemon, slaad_grey, nycadaemon and slaad_death, plus the ten FILL defs
// in print order: achaierai, adherer, aleax, apparition, astral_searcher,
// babbler, berbalang, blindheim, bonesnapper and booka), the twenty-four
// blank dungeon encounter cells rekeyed (fifteen to the new defs, nine to the
// standing norker, coffer_corpse, quaggoth, kenku, shocker, thoqqua,
// caterwaul, algoid and red_slaad defs), the two FF rows left keyless (the
// Elemental Prince row - no print def - and the Hornet Giant row, the FF p.
// 52 def rides a future promotion), the dungeon walk-key census re-pinned
// (146 -> 170), the blank census drains 44 -> 20, the registry 887 -> 912,
// the ff def census 77 -> 102, the source rows stay (ff 26 dungeon), no gap
// boxes flip; the def bodies carry the print-fidelity pin headers
//
namespace rules {

// ---- the fourth FF promotion batch ----

// the round
inline int ffuRound()
    { return 839; }

// the standing pace: defs per promotion round
inline int ffuPaceDefs()
    { return 25; }

// the defs in the fourth FF promotion batch
inline int ffuBatchDefs()
    { return 25; }

// the dungeon cells rekeyed this round
inline int ffuDunCellsRewired()
    { return 24; }

// the cells rekeyed to new batch defs
inline int ffuNewDefCells()
    { return 15; }

// the cells rekeyed to the standing defs
inline int ffuExistingDefCells()
    { return 9; }

// the dungeon walk-key census before
inline int ffuDunKeyedBefore()
    { return 146; }

// the dungeon walk-key census after
inline int ffuDunKeyedAfter()
    { return 170; }

// the blank dungeon cells before
inline int ffuDunBlankBefore()
    { return 44; }

// the blank dungeon cells after
inline int ffuDunBlankAfter()
    { return 20; }

// the character-party rows (blank by design, the DMG subtable)
inline int ffuDunPartyBlankRows()
    { return 10; }

// the (MM1) rows left blank (no def in the registry)
inline int ffuDunMm1BlankCells()
    { return 4; }

// the (MM2) rows left blank (no def in the registry)
inline int ffuDunMm2BlankCells()
    { return 2; }

// the unique-court rows left keyless (the Level X demon prince and devil duke
// rows)
inline int ffuDunCourtKeylessCells()
    { return 2; }

// the (FF) rows across the ten grids (unchanged)
inline int ffuDunFfRows()
    { return 26; }

// the FF rows keyed after the batch
inline int ffuDunFfKeyed()
    { return 24; }

// the FF rows left keyless (the Elemental Prince and Hornet Giant rows)
inline int ffuDunFfKeylessAfter()
    { return 2; }

// the Elemental Prince row (no print def, the settled no-def read)
inline int ffuDunFfElementalRows()
    { return 1; }

// the Hornet Giant row (the FF p. 52 def rides a future promotion)
inline int ffuDunFfHornetRows()
    { return 1; }

// the registry census before the batch
inline int ffuRegistryBefore()
    { return 887; }

// the registry census after the batch
inline int ffuRegistryAfter()
    { return 912; }

// the ff def census before the batch
inline int ffuFfDefsBefore()
    { return 77; }

// the ff def census after the batch
inline int ffuFfDefsAfter()
    { return 102; }

// every batch def lifts the FF print
inline bool ffuDefsFromFfPrint()
    { return true; }

// the source rows ride unchanged
inline bool ffuSourceRowsStay()
    { return true; }

// no MM2 gap boxes flip this round
inline bool ffuNoGapBoxesFlip()
    { return true; }

// the Elemental Prince row rides keyless (the settled no-def read)
inline bool ffuDunElementalStaysKeyless()
    { return true; }

// the Hornet Giant row rides keyless (the FF print def rides a future
// promotion)
inline bool ffuDunHornetStaysKeyless()
    { return true; }

}   // namespace rules
