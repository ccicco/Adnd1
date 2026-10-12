// ==========================================================================
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

