// ===========================================================================
// Adnd1 - rules/uailspells2.h
// The UA NEW ILLUSIONIST SPELLS (pp. 67-68) pins,
// R363: the 2nd-level spell descriptions - read
// magic, spook, alter self and fascinate, plus the
// ultravision and wind reprints with their illusion-
// ist stat blocks.
//
// Pin-era pattern (R322): pinned data only - no
// engine site exists.
//
// JUDGMENTs (the decode method):
//   - the printed section carries read magic and
//     spook under a 2ND LEVEL running header: the
//     read magic level cell never prints (the stat
//     block scrambles into V, and M fragments) - the
//     level pins from the header, flagged pending the
//     PDF; the spook level cell prints the digit-
//     garble 7 - the family decodes the 2 (the header
//     corroborates), flagged.
//   - the item list (the R322 index) names phantom
//     armor, read magic and spook at 2nd and delude
//     and wraithform there as well; the print places
//     phantom armor at 1st (a clean Level: 1 cell)
//     and delude and wraithform in the third-level
//     section - the print wins, the divergence
//     flagged in the R363 note; delude and wraithform
//     pin with the third level in a later round.
//   - the alter self components cell garbles the
//     sign (V, $) - the V, S pin from the pattern;
//     the maneuverability minimum class is lost in a
//     mid-sentence cut - a hole.
//   - the fascinate stat block interleaves (the
//     casting 2 segments scrambles) and the request
//     sentence garbles - the +2 to +6 dangerous-
//     request ladder pins from the fragments,
//     flagged pending the PDF.
//   - ultravision and wind are reprints of PHB magic-
//     user spells with illusionist stat blocks -
//     pinned small (the ultravision version seam-
//     checks the R359 MU pin); the wind name header
//     garbles and the prose reads as the whispering
//     wind throughout.
//   - the R342 IL table seam: the readable 2nd column
//     prints four PHB names - none of the new names
//     seam-checks, asserted in the audit.
// ===========================================================================

#pragma once

namespace rules {

// ---- read magic (Divination), reversible ----
inline const char* uail2ReadName()
    { return "Read Magic (Divination)"; }

inline bool uail2ReadReversible()
    { return true; }

// The stat block scrambles - the level cell never
// prints; the components print as bare V, and M
// fragments.
inline bool uail2ReadStatBlockScrambled()
    { return true; }

inline bool uail2ReadComponentsVM()
    { return true; }

inline bool uail2ReadLevelCellLost()
    { return true; }

// The level pins from the printed 2ND LEVEL section
// header - flagged pending the PDF.
inline int uail2ReadLevel()
    { return 2; }

inline bool uail2ReadLevelFromSectionHeader()
    { return true; }

// The casting cell prints 7 segment - the family
// decodes the 1 segment.
inline int uail2ReadCastingTimeSegments()
    { return 1; }

inline bool uail2ReadCastingGarbleDecoded()
    { return true; }

// The duration prints 2 rounds per level.
inline int uail2ReadDurationRoundsPerLevel()
    { return 2; }

inline bool uail2ReadSaveNone()
    { return true; }

inline bool uail2ReadAoeSpecial()
    { return true; }

// The same as the 1st-level magic-user spell read
// magic, except that it applies only to spells
// usable by and used by illusionists, as well as to
// various other inscriptions written in
// illusionist-type magic script by illusionists.
inline bool uail2ReadSameAsMuFirstLevelReadMagic()
    { return true; }

inline bool uail2ReadIllusionistScriptOnly()
    { return true; }

// ---- spook (Illusion/Phantasm) ----
inline const char* uail2SpookName()
    { return "Spook (Illusion/Phantasm)"; }

// The level cell prints the digit-garble 7 - the
// family decodes the 2 (the printed 2ND LEVEL
// section header corroborates), flagged pending
// the PDF.
inline int uail2SpookLevel()
    { return 2; }

inline bool uail2SpookLevelGarbleDecoded()
    { return true; }

// The range cell prints empty - a hole pending the
// PDF.
inline bool uail2SpookRangeCellLost()
    { return true; }

// The casting cell prints 7 segment - the family
// decodes the 1 segment.
inline int uail2SpookCastingTimeSegments()
    { return 1; }

inline bool uail2SpookCastingGarbleDecoded()
    { return true; }

inline bool uail2SpookDurationSpecial()
    { return true; }

inline bool uail2SpookSaveNegates()
    { return true; }

// The area of effect: one creature within 1 inch of
// the illusionist.
inline int uail2SpookAoeOneCreatureWithinInches()
    { return 1; }

// The spell plays upon natural fears to cause the
// subject to perceive the spell caster as someone
// or something inimical; the illusionist advances
// threateningly without actually knowing what the
// subject perceives.
inline bool uail2SpookPlaysOnNaturalFears()
    { return true; }

inline bool uail2SpookSubjectPerceivesCasterInimical()
    { return true; }

inline bool uail2SpookAdvancesThreateningly()
    { return true; }

// On a failed save versus spell the creature reacts
// by rapidly fleeing, getting as much distance from
// the illusionist as possible - the effects as a
// wand of fear; items carried are not dropped.
inline bool uail2SpookFleesRapidlyOnFailedSave()
    { return true; }

inline bool uail2SpookEffectsAsWandOfFear()
    { return true; }

inline bool uail2SpookItemsNotDropped()
    { return true; }

// The caster does not actually pursue - a phantasm
// from the fleeing creature own mind does so.
inline bool uail2SpookPhantasmPursues()
    { return true; }

// Each round after the initial casting the creature
// is entitled to another saving throw, each at a
// cumulative +1 per round, until it successfully
// saves and the spell is broken.
inline int uail2SpookCumulativeSaveBonusPerRound()
    { return 1; }

// The spell functions only against creatures with
// intelligence of not less than 1.
inline int uail2SpookMinIntelligence()
    { return 1; }

// ---- alter self (Alteration/Illusion) ----
inline const char* uail2AlterName()
    { return "Alter Self (Alteration/Illusion)"; }

inline int uail2AlterLevel()
    { return 2; }

// The components cell garbles the sign (V, $) - the
// V, S pins from the stat pattern.
inline bool uail2AlterComponentsVS()
    { return true; }

inline bool uail2AlterComponentsCellGarbled()
    { return true; }

inline bool uail2AlterRangeZero()
    { return true; }

inline int uail2AlterCastingTimeSegments()
    { return 2; }

// The duration: 3-12 rounds plus 2 per level.
inline int uail2AlterDurationRoundsMin()
    { return 3; }

inline int uail2AlterDurationRoundsMax()
    { return 12; }

inline int uail2AlterDurationRoundsPerLevel()
    { return 2; }

inline bool uail2AlterSaveNone()
    { return true; }

inline bool uail2AlterAoeTheIllusionist()
    { return true; }

// The illusionist alters himself or herself in a
// manner similar to a change self spell - but with a
// quasi-real change.
inline bool uail2AlterSimilarToChangeSelf()
    { return true; }

inline bool uail2AlterQuasiRealChange()
    { return true; }

// Size can be altered by 50% of actual.
inline int uail2AlterSizeChangePct()
    { return 50; }

// If the form selected has wings the illusionist
// can actually fly - at one-quarter the rate of
// speed of a true creature of that type, with a
// loss of two Maneuverability Classes (to a minimum
// lost in a mid-sentence cut - a hole pending the
// PDF).
inline bool uail2AlterFlyQuarterSpeed()
    { return true; }

inline int uail2AlterManeuverClassLoss()
    { return 2; }

inline bool uail2AlterMinManeuverClassHole()
    { return true; }

// If the form has gills, the illusionist can
// breathe underwater as long as the spell lasts.
inline bool uail2AlterGillsBreatheWater()
    { return true; }

// Changing into a larger creature does not permit
// additional attacks or damage unless the
// illusionist is accustomed to this form.
inline bool uail2AlterLargerFormNoExtraAttacks()
    { return true; }

inline bool uail2AlterUnlessAccustomed()
    { return true; }

// ---- fascinate (Illusion/Phantasm) ----
// The R322 comeliness pin names fascinate as the
// 2nd-level illusionist spell - the corroborating
// seam for the section-heading level.
inline const char* uail2FascName()
    { return "Fascinate (Illusion/Phantasm)"; }

// The level cell never prints - the level pins from
// the printed Second Level Spells section heading,
// flagged pending the PDF.
inline bool uail2FascLevelCellLost()
    { return true; }

inline int uail2FascLevel()
    { return 2; }

inline bool uail2FascLevelFromSectionHeader()
    { return true; }

// The components cell garbles the sign (V, a
// paragraph sign) - the V, S pins from the pattern.
inline bool uail2FascComponentsVS()
    { return true; }

inline bool uail2FascComponentsCellGarbled()
    { return true; }

// The stat block interleaves - the casting 2
// segments scrambles across lines.
inline int uail2FascCastingTimeSegments()
    { return 2; }

inline bool uail2FascStatBlockInterleaved()
    { return true; }

inline bool uail2FascDurationSpecial()
    { return true; }

inline bool uail2FascSaveNegates()
    { return true; }

inline bool uail2FascAoeOneCreature()
    { return true; }

// The illusionist attempts to captivate the subject
// attention and gain its love - becoming, in the
// eyes of the subject, a trusted and/or desired
// companion.
inline bool uail2FascCaptivatesAttentionAndLove()
    { return true; }

inline bool uail2FascTrustedDesiredCompanion()
    { return true; }

// Unless the save versus spell is made, the subject
// follows the illusionist wherever he or she goes,
// if possible without undue risk to life and
// safety.
inline bool uail2FascFollowsWithoutUndueRisk()
    { return true; }

// If the illusionist can converse with the
// fascinated creature, the subject obeys requests
// as long as a roll of 3d6 per request does not
// exceed the comeliness of the illusionist.
inline int uail2FascRequestDiceCount()
    { return 3; }

inline int uail2FascRequestDiceSides()
    { return 6; }

inline bool uail2FascRequestRollVsComeliness()
    { return true; }

// The request sentence garbles: requests obviously
// against the creature add from +2 to +6 to the
// dice roll, and the subject will certainly be
// filled with rage and hate - the ladder pins from
// the fragments, flagged pending the PDF.
inline int uail2FascDangerousRequestBonusMin()
    { return 2; }

inline int uail2FascDangerousRequestBonusMax()
    { return 6; }

inline bool uail2FascRequestSentenceGarbled()
    { return true; }

inline bool uail2FascRageAndHate()
    { return true; }

// Creatures of normal sort with animal intelligence
// remain fascinated for only a short period - 1-4
// days.
inline int uail2FascAnimalIntDaysMin()
    { return 1; }

inline int uail2FascAnimalIntDaysMax()
    { return 4; }

// If the illusionist treats the subject well,
// attends to its needs and feeds it, there is a 2%
// chance per point of caster comeliness that the
// subject willingly chooses to befriend and follow.
inline int uail2FascBefriendPctPerComelinessPoint()
    { return 2; }

// Otherwise the creature attacks (if it was not
// cared for) or leaves (if it was) when the spell
// wears off.
inline bool uail2FascAttackOrLeaveWhenWorn()
    { return true; }

// Non-intelligent creatures are not subject to a
// fascinate spell (cf. charm person).
inline bool uail2FascNonIntelligentImmune()
    { return true; }

// The section tail prints stray fragments (the spell
// illusion around the better) - a hole pending the
// PDF.
inline bool uail2FascTailFragmentsHole()
    { return true; }

// ---- ultravision (Alteration), the IL reprint ----
inline const char* uail2UltraName()
    { return "Ultravision (Alteration)"; }

inline int uail2UltraLevel()
    { return 2; }

inline bool uail2UltraRangeTouch()
    { return true; }

// The duration: 6 turns plus 1 per level.
inline int uail2UltraDurationTurnsBase()
    { return 6; }

inline int uail2UltraDurationTurnsPerLevel()
    { return 1; }

inline bool uail2UltraAoeCreatureTouched()
    { return true; }

// The components cell garbles the sign - the V, S, M
// pins from the stat pattern.
inline bool uail2UltraComponentsVSM()
    { return true; }

inline bool uail2UltraComponentsCellGarbled()
    { return true; }

inline int uail2UltraCastingTimeSegments()
    { return 2; }

inline bool uail2UltraSaveNone()
    { return true; }

// Essentially the same as the 4th-level magic-user
// spell of the same name (the R359 pin) - except as
// the IL stat block prints: level 2, touch, 6 turns
// + 1 per level.
inline bool uail2UltraSameAsMuFourthLevel()
    { return true; }

// With high intelligence the caster might be able
// to detect invisible creatures by the use of
// ultravision, either natural or magically bestowed
// - the note sentence scrambles, flagged pending
// the PDF.
inline bool uail2UltraHighIntDetectsInvisible()
    { return true; }

inline bool uail2UltraNoteSentenceGarbled()
    { return true; }

// The material component: a powdered essence of
// carrots.
inline bool uail2UltraMaterialPowderedCarrots()
    { return true; }

// ---- wind (Phantasm), the IL reprint ----
// The name header garbles (Wind, with the school a
// bare fragment); the prose reads as the whispering
// wind throughout.
inline const char* uail2WindName()
    { return "Wind (Phantasm)"; }

inline bool uail2WindNameHeaderGarbled()
    { return true; }

inline bool uail2WindWhisperingWindProse()
    { return true; }

inline int uail2WindLevel()
    { return 2; }

inline bool uail2WindComponentsVS()
    { return true; }

inline int uail2WindCastingTimeSegments()
    { return 2; }

inline bool uail2WindRangeSpecial()
    { return true; }

inline bool uail2WindSaveNone()
    { return true; }

inline bool uail2WindDurationSpecial()
    { return true; }

// The area of effect prints a 2-radius - pinned as
// printed.
inline int uail2WindAoeRadiusFeet()
    { return 2; }

// The illusionist either sends a message or causes
// a desired sound effect: the whispering wind
// travels as many tens of feet underground or miles
// above ground as the caster has levels - a
// 3rd-level illusionist sends it 30 feet in a
// dungeon or three miles outdoors.
inline bool uail2WindTensFeetPerLevelUnderground()
    { return true; }

inline bool uail2WindMilesPerLevelAboveGround()
    { return true; }

// The wind is as gentle and unnoticed as a zephyr
// until it reaches the objective; it then delivers
// its whisper-quiet message or other sound for up
// to two segments.
inline int uail2WindDeliverySegments()
    { return 2; }

// The dweomer fades and vanishes if the subject is
// beyond range, more than two hours of time have
// elapsed, or it is magically dispelled.
inline int uail2WindFadesAfterHours()
    { return 2; }

// The spell bears a message of up to 12 words,
// delivers other sounds for 12 seconds, or merely a
// faint stirring of the air with a susurrant sound.
inline int uail2WindMessageWords()
    { return 12; }

inline int uail2WindSoundSeconds()
    { return 12; }

// The wind moves as slowly as 1 inch per round or
// as quickly as 20 inches (or any rate in
// between); it swirls and remains the full two
// segments at the objective regardless of speed.
inline int uail2WindSpeedMinInchesPerRound()
    { return 1; }

inline int uail2WindSpeedMaxInchesPerRound()
    { return 20; }

// As with the magic mouth spell, no spells may be
// cast through the whispering wind.
inline bool uail2WindNoSpellsThrough()
    { return true; }

}   // namespace rules

