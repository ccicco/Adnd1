// ===========================================================================
// Adnd1 - rules/uadruidspells6.h
// The UA NEW DRUID SPELLS (p. 45) pins, R354: the 6th-level
// spell descriptions - liveoak and water to dust.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the liveoak
//     casting time prints "7 turn" - the family decodes
//     1 turn (liveoak prints a clean "Level: 6" cell; water to
//     dust prints a clean 6 and a clean "8 segments").
//   - the water to dust name header prints "Water To Dust (,"
//     [sic]) -
//     the school is lost in the garble; the gap item list calls
//     it "transmute water to dust" - the spell pins as Water To
//     Dust with the school and the transmute prefix flagged as
//     holes.
//   - the water to dust stat block interleaves both columns:
//     the components cell prints only "V,"; the prose pins the
//     full components (diamond dust of at least 500 gp value, a
//     bit of seashell, and the druid's mistletoe; the reverse
//     adds a pinch of normal dust).
//   - the liveoak treant interleave: ", matching the
//     specifications of the Monster Manual de-" + "scription,
//     but with only a 3\" + "rate. An oak" reassembles as:
//     matching the Monster Manual description, but with only a
//     3" movement rate. An oak spell will radiate a magic
//     aura - the word between 3" and "rate" position-decodes as
//     "movement", flagged with doubt pending the PDF.
//
// OCR holes (the item stays open - the 7th level pins in the
// next round; these stay pending the PDF): the liveoak movement
// word; the water to dust school and transmute prefix; the
// water to dust components cell beyond the "V," fragment.
// ===========================================================================

#pragma once

namespace rules {

// ---- liveoak (Enchantment), p. 45 ----
inline const char* uad6LiveoakName()
    { return "Liveoak (Enchantment)"; }

inline bool uad6LiveoakComponentsVSM()
    { return true; }

inline int uad6LiveoakLevel()
    { return 6; }

inline bool uad6LiveoakRangeTouch()
    { return true; }

inline int uad6LiveoakDurationDaysPerLevel()
    { return 1; }

inline bool uad6LiveoakAoeOneOakTree()
    { return true; }

// The casting time prints "7 turn" - the digit-garble family
// decodes 1 turn.
inline int uad6LiveoakCastingTimeTurns()
    { return 1; }

inline bool uad6LiveoakSaveNone()
    { return true; }

// The spell is cast on but a single tree at a time, and while a
// liveoak cast by a particular druid is in effect, he or she
// cannot cast another such spell.
inline bool uad6LiveoakSingleTreeAtATime()
    { return true; }

inline bool uad6LiveoakOnlyOnePerDruid()
    { return true; }

// The tree must be within 10 feet of the druid's dwelling
// place, within a place sacred to the druid, or within 10
// inches of something which the druid wishes to guard or
// protect.
inline int uad6LiveoakDwellingFeet()
    { return 10; }

inline bool uad6LiveoakWithinSacredPlace()
    { return true; }

inline int uad6LiveoakGuardedInches()
    { return 10; }

// A healthy tree of small, medium, or large size, according to
// desire and availability.
inline bool uad6LiveoakSizePerDesireAndAvailability()
    { return true; }

// A triggering phrase of up to one word per level of the caster
// is placed upon the dweomered oak.
inline int uad6LiveoakTriggerWordsPerLevel()
    { return 1; }

// The example: an 11-word trigger usable by a druid of 11th or
// higher level - attack any persons who come near without
// first saying the sacred mistletoe phrase.
inline int uad6LiveoakExampleTriggerWords()
    { return 11; }

inline int uad6LiveoakExampleCasterLevel()
    { return 11; }

// The liveoak triggers the tree into becoming a treant of
// appropriate size and attack capability, matching the Monster
// Manual specification.
inline bool uad6LiveoakBecomesTreantMmSpec()
    { return true; }

// The treant moves with only a 3-inch movement rate (the
// interleave decode; the movement word position-decoded with
// doubt).
inline int uad6LiveoakTreantMovementRateInches()
    { return 3; }

inline bool uad6LiveoakMovementWordDecoded()
    { return true; }

// The oak spell radiates a magic aura, and can be returned to
// normal by a successful dispel magic or upon the desire of the
// druid who enchanted it.
inline bool uad6LiveoakRadiatesMagicAura()
    { return true; }

inline bool uad6LiveoakDispelOrDesireReturns()
    { return true; }

inline bool uad6LiveoakMaterialMistletoe()
    { return true; }

// ---- water to dust, p. 45 ----
// The name header prints "Water To Dust (," [sic]) - the
// school is
// lost in the garble; the gap item list calls the spell
// "transmute water to dust".
inline const char* uad6WaterToDustName()
    { return "Water To Dust"; }

inline bool uad6WaterToDustNameHeaderGarbled()
    { return true; }

inline bool uad6WaterToDustSchoolLost()
    { return true; }

inline bool uad6WaterToDustGapItemSaysTransmute()
    { return true; }

// The components cell prints only "V," - a hole; the prose pins
// the full components.
inline bool uad6WaterToDustComponentsCellLost()
    { return true; }

inline int uad6WaterToDustLevel()
    { return 6; }

inline int uad6WaterToDustRangeInches()
    { return 6; }

inline int uad6WaterToDustCastingTimeSegments()
    { return 8; }

inline bool uad6WaterToDustSaveNoneAndSpecial()
    { return true; }

inline bool uad6WaterToDustDurationPermanent()
    { return true; }

inline int uad6WaterToDustAoeCubicInchesPerLevel()
    { return 1; }

// The stat block interleaves both columns; the prose opener
// splits as "in-" + "stantly" across the block.
inline bool uad6WaterToDustStatBlockInterleaveDecoded()
    { return true; }

// The subject area instantly undergoes a change from liquid to
// powdery dust.
inline bool uad6WaterToDustLiquidToPowderyDust()
    { return true; }

// Muddy water expands the area of effect to double normal; wet
// mud quadruples it.
inline int uad6WaterToDustMuddyAreaMultiplier()
    { return 2; }

inline int uad6WaterToDustWetMudAreaMultiplier()
    { return 4; }

// Water remaining in contact with the transmuted dust quickly
// permeates it, turning the dust into silty mud if a
// sufficient quantity exists, otherwise soaking or dampening
// accordingly.
inline bool uad6WaterToDustContactFormsSiltyMud()
    { return true; }

// Only liquid actually existing in the area at the moment of
// casting is affected.
inline bool uad6WaterToDustOnlyLiquidAtCasting()
    { return true; }

// Liquids only partially water are affected as far as the
// actual water is concerned; potions containing water as a
// component part are rendered useless.
inline bool uad6WaterToDustPartialWaterAffected()
    { return true; }

inline bool uad6WaterToDustPotionsRenderedUseless()
    { return true; }

// Living creatures are unaffected, except those native to the
// Elemental Plane of Water: they receive a saving throw versus
// spell to escape, and only one such creature can be affected
// by any single casting, regardless of size (creature or area).
inline bool uad6WaterToDustLivingUnaffectedExceptWaterNatives()
    { return true; }

inline bool uad6WaterToDustWaterNativeSaveVsSpell()
    { return true; }

inline bool uad6WaterToDustOneCreaturePerCasting()
    { return true; }

// The reverse is simply a very high-powered create water spell
// requiring a pinch of normal dust as an additional material
// component.
inline bool uad6WaterToDustReverseCreateWater()
    { return true; }

inline bool uad6WaterToDustReverseAddsDustPinch()
    { return true; }

// For either usage: diamond dust of at least 500 gp value, a
// bit of seashell, and the druid's mistletoe.
inline int uad6WaterToDustDiamondDustMinGp()
    { return 500; }

inline bool uad6WaterToDustMaterialSeashell()
    { return true; }

inline bool uad6WaterToDustMaterialMistletoe()
    { return true; }

}   // namespace rules
