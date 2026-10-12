# R384: the UA misc magic prose
# part 4 pin round (the I-P
# stretch): NINE items pin -
# FIVE fully clean (the iron
# bands of Bilarro, the lens
# of detection, the mantle of
# Celestian, the pearl of the
# sirines, the pouch of
# accessibility) plus FOUR
# mechanics-clean with flagged
# holes (the lens of
# ultravision's diameter cell,
# Murlynd's spoon's gruel tail,
# the philosopher's stone's
# transmutation cells, the
# prison of Zagyg's attunement
# seam); NOTHING in I-P fully
# garbles - the gap item
# AMENDED with the part-4 note,
# stays OPEN for Q-Z,
# PDF-gated; the R383 seam the
# part-3 ledger, the R375 seam
# the misc band; the census
# 310 -> 311.
# Pin-era pattern (R322).
# Idempotent; run twice.
import io
import os


NL = '\n'
applied = []
already = []


def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)


# ---- (a) the seed: the R383 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R383 landed 2026-10-12: commit',
    '  1dbe6a0, census 310, the UA',
    '  misc magic prose part 3 pin',
    '  round (rules/uamiscprose3.h):',
    '  eleven G-H items pin - two',
    '  fully clean (the gloves of',
    '  missile snaring, the hat of',
    '  stupidity) plus nine',
    '  mechanics-clean with flagged',
    '  holes (the gem of insight,',
    '  the girdle of dwarvenkind,',
    '  the girdle of many pouches,',
    '  the gloves of thievery,',
    '  the hat of difference, the',
    '  hat of disguise, the',
    '  haversack, the horn of fog,',
    '  the horn of goodness);',
    '  nothing in G-H fully',
    '  garbles - the item AMENDED,',
    '  stays OPEN for I-Z,',
    '  PDF-gated; the R382 seam',
    '  the part-2 ledger, the',
    '  R375 seam the misc band;',
    '  GREEN on the first run.'
])
s = rd(SD)
if 'R383 landed 2026-10-12' in s:
    already.append('seed: the R383 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R383 record')
s = rd(SD)
assert s.count(
    'R383 landed 2026-10-12'
) == 1, 'a entry'


s = rd(SD)
assert s.count(
    'R382 landed 2026-10-12'
) == 1, 'a R382 kept'
assert s.count(
    'R381 landed 2026-10-12'
) == 1, 'a R381 kept'
assert s.count(
    'R380 landed 2026-10-12'
) == 1, 'a R380 kept'
assert s.count(
    'R379 landed 2026-10-12'
) == 1, 'a R379 kept'
assert s.count(
    'R378 landed 2026-10-12'
) == 1, 'a R378 kept'
assert s.count(
    'R377 landed 2026-10-12'
) == 1, 'a R377 kept'
assert s.count(
    'R376 landed 2026-10-12'
) == 1, 'a R376 kept'
assert s.count(
    'R375 landed 2026-10-12'
) == 1, 'a R375 kept'
assert s.count(
    'R374 landed 2026-10-12'
) == 1, 'a R374 kept'
assert s.count(
    'R373 landed 2026-10-12'
) == 1, 'a R373 kept'
assert s.count(
    'R372 landed 2026-10-12'
) == 1, 'a R372 kept'
assert s.count(
    'R371 landed 2026-10-12'
) == 1, 'a R371 kept'
assert s.count(
    'R370 landed 2026-10-12'
) == 1, 'a R370 kept'
assert s.count(
    'R369 landed 2026-10-12'
) == 1, 'a R369 kept'
assert s.count(
    'R368 landed 2026-10-12'
) == 1, 'a R368 kept'
assert s.count(
    'R367 landed 2026-10-12'
) == 1, 'a R367 kept'
assert s.count(
    'R366 landed 2026-10-12'
) == 1, 'a R366 kept'
assert s.count(
    'R365 landed 2026-10-12'
) == 1, 'a R365 kept'
assert s.count(
    'R364 landed 2026-10-11'
) == 1, 'a R364 kept'
assert s.count(
    'R363 landed 2026-10-11'
) == 1, 'a R363 kept'
assert s.count(
    'R362 landed 2026-10-11'
) == 1, 'a R362 kept'
assert s.count(
    'R361 landed 2026-10-11'
) == 1, 'a R361 kept'
assert s.count(
    'R360 landed 2026-10-11'
) == 1, 'a R360 kept'
assert s.count(
    'R359 landed 2026-10-11'
) == 1, 'a R359 kept'
assert s.count(
    'R358 landed 2026-10-11'
) == 1, 'a R358 kept'
assert s.count(
    'R357 landed 2026-10-11'
) == 1, 'a R357 kept'
assert s.count(
    'R356 landed 2026-10-11'
) == 1, 'a R356 kept'
assert s.count(
    'R355 landed 2026-10-11'
) == 1, 'a R355 kept'
assert s.count(
    'R354 landed 2026-10-11'
) == 1, 'a R354 kept'
assert s.count(
    'R352 landed 2026-10-11'
) == 1, 'a R352 kept'
assert s.count(
    'R351 landed 2026-10-11'
) == 1, 'a R351 kept'
assert s.count(
    'R350 landed 2026-10-11'
) == 1, 'a R350 kept'
assert s.count(
    'R349 landed 2026-10-11'
) == 1, 'a R349 kept'
assert s.count(
    'R347 landed 2026-10-11'
) == 1, 'a R347 kept'
assert s.count(
    'R343 landed 2026-10-11'
) == 1, 'a R343 kept'
assert s.count(
    '## Knowledge maintenance'
) == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'


# ---- (b) NEW rules/uamiscprose4.h ----
P = 'rules/uamiscprose4.h'
if os.path.exists(P) and 'R384' in rd(P):
    already.append('uamiscprose4.h: the pins')
else:
    HDR = r"""// ===========================================================================
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

// The printed diameter cell
// garbles ("1'z inches") -
// read as about one and a
// half inches; flagged.
inline int uamm4LulDiameterIn()
    { return 1; }

inline bool uamm4LulDiameterCellGarbles()
    { return true; }

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

// The nourishment seam
// OCR-scrambles; the
// reconstruction: the gruel
// is highly nourishing, and
// the spoon produces enough
// in a day to feed up to
// four humans; flagged.
inline bool uamm4MslHighlyNourishing()
    { return true; }

inline int uamm4MslFeedsHumansPerDay()
    { return 4; }

inline bool uamm4MslGruelTailGarbles()
    { return true; }

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

// The transmutation amount
// cells OCR-scramble; the
// reconstruction: up to 50
// pounds of iron into silver,
// or 100 pounds of lead into
// gold, from a single stone;
// either an alchemist or a
// magic-user can effectuate
// it; flagged.
inline int uamm4PstIronLbsPerStone()
    { return 50; }

inline int uamm4PstLeadLbsPerStone()
    { return 100; }

inline bool uamm4PstAlchemistOrMagicUser()
    { return true; }

inline bool uamm4PstTransmutationCellsGarble()
    { return true; }

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

// The attunement sentence
// OCR-scrambles; the
// reconstruction: each prison
// attunes itself to the
// possessor when he or she
// learns the activation
// wording; flagged.
inline bool uamm4PzaAttunementSeamGarbles()
    { return true; }

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
// a foot in height and
// transports it
// instantaneously into the
// cage.
inline bool uamm4PzaSaveVsSpell()
    { return true; }

inline int uamm4PzaShrinksToHeightFt()
    { return 1; }

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
// Nine I-P items: five fully
// clean, four flagged, none
// fully garbled.
inline int uamm4PartItemTotal()
    { return 9; }

inline int uamm4PartCleanCount()
    { return 5; }

inline int uamm4PartFlaggedCount()
    { return 4; }

inline int uamm4PartGarbledCount()
    { return 0; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uamiscprose4.h: the pins')


s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 127, 'b inline count'
assert s.count('R384') == 1, 'b round tag'
assert s.count(
    'uamm4IbaGlobeDiameterIn'
    ) >= 1, 'b fn'
assert 'uafol' not in s, 'b no uafol ref'
assert 'uanw' not in s, 'b no uanw ref'
assert 'uacm' not in s, 'b no uacm ref'
assert 'uaarm' not in s, 'b no uaarm ref'
assert 'uacavt' not in s, 'b no uacavt ref'
assert 'uawt' not in s, 'b no uawt ref'
assert 'uamt' not in s, 'b no uamt ref'
assert 'uatd' not in s, 'b no uatd ref'
assert 'uads' not in s, 'b no uads ref'
assert 'uapp' not in s, 'b no uapp ref'
assert 'uaps' not in s, 'b no uaps ref'
assert 'uarp' not in s, 'b no uarp ref'
assert 'uaro' not in s, 'b no uaro ref'
assert 'uawd' not in s, 'b no uawd ref'
assert 'uam2' not in s, 'b no uam2 ref'
assert 'uamm3' not in s, 'b no uamm3 ref'
assert s.count('uamm') == s.count(
    'uamm4'), 'b no R381-R383 uamm ref'
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (c) the gap report: the
# amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R384' in s:
    already.append('gap: the amendment')
else:
    OLD = NL.join([
        '- [ ] **The new miscellaneous magic',
        '      items** (pp. 97-104) - the named',
        '      additions: the Egg of Reason, the',
        '      Girdle of Many Pouches, the',
        '      Gloves of Missile Snaring, the',
        '      Hat of Difference, the Heward',
        '      haversack, the Horn of Fog, the',
        '      Prison of Zagyg, the Quiver of',
        '      Ehlonna, the Robe of Stars, the',
        '      Scarab versus Golems, the Shadow',
        '      Lanthorn, the Sheet of Smallness.',
        '      - AMENDED R381: the misc magic',
        '        prose part 1 pin round',
        '        (rules/uamiscprose1.h) - the',
        '        A-C stretch, THIRTEEN items',
        '        pin: EIGHT fully clean (the',
        '        beads of force, the boots of',
        '        the north, the boots winged,',
        '        the bracers of archery, the',
        '        bracers of brachiation, the',
        '        cloak of arachnidia, the',
        '        cloak of the bat, the',
        '        cyclocone) plus FIVE',
        '        mechanics-clean with flagged',
        '        holes (the amulet versus',
        "        undead's 9th-level cell, the",
        "        anything item's tail, the",
        "        boccob book's save cell and",
        '        scribing tail, the boots of',
        "        varied tracks' row-one",
        '        print, the chime of',
        "        interruption's opening);",
        '        NOTHING in A-C fully garbles',
        '        - the item stays OPEN for',
        '        D-Z and the PDF.',
        '      - AMENDED R382: the misc magic',
        '        prose part 2 pin round',
        '        (rules/uamiscprose2.h) - the',
        '        D-E stretch, EIGHT items pin:',
        '        ONE fully clean (the dust of',
        '        tracelessness) plus SEVEN',
        '        mechanics-clean with flagged',
        "        holes (the deck of illusions'",
        "        card list, the dicerion's",
        '        description seam, the dust of',
        "        dryness' elemental-save cell,",
        "        the dust of illusion's intro,",
        "        the egg of desire's int seam,",
        "        the egg of reason's 18+ cell,",
        "        the egg of shattering's attack",
        '        seam); NOTHING in D-E fully',
        '        garbles - the item stays OPEN',
        '        for F-Z and the PDF.',
        '      - AMENDED R383: the misc magic',
        '        prose part 3 pin round',
        '        (rules/uamiscprose3.h) - the',
        '        G-H stretch, ELEVEN items pin:',
        '        TWO fully clean (the gloves of',
        '        missile snaring, the hat of',
        '        stupidity) plus NINE',
        '        mechanics-clean with flagged',
        "        holes (the gem of insight's",
        '        recall seam, the girdle of',
        "        dwarvenkind's racial block, the",
        "        girdle of many pouches' tail,",
        "        the gloves of thievery's level",
        "        cells, the hat of difference's",
        '        loss seam, the hat of',
        "        disguise's removal seam, the",
        "        haversack's quart merge, the",
        "        horn of fog's rounds/minutes",
        "        seam, the horn of goodness'",
        '        eaten header); NOTHING in G-H',
        '        fully garbles - the item stays',
        '        OPEN for I-Z and the PDF.'
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = OLD + NL + NL.join([
        '      - AMENDED R384: the misc magic',
        '        prose part 4 pin round',
        '        (rules/uamiscprose4.h) - the',
        '        I-P stretch, NINE items pin:',
        '        FIVE fully clean (the iron',
        '        bands of Bilarro, the lens of',
        '        detection, the mantle of',
        '        Celestian, the pearl of the',
        '        sirines, the pouch of',
        '        accessibility) plus FOUR',
        '        mechanics-clean with flagged',
        '        holes (the lens of',
        "        ultravision's diameter cell,",
        "        Murlynd's spoon's gruel tail,",
        "        the philosopher's stone's",
        '        transmutation cells, the',
        "        prison of Zagyg's attunement",
        '        seam); NOTHING in I-P fully',
        '        garbles - the item stays OPEN',
        '        for Q-Z and the PDF.'
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the amendment')
wr(GP, s)


# ---- (c) the gap kept asserts ----
s = rd(GP)
assert s.count(
    '- [ ] **The new miscellaneous magic'
) == 1, 'c item kept open'
assert s.count(
    'AMENDED R384'
) == 1, 'c amendment'
assert s.count(
    'AMENDED R383'
) == 1, 'c r383 amendment kept'
assert s.count(
    'AMENDED R382'
) == 1, 'c r382 amendment kept'
assert s.count(
    'AMENDED R381'
) == 1, 'c r381 amendment kept'
assert s.count(
    'AMENDED R380'
) == 1, 'c r380 amendment kept'
assert s.count(
    'AMENDED R379'
) == 1, 'c r379 amendment kept'
assert s.count(
    'AMENDED R378'
) == 1, 'c r378 amendment kept'
assert s.count(
    'AMENDED R377'
) == 1, 'c r377 amendment kept'
assert s.count(
    'AMENDED R376'
) == 1, 'c r376 amendment kept'
assert s.count(
    'AMENDED R375'
) == 1, 'c r375 amendment kept'
assert s.count(
    '(rules/uamiscprose2.h)'
) == 1, 'c misc2 note kept'
assert s.count(
    '(rules/uamiscprose4.h)'
) == 1, 'c misc4 note'
assert s.count(
    '(rules/uamiscprose3.h)'
) == 1, 'c misc3 note kept'
assert s.count(
    '(rules/uamiscprose1.h)'
) == 1, 'c misc note kept'
assert s.count(
    '(rules/uawandprose.h)'
) == 1, 'c wands note kept'
assert s.count(
    '(rules/uarodstave.h)'
) == 1, 'c rods note kept'
assert s.count(
    '(rules/uaringprose.h)'
) == 1, 'c rings note kept'
assert s.count(
    '(rules/uaprotscr.h)'
) == 1, 'c scrolls note kept'
assert s.count(
    '(rules/uapotprose.h)'
) == 1, 'c potions note kept'
assert s.count(
    '(rules/uadetskel.h)'
) == 1, 'c skeleton note kept'
assert s.count(
    'DECIDED R374'
) == 1, 'c r374 decision kept'
assert s.count(
    '### Treasure (pp. 84-106) - THE DECISION'
) == 1, 'c treasure section kept'
assert s.count(
    '- [ ] **The random determination'
) == 1, 'c det tables kept open'
assert s.count(
    '- [ ] **The new potions**'
) == 1, 'c potions kept open'
assert s.count(
    '- [ ] **The new scrolls**'
) == 1, 'c scrolls kept open'
assert s.count(
    '- [ ] **The new rings**'
) == 1, 'c rings kept open'
assert s.count(
    '- [ ] **The new rods and staves**'
) == 1, 'c rods staves kept open'
assert s.count(
    '- [ ] **The new wands**'
) == 1, 'c wands kept open'
assert s.count(
    '- [ ] **The new armor and shields and'
) == 1, 'c armor shields kept open'
assert s.count(
    '- [ ] **The new miscellaneous weapons**'
) == 1, 'c misc weapons kept open'
assert s.count(
    '- [x] **The comeliness creation note**'
) == 1, 'c r373 note kept closed'
assert s.count(
    '- [x] **The cavalier follower tables**'
) == 1, 'c r372 kept closed'
assert s.count(
    '- [ ] **The Armor Class Table**'
) == 1, 'c armor class table kept open'
assert len(applied) + len(already) == 3, 'c count'


# ---- (d) regtest.cpp: the
# includes, the audit, the
# census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R384 UA misc magic prose part 4 pin audit' in s:
    already.append('regtest.cpp: the R384 audit')
else:
    INC_ANCH = ('#include "rules/uamiscprose3.h"  // '
        'R383: the UA misc magic prose 3')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamiscprose4.h"  // R384: the UA misc magic prose 4'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R384: the UA misc magic
    // prose part 4 pin audit ----
    // The I-P stretch: nine pins -
    // five fully clean (the iron
    // bands of Bilarro, the lens of
    // detection, the mantle of
    // Celestian, the pearl of the
    // sirines, the pouch of
    // accessibility) plus four
    // mechanics-clean with flagged
    // holes (the lens of
    // ultravision's diameter cell,
    // Murlynd's spoon's gruel tail,
    // the philosopher's stone's
    // transmutation cells, the
    // prison of Zagyg's attunement
    // seam); the R383 seam the
    // part-3 ledger, the R375 seam
    // the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the iron bands of
        // Bilarro ----
            if (uamm4IbaGlobeDiameterIn()
                    != 3) ++bad;
            if (!uamm4IbaAppearsRustySphere())
                ++bad;
            if (!uamm4IbaStrongIndeterminateDweomer())
                ++bad;
            if (!uamm4IbaNeedsCommandWord()) ++bad;
            if (!uamm4IbaHurlAtOpponent()) ++bad;
            if (!uamm4IbaUnadjustedToHitOnly())
                ++bad;
            if (!uamm4IbaSingleCreatureOnly())
                ++bad;
            if (!uamm4IbaHoldsGiantSize()) ++bad;
            if (!uamm4IbaImmobileUntilCommandAgain())
                ++bad;
            if (!uamm4IbaBreakEqualsBendBars())
                ++bad;
            if (!uamm4IbaBreakRuinsBands()) ++bad;
            if (uamm4IbaBreakAttempts() != 1)
                ++bad;
            if (!uamm4IbaInescapableAfterAttempt())
                ++bad;
            // the captive gets exactly
            // one break attempt
            if (uamm4IbaBreakAttempts()
                    != 1) ++bad;
        // ---- the lens of detection
        // ----
            if (!uamm4LdeDetectsMinuteThings())
                ++bad;
            if (uamm4LdeMinuteSeeingPct()
                    != 50) ++bad;
            if (!uamm4LdeTracksAsRanger()) ++bad;
            if (uamm4LdeTrackBaseSpeedIn() != 6)
                ++bad;
            if (uamm4LdeDiameterIn() != 6) ++bad;
            if (!uamm4LdeNeedsFrameAndHandle())
                ++bad;
            // the diameter matches the
            // track base speed, both 6
            if (uamm4LdeDiameterIn()
                    != uamm4LdeTrackBaseSpeedIn())
                ++bad;
        // ---- the lens of
        // ultravision ----
            if (!uamm4LulFacetedAquamarine())
                ++bad;
            if (!uamm4LulSensesUltraviolet()) ++bad;
            if (!uamm4LulDarknessAsMoonlight())
                ++bad;
            if (uamm4LulOutlineRangeFt() != 240)
                ++bad;
            if (uamm4LulDetailRangeFt() != 120)
                ++bad;
            if (!uamm4LulMustBeHeldBeforeEye())
                ++bad;
            if (uamm4LulDiameterIn() != 1) ++bad;
            if (!uamm4LulDiameterCellGarbles())
                ++bad;
            // the detail range is
            // half the outline range
            if (2 * uamm4LulDetailRangeFt()
                    != uamm4LulOutlineRangeFt())
                ++bad;
        // ---- the mantle of
        // Celestian ----
            if (!uamm4MceBlackClothSeventhOrder())
                ++bad;
            if (!uamm4MceAlterationAura()) ++bad;
            if (!uamm4MceVoidOfSpaceSurvival())
                ++bad;
            if (!uamm4MceBreathesAsIfVentilated())
                ++bad;
            if (!uamm4MceProtectsAgainstPoisonGas())
                ++bad;
            if (uamm4MceSaveBonus() != 1) ++bad;
            if (!uamm4MceSaveVsElectricity()) ++bad;
            if (!uamm4MceSaveVsFire()) ++bad;
            if (!uamm4MceSaveVsNoise()) ++bad;
            if (!uamm4MceFoodOncePerDay()) ++bad;
            if (uamm4MceEwerGallons() != 7) ++bad;
            if (!uamm4MceEwerOncePerDay()) ++bad;
            if (!uamm4MceNoColdHotWetDamp()) ++bad;
            if (uamm4MceLargePockets() != 7) ++bad;
            if (uamm4MceSmallPockets() != 7) ++bad;
            if (uamm4McePocketsForFoodWater()
                    != 2) ++bad;
            if (uamm4MceRemainingPockets() != 12)
                ++bad;
            if (uamm4MceSmallPocketWeightGp()
                    != 70) ++bad;
            if (uamm4MceLargePocketWeightGp()
                    != 140) ++bad;
            if (!uamm4MceNoBulkOrAddedWeight())
                ++bad;
            if (!uamm4MceAuraPowerClericsOnly())
                ++bad;
            if (!uamm4MceAuraNeedsConcentration())
                ++bad;
            if (!uamm4MceAuraRevealsAlignmentIntent())
                ++bad;
            // the pocket counts: the
            // remaining twelve = the
            // seven large + the seven
            // small - the two food
            // and water pockets
            if (uamm4MceLargePockets()
                    != uamm4MceSmallPockets()) ++bad;
            if (uamm4MceLargePockets()
                    + uamm4MceSmallPockets()
                    - uamm4McePocketsForFoodWater()
                    != uamm4MceRemainingPockets())
                ++bad;
            // the large pocket holds
            // twice the small, 140
            // against 70
            if (2 * uamm4MceSmallPocketWeightGp()
                    != uamm4MceLargePocketWeightGp())
                ++bad;
        // ---- Murlynd's spoon ----
            if (!uamm4MslFashionedFromHorn())
                ++bad;
            if (!uamm4MslDimConjurationDweomer())
                ++bad;
            if (!uamm4MslFillsEmptyContainer())
                ++bad;
            if (!uamm4MslThickPastyGruel()) ++bad;
            if (!uamm4MslCardboardFlavor()) ++bad;
            if (!uamm4MslHighlyNourishing()) ++bad;
            if (uamm4MslFeedsHumansPerDay() != 4)
                ++bad;
            if (!uamm4MslGruelTailGarbles()) ++bad;
        // ---- the pearl of the
        // sirines ----
            if (!uamm4PsiFaintEnchantmentAura())
                ++bad;
            if (uamm4PsiWorthGp() != 1000) ++bad;
            if (!uamm4PsiClaspedToActivate()) ++bad;
            if (!uamm4PsiWaterBreathing()) ++bad;
            if (uamm4PsiUnderwaterMoveIn() != 24)
                ++bad;
            if (!uamm4PsiImmuneToSirineTouch())
                ++bad;
            if (!uamm4PsiMustRemainNearby()) ++bad;
        // ---- the philosopher's
        // stone ----
            if (!uamm4PstSootyBlackishRock())
                ++bad;
            if (!uamm4PstFaintIndeterminateDweomer())
                ++bad;
            if (!uamm4PstGeodeCavity()) ++bad;
            if (!uamm4PstQuicksilverLined()) ++bad;
            if (!uamm4PstIronToSilver()) ++bad;
            if (!uamm4PstLeadToGold()) ++bad;
            if (uamm4PstIronLbsPerStone() != 50)
                ++bad;
            if (uamm4PstLeadLbsPerStone() != 100)
                ++bad;
            if (!uamm4PstAlchemistOrMagicUser())
                ++bad;
            if (!uamm4PstTransmutationCellsGarble())
                ++bad;
            if (!uamm4PstAllQuicksilverAtOnce())
                ++bad;
            if (!uamm4PstFirstAttemptOnly()) ++bad;
            if (uamm4PstLongevitySaltChancePct()
                    != 75) ++bad;
            if (uamm4PstLongevityPotionsLo() != 1)
                ++bad;
            if (uamm4PstLongevityPotionsHi() != 4)
                ++bad;
            if (uamm4PstWhitePowderChancePct()
                    != 25) ++bad;
            if (!uamm4PstPowderRestoresLife())
                ++bad;
            if (uamm4PstDemiseWeeks() != 1) ++bad;
            if (!uamm4PstCfRaiseDead()) ++bad;
            if (!uamm4PstValuesOnlyUnopened())
                ++bad;
            // the lead transmutes at
            // twice the iron weight
            if (2 * uamm4PstIronLbsPerStone()
                    != uamm4PstLeadLbsPerStone())
                ++bad;
            // the salt and powder
            // chances sum to a
            // certainty inside a
            // given stone, 75 + 25
            if (uamm4PstLongevitySaltChancePct()
                    + uamm4PstWhitePowderChancePct()
                    != 100) ++bad;
            // the longevity potions
            // ride the 1-4 range
            if (uamm4PstLongevityPotionsLo() >=
                    uamm4PstLongevityPotionsHi())
                ++bad;
        // ---- the pouch of
        // accessibility ----
            if (uamm4PacTotalWeightGp() != 3000)
                ++bad;
            if (uamm4PacPocketCount() != 30) ++bad;
            if (uamm4PacPocketWeightGp() != 100)
                ++bad;
            if (uamm4PacPocketCuFt() != 1) ++bad;
            if (!uamm4PacWhicheverFirst()) ++bad;
            if (!uamm4PacSpeakNameToSummon())
                ++bad;
            if (!uamm4PacAppearsAtTopReady()) ++bad;
            if (!uamm4PacLikeBagOfHolding()) ++bad;
            if (!uamm4PacPlacementStricturesApply())
                ++bad;
            if (uamm4PacWeightEmptyGp() != 10)
                ++bad;
            if (uamm4PacWeightFilledGp() != 40)
                ++bad;
            // the 3,000 gp total =
            // the 30 pockets x the
            // 100 gp per pocket
            if (uamm4PacPocketCount()
                    * uamm4PacPocketWeightGp()
                    != uamm4PacTotalWeightGp()) ++bad;
            // the filled-minus-empty
            // weight, 40 - 10,
            // matches the pocket
            // count, 30
            if (uamm4PacWeightFilledGp()
                    - uamm4PacWeightEmptyGp()
                    != uamm4PacPocketCount()) ++bad;
        // ---- the prison of
        // Zagyg ----
            if (uamm4PzaThoughtToExist() != 5)
                ++bad;
            if (!uamm4PzaAppearsAsBirdcage()) ++bad;
            if (!uamm4PzaNormalExamFails()) ++bad;
            if (uamm4PzaDetectVaguePct() != 50)
                ++bad;
            if (!uamm4PzaErroneousClassPossible())
                ++bad;
            if (!uamm4PzaAttunementSeamGarbles())
                ++bad;
            if (!uamm4PzaActivationWord()) ++bad;
            if (!uamm4PzaDoorHeldByWizardLock())
                ++bad;
            if (!uamm4PzaOpensOnlyFromOutside())
                ++bad;
            if (!uamm4PzaOnlyMagicUserOpens())
                ++bad;
            if (!uamm4PzaTriggerWord()) ++bad;
            if (uamm4PzaEnchantCastingRounds() != 1)
                ++bad;
            if (!uamm4PzaNeedsTrueName()) ++bad;
            if (!uamm4PzaHistoryForNameless()) ++bad;
            if (!uamm4PzaSaveVsSpell()) ++bad;
            if (uamm4PzaShrinksToHeightFt() != 1)
                ++bad;
            if (!uamm4PzaTransportedIntoCage())
                ++bad;
            if (!uamm4PzaMagicFailsInside()) ++bad;
            if (!uamm4PzaPrisonerCannotEscape())
                ++bad;
            if (!uamm4PzaFreedByMagicUser()) ++bad;
            if (!uamm4PzaFreedByWishOrAlterReality())
                ++bad;
            if (!uamm4PzaImmuneToForceAndMagic())
                ++bad;
            if (!uamm4PzaHiddenFromLocation()) ++bad;
            if (!uamm4PzaFoundOnlyBySightHearing())
                ++bad;
            if (!uamm4PzaFreedomWord()) ++bad;
            if (!uamm4PzaFreedRestored()) ++bad;
            if (!uamm4PzaNoFoodOrDrinkNeeded())
                ++bad;
        // ---- the part ledger ----
            if (uamm4PartItemTotal() != 9) ++bad;
            if (uamm4PartCleanCount() != 5) ++bad;
            if (uamm4PartFlaggedCount() != 4)
                ++bad;
            if (uamm4PartGarbledCount() != 0)
                ++bad;
            if (uamm4PartCleanCount()
                    + uamm4PartFlaggedCount()
                    + uamm4PartGarbledCount()
                    != uamm4PartItemTotal()) ++bad;
        // ---- the R383 part-3 seam ----
            if (uamm3PartItemTotal() != 11) ++bad;
            if (uamm3PartCleanCount() != 2) ++bad;
            if (uamm3PartFlaggedCount() != 9)
                ++bad;
            if (uamm3PartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (!uadsRowBodiesGarble()) ++bad;
        printf("R384 UA misc magic prose part 4 pin audit: bad %d\n", bad);
        if (bad) return 1;
    }"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R384 audit')


s = rd(RT)
assert s.count(
    'R384 UA misc magic prose part 4 pin audit: bad '
) == 1, 'd audit line'
assert s.count(
    'R383 UA misc magic prose part 3 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R382 UA misc magic prose part 2 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R381 UA misc magic prose part 1 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R380 UA new wands prose pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R379 UA new rods staves prose pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R378 UA new rings prose pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R377 UA new scrolls protection pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R376 UA new potions prose part 1 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R375 UA determination skeleton pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R374 UA treasure dial pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R373 UA comeliness note pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R372 UA cavalier followers pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R371 UA expanded armor pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R370 UA DM-section smalls pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R369 UA cantrip acquisition pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R368 UA Cavaliers Table I pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R367 UA social/birth pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R366 UA DM-section spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R365 UA IL 6th/7th and DM pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R364 UA IL 3rd/4th/5th spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R363 UA IL cantrips/1st/2nd pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R362 UA MU 8th/9th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R361 UA MU 7th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R360 UA MU 5th/6th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R359 UA MU 4th level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R358 UA MU 3rd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R357 UA MU 2nd level spells pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R356 UA MU 1st level spells pin audit: bad '
) == 1, 'd kept'
assert s.count('audit: bad ') == 311, 'd census 311'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uamiscprose4.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uamiscprose3.h"'
) == 1, 'd kept include'
for h in (
        'rules/cavalier.h',
        'rules/classtables.h',
        'rules/uabirth.h',
        'rules/uasocialclass.h',
        'rules/uaspellbooks.h',
        'rules/uaspellcomment.h',
        'rules/uauwspelluse.h',
        'rules/uadarkness.h',
        'rules/uacavtable.h',
        'rules/uacantacq.h',
        'rules/uasmalls1.h',
        'rules/uailacquisition.h',
        'rules/thiefarmor.h',
        'rules/armorratings.h',
        'rules/comeliness.h',
        'rules/uaweapontable.h',
        'rules/uamissile.h',
        'rules/uanewweapons.h',
        'rules/uafollowers.h',
        'rules/uacomnote.h',
        'rules/uatreasuredial.h',
        'rules/uadetskel.h',
        'rules/uapotprose.h',
        'rules/uaprotscr.h',
        'rules/uaringprose.h',
        'rules/uarodstave.h',
        'rules/uawandprose.h',
        'rules/uamiscprose1.h',
        'rules/uamiscprose2.h',
        'rules/uamiscprose3.h',
        'rules/treasdet.h',
        'rules/hoard.h'):
    assert s.count(
        '#include "' + h + '"'
        ) == 1, 'd kept include'
for i in range(1, 8):
    assert s.count(
        '#include "rules/uailspells%d.h"'
        % i) == 1, 'd il include'
for i in range(1, 10):
    assert s.count(
        '#include "rules/uamuspells%d.h"'
        % i) == 1, 'd mu include'
assert len(applied) + len(already) == 4, 'd count'


# ---- the summary ----
print(
    'R384 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R384 note: the misc magic',
    'prose part 4 round - the',
    'I-P stretch, nine items',
    'pin: five fully clean (the',
    'iron bands of Bilarro, the',
    'lens of detection, the',
    'mantle of Celestian, the',
    'pearl of the sirines, the',
    'pouch of accessibility)',
    'plus four mechanics-clean',
    'with flagged holes (the',
    "lens of ultravision,",
    "Murlynd's spoon, the",
    "philosopher's stone, the",
    'prison of Zagyg); nothing',
    'in I-P fully garbles - the',
    'item AMENDED, stays OPEN',
    'for Q-Z, PDF-gated; the',
    'R383 seam the part-3',
    'ledger, the R375 seam the',
    'misc band; the census',
    '310 -> 311'
])
print(NOTE)
print('commit: R384: the UA misc')
print('magic prose part 4 pin round')
print('(census 311)')

