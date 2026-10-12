// ===========================================================================
// Adnd1 - rules/uawandprose.h
// The UA TREASURE (WANDS)
// prose pins, R380: the seven
// pinnable new-wand types
// (pp. 96-97) - five fully
// clean (anything, fireballs,
// flame extinguishing, ice
// storms, lightning bolts)
// plus two mechanics-clean
// with flagged holes
// (defoliation's opening
// sentence, metal command's
// dropped verb). The five
// garbled types (buckler,
// earth and stone, force,
// size alteration, steam and
// vapor) await the PDF - the
// gap item stays open. The
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
// sentence interleaves in the
// extract - the hole flagged;
// all charge mechanics read
// clean. Never wood - ivory
// or bone.
inline bool uawdDefOpeningHoleFlagged()
    { return true; }

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
// drops its verb in the
// extract - the hole flagged;
// all three charge functions
// read clean. Appears as a
// wand of metal and mineral
// detection; operational only
// in the hands of a dwarf or
// gnome.
inline bool uawdMcVerbHoleFlagged()
    { return true; }

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

// ---- the extract ledger ----
// Five fully clean, two
// mechanics-clean with
// flagged holes, five
// garbled - twelve types.
inline int uawdCleanCount()
    { return 5; }

inline int uawdFlaggedCount()
    { return 2; }

inline int uawdGarbledCount()
    { return 5; }

inline int uawdTotalTypes()
    { return 12; }

}   // namespace rules

