// =========================================================================================
// Adnd1 - rules/filepatchseam.h
// THE FILE-PATCH SEAM - the ritual tooling extension: the spec-declared
// extra-file patches
// census 696 -> 697.
//
// The R775 mounted-combat engine site (the last ungated UA deferred item)
// touches game/party.h and game/state_combat.cpp, and the R403 charge
// conditions in regtest must flip with the site - none of them land through
// the ritual as it stood. This round extends the engine (the file_patches
// spec key, gap-flip semantics: byte-exact anchors, one replace, idempotent,
// counted in the applied/already census), rverify (restore + count the patch
// targets at the base sha), and ./rn (the extra git-add paths derived from
// the spec). The three tools land by hand this once (the bootstrap note): the
// tool files cannot patch themselves; after R774 every file-patch round lands
// through the ritual like any other. The demo patch is comment-only in
// rules/mountlayer.h - the charge stays open until the site lands R775.
//
// No book pages this round: the provenance is the tooling itself (the R428
// one-command-harness precedent).
//
namespace rules {

// ---- the file-patch seam (the R774 tooling) ----

// The three tools the seam extends: rn, tools/splice_engine.py, and
// tools/rverify.py - the git add, the patch applier, and the restore/count
// gate.
inline int dnlPatchedToolCount()
    { return 3; }

// R774 is the first round carrying the file_patches spec key - the demo patch
// rides rules/mountlayer.h.
inline int dnlFirstFilePatchRound()
    { return 774; }

// The first engine site through the seam: the mounted-combat site lands R775
// on game/party.h and game/state_combat.cpp.
inline int dnlMountSiteRound()
    { return 775; }

// The spec key file_patches is a list of {file, note, from, to} - the round
// declares its extra-file patches, exactly like gap_flips.
inline bool dnlFilePatchesSpecDeclared()
    { return true; }

// The from anchor is byte-exact and must occur; a missing anchor dies before
// any write (the all-or-nothing rule).
inline bool dnlFilePatchAnchorByteExact()
    { return true; }

// Each file patch counts in the applied/already census - the double-run gate
// covers them exactly like gap flips.
inline bool dnlFilePatchesCountedAsPatches()
    { return true; }

// ./rn derives the extra git-add paths from the spec and commits them with
// the round.
inline bool dnlFilePatchesGoInTheGitAdd()
    { return true; }

// The mountlayer charge comment now notes the R775 site seam (the R774 demo
// patch, comment-only).
inline bool dnlMountlayerSeamNotesR775()
    { return true; }

}   // namespace rules
