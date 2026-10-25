// =========================================================================================
// Adnd1 - rules/ffp.h
// the first FF promotion batch - the ff arc opens
// census 758 -> 759.
//
// spec-driven; the first Fiend Folio promotion batch - twenty-five defs
// lifted from the ff print as new lua data files (thirteen aquatic, twelve
// outdoor), the thirty-seven blank encounter cells rekeyed to their new defs,
// the walk-key censuses re-pinned (the aquatic 192 -> 211, the outdoor 572 ->
// 590), the registry 812 -> 837, the ff def census 2 -> 27, the source rows
// stay (ff 19 aquatic, 74 outdoor), no gap boxes flip; the def bodies carry
// the print-fidelity pin headers
//
namespace rules {

// ---- the first FF promotion batch ----

// the round
inline int ffpRound()
    { return 836; }

// the standing pace: defs per promotion round
inline int ffpDefsPerRound()
    { return 25; }

// the defs in the first FF promotion batch
inline int ffpBatchDefs()
    { return 25; }

// the aquatic defs in the batch
inline int ffpAquaDefs()
    { return 13; }

// the outdoor defs in the batch
inline int ffpOutDefs()
    { return 12; }

// the aquatic cells rekeyed to batch defs
inline int ffpAquaCellsRewired()
    { return 19; }

// the outdoor cells rekeyed to batch defs
inline int ffpOutCellsRewired()
    { return 18; }

// the cells rekeyed in the batch
inline int ffpCellsRewired()
    { return 37; }

// the aquatic walk-key census before
inline int ffpAquaWalkKeysBefore()
    { return 192; }

// the aquatic walk-key census after
inline int ffpAquaWalkKeysAfter()
    { return 211; }

// the outdoor walk-key census before
inline int ffpOutWalkKeysBefore()
    { return 572; }

// the outdoor walk-key census after
inline int ffpOutWalkKeysAfter()
    { return 590; }

// the registry census before the batch
inline int ffpRegistryBefore()
    { return 812; }

// the registry census after the batch
inline int ffpRegistryAfter()
    { return 837; }

// the ff def census before the batch
inline int ffpFfDefsBefore()
    { return 2; }

// the ff def census after the batch
inline int ffpFfDefsAfter()
    { return 27; }

// the defs lift from the ff print
inline bool ffpDefsFromFfPrint()
    { return true; }

// the walk keys settle before the def prose
inline bool ffpWalkPriorityFirst()
    { return true; }

// the source census rows stay put
inline bool ffpSourceCellsStay()
    { return true; }

// no gap boxes flip this round
inline bool ffpNoGapBoxesFlip()
    { return true; }

}   // namespace rules
