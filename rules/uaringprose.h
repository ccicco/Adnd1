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
// sustenance's reattune) the
// R397 clean read filled -
// the gap item closed. The
// scrolls and
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

// ---- the ring of boccob (the R397
// clean read) ----
// An ornate ring that appears
// valuable but non-magical; even the
// strongest magical detection
// reveals nothing.
inline bool uarpBoccobAppearsNonMagical()
    { return true; }

inline bool uarpBoccobUndetectable()
    { return true; }

// A contacting magical device
// malfunctions and fails to affect
// its target.
inline bool uarpBoccobContactsDeviceFails()
    { return true; }

// A device failing its save versus
// the ring turns non-magical.
inline bool uarpBoccobFailedSaveNonMagical()
    { return true; }

// Each cancellation silences the
// ring 1-4 hours.
inline int uarpBoccobQuiescenceLoHours()
    { return 1; }

inline int uarpBoccobQuiescenceHiHours()
    { return 4; }

// Single-use items (a magic arrow, a
// javelin of lightning) are not
// cancelled, only their magic is
// blunted.
inline bool uarpBoccobSingleUseNotCancelled()
    { return true; }

// The immunity never prevents the
// normal damage of such an item.
inline bool uarpBoccobNormalDamageStill()
    { return true; }

// Item saves versus the
// cancellation: 1 automatic failure;
// 2 relics; 3 artifacts; 4 hand-held
// weapons; 5 rods and staves; 6 all
// other items; 7-20 any item saves.
inline int uarpBoccobSaveAutoFailRoll()
    { return 1; }

inline int uarpBoccobSaveRelicRoll()
    { return 2; }

inline int uarpBoccobSaveArtifactRoll()
    { return 3; }

inline int uarpBoccobSaveHandWeaponRoll()
    { return 4; }

inline int uarpBoccobSaveRodStaffRoll()
    { return 5; }

inline int uarpBoccobSaveOtherRoll()
    { return 6; }

inline int uarpBoccobSaveAnySavesLo()
    { return 7; }

inline int uarpBoccobSaveAnySavesHi()
    { return 20; }

// ---- the ring of chameleon power
// (the R397 clean read) ----
// Magical blending with the
// surroundings: 90% invisibility in
// foliage, against walls, and so
// forth.
inline int uarpChamInvisibilityPct()
    { return 90; }

// Amid creatures of intelligence 4
// or greater within 6", the wearer
// seems one of them; each turn of
// association carries a 5%
// cumulative detection chance.
inline int uarpChamAssociateIntMin()
    { return 4; }

inline int uarpChamAssociateRangeIn()
    { return 6; }

inline int uarpChamDetectPctPerTurn()
    { return 5; }

// The association never persists
// past 20 turns - the chance reaches
// 100%.
inline int uarpChamMaxAssociationTurns()
    { return 20; }

// Creatures of intelligence 16 or
// greater add their intelligence
// score to the base chance.
inline int uarpChamIntBonusMin()
    { return 16; }

// Creatures of intelligence 3 or
// lower detect the wearer
// instinctively within 1".
inline int uarpChamLowIntMax()
    { return 3; }

inline int uarpChamLowIntRangeIn()
    { return 1; }

// ---- the ring of clumsiness (the
// R397 clean read) ----
// A cursed ring radiating a
// disguising secondary dweomer; it
// takes effect only under stress -
// combat, stealth, delicate
// activity.
inline bool uarpClumDisguisesBanefulNature()
    { return true; }

inline bool uarpClumTriggersUnderStress()
    { return true; }

// The secondary powers roll d%:
// 01-10 free action, 11-20 feather
// falling, 21-35 invisibility, 36-50
// jumping, 51-60 swimming, 61-80
// warmth, 81-00 water walking.
inline int uarpClumSecondaryPowerCount()
    { return 7; }

inline int uarpClumFreeActionLo()
    { return 1; }

inline int uarpClumFreeActionHi()
    { return 10; }

inline int uarpClumFeatherFallLo()
    { return 11; }

inline int uarpClumFeatherFallHi()
    { return 20; }

inline int uarpClumInvisibilityLo()
    { return 21; }

inline int uarpClumInvisibilityHi()
    { return 35; }

inline int uarpClumJumpingLo()
    { return 36; }

inline int uarpClumJumpingHi()
    { return 50; }

inline int uarpClumSwimmingLo()
    { return 51; }

inline int uarpClumSwimmingHi()
    { return 60; }

inline int uarpClumWarmthLo()
    { return 61; }

inline int uarpClumWarmthHi()
    { return 80; }

inline int uarpClumWaterWalkLo()
    { return 81; }

inline int uarpClumWaterWalkHi()
    { return 100; }

// Dexterity drops to half normal,
// rounded down; stealth and
// precise-action chances halve the
// same way.
inline bool uarpClumDexHalvedDown()
    { return true; }

inline bool uarpClumStealthHalved()
    { return true; }

// Casting that handles a material or
// somatic component succeeds only on
// a save versus spell - else the
// spell is botched and annulled.
inline bool uarpClumComponentNeedsSave()
    { return true; }

// Only a dispel magic versus
// 12th-level magic removes the ring,
// destroying both dweomers.
inline bool uarpClumRemovalIsDispel()
    { return true; }

inline int uarpClumRemovalVsLevel()
    { return 12; }

inline bool uarpClumRemovalDestroysBoth()
    { return true; }

// ---- the ring of faerie (the R397
// clean read) ----
// Given by the grey elves to their
// closest associates and allies
// only; each ring aligns to evil
// (5%), good (75%), or neutrality
// (20%).
inline bool uarpFaerieGreyElfGift()
    { return true; }

inline int uarpFaerieEvilPct()
    { return 5; }

inline int uarpFaerieGoodPct()
    { return 75; }

inline int uarpFaerieNeutralPct()
    { return 20; }

// A ring of contrary alignment will
// not function.
inline bool uarpFaerieAlignmentMustMatch()
    { return true; }

// In woodlands the wearer is
// detectable only by creatures able
// to detect invisible objects.
inline bool uarpFaerieWoodlandHideInvisible()
    { return true; }

// Alone and not in metal armor, the
// wearer moves silently: a 01-67
// roll (66 and two-thirds percent)
// succeeds and grants surprise on
// 1-4 on a d6.
inline bool uarpFaerieSilenceNeedsAlone()
    { return true; }

inline bool uarpFaerieSilenceNoMetalArmor()
    { return true; }

inline int uarpFaerieSilentSuccessHi()
    { return 67; }

// A 68 or higher means the movement
// noise carries that many feet.
inline int uarpFaerieNoiseFeetMin()
    { return 68; }

inline int uarpFaerieSurpriseDieMin()
    { return 1; }

inline int uarpFaerieSurpriseDieMax()
    { return 4; }

// Infravision to 60 feet.
inline int uarpFaerieInfravisionFeet()
    { return 60; }

// Concealed doors noted 16 and
// two-thirds percent (1 on d6) in
// passing, 50% when actively
// searched.
inline int uarpFaerieConcealedPassDie()
    { return 1; }

inline int uarpFaerieConcealedSearchedPct()
    { return 50; }

// Secret doors found 33 and
// one-third percent (1-2 on d6) when
// actively searched.
inline int uarpFaerieSecretSearchedDieMin()
    { return 1; }

inline int uarpFaerieSecretSearchedDieMax()
    { return 2; }

// ---- the ring of the ram (the R397
// clean read) ----
// The ram-force strikes one target:
// 1-6 at 1 charge, 2-12 at 2, 3-18
// at 3 (the maximum); range 3".
inline int uarpRamDmgLoOneCharge()
    { return 1; }

inline int uarpRamDmgHiOneCharge()
    { return 6; }

inline int uarpRamDmgLoTwoCharges()
    { return 2; }

inline int uarpRamDmgHiTwoCharges()
    { return 12; }

inline int uarpRamDmgLoThreeCharges()
    { return 3; }

inline int uarpRamDmgHiThreeCharges()
    { return 18; }

inline int uarpRamMaxChargesPerAttack()
    { return 3; }

inline int uarpRamRangeIn()
    { return 3; }

// A failed save versus spell knocks
// the victim free - off walls,
// ladders, ledges.
inline bool uarpRamFailedSaveKnockedFree()
    { return true; }

// Save adjustments: smaller than
// man-sized -1, larger +2, Strength
// under 12 -1, Strength 18-20 +3,
// Strength over 20 +6, four or more
// legs +4, over 1,000 pounds +2, 2
// charges -1, 3 charges -2.
inline int uarpRamAdjSmaller()
    { return -1; }

inline int uarpRamAdjLarger()
    { return 2; }

inline int uarpRamAdjStrUnder12()
    { return -1; }

inline int uarpRamAdjStr18to20()
    { return 3; }

inline int uarpRamAdjStrOver20()
    { return 6; }

inline int uarpRamAdjFourLegs()
    { return 4; }

inline int uarpRamAdjOver1000Lbs()
    { return 2; }

inline int uarpRamAdjTwoCharges()
    { return -1; }

inline int uarpRamAdjThreeCharges()
    { return -2; }

// Doors open as an 18/00 Strength; 2
// charges as Strength 19, 3 as
// Strength 20; held or locked
// portals included.
inline int uarpRamDoorStrBase()
    { return 18; }

inline int uarpRamDoorStrTwoCharges()
    { return 19; }

inline int uarpRamDoorStrThreeCharges()
    { return 20; }

// Structural damage matches an
// actual battering ram, with double
// or triple damage at 2 or 3
// charges.
inline bool uarpRamStructuralAsBatteringRam()
    { return true; }

inline bool uarpRamStructuralDoubleTriple()
    { return true; }

// Magic items struck save versus
// crushing blow only at the full 3
// charges; non-magical items always
// save against the impact.
inline bool uarpRamItemsSaveOnlyAtThree()
    { return true; }

inline bool uarpRamItemsSaveVsCrushing()
    { return true; }

// Discovered with 6-60 charges;
// recharged by enchant an item plus
// Bigby's Clenched Fist.
inline int uarpRamChargesLo()
    { return 6; }

inline int uarpRamChargesHi()
    { return 60; }

inline bool uarpRamRechargeNeedsFist()
    { return true; }

// ---- the ring of shocking grasp
// (the R397 clean read) ----
// Only a faint, unidentifiable aura
// radiates; a successful touch
// attack with the ring hand delivers
// 7-14 (d8 + 6).
inline bool uarpShockFaintUnidentifiable()
    { return true; }

inline bool uarpShockNeedsTouchHit()
    { return true; }

inline int uarpShockDmgLo()
    { return 7; }

inline int uarpShockDmgHi()
    { return 14; }

inline int uarpShockDmgDieSides()
    { return 8; }

inline int uarpShockDmgPlus()
    { return 6; }

// After three discharges the ring
// goes inert for 1 turn.
inline int uarpShockDischargesBeforeRest()
    { return 3; }

inline int uarpShockRestTurns()
    { return 1; }

// ---- the ring of sustenance (the
// R397 clean read) ----
// Life-sustaining nourishment
// without food or drink; two hours
// of sleep give the benefit of
// eight.
inline bool uarpSustNoFoodOrDrink()
    { return true; }

inline int uarpSustSleepHours()
    { return 2; }

inline int uarpSustSleepBenefitHours()
    { return 8; }

// A full week of wearing attunes the
// ring; removal immediately drops
// the benefits and demands a fresh
// week.
inline int uarpSustWearWeeks()
    { return 1; }

inline bool uarpSustRemovalResets()
    { return true; }

inline int uarpSustReattuneWeeks()
    { return 1; }

// After any seven consecutive days
// of functioning the ring rests one
// week.
inline int uarpSustConsecutiveDays()
    { return 7; }

inline int uarpSustRestWeeks()
    { return 1; }
// ---- the extract ledger ----
// All thirteen descriptions
// pin - the R397 clean read
// filled the seven the
// extract garbled.
inline int uarpCleanCount()
    { return 13; }

inline int uarpGarbledCount()
    { return 0; }

inline int uarpTotalTypes()
    { return 13; }

}   // namespace rules

