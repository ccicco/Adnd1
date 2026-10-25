// =========================================================================================
// Adnd1 - rules/ffk.h
// the sixth FF promotion batch - the missing prints walk on
// census 765 -> 766.
//
// spec-driven; the sixth Fiend Folio promotion batch - twenty-five of the
// fifty-seven missing FF print stat-blocks lifted as new lua data files, the
// holdouts in ToC order from the flind p. 39 through the kuo-toa pp. 57-59
// (the garbug promoting as two defs - the black and the violet, the
// two-column variant precedent; the fog giant p. 42, the mountain giant p. 42
// and the giant strider p. 42 riding the print family prose; the kuo-toa
// carrying its three-page community entry with the hit-point, arms and slave
// tables), the stat blocks read from the three-voice scan collation (the djvu
// text, the word-geometry xml, the abbyy char xml) with the 1eonline print
// transcripts recovering the shredded rows - the guardian familiar psionic
// and attack/defence mode rows stay unrecovered in both scan voices and ride
// the query-mark sentinel per the landed precedent (dryad, dwarf, dragon
// turtle); the scan OCRs 1 as 7 systematically (the galltrit no-appearing,
// the iron cobra no-appearing, the guardian familiar hit dice and xp reads
// corrected); the registry 938 -> 963, the ff def census 128 -> 153, the
// missing print census 57 -> 32 (the R842-pinned 57 stands; the independent
// recount makes 58 with the yellow urchin p. 92 - the drain is per def, so
// the arithmetic holds either way), no encounter cells rewire, no gap boxes
// flip; the def bodies carry the print-fidelity pin headers
//
namespace rules {

// ---- the sixth FF promotion batch ----

// the round
inline int ffkRound()
    { return 843; }

// the standing pace: defs per promotion round
inline int ffkDefsPerRound()
    { return 25; }

// the defs in the sixth FF promotion batch
inline int ffkBatchDefs()
    { return 25; }

// the garbug variant defs (the black and the violet)
inline int ffkGarbugDefs()
    { return 2; }

// the giant-kin defs (the fog, mountain and strider)
inline int ffkGiantDefs()
    { return 3; }

// the holdout defs (the twenty remaining)
inline int ffkHoldoutDefs()
    { return 20; }

// the first FF print page in the batch (the flind)
inline int ffkFirstPage()
    { return 39; }

// the last FF print page in the batch (the kuo-toa)
inline int ffkLastPage()
    { return 59; }

// the registry census before the batch
inline int ffkRegistryBefore()
    { return 938; }

// the registry census after the batch
inline int ffkRegistryAfter()
    { return 963; }

// the ff def census before the batch
inline int ffkFfDefsBefore()
    { return 128; }

// the ff def census after the batch
inline int ffkFfDefsAfter()
    { return 153; }

// the FF print stat-block census (the R841 verification count)
inline int ffkPrintStatBlocks()
    { return 185; }

// the FF print stat-blocks saved after the batch
inline int ffkPrintSaved()
    { return 153; }

// the missing FF print stat-block census before
inline int ffkPrintMissingBefore()
    { return 57; }

// the missing FF print stat-block census after
inline int ffkPrintMissingAfter()
    { return 32; }

// the defs lift from the ff print
inline bool ffkDefsFromFfPrint()
    { return true; }

// the stat blocks read from the three-voice scan collation (the djvu text,
// the word-geometry xml, the abbyy char xml)
inline bool ffkThreeVoiceRead()
    { return true; }

// the two-column variants promote as separate defs (the garbug black and
// violet)
inline bool ffkVariantDefsSplit()
    { return true; }

// the guardian familiar psionic rows stay unrecovered (both scan voices shred
// them; the query-mark sentinel rides the landed precedent)
inline bool ffkPsionicRowUnrecovered()
    { return true; }

// the source census rows stay put
inline bool ffkSourceRowsStay()
    { return true; }

// no gap boxes flip this round
inline bool ffkNoGapBoxesFlip()
    { return true; }

}   // namespace rules
