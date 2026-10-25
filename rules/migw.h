// =========================================================================================
// Adnd1 - rules/migw.h
// the audit blocks migration wiring - the tooling round of the regtest
// decomposition arc
// census 745 -> 746.
//
// spec-driven; the engine gains the migrate_blocks key - a declared block
// leaves regtest verbatim for a rules/audits fragment, regtest keeps the
// one-line include at its head line; the census holds, the label relocates;
// rverify counts the moves, rn git-adds the fragments
//
namespace rules {

// ---- the migration wiring ----

// the fragments per pilot migration round
inline int migw_frag_gap()
    { return 3; }

// the max upward walk from a label to its head
inline int migw_head_walk()
    { return 800; }

// the line-width gate for the moving blocks
inline int migw_width()
    { return 78; }

// the census after this round lands its own audit
inline int migw_census()
    { return 746; }

// the blocks standing before this round
inline int migw_blocks_total()
    { return 745; }

// the floor on a migration batch
inline int migw_min_blocks()
    { return 1; }

// the include indent inside the battery body
inline int migw_anchor_pad()
    { return 4; }

// the bad markers a moving block must carry
inline int migw_bad_marker()
    { return 1; }

// the brace delta a moving block must show
inline int migw_brace_delta()
    { return 0; }

// the audit label length this round
inline int migw_label_len()
    { return 33; }

// the fragment path must sit under rules/audits
inline bool migw_frag_required()
    { return true; }

// the block moves byte for byte
inline bool migw_verbatim()
    { return true; }

// a moving block never carries a bare return 0
inline bool migw_no_bare_return()
    { return true; }

// the one-line include lands at the head line
inline bool migw_include_inline()
    { return true; }

// the total census survives the move
inline bool migw_census_holds()
    { return true; }

// the migration gates re-verify each block
inline bool migw_gates_recheck()
    { return true; }

// the writes list keeps the final regtest
inline bool migw_last_wins()
    { return true; }

// the ritual git-adds the fragments
inline bool migw_rn_adds()
    { return true; }

// the harness census counts the migrations
inline bool migw_rverify_counts()
    { return true; }

// tooling lands alone - the R791 lesson
inline bool migw_tooling_alone()
    { return true; }

}   // namespace rules
