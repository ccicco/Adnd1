// ===========================================================================
// Adnd1 - rules/uamuspells6.h
// The UA NEW MAGIC-USER SPELLS (pp. 66-71) pins, R360: the
// 6th-level spell descriptions - chain lightning,
// contingency, ensnarement, eyebite, the Mordenkainen
// lucubration and transmute water to dust.
//
// Pin-era pattern (R322): pinned data only - no engine site
// exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the
//     casting-time and duration 7s decode as 1 - the
//     contingency "7 day/level" as 1 day/level, the
//     eyebite and lucubration "7 segment" as 1 segment.
//     The range 7s stay as printed (the ensnarement "7""
//     below): the family decodes a range cell only when
//     corroborated (the flaming sphere prose, the R352
//     cloudburst seam, the druid water-to-dust seam
//     below) - pending the PDF. The water-to-dust "7
//     cubic" area decodes as 1 - corroborated by the
//     druid seam in rules/uadruidspells6.h.
//   - the R342 MU table seam loses the whole 6th-level
//     column - no 6th-level seam fn
//     exists; every 6th-level name pins
//     from the section bodies and the gap item list.
//   - the ensnarement name header is lost - the section
//     opens with a bare open-paren-C fragment; the name
//     pins from the gap item list and the prose (the
//     "ensnarement spell" self-references). The stat
//     block prints clean after the scrambled head.
//   - the eyebite header garbles the school tail
//     ("harm, lllusion/F tasm") - the school is a hole
//     pending the PDF, not pinned as data. The
//     components cell prints "V" plus a garbled sign -
//     flagged pending the PDF. A scrambled note has the
//     creatures saving at +4 - flagged pending the PDF.
//   - the lucubration name header is lost - the section
//     opens with a bare "sl" fragment; the name pins
//     from the gap item list and the prose (the
//     "Mordenkainen Lucubration" self-reference). The
//     duration cell is lost - the "Instantaneous" line
//     prints as a bare stat fragment.
//   - the water-to-dust header prints the short name
//     only; the full name "Transmute Water To Dust"
//     pins from the R342 spell-table seam and the
//     druid spell of the same name. The magic-user
//     print gives a 6-segment casting against the
//     druid seam 8 - flagged as a print discrepancy
//     (the cloudburst precedent), pinned as printed.
//   - the chain lightning range cell truncates after
//     the base 4 - the per-level tail is a hole pending
//     the PDF, the base pins as printed. The saving
//     throw cell garbles a "2 fraction ("2 or Neg.")
//     - the save pins from the prose (a half-damage
//     save per strike plus a hit-arc save), the cell
//     flagged pending the PDF.
// ===========================================================================

namespace rules {

// ---- chain lightning (Evocation) ----
inline const char* uam6ChainName()
    { return "Chain Lightning (Evocation)"; }

inline int uam6ChainLevel()
    { return 6; }

inline bool uam6ChainComponentsVSM()
    { return true; }

inline int uam6ChainCastingTimeSegments()
    { return 6; }

// The range cell truncates after the base 4 - the
// per-level tail is a hole pending the PDF.
inline int uam6ChainRangeBaseInches()
    { return 4; }

inline bool uam6ChainRangePerLevelTailLost()
    { return true; }

// The saving throw cell garbles a 2 fraction; the save
// pins from the prose instead.
inline bool uam6ChainSaveCellFractionGarbled()
    { return true; }

// A saving throw versus spell decides whether the bolt
// actually arcs to a secondary target; a saved target
// takes no damage and the stroke arcs onward.
inline bool uam6ChainSaveAvoidsSecondaryHit()
    { return true; }

// Each strike also allows the half-damage save.
inline bool uam6ChainHalfDamageSavePerStrike()
    { return true; }

inline bool uam6ChainDurationInstantaneous()
    { return true; }

inline bool uam6ChainAoeSpecial()
    { return true; }

// The bolt begins one quarter inch wide at the
// fingertips and extends to the primary target.
inline bool uam6ChainStrokeQuarterInchWide()
    { return true; }

// The primary target must lie within the maximum range
// dictated by the caster level.
inline bool uam6ChainPrimaryWithinRangeLimit()
    { return true; }

// The primary target takes 1d6 damage per caster level.
inline int uam6ChainPrimaryDicePerLevel()
    { return 1; }

inline int uam6ChainPrimaryDiceSides()
    { return 6; }

// Each target after the primary takes one less d6 than
// the target before it, down to 1d6.
inline int uam6ChainDiceStepDownPerTarget()
    { return 1; }

// The chain builds up to as many links, including the
// initial target, as the caster has levels.
inline bool uam6ChainLinksEqualCasterLevels()
    { return true; }

// A 12th-level caster hits 12 targets: the primary
// first, then 11 others.
inline int uam6ChainExampleLevel()
    { return 12; }

inline int uam6ChainExampleTargets()
    { return 12; }

// Equidistant targets: the bolt arcs to metal first,
// then to the one with the most fluid, else at random.
inline bool uam6ChainTiebreakMetalThenFluid()
    { return true; }

// The chain can oscillate between two immobilized
// objects or form a regular pattern of three or more.
inline bool uam6ChainOscillationPossible()
    { return true; }

// A single arc can never exceed the range limit; a
// longer needed arc fades into nothing.
inline bool uam6ChainArcBoundedByRange()
    { return true; }

// A tree or a substantial piece of conductive metal
// grounds the stroke and ends the arcing.
inline bool uam6ChainGroundedByTreeOrMetal()
    { return true; }

// The caster can be struck by an arc from his or her
// own spell.
inline bool uam6ChainCasterCanBeStruck()
    { return true; }

// The material components: a bit of fur; an amber,
// glass, or crystal rod; and as many silver pins as the
// caster has levels.
inline bool uam6ChainMaterialFurRodPins()
    { return true; }

inline bool uam6ChainSilverPinsPerLevel()
    { return true; }

// ---- contingency (Evocation) ----
inline const char* uam6ContName()
    { return "Contingency (Evocation)"; }

inline int uam6ContLevel()
    { return 6; }

// The casting time and components cells are lost in
// the scrambled block; the prose pins the 1-turn
// casting as the total for both spells.
inline bool uam6ContCastingCellsLost()
    { return true; }

inline int uam6ContCastingTimeTurns()
    { return 1; }

inline bool uam6ContCastingCoversBothSpells()
    { return true; }

inline int uam6ContRangeZero()
    { return 0; }

// The digit-garble family decodes the "7 day/level"
// duration as 1 day per level.
inline int uam6ContDurationDaysPerLevel()
    { return 1; }

inline bool uam6ContSaveNone()
    { return true; }

inline bool uam6ContAoeTheMagicUser()
    { return true; }

// The companion spell must affect the magic-user's
// person (feather fall, levitation, fly, statue,
// feign death, etc.).
inline bool uam6ContCompanionAffectsCaster()
    { return true; }

// The companion is limited to one-third of the caster
// level, rounded down, capped at the 6th spell level.
inline int uam6ContCompanionLevelDivisor()
    { return 3; }

inline bool uam6ContCompanionLevelCap()
    { return 6; }

// A 4th-level maximum at 12th, 13th or 14th level.
inline int uam6ContMax4thAtLevel()
    { return 12; }

// A 5th-level maximum at 15th, 16th or 17th level.
inline int uam6ContMax5thAtLevel()
    { return 15; }

// A 6th-level maximum at 18th level and beyond.
inline int uam6ContMax6thAtLevel()
    { return 18; }

// Only one contingency can be in effect at a time; a
// second cancels the first if still active.
inline bool uam6ContOneAtATime()
    { return true; }

inline bool uam6ContSecondCancelsFirst()
    { return true; }

// The prescribed situation must be clear, although it
// can be rather general.
inline bool uam6ContSituationClearThoughGeneral()
    { return true; }

// The companion spell is cast instantaneously when the
// circumstances occur.
inline bool uam6ContCompanionInstantaneous()
    { return true; }

// Complex or unlikely situations are likely to cause
// the whole spell complex to fail when called upon.
inline bool uam6ContComplexSituationsLikelyFail()
    { return true; }

// The material components, beyond the companion
// spell's own: 100 gp worth of quicksilver, an
// elephant ivory statuette of the magic-user, and an
// eyelash of an ogre magi, ki-rin, or similar
// spell-using creature.
inline int uam6ContQuicksilverGp()
    { return 100; }

inline bool uam6ContMaterialIvoryStatuette()
    { return true; }

inline bool uam6ContMaterialEyelashSpellUser()
    { return true; }

// The statuette is not destroyed by the casting and
// must be carried on the caster's person.
inline bool uam6ContStatuetteNotConsumed()
    { return true; }

inline bool uam6ContStatuetteMustBeCarried()
    { return true; }

// ---- ensnarement (Conjuration/Summoning) ----
// The name header is lost; the school cell does not
// print. The name pins from the gap item list and the
// prose; the school is a hole pending the PDF.
inline const char* uam6EnsnareName()
    { return "Ensnarement (Conjuration/Summoning)"; }

inline bool uam6EnsnareNameHeaderLost()
    { return true; }

inline bool uam6EnsnareSchoolCellLost()
    { return true; }

inline bool uam6EnsnareComponentsVSM()
    { return true; }

inline int uam6EnsnareLevel()
    { return 6; }

inline int uam6EnsnareCastingTimeTurns()
    { return 1; }

// The range 7 stays as printed - the family decodes a
// range cell only when corroborated; flagged pending
// the PDF.
inline int uam6EnsnareRangeInches()
    { return 7; }

inline bool uam6EnsnareRangePendingPdf()
    { return true; }

inline bool uam6EnsnareDurationSpecial()
    { return true; }

inline bool uam6EnsnareAoeSpecial()
    { return true; }

inline bool uam6EnsnareSaveNeg()
    { return true; }

// The spell lures a powerful creature from another
// plane into a specially prepared trap, holding it
// until it agrees to perform one service.
inline bool uam6EnsnareOneServiceForFreedom()
    { return true; }

// The creature must save by rolling equal to or less
// than its intelligence on 3d6.
inline int uam6EnsnareSaveDice()
    { return 3; }

inline int uam6EnsnareSaveDieSides()
    { return 6; }

// If the creature's intelligence is higher, the
// difference is subtracted from its roll; if the
// caster's is higher, the difference is added.
inline bool uam6EnsnareSaveModifiedByIntDiff()
    { return true; }

// A saved throw means the creature ignores the
// opening and the dweomer fails.
inline bool uam6EnsnareSaveIgnoresOpening()
    { return true; }

// The creature type must be known and stated; a
// specific, proper, or given name must be used.
inline bool uam6EnsnareCreatureMustBeNamed()
    { return true; }

// A magic circle for Ethereal or Astral creatures; a
// pentagram for creatures from the lower infernal
// planes.
inline bool uam6EnsnareCircleForEtherealAstral()
    { return true; }

inline bool uam6EnsnarePentagramForInfernal()
    { return true; }

// Break-free base: 20% for a hand-done design, 10%
// for one inlaid or carved.
inline int uam6EnsnareBreakBaseHandPct()
    { return 20; }

inline int uam6EnsnareBreakBaseInlaidPct()
    { return 10; }

// The base chance applies for the first time only,
// indicating whether the job was done properly.
inline bool uam6EnsnareBaseFirstTimeOnly()
    { return true; }

// The break-free chance is further modified by the
// combined caster level and intelligence against the
// creature level-or-hit-dice and intelligence.
inline bool uam6EnsnareBreakModifiedByTotals()
    { return true; }

// If the caster's total is higher, the difference is
// subtracted from the creature's chance; if the
// creature's total is higher, it is added.
inline bool uam6EnsnareBreakDiffSubtractedOrAdded()
    { return true; }

// Specially prepared pigments at 1,000 gp per turn of
// application reduce the chance by 1% per turn.
inline int uam6EnsnarePigmentGpPerTurn()
    { return 1000; }

inline int uam6EnsnarePigmentPctPerTurn()
    { return 1; }

// This can bring the base to 0%, but the intelligence
// and level/hit-dice modifications still apply.
inline bool uam6EnsnarePigmentCannotNegateMods()
    { return true; }

// An inlaid or inscribed design reaches 0% by inlaying
// metals, minerals, etc., into the stone - one month
// of full-time work and not less than 50,000 gp.
inline int uam6EnsnareInlayMonths()
    { return 1; }

inline int uam6EnsnareInlayGp()
    { return 50000; }

// A straw dropped across the lines, or any blurring of
// the glyphs, runes, and sigils, spoils the barrier
// and the creature breaks free automatically.
inline bool uam6EnsnareStrawSpoilsBarrier()
    { return true; }

// The creature within cannot place a straw upon any
// portion of the device - the barrier prevents it.
inline bool uam6EnsnareCreatureCannotSpoil()
    { return true; }

// The caster can bribe, promise, or threaten; the DM
// rates the offer from 0 to 6, subtracted from the
// creature's intelligence.
inline int uam6EnsnareOfferRatingMin()
    { return 0; }

inline int uam6EnsnareOfferRatingMax()
    { return 6; }

// A save equal to or less than the adjusted
// intelligence means the creature refuses service.
inline bool uam6EnsnareSaveRefusesService()
    { return true; }

// New offers can be made 24 hours later, when the
// creature's intelligence has dropped by 1 point from
// the confinement.
inline int uam6EnsnareReofferHours()
    { return 24; }

inline int uam6EnsnareIntDropPerDay()
    { return 1; }

// The cycle repeats until service, break-free, or a
// riddance spell release.
inline bool uam6EnsnareRepeatUntilService()
    { return true; }

// Once the single service is completed, the creature
// need only inform the caster to be instantly
// teleported from whence it came.
inline bool uam6EnsnareTeleportAfterService()
    { return true; }

// Revenge can be sought - cf. efreeti, aerial servant,
// and invisible stalker; certain services will never
// be agreed to.
inline bool uam6EnsnareRevengeRisk()
    { return true; }

// ---- eyebite ----
// The header garbles the school tail; the school is a
// hole pending the PDF, not pinned as data.
inline const char* uam6EyeName()
    { return "Eyebite"; }

inline bool uam6EyeSchoolHeaderGarbled()
    { return true; }

inline bool uam6EyeSchoolPendingPdf()
    { return true; }

// The components cell prints V plus a garbled sign -
// flagged pending the PDF.
inline bool uam6EyeComponentsV()
    { return true; }

inline bool uam6EyeComponentsCellGarbled()
    { return true; }

inline int uam6EyeLevel()
    { return 6; }

inline int uam6EyeRangeInches()
    { return 20; }

// The digit-garble family decodes the "7 segment"
// casting time as 1 segment.
inline int uam6EyeCastingTimeSegments()
    { return 1; }

inline bool uam6EyeDurationSpecial()
    { return true; }

inline bool uam6EyeSaveSpecial()
    { return true; }

inline bool uam6EyeAoeOneCreature()
    { return true; }

// The caster meets the subject's gaze and speaks a
// single word; choosing one effect dissipates the
// spell even though only one of four was used.
inline bool uam6EyeGazePlusSingleWord()
    { return true; }

inline int uam6EyeEffectCount()
    { return 4; }

inline bool uam6EyeDissipatesAfterOneEffect()
    { return true; }

// A scrambled note has the creatures saving at +4 -
// flagged pending the PDF.
inline bool uam6EyeSavePlusFourNoteGarbled()
    { return true; }

// Charm: a person or monster becomes absolutely loyal
// and docile, even to personal danger; otherwise the
// same as charm person or charm monster. A save versus
// spell negates.
inline bool uam6EyeCharmLoyalDocile()
    { return true; }

inline bool uam6EyeCharmSameAsCharmSpells()
    { return true; }

inline bool uam6EyeCharmSaveNegates()
    { return true; }

// Fear: the subject acts as if struck by a fear spell
// unless a save versus spell succeeds.
inline bool uam6EyeFearAsFearSpell()
    { return true; }

inline bool uam6EyeFearSaveNegates()
    { return true; }

// Sicken: sudden nausea - one-half normal abilities and
// movement; the victim must rest half of each turn to
// move at all. Creatures without ability scores are
// not affected. A save versus spell negates.
inline bool uam6EyeSickenHalfAbilities()
    { return true; }

inline bool uam6EyeSickenHalfMovement()
    { return true; }

inline bool uam6EyeSickenRestHalfTurn()
    { return true; }

inline bool uam6EyeSickenSkipsNoScoreCreatures()
    { return true; }

inline bool uam6EyeSickenSaveNegates()
    { return true; }

// Otherwise the victim loses one point of
// constitution per day until death at zero.
inline int uam6EyeSickenConLossPerDay()
    { return 1; }

// The sickness is negated by a dispel magic or a heal;
// alter reality, limited wish, and wish also cure it,
// but a cure disease does not.
inline bool uam6EyeSickenCuredByDispelOrHeal()
    { return true; }

inline bool uam6EyeSickenCuredByWishFamily()
    { return true; }

inline bool uam6EyeSickenNotCuredByCureDisease()
    { return true; }

// Sleep: a comatose slumber unless the subject saves
// versus spell. Creatures normally subject to the
// 1st-level sleep spell save at -2. Undead are not
// subject. Affected creatures must be shaken or
// shocked back to consciousness.
inline bool uam6EyeSleepComatose()
    { return true; }

inline bool uam6EyeSleepSaveNegates()
    { return true; }

inline int uam6EyeSleepSaveAdj()
    { return -2; }

inline bool uam6EyeSleepUndeadImmune()
    { return true; }

inline bool uam6EyeSleepNeedsShaking()
    { return true; }

// ---- the Mordenkainen lucubration ----
// The name header is lost - a bare "sl" fragment; the
// name pins from the gap item list and the prose.
inline const char* uam6LucName()
    { return "Mordenkainen's Lucubration"; }

inline bool uam6LucNameHeaderLost()
    { return true; }

inline bool uam6LucComponentsVS()
    { return true; }

// The digit-garble family decodes the "7 segment"
// casting time as 1 segment.
inline int uam6LucCastingTimeSegments()
    { return 1; }

inline bool uam6LucSaveNone()
    { return true; }

// The duration cell is lost - the "Instantaneous"
// line prints as a bare stat fragment; flagged
// pending the PDF.
inline bool uam6LucDurationCellLost()
    { return true; }

inline bool uam6LucDurationInstantaneous()
    { return true; }

inline int uam6LucLevel()
    { return 6; }

inline bool uam6LucAoeTheMagicUser()
    { return true; }

// The caster instantly recalls any spell used and
// otherwise forgotten during the past 24 hours.
inline int uam6LucRecallWindowHours()
    { return 24; }

// The recalled spell must have been memorized and
// actually used within the window, and cannot be of
// greater power than fifth level.
inline bool uam6LucRecallMustHaveBeenCast()
    { return true; }

inline int uam6LucRecallMaxLevel()
    { return 5; }

// Only one such spell can be recalled per lucubration;
// it can be cast normally on any succeeding round.
inline bool uam6LucOneSpellPerCasting()
    { return true; }

inline bool uam6LucRecastOnSucceedingRound()
    { return true; }

// Material spell components must be available if the
// recalled spell requires such, or the remembered
// spell is not usable until they are.
inline bool uam6LucComponentsMustBeAvailable()
    { return true; }

// ---- transmute water to dust ----
// The header prints the short name only; the full name
// pins from the R342 spell-table seam and the druid
// spell of the same name.
inline const char* uam6WaterName()
    { return "Transmute Water To Dust"; }

inline bool uam6WaterHeaderPrintsShortName()
    { return true; }

// The components cell prints a garbled sign for the S;
// the spell is V, S, M - the magic-user needs no
// mistletoe, unlike the druid version.
inline bool uam6WaterComponentsVSM()
    { return true; }

inline bool uam6WaterComponentsCellGarbled()
    { return true; }

inline bool uam6WaterNoMistletoe()
    { return true; }

inline int uam6WaterLevel()
    { return 6; }

inline int uam6WaterRangeInches()
    { return 6; }

// The print gives a 6-segment casting against the
// druid seam 8 - flagged as a print discrepancy (the
// cloudburst precedent), pinned as printed.
inline int uam6WaterCastingTimeSegments()
    { return 6; }

inline int uam6WaterDruidSeamCastingTimeSegments()
    { return 8; }

inline bool uam6WaterCastingDiscrepancyFlagged()
    { return true; }

inline bool uam6WaterSaveNoneAndSpecial()
    { return true; }

inline bool uam6WaterDurationPermanent()
    { return true; }

// The "7 cubic" area decodes as 1 cubic inch per
// caster level - corroborated by the druid seam.
inline int uam6WaterCubicInchesPerLevel()
    { return 1; }

inline bool uam6WaterAoeGarbleCorroborated()
    { return true; }

// The spell is identical to the 6th-level druid spell
// of the same name, except as noted above.
inline bool uam6WaterSameAsDruid6th()
    { return true; }

// ===========================================================================

}   // namespace rules

