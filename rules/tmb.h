// =========================================================================================
// Adnd1 - rules/tmb.h
// the DMG tables migration batch - the third batch of blocks leaves regtest
// census 748 -> 749.
//
// spec-driven; the third 18 real audit blocks (R147 x3 through R178c, 1938
// lines - the DMG tables and appendix audits) move verbatim into rules/audits
// fragments, regtest keeps the one-line include at each head line; the census
// holds, the labels relocate; the round audit rides a fragment as before
//
namespace rules {

// ---- the DMG tables batch ----

// the blocks in the DMG tables batch
inline int tmb_batch()
    { return 18; }

// the lines the batch moves
inline int tmb_moving_lines()
    { return 1938; }

// the digest head line of R147 dwarf CON save
inline int tmb_first_head()
    { return 3544; }

// the digest end line of R178c tables
inline int tmb_last_end()
    { return 5481; }

// the largest moving block - R160 weaponless combat
inline int tmb_largest()
    { return 303; }

// the smallest moving block - R147 dwarf CON save
inline int tmb_smallest()
    { return 25; }

// this round audit rides a fragment
inline bool tmb_audit_rides()
    { return true; }

// the blocks move verbatim, never hand-authored
inline bool tmb_blocks_move()
    { return true; }

// the migration gates re-verify each block before it moves
inline bool tmb_gates_recheck()
    { return true; }

// the census survives the move - the labels relocate
inline bool tmb_census_holds()
    { return true; }

}   // namespace rules
