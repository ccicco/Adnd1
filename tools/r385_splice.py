
# R385: the UA misc magic
# prose part 5 pin round (the
# Q-S stretch): ELEVEN items
# pin - SEVEN fully clean (the
# robe of stars, the scarab
# versus golems, the shadow
# lanthorn, the shoes of
# Fharlanghn, the slippers of
# kicking, the slippers of
# spider climbing, the
# sovereign glue) plus FOUR
# mechanics-clean with flagged
# holes (the quiver of
# Ehlonna's command sentence,
# the robe of vermin's removal
# tail, the sheet of
# smallness' intro seam, the
# spoon of stirring's table
# cell); NOTHING in Q-S fully
# garbles - the gap item
# AMENDED with the part-5
# note, stays OPEN for S-Z,
# PDF-gated; the R384 seam the
# part-4 ledger, the R375 seam
# the misc band; the census
# 311 -> 312.
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


# ---- (a) the seed: the R384 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R384 landed 2026-10-12: commit',
    '  876adbc, census 311, the UA',
    '  misc magic prose part 4 pin',
    '  round (rules/uamiscprose4.h):',
    '  nine I-P items pin - five',
    '  fully clean (the iron bands',
    '  of Bilarro, the lens of',
    '  detection, the mantle of',
    '  Celestian, the pearl of the',
    '  sirines, the pouch of',
    '  accessibility) plus four',
    '  mechanics-clean with flagged',
    '  holes (the lens of',
    "  ultravision's diameter cell,",
    "  Murlynd's spoon's gruel tail,",
    "  the philosopher's stone's",
    '  transmutation cells, the',
    '  prison of Zagyg\'s attunement',
    '  seam); nothing in I-P fully',
    '  garbles - the item AMENDED,',
    '  stays OPEN for Q-Z,',
    '  PDF-gated; the R383 seam the',
    '  part-3 ledger, the R375 seam',
    '  the misc band; GREEN on the',
    '  first run.'
])
s = rd(SD)
if 'R384 landed 2026-10-12' in s:
    already.append('seed: the R384 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R384 record')
s = rd(SD)
assert s.count(
    'R384 landed 2026-10-12'
) == 1, 'a entry'


s = rd(SD)
assert s.count(
    'R383 landed 2026-10-12'
) == 1, 'a R383 kept'


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


# ---- (b) NEW rules/uamiscprose5.h ----
P = 'rules/uamiscprose5.h'
if os.path.exists(P) and 'R385' in rd(P):
    already.append('uamiscprose5.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uamiscprose5.h
// The UA TREASURE
// (MISCELLANEOUS MAGIC) prose
// pins, part 5, R385: the
// Q-S stretch - eleven pins,
// seven fully clean (the robe
// of stars, the scarab versus
// golems, the shadow
// lanthorn, the shoes of
// Fharlanghn, the slippers of
// kicking, the slippers of
// spider climbing, the
// sovereign glue) plus four
// mechanics-clean with flagged
// holes (the quiver of
// Ehlonna's command sentence,
// the robe of vermin's removal
// tail, the sheet of
// smallness' intro seam, the
// spoon of stirring's table
// cell). Nothing in Q-S fully
// garbles; S-Z rides the
// later part. The part-4 and
// skeleton seams ride in the
// regtest audit, not here.
namespace rules {

// ---- the quiver of Ehlonna
// ----
// An arrow container that
// appears a typical device to
// hold about a score of
// shafts; an alteration aura
// under examination; three
// distinct portions.
inline bool uamm5QehAppearsTypicalArrowCase()
    { return true; }

inline int uamm5QehAppearsToHoldShafts()
    { return 20; }

inline bool uamm5QehAlterationAura()
    { return true; }

inline bool uamm5QehThreeDistinctPortions()
    { return true; }

// The first and smallest
// portion holds up to 60
// arrow-like objects; the
// second, slightly longer,
// up to 18 javelin-like; the
// third and longest, up to 6
// spear- or staff-like.
inline int uamm5QehArrowPortionCapacity()
    { return 60; }

inline int uamm5QehJavelinPortionCapacity()
    { return 18; }

inline int uamm5QehSpearPortionCapacity()
    { return 6; }

// The command sentence
// OCR-scrambles; the
// reconstruction: the
// possessor commands the
// quiver to produce whatever
// is wished - an arrow, a
// javelin, and so on - one
// each round; flagged.
inline bool uamm5QehProducesOnCommand()
    { return true; }

inline bool uamm5QehOnePerRound()
    { return true; }

inline bool uamm5QehCommandSentenceGarbles()
    { return true; }

// ---- the robe of stars ----
// A rather ordinary-appearing
// garment typical of magic-
// user apparel; a strong aura
// of alteration and evocation
// under examination.
inline bool uamm5RstOrdinaryAppearance()
    { return true; }

inline bool uamm5RstStrongAlterationEvocationAura()
    { return true; }

// Enables the wearer to
// travel the Astral Plane
// physically, along with all
// worn or carried; survives
// comfortably in the void of
// outer space as well.
inline bool uamm5RstAstralTravelPhysical()
    { return true; }

inline bool uamm5RstCarriesGearAlong()
    { return true; }

inline bool uamm5RstVoidSurvivalComfort()
    { return true; }

// +1 on all saving throws in
// other situations.
inline int uamm5RstSaveBonus()
    { return 1; }

// Up to six of the stars
// embroidered on the chest
// portion serve as missile
// weapons, provided the
// magic-user is proficient
// with darts; each star is a
// +5 throwing weapon to hit
// and damage, maximum range
// 6 inches, base damage 2-8
// per hit.
inline int uamm5RstStarMissiles()
    { return 6; }

inline bool uamm5RstNeedsDartProficiency()
    { return true; }

inline int uamm5RstStarBonus()
    { return 5; }

inline int uamm5RstStarRangeIn()
    { return 6; }

inline int uamm5RstStarDamageLo()
    { return 2; }

inline int uamm5RstStarDamageHi()
    { return 8; }

inline bool uamm5RstStarsOnChest()
    { return true; }

// Unused stars replace
// themselves at one per day;
// if all six are used, all
// the robe's power is gone
// forever.
inline int uamm5RstStarsRegrowPerDay()
    { return 1; }

inline bool uamm5RstAllUsedLosesPowerForever()
    { return true; }

// ---- the robe of vermin
// ----
// A magical-seeming garment
// radiating a dim
// enchantment aura; the
// wearer notices nothing
// unusual when donned - it
// conveys some power then,
// protection +1 for example.
inline bool uamm5RveDimEnchantmentAura()
    { return true; }

inline bool uamm5RveSeemsBeneficialAtFirst()
    { return true; }

inline int uamm5RveInitialProtectionBonus()
    { return 1; }

// In any situation requiring
// concentration and action
// against hostile opponents,
// the true nature reveals:
// a multitude of vermin
// bites; the wearer must
// cease other activities to
// scratch and shift, cannot
// gain initiative, suffers a
// 50% chance of being unable
// to complete a spell, and
// all other manual actions
// at one-half normal
// probability.
inline bool uamm5RveVerminBiteInCombat()
    { return true; }

inline bool uamm5RveCannotGainInitiative()
    { return true; }

inline int uamm5RveSpellFailurePct()
    { return 50; }

inline bool uamm5RveManualActionsHalfProb()
    { return true; }

// The removal tail
// OCR-scrambles; the
// reconstruction: the robe
// is removed only by means
// of a remove curse or
// similar magic-preventing
// magic; flagged.
inline bool uamm5RveRemovalTailGarbles()
    { return true; }

inline bool uamm5RveRemovalNeedsRemoveCurse()
    { return true; }

// ---- the scarab versus
// golems ----
// A magical pin enabling its
// wearer to detect any form
// of golem within 60 feet,
// with actual concentration.
inline bool uamm5SvgPinDetectsGolems()
    { return true; }

inline int uamm5SvgDetectRangeFt()
    { return 60; }

inline bool uamm5SvgNeedsConcentration()
    { return true; }

// Enables the possessor to
// combat a golem with
// hand-held or missile
// weapons as if a normal
// monster - hit and damage
// as if no special defenses;
// effective against any
// lesser golem created by
// the 5th-level clerical
// golem spell.
inline bool uamm5SvgCombatsAsNormalMonster()
    { return true; }

inline bool uamm5SvgLesserGolemsOnly()
    { return true; }

inline int uamm5SvgClericalSpellLevel()
    { return 5; }

// The protective-abilities
// table: six dice-roll rows;
// the flesh row carries 400
// XP and 3,200 gp; the
// any-golem row (96-00)
// carries 1,250 XP and
// 12,500 gp.
inline int uamm5SvgTableRows()
    { return 6; }

inline int uamm5SvgFleshXp()
    { return 400; }

inline int uamm5SvgFleshGp()
    { return 3200; }

inline int uamm5SvgAnyGolemRowLo()
    { return 96; }

inline int uamm5SvgAnyGolemRowHi()
    { return 100; }

inline int uamm5SvgAnyGolemXp()
    { return 1250; }

inline int uamm5SvgAnyGolemGp()
    { return 12500; }

// ---- the shadow lanthorn
// ----
// A mundane-appearing light
// radiating a faint, evil
// dweomer.
inline bool uamm5SlaMundaneAppearance()
    { return true; }

inline bool uamm5SlaFaintEvilDweomer()
    { return true; }

// Fueled by oil rendered
// from the fat of human
// corpses, its beam
// generates 5-8 shadows
// serving the possessor for
// as long as it burns; when
// the oil is consumed the
// shadows disappear;
// typical burning time one
// hour.
inline bool uamm5SlaNeedsCorpseFatOil()
    { return true; }

inline int uamm5SlaShadowsLo()
    { return 5; }

inline int uamm5SlaShadowsHi()
    { return 8; }

inline bool uamm5SlaShadowsServePossessor()
    { return true; }

inline bool uamm5SlaShadowsVanishWhenConsumed()
    { return true; }

inline int uamm5SlaBurningHours()
    { return 1; }

// Characters of good
// alignment lose experience
// points equal to the
// item's value if they do
// not destroy the device.
inline bool uamm5SlaGoodLosesXpIfKept()
    { return true; }

// ---- the sheet of
// smallness ----
// Appears a well-made piece
// of very fine linen or
// silk, one side white, the
// other black; the intro
// prose OCR-scrambles; an
// alteration aura is
// detectable from the cloth;
// flagged.
inline bool uamm5SsmFineClothAppearance()
    { return true; }

inline bool uamm5SsmOneSideWhite()
    { return true; }

inline bool uamm5SsmOtherSideBlack()
    { return true; }

inline bool uamm5SsmIntroSeamGarbles()
    { return true; }

inline bool uamm5SsmAlterationAura()
    { return true; }

// Any item of regular
// magical sort (not an
// artifact or relic)
// wrapped within shrinks to
// 1/12 its normal size and
// weight; wrapped touching
// the reverse side, it
// grows back to normal.
inline bool uamm5SsmShrinksToTwelfth()
    { return true; }

inline bool uamm5SsmNoArtifactsOrRelics()
    { return true; }

inline bool uamm5SsmReverseSideRestores()
    { return true; }

// The dweomer affects no
// living material; no shrunk
// item is functional or
// usable in reduced form; a
// change in size takes a
// full two rounds,
// shrinking or restoring.
inline bool uamm5SsmNoLivingMaterial()
    { return true; }

inline bool uamm5SsmNonFunctionalWhenSmall()
    { return true; }

inline int uamm5SsmChangeRounds()
    { return 2; }

// ---- the shoes of
// Fharlanghn ----
// Low, thick-soled shoes so
// durable they never wear
// out; the wearer never
// grows fatigued from
// walking, easily
// maintaining 20-30 miles
// per day.
inline bool uamm5SfaNeverWearOut()
    { return true; }

inline bool uamm5SfaNeverFatigued()
    { return true; }

inline int uamm5SfaMilesPerDayLo()
    { return 20; }

inline int uamm5SfaMilesPerDayHi()
    { return 30; }

// Neutral or neutral good
// wearers additionally:
// never trip, step into a
// snare or pit, or become
// entangled; climb up or
// down 45-degree hills
// without effort; walk
// narrow ledges or slippery
// logs without a slip.
inline bool uamm5SfaNeverTripsOrSnared()
    { return true; }

inline int uamm5SfaHillClimbAngleDeg()
    { return 45; }

inline bool uamm5SfaSureFootedOnLedges()
    { return true; }

// A worshiper of Fharlanghn
// gains more: becoming lost
// is impossible; nothing
// walking on the earth can
// surprise; run at 18-inch
// movement and jump up to 20
// feet; climb vertical
// surfaces as a 10th-level
// thief; tread on any earth
// as on a smooth roadway.
inline bool uamm5SfaWorshipperNeverLost()
    { return true; }

inline bool uamm5SfaWorshipperNoSurprise()
    { return true; }

inline int uamm5SfaWorshipperRunIn()
    { return 18; }

inline int uamm5SfaWorshipperJumpFt()
    { return 20; }

inline int uamm5SfaWorshipperThiefClimbLevel()
    { return 10; }

inline bool uamm5SfaWorshipperEarthAsRoad()
    { return true; }

// At least a dozen pairs
// are known in treasure
// troves.
inline int uamm5SfaKnownPairs()
    { return 12; }

// ---- the slippers of
// kicking ----
// The wearer utilizes feet
// as effective weapons: two
// attacks each combat round
// (two special attacks if
// foregoing other methods),
// attack level unchanged.
inline bool uamm5SkiFeetAsWeapons()
    { return true; }

inline int uamm5SkiAttacksPerRound()
    { return 2; }

inline bool uamm5SkiSpecialNeedsForegoing()
    { return true; }

inline bool uamm5SkiAttackLevelUnchanged()
    { return true; }

// Damage: 1-6 versus
// man-sized or smaller, 1-4
// versus larger than
// man-sized; the dweomer
// inflicts twice normal
// damage in a separate
// category, recovered by the
// opponent after one
// complete turn, like
// stunning.
inline int uamm5SkiDamageManSizedLo()
    { return 1; }

inline int uamm5SkiDamageManSizedHi()
    { return 6; }

inline int uamm5SkiDamageLargerLo()
    { return 1; }

inline int uamm5SkiDamageLargerHi()
    { return 4; }

inline bool uamm5SkiDoubleDamageSeparate()
    { return true; }

inline bool uamm5SkiExtraRecoveredAfterTurn()
    { return true; }

// The printed example: a
// larger opponent takes 3
// (plus 3) and 4 (plus 4);
// at the 11th round it
// recovers the 7 extra
// points as the stunning
// wears off.
inline int uamm5SkiExamplePlusOne()
    { return 3; }

inline int uamm5SkiExamplePlusTwo()
    { return 4; }

inline int uamm5SkiExampleRecovered()
    { return 7; }

// Worn by a character with
// martial arts skills, the
// effect is merely +1 on
// foot attacks and damage.
inline int uamm5SkiMartialArtsBonus()
    { return 1; }

inline bool uamm5SkiMartialArtsNoDouble()
    { return true; }

// ---- the slippers of
// spider climbing ----
// Totally unremarkable in
// appearance, a faint
// alteration dweomer under
// detection; worn, they
// enable movement at 6-inch
// rate on vertical surfaces
// or upside down along
// ceilings, hands free.
inline bool uamm5SscUnremarkableAppearance()
    { return true; }

inline bool uamm5SscFaintAlterationDweomer()
    { return true; }

inline int uamm5SscClimbRateIn()
    { return 6; }

inline bool uamm5SscCeilingsToo()
    { return true; }

inline bool uamm5SscHandsFree()
    { return true; }

// Extremely slippery
// surfaces - ice, oiled or
// greased - make the
// slippers useless.
inline bool uamm5SscUselessOnSlippery()
    { return true; }

// ---- the sovereign glue
// ----
// A pale amber substance,
// thick and viscous;
// containable only within a
// flask coated with oil of
// slipperiness; after each
// pouring, a fresh oil
// application must be made
// within 1 round to keep
// the glue from adhering to
// the container.
inline bool uamm5SglPaleAmberViscous()
    { return true; }

inline bool uamm5SglNeedsSlipperinessFlask()
    { return true; }

inline int uamm5SglReoilWithinRounds()
    { return 1; }

inline bool uamm5SglElseAdheresToFlask()
    { return true; }

// One ounce covers about
// one square foot, bonding
// virtually any two
// substances permanently;
// the glue takes one full
// round to set - pulled
// apart earlier, that
// application is worthless.
inline int uamm5SglSqFtPerOunce()
    { return 1; }

inline bool uamm5SglPermanentBond()
    { return true; }

inline int uamm5SglSetRounds()
    { return 1; }

inline bool uamm5SglEarlyPullRuinsApplication()
    { return true; }

// A set bond separates only
// by rending one object or
// the other, except by oil
// of etherealness or
// ultimate solution, the
// only solvents; a typical
// container holds 1-10
// ounces.
inline bool uamm5SglSetBondRends()
    { return true; }

inline bool uamm5SglDissolvedByEtherealnessOrUltimate()
    { return true; }

inline int uamm5SglOuncesLo()
    { return 1; }

inline int uamm5SglOuncesHi()
    { return 10; }

// ---- the spoon of
// stirring ----
// A normal, unremarkable
// spoon that radiates no
// magic unless dipped into
// a potion; inserted, it
// gives off a burst of
// alteration magic, and the
// contents change into some
// other potion - the spoon
// seems normal thereafter,
// reusable on the same or
// different potions.
inline bool uamm5SstUnremarkableSpoon()
    { return true; }

inline bool uamm5SstRadiatesOnlyInPotion()
    { return true; }

inline bool uamm5SstAlterationBurst()
    { return true; }

inline bool uamm5SstChangesPotion()
    { return true; }

inline bool uamm5SstReusable()
    { return true; }

// The same potion treated
// more than three times - a
// fourth usage - loses all
// magic, a noisome liquor
// of no value.
inline int uamm5SstMaxUsesPerPotion()
    { return 3; }

inline bool uamm5SstFourthUseRuins()
    { return true; }

// The table-reference cell
// OCR-scrambles; the
// reconstruction: the type
// produced is diced from
// Table III.A.2; flagged.
inline bool uamm5SstTableCellGarbles()
    { return true; }

inline bool uamm5SstDeterminedByTable()
    { return true; }

// A same-type result changes
// the appearance and the
// strength: twice normal on
// 01-50, half normal on
// 51-00.
inline bool uamm5SstSameResultChangesAppearance()
    { return true; }

inline int uamm5SstTwiceStrengthLo()
    { return 1; }

inline int uamm5SstTwiceStrengthHi()
    { return 50; }

inline int uamm5SstHalfStrengthLo()
    { return 51; }

inline int uamm5SstHalfStrengthHi()
    { return 100; }

// ---- the part ledger ----
// Eleven Q-S items: seven
// fully clean, four flagged,
// none fully garbled.
inline int uamm5PartItemTotal()
    { return 11; }

inline int uamm5PartCleanCount()
    { return 7; }

inline int uamm5PartFlaggedCount()
    { return 4; }

inline int uamm5PartGarbledCount()
    { return 0; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uamiscprose5.h: the pins')


s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 132, 'b inline count'
assert s.count('R385') == 1, 'b round tag'
assert s.count(
    'uamm5QehArrowPortionCapacity'
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
assert 'uamm4' not in s, 'b no uamm4 ref'
assert s.count('uamm') == s.count(
    'uamm5'), 'b no R381-R384 uamm ref'
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (c) the gap report: the
# amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R385' in s:
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
        '        OPEN for I-Z and the PDF.',
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
    assert s.count(OLD) == 1, 'c1 old'
    NEW = OLD + NL + NL.join([
        '      - AMENDED R385: the misc magic',
        '        prose part 5 pin round',
        '        (rules/uamiscprose5.h) - the',
        '        Q-S stretch, ELEVEN items pin:',
        '        SEVEN fully clean (the robe of',
        '        stars, the scarab versus',
        '        golems, the shadow lanthorn,',
        '        the shoes of Fharlanghn, the',
        '        slippers of kicking, the',
        '        slippers of spider climbing,',
        '        the sovereign glue) plus FOUR',
        '        mechanics-clean with flagged',
        "        holes (the quiver of Ehlonna's",
        '        command sentence, the robe of',
        "        vermin's removal tail, the",
        "        sheet of smallness' intro",
        "        seam, the spoon of stirring's",
        '        table cell); NOTHING in Q-S',
        '        fully garbles - the item stays',
        '        OPEN for S-Z and the PDF.'
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
    'AMENDED R385'
) == 1, 'c amendment'
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
    '(rules/uamiscprose2.h)'
) == 1, 'c misc2 note kept'
assert s.count(
    '(rules/uamiscprose5.h)'
) == 1, 'c misc5 note'
assert s.count(
    '(rules/uamiscprose4.h)'
) == 1, 'c misc4 note kept'
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
if 'R385 UA misc magic prose part 5 pin audit' in s:
    already.append('regtest.cpp: the R385 audit')
else:
    INC_ANCH = ('#include "rules/uamiscprose4.h"  // '
        'R384: the UA misc magic prose 4')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamiscprose5.h"  // R385: the UA misc magic prose 5'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R385: the UA misc magic
    // prose part 5 pin audit ----
    // The Q-S stretch: eleven pins -
    // seven fully clean (the robe
    // of stars, the scarab versus
    // golems, the shadow lanthorn,
    // the shoes of Fharlanghn, the
    // slippers of kicking, the
    // slippers of spider climbing,
    // the sovereign glue) plus four
    // mechanics-clean with flagged
    // holes (the quiver of
    // Ehlonna's command sentence,
    // the robe of vermin's removal
    // tail, the sheet of smallness'
    // intro seam, the spoon of
    // stirring's table cell); the
    // R384 seam the part-4 ledger,
    // the R375 seam the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the quiver of Ehlonna
        // ----
            if (!uamm5QehAppearsTypicalArrowCase())
                ++bad;
            if (uamm5QehAppearsToHoldShafts() != 20)
                ++bad;
            if (!uamm5QehAlterationAura()) ++bad;
            if (!uamm5QehThreeDistinctPortions())
                ++bad;
            if (uamm5QehArrowPortionCapacity()
                    != 60) ++bad;
            if (uamm5QehJavelinPortionCapacity()
                    != 18) ++bad;
            if (uamm5QehSpearPortionCapacity() != 6)
                ++bad;
            if (!uamm5QehProducesOnCommand()) ++bad;
            if (!uamm5QehOnePerRound()) ++bad;
            if (!uamm5QehCommandSentenceGarbles())
                ++bad;
            // the javelin portion holds
            // three times the spear
            // portion, the arrow ten
            if (3 * uamm5QehSpearPortionCapacity()
                    != uamm5QehJavelinPortionCapacity())
                ++bad;
            if (10 * uamm5QehSpearPortionCapacity()
                    != uamm5QehArrowPortionCapacity())
                ++bad;
        // ---- the robe of stars ----
            if (!uamm5RstOrdinaryAppearance()) ++bad;
            if (!uamm5RstStrongAlterationEvocationAura())
                ++bad;
            if (!uamm5RstAstralTravelPhysical())
                ++bad;
            if (!uamm5RstCarriesGearAlong()) ++bad;
            if (!uamm5RstVoidSurvivalComfort()) ++bad;
            if (uamm5RstSaveBonus() != 1) ++bad;
            if (uamm5RstStarMissiles() != 6) ++bad;
            if (!uamm5RstNeedsDartProficiency())
                ++bad;
            if (uamm5RstStarBonus() != 5) ++bad;
            if (uamm5RstStarRangeIn() != 6) ++bad;
            if (uamm5RstStarDamageLo() != 2) ++bad;
            if (uamm5RstStarDamageHi() != 8) ++bad;
            if (!uamm5RstStarsOnChest()) ++bad;
            if (uamm5RstStarsRegrowPerDay() != 1)
                ++bad;
            if (!uamm5RstAllUsedLosesPowerForever())
                ++bad;
            // the star damage rides
            // the 2-8 spread, four
            // lows to a high
            if (4 * uamm5RstStarDamageLo()
                    != uamm5RstStarDamageHi()) ++bad;
            // the star count matches
            // the maximum range, six
            if (uamm5RstStarMissiles()
                    != uamm5RstStarRangeIn()) ++bad;
        // ---- the robe of vermin
        // ----
            if (!uamm5RveDimEnchantmentAura())
                ++bad;
            if (!uamm5RveSeemsBeneficialAtFirst())
                ++bad;
            if (uamm5RveInitialProtectionBonus()
                    != 1) ++bad;
            if (!uamm5RveVerminBiteInCombat()) ++bad;
            if (!uamm5RveCannotGainInitiative())
                ++bad;
            if (uamm5RveSpellFailurePct() != 50)
                ++bad;
            if (!uamm5RveManualActionsHalfProb())
                ++bad;
            if (!uamm5RveRemovalTailGarbles()) ++bad;
            if (!uamm5RveRemovalNeedsRemoveCurse())
                ++bad;
            // the spell-failure
            // chance is half of a
            // certainty
            if (2 * uamm5RveSpellFailurePct()
                    != 100) ++bad;
        // ---- the scarab versus
        // golems ----
            if (!uamm5SvgPinDetectsGolems()) ++bad;
            if (uamm5SvgDetectRangeFt() != 60) ++bad;
            if (!uamm5SvgNeedsConcentration()) ++bad;
            if (!uamm5SvgCombatsAsNormalMonster())
                ++bad;
            if (!uamm5SvgLesserGolemsOnly()) ++bad;
            if (uamm5SvgClericalSpellLevel() != 5)
                ++bad;
            if (uamm5SvgTableRows() != 6) ++bad;
            if (uamm5SvgFleshXp() != 400) ++bad;
            if (uamm5SvgFleshGp() != 3200) ++bad;
            if (uamm5SvgAnyGolemRowLo() != 96) ++bad;
            if (uamm5SvgAnyGolemRowHi() != 100)
                ++bad;
            if (uamm5SvgAnyGolemXp() != 1250) ++bad;
            if (uamm5SvgAnyGolemGp() != 12500) ++bad;
            // the any-golem row spans
            // the last five points of
            // the table, 96 through 00
            if (uamm5SvgAnyGolemRowHi()
                    - uamm5SvgAnyGolemRowLo() != 4)
                ++bad;
            // the any-golem sale value
            // is ten times its XP
            if (10 * uamm5SvgAnyGolemXp()
                    != uamm5SvgAnyGolemGp()) ++bad;
        // ---- the shadow
        // lanthorn ----
            if (!uamm5SlaMundaneAppearance()) ++bad;
            if (!uamm5SlaFaintEvilDweomer()) ++bad;
            if (!uamm5SlaNeedsCorpseFatOil()) ++bad;
            if (uamm5SlaShadowsLo() != 5) ++bad;
            if (uamm5SlaShadowsHi() != 8) ++bad;
            if (!uamm5SlaShadowsServePossessor())
                ++bad;
            if (!uamm5SlaShadowsVanishWhenConsumed())
                ++bad;
            if (uamm5SlaBurningHours() != 1) ++bad;
            if (!uamm5SlaGoodLosesXpIfKept()) ++bad;
            // the shadow band rides
            // the 5-8 spread
            if (uamm5SlaShadowsLo()
                    >= uamm5SlaShadowsHi()) ++bad;
        // ---- the sheet of
        // smallness ----
            if (!uamm5SsmFineClothAppearance())
                ++bad;
            if (!uamm5SsmOneSideWhite()) ++bad;
            if (!uamm5SsmOtherSideBlack()) ++bad;
            if (!uamm5SsmIntroSeamGarbles()) ++bad;
            if (!uamm5SsmAlterationAura()) ++bad;
            if (!uamm5SsmShrinksToTwelfth()) ++bad;
            if (!uamm5SsmNoArtifactsOrRelics())
                ++bad;
            if (!uamm5SsmReverseSideRestores())
                ++bad;
            if (!uamm5SsmNoLivingMaterial()) ++bad;
            if (!uamm5SsmNonFunctionalWhenSmall())
                ++bad;
            if (uamm5SsmChangeRounds() != 2) ++bad;
            // the two-round change
            // shrinks to a twelfth:
            // 2 rounds x 6 = 12
            if (6 * uamm5SsmChangeRounds() != 12)
                ++bad;
        // ---- the shoes of
        // Fharlanghn ----
            if (!uamm5SfaNeverWearOut()) ++bad;
            if (!uamm5SfaNeverFatigued()) ++bad;
            if (uamm5SfaMilesPerDayLo() != 20) ++bad;
            if (uamm5SfaMilesPerDayHi() != 30) ++bad;
            if (!uamm5SfaNeverTripsOrSnared())
                ++bad;
            if (uamm5SfaHillClimbAngleDeg() != 45)
                ++bad;
            if (!uamm5SfaSureFootedOnLedges()) ++bad;
            if (!uamm5SfaWorshipperNeverLost())
                ++bad;
            if (!uamm5SfaWorshipperNoSurprise())
                ++bad;
            if (uamm5SfaWorshipperRunIn() != 18)
                ++bad;
            if (uamm5SfaWorshipperJumpFt() != 20)
                ++bad;
            if (uamm5SfaWorshipperThiefClimbLevel()
                    != 10) ++bad;
            if (!uamm5SfaWorshipperEarthAsRoad())
                ++bad;
            if (uamm5SfaKnownPairs() != 12) ++bad;
            // the daily pace rides
            // the 20-30 mile band
            if (uamm5SfaMilesPerDayLo()
                    >= uamm5SfaMilesPerDayHi()) ++bad;
        // ---- the slippers of
        // kicking ----
            if (!uamm5SkiFeetAsWeapons()) ++bad;
            if (uamm5SkiAttacksPerRound() != 2)
                ++bad;
            if (!uamm5SkiSpecialNeedsForegoing())
                ++bad;
            if (!uamm5SkiAttackLevelUnchanged())
                ++bad;
            if (uamm5SkiDamageManSizedLo() != 1)
                ++bad;
            if (uamm5SkiDamageManSizedHi() != 6)
                ++bad;
            if (uamm5SkiDamageLargerLo() != 1) ++bad;
            if (uamm5SkiDamageLargerHi() != 4) ++bad;
            if (!uamm5SkiDoubleDamageSeparate())
                ++bad;
            if (!uamm5SkiExtraRecoveredAfterTurn())
                ++bad;
            if (uamm5SkiExamplePlusOne() != 3) ++bad;
            if (uamm5SkiExamplePlusTwo() != 4) ++bad;
            if (uamm5SkiExampleRecovered() != 7)
                ++bad;
            if (uamm5SkiMartialArtsBonus() != 1)
                ++bad;
            if (!uamm5SkiMartialArtsNoDouble())
                ++bad;
            // the printed example
            // recovers the two pluses,
            // 3 + 4 = 7
            if (uamm5SkiExamplePlusOne()
                    + uamm5SkiExamplePlusTwo()
                    != uamm5SkiExampleRecovered())
                ++bad;
        // ---- the slippers of
        // spider climbing ----
            if (!uamm5SscUnremarkableAppearance())
                ++bad;
            if (!uamm5SscFaintAlterationDweomer())
                ++bad;
            if (uamm5SscClimbRateIn() != 6) ++bad;
            if (!uamm5SscCeilingsToo()) ++bad;
            if (!uamm5SscHandsFree()) ++bad;
            if (!uamm5SscUselessOnSlippery())
                ++bad;
        // ---- the sovereign
        // glue ----
            if (!uamm5SglPaleAmberViscous()) ++bad;
            if (!uamm5SglNeedsSlipperinessFlask())
                ++bad;
            if (uamm5SglReoilWithinRounds() != 1)
                ++bad;
            if (!uamm5SglElseAdheresToFlask())
                ++bad;
            if (uamm5SglSqFtPerOunce() != 1) ++bad;
            if (!uamm5SglPermanentBond()) ++bad;
            if (uamm5SglSetRounds() != 1) ++bad;
            if (!uamm5SglEarlyPullRuinsApplication())
                ++bad;
            if (!uamm5SglSetBondRends()) ++bad;
            if (!uamm5SglDissolvedByEtherealnessOrUltimate())
                ++bad;
            if (uamm5SglOuncesLo() != 1) ++bad;
            if (uamm5SglOuncesHi() != 10) ++bad;
            // the typical container
            // rides the 1-10 ounce
            // band
            if (uamm5SglOuncesLo()
                    >= uamm5SglOuncesHi()) ++bad;
        // ---- the spoon of
        // stirring ----
            if (!uamm5SstUnremarkableSpoon()) ++bad;
            if (!uamm5SstRadiatesOnlyInPotion())
                ++bad;
            if (!uamm5SstAlterationBurst()) ++bad;
            if (!uamm5SstChangesPotion()) ++bad;
            if (!uamm5SstReusable()) ++bad;
            if (uamm5SstMaxUsesPerPotion() != 3)
                ++bad;
            if (!uamm5SstFourthUseRuins()) ++bad;
            if (!uamm5SstTableCellGarbles()) ++bad;
            if (!uamm5SstDeterminedByTable()) ++bad;
            if (!uamm5SstSameResultChangesAppearance())
                ++bad;
            if (uamm5SstTwiceStrengthLo() != 1)
                ++bad;
            if (uamm5SstTwiceStrengthHi() != 50)
                ++bad;
            if (uamm5SstHalfStrengthLo() != 51) ++bad;
            if (uamm5SstHalfStrengthHi() != 100)
                ++bad;
            // the fourth usage ruins:
            // three good uses plus
            // the one too many
            if (uamm5SstMaxUsesPerPotion() + 1
                    != 4) ++bad;
            // the twice and half
            // bands split the table,
            // 50 and 50
            if (uamm5SstTwiceStrengthHi()
                    + uamm5SstHalfStrengthHi()
                    - uamm5SstHalfStrengthLo()
                    + 1 != 100) ++bad;
        // ---- the part ledger ----
            if (uamm5PartItemTotal() != 11) ++bad;
            if (uamm5PartCleanCount() != 7) ++bad;
            if (uamm5PartFlaggedCount() != 4)
                ++bad;
            if (uamm5PartGarbledCount() != 0)
                ++bad;
            if (uamm5PartCleanCount()
                    + uamm5PartFlaggedCount()
                    + uamm5PartGarbledCount()
                    != uamm5PartItemTotal()) ++bad;
        // ---- the R384 part-4 seam ----
            if (uamm4PartItemTotal() != 9) ++bad;
            if (uamm4PartCleanCount() != 5) ++bad;
            if (uamm4PartFlaggedCount() != 4)
                ++bad;
            if (uamm4PartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (!uadsRowBodiesGarble()) ++bad;
        printf("R385 UA misc magic prose part 5 pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R385 audit')


s = rd(RT)
assert s.count(
    'R385 UA misc magic prose part 5 pin audit: bad '
) == 1, 'd audit line'
assert s.count(
    'R384 UA misc magic prose part 4 pin audit: bad '
) == 1, 'd kept'
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
assert s.count('audit: bad ') == 312, 'd census 312'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uamiscprose5.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uamiscprose4.h"'
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
    'R385 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R385 note: the misc magic',
    'prose part 5 round - the',
    'Q-S stretch, eleven items',
    'pin: seven fully clean (the',
    'robe of stars, the scarab',
    'versus golems, the shadow',
    'lanthorn, the shoes of',
    'Fharlanghn, the slippers of',
    'kicking, the slippers of',
    'spider climbing, the',
    'sovereign glue) plus four',
    'mechanics-clean with',
    'flagged holes (the quiver',
    'of Ehlonna, the robe of',
    'vermin, the sheet of',
    'smallness, the spoon of',
    'stirring); nothing in Q-S',
    'fully garbles - the item',
    'AMENDED, stays OPEN for',
    'S-Z, PDF-gated; the R384',
    'seam the part-4 ledger, the',
    'R375 seam the misc band;',
    'the census 311 -> 312'
])
print(NOTE)
print('commit: R385: the UA misc')
print('magic prose part 5 pin round')
print('(census 312)')

