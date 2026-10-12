// ===========================================================================
// Adnd1 - rules/uaarmor.h
// The UA EXPANDED ARMOR (pp. 75-76)
// pins, R371: the armor and
// encumbrance table rows (the
// costs, the weights, the base
// movement, the bulk column, the
// shield rows) and the four new
// armor descriptions - bronze
// plate (the AC 4 with the +2
// rear-attack exposure and the
// rust immunity), elfin chain
// (the thief-wearable read), field
// plate (the 1 point per die
// absorption, the 12 point cap,
// the repair costs), full plate.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. Cross-checks the landed R191 seam
// (rules/armorratings.h - the plate mail AC 3 the
// bronze plate reads one worse than), the R334 seam
// (rules/thiefarmor.h - the elfin chain rows) and the
// R370 seam (the elfin-chain barding weight read).
//
// JUDGMENTs (the decode method):
//   - the table rows print clean for banded, bronze
//     plate, field plate, full plate, ring, scale,
//     splint and studded leather; the elfin chain
//     cost cell garbles - which confirms the clean
//     footnote (never on the open market) rather
//     than contradicting it; some weight cells carry
//     the OCR crosshatch - the weights pinned where
//     clean, flagged where not.
//   - the four descriptions print clean throughout.

namespace rules {

// ---- the expanded armor table (p. 75) ----
// Banded: bulky, 35 pounds, 9 inches, 90 gp.
inline int uaarmBandedWeight()
    { return 35; }

inline int uaarmBandedMove()
    { return 9; }

inline int uaarmBandedCost()
    { return 90; }

inline bool uaarmBandedBulky()
    { return true; }

// Bronze plate: bulky, 45 pounds, 6 inches, 100 gp.
inline int uaarmBronzePlateWeight()
    { return 45; }

inline int uaarmBronzePlateMove()
    { return 6; }

inline int uaarmBronzePlateCost()
    { return 100; }

inline bool uaarmBronzePlateBulky()
    { return true; }

// Field plate: fairly bulky, 55 pounds, 6 inches,
// 2000 gp.
inline int uaarmFieldPlateWeight()
    { return 55; }

inline int uaarmFieldPlateMove()
    { return 6; }

inline int uaarmFieldPlateCost()
    { return 2000; }

inline bool uaarmFieldPlateFairlyBulky()
    { return true; }

// Full plate: fairly bulky, 65 pounds, 6 inches,
// 4000 gp.
inline int uaarmFullPlateWeight()
    { return 65; }

inline int uaarmFullPlateMove()
    { return 6; }

inline int uaarmFullPlateCost()
    { return 4000; }

inline bool uaarmFullPlateFairlyBulky()
    { return true; }

// Ring mail: fairly bulky, 25 pounds, 9 inches,
// 30 gp.
inline int uaarmRingMailWeight()
    { return 25; }

inline int uaarmRingMailMove()
    { return 9; }

inline int uaarmRingMailCost()
    { return 30; }

// Scale mail: fairly bulky, 40 pounds, 6 inches,
// 45 gp.
inline int uaarmScaleMailWeight()
    { return 40; }

inline int uaarmScaleMailMove()
    { return 6; }

inline int uaarmScaleMailCost()
    { return 45; }

// Splint mail: fairly bulky, 40 pounds, 6 inches,
// 80 gp.
inline int uaarmSplintMailWeight()
    { return 40; }

inline int uaarmSplintMailMove()
    { return 6; }

inline int uaarmSplintMailCost()
    { return 80; }

// Studded leather: fairly bulky, 20 pounds,
// 9 inches, 15 gp.
inline int uaarmStuddedLeatherWeight()
    { return 20; }

inline int uaarmStuddedLeatherMove()
    { return 9; }

inline int uaarmStuddedLeatherCost()
    { return 15; }

// ---- the elfin chain footnote ----
// The clean footnote: never available on the
// open market (the cost cell garbles, which
// confirms the read).
inline bool uaarmElfinNeverOnOpenMarket()
    { return true; }

// ---- the shield rows ----
inline int uaarmShieldBucklerWeight()
    { return 3; }

inline int uaarmShieldBucklerCost()
    { return 5; }

inline int uaarmShieldLargeWeight()
    { return 10; }

inline int uaarmShieldLargeCost()
    { return 15; }

inline int uaarmShieldSmallWeight()
    { return 5; }

inline int uaarmShieldSmallCost()
    { return 10; }

// ---- the bronze plate description ----
// AC 4 (the regular plate mail AC 3), the
// rear attacks at +2, the rust-monster
// immunity.
inline int uaarmBronzeAc()
    { return 4; }

inline int uaarmBronzeRearAttackBonus()
    { return 2; }

inline bool uaarmBronzeRustImmune()
    { return true; }

inline bool uaarmBronzeEarlierCheaperVersion()
    { return true; }

// ---- the elfin chain description ----
inline bool uaarmElfinElvenMade()
    { return true; }

inline bool uaarmElfinExtremelyRare()
    { return true; }

inline bool uaarmElfinThiefWearable()
    { return true; }

inline bool uaarmElfinSomewhatImpairsThiefAbilities()
    { return true; }

// ---- the field plate description ----
// Absorbs 1 point per die of damage (a die
// roll of 1 takes no damage); after 12
// absorbed points the armor is damaged.
inline int uaarmFieldPlateAbsorbPerDie()
    { return 1; }

inline int uaarmFieldPlateAbsorbCap()
    { return 12; }

inline int uaarmFieldPlateRepairCostPerPoint()
    { return 100; }

inline int uaarmFieldPlateRepairDaysPerPoint()
    { return 1; }

inline bool uaarmFieldPlateFittedToWearer()
    { return true; }

inline bool uaarmFieldPlateBulkyAsChain()
    { return true; }

// ---- the full plate description ----
inline bool uaarmFullPlateInterlockedBackedWithChain()
    { return true; }

inline bool uaarmFullPlateBulkyAsChain()
    { return true; }

}   // namespace rules

