// ===========================================================================
// Adnd1 - rules/uadruidspells2.h
// The UA NEW DRUID SPELLS (pp. 43-44) pins, R351: the 2nd-level
// spell descriptions - flame blade, goodberry, reflecting pool
// and slow poison.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the flame
//     blade and reflecting pool durations print "7 round/level"
//     and the goodberry casting time prints "7 round" - the
//     family decodes each as 1 (flame blade prints a clean
//     "Level: 2" cell).
//   - the goodberry name header and school never print (the
//     stat block follows the flame blade material sentence
//     directly); identified by the prose "goodberry spell" plus
//     the gap item list.
//   - the reflecting pool name header prints "Pool ion -" - a
//     two-column garble of "Reflecting Pool"; identified by the
//     prose "cast through a reflecting pool" plus the gap item
//     list. The school never prints.
//   - the flame blade damage sentence splits after "if the
//     creature is": the scrambled fragments reassemble as the
//     -2 clause (a fire-dweller or which uses fire attack form)
//     and the protected-from-fire sentence (no damage can be
//     inflicted upon a creature which is protected from fire).
//   - the flame blade material fragments reassemble: "In
//     addition to mistletoe, the druid must have a leaf of the
//     sumac in order to cast this spell" (the "class. order"
//     fragment carries the lost "order").
//   - the flame blade area cell prints "3 long, sword-like
//     blade" - the unit mark is lost; position-decoded as a
//     3-foot blade, pinned with doubt pending the PDF.
//   - the goodberry duration prints "1 day + 1/level" - the
//     per-level unit is lost; pinned verbatim with the unit
//     flagged as a hole.
//   - the reflecting pool material fragments scramble around
//     the walnut oil: mistletoe plus oil extracted from nuts
//     such as the walnut; the measure fragment stays a hole.
//   - the reflecting pool prose loses the spell name after
//     "the spells starshine and" - a hole (see hereafter points
//     into this chapter).
//   - the slow poison range cell prints head-lost as "ge:
//     Touch" = Range: Touch; the level cell never prints -
//     position-certain 2 by the section header. The stray "that"
//     fragment after the saving throw is the tail of the
//     "is able to determine that" clause.
//
// OCR holes (the item stays open - the 3rd-7th levels pin in
// later rounds; these stay pending the PDF): the goodberry name
// header and school; the goodberry duration unit; the reflecting
// pool name header and school; the reflecting pool material
// measure; the lost spell name after "starshine and"; the flame
// blade area unit mark.
// ===========================================================================

#pragma once

namespace rules {

// ---- flame blade (Evocation), p. 43 ----
inline const char* uad2FlameBladeName()
    { return "Flame Blade (Evocation)"; }

inline bool uad2FlameBladeComponentsVSM()
    { return true; }

inline int uad2FlameBladeLevel()
    { return 2; }

inline int uad2FlameBladeCastingTimeSegments()
    { return 3; }

inline int uad2FlameBladeRangeInches()
    { return 0; }

inline bool uad2FlameBladeSaveNone()
    { return true; }

// The duration prints "7 round/level" - the digit-garble family
// decodes 1 round/level.
inline int uad2FlameBladeDurationRoundsPerLevel()
    { return 1; }

// The area cell prints "3 long, sword-like blade" - the unit
// mark is lost; position-decoded as 3 feet, with doubt.
inline int uad2FlameBladeBladeLengthFeet()
    { return 3; }

inline bool uad2FlameBladeBladeUnitLost()
    { return true; }

// A blazing ray of red-hot fire springs from the druid's hand,
// wielded as if it were a scimitar.
inline bool uad2FlameBladeWieldedAsScimitar()
    { return true; }

// A successful hit inflicts 5-8 points of damage; +2 if the
// creature is undead or especially vulnerable to fire; -2 if a
// fire-dweller or a fire-attack-form user.
inline int uad2FlameBladeDamageMin()
    { return 5; }

inline int uad2FlameBladeDamageMax()
    { return 8; }

inline int uad2FlameBladeUndeadOrFireVulnerableBonus()
    { return 2; }

inline int uad2FlameBladeFireDwellerPenalty()
    { return -2; }

// No damage can be inflicted upon a creature protected from
// fire (the interleave decode).
inline bool uad2FlameBladeNoDamageOnFireProtected()
    { return true; }

// The blade will ignite dry materials such as straw, sticks,
// cloth, etc.
inline bool uad2FlameBladeIgnitesDryMaterials()
    { return true; }

// Not a magical weapon in the normal sense except with respect
// to undead monsters - creatures struck only by magical weapons
// are not harmed unless of the undead class.
inline bool uad2FlameBladeNotMagicalExceptVsUndead()
    { return true; }

inline bool uad2FlameBladeMagicOnlyCreaturesImmuneUnlessUndead()
    { return true; }

// The material: mistletoe plus a leaf of the sumac (the
// interleave decode; the "order" fragment).
inline bool uad2FlameBladeMaterialMistletoe()
    { return true; }

inline bool uad2FlameBladeMaterialSumacLeaf()
    { return true; }

inline bool uad2FlameBladeMaterialInterleaveDecoded()
    { return true; }

// ---- goodberry, p. 44 ----
// The name header and school never print; identified by the
// prose "goodberry spell" plus the gap item list.
inline const char* uad2GoodberryName()
    { return "Goodberry"; }

inline bool uad2GoodberryNameHeaderLost()
    { return true; }

inline bool uad2GoodberrySchoolLost()
    { return true; }

inline bool uad2GoodberryComponentsVSM()
    { return true; }

inline int uad2GoodberryLevel()
    { return 2; }

// The casting time prints "7 round" - the family decodes
// 1 round.
inline int uad2GoodberryCastingTimeRounds()
    { return 1; }

inline bool uad2GoodberryRangeTouch()
    { return true; }

inline bool uad2GoodberrySaveNone()
    { return true; }

// The duration prints "1 day + 1/level" - the per-level unit is
// lost; pinned verbatim with the unit flagged.
inline int uad2GoodberryDurationDaysBase()
    { return 1; }

inline int uad2GoodberryDurationPerLevelAddend()
    { return 1; }

inline bool uad2GoodberryDurationUnitLost()
    { return true; }

inline int uad2GoodberryBerriesMin()
    { return 2; }

inline int uad2GoodberryBerriesMax()
    { return 8; }

// The casting druid (or any druid of 3rd or higher level)
// immediately discerns the affected berries; detect magic
// discovers them also.
inline bool uad2GoodberryDiscernedByDruid3rdPlus()
    { return true; }

inline bool uad2GoodberryDetectMagicReveals()
    { return true; }

// Each berry either nourishes a hungry man-size creature as a
// full meal or cures 1 point of damage, to a maximum of 8
// points of curing in any 24-hour period.
inline bool uad2GoodberryNourishAsFullMeal()
    { return true; }

inline int uad2GoodberryCurePerBerry()
    { return 1; }

inline int uad2GoodberryCureMaxPer24h()
    { return 8; }

// The reverse, badberry: rotten berries appear wholesome but
// each delivers 1 point of poison damage, no saving throw.
inline bool uad2GoodberryReverseBadberry()
    { return true; }

inline int uad2GoodberryBadberryPoisonPoints()
    { return 1; }

inline bool uad2GoodberryBadberryNoSave()
    { return true; }

// The material is mistletoe passed over the freshly picked,
// edible berries; the example list tail survives (currants,
// gooseberries, etc.) - the first list item is lost.
inline bool uad2GoodberryMaterialMistletoe()
    { return true; }

inline bool uad2GoodberryExampleListFirstItemLost()
    { return true; }

// ---- reflecting pool, p. 44 ----
// The name header prints "Pool ion -" - a two-column garble of
// Reflecting Pool; identified by the prose "cast through a
// reflecting pool" plus the gap item list.
inline const char* uad2ReflectingPoolName()
    { return "Reflecting Pool"; }

inline bool uad2ReflectingPoolNameHeaderGarbled()
    { return true; }

inline bool uad2ReflectingPoolSchoolLost()
    { return true; }

inline bool uad2ReflectingPoolComponentsVSM()
    { return true; }

inline int uad2ReflectingPoolLevel()
    { return 2; }

inline int uad2ReflectingPoolCastingTimeHours()
    { return 2; }

inline int uad2ReflectingPoolRangeInches()
    { return 1; }

inline bool uad2ReflectingPoolSaveNone()
    { return true; }

// The duration prints "7 round/level" - the family decodes
// 1 round/level.
inline int uad2ReflectingPoolDurationRoundsPerLevel()
    { return 1; }

inline bool uad2ReflectingPoolAoeSpecial()
    { return true; }

// The pool is normal water in a natural setting, acting as a
// scrying device of no greater diameter than 2 feet per level
// of the caster.
inline bool uad2ReflectingPoolNaturalWaterOnly()
    { return true; }

inline int uad2ReflectingPoolDiameterFeetPerLevel()
    { return 2; }

// Similar to a crystal ball, in the fashion of the magic-user
// magic mirror and the clerical magic font.
inline bool uad2ReflectingPoolCrystalBallLike()
    { return true; }

inline bool uad2ReflectingPoolMagicMirrorAndFontRef()
    { return true; }

// The scrying extends only to planes coexistent with or
// bordering the Prime Material - the Inner Planes, including
// the Para-elemental Planes and the Plane of Shadow; the
// crystal ball penalties (DMG) apply beyond the druid's own
// plane.
inline bool uad2ReflectingPoolCoexistentPlanesOnly()
    { return true; }

inline bool uad2ReflectingPoolIncludesParaElementalAndShadow()
    { return true; }

inline bool uad2ReflectingPoolCrystalBallPenaltiesApply()
    { return true; }

// The spells cast through the pool, with a 5% per level chance
// of operating correctly: detect magic, detect snares and pits,
// detect poison.
inline int uad2ReflectingPoolCastThroughChancePctPerLevel()
    { return 5; }

inline int uad2ReflectingPoolCastThroughCount()
    { return 3; }

inline const char* uad2ReflectingPoolCastThroughName(int i) {
    static const char* const k[3] = {
        "Detect Magic", "Detect Snares and Pits",
        "Detect Poison",
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return k[i];
}

// Infravision and ultravision operate normally through the
// pool, as will the spells starshine and [the companion name
// is lost - a hole].
inline bool uad2ReflectingPoolInfraAndUltravisionNormal()
    { return true; }

inline bool uad2ReflectingPoolStarshineOperates()
    { return true; }

inline bool uad2ReflectingPoolCompanionSpellNameLost()
    { return true; }

// The material: mistletoe and oil extracted from nuts such as
// the walnut; the measure fragment stays a hole.
inline bool uad2ReflectingPoolMaterialMistletoe()
    { return true; }

inline bool uad2ReflectingPoolMaterialNutOil()
    { return true; }

inline bool uad2ReflectingPoolMaterialMeasureLost()
    { return true; }

// ---- slow poison (Necromantic), p. 44 ----
inline const char* uad2SlowPoisonName()
    { return "Slow Poison (Necromantic)"; }

inline bool uad2SlowPoisonComponentsVSM()
    { return true; }

// The level cell never prints - position-certain 2 by the
// section header.
inline int uad2SlowPoisonLevel()
    { return 2; }

// The range cell prints head-lost as "ge: Touch" = Touch.
inline bool uad2SlowPoisonRangeTouch()
    { return true; }

inline bool uad2SlowPoisonRangeCellHeadLost()
    { return true; }

inline bool uad2SlowPoisonSaveNone()
    { return true; }

inline int uad2SlowPoisonDurationHoursPerLevel()
    { return 1; }

inline bool uad2SlowPoisonAoeCreatureTouched()
    { return true; }

inline int uad2SlowPoisonCastingTimeSegments()
    { return 1; }

// Identical to the 2nd-level clerical slow poison, except: if
// the poison was made from some living plant, the druid has a
// 5% chance per level of knowing an herbal antidote which will
// neutralize the poison.
inline bool uad2SlowPoisonIdenticalToClerical()
    { return true; }

inline int uad2SlowPoisonAntidoteChancePctPerLevel()
    { return 5; }

inline bool uad2SlowPoisonPlantPoisonCondition()
    { return true; }

// If the actual type of poison is not given by the DM, a
// successful detect poison (type) indicates an organic poison
// which can be countered; a dice roll equal to or less than
// the druid's chance indicates neutralization.
inline bool uad2SlowPoisonDetectPoisonIndicatesOrganic()
    { return true; }

inline bool uad2SlowPoisonRollEqualOrLessNeutralizes()
    { return true; }

// The material: mistletoe, plus crushed garlic rubbed on the
// recipient's feet; antidotes from green vegetables outdoors or
// an herbalist or similar source.
inline bool uad2SlowPoisonMaterialMistletoe()
    { return true; }

inline bool uad2SlowPoisonMaterialGarlicOnFeet()
    { return true; }

inline bool uad2SlowPoisonAntidoteOutdoorOrHerbalist()
    { return true; }

}   // namespace rules
