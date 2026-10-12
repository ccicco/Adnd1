// ===========================================================================
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

