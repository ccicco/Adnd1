
# R391: the UA pole-arm
# nomenclature appendix T pin
# round: the pp. 123-129
# stretch, SEVEN items pin -
# TWO fully clean (the spear
# family, the axe family) plus
# FIVE mechanics-clean with
# flagged holes (the
# classification system
# paragraph, the fauchard
# description, the Lucern/bec
# comparison tail, the
# combination intro and
# features list, the confusion
# sentence); NOTHING fully
# garbles - every
# classification survives its
# scrambled prose - the item
# AMENDED with the R391 note,
# the prose pinned, the R340
# seam the hook fauchard
# roster; the census
# 317 -> 318.
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


# ---- (a) the seed: the R390
# record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R390 landed 2026-10-12: commit',
    '  ade8785, census 317, the UA',
    '  non-lethal combat appendix R',
    '  pin round (rules/uaappendr.h):',
    '  the pp. 109-110 stretch, 85',
    '  uanl pins, seven items pin -',
    '  two fully clean (the subdual',
    '  eligibility, the subdual',
    '  damage accounting) plus five',
    '  mechanics-clean with flagged',
    '  holes (the subdual supercedes',
    '  sentence, the vanquishing',
    '  loser sentence, the chaotic',
    '  constraints line, the',
    '  monks-druids garble head,',
    '  the disarming scimitar',
    '  seam); nothing fully',
    '  garbles; the R159 overlap',
    '  reconciled (the DMG p.67',
    '  knockout stays the engine',
    '  default, the UA subdual pins',
    '  as its own data layer), the',
    '  R389 seam the System II',
    '  weaponless layer; GREEN on',
    '  the first run.',
])
s = rd(SD)
if 'R390 landed 2026-10-12' in s:
    already.append('seed: the R390 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R390 record')
s = rd(SD)
assert s.count(
    'R390 landed 2026-10-12'
) == 1, 'a entry'


s = rd(SD)
assert s.count(
    'R389 landed 2026-10-12'
) == 1, 'a R389 kept'


s = rd(SD)
assert s.count(
    'R388 landed 2026-10-12'
) == 1, 'a R388 kept'


s = rd(SD)
assert s.count(
    'R387 landed 2026-10-12'
) == 1, 'a R387 kept'


s = rd(SD)
assert s.count(
    'R386 landed 2026-10-12'
) == 1, 'a R386 kept'


s = rd(SD)
assert s.count(
    'R385 landed 2026-10-12'
) == 1, 'a R385 kept'


s = rd(SD)
assert s.count(
    'R384 landed 2026-10-12'
) == 1, 'a R384 kept'


s = rd(SD)
assert s.count(
    'R383 landed 2026-10-12'
) == 1, 'a R383 kept'


s = rd(SD)
assert s.count(
    'R382 landed 2026-10-12'
) == 1, 'a R382 kept'


s = rd(SD)
assert s.count(
    'R381 landed 2026-10-12'
) == 1, 'a R381 kept'


s = rd(SD)
assert s.count(
    'R380 landed 2026-10-12'
) == 1, 'a R380 kept'


s = rd(SD)
assert s.count(
    'R379 landed 2026-10-12'
) == 1, 'a R379 kept'


s = rd(SD)
assert s.count(
    'R378 landed 2026-10-12'
) == 1, 'a R378 kept'


s = rd(SD)
assert s.count(
    'R377 landed 2026-10-12'
) == 1, 'a R377 kept'


s = rd(SD)
assert s.count(
    'R376 landed 2026-10-12'
) == 1, 'a R376 kept'


s = rd(SD)
assert s.count(
    'R375 landed 2026-10-12'
) == 1, 'a R375 kept'


s = rd(SD)
assert s.count(
    'R374 landed 2026-10-12'
) == 1, 'a R374 kept'


s = rd(SD)
assert s.count(
    'R373 landed 2026-10-12'
) == 1, 'a R373 kept'


s = rd(SD)
assert s.count(
    'R372 landed 2026-10-12'
) == 1, 'a R372 kept'


s = rd(SD)
assert s.count(
    'R371 landed 2026-10-12'
) == 1, 'a R371 kept'


s = rd(SD)
assert s.count(
    'R370 landed 2026-10-12'
) == 1, 'a R370 kept'


s = rd(SD)
assert s.count(
    'R369 landed 2026-10-12'
) == 1, 'a R369 kept'


s = rd(SD)
assert s.count(
    'R368 landed 2026-10-12'
) == 1, 'a R368 kept'


s = rd(SD)
assert s.count(
    'R367 landed 2026-10-12'
) == 1, 'a R367 kept'


s = rd(SD)
assert s.count(
    'R366 landed 2026-10-12'
) == 1, 'a R366 kept'


s = rd(SD)
assert s.count(
    'R365 landed 2026-10-12'
) == 1, 'a R365 kept'


s = rd(SD)
assert s.count(
    'R363 landed 2026-10-11'
) == 1, 'a R363 kept'


s = rd(SD)
assert s.count(
    'R362 landed 2026-10-11'
) == 1, 'a R362 kept'


s = rd(SD)
assert s.count(
    'R361 landed 2026-10-11'
) == 1, 'a R361 kept'


s = rd(SD)
assert s.count(
    'R360 landed 2026-10-11'
) == 1, 'a R360 kept'


s = rd(SD)
assert s.count(
    'R359 landed 2026-10-11'
) == 1, 'a R359 kept'


s = rd(SD)
assert s.count(
    'R358 landed 2026-10-11'
) == 1, 'a R358 kept'


s = rd(SD)
assert s.count(
    'R357 landed 2026-10-11'
) == 1, 'a R357 kept'


s = rd(SD)
assert s.count(
    'R356 landed 2026-10-11'
) == 1, 'a R356 kept'


s = rd(SD)
assert s.count(
    'R355 landed 2026-10-11'
) == 1, 'a R355 kept'


s = rd(SD)
assert s.count(
    'R354 landed 2026-10-11'
) == 1, 'a R354 kept'


s = rd(SD)
assert s.count(
    'R352 landed 2026-10-11'
) == 1, 'a R352 kept'


s = rd(SD)
assert s.count(
    'R351 landed 2026-10-11'
) == 1, 'a R351 kept'


s = rd(SD)
assert s.count(
    'R350 landed 2026-10-11'
) == 1, 'a R350 kept'


s = rd(SD)
assert s.count(
    'R349 landed 2026-10-11'
) == 1, 'a R349 kept'


s = rd(SD)
assert s.count(
    'R347 landed 2026-10-11'
) == 1, 'a R347 kept'


s = rd(SD)
assert s.count(
    'R343 landed 2026-10-11'
) == 1, 'a R343 kept'
assert s.count(
    '## Knowledge maintenance'
) == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'


# ---- (b) NEW rules/uaappendt.h ----
P = 'rules/uaappendt.h'
if os.path.exists(P) and 'R391' in rd(P):
    already.append('uaappendt.h: the pins')
else:
    HDR = r"""// ==========================================================================
// Adnd1 - rules/uaappendt.h
// The UA APPENDIX T: POLE-ARM
// NOMENCLATURE pins, R391: the
// pp. 123-129 stretch - seven
// items, two fully clean (the
// spear family, the axe family)
// plus five mechanics-clean with
// flagged holes (the
// classification system
// paragraph, the fauchard
// description, the Lucern/bec
// comparison tail, the
// combination intro and features
// list, the confusion sentence).
// Nothing fully garbles - every
// classification survives its
// scrambled prose. The taxonomy
// pairs with the R340 new
// weapons roster (the hook
// fauchard seam). Pin-era
// pattern (R322).
namespace rules {

// The definition: a pole arm
// is a weapon on the end of a
// stick.
inline bool uapaDefWeaponOnStick()
    { return true; }
// Pole arms are infantry
// weapons.
inline bool uapaInfantryWeapons()
    { return true; }
// The reach lets the wielder
// strike first or hold the
// enemy at a distance.
inline bool uapaReachAdvantage()
    { return true; }
// The ultimate pole arm: the
// 18-21 foot pike.
inline int uapaUltimatePikeMinFt()
    { return 18; }
// The pike upper bound.
inline int uapaUltimatePikeMaxFt()
    { return 21; }
// An axe blade on a 5-foot
// haft is just as much a pole
// arm.
inline bool uapaAxeOnFiveFtHaftStillPoleArm()
    { return true; }
// The classification
// presupposes a haft or shaft
// of not less than 5 feet.
inline int uapaMinHaftLengthFt()
    { return 5; }
// The illustrations: about
// 1/20 of actual size.
inline int uapaScaleDrawingDivisor()
    { return 20; }
// The scale lance: 15 feet
// long in scale.
inline int uapaScaleLanceFeet()
    { return 15; }
// The scale applies to shaft
// lengths and general blade
// size, not thickness or
// complex blade detail.
inline bool uapaShaftThicknessNotScale()
    { return true; }
// Authors brand one weapon
// under a mistaken
// classification, confusing
// the reader.
inline bool uapaNamingConfusionCommon()
    { return true; }
// The print example: Saxtorph
// identifies an obvious
// morning star as a mace.
inline bool uapaSaxtorphMorningStarMisnamed()
    { return true; }
// A mace: short-shafted,
// flanged head, cast in one
// piece.
inline bool uapaMaceShortShaftedFlanged()
    { return true; }
// A morning star: longer,
// infantry, wooden shaft and
// head with radiating spikes.
inline bool uapaMorningStarLongerSpiked()
    { return true; }
// FLAG: the print garbles the
// system-rationale paragraph
// head (the "reasonable"
// line) - the classification
// standard recovers only in
// part.
inline bool uapaSystemParagraphGarbles()
    { return true; }
// Most medieval weapons:
// hunting weapons or
// agricultural implements
// adapted.
inline bool uapaHuntingOrAgriculturalOrigin()
    { return true; }
// Late-period weapons: more
// specialized than their
// models, or combinations
// trying to merge strengths.
inline bool uapaSpecializedOrCombination()
    { return true; }
// The spear is a dagger set
// atop a pole.
inline bool uapaSpearDaggerAtopPole()
    { return true; }
// Principally a thrusting
// weapon.
inline bool uapaSpearThrustingPrimary()
    { return true; }
// A broad blade (the ox
// tongue) gives a secondary
// cutting function when
// lengthened.
inline bool uapaOxTongueSecondaryCutting()
    { return true; }
// Spears of about 12 feet:
// the ash spears of English
// writings.
inline int uapaAshSpearTwelveFt()
    { return 12; }
// At such length often
// confused with pikes.
inline bool uapaSpearConfusedWithPikes()
    { return true; }
// A lance is a long spear
// carried by a mounted man.
inline bool uapaLanceMountedSpear()
    { return true; }
// Norman lances: about 12
// feet, some less.
inline int uapaNormanLanceFt()
    { return 12; }
// Later Middle Ages: an
// average of about 14 feet.
inline int uapaLaterLanceFt()
    { return 14; }
// Gives the horseman about 10
// feet of reach beyond the
// horse's head when charging.
inline int uapaLanceReachBeyondHorseHeadFt()
    { return 10; }
// The lance is a horseman
// weapon, not a true
// footman's pole arm.
inline bool uapaLanceNotFootmansWeapon()
    { return true; }
// Any spear with a shaft of
// 15 feet or longer is
// considered a pike.
inline int uapaPikeShaftMinFt()
    { return 15; }
// The pike delivers a
// thrusting attack at long
// range, keeping the opponent
// there.
inline bool uapaPikeThrustingLongRange()
    { return true; }
// Always used in mass.
inline bool uapaPikeUsedInMass()
    { return true; }
// The awl pike: the most
// common form, strictly
// piercing.
inline bool uapaAwlPikePiercingOnly()
    { return true; }
// Swiss and German pikes:
// metal protects the shaft
// up to 2 feet from the
// head.
inline int uapaPikeShaftGuardFt()
    { return 2; }
// The spetum: a sharp,
// tapering point plus two
// blades pointing forward.
inline bool uapaSpetumTwoForwardBlades()
    { return true; }
// The side blades point
// forward at about 45
// degrees.
inline int uapaSpetumBladeAngleDeg()
    { return 45; }
// Same class: the corseques
// or korsekes.
inline bool uapaSpetumClassCorseque()
    { return true; }
// The ranseur: backward-
// hooking projections set
// well below the large
// central blade.
inline bool uapaRanseurBackwardHooks()
    { return true; }
// A twist of the shaft
// breaks a caught weapon or
// disarms its wielder.
inline bool uapaRanseurTrapAndDisarm()
    { return true; }
// The projections hold an
// opponent at range or pull
// mounted opponents off the
// horse.
inline bool uapaRanseurPullsRidersDown()
    { return true; }
// Synonyms: chauve souris,
// ransom, rhonca, roncie,
// runka - five.
inline int uapaRanseurSynonymCount()
    { return 5; }
// The partisan: a spear,
// often with an ox tongue
// blade, plus a pair of small
// axe heads below the dagger
// blade.
inline bool uapaPartisanSpearWithAxeHeads()
    { return true; }
// The Bohemian earspoon: the
// axes become piercing spikes
// against plate, with a
// ranseur-like function.
inline bool uapaBohemianEarspoonSpikes()
    { return true; }
// The family: the spear
// proper, the pike, the
// spetum, the ranseur, the
// partisan - five.
inline int uapaSpearFamilyCount()
    { return 5; }
// All are daggers atop a
// sturdy pole with trimmings
// for efficiency.
inline bool uapaSpearFamilyDaggersTrimmed()
    { return true; }
// Two basic head forms:
// broad and narrow.
inline int uapaAxeHeadFormCount()
    { return 2; }
// The narrow form is thicker,
// for the necessary weight.
inline bool uapaNarrowHeadThicker()
    { return true; }
// The cleaver: a butchering
// tool adapted for military
// use.
inline bool uapaCleaverButcheringAdapted()
    { return true; }
// The axe and cleaver
// families chop at the
// opponent rather than
// thrust.
inline bool uapaAxePrimaryChopping()
    { return true; }
// A pole axe: an axe head on
// a long haft for an
// earlier, more forceful
// blow.
inline bool uapaPoleAxeAxeHeadLongHaft()
    { return true; }
// Can be double-bitted,
// spike-backed and/or
// dagger-topped - still
// recognizable as an axe.
inline bool uapaPoleAxeVariants()
    { return true; }
// The halberd: a convex-
// headed broad axe, the head
// set at a convenient angle.
inline bool uapaHalberdConvexBroadAxe()
    { return true; }
// The whole weapon often
// reached 8 feet.
inline int uapaHalberdTotalFt()
    { return 8; }
// Always topped with a fairly
// long spear point.
inline bool uapaHalberdSpearPointTop()
    { return true; }
// Backed by a spike, often
// angled or hooked slightly
// downward.
inline bool uapaHalberdBackSpikeAngled()
    { return true; }
// The opposing spike
// penetrates heavy plate
// armor.
inline bool uapaHalberdSpikePenetratesPlate()
    { return true; }
// The spike doubles as a hook
// for dismounting opponents.
inline bool uapaHalberdHookDismounts()
    { return true; }
// Useless vs. mounted lances:
// the Battle of Arbedo,
// 1422.
inline int uapaHalberdArbedoYear()
    { return 1422; }
// Some heads made smaller (
// the piercing axe) to
// penetrate armor better.
inline bool uapaHalberdPiercingAxeSmaller()
    { return true; }
// Many weapons pictured in
// texts are fanciful parade
// arms, not battle arms.
inline bool uapaParadeArmsExist()
    { return true; }
// The bardiche: a broad,
// heavy axe linking pole axes
// to pole cleavers.
inline bool uapaBardicheTransitionalForm()
    { return true; }
// The bardiche head: from
// about 2 feet in length.
inline int uapaBardicheHeadMinFt()
    { return 2; }
// To over 3 feet.
inline int uapaBardicheHeadMaxFt()
    { return 3; }
// Attached with two rings,
// or one when the shorter
// blade is backed with a
// hammer head or spike.
inline bool uapaBardicheRingsOrHammerBack()
    { return true; }
// Very heavy and cumbersome
// - more so by far than a
// halberd.
inline bool uapaBardicheHeavierThanHalberd()
    { return true; }
// Used principally in
// Eastern Europe.
inline bool uapaBardicheEasternEurope()
    { return true; }
// The true members: the pole
// axe, the halberd (possibly
// the brown bill), the
// bardiche - three.
inline int uapaAxeFamilyTrueMemberCount()
    { return 3; }
// Per Oman: the English brown
// bill was a halberd in all
// respects save the back
// spike.
inline bool uapaBrownBillHalberdSansSpike()
    { return true; }
// The pole cleaver: an
// outraged peasant fastened
// his meat cleaver to a
// stave.
inline bool uapaPeasantCleaverOrigin()
    { return true; }
// The fauchard: a development
// of the scythe or sickle -
// a cutting blade set upon a
// pole.
inline bool uapaFauchardSickleDevelopment()
    { return true; }
// For cutting, catching and
// holding, parrying and
// dismounting.
inline bool uapaFauchardDismountFunction()
    { return true; }
// FLAG: the print scrambles
// the fauchard description
// body into column order -
// the classification
// survives, the prose
// garbles.
inline bool uapaFauchardGarblesFull()
    { return true; }
// The fauchard passed out
// rather quickly.
inline bool uapaFauchardPassedOutEarly()
    { return true; }
// Its combination form, the
// fauchard-fork, remained.
inline bool uapaFauchardForkRemained()
    { return true; }
// The glaive: a knife-bladed
// spear.
inline bool uapaGlaiveKnifeBladedSpear()
    { return true; }
// The thrust of the spear
// plus the secondary cutting
// of the convex knife blade.
inline bool uapaGlaiveThrustPlusCutting()
    { return true; }
// The blade rapidly enlarged
// to give a cleaving
// function.
inline bool uapaGlaiveEnlargedForCleaving()
    { return true; }
// The modifications produced
// the glaive-guisarme (the
// combination arms section).
inline bool uapaGlaiveGuisarmeModification()
    { return true; }
// As with the fauchard, not
// overly effective at
// holding opponents, and no
// piercing back.
inline bool uapaGlaiveWeakAtHolding()
    { return true; }
// The guisarme: pruning hooks
// made reasonably effective
// pole arms.
inline bool uapaGuisarmePruningHookOrigin()
    { return true; }
// A sharp cutting edge along
// the convex side, from
// reverse spike to hook.
inline bool uapaGuisarmeSharpConvexEdge()
    { return true; }
// The curved hook pulls
// horsemen to the ground.
inline bool uapaGuisarmeHookPullsHorsemen()
    { return true; }
// Deficiencies: no spear
// point for thrusting, one
// projection for
// penetrating.
inline bool uapaGuisarmeNoSpearPoint()
    { return true; }
// Soon combined into a
// second generation of
// all-purpose pole arms.
inline bool uapaGuisarmeSecondGeneration()
    { return true; }
// The voulge: a hefty cleaver
// on a long, stout shaft.
inline bool uapaVoulgeHeftyCleaverShaft()
    { return true; }
// The leverage lets the
// wielder cleave through
// armor.
inline bool uapaVoulgeCleavesArmor()
    { return true; }
// A ground-down front or back
// edge gives a dagger-like
// tip - the more complete
// form.
inline bool uapaVoulgeGroundTipDagger()
    { return true; }
// Sometimes backed with a
// spike or hooked spike -
// the crude guisarme-
// voulge.
inline bool uapaVoulgeBackedSpikeCrude()
    { return true; }
// The Lochaber axe in early,
// crude forms: the same as a
// voulge.
inline bool uapaLochaberEarlyFormVoulge()
    { return true; }
// Development added a hook,
// as a tip or blade backing.
inline bool uapaLochaberHookAdded()
    { return true; }
// In that form nearly
// identical to the guisarme-
// voulge - no real
// differentiation.
inline bool uapaLochaberEqualsGuisarmeVoulge()
    { return true; }
// The Scots developed the
// Lochaber axe; the Continent
// the voulge - the same
// thing.
inline bool uapaLochaberScotsVoulgeContinental()
    { return true; }
// The English bill hook:
// almost exactly the French
// guisarme.
inline bool uapaBillHookEnglishGuisarme()
    { return true; }
// Its concave (hook) edge is
// the sharp one.
inline bool uapaBillConcaveEdgeSharp()
    { return true; }
// An L-shaped tine projects
// forward instead of a
// straight back spike.
inline bool uapaBillLTineForward()
    { return true; }
// Slightly more effective
// than the European
// guisarme.
inline bool uapaBillSlightlyMoreEffective()
    { return true; }
// The military fork: the
// lowly hay fork,
// straightened and
// strengthened.
inline bool uapaMilitaryForkHayForkOrigin()
    { return true; }
// Two efficient piercing
// points for holding off an
// enemy.
inline int uapaMilitaryForkTwoPoints()
    { return 2; }
// Sometimes a shorter third
// tine in the crotch -
// opponents are channeled
// into a third attack.
inline bool uapaMilitaryForkThirdTine()
    { return true; }
// The major drawback: lack
// of penetrating power vs.
// heavily armored targets.
inline bool uapaMilitaryForkWeakVsArmor()
    { return true; }
// The threshing flail: a
// wooden handle plus billet
// joined by a swivel or
// chain links.
inline bool uapaFlailSwivelOrChain()
    { return true; }
// Horsemen used a short-
// hafted flail with chains
// ending in smooth or
// spiked iron balls.
inline bool uapaHorsemanFlailIronBalls()
    { return true; }
// The peasant flail: a heavy
// shaft of about 3 feet.
inline int uapaPeasantFlailShaftMinFt()
    { return 3; }
// To 4 feet in length.
inline int uapaPeasantFlailShaftMaxFt()
    { return 4; }
// Hung with one or two
// metal-shod, spiked rods of
// wood or iron.
inline bool uapaPeasantFlailOneOrTwoRods()
    { return true; }
// The whole weapon over 5
// feet, with tremendous
// penetration and crushing
// power.
inline bool uapaPeasantFlailOverFiveFt()
    { return true; }
// The morning star: a heavy
// wooden haft from 3 feet or
// more in length.
inline bool uapaMorningStarHaftThreeFt()
    { return true; }
// A cylinder, barrel or
// truncated cone, metal-
// bound and set with vicious
// metal spikes.
inline bool uapaMorningStarSpikedHead()
    { return true; }
// Also called the holy water
// sprinkler.
inline bool uapaMorningStarHolyWaterSprinkler()
    { return true; }
// Or the godentag in the Low
// Countries.
inline bool uapaMorningStarGodentag()
    { return true; }
// Used extensively by the
// Swiss until the halberd
// replaced it.
inline bool uapaMorningStarSwissThenHalberd()
    { return true; }
// Often spear-tipped in
// longer form - some models
// long enough to be pole
// arms.
inline bool uapaMorningStarSometimesPoleArm()
    { return true; }
// Some military picks
// pole-mounted, shafts of 5
// feet or greater.
inline bool uapaMilitaryPicksPoleMounted()
    { return true; }
// Two pole arms developed
// purely as weapons -
// similar but separate and
// distinct.
inline bool uapaTwoPureWeaponForms()
    { return true; }
// The Lucern hammer: very
// similar to the halberd.
inline bool uapaLucernLikeHalberd()
    { return true; }
// Its end spike generally
// longer than a halberd.
inline bool uapaLucernLongerSpike()
    { return true; }
// A smaller, hammer-like
// head with three prongs
// instead of an axe head.
inline bool uapaLucernThreeProngHead()
    { return true; }
// Less efficient vs. armor -
// replaced by the halberd
// amongst the Swiss.
inline bool uapaLucernReplacedByHalberd()
    { return true; }
// Replaced after the 14th
// century.
inline int uapaLucernAfterCentury()
    { return 14; }
// The bec de corbin: used
// late by knights and nobles,
// not commoners.
inline bool uapaBecDeCorbinKnightsWeapon()
    { return true; }
// The heavy crow's-beak
// blade punctures the heavy
// plate of upper-class
// warriors.
inline bool uapaBecDeCorbinBeakPunctures()
    { return true; }
// In this weapon the beak is
// the major feature.
inline bool uapaBecDeCorbinBeakMajor()
    { return true; }
// The bec de corbin more
// specialized than the Lucern
// hammer.
inline bool uapaBecMoreSpecializedThanLucern()
    { return true; }
// FLAG: the print garbles the
// Lucern/bec de corbin
// comparison tail into column
// order - the classifications
// survive, the prose
// garbles.
inline bool uapaLucernBecComparisonGarbles()
    { return true; }
// Technically, all pole arms
// with a secondary spear tip
// are combination weapons.
inline bool uapaSecondarySpearTipCombination()
    { return true; }
// The partisan stays in the
// spear family - primarily a
// thrusting weapon.
inline bool uapaPartisanNotCombination()
    { return true; }
// FLAG: the print garbles the
// combination intro (the
// "to ignore" line) - the
// doctrine recovers in
// part.
inline bool uapaCombinationIntroGarbles()
    { return true; }
// The fauchard-fork: two
// general forms.
inline int uapaFauchardForkFormCount()
    { return 2; }
// The first follows the
// typical fauchard form with
// a single spike projecting
// from the back.
inline bool uapaFauchardForkFormOneBackSpike()
    { return true; }
// The second reverses the
// scythe blade - concave edge
// toward the opponent, more
// curved and sicklelike, a
// spike tipping the pole end.
inline bool uapaFauchardForkFormTwoReversed()
    { return true; }
// The fauchard-guisarme: a
// scythe blade backed by a
// heavy hook for dismounting.
inline bool uapaFauchardGuisarmeScytheHook()
    { return true; }
// The glaive-guisarme: a
// heavier, longer glaive head
// plus a guisarme hook to
// jerk horsemen from their
// seats.
inline bool uapaGlaiveGuisarmeHookJerks()
    { return true; }
// The guisarme-voulge: like
// the Lochaber axe, but the
// hook is formed from the
// voulge blade itself.
inline bool uapaGuisarmeVoulgeHookFromBlade()
    { return true; }
// Featured the pointed tip or
// spike so as to be as
// all-purpose as possible.
inline bool uapaGuisarmeVoulgeAllPurpose()
    { return true; }
// The bill-guisarme features:
// a sharp spear or awl point,
// a large hook from the body,
// a back spike for armor
// penetration, and several
// cutting edges - four.
inline int uapaBillGuisarmeFeatureCount()
    { return 4; }
// FLAG: the print splits the
// features list (the "armor
// ion" cell) - the roster
// recovers, the prose
// garbles.
inline bool uapaBillGuisarmeFeaturesGarble()
    { return true; }
// Some bill-guisarmes have
// sufficiently heavy blades
// and cutting edges to be
// voulge-like.
inline bool uapaBillGuisarmeVoulgeLike()
    { return true; }
// Persisted the longest of
// all save the pike and the
// halberd - efficient in all
// functions.
inline bool uapaBillGuisarmePersistedLongest()
    { return true; }
// The scorpion: one typical
// form of the bill-guisarme.
inline bool uapaScorpionBillGuisarmeForm()
    { return true; }
// A weapon with an added
// feature is identified by the
// major weapon, not the
// added part.
inline bool uapaIdentifyByMajorWeapon()
    { return true; }
// An axe head on what is
// basically a spear (the
// partisan) is not a pole
// axe - a thrusting weapon
// with secondary functions.
inline bool uapaPartisanWithAxeNotPoleAxe()
    { return true; }
// The glaring example: Stone
// identifies a halberd with a
// fork tip as a military
// fork.
inline bool uapaStoneForkMisidentified()
    { return true; }
// A halberd-sized pole: simply
// a halberd with an
// incidental fork atop it.
inline bool uapaHalberdWithIncidentalFork()
    { return true; }
// FLAG: the print cuts the
// confusion sentence tail
// ("is certainly") - the
// caution recovers in part.
inline bool uapaConfusionSentenceGarbles()
    { return true; }
// Careful examination of the
// shaft length and head shape
// gives the identity clues.
inline bool uapaCareShaftLengthHeadShape()
    { return true; }
// The pole arm put infantry on
// even terms with cavalry.
inline bool uapaInfantryVsCavalryPurpose()
    { return true; }
// The Swiss mixed pike,
// halberd/Lucern hammer and
// morning star - 40 pike as
// an average.
inline int uapaSwissPikePct()
    { return 40; }
// 40 halberd/Lucern hammer.
inline int uapaSwissHalberdPct()
    { return 40; }
// 20 morning star - 40-40-20
// as an average.
inline int uapaSwissMorningStarPct()
    { return 20; }
// The pike proliferated: most
// useful for keeping horsemen
// at a distance.
inline bool uapaPikeKeepsHorsemenDistant()
    { return true; }
// Swiss pikemen held the rear
// of the shaft higher, forcing
// glancing points downward -
// not grounding the butt.
inline bool uapaPikemenRearHigher()
    { return true; }
// Massive-headed pole arms
// were inefficient when
// lengthened past a limit -
// too cumbersome to wield.
inline bool uapaMassiveHeadsTooCumbersome()
    { return true; }
// Spear-type pole arms
// lengthened to pikes were
// then called just that.
inline bool uapaSpearTypesLengthenedToPikes()
    { return true; }
// The pike shaft is too long
// for useful ranseur or
// partisan heads.
inline bool uapaPikeShaftTooLongForHeads()
    { return true; }
// Shortened cleaving weapons:
// less efficient than the
// halberd, or changed to
// become almost
// indistinguishable from it.
inline bool uapaShortenedCleaversToHalberd()
    { return true; }
// The typically indistin-
// guishable forms: the
// guisarme-voulge.
inline bool uapaGuisarmeVoulgeTypically()
    { return true; }
// The pole arm evolution
// reflects the trends in
// armor and tactics in
// medieval warfare.
inline bool uapaEvolutionReflectsArmor()
    { return true; }
// The system derived from
// early reading of the
// Encyclopedia Britannica and
// ffoulkes's book.
inline bool uapaSystemDerivedBritannica()
    { return true; }
// The bibliography: Ashdown,
// ffoulkes, Oman, Saxtorph,
// the Britannica - five.
inline int uapaBibliographySourceCount()
    { return 5; }
// The item ledger: seven
// items.
inline int uapaPartItemTotal()
    { return 7; }
// Two fully clean (the spear
// family, the axe family).
inline int uapaPartCleanCount()
    { return 2; }
// Five mechanics-clean with
// flagged holes (the
// classification system
// paragraph, the fauchard
// description, the Lucern/bec
// comparison tail, the
// combination intro and
// features list, the
// confusion sentence).
inline int uapaPartFlaggedCount()
    { return 5; }
// Nothing fully garbles -
// every classification
// survives its scrambled
// prose.
inline int uapaPartGarbledCount()
    { return 0; }
}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uaappendt.h: the pins')



s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 161, 'b inline count'
assert s.count('R391') == 1, 'b round tag'
assert s.count(
    'uapaFauchardForkRemained'
    ) >= 1, 'b fn'
assert 'uafol' not in s, 'b no uafol ref'
assert 'uanw' not in s, 'b no uanw ref'
assert 'uacm' not in s, 'b no uacm ref'
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
assert 'uamm' not in s, 'b no uamm ref'
assert 'uaasp' not in s, 'b no uaasp ref'
assert 'uanl' not in s, 'b no uanl ref'
assert 'uaq' not in s, 'b no uaq ref'
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert 'uanwHookFauchard' not in s, 'b no uanwHookFauchard ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (c) the gap report: the
# amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R391' in s:
    already.append('gap: the amendment')
else:
    OLD = NL.join([
        '- [ ] **Appendix T: pole-arm',
        '      nomenclature** (pp. 123-129) - the',
        '      taxonomy (the bill hook, the',
        '      fauchard-guisarme, the voulge, the',
        '      pike, the axe family); a data',
        '      charge that pairs with the new',
        '      weapon tables.',
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = OLD + NL + NL.join([
        '      - AMENDED R391: the UA',
        '        pole-arm nomenclature',
        '        appendix T pin round',
        '        (rules/uaappendt.h) - the',
        '        pp. 123-129 stretch,',
        '        SEVEN items pin: TWO',
        '        fully clean (the spear',
        '        family, the axe family)',
        '        plus FIVE mechanics-clean',
        '        with flagged holes (the',
        '        classification system',
        '        paragraph, the fauchard',
        '        description, the Lucern/',
        '        bec comparison tail, the',
        '        combination intro and',
        '        features list, the',
        '        confusion sentence);',
        '        NOTHING fully garbles -',
        '        every classification',
        '        survives its scrambled',
        '        prose - the item AMENDED,',
        '        the prose pinned, the',
        '        R340 seam the hook',
        '        fauchard roster, stays',
        '        PDF-gated only.',
    ])
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    applied.append('gap: the amendment')
wr(GP, s)



s = rd(GP)
assert s.count(
    '- [ ] **The new miscellaneous magic'
) == 1, 'c item kept open'
assert s.count(
    '- [ ] **The random determination'
) == 1, 'c item kept open'
assert s.count(
    '- [ ] **The new potions**'
) == 1, 'c item kept open'
assert s.count(
    '- [ ] **The new scrolls**'
) == 1, 'c item kept open'
assert s.count(
    '- [ ] **The new rings**'
) == 1, 'c item kept open'
assert s.count(
    '- [ ] **The new rods and staves**'
) == 1, 'c item kept open'
assert s.count(
    '- [ ] **The new wands**'
) == 1, 'c item kept open'
assert s.count(
    '- [ ] **The new armor and shields and'
) == 1, 'c item kept open'
assert s.count(
    '- [ ] **The new miscellaneous weapons**'
) == 1, 'c item kept open'
assert s.count(
    '- [x] **The comeliness creation note**'
) == 1, 'c kept closed'
assert s.count(
    '- [x] **The cavalier follower tables**'
) == 1, 'c kept closed'
assert s.count(
    '- [ ] **The Armor Class Table**'
) == 1, 'c item kept open'
assert s.count(
    '- [ ] **Appendix Q: weaponless combat**'
) == 1, 'c item kept open'
assert s.count(
    '- [ ] **Appendix R: non-lethal combat**'
) == 1, 'c item kept open'
assert s.count(
    '- [ ] **Appendix S: non-human deities**'
) == 1, 'c item kept open'
assert s.count(
    '- [ ] **Appendix T: pole-arm'
) == 1, 'c item kept open'
assert s.count(
    'AMENDED R391'
) == 1, 'c amendment'
assert s.count(
    'AMENDED R390'
) == 1, 'c r390 amendment kept'
assert s.count(
    'AMENDED R389'
) == 1, 'c r389 amendment kept'
assert s.count(
    'AMENDED R388'
) == 1, 'c r388 amendment kept'
assert s.count(
    'AMENDED R387'
) == 1, 'c r387 amendment kept'
assert s.count(
    'AMENDED R386'
) == 1, 'c r386 amendment kept'
assert s.count(
    'AMENDED R385'
) == 1, 'c r385 amendment kept'
assert s.count(
    'AMENDED R384'
) == 1, 'c r384 amendment kept'
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
    '(rules/uaappendt.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uaappendr.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uaappendq.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uamweapprose.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uaarmprose.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uamiscprose6.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uamiscprose5.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uamiscprose4.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uamiscprose3.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uamiscprose2.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uamiscprose1.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uawandprose.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uarodstave.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uaringprose.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uaprotscr.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uapotprose.h)'
) == 1, 'c note kept'
assert s.count(
    '(rules/uadetskel.h)'
) == 1, 'c note kept'
assert s.count(
    'DECIDED R374'
) == 1, 'c note kept'
assert s.count(
    '### Treasure (pp. 84-106) - THE DECISION'
) == 1, 'c note kept'
assert len(applied) + len(already) == 3, 'c count'


# ---- (d) regtest.cpp: the
# includes, the audit, the
# census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R391 UA pole-arm nomenclature pin audit' in s:
    already.append('regtest.cpp: the R391 audit')
else:
    INC_ANCH = ('#include "rules/uaappendr.h"  // '
        'R390: the UA non-lethal combat')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uaappendt.h"  // R391: the UA pole-arm'
        ' nomenclature'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R391: the UA
    // pole-arm nomenclature
    // appendix T pin audit ----
    // The pp. 123-129 stretch:
    // seven items pin - two
    // fully clean (the spear
    // family, the axe family)
    // plus five mechanics-clean
    // with flagged holes (the
    // classification system
    // paragraph, the fauchard
    // description, the Lucern/
    // bec comparison tail, the
    // combination intro and
    // features list, the
    // confusion sentence); the
    // R340 seam the hook
    // fauchard roster.
    {
        using namespace rules;
        int bad = 0;
            if (!uapaDefWeaponOnStick()) ++bad;
            if (!uapaInfantryWeapons()) ++bad;
            if (!uapaReachAdvantage()) ++bad;
            if (uapaUltimatePikeMinFt() != 18) ++bad;
            if (uapaUltimatePikeMaxFt() != 21) ++bad;
            if (!uapaAxeOnFiveFtHaftStillPoleArm()) ++bad;
            if (uapaMinHaftLengthFt() != 5) ++bad;
            if (uapaScaleDrawingDivisor() != 20) ++bad;
            if (uapaScaleLanceFeet() != 15) ++bad;
            if (!uapaShaftThicknessNotScale()) ++bad;
            if (!uapaNamingConfusionCommon()) ++bad;
            if (!uapaSaxtorphMorningStarMisnamed()) ++bad;
            if (!uapaMaceShortShaftedFlanged()) ++bad;
            if (!uapaMorningStarLongerSpiked()) ++bad;
            if (!uapaSystemParagraphGarbles()) ++bad;
            if (!uapaHuntingOrAgriculturalOrigin()) ++bad;
            if (!uapaSpecializedOrCombination()) ++bad;
            if (!uapaSpearDaggerAtopPole()) ++bad;
            if (!uapaSpearThrustingPrimary()) ++bad;
            if (!uapaOxTongueSecondaryCutting()) ++bad;
            if (uapaAshSpearTwelveFt() != 12) ++bad;
            if (!uapaSpearConfusedWithPikes()) ++bad;
            if (!uapaLanceMountedSpear()) ++bad;
            if (uapaNormanLanceFt() != 12) ++bad;
            if (uapaLaterLanceFt() != 14) ++bad;
            if (uapaLanceReachBeyondHorseHeadFt() != 10) ++bad;
            if (!uapaLanceNotFootmansWeapon()) ++bad;
            if (uapaPikeShaftMinFt() != 15) ++bad;
            if (!uapaPikeThrustingLongRange()) ++bad;
            if (!uapaPikeUsedInMass()) ++bad;
            if (!uapaAwlPikePiercingOnly()) ++bad;
            if (uapaPikeShaftGuardFt() != 2) ++bad;
            if (!uapaSpetumTwoForwardBlades()) ++bad;
            if (uapaSpetumBladeAngleDeg() != 45) ++bad;
            if (!uapaSpetumClassCorseque()) ++bad;
            if (!uapaRanseurBackwardHooks()) ++bad;
            if (!uapaRanseurTrapAndDisarm()) ++bad;
            if (!uapaRanseurPullsRidersDown()) ++bad;
            if (uapaRanseurSynonymCount() != 5) ++bad;
            if (!uapaPartisanSpearWithAxeHeads()) ++bad;
            if (!uapaBohemianEarspoonSpikes()) ++bad;
            if (uapaSpearFamilyCount() != 5) ++bad;
            if (!uapaSpearFamilyDaggersTrimmed()) ++bad;
            if (uapaAxeHeadFormCount() != 2) ++bad;
            if (!uapaNarrowHeadThicker()) ++bad;
            if (!uapaCleaverButcheringAdapted()) ++bad;
            if (!uapaAxePrimaryChopping()) ++bad;
            if (!uapaPoleAxeAxeHeadLongHaft()) ++bad;
            if (!uapaPoleAxeVariants()) ++bad;
            if (!uapaHalberdConvexBroadAxe()) ++bad;
            if (uapaHalberdTotalFt() != 8) ++bad;
            if (!uapaHalberdSpearPointTop()) ++bad;
            if (!uapaHalberdBackSpikeAngled()) ++bad;
            if (!uapaHalberdSpikePenetratesPlate()) ++bad;
            if (!uapaHalberdHookDismounts()) ++bad;
            if (uapaHalberdArbedoYear() != 1422) ++bad;
            if (!uapaHalberdPiercingAxeSmaller()) ++bad;
            if (!uapaParadeArmsExist()) ++bad;
            if (!uapaBardicheTransitionalForm()) ++bad;
            if (uapaBardicheHeadMinFt() != 2) ++bad;
            if (uapaBardicheHeadMaxFt() != 3) ++bad;
            if (!uapaBardicheRingsOrHammerBack()) ++bad;
            if (!uapaBardicheHeavierThanHalberd()) ++bad;
            if (!uapaBardicheEasternEurope()) ++bad;
            if (uapaAxeFamilyTrueMemberCount() != 3) ++bad;
            if (!uapaBrownBillHalberdSansSpike()) ++bad;
            if (!uapaPeasantCleaverOrigin()) ++bad;
            if (!uapaFauchardSickleDevelopment()) ++bad;
            if (!uapaFauchardDismountFunction()) ++bad;
            if (!uapaFauchardGarblesFull()) ++bad;
            if (!uapaFauchardPassedOutEarly()) ++bad;
            if (!uapaFauchardForkRemained()) ++bad;
            if (!uapaGlaiveKnifeBladedSpear()) ++bad;
            if (!uapaGlaiveThrustPlusCutting()) ++bad;
            if (!uapaGlaiveEnlargedForCleaving()) ++bad;
            if (!uapaGlaiveGuisarmeModification()) ++bad;
            if (!uapaGlaiveWeakAtHolding()) ++bad;
            if (!uapaGuisarmePruningHookOrigin()) ++bad;
            if (!uapaGuisarmeSharpConvexEdge()) ++bad;
            if (!uapaGuisarmeHookPullsHorsemen()) ++bad;
            if (!uapaGuisarmeNoSpearPoint()) ++bad;
            if (!uapaGuisarmeSecondGeneration()) ++bad;
            if (!uapaVoulgeHeftyCleaverShaft()) ++bad;
            if (!uapaVoulgeCleavesArmor()) ++bad;
            if (!uapaVoulgeGroundTipDagger()) ++bad;
            if (!uapaVoulgeBackedSpikeCrude()) ++bad;
            if (!uapaLochaberEarlyFormVoulge()) ++bad;
            if (!uapaLochaberHookAdded()) ++bad;
            if (!uapaLochaberEqualsGuisarmeVoulge()) ++bad;
            if (!uapaLochaberScotsVoulgeContinental()) ++bad;
            if (!uapaBillHookEnglishGuisarme()) ++bad;
            if (!uapaBillConcaveEdgeSharp()) ++bad;
            if (!uapaBillLTineForward()) ++bad;
            if (!uapaBillSlightlyMoreEffective()) ++bad;
            if (!uapaMilitaryForkHayForkOrigin()) ++bad;
            if (uapaMilitaryForkTwoPoints() != 2) ++bad;
            if (!uapaMilitaryForkThirdTine()) ++bad;
            if (!uapaMilitaryForkWeakVsArmor()) ++bad;
            if (!uapaFlailSwivelOrChain()) ++bad;
            if (!uapaHorsemanFlailIronBalls()) ++bad;
            if (uapaPeasantFlailShaftMinFt() != 3) ++bad;
            if (uapaPeasantFlailShaftMaxFt() != 4) ++bad;
            if (!uapaPeasantFlailOneOrTwoRods()) ++bad;
            if (!uapaPeasantFlailOverFiveFt()) ++bad;
            if (!uapaMorningStarHaftThreeFt()) ++bad;
            if (!uapaMorningStarSpikedHead()) ++bad;
            if (!uapaMorningStarHolyWaterSprinkler()) ++bad;
            if (!uapaMorningStarGodentag()) ++bad;
            if (!uapaMorningStarSwissThenHalberd()) ++bad;
            if (!uapaMorningStarSometimesPoleArm()) ++bad;
            if (!uapaMilitaryPicksPoleMounted()) ++bad;
            if (!uapaTwoPureWeaponForms()) ++bad;
            if (!uapaLucernLikeHalberd()) ++bad;
            if (!uapaLucernLongerSpike()) ++bad;
            if (!uapaLucernThreeProngHead()) ++bad;
            if (!uapaLucernReplacedByHalberd()) ++bad;
            if (uapaLucernAfterCentury() != 14) ++bad;
            if (!uapaBecDeCorbinKnightsWeapon()) ++bad;
            if (!uapaBecDeCorbinBeakPunctures()) ++bad;
            if (!uapaBecDeCorbinBeakMajor()) ++bad;
            if (!uapaBecMoreSpecializedThanLucern()) ++bad;
            if (!uapaLucernBecComparisonGarbles()) ++bad;
            if (!uapaSecondarySpearTipCombination()) ++bad;
            if (!uapaPartisanNotCombination()) ++bad;
            if (!uapaCombinationIntroGarbles()) ++bad;
            if (uapaFauchardForkFormCount() != 2) ++bad;
            if (!uapaFauchardForkFormOneBackSpike()) ++bad;
            if (!uapaFauchardForkFormTwoReversed()) ++bad;
            if (!uapaFauchardGuisarmeScytheHook()) ++bad;
            if (!uapaGlaiveGuisarmeHookJerks()) ++bad;
            if (!uapaGuisarmeVoulgeHookFromBlade()) ++bad;
            if (!uapaGuisarmeVoulgeAllPurpose()) ++bad;
            if (uapaBillGuisarmeFeatureCount() != 4) ++bad;
            if (!uapaBillGuisarmeFeaturesGarble()) ++bad;
            if (!uapaBillGuisarmeVoulgeLike()) ++bad;
            if (!uapaBillGuisarmePersistedLongest()) ++bad;
            if (!uapaScorpionBillGuisarmeForm()) ++bad;
            if (!uapaIdentifyByMajorWeapon()) ++bad;
            if (!uapaPartisanWithAxeNotPoleAxe()) ++bad;
            if (!uapaStoneForkMisidentified()) ++bad;
            if (!uapaHalberdWithIncidentalFork()) ++bad;
            if (!uapaConfusionSentenceGarbles()) ++bad;
            if (!uapaCareShaftLengthHeadShape()) ++bad;
            if (!uapaInfantryVsCavalryPurpose()) ++bad;
            if (uapaSwissPikePct() != 40) ++bad;
            if (uapaSwissHalberdPct() != 40) ++bad;
            if (uapaSwissMorningStarPct() != 20) ++bad;
            if (!uapaPikeKeepsHorsemenDistant()) ++bad;
            if (!uapaPikemenRearHigher()) ++bad;
            if (!uapaMassiveHeadsTooCumbersome()) ++bad;
            if (!uapaSpearTypesLengthenedToPikes()) ++bad;
            if (!uapaPikeShaftTooLongForHeads()) ++bad;
            if (!uapaShortenedCleaversToHalberd()) ++bad;
            if (!uapaGuisarmeVoulgeTypically()) ++bad;
            if (!uapaEvolutionReflectsArmor()) ++bad;
            if (!uapaSystemDerivedBritannica()) ++bad;
            if (uapaBibliographySourceCount() != 5) ++bad;
            if (uapaPartItemTotal() != 7) ++bad;
            if (uapaPartCleanCount() != 2) ++bad;
            if (uapaPartFlaggedCount() != 5) ++bad;
            if (uapaPartGarbledCount() != 0) ++bad;
            if (uapaSwissPikePct()
                + uapaSwissHalberdPct()
                + uapaSwissMorningStarPct()
                != 100) ++bad;
            if (uapaUltimatePikeMaxFt()
                - uapaUltimatePikeMinFt() != 3)
                ++bad;
            if (uapaPikeShaftMinFt()
                - uapaAshSpearTwelveFt() != 3)
                ++bad;
            if (uapaBardicheHeadMaxFt()
                - uapaBardicheHeadMinFt() != 1)
                ++bad;
            if (uapaPeasantFlailShaftMaxFt()
                - uapaPeasantFlailShaftMinFt()
                != 1) ++bad;
            if (uapaScaleDrawingDivisor()
                != 20) ++bad;
            if (uapaFauchardForkFormCount()
                != 2) ++bad;
            if (uapaSpearFamilyCount()
                + uapaAxeFamilyTrueMemberCount()
                >= uapaPartItemTotal()) ++bad;
            if (uanwHookFauchardDismountPct()
                != 20) ++bad;
            if (uanwHookFauchardSizeReqPct()
                != 50) ++bad;
        printf("R391 UA pole-arm nomenclature pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    assert INC_NEW.split(NL)[1] == (
        '#include "rules/uaappendt.h"  // R391: '
        'the UA pole-arm nomenclature'
        ), 'd inc text'
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R391 audit')



s = rd(RT)
assert s.count(
    'R390 UA non-lethal combat pin audit: bad '
) == 1, 'd r390 kept'
assert s.count(
    'R389 UA weaponless combat pin audit: bad '
) == 1, 'd r389 kept'
assert s.count(
    'R388 UA misc weapons prose pin audit: bad '
) == 1, 'd r388 kept'
assert s.count(
    'R387 UA armor and swords prose pin audit: bad '
) == 1, 'd r387 kept'
assert s.count(
    'R386 UA misc magic prose part 6 pin audit: bad '
) == 1, 'd r386 kept'
assert s.count(
    'R385 UA misc magic prose part 5 pin audit: bad '
) == 1, 'd r385 kept'
assert s.count(
    'R384 UA misc magic prose part 4 pin audit: bad '
) == 1, 'd r384 kept'
assert s.count(
    'R383 UA misc magic prose part 3 pin audit: bad '
) == 1, 'd r383 kept'
assert s.count(
    'R382 UA misc magic prose part 2 pin audit: bad '
) == 1, 'd r382 kept'
assert s.count(
    'R381 UA misc magic prose part 1 pin audit: bad '
) == 1, 'd r381 kept'
assert s.count(
    'R380 UA new wands prose pin audit: bad '
) == 1, 'd r380 kept'
assert s.count(
    'R379 UA new rods staves prose pin audit: bad '
) == 1, 'd r379 kept'
assert s.count(
    'R378 UA new rings prose pin audit: bad '
) == 1, 'd r378 kept'
assert s.count(
    'R377 UA new scrolls protection pin audit: bad '
) == 1, 'd r377 kept'
assert s.count(
    'R376 UA new potions prose part 1 pin audit: bad '
) == 1, 'd r376 kept'
assert s.count(
    'R375 UA determination skeleton pin audit: bad '
) == 1, 'd r375 kept'
assert s.count(
    'R374 UA treasure dial pin audit: bad '
) == 1, 'd r374 kept'
assert s.count(
    'R373 UA comeliness note pin audit: bad '
) == 1, 'd r373 kept'
assert s.count(
    'R372 UA cavalier followers pin audit: bad '
) == 1, 'd r372 kept'
assert s.count(
    'R371 UA expanded armor pin audit: bad '
) == 1, 'd r371 kept'
assert s.count(
    'R370 UA DM-section smalls pin audit: bad '
) == 1, 'd r370 kept'
assert s.count(
    'R369 UA cantrip acquisition pin audit: bad '
) == 1, 'd r369 kept'
assert s.count(
    'R368 UA Cavaliers Table I pin audit: bad '
) == 1, 'd r368 kept'
assert s.count(
    'R367 UA social/birth pin audit: bad '
) == 1, 'd r367 kept'
assert s.count(
    'R366 UA DM-section spells pin audit: bad '
) == 1, 'd r366 kept'
assert s.count(
    'R365 UA IL 6th/7th and DM pin audit: bad '
) == 1, 'd r365 kept'
assert s.count(
    'R364 UA IL 3rd/4th/5th spells pin audit: bad '
) == 1, 'd r364 kept'
assert s.count(
    'R363 UA IL cantrips/1st/2nd pin audit: bad '
) == 1, 'd r363 kept'
assert s.count(
    'R362 UA MU 8th/9th level spells pin audit: bad '
) == 1, 'd r362 kept'
assert s.count(
    'R361 UA MU 7th level spells pin audit: bad '
) == 1, 'd r361 kept'
assert s.count(
    'R360 UA MU 5th/6th level spells pin audit: bad '
) == 1, 'd r360 kept'
assert s.count(
    'R359 UA MU 4th level spells pin audit: bad '
) == 1, 'd r359 kept'
assert s.count(
    'R358 UA MU 3rd level spells pin audit: bad '
) == 1, 'd r358 kept'
assert s.count(
    'R357 UA MU 2nd level spells pin audit: bad '
) == 1, 'd r357 kept'
assert s.count(
    'R356 UA MU 1st level spells pin audit: bad '
) == 1, 'd r356 kept'
assert s.count('audit: bad ') == 318, 'd census 318'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uaappendt.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uaappendr.h"'
) == 1, 'd r390 include kept'
assert s.count(
    '#include "rules/uaappendq.h"'
) == 1, 'd r389 include kept'
assert s.count(
    '#include "rules/uamweapprose.h"'
) == 1, 'd r388 include kept'
assert s.count(
    '#include "rules/uaarmprose.h"'
) == 1, 'd r387 include kept'
assert s.count(
    '#include "rules/uamiscprose6.h"'
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
        'rules/uamiscprose4.h',
        'rules/uamiscprose5.h',
        'rules/uamiscprose6.h',
        'rules/uaarmprose.h',
        'rules/uamweapprose.h',
        'rules/uaappendq.h',
        'rules/uaappendr.h',
        'rules/treasdet.h',
        'rules/hoard.h',
):
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
    'R391 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R391 note: the UA pole-arm',
    'nomenclature appendix T',
    'round - the pp. 123-129',
    'stretch, seven items pin: two',
    'fully clean (the spear family,',
    'the axe family) plus five',
    'mechanics-clean with flagged',
    'holes (the classification',
    'system paragraph, the fauchard',
    'description, the Lucern/bec',
    'comparison tail, the',
    'combination intro and features',
    'list, the confusion sentence);',
    'nothing fully garbles - every',
    'classification survives its',
    'scrambled prose - the item',
    'AMENDED, the prose pinned, the',
    'R340 seam the hook fauchard',
    'roster; the census 317 -> 318',
])
print(NOTE)
print('commit: R391: the UA pole-arm')
print('nomenclature appendix T pin')
print('round (census 318)')

