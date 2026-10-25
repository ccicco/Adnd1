// =========================================================================================
// Adnd1 - rules/afw.h
// THE AUDIT FILES DECOMPOSITION WIRING - the regtest monolith begins to come
// apart: the engine gains the audit_file spec key (a round's audit block
// rides a NEW fragment under rules/audits/, regtest gets the one-line
// #include at the R227 anchor), the census sums regtest.cpp plus the
// fragments, preflight reads the fragment printfs, and rn adds the fragment
// to the git add - the tooling round, lands alone, no gap boxes flip
// census 744 -> 745.
//
// Curtiss's Go call on the audit-files decomposition plan (2026-10-25): the
// thin-driver route, fragment headers first, same TU, same binary - the
// per-book migration rounds ride the wiring in later rounds, smallest first
//
// The R791 lesson binds: the engine can never consume its own extension in
// the run that patches it in - R822 lands its own audit inline, and the first
// audit-file round is the next one
//
namespace rules {

// ---- the R822 census ----

// The audit files decomposition wiring round (the regtest monolith begins to
// come apart)
inline int afwRound()
    { return 822; }

// The audit census before the round (the R821 landing closed at 744)
inline int afwCensusBefore()
    { return 744; }

// The audit census after the round (one audit added)
inline int afwCensusAfter()
    { return 745; }

// The regtest.cpp byte size at the 951b962 base sha - the monolith this round
// begins to decompose
inline int afwRegtestBytesAtBase()
    { return 5717896; }

// The four tool files the wiring touches: the engine, rverify, preflight, rn
inline int afwToolFilesPatched()
    { return 4; }

// ---- the wiring doctrine (the R822 census) ----

// A declared audit_file round writes its engine-emitted audit block to a NEW
// fragment under rules/audits/ - the same block, the same gates, only the
// file the compiler reads it from changes
inline bool afwFragmentCarriesAuditBlock()
    { return true; }

// regtest gets the one-line #include at the R227 audit anchor, inside the
// battery function body - the preprocessor unrolls it and the binary is
// unchanged
inline bool afwIncludeAtTheAnchor()
    { return true; }

// The engine census sums audit: bad over regtest.cpp PLUS rules/audits/*.h -
// a fragment label is never dropped
inline bool afwCensusCountsFragments()
    { return true; }

// The preflight battery census reads its printf patterns from regtest.cpp
// plus the fragments, so a fragment audit is covered exactly as before
inline bool afwPreflightReadsFragments()
    { return true; }

// rn derives the audit_file from the spec and adds it to the git add (the
// R793 untracked-defs lesson)
inline bool afwRnAddsTheFragment()
    { return true; }

// An audit-file round counts the fragment and the include as two applied
// items in rverify (3 + 2 instead of 3 + 1)
inline bool afwRverifyCountsTwo()
    { return true; }

// The R791 lesson: tooling lands alone, the content rides the extension in a
// later round
inline bool afwToolingLandsAlone()
    { return true; }

// R822 itself lands its own audit the pre-R822 way - the engine can never
// consume its own extension in the run that patches it in
inline bool afwR822LandsOldWay()
    { return true; }

// The fragment is emitted by the engine from the spec, never hand-authored -
// the R515/R608 delivery lessons bind the fragment exactly like a header
inline bool afwFragmentEngineEmitted()
    { return true; }

// The per-book migration rounds ride after the wiring, smallest-first,
// Curtiss's call each round
inline bool afwMigrationFollows()
    { return true; }

// ---- the patch arithmetic (the R822 census) ----

// The engine file patches: the audit_file branch and the fragment census
inline int afwEnginePatches()
    { return 2; }

// The rverify file patches: the restore list and the n_patches count
inline int afwRverifyPatches()
    { return 2; }

// The preflight file patches: the census comment and the pattern source
inline int afwPreflightPatches()
    { return 2; }

// The rn file patches: the audit_file fact, the echo, the git add
inline int afwRnPatches()
    { return 3; }

// The nine file patches the round rides
inline int afwFilePatchesTotal()
    { return 9; }

}   // namespace rules
