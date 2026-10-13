// ===========================================================================
// Adnd1 - rules/uawandprose.h
// The UA TREASURE (WANDS)
// prose pins, R380: the seven
// pinnable new-wand types
// (pp. 96-97) - five fully
// clean (anything, fireballs,
// flame extinguishing, ice
// storms, lightning bolts)
// plus two whose holes
// (defoliation's opening
// sentence, metal command's
// dropped verb) and five
// garbled types (buckler,
// earth and stone, force,
// size alteration, steam and
// vapor) the R397 clean read
// filled - the gap item
// closed. The
// rods and skeleton seams
// ride in the regtest audit,
// not here.
namespace rules {

// ---- the anything wand ----
// Performs as an ordinary
// wand of wonder, with no
// more than 50 usages.
inline bool uawdAnyIsWonderLike()
    { return true; }

inline int uawdAnyMaxUsages()
    { return 50; }

// Upon command it performs as
// any other known wand, but
// each kind only once - a
// repeated command has no
// effect.
inline bool uawdAnyDuplicatesAnyKnownWand()
    { return true; }

inline bool uawdAnyEachKindOnce()
    { return true; }

inline bool uawdAnyRepeatCommandInert()
    { return true; }

// After three such demands,
// successful or not, the wand
// is totally drained and
// useless; it cannot be
// recharged.
inline int uawdAnyDrainDemands()
    { return 3; }

inline bool uawdAnyDrainCountsFailed()
    { return true; }

inline bool uawdAnyRechargeable()
    { return false; }

// ---- the wand of fireballs
// ----
// Casts fireball as a
// magic-user of 6th level; 1
// segment to activate, 1
// segment to loose the
// fireball.
inline int uawdFbCasterLevel()
    { return 6; }

inline int uawdFbActivateSegs()
    { return 1; }

inline int uawdFbDischargeSegs()
    { return 1; }

// Damage 6-36 (6d6), save for
// half; recharge by a
// magic-user of 8th or higher.
inline int uawdFbDmgDice()
    { return 6; }

inline int uawdFbDmgLo()
    { return 6; }

inline int uawdFbDmgHi()
    { return 36; }

inline bool uawdFbSaveForHalf()
    { return true; }

inline int uawdFbRechargeMuLevel()
    { return 8; }

// ---- the wand of flame
// extinguishing ----
// Normal fires: no charges -
// up to a bonfire or hearth
// fire, four to six billets
// burning hotly.
inline bool uawdFxNormalFree()
    { return true; }

inline int uawdFxNormalBilletsLo()
    { return 4; }

inline int uawdFxNormalBilletsHi()
    { return 6; }

// Large normal fires - a
// gallon or more of flaming
// oil, demon or devil fire,
// flame tongue, burning hands
// - cost 1 charge; continual
// magical flames suppress 6
// rounds then flare up again.
inline int uawdFxLargeNormalCharges()
    { return 1; }

inline int uawdFxOilGallonMin()
    { return 1; }

inline int uawdFxSuppressionRounds()
    { return 6; }

// Large magical fires -
// fireball, flame strike,
// wall of fire - cost 2
// charges.
inline int uawdFxLargeMagicalCharges()
    { return 2; }

// One charge against a fire
// creature (a fire elemental)
// inflicts 6-36 (6d6).
inline int uawdFxCreatureCharges()
    { return 1; }

inline int uawdFxCreatureDmgDice()
    { return 6; }

inline int uawdFxCreatureDmgLo()
    { return 6; }

inline int uawdFxCreatureDmgHi()
    { return 36; }

// ---- the wand of ice storms
// ----
// Ice storm as a magic-user
// of 7th level; hail or sleet
// forms; 1 segment to
// activate, 1 segment for the
// dweomer to emerge; recharge
// by a magic-user of 9th or
// higher.
inline int uawdIceCasterLevel()
    { return 7; }

inline int uawdIceFormsCount()
    { return 2; }

inline int uawdIceActivateSegs()
    { return 1; }

inline int uawdIceEmergeSegs()
    { return 1; }

inline int uawdIceRechargeMuLevel()
    { return 9; }

// ---- the wand of lightning
// bolts ----
// Lightning bolt as a
// magic-user of 6th level;
// forked or single stroke;
// 1 segment to activate, 1
// segment to discharge;
// recharge by a magic-user of
// 8th or higher.
inline int uawdLbCasterLevel()
    { return 6; }

inline bool uawdLbForkedOrSingle()
    { return true; }

inline int uawdLbDmgDice()
    { return 6; }

inline int uawdLbDmgLo()
    { return 6; }

inline int uawdLbDmgHi()
    { return 36; }

inline bool uawdLbSaveForHalf()
    { return true; }

inline int uawdLbActivateSegs()
    { return 1; }

inline int uawdLbDischargeSegs()
    { return 1; }

inline int uawdLbRechargeMuLevel()
    { return 8; }

// ---- the wand of
// defoliation ----
// The opening construction
// sentence reads clean in
// the R397 PDF pass: the
// wand is never constructed
// of wood - ivory or bone
// is the major component.
inline bool uawdDefNeverWood()
    { return true; }

inline bool uawdDefIvoryOrBone()
    { return true; }

inline bool uawdDefOpeningHoleFlagged()
    { return false; }

// One charge: all chlorophyll
// in a 3" radius destroyed -
// leaves turn autumnal and
// drop, grass browns.
inline int uawdDefChlorophyllCharges()
    { return 1; }

inline int uawdDefChlorophyllRadiusIn()
    { return 3; }

// Two charges: normal plant
// life in the 3" radius
// withers and dies; sentient
// and non-normal plants
// suffer 1-6 (1d6) instead.
inline int uawdDefWitherCharges()
    { return 2; }

inline int uawdDefWitherRadiusIn()
    { return 3; }

inline int uawdDefSentientDmgLo()
    { return 1; }

inline int uawdDefSentientDmgHi()
    { return 6; }

// The cone option: 3" length,
// 1" diameter at the far
// point; sentient and
// non-normal plants there
// suffer 6-36 (6d6), save
// versus rods staves wands
// for half (3d6).
inline int uawdDefConeLengthIn()
    { return 3; }

inline int uawdDefConeFarDiamIn()
    { return 1; }

inline int uawdDefConeDmgDice()
    { return 6; }

inline int uawdDefConeDmgLo()
    { return 6; }

inline int uawdDefConeDmgHi()
    { return 36; }

inline bool uawdDefConeSaveForHalf()
    { return true; }

inline int uawdDefConeHalfDice()
    { return 3; }

// ---- the wand of metal
// command ----
// The transmutation sentence
// reads clean in the R397
// PDF pass: in the hands of
// a dwarf or gnome its
// exceptional powers become
// operational. Appears as a
// wand of metal and mineral
// detection.
inline bool uawdMcPowersOperational()
    { return true; }

inline bool uawdMcVerbHoleFlagged()
    { return false; }

inline bool uawdMcAppearsDetection()
    { return true; }

inline bool uawdMcDwarfGnomeOnly()
    { return true; }

// One charge: gold to lead or
// lead to gold, range 3", 1-6
// pounds (10-60 gp weight).
inline int uawdMcTransmuteCharges()
    { return 1; }

inline int uawdMcTransmuteRangeIn()
    { return 3; }

inline int uawdMcTransmuteLbsLo()
    { return 1; }

inline int uawdMcTransmuteLbsHi()
    { return 6; }

inline int uawdMcTransmuteGpLo()
    { return 10; }

inline int uawdMcTransmuteGpHi()
    { return 60; }

// Two charges: heat metal as
// the druid spell, range 3",
// a single 3-foot diameter
// target area, up to 600 gp
// weight of metal.
inline int uawdMcHeatCharges()
    { return 2; }

inline int uawdMcHeatRangeIn()
    { return 3; }

inline int uawdMcHeatAreaDiamFt()
    { return 3; }

inline int uawdMcHeatMaxGp()
    { return 600; }

// Three charges: crystalbrittle,
// glassee, or glassteel as an
// 18th-level magic-user.
inline int uawdMcSpellCharges()
    { return 3; }

inline int uawdMcSpellCount()
    { return 3; }

inline int uawdMcSpellCasterLevel()
    { return 18; }

// ---- the buckler wand (the R397
// clean read) ----
// A shortish, thick wand about one
// and a half feet long; an
// exceptionally sharp point at one
// end, the trigger mechanism at the
// blunt other end.
inline int uawdBuckLengthTenthsFt()
    { return 15; }

inline bool uawdBuckSharpTipOneEnd()
    { return true; }

inline bool uawdBuckTriggerOtherEnd()
    { return true; }

// Usable by any character except a
// cleric; activation takes a single
// segment.
inline bool uawdBuckBlocksCleric()
    { return true; }

inline int uawdBuckActivateSegs()
    { return 1; }

// Grasped thick end, trigger
// pressed: the tip equals a dagger
// +1, the shaft a buckler +1 shield;
// the whole a spiked buckler +1.
inline bool uawdBuckTipDaggerPlusOne()
    { return true; }

inline bool uawdBuckShaftBucklerPlusOne()
    { return true; }

inline bool uawdBuckWholeSpikedPlusOne()
    { return true; }

// Magic-users may employ it, but no
// spells may be cast while it is in
// buckler form unless the caster is
// multi-classed with fighter and
// magic-user abilities.
inline bool uawdBuckMuMayEmploy()
    { return true; }

inline bool uawdBuckMuNoSpellsInForm()
    { return true; }

inline bool uawdBuckMulticlassException()
    { return true; }

// A thief employing it cannot climb
// walls or use other hand-requiring
// abilities while holding the
// device.
inline bool uawdBuckThiefNoClimbing()
    { return true; }

// ---- the wand of earth and stone
// (the R397 clean read) ----
// A shortish mineral-tipped wand:
// dig costs a half charge, passwall
// 1, move earth 2.
inline int uawdEarthDigCostTenths()
    { return 5; }

inline int uawdEarthPasswallCharges()
    { return 1; }

inline int uawdEarthMoveEarthCharges()
    { return 2; }

// Half of these wands (the
// higher-valued) add transmute mud
// to rock and transmute rock to mud,
// 1 charge each.
inline int uawdEarthPctWithExtras()
    { return 50; }

inline bool uawdEarthExtrasAreHigherValued()
    { return true; }

inline int uawdEarthExtraPowerCount()
    { return 2; }

inline int uawdEarthMudToRockCharges()
    { return 1; }

inline int uawdEarthRockToMudCharges()
    { return 1; }

// ---- the wand of force (the R397
// clean read) ----
// A tri-function device; the third
// demands operator knowledge.
inline int uawdForceFunctionCount()
    { return 3; }

// First: a nearly invisible
// blue-white shaft of energy, 4 feet
// long, equal to a +5 bastard sword;
// 1 charge per turn.
inline int uawdForceShaftFeet()
    { return 4; }

inline bool uawdForceShaftPlusFive()
    { return true; }

inline bool uawdForceShaftIsBastard()
    { return true; }

inline int uawdForceShaftChargesPerTurn()
    { return 1; }

// Second: a wall of force as a
// 10th-level magic-user; 1 charge
// per wall, a single usage per
// round.
inline int uawdForceWallCasterLevel()
    { return 10; }

inline int uawdForceWallCharges()
    { return 1; }

inline bool uawdForceWallOncePerRound()
    { return true; }

// Third: a Bigby's Forceful Hand
// plane; the user must be a
// magic-user with a Bigby's Hand or
// Fist spell recorded in the books;
// half a charge per round.
inline bool uawdForceHandNeedsMu()
    { return true; }

inline bool uawdForceHandNeedsSpellRecorded()
    { return true; }

inline int uawdForceHandCostTenths()
    { return 5; }

// Fighters of all types use the
// first and second functions;
// recharge by a magic-user of 16th
// or higher.
inline bool uawdForceFightersUseFirstTwo()
    { return true; }

inline int uawdForceRechargeMuLevel()
    { return 16; }

// Touching a Bigby's Hand or Fist, a
// Mordenkainen's Sword, or a wall of
// force disintegrates the
// manifestation and absorbs one
// charge.
inline bool uawdForceTouchDisintegrates()
    { return true; }

inline int uawdForceTouchKinds()
    { return 3; }

inline bool uawdForceTouchAbsorbsCharge()
    { return true; }

// ---- the wand of size alteration
// (the R397 clean read) ----
// Any single creature enlarges or
// diminishes by half; strength and
// power scale proportionally for
// humanoids - 9 feet matches a hill
// giant's Strength 19, 13 feet a
// fire giant's 22.
inline int uawdSizeChangePct()
    { return 50; }

inline int uawdSizeHillGiantFeet()
    { return 9; }

inline int uawdSizeHillGiantStr()
    { return 19; }

inline int uawdSizeFireGiantFeet()
    { return 13; }

inline int uawdSizeFireGiantStr()
    { return 22; }

// Range 1"; the target and all it
// wears or carries are affected
// unless the save succeeds - a
// willing target forgoes the save.
inline int uawdSizeRangeIn()
    { return 1; }

inline bool uawdSizeGearAffected()
    { return true; }

inline bool uawdSizeWillingForgoesSave()
    { return true; }

// A dispel magic removal demands a
// system shock roll; the possessor
// may cancel the effect at will
// before it expires.
inline bool uawdSizeDispelNeedsShock()
    { return true; }

inline bool uawdSizePossessorMayCancel()
    { return true; }

// Each usage expends 1 charge; the
// cancellation is free; recharge by
// a magic-user of 12th or higher.
inline int uawdSizeChargesPerUse()
    { return 1; }

inline bool uawdSizeCancellationFree()
    { return true; }

inline int uawdSizeRechargeMuLevel()
    { return 12; }

// ---- the wand of steam and vapor
// (the R397 clean read) ----
// Two functions, 1 charge each.
inline int uawdSteamCharges()
    { return 1; }

// STEAM: in one segment a jet of
// superheated steam, a cone of 1" by
// 3" by 5"; 6-36 (6d6) the first
// round, 4d6 the second, 2d6 the
// third and last; saves apply for
// half.
inline int uawdSteamActivateSegs()
    { return 1; }

inline int uawdSteamConeLoIn()
    { return 1; }

inline int uawdSteamConeMidIn()
    { return 3; }

inline int uawdSteamConeHiIn()
    { return 5; }

inline int uawdSteamRound1Dice()
    { return 6; }

inline int uawdSteamRound2Dice()
    { return 4; }

inline int uawdSteamRound3Dice()
    { return 2; }

inline bool uawdSteamSaveForHalf()
    { return true; }

// Fire-dwelling or fire-using
// creatures are unharmed - unless
// dampness harms them.
inline bool uawdSteamFireCreaturesImmune()
    { return true; }

inline bool uawdSteamDampnessException()
    { return true; }

// VAPOR: in one segment billows of
// warm steamy vapor, a fog cloud of
// 4" depth, 6" height, 8" breadth;
// it persists 6 rounds, stationary
// unless winds move it.
inline int uawdVaporCharges()
    { return 1; }

inline int uawdVaporActivateSegs()
    { return 1; }

inline int uawdVaporDepthIn()
    { return 4; }

inline int uawdVaporHeightIn()
    { return 6; }

inline int uawdVaporBreadthIn()
    { return 8; }

inline int uawdVaporRounds()
    { return 6; }

inline bool uawdVaporStationaryUnlessWinds()
    { return true; }

// Cold-using creatures inside suffer
// 1 point per round; cold-dwelling
// creatures take twice that.
inline int uawdVaporColdUserDmg()
    { return 1; }

inline int uawdVaporColdDwellerDmg()
    { return 2; }
// ---- the extract ledger ----
// All twelve types pin - the
// R397 clean read filled the
// two flagged holes and the
// five the extract garbled.
inline int uawdCleanCount()
    { return 12; }

inline int uawdFlaggedCount()
    { return 0; }

inline int uawdGarbledCount()
    { return 0; }

inline int uawdTotalTypes()
    { return 12; }

}   // namespace rules

