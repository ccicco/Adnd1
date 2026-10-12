// ===========================================================================
// Adnd1 - rules/uauwspelluse.h
// The UA UNDERWATER SPELL USE (pp. 81-83 print) pins,
// R366: the cannot-be-used lists by class, the
// airy-water footnote and the altered-effects reads.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. The DMG underwater spells (R168) are a
// separate battery item; this is the UA adventure
// layer.
//
// JUDGMENTs (the decode method):
//   - the magic-user cannot-use list garbles at the
//     cantrip row (dampen reads; the second cantrip
//     cell is lost) - flagged, no name pin.
//   - the list tail interleaves the illusionist
//     column (haze, rainbow, whispering wind, phantom
//     wind, solid fog, death fog) - the fragment pins
//     as the illusionist list, corroborated by the
//     landed UA IL spell levels (R363-R365: rainbow at
//     1st, whispering wind at 2nd, phantom wind at
//     3rd, solid fog at 4th, death fog at 6th).
//   - the chain lightning save tail truncates ("half
//     dama") - decoded as the standard save-for-half
//     per the DMG lightning bolt.
//   - the starred footnote: spells that can be cast
//     and will function within the bounds of an airy
//     water spell.
// ===========================================================================

#pragma once

namespace rules {

// ---- the cleric cannot-use list ----
inline int uauwClericCannotUseCount()
    { return 5; }

inline bool uauwClericPrecipitationFirst()
    { return true; }

inline bool uauwClericDustDevilSecond()
    { return true; }

inline bool uauwClericCloudburstThird()
    { return true; }

inline bool uauwClericAirWalkFifth()
    { return true; }

inline bool uauwClericRainbowFifth()
    { return true; }

inline bool uauwClericAirWalkStarred()
    { return true; }

inline bool uauwClericRainbowStarred()
    { return true; }

// ---- the druid cannot-use list ----
inline int uauwDruidCannotUseCount()
    { return 4; }

inline bool uauwDruidPrecipitationFirst()
    { return true; }

inline bool uauwDruidFlameBladeSecond()
    { return true; }

inline bool uauwDruidCloudburstThird()
    { return true; }

inline bool uauwDruidLiveoakSixth()
    { return true; }

inline bool uauwDruidFlameBladeStarred()
    { return true; }

// ---- the magic-user cannot-use list ----
inline bool uauwMuDampenCantripListed()
    { return true; }

inline bool uauwMuCantripSecondCellLost()
    { return true; }

inline bool uauwMuMountFirst()
    { return true; }

inline bool uauwMuPrecipitationFirst()
    { return true; }

inline bool uauwMuFlamingSphereSecond()
    { return true; }

inline bool uauwMuCloudburstThird()
    { return true; }

inline bool uauwMuMinuteMeteorsThird()
    { return true; }

inline bool uauwMuWindWallThird()
    { return true; }

inline bool uauwMuShoutFourth()
    { return true; }

inline bool uauwMuFlamingSphereStarred()
    { return true; }

inline bool uauwMuWindWallStarred()
    { return true; }

inline bool uauwMuShoutStarred()
    { return true; }

// ---- the illusionist fragment ----
inline bool uauwIlFragmentReadsAsIllusionist()
    { return true; }

inline bool uauwIlHazeCantripListed()
    { return true; }

inline bool uauwIlRainbowFirst()
    { return true; }

inline bool uauwIlWhisperingWindSecond()
    { return true; }

inline bool uauwIlPhantomWindThird()
    { return true; }

inline bool uauwIlSolidFogFourth()
    { return true; }

inline bool uauwIlDeathFogSixth()
    { return true; }

inline bool uauwIlFragmentAllStarred()
    { return true; }

// ---- the airy-water footnote ----
inline bool uauwStarredCastableInAiryWater()
    { return true; }

// ---- the cleric altered effects ----
// Water walk (3rd): the casting causes the recipient
// to immediately bob to the surface. Magic font (5th):
// requires a glass globe of pure water as opposed to
// a font.
inline bool uauwWaterWalkBobsToSurface()
    { return true; }

inline bool uauwMagicFontNeedsGlassGlobe()
    { return true; }

// ---- the druid altered effects ----
inline bool uauwReflectingPoolAnyWaterySpace()
    { return true; }

// Transmute water to dust (6th) underwater opens a
// hole of 10 cubic feet per level of the caster; the
// surrounding water rushes in, inflicting 1-4 points
// of damage per level (no saving throw).
inline int uauwTransmuteHoleCubicFeetPerLevel()
    { return 10; }

inline int uauwTransmuteRushInDamagePerLevelDice()
    { return 4; }

inline bool uauwTransmuteNoSavingThrow()
    { return true; }

// ---- the magic-user altered effects ----
// The salt cantrip produces about 1 pint of salt
// water total; unless contained it quickly disperses
// into the surrounding water.
inline int uauwSaltCantripPints()
    { return 1; }

inline bool uauwSaltWaterDispersesUnlessContained()
    { return true; }

// Firewater (1st) floats to the top of the body of
// water and may not be ignited underwater.
inline bool uauwFirewaterFloatsToTop()
    { return true; }

inline bool uauwFirewaterNotIgnitableUnderwater()
    { return true; }

// Melf's acid arrow (2nd): the acid lasts only a
// single round, then is washed away.
inline int uauwAcidArrowLastsRounds()
    { return 1; }

inline bool uauwAcidArrowWashedAway()
    { return true; }

// Chain lightning (6th) underwater: effects as a
// lightning bolt of double normal radius but inflicts
// only 1d6 of damage per level of the caster (saving
// throw for half).
inline bool uauwChainLightningDoubleRadius()
    { return true; }

inline int uauwChainLightningDamageDicePerLevel()
    { return 6; }

inline bool uauwChainLightningSaveForHalf()
    { return true; }

inline bool uauwMuTransmuteAsDruid()
    { return true; }

// Mordenkainen's magnificent mansion (7th): at the
// caster's option the mansion can be filled with
// water, or the membrane can prevent the influx of
// water, leaving the interior tidy and dry.
inline bool uauwMansionWaterFilledOrDryOption()
    { return true; }

// Sink (8th): places a creature the given number of
// feet below the floor of the river or sea; the
// containment magic radiates through the water to the
// surface.
inline bool uauwSinkRadiatesToSurface()
    { return true; }

// ---- the illusionist altered effect ----
// Phantom steed (3rd) summoned underwater: hippocampi
// with black forebodies and silver-gray scales; no
// traveling or flying specials, but they gain the
// 4"/level movement of the phantom steed.
inline bool uauwPhantomSteedBecomesHippocampus()
    { return true; }

inline bool uauwPhantomSteedBlackForebodySilverScales()
    { return true; }

inline bool uauwPhantomSteedNoTravelOrFlySpecials()
    { return true; }

inline int uauwPhantomSteedMovementPerLevel()
    { return 4; }

}   // namespace rules

