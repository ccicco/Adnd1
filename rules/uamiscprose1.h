// ===========================================================================
// Adnd1 - rules/uamiscprose1.h
// The UA TREASURE
// (MISCELLANEOUS MAGIC) prose
// pins, part 1, R381: the
// A-C items (pp. 97-100) -
// thirteen pins, eight fully
// clean (beads of force,
// boots of the north, boots
// winged, bracers of archery,
// bracers of brachiation,
// cloak of arachnidia, cloak
// of the bat, cyclocone) and
// five mechanics-clean with
// flagged holes (the amulet
// versus undead's 9th-level
// cell, the anything item's
// tail, the boccob book's
// save cell and scribing
// tail, the boots of varied
// tracks' row-one print, the
// chime of interruption's
// opening). Nothing in A-C
// fully garbles; D-Z rides
// the later parts. The wands
// and skeleton seams ride in
// the regtest audit, not
// here.
namespace rules {

// ---- the amulet versus
// undead ----
// A specially blessed symbol
// that turns undead as a
// cleric of its effective
// level; glows when
// presented strongly in the
// presence of undead.
inline bool uammAmuTurnsAsCleric()
    { return true; }

inline bool uammAmuGlowsWhenPresented()
    { return true; }

// The five strength bands:
// 01-30 5th, 31-55 6th,
// 56-75 7th, 76-90 8th,
// 91-00 9th - the 9th cell
// OCR-garbles ("Sth"), the
// sequence pins it; flagged.
inline int uammAmuBandCount()
    { return 5; }

inline int uammAmuLevelForBand(int i) {
    static const int k[5] = {
        5, 6, 7, 8, 9};
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

inline int uammAmuBandLo(int i) {
    static const int k[5] = {
        1, 31, 56, 76, 91};
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

inline int uammAmuBandHi(int i) {
    static const int k[5] = {
        30, 55, 75, 90, 100};
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

inline bool uammAmuNinthCellGarbles()
    { return true; }

// Must be worn at all times;
// inert when not worn, and
// inert for the first seven
// days after it is put on.
inline bool uammAmuMustBeWorn()
    { return true; }

inline bool uammAmuInertWhenNotWorn()
    { return true; }

inline int uammAmuInertDaysOnDonning()
    { return 7; }

// The value rides the
// effective level: 200 x.p.,
// 1,000 gp sale, per level.
inline int uammAmuXpPerLevel()
    { return 200; }

inline int uammAmuGpPerLevel()
    { return 1000; }

// ---- the anything item ----
// Appears as one of the small,
// weak, frequently-found
// misc items; on command
// becomes any other misc
// magic item except an
// artifact or relic.
inline bool uammAnyBecomesAnyMiscItem()
    { return true; }

inline bool uammAnyExcludesArtifactsRelics()
    { return true; }

inline bool uammAnyNoFormRepeated()
    { return true; }

// If the commanded form is
// normally destroyed in
// usage, the anything item
// is destroyed likewise.
inline bool uammAnyDiesWithDestructiveForms()
    { return true; }

// Short-term single-usage
// forms (a horn, drums)
// return it to original after
// one use; long-term forms
// see it disappear after
// three uses - the tail
// sentence OCR-scrambles, the
// mechanics read; flagged.
inline bool uammAnyShortTermReturnsOnce()
    { return true; }

inline bool uammAnyLongTermDisappears()
    { return true; }

inline int uammAnyLongTermUseLimit()
    { return 3; }

inline bool uammAnyTailGarbles()
    { return true; }

// ---- the beads of force ----
// A small black sphere,
// three-quarters of an inch
// across, nearly an ounce;
// hurled up to 3".
inline int uammBeaDiamEighthIn()
    { return 6; }

inline int uammBeaWeightOunces()
    { return 1; }

inline int uammBeaHurlRangeIn()
    { return 3; }

// On impact: 5-20 (5d4) to
// all within a 10-foot radius,
// save versus spell - savers
// thrown clear, failers
// encapsulated after taking
// the damage.
inline int uammBeaDmgDice()
    { return 5; }

inline int uammBeaDmgLo()
    { return 5; }

inline int uammBeaDmgHi()
    { return 20; }

inline int uammBeaBlastRadiusFt()
    { return 10; }

inline bool uammBeaSaveIsVsSpell()
    { return true; }

inline bool uammBeaSaversThrownClear()
    { return true; }

inline bool uammBeaFailersEncapsulated()
    { return true; }

// The sphere of force holds
// 3-12 rounds, even around
// large creatures; escape
// only as from a wall of
// force.
inline int uammBeaSphereLoRounds()
    { return 3; }

inline int uammBeaSphereHiRounds()
    { return 12; }

inline bool uammBeaEscapeOnlyAsWallOfForce()
    { return true; }

// Five to eight beads are
// usually found together.
inline int uammBeaFoundLo()
    { return 5; }

inline int uammBeaFoundHi()
    { return 8; }

// ---- boccob's blessed book
// ----
// A small durable tome: no
// more than 12 inches tall,
// 6 wide, 1 thick; some a
// mere 6 inches in height.
inline int uammBocMaxHeightIn()
    { return 12; }

inline int uammBocWidthIn()
    { return 6; }

inline int uammBocThickIn()
    { return 1; }

inline int uammBocSomeMereHeightIn()
    { return 6; }

inline bool uammBocWaterproofBoundLocked()
    { return true; }

// +3 on saving throws - the
// save-category cell ("leather
// or ...") OCR-truncates,
// flagged.
inline int uammBocSaveBonus()
    { return 3; }

inline bool uammBocSaveCellGarbles()
    { return true; }

// The pages accept scribed
// spells; a book holds up to
// 45 levels - prized as a
// travelling spell book; the
// enscribing tail garbles,
// flagged.
inline int uammBocMaxSpellLevels()
    { return 45; }

inline bool uammBocPrizedAsTravellingBook()
    { return true; }

inline bool uammBocScribingTailGarbles()
    { return true; }

// ---- the boots of the north
// ----
// Snow travel at normal rate
// leaving no tracks; half
// normal rate on the most
// slippery ice, horizontal
// surfaces only.
inline bool uammBnSnowNormalNoTracks()
    { return true; }

inline bool uammBnIceHalfRateHorizontal()
    { return true; }

// Warmth: -50 F in scant
// clothing; -100 F fully
// dressed in cold-weather
// gear.
inline int uammBnScantClothingMinF()
    { return -50; }

inline int uammBnFullDressMinF()
    { return -100; }

// ---- the boots of varied
// tracks ----
// On command the wearer's
// tracks alter: as small as a
// halfling's, as large as an
// ogre's, bare or shod.
inline bool uammBvtCommandAltersTracks()
    { return true; }

inline bool uammBvtSmallAsHalfling()
    { return true; }

inline bool uammBvtLargeAsOgre()
    { return true; }

inline bool uammBvtBareOrShod()
    { return true; }

// Each pair carries four
// capabilities from the
// 16-entry track table; the
// table's row-one print
// OCR-garbles, the other
// fifteen read; flagged.
inline int uammBvtCapabilitiesPerPair()
    { return 4; }

inline int uammBvtTrackTableCount()
    { return 16; }

inline bool uammBvtRowOnePrintGarbles()
    { return true; }

// ---- the boots, winged ----
// Up to two hours of flight
// per day, at once or split;
// past the limit the power
// fades slowly, a gentle
// descent.
inline int uammBwMaxHoursPerDay()
    { return 2; }

inline bool uammBwFadeSlowlyPastLimit()
    { return true; }

// Twelve hours of non-use
// regain one flying hour;
// never above the two-hour
// maximum.
inline int uammBwRestHoursPerChargeHour()
    { return 12; }

inline bool uammBwNeverAboveMax()
    { return true; }

// The four types by die roll:
// 1: 15" MC A, 2: 18" B,
// 3: 21" C, 4: 24" D - the
// die column carries minor
// OCR, the mapping pins;
// flagged.
inline int uammBwTypeCount()
    { return 4; }

inline int uammBwSpeedForRoll(int r) {
    static const int k[4] = {
        15, 18, 21, 24};
    if (r < 1) return 0;
    if (r > 4) return 0;
    return k[r - 1];
}

inline char uammBwMcForRoll(int r) {
    static const char k[4] = {
        'A', 'B', 'C', 'D'};
    if (r < 1) return ' ';
    if (r > 4) return ' ';
    return k[r - 1];
}

inline bool uammBwDieCellsMinorOcr()
    { return true; }

// ---- the bracers of
// archery ----
// For bow-able wearers
// (crossbows excluded):
// grants proficiency if
// lacking; with proficiency
// in the bow type used:
// +2 to hit, +1 to damage.
inline bool uammBaWorksForBowUsers()
    { return true; }

inline bool uammBaExcludesCrossbows()
    { return true; }

inline bool uammBaGrantsProficiencyIfLacking()
    { return true; }

inline int uammBaProficientHitBonus()
    { return 2; }

inline int uammBaProficientDmgBonus()
    { return 1; }

// The bonuses are cumulative
// with all others except
// weapon specialization.
inline bool uammBaCumulativeExceptSpecialization()
    { return true; }

// ---- the bracers of
// brachiation ----
// Movement by brachiation
// where hand-holds exist:
// 3", 6", or 9" by how
// jungle-like the locale.
inline bool uammBbNeedsHandholds()
    { return true; }

inline int uammBbMoveRatesCount()
    { return 3; }

inline int uammBbMoveLoIn()
    { return 3; }

inline int uammBbMoveHiIn()
    { return 9; }

// Climbs trees, vines, poles,
// ropes at 6"; swings as a
// simian; leaps and jumps as
// boots of striding and
// springing, but the jump
// must culminate in a
// brachiation-related
// activity.
inline int uammBbClimbRateIn()
    { return 6; }

inline bool uammBbSwingsAsSimian()
    { return true; }

inline bool uammBbJumpsAsStridingSpringing()
    { return true; }

inline bool uammBbJumpMustCulminate()
    { return true; }

// ---- the chime of
// interruption ----
// The opening sentence
// OCR-scrambles - the item
// name garbles into the
// mechanics; flagged. Struck
// only once per turn; the
// resonant tone lasts three
// full rounds.
inline bool uammChiOpeningGarbles()
    { return true; }

inline int uammChiStrikesPerTurn()
    { return 1; }

inline int uammChiToneRounds()
    { return 3; }

// While resonating: no
// verbal-component spell
// within a 30-foot radius
// unless the caster saves
// versus breath weapon.
inline int uammChiVerbalBlockRadiusFt()
    { return 30; }

inline bool uammChiBlockSaveIsVsBreath()
    { return true; }

// After the tone fades the
// chime rests at least 7
// rounds; an early strike
// sounds nothing and waits
// a full turn from that
// point.
inline int uammChiRestRounds()
    { return 7; }

inline bool uammChiEarlyStrikeSilent()
    { return true; }

inline int uammChiEarlyStrikeWaitTurns()
    { return 1; }

// ---- the cloak of
// arachnidia ----
// A strong alteration aura;
// the wearer climbs as
// spider climb, immune to
// web entrapment, moving in
// webs at the creator
// spider's rate or base 6".
inline bool uammCaStrongAlterationAura()
    { return true; }

inline bool uammCaGrantsSpiderClimb()
    { return true; }

inline bool uammCaImmuneToWebs()
    { return true; }

inline int uammCaWebMoveBaseIn()
    { return 6; }

// Once per day a
// double-sized web, as the
// 2nd-level magic-user
// spell; +2 on saves versus
// arachnid poison.
inline int uammCaDoubleWebPerDay()
    { return 1; }

inline int uammCaDoubleWebSpellLevel()
    { return 2; }

inline int uammCaSaveVsArachnidPoison()
    { return 2; }

// ---- the cloak of the bat
// ----
// 90% invisible when
// stationary in shadow or
// darkness; the wearer may
// hang upside down keeping
// the chance.
inline int uammCbInvisibilityPct()
    { return 90; }

inline bool uammCbStationaryInShadowOrDark()
    { return true; }

inline bool uammCbHangsUpsideDown()
    { return true; }

// Holding the edges: fly at
// 15" (MC B); or transform
// into an ordinary bat, all
// possessions riding along.
inline int uammCbFlySpeedIn()
    { return 15; }

inline char uammCbFlyMcClass()
    { return 'B'; }

inline bool uammCbBatTransformation()
    { return true; }

// Flying, either way, only in
// darkness; up to one hour
// at a time, then no flight
// for a like period.
inline bool uammCbFlightDarknessOnly()
    { return true; }

inline int uammCbFlightMaxHours()
    { return 1; }

inline bool uammCbRestEqualsFlight()
    { return true; }

// Protection as a robe of
// protection at +2, holding
// even in bat form.
inline int uammCbProtectionBonus()
    { return 2; }

inline bool uammCbProtectionHoldsInBatForm()
    { return true; }

// ---- the cyclocone ----
// An ordinary pointed hat
// radiating dim evocation;
// magic-user only, tossed
// with a spinning motion.
inline bool uammCyDimEvocationAura()
    { return true; }

inline bool uammCyMuOnly()
    { return true; }

// The whirlwind: 5 feet wide
// at the base, 15 at the
// top, up to 45 high; forms
// within 1-4 segments.
inline int uammCyBaseWidthFt()
    { return 5; }

inline int uammCyTopWidthFt()
    { return 15; }

inline int uammCyMaxHeightFt()
    { return 45; }

inline int uammCyFormSegsLo()
    { return 1; }

inline int uammCyFormSegsHi()
    { return 4; }

// It sweeps straight at 18"
// for one full round, until
// a solid sturdy object
// breaks it up - a living
// breaker takes the damage.
inline int uammCyMoveRateIn()
    { return 18; }

inline int uammCyDurationRounds()
    { return 1; }

inline bool uammCySturdyObjectBreaksIt()
    { return true; }

inline bool uammCyBreakerTakesDamage()
    { return true; }

// Creatures under 2+1 hit
// dice caught or touched:
// instantly killed and
// carried along; others take
// 4-16; within 5 feet of the
// outer edge at formation:
// 2-8.
inline bool uammCyInstantKillBelowTwoPlusOne()
    { return true; }

inline int uammCyCaughtDmgLo()
    { return 4; }

inline int uammCyCaughtDmgHi()
    { return 16; }

inline int uammCyEdgeRangeFt()
    { return 5; }

inline int uammCyEdgeDmgLo()
    { return 2; }

inline int uammCyEdgeDmgHi()
    { return 8; }

// Not reusable - destroyed
// when the whirlwind
// dissipates.
inline bool uammCyNotReusable()
    { return true; }

// ---- the part ledger ----
// Thirteen A-C items: eight
// fully clean, five
// mechanics-clean with
// flagged holes, none fully
// garbled.
inline int uammPartItemTotal()
    { return 13; }

inline int uammPartCleanCount()
    { return 8; }

inline int uammPartFlaggedCount()
    { return 5; }

inline int uammPartGarbledCount()
    { return 0; }

}   // namespace rules

