// =========================================================================================
// Adnd1 - rules/zmb.h
// the hundred-block migration batch - the pace call doubles to a hundred
// blocks
// census 750 -> 751.
//
// spec-driven; the fifth batch of real audit blocks (digest idx 120-238, R246
// wands prose through R356 UA MU 1st level spells - the DMG magic items and
// artifacts pins, the underwater and seam engines, the first UA pins; 100
// blocks at Curtiss's 100-per-round pace call, 17574 lines) move verbatim
// into rules/audits fragments, regtest keeps the one-line include at each
// head line; the census holds, the labels relocate; the round audit rides a
// fragment as before
//
namespace rules {

// ---- the hundred batch ----

// the blocks in the hundred batch
inline int zmb_batch()
    { return 100; }

// the lines the batch moves
inline int zmb_moving_lines()
    { return 17574; }

// the digest head line of R246 wands prose
inline int zmb_first_head()
    { return 12798; }

// the digest end line of R356 UA MU 1st spells
inline int zmb_last_end()
    { return 32421; }

// the largest moving block - R324 subrace limits
inline int zmb_largest()
    { return 641; }

// the smallest moving block - R313a fight seam
inline int zmb_smallest()
    { return 43; }

// this round audit rides a fragment
inline bool zmb_audit_rides()
    { return true; }

// the blocks move verbatim, never hand-authored
inline bool zmb_blocks_move()
    { return true; }

// the gates re-verify each block
inline bool zmb_gates_recheck()
    { return true; }

// the census survives the move
inline bool zmb_census_holds()
    { return true; }

}   // namespace rules
