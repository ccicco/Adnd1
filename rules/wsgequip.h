// =========================================================================================
// Adnd1 - rules/wsgequip.h
// The WSG EFFECTS ON EQUIPMENT, R431: the water and rust rules (the 2-day
// drying, the 2-week oiling, the armor crack, the shield split, the weapon
// break), the leather and rope rules, the wet-clothing temperature shift and
// the sand/dust chafe rules - the section closes the
// effects-of-the-environment chapter WHOLE.
// census 355 -> 356.
//
// Provenance: the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed
// pp. 28-29; the user own copy OCR cross-checked against the djvu text layer,
// every number matched.
//
namespace rules {

// ---- the water and rust rules ----

// Dry metal off once every 2 days.
inline int weqRustDryDays()
    { return 2; }

// Oil or protect metal once every 2 weeks.
inline int weqRustOilWeeks()
    { return 2; }

// The rusted-armor crack trigger: an unmodified 20.
inline int weqArmorCrackRoll()
    { return 20; }

// The crack needs more than 4 points of damage.
inline int weqArmorCrackDmgMin()
    { return 4; }

// The crack chance: 1 in 3.
inline int weqArmorCrackDen()
    { return 3; }

// Rusted armor suffers no direct AC penalty.
inline bool weqRustedArmorNoAcPenalty()
    { return true; }

// A cracked armor is one AC step worse.
inline bool weqArmorCrackOneStepWorse()
    { return true; }

// A second crack hit breaks the armor entirely until repaired.
inline bool weqArmorSecondHitBreaks()
    { return true; }

// The rusted-shield split chance: 50 percent.
inline int weqShieldSplitPct()
    { return 50; }

// A shield hit at one under the needed roll may split it.
inline bool weqShieldNearMissSplits()
    { return true; }

// The rusted-weapon break trigger: an unmodified 1.
inline int weqWeaponBreakRoll()
    { return 1; }

// The weapon break chance: 1 in 3.
inline int weqWeaponBreakDen()
    { return 3; }

// ---- the leather, rope and moisture rules ----

// Thoroughly dry boots once every 2 days or so.
inline int weqBootsDryDays()
    { return 2; }

// Too much heat cracks leather drying it.
inline bool weqLeatherHeatCracks()
    { return true; }

// Cracked leather armor treats blows like rusted metal armor.
inline bool weqLeatherCrackedAsRusted()
    { return true; }

// Excessive dried mud can crack leather too.
inline bool weqMudCanCrackLeather()
    { return true; }

// A dry-made knot in a wet rope is hard to untie.
inline bool weqWetKnotHardToUntie()
    { return true; }

// A wet-made knot weakens after the rope dries.
inline bool weqDryKnotLoosens()
    { return true; }

// Wet clothing at 30 degrees counts as 10 degrees colder.
inline int weqWetClothesDeltaTemp()
    { return 10; }

// ---- the wet arrows and inks ----

// A waterlogged arrow: -1 to hit and damage for a non-specialist.
inline int weqWetArrowPenalty()
    { return -1; }

// A bow specialist takes no wet-arrow penalty.
inline bool weqArrowSpecialistExempt()
    { return true; }

// Spell and protection scrolls use waterproof ink.
inline bool weqMagicalInkWaterproof()
    { return true; }

// ---- the sand and dust rules ----

// Sand chafe: the surprise chance +1 in 6.
inline int weqChafeSurpriseDen()
    { return 6; }

// Severe chafe: 3/4 normal speed (numerator).
inline int weqChafeMoveNum()
    { return 3; }

// The chafe move denominator.
inline int weqChafeMoveDen()
    { return 4; }

// Severe chafe: -1 dexterity for dodging and abrupt moves.
inline int weqChafeDexPenalty()
    { return -1; }

// Sand abrasion has no short-term effect in the vast majority of sandstorms.
inline bool weqSandAbrasionNegligible()
    { return true; }

// A sand-contaminated potion may be untainted, ruined or poison at the DM
// discretion.
inline bool weqSandPotionDmCall()
    { return true; }

// Dust is not abrasive; it penetrates further than sand.
inline bool weqDustNotAbrasive()
    { return true; }

// Dust in clothing does not chafe; no prompt cleaning needed.
inline bool weqDustNoChafe()
    { return true; }

}   // namespace rules
