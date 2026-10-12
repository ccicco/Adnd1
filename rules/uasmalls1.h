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
//   - the barding table: light 21/15 with scale and
//     plate not allowed, medium 17/15 with the scale
//     cell garbled and plate not allowed, heavy
//     14/13/12 with the leather cell lost - the two
//     lost cells flagged pending the PDF; the
//     endurance, magical-barding and other-steeds
//     prose prints clean.

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

// The dice-count table body extracts empty -
// every cell a hole pending the PDF.
inline bool uasm1MethodVTableCellsLost()
    { return true; }

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

// ---- the barding movement table (p. 76) ----
// Base movement rates in inches; NA = the
// heavier barding is not allowed on the
// lighter horse.
inline int uasm1BardLightLeather()
    { return 21; }

inline int uasm1BardLightChain()
    { return 15; }

inline bool uasm1BardLightScaleNa()
    { return true; }

inline bool uasm1BardLightPlateNa()
    { return true; }

inline int uasm1BardMediumLeather()
    { return 17; }

inline int uasm1BardMediumChain()
    { return 15; }

// The medium scale cell garbles in the
// extract - a hole pending the PDF.
inline bool uasm1BardMediumScaleCellLost()
    { return true; }

inline bool uasm1BardMediumPlateNa()
    { return true; }

// The heavy leather cell is lost - a hole
// pending the PDF.
inline bool uasm1BardHeavyLeatherCellLost()
    { return true; }

inline int uasm1BardHeavyChain()
    { return 14; }

inline int uasm1BardHeavyScale()
    { return 13; }

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

