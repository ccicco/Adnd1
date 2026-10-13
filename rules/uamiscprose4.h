// ===========================================================================
// Adnd1 - rules/uamiscprose4.h
// The UA TREASURE
// (MISCELLANEOUS MAGIC) prose
// pins, part 4, R384: the
// I-P stretch - nine pins,
// five fully clean (the iron
// bands of Bilarro, the lens
// of detection, the mantle of
// Celestian, the pearl of the
// sirines, the pouch of
// accessibility) plus four
// mechanics-clean with flagged
// holes (the lens of
// ultravision's diameter cell,
// Murlynd's spoon's gruel
// tail, the philosopher's
// stone's transmutation cells,
// the prison of Zagyg's
// attunement seam). Nothing in
// I-P fully garbles; Q-Z rides
// the later parts. The
// part-3 and skeleton seams
// ride in the regtest audit,
// not here.
// The R398 clean read
// filled every flagged hole
// named above.
namespace rules {

// ---- the iron bands of
// Bilarro ----
// At first discovery, a
// somewhat rusty iron sphere;
// close examination shows
// bandings on the 3-inch
// globe; detection shows a
// strong dweomer of
// indeterminable nature.
inline int uamm4IbaGlobeDiameterIn()
    { return 3; }

inline bool uamm4IbaAppearsRustySphere()
    { return true; }

inline bool uamm4IbaStrongIndeterminateDweomer()
    { return true; }

// On the command word the
// hurled device's bands
// expand and constrict the
// target on a successful,
// unadjusted to-hit roll.
inline bool uamm4IbaNeedsCommandWord()
    { return true; }

inline bool uamm4IbaHurlAtOpponent()
    { return true; }

inline bool uamm4IbaUnadjustedToHitOnly()
    { return true; }

// Holds a single creature up
// to frost/fire giant-size,
// immobile until the command
// word restores globular
// form.
inline bool uamm4IbaSingleCreatureOnly()
    { return true; }

inline bool uamm4IbaHoldsGiantSize()
    { return true; }

inline bool uamm4IbaImmobileUntilCommandAgain()
    { return true; }

// The captive's one chance to
// break (and ruin) the bands
// equals its bend-bars
// likelihood; after one
// failed attempt the bands
// are set inescapable.
inline bool uamm4IbaBreakEqualsBendBars()
    { return true; }

inline bool uamm4IbaBreakRuinsBands()
    { return true; }

inline int uamm4IbaBreakAttempts()
    { return 1; }

inline bool uamm4IbaInescapableAfterAttempt()
    { return true; }

// ---- the lens of detection
// ----
// A circular prism that
// detects minute things at
// 50% of the ability of eyes
// of minute seeing.
inline bool uamm4LdeDetectsMinuteThings()
    { return true; }

inline int uamm4LdeMinuteSeeingPct()
    { return 50; }

// Enables tracking as a
// ranger does, at 6-inch base
// speed; about 6 inches in
// diameter; must be set in a
// frame with a handle.
inline bool uamm4LdeTracksAsRanger()
    { return true; }

inline int uamm4LdeTrackBaseSpeedIn()
    { return 6; }

inline int uamm4LdeDiameterIn()
    { return 6; }

inline bool uamm4LdeNeedsFrameAndHandle()
    { return true; }

// ---- the lens of
// ultravision ----
// A circular faceted prism
// of pale aquamarine crystal;
// held before the eye it
// senses ultraviolet - the
// user sees total darkness as
// if in bright moonlight.
inline bool uamm4LulFacetedAquamarine()
    { return true; }

inline bool uamm4LulSensesUltraviolet()
    { return true; }

inline bool uamm4LulDarknessAsMoonlight()
    { return true; }

// General outlines up to 240
// feet; details clearly at
// 120 feet.
inline int uamm4LulOutlineRangeFt()
    { return 240; }

inline int uamm4LulDetailRangeFt()
    { return 120; }

inline bool uamm4LulMustBeHeldBeforeEye()
    { return true; }

// The R398 clean read fills
// the cell: the lens is about
// one and a half inches in
// diameter - 15 tenths.
inline int uamm4LulDiameterTenthsIn()
    { return 15; }

inline bool uamm4LulDiameterCellGarbles()
    { return false; }

// ---- the mantle of
// Celestian ----
// Black cloth - the color of
// the 7th Order of clerics of
// Celestian; an alteration
// aura under detection.
inline bool uamm4MceBlackClothSeventhOrder()
    { return true; }

inline bool uamm4MceAlterationAura()
    { return true; }

// The wearer exists in the
// cold void of outer space,
// breathing as if in a cool,
// well-ventilated place; it
// protects against poison
// gases of all sorts.
inline bool uamm4MceVoidOfSpaceSurvival()
    { return true; }

inline bool uamm4MceBreathesAsIfVentilated()
    { return true; }

inline bool uamm4MceProtectsAgainstPoisonGas()
    { return true; }

// +1 on all saving throws
// versus electricity, fire,
// and noise (including drums
// of deafening or panic,
// roaring, thunder).
inline int uamm4MceSaveBonus()
    { return 1; }

inline bool uamm4MceSaveVsElectricity()
    { return true; }

inline bool uamm4MceSaveVsFire()
    { return true; }

inline bool uamm4MceSaveVsNoise()
    { return true; }

// Food: a pocket yields
// sufficient rations for one
// person for one day, once
// per day.
inline bool uamm4MceFoodOncePerDay()
    { return true; }

// Drink: a small ewer gives
// up to seven gallons of
// water, cold or warm as
// commanded, once per day.
inline int uamm4MceEwerGallons()
    { return 7; }

inline bool uamm4MceEwerOncePerDay()
    { return true; }

// Shelter: the wearer never
// grows cold or hot or
// becomes wet or damp.
inline bool uamm4MceNoColdHotWetDamp()
    { return true; }

// Belongings: seven large and
// seven small pockets; one of
// each serves food and water,
// leaving 12 free - up to 70
// gp weight in the small, 140
// in the large, with no bulk
// or added weight.
inline int uamm4MceLargePockets()
    { return 7; }

inline int uamm4MceSmallPockets()
    { return 7; }

inline int uamm4McePocketsForFoodWater()
    { return 2; }

inline int uamm4MceRemainingPockets()
    { return 12; }

inline int uamm4MceSmallPocketWeightGp()
    { return 70; }

inline int uamm4MceLargePocketWeightGp()
    { return 140; }

inline bool uamm4MceNoBulkOrAddedWeight()
    { return true; }

// Only a cleric of Celestian,
// druidical or not, gains the
// aura power: with
// concentration, "see" the
// aura of any stranger met -
// warning of evil, neutral,
// or good intent.
inline bool uamm4MceAuraPowerClericsOnly()
    { return true; }

inline bool uamm4MceAuraNeedsConcentration()
    { return true; }

inline bool uamm4MceAuraRevealsAlignmentIntent()
    { return true; }

// ---- Murlynd's spoon ----
// An unremarkable eating
// utensil typically fashioned
// from horn; a dim conjuration
// dweomer under detection.
inline bool uamm4MslFashionedFromHorn()
    { return true; }

inline bool uamm4MslDimConjurationDweomer()
    { return true; }

// Placed in any empty
// container - bowl, cup,
// dish - the vessel fills
// with a thick pasty gruel;
// the flavor is like warm wet
// cardboard.
inline bool uamm4MslFillsEmptyContainer()
    { return true; }

inline bool uamm4MslThickPastyGruel()
    { return true; }

inline bool uamm4MslCardboardFlavor()
    { return true; }

// The R398 clean read fills
// the seam: the gruel is
// highly nourishing,
// sustains any diet, and the
// spoon produces enough in a
// day to feed up to four
// humans.
inline bool uamm4MslHighlyNourishing()
    { return true; }

inline bool uamm4MslSustainsAllDiets()
    { return true; }

inline int uamm4MslFeedsHumansPerDay()
    { return 4; }

inline bool uamm4MslGruelTailGarbles()
    { return false; }

// ---- the pearl of the
// sirines ----
// A normal-seeming pearl with
// a faint enchantment dweomer
// - very beautiful, worth at
// least 1,000 gp on that
// basis alone.
inline bool uamm4PsiFaintEnchantmentAura()
    { return true; }

inline int uamm4PsiWorthGp()
    { return 1000; }

// Clasped firmly in hand or
// to breast, the possessor
// understands and can employ
// the item when attempting
// related actions.
inline bool uamm4PsiClaspedToActivate()
    { return true; }

// Breathe in water as if in
// clean fresh air;
// underwater movement rate
// 24 inches.
inline bool uamm4PsiWaterBreathing()
    { return true; }

inline int uamm4PsiUnderwaterMoveIn()
    { return 24; }

// Immune to any ill effects
// from the touch of a
// sirine; the pearl must be
// within the general area -
// less than distant - to
// convey its powers.
inline bool uamm4PsiImmuneToSirineTouch()
    { return true; }

inline bool uamm4PsiMustRemainNearby()
    { return true; }

// ---- the philosopher's
// stone ----
// A rare magical substance
// appearing as an ordinary,
// rather blackish and sooty
// piece of rock; a faint
// dweomer of indeterminate
// sort.
inline bool uamm4PstSootyBlackishRock()
    { return true; }

inline bool uamm4PstFaintIndeterminateDweomer()
    { return true; }

// Broken open, a geode-like
// cavity lined with
// quicksilver that transmutes
// base metals - iron into
// silver, lead into gold.
inline bool uamm4PstGeodeCavity()
    { return true; }

inline bool uamm4PstQuicksilverLined()
    { return true; }

inline bool uamm4PstIronToSilver()
    { return true; }

inline bool uamm4PstLeadToGold()
    { return true; }

// The R398 clean read fills
// the cells: from 50 to 500
// pounds of iron into silver,
// or 10 to 100 pounds of lead
// into gold, from a single
// stone; either an alchemist
// or a magic-user can
// effectuate it.
inline int uamm4PstIronLbsLo()
    { return 50; }

inline int uamm4PstIronLbsHi()
    { return 500; }

inline int uamm4PstLeadLbsLo()
    { return 10; }

inline int uamm4PstLeadLbsHi()
    { return 100; }

inline bool uamm4PstAlchemistOrMagicUser()
    { return true; }

inline bool uamm4PstTransmutationCellsGarble()
    { return false; }

// All the quicksilver must be
// employed at one time, on
// the first attempt.
inline bool uamm4PstAllQuicksilverAtOnce()
    { return true; }

inline bool uamm4PstFirstAttemptOnly()
    { return true; }

// A greenish crystalline
// salt allows the manufacture
// of 1-4 potions of
// longevity; a 75% chance of
// occurring inside a given
// stone.
inline int uamm4PstLongevitySaltChancePct()
    { return 75; }

inline int uamm4PstLongevityPotionsLo()
    { return 1; }

inline int uamm4PstLongevityPotionsHi()
    { return 4; }

// A pure white powder,
// admixed with a potion of
// longevity, restores life to
// a dead human or demi-human
// if administered internally
// within one week of demise
// (cf. the raise dead
// spell); a 25% chance of
// occurring.
inline int uamm4PstWhitePowderChancePct()
    { return 25; }

inline bool uamm4PstPowderRestoresLife()
    { return true; }

inline int uamm4PstDemiseWeeks()
    { return 1; }

inline bool uamm4PstCfRaiseDead()
    { return true; }

// The experience-point and
// gold-piece values apply
// only to an unopened stone.
inline bool uamm4PstValuesOnlyUnopened()
    { return true; }

// ---- the pouch of
// accessibility ----
// A normal-seeming pouch that
// holds up to 3,000 gp of
// weight in 30 specially
// constructed pockets.
inline int uamm4PacTotalWeightGp()
    { return 3000; }

inline int uamm4PacPocketCount()
    { return 30; }

// Each pocket holds a maximum
// of 100 gp weight or 1
// cubic foot of volume,
// whichever is reached first.
inline int uamm4PacPocketWeightGp()
    { return 100; }

inline int uamm4PacPocketCuFt()
    { return 1; }

inline bool uamm4PacWhicheverFirst()
    { return true; }

// Merely speaking the name of
// a desired object causes it
// to appear at the top of the
// pouch, ready for instant
// grasp.
inline bool uamm4PacSpeakNameToSummon()
    { return true; }

inline bool uamm4PacAppearsAtTopReady()
    { return true; }

// Similar to bags of holding
// and portable holes - their
// placement strictures apply
// fully.
inline bool uamm4PacLikeBagOfHolding()
    { return true; }

inline bool uamm4PacPlacementStricturesApply()
    { return true; }

// Weighs 10 gp empty, 40 gp
// filled.
inline int uamm4PacWeightEmptyGp()
    { return 10; }

inline int uamm4PacWeightFilledGp()
    { return 40; }

// ---- the prison of Zagyg
// ----
// Only five of these brass
// devices are thought to
// exist; each appears to be a
// small, well-made birdcage.
inline int uamm4PzaThoughtToExist()
    { return 5; }

inline bool uamm4PzaAppearsAsBirdcage()
    { return true; }

// No normal handling reveals
// the magic; detect magic is
// 50% likely to show a vague
// dweomer of uncertain nature
// - either no class of magic
// or an erroneous one.
inline bool uamm4PzaNormalExamFails()
    { return true; }

inline int uamm4PzaDetectVaguePct()
    { return 50; }

inline bool uamm4PzaErroneousClassPossible()
    { return true; }

// The R398 clean read fills
// the seam: the cage carries
// an anti-magic and
// non-detection spell in and
// upon it, and each prison
// attunes itself to the
// possessor who learns the
// activation wording.
inline bool uamm4PzaPermanentAntiMagic()
    { return true; }

inline bool uamm4PzaNonDetection()
    { return true; }

inline bool uamm4PzaAttunesToOwner()
    { return true; }

inline bool uamm4PzaAttunementSeamGarbles()
    { return false; }

// The activation word works
// two effects: the cage door
// is held fast by a wizard
// lock as if cast by the
// possessor.
inline bool uamm4PzaActivationWord()
    { return true; }

inline bool uamm4PzaDoorHeldByWizardLock()
    { return true; }

// The door opens only from
// the outside, by a
// magic-user who could
// normally overcome such a
// lock without additional
// magic.
inline bool uamm4PzaOpensOnlyFromOutside()
    { return true; }

inline bool uamm4PzaOnlyMagicUserOpens()
    { return true; }

// The trigger word invokes
// an enchantment of 1-round
// casting time - a command
// naming the creature's true
// name, or its history in
// great detail for the
// nameless.
inline bool uamm4PzaTriggerWord()
    { return true; }

inline int uamm4PzaEnchantCastingRounds()
    { return 1; }

inline bool uamm4PzaNeedsTrueName()
    { return true; }

inline bool uamm4PzaHistoryForNameless()
    { return true; }

// A failed save versus spell
// shrinks the victim to about
// a quarter foot - three
// inches - in height and
// transports it
// instantaneously into the
// cage.
inline bool uamm4PzaSaveVsSpell()
    { return true; }

inline int uamm4PzaShrinksToHeightIn()
    { return 3; }

inline bool uamm4PzaTransportedIntoCage()
    { return true; }

// Magic does not function
// within the cage; the
// prisoner cannot itself
// escape.
inline bool uamm4PzaMagicFailsInside()
    { return true; }

inline bool uamm4PzaPrisonerCannotEscape()
    { return true; }

// Freed only by a magic-user
// able to open the door, or
// by a wish or an alter
// reality spell.
inline bool uamm4PzaFreedByMagicUser()
    { return true; }

inline bool uamm4PzaFreedByWishOrAlterReality()
    { return true; }

// The prison cannot be harmed
// or affected by force or
// magic; a creature inside
// cannot be located by any
// means except actual sight
// or hearing.
inline bool uamm4PzaImmuneToForceAndMagic()
    { return true; }

inline bool uamm4PzaHiddenFromLocation()
    { return true; }

inline bool uamm4PzaFoundOnlyBySightHearing()
    { return true; }

// The possessor frees a
// prisoner with a single
// freedom word; the freed
// captive is restored to
// former size and abilities.
inline bool uamm4PzaFreedomWord()
    { return true; }

inline bool uamm4PzaFreedRestored()
    { return true; }

// Imprisoned creatures need
// neither food nor drink -
// the cage's magic negates
// the need for either.
inline bool uamm4PzaNoFoodOrDrinkNeeded()
    { return true; }

// ---- the part ledger ----
// Nine I-P items, all fully
// clean - the R398 clean read
// filled the four flagged
// holes, none fully garbled.
inline int uamm4PartItemTotal()
    { return 9; }

inline int uamm4PartCleanCount()
    { return 9; }

inline int uamm4PartFlaggedCount()
    { return 0; }

inline int uamm4PartGarbledCount()
    { return 0; }

}   // namespace rules

