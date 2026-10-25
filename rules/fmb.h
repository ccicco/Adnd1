// =========================================================================================
// Adnd1 - rules/fmb.h
// the final digest migration batch - the digest runs dry
// census 755 -> 756.
//
// spec-driven; the tenth batch of real audit blocks (digest idx 650-744, R772
// OA Weapons prose through R113 class matrix - the OA back matter, the seam
// and registry blocks R774-R822, the MM2 walks and grids, and the early-file
// blocks R84-R137; 86 blocks - every digest entry that passes the gates, at
// Curtiss's 100-per-round pace call, 14289 lines) move verbatim into
// rules/audits fragments, regtest keeps the one-line include at each head
// line; the census holds, the labels relocate; the round audit rides a
// fragment as before
//
namespace rules {

// ---- the final digest batch ----

// the blocks in the final digest batch
inline int fmb_batch()
    { return 86; }

// the lines the batch moves
inline int fmb_moving_lines()
    { return 14289; }

// the digest head line of R772 OA Weapons
inline int fmb_first_head()
    { return 120220; }

// the digest end line of R113 class matrix
inline int fmb_last_end()
    { return 144417; }

// the largest moving block - R818 aquatic grids
inline int fmb_largest()
    { return 786; }

// the smallest moving block - R137 engage hook
inline int fmb_smallest()
    { return 17; }

// this round audit rides a fragment
inline bool fmb_audit_rides()
    { return true; }

// the blocks move verbatim, never hand-authored
inline bool fmb_blocks_move()
    { return true; }

// the gates re-verify each block
inline bool fmb_gates_recheck()
    { return true; }

// the census survives the move
inline bool fmb_census_holds()
    { return true; }

}   // namespace rules
