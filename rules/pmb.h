// =========================================================================================
// Adnd1 - rules/pmb.h
// the pilot migration round - the first real blocks leave regtest
// census 746 -> 747.
//
// spec-driven; the first 18 real audit blocks (R79-R97, 784 lines) move
// verbatim into rules/audits fragments, regtest keeps the one-line include at
// each head line; the census holds, the labels relocate; this round audit
// rides a fragment - the first real use of the R822 wiring
//
namespace rules {

// ---- the pilot batch ----

// the blocks in the pilot batch
inline int pmb_batch()
    { return 18; }

// the digest head line of R79
inline int pmb_first_head()
    { return 967; }

// the digest end line of R97
inline int pmb_last_end()
    { return 1825; }

// the lines the pilot batch moves
inline int pmb_moving_lines()
    { return 784; }

// the smallest moving block - R91 stairs
inline int pmb_smallest()
    { return 16; }

// the largest moving block - R87 burden
inline int pmb_largest()
    { return 84; }

// this round audit rides a fragment
inline bool pmb_audit_rides()
    { return true; }

// the blocks move verbatim, never hand-authored
inline bool pmb_blocks_move()
    { return true; }

// the migration gates re-verify each block before it moves
inline bool pmb_gates_recheck()
    { return true; }

// the census survives the move - the labels relocate
inline bool pmb_census_holds()
    { return true; }

}   // namespace rules
