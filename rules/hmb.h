// =========================================================================================
// Adnd1 - rules/hmb.h
// the holdback tooling patch - the second tooling round of the regtest
// decomposition arc
// census 756 -> 757.
//
// spec-driven; the engine head walk widens 800 to 4000 so the sixteen no-head
// blocks (the WSG weather pair, the DMO family, the MM2 letter walks - heads
// 823 to 2325 lines above their labels) find their heads, and the migrate key
// gains a per-block allow_wide tolerance so the thirty-one width-family
// blocks (77 wide code lines, 79 to 159 cols; regtest itself runs to 305)
// move verbatim instead of split; the 78-col default stands for every
// undeclared block; no block moves this round - the tooling lands alone, the
// final 55-block batch closes the arc
//
namespace rules {

// ---- the holdback tooling ----

// the widened upward walk from a label to its head
inline int hmb_head_walk()
    { return 4000; }

// the prior head-walk bound
inline int hmb_walk_old()
    { return 800; }

// the largest label-to-head distance in the no-head family
inline int hmb_walk_farthest()
    { return 2325; }

// the no-head family: the WSG weather pair, the DMO family, the MM2 letters
inline int hmb_no_head()
    { return 16; }

// the width family held back by the 78-col gate
inline int hmb_width_family()
    { return 31; }

// the family that needs no tooling at all
inline int hmb_ready_now()
    { return 8; }

// the total holdback blocks awaiting the final batch
inline int hmb_holdbacks()
    { return 55; }

// the wide code lines the width family carries
inline int hmb_wide_lines()
    { return 77; }

// the widest moving line, in columns
inline int hmb_wide_max()
    { return 159; }

// the census after this round audit rides its fragment
inline int hmb_census()
    { return 757; }

// the per-block wide tolerance rides the migrate key
inline bool hmb_allow_wide()
    { return true; }

// the 78-col gate stands for every undeclared block
inline bool hmb_default_width()
    { return true; }

// the wide lines move byte for byte, never split
inline bool hmb_verbatim()
    { return true; }

// the head walk goes only up from the label
inline bool hmb_walk_upward()
    { return true; }

// the one-marker, bare-return and brace gates stand unchanged
inline bool hmb_gates_hold()
    { return true; }

// no block moves in the tooling round
inline bool hmb_tooling_alone()
    { return true; }

// this round audit rides a fragment
inline bool hmb_audit_rides()
    { return true; }

// the wiring audit stays put by design
inline bool hmb_wiring_kept()
    { return true; }

// the census survives the final move
inline bool hmb_census_holds()
    { return true; }

// the final 55-block batch closes the decomposition arc
inline bool hmb_arc_closes()
    { return true; }

}   // namespace rules
