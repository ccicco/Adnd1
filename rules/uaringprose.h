// ===========================================================================
// Adnd1 - rules/uaringprose.h
// The UA TREASURE (RINGS) prose
// pins, R378: the six clean
// new-ring descriptions
// (pp. 92-94) - animal
// friendship, anything,
// blinking, jumping, mind
// shielding, truth. The seven
// garbled descriptions
// (boccob's save list,
// chameleon's detection tail,
// clumsiness' power table,
// faerie's fraction cells,
// ram's adjustment tail,
// shocking grasp's opening,
// sustenance's reattune) await
// the PDF - the gap item
// stays open. The scrolls and
// skeleton seams ride in the
// regtest audit, not here.
namespace rules {

// ---- the ring of animal
// friendship ----
// Within 1" of neutral
// animals of animal
// intelligence: save versus
// spell - success flees,
// failure goes docile and
// follows.
inline int uarpAfRadiusIn()
    { return 1; }

inline bool uarpAfSaveIsVsSpell()
    { return true; }

inline bool uarpAfSaveSuccessFlees()
    { return true; }

inline bool uarpAfSaveFailDocile()
    { return true; }

// The dweomer functions at
// 6th level: 12 hit dice of
// animals; a charge buys
// guard-and-protect.
inline int uarpAfDweomerLevel()
    { return 6; }

inline int uarpAfMaxHd()
    { return 12; }

inline int uarpAfGuardCostCharges()
    { return 1; }

inline int uarpAfChargesTypical()
    { return 27; }

inline bool uarpAfRechargeable()
    { return false; }

// A druid influences twice
// the hit dice; a ranger
// eighteen.
inline int uarpAfDruidMaxHd()
    { return 24; }

inline int uarpAfRangerMaxHd()
    { return 18; }

// ---- the anything ring ----
// Initially appears as a
// standard ring of warmth;
// three commanded functions
// from among the other
// standard sorts.
inline bool uarpAnyAppearsWarmth()
    { return true; }

inline int uarpAnyCommands()
    { return 3; }

// Operation-type functions
// give one operation; the
// rest last one day (24
// hours). Any commanded
// function never comes
// again.
inline bool uarpAnyOpTypeIsOneOperation()
    { return true; }

inline int uarpAnyEffectHours()
    { return 24; }

inline bool uarpAnyNeverReusable()
    { return true; }

// After three singular uses
// the ring turns to
// non-magical jewelry worth
// 100 to 600 gp.
inline bool uarpAnyBecomesJewelry()
    { return true; }

inline int uarpAnyJewelryLoGp()
    { return 100; }

inline int uarpAnyJewelryHiGp()
    { return 600; }

// ---- the ring of blinking ----
// The proper verbal command
// activates a blink spell
// effect for 6 rounds; the
// ring then rests 6 turns
// (1 hour) replenishing.
inline bool uarpBlinkIsBlinkSpell()
    { return true; }

inline int uarpBlinkActiveRounds()
    { return 6; }

inline int uarpBlinkRechargeTurns()
    { return 6; }

inline int uarpBlinkRechargeHours()
    { return 1; }

// The command word is
// usually engraved on the
// ring; anyone may speak it
// within 10 feet.
inline bool uarpBlinkWordEngraved()
    { return true; }

inline bool uarpBlinkAnyoneMaySpeak()
    { return true; }

inline int uarpBlinkActivationFeet()
    { return 10; }

// ---- the ring of jumping ----
// One segment to call forth:
// leap 30 feet ahead, or 10
// feet backwards or straight
// up, an arc of 2 feet per
// 10 feet traveled; four
// times per day.
inline int uarpJumpActivationSegs()
    { return 1; }

inline int uarpJumpAheadFeet()
    { return 30; }

inline int uarpJumpBackFeet()
    { return 10; }

inline int uarpJumpArcFeetPerTen()
    { return 2; }

inline int uarpJumpUsesPerDay()
    { return 4; }

// ---- the ring of mind
// shielding ----
// Fine gold workmanship; the
// wearer is immune to ESP,
// detect lie, know
// alignment, and telepathic
// reading of the mind.
inline int uarpMsImmuneCount()
    { return 4; }

inline bool uarpMsBlocksEsp()
    { return true; }

inline bool uarpMsBlocksDetectLie()
    { return true; }

inline bool uarpMsBlocksKnowAlignment()
    { return true; }

inline bool uarpMsBlocksTelepathy()
    { return true; }

// A psionic wearer gains a
// thought shield at no point
// cost; psionic attack damage
// at -2.
inline bool uarpMsThoughtShieldFree()
    { return true; }

inline int uarpMsPsionicAttackDmgAdj()
    { return -2; }

// Versus a psionic blast: +1
// on saves if not psionically
// endowed, -3 on damage if
// psionic.
inline int uarpMsBlastSaveNonPsionic()
    { return 1; }

inline int uarpMsBlastDmgPsionic()
    { return -3; }

// ---- the ring of truth ----
// Any lie told to the wearer
// is detectable; the wearer
// cannot lie - any attempt
// speaks the literal truth -
// and discerns the last
// prevarication; the liar's
// voice rises to falsetto.
inline bool uarpTruthLiesDetectable()
    { return true; }

inline bool uarpTruthWearerCannotLie()
    { return true; }

inline bool uarpTruthSpeaksLiteralTruth()
    { return true; }

inline bool uarpTruthDiscernsLastLie()
    { return true; }

inline bool uarpTruthFalsettoVoice()
    { return true; }

// Against falsehood-masking
// dweomers (undetectable lie,
// philter of glibness): no
// lie is noticed, and the
// wearer does not hear the
// dweomered person's voice.
inline bool uarpTruthDweomerBlocksNotice()
    { return true; }

inline bool uarpTruthDweomerSilencesVoice()
    { return true; }

// ---- the extract ledger ----
// Six of the thirteen
// descriptions pin; the
// seven garbled ones stay
// PDF-gated.
inline int uarpCleanCount()
    { return 6; }

inline int uarpGarbledCount()
    { return 7; }

inline int uarpTotalTypes()
    { return 13; }

}   // namespace rules

