// ===========================================================================
// Adnd1 - rules/uasmalls1.h
// The UA DM-SECTION SMALLS, part 1,
// R370: three items - Method V
// (p. 74), the starting hit-point
// minimums (p. 74), the warhorses
// and barding movement rate table
// (p. 76).
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. The R368 seam cross-checks the cavalier
// starting floor against the level-1 d10 pin
// (rules/uacavtable.h).
//
// JUDGMENTs (the decode method):
//   - the Method V prose prints clean (the humans-only
//     class-first read, the best-three-of-N roll, the
//     minimum and maximum clamps, the 9d6 fighter
//     strength example); the dice-count table body
//     extracts EMPTY - every cell a hole, flagged
//     pending the PDF.
//   - the starting hit-point minimums print clean -
//     the 12 class floors, the multi-class average
//     rounded up with the fighter/magic-user 5
//     example, the constitution adjustment with the
//     con-17 fighter 9 example.
//   - R394: the clean PDF read fills the
//     Method V dice-count table (the 12 x 7
//     matrix cell by cell) and repins the
//     barding columns - the R370 labels sat
//     one column off: light leather 21 scale
//     15 chain NA, medium 17/15/12, heavy
//     leather 15 scale 14 chain 13 plate 12.

namespace rules {

// ---- Method V (p. 74) ----
// The class-first generation: the player picks
// the class (subject to DM approval), rolls N
// dice per ability, keeps the best three.
inline bool uasm1MethodVHumansOnly()
    { return true; }

inline bool uasm1MethodVClassFirst()
    { return true; }

inline bool uasm1MethodVRequiresDmApproval()
    { return true; }

inline bool uasm1MethodVBestThreeOfN()
    { return true; }

// If the best-three total is below the class
// minimum the minimum applies; if above the
// maximum allowable (the barbarian wisdom) the
// maximum applies.
inline bool uasm1MethodVMinClampApplies()
    { return true; }

inline bool uasm1MethodVMaxClampApplies()
    { return true; }

// The worked example: the fighter strength
// rolls 9d6, keep the three highest.
inline int uasm1MethodVFighterStrengthDice()
    { return 9; }

// The dice-count table body extracts
// empty in the markdown; the R394
// clean PDF read fills the matrix.
inline bool uasm1MethodVTableCellsLost()
    { return false; }

// ---- the starting hit-point minimums (p. 74) ----
// Slots: 0 Cavalier, 1 Paladin, 2 Cleric,
// 3 Druid, 4 Fighter, 5 Barbarian, 6 Ranger,
// 7 Magic-user, 8 Illusionist, 9 Thief,
// 10 Assassin, 11 Monk.
inline int uasm1StartHpClassCount()
    { return 12; }

inline int uasm1StartHpMin(int slot) {
    static const int k[12] = {
        6, 6, 5, 5, 6, 7, 9, 3, 3, 4, 4, 5,
    };
    if (slot < 0) slot = 0;
    if (slot > 11) slot = 11;
    return k[slot];
}

// A multi-class character uses the average of
// the applicable minimums, rounded up.
inline bool uasm1StartHpMultiClassAverageRoundedUp()
    { return true; }

// The worked example: (6 + 3) / 2 = 5.
inline int uasm1StartHpExampleFighterMage()
    { return 5; }

inline bool uasm1StartHpConAdjustApplies()
    { return true; }

// The worked example: a 1st-level fighter with
// a 17 constitution has at least 9.
inline int uasm1StartHpExampleCon17Fighter()
    { return 9; }

// ---- the Method V dice-count
// table (p. 74, the R394 clean
// read) ----
// Rows: 0 Cavalier, 1 Paladin,
// 2 Cleric, 3 Druid, 4 Fighter,
// 5 Barbarian, 6 Ranger,
// 7 Magic-user, 8 Illusionist,
// 9 Thief, 10 Assassin, 11 Monk.
// Columns: 0 Str, 1 Int, 2 Wis,
// 3 Dex, 4 Con, 5 Cha, 6 Com.
inline int uasm1MethodVClassCount()
    { return 12; }

inline int uasm1MethodVAbilityCount()
    { return 7; }

inline int uasm1MethodVDice(int cls, int ab) {
    static const int k[12][7] = {
        {8, 6, 4, 7, 9, 3, 5},
        {7, 5, 8, 3, 6, 9, 4},
        {7, 4, 9, 5, 8, 6, 3},
        {7, 4, 8, 5, 6, 9, 3},
        {9, 3, 5, 7, 8, 6, 4},
        {9, 3, 5, 7, 8, 6, 4},
        {7, 6, 8, 5, 9, 4, 3},
        {4, 9, 7, 8, 6, 5, 3},
        {3, 8, 7, 9, 5, 6, 4},
        {6, 5, 3, 9, 7, 4, 8},
        {6, 7, 4, 9, 8, 3, 5},
        {7, 5, 9, 8, 6, 4, 3},
    };
    if (cls < 0) cls = 0;
    if (cls > 11) cls = 11;
    if (ab < 0) ab = 0;
    if (ab > 6) ab = 6;
    return k[cls][ab];
}

// ---- the barding movement table (p. 76) ----// Base movement rates in inches; NA = the
// heavier barding is not allowed on the
// lighter horse.
inline int uasm1BardLightLeather()
    { return 21; }

// The R394 clean read: the light row
// is leather 21, scale 15, chain NA
// - the R370 15 sat on the scale
// cell and the NA on the chain.
inline int uasm1BardLightScale()
    { return 15; }

inline bool uasm1BardLightChainNa()
    { return true; }

inline int uasm1BardLightChain()
    { return 0; }

inline bool uasm1BardLightScaleNa()
    { return false; }

inline bool uasm1BardLightPlateNa()
    { return true; }

inline int uasm1BardMediumLeather()
    { return 17; }

// The R394 clean read: medium scale
// 15, chain 12 - the R370 15 was
// the scale value on the chain cell.
inline int uasm1BardMediumScale()
    { return 15; }

inline int uasm1BardMediumChain()
    { return 12; }

inline bool uasm1BardMediumScaleCellLost()
    { return false; }

inline bool uasm1BardMediumPlateNa()
    { return true; }

// The R394 clean read: the heavy row
// is leather 15, scale 14, chain 13
// - the R370 values sat one column
// left.
inline int uasm1BardHeavyLeather()
    { return 15; }

inline bool uasm1BardHeavyLeatherCellLost()
    { return false; }

inline int uasm1BardHeavyChain()
    { return 13; }

inline int uasm1BardHeavyScale()
    { return 14; }

inline int uasm1BardHeavyPlate()
    { return 12; }

// The endurance rule: the base movement rate
// gives the miles per day.
inline bool uasm1BardEnduranceFromBaseRate()
    { return true; }

// ---- the magical barding ----
// Worth five times the cost of comparable
// armor; the plus can never exceed +3.
inline int uasm1MagBardingCostMultiple()
    { return 5; }

inline int uasm1MagBardingPlusCap()
    { return 3; }

inline int uasm1MagBardingPlus1Pct()
    { return 65; }

inline int uasm1MagBardingPlus2Pct()
    { return 25; }

inline int uasm1MagBardingPlus3Pct()
    { return 10; }

inline int uasm1MagBardingLeatherPct()
    { return 10; }

inline int uasm1MagBardingScalePct()
    { return 15; }

inline int uasm1MagBardingChainPct()
    { return 25; }

inline int uasm1MagBardingPlatePct()
    { return 50; }

// ---- the other steeds ----
// Flying steeds wear only leather (or elfin
// chain) barding, with the movement reduced
// by one-eighth; aquatic steeds cannot be
// barded.
inline bool uasm1FlyingSteedsLeatherOrElfinOnly()
    { return true; }

inline bool uasm1FlyingSteedsReductionEighth()
    { return true; }

inline bool uasm1AquaticSteedsNotBarded()
    { return true; }

// A very strong mount in plate barding loses
// from one-fifth to one-eighth of its
// movement; an elephant the least (the
// one-eighth).
inline int uasm1StrongMountPlateReductionMin()
    { return 5; }

inline int uasm1StrongMountPlateReductionMax()
    { return 8; }

// Elfin chain for unicorns or griffons: the
// weight and movement effect equal leather
// barding; the protection equal chain.
inline bool uasm1UnicornGriffonElfinWeightAsLeather()
    { return true; }

}   // namespace rules

