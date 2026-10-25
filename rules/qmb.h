// =========================================================================================
// Adnd1 - rules/qmb.h
// the subclass migration batch - the fourth batch leaves regtest at fifty
// blocks
// census 749 -> 750.
//
// spec-driven; the fourth batch of real audit blocks (digest idx 54-119, R179
// subclass registry through R245 staves prose, 50 blocks at Curtiss's
// 50-per-round pace call, 5111 lines - the subclass seams and engines, the
// class audits, the DMG magic item pins) move verbatim into rules/audits
// fragments, regtest keeps the one-line include at each head line; the census
// holds, the labels relocate; the round audit rides a fragment as before
//
namespace rules {

// ---- the subclass batch ----

// the blocks in the subclass batch
inline int qmb_batch()
    { return 50; }

// the lines the batch moves
inline int qmb_moving_lines()
    { return 5111; }

// the digest head line of R179 subclass registry
inline int qmb_first_head()
    { return 5482; }

// the digest end line of R245 staves prose
inline int qmb_last_end()
    { return 12797; }

// the largest moving block - R186 the bard
inline int qmb_largest()
    { return 320; }

// the smallest moving block - R234a dual-class seam
inline int qmb_smallest()
    { return 30; }

// this round audit rides a fragment
inline bool qmb_audit_rides()
    { return true; }

// the blocks move verbatim, never hand-authored
inline bool qmb_blocks_move()
    { return true; }

// the migration gates re-verify each block before it moves
inline bool qmb_gates_recheck()
    { return true; }

// the census survives the move - the labels relocate
inline bool qmb_census_holds()
    { return true; }

}   // namespace rules
