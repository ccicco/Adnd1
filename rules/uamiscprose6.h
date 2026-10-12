// ===========================================================================
// Adnd1 - rules/uamiscprose6.h
// The UA TREASURE
// (MISCELLANEOUS MAGIC) prose
// pins, part 6, R386: the
// S-Z close-out - five pins,
// two fully clean (the wind
// fan, Zagyg's flowing
// flagon) plus three
// mechanics-clean with
// flagged holes (the stone
// horse's activation word
// seam, the ultimate
// solution's transmutation
// seam, Zagyg's spell
// component case's gp tail).
// Nothing in S-Z fully
// garbles; with parts 1-5
// the prose stands pinned
// A-Z. The part-5 and
// skeleton seams ride in
// the regtest audit, not
// here.
namespace rules {

// ---- the stone horse ----
// A full-sized, roughly-hewn
// statue of a horse carved
// from some type of hard
// stone; two sorts exist.
inline bool uamm6ShStatueAppearance()
    { return true; }

inline bool uamm6ShCarvedFromHardStone()
    { return true; }

inline int uamm6ShTwoSorts()
    { return 2; }

// The activation-word
// sentence OCR-scrambles;
// the reconstruction: the
// dweomer activates on a
// spoken word, bringing the
// steed to animation,
// enabling it to carry a
// burden and attack as a
// warhorse; flagged.
inline bool uamm6ShActivationWord()
    { return true; }

inline bool uamm6ShAnimateCarryAttack()
    { return true; }

inline bool uamm6ShActivationSeamGarbles()
    { return true; }

// A stone horse carries
// 1,000 pounds tirelessly
// and never needs to rest
// or feed.
inline int uamm6ShCarriesLbs()
    { return 1000; }

inline bool uamm6ShTirelessNoFeeding()
    { return true; }

// Damage repaired by first
// using a stone to flesh
// spell, turning it into a
// normal horse; grazing and
// resting, it heals 1 point
// per day and automatically
// reverts to magical form
// when fully healed.
inline bool uamm6ShRepairByStoneToFlesh()
    { return true; }

inline int uamm6ShHealPerDay()
    { return 1; }

inline bool uamm6ShRevertsWhenHealed()
    { return true; }

// ---- the courser ----
// The courser travels at
// the light-horse movement
// rate and attacks as a
// medium warhorse: three
// attacks for 1-6/1-6/1-3.
inline bool uamm6CrsLightHorseRate()
    { return true; }

inline bool uamm6CrsMediumWarhorseAttacks()
    { return true; }

inline int uamm6CrsAttacksPerRound()
    { return 3; }

inline int uamm6CrsHoofDamageLo()
    { return 1; }

inline int uamm6CrsHoofDamageHi()
    { return 6; }

inline int uamm6CrsThirdAttackDamageLo()
    { return 1; }

inline int uamm6CrsThirdAttackDamageHi()
    { return 3; }

inline int uamm6CrsArmorClass()
    { return 3; }

inline int uamm6CrsHitPoints()
    { return 18; }

inline bool uamm6CrsSavesAsHardMetal()
    { return true; }

// ---- the destrier ----
// The destrier travels at
// the medium-horse movement
// rate and attacks as a
// heavy warhorse: three
// attacks for 1-8/1-8/1-3.
inline bool uamm6DstMediumHorseRate()
    { return true; }

inline bool uamm6DstHeavyWarhorseAttacks()
    { return true; }

inline int uamm6DstAttacksPerRound()
    { return 3; }

inline int uamm6DstHoofDamageLo()
    { return 1; }

inline int uamm6DstHoofDamageHi()
    { return 8; }

inline int uamm6DstThirdAttackDamageLo()
    { return 1; }

inline int uamm6DstThirdAttackDamageHi()
    { return 3; }

inline int uamm6DstArmorClass()
    { return 1; }

inline int uamm6DstHitPoints()
    { return 26; }

inline bool uamm6DstSavesAsHardMetal()
    { return true; }

// ---- the ultimate
// solution ----
// A strange magical liquid
// appearing nothing more
// remarkable than some
// minor oil or potion; upon
// first examination it
// seems to have the
// properties of both oil of
// slipperiness and a potion
// of delusion.
inline bool uamm6UsoMinorOilAppearance()
    { return true; }

inline bool uamm6UsoSeemsSlipperinessAndDelusion()
    { return true; }

// Applied to any form of
// adhesive or sticky
// material, the solution
// immediately dissolves
// it - the effect of
// sovereign glue is
// immediately negated, as
// is any other cement,
// glue, or adhesive.
inline bool uamm6UsoDissolvesAdhesives()
    { return true; }

inline bool uamm6UsoNegatesSovereignGlue()
    { return true; }

// The area of effect is 1
// cubic foot per ounce; a
// typical container holds
// 27 ounces.
inline int uamm6UsoCuFtPerOunce()
    { return 1; }

inline int uamm6UsoContainerOunces()
    { return 27; }

// The concentrated
// transmutation sentence
// OCR-scrambles; the
// reconstruction: distilled
// down to one-third of its
// original volume, each
// ounce dissolves 1 cubic
// foot of material, organic
// or inorganic, as the
// transmutation spell;
// flagged.
inline bool uamm6UsoDistillToThird()
    { return true; }

inline int uamm6UsoDistilledOunces()
    { return 9; }

inline int uamm6UsoDistilledCuFtPerOunce()
    { return 1; }

inline bool uamm6UsoTransmutationSeamGarbles()
    { return true; }

// A living target requires a
// successful roll to hit and
// is entitled to a saving
// throw versus spell;
// inanimate objects are
// automatically affected,
// but magic items gain a
// saving throw versus
// disintegrate.
inline bool uamm6UsoLivingNeedsToHit()
    { return true; }

inline bool uamm6UsoLivingSaveVsSpell()
    { return true; }

inline bool uamm6UsoInanimateAutomatic()
    { return true; }

inline bool uamm6UsoMagicItemsSaveVsDisintegrate()
    { return true; }

// ---- the wind fan ----
// A magical apparatus
// appearing nothing more
// than a wood and papyrus
// or cloth instrument for
// creating a cooling breeze.
inline bool uamm6WfaCoolingBreezeAppearance()
    { return true; }

// Uttering the correct word
// generates air exactly
// duplicating a gust of wind
// spell as if cast by a
// 5th-level magic-user.
inline bool uamm6WfaWordTriggersGust()
    { return true; }

inline int uamm6WfaCasterLevel()
    { return 5; }

// The fan is usable once per
// day with no risk; more
// frequent use carries a
// cumulative 20% chance per
// usage of tearing into
// useless, non-magical
// tatters.
inline bool uamm6WfaOncePerDaySafe()
    { return true; }

inline int uamm6WfaTearChancePctPerUse()
    { return 20; }

inline bool uamm6WfaTearsNonMagical()
    { return true; }

// ---- Zagyg's flowing
// flagon ----
// A well-made vessel,
// usually of nickel-silver,
// engraved and sculpted with
// grapes, vines, wine
// cellars, and drinking
// scenes; somewhere on it a
// line of magical writing -
// the words of a toast.
inline bool uamm6ZffNickelSilverVessel()
    { return true; }

inline bool uamm6ZffEngravedDrinkingScenes()
    { return true; }

inline bool uamm6ZffToastLineOnVessel()
    { return true; }

// The first individual to
// pick up the flagon reads
// the toast; no other can,
// normally or magically,
// until becoming the owner.
inline bool uamm6ZffFirstPickerReadsOnly()
    { return true; }

inline bool uamm6ZffOwnerOnlyUntilOwned()
    { return true; }

// The phrase is read to
// activate; each activation
// changes the phrase.
inline bool uamm6ZffReadToActivate()
    { return true; }

inline bool uamm6ZffPhraseChangesEachUse()
    { return true; }

// The six-draught ladder:
// the weak wine about 7%
// alcohol, then 10%, 13%,
// port-like 20%, the
// near-liquor 40%, and the
// sixth and last draught a
// brandy-like 80%.
inline int uamm6ZffDraughtCount()
    { return 6; }

inline int uamm6ZffFirstAlcoholPct()
    { return 7; }

inline int uamm6ZffSecondAlcoholPct()
    { return 10; }

inline int uamm6ZffThirdAlcoholPct()
    { return 13; }

inline int uamm6ZffFourthAlcoholPct()
    { return 20; }

inline int uamm6ZffFifthAlcoholPct()
    { return 40; }

inline int uamm6ZffSixthAlcoholPct()
    { return 80; }

// The typical flagon holds
// about 1 pint (16 ounces);
// it is 90% unlikely that
// any partaker of the first
// draught notices the
// increase in alcohol; the
// flagon is usable a
// maximum of three times
// per day.
inline int uamm6ZffPintOunces()
    { return 16; }

inline int uamm6ZffNoticeUnlikelyPct()
    { return 90; }

inline int uamm6ZffUsesPerDay()
    { return 3; }

// ---- Zagyg's spell
// component case ----
// A normal belt pouch of
// unremarkable sort
// radiating a faint magic
// aura if detected for.
inline bool uamm6ZscBeltPouchAppearance()
    { return true; }

inline bool uamm6ZscFaintMagicAura()
    { return true; }

// A magic-user thinking of
// the material components
// desired for a spell finds
// them appearing in the
// pouch; unused within 1
// round they immediately
// disappear and the usage
// is wasted; employed in
// casting, they likewise
// disappear as soon as the
// spell is cast.
inline bool uamm6ZscComponentsOnThought()
    { return true; }

inline int uamm6ZscVanishAfterRounds()
    { return 1; }

inline bool uamm6ZscWastedIfUnused()
    { return true; }

inline bool uamm6ZscVanishOnCasting()
    { return true; }

// The uses-per-day table:
// six rows, from 2 times per
// day to 7; the XP value is
// 100 times the uses (200
// to 700); the sale value
// is 1,000 times (2,000 to
// 7,000) - the printed gp
// tail truncates ("7,00");
// flagged.
inline int uamm6ZscTableRows()
    { return 6; }

inline int uamm6ZscUsesLo()
    { return 2; }

inline int uamm6ZscUsesHi()
    { return 7; }

inline int uamm6ZscXpPerUse()
    { return 100; }

inline int uamm6ZscGpPerUse()
    { return 1000; }

inline bool uamm6ZscGpTailGarbles()
    { return true; }

// ---- the part ledger ----
// Five S-Z items: two fully
// clean, three flagged, none
// fully garbled.
inline int uamm6PartItemTotal()
    { return 5; }

inline int uamm6PartCleanCount()
    { return 2; }

inline int uamm6PartFlaggedCount()
    { return 3; }

inline int uamm6PartGarbledCount()
    { return 0; }

}   // namespace rules

