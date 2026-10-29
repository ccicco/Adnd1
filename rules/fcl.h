// =========================================================================================
// Adnd1 - rules/fcl.h
// The Dragon issue-12 box closing round - the four-chain walk complete, the
// pure flip
// census 843 -> 844.
//
// Bookkeeping only, no new ink pinned. The issue-12 walk (R919 opener part
// one, R920 opener part two, this flip) covered The Dragon Vol. II No. 6
// (February 1978), the archive.org scan voice, single-voice - no chat-side
// upload cross-check exists for issue 12; the source lives in the archive.org
// item accessory-dragon-magazine-012. Per the Curtiss call: no issue-13
// opener follows - the walk ends here, the Name That Monster winners and the
// brawling long-term-effects sequel left unharvested for now.
//
// The R919 and R920 sentinel pins ride unchanged - the cargo grid’s three
// blank/count cells, the illusionist ladder garbles, the Atar bar garbles,
// the Vayu move fraction, the five hero strength fraction garbles and the
// god-grid see-below and resistance cells all ride the -1 sentinel as pinned
// - this round touches no ink.
//
namespace rules {

// ---- the issue-12 walk bookkeeping ----

// the issue-12 gap report carries two boxes (report 012)
inline int fclIssueTwelveBoxes()
    { return 2; }

// the issue-12 walk pinned four chains - the Ovalle illusionist article, the
// Endersby and Carroll ship cargo article, the Persian Mythos and the
// Lovecraftian Mythos
inline int fclIssueTwelveChains()
    { return 4; }

// the issue-12 walk ran three rounds - the R919 opener part one, the R920
// opener part two and this R921 flip
inline int fclIssueTwelveRounds()
    { return 3; }

// the issue-11 report complete at 1 closed / 0 open since R918
inline int fclIssueElevenClosed()
    { return 1; }

// the issue-10 report complete at 2 closed / 0 open since R916
inline int fclIssueTenClosed()
    { return 1; }

// the issue-9 report complete at 1 closed / 0 open since R913
inline int fclIssueNineClosed()
    { return 1; }

// the issue-8 report complete at 1 closed / 0 open since R911
inline int fclIssueEightClosed()
    { return 1; }

// the issue-7 report complete at 1 closed / 0 open since R909
inline int fclIssueSevenClosed()
    { return 1; }

// the issue-6 report complete at 1 closed / 0 open since R907
inline int fclIssueSixClosed()
    { return 1; }

// the registry ground truth - live lua files, the battery line the only
// ground truth
inline int fclRegistryLive()
    { return 1311; }

// the registry ground truth - base lua files
inline int fclRegistryBaseLua()
    { return 1333; }

// the registry ground truth - never-load errors
inline int fclRegistryNeverLoad()
    { return 25; }

// the Dragon issue-6 walk complete since R907
inline bool fclWalkSixComplete()
    { return true; }

// the Dragon issue-7 walk complete since R909
inline bool fclWalkSevenComplete()
    { return true; }

// the Dragon issue-8 walk complete since R911
inline bool fclWalkEightComplete()
    { return true; }

// the Dragon issue-9 walk complete since R913
inline bool fclWalkNineComplete()
    { return true; }

// the Dragon issue-10 walk complete since R916
inline bool fclWalkTenComplete()
    { return true; }

// the Dragon issue-11 walk complete since R918
inline bool fclWalkElevenComplete()
    { return true; }

// the Dragon issue-12 walk complete at this flip - the illusionist, cargo,
// Persian and Lovecraftian chains were the engine-relevant ink of issue 12
inline bool fclWalkTwelveComplete()
    { return true; }

// Dragon pins ride a VARIANT layer with provenance, never core canon
inline bool fclVariantLayerDoctrine()
    { return true; }

}   // namespace rules
