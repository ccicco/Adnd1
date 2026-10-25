// =========================================================================================
// Adnd1 - rules/ymb.h
// the final holdback batch - the decomposition arc closes
// census 757 -> 758.
//
// spec-driven; the last 55 holdback blocks leave regtest - the 8 ready-now
// blocks, the 16 no-head blocks (the WSG weather pair, the DMO family, the
// MM2 letter walks - heads 823 to 2325 lines above their labels, found by the
// R834 widened walk), and the 31 width-family blocks riding the per-block
// allow_wide tolerance (77 wide code lines, up to 159 cols) - all moving
// verbatim into rules/audits fragments, regtest keeping the one-line include
// at each head line; the census holds, the labels relocate; the wiring audit
// stays put by design; the arc closes: one wiring audit remains inline, 757
// blocks live in fragments
//
namespace rules {

// ---- the final holdback batch ----

// the blocks in the final holdback batch
inline int ymb_batch()
    { return 55; }

// the lines the batch moves
inline int ymb_moving_lines()
    { return 29060; }

// the head line of R180 qualification and race gates
inline int ymb_first_head()
    { return 1091; }

// the end line of R172 appendix J herbs
inline int ymb_last_end()
    { return 33604; }

// the largest block: R494 WSG weather effects
inline int ymb_largest()
    { return 2434; }

// the smallest block: R194 wisdom defense repin
inline int ymb_smallest()
    { return 38; }

// this round audit rides a fragment
inline bool ymb_audit_rides()
    { return true; }

// the blocks move verbatim, never hand-authored
inline bool ymb_blocks_move()
    { return true; }

// the gates re-verify each block
inline bool ymb_gates_recheck()
    { return true; }

// the decomposition arc closes with this batch
inline bool ymb_arc_closes()
    { return true; }

}   // namespace rules
