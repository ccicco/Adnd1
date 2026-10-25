// =========================================================================================
// Adnd1 - rules/jmb.h
// the OA tail migration batch - the ninth batch, a clean hundred
// census 754 -> 755.
//
// spec-driven; the ninth batch of real audit blocks (digest idx 550-649, R672
// OA wu jen third level spells through R771 OA open boxes - the OA spells,
// combat, calendar, monsters, treasure, armor and weapons, Kara-Tur, and
// daily-life pins; 100 blocks at Curtiss's 100-per-round pace call, 12737
// lines, zero blocks held back) move verbatim into rules/audits fragments,
// regtest keeps the one-line include at each head line; the census holds, the
// labels relocate; the round audit rides a fragment as before
//
namespace rules {

// ---- the OA tail batch ----

// the blocks in the OA tail batch
inline int jmb_batch()
    { return 100; }

// the lines the batch moves
inline int jmb_moving_lines()
    { return 12737; }

// the digest head line of R672 wu jen 3rd
inline int jmb_first_head()
    { return 107483; }

// the digest end line of R771 open boxes
inline int jmb_last_end()
    { return 120219; }

// the largest moving block - R720 Hu Hsien
inline int jmb_largest()
    { return 424; }

// the smallest moving block - R743 armor shield
inline int jmb_smallest()
    { return 35; }

// this round audit rides a fragment
inline bool jmb_audit_rides()
    { return true; }

// the blocks move verbatim, never hand-authored
inline bool jmb_blocks_move()
    { return true; }

// the gates re-verify each block
inline bool jmb_gates_recheck()
    { return true; }

// the census survives the move
inline bool jmb_census_holds()
    { return true; }

}   // namespace rules
