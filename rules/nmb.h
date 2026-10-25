// =========================================================================================
// Adnd1 - rules/nmb.h
// the DMG appendix migration batch - the second batch of blocks leaves
// regtest
// census 747 -> 748.
//
// spec-driven; the next 18 real audit blocks (R114-R131, 1700 lines - the DMG
// appendix audits) move verbatim into rules/audits fragments, regtest keeps
// the one-line include at each head line; the census holds, the labels
// relocate; the round audit rides a fragment as before
//
namespace rules {

// ---- the DMG appendix batch ----

// the blocks in the DMG appendix batch
inline int nmb_batch()
    { return 18; }

// the lines the batch moves
inline int nmb_moving_lines()
    { return 1700; }

// the digest head line of R114 aging
inline int nmb_first_head()
    { return 1826; }

// the digest end line of R131 plumbing
inline int nmb_last_end()
    { return 3568; }

// the largest moving block - R124 appendix A dressing
inline int nmb_largest()
    { return 517; }

// the smallest moving blocks - R115 gate and R119 rest
inline int nmb_smallest()
    { return 18; }

// this round audit rides a fragment
inline bool nmb_audit_rides()
    { return true; }

// the blocks move verbatim, never hand-authored
inline bool nmb_blocks_move()
    { return true; }

// the migration gates re-verify each block before it moves
inline bool nmb_gates_recheck()
    { return true; }

// the census survives the move - the labels relocate
inline bool nmb_census_holds()
    { return true; }

}   // namespace rules
