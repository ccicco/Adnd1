// =========================================================================================
// Adnd1 - rules/kmb.h
// the planes and OA migration batch - the eighth batch rides the same wiring
// census 753 -> 754.
//
// spec-driven; the eighth batch of real audit blocks (digest idx 441-549,
// R562 DSG intro frame through R671 OA wu jen second level spells - the DSG
// tail, the MotP planes, the DMO sections, the first OA ability, class,
// family, equipment, and spell pins; 100 blocks at Curtiss's 100-per-round
// pace call, 19285 lines) move verbatim into rules/audits fragments, regtest
// keeps the one-line include at each head line; the census holds, the labels
// relocate; the round audit rides a fragment as before
//
namespace rules {

// ---- the planes and OA batch ----

// the blocks in the planes and OA batch
inline int kmb_batch()
    { return 100; }

// the lines the batch moves
inline int kmb_moving_lines()
    { return 19285; }

// the digest head line of R562 DSG intro
inline int kmb_first_head()
    { return 74363; }

// the digest end line of R671 wu jen 2nd
inline int kmb_last_end()
    { return 107482; }

// the largest moving block - R615 OA abilities
inline int kmb_largest()
    { return 687; }

// the smallest moving block - R563 final census
inline int kmb_smallest()
    { return 16; }

// this round audit rides a fragment
inline bool kmb_audit_rides()
    { return true; }

// the blocks move verbatim, never hand-authored
inline bool kmb_blocks_move()
    { return true; }

// the gates re-verify each block
inline bool kmb_gates_recheck()
    { return true; }

// the census survives the move
inline bool kmb_census_holds()
    { return true; }

}   // namespace rules
