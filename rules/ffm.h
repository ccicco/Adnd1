// =========================================================================================
// Adnd1 - rules/ffm.h
// the eighth FF promotion batch - the print walk closes
// census 767 -> 768.
//
// spec-driven; the eighth Fiend Folio promotion batch - the LAST SEVEN of the
// missing FF print stat-blocks lifted as new lua data files, the holdouts in
// ToC order from the yellow urchin p. 92 through the yellow musk pair p. 97
// (a 7-def SHORT BATCH: the R836 pace pin rests at 25 defs per round but the
// missing print census runs dry at 7 - the FF print walk CLOSES with this
// round, the missing print census 7 -> 0 and every one of the 185 FF print
// stat-blocks saved; the yellow urchin riding the R836 urchin family prose;
// the yellow musk creeper and zombie promoting as two defs; the vision
// carrying the dual AC row 0 (10) and the with 30' suggestion range recovered
// from the shredded scan row; the whipweed carrying its stalks/base stat rows
// as print strings; the xill riding the grapple/subdue/etherealness prose);
// the stat blocks read from the three-voice scan collation (the djvu text,
// the word-geometry xml, the abbyy char xml) with the 1eonline print
// transcripts recovering the shredded rows - the witherstench no-appearing
// reads 3-12 with the scan OCR garbling 1 as 7 systematically; the registry
// 988 -> 995, the ff def census 178 -> 185, the missing print census 7 -> 0,
// no encounter cells rewire, no gap boxes flip; the def bodies carry the
// print-fidelity pin headers
//
namespace rules {

// ---- the eighth FF promotion batch ----

// the round
inline int ffmRound()
    { return 845; }

// the standing pace: defs per promotion round
inline int ffmDefsPerRound()
    { return 25; }

// the defs in the eighth FF promotion batch (the short batch that closes the
// walk)
inline int ffmBatchDefs()
    { return 7; }

// the yellow musk pair defs (the creeper and the zombie)
inline int ffmMuskPairDefs()
    { return 2; }

// the yellow urchin def (riding the R836 urchin family prose)
inline int ffmUrchinDefs()
    { return 1; }

// the holdout defs (the vision, whipweed, witherstench and xill)
inline int ffmHoldoutDefs()
    { return 4; }

// the first FF print page in the batch (the yellow urchin)
inline int ffmFirstPage()
    { return 92; }

// the last FF print page in the batch (the yellow musk pair)
inline int ffmLastPage()
    { return 97; }

// the registry census before the batch
inline int ffmRegistryBefore()
    { return 988; }

// the registry census after the batch
inline int ffmRegistryAfter()
    { return 995; }

// the ff def census before the batch
inline int ffmFfDefsBefore()
    { return 178; }

// the ff def census after the batch
inline int ffmFfDefsAfter()
    { return 185; }

// the FF print stat-block census (the R841 verification count)
inline int ffmPrintStatBlocks()
    { return 185; }

// the FF print stat-blocks saved after the batch (the walk is closed)
inline int ffmPrintSaved()
    { return 185; }

// the missing FF print stat-block census before
inline int ffmPrintMissingBefore()
    { return 7; }

// the missing FF print stat-block census after (none left)
inline int ffmPrintMissingAfter()
    { return 0; }

// the defs lift from the ff print
inline bool ffmDefsFromFfPrint()
    { return true; }

// the stat blocks read from the three-voice scan collation (the djvu text,
// the word-geometry xml, the abbyy char xml)
inline bool ffmThreeVoiceRead()
    { return true; }

// the 7-def short batch closes the FF print walk - the pace pin rests at 25
// but the census runs dry
inline bool ffmShortBatchClosesWalk()
    { return true; }

// the two-column variants promote as separate defs (the yellow musk creeper
// and zombie; the yellow urchin rides the R836 family)
inline bool ffmVariantDefsSplit()
    { return true; }

// the source census rows stay put
inline bool ffmSourceRowsStay()
    { return true; }

// no gap boxes flip this round
inline bool ffmNoGapBoxesFlip()
    { return true; }

}   // namespace rules
