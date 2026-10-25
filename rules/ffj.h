// =========================================================================================
// Adnd1 - rules/ffj.h
// the fifth FF promotion batch - the missing prints open
// census 764 -> 765.
//
// spec-driven; the fifth Fiend Folio promotion batch - twenty-five of the
// eighty-two missing FF print stat-blocks lifted as new lua data files (the
// three lung dragons - the pan lung p. 29, the tien lung p. 29, the yu lung
// p. 30; the five elemental princes of evil - cryonax p. 31, imix p. 31,
// ogremoch p. 32, olhydra p. 32, yan-c-bin p. 33; and seventeen holdouts from
// the giant bloodworm p. 15 to the flail snail p. 38), the stat blocks read
// from the three-voice scan collation (the djvu text, the word-geometry xml,
// the abbyy char xml) with the shredded dark stalker rows recovered from the
// print transcriptions, the registry 913 -> 938, the ff def census 103 ->
// 128, the missing print census 82 -> 57, no encounter cells rewire, no gap
// boxes flip; the def bodies carry the print-fidelity pin headers
//
namespace rules {

// ---- the fifth FF promotion batch ----

// the round
inline int ffjRound()
    { return 842; }

// the standing pace: defs per promotion round
inline int ffjDefsPerRound()
    { return 25; }

// the defs in the fifth FF promotion batch
inline int ffjBatchDefs()
    { return 25; }

// the lung dragon defs (the pan, tien and yu lungs)
inline int ffjLungDefs()
    { return 3; }

// the elemental prince defs (the cold, fire, earth, water and air princes)
inline int ffjPrinceDefs()
    { return 5; }

// the holdout defs (the seventeen remaining)
inline int ffjHoldoutDefs()
    { return 17; }

// the first FF print page in the batch (the giant bloodworm)
inline int ffjFirstPage()
    { return 15; }

// the last FF print page in the batch (the flail snail)
inline int ffjLastPage()
    { return 38; }

// the registry census before the batch
inline int ffjRegistryBefore()
    { return 913; }

// the registry census after the batch
inline int ffjRegistryAfter()
    { return 938; }

// the ff def census before the batch
inline int ffjFfDefsBefore()
    { return 103; }

// the ff def census after the batch
inline int ffjFfDefsAfter()
    { return 128; }

// the FF print stat-block census (the R841 verification count)
inline int ffjPrintStatBlocks()
    { return 185; }

// the FF print stat-blocks saved after the batch
inline int ffjPrintSaved()
    { return 128; }

// the missing FF print stat-block census before
inline int ffjPrintMissingBefore()
    { return 82; }

// the missing FF print stat-block census after
inline int ffjPrintMissingAfter()
    { return 57; }

// the defs lift from the ff print
inline bool ffjDefsFromFfPrint()
    { return true; }

// the stat blocks read from the three-voice scan collation (the djvu text,
// the word-geometry xml, the abbyy char xml)
inline bool ffjThreeVoiceRead()
    { return true; }

// the shredded dark stalker rows recovered from the print transcriptions
inline bool ffjShreddedRowsRecovered()
    { return true; }

// the source census rows stay put
inline bool ffjSourceRowsStay()
    { return true; }

// no gap boxes flip this round
inline bool ffjNoGapBoxesFlip()
    { return true; }

}   // namespace rules
