// ===========================================================================
// Adnd1 - rules/uailspells1.h
// The UA NEW ILLUSIONIST SPELLS (pp. 66-68) pins, R363:
// the 1st-level spell descriptions - the chromatic
// orb and phantom armor.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the chromatic orb name header garbles to a bare
//     cl-orb fragment - the name pins from the gap
//     item list and the prose; the school tail is
//     lost - a hole pending the PDF.
//   - the orb casting cell prints 7 segment - the
//     digit-garble family (the R343 precedent) decodes
//     the 1 segment.
//   - the orb to-hit ladder interleaves with the
//     range sentence: +3 at 1 inch or closer, +2 at
//     over 1 to 2 inches, +1 from over 2 inches to the
//     3-inch maximum - the fragments corroborate the
//     band values; the sentence garbles, flagged
//     pending the PDF.
//   - the orb color table prints nine rows - the
//     level ladder jumps 7th to 10th to 12th (no 8th
//     or 9th row prints) and the 10th and 12th damage
//     cells print empty - pinned as printed, the
//     holes noted pending the PDF; the special-power
//     notes print as an unnumbered bullet ladder with
//     garbled markers, mapped to the rows by order.
//   - the phantom armor level cell prints the clean
//     1 - the item list (the R322 index) names it at
//     2nd; the print wins, the divergence flagged in
//     the round note pending the PDF. The save-bonus
//     numeral garbles (a bare +) - a hole.
//   - the R342 IL table seam: the readable 1st
//     column prints five PHB names - neither new
//     name seam-checks, asserted in the audit.
// ===========================================================================

#pragma once

namespace rules {

// ---- the chromatic orb ----
// The name header garbles to a bare cl-orb fragment;
// the name pins from the gap item list and the
// prose. The school tail is lost - a hole pending
// the PDF.
inline const char* uail1OrbName()
    { return "Chromatic Orb"; }

inline bool uail1OrbNameHeaderGarbled()
    { return true; }

inline bool uail1OrbSchoolTailLost()
    { return true; }

inline int uail1OrbLevel()
    { return 1; }

inline bool uail1OrbRangeZero()
    { return true; }

inline bool uail1OrbDurationSpecial()
    { return true; }

inline bool uail1OrbAoeOneCreature()
    { return true; }

inline bool uail1OrbComponentsVSM()
    { return true; }

// The casting cell prints 7 segment - the family
// decodes the 1 segment.
inline int uail1OrbCastingTimeSegments()
    { return 1; }

inline bool uail1OrbCastingGarbleDecoded()
    { return true; }

inline bool uail1OrbSaveSpecial()
    { return true; }

// A small globe of varying hue, created in the hand
// and hurled at any opponent - no barriers between
// the illusionist and the target, which must be
// within the 3-inch maximum hurl distance.
inline int uail1OrbMaxHurlInches()
    { return 3; }

inline bool uail1OrbNoBarriers()
    { return true; }

// The orb is magical - even creatures normally
// struck only by +5, +4 etc. magic weapons are
// affected if it strikes; magic resistance
// withstands the spell.
inline bool uail1OrbMagicalVsHighPlus()
    { return true; }

inline bool uail1OrbMagicResistanceWithstands()
    { return true; }

// The to-hit ladder (the sentence interleaves with
// the range fragments, flagged pending the PDF):
// +3 at 1 inch or closer, +2 at over 1 to 2 inches,
// +1 from over 2 inches to the maximum 3 inches.
inline int uail1OrbHitAdjAtOneInch()
    { return 3; }

inline int uail1OrbHitAdjAtTwoInches()
    { return 2; }

inline int uail1OrbHitAdjAtMaxRange()
    { return 1; }

inline bool uail1OrbToHitSentenceInterleaved()
    { return true; }

// The color of the globe determines the effect when
// the subject is struck; low-level illusionists are
// restricted to colors at or below their level, the
// hues below always available.
inline bool uail1OrbColorDeterminesEffect()
    { return true; }

inline bool uail1OrbColorRestrictedByLevel()
    { return true; }

inline bool uail1OrbLowerHuesAlwaysAvailable()
    { return true; }

// The nine-row color ladder (the level cells print
// 1st through 7th, then 10th and 12th - the ladder
// jumps, no 8th or 9th row prints).
inline int uail1OrbRowCount()
    { return 9; }

inline int uail1OrbRowLevel(int i) {
    static const int k[9] = {
        1, 2, 3, 4, 5, 6, 7, 10, 12,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline const char* uail1OrbRowName(int i) {
    static const char* const k[9] = {
        "Pearly", "Ruby", "Flame", "Amber",
        "Emerald", "Turquoise", "Sapphire",
        "Amethyst", "Ashen",
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

// The 10th and 12th damage cells print empty - holes
// pending the PDF, pinned as zero with the lost
// flag.
inline int uail1OrbRowDamageMin(int i) {
    static const int k[9] = {
        1, 1, 1, 1, 1, 2, 2, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline int uail1OrbRowDamageMax(int i) {
    static const int k[9] = {
        4, 6, 8, 10, 12, 16, 8, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline bool uail1OrbRowDamageCellLost(int i)
    { return i == 7 || i == 8; }

// The special powers, mapped by row order (the note
// markers garble in the print).
// Pearly: light equal to a light spell persists 1
// round per caster level; a subject failing to save
// versus spell is blinded for the duration.
inline int uail1OrbPearlyLightRoundsPerLevel()
    { return 1; }

inline bool uail1OrbPearlyBlindsOnFailedSave()
    { return true; }

// Ruby: heat melts up to 1 cubic yard of ice; a
// creature not saving versus spell suffers a loss
// of 1 strength point and 1 dexterity point (or -1
// to hit and AC) for 1 round following the strike.
inline int uail1OrbRubyMeltsIceCuYd()
    { return 1; }

inline int uail1OrbRubyStatLossPerStat()
    { return 1; }

inline int uail1OrbRubyStatLossRounds()
    { return 1; }

// Flame: fire sets aflame all combustibles within 1
// inch radius of the target; unless the target saves
// versus spell an additional 2 points of fire
// damage are suffered (except when protected from
// fire by magical or natural means).
inline int uail1OrbFlameCombustiblesRadiusInches()
    { return 1; }

inline int uail1OrbFlameExtraDamage()
    { return 2; }

// Amber: the subject suffers blindness for 5-8
// rounds unless the save versus spell is made (cure
// blindness or dispel magic negates).
inline int uail1OrbAmberBlindRoundsMin()
    { return 5; }

inline int uail1OrbAmberBlindRoundsMax()
    { return 8; }

// Emerald: a magical stinking cloud of 5-radius
// around the target on a successful hit; the subject
// must save versus poison or be helpless, and in any
// event is helpless until leaving the vapors (cf.
// the stinking cloud spell).
inline int uail1OrbEmeraldCloudRadiusFeet()
    { return 5; }

// Turquoise: electrical damage; if the target wears
// ferrous metal it is magnetized for 3-12 rounds
// unless the save versus spell is made. Magnetized
// metal sticks fast to other magnetized items;
// non-magnetized ferrous items cling until pulled
// free.
inline int uail1OrbTurquoiseMagnetizeRoundsMin()
    { return 3; }

inline int uail1OrbTurquoiseMagnetizeRoundsMax()
    { return 12; }

// Sapphire: the subject is paralyzed for 5-20
// rounds unless the save versus paralyzation is
// made.
inline int uail1OrbSapphireParalysisRoundsMin()
    { return 5; }

inline int uail1OrbSapphireParalysisRoundsMax()
    { return 20; }

// Amethyst: the subject is turned to stone unless
// the save versus petrification is made; even if
// the save is made, the subject is slowed for 2-8
// rounds (cf. the slow spell).
inline bool uail1OrbAmethystStoneOnFailedSave()
    { return true; }

inline int uail1OrbAmethystSlowRoundsMin()
    { return 2; }

inline int uail1OrbAmethystSlowRoundsMax()
    { return 8; }

// Ashen: the subject dies unless the save versus
// death magic is made; even if the save is made, the
// subject is paralyzed for 2-5 rounds.
inline bool uail1OrbAshenDeathOnFailedSave()
    { return true; }

inline int uail1OrbAshenParalysisRoundsMin()
    { return 2; }

inline int uail1OrbAshenParalysisRoundsMax()
    { return 5; }

// The material component: a gem of the appropriate
// hue, or a clear crystal one (such as a diamond) -
// as small as 50 gold pieces in value as long as
// the color is appropriate.
inline int uail1OrbGemGpMin()
    { return 50; }

inline bool uail1OrbClearCrystalSubstitute()
    { return true; }

// ---- phantom armor (Alteration/Illusion) ----
inline const char* uail1PhantomName()
    { return "Phantom Armor (Alteration/Illusion)"; }

inline bool uail1PhantomComponentsVSM()
    { return true; }

// The level cell prints the clean 1 - the item list
// names the spell at 2nd; the print wins, the
// divergence flagged in the R363 note.
inline int uail1PhantomLevel()
    { return 1; }

inline bool uail1PhantomLevelDivergenceFlagged()
    { return true; }

// The casting cell prints 7 round - the family
// decodes the 1 round.
inline int uail1PhantomCastingTimeRounds()
    { return 1; }

inline bool uail1PhantomCastingGarbleDecoded()
    { return true; }

inline bool uail1PhantomRangeTouch()
    { return true; }

inline bool uail1PhantomDurationSpecial()
    { return true; }

inline bool uail1PhantomSaveNone()
    { return true; }

inline bool uail1PhantomAoeOnePerson()
    { return true; }

// The illusionist creates a quasi-real suit of
// plate mail - semi-illusory material covering the
// subject and giving some real protection.
inline bool uail1PhantomQuasiRealPlateMail()
    { return true; }

// The armor protects the wearer as if in plate mail:
// AC 3, armor type 3 as well.
inline int uail1PhantomAc()
    { return 3; }

inline int uail1PhantomArmorType()
    { return 3; }

// For each caster level the phantom armor absorbs
// 1 point of damage from a blow which would
// otherwise hit armor class 3; when it has absorbed
// as many points as the caster has levels, it is
// dispelled and vanishes - any remaining and all
// additional damage accrues to the person.
inline int uail1PhantomAbsorbPerLevel()
    { return 1; }

inline bool uail1PhantomVanishesAtLevelsAbsorbed()
    { return true; }

inline bool uail1PhantomRemainderAccrues()
    { return true; }

// The armor gives real protection unless the
// opponent actively disbelieves (saves versus
// spell), a dispel illusion or dispel magic is cast
// upon it, or a wand of negation affects it.
inline bool uail1PhantomDisbeliefBreaks()
    { return true; }

inline bool uail1PhantomDispelBreaks()
    { return true; }

inline bool uail1PhantomWandOfNegationBreaks()
    { return true; }

// The save-bonus numeral garbles (a bare + before
// saving throws versus all attack forms similarly
// modified by magic armor) - a hole pending the
// PDF.
inline bool uail1PhantomSaveBonusCellLost()
    { return true; }

// The dweomer in no way affects the movement or
// spell-casting abilities of the wearer.
inline bool uail1PhantomNoMovementOrCastingHindrance()
    { return true; }

// Not subject to rust monster attack (and such an
// attack may enhance disbelief).
inline bool uail1PhantomRustMonsterImmune()
    { return true; }

// The spell will not function with any other form
// of magical protection.
inline bool uail1PhantomNoOtherProtection()
    { return true; }

// The material component: a small plate of mithral
// (10 gp value) which disappears when the spell is
// cast.
inline int uail1PhantomMithralGp()
    { return 10; }

inline bool uail1PhantomDisappearsOnCast()
    { return true; }

}   // namespace rules

