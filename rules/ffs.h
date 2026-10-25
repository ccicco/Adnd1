// =========================================================================================
// Adnd1 - rules/ffs.h
// the second FF promotion batch - 25 more ff defs walk
// census 759 -> 760.
//
// spec-driven; the second Fiend Folio promotion batch - twenty-five defs
// lifted from the ff print as new lua data files (disenchanter through
// sandman, the print-order batch), the forty-two blank outdoor encounter
// cells rekeyed (forty-one to the new defs, the one Grabman cell to the
// standing crabman def - the print misspelling settle), the outdoor walk-key
// census re-pinned (590 -> 632), the registry 837 -> 862, the ff def census
// 27 -> 52, the keyless outdoor FF cells 56 -> 14, the source rows stay (ff
// 74 outdoor), no aquatic cells this round (the remaining aquatic blanks are
// structural rows), the huecuva xp line pins the print verbatim (the III/81
// per hit point read, the + settle noted in the record), no gap boxes flip;
// the def bodies carry the print-fidelity pin headers
//
namespace rules {

// ---- the second FF promotion batch ----

// the round
inline int ffsRound()
    { return 837; }

// the standing pace: defs per promotion round
inline int ffsPaceDefs()
    { return 25; }

// the defs in the second FF promotion batch
inline int ffsBatchDefs()
    { return 25; }

// the outdoor cells rekeyed to batch defs
inline int ffsOutCellsRewired()
    { return 42; }

// the cells rekeyed to new batch defs
inline int ffsNewDefCells()
    { return 41; }

// the Grabman cell rekeyed to the standing crabman def
inline int ffsGrabmanCells()
    { return 1; }

// the aquatic cells rekeyed this round (none - the tail is structural)
inline int ffsAquaCellsRewired()
    { return 0; }

// the outdoor walk-key census before
inline int ffsOutWalkKeysBefore()
    { return 590; }

// the outdoor walk-key census after
inline int ffsOutWalkKeysAfter()
    { return 632; }

// the keyless outdoor FF cells before
inline int ffsOutFfKeylessBefore()
    { return 56; }

// the keyless outdoor FF cells after
inline int ffsOutFfKeylessAfter()
    { return 14; }

// the FF rows already keyed (the R820 and R836 rewires)
inline int ffsKeyedFfRows()
    { return 18; }

// the outdoor FF source rows (unchanged)
inline int ffsFfSourceRows()
    { return 74; }

// the registry census before the batch
inline int ffsRegistryBefore()
    { return 837; }

// the registry census after the batch
inline int ffsRegistryAfter()
    { return 862; }

// the ff def census before the batch
inline int ffsFfDefsBefore()
    { return 27; }

// the ff def census after the batch
inline int ffsFfDefsAfter()
    { return 52; }

// every batch def lifts the FF print
inline bool ffsDefsFromFfPrint()
    { return true; }

// the source rows ride unchanged
inline bool ffsSourceCellsStay()
    { return true; }

// no MM2 gap boxes flip this round
inline bool ffsNoGapBoxesFlip()
    { return true; }

// the print Grabman cell is the FF Crabman (the misspelling settle)
inline bool ffsGrabmanIsCrabman()
    { return true; }

}   // namespace rules
