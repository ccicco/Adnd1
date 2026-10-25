// =========================================================================================
// Adnd1 - rules/xmb.h
// the WSG tail and DSG migration batch - the seventh batch rides the same
// wiring
// census 752 -> 753.
//
// spec-driven; the seventh batch of real audit blocks (digest idx 339-440,
// R459 WSG capsized use through R561 DSG DM section - the WSG tail pins, the
// DSG surface and Deepearth and campaign pins; 100 blocks at Curtiss's
// 100-per-round pace call, 19526 lines) move verbatim into rules/audits
// fragments, regtest keeps the one-line include at each head line; the census
// holds, the labels relocate; the round audit rides a fragment as before
//
namespace rules {

// ---- the WSG tail and DSG batch ----

// the blocks in the WSG tail and DSG batch
inline int xmb_batch()
    { return 100; }

// the lines the batch moves
inline int xmb_moving_lines()
    { return 19526; }

// the digest head line of R459 capsized use
inline int xmb_first_head()
    { return 50955; }

// the digest end line of R561 DSG DM
inline int xmb_last_end()
    { return 74362; }

// the largest moving block - R504 DSG movement I
inline int xmb_largest()
    { return 763; }

// the smallest moving block - R549 Deepearth closed
inline int xmb_smallest()
    { return 14; }

// this round audit rides a fragment
inline bool xmb_audit_rides()
    { return true; }

// the blocks move verbatim, never hand-authored
inline bool xmb_blocks_move()
    { return true; }

// the gates re-verify each block
inline bool xmb_gates_recheck()
    { return true; }

// the census survives the move
inline bool xmb_census_holds()
    { return true; }

}   // namespace rules
