// ===========================================================================
// Adnd1 - rules/uaarmprose.h
// The UA TREASURE (ARMOR AND
// SHIELD / SWORDS) prose pins,
// R387: the pp. 104-105
// stretch - eight pins, four
// fully clean (the anything
// armor, the short sword of
// quickness, the sword of the
// planes, the anything sword)
// plus four mechanics-clean
// with flagged holes (the
// elfin chain mail's
// size-table garble, the
// plate's conform seam, the
// sun blade's radiance seam,
// the Final Word broadswords'
// names tail), riding the
// construction rule (+3
// meteorite iron, +4 mithral
// alloyed, +5 adamantite
// alloyed steel). Nothing
// fully garbles; the part-6
// and skeleton seams ride in
// the regtest audit, not
// here.
namespace rules {

// ---- the construction rule
// ----
// Except where this obviously
// does not apply (such as for
// leather armor +3), armor of
// +3 bonus is of special
// meteorite iron steel, +4 is
// mithral alloyed steel, and
// +5 is adamantite alloyed
// steel.
inline int uaaspCnsBonus3Material()
    { return 3; }

inline bool uaaspCnsBonus3MeteoriteIron()
    { return true; }

inline int uaaspCnsBonus4Material()
    { return 4; }

inline bool uaaspCnsBonus4MithralAlloyed()
    { return true; }

inline int uaaspCnsBonus5Material()
    { return 5; }

inline bool uaaspCnsBonus5AdamantiteAlloyed()
    { return true; }

// ---- the anything armor
// ----
// Any construction, leather to
// plate; originally appears
// with a +1 dweomer.
inline bool uaaspAamAnyConstruction()
    { return true; }

inline int uaaspAamOriginalBonus()
    { return 1; }

// Upon command it becomes any
// sort of other normal
// magical armor - one of the
// types listed on the tables,
// not necessarily of the same
// construction; each such
// change is singular, a
// specific type never formed
// more than once.
inline bool uaaspAamChangesOnCommand()
    { return true; }

inline bool uaaspAamTypeNeedNotMatchConstruction()
    { return true; }

inline bool uaaspAamEachChangeSingular()
    { return true; }

inline bool uaaspAamNoTypeTwice()
    { return true; }

// A change into a non-special
// sort of armor lasts 1 day
// (24 hours) before reverting
// to the usual +1 status; a
// change into a
// special-function type (such
// as plate mail of
// etherealness) lasts but 1
// hour.
inline int uaaspAamNonSpecialChangeHours()
    { return 24; }

inline bool uaaspAamNonSpecialLastsOneDay()
    { return true; }

inline bool uaaspAamRevertsToPlusOne()
    { return true; }

inline int uaaspAamSpecialChangeHours()
    { return 1; }

// After the possessor has
// commanded three different
// changes, the armor loses
// all of its magical
// properties.
inline int uaaspAamChangesAllowed()
    { return 3; }

inline bool uaaspAamLosesAllMagicAfter()
    { return true; }

// ---- the elfin chain mail
// ----
// So fine and light it can be
// worn under normal clothing
// without revealing it;
// thieves can utilize it,
// though it may slightly
// hinder their activities;
// rarely sized for anyone
// other than an elf or a
// half-elf.
inline bool uaaspEcmWornUnderClothing()
    { return true; }

inline bool uaaspEcmThievesCanUtilize()
    { return true; }

inline bool uaaspEcmMaySlightlyHinder()
    { return true; }

inline bool uaaspEcmRareForNonElves()
    { return true; }

// The size table
// OCR-scrambles (the header
// and row labels
// dislocate); the
// reconstruction: five rows -
// 01-10 hairfoot, 11-15
// dwarf/halfling (stout or
// tallfellow), 16-80
// elf/half-elf, 81-95
// man-sized normal (up to 6
// feet, 200 lbs.), 96-00
// man-sized large (up to 250
// lbs.); flagged.
inline int uaaspEcmSizeTableRows()
    { return 5; }

inline int uaaspEcmHairfootLo()
    { return 1; }

inline int uaaspEcmHairfootHi()
    { return 10; }

inline int uaaspEcmDwarfHalflingLo()
    { return 11; }

inline int uaaspEcmDwarfHalflingHi()
    { return 15; }

inline int uaaspEcmElfHalfElfLo()
    { return 16; }

inline int uaaspEcmElfHalfElfHi()
    { return 80; }

inline int uaaspEcmManNormalLo()
    { return 81; }

inline int uaaspEcmManNormalHi()
    { return 95; }

inline int uaaspEcmManLargeLo()
    { return 96; }

inline int uaaspEcmManLargeHi()
    { return 100; }

inline int uaaspEcmManNormalLbs()
    { return 200; }

inline int uaaspEcmManLargeLbs()
    { return 250; }

inline bool uaaspEcmSizeTableGarbles()
    { return true; }

// ---- the plate ----
// Field plate or full plate,
// as shown on Armor Table
// III.F.2; the dweomer
// perfectly conforms to the
// wearer's physical
// dimensions, so long as the
// wearer is of the race the
// armor was manufactured
// for; the conform sentence
// OCR-scrambles; flagged.
inline bool uaaspPltFieldOrFullPlate()
    { return true; }

inline bool uaaspPltConformsToWearer()
    { return true; }

inline bool uaaspPltSameRaceRequired()
    { return true; }

inline bool uaaspPltConformSeamGarbles()
    { return true; }

// Magical plate absorbs more
// damage than non-magical of
// the same sort: field plate
// an additional 10 points of
// damage per plus, full plate
// an additional 16 per plus.
inline int uaaspPltFieldAbsorbPerPlus()
    { return 10; }

inline int uaaspPltFullAbsorbPerPlus()
    { return 16; }

// Repairs after absorbing
// the limit, at non-magical
// costs: field plate 1 day
// and 100 gp per point of
// damage absorption, full
// plate 2 days and 200 gp per
// point; only an armorer
// well versed in the
// creation and repair of
// magical protection can
// make them.
inline int uaaspPltFieldRepairDays()
    { return 1; }

inline int uaaspPltFieldRepairGp()
    { return 100; }

inline int uaaspPltFullRepairDays()
    { return 2; }

inline int uaaspPltFullRepairGp()
    { return 200; }

inline bool uaaspPltRepairsNeedMagicArmorer()
    { return true; }

// ---- the short sword of
// quickness ----
// A specially dweomered blade
// enabling the wielder to
// strike first in every
// combat round; also a +2
// magic weapon, the bonus
// applicable to both hitting
// and damage.
inline bool uaaspQswStrikesFirstEveryRound()
    { return true; }

inline int uaaspQswBonus()
    { return 2; }

inline bool uaaspQswBonusToHitAndDamage()
    { return true; }

// ---- the sword of the
// planes ----
// Forged only as a
// broadsword; +1 on the
// Prime Material Plane; +2
// on any Inner Plane, and
// also on the Prime against
// opponents from the Inner
// Planes; +3 on an Outer
// Plane or against creatures
// from the Outer Planes; +4
// on the Astral or Ethereal
// Plane or against
// opponents from either.
inline bool uaaspPlnBroadswordOnly()
    { return true; }

inline int uaaspPlnPrimeBonus()
    { return 1; }

inline int uaaspPlnInnerPlanesBonus()
    { return 2; }

inline bool uaaspPlnInnerAppliesVsOpponents()
    { return true; }

inline int uaaspPlnOuterPlanesBonus()
    { return 3; }

inline bool uaaspPlnOuterAppliesVsOpponents()
    { return true; }

inline int uaaspPlnAstralEtherealBonus()
    { return 4; }

inline bool uaaspPlnAstralAppliesVsOpponents()
    { return true; }

// ---- the sun blade ----
// All of great size, treated
// as bastard swords; wielded
// as if short swords with
// respect to encumbrance,
// weight, speed factor, and
// ease of use; anyone able to
// use either a bastard sword
// or a short sword with
// proficiency or expertise can
// use one.
inline bool uaaspSubTreatedAsBastard()
    { return true; }

inline bool uaaspSubWieldedAsShortSword()
    { return true; }

inline bool uaaspSubEitherProficiencyServes()
    { return true; }

// In normal combat the
// glowing golden blade equals
// a +2 magic sword; against
// evil creatures the bonus
// doubles to +4; against
// creatures from the Negative
// Material Plane or those
// drawing power from it (many
// of the undead), double
// normal damage regardless of
// the +2 or +4 bonus.
inline int uaaspSubNormalBonus()
    { return 2; }

inline int uaaspSubEvilBonus()
    { return 4; }

inline bool uaaspSubDoubleDamageVsNegative()
    { return true; }

// The radiance sentence
// OCR-scrambles; the
// reconstruction: upon
// command the blade is swung
// through the air, shedding a
// bright yellow radiance
// equaling full daylight;
// flagged.
inline bool uaaspSubRadianceOnCommand()
    { return true; }

inline bool uaaspSubRadianceSeamGarbles()
    { return true; }

// The radiance begins within
// a 10-foot radius, spreads
// outward at 5 feet per round
// for 10 rounds - engulfing a
// 60-foot radius - then fades
// to a dim glow persisting
// another 10 rounds before
// disappearing; once per day;
// all sun blades are of good
// alignment.
inline int uaaspSubRadianceStartFt()
    { return 10; }

inline int uaaspSubRadianceSpreadPerRoundFt()
    { return 5; }

inline int uaaspSubRadianceSpreadRounds()
    { return 10; }

inline int uaaspSubRadianceFullRadiusFt()
    { return 60; }

inline int uaaspSubDimGlowRounds()
    { return 10; }

inline bool uaaspSubOncePerDay()
    { return true; }

inline bool uaaspSubGoodAlignment()
    { return true; }

// ---- the anything sword
// ----
// Originally appears a sword
// +1 of any type - short,
// long, etc.; upon command
// changes into any desired
// type of magic sword of any
// power (for instance, from a
// short sword +1 to a holy
// avenger +5 of long,
// bastard, or even
// two-handed sort).
inline int uaaspAswOriginalBonus()
    { return 1; }

inline bool uaaspAswAnyOriginalType()
    { return true; }

inline bool uaaspAswChangesOnCommand()
    { return true; }

inline bool uaaspAswAnyPower()
    { return true; }

inline int uaaspAswExampleAvengerBonus()
    { return 5; }

// The commanded form remains
// 1 day (24 hours) or until
// it performs a special,
// highly powerful function
// such as draining a level or
// severing some body part.
inline int uaaspAswFormHours()
    { return 24; }

inline bool uaaspAswEndsOnSpecialFunction()
    { return true; }

// Commanded to assume another
// form no more than three
// times; each form is
// singular and may not be
// repeated - a dancing sword
// but once, a frost brand but
// once, a vorpal blade but
// once; after the third change
// and reverting, an ordinary
// blade; never has
// intelligence, ego,
// communication power, or any
// other special ability.
inline int uaaspAswChangesAllowed()
    { return 3; }

inline bool uaaspAswEachFormSingular()
    { return true; }

inline bool uaaspAswNoFormRepeated()
    { return true; }

inline bool uaaspAswOrdinaryAfterThird()
    { return true; }

inline bool uaaspAswNeverIntelligent()
    { return true; }

// ---- the Final Word
// broadswords ----
// Very rare - only nine known
// to exist; each patterned
// after the legendary
// broadsword Fragarach,
// which means "final word" in
// the tongue of the ancient
// Oeridians; each thought to
// have a differing alignment,
// but in all other respects
// alike.
inline int uaaspFwbKnownCount()
    { return 9; }

inline bool uaaspFwbPatternedAfterFragarach()
    { return true; }

inline bool uaaspFwbFragarachMeansFinalWord()
    { return true; }

inline bool uaaspFwbDifferingAlignments()
    { return true; }

// A creature of an alignment
// different from the sword's
// attempting to wield it in
// battle gets no bonuses; in
// the hands of a like-aligned
// creature it becomes a +3
// blade which always strikes
// last in any round.
inline bool uaaspFwbUnlikeAlignmentNoBonuses()
    { return true; }

inline int uaaspFwbLikeAlignmentBonus()
    { return 3; }

inline bool uaaspFwbAlwaysStrikesLast()
    { return true; }

// It strikes unerringly and
// does damage to any opponent
// that struck at the wielder
// earlier in the same round,
// regardless of whether the
// opponent successfully hit,
// up to the wielder's
// allowable number of attacks
// per round; opponents immune
// to weapons of less than +4
// value are not harmed.
inline bool uaaspFwbUnerringCounterstrike()
    { return true; }

inline bool uaaspFwbCounterstrikesHitOrMiss()
    { return true; }

inline bool uaaspFwbUpToWielderAttacks()
    { return true; }

inline bool uaaspFwbPlus3Only()
    { return true; }

// Each has a gem of 10,000 gp
// value set in its pommel,
// each gem different in type
// from all the others; each
// bears an identifying name -
// the nine-appellations list
// OCR-scrambles; flagged.
inline int uaaspFwbPommelGemGp()
    { return 10000; }

inline bool uaaspFwbEachGemDifferent()
    { return true; }

inline bool uaaspFwbNamesTailGarbles()
    { return true; }

// ---- the part ledger ----
// Eight items: four fully
// clean, four flagged, none
// fully garbled.
inline int uaaspPartItemTotal()
    { return 8; }

inline int uaaspPartCleanCount()
    { return 4; }

inline int uaaspPartFlaggedCount()
    { return 4; }

inline int uaaspPartGarbledCount()
    { return 0; }

}   // namespace rules

