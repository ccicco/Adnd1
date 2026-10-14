// =========================================================================================
// Adnd1 - rules/wsgjump.h
// The WSG JUMPING, R448: the jumping prose and TABLE 22 CHARACTERS' JUMPING
// ABILITY with the p. 40 modifiers - thief-acrobats and barbarians are
// particularly skilled in jumping, but ANY character can make a broad jump or
// a high jump. On the average a running broad jump covers FOUR more feet than
// a standing one, but it requires a 20-foot run in a straight line toward the
// obstacle immediately before leaping; without that space or the time to
// start the run, the standing jump is the best he can do. A high jump covers
// HALF as much distance horizontally as its height; a flat surface higher
// than the current elevation is landed on with a roll to absorb the impact; a
// thin barrier with level ground on the far side demands a successful high
// jump AND a Dexterity Check - failure lands him in a heap (1d3 damage for a
// jump of five feet or higher) and he needs the next round to stand up. The
// die is rolled for EACH jump attempt (a 4th-level character clears a 3-foot
// high jump only on a 1d3 roll of 3). Table 22: the seven level bands 1-6
// through 23+ with the standing broad (1d4+1 to 1d6+6), the running broad
// (1d4+5 to 1d6+15) and the high jump (1d3 to 1d6+1). Modifiers, cumulative:
// moderately encumbered -1 foot; heavily encumbered -2 feet and cannot high
// jump; severely encumbered cannot jump at all; halfling -1 foot on broad
// jumps only; gnome or dwarf -2 feet broad and -1 foot high - with floors of
// 2 feet broad and 1 foot high. Census 372 -> 373.
// census 372 -> 373.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 39-40;
// the user own copy OCR (pages 40-41) cross-checked against the archive djvu
// word layer (Guide_0039.djvu with the Guide_0040.djvu head) - the prose
// reads CLEAN two-way, every number (the four-foot advantage, the 20-foot
// run, the half-height high jump, the 1d3 five-foot heap damage, the modifier
// feet and the 2/1 floors) matched exactly; the Table 22 grid is GARBLED in
// the djvu word layer, so every cell was confirmed by TWO independent IIIF
// eye-reads of leaf 39 - the OCR and both eye-reads agree on all 21 cells.
//
// A running broad jump buys four feet over a standing one but only after a
// 20-foot straight run; a high jump covers half its height sideways; Table 22
// rolls the dice per attempt by level band, and the cumulative encumbrance
// and demihuman modifiers can never push a jump below two feet broad or one
// foot high.
//
namespace rules {

// ---- the jumping prose rules ----

// On the average, a character can cover four more feet of distance with a
// running broad jump than he can with a standing broad jump.
inline int wjpRunningAdvantageFt()
    { return 4; }

// A running broad jump requires the character to make a 20-foot run in a
// straight line toward the obstacle immediately before leaping.
inline int wjpRunRequiredFt()
    { return 20; }

// Although thief-acrobats and barbarians are particularly skilled in jumping,
// any character is capable of making a broad jump or a high jump to get
// across or over something in his path.
inline bool wjpAnyCharacterCanJump()
    { return true; }

// A running broad jump requires the 20-foot straight-line run; if this space
// does not exist or there is no time to back up and start the run, then a
// standing broad jump is the best he can do.
inline bool wjpRunNeedsStraightRun()
    { return true; }

// A high jump will cover half as much distance horizontally as the height of
// the jump.
inline int wjpHighHorizDiv()
    { return 2; }

// If the target is a flat surface higher than the character current
// elevation, he can (if he succeeds in the leap) jump up to the surface and
// roll to absorb the impact of the jump.
inline bool wjpRollToHigherSurface()
    { return true; }

// If the obstacle is a thin barrier and the surface on the other side is at
// the same elevation, the jumper must make a successful high jump and then a
// Dexterity Check.
inline bool wjpThinBarrierDexCheck()
    { return true; }

// Failure on the thin-barrier Dexterity Check indicates the jumper has landed
// in a heap, possibly causing damage (a 1d3 roll for a jump of five feet or
// higher).
inline int wjpHeapDmgDie()
    { return 3; }

// The heap damage is possible for a jump of five feet or higher.
inline int wjpHeapMinFt()
    { return 5; }

// Failure on the check indicates that he has landed in a heap and will need
// the next round to stand up.
inline bool wjpHeapNeedsNextRound()
    { return true; }

// The die is rolled for each jump attempt - a 4th-level character can make a
// 3-foot high jump if a roll of 1d3 results in a 3, but fails to clear the
// height on a 1 or 2.
inline bool wjpDieRolledPerJump()
    { return true; }

// The modifiers to jumping ability are cumulative, subject to the 2-foot
// broad and 1-foot high floors.
inline bool wjpModifiersCumulative()
    { return true; }

// Moderately encumbered: -1 foot on jumping ability.
inline int wjpEncModerateFt()
    { return 1; }

// Heavily encumbered: -2 feet, and the character cannot high jump at all.
inline int wjpEncHeavyBroadFt()
    { return 2; }

// A heavily encumbered character cannot high jump (the -2 feet applies to the
// broad jumps he can still make).
inline bool wjpHeavyCannotHighJump()
    { return true; }

// A severely encumbered character cannot jump at all.
inline bool wjpSevereCannotJump()
    { return true; }

// Halfling: -1 foot on broad jumps only.
inline int wjpHalflingBroadFt()
    { return 1; }

// Gnome or dwarf: -2 feet on broad jumps.
inline int wjpDwarfBroadFt()
    { return 2; }

// Gnome or dwarf: -1 foot on high jumps.
inline int wjpDwarfHighFt()
    { return 1; }

// The modifiers are cumulative, but in no case can a broad jump be reduced to
// less than 2 feet for a character who is otherwise able to make the jump.
inline int wjpStandFloorFt()
    { return 2; }

// In no case can a high jump be reduced to less than 1 foot for a character
// who is otherwise able to make the jump.
inline int wjpHighFloorFt()
    { return 1; }

// ---- the Table 22 jumping grid ----

// Table 22 has seven level bands: 1-6, 7-9, 10-12, 13-15, 16-18, 19-22 and
// 23+.
inline int wjpBandCount()
    { return 7; }

// The standing broad jump die by level band (4 = 1d4, 6 = 1d6): 1d4 for the
// 1-6 and 7-9 bands, 1d6 for the 10-12 through 23+ bands.
inline int wjpStandDie(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The standing broad jump plus feet by level band: 1, 2, 2, 3, 4, 5 and 6 -
// the 1d4+1 through 1d6+6 ladder.
inline int wjpStandPlus(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The running broad jump die by level band (4 = 1d4, 6 = 1d6): 1d4 for the
// 1-6 and 7-9 bands, 1d6 for the 10-12 through 23+ bands.
inline int wjpRunDie(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The running broad jump plus feet by level band: 5, 6, 5, 6, 9, 12 and 15 -
// the 1d4+5 through 1d6+15 ladder.
inline int wjpRunPlus(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 9;
        case 5:
            return 12;
        case 6:
            return 15;
        default:
            return 0;
        }
    }

// The high jump die by level band (3 = 1d3, 4 = 1d4, 5 = 1d5, 6 = 1d6): 1d3,
// 1d4, 1d3, 1d4, 1d5, 1d5 and 1d6.
inline int wjpHighDie(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The high jump plus feet by level band: 0, 0, 1, 1, 0, 1 and 1 - the 1d3
// through 1d6+1 ladder.
inline int wjpHighPlus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        default:
            return 0;
        }
    }

}   // namespace rules
