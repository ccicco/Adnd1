// =========================================================================================
// Adnd1 - rules/wsgultra.h
// R484: the WSG ULTRAVISION and infravision effectiveness slice, printed p.
// 74 - the third vision-and-visibility round, a prose round with a pin-table
// interior (no printed grid): the infravision daylight bar, the heat-as-light
// color scale with its ten temperature bands, the surface-temperature
// perception examples, the obstruction and campfire rules, the
// extreme-climate and heat-blindness rules with the 1d6+4 recovery, the
// cold-blooded bar, and the ultravision definition with the deep gnome
// 30-yard range, the brighter-than-moonlight bar, and the five sky-condition
// range modifiers.
// census 408 -> 409.
//
// The settle: the ten temperature bands, the 98/90 human example, the 5-10
// turn (1d6+4) recovery, the deep gnome 30 yards and the 1/16 forest example
// read two-way clean (tesseract, pdfy and tsv agree on every number). The
// five sky-condition fractions were CONTESTED - both text readers garbled the
// fraction slashes (tesseract X 2/5, X 2, X s, X /s, X s; pdfy X 2/3, x 112,
// x 113, X 114, X 114) - and took six vision reads to settle: the tiny
// stacked numerals repeatedly pattern-completed to 1/2 on line one, but the
// first full-list read, the pdfy text layer (X 2/3 with a real slash) and an
// independent published transcription of the WSG list all agree on the
// descending ladder 2/3, 1/2, 1/3, 1/4, 1/4, and the book's own worked
// example (moonlit overcast x thick cover = 1/16) independently confirms both
// 1/4 entries. The artificial illumination section opens at the page bottom
// and is cut mid-word - it stays out of scope for the R485 round.
//
// Bounds held: the ten color bands tile the scale with no gaps (each interior
// low is exactly one above the previous high), the recovery dice 1d6+4 spans
// exactly 5-10, and the five modifiers descend 2/3, 1/2, 1/3, 1/4 with thick
// cover cumulative into the 1/16 forest floor.
//
namespace rules {

// ---- The infravision daylight bar ----

// infravision is useless in daylight or when the viewer or the target is
// bathed in artificial illumination stronger than moonlight
inline bool wuvUselessInDaylight()
    { return true; }

// in such cases the normally visible light overrides the heat radiation, and
// the former is all that can be sensed
inline bool wuvVisibleLightOverrides()
    { return true; }

// a character using infravision sees heat as light
inline bool wuvSeesHeatAsLight()
    { return true; }

// ---- The heat-as-light color scale ----

// the infravisual color scale runs from 1
inline int wuvColorScaleMin()
    { return 1; }

// to 10
inline int wuvColorScaleMax()
    { return 10; }

// very cold objects are very dark, hot objects are very bright, and
// temperatures between the extremes are varying shades of gray
inline bool wuvColdDarkHotBright()
    { return true; }

// color 1 on the scale is pitch black
inline bool wuvScale1PitchBlack()
    { return true; }

// color 10 on the scale is excruciatingly bright
inline bool wuvScale10Excruciating()
    { return true; }

// color 2: -50 to -11 (the very-cold floor is below -50)
inline int wuvBand2Low()
    { return -50; }

// color 2 upper bound
inline int wuvBand2High()
    { return -11; }

// color 3: -10 to 15
inline int wuvBand3Low()
    { return -10; }

// color 3 upper bound
inline int wuvBand3High()
    { return 15; }

// color 4: 16 to 32
inline int wuvBand4Low()
    { return 16; }

// color 4 upper bound
inline int wuvBand4High()
    { return 32; }

// color 5: 33 to 50
inline int wuvBand5Low()
    { return 33; }

// color 5 upper bound
inline int wuvBand5High()
    { return 50; }

// color 6: 51 to 70
inline int wuvBand6Low()
    { return 51; }

// color 6 upper bound
inline int wuvBand6High()
    { return 70; }

// color 7: 71 to 90
inline int wuvBand7Low()
    { return 71; }

// color 7 upper bound
inline int wuvBand7High()
    { return 90; }

// color 8: 91 to 110
inline int wuvBand8Low()
    { return 91; }

// color 8 upper bound
inline int wuvBand8High()
    { return 110; }

// color 9: 111 to 130
inline int wuvBand9Low()
    { return 111; }

// color 9 upper bound (above 130 is color 10)
inline int wuvBand9High()
    { return 130; }

// ---- The surface temperature examples ----

// the first thing to consider is the temperature of the air, which dictates
// the overall level of brightness perceived
inline bool wuvAirTempDictates()
    { return true; }

// an object or creature with a surface temperature warmer or colder than the
// air appears as a brighter or darker image against the backdrop of the
// atmosphere
inline bool wuvWarmerColderShows()
    { return true; }

// human body temperature approximately 98 degrees
inline int wuvHumanBodyTempF()
    { return 98; }

// a normally clothed human appears brighter than his surroundings when the
// air temperature is 90 or lower
inline int wuvBrightBelowAirF()
    { return 90; }

// a human in nothing thicker than normal clothing appears brighter than his
// surroundings when the air temperature is 90 or lower
inline bool wuvHumanBrightAt90OrBelow()
    { return true; }

// the same holds true for demi-humans and most size M humanoids with roughly
// human body temperatures
inline bool wuvDemiHumanSameRule()
    { return true; }

// a human completely bundled in heavy clothing has the same surface
// temperature as the surrounding air and is not detectable by infravision
inline bool wuvBundledUndetectable()
    { return true; }

// if just a small part of the body (such as the face or hands) is uncovered,
// those areas appear as small spots of brightness
inline bool wuvUncoveredSpotsShow()
    { return true; }

// or of darkness, if the air temperature is very high
inline bool wuvUncoveredDarkIfHot()
    { return true; }

// ---- The obstruction and campfire rules ----

// in most cases infravision will not detect an object or creature when the
// line of sight is obstructed - a man crouched behind a large rock is
// invisible, just as to normal vision
inline bool wuvObstructionBlocks()
    { return true; }

// an object or creature giving off a great amount of heat or cold might be
// indirectly detectable because its presence changes the temperature of the
// surrounding air
inline bool wuvStrongHeatIndirect()
    { return true; }

// a campfire built behind a large rock warms the air, and the side of the
// rock facing the viewer appears as a dark shape outlined against a lighter
// background
inline bool wuvCampfireRockExample()
    { return true; }

// ---- The extremes and heat blindness ----

// extreme heat or extreme cold renders infravision useless when everything in
// the range of vision is effectively at the same temperature
inline bool wuvExtremeSameTempUseless()
    { return true; }

// in a very cold climate, temperature lower than -50 degrees, everything
// appears pitch black
inline bool wuvVeryColdPitchBlack()
    { return true; }

// in a very hot climate, temperature higher than 130, infravision detects
// nothing but a blanket of almost blinding brightness
inline bool wuvVeryHotBlinding()
    { return true; }

// a character using infravision can be afflicted by heat blindness if he
// suddenly finds himself in close proximity to a large fire or a source of
// great heat
inline bool wuvHeatBlindnessRisk()
    { return true; }

// a wall of fire springing up in front of an infraviewer burns out his
// infravision and renders the power useless until cure blindness or similar
// healing magic is applied
inline bool wuvWallOfFireBurnout()
    { return true; }

// in a less extreme case the viewer is only temporarily blinded to infrared
// rays while his eyes recover from the shock
inline bool wuvTempBlindRecover()
    { return true; }

// temporary infrared blindness lasts at least 5 turns
inline int wuvTempBlindMinTurns()
    { return 5; }

// and at most 10 turns
inline int wuvTempBlindMaxTurns()
    { return 10; }

// the recovery period is 1d6
inline int wuvTempBlindDice()
    { return 6; }

// plus 4 turns
inline int wuvTempBlindPlus()
    { return 4; }

// ---- The cold-blooded bar ----

// infravision will not detect cold-blooded creatures (reptiles, insects, and
// most other nonmammalian creatures) because their temperature is the same as
// that of the surrounding air
inline bool wuvColdBloodedUndetected()
    { return true; }

// if magic abruptly changes the temperature of the surrounding air, a
// cold-blooded creature stands out against the background for a short time
// because its body temperature does not change that quickly
inline bool wuvMagicTempReveals()
    { return true; }

// ---- The ultravision definition and ranges ----

// ultravision, or night vision, is the ability to see into the ultraviolet
// range of the spectrum and thereby distinguish objects from their
// surroundings even in darkness
inline bool wuvNightVisionDefinition()
    { return true; }

// for an ultraviewer the word darkness takes on a different meaning: he can
// distinguish colors, shapes, and the relative position of objects even in
// the absence of light in the normal visible spectrum
inline bool wuvDarknessRedefined()
    { return true; }

// only one character race, the deep gnome, has inborn ultravisual
// capabilities
inline bool wuvDeepGnomeOnly()
    { return true; }

// the deep gnome has inborn night vision to a range of 30 yards
inline int wuvDeepGnomeRangeYards()
    { return 30; }

// objects within the deep gnome's night vision range are visible to him just
// as if he was using normal vision during daylight
inline bool wuvDeepGnomeDaylightQuality()
    { return true; }

// other characters can acquire ultravision temporarily through magical means,
// such as a lens of ultravision and the ultravision spell, cast by a
// magic-user or an illusionist
inline bool wuvMagicalAcquisition()
    { return true; }

// the exact capabilities bestowed by magical ultravision (range and amount of
// illumination perceived) vary depending on the means employed
inline bool wuvMagicalCapabilitiesVary()
    { return true; }

// as with infravision, ultravision is useless when the viewer or the target
// is illuminated by any light source brighter than moonlight
inline bool wuvUltraUselessInLight()
    { return true; }

// a character trying to use ultravision in daylight or in an area affected by
// artificial illumination sees nothing but blackness
inline bool wuvUltraDaylightBlackness()
    { return true; }

// ---- The sky-condition range modifiers ----

// ultravision works best during a moonless night under a clear sky
inline bool wuvBestMoonlessClear()
    { return true; }

// moonless night partly cloudy: x 2/3, numerator
inline int wuvMoonlessCloudyNum()
    { return 2; }

// x 2/3, denominator
inline int wuvMoonlessCloudyDen()
    { return 3; }

// moonless night overcast: x 1/2, numerator
inline int wuvMoonlessOvercastNum()
    { return 1; }

// x 1/2, denominator
inline int wuvMoonlessOvercastDen()
    { return 2; }

// moonlight partly cloudy: x 1/3, numerator
inline int wuvMoonlightCloudyNum()
    { return 1; }

// x 1/3, denominator
inline int wuvMoonlightCloudyDen()
    { return 3; }

// moonlight overcast: x 1/4, numerator
inline int wuvMoonlightOvercastNum()
    { return 1; }

// x 1/4, denominator
inline int wuvMoonlightOvercastDen()
    { return 4; }

// viewer standing under thick cover: x 1/4, numerator
inline int wuvThickCoverNum()
    { return 1; }

// x 1/4, denominator
inline int wuvThickCoverDen()
    { return 4; }

// the thick-cover modifier is cumulative with any other modifier that applies
inline bool wuvThickCoverCumulative()
    { return true; }

// the worked example: thick forest on a moonlit overcast night = 1/16 of
// ideal range
inline int wuvForestExampleNum()
    { return 1; }

// 1/16, the cumulative product
inline int wuvForestExampleDen()
    { return 16; }

}   // namespace rules
