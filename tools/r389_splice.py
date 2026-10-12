

# R389: the UA weaponless
# combat appendix Q pin round:
# the pp. 106-108 stretch, SIX
# items pin - ONE fully clean
# (the throwing rules) plus
# FIVE mechanics-clean with
# flagged holes (the System I
# height example cell, the
# pummeling table row bodies,
# the kicking tail, the
# grappling size bands, the
# overbearing AC prose);
# NOTHING fully garbles - the
# item AMENDED with the R389
# note, the prose pinned, the
# R160 overlap RECONCILED (the
# DMG pp. 72-73 system stays
# the engine default, the UA
# System II pins as its own
# data layer - the R374 dial
# precedent), stays PDF-gated
# only; the R388 seam the misc
# weapons ledger; the census
# 315 -> 316.
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


# ---- (a) the seed: the R388
# record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R388 landed 2026-10-12: commit',
    '  cc2a141, census 315, the UA',
    '  misc weapons prose pin round',
    '  (rules/uamweapprose.h): the',
    '  pp. 105-106 stretch, nine',
    '  items pin - six fully clean',
    '  (the bullet of impact, the',
    '  dagger Longtooth, the darts',
    '  of homing, the knife buckle,',
    '  the magic quarterstaff, the',
    '  scimitar of speed) plus',
    '  three mechanics-clean with',
    '  flagged holes (the axe of',
    "  hurling's familiarization",
    '  tail, the dagger of',
    "  throwing's range cells, the",
    "  hornblade's handle sentence)",
    '  the R388 audit block covers',
    '  in full; nothing fully',
    '  garbles - the item AMENDED,',
    '  the prose pinned, the',
    '  treasure prose sweep',
    '  complete, stays PDF-gated',
    '  only; the R387 seam the',
    '  armor ledger, the R375 seam',
    '  the misc band; GREEN on',
    '  the first run.'
])
s = rd(SD)
if 'R388 landed 2026-10-12' in s:
    already.append('seed: the R388 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R388 record')
s = rd(SD)
assert s.count(
    'R388 landed 2026-10-12'
) == 1, 'a entry'


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


# ---- (b) NEW rules/uaappendq.h ----
P = 'rules/uaappendq.h'
if os.path.exists(P) and 'R389' in rd(P):
    already.append('uaappendq.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uaappendq.h
// The UA APPENDIX Q: WEAPONLESS
// COMBAT pins, R389: the pp.
// 106-108 stretch - six items,
// one fully clean (the
// throwing rules) plus five
// mechanics-clean with flagged
// holes (the System I height
// example cell, the pummeling
// table row bodies, the kicking
// tail, the grappling size
// bands, the overbearing AC
// prose). Nothing fully
// garbles. The R160 overlap
// RECONCILED: the DMG pp. 72-73
// system stays the engine
// default; this header pins the
// UA System I / System II layer
// as its own data - the R374
// dial precedent. Pin-era
// pattern (R322).
namespace rules {
// The first system: very
// simple, used quickly in
// need.
inline bool uaqSysOneSimpleQuickSystem()
    { return true; }

// The second system: an
// outgrowth of the first,
// greater detail, the more
// powerful of the two.
inline bool uaqSysTwoOutgrowthMorePowerful()
    { return true; }

// Used by humans,
// demi-humans and humanoids
// only, against the same.
inline int uaqSysOneUserTypeCount()
    { return 3; }

// The three steps: choose
// the action (pummeling,
// grappling or overbearing),
// roll to hit, the DM
// administers the result.
inline int uaqSysOneActionCount()
    { return 3; }

// The target cannot exceed
// 125 percent of the
// attacker's height.
inline int uaqSysOneHeightPctLimit()
    { return 125; }

// The four-foot example:
inline int uaqSysOneExampleShortFt()
    { return 4; }

// no use against creatures
// of more than five feet.
inline int uaqSysOneExampleTallFt()
    { return 5; }

// The six-foot example
// height cell OCR-lost -
// flagged, PDF-gated.
inline bool uaqSysOneSixFtExampleGarbles()
    { return true; }

// The to-hit roll: the
// standard class chance
// modified only for
// strength.
inline bool uaqSysOneToHitStrengthOnlyMod()
    { return true; }

// The defender gains
// armor, dexterity and magic
// benefits.
inline bool uaqSysOneDefenderArmorDexMagic()
    { return true; }

// A pummeling hit delays
// the action 1 segment and
// negates spell casting.
inline int uaqSysOnePummelDelaySegments()
    { return 1; }

inline int uaqSysOnePummelDamageLo()
    { return 1; }

// Damage 1-2 points; the
// strength bonus only with
// a weapon such as a
// mailed glove.
inline int uaqSysOnePummelDamageHi()
    { return 2; }

inline bool uaqSysOnePummelStrBonusNeedsWeapon()
    { return true; }

// No further delay for
// multiple pummels in the
// same round.
inline bool uaqSysOnePummelMultiNoExtraDelay()
    { return true; }

// A grappling attack
// inflicts no damage, holds
// the opponent 1 round.
inline bool uaqSysOneGrappleNoDamage()
    { return true; }

inline int uaqSysOneGrappleHoldRounds()
    { return 1; }

// While held: +2 to be hit,
// -2 to hit.
inline int uaqSysOneGrappledToHitPenalty()
    { return 2; }

inline int uaqSysOneGrappledHitByBonus()
    { return 2; }

// The grapple breaks
// automatically at the start
// of the next round.
inline bool uaqSysOneGrappleAutoBreaksNextRound()
    { return true; }

// A successful overbearing
// attack inflicts no damage
// but knocks the opponent
// prone.
inline bool uaqSysOneOverbearKnocksProne()
    { return true; }

// Prone opponents are +4
// to be hit until regaining
// their feet.
inline int uaqSysOneProneHitByBonus()
    { return 4; }

// Weaponless initiative at
// a -2 penalty.
inline int uaqSysOneInitPenalty()
    { return 2; }

// Damage suffered before
// the attack spoils it.
inline bool uaqSysOneSpoiledByPriorDamage()
    { return true; }

// Available to any creature
// with a strength score (or
// the equivalent); players,
// most humans, giants and
// vampires may, most other
// undead, dragons and
// non-humanoids may not.
inline bool uaqPumAvailWithStrengthScore()
    { return true; }

inline int uaqPumMayRosterCount()
    { return 4; }

inline int uaqPumMayNotRosterCount()
    { return 3; }

// The target must be a
// non-undead, non-vegetable
// organic native of the
// Prime Material Plane.
inline bool uaqPumTargetNonUndeadNonVegetable()
    { return true; }

inline bool uaqPumTargetPrimeNative()
    { return true; }

// Cannot be pummeled:
// shambling mounds,
// elementals, all demons,
// slimes and fungus
// creatures.
inline int uaqPumCannotRosterCount()
    { return 5; }

// The demon exception
// cell OCR-lost - flagged,
// PDF-gated.
inline bool uaqPumDemonExceptionGarbles()
    { return true; }

// Same or smaller size class
// only; any size if the
// target is prone.
inline bool uaqPumSameOrSmallerSizeClass()
    { return true; }

inline bool uaqPumAnySizeIfTargetProne()
    { return true; }

// Initiative at -4 plus the
// dexterity modifiers.
inline int uaqPumInitPenalty()
    { return 4; }

inline bool uaqPumDexModsStillApply()
    { return true; }

// Surprise or from-behind
// attacks take no penalty
// and strike at +2.
inline bool uaqPumSurpriseNoInitPenalty()
    { return true; }

inline bool uaqPumBehindNoInitPenalty()
    { return true; }

inline int uaqPumSurpriseOrBehindToHitBonus()
    { return 2; }

// Damage from the attacked
// creature first spoils the
// pummel.
inline bool uaqPumSpoiledByPriorDamage()
    { return true; }

// Resolve: the item type,
// the vulnerability, the
// to-hit versus the effective
// AC, then the stunning
// table.
inline int uaqPumResolutionSteps()
    { return 4; }

// The four object types:
// small soft (bare fist or
// foot), small hard (mailed
// fist or pommel), large
// soft (an unconscious
// figure), large hard (a
// table or chair).
inline int uaqPumObjTypeCount()
    { return 4; }

inline int uaqPumObjSmallSoft()
    { return 0; }

inline int uaqPumObjSmallHard()
    { return 1; }

inline int uaqPumObjLargeSoft()
    { return 2; }

inline int uaqPumObjLargeHard()
    { return 3; }

// Large objects take a
// round to pick up.
inline bool uaqPumLargeObjPickupRound()
    { return true; }

// A target qualifying for
// two categories counts as
// the more vulnerable.
inline bool uaqPumMoreVulnerableCategoryWins()
    { return true; }

// Exposed: bare head or
// face, ordinary cap or
// clothing, leather or
// padded armor, or natural AC
// 7 or worse.
inline bool uaqPumExposedBareHeadOrFace()
    { return true; }

inline bool uaqPumExposedOrdinaryCapClothing()
    { return true; }

inline bool uaqPumExposedLeatherOrPadded()
    { return true; }

inline int uaqPumExposedNaturalAcWorst()
    { return 7; }

// Semi-exposed: standard
// armor between ring and
// plate mail, or natural AC
// between 7 and 2.
inline bool uaqPumSemiRingToPlateMail()
    { return true; }

inline int uaqPumSemiNaturalLo()
    { return 7; }

inline int uaqPumSemiNaturalHi()
    { return 2; }

// Unexposed: full or field
// plate, or natural AC 2 or
// better.
inline bool uaqPumUnexposedFullOrFieldPlate()
    { return true; }

inline int uaqPumUnexposedNaturalAcBest()
    { return 2; }

// Vulnerability ignores
// shields and magic armor
// bonuses.
inline bool uaqPumVulnIgnoresShieldsAndMagicArmor()
    { return true; }

// Effective AC ignores the
// shield unless a buckler;
// magic and dexterity count.
inline bool uaqPumEffAcShieldIgnoredUnlessBuckler()
    { return true; }

inline bool uaqPumEffAcMagicAndDexCount()
    { return true; }

// Weapon-to-AC adjustments
// read the pummel as fist
// or open hand.
inline bool uaqPumAcaReadsFistOrOpenHand()
    { return true; }

// The Pummeling Table: 3
// vulnerability rows by 4
// object columns, the
// chance per point of
// strength of stunning;
inline int uaqPumTableRows()
    { return 3; }

inline int uaqPumTableCols()
    { return 4; }

// the exposed row decoded
// from the clean worked
// example: 2 percent per
inline int uaqPumExposedSmallSoftPerPt()
    { return 2; }

// point, 40 percent at
// 18/01;
inline int uaqPumExposedSmallSoftCap()
    { return 40; }

inline int uaqPumExposedSmallHardPerPt()
    { return 4; }

// 4 percent per point, 75
// percent at 18/01;
inline int uaqPumExposedSmallHardCap()
    { return 75; }

inline int uaqPumExposedLargeHardPerPt()
    { return 5; }

// 5 percent per point, 95
// percent at 18/01.
inline int uaqPumExposedLargeHardCap()
    { return 95; }

// The printed fragment pairs
// (the row bodies
// OCR-scramble): 1 percent
inline int uaqPumFragPair1PerPt()
    { return 1; }

// per point with 20 at
// 18/01,
inline int uaqPumFragPair1Cap()
    { return 20; }

inline int uaqPumFragPair2PerPt()
    { return 2; }

// 2 percent per point with
// 40 at 18/01,
inline int uaqPumFragPair2Cap()
    { return 40; }

inline int uaqPumFragPair3PerPt()
    { return 4; }

// 4 percent per point with
// 75 at 18/01 - the
// attribution flagged,
inline int uaqPumFragPair3Cap()
    { return 75; }

// the unattributed cells
// OCR-lost - flagged,
// PDF-gated.
inline bool uaqPumTableRowBodiesGarble()
    { return true; }

// Strength 18/01 or higher
// reads as 18/01 for
// stunning.
inline bool uaqPumStr1801PlusCountsAs1801()
    { return true; }

// The example: a strength-15
// fighter versus padded
// armor (exposed) - 30
// percent bare-fist, 60
// percent with a dagger
// pommel, 75 percent with
// a chair.
inline int uaqPumExStrength()
    { return 15; }

inline bool uaqPumExPaddedArmorExposed()
    { return true; }

inline int uaqPumExSmallSoftPct()
    { return 30; }

inline int uaqPumExSmallHardPct()
    { return 60; }

inline int uaqPumExLargeHardPct()
    { return 75; }

// A stunned opponent stays
// so 1-10 segments, unable
// to act, spells lost,
inline int uaqPumStunSegmentsLo()
    { return 1; }

inline int uaqPumStunSegmentsHi()
    { return 10; }

inline bool uaqPumStunNoActions()
    { return true; }

inline bool uaqPumStunSpellsLost()
    { return true; }

inline bool uaqPumStunConcentrationBroken()
    { return true; }

// concentration broken; a
// second stun brings 1-4
// rounds unconscious.
inline int uaqPumRestunUnconsciousLo()
    { return 1; }

inline int uaqPumRestunUnconsciousHi()
    { return 4; }

// The stunned defend
// without dexterity or
// shield, +4 to be hit.
inline bool uaqPumStunnedLosesDexAndShield()
    { return true; }

inline int uaqPumStunnedHitByBonus()
    { return 4; }

// Damage: small soft objects
// inflict 1-2 points, small
// hard 1-3 (the printed
// fragments), whether or
inline int uaqPumSmallSoftDamageLo()
    { return 1; }

inline int uaqPumSmallSoftDamageHi()
    { return 2; }

inline int uaqPumSmallHardDamageLo()
    { return 1; }

inline int uaqPumSmallHardDamageHi()
    { return 3; }

// not a stun occurs; the
// conventional-manner rule
// excludes normal weapon
// damage.
inline bool uaqPumDamageWhetherOrNotStun()
    { return true; }

// The large-object damage
// cells OCR-lost - flagged,
// PDF-gated.
inline bool uaqPumLargeDamageCellsGarble()
    { return true; }

// Class notes: monks take
// no pummeling initiative
// penalty and may pummel or
// strike open-hand;
inline bool uaqPumMonksNoInitPenalty()
    { return true; }

inline bool uaqPumMonksPummelOrOpenHand()
    { return true; }

// thieves (with
// thief-acrobats and assassins)
// gain +4 to hit from
// behind;
inline int uaqPumThievesBehindToHitBonus()
    { return 4; }

// the thief-acrobat
// tumbling note OCR-lost -
// flagged, PDF-gated;
inline bool uaqPumThiefTumblingNoteGarbles()
    { return true; }

// cavaliers (with paladins)
// pummel bare-handed at
// -2 to hit.
inline int uaqPumCavaliersBareHandToHitPenalty()
    { return 2; }

// Kicking: bare feet read
// small soft, metal-shod
// boots small hard;
inline bool uaqKickBareFeetSmallSoft()
    { return true; }

inline bool uaqKickMetalShodSmallHard()
    { return true; }

// a same-size defender
// counts only armor from the
// waist down;
inline bool uaqKickSameSizeWaistDownArmorOnly()
    { return true; }

// the smaller-target tail
// OCR-lost - flagged,
// PDF-gated;
inline bool uaqKickSmallerTailGarbles()
    { return true; }

// jumpers (monks,
// thief-acrobats, barbarians)
// kick any portion of a
inline int uaqKickJumperClassCount()
    { return 3; }

// same-size target; a
// higher elevation kicks
// any portion.
inline bool uaqKickJumperAnyPortionSameSize()
    { return true; }

inline bool uaqKickHigherElevationAnyPortion()
    { return true; }

// Throwing: a small object
// hurled 30 feet, a large
// one no more than 10;
inline int uaqThrowSmallRangeFeet()
    { return 30; }

inline int uaqThrowLargeRangeFeet()
    { return 10; }

// the throw reads a missile
// at long range (-5) plus
// strength if applicable;
inline int uaqThrowToHitLongRangeMod()
    { return -5; }

inline bool uaqThrowStrengthModApplies()
    { return true; }

// misses scatter as
// grenade-like missiles.
inline bool uaqThrowMissScattersGrenadeLike()
    { return true; }

// Grappling: any intelligent
// creature that can
// conceivably restrain an
// opponent.
inline bool uaqGrapAvailIntelligentRestraint()
    { return true; }

// Cannot grapple: the
// non-corporeal, the astral
// and ethereal natives,
inline bool uaqGrapNoNonCorporeal()
    { return true; }

inline bool uaqGrapNoAstralEthereal()
    { return true; }

// the non-intelligent slimes
// and jellies (a beholder
// or a bound orc, for
// instance).
inline bool uaqGrapNoUnintelligentSlimes()
    { return true; }

inline bool uaqGrapBeholderExample()
    { return true; }

inline bool uaqGrapBoundOrcExample()
    { return true; }

// The grapple delays an
// upcoming action or
// restrains the opponent
inline bool uaqGrapPurposeDelaysOrRestrains()
    { return true; }

// (the purpose sentence
// OCR-lost - flagged,
// PDF-gated).
inline bool uaqGrapPurposeSentenceGarbles()
    { return true; }

// Larger creatures cannot
// be grappled unless prone
inline bool uaqGrapLargerUnlessProne()
    { return true; }

// (the size word lost -
// position-decoded,
// flagged).
inline bool uaqGrapLargerWordGarbles()
    { return true; }

// Initiative at -1; damage
// earlier in the round
// ruins the attempt.
inline int uaqGrapInitPenalty()
    { return 1; }

inline bool uaqGrapSpoiledByPriorDamage()
    { return true; }

// Resolve: the effective AC
// (ignoring shield and
// magic armor, counting
// rings, protection
// devices, bracers and
// magical plate), then the
// to-hit roll.
inline int uaqGrapResolutionSteps()
    { return 2; }

inline bool uaqGrapEffAcIgnoresShieldMagicArmor()
    { return true; }

inline bool uaqGrapRingsProtectionBracersCount()
    { return true; }

inline bool uaqGrapMagicalPlateCounts()
    { return true; }

// A hold inflicts no damage
// and prevents further
// action that round;
inline bool uaqGrapNoDamage()
    { return true; }

inline bool uaqGrapPreventsFurtherAction()
    { return true; }

// the held target is -2 to
// hit and +2 to be hit,
// dexterity negated.
inline int uaqGrapVictimToHitPenalty()
    { return 2; }

inline int uaqGrapVictimHitByBonus()
    { return 2; }

inline bool uaqGrapDexNegatedWhileHeld()
    { return true; }

// The hold breaks five
// ways: the release;
inline int uaqGrapBreakWayCount()
    { return 5; }

inline bool uaqGrapBreakByRelease()
    { return true; }

// damage on the attacker
// (at -2);
inline bool uaqGrapBreakByInflictingDamage()
    { return true; }

inline int uaqGrapCounterAttacksAtPenalty()
    { return 2; }

// a counter-grapple (the
// original attacker keeps
// magic and dexterity,
inline bool uaqGrapCounterAttackerKeepsMagicDex()
    { return true; }

// plus the strength
// to-hit bonus as AC bonus;
inline bool uaqGrapCounterStrToHitAsAcBonus()
    { return true; }

// the Str-17 example tail
// OCR-lost - flagged);
inline bool uaqGrapStr17ExampleTailGarbles()
    { return true; }

inline bool uaqGrapBreakByCounterGrapple()
    { return true; }

// a bend-bars roll;
inline bool uaqGrapBreakByBendBars()
    { return true; }

// a thief-acrobat tumbles
// out on the evasion
// percentage.
inline bool uaqGrapBreakByAcrobatEvasion()
    { return true; }

// A held figure serves as
// a large soft pummeling
// object if liftable.
inline bool uaqGrapHeldAsLargeSoftObject()
    { return true; }

// Versus multiple separate
// attacks the grapple
// neutralizes only one
inline bool uaqGrapNeutralizesOneOfMany()
    { return true; }

// (the scorpion claw-or-sting
// example); same-weapon
// multiples all go.
inline bool uaqGrapScorpionExample()
    { return true; }

inline bool uaqGrapSameWeaponAllNeutralized()
    { return true; }

// A similar group grapples
// on a single roll, +2 per
// member beyond the first.
inline bool uaqGrapGroupSingleRoll()
    { return true; }

inline int uaqGrapPerExtraMemberBonus()
    { return 2; }

// The grapple counts: a
// size-S defender takes 3
// size-S attackers, 1-2
inline int uaqGrapDefSMaxSizeS()
    { return 3; }

// size-M, or 1 size-L;
inline int uaqGrapDefSBySizeMHi()
    { return 2; }

inline int uaqGrapDefSBySizeL()
    { return 1; }

// a size-M defender takes 3
// size-M (the rest of the
inline int uaqGrapDefMMaxSizeM()
    { return 3; }

// band OCR-lost - flagged,
// PDF-gated);
inline bool uaqGrapDefMBandsGarble()
    { return true; }

// a size-L defender takes 3
// size-L; a prone figure 8
// size-S, 6 size-M or 4
inline int uaqGrapDefLMaxSizeL()
    { return 3; }

inline int uaqGrapProneMaxSizeS()
    { return 8; }

inline int uaqGrapProneMaxSizeM()
    { return 6; }

inline int uaqGrapProneMaxSizeL()
    { return 4; }

// Overbearing: any creature
// against any other with a
// discernible upright
inline bool uaqOvbAnyVsAny()
    { return true; }

// position (not a purple
// worm or gelatinous
// cube).
inline bool uaqOvbNeedsDiscernibleUpright()
    { return true; }

inline bool uaqOvbPurpleWormCubeException()
    { return true; }

// A normal attack, no
// initiative modification;
inline bool uaqOvbNoInitModification()
    { return true; }

// prior damage in the round
// negates it.
inline bool uaqOvbSpoiledByPriorDamage()
    { return true; }

// Resolve: the effective AC,
// then the to-hit roll;
inline int uaqOvbResolutionSteps()
    { return 2; }

// no inherent damage (the
// situation may inflict
// it - flaming oil, a pit);
inline bool uaqOvbNoInherentDamage()
    { return true; }

inline bool uaqOvbSituationMayDamage()
    { return true; }

// the prone are +4 to be
// hit and strike at -2
inline int uaqOvbProneHitByBonus()
    { return 4; }

// until regaining their
// feet, and may be grappled
// and pummeled regardless
inline int uaqOvbProneStrikePenalty()
    { return 2; }

// of size class;
inline bool uaqOvbProneGrapplePummelAnySize()
    { return true; }

// the effective-AC prose
// OCR-lost - flagged,
// PDF-gated.
inline bool uaqOvbAcProseGarbles()
    { return true; }

// The Armor Class Adjustment
// for Size table reads
// clean: 3 defender rows by
inline int uaqOvbAcRows()
    { return 3; }

// 3 attacker columns; the
// diagonal is zero;
inline int uaqOvbAcCols()
    { return 3; }

// a size-S defender: 0
// versus S, +2 versus M,
// +4 versus L;
inline int uaqOvbAcDefSVsS()
    { return 0; }

inline int uaqOvbAcDefSVsM()
    { return 2; }

inline int uaqOvbAcDefSVsL()
    { return 4; }

// a size-M defender: -4
// versus S, 0 versus M,
// +2 versus L;
inline int uaqOvbAcDefMVsS()
    { return -4; }

inline int uaqOvbAcDefMVsM()
    { return 0; }

inline int uaqOvbAcDefMVsL()
    { return 2; }

// a size-L defender: -8
// versus S, -4 versus M,
// 0 versus L.
inline int uaqOvbAcDefLVsS()
    { return -8; }

inline int uaqOvbAcDefLVsM()
    { return -4; }

inline int uaqOvbAcDefLVsL()
    { return 0; }

// The footing list: 4 legs
// -6, 6 legs -8, more
// than 6 legs -10;
inline int uaqOvbFootFourLegsAcAdj()
    { return -6; }

inline int uaqOvbFootSixLegsAcAdj()
    { return -8; }

inline int uaqOvbFootMoreLegsAcAdj()
    { return -10; }

// no legs, never overborne;
inline bool uaqOvbNoLegsCannotBeOverborne()
    { return true; }

// size-L multi-leg creatures
// rise automatically the
// next round.
inline bool uaqOvbLargeMultiLegRiseAuto()
    { return true; }

// A similar group overbears
// on a single roll, +1 per
// figure after the first;
inline bool uaqOvbGroupSingleRoll()
    { return true; }

inline int uaqOvbPerExtraFigureBonus()
    { return 1; }

// a dissimilar group rolls
// the weakest to-hit
inline bool uaqOvbWeakestToHitUsed()
    { return true; }

// (the sentence tail
// OCR-lost - flagged,
// PDF-gated).
inline bool uaqOvbWeakestSentenceGarbles()
    { return true; }

// The overbear counts read
// clean: a size-S target
// takes 6 size-S, 4 size-M
inline int uaqOvbTargetSMaxSizeS()
    { return 6; }

inline int uaqOvbTargetSBySizeM()
    { return 4; }

// or 2 size-L;
inline int uaqOvbTargetSBySizeL()
    { return 2; }

// a size-M target 8 size-S,
// 6 size-M, 4 size-L;
inline int uaqOvbTargetMMaxSizeS()
    { return 8; }

inline int uaqOvbTargetMBySizeM()
    { return 6; }

inline int uaqOvbTargetMBySizeL()
    { return 4; }

// a size-L target 12 size-S,
// 8 size-M, 6 size-L.
inline int uaqOvbTargetLMaxSizeS()
    { return 12; }

inline int uaqOvbTargetLBySizeM()
    { return 8; }

inline int uaqOvbTargetLBySizeL()
    { return 6; }

// The R160 reconciliation:
// the DMG pp. 72-73 system
// (rules/weaponless.h)
// stays the engine default;
inline bool uaqR160DmgSystemStaysDefault()
    { return true; }

// the UA Appendix Q system
// pins here as its own data
// layer - the R374 dial
// precedent, run both.
inline bool uaqR160DivergentSystemsRunBoth()
    { return true; }

inline bool uaqR160OverlapReconciled()
    { return true; }

// The part ledger: six
// items, one fully clean,
// five flagged, none fully
// garbled.
inline int uaqPartItemTotal()
    { return 6; }

inline int uaqPartCleanCount()
    { return 1; }

inline int uaqPartFlaggedCount()
    { return 5; }

inline int uaqPartGarbledCount()
    { return 0; }
}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uaappendq.h: the pins')


s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 207, 'b inline count'
assert s.count('R389') == 1, 'b round tag'
assert s.count(
    'uaqSysOneHeightPctLimit'
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
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (c) the gap report: the
# amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R389' in s:
    already.append('gap: the amendment')
else:
    OLD = NL.join([
        '- [ ] **Appendix Q: weaponless combat**',
        '      (pp. 106-108) - the pummeling,',
        '      wrestling and overbearing systems,',
        '      the Pummeling Table and the',
        '      Overbearing AC Adjustments;',
        '      overlaps the R160 pin - reconcile',
        '      before charging.',
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = OLD + NL + NL.join([
        '      - AMENDED R389: the UA',
        '        weaponless combat appendix Q',
        '        pin round (rules/uaappendq.h)',
        '        - the pp. 106-108 stretch, SIX',
        '        items pin: ONE fully clean (the',
        '        throwing rules) plus FIVE',
        '        mechanics-clean with flagged',
        '        holes (the System I height',
        '        example cell, the Pummeling',
        '        Table row bodies, the kicking',
        '        tail, the grappling size bands,',
        '        the overbearing AC prose);',
        '        NOTHING fully garbles - the',
        '        item AMENDED, the prose',
        '        pinned, the R160 overlap',
        '        RECONCILED (the DMG pp. 72-73',
        '        system stays the engine',
        '        default, the UA System II',
        '        pins as its own data layer -',
        '        the R374 dial precedent),',
        '        stays PDF-gated only.',
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
    'AMENDED R389'
) == 1, 'c amendment'
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
    '(rules/uamiscprose2.h)'
) == 1, 'c misc2 note kept'
assert s.count(
    '(rules/uaappendq.h)'
) == 1, 'c appendq note'
assert s.count(
    '(rules/uamweapprose.h)'
) == 1, 'c mweapprose note kept'
assert s.count(
    '(rules/uaarmprose.h)'
) == 1, 'c armprose note kept'
assert s.count(
    '(rules/uamiscprose6.h)'
) == 1, 'c misc6 note kept'
assert s.count(
    '(rules/uamiscprose5.h)'
) == 1, 'c misc5 note kept'
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
assert s.count(
    '- [ ] **Appendix Q: weaponless combat**'
) == 1, 'c appendix q kept open'
assert s.count(
    '- [ ] **Appendix R: non-lethal combat**'
) == 1, 'c appendix r kept open'
assert len(applied) + len(already) == 3, 'c count'


# ---- (d) regtest.cpp: the
# includes, the audit, the
# census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R389 UA weaponless combat pin audit' in s:
    already.append('regtest.cpp: the R389 audit')
else:
    INC_ANCH = ('#include "rules/uamweapprose.h"  // '
        'R388: the UA misc weapons prose')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uaappendq.h"  // R389: the UA weaponless combat'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R389: the UA
    // weaponless combat appendix
    // Q pin audit ----
    // The pp. 106-108 stretch:
    // six items pin - one fully
    // clean (the throwing rules)
    // plus five mechanics-clean
    // with flagged holes (the
    // System I height example
    // cell, the pummeling table
    // row bodies, the kicking
    // tail, the grappling size
    // bands, the overbearing AC
    // prose); the R160 seam the
    // DMG default, the R388 seam
    // the misc weapons ledger.
    {
        using namespace rules;
        int bad = 0;
            if (!uaqSysOneSimpleQuickSystem()) ++bad;
            if (!uaqSysTwoOutgrowthMorePowerful()) ++bad;
            if (uaqSysOneUserTypeCount() != 3) ++bad;
            if (uaqSysOneActionCount() != 3) ++bad;
            if (uaqSysOneHeightPctLimit() != 125) ++bad;
            if (uaqSysOneExampleShortFt() != 4) ++bad;
            if (uaqSysOneExampleTallFt() != 5) ++bad;
            if (!uaqSysOneSixFtExampleGarbles()) ++bad;
            if (!uaqSysOneToHitStrengthOnlyMod()) ++bad;
            if (!uaqSysOneDefenderArmorDexMagic()) ++bad;
            if (uaqSysOnePummelDelaySegments() != 1) ++bad;
            if (uaqSysOnePummelDamageLo() != 1) ++bad;
            if (uaqSysOnePummelDamageHi() != 2) ++bad;
            if (!uaqSysOnePummelStrBonusNeedsWeapon()) ++bad;
            if (!uaqSysOnePummelMultiNoExtraDelay()) ++bad;
            if (!uaqSysOneGrappleNoDamage()) ++bad;
            if (uaqSysOneGrappleHoldRounds() != 1) ++bad;
            if (uaqSysOneGrappledToHitPenalty() != 2) ++bad;
            if (uaqSysOneGrappledHitByBonus() != 2) ++bad;
            if (!uaqSysOneGrappleAutoBreaksNextRound()) ++bad;
            if (!uaqSysOneOverbearKnocksProne()) ++bad;
            if (uaqSysOneProneHitByBonus() != 4) ++bad;
            if (uaqSysOneInitPenalty() != 2) ++bad;
            if (!uaqSysOneSpoiledByPriorDamage()) ++bad;
            if (!uaqPumAvailWithStrengthScore()) ++bad;
            if (uaqPumMayRosterCount() != 4) ++bad;
            if (uaqPumMayNotRosterCount() != 3) ++bad;
            if (!uaqPumTargetNonUndeadNonVegetable()) ++bad;
            if (!uaqPumTargetPrimeNative()) ++bad;
            if (uaqPumCannotRosterCount() != 5) ++bad;
            if (!uaqPumDemonExceptionGarbles()) ++bad;
            if (!uaqPumSameOrSmallerSizeClass()) ++bad;
            if (!uaqPumAnySizeIfTargetProne()) ++bad;
            if (uaqPumInitPenalty() != 4) ++bad;
            if (!uaqPumDexModsStillApply()) ++bad;
            if (!uaqPumSurpriseNoInitPenalty()) ++bad;
            if (!uaqPumBehindNoInitPenalty()) ++bad;
            if (uaqPumSurpriseOrBehindToHitBonus() != 2) ++bad;
            if (!uaqPumSpoiledByPriorDamage()) ++bad;
            if (uaqPumResolutionSteps() != 4) ++bad;
            if (uaqPumObjTypeCount() != 4) ++bad;
            if (uaqPumObjSmallSoft() != 0) ++bad;
            if (uaqPumObjSmallHard() != 1) ++bad;
            if (uaqPumObjLargeSoft() != 2) ++bad;
            if (uaqPumObjLargeHard() != 3) ++bad;
            if (!uaqPumLargeObjPickupRound()) ++bad;
            if (!uaqPumMoreVulnerableCategoryWins()) ++bad;
            if (!uaqPumExposedBareHeadOrFace()) ++bad;
            if (!uaqPumExposedOrdinaryCapClothing()) ++bad;
            if (!uaqPumExposedLeatherOrPadded()) ++bad;
            if (uaqPumExposedNaturalAcWorst() != 7) ++bad;
            if (!uaqPumSemiRingToPlateMail()) ++bad;
            if (uaqPumSemiNaturalLo() != 7) ++bad;
            if (uaqPumSemiNaturalHi() != 2) ++bad;
            if (!uaqPumUnexposedFullOrFieldPlate()) ++bad;
            if (uaqPumUnexposedNaturalAcBest() != 2) ++bad;
            if (!uaqPumVulnIgnoresShieldsAndMagicArmor()) ++bad;
            if (!uaqPumEffAcShieldIgnoredUnlessBuckler()) ++bad;
            if (!uaqPumEffAcMagicAndDexCount()) ++bad;
            if (!uaqPumAcaReadsFistOrOpenHand()) ++bad;
            if (uaqPumTableRows() != 3) ++bad;
            if (uaqPumTableCols() != 4) ++bad;
            if (uaqPumExposedSmallSoftPerPt() != 2) ++bad;
            if (uaqPumExposedSmallSoftCap() != 40) ++bad;
            if (uaqPumExposedSmallHardPerPt() != 4) ++bad;
            if (uaqPumExposedSmallHardCap() != 75) ++bad;
            if (uaqPumExposedLargeHardPerPt() != 5) ++bad;
            if (uaqPumExposedLargeHardCap() != 95) ++bad;
            if (uaqPumFragPair1PerPt() != 1) ++bad;
            if (uaqPumFragPair1Cap() != 20) ++bad;
            if (uaqPumFragPair2PerPt() != 2) ++bad;
            if (uaqPumFragPair2Cap() != 40) ++bad;
            if (uaqPumFragPair3PerPt() != 4) ++bad;
            if (uaqPumFragPair3Cap() != 75) ++bad;
            if (!uaqPumTableRowBodiesGarble()) ++bad;
            if (!uaqPumStr1801PlusCountsAs1801()) ++bad;
            if (uaqPumExStrength() != 15) ++bad;
            if (!uaqPumExPaddedArmorExposed()) ++bad;
            if (uaqPumExSmallSoftPct() != 30) ++bad;
            if (uaqPumExSmallHardPct() != 60) ++bad;
            if (uaqPumExLargeHardPct() != 75) ++bad;
            if (uaqPumStunSegmentsLo() != 1) ++bad;
            if (uaqPumStunSegmentsHi() != 10) ++bad;
            if (!uaqPumStunNoActions()) ++bad;
            if (!uaqPumStunSpellsLost()) ++bad;
            if (!uaqPumStunConcentrationBroken()) ++bad;
            if (uaqPumRestunUnconsciousLo() != 1) ++bad;
            if (uaqPumRestunUnconsciousHi() != 4) ++bad;
            if (!uaqPumStunnedLosesDexAndShield()) ++bad;
            if (uaqPumStunnedHitByBonus() != 4) ++bad;
            if (uaqPumSmallSoftDamageLo() != 1) ++bad;
            if (uaqPumSmallSoftDamageHi() != 2) ++bad;
            if (uaqPumSmallHardDamageLo() != 1) ++bad;
            if (uaqPumSmallHardDamageHi() != 3) ++bad;
            if (!uaqPumDamageWhetherOrNotStun()) ++bad;
            if (!uaqPumLargeDamageCellsGarble()) ++bad;
            if (!uaqPumMonksNoInitPenalty()) ++bad;
            if (!uaqPumMonksPummelOrOpenHand()) ++bad;
            if (uaqPumThievesBehindToHitBonus() != 4) ++bad;
            if (!uaqPumThiefTumblingNoteGarbles()) ++bad;
            if (uaqPumCavaliersBareHandToHitPenalty() != 2) ++bad;
            if (!uaqKickBareFeetSmallSoft()) ++bad;
            if (!uaqKickMetalShodSmallHard()) ++bad;
            if (!uaqKickSameSizeWaistDownArmorOnly()) ++bad;
            if (!uaqKickSmallerTailGarbles()) ++bad;
            if (uaqKickJumperClassCount() != 3) ++bad;
            if (!uaqKickJumperAnyPortionSameSize()) ++bad;
            if (!uaqKickHigherElevationAnyPortion()) ++bad;
            if (uaqThrowSmallRangeFeet() != 30) ++bad;
            if (uaqThrowLargeRangeFeet() != 10) ++bad;
            if (uaqThrowToHitLongRangeMod() != -5) ++bad;
            if (!uaqThrowStrengthModApplies()) ++bad;
            if (!uaqThrowMissScattersGrenadeLike()) ++bad;
            if (!uaqGrapAvailIntelligentRestraint()) ++bad;
            if (!uaqGrapNoNonCorporeal()) ++bad;
            if (!uaqGrapNoAstralEthereal()) ++bad;
            if (!uaqGrapNoUnintelligentSlimes()) ++bad;
            if (!uaqGrapBeholderExample()) ++bad;
            if (!uaqGrapBoundOrcExample()) ++bad;
            if (!uaqGrapPurposeDelaysOrRestrains()) ++bad;
            if (!uaqGrapPurposeSentenceGarbles()) ++bad;
            if (!uaqGrapLargerUnlessProne()) ++bad;
            if (!uaqGrapLargerWordGarbles()) ++bad;
            if (uaqGrapInitPenalty() != 1) ++bad;
            if (!uaqGrapSpoiledByPriorDamage()) ++bad;
            if (uaqGrapResolutionSteps() != 2) ++bad;
            if (!uaqGrapEffAcIgnoresShieldMagicArmor()) ++bad;
            if (!uaqGrapRingsProtectionBracersCount()) ++bad;
            if (!uaqGrapMagicalPlateCounts()) ++bad;
            if (!uaqGrapNoDamage()) ++bad;
            if (!uaqGrapPreventsFurtherAction()) ++bad;
            if (uaqGrapVictimToHitPenalty() != 2) ++bad;
            if (uaqGrapVictimHitByBonus() != 2) ++bad;
            if (!uaqGrapDexNegatedWhileHeld()) ++bad;
            if (uaqGrapBreakWayCount() != 5) ++bad;
            if (!uaqGrapBreakByRelease()) ++bad;
            if (!uaqGrapBreakByInflictingDamage()) ++bad;
            if (uaqGrapCounterAttacksAtPenalty() != 2) ++bad;
            if (!uaqGrapCounterAttackerKeepsMagicDex()) ++bad;
            if (!uaqGrapCounterStrToHitAsAcBonus()) ++bad;
            if (!uaqGrapStr17ExampleTailGarbles()) ++bad;
            if (!uaqGrapBreakByCounterGrapple()) ++bad;
            if (!uaqGrapBreakByBendBars()) ++bad;
            if (!uaqGrapBreakByAcrobatEvasion()) ++bad;
            if (!uaqGrapHeldAsLargeSoftObject()) ++bad;
            if (!uaqGrapNeutralizesOneOfMany()) ++bad;
            if (!uaqGrapScorpionExample()) ++bad;
            if (!uaqGrapSameWeaponAllNeutralized()) ++bad;
            if (!uaqGrapGroupSingleRoll()) ++bad;
            if (uaqGrapPerExtraMemberBonus() != 2) ++bad;
            if (uaqGrapDefSMaxSizeS() != 3) ++bad;
            if (uaqGrapDefSBySizeMHi() != 2) ++bad;
            if (uaqGrapDefSBySizeL() != 1) ++bad;
            if (uaqGrapDefMMaxSizeM() != 3) ++bad;
            if (!uaqGrapDefMBandsGarble()) ++bad;
            if (uaqGrapDefLMaxSizeL() != 3) ++bad;
            if (uaqGrapProneMaxSizeS() != 8) ++bad;
            if (uaqGrapProneMaxSizeM() != 6) ++bad;
            if (uaqGrapProneMaxSizeL() != 4) ++bad;
            if (!uaqOvbAnyVsAny()) ++bad;
            if (!uaqOvbNeedsDiscernibleUpright()) ++bad;
            if (!uaqOvbPurpleWormCubeException()) ++bad;
            if (!uaqOvbNoInitModification()) ++bad;
            if (!uaqOvbSpoiledByPriorDamage()) ++bad;
            if (uaqOvbResolutionSteps() != 2) ++bad;
            if (!uaqOvbNoInherentDamage()) ++bad;
            if (!uaqOvbSituationMayDamage()) ++bad;
            if (uaqOvbProneHitByBonus() != 4) ++bad;
            if (uaqOvbProneStrikePenalty() != 2) ++bad;
            if (!uaqOvbProneGrapplePummelAnySize()) ++bad;
            if (!uaqOvbAcProseGarbles()) ++bad;
            if (uaqOvbAcRows() != 3) ++bad;
            if (uaqOvbAcCols() != 3) ++bad;
            if (uaqOvbAcDefSVsS() != 0) ++bad;
            if (uaqOvbAcDefSVsM() != 2) ++bad;
            if (uaqOvbAcDefSVsL() != 4) ++bad;
            if (uaqOvbAcDefMVsS() != -4) ++bad;
            if (uaqOvbAcDefMVsM() != 0) ++bad;
            if (uaqOvbAcDefMVsL() != 2) ++bad;
            if (uaqOvbAcDefLVsS() != -8) ++bad;
            if (uaqOvbAcDefLVsM() != -4) ++bad;
            if (uaqOvbAcDefLVsL() != 0) ++bad;
            if (uaqOvbFootFourLegsAcAdj() != -6) ++bad;
            if (uaqOvbFootSixLegsAcAdj() != -8) ++bad;
            if (uaqOvbFootMoreLegsAcAdj() != -10) ++bad;
            if (!uaqOvbNoLegsCannotBeOverborne()) ++bad;
            if (!uaqOvbLargeMultiLegRiseAuto()) ++bad;
            if (!uaqOvbGroupSingleRoll()) ++bad;
            if (uaqOvbPerExtraFigureBonus() != 1) ++bad;
            if (!uaqOvbWeakestToHitUsed()) ++bad;
            if (!uaqOvbWeakestSentenceGarbles()) ++bad;
            if (uaqOvbTargetSMaxSizeS() != 6) ++bad;
            if (uaqOvbTargetSBySizeM() != 4) ++bad;
            if (uaqOvbTargetSBySizeL() != 2) ++bad;
            if (uaqOvbTargetMMaxSizeS() != 8) ++bad;
            if (uaqOvbTargetMBySizeM() != 6) ++bad;
            if (uaqOvbTargetMBySizeL() != 4) ++bad;
            if (uaqOvbTargetLMaxSizeS() != 12) ++bad;
            if (uaqOvbTargetLBySizeM() != 8) ++bad;
            if (uaqOvbTargetLBySizeL() != 6) ++bad;
            if (!uaqR160DmgSystemStaysDefault()) ++bad;
            if (!uaqR160DivergentSystemsRunBoth()) ++bad;
            if (!uaqR160OverlapReconciled()) ++bad;
            if (uaqPartItemTotal() != 6) ++bad;
            if (uaqPartCleanCount() != 1) ++bad;
            if (uaqPartFlaggedCount() != 5) ++bad;
            if (uaqPartGarbledCount() != 0) ++bad;
        // ---- the cross-checks ----
        // the height example:
        // 4 feet at 125 percent
        // reads 5 feet
            if (uaqSysOneExampleShortFt()
                * uaqSysOneHeightPctLimit()
                / 100 != uaqSysOneExampleTallFt())
                ++bad;
        // the Str-15 example
        // multiplies the decoded
        // per-point cells exactly
            if (uaqPumExStrength()
                * uaqPumExposedSmallSoftPerPt()
                != uaqPumExSmallSoftPct())
                ++bad;
            if (uaqPumExStrength()
                * uaqPumExposedSmallHardPerPt()
                != uaqPumExSmallHardPct())
                ++bad;
            if (uaqPumExStrength()
                * uaqPumExposedLargeHardPerPt()
                != uaqPumExLargeHardPct())
                ++bad;
        // the caps climb
        // 40 < 75 < 95
            if (uaqPumExposedSmallSoftCap()
                >= uaqPumExposedSmallHardCap()
                || uaqPumExposedSmallHardCap()
                >= uaqPumExposedLargeHardCap())
                ++bad;
        // the fragment pairs
        // tile the 18/01 caps:
        // 20 = 1 x 20, 40 = 2 x 20
            if (uaqPumFragPair1PerPt() * 20
                != uaqPumFragPair1Cap()
                || uaqPumFragPair2PerPt() * 20
                != uaqPumFragPair2Cap())
                ++bad;
        // the four object ids
        // are 0-3 contiguous
            if (uaqPumObjSmallSoft() + 1
                != uaqPumObjSmallHard()
                || uaqPumObjSmallHard() + 1
                != uaqPumObjLargeSoft()
                || uaqPumObjLargeSoft() + 1
                != uaqPumObjLargeHard())
                ++bad;
        // the ledger sums
            if (uaqPartCleanCount()
                + uaqPartFlaggedCount()
                + uaqPartGarbledCount()
                != uaqPartItemTotal())
                ++bad;
        // the overbear size-AC
        // diagonal is zero and
        // the rows shift by 4,
        // 2 and 2
            if (uaqOvbAcDefSVsS() != 0
                || uaqOvbAcDefMVsM() != 0
                || uaqOvbAcDefLVsL() != 0
                || uaqOvbAcDefSVsM()
                - uaqOvbAcDefSVsS() != 2
                || uaqOvbAcDefMVsM()
                - uaqOvbAcDefMVsS() != 4
                || uaqOvbAcDefLVsM()
                - uaqOvbAcDefLVsS() != 4)
                ++bad;
        // the footing ladder
        // descends -6 -8 -10
            if (uaqOvbFootFourLegsAcAdj()
                <= uaqOvbFootSixLegsAcAdj()
                || uaqOvbFootSixLegsAcAdj()
                <= uaqOvbFootMoreLegsAcAdj())
                ++bad;
        // the overbear count
        // bands descend within
        // each row and climb
        // by row
            if (uaqOvbTargetSMaxSizeS()
                <= uaqOvbTargetSBySizeM()
                || uaqOvbTargetSBySizeM()
                <= uaqOvbTargetSBySizeL()
                || uaqOvbTargetMMaxSizeS()
                <= uaqOvbTargetMBySizeM()
                || uaqOvbTargetMBySizeM()
                <= uaqOvbTargetMBySizeL()
                || uaqOvbTargetLMaxSizeS()
                <= uaqOvbTargetLBySizeM()
                || uaqOvbTargetLBySizeM()
                <= uaqOvbTargetLBySizeL()
                || uaqOvbTargetMMaxSizeS()
                - uaqOvbTargetSMaxSizeS() != 2
                || uaqOvbTargetLMaxSizeS()
                - uaqOvbTargetMMaxSizeS() != 4)
                ++bad;
        // the grapple prone
        // bands descend 8 6 4
            if (uaqGrapProneMaxSizeS()
                - uaqGrapProneMaxSizeM() != 2
                || uaqGrapProneMaxSizeM()
                - uaqGrapProneMaxSizeL() != 2)
                ++bad;
        // the stun bands
            if (uaqPumStunSegmentsLo() != 1
                || uaqPumStunSegmentsHi() != 10
                || uaqPumRestunUnconsciousLo() != 1
                || uaqPumRestunUnconsciousHi()
                != 4) ++bad;
        // ---- the R160 seam ----
        // the DMG pp. 72-73 system
        // stays the engine default:
        // its pummel base ladder
        // reads AC x 10
            if (pummelBaseChance(10) != 100
                || pummelBaseChance(9) != 90
                || pummelBaseChance(0) != 0)
                ++bad;
        printf("R389 UA weaponless combat pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R389 audit')


s = rd(RT)
assert s.count(
    'R389 UA weaponless combat pin audit: bad '
) == 1, 'd audit line'
assert s.count(
    'R388 UA misc weapons prose pin audit: bad '
) == 1, 'd r388 kept'
assert s.count(
    'R387 UA armor and swords prose pin audit: bad '
) == 1, 'd r387 kept'
assert s.count(
    'R386 UA misc magic prose part 6 pin audit: bad '
) == 1, 'd kept'
assert s.count(
    'R385 UA misc magic prose part 5 pin audit: bad '
) == 1, 'd kept'
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
assert s.count('audit: bad ') == 316, 'd census 316'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uaappendq.h"'
) == 1, 'd new include'
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
    'R389 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R389 note: the UA weaponless',
    'combat appendix Q round - the',
    'pp. 106-108 stretch, six items',
    'pin: one fully clean (the',
    'throwing rules) plus five',
    'mechanics-clean with flagged',
    'holes (the System I height',
    'example cell, the Pummeling',
    'Table row bodies, the kicking',
    'tail, the grappling size bands,',
    'the overbearing AC prose);',
    'nothing fully garbles - the',
    'item AMENDED, the prose',
    'pinned, the R160 overlap',
    'reconciled (the DMG system',
    'stays the engine default, the',
    'UA System II pins as its own',
    'data layer), stays PDF-gated',
    'only; the R388 seam the misc',
    'weapons ledger; the census',
    '315 -> 316',
])
print(NOTE)
print('commit: R389: the UA')
print('weaponless combat appendix')
print('Q pin round (census 316)')

