// =========================================================================================
// Adnd1 - rules/vmb.h
// the UA and WSG migration batch - the sixth batch, a clean hundred
// census 751 -> 752.
//
// spec-driven; the sixth batch of real audit blocks (digest idx 239-338, R357
// UA MU 2nd level spells through R458 WSG portaging - the UA pins and
// appendices, the WSG pins; 100 blocks at Curtiss's 100-per-round pace call,
// 18485 lines, zero blocks held back) move verbatim into rules/audits
// fragments, regtest keeps the one-line include at each head line; the census
// holds, the labels relocate; the round audit rides a fragment as before
//
namespace rules {

// ---- the UA and WSG batch ----

// the blocks in the UA and WSG batch
inline int vmb_batch()
    { return 100; }

// the lines the batch moves
inline int vmb_moving_lines()
    { return 18485; }

// the digest head line of R357 UA MU 2nd
inline int vmb_first_head()
    { return 32422; }

// the digest end line of R458 WSG portaging
inline int vmb_last_end()
    { return 50954; }

// the largest moving block - R395 treasure rows
inline int vmb_largest()
    { return 690; }

// the smallest moving block - R447 slippery
inline int vmb_smallest()
    { return 50; }

// this round audit rides a fragment
inline bool vmb_audit_rides()
    { return true; }

// the blocks move verbatim, never hand-authored
inline bool vmb_blocks_move()
    { return true; }

// the gates re-verify each block
inline bool vmb_gates_recheck()
    { return true; }

// the census survives the move
inline bool vmb_census_holds()
    { return true; }

}   // namespace rules
