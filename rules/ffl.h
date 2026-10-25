// =========================================================================================
// Adnd1 - rules/ffl.h
// the seventh FF promotion batch - the missing prints walk on
// census 766 -> 767.
//
// spec-driven; the seventh Fiend Folio promotion batch - twenty-five of the
// thirty-two missing FF print stat-blocks lifted as new lua data files, the
// holdouts in ToC order from the lamia noble p. 59 through the umpleby p. 92
// (the lava, smoke and steam mephits promoting as three defs, the two-column
// variant precedent, riding the print family prose; the giant troll, the
// giant two-headed troll and the spirit troll carrying their own sections
// only per the landed ice troll precedent; the two slaad lords Ssendam and
// Ygorl promoting as unique defs per the imix precedent, the protein
// polymorph under its print heading NOT the protean); the stat blocks read
// from the three-voice scan collation (the djvu text, the word-geometry xml,
// the abbyy char xml) with the 1eonline print transcripts recovering the
// shredded rows - the qullan magic resistance row is BLANK in the print and
// both scan voices and rides the query-mark sentinel per the landed
// precedent; the protein polymorph treasure type reads zero in both scan
// voices and stands; the needleman no-appearing reads 5-50 in both scan
// voices over the transcript 5-20 and stands; the nilbog lair treasure reads
// G in both scans over the transcript C; the retriever lair percentage reads
// 70 in both scans over the transcript 10; the umpleby size reads 8' + tail
// in both scans; the scan OCRs 1 as 7 systematically; the registry 963 ->
// 988, the ff def census 153 -> 178, the missing print census 32 -> 7, no
// encounter cells rewire, no gap boxes flip; the def bodies carry the
// print-fidelity pin headers
//
namespace rules {

// ---- the seventh FF promotion batch ----

// the round
inline int fflRound()
    { return 844; }

// the standing pace: defs per promotion round
inline int fflDefsPerRound()
    { return 25; }

// the defs in the seventh FF promotion batch
inline int fflBatchDefs()
    { return 25; }

// the mephit variant defs (the lava, smoke and steam)
inline int fflMephitDefs()
    { return 3; }

// the troll defs (the giant, the giant two-headed and the spirit)
inline int fflTrollDefs()
    { return 3; }

// the slaad lord defs (Ssendam and Ygorl)
inline int fflSlaadLordDefs()
    { return 2; }

// the holdout defs (the remaining seventeen)
inline int fflHoldoutDefs()
    { return 17; }

// the first FF print page in the batch (the lamia noble)
inline int fflFirstPage()
    { return 59; }

// the last FF print page in the batch (the umpleby)
inline int fflLastPage()
    { return 92; }

// the registry census before the batch
inline int fflRegistryBefore()
    { return 963; }

// the registry census after the batch
inline int fflRegistryAfter()
    { return 988; }

// the ff def census before the batch
inline int fflFfDefsBefore()
    { return 153; }

// the ff def census after the batch
inline int fflFfDefsAfter()
    { return 178; }

// the FF print stat-block census (the R841 verification count)
inline int fflPrintStatBlocks()
    { return 185; }

// the FF print stat-blocks saved after the batch
inline int fflPrintSaved()
    { return 178; }

// the missing FF print stat-block census before
inline int fflPrintMissingBefore()
    { return 32; }

// the missing FF print stat-block census after
inline int fflPrintMissingAfter()
    { return 7; }

// the defs lift from the ff print
inline bool fflDefsFromFfPrint()
    { return true; }

// the stat blocks read from the three-voice scan collation (the djvu text,
// the word-geometry xml, the abbyy char xml)
inline bool fflThreeVoiceRead()
    { return true; }

// the two-column variants promote as separate defs (the lava, smoke and steam
// mephits)
inline bool fflVariantDefsSplit()
    { return true; }

// the qullan magic resistance row is blank in the print and both scan voices
// - the query-mark sentinel rides the landed precedent
inline bool fflMagicResistanceRowBlank()
    { return true; }

// the protein polymorph treasure type row reads zero in both scan voices -
// the print value stands
inline bool fflTreasureTypeZero()
    { return true; }

// the source census rows stay put
inline bool fflSourceRowsStay()
    { return true; }

// no gap boxes flip this round
inline bool fflNoGapBoxesFlip()
    { return true; }

}   // namespace rules
