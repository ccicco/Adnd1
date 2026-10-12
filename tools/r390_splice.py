
# R390: the UA non-lethal
# combat appendix R pin round:
# the pp. 109-110 stretch, SEVEN
# items pin - TWO fully clean
# (the subdual eligibility, the
# subdual damage accounting) plus
# FIVE mechanics-clean with
# flagged holes (the subdual
# supercedes sentence, the
# vanquishing loser sentence, the
# chaotic constraints line, the
# monks-druids garble head, the
# disarming scimitar seam);
# NOTHING fully garbles - the
# item AMENDED with the R390
# note, the prose pinned, the
# R159 overlap RECONCILED (the
# DMG p.67 knockout stays the
# engine default, the UA subdual
# pins as its own data layer -
# the R374 dial precedent), the
# R389 seam the System II
# weaponless layer; the census
# 316 -> 317.
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


# ---- (a) the seed: the R389
# record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R389 landed 2026-10-12: commit',
    '  b20764a, census 316, the UA',
    '  weaponless combat appendix Q',
    '  pin round (rules/uaappendq.h):',
    '  the pp. 106-108 stretch, 207',
    '  uaq pins, six items pin -',
    '  one fully clean (the',
    '  throwing rules) plus five',
    '  mechanics-clean with flagged',
    '  holes (the System I height',
    '  example cell, the Pummeling',
    '  Table row bodies, the kicking',
    '  tail, the grappling size',
    '  bands, the overbearing AC',
    '  prose); nothing fully',
    '  garbles; the R160 overlap',
    '  reconciled (the DMG system',
    '  stays the engine default,',
    '  the UA System II pins as its',
    '  own data layer); GREEN on',
    '  the first run after the',
    '  printf-label fix.',
])
s = rd(SD)
if 'R389 landed 2026-10-12' in s:
    already.append('seed: the R389 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R389 record')
s = rd(SD)
assert s.count(
    'R389 landed 2026-10-12'
) == 1, 'a entry'


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


# ---- (b) NEW rules/uaappendr.h ----
P = 'rules/uaappendr.h'
if os.path.exists(P) and 'R390' in rd(P):
    already.append('uaappendr.h: the pins')
else:
    HDR = r"""// ==========================================================================
// Adnd1 - rules/uaappendr.h
// The UA APPENDIX R: NON-LETHAL
// COMBAT pins, R390: the pp.
// 109-110 stretch - seven items,
// two fully clean (the subdual
// eligibility, the subdual damage
// accounting) plus five
// mechanics-clean with flagged
// holes (the subdual supercedes
// sentence, the vanquishing
// loser sentence, the chaotic
// constraints line, the
// monks-druids garble head, the
// disarming scimitar seam).
// Nothing fully garbles - the
// recoverable tails pin, the
// destroyed heads flag. The R159
// overlap RECONCILED: the DMG
// p.67 knockout stays the engine
// default; this header pins the
// UA subdual layer as its own
// data - the R374 dial
// precedent. The disarming
// recommendation rides the R389
// System II seam. Pin-era
// pattern (R322).
namespace rules {

// Subdual: an effective form of
// non-lethal combat.
inline bool uanlSubdualEffectiveNonLethal()
    { return true; }
// Used against creatures of at
// least low intelligence.
inline bool uanlSubdualIntMinLow()
    { return true; }
// No greater than genius
// intelligence.
inline bool uanlSubdualIntMaxGenius()
    { return true; }
// Used against dragons and
// similar types of creatures.
inline bool uanlSubdualSimilarTypesDragons()
    { return true; }
// Named examples: basilisks,
// wyverns, dragonnes, giants,
// ettins, bugbears - six.
inline int uanlSubdualExampleCreatureCount()
    { return 6; }
// Also against giants, ettins,
// bugbears and other humanoid
// non-magical creatures of
// size L.
inline bool uanlSubdualHumanoidNonMagicalSizeL()
    { return true; }
// Whether other creatures are
// affected: the DM decides.
inline bool uanlSubdualOtherCreaturesDMDecision()
    { return true; }
// Planar creatures cannot be
// subdued except on those
// planes.
inline bool uanlSubdualPlanarNativePlaneOnly()
    { return true; }
// Player characters can never
// be subdued.
inline bool uanlSubdualPCsNeverSubduable()
    { return true; }
// All attackers must use the
// flat, butt, haft, pommel or
// other non-lethal part of
// the weapon.
inline bool uanlSubdualFlatButtHaftPommel()
    { return true; }
// Full damage or damage-
// inflicting spells negate the
// subdual effects recorded up
// to that point.
inline bool uanlSubdualFullDamageNegates()
    { return true; }
// Subdual damage is noted
// separately from real damage.
inline bool uanlSubdualNotedSeparately()
    { return true; }
// 75 percent temporary.
inline int uanlSubdualTemporaryPct()
    { return 75; }
// 25 percent real.
inline int uanlSubdualRealPct()
    { return 25; }
// The print example: 40 points
// of subdual damage.
inline int uanlSubdualExamplePoints()
    { return 40; }
// Only 10 of those points are
// real (inflicted on a stone
// giant).
inline int uanlSubdualExampleReal()
    { return 10; }
// Subdued when subdual damage
// exceeds the total hit points
// of the creature - the UA
// reading; the R159 engine
// knockout reads meets-or-
// exceeds: run both layers.
inline bool uanlSubdualSubduedWhenExceedsTotal()
    { return true; }
// A subdued victim will not
// attack after being subdued
// except in self-defense.
inline bool uanlSubduedNoAttackExceptSelfDefense()
    { return true; }
// Subduing a monster: it will
// not further attack the group
// that subdued it.
inline bool uanlSubduedMonsterWillNotAttackGroup()
    { return true; }
// If captured, submits but
// seeks the first chance to
// escape.
inline bool uanlSubduedSubmitsSeeksEscape()
    { return true; }
// Turns on its captors if the
// party is weaker than itself.
inline bool uanlSubduedTurnsIfPartyWeaker()
    { return true; }
// The subdual lasts as long
// as the party has a clear
// upper hand.
inline bool uanlSubdualLastsWhileUpperHand()
    { return true; }
// FLAG: the print splits
// 'super-/previously published'
// - the requirements and
// effects of subdual under
// this section supercede the
// previously published
// material.
inline bool uanlSubdualSupercedesPublished()
    { return true; }
// In particular with regard
// to the subdual of dragons -
// the R159 seam.
inline bool uanlSubdualSupercedesDragonSubdual()
    { return true; }
// Vanquishing: used by
// cavaliers, paladins, monks
// and other lawful creatures
// to settle disputes without
// excessive bloodshed.
inline bool uanlVanqUsedByLawfulToSettle()
    { return true; }
// Involves a duel of honor.
inline bool uanlVanqDuelOfHonor()
    { return true; }
// One combatant issues the
// challenge; the opponent
// must take it up.
inline bool uanlVanqChallengeMustTakeUp()
    { return true; }
// Only between two intelligent
// beings capable of
// understanding each other's
// language.
inline bool uanlVanqIntelligentLanguageCapable()
    { return true; }
// Who choose to communicate
// and agree to the combat.
inline bool uanlVanqMustCommunicateAndAgree()
    { return true; }
// Combat proceeds as normal;
// each holds back blows that
// would otherwise kill
// outright, proving mastery
// by superior weapon-handling.
inline bool uanlVanqCombatNormalHoldingBack()
    { return true; }
// Only one quarter of the
// damage inflicted is real
// between honor-bound
// opponents - the same 25
// percent as subdual.
inline int uanlVanqRealDamageQuarterPct()
    { return 25; }
// Either side may resort to
// real combat at the start of
// any round.
inline bool uanlVanqResortToRealAtRoundStart()
    { return true; }
// Any full real damage (by an
// opponent or a third party)
// negates the vanquishing.
inline bool uanlVanqFullRealDamageNegates()
    { return true; }
// Temporary points lost are
// ignored; both parties attack
// normally.
inline bool uanlVanqTemporaryLostIgnored()
    { return true; }
// Poisoned blades, vorpal
// swords and similar weapons
// with automatic effects
// perform as if in real
// combat.
inline bool uanlVanqPoisonedVorpalPerformReal()
    { return true; }
// Vanquishing damage is noted
// separately from real
// damage.
inline bool uanlVanqDamageNotedSeparately()
    { return true; }
// FLAG: the print garbles
// 'reduced to0 hit points, he'
// - reduced to 0 hit points
// makes the loser; the
// 'must' tail garbles.
inline bool uanlVanqLoserAtZeroHp()
    { return true; }
// If both are reduced to 0 hit
// points in the same round,
// the combat is a draw.
inline bool uanlVanqDrawIfBothZeroSameRound()
    { return true; }
// The winner may demand a
// single service or item from
// the loser.
inline bool uanlVanqWinnerDemandSingle()
    { return true; }
// Service examples: banishment
// from the area for a time,
// carry a message, a small
// favor, sing the praises of
// the victor - four.
inline int uanlVanqServiceExampleCount()
    { return 4; }
// An item may include any one
// weapon, armor or shield of
// the loser (including magic
// items).
inline bool uanlVanqItemWeaponArmorShield()
    { return true; }
// Or a treasure of a value
// not more than 1,000 gp times
// the loser's hit dice or
// level.
inline int uanlVanqTreasureGpPerHitDieOrLevel()
    { return 1000; }
// Attempts to enslave or slay
// a vanquished opponent free
// the opponent from any duty
// to the victor.
inline bool uanlVanqEnslaveOrSlayFreesDuty()
    { return true; }
// A vanquished opponent may be
// imprisoned if the victor
// stated that fact in the
// initial challenge.
inline bool uanlVanqImprisonIfStated()
    { return true; }
// Lawful creatures defeated
// this manner are honor-bound
// to the terms of the victor,
// unless morally opposed to
// their alignments.
inline bool uanlVanqLawfulHonorBound()
    { return true; }
// Good creatures cannot be
// made to perform evil acts.
inline bool uanlVanqGoodCannotPerformEvil()
    { return true; }
// Neutral creatures have the
// choice of honoring the
// agreement.
inline bool uanlVanqNeutralHasChoice()
    { return true; }
// FLAG: the print garbles the
// 're under no con-straints'
// line - chaotic evil
// opponents see no problem
// striking after lowering
// defenses.
inline bool uanlVanqChaoticEvilNoConstraints()
    { return true; }
// In general, vanquishing
// combat takes place between
// only two combatants.
inline bool uanlVanqGenerallyTwoCombatants()
    { return true; }
// Multiple combat possible:
// the hit points of all
// members of one side must be
// brought to 0 for the other
// side to claim victory.
inline bool uanlVanqMultipleAllSideToZero()
    { return true; }
// Individuals reduced to 0
// vanquishing damage may
// continue to fight.
inline bool uanlVanqZeroDamageMayContinue()
    { return true; }
// All damage taken past that
// point is the full, normal
// amount.
inline bool uanlVanqPastZeroFullDamage()
    { return true; }
// A character reduced to 0 in
// multiple vanquishing combat
// usually retires with no
// loss of honor.
inline bool uanlVanqMultipleZeroRetiresHonor()
    { return true; }
// FLAG: the print garbles the
// sentence head (the monks
// and druids stretch) - the
// usage context recovers only
// in part.
inline bool uanlVanqMonksDruidsGarbleHead()
    { return true; }
// Used seeking to advance to
// the next level by combat
// (the legible tail of the
// garbled sentence).
inline bool uanlVanqUsedToAdvanceLevelByCombat()
    { return true; }
// Also used in lawful
// communities to apprehend
// felons for trial.
inline bool uanlVanqLawfulCommunitiesApprehend()
    { return true; }
// Disarming: only fighters,
// cavaliers and members of
// their sub-classes.
inline bool uanlDisarmFighterCavalierOnly()
    { return true; }
// Only the listed weapons, in
// order of length - six
// entries.
inline int uanlDisarmWeaponCount()
    { return 6; }
// The knife.
inline int uanlDisarmOrderKnife()
    { return 1; }
// The dagger.
inline int uanlDisarmOrderDagger()
    { return 2; }
// The horseman's mace.
inline int uanlDisarmOrderHorsemanMace()
    { return 3; }
// The short sword.
inline int uanlDisarmOrderShortSword()
    { return 4; }
// The footman's mace.
inline int uanlDisarmOrderFootmanMace()
    { return 5; }
// The broad, long, falchion or
// khopesh sword.
inline int uanlDisarmOrderSword()
    { return 6; }
// The khopesh has a chance of
// disarming an opponent in its
// normal mode of use.
inline bool uanlDisarmKhopeshDisarmsNormally()
    { return true; }
// Used intentionally for a
// disarm attempt, the rules
// here apply (the print
// footnote).
inline bool uanlDisarmKhopeshIntentionalTheseRules()
    { return true; }
// Only a fighter or cavalier
// wielding a weapon in which
// he or she has proficiency.
inline bool uanlDisarmRequiresProficiency()
    { return true; }
// Against an opponent likewise
// using one of the listed
// weapons.
inline bool uanlDisarmOpponentListedWeapon()
    { return true; }
// Any weapon requiring two
// hands can never be affected
// by this form of attack.
inline bool uanlDisarmTwoHandedNeverAffected()
    { return true; }
// Disarming inflicts no
// damage.
inline bool uanlDisarmInflictsNoDamage()
    { return true; }
// A successful hit forces the
// defender to save versus
// petrification or lose the
// weapon (superior swordplay).
inline bool uanlDisarmHitThenSaveVsPetrification()
    { return true; }
// Only against weapons of the
// same length or shorter.
inline bool uanlDisarmSameLengthOrShorterOnly()
    { return true; }
// A dagger may disarm someone
// holding a knife.
inline bool uanlDisarmExampleDaggerDisarmsKnife()
    { return true; }
// A scimitar may disarm
// someone with a mace.
inline bool uanlDisarmExampleScimitarDisarmsMace()
    { return true; }
// A dagger cannot disarm
// someone with a short sword.
inline bool uanlDisarmExampleDaggerNotShortSword()
    { return true; }
// FLAG: the scimitar example
// names a weapon not in the
// listed disarm weapons - a
// print seam, pinned as
// print.
inline bool uanlDisarmScimitarSeam()
    { return true; }
// The weapon falls at the
// owner's feet if the same
// size as the attacker's.
inline bool uanlDisarmFallsAtFeetIfSameSize()
    { return true; }
// If of a smaller size: 1-10
// feet away - the minimum.
inline int uanlDisarmFallsMinFeet()
    { return 1; }
// The 1-10 feet maximum.
inline int uanlDisarmFallsMaxFeet()
    { return 10; }
// The former wielder: take a
// round to recover the weapon,
// draw another, or engage in
// weaponless combat - three
// options.
inline int uanlDisarmRecoverOptionsCount()
    { return 3; }
// Recommended only if the
// weaponless combat System II
// is employed in the campaign
// - the R389 seam.
inline bool uanlDisarmRecommendedWithSystemTwo()
    { return true; }
// The item ledger: seven
// items.
inline int uanlPartItemTotal()
    { return 7; }
// Two fully clean (the subdual
// eligibility, the subdual
// damage accounting).
inline int uanlPartCleanCount()
    { return 2; }
// Five mechanics-clean with
// flagged holes (the subdual
// supercedes sentence, the
// vanquishing loser sentence,
// the chaotic constraints line,
// the monks-druids garble
// head, the disarming scimitar
// seam).
inline int uanlPartFlaggedCount()
    { return 5; }
// Nothing fully garbles - the
// recoverable tails pin, the
// destroyed heads flag.
inline int uanlPartGarbledCount()
    { return 0; }
}   // namespace rules
"""
    clean(HDR, 78)
    wr(P, HDR + NL)
    applied.append('uaappendr.h: the pins')



s = rd(P)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 85, 'b inline count'
assert s.count('R390') == 1, 'b round tag'
assert s.count(
    'uanlSubdualSubduedWhenExceedsTotal'
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
assert 'uaq' not in s, 'b no uaq ref'
assert 'treasdet' not in s, 'b no treasdet ref'
assert 'hoard' not in s, 'b no hoard ref'
assert 'subdualTemporaryPct' not in s, 'b no subdualTemporaryPct ref'
assert 'subdualRealDamage' not in s, 'b no subdualRealDamage ref'
assert 'pummelBaseChance' not in s, 'b no pummelBaseChance ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (c) the gap report: the
# amendment ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R390' in s:
    already.append('gap: the amendment')
else:
    OLD = NL.join([
        '- [ ] **Appendix R: non-lethal combat**',
        '      (pp. 109-110) - the subdual rules',
        '      (the intelligence bands, the flat',
        '      and butt requirement), the',
        '      grappling and disarming systems,',
        '      the vanquishing read, the footing',
        '      AC.',
    ])
    assert s.count(OLD) == 1, 'c1 old'
    NEW = OLD + NL + NL.join([
        '      - AMENDED R390: the UA',
        '        non-lethal combat appendix',
        '        R pin round (rules/uaappendr.h)',
        '        - the pp. 109-110 stretch,',
        '        SEVEN items pin: TWO fully',
        '        clean (the subdual',
        '        eligibility, the subdual',
        '        damage accounting) plus',
        '        FIVE mechanics-clean with',
        '        flagged holes (the subdual',
        '        supercedes sentence, the',
        '        vanquishing loser sentence,',
        '        the chaotic constraints',
        '        line, the monks-druids',
        '        garble head, the disarming',
        '        scimitar seam); NOTHING',
        '        fully garbles - the item',
        '        AMENDED, the prose pinned,',
        '        the R159 overlap RECONCILED',
        '        (the DMG p.67 knockout',
        '        stays the engine default,',
        '        the UA subdual pins as its',
        '        own data layer - the R374',
        '        dial precedent), the R389',
        '        seam the System II',
        '        weaponless layer, stays',
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
    '- [ ] **Appendix S: non-human deities**'
) == 1, 'c item kept open'
assert s.count(
    '- [ ] **Appendix R: non-lethal combat**'
) == 1, 'c item kept open'
assert s.count(
    'AMENDED R390'
) == 1, 'c amendment'
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
if 'R390 UA non-lethal combat pin audit' in s:
    already.append('regtest.cpp: the R390 audit')
else:
    INC_ANCH = ('#include "rules/uaappendq.h"  // '
        'R389: the UA weaponless combat')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uaappendr.h"  // R390: the UA '
        'non-lethal combat'
    ])
    AUD_ANCH = '    // ---- R227: the wis mental save wiring audit ----'
    AUDIT = r"""    // ---- R390: the UA
    // non-lethal combat appendix
    // R pin audit ----
    // The pp. 109-110 stretch:
    // seven items pin - two
    // fully clean (the subdual
    // eligibility, the subdual
    // damage accounting) plus
    // five mechanics-clean with
    // flagged holes (the subdual
    // supercedes sentence, the
    // vanquishing loser sentence,
    // the chaotic constraints
    // line, the monks-druids
    // garble head, the disarming
    // scimitar seam); the R159
    // seam the DMG knockout, the
    // R389 seam the System II
    // layer.
    {
        using namespace rules;
        int bad = 0;
            if (!uanlSubdualEffectiveNonLethal()) ++bad;
            if (!uanlSubdualIntMinLow()) ++bad;
            if (!uanlSubdualIntMaxGenius()) ++bad;
            if (!uanlSubdualSimilarTypesDragons()) ++bad;
            if (uanlSubdualExampleCreatureCount() != 6) ++bad;
            if (!uanlSubdualHumanoidNonMagicalSizeL()) ++bad;
            if (!uanlSubdualOtherCreaturesDMDecision()) ++bad;
            if (!uanlSubdualPlanarNativePlaneOnly()) ++bad;
            if (!uanlSubdualPCsNeverSubduable()) ++bad;
            if (!uanlSubdualFlatButtHaftPommel()) ++bad;
            if (!uanlSubdualFullDamageNegates()) ++bad;
            if (!uanlSubdualNotedSeparately()) ++bad;
            if (uanlSubdualTemporaryPct() != 75) ++bad;
            if (uanlSubdualRealPct() != 25) ++bad;
            if (uanlSubdualExamplePoints() != 40) ++bad;
            if (uanlSubdualExampleReal() != 10) ++bad;
            if (!uanlSubdualSubduedWhenExceedsTotal()) ++bad;
            if (!uanlSubduedNoAttackExceptSelfDefense()) ++bad;
            if (!uanlSubduedMonsterWillNotAttackGroup()) ++bad;
            if (!uanlSubduedSubmitsSeeksEscape()) ++bad;
            if (!uanlSubduedTurnsIfPartyWeaker()) ++bad;
            if (!uanlSubdualLastsWhileUpperHand()) ++bad;
            if (!uanlSubdualSupercedesPublished()) ++bad;
            if (!uanlSubdualSupercedesDragonSubdual()) ++bad;
            if (!uanlVanqUsedByLawfulToSettle()) ++bad;
            if (!uanlVanqDuelOfHonor()) ++bad;
            if (!uanlVanqChallengeMustTakeUp()) ++bad;
            if (!uanlVanqIntelligentLanguageCapable()) ++bad;
            if (!uanlVanqMustCommunicateAndAgree()) ++bad;
            if (!uanlVanqCombatNormalHoldingBack()) ++bad;
            if (uanlVanqRealDamageQuarterPct() != 25) ++bad;
            if (!uanlVanqResortToRealAtRoundStart()) ++bad;
            if (!uanlVanqFullRealDamageNegates()) ++bad;
            if (!uanlVanqTemporaryLostIgnored()) ++bad;
            if (!uanlVanqPoisonedVorpalPerformReal()) ++bad;
            if (!uanlVanqDamageNotedSeparately()) ++bad;
            if (!uanlVanqLoserAtZeroHp()) ++bad;
            if (!uanlVanqDrawIfBothZeroSameRound()) ++bad;
            if (!uanlVanqWinnerDemandSingle()) ++bad;
            if (uanlVanqServiceExampleCount() != 4) ++bad;
            if (!uanlVanqItemWeaponArmorShield()) ++bad;
            if (uanlVanqTreasureGpPerHitDieOrLevel() != 1000) ++bad;
            if (!uanlVanqEnslaveOrSlayFreesDuty()) ++bad;
            if (!uanlVanqImprisonIfStated()) ++bad;
            if (!uanlVanqLawfulHonorBound()) ++bad;
            if (!uanlVanqGoodCannotPerformEvil()) ++bad;
            if (!uanlVanqNeutralHasChoice()) ++bad;
            if (!uanlVanqChaoticEvilNoConstraints()) ++bad;
            if (!uanlVanqGenerallyTwoCombatants()) ++bad;
            if (!uanlVanqMultipleAllSideToZero()) ++bad;
            if (!uanlVanqZeroDamageMayContinue()) ++bad;
            if (!uanlVanqPastZeroFullDamage()) ++bad;
            if (!uanlVanqMultipleZeroRetiresHonor()) ++bad;
            if (!uanlVanqMonksDruidsGarbleHead()) ++bad;
            if (!uanlVanqUsedToAdvanceLevelByCombat()) ++bad;
            if (!uanlVanqLawfulCommunitiesApprehend()) ++bad;
            if (!uanlDisarmFighterCavalierOnly()) ++bad;
            if (uanlDisarmWeaponCount() != 6) ++bad;
            if (uanlDisarmOrderKnife() != 1) ++bad;
            if (uanlDisarmOrderDagger() != 2) ++bad;
            if (uanlDisarmOrderHorsemanMace() != 3) ++bad;
            if (uanlDisarmOrderShortSword() != 4) ++bad;
            if (uanlDisarmOrderFootmanMace() != 5) ++bad;
            if (uanlDisarmOrderSword() != 6) ++bad;
            if (!uanlDisarmKhopeshDisarmsNormally()) ++bad;
            if (!uanlDisarmKhopeshIntentionalTheseRules()) ++bad;
            if (!uanlDisarmRequiresProficiency()) ++bad;
            if (!uanlDisarmOpponentListedWeapon()) ++bad;
            if (!uanlDisarmTwoHandedNeverAffected()) ++bad;
            if (!uanlDisarmInflictsNoDamage()) ++bad;
            if (!uanlDisarmHitThenSaveVsPetrification()) ++bad;
            if (!uanlDisarmSameLengthOrShorterOnly()) ++bad;
            if (!uanlDisarmExampleDaggerDisarmsKnife()) ++bad;
            if (!uanlDisarmExampleScimitarDisarmsMace()) ++bad;
            if (!uanlDisarmExampleDaggerNotShortSword()) ++bad;
            if (!uanlDisarmScimitarSeam()) ++bad;
            if (!uanlDisarmFallsAtFeetIfSameSize()) ++bad;
            if (uanlDisarmFallsMinFeet() != 1) ++bad;
            if (uanlDisarmFallsMaxFeet() != 10) ++bad;
            if (uanlDisarmRecoverOptionsCount() != 3) ++bad;
            if (!uanlDisarmRecommendedWithSystemTwo()) ++bad;
            if (uanlPartItemTotal() != 7) ++bad;
            if (uanlPartCleanCount() != 2) ++bad;
            if (uanlPartFlaggedCount() != 5) ++bad;
            if (uanlPartGarbledCount() != 0) ++bad;
            if (uanlSubdualTemporaryPct()
                + uanlSubdualRealPct() != 100)
                ++bad;
            if (uanlVanqRealDamageQuarterPct()
                != uanlSubdualRealPct()) ++bad;
            if (uanlVanqTreasureGpPerHitDieOrLevel()
                * 4 != 4000) ++bad;
            if (uanlDisarmOrderDagger()
                <= uanlDisarmOrderKnife()) ++bad;
            if (uanlDisarmOrderShortSword()
                <= uanlDisarmOrderDagger()) ++bad;
            if (uanlDisarmFallsMinFeet()
                >= uanlDisarmFallsMaxFeet()) ++bad;
            if (uanlDisarmWeaponCount()
                != uanlDisarmOrderSword()) ++bad;
            if (subdualTemporaryPct()
                != uanlSubdualTemporaryPct()
                || subdualRealPct()
                != uanlSubdualRealPct()) ++bad;
            if (subdualRealDamage(
                uanlSubdualExamplePoints())
                != uanlSubdualExampleReal()) ++bad;
            if (!uaqSysTwoOutgrowthMorePowerful())
                ++bad;
        printf("R390 UA non-lethal combat pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R390 audit')



s = rd(RT)
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
assert s.count('audit: bad ') == 317, 'd census 317'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uaappendr.h"'
) == 1, 'd new include'
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
    'R390 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R390 note: the UA',
    'non-lethal combat appendix R',
    'round - the pp. 109-110',
    'stretch, seven items pin: two',
    'fully clean (the subdual',
    'eligibility, the subdual',
    'damage accounting) plus five',
    'mechanics-clean with flagged',
    'holes (the subdual supercedes',
    'sentence, the vanquishing',
    'loser sentence, the chaotic',
    'constraints line, the',
    'monks-druids garble head,',
    'the disarming scimitar seam);',
    'nothing fully garbles - the',
    'item AMENDED, the prose',
    'pinned, the R159 overlap',
    'reconciled (the DMG knockout',
    'stays the engine default,',
    'the UA subdual pins as its',
    'own data layer), the R389',
    'seam the System II',
    'weaponless layer; the census',
    '316 -> 317',
])
print(NOTE)
print('commit: R390: the UA')
print('non-lethal combat appendix')
print('R pin round (census 317)')

