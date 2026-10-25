// =========================================================================================
// Adnd1 - rules/fft.h
// the third FF promotion batch - the outdoor tail walks
// census 760 -> 761.
//
// spec-driven; the third Fiend Folio promotion batch - twenty-five defs
// lifted from the ff print as new lua data files (scarecrow through xvart,
// the print-order batch: the outdoor tail plus the s-through-x fill), the
// thirteen blank outdoor encounter cells rekeyed (eleven to the new defs, the
// two disenchanter cells to the standing R837 def), the Mountain Giant cell
// stays keyless (the settled no-def read, the FF p.42 Lambeosaurus
// parenthetical), the outdoor walk-key census re-pinned (632 -> 645), the
// registry 862 -> 887, the ff def census 52 -> 77, the keyless outdoor FF
// cells 14 -> 1, the source rows stay (ff 74 outdoor), no aquatic cells this
// round (the aquatic surface is fully keyed; the dungeon mm2encd FF rows ride
// a future round), no gap boxes flip; the def bodies carry the print-fidelity
// pin headers
//
namespace rules {

// ---- the third FF promotion batch ----

// the round
inline int fftRound()
    { return 838; }

// the standing pace: defs per promotion round
inline int fftPaceDefs()
    { return 25; }

// the defs in the third FF promotion batch
inline int fftBatchDefs()
    { return 25; }

// the outdoor cells rekeyed to batch defs
inline int fftOutCellsRewired()
    { return 13; }

// the cells rekeyed to new batch defs
inline int fftNewDefCells()
    { return 11; }

// the cells rekeyed to the standing disenchanter def
inline int fftExistingDefCells()
    { return 2; }

// the Mountain Giant row left keyless (the settled no-def read)
inline int fftMountainGiantRows()
    { return 1; }

// the outdoor walk-key census before
inline int fftOutWalkKeysBefore()
    { return 632; }

// the outdoor walk-key census after
inline int fftOutWalkKeysAfter()
    { return 645; }

// the keyless outdoor FF cells before
inline int fftOutFfKeylessBefore()
    { return 14; }

// the keyless outdoor FF cells after (the Mountain Giant row)
inline int fftOutFfKeylessAfter()
    { return 1; }

// the FF rows already keyed (the R820, R836 and R837 rewires)
inline int fftKeyedFfRows()
    { return 60; }

// the outdoor FF source rows (unchanged)
inline int fftFfSourceRows()
    { return 74; }

// the registry census before the batch
inline int fftRegistryBefore()
    { return 862; }

// the registry census after the batch
inline int fftRegistryAfter()
    { return 887; }

// the ff def census before the batch
inline int fftFfDefsBefore()
    { return 52; }

// the ff def census after the batch
inline int fftFfDefsAfter()
    { return 77; }

// every batch def lifts the FF print
inline bool fftDefsFromFfPrint()
    { return true; }

// the source rows ride unchanged
inline bool fftSourceCellsStay()
    { return true; }

// no MM2 gap boxes flip this round
inline bool fftNoGapBoxesFlip()
    { return true; }

// the Mountain Giant cell rides keyless (the settled no-def read)
inline bool fftMountainGiantStaysKeyless()
    { return true; }

}   // namespace rules
