// ===========================================================================
// Adnd1 - rules/uaclericspells2.h
// The UA NEW CLERIC SPELLS (pp. 35-36) pins, R344: the 2nd-level
// spell descriptions - aid, detect life, dust devil, enthrall,
// holy symbol, messenger, withdraw, wyvern watch.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The R341 cleric table pin (rules/uaspelltables.h) is the name seam.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (established R343): the OCR prints 7
//     where 1 belongs in the stat cells. This round's five 7s all
//     decode as 1: aid duration "7 round + 1/level" = 1 round +
//     1/level; detect life casting time "7 round" = 1 round; holy
//     symbol casting time "7 turn" = 1 turn; messenger duration
//     "7 hour/level" = 1 hour/level and casting time "7 round" =
//     1 round. Every "Level: 2" cell prints clean - the family is
//     corroborated five times over.
//   - enthrall's area prints "90° radius" - the degree sign is the
//     OCR's foot mark; decoded as a 90-foot radius.
//   - the wyvern watch header prints "'Wyvern Watch" - a stray
//     curly apostrophe before the name; decoded as Wyvern Watch.
//   - holy symbol's "holy bol" garble = the tail of "holy symbol"
//     lost mid-word; decoded.
//   - messenger's "may be it nored" scramble = "may be ignored";
//     decoded.
//   - withdraw's interleaved example: the fragments "Thus; 5th
//     level experience, ... while but 6 segments of time for all
//     others" decode as the worked example - a 5th-level caster
//     passes 6 segments for all others (the cleric experiences 6
//     rounds). The formula: base 2 segments at 1st level, plus one
//     per level beyond (segments = level + 1; 2 + 4 = 6 at 5th).
//     The "(The DM must allow the caster 1 minute of real time
//     per segment to ponder some problem or question with which
//     the spell caster is confronted)" fragments decode likewise.
//   - the R341 table 2nd-column hole decodes: the "draw" fragment
//     at row 18 (R341 pinned it as a hole; it sorts between
//     Spiritual Hammer and Wyvern Watch) decodes as Withdraw -
//     position-forced by alphabetical continuity and corroborated
//     by this round's prose section. The three leading empty cells
//     include Aid's lost cell (aid sorts before Detect Charm and
//     this round's prose confirms aid as a UA 2nd-level cleric
//     spell) - noted, not row-resolved, pending the PDF.
//   - aid's stat components cell prints empty - a hole; the
//     material component survives in the prose (a tiny strip of
//     white cloth with a sticky substance such as tree sap on the
//     ends, plus the cleric's holy symbol) - pinned from the
//     prose, the stat cell flagged lost.
//   - messenger's range cell prints empty - a hole.
//
// OCR holes (the item stays open - the 3rd-7th levels pin in later
// rounds; these stay pending the PDF): the aid casting-time cell
// and stat components cell; the messenger range cell; the aid
// leading-empty row resolution; the withdraw scrambled column
// beyond the readable fragments.
// ===========================================================================

#pragma once

namespace rules {

// ---- aid (Necromantic - Conjuration), p. 35 ----
inline const char* uac2AidName()
    { return "Aid (Necromantic - Conjuration)"; }

// The recipient gains the benefit of a bless spell plus 1-8
// additional hit points.
inline int uac2AidBonusHpMin()
    { return 1; }

inline int uac2AidBonusHpMax()
    { return 8; }

inline bool uac2AidGrantsBless()
    { return true; }

// The bless lasts as long as the aid spell, as do the hit points;
// the recipient may exceed the full normal total.
inline bool uac2AidMayExceedNormalTotal()
    { return true; }

// Damage comes off the temporary points before regular ones.
inline bool uac2AidTempHpLostFirst()
    { return true; }

// Hit points bestowed by aid and then lost cannot be regained by
// curative magic.
inline bool uac2AidLostTempHpNotCurable()
    { return true; }

// The worked example: a 1st-level fighter with 8 hit points takes
// 2 damage, then receives aid for 6 additional hit points (12
// total, 6 temporary); hit for 7, one regular point and all six
// temporary points are lost.
inline int uac2AidExampleStartHp()
    { return 8; }

inline int uac2AidExampleFirstDamage()
    { return 2; }

inline int uac2AidExampleBonusHp()
    { return 6; }

inline int uac2AidExampleTotalHp()
    { return 12; }

inline int uac2AidExampleSecondDamage()
    { return 7; }

inline int uac2AidExampleRegularLost()
    { return 1; }

// The duration prints "7 round + 1/level" - the digit-garble
// family decodes 1 round + 1/level.
inline int uac2AidDurationBaseRounds()
    { return 1; }

inline int uac2AidDurationRoundsPerLevel()
    { return 1; }

inline int uac2AidRangeTouch()
    { return 0; }

// The material survives in the prose; the stat cell is lost.
inline bool uac2AidMaterialClothAndSap()
    { return true; }

inline bool uac2AidComponentsStatCellLost()
    { return true; }

inline bool uac2AidCastingTimeLost()
    { return true; }

// ---- detect life (Divination), p. 35 ----
inline const char* uac2DetectLifeName()
    { return "Detect Life (Divination)"; }

inline int uac2DetectLifeRangeFeet()
    { return 10; }

inline int uac2DetectLifeDurationRounds()
    { return 5; }

// The casting time prints "7 round" - the family decodes 1 round.
inline int uac2DetectLifeCastingTimeRounds()
    { return 1; }

inline bool uac2DetectLifeComponentsVSM()
    { return true; }

// Detects life in a feign death recipient, a coma, a deathlike
// trance or suspended animation; reveals an astral-traveling
// creature as alive; works on plants and plant creatures as well
// as animals.
inline bool uac2DetectLifeSeesFeignDeath()
    { return true; }

inline bool uac2DetectLifeSeesAstralTraveler()
    { return true; }

inline bool uac2DetectLifeWorksOnPlants()
    { return true; }

// Each inch of wood or stone barrier counts as 10 feet of open
// space; a metal barrier of any thickness ruins the spell.
inline int uac2DetectLifeInchBarrierFeet()
    { return 10; }

inline bool uac2DetectLifeMetalBarrierRuins()
    { return true; }

// Any mental protection (psionic or magical) likewise ruins the
// spell without anything being detected.
inline bool uac2DetectLifeMentalProtectionRuins()
    { return true; }

// Detects the first living creature along the line of sight
// within range, or the first creature crossing it before the
// duration expires.
inline bool uac2DetectLifeFirstAlongLineOfSight()
    { return true; }

// ---- dust devil (Conjuration/Summoning), p. 35-36 ----
inline const char* uac2DustDevilName()
    { return "Dust Devil (Conjuration/Summoning)"; }

inline int uac2DustDevilAc()
    { return 4; }

inline int uac2DustDevilHitDice()
    { return 2; }

inline int uac2DustDevilMvInches()
    { return 18; }

inline int uac2DustDevilDamageMin()
    { return 1; }

inline int uac2DustDevilDamageMax()
    { return 4; }

// Hit by normal weapons; magic weapons of any type cause double
// damage.
inline bool uac2DustDevilHitByNormalWeapons()
    { return true; }

inline bool uac2DustDevilMagicWeaponDoubleDamage()
    { return true; }

// A small whirlwind: 5 feet diameter at the base, 15 feet tall,
// 10 feet across at the top.
inline int uac2DustDevilBaseDiameterFeet()
    { return 5; }

inline int uac2DustDevilHeightFeet()
    { return 15; }

inline int uac2DustDevilTopDiameterFeet()
    { return 10; }

inline int uac2DustDevilRangeInches()
    { return 3; }

inline int uac2DustDevilCastingTimeRounds()
    { return 3; }

inline int uac2DustDevilDurationRoundsPerLevel()
    { return 1; }

inline bool uac2DustDevilComponentsVS()
    { return true; }

// Dismissed if ordered beyond 3" from the caster.
inline bool uac2DustDevilDispelBeyondRange()
    { return true; }

// Its winds hold a gas cloud or gaseous creature at bay or push
// it away (but cannot damage or dispel such a cloud); they put
// out torches, small campfires, exposed lanterns and other small
// open flames of non-magical origin.
inline bool uac2DustDevilWindsHoldGas()
    { return true; }

inline bool uac2DustDevilWindsExtinguishSmallFlames()
    { return true; }

// Skimming loose dust, sand or ash: disperses a cloud 30 feet in
// diameter; normal vision impossible; creatures blinded until
// one round after leaving.
inline int uac2DustDevilCloudDiameterFeet()
    { return 30; }

inline bool uac2DustDevilCloudBlinds()
    { return true; }

inline int uac2DustDevilBlindLingersRounds()
    { return 1; }

// Spellcasting inside the cloud or the devil is virtually
// impossible: a save versus spell keeps concentration even if the
// winds score no damage.
inline bool uac2DustDevilCastingRequiresSave()
    { return true; }

// Creatures native to the Elemental Plane of Air (even another
// of the same sort) can dismiss it at will from 3" or less.
inline bool uac2DustDevilAirNativeCanDismiss()
    { return true; }

// Creatures not native to the plane occupied by the caster are
// unaffected.
inline bool uac2DustDevilNonNativeUnaffected()
    { return true; }

// Automatically dispelled on contact with innate magic resistance
// - but only after it gets its chance to hit and do damage.
inline bool uac2DustDevilResistContactDispels()
    { return true; }

inline bool uac2DustDevilResistDispelsAfterItsAttack()
    { return true; }

// ---- enthrall (Enchantment/Charm), p. 36 ----
inline const char* uac2EnthrallName()
    { return "Enthrall (Enchantment/Charm)"; }

inline bool uac2EnthrallComponentsVS()
    { return true; }

inline int uac2EnthrallCastingTimeRounds()
    { return 1; }

inline int uac2EnthrallRangeInches()
    { return 3; }

// The area prints "90° radius" - the degree sign is the foot
// mark; decoded as a 90-foot radius.
inline int uac2EnthrallRadiusFeet()
    { return 90; }

// The audience must fully understand the caster's language.
inline bool uac2EnthrallRequiresUnderstanding()
    { return true; }

// Listeners of the same race save versus spell; those of a
// generally unfriendly different race save at +4.
inline bool uac2EnthrallSameRaceSaves()
    { return true; }

inline int uac2EnthrallUnfriendlyRaceSaveMod()
    { return 4; }

// Impossible to enthrall more than 4 levels or hit dice, or a
// wisdom score greater than 15.
inline int uac2EnthrallMaxLevelsOrHd()
    { return 4; }

inline int uac2EnthrallMaxWisdom()
    { return 15; }

// The caster must speak without interruption for a full round;
// the enchantment lasts while speaking, to a maximum of 6 turns.
inline bool uac2EnthrallRequiresFullRoundSpeech()
    { return true; }

inline int uac2EnthrallMaxDurationTurns()
    { return 6; }

// Failed save: the listeners view the cleric as charisma 21
// (loyalty base +70%, reaction adjustment +50%); they stand and
// listen but do not act on the words as if a suggestion had been
// cast.
inline int uac2EnthrallFailedSaveCharisma()
    { return 21; }

inline int uac2EnthrallLoyaltyBasePct()
    { return 70; }

inline int uac2EnthrallReactionAdjPct()
    { return 50; }

inline bool uac2EnthrallNotASuggestion()
    { return true; }

// Stopping the speech, any attack against the cleric (a
// successful hit or a spell cast), or the cleric casting a
// different spell or performing another action breaks it.
inline bool uac2EnthrallEndsIfCasterStopsOrActs()
    { return true; }

inline bool uac2EnthrallAttackOnClericCancels()
    { return true; }

// Successful save: the listener views the cleric as charisma 3,
// and may (50% chance) hoot and jeer, allowing a new saving throw
// for the others.
inline int uac2EnthrallMadeSaveCharisma()
    { return 3; }

inline int uac2EnthrallJeerChancePct()
    { return 50; }

inline bool uac2EnthrallJeerAllowsNewSaves()
    { return true; }

// Preaching a religion or alignment opposed to the audience's:
// each offended listener gets a new save at +5.
inline int uac2EnthrallOffendedSaveMod()
    { return 5; }

// ---- holy symbol (Conjuration/Summoning), p. 36 ----
inline const char* uac2HolySymbolName()
    { return "Holy Symbol (Conjuration/Summoning)"; }

inline bool uac2HolySymbolComponentsVSM()
    { return true; }

// The casting time prints "7 turn" - the family decodes 1 turn.
inline int uac2HolySymbolCastingTimeTurns()
    { return 1; }

// Prepares a holy symbol or creates a replacement for a lost or
// damaged one.
inline bool uac2HolySymbolCreatesOrReplaces()
    { return true; }

// The symbol-to-be IS the material component (obviously not
// consumed); it must be crafted of appropriate material per the
// religion and of proper shape and design - not just any item.
inline bool uac2HolySymbolMaterialIsTheSymbol()
    { return true; }

inline bool uac2HolySymbolMustBeCrafted()
    { return true; }

// A cleric may possess two holy symbols at one time; the spell
// can create the spare.
inline int uac2HolySymbolMaxPossessed()
    { return 2; }

// No cleric can create a holy symbol of a religion or deity
// other than the one worshipped.
inline bool uac2HolySymbolOnlyOwnReligion()
    { return true; }

// A good or evil cleric's symbol radiates a faint aura of good
// or evil but is not magical per se; a neutral cleric's symbol
// has no such aura.
inline bool uac2HolySymbolRadiatesAlignmentAura()
    { return true; }

inline bool uac2HolySymbolNeutralNoAura()
    { return true; }

// ---- messenger (Enchantment/Charm), p. 36 ----
inline const char* uac2MessengerName()
    { return "Messenger (Enchantment/Charm)"; }

inline bool uac2MessengerComponentsVSM()
    { return true; }

// Calls a small (size S) creature of at least animal
// intelligence; no "giant" types; nothing of intelligence 4 or
// higher, or low intelligence or better.
inline bool uac2MessengerRequiresSizeS()
    { return true; }

inline bool uac2MessengerExcludesGiantTypes()
    { return true; }

inline int uac2MessengerMaxIntelligence()
    { return 3; }

// If the creature is within range, the cleric calls it with food
// as a lure; a successful save means the spell fails.
inline bool uac2MessengerLureIsFood()
    { return true; }

inline bool uac2MessengerSaveNegates()
    { return true; }

// The cleric communicates crudely - go to a place, with simple
// directions; a small item or note can be attached; the animal
// waits at the location until the duration ends.
inline bool uac2MessengerSimpleDirectionsOnly()
    { return true; }

inline bool uac2MessengerCanCarryNote()
    { return true; }

inline bool uac2MessengerWaitsUntilDurationEnds()
    { return true; }

// A recipient not in small animal or bird form may be ignored;
// when the duration expires the animal returns to normal
// activities; the receiver gains no communication ability.
inline bool uac2MessengerRecipientMayIgnore()
    { return true; }

inline bool uac2MessengerReceiverGainsNothing()
    { return true; }

// The duration prints "7 hour/level" and the casting time
// "7 round" - the family decodes 1 hour/level and 1 round.
inline int uac2MessengerDurationHoursPerLevel()
    { return 1; }

inline int uac2MessengerCastingTimeRounds()
    { return 1; }

// The range cell prints empty - a hole.
inline bool uac2MessengerRangeLost()
    { return true; }

// ---- withdraw (Alteration), p. 36 ----
inline const char* uac2WithdrawName()
    { return "Withdraw (Alteration)"; }

inline bool uac2WithdrawComponentsVSM()
    { return true; }

inline int uac2WithdrawCastingTimeSegments()
    { return 3; }

inline int uac2WithdrawRangeZero()
    { return 0; }

// While but 1 segment passes for those unaffected, the cleric
// spends 1 round in contemplation.
inline bool uac2WithdrawTimeRatioSegmentToRound()
    { return true; }

// Base duration 2 segments (2 rounds from the cleric's point of
// view), plus 1 increment per level of experience - the 5th-level
// example passes 6 segments for all others.
inline int uac2WithdrawBaseSegments()
    { return 2; }

inline int uac2WithdrawSegmentsPerLevel()
    { return 1; }

inline int uac2WithdrawSegmentsForLevel(int level) {
    if (level < 1) level = 1;
    return 1 + level;
}

// The DM must allow 1 minute of real time per segment to ponder
// some problem or question.
inline int uac2WithdrawRealMinutesPerSegment()
    { return 1; }

// Permitted acts only: an augury spell, any curing or healing
// spells, or any informational spells - and only on the cleric
// himself; casting any of them otherwise ends the withdraw.
inline bool uac2WithdrawPermitsAuguryCuringInfo()
    { return true; }

inline bool uac2WithdrawSpellsOnlyOnSelf()
    { return true; }

inline bool uac2WithdrawOtherCastingEndsIt()
    { return true; }

// No walking, running, invisibility or other actions beyond
// thinking, reading and the like; the cleric can be affected by
// others' actions; any attack on the cleric that succeeds breaks
// the spell.
inline bool uac2WithdrawNoPhysicalActions()
    { return true; }

inline bool uac2WithdrawAttackBreaksIt()
    { return true; }

// The R341 table's "draw" fragment (row 18) decodes as this
// spell - position-forced between Spiritual Hammer and Wyvern
// Watch, corroborated by the prose (see the JUDGMENTs).
inline bool uac2WithdrawDrawHoleDecoded()
    { return true; }

// The R341 2nd-column leading empties include aid's lost cell -
// noted, not row-resolved, pending the PDF.
inline bool uac2AidLeadingEmptyNoted()
    { return true; }

// ---- wyvern watch (Evocation), p. 36 ----
inline const char* uac2WyvernWatchName()
    { return "Wyvern Watch (Evocation)"; }

inline bool uac2WyvernWatchComponentsVSM()
    { return true; }

inline int uac2WyvernWatchRangeInches()
    { return 3; }

inline int uac2WyvernWatchCastingTimeSegments()
    { return 5; }

inline int uac2WyvernWatchDurationHours()
    { return 8; }

// The area prints a 1" diameter sphere.
inline int uac2WyvernWatchSphereDiameterInches()
    { return 1; }

// The insubstantial haze vaguely resembles a wyvern; typically
// guards an area against intrusion; any creature within 1" is
// subject to attack from the spell force.
inline bool uac2WyvernWatchGuardsArea()
    { return true; }

inline int uac2WyvernWatchTriggerRangeInches()
    { return 1; }

// Save versus spell or stand paralyzed 1 round per level of the
// caster, until freed by the caster, a dispel magic or a remove
// paralysis.
inline int uac2WyvernWatchParalysisRoundsPerLevel()
    { return 1; }

inline bool uac2WyvernWatchFreeDispelOrRemoveParalysis()
    { return true; }

// A successful save means the target was missed and the spell
// remains; once a target is struck the paralysis takes effect and
// the force dissipates; it also dissipates after 8 hours with no
// intruder struck.
inline bool uac2WyvernWatchSaveMeansMissed()
    { return true; }

inline bool uac2WyvernWatchStrikeDissipates()
    { return true; }

inline bool uac2WyvernWatchDissipatesAfterDuration()
    { return true; }

// Detection before entering: 90% in bright light, 30% in
// twilight, 0% in darkness.
inline int uac2WyvernWatchDetectBrightPct()
    { return 90; }

inline int uac2WyvernWatchDetectTwilightPct()
    { return 30; }

inline int uac2WyvernWatchDetectDarknessPct()
    { return 0; }

inline bool uac2WyvernWatchMaterialHolySymbol()
    { return true; }

}   // namespace rules
