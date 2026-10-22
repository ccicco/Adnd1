// =========================================================================================
// Adnd1 - rules/rtseam.h
// THE RT SEAM FIX - regtest.cpp file patches ride the in-memory engine text;
// the seam upgrades the engine through the ritual itself
// census 697 -> 698.
//
// The R774 seam read every file patch target from disk. regtest.cpp is the
// one target the engine also patches in memory (the include and the audit
// block, writes deferred to the end), so the R776 site round - whose R403
// charge flips are regtest file patches - would have clobbered them with the
// pristine disk copy. The fix is a file patch on tools/splice_engine.py: when
// the target is RT, the patch reads the in-memory text instead. The patch
// lands through the ritual, closing the R774 bootstrap note: the running old
// engine applies it to its own source on disk, the second run of the
// double-run executes the new engine, and ./rn git-adds the tool via the spec
// the usual way. The mount site itself is R776.
//
// No book pages this round either: the provenance is the clobber class the
// site design exposed.
//
namespace rules {

// ---- the RT seam fix (the R775 tooling) ----

// The first round a tool file lands through the ritual itself - the spec file
// patch rides tools/splice_engine.py.
inline int dnbSelfPatchedToolRound()
    { return 775; }

// The mounted-combat site lands R776 - one round later than the R774 record
// hoped, because the regtest charge flips needed this fix first.
inline int dnbMountSiteRound()
    { return 776; }

// A regtest.cpp file patch reads the in-memory engine text (include and audit
// included), never the pristine disk copy.
inline bool dnbRegtestPatchesRideInMemory()
    { return true; }

// The clobber class - the last RT write losing the include and the audit to a
// stale read - dies by the fix.
inline bool dnbClobberClassDead()
    { return true; }

// A tool file lands as a spec file patch: the engine applies it, the
// double-run re-executes the new source, ./rn git-adds it - no hand-save, no
// manual tool commit.
inline bool dnbToolsLandThroughTheRitual()
    { return true; }

}   // namespace rules
