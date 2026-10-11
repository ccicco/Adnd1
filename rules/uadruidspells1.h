// ===========================================================================
// Adnd1 - rules/uadruidspells1.h
// The UA NEW DRUID SPELLS (pp. 42-43) pins, R350: the 1st-level
// spell descriptions - ceremony, detect balance, detect poison,
// precipitation.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The R341 druid table pin (rules/uaspelltables.h) is the name seam.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): three
//     "Level: 7" cells print where the level is position-certain 1
//     (ceremony, detect poison, precipitation) - the section header
//     reads First Level Spells and detect balance prints a clean
//     "Level: 1" cell. The same family decodes the detect balance
//     casting time "7 segment" and the two "7 round/level"
//     durations (detect balance, detect poison) as 1.
//   - the ceremony opener prints "The druidic ... spell is similar
//     to the clerical spell of the same name" with a stray "y"
//     fragment - the lost word decodes as ceremony (the section
//     subject); the fragment noted.
//   - the ceremony stat block prints empty Components and Casting
//     Time cells - holes; the prose pins mistletoe (always) and
//     the dawn-or-dusk rite setting.
//   - the ceremony variety ladder: the "1st-level druid" and
//     "12th-level druid" prefixes print clean; the three middle
//     group prefixes are lost cells ("id:" is a tail of a lost
//     "...level druid:" prefix) - the group membership and order
//     pin (dedication, investiture; initiation, special vows;
//     hallowed ground), the middle prefix numbers stay holes
//     pending the PDF. The "Th as follows:" line is the scrambled
//     "The effects of the various types of druidic ceremony spells
//     are as follows:" head.
//   - hallowed ground: "his or her willy grove" decodes as the
//     druid's own grove (the "willy" garble noted); the displaced
//     "never" reads "the trees of the grove will never be affected
//     by disease or other natural disasters".
//   - cast out: the permission interleave decodes as the ladder
//     druid <- Archdruid <- Great Druid <- Grand Druid ("Archdruid"
//     prints displaced before "performed"; the "us" fragment is a
//     stray tail); the Grand Druid needs no permission but a
//     Hierophant Druid may reverse the Grand Druid at any time.
//     The adverb after "causing any natural crea- tures to react"
//     is lost - a hole.
//   - the detect poison opener scrambles two columns: "By means of
//     this spell the druid is able to determine if some object,
//     creature, or area contains or has been poisoned."
//   - precipitation: the name header never prints (the stat block
//     follows detect poison's scrambled opener directly);
//     identified by the gap item list plus "identical to the
//     1st-level clerical spell of the same name" - the R343
//     clerical precipitation pin. The duration prints
//     "1 segment/ievel" = level; the range cell prints empty - a
//     hole (the R343 clerical range was lost too).
//
// OCR holes (the item stays open - the 2nd-7th levels pin in later
// rounds; these stay pending the PDF): the ceremony components
// cell beyond the prose mistletoe and the empty casting time cell;
// the three middle ceremony variety prefix numbers; the cast out
// react-adverb; the detect balance range cell; the precipitation
// name header, school line and range cell.
// ===========================================================================

#pragma once

namespace rules {

// ---- ceremony (Invocation), p. 42-43 ----
inline const char* uad1CeremonyName()
    { return "Ceremony (Invocation)"; }

// The stat block prints "Level: 7" - the digit-garble family
// decodes 1 (the section header and the R343 family precedent).
inline int uad1CeremonyLevel()
    { return 1; }

inline bool uad1CeremonyRangeTouch()
    { return true; }

inline bool uad1CeremonySaveSpecial()
    { return true; }

inline bool uad1CeremonyDurationPermanent()
    { return true; }

inline bool uad1CeremonyAoeOneCreatureItemOrArea()
    { return true; }

// The components and casting time cells print empty - holes; the
// prose pins that the components always include mistletoe.
inline bool uad1CeremonyComponentsIncludeMistletoe()
    { return true; }

inline bool uad1CeremonyComponentsCellLost()
    { return true; }

inline bool uad1CeremonyCastingTimeCellLost()
    { return true; }

// The opener decodes: the druidic ceremony spell is similar to the
// clerical spell of the same name.
inline bool uad1CeremonySimilarToClerical()
    { return true; }

inline bool uad1CeremonyNoAuraOfMagic()
    { return true; }

inline bool uad1CeremonyKnowAlignmentRevealsNeutrality()
    { return true; }

// The nine ceremony varieties, in list order. The caster level
// pins clean for the 1st (the first three) and the 12th (cast
// out); the three middle group prefixes are lost cells.
inline int uad1CeremonyVarietyCount()
    { return 9; }

inline const char* uad1CeremonyVarietyName(int i) {
    static const char* const k[9] = {
        "Coming of Age", "Rest Eternal", "Marriage",
        "Dedication", "Investiture", "Initiation",
        "Special Vows", "Hallowed Ground", "Cast Out",
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline int uad1CeremonyVarietyCasterLevel(int i) {
    // 1 for the first three; 12 for cast out; 0 marks the
    // lost middle prefixes (pending the PDF).
    static const int k[9] = {
        1, 1, 1, 0, 0, 0, 0, 0, 12,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

// A druid of the indicated or lower level can cast each rite.
inline bool uad1CeremonyIndicatedOrLowerLevel()
    { return true; }

// Coming of age: usually at age 14, symbolic of entrance into
// adulthood; the +1 bonus to a single saving throw matches the
// clerical version.
inline int uad1ComingOfAgeUsualAge()
    { return 14; }

inline int uad1ComingOfAgeSaveBonus()
    { return 1; }

// Rest eternal: the soul is hastened to its final resting place;
// raise dead and resurrection will not restore life afterwards -
// a wish would serve.
inline bool uad1RestEternalBlocksRaiseDeadAndResurrection()
    { return true; }

inline bool uad1RestEternalWishWorks()
    { return true; }

inline bool uad1MarriageIdenticalToClerical()
    { return true; }

// Dedication: taken into the ranks of followers/worshipers,
// provided the character is true neutral; charged, as druids,
// with preserving and protecting nature and the balance.
inline bool uad1DedicationRequiresTrueNeutral()
    { return true; }

inline bool uad1DedicationChargesBalanceKeeping()
    { return true; }

// Investiture: must be performed before a character can become an
// Aspirant (1st-level druid); conveys no other benefit.
inline bool uad1InvestitureBeforeAspirant()
    { return true; }

inline bool uad1InvestitureNoOtherBenefit()
    { return true; }

// Initiation: imbues the shape-changing and woodland-charm
// immunity powers available upon attaining 7th level; must be
// performed immediately after the druid begins advancing through
// the 7th level or it will not work.
inline bool uad1InitiationGrantsShapechangeAndWoodlandImmunity()
    { return true; }

inline bool uad1InitiationMustFollowSeventhLevelStart()
    { return true; }

inline bool uad1InitiationUsuallyBySeventhPlusDruid()
    { return true; }

inline bool uad1InitiationSelfCastUnusual()
    { return true; }

// Special vows: same fashion as the clerical rite; does not work
// upon paladins, but functions upon cavaliers of any alignment.
inline bool uad1SpecialVowsNotOnPaladins()
    { return true; }

inline bool uad1SpecialVowsWorksOnCavaliersAnyAlignment()
    { return true; }

// Hallowed ground: cast on the druid's own grove; the trees will
// never be affected by disease or other natural disasters; the
// ground stays hallowed while the druid keeps the grove as his
// or her permanent base.
inline bool uad1HallowedGroundOwnGrove()
    { return true; }

inline bool uad1HallowedGroundTreesNeverDiseased()
    { return true; }

inline bool uad1HallowedGroundLastsWhilePermanentBase()
    { return true; }

// Cast out: excommunication or punishment for sacrilege upon the
// natural environment or violations of druidic principles; the
// effects may be lessened later by a reversed version cast by the
// same druid or another of at least as high a level; never
// completely neutralized except by a Hierophant Druid of any
// level.
inline bool uad1CastOutExcommunicationForSacrilege()
    { return true; }

inline bool uad1CastOutLessenedByReversedVersion()
    { return true; }

inline bool uad1CastOutReverserAtLeastEqualLevel()
    { return true; }

inline bool uad1CastOutOnlyHierophantNeutralizes()
    { return true; }

// The cast-out druid exudes an aura causing any natural creatures
// to react [adverb lost - a hole]; this includes all animals
// native to the woodlands, domesticated beasts such as horses and
// dogs, and all druids and their followers.
inline bool uad1CastOutAuraAffectsNaturalCreatures()
    { return true; }

inline bool uad1CastOutReactAdverbLost()
    { return true; }

inline bool uad1CastOutAuraIncludesDomesticAndDruids()
    { return true; }

// The permission ladder: a druid needs permission from his or her
// Archdruid; an Archdruid similarly from the Great Druid; the
// Great Druid from the Grand Druid; the Grand Druid needs no
// permission, but a Hierophant Druid may reverse the Grand Druid
// at any time. A denied or offset druid may be punished by
// higher-ranking hierarchy members.
inline bool uad1CastOutNeedsArchdruidPermission()
    { return true; }

inline bool uad1ArchdruidNeedsGreatDruidPermission()
    { return true; }

inline bool uad1GreatDruidNeedsGrandDruidPermission()
    { return true; }

inline bool uad1GrandDruidNeedsNoPermission()
    { return true; }

inline bool uad1GrandDruidReversibleByHierophant()
    { return true; }

inline bool uad1CastOutDeniedOrOffsetPunishable()
    { return true; }

// An unwilling recipient receives a saving throw versus spell,
// at -4, to negate.
inline int uad1CastOutUnwillingSaveMod()
    { return -4; }

// The components always include mistletoe; the rite must be
// performed in a druid grove or another natural, healthy patch
// of forest, normally at dawn or dusk (night and day in balance).
inline bool uad1CeremonyRiteInGroveOrHealthyForest()
    { return true; }

inline bool uad1CeremonyAtDawnOrDusk()
    { return true; }

// ---- detect balance (Divination), p. 43 ----
inline const char* uad1DetectBalanceName()
    { return "Detect Balance (Divination)"; }

inline bool uad1DetectBalanceComponentsVSM()
    { return true; }

// This one prints a clean "Level: 1" cell.
inline int uad1DetectBalanceLevel()
    { return 1; }

// The casting time prints "7 segment" - the digit-garble family
// decodes 1 segment.
inline int uad1DetectBalanceCastingTimeSegments()
    { return 1; }

// The range cell prints empty - a hole.
inline bool uad1DetectBalanceRangeLost()
    { return true; }

inline bool uad1DetectBalanceSaveNone()
    { return true; }

// The duration prints "7 round/level" - the family decodes
// 1 round/level.
inline int uad1DetectBalanceDurationRoundsPerLevel()
    { return 1; }

inline bool uad1DetectBalanceAoeOnePerRound()
    { return true; }

// The spell determines if non-neutral alignments are at work in
// the area of effect or upon the object or creature; a partly
// neutral alignment (neutral good) radiates a mild aura; one
// with no neutral part (chaotic good) gives off a strong aura.
inline bool uad1DetectBalanceDetectsNonNeutralForces()
    { return true; }

inline bool uad1DetectBalancePartlyNeutralMildAura()
    { return true; }

inline bool uad1DetectBalanceNoNeutralPartStrongAura()
    { return true; }

// It does not determine exact alignment - only whether neutral;
// a paladin and a chaotic evil thief radiate the same strength.
inline bool uad1DetectBalanceNotExactAlignment()
    { return true; }

inline bool uad1DetectBalanceSameStrengthForSameNeutrality()
    { return true; }

// It will not function upon non-living items without a natural
// aura (a vial of poison) but works upon an aligned magical
// sword; unknowable alignment or similar magic blocks the read;
// a true neutral subject (another druid) produces a smooth,
// well-balanced aura of neutrality.
inline bool uad1DetectBalanceNoAuraOnPlainItems()
    { return true; }

inline bool uad1DetectBalanceWorksOnAlignedMagicItem()
    { return true; }

inline bool uad1DetectBalanceUnknowableAlignmentBlocks()
    { return true; }

inline bool uad1DetectBalanceTrueNeutralSmoothAura()
    { return true; }

// ---- detect poison (Divination), p. 43 ----
inline const char* uad1DetectPoisonName()
    { return "Detect Poison (Divination)"; }

inline bool uad1DetectPoisonComponentsVSM()
    { return true; }

// The stat block prints "Level: 7" - the family decodes 1.
inline int uad1DetectPoisonLevel()
    { return 1; }

inline bool uad1DetectPoisonRangeZero()
    { return true; }

inline int uad1DetectPoisonCastingTimeRounds()
    { return 1; }

inline bool uad1DetectPoisonSaveNone()
    { return true; }

// The duration prints "7 round/level" - the family decodes
// 1 round/level.
inline int uad1DetectPoisonDurationRoundsPerLevel()
    { return 1; }

inline bool uad1DetectPoisonAoeSpecial()
    { return true; }

// The scrambled opener decodes: by means of this spell the druid
// is able to determine if some object, creature, or area
// contains or has been poisoned.
inline bool uad1DetectPoisonOpenerScrambleDecoded()
    { return true; }

// About 1 cubic yard of space can be perused per round - the
// druid cannot tell if an entire pond is poisoned, but can tell
// of a portion (or something within it) scanned during a round.
inline int uad1DetectPoisonScanVolumeCubicYards()
    { return 1; }

inline bool uad1DetectPoisonPortionNotWholePond()
    { return true; }

// A 5% chance per level of experience also discovers the type of
// poison used or contained: contact (insinuative), ingestive, or
// respirative (gas).
inline int uad1DetectPoisonTypeChancePctPerLevel()
    { return 5; }

inline int uad1DetectPoisonTypeCount()
    { return 3; }

inline const char* uad1DetectPoisonTypeName(int i) {
    static const char* const k[3] = {
        "Contact (Insinuative)", "Ingestive",
        "Respirative (Gas)",
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return k[i];
}

// More than one area can be scanned during the duration, but any
// single failure on the 5% type roll makes the spell useless for
// type detection for the remainder of that casting.
inline bool uad1DetectPoisonOneFailureEndsTypeDetection()
    { return true; }

// The components are mistletoe plus a yew leaf; the yew leaf
// turns brown if poison is present, so several may be needed to
// utilize the entire duration.
inline bool uad1DetectPoisonMaterialMistletoe()
    { return true; }

inline bool uad1DetectPoisonMaterialYewLeaf()
    { return true; }

inline bool uad1DetectPoisonYewLeafTurnsBrown()
    { return true; }

inline bool uad1DetectPoisonSeveralLeavesNeeded()
    { return true; }

// ---- precipitation, p. 43 ----
// The name header never prints - the stat block follows the
// detect poison scrambled opener directly; identified by the
// gap item list plus "identical to the 1st-level clerical spell
// of the same name" (the R343 clerical pin).
inline const char* uad1PrecipName()
    { return "Precipitation"; }

inline bool uad1PrecipNameHeaderLost()
    { return true; }

inline bool uad1PrecipSchoolLost()
    { return true; }

inline bool uad1PrecipIdenticalToClerical()
    { return true; }

inline bool uad1PrecipComponentsVSM()
    { return true; }

// The stat block prints "Level: 7" - the family decodes 1.
inline int uad1PrecipLevel()
    { return 1; }

inline int uad1PrecipCastingTimeSegments()
    { return 3; }

// The range cell prints empty - a hole (the R343 clerical range
// was lost too).
inline bool uad1PrecipRangeLost()
    { return true; }

// The saving throw prints "None (& special)".
inline bool uad1PrecipSaveNoneAndSpecial()
    { return true; }

// The duration prints "1 segment/ievel" - the OCR "ievel" reads
// level.
inline int uad1PrecipDurationSegmentsPerLevel()
    { return 1; }

inline int uad1PrecipCylinderDiameterInches()
    { return 3; }

inline int uad1PrecipCylinderHeightInches()
    { return 12; }

// The druidic version is identical to the 1st-level clerical
// spell of the same name except that the druid needs mistletoe
// as an additional material component.
inline bool uad1PrecipAddsMistletoeToClerical()
    { return true; }

}   // namespace rules
